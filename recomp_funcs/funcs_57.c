#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_805DB2D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DB2D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805DB2DC: lui         $t7, 0x805E
    ctx->r15 = S32(RELOC_HI16(480, 0X2714) << 16);
    // 0x805DB2E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DB2E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805DB2E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805DB2EC: addiu       $t7, $t7, -0x2BEC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(480, 0X2714));
    // 0x805DB2F0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x805DB2F4: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x805DB2F8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x805DB2FC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x805DB300: lhu         $t9, 0x8($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X8);
    // 0x805DB304: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x805DB308: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805DB30C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805DB310: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x805DB314: blez        $a1, L_805DB36C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x805DB318: sh          $t9, 0x8($t6)
        MEM_H(0X8, ctx->r14) = ctx->r25;
            goto L_805DB36C;
    }
    // 0x805DB318: sh          $t9, 0x8($t6)
    MEM_H(0X8, ctx->r14) = ctx->r25;
    // 0x805DB31C: andi        $a0, $a1, 0x3
    ctx->r4 = ctx->r5 & 0X3;
    // 0x805DB320: beq         $a0, $zero, L_805DB344
    if (ctx->r4 == 0) {
        // 0x805DB324: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_805DB344;
    }
    // 0x805DB324: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x805DB328: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x805DB32C: addu        $v0, $s1, $t0
    ctx->r2 = ADD32(ctx->r17, ctx->r8);
L_805DB330:
    // 0x805DB330: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x805DB334: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x805DB338: bne         $v1, $a2, L_805DB330
    if (ctx->r3 != ctx->r6) {
        // 0x805DB33C: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_805DB330;
    }
    // 0x805DB33C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x805DB340: beq         $a2, $s0, L_805DB36C
    if (ctx->r6 == ctx->r16) {
        // 0x805DB344: sll         $t1, $a2, 1
        ctx->r9 = S32(ctx->r6 << 1);
            goto L_805DB36C;
    }
L_805DB344:
    // 0x805DB344: sll         $t1, $a2, 1
    ctx->r9 = S32(ctx->r6 << 1);
    // 0x805DB348: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x805DB34C: addu        $v1, $t2, $s1
    ctx->r3 = ADD32(ctx->r10, ctx->r17);
    // 0x805DB350: addu        $v0, $s1, $t1
    ctx->r2 = ADD32(ctx->r17, ctx->r9);
L_805DB354:
    // 0x805DB354: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x805DB358: sh          $zero, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = 0;
    // 0x805DB35C: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x805DB360: sh          $zero, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = 0;
    // 0x805DB364: bne         $v0, $v1, L_805DB354
    if (ctx->r2 != ctx->r3) {
        // 0x805DB368: sh          $zero, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = 0;
            goto L_805DB354;
    }
    // 0x805DB368: sh          $zero, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = 0;
L_805DB36C:
    // 0x805DB36C: jal         0x800653D8
    // 0x805DB370: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x805DB370: nop

    after_0:
    // 0x805DB374: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB378: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB37C: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x805DB380: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x805DB384: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x805DB388: bne         $s0, $zero, L_805DB394
    if (ctx->r16 != 0) {
        // 0x805DB38C: nop
    
            goto L_805DB394;
    }
    // 0x805DB38C: nop

    // 0x805DB390: break       7
    do_break(2153624464);
L_805DB394:
    // 0x805DB394: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB398: bne         $s0, $at, L_805DB3AC
    if (ctx->r16 != ctx->r1) {
        // 0x805DB39C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB3AC;
    }
    // 0x805DB39C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB3A0: bne         $v0, $at, L_805DB3AC
    if (ctx->r2 != ctx->r1) {
        // 0x805DB3A4: nop
    
            goto L_805DB3AC;
    }
    // 0x805DB3A4: nop

    // 0x805DB3A8: break       6
    do_break(2153624488);
L_805DB3AC:
    // 0x805DB3AC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB3B0: beql        $t5, $zero, L_805DB408
    if (ctx->r13 == 0) {
        // 0x805DB3B4: lhu         $t9, 0x30($sp)
        ctx->r25 = MEM_HU(ctx->r29, 0X30);
            goto L_805DB408;
    }
    goto skip_0;
    // 0x805DB3B4: lhu         $t9, 0x30($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X30);
    skip_0:
L_805DB3B8:
    // 0x805DB3B8: jal         0x800653D8
    // 0x805DB3BC: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x805DB3BC: nop

    after_1:
    // 0x805DB3C0: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB3C4: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB3C8: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x805DB3CC: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x805DB3D0: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x805DB3D4: bne         $s0, $zero, L_805DB3E0
    if (ctx->r16 != 0) {
        // 0x805DB3D8: nop
    
            goto L_805DB3E0;
    }
    // 0x805DB3D8: nop

    // 0x805DB3DC: break       7
    do_break(2153624540);
L_805DB3E0:
    // 0x805DB3E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB3E4: bne         $s0, $at, L_805DB3F8
    if (ctx->r16 != ctx->r1) {
        // 0x805DB3E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB3F8;
    }
    // 0x805DB3E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB3EC: bne         $v0, $at, L_805DB3F8
    if (ctx->r2 != ctx->r1) {
        // 0x805DB3F0: nop
    
            goto L_805DB3F8;
    }
    // 0x805DB3F0: nop

    // 0x805DB3F4: break       6
    do_break(2153624564);
L_805DB3F8:
    // 0x805DB3F8: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB3FC: bne         $t8, $zero, L_805DB3B8
    if (ctx->r24 != 0) {
        // 0x805DB400: nop
    
            goto L_805DB3B8;
    }
    // 0x805DB400: nop

    // 0x805DB404: lhu         $t9, 0x30($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X30);
L_805DB408:
    // 0x805DB408: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x805DB40C: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x805DB410: jal         0x800653D8
    // 0x805DB414: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x805DB414: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    after_2:
    // 0x805DB418: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB41C: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB420: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    // 0x805DB424: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x805DB428: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x805DB42C: bne         $s0, $zero, L_805DB438
    if (ctx->r16 != 0) {
        // 0x805DB430: nop
    
            goto L_805DB438;
    }
    // 0x805DB430: nop

    // 0x805DB434: break       7
    do_break(2153624628);
L_805DB438:
    // 0x805DB438: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB43C: bne         $s0, $at, L_805DB450
    if (ctx->r16 != ctx->r1) {
        // 0x805DB440: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB450;
    }
    // 0x805DB440: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB444: bne         $v0, $at, L_805DB450
    if (ctx->r2 != ctx->r1) {
        // 0x805DB448: nop
    
            goto L_805DB450;
    }
    // 0x805DB448: nop

    // 0x805DB44C: break       6
    do_break(2153624652);
L_805DB450:
    // 0x805DB450: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB454: beql        $t4, $zero, L_805DB4AC
    if (ctx->r12 == 0) {
        // 0x805DB458: lhu         $t8, 0x30($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X30);
            goto L_805DB4AC;
    }
    goto skip_1;
    // 0x805DB458: lhu         $t8, 0x30($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X30);
    skip_1:
L_805DB45C:
    // 0x805DB45C: jal         0x800653D8
    // 0x805DB460: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x805DB460: nop

    after_3:
    // 0x805DB464: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB468: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB46C: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x805DB470: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x805DB474: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x805DB478: bne         $s0, $zero, L_805DB484
    if (ctx->r16 != 0) {
        // 0x805DB47C: nop
    
            goto L_805DB484;
    }
    // 0x805DB47C: nop

    // 0x805DB480: break       7
    do_break(2153624704);
L_805DB484:
    // 0x805DB484: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB488: bne         $s0, $at, L_805DB49C
    if (ctx->r16 != ctx->r1) {
        // 0x805DB48C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB49C;
    }
    // 0x805DB48C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB490: bne         $v0, $at, L_805DB49C
    if (ctx->r2 != ctx->r1) {
        // 0x805DB494: nop
    
            goto L_805DB49C;
    }
    // 0x805DB494: nop

    // 0x805DB498: break       6
    do_break(2153624728);
L_805DB49C:
    // 0x805DB49C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB4A0: bne         $t7, $zero, L_805DB45C
    if (ctx->r15 != 0) {
        // 0x805DB4A4: nop
    
            goto L_805DB45C;
    }
    // 0x805DB4A4: nop

    // 0x805DB4A8: lhu         $t8, 0x30($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X30);
L_805DB4AC:
    // 0x805DB4AC: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x805DB4B0: addu        $t9, $s1, $t0
    ctx->r25 = ADD32(ctx->r17, ctx->r8);
    // 0x805DB4B4: jal         0x800653D8
    // 0x805DB4B8: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x805DB4B8: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    after_4:
    // 0x805DB4BC: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB4C0: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB4C4: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x805DB4C8: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x805DB4CC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x805DB4D0: bne         $s0, $zero, L_805DB4DC
    if (ctx->r16 != 0) {
        // 0x805DB4D4: nop
    
            goto L_805DB4DC;
    }
    // 0x805DB4D4: nop

    // 0x805DB4D8: break       7
    do_break(2153624792);
L_805DB4DC:
    // 0x805DB4DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB4E0: bne         $s0, $at, L_805DB4F4
    if (ctx->r16 != ctx->r1) {
        // 0x805DB4E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB4F4;
    }
    // 0x805DB4E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB4E8: bne         $v0, $at, L_805DB4F4
    if (ctx->r2 != ctx->r1) {
        // 0x805DB4EC: nop
    
            goto L_805DB4F4;
    }
    // 0x805DB4EC: nop

    // 0x805DB4F0: break       6
    do_break(2153624816);
L_805DB4F4:
    // 0x805DB4F4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB4F8: beql        $t3, $zero, L_805DB550
    if (ctx->r11 == 0) {
        // 0x805DB4FC: lhu         $t7, 0x32($sp)
        ctx->r15 = MEM_HU(ctx->r29, 0X32);
            goto L_805DB550;
    }
    goto skip_2;
    // 0x805DB4FC: lhu         $t7, 0x32($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X32);
    skip_2:
L_805DB500:
    // 0x805DB500: jal         0x800653D8
    // 0x805DB504: nop

    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x805DB504: nop

    after_5:
    // 0x805DB508: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB50C: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB510: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x805DB514: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x805DB518: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x805DB51C: bne         $s0, $zero, L_805DB528
    if (ctx->r16 != 0) {
        // 0x805DB520: nop
    
            goto L_805DB528;
    }
    // 0x805DB520: nop

    // 0x805DB524: break       7
    do_break(2153624868);
L_805DB528:
    // 0x805DB528: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB52C: bne         $s0, $at, L_805DB540
    if (ctx->r16 != ctx->r1) {
        // 0x805DB530: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB540;
    }
    // 0x805DB530: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB534: bne         $v0, $at, L_805DB540
    if (ctx->r2 != ctx->r1) {
        // 0x805DB538: nop
    
            goto L_805DB540;
    }
    // 0x805DB538: nop

    // 0x805DB53C: break       6
    do_break(2153624892);
L_805DB540:
    // 0x805DB540: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB544: bne         $t6, $zero, L_805DB500
    if (ctx->r14 != 0) {
        // 0x805DB548: nop
    
            goto L_805DB500;
    }
    // 0x805DB548: nop

    // 0x805DB54C: lhu         $t7, 0x32($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X32);
L_805DB550:
    // 0x805DB550: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x805DB554: addu        $t8, $s1, $t0
    ctx->r24 = ADD32(ctx->r17, ctx->r8);
    // 0x805DB558: jal         0x800653D8
    // 0x805DB55C: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    func_800653D8(rdram, ctx);
        goto after_6;
    // 0x805DB55C: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    after_6:
    // 0x805DB560: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB564: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB568: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x805DB56C: addu        $t1, $s1, $t9
    ctx->r9 = ADD32(ctx->r17, ctx->r25);
    // 0x805DB570: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x805DB574: bne         $s0, $zero, L_805DB580
    if (ctx->r16 != 0) {
        // 0x805DB578: nop
    
            goto L_805DB580;
    }
    // 0x805DB578: nop

    // 0x805DB57C: break       7
    do_break(2153624956);
L_805DB580:
    // 0x805DB580: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB584: bne         $s0, $at, L_805DB598
    if (ctx->r16 != ctx->r1) {
        // 0x805DB588: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB598;
    }
    // 0x805DB588: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB58C: bne         $v0, $at, L_805DB598
    if (ctx->r2 != ctx->r1) {
        // 0x805DB590: nop
    
            goto L_805DB598;
    }
    // 0x805DB590: nop

    // 0x805DB594: break       6
    do_break(2153624980);
L_805DB598:
    // 0x805DB598: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB59C: beql        $t2, $zero, L_805DB5F4
    if (ctx->r10 == 0) {
        // 0x805DB5A0: lhu         $t6, 0x32($sp)
        ctx->r14 = MEM_HU(ctx->r29, 0X32);
            goto L_805DB5F4;
    }
    goto skip_3;
    // 0x805DB5A0: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    skip_3:
L_805DB5A4:
    // 0x805DB5A4: jal         0x800653D8
    // 0x805DB5A8: nop

    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x805DB5A8: nop

    after_7:
    // 0x805DB5AC: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB5B0: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB5B4: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x805DB5B8: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x805DB5BC: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x805DB5C0: bne         $s0, $zero, L_805DB5CC
    if (ctx->r16 != 0) {
        // 0x805DB5C4: nop
    
            goto L_805DB5CC;
    }
    // 0x805DB5C4: nop

    // 0x805DB5C8: break       7
    do_break(2153625032);
L_805DB5CC:
    // 0x805DB5CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB5D0: bne         $s0, $at, L_805DB5E4
    if (ctx->r16 != ctx->r1) {
        // 0x805DB5D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB5E4;
    }
    // 0x805DB5D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB5D8: bne         $v0, $at, L_805DB5E4
    if (ctx->r2 != ctx->r1) {
        // 0x805DB5DC: nop
    
            goto L_805DB5E4;
    }
    // 0x805DB5DC: nop

    // 0x805DB5E0: break       6
    do_break(2153625056);
L_805DB5E4:
    // 0x805DB5E4: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB5E8: bne         $t5, $zero, L_805DB5A4
    if (ctx->r13 != 0) {
        // 0x805DB5EC: nop
    
            goto L_805DB5A4;
    }
    // 0x805DB5EC: nop

    // 0x805DB5F0: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
L_805DB5F4:
    // 0x805DB5F4: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x805DB5F8: addu        $t7, $s1, $t0
    ctx->r15 = ADD32(ctx->r17, ctx->r8);
    // 0x805DB5FC: jal         0x800653D8
    // 0x805DB600: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    func_800653D8(rdram, ctx);
        goto after_8;
    // 0x805DB600: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    after_8:
    // 0x805DB604: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB608: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB60C: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x805DB610: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x805DB614: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x805DB618: bne         $s0, $zero, L_805DB624
    if (ctx->r16 != 0) {
        // 0x805DB61C: nop
    
            goto L_805DB624;
    }
    // 0x805DB61C: nop

    // 0x805DB620: break       7
    do_break(2153625120);
L_805DB624:
    // 0x805DB624: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB628: bne         $s0, $at, L_805DB63C
    if (ctx->r16 != ctx->r1) {
        // 0x805DB62C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB63C;
    }
    // 0x805DB62C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB630: bne         $v0, $at, L_805DB63C
    if (ctx->r2 != ctx->r1) {
        // 0x805DB634: nop
    
            goto L_805DB63C;
    }
    // 0x805DB634: nop

    // 0x805DB638: break       6
    do_break(2153625144);
L_805DB63C:
    // 0x805DB63C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB640: beql        $t1, $zero, L_805DB698
    if (ctx->r9 == 0) {
        // 0x805DB644: lhu         $t5, 0x34($sp)
        ctx->r13 = MEM_HU(ctx->r29, 0X34);
            goto L_805DB698;
    }
    goto skip_4;
    // 0x805DB644: lhu         $t5, 0x34($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X34);
    skip_4:
L_805DB648:
    // 0x805DB648: jal         0x800653D8
    // 0x805DB64C: nop

    func_800653D8(rdram, ctx);
        goto after_9;
    // 0x805DB64C: nop

    after_9:
    // 0x805DB650: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB654: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB658: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    // 0x805DB65C: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x805DB660: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x805DB664: bne         $s0, $zero, L_805DB670
    if (ctx->r16 != 0) {
        // 0x805DB668: nop
    
            goto L_805DB670;
    }
    // 0x805DB668: nop

    // 0x805DB66C: break       7
    do_break(2153625196);
L_805DB670:
    // 0x805DB670: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB674: bne         $s0, $at, L_805DB688
    if (ctx->r16 != ctx->r1) {
        // 0x805DB678: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB688;
    }
    // 0x805DB678: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB67C: bne         $v0, $at, L_805DB688
    if (ctx->r2 != ctx->r1) {
        // 0x805DB680: nop
    
            goto L_805DB688;
    }
    // 0x805DB680: nop

    // 0x805DB684: break       6
    do_break(2153625220);
L_805DB688:
    // 0x805DB688: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB68C: bne         $t4, $zero, L_805DB648
    if (ctx->r12 != 0) {
        // 0x805DB690: nop
    
            goto L_805DB648;
    }
    // 0x805DB690: nop

    // 0x805DB694: lhu         $t5, 0x34($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X34);
L_805DB698:
    // 0x805DB698: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x805DB69C: addu        $t6, $s1, $t0
    ctx->r14 = ADD32(ctx->r17, ctx->r8);
    // 0x805DB6A0: jal         0x800653D8
    // 0x805DB6A4: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    func_800653D8(rdram, ctx);
        goto after_10;
    // 0x805DB6A4: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    after_10:
    // 0x805DB6A8: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB6AC: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB6B0: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x805DB6B4: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x805DB6B8: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x805DB6BC: bne         $s0, $zero, L_805DB6C8
    if (ctx->r16 != 0) {
        // 0x805DB6C0: nop
    
            goto L_805DB6C8;
    }
    // 0x805DB6C0: nop

    // 0x805DB6C4: break       7
    do_break(2153625284);
L_805DB6C8:
    // 0x805DB6C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB6CC: bne         $s0, $at, L_805DB6E0
    if (ctx->r16 != ctx->r1) {
        // 0x805DB6D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB6E0;
    }
    // 0x805DB6D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB6D4: bne         $v0, $at, L_805DB6E0
    if (ctx->r2 != ctx->r1) {
        // 0x805DB6D8: nop
    
            goto L_805DB6E0;
    }
    // 0x805DB6D8: nop

    // 0x805DB6DC: break       6
    do_break(2153625308);
L_805DB6E0:
    // 0x805DB6E0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB6E4: beql        $t9, $zero, L_805DB73C
    if (ctx->r25 == 0) {
        // 0x805DB6E8: lhu         $t4, 0x34($sp)
        ctx->r12 = MEM_HU(ctx->r29, 0X34);
            goto L_805DB73C;
    }
    goto skip_5;
    // 0x805DB6E8: lhu         $t4, 0x34($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X34);
    skip_5:
L_805DB6EC:
    // 0x805DB6EC: jal         0x800653D8
    // 0x805DB6F0: nop

    func_800653D8(rdram, ctx);
        goto after_11;
    // 0x805DB6F0: nop

    after_11:
    // 0x805DB6F4: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB6F8: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB6FC: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x805DB700: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x805DB704: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x805DB708: bne         $s0, $zero, L_805DB714
    if (ctx->r16 != 0) {
        // 0x805DB70C: nop
    
            goto L_805DB714;
    }
    // 0x805DB70C: nop

    // 0x805DB710: break       7
    do_break(2153625360);
L_805DB714:
    // 0x805DB714: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB718: bne         $s0, $at, L_805DB72C
    if (ctx->r16 != ctx->r1) {
        // 0x805DB71C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB72C;
    }
    // 0x805DB71C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB720: bne         $v0, $at, L_805DB72C
    if (ctx->r2 != ctx->r1) {
        // 0x805DB724: nop
    
            goto L_805DB72C;
    }
    // 0x805DB724: nop

    // 0x805DB728: break       6
    do_break(2153625384);
L_805DB72C:
    // 0x805DB72C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB730: bne         $t3, $zero, L_805DB6EC
    if (ctx->r11 != 0) {
        // 0x805DB734: nop
    
            goto L_805DB6EC;
    }
    // 0x805DB734: nop

    // 0x805DB738: lhu         $t4, 0x34($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X34);
L_805DB73C:
    // 0x805DB73C: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x805DB740: addu        $t5, $s1, $t0
    ctx->r13 = ADD32(ctx->r17, ctx->r8);
    // 0x805DB744: jal         0x800653D8
    // 0x805DB748: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    func_800653D8(rdram, ctx);
        goto after_12;
    // 0x805DB748: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    after_12:
    // 0x805DB74C: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB750: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB754: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x805DB758: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x805DB75C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x805DB760: bne         $s0, $zero, L_805DB76C
    if (ctx->r16 != 0) {
        // 0x805DB764: nop
    
            goto L_805DB76C;
    }
    // 0x805DB764: nop

    // 0x805DB768: break       7
    do_break(2153625448);
L_805DB76C:
    // 0x805DB76C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB770: bne         $s0, $at, L_805DB784
    if (ctx->r16 != ctx->r1) {
        // 0x805DB774: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB784;
    }
    // 0x805DB774: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB778: bne         $v0, $at, L_805DB784
    if (ctx->r2 != ctx->r1) {
        // 0x805DB77C: nop
    
            goto L_805DB784;
    }
    // 0x805DB77C: nop

    // 0x805DB780: break       6
    do_break(2153625472);
L_805DB784:
    // 0x805DB784: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB788: beql        $t8, $zero, L_805DB7E0
    if (ctx->r24 == 0) {
        // 0x805DB78C: lhu         $t3, 0x36($sp)
        ctx->r11 = MEM_HU(ctx->r29, 0X36);
            goto L_805DB7E0;
    }
    goto skip_6;
    // 0x805DB78C: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
    skip_6:
L_805DB790:
    // 0x805DB790: jal         0x800653D8
    // 0x805DB794: nop

    func_800653D8(rdram, ctx);
        goto after_13;
    // 0x805DB794: nop

    after_13:
    // 0x805DB798: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB79C: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB7A0: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x805DB7A4: addu        $t1, $s1, $t9
    ctx->r9 = ADD32(ctx->r17, ctx->r25);
    // 0x805DB7A8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x805DB7AC: bne         $s0, $zero, L_805DB7B8
    if (ctx->r16 != 0) {
        // 0x805DB7B0: nop
    
            goto L_805DB7B8;
    }
    // 0x805DB7B0: nop

    // 0x805DB7B4: break       7
    do_break(2153625524);
L_805DB7B8:
    // 0x805DB7B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB7BC: bne         $s0, $at, L_805DB7D0
    if (ctx->r16 != ctx->r1) {
        // 0x805DB7C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB7D0;
    }
    // 0x805DB7C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB7C4: bne         $v0, $at, L_805DB7D0
    if (ctx->r2 != ctx->r1) {
        // 0x805DB7C8: nop
    
            goto L_805DB7D0;
    }
    // 0x805DB7C8: nop

    // 0x805DB7CC: break       6
    do_break(2153625548);
L_805DB7D0:
    // 0x805DB7D0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB7D4: bne         $t2, $zero, L_805DB790
    if (ctx->r10 != 0) {
        // 0x805DB7D8: nop
    
            goto L_805DB790;
    }
    // 0x805DB7D8: nop

    // 0x805DB7DC: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
L_805DB7E0:
    // 0x805DB7E0: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x805DB7E4: addu        $t4, $s1, $t0
    ctx->r12 = ADD32(ctx->r17, ctx->r8);
    // 0x805DB7E8: jal         0x800653D8
    // 0x805DB7EC: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    func_800653D8(rdram, ctx);
        goto after_14;
    // 0x805DB7EC: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    after_14:
    // 0x805DB7F0: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB7F4: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB7F8: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x805DB7FC: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x805DB800: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x805DB804: bne         $s0, $zero, L_805DB810
    if (ctx->r16 != 0) {
        // 0x805DB808: nop
    
            goto L_805DB810;
    }
    // 0x805DB808: nop

    // 0x805DB80C: break       7
    do_break(2153625612);
L_805DB810:
    // 0x805DB810: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB814: bne         $s0, $at, L_805DB828
    if (ctx->r16 != ctx->r1) {
        // 0x805DB818: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB828;
    }
    // 0x805DB818: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB81C: bne         $v0, $at, L_805DB828
    if (ctx->r2 != ctx->r1) {
        // 0x805DB820: nop
    
            goto L_805DB828;
    }
    // 0x805DB820: nop

    // 0x805DB824: break       6
    do_break(2153625636);
L_805DB828:
    // 0x805DB828: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB82C: beql        $t7, $zero, L_805DB884
    if (ctx->r15 == 0) {
        // 0x805DB830: lhu         $t2, 0x36($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X36);
            goto L_805DB884;
    }
    goto skip_7;
    // 0x805DB830: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    skip_7:
L_805DB834:
    // 0x805DB834: jal         0x800653D8
    // 0x805DB838: nop

    func_800653D8(rdram, ctx);
        goto after_15;
    // 0x805DB838: nop

    after_15:
    // 0x805DB83C: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB840: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB844: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x805DB848: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x805DB84C: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x805DB850: bne         $s0, $zero, L_805DB85C
    if (ctx->r16 != 0) {
        // 0x805DB854: nop
    
            goto L_805DB85C;
    }
    // 0x805DB854: nop

    // 0x805DB858: break       7
    do_break(2153625688);
L_805DB85C:
    // 0x805DB85C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB860: bne         $s0, $at, L_805DB874
    if (ctx->r16 != ctx->r1) {
        // 0x805DB864: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB874;
    }
    // 0x805DB864: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB868: bne         $v0, $at, L_805DB874
    if (ctx->r2 != ctx->r1) {
        // 0x805DB86C: nop
    
            goto L_805DB874;
    }
    // 0x805DB86C: nop

    // 0x805DB870: break       6
    do_break(2153625712);
L_805DB874:
    // 0x805DB874: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB878: bne         $t1, $zero, L_805DB834
    if (ctx->r9 != 0) {
        // 0x805DB87C: nop
    
            goto L_805DB834;
    }
    // 0x805DB87C: nop

    // 0x805DB880: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
L_805DB884:
    // 0x805DB884: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x805DB888: addu        $t3, $s1, $t0
    ctx->r11 = ADD32(ctx->r17, ctx->r8);
    // 0x805DB88C: jal         0x800653D8
    // 0x805DB890: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    func_800653D8(rdram, ctx);
        goto after_16;
    // 0x805DB890: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    after_16:
    // 0x805DB894: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB898: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB89C: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x805DB8A0: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x805DB8A4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x805DB8A8: bne         $s0, $zero, L_805DB8B4
    if (ctx->r16 != 0) {
        // 0x805DB8AC: nop
    
            goto L_805DB8B4;
    }
    // 0x805DB8AC: nop

    // 0x805DB8B0: break       7
    do_break(2153625776);
L_805DB8B4:
    // 0x805DB8B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB8B8: bne         $s0, $at, L_805DB8CC
    if (ctx->r16 != ctx->r1) {
        // 0x805DB8BC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB8CC;
    }
    // 0x805DB8BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB8C0: bne         $v0, $at, L_805DB8CC
    if (ctx->r2 != ctx->r1) {
        // 0x805DB8C4: nop
    
            goto L_805DB8CC;
    }
    // 0x805DB8C4: nop

    // 0x805DB8C8: break       6
    do_break(2153625800);
L_805DB8CC:
    // 0x805DB8CC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB8D0: beq         $t6, $zero, L_805DB924
    if (ctx->r14 == 0) {
        // 0x805DB8D4: nop
    
            goto L_805DB924;
    }
    // 0x805DB8D4: nop

L_805DB8D8:
    // 0x805DB8D8: jal         0x800653D8
    // 0x805DB8DC: nop

    func_800653D8(rdram, ctx);
        goto after_17;
    // 0x805DB8DC: nop

    after_17:
    // 0x805DB8E0: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB8E4: mfhi        $v1
    ctx->r3 = hi;
    // 0x805DB8E8: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x805DB8EC: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x805DB8F0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x805DB8F4: bne         $s0, $zero, L_805DB900
    if (ctx->r16 != 0) {
        // 0x805DB8F8: nop
    
            goto L_805DB900;
    }
    // 0x805DB8F8: nop

    // 0x805DB8FC: break       7
    do_break(2153625852);
L_805DB900:
    // 0x805DB900: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB904: bne         $s0, $at, L_805DB918
    if (ctx->r16 != ctx->r1) {
        // 0x805DB908: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB918;
    }
    // 0x805DB908: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB90C: bne         $v0, $at, L_805DB918
    if (ctx->r2 != ctx->r1) {
        // 0x805DB910: nop
    
            goto L_805DB918;
    }
    // 0x805DB910: nop

    // 0x805DB914: break       6
    do_break(2153625876);
L_805DB918:
    // 0x805DB918: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x805DB91C: bne         $t9, $zero, L_805DB8D8
    if (ctx->r25 != 0) {
        // 0x805DB920: nop
    
            goto L_805DB8D8;
    }
    // 0x805DB920: nop

L_805DB924:
    // 0x805DB924: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x805DB928: lw          $t1, -0x76C0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76C0);
    // 0x805DB92C: sll         $t3, $a2, 1
    ctx->r11 = S32(ctx->r6 << 1);
    // 0x805DB930: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x805DB934: sll         $t0, $t1, 1
    ctx->r8 = S32(ctx->r9 << 1);
    // 0x805DB938: addu        $t2, $sp, $t0
    ctx->r10 = ADD32(ctx->r29, ctx->r8);
    // 0x805DB93C: lhu         $t2, 0x30($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X30);
    // 0x805DB940: jal         0x800653D8
    // 0x805DB944: sh          $t2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r10;
    func_800653D8(rdram, ctx);
        goto after_18;
    // 0x805DB944: sh          $t2, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r10;
    after_18:
    // 0x805DB948: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB94C: mfhi        $t5
    ctx->r13 = hi;
    // 0x805DB950: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x805DB954: addu        $v1, $s1, $t6
    ctx->r3 = ADD32(ctx->r17, ctx->r14);
    // 0x805DB958: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x805DB95C: bne         $s0, $zero, L_805DB968
    if (ctx->r16 != 0) {
        // 0x805DB960: nop
    
            goto L_805DB968;
    }
    // 0x805DB960: nop

    // 0x805DB964: break       7
    do_break(2153625956);
L_805DB968:
    // 0x805DB968: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB96C: bne         $s0, $at, L_805DB980
    if (ctx->r16 != ctx->r1) {
        // 0x805DB970: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB980;
    }
    // 0x805DB970: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB974: bne         $v0, $at, L_805DB980
    if (ctx->r2 != ctx->r1) {
        // 0x805DB978: nop
    
            goto L_805DB980;
    }
    // 0x805DB978: nop

    // 0x805DB97C: break       6
    do_break(2153625980);
L_805DB980:
    // 0x805DB980: beq         $t7, $zero, L_805DB9D0
    if (ctx->r15 == 0) {
        // 0x805DB984: nop
    
            goto L_805DB9D0;
    }
    // 0x805DB984: nop

L_805DB988:
    // 0x805DB988: jal         0x800653D8
    // 0x805DB98C: nop

    func_800653D8(rdram, ctx);
        goto after_19;
    // 0x805DB98C: nop

    after_19:
    // 0x805DB990: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x805DB994: mfhi        $t8
    ctx->r24 = hi;
    // 0x805DB998: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x805DB99C: addu        $v1, $s1, $t9
    ctx->r3 = ADD32(ctx->r17, ctx->r25);
    // 0x805DB9A0: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x805DB9A4: bne         $s0, $zero, L_805DB9B0
    if (ctx->r16 != 0) {
        // 0x805DB9A8: nop
    
            goto L_805DB9B0;
    }
    // 0x805DB9A8: nop

    // 0x805DB9AC: break       7
    do_break(2153626028);
L_805DB9B0:
    // 0x805DB9B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805DB9B4: bne         $s0, $at, L_805DB9C8
    if (ctx->r16 != ctx->r1) {
        // 0x805DB9B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805DB9C8;
    }
    // 0x805DB9B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805DB9BC: bne         $v0, $at, L_805DB9C8
    if (ctx->r2 != ctx->r1) {
        // 0x805DB9C0: nop
    
            goto L_805DB9C8;
    }
    // 0x805DB9C0: nop

    // 0x805DB9C4: break       6
    do_break(2153626052);
L_805DB9C8:
    // 0x805DB9C8: bne         $t1, $zero, L_805DB988
    if (ctx->r9 != 0) {
        // 0x805DB9CC: nop
    
            goto L_805DB988;
    }
    // 0x805DB9CC: nop

L_805DB9D0:
    // 0x805DB9D0: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x805DB9D4: lw          $t0, -0x76C0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76C0);
    // 0x805DB9D8: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
    // 0x805DB9DC: addu        $t2, $sp, $t3
    ctx->r10 = ADD32(ctx->r29, ctx->r11);
    // 0x805DB9E0: lhu         $t2, 0x30($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X30);
    // 0x805DB9E4: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x805DB9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805DB9EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805DB9F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805DB9F4: jr          $ra
    // 0x805DB9F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x805DB9F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80679E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80679E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80679E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80679E18: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80679E1C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80679E20: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80679E24: beq         $a1, $at, L_80679E40
    if (ctx->r5 == ctx->r1) {
        // 0x80679E28: addiu       $a0, $zero, 0x50
        ctx->r4 = ADD32(0, 0X50);
            goto L_80679E40;
    }
    // 0x80679E28: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x80679E2C: jal         0x80067878
    // 0x80679E30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80679E30: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80679E34: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80679E38: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80679E3C: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_80679E40:
    // 0x80679E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80679E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80679E48: jr          $ra
    // 0x80679E4C: nop

    return;
    // 0x80679E4C: nop

;}
RECOMP_FUNC void func_80035A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035A70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80035A74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80035A78: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80035A7C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80035A80: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80035A84: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
    // 0x80035A88: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80035A8C: lbu         $t9, 0x33($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X33);
    // 0x80035A90: beql        $t7, $zero, L_80035AA4
    if (ctx->r15 == 0) {
        // 0x80035A94: lbu         $v0, 0x30($t8)
        ctx->r2 = MEM_BU(ctx->r24, 0X30);
            goto L_80035AA4;
    }
    goto skip_0;
    // 0x80035A94: lbu         $v0, 0x30($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X30);
    skip_0:
    // 0x80035A98: b           L_80035AD8
    // 0x80035A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80035AD8;
    // 0x80035A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80035AA0: lbu         $v0, 0x30($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X30);
L_80035AA4:
    // 0x80035AA4: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x80035AA8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80035AAC: beq         $t9, $v0, L_80035ABC
    if (ctx->r25 == ctx->r2) {
        // 0x80035AB0: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80035ABC;
    }
    // 0x80035AB0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80035AB4: bnel        $t0, $v0, L_80035AD8
    if (ctx->r8 != ctx->r2) {
        // 0x80035AB8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80035AD8;
    }
    goto skip_1;
    // 0x80035AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_80035ABC:
    // 0x80035ABC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80035AC0: lw          $a1, 0x14C($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X14C);
    // 0x80035AC4: jal         0x80035900
    // 0x80035AC8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_80035900(rdram, ctx);
        goto after_0;
    // 0x80035AC8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_0:
    // 0x80035ACC: b           L_80035ADC
    // 0x80035AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80035ADC;
    // 0x80035AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80035AD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80035AD8:
    // 0x80035AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80035ADC:
    // 0x80035ADC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80035AE0: jr          $ra
    // 0x80035AE4: nop

    return;
    // 0x80035AE4: nop

;}
RECOMP_FUNC void func_804BD678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD678: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x804BD67C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BD680: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X1DE8) << 16);
    // 0x804BD684: addiu       $t6, $t6, -0x28E8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X1DE8));
    // 0x804BD688: sh          $zero, 0x30($a0)
    MEM_H(0X30, ctx->r4) = 0;
    // 0x804BD68C: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
    // 0x804BD690: jr          $ra
    // 0x804BD694: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x804BD694: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_804E9C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E9CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E9CA4: lui         $a1, 0x804F
    ctx->r5 = S32(RELOC_HI16(264, 0X1B0) << 16);
    // 0x804E9CA8: jal         0x804E9C50
    // 0x804E9CAC: addiu       $a1, $a1, -0x64E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(264, 0X1B0));
    func_804E9C50(rdram, ctx);
        goto after_0;
    // 0x804E9CAC: addiu       $a1, $a1, -0x64E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(264, 0X1B0));
    after_0:
    // 0x804E9CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E9CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E9CB8: jr          $ra
    // 0x804E9CBC: nop

    return;
    // 0x804E9CBC: nop

;}
RECOMP_FUNC void func_8064EA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EA00: lui         $v0, 0x8065
    ctx->r2 = S32(RELOC_HI16(501, 0XA80) << 16);
    // 0x8064EA04: jr          $ra
    // 0x8064EA08: addiu       $v0, $v0, -0xB80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(501, 0XA80));
    return;
    // 0x8064EA08: addiu       $v0, $v0, -0xB80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(501, 0XA80));
;}
RECOMP_FUNC void func_80475930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475930: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475934: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475938: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047593C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475940: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475944: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475948: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047594C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475950: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475954: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475958: jr          $ra
    // 0x8047595C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047595C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8078DF30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078DF30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078DF34: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8078DF38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078DF3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078DF40: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8078DF44: jal         0x80065954
    // 0x8078DF48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8078DF48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8078DF4C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8078DF50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8078DF54: lwc1        $f2, 0x70($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8078DF58: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8078DF5C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA70) << 16);
    // 0x8078DF60: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8078DF64: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8078DF68: bc1f        L_8078DF90
    if (!c1cs) {
        // 0x8078DF6C: nop
    
            goto L_8078DF90;
    }
    // 0x8078DF6C: nop

    // 0x8078DF70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078DF74: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8078DF78: jal         0x80065954
    // 0x8078DF7C: nop

    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8078DF7C: nop

    after_1:
    // 0x8078DF80: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8078DF84: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8078DF88: b           L_8078DFC4
    // 0x8078DF8C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
        goto L_8078DFC4;
    // 0x8078DF8C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
L_8078DF90:
    // 0x8078DF90: lwc1        $f10, -0x1670($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA70));
    // 0x8078DF94: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8078DF98: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8078DF9C: nop

    // 0x8078DFA0: bc1fl       L_8078DFC4
    if (!c1cs) {
        // 0x8078DFA4: lh          $a1, 0x1F0($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X1F0);
            goto L_8078DFC4;
    }
    goto skip_0;
    // 0x8078DFA4: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    skip_0:
    // 0x8078DFA8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8078DFAC: jal         0x80065954
    // 0x8078DFB0: nop

    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8078DFB0: nop

    after_2:
    // 0x8078DFB4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8078DFB8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8078DFBC: nop

    // 0x8078DFC0: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
L_8078DFC4:
    // 0x8078DFC4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8078DFC8: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    // 0x8078DFCC: bne         $a1, $at, L_8078DFF8
    if (ctx->r5 != ctx->r1) {
        // 0x8078DFD0: nop
    
            goto L_8078DFF8;
    }
    // 0x8078DFD0: nop

    // 0x8078DFD4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8078DFD8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8078DFDC: jal         0x80067D5C
    // 0x8078DFE0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x8078DFE0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8078DFE4: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    // 0x8078DFE8: jal         0x80067F78
    // 0x8078DFEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_4;
    // 0x8078DFEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8078DFF0: b           L_8078E058
    // 0x8078DFF4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8078E058;
    // 0x8078DFF4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_8078DFF8:
    // 0x8078DFF8: jal         0x80067930
    // 0x8078DFFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_5;
    // 0x8078DFFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_5:
    // 0x8078E000: beq         $v0, $zero, L_8078E038
    if (ctx->r2 == 0) {
        // 0x8078E004: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_8078E038;
    }
    // 0x8078E004: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8078E008: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8078E00C: bne         $v0, $at, L_8078E058
    if (ctx->r2 != ctx->r1) {
        // 0x8078E010: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8078E058;
    }
    // 0x8078E010: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8078E014: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8078E018: jal         0x80067D5C
    // 0x8078E01C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_6;
    // 0x8078E01C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x8078E020: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    // 0x8078E024: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8078E028: jal         0x800678F0
    // 0x8078E02C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_7;
    // 0x8078E02C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_7:
    // 0x8078E030: b           L_8078E05C
    // 0x8078E034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078E05C;
    // 0x8078E034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078E038:
    // 0x8078E038: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8078E03C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8078E040: jal         0x80067D5C
    // 0x8078E044: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_8;
    // 0x8078E044: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_8:
    // 0x8078E048: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    // 0x8078E04C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8078E050: jal         0x80067838
    // 0x8078E054: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_9;
    // 0x8078E054: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_9:
L_8078E058:
    // 0x8078E058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078E05C:
    // 0x8078E05C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078E060: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078E064: jr          $ra
    // 0x8078E068: nop

    return;
    // 0x8078E068: nop

;}
RECOMP_FUNC void func_804BAF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BAF2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804BAF30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BAF34: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804BAF38: lwc1        $f2, 0x3C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804BAF3C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804BAF40: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x804BAF44: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x804BAF48: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x804BAF4C: jal         0x804BB604
    // 0x804BAF50: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_804BB604(rdram, ctx);
        goto after_0;
    // 0x804BAF50: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x804BAF54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804BAF58: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804BAF5C: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804BAF60: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x804BAF64: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804BAF68: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x804BAF6C: beql        $t6, $zero, L_804BAFA4
    if (ctx->r14 == 0) {
        // 0x804BAF70: sub.s       $f2, $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_804BAFA4;
    }
    goto skip_0;
    // 0x804BAF70: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    skip_0:
    // 0x804BAF74: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x804BAF78: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x804BAF7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BAF80: nop

    // 0x804BAF84: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x804BAF88: nop

    // 0x804BAF8C: bc1fl       L_804BAFC8
    if (!c1cs) {
        // 0x804BAF90: swc1        $f2, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
            goto L_804BAFC8;
    }
    goto skip_1;
    // 0x804BAF90: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    skip_1:
    // 0x804BAF94: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x804BAF98: b           L_804BAFC4
    // 0x804BAF9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_804BAFC4;
    // 0x804BAF9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804BAFA0: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
L_804BAFA4:
    // 0x804BAFA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BAFA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804BAFAC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x804BAFB0: nop

    // 0x804BAFB4: bc1fl       L_804BAFC8
    if (!c1cs) {
        // 0x804BAFB8: swc1        $f2, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
            goto L_804BAFC8;
    }
    goto skip_2;
    // 0x804BAFB8: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    skip_2:
    // 0x804BAFBC: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
    // 0x804BAFC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_804BAFC4:
    // 0x804BAFC4: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
L_804BAFC8:
    // 0x804BAFC8: jal         0x804BAD44
    // 0x804BAFCC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804BAD44(rdram, ctx);
        goto after_1;
    // 0x804BAFCC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x804BAFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BAFD4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804BAFD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804BAFDC: jr          $ra
    // 0x804BAFE0: nop

    return;
    // 0x804BAFE0: nop

;}
RECOMP_FUNC void func_8003C358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C358: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003C35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C360: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8003C364: jal         0x8004700C
    // 0x8003C368: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003C368: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003C36C: beq         $v0, $zero, L_8003C3B0
    if (ctx->r2 == 0) {
        // 0x8003C370: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8003C3B0;
    }
    // 0x8003C370: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8003C374: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003C378: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8003C37C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8003C380: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003C384: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8003C388: jal         0x8003DF38
    // 0x8003C38C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8003DF38(rdram, ctx);
        goto after_1;
    // 0x8003C38C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003C390: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C394: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8003C398: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003C39C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003C3A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003C3A4: sb          $t7, 0x159($t8)
    MEM_B(0X159, ctx->r24) = ctx->r15;
    // 0x8003C3A8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8003C3AC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8003C3B0:
    // 0x8003C3B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003C3B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003C3B8: jr          $ra
    // 0x8003C3BC: nop

    return;
    // 0x8003C3BC: nop

;}
RECOMP_FUNC void func_804C52A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C52A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C52A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C52A8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x804C52AC: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x804C52B0: bne         $a1, $at, L_804C52C0
    if (ctx->r5 != ctx->r1) {
        // 0x804C52B4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_804C52C0;
    }
    // 0x804C52B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C52B8: jal         0x804C5158
    // 0x804C52BC: nop

    func_804C5158(rdram, ctx);
        goto after_0;
    // 0x804C52BC: nop

    after_0:
L_804C52C0:
    // 0x804C52C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C52C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C52C8: jr          $ra
    // 0x804C52CC: nop

    return;
    // 0x804C52CC: nop

;}
RECOMP_FUNC void func_800114E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800114E8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800114EC: addiu       $v1, $v1, -0x6D9C
    ctx->r3 = ADD32(ctx->r3, -0X6D9C);
    // 0x800114F0: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800114F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800114F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800114FC: beq         $t6, $zero, L_80011530
    if (ctx->r14 == 0) {
        // 0x80011500: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80011530;
    }
    // 0x80011500: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80011504: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80011508: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x8001150C: beql        $v0, $zero, L_80011534
    if (ctx->r2 == 0) {
        // 0x80011510: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80011534;
    }
    goto skip_0;
    // 0x80011510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80011514: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80011518: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8001151C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80011520: bne         $t7, $at, L_80011530
    if (ctx->r15 != ctx->r1) {
        // 0x80011524: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80011530;
    }
    // 0x80011524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011528: jal         0x80011600
    // 0x8001152C: lh          $a0, -0x5AE0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X5AE0);
    func_80011600(rdram, ctx);
        goto after_0;
    // 0x8001152C: lh          $a0, -0x5AE0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X5AE0);
    after_0:
L_80011530:
    // 0x80011530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011534:
    // 0x80011534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011538: jr          $ra
    // 0x8001153C: nop

    return;
    // 0x8001153C: nop

;}
RECOMP_FUNC void func_80462520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462520: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80462524: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x80462528: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046252C: lwc1        $f6, 0x3C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80462530: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80462534: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x80462538: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8046253C: lwc1        $f16, 0x40($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80462540: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80462544: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x80462548: lwc1        $f4, 0x50($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X50);
    // 0x8046254C: jr          $ra
    // 0x80462550: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80462550: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_805DA610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA610: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805DA614: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DA618: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DA61C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DA620: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805DA624: jal         0x805DA4E0
    // 0x805DA628: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805DA4E0(rdram, ctx);
        goto after_0;
    // 0x805DA628: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x805DA62C: bne         $v0, $zero, L_805DA710
    if (ctx->r2 != 0) {
        // 0x805DA630: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_805DA710;
    }
    // 0x805DA630: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805DA634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DA638: jal         0x805DA464
    // 0x805DA63C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805DA464(rdram, ctx);
        goto after_1;
    // 0x805DA63C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x805DA640: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805DA644: addiu       $t4, $zero, 0x12
    ctx->r12 = ADD32(0, 0X12);
    // 0x805DA648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DA64C: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x805DA650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DA654: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805DA658: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x805DA65C: beql        $at, $zero, L_805DA704
    if (ctx->r1 == 0) {
        // 0x805DA660: sw          $zero, 0x10($v1)
        MEM_W(0X10, ctx->r3) = 0;
            goto L_805DA704;
    }
    goto skip_0;
    // 0x805DA660: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    skip_0:
    // 0x805DA664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DA668: jal         0x805DA3B0
    // 0x805DA66C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805DA3B0(rdram, ctx);
        goto after_2;
    // 0x805DA66C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x805DA670: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805DA674: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x805DA678: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x805DA67C: bnel        $t7, $at, L_805DA714
    if (ctx->r15 != ctx->r1) {
        // 0x805DA680: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DA714;
    }
    goto skip_1;
    // 0x805DA680: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805DA684: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x805DA688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805DA68C: bnel        $v0, $t8, L_805DA714
    if (ctx->r2 != ctx->r24) {
        // 0x805DA690: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DA714;
    }
    goto skip_2;
    // 0x805DA690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805DA694: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    // 0x805DA698: addiu       $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
    // 0x805DA69C: bne         $t9, $zero, L_805DA6B0
    if (ctx->r25 != 0) {
        // 0x805DA6A0: nop
    
            goto L_805DA6B0;
    }
    // 0x805DA6A0: nop

    // 0x805DA6A4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x805DA6A8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x805DA6AC: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
L_805DA6B0:
    // 0x805DA6B0: jal         0x805DA298
    // 0x805DA6B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DA298(rdram, ctx);
        goto after_3;
    // 0x805DA6B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805DA6B8: jal         0x805DA0C0
    // 0x805DA6BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DA0C0(rdram, ctx);
        goto after_4;
    // 0x805DA6BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805DA6C0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805DA6C4: jal         0x80067BBC
    // 0x805DA6C8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x805DA6C8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x805DA6CC: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x805DA6D0: jal         0x80067818
    // 0x805DA6D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x805DA6D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x805DA6D8: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x805DA6DC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805DA6E0: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x805DA6E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805DA6E8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x805DA6EC: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x805DA6F0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805DA6F4: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x805DA6F8: b           L_805DA710
    // 0x805DA6FC: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
        goto L_805DA710;
    // 0x805DA6FC: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
    // 0x805DA700: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
L_805DA704:
    // 0x805DA704: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x805DA708: jal         0x805DAA20
    // 0x805DA70C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805DAA20(rdram, ctx);
        goto after_7;
    // 0x805DA70C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_7:
L_805DA710:
    // 0x805DA710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DA714:
    // 0x805DA714: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DA718: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805DA71C: jr          $ra
    // 0x805DA720: nop

    return;
    // 0x805DA720: nop

;}
RECOMP_FUNC void func_80742A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742A04: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742A08: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742A0C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742A10: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742A14: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742A18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742A1C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742A20: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742A24: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742A28: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742A2C: jr          $ra
    // 0x80742A30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742A30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8007E40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E40C: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8007E410: lw          $v1, -0x65B0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X65B0);
    // 0x8007E414: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8007E418: addiu       $a1, $a1, -0x1270
    ctx->r5 = ADD32(ctx->r5, -0X1270);
    // 0x8007E41C: blez        $v1, L_8007E448
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007E420: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007E448;
    }
    // 0x8007E420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007E424:
    // 0x8007E424: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8007E428: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007E42C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007E430: bne         $a0, $t6, L_8007E440
    if (ctx->r4 != ctx->r14) {
        // 0x8007E434: nop
    
            goto L_8007E440;
    }
    // 0x8007E434: nop

    // 0x8007E438: jr          $ra
    // 0x8007E43C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    return;
    // 0x8007E43C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
L_8007E440:
    // 0x8007E440: bne         $at, $zero, L_8007E424
    if (ctx->r1 != 0) {
        // 0x8007E444: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_8007E424;
    }
    // 0x8007E444: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_8007E448:
    // 0x8007E448: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8007E44C: addiu       $v0, $v0, 0x2F20
    ctx->r2 = ADD32(ctx->r2, 0X2F20);
    // 0x8007E450: jr          $ra
    // 0x8007E454: nop

    return;
    // 0x8007E454: nop

;}
RECOMP_FUNC void func_8002269C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002269C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800226A0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800226A4: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x800226A8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800226AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800226B0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800226B4: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800226B8: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800226BC: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x800226C0: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x800226C4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800226C8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800226CC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800226D0: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800226D4: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800226D8: beq         $s0, $zero, L_80022794
    if (ctx->r16 == 0) {
        // 0x800226DC: lwc1        $f20, -0x390($at)
        ctx->f20.u32l = MEM_W(ctx->r1, -0X390);
            goto L_80022794;
    }
    // 0x800226DC: lwc1        $f20, -0x390($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X390);
    // 0x800226E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800226E4: lwc1        $f30, -0x38C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, -0X38C);
    // 0x800226E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800226EC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800226F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800226F4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800226F8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800226FC: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x80022700: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80022704: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80022708: addiu       $s2, $s2, 0x7EA0
    ctx->r18 = ADD32(ctx->r18, 0X7EA0);
    // 0x8002270C: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
    // 0x80022710: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    // 0x80022714: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
L_80022718:
    // 0x80022718: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8002271C: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80022720: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80022724: swc1        $f20, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f20.u32l;
    // 0x80022728: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x8002272C: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x80022730: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x80022734: jal         0x80065414
    // 0x80022738: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    func_80065414(rdram, ctx);
        goto after_0;
    // 0x80022738: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8002273C: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x80022740: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80022744: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80022748: add.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8002274C: jal         0x80065414
    // 0x80022750: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    func_80065414(rdram, ctx);
        goto after_1;
    // 0x80022750: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80022754: cvt.s.d     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f16.fl = CVT_S_D(ctx->f0.d);
    // 0x80022758: lw          $t6, 0xA68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0XA68);
    // 0x8002275C: swc1        $f26, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f26.u32l;
    // 0x80022760: swc1        $f28, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f28.u32l;
    // 0x80022764: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80022768: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002276C: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80022770: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x80022774: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80022778: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8002277C: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x80022780: jalr        $t9
    // 0x80022784: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80022784: nop

    after_2:
    // 0x80022788: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8002278C: bne         $s0, $zero, L_80022718
    if (ctx->r16 != 0) {
        // 0x80022790: add.s       $f20, $f20, $f30
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f30.fl;
            goto L_80022718;
    }
    // 0x80022790: add.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f30.fl;
L_80022794:
    // 0x80022794: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80022798: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8002279C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800227A0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800227A4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800227A8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800227AC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x800227B0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800227B4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800227B8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800227BC: jr          $ra
    // 0x800227C0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800227C0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_805A4588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A4588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A458C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A4590: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805A4594: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(414, 0X1D40) << 16);
    // 0x805A4598: addiu       $t6, $t6, 0x50D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(414, 0X1D40));
    // 0x805A459C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805A45A0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805A45A4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805A45A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A45AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A45B0: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x805A45B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A45B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A45BC: jal         0x805A4678
    // 0x805A45C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_805A4678(rdram, ctx);
        goto after_0;
    // 0x805A45C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x805A45C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A45C8: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(414, 0X92C) << 16);
    // 0x805A45CC: addiu       $t9, $t9, 0x3CBC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(414, 0X92C));
    // 0x805A45D0: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x805A45D4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805A45D8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x805A45DC: jal         0x80045A34
    // 0x805A45E0: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x805A45E0: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_1:
    // 0x805A45E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A45E8: jal         0x805A42E0
    // 0x805A45EC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    func_805A42E0(rdram, ctx);
        goto after_2;
    // 0x805A45EC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    after_2:
    // 0x805A45F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A45F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A45F8: jr          $ra
    // 0x805A45FC: nop

    return;
    // 0x805A45FC: nop

;}
RECOMP_FUNC void func_80716FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716FA8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716FAC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716FB0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716FB4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716FB8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716FBC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716FC0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716FC4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716FC8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716FCC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716FD0: jr          $ra
    // 0x80716FD4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716FD4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805A3390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3390: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x805A3394: addiu       $at, $zero, 0x41CF
    ctx->r1 = ADD32(0, 0X41CF);
    // 0x805A3398: beq         $v0, $at, L_805A33C0
    if (ctx->r2 == ctx->r1) {
        // 0x805A339C: addiu       $at, $zero, 0x44E3
        ctx->r1 = ADD32(0, 0X44E3);
            goto L_805A33C0;
    }
    // 0x805A339C: addiu       $at, $zero, 0x44E3
    ctx->r1 = ADD32(0, 0X44E3);
    // 0x805A33A0: beq         $v0, $at, L_805A33E4
    if (ctx->r2 == ctx->r1) {
        // 0x805A33A4: addiu       $at, $zero, 0x4506
        ctx->r1 = ADD32(0, 0X4506);
            goto L_805A33E4;
    }
    // 0x805A33A4: addiu       $at, $zero, 0x4506
    ctx->r1 = ADD32(0, 0X4506);
    // 0x805A33A8: beq         $v0, $at, L_805A33CC
    if (ctx->r2 == ctx->r1) {
        // 0x805A33AC: addiu       $at, $zero, 0x450B
        ctx->r1 = ADD32(0, 0X450B);
            goto L_805A33CC;
    }
    // 0x805A33AC: addiu       $at, $zero, 0x450B
    ctx->r1 = ADD32(0, 0X450B);
    // 0x805A33B0: beq         $v0, $at, L_805A33D8
    if (ctx->r2 == ctx->r1) {
        // 0x805A33B4: nop
    
            goto L_805A33D8;
    }
    // 0x805A33B4: nop

    // 0x805A33B8: b           L_805A33F0
    // 0x805A33BC: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(414, 0X10DC) << 16);
        goto L_805A33F0;
    // 0x805A33BC: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(414, 0X10DC) << 16);
L_805A33C0:
    // 0x805A33C0: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(414, 0X10DC) << 16);
    // 0x805A33C4: jr          $ra
    // 0x805A33C8: addiu       $v0, $v0, 0x446C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(414, 0X10DC));
    return;
    // 0x805A33C8: addiu       $v0, $v0, 0x446C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(414, 0X10DC));
L_805A33CC:
    // 0x805A33CC: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(414, 0X1270) << 16);
    // 0x805A33D0: jr          $ra
    // 0x805A33D4: addiu       $v0, $v0, 0x4600
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(414, 0X1270));
    return;
    // 0x805A33D4: addiu       $v0, $v0, 0x4600
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(414, 0X1270));
L_805A33D8:
    // 0x805A33D8: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(414, 0X1174) << 16);
    // 0x805A33DC: jr          $ra
    // 0x805A33E0: addiu       $v0, $v0, 0x4504
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(414, 0X1174));
    return;
    // 0x805A33E0: addiu       $v0, $v0, 0x4504
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(414, 0X1174));
L_805A33E4:
    // 0x805A33E4: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(414, 0X11F8) << 16);
    // 0x805A33E8: jr          $ra
    // 0x805A33EC: addiu       $v0, $v0, 0x4588
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(414, 0X11F8));
    return;
    // 0x805A33EC: addiu       $v0, $v0, 0x4588
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(414, 0X11F8));
L_805A33F0:
    // 0x805A33F0: addiu       $v0, $v0, 0x446C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(414, 0X10DC));
    // 0x805A33F4: jr          $ra
    // 0x805A33F8: nop

    return;
    // 0x805A33F8: nop

;}
RECOMP_FUNC void func_8045FE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FE54: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8045FE58: lw          $v1, 0x16C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X16C);
    // 0x8045FE5C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8045FE60: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x8045FE64: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8045FE68: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x8045FE6C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8045FE70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8045FE74: ori         $t8, $t8, 0xCF0
    ctx->r24 = ctx->r24 | 0XCF0;
    // 0x8045FE78: ori         $t7, $t7, 0x18
    ctx->r15 = ctx->r15 | 0X18;
    // 0x8045FE7C: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x8045FE80: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8045FE84: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8045FE88: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8045FE8C: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x8045FE90: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8045FE94: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8045FE98: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x8045FE9C: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x8045FEA0: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x8045FEA4: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x8045FEA8: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8045FEAC: lbu         $t5, 0xD($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XD);
    // 0x8045FEB0: lbu         $t2, 0x10($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X10);
    // 0x8045FEB4: lbu         $t9, 0xE($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XE);
    // 0x8045FEB8: andi        $t6, $t5, 0xF8
    ctx->r14 = ctx->r13 & 0XF8;
    // 0x8045FEBC: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x8045FEC0: sra         $t4, $t3, 7
    ctx->r12 = S32(SIGNED(ctx->r11) >> 7);
    // 0x8045FEC4: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8045FEC8: lbu         $t5, 0xF($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF);
    // 0x8045FECC: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8045FED0: andi        $t1, $t9, 0xF8
    ctx->r9 = ctx->r25 & 0XF8;
    // 0x8045FED4: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8045FED8: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x8045FEDC: lbu         $t8, 0x11($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X11);
    // 0x8045FEE0: andi        $t6, $t5, 0xF8
    ctx->r14 = ctx->r13 & 0XF8;
    // 0x8045FEE4: lbu         $t7, 0x14($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X14);
    // 0x8045FEE8: sra         $t4, $t6, 2
    ctx->r12 = S32(SIGNED(ctx->r14) >> 2);
    // 0x8045FEEC: or          $a1, $t3, $t4
    ctx->r5 = ctx->r11 | ctx->r12;
    // 0x8045FEF0: lbu         $t3, 0x12($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X12);
    // 0x8045FEF4: andi        $t2, $t8, 0xF8
    ctx->r10 = ctx->r24 & 0XF8;
    // 0x8045FEF8: lbu         $t8, 0x13($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X13);
    // 0x8045FEFC: andi        $t9, $t7, 0x80
    ctx->r25 = ctx->r15 & 0X80;
    // 0x8045FF00: sra         $t1, $t9, 7
    ctx->r9 = S32(SIGNED(ctx->r25) >> 7);
    // 0x8045FF04: sll         $t5, $t2, 8
    ctx->r13 = S32(ctx->r10 << 8);
    // 0x8045FF08: or          $t6, $t1, $t5
    ctx->r14 = ctx->r9 | ctx->r13;
    // 0x8045FF0C: andi        $t4, $t3, 0xF8
    ctx->r12 = ctx->r11 & 0XF8;
    // 0x8045FF10: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x8045FF14: andi        $t2, $t8, 0xF8
    ctx->r10 = ctx->r24 & 0XF8;
    // 0x8045FF18: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x8045FF1C: sra         $t1, $t2, 2
    ctx->r9 = S32(SIGNED(ctx->r10) >> 2);
    // 0x8045FF20: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8045FF24: or          $a2, $t9, $t1
    ctx->r6 = ctx->r25 | ctx->r9;
    // 0x8045FF28: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8045FF2C: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x8045FF30: or          $t4, $t3, $a2
    ctx->r12 = ctx->r11 | ctx->r6;
    // 0x8045FF34: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8045FF38: lui         $t5, 0xF700
    ctx->r13 = S32(0XF700 << 16);
    // 0x8045FF3C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8045FF40: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x8045FF44: lui         $t6, 0xF64F
    ctx->r14 = S32(0XF64F << 16);
    // 0x8045FF48: ori         $t6, $t6, 0xC3BC
    ctx->r14 = ctx->r14 | 0XC3BC;
    // 0x8045FF4C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8045FF50: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8045FF54: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x8045FF58: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x8045FF5C: jr          $ra
    // 0x8045FF60: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    return;
    // 0x8045FF60: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
;}
RECOMP_FUNC void func_800329B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800329B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800329BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800329C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800329C4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800329C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800329CC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800329D0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x800329D4: lwc1        $f18, 0x84($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800329D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800329DC: lwc1        $f10, 0x64($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X64);
    // 0x800329E0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800329E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800329E8: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800329EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800329F0: lw          $t7, 0x1EC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1EC);
    // 0x800329F4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800329F8: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x800329FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80032A00: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80032A04: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80032A08: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80032A0C: lwc1        $f18, 0x4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4C);
    // 0x80032A10: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80032A14: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80032A18: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80032A1C: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80032A20: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80032A24: jal         0x8003B9D8
    // 0x80032A28: nop

    func_8003B9D8(rdram, ctx);
        goto after_0;
    // 0x80032A28: nop

    after_0:
    // 0x80032A2C: beq         $v0, $zero, L_80032A78
    if (ctx->r2 == 0) {
        // 0x80032A30: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80032A78;
    }
    // 0x80032A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80032A34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80032A38: lwc1        $f14, 0x50($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X50);
    // 0x80032A3C: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80032A40: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80032A44: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80032A48: mul.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80032A4C: nop

    // 0x80032A50: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80032A54: nop

    // 0x80032A58: mul.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80032A5C: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x80032A60: swc1        $f0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f0.u32l;
    // 0x80032A64: swc1        $f2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f2.u32l;
    // 0x80032A68: swc1        $f2, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f2.u32l;
    // 0x80032A6C: swc1        $f12, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f12.u32l;
    // 0x80032A70: jal         0x80044194
    // 0x80032A74: swc1        $f12, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->f12.u32l;
    func_80044194(rdram, ctx);
        goto after_1;
    // 0x80032A74: swc1        $f12, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->f12.u32l;
    after_1:
L_80032A78:
    // 0x80032A78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80032A7C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80032A80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80032A84: jr          $ra
    // 0x80032A88: nop

    return;
    // 0x80032A88: nop

;}
RECOMP_FUNC void func_80680EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680EC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80680EC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680ECC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680ED0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80680ED4: jal         0x80680E08
    // 0x80680ED8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80680E08(rdram, ctx);
        goto after_0;
    // 0x80680ED8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80680EDC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80680EE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80680EE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80680EE8: lwc1        $f6, 0x8C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80680EEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80680EF0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80680EF4: nop

    // 0x80680EF8: bc1fl       L_80680F2C
    if (!c1cs) {
        // 0x80680EFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80680F2C;
    }
    goto skip_0;
    // 0x80680EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80680F00: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80680F04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80680F08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80680F0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80680F10: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80680F14: nop

    // 0x80680F18: bc1fl       L_80680F2C
    if (!c1cs) {
        // 0x80680F1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80680F2C;
    }
    goto skip_1;
    // 0x80680F1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80680F20: jal         0x806815B8
    // 0x80680F24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806815B8(rdram, ctx);
        goto after_1;
    // 0x80680F24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80680F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80680F2C:
    // 0x80680F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80680F30: jr          $ra
    // 0x80680F34: nop

    return;
    // 0x80680F34: nop

;}
RECOMP_FUNC void func_80038E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038E18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80038E1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80038E20: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80038E24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80038E28: lwc1        $f4, 0x14C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X14C);
    // 0x80038E2C: lwc1        $f6, 0x8C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8C);
    // 0x80038E30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80038E34: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x80038E38: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80038E3C: addiu       $t6, $a1, 0x78
    ctx->r14 = ADD32(ctx->r5, 0X78);
    // 0x80038E40: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80038E44: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80038E48: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80038E4C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80038E50: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80038E54: jal         0x80038B00
    // 0x80038E58: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80038B00(rdram, ctx);
        goto after_0;
    // 0x80038E58: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038E5C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80038E60: beq         $v0, $zero, L_80038E70
    if (ctx->r2 == 0) {
        // 0x80038E64: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80038E70;
    }
    // 0x80038E64: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80038E68: jal         0x80038CB8
    // 0x80038E6C: lw          $a0, 0x1F4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1F4);
    func_80038CB8(rdram, ctx);
        goto after_1;
    // 0x80038E6C: lw          $a0, 0x1F4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1F4);
    after_1:
L_80038E70:
    // 0x80038E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80038E74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80038E78: jr          $ra
    // 0x80038E7C: nop

    return;
    // 0x80038E7C: nop

;}
RECOMP_FUNC void func_80428A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428A34: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80428A38: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x80428A3C: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(41, 0X1C10) << 16);
    // 0x80428A40: lw          $t6, 0x690($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X690);
    // 0x80428A44: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80428A48: addiu       $t8, $t8, -0x6AB0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(41, 0X1C10));
    // 0x80428A4C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80428A50: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80428A54: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80428A58: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80428A5C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80428A60: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x80428A64: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    // 0x80428A68: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80428A6C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80428A70: addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // 0x80428A74: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x80428A78: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80428A7C: addiu       $v1, $t0, 0x8
    ctx->r3 = ADD32(ctx->r8, 0X8);
    // 0x80428A80: jr          $ra
    // 0x80428A84: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    return;
    // 0x80428A84: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_8079B7F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079B7F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079B7F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079B7FC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8079B800: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8079B804: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8079B808: lui         $t8, 0x807A
    ctx->r24 = S32(RELOC_HI16(829, 0XAE4) << 16);
    // 0x8079B80C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8079B810: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8079B814: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8079B818: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8079B81C: lw          $t8, -0x3DAC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(829, 0XAE4));
    // 0x8079B820: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8079B824: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8079B828: jal         0x80048490
    // 0x8079B82C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8079B82C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8079B830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079B834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079B838: jr          $ra
    // 0x8079B83C: nop

    return;
    // 0x8079B83C: nop

;}
RECOMP_FUNC void func_8069CFB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069CFB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069CFB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069CFB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8069CFBC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069CFC0: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8069CFC4: jal         0x80066DE4
    // 0x8069CFC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8069CFC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8069CFCC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8069CFD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8069CFD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8069CFD8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8069CFDC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8069CFE0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8069CFE4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8069CFE8: swc1        $f10, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f10.u32l;
    // 0x8069CFEC: jal         0x80066E88
    // 0x8069CFF0: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8069CFF0: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    after_1:
    // 0x8069CFF4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8069CFF8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8069CFFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8069D000: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8069D004: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8069D008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8069D00C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8069D010: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8069D014: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8069D018: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8069D01C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8069D020: swc1        $f6, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f6.u32l;
    // 0x8069D024: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8069D028: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8069D02C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8069D030: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8069D034: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8069D038: nop

    // 0x8069D03C: bc1fl       L_8069D050
    if (!c1cs) {
        // 0x8069D040: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8069D050;
    }
    goto skip_0;
    // 0x8069D040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8069D044: sub.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8069D048: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8069D04C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8069D050:
    // 0x8069D050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069D054: jr          $ra
    // 0x8069D058: nop

    return;
    // 0x8069D058: nop

;}
RECOMP_FUNC void func_804E99D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E99D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E99D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E99D8: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x804E99DC: addiu       $at, $zero, 0x44DE
    ctx->r1 = ADD32(0, 0X44DE);
    // 0x804E99E0: beq         $v0, $at, L_804E99F8
    if (ctx->r2 == ctx->r1) {
        // 0x804E99E4: addiu       $at, $zero, 0x44DF
        ctx->r1 = ADD32(0, 0X44DF);
            goto L_804E99F8;
    }
    // 0x804E99E4: addiu       $at, $zero, 0x44DF
    ctx->r1 = ADD32(0, 0X44DF);
    // 0x804E99E8: beq         $v0, $at, L_804E9A08
    if (ctx->r2 == ctx->r1) {
        // 0x804E99EC: nop
    
            goto L_804E9A08;
    }
    // 0x804E99EC: nop

    // 0x804E99F0: b           L_804E9A14
    // 0x804E99F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804E9A14;
    // 0x804E99F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804E99F8:
    // 0x804E99F8: jal         0x804E9A20
    // 0x804E99FC: nop

    func_804E9A20(rdram, ctx);
        goto after_0;
    // 0x804E99FC: nop

    after_0:
    // 0x804E9A00: b           L_804E9A14
    // 0x804E9A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804E9A14;
    // 0x804E9A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804E9A08:
    // 0x804E9A08: jal         0x804E9A70
    // 0x804E9A0C: nop

    func_804E9A70(rdram, ctx);
        goto after_1;
    // 0x804E9A0C: nop

    after_1:
    // 0x804E9A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804E9A14:
    // 0x804E9A14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E9A18: jr          $ra
    // 0x804E9A1C: nop

    return;
    // 0x804E9A1C: nop

;}
RECOMP_FUNC void func_80076828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076828: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007682C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076830: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80076834: addiu       $v0, $v0, -0x7ADC
    ctx->r2 = ADD32(ctx->r2, -0X7ADC);
    // 0x80076838: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8007683C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076840: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80076844: sw          $zero, -0x7AD8($at)
    MEM_W(-0X7AD8, ctx->r1) = 0;
    // 0x80076848: jal         0x80075710
    // 0x8007684C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80075710(rdram, ctx);
        goto after_0;
    // 0x8007684C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80076850: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80076854: addiu       $t7, $t7, -0x7B20
    ctx->r15 = ADD32(ctx->r15, -0X7B20);
    // 0x80076858: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007685C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80076860: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80076864: bne         $t8, $zero, L_800768F8
    if (ctx->r24 != 0) {
        // 0x80076868: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_800768F8;
    }
    // 0x80076868: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8007686C: jal         0x80075DAC
    // 0x80076870: sw          $t9, -0x26A0($at)
    MEM_W(-0X26A0, ctx->r1) = ctx->r25;
    func_80075DAC(rdram, ctx);
        goto after_1;
    // 0x80076870: sw          $t9, -0x26A0($at)
    MEM_W(-0X26A0, ctx->r1) = ctx->r25;
    after_1:
    // 0x80076874: jal         0x80075FDC
    // 0x80076878: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80075FDC(rdram, ctx);
        goto after_2;
    // 0x80076878: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x8007687C: lui         $t0, 0x800B
    ctx->r8 = S32(0X800B << 16);
    // 0x80076880: lw          $t0, -0x7AF0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AF0);
    // 0x80076884: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80076888: beql        $t1, $zero, L_8007689C
    if (ctx->r9 == 0) {
        // 0x8007688C: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_8007689C;
    }
    goto skip_0;
    // 0x8007688C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80076890: jal         0x80076070
    // 0x80076894: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80076070(rdram, ctx);
        goto after_3;
    // 0x80076894: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80076898: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_8007689C:
    // 0x8007689C: lui         $t5, 0xD00
    ctx->r13 = S32(0XD00 << 16);
    // 0x800768A0: addiu       $t5, $t5, 0x150
    ctx->r13 = ADD32(ctx->r13, 0X150);
    // 0x800768A4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800768A8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800768AC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800768B0: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x800768B4: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x800768B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800768BC: sw          $zero, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = 0;
    // 0x800768C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800768C4: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
    // 0x800768C8: jal         0x8007662C
    // 0x800768CC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_8007662C(rdram, ctx);
        goto after_4;
    // 0x800768CC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x800768D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800768D4: jal         0x80079140
    // 0x800768D8: addiu       $a0, $a0, -0x2600
    ctx->r4 = ADD32(ctx->r4, -0X2600);
    func_80079140(rdram, ctx);
        goto after_5;
    // 0x800768D8: addiu       $a0, $a0, -0x2600
    ctx->r4 = ADD32(ctx->r4, -0X2600);
    after_5:
    // 0x800768DC: beq         $v0, $zero, L_800768F0
    if (ctx->r2 == 0) {
        // 0x800768E0: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800768F0;
    }
    // 0x800768E0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800768E4: addiu       $a0, $a0, -0x2600
    ctx->r4 = ADD32(ctx->r4, -0X2600);
    // 0x800768E8: jal         0x80079060
    // 0x800768EC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80079060(rdram, ctx);
        goto after_6;
    // 0x800768EC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_6:
L_800768F0:
    // 0x800768F0: jal         0x80076190
    // 0x800768F4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80076190(rdram, ctx);
        goto after_7;
    // 0x800768F4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_7:
L_800768F8:
    // 0x800768F8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800768FC: jal         0x8007288C
    // 0x80076900: lw          $a0, -0x260C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X260C);
    func_8007288C(rdram, ctx);
        goto after_8;
    // 0x80076900: lw          $a0, -0x260C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X260C);
    after_8:
    // 0x80076904: jal         0x8007291C
    // 0x80076908: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8007291C(rdram, ctx);
        goto after_9;
    // 0x80076908: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x8007690C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076910: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80076914: jr          $ra
    // 0x80076918: nop

    return;
    // 0x80076918: nop

;}
RECOMP_FUNC void func_80006B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006B14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006B18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80006B1C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80006B20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80006B24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80006B28: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80006B2C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80006B30: jal         0x800073BC
    // 0x80006B34: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800073BC(rdram, ctx);
        goto after_0;
    // 0x80006B34: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80006B38: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80006B3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80006B40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80006B44: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80006B48: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80006B4C: jal         0x800078B4
    // 0x80006B50: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800078B4(rdram, ctx);
        goto after_1;
    // 0x80006B50: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x80006B54: bne         $v0, $zero, L_80006B68
    if (ctx->r2 != 0) {
        // 0x80006B58: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80006B68;
    }
    // 0x80006B58: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80006B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80006B60: jal         0x80082210
    // 0x80006B64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80006B64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80006B68:
    // 0x80006B68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80006B6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80006B70: jr          $ra
    // 0x80006B74: nop

    return;
    // 0x80006B74: nop

;}
RECOMP_FUNC void func_805D17AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D17AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D17B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D17B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D17B8: jal         0x80045A34
    // 0x805D17BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805D17BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x805D17C0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805D17C4: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x805D17C8: bne         $v0, $zero, L_805D17D8
    if (ctx->r2 != 0) {
        // 0x805D17CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D17D8;
    }
    // 0x805D17CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D17D0: b           L_805D17DC
    // 0x805D17D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805D17DC;
    // 0x805D17D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D17D8:
    // 0x805D17D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805D17DC:
    // 0x805D17DC: jr          $ra
    // 0x805D17E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805D17E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80519124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051912C: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x80519130: beql        $v0, $zero, L_80519164
    if (ctx->r2 == 0) {
        // 0x80519134: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80519164;
    }
    goto skip_0;
    // 0x80519134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80519138: jalr        $v0
    // 0x8051913C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8051913C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80519140: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80519144: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80519148: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x8051914C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80519150: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80519154: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80519158: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8051915C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x80519160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80519164:
    // 0x80519164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519168: jr          $ra
    // 0x8051916C: nop

    return;
    // 0x8051916C: nop

;}
RECOMP_FUNC void func_806E793C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E793C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806E7940: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806E7944: sll         $s1, $a1, 16
    ctx->r17 = S32(ctx->r5 << 16);
    // 0x806E7948: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x806E794C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806E7950: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E7954: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x806E7958: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x806E795C: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x806E7960: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x806E7964: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x806E7968: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x806E796C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x806E7970: beq         $s1, $zero, L_806E7A30
    if (ctx->r17 == 0) {
        // 0x806E7974: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_806E7A30;
    }
    // 0x806E7974: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x806E7978: addiu       $s7, $zero, 0x4001
    ctx->r23 = ADD32(0, 0X4001);
    // 0x806E797C: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
    // 0x806E7980: addiu       $s5, $zero, 0xB
    ctx->r21 = ADD32(0, 0XB);
    // 0x806E7984: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x806E7988: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x806E798C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_806E7990:
    // 0x806E7990: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x806E7994: beq         $v1, $zero, L_806E7A28
    if (ctx->r3 == 0) {
        // 0x806E7998: nop
    
            goto L_806E7A28;
    }
    // 0x806E7998: nop

    // 0x806E799C: beql        $s2, $v1, L_806E7A20
    if (ctx->r18 == ctx->r3) {
        // 0x806E79A0: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_806E7A20;
    }
    goto skip_0;
    // 0x806E79A0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x806E79A4: lh          $a1, 0x184($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X184);
    // 0x806E79A8: beql        $a1, $zero, L_806E79CC
    if (ctx->r5 == 0) {
        // 0x806E79AC: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_806E79CC;
    }
    goto skip_1;
    // 0x806E79AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x806E79B0: jal         0x806E793C
    // 0x806E79B4: addiu       $a0, $v1, 0x188
    ctx->r4 = ADD32(ctx->r3, 0X188);
    func_806E793C(rdram, ctx);
        goto after_0;
    // 0x806E79B4: addiu       $a0, $v1, 0x188
    ctx->r4 = ADD32(ctx->r3, 0X188);
    after_0:
    // 0x806E79B8: beql        $v0, $zero, L_806E79CC
    if (ctx->r2 == 0) {
        // 0x806E79BC: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_806E79CC;
    }
    goto skip_2;
    // 0x806E79BC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x806E79C0: b           L_806E7A38
    // 0x806E79C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_806E7A38;
    // 0x806E79C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x806E79C8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_806E79CC:
    // 0x806E79CC: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x806E79D0: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x806E79D4: bnel        $s3, $t7, L_806E7A20
    if (ctx->r19 != ctx->r15) {
        // 0x806E79D8: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_806E7A20;
    }
    goto skip_3;
    // 0x806E79D8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_3:
    // 0x806E79DC: lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XE);
    // 0x806E79E0: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x806E79E4: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x806E79E8: beql        $s4, $v0, L_806E7A0C
    if (ctx->r20 == ctx->r2) {
        // 0x806E79EC: lhu         $t8, 0xC($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0XC);
            goto L_806E7A0C;
    }
    goto skip_4;
    // 0x806E79EC: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    skip_4:
    // 0x806E79F0: beql        $s5, $v0, L_806E7A0C
    if (ctx->r21 == ctx->r2) {
        // 0x806E79F4: lhu         $t8, 0xC($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0XC);
            goto L_806E7A0C;
    }
    goto skip_5;
    // 0x806E79F4: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    skip_5:
    // 0x806E79F8: beql        $v0, $zero, L_806E7A0C
    if (ctx->r2 == 0) {
        // 0x806E79FC: lhu         $t8, 0xC($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0XC);
            goto L_806E7A0C;
    }
    goto skip_6;
    // 0x806E79FC: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    skip_6:
    // 0x806E7A00: bnel        $s6, $v0, L_806E7A20
    if (ctx->r22 != ctx->r2) {
        // 0x806E7A04: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_806E7A20;
    }
    goto skip_7;
    // 0x806E7A04: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_7:
    // 0x806E7A08: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
L_806E7A0C:
    // 0x806E7A0C: beql        $s7, $t8, L_806E7A20
    if (ctx->r23 == ctx->r24) {
        // 0x806E7A10: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_806E7A20;
    }
    goto skip_8;
    // 0x806E7A10: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_8:
    // 0x806E7A14: b           L_806E7A34
    // 0x806E7A18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_806E7A34;
    // 0x806E7A18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x806E7A1C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_806E7A20:
    // 0x806E7A20: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x806E7A24: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
L_806E7A28:
    // 0x806E7A28: bne         $s1, $zero, L_806E7990
    if (ctx->r17 != 0) {
        // 0x806E7A2C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_806E7990;
    }
    // 0x806E7A2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_806E7A30:
    // 0x806E7A30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806E7A34:
    // 0x806E7A34: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_806E7A38:
    // 0x806E7A38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806E7A3C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806E7A40: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x806E7A44: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x806E7A48: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x806E7A4C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x806E7A50: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x806E7A54: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x806E7A58: jr          $ra
    // 0x806E7A5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x806E7A5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_804CC480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CC484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CC488: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x804CC48C: addiu       $t7, $t6, -0x4131
    ctx->r15 = ADD32(ctx->r14, -0X4131);
    // 0x804CC490: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x804CC494: beq         $at, $zero, L_804CC538
    if (ctx->r1 == 0) {
        // 0x804CC498: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_804CC538;
    }
    // 0x804CC498: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804CC49C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(237, 0X1C90) << 16);
    // 0x804CC4A0: addu        $at, $at, $t7
    gpr jr_addend_804CC4A8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x804CC4A4: lw          $t7, -0x1F00($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(237, 0X1C90));
    // 0x804CC4A8: jr          $t7
    // 0x804CC4AC: nop

    switch (jr_addend_804CC4A8 >> 2) {
        case 0: goto L_804CC4B0; break;
        case 1: goto L_804CC4C0; break;
        case 2: goto L_804CC4D0; break;
        case 3: goto L_804CC4E0; break;
        case 4: goto L_804CC4F0; break;
        case 5: goto L_804CC500; break;
        case 6: goto L_804CC510; break;
        case 7: goto L_804CC520; break;
        case 8: goto L_804CC530; break;
        default: switch_error(__func__, 0x804CC4A8, 0x804CE100);
    }
    // 0x804CC4AC: nop

L_804CC4B0:
    // 0x804CC4B0: jal         0x804CC560
    // 0x804CC4B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_804CC560(rdram, ctx);
        goto after_0;
    // 0x804CC4B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x804CC4B8: b           L_804CC53C
    // 0x804CC4BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CC53C;
    // 0x804CC4BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC4C0:
    // 0x804CC4C0: jal         0x804CC560
    // 0x804CC4C4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_804CC560(rdram, ctx);
        goto after_1;
    // 0x804CC4C4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x804CC4C8: b           L_804CC53C
    // 0x804CC4CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CC53C;
    // 0x804CC4CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC4D0:
    // 0x804CC4D0: jal         0x804CC560
    // 0x804CC4D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_804CC560(rdram, ctx);
        goto after_2;
    // 0x804CC4D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x804CC4D8: b           L_804CC53C
    // 0x804CC4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CC53C;
    // 0x804CC4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC4E0:
    // 0x804CC4E0: jal         0x804CC560
    // 0x804CC4E4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_804CC560(rdram, ctx);
        goto after_3;
    // 0x804CC4E4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x804CC4E8: b           L_804CC53C
    // 0x804CC4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CC53C;
    // 0x804CC4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC4F0:
    // 0x804CC4F0: jal         0x804CC61C
    // 0x804CC4F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_804CC61C(rdram, ctx);
        goto after_4;
    // 0x804CC4F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x804CC4F8: b           L_804CC53C
    // 0x804CC4FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CC53C;
    // 0x804CC4FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC500:
    // 0x804CC500: jal         0x804CC61C
    // 0x804CC504: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_804CC61C(rdram, ctx);
        goto after_5;
    // 0x804CC504: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_5:
    // 0x804CC508: b           L_804CC53C
    // 0x804CC50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CC53C;
    // 0x804CC50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC510:
    // 0x804CC510: jal         0x804CC61C
    // 0x804CC514: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_804CC61C(rdram, ctx);
        goto after_6;
    // 0x804CC514: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_6:
    // 0x804CC518: b           L_804CC53C
    // 0x804CC51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CC53C;
    // 0x804CC51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC520:
    // 0x804CC520: jal         0x804CC61C
    // 0x804CC524: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_804CC61C(rdram, ctx);
        goto after_7;
    // 0x804CC524: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_7:
    // 0x804CC528: b           L_804CC53C
    // 0x804CC52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CC53C;
    // 0x804CC52C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC530:
    // 0x804CC530: jal         0x804CC79C
    // 0x804CC534: nop

    func_804CC79C(rdram, ctx);
        goto after_8;
    // 0x804CC534: nop

    after_8:
L_804CC538:
    // 0x804CC538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC53C:
    // 0x804CC53C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CC540: jr          $ra
    // 0x804CC544: nop

    return;
    // 0x804CC544: nop

;}
RECOMP_FUNC void func_8045FF64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FF64: jr          $ra
    // 0x8045FF68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8045FF68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806EC20C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC20C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EC210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EC214: jal         0x806EC124
    // 0x806EC218: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806EC124(rdram, ctx);
        goto after_0;
    // 0x806EC218: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EC21C: jal         0x80045BD8
    // 0x806EC220: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x806EC220: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806EC224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EC228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EC22C: jr          $ra
    // 0x806EC230: nop

    return;
    // 0x806EC230: nop

;}
RECOMP_FUNC void func_806F35BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F35BC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806F35C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806F35C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F35C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F35CC: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x806F35D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806F35D4: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x806F35D8: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x806F35DC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806F35E0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x806F35E4: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x806F35E8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x806F35EC: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x806F35F0: bc1f        L_806F35FC
    if (!c1cs) {
        // 0x806F35F4: addiu       $v1, $v1, 0xD
        ctx->r3 = ADD32(ctx->r3, 0XD);
            goto L_806F35FC;
    }
    // 0x806F35F4: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x806F35F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_806F35FC:
    // 0x806F35FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F3600: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X920) << 16);
    // 0x806F3604: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x806F3608: lwc1        $f4, 0x3D70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X920));
    // 0x806F360C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806F3610: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806F3614: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x806F3618: nop

    // 0x806F361C: bc1fl       L_806F362C
    if (!c1cs) {
        // 0x806F3620: swc1        $f0, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
            goto L_806F362C;
    }
    goto skip_0;
    // 0x806F3620: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    skip_0:
    // 0x806F3624: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x806F3628: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
L_806F362C:
    // 0x806F362C: bne         $v0, $at, L_806F3698
    if (ctx->r2 != ctx->r1) {
        // 0x806F3630: sub.s       $f2, $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_806F3698;
    }
    // 0x806F3630: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x806F3634: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F3638: nop

    // 0x806F363C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806F3640: nop

    // 0x806F3644: bc1fl       L_806F3710
    if (!c1cs) {
        // 0x806F3648: cfc1        $t4, $FpcCsr
        ctx->r12 = get_cop1_cs();
            goto L_806F3710;
    }
    goto skip_1;
    // 0x806F3648: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    skip_1:
    // 0x806F364C: lw          $a0, 0x180($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X180);
    // 0x806F3650: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X9A0) << 16);
    // 0x806F3654: lwc1        $f6, 0x3DF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X9A0));
    // 0x806F3658: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F365C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X9A4) << 16);
    // 0x806F3660: lwc1        $f0, 0x8($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X8);
    // 0x806F3664: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x806F3668: nop

    // 0x806F366C: bc1tl       L_806F3710
    if (c1cs) {
        // 0x806F3670: cfc1        $t4, $FpcCsr
        ctx->r12 = get_cop1_cs();
            goto L_806F3710;
    }
    goto skip_2;
    // 0x806F3670: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    skip_2:
    // 0x806F3674: lwc1        $f8, 0x3DF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X9A4));
    // 0x806F3678: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806F367C: nop

    // 0x806F3680: bc1tl       L_806F3710
    if (c1cs) {
        // 0x806F3684: cfc1        $t4, $FpcCsr
        ctx->r12 = get_cop1_cs();
            goto L_806F3710;
    }
    goto skip_3;
    // 0x806F3684: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    skip_3:
    // 0x806F3688: jal         0x800447C8
    // 0x806F368C: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x806F368C: nop

    after_0:
    // 0x806F3690: b           L_806F379C
    // 0x806F3694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806F379C;
    // 0x806F3694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F3698:
    // 0x806F3698: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F369C: nop

    // 0x806F36A0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806F36A4: nop

    // 0x806F36A8: bc1fl       L_806F36BC
    if (!c1cs) {
        // 0x806F36AC: lw          $t9, 0x174($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X174);
            goto L_806F36BC;
    }
    goto skip_4;
    // 0x806F36AC: lw          $t9, 0x174($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X174);
    skip_4:
    // 0x806F36B0: b           L_806F370C
    // 0x806F36B4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_806F370C;
    // 0x806F36B4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x806F36B8: lw          $t9, 0x174($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X174);
L_806F36BC:
    // 0x806F36BC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806F36C0: lbu         $t1, 0x74($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X74);
    // 0x806F36C4: beql        $t1, $zero, L_806F3710
    if (ctx->r9 == 0) {
        // 0x806F36C8: cfc1        $t4, $FpcCsr
        ctx->r12 = get_cop1_cs();
            goto L_806F3710;
    }
    goto skip_5;
    // 0x806F36C8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    skip_5:
    // 0x806F36CC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x806F36D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806F36D4: bc1fl       L_806F3710
    if (!c1cs) {
        // 0x806F36D8: cfc1        $t4, $FpcCsr
        ctx->r12 = get_cop1_cs();
            goto L_806F3710;
    }
    goto skip_6;
    // 0x806F36D8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    skip_6:
    // 0x806F36DC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x806F36E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806F36E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806F36E8: jal         0x8005FE48
    // 0x806F36EC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x806F36EC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x806F36F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x806F36F4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806F36F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806F36FC: lw          $t2, 0x174($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X174);
    // 0x806F3700: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806F3704: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x806F3708: sb          $zero, 0x74($t3)
    MEM_B(0X74, ctx->r11) = 0;
L_806F370C:
    // 0x806F370C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
L_806F3710:
    // 0x806F3710: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x806F3714: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x806F3718: swc1        $f2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f2.u32l;
    // 0x806F371C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x806F3720: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x806F3724: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x806F3728: nop

    // 0x806F372C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x806F3730: beql        $t5, $zero, L_806F3780
    if (ctx->r13 == 0) {
        // 0x806F3734: mfc1        $t5, $f10
        ctx->r13 = (int32_t)ctx->f10.u32l;
            goto L_806F3780;
    }
    goto skip_7;
    // 0x806F3734: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    skip_7:
    // 0x806F3738: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806F373C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x806F3740: sub.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x806F3744: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x806F3748: nop

    // 0x806F374C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x806F3750: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x806F3754: nop

    // 0x806F3758: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x806F375C: bne         $t5, $zero, L_806F3774
    if (ctx->r13 != 0) {
        // 0x806F3760: nop
    
            goto L_806F3774;
    }
    // 0x806F3760: nop

    // 0x806F3764: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x806F3768: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806F376C: b           L_806F378C
    // 0x806F3770: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_806F378C;
    // 0x806F3770: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_806F3774:
    // 0x806F3774: b           L_806F378C
    // 0x806F3778: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_806F378C;
    // 0x806F3778: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x806F377C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
L_806F3780:
    // 0x806F3780: nop

    // 0x806F3784: bltz        $t5, L_806F3774
    if (SIGNED(ctx->r13) < 0) {
        // 0x806F3788: nop
    
            goto L_806F3774;
    }
    // 0x806F3788: nop

L_806F378C:
    // 0x806F378C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x806F3790: sb          $t5, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r13;
    // 0x806F3794: nop

    // 0x806F3798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F379C:
    // 0x806F379C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F37A0: jr          $ra
    // 0x806F37A4: nop

    return;
    // 0x806F37A4: nop

;}
RECOMP_FUNC void func_8040D410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D410: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8040D414: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8040D418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040D41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040D420: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x8040D424: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040D428: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8040D42C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8040D430: bc1fl       L_8040D448
    if (!c1cs) {
        // 0x8040D434: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8040D448;
    }
    goto skip_0;
    // 0x8040D434: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x8040D438: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040D43C: b           L_8040D490
    // 0x8040D440: swc1        $f6, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f6.u32l;
        goto L_8040D490;
    // 0x8040D440: swc1        $f6, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f6.u32l;
    // 0x8040D444: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8040D448:
    // 0x8040D448: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8040D44C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8040D450: nop

    // 0x8040D454: bc1fl       L_8040D494
    if (!c1cs) {
        // 0x8040D458: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040D494;
    }
    goto skip_1;
    // 0x8040D458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8040D45C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8040D460: sw          $zero, 0x34($a1)
    MEM_W(0X34, ctx->r5) = 0;
    // 0x8040D464: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040D468: swc1        $f10, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f10.u32l;
    // 0x8040D46C: lbu         $t6, 0x165($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X165);
    // 0x8040D470: beql        $t6, $at, L_8040D494
    if (ctx->r14 == ctx->r1) {
        // 0x8040D474: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040D494;
    }
    goto skip_2;
    // 0x8040D474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8040D478: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8040D47C: jal         0x80067BBC
    // 0x8040D480: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8040D480: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_0:
    // 0x8040D484: addiu       $a0, $zero, 0x9F
    ctx->r4 = ADD32(0, 0X9F);
    // 0x8040D488: jal         0x80067818
    // 0x8040D48C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8040D48C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
L_8040D490:
    // 0x8040D490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040D494:
    // 0x8040D494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040D498: jr          $ra
    // 0x8040D49C: nop

    return;
    // 0x8040D49C: nop

;}
RECOMP_FUNC void func_8079AD94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079AD94: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079AD98: jr          $ra
    // 0x8079AD9C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    return;
    // 0x8079AD9C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void func_806F897C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F897C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F8980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F8984: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x806F8988: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x806F898C: beq         $v0, $zero, L_806F899C
    if (ctx->r2 == 0) {
        // 0x806F8990: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806F899C;
    }
    // 0x806F8990: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806F8994: b           L_806F89D4
    // 0x806F8998: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_806F89D4;
    // 0x806F8998: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_806F899C:
    // 0x806F899C: jal         0x8004700C
    // 0x806F89A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806F89A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x806F89A4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x806F89A8: beq         $v0, $zero, L_806F89D4
    if (ctx->r2 == 0) {
        // 0x806F89AC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_806F89D4;
    }
    // 0x806F89AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806F89B0: lw          $t8, 0x1F4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1F4);
    // 0x806F89B4: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x806F89B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806F89BC: sb          $t7, 0x1B4($t8)
    MEM_B(0X1B4, ctx->r24) = ctx->r15;
    // 0x806F89C0: lw          $t9, 0x260($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X260);
    // 0x806F89C4: lbu         $a0, 0x15($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X15);
    // 0x806F89C8: jal         0x80062DD4
    // 0x806F89CC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80062DD4(rdram, ctx);
        goto after_1;
    // 0x806F89CC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x806F89D0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_806F89D4:
    // 0x806F89D4: lw          $t0, 0x1F4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1F4);
    // 0x806F89D8: jal         0x806F84D8
    // 0x806F89DC: lwc1        $f12, 0x268($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X268);
    func_806F84D8(rdram, ctx);
        goto after_2;
    // 0x806F89DC: lwc1        $f12, 0x268($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X268);
    after_2:
    // 0x806F89E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F89E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F89E8: jr          $ra
    // 0x806F89EC: nop

    return;
    // 0x806F89EC: nop

;}
RECOMP_FUNC void func_8051EA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051EA00: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(300, 0X148) << 16);
    // 0x8051EA04: addiu       $v0, $v0, -0x14B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(300, 0X148));
    // 0x8051EA08: jr          $ra
    // 0x8051EA0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8051EA0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804A0440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0440: lui         $t6, 0x804A
    ctx->r14 = S32(RELOC_HI16(173, 0X20) << 16);
    // 0x804A0444: addiu       $t6, $t6, 0x460
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(173, 0X20));
    // 0x804A0448: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804A044C: lui         $v0, 0x804A
    ctx->r2 = S32(RELOC_HI16(173, 0X108) << 16);
    // 0x804A0450: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804A0454: sw          $t6, -0x7208($at)
    MEM_W(-0X7208, ctx->r1) = ctx->r14;
    // 0x804A0458: jr          $ra
    // 0x804A045C: addiu       $v0, $v0, 0x548
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(173, 0X108));
    return;
    // 0x804A045C: addiu       $v0, $v0, 0x548
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(173, 0X108));
;}
RECOMP_FUNC void func_80035DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035DA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035DB0: lw          $t6, 0x12D0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X12D0);
    // 0x80035DB4: beql        $t6, $zero, L_80035DF4
    if (ctx->r14 == 0) {
        // 0x80035DB8: lw          $t8, 0x14($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X14);
            goto L_80035DF4;
    }
    goto skip_0;
    // 0x80035DB8: lw          $t8, 0x14($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X14);
    skip_0:
    // 0x80035DBC: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x80035DC0: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80035DC4: beq         $t7, $zero, L_80035DE8
    if (ctx->r15 == 0) {
        // 0x80035DC8: nop
    
            goto L_80035DE8;
    }
    // 0x80035DC8: nop

    // 0x80035DCC: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80035DD0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80035DD4: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x80035DD8: jalr        $t9
    // 0x80035DDC: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80035DDC: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x80035DE0: b           L_80035E18
    // 0x80035DE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80035E18;
    // 0x80035DE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80035DE8:
    // 0x80035DE8: b           L_80035E18
    // 0x80035DEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80035E18;
    // 0x80035DEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80035DF0: lw          $t8, 0x14($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X14);
L_80035DF4:
    // 0x80035DF4: bne         $t8, $zero, L_80035E0C
    if (ctx->r24 != 0) {
        // 0x80035DF8: nop
    
            goto L_80035E0C;
    }
    // 0x80035DF8: nop

    // 0x80035DFC: jal         0x80035D2C
    // 0x80035E00: nop

    func_80035D2C(rdram, ctx);
        goto after_1;
    // 0x80035E00: nop

    after_1:
    // 0x80035E04: b           L_80035E18
    // 0x80035E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80035E18;
    // 0x80035E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80035E0C:
    // 0x80035E0C: jal         0x80035C80
    // 0x80035E10: nop

    func_80035C80(rdram, ctx);
        goto after_2;
    // 0x80035E10: nop

    after_2:
    // 0x80035E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80035E18:
    // 0x80035E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035E20: jr          $ra
    // 0x80035E24: nop

    return;
    // 0x80035E24: nop

;}
RECOMP_FUNC void func_800682D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800682D4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800682D8: lw          $t6, -0x6C74($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C74);
    // 0x800682DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800682E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800682E4: beql        $t6, $zero, L_80068314
    if (ctx->r14 == 0) {
        // 0x800682E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068314;
    }
    goto skip_0;
    // 0x800682E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800682EC: jal         0x800677F8
    // 0x800682F0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x800682F0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_0:
    // 0x800682F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800682F8: jal         0x80067ACC
    // 0x800682FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067ACC(rdram, ctx);
        goto after_1;
    // 0x800682FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80068300: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068304: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068308: sw          $zero, 0x14EC($v0)
    MEM_W(0X14EC, ctx->r2) = 0;
    // 0x8006830C: sw          $zero, 0x14E8($v0)
    MEM_W(0X14E8, ctx->r2) = 0;
    // 0x80068310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068314:
    // 0x80068314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068318: jr          $ra
    // 0x8006831C: nop

    return;
    // 0x8006831C: nop

;}
RECOMP_FUNC void func_80052BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80052BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052BAC: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x80052BB0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80052BB4: beql        $a1, $zero, L_80052C80
    if (ctx->r5 == 0) {
        // 0x80052BB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80052C80;
    }
    goto skip_0;
    // 0x80052BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80052BBC: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    // 0x80052BC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80052BC4: jal         0x8005BB78
    // 0x80052BC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8005BB78(rdram, ctx);
        goto after_0;
    // 0x80052BC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80052BCC: beq         $v0, $zero, L_80052C10
    if (ctx->r2 == 0) {
        // 0x80052BD0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80052C10;
    }
    // 0x80052BD0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80052BD4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80052BD8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80052BDC: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x80052BE0: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x80052BE4: sh          $t7, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r15;
    // 0x80052BE8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80052BEC: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x80052BF0: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x80052BF4: sh          $t9, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r25;
    // 0x80052BF8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80052BFC: lw          $t0, 0x20($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X20);
    // 0x80052C00: lh          $t1, 0x10($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X10);
    // 0x80052C04: sh          $t1, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r9;
    // 0x80052C08: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80052C0C: sb          $t2, 0x74($t3)
    MEM_B(0X74, ctx->r11) = ctx->r10;
L_80052C10:
    // 0x80052C10: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80052C14: lhu         $a0, 0xC($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0XC);
    // 0x80052C18: jal         0x8005BC68
    // 0x80052C1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8005BC68(rdram, ctx);
        goto after_1;
    // 0x80052C1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80052C20: beq         $v0, $zero, L_80052C34
    if (ctx->r2 == 0) {
        // 0x80052C24: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80052C34;
    }
    // 0x80052C24: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80052C28: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80052C2C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80052C30: sb          $t5, 0x75($t6)
    MEM_B(0X75, ctx->r14) = ctx->r13;
L_80052C34:
    // 0x80052C34: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80052C38: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80052C3C: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x80052C40: beql        $t8, $zero, L_80052C80
    if (ctx->r24 == 0) {
        // 0x80052C44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80052C80;
    }
    goto skip_1;
    // 0x80052C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80052C48: lhu         $a0, 0xC($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0XC);
    // 0x80052C4C: jal         0x8005BDF8
    // 0x80052C50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8005BDF8(rdram, ctx);
        goto after_2;
    // 0x80052C50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80052C54: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80052C58: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80052C5C: lw          $t0, 0x2C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2C);
    // 0x80052C60: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80052C64: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80052C68: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80052C6C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80052C70: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80052C74: jal         0x8004A73C
    // 0x80052C78: sh          $t3, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r11;
    func_8004A73C(rdram, ctx);
        goto after_3;
    // 0x80052C78: sh          $t3, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r11;
    after_3:
    // 0x80052C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80052C80:
    // 0x80052C80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80052C84: jr          $ra
    // 0x80052C88: nop

    return;
    // 0x80052C88: nop

    // 0x80052C8C: nop

;}
RECOMP_FUNC void func_8041F2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041F2E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8041F2EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041F2F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041F2F4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041F2F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041F2FC: jal         0x8041DB1C
    // 0x8041F300: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041F300: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8041F304: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8041F308: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8041F30C: jal         0x80048F84
    // 0x8041F310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8041F310: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8041F314: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8041F318: jal         0x80048F84
    // 0x8041F31C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8041F31C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8041F320: jal         0x8041E5E8
    // 0x8041F324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_3;
    // 0x8041F324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8041F328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F32C: jal         0x8041E430
    // 0x8041F330: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8041E430(rdram, ctx);
        goto after_4;
    // 0x8041F330: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8041F334: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8041F338: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8041F33C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8041F340: nop

    // 0x8041F344: bc1fl       L_8041F380
    if (!c1cs) {
        // 0x8041F348: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F380;
    }
    goto skip_0;
    // 0x8041F348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8041F34C: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8041F350: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8041F354: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8041F358: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8041F35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041F364: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8041F368: bc1fl       L_8041F380
    if (!c1cs) {
        // 0x8041F36C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F380;
    }
    goto skip_1;
    // 0x8041F36C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8041F370: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x8041F374: jal         0x8041FE10
    // 0x8041F378: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_5;
    // 0x8041F378: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
    // 0x8041F37C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041F380:
    // 0x8041F380: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041F384: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8041F388: jr          $ra
    // 0x8041F38C: nop

    return;
    // 0x8041F38C: nop

;}
RECOMP_FUNC void func_80052D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052D1C: addiu       $sp, $sp, -0x8E8
    ctx->r29 = ADD32(ctx->r29, -0X8E8);
    // 0x80052D20: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80052D24: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80052D28: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80052D2C: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80052D30: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80052D34: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80052D38: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80052D3C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80052D40: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80052D44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80052D48: sw          $a2, 0x8F0($sp)
    MEM_W(0X8F0, ctx->r29) = ctx->r6;
    // 0x80052D4C: sw          $a3, 0x8F4($sp)
    MEM_W(0X8F4, ctx->r29) = ctx->r7;
    // 0x80052D50: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80052D54: beq         $a1, $zero, L_80052E14
    if (ctx->r5 == 0) {
        // 0x80052D58: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_80052E14;
    }
    // 0x80052D58: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80052D5C: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80052D60: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80052D64: beq         $v1, $zero, L_80052DA0
    if (ctx->r3 == 0) {
        // 0x80052D68: addu        $a0, $v1, $a1
        ctx->r4 = ADD32(ctx->r3, ctx->r5);
            goto L_80052DA0;
    }
    // 0x80052D68: addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
    // 0x80052D6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80052D70: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
L_80052D74:
    // 0x80052D74: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80052D78: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80052D7C: lbu         $t6, 0x14($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X14);
    // 0x80052D80: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80052D84: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x80052D88: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x80052D8C: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80052D90: bne         $a0, $t0, L_80052D74
    if (ctx->r4 != ctx->r8) {
        // 0x80052D94: sb          $t6, -0x3($v0)
        MEM_B(-0X3, ctx->r2) = ctx->r14;
            goto L_80052D74;
    }
    // 0x80052D94: sb          $t6, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r14;
    // 0x80052D98: beql        $t0, $zero, L_80052E18
    if (ctx->r8 == 0) {
        // 0x80052D9C: sltiu       $at, $s6, 0x14
        ctx->r1 = ctx->r22 < 0X14 ? 1 : 0;
            goto L_80052E18;
    }
    goto skip_0;
    // 0x80052D9C: sltiu       $at, $s6, 0x14
    ctx->r1 = ctx->r22 < 0X14 ? 1 : 0;
    skip_0:
L_80052DA0:
    // 0x80052DA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80052DA4: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
L_80052DA8:
    // 0x80052DA8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80052DAC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80052DB0: lbu         $t7, 0x14($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X14);
    // 0x80052DB4: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80052DB8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80052DBC: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x80052DC0: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x80052DC4: sb          $t7, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r15;
    // 0x80052DC8: lbu         $t8, 0x14($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X14);
    // 0x80052DCC: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x80052DD0: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x80052DD4: sh          $v1, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r3;
    // 0x80052DD8: sb          $zero, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = 0;
    // 0x80052DDC: sb          $t8, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r24;
    // 0x80052DE0: lbu         $t9, 0x14($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X14);
    // 0x80052DE4: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x80052DE8: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80052DEC: sh          $v1, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r3;
    // 0x80052DF0: sb          $zero, 0x44($v0)
    MEM_B(0X44, ctx->r2) = 0;
    // 0x80052DF4: sb          $t9, 0x45($v0)
    MEM_B(0X45, ctx->r2) = ctx->r25;
    // 0x80052DF8: lbu         $t2, 0x14($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X14);
    // 0x80052DFC: addiu       $t0, $t0, -0x4
    ctx->r8 = ADD32(ctx->r8, -0X4);
    // 0x80052E00: sh          $v1, 0x48($v0)
    MEM_H(0X48, ctx->r2) = ctx->r3;
    // 0x80052E04: sb          $zero, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = 0;
    // 0x80052E08: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // 0x80052E0C: bne         $t0, $zero, L_80052DA8
    if (ctx->r8 != 0) {
        // 0x80052E10: sb          $t2, -0x3($v0)
        MEM_B(-0X3, ctx->r2) = ctx->r10;
            goto L_80052DA8;
    }
    // 0x80052E10: sb          $t2, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r10;
L_80052E14:
    // 0x80052E14: sltiu       $at, $s6, 0x14
    ctx->r1 = ctx->r22 < 0X14 ? 1 : 0;
L_80052E18:
    // 0x80052E18: bne         $at, $zero, L_80052E24
    if (ctx->r1 != 0) {
        // 0x80052E1C: lui         $s0, 0x800A
        ctx->r16 = S32(0X800A << 16);
            goto L_80052E24;
    }
    // 0x80052E1C: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80052E20: addiu       $s6, $zero, 0x13
    ctx->r22 = ADD32(0, 0X13);
L_80052E24:
    // 0x80052E24: addiu       $s0, $s0, 0x60D0
    ctx->r16 = ADD32(ctx->r16, 0X60D0);
    // 0x80052E28: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80052E2C: bnel        $t3, $zero, L_80052E50
    if (ctx->r11 != 0) {
        // 0x80052E30: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80052E50;
    }
    goto skip_1;
    // 0x80052E30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80052E34: jal         0x80052CDC
    // 0x80052E38: nop

    func_80052CDC(rdram, ctx);
        goto after_0;
    // 0x80052E38: nop

    after_0:
    // 0x80052E3C: bnel        $v0, $zero, L_80052E50
    if (ctx->r2 != 0) {
        // 0x80052E40: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80052E50;
    }
    goto skip_2;
    // 0x80052E40: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80052E44: b           L_80053498
    // 0x80052E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80053498;
    // 0x80052E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80052E4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80052E50:
    // 0x80052E50: lw          $t4, 0x16C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X16C);
    // 0x80052E54: lw          $v1, 0x1B0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X1B0);
    // 0x80052E58: beq         $v1, $zero, L_80052E70
    if (ctx->r3 == 0) {
        // 0x80052E5C: nop
    
            goto L_80052E70;
    }
    // 0x80052E5C: nop

    // 0x80052E60: lw          $t5, 0x20($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X20);
    // 0x80052E64: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x80052E68: bne         $t6, $zero, L_80052E78
    if (ctx->r14 != 0) {
        // 0x80052E6C: nop
    
            goto L_80052E78;
    }
    // 0x80052E6C: nop

L_80052E70:
    // 0x80052E70: b           L_80053498
    // 0x80052E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80053498;
    // 0x80052E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80052E78:
    // 0x80052E78: jal         0x80049018
    // 0x80052E7C: lw          $a0, 0x8F8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8F8);
    func_80049018(rdram, ctx);
        goto after_1;
    // 0x80052E7C: lw          $a0, 0x8F8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8F8);
    after_1:
    // 0x80052E80: lw          $t9, 0x8F0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8F0);
    // 0x80052E84: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80052E88: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80052E8C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80052E90: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80052E94: lwc1        $f0, 0x60D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X60D4);
    // 0x80052E98: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80052E9C: lw          $s5, 0x8FC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X8FC);
    // 0x80052EA0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80052EA4: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80052EA8: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80052EAC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80052EB0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80052EB4: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80052EB8: nop

    // 0x80052EBC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80052EC0: jal         0x8006A99C
    // 0x80052EC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_2;
    // 0x80052EC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x80052EC8: lw          $t3, 0x8F4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8F4);
    // 0x80052ECC: sh          $v0, 0x8B8($sp)
    MEM_H(0X8B8, ctx->r29) = ctx->r2;
    // 0x80052ED0: lwc1        $f18, 0x4($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X4);
    // 0x80052ED4: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80052ED8: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80052EDC: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80052EE0: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80052EE4: nop

    // 0x80052EE8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80052EEC: jal         0x8006A99C
    // 0x80052EF0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_3;
    // 0x80052EF0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
    // 0x80052EF4: lh          $v1, 0x8B8($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X8B8);
    // 0x80052EF8: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80052EFC: sltiu       $at, $s6, 0x2
    ctx->r1 = ctx->r22 < 0X2 ? 1 : 0;
    // 0x80052F00: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80052F04: sh          $v0, 0x88A($sp)
    MEM_H(0X88A, ctx->r29) = ctx->r2;
    // 0x80052F08: sh          $v0, 0x890($sp)
    MEM_H(0X890, ctx->r29) = ctx->r2;
    // 0x80052F0C: sh          $v1, 0x884($sp)
    MEM_H(0X884, ctx->r29) = ctx->r3;
    // 0x80052F10: bne         $at, $zero, L_80053014
    if (ctx->r1 != 0) {
        // 0x80052F14: sh          $v1, 0x888($sp)
        MEM_H(0X888, ctx->r29) = ctx->r3;
            goto L_80053014;
    }
    // 0x80052F14: sh          $v1, 0x888($sp)
    MEM_H(0X888, ctx->r29) = ctx->r3;
    // 0x80052F18: lw          $s3, 0x8F0($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8F0);
    // 0x80052F1C: lw          $s4, 0x8F4($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X8F4);
    // 0x80052F20: sll         $t5, $s6, 1
    ctx->r13 = S32(ctx->r22 << 1);
    // 0x80052F24: addiu       $t6, $sp, 0x890
    ctx->r14 = ADD32(ctx->r29, 0X890);
    // 0x80052F28: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80052F2C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80052F30: sh          $t1, 0x886($sp)
    MEM_H(0X886, ctx->r29) = ctx->r9;
    // 0x80052F34: addiu       $s1, $sp, 0x8BA
    ctx->r17 = ADD32(ctx->r29, 0X8BA);
    // 0x80052F38: addiu       $s0, $sp, 0x892
    ctx->r16 = ADD32(ctx->r29, 0X892);
    // 0x80052F3C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80052F40: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_80052F44:
    // 0x80052F44: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80052F48: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80052F4C: lwc1        $f6, 0x0($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80052F50: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80052F54: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80052F58: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80052F5C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80052F60: nop

    // 0x80052F64: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80052F68: jal         0x8006A99C
    // 0x80052F6C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_4;
    // 0x80052F6C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_4:
    // 0x80052F70: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80052F74: lwc1        $f16, 0x0($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80052F78: lwc1        $f10, 0x4($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X4);
    // 0x80052F7C: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80052F80: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80052F84: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80052F88: nop

    // 0x80052F8C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80052F90: jal         0x8006A99C
    // 0x80052F94: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_5;
    // 0x80052F94: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_5:
    // 0x80052F98: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80052F9C: lh          $t2, 0x884($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X884);
    // 0x80052FA0: lh          $v1, 0x0($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X0);
    // 0x80052FA4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80052FA8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80052FAC: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80052FB0: beql        $at, $zero, L_80052FC0
    if (ctx->r1 == 0) {
        // 0x80052FB4: lh          $t1, 0x886($sp)
        ctx->r9 = MEM_H(ctx->r29, 0X886);
            goto L_80052FC0;
    }
    goto skip_3;
    // 0x80052FB4: lh          $t1, 0x886($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X886);
    skip_3:
    // 0x80052FB8: sh          $v1, 0x884($sp)
    MEM_H(0X884, ctx->r29) = ctx->r3;
    // 0x80052FBC: lh          $t1, 0x886($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X886);
L_80052FC0:
    // 0x80052FC0: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80052FC4: lh          $t3, 0x888($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X888);
    // 0x80052FC8: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80052FCC: beql        $at, $zero, L_80052FE0
    if (ctx->r1 == 0) {
        // 0x80052FD0: slt         $at, $v1, $t3
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_80052FE0;
    }
    goto skip_4;
    // 0x80052FD0: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    skip_4:
    // 0x80052FD4: sll         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2 << 16);
    // 0x80052FD8: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80052FDC: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
L_80052FE0:
    // 0x80052FE0: beql        $at, $zero, L_80052FF0
    if (ctx->r1 == 0) {
        // 0x80052FE4: lh          $t4, 0x88A($sp)
        ctx->r12 = MEM_H(ctx->r29, 0X88A);
            goto L_80052FF0;
    }
    goto skip_5;
    // 0x80052FE4: lh          $t4, 0x88A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X88A);
    skip_5:
    // 0x80052FE8: sh          $v1, 0x888($sp)
    MEM_H(0X888, ctx->r29) = ctx->r3;
    // 0x80052FEC: lh          $t4, 0x88A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X88A);
L_80052FF0:
    // 0x80052FF0: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80052FF4: beql        $at, $zero, L_80053004
    if (ctx->r1 == 0) {
        // 0x80052FF8: lw          $t5, 0x44($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X44);
            goto L_80053004;
    }
    goto skip_6;
    // 0x80052FF8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    skip_6:
    // 0x80052FFC: sh          $v0, 0x88A($sp)
    MEM_H(0X88A, ctx->r29) = ctx->r2;
    // 0x80053000: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
L_80053004:
    // 0x80053004: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80053008: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8005300C: bne         $s0, $t5, L_80052F44
    if (ctx->r16 != ctx->r13) {
        // 0x80053010: sh          $t1, 0x886($sp)
        MEM_H(0X886, ctx->r29) = ctx->r9;
            goto L_80052F44;
    }
    // 0x80053010: sh          $t1, 0x886($sp)
    MEM_H(0X886, ctx->r29) = ctx->r9;
L_80053014:
    // 0x80053014: lh          $a2, 0x88A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X88A);
    // 0x80053018: lh          $t6, 0x884($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X884);
    // 0x8005301C: lh          $a1, 0x888($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X888);
    // 0x80053020: subu        $t1, $t1, $a2
    ctx->r9 = SUB32(ctx->r9, ctx->r6);
    // 0x80053024: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80053028: subu        $t8, $t6, $a1
    ctx->r24 = SUB32(ctx->r14, ctx->r5);
    // 0x8005302C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80053030: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x80053034: addiu       $s5, $sp, 0x84
    ctx->r21 = ADD32(ctx->r29, 0X84);
    // 0x80053038: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8005303C: sll         $a3, $t9, 16
    ctx->r7 = S32(ctx->r25 << 16);
    // 0x80053040: sh          $t9, 0x884($sp)
    MEM_H(0X884, ctx->r29) = ctx->r25;
    // 0x80053044: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80053048: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8005304C: sh          $t1, 0x886($sp)
    MEM_H(0X886, ctx->r29) = ctx->r9;
    // 0x80053050: jal         0x8006AFA0
    // 0x80053054: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8006AFA0(rdram, ctx);
        goto after_6;
    // 0x80053054: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x80053058: bne         $v0, $zero, L_80053068
    if (ctx->r2 != 0) {
        // 0x8005305C: lw          $v1, 0x8F8($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X8F8);
            goto L_80053068;
    }
    // 0x8005305C: lw          $v1, 0x8F8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8F8);
    // 0x80053060: b           L_80053498
    // 0x80053064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80053498;
    // 0x80053064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80053068:
    // 0x80053068: lbu         $v0, 0x18($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X18);
    // 0x8005306C: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80053070: beq         $v0, $at, L_80053080
    if (ctx->r2 == ctx->r1) {
        // 0x80053074: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_80053080;
    }
    // 0x80053074: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80053078: bne         $v0, $at, L_80053218
    if (ctx->r2 != ctx->r1) {
        // 0x8005307C: nop
    
            goto L_80053218;
    }
    // 0x8005307C: nop

L_80053080:
    // 0x80053080: lw          $t3, 0x174($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X174);
    // 0x80053084: addiu       $s1, $sp, 0x8B8
    ctx->r17 = ADD32(ctx->r29, 0X8B8);
    // 0x80053088: addiu       $s0, $sp, 0x890
    ctx->r16 = ADD32(ctx->r29, 0X890);
    // 0x8005308C: lbu         $t4, 0x10($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X10);
    // 0x80053090: sll         $t6, $s6, 1
    ctx->r14 = S32(ctx->r22 << 1);
    // 0x80053094: beq         $s6, $zero, L_80053494
    if (ctx->r22 == 0) {
        // 0x80053098: sb          $t4, 0x73($sp)
        MEM_B(0X73, ctx->r29) = ctx->r12;
            goto L_80053494;
    }
    // 0x80053098: sb          $t4, 0x73($sp)
    MEM_B(0X73, ctx->r29) = ctx->r12;
    // 0x8005309C: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x800530A0: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x800530A4: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800530A8: addiu       $s3, $sp, 0x7A
    ctx->r19 = ADD32(ctx->r29, 0X7A);
    // 0x800530AC: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // 0x800530B0: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
L_800530B4:
    // 0x800530B4: lh          $t2, 0x88A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X88A);
    // 0x800530B8: lh          $t3, 0x884($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X884);
    // 0x800530BC: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x800530C0: subu        $t9, $t7, $t2
    ctx->r25 = SUB32(ctx->r15, ctx->r10);
    // 0x800530C4: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800530C8: lh          $t9, 0x888($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X888);
    // 0x800530CC: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800530D0: lbu         $t8, 0x73($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X73);
    // 0x800530D4: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x800530D8: mflo        $t4
    ctx->r12 = lo;
    // 0x800530DC: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800530E0: addu        $t5, $s5, $t6
    ctx->r13 = ADD32(ctx->r21, ctx->r14);
    // 0x800530E4: addu        $t2, $t5, $t7
    ctx->r10 = ADD32(ctx->r13, ctx->r15);
    // 0x800530E8: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x800530EC: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x800530F0: lhu         $a2, 0x0($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X0);
    // 0x800530F4: beq         $t8, $zero, L_80053124
    if (ctx->r24 == 0) {
        // 0x800530F8: sh          $a2, 0x7A($sp)
        MEM_H(0X7A, ctx->r29) = ctx->r6;
            goto L_80053124;
    }
    // 0x800530F8: sh          $a2, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r6;
    // 0x800530FC: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x80053100: addiu       $t3, $t8, -0x1
    ctx->r11 = ADD32(ctx->r24, -0X1);
    // 0x80053104: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80053108: andi        $t7, $t5, 0xF8
    ctx->r15 = ctx->r13 & 0XF8;
    // 0x8005310C: xor         $t9, $v1, $t7
    ctx->r25 = ctx->r3 ^ ctx->r15;
    // 0x80053110: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80053114: beql        $t9, $t3, L_80053128
    if (ctx->r25 == ctx->r11) {
        // 0x80053118: lbu         $v0, 0x1($s3)
        ctx->r2 = MEM_BU(ctx->r19, 0X1);
            goto L_80053128;
    }
    goto skip_7;
    // 0x80053118: lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1);
    skip_7:
    // 0x8005311C: b           L_800531D8
    // 0x80053120: sh          $a2, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r6;
        goto L_800531D8;
    // 0x80053120: sh          $a2, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r6;
L_80053124:
    // 0x80053124: lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X1);
L_80053128:
    // 0x80053128: lui         $at, 0x406F
    ctx->r1 = S32(0X406F << 16);
    // 0x8005312C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80053130: srl         $t4, $v0, 6
    ctx->r12 = S32(U32(ctx->r2) >> 6);
    // 0x80053134: bne         $s4, $t4, L_800531D8
    if (ctx->r20 != ctx->r12) {
        // 0x80053138: andi        $a0, $v0, 0x3F
        ctx->r4 = ctx->r2 & 0X3F;
            goto L_800531D8;
    }
    // 0x80053138: andi        $a0, $v0, 0x3F
    ctx->r4 = ctx->r2 & 0X3F;
    // 0x8005313C: jal         0x80046DEC
    // 0x80053140: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_80046DEC(rdram, ctx);
        goto after_7;
    // 0x80053140: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_7:
    // 0x80053144: beq         $v0, $zero, L_800531D0
    if (ctx->r2 == 0) {
        // 0x80053148: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800531D0;
    }
    // 0x80053148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005314C: jal         0x8006F324
    // 0x80053150: nop

    func_8006F324(rdram, ctx);
        goto after_8;
    // 0x80053150: nop

    after_8:
    // 0x80053154: lhu         $a2, 0x7A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X7A);
    // 0x80053158: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x8005315C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80053160: andi        $a2, $a2, 0xF800
    ctx->r6 = ctx->r6 & 0XF800;
    // 0x80053164: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80053168: jal         0x8006B1C8
    // 0x8005316C: sh          $a2, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r6;
    func_8006B1C8(rdram, ctx);
        goto after_9;
    // 0x8005316C: sh          $a2, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r6;
    after_9:
    // 0x80053170: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x80053174: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x80053178: lh          $t4, 0x88A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X88A);
    // 0x8005317C: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x80053180: addu        $t7, $s5, $t5
    ctx->r15 = ADD32(ctx->r21, ctx->r13);
    // 0x80053184: lh          $t5, 0x884($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X884);
    // 0x80053188: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x8005318C: lh          $t8, 0x888($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X888);
    // 0x80053190: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053194: lhu         $a2, 0x7A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X7A);
    // 0x80053198: negu        $at, $t8
    ctx->r1 = SUB32(0, ctx->r24);
    // 0x8005319C: sll         $t9, $at, 1
    ctx->r25 = S32(ctx->r1 << 1);
    // 0x800531A0: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x800531A4: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x800531A8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800531AC: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // 0x800531B0: mflo        $t8
    ctx->r24 = lo;
    // 0x800531B4: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800531B8: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x800531BC: sh          $a2, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r6;
    // 0x800531C0: lw          $t2, -0x76A4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X76A4);
    // 0x800531C4: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x800531C8: b           L_800531D8
    // 0x800531CC: sw          $t4, -0x76A4($at)
    MEM_W(-0X76A4, ctx->r1) = ctx->r12;
        goto L_800531D8;
    // 0x800531CC: sw          $t4, -0x76A4($at)
    MEM_W(-0X76A4, ctx->r1) = ctx->r12;
L_800531D0:
    // 0x800531D0: sh          $zero, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = 0;
    // 0x800531D4: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
L_800531D8:
    // 0x800531D8: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x800531DC: lhu         $a2, 0x7A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X7A);
    // 0x800531E0: andi        $t6, $t5, 0xF8
    ctx->r14 = ctx->r13 & 0XF8;
    // 0x800531E4: bne         $v1, $t6, L_800531F0
    if (ctx->r3 != ctx->r14) {
        // 0x800531E8: andi        $a2, $a2, 0x7FF
        ctx->r6 = ctx->r6 & 0X7FF;
            goto L_800531F0;
    }
    // 0x800531E8: andi        $a2, $a2, 0x7FF
    ctx->r6 = ctx->r6 & 0X7FF;
    // 0x800531EC: sh          $a2, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r6;
L_800531F0:
    // 0x800531F0: lhu         $t8, 0x7A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X7A);
    // 0x800531F4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800531F8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800531FC: sh          $t8, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r24;
    // 0x80053200: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80053204: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x80053208: bnel        $s0, $t3, L_800530B4
    if (ctx->r16 != ctx->r11) {
        // 0x8005320C: lh          $t7, 0x0($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X0);
            goto L_800530B4;
    }
    goto skip_8;
    // 0x8005320C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    skip_8:
    // 0x80053210: b           L_80053498
    // 0x80053214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80053498;
    // 0x80053214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80053218:
    // 0x80053218: beq         $s6, $zero, L_80053494
    if (ctx->r22 == 0) {
        // 0x8005321C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80053494;
    }
    // 0x8005321C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80053220: andi        $v0, $s6, 0x3
    ctx->r2 = ctx->r22 & 0X3;
    // 0x80053224: beq         $v0, $zero, L_800532C4
    if (ctx->r2 == 0) {
        // 0x80053228: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800532C4;
    }
    // 0x80053228: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005322C: sll         $a0, $zero, 1
    ctx->r4 = S32(0 << 1);
    // 0x80053230: addiu       $t7, $sp, 0x8B8
    ctx->r15 = ADD32(ctx->r29, 0X8B8);
    // 0x80053234: addiu       $t9, $sp, 0x890
    ctx->r25 = ADD32(ctx->r29, 0X890);
    // 0x80053238: addu        $s0, $a0, $t9
    ctx->r16 = ADD32(ctx->r4, ctx->r25);
    // 0x8005323C: addu        $s1, $a0, $t7
    ctx->r17 = ADD32(ctx->r4, ctx->r15);
    // 0x80053240: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x80053244: addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
L_80053248:
    // 0x80053248: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x8005324C: lh          $t4, 0x88A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X88A);
    // 0x80053250: lh          $t6, 0x884($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X884);
    // 0x80053254: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x80053258: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x8005325C: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053260: lh          $t5, 0x888($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X888);
    // 0x80053264: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80053268: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005326C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80053270: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80053274: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80053278: mflo        $t8
    ctx->r24 = lo;
    // 0x8005327C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x80053280: addu        $t7, $s5, $t3
    ctx->r15 = ADD32(ctx->r21, ctx->r11);
    // 0x80053284: addu        $t4, $t7, $t2
    ctx->r12 = ADD32(ctx->r15, ctx->r10);
    // 0x80053288: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x8005328C: addu        $t3, $t4, $t8
    ctx->r11 = ADD32(ctx->r12, ctx->r24);
    // 0x80053290: lhu         $t9, 0x0($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X0);
    // 0x80053294: sh          $t9, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r25;
    // 0x80053298: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8005329C: andi        $t5, $t9, 0xF800
    ctx->r13 = ctx->r25 & 0XF800;
    // 0x800532A0: srl         $t2, $t7, 6
    ctx->r10 = S32(U32(ctx->r15) >> 6);
    // 0x800532A4: bnel        $s4, $t2, L_800532B4
    if (ctx->r20 != ctx->r10) {
        // 0x800532A8: lhu         $t6, 0x70($sp)
        ctx->r14 = MEM_HU(ctx->r29, 0X70);
            goto L_800532B4;
    }
    goto skip_9;
    // 0x800532A8: lhu         $t6, 0x70($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X70);
    skip_9:
    // 0x800532AC: sh          $t5, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r13;
    // 0x800532B0: lhu         $t6, 0x70($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X70);
L_800532B4:
    // 0x800532B4: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x800532B8: bne         $v1, $t0, L_80053248
    if (ctx->r3 != ctx->r8) {
        // 0x800532BC: sh          $t6, -0x18($s2)
        MEM_H(-0X18, ctx->r18) = ctx->r14;
            goto L_80053248;
    }
    // 0x800532BC: sh          $t6, -0x18($s2)
    MEM_H(-0X18, ctx->r18) = ctx->r14;
    // 0x800532C0: beq         $t0, $s6, L_80053494
    if (ctx->r8 == ctx->r22) {
        // 0x800532C4: sll         $a0, $t0, 1
        ctx->r4 = S32(ctx->r8 << 1);
            goto L_80053494;
    }
L_800532C4:
    // 0x800532C4: sll         $a0, $t0, 1
    ctx->r4 = S32(ctx->r8 << 1);
    // 0x800532C8: addiu       $t8, $sp, 0x890
    ctx->r24 = ADD32(ctx->r29, 0X890);
    // 0x800532CC: addiu       $t4, $sp, 0x8B8
    ctx->r12 = ADD32(ctx->r29, 0X8B8);
    // 0x800532D0: sll         $t3, $s6, 1
    ctx->r11 = S32(ctx->r22 << 1);
    // 0x800532D4: addu        $v1, $t3, $t8
    ctx->r3 = ADD32(ctx->r11, ctx->r24);
    // 0x800532D8: addu        $s1, $a0, $t4
    ctx->r17 = ADD32(ctx->r4, ctx->r12);
    // 0x800532DC: addu        $s0, $a0, $t8
    ctx->r16 = ADD32(ctx->r4, ctx->r24);
    // 0x800532E0: addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // 0x800532E4: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_800532E8:
    // 0x800532E8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800532EC: lh          $t2, 0x88A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X88A);
    // 0x800532F0: lh          $t5, 0x884($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X884);
    // 0x800532F4: lh          $t8, 0x0($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X0);
    // 0x800532F8: subu        $t9, $t7, $t2
    ctx->r25 = SUB32(ctx->r15, ctx->r10);
    // 0x800532FC: multu       $t9, $t5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053300: lh          $t9, 0x888($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X888);
    // 0x80053304: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x80053308: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8005330C: mflo        $t6
    ctx->r14 = lo;
    // 0x80053310: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x80053314: addu        $t3, $s5, $t4
    ctx->r11 = ADD32(ctx->r21, ctx->r12);
    // 0x80053318: addu        $t2, $t3, $t7
    ctx->r10 = ADD32(ctx->r11, ctx->r15);
    // 0x8005331C: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x80053320: addu        $t4, $t2, $t6
    ctx->r12 = ADD32(ctx->r10, ctx->r14);
    // 0x80053324: lhu         $t8, 0x0($t4)
    ctx->r24 = MEM_HU(ctx->r12, 0X0);
    // 0x80053328: sh          $t8, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r24;
    // 0x8005332C: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x80053330: andi        $t9, $t8, 0xF800
    ctx->r25 = ctx->r24 & 0XF800;
    // 0x80053334: srl         $t7, $t3, 6
    ctx->r15 = S32(U32(ctx->r11) >> 6);
    // 0x80053338: bnel        $s4, $t7, L_80053348
    if (ctx->r20 != ctx->r15) {
        // 0x8005333C: lhu         $t5, 0x70($sp)
        ctx->r13 = MEM_HU(ctx->r29, 0X70);
            goto L_80053348;
    }
    goto skip_10;
    // 0x8005333C: lhu         $t5, 0x70($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X70);
    skip_10:
    // 0x80053340: sh          $t9, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r25;
    // 0x80053344: lhu         $t5, 0x70($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X70);
L_80053348:
    // 0x80053348: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x8005334C: sh          $t5, -0x18($s2)
    MEM_H(-0X18, ctx->r18) = ctx->r13;
    // 0x80053350: lh          $t6, 0x88A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X88A);
    // 0x80053354: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x80053358: lh          $t3, 0x884($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X884);
    // 0x8005335C: lh          $t5, 0x2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2);
    // 0x80053360: subu        $t4, $t2, $t6
    ctx->r12 = SUB32(ctx->r10, ctx->r14);
    // 0x80053364: multu       $t4, $t3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053368: lh          $t4, 0x888($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X888);
    // 0x8005336C: sll         $t2, $t5, 1
    ctx->r10 = S32(ctx->r13 << 1);
    // 0x80053370: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x80053374: mflo        $t7
    ctx->r15 = lo;
    // 0x80053378: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8005337C: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x80053380: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x80053384: negu        $t7, $t3
    ctx->r15 = SUB32(0, ctx->r11);
    // 0x80053388: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8005338C: lhu         $t5, 0x0($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X0);
    // 0x80053390: sh          $t5, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r13;
    // 0x80053394: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x80053398: andi        $t4, $t5, 0xF800
    ctx->r12 = ctx->r13 & 0XF800;
    // 0x8005339C: srl         $t2, $t9, 6
    ctx->r10 = S32(U32(ctx->r25) >> 6);
    // 0x800533A0: bnel        $s4, $t2, L_800533B0
    if (ctx->r20 != ctx->r10) {
        // 0x800533A4: lhu         $t3, 0x70($sp)
        ctx->r11 = MEM_HU(ctx->r29, 0X70);
            goto L_800533B0;
    }
    goto skip_11;
    // 0x800533A4: lhu         $t3, 0x70($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X70);
    skip_11:
    // 0x800533A8: sh          $t4, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r12;
    // 0x800533AC: lhu         $t3, 0x70($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X70);
L_800533B0:
    // 0x800533B0: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x800533B4: sh          $t3, -0x18($s2)
    MEM_H(-0X18, ctx->r18) = ctx->r11;
    // 0x800533B8: lh          $t7, 0x88A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X88A);
    // 0x800533BC: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800533C0: lh          $t9, 0x884($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X884);
    // 0x800533C4: lh          $t3, 0x4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X4);
    // 0x800533C8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800533CC: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800533D0: lh          $t8, 0x888($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X888);
    // 0x800533D4: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800533D8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800533DC: mflo        $t2
    ctx->r10 = lo;
    // 0x800533E0: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800533E4: addu        $t4, $s5, $t5
    ctx->r12 = ADD32(ctx->r21, ctx->r13);
    // 0x800533E8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800533EC: negu        $t2, $t9
    ctx->r10 = SUB32(0, ctx->r25);
    // 0x800533F0: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x800533F4: lhu         $t3, 0x0($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X0);
    // 0x800533F8: sh          $t3, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r11;
    // 0x800533FC: lbu         $t4, 0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1);
    // 0x80053400: andi        $t8, $t3, 0xF800
    ctx->r24 = ctx->r11 & 0XF800;
    // 0x80053404: srl         $t6, $t4, 6
    ctx->r14 = S32(U32(ctx->r12) >> 6);
    // 0x80053408: bnel        $s4, $t6, L_80053418
    if (ctx->r20 != ctx->r14) {
        // 0x8005340C: lhu         $t9, 0x70($sp)
        ctx->r25 = MEM_HU(ctx->r29, 0X70);
            goto L_80053418;
    }
    goto skip_12;
    // 0x8005340C: lhu         $t9, 0x70($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X70);
    skip_12:
    // 0x80053410: sh          $t8, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r24;
    // 0x80053414: lhu         $t9, 0x70($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X70);
L_80053418:
    // 0x80053418: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x8005341C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80053420: sh          $t9, -0x18($s2)
    MEM_H(-0X18, ctx->r18) = ctx->r25;
    // 0x80053424: lh          $t2, 0x88A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X88A);
    // 0x80053428: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8005342C: lh          $t4, 0x884($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X884);
    // 0x80053430: lh          $t9, -0x2($s1)
    ctx->r25 = MEM_H(ctx->r17, -0X2);
    // 0x80053434: subu        $t5, $t7, $t2
    ctx->r13 = SUB32(ctx->r15, ctx->r10);
    // 0x80053438: multu       $t5, $t4
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005343C: lh          $t5, 0x888($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X888);
    // 0x80053440: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80053444: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80053448: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x8005344C: mflo        $t6
    ctx->r14 = lo;
    // 0x80053450: sll         $t3, $t6, 1
    ctx->r11 = S32(ctx->r14 << 1);
    // 0x80053454: addu        $t8, $s5, $t3
    ctx->r24 = ADD32(ctx->r21, ctx->r11);
    // 0x80053458: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x8005345C: negu        $t6, $t4
    ctx->r14 = SUB32(0, ctx->r12);
    // 0x80053460: addu        $t3, $t2, $t6
    ctx->r11 = ADD32(ctx->r10, ctx->r14);
    // 0x80053464: lhu         $t9, 0x0($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X0);
    // 0x80053468: sh          $t9, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r25;
    // 0x8005346C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80053470: andi        $t5, $t9, 0xF800
    ctx->r13 = ctx->r25 & 0XF800;
    // 0x80053474: srl         $t7, $t8, 6
    ctx->r15 = S32(U32(ctx->r24) >> 6);
    // 0x80053478: bnel        $s4, $t7, L_80053488
    if (ctx->r20 != ctx->r15) {
        // 0x8005347C: lhu         $t4, 0x70($sp)
        ctx->r12 = MEM_HU(ctx->r29, 0X70);
            goto L_80053488;
    }
    goto skip_13;
    // 0x8005347C: lhu         $t4, 0x70($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X70);
    skip_13:
    // 0x80053480: sh          $t5, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r13;
    // 0x80053484: lhu         $t4, 0x70($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X70);
L_80053488:
    // 0x80053488: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x8005348C: bne         $s0, $v1, L_800532E8
    if (ctx->r16 != ctx->r3) {
        // 0x80053490: sh          $t4, -0x18($s2)
        MEM_H(-0X18, ctx->r18) = ctx->r12;
            goto L_800532E8;
    }
    // 0x80053490: sh          $t4, -0x18($s2)
    MEM_H(-0X18, ctx->r18) = ctx->r12;
L_80053494:
    // 0x80053494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80053498:
    // 0x80053498: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005349C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800534A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800534A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800534A8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800534AC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800534B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800534B4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800534B8: jr          $ra
    // 0x800534BC: addiu       $sp, $sp, 0x8E8
    ctx->r29 = ADD32(ctx->r29, 0X8E8);
    return;
    // 0x800534BC: addiu       $sp, $sp, 0x8E8
    ctx->r29 = ADD32(ctx->r29, 0X8E8);
;}
RECOMP_FUNC void func_804BBB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BBB14: lw          $v1, 0x35C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X35C);
    // 0x804BBB18: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x804BBB1C: beq         $t6, $zero, L_804BBB30
    if (ctx->r14 == 0) {
        // 0x804BBB20: nop
    
            goto L_804BBB30;
    }
    // 0x804BBB20: nop

    // 0x804BBB24: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x804BBB28: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x804BBB2C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_804BBB30:
    // 0x804BBB30: jr          $ra
    // 0x804BBB34: nop

    return;
    // 0x804BBB34: nop

;}
RECOMP_FUNC void func_804201E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804201E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804201E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804201E8: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x804201EC: addiu       $a2, $a0, 0x188
    ctx->r6 = ADD32(ctx->r4, 0X188);
    // 0x804201F0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x804201F4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x804201F8: jal         0x8041FF80
    // 0x804201FC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_8041FF80(rdram, ctx);
        goto after_0;
    // 0x804201FC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_0:
    // 0x80420200: jal         0x804200B0
    // 0x80420204: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_804200B0(rdram, ctx);
        goto after_1;
    // 0x80420204: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80420208: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8042020C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80420210: jal         0x80048F84
    // 0x80420214: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x80420214: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    after_2:
    // 0x80420218: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8042021C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80420220: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80420224: lw          $t6, 0x10($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X10);
    // 0x80420228: sw          $t6, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r14;
    // 0x8042022C: lw          $t7, 0x180($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X180);
    // 0x80420230: beql        $t7, $zero, L_80420244
    if (ctx->r15 == 0) {
        // 0x80420234: lw          $v0, 0x1E4($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X1E4);
            goto L_80420244;
    }
    goto skip_0;
    // 0x80420234: lw          $v0, 0x1E4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1E4);
    skip_0:
    // 0x80420238: b           L_804204E0
    // 0x8042023C: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
        goto L_804204E0;
    // 0x8042023C: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    // 0x80420240: lw          $v0, 0x1E4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1E4);
L_80420244:
    // 0x80420244: beq         $v0, $zero, L_804202D8
    if (ctx->r2 == 0) {
        // 0x80420248: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_804202D8;
    }
    // 0x80420248: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8042024C: slti        $at, $t8, 0xB4
    ctx->r1 = SIGNED(ctx->r24) < 0XB4 ? 1 : 0;
    // 0x80420250: beq         $at, $zero, L_804202E8
    if (ctx->r1 == 0) {
        // 0x80420254: sw          $t8, 0x1E4($a3)
        MEM_W(0X1E4, ctx->r7) = ctx->r24;
            goto L_804202E8;
    }
    // 0x80420254: sw          $t8, 0x1E4($a3)
    MEM_W(0X1E4, ctx->r7) = ctx->r24;
    // 0x80420258: lw          $v1, 0x16C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X16C);
    // 0x8042025C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80420260: lbu         $t1, 0x10($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X10);
    // 0x80420264: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x80420268: bnel        $t1, $zero, L_8042027C
    if (ctx->r9 != 0) {
        // 0x8042026C: lw          $v0, 0x1E0($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X1E0);
            goto L_8042027C;
    }
    goto skip_1;
    // 0x8042026C: lw          $v0, 0x1E0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1E0);
    skip_1:
    // 0x80420270: b           L_804202E8
    // 0x80420274: sb          $t2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r10;
        goto L_804202E8;
    // 0x80420274: sb          $t2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r10;
    // 0x80420278: lw          $v0, 0x1E0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1E0);
L_8042027C:
    // 0x8042027C: beq         $v0, $zero, L_8042028C
    if (ctx->r2 == 0) {
        // 0x80420280: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8042028C;
    }
    // 0x80420280: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80420284: b           L_804202E8
    // 0x80420288: sw          $t3, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r11;
        goto L_804202E8;
    // 0x80420288: sw          $t3, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r11;
L_8042028C:
    // 0x8042028C: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x80420290: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80420294: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80420298: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8042029C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x804202A0: jal         0x80067BBC
    // 0x804202A4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x804202A4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_3:
    // 0x804202A8: addiu       $a0, $zero, 0xA9
    ctx->r4 = ADD32(0, 0XA9);
    // 0x804202AC: jal         0x80067818
    // 0x804202B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x804202B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x804202B4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x804202B8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x804202BC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x804202C0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804202C4: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x804202C8: lw          $t4, 0x1E4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X1E4);
    // 0x804202CC: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x804202D0: b           L_804202E8
    // 0x804202D4: sw          $t5, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r13;
        goto L_804202E8;
    // 0x804202D4: sw          $t5, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r13;
L_804202D8:
    // 0x804202D8: jal         0x80420118
    // 0x804202DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80420118(rdram, ctx);
        goto after_5;
    // 0x804202DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
    // 0x804202E0: b           L_80420514
    // 0x804202E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80420514;
    // 0x804202E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804202E8:
    // 0x804202E8: lh          $v1, 0x184($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X184);
    // 0x804202EC: addiu       $a1, $a3, 0x13C
    ctx->r5 = ADD32(ctx->r7, 0X13C);
    // 0x804202F0: beql        $v1, $zero, L_8042047C
    if (ctx->r3 == 0) {
        // 0x804202F4: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8042047C;
    }
    goto skip_2;
    // 0x804202F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_2:
    // 0x804202F8: beq         $v1, $zero, L_80420328
    if (ctx->r3 == 0) {
        // 0x804202FC: addiu       $a0, $zero, 0x4001
        ctx->r4 = ADD32(0, 0X4001);
            goto L_80420328;
    }
    // 0x804202FC: addiu       $a0, $zero, 0x4001
    ctx->r4 = ADD32(0, 0X4001);
L_80420300:
    // 0x80420300: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80420304: beq         $v0, $zero, L_80420320
    if (ctx->r2 == 0) {
        // 0x80420308: nop
    
            goto L_80420320;
    }
    // 0x80420308: nop

    // 0x8042030C: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x80420310: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80420314: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80420318: beq         $a0, $t6, L_80420328
    if (ctx->r4 == ctx->r14) {
        // 0x8042031C: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_80420328;
    }
    // 0x8042031C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80420320:
    // 0x80420320: bne         $v1, $zero, L_80420300
    if (ctx->r3 != 0) {
        // 0x80420324: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80420300;
    }
    // 0x80420324: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80420328:
    // 0x80420328: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x8042032C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80420330: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80420334: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80420338: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8042033C: jal         0x80059700
    // 0x80420340: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_80059700(rdram, ctx);
        goto after_6;
    // 0x80420340: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_6:
    // 0x80420344: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80420348: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8042034C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80420350: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80420354: bne         $v0, $zero, L_80420394
    if (ctx->r2 != 0) {
        // 0x80420358: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_80420394;
    }
    // 0x80420358: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8042035C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80420360: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x80420364: jal         0x80059848
    // 0x80420368: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_80059848(rdram, ctx);
        goto after_7;
    // 0x80420368: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_7:
    // 0x8042036C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80420370: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80420374: bne         $v0, $zero, L_80420394
    if (ctx->r2 != 0) {
        // 0x80420378: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_80420394;
    }
    // 0x80420378: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8042037C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80420380: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80420384: lw          $t8, 0x174($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X174);
    // 0x80420388: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8042038C: beql        $t9, $zero, L_804203A8
    if (ctx->r25 == 0) {
        // 0x80420390: sw          $t1, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r9;
            goto L_804203A8;
    }
    goto skip_3;
    // 0x80420390: sw          $t1, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r9;
    skip_3:
L_80420394:
    // 0x80420394: jal         0x80420118
    // 0x80420398: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80420118(rdram, ctx);
        goto after_8;
    // 0x80420398: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_8:
    // 0x8042039C: b           L_80420514
    // 0x804203A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80420514;
    // 0x804203A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804203A4: sw          $t1, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r9;
L_804203A8:
    // 0x804203A8: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x804203AC: lw          $t3, 0x138($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X138);
    // 0x804203B0: sw          $t3, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->r11;
    // 0x804203B4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x804203B8: bnel        $v0, $zero, L_804203F4
    if (ctx->r2 != 0) {
        // 0x804203BC: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_804203F4;
    }
    goto skip_4;
    // 0x804203BC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_4:
    // 0x804203C0: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x804203C4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x804203C8: lwc1        $f4, 0x3C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X3C);
    // 0x804203CC: swc1        $f4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f4.u32l;
    // 0x804203D0: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x804203D4: lwc1        $f6, 0x40($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X40);
    // 0x804203D8: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x804203DC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x804203E0: lwc1        $f8, 0x44($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X44);
    // 0x804203E4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x804203E8: b           L_804204E0
    // 0x804203EC: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
        goto L_804204E0;
    // 0x804203EC: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x804203F0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_804203F4:
    // 0x804203F4: lwc1        $f0, 0x4($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
    // 0x804203F8: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x804203FC: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80420400: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x80420404: lwc1        $f16, 0x3C($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80420408: sub.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8042040C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80420410: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80420414: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80420418: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8042041C: swc1        $f18, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f18.u32l;
    // 0x80420420: lw          $t8, 0x7EA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7EA8);
    // 0x80420424: lb          $t9, 0x3($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X3);
    // 0x80420428: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x8042042C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80420430: nop

    // 0x80420434: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80420438: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8042043C: nop

    // 0x80420440: bc1fl       L_80420454
    if (!c1cs) {
        // 0x80420444: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80420454;
    }
    goto skip_5;
    // 0x80420444: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_5:
    // 0x80420448: b           L_8042046C
    // 0x8042044C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_8042046C;
    // 0x8042044C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80420450: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80420454:
    // 0x80420454: nop

    // 0x80420458: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8042045C: nop

    // 0x80420460: bc1fl       L_80420470
    if (!c1cs) {
        // 0x80420464: div.s       $f6, $f2, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
            goto L_80420470;
    }
    goto skip_6;
    // 0x80420464: div.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    skip_6:
    // 0x80420468: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8042046C:
    // 0x8042046C: div.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
L_80420470:
    // 0x80420470: b           L_804204E0
    // 0x80420474: swc1        $f6, 0xE0($a3)
    MEM_W(0XE0, ctx->r7) = ctx->f6.u32l;
        goto L_804204E0;
    // 0x80420474: swc1        $f6, 0xE0($a3)
    MEM_W(0XE0, ctx->r7) = ctx->f6.u32l;
    // 0x80420478: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8042047C:
    // 0x8042047C: nop

    // 0x80420480: swc1        $f0, 0xE0($a3)
    MEM_W(0XE0, ctx->r7) = ctx->f0.u32l;
    // 0x80420484: swc1        $f0, 0xDC($a3)
    MEM_W(0XDC, ctx->r7) = ctx->f0.u32l;
    // 0x80420488: swc1        $f0, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f0.u32l;
    // 0x8042048C: swc1        $f0, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f0.u32l;
    // 0x80420490: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80420494: beql        $t2, $zero, L_804204DC
    if (ctx->r10 == 0) {
        // 0x80420498: sw          $zero, 0x0($t0)
        MEM_W(0X0, ctx->r8) = 0;
            goto L_804204DC;
    }
    goto skip_7;
    // 0x80420498: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    skip_7:
    // 0x8042049C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x804204A0: jal         0x8004700C
    // 0x804204A4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_8004700C(rdram, ctx);
        goto after_9;
    // 0x804204A4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_9:
    // 0x804204A8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x804204AC: beq         $v0, $zero, L_804204D8
    if (ctx->r2 == 0) {
        // 0x804204B0: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_804204D8;
    }
    // 0x804204B0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804204B4: lw          $t3, 0x174($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X174);
    // 0x804204B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x804204BC: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x804204C0: beql        $t4, $zero, L_804204DC
    if (ctx->r12 == 0) {
        // 0x804204C4: sw          $zero, 0x0($t0)
        MEM_W(0X0, ctx->r8) = 0;
            goto L_804204DC;
    }
    goto skip_8;
    // 0x804204C4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    skip_8:
    // 0x804204C8: jal         0x80420118
    // 0x804204CC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    func_80420118(rdram, ctx);
        goto after_10;
    // 0x804204CC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    after_10:
    // 0x804204D0: b           L_80420514
    // 0x804204D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80420514;
    // 0x804204D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804204D8:
    // 0x804204D8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_804204DC:
    // 0x804204DC: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
L_804204E0:
    // 0x804204E0: lw          $t5, 0x14($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X14);
    // 0x804204E4: bnel        $t5, $zero, L_80420514
    if (ctx->r13 != 0) {
        // 0x804204E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80420514;
    }
    goto skip_9;
    // 0x804204E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x804204EC: lw          $t6, 0x10($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X10);
    // 0x804204F0: beql        $t6, $zero, L_80420514
    if (ctx->r14 == 0) {
        // 0x804204F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80420514;
    }
    goto skip_10;
    // 0x804204F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x804204F8: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x804204FC: jal         0x80067BBC
    // 0x80420500: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_11;
    // 0x80420500: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_11:
    // 0x80420504: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x80420508: jal         0x80067818
    // 0x8042050C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_12;
    // 0x8042050C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x80420510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80420514:
    // 0x80420514: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80420518: jr          $ra
    // 0x8042051C: nop

    return;
    // 0x8042051C: nop

;}
RECOMP_FUNC void func_807B8AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8AE4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807B8AE8: lw          $v0, 0x7EA8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7EA8);
    // 0x807B8AEC: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
    // 0x807B8AF0: slti        $at, $v1, 0x1F
    ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x807B8AF4: bnel        $at, $zero, L_807B8B08
    if (ctx->r1 != 0) {
        // 0x807B8AF8: slti        $at, $v1, -0x1E
        ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
            goto L_807B8B08;
    }
    goto skip_0;
    // 0x807B8AF8: slti        $at, $v1, -0x1E
    ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
    skip_0:
    // 0x807B8AFC: b           L_807B8B44
    // 0x807B8B00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_807B8B44;
    // 0x807B8B00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x807B8B04: slti        $at, $v1, -0x1E
    ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
L_807B8B08:
    // 0x807B8B08: beql        $at, $zero, L_807B8B1C
    if (ctx->r1 == 0) {
        // 0x807B8B0C: lb          $v1, 0x3($v0)
        ctx->r3 = MEM_B(ctx->r2, 0X3);
            goto L_807B8B1C;
    }
    goto skip_1;
    // 0x807B8B0C: lb          $v1, 0x3($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3);
    skip_1:
    // 0x807B8B10: b           L_807B8B44
    // 0x807B8B14: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_807B8B44;
    // 0x807B8B14: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x807B8B18: lb          $v1, 0x3($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3);
L_807B8B1C:
    // 0x807B8B1C: slti        $at, $v1, 0x1F
    ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x807B8B20: bnel        $at, $zero, L_807B8B34
    if (ctx->r1 != 0) {
        // 0x807B8B24: slti        $at, $v1, -0x1E
        ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
            goto L_807B8B34;
    }
    goto skip_2;
    // 0x807B8B24: slti        $at, $v1, -0x1E
    ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
    skip_2:
    // 0x807B8B28: b           L_807B8B44
    // 0x807B8B2C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_807B8B44;
    // 0x807B8B2C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x807B8B30: slti        $at, $v1, -0x1E
    ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
L_807B8B34:
    // 0x807B8B34: beq         $at, $zero, L_807B8B44
    if (ctx->r1 == 0) {
        // 0x807B8B38: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_807B8B44;
    }
    // 0x807B8B38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x807B8B3C: b           L_807B8B44
    // 0x807B8B40: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
        goto L_807B8B44;
    // 0x807B8B40: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_807B8B44:
    // 0x807B8B44: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B8B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807B8B4C: lw          $t6, 0x48($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X48);
    // 0x807B8B50: beql        $v1, $t6, L_807B8B68
    if (ctx->r3 == ctx->r14) {
        // 0x807B8B54: sw          $v1, 0x48($a1)
        MEM_W(0X48, ctx->r5) = ctx->r3;
            goto L_807B8B68;
    }
    goto skip_3;
    // 0x807B8B54: sw          $v1, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r3;
    skip_3:
    // 0x807B8B58: sw          $v1, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r3;
    // 0x807B8B5C: jr          $ra
    // 0x807B8B60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x807B8B60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x807B8B64: sw          $v1, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r3;
L_807B8B68:
    // 0x807B8B68: jr          $ra
    // 0x807B8B6C: nop

    return;
    // 0x807B8B6C: nop

;}
RECOMP_FUNC void func_804F34EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F34EC: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x804F34F0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x804F34F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804F34F8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x804F34FC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x804F3500: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x804F3504: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x804F3508: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x804F350C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x804F3510: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x804F3514: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x804F3518: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
L_804F351C:
    // 0x804F351C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x804F3520: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x804F3524: sh          $a0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r4;
    // 0x804F3528: sh          $a0, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r4;
    // 0x804F352C: sh          $a0, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r4;
    // 0x804F3530: bne         $at, $zero, L_804F351C
    if (ctx->r1 != 0) {
        // 0x804F3534: sh          $a0, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r4;
            goto L_804F351C;
    }
    // 0x804F3534: sh          $a0, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r4;
    // 0x804F3538: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x804F353C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804F3540: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x804F3544: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x804F3548: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804F354C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804F3550: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804F3554: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x804F3558: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x804F355C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804F3560: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804F3564: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x804F3568: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x804F356C: nop

    // 0x804F3570: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x804F3574: jal         0x8006A99C
    // 0x804F3578: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x804F3578: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x804F357C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804F3580: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x804F3584: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804F3588: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804F358C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x804F3590: nop

    // 0x804F3594: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x804F3598: jal         0x8006A99C
    // 0x804F359C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x804F359C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x804F35A0: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x804F35A4: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x804F35A8: sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17 << 16);
    // 0x804F35AC: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x804F35B0: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x804F35B4: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x804F35B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x804F35BC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x804F35C0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x804F35C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x804F35C8: jal         0x8006AFA0
    // 0x804F35CC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_8006AFA0(rdram, ctx);
        goto after_2;
    // 0x804F35CC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_2:
    // 0x804F35D0: lui         $s0, 0x804F
    ctx->r16 = S32(RELOC_HI16(270, 0XD48) << 16);
    // 0x804F35D4: lui         $s5, 0x804F
    ctx->r21 = S32(RELOC_HI16(270, 0XD80) << 16);
    // 0x804F35D8: addiu       $s5, $s5, 0x40B0
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(270, 0XD80));
    // 0x804F35DC: addiu       $s0, $s0, 0x4078
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(270, 0XD48));
    // 0x804F35E0: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // 0x804F35E4: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
L_804F35E8:
    // 0x804F35E8: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x804F35EC: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x804F35F0: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x804F35F4: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x804F35F8: andi        $a3, $v0, 0xF000
    ctx->r7 = ctx->r2 & 0XF000;
    // 0x804F35FC: sra         $a3, $a3, 12
    ctx->r7 = S32(SIGNED(ctx->r7) >> 12);
    // 0x804F3600: beq         $s4, $a0, L_804F3650
    if (ctx->r20 == ctx->r4) {
        // 0x804F3604: andi        $v1, $a0, 0xF800
        ctx->r3 = ctx->r4 & 0XF800;
            goto L_804F3650;
    }
    // 0x804F3604: andi        $v1, $a0, 0xF800
    ctx->r3 = ctx->r4 & 0XF800;
    // 0x804F3608: bne         $v1, $zero, L_804F3614
    if (ctx->r3 != 0) {
        // 0x804F360C: sll         $a3, $a3, 16
        ctx->r7 = S32(ctx->r7 << 16);
            goto L_804F3614;
    }
    // 0x804F360C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x804F3610: addiu       $v1, $zero, 0x5800
    ctx->r3 = ADD32(0, 0X5800);
L_804F3614:
    // 0x804F3614: andi        $t0, $v0, 0xF00
    ctx->r8 = ctx->r2 & 0XF00;
    // 0x804F3618: sra         $t0, $t0, 8
    ctx->r8 = S32(SIGNED(ctx->r8) >> 8);
    // 0x804F361C: lhu         $t3, 0x2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2);
    // 0x804F3620: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x804F3624: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x804F3628: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x804F362C: addu        $a1, $s2, $t0
    ctx->r5 = ADD32(ctx->r18, ctx->r8);
    // 0x804F3630: addu        $a0, $s1, $a3
    ctx->r4 = ADD32(ctx->r17, ctx->r7);
    // 0x804F3634: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x804F3638: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x804F363C: or          $a2, $t3, $v1
    ctx->r6 = ctx->r11 | ctx->r3;
    // 0x804F3640: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x804F3644: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x804F3648: jal         0x8006B1C8
    // 0x804F364C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006B1C8(rdram, ctx);
        goto after_3;
    // 0x804F364C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
L_804F3650:
    // 0x804F3650: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x804F3654: bnel        $s0, $s5, L_804F35E8
    if (ctx->r16 != ctx->r21) {
        // 0x804F3658: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_804F35E8;
    }
    goto skip_0;
    // 0x804F3658: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_0:
    // 0x804F365C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x804F3660: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x804F3664: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x804F3668: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x804F366C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x804F3670: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x804F3674: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x804F3678: jr          $ra
    // 0x804F367C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x804F367C: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_8043E7CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E7CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043E7D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E7D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043E7D8: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8043E7DC: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x8043E7E0: bnel        $t6, $at, L_8043E808
    if (ctx->r14 != ctx->r1) {
        // 0x8043E7E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043E808;
    }
    goto skip_0;
    // 0x8043E7E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043E7E8: jal         0x8043E65C
    // 0x8043E7EC: nop

    func_8043E65C(rdram, ctx);
        goto after_0;
    // 0x8043E7EC: nop

    after_0:
    // 0x8043E7F0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8043E7F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8043E7F8: lw          $t9, 0x174($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X174);
    // 0x8043E7FC: jal         0x800496D4
    // 0x8043E800: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    func_800496D4(rdram, ctx);
        goto after_1;
    // 0x8043E800: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    after_1:
    // 0x8043E804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043E808:
    // 0x8043E808: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043E80C: jr          $ra
    // 0x8043E810: nop

    return;
    // 0x8043E810: nop

;}
RECOMP_FUNC void func_8044AF54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AF54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044AF58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AF5C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044AF60: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044AF64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044AF68: jal         0x8044A558
    // 0x8044AF6C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044AF6C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x8044AF70: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AF74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044AF78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044AF7C: bne         $v0, $zero, L_8044AF94
    if (ctx->r2 != 0) {
        // 0x8044AF80: nop
    
            goto L_8044AF94;
    }
    // 0x8044AF80: nop

    // 0x8044AF84: jal         0x80446568
    // 0x8044AF88: nop

    func_80446568(rdram, ctx);
        goto after_1;
    // 0x8044AF88: nop

    after_1:
    // 0x8044AF8C: b           L_8044AFB8
    // 0x8044AF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044AFB8;
    // 0x8044AF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AF94:
    // 0x8044AF94: bne         $v0, $at, L_8044AFAC
    if (ctx->r2 != ctx->r1) {
        // 0x8044AF98: nop
    
            goto L_8044AFAC;
    }
    // 0x8044AF98: nop

    // 0x8044AF9C: jal         0x804465A0
    // 0x8044AFA0: nop

    func_804465A0(rdram, ctx);
        goto after_2;
    // 0x8044AFA0: nop

    after_2:
    // 0x8044AFA4: b           L_8044AFB8
    // 0x8044AFA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044AFB8;
    // 0x8044AFA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AFAC:
    // 0x8044AFAC: jal         0x804465DC
    // 0x8044AFB0: nop

    func_804465DC(rdram, ctx);
        goto after_3;
    // 0x8044AFB0: nop

    after_3:
    // 0x8044AFB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AFB8:
    // 0x8044AFB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044AFBC: jr          $ra
    // 0x8044AFC0: nop

    return;
    // 0x8044AFC0: nop

;}
RECOMP_FUNC void Fault_LogFReg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FA08: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x8006FA0C: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x8006FA10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006FA14: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_8006FA18:
    // 0x8006FA18: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x8006FA1C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8006FA20: bne         $t9, $sp, L_8006FA18
    if (ctx->r25 != ctx->r29) {
        // 0x8006FA24: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_8006FA18;
    }
    // 0x8006FA24: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006FA28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FA2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006FA30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006FA34: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8006FA38: lui         $at, 0x7F80
    ctx->r1 = S32(0X7F80 << 16);
    // 0x8006FA3C: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8006FA40: and         $v1, $v0, $at
    ctx->r3 = ctx->r2 & ctx->r1;
    // 0x8006FA44: srl         $v1, $v1, 23
    ctx->r3 = S32(U32(ctx->r3) >> 23);
    // 0x8006FA48: addiu       $v1, $v1, -0x7F
    ctx->r3 = ADD32(ctx->r3, -0X7F);
    // 0x8006FA4C: slti        $at, $v1, -0x7E
    ctx->r1 = SIGNED(ctx->r3) < -0X7E ? 1 : 0;
    // 0x8006FA50: bne         $at, $zero, L_8006FA60
    if (ctx->r1 != 0) {
        // 0x8006FA54: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_8006FA60;
    }
    // 0x8006FA54: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8006FA58: bnel        $at, $zero, L_8006FA6C
    if (ctx->r1 != 0) {
        // 0x8006FA5C: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8006FA6C;
    }
    goto skip_0;
    // 0x8006FA5C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8006FA60:
    // 0x8006FA60: bne         $v0, $zero, L_8006FA98
    if (ctx->r2 != 0) {
        // 0x8006FA64: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8006FA98;
    }
    // 0x8006FA64: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006FA68: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_8006FA6C:
    // 0x8006FA6C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006FA70: addiu       $a0, $a0, 0x13B4
    ctx->r4 = ADD32(ctx->r4, 0X13B4);
    // 0x8006FA74: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8006FA78: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006FA7C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8006FA80: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8006FA84: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x8006FA88: jal         0x8008AD5C
    // 0x8006FA8C: nop

    osSyncPrintf(rdram, ctx);
        goto after_0;
    // 0x8006FA8C: nop

    after_0:
    // 0x8006FA90: b           L_8006FAA8
    // 0x8006FA94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006FAA8;
    // 0x8006FA94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006FA98:
    // 0x8006FA98: addiu       $a0, $a0, 0x13C4
    ctx->r4 = ADD32(ctx->r4, 0X13C4);
    // 0x8006FA9C: jal         0x8008AD5C
    // 0x8006FAA0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    osSyncPrintf(rdram, ctx);
        goto after_1;
    // 0x8006FAA0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006FAA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006FAA8:
    // 0x8006FAA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006FAAC: jr          $ra
    // 0x8006FAB0: nop

    return;
    // 0x8006FAB0: nop

;}
RECOMP_FUNC void func_806CD8A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD8A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CD8A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CD8AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CD8B0: jal         0x806CCF00
    // 0x806CD8B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CCF00(rdram, ctx);
        goto after_0;
    // 0x806CD8B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CD8B8: jal         0x806CD470
    // 0x806CD8BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CD470(rdram, ctx);
        goto after_1;
    // 0x806CD8BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CD8C0: jal         0x806CCE38
    // 0x806CD8C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCE38(rdram, ctx);
        goto after_2;
    // 0x806CD8C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806CD8C8: beq         $v0, $zero, L_806CD8EC
    if (ctx->r2 == 0) {
        // 0x806CD8CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806CD8EC;
    }
    // 0x806CD8CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD8D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD8D4: jal         0x806CED40
    // 0x806CD8D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_806CED40(rdram, ctx);
        goto after_3;
    // 0x806CD8D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x806CD8DC: jal         0x806CCCE4
    // 0x806CD8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_4;
    // 0x806CD8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806CD8E4: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x806CD8E8: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_806CD8EC:
    // 0x806CD8EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806CD8F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CD8F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CD8F8: jr          $ra
    // 0x806CD8FC: nop

    return;
    // 0x806CD8FC: nop

;}
RECOMP_FUNC void func_8007B4F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B4F0: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8007B4F4: addiu       $v1, $v1, -0x7AF0
    ctx->r3 = ADD32(ctx->r3, -0X7AF0);
    // 0x8007B4F8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007B4FC: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8007B500: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8007B504: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8007B508: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8007B50C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007B510: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8007B514: lhu         $t8, 0x6($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6);
    // 0x8007B518: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007B51C: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x8007B520: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8007B524: lhu         $t0, 0x8($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X8);
    // 0x8007B528: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8007B52C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8007B530: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x8007B534: lwc1        $f6, 0x29F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X29F0);
    // 0x8007B538: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007B53C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007B540: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8007B544: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8007B548: jr          $ra
    // 0x8007B54C: nop

    return;
    // 0x8007B54C: nop

;}
RECOMP_FUNC void func_805AC200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AC204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC208: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x805AC20C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805AC210: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AC214: bne         $v1, $at, L_805AC240
    if (ctx->r3 != ctx->r1) {
        // 0x805AC218: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_805AC240;
    }
    // 0x805AC218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AC21C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x805AC220: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x805AC224: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805AC228: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x805AC22C: jal         0x805AD274
    // 0x805AC230: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_805AD274(rdram, ctx);
        goto after_0;
    // 0x805AC230: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x805AC234: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805AC238: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805AC23C: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
L_805AC240:
    // 0x805AC240: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x805AC244: bne         $v1, $at, L_805AC25C
    if (ctx->r3 != ctx->r1) {
        // 0x805AC248: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_805AC25C;
    }
    // 0x805AC248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AC24C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x805AC250: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x805AC254: jal         0x805AD274
    // 0x805AC258: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_805AD274(rdram, ctx);
        goto after_1;
    // 0x805AC258: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
L_805AC25C:
    // 0x805AC25C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AC260: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805AC264: jr          $ra
    // 0x805AC268: nop

    return;
    // 0x805AC268: nop

;}
RECOMP_FUNC void func_80427D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427D4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80427D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80427D54: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80427D58: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80427D5C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80427D60: lh          $t6, 0x1C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1C);
    // 0x80427D64: addiu       $v1, $v0, 0x1C
    ctx->r3 = ADD32(ctx->r2, 0X1C);
    // 0x80427D68: beql        $t6, $at, L_80427D8C
    if (ctx->r14 == ctx->r1) {
        // 0x80427D6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80427D8C;
    }
    goto skip_0;
    // 0x80427D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80427D70: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x80427D74: jal         0x80067878
    // 0x80427D78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80427D78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80427D7C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80427D80: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80427D84: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80427D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80427D8C:
    // 0x80427D8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80427D90: jr          $ra
    // 0x80427D94: nop

    return;
    // 0x80427D94: nop

;}
RECOMP_FUNC void func_804A04F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A04F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A04F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A04F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A04FC: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x804A0500: lui         $at, 0x41FB
    ctx->r1 = S32(0X41FB << 16);
    // 0x804A0504: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x804A0508: addiu       $v0, $v0, -0x41F1
    ctx->r2 = ADD32(ctx->r2, -0X41F1);
    // 0x804A050C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x804A0510: addiu       $a0, $v0, 0x200
    ctx->r4 = ADD32(ctx->r2, 0X200);
    // 0x804A0514: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    // 0x804A0518: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x804A051C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x804A0520: jal         0x8004613C
    // 0x804A0524: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x804A0524: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_0:
    // 0x804A0528: beq         $v0, $zero, L_804A0538
    if (ctx->r2 == 0) {
        // 0x804A052C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804A0538;
    }
    // 0x804A052C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804A0530: jal         0x80047F9C
    // 0x804A0534: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x804A0534: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_804A0538:
    // 0x804A0538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A053C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A0540: jr          $ra
    // 0x804A0544: nop

    return;
    // 0x804A0544: nop

;}
RECOMP_FUNC void func_806CFE48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFE48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CFE4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CFE50: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806CFE54: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806CFE58: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806CFE5C: bne         $a1, $zero, L_806CFEF0
    if (ctx->r5 != 0) {
        // 0x806CFE60: lw          $s0, 0x1F4($a0)
        ctx->r16 = MEM_W(ctx->r4, 0X1F4);
            goto L_806CFEF0;
    }
    // 0x806CFE60: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CFE64: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x806CFE68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806CFE6C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x806CFE70: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806CFE74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806CFE78: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x806CFE7C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806CFE80: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x806CFE84: jal         0x806CF864
    // 0x806CFE88: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    func_806CF864(rdram, ctx);
        goto after_0;
    // 0x806CFE88: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x806CFE8C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x806CFE90: jal         0x80066DE4
    // 0x806CFE94: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x806CFE94: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x806CFE98: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x806CFE9C: lwc1        $f8, 0x3C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x806CFEA0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x806CFEA4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806CFEA8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806CFEAC: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x806CFEB0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806CFEB4: jal         0x80066E88
    // 0x806CFEB8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x806CFEB8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x806CFEBC: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x806CFEC0: lwc1        $f10, 0x40($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X40);
    // 0x806CFEC4: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x806CFEC8: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806CFECC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806CFED0: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AF4) << 16);
    // 0x806CFED4: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x806CFED8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806CFEDC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806CFEE0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x806CFEE4: lwc1        $f10, 0x1294($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AF4));
    // 0x806CFEE8: b           L_806CFF78
    // 0x806CFEEC: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
        goto L_806CFF78;
    // 0x806CFEEC: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
L_806CFEF0:
    // 0x806CFEF0: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x806CFEF4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806CFEF8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x806CFEFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806CFF00: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806CFF04: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x806CFF08: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806CFF0C: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x806CFF10: jal         0x806CF864
    // 0x806CFF14: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    func_806CF864(rdram, ctx);
        goto after_3;
    // 0x806CFF14: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x806CFF18: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x806CFF1C: jal         0x80066DE4
    // 0x806CFF20: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x806CFF20: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_4:
    // 0x806CFF24: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x806CFF28: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x806CFF2C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x806CFF30: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806CFF34: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806CFF38: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x806CFF3C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806CFF40: jal         0x80066E88
    // 0x806CFF44: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x806CFF44: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_5:
    // 0x806CFF48: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x806CFF4C: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x806CFF50: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x806CFF54: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806CFF58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806CFF5C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AF8) << 16);
    // 0x806CFF60: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x806CFF64: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806CFF68: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806CFF6C: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x806CFF70: lwc1        $f6, 0x1298($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AF8));
    // 0x806CFF74: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_806CFF78:
    // 0x806CFF78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806CFF7C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806CFF80: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806CFF84: jr          $ra
    // 0x806CFF88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806CFF88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80031060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031068: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003106C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80031070: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80031074: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x80031078: beq         $t8, $zero, L_80031090
    if (ctx->r24 == 0) {
        // 0x8003107C: nop
    
            goto L_80031090;
    }
    // 0x8003107C: nop

    // 0x80031080: jal         0x8002CBF0
    // 0x80031084: nop

    func_8002CBF0(rdram, ctx);
        goto after_0;
    // 0x80031084: nop

    after_0:
    // 0x80031088: b           L_80031090
    // 0x8003108C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80031090;
    // 0x8003108C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80031090:
    // 0x80031090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031098: jr          $ra
    // 0x8003109C: nop

    return;
    // 0x8003109C: nop

;}
RECOMP_FUNC void func_8045C204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045C204: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8045C208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045C20C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8045C210: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x8045C214: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8045C218: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8045C21C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8045C220: jal         0x8004921C
    // 0x8045C224: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8045C224: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    after_0:
    // 0x8045C228: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8045C22C: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x8045C230: jal         0x8004921C
    // 0x8045C234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8045C234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8045C238: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x8045C23C: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8045C240: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x8045C244: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8045C248: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x8045C24C: lbu         $t7, 0x145($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X145);
    // 0x8045C250: lw          $v1, 0x168($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X168);
    // 0x8045C254: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8045C258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8045C25C: lw          $t9, 0x80($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X80);
    // 0x8045C260: mflo        $t6
    ctx->r14 = lo;
    // 0x8045C264: nop

    // 0x8045C268: nop

    // 0x8045C26C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8045C270: mflo        $t8
    ctx->r24 = lo;
    // 0x8045C274: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8045C278: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x8045C27C: lw          $t7, 0x88($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X88);
    // 0x8045C280: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    // 0x8045C284: lw          $t0, 0x1F4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X1F4);
    // 0x8045C288: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8045C28C: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    // 0x8045C290: jal         0x80077338
    // 0x8045C294: sw          $t1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r9;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x8045C294: sw          $t1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r9;
    after_2:
    // 0x8045C298: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x8045C29C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8045C2A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8045C2A4: jal         0x8007711C
    // 0x8045C2A8: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8045C2A8: lw          $a3, 0xAC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XAC);
    after_3:
    // 0x8045C2AC: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x8045C2B0: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8045C2B4: lw          $a1, 0x16C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X16C);
    // 0x8045C2B8: jal         0x8045BF84
    // 0x8045C2BC: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    func_8045BF84(rdram, ctx);
        goto after_4;
    // 0x8045C2BC: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    after_4:
    // 0x8045C2C0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C2C4: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x8045C2C8: lui         $t2, 0xFD50
    ctx->r10 = S32(0XFD50 << 16);
    // 0x8045C2CC: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8045C2D0: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8045C2D4: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x8045C2D8: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8045C2DC: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x8045C2E0: ori         $t4, $t4, 0x6F
    ctx->r12 = ctx->r12 | 0X6F;
    // 0x8045C2E4: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8045C2E8: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C2EC: lui         $t3, 0xF550
    ctx->r11 = S32(0XF550 << 16);
    // 0x8045C2F0: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x8045C2F4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8045C2F8: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x8045C2FC: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x8045C300: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8045C304: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C308: lui         $ra, 0xF300
    ctx->r31 = S32(0XF300 << 16);
    // 0x8045C30C: addiu       $at, $zero, 0x4108
    ctx->r1 = ADD32(0, 0X4108);
    // 0x8045C310: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8045C314: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x8045C318: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8045C31C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8045C320: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C324: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x8045C328: ori         $t6, $t6, 0xF100
    ctx->r14 = ctx->r14 | 0XF100;
    // 0x8045C32C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8045C330: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x8045C334: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8045C338: sw          $ra, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r31;
    // 0x8045C33C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C340: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8045C344: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8045C348: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8045C34C: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8045C350: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8045C354: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8045C358: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C35C: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x8045C360: ori         $t8, $t8, 0x1000
    ctx->r24 = ctx->r24 | 0X1000;
    // 0x8045C364: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8045C368: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x8045C36C: addiu       $t9, $zero, 0x6F
    ctx->r25 = ADD32(0, 0X6F);
    // 0x8045C370: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8045C374: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8045C378: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C37C: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x8045C380: ori         $t9, $t9, 0xC07C
    ctx->r25 = ctx->r25 | 0XC07C;
    // 0x8045C384: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8045C388: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x8045C38C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8045C390: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8045C394: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8045C398: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8045C39C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C3A0: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8045C3A4: lhu         $a0, 0xC($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0XC);
    // 0x8045C3A8: ori         $t9, $t9, 0x699F
    ctx->r25 = ctx->r25 | 0X699F;
    // 0x8045C3AC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8045C3B0: beq         $a0, $at, L_8045C3FC
    if (ctx->r4 == ctx->r1) {
        // 0x8045C3B4: addiu       $at, $zero, 0x4109
        ctx->r1 = ADD32(0, 0X4109);
            goto L_8045C3FC;
    }
    // 0x8045C3B4: addiu       $at, $zero, 0x4109
    ctx->r1 = ADD32(0, 0X4109);
    // 0x8045C3B8: beq         $a0, $at, L_8045C51C
    if (ctx->r4 == ctx->r1) {
        // 0x8045C3BC: lw          $t6, 0xB4($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XB4);
            goto L_8045C51C;
    }
    // 0x8045C3BC: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C3C0: addiu       $at, $zero, 0x410A
    ctx->r1 = ADD32(0, 0X410A);
    // 0x8045C3C4: beq         $a0, $at, L_8045C3FC
    if (ctx->r4 == ctx->r1) {
        // 0x8045C3C8: addiu       $at, $zero, 0x410B
        ctx->r1 = ADD32(0, 0X410B);
            goto L_8045C3FC;
    }
    // 0x8045C3C8: addiu       $at, $zero, 0x410B
    ctx->r1 = ADD32(0, 0X410B);
    // 0x8045C3CC: beq         $a0, $at, L_8045C51C
    if (ctx->r4 == ctx->r1) {
        // 0x8045C3D0: addiu       $at, $zero, 0x469C
        ctx->r1 = ADD32(0, 0X469C);
            goto L_8045C51C;
    }
    // 0x8045C3D0: addiu       $at, $zero, 0x469C
    ctx->r1 = ADD32(0, 0X469C);
    // 0x8045C3D4: beq         $a0, $at, L_8045C3FC
    if (ctx->r4 == ctx->r1) {
        // 0x8045C3D8: addiu       $at, $zero, 0x469D
        ctx->r1 = ADD32(0, 0X469D);
            goto L_8045C3FC;
    }
    // 0x8045C3D8: addiu       $at, $zero, 0x469D
    ctx->r1 = ADD32(0, 0X469D);
    // 0x8045C3DC: beq         $a0, $at, L_8045C51C
    if (ctx->r4 == ctx->r1) {
        // 0x8045C3E0: addiu       $at, $zero, 0x469E
        ctx->r1 = ADD32(0, 0X469E);
            goto L_8045C51C;
    }
    // 0x8045C3E0: addiu       $at, $zero, 0x469E
    ctx->r1 = ADD32(0, 0X469E);
    // 0x8045C3E4: beq         $a0, $at, L_8045C3FC
    if (ctx->r4 == ctx->r1) {
        // 0x8045C3E8: addiu       $at, $zero, 0x469F
        ctx->r1 = ADD32(0, 0X469F);
            goto L_8045C3FC;
    }
    // 0x8045C3E8: addiu       $at, $zero, 0x469F
    ctx->r1 = ADD32(0, 0X469F);
    // 0x8045C3EC: beql        $a0, $at, L_8045C520
    if (ctx->r4 == ctx->r1) {
        // 0x8045C3F0: addiu       $t7, $t6, 0x8
        ctx->r15 = ADD32(ctx->r14, 0X8);
            goto L_8045C520;
    }
    goto skip_0;
    // 0x8045C3F0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    skip_0:
    // 0x8045C3F4: b           L_8045C688
    // 0x8045C3F8: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
        goto L_8045C688;
    // 0x8045C3F8: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
L_8045C3FC:
    // 0x8045C3FC: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8045C400: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x8045C404: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8045C408: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C40C: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(107, 0X1E30) << 16);
    // 0x8045C410: addiu       $t8, $t8, -0x2940
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(107, 0X1E30));
    // 0x8045C414: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8045C418: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x8045C41C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8045C420: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x8045C424: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C428: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8045C42C: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8045C430: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x8045C434: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8045C438: addiu       $t8, $t7, 0x800
    ctx->r24 = ADD32(ctx->r15, 0X800);
    // 0x8045C43C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8045C440: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C444: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8045C448: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8045C44C: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x8045C450: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x8045C454: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C458: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8045C45C: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8045C460: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8045C464: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8045C468: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C46C: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x8045C470: ori         $t7, $t7, 0xF100
    ctx->r15 = ctx->r15 | 0XF100;
    // 0x8045C474: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8045C478: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8045C47C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8045C480: sw          $ra, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r31;
    // 0x8045C484: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C488: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8045C48C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8045C490: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x8045C494: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8045C498: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8045C49C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C4A0: lui         $t9, 0xF548
    ctx->r25 = S32(0XF548 << 16);
    // 0x8045C4A4: ori         $t9, $t9, 0x1000
    ctx->r25 = ctx->r25 | 0X1000;
    // 0x8045C4A8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8045C4AC: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8045C4B0: addiu       $t6, $zero, 0x6F
    ctx->r14 = ADD32(0, 0X6F);
    // 0x8045C4B4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8045C4B8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8045C4BC: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C4C0: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x8045C4C4: ori         $t6, $t6, 0xC07C
    ctx->r14 = ctx->r14 | 0XC07C;
    // 0x8045C4C8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8045C4CC: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8045C4D0: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8045C4D4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8045C4D8: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8045C4DC: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C4E0: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8045C4E4: ori         $t9, $t9, 0x289F
    ctx->r25 = ctx->r25 | 0X289F;
    // 0x8045C4E8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8045C4EC: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8045C4F0: addiu       $t6, $t1, 0x180
    ctx->r14 = ADD32(ctx->r9, 0X180);
    // 0x8045C4F4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8045C4F8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8045C4FC: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C500: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(107, 0X1EF8) << 16);
    // 0x8045C504: addiu       $t9, $t9, -0x2878
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(107, 0X1EF8));
    // 0x8045C508: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8045C50C: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8045C510: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8045C514: b           L_8045C684
    // 0x8045C518: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
        goto L_8045C684;
    // 0x8045C518: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
L_8045C51C:
    // 0x8045C51C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
L_8045C520:
    // 0x8045C520: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x8045C524: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8045C528: ori         $t8, $t8, 0x81FF
    ctx->r24 = ctx->r24 | 0X81FF;
    // 0x8045C52C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8045C530: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8045C534: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C538: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(107, 0X1F40) << 16);
    // 0x8045C53C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8045C540: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8045C544: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8045C548: addiu       $t7, $t7, -0x2830
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(107, 0X1F40));
    // 0x8045C54C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8045C550: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
    // 0x8045C554: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C558: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8045C55C: ori         $t6, $t6, 0x71BF
    ctx->r14 = ctx->r14 | 0X71BF;
    // 0x8045C560: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8045C564: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x8045C568: addiu       $t7, $t1, 0x1E0
    ctx->r15 = ADD32(ctx->r9, 0X1E0);
    // 0x8045C56C: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8045C570: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8045C574: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C578: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(107, 0X2038) << 16);
    // 0x8045C57C: addiu       $t6, $t6, -0x2738
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(107, 0X2038));
    // 0x8045C580: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8045C584: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x8045C588: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8045C58C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8045C590: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C594: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8045C598: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8045C59C: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x8045C5A0: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x8045C5A4: addiu       $t6, $t9, 0x800
    ctx->r14 = ADD32(ctx->r25, 0X800);
    // 0x8045C5A8: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8045C5AC: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C5B0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8045C5B4: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8045C5B8: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x8045C5BC: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x8045C5C0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C5C4: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8045C5C8: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8045C5CC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8045C5D0: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x8045C5D4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C5D8: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x8045C5DC: ori         $t9, $t9, 0xF100
    ctx->r25 = ctx->r25 | 0XF100;
    // 0x8045C5E0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8045C5E4: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x8045C5E8: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8045C5EC: sw          $ra, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r31;
    // 0x8045C5F0: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C5F4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8045C5F8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8045C5FC: sw          $t7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r15;
    // 0x8045C600: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8045C604: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8045C608: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C60C: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x8045C610: ori         $t7, $t7, 0x1000
    ctx->r15 = ctx->r15 | 0X1000;
    // 0x8045C614: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8045C618: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8045C61C: addiu       $t8, $zero, 0x6F
    ctx->r24 = ADD32(0, 0X6F);
    // 0x8045C620: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8045C624: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8045C628: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C62C: lui         $t8, 0xF
    ctx->r24 = S32(0XF << 16);
    // 0x8045C630: ori         $t8, $t8, 0xC07C
    ctx->r24 = ctx->r24 | 0XC07C;
    // 0x8045C634: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8045C638: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8045C63C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8045C640: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8045C644: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8045C648: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C64C: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x8045C650: ori         $t7, $t7, 0x289F
    ctx->r15 = ctx->r15 | 0X289F;
    // 0x8045C654: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8045C658: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8045C65C: addiu       $t8, $t1, 0x380
    ctx->r24 = ADD32(ctx->r9, 0X380);
    // 0x8045C660: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8045C664: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8045C668: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8045C66C: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(107, 0X1EF8) << 16);
    // 0x8045C670: addiu       $t7, $t7, -0x2878
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(107, 0X1EF8));
    // 0x8045C674: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8045C678: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8045C67C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8045C680: sw          $t0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r8;
L_8045C684:
    // 0x8045C684: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
L_8045C688:
    // 0x8045C688: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    // 0x8045C68C: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8045C690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045C694: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x8045C698: jr          $ra
    // 0x8045C69C: nop

    return;
    // 0x8045C69C: nop

;}
RECOMP_FUNC void func_80019E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019E08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019E0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80019E10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80019E14: jal         0x80019AC4
    // 0x80019E18: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x80019E18: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80019E1C: beq         $v0, $zero, L_80019E88
    if (ctx->r2 == 0) {
        // 0x80019E20: lh          $t6, 0x1A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X1A);
            goto L_80019E88;
    }
    // 0x80019E20: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x80019E24: lh          $v1, 0x2A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2A);
    // 0x80019E28: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
    // 0x80019E2C: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x80019E30: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x80019E34: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
    // 0x80019E38: lh          $t8, 0x22($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X22);
    // 0x80019E3C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80019E40: nop

    // 0x80019E44: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80019E48: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
    // 0x80019E4C: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x80019E50: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80019E54: sw          $zero, 0x38($v0)
    MEM_W(0X38, ctx->r2) = 0;
    // 0x80019E58: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80019E5C: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x80019E60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80019E64: beq         $v1, $zero, L_80019E88
    if (ctx->r3 == 0) {
        // 0x80019E68: swc1        $f10, 0x30($v0)
        MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
            goto L_80019E88;
    }
    // 0x80019E68: swc1        $f10, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
    // 0x80019E6C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80019E70: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80019E74: lwc1        $f18, 0x28($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80019E78: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80019E7C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80019E80: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80019E84: swc1        $f10, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f10.u32l;
L_80019E88:
    // 0x80019E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019E8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019E90: jr          $ra
    // 0x80019E94: nop

    return;
    // 0x80019E94: nop

;}
RECOMP_FUNC void func_8043E5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E5BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043E5C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E5C4: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x8043E5C8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043E5CC: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(92, 0X1118) << 16);
    // 0x8043E5D0: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x8043E5D4: addiu       $t7, $t7, -0x1EA8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(92, 0X1118));
    // 0x8043E5D8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8043E5DC: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8043E5E0: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8043E5E4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8043E5E8: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
    // 0x8043E5EC: sw          $v0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r2;
    // 0x8043E5F0: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
    // 0x8043E5F4: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8043E5F8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8043E5FC: sb          $t8, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r24;
    // 0x8043E600: sb          $t9, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r25;
    // 0x8043E604: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8043E608: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8043E60C: jal         0x80065954
    // 0x8043E610: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8043E610: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8043E614: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8043E618: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8043E61C: jal         0x80065954
    // 0x8043E620: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8043E620: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    after_1:
    // 0x8043E624: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8043E628: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8043E62C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8043E630: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8043E634: nop

    // 0x8043E638: bc1fl       L_8043E64C
    if (!c1cs) {
        // 0x8043E63C: sb          $t0, 0x6($v1)
        MEM_B(0X6, ctx->r3) = ctx->r8;
            goto L_8043E64C;
    }
    goto skip_0;
    // 0x8043E63C: sb          $t0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r8;
    skip_0:
    // 0x8043E640: b           L_8043E64C
    // 0x8043E644: sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
        goto L_8043E64C;
    // 0x8043E644: sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
    // 0x8043E648: sb          $t0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r8;
L_8043E64C:
    // 0x8043E64C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043E654: jr          $ra
    // 0x8043E658: nop

    return;
    // 0x8043E658: nop

;}
RECOMP_FUNC void func_807B0F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0F14: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x807B0F18: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(871, 0X3688) << 16);
    // 0x807B0F1C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B0F20: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x807B0F24: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x807B0F28: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B0F2C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B0F30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B0F34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B0F38: addiu       $t6, $t6, 0x31D8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(871, 0X3688));
    // 0x807B0F3C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x807B0F40: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
    // 0x807B0F44: lui         $t9, 0x807B
    ctx->r25 = S32(RELOC_HI16(871, 0X36A0) << 16);
    // 0x807B0F48: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x807B0F4C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x807B0F50: addiu       $t9, $t9, 0x31F0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(871, 0X36A0));
    // 0x807B0F54: addiu       $s4, $sp, 0x34
    ctx->r20 = ADD32(ctx->r29, 0X34);
    // 0x807B0F58: sw          $t7, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r15;
    // 0x807B0F5C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x807B0F60: addiu       $s1, $a0, 0x178
    ctx->r17 = ADD32(ctx->r4, 0X178);
    // 0x807B0F64: addiu       $s0, $a0, 0x388
    ctx->r16 = ADD32(ctx->r4, 0X388);
    // 0x807B0F68: sw          $t8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r24;
    // 0x807B0F6C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x807B0F70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807B0F74: addiu       $s5, $zero, 0x42
    ctx->r21 = ADD32(0, 0X42);
    // 0x807B0F78: sw          $t7, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r15;
    // 0x807B0F7C: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x807B0F80: sw          $t8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r24;
    // 0x807B0F84: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x807B0F88: sw          $t7, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r15;
    // 0x807B0F8C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x807B0F90: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
    // 0x807B0F94: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x807B0F98: sw          $t0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r8;
    // 0x807B0F9C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x807B0FA0: sw          $t1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r9;
    // 0x807B0FA4: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x807B0FA8: sw          $t0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r8;
    // 0x807B0FAC: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x807B0FB0: sw          $t1, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r9;
    // 0x807B0FB4: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x807B0FB8: sw          $t0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r8;
L_807B0FBC:
    // 0x807B0FBC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x807B0FC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807B0FC4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x807B0FC8: addu        $t2, $s4, $v0
    ctx->r10 = ADD32(ctx->r20, ctx->r2);
    // 0x807B0FCC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x807B0FD0: addu        $t5, $s3, $v0
    ctx->r13 = ADD32(ctx->r19, ctx->r2);
    // 0x807B0FD4: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x807B0FD8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x807B0FDC: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    // 0x807B0FE0: jalr        $t9
    // 0x807B0FE4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x807B0FE4: nop

    after_0:
    // 0x807B0FE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x807B0FEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x807B0FF0: bne         $s2, $s5, L_807B0FBC
    if (ctx->r18 != ctx->r21) {
        // 0x807B0FF4: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_807B0FBC;
    }
    // 0x807B0FF4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B0FF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807B0FFC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B1000: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B1004: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B1008: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B100C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x807B1010: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x807B1014: jr          $ra
    // 0x807B1018: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x807B1018: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8006237C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006237C: lh          $v1, 0x6($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X6);
    // 0x80062380: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80062384: beq         $v1, $zero, L_800623C0
    if (ctx->r3 == 0) {
        // 0x80062388: nop
    
            goto L_800623C0;
    }
    // 0x80062388: nop

L_8006238C:
    // 0x8006238C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80062390: beq         $a0, $zero, L_800623B8
    if (ctx->r4 == 0) {
        // 0x80062394: nop
    
            goto L_800623B8;
    }
    // 0x80062394: nop

    // 0x80062398: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x8006239C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800623A0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800623A4: lw          $a2, 0x18($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X18);
    // 0x800623A8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800623AC: beq         $a2, $zero, L_800623B8
    if (ctx->r6 == 0) {
        // 0x800623B0: addiu       $t6, $a2, -0x1
        ctx->r14 = ADD32(ctx->r6, -0X1);
            goto L_800623B8;
    }
    // 0x800623B0: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x800623B4: sw          $t6, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r14;
L_800623B8:
    // 0x800623B8: bne         $v1, $zero, L_8006238C
    if (ctx->r3 != 0) {
        // 0x800623BC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006238C;
    }
    // 0x800623BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800623C0:
    // 0x800623C0: jr          $ra
    // 0x800623C4: nop

    return;
    // 0x800623C4: nop

;}
RECOMP_FUNC void func_8006607C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006607C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066080: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80066084: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80066088: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8006608C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80066090: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80066094: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066098: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006609C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800660A0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800660A4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800660A8: jal         0x8007FFF0
    // 0x800660AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8007FFF0(rdram, ctx);
        goto after_0;
    // 0x800660AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800660B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800660B4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800660B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800660BC: beql        $t6, $zero, L_800660D8
    if (ctx->r14 == 0) {
        // 0x800660C0: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_800660D8;
    }
    goto skip_0;
    // 0x800660C0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x800660C4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800660C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800660CC: b           L_800660DC
    // 0x800660D0: nop

        goto L_800660DC;
    // 0x800660D0: nop

    // 0x800660D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_800660D8:
    // 0x800660D8: nop

L_800660DC:
    // 0x800660DC: beq         $t7, $zero, L_800660F4
    if (ctx->r15 == 0) {
        // 0x800660E0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800660F4;
    }
    // 0x800660E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800660E4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800660E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800660EC: b           L_80066100
    // 0x800660F0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
        goto L_80066100;
    // 0x800660F0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_800660F4:
    // 0x800660F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800660F8: nop

    // 0x800660FC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_80066100:
    // 0x80066100: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80066104: jal         0x8007FE74
    // 0x80066108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007FE74(rdram, ctx);
        goto after_1;
    // 0x80066108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006610C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80066110: lwc1        $f10, 0xEE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XEE0);
    // 0x80066114: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80066118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006611C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80066120: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80066124: jal         0x8007FF58
    // 0x80066128: nop

    func_8007FF58(rdram, ctx);
        goto after_2;
    // 0x80066128: nop

    after_2:
    // 0x8006612C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80066130: lwc1        $f4, 0xEE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XEE4);
    // 0x80066134: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80066138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006613C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80066140: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80066144: jal         0x8007FF0C
    // 0x80066148: nop

    func_8007FF0C(rdram, ctx);
        goto after_3;
    // 0x80066148: nop

    after_3:
    // 0x8006614C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80066150: lwc1        $f10, 0xEE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XEE8);
    // 0x80066154: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80066158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006615C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80066160: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80066164: jal         0x8007FEC8
    // 0x80066168: nop

    func_8007FEC8(rdram, ctx);
        goto after_4;
    // 0x80066168: nop

    after_4:
    // 0x8006616C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066170: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80066174: jal         0x8007FE74
    // 0x80066178: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    func_8007FE74(rdram, ctx);
        goto after_5;
    // 0x80066178: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_5:
    // 0x8006617C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066180: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066184: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80066188: jr          $ra
    // 0x8006618C: nop

    return;
    // 0x8006618C: nop

;}
RECOMP_FUNC void func_80798D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798D3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80798D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80798D44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80798D48: jal         0x80045A34
    // 0x80798D4C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80798D4C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80798D50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80798D54: bne         $v0, $zero, L_80798D64
    if (ctx->r2 != 0) {
        // 0x80798D58: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80798D64;
    }
    // 0x80798D58: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80798D5C: b           L_80798D70
    // 0x80798D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80798D70;
    // 0x80798D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80798D64:
    // 0x80798D64: jal         0x80798D2C
    // 0x80798D68: nop

    func_80798D2C(rdram, ctx);
        goto after_1;
    // 0x80798D68: nop

    after_1:
    // 0x80798D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80798D70:
    // 0x80798D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80798D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80798D78: jr          $ra
    // 0x80798D7C: nop

    return;
    // 0x80798D7C: nop

;}
RECOMP_FUNC void func_806707A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806707A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806707A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806707AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806707B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806707B4: jal         0x80045A34
    // 0x806707B8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806707B8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x806707BC: bne         $v0, $zero, L_806707D4
    if (ctx->r2 != 0) {
        // 0x806707C0: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_806707D4;
    }
    // 0x806707C0: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806707C4: jal         0x800445A4
    // 0x806707C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806707C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806707CC: b           L_8067086C
    // 0x806707D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8067086C;
    // 0x806707D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806707D4:
    // 0x806707D4: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x806707D8: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(520, 0X718) << 16);
    // 0x806707DC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806707E0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806707E4: addiu       $t6, $t6, 0x998
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(520, 0X718));
    // 0x806707E8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806707EC: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806707F0: lui         $t0, 0x8067
    ctx->r8 = S32(RELOC_HI16(520, 0X164) << 16);
    // 0x806707F4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x806707F8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806707FC: addiu       $t0, $t0, 0x3E4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(520, 0X164));
    // 0x80670800: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x80670804: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x80670808: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x8067080C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80670810: jal         0x80067BBC
    // 0x80670814: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80670814: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x80670818: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8067081C: jal         0x80067F78
    // 0x80670820: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_3;
    // 0x80670820: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80670824: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80670828: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8067082C: addiu       $t1, $zero, 0x1F4
    ctx->r9 = ADD32(0, 0X1F4);
    // 0x80670830: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x80670834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80670838: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8067083C: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x80670840: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80670844: jal         0x8005FD1C
    // 0x80670848: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    func_8005FD1C(rdram, ctx);
        goto after_4;
    // 0x80670848: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    after_4:
    // 0x8067084C: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x80670850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80670854: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80670858: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8067085C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80670860: jal         0x8067087C
    // 0x80670864: sh          $zero, 0x12($t4)
    MEM_H(0X12, ctx->r12) = 0;
    func_8067087C(rdram, ctx);
        goto after_5;
    // 0x80670864: sh          $zero, 0x12($t4)
    MEM_H(0X12, ctx->r12) = 0;
    after_5:
    // 0x80670868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067086C:
    // 0x8067086C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80670870: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80670874: jr          $ra
    // 0x80670878: nop

    return;
    // 0x80670878: nop

;}
RECOMP_FUNC void func_800444D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800444D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800444D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800444D8: lh          $t6, 0x17E($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X17E);
    // 0x800444DC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800444E0: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x800444E4: bne         $t6, $at, L_80044500
    if (ctx->r14 != ctx->r1) {
        // 0x800444E8: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80044500;
    }
    // 0x800444E8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800444EC: addiu       $a0, $a0, 0x480
    ctx->r4 = ADD32(ctx->r4, 0X480);
    // 0x800444F0: jal         0x80071380
    // 0x800444F4: addiu       $a1, $zero, 0x4A2
    ctx->r5 = ADD32(0, 0X4A2);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x800444F4: addiu       $a1, $zero, 0x4A2
    ctx->r5 = ADD32(0, 0X4A2);
    after_0:
    // 0x800444F8: b           L_80044570
    // 0x800444FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80044570;
    // 0x800444FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044500:
    // 0x80044500: lbu         $t7, 0x17D($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X17D);
    // 0x80044504: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80044508: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004450C: beq         $t7, $at, L_80044524
    if (ctx->r15 == ctx->r1) {
        // 0x80044510: addiu       $a0, $a0, 0x490
        ctx->r4 = ADD32(ctx->r4, 0X490);
            goto L_80044524;
    }
    // 0x80044510: addiu       $a0, $a0, 0x490
    ctx->r4 = ADD32(ctx->r4, 0X490);
    // 0x80044514: addiu       $a1, $zero, 0x4AC
    ctx->r5 = ADD32(0, 0X4AC);
    // 0x80044518: jal         0x80071380
    // 0x8004451C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8004451C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80044520: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80044524:
    // 0x80044524: lw          $t8, 0x180($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X180);
    // 0x80044528: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004452C: addiu       $a0, $a0, 0x4A0
    ctx->r4 = ADD32(ctx->r4, 0X4A0);
    // 0x80044530: beq         $t8, $zero, L_80044548
    if (ctx->r24 == 0) {
        // 0x80044534: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_80044548;
    }
    // 0x80044534: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80044538: jal         0x80071380
    // 0x8004453C: addiu       $a1, $zero, 0x4B5
    ctx->r5 = ADD32(0, 0X4B5);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8004453C: addiu       $a1, $zero, 0x4B5
    ctx->r5 = ADD32(0, 0X4B5);
    after_2:
    // 0x80044540: b           L_80044570
    // 0x80044544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80044570;
    // 0x80044544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044548:
    // 0x80044548: lw          $t0, -0x77F0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X77F0);
    // 0x8004454C: lh          $t2, 0x17E($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X17E);
    // 0x80044550: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80044554: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80044558: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8004455C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80044560: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80044564: jal         0x80043C94
    // 0x80044568: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    func_80043C94(rdram, ctx);
        goto after_3;
    // 0x80044568: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    after_3:
    // 0x8004456C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044570:
    // 0x80044570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044574: jr          $ra
    // 0x80044578: nop

    return;
    // 0x80044578: nop

;}
RECOMP_FUNC void func_8057EFC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057EFC4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8057EFC8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8057EFCC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8057EFD0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8057EFD4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8057EFD8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8057EFDC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8057EFE0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8057EFE4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8057EFE8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8057EFEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8057EFF0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8057EFF4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057EFF8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8057EFFC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8057F000: addiu       $s3, $v0, 0x14
    ctx->r19 = ADD32(ctx->r2, 0X14);
    // 0x8057F004: addiu       $s4, $v0, 0x1C
    ctx->r20 = ADD32(ctx->r2, 0X1C);
    // 0x8057F008: jal         0x8057EFA0
    // 0x8057F00C: addiu       $s2, $v0, 0x2C
    ctx->r18 = ADD32(ctx->r2, 0X2C);
    func_8057EFA0(rdram, ctx);
        goto after_0;
    // 0x8057F00C: addiu       $s2, $v0, 0x2C
    ctx->r18 = ADD32(ctx->r2, 0X2C);
    after_0:
    // 0x8057F010: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8057F014: bltz        $v0, L_8057F0C0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8057F018: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8057F0C0;
    }
    // 0x8057F018: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8057F01C: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47C8) << 16);
    // 0x8057F020: lui         $s7, 0x800F
    ctx->r23 = S32(0X800F << 16);
    // 0x8057F024: lui         $s6, 0x8058
    ctx->r22 = S32(RELOC_HI16(399, 0X41A8) << 16);
    // 0x8057F028: addiu       $s6, $s6, 0x2FB8
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(399, 0X41A8));
    // 0x8057F02C: addiu       $s7, $s7, 0x7EA0
    ctx->r23 = ADD32(ctx->r23, 0X7EA0);
    // 0x8057F030: lwc1        $f20, 0x35D8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47C8));
L_8057F034:
    // 0x8057F034: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8057F038: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8057F03C: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x8057F040: jal         0x805803C4
    // 0x8057F044: lw          $a3, 0x8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X8);
    func_805803C4(rdram, ctx);
        goto after_1;
    // 0x8057F044: lw          $a3, 0x8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X8);
    after_1:
    // 0x8057F048: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8057F04C: sh          $s0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r16;
    // 0x8057F050: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x8057F054: lw          $t6, 0xA68($s7)
    ctx->r14 = MEM_W(ctx->r23, 0XA68);
    // 0x8057F058: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x8057F05C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8057F060: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8057F064: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8057F068: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8057F06C: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8057F070: addiu       $a2, $zero, 0x40EC
    ctx->r6 = ADD32(0, 0X40EC);
    // 0x8057F074: jalr        $t9
    // 0x8057F078: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8057F078: nop

    after_2:
    // 0x8057F07C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8057F080: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8057F084: slt         $at, $s5, $s0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8057F088: lwc1        $f4, 0x6C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x8057F08C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x8057F090: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8057F094: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8057F098: swc1        $f6, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f6.u32l;
    // 0x8057F09C: lw          $v1, -0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X4);
    // 0x8057F0A0: lwc1        $f8, 0x70($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X70);
    // 0x8057F0A4: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8057F0A8: swc1        $f10, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f10.u32l;
    // 0x8057F0AC: lw          $v1, -0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X4);
    // 0x8057F0B0: lwc1        $f16, 0x74($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8057F0B4: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8057F0B8: beq         $at, $zero, L_8057F034
    if (ctx->r1 == 0) {
        // 0x8057F0BC: swc1        $f18, 0x74($v1)
        MEM_W(0X74, ctx->r3) = ctx->f18.u32l;
            goto L_8057F034;
    }
    // 0x8057F0BC: swc1        $f18, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f18.u32l;
L_8057F0C0:
    // 0x8057F0C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8057F0C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8057F0C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8057F0CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8057F0D0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8057F0D4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8057F0D8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8057F0DC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8057F0E0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8057F0E4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8057F0E8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8057F0EC: jr          $ra
    // 0x8057F0F0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8057F0F0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8003B7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B7D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B7D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B7DC: jal         0x8004700C
    // 0x8003B7E0: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003B7E0: nop

    after_0:
    // 0x8003B7E4: jal         0x8003B764
    // 0x8003B7E8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8003B764(rdram, ctx);
        goto after_1;
    // 0x8003B7E8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003B7EC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8003B7F0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x8003B7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B7F8: beql        $a3, $zero, L_8003B888
    if (ctx->r7 == 0) {
        // 0x8003B7FC: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8003B888;
    }
    goto skip_0;
    // 0x8003B7FC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    skip_0:
    // 0x8003B800: lw          $a2, 0x1F4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X1F4);
    // 0x8003B804: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x8003B808: lbu         $t6, 0x1F8($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1F8);
    // 0x8003B80C: lbu         $v1, 0x12C8($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X12C8);
    // 0x8003B810: lhu         $a0, 0x12BE($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X12BE);
    // 0x8003B814: beq         $t6, $zero, L_8003B840
    if (ctx->r14 == 0) {
        // 0x8003B818: lw          $t0, 0x1F0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X1F0);
            goto L_8003B840;
    }
    // 0x8003B818: lw          $t0, 0x1F0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X1F0);
    // 0x8003B81C: beq         $t0, $zero, L_8003B840
    if (ctx->r8 == 0) {
        // 0x8003B820: nop
    
            goto L_8003B840;
    }
    // 0x8003B820: nop

    // 0x8003B824: lhu         $t7, 0xC($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0XC);
    // 0x8003B828: addiu       $at, $zero, 0x4005
    ctx->r1 = ADD32(0, 0X4005);
    // 0x8003B82C: bne         $t7, $at, L_8003B840
    if (ctx->r15 != ctx->r1) {
        // 0x8003B830: nop
    
            goto L_8003B840;
    }
    // 0x8003B830: nop

    // 0x8003B834: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8003B838: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003B83C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_8003B840:
    // 0x8003B840: beq         $v1, $zero, L_8003B884
    if (ctx->r3 == 0) {
        // 0x8003B844: addiu       $t0, $zero, 0x4004
        ctx->r8 = ADD32(0, 0X4004);
            goto L_8003B884;
    }
    // 0x8003B844: addiu       $t0, $zero, 0x4004
    ctx->r8 = ADD32(0, 0X4004);
L_8003B848:
    // 0x8003B848: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003B84C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003B850: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003B854: andi        $a0, $a0, 0x7
    ctx->r4 = ctx->r4 & 0X7;
    // 0x8003B858: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8003B85C: mflo        $t8
    ctx->r24 = lo;
    // 0x8003B860: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8003B864: lw          $v0, 0x11FC($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X11FC);
    // 0x8003B868: lhu         $t1, 0xC($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XC);
    // 0x8003B86C: bne         $t0, $t1, L_8003B87C
    if (ctx->r8 != ctx->r9) {
        // 0x8003B870: nop
    
            goto L_8003B87C;
    }
    // 0x8003B870: nop

    // 0x8003B874: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003B878: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_8003B87C:
    // 0x8003B87C: bne         $v1, $zero, L_8003B848
    if (ctx->r3 != 0) {
        // 0x8003B880: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_8003B848;
    }
    // 0x8003B880: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
L_8003B884:
    // 0x8003B884: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8003B888:
    // 0x8003B888: jr          $ra
    // 0x8003B88C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003B88C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000157C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000157C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80001580: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80001584: lh          $t6, 0x36($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X36);
    // 0x80001588: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x8000158C: addiu       $t8, $t8, 0x4D10
    ctx->r24 = ADD32(ctx->r24, 0X4D10);
    // 0x80001590: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80001594: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80001598: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000159C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800015A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800015A4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800015A8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800015AC: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x800015B0: lbu         $t9, 0x1B($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1B);
    // 0x800015B4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800015B8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800015BC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800015C0: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x800015C4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800015C8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800015CC: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800015D0: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800015D4: lbu         $t4, 0x1C($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X1C);
    // 0x800015D8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800015DC: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x800015E0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800015E4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800015E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800015EC: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x800015F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800015F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800015F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800015FC: bne         $t4, $at, L_80001668
    if (ctx->r12 != ctx->r1) {
        // 0x80001600: addiu       $v1, $v0, 0x50
        ctx->r3 = ADD32(ctx->r2, 0X50);
            goto L_80001668;
    }
    // 0x80001600: addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // 0x80001604: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80001608: lhu         $a2, 0xE($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0XE);
    // 0x8000160C: lh          $a3, 0x10($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X10);
    // 0x80001610: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80001614: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80001618: addiu       $a1, $zero, 0xC80
    ctx->r5 = ADD32(0, 0XC80);
    // 0x8000161C: jal         0x800013D4
    // 0x80001620: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800013D4(rdram, ctx);
        goto after_0;
    // 0x80001620: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_0:
    // 0x80001624: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80001628: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8000162C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80001630: lh          $a3, 0x12($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X12);
    // 0x80001634: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80001638: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000163C: beq         $a3, $zero, L_80001690
    if (ctx->r7 == 0) {
        // 0x80001640: lh          $t6, 0x36($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X36);
            goto L_80001690;
    }
    // 0x80001640: lh          $t6, 0x36($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X36);
    // 0x80001644: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x80001648: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8000164C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80001650: addiu       $a1, $a1, 0xC80
    ctx->r5 = ADD32(ctx->r5, 0XC80);
    // 0x80001654: jal         0x800013D4
    // 0x80001658: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_800013D4(rdram, ctx);
        goto after_1;
    // 0x80001658: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_1:
    // 0x8000165C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80001660: b           L_80001690
    // 0x80001664: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80001690;
    // 0x80001664: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80001668:
    // 0x80001668: lw          $a3, 0x54($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X54);
    // 0x8000166C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80001670: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80001674: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80001678: addiu       $a1, $zero, 0xC80
    ctx->r5 = ADD32(0, 0XC80);
    // 0x8000167C: addiu       $a2, $zero, 0x340
    ctx->r6 = ADD32(0, 0X340);
    // 0x80001680: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80001684: jal         0x800010EC
    // 0x80001688: addu        $a3, $a3, $at
    ctx->r7 = ADD32(ctx->r7, ctx->r1);
    func_800010EC(rdram, ctx);
        goto after_2;
    // 0x80001688: addu        $a3, $a3, $at
    ctx->r7 = ADD32(ctx->r7, ctx->r1);
    after_2:
    // 0x8000168C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
L_80001690:
    // 0x80001690: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001694: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80001698: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000169C: sb          $zero, 0x18($t0)
    MEM_B(0X18, ctx->r8) = 0;
    // 0x800016A0: jr          $ra
    // 0x800016A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800016A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80682DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682DD4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682DD8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682DDC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682DE0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682DE4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682DE8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682DEC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682DF0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682DF4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682DF8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682DFC: jr          $ra
    // 0x80682E00: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682E00: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8067BD3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BD3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067BD40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067BD44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8067BD48: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067BD4C: jal         0x8004700C
    // 0x8067BD50: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8067BD50: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8067BD54: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8067BD58: jal         0x8067B500
    // 0x8067BD5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8067B500(rdram, ctx);
        goto after_1;
    // 0x8067BD5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8067BD60: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8067BD64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8067BD68: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x8067BD6C: jalr        $t9
    // 0x8067BD70: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8067BD70: nop

    after_2:
    // 0x8067BD74: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8067BD78: beql        $v0, $zero, L_8067BDB4
    if (ctx->r2 == 0) {
        // 0x8067BD7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8067BDB4;
    }
    goto skip_0;
    // 0x8067BD7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8067BD80: lw          $t1, 0x174($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X174);
    // 0x8067BD84: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8067BD88: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8067BD8C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8067BD90: bnel        $t0, $t2, L_8067BDB4
    if (ctx->r8 != ctx->r10) {
        // 0x8067BD94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8067BDB4;
    }
    goto skip_1;
    // 0x8067BD94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8067BD98: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x8067BD9C: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X2664) << 16);
    // 0x8067BDA0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8067BDA4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8067BDA8: lwc1        $f4, -0x3CEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X2664));
    // 0x8067BDAC: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x8067BDB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8067BDB4:
    // 0x8067BDB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067BDB8: jr          $ra
    // 0x8067BDBC: nop

    return;
    // 0x8067BDBC: nop

;}
RECOMP_FUNC void func_80003850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003850: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003854: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x80003858: lw          $t6, 0x1F08($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F08);
    // 0x8000385C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80003864: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80003868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000386C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003870: sw          $t6, 0x1F0C($v0)
    MEM_W(0X1F0C, ctx->r2) = ctx->r14;
    // 0x80003874: addiu       $a0, $a0, 0x6C18
    ctx->r4 = ADD32(ctx->r4, 0X6C18);
    // 0x80003878: jal         0x80003698
    // 0x8000387C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    func_80003698(rdram, ctx);
        goto after_0;
    // 0x8000387C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x80003880: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80003884: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003888: addiu       $a0, $a0, 0x6C28
    ctx->r4 = ADD32(ctx->r4, 0X6C28);
    // 0x8000388C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80003890: jal         0x800036F0
    // 0x80003894: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    func_800036F0(rdram, ctx);
        goto after_1;
    // 0x80003894: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x80003898: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8000389C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800038A0: addiu       $a0, $a0, 0x6C18
    ctx->r4 = ADD32(ctx->r4, 0X6C18);
    // 0x800038A4: jal         0x80003698
    // 0x800038A8: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    func_80003698(rdram, ctx);
        goto after_2;
    // 0x800038A8: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    after_2:
    // 0x800038AC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800038B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800038B4: addiu       $a0, $a0, 0x6C38
    ctx->r4 = ADD32(ctx->r4, 0X6C38);
    // 0x800038B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800038BC: jal         0x800036F0
    // 0x800038C0: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    func_800036F0(rdram, ctx);
        goto after_3;
    // 0x800038C0: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    after_3:
    // 0x800038C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800038C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800038CC: jr          $ra
    // 0x800038D0: nop

    return;
    // 0x800038D0: nop

;}
RECOMP_FUNC void func_80453B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453B04: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80453B08: lhu         $v1, -0x6DAC($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X6DAC);
    // 0x80453B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453B14: andi        $v1, $v1, 0x7
    ctx->r3 = ctx->r3 & 0X7;
    // 0x80453B18: beq         $v1, $zero, L_80453B38
    if (ctx->r3 == 0) {
        // 0x80453B1C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80453B38;
    }
    // 0x80453B1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80453B20: bltz        $v1, L_80453B34
    if (SIGNED(ctx->r3) < 0) {
        // 0x80453B24: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80453B34;
    }
    // 0x80453B24: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80453B28: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80453B2C: bnel        $at, $zero, L_80453B3C
    if (ctx->r1 != 0) {
        // 0x80453B30: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80453B3C;
    }
    goto skip_0;
    // 0x80453B30: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    skip_0:
L_80453B34:
    // 0x80453B34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80453B38:
    // 0x80453B38: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_80453B3C:
    // 0x80453B3C: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D8C) << 16);
    // 0x80453B40: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80453B44: lw          $t9, -0x7E94($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D8C));
    // 0x80453B48: jalr        $t9
    // 0x80453B4C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80453B4C: nop

    after_0:
    // 0x80453B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453B54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453B58: jr          $ra
    // 0x80453B5C: nop

    return;
    // 0x80453B5C: nop

;}
RECOMP_FUNC void func_804C2AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2AC0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804C2AC4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x804C2AC8: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x804C2ACC: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x804C2AD0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x804C2AD4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x804C2AD8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x804C2ADC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x804C2AE0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804C2AE4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804C2AE8: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C2AEC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x804C2AF0: jal         0x8004921C
    // 0x804C2AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804C2AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804C2AF8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x804C2AFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C2B00: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x804C2B04: jal         0x8004921C
    // 0x804C2B08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804C2B08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x804C2B0C: lwc1        $f4, 0x6D4($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X6D4);
    // 0x804C2B10: lwc1        $f6, 0x88($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X88);
    // 0x804C2B14: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x804C2B18: negu        $t8, $v0
    ctx->r24 = SUB32(0, ctx->r2);
    // 0x804C2B1C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804C2B20: bgez        $a2, L_804C2B30
    if (SIGNED(ctx->r6) >= 0) {
        // 0x804C2B24: sra         $s0, $a2, 1
        ctx->r16 = S32(SIGNED(ctx->r6) >> 1);
            goto L_804C2B30;
    }
    // 0x804C2B24: sra         $s0, $a2, 1
    ctx->r16 = S32(SIGNED(ctx->r6) >> 1);
    // 0x804C2B28: addiu       $at, $a2, 0x1
    ctx->r1 = ADD32(ctx->r6, 0X1);
    // 0x804C2B2C: sra         $s0, $at, 1
    ctx->r16 = S32(SIGNED(ctx->r1) >> 1);
L_804C2B30:
    // 0x804C2B30: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804C2B34: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x804C2B38: addiu       $s5, $v0, -0x6
    ctx->r21 = ADD32(ctx->r2, -0X6);
    // 0x804C2B3C: addiu       $v1, $s4, 0x288
    ctx->r3 = ADD32(ctx->r20, 0X288);
    // 0x804C2B40: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x804C2B44: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x804C2B48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804C2B4C: subu        $ra, $t8, $t7
    ctx->r31 = SUB32(ctx->r24, ctx->r15);
    // 0x804C2B50: addiu       $ra, $ra, 0x9C
    ctx->r31 = ADD32(ctx->r31, 0X9C);
    // 0x804C2B54: sll         $t4, $a2, 6
    ctx->r12 = S32(ctx->r6 << 6);
    // 0x804C2B58: addiu       $t0, $v1, 0x20
    ctx->r8 = ADD32(ctx->r3, 0X20);
    // 0x804C2B5C: sll         $t5, $t5, 6
    ctx->r13 = S32(ctx->r13 << 6);
    // 0x804C2B60: negu        $s2, $s0
    ctx->r18 = SUB32(0, ctx->r16);
    // 0x804C2B64: addiu       $s6, $zero, 0xF
    ctx->r22 = ADD32(0, 0XF);
    // 0x804C2B68: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x804C2B6C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x804C2B70: bgez        $v0, L_804C2B80
    if (SIGNED(ctx->r2) >= 0) {
        // 0x804C2B74: sra         $s1, $v0, 1
        ctx->r17 = S32(SIGNED(ctx->r2) >> 1);
            goto L_804C2B80;
    }
    // 0x804C2B74: sra         $s1, $v0, 1
    ctx->r17 = S32(SIGNED(ctx->r2) >> 1);
    // 0x804C2B78: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x804C2B7C: sra         $s1, $at, 1
    ctx->r17 = S32(SIGNED(ctx->r1) >> 1);
L_804C2B80:
    // 0x804C2B80: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x804C2B84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804C2B88: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(206, 0X1450) << 16);
    // 0x804C2B8C: lwc1        $f14, 0x3ED0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(206, 0X1450));
    // 0x804C2B90: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(206, 0X1454) << 16);
    // 0x804C2B94: lwc1        $f12, 0x3ED4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(206, 0X1454));
    // 0x804C2B98: negu        $s3, $s1
    ctx->r19 = SUB32(0, ctx->r17);
    // 0x804C2B9C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x804C2BA0: addiu       $s7, $zero, 0xE
    ctx->r23 = ADD32(0, 0XE);
L_804C2BA4:
    // 0x804C2BA4: lwc1        $f0, 0x6C8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X6C8);
    // 0x804C2BA8: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x804C2BAC: addu        $a2, $s3, $t3
    ctx->r6 = ADD32(ctx->r19, ctx->r11);
    // 0x804C2BB0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x804C2BB4: addu        $t1, $s1, $t3
    ctx->r9 = ADD32(ctx->r17, ctx->r11);
    // 0x804C2BB8: bc1t        L_804C2BD8
    if (c1cs) {
        // 0x804C2BBC: nop
    
            goto L_804C2BD8;
    }
    // 0x804C2BBC: nop

    // 0x804C2BC0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x804C2BC4: nop

    // 0x804C2BC8: bc1t        L_804C2BD8
    if (c1cs) {
        // 0x804C2BCC: nop
    
            goto L_804C2BD8;
    }
    // 0x804C2BCC: nop

    // 0x804C2BD0: b           L_804C2C70
    // 0x804C2BD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_804C2C70;
    // 0x804C2BD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_804C2BD8:
    // 0x804C2BD8: beq         $at, $zero, L_804C2BF8
    if (ctx->r1 == 0) {
        // 0x804C2BDC: subu        $t9, $s7, $t2
        ctx->r25 = SUB32(ctx->r23, ctx->r10);
            goto L_804C2BF8;
    }
    // 0x804C2BDC: subu        $t9, $s7, $t2
    ctx->r25 = SUB32(ctx->r23, ctx->r10);
    // 0x804C2BE0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x804C2BE4: nop

    // 0x804C2BE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804C2BEC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804C2BF0: b           L_804C2C0C
    // 0x804C2BF4: div.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
        goto L_804C2C0C;
    // 0x804C2BF4: div.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
L_804C2BF8:
    // 0x804C2BF8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x804C2BFC: nop

    // 0x804C2C00: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804C2C04: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804C2C08: div.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
L_804C2C0C:
    // 0x804C2C0C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x804C2C10: nop

    // 0x804C2C14: bc1tl       L_804C2C38
    if (c1cs) {
        // 0x804C2C18: c.lt.s      $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
            goto L_804C2C38;
    }
    goto skip_0;
    // 0x804C2C18: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    skip_0:
    // 0x804C2C1C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x804C2C20: nop

    // 0x804C2C24: bc1tl       L_804C2C38
    if (c1cs) {
        // 0x804C2C28: c.lt.s      $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
            goto L_804C2C38;
    }
    goto skip_1;
    // 0x804C2C28: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    skip_1:
    // 0x804C2C2C: b           L_804C2C70
    // 0x804C2C30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_804C2C70;
    // 0x804C2C30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804C2C34: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
L_804C2C38:
    // 0x804C2C38: nop

    // 0x804C2C3C: bc1fl       L_804C2C5C
    if (!c1cs) {
        // 0x804C2C40: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_804C2C5C;
    }
    goto skip_2;
    // 0x804C2C40: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_2:
    // 0x804C2C44: sqrt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = sqrtf(ctx->f2.fl);
    // 0x804C2C48: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x804C2C4C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x804C2C50: b           L_804C2C74
    // 0x804C2C54: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
        goto L_804C2C74;
    // 0x804C2C54: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x804C2C58: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_804C2C5C:
    // 0x804C2C5C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x804C2C60: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x804C2C64: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804C2C68: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x804C2C6C: nop

L_804C2C70:
    // 0x804C2C70: slt         $at, $ra, $t3
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r11) ? 1 : 0;
L_804C2C74:
    // 0x804C2C74: beq         $at, $zero, L_804C2D30
    if (ctx->r1 == 0) {
        // 0x804C2C78: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_804C2D30;
    }
    // 0x804C2C78: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x804C2C7C: addu        $a0, $s2, $a3
    ctx->r4 = ADD32(ctx->r18, ctx->r7);
    // 0x804C2C80: addu        $a2, $s3, $ra
    ctx->r6 = ADD32(ctx->r19, ctx->r31);
    // 0x804C2C84: addu        $t1, $s1, $ra
    ctx->r9 = ADD32(ctx->r17, ctx->r31);
    // 0x804C2C88: addu        $a1, $s0, $a3
    ctx->r5 = ADD32(ctx->r16, ctx->r7);
    // 0x804C2C8C: sh          $a2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r6;
    // 0x804C2C90: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x804C2C94: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x804C2C98: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x804C2C9C: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x804C2CA0: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x804C2CA4: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x804C2CA8: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x804C2CAC: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x804C2CB0: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x804C2CB4: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
    // 0x804C2CB8: sh          $a0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r4;
    // 0x804C2CBC: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x804C2CC0: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x804C2CC4: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x804C2CC8: sh          $t5, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r13;
    // 0x804C2CCC: sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // 0x804C2CD0: sb          $v0, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r2;
    // 0x804C2CD4: sb          $v0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r2;
    // 0x804C2CD8: sb          $v0, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r2;
    // 0x804C2CDC: sh          $a1, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r5;
    // 0x804C2CE0: sh          $a2, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r6;
    // 0x804C2CE4: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x804C2CE8: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x804C2CEC: sh          $t4, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r12;
    // 0x804C2CF0: sb          $v0, 0xF($t0)
    MEM_B(0XF, ctx->r8) = ctx->r2;
    // 0x804C2CF4: sb          $v0, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r2;
    // 0x804C2CF8: sb          $v0, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r2;
    // 0x804C2CFC: sb          $v0, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r2;
    // 0x804C2D00: sh          $zero, 0xA($t0)
    MEM_H(0XA, ctx->r8) = 0;
    // 0x804C2D04: sb          $v0, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = ctx->r2;
    // 0x804C2D08: sb          $v0, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = ctx->r2;
    // 0x804C2D0C: sb          $v0, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = ctx->r2;
    // 0x804C2D10: sb          $v0, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = ctx->r2;
    // 0x804C2D14: sh          $t5, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = ctx->r13;
    // 0x804C2D18: sh          $t4, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r12;
    // 0x804C2D1C: sh          $zero, 0x36($v1)
    MEM_H(0X36, ctx->r3) = 0;
    // 0x804C2D20: sh          $zero, 0x34($v1)
    MEM_H(0X34, ctx->r3) = 0;
    // 0x804C2D24: sh          $t1, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r9;
    // 0x804C2D28: b           L_804C2DD8
    // 0x804C2D2C: sh          $a1, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r5;
        goto L_804C2DD8;
    // 0x804C2D2C: sh          $a1, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r5;
L_804C2D30:
    // 0x804C2D30: addu        $a0, $s2, $a3
    ctx->r4 = ADD32(ctx->r18, ctx->r7);
    // 0x804C2D34: addu        $a1, $s0, $a3
    ctx->r5 = ADD32(ctx->r16, ctx->r7);
    // 0x804C2D38: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x804C2D3C: sh          $a2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r6;
    // 0x804C2D40: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x804C2D44: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x804C2D48: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x804C2D4C: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x804C2D50: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x804C2D54: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x804C2D58: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x804C2D5C: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x804C2D60: sh          $a0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r4;
    // 0x804C2D64: sh          $t1, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r9;
    // 0x804C2D68: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x804C2D6C: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x804C2D70: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x804C2D74: sh          $t5, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r13;
    // 0x804C2D78: sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    // 0x804C2D7C: sb          $v0, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r2;
    // 0x804C2D80: sb          $v0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r2;
    // 0x804C2D84: sb          $v0, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r2;
    // 0x804C2D88: sh          $a1, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r5;
    // 0x804C2D8C: sh          $a2, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r6;
    // 0x804C2D90: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x804C2D94: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x804C2D98: sh          $t4, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r12;
    // 0x804C2D9C: sb          $v0, 0xF($t0)
    MEM_B(0XF, ctx->r8) = ctx->r2;
    // 0x804C2DA0: sb          $v0, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r2;
    // 0x804C2DA4: sb          $v0, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r2;
    // 0x804C2DA8: sb          $v0, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r2;
    // 0x804C2DAC: sh          $zero, 0xA($t0)
    MEM_H(0XA, ctx->r8) = 0;
    // 0x804C2DB0: sb          $v0, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = ctx->r2;
    // 0x804C2DB4: sb          $v0, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = ctx->r2;
    // 0x804C2DB8: sb          $v0, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = ctx->r2;
    // 0x804C2DBC: sb          $v0, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = ctx->r2;
    // 0x804C2DC0: sh          $t5, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = ctx->r13;
    // 0x804C2DC4: sh          $t4, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r12;
    // 0x804C2DC8: sh          $zero, 0x36($v1)
    MEM_H(0X36, ctx->r3) = 0;
    // 0x804C2DCC: sh          $zero, 0x34($v1)
    MEM_H(0X34, ctx->r3) = 0;
    // 0x804C2DD0: sh          $t1, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r9;
    // 0x804C2DD4: sh          $a1, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r5;
L_804C2DD8:
    // 0x804C2DD8: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x804C2DDC: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x804C2DE0: bne         $t2, $s6, L_804C2BA4
    if (ctx->r10 != ctx->r22) {
        // 0x804C2DE4: addu        $t3, $t3, $s5
        ctx->r11 = ADD32(ctx->r11, ctx->r21);
            goto L_804C2BA4;
    }
    // 0x804C2DE4: addu        $t3, $t3, $s5
    ctx->r11 = ADD32(ctx->r11, ctx->r21);
    // 0x804C2DE8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x804C2DEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804C2DF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804C2DF4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x804C2DF8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x804C2DFC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x804C2E00: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x804C2E04: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x804C2E08: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x804C2E0C: jr          $ra
    // 0x804C2E10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x804C2E10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8049F874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F874: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8049F878: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8049F87C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8049F880: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8049F884: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8049F888: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8049F88C: lui         $t7, 0x804A
    ctx->r15 = S32(RELOC_HI16(167, 0X1160) << 16);
    // 0x8049F890: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8049F894: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8049F898: addiu       $t7, $t7, -0x320
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(167, 0X1160));
    // 0x8049F89C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8049F8A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8049F8A4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8049F8A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F8AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8049F8B0: jal         0x8049FBAC
    // 0x8049F8B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8049FBAC(rdram, ctx);
        goto after_0;
    // 0x8049F8B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8049F8B8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8049F8BC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8049F8C0: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    // 0x8049F8C4: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x8049F8C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8049F8CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8049F8D0: jal         0x80048378
    // 0x8049F8D4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8049F8D4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    after_1:
    // 0x8049F8D8: lw          $t2, 0x174($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X174);
    // 0x8049F8DC: lui         $t1, 0x804A
    ctx->r9 = S32(RELOC_HI16(167, 0XA78) << 16);
    // 0x8049F8E0: addiu       $t1, $t1, -0xA08
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(167, 0XA78));
    // 0x8049F8E4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8049F8E8: lui         $t4, 0x804A
    ctx->r12 = S32(RELOC_HI16(167, 0XCC8) << 16);
    // 0x8049F8EC: addiu       $t4, $t4, -0x7B8
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(167, 0XCC8));
    // 0x8049F8F0: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x8049F8F4: sw          $t4, 0x1F8($s1)
    MEM_W(0X1F8, ctx->r17) = ctx->r12;
    // 0x8049F8F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8049F8FC: jal         0x80045A34
    // 0x8049F900: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x8049F900: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_2:
    // 0x8049F904: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x8049F908: jal         0x80058958
    // 0x8049F90C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_80058958(rdram, ctx);
        goto after_3;
    // 0x8049F90C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_3:
    // 0x8049F910: beq         $v0, $zero, L_8049F984
    if (ctx->r2 == 0) {
        // 0x8049F914: lui         $t5, 0x8010
        ctx->r13 = S32(0X8010 << 16);
            goto L_8049F984;
    }
    // 0x8049F914: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x8049F918: lw          $t5, -0x7BC4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7BC4);
    // 0x8049F91C: lw          $t6, 0x10C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10C);
    // 0x8049F920: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8049F924: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x8049F928: beql        $t8, $zero, L_8049F988
    if (ctx->r24 == 0) {
        // 0x8049F92C: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_8049F988;
    }
    goto skip_0;
    // 0x8049F92C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    skip_0:
    // 0x8049F930: jal         0x80056564
    // 0x8049F934: nop

    func_80056564(rdram, ctx);
        goto after_4;
    // 0x8049F934: nop

    after_4:
    // 0x8049F938: beq         $v0, $zero, L_8049F988
    if (ctx->r2 == 0) {
        // 0x8049F93C: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8049F988;
    }
    // 0x8049F93C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8049F940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8049F944: jal         0x800457A0
    // 0x8049F948: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_5;
    // 0x8049F948: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8049F94C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8049F950: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x8049F954: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8049F958: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8049F95C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8049F960: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8049F964: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8049F968: jal         0x80056584
    // 0x8049F96C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_6;
    // 0x8049F96C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_6:
    // 0x8049F970: lw          $t1, 0x16C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X16C);
    // 0x8049F974: lui         $t2, 0x804A
    ctx->r10 = S32(RELOC_HI16(167, 0XC58) << 16);
    // 0x8049F978: addiu       $t2, $t2, -0x828
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(167, 0XC58));
    // 0x8049F97C: b           L_8049F988
    // 0x8049F980: sw          $t2, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r10;
        goto L_8049F988;
    // 0x8049F980: sw          $t2, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r10;
L_8049F984:
    // 0x8049F984: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8049F988:
    // 0x8049F988: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8049F98C: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8049F990: ori         $t6, $zero, 0x2
    ctx->r14 = 0 | 0X2;
    // 0x8049F994: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x8049F998: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x8049F99C: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8049F9A0: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8049F9A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8049F9A8: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8049F9AC: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8049F9B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8049F9B4: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8049F9B8: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x8049F9BC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8049F9C0: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8049F9C4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8049F9C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8049F9CC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8049F9D0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8049F9D4: jr          $ra
    // 0x8049F9D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8049F9D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80043F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043F00: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80043F04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80043F08: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80043F0C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80043F10: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80043F14: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80043F18: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80043F1C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80043F20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80043F24: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80043F28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80043F2C: lh          $s2, 0x6($a0)
    ctx->r18 = MEM_H(ctx->r4, 0X6);
    // 0x80043F30: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80043F34: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80043F38: beq         $s2, $zero, L_80043FE4
    if (ctx->r18 == 0) {
        // 0x80043F3C: lw          $s3, 0x10($a0)
        ctx->r19 = MEM_W(ctx->r4, 0X10);
            goto L_80043FE4;
    }
    // 0x80043F3C: lw          $s3, 0x10($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X10);
    // 0x80043F40: lui         $s7, 0x800B
    ctx->r23 = S32(0X800B << 16);
    // 0x80043F44: addiu       $s7, $s7, 0x3E0
    ctx->r23 = ADD32(ctx->r23, 0X3E0);
    // 0x80043F48: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x80043F4C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80043F50: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80043F54:
    // 0x80043F54: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80043F58: beq         $v0, $zero, L_80043FDC
    if (ctx->r2 == 0) {
        // 0x80043F5C: nop
    
            goto L_80043FDC;
    }
    // 0x80043F5C: nop

    // 0x80043F60: beq         $s6, $v0, L_80043FD0
    if (ctx->r22 == ctx->r2) {
        // 0x80043F64: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_80043FD0;
    }
    // 0x80043F64: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80043F68: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80043F6C: beq         $t7, $zero, L_80043F80
    if (ctx->r15 == 0) {
        // 0x80043F70: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80043F80;
    }
    // 0x80043F70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80043F74: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80043F78: jal         0x80071380
    // 0x80043F7C: addiu       $a1, $zero, 0x321
    ctx->r5 = ADD32(0, 0X321);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80043F7C: addiu       $a1, $zero, 0x321
    ctx->r5 = ADD32(0, 0X321);
    after_0:
L_80043F80:
    // 0x80043F80: bne         $s5, $s4, L_80043F90
    if (ctx->r21 != ctx->r20) {
        // 0x80043F84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80043F90;
    }
    // 0x80043F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80043F88: jal         0x800461F4
    // 0x80043F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800461F4(rdram, ctx);
        goto after_1;
    // 0x80043F8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80043F90:
    // 0x80043F90: lbu         $t8, 0x4($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X4);
    // 0x80043F94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80043F98: beql        $s4, $t8, L_80043FD4
    if (ctx->r20 == ctx->r24) {
        // 0x80043F9C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_80043FD4;
    }
    goto skip_0;
    // 0x80043F9C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x80043FA0: jal         0x80043D0C
    // 0x80043FA4: lh          $a1, 0x17E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X17E);
    func_80043D0C(rdram, ctx);
        goto after_2;
    // 0x80043FA4: lh          $a1, 0x17E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X17E);
    after_2:
    // 0x80043FA8: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x80043FAC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80043FB0: sh          $t0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r8;
    // 0x80043FB4: lbu         $t1, 0x18($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X18);
    // 0x80043FB8: beq         $fp, $t1, L_80043FC8
    if (ctx->r30 == ctx->r9) {
        // 0x80043FBC: nop
    
            goto L_80043FC8;
    }
    // 0x80043FBC: nop

    // 0x80043FC0: jal         0x80048CF8
    // 0x80043FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048CF8(rdram, ctx);
        goto after_3;
    // 0x80043FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80043FC8:
    // 0x80043FC8: jal         0x80048BA0
    // 0x80043FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048BA0(rdram, ctx);
        goto after_4;
    // 0x80043FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80043FD0:
    // 0x80043FD0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80043FD4:
    // 0x80043FD4: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80043FD8: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
L_80043FDC:
    // 0x80043FDC: bne         $s2, $zero, L_80043F54
    if (ctx->r18 != 0) {
        // 0x80043FE0: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80043F54;
    }
    // 0x80043FE0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_80043FE4:
    // 0x80043FE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80043FE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043FEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80043FF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80043FF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80043FF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80043FFC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80044000: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80044004: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80044008: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8004400C: jr          $ra
    // 0x80044010: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80044010: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_807AB2BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AB2BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AB2C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AB2C4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807AB2C8: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(853, 0X170C) << 16);
    // 0x807AB2CC: addiu       $t6, $t6, -0x4CB4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(853, 0X170C));
    // 0x807AB2D0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807AB2D4: jal         0x8005FCA8
    // 0x807AB2D8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x807AB2D8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    after_0:
    // 0x807AB2DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AB2E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AB2E4: jr          $ra
    // 0x807AB2E8: nop

    return;
    // 0x807AB2E8: nop

;}
RECOMP_FUNC void func_8005B870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B870: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005B874: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005B878: lh          $t7, 0x4E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4E);
    // 0x8005B87C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8005B880: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8005B884: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8005B888: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005B88C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8005B890: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x8005B894: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8005B898: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8005B89C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8005B8A0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005B8A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005B8A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005B8AC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005B8B0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8005B8B4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8005B8B8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8005B8BC: jal         0x8005B54C
    // 0x8005B8C0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    func_8005B54C(rdram, ctx);
        goto after_0;
    // 0x8005B8C0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_0:
    // 0x8005B8C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B8C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005B8CC: jr          $ra
    // 0x8005B8D0: nop

    return;
    // 0x8005B8D0: nop

;}
RECOMP_FUNC void func_80046EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046EF0: lhu         $t6, 0xE($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XE);
    // 0x80046EF4: lhu         $t8, 0x0($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X0);
    // 0x80046EF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80046EFC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80046F00: bne         $t7, $t8, L_80046F10
    if (ctx->r15 != ctx->r24) {
        // 0x80046F04: nop
    
            goto L_80046F10;
    }
    // 0x80046F04: nop

    // 0x80046F08: jr          $ra
    // 0x80046F0C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80046F0C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80046F10:
    // 0x80046F10: jr          $ra
    // 0x80046F14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80046F14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_804E9C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E9C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E9C58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804E9C5C: jal         0x80059278
    // 0x804E9C60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80059278(rdram, ctx);
        goto after_0;
    // 0x804E9C60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x804E9C64: beq         $v0, $zero, L_804E9C80
    if (ctx->r2 == 0) {
        // 0x804E9C68: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_804E9C80;
    }
    // 0x804E9C68: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x804E9C6C: jalr        $t9
    // 0x804E9C70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x804E9C70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804E9C74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804E9C78: bnel        $v0, $at, L_804E9C8C
    if (ctx->r2 != ctx->r1) {
        // 0x804E9C7C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804E9C8C;
    }
    goto skip_0;
    // 0x804E9C7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_804E9C80:
    // 0x804E9C80: b           L_804E9C8C
    // 0x804E9C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804E9C8C;
    // 0x804E9C84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804E9C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804E9C8C:
    // 0x804E9C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E9C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E9C94: jr          $ra
    // 0x804E9C98: nop

    return;
    // 0x804E9C98: nop

;}
RECOMP_FUNC void func_8051A640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051A644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051A648: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8051A64C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8051A650: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8051A654: beq         $a1, $at, L_8051A670
    if (ctx->r5 == ctx->r1) {
        // 0x8051A658: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_8051A670;
    }
    // 0x8051A658: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x8051A65C: jal         0x80067878
    // 0x8051A660: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8051A660: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8051A664: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8051A668: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8051A66C: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_8051A670:
    // 0x8051A670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051A674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051A678: jr          $ra
    // 0x8051A67C: nop

    return;
    // 0x8051A67C: nop

;}
RECOMP_FUNC void func_8002EB04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EB04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002EB08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002EB0C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002EB10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002EB14: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002EB18: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8002EB1C: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8002EB20: sw          $t6, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->r14;
    // 0x8002EB24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002EB28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8002EB2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002EB30: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002EB34: jal         0x8001DC5C
    // 0x8002EB38: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_8001DC5C(rdram, ctx);
        goto after_0;
    // 0x8002EB38: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x8002EB3C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002EB40: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002EB44: addiu       $t8, $t8, 0x3450
    ctx->r24 = ADD32(ctx->r24, 0X3450);
    // 0x8002EB48: sb          $t7, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r15;
    // 0x8002EB4C: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x8002EB50: jal         0x8002AE90
    // 0x8002EB54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002AE90(rdram, ctx);
        goto after_1;
    // 0x8002EB54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002EB58: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002EB5C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002EB60: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8002EB64: sh          $v1, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r3;
    // 0x8002EB68: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8002EB6C: sh          $v1, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r3;
    // 0x8002EB70: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8002EB74: sh          $v1, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r3;
    // 0x8002EB78: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8002EB7C: lh          $t3, 0x10($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X10);
    // 0x8002EB80: beql        $t3, $zero, L_8002EBAC
    if (ctx->r11 == 0) {
        // 0x8002EB84: lh          $t5, 0x12($v0)
        ctx->r13 = MEM_H(ctx->r2, 0X12);
            goto L_8002EBAC;
    }
    goto skip_0;
    // 0x8002EB84: lh          $t5, 0x12($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X12);
    skip_0:
    // 0x8002EB88: lbu         $t4, 0x76($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X76);
    // 0x8002EB8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002EB90: bnel        $t4, $zero, L_8002EBAC
    if (ctx->r12 != 0) {
        // 0x8002EB94: lh          $t5, 0x12($v0)
        ctx->r13 = MEM_H(ctx->r2, 0X12);
            goto L_8002EBAC;
    }
    goto skip_1;
    // 0x8002EB94: lh          $t5, 0x12($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X12);
    skip_1:
    // 0x8002EB98: jal         0x8005FA48
    // 0x8002EB9C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_8005FA48(rdram, ctx);
        goto after_2;
    // 0x8002EB9C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_2:
    // 0x8002EBA0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002EBA4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8002EBA8: lh          $t5, 0x12($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X12);
L_8002EBAC:
    // 0x8002EBAC: beql        $t5, $zero, L_8002EBD8
    if (ctx->r13 == 0) {
        // 0x8002EBB0: lh          $t7, 0x14($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X14);
            goto L_8002EBD8;
    }
    goto skip_2;
    // 0x8002EBB0: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    skip_2:
    // 0x8002EBB4: lbu         $t6, 0x77($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X77);
    // 0x8002EBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002EBBC: bnel        $t6, $zero, L_8002EBD8
    if (ctx->r14 != 0) {
        // 0x8002EBC0: lh          $t7, 0x14($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X14);
            goto L_8002EBD8;
    }
    goto skip_3;
    // 0x8002EBC0: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
    skip_3:
    // 0x8002EBC4: jal         0x8005FAE0
    // 0x8002EBC8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_8005FAE0(rdram, ctx);
        goto after_3;
    // 0x8002EBC8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_3:
    // 0x8002EBCC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002EBD0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8002EBD4: lh          $t7, 0x14($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X14);
L_8002EBD8:
    // 0x8002EBD8: beq         $t7, $zero, L_8002EBF4
    if (ctx->r15 == 0) {
        // 0x8002EBDC: nop
    
            goto L_8002EBF4;
    }
    // 0x8002EBDC: nop

    // 0x8002EBE0: lbu         $t8, 0x79($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X79);
    // 0x8002EBE4: bne         $t8, $zero, L_8002EBF4
    if (ctx->r24 != 0) {
        // 0x8002EBE8: nop
    
            goto L_8002EBF4;
    }
    // 0x8002EBE8: nop

    // 0x8002EBEC: jal         0x8005FB74
    // 0x8002EBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FB74(rdram, ctx);
        goto after_4;
    // 0x8002EBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8002EBF4:
    // 0x8002EBF4: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x8002EBF8: addiu       $t9, $t9, 0x33B4
    ctx->r25 = ADD32(ctx->r25, 0X33B4);
    // 0x8002EBFC: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8002EC00: lwc1        $f4, 0xC4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8002EC04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002EC08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002EC0C: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8002EC10: lwc1        $f6, 0xC8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8002EC14: jal         0x8002E274
    // 0x8002EC18: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    func_8002E274(rdram, ctx);
        goto after_5;
    // 0x8002EC18: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x8002EC1C: jal         0x8002DB78
    // 0x8002EC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002DB78(rdram, ctx);
        goto after_6;
    // 0x8002EC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8002EC24: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8002EC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002EC2C: jal         0x8003D894
    // 0x8002EC30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003D894(rdram, ctx);
        goto after_7;
    // 0x8002EC30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8002EC34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002EC38: jal         0x8002E90C
    // 0x8002EC3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8002E90C(rdram, ctx);
        goto after_8;
    // 0x8002EC3C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x8002EC40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002EC44: lwc1        $f10, -0x50($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X50);
    // 0x8002EC48: lwc1        $f8, 0x8C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8002EC4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002EC50: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x8002EC54: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8002EC58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002EC5C: bc1f        L_8002EC70
    if (!c1cs) {
        // 0x8002EC60: nop
    
            goto L_8002EC70;
    }
    // 0x8002EC60: nop

    // 0x8002EC64: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002EC68: b           L_8002EC74
    // 0x8002EC6C: lwc1        $f0, -0x4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4C);
        goto L_8002EC74;
    // 0x8002EC6C: lwc1        $f0, -0x4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4C);
L_8002EC70:
    // 0x8002EC70: lwc1        $f0, -0x48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X48);
L_8002EC74:
    // 0x8002EC74: jal         0x80047AB8
    // 0x8002EC78: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    func_80047AB8(rdram, ctx);
        goto after_9;
    // 0x8002EC78: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    after_9:
    // 0x8002EC7C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002EC80: jal         0x8002ADE4
    // 0x8002EC84: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    func_8002ADE4(rdram, ctx);
        goto after_10;
    // 0x8002EC84: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    after_10:
    // 0x8002EC88: jal         0x80067A50
    // 0x8002EC8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80067A50(rdram, ctx);
        goto after_11;
    // 0x8002EC8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x8002EC90: sw          $zero, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = 0;
    // 0x8002EC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002EC98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002EC9C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002ECA0: jr          $ra
    // 0x8002ECA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002ECA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805362F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805362F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805362F8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805362FC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536300: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536304: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536308: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053630C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536310: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536314: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536318: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053631C: jr          $ra
    // 0x80536320: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536320: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807A6778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6778: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807A677C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807A6780: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807A6784: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807A6788: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807A678C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807A6790: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807A6794: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807A6798: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807A679C: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(847, 0X14EC) << 16);
    // 0x807A67A0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807A67A4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807A67A8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807A67AC: lw          $t1, 0x71EC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(847, 0X14EC));
    // 0x807A67B0: jr          $ra
    // 0x807A67B4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807A67B4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8052D5FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D5FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8052D600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052D604: jal         0x8052D478
    // 0x8052D608: nop

    func_8052D478(rdram, ctx);
        goto after_0;
    // 0x8052D608: nop

    after_0:
    // 0x8052D60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052D610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052D614: jr          $ra
    // 0x8052D618: nop

    return;
    // 0x8052D618: nop

;}
RECOMP_FUNC void func_804D64CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D64CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D64D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D64D4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804D64D8: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804D64DC: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(252, 0X5E4) << 16);
    // 0x804D64E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804D64E4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804D64E8: lw          $t8, 0x68E4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(252, 0X5E4));
    // 0x804D64EC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804D64F0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804D64F4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804D64F8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804D64FC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804D6500: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804D6504: beql        $v1, $zero, L_804D6538
    if (ctx->r3 == 0) {
        // 0x804D6508: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804D6538;
    }
    goto skip_0;
    // 0x804D6508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804D650C: jalr        $v1
    // 0x804D6510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804D6510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804D6514: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D6518: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804D651C: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804D6520: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804D6524: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804D6528: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804D652C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804D6530: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804D6534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D6538:
    // 0x804D6538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D653C: jr          $ra
    // 0x804D6540: nop

    return;
    // 0x804D6540: nop

;}
RECOMP_FUNC void func_80052A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052A28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80052A2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80052A30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80052A34: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80052A38: jal         0x80052840
    // 0x80052A3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80052840(rdram, ctx);
        goto after_0;
    // 0x80052A3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80052A40: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80052A44: bne         $v0, $zero, L_80052A54
    if (ctx->r2 != 0) {
        // 0x80052A48: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80052A54;
    }
    // 0x80052A48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80052A4C: b           L_80052A90
    // 0x80052A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80052A90;
    // 0x80052A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80052A54:
    // 0x80052A54: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    // 0x80052A58: jal         0x80065728
    // 0x80052A5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x80052A5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80052A60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80052A64: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80052A68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80052A6C: addiu       $t6, $a0, 0x6C
    ctx->r14 = ADD32(ctx->r4, 0X6C);
    // 0x80052A70: jal         0x80052950
    // 0x80052A74: sw          $t6, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->r14;
    func_80052950(rdram, ctx);
        goto after_2;
    // 0x80052A74: sw          $t6, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->r14;
    after_2:
    // 0x80052A78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80052A7C: jal         0x800529E4
    // 0x80052A80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800529E4(rdram, ctx);
        goto after_3;
    // 0x80052A80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80052A84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80052A88: jal         0x80052994
    // 0x80052A8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80052994(rdram, ctx);
        goto after_4;
    // 0x80052A8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
L_80052A90:
    // 0x80052A90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052A94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052A98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80052A9C: jr          $ra
    // 0x80052AA0: nop

    return;
    // 0x80052AA0: nop

;}
RECOMP_FUNC void func_806A9CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9CD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806A9CDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806A9CE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806A9CE4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806A9CE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806A9CEC: jal         0x806A9A30
    // 0x806A9CF0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_806A9A30(rdram, ctx);
        goto after_0;
    // 0x806A9CF0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x806A9CF4: beq         $v0, $zero, L_806A9D4C
    if (ctx->r2 == 0) {
        // 0x806A9CF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806A9D4C;
    }
    // 0x806A9CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806A9CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A9D00: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806A9D04: jal         0x806AA784
    // 0x806A9D08: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806A9D08: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x806A9D0C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x806A9D10: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x806A9D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806A9D18: lhu         $t7, 0x1C0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1C0);
    // 0x806A9D1C: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    // 0x806A9D20: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x806A9D24: sh          $t8, 0x1C0($v0)
    MEM_H(0X1C0, ctx->r2) = ctx->r24;
    // 0x806A9D28: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    // 0x806A9D2C: lh          $t3, 0x1BE($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X1BE);
    // 0x806A9D30: lh          $t9, 0x144($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X144);
    // 0x806A9D34: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x806A9D38: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x806A9D3C: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x806A9D40: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x806A9D44: jal         0x806A99B4
    // 0x806A9D48: sh          $t2, 0x12C($t5)
    MEM_H(0X12C, ctx->r13) = ctx->r10;
    func_806A99B4(rdram, ctx);
        goto after_2;
    // 0x806A9D48: sh          $t2, 0x12C($t5)
    MEM_H(0X12C, ctx->r13) = ctx->r10;
    after_2:
L_806A9D4C:
    // 0x806A9D4C: jal         0x806A99EC
    // 0x806A9D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806A99EC(rdram, ctx);
        goto after_3;
    // 0x806A9D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806A9D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806A9D58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806A9D5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806A9D60: jr          $ra
    // 0x806A9D64: nop

    return;
    // 0x806A9D64: nop

;}
RECOMP_FUNC void func_805E4C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4C4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E4C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E4C54: jal         0x805E4BB8
    // 0x805E4C58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805E4BB8(rdram, ctx);
        goto after_0;
    // 0x805E4C58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805E4C5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805E4C60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4C64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805E4C68: jal         0x805E4D78
    // 0x805E4C6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805E4D78(rdram, ctx);
        goto after_1;
    // 0x805E4C6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x805E4C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E4C74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4C78: jr          $ra
    // 0x805E4C7C: nop

    return;
    // 0x805E4C7C: nop

;}
RECOMP_FUNC void func_800667D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800667D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800667D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800667DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800667E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800667E4: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x800667E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800667EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800667F0: bc1fl       L_80066800
    if (!c1cs) {
        // 0x800667F4: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_80066800;
    }
    goto skip_0;
    // 0x800667F4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x800667F8: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    // 0x800667FC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_80066800:
    // 0x80066800: nop

    // 0x80066804: bc1f        L_80066810
    if (!c1cs) {
        // 0x80066808: nop
    
            goto L_80066810;
    }
    // 0x80066808: nop

    // 0x8006680C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80066810:
    // 0x80066810: lwc1        $f6, 0xEF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XEF8);
    // 0x80066814: sub.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x80066818: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006681C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80066820: nop

    // 0x80066824: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80066828: nop

    // 0x8006682C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80066830: nop

    // 0x80066834: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80066838: nop

    // 0x8006683C: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80066840: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80066844: lwc1        $f6, 0xEFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XEFC);
    // 0x80066848: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006684C: mul.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80066850: lwc1        $f8, 0xF00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XF00);
    // 0x80066854: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80066858: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006685C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80066860: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80066864: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80066868: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8006686C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80066870: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80066874: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80066878: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x8006687C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80066880: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80066884: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80066888: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    // 0x8006688C: jr          $ra
    // 0x80066890: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x80066890: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_8005B20C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B20C: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8005B210: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8005B214: jr          $ra
    // 0x8005B218: lh          $v0, 0x2C($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2C);
    return;
    // 0x8005B218: lh          $v0, 0x2C($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X2C);
;}
RECOMP_FUNC void pad_set_logical_stick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FBA8: sb          $a1, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r5;
    // 0x8007FBAC: jr          $ra
    // 0x8007FBB0: sb          $a2, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r6;
    return;
    // 0x8007FBB0: sb          $a2, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void func_804104C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804104C4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x804104C8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x804104CC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x804104D0: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x804104D4: addu        $a3, $a0, $at
    ctx->r7 = ADD32(ctx->r4, ctx->r1);
    // 0x804104D8: lw          $t6, 0x39E4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39E4);
    // 0x804104DC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x804104E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804104E4: beq         $t6, $zero, L_8041068C
    if (ctx->r14 == 0) {
        // 0x804104E8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8041068C;
    }
    // 0x804104E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804104EC: addu        $t0, $a0, $at
    ctx->r8 = ADD32(ctx->r4, ctx->r1);
    // 0x804104F0: lw          $t4, 0x39E8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X39E8);
    // 0x804104F4: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
L_804104F8:
    // 0x804104F8: beq         $t4, $zero, L_80410678
    if (ctx->r12 == 0) {
        // 0x804104FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80410678;
    }
    // 0x804104FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80410500: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80410504: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80410508: sll         $t8, $t8, 9
    ctx->r24 = S32(ctx->r24 << 9);
    // 0x8041050C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80410510: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80410514: addu        $t5, $t7, $t9
    ctx->r13 = ADD32(ctx->r15, ctx->r25);
    // 0x80410518: addiu       $t5, $t5, 0x5C0
    ctx->r13 = ADD32(ctx->r13, 0X5C0);
    // 0x8041051C: addiu       $s0, $t5, 0x30
    ctx->r16 = ADD32(ctx->r13, 0X30);
    // 0x80410520: addiu       $t1, $a2, 0x1
    ctx->r9 = ADD32(ctx->r6, 0X1);
    // 0x80410524: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
L_80410528:
    // 0x80410528: sh          $zero, 0x2($t5)
    MEM_H(0X2, ctx->r13) = 0;
    // 0x8041052C: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x80410530: sh          $zero, 0x6($t5)
    MEM_H(0X6, ctx->r13) = 0;
    // 0x80410534: lw          $t6, 0x39DC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39DC);
    // 0x80410538: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8041053C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80410540: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80410544: addiu       $t5, $t5, 0x40
    ctx->r13 = ADD32(ctx->r13, 0X40);
    // 0x80410548: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8041054C: mflo        $t8
    ctx->r24 = lo;
    // 0x80410550: sll         $t7, $t8, 6
    ctx->r15 = S32(ctx->r24 << 6);
    // 0x80410554: sh          $t7, -0x38($t5)
    MEM_H(-0X38, ctx->r13) = ctx->r15;
    // 0x80410558: lw          $t9, 0x39E0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X39E0);
    // 0x8041055C: sb          $s1, -0x31($t5)
    MEM_B(-0X31, ctx->r13) = ctx->r17;
    // 0x80410560: sb          $s1, -0x32($t5)
    MEM_B(-0X32, ctx->r13) = ctx->r17;
    // 0x80410564: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80410568: sb          $s1, -0x33($t5)
    MEM_B(-0X33, ctx->r13) = ctx->r17;
    // 0x8041056C: sb          $s1, -0x34($t5)
    MEM_B(-0X34, ctx->r13) = ctx->r17;
    // 0x80410570: sh          $zero, -0x2A($t5)
    MEM_H(-0X2A, ctx->r13) = 0;
    // 0x80410574: sh          $zero, -0x2C($t5)
    MEM_H(-0X2C, ctx->r13) = 0;
    // 0x80410578: sh          $zero, -0x2E($t5)
    MEM_H(-0X2E, ctx->r13) = 0;
    // 0x8041057C: sh          $zero, -0x30($t5)
    MEM_H(-0X30, ctx->r13) = 0;
    // 0x80410580: mflo        $t6
    ctx->r14 = lo;
    // 0x80410584: sll         $t8, $t6, 6
    ctx->r24 = S32(ctx->r14 << 6);
    // 0x80410588: sh          $t8, -0x36($t5)
    MEM_H(-0X36, ctx->r13) = ctx->r24;
    // 0x8041058C: lw          $t7, 0x39DC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X39DC);
    // 0x80410590: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80410594: mflo        $t9
    ctx->r25 = lo;
    // 0x80410598: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8041059C: sll         $t8, $t6, 6
    ctx->r24 = S32(ctx->r14 << 6);
    // 0x804105A0: sh          $t8, -0x28($t5)
    MEM_H(-0X28, ctx->r13) = ctx->r24;
    // 0x804105A4: lw          $t7, 0x39E0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X39E0);
    // 0x804105A8: sb          $s1, -0x21($t5)
    MEM_B(-0X21, ctx->r13) = ctx->r17;
    // 0x804105AC: sb          $s1, -0x22($t5)
    MEM_B(-0X22, ctx->r13) = ctx->r17;
    // 0x804105B0: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804105B4: sb          $s1, -0x23($t5)
    MEM_B(-0X23, ctx->r13) = ctx->r17;
    // 0x804105B8: sb          $s1, -0x24($t5)
    MEM_B(-0X24, ctx->r13) = ctx->r17;
    // 0x804105BC: sh          $zero, -0x1A($t5)
    MEM_H(-0X1A, ctx->r13) = 0;
    // 0x804105C0: sh          $zero, -0x1C($t5)
    MEM_H(-0X1C, ctx->r13) = 0;
    // 0x804105C4: sh          $zero, -0x1E($t5)
    MEM_H(-0X1E, ctx->r13) = 0;
    // 0x804105C8: sh          $zero, -0x20($t5)
    MEM_H(-0X20, ctx->r13) = 0;
    // 0x804105CC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x804105D0: mflo        $t9
    ctx->r25 = lo;
    // 0x804105D4: sll         $t6, $t9, 6
    ctx->r14 = S32(ctx->r25 << 6);
    // 0x804105D8: sh          $t6, -0x26($t5)
    MEM_H(-0X26, ctx->r13) = ctx->r14;
    // 0x804105DC: lw          $t8, 0x39DC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X39DC);
    // 0x804105E0: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804105E4: mflo        $t7
    ctx->r15 = lo;
    // 0x804105E8: sll         $t9, $t7, 6
    ctx->r25 = S32(ctx->r15 << 6);
    // 0x804105EC: sh          $t9, -0x18($t5)
    MEM_H(-0X18, ctx->r13) = ctx->r25;
    // 0x804105F0: lw          $t6, 0x39E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39E0);
    // 0x804105F4: sb          $s1, -0x11($t5)
    MEM_B(-0X11, ctx->r13) = ctx->r17;
    // 0x804105F8: sb          $s1, -0x12($t5)
    MEM_B(-0X12, ctx->r13) = ctx->r17;
    // 0x804105FC: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80410600: sb          $s1, -0x13($t5)
    MEM_B(-0X13, ctx->r13) = ctx->r17;
    // 0x80410604: sb          $s1, -0x14($t5)
    MEM_B(-0X14, ctx->r13) = ctx->r17;
    // 0x80410608: mflo        $t8
    ctx->r24 = lo;
    // 0x8041060C: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80410610: sll         $t9, $t7, 6
    ctx->r25 = S32(ctx->r15 << 6);
    // 0x80410614: sh          $t9, -0x16($t5)
    MEM_H(-0X16, ctx->r13) = ctx->r25;
    // 0x80410618: sh          $zero, -0x3A($s0)
    MEM_H(-0X3A, ctx->r16) = 0;
    // 0x8041061C: sh          $zero, -0x3C($s0)
    MEM_H(-0X3C, ctx->r16) = 0;
    // 0x80410620: sh          $zero, -0x3E($s0)
    MEM_H(-0X3E, ctx->r16) = 0;
    // 0x80410624: sh          $zero, -0x40($s0)
    MEM_H(-0X40, ctx->r16) = 0;
    // 0x80410628: lw          $t6, 0x39DC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39DC);
    // 0x8041062C: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80410630: mflo        $t8
    ctx->r24 = lo;
    // 0x80410634: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80410638: sll         $t9, $t7, 6
    ctx->r25 = S32(ctx->r15 << 6);
    // 0x8041063C: sh          $t9, -0x38($s0)
    MEM_H(-0X38, ctx->r16) = ctx->r25;
    // 0x80410640: lw          $t6, 0x39E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X39E0);
    // 0x80410644: sb          $s1, -0x31($s0)
    MEM_B(-0X31, ctx->r16) = ctx->r17;
    // 0x80410648: sb          $s1, -0x32($s0)
    MEM_B(-0X32, ctx->r16) = ctx->r17;
    // 0x8041064C: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80410650: sb          $s1, -0x33($s0)
    MEM_B(-0X33, ctx->r16) = ctx->r17;
    // 0x80410654: sb          $s1, -0x34($s0)
    MEM_B(-0X34, ctx->r16) = ctx->r17;
    // 0x80410658: mflo        $t8
    ctx->r24 = lo;
    // 0x8041065C: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80410660: sll         $t9, $t7, 6
    ctx->r25 = S32(ctx->r15 << 6);
    // 0x80410664: sh          $t9, -0x36($s0)
    MEM_H(-0X36, ctx->r16) = ctx->r25;
    // 0x80410668: lw          $t4, 0x39E8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X39E8);
    // 0x8041066C: sltu        $at, $t2, $t4
    ctx->r1 = ctx->r10 < ctx->r12 ? 1 : 0;
    // 0x80410670: bnel        $at, $zero, L_80410528
    if (ctx->r1 != 0) {
        // 0x80410674: sh          $zero, 0x0($t5)
        MEM_H(0X0, ctx->r13) = 0;
            goto L_80410528;
    }
    goto skip_0;
    // 0x80410674: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
    skip_0:
L_80410678:
    // 0x80410678: lw          $t6, 0x39E4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X39E4);
    // 0x8041067C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80410680: sltu        $at, $a2, $t6
    ctx->r1 = ctx->r6 < ctx->r14 ? 1 : 0;
    // 0x80410684: bne         $at, $zero, L_804104F8
    if (ctx->r1 != 0) {
        // 0x80410688: nop
    
            goto L_804104F8;
    }
    // 0x80410688: nop

L_8041068C:
    // 0x8041068C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80410690: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80410694: jr          $ra
    // 0x80410698: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80410698: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80448A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448A00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80448A04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80448A08: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80448A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448A10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80448A14: bne         $a2, $zero, L_80448A54
    if (ctx->r6 != 0) {
        // 0x80448A18: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80448A54;
    }
    // 0x80448A18: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80448A1C: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80448A20: lw          $v1, 0x7C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7C);
    // 0x80448A24: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80448A28: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80448A2C: bne         $at, $zero, L_80448A94
    if (ctx->r1 != 0) {
        // 0x80448A30: sw          $t7, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->r15;
            goto L_80448A94;
    }
    // 0x80448A30: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x80448A34: jal         0x80446758
    // 0x80448A38: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446758(rdram, ctx);
        goto after_0;
    // 0x80448A38: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80448A3C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448A40: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448A44: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80448A48: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448A4C: b           L_80448A94
    // 0x80448A50: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80448A94;
    // 0x80448A50: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_80448A54:
    // 0x80448A54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80448A58: bnel        $a2, $at, L_80448A84
    if (ctx->r6 != ctx->r1) {
        // 0x80448A5C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80448A84;
    }
    goto skip_0;
    // 0x80448A5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80448A60: jal         0x80446758
    // 0x80448A64: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446758(rdram, ctx);
        goto after_1;
    // 0x80448A64: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80448A68: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448A6C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448A70: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80448A74: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448A78: b           L_80448A94
    // 0x80448A7C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80448A94;
    // 0x80448A7C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80448A80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80448A84:
    // 0x80448A84: bnel        $a2, $at, L_80448A98
    if (ctx->r6 != ctx->r1) {
        // 0x80448A88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448A98;
    }
    goto skip_1;
    // 0x80448A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80448A8C: jal         0x804467BC
    // 0x80448A90: nop

    func_804467BC(rdram, ctx);
        goto after_2;
    // 0x80448A90: nop

    after_2:
L_80448A94:
    // 0x80448A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448A98:
    // 0x80448A98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80448A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448AA0: jr          $ra
    // 0x80448AA4: nop

    return;
    // 0x80448AA4: nop

;}
RECOMP_FUNC void func_8064C298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C29C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C2A0: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064C2A4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064C2A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C2AC: blez        $v0, L_8064C2C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064C2B0: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_8064C2C0;
    }
    // 0x8064C2B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8064C2B4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064C2B8: b           L_8064C2D0
    // 0x8064C2BC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064C2D0;
    // 0x8064C2BC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064C2C0:
    // 0x8064C2C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064C2C4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064C2C8: jal         0x8064C5D8
    // 0x8064C2CC: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    func_8064C5D8(rdram, ctx);
        goto after_0;
    // 0x8064C2CC: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    after_0:
L_8064C2D0:
    // 0x8064C2D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064C2D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C2D8: jr          $ra
    // 0x8064C2DC: nop

    return;
    // 0x8064C2DC: nop

;}
RECOMP_FUNC void func_80679D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80679D20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80679D24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80679D28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80679D2C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80679D30: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(541, 0X2658) << 16);
    // 0x80679D34: lh          $s0, 0x1F0($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X1F0);
    // 0x80679D38: lw          $v0, 0x18($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X18);
    // 0x80679D3C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80679D40: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80679D44: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80679D48: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80679D4C: lw          $t8, -0x3CF8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(541, 0X2658));
    // 0x80679D50: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x80679D54: bne         $s0, $at, L_80679DC0
    if (ctx->r16 != ctx->r1) {
        // 0x80679D58: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_80679DC0;
    }
    // 0x80679D58: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80679D5C: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80679D60: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x80679D64: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80679D68: jal         0x80067D5C
    // 0x80679D6C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x80679D6C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x80679D70: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x80679D74: jal         0x80067F78
    // 0x80679D78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80679D78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80679D7C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80679D80: sll         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2 << 16);
    // 0x80679D84: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80679D88: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80679D8C: beq         $v0, $at, L_80679DFC
    if (ctx->r2 == ctx->r1) {
        // 0x80679D90: sh          $v0, 0x1F0($a3)
        MEM_H(0X1F0, ctx->r7) = ctx->r2;
            goto L_80679DFC;
    }
    // 0x80679D90: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
    // 0x80679D94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80679D98: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80679D9C: jal         0x80067D5C
    // 0x80679DA0: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x80679DA0: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80679DA4: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80679DA8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80679DAC: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x80679DB0: jal         0x80067838
    // 0x80679DB4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x80679DB4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x80679DB8: b           L_80679E00
    // 0x80679DBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80679E00;
    // 0x80679DBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80679DC0:
    // 0x80679DC0: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80679DC4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80679DC8: jal         0x80067930
    // 0x80679DCC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_4;
    // 0x80679DCC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_4:
    // 0x80679DD0: beq         $v0, $zero, L_80679DFC
    if (ctx->r2 == 0) {
        // 0x80679DD4: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_80679DFC;
    }
    // 0x80679DD4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80679DD8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80679DDC: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80679DE0: jal         0x80067D5C
    // 0x80679DE4: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_5;
    // 0x80679DE4: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_5:
    // 0x80679DE8: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x80679DEC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80679DF0: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x80679DF4: jal         0x800678F0
    // 0x80679DF8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x80679DF8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_80679DFC:
    // 0x80679DFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80679E00:
    // 0x80679E00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80679E04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80679E08: jr          $ra
    // 0x80679E0C: nop

    return;
    // 0x80679E0C: nop

;}
