#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80028320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028328: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002832C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80028330: lw          $t6, 0x94($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X94);
    // 0x80028334: beq         $t6, $zero, L_8002834C
    if (ctx->r14 == 0) {
        // 0x80028338: nop
    
            goto L_8002834C;
    }
    // 0x80028338: nop

    // 0x8002833C: jal         0x80028170
    // 0x80028340: addiu       $a1, $a2, 0x80
    ctx->r5 = ADD32(ctx->r6, 0X80);
    func_80028170(rdram, ctx);
        goto after_0;
    // 0x80028340: addiu       $a1, $a2, 0x80
    ctx->r5 = ADD32(ctx->r6, 0X80);
    after_0:
    // 0x80028344: b           L_80028350
    // 0x80028348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80028350;
    // 0x80028348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002834C:
    // 0x8002834C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80028350:
    // 0x80028350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028354: jr          $ra
    // 0x80028358: nop

    return;
    // 0x80028358: nop

;}
RECOMP_FUNC void func_80438BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80438BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80438BC4: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80438BC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80438BCC: beq         $t6, $zero, L_80438C08
    if (ctx->r14 == 0) {
        // 0x80438BD0: nop
    
            goto L_80438C08;
    }
    // 0x80438BD0: nop

    // 0x80438BD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80438BD8: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80438BDC: jalr        $t9
    // 0x80438BE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80438BE0: nop

    after_0:
    // 0x80438BE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80438BE8: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80438BEC: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80438BF0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80438BF4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80438BF8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80438BFC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80438C00: b           L_80438C08
    // 0x80438C04: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80438C08;
    // 0x80438C04: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80438C08:
    // 0x80438C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80438C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80438C10: jr          $ra
    // 0x80438C14: nop

    return;
    // 0x80438C14: nop

;}
RECOMP_FUNC void func_80001198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001198: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8000119C: lui         $at, 0x1900
    ctx->r1 = S32(0X1900 << 16);
    // 0x800011A0: andi        $t0, $a3, 0xFFFF
    ctx->r8 = ctx->r7 & 0XFFFF;
    // 0x800011A4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800011A8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800011AC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800011B0: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x800011B4: andi        $t4, $a2, 0xFFFF
    ctx->r12 = ctx->r6 & 0XFFFF;
    // 0x800011B8: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800011BC: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800011C0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800011C4: jr          $ra
    // 0x800011C8: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    return;
    // 0x800011C8: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void func_806A9FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9FE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806A9FE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806A9FEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806A9FF0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806A9FF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806A9FF8: jal         0x806A98AC
    // 0x806A9FFC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_806A98AC(rdram, ctx);
        goto after_0;
    // 0x806A9FFC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x806AA000: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806AA004: bne         $v0, $at, L_806AA01C
    if (ctx->r2 != ctx->r1) {
        // 0x806AA008: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806AA01C;
    }
    // 0x806AA008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AA00C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AA010: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806AA014: jal         0x806AA784
    // 0x806AA018: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806AA018: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
L_806AA01C:
    // 0x806AA01C: jal         0x806A9A30
    // 0x806AA020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806A9A30(rdram, ctx);
        goto after_2;
    // 0x806AA020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806AA024: beq         $v0, $zero, L_806AA050
    if (ctx->r2 == 0) {
        // 0x806AA028: nop
    
            goto L_806AA050;
    }
    // 0x806AA028: nop

    // 0x806AA02C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806AA030: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x806AA034: lh          $t7, 0x144($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X144);
    // 0x806AA038: lh          $t1, 0x1BE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1BE);
    // 0x806AA03C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x806AA040: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806AA044: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x806AA048: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x806AA04C: sh          $t0, 0x12C($t3)
    MEM_H(0X12C, ctx->r11) = ctx->r8;
L_806AA050:
    // 0x806AA050: jal         0x806A99EC
    // 0x806AA054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806A99EC(rdram, ctx);
        goto after_3;
    // 0x806AA054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806AA058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806AA05C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AA060: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806AA064: jr          $ra
    // 0x806AA068: nop

    return;
    // 0x806AA068: nop

;}
RECOMP_FUNC void func_8075F224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075F224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8075F228: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8075F22C: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x8075F230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8075F234: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8075F238: lw          $t6, 0xEC0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XEC0);
    // 0x8075F23C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8075F240: lw          $t7, 0x230($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X230);
    // 0x8075F244: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8075F248: beql        $v0, $t7, L_8075F29C
    if (ctx->r2 == ctx->r15) {
        // 0x8075F24C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8075F29C;
    }
    goto skip_0;
    // 0x8075F24C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8075F250: sw          $v0, 0x230($v1)
    MEM_W(0X230, ctx->r3) = ctx->r2;
    // 0x8075F254: lw          $t8, 0xEC0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XEC0);
    // 0x8075F258: lui         $t2, 0x8076
    ctx->r10 = S32(RELOC_HI16(757, 0XCE8) << 16);
    // 0x8075F25C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8075F260: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8075F264: bne         $t9, $zero, L_8075F298
    if (ctx->r25 != 0) {
        // 0x8075F268: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_8075F298;
    }
    // 0x8075F268: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8075F26C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8075F270: lw          $t2, -0x5C8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(757, 0XCE8));
    // 0x8075F274: beq         $t2, $zero, L_8075F298
    if (ctx->r10 == 0) {
        // 0x8075F278: sw          $t2, 0x22C($v1)
        MEM_W(0X22C, ctx->r3) = ctx->r10;
            goto L_8075F298;
    }
    // 0x8075F278: sw          $t2, 0x22C($v1)
    MEM_W(0X22C, ctx->r3) = ctx->r10;
    // 0x8075F27C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8075F280: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x8075F284: jal         0x80067D5C
    // 0x8075F288: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x8075F288: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_0:
    // 0x8075F28C: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    // 0x8075F290: jal         0x80067818
    // 0x8075F294: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8075F294: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
L_8075F298:
    // 0x8075F298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8075F29C:
    // 0x8075F29C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8075F2A0: jr          $ra
    // 0x8075F2A4: nop

    return;
    // 0x8075F2A4: nop

;}
RECOMP_FUNC void StackCheck_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081910: bne         $a0, $zero, L_80081924
    if (ctx->r4 != 0) {
        // 0x80081914: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_80081924;
    }
    // 0x80081914: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80081918: addiu       $v0, $v0, -0x5C60
    ctx->r2 = ADD32(ctx->r2, -0X5C60);
    // 0x8008191C: jr          $ra
    // 0x80081920: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    return;
    // 0x80081920: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80081924:
    // 0x80081924: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x80081928: sw          $a2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r6;
    // 0x8008192C: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    // 0x80081930: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80081934: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80081938: addiu       $v1, $v1, -0x5C5C
    ctx->r3 = ADD32(ctx->r3, -0X5C5C);
    // 0x8008193C: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x80081940: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80081944: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x80081948: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008194C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80081950: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80081954: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80081958: beq         $v0, $zero, L_80081964
    if (ctx->r2 == 0) {
        // 0x8008195C: nop
    
            goto L_80081964;
    }
    // 0x8008195C: nop

    // 0x80081960: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_80081964:
    // 0x80081964: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80081968: addiu       $v0, $v0, -0x5C60
    ctx->r2 = ADD32(ctx->r2, -0X5C60);
    // 0x8008196C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80081970: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80081974: bnel        $t9, $zero, L_80081984
    if (ctx->r25 != 0) {
        // 0x80081978: lw          $t0, 0x14($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X14);
            goto L_80081984;
    }
    goto skip_0;
    // 0x80081978: lw          $t0, 0x14($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14);
    skip_0:
    // 0x8008197C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80081980: lw          $t0, 0x14($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14);
L_80081984:
    // 0x80081984: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081988: beq         $t0, $at, L_800819C0
    if (ctx->r8 == ctx->r1) {
        // 0x8008198C: nop
    
            goto L_800819C0;
    }
    // 0x8008198C: nop

    // 0x80081990: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80081994: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80081998: sltu        $at, $v0, $t1
    ctx->r1 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x8008199C: beq         $at, $zero, L_800819C0
    if (ctx->r1 == 0) {
        // 0x800819A0: nop
    
            goto L_800819C0;
    }
    // 0x800819A0: nop

    // 0x800819A4: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
L_800819A8:
    // 0x800819A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800819AC: sw          $t2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r10;
    // 0x800819B0: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800819B4: sltu        $at, $v0, $t3
    ctx->r1 = ctx->r2 < ctx->r11 ? 1 : 0;
    // 0x800819B8: bnel        $at, $zero, L_800819A8
    if (ctx->r1 != 0) {
        // 0x800819BC: lw          $t2, 0x10($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X10);
            goto L_800819A8;
    }
    goto skip_1;
    // 0x800819BC: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    skip_1:
L_800819C0:
    // 0x800819C0: jr          $ra
    // 0x800819C4: nop

    return;
    // 0x800819C4: nop

;}
RECOMP_FUNC void func_807AE58C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE58C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AE590: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AE594: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AE598: jal         0x807AC734
    // 0x807AE59C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807AC734(rdram, ctx);
        goto after_0;
    // 0x807AE59C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807AE5A0: beq         $v0, $zero, L_807AE5B8
    if (ctx->r2 == 0) {
        // 0x807AE5A4: nop
    
            goto L_807AE5B8;
    }
    // 0x807AE5A4: nop

    // 0x807AE5A8: jal         0x807AE0E0
    // 0x807AE5AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807AE0E0(rdram, ctx);
        goto after_1;
    // 0x807AE5AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807AE5B0: b           L_807AE66C
    // 0x807AE5B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807AE66C;
    // 0x807AE5B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AE5B8:
    // 0x807AE5B8: jal         0x807ADD60
    // 0x807AE5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807ADD60(rdram, ctx);
        goto after_2;
    // 0x807AE5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807AE5C0: beql        $v0, $zero, L_807AE5E0
    if (ctx->r2 == 0) {
        // 0x807AE5C4: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_807AE5E0;
    }
    goto skip_0;
    // 0x807AE5C4: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x807AE5C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE5CC: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE5D0: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x807AE5D4: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE5D8: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x807AE5DC: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_807AE5E0:
    // 0x807AE5E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE5E4: blez        $v0, L_807AE5F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807AE5E8: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_807AE5F4;
    }
    // 0x807AE5E8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x807AE5EC: b           L_807AE668
    // 0x807AE5F0: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
        goto L_807AE668;
    // 0x807AE5F0: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
L_807AE5F4:
    // 0x807AE5F4: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AE5FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE600: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x807AE604: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE608: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807AE60C: jal         0x807AEA24
    // 0x807AE610: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    func_807AEA24(rdram, ctx);
        goto after_3;
    // 0x807AE610: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    after_3:
    // 0x807AE614: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x807AE618: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE61C: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x807AE620: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE624: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x807AE628: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x807AE62C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807AE630: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE634: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x807AE638: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807AE63C: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
    // 0x807AE640: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x807AE644: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807AE648: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x807AE64C: lbu         $t4, 0xF0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XF0);
    // 0x807AE650: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x807AE654: addiu       $t6, $t5, 0x40
    ctx->r14 = ADD32(ctx->r13, 0X40);
    // 0x807AE658: sb          $t6, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = ctx->r14;
    // 0x807AE65C: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x807AE660: sb          $t7, 0xF2($t8)
    MEM_B(0XF2, ctx->r24) = ctx->r15;
    // 0x807AE664: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
L_807AE668:
    // 0x807AE668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AE66C:
    // 0x807AE66C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AE670: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AE674: jr          $ra
    // 0x807AE678: nop

    return;
    // 0x807AE678: nop

;}
RECOMP_FUNC void func_800810B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800810B8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800810BC: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800810C0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800810C4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800810C8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800810CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800810D0: bc1tl       L_800810FC
    if (c1cs) {
        // 0x800810D4: lwc1        $f0, 0x1C($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
            goto L_800810FC;
    }
    goto skip_0;
    // 0x800810D4: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    skip_0:
    // 0x800810D8: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800810DC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800810E0: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800810E4: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800810E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800810EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800810F0: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800810F4: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800810F8: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
L_800810FC:
    // 0x800810FC: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80081100: nop

    // 0x80081104: bc1tl       L_80081130
    if (c1cs) {
        // 0x80081108: lwc1        $f0, 0x2C($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
            goto L_80081130;
    }
    goto skip_1;
    // 0x80081108: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    skip_1:
    // 0x8008110C: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80081110: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80081114: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80081118: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8008111C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80081120: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80081124: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80081128: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x8008112C: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
L_80081130:
    // 0x80081130: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80081134: nop

    // 0x80081138: bc1tl       L_80081164
    if (c1cs) {
        // 0x8008113C: lwc1        $f0, 0x3C($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_80081164;
    }
    goto skip_2;
    // 0x8008113C: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    skip_2:
    // 0x80081140: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80081144: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80081148: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8008114C: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80081150: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80081154: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80081158: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x8008115C: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80081160: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
L_80081164:
    // 0x80081164: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80081168: nop

    // 0x8008116C: bc1t        L_800811C8
    if (c1cs) {
        // 0x80081170: nop
    
            goto L_800811C8;
    }
    // 0x80081170: nop

    // 0x80081174: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081178: nop

    // 0x8008117C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80081180: nop

    // 0x80081184: bc1tl       L_800811B4
    if (c1cs) {
        // 0x80081188: lwc1        $f6, 0x30($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
            goto L_800811B4;
    }
    goto skip_3;
    // 0x80081188: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    skip_3:
    // 0x8008118C: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80081190: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80081194: lwc1        $f16, 0x34($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80081198: mul.s       $f18, $f0, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8008119C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800811A0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800811A4: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x800811A8: jr          $ra
    // 0x800811AC: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800811AC: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x800811B0: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
L_800811B4:
    // 0x800811B4: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800811B8: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800811BC: add.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x800811C0: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x800811C4: swc1        $f16, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f16.u32l;
L_800811C8:
    // 0x800811C8: jr          $ra
    // 0x800811CC: nop

    return;
    // 0x800811CC: nop

;}
RECOMP_FUNC void func_80080824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080824: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80080828: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008082C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80080830: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80080834: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80080838: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x8008083C: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80080840: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80080844: bc1tl       L_80080884
    if (c1cs) {
        // 0x80080848: c.eq.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
            goto L_80080884;
    }
    goto skip_0;
    // 0x80080848: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    skip_0:
    // 0x8008084C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80080850: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80080854: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80080858: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8008085C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80080860: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80080864: nop

    // 0x80080868: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8008086C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80080870: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080874: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x80080878: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x8008087C: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80080880: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
L_80080884:
    // 0x80080884: nop

    // 0x80080888: bc1tl       L_800808C8
    if (c1cs) {
        // 0x8008088C: c.eq.s      $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
            goto L_800808C8;
    }
    goto skip_1;
    // 0x8008088C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    skip_1:
    // 0x80080890: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80080894: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80080898: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8008089C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800808A0: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800808A4: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800808A8: nop

    // 0x800808AC: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800808B0: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800808B4: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800808B8: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800808BC: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x800808C0: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x800808C4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
L_800808C8:
    // 0x800808C8: nop

    // 0x800808CC: bc1tl       L_8008090C
    if (c1cs) {
        // 0x800808D0: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8008090C;
    }
    goto skip_2;
    // 0x800808D0: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_2:
    // 0x800808D4: lwc1        $f16, 0x20($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800808D8: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800808DC: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800808E0: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800808E4: lwc1        $f16, 0x2C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800808E8: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800808EC: nop

    // 0x800808F0: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800808F4: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x800808F8: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800808FC: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x80080900: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    // 0x80080904: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
    // 0x80080908: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_8008090C:
    // 0x8008090C: jr          $ra
    // 0x80080910: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80080910: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80566900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566900: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80566904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566908: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8056690C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80566910: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80566914: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80566918: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8056691C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80566920: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80566924: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80566928: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(375, 0XD30) << 16);
    // 0x8056692C: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80566930: lwc1        $f16, 0x7280($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(375, 0XD30));
    // 0x80566934: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80566938: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8056693C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80566940: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80566944: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80566948: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8056694C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80566950: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80566954: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80566958: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8056695C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80566960: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80566964: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80566968: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8056696C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80566970: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80566974: jalr        $t9
    // 0x80566978: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80566978: nop

    after_0:
    // 0x8056697C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566980: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80566984: jr          $ra
    // 0x80566988: nop

    return;
    // 0x80566988: nop

;}
RECOMP_FUNC void func_80669FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80669FA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80669FA8: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(511, 0XD60) << 16);
    // 0x80669FAC: lwc1        $f2, -0x5520($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(511, 0XD60));
    // 0x80669FB0: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(511, 0XD64) << 16);
    // 0x80669FB4: lwc1        $f6, -0x551C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(511, 0XD64));
    // 0x80669FB8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80669FBC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80669FC0: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80669FC4: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80669FC8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80669FCC: nop

    // 0x80669FD0: bc1fl       L_80669FE4
    if (!c1cs) {
        // 0x80669FD4: lwc1        $f2, 0x50($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
            goto L_80669FE4;
    }
    goto skip_0;
    // 0x80669FD4: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    skip_0:
    // 0x80669FD8: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x80669FDC: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80669FE0: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
L_80669FE4:
    // 0x80669FE4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80669FE8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80669FEC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80669FF0: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80669FF4: nop

    // 0x80669FF8: bc1f        L_8066A004
    if (!c1cs) {
        // 0x80669FFC: nop
    
            goto L_8066A004;
    }
    // 0x80669FFC: nop

    // 0x8066A000: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
L_8066A004:
    // 0x8066A004: jr          $ra
    // 0x8066A008: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8066A008: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_80454524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454524: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454528: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x8045452C: addiu       $a1, $zero, 0x1B6C
    ctx->r5 = ADD32(0, 0X1B6C);
    // 0x80454530: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x80454534: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x80454538: sw          $v1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r3;
    // 0x8045453C: sw          $a1, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r5;
    // 0x80454540: sw          $v1, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r3;
    // 0x80454544: sw          $a1, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->r5;
    // 0x80454548: jr          $ra
    // 0x8045454C: sw          $t6, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r14;
    return;
    // 0x8045454C: sw          $t6, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8079A6CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A6CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079A6D0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8079A6D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079A6D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8079A6DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8079A6E0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8079A6E4: jal         0x80062AEC
    // 0x8079A6E8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x8079A6E8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8079A6EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8079A6F0: beq         $v0, $at, L_8079A71C
    if (ctx->r2 == ctx->r1) {
        // 0x8079A6F4: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_8079A71C;
    }
    // 0x8079A6F4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8079A6F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8079A6FC: beq         $v0, $at, L_8079A750
    if (ctx->r2 == ctx->r1) {
        // 0x8079A700: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8079A750;
    }
    // 0x8079A700: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8079A704: beq         $v0, $at, L_8079A784
    if (ctx->r2 == ctx->r1) {
        // 0x8079A708: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8079A784;
    }
    // 0x8079A708: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8079A70C: beq         $v0, $at, L_8079A7B8
    if (ctx->r2 == ctx->r1) {
        // 0x8079A710: nop
    
            goto L_8079A7B8;
    }
    // 0x8079A710: nop

    // 0x8079A714: b           L_8079A7EC
    // 0x8079A718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A7EC;
    // 0x8079A718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A71C:
    // 0x8079A71C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2730) << 16);
    // 0x8079A720: lwc1        $f4, -0x4DB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X2730));
    // 0x8079A724: lwc1        $f0, 0xC4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x8079A728: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8079A72C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8079A730: nop

    // 0x8079A734: bc1fl       L_8079A7EC
    if (!c1cs) {
        // 0x8079A738: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079A7EC;
    }
    goto skip_0;
    // 0x8079A738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8079A73C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8079A740: nop

    // 0x8079A744: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8079A748: b           L_8079A7E8
    // 0x8079A74C: swc1        $f8, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f8.u32l;
        goto L_8079A7E8;
    // 0x8079A74C: swc1        $f8, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f8.u32l;
L_8079A750:
    // 0x8079A750: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2734) << 16);
    // 0x8079A754: lwc1        $f10, -0x4DAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X2734));
    // 0x8079A758: lwc1        $f0, 0xC4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x8079A75C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8079A760: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8079A764: nop

    // 0x8079A768: bc1fl       L_8079A7EC
    if (!c1cs) {
        // 0x8079A76C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079A7EC;
    }
    goto skip_1;
    // 0x8079A76C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8079A770: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8079A774: nop

    // 0x8079A778: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8079A77C: b           L_8079A7E8
    // 0x8079A780: swc1        $f18, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f18.u32l;
        goto L_8079A7E8;
    // 0x8079A780: swc1        $f18, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f18.u32l;
L_8079A784:
    // 0x8079A784: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2738) << 16);
    // 0x8079A788: lwc1        $f4, -0x4DA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X2738));
    // 0x8079A78C: lwc1        $f0, 0xC8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x8079A790: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8079A794: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8079A798: nop

    // 0x8079A79C: bc1fl       L_8079A7EC
    if (!c1cs) {
        // 0x8079A7A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079A7EC;
    }
    goto skip_2;
    // 0x8079A7A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8079A7A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8079A7A8: nop

    // 0x8079A7AC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8079A7B0: b           L_8079A7E8
    // 0x8079A7B4: swc1        $f8, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f8.u32l;
        goto L_8079A7E8;
    // 0x8079A7B4: swc1        $f8, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f8.u32l;
L_8079A7B8:
    // 0x8079A7B8: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X273C) << 16);
    // 0x8079A7BC: lwc1        $f10, -0x4DA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X273C));
    // 0x8079A7C0: lwc1        $f0, 0xC8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x8079A7C4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8079A7C8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8079A7CC: nop

    // 0x8079A7D0: bc1fl       L_8079A7EC
    if (!c1cs) {
        // 0x8079A7D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079A7EC;
    }
    goto skip_3;
    // 0x8079A7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8079A7D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8079A7DC: nop

    // 0x8079A7E0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8079A7E4: swc1        $f18, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f18.u32l;
L_8079A7E8:
    // 0x8079A7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A7EC:
    // 0x8079A7EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079A7F0: jr          $ra
    // 0x8079A7F4: nop

    return;
    // 0x8079A7F4: nop

;}
RECOMP_FUNC void func_806993C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806993C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806993CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806993D0: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806993D4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806993D8: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806993DC: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(559, 0XC0) << 16);
    // 0x806993E0: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x806993E4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806993E8: addiu       $t7, $t7, -0x6B90
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(559, 0XC0));
    // 0x806993EC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806993F0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806993F4: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x806993F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806993FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80699400: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80699404: jal         0x8069942C
    // 0x80699408: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8069942C(rdram, ctx);
        goto after_0;
    // 0x80699408: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8069940C: jal         0x806993C0
    // 0x80699410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806993C0(rdram, ctx);
        goto after_1;
    // 0x80699410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80699414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069941C: jr          $ra
    // 0x80699420: nop

    return;
    // 0x80699420: nop

;}
RECOMP_FUNC void func_8051F61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F61C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051F620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051F624: jal         0x80044658
    // 0x8051F628: nop

    func_80044658(rdram, ctx);
        goto after_0;
    // 0x8051F628: nop

    after_0:
    // 0x8051F62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051F630: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8051F634: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8051F638: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x8051F63C: jr          $ra
    // 0x8051F640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8051F640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806CD7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD7B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CD7B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CD7B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CD7BC: jal         0x806CCF00
    // 0x806CD7C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CCF00(rdram, ctx);
        goto after_0;
    // 0x806CD7C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CD7C4: jal         0x806CD470
    // 0x806CD7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CD470(rdram, ctx);
        goto after_1;
    // 0x806CD7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CD7CC: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806CD7D0: blez        $v0, L_806CD7E0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806CD7D4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806CD7E0;
    }
    // 0x806CD7D4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806CD7D8: b           L_806CD80C
    // 0x806CD7DC: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
        goto L_806CD80C;
    // 0x806CD7DC: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_806CD7E0:
    // 0x806CD7E0: jal         0x806CCE38
    // 0x806CD7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCE38(rdram, ctx);
        goto after_2;
    // 0x806CD7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806CD7E8: beq         $v0, $zero, L_806CD80C
    if (ctx->r2 == 0) {
        // 0x806CD7EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806CD80C;
    }
    // 0x806CD7EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD7F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD7F4: jal         0x806CED40
    // 0x806CD7F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806CED40(rdram, ctx);
        goto after_3;
    // 0x806CD7F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x806CD7FC: jal         0x806CCCE4
    // 0x806CD800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_4;
    // 0x806CD800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806CD804: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x806CD808: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_806CD80C:
    // 0x806CD80C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806CD810: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CD814: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CD818: jr          $ra
    // 0x806CD81C: nop

    return;
    // 0x806CD81C: nop

;}
RECOMP_FUNC void func_807C5E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C5E00: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x807C5E04: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x807C5E08: lw          $t6, 0xE88($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XE88);
    // 0x807C5E0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807C5E10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C5E14: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x807C5E18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807C5E1C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C5E20: bne         $t7, $at, L_807C5E38
    if (ctx->r15 != ctx->r1) {
        // 0x807C5E24: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_807C5E38;
    }
    // 0x807C5E24: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807C5E28: jal         0x807C66CC
    // 0x807C5E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807C66CC(rdram, ctx);
        goto after_0;
    // 0x807C5E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x807C5E30: b           L_807C5F0C
    // 0x807C5E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C5F0C;
    // 0x807C5E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C5E38:
    // 0x807C5E38: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x807C5E3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807C5E40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807C5E44: beq         $v1, $zero, L_807C5E54
    if (ctx->r3 == 0) {
        // 0x807C5E48: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_807C5E54;
    }
    // 0x807C5E48: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x807C5E4C: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x807C5E50: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
L_807C5E54:
    // 0x807C5E54: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807C5E58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807C5E5C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(913, 0X960) << 16);
    // 0x807C5E60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807C5E64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807C5E68: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x807C5E6C: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807C5E70: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x807C5E74: nop

    // 0x807C5E78: bc1fl       L_807C5EA0
    if (!c1cs) {
        // 0x807C5E7C: swc1        $f0, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
            goto L_807C5EA0;
    }
    goto skip_0;
    // 0x807C5E7C: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x807C5E80: lwc1        $f12, 0x6750($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(913, 0X960));
    // 0x807C5E84: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807C5E88: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x807C5E8C: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x807C5E90: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    // 0x807C5E94: b           L_807C5EA4
    // 0x807C5E98: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
        goto L_807C5EA4;
    // 0x807C5E98: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
    // 0x807C5E9C: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
L_807C5EA0:
    // 0x807C5EA0: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
L_807C5EA4:
    // 0x807C5EA4: lw          $v1, 0x478($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X478);
    // 0x807C5EA8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x807C5EAC: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x807C5EB0: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x807C5EB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807C5EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C5EBC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807C5EC0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x807C5EC4: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807C5EC8: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x807C5ECC: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807C5ED0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807C5ED4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x807C5ED8: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x807C5EDC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807C5EE0: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x807C5EE4: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807C5EE8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x807C5EEC: nop

    // 0x807C5EF0: bc1fl       L_807C5F0C
    if (!c1cs) {
        // 0x807C5EF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807C5F0C;
    }
    goto skip_1;
    // 0x807C5EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x807C5EF8: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x807C5EFC: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x807C5F00: jal         0x807C66CC
    // 0x807C5F04: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    func_807C66CC(rdram, ctx);
        goto after_1;
    // 0x807C5F04: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    after_1:
    // 0x807C5F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C5F0C:
    // 0x807C5F0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807C5F10: jr          $ra
    // 0x807C5F14: nop

    return;
    // 0x807C5F14: nop

;}
RECOMP_FUNC void func_80584D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584D2C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584D30: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584D34: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584D38: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584D3C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584D40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584D44: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584D48: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584D4C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584D50: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584D54: jr          $ra
    // 0x80584D58: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584D58: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8042BF3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042BF3C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8042BF40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042BF44: jal         0x8004700C
    // 0x8042BF48: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8042BF48: nop

    after_0:
    // 0x8042BF4C: jal         0x800653D8
    // 0x8042BF50: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8042BF50: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8042BF54: andi        $t6, $v0, 0x7F
    ctx->r14 = ctx->r2 & 0X7F;
    // 0x8042BF58: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8042BF5C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8042BF60: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8042BF64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042BF68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042BF6C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8042BF70: beq         $v1, $zero, L_8042BFE4
    if (ctx->r3 == 0) {
        // 0x8042BF74: sub.s       $f0, $f6, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
            goto L_8042BFE4;
    }
    // 0x8042BF74: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8042BF78: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8042BF7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8042BF80: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X303C) << 16);
    // 0x8042BF84: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8042BF88: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8042BF8C: lwc1        $f6, -0x2724($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X303C));
    // 0x8042BF90: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3040) << 16);
    // 0x8042BF94: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8042BF98: lwc1        $f4, 0x8C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x8042BF9C: lwc1        $f10, -0x2720($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3040));
    // 0x8042BFA0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8042BFA4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8042BFA8: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8042BFAC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8042BFB0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8042BFB4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8042BFB8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8042BFBC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8042BFC0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8042BFC4: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x8042BFC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042BFCC: jalr        $t9
    // 0x8042BFD0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8042BFD0: nop

    after_2:
    // 0x8042BFD4: beq         $v0, $zero, L_8042BFE4
    if (ctx->r2 == 0) {
        // 0x8042BFD8: addiu       $v1, $zero, 0x100
        ctx->r3 = ADD32(0, 0X100);
            goto L_8042BFE4;
    }
    // 0x8042BFD8: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x8042BFDC: sh          $v1, 0xC0($v0)
    MEM_H(0XC0, ctx->r2) = ctx->r3;
    // 0x8042BFE0: sh          $v1, 0xC2($v0)
    MEM_H(0XC2, ctx->r2) = ctx->r3;
L_8042BFE4:
    // 0x8042BFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042BFE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8042BFEC: jr          $ra
    // 0x8042BFF0: nop

    return;
    // 0x8042BFF0: nop

;}
RECOMP_FUNC void func_80436BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80436BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436BE8: jal         0x80436BBC
    // 0x80436BEC: nop

    func_80436BBC(rdram, ctx);
        goto after_0;
    // 0x80436BEC: nop

    after_0:
    // 0x80436BF0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80436BF4: beql        $v0, $zero, L_80436C0C
    if (ctx->r2 == 0) {
        // 0x80436BF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80436C0C;
    }
    goto skip_0;
    // 0x80436BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80436BFC: jal         0x80436B3C
    // 0x80436C00: nop

    func_80436B3C(rdram, ctx);
        goto after_1;
    // 0x80436C00: nop

    after_1:
    // 0x80436C04: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80436C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80436C0C:
    // 0x80436C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80436C10: jr          $ra
    // 0x80436C14: nop

    return;
    // 0x80436C14: nop

;}
RECOMP_FUNC void func_8001C148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C148: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8001C14C: addiu       $v0, $v0, -0x3EA8
    ctx->r2 = ADD32(ctx->r2, -0X3EA8);
    // 0x8001C150: jr          $ra
    // 0x8001C154: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8001C154: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80582090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80582094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80582098: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8058209C: jal         0x8057EF14
    // 0x805820A0: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    func_8057EF14(rdram, ctx);
        goto after_0;
    // 0x805820A0: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    after_0:
    // 0x805820A4: beq         $v0, $zero, L_805820D0
    if (ctx->r2 == 0) {
        // 0x805820A8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_805820D0;
    }
    // 0x805820A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805820AC: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    // 0x805820B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805820B4: beql        $a2, $zero, L_805820D4
    if (ctx->r6 == 0) {
        // 0x805820B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805820D4;
    }
    goto skip_0;
    // 0x805820B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805820BC: jal         0x805820E0
    // 0x805820C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_805820E0(rdram, ctx);
        goto after_1;
    // 0x805820C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x805820C4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805820C8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x805820CC: sb          $t6, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r14;
L_805820D0:
    // 0x805820D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805820D4:
    // 0x805820D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805820D8: jr          $ra
    // 0x805820DC: nop

    return;
    // 0x805820DC: nop

;}
RECOMP_FUNC void func_80716790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716790: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80716794: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80716798: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8071679C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807167A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807167A4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807167A8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x807167AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807167B0: addiu       $t6, $zero, 0x99C
    ctx->r14 = ADD32(0, 0X99C);
    // 0x807167B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807167B8: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x807167BC: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x807167C0: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x807167C4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x807167C8: jal         0x8071637C
    // 0x807167CC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8071637C(rdram, ctx);
        goto after_0;
    // 0x807167CC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x807167D0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x807167D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807167D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807167DC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x807167E0: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x807167E4: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x807167E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807167EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807167F0: jr          $ra
    // 0x807167F4: nop

    return;
    // 0x807167F4: nop

;}
RECOMP_FUNC void func_8000D8D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D8D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000D8DC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8000D8E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000D8E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D8E8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
L_8000D8EC:
    // 0x8000D8EC: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8000D8F0: beq         $t6, $zero, L_8000D91C
    if (ctx->r14 == 0) {
        // 0x8000D8F4: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8000D91C;
    }
    // 0x8000D8F4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8000D8F8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8000D8FC: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8000D900: lw          $a0, 0x34($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X34);
    // 0x8000D904: lbu         $t9, 0x5($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X5);
    // 0x8000D908: sb          $t9, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r25;
    // 0x8000D90C: lbu         $t0, 0x3($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X3);
    // 0x8000D910: sb          $t0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r8;
    // 0x8000D914: lbu         $t1, 0x2($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X2);
    // 0x8000D918: sb          $t1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r9;
L_8000D91C:
    // 0x8000D91C: sra         $a1, $v1, 1
    ctx->r5 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8000D920: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x8000D924: andi        $t2, $v1, 0x1
    ctx->r10 = ctx->r3 & 0X1;
    // 0x8000D928: beq         $t2, $zero, L_8000D954
    if (ctx->r10 == 0) {
        // 0x8000D92C: sra         $a1, $v1, 1
        ctx->r5 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8000D954;
    }
    // 0x8000D92C: sra         $a1, $v1, 1
    ctx->r5 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8000D930: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8000D934: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x8000D938: lw          $a0, 0x38($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X38);
    // 0x8000D93C: lbu         $t5, 0x5($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X5);
    // 0x8000D940: sb          $t5, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r13;
    // 0x8000D944: lbu         $t6, 0x3($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X3);
    // 0x8000D948: sb          $t6, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r14;
    // 0x8000D94C: lbu         $t7, 0x2($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X2);
    // 0x8000D950: sb          $t7, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r15;
L_8000D954:
    // 0x8000D954: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x8000D958: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x8000D95C: beq         $t8, $zero, L_8000D988
    if (ctx->r24 == 0) {
        // 0x8000D960: sra         $a1, $v1, 1
        ctx->r5 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8000D988;
    }
    // 0x8000D960: sra         $a1, $v1, 1
    ctx->r5 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8000D964: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8000D968: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x8000D96C: lw          $a0, 0x3C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X3C);
    // 0x8000D970: lbu         $t1, 0x5($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X5);
    // 0x8000D974: sb          $t1, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r9;
    // 0x8000D978: lbu         $t2, 0x3($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X3);
    // 0x8000D97C: sb          $t2, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r10;
    // 0x8000D980: lbu         $t3, 0x2($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X2);
    // 0x8000D984: sb          $t3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r11;
L_8000D988:
    // 0x8000D988: andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // 0x8000D98C: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x8000D990: beq         $t4, $zero, L_8000D9BC
    if (ctx->r12 == 0) {
        // 0x8000D994: sra         $a1, $v1, 1
        ctx->r5 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8000D9BC;
    }
    // 0x8000D994: sra         $a1, $v1, 1
    ctx->r5 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8000D998: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8000D99C: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x8000D9A0: lw          $a0, 0x40($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X40);
    // 0x8000D9A4: lbu         $t7, 0x5($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X5);
    // 0x8000D9A8: sb          $t7, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r15;
    // 0x8000D9AC: lbu         $t8, 0x3($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3);
    // 0x8000D9B0: sb          $t8, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r24;
    // 0x8000D9B4: lbu         $t9, 0x2($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X2);
    // 0x8000D9B8: sb          $t9, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r25;
L_8000D9BC:
    // 0x8000D9BC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000D9C0: bne         $v0, $a3, L_8000D8EC
    if (ctx->r2 != ctx->r7) {
        // 0x8000D9C4: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_8000D8EC;
    }
    // 0x8000D9C4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8000D9C8: jr          $ra
    // 0x8000D9CC: nop

    return;
    // 0x8000D9CC: nop

;}
RECOMP_FUNC void func_805848DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805848DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805848E0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805848E4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805848E8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805848EC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805848F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805848F4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805848F8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805848FC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584900: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584904: jr          $ra
    // 0x80584908: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584908: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805213D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805213D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805213D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805213D8: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x805213DC: beql        $v0, $zero, L_80521414
    if (ctx->r2 == 0) {
        // 0x805213E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80521414;
    }
    goto skip_0;
    // 0x805213E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x805213E4: jalr        $v0
    // 0x805213E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x805213E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805213EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805213F0: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x805213F4: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x805213F8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x805213FC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80521400: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80521404: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80521408: b           L_80521414
    // 0x8052140C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
        goto L_80521414;
    // 0x8052140C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x80521410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80521414:
    // 0x80521414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052141C: jr          $ra
    // 0x80521420: nop

    return;
    // 0x80521420: nop

;}
RECOMP_FUNC void func_8002F8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F8EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F8F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F8F4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002F8F8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F8FC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002F900: jal         0x8002F678
    // 0x8002F904: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002F904: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002F908: beq         $v0, $zero, L_8002F91C
    if (ctx->r2 == 0) {
        // 0x8002F90C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002F91C;
    }
    // 0x8002F90C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F910: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002F914: addiu       $t6, $t6, -0x3410
    ctx->r14 = ADD32(ctx->r14, -0X3410);
    // 0x8002F918: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002F91C:
    // 0x8002F91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F920: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F924: jr          $ra
    // 0x8002F928: nop

    return;
    // 0x8002F928: nop

;}
RECOMP_FUNC void func_805AE6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE6C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AE6CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AE6D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805AE6D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805AE6D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805AE6DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AE6E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805AE6E4: lui         $a2, 0x805C
    ctx->r6 = S32(RELOC_HI16(444, 0X17894) << 16);
    // 0x805AE6E8: lui         $a1, 0x805C
    ctx->r5 = S32(RELOC_HI16(444, 0X178B8) << 16);
    // 0x805AE6EC: addiu       $a1, $a1, 0x4FB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(444, 0X178B8));
    // 0x805AE6F0: addiu       $a2, $a2, 0x4F94
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(444, 0X17894));
    // 0x805AE6F4: jal         0x805AD7C8
    // 0x805AE6F8: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_805AD7C8(rdram, ctx);
        goto after_0;
    // 0x805AE6F8: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_0:
    // 0x805AE6FC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x805AE700: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805AE704: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805AE708: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805AE70C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x805AE710: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x805AE714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AE718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AE71C: jr          $ra
    // 0x805AE720: nop

    return;
    // 0x805AE720: nop

;}
RECOMP_FUNC void func_8051A95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A95C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051A960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051A964: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8051A968: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8051A96C: jal         0x80048F84
    // 0x8051A970: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8051A970: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8051A974: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051A978: jal         0x80048F84
    // 0x8051A97C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8051A97C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8051A980: beq         $v0, $zero, L_8051A99C
    if (ctx->r2 == 0) {
        // 0x8051A984: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8051A99C;
    }
    // 0x8051A984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051A988: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8051A98C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8051A990: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8051A994: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8051A998: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
L_8051A99C:
    // 0x8051A99C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051A9A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051A9A4: jr          $ra
    // 0x8051A9A8: nop

    return;
    // 0x8051A9A8: nop

;}
RECOMP_FUNC void func_8005BB28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BB28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005BB2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BB30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005BB34: jal         0x8005BA30
    // 0x8005BB38: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_8005BA30(rdram, ctx);
        goto after_0;
    // 0x8005BB38: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x8005BB3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BB40: bne         $v0, $at, L_8005BB50
    if (ctx->r2 != ctx->r1) {
        // 0x8005BB44: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005BB50;
    }
    // 0x8005BB44: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005BB48: b           L_8005BB68
    // 0x8005BB4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005BB68;
    // 0x8005BB4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005BB50:
    // 0x8005BB50: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8005BB54: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8005BB58: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8005BB5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8005BB60: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8005BB64: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
L_8005BB68:
    // 0x8005BB68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BB6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005BB70: jr          $ra
    // 0x8005BB74: nop

    return;
    // 0x8005BB74: nop

;}
RECOMP_FUNC void func_8071637C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8071637C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80716380: beql        $at, $zero, L_80716394
    if (ctx->r1 == 0) {
        // 0x80716384: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80716394;
    }
    goto skip_0;
    // 0x80716384: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x80716388: jr          $ra
    // 0x8071638C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x8071638C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80716390: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_80716394:
    // 0x80716394: beq         $at, $zero, L_807163D0
    if (ctx->r1 == 0) {
        // 0x80716398: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_807163D0;
    }
    // 0x80716398: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x8071639C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x807163A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807163A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807163A8: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x807163AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807163B0: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x807163B4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x807163B8: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x807163BC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807163C0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x807163C4: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x807163C8: jr          $ra
    // 0x807163CC: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x807163CC: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_807163D0:
    // 0x807163D0: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x807163D4: beq         $at, $zero, L_807163EC
    if (ctx->r1 == 0) {
        // 0x807163D8: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_807163EC;
    }
    // 0x807163D8: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x807163DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807163E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807163E4: jr          $ra
    // 0x807163E8: nop

    return;
    // 0x807163E8: nop

L_807163EC:
    // 0x807163EC: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x807163F0: beq         $at, $zero, L_80716430
    if (ctx->r1 == 0) {
        // 0x807163F4: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80716430;
    }
    // 0x807163F4: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807163F8: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x807163FC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80716400: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80716404: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80716408: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8071640C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80716410: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x80716414: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80716418: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8071641C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80716420: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80716424: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80716428: jr          $ra
    // 0x8071642C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x8071642C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_80716430:
    // 0x80716430: jr          $ra
    // 0x80716434: nop

    return;
    // 0x80716434: nop

;}
RECOMP_FUNC void func_8004E5C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E5C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004E5CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004E5D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004E5D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004E5D8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004E5DC: lw          $s0, 0x174($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X174);
    // 0x8004E5E0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8004E5E4: jal         0x80047AB8
    // 0x8004E5E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8004E5E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8004E5EC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8004E5F0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8004E5F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8004E5F8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    // 0x8004E5FC: lwc1        $f4, 0xC8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8004E600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004E604: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004E608: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8004E60C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004E610: bc1fl       L_8004E648
    if (!c1cs) {
        // 0x8004E614: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E648;
    }
    goto skip_0;
    // 0x8004E614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8004E618: jal         0x8004DC08
    // 0x8004E61C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_8004DC08(rdram, ctx);
        goto after_1;
    // 0x8004E61C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8004E620: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8004E624: lw          $v0, 0x40($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X40);
    // 0x8004E628: lbu         $t8, 0x14($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X14);
    // 0x8004E62C: beql        $t8, $zero, L_8004E648
    if (ctx->r24 == 0) {
        // 0x8004E630: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E648;
    }
    goto skip_1;
    // 0x8004E630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8004E634: lwc1        $f8, 0x40($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8004E638: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8004E63C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004E640: swc1        $f16, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f16.u32l;
    // 0x8004E644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004E648:
    // 0x8004E648: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004E64C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004E650: jr          $ra
    // 0x8004E654: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004E654: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80000470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000470: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80000474: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80000478: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000047C: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80000480: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80000484: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80000488: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8000048C: addiu       $t7, $t7, 0x4D10
    ctx->r15 = ADD32(ctx->r15, 0X4D10);
    // 0x80000490: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80000494: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x80000498: lbu         $t8, 0x1C($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X1C);
    // 0x8000049C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800004A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800004A4: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x800004A8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800004AC: bne         $at, $zero, L_80000644
    if (ctx->r1 != 0) {
        // 0x800004B0: sw          $a1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r5;
            goto L_80000644;
    }
    // 0x800004B0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800004B4: addiu       $a3, $t0, 0x18
    ctx->r7 = ADD32(ctx->r8, 0X18);
    // 0x800004B8: lbu         $t9, 0x2($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X2);
    // 0x800004BC: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x800004C0: addu        $t5, $t5, $a1
    ctx->r13 = ADD32(ctx->r13, ctx->r5);
    // 0x800004C4: bnel        $t9, $zero, L_80000648
    if (ctx->r25 != 0) {
        // 0x800004C8: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_80000648;
    }
    goto skip_0;
    // 0x800004C8: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x800004CC: lbu         $t1, 0x3($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X3);
    // 0x800004D0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800004D4: addiu       $a1, $zero, 0x340
    ctx->r5 = ADD32(0, 0X340);
    // 0x800004D8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800004DC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800004E0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800004E4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800004E8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800004EC: addu        $t3, $a3, $t2
    ctx->r11 = ADD32(ctx->r7, ctx->r10);
    // 0x800004F0: addu        $a2, $t3, $t5
    ctx->r6 = ADD32(ctx->r11, ctx->r13);
    // 0x800004F4: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    // 0x800004F8: addiu       $a2, $a2, 0x38
    ctx->r6 = ADD32(ctx->r6, 0X38);
    // 0x800004FC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x80000500: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80000504: jal         0x8000AC90
    // 0x80000508: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8000AC90(rdram, ctx);
        goto after_0;
    // 0x80000508: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000050C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80000510: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80000514: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80000518: lh          $t6, 0x10($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X10);
    // 0x8000051C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000520: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80000524: bgez        $t6, L_80000534
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80000528: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80000534;
    }
    // 0x80000528: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8000052C: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80000530: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_80000534:
    // 0x80000534: blezl       $t7, L_800005C4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80000538: lh          $t2, 0x12($a2)
        ctx->r10 = MEM_H(ctx->r6, 0X12);
            goto L_800005C4;
    }
    goto skip_1;
    // 0x80000538: lh          $t2, 0x12($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X12);
    skip_1:
    // 0x8000053C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80000540: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
L_80000544:
    // 0x80000544: lw          $t4, 0xC($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XC);
    // 0x80000548: lw          $t2, 0x20($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X20);
    // 0x8000054C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x80000550: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80000554: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x80000558: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x8000055C: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80000560: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80000564: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
    // 0x80000568: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x8000056C: lw          $t2, 0xC($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XC);
    // 0x80000570: lw          $t4, 0x24($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X24);
    // 0x80000574: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80000578: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8000057C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80000580: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x80000584: addu        $t1, $t5, $v0
    ctx->r9 = ADD32(ctx->r13, ctx->r2);
    // 0x80000588: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x8000058C: lh          $t7, 0x10($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X10);
    // 0x80000590: lbu         $t6, 0x4($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X4);
    // 0x80000594: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80000598: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000059C: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x800005A0: bgez        $t7, L_800005B0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800005A4: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_800005B0;
    }
    // 0x800005A4: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800005A8: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x800005AC: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_800005B0:
    // 0x800005B0: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800005B4: bnel        $at, $zero, L_80000544
    if (ctx->r1 != 0) {
        // 0x800005B8: lw          $t8, 0x4($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X4);
            goto L_80000544;
    }
    goto skip_2;
    // 0x800005B8: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    skip_2:
    // 0x800005BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800005C0: lh          $t2, 0x12($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X12);
L_800005C4:
    // 0x800005C4: bgez        $t2, L_800005D4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800005C8: sra         $t4, $t2, 1
        ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800005D4;
    }
    // 0x800005C8: sra         $t4, $t2, 1
    ctx->r12 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800005CC: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800005D0: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_800005D4:
    // 0x800005D4: blezl       $t4, L_80000648
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800005D8: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_80000648;
    }
    goto skip_3;
    // 0x800005D8: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    skip_3:
    // 0x800005DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800005E0: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
L_800005E4:
    // 0x800005E4: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800005E8: lw          $t1, 0x20($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X20);
    // 0x800005EC: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x800005F0: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x800005F4: addu        $t6, $t1, $v0
    ctx->r14 = ADD32(ctx->r9, ctx->r2);
    // 0x800005F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800005FC: sh          $t9, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r25;
    // 0x80000600: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x80000604: lw          $t4, 0x24($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X24);
    // 0x80000608: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8000060C: lh          $t2, 0x0($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X0);
    // 0x80000610: addu        $t3, $t4, $v0
    ctx->r11 = ADD32(ctx->r12, ctx->r2);
    // 0x80000614: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80000618: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x8000061C: lh          $t1, 0x12($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X12);
    // 0x80000620: lbu         $t5, 0x4($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X4);
    // 0x80000624: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80000628: bgez        $t1, L_80000638
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8000062C: sra         $t9, $t1, 1
        ctx->r25 = S32(SIGNED(ctx->r9) >> 1);
            goto L_80000638;
    }
    // 0x8000062C: sra         $t9, $t1, 1
    ctx->r25 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80000630: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x80000634: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80000638:
    // 0x80000638: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000063C: bnel        $at, $zero, L_800005E4
    if (ctx->r1 != 0) {
        // 0x80000640: lw          $t3, 0x4($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X4);
            goto L_800005E4;
    }
    goto skip_4;
    // 0x80000640: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    skip_4:
L_80000644:
    // 0x80000644: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_80000648:
    // 0x80000648: addiu       $a3, $t0, 0x18
    ctx->r7 = ADD32(ctx->r8, 0X18);
    // 0x8000064C: lbu         $t5, 0x4($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X4);
    // 0x80000650: lbu         $t6, 0x3($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X3);
    // 0x80000654: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80000658: div         $zero, $t3, $t5
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r13)));
    // 0x8000065C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80000660: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80000664: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80000668: lw          $t1, 0x14($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X14);
    // 0x8000066C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80000670: lw          $t6, 0x1C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1C);
    // 0x80000674: mflo        $v0
    ctx->r2 = lo;
    // 0x80000678: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8000067C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80000680: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x80000684: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x80000688: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8000068C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80000690: subu        $v1, $t9, $t6
    ctx->r3 = SUB32(ctx->r25, ctx->r14);
    // 0x80000694: addu        $a2, $t8, $t2
    ctx->r6 = ADD32(ctx->r24, ctx->r10);
    // 0x80000698: addiu       $a2, $a2, 0x38
    ctx->r6 = ADD32(ctx->r6, 0X38);
    // 0x8000069C: bne         $t5, $zero, L_800006A8
    if (ctx->r13 != 0) {
        // 0x800006A0: nop
    
            goto L_800006A8;
    }
    // 0x800006A0: nop

    // 0x800006A4: break       7
    do_break(2147485348);
L_800006A8:
    // 0x800006A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800006AC: bne         $t5, $at, L_800006C0
    if (ctx->r13 != ctx->r1) {
        // 0x800006B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800006C0;
    }
    // 0x800006B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800006B4: bne         $t3, $at, L_800006C0
    if (ctx->r11 != ctx->r1) {
        // 0x800006B8: nop
    
            goto L_800006C0;
    }
    // 0x800006B8: nop

    // 0x800006BC: break       6
    do_break(2147485372);
L_800006C0:
    // 0x800006C0: subu        $t3, $v0, $v1
    ctx->r11 = SUB32(ctx->r2, ctx->r3);
    // 0x800006C4: bgez        $v1, L_800006F0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800006C8: sll         $t5, $t3, 1
        ctx->r13 = S32(ctx->r11 << 1);
            goto L_800006F0;
    }
    // 0x800006C8: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x800006CC: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800006D0: sh          $t7, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r15;
    // 0x800006D4: sh          $zero, 0x12($a2)
    MEM_H(0X12, ctx->r6) = 0;
    // 0x800006D8: lw          $t4, 0x14($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X14);
    // 0x800006DC: sw          $t4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r12;
    // 0x800006E0: lw          $t8, 0x14($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14);
    // 0x800006E4: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x800006E8: b           L_80000708
    // 0x800006EC: sw          $t2, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r10;
        goto L_80000708;
    // 0x800006EC: sw          $t2, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r10;
L_800006F0:
    // 0x800006F0: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x800006F4: sh          $t5, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r13;
    // 0x800006F8: sh          $t1, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r9;
    // 0x800006FC: lw          $t9, 0x14($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X14);
    // 0x80000700: sw          $t9, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r25;
    // 0x80000704: sw          $v1, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r3;
L_80000708:
    // 0x80000708: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8000070C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80000710: sh          $t6, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r14;
    // 0x80000714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000718: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8000071C: jr          $ra
    // 0x80000720: nop

    return;
    // 0x80000720: nop

;}
RECOMP_FUNC void func_80429168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042916C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429170: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80429174: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80429178: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(41, 0X1E84) << 16);
    // 0x8042917C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80429180: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80429184: lw          $t8, -0x683C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(41, 0X1E84));
    // 0x80429188: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042918C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80429190: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80429194: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80429198: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042919C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804291A0: beql        $v1, $zero, L_804291D4
    if (ctx->r3 == 0) {
        // 0x804291A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804291D4;
    }
    goto skip_0;
    // 0x804291A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804291A8: jalr        $v1
    // 0x804291AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804291AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804291B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804291B4: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804291B8: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804291BC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804291C0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804291C4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804291C8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804291CC: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804291D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804291D4:
    // 0x804291D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804291D8: jr          $ra
    // 0x804291DC: nop

    return;
    // 0x804291DC: nop

;}
RECOMP_FUNC void func_80553914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553914: lwc1        $f4, 0xDB8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XDB8);
    // 0x80553918: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8055391C: jr          $ra
    // 0x80553920: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80553920: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80041714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004171C: jal         0x800415D0
    // 0x80041720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800415D0(rdram, ctx);
        goto after_0;
    // 0x80041720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80041724: beq         $v0, $zero, L_80041734
    if (ctx->r2 == 0) {
        // 0x80041728: nop
    
            goto L_80041734;
    }
    // 0x80041728: nop

    // 0x8004172C: b           L_80041750
    // 0x80041730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041750;
    // 0x80041730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041734:
    // 0x80041734: jal         0x8003200C
    // 0x80041738: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003200C(rdram, ctx);
        goto after_1;
    // 0x80041738: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8004173C: beql        $v0, $zero, L_80041750
    if (ctx->r2 == 0) {
        // 0x80041740: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80041750;
    }
    goto skip_0;
    // 0x80041740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80041744: b           L_80041750
    // 0x80041748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041750;
    // 0x80041748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004174C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041750:
    // 0x80041750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041758: jr          $ra
    // 0x8004175C: nop

    return;
    // 0x8004175C: nop

;}
RECOMP_FUNC void func_8044E2E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044E2E4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8044E2E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8044E2EC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8044E2F0: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x8044E2F4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044E2F8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044E2FC: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x8044E300: lw          $a0, 0x6A28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6A28);
    // 0x8044E304: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8044E308: jal         0x8044DED0
    // 0x8044E30C: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    func_8044DED0(rdram, ctx);
        goto after_0;
    // 0x8044E30C: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044E310: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x8044E314: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8044E318: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8044E31C: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x8044E320: jal         0x8006C67C
    // 0x8044E324: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    func_8006C67C(rdram, ctx);
        goto after_1;
    // 0x8044E324: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    after_1:
    // 0x8044E328: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8044E32C: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8044E330: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8044E334: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8044E338: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8044E33C: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8044E340: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8044E344: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8044E348: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8044E34C: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x8044E350: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8044E354: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8044E358: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x8044E35C: mul.s       $f20, $f2, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8044E360: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x8044E364: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x8044E368: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x8044E36C: add.s       $f0, $f20, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x8044E370: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x8044E374: jal         0x80081E8C
    // 0x8044E378: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    fatan2(rdram, ctx);
        goto after_2;
    // 0x8044E378: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_2:
    // 0x8044E37C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1409C) << 16);
    // 0x8044E380: lwc1        $f10, -0x7B84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1409C));
    // 0x8044E384: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8044E388: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8044E38C: mul.s       $f20, $f0, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8044E390: jal         0x80081E8C
    // 0x8044E394: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
    fatan2(rdram, ctx);
        goto after_3;
    // 0x8044E394: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
    after_3:
    // 0x8044E398: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8044E39C: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8044E3A0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140A0) << 16);
    // 0x8044E3A4: lwc1        $f4, -0x7B80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140A0));
    // 0x8044E3A8: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8044E3AC: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8044E3B0: mul.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8044E3B4: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x8044E3B8: add.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8044E3BC: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x8044E3C0: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8044E3C4: bltz        $a1, L_8044E670
    if (SIGNED(ctx->r5) < 0) {
        // 0x8044E3C8: mov.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
            goto L_8044E670;
    }
    // 0x8044E3C8: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x8044E3CC: beq         $at, $zero, L_8044E670
    if (ctx->r1 == 0) {
        // 0x8044E3D0: lui         $t7, 0x800F
        ctx->r15 = S32(0X800F << 16);
            goto L_8044E670;
    }
    // 0x8044E3D0: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8044E3D4: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x8044E3D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8044E3DC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8044E3E0: lhu         $v1, 0x0($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X0);
    // 0x8044E3E4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8044E3E8: andi        $a0, $v1, 0x8
    ctx->r4 = ctx->r3 & 0X8;
    // 0x8044E3EC: beq         $a3, $a0, L_8044E42C
    if (ctx->r7 == ctx->r4) {
        // 0x8044E3F0: andi        $t8, $v1, 0x10
        ctx->r24 = ctx->r3 & 0X10;
            goto L_8044E42C;
    }
    // 0x8044E3F0: andi        $t8, $v1, 0x10
    ctx->r24 = ctx->r3 & 0X10;
    // 0x8044E3F4: beq         $t8, $at, L_8044E42C
    if (ctx->r24 == ctx->r1) {
        // 0x8044E3F8: andi        $t9, $v1, 0x2000
        ctx->r25 = ctx->r3 & 0X2000;
            goto L_8044E42C;
    }
    // 0x8044E3F8: andi        $t9, $v1, 0x2000
    ctx->r25 = ctx->r3 & 0X2000;
    // 0x8044E3FC: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x8044E400: beq         $t9, $at, L_8044E42C
    if (ctx->r25 == ctx->r1) {
        // 0x8044E404: andi        $t0, $v1, 0x4
        ctx->r8 = ctx->r3 & 0X4;
            goto L_8044E42C;
    }
    // 0x8044E404: andi        $t0, $v1, 0x4
    ctx->r8 = ctx->r3 & 0X4;
    // 0x8044E408: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8044E40C: beq         $t0, $at, L_8044E42C
    if (ctx->r8 == ctx->r1) {
        // 0x8044E410: andi        $t1, $v1, 0x1
        ctx->r9 = ctx->r3 & 0X1;
            goto L_8044E42C;
    }
    // 0x8044E410: andi        $t1, $v1, 0x1
    ctx->r9 = ctx->r3 & 0X1;
    // 0x8044E414: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044E418: beq         $t1, $at, L_8044E42C
    if (ctx->r9 == ctx->r1) {
        // 0x8044E41C: andi        $t2, $v1, 0x2
        ctx->r10 = ctx->r3 & 0X2;
            goto L_8044E42C;
    }
    // 0x8044E41C: andi        $t2, $v1, 0x2
    ctx->r10 = ctx->r3 & 0X2;
    // 0x8044E420: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8044E424: bne         $t2, $at, L_8044E648
    if (ctx->r10 != ctx->r1) {
        // 0x8044E428: addiu       $t8, $sp, 0x90
        ctx->r24 = ADD32(ctx->r29, 0X90);
            goto L_8044E648;
    }
    // 0x8044E428: addiu       $t8, $sp, 0x90
    ctx->r24 = ADD32(ctx->r29, 0X90);
L_8044E42C:
    // 0x8044E42C: lui         $at, 0x8045
    ctx->r1 = S32(RELOC_HI16(98, 0X13B58) << 16);
    // 0x8044E430: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044E434: lwc1        $f12, 0x7F38($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13B58));
    // 0x8044E438: lui         $at, 0x8045
    ctx->r1 = S32(RELOC_HI16(98, 0X13B40) << 16);
    // 0x8044E43C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044E440: lwc1        $f18, 0x7F20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13B40));
    // 0x8044E444: lui         $at, 0x8045
    ctx->r1 = S32(RELOC_HI16(98, 0X13B70) << 16);
    // 0x8044E448: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044E44C: lwc1        $f4, 0x7F50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13B70));
    // 0x8044E450: lui         $at, 0x8045
    ctx->r1 = S32(RELOC_HI16(98, 0X13B88) << 16);
    // 0x8044E454: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044E458: lwc1        $f8, 0x7F68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13B88));
    // 0x8044E45C: lui         $at, 0x8045
    ctx->r1 = S32(RELOC_HI16(98, 0X13BA0) << 16);
    // 0x8044E460: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044E464: lwc1        $f2, 0x7F80($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13BA0));
    // 0x8044E468: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8044E46C: andi        $t3, $v1, 0x10
    ctx->r11 = ctx->r3 & 0X10;
    // 0x8044E470: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x8044E474: andi        $a2, $v1, 0x1
    ctx->r6 = ctx->r3 & 0X1;
    // 0x8044E478: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x8044E47C: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8044E480: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8044E484: bne         $t3, $at, L_8044E49C
    if (ctx->r11 != ctx->r1) {
        // 0x8044E488: swc1        $f2, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
            goto L_8044E49C;
    }
    // 0x8044E488: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8044E48C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044E490: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8044E494: b           L_8044E4B8
    // 0x8044E498: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_8044E4B8;
    // 0x8044E498: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
L_8044E49C:
    // 0x8044E49C: andi        $t4, $v1, 0x2000
    ctx->r12 = ctx->r3 & 0X2000;
    // 0x8044E4A0: addiu       $at, $zero, 0x2000
    ctx->r1 = ADD32(0, 0X2000);
    // 0x8044E4A4: bne         $t4, $at, L_8044E4B8
    if (ctx->r12 != ctx->r1) {
        // 0x8044E4A8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8044E4B8;
    }
    // 0x8044E4A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044E4AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8044E4B0: nop

    // 0x8044E4B4: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
L_8044E4B8:
    // 0x8044E4B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044E4BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8044E4C0: bne         $a3, $a0, L_8044E4D0
    if (ctx->r7 != ctx->r4) {
        // 0x8044E4C4: lwc1        $f10, 0x50($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
            goto L_8044E4D0;
    }
    // 0x8044E4C4: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8044E4C8: b           L_8044E4E4
    // 0x8044E4CC: add.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
        goto L_8044E4E4;
    // 0x8044E4CC: add.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
L_8044E4D0:
    // 0x8044E4D0: andi        $t5, $v1, 0x4
    ctx->r13 = ctx->r3 & 0X4;
    // 0x8044E4D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8044E4D8: bnel        $t5, $at, L_8044E4E8
    if (ctx->r13 != ctx->r1) {
        // 0x8044E4DC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8044E4E8;
    }
    goto skip_0;
    // 0x8044E4DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8044E4E0: sub.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f2.fl;
L_8044E4E4:
    // 0x8044E4E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8044E4E8:
    // 0x8044E4E8: bne         $a2, $at, L_8044E4F8
    if (ctx->r6 != ctx->r1) {
        // 0x8044E4EC: lwc1        $f8, 0x48($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
            goto L_8044E4F8;
    }
    // 0x8044E4EC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8044E4F0: b           L_8044E50C
    // 0x8044E4F4: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
        goto L_8044E50C;
    // 0x8044E4F4: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
L_8044E4F8:
    // 0x8044E4F8: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x8044E4FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8044E500: bnel        $t6, $at, L_8044E510
    if (ctx->r14 != ctx->r1) {
        // 0x8044E504: c.lt.s      $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
            goto L_8044E510;
    }
    goto skip_1;
    // 0x8044E504: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    skip_1:
    // 0x8044E508: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
L_8044E50C:
    // 0x8044E50C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
L_8044E510:
    // 0x8044E510: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8044E514: bc1fl       L_8044E528
    if (!c1cs) {
        // 0x8044E518: c.lt.s      $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
            goto L_8044E528;
    }
    goto skip_2;
    // 0x8044E518: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    skip_2:
    // 0x8044E51C: b           L_8044E538
    // 0x8044E520: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
        goto L_8044E538;
    // 0x8044E520: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x8044E524: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
L_8044E528:
    // 0x8044E528: nop

    // 0x8044E52C: bc1fl       L_8044E53C
    if (!c1cs) {
        // 0x8044E530: c.lt.s      $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
            goto L_8044E53C;
    }
    goto skip_3;
    // 0x8044E530: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    skip_3:
    // 0x8044E534: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
L_8044E538:
    // 0x8044E538: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
L_8044E53C:
    // 0x8044E53C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8044E540: bc1fl       L_8044E554
    if (!c1cs) {
        // 0x8044E544: c.lt.s      $f4, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
            goto L_8044E554;
    }
    goto skip_4;
    // 0x8044E544: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    skip_4:
    // 0x8044E548: b           L_8044E564
    // 0x8044E54C: mov.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = ctx->f10.fl;
        goto L_8044E564;
    // 0x8044E54C: mov.s       $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = ctx->f10.fl;
    // 0x8044E550: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
L_8044E554:
    // 0x8044E554: nop

    // 0x8044E558: bc1fl       L_8044E568
    if (!c1cs) {
        // 0x8044E55C: c.lt.s      $f14, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
            goto L_8044E568;
    }
    goto skip_5;
    // 0x8044E55C: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    skip_5:
    // 0x8044E560: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
L_8044E564:
    // 0x8044E564: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
L_8044E568:
    // 0x8044E568: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8044E56C: bc1fl       L_8044E580
    if (!c1cs) {
        // 0x8044E570: c.lt.s      $f6, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
            goto L_8044E580;
    }
    goto skip_6;
    // 0x8044E570: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    skip_6:
    // 0x8044E574: b           L_8044E590
    // 0x8044E578: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
        goto L_8044E590;
    // 0x8044E578: mov.s       $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = ctx->f8.fl;
    // 0x8044E57C: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
L_8044E580:
    // 0x8044E580: nop

    // 0x8044E584: bc1fl       L_8044E594
    if (!c1cs) {
        // 0x8044E588: swc1        $f14, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
            goto L_8044E594;
    }
    goto skip_7;
    // 0x8044E588: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
    skip_7:
    // 0x8044E58C: mov.s       $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = ctx->f6.fl;
L_8044E590:
    // 0x8044E590: swc1        $f14, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f14.u32l;
L_8044E594:
    // 0x8044E594: jal         0x80066DE4
    // 0x8044E598: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8044E598: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8044E59C: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8044E5A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8044E5A4: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8044E5A8: jal         0x80066E88
    // 0x8044E5AC: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x8044E5AC: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8044E5B0: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8044E5B4: lwc1        $f12, 0x84($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8044E5B8: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8044E5BC: jal         0x80066DE4
    // 0x8044E5C0: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x8044E5C0: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8044E5C4: lwc1        $f20, 0x7C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8044E5C8: lwc1        $f12, 0x84($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8044E5CC: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8044E5D0: jal         0x80066E88
    // 0x8044E5D4: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x8044E5D4: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x8044E5D8: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8044E5DC: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8044E5E0: mul.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8044E5E4: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8044E5E8: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8044E5EC: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8044E5F0: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8044E5F4: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8044E5F8: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x8044E5FC: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8044E600: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8044E604: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x8044E608: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8044E60C: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8044E610: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x8044E614: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x8044E618: jal         0x8006C56C
    // 0x8044E61C: swc1        $f8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
    func_8006C56C(rdram, ctx);
        goto after_8;
    // 0x8044E61C: swc1        $f8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x8044E620: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8044E624: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8044E628: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044E62C: swc1        $f0, 0x6F20($v0)
    MEM_W(0X6F20, ctx->r2) = ctx->f0.u32l;
    // 0x8044E630: swc1        $f0, 0x6F24($v0)
    MEM_W(0X6F24, ctx->r2) = ctx->f0.u32l;
    // 0x8044E634: swc1        $f0, 0x6F28($v0)
    MEM_W(0X6F28, ctx->r2) = ctx->f0.u32l;
    // 0x8044E638: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8044E63C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8044E640: b           L_8044E670
    // 0x8044E644: swc1        $f0, 0x6F18($at)
    MEM_W(0X6F18, ctx->r1) = ctx->f0.u32l;
        goto L_8044E670;
    // 0x8044E644: swc1        $f0, 0x6F18($at)
    MEM_W(0X6F18, ctx->r1) = ctx->f0.u32l;
L_8044E648:
    // 0x8044E648: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8044E64C: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8044E650: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8044E654: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8044E658: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x8044E65C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8044E660: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8044E664: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8044E668: jal         0x8044DF2C
    // 0x8044E66C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_8044DF2C(rdram, ctx);
        goto after_9;
    // 0x8044E66C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_9:
L_8044E670:
    // 0x8044E670: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8044E674: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8044E678: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x8044E67C: jr          $ra
    // 0x8044E680: nop

    return;
    // 0x8044E680: nop

;}
RECOMP_FUNC void func_80425408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80425408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042540C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80425410: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80425414: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80425418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042541C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80425420: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80425424: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80425428: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8042542C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80425430: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80425434: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80425438: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(35, 0X366C) << 16);
    // 0x8042543C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80425440: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80425444: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80425448: lw          $t2, 0x606C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(35, 0X366C));
    // 0x8042544C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80425450: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80425454: jal         0x80424EC0
    // 0x80425458: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80424EC0(rdram, ctx);
        goto after_0;
    // 0x80425458: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042545C: jal         0x80424F1C
    // 0x80425460: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80424F1C(rdram, ctx);
        goto after_1;
    // 0x80425460: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80425464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80425468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042546C: jr          $ra
    // 0x80425470: nop

    return;
    // 0x80425470: nop

;}
RECOMP_FUNC void func_8076009C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076009C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x807600A0: beql        $at, $zero, L_807600B4
    if (ctx->r1 == 0) {
        // 0x807600A4: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_807600B4;
    }
    goto skip_0;
    // 0x807600A4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x807600A8: jr          $ra
    // 0x807600AC: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x807600AC: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x807600B0: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_807600B4:
    // 0x807600B4: beq         $at, $zero, L_807600F0
    if (ctx->r1 == 0) {
        // 0x807600B8: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_807600F0;
    }
    // 0x807600B8: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x807600BC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x807600C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807600C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807600C8: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x807600CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807600D0: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x807600D4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x807600D8: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x807600DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807600E0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x807600E4: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x807600E8: jr          $ra
    // 0x807600EC: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x807600EC: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_807600F0:
    // 0x807600F0: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x807600F4: beq         $at, $zero, L_8076010C
    if (ctx->r1 == 0) {
        // 0x807600F8: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_8076010C;
    }
    // 0x807600F8: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x807600FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80760100: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80760104: jr          $ra
    // 0x80760108: nop

    return;
    // 0x80760108: nop

L_8076010C:
    // 0x8076010C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80760110: beq         $at, $zero, L_80760150
    if (ctx->r1 == 0) {
        // 0x80760114: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80760150;
    }
    // 0x80760114: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80760118: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x8076011C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80760120: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80760124: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80760128: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8076012C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80760130: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x80760134: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80760138: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8076013C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80760140: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80760144: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80760148: jr          $ra
    // 0x8076014C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x8076014C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_80760150:
    // 0x80760150: jr          $ra
    // 0x80760154: nop

    return;
    // 0x80760154: nop

;}
RECOMP_FUNC void func_8078EFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078EFE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078EFEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078EFF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078EFF4: jal         0x8078EFA4
    // 0x8078EFF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8078EFA4(rdram, ctx);
        goto after_0;
    // 0x8078EFF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8078EFFC: bne         $v0, $zero, L_8078F014
    if (ctx->r2 != 0) {
        // 0x8078F000: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8078F014;
    }
    // 0x8078F000: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8078F004: jal         0x800445A4
    // 0x8078F008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8078F008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8078F00C: b           L_8078F090
    // 0x8078F010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078F090;
    // 0x8078F010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078F014:
    // 0x8078F014: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8078F018: addiu       $at, $zero, 0x46E2
    ctx->r1 = ADD32(0, 0X46E2);
    // 0x8078F01C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8078F020: sb          $t6, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r14;
    // 0x8078F024: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8078F028: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8078F02C: beq         $v0, $at, L_8078F06C
    if (ctx->r2 == ctx->r1) {
        // 0x8078F030: sh          $zero, 0x144($s0)
        MEM_H(0X144, ctx->r16) = 0;
            goto L_8078F06C;
    }
    // 0x8078F030: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x8078F034: addiu       $at, $zero, 0x46E3
    ctx->r1 = ADD32(0, 0X46E3);
    // 0x8078F038: bne         $v0, $at, L_8078F08C
    if (ctx->r2 != ctx->r1) {
        // 0x8078F03C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8078F08C;
    }
    // 0x8078F03C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078F040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078F044: jal         0x8078F0A0
    // 0x8078F048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8078F0A0(rdram, ctx);
        goto after_2;
    // 0x8078F048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8078F04C: jal         0x8078EB10
    // 0x8078F050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078EB10(rdram, ctx);
        goto after_3;
    // 0x8078F050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8078F054: bnel        $v0, $zero, L_8078F090
    if (ctx->r2 != 0) {
        // 0x8078F058: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078F090;
    }
    goto skip_0;
    // 0x8078F058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8078F05C: jal         0x800445A4
    // 0x8078F060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8078F060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8078F064: b           L_8078F090
    // 0x8078F068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078F090;
    // 0x8078F068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078F06C:
    // 0x8078F06C: lbu         $t7, 0xE($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XE);
    // 0x8078F070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078F074: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078F078: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x8078F07C: ori         $t9, $t8, 0x18
    ctx->r25 = ctx->r24 | 0X18;
    // 0x8078F080: sb          $t9, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r25;
    // 0x8078F084: jal         0x8078F0A0
    // 0x8078F088: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8078F0A0(rdram, ctx);
        goto after_5;
    // 0x8078F088: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
L_8078F08C:
    // 0x8078F08C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078F090:
    // 0x8078F090: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078F094: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078F098: jr          $ra
    // 0x8078F09C: nop

    return;
    // 0x8078F09C: nop

;}
RECOMP_FUNC void func_8078A9EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A9EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078A9F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078A9F4: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8078A9F8: lui         $a1, 0xBCA3
    ctx->r5 = S32(0XBCA3 << 16);
    // 0x8078A9FC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8078AA00: beq         $t6, $zero, L_8078AA24
    if (ctx->r14 == 0) {
        // 0x8078AA04: ori         $a1, $a1, 0xD70A
        ctx->r5 = ctx->r5 | 0XD70A;
            goto L_8078AA24;
    }
    // 0x8078AA04: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x8078AA08: jal         0x8078A81C
    // 0x8078AA0C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8078A81C(rdram, ctx);
        goto after_0;
    // 0x8078AA0C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8078AA10: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8078AA14: lw          $t7, 0x1E0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1E0);
    // 0x8078AA18: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8078AA1C: b           L_8078AA54
    // 0x8078AA20: sw          $t8, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r24;
        goto L_8078AA54;
    // 0x8078AA20: sw          $t8, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r24;
L_8078AA24:
    // 0x8078AA24: jal         0x8004700C
    // 0x8078AA28: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x8078AA28: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8078AA2C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8078AA30: beq         $v0, $zero, L_8078AA54
    if (ctx->r2 == 0) {
        // 0x8078AA34: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8078AA54;
    }
    // 0x8078AA34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8078AA38: lw          $t0, 0x1F4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1F4);
    // 0x8078AA3C: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    // 0x8078AA40: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8078AA44: sb          $t9, 0x1B4($t0)
    MEM_B(0X1B4, ctx->r8) = ctx->r25;
    // 0x8078AA48: lw          $t1, 0x260($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X260);
    // 0x8078AA4C: jal         0x80062DD4
    // 0x8078AA50: lbu         $a0, 0x15($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X15);
    func_80062DD4(rdram, ctx);
        goto after_2;
    // 0x8078AA50: lbu         $a0, 0x15($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X15);
    after_2:
L_8078AA54:
    // 0x8078AA54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078AA58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078AA5C: jr          $ra
    // 0x8078AA60: nop

    return;
    // 0x8078AA60: nop

;}
RECOMP_FUNC void func_807B93C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B93C0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x807B93C4: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x807B93C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B93CC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x807B93D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x807B93D4: lw          $a2, 0x3C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X3C);
    // 0x807B93D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807B93DC: blezl       $a2, L_807B9410
    if (SIGNED(ctx->r6) <= 0) {
        // 0x807B93E0: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_807B9410;
    }
    goto skip_0;
    // 0x807B93E0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_0:
L_807B93E4:
    // 0x807B93E4: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x807B93E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x807B93EC: beql        $a1, $zero, L_807B9404
    if (ctx->r5 == 0) {
        // 0x807B93F0: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_807B9404;
    }
    goto skip_1;
    // 0x807B93F0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    skip_1:
    // 0x807B93F4: lw          $a3, 0x16C($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X16C);
    // 0x807B93F8: sb          $s0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r16;
    // 0x807B93FC: lw          $a2, 0x3C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X3C);
    // 0x807B9400: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
L_807B9404:
    // 0x807B9404: bne         $at, $zero, L_807B93E4
    if (ctx->r1 != 0) {
        // 0x807B9408: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_807B93E4;
    }
    // 0x807B9408: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807B940C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_807B9410:
    // 0x807B9410: jr          $ra
    // 0x807B9414: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x807B9414: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_804B9FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B9FA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804B9FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B9FAC: jal         0x8004700C
    // 0x804B9FB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804B9FB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B9FB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804B9FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B9FBC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804B9FC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x804B9FC4: jal         0x8004921C
    // 0x804B9FC8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804B9FC8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x804B9FCC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x804B9FD0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x804B9FD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804B9FD8: beq         $a2, $zero, L_804BA0B8
    if (ctx->r6 == 0) {
        // 0x804B9FDC: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_804BA0B8;
    }
    // 0x804B9FDC: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x804B9FE0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x804B9FE4: lwc1        $f4, 0xB68($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB68);
    // 0x804B9FE8: lwc1        $f6, 0xB6C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB6C);
    // 0x804B9FEC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804B9FF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804B9FF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804B9FF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804B9FFC: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(185, 0X2AFC) << 16);
    // 0x804BA000: swc1        $f8, 0xB68($v1)
    MEM_W(0XB68, ctx->r3) = ctx->f8.u32l;
    // 0x804BA004: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804BA008: lwc1        $f10, 0xB68($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XB68);
    // 0x804BA00C: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x804BA010: lwc1        $f6, -0x56E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(185, 0X2AFC));
    // 0x804BA014: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(185, 0X2B00) << 16);
    // 0x804BA018: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x804BA01C: nop

    // 0x804BA020: bc1tl       L_804BA040
    if (c1cs) {
        // 0x804BA024: lw          $t7, 0x180($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X180);
            goto L_804BA040;
    }
    goto skip_0;
    // 0x804BA024: lw          $t7, 0x180($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X180);
    skip_0:
    // 0x804BA028: lwc1        $f8, -0x56E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(185, 0X2B00));
    // 0x804BA02C: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x804BA030: nop

    // 0x804BA034: bc1fl       L_804BA0BC
    if (!c1cs) {
        // 0x804BA038: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BA0BC;
    }
    goto skip_1;
    // 0x804BA038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804BA03C: lw          $t7, 0x180($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X180);
L_804BA040:
    // 0x804BA040: bnel        $a0, $t7, L_804BA0BC
    if (ctx->r4 != ctx->r15) {
        // 0x804BA044: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BA0BC;
    }
    goto skip_2;
    // 0x804BA044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804BA048: lwc1        $f12, 0xB68($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XB68);
    // 0x804BA04C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x804BA050: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804BA054: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x804BA058: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(185, 0X2B08) << 16);
    // 0x804BA05C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804BA060: nop

    // 0x804BA064: bc1f        L_804BA09C
    if (!c1cs) {
        // 0x804BA068: nop
    
            goto L_804BA09C;
    }
    // 0x804BA068: nop

    // 0x804BA06C: lwc1        $f0, 0xB6C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XB6C);
    // 0x804BA070: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804BA074: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(185, 0X2B04) << 16);
    // 0x804BA078: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x804BA07C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x804BA080: nop

    // 0x804BA084: bc1fl       L_804BA0BC
    if (!c1cs) {
        // 0x804BA088: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BA0BC;
    }
    goto skip_3;
    // 0x804BA088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x804BA08C: lwc1        $f4, -0x56DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(185, 0X2B04));
    // 0x804BA090: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804BA094: b           L_804BA0B8
    // 0x804BA098: swc1        $f6, 0xB6C($v1)
    MEM_W(0XB6C, ctx->r3) = ctx->f6.u32l;
        goto L_804BA0B8;
    // 0x804BA098: swc1        $f6, 0xB6C($v1)
    MEM_W(0XB6C, ctx->r3) = ctx->f6.u32l;
L_804BA09C:
    // 0x804BA09C: lwc1        $f8, -0x56D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(185, 0X2B08));
    // 0x804BA0A0: lwc1        $f10, 0x3C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x804BA0A4: lwc1        $f4, 0xB6C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB6C);
    // 0x804BA0A8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804BA0AC: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x804BA0B0: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x804BA0B4: swc1        $f6, 0xB6C($v1)
    MEM_W(0XB6C, ctx->r3) = ctx->f6.u32l;
L_804BA0B8:
    // 0x804BA0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BA0BC:
    // 0x804BA0BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BA0C0: jr          $ra
    // 0x804BA0C4: nop

    return;
    // 0x804BA0C4: nop

;}
RECOMP_FUNC void func_80056904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056908: beq         $a0, $zero, L_80056924
    if (ctx->r4 == 0) {
        // 0x8005690C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80056924;
    }
    // 0x8005690C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056910: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80056914: beql        $a0, $zero, L_80056928
    if (ctx->r4 == 0) {
        // 0x80056918: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80056928;
    }
    goto skip_0;
    // 0x80056918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005691C: jal         0x80064E84
    // 0x80056920: nop

    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80056920: nop

    after_0:
L_80056924:
    // 0x80056924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80056928:
    // 0x80056928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005692C: jr          $ra
    // 0x80056930: nop

    return;
    // 0x80056930: nop

;}
RECOMP_FUNC void func_8002DAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DAF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002DAF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002DAF8: sb          $t6, 0xF4($a0)
    MEM_B(0XF4, ctx->r4) = ctx->r14;
    // 0x8002DAFC: sw          $zero, 0x12D0($a0)
    MEM_W(0X12D0, ctx->r4) = 0;
    // 0x8002DB00: sb          $zero, 0x21($a0)
    MEM_B(0X21, ctx->r4) = 0;
    // 0x8002DB04: sh          $zero, 0x102($a0)
    MEM_H(0X102, ctx->r4) = 0;
    // 0x8002DB08: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    // 0x8002DB0C: jr          $ra
    // 0x8002DB10: swc1        $f0, 0x12E4($a0)
    MEM_W(0X12E4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8002DB10: swc1        $f0, 0x12E4($a0)
    MEM_W(0X12E4, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80672750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672750: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80672754: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x80672758: lui         $t9, 0x8067
    ctx->r25 = S32(RELOC_HI16(526, 0X21F0) << 16);
    // 0x8067275C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80672760: andi        $v0, $t7, 0x10
    ctx->r2 = ctx->r15 & 0X10;
    // 0x80672764: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x80672768: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8067276C: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80672770: lbu         $t9, 0x2D20($t9)
    ctx->r25 = MEM_BU(ctx->r25, (int16_t)RELOC_LO16(526, 0X21F0));
    // 0x80672774: lw          $v1, 0x16C($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X16C);
    // 0x80672778: jr          $ra
    // 0x8067277C: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
    return;
    // 0x8067277C: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
;}
RECOMP_FUNC void func_8006D7E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D7E8: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8006D7EC: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x8006D7F0: lw          $t6, 0x3EC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X3EC);
    // 0x8006D7F4: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x8006D7F8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006D7FC: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8006D800: beq         $v0, $at, L_8006D81C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D804: lbu         $v1, 0x1C($t7)
        ctx->r3 = MEM_BU(ctx->r15, 0X1C);
            goto L_8006D81C;
    }
    // 0x8006D804: lbu         $v1, 0x1C($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X1C);
    // 0x8006D808: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006D80C: beq         $v0, $at, L_8006D81C
    if (ctx->r2 == ctx->r1) {
        // 0x8006D810: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006D81C;
    }
    // 0x8006D810: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006D814: bnel        $v0, $at, L_8006D854
    if (ctx->r2 != ctx->r1) {
        // 0x8006D818: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8006D854;
    }
    goto skip_0;
    // 0x8006D818: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
L_8006D81C:
    // 0x8006D81C: lw          $a0, 0x8D0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8D0);
    // 0x8006D820: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D824: lh          $t8, 0x7C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X7C);
    // 0x8006D828: bnel        $t8, $at, L_8006D840
    if (ctx->r24 != ctx->r1) {
        // 0x8006D82C: lw          $a0, 0x62C($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X62C);
            goto L_8006D840;
    }
    goto skip_1;
    // 0x8006D82C: lw          $a0, 0x62C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X62C);
    skip_1:
    // 0x8006D830: lw          $t9, 0x80($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X80);
    // 0x8006D834: jr          $ra
    // 0x8006D838: lbu         $v0, 0x4($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X4);
    return;
    // 0x8006D838: lbu         $v0, 0x4($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X4);
    // 0x8006D83C: lw          $a0, 0x62C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X62C);
L_8006D840:
    // 0x8006D840: beql        $a0, $zero, L_8006D854
    if (ctx->r4 == 0) {
        // 0x8006D844: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8006D854;
    }
    goto skip_2;
    // 0x8006D844: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_2:
    // 0x8006D848: jr          $ra
    // 0x8006D84C: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    return;
    // 0x8006D84C: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x8006D850: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8006D854:
    // 0x8006D854: jr          $ra
    // 0x8006D858: nop

    return;
    // 0x8006D858: nop

;}
RECOMP_FUNC void func_800654B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800654B4: bne         $a0, $zero, L_800654C4
    if (ctx->r4 != 0) {
        // 0x800654B8: nop
    
            goto L_800654C4;
    }
    // 0x800654B8: nop

    // 0x800654BC: jr          $ra
    // 0x800654C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800654C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800654C4:
    // 0x800654C4: bne         $a1, $zero, L_800654D4
    if (ctx->r5 != 0) {
        // 0x800654C8: sltu        $at, $a2, $a3
        ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
            goto L_800654D4;
    }
    // 0x800654C8: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x800654CC: jr          $ra
    // 0x800654D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800654D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800654D4:
    // 0x800654D4: bne         $at, $zero, L_80065508
    if (ctx->r1 != 0) {
        // 0x800654D8: nop
    
            goto L_80065508;
    }
    // 0x800654D8: nop

    // 0x800654DC: divu        $zero, $a2, $a3
    lo = S32(U32(ctx->r6) / U32(ctx->r7)); hi = S32(U32(ctx->r6) % U32(ctx->r7));
    // 0x800654E0: mflo        $t6
    ctx->r14 = lo;
    // 0x800654E4: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x800654E8: bne         $a3, $zero, L_800654F4
    if (ctx->r7 != 0) {
        // 0x800654EC: nop
    
            goto L_800654F4;
    }
    // 0x800654EC: nop

    // 0x800654F0: break       7
    do_break(2147898608);
L_800654F4:
    // 0x800654F4: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800654F8: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x800654FC: mflo        $t7
    ctx->r15 = lo;
    // 0x80065500: beq         $a2, $t7, L_80065510
    if (ctx->r6 == ctx->r15) {
        // 0x80065504: nop
    
            goto L_80065510;
    }
    // 0x80065504: nop

L_80065508:
    // 0x80065508: jr          $ra
    // 0x8006550C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006550C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065510:
    // 0x80065510: beq         $t9, $zero, L_80065520
    if (ctx->r25 == 0) {
        // 0x80065514: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80065520;
    }
    // 0x80065514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80065518: jr          $ra
    // 0x8006551C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006551C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80065520:
    // 0x80065520: jr          $ra
    // 0x80065524: nop

    return;
    // 0x80065524: nop

;}
RECOMP_FUNC void func_804E7AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E7AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E7AF8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804E7AFC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804E7B00: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804E7B04: lui         $t8, 0x804E
    ctx->r24 = S32(RELOC_HI16(261, 0X674) << 16);
    // 0x804E7B08: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804E7B0C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804E7B10: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804E7B14: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804E7B18: lw          $t8, 0x7ED4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(261, 0X674));
    // 0x804E7B1C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804E7B20: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804E7B24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804E7B28: jal         0x80048490
    // 0x804E7B2C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804E7B2C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804E7B30: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804E7B34: jal         0x80048378
    // 0x804E7B38: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804E7B38: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804E7B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E7B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E7B44: jr          $ra
    // 0x804E7B48: nop

    return;
    // 0x804E7B48: nop

;}
RECOMP_FUNC void func_807AD774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD774: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x807AD778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AD77C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x807AD780: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x807AD784: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x807AD788: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x807AD78C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807AD790: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x807AD794: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x807AD798: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x807AD79C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x807AD7A0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807AD7A4: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x807AD7A8: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x807AD7AC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x807AD7B0: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x807AD7B4: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x807AD7B8: ori         $t6, $t6, 0x2CC0
    ctx->r14 = ctx->r14 | 0X2CC0;
    // 0x807AD7BC: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x807AD7C0: ori         $t5, $t5, 0x18
    ctx->r13 = ctx->r13 | 0X18;
    // 0x807AD7C4: ori         $a1, $a1, 0x4240
    ctx->r5 = ctx->r5 | 0X4240;
    // 0x807AD7C8: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x807AD7CC: beq         $a2, $zero, L_807AD81C
    if (ctx->r6 == 0) {
        // 0x807AD7D0: addiu       $t1, $t0, 0x8
        ctx->r9 = ADD32(ctx->r8, 0X8);
            goto L_807AD81C;
    }
    // 0x807AD7D0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x807AD7D4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x807AD7D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807AD7DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807AD7E0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807AD7E4: ctc1        $a2, $FpcCsr
    set_cop1_cs(ctx->r6);
    // 0x807AD7E8: nop

    // 0x807AD7EC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x807AD7F0: cfc1        $a2, $FpcCsr
    ctx->r6 = get_cop1_cs();
    // 0x807AD7F4: nop

    // 0x807AD7F8: andi        $a2, $a2, 0x78
    ctx->r6 = ctx->r6 & 0X78;
    // 0x807AD7FC: bne         $a2, $zero, L_807AD814
    if (ctx->r6 != 0) {
        // 0x807AD800: nop
    
            goto L_807AD814;
    }
    // 0x807AD800: nop

    // 0x807AD804: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x807AD808: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x807AD80C: b           L_807AD82C
    // 0x807AD810: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
        goto L_807AD82C;
    // 0x807AD810: or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
L_807AD814:
    // 0x807AD814: b           L_807AD82C
    // 0x807AD818: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_807AD82C;
    // 0x807AD818: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_807AD81C:
    // 0x807AD81C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x807AD820: nop

    // 0x807AD824: bltz        $a2, L_807AD814
    if (SIGNED(ctx->r6) < 0) {
        // 0x807AD828: nop
    
            goto L_807AD814;
    }
    // 0x807AD828: nop

L_807AD82C:
    // 0x807AD82C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x807AD830: sltiu       $at, $a2, 0x100
    ctx->r1 = ctx->r6 < 0X100 ? 1 : 0;
    // 0x807AD834: bne         $at, $zero, L_807AD840
    if (ctx->r1 != 0) {
        // 0x807AD838: lui         $t9, 0xB900
        ctx->r25 = S32(0XB900 << 16);
            goto L_807AD840;
    }
    // 0x807AD838: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x807AD83C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_807AD840:
    // 0x807AD840: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x807AD844: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x807AD848: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x807AD84C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x807AD850: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x807AD854: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x807AD858: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x807AD85C: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x807AD860: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x807AD864: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x807AD868: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x807AD86C: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x807AD870: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x807AD874: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x807AD878: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x807AD87C: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x807AD880: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x807AD884: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x807AD888: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x807AD88C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x807AD890: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x807AD894: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x807AD898: sw          $a1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r5;
    // 0x807AD89C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x807AD8A0: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x807AD8A4: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x807AD8A8: lui         $t1, 0xFFFF
    ctx->r9 = S32(0XFFFF << 16);
    // 0x807AD8AC: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x807AD8B0: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x807AD8B4: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x807AD8B8: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x807AD8BC: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x807AD8C0: ori         $t1, $t1, 0x7F00
    ctx->r9 = ctx->r9 | 0X7F00;
    // 0x807AD8C4: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x807AD8C8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x807AD8CC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x807AD8D0: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
    // 0x807AD8D4: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x807AD8D8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x807AD8DC: lui         $t5, 0x5566
    ctx->r13 = S32(0X5566 << 16);
    // 0x807AD8E0: lui         $t4, 0xFC30
    ctx->r12 = S32(0XFC30 << 16);
    // 0x807AD8E4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x807AD8E8: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x807AD8EC: ori         $t4, $t4, 0xB261
    ctx->r12 = ctx->r12 | 0XB261;
    // 0x807AD8F0: ori         $t5, $t5, 0xDB6D
    ctx->r13 = ctx->r13 | 0XDB6D;
    // 0x807AD8F4: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x807AD8F8: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x807AD8FC: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x807AD900: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x807AD904: addiu       $t9, $zero, 0x204
    ctx->r25 = ADD32(0, 0X204);
    // 0x807AD908: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x807AD90C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x807AD910: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x807AD914: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x807AD918: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x807AD91C: lui         $t2, 0xBB00
    ctx->r10 = S32(0XBB00 << 16);
    // 0x807AD920: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
    // 0x807AD924: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x807AD928: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x807AD92C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x807AD930: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x807AD934: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x807AD938: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x807AD93C: jal         0x807AD654
    // 0x807AD940: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_807AD654(rdram, ctx);
        goto after_0;
    // 0x807AD940: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x807AD944: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x807AD948: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x807AD94C: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
    // 0x807AD950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AD954: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x807AD958: jr          $ra
    // 0x807AD95C: nop

    return;
    // 0x807AD95C: nop

;}
RECOMP_FUNC void func_80031170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031170: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80031174: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80031178: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8003117C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80031180: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80031184: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80031188: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8003118C: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80031190: lwc1        $f16, 0xC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80031194: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80031198: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003119C: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x800311A0: nop

    // 0x800311A4: bc1fl       L_800311C4
    if (!c1cs) {
        // 0x800311A8: swc1        $f0, 0x74($a0)
        MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
            goto L_800311C4;
    }
    goto skip_0;
    // 0x800311A8: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x800311AC: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800311B0: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
    // 0x800311B4: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x800311B8: jr          $ra
    // 0x800311BC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800311BC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x800311C0: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
L_800311C4:
    // 0x800311C4: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x800311C8: jr          $ra
    // 0x800311CC: nop

    return;
    // 0x800311CC: nop

;}
RECOMP_FUNC void func_805586D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805586D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805586DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805586E0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805586E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805586E8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805586EC: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    // 0x805586F0: jal         0x8005FCA8
    // 0x805586F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x805586F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805586F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805586FC: lui         $t9, 0x8055
    ctx->r25 = S32(RELOC_HI16(363, 0X1F4) << 16);
    // 0x80558700: addiu       $t9, $t9, 0x7D44
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(363, 0X1F4));
    // 0x80558704: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x80558708: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8055870C: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    // 0x80558710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80558714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80558718: jr          $ra
    // 0x8055871C: nop

    return;
    // 0x8055871C: nop

;}
RECOMP_FUNC void func_80742944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742944: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742948: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8074294C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742950: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742954: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742958: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8074295C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742960: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742964: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742968: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8074296C: jr          $ra
    // 0x80742970: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742970: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80525F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525F00: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(327, 0X10) << 16);
    // 0x80525F04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80525F08: jr          $ra
    // 0x80525F0C: addiu       $v0, $v0, 0x5F10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(327, 0X10));
    return;
    // 0x80525F0C: addiu       $v0, $v0, 0x5F10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(327, 0X10));
;}
RECOMP_FUNC void func_805A52C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A52C0: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(417, 0X20) << 16);
    // 0x805A52C4: addiu       $t6, $t6, 0x52E0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(417, 0X20));
    // 0x805A52C8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A52CC: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(417, 0X1340) << 16);
    // 0x805A52D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x805A52D4: sw          $t6, -0x729C($at)
    MEM_W(-0X729C, ctx->r1) = ctx->r14;
    // 0x805A52D8: jr          $ra
    // 0x805A52DC: addiu       $v0, $v0, 0x6600
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(417, 0X1340));
    return;
    // 0x805A52DC: addiu       $v0, $v0, 0x6600
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(417, 0X1340));
;}
RECOMP_FUNC void func_806E6254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E6254: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E6258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E625C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806E6260: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x806E6264: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x806E6268: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806E626C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E6270: bnel        $t6, $at, L_806E6300
    if (ctx->r14 != ctx->r1) {
        // 0x806E6274: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E6300;
    }
    goto skip_0;
    // 0x806E6274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E6278: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x806E627C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806E6280: bnel        $t7, $at, L_806E6300
    if (ctx->r15 != ctx->r1) {
        // 0x806E6284: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E6300;
    }
    goto skip_1;
    // 0x806E6284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806E6288: lbu         $t8, 0x30($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X30);
    // 0x806E628C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x806E6290: bnel        $t8, $at, L_806E6300
    if (ctx->r24 != ctx->r1) {
        // 0x806E6294: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E6300;
    }
    goto skip_2;
    // 0x806E6294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x806E6298: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x806E629C: beql        $v1, $zero, L_806E6300
    if (ctx->r3 == 0) {
        // 0x806E62A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E6300;
    }
    goto skip_3;
    // 0x806E62A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x806E62A4: lw          $t9, 0x40($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X40);
    // 0x806E62A8: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x806E62AC: bnel        $t9, $zero, L_806E6300
    if (ctx->r25 != 0) {
        // 0x806E62B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E6300;
    }
    goto skip_4;
    // 0x806E62B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x806E62B4: sw          $t0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r8;
    // 0x806E62B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806E62BC: jal         0x806E5E54
    // 0x806E62C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_806E5E54(rdram, ctx);
        goto after_0;
    // 0x806E62C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x806E62C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806E62C8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x806E62CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E62D0: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x806E62D4: lw          $t2, 0x3C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X3C);
    // 0x806E62D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E62DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806E62E0: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x806E62E4: sw          $t1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r9;
    // 0x806E62E8: bne         $t2, $zero, L_806E62FC
    if (ctx->r10 != 0) {
        // 0x806E62EC: swc1        $f8, 0x30($v0)
        MEM_W(0X30, ctx->r2) = ctx->f8.u32l;
            goto L_806E62FC;
    }
    // 0x806E62EC: swc1        $f8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f8.u32l;
    // 0x806E62F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E62F4: jal         0x806E6BC8
    // 0x806E62F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_806E6BC8(rdram, ctx);
        goto after_1;
    // 0x806E62F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_806E62FC:
    // 0x806E62FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E6300:
    // 0x806E6300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E6304: jr          $ra
    // 0x806E6308: nop

    return;
    // 0x806E6308: nop

;}
RECOMP_FUNC void func_80048690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048690: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80048694: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x80048698: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x8004869C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800486A0: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x800486A4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800486A8: sltu        $at, $t7, $t0
    ctx->r1 = ctx->r15 < ctx->r8 ? 1 : 0;
    // 0x800486AC: bnel        $at, $zero, L_800486EC
    if (ctx->r1 != 0) {
        // 0x800486B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800486EC;
    }
    goto skip_0;
    // 0x800486B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800486B4: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x800486B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800486BC: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x800486C0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800486C4: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x800486C8: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x800486CC: beql        $t2, $t3, L_800486E0
    if (ctx->r10 == ctx->r11) {
        // 0x800486D0: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_800486E0;
    }
    goto skip_1;
    // 0x800486D0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_1:
    // 0x800486D4: b           L_800486E8
    // 0x800486D8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
        goto L_800486E8;
    // 0x800486D8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800486DC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800486E0:
    // 0x800486E0: jr          $ra
    // 0x800486E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800486E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800486E8:
    // 0x800486E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800486EC:
    // 0x800486EC: jr          $ra
    // 0x800486F0: nop

    return;
    // 0x800486F0: nop

;}
RECOMP_FUNC void func_80445AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445AB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445ABC: jal         0x800677F8
    // 0x80445AC0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x80445AC0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80445AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445ACC: jr          $ra
    // 0x80445AD0: nop

    return;
    // 0x80445AD0: nop

;}
RECOMP_FUNC void func_80041024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041024: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80041028: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8004102C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80041030: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80041034: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80041038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004103C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80041040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041044: addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // 0x80041048: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8004104C: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x80041050: jalr        $t9
    // 0x80041054: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80041054: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    after_0:
    // 0x80041058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004105C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041064: jr          $ra
    // 0x80041068: nop

    return;
    // 0x80041068: nop

;}
RECOMP_FUNC void func_8002E0B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E0B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E0B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002E0B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002E0BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E0C0: jal         0x80040C48
    // 0x8002E0C4: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    func_80040C48(rdram, ctx);
        goto after_0;
    // 0x8002E0C4: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    after_0:
    // 0x8002E0C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E0CC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8002E0D0: jal         0x8002DBE4
    // 0x8002E0D4: lw          $a2, 0x12C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X12C);
    func_8002DBE4(rdram, ctx);
        goto after_1;
    // 0x8002E0D4: lw          $a2, 0x12C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x8002E0D8: jal         0x8001D770
    // 0x8002E0DC: nop

    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x8002E0DC: nop

    after_2:
    // 0x8002E0E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002E0E4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002E0E8: jal         0x80067BF8
    // 0x8002E0EC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x8002E0EC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8002E0F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8002E0F4: jal         0x80067818
    // 0x8002E0F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8002E0F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8002E0FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002E104: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002E108: jr          $ra
    // 0x8002E10C: nop

    return;
    // 0x8002E10C: nop

;}
RECOMP_FUNC void func_8066A354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A35C: jal         0x80669E80
    // 0x8066A360: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80669E80(rdram, ctx);
        goto after_0;
    // 0x8066A360: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066A364: jal         0x80669FA4
    // 0x8066A368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80669FA4(rdram, ctx);
        goto after_1;
    // 0x8066A368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8066A36C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066A370: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8066A374: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A378: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8066A37C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8066A380: blez        $v0, L_8066A390
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8066A384: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8066A390;
    }
    // 0x8066A384: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8066A388: b           L_8066A3A0
    // 0x8066A38C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8066A3A0;
    // 0x8066A38C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8066A390:
    // 0x8066A390: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8066A394: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8066A398: jal         0x8066A790
    // 0x8066A39C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    func_8066A790(rdram, ctx);
        goto after_2;
    // 0x8066A39C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    after_2:
L_8066A3A0:
    // 0x8066A3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066A3A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A3A8: jr          $ra
    // 0x8066A3AC: nop

    return;
    // 0x8066A3AC: nop

;}
RECOMP_FUNC void func_8007DC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DC5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007DC60: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007DC64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007DC68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007DC6C: lbu         $t6, 0x10($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X10);
    // 0x8007DC70: bnel        $t6, $zero, L_8007DC84
    if (ctx->r14 != 0) {
        // 0x8007DC74: lw          $t7, 0x1C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X1C);
            goto L_8007DC84;
    }
    goto skip_0;
    // 0x8007DC74: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    skip_0:
    // 0x8007DC78: b           L_8007DD5C
    // 0x8007DC7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007DD5C;
    // 0x8007DC7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007DC80: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
L_8007DC84:
    // 0x8007DC84: sltiu       $at, $t7, 0x10
    ctx->r1 = ctx->r15 < 0X10 ? 1 : 0;
    // 0x8007DC88: beql        $at, $zero, L_8007DC9C
    if (ctx->r1 == 0) {
        // 0x8007DC8C: lw          $v0, 0x18($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X18);
            goto L_8007DC9C;
    }
    goto skip_1;
    // 0x8007DC8C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    skip_1:
    // 0x8007DC90: b           L_8007DD5C
    // 0x8007DC94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007DD5C;
    // 0x8007DC94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007DC98: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
L_8007DC9C:
    // 0x8007DC9C: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x8007DCA0: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x8007DCA4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8007DCA8: ori         $at, $at, 0x5052
    ctx->r1 = ctx->r1 | 0X5052;
    // 0x8007DCAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007DCB0: bnel        $t8, $at, L_8007DCFC
    if (ctx->r24 != ctx->r1) {
        // 0x8007DCB4: lw          $t3, 0x8($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X8);
            goto L_8007DCFC;
    }
    goto skip_2;
    // 0x8007DCB4: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x8007DCB8: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x8007DCBC: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x8007DCC0: sb          $t9, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r25;
    // 0x8007DCC4: addiu       $t1, $t0, 0x10
    ctx->r9 = ADD32(ctx->r8, 0X10);
    // 0x8007DCC8: sw          $t1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r9;
    // 0x8007DCCC: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8007DCD0: beq         $v1, $zero, L_8007DCE0
    if (ctx->r3 == 0) {
        // 0x8007DCD4: sw          $t2, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r10;
            goto L_8007DCE0;
    }
    // 0x8007DCD4: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
    // 0x8007DCD8: b           L_8007DD00
    // 0x8007DCDC: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
        goto L_8007DD00;
    // 0x8007DCDC: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
L_8007DCE0:
    // 0x8007DCE0: jal         0x80064D1C
    // 0x8007DCE4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x8007DCE4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_0:
    // 0x8007DCE8: bne         $v0, $zero, L_8007DD00
    if (ctx->r2 != 0) {
        // 0x8007DCEC: sw          $v0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r2;
            goto L_8007DD00;
    }
    // 0x8007DCEC: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8007DCF0: b           L_8007DD5C
    // 0x8007DCF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007DD5C;
    // 0x8007DCF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8007DCF8: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
L_8007DCFC:
    // 0x8007DCFC: sw          $t3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r11;
L_8007DD00:
    // 0x8007DD00: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007DD04: addiu       $a0, $a0, -0x12B0
    ctx->r4 = ADD32(ctx->r4, -0X12B0);
    // 0x8007DD08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8007DD0C: jal         0x80082210
    // 0x8007DD10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8007DD10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8007DD14: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8007DD18: jal         0x8008AED0
    // 0x8007DD1C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osInvalDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x8007DD1C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_2:
    // 0x8007DD20: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x8007DD24: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8007DD28: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8007DD2C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8007DD30: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x8007DD34: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8007DD38: addiu       $t6, $t6, -0x12F0
    ctx->r14 = ADD32(ctx->r14, -0X12F0);
    // 0x8007DD3C: addiu       $t7, $zero, 0x1000
    ctx->r15 = ADD32(0, 0X1000);
    // 0x8007DD40: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8007DD44: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8007DD48: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x8007DD4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007DD50: jal         0x8007DB60
    // 0x8007DD54: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    DmaMgr_Read(rdram, ctx);
        goto after_3;
    // 0x8007DD54: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_3:
    // 0x8007DD58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007DD5C:
    // 0x8007DD5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DD60: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007DD64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007DD68: jr          $ra
    // 0x8007DD6C: nop

    return;
    // 0x8007DD6C: nop

;}
RECOMP_FUNC void func_806E3990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3990: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E3994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E3998: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x806E399C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E39A0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806E39A4: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806E39A8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806E39AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806E39B0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x806E39B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x806E39B8: jal         0x8004D150
    // 0x806E39BC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8004D150(rdram, ctx);
        goto after_0;
    // 0x806E39BC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x806E39C0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806E39C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806E39C8: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x806E39CC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x806E39D0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806E39D4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806E39D8: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x806E39DC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x806E39E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E39E4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x806E39E8: lbu         $t1, 0x14($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X14);
    // 0x806E39EC: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x806E39F0: beql        $t1, $zero, L_806E3A24
    if (ctx->r9 == 0) {
        // 0x806E39F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E3A24;
    }
    goto skip_0;
    // 0x806E39F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E39F8: jal         0x8004D618
    // 0x806E39FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8004D618(rdram, ctx);
        goto after_1;
    // 0x806E39FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x806E3A00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E3A04: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806E3A08: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806E3A0C: sw          $v1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r3;
    // 0x806E3A10: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
    // 0x806E3A14: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x806E3A18: ori         $t3, $t2, 0xF00
    ctx->r11 = ctx->r10 | 0XF00;
    // 0x806E3A1C: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x806E3A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E3A24:
    // 0x806E3A24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E3A28: jr          $ra
    // 0x806E3A2C: nop

    return;
    // 0x806E3A2C: nop

;}
RECOMP_FUNC void func_8000571C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000571C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005724: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80005728: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8000572C: jal         0x80005854
    // 0x80005730: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80005854(rdram, ctx);
        goto after_0;
    // 0x80005730: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80005734: beq         $v0, $zero, L_80005758
    if (ctx->r2 == 0) {
        // 0x80005738: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80005758;
    }
    // 0x80005738: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000573C: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x80005740: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80005744: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80005748: lb          $t8, 0x27($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X27);
    // 0x8000574C: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x80005750: b           L_8000575C
    // 0x80005754: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
        goto L_8000575C;
    // 0x80005754: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
L_80005758:
    // 0x80005758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000575C:
    // 0x8000575C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005764: jr          $ra
    // 0x80005768: nop

    return;
    // 0x80005768: nop

;}
RECOMP_FUNC void func_80026B08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026B08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026B0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026B10: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026B14: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80026B18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80026B1C: lw          $t7, 0x1A4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1A4);
    // 0x80026B20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80026B24: bnel        $t7, $zero, L_80026B40
    if (ctx->r15 != 0) {
        // 0x80026B28: addiu       $a0, $a1, 0x14C
        ctx->r4 = ADD32(ctx->r5, 0X14C);
            goto L_80026B40;
    }
    goto skip_0;
    // 0x80026B28: addiu       $a0, $a1, 0x14C
    ctx->r4 = ADD32(ctx->r5, 0X14C);
    skip_0:
    // 0x80026B2C: jal         0x80026AE4
    // 0x80026B30: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    func_80026AE4(rdram, ctx);
        goto after_0;
    // 0x80026B30: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    after_0:
    // 0x80026B34: b           L_80026B70
    // 0x80026B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80026B70;
    // 0x80026B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026B3C: addiu       $a0, $a1, 0x14C
    ctx->r4 = ADD32(ctx->r5, 0X14C);
L_80026B40:
    // 0x80026B40: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80026B44: jal         0x80024680
    // 0x80026B48: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80024680(rdram, ctx);
        goto after_1;
    // 0x80026B48: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x80026B4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80026B50: bne         $v0, $at, L_80026B6C
    if (ctx->r2 != ctx->r1) {
        // 0x80026B54: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80026B6C;
    }
    // 0x80026B54: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80026B58: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x80026B5C: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80026B60: sw          $t8, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->r24;
    // 0x80026B64: sw          $zero, 0x154($a1)
    MEM_W(0X154, ctx->r5) = 0;
    // 0x80026B68: sb          $t9, 0x158($a1)
    MEM_B(0X158, ctx->r5) = ctx->r25;
L_80026B6C:
    // 0x80026B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80026B70:
    // 0x80026B70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026B74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026B78: jr          $ra
    // 0x80026B7C: nop

    return;
    // 0x80026B7C: nop

;}
RECOMP_FUNC void func_8005BE60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BE60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005BE64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BE68: jal         0x8005D110
    // 0x8005BE6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8005D110(rdram, ctx);
        goto after_0;
    // 0x8005BE6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8005BE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BE74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005BE78: jr          $ra
    // 0x8005BE7C: nop

    return;
    // 0x8005BE7C: nop

;}
RECOMP_FUNC void func_80034980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034988: jal         0x80021958
    // 0x8003498C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x8003498C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034990: bne         $v0, $zero, L_800349A0
    if (ctx->r2 != 0) {
        // 0x80034994: nop
    
            goto L_800349A0;
    }
    // 0x80034994: nop

    // 0x80034998: b           L_800349D4
    // 0x8003499C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800349D4;
    // 0x8003499C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800349A0:
    // 0x800349A0: jal         0x80041698
    // 0x800349A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80041698(rdram, ctx);
        goto after_1;
    // 0x800349A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800349A8: beq         $v0, $zero, L_800349B8
    if (ctx->r2 == 0) {
        // 0x800349AC: nop
    
            goto L_800349B8;
    }
    // 0x800349AC: nop

    // 0x800349B0: b           L_800349D4
    // 0x800349B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800349D4;
    // 0x800349B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800349B8:
    // 0x800349B8: jal         0x8003431C
    // 0x800349BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003431C(rdram, ctx);
        goto after_2;
    // 0x800349BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800349C0: bnel        $v0, $zero, L_800349D4
    if (ctx->r2 != 0) {
        // 0x800349C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800349D4;
    }
    goto skip_0;
    // 0x800349C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800349C8: b           L_800349D4
    // 0x800349CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800349D4;
    // 0x800349CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800349D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800349D4:
    // 0x800349D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800349D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800349DC: jr          $ra
    // 0x800349E0: nop

    return;
    // 0x800349E0: nop

;}
RECOMP_FUNC void func_800106CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800106CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800106D0: beq         $a0, $zero, L_800106F4
    if (ctx->r4 == 0) {
        // 0x800106D4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800106F4;
    }
    // 0x800106D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800106D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800106DC: beq         $a0, $at, L_80010704
    if (ctx->r4 == ctx->r1) {
        // 0x800106E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80010704;
    }
    // 0x800106E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800106E4: beq         $a0, $at, L_80010714
    if (ctx->r4 == ctx->r1) {
        // 0x800106E8: nop
    
            goto L_80010714;
    }
    // 0x800106E8: nop

    // 0x800106EC: b           L_80010720
    // 0x800106F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80010720;
    // 0x800106F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800106F4:
    // 0x800106F4: jal         0x80019128
    // 0x800106F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80019128(rdram, ctx);
        goto after_0;
    // 0x800106F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800106FC: b           L_80010720
    // 0x80010700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80010720;
    // 0x80010700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010704:
    // 0x80010704: jal         0x80019128
    // 0x80010708: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80019128(rdram, ctx);
        goto after_1;
    // 0x80010708: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x8001070C: b           L_80010720
    // 0x80010710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80010720;
    // 0x80010710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010714:
    // 0x80010714: jal         0x80019128
    // 0x80010718: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80019128(rdram, ctx);
        goto after_2;
    // 0x80010718: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8001071C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010720:
    // 0x80010720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80010724: jr          $ra
    // 0x80010728: nop

    return;
    // 0x80010728: nop

    // 0x8001072C: nop

;}
RECOMP_FUNC void func_80045144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045144: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80045148: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8004514C: sll         $s2, $a2, 16
    ctx->r18 = S32(ctx->r6 << 16);
    // 0x80045150: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x80045154: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80045158: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004515C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80045160: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80045164: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80045168: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8004516C: beq         $s2, $zero, L_800451D4
    if (ctx->r18 == 0) {
        // 0x80045170: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_800451D4;
    }
    // 0x80045170: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80045174: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80045178:
    // 0x80045178: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8004517C: beq         $v0, $zero, L_800451CC
    if (ctx->r2 == 0) {
        // 0x80045180: nop
    
            goto L_800451CC;
    }
    // 0x80045180: nop

    // 0x80045184: beql        $s3, $v0, L_800451C4
    if (ctx->r19 == ctx->r2) {
        // 0x80045188: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_800451C4;
    }
    goto skip_0;
    // 0x80045188: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x8004518C: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x80045190: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80045194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80045198: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004519C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800451A0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x800451A4: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x800451A8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800451AC: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    // 0x800451B0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800451B4: addiu       $a1, $v0, 0x188
    ctx->r5 = ADD32(ctx->r2, 0X188);
    // 0x800451B8: jal         0x80045144
    // 0x800451BC: lh          $a2, 0x184($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X184);
    func_80045144(rdram, ctx);
        goto after_0;
    // 0x800451BC: lh          $a2, 0x184($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X184);
    after_0:
    // 0x800451C0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_800451C4:
    // 0x800451C4: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800451C8: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
L_800451CC:
    // 0x800451CC: bne         $s2, $zero, L_80045178
    if (ctx->r18 != 0) {
        // 0x800451D0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80045178;
    }
    // 0x800451D0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800451D4:
    // 0x800451D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800451D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800451DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800451E0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800451E4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800451E8: jr          $ra
    // 0x800451EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800451EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80469580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80469584: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80469588: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8046958C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80469590: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80469594: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80469598: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8046959C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804695A0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804695A4: lui         $t1, 0x8047
    ctx->r9 = S32(RELOC_HI16(135, 0XE38) << 16);
    // 0x804695A8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804695AC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804695B0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804695B4: lw          $t1, -0x69A8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(135, 0XE38));
    // 0x804695B8: jal         0x804695D0
    // 0x804695BC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_804695D0(rdram, ctx);
        goto after_0;
    // 0x804695BC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x804695C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804695C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804695C8: jr          $ra
    // 0x804695CC: nop

    return;
    // 0x804695CC: nop

;}
RECOMP_FUNC void func_8004870C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004870C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80048710: addiu       $t6, $t6, -0x7970
    ctx->r14 = ADD32(ctx->r14, -0X7970);
    // 0x80048714: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x80048718: jr          $ra
    // 0x8004871C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8004871C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80027B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027B4C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80027B50: lw          $t6, -0x7280($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7280);
    // 0x80027B54: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80027B58: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80027B5C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80027B60: bne         $at, $zero, L_80027B70
    if (ctx->r1 != 0) {
        // 0x80027B64: addiu       $t8, $t8, 0x7B14
        ctx->r24 = ADD32(ctx->r24, 0X7B14);
            goto L_80027B70;
    }
    // 0x80027B64: addiu       $t8, $t8, 0x7B14
    ctx->r24 = ADD32(ctx->r24, 0X7B14);
    // 0x80027B68: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
    // 0x80027B6C: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
L_80027B70:
    // 0x80027B70: jr          $ra
    // 0x80027B74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80027B74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800097F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800097F0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800097F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800097F8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800097FC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80009800: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80009804: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80009808: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000980C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80009810: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80009814: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80009818: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000981C: jal         0x8000744C
    // 0x80009820: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8000744C(rdram, ctx);
        goto after_0;
    // 0x80009820: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80009824: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x80009828: addiu       $s5, $s5, 0x4D10
    ctx->r21 = ADD32(ctx->r21, 0X4D10);
    // 0x8000982C: lw          $v1, 0x2274($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X2274);
    // 0x80009830: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80009834: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80009838: blez        $v1, L_80009900
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000983C: lui         $s0, 0x800B
        ctx->r16 = S32(0X800B << 16);
            goto L_80009900;
    }
    // 0x8000983C: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80009840: addiu       $s0, $s0, 0x4D10
    ctx->r16 = ADD32(ctx->r16, 0X4D10);
    // 0x80009844: addiu       $fp, $sp, 0x4C
    ctx->r30 = ADD32(ctx->r29, 0X4C);
    // 0x80009848: addiu       $s7, $zero, 0xC
    ctx->r23 = ADD32(0, 0XC);
    // 0x8000984C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80009850: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
L_80009854:
    // 0x80009854: lh          $t6, 0x2280($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2280);
    // 0x80009858: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000985C: bnel        $s6, $t6, L_800098F4
    if (ctx->r22 != ctx->r14) {
        // 0x80009860: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800098F4;
    }
    goto skip_0;
    // 0x80009860: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80009864: jal         0x800073BC
    // 0x80009868: lh          $a1, 0x2282($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2282);
    func_800073BC(rdram, ctx);
        goto after_1;
    // 0x80009868: lh          $a1, 0x2282($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2282);
    after_1:
    // 0x8000986C: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80009870: lw          $t7, 0x1D78($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X1D78);
    // 0x80009874: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80009878: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000987C: mflo        $t8
    ctx->r24 = lo;
    // 0x80009880: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80009884: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    // 0x80009888: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x8000988C: lbu         $t0, 0x3($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X3);
    // 0x80009890: beq         $t9, $s4, L_800098B4
    if (ctx->r25 == ctx->r20) {
        // 0x80009894: sw          $t0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r8;
            goto L_800098B4;
    }
    // 0x80009894: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x80009898: jal         0x800073BC
    // 0x8000989C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_800073BC(rdram, ctx);
        goto after_2;
    // 0x8000989C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_2:
    // 0x800098A0: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x800098A4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800098A8: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x800098AC: lb          $t4, 0x18($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X18);
    // 0x800098B0: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
L_800098B4:
    // 0x800098B4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800098B8: beql        $a1, $s4, L_800098E0
    if (ctx->r5 == ctx->r20) {
        // 0x800098BC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800098E0;
    }
    goto skip_1;
    // 0x800098BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x800098C0: jal         0x800073BC
    // 0x800098C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800073BC(rdram, ctx);
        goto after_3;
    // 0x800098C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x800098C8: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x800098CC: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800098D0: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x800098D4: lb          $t7, 0x18($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X18);
    // 0x800098D8: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x800098DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800098E0:
    // 0x800098E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800098E4: jal         0x8000938C
    // 0x800098E8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    func_8000938C(rdram, ctx);
        goto after_4;
    // 0x800098E8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_4:
    // 0x800098EC: lw          $v1, 0x2274($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X2274);
    // 0x800098F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800098F4:
    // 0x800098F4: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800098F8: bne         $at, $zero, L_80009854
    if (ctx->r1 != 0) {
        // 0x800098FC: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80009854;
    }
    // 0x800098FC: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80009900:
    // 0x80009900: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80009904: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009908: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000990C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80009910: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80009914: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80009918: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000991C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80009920: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80009924: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80009928: jr          $ra
    // 0x8000992C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8000992C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8069F3EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069F3EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069F3F0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8069F3F4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8069F3F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8069F3FC: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x8069F400: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
    // 0x8069F404: jr          $ra
    // 0x8069F408: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8069F408: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_807B7F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B7F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B7F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B7F54: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x807B7F58: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x807B7F5C: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x807B7F60: bne         $at, $zero, L_807B7F78
    if (ctx->r1 != 0) {
        // 0x807B7F64: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_807B7F78;
    }
    // 0x807B7F64: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x807B7F68: jal         0x807B7C68
    // 0x807B7F6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807B7C68(rdram, ctx);
        goto after_0;
    // 0x807B7F6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807B7F70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B7F74: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
L_807B7F78:
    // 0x807B7F78: jal         0x807B7E18
    // 0x807B7F7C: nop

    func_807B7E18(rdram, ctx);
        goto after_1;
    // 0x807B7F7C: nop

    after_1:
    // 0x807B7F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B7F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B7F88: jr          $ra
    // 0x807B7F8C: nop

    return;
    // 0x807B7F8C: nop

;}
RECOMP_FUNC void func_800300E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800300E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800300E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800300EC: jal         0x800243F8
    // 0x800300F0: nop

    func_800243F8(rdram, ctx);
        goto after_0;
    // 0x800300F0: nop

    after_0:
    // 0x800300F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800300F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800300FC: jr          $ra
    // 0x80030100: nop

    return;
    // 0x80030100: nop

;}
RECOMP_FUNC void func_806EB05C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EB05C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806EB060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EB064: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EB068: jal         0x8004700C
    // 0x806EB06C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EB06C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EB070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EB074: jal         0x806EA9C0
    // 0x806EB078: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_806EA9C0(rdram, ctx);
        goto after_1;
    // 0x806EB078: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x806EB07C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x806EB080: beql        $a1, $zero, L_806EB254
    if (ctx->r5 == 0) {
        // 0x806EB084: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EB254;
    }
    goto skip_0;
    // 0x806EB084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EB088: lwc1        $f4, 0x88($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X88);
    // 0x806EB08C: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806EB090: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806EB094: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806EB098: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806EB09C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806EB0A0: bc1fl       L_806EB0F8
    if (!c1cs) {
        // 0x806EB0A4: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806EB0F8;
    }
    goto skip_1;
    // 0x806EB0A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x806EB0A8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806EB0AC: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806EB0B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806EB0B4: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806EB0B8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(670, 0XF70) << 16);
    // 0x806EB0BC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806EB0C0: nop

    // 0x806EB0C4: bc1fl       L_806EB138
    if (!c1cs) {
        // 0x806EB0C8: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_806EB138;
    }
    goto skip_2;
    // 0x806EB0C8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_2:
    // 0x806EB0CC: lwc1        $f8, -0x48C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(670, 0XF70));
    // 0x806EB0D0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x806EB0D4: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x806EB0D8: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806EB0DC: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x806EB0E0: nop

    // 0x806EB0E4: bc1fl       L_806EB138
    if (!c1cs) {
        // 0x806EB0E8: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_806EB138;
    }
    goto skip_3;
    // 0x806EB0E8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_3:
    // 0x806EB0EC: b           L_806EB134
    // 0x806EB0F0: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
        goto L_806EB134;
    // 0x806EB0F0: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x806EB0F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806EB0F8:
    // 0x806EB0F8: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806EB0FC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(670, 0XF74) << 16);
    // 0x806EB100: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806EB104: nop

    // 0x806EB108: bc1fl       L_806EB138
    if (!c1cs) {
        // 0x806EB10C: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_806EB138;
    }
    goto skip_4;
    // 0x806EB10C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_4:
    // 0x806EB110: lwc1        $f18, -0x48BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(670, 0XF74));
    // 0x806EB114: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x806EB118: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x806EB11C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806EB120: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x806EB124: nop

    // 0x806EB128: bc1fl       L_806EB138
    if (!c1cs) {
        // 0x806EB12C: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_806EB138;
    }
    goto skip_5;
    // 0x806EB12C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_5:
    // 0x806EB130: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_806EB134:
    // 0x806EB134: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_806EB138:
    // 0x806EB138: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x806EB13C: beq         $at, $zero, L_806EB14C
    if (ctx->r1 == 0) {
        // 0x806EB140: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_806EB14C;
    }
    // 0x806EB140: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x806EB144: b           L_806EB180
    // 0x806EB148: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
        goto L_806EB180;
    // 0x806EB148: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_806EB14C:
    // 0x806EB14C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x806EB150: jal         0x806EAA74
    // 0x806EB154: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_806EAA74(rdram, ctx);
        goto after_2;
    // 0x806EB154: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x806EB158: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806EB15C: bne         $v0, $zero, L_806EB180
    if (ctx->r2 != 0) {
        // 0x806EB160: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_806EB180;
    }
    // 0x806EB160: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x806EB164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EB168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EB16C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806EB170: jal         0x806EB43C
    // 0x806EB174: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
    func_806EB43C(rdram, ctx);
        goto after_3;
    // 0x806EB174: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
    after_3:
    // 0x806EB178: b           L_806EB254
    // 0x806EB17C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EB254;
    // 0x806EB17C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EB180:
    // 0x806EB180: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
    // 0x806EB184: bnel        $a3, $zero, L_806EB1F4
    if (ctx->r7 != 0) {
        // 0x806EB188: lwc1        $f4, 0x84($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
            goto L_806EB1F4;
    }
    goto skip_6;
    // 0x806EB188: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    skip_6:
    // 0x806EB18C: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806EB190: lwc1        $f10, 0x84($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X84);
    // 0x806EB194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EB198: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x806EB19C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806EB1A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EB1A4: bc1fl       L_806EB1C0
    if (!c1cs) {
        // 0x806EB1A8: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806EB1C0;
    }
    goto skip_7;
    // 0x806EB1A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_7:
    // 0x806EB1AC: jal         0x806EB43C
    // 0x806EB1B0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_806EB43C(rdram, ctx);
        goto after_4;
    // 0x806EB1B0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_4:
    // 0x806EB1B4: b           L_806EB254
    // 0x806EB1B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EB254;
    // 0x806EB1B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EB1BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806EB1C0:
    // 0x806EB1C0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806EB1C4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(670, 0XF78) << 16);
    // 0x806EB1C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806EB1CC: nop

    // 0x806EB1D0: bc1f        L_806EB1E8
    if (!c1cs) {
        // 0x806EB1D4: nop
    
            goto L_806EB1E8;
    }
    // 0x806EB1D4: nop

    // 0x806EB1D8: lwc1        $f16, -0x48B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(670, 0XF78));
    // 0x806EB1DC: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x806EB1E0: b           L_806EB250
    // 0x806EB1E4: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
        goto L_806EB250;
    // 0x806EB1E4: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_806EB1E8:
    // 0x806EB1E8: b           L_806EB250
    // 0x806EB1EC: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
        goto L_806EB250;
    // 0x806EB1EC: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x806EB1F0: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
L_806EB1F4:
    // 0x806EB1F4: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806EB1F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EB1FC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806EB200: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806EB204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EB208: bc1fl       L_806EB224
    if (!c1cs) {
        // 0x806EB20C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806EB224;
    }
    goto skip_8;
    // 0x806EB20C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_8:
    // 0x806EB210: jal         0x806EB43C
    // 0x806EB214: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_806EB43C(rdram, ctx);
        goto after_5;
    // 0x806EB214: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_5:
    // 0x806EB218: b           L_806EB254
    // 0x806EB21C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EB254;
    // 0x806EB21C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EB220: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806EB224:
    // 0x806EB224: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806EB228: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(670, 0XF7C) << 16);
    // 0x806EB22C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806EB230: nop

    // 0x806EB234: bc1fl       L_806EB250
    if (!c1cs) {
        // 0x806EB238: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_806EB250;
    }
    goto skip_9;
    // 0x806EB238: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_9:
    // 0x806EB23C: lwc1        $f8, -0x48B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(670, 0XF7C));
    // 0x806EB240: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x806EB244: b           L_806EB250
    // 0x806EB248: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
        goto L_806EB250;
    // 0x806EB248: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x806EB24C: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_806EB250:
    // 0x806EB250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EB254:
    // 0x806EB254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EB258: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806EB25C: jr          $ra
    // 0x806EB260: nop

    return;
    // 0x806EB260: nop

;}
RECOMP_FUNC void func_806EF1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF1E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EF1E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EF1EC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806EF1F0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806EF1F4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806EF1F8: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(676, 0X49E4) << 16);
    // 0x806EF1FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806EF200: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806EF204: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806EF208: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806EF20C: lw          $t8, 0x934($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(676, 0X49E4));
    // 0x806EF210: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806EF214: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806EF218: jal         0x80048490
    // 0x806EF21C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806EF21C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806EF220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EF224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EF228: jr          $ra
    // 0x806EF22C: nop

    return;
    // 0x806EF22C: nop

;}
RECOMP_FUNC void func_80426B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80426B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80426B44: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80426B48: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80426B4C: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(38, 0X11E8) << 16);
    // 0x80426B50: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80426B54: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80426B58: lw          $t8, 0x77E8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(38, 0X11E8));
    // 0x80426B5C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80426B60: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80426B64: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80426B68: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80426B6C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80426B70: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80426B74: beql        $v1, $zero, L_80426BA8
    if (ctx->r3 == 0) {
        // 0x80426B78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80426BA8;
    }
    goto skip_0;
    // 0x80426B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80426B7C: jalr        $v1
    // 0x80426B80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80426B80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80426B84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80426B88: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80426B8C: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80426B90: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80426B94: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80426B98: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80426B9C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80426BA0: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80426BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80426BA8:
    // 0x80426BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80426BAC: jr          $ra
    // 0x80426BB0: nop

    return;
    // 0x80426BB0: nop

;}
RECOMP_FUNC void func_807153E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807153E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807153E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807153E8: jal         0x80714DD4
    // 0x807153EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80714DD4(rdram, ctx);
        goto after_0;
    // 0x807153EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807153F0: jal         0x80714E64
    // 0x807153F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80714E64(rdram, ctx);
        goto after_1;
    // 0x807153F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807153F8: jal         0x80714B7C
    // 0x807153FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80714B7C(rdram, ctx);
        goto after_2;
    // 0x807153FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80715400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80715404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715408: jr          $ra
    // 0x8071540C: nop

    return;
    // 0x8071540C: nop

;}
RECOMP_FUNC void func_807A1AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A1AB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A1AB8: jal         0x807A1A24
    // 0x807A1ABC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A1A24(rdram, ctx);
        goto after_0;
    // 0x807A1ABC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A1AC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A1AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A1AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807A1ACC: jal         0x807A1AE4
    // 0x807A1AD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807A1AE4(rdram, ctx);
        goto after_1;
    // 0x807A1AD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807A1AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A1AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A1ADC: jr          $ra
    // 0x807A1AE0: nop

    return;
    // 0x807A1AE0: nop

;}
RECOMP_FUNC void func_80522AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522AA4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80522AA8: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(321, 0X698) << 16);
    // 0x80522AAC: addiu       $t6, $t6, 0x2948
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(321, 0X698));
    // 0x80522AB0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80522AB4: jr          $ra
    // 0x80522AB8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80522AB8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_800262D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800262D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800262DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800262E0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x800262E4: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x800262E8: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x800262EC: beq         $t8, $zero, L_8002637C
    if (ctx->r24 == 0) {
        // 0x800262F0: nop
    
            goto L_8002637C;
    }
    // 0x800262F0: nop

    // 0x800262F4: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x800262F8: jal         0x80065954
    // 0x800262FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x800262FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80026300: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80026304: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80026308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002630C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80026310: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80026314: nop

    // 0x80026318: bc1f        L_8002637C
    if (!c1cs) {
        // 0x8002631C: nop
    
            goto L_8002637C;
    }
    // 0x8002631C: nop

    // 0x80026320: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80026324: lwc1        $f6, -0x26C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X26C);
    // 0x80026328: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002632C: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x80026330: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80026334: nop

    // 0x80026338: bc1t        L_80026374
    if (c1cs) {
        // 0x8002633C: nop
    
            goto L_80026374;
    }
    // 0x8002633C: nop

    // 0x80026340: lwc1        $f8, -0x268($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X268);
    // 0x80026344: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80026348: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x8002634C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80026350: nop

    // 0x80026354: bc1t        L_80026374
    if (c1cs) {
        // 0x80026358: nop
    
            goto L_80026374;
    }
    // 0x80026358: nop

    // 0x8002635C: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x80026360: sb          $v0, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r2;
    // 0x80026364: addiu       $t0, $t0, 0x4748
    ctx->r8 = ADD32(ctx->r8, 0X4748);
    // 0x80026368: sw          $v0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r2;
    // 0x8002636C: b           L_80026384
    // 0x80026370: sw          $t0, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r8;
        goto L_80026384;
    // 0x80026370: sw          $t0, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r8;
L_80026374:
    // 0x80026374: b           L_80026384
    // 0x80026378: sw          $t1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r9;
        goto L_80026384;
    // 0x80026378: sw          $t1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r9;
L_8002637C:
    // 0x8002637C: jal         0x80048690
    // 0x80026380: nop

    func_80048690(rdram, ctx);
        goto after_1;
    // 0x80026380: nop

    after_1:
L_80026384:
    // 0x80026384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002638C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026390: jr          $ra
    // 0x80026394: nop

    return;
    // 0x80026394: nop

;}
RECOMP_FUNC void func_806F37F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F37F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F37FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F3800: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x806F3804: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x806F3808: bne         $t7, $zero, L_806F3818
    if (ctx->r15 != 0) {
        // 0x806F380C: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_806F3818;
    }
    // 0x806F380C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x806F3810: jal         0x806F37A8
    // 0x806F3814: nop

    func_806F37A8(rdram, ctx);
        goto after_0;
    // 0x806F3814: nop

    after_0:
L_806F3818:
    // 0x806F3818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F381C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F3820: jr          $ra
    // 0x806F3824: nop

    return;
    // 0x806F3824: nop

;}
RECOMP_FUNC void func_80046118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046118: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8004611C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80046120: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80046124: bne         $a0, $at, L_80046134
    if (ctx->r4 != ctx->r1) {
        // 0x80046128: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80046134;
    }
    // 0x80046128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004612C: jr          $ra
    // 0x80046130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80046130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046134:
    // 0x80046134: jr          $ra
    // 0x80046138: nop

    return;
    // 0x80046138: nop

;}
RECOMP_FUNC void func_800190FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800190FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019104: jal         0x80019AC4
    // 0x80019108: nop

    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x80019108: nop

    after_0:
    // 0x8001910C: beq         $v0, $zero, L_80019118
    if (ctx->r2 == 0) {
        // 0x80019110: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_80019118;
    }
    // 0x80019110: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80019114: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80019118:
    // 0x80019118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001911C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019120: jr          $ra
    // 0x80019124: nop

    return;
    // 0x80019124: nop

;}
RECOMP_FUNC void func_804C8F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C8F9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C8FA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C8FA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C8FA8: jal         0x804C8EFC
    // 0x804C8FAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804C8EFC(rdram, ctx);
        goto after_0;
    // 0x804C8FAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804C8FB0: beql        $v0, $zero, L_804C909C
    if (ctx->r2 == 0) {
        // 0x804C8FB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804C909C;
    }
    goto skip_0;
    // 0x804C8FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804C8FB8: jal         0x804C8DC0
    // 0x804C8FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C8DC0(rdram, ctx);
        goto after_1;
    // 0x804C8FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804C8FC0: jal         0x804C8D14
    // 0x804C8FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C8D14(rdram, ctx);
        goto after_2;
    // 0x804C8FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804C8FC8: bne         $v0, $zero, L_804C8FE0
    if (ctx->r2 != 0) {
        // 0x804C8FCC: nop
    
            goto L_804C8FE0;
    }
    // 0x804C8FCC: nop

    // 0x804C8FD0: jal         0x804C8E98
    // 0x804C8FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C8E98(rdram, ctx);
        goto after_3;
    // 0x804C8FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804C8FD8: b           L_804C909C
    // 0x804C8FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804C909C;
    // 0x804C8FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C8FE0:
    // 0x804C8FE0: jal         0x8004700C
    // 0x804C8FE4: nop

    func_8004700C(rdram, ctx);
        goto after_4;
    // 0x804C8FE4: nop

    after_4:
    // 0x804C8FE8: beq         $v0, $zero, L_804C9088
    if (ctx->r2 == 0) {
        // 0x804C8FEC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804C9088;
    }
    // 0x804C8FEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804C8FF0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804C8FF4: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804C8FF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C8FFC: addiu       $v1, $v0, 0x3C
    ctx->r3 = ADD32(ctx->r2, 0X3C);
    // 0x804C9000: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x804C9004: nop

    // 0x804C9008: bc1fl       L_804C9030
    if (!c1cs) {
        // 0x804C900C: lwc1        $f0, 0x0($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
            goto L_804C9030;
    }
    goto skip_1;
    // 0x804C900C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x804C9010: addiu       $v1, $v0, 0x3C
    ctx->r3 = ADD32(ctx->r2, 0X3C);
    // 0x804C9014: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804C9018: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804C901C: nop

    // 0x804C9020: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804C9024: b           L_804C9054
    // 0x804C9028: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
        goto L_804C9054;
    // 0x804C9028: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x804C902C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
L_804C9030:
    // 0x804C9030: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C9034: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804C9038: nop

    // 0x804C903C: bc1fl       L_804C9058
    if (!c1cs) {
        // 0x804C9040: addiu       $v0, $a0, 0x3C
        ctx->r2 = ADD32(ctx->r4, 0X3C);
            goto L_804C9058;
    }
    goto skip_2;
    // 0x804C9040: addiu       $v0, $a0, 0x3C
    ctx->r2 = ADD32(ctx->r4, 0X3C);
    skip_2:
    // 0x804C9044: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804C9048: nop

    // 0x804C904C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x804C9050: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_804C9054:
    // 0x804C9054: addiu       $v0, $a0, 0x3C
    ctx->r2 = ADD32(ctx->r4, 0X3C);
L_804C9058:
    // 0x804C9058: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804C905C: jal         0x80065954
    // 0x804C9060: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x804C9060: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_5:
    // 0x804C9064: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C9068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804C906C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804C9070: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804C9074: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x804C9078: nop

    // 0x804C907C: bc1f        L_804C9088
    if (!c1cs) {
        // 0x804C9080: nop
    
            goto L_804C9088;
    }
    // 0x804C9080: nop

    // 0x804C9084: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_804C9088:
    // 0x804C9088: jal         0x804C8AA8
    // 0x804C908C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C8AA8(rdram, ctx);
        goto after_6;
    // 0x804C908C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804C9090: jal         0x804C8950
    // 0x804C9094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C8950(rdram, ctx);
        goto after_7;
    // 0x804C9094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x804C9098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C909C:
    // 0x804C909C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C90A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804C90A4: jr          $ra
    // 0x804C90A8: nop

    return;
    // 0x804C90A8: nop

;}
RECOMP_FUNC void func_8040C778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040C77C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C780: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8040C784: beql        $a1, $zero, L_8040C798
    if (ctx->r5 == 0) {
        // 0x8040C788: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040C798;
    }
    goto skip_0;
    // 0x8040C788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040C78C: jal         0x800568E0
    // 0x8040C790: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800568E0(rdram, ctx);
        goto after_0;
    // 0x8040C790: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8040C794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C798:
    // 0x8040C798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040C79C: jr          $ra
    // 0x8040C7A0: nop

    return;
    // 0x8040C7A0: nop

;}
RECOMP_FUNC void func_80029148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002914C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80029154: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80029158: jal         0x80028D3C
    // 0x8002915C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80028D3C(rdram, ctx);
        goto after_0;
    // 0x8002915C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x80029160: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80029164: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80029168: jal         0x80028DB4
    // 0x8002916C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80028DB4(rdram, ctx);
        goto after_1;
    // 0x8002916C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x80029170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029178: jr          $ra
    // 0x8002917C: nop

    return;
    // 0x8002917C: nop

;}
RECOMP_FUNC void func_800255E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800255E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800255E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800255EC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800255F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800255F4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800255F8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800255FC: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x80025600: jal         0x80024680
    // 0x80025604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x80025604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80025608: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002560C: bne         $v0, $at, L_80025620
    if (ctx->r2 != ctx->r1) {
        // 0x80025610: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80025620;
    }
    // 0x80025610: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80025614: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80025618: addiu       $t6, $t6, 0x5578
    ctx->r14 = ADD32(ctx->r14, 0X5578);
    // 0x8002561C: sw          $t6, 0x160($a1)
    MEM_W(0X160, ctx->r5) = ctx->r14;
L_80025620:
    // 0x80025620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80025624: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80025628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002562C: jr          $ra
    // 0x80025630: nop

    return;
    // 0x80025630: nop

;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090370: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x80090374: mflo        $v0
    ctx->r2 = lo;
    // 0x80090378: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8009037C: bne         $a2, $zero, L_80090388
    if (ctx->r6 != 0) {
        // 0x80090380: nop
    
            goto L_80090388;
    }
    // 0x80090380: nop

    // 0x80090384: break       7
    do_break(2148074372);
L_80090388:
    // 0x80090388: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009038C: bne         $a2, $at, L_800903A0
    if (ctx->r6 != ctx->r1) {
        // 0x80090390: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800903A0;
    }
    // 0x80090390: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80090394: bne         $a1, $at, L_800903A0
    if (ctx->r5 != ctx->r1) {
        // 0x80090398: nop
    
            goto L_800903A0;
    }
    // 0x80090398: nop

    // 0x8009039C: break       6
    do_break(2148074396);
L_800903A0:
    // 0x800903A0: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800903A4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800903A8: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x800903AC: mflo        $t6
    ctx->r14 = lo;
    // 0x800903B0: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x800903B4: bgez        $v0, L_800903D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800903B8: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800903D8;
    }
    // 0x800903B8: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800903BC: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800903C0: blez        $v1, L_800903D8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800903C4: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800903D8;
    }
    // 0x800903C4: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800903C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800903CC: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800903D0: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800903D4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_800903D8:
    // 0x800903D8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800903DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800903E0: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x800903E4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800903E8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800903EC: jr          $ra
    // 0x800903F0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x800903F0: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void func_8044AFC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AFC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044AFC8: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X134F4) << 16);
    // 0x8044AFCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AFD0: addiu       $t6, $t6, 0x78D4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X134F4));
    // 0x8044AFD4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044AFD8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044AFDC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044AFE0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044AFE4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044AFE8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044AFEC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044AFF0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044AFF4: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044AFF8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044AFFC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044B000: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044B004: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B008: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044B00C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044B010: jal         0x80050A50
    // 0x8044B014: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044B014: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044B018: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044B01C: jalr        $v0
    // 0x8044B020: sw          $v0, 0x6A68($v1)
    MEM_W(0X6A68, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044B020: sw          $v0, 0x6A68($v1)
    MEM_W(0X6A68, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044B024: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B028: sw          $v0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r2;
    // 0x8044B02C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B030: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044B034: jr          $ra
    // 0x8044B038: nop

    return;
    // 0x8044B038: nop

;}
RECOMP_FUNC void func_8007FEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FEC0: jr          $ra
    // 0x8007FEC4: nop

    return;
    // 0x8007FEC4: nop

;}
RECOMP_FUNC void func_80565C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80565C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80565C2C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80565C30: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80565C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80565C38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80565C3C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80565C40: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80565C44: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80565C48: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80565C4C: lui         $t1, 0x8056
    ctx->r9 = S32(RELOC_HI16(369, 0X2538) << 16);
    // 0x80565C50: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80565C54: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80565C58: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80565C5C: lw          $t1, 0x5D98($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(369, 0X2538));
    // 0x80565C60: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80565C64: jal         0x80048378
    // 0x80565C68: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80565C68: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    after_0:
    // 0x80565C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80565C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80565C74: jr          $ra
    // 0x80565C78: nop

    return;
    // 0x80565C78: nop

    // 0x80565C7C: nop

;}
RECOMP_FUNC void func_800413C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800413C8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800413CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800413D0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x800413D4: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x800413D8: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800413DC: addiu       $t6, $t6, -0x6E80
    ctx->r14 = ADD32(ctx->r14, -0X6E80);
    // 0x800413E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800413E4: bc1fl       L_800413F8
    if (!c1cs) {
        // 0x800413E8: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800413F8;
    }
    goto skip_0;
    // 0x800413E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x800413EC: jr          $ra
    // 0x800413F0: sw          $zero, 0x12D0($a0)
    MEM_W(0X12D0, ctx->r4) = 0;
    return;
    // 0x800413F0: sw          $zero, 0x12D0($a0)
    MEM_W(0X12D0, ctx->r4) = 0;
    // 0x800413F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800413F8:
    // 0x800413F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800413FC: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80041400: nop

    // 0x80041404: bc1f        L_8004141C
    if (!c1cs) {
        // 0x80041408: nop
    
            goto L_8004141C;
    }
    // 0x80041408: nop

    // 0x8004140C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80041410: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80041414: b           L_80041434
    // 0x80041418: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
        goto L_80041434;
    // 0x80041418: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_8004141C:
    // 0x8004141C: lwc1        $f8, 0x2F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2F4);
    // 0x80041420: lui         $at, 0xC188
    ctx->r1 = S32(0XC188 << 16);
    // 0x80041424: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80041428: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8004142C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80041430: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_80041434:
    // 0x80041434: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80041438: sw          $t6, 0x12D0($a0)
    MEM_W(0X12D0, ctx->r4) = ctx->r14;
    // 0x8004143C: swc1        $f12, 0x12D8($a0)
    MEM_W(0X12D8, ctx->r4) = ctx->f12.u32l;
    // 0x80041440: sw          $t7, 0x12E0($a0)
    MEM_W(0X12E0, ctx->r4) = ctx->r15;
    // 0x80041444: swc1        $f18, 0x12DC($a0)
    MEM_W(0X12DC, ctx->r4) = ctx->f18.u32l;
    // 0x80041448: jr          $ra
    // 0x8004144C: nop

    return;
    // 0x8004144C: nop

;}
RECOMP_FUNC void func_805A4600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A4600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A4604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A4608: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805A460C: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(414, 0X1D40) << 16);
    // 0x805A4610: addiu       $t6, $t6, 0x50D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(414, 0X1D40));
    // 0x805A4614: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805A4618: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805A461C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805A4620: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A4624: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A4628: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x805A462C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A4630: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A4634: jal         0x805A4678
    // 0x805A4638: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805A4678(rdram, ctx);
        goto after_0;
    // 0x805A4638: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x805A463C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A4640: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(414, 0XA70) << 16);
    // 0x805A4644: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(414, 0XA70));
    // 0x805A4648: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x805A464C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805A4650: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x805A4654: jal         0x80045A34
    // 0x805A4658: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x805A4658: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_1:
    // 0x805A465C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A4660: jal         0x805A431C
    // 0x805A4664: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    func_805A431C(rdram, ctx);
        goto after_2;
    // 0x805A4664: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    after_2:
    // 0x805A4668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A466C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A4670: jr          $ra
    // 0x805A4674: nop

    return;
    // 0x805A4674: nop

;}
RECOMP_FUNC void func_80580920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580924: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80580928: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8058092C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80580930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580934: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80580938: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8058093C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80580940: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80580944: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80580948: lui         $t2, 0x8058
    ctx->r10 = S32(RELOC_HI16(399, 0X45B0) << 16);
    // 0x8058094C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80580950: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80580954: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80580958: lw          $t2, 0x33C0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(399, 0X45B0));
    // 0x8058095C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80580960: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80580964: jal         0x80580794
    // 0x80580968: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580794(rdram, ctx);
        goto after_0;
    // 0x80580968: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8058096C: jal         0x805807F0
    // 0x80580970: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805807F0(rdram, ctx);
        goto after_1;
    // 0x80580970: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80580974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8058097C: jr          $ra
    // 0x80580980: nop

    return;
    // 0x80580980: nop

;}
RECOMP_FUNC void func_806735BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806735BC: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x806735C0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806735C4: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x806735C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806735CC: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x806735D0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x806735D4: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x806735D8: bnel        $at, $zero, L_80673618
    if (ctx->r1 != 0) {
        // 0x806735DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80673618;
    }
    goto skip_0;
    // 0x806735DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806735E0: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x806735E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x806735E8: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x806735EC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806735F0: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x806735F4: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x806735F8: beql        $t1, $t2, L_8067360C
    if (ctx->r9 == ctx->r10) {
        // 0x806735FC: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8067360C;
    }
    goto skip_1;
    // 0x806735FC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_1:
    // 0x80673600: b           L_80673614
    // 0x80673604: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_80673614;
    // 0x80673604: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80673608: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8067360C:
    // 0x8067360C: jr          $ra
    // 0x80673610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80673610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80673614:
    // 0x80673614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80673618:
    // 0x80673618: jr          $ra
    // 0x8067361C: nop

    return;
    // 0x8067361C: nop

;}
RECOMP_FUNC void func_80437A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437A1C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80437A20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80437A24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80437A28: jal         0x8004700C
    // 0x80437A2C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80437A2C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    after_0:
    // 0x80437A30: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80437A34: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80437A38: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80437A3C: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x80437A40: addiu       $a1, $v0, 0x84
    ctx->r5 = ADD32(ctx->r2, 0X84);
    // 0x80437A44: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80437A48: beq         $v0, $zero, L_80437B60
    if (ctx->r2 == 0) {
        // 0x80437A4C: swc1        $f4, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
            goto L_80437B60;
    }
    // 0x80437A4C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80437A50: jal         0x80065490
    // 0x80437A54: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x80437A54: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_1:
    // 0x80437A58: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80437A5C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80437A60: jal         0x80065490
    // 0x80437A64: addiu       $a1, $a1, 0x84
    ctx->r5 = ADD32(ctx->r5, 0X84);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x80437A64: addiu       $a1, $a1, 0x84
    ctx->r5 = ADD32(ctx->r5, 0X84);
    after_2:
    // 0x80437A68: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80437A6C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80437A70: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80437A74: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80437A78: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80437A7C: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80437A80: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80437A84: sub.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x80437A88: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80437A8C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80437A90: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80437A94: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    // 0x80437A98: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x80437A9C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80437AA0: jal         0x80065490
    // 0x80437AA4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x80437AA4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80437AA8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80437AAC: jal         0x80047AB8
    // 0x80437AB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047AB8(rdram, ctx);
        goto after_4;
    // 0x80437AB0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80437AB4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80437AB8: jal         0x80047AB8
    // 0x80437ABC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_80047AB8(rdram, ctx);
        goto after_5;
    // 0x80437ABC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_5:
    // 0x80437AC0: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80437AC4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80437AC8: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80437ACC: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80437AD0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80437AD4: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80437AD8: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80437ADC: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
    // 0x80437AE0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80437AE4: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80437AE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80437AEC: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80437AF0: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80437AF4: bc1fl       L_80437B64
    if (!c1cs) {
        // 0x80437AF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80437B64;
    }
    goto skip_0;
    // 0x80437AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80437AFC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80437B00: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80437B04: bc1fl       L_80437B64
    if (!c1cs) {
        // 0x80437B08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80437B64;
    }
    goto skip_1;
    // 0x80437B08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80437B0C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80437B10: nop

    // 0x80437B14: bc1fl       L_80437B64
    if (!c1cs) {
        // 0x80437B18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80437B64;
    }
    goto skip_2;
    // 0x80437B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80437B1C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80437B20: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x80437B24: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80437B28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80437B2C: bc1fl       L_80437B64
    if (!c1cs) {
        // 0x80437B30: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80437B64;
    }
    goto skip_3;
    // 0x80437B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80437B34: jal         0x80437960
    // 0x80437B38: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_80437960(rdram, ctx);
        goto after_6;
    // 0x80437B38: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x80437B3C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80437B40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80437B44: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x80437B48: bnel        $t8, $at, L_80437B64
    if (ctx->r24 != ctx->r1) {
        // 0x80437B4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80437B64;
    }
    goto skip_4;
    // 0x80437B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80437B50: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80437B54: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x80437B58: ori         $t0, $t9, 0x700
    ctx->r8 = ctx->r25 | 0X700;
    // 0x80437B5C: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
L_80437B60:
    // 0x80437B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80437B64:
    // 0x80437B64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80437B68: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80437B6C: jr          $ra
    // 0x80437B70: nop

    return;
    // 0x80437B70: nop

;}
RECOMP_FUNC void func_8046C478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046C47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046C480: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8046C484: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(143, 0X1010) << 16);
    // 0x8046C488: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8046C48C: addiu       $t6, $t6, -0x2BA0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(143, 0X1010));
    // 0x8046C490: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8046C494: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8046C498: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8046C49C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8046C4A0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8046C4A4: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x8046C4A8: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x8046C4AC: jal         0x8046C460
    // 0x8046C4B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8046C460(rdram, ctx);
        goto after_0;
    // 0x8046C4B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046C4B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046C4B8: lui         $t0, 0x8047
    ctx->r8 = S32(RELOC_HI16(143, 0X2A0) << 16);
    // 0x8046C4BC: addiu       $t0, $t0, -0x3910
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(143, 0X2A0));
    // 0x8046C4C0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8046C4C4: jal         0x80045A34
    // 0x8046C4C8: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8046C4C8: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    after_1:
    // 0x8046C4CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046C4D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046C4D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8046C4D8: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8046C4DC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8046C4E0: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046C4E4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8046C4E8: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046C4EC: jal         0x8046D3E8
    // 0x8046C4F0: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    func_8046D3E8(rdram, ctx);
        goto after_2;
    // 0x8046C4F0: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    after_2:
    // 0x8046C4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046C4F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8046C4FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8046C500: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
    // 0x8046C504: jr          $ra
    // 0x8046C508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8046C508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
