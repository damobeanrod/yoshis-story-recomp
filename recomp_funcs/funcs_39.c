#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80584220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584220: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80584224: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80584228: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8058422C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80584230: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80584234: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80584238: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8058423C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80584240: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80584244: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A388) << 16);
    // 0x80584248: lwc1        $f6, -0x1FB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A388));
    // 0x8058424C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80584250: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A38C) << 16);
    // 0x80584254: lwc1        $f8, -0x1FB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A38C));
    // 0x80584258: addiu       $t7, $zero, 0x1BA8
    ctx->r15 = ADD32(0, 0X1BA8);
    // 0x8058425C: addiu       $t8, $zero, 0x1C20
    ctx->r24 = ADD32(0, 0X1C20);
    // 0x80584260: addiu       $t9, $zero, 0x1EF0
    ctx->r25 = ADD32(0, 0X1EF0);
    // 0x80584264: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80584268: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8058426C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80584270: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80584274: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80584278: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8058427C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80584280: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80584284: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80584288: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8058428C: jal         0x80583E84
    // 0x80584290: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_80583E84(rdram, ctx);
        goto after_0;
    // 0x80584290: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80584294: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80584298: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8058429C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805842A0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805842A4: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x805842A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x805842AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805842B0: jr          $ra
    // 0x805842B4: nop

    return;
    // 0x805842B4: nop

;}
RECOMP_FUNC void func_8057D994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057D994: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8057D998: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8057D99C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057D9A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057D9A4: sw          $zero, 0xC30($v1)
    MEM_W(0XC30, ctx->r3) = 0;
    // 0x8057D9A8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8057D9AC: lui         $t6, 0x8058
    ctx->r14 = S32(RELOC_HI16(390, 0X330) << 16);
    // 0x8057D9B0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8057D9B4: addiu       $t6, $t6, -0x2590
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(390, 0X330));
    // 0x8057D9B8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8057D9BC: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x8057D9C0: addiu       $at, $zero, 0x41FC
    ctx->r1 = ADD32(0, 0X41FC);
    // 0x8057D9C4: bnel        $t8, $at, L_8057D9F0
    if (ctx->r24 != ctx->r1) {
        // 0x8057D9C8: lw          $v0, 0xFB8($v1)
        ctx->r2 = MEM_W(ctx->r3, 0XFB8);
            goto L_8057D9F0;
    }
    goto skip_0;
    // 0x8057D9C8: lw          $v0, 0xFB8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XFB8);
    skip_0:
    // 0x8057D9CC: jal         0x8057D7D0
    // 0x8057D9D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8057D7D0(rdram, ctx);
        goto after_0;
    // 0x8057D9D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057D9D4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8057D9D8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8057D9DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8057D9E0: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x8057D9E4: b           L_8057DA24
    // 0x8057D9E8: sb          $zero, 0x14($v1)
    MEM_B(0X14, ctx->r3) = 0;
        goto L_8057DA24;
    // 0x8057D9E8: sb          $zero, 0x14($v1)
    MEM_B(0X14, ctx->r3) = 0;
    // 0x8057D9EC: lw          $v0, 0xFB8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XFB8);
L_8057D9F0:
    // 0x8057D9F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8057D9F4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8057D9F8: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x8057D9FC: bne         $v0, $zero, L_8057DA18
    if (ctx->r2 != 0) {
        // 0x8057DA00: nop
    
            goto L_8057DA18;
    }
    // 0x8057DA00: nop

    // 0x8057DA04: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8057DA08: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8057DA0C: lw          $v0, -0x71A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X71A8);
    // 0x8057DA10: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8057DA14: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
L_8057DA18:
    // 0x8057DA18: bne         $v1, $v0, L_8057DA24
    if (ctx->r3 != ctx->r2) {
        // 0x8057DA1C: nop
    
            goto L_8057DA24;
    }
    // 0x8057DA1C: nop

    // 0x8057DA20: sh          $v1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r3;
L_8057DA24:
    // 0x8057DA24: jal         0x8057DA4C
    // 0x8057DA28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8057DA4C(rdram, ctx);
        goto after_1;
    // 0x8057DA28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8057DA2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057DA30: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8057DA34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8057DA38: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x8057DA3C: jr          $ra
    // 0x8057DA40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8057DA40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8044580C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044580C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80445810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445814: jal         0x80444408
    // 0x80445818: addiu       $a1, $zero, 0x40F6
    ctx->r5 = ADD32(0, 0X40F6);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x80445818: addiu       $a1, $zero, 0x40F6
    ctx->r5 = ADD32(0, 0X40F6);
    after_0:
    // 0x8044581C: beq         $v0, $zero, L_80445848
    if (ctx->r2 == 0) {
        // 0x80445820: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80445848;
    }
    // 0x80445820: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80445824: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80445828: jal         0x80444408
    // 0x8044582C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80444408(rdram, ctx);
        goto after_1;
    // 0x8044582C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80445830: beq         $v0, $zero, L_80445840
    if (ctx->r2 == 0) {
        // 0x80445834: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80445840;
    }
    // 0x80445834: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80445838: jal         0x8005C9A8
    // 0x8044583C: nop

    func_8005C9A8(rdram, ctx);
        goto after_2;
    // 0x8044583C: nop

    after_2:
L_80445840:
    // 0x80445840: jal         0x800447C8
    // 0x80445844: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x80445844: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_80445848:
    // 0x80445848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044584C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80445850: jr          $ra
    // 0x80445854: nop

    return;
    // 0x80445854: nop

;}
RECOMP_FUNC void func_80050634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050638: bne         $a0, $zero, L_80050658
    if (ctx->r4 != 0) {
        // 0x8005063C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80050658;
    }
    // 0x8005063C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050640: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80050644: addiu       $a0, $a0, 0x9B0
    ctx->r4 = ADD32(ctx->r4, 0X9B0);
    // 0x80050648: jal         0x80071380
    // 0x8005064C: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8005064C: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    after_0:
    // 0x80050650: b           L_80050664
    // 0x80050654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050664;
    // 0x80050654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050658:
    // 0x80050658: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005065C: xor         $v0, $a1, $t6
    ctx->r2 = ctx->r5 ^ ctx->r14;
    // 0x80050660: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80050664:
    // 0x80050664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005066C: jr          $ra
    // 0x80050670: nop

    return;
    // 0x80050670: nop

;}
RECOMP_FUNC void func_805182AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805182AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805182B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805182B4: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x805182B8: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x805182BC: bnel        $t6, $at, L_80518300
    if (ctx->r14 != ctx->r1) {
        // 0x805182C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80518300;
    }
    goto skip_0;
    // 0x805182C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805182C4: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
    // 0x805182C8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805182CC: bne         $t7, $at, L_805182E4
    if (ctx->r15 != ctx->r1) {
        // 0x805182D0: nop
    
            goto L_805182E4;
    }
    // 0x805182D0: nop

    // 0x805182D4: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x805182D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805182DC: beql        $t8, $at, L_80518300
    if (ctx->r24 == ctx->r1) {
        // 0x805182E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80518300;
    }
    goto skip_1;
    // 0x805182E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_805182E4:
    // 0x805182E4: jal         0x80519CD8
    // 0x805182E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80519CD8(rdram, ctx);
        goto after_0;
    // 0x805182E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805182EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805182F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805182F4: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x805182F8: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
    // 0x805182FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80518300:
    // 0x80518300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80518304: jr          $ra
    // 0x80518308: nop

    return;
    // 0x80518308: nop

;}
RECOMP_FUNC void func_80467630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80467630: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80467634: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80467638: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8046763C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80467640: jal         0x80467610
    // 0x80467644: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_80467610(rdram, ctx);
        goto after_0;
    // 0x80467644: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80467648: jal         0x800554F4
    // 0x8046764C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800554F4(rdram, ctx);
        goto after_1;
    // 0x8046764C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x80467650: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80467654: addiu       $a2, $s0, 0x2198
    ctx->r6 = ADD32(ctx->r16, 0X2198);
    // 0x80467658: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    // 0x8046765C: sw          $zero, 0x130($t6)
    MEM_W(0X130, ctx->r14) = 0;
    // 0x80467660: lh          $t7, 0x14($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X14);
    // 0x80467664: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80467668: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8046766C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80467670: addiu       $a1, $s0, 0x1FA4
    ctx->r5 = ADD32(ctx->r16, 0X1FA4);
    // 0x80467674: jal         0x8005558C
    // 0x80467678: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8005558C(rdram, ctx);
        goto after_2;
    // 0x80467678: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x8046767C: sw          $v0, 0x2410($s0)
    MEM_W(0X2410, ctx->r16) = ctx->r2;
    // 0x80467680: lbu         $a2, 0x1B($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1B);
    // 0x80467684: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80467688: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8046768C: blez        $v0, L_804676D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80467690: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_804676D4;
    }
    // 0x80467690: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80467694: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80467698:
    // 0x80467698: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8046769C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x804676A0: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x804676A4: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x804676A8: beq         $at, $zero, L_804676B4
    if (ctx->r1 == 0) {
        // 0x804676AC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_804676B4;
    }
    // 0x804676AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x804676B0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_804676B4:
    // 0x804676B4: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x804676B8: beq         $at, $zero, L_804676C4
    if (ctx->r1 == 0) {
        // 0x804676BC: andi        $t1, $t1, 0xFF
        ctx->r9 = ctx->r9 & 0XFF;
            goto L_804676C4;
    }
    // 0x804676BC: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x804676C0: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
L_804676C4:
    // 0x804676C4: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x804676C8: bne         $at, $zero, L_80467698
    if (ctx->r1 != 0) {
        // 0x804676CC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80467698;
    }
    // 0x804676CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x804676D0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_804676D4:
    // 0x804676D4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x804676D8: sb          $t1, 0x41($sp)
    MEM_B(0X41, ctx->r29) = ctx->r9;
    // 0x804676DC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x804676E0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x804676E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804676E8: jal         0x8004921C
    // 0x804676EC: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x804676EC: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    after_3:
    // 0x804676F0: lh          $t9, 0x1A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A);
    // 0x804676F4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x804676F8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x804676FC: subu        $t3, $t9, $v0
    ctx->r11 = SUB32(ctx->r25, ctx->r2);
    // 0x80467700: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80467704: subu        $t5, $t8, $t4
    ctx->r13 = SUB32(ctx->r24, ctx->r12);
    // 0x80467708: sb          $t5, 0x238C($s0)
    MEM_B(0X238C, ctx->r16) = ctx->r13;
    // 0x8046770C: jal         0x8004921C
    // 0x80467710: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x80467710: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80467714: lh          $t6, 0x1A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A);
    // 0x80467718: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8046771C: lh          $t8, 0x16($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X16);
    // 0x80467720: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80467724: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80467728: subu        $t3, $t0, $t9
    ctx->r11 = SUB32(ctx->r8, ctx->r25);
    // 0x8046772C: sb          $t3, 0x238D($s0)
    MEM_B(0X238D, ctx->r16) = ctx->r11;
    // 0x80467730: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80467734: addiu       $a2, $s0, 0x2608
    ctx->r6 = ADD32(ctx->r16, 0X2608);
    // 0x80467738: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8046773C: sb          $zero, 0x43($sp)
    MEM_B(0X43, ctx->r29) = 0;
    // 0x80467740: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80467744: addiu       $a1, $s0, 0x2414
    ctx->r5 = ADD32(ctx->r16, 0X2414);
    // 0x80467748: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8046774C: jal         0x8005558C
    // 0x80467750: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8005558C(rdram, ctx);
        goto after_5;
    // 0x80467750: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_5:
    // 0x80467754: lbu         $t1, 0x41($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X41);
    // 0x80467758: lbu         $t2, 0x43($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X43);
    // 0x8046775C: sw          $v0, 0x2880($s0)
    MEM_W(0X2880, ctx->r16) = ctx->r2;
    // 0x80467760: lbu         $a2, 0x1B($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1B);
    // 0x80467764: blez        $v0, L_804677A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80467768: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_804677A8;
    }
    // 0x80467768: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8046776C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80467770:
    // 0x80467770: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80467774: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80467778: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x8046777C: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80467780: beq         $at, $zero, L_8046778C
    if (ctx->r1 == 0) {
        // 0x80467784: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8046778C;
    }
    // 0x80467784: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80467788: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_8046778C:
    // 0x8046778C: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80467790: beq         $at, $zero, L_8046779C
    if (ctx->r1 == 0) {
        // 0x80467794: andi        $t1, $t1, 0xFF
        ctx->r9 = ctx->r9 & 0XFF;
            goto L_8046779C;
    }
    // 0x80467794: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x80467798: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
L_8046779C:
    // 0x8046779C: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x804677A0: bne         $at, $zero, L_80467770
    if (ctx->r1 != 0) {
        // 0x804677A4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80467770;
    }
    // 0x804677A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_804677A8:
    // 0x804677A8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x804677AC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x804677B0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x804677B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804677B8: jal         0x8004921C
    // 0x804677BC: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    func_8004921C(rdram, ctx);
        goto after_6;
    // 0x804677BC: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    after_6:
    // 0x804677C0: lh          $t5, 0x1A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1A);
    // 0x804677C4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x804677C8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x804677CC: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x804677D0: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x804677D4: subu        $t9, $t4, $t7
    ctx->r25 = SUB32(ctx->r12, ctx->r15);
    // 0x804677D8: sb          $t9, 0x27FC($s0)
    MEM_B(0X27FC, ctx->r16) = ctx->r25;
    // 0x804677DC: jal         0x8004921C
    // 0x804677E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_7;
    // 0x804677E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x804677E4: lh          $t3, 0x1A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X1A);
    // 0x804677E8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x804677EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804677F0: subu        $t8, $t3, $v0
    ctx->r24 = SUB32(ctx->r11, ctx->r2);
    // 0x804677F4: sra         $t5, $t8, 1
    ctx->r13 = S32(SIGNED(ctx->r24) >> 1);
    // 0x804677F8: subu        $t6, $t0, $t5
    ctx->r14 = SUB32(ctx->r8, ctx->r13);
    // 0x804677FC: sb          $t6, 0x27FD($s0)
    MEM_B(0X27FD, ctx->r16) = ctx->r14;
    // 0x80467800: sw          $zero, 0x2CF8($s0)
    MEM_W(0X2CF8, ctx->r16) = 0;
    // 0x80467804: swc1        $f4, 0x2CF4($s0)
    MEM_W(0X2CF4, ctx->r16) = ctx->f4.u32l;
    // 0x80467808: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8046780C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80467810: jal         0x804686B4
    // 0x80467814: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804686B4(rdram, ctx);
        goto after_8;
    // 0x80467814: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80467818: jal         0x80466950
    // 0x8046781C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80466950(rdram, ctx);
        goto after_9;
    // 0x8046781C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_9:
    // 0x80467820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80467824: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80467828: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8046782C: jr          $ra
    // 0x80467830: nop

    return;
    // 0x80467830: nop

;}
RECOMP_FUNC void func_804249A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804249A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804249A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804249A8: jal         0x804233F4
    // 0x804249AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804233F4(rdram, ctx);
        goto after_0;
    // 0x804249AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804249B0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x804249B4: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x804249B8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x804249BC: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x804249C0: addiu       $t7, $v0, 0x90
    ctx->r15 = ADD32(ctx->r2, 0X90);
    // 0x804249C4: addiu       $t8, $v0, 0x9C
    ctx->r24 = ADD32(ctx->r2, 0X9C);
    // 0x804249C8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x804249CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x804249D0: addiu       $a1, $v0, 0xA0
    ctx->r5 = ADD32(ctx->r2, 0XA0);
    // 0x804249D4: jal         0x80424690
    // 0x804249D8: addiu       $a3, $v0, 0x28
    ctx->r7 = ADD32(ctx->r2, 0X28);
    func_80424690(rdram, ctx);
        goto after_1;
    // 0x804249D8: addiu       $a3, $v0, 0x28
    ctx->r7 = ADD32(ctx->r2, 0X28);
    after_1:
    // 0x804249DC: jal         0x804235A8
    // 0x804249E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804235A8(rdram, ctx);
        goto after_2;
    // 0x804249E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x804249E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804249E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804249EC: jr          $ra
    // 0x804249F0: nop

    return;
    // 0x804249F0: nop

;}
RECOMP_FUNC void func_8051F81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F81C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8051F820: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8051F824: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8051F828: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8051F82C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8051F830: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8051F834: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x8051F838: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8051F83C: lui         $a0, 0x8052
    ctx->r4 = S32(RELOC_HI16(303, 0XA30) << 16);
    // 0x8051F840: slti        $at, $t7, 0x96
    ctx->r1 = SIGNED(ctx->r15) < 0X96 ? 1 : 0;
    // 0x8051F844: bne         $at, $zero, L_8051F854
    if (ctx->r1 != 0) {
        // 0x8051F848: addiu       $a0, $a0, -0x550
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(303, 0XA30));
            goto L_8051F854;
    }
    // 0x8051F848: addiu       $a0, $a0, -0x550
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(303, 0XA30));
    // 0x8051F84C: b           L_8051F934
    // 0x8051F850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8051F934;
    // 0x8051F850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8051F854:
    // 0x8051F854: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8051F858: lui         $a1, 0x4012
    ctx->r5 = S32(0X4012 << 16);
    // 0x8051F85C: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x8051F860: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x8051F864: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8051F868: jal         0x80046804
    // 0x8051F86C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x8051F86C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8051F870: bne         $v0, $zero, L_8051F880
    if (ctx->r2 != 0) {
        // 0x8051F874: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8051F880;
    }
    // 0x8051F874: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8051F878: b           L_8051F934
    // 0x8051F87C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8051F934;
    // 0x8051F87C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8051F880:
    // 0x8051F880: jal         0x80047090
    // 0x8051F884: addiu       $a0, $zero, 0x4012
    ctx->r4 = ADD32(0, 0X4012);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x8051F884: addiu       $a0, $zero, 0x4012
    ctx->r4 = ADD32(0, 0X4012);
    after_1:
    // 0x8051F888: lhu         $t0, 0xE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XE);
    // 0x8051F88C: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x8051F890: addiu       $a2, $s0, 0xC4
    ctx->r6 = ADD32(ctx->r16, 0XC4);
    // 0x8051F894: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x8051F898: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8051F89C: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    // 0x8051F8A0: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8051F8A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8051F8A8: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x8051F8AC: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8051F8B0: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x8051F8B4: jal         0x80048378
    // 0x8051F8B8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80048378(rdram, ctx);
        goto after_2;
    // 0x8051F8B8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x8051F8BC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8051F8C0: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8051F8C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8051F8C8: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x8051F8CC: lwc1        $f16, 0x1C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8051F8D0: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8051F8D4: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8051F8D8: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8051F8DC: swc1        $f18, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f18.u32l;
    // 0x8051F8E0: lwc1        $f4, 0x24($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8051F8E4: swc1        $f0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f0.u32l;
    // 0x8051F8E8: swc1        $f4, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f4.u32l;
    // 0x8051F8EC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8051F8F0: jal         0x8051F4F4
    // 0x8051F8F4: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    func_8051F4F4(rdram, ctx);
        goto after_3;
    // 0x8051F8F4: lw          $a0, 0x16C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X16C);
    after_3:
    // 0x8051F8F8: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x8051F8FC: bne         $a0, $zero, L_8051F920
    if (ctx->r4 != 0) {
        // 0x8051F900: nop
    
            goto L_8051F920;
    }
    // 0x8051F900: nop

    // 0x8051F904: jal         0x8051F708
    // 0x8051F908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051F708(rdram, ctx);
        goto after_4;
    // 0x8051F908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8051F90C: lui         $t3, 0x8052
    ctx->r11 = S32(RELOC_HI16(303, 0X6C0) << 16);
    // 0x8051F910: addiu       $t3, $t3, -0x8C0
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(303, 0X6C0));
    // 0x8051F914: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8051F918: sw          $t3, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r11;
    // 0x8051F91C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8051F920:
    // 0x8051F920: jal         0x8051F760
    // 0x8051F924: nop

    func_8051F760(rdram, ctx);
        goto after_5;
    // 0x8051F924: nop

    after_5:
    // 0x8051F928: jal         0x80044194
    // 0x8051F92C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_6;
    // 0x8051F92C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8051F930: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8051F934:
    // 0x8051F934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8051F938: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8051F93C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8051F940: jr          $ra
    // 0x8051F944: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8051F944: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8051F948: nop

    // 0x8051F94C: nop

;}
RECOMP_FUNC void func_8042D324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042D324: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8042D328: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(50, 0X2928) << 16);
    // 0x8042D32C: addiu       $t6, $t6, -0x2E38
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(50, 0X2928));
    // 0x8042D330: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8042D334: jr          $ra
    // 0x8042D338: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8042D338: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80534920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534920: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80534924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80534928: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8053492C: lwc1        $f4, 0xDC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80534930: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80534934: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80534938: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8053493C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80534940: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80534944: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80534948: bc1fl       L_80534964
    if (!c1cs) {
        // 0x8053494C: lhu         $t6, 0xE($v1)
        ctx->r14 = MEM_HU(ctx->r3, 0XE);
            goto L_80534964;
    }
    goto skip_0;
    // 0x8053494C: lhu         $t6, 0xE($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XE);
    skip_0:
    // 0x80534950: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80534954: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80534958: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8053495C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80534960: lhu         $t6, 0xE($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XE);
L_80534964:
    // 0x80534964: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80534968: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8053496C: beq         $t7, $zero, L_80534980
    if (ctx->r15 == 0) {
        // 0x80534970: nop
    
            goto L_80534980;
    }
    // 0x80534970: nop

    // 0x80534974: jal         0x805350A0
    // 0x80534978: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_805350A0(rdram, ctx);
        goto after_0;
    // 0x80534978: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8053497C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80534980:
    // 0x80534980: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(348, 0X1088) << 16);
    // 0x80534984: lwc1        $f4, 0x5698($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(348, 0X1088));
    // 0x80534988: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8053498C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80534990: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80534994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80534998: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8053499C: jr          $ra
    // 0x805349A0: nop

    return;
    // 0x805349A0: nop

;}
RECOMP_FUNC void func_80532074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532074: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80532078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8053207C: jal         0x8004700C
    // 0x80532080: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80532080: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80532084: beq         $v0, $zero, L_805320F4
    if (ctx->r2 == 0) {
        // 0x80532088: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_805320F4;
    }
    // 0x80532088: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8053208C: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x80532090: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80532094: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80532098: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8053209C: lw          $a0, 0x1F4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1F4);
    // 0x805320A0: lui         $a3, 0xBE4C
    ctx->r7 = S32(0XBE4C << 16);
    // 0x805320A4: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x805320A8: lwc1        $f10, 0x268($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X268);
    // 0x805320AC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x805320B0: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x805320B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805320B8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805320BC: jal         0x80531A90
    // 0x805320C0: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_80531A90(rdram, ctx);
        goto after_1;
    // 0x805320C0: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x805320C4: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x805320C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805320CC: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x805320D0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x805320D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805320D8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x805320DC: nop

    // 0x805320E0: bc1f        L_805320F4
    if (!c1cs) {
        // 0x805320E4: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_805320F4;
    }
    // 0x805320E4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x805320E8: sw          $t9, 0x1E0($t0)
    MEM_W(0X1E0, ctx->r8) = ctx->r25;
    // 0x805320EC: jal         0x805323E8
    // 0x805320F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_805323E8(rdram, ctx);
        goto after_2;
    // 0x805320F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_805320F4:
    // 0x805320F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805320F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805320FC: jr          $ra
    // 0x80532100: nop

    return;
    // 0x80532100: nop

;}
RECOMP_FUNC void func_804B8B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8B54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804B8B58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B8B5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B8B60: jal         0x804B8B10
    // 0x804B8B64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804B8B10(rdram, ctx);
        goto after_0;
    // 0x804B8B64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804B8B68: bne         $v0, $zero, L_804B8B80
    if (ctx->r2 != 0) {
        // 0x804B8B6C: lui         $t6, 0x804C
        ctx->r14 = S32(RELOC_HI16(185, 0X854) << 16);
            goto L_804B8B80;
    }
    // 0x804B8B6C: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(185, 0X854) << 16);
    // 0x804B8B70: jal         0x800445A4
    // 0x804B8B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804B8B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804B8B78: b           L_804B8BF0
    // 0x804B8B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804B8BF0;
    // 0x804B8B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B8B80:
    // 0x804B8B80: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x804B8B84: addiu       $t6, $t6, -0x798C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(185, 0X854));
    // 0x804B8B88: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x804B8B8C: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x804B8B90: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x804B8B94: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x804B8B98: lui         $t9, 0x804C
    ctx->r25 = S32(RELOC_HI16(185, 0X2994) << 16);
    // 0x804B8B9C: sw          $t8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r24;
    // 0x804B8BA0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804B8BA4: addiu       $t9, $t9, -0x584C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(185, 0X2994));
    // 0x804B8BA8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x804B8BAC: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804B8BB0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804B8BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B8BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B8BBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804B8BC0: jal         0x804B8C00
    // 0x804B8BC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B8C00(rdram, ctx);
        goto after_2;
    // 0x804B8BC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804B8BC8: jal         0x804B87CC
    // 0x804B8BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B87CC(rdram, ctx);
        goto after_3;
    // 0x804B8BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804B8BD0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x804B8BD4: sh          $t1, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r9;
    // 0x804B8BD8: jal         0x804B7F14
    // 0x804B8BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7F14(rdram, ctx);
        goto after_4;
    // 0x804B8BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804B8BE0: lui         $t2, 0x804B
    ctx->r10 = S32(RELOC_HI16(185, 0X194) << 16);
    // 0x804B8BE4: addiu       $t2, $t2, 0x7FB4
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(185, 0X194));
    // 0x804B8BE8: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x804B8BEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B8BF0:
    // 0x804B8BF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B8BF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804B8BF8: jr          $ra
    // 0x804B8BFC: nop

    return;
    // 0x804B8BFC: nop

;}
RECOMP_FUNC void func_8064E194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E194: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064E198: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064E19C: lui         $t0, 0x8065
    ctx->r8 = S32(RELOC_HI16(498, 0XB50) << 16);
    // 0x8064E1A0: beq         $v1, $zero, L_8064E1B0
    if (ctx->r3 == 0) {
        // 0x8064E1A4: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8064E1B0;
    }
    // 0x8064E1A4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8064E1A8: jr          $ra
    // 0x8064E1AC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    return;
    // 0x8064E1AC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064E1B0:
    // 0x8064E1B0: sw          $a1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r5;
    // 0x8064E1B4: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x8064E1B8: addiu       $v1, $t7, 0x1
    ctx->r3 = ADD32(ctx->r15, 0X1);
    // 0x8064E1BC: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8064E1C0: bne         $at, $zero, L_8064E1D0
    if (ctx->r1 != 0) {
        // 0x8064E1C4: sw          $v1, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->r3;
            goto L_8064E1D0;
    }
    // 0x8064E1C4: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x8064E1C8: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x8064E1CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8064E1D0:
    // 0x8064E1D0: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8064E1D4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8064E1D8: lh          $t0, -0x17E0($t0)
    ctx->r8 = MEM_H(ctx->r8, (int16_t)RELOC_LO16(498, 0XB50));
    // 0x8064E1DC: sh          $t0, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r8;
    // 0x8064E1E0: jr          $ra
    // 0x8064E1E4: nop

    return;
    // 0x8064E1E4: nop

;}
RECOMP_FUNC void func_804269B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804269B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804269B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804269B8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x804269BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804269C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804269C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804269C8: jal         0x80064E84
    // 0x804269CC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x804269CC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x804269D0: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x804269D4: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x804269D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_804269DC:
    // 0x804269DC: jal         0x80064E84
    // 0x804269E0: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x804269E0: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    after_1:
    // 0x804269E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x804269E8: bne         $s0, $s2, L_804269DC
    if (ctx->r16 != ctx->r18) {
        // 0x804269EC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_804269DC;
    }
    // 0x804269EC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x804269F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804269F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804269F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804269FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80426A00: jr          $ra
    // 0x80426A04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80426A04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8051B5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051B5F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051B5F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051B5FC: jal         0x8051B3BC
    // 0x8051B600: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8051B3BC(rdram, ctx);
        goto after_0;
    // 0x8051B600: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051B604: bnel        $v0, $zero, L_8051B624
    if (ctx->r2 != 0) {
        // 0x8051B608: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8051B624;
    }
    goto skip_0;
    // 0x8051B608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8051B60C: jal         0x80044658
    // 0x8051B610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80044658(rdram, ctx);
        goto after_1;
    // 0x8051B610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8051B614: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8051B618: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8051B61C: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x8051B620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051B624:
    // 0x8051B624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051B628: jr          $ra
    // 0x8051B62C: nop

    return;
    // 0x8051B62C: nop

;}
RECOMP_FUNC void func_804D641C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D641C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D6420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D6424: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x804D6428: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x804D642C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804D6430: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x804D6434: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(252, 0X574) << 16);
    // 0x804D6438: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804D643C: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x804D6440: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804D6444: addiu       $t8, $t8, 0x6874
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(252, 0X574));
    // 0x804D6448: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804D644C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804D6450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804D6454: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804D6458: jal         0x804D6620
    // 0x804D645C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804D6620(rdram, ctx);
        goto after_0;
    // 0x804D645C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804D6460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D6464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D6468: jr          $ra
    // 0x804D646C: nop

    return;
    // 0x804D646C: nop

;}
RECOMP_FUNC void func_805636D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805636D0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805636D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805636D8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x805636DC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805636E0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805636E4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805636E8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805636EC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805636F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805636F4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805636F8: lui         $t1, 0x8056
    ctx->r9 = S32(RELOC_HI16(366, 0X22F0) << 16);
    // 0x805636FC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80563700: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80563704: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80563708: lw          $t1, 0x3740($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(366, 0X22F0));
    // 0x8056370C: jr          $ra
    // 0x80563710: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80563710: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x80563714: nop

    // 0x80563718: nop

    // 0x8056371C: nop

;}
RECOMP_FUNC void func_806A2860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A2860: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A2864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A2868: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806A286C: addiu       $at, $zero, 0x4716
    ctx->r1 = ADD32(0, 0X4716);
    // 0x806A2870: beq         $v0, $at, L_806A2880
    if (ctx->r2 == ctx->r1) {
        // 0x806A2874: addiu       $at, $zero, 0x4717
        ctx->r1 = ADD32(0, 0X4717);
            goto L_806A2880;
    }
    // 0x806A2874: addiu       $at, $zero, 0x4717
    ctx->r1 = ADD32(0, 0X4717);
    // 0x806A2878: bne         $v0, $at, L_806A288C
    if (ctx->r2 != ctx->r1) {
        // 0x806A287C: lui         $a0, 0x806A
        ctx->r4 = S32(RELOC_HI16(583, 0X650) << 16);
            goto L_806A288C;
    }
    // 0x806A287C: lui         $a0, 0x806A
    ctx->r4 = S32(RELOC_HI16(583, 0X650) << 16);
L_806A2880:
    // 0x806A2880: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(583, 0X3E4) << 16);
    // 0x806A2884: b           L_806A28C0
    // 0x806A2888: addiu       $v0, $v0, 0x2C44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(583, 0X3E4));
        goto L_806A28C0;
    // 0x806A2888: addiu       $v0, $v0, 0x2C44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(583, 0X3E4));
L_806A288C:
    // 0x806A288C: lui         $a1, 0x806A
    ctx->r5 = S32(RELOC_HI16(583, 0X660) << 16);
    // 0x806A2890: addiu       $a1, $a1, 0x2EC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(583, 0X660));
    // 0x806A2894: addiu       $a0, $a0, 0x2EB0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(583, 0X650));
    // 0x806A2898: jal         0x8004667C
    // 0x806A289C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x806A289C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_0:
    // 0x806A28A0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x806A28A4: lui         $a2, 0x806A
    ctx->r6 = S32(RELOC_HI16(583, 0X450) << 16);
    // 0x806A28A8: addiu       $a2, $a2, 0x2CB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(583, 0X450));
    // 0x806A28AC: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x806A28B0: jal         0x80057B28
    // 0x806A28B4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x806A28B4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_1:
    // 0x806A28B8: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(583, 0X2F0) << 16);
    // 0x806A28BC: addiu       $v0, $v0, 0x2B50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(583, 0X2F0));
L_806A28C0:
    // 0x806A28C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A28C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806A28C8: jr          $ra
    // 0x806A28CC: nop

    return;
    // 0x806A28CC: nop

;}
RECOMP_FUNC void func_8005A52C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A52C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A534: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005A538: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005A53C: lwc1        $f4, 0x9C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x8005A540: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005A544: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005A548: jal         0x8006586C
    // 0x8005A54C: nop

    func_8006586C(rdram, ctx);
        goto after_0;
    // 0x8005A54C: nop

    after_0:
    // 0x8005A550: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8005A554: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005A558: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005A55C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A560: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005A564: lwc1        $f10, 0xA0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x8005A568: mul.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8005A56C: jal         0x8006586C
    // 0x8005A570: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    func_8006586C(rdram, ctx);
        goto after_1;
    // 0x8005A570: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8005A574: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005A578: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8005A57C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005A580: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8005A584: lwc1        $f8, 0x34($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8005A588: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8005A58C: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x8005A590: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8005A594: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x8005A598: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8005A59C: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
    // 0x8005A5A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005A5A4: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005A5A8: lwc1        $f10, 0xA0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x8005A5AC: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8005A5B0: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8005A5B4: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8005A5B8: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8005A5BC: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005A5C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005A5C4: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8005A5C8: sb          $zero, 0xA9($a0)
    MEM_B(0XA9, ctx->r4) = 0;
    // 0x8005A5CC: sw          $t7, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->r15;
    // 0x8005A5D0: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8005A5D4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8005A5D8: lwc1        $f8, 0x9C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x8005A5DC: swc1        $f14, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f14.u32l;
    // 0x8005A5E0: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x8005A5E4: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8005A5E8: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005A5EC: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
    // 0x8005A5F0: add.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8005A5F4: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x8005A5F8: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x8005A5FC: add.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8005A600: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x8005A604: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x8005A608: add.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x8005A60C: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8005A610: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8005A614: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8005A618: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
    // 0x8005A61C: lwc1        $f8, 0x34($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8005A620: lwc1        $f10, 0x7C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8005A624: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8005A628: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8005A62C: swc1        $f2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f2.u32l;
    // 0x8005A630: swc1        $f2, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f2.u32l;
    // 0x8005A634: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005A638: swc1        $f6, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f6.u32l;
    // 0x8005A63C: sw          $t9, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r25;
    // 0x8005A640: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8005A644: swc1        $f4, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->f4.u32l;
    // 0x8005A648: lwc1        $f12, 0xBE4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0XBE4);
    // 0x8005A64C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005A650: lwc1        $f2, 0xBE8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XBE8);
    // 0x8005A654: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005A658: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8005A65C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_8005A660:
    // 0x8005A660: lwc1        $f0, 0xAC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XAC);
    // 0x8005A664: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005A668: nop

    // 0x8005A66C: bc1tl       L_8005A690
    if (c1cs) {
        // 0x8005A670: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8005A690;
    }
    goto skip_0;
    // 0x8005A670: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x8005A674: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8005A678: nop

    // 0x8005A67C: bc1tl       L_8005A690
    if (c1cs) {
        // 0x8005A680: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8005A690;
    }
    goto skip_1;
    // 0x8005A680: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x8005A684: b           L_8005A6C8
    // 0x8005A688: swc1        $f14, 0xAC($a1)
    MEM_W(0XAC, ctx->r5) = ctx->f14.u32l;
        goto L_8005A6C8;
    // 0x8005A688: swc1        $f14, 0xAC($a1)
    MEM_W(0XAC, ctx->r5) = ctx->f14.u32l;
    // 0x8005A68C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8005A690:
    // 0x8005A690: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8005A694: addiu       $t1, $t1, 0x6140
    ctx->r9 = ADD32(ctx->r9, 0X6140);
    // 0x8005A698: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x8005A69C: bc1f        L_8005A6B8
    if (!c1cs) {
        // 0x8005A6A0: addu        $v0, $t0, $t1
        ctx->r2 = ADD32(ctx->r8, ctx->r9);
            goto L_8005A6B8;
    }
    // 0x8005A6A0: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8005A6A4: lbu         $t2, 0xA9($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XA9);
    // 0x8005A6A8: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x8005A6AC: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x8005A6B0: b           L_8005A6C8
    // 0x8005A6B4: sb          $t4, 0xA9($a0)
    MEM_B(0XA9, ctx->r4) = ctx->r12;
        goto L_8005A6C8;
    // 0x8005A6B4: sb          $t4, 0xA9($a0)
    MEM_B(0XA9, ctx->r4) = ctx->r12;
L_8005A6B8:
    // 0x8005A6B8: lbu         $t5, 0xA9($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XA9);
    // 0x8005A6BC: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8005A6C0: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8005A6C4: sb          $t7, 0xA9($a0)
    MEM_B(0XA9, ctx->r4) = ctx->r15;
L_8005A6C8:
    // 0x8005A6C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005A6CC: bne         $v1, $a2, L_8005A660
    if (ctx->r3 != ctx->r6) {
        // 0x8005A6D0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8005A660;
    }
    // 0x8005A6D0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8005A6D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A6D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A6DC: jr          $ra
    // 0x8005A6E0: nop

    return;
    // 0x8005A6E0: nop

;}
RECOMP_FUNC void func_8066DEB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066DEB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066DEBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066DEC0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066DEC4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8066DEC8: lw          $v1, 0x1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C);
    // 0x8066DECC: beq         $v1, $zero, L_8066DEDC
    if (ctx->r3 == 0) {
        // 0x8066DED0: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8066DEDC;
    }
    // 0x8066DED0: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8066DED4: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x8066DED8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8066DEDC:
    // 0x8066DEDC: bnel        $v1, $zero, L_8066DF58
    if (ctx->r3 != 0) {
        // 0x8066DEE0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8066DF58;
    }
    goto skip_0;
    // 0x8066DEE0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x8066DEE4: lw          $a1, 0x138($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X138);
    // 0x8066DEE8: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x8066DEEC: lui         $t9, 0x8067
    ctx->r25 = S32(RELOC_HI16(517, 0X2910) << 16);
    // 0x8066DEF0: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8066DEF4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8066DEF8: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x8066DEFC: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8066DF00: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8066DF04: lw          $t9, -0x130($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(517, 0X2910));
    // 0x8066DF08: lui         $t0, 0x8067
    ctx->r8 = S32(RELOC_HI16(517, 0X28D0) << 16);
    // 0x8066DF0C: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8066DF10: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x8066DF14: lw          $t0, -0x170($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(517, 0X28D0));
    // 0x8066DF18: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x8066DF1C: sw          $t1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r9;
    // 0x8066DF20: bne         $t0, $zero, L_8066DF54
    if (ctx->r8 != 0) {
        // 0x8066DF24: sw          $t0, 0x28($v0)
        MEM_W(0X28, ctx->r2) = ctx->r8;
            goto L_8066DF54;
    }
    // 0x8066DF24: sw          $t0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r8;
    // 0x8066DF28: lw          $t3, 0x138($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X138);
    // 0x8066DF2C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8066DF30: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8066DF34: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x8066DF38: sw          $t5, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->r13;
    // 0x8066DF3C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x8066DF40: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8066DF44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066DF48: jal         0x8066E4C8
    // 0x8066DF4C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8066E4C8(rdram, ctx);
        goto after_0;
    // 0x8066DF4C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8066DF50: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8066DF54:
    // 0x8066DF54: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8066DF58:
    // 0x8066DF58: jal         0x8066DB84
    // 0x8066DF5C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8066DB84(rdram, ctx);
        goto after_1;
    // 0x8066DF5C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x8066DF60: jal         0x8066D8D8
    // 0x8066DF64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8066D8D8(rdram, ctx);
        goto after_2;
    // 0x8066DF64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8066DF68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066DF6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066DF70: jr          $ra
    // 0x8066DF74: nop

    return;
    // 0x8066DF74: nop

;}
RECOMP_FUNC void func_804368F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804368F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804368F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804368FC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80436900: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80436904: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80436908: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(77, 0X1EBC) << 16);
    // 0x8043690C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80436910: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80436914: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80436918: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8043691C: lw          $t8, -0x78A4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(77, 0X1EBC));
    // 0x80436920: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80436924: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80436928: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043692C: jal         0x80048490
    // 0x80436930: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80436930: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80436934: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80436938: jal         0x80048378
    // 0x8043693C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8043693C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80436940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80436944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80436948: jr          $ra
    // 0x8043694C: nop

    return;
    // 0x8043694C: nop

;}
RECOMP_FUNC void func_800271C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800271C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800271C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800271CC: jal         0x80024748
    // 0x800271D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x800271D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800271D4: beq         $v0, $zero, L_8002724C
    if (ctx->r2 == 0) {
        // 0x800271D8: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_8002724C;
    }
    // 0x800271D8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800271DC: lw          $v1, 0x1F4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X1F4);
    // 0x800271E0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800271E4: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x800271E8: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x800271EC: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800271F0: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800271F4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800271F8: bne         $v0, $zero, L_8002721C
    if (ctx->r2 != 0) {
        // 0x800271FC: sw          $v0, 0x4C($v1)
        MEM_W(0X4C, ctx->r3) = ctx->r2;
            goto L_8002721C;
    }
    // 0x800271FC: sw          $v0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r2;
    // 0x80027200: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80027204: addiu       $t8, $t8, 0x4778
    ctx->r24 = ADD32(ctx->r24, 0X4778);
    // 0x80027208: sw          $t6, 0x14C($a3)
    MEM_W(0X14C, ctx->r7) = ctx->r14;
    // 0x8002720C: sb          $t7, 0x158($a3)
    MEM_B(0X158, ctx->r7) = ctx->r15;
    // 0x80027210: sw          $t8, 0x160($a3)
    MEM_W(0X160, ctx->r7) = ctx->r24;
    // 0x80027214: b           L_8002724C
    // 0x80027218: sw          $zero, 0x154($a3)
    MEM_W(0X154, ctx->r7) = 0;
        goto L_8002724C;
    // 0x80027218: sw          $zero, 0x154($a3)
    MEM_W(0X154, ctx->r7) = 0;
L_8002721C:
    // 0x8002721C: sw          $t9, 0x14C($a3)
    MEM_W(0X14C, ctx->r7) = ctx->r25;
    // 0x80027220: sb          $t0, 0x158($a3)
    MEM_B(0X158, ctx->r7) = ctx->r8;
    // 0x80027224: jal         0x8001D770
    // 0x80027228: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80027228: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x8002722C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80027230: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80027234: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80027238: jal         0x80067BF8
    // 0x8002723C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x8002723C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80027240: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80027244: jal         0x80067818
    // 0x80027248: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80027248: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_8002724C:
    // 0x8002724C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80027258: jr          $ra
    // 0x8002725C: nop

    return;
    // 0x8002725C: nop

;}
RECOMP_FUNC void func_800301F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800301F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800301F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800301FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80030200: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80030204: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80030208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003020C: jal         0x80030194
    // 0x80030210: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80030194(rdram, ctx);
        goto after_0;
    // 0x80030210: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80030214: beql        $v0, $zero, L_800302F0
    if (ctx->r2 == 0) {
        // 0x80030218: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800302F0;
    }
    goto skip_0;
    // 0x80030218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8003021C: jal         0x800433D0
    // 0x80030220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800433D0(rdram, ctx);
        goto after_1;
    // 0x80030220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80030224: jal         0x80030104
    // 0x80030228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80030104(rdram, ctx);
        goto after_2;
    // 0x80030228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003022C: jal         0x80041D3C
    // 0x80030230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041D3C(rdram, ctx);
        goto after_3;
    // 0x80030230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80030234: jal         0x80041450
    // 0x80030238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041450(rdram, ctx);
        goto after_4;
    // 0x80030238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8003023C: jal         0x80036924
    // 0x80030240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80036924(rdram, ctx);
        goto after_5;
    // 0x80030240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80030244: jal         0x80021A44
    // 0x80030248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021A44(rdram, ctx);
        goto after_6;
    // 0x80030248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8003024C: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x80030250: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x80030254: beql        $t7, $zero, L_80030288
    if (ctx->r15 == 0) {
        // 0x80030258: lw          $t9, 0x174($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X174);
            goto L_80030288;
    }
    goto skip_1;
    // 0x80030258: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    skip_1:
    // 0x8003025C: lbu         $t8, 0xF4($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0XF4);
    // 0x80030260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80030264: beql        $t8, $zero, L_80030288
    if (ctx->r24 == 0) {
        // 0x80030268: lw          $t9, 0x174($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X174);
            goto L_80030288;
    }
    goto skip_2;
    // 0x80030268: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    skip_2:
    // 0x8003026C: jal         0x8002E274
    // 0x80030270: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002E274(rdram, ctx);
        goto after_7;
    // 0x80030270: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80030274: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80030278: lwc1        $f4, 0x68($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8003027C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80030280: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x80030284: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
L_80030288:
    // 0x80030288: lbu         $t0, 0x12($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X12);
    // 0x8003028C: beq         $t0, $zero, L_800302A4
    if (ctx->r8 == 0) {
        // 0x80030290: nop
    
            goto L_800302A4;
    }
    // 0x80030290: nop

    // 0x80030294: jal         0x800232A4
    // 0x80030298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800232A4(rdram, ctx);
        goto after_8;
    // 0x80030298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8003029C: b           L_800302B0
    // 0x800302A0: lw          $t9, 0xAC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XAC);
        goto L_800302B0;
    // 0x800302A0: lw          $t9, 0xAC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XAC);
L_800302A4:
    // 0x800302A4: jal         0x800231AC
    // 0x800302A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800231AC(rdram, ctx);
        goto after_9;
    // 0x800302A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800302AC: lw          $t9, 0xAC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XAC);
L_800302B0:
    // 0x800302B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800302B4: jalr        $t9
    // 0x800302B8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x800302B8: nop

    after_10:
    // 0x800302BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800302C0: jal         0x80030120
    // 0x800302C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80030120(rdram, ctx);
        goto after_11;
    // 0x800302C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x800302C8: beql        $v0, $zero, L_800302F0
    if (ctx->r2 == 0) {
        // 0x800302CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800302F0;
    }
    goto skip_3;
    // 0x800302CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800302D0: jal         0x80028220
    // 0x800302D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_12;
    // 0x800302D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800302D8: sw          $v0, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r2;
    // 0x800302DC: jal         0x8003635C
    // 0x800302E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003635C(rdram, ctx);
        goto after_13;
    // 0x800302E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800302E4: jal         0x80023EA0
    // 0x800302E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80023EA0(rdram, ctx);
        goto after_14;
    // 0x800302E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800302EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800302F0:
    // 0x800302F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800302F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800302F8: jr          $ra
    // 0x800302FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800302FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_805AC4B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC4B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AC4BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC4C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805AC4C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805AC4C8: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805AC4CC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC4D0: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805AC4D4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x805AC4D8: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x805AC4DC: bc1fl       L_805AC51C
    if (!c1cs) {
        // 0x805AC4E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AC51C;
    }
    goto skip_0;
    // 0x805AC4E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805AC4E4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x805AC4E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x805AC4EC: jal         0x8004D1F0
    // 0x805AC4F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x805AC4F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AC4F4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC4F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805AC4FC: addiu       $a2, $a2, -0x2B90
    ctx->r6 = ADD32(ctx->r6, -0X2B90);
    // 0x805AC500: jal         0x8004D698
    // 0x805AC504: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x805AC504: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x805AC508: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805AC50C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x805AC510: ori         $t7, $t6, 0xF000
    ctx->r15 = ctx->r14 | 0XF000;
    // 0x805AC514: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x805AC518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AC51C:
    // 0x805AC51C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805AC520: jr          $ra
    // 0x805AC524: nop

    return;
    // 0x805AC524: nop

;}
RECOMP_FUNC void func_804BE250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BE250: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BE254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BE258: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804BE25C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804BE260: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x804BE264: lw          $t8, 0x1F4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1F4);
    // 0x804BE268: lw          $a1, 0x370($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X370);
    // 0x804BE26C: jal         0x8004700C
    // 0x804BE270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804BE270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x804BE274: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x804BE278: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x804BE27C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804BE280: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BE284: lwc1        $f4, 0x50($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X50);
    // 0x804BE288: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x804BE28C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804BE290: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804BE294: swc1        $f8, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f8.u32l;
    // 0x804BE298: lwc1        $f16, 0x50($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X50);
    // 0x804BE29C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x804BE2A0: nop

    // 0x804BE2A4: bc1fl       L_804BE2F8
    if (!c1cs) {
        // 0x804BE2A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BE2F8;
    }
    goto skip_0;
    // 0x804BE2A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BE2AC: beql        $v0, $zero, L_804BE2E8
    if (ctx->r2 == 0) {
        // 0x804BE2B0: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_804BE2E8;
    }
    goto skip_1;
    // 0x804BE2B0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x804BE2B4: lw          $t9, 0x180($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X180);
    // 0x804BE2B8: bnel        $a1, $t9, L_804BE2E8
    if (ctx->r5 != ctx->r25) {
        // 0x804BE2BC: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_804BE2E8;
    }
    goto skip_2;
    // 0x804BE2BC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x804BE2C0: jal         0x800610A0
    // 0x804BE2C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800610A0(rdram, ctx);
        goto after_1;
    // 0x804BE2C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x804BE2C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BE2CC: jal         0x8002FABC
    // 0x804BE2D0: lui         $a1, 0xC100
    ctx->r5 = S32(0XC100 << 16);
    func_8002FABC(rdram, ctx);
        goto after_2;
    // 0x804BE2D0: lui         $a1, 0xC100
    ctx->r5 = S32(0XC100 << 16);
    after_2:
    // 0x804BE2D4: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x804BE2D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804BE2DC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x804BE2E0: swc1        $f18, 0xC4($t0)
    MEM_W(0XC4, ctx->r8) = ctx->f18.u32l;
    // 0x804BE2E4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
L_804BE2E8:
    // 0x804BE2E8: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(191, 0X29D4) << 16);
    // 0x804BE2EC: addiu       $t1, $t1, -0x1CFC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(191, 0X29D4));
    // 0x804BE2F0: sw          $t1, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r9;
    // 0x804BE2F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BE2F8:
    // 0x804BE2F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BE2FC: jr          $ra
    // 0x804BE300: nop

    return;
    // 0x804BE300: nop

;}
RECOMP_FUNC void vaprintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80082144: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80082148: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8008214C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80082150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80082154: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80082158: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8008215C: jal         0x8008A510
    // 0x80082160: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    _Printf(rdram, ctx);
        goto after_0;
    // 0x80082160: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80082164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80082168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008216C: jr          $ra
    // 0x80082170: nop

    return;
    // 0x80082170: nop

;}
RECOMP_FUNC void guPerspectiveF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800863D4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800863D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800863DC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800863E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800863E4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800863E8: jal         0x80086EA0
    // 0x800863EC: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800863EC: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800863F0: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800863F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800863F8: ldc1        $f6, 0x32C0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X32C0);
    // 0x800863FC: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x80086400: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80086404: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80086408: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008640C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80086410: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80086414: jal         0x8008D250
    // 0x80086418: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80086418: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8008641C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80086420: jal         0x80082730
    // 0x80086424: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    fsin(rdram, ctx);
        goto after_2;
    // 0x80086424: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80086428: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008642C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80086430: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80086434: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80086438: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8008643C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80086440: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80086444: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80086448: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8008644C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80086450: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80086454: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80086458: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x8008645C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80086460: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80086464: div.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80086468: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x8008646C: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80086470: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80086474: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x80086478: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8008647C: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80086480: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80086484: nop

    // 0x80086488: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x8008648C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80086490: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80086494: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x80086498: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8008649C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800864A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800864A4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800864A8: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800864AC: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800864B0: beq         $v1, $a0, L_800864F4
    if (ctx->r3 == ctx->r4) {
        // 0x800864B4: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
            goto L_800864F4;
    }
    // 0x800864B4: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
L_800864B8:
    // 0x800864B8: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800864BC: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800864C0: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800864C4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800864C8: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800864CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800864D0: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800864D4: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800864D8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800864DC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800864E0: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800864E4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800864E8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800864EC: bne         $v1, $a0, L_800864B8
    if (ctx->r3 != ctx->r4) {
        // 0x800864F0: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_800864B8;
    }
    // 0x800864F0: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_800864F4:
    // 0x800864F4: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800864F8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800864FC: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80086500: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80086504: nop

    // 0x80086508: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8008650C: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80086510: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80086514: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80086518: beq         $a1, $zero, L_800865F0
    if (ctx->r5 == 0) {
        // 0x8008651C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800865F0;
    }
    // 0x8008651C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80086520: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80086524: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80086528: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8008652C: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80086530: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x80086534: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80086538: bc1fl       L_8008654C
    if (!c1cs) {
        // 0x8008653C: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_8008654C;
    }
    goto skip_0;
    // 0x8008653C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x80086540: b           L_800865F0
    // 0x80086544: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_800865F0;
    // 0x80086544: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80086548: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_8008654C:
    // 0x8008654C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80086550: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80086554: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80086558: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x8008655C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80086560: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80086564: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80086568: nop

    // 0x8008656C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x80086570: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80086574: nop

    // 0x80086578: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8008657C: beql        $t8, $zero, L_800865D0
    if (ctx->r24 == 0) {
        // 0x80086580: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_800865D0;
    }
    goto skip_1;
    // 0x80086580: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x80086584: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80086588: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8008658C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80086590: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x80086594: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80086598: nop

    // 0x8008659C: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800865A0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800865A4: nop

    // 0x800865A8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800865AC: bne         $t8, $zero, L_800865C4
    if (ctx->r24 != 0) {
        // 0x800865B0: nop
    
            goto L_800865C4;
    }
    // 0x800865B0: nop

    // 0x800865B4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800865B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800865BC: b           L_800865DC
    // 0x800865C0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800865DC;
    // 0x800865C0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800865C4:
    // 0x800865C4: b           L_800865DC
    // 0x800865C8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800865DC;
    // 0x800865C8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800865CC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_800865D0:
    // 0x800865D0: nop

    // 0x800865D4: bltz        $t8, L_800865C4
    if (SIGNED(ctx->r24) < 0) {
        // 0x800865D8: nop
    
            goto L_800865C4;
    }
    // 0x800865D8: nop

L_800865DC:
    // 0x800865DC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800865E0: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800865E4: bgtz        $t9, L_800865F0
    if (SIGNED(ctx->r25) > 0) {
        // 0x800865E8: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_800865F0;
    }
    // 0x800865E8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800865EC: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_800865F0:
    // 0x800865F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800865F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800865F8: jr          $ra
    // 0x800865FC: nop

    return;
    // 0x800865FC: nop

;}
RECOMP_FUNC void func_805A0238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A0238: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805A023C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A0240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A0244: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x805A0248: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x805A024C: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x805A0250: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A0254: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805A0258: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805A025C: jal         0x80062AEC
    // 0x805A0260: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x805A0260: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
    after_0:
    // 0x805A0264: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x805A0268: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805A026C: lhu         $v1, 0x3E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X3E);
    // 0x805A0270: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805A0274: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x805A0278: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x805A027C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x805A0280: beq         $v1, $at, L_805A029C
    if (ctx->r3 == ctx->r1) {
        // 0x805A0284: swc1        $f0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
            goto L_805A029C;
    }
    // 0x805A0284: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x805A0288: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x805A028C: beq         $v1, $at, L_805A02F4
    if (ctx->r3 == ctx->r1) {
        // 0x805A0290: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_805A02F4;
    }
    // 0x805A0290: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x805A0294: b           L_805A0330
    // 0x805A0298: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
        goto L_805A0330;
    // 0x805A0298: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
L_805A029C:
    // 0x805A029C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805A02A0: beq         $v0, $at, L_805A02B4
    if (ctx->r2 == ctx->r1) {
        // 0x805A02A4: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_805A02B4;
    }
    // 0x805A02A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805A02A8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x805A02AC: jal         0x8002F6E4
    // 0x805A02B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x805A02B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_805A02B4:
    // 0x805A02B4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x805A02B8: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x805A02BC: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x805A02C0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x805A02C4: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x805A02C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805A02CC: lw          $t9, 0x4C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4C);
    // 0x805A02D0: jalr        $t9
    // 0x805A02D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x805A02D4: nop

    after_2:
    // 0x805A02D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A02DC: jal         0x8059FAA0
    // 0x805A02E0: addiu       $a1, $zero, 0xB1
    ctx->r5 = ADD32(0, 0XB1);
    func_8059FAA0(rdram, ctx);
        goto after_3;
    // 0x805A02E0: addiu       $a1, $zero, 0xB1
    ctx->r5 = ADD32(0, 0XB1);
    after_3:
    // 0x805A02E4: jal         0x800447C8
    // 0x805A02E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x805A02E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A02EC: b           L_805A0378
    // 0x805A02F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A0378;
    // 0x805A02F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A02F4:
    // 0x805A02F4: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x805A02F8: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x805A02FC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x805A0300: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x805A0304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805A0308: lw          $t9, 0x4C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4C);
    // 0x805A030C: jalr        $t9
    // 0x805A0310: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x805A0310: nop

    after_5:
    // 0x805A0314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A0318: jal         0x8059FAA0
    // 0x805A031C: addiu       $a1, $zero, 0xB1
    ctx->r5 = ADD32(0, 0XB1);
    func_8059FAA0(rdram, ctx);
        goto after_6;
    // 0x805A031C: addiu       $a1, $zero, 0xB1
    ctx->r5 = ADD32(0, 0XB1);
    after_6:
    // 0x805A0320: jal         0x800447C8
    // 0x805A0324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x805A0324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805A0328: b           L_805A0378
    // 0x805A032C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A0378;
    // 0x805A032C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A0330:
    // 0x805A0330: lbu         $t2, 0x18($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X18);
    // 0x805A0334: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805A0338: bnel        $t2, $at, L_805A0378
    if (ctx->r10 != ctx->r1) {
        // 0x805A033C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A0378;
    }
    goto skip_0;
    // 0x805A033C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805A0340: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x805A0344: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x805A0348: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x805A034C: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x805A0350: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805A0354: lw          $t9, 0x4C($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4C);
    // 0x805A0358: jalr        $t9
    // 0x805A035C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x805A035C: nop

    after_8:
    // 0x805A0360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A0364: jal         0x8059FAA0
    // 0x805A0368: addiu       $a1, $zero, 0xB1
    ctx->r5 = ADD32(0, 0XB1);
    func_8059FAA0(rdram, ctx);
        goto after_9;
    // 0x805A0368: addiu       $a1, $zero, 0xB1
    ctx->r5 = ADD32(0, 0XB1);
    after_9:
    // 0x805A036C: jal         0x800447C8
    // 0x805A0370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_10;
    // 0x805A0370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x805A0374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A0378:
    // 0x805A0378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A037C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805A0380: jr          $ra
    // 0x805A0384: nop

    return;
    // 0x805A0384: nop

;}
RECOMP_FUNC void func_805D87D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D87D0: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x805D87D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805D87D8: lbu         $t7, 0x10($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X10);
    // 0x805D87DC: bne         $t7, $at, L_805D87F0
    if (ctx->r15 != ctx->r1) {
        // 0x805D87E0: lui         $at, 0x805E
        ctx->r1 = S32(RELOC_HI16(474, 0X2578) << 16);
            goto L_805D87F0;
    }
    // 0x805D87E0: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(474, 0X2578) << 16);
    // 0x805D87E4: lwc1        $f4, -0x6188($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(474, 0X2578));
    // 0x805D87E8: jr          $ra
    // 0x805D87EC: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x805D87EC: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
L_805D87F0:
    // 0x805D87F0: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(474, 0X257C) << 16);
    // 0x805D87F4: lwc1        $f6, -0x6184($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(474, 0X257C));
    // 0x805D87F8: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    // 0x805D87FC: jr          $ra
    // 0x805D8800: nop

    return;
    // 0x805D8800: nop

;}
RECOMP_FUNC void func_804F36C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F36C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804F36C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804F36C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804F36CC: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x804F36D0: addiu       $at, $zero, 0x404D
    ctx->r1 = ADD32(0, 0X404D);
    // 0x804F36D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804F36D8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x804F36DC: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x804F36E0: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x804F36E4: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x804F36E8: beq         $v0, $at, L_804F3700
    if (ctx->r2 == ctx->r1) {
        // 0x804F36EC: addiu       $at, $zero, 0x404F
        ctx->r1 = ADD32(0, 0X404F);
            goto L_804F3700;
    }
    // 0x804F36EC: addiu       $at, $zero, 0x404F
    ctx->r1 = ADD32(0, 0X404F);
    // 0x804F36F0: beq         $v0, $at, L_804F3724
    if (ctx->r2 == ctx->r1) {
        // 0x804F36F4: nop
    
            goto L_804F3724;
    }
    // 0x804F36F4: nop

    // 0x804F36F8: b           L_804F3744
    // 0x804F36FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804F3744;
    // 0x804F36FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F3700:
    // 0x804F3700: jal         0x804F3360
    // 0x804F3704: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_804F3360(rdram, ctx);
        goto after_0;
    // 0x804F3704: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x804F3708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F370C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F3710: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804F3714: jal         0x804F3EF0
    // 0x804F3718: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804F3EF0(rdram, ctx);
        goto after_1;
    // 0x804F3718: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804F371C: b           L_804F3744
    // 0x804F3720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804F3744;
    // 0x804F3720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F3724:
    // 0x804F3724: jal         0x804F34EC
    // 0x804F3728: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_804F34EC(rdram, ctx);
        goto after_2;
    // 0x804F3728: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x804F372C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F3730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F3734: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804F3738: jal         0x804F3EF0
    // 0x804F373C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_804F3EF0(rdram, ctx);
        goto after_3;
    // 0x804F373C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x804F3740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F3744:
    // 0x804F3744: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804F3748: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804F374C: jr          $ra
    // 0x804F3750: nop

    return;
    // 0x804F3750: nop

;}
RECOMP_FUNC void func_807B8F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B8FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B8FA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B8FA8: jal         0x800694BC
    // 0x807B8FAC: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    func_800694BC(rdram, ctx);
        goto after_0;
    // 0x807B8FAC: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_0:
    // 0x807B8FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B8FB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B8FB8: jr          $ra
    // 0x807B8FBC: nop

    return;
    // 0x807B8FBC: nop

;}
RECOMP_FUNC void func_8044C5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044C5F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044C5F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044C5FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8044C600: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8044C604: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8044C608: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8044C60C: jal         0x80066E88
    // 0x8044C610: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8044C610: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x8044C614: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8044C618: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C61C: jal         0x80066DE4
    // 0x8044C620: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8044C620: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x8044C624: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C628: jal         0x80066E88
    // 0x8044C62C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8044C62C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8044C630: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C634: jal         0x80066DE4
    // 0x8044C638: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8044C638: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8044C63C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8044C640: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8044C644: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8044C648: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8044C64C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8044C650: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8044C654: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8044C658: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8044C65C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8044C660: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8044C664: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8044C668: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C66C: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8044C670: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8044C674: swc1        $f14, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f14.u32l;
    // 0x8044C678: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8044C67C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8044C680: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x8044C684: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x8044C688: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x8044C68C: swc1        $f16, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f16.u32l;
    // 0x8044C690: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x8044C694: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x8044C698: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044C69C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8044C6A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8044C6A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8044C6A8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C6AC: jr          $ra
    // 0x8044C6B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8044C6B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800383E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800383E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800383E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800383E8: jal         0x800238A8
    // 0x800383EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800238A8(rdram, ctx);
        goto after_0;
    // 0x800383EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800383F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800383F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800383F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800383FC: lwc1        $f4, 0xDC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80038400: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80038404: jal         0x80023EA0
    // 0x80038408: swc1        $f8, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f8.u32l;
    func_80023EA0(rdram, ctx);
        goto after_1;
    // 0x80038408: swc1        $f8, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f8.u32l;
    after_1:
    // 0x8003840C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038414: jr          $ra
    // 0x80038418: nop

    return;
    // 0x80038418: nop

;}
RECOMP_FUNC void func_80676640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676640: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80676644: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80676648: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8067664C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80676650: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80676654: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80676658: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8067665C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80676660: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80676664: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80676668: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8067666C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80676670: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80676674: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676678: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X25E4) << 16);
    // 0x8067667C: lwc1        $f28, 0x7CA4($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X25E4));
    // 0x80676680: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X25E8) << 16);
    // 0x80676684: addiu       $v1, $s4, 0x36C
    ctx->r3 = ADD32(ctx->r20, 0X36C);
    // 0x80676688: addiu       $s1, $v1, 0x4
    ctx->r17 = ADD32(ctx->r3, 0X4);
    // 0x8067668C: lwc1        $f0, 0x7CA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X25E8));
    // 0x80676690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80676694: lw          $s3, 0x404($s4)
    ctx->r19 = MEM_W(ctx->r20, 0X404);
    // 0x80676698: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
L_8067669C:
    // 0x8067669C: lwc1        $f6, 0x2F0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x806766A0: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x806766A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x806766A8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x806766AC: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x806766B0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806766B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806766B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806766BC: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x806766C0: swc1        $f16, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f16.u32l;
    // 0x806766C4: lwc1        $f6, 0x2EC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x806766C8: lwc1        $f18, 0x2E8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x806766CC: lwc1        $f10, -0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, -0X4);
    // 0x806766D0: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x806766D4: mul.s       $f4, $f8, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x806766D8: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x806766DC: bne         $at, $zero, L_8067669C
    if (ctx->r1 != 0) {
        // 0x806766E0: swc1        $f16, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f16.u32l;
            goto L_8067669C;
    }
    // 0x806766E0: swc1        $f16, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f16.u32l;
    // 0x806766E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806766E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806766EC: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
    // 0x806766F0: addiu       $s2, $sp, 0x94
    ctx->r18 = ADD32(ctx->r29, 0X94);
    // 0x806766F4: addiu       $s1, $v1, 0x4
    ctx->r17 = ADD32(ctx->r3, 0X4);
    // 0x806766F8: addiu       $v0, $sp, 0x108
    ctx->r2 = ADD32(ctx->r29, 0X108);
    // 0x806766FC: lwc1        $f20, 0x2F4($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X2F4);
    // 0x80676700: lwc1        $f22, 0x2F0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80676704: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80676708: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x8067670C: sub.s       $f22, $f20, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80676710: lwc1        $f30, 0x0($s1)
    ctx->f30.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80676714: mul.s       $f26, $f22, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = MUL_S(ctx->f22.fl, ctx->f28.fl);
    // 0x80676718: beql        $at, $zero, L_80676778
    if (ctx->r1 == 0) {
        // 0x8067671C: add.s       $f24, $f30, $f26
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = ctx->f30.fl + ctx->f26.fl;
            goto L_80676778;
    }
    goto skip_0;
    // 0x8067671C: add.s       $f24, $f30, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = ctx->f30.fl + ctx->f26.fl;
    skip_0:
    // 0x80676720: add.s       $f24, $f30, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = ctx->f30.fl + ctx->f26.fl;
L_80676724:
    // 0x80676724: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80676728: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x8067672C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80676730: swc1        $f24, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f24.u32l;
    // 0x80676734: lwc1        $f24, 0x2E8($s0)
    ctx->f24.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x80676738: lwc1        $f22, 0x2F0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8067673C: lwc1        $f20, 0x2EC($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x80676740: mul.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80676744: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80676748: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8067674C: add.s       $f22, $f24, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f24.fl + ctx->f22.fl;
    // 0x80676750: sub.s       $f20, $f22, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x80676754: swc1        $f20, -0x8($s2)
    MEM_W(-0X8, ctx->r18) = ctx->f20.u32l;
    // 0x80676758: lwc1        $f20, 0x2F4($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X2F4);
    // 0x8067675C: lwc1        $f22, 0x2F0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80676760: lwc1        $f30, 0x0($s1)
    ctx->f30.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80676764: sub.s       $f22, $f20, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80676768: mul.s       $f26, $f22, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = MUL_S(ctx->f22.fl, ctx->f28.fl);
    // 0x8067676C: bnel        $at, $zero, L_80676724
    if (ctx->r1 != 0) {
        // 0x80676770: add.s       $f24, $f30, $f26
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = ctx->f30.fl + ctx->f26.fl;
            goto L_80676724;
    }
    goto skip_1;
    // 0x80676770: add.s       $f24, $f30, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = ctx->f30.fl + ctx->f26.fl;
    skip_1:
    // 0x80676774: add.s       $f24, $f30, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = ctx->f30.fl + ctx->f26.fl;
L_80676778:
    // 0x80676778: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8067677C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80676780: swc1        $f24, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f24.u32l;
    // 0x80676784: lwc1        $f24, 0x2E8($s0)
    ctx->f24.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x80676788: lwc1        $f22, 0x2F0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8067678C: lwc1        $f20, 0x2EC($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x80676790: mul.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80676794: nop

    // 0x80676798: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8067679C: add.s       $f22, $f24, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f24.fl + ctx->f22.fl;
    // 0x806767A0: sub.s       $f20, $f22, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x806767A4: swc1        $f20, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->f20.u32l;
    // 0x806767A8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x806767AC: nop

    // 0x806767B0: swc1        $f24, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f24.u32l;
    // 0x806767B4: lwc1        $f6, 0x2F0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x806767B8: lwc1        $f8, 0x2EC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x806767BC: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x806767C0: beq         $s3, $zero, L_8067689C
    if (ctx->r19 == 0) {
        // 0x806767C4: swc1        $f4, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
            goto L_8067689C;
    }
    // 0x806767C4: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x806767C8: lwc1        $f0, 0xC4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC4);
    // 0x806767CC: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x806767D0: addiu       $s0, $v1, 0x78
    ctx->r16 = ADD32(ctx->r3, 0X78);
    // 0x806767D4: c.eq.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl == ctx->f0.fl;
    // 0x806767D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x806767DC: addiu       $s2, $zero, 0x28
    ctx->r18 = ADD32(0, 0X28);
    // 0x806767E0: bc1tl       L_806768A0
    if (c1cs) {
        // 0x806767E4: lwc1        $f4, 0x3EC($s4)
        ctx->f4.u32l = MEM_W(ctx->r20, 0X3EC);
            goto L_806768A0;
    }
    goto skip_2;
    // 0x806767E4: lwc1        $f4, 0x3EC($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X3EC);
    skip_2:
    // 0x806767E8: lwc1        $f10, 0x3EC($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X3EC);
    // 0x806767EC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806767F0: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x806767F4: mul.s       $f26, $f0, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806767F8: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
L_806767FC:
    // 0x806767FC: jal         0x80066E88
    // 0x80676800: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80676800: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x80676804: mul.s       $f2, $f0, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x80676808: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8067680C: add.s       $f22, $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x80676810: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x80676814: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80676818: bc1f        L_8067683C
    if (!c1cs) {
        // 0x8067681C: swc1        $f18, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
            goto L_8067683C;
    }
    // 0x8067681C: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80676820: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80676824: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80676828: nop

    // 0x8067682C: bc1fl       L_80676858
    if (!c1cs) {
        // 0x80676830: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80676858;
    }
    goto skip_3;
    // 0x80676830: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_3:
    // 0x80676834: b           L_80676854
    // 0x80676838: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
        goto L_80676854;
    // 0x80676838: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
L_8067683C:
    // 0x8067683C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80676840: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80676844: nop

    // 0x80676848: bc1fl       L_80676858
    if (!c1cs) {
        // 0x8067684C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80676858;
    }
    goto skip_4;
    // 0x8067684C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_4:
    // 0x80676850: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
L_80676854:
    // 0x80676854: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80676858:
    // 0x80676858: bne         $s1, $s2, L_806767FC
    if (ctx->r17 != ctx->r18) {
        // 0x8067685C: addiu       $s0, $s0, -0x4
        ctx->r16 = ADD32(ctx->r16, -0X4);
            goto L_806767FC;
    }
    // 0x8067685C: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x80676860: lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X1F4);
    // 0x80676864: lhu         $t7, 0x4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X4);
    // 0x80676868: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8067686C: bnel        $t8, $zero, L_80676898
    if (ctx->r24 != 0) {
        // 0x80676870: swc1        $f24, 0xC4($s3)
        MEM_W(0XC4, ctx->r19) = ctx->f24.u32l;
            goto L_80676898;
    }
    goto skip_5;
    // 0x80676870: swc1        $f24, 0xC4($s3)
    MEM_W(0XC4, ctx->r19) = ctx->f24.u32l;
    skip_5:
    // 0x80676874: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
    // 0x80676878: blez        $a0, L_80676888
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8067687C: addiu       $t9, $a0, -0x1
        ctx->r25 = ADD32(ctx->r4, -0X1);
            goto L_80676888;
    }
    // 0x8067687C: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x80676880: b           L_8067688C
    // 0x80676884: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
        goto L_8067688C;
    // 0x80676884: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
L_80676888:
    // 0x80676888: swc1        $f24, 0xC4($s3)
    MEM_W(0XC4, ctx->r19) = ctx->f24.u32l;
L_8067688C:
    // 0x8067688C: b           L_8067689C
    // 0x80676890: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
        goto L_8067689C;
    // 0x80676890: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80676894: swc1        $f24, 0xC4($s3)
    MEM_W(0XC4, ctx->r19) = ctx->f24.u32l;
L_80676898:
    // 0x80676898: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
L_8067689C:
    // 0x8067689C: lwc1        $f4, 0x3EC($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X3EC);
L_806768A0:
    // 0x806768A0: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X25EC) << 16);
    // 0x806768A4: lwc1        $f22, 0x7CAC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X25EC));
    // 0x806768A8: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X25F0) << 16);
    // 0x806768AC: mul.s       $f20, $f4, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x806768B0: mov.s       $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    ctx->f26.fl = ctx->f24.fl;
    // 0x806768B4: lwc1        $f30, 0x7CB0($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X25F0));
    // 0x806768B8: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
    // 0x806768BC: addiu       $s2, $sp, 0x94
    ctx->r18 = ADD32(ctx->r29, 0X94);
    // 0x806768C0: addiu       $s1, $v1, 0x4
    ctx->r17 = ADD32(ctx->r3, 0X4);
    // 0x806768C4: addiu       $s3, $sp, 0x10C
    ctx->r19 = ADD32(ctx->r29, 0X10C);
L_806768C8:
    // 0x806768C8: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x806768CC: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x806768D0: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x806768D4: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x806768D8: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x806768DC: nop

    // 0x806768E0: bc1fl       L_80676924
    if (!c1cs) {
        // 0x806768E4: lwc1        $f0, 0x2F0($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X2F0);
            goto L_80676924;
    }
    goto skip_6;
    // 0x806768E4: lwc1        $f0, 0x2F0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2F0);
    skip_6:
    // 0x806768E8: lwc1        $f0, 0x2F0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x806768EC: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x806768F0: nop

    // 0x806768F4: bc1fl       L_80676954
    if (!c1cs) {
        // 0x806768F8: add.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_80676954;
    }
    goto skip_7;
    // 0x806768F8: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    skip_7:
    // 0x806768FC: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    // 0x80676900: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80676904: nop

    // 0x80676908: bc1fl       L_80676954
    if (!c1cs) {
        // 0x8067690C: add.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_80676954;
    }
    goto skip_8;
    // 0x8067690C: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    skip_8:
    // 0x80676910: swc1        $f12, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f12.u32l;
    // 0x80676914: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80676918: b           L_80676950
    // 0x8067691C: lwc1        $f0, 0x2F0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2F0);
        goto L_80676950;
    // 0x8067691C: lwc1        $f0, 0x2F0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80676920: lwc1        $f0, 0x2F0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2F0);
L_80676924:
    // 0x80676924: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x80676928: nop

    // 0x8067692C: bc1fl       L_80676954
    if (!c1cs) {
        // 0x80676930: add.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_80676954;
    }
    goto skip_9;
    // 0x80676930: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    skip_9:
    // 0x80676934: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80676938: nop

    // 0x8067693C: bc1fl       L_80676954
    if (!c1cs) {
        // 0x80676940: add.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_80676954;
    }
    goto skip_10;
    // 0x80676940: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    skip_10:
    // 0x80676944: swc1        $f20, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f20.u32l;
    // 0x80676948: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8067694C: lwc1        $f0, 0x2F0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2F0);
L_80676950:
    // 0x80676950: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
L_80676954:
    // 0x80676954: lwc1        $f18, 0x3EC($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X3EC);
    // 0x80676958: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X25F4) << 16);
    // 0x8067695C: add.s       $f22, $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f30.fl;
    // 0x80676960: swc1        $f6, 0x2F0($s0)
    MEM_W(0X2F0, ctx->r16) = ctx->f6.u32l;
    // 0x80676964: mul.s       $f8, $f28, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f18.fl);
    // 0x80676968: lwc1        $f10, 0x7CB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X25F4));
    // 0x8067696C: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80676970: lwc1        $f18, 0x2F0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80676974: lwc1        $f6, 0x2EC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x80676978: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8067697C: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x80676980: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80676984: swc1        $f8, 0x2F0($s0)
    MEM_W(0X2F0, ctx->r16) = ctx->f8.u32l;
    // 0x80676988: lwc1        $f4, 0x2F0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8067698C: jal         0x80065954
    // 0x80676990: sub.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f4.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80676990: sub.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f4.fl;
    after_1:
    // 0x80676994: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80676998: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8067699C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806769A0: bne         $s2, $s3, L_806768C8
    if (ctx->r18 != ctx->r19) {
        // 0x806769A4: add.s       $f26, $f26, $f0
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f0.fl;
            goto L_806768C8;
    }
    // 0x806769A4: add.s       $f26, $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f0.fl;
    // 0x806769A8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806769AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806769B0: lwc1        $f10, 0x3EC($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X3EC);
    // 0x806769B4: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x806769B8: mul.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x806769BC: jal         0x80067114
    // 0x806769C0: nop

    func_80067114(rdram, ctx);
        goto after_2;
    // 0x806769C0: nop

    after_2:
    // 0x806769C4: jal         0x80066E88
    // 0x806769C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x806769C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x806769CC: swc1        $f0, 0x400($s4)
    MEM_W(0X400, ctx->r20) = ctx->f0.u32l;
    // 0x806769D0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x806769D4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x806769D8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x806769DC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x806769E0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x806769E4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x806769E8: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x806769EC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x806769F0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x806769F4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x806769F8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806769FC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80676A00: jr          $ra
    // 0x80676A04: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x80676A04: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_80048320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048320: beq         $a0, $zero, L_80048340
    if (ctx->r4 == 0) {
        // 0x80048324: nop
    
            goto L_80048340;
    }
    // 0x80048324: nop

    // 0x80048328: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8004832C: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80048330: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80048334: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80048338: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x8004833C: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
L_80048340:
    // 0x80048340: jr          $ra
    // 0x80048344: nop

    return;
    // 0x80048344: nop

;}
RECOMP_FUNC void func_80030DDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030DDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030DE4: lw          $t6, 0x78($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X78);
    // 0x80030DE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030DEC: beq         $t6, $zero, L_80030E04
    if (ctx->r14 == 0) {
        // 0x80030DF0: nop
    
            goto L_80030E04;
    }
    // 0x80030DF0: nop

    // 0x80030DF4: jal         0x8002D898
    // 0x80030DF8: nop

    func_8002D898(rdram, ctx);
        goto after_0;
    // 0x80030DF8: nop

    after_0:
    // 0x80030DFC: b           L_80030E04
    // 0x80030E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80030E04;
    // 0x80030E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80030E04:
    // 0x80030E04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030E08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030E0C: jr          $ra
    // 0x80030E10: nop

    return;
    // 0x80030E10: nop

;}
RECOMP_FUNC void func_80581AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581AA4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80581AA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80581AAC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80581AB0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80581AB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80581AB8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80581ABC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80581AC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80581AC4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80581AC8: lui         $t1, 0x8058
    ctx->r9 = S32(RELOC_HI16(399, 0X465C) << 16);
    // 0x80581ACC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80581AD0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80581AD4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80581AD8: lw          $t1, 0x346C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(399, 0X465C));
    // 0x80581ADC: jr          $ra
    // 0x80581AE0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80581AE0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804EF2BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF2BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF2C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF2C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804EF2C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804EF2CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804EF2D0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x804EF2D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804EF2D8: sltiu       $at, $v1, 0x96
    ctx->r1 = ctx->r3 < 0X96 ? 1 : 0;
    // 0x804EF2DC: bne         $at, $zero, L_804EF314
    if (ctx->r1 != 0) {
        // 0x804EF2E0: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_804EF314;
    }
    // 0x804EF2E0: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x804EF2E4: jal         0x804EF5A0
    // 0x804EF2E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804EF5A0(rdram, ctx);
        goto after_0;
    // 0x804EF2E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EF2EC: jal         0x804EEF8C
    // 0x804EF2F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804EEF8C(rdram, ctx);
        goto after_1;
    // 0x804EF2F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804EF2F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804EF2F8: jal         0x80067E78
    // 0x804EF2FC: lw          $a0, 0x34($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X34);
    func_80067E78(rdram, ctx);
        goto after_2;
    // 0x804EF2FC: lw          $a0, 0x34($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X34);
    after_2:
    // 0x804EF300: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x804EF304: jal         0x80067818
    // 0x804EF308: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x804EF308: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x804EF30C: b           L_804EF31C
    // 0x804EF310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804EF31C;
    // 0x804EF310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EF314:
    // 0x804EF314: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804EF318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EF31C:
    // 0x804EF31C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF320: jr          $ra
    // 0x804EF324: nop

    return;
    // 0x804EF324: nop

;}
RECOMP_FUNC void func_80707704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80707704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80707708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070770C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80707710: jal         0x80045A34
    // 0x80707714: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80707714: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80707718: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8070771C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80707720: bne         $v0, $zero, L_80707738
    if (ctx->r2 != 0) {
        // 0x80707724: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80707738;
    }
    // 0x80707724: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80707728: jal         0x800445A4
    // 0x8070772C: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8070772C: nop

    after_1:
    // 0x80707730: b           L_8070777C
    // 0x80707734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8070777C;
    // 0x80707734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80707738:
    // 0x80707738: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8070773C: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(712, 0X638) << 16);
    // 0x80707740: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80707744: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80707748: addiu       $t7, $t7, 0x77D8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(712, 0X638));
    // 0x8070774C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80707750: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80707754: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80707758: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8070775C: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x80707760: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x80707764: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x80707768: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070776C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80707770: jal         0x80707788
    // 0x80707774: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_80707788(rdram, ctx);
        goto after_2;
    // 0x80707774: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_2:
    // 0x80707778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8070777C:
    // 0x8070777C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80707780: jr          $ra
    // 0x80707784: nop

    return;
    // 0x80707784: nop

;}
RECOMP_FUNC void func_80079140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079140: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80079144: jr          $ra
    // 0x80079148: nop

    return;
    // 0x80079148: nop

;}
RECOMP_FUNC void func_8003D8DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D8DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003D8E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D8E4: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x8003D8E8: lui         $ra, 0x800F
    ctx->r31 = S32(0X800F << 16);
    // 0x8003D8EC: addiu       $ra, $ra, 0x7EA0
    ctx->r31 = ADD32(ctx->r31, 0X7EA0);
    // 0x8003D8F0: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8003D8F4: lw          $t1, 0xF10($ra)
    ctx->r9 = MEM_W(ctx->r31, 0XF10);
    // 0x8003D8F8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8003D8FC: lhu         $t7, 0x18($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X18);
    // 0x8003D900: lhu         $t9, 0x1A($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X1A);
    // 0x8003D904: sll         $a3, $t1, 2
    ctx->r7 = S32(ctx->r9 << 2);
    // 0x8003D908: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8003D90C: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x8003D910: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8003D914: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x8003D918: lw          $t6, -0x20BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X20BC);
    // 0x8003D91C: addu        $t8, $t8, $a3
    ctx->r24 = ADD32(ctx->r24, ctx->r7);
    // 0x8003D920: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x8003D924: lw          $t8, -0x209C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X209C);
    // 0x8003D928: and         $t7, $t0, $t6
    ctx->r15 = ctx->r8 & ctx->r14;
    // 0x8003D92C: lbu         $t3, 0x1C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1C);
    // 0x8003D930: srlv        $t5, $t7, $t8
    ctx->r13 = S32(U32(ctx->r15) >> (ctx->r24 & 31));
    // 0x8003D934: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8003D938: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8003D93C: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x8003D940: lw          $t4, -0x20DC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X20DC);
    // 0x8003D944: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8003D948: beq         $t3, $zero, L_8003D968
    if (ctx->r11 == 0) {
        // 0x8003D94C: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_8003D968;
    }
    // 0x8003D94C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8003D950: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
L_8003D954:
    // 0x8003D954: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x8003D958: beq         $at, $zero, L_8003D968
    if (ctx->r1 == 0) {
        // 0x8003D95C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8003D968;
    }
    // 0x8003D95C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003D960: bnel        $v0, $zero, L_8003D954
    if (ctx->r2 != 0) {
        // 0x8003D964: sll         $a2, $a2, 1
        ctx->r6 = S32(ctx->r6 << 1);
            goto L_8003D954;
    }
    goto skip_0;
    // 0x8003D964: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    skip_0:
L_8003D968:
    // 0x8003D968: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x8003D96C: blez        $t4, L_8003D9D4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8003D970: sb          $t6, 0x1C($t2)
        MEM_B(0X1C, ctx->r10) = ctx->r14;
            goto L_8003D9D4;
    }
    // 0x8003D970: sb          $t6, 0x1C($t2)
    MEM_B(0X1C, ctx->r10) = ctx->r14;
    // 0x8003D974: lw          $v1, 0xAB4($ra)
    ctx->r3 = MEM_W(ctx->r31, 0XAB4);
    // 0x8003D978: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8003D97C: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8003D980: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8003D984: jal         0x8004700C
    // 0x8003D988: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003D988: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8003D98C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D990: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8003D994: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8003D998: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003D99C: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003D9A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003D9A4: mflo        $t7
    ctx->r15 = lo;
    // 0x8003D9A8: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8003D9AC: bgez        $v1, L_8003D9B8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8003D9B0: nop
    
            goto L_8003D9B8;
    }
    // 0x8003D9B0: nop

    // 0x8003D9B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8003D9B8:
    // 0x8003D9B8: beq         $v0, $zero, L_8003D9CC
    if (ctx->r2 == 0) {
        // 0x8003D9BC: nop
    
            goto L_8003D9CC;
    }
    // 0x8003D9BC: nop

    // 0x8003D9C0: jal         0x8002B03C
    // 0x8003D9C4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8002B03C(rdram, ctx);
        goto after_1;
    // 0x8003D9C4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x8003D9C8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_8003D9CC:
    // 0x8003D9CC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003D9D0: sw          $v1, -0x76AC($at)
    MEM_W(-0X76AC, ctx->r1) = ctx->r3;
L_8003D9D4:
    // 0x8003D9D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D9D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8003D9DC: jr          $ra
    // 0x8003D9E0: nop

    return;
    // 0x8003D9E0: nop

;}
RECOMP_FUNC void func_806EF2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF2F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EF2F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EF2FC: jal         0x80056904
    // 0x806EF300: nop

    func_80056904(rdram, ctx);
        goto after_0;
    // 0x806EF300: nop

    after_0:
    // 0x806EF304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EF308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EF30C: jr          $ra
    // 0x806EF310: nop

    return;
    // 0x806EF310: nop

;}
RECOMP_FUNC void func_80531A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531A90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80531A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80531A98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80531A9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80531AA0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80531AA4: lw          $t6, 0x1F4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1F4);
    // 0x80531AA8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80531AAC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80531AB0: jal         0x805317EC
    // 0x80531AB4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_805317EC(rdram, ctx);
        goto after_0;
    // 0x80531AB4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80531AB8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80531ABC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80531AC0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80531AC4: lw          $t8, 0x78($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X78);
    // 0x80531AC8: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A10) << 16);
    // 0x80531ACC: beql        $t8, $zero, L_80531AE0
    if (ctx->r24 == 0) {
        // 0x80531AD0: lwc1        $f0, 0x270($a2)
        ctx->f0.u32l = MEM_W(ctx->r6, 0X270);
            goto L_80531AE0;
    }
    goto skip_0;
    // 0x80531AD0: lwc1        $f0, 0x270($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X270);
    skip_0:
    // 0x80531AD4: b           L_80531B24
    // 0x80531AD8: swc1        $f4, 0x270($a2)
    MEM_W(0X270, ctx->r6) = ctx->f4.u32l;
        goto L_80531B24;
    // 0x80531AD8: swc1        $f4, 0x270($a2)
    MEM_W(0X270, ctx->r6) = ctx->f4.u32l;
    // 0x80531ADC: lwc1        $f0, 0x270($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X270);
L_80531AE0:
    // 0x80531AE0: lwc1        $f6, 0x2800($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A10));
    // 0x80531AE4: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A14) << 16);
    // 0x80531AE8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80531AEC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80531AF0: lui         $a1, 0xBD4C
    ctx->r5 = S32(0XBD4C << 16);
    // 0x80531AF4: bc1t        L_80531B10
    if (c1cs) {
        // 0x80531AF8: nop
    
            goto L_80531B10;
    }
    // 0x80531AF8: nop

    // 0x80531AFC: lwc1        $f8, 0x2804($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A14));
    // 0x80531B00: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80531B04: nop

    // 0x80531B08: bc1fl       L_80531B28
    if (!c1cs) {
        // 0x80531B0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80531B28;
    }
    goto skip_1;
    // 0x80531B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_80531B10:
    // 0x80531B10: jal         0x80531880
    // 0x80531B14: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80531880(rdram, ctx);
        goto after_1;
    // 0x80531B14: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_1:
    // 0x80531B18: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80531B1C: jal         0x80531774
    // 0x80531B20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80531774(rdram, ctx);
        goto after_2;
    // 0x80531B20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_80531B24:
    // 0x80531B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80531B28:
    // 0x80531B28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80531B2C: jr          $ra
    // 0x80531B30: nop

    return;
    // 0x80531B30: nop

;}
RECOMP_FUNC void func_80446BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446BDC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446BE0: addiu       $v1, $zero, 0xAC8
    ctx->r3 = ADD32(0, 0XAC8);
    // 0x80446BE4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446BE8: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x80446BEC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446BF0: sw          $zero, 0x6CC8($at)
    MEM_W(0X6CC8, ctx->r1) = 0;
    // 0x80446BF4: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446BF8: addiu       $t7, $zero, 0x744
    ctx->r15 = ADD32(0, 0X744);
    // 0x80446BFC: sw          $t6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r14;
    // 0x80446C00: sw          $t7, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r15;
    // 0x80446C04: jr          $ra
    // 0x80446C08: sw          $v1, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r3;
    return;
    // 0x80446C08: sw          $v1, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_806D3B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3B34: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806D3B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D3B3C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x806D3B40: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x806D3B44: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x806D3B48: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x806D3B4C: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x806D3B50: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
    // 0x806D3B54: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D3B58: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x806D3B5C: jal         0x8004700C
    // 0x806D3B60: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D3B60: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    after_0:
    // 0x806D3B64: lhu         $v1, 0x3E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X3E);
    // 0x806D3B68: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x806D3B6C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806D3B70: beq         $v1, $at, L_806D3B98
    if (ctx->r3 == ctx->r1) {
        // 0x806D3B74: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_806D3B98;
    }
    // 0x806D3B74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806D3B78: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806D3B7C: beq         $v1, $at, L_806D3C18
    if (ctx->r3 == ctx->r1) {
        // 0x806D3B80: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_806D3C18;
    }
    // 0x806D3B80: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x806D3B84: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x806D3B88: beq         $v1, $at, L_806D3D44
    if (ctx->r3 == ctx->r1) {
        // 0x806D3B8C: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_806D3D44;
    }
    // 0x806D3B8C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x806D3B90: b           L_806D3D94
    // 0x806D3B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D3D94;
    // 0x806D3B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D3B98:
    // 0x806D3B98: jal         0x806D3A5C
    // 0x806D3B9C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_806D3A5C(rdram, ctx);
        goto after_1;
    // 0x806D3B9C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_1:
    // 0x806D3BA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x806D3BA4: jal         0x8003E478
    // 0x806D3BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003E478(rdram, ctx);
        goto after_2;
    // 0x806D3BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x806D3BAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806D3BB0: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x806D3BB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806D3BB8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x806D3BBC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806D3BC0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x806D3BC4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x806D3BC8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x806D3BCC: lbu         $t9, 0x18($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X18);
    // 0x806D3BD0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806D3BD4: beql        $t9, $at, L_806D3BF4
    if (ctx->r25 == ctx->r1) {
        // 0x806D3BD8: addiu       $t0, $zero, 0x32
        ctx->r8 = ADD32(0, 0X32);
            goto L_806D3BF4;
    }
    goto skip_0;
    // 0x806D3BD8: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    skip_0:
    // 0x806D3BDC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x806D3BE0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x806D3BE4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x806D3BE8: jal         0x8002F96C
    // 0x806D3BEC: nop

    func_8002F96C(rdram, ctx);
        goto after_3;
    // 0x806D3BEC: nop

    after_3:
    // 0x806D3BF0: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
L_806D3BF4:
    // 0x806D3BF4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806D3BF8: sb          $t0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r8;
    // 0x806D3BFC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806D3C00: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x806D3C04: sb          $t1, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r9;
    // 0x806D3C08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806D3C0C: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x806D3C10: b           L_806D3D90
    // 0x806D3C14: sb          $t2, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r10;
        goto L_806D3D90;
    // 0x806D3C14: sb          $t2, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r10;
L_806D3C18:
    // 0x806D3C18: lbu         $t3, 0x18($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X18);
    // 0x806D3C1C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806D3C20: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x806D3C24: bnel        $t3, $at, L_806D3D94
    if (ctx->r11 != ctx->r1) {
        // 0x806D3C28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D3D94;
    }
    goto skip_1;
    // 0x806D3C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806D3C2C: sb          $t4, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r12;
    // 0x806D3C30: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x806D3C34: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x806D3C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D3C3C: jalr        $t9
    // 0x806D3C40: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x806D3C40: nop

    after_4:
    // 0x806D3C44: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x806D3C48: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x806D3C4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806D3C50: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x806D3C54: lwc1        $f8, 0x84($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X84);
    // 0x806D3C58: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806D3C5C: nop

    // 0x806D3C60: bc1fl       L_806D3CD8
    if (!c1cs) {
        // 0x806D3C64: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_806D3CD8;
    }
    goto skip_2;
    // 0x806D3C64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_2:
    // 0x806D3C68: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806D3C6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806D3C70: addiu       $t5, $v1, 0xC4
    ctx->r13 = ADD32(ctx->r3, 0XC4);
    // 0x806D3C74: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x806D3C78: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x806D3C7C: lbu         $v0, 0x30($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X30);
    // 0x806D3C80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D3C84: bnel        $v0, $at, L_806D3C9C
    if (ctx->r2 != ctx->r1) {
        // 0x806D3C88: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_806D3C9C;
    }
    goto skip_3;
    // 0x806D3C88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_3:
    // 0x806D3C8C: lw          $t7, 0x12C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X12C);
    // 0x806D3C90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D3C94: beq         $t7, $at, L_806D3CA4
    if (ctx->r15 == ctx->r1) {
        // 0x806D3C98: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_806D3CA4;
    }
    // 0x806D3C98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_806D3C9C:
    // 0x806D3C9C: bne         $v0, $at, L_806D3CC4
    if (ctx->r2 != ctx->r1) {
        // 0x806D3CA0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_806D3CC4;
    }
    // 0x806D3CA0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_806D3CA4:
    // 0x806D3CA4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806D3CA8: jal         0x806D3A5C
    // 0x806D3CAC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_806D3A5C(rdram, ctx);
        goto after_5;
    // 0x806D3CAC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_5:
    // 0x806D3CB0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x806D3CB4: jal         0x8003E478
    // 0x806D3CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003E478(rdram, ctx);
        goto after_6;
    // 0x806D3CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x806D3CBC: b           L_806D3D34
    // 0x806D3CC0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
        goto L_806D3D34;
    // 0x806D3CC0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_806D3CC4:
    // 0x806D3CC4: jal         0x806D3ADC
    // 0x806D3CC8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_806D3ADC(rdram, ctx);
        goto after_7;
    // 0x806D3CC8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_7:
    // 0x806D3CCC: b           L_806D3D34
    // 0x806D3CD0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
        goto L_806D3D34;
    // 0x806D3CD0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806D3CD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_806D3CD8:
    // 0x806D3CD8: addiu       $t8, $v1, 0xC4
    ctx->r24 = ADD32(ctx->r3, 0XC4);
    // 0x806D3CDC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x806D3CE0: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x806D3CE4: lbu         $v0, 0x30($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X30);
    // 0x806D3CE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D3CEC: bnel        $v0, $at, L_806D3D00
    if (ctx->r2 != ctx->r1) {
        // 0x806D3CF0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_806D3D00;
    }
    goto skip_4;
    // 0x806D3CF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_4:
    // 0x806D3CF4: lw          $t1, 0x12C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X12C);
    // 0x806D3CF8: beq         $t1, $zero, L_806D3D08
    if (ctx->r9 == 0) {
        // 0x806D3CFC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_806D3D08;
    }
    // 0x806D3CFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_806D3D00:
    // 0x806D3D00: bne         $v0, $at, L_806D3D28
    if (ctx->r2 != ctx->r1) {
        // 0x806D3D04: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_806D3D28;
    }
    // 0x806D3D04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_806D3D08:
    // 0x806D3D08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806D3D0C: jal         0x806D3A5C
    // 0x806D3D10: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_806D3A5C(rdram, ctx);
        goto after_8;
    // 0x806D3D10: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_8:
    // 0x806D3D14: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x806D3D18: jal         0x8003E478
    // 0x806D3D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003E478(rdram, ctx);
        goto after_9;
    // 0x806D3D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x806D3D20: b           L_806D3D34
    // 0x806D3D24: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
        goto L_806D3D34;
    // 0x806D3D24: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_806D3D28:
    // 0x806D3D28: jal         0x806D3ADC
    // 0x806D3D2C: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    func_806D3ADC(rdram, ctx);
        goto after_10;
    // 0x806D3D2C: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    after_10:
    // 0x806D3D30: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_806D3D34:
    // 0x806D3D34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806D3D38: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x806D3D3C: b           L_806D3D90
    // 0x806D3D40: swc1        $f18, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f18.u32l;
        goto L_806D3D90;
    // 0x806D3D40: swc1        $f18, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f18.u32l;
L_806D3D44:
    // 0x806D3D44: lw          $t4, 0x28($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X28);
    // 0x806D3D48: bnel        $t4, $zero, L_806D3D94
    if (ctx->r12 != 0) {
        // 0x806D3D4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D3D94;
    }
    goto skip_5;
    // 0x806D3D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x806D3D50: beq         $v0, $zero, L_806D3D90
    if (ctx->r2 == 0) {
        // 0x806D3D54: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_806D3D90;
    }
    // 0x806D3D54: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x806D3D58: lwc1        $f4, 0x84($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X84);
    // 0x806D3D5C: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806D3D60: lui         $a1, 0xBF00
    ctx->r5 = S32(0XBF00 << 16);
    // 0x806D3D64: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806D3D68: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806D3D6C: nop

    // 0x806D3D70: bc1f        L_806D3D88
    if (!c1cs) {
        // 0x806D3D74: nop
    
            goto L_806D3D88;
    }
    // 0x806D3D74: nop

    // 0x806D3D78: jal         0x806D3ADC
    // 0x806D3D7C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_806D3ADC(rdram, ctx);
        goto after_11;
    // 0x806D3D7C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_11:
    // 0x806D3D80: b           L_806D3D94
    // 0x806D3D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D3D94;
    // 0x806D3D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D3D88:
    // 0x806D3D88: jal         0x806D3ADC
    // 0x806D3D8C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_806D3ADC(rdram, ctx);
        goto after_12;
    // 0x806D3D8C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_12:
L_806D3D90:
    // 0x806D3D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D3D94:
    // 0x806D3D94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806D3D98: jr          $ra
    // 0x806D3D9C: nop

    return;
    // 0x806D3D9C: nop

;}
RECOMP_FUNC void func_805616BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805616BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805616C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805616C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805616C8: jal         0x80561804
    // 0x805616CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80561804(rdram, ctx);
        goto after_0;
    // 0x805616CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805616D0: beq         $v0, $zero, L_80561744
    if (ctx->r2 == 0) {
        // 0x805616D4: nop
    
            goto L_80561744;
    }
    // 0x805616D4: nop

    // 0x805616D8: jal         0x8056183C
    // 0x805616DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8056183C(rdram, ctx);
        goto after_1;
    // 0x805616DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805616E0: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x805616E4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x805616E8: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x805616EC: lui         $t7, 0x8056
    ctx->r15 = S32(RELOC_HI16(366, 0X22E8) << 16);
    // 0x805616F0: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x805616F4: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805616F8: addiu       $t7, $t7, 0x3738
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(366, 0X22E8));
    // 0x805616FC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80561700: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80561704: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80561708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8056170C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80561710: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80561714: jal         0x805636D0
    // 0x80561718: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805636D0(rdram, ctx);
        goto after_2;
    // 0x80561718: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8056171C: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x80561720: lui         $t9, 0x8056
    ctx->r25 = S32(RELOC_HI16(366, 0XB7C) << 16);
    // 0x80561724: addiu       $t9, $t9, 0x1FCC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(366, 0XB7C));
    // 0x80561728: lui         $t1, 0x8056
    ctx->r9 = S32(RELOC_HI16(366, 0X244) << 16);
    // 0x8056172C: addiu       $t1, $t1, 0x1694
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(366, 0X244));
    // 0x80561730: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80561734: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x80561738: sw          $t1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r9;
    // 0x8056173C: b           L_8056174C
    // 0x80561740: sh          $t2, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r10;
        goto L_8056174C;
    // 0x80561740: sh          $t2, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r10;
L_80561744:
    // 0x80561744: jal         0x800445A4
    // 0x80561748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x80561748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8056174C:
    // 0x8056174C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80561750: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80561754: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80561758: jr          $ra
    // 0x8056175C: nop

    return;
    // 0x8056175C: nop

;}
RECOMP_FUNC void func_8076C7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076C7F0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8076C7F4: addiu       $at, $zero, 0x4634
    ctx->r1 = ADD32(0, 0X4634);
    // 0x8076C7F8: beq         $v0, $at, L_8076C838
    if (ctx->r2 == ctx->r1) {
        // 0x8076C7FC: addiu       $at, $zero, 0x4635
        ctx->r1 = ADD32(0, 0X4635);
            goto L_8076C838;
    }
    // 0x8076C7FC: addiu       $at, $zero, 0x4635
    ctx->r1 = ADD32(0, 0X4635);
    // 0x8076C800: beq         $v0, $at, L_8076C820
    if (ctx->r2 == ctx->r1) {
        // 0x8076C804: addiu       $at, $zero, 0x4649
        ctx->r1 = ADD32(0, 0X4649);
            goto L_8076C820;
    }
    // 0x8076C804: addiu       $at, $zero, 0x4649
    ctx->r1 = ADD32(0, 0X4649);
    // 0x8076C808: beq         $v0, $at, L_8076C82C
    if (ctx->r2 == ctx->r1) {
        // 0x8076C80C: addiu       $at, $zero, 0x464A
        ctx->r1 = ADD32(0, 0X464A);
            goto L_8076C82C;
    }
    // 0x8076C80C: addiu       $at, $zero, 0x464A
    ctx->r1 = ADD32(0, 0X464A);
    // 0x8076C810: beq         $v0, $at, L_8076C82C
    if (ctx->r2 == ctx->r1) {
        // 0x8076C814: nop
    
            goto L_8076C82C;
    }
    // 0x8076C814: nop

    // 0x8076C818: b           L_8076C838
    // 0x8076C81C: nop

        goto L_8076C838;
    // 0x8076C81C: nop

L_8076C820:
    // 0x8076C820: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X168C) << 16);
    // 0x8076C824: jr          $ra
    // 0x8076C828: addiu       $v0, $v0, -0x2184
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X168C));
    return;
    // 0x8076C828: addiu       $v0, $v0, -0x2184
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X168C));
L_8076C82C:
    // 0x8076C82C: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X15E0) << 16);
    // 0x8076C830: jr          $ra
    // 0x8076C834: addiu       $v0, $v0, -0x2230
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X15E0));
    return;
    // 0x8076C834: addiu       $v0, $v0, -0x2230
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X15E0));
L_8076C838:
    // 0x8076C838: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X148) << 16);
    // 0x8076C83C: addiu       $v0, $v0, -0x36C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X148));
    // 0x8076C840: jr          $ra
    // 0x8076C844: nop

    return;
    // 0x8076C844: nop

;}
RECOMP_FUNC void func_8064B5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B5F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B5F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B5FC: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064B600: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064B604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B608: blez        $v0, L_8064B61C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064B60C: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_8064B61C;
    }
    // 0x8064B60C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8064B610: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064B614: b           L_8064B62C
    // 0x8064B618: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064B62C;
    // 0x8064B618: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064B61C:
    // 0x8064B61C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064B620: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064B624: jal         0x8064B918
    // 0x8064B628: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    func_8064B918(rdram, ctx);
        goto after_0;
    // 0x8064B628: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    after_0:
L_8064B62C:
    // 0x8064B62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064B630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B634: jr          $ra
    // 0x8064B638: nop

    return;
    // 0x8064B638: nop

;}
RECOMP_FUNC void func_80057C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057C9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057CA4: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80057CA8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80057CAC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80057CB0: bnel        $t6, $zero, L_80057CC4
    if (ctx->r14 != 0) {
        // 0x80057CB4: lh          $a1, 0x2($a3)
        ctx->r5 = MEM_H(ctx->r7, 0X2);
            goto L_80057CC4;
    }
    goto skip_0;
    // 0x80057CB4: lh          $a1, 0x2($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X2);
    skip_0:
    // 0x80057CB8: b           L_80057D0C
    // 0x80057CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80057D0C;
    // 0x80057CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80057CC0: lh          $a1, 0x2($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X2);
L_80057CC4:
    // 0x80057CC4: jal         0x80057BAC
    // 0x80057CC8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80057BAC(rdram, ctx);
        goto after_0;
    // 0x80057CC8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80057CCC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80057CD0: bne         $v0, $zero, L_80057CE0
    if (ctx->r2 != 0) {
        // 0x80057CD4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80057CE0;
    }
    // 0x80057CD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80057CD8: b           L_80057D0C
    // 0x80057CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80057D0C;
    // 0x80057CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057CE0:
    // 0x80057CE0: lh          $a1, 0x8($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X8);
    // 0x80057CE4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80057CE8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80057CEC: addiu       $a0, $a3, 0x2
    ctx->r4 = ADD32(ctx->r7, 0X2);
    // 0x80057CF0: jal         0x8006515C
    // 0x80057CF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8006515C(rdram, ctx);
        goto after_1;
    // 0x80057CF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80057CF8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80057CFC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80057D00: lh          $t7, 0x6($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X6);
    // 0x80057D04: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80057D08: sh          $t8, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r24;
L_80057D0C:
    // 0x80057D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057D10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80057D14: jr          $ra
    // 0x80057D18: nop

    return;
    // 0x80057D18: nop

;}
RECOMP_FUNC void func_80445C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445C4C: jr          $ra
    // 0x80445C50: nop

    return;
    // 0x80445C50: nop

;}
RECOMP_FUNC void func_8006F34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F34C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F354: jal         0x8006E7F0
    // 0x8006F358: nop

    func_8006E7F0(rdram, ctx);
        goto after_0;
    // 0x8006F358: nop

    after_0:
    // 0x8006F35C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F364: jr          $ra
    // 0x8006F368: nop

    return;
    // 0x8006F368: nop

;}
RECOMP_FUNC void func_80067BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067BFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067C04: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80067C08: jal         0x80067BBC
    // 0x80067C0C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80067C0C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80067C10: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80067C14: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067C18: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067C1C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80067C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067C28: jr          $ra
    // 0x80067C2C: nop

    return;
    // 0x80067C2C: nop

;}
RECOMP_FUNC void func_806AF64C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AF64C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AF650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AF654: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806AF658: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806AF65C: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x806AF660: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x806AF664: lui         $t7, 0x806B
    ctx->r15 = S32(RELOC_HI16(595, 0X1EFC) << 16);
    // 0x806AF668: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806AF66C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806AF670: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806AF674: lw          $t7, -0x3C4($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(595, 0X1EFC));
    // 0x806AF678: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x806AF67C: sw          $a3, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r7;
    // 0x806AF680: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x806AF684: beq         $v1, $at, L_806AF6A8
    if (ctx->r3 == ctx->r1) {
        // 0x806AF688: sw          $t7, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->r15;
            goto L_806AF6A8;
    }
    // 0x806AF688: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806AF68C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AF690: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806AF694: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x806AF698: jal         0x806ADEE0
    // 0x806AF69C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806ADEE0(rdram, ctx);
        goto after_0;
    // 0x806AF69C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AF6A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AF6A4: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
L_806AF6A8:
    // 0x806AF6A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806AF6AC: bnel        $v1, $at, L_806AF6C0
    if (ctx->r3 != ctx->r1) {
        // 0x806AF6B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806AF6C0;
    }
    goto skip_0;
    // 0x806AF6B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806AF6B4: jal         0x806ADE38
    // 0x806AF6B8: addiu       $a1, $zero, 0x283
    ctx->r5 = ADD32(0, 0X283);
    func_806ADE38(rdram, ctx);
        goto after_1;
    // 0x806AF6B8: addiu       $a1, $zero, 0x283
    ctx->r5 = ADD32(0, 0X283);
    after_1:
    // 0x806AF6BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806AF6C0:
    // 0x806AF6C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AF6C4: jr          $ra
    // 0x806AF6C8: nop

    return;
    // 0x806AF6C8: nop

    // 0x806AF6CC: nop

;}
RECOMP_FUNC void func_806D0A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0A68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D0A6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D0A70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806D0A74: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806D0A78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D0A7C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D0A80: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x806D0A84: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806D0A88: jal         0x80065ABC
    // 0x806D0A8C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x806D0A8C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    after_0:
    // 0x806D0A90: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806D0A94: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1B18) << 16);
    // 0x806D0A98: lwc1        $f4, 0x12B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1B18));
    // 0x806D0A9C: lwc1        $f2, 0xC4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806D0AA0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x806D0AA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806D0AA8: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x806D0AAC: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x806D0AB0: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x806D0AB4: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x806D0AB8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806D0ABC: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x806D0AC0: jal         0x800659EC
    // 0x806D0AC4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x806D0AC4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    after_1:
    // 0x806D0AC8: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x806D0ACC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x806D0AD0: jal         0x80066E88
    // 0x806D0AD4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x806D0AD4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    after_2:
    // 0x806D0AD8: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806D0ADC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806D0AE0: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x806D0AE4: jal         0x80066DE4
    // 0x806D0AE8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x806D0AE8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    after_3:
    // 0x806D0AEC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806D0AF0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x806D0AF4: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x806D0AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D0AFC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806D0B00: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806D0B04: jr          $ra
    // 0x806D0B08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806D0B08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806FCB38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FCB38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806FCB3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FCB40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FCB44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806FCB48: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x806FCB4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x806FCB50: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806FCB54: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806FCB58: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806FCB5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806FCB60: jal         0x80062AEC
    // 0x806FCB64: sh          $t6, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r14;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x806FCB64: sh          $t6, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r14;
    after_0:
    // 0x806FCB68: lhu         $t7, 0x22($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X22);
    // 0x806FCB6C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806FCB70: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x806FCB74: bne         $t7, $at, L_806FCCC8
    if (ctx->r15 != ctx->r1) {
        // 0x806FCB78: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_806FCCC8;
    }
    // 0x806FCB78: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x806FCB7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806FCB80: beq         $v0, $v1, L_806FCBAC
    if (ctx->r2 == ctx->r3) {
        // 0x806FCB84: lui         $at, 0x8070
        ctx->r1 = S32(RELOC_HI16(703, 0XA90) << 16);
            goto L_806FCBAC;
    }
    // 0x806FCB84: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(703, 0XA90) << 16);
    // 0x806FCB88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806FCB8C: beq         $v0, $at, L_806FCC00
    if (ctx->r2 == ctx->r1) {
        // 0x806FCB90: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_806FCC00;
    }
    // 0x806FCB90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806FCB94: beq         $v0, $at, L_806FCCC8
    if (ctx->r2 == ctx->r1) {
        // 0x806FCB98: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_806FCCC8;
    }
    // 0x806FCB98: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806FCB9C: beq         $v0, $at, L_806FCC58
    if (ctx->r2 == ctx->r1) {
        // 0x806FCBA0: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_806FCC58;
    }
    // 0x806FCBA0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x806FCBA4: b           L_806FCCCC
    // 0x806FCBA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806FCCCC;
    // 0x806FCBA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806FCBAC:
    // 0x806FCBAC: lwc1        $f4, -0x2C60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(703, 0XA90));
    // 0x806FCBB0: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806FCBB4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806FCBB8: nop

    // 0x806FCBBC: bc1fl       L_806FCBEC
    if (!c1cs) {
        // 0x806FCBC0: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806FCBEC;
    }
    goto skip_0;
    // 0x806FCBC0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x806FCBC4: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806FCBC8: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x806FCBCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806FCBD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806FCBD4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806FCBD8: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806FCBDC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806FCBE0: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x806FCBE4: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x806FCBE8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_806FCBEC:
    // 0x806FCBEC: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x806FCBF0: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x806FCBF4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x806FCBF8: b           L_806FCCC8
    // 0x806FCBFC: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
        goto L_806FCCC8;
    // 0x806FCBFC: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_806FCC00:
    // 0x806FCC00: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(703, 0XA94) << 16);
    // 0x806FCC04: lwc1        $f16, -0x2C5C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(703, 0XA94));
    // 0x806FCC08: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806FCC0C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806FCC10: nop

    // 0x806FCC14: bc1fl       L_806FCC44
    if (!c1cs) {
        // 0x806FCC18: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806FCC44;
    }
    goto skip_1;
    // 0x806FCC18: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x806FCC1C: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x806FCC20: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806FCC24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806FCC28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806FCC2C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x806FCC30: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806FCC34: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x806FCC38: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806FCC3C: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x806FCC40: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_806FCC44:
    // 0x806FCC44: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x806FCC48: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x806FCC4C: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x806FCC50: b           L_806FCCC8
    // 0x806FCC54: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
        goto L_806FCCC8;
    // 0x806FCC54: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
L_806FCC58:
    // 0x806FCC58: lw          $v0, 0x1F4($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X1F4);
    // 0x806FCC5C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x806FCC60: bnel        $t3, $zero, L_806FCCCC
    if (ctx->r11 != 0) {
        // 0x806FCC64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806FCCCC;
    }
    goto skip_2;
    // 0x806FCC64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806FCC68: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806FCC6C: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806FCC70: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(703, 0XA98) << 16);
    // 0x806FCC74: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x806FCC78: nop

    // 0x806FCC7C: bc1tl       L_806FCCCC
    if (c1cs) {
        // 0x806FCC80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806FCCCC;
    }
    goto skip_3;
    // 0x806FCC80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806FCC84: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x806FCC88: lwc1        $f10, -0x2C58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(703, 0XA98));
    // 0x806FCC8C: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806FCC90: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806FCC94: nop

    // 0x806FCC98: bc1fl       L_806FCCBC
    if (!c1cs) {
        // 0x806FCC9C: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806FCCBC;
    }
    goto skip_4;
    // 0x806FCC9C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_4:
    // 0x806FCCA0: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806FCCA4: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806FCCA8: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806FCCAC: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806FCCB0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x806FCCB4: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x806FCCB8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_806FCCBC:
    // 0x806FCCBC: lw          $t4, 0x34($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X34);
    // 0x806FCCC0: ori         $t5, $t4, 0x3000
    ctx->r13 = ctx->r12 | 0X3000;
    // 0x806FCCC4: sw          $t5, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r13;
L_806FCCC8:
    // 0x806FCCC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806FCCCC:
    // 0x806FCCCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FCCD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806FCCD4: jr          $ra
    // 0x806FCCD8: nop

    return;
    // 0x806FCCD8: nop

;}
RECOMP_FUNC void func_8042E428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E428: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042E42C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E430: jal         0x80081E8C
    // 0x8042E434: nop

    fatan2(rdram, ctx);
        goto after_0;
    // 0x8042E434: nop

    after_0:
    // 0x8042E438: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8042E43C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8042E440: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8042E444: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042E448: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3B80) << 16);
    // 0x8042E44C: lwc1        $f8, 0x1C60($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3B80));
    // 0x8042E450: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8042E454: ori         $at, $zero, 0x8CA0
    ctx->r1 = 0 | 0X8CA0;
    // 0x8042E458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042E45C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042E460: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8042E464: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8042E468: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8042E46C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8042E470: nop

    // 0x8042E474: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x8042E478: mfhi        $t8
    ctx->r24 = hi;
    // 0x8042E47C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8042E480: nop

    // 0x8042E484: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042E488: jr          $ra
    // 0x8042E48C: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    return;
    // 0x8042E48C: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
;}
RECOMP_FUNC void func_8044448C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044448C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80444490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80444494: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80444498: jal         0x80444408
    // 0x8044449C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x8044449C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x804444A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804444A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804444A8: jr          $ra
    // 0x804444AC: nop

    return;
    // 0x804444AC: nop

;}
RECOMP_FUNC void func_805DA724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA724: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805DA728: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DA72C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DA730: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DA734: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805DA738: jal         0x805DA4E0
    // 0x805DA73C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_805DA4E0(rdram, ctx);
        goto after_0;
    // 0x805DA73C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x805DA740: bnel        $v0, $zero, L_805DA7A8
    if (ctx->r2 != 0) {
        // 0x805DA744: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DA7A8;
    }
    goto skip_0;
    // 0x805DA744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805DA748: jal         0x805DA464
    // 0x805DA74C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DA464(rdram, ctx);
        goto after_1;
    // 0x805DA74C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805DA750: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805DA754: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x805DA758: blez        $v0, L_805DA768
    if (SIGNED(ctx->r2) <= 0) {
        // 0x805DA75C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_805DA768;
    }
    // 0x805DA75C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x805DA760: b           L_805DA7A4
    // 0x805DA764: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
        goto L_805DA7A4;
    // 0x805DA764: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
L_805DA768:
    // 0x805DA768: jal         0x805DA164
    // 0x805DA76C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DA164(rdram, ctx);
        goto after_2;
    // 0x805DA76C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805DA770: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805DA774: jal         0x80067BBC
    // 0x805DA778: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x805DA778: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x805DA77C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x805DA780: jal         0x80067818
    // 0x805DA784: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x805DA784: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x805DA788: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805DA78C: sb          $t8, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r24;
    // 0x805DA790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DA794: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DA798: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805DA79C: jal         0x805DAA20
    // 0x805DA7A0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805DAA20(rdram, ctx);
        goto after_5;
    // 0x805DA7A0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
L_805DA7A4:
    // 0x805DA7A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DA7A8:
    // 0x805DA7A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DA7AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805DA7B0: jr          $ra
    // 0x805DA7B4: nop

    return;
    // 0x805DA7B4: nop

;}
RECOMP_FUNC void func_804386F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804386F4: jr          $ra
    // 0x804386F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804386F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804301BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804301BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804301C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804301C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804301C8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BD8) << 16);
    // 0x804301CC: lwc1        $f0, 0x1CB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BD8));
    // 0x804301D0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BDC) << 16);
    // 0x804301D4: lwc1        $f6, 0x1CBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BDC));
    // 0x804301D8: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x804301DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804301E0: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x804301E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804301E8: lwc1        $f12, 0x1C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x804301EC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x804301F0: nop

    // 0x804301F4: bc1f        L_80430208
    if (!c1cs) {
        // 0x804301F8: nop
    
            goto L_80430208;
    }
    // 0x804301F8: nop

    // 0x804301FC: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80430200: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430204: lwc1        $f12, 0x1C($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X1C);
L_80430208:
    // 0x80430208: jal         0x80082730
    // 0x8043020C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fsin(rdram, ctx);
        goto after_0;
    // 0x8043020C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80430210: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BE0) << 16);
    // 0x80430214: lwc1        $f10, 0x1CC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BE0));
    // 0x80430218: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043021C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80430220: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80430224: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80430228: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043022C: lwc1        $f12, 0x1C($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80430230: jal         0x8008D250
    // 0x80430234: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80430234: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80430238: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BE4) << 16);
    // 0x8043023C: lwc1        $f18, 0x1CC4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BE4));
    // 0x80430240: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80430244: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80430248: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8043024C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BE8) << 16);
    // 0x80430250: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80430254: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430258: lwc1        $f8, 0x1CC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BE8));
    // 0x8043025C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80430260: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80430264: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80430268: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BEC) << 16);
    // 0x8043026C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80430270: lwc1        $f4, 0x1CCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BEC));
    // 0x80430274: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BF0) << 16);
    // 0x80430278: lwc1        $f8, 0x1CD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BF0));
    // 0x8043027C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80430280: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80430284: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80430288: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x8043028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80430290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80430294: jr          $ra
    // 0x80430298: nop

    return;
    // 0x80430298: nop

;}
RECOMP_FUNC void func_807AC6D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC6D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807AC6DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AC6E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AC6E4: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x807AC6E8: nop

    // 0x807AC6EC: bc1fl       L_807AC700
    if (!c1cs) {
        // 0x807AC6F0: swc1        $f12, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
            goto L_807AC700;
    }
    goto skip_0;
    // 0x807AC6F0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x807AC6F4: b           L_807AC724
    // 0x807AC6F8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_807AC724;
    // 0x807AC6F8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x807AC6FC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
L_807AC700:
    // 0x807AC700: jal         0x80065414
    // 0x807AC704: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80065414(rdram, ctx);
        goto after_0;
    // 0x807AC704: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x807AC708: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x807AC70C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807AC710: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807AC714: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x807AC718: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x807AC71C: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x807AC720: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
L_807AC724:
    // 0x807AC724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AC728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AC72C: jr          $ra
    // 0x807AC730: nop

    return;
    // 0x807AC730: nop

;}
RECOMP_FUNC void func_804F4F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F4F50: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804F4F54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804F4F58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804F4F5C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x804F4F60: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F4F64: jal         0x804F4CF8
    // 0x804F4F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804F4CF8(rdram, ctx);
        goto after_0;
    // 0x804F4F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x804F4F6C: bne         $v0, $zero, L_804F5030
    if (ctx->r2 != 0) {
        // 0x804F4F70: addiu       $a0, $s0, 0x68
        ctx->r4 = ADD32(ctx->r16, 0X68);
            goto L_804F5030;
    }
    // 0x804F4F70: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x804F4F74: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x804F4F78: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x804F4F7C: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X20800) << 16);
    // 0x804F4F80: addiu       $t8, $t7, 0x6
    ctx->r24 = ADD32(ctx->r15, 0X6);
    // 0x804F4F84: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x804F4F88: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x804F4F8C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x804F4F90: addiu       $a1, $a1, 0x4A90
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X20800));
    // 0x804F4F94: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x804F4F98: sw          $t0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r8;
    // 0x804F4F9C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x804F4FA0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x804F4FA4: lbu         $t2, 0x30($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X30);
    // 0x804F4FA8: beql        $t2, $at, L_804F4FB8
    if (ctx->r10 == ctx->r1) {
        // 0x804F4FAC: lw          $t4, 0x14($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X14);
            goto L_804F4FB8;
    }
    goto skip_0;
    // 0x804F4FAC: lw          $t4, 0x14($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X14);
    skip_0:
    // 0x804F4FB0: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x804F4FB4: lw          $t4, 0x14($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X14);
L_804F4FB8:
    // 0x804F4FB8: blez        $t4, L_804F4FDC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x804F4FBC: nop
    
            goto L_804F4FDC;
    }
    // 0x804F4FBC: nop

    // 0x804F4FC0: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X20818) << 16);
    // 0x804F4FC4: addiu       $a1, $a1, 0x4AA8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X20818));
    // 0x804F4FC8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x804F4FCC: jal         0x804F4C88
    // 0x804F4FD0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_804F4C88(rdram, ctx);
        goto after_1;
    // 0x804F4FD0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x804F4FD4: b           L_804F4FF8
    // 0x804F4FD8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
        goto L_804F4FF8;
    // 0x804F4FD8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_804F4FDC:
    // 0x804F4FDC: jal         0x804F4C88
    // 0x804F4FE0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_804F4C88(rdram, ctx);
        goto after_2;
    // 0x804F4FE0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x804F4FE4: jal         0x800653D8
    // 0x804F4FE8: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x804F4FE8: nop

    after_3:
    // 0x804F4FEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804F4FF0: andi        $t5, $v0, 0x7
    ctx->r13 = ctx->r2 & 0X7;
    // 0x804F4FF4: sw          $t5, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r13;
L_804F4FF8:
    // 0x804F4FF8: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x804F4FFC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804F5000: lui         $t1, 0x8051
    ctx->r9 = S32(RELOC_HI16(273, 0X207AC) << 16);
    // 0x804F5004: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804F5008: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x804F500C: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x804F5010: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x804F5014: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x804F5018: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x804F501C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804F5020: lhu         $t1, 0x4A3C($t1)
    ctx->r9 = MEM_HU(ctx->r9, (int16_t)RELOC_LO16(273, 0X207AC));
    // 0x804F5024: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x804F5028: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x804F502C: sw          $t3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r11;
L_804F5030:
    // 0x804F5030: jal         0x804F4D88
    // 0x804F5034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804F4D88(rdram, ctx);
        goto after_4;
    // 0x804F5034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804F5038: bne         $v0, $zero, L_804F5118
    if (ctx->r2 != 0) {
        // 0x804F503C: addiu       $a0, $s0, 0x80
        ctx->r4 = ADD32(ctx->r16, 0X80);
            goto L_804F5118;
    }
    // 0x804F503C: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    // 0x804F5040: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x804F5044: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x804F5048: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X20830) << 16);
    // 0x804F504C: addiu       $t4, $v0, 0xC
    ctx->r12 = ADD32(ctx->r2, 0XC);
    // 0x804F5050: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x804F5054: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x804F5058: lw          $t5, 0x94($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X94);
    // 0x804F505C: addiu       $a1, $a1, 0x4AC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X20830));
    // 0x804F5060: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x804F5064: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x804F5068: sw          $t7, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r15;
    // 0x804F506C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x804F5070: lbu         $t8, 0x30($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X30);
    // 0x804F5074: bnel        $t8, $at, L_804F5084
    if (ctx->r24 != ctx->r1) {
        // 0x804F5078: lw          $t9, 0x14($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X14);
            goto L_804F5084;
    }
    goto skip_1;
    // 0x804F5078: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    skip_1:
    // 0x804F507C: sw          $zero, 0x94($s0)
    MEM_W(0X94, ctx->r16) = 0;
    // 0x804F5080: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
L_804F5084:
    // 0x804F5084: blez        $t9, L_804F50A8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x804F5088: nop
    
            goto L_804F50A8;
    }
    // 0x804F5088: nop

    // 0x804F508C: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X20840) << 16);
    // 0x804F5090: addiu       $a1, $a1, 0x4AD0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X20840));
    // 0x804F5094: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x804F5098: jal         0x804F4C88
    // 0x804F509C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_804F4C88(rdram, ctx);
        goto after_5;
    // 0x804F509C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_5:
    // 0x804F50A0: b           L_804F50C4
    // 0x804F50A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
        goto L_804F50C4;
    // 0x804F50A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_804F50A8:
    // 0x804F50A8: jal         0x804F4C88
    // 0x804F50AC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_804F4C88(rdram, ctx);
        goto after_6;
    // 0x804F50AC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_6:
    // 0x804F50B0: jal         0x800653D8
    // 0x804F50B4: nop

    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x804F50B4: nop

    after_7:
    // 0x804F50B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804F50BC: andi        $t0, $v0, 0x7
    ctx->r8 = ctx->r2 & 0X7;
    // 0x804F50C0: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_804F50C4:
    // 0x804F50C4: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x804F50C8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x804F50CC: lui         $t7, 0x8051
    ctx->r15 = S32(RELOC_HI16(273, 0X207BC) << 16);
    // 0x804F50D0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x804F50D4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804F50D8: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x804F50DC: lui         $t0, 0x8051
    ctx->r8 = S32(RELOC_HI16(273, 0X207B4) << 16);
    // 0x804F50E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x804F50E4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x804F50E8: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x804F50EC: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x804F50F0: lhu         $t7, 0x4A4C($t7)
    ctx->r15 = MEM_HU(ctx->r15, (int16_t)RELOC_LO16(273, 0X207BC));
    // 0x804F50F4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x804F50F8: sh          $t7, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r15;
    // 0x804F50FC: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x804F5100: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x804F5104: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x804F5108: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804F510C: lhu         $t0, 0x4A44($t0)
    ctx->r8 = MEM_HU(ctx->r8, (int16_t)RELOC_LO16(273, 0X207B4));
    // 0x804F5110: sh          $t0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r8;
    // 0x804F5114: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
L_804F5118:
    // 0x804F5118: jal         0x804F4E30
    // 0x804F511C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804F4E30(rdram, ctx);
        goto after_8;
    // 0x804F511C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x804F5120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804F5124: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804F5128: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x804F512C: jr          $ra
    // 0x804F5130: nop

    return;
    // 0x804F5130: nop

;}
RECOMP_FUNC void func_806E7140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7140: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(661, 0X18) << 16);
    // 0x806E7144: addiu       $v0, $v0, 0x7158
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(661, 0X18));
    // 0x806E7148: jr          $ra
    // 0x806E714C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806E714C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80523274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80523274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80523278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052327C: jal         0x80522AD4
    // 0x80523280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80522AD4(rdram, ctx);
        goto after_0;
    // 0x80523280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80523284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80523288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052328C: jr          $ra
    // 0x80523290: nop

    return;
    // 0x80523290: nop

;}
RECOMP_FUNC void func_80531924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531924: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80531928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8053192C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80531930: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80531934: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80531938: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8053193C: lw          $a0, 0x264($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X264);
    // 0x80531940: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80531944: jal         0x800443EC
    // 0x80531948: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800443EC(rdram, ctx);
        goto after_0;
    // 0x80531948: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8053194C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80531950: bne         $v0, $zero, L_80531960
    if (ctx->r2 != 0) {
        // 0x80531954: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80531960;
    }
    // 0x80531954: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80531958: b           L_805319E4
    // 0x8053195C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805319E4;
    // 0x8053195C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80531960:
    // 0x80531960: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A04) << 16);
    // 0x80531964: lwc1        $f0, 0x27F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A04));
    // 0x80531968: lwc1        $f4, 0x78($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X78);
    // 0x8053196C: lwc1        $f8, 0x7C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X7C);
    // 0x80531970: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A08) << 16);
    // 0x80531974: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80531978: addiu       $a0, $a2, 0x84
    ctx->r4 = ADD32(ctx->r6, 0X84);
    // 0x8053197C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80531980: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80531984: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
    // 0x80531988: swc1        $f10, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f10.u32l;
    // 0x8053198C: lwc1        $f16, 0x84($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80531990: swc1        $f16, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f16.u32l;
    // 0x80531994: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80531998: swc1        $f18, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f18.u32l;
    // 0x8053199C: lwc1        $f6, 0x27F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A08));
    // 0x805319A0: lwc1        $f4, 0x8C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x805319A4: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
    // 0x805319A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805319AC: jal         0x80047AB8
    // 0x805319B0: swc1        $f8, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f8.u32l;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x805319B0: swc1        $f8, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x805319B4: sw          $zero, 0x264($s0)
    MEM_W(0X264, ctx->r16) = 0;
    // 0x805319B8: addiu       $a0, $zero, 0x1F5
    ctx->r4 = ADD32(0, 0X1F5);
    // 0x805319BC: jal         0x80067818
    // 0x805319C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x805319C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x805319C4: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A0C) << 16);
    // 0x805319C8: lwc1        $f10, 0x27FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A0C));
    // 0x805319CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x805319D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805319D4: swc1        $f10, 0x274($s0)
    MEM_W(0X274, ctx->r16) = ctx->f10.u32l;
    // 0x805319D8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x805319DC: swc1        $f18, 0x26C($s0)
    MEM_W(0X26C, ctx->r16) = ctx->f18.u32l;
    // 0x805319E0: swc1        $f16, 0x270($s0)
    MEM_W(0X270, ctx->r16) = ctx->f16.u32l;
L_805319E4:
    // 0x805319E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805319E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805319EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805319F0: jr          $ra
    // 0x805319F4: nop

    return;
    // 0x805319F4: nop

;}
RECOMP_FUNC void func_80475000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475000: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475004: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475008: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047500C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475010: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475014: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475018: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047501C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475020: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475024: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475028: jr          $ra
    // 0x8047502C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047502C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80475750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475750: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475754: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475758: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047575C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475760: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475764: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475768: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047576C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475770: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475774: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475778: jr          $ra
    // 0x8047577C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047577C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80739A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80739A40: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80739A44: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80739A48: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80739A4C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80739A50: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80739A54: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80739A58: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80739A5C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80739A60: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80739A64: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80739A68: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80739A6C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80739A70: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x80739A74: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x80739A78: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80739A7C: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x80739A80: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80739A84: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80739A88: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80739A8C: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80739A90: lw          $t9, 0x1E0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1E0);
    // 0x80739A94: lw          $t7, 0x1E4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E4);
    // 0x80739A98: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80739A9C: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80739AA0: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x80739AA4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80739AA8: lh          $t0, 0x144($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X144);
    // 0x80739AAC: lh          $t1, 0x14A($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X14A);
    // 0x80739AB0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x80739AB4: bne         $at, $zero, L_80739AD8
    if (ctx->r1 != 0) {
        // 0x80739AB8: sw          $t8, 0x1E4($a0)
        MEM_W(0X1E4, ctx->r4) = ctx->r24;
            goto L_80739AD8;
    }
    // 0x80739AB8: sw          $t8, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r24;
    // 0x80739ABC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80739AC0: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x80739AC4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80739AC8: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80739ACC: bne         $at, $zero, L_80739AD8
    if (ctx->r1 != 0) {
        // 0x80739AD0: sw          $t7, 0x8($a3)
        MEM_W(0X8, ctx->r7) = ctx->r15;
            goto L_80739AD8;
    }
    // 0x80739AD0: sw          $t7, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r15;
    // 0x80739AD4: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_80739AD8:
    // 0x80739AD8: lw          $t9, 0x1E4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1E4);
    // 0x80739ADC: ori         $t4, $zero, 0x8700
    ctx->r12 = 0 | 0X8700;
    // 0x80739AE0: lui         $s7, 0xE700
    ctx->r23 = S32(0XE700 << 16);
    // 0x80739AE4: slti        $at, $t9, 0x37
    ctx->r1 = SIGNED(ctx->r25) < 0X37 ? 1 : 0;
    // 0x80739AE8: bne         $at, $zero, L_80739AFC
    if (ctx->r1 != 0) {
        // 0x80739AEC: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_80739AFC;
    }
    // 0x80739AEC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80739AF0: sw          $zero, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = 0;
    // 0x80739AF4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80739AF8: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
L_80739AFC:
    // 0x80739AFC: lh          $a1, 0xA($a3)
    ctx->r5 = MEM_H(ctx->r7, 0XA);
    // 0x80739B00: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80739B04: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739B08: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x80739B0C: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x80739B10: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80739B14: andi        $t7, $t0, 0xFF
    ctx->r15 = ctx->r8 & 0XFF;
    // 0x80739B18: multu       $t7, $t4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80739B1C: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80739B20: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x80739B24: lw          $t2, 0x80($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X80);
    // 0x80739B28: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80739B2C: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x80739B30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739B34: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739B38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80739B3C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739B40: mflo        $t8
    ctx->r24 = lo;
    // 0x80739B44: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80739B48: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80739B4C: multu       $t6, $t4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80739B50: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x80739B54: ori         $t9, $t9, 0x18
    ctx->r25 = ctx->r25 | 0X18;
    // 0x80739B58: lui         $t6, 0x18
    ctx->r14 = S32(0X18 << 16);
    // 0x80739B5C: ori         $t6, $t6, 0x2CF0
    ctx->r14 = ctx->r14 | 0X2CF0;
    // 0x80739B60: lui         $t0, 0xC18
    ctx->r8 = S32(0XC18 << 16);
    // 0x80739B64: ori         $t0, $t0, 0x4340
    ctx->r8 = ctx->r8 | 0X4340;
    // 0x80739B68: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80739B6C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739B70: lui         $s6, 0xF588
    ctx->r22 = S32(0XF588 << 16);
    // 0x80739B74: mflo        $t7
    ctx->r15 = lo;
    // 0x80739B78: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x80739B7C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80739B80: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x80739B84: sw          $s7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r23;
    // 0x80739B88: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80739B8C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80739B90: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80739B94: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x80739B98: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80739B9C: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x80739BA0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80739BA4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80739BA8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80739BAC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80739BB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739BB4: lui         $t9, 0xFC16
    ctx->r25 = S32(0XFC16 << 16);
    // 0x80739BB8: ori         $t9, $t9, 0x1A60
    ctx->r25 = ctx->r25 | 0X1A60;
    // 0x80739BBC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739BC0: lui         $t6, 0x25FD
    ctx->r14 = S32(0X25FD << 16);
    // 0x80739BC4: ori         $t6, $t6, 0x2578
    ctx->r14 = ctx->r14 | 0X2578;
    // 0x80739BC8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80739BCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80739BD0: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80739BD4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739BD8: addiu       $t8, $zero, 0x204
    ctx->r24 = ADD32(0, 0X204);
    // 0x80739BDC: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x80739BE0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80739BE4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80739BE8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80739BEC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80739BF0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80739BF4: lbu         $t9, 0xD($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XD);
    // 0x80739BF8: lbu         $t7, 0x10($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X10);
    // 0x80739BFC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739C00: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x80739C04: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80739C08: lbu         $t7, 0xE($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XE);
    // 0x80739C0C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80739C10: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739C14: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80739C18: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80739C1C: lbu         $t8, 0xF($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF);
    // 0x80739C20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739C24: lui         $s4, 0x708
    ctx->r20 = S32(0X708 << 16);
    // 0x80739C28: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x80739C2C: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80739C30: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80739C34: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80739C38: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80739C3C: lbu         $t8, 0x11($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X11);
    // 0x80739C40: lbu         $t6, 0x10($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X10);
    // 0x80739C44: lui         $s3, 0xF588
    ctx->r19 = S32(0XF588 << 16);
    // 0x80739C48: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80739C4C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80739C50: lbu         $t6, 0x12($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X12);
    // 0x80739C54: lui         $s2, 0xFD88
    ctx->r18 = S32(0XFD88 << 16);
    // 0x80739C58: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739C5C: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80739C60: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80739C64: lbu         $t7, 0x13($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X13);
    // 0x80739C68: ori         $s2, $s2, 0xD7
    ctx->r18 = ctx->r18 | 0XD7;
    // 0x80739C6C: ori         $s3, $s3, 0x3600
    ctx->r19 = ctx->r19 | 0X3600;
    // 0x80739C70: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x80739C74: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80739C78: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80739C7C: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80739C80: ori         $t7, $t7, 0x595F
    ctx->r15 = ctx->r15 | 0X595F;
    // 0x80739C84: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80739C88: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x80739C8C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80739C90: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(739, 0X1F68) << 16);
    // 0x80739C94: addiu       $t1, $t8, -0x4668
    ctx->r9 = ADD32(ctx->r24, (int16_t)RELOC_LO16(739, 0X1F68));
    // 0x80739C98: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80739C9C: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80739CA0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80739CA4: addu        $fp, $t6, $t1
    ctx->r30 = ADD32(ctx->r14, ctx->r9);
    // 0x80739CA8: ori         $s4, $s4, 0x200
    ctx->r20 = ctx->r20 | 0X200;
    // 0x80739CAC: ori         $s6, $s6, 0x3700
    ctx->r22 = ctx->r22 | 0X3700;
    // 0x80739CB0: lui         $ra, 0xF400
    ctx->r31 = S32(0XF400 << 16);
    // 0x80739CB4: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
L_80739CB8:
    // 0x80739CB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80739CBC: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x80739CC0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80739CC4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739CC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739CCC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739CD0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80739CD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80739CD8: sw          $s4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r20;
    // 0x80739CDC: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x80739CE0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739CE4: addiu       $t0, $s1, 0x7
    ctx->r8 = ADD32(ctx->r17, 0X7);
    // 0x80739CE8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80739CEC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80739CF0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80739CF4: sw          $s5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r21;
    // 0x80739CF8: sll         $a3, $s1, 2
    ctx->r7 = S32(ctx->r17 << 2);
    // 0x80739CFC: lui         $at, 0x735
    ctx->r1 = S32(0X735 << 16);
    // 0x80739D00: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80739D04: andi        $a3, $a3, 0xFFF
    ctx->r7 = ctx->r7 & 0XFFF;
    // 0x80739D08: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739D0C: andi        $t0, $t0, 0xFFF
    ctx->r8 = ctx->r8 & 0XFFF;
    // 0x80739D10: or          $t3, $t0, $at
    ctx->r11 = ctx->r8 | ctx->r1;
    // 0x80739D14: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x80739D18: or          $t2, $a3, $ra
    ctx->r10 = ctx->r7 | ctx->r31;
    // 0x80739D1C: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80739D20: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739D24: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x80739D28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80739D2C: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80739D30: or          $t4, $a3, $at
    ctx->r12 = ctx->r7 | ctx->r1;
    // 0x80739D34: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739D38: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80739D3C: sw          $s7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r23;
    // 0x80739D40: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80739D44: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80739D48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739D4C: lui         $at, 0x35
    ctx->r1 = S32(0X35 << 16);
    // 0x80739D50: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80739D54: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80739D58: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x80739D5C: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x80739D60: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739D64: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80739D68: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80739D6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80739D70: sw          $s2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r18;
    // 0x80739D74: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80739D78: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739D7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80739D80: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80739D84: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739D88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80739D8C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739D90: sw          $s4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r20;
    // 0x80739D94: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x80739D98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739D9C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80739DA0: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x80739DA4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739DA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80739DAC: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x80739DB0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80739DB4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739DB8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80739DBC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739DC0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80739DC4: sw          $s7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r23;
    // 0x80739DC8: lui         $t7, 0x108
    ctx->r15 = S32(0X108 << 16);
    // 0x80739DCC: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80739DD0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80739DD4: lui         $at, 0x135
    ctx->r1 = S32(0X135 << 16);
    // 0x80739DD8: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80739DDC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80739DE0: sw          $s6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r22;
    // 0x80739DE4: or          $t9, $t0, $at
    ctx->r25 = ctx->r8 | ctx->r1;
    // 0x80739DE8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739DEC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80739DF0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80739DF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739DF8: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80739DFC: addiu       $t1, $t1, 0x18
    ctx->r9 = ADD32(ctx->r9, 0X18);
    // 0x80739E00: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80739E04: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80739E08: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739E0C: bne         $t1, $fp, L_80739CB8
    if (ctx->r9 != ctx->r30) {
        // 0x80739E10: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80739CB8;
    }
    // 0x80739E10: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80739E14: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80739E18: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80739E1C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80739E20: addiu       $t7, $t8, 0x4380
    ctx->r15 = ADD32(ctx->r24, 0X4380);
    // 0x80739E24: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x80739E28: addiu       $t6, $t9, 0x4380
    ctx->r14 = ADD32(ctx->r25, 0X4380);
    // 0x80739E2C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80739E30: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80739E34: ori         $t8, $t8, 0x595F
    ctx->r24 = ctx->r24 | 0X595F;
    // 0x80739E38: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80739E3C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80739E40: lui         $t9, 0x8074
    ctx->r25 = S32(RELOC_HI16(739, 0X2058) << 16);
    // 0x80739E44: lui         $s2, 0xFD88
    ctx->r18 = S32(0XFD88 << 16);
    // 0x80739E48: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80739E4C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80739E50: lui         $s3, 0xF588
    ctx->r19 = S32(0XF588 << 16);
    // 0x80739E54: lui         $s4, 0x708
    ctx->r20 = S32(0X708 << 16);
    // 0x80739E58: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80739E5C: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80739E60: lui         $s6, 0xF588
    ctx->r22 = S32(0XF588 << 16);
    // 0x80739E64: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80739E68: addiu       $t1, $t9, -0x4578
    ctx->r9 = ADD32(ctx->r25, (int16_t)RELOC_LO16(739, 0X2058));
    // 0x80739E6C: ori         $s6, $s6, 0x3700
    ctx->r22 = ctx->r22 | 0X3700;
    // 0x80739E70: ori         $s4, $s4, 0x200
    ctx->r20 = ctx->r20 | 0X200;
    // 0x80739E74: ori         $s3, $s3, 0x3600
    ctx->r19 = ctx->r19 | 0X3600;
    // 0x80739E78: ori         $s2, $s2, 0xD7
    ctx->r18 = ctx->r18 | 0XD7;
    // 0x80739E7C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80739E80: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
    // 0x80739E84: lui         $ra, 0xF400
    ctx->r31 = S32(0XF400 << 16);
    // 0x80739E88: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739E8C: addu        $fp, $t8, $t1
    ctx->r30 = ADD32(ctx->r24, ctx->r9);
L_80739E90:
    // 0x80739E90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80739E94: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x80739E98: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80739E9C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739EA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739EA4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739EA8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80739EAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80739EB0: sw          $s4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r20;
    // 0x80739EB4: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
    // 0x80739EB8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739EBC: addiu       $t0, $s1, 0x7
    ctx->r8 = ADD32(ctx->r17, 0X7);
    // 0x80739EC0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80739EC4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80739EC8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80739ECC: sw          $s5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r21;
    // 0x80739ED0: sll         $a3, $s1, 2
    ctx->r7 = S32(ctx->r17 << 2);
    // 0x80739ED4: lui         $at, 0x735
    ctx->r1 = S32(0X735 << 16);
    // 0x80739ED8: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80739EDC: andi        $a3, $a3, 0xFFF
    ctx->r7 = ctx->r7 & 0XFFF;
    // 0x80739EE0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739EE4: andi        $t0, $t0, 0xFFF
    ctx->r8 = ctx->r8 & 0XFFF;
    // 0x80739EE8: or          $t3, $t0, $at
    ctx->r11 = ctx->r8 | ctx->r1;
    // 0x80739EEC: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x80739EF0: or          $t2, $a3, $ra
    ctx->r10 = ctx->r7 | ctx->r31;
    // 0x80739EF4: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80739EF8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739EFC: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x80739F00: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80739F04: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80739F08: or          $t4, $a3, $at
    ctx->r12 = ctx->r7 | ctx->r1;
    // 0x80739F0C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739F10: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80739F14: sw          $s7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r23;
    // 0x80739F18: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x80739F1C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80739F20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739F24: lui         $at, 0x35
    ctx->r1 = S32(0X35 << 16);
    // 0x80739F28: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80739F2C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80739F30: sw          $s3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r19;
    // 0x80739F34: or          $t8, $t0, $at
    ctx->r24 = ctx->r8 | ctx->r1;
    // 0x80739F38: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739F3C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80739F40: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80739F44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80739F48: sw          $s2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r18;
    // 0x80739F4C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80739F50: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739F54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80739F58: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80739F5C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739F60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80739F64: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739F68: sw          $s4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r20;
    // 0x80739F6C: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x80739F70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739F74: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80739F78: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x80739F7C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739F80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80739F84: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x80739F88: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80739F8C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739F90: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80739F94: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739F98: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80739F9C: sw          $s7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r23;
    // 0x80739FA0: lui         $t7, 0x108
    ctx->r15 = S32(0X108 << 16);
    // 0x80739FA4: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80739FA8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80739FAC: lui         $at, 0x135
    ctx->r1 = S32(0X135 << 16);
    // 0x80739FB0: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x80739FB4: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80739FB8: sw          $s6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r22;
    // 0x80739FBC: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x80739FC0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739FC4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80739FC8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80739FCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80739FD0: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80739FD4: addiu       $t1, $t1, 0x18
    ctx->r9 = ADD32(ctx->r9, 0X18);
    // 0x80739FD8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80739FDC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80739FE0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80739FE4: bne         $t1, $fp, L_80739E90
    if (ctx->r9 != ctx->r30) {
        // 0x80739FE8: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80739E90;
    }
    // 0x80739FE8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80739FEC: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80739FF0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80739FF4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80739FF8: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80739FFC: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8073A000: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8073A004: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8073A008: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8073A00C: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8073A010: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8073A014: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8073A018: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8073A01C: jr          $ra
    // 0x8073A020: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8073A020: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80046DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046DEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046DF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046DF8: bne         $a0, $at, L_80046E08
    if (ctx->r4 != ctx->r1) {
        // 0x80046DFC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80046E08;
    }
    // 0x80046DFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80046E00: b           L_80046E18
    // 0x80046E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046E18;
    // 0x80046E04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046E08:
    // 0x80046E08: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80046E0C: addiu       $a0, $a0, 0x6DC8
    ctx->r4 = ADD32(ctx->r4, 0X6DC8);
    // 0x80046E10: jal         0x80046D2C
    // 0x80046E14: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_80046D2C(rdram, ctx);
        goto after_0;
    // 0x80046E14: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
L_80046E18:
    // 0x80046E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046E20: jr          $ra
    // 0x80046E24: nop

    return;
    // 0x80046E24: nop

;}
RECOMP_FUNC void func_80432608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432608: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8043260C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80432610: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80432614: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80432618: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8043261C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80432620: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80432624: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80432628: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8043262C: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x80432630: sb          $s0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r16;
    // 0x80432634: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80432638: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8043263C: jal         0x804326C4
    // 0x80432640: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804326C4(rdram, ctx);
        goto after_0;
    // 0x80432640: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80432644: sw          $zero, 0x130($s3)
    MEM_W(0X130, ctx->r19) = 0;
    // 0x80432648: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043264C: sb          $s0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r16;
    // 0x80432650: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80432654: jal         0x80045A34
    // 0x80432658: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80432658: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_1:
    // 0x8043265C: sw          $v0, 0x1F4($s3)
    MEM_W(0X1F4, ctx->r19) = ctx->r2;
    // 0x80432660: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80432664: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80432668: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8043266C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80432670: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80432674: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80432678: addiu       $s4, $zero, 0x28
    ctx->r20 = ADD32(0, 0X28);
L_8043267C:
    // 0x8043267C: jal         0x80432588
    // 0x80432680: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80432588(rdram, ctx);
        goto after_2;
    // 0x80432680: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x80432684: beq         $v0, $zero, L_80432698
    if (ctx->r2 == 0) {
        // 0x80432688: sw          $v0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r2;
            goto L_80432698;
    }
    // 0x80432688: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x8043268C: lw          $t6, 0x4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X4);
    // 0x80432690: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80432694: sw          $t7, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r15;
L_80432698:
    // 0x80432698: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8043269C: bne         $s0, $s4, L_8043267C
    if (ctx->r16 != ctx->r20) {
        // 0x804326A0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8043267C;
    }
    // 0x804326A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x804326A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x804326A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804326AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804326B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x804326B4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x804326B8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x804326BC: jr          $ra
    // 0x804326C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804326C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8067BE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BE38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067BE3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067BE40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8067BE44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8067BE48: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8067BE4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8067BE50: jal         0x80045A34
    // 0x8067BE54: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8067BE54: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x8067BE58: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8067BE5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8067BE60: bne         $v0, $zero, L_8067BE78
    if (ctx->r2 != 0) {
        // 0x8067BE64: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_8067BE78;
    }
    // 0x8067BE64: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x8067BE68: jal         0x800445A4
    // 0x8067BE6C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8067BE6C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8067BE70: b           L_8067BECC
    // 0x8067BE74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8067BECC;
    // 0x8067BE74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8067BE78:
    // 0x8067BE78: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x8067BE7C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8067BE80: jal         0x80065728
    // 0x8067BE84: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8067BE84: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8067BE88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8067BE8C: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(541, 0X3C90) << 16);
    // 0x8067BE90: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8067BE94: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8067BE98: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8067BE9C: lw          $t6, -0x26C0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(541, 0X3C90));
    // 0x8067BEA0: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X3CC0) << 16);
    // 0x8067BEA4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8067BEA8: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8067BEAC: lwc1        $f4, -0x2690($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X3CC0));
    // 0x8067BEB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8067BEB4: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8067BEB8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8067BEBC: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x8067BEC0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8067BEC4: sw          $a1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r5;
    // 0x8067BEC8: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
L_8067BECC:
    // 0x8067BECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067BED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067BED4: jr          $ra
    // 0x8067BED8: nop

    return;
    // 0x8067BED8: nop

;}
RECOMP_FUNC void func_80422F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422F08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80422F0C: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(35, 0X2EFC) << 16);
    // 0x80422F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80422F14: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80422F18: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80422F1C: addiu       $t6, $t6, 0x58FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(35, 0X2EFC));
    // 0x80422F20: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80422F24: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80422F28: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80422F2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80422F30: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80422F34: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80422F38: andi        $t0, $a1, 0xFF
    ctx->r8 = ctx->r5 & 0XFF;
    // 0x80422F3C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80422F40: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80422F44: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80422F48: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x80422F4C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80422F50: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80422F54: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80422F58: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80422F5C: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80422F60: lbu         $t9, 0x164($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X164);
    // 0x80422F64: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80422F68: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80422F6C: bne         $t9, $zero, L_80422F7C
    if (ctx->r25 != 0) {
        // 0x80422F70: addu        $t5, $t2, $t4
        ctx->r13 = ADD32(ctx->r10, ctx->r12);
            goto L_80422F7C;
    }
    // 0x80422F70: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80422F74: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80422F78: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
L_80422F7C:
    // 0x80422F7C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80422F80: jal         0x80422B08
    // 0x80422F84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80422B08(rdram, ctx);
        goto after_0;
    // 0x80422F84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80422F88: jal         0x80422B64
    // 0x80422F8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80422B64(rdram, ctx);
        goto after_1;
    // 0x80422F8C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80422F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80422F94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80422F98: jr          $ra
    // 0x80422F9C: nop

    return;
    // 0x80422F9C: nop

    // 0x80422FA0: jr          $ra
    // 0x80422FA4: nop

    return;
    // 0x80422FA4: nop

;}
RECOMP_FUNC void func_80426A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426A08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80426A0C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80426A10: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80426A14: addiu       $s2, $zero, 0x16
    ctx->r18 = ADD32(0, 0X16);
    // 0x80426A18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80426A1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80426A20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80426A24: lui         $v1, 0x8042
    ctx->r3 = S32(RELOC_HI16(38, 0XEF8) << 16);
    // 0x80426A28: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80426A2C: addiu       $v1, $v1, 0x74F8
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(38, 0XEF8));
    // 0x80426A30: sw          $s2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r18;
    // 0x80426A34: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80426A38: jal         0x80064D1C
    // 0x80426A3C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x80426A3C: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_0:
    // 0x80426A40: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x80426A44: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80426A48: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80426A4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80426A50: beq         $t6, $zero, L_80426A90
    if (ctx->r14 == 0) {
        // 0x80426A54: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80426A90;
    }
    // 0x80426A54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80426A58: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_80426A5C:
    // 0x80426A5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80426A60: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80426A64: sh          $t7, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r15;
    // 0x80426A68: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80426A6C: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80426A70: sh          $t8, -0x4($a0)
    MEM_H(-0X4, ctx->r4) = ctx->r24;
    // 0x80426A74: lh          $t9, -0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, -0X2);
    // 0x80426A78: sh          $t9, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r25;
    // 0x80426A7C: lw          $t0, 0x4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4);
    // 0x80426A80: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x80426A84: bnel        $at, $zero, L_80426A5C
    if (ctx->r1 != 0) {
        // 0x80426A88: lh          $t7, 0x0($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X0);
            goto L_80426A5C;
    }
    goto skip_0;
    // 0x80426A88: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    skip_0:
    // 0x80426A8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80426A90:
    // 0x80426A90: lui         $t1, 0x8042
    ctx->r9 = S32(RELOC_HI16(38, 0X1000) << 16);
    // 0x80426A94: addiu       $t1, $t1, 0x7600
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(38, 0X1000));
    // 0x80426A98: sw          $s2, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r18;
    // 0x80426A9C: sw          $t1, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r9;
    // 0x80426AA0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80426AA4: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_80426AA8:
    // 0x80426AA8: jal         0x80064D1C
    // 0x80426AAC: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x80426AAC: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    after_1:
    // 0x80426AB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80426AB4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80426AB8: bne         $s0, $s2, L_80426AA8
    if (ctx->r16 != ctx->r18) {
        // 0x80426ABC: sw          $v0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r2;
            goto L_80426AA8;
    }
    // 0x80426ABC: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80426AC0: sh          $zero, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = 0;
    // 0x80426AC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80426AC8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80426ACC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80426AD0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80426AD4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80426AD8: jr          $ra
    // 0x80426ADC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80426ADC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80065954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065954: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80065958: nop

    // 0x8006595C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80065960: nop

    // 0x80065964: bc1fl       L_8006597C
    if (!c1cs) {
        // 0x80065968: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_8006597C;
    }
    goto skip_0;
    // 0x80065968: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_0:
    // 0x8006596C: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x80065970: jr          $ra
    // 0x80065974: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80065974: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80065978: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8006597C:
    // 0x8006597C: jr          $ra
    // 0x80065980: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80065980: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_806DF754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF754: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806DF758: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X1170) << 16);
    // 0x806DF75C: lwc1        $f8, 0x5A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X1170));
    // 0x806DF760: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x806DF764: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x806DF768: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806DF76C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806DF770: lwc1        $f4, 0xE8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XE8);
    // 0x806DF774: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806DF778: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X1174) << 16);
    // 0x806DF77C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806DF780: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806DF784: lwc1        $f10, 0xDC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x806DF788: mul.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x806DF78C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x806DF790: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x806DF794: lwc1        $f16, 0xC4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806DF798: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806DF79C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806DF7A0: bc1f        L_806DF7B8
    if (!c1cs) {
        // 0x806DF7A4: nop
    
            goto L_806DF7B8;
    }
    // 0x806DF7A4: nop

    // 0x806DF7A8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806DF7AC: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x806DF7B0: b           L_806DF7D4
    // 0x806DF7B4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
        goto L_806DF7D4;
    // 0x806DF7B4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_806DF7B8:
    // 0x806DF7B8: lwc1        $f0, 0x5A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X1174));
    // 0x806DF7BC: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806DF7C0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x806DF7C4: nop

    // 0x806DF7C8: bc1fl       L_806DF7D8
    if (!c1cs) {
        // 0x806DF7CC: lwc1        $f0, 0x1C($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_806DF7D8;
    }
    goto skip_0;
    // 0x806DF7CC: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    skip_0:
    // 0x806DF7D0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_806DF7D4:
    // 0x806DF7D4: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
L_806DF7D8:
    // 0x806DF7D8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806DF7DC: lwc1        $f8, 0x28($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X28);
    // 0x806DF7E0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806DF7E4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x806DF7E8: bc1f        L_806DF80C
    if (!c1cs) {
        // 0x806DF7EC: swc1        $f10, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
            goto L_806DF80C;
    }
    // 0x806DF7EC: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x806DF7F0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806DF7F4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806DF7F8: nop

    // 0x806DF7FC: bc1f        L_806DF824
    if (!c1cs) {
        // 0x806DF800: nop
    
            goto L_806DF824;
    }
    // 0x806DF800: nop

    // 0x806DF804: jr          $ra
    // 0x806DF808: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x806DF808: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_806DF80C:
    // 0x806DF80C: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806DF810: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x806DF814: nop

    // 0x806DF818: bc1f        L_806DF824
    if (!c1cs) {
        // 0x806DF81C: nop
    
            goto L_806DF824;
    }
    // 0x806DF81C: nop

    // 0x806DF820: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_806DF824:
    // 0x806DF824: jr          $ra
    // 0x806DF828: nop

    return;
    // 0x806DF828: nop

;}
RECOMP_FUNC void func_8057E480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057E480: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8057E484: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8057E488: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8057E48C: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8057E490: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8057E494: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8057E498: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8057E49C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8057E4A0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8057E4A4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8057E4A8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8057E4AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8057E4B0: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x8057E4B4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057E4B8: addiu       $s2, $v0, 0x1E0
    ctx->r18 = ADD32(ctx->r2, 0X1E0);
    // 0x8057E4BC: jal         0x8004700C
    // 0x8057E4C0: addiu       $s0, $v0, 0x1E8
    ctx->r16 = ADD32(ctx->r2, 0X1E8);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8057E4C0: addiu       $s0, $v0, 0x1E8
    ctx->r16 = ADD32(ctx->r2, 0X1E8);
    after_0:
    // 0x8057E4C4: beq         $v0, $zero, L_8057E5EC
    if (ctx->r2 == 0) {
        // 0x8057E4C8: sw          $v0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r2;
            goto L_8057E5EC;
    }
    // 0x8057E4C8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8057E4CC: lw          $t7, 0x174($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X174);
    // 0x8057E4D0: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x8057E4D4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8057E4D8: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x8057E4DC: lwc1        $f28, 0x84($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8057E4E0: lwc1        $f30, 0x88($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8057E4E4: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x8057E4E8: lh          $t9, 0xC($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XC);
    // 0x8057E4EC: lw          $a0, 0x70($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X70);
    // 0x8057E4F0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8057E4F4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8057E4F8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8057E4FC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8057E500: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8057E504: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8057E508: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8057E50C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8057E510: mul.s       $f24, $f4, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8057E514: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8057E518: lwc1        $f4, 0x6C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X6C);
    // 0x8057E51C: mul.s       $f26, $f10, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8057E520: nop

    // 0x8057E524: mul.s       $f22, $f4, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8057E528: nop

L_8057E52C:
    // 0x8057E52C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8057E530: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8057E534: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8057E538: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8057E53C: sub.s       $f2, $f18, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8057E540: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8057E544: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8057E548: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8057E54C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8057E550: sub.s       $f10, $f16, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x8057E554: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8057E558: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8057E55C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8057E560: mul.s       $f20, $f0, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8057E564: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x8057E568: nop

    // 0x8057E56C: bc1fl       L_8057E57C
    if (!c1cs) {
        // 0x8057E570: swc1        $f10, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
            goto L_8057E57C;
    }
    goto skip_0;
    // 0x8057E570: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    skip_0:
    // 0x8057E574: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8057E578: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
L_8057E57C:
    // 0x8057E57C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8057E580: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8057E584: sub.s       $f4, $f6, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f30.fl;
    // 0x8057E588: jal         0x80065954
    // 0x8057E58C: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8057E58C: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8057E590: add.s       $f8, $f24, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x8057E594: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8057E598: nop

    // 0x8057E59C: bc1fl       L_8057E5E0
    if (!c1cs) {
        // 0x8057E5A0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8057E5E0;
    }
    goto skip_1;
    // 0x8057E5A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8057E5A4: jal         0x80065954
    // 0x8057E5A8: lwc1        $f12, 0x84($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X84);
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8057E5A8: lwc1        $f12, 0x84($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X84);
    after_2:
    // 0x8057E5AC: add.s       $f18, $f26, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f26.fl + ctx->f20.fl;
    // 0x8057E5B0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8057E5B4: nop

    // 0x8057E5B8: bc1fl       L_8057E5E0
    if (!c1cs) {
        // 0x8057E5BC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8057E5E0;
    }
    goto skip_2;
    // 0x8057E5BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x8057E5C0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8057E5C4: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x8057E5C8: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    // 0x8057E5CC: jal         0x8002F6E4
    // 0x8057E5D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_3;
    // 0x8057E5D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8057E5D4: b           L_8057E5F0
    // 0x8057E5D8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8057E5F0;
    // 0x8057E5D8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8057E5DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8057E5E0:
    // 0x8057E5E0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8057E5E4: bne         $s1, $s3, L_8057E52C
    if (ctx->r17 != ctx->r19) {
        // 0x8057E5E8: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8057E52C;
    }
    // 0x8057E5E8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8057E5EC:
    // 0x8057E5EC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8057E5F0:
    // 0x8057E5F0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8057E5F4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8057E5F8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8057E5FC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8057E600: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8057E604: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8057E608: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8057E60C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8057E610: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8057E614: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8057E618: jr          $ra
    // 0x8057E61C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8057E61C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80716A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716A28: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716A2C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716A30: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716A34: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716A38: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716A3C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716A40: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716A44: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716A48: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716A4C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716A50: jr          $ra
    // 0x80716A54: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716A54: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8040D6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D6C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040D6C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040D6C8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D6CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040D6D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040D6D4: jal         0x8040CBE8
    // 0x8040D6D8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8040CBE8(rdram, ctx);
        goto after_0;
    // 0x8040D6D8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8040D6DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040D6E0: jal         0x8040CBE8
    // 0x8040D6E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8040CBE8(rdram, ctx);
        goto after_1;
    // 0x8040D6E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8040D6E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040D6EC: bne         $v0, $at, L_8040D718
    if (ctx->r2 != ctx->r1) {
        // 0x8040D6F0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8040D718;
    }
    // 0x8040D6F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040D6F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8040D6F8: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8040D6FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D700: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8040D704: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8040D708: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8040D70C: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x8040D710: jal         0x8040E254
    // 0x8040D714: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040D714: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_2:
L_8040D718:
    // 0x8040D718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040D71C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040D720: jr          $ra
    // 0x8040D724: nop

    return;
    // 0x8040D724: nop

;}
RECOMP_FUNC void func_80022EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022EB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022EB8: nop

    // 0x80022EBC: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x80022EC0: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    // 0x80022EC4: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x80022EC8: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x80022ECC: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x80022ED0: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x80022ED4: swc1        $f0, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f0.u32l;
    // 0x80022ED8: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x80022EDC: jr          $ra
    // 0x80022EE0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80022EE0: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80000C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C44: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80000C48: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80000C4C: lh          $t6, 0x4A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4A);
    // 0x80000C50: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80000C54: addiu       $t8, $t8, 0x4D10
    ctx->r24 = ADD32(ctx->r24, 0X4D10);
    // 0x80000C58: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80000C5C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80000C60: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80000C64: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80000C68: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80000C6C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80000C70: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80000C74: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80000C78: lbu         $t9, 0x1B($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1B);
    // 0x80000C7C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80000C80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80000C84: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80000C88: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x80000C8C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80000C90: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80000C94: lh          $t9, 0x4E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4E);
    // 0x80000C98: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80000C9C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80000CA0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80000CA4: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80000CA8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80000CAC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80000CB0: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x80000CB4: lw          $v0, 0x5C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X5C);
    // 0x80000CB8: lh          $t9, 0x60($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X60);
    // 0x80000CBC: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80000CC0: andi        $t1, $v0, 0x7
    ctx->r9 = ctx->r2 & 0X7;
    // 0x80000CC4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80000CC8: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x80000CCC: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80000CD0: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x80000CD4: addiu       $t2, $t2, 0xF
    ctx->r10 = ADD32(ctx->r10, 0XF);
    // 0x80000CD8: andi        $t2, $t2, 0xFFF0
    ctx->r10 = ctx->r10 & 0XFFF0;
    // 0x80000CDC: sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10 << 16);
    // 0x80000CE0: addiu       $t0, $t0, 0x50
    ctx->r8 = ADD32(ctx->r8, 0X50);
    // 0x80000CE4: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80000CE8: sh          $t2, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r10;
    // 0x80000CEC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80000CF0: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
    // 0x80000CF4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80000CF8: addiu       $a1, $zero, 0x3E0
    ctx->r5 = ADD32(0, 0X3E0);
    // 0x80000CFC: bgez        $t1, L_80000D0C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80000D00: sra         $t8, $t1, 1
        ctx->r24 = S32(SIGNED(ctx->r9) >> 1);
            goto L_80000D0C;
    }
    // 0x80000D00: sra         $t8, $t1, 1
    ctx->r24 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80000D04: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x80000D08: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80000D0C:
    // 0x80000D0C: subu        $a2, $v0, $t8
    ctx->r6 = SUB32(ctx->r2, ctx->r24);
    // 0x80000D10: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80000D14: addiu       $a3, $zero, 0x1A0
    ctx->r7 = ADD32(0, 0X1A0);
    // 0x80000D18: jal         0x80001338
    // 0x80000D1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80001338(rdram, ctx);
        goto after_0;
    // 0x80000D1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80000D20: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80000D24: lh          $t2, 0x38($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X38);
    // 0x80000D28: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80000D2C: lh          $t7, 0x12($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X12);
    // 0x80000D30: lh          $t1, 0x3A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3A);
    // 0x80000D34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80000D38: beq         $t7, $zero, L_80000D6C
    if (ctx->r15 == 0) {
        // 0x80000D3C: addiu       $a1, $t2, 0x3E0
        ctx->r5 = ADD32(ctx->r10, 0X3E0);
            goto L_80000D6C;
    }
    // 0x80000D3C: addiu       $a1, $t2, 0x3E0
    ctx->r5 = ADD32(ctx->r10, 0X3E0);
    // 0x80000D40: lh          $t8, 0x4A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4A);
    // 0x80000D44: addiu       $t9, $zero, 0x1A0
    ctx->r25 = ADD32(0, 0X1A0);
    // 0x80000D48: subu        $a3, $t9, $t2
    ctx->r7 = SUB32(ctx->r25, ctx->r10);
    // 0x80000D4C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80000D50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80000D54: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80000D58: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
    // 0x80000D5C: jal         0x80001338
    // 0x80000D60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80001338(rdram, ctx);
        goto after_1;
    // 0x80000D60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x80000D64: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80000D68: lh          $t1, 0x3A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3A);
L_80000D6C:
    // 0x80000D6C: addiu       $t6, $t1, 0x3E0
    ctx->r14 = ADD32(ctx->r9, 0X3E0);
    // 0x80000D70: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x80000D74: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80000D78: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x80000D7C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80000D80: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80000D84: lui         $at, 0xC80
    ctx->r1 = S32(0XC80 << 16);
    // 0x80000D88: lui         $t4, 0x500
    ctx->r12 = S32(0X500 << 16);
    // 0x80000D8C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x80000D90: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80000D94: or          $t8, $a2, $at
    ctx->r24 = ctx->r6 | ctx->r1;
    // 0x80000D98: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80000D9C: lhu         $t7, 0x26($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X26);
    // 0x80000DA0: lbu         $t6, 0x18($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X18);
    // 0x80000DA4: addiu       $a3, $v0, 0x8
    ctx->r7 = ADD32(ctx->r2, 0X8);
    // 0x80000DA8: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x80000DAC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80000DB0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80000DB4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80000DB8: lw          $t6, 0x40($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X40);
    // 0x80000DBC: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80000DC0: addiu       $t7, $t1, 0x580
    ctx->r15 = ADD32(ctx->r9, 0X580);
    // 0x80000DC4: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x80000DC8: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x80000DCC: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x80000DD0: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80000DD4: lui         $at, 0xE20
    ctx->r1 = S32(0XE20 << 16);
    // 0x80000DD8: or          $t9, $a2, $at
    ctx->r25 = ctx->r6 | ctx->r1;
    // 0x80000DDC: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x80000DE0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80000DE4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80000DE8: lhu         $t8, 0x26($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X26);
    // 0x80000DEC: lbu         $t7, 0x18($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X18);
    // 0x80000DF0: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x80000DF4: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x80000DF8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80000DFC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80000E00: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80000E04: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x80000E08: addiu       $v0, $t2, 0x8
    ctx->r2 = ADD32(ctx->r10, 0X8);
    // 0x80000E0C: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x80000E10: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x80000E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80000E18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80000E1C: jr          $ra
    // 0x80000E20: nop

    return;
    // 0x80000E20: nop

;}
RECOMP_FUNC void func_805221D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805221D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805221D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805221D8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x805221DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805221E0: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(318, 0XA0) << 16);
    // 0x805221E4: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x805221E8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805221EC: addiu       $t7, $t7, 0x2240
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(318, 0XA0));
    // 0x805221F0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805221F4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x805221F8: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x805221FC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80522200: jal         0x80522218
    // 0x80522204: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    func_80522218(rdram, ctx);
        goto after_0;
    // 0x80522204: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    after_0:
    // 0x80522208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052220C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80522210: jr          $ra
    // 0x80522214: nop

    return;
    // 0x80522214: nop

;}
RECOMP_FUNC void Fault_PrintFPCSR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FAB4: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x8006FAB8: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x8006FABC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006FAC0: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_8006FAC4:
    // 0x8006FAC4: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x8006FAC8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8006FACC: bne         $t9, $sp, L_8006FAC4
    if (ctx->r25 != ctx->r29) {
        // 0x8006FAD0: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_8006FAC4;
    }
    // 0x8006FAD0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006FAD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FAD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006FADC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006FAE0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8006FAE4: lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // 0x8006FAE8: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FAEC: addiu       $a2, $a2, 0x13E0
    ctx->r6 = ADD32(ctx->r6, 0X13E0);
    // 0x8006FAF0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8006FAF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006FAF8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006FAFC: jal         0x8006F884
    // 0x8006FB00: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    Fault_Printf(rdram, ctx);
        goto after_0;
    // 0x8006FB00: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x8006FB04: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8006FB08: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8006FB0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006FB10: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_8006FB14:
    // 0x8006FB14: and         $t6, $a3, $v1
    ctx->r14 = ctx->r7 & ctx->r3;
    // 0x8006FB18: beql        $t6, $zero, L_8006FB54
    if (ctx->r14 == 0) {
        // 0x8006FB1C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8006FB54;
    }
    goto skip_0;
    // 0x8006FB1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8006FB20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006FB24: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006FB28: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x8006FB2C: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x8006FB30: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006FB34: addiu       $a2, $a2, 0x13EC
    ctx->r6 = ADD32(ctx->r6, 0X13EC);
    // 0x8006FB38: lw          $a3, -0x7BAC($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7BAC);
    // 0x8006FB3C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006FB40: jal         0x8006F884
    // 0x8006FB44: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    Fault_Printf(rdram, ctx);
        goto after_1;
    // 0x8006FB44: addiu       $a0, $a0, 0x64
    ctx->r4 = ADD32(ctx->r4, 0X64);
    after_1:
    // 0x8006FB48: b           L_8006FB60
    // 0x8006FB4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006FB60;
    // 0x8006FB4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006FB50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8006FB54:
    // 0x8006FB54: bne         $v0, $a0, L_8006FB14
    if (ctx->r2 != ctx->r4) {
        // 0x8006FB58: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_8006FB14;
    }
    // 0x8006FB58: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x8006FB5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006FB60:
    // 0x8006FB60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006FB64: jr          $ra
    // 0x8006FB68: nop

    return;
    // 0x8006FB68: nop

;}
RECOMP_FUNC void func_804CAD78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CAD78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CAD7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CAD80: jal         0x804CACF8
    // 0x804CAD84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804CACF8(rdram, ctx);
        goto after_0;
    // 0x804CAD84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CAD88: beq         $v0, $zero, L_804CAE18
    if (ctx->r2 == 0) {
        // 0x804CAD8C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804CAE18;
    }
    // 0x804CAD8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CAD90: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804CAD94: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804CAD98: lui         $t7, 0x804D
    ctx->r15 = S32(RELOC_HI16(231, 0X12B4) << 16);
    // 0x804CAD9C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804CADA0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804CADA4: addiu       $t7, $t7, -0x420C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(231, 0X12B4));
    // 0x804CADA8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804CADAC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804CADB0: jal         0x804CAD4C
    // 0x804CADB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804CAD4C(rdram, ctx);
        goto after_1;
    // 0x804CADB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x804CADB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804CADBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804CADC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CADC4: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13C0) << 16);
    // 0x804CADC8: lwc1        $f2, -0x4100($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13C0));
    // 0x804CADCC: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x804CADD0: lui         $t0, 0x804D
    ctx->r8 = S32(RELOC_HI16(231, 0XE74) << 16);
    // 0x804CADD4: addiu       $t9, $t9, 0x5284
    ctx->r25 = ADD32(ctx->r25, 0X5284);
    // 0x804CADD8: addiu       $t0, $t0, -0x464C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(231, 0XE74));
    // 0x804CADDC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13C4) << 16);
    // 0x804CADE0: sw          $t9, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r25;
    // 0x804CADE4: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x804CADE8: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    // 0x804CADEC: lwc1        $f4, -0x40FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13C4));
    // 0x804CADF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CADF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804CADF8: swc1        $f0, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->f0.u32l;
    // 0x804CADFC: swc1        $f2, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f2.u32l;
    // 0x804CAE00: swc1        $f2, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->f2.u32l;
    // 0x804CAE04: jal         0x804CBA88
    // 0x804CAE08: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    func_804CBA88(rdram, ctx);
        goto after_2;
    // 0x804CAE08: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x804CAE0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x804CAE10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804CAE14: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
L_804CAE18:
    // 0x804CAE18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CAE1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CAE20: jr          $ra
    // 0x804CAE24: nop

    return;
    // 0x804CAE24: nop

;}
RECOMP_FUNC void func_8076CEFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076CEFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8076CF00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076CF04: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8076CF08: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8076CF0C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8076CF10: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8076CF14: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8076CF18: jal         0x8004700C
    // 0x8076CF1C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8076CF1C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8076CF20: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8076CF24: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8076CF28: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8076CF2C: lw          $t6, 0xC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XC);
    // 0x8076CF30: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8076CF34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8076CF38: beq         $v0, $zero, L_8076CF90
    if (ctx->r2 == 0) {
        // 0x8076CF3C: lw          $v1, 0x1F4($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X1F4);
            goto L_8076CF90;
    }
    // 0x8076CF3C: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x8076CF40: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8076CF44: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8076CF48: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8076CF4C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8076CF50: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8076CF54: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8076CF58: jal         0x80047AB8
    // 0x8076CF5C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x8076CF5C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8076CF60: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8076CF64: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8076CF68: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8076CF6C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8076CF70: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8076CF74: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8076CF78: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8076CF7C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8076CF80: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8076CF84: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8076CF88: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8076CF8C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
L_8076CF90:
    // 0x8076CF90: lwc1        $f14, 0x30($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X30);
    // 0x8076CF94: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8076CF98: nop

    // 0x8076CF9C: bc1fl       L_8076D084
    if (!c1cs) {
        // 0x8076CFA0: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8076D084;
    }
    goto skip_0;
    // 0x8076CFA0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_0:
    // 0x8076CFA4: lwc1        $f12, 0x34($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8076CFA8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8076CFAC: nop

    // 0x8076CFB0: bc1fl       L_8076D084
    if (!c1cs) {
        // 0x8076CFB4: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8076D084;
    }
    goto skip_1;
    // 0x8076CFB4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_1:
    // 0x8076CFB8: lwc1        $f16, 0x28($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X28);
    // 0x8076CFBC: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8076CFC0: nop

    // 0x8076CFC4: bc1fl       L_8076D084
    if (!c1cs) {
        // 0x8076CFC8: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8076D084;
    }
    goto skip_2;
    // 0x8076CFC8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_2:
    // 0x8076CFCC: lwc1        $f18, 0x2C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x8076CFD0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8076CFD4: nop

    // 0x8076CFD8: bc1fl       L_8076D084
    if (!c1cs) {
        // 0x8076CFDC: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8076D084;
    }
    goto skip_3;
    // 0x8076CFDC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_3:
    // 0x8076CFE0: beq         $a1, $zero, L_8076D124
    if (ctx->r5 == 0) {
        // 0x8076CFE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8076D124;
    }
    // 0x8076CFE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8076CFE8: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8076CFEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8076CFF0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8076CFF4: beq         $t7, $at, L_8076D124
    if (ctx->r15 == ctx->r1) {
        // 0x8076CFF8: nop
    
            goto L_8076D124;
    }
    // 0x8076CFF8: nop

    // 0x8076CFFC: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x8076D000: nop

    // 0x8076D004: bc1f        L_8076D124
    if (!c1cs) {
        // 0x8076D008: nop
    
            goto L_8076D124;
    }
    // 0x8076D008: nop

    // 0x8076D00C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8076D010: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8076D014: bc1f        L_8076D124
    if (!c1cs) {
        // 0x8076D018: nop
    
            goto L_8076D124;
    }
    // 0x8076D018: nop

    // 0x8076D01C: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8076D020: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8076D024: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x8076D028: jal         0x80065954
    // 0x8076D02C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8076D02C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x8076D030: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x8076D034: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8076D038: nop

    // 0x8076D03C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8076D040: nop

    // 0x8076D044: bc1f        L_8076D078
    if (!c1cs) {
        // 0x8076D048: nop
    
            goto L_8076D078;
    }
    // 0x8076D048: nop

    // 0x8076D04C: jal         0x80065954
    // 0x8076D050: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8076D050: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x8076D054: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x8076D058: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8076D05C: nop

    // 0x8076D060: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8076D064: nop

    // 0x8076D068: bc1f        L_8076D078
    if (!c1cs) {
        // 0x8076D06C: nop
    
            goto L_8076D078;
    }
    // 0x8076D06C: nop

    // 0x8076D070: b           L_8076D124
    // 0x8076D074: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8076D124;
    // 0x8076D074: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8076D078:
    // 0x8076D078: b           L_8076D124
    // 0x8076D07C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8076D124;
    // 0x8076D07C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8076D080: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_8076D084:
    // 0x8076D084: lwc1        $f12, 0x34($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8076D088: bc1fl       L_8076D0A0
    if (!c1cs) {
        // 0x8076D08C: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_8076D0A0;
    }
    goto skip_4;
    // 0x8076D08C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_4:
    // 0x8076D090: sub.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8076D094: b           L_8076D0C4
    // 0x8076D098: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
        goto L_8076D0C4;
    // 0x8076D098: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x8076D09C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_8076D0A0:
    // 0x8076D0A0: nop

    // 0x8076D0A4: bc1fl       L_8076D0BC
    if (!c1cs) {
        // 0x8076D0A8: lwc1        $f6, 0x38($a3)
        ctx->f6.u32l = MEM_W(ctx->r7, 0X38);
            goto L_8076D0BC;
    }
    goto skip_5;
    // 0x8076D0A8: lwc1        $f6, 0x38($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X38);
    skip_5:
    // 0x8076D0AC: sub.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8076D0B0: b           L_8076D0C4
    // 0x8076D0B4: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
        goto L_8076D0C4;
    // 0x8076D0B4: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x8076D0B8: lwc1        $f6, 0x38($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X38);
L_8076D0BC:
    // 0x8076D0BC: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8076D0C0: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_8076D0C4:
    // 0x8076D0C4: lwc1        $f0, 0x28($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X28);
    // 0x8076D0C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8076D0CC: nop

    // 0x8076D0D0: bc1fl       L_8076D0F0
    if (!c1cs) {
        // 0x8076D0D4: lwc1        $f18, 0x2C($a3)
        ctx->f18.u32l = MEM_W(ctx->r7, 0X2C);
            goto L_8076D0F0;
    }
    goto skip_6;
    // 0x8076D0D4: lwc1        $f18, 0x2C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X2C);
    skip_6:
    // 0x8076D0D8: lwc1        $f10, 0x2C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x8076D0DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8076D0E0: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8076D0E4: b           L_8076D124
    // 0x8076D0E8: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
        goto L_8076D124;
    // 0x8076D0E8: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8076D0EC: lwc1        $f18, 0x2C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X2C);
L_8076D0F0:
    // 0x8076D0F0: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8076D0F4: nop

    // 0x8076D0F8: bc1fl       L_8076D114
    if (!c1cs) {
        // 0x8076D0FC: lwc1        $f6, 0x3C($a3)
        ctx->f6.u32l = MEM_W(ctx->r7, 0X3C);
            goto L_8076D114;
    }
    goto skip_7;
    // 0x8076D0FC: lwc1        $f6, 0x3C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X3C);
    skip_7:
    // 0x8076D100: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8076D104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8076D108: b           L_8076D124
    // 0x8076D10C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
        goto L_8076D124;
    // 0x8076D10C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8076D110: lwc1        $f6, 0x3C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X3C);
L_8076D114:
    // 0x8076D114: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8076D118: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x8076D11C: b           L_8076D124
    // 0x8076D120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8076D124;
    // 0x8076D120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8076D124:
    // 0x8076D124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8076D128: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8076D12C: jr          $ra
    // 0x8076D130: nop

    return;
    // 0x8076D130: nop

;}
RECOMP_FUNC void func_8079E4CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079E4CC: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(835, 0X1918) << 16);
    // 0x8079E4D0: lw          $t6, -0xBF8($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(835, 0X1918));
    // 0x8079E4D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079E4D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079E4DC: bne         $t6, $zero, L_8079E66C
    if (ctx->r14 != 0) {
        // 0x8079E4E0: lui         $t7, 0x800F
        ctx->r15 = S32(0X800F << 16);
            goto L_8079E66C;
    }
    // 0x8079E4E0: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8079E4E4: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x8079E4E8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8079E4EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8079E4F0: lb          $t8, 0x2($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X2);
    // 0x8079E4F4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8079E4F8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8079E4FC: nop

    // 0x8079E500: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8079E504: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8079E508: nop

    // 0x8079E50C: bc1fl       L_8079E554
    if (!c1cs) {
        // 0x8079E510: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8079E554;
    }
    goto skip_0;
    // 0x8079E510: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_0:
    // 0x8079E514: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8079E518: nop

    // 0x8079E51C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8079E520: nop

    // 0x8079E524: bc1fl       L_8079E554
    if (!c1cs) {
        // 0x8079E528: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8079E554;
    }
    goto skip_1;
    // 0x8079E528: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_1:
    // 0x8079E52C: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8079E530: jal         0x80082050
    // 0x8079E534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    truncf_recomp(rdram, ctx);
        goto after_0;
    // 0x8079E534: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079E538: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079E53C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8079E540: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1910) << 16);
    // 0x8079E544: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8079E548: b           L_8079E66C
    // 0x8079E54C: swc1        $f12, -0xC00($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1910), ctx->r1) = ctx->f12.u32l;
        goto L_8079E66C;
    // 0x8079E54C: swc1        $f12, -0xC00($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1910), ctx->r1) = ctx->f12.u32l;
    // 0x8079E550: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
L_8079E554:
    // 0x8079E554: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8079E558: bc1fl       L_8079E56C
    if (!c1cs) {
        // 0x8079E55C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8079E56C;
    }
    goto skip_2;
    // 0x8079E55C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_2:
    // 0x8079E560: b           L_8079E574
    // 0x8079E564: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_8079E574;
    // 0x8079E564: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8079E568: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8079E56C:
    // 0x8079E56C: nop

    // 0x8079E570: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
L_8079E574:
    // 0x8079E574: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1910) << 16);
    // 0x8079E578: lwc1        $f12, -0xC00($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1910));
    // 0x8079E57C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8079E580: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1978) << 16);
    // 0x8079E584: lwc1        $f10, -0xB98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1978));
    // 0x8079E588: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x8079E58C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8079E590: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8079E594: bc1fl       L_8079E610
    if (!c1cs) {
        // 0x8079E598: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8079E610;
    }
    goto skip_3;
    // 0x8079E598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_3:
    // 0x8079E59C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8079E5A0: nop

    // 0x8079E5A4: bc1tl       L_8079E7F4
    if (c1cs) {
        // 0x8079E5A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079E7F4;
    }
    goto skip_4;
    // 0x8079E5A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8079E5AC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8079E5B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8079E5B4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8079E5B8: nop

    // 0x8079E5BC: bc1fl       L_8079E5EC
    if (!c1cs) {
        // 0x8079E5C0: lwc1        $f8, 0x0($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
            goto L_8079E5EC;
    }
    goto skip_5;
    // 0x8079E5C0: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    skip_5:
    // 0x8079E5C4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8079E5C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8079E5CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8079E5D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8079E5D4: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8079E5D8: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8079E5DC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8079E5E0: b           L_8079E5FC
    // 0x8079E5E4: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
        goto L_8079E5FC;
    // 0x8079E5E4: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8079E5E8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
L_8079E5EC:
    // 0x8079E5EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8079E5F0: nop

    // 0x8079E5F4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8079E5F8: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_8079E5FC:
    // 0x8079E5FC: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8079E600: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1910) << 16);
    // 0x8079E604: b           L_8079E7F0
    // 0x8079E608: swc1        $f12, -0xC00($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1910), ctx->r1) = ctx->f12.u32l;
        goto L_8079E7F0;
    // 0x8079E608: swc1        $f12, -0xC00($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1910), ctx->r1) = ctx->f12.u32l;
    // 0x8079E60C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8079E610:
    // 0x8079E610: nop

    // 0x8079E614: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x8079E618: nop

    // 0x8079E61C: bc1fl       L_8079E638
    if (!c1cs) {
        // 0x8079E620: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8079E638;
    }
    goto skip_6;
    // 0x8079E620: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_6:
    // 0x8079E624: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8079E628: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8079E62C: b           L_8079E7F0
    // 0x8079E630: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
        goto L_8079E7F0;
    // 0x8079E630: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8079E634: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8079E638:
    // 0x8079E638: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8079E63C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8079E640: nop

    // 0x8079E644: bc1fl       L_8079E660
    if (!c1cs) {
        // 0x8079E648: add.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_8079E660;
    }
    goto skip_7;
    // 0x8079E648: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    skip_7:
    // 0x8079E64C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8079E650: nop

    // 0x8079E654: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8079E658: nop

    // 0x8079E65C: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_8079E660:
    // 0x8079E660: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1910) << 16);
    // 0x8079E664: b           L_8079E7F0
    // 0x8079E668: swc1        $f12, -0xC00($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1910), ctx->r1) = ctx->f12.u32l;
        goto L_8079E7F0;
    // 0x8079E668: swc1        $f12, -0xC00($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1910), ctx->r1) = ctx->f12.u32l;
L_8079E66C:
    // 0x8079E66C: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x8079E670: lw          $t9, 0x7EA8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7EA8);
    // 0x8079E674: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8079E678: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8079E67C: lb          $t0, 0x3($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X3);
    // 0x8079E680: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8079E684: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8079E688: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8079E68C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8079E690: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8079E694: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8079E698: mul.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8079E69C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8079E6A0: nop

    // 0x8079E6A4: bc1fl       L_8079E6F4
    if (!c1cs) {
        // 0x8079E6A8: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8079E6F4;
    }
    goto skip_8;
    // 0x8079E6A8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_8:
    // 0x8079E6AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8079E6B0: nop

    // 0x8079E6B4: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8079E6B8: nop

    // 0x8079E6BC: bc1fl       L_8079E6F4
    if (!c1cs) {
        // 0x8079E6C0: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8079E6F4;
    }
    goto skip_9;
    // 0x8079E6C0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_9:
    // 0x8079E6C4: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8079E6C8: jal         0x80082050
    // 0x8079E6CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    truncf_recomp(rdram, ctx);
        goto after_1;
    // 0x8079E6CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8079E6D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079E6D4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1918) << 16);
    // 0x8079E6D8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8079E6DC: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8079E6E0: sw          $zero, -0xBF8($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1918), ctx->r1) = 0;
    // 0x8079E6E4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1914) << 16);
    // 0x8079E6E8: b           L_8079E7F0
    // 0x8079E6EC: swc1        $f12, -0xBFC($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1914), ctx->r1) = ctx->f12.u32l;
        goto L_8079E7F0;
    // 0x8079E6EC: swc1        $f12, -0xBFC($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1914), ctx->r1) = ctx->f12.u32l;
    // 0x8079E6F0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
L_8079E6F4:
    // 0x8079E6F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8079E6F8: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1918) << 16);
    // 0x8079E6FC: sw          $t1, -0xBF8($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1918), ctx->r1) = ctx->r9;
    // 0x8079E700: bc1f        L_8079E710
    if (!c1cs) {
        // 0x8079E704: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8079E710;
    }
    // 0x8079E704: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8079E708: b           L_8079E71C
    // 0x8079E70C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_8079E71C;
    // 0x8079E70C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8079E710:
    // 0x8079E710: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8079E714: nop

    // 0x8079E718: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
L_8079E71C:
    // 0x8079E71C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1914) << 16);
    // 0x8079E720: lwc1        $f12, -0xBFC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1914));
    // 0x8079E724: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8079E728: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X197C) << 16);
    // 0x8079E72C: lwc1        $f8, -0xB94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X197C));
    // 0x8079E730: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x8079E734: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8079E738: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8079E73C: bc1fl       L_8079E7A8
    if (!c1cs) {
        // 0x8079E740: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8079E7A8;
    }
    goto skip_10;
    // 0x8079E740: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_10:
    // 0x8079E744: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8079E748: nop

    // 0x8079E74C: bc1tl       L_8079E7F4
    if (c1cs) {
        // 0x8079E750: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079E7F4;
    }
    goto skip_11;
    // 0x8079E750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x8079E754: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8079E758: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8079E75C: bc1fl       L_8079E784
    if (!c1cs) {
        // 0x8079E760: lwc1        $f6, 0x4($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
            goto L_8079E784;
    }
    goto skip_12;
    // 0x8079E760: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    skip_12:
    // 0x8079E764: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8079E768: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8079E76C: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8079E770: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8079E774: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8079E778: b           L_8079E794
    // 0x8079E77C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
        goto L_8079E794;
    // 0x8079E77C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8079E780: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
L_8079E784:
    // 0x8079E784: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8079E788: nop

    // 0x8079E78C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8079E790: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
L_8079E794:
    // 0x8079E794: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8079E798: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1914) << 16);
    // 0x8079E79C: b           L_8079E7F0
    // 0x8079E7A0: swc1        $f12, -0xBFC($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1914), ctx->r1) = ctx->f12.u32l;
        goto L_8079E7F0;
    // 0x8079E7A0: swc1        $f12, -0xBFC($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1914), ctx->r1) = ctx->f12.u32l;
    // 0x8079E7A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8079E7A8:
    // 0x8079E7A8: nop

    // 0x8079E7AC: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x8079E7B0: nop

    // 0x8079E7B4: bc1fl       L_8079E7D0
    if (!c1cs) {
        // 0x8079E7B8: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8079E7D0;
    }
    goto skip_13;
    // 0x8079E7B8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_13:
    // 0x8079E7BC: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8079E7C0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8079E7C4: b           L_8079E7F0
    // 0x8079E7C8: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
        goto L_8079E7F0;
    // 0x8079E7C8: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8079E7CC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_8079E7D0:
    // 0x8079E7D0: nop

    // 0x8079E7D4: bc1fl       L_8079E7E8
    if (!c1cs) {
        // 0x8079E7D8: add.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_8079E7E8;
    }
    goto skip_14;
    // 0x8079E7D8: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    skip_14:
    // 0x8079E7DC: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8079E7E0: nop

    // 0x8079E7E4: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_8079E7E8:
    // 0x8079E7E8: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1914) << 16);
    // 0x8079E7EC: swc1        $f12, -0xBFC($at)
    MEM_W((int16_t)RELOC_LO16(835, 0X1914), ctx->r1) = ctx->f12.u32l;
L_8079E7F0:
    // 0x8079E7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079E7F4:
    // 0x8079E7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079E7F8: jr          $ra
    // 0x8079E7FC: nop

    return;
    // 0x8079E7FC: nop

;}
RECOMP_FUNC void func_806A7AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A7AC4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x806A7AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806A7ACC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806A7AD0: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806A7AD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806A7AD8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806A7ADC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A7AE0: jal         0x80048F84
    // 0x806A7AE4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x806A7AE4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x806A7AE8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806A7AEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806A7AF0: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806A7AF4: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x806A7AF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806A7AFC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806A7B00: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x806A7B04: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x806A7B08: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x806A7B0C: nop

    // 0x806A7B10: bc1fl       L_806A7B2C
    if (!c1cs) {
        // 0x806A7B14: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806A7B2C;
    }
    goto skip_0;
    // 0x806A7B14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x806A7B18: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x806A7B1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806A7B20: b           L_806A7B44
    // 0x806A7B24: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
        goto L_806A7B44;
    // 0x806A7B24: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x806A7B28: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806A7B2C:
    // 0x806A7B2C: nop

    // 0x806A7B30: c.le.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl <= ctx->f14.fl;
    // 0x806A7B34: nop

    // 0x806A7B38: bc1fl       L_806A7B48
    if (!c1cs) {
        // 0x806A7B3C: swc1        $f14, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f14.u32l;
            goto L_806A7B48;
    }
    goto skip_1;
    // 0x806A7B3C: swc1        $f14, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f14.u32l;
    skip_1:
    // 0x806A7B40: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
L_806A7B44:
    // 0x806A7B44: swc1        $f14, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f14.u32l;
L_806A7B48:
    // 0x806A7B48: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806A7B4C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806A7B50: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806A7B54: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x806A7B58: lbu         $t0, 0x2C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2C);
    // 0x806A7B5C: beql        $t0, $zero, L_806A7CE0
    if (ctx->r8 == 0) {
        // 0x806A7B60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806A7CE0;
    }
    goto skip_2;
    // 0x806A7B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806A7B64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806A7B68: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x806A7B6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806A7B70: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(586, 0X464) << 16);
    // 0x806A7B74: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x806A7B78: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    // 0x806A7B7C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x806A7B80: lwc1        $f18, 0x84($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806A7B84: lwc1        $f10, 0x7E24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(586, 0X464));
    // 0x806A7B88: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x806A7B8C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x806A7B90: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806A7B94: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x806A7B98: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x806A7B9C: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x806A7BA0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x806A7BA4: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x806A7BA8: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x806A7BAC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x806A7BB0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x806A7BB4: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x806A7BB8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x806A7BBC: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x806A7BC0: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x806A7BC4: lw          $t9, 0x10($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X10);
    // 0x806A7BC8: jalr        $t9
    // 0x806A7BCC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x806A7BCC: nop

    after_1:
    // 0x806A7BD0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806A7BD4: jal         0x80067BBC
    // 0x806A7BD8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806A7BD8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x806A7BDC: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x806A7BE0: jal         0x80067818
    // 0x806A7BE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806A7BE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x806A7BE8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x806A7BEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806A7BF0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x806A7BF4: lw          $t5, 0x40($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X40);
    // 0x806A7BF8: jal         0x8004A97C
    // 0x806A7BFC: lhu         $a0, 0x18($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X18);
    func_8004A97C(rdram, ctx);
        goto after_4;
    // 0x806A7BFC: lhu         $a0, 0x18($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X18);
    after_4:
    // 0x806A7C00: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x806A7C04: jal         0x80065954
    // 0x806A7C08: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x806A7C08: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x806A7C0C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806A7C10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806A7C14: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806A7C18: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x806A7C1C: nop

    // 0x806A7C20: bc1fl       L_806A7C4C
    if (!c1cs) {
        // 0x806A7C24: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_806A7C4C;
    }
    goto skip_3;
    // 0x806A7C24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x806A7C28: jal         0x80066DE4
    // 0x806A7C2C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x806A7C2C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_6:
    // 0x806A7C30: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806A7C34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806A7C38: nop

    // 0x806A7C3C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x806A7C40: b           L_806A7CDC
    // 0x806A7C44: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
        goto L_806A7CDC;
    // 0x806A7C44: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x806A7C48: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_806A7C4C:
    // 0x806A7C4C: nop

    // 0x806A7C50: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x806A7C54: nop

    // 0x806A7C58: bc1fl       L_806A7C6C
    if (!c1cs) {
        // 0x806A7C5C: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_806A7C6C;
    }
    goto skip_4;
    // 0x806A7C5C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_4:
    // 0x806A7C60: b           L_806A7CAC
    // 0x806A7C64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_806A7CAC;
    // 0x806A7C64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x806A7C68: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_806A7C6C:
    // 0x806A7C6C: nop

    // 0x806A7C70: bc1fl       L_806A7C84
    if (!c1cs) {
        // 0x806A7C74: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_806A7C84;
    }
    goto skip_5;
    // 0x806A7C74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_5:
    // 0x806A7C78: b           L_806A7CAC
    // 0x806A7C7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_806A7CAC;
    // 0x806A7C7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806A7C80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_806A7C84:
    // 0x806A7C84: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806A7C88: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x806A7C8C: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x806A7C90: nop

    // 0x806A7C94: bc1f        L_806A7CAC
    if (!c1cs) {
        // 0x806A7C98: nop
    
            goto L_806A7CAC;
    }
    // 0x806A7C98: nop

    // 0x806A7C9C: jal         0x800653D8
    // 0x806A7CA0: nop

    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x806A7CA0: nop

    after_7:
    // 0x806A7CA4: b           L_806A7CAC
    // 0x806A7CA8: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
        goto L_806A7CAC;
    // 0x806A7CA8: andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
L_806A7CAC:
    // 0x806A7CAC: bltz        $v1, L_806A7CDC
    if (SIGNED(ctx->r3) < 0) {
        // 0x806A7CB0: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_806A7CDC;
    }
    // 0x806A7CB0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806A7CB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806A7CB8: jal         0x80066DE4
    // 0x806A7CBC: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x806A7CBC: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_8:
    // 0x806A7CC0: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x806A7CC4: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(586, 0X440) << 16);
    // 0x806A7CC8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x806A7CCC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x806A7CD0: lwc1        $f8, 0x7E00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(586, 0X440));
    // 0x806A7CD4: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x806A7CD8: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
L_806A7CDC:
    // 0x806A7CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806A7CE0:
    // 0x806A7CE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806A7CE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x806A7CE8: jr          $ra
    // 0x806A7CEC: nop

    return;
    // 0x806A7CEC: nop

;}
RECOMP_FUNC void func_80438560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438560: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80438564: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80438568: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043856C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80438570: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80438574: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80438578: jal         0x804383DC
    // 0x8043857C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    func_804383DC(rdram, ctx);
        goto after_0;
    // 0x8043857C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    after_0:
    // 0x80438580: bne         $v0, $zero, L_80438598
    if (ctx->r2 != 0) {
        // 0x80438584: lui         $t7, 0x8044
        ctx->r15 = S32(RELOC_HI16(77, 0X1F1C) << 16);
            goto L_80438598;
    }
    // 0x80438584: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(77, 0X1F1C) << 16);
    // 0x80438588: jal         0x800445A4
    // 0x8043858C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8043858C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80438590: b           L_80438618
    // 0x80438594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80438618;
    // 0x80438594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80438598:
    // 0x80438598: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8043859C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804385A0: addiu       $t7, $t7, -0x7844
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(77, 0X1F1C));
    // 0x804385A4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804385A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804385AC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x804385B0: jal         0x80438520
    // 0x804385B4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    func_80438520(rdram, ctx);
        goto after_2;
    // 0x804385B4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x804385B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804385BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804385C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804385C4: jal         0x80438628
    // 0x804385C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80438628(rdram, ctx);
        goto after_3;
    // 0x804385C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x804385CC: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804385D0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804385D4: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x804385D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804385DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804385E0: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804385E4: jal         0x804369D8
    // 0x804385E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804369D8(rdram, ctx);
        goto after_4;
    // 0x804385E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804385EC: bne         $v0, $zero, L_80438604
    if (ctx->r2 != 0) {
        // 0x804385F0: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_80438604;
    }
    // 0x804385F0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x804385F4: jal         0x800445A4
    // 0x804385F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x804385F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804385FC: b           L_80438618
    // 0x80438600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80438618;
    // 0x80438600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80438604:
    // 0x80438604: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(77, 0X1C98) << 16);
    // 0x80438608: addiu       $t2, $t2, -0x7AC8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(77, 0X1C98));
    // 0x8043860C: sh          $t1, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r9;
    // 0x80438610: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x80438614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80438618:
    // 0x80438618: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043861C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80438620: jr          $ra
    // 0x80438624: nop

    return;
    // 0x80438624: nop

;}
RECOMP_FUNC void func_80715840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715840: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80715844: jr          $ra
    // 0x80715848: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x80715848: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_807B4B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4B3C: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x807B4B40: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x807B4B44: bltz        $v0, L_807B4B98
    if (SIGNED(ctx->r2) < 0) {
        // 0x807B4B48: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_807B4B98;
    }
    // 0x807B4B48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x807B4B4C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x807B4B50: addu        $a1, $a0, $t6
    ctx->r5 = ADD32(ctx->r4, ctx->r14);
    // 0x807B4B54: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_807B4B58:
    // 0x807B4B58: div         $zero, $a3, $v0
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r2)));
    // 0x807B4B5C: bne         $v0, $zero, L_807B4B68
    if (ctx->r2 != 0) {
        // 0x807B4B60: nop
    
            goto L_807B4B68;
    }
    // 0x807B4B60: nop

    // 0x807B4B64: break       7
    do_break(2155563876);
L_807B4B68:
    // 0x807B4B68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x807B4B6C: bne         $v0, $at, L_807B4B80
    if (ctx->r2 != ctx->r1) {
        // 0x807B4B70: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_807B4B80;
    }
    // 0x807B4B70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x807B4B74: bne         $a3, $at, L_807B4B80
    if (ctx->r7 != ctx->r1) {
        // 0x807B4B78: nop
    
            goto L_807B4B80;
    }
    // 0x807B4B78: nop

    // 0x807B4B7C: break       6
    do_break(2155563900);
L_807B4B80:
    // 0x807B4B80: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x807B4B84: mfhi        $t7
    ctx->r15 = hi;
    // 0x807B4B88: mflo        $a3
    ctx->r7 = lo;
    // 0x807B4B8C: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x807B4B90: bgez        $v1, L_807B4B58
    if (SIGNED(ctx->r3) >= 0) {
        // 0x807B4B94: sw          $t7, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r15;
            goto L_807B4B58;
    }
    // 0x807B4B94: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
L_807B4B98:
    // 0x807B4B98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807B4B9C: blez        $a2, L_807B4D08
    if (SIGNED(ctx->r6) <= 0) {
        // 0x807B4BA0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_807B4D08;
    }
    // 0x807B4BA0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x807B4BA4: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x807B4BA8: beq         $a3, $zero, L_807B4C04
    if (ctx->r7 == 0) {
        // 0x807B4BAC: or          $t1, $a3, $zero
        ctx->r9 = ctx->r7 | 0;
            goto L_807B4C04;
    }
    // 0x807B4BAC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x807B4BB0: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x807B4BB4: addu        $a1, $a0, $t8
    ctx->r5 = ADD32(ctx->r4, ctx->r24);
    // 0x807B4BB8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_807B4BBC:
    // 0x807B4BBC: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
    // 0x807B4BC0: bne         $a2, $a3, L_807B4BCC
    if (ctx->r6 != ctx->r7) {
        // 0x807B4BC4: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_807B4BCC;
    }
    // 0x807B4BC4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x807B4BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807B4BCC:
    // 0x807B4BCC: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x807B4BD0: bne         $t0, $zero, L_807B4BF0
    if (ctx->r8 != 0) {
        // 0x807B4BD4: addiu       $t9, $t0, 0x10
        ctx->r25 = ADD32(ctx->r8, 0X10);
            goto L_807B4BF0;
    }
    // 0x807B4BD4: addiu       $t9, $t0, 0x10
    ctx->r25 = ADD32(ctx->r8, 0X10);
    // 0x807B4BD8: beq         $v0, $zero, L_807B4BE8
    if (ctx->r2 == 0) {
        // 0x807B4BDC: nop
    
            goto L_807B4BE8;
    }
    // 0x807B4BDC: nop

    // 0x807B4BE0: b           L_807B4BF8
    // 0x807B4BE4: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
        goto L_807B4BF8;
    // 0x807B4BE4: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_807B4BE8:
    // 0x807B4BE8: b           L_807B4BF8
    // 0x807B4BEC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_807B4BF8;
    // 0x807B4BEC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_807B4BF0:
    // 0x807B4BF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B4BF4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_807B4BF8:
    // 0x807B4BF8: bne         $t1, $a3, L_807B4BBC
    if (ctx->r9 != ctx->r7) {
        // 0x807B4BFC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_807B4BBC;
    }
    // 0x807B4BFC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x807B4C00: beq         $a3, $a2, L_807B4D08
    if (ctx->r7 == ctx->r6) {
        // 0x807B4C04: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_807B4D08;
    }
L_807B4C04:
    // 0x807B4C04: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x807B4C08: addu        $a1, $a0, $t3
    ctx->r5 = ADD32(ctx->r4, ctx->r11);
    // 0x807B4C0C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_807B4C10:
    // 0x807B4C10: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x807B4C14: bne         $a2, $t4, L_807B4C20
    if (ctx->r6 != ctx->r12) {
        // 0x807B4C18: addiu       $t6, $v1, 0x2
        ctx->r14 = ADD32(ctx->r3, 0X2);
            goto L_807B4C20;
    }
    // 0x807B4C18: addiu       $t6, $v1, 0x2
    ctx->r14 = ADD32(ctx->r3, 0X2);
    // 0x807B4C1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807B4C20:
    // 0x807B4C20: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x807B4C24: addiu       $t8, $v1, 0x3
    ctx->r24 = ADD32(ctx->r3, 0X3);
    // 0x807B4C28: bne         $t0, $zero, L_807B4C48
    if (ctx->r8 != 0) {
        // 0x807B4C2C: addiu       $t5, $t0, 0x10
        ctx->r13 = ADD32(ctx->r8, 0X10);
            goto L_807B4C48;
    }
    // 0x807B4C2C: addiu       $t5, $t0, 0x10
    ctx->r13 = ADD32(ctx->r8, 0X10);
    // 0x807B4C30: beq         $v0, $zero, L_807B4C40
    if (ctx->r2 == 0) {
        // 0x807B4C34: nop
    
            goto L_807B4C40;
    }
    // 0x807B4C34: nop

    // 0x807B4C38: b           L_807B4C50
    // 0x807B4C3C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
        goto L_807B4C50;
    // 0x807B4C3C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_807B4C40:
    // 0x807B4C40: b           L_807B4C50
    // 0x807B4C44: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_807B4C50;
    // 0x807B4C44: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_807B4C48:
    // 0x807B4C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B4C4C: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_807B4C50:
    // 0x807B4C50: bnel        $a2, $t6, L_807B4C60
    if (ctx->r6 != ctx->r14) {
        // 0x807B4C54: lw          $a0, 0x4($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X4);
            goto L_807B4C60;
    }
    goto skip_0;
    // 0x807B4C54: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    skip_0:
    // 0x807B4C58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B4C5C: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
L_807B4C60:
    // 0x807B4C60: bne         $a0, $zero, L_807B4C80
    if (ctx->r4 != 0) {
        // 0x807B4C64: addiu       $t7, $a0, 0x10
        ctx->r15 = ADD32(ctx->r4, 0X10);
            goto L_807B4C80;
    }
    // 0x807B4C64: addiu       $t7, $a0, 0x10
    ctx->r15 = ADD32(ctx->r4, 0X10);
    // 0x807B4C68: beq         $v0, $zero, L_807B4C78
    if (ctx->r2 == 0) {
        // 0x807B4C6C: nop
    
            goto L_807B4C78;
    }
    // 0x807B4C6C: nop

    // 0x807B4C70: b           L_807B4C88
    // 0x807B4C74: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
        goto L_807B4C88;
    // 0x807B4C74: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
L_807B4C78:
    // 0x807B4C78: b           L_807B4C88
    // 0x807B4C7C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
        goto L_807B4C88;
    // 0x807B4C7C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_807B4C80:
    // 0x807B4C80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B4C84: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
L_807B4C88:
    // 0x807B4C88: bnel        $a2, $t8, L_807B4C98
    if (ctx->r6 != ctx->r24) {
        // 0x807B4C8C: lw          $a0, 0x8($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X8);
            goto L_807B4C98;
    }
    goto skip_1;
    // 0x807B4C8C: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    skip_1:
    // 0x807B4C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B4C94: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
L_807B4C98:
    // 0x807B4C98: bne         $a0, $zero, L_807B4CB8
    if (ctx->r4 != 0) {
        // 0x807B4C9C: addiu       $t9, $a0, 0x10
        ctx->r25 = ADD32(ctx->r4, 0X10);
            goto L_807B4CB8;
    }
    // 0x807B4C9C: addiu       $t9, $a0, 0x10
    ctx->r25 = ADD32(ctx->r4, 0X10);
    // 0x807B4CA0: beq         $v0, $zero, L_807B4CB0
    if (ctx->r2 == 0) {
        // 0x807B4CA4: nop
    
            goto L_807B4CB0;
    }
    // 0x807B4CA4: nop

    // 0x807B4CA8: b           L_807B4CC0
    // 0x807B4CAC: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
        goto L_807B4CC0;
    // 0x807B4CAC: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
L_807B4CB0:
    // 0x807B4CB0: b           L_807B4CC0
    // 0x807B4CB4: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
        goto L_807B4CC0;
    // 0x807B4CB4: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
L_807B4CB8:
    // 0x807B4CB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B4CBC: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
L_807B4CC0:
    // 0x807B4CC0: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x807B4CC4: bnel        $a2, $a0, L_807B4CD4
    if (ctx->r6 != ctx->r4) {
        // 0x807B4CC8: lw          $v1, 0xC($a1)
        ctx->r3 = MEM_W(ctx->r5, 0XC);
            goto L_807B4CD4;
    }
    goto skip_2;
    // 0x807B4CC8: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
    skip_2:
    // 0x807B4CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B4CD0: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
L_807B4CD4:
    // 0x807B4CD4: bne         $v1, $zero, L_807B4CF4
    if (ctx->r3 != 0) {
        // 0x807B4CD8: addiu       $t3, $v1, 0x10
        ctx->r11 = ADD32(ctx->r3, 0X10);
            goto L_807B4CF4;
    }
    // 0x807B4CD8: addiu       $t3, $v1, 0x10
    ctx->r11 = ADD32(ctx->r3, 0X10);
    // 0x807B4CDC: beq         $v0, $zero, L_807B4CEC
    if (ctx->r2 == 0) {
        // 0x807B4CE0: nop
    
            goto L_807B4CEC;
    }
    // 0x807B4CE0: nop

    // 0x807B4CE4: b           L_807B4CFC
    // 0x807B4CE8: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
        goto L_807B4CFC;
    // 0x807B4CE8: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
L_807B4CEC:
    // 0x807B4CEC: b           L_807B4CFC
    // 0x807B4CF0: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
        goto L_807B4CFC;
    // 0x807B4CF0: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
L_807B4CF4:
    // 0x807B4CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B4CF8: sw          $t3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r11;
L_807B4CFC:
    // 0x807B4CFC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x807B4D00: bne         $a0, $a2, L_807B4C10
    if (ctx->r4 != ctx->r6) {
        // 0x807B4D04: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_807B4C10;
    }
    // 0x807B4D04: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_807B4D08:
    // 0x807B4D08: jr          $ra
    // 0x807B4D0C: nop

    return;
    // 0x807B4D0C: nop

;}
RECOMP_FUNC void func_807C4004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C4004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C4008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C400C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807C4010: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(907, 0X1458) << 16);
    // 0x807C4014: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807C4018: addiu       $t6, $t6, 0x47B8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(907, 0X1458));
    // 0x807C401C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807C4020: lui         $t0, 0x807C
    ctx->r8 = S32(RELOC_HI16(907, 0XC7C) << 16);
    // 0x807C4024: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807C4028: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x807C402C: addiu       $t0, $t0, 0x3FDC
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(907, 0XC7C));
    // 0x807C4030: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
    // 0x807C4034: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807C4038: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807C403C: sh          $t9, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r25;
    // 0x807C4040: sw          $t0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r8;
    // 0x807C4044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C4048: jal         0x807C40C8
    // 0x807C404C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807C40C8(rdram, ctx);
        goto after_0;
    // 0x807C404C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x807C4050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C4054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C4058: jr          $ra
    // 0x807C405C: nop

    return;
    // 0x807C405C: nop

;}
RECOMP_FUNC void func_806CFDF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFDF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CFDFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CFE00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806CFE04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806CFE08: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x806CFE0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CFE10: jal         0x806D093C
    // 0x806CFE14: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_806D093C(rdram, ctx);
        goto after_0;
    // 0x806CFE14: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x806CFE18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CFE1C: jal         0x806D02A4
    // 0x806CFE20: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_806D02A4(rdram, ctx);
        goto after_1;
    // 0x806CFE20: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x806CFE24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CFE28: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(607, 0X17C) << 16);
    // 0x806CFE2C: addiu       $t6, $t6, -0x6E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(607, 0X17C));
    // 0x806CFE30: jal         0x806CFD94
    // 0x806CFE34: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    func_806CFD94(rdram, ctx);
        goto after_2;
    // 0x806CFE34: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    after_2:
    // 0x806CFE38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CFE3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CFE40: jr          $ra
    // 0x806CFE44: nop

    return;
    // 0x806CFE44: nop

;}
RECOMP_FUNC void func_80031D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031D88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031D8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031D90: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031D94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80031D98: jal         0x800310A0
    // 0x80031D9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031D9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031DA0: jal         0x80021A44
    // 0x80031DA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80021A44(rdram, ctx);
        goto after_1;
    // 0x80031DA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80031DA8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80031DAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031DB0: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x80031DB4: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x80031DB8: beq         $t7, $zero, L_80031DD0
    if (ctx->r15 == 0) {
        // 0x80031DBC: nop
    
            goto L_80031DD0;
    }
    // 0x80031DBC: nop

    // 0x80031DC0: jal         0x8002CEEC
    // 0x80031DC4: nop

    func_8002CEEC(rdram, ctx);
        goto after_2;
    // 0x80031DC4: nop

    after_2:
    // 0x80031DC8: b           L_80031DDC
    // 0x80031DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80031DDC;
    // 0x80031DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031DD0:
    // 0x80031DD0: jal         0x800310D0
    // 0x80031DD4: nop

    func_800310D0(rdram, ctx);
        goto after_3;
    // 0x80031DD4: nop

    after_3:
    // 0x80031DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031DDC:
    // 0x80031DDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031DE0: jr          $ra
    // 0x80031DE4: nop

    return;
    // 0x80031DE4: nop

;}
RECOMP_FUNC void func_805306C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805306C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805306C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805306CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805306D0: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805306D4: addiu       $at, $zero, 0x414F
    ctx->r1 = ADD32(0, 0X414F);
    // 0x805306D8: beq         $v0, $at, L_805306F8
    if (ctx->r2 == ctx->r1) {
        // 0x805306DC: addiu       $at, $zero, 0x468B
        ctx->r1 = ADD32(0, 0X468B);
            goto L_805306F8;
    }
    // 0x805306DC: addiu       $at, $zero, 0x468B
    ctx->r1 = ADD32(0, 0X468B);
    // 0x805306E0: beq         $v0, $at, L_80530720
    if (ctx->r2 == ctx->r1) {
        // 0x805306E4: addiu       $at, $zero, 0x4732
        ctx->r1 = ADD32(0, 0X4732);
            goto L_80530720;
    }
    // 0x805306E4: addiu       $at, $zero, 0x4732
    ctx->r1 = ADD32(0, 0X4732);
    // 0x805306E8: beq         $v0, $at, L_80530748
    if (ctx->r2 == ctx->r1) {
        // 0x805306EC: nop
    
            goto L_80530748;
    }
    // 0x805306EC: nop

    // 0x805306F0: b           L_80530768
    // 0x805306F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80530768;
    // 0x805306F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805306F8:
    // 0x805306F8: jal         0x80067E68
    // 0x805306FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_0;
    // 0x805306FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80530700: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80530704: jal         0x80067818
    // 0x80530708: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80530708: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8053070C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80530710: jal         0x8053056C
    // 0x80530714: addiu       $a1, $zero, 0x4034
    ctx->r5 = ADD32(0, 0X4034);
    func_8053056C(rdram, ctx);
        goto after_2;
    // 0x80530714: addiu       $a1, $zero, 0x4034
    ctx->r5 = ADD32(0, 0X4034);
    after_2:
    // 0x80530718: b           L_80530768
    // 0x8053071C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80530768;
    // 0x8053071C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80530720:
    // 0x80530720: jal         0x80067E68
    // 0x80530724: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x80530724: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80530728: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8053072C: jal         0x80067818
    // 0x80530730: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80530730: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80530734: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80530738: jal         0x8053056C
    // 0x8053073C: addiu       $a1, $zero, 0x4035
    ctx->r5 = ADD32(0, 0X4035);
    func_8053056C(rdram, ctx);
        goto after_5;
    // 0x8053073C: addiu       $a1, $zero, 0x4035
    ctx->r5 = ADD32(0, 0X4035);
    after_5:
    // 0x80530740: b           L_80530768
    // 0x80530744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80530768;
    // 0x80530744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80530748:
    // 0x80530748: jal         0x80067E68
    // 0x8053074C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80067E68(rdram, ctx);
        goto after_6;
    // 0x8053074C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80530750: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80530754: jal         0x80067818
    // 0x80530758: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x80530758: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8053075C: jal         0x805305E8
    // 0x80530760: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805305E8(rdram, ctx);
        goto after_8;
    // 0x80530760: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_8:
    // 0x80530764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80530768:
    // 0x80530768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8053076C: jr          $ra
    // 0x80530770: nop

    return;
    // 0x80530770: nop

;}
RECOMP_FUNC void func_8007B580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B580: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
    // 0x8007B584: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x8007B588: sw          $a3, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r7;
    // 0x8007B58C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8007B590: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8007B594: jr          $ra
    // 0x8007B598: nop

    return;
    // 0x8007B598: nop

;}
RECOMP_FUNC void func_807923A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807923A0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x807923A4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x807923A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807923AC: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AF8) << 16);
    // 0x807923B0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x807923B4: lwc1        $f4, 0x7E48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AF8));
    // 0x807923B8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x807923BC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x807923C0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x807923C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x807923C8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x807923CC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x807923D0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x807923D4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x807923D8: lui         $s0, 0x8079
    ctx->r16 = S32(RELOC_HI16(817, 0X79D8) << 16);
    // 0x807923DC: lui         $s1, 0x8079
    ctx->r17 = S32(RELOC_HI16(817, 0X79CC) << 16);
    // 0x807923E0: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x807923E4: lui         $s5, 0x8079
    ctx->r21 = S32(RELOC_HI16(817, 0X79E4) << 16);
    // 0x807923E8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x807923EC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x807923F0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x807923F4: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x807923F8: addiu       $s5, $s5, 0x7D34
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(817, 0X79E4));
    // 0x807923FC: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x80792400: addiu       $s1, $s1, 0x7D1C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(817, 0X79CC));
    // 0x80792404: addiu       $s0, $s0, 0x7D28
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(817, 0X79D8));
    // 0x80792408: addiu       $s4, $sp, 0x48
    ctx->r20 = ADD32(ctx->r29, 0X48);
    // 0x8079240C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80792410: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80792414: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x80792418: swc1        $f2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f2.u32l;
    // 0x8079241C: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
L_80792420:
    // 0x80792420: lwc1        $f6, 0x84($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X84);
    // 0x80792424: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80792428: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8079242C: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x80792430: lwc1        $f8, 0x88($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X88);
    // 0x80792434: lw          $t6, 0xA68($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XA68);
    // 0x80792438: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x8079243C: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80792440: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x80792444: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80792448: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8079244C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80792450: lw          $t9, 0x28($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X28);
    // 0x80792454: jalr        $t9
    // 0x80792458: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80792458: nop

    after_0:
    // 0x8079245C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80792460: bne         $s0, $s5, L_80792420
    if (ctx->r16 != ctx->r21) {
        // 0x80792464: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80792420;
    }
    // 0x80792464: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80792468: lw          $v0, 0x478($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X478);
    // 0x8079246C: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80792470: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80792474: lbu         $t8, 0xF0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XF0);
    // 0x80792478: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x8079247C: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80792480: andi        $t0, $t8, 0x7
    ctx->r8 = ctx->r24 & 0X7;
    // 0x80792484: addiu       $t1, $t0, 0x20
    ctx->r9 = ADD32(ctx->r8, 0X20);
    // 0x80792488: sb          $t1, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = ctx->r9;
    // 0x8079248C: lw          $t2, 0x478($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X478);
    // 0x80792490: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80792494: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x80792498: sb          $zero, 0xF2($t2)
    MEM_B(0XF2, ctx->r10) = 0;
    // 0x8079249C: sb          $t3, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r11;
    // 0x807924A0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807924A4: sb          $t4, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r12;
    // 0x807924A8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807924AC: jal         0x807907AC
    // 0x807924B0: sb          $t5, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r13;
    func_807907AC(rdram, ctx);
        goto after_1;
    // 0x807924B0: sb          $t5, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r13;
    after_1:
    // 0x807924B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x807924B8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x807924BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807924C0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807924C4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x807924C8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x807924CC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x807924D0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x807924D4: jr          $ra
    // 0x807924D8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x807924D8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80790878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790878: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079087C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80790880: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80790884: lw          $v0, 0x1E4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E4);
    // 0x80790888: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8079088C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80790890: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80790894: bnel        $at, $zero, L_807908A8
    if (ctx->r1 != 0) {
        // 0x80790898: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_807908A8;
    }
    goto skip_0;
    // 0x80790898: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    skip_0:
    // 0x8079089C: b           L_807908BC
    // 0x807908A0: subu        $a0, $t6, $v0
    ctx->r4 = SUB32(ctx->r14, ctx->r2);
        goto L_807908BC;
    // 0x807908A0: subu        $a0, $t6, $v0
    ctx->r4 = SUB32(ctx->r14, ctx->r2);
    // 0x807908A4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
L_807908A8:
    // 0x807908A8: beq         $at, $zero, L_807908BC
    if (ctx->r1 == 0) {
        // 0x807908AC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_807908BC;
    }
    // 0x807908AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807908B0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x807908B4: b           L_807908BC
    // 0x807908B8: subu        $a0, $t7, $v0
    ctx->r4 = SUB32(ctx->r15, ctx->r2);
        goto L_807908BC;
    // 0x807908B8: subu        $a0, $t7, $v0
    ctx->r4 = SUB32(ctx->r15, ctx->r2);
L_807908BC:
    // 0x807908BC: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x807908C0: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x807908C4: jal         0x80067D5C
    // 0x807908C8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x807908C8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x807908CC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x807908D0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x807908D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x807908D8: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    // 0x807908DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x807908E0: bnel        $a1, $at, L_80790908
    if (ctx->r5 != ctx->r1) {
        // 0x807908E4: sw          $a2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r6;
            goto L_80790908;
    }
    goto skip_1;
    // 0x807908E4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    skip_1:
    // 0x807908E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x807908EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807908F0: jal         0x80067F78
    // 0x807908F4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x807908F4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x807908F8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x807908FC: b           L_8079092C
    // 0x80790900: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
        goto L_8079092C;
    // 0x80790900: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
    // 0x80790904: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
L_80790908:
    // 0x80790908: jal         0x80067930
    // 0x8079090C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x8079090C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80790910: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80790914: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80790918: bne         $v0, $at, L_8079092C
    if (ctx->r2 != ctx->r1) {
        // 0x8079091C: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_8079092C;
    }
    // 0x8079091C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80790920: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80790924: jal         0x800678F0
    // 0x80790928: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x80790928: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_3:
L_8079092C:
    // 0x8079092C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80790930: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80790934: jr          $ra
    // 0x80790938: nop

    return;
    // 0x80790938: nop

;}
RECOMP_FUNC void func_80715410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80715414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80715418: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8071541C: beq         $v0, $zero, L_80715438
    if (ctx->r2 == 0) {
        // 0x80715420: nop
    
            goto L_80715438;
    }
    // 0x80715420: nop

    // 0x80715424: lh          $t6, 0x144($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X144);
    // 0x80715428: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8071542C: lw          $t7, 0x138($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X138);
    // 0x80715430: b           L_80715444
    // 0x80715434: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
        goto L_80715444;
    // 0x80715434: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
L_80715438:
    // 0x80715438: jal         0x800447C8
    // 0x8071543C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x8071543C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80715440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80715444:
    // 0x80715444: jal         0x8071496C
    // 0x80715448: nop

    func_8071496C(rdram, ctx);
        goto after_1;
    // 0x80715448: nop

    after_1:
    // 0x8071544C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80715450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715454: jr          $ra
    // 0x80715458: nop

    return;
    // 0x80715458: nop

;}
RECOMP_FUNC void func_8004012C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004012C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040134: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80040138: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8004013C: beq         $v0, $at, L_8004017C
    if (ctx->r2 == ctx->r1) {
        // 0x80040140: addiu       $at, $zero, 0x401C
        ctx->r1 = ADD32(0, 0X401C);
            goto L_8004017C;
    }
    // 0x80040140: addiu       $at, $zero, 0x401C
    ctx->r1 = ADD32(0, 0X401C);
    // 0x80040144: beq         $v0, $at, L_8004019C
    if (ctx->r2 == ctx->r1) {
        // 0x80040148: addiu       $at, $zero, 0x401D
        ctx->r1 = ADD32(0, 0X401D);
            goto L_8004019C;
    }
    // 0x80040148: addiu       $at, $zero, 0x401D
    ctx->r1 = ADD32(0, 0X401D);
    // 0x8004014C: beq         $v0, $at, L_8004019C
    if (ctx->r2 == ctx->r1) {
        // 0x80040150: addiu       $at, $zero, 0x401F
        ctx->r1 = ADD32(0, 0X401F);
            goto L_8004019C;
    }
    // 0x80040150: addiu       $at, $zero, 0x401F
    ctx->r1 = ADD32(0, 0X401F);
    // 0x80040154: beq         $v0, $at, L_8004019C
    if (ctx->r2 == ctx->r1) {
        // 0x80040158: addiu       $at, $zero, 0x406C
        ctx->r1 = ADD32(0, 0X406C);
            goto L_8004019C;
    }
    // 0x80040158: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8004015C: beq         $v0, $at, L_8004018C
    if (ctx->r2 == ctx->r1) {
        // 0x80040160: addiu       $at, $zero, 0x4144
        ctx->r1 = ADD32(0, 0X4144);
            goto L_8004018C;
    }
    // 0x80040160: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x80040164: beq         $v0, $at, L_8004018C
    if (ctx->r2 == ctx->r1) {
        // 0x80040168: addiu       $at, $zero, 0x4301
        ctx->r1 = ADD32(0, 0X4301);
            goto L_8004018C;
    }
    // 0x80040168: addiu       $at, $zero, 0x4301
    ctx->r1 = ADD32(0, 0X4301);
    // 0x8004016C: beq         $v0, $at, L_8004019C
    if (ctx->r2 == ctx->r1) {
        // 0x80040170: nop
    
            goto L_8004019C;
    }
    // 0x80040170: nop

    // 0x80040174: b           L_800401A8
    // 0x80040178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800401A8;
    // 0x80040178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004017C:
    // 0x8004017C: jal         0x8003FC48
    // 0x80040180: nop

    func_8003FC48(rdram, ctx);
        goto after_0;
    // 0x80040180: nop

    after_0:
    // 0x80040184: b           L_800401A8
    // 0x80040188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800401A8;
    // 0x80040188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004018C:
    // 0x8004018C: jal         0x8003FDC4
    // 0x80040190: nop

    func_8003FDC4(rdram, ctx);
        goto after_1;
    // 0x80040190: nop

    after_1:
    // 0x80040194: b           L_800401A8
    // 0x80040198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800401A8;
    // 0x80040198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004019C:
    // 0x8004019C: jal         0x8003FFD8
    // 0x800401A0: nop

    func_8003FFD8(rdram, ctx);
        goto after_2;
    // 0x800401A0: nop

    after_2:
    // 0x800401A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800401A8:
    // 0x800401A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800401AC: jr          $ra
    // 0x800401B0: nop

    return;
    // 0x800401B0: nop

;}
RECOMP_FUNC void func_8051B330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051B330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051B334: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8051B338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051B33C: lui         $a0, 0x8052
    ctx->r4 = S32(RELOC_HI16(297, 0X4C0) << 16);
    // 0x8051B340: lui         $a1, 0x8052
    ctx->r5 = S32(RELOC_HI16(297, 0X4D0) << 16);
    // 0x8051B344: addiu       $a1, $a1, -0x4800
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(297, 0X4D0));
    // 0x8051B348: addiu       $a0, $a0, -0x4810
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(297, 0X4C0));
    // 0x8051B34C: jal         0x8004667C
    // 0x8051B350: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8051B350: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x8051B354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051B358: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(297, 0X358) << 16);
    // 0x8051B35C: addiu       $v0, $v0, -0x4978
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(297, 0X358));
    // 0x8051B360: jr          $ra
    // 0x8051B364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8051B364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806CFCC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFCC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CFCC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CFCCC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806CFCD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806CFCD4: jal         0x806CF9B8
    // 0x806CFCD8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_806CF9B8(rdram, ctx);
        goto after_0;
    // 0x806CFCD8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x806CFCDC: jal         0x806CFA34
    // 0x806CFCE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CFA34(rdram, ctx);
        goto after_1;
    // 0x806CFCE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CFCE4: jal         0x806CFAB8
    // 0x806CFCE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CFAB8(rdram, ctx);
        goto after_2;
    // 0x806CFCE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806CFCEC: bne         $v0, $zero, L_806CFD80
    if (ctx->r2 != 0) {
        // 0x806CFCF0: addiu       $s1, $s0, 0xC4
        ctx->r17 = ADD32(ctx->r16, 0XC4);
            goto L_806CFD80;
    }
    // 0x806CFCF0: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x806CFCF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806CFCF8: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x806CFCFC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806CFD00: nop

    // 0x806CFD04: bc1fl       L_806CFD84
    if (!c1cs) {
        // 0x806CFD08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CFD84;
    }
    goto skip_0;
    // 0x806CFD08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806CFD0C: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x806CFD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CFD14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CFD18: bne         $t6, $zero, L_806CFD50
    if (ctx->r14 != 0) {
        // 0x806CFD1C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_806CFD50;
    }
    // 0x806CFD1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806CFD20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CFD24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CFD28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806CFD2C: jal         0x806D093C
    // 0x806CFD30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806D093C(rdram, ctx);
        goto after_3;
    // 0x806CFD30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x806CFD34: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AE4) << 16);
    // 0x806CFD38: lwc1        $f12, 0x1284($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AE4));
    // 0x806CFD3C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AE8) << 16);
    // 0x806CFD40: jal         0x806CF864
    // 0x806CFD44: lwc1        $f14, 0x1288($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AE8));
    func_806CF864(rdram, ctx);
        goto after_4;
    // 0x806CFD44: lwc1        $f14, 0x1288($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AE8));
    after_4:
    // 0x806CFD48: b           L_806CFD6C
    // 0x806CFD4C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_806CFD6C;
    // 0x806CFD4C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_806CFD50:
    // 0x806CFD50: jal         0x806D093C
    // 0x806CFD54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806D093C(rdram, ctx);
        goto after_5;
    // 0x806CFD54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x806CFD58: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AEC) << 16);
    // 0x806CFD5C: lwc1        $f12, 0x128C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AEC));
    // 0x806CFD60: jal         0x806CF864
    // 0x806CFD64: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_806CF864(rdram, ctx);
        goto after_6;
    // 0x806CFD64: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_6:
    // 0x806CFD68: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_806CFD6C:
    // 0x806CFD6C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AF0) << 16);
    // 0x806CFD70: lwc1        $f14, 0x1290($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AF0));
    // 0x806CFD74: jal         0x806CF864
    // 0x806CFD78: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    func_806CF864(rdram, ctx);
        goto after_7;
    // 0x806CFD78: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    after_7:
    // 0x806CFD7C: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
L_806CFD80:
    // 0x806CFD80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CFD84:
    // 0x806CFD84: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806CFD88: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806CFD8C: jr          $ra
    // 0x806CFD90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806CFD90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
