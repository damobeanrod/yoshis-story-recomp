#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8059FAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059FAA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8059FAA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059FAA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8059FAAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8059FAB0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8059FAB4: jal         0x80067BBC
    // 0x8059FAB8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8059FAB8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8059FABC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8059FAC0: jal         0x80067818
    // 0x8059FAC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8059FAC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8059FAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8059FACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8059FAD0: jr          $ra
    // 0x8059FAD4: nop

    return;
    // 0x8059FAD4: nop

;}
RECOMP_FUNC void func_8005EFE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EFE0: jr          $ra
    // 0x8005EFE4: sw          $zero, 0x19C($a0)
    MEM_W(0X19C, ctx->r4) = 0;
    return;
    // 0x8005EFE4: sw          $zero, 0x19C($a0)
    MEM_W(0X19C, ctx->r4) = 0;
;}
RECOMP_FUNC void func_807AB278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AB278: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807AB27C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807AB280: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807AB284: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807AB288: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807AB28C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807AB290: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807AB294: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807AB298: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x807AB29C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807AB2A0: lui         $t1, 0x807B
    ctx->r9 = S32(RELOC_HI16(853, 0X1BC0) << 16);
    // 0x807AB2A4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807AB2A8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807AB2AC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807AB2B0: lw          $t1, -0x4800($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(853, 0X1BC0));
    // 0x807AB2B4: jr          $ra
    // 0x807AB2B8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807AB2B8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8001FD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FD9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FDA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FDA4: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8001FDA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FDAC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001FDB0: bnel        $t6, $at, L_8001FDD8
    if (ctx->r14 != ctx->r1) {
        // 0x8001FDB4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FDD8;
    }
    goto skip_0;
    // 0x8001FDB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8001FDB8: lbu         $t7, 0xF4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF4);
    // 0x8001FDBC: bnel        $t7, $zero, L_8001FDD8
    if (ctx->r15 != 0) {
        // 0x8001FDC0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FDD8;
    }
    goto skip_1;
    // 0x8001FDC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8001FDC4: jal         0x8002DB78
    // 0x8001FDC8: nop

    func_8002DB78(rdram, ctx);
        goto after_0;
    // 0x8001FDC8: nop

    after_0:
    // 0x8001FDCC: b           L_8001FDD8
    // 0x8001FDD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001FDD8;
    // 0x8001FDD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001FDD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001FDD8:
    // 0x8001FDD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FDDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FDE0: jr          $ra
    // 0x8001FDE4: nop

    return;
    // 0x8001FDE4: nop

;}
RECOMP_FUNC void func_80460F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460F54: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80460F58: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80460F5C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80460F60: beq         $a1, $at, L_80460F84
    if (ctx->r5 == ctx->r1) {
        // 0x80460F64: addiu       $a0, $zero, 0x48
        ctx->r4 = ADD32(0, 0X48);
            goto L_80460F84;
    }
    // 0x80460F64: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80460F68: jal         0x80067930
    // 0x80460F6C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80460F6C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80460F70: beq         $v0, $zero, L_80460F84
    if (ctx->r2 == 0) {
        // 0x80460F74: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80460F84;
    }
    // 0x80460F74: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80460F78: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80460F7C: jal         0x80067878
    // 0x80460F80: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80460F80: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    after_1:
L_80460F84:
    // 0x80460F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460F88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460F8C: jr          $ra
    // 0x80460F90: nop

    return;
    // 0x80460F90: nop

;}
RECOMP_FUNC void func_806E7370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E7374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E7378: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x806E737C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806E7380: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806E7384: beq         $a1, $at, L_806E73C0
    if (ctx->r5 == ctx->r1) {
        // 0x806E7388: addiu       $a0, $zero, 0x4E
        ctx->r4 = ADD32(0, 0X4E);
            goto L_806E73C0;
    }
    // 0x806E7388: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x806E738C: jal         0x80067930
    // 0x806E7390: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x806E7390: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x806E7394: bne         $v0, $zero, L_806E73C0
    if (ctx->r2 != 0) {
        // 0x806E7398: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_806E73C0;
    }
    // 0x806E7398: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806E739C: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x806E73A0: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x806E73A4: jal         0x80067BBC
    // 0x806E73A8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x806E73A8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x806E73AC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806E73B0: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x806E73B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806E73B8: jal         0x80067838
    // 0x806E73BC: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_80067838(rdram, ctx);
        goto after_2;
    // 0x806E73BC: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_2:
L_806E73C0:
    // 0x806E73C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E73C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E73C8: jr          $ra
    // 0x806E73CC: nop

    return;
    // 0x806E73CC: nop

;}
RECOMP_FUNC void func_8077F910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077F910: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8077F914: slti        $at, $v0, 0x4411
    ctx->r1 = SIGNED(ctx->r2) < 0X4411 ? 1 : 0;
    // 0x8077F918: bne         $at, $zero, L_8077F938
    if (ctx->r1 != 0) {
        // 0x8077F91C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8077F938;
    }
    // 0x8077F91C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8077F920: slti        $at, $v1, 0x444E
    ctx->r1 = SIGNED(ctx->r3) < 0X444E ? 1 : 0;
    // 0x8077F924: beql        $at, $zero, L_8077F93C
    if (ctx->r1 == 0) {
        // 0x8077F928: slti        $at, $v1, 0x444E
        ctx->r1 = SIGNED(ctx->r3) < 0X444E ? 1 : 0;
            goto L_8077F93C;
    }
    goto skip_0;
    // 0x8077F928: slti        $at, $v1, 0x444E
    ctx->r1 = SIGNED(ctx->r3) < 0X444E ? 1 : 0;
    skip_0:
    // 0x8077F92C: lui         $v0, 0x8078
    ctx->r2 = S32(RELOC_HI16(781, 0X5FC) << 16);
    // 0x8077F930: jr          $ra
    // 0x8077F934: addiu       $v0, $v0, -0xF4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(781, 0X5FC));
    return;
    // 0x8077F934: addiu       $v0, $v0, -0xF4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(781, 0X5FC));
L_8077F938:
    // 0x8077F938: slti        $at, $v1, 0x444E
    ctx->r1 = SIGNED(ctx->r3) < 0X444E ? 1 : 0;
L_8077F93C:
    // 0x8077F93C: bne         $at, $zero, L_8077F958
    if (ctx->r1 != 0) {
        // 0x8077F940: slti        $at, $v1, 0x44CA
        ctx->r1 = SIGNED(ctx->r3) < 0X44CA ? 1 : 0;
            goto L_8077F958;
    }
    // 0x8077F940: slti        $at, $v1, 0x44CA
    ctx->r1 = SIGNED(ctx->r3) < 0X44CA ? 1 : 0;
    // 0x8077F944: beql        $at, $zero, L_8077F95C
    if (ctx->r1 == 0) {
        // 0x8077F948: addiu       $at, $zero, 0x46FD
        ctx->r1 = ADD32(0, 0X46FD);
            goto L_8077F95C;
    }
    goto skip_1;
    // 0x8077F948: addiu       $at, $zero, 0x46FD
    ctx->r1 = ADD32(0, 0X46FD);
    skip_1:
    // 0x8077F94C: lui         $v0, 0x8078
    ctx->r2 = S32(RELOC_HI16(781, 0X670) << 16);
    // 0x8077F950: jr          $ra
    // 0x8077F954: addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(781, 0X670));
    return;
    // 0x8077F954: addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(781, 0X670));
L_8077F958:
    // 0x8077F958: addiu       $at, $zero, 0x46FD
    ctx->r1 = ADD32(0, 0X46FD);
L_8077F95C:
    // 0x8077F95C: beq         $v1, $at, L_8077F96C
    if (ctx->r3 == ctx->r1) {
        // 0x8077F960: addiu       $at, $zero, 0x4734
        ctx->r1 = ADD32(0, 0X4734);
            goto L_8077F96C;
    }
    // 0x8077F960: addiu       $at, $zero, 0x4734
    ctx->r1 = ADD32(0, 0X4734);
    // 0x8077F964: bne         $v1, $at, L_8077F974
    if (ctx->r3 != ctx->r1) {
        // 0x8077F968: nop
    
            goto L_8077F974;
    }
    // 0x8077F968: nop

L_8077F96C:
    // 0x8077F96C: lui         $v0, 0x8078
    ctx->r2 = S32(RELOC_HI16(781, 0X738) << 16);
    // 0x8077F970: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(781, 0X738));
L_8077F974:
    // 0x8077F974: jr          $ra
    // 0x8077F978: nop

    return;
    // 0x8077F978: nop

;}
RECOMP_FUNC void func_806B1050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1050: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B1054: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806B1058: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806B105C: jal         0x8004700C
    // 0x806B1060: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806B1060: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806B1064: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806B1068: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x806B106C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    // 0x806B1070: jal         0x80065ABC
    // 0x806B1074: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x806B1074: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x806B1078: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806B107C: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806B1080: beql        $a3, $zero, L_806B10E4
    if (ctx->r7 == 0) {
        // 0x806B1084: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806B10E4;
    }
    goto skip_0;
    // 0x806B1084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806B1088: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806B108C: lwc1        $f6, 0x84($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X84);
    // 0x806B1090: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1094: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806B1098: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806B109C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806B10A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806B10A4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806B10A8: nop

    // 0x806B10AC: bc1fl       L_806B10E4
    if (!c1cs) {
        // 0x806B10B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806B10E4;
    }
    goto skip_1;
    // 0x806B10B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806B10B4: lw          $t6, 0x1F4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1F4);
    // 0x806B10B8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806B10BC: jal         0x80048114
    // 0x806B10C0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80048114(rdram, ctx);
        goto after_2;
    // 0x806B10C0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_2:
    // 0x806B10C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806B10C8: jal         0x806B1198
    // 0x806B10CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806B1198(rdram, ctx);
        goto after_3;
    // 0x806B10CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806B10D0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806B10D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806B10D8: sw          $s0, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->r16;
    // 0x806B10DC: sw          $t7, 0x104($v0)
    MEM_W(0X104, ctx->r2) = ctx->r15;
    // 0x806B10E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806B10E4:
    // 0x806B10E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806B10E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B10EC: jr          $ra
    // 0x806B10F0: nop

    return;
    // 0x806B10F0: nop

;}
RECOMP_FUNC void func_80065308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065308: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x8006530C: bne         $at, $zero, L_80065360
    if (ctx->r1 != 0) {
        // 0x80065310: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80065360;
    }
    // 0x80065310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80065314: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x80065318: andi        $a0, $a0, 0x3
    ctx->r4 = ctx->r4 & 0X3;
    // 0x8006531C: beq         $a0, $zero, L_8006533C
    if (ctx->r4 == 0) {
        // 0x80065320: addiu       $v1, $a0, 0x1
        ctx->r3 = ADD32(ctx->r4, 0X1);
            goto L_8006533C;
    }
    // 0x80065320: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
L_80065324:
    // 0x80065324: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80065328: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006532C: bne         $v1, $v0, L_80065324
    if (ctx->r3 != ctx->r2) {
        // 0x80065330: nop
    
            goto L_80065324;
    }
    // 0x80065330: nop

    // 0x80065334: beq         $v0, $a1, L_80065360
    if (ctx->r2 == ctx->r5) {
        // 0x80065338: nop
    
            goto L_80065360;
    }
    // 0x80065338: nop

L_8006533C:
    // 0x8006533C: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80065340: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80065344: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80065348: nop

    // 0x8006534C: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80065350: nop

    // 0x80065354: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80065358: bne         $v0, $a1, L_8006533C
    if (ctx->r2 != ctx->r5) {
        // 0x8006535C: nop
    
            goto L_8006533C;
    }
    // 0x8006535C: nop

L_80065360:
    // 0x80065360: jr          $ra
    // 0x80065364: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80065364: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void func_8044EFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044EFA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044EFA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044EFA8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8044EFAC: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044EFB0: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044EFB4: addu        $t7, $a2, $v1
    ctx->r15 = ADD32(ctx->r6, ctx->r3);
    // 0x8044EFB8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8044EFBC: lw          $t9, 0x6A20($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X6A20);
    // 0x8044EFC0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8044EFC4: lw          $t0, 0x6A24($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X6A24);
    // 0x8044EFC8: slti        $at, $t9, 0xC
    ctx->r1 = SIGNED(ctx->r25) < 0XC ? 1 : 0;
    // 0x8044EFCC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8044EFD0: lw          $t1, 0x6A28($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X6A28);
    // 0x8044EFD4: bltz        $t9, L_8044F038
    if (SIGNED(ctx->r25) < 0) {
        // 0x8044EFD8: sw          $t1, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r9;
            goto L_8044F038;
    }
    // 0x8044EFD8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8044EFDC: beq         $at, $zero, L_8044F038
    if (ctx->r1 == 0) {
        // 0x8044EFE0: sll         $v0, $t9, 2
        ctx->r2 = S32(ctx->r25 << 2);
            goto L_8044F038;
    }
    // 0x8044EFE0: sll         $v0, $t9, 2
    ctx->r2 = S32(ctx->r25 << 2);
    // 0x8044EFE4: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x8044EFE8: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8044EFEC: lw          $t4, 0x6A4C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X6A4C);
    // 0x8044EFF0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x8044EFF4: bnel        $t4, $zero, L_8044F03C
    if (ctx->r12 != 0) {
        // 0x8044EFF8: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_8044F03C;
    }
    goto skip_0;
    // 0x8044EFF8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8044EFFC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8044F000: jal         0x8044EF50
    // 0x8044F004: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_8044EF50(rdram, ctx);
        goto after_0;
    // 0x8044F004: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8044F008: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8044F00C: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X13174) << 16);
    // 0x8044F010: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8044F014: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044F018: lw          $v1, 0x7554($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X13174));
    // 0x8044F01C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044F020: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8044F024: beql        $v1, $zero, L_8044F03C
    if (ctx->r3 == 0) {
        // 0x8044F028: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_8044F03C;
    }
    goto skip_1;
    // 0x8044F028: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8044F02C: jalr        $v1
    // 0x8044F030: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x8044F030: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8044F034: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_8044F038:
    // 0x8044F038: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_8044F03C:
    // 0x8044F03C: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044F040: bltz        $t5, L_8044F0A8
    if (SIGNED(ctx->r13) < 0) {
        // 0x8044F044: slti        $at, $t5, 0xC
        ctx->r1 = SIGNED(ctx->r13) < 0XC ? 1 : 0;
            goto L_8044F0A8;
    }
    // 0x8044F044: slti        $at, $t5, 0xC
    ctx->r1 = SIGNED(ctx->r13) < 0XC ? 1 : 0;
    // 0x8044F048: beq         $at, $zero, L_8044F0A8
    if (ctx->r1 == 0) {
        // 0x8044F04C: sll         $v0, $t5, 2
        ctx->r2 = S32(ctx->r13 << 2);
            goto L_8044F0A8;
    }
    // 0x8044F04C: sll         $v0, $t5, 2
    ctx->r2 = S32(ctx->r13 << 2);
    // 0x8044F050: addu        $t7, $a2, $v0
    ctx->r15 = ADD32(ctx->r6, ctx->r2);
    // 0x8044F054: addu        $t0, $t7, $v1
    ctx->r8 = ADD32(ctx->r15, ctx->r3);
    // 0x8044F058: lw          $t8, 0x6A4C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X6A4C);
    // 0x8044F05C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044F060: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8044F064: bnel        $t8, $zero, L_8044F0AC
    if (ctx->r24 != 0) {
        // 0x8044F068: lw          $t1, 0x20($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X20);
            goto L_8044F0AC;
    }
    goto skip_2;
    // 0x8044F068: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x8044F06C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8044F070: jal         0x8044EF50
    // 0x8044F074: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_8044EF50(rdram, ctx);
        goto after_2;
    // 0x8044F074: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x8044F078: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8044F07C: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X13174) << 16);
    // 0x8044F080: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8044F084: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044F088: lw          $v1, 0x7554($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X13174));
    // 0x8044F08C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044F090: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8044F094: beql        $v1, $zero, L_8044F0AC
    if (ctx->r3 == 0) {
        // 0x8044F098: lw          $t1, 0x20($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X20);
            goto L_8044F0AC;
    }
    goto skip_3;
    // 0x8044F098: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    skip_3:
    // 0x8044F09C: jalr        $v1
    // 0x8044F0A0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_3;
    // 0x8044F0A0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_3:
    // 0x8044F0A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_8044F0A8:
    // 0x8044F0A8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
L_8044F0AC:
    // 0x8044F0AC: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044F0B0: bltz        $t1, L_8044F108
    if (SIGNED(ctx->r9) < 0) {
        // 0x8044F0B4: slti        $at, $t1, 0xC
        ctx->r1 = SIGNED(ctx->r9) < 0XC ? 1 : 0;
            goto L_8044F108;
    }
    // 0x8044F0B4: slti        $at, $t1, 0xC
    ctx->r1 = SIGNED(ctx->r9) < 0XC ? 1 : 0;
    // 0x8044F0B8: beq         $at, $zero, L_8044F108
    if (ctx->r1 == 0) {
        // 0x8044F0BC: sll         $v0, $t1, 2
        ctx->r2 = S32(ctx->r9 << 2);
            goto L_8044F108;
    }
    // 0x8044F0BC: sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9 << 2);
    // 0x8044F0C0: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x8044F0C4: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8044F0C8: lw          $t4, 0x6A4C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X6A4C);
    // 0x8044F0CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044F0D0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8044F0D4: bnel        $t4, $zero, L_8044F10C
    if (ctx->r12 != 0) {
        // 0x8044F0D8: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_8044F10C;
    }
    goto skip_4;
    // 0x8044F0D8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8044F0DC: jal         0x8044EF50
    // 0x8044F0E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8044EF50(rdram, ctx);
        goto after_4;
    // 0x8044F0E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_4:
    // 0x8044F0E4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8044F0E8: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X13174) << 16);
    // 0x8044F0EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044F0F0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044F0F4: lw          $v1, 0x7554($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X13174));
    // 0x8044F0F8: beql        $v1, $zero, L_8044F10C
    if (ctx->r3 == 0) {
        // 0x8044F0FC: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_8044F10C;
    }
    goto skip_5;
    // 0x8044F0FC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x8044F100: jalr        $v1
    // 0x8044F104: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_5;
    // 0x8044F104: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
L_8044F108:
    // 0x8044F108: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_8044F10C:
    // 0x8044F10C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8044F110: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8044F114: beq         $t6, $v0, L_8044F124
    if (ctx->r14 == ctx->r2) {
        // 0x8044F118: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8044F124;
    }
    // 0x8044F118: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8044F11C: bnel        $t9, $v0, L_8044F13C
    if (ctx->r25 != ctx->r2) {
        // 0x8044F120: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_8044F13C;
    }
    goto skip_6;
    // 0x8044F120: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    skip_6:
L_8044F124:
    // 0x8044F124: lw          $t0, 0x6A90($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X6A90);
    // 0x8044F128: bnel        $t0, $zero, L_8044F13C
    if (ctx->r8 != 0) {
        // 0x8044F12C: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_8044F13C;
    }
    goto skip_7;
    // 0x8044F12C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    skip_7:
    // 0x8044F130: jal         0x8044B604
    // 0x8044F134: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8044B604(rdram, ctx);
        goto after_6;
    // 0x8044F134: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x8044F138: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
L_8044F13C:
    // 0x8044F13C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8044F140: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8044F144: beq         $t8, $v0, L_8044F154
    if (ctx->r24 == ctx->r2) {
        // 0x8044F148: lw          $t2, 0x1C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X1C);
            goto L_8044F154;
    }
    // 0x8044F148: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8044F14C: bnel        $t5, $v0, L_8044F16C
    if (ctx->r13 != ctx->r2) {
        // 0x8044F150: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044F16C;
    }
    goto skip_8;
    // 0x8044F150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
L_8044F154:
    // 0x8044F154: lw          $t3, 0x6A8C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X6A8C);
    // 0x8044F158: bnel        $t3, $zero, L_8044F16C
    if (ctx->r11 != 0) {
        // 0x8044F15C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044F16C;
    }
    goto skip_9;
    // 0x8044F15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x8044F160: jal         0x8044B58C
    // 0x8044F164: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8044B58C(rdram, ctx);
        goto after_7;
    // 0x8044F164: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8044F168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044F16C:
    // 0x8044F16C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8044F170: jr          $ra
    // 0x8044F174: nop

    return;
    // 0x8044F174: nop

;}
RECOMP_FUNC void func_807812EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807812EC: jr          $ra
    // 0x807812F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807812F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8004DF58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DF58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004DF5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004DF60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8004DF64: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8004DF68: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8004DF6C: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x8004DF70: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004DF74: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004DF78: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004DF7C: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x8004DF80: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004DF84: beql        $v1, $zero, L_8004DFBC
    if (ctx->r3 == 0) {
        // 0x8004DF88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DFBC;
    }
    goto skip_0;
    // 0x8004DF88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004DF8C: beql        $v1, $at, L_8004DFBC
    if (ctx->r3 == ctx->r1) {
        // 0x8004DF90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DFBC;
    }
    goto skip_1;
    // 0x8004DF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004DF94: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8004DF98: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004DF9C: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x8004DFA0: beq         $v1, $at, L_8004DFB8
    if (ctx->r3 == ctx->r1) {
        // 0x8004DFA4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004DFB8;
    }
    // 0x8004DFA4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004DFA8: beq         $v1, $at, L_8004DFB8
    if (ctx->r3 == ctx->r1) {
        // 0x8004DFAC: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004DFB8;
    }
    // 0x8004DFAC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004DFB0: jal         0x8004CF88
    // 0x8004DFB4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8004CF88(rdram, ctx);
        goto after_0;
    // 0x8004DFB4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
L_8004DFB8:
    // 0x8004DFB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004DFBC:
    // 0x8004DFBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004DFC0: jr          $ra
    // 0x8004DFC4: nop

    return;
    // 0x8004DFC4: nop

;}
RECOMP_FUNC void func_805806B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805806B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805806B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805806BC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x805806C0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805806C4: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(399, 0X4528) << 16);
    // 0x805806C8: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805806CC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805806D0: addiu       $t7, $t7, 0x3338
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(399, 0X4528));
    // 0x805806D4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805806D8: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x805806DC: lui         $t9, 0x8058
    ctx->r25 = S32(RELOC_HI16(399, 0X4190) << 16);
    // 0x805806E0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805806E4: addiu       $t9, $t9, 0x2FA0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(399, 0X4190));
    // 0x805806E8: sw          $t9, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r25;
    // 0x805806EC: jal         0x80580614
    // 0x805806F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580614(rdram, ctx);
        goto after_0;
    // 0x805806F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805806F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805806F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805806FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80580700: jal         0x80580650
    // 0x80580704: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80580650(rdram, ctx);
        goto after_1;
    // 0x80580704: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80580708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8058070C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80580710: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80580714: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x80580718: jr          $ra
    // 0x8058071C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8058071C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80437440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80437444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437448: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8043744C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437450: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x80437454: lbu         $t7, 0xF4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XF4);
    // 0x80437458: bnel        $t7, $zero, L_80437498
    if (ctx->r15 != 0) {
        // 0x8043745C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80437498;
    }
    goto skip_0;
    // 0x8043745C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80437460: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80437464: andi        $t9, $t8, 0xF00
    ctx->r25 = ctx->r24 & 0XF00;
    // 0x80437468: bnel        $t9, $zero, L_80437498
    if (ctx->r25 != 0) {
        // 0x8043746C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80437498;
    }
    goto skip_1;
    // 0x8043746C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80437470: jal         0x80065954
    // 0x80437474: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80437474: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x80437478: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8043747C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80437480: nop

    // 0x80437484: bc1fl       L_80437498
    if (!c1cs) {
        // 0x80437488: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80437498;
    }
    goto skip_2;
    // 0x80437488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8043748C: b           L_80437498
    // 0x80437490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80437498;
    // 0x80437490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80437494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80437498:
    // 0x80437498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043749C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804374A0: jr          $ra
    // 0x804374A4: nop

    return;
    // 0x804374A4: nop

;}
RECOMP_FUNC void Math_FRoundF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081D08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081D10: jal         0x800820C0
    // 0x80081D14: nop

    roundf_recomp(rdram, ctx);
        goto after_0;
    // 0x80081D14: nop

    after_0:
    // 0x80081D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081D1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081D20: jr          $ra
    // 0x80081D24: nop

    return;
    // 0x80081D24: nop

;}
RECOMP_FUNC void func_80516EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516EB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80516EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80516EBC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80516EC0: lui         $t6, 0x8051
    ctx->r14 = S32(RELOC_HI16(282, 0X1E0) << 16);
    // 0x80516EC4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80516EC8: addiu       $t6, $t6, 0x7010
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(282, 0X1E0));
    // 0x80516ECC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80516ED0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80516ED4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80516ED8: jal         0x80516FB4
    // 0x80516EDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80516FB4(rdram, ctx);
        goto after_0;
    // 0x80516EDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80516EE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80516EE4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80516EE8: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x80516EEC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80516EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80516EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80516EF8: jr          $ra
    // 0x80516EFC: nop

    return;
    // 0x80516EFC: nop

;}
RECOMP_FUNC void func_806F3BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F3BB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F3BBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F3BC0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x806F3BC4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x806F3BC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F3BCC: lui         $a1, 0x4018
    ctx->r5 = S32(0X4018 << 16);
    // 0x806F3BD0: lui         $a0, 0x806F
    ctx->r4 = S32(RELOC_HI16(682, 0XB00) << 16);
    // 0x806F3BD4: lw          $a3, 0x88($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X88);
    // 0x806F3BD8: lw          $a2, 0x84($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X84);
    // 0x806F3BDC: addiu       $a0, $a0, 0x3F50
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(682, 0XB00));
    // 0x806F3BE0: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x806F3BE4: jal         0x80046804
    // 0x806F3BE8: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x806F3BE8: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x806F3BEC: bne         $v0, $zero, L_806F3BFC
    if (ctx->r2 != 0) {
        // 0x806F3BF0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_806F3BFC;
    }
    // 0x806F3BF0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806F3BF4: b           L_806F3C00
    // 0x806F3BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F3C00;
    // 0x806F3BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F3BFC:
    // 0x806F3BFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_806F3C00:
    // 0x806F3C00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F3C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F3C08: jr          $ra
    // 0x806F3C0C: nop

    return;
    // 0x806F3C0C: nop

;}
RECOMP_FUNC void func_807776F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807776F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807776FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80777700: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80777704: jal         0x80777668
    // 0x80777708: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80777668(rdram, ctx);
        goto after_0;
    // 0x80777708: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8077770C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80777710: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80777714: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80777718: jal         0x80777864
    // 0x8077771C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80777864(rdram, ctx);
        goto after_1;
    // 0x8077771C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80777720: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80777724: jal         0x80048378
    // 0x80777728: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048378(rdram, ctx);
        goto after_2;
    // 0x80777728: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8077772C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80777730: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80777734: jal         0x800653D8
    // 0x80777738: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x80777738: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    after_3:
    // 0x8077773C: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80777740: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80777744: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(775, 0X4C8) << 16);
    // 0x80777748: lwc1        $f10, 0x78D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(775, 0X4C8));
    // 0x8077774C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80777750: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80777754: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80777758: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8077775C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80777760: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80777764: jal         0x800653D8
    // 0x80777768: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x80777768: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    after_4:
    // 0x8077776C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x80777770: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80777774: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(775, 0X4CC) << 16);
    // 0x80777778: lwc1        $f10, 0x78DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(775, 0X4CC));
    // 0x8077777C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80777780: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(775, 0X4D0) << 16);
    // 0x80777784: lwc1        $f16, 0x78E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(775, 0X4D0));
    // 0x80777788: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8077778C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80777790: add.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80777794: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    // 0x80777798: swc1        $f0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f0.u32l;
    // 0x8077779C: jal         0x800653D8
    // 0x807777A0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x807777A0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_5:
    // 0x807777A4: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x807777A8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x807777AC: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(775, 0X4D4) << 16);
    // 0x807777B0: lwc1        $f8, 0x78E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(775, 0X4D4));
    // 0x807777B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807777B8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x807777BC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807777C0: jal         0x800653D8
    // 0x807777C4: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    func_800653D8(rdram, ctx);
        goto after_6;
    // 0x807777C4: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    after_6:
    // 0x807777C8: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x807777CC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x807777D0: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(775, 0X4D8) << 16);
    // 0x807777D4: lwc1        $f4, 0x78E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(775, 0X4D8));
    // 0x807777D8: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807777DC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x807777E0: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x807777E4: jal         0x800653D8
    // 0x807777E8: swc1        $f6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f6.u32l;
    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x807777E8: swc1        $f6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f6.u32l;
    after_7:
    // 0x807777EC: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x807777F0: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x807777F4: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(775, 0X4DC) << 16);
    // 0x807777F8: lwc1        $f18, 0x78EC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(775, 0X4DC));
    // 0x807777FC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80777800: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80777804: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80777808: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8077780C: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80777810: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80777814: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80777818: jal         0x800653D8
    // 0x8077781C: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    func_800653D8(rdram, ctx);
        goto after_8;
    // 0x8077781C: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x80777820: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x80777824: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80777828: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(775, 0X4E0) << 16);
    // 0x8077782C: lwc1        $f6, 0x78F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(775, 0X4E0));
    // 0x80777830: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80777834: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80777838: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8077783C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80777840: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80777844: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80777848: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8077784C: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x80777850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80777854: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80777858: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8077785C: jr          $ra
    // 0x80777860: nop

    return;
    // 0x80777860: nop

;}
RECOMP_FUNC void func_8073F0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F0F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073F0FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073F100: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8073F104: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8073F108: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8073F10C: jal         0x8073EE40
    // 0x8073F110: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8073EE40(rdram, ctx);
        goto after_0;
    // 0x8073F110: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8073F114: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x8073F118: jal         0x8073EED0
    // 0x8073F11C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073EED0(rdram, ctx);
        goto after_1;
    // 0x8073F11C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8073F120: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x8073F124: jal         0x8073EF60
    // 0x8073F128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073EF60(rdram, ctx);
        goto after_2;
    // 0x8073F128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8073F12C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8073F130: jal         0x8073EFE8
    // 0x8073F134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073EFE8(rdram, ctx);
        goto after_3;
    // 0x8073F134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8073F138: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8073F13C: jal         0x8073F070
    // 0x8073F140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F070(rdram, ctx);
        goto after_4;
    // 0x8073F140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8073F144: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x8073F148: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x8073F14C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073F150: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8073F154: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8073F158: beq         $v1, $zero, L_8073F1A0
    if (ctx->r3 == 0) {
        // 0x8073F15C: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_8073F1A0;
    }
    // 0x8073F15C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8073F160: lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X10);
    // 0x8073F164: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8073F168: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8073F16C: beql        $v1, $zero, L_8073F1A4
    if (ctx->r3 == 0) {
        // 0x8073F170: lw          $s1, 0x18($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X18);
            goto L_8073F1A4;
    }
    goto skip_0;
    // 0x8073F170: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8073F174: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8073F178: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8073F17C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8073F180: beql        $v1, $zero, L_8073F1A4
    if (ctx->r3 == 0) {
        // 0x8073F184: lw          $s1, 0x18($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X18);
            goto L_8073F1A4;
    }
    goto skip_1;
    // 0x8073F184: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x8073F188: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8073F18C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8073F190: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8073F194: beql        $v1, $zero, L_8073F1A4
    if (ctx->r3 == 0) {
        // 0x8073F198: lw          $s1, 0x18($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X18);
            goto L_8073F1A4;
    }
    goto skip_2;
    // 0x8073F198: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    skip_2:
    // 0x8073F19C: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
L_8073F1A0:
    // 0x8073F1A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
L_8073F1A4:
    // 0x8073F1A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073F1A8: jr          $ra
    // 0x8073F1AC: sltiu       $v0, $v1, 0x1
    ctx->r2 = ctx->r3 < 0X1 ? 1 : 0;
    return;
    // 0x8073F1AC: sltiu       $v0, $v1, 0x1
    ctx->r2 = ctx->r3 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80468FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80468FC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80468FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80468FD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80468FD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80468FD8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80468FDC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80468FE0: jal         0x80468830
    // 0x80468FE4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80468830(rdram, ctx);
        goto after_0;
    // 0x80468FE4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80468FE8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80468FEC: jal         0x8046895C
    // 0x80468FF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8046895C(rdram, ctx);
        goto after_1;
    // 0x80468FF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80468FF4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80468FF8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80468FFC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80469000: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80469004: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80469008: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8046900C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80469010: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80469014: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80469018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046901C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80469020: jr          $ra
    // 0x80469024: nop

    return;
    // 0x80469024: nop

;}
RECOMP_FUNC void func_805CF0B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CF0B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CF0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CF0B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805CF0BC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805CF0C0: jal         0x80048F84
    // 0x805CF0C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x805CF0C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x805CF0C8: beq         $v0, $zero, L_805CF0D8
    if (ctx->r2 == 0) {
        // 0x805CF0CC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805CF0D8;
    }
    // 0x805CF0CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805CF0D0: jal         0x805CF180
    // 0x805CF0D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_805CF180(rdram, ctx);
        goto after_1;
    // 0x805CF0D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_805CF0D8:
    // 0x805CF0D8: jal         0x805CF068
    // 0x805CF0DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805CF068(rdram, ctx);
        goto after_2;
    // 0x805CF0DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x805CF0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CF0E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805CF0E8: jr          $ra
    // 0x805CF0EC: nop

    return;
    // 0x805CF0EC: nop

;}
RECOMP_FUNC void func_80742404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742404: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80742408: lui         $at, 0x8076
    ctx->r1 = S32(RELOC_HI16(754, 0X1C370) << 16);
    // 0x8074240C: lwc1        $f0, -0x1A50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(754, 0X1C370));
    // 0x80742410: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80742414: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80742418: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8074241C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80742420: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80742424: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80742428: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x8074242C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80742430: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80742434: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x80742438: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8074243C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80742440: jal         0x8074224C
    // 0x80742444: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8074224C(rdram, ctx);
        goto after_0;
    // 0x80742444: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80742448: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8074244C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80742450: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80742454: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80742458: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8074245C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80742460: jr          $ra
    // 0x80742464: nop

    return;
    // 0x80742464: nop

;}
RECOMP_FUNC void func_80038078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003807C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038080: jal         0x80038018
    // 0x80038084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80038018(rdram, ctx);
        goto after_0;
    // 0x80038084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038088: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003808C: jal         0x80065954
    // 0x80038090: lwc1        $f12, 0xC4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC4);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80038090: lwc1        $f12, 0xC4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC4);
    after_1:
    // 0x80038094: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80038098: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003809C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800380A0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800380A4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800380A8: jal         0x80041214
    // 0x800380AC: nop

    func_80041214(rdram, ctx);
        goto after_2;
    // 0x800380AC: nop

    after_2:
    // 0x800380B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800380B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800380B8: jr          $ra
    // 0x800380BC: nop

    return;
    // 0x800380BC: nop

;}
RECOMP_FUNC void func_80453724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045372C: jal         0x80453644
    // 0x80453730: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80453644(rdram, ctx);
        goto after_0;
    // 0x80453730: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80453734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045373C: jr          $ra
    // 0x80453740: nop

    return;
    // 0x80453740: nop

;}
RECOMP_FUNC void func_80681A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681A80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80681A84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80681A88: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80681A8C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80681A90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80681A94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80681A98: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80681A9C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80681AA0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80681AA4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80681AA8: bne         $v0, $at, L_80681BA4
    if (ctx->r2 != ctx->r1) {
        // 0x80681AAC: or          $s2, $a3, $zero
        ctx->r18 = ctx->r7 | 0;
            goto L_80681BA4;
    }
    // 0x80681AAC: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80681AB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80681AB4: jal         0x80062AEC
    // 0x80681AB8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x80681AB8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80681ABC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80681AC0: beq         $v0, $at, L_80681ADC
    if (ctx->r2 == ctx->r1) {
        // 0x80681AC4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80681ADC;
    }
    // 0x80681AC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80681AC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80681ACC: beq         $v0, $at, L_80681B44
    if (ctx->r2 == ctx->r1) {
        // 0x80681AD0: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80681B44;
    }
    // 0x80681AD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80681AD4: b           L_80681BA8
    // 0x80681AD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80681BA8;
    // 0x80681AD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80681ADC:
    // 0x80681ADC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80681AE0: jal         0x80681A20
    // 0x80681AE4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80681A20(rdram, ctx);
        goto after_1;
    // 0x80681AE4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80681AE8: beq         $v0, $zero, L_80681BA4
    if (ctx->r2 == 0) {
        // 0x80681AEC: lui         $at, 0x8068
        ctx->r1 = S32(RELOC_HI16(550, 0X2278) << 16);
            goto L_80681BA4;
    }
    // 0x80681AEC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2278) << 16);
    // 0x80681AF0: lwc1        $f4, 0x2688($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2278));
    // 0x80681AF4: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80681AF8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80681AFC: nop

    // 0x80681B00: bc1fl       L_80681B30
    if (!c1cs) {
        // 0x80681B04: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80681B30;
    }
    goto skip_0;
    // 0x80681B04: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x80681B08: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80681B0C: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80681B10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80681B14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80681B18: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80681B1C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80681B20: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80681B24: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80681B28: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x80681B2C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80681B30:
    // 0x80681B30: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80681B34: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x80681B38: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80681B3C: b           L_80681BA4
    // 0x80681B40: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
        goto L_80681BA4;
    // 0x80681B40: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
L_80681B44:
    // 0x80681B44: jal         0x80681A20
    // 0x80681B48: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80681A20(rdram, ctx);
        goto after_2;
    // 0x80681B48: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80681B4C: beq         $v0, $zero, L_80681BA4
    if (ctx->r2 == 0) {
        // 0x80681B50: lui         $at, 0x8068
        ctx->r1 = S32(RELOC_HI16(550, 0X227C) << 16);
            goto L_80681BA4;
    }
    // 0x80681B50: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X227C) << 16);
    // 0x80681B54: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80681B58: lwc1        $f16, 0x268C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X227C));
    // 0x80681B5C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80681B60: nop

    // 0x80681B64: bc1fl       L_80681B94
    if (!c1cs) {
        // 0x80681B68: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80681B94;
    }
    goto skip_1;
    // 0x80681B68: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x80681B6C: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80681B70: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80681B74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80681B78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80681B7C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80681B80: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80681B84: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80681B88: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80681B8C: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x80681B90: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80681B94:
    // 0x80681B94: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x80681B98: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x80681B9C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80681BA0: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_80681BA4:
    // 0x80681BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80681BA8:
    // 0x80681BA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80681BAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80681BB0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80681BB4: jr          $ra
    // 0x80681BB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80681BB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80041338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041338: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8004133C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80041340: lwc1        $f0, 0x12E4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X12E4);
    // 0x80041344: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80041348: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004134C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80041350: addiu       $t6, $t6, -0x6EB8
    ctx->r14 = ADD32(ctx->r14, -0X6EB8);
    // 0x80041354: bc1fl       L_80041368
    if (!c1cs) {
        // 0x80041358: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80041368;
    }
    goto skip_0;
    // 0x80041358: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x8004135C: jr          $ra
    // 0x80041360: sw          $zero, 0x12D0($a0)
    MEM_W(0X12D0, ctx->r4) = 0;
    return;
    // 0x80041360: sw          $zero, 0x12D0($a0)
    MEM_W(0X12D0, ctx->r4) = 0;
    // 0x80041364: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80041368:
    // 0x80041368: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004136C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80041370: nop

    // 0x80041374: bc1fl       L_80041390
    if (!c1cs) {
        // 0x80041378: sub.s       $f6, $f0, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80041390;
    }
    goto skip_1;
    // 0x80041378: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x8004137C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80041380: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80041384: b           L_800413A8
    // 0x80041388: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800413A8;
    // 0x80041388: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004138C: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
L_80041390:
    // 0x80041390: lwc1        $f8, 0x2F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2F0);
    // 0x80041394: lui         $at, 0xC188
    ctx->r1 = S32(0XC188 << 16);
    // 0x80041398: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004139C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800413A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800413A4: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
L_800413A8:
    // 0x800413A8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800413AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800413B0: sw          $t6, 0x12D0($a0)
    MEM_W(0X12D0, ctx->r4) = ctx->r14;
    // 0x800413B4: swc1        $f0, 0x12D8($a0)
    MEM_W(0X12D8, ctx->r4) = ctx->f0.u32l;
    // 0x800413B8: sw          $v0, 0x12E0($a0)
    MEM_W(0X12E0, ctx->r4) = ctx->r2;
    // 0x800413BC: swc1        $f18, 0x12DC($a0)
    MEM_W(0X12DC, ctx->r4) = ctx->f18.u32l;
    // 0x800413C0: jr          $ra
    // 0x800413C4: nop

    return;
    // 0x800413C4: nop

;}
RECOMP_FUNC void func_806FDA5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FDA5C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x806FDA60: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x806FDA64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806FDA68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FDA6C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x806FDA70: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806FDA74: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806FDA78: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x806FDA7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806FDA80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806FDA84: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x806FDA88: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806FDA8C: sub.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x806FDA90: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x806FDA94: nop

    // 0x806FDA98: bc1fl       L_806FDABC
    if (!c1cs) {
        // 0x806FDA9C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_806FDABC;
    }
    goto skip_0;
    // 0x806FDA9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x806FDAA0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x806FDAA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806FDAA8: nop

    // 0x806FDAAC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806FDAB0: jr          $ra
    // 0x806FDAB4: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x806FDAB4: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x806FDAB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_806FDABC:
    // 0x806FDABC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x806FDAC0: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x806FDAC4: nop

    // 0x806FDAC8: bc1f        L_806FDAE0
    if (!c1cs) {
        // 0x806FDACC: nop
    
            goto L_806FDAE0;
    }
    // 0x806FDACC: nop

    // 0x806FDAD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FDAD4: nop

    // 0x806FDAD8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x806FDADC: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
L_806FDAE0:
    // 0x806FDAE0: jr          $ra
    // 0x806FDAE4: nop

    return;
    // 0x806FDAE4: nop

;}
RECOMP_FUNC void func_80557B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80557B50: lui         $v0, 0x8056
    ctx->r2 = S32(RELOC_HI16(363, 0XAEC) << 16);
    // 0x80557B54: addiu       $v0, $v0, -0x79C4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(363, 0XAEC));
    // 0x80557B58: jr          $ra
    // 0x80557B5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80557B5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8000678C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000678C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80006790: beq         $a0, $at, L_800067B4
    if (ctx->r4 == ctx->r1) {
        // 0x80006794: lui         $t6, 0x800B
        ctx->r14 = S32(0X800B << 16);
            goto L_800067B4;
    }
    // 0x80006794: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80006798: addiu       $t6, $t6, 0x4D10
    ctx->r14 = ADD32(ctx->r14, 0X4D10);
    // 0x8000679C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800067A0: lbu         $t7, 0x29DC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X29DC);
    // 0x800067A4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800067A8: beq         $t7, $at, L_800067B4
    if (ctx->r15 == ctx->r1) {
        // 0x800067AC: nop
    
            goto L_800067B4;
    }
    // 0x800067AC: nop

    // 0x800067B0: sb          $a1, 0x29DC($v0)
    MEM_B(0X29DC, ctx->r2) = ctx->r5;
L_800067B4:
    // 0x800067B4: jr          $ra
    // 0x800067B8: nop

    return;
    // 0x800067B8: nop

;}
RECOMP_FUNC void func_80434F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434F34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80434F38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80434F3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80434F40: jal         0x804347A8
    // 0x80434F44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804347A8(rdram, ctx);
        goto after_0;
    // 0x80434F44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80434F48: jal         0x80434774
    // 0x80434F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434774(rdram, ctx);
        goto after_1;
    // 0x80434F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80434F50: jal         0x804348BC
    // 0x80434F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804348BC(rdram, ctx);
        goto after_2;
    // 0x80434F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80434F58: jal         0x80434A28
    // 0x80434F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434A28(rdram, ctx);
        goto after_3;
    // 0x80434F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80434F60: jal         0x80434C38
    // 0x80434F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434C38(rdram, ctx);
        goto after_4;
    // 0x80434F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80434F68: jal         0x80434D00
    // 0x80434F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434D00(rdram, ctx);
        goto after_5;
    // 0x80434F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80434F70: jal         0x80434CBC
    // 0x80434F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80434CBC(rdram, ctx);
        goto after_6;
    // 0x80434F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80434F78: beq         $v0, $zero, L_80434F90
    if (ctx->r2 == 0) {
        // 0x80434F7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80434F90;
    }
    // 0x80434F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80434F80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80434F84: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80434F88: jal         0x804351E8
    // 0x80434F8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804351E8(rdram, ctx);
        goto after_7;
    // 0x80434F8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_80434F90:
    // 0x80434F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80434F94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80434F98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80434F9C: jr          $ra
    // 0x80434FA0: nop

    return;
    // 0x80434FA0: nop

;}
RECOMP_FUNC void func_8058487C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058487C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584880: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584884: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584888: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058488C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584890: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584894: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584898: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058489C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805848A0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805848A4: jr          $ra
    // 0x805848A8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805848A8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80049FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049FFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004A000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A004: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x8004A008: jal         0x80049F68
    // 0x8004A00C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80049F68(rdram, ctx);
        goto after_0;
    // 0x8004A00C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004A010: jal         0x8004EC10
    // 0x8004A014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8004EC10(rdram, ctx);
        goto after_1;
    // 0x8004A014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8004A018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004A01C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004A020: jr          $ra
    // 0x8004A024: nop

    return;
    // 0x8004A024: nop

;}
RECOMP_FUNC void func_80440D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80440D94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80440D98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80440D9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80440DA0: jal         0x8043F33C
    // 0x80440DA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8043F33C(rdram, ctx);
        goto after_0;
    // 0x80440DA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80440DA8: jal         0x8043FBDC
    // 0x80440DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FBDC(rdram, ctx);
        goto after_1;
    // 0x80440DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80440DB0: jal         0x8043F150
    // 0x80440DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_2;
    // 0x80440DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80440DB8: jal         0x804400F0
    // 0x80440DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804400F0(rdram, ctx);
        goto after_3;
    // 0x80440DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80440DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80440DC4: jal         0x8043EF80
    // 0x80440DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8043EF80(rdram, ctx);
        goto after_4;
    // 0x80440DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80440DCC: jal         0x80440950
    // 0x80440DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80440950(rdram, ctx);
        goto after_5;
    // 0x80440DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80440DD4: beql        $v0, $zero, L_80440DF0
    if (ctx->r2 == 0) {
        // 0x80440DD8: lw          $t6, 0x180($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X180);
            goto L_80440DF0;
    }
    goto skip_0;
    // 0x80440DD8: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x80440DDC: jal         0x8043F46C
    // 0x80440DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F46C(rdram, ctx);
        goto after_6;
    // 0x80440DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80440DE4: b           L_80440E2C
    // 0x80440DE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80440E2C;
    // 0x80440DE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80440DEC: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
L_80440DF0:
    // 0x80440DF0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80440DF4: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x80440DF8: bne         $t7, $at, L_80440E10
    if (ctx->r15 != ctx->r1) {
        // 0x80440DFC: nop
    
            goto L_80440E10;
    }
    // 0x80440DFC: nop

    // 0x80440E00: jal         0x8043F6F4
    // 0x80440E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F6F4(rdram, ctx);
        goto after_7;
    // 0x80440E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80440E08: b           L_80440E2C
    // 0x80440E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80440E2C;
    // 0x80440E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80440E10:
    // 0x80440E10: jal         0x804406D0
    // 0x80440E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804406D0(rdram, ctx);
        goto after_8;
    // 0x80440E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80440E18: bnel        $v0, $zero, L_80440E2C
    if (ctx->r2 != 0) {
        // 0x80440E1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80440E2C;
    }
    goto skip_1;
    // 0x80440E1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80440E20: jal         0x8043F9A0
    // 0x80440E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F9A0(rdram, ctx);
        goto after_9;
    // 0x80440E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80440E28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80440E2C:
    // 0x80440E2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80440E30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80440E34: jr          $ra
    // 0x80440E38: nop

    return;
    // 0x80440E38: nop

;}
RECOMP_FUNC void func_8076C938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076C938: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8076C93C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076C940: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8076C944: jal         0x8076CAD0
    // 0x8076C948: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8076CAD0(rdram, ctx);
        goto after_0;
    // 0x8076C948: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8076C94C: beq         $v0, $zero, L_8076CA98
    if (ctx->r2 == 0) {
        // 0x8076C950: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_8076CA98;
    }
    // 0x8076C950: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8076C954: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8076C958: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8076C95C: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8076C960: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
    // 0x8076C964: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8076C968: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8076C96C: jal         0x8076CB18
    // 0x8076C970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8076CB18(rdram, ctx);
        goto after_1;
    // 0x8076C970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8076C974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076C978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076C97C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8076C980: jal         0x8076DD8C
    // 0x8076C984: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_2;
    // 0x8076C984: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8076C988: jal         0x8076C848
    // 0x8076C98C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8076C848(rdram, ctx);
        goto after_3;
    // 0x8076C98C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8076C990: lui         $t8, 0x8077
    ctx->r24 = S32(RELOC_HI16(766, 0X120) << 16);
    // 0x8076C994: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8076C998: addiu       $t8, $t8, -0x36F0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(766, 0X120));
    // 0x8076C99C: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x8076C9A0: addiu       $a0, $zero, 0x4649
    ctx->r4 = ADD32(0, 0X4649);
    // 0x8076C9A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8076C9A8: jal         0x8076E4DC
    // 0x8076C9AC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8076E4DC(rdram, ctx);
        goto after_4;
    // 0x8076C9AC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x8076C9B0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8076C9B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8076C9B8: bne         $v0, $zero, L_8076C9D0
    if (ctx->r2 != 0) {
        // 0x8076C9BC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8076C9D0;
    }
    // 0x8076C9BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8076C9C0: jal         0x800445A4
    // 0x8076C9C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x8076C9C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8076C9C8: b           L_8076CAC0
    // 0x8076C9CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076CAC0;
    // 0x8076C9CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076C9D0:
    // 0x8076C9D0: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8076C9D4: addiu       $a0, $zero, 0x4649
    ctx->r4 = ADD32(0, 0X4649);
    // 0x8076C9D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8076C9DC: sh          $t9, 0x144($t0)
    MEM_H(0X144, ctx->r8) = ctx->r25;
    // 0x8076C9E0: jal         0x8076E4DC
    // 0x8076C9E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8076E4DC(rdram, ctx);
        goto after_6;
    // 0x8076C9E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_6:
    // 0x8076C9E8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8076C9EC: addiu       $a0, $zero, 0x464A
    ctx->r4 = ADD32(0, 0X464A);
    // 0x8076C9F0: bne         $v0, $zero, L_8076CA08
    if (ctx->r2 != 0) {
        // 0x8076C9F4: sw          $v0, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r2;
            goto L_8076CA08;
    }
    // 0x8076C9F4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8076C9F8: jal         0x800445A4
    // 0x8076C9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x8076C9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8076CA00: b           L_8076CAC0
    // 0x8076CA04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076CAC0;
    // 0x8076CA04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076CA08:
    // 0x8076CA08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8076CA0C: jal         0x8076E4DC
    // 0x8076CA10: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8076E4DC(rdram, ctx);
        goto after_8;
    // 0x8076CA10: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_8:
    // 0x8076CA14: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8076CA18: addiu       $a0, $zero, 0x4635
    ctx->r4 = ADD32(0, 0X4635);
    // 0x8076CA1C: bne         $v0, $zero, L_8076CA34
    if (ctx->r2 != 0) {
        // 0x8076CA20: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_8076CA34;
    }
    // 0x8076CA20: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8076CA24: jal         0x800445A4
    // 0x8076CA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x8076CA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8076CA2C: b           L_8076CAC0
    // 0x8076CA30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076CAC0;
    // 0x8076CA30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076CA34:
    // 0x8076CA34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8076CA38: jal         0x8076E4DC
    // 0x8076CA3C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8076E4DC(rdram, ctx);
        goto after_10;
    // 0x8076CA3C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_10:
    // 0x8076CA40: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8076CA44: bne         $v0, $zero, L_8076CA5C
    if (ctx->r2 != 0) {
        // 0x8076CA48: sw          $v0, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r2;
            goto L_8076CA5C;
    }
    // 0x8076CA48: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8076CA4C: jal         0x800445A4
    // 0x8076CA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_11;
    // 0x8076CA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8076CA54: b           L_8076CAC0
    // 0x8076CA58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076CAC0;
    // 0x8076CA58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076CA5C:
    // 0x8076CA5C: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X3A18) << 16);
    // 0x8076CA60: addiu       $v0, $v0, 0x208
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X3A18));
    // 0x8076CA64: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8076CA68: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8076CA6C: swc1        $f4, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f4.u32l;
    // 0x8076CA70: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x8076CA74: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8076CA78: swc1        $f6, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f6.u32l;
    // 0x8076CA7C: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x8076CA80: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8076CA84: swc1        $f8, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f8.u32l;
    // 0x8076CA88: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x8076CA8C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8076CA90: b           L_8076CAA0
    // 0x8076CA94: swc1        $f10, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f10.u32l;
        goto L_8076CAA0;
    // 0x8076CA94: swc1        $f10, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f10.u32l;
L_8076CA98:
    // 0x8076CA98: jal         0x800445A4
    // 0x8076CA9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_12;
    // 0x8076CA9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_8076CAA0:
    // 0x8076CAA0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8076CAA4: jal         0x80067BBC
    // 0x8076CAA8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_13;
    // 0x8076CAA8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_13:
    // 0x8076CAAC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8076CAB0: jal         0x80067F78
    // 0x8076CAB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_14;
    // 0x8076CAB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x8076CAB8: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8076CABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076CAC0:
    // 0x8076CAC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8076CAC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8076CAC8: jr          $ra
    // 0x8076CACC: nop

    return;
    // 0x8076CACC: nop

;}
RECOMP_FUNC void func_80471860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471860: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80471864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471868: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8047186C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80471870: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80471874: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(158, 0X1A7C) << 16);
    // 0x80471878: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8047187C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80471880: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80471884: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80471888: lw          $t8, 0x2F3C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(158, 0X1A7C));
    // 0x8047188C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80471890: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80471894: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80471898: jal         0x80048490
    // 0x8047189C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8047189C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804718A0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804718A4: jal         0x80048378
    // 0x804718A8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804718A8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804718AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804718B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804718B4: jr          $ra
    // 0x804718B8: nop

    return;
    // 0x804718B8: nop

;}
RECOMP_FUNC void func_804A0610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A0614: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x804A0618: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x804A061C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804A0620: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804A0624: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x804A0628: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x804A062C: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x804A0630: beq         $v0, $zero, L_804A069C
    if (ctx->r2 == 0) {
        // 0x804A0634: add.s       $f12, $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f14.fl;
            goto L_804A069C;
    }
    // 0x804A0634: add.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x804A0638: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A063C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0640: nop

    // 0x804A0644: bc1fl       L_804A06A0
    if (!c1cs) {
        // 0x804A0648: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A06A0;
    }
    goto skip_0;
    // 0x804A0648: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x804A064C: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0650: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804A0654: sub.s       $f16, $f12, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x804A0658: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A065C: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0660: bc1fl       L_804A06A0
    if (!c1cs) {
        // 0x804A0664: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A06A0;
    }
    goto skip_1;
    // 0x804A0664: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x804A0668: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A066C: neg.s       $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = -ctx->f22.fl;
    // 0x804A0670: sub.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x804A0674: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x804A0678: nop

    // 0x804A067C: bc1fl       L_804A06A0
    if (!c1cs) {
        // 0x804A0680: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A06A0;
    }
    goto skip_2;
    // 0x804A0680: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_2:
    // 0x804A0684: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A0688: nop

    // 0x804A068C: bc1fl       L_804A06A0
    if (!c1cs) {
        // 0x804A0690: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A06A0;
    }
    goto skip_3;
    // 0x804A0690: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_3:
    // 0x804A0694: b           L_804A0944
    // 0x804A0698: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0944;
    // 0x804A0698: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_804A069C:
    // 0x804A069C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A06A0:
    // 0x804A06A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804A06A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A06A8: beql        $v0, $zero, L_804A0714
    if (ctx->r2 == 0) {
        // 0x804A06AC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0714;
    }
    goto skip_4;
    // 0x804A06AC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_4:
    // 0x804A06B0: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A06B4: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A06B8: nop

    // 0x804A06BC: bc1fl       L_804A0714
    if (!c1cs) {
        // 0x804A06C0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0714;
    }
    goto skip_5;
    // 0x804A06C0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_5:
    // 0x804A06C4: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A06C8: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x804A06CC: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A06D0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A06D4: bc1fl       L_804A0714
    if (!c1cs) {
        // 0x804A06D8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0714;
    }
    goto skip_6;
    // 0x804A06D8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_6:
    // 0x804A06DC: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A06E0: neg.s       $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
    // 0x804A06E4: sub.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x804A06E8: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x804A06EC: nop

    // 0x804A06F0: bc1fl       L_804A0714
    if (!c1cs) {
        // 0x804A06F4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0714;
    }
    goto skip_7;
    // 0x804A06F4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_7:
    // 0x804A06F8: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A06FC: nop

    // 0x804A0700: bc1fl       L_804A0714
    if (!c1cs) {
        // 0x804A0704: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0714;
    }
    goto skip_8;
    // 0x804A0704: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_8:
    // 0x804A0708: b           L_804A0944
    // 0x804A070C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0944;
    // 0x804A070C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0710: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0714:
    // 0x804A0714: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0718: beql        $v0, $zero, L_804A0784
    if (ctx->r2 == 0) {
        // 0x804A071C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0784;
    }
    goto skip_9;
    // 0x804A071C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_9:
    // 0x804A0720: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0724: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0728: nop

    // 0x804A072C: bc1fl       L_804A0784
    if (!c1cs) {
        // 0x804A0730: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0784;
    }
    goto skip_10;
    // 0x804A0730: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x804A0734: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0738: sub.s       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x804A073C: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A0740: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0744: bc1fl       L_804A0784
    if (!c1cs) {
        // 0x804A0748: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0784;
    }
    goto skip_11;
    // 0x804A0748: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_11:
    // 0x804A074C: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0750: neg.s       $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = -ctx->f22.fl;
    // 0x804A0754: sub.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x804A0758: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x804A075C: nop

    // 0x804A0760: bc1fl       L_804A0784
    if (!c1cs) {
        // 0x804A0764: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0784;
    }
    goto skip_12;
    // 0x804A0764: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_12:
    // 0x804A0768: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A076C: nop

    // 0x804A0770: bc1fl       L_804A0784
    if (!c1cs) {
        // 0x804A0774: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0784;
    }
    goto skip_13;
    // 0x804A0774: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_13:
    // 0x804A0778: b           L_804A0944
    // 0x804A077C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0944;
    // 0x804A077C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0780: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0784:
    // 0x804A0784: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0788: beql        $v0, $zero, L_804A07F4
    if (ctx->r2 == 0) {
        // 0x804A078C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A07F4;
    }
    goto skip_14;
    // 0x804A078C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_14:
    // 0x804A0790: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0794: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0798: nop

    // 0x804A079C: bc1fl       L_804A07F4
    if (!c1cs) {
        // 0x804A07A0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A07F4;
    }
    goto skip_15;
    // 0x804A07A0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_15:
    // 0x804A07A4: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A07A8: sub.s       $f16, $f12, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x804A07AC: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A07B0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A07B4: bc1fl       L_804A07F4
    if (!c1cs) {
        // 0x804A07B8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A07F4;
    }
    goto skip_16;
    // 0x804A07B8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_16:
    // 0x804A07BC: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A07C0: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
    // 0x804A07C4: sub.s       $f2, $f8, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x804A07C8: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x804A07CC: nop

    // 0x804A07D0: bc1fl       L_804A07F4
    if (!c1cs) {
        // 0x804A07D4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A07F4;
    }
    goto skip_17;
    // 0x804A07D4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_17:
    // 0x804A07D8: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A07DC: nop

    // 0x804A07E0: bc1fl       L_804A07F4
    if (!c1cs) {
        // 0x804A07E4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A07F4;
    }
    goto skip_18;
    // 0x804A07E4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_18:
    // 0x804A07E8: b           L_804A0944
    // 0x804A07EC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0944;
    // 0x804A07EC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A07F0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A07F4:
    // 0x804A07F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A07F8: beql        $v0, $zero, L_804A0864
    if (ctx->r2 == 0) {
        // 0x804A07FC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0864;
    }
    goto skip_19;
    // 0x804A07FC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_19:
    // 0x804A0800: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0804: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0808: nop

    // 0x804A080C: bc1fl       L_804A0864
    if (!c1cs) {
        // 0x804A0810: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0864;
    }
    goto skip_20;
    // 0x804A0810: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_20:
    // 0x804A0814: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0818: sub.s       $f16, $f12, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x804A081C: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A0820: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0824: bc1fl       L_804A0864
    if (!c1cs) {
        // 0x804A0828: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0864;
    }
    goto skip_21;
    // 0x804A0828: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_21:
    // 0x804A082C: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0830: neg.s       $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = -ctx->f22.fl;
    // 0x804A0834: sub.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x804A0838: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x804A083C: nop

    // 0x804A0840: bc1fl       L_804A0864
    if (!c1cs) {
        // 0x804A0844: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0864;
    }
    goto skip_22;
    // 0x804A0844: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_22:
    // 0x804A0848: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A084C: nop

    // 0x804A0850: bc1fl       L_804A0864
    if (!c1cs) {
        // 0x804A0854: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0864;
    }
    goto skip_23;
    // 0x804A0854: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_23:
    // 0x804A0858: b           L_804A0944
    // 0x804A085C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0944;
    // 0x804A085C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0860: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0864:
    // 0x804A0864: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0868: beql        $v0, $zero, L_804A08D4
    if (ctx->r2 == 0) {
        // 0x804A086C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A08D4;
    }
    goto skip_24;
    // 0x804A086C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_24:
    // 0x804A0870: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0874: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0878: nop

    // 0x804A087C: bc1fl       L_804A08D4
    if (!c1cs) {
        // 0x804A0880: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A08D4;
    }
    goto skip_25;
    // 0x804A0880: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_25:
    // 0x804A0884: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0888: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x804A088C: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A0890: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0894: bc1fl       L_804A08D4
    if (!c1cs) {
        // 0x804A0898: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A08D4;
    }
    goto skip_26;
    // 0x804A0898: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_26:
    // 0x804A089C: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A08A0: neg.s       $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
    // 0x804A08A4: sub.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x804A08A8: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x804A08AC: nop

    // 0x804A08B0: bc1fl       L_804A08D4
    if (!c1cs) {
        // 0x804A08B4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A08D4;
    }
    goto skip_27;
    // 0x804A08B4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_27:
    // 0x804A08B8: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A08BC: nop

    // 0x804A08C0: bc1fl       L_804A08D4
    if (!c1cs) {
        // 0x804A08C4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A08D4;
    }
    goto skip_28;
    // 0x804A08C4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_28:
    // 0x804A08C8: b           L_804A0944
    // 0x804A08CC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0944;
    // 0x804A08CC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A08D0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A08D4:
    // 0x804A08D4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A08D8: beql        $v0, $zero, L_804A0944
    if (ctx->r2 == 0) {
        // 0x804A08DC: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_804A0944;
    }
    goto skip_29;
    // 0x804A08DC: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_29:
    // 0x804A08E0: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A08E4: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A08E8: nop

    // 0x804A08EC: bc1fl       L_804A0944
    if (!c1cs) {
        // 0x804A08F0: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_804A0944;
    }
    goto skip_30;
    // 0x804A08F0: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_30:
    // 0x804A08F4: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A08F8: sub.s       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x804A08FC: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A0900: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0904: bc1fl       L_804A0944
    if (!c1cs) {
        // 0x804A0908: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_804A0944;
    }
    goto skip_31;
    // 0x804A0908: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_31:
    // 0x804A090C: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0910: neg.s       $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = -ctx->f22.fl;
    // 0x804A0914: sub.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x804A0918: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x804A091C: nop

    // 0x804A0920: bc1fl       L_804A0944
    if (!c1cs) {
        // 0x804A0924: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_804A0944;
    }
    goto skip_32;
    // 0x804A0924: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_32:
    // 0x804A0928: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A092C: nop

    // 0x804A0930: bc1fl       L_804A0944
    if (!c1cs) {
        // 0x804A0934: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_804A0944;
    }
    goto skip_33;
    // 0x804A0934: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_33:
    // 0x804A0938: b           L_804A0944
    // 0x804A093C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0944;
    // 0x804A093C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0940: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_804A0944:
    // 0x804A0944: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x804A0948: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x804A094C: jr          $ra
    // 0x804A0950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804A0950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80475F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475F50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475F54: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475F58: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475F5C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475F60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475F64: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26E78) << 16);
    // 0x80475F68: addiu       $a2, $a2, -0x49C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26E78));
    // 0x80475F6C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80475F70: jal         0x80475BBC
    // 0x80475F74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475BBC(rdram, ctx);
        goto after_0;
    // 0x80475F74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475F78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475F7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475F80: jr          $ra
    // 0x80475F84: nop

    return;
    // 0x80475F84: nop

;}
RECOMP_FUNC void func_800648DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800648DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800648E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800648E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800648E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800648EC: jal         0x80064850
    // 0x800648F0: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    func_80064850(rdram, ctx);
        goto after_0;
    // 0x800648F0: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x800648F4: bne         $v0, $zero, L_80064904
    if (ctx->r2 != 0) {
        // 0x800648F8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80064904;
    }
    // 0x800648F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800648FC: b           L_80064910
    // 0x80064900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80064910;
    // 0x80064900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80064904:
    // 0x80064904: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80064908: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006490C: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
L_80064910:
    // 0x80064910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064918: jr          $ra
    // 0x8006491C: nop

    return;
    // 0x8006491C: nop

;}
RECOMP_FUNC void func_806AF290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AF290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AF294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AF298: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x806AF29C: beql        $a1, $zero, L_806AF2B0
    if (ctx->r5 == 0) {
        // 0x806AF2A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806AF2B0;
    }
    goto skip_0;
    // 0x806AF2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806AF2A4: jal         0x800545F4
    // 0x806AF2A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800545F4(rdram, ctx);
        goto after_0;
    // 0x806AF2A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x806AF2AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806AF2B0:
    // 0x806AF2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AF2B4: jr          $ra
    // 0x806AF2B8: nop

    return;
    // 0x806AF2B8: nop

;}
RECOMP_FUNC void func_80435254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80435258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043525C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80435260: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80435264: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(71, 0X2A9C) << 16);
    // 0x80435268: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043526C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80435270: lw          $t8, 0x654C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(71, 0X2A9C));
    // 0x80435274: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80435278: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8043527C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80435280: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80435284: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80435288: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8043528C: beql        $v1, $zero, L_804352C0
    if (ctx->r3 == 0) {
        // 0x80435290: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804352C0;
    }
    goto skip_0;
    // 0x80435290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80435294: jalr        $v1
    // 0x80435298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80435298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043529C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804352A0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804352A4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804352A8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804352AC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804352B0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804352B4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804352B8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804352BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804352C0:
    // 0x804352C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804352C4: jr          $ra
    // 0x804352C8: nop

    return;
    // 0x804352C8: nop

;}
RECOMP_FUNC void func_80036B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036B80: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80036B84: lwc1        $f6, -0x7678($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7678);
    // 0x80036B88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036B8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80036B90: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80036B94: nop

    // 0x80036B98: bc1t        L_80036BA8
    if (c1cs) {
        // 0x80036B9C: nop
    
            goto L_80036BA8;
    }
    // 0x80036B9C: nop

    // 0x80036BA0: jr          $ra
    // 0x80036BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80036BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036BA8:
    // 0x80036BA8: jr          $ra
    // 0x80036BAC: nop

    return;
    // 0x80036BAC: nop

;}
RECOMP_FUNC void func_800104A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800104A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800104A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800104AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800104B0: jal         0x8000DC14
    // 0x800104B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8000DC14(rdram, ctx);
        goto after_0;
    // 0x800104B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800104B8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800104BC: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800104C0: addiu       $v1, $v1, 0x6D10
    ctx->r3 = ADD32(ctx->r3, 0X6D10);
    // 0x800104C4: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
L_800104C8:
    // 0x800104C8: lbu         $t6, 0x2E50($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2E50);
    // 0x800104CC: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // 0x800104D0: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800104D4: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x800104D8: sw          $zero, 0x2E20($v0)
    MEM_W(0X2E20, ctx->r2) = 0;
    // 0x800104DC: bne         $at, $zero, L_800104C8
    if (ctx->r1 != 0) {
        // 0x800104E0: sb          $t7, 0x2DD0($v0)
        MEM_B(0X2DD0, ctx->r2) = ctx->r15;
            goto L_800104C8;
    }
    // 0x800104E0: sb          $t7, 0x2DD0($v0)
    MEM_B(0X2DD0, ctx->r2) = ctx->r15;
    // 0x800104E4: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800104E8: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x800104EC: addiu       $s1, $s1, 0x7B60
    ctx->r17 = ADD32(ctx->r17, 0X7B60);
    // 0x800104F0: addiu       $s0, $s0, 0x7740
    ctx->r16 = ADD32(ctx->r16, 0X7740);
L_800104F4:
    // 0x800104F4: jal         0x800103EC
    // 0x800104F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800103EC(rdram, ctx);
        goto after_1;
    // 0x800104F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800104FC: addiu       $s0, $s0, 0x160
    ctx->r16 = ADD32(ctx->r16, 0X160);
    // 0x80010500: bne         $s0, $s1, L_800104F4
    if (ctx->r16 != ctx->r17) {
        // 0x80010504: nop
    
            goto L_800104F4;
    }
    // 0x80010504: nop

    // 0x80010508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001050C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80010510: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80010514: jr          $ra
    // 0x80010518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80010518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001051C: nop

;}
RECOMP_FUNC void pad_button(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB88: jr          $ra
    // 0x8007FB8C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    return;
    // 0x8007FB8C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
;}
RECOMP_FUNC void func_805D361C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D361C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D3620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D3624: jal         0x805D3358
    // 0x805D3628: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D3358(rdram, ctx);
        goto after_0;
    // 0x805D3628: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D362C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D3630: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D3634: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805D3638: jal         0x805D3B18
    // 0x805D363C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805D3B18(rdram, ctx);
        goto after_1;
    // 0x805D363C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805D3640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D3644: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D3648: jr          $ra
    // 0x805D364C: nop

    return;
    // 0x805D364C: nop

;}
RECOMP_FUNC void func_8000DBD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DBD4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000DBD8: bnel        $v1, $a0, L_8000DBEC
    if (ctx->r3 != ctx->r4) {
        // 0x8000DBDC: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_8000DBEC;
    }
    goto skip_0;
    // 0x8000DBDC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x8000DBE0: jr          $ra
    // 0x8000DBE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000DBE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DBE8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8000DBEC:
    // 0x8000DBEC: sw          $a0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r4;
    // 0x8000DBF0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000DBF4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000DBF8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000DBFC: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8000DC00: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8000DC04: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8000DC08: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8000DC0C: jr          $ra
    // 0x8000DC10: nop

    return;
    // 0x8000DC10: nop

;}
RECOMP_FUNC void func_804CDC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CDC4C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x804CDC50: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804CDC54: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804CDC58: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x804CDC5C: nop

    // 0x804CDC60: bc1fl       L_804CDCB0
    if (!c1cs) {
        // 0x804CDC64: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_804CDCB0;
    }
    goto skip_0;
    // 0x804CDC64: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x804CDC68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804CDC6C: nop

    // 0x804CDC70: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804CDC74: add.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x804CDC78: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x804CDC7C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804CDC80: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804CDC84: nop

    // 0x804CDC88: bc1f        L_804CDCFC
    if (!c1cs) {
        // 0x804CDC8C: nop
    
            goto L_804CDCFC;
    }
    // 0x804CDC8C: nop

    // 0x804CDC90: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x804CDC94: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x804CDC98: nop

    // 0x804CDC9C: bc1f        L_804CDCFC
    if (!c1cs) {
        // 0x804CDCA0: nop
    
            goto L_804CDCFC;
    }
    // 0x804CDCA0: nop

    // 0x804CDCA4: jr          $ra
    // 0x804CDCA8: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x804CDCA8: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x804CDCAC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_804CDCB0:
    // 0x804CDCB0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804CDCB4: bc1f        L_804CDCFC
    if (!c1cs) {
        // 0x804CDCB8: nop
    
            goto L_804CDCFC;
    }
    // 0x804CDCB8: nop

    // 0x804CDCBC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804CDCC0: nop

    // 0x804CDCC4: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x804CDCC8: add.s       $f16, $f12, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x804CDCCC: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x804CDCD0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804CDCD4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x804CDCD8: nop

    // 0x804CDCDC: bc1f        L_804CDCFC
    if (!c1cs) {
        // 0x804CDCE0: nop
    
            goto L_804CDCFC;
    }
    // 0x804CDCE0: nop

    // 0x804CDCE4: sub.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x804CDCE8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x804CDCEC: nop

    // 0x804CDCF0: bc1f        L_804CDCFC
    if (!c1cs) {
        // 0x804CDCF4: nop
    
            goto L_804CDCFC;
    }
    // 0x804CDCF4: nop

    // 0x804CDCF8: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
L_804CDCFC:
    // 0x804CDCFC: jr          $ra
    // 0x804CDD00: nop

    return;
    // 0x804CDD00: nop

;}
RECOMP_FUNC void func_80675738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067573C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80675740: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80675744: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80675748: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8067574C: jal         0x80067BBC
    // 0x80675750: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80675750: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x80675754: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80675758: jal         0x80067818
    // 0x8067575C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8067575C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80675760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80675764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80675768: jr          $ra
    // 0x8067576C: nop

    return;
    // 0x8067576C: nop

;}
RECOMP_FUNC void func_806CF91C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CF91C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CF920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CF924: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CF928: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806CF92C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806CF930: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x806CF934: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806CF938: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806CF93C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x806CF940: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806CF944: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806CF948: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x806CF94C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806CF950: jal         0x80066DE4
    // 0x806CF954: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x806CF954: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x806CF958: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806CF95C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806CF960: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x806CF964: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x806CF968: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x806CF96C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806CF970: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x806CF974: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x806CF978: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x806CF97C: jal         0x80066E88
    // 0x806CF980: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x806CF980: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x806CF984: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806CF988: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806CF98C: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x806CF990: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x806CF994: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x806CF998: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806CF99C: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x806CF9A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806CF9A4: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x806CF9A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CF9AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CF9B0: jr          $ra
    // 0x806CF9B4: nop

    return;
    // 0x806CF9B4: nop

;}
RECOMP_FUNC void func_80038E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038E80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80038E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038E88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80038E8C: lwc1        $f4, 0x150($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X150);
    // 0x80038E90: lwc1        $f6, 0x8C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80038E94: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80038E98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80038E9C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80038EA0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x80038EA4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80038EA8: jal         0x80038A6C
    // 0x80038EAC: nop

    func_80038A6C(rdram, ctx);
        goto after_0;
    // 0x80038EAC: nop

    after_0:
    // 0x80038EB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80038EB4: beq         $v0, $zero, L_80038F28
    if (ctx->r2 == 0) {
        // 0x80038EB8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80038F28;
    }
    // 0x80038EB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80038EBC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80038EC0: sw          $a1, 0x1F4($v0)
    MEM_W(0X1F4, ctx->r2) = ctx->r5;
    // 0x80038EC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038EC8: jal         0x80047F9C
    // 0x80038ECC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x80038ECC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80038ED0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80038ED4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80038ED8: lwc1        $f2, 0x154($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X154);
    // 0x80038EDC: lwc1        $f10, 0x78($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80038EE0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80038EE4: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80038EE8: lwc1        $f4, 0x3C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80038EEC: lw          $t6, 0x1F4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1F4);
    // 0x80038EF0: swc1        $f0, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->f0.u32l;
    // 0x80038EF4: swc1        $f0, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f0.u32l;
    // 0x80038EF8: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x80038EFC: mul.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80038F00: swc1        $f0, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->f0.u32l;
    // 0x80038F04: swc1        $f0, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f0.u32l;
    // 0x80038F08: lwc1        $f18, 0x80($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X80);
    // 0x80038F0C: mul.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80038F10: swc1        $f0, 0x80($a1)
    MEM_W(0X80, ctx->r5) = ctx->f0.u32l;
    // 0x80038F14: swc1        $f0, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->f0.u32l;
    // 0x80038F18: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x80038F1C: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
    // 0x80038F20: lwc1        $f6, 0x40($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X40);
    // 0x80038F24: swc1        $f6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f6.u32l;
L_80038F28:
    // 0x80038F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80038F30: jr          $ra
    // 0x80038F34: nop

    return;
    // 0x80038F34: nop

;}
RECOMP_FUNC void func_8040F7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040F7C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040F7CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040F7D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8040F7D4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8040F7D8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8040F7DC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8040F7E0: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x8040F7E4: jal         0x804103C0
    // 0x8040F7E8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_804103C0(rdram, ctx);
        goto after_0;
    // 0x8040F7E8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_0:
    // 0x8040F7EC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8040F7F0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8040F7F4: jal         0x80410AF4
    // 0x8040F7F8: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    func_80410AF4(rdram, ctx);
        goto after_1;
    // 0x8040F7F8: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x8040F7FC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8040F800: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8040F804: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8040F808: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8040F80C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8040F810: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8040F814: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8040F818: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8040F81C: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
    // 0x8040F820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040F824: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040F828: jr          $ra
    // 0x8040F82C: nop

    return;
    // 0x8040F82C: nop

;}
RECOMP_FUNC void func_806F2A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2A48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2A4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F2A50: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806F2A54: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806F2A58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2A5C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806F2A60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806F2A64: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806F2A68: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806F2A6C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806F2A70: lui         $t2, 0x806F
    ctx->r10 = S32(RELOC_HI16(679, 0X1B7C) << 16);
    // 0x806F2A74: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806F2A78: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806F2A7C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806F2A80: lw          $t2, 0x30FC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(679, 0X1B7C));
    // 0x806F2A84: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806F2A88: jal         0x806F28E8
    // 0x806F2A8C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_806F28E8(rdram, ctx);
        goto after_0;
    // 0x806F2A8C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x806F2A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F2A98: jr          $ra
    // 0x806F2A9C: nop

    return;
    // 0x806F2A9C: nop

;}
RECOMP_FUNC void func_805CACC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CACC4: jr          $ra
    // 0x805CACC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805CACC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80791BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791BF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80791BF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80791BF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80791BFC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80791C00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80791C04: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80791C08: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80791C0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791C10: jal         0x807903C4
    // 0x80791C14: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x80791C14: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x80791C18: jal         0x80790714
    // 0x80791C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80791C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80791C20: beql        $v0, $zero, L_80791CEC
    if (ctx->r2 == 0) {
        // 0x80791C24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80791CEC;
    }
    goto skip_0;
    // 0x80791C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80791C28: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x80791C2C: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80791C30: beq         $at, $zero, L_80791C58
    if (ctx->r1 == 0) {
        // 0x80791C34: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80791C58;
    }
    // 0x80791C34: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80791C38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80791C3C: jal         0x8006CB1C
    // 0x80791C40: nop

    func_8006CB1C(rdram, ctx);
        goto after_2;
    // 0x80791C40: nop

    after_2:
    // 0x80791C44: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80791C48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80791C4C: jal         0x8006CB2C
    // 0x80791C50: nop

    func_8006CB2C(rdram, ctx);
        goto after_3;
    // 0x80791C50: nop

    after_3:
    // 0x80791C54: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
L_80791C58:
    // 0x80791C58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80791C5C: bne         $v0, $at, L_80791CA8
    if (ctx->r2 != ctx->r1) {
        // 0x80791C60: addiu       $a0, $zero, 0x26
        ctx->r4 = ADD32(0, 0X26);
            goto L_80791CA8;
    }
    // 0x80791C60: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x80791C64: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80791C68: jal         0x800677F8
    // 0x80791C6C: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    func_800677F8(rdram, ctx);
        goto after_4;
    // 0x80791C6C: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    after_4:
    // 0x80791C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791C74: jal         0x80790CD8
    // 0x80791C78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80790CD8(rdram, ctx);
        goto after_5;
    // 0x80791C78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80791C7C: bne         $v0, $zero, L_80791C98
    if (ctx->r2 != 0) {
        // 0x80791C80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80791C98;
    }
    // 0x80791C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791C84: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80791C88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791C8C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80791C90: jal         0x8079393C
    // 0x80791C94: lw          $a3, 0x68($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X68);
    func_8079393C(rdram, ctx);
        goto after_6;
    // 0x80791C94: lw          $a3, 0x68($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X68);
    after_6:
L_80791C98:
    // 0x80791C98: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80791C9C: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80791CA0: b           L_80791CE8
    // 0x80791CA4: sw          $t8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r24;
        goto L_80791CE8;
    // 0x80791CA4: sw          $t8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r24;
L_80791CA8:
    // 0x80791CA8: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80791CAC: beq         $at, $zero, L_80791CD4
    if (ctx->r1 == 0) {
        // 0x80791CB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80791CD4;
    }
    // 0x80791CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791CB4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80791CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791CBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791CC0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80791CC4: jal         0x8079393C
    // 0x80791CC8: lw          $a3, 0x68($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X68);
    func_8079393C(rdram, ctx);
        goto after_7;
    // 0x80791CC8: lw          $a3, 0x68($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X68);
    after_7:
    // 0x80791CCC: b           L_80791CEC
    // 0x80791CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80791CEC;
    // 0x80791CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80791CD4:
    // 0x80791CD4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80791CD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791CDC: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80791CE0: jal         0x8079393C
    // 0x80791CE4: lw          $a3, 0x68($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X68);
    func_8079393C(rdram, ctx);
        goto after_8;
    // 0x80791CE4: lw          $a3, 0x68($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X68);
    after_8:
L_80791CE8:
    // 0x80791CE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80791CEC:
    // 0x80791CEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80791CF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80791CF4: jr          $ra
    // 0x80791CF8: nop

    return;
    // 0x80791CF8: nop

;}
RECOMP_FUNC void func_804EEEDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EEEDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EEEE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EEEE4: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804EEEE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804EEEEC: beq         $t6, $zero, L_804EEF28
    if (ctx->r14 == 0) {
        // 0x804EEEF0: nop
    
            goto L_804EEF28;
    }
    // 0x804EEEF0: nop

    // 0x804EEEF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804EEEF8: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804EEEFC: jalr        $t9
    // 0x804EEF00: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804EEF00: nop

    after_0:
    // 0x804EEF04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EEF08: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804EEF0C: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804EEF10: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804EEF14: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804EEF18: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804EEF1C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804EEF20: b           L_804EEF28
    // 0x804EEF24: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804EEF28;
    // 0x804EEF24: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804EEF28:
    // 0x804EEF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EEF2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EEF30: jr          $ra
    // 0x804EEF34: nop

    return;
    // 0x804EEF34: nop

;}
RECOMP_FUNC void func_8000938C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000938C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80009390: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80009394: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x80009398: addiu       $s3, $s3, 0x4D10
    ctx->r19 = ADD32(ctx->r19, 0X4D10);
    // 0x8000939C: lw          $t6, 0xD84($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XD84);
    // 0x800093A0: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x800093A4: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800093A8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800093AC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800093B0: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800093B4: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800093B8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800093BC: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x800093C0: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800093C4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800093C8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800093CC: beq         $t6, $zero, L_800093DC
    if (ctx->r14 == 0) {
        // 0x800093D0: sw          $zero, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = 0;
            goto L_800093DC;
    }
    // 0x800093D0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800093D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800093D8: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_800093DC:
    // 0x800093DC: lw          $t8, 0x1D78($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X1D78);
    // 0x800093E0: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x800093E4: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x800093E8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800093EC: sw          $zero, 0xD80($s3)
    MEM_W(0XD80, ctx->r19) = 0;
    // 0x800093F0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800093F4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800093F8: lbu         $s7, 0x1($v0)
    ctx->r23 = MEM_BU(ctx->r2, 0X1);
    // 0x800093FC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80009400: blez        $v1, L_80009464
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80009404: addiu       $s4, $zero, 0x7F
        ctx->r20 = ADD32(0, 0X7F);
            goto L_80009464;
    }
    // 0x80009404: addiu       $s4, $zero, 0x7F
    ctx->r20 = ADD32(0, 0X7F);
    // 0x80009408: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x8000940C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80009410:
    // 0x80009410: jal         0x8000B808
    // 0x80009414: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8000B808(rdram, ctx);
        goto after_0;
    // 0x80009414: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80009418: beq         $v0, $zero, L_80009450
    if (ctx->r2 == 0) {
        // 0x8000941C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80009450;
    }
    // 0x8000941C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80009420: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x80009424: beql        $t2, $zero, L_80009438
    if (ctx->r10 == 0) {
        // 0x80009428: lbu         $t3, 0x2($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X2);
            goto L_80009438;
    }
    goto skip_0;
    // 0x80009428: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
    skip_0:
    // 0x8000942C: jal         0x80009334
    // 0x80009430: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    func_80009334(rdram, ctx);
        goto after_1;
    // 0x80009430: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    after_1:
    // 0x80009434: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
L_80009438:
    // 0x80009438: beq         $s4, $t3, L_80009448
    if (ctx->r20 == ctx->r11) {
        // 0x8000943C: nop
    
            goto L_80009448;
    }
    // 0x8000943C: nop

    // 0x80009440: jal         0x80009334
    // 0x80009444: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_80009334(rdram, ctx);
        goto after_2;
    // 0x80009444: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_2:
L_80009448:
    // 0x80009448: jal         0x80009334
    // 0x8000944C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_80009334(rdram, ctx);
        goto after_3;
    // 0x8000944C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_3:
L_80009450:
    // 0x80009450: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80009454: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80009458: bnel        $s2, $t4, L_80009410
    if (ctx->r18 != ctx->r12) {
        // 0x8000945C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80009410;
    }
    goto skip_1;
    // 0x8000945C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x80009460: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80009464:
    // 0x80009464: blez        $s7, L_80009490
    if (SIGNED(ctx->r23) <= 0) {
        // 0x80009468: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80009490;
    }
    // 0x80009468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8000946C:
    // 0x8000946C: jal         0x8000B8DC
    // 0x80009470: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8000B8DC(rdram, ctx);
        goto after_4;
    // 0x80009470: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80009474: beql        $v0, $zero, L_80009488
    if (ctx->r2 == 0) {
        // 0x80009478: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80009488;
    }
    goto skip_2;
    // 0x80009478: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x8000947C: jal         0x80009334
    // 0x80009480: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    func_80009334(rdram, ctx);
        goto after_5;
    // 0x80009480: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    after_5:
    // 0x80009484: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80009488:
    // 0x80009488: bnel        $s2, $s7, L_8000946C
    if (ctx->r18 != ctx->r23) {
        // 0x8000948C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8000946C;
    }
    goto skip_3;
    // 0x8000948C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
L_80009490:
    // 0x80009490: lw          $a0, 0xD80($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XD80);
    // 0x80009494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80009498: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000949C: beql        $a0, $zero, L_800097C8
    if (ctx->r4 == 0) {
        // 0x800094A0: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800097C8;
    }
    goto skip_4;
    // 0x800094A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x800094A4: blez        $a0, L_800094F0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800094A8: lw          $v1, 0xD84($s3)
        ctx->r3 = MEM_W(ctx->r19, 0XD84);
            goto L_800094F0;
    }
    // 0x800094A8: lw          $v1, 0xD84($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XD84);
    // 0x800094AC: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x800094B0: addiu       $v0, $t5, 0x4D10
    ctx->r2 = ADD32(ctx->r13, 0X4D10);
    // 0x800094B4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800094B8: addu        $a3, $t6, $v0
    ctx->r7 = ADD32(ctx->r14, ctx->r2);
    // 0x800094BC: addiu       $a2, $zero, -0x10
    ctx->r6 = ADD32(0, -0X10);
L_800094C0:
    // 0x800094C0: lw          $t7, 0x180($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X180);
    // 0x800094C4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800094C8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800094CC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800094D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800094D4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800094D8: addiu       $t2, $t9, 0xF
    ctx->r10 = ADD32(ctx->r25, 0XF);
    // 0x800094DC: sltu        $at, $v0, $a3
    ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x800094E0: and         $t3, $t2, $a2
    ctx->r11 = ctx->r10 & ctx->r6;
    // 0x800094E4: bne         $at, $zero, L_800094C0
    if (ctx->r1 != 0) {
        // 0x800094E8: addu        $a1, $a1, $t3
        ctx->r5 = ADD32(ctx->r5, ctx->r11);
            goto L_800094C0;
    }
    // 0x800094E8: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x800094EC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800094F0:
    // 0x800094F0: blez        $a0, L_80009758
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800094F4: addiu       $s7, $zero, 0x1
        ctx->r23 = ADD32(0, 0X1);
            goto L_80009758;
    }
    // 0x800094F4: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800094F8: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x800094FC: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80009500: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
L_80009504:
    // 0x80009504: beq         $v1, $at, L_80009758
    if (ctx->r3 == ctx->r1) {
        // 0x80009508: sll         $t4, $s2, 2
        ctx->r12 = S32(ctx->r18 << 2);
            goto L_80009758;
    }
    // 0x80009508: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x8000950C: addu        $t6, $s3, $t4
    ctx->r14 = ADD32(ctx->r19, ctx->r12);
    // 0x80009510: beq         $s6, $zero, L_80009528
    if (ctx->r22 == 0) {
        // 0x80009514: lw          $s0, 0x180($t6)
        ctx->r16 = MEM_W(ctx->r14, 0X180);
            goto L_80009528;
    }
    // 0x80009514: lw          $s0, 0x180($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X180);
    // 0x80009518: beql        $s6, $s7, L_80009598
    if (ctx->r22 == ctx->r23) {
        // 0x8000951C: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80009598;
    }
    goto skip_5;
    // 0x8000951C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x80009520: b           L_800095FC
    // 0x80009524: nop

        goto L_800095FC;
    // 0x80009524: nop

L_80009528:
    // 0x80009528: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000952C: lw          $t5, 0x10($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X10);
    // 0x80009530: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80009534: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80009538: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x8000953C: bne         $t5, $v1, L_80009564
    if (ctx->r13 != ctx->r3) {
        // 0x80009540: ori         $at, $at, 0xFFFF
        ctx->r1 = ctx->r1 | 0XFFFF;
            goto L_80009564;
    }
    // 0x80009540: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80009544: sll         $a3, $v1, 24
    ctx->r7 = S32(ctx->r3 << 24);
    // 0x80009548: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x8000954C: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    // 0x80009550: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x80009554: jal         0x8000576C
    // 0x80009558: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_8000576C(rdram, ctx);
        goto after_6;
    // 0x80009558: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x8000955C: b           L_800095FC
    // 0x80009560: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800095FC;
    // 0x80009560: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80009564:
    // 0x80009564: lw          $t7, 0x14($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X14);
    // 0x80009568: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000956C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80009570: bne         $t7, $v1, L_800095FC
    if (ctx->r15 != ctx->r3) {
        // 0x80009574: and         $a0, $v0, $at
        ctx->r4 = ctx->r2 & ctx->r1;
            goto L_800095FC;
    }
    // 0x80009574: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    // 0x80009578: sll         $a3, $v1, 24
    ctx->r7 = S32(ctx->r3 << 24);
    // 0x8000957C: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80009580: lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X4);
    // 0x80009584: jal         0x8000576C
    // 0x80009588: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_8000576C(rdram, ctx);
        goto after_7;
    // 0x80009588: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_7:
    // 0x8000958C: b           L_800095FC
    // 0x80009590: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800095FC;
    // 0x80009590: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80009594: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80009598:
    // 0x80009598: lw          $t8, 0x10($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X10);
    // 0x8000959C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800095A0: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800095A4: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x800095A8: bne         $t8, $v1, L_800095D0
    if (ctx->r24 != ctx->r3) {
        // 0x800095AC: ori         $at, $at, 0xFFFF
        ctx->r1 = ctx->r1 | 0XFFFF;
            goto L_800095D0;
    }
    // 0x800095AC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800095B0: sll         $a3, $v1, 24
    ctx->r7 = S32(ctx->r3 << 24);
    // 0x800095B4: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x800095B8: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    // 0x800095BC: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x800095C0: jal         0x8000571C
    // 0x800095C4: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_8000571C(rdram, ctx);
        goto after_8;
    // 0x800095C4: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_8:
    // 0x800095C8: b           L_800095FC
    // 0x800095CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800095FC;
    // 0x800095CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800095D0:
    // 0x800095D0: lw          $t9, 0x14($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X14);
    // 0x800095D4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800095D8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800095DC: bne         $t9, $v1, L_800095FC
    if (ctx->r25 != ctx->r3) {
        // 0x800095E0: and         $a0, $v0, $at
        ctx->r4 = ctx->r2 & ctx->r1;
            goto L_800095FC;
    }
    // 0x800095E0: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    // 0x800095E4: sll         $a3, $v1, 24
    ctx->r7 = S32(ctx->r3 << 24);
    // 0x800095E8: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x800095EC: lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X4);
    // 0x800095F0: jal         0x8000571C
    // 0x800095F4: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_8000571C(rdram, ctx);
        goto after_9;
    // 0x800095F4: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_9:
    // 0x800095F8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800095FC:
    // 0x800095FC: bne         $s1, $zero, L_80009610
    if (ctx->r17 != 0) {
        // 0x80009600: nop
    
            goto L_80009610;
    }
    // 0x80009600: nop

    // 0x80009604: lw          $v1, 0xD84($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XD84);
    // 0x80009608: b           L_80009744
    // 0x8000960C: lw          $a0, 0xD80($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XD80);
        goto L_80009744;
    // 0x8000960C: lw          $a0, 0xD80($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XD80);
L_80009610:
    // 0x80009610: beql        $s6, $zero, L_8000962C
    if (ctx->r22 == 0) {
        // 0x80009614: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8000962C;
    }
    goto skip_6;
    // 0x80009614: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_6:
    // 0x80009618: beq         $s6, $s7, L_800096A8
    if (ctx->r22 == ctx->r23) {
        // 0x8000961C: lw          $v1, 0xD84($s3)
        ctx->r3 = MEM_W(ctx->r19, 0XD84);
            goto L_800096A8;
    }
    // 0x8000961C: lw          $v1, 0xD84($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XD84);
    // 0x80009620: b           L_80009744
    // 0x80009624: lw          $a0, 0xD80($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XD80);
        goto L_80009744;
    // 0x80009624: lw          $a0, 0xD80($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XD80);
    // 0x80009628: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8000962C:
    // 0x8000962C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009630: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80009634: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80009638: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x8000963C: bne         $v1, $at, L_80009678
    if (ctx->r3 != ctx->r1) {
        // 0x80009640: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80009678;
    }
    // 0x80009640: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80009644: lw          $t2, 0x1D6C($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X1D6C);
    // 0x80009648: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000964C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80009650: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x80009654: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80009658: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000965C: jal         0x80007798
    // 0x80009660: lh          $a3, 0x2($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X2);
    func_80007798(rdram, ctx);
        goto after_10;
    // 0x80009660: lh          $a3, 0x2($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X2);
    after_10:
    // 0x80009664: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x80009668: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x8000966C: andi        $t4, $t3, 0xFFF3
    ctx->r12 = ctx->r11 & 0XFFF3;
    // 0x80009670: b           L_8000969C
    // 0x80009674: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
        goto L_8000969C;
    // 0x80009674: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
L_80009678:
    // 0x80009678: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000967C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80009680: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x80009684: jal         0x80007674
    // 0x80009688: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_80007674(rdram, ctx);
        goto after_11;
    // 0x80009688: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_11:
    // 0x8000968C: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80009690: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
    // 0x80009694: andi        $t5, $t6, 0xFFF3
    ctx->r13 = ctx->r14 & 0XFFF3;
    // 0x80009698: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_8000969C:
    // 0x8000969C: lw          $v1, 0xD84($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XD84);
    // 0x800096A0: b           L_80009744
    // 0x800096A4: lw          $a0, 0xD80($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XD80);
        goto L_80009744;
    // 0x800096A4: lw          $a0, 0xD80($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XD80);
L_800096A8:
    // 0x800096A8: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800096AC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800096B0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800096B4: mflo        $t7
    ctx->r15 = lo;
    // 0x800096B8: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x800096BC: sw          $s0, 0x384($t8)
    MEM_W(0X384, ctx->r24) = ctx->r16;
    // 0x800096C0: lw          $t9, 0xD84($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XD84);
    // 0x800096C4: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800096C8: mflo        $t2
    ctx->r10 = lo;
    // 0x800096CC: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x800096D0: sw          $s1, 0x388($t3)
    MEM_W(0X388, ctx->r11) = ctx->r17;
    // 0x800096D4: lw          $v1, 0xD84($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XD84);
    // 0x800096D8: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800096DC: sll         $t4, $v1, 24
    ctx->r12 = S32(ctx->r3 << 24);
    // 0x800096E0: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x800096E4: mflo        $t5
    ctx->r13 = lo;
    // 0x800096E8: addu        $t7, $s3, $t5
    ctx->r15 = ADD32(ctx->r19, ctx->r13);
    // 0x800096EC: sw          $t6, 0x38C($t7)
    MEM_W(0X38C, ctx->r15) = ctx->r14;
    // 0x800096F0: lw          $t8, 0xD84($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XD84);
    // 0x800096F4: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800096F8: mflo        $t9
    ctx->r25 = lo;
    // 0x800096FC: addu        $t2, $s3, $t9
    ctx->r10 = ADD32(ctx->r19, ctx->r25);
    // 0x80009700: sw          $zero, 0x390($t2)
    MEM_W(0X390, ctx->r10) = 0;
    // 0x80009704: lw          $t9, 0xD84($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XD84);
    // 0x80009708: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000970C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80009710: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80009714: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x80009718: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8000971C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80009720: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x80009724: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80009728: mflo        $t2
    ctx->r10 = lo;
    // 0x8000972C: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x80009730: sw          $t8, 0x380($t3)
    MEM_W(0X380, ctx->r11) = ctx->r24;
    // 0x80009734: lw          $t4, 0xD84($s3)
    ctx->r12 = MEM_W(ctx->r19, 0XD84);
    // 0x80009738: lw          $a0, 0xD80($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XD80);
    // 0x8000973C: addiu       $v1, $t4, 0x1
    ctx->r3 = ADD32(ctx->r12, 0X1);
    // 0x80009740: sw          $v1, 0xD84($s3)
    MEM_W(0XD84, ctx->r19) = ctx->r3;
L_80009744:
    // 0x80009744: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80009748: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000974C: bnel        $at, $zero, L_80009504
    if (ctx->r1 != 0) {
        // 0x80009750: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_80009504;
    }
    goto skip_7;
    // 0x80009750: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    skip_7:
    // 0x80009754: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
L_80009758:
    // 0x80009758: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x8000975C: beq         $v1, $zero, L_800097C4
    if (ctx->r3 == 0) {
        // 0x80009760: sw          $zero, 0xD80($s3)
        MEM_W(0XD80, ctx->r19) = 0;
            goto L_800097C4;
    }
    // 0x80009760: sw          $zero, 0xD80($s3)
    MEM_W(0XD80, ctx->r19) = 0;
    // 0x80009764: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80009768: bnel        $t5, $zero, L_800097C8
    if (ctx->r13 != 0) {
        // 0x8000976C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800097C8;
    }
    goto skip_8;
    // 0x8000976C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_8:
    // 0x80009770: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80009774: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80009778: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000977C: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80009780: addiu       $t9, $t9, 0x60DC
    ctx->r25 = ADD32(ctx->r25, 0X60DC);
    // 0x80009784: mflo        $t7
    ctx->r15 = lo;
    // 0x80009788: addu        $t0, $s3, $t7
    ctx->r8 = ADD32(ctx->r19, ctx->r15);
    // 0x8000978C: lw          $s0, 0x370($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X370);
    // 0x80009790: lw          $t2, 0x378($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X378);
    // 0x80009794: lw          $a1, 0x374($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X374);
    // 0x80009798: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000979C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800097A0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800097A4: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x800097A8: srl         $t1, $a2, 12
    ctx->r9 = S32(U32(ctx->r6) >> 12);
    // 0x800097AC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800097B0: sll         $a3, $v0, 4
    ctx->r7 = S32(ctx->r2 << 4);
    // 0x800097B4: srl         $a3, $a3, 30
    ctx->r7 = S32(U32(ctx->r7) >> 30);
    // 0x800097B8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800097BC: jal         0x80008668
    // 0x800097C0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    func_80008668(rdram, ctx);
        goto after_12;
    // 0x800097C0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_12:
L_800097C4:
    // 0x800097C4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800097C8:
    // 0x800097C8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800097CC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800097D0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800097D4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800097D8: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800097DC: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800097E0: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x800097E4: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x800097E8: jr          $ra
    // 0x800097EC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800097EC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8003AA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AA98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003AA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AAA0: jal         0x8003A620
    // 0x8003AAA4: nop

    func_8003A620(rdram, ctx);
        goto after_0;
    // 0x8003AAA4: nop

    after_0:
    // 0x8003AAA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AAAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003AAB0: jr          $ra
    // 0x8003AAB4: nop

    return;
    // 0x8003AAB4: nop

;}
RECOMP_FUNC void func_806F1754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1754: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806F1758: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x806F175C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F1760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F1764: beq         $t6, $zero, L_806F17A4
    if (ctx->r14 == 0) {
        // 0x806F1768: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806F17A4;
    }
    // 0x806F1768: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F176C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x806F1770: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F1774: jal         0x806F1F14
    // 0x806F1778: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806F1F14(rdram, ctx);
        goto after_0;
    // 0x806F1778: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x806F177C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F1780: jal         0x8005FDC4
    // 0x806F1784: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x806F1784: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    after_1:
    // 0x806F1788: jal         0x806F1644
    // 0x806F178C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806F1644(rdram, ctx);
        goto after_2;
    // 0x806F178C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806F1790: jal         0x80067E68
    // 0x806F1794: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x806F1794: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x806F1798: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F179C: jal         0x80067818
    // 0x806F17A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x806F17A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
L_806F17A4:
    // 0x806F17A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F17A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F17AC: jr          $ra
    // 0x806F17B0: nop

    return;
    // 0x806F17B0: nop

;}
RECOMP_FUNC void func_80003698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003698: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x8000369C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800036A0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x800036A4: addiu       $v0, $a1, 0xF
    ctx->r2 = ADD32(ctx->r5, 0XF);
    // 0x800036A8: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800036AC: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x800036B0: addu        $t9, $a2, $v0
    ctx->r25 = ADD32(ctx->r6, ctx->r2);
    // 0x800036B4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800036B8: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x800036BC: bne         $at, $zero, L_800036D0
    if (ctx->r1 != 0) {
        // 0x800036C0: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800036D0;
    }
    // 0x800036C0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800036C4: addu        $t0, $a2, $v0
    ctx->r8 = ADD32(ctx->r6, ctx->r2);
    // 0x800036C8: b           L_800036D8
    // 0x800036CC: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
        goto L_800036D8;
    // 0x800036CC: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
L_800036D0:
    // 0x800036D0: jr          $ra
    // 0x800036D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800036D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800036D8:
    // 0x800036D8: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800036DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800036E0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800036E4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x800036E8: jr          $ra
    // 0x800036EC: nop

    return;
    // 0x800036EC: nop

;}
RECOMP_FUNC void func_804A4EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4EF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A4EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A4EFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A4F00: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804A4F04: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804A4F08: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804A4F0C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804A4F10: lw          $v1, 0x6EE8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6EE8);
    // 0x804A4F14: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x804A4F18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A4F1C: bne         $v1, $zero, L_804A4F4C
    if (ctx->r3 != 0) {
        // 0x804A4F20: nop
    
            goto L_804A4F4C;
    }
    // 0x804A4F20: nop

    // 0x804A4F24: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x804A4F28: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x804A4F2C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x804A4F30: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x804A4F34: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x804A4F38: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804A4F3C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x804A4F40: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804A4F44: b           L_804A4F54
    // 0x804A4F48: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
        goto L_804A4F54;
    // 0x804A4F48: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_804A4F4C:
    // 0x804A4F4C: jal         0x804A4E64
    // 0x804A4F50: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_804A4E64(rdram, ctx);
        goto after_0;
    // 0x804A4F50: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
L_804A4F54:
    // 0x804A4F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A4F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A4F5C: jr          $ra
    // 0x804A4F60: nop

    return;
    // 0x804A4F60: nop

;}
RECOMP_FUNC void func_80040C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040C48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040C50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80040C54: lw          $t6, 0x1F0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1F0);
    // 0x80040C58: beql        $t6, $zero, L_80040C8C
    if (ctx->r14 == 0) {
        // 0x80040C5C: sb          $zero, 0x1F8($a1)
        MEM_B(0X1F8, ctx->r5) = 0;
            goto L_80040C8C;
    }
    goto skip_0;
    // 0x80040C5C: sb          $zero, 0x1F8($a1)
    MEM_B(0X1F8, ctx->r5) = 0;
    skip_0:
    // 0x80040C60: lbu         $t7, 0x1F8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1F8);
    // 0x80040C64: bnel        $t7, $zero, L_80040C7C
    if (ctx->r15 != 0) {
        // 0x80040C68: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80040C7C;
    }
    goto skip_1;
    // 0x80040C68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x80040C6C: jal         0x8003BF08
    // 0x80040C70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8003BF08(rdram, ctx);
        goto after_0;
    // 0x80040C70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80040C74: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80040C78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80040C7C:
    // 0x80040C7C: jal         0x8003FBE4
    // 0x80040C80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8003FBE4(rdram, ctx);
        goto after_1;
    // 0x80040C80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80040C84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80040C88: sb          $zero, 0x1F8($a1)
    MEM_B(0X1F8, ctx->r5) = 0;
L_80040C8C:
    // 0x80040C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040C94: jr          $ra
    // 0x80040C98: nop

    return;
    // 0x80040C98: nop

;}
RECOMP_FUNC void func_806761F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806761F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806761F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806761F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806761FC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676200: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80676204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80676208: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x8067620C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80676210: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80676214: blez        $v1, L_80676224
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80676218: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80676224;
    }
    // 0x80676218: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8067621C: b           L_80676238
    // 0x80676220: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
        goto L_80676238;
    // 0x80676220: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
L_80676224:
    // 0x80676224: sh          $t8, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r24;
    // 0x80676228: jal         0x80677A88
    // 0x8067622C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80677A88(rdram, ctx);
        goto after_0;
    // 0x8067622C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80676230: jal         0x80675B9C
    // 0x80676234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80675B9C(rdram, ctx);
        goto after_1;
    // 0x80676234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80676238:
    // 0x80676238: jal         0x80675CD0
    // 0x8067623C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80675CD0(rdram, ctx);
        goto after_2;
    // 0x8067623C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80676240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80676244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80676248: jr          $ra
    // 0x8067624C: nop

    return;
    // 0x8067624C: nop

;}
RECOMP_FUNC void func_80670280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670280: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(520, 0X524) << 16);
    // 0x80670284: addiu       $v0, $v0, 0x7A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(520, 0X524));
    // 0x80670288: jr          $ra
    // 0x8067028C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8067028C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8005FB2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FB2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FB34: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8005FB38: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005FB3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005FB40: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005FB44: lbu         $t7, 0x77($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X77);
    // 0x8005FB48: beql        $t7, $zero, L_8005FB68
    if (ctx->r15 == 0) {
        // 0x8005FB4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FB68;
    }
    goto skip_0;
    // 0x8005FB4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005FB50: jal         0x8005F9F4
    // 0x8005FB54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8005F9F4(rdram, ctx);
        goto after_0;
    // 0x8005FB54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005FB58: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FB5C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8005FB60: sb          $zero, 0x77($t8)
    MEM_B(0X77, ctx->r24) = 0;
    // 0x8005FB64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FB68:
    // 0x8005FB68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FB6C: jr          $ra
    // 0x8005FB70: nop

    return;
    // 0x8005FB70: nop

;}
RECOMP_FUNC void func_807AD9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AD9C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AD9C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AD9C8: jal         0x807AD97C
    // 0x807AD9CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807AD97C(rdram, ctx);
        goto after_0;
    // 0x807AD9CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AD9D0: bne         $v0, $zero, L_807AD9E8
    if (ctx->r2 != 0) {
        // 0x807AD9D4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807AD9E8;
    }
    // 0x807AD9D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AD9D8: jal         0x800447C8
    // 0x807AD9DC: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x807AD9DC: nop

    after_1:
    // 0x807AD9E0: b           L_807ADA54
    // 0x807AD9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807ADA54;
    // 0x807AD9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AD9E8:
    // 0x807AD9E8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807AD9EC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26D8) << 16);
    // 0x807AD9F0: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(859, 0X1114) << 16);
    // 0x807AD9F4: lwc1        $f0, -0x12C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26D8));
    // 0x807AD9F8: addiu       $t6, $t6, -0x288C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(859, 0X1114));
    // 0x807AD9FC: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x807ADA00: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x807ADA04: lui         $t8, 0x807B
    ctx->r24 = S32(RELOC_HI16(859, 0X2630) << 16);
    // 0x807ADA08: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807ADA0C: addiu       $t8, $t8, -0x1370
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(859, 0X2630));
    // 0x807ADA10: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x807ADA14: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x807ADA18: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x807ADA1C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807ADA20: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807ADA24: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807ADA28: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807ADA2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807ADA30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807ADA34: jal         0x807ADA60
    // 0x807ADA38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807ADA60(rdram, ctx);
        goto after_2;
    // 0x807ADA38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x807ADA3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807ADA40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807ADA44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807ADA48: sb          $v0, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r2;
    // 0x807ADA4C: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x807ADA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807ADA54:
    // 0x807ADA54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807ADA58: jr          $ra
    // 0x807ADA5C: nop

    return;
    // 0x807ADA5C: nop

;}
RECOMP_FUNC void func_8078D218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078D21C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8078D220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078D224: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8078D228: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8078D22C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8078D230: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8078D234: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078D238: lw          $a2, -0x72B0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X72B0);
    // 0x8078D23C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8078D240: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8078D244: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8078D248: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8078D24C: lw          $v1, 0x1F4($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X1F4);
    // 0x8078D250: bne         $t9, $zero, L_8078D2AC
    if (ctx->r25 != 0) {
        // 0x8078D254: lw          $a1, 0x1F4($t8)
        ctx->r5 = MEM_W(ctx->r24, 0X1F4);
            goto L_8078D2AC;
    }
    // 0x8078D254: lw          $a1, 0x1F4($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X1F4);
    // 0x8078D258: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8078D25C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8078D260: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8078D264: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8078D268: jal         0x8004816C
    // 0x8078D26C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8004816C(rdram, ctx);
        goto after_0;
    // 0x8078D26C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8078D270: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8078D274: jal         0x8004816C
    // 0x8078D278: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x8078D278: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    after_1:
    // 0x8078D27C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8078D280: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8078D284: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8078D288: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8078D28C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8078D290: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x8078D294: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8078D298: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x8078D29C: sw          $a2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r6;
    // 0x8078D2A0: sw          $a2, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r6;
    // 0x8078D2A4: jal         0x80044658
    // 0x8078D2A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80044658(rdram, ctx);
        goto after_2;
    // 0x8078D2A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
L_8078D2AC:
    // 0x8078D2AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078D2B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078D2B4: jr          $ra
    // 0x8078D2B8: nop

    return;
    // 0x8078D2B8: nop

;}
RECOMP_FUNC void func_80046978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004697C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046980: lbu         $t6, 0x5($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X5);
    // 0x80046984: beql        $t6, $zero, L_800469A8
    if (ctx->r14 == 0) {
        // 0x80046988: lbu         $t7, 0x5($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X5);
            goto L_800469A8;
    }
    goto skip_0;
    // 0x80046988: lbu         $t7, 0x5($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X5);
    skip_0:
    // 0x8004698C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80046990: addiu       $a0, $a0, 0x730
    ctx->r4 = ADD32(ctx->r4, 0X730);
    // 0x80046994: jal         0x80071380
    // 0x80046998: addiu       $a1, $zero, 0x612
    ctx->r5 = ADD32(0, 0X612);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80046998: addiu       $a1, $zero, 0x612
    ctx->r5 = ADD32(0, 0X612);
    after_0:
    // 0x8004699C: b           L_80046A2C
    // 0x800469A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80046A2C;
    // 0x800469A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800469A4: lbu         $t7, 0x5($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X5);
L_800469A8:
    // 0x800469A8: beql        $t7, $zero, L_800469CC
    if (ctx->r15 == 0) {
        // 0x800469AC: lbu         $v0, 0x164($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X164);
            goto L_800469CC;
    }
    goto skip_1;
    // 0x800469AC: lbu         $v0, 0x164($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X164);
    skip_1:
    // 0x800469B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800469B4: addiu       $a0, $a0, 0x740
    ctx->r4 = ADD32(ctx->r4, 0X740);
    // 0x800469B8: jal         0x80071380
    // 0x800469BC: addiu       $a1, $zero, 0x619
    ctx->r5 = ADD32(0, 0X619);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x800469BC: addiu       $a1, $zero, 0x619
    ctx->r5 = ADD32(0, 0X619);
    after_1:
    // 0x800469C0: b           L_80046A2C
    // 0x800469C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80046A2C;
    // 0x800469C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800469C8: lbu         $v0, 0x164($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X164);
L_800469CC:
    // 0x800469CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800469D0: addiu       $a2, $zero, 0x27C
    ctx->r6 = ADD32(0, 0X27C);
    // 0x800469D4: beq         $v0, $zero, L_80046A14
    if (ctx->r2 == 0) {
        // 0x800469D8: nop
    
            goto L_80046A14;
    }
    // 0x800469D8: nop

    // 0x800469DC: beq         $v0, $at, L_80046A14
    if (ctx->r2 == ctx->r1) {
        // 0x800469E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80046A14;
    }
    // 0x800469E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800469E4: beq         $v0, $at, L_80046A14
    if (ctx->r2 == ctx->r1) {
        // 0x800469E8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80046A14;
    }
    // 0x800469E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800469EC: beq         $v0, $at, L_80046A14
    if (ctx->r2 == ctx->r1) {
        // 0x800469F0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80046A14;
    }
    // 0x800469F0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800469F4: beq         $v0, $at, L_80046A14
    if (ctx->r2 == ctx->r1) {
        // 0x800469F8: nop
    
            goto L_80046A14;
    }
    // 0x800469F8: nop

    // 0x800469FC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80046A00: addiu       $a0, $a0, 0x750
    ctx->r4 = ADD32(ctx->r4, 0X750);
    // 0x80046A04: jal         0x80071380
    // 0x80046A08: addiu       $a1, $zero, 0x622
    ctx->r5 = ADD32(0, 0X622);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x80046A08: addiu       $a1, $zero, 0x622
    ctx->r5 = ADD32(0, 0X622);
    after_2:
    // 0x80046A0C: b           L_80046A2C
    // 0x80046A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80046A2C;
    // 0x80046A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80046A14:
    // 0x80046A14: jal         0x80065528
    // 0x80046A18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065528(rdram, ctx);
        goto after_3;
    // 0x80046A18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x80046A1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80046A20: addiu       $t8, $a0, 0x1FC
    ctx->r24 = ADD32(ctx->r4, 0X1FC);
    // 0x80046A24: sw          $t8, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->r24;
    // 0x80046A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80046A2C:
    // 0x80046A2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046A30: jr          $ra
    // 0x80046A34: nop

    return;
    // 0x80046A34: nop

;}
RECOMP_FUNC void func_8002C6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C6F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C6FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C700: jal         0x8002C684
    // 0x8002C704: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002C684(rdram, ctx);
        goto after_0;
    // 0x8002C704: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002C708: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8002C70C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002C710: sw          $t6, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r14;
    // 0x8002C714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C71C: jr          $ra
    // 0x8002C720: nop

    return;
    // 0x8002C720: nop

;}
RECOMP_FUNC void pad_on_trigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8007FB54: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8007FB58: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8007FB5C: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x8007FB60: xor         $v0, $t7, $a1
    ctx->r2 = ctx->r15 ^ ctx->r5;
    // 0x8007FB64: jr          $ra
    // 0x8007FB68: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8007FB68: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_807A106C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A106C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x807A1070: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A1074: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(841, 0XD24) << 16);
    // 0x807A1078: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807A107C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x807A1080: lw          $v0, 0x1C64($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(841, 0XD24));
    // 0x807A1084: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x807A1088: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(841, 0XD08) << 16);
    // 0x807A108C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(841, 0XCA0) << 16);
    // 0x807A1090: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x807A1094: lbu         $a1, 0x0($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X0);
    // 0x807A1098: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x807A109C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807A10A0: lhu         $t1, 0x1C48($t1)
    ctx->r9 = MEM_HU(ctx->r9, (int16_t)RELOC_LO16(841, 0XD08));
    // 0x807A10A4: sll         $a2, $a1, 2
    ctx->r6 = S32(ctx->r5 << 2);
    // 0x807A10A8: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x807A10AC: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x807A10B0: lwc1        $f4, 0x1BE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(841, 0XCA0));
    // 0x807A10B4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(841, 0XCD4) << 16);
    // 0x807A10B8: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x807A10BC: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x807A10C0: lwc1        $f6, 0x1C14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(841, 0XCD4));
    // 0x807A10C4: jr          $ra
    // 0x807A10C8: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x807A10C8: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8057F680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F680: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8057F684: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8057F688: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8057F68C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8057F690: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8057F694: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8057F698: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8057F69C: lui         $t1, 0x8058
    ctx->r9 = S32(RELOC_HI16(399, 0X41BC) << 16);
    // 0x8057F6A0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8057F6A4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8057F6A8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8057F6AC: lw          $t1, 0x2FCC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(399, 0X41BC));
    // 0x8057F6B0: jr          $ra
    // 0x8057F6B4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8057F6B4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8003B328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B32C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B330: jal         0x8003B26C
    // 0x8003B334: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003B26C(rdram, ctx);
        goto after_0;
    // 0x8003B334: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B33C: jal         0x8003B540
    // 0x8003B340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003B540(rdram, ctx);
        goto after_1;
    // 0x8003B340: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8003B344: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B348: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003B34C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8003B350: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8003B354: addiu       $t7, $t7, -0x5A14
    ctx->r15 = ADD32(ctx->r15, -0X5A14);
    // 0x8003B358: addiu       $t8, $t8, -0x52A8
    ctx->r24 = ADD32(ctx->r24, -0X52A8);
    // 0x8003B35C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8003B360: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    // 0x8003B364: jal         0x8003AF20
    // 0x8003B368: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    func_8003AF20(rdram, ctx);
        goto after_2;
    // 0x8003B368: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    after_2:
    // 0x8003B36C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B374: jr          $ra
    // 0x8003B378: nop

    return;
    // 0x8003B378: nop

;}
RECOMP_FUNC void func_80409798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409798: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8040979C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x804097A0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x804097A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804097A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804097AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804097B0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804097B4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804097B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x804097BC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x804097C0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x804097C4: addiu       $s4, $zero, 0x20
    ctx->r20 = ADD32(0, 0X20);
L_804097C8:
    // 0x804097C8: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x804097CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x804097D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804097D4: beql        $v0, $zero, L_804097E8
    if (ctx->r2 == 0) {
        // 0x804097D8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_804097E8;
    }
    goto skip_0;
    // 0x804097D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x804097DC: jalr        $v0
    // 0x804097E0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x804097E0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x804097E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_804097E8:
    // 0x804097E8: bne         $s1, $s4, L_804097C8
    if (ctx->r17 != ctx->r20) {
        // 0x804097EC: addiu       $s0, $s0, 0x30
        ctx->r16 = ADD32(ctx->r16, 0X30);
            goto L_804097C8;
    }
    // 0x804097EC: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x804097F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x804097F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804097F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804097FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80409800: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80409804: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80409808: jr          $ra
    // 0x8040980C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8040980C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806E96C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E96C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E96CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E96D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806E96D4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x806E96D8: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x806E96DC: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806E96E0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806E96E4: bgtzl       $t6, L_806E973C
    if (SIGNED(ctx->r14) > 0) {
        // 0x806E96E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E973C;
    }
    goto skip_0;
    // 0x806E96E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806E96EC: bnel        $v0, $at, L_806E973C
    if (ctx->r2 != ctx->r1) {
        // 0x806E96F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E973C;
    }
    goto skip_1;
    // 0x806E96F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806E96F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806E96F8: lwc1        $f6, 0xC8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x806E96FC: lui         $t9, 0x806F
    ctx->r25 = S32(RELOC_HI16(667, 0XFE0) << 16);
    // 0x806E9700: addiu       $t9, $t9, -0x6D70
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(667, 0XFE0));
    // 0x806E9704: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806E9708: or          $t7, $a2, $zero
    ctx->r15 = ctx->r6 | 0;
    // 0x806E970C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x806E9710: bc1fl       L_806E973C
    if (!c1cs) {
        // 0x806E9714: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E973C;
    }
    goto skip_2;
    // 0x806E9714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806E9718: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x806E971C: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x806E9720: lw          $a2, 0x4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4);
    // 0x806E9724: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x806E9728: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x806E972C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x806E9730: jal         0x806E93E4
    // 0x806E9734: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_806E93E4(rdram, ctx);
        goto after_0;
    // 0x806E9734: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x806E9738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806E973C:
    // 0x806E973C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E9740: jr          $ra
    // 0x806E9744: nop

    return;
    // 0x806E9744: nop

;}
RECOMP_FUNC void func_80699EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699F00: jal         0x80699C60
    // 0x80699F04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80699C60(rdram, ctx);
        goto after_0;
    // 0x80699F04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80699F08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80699F0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80699F10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80699F14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80699F18: jal         0x8069A0F0
    // 0x80699F1C: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    func_8069A0F0(rdram, ctx);
        goto after_1;
    // 0x80699F1C: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    after_1:
    // 0x80699F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699F28: jr          $ra
    // 0x80699F2C: nop

    return;
    // 0x80699F2C: nop

;}
RECOMP_FUNC void func_805D81A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D81A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805D81AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D81B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D81B4: jal         0x8004700C
    // 0x805D81B8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D81B8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D81BC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x805D81C0: beq         $v0, $zero, L_805D835C
    if (ctx->r2 == 0) {
        // 0x805D81C4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805D835C;
    }
    // 0x805D81C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805D81C8: lw          $t6, 0x1F4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1F4);
    // 0x805D81CC: lh          $t7, 0x22($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X22);
    // 0x805D81D0: beql        $t7, $zero, L_805D8360
    if (ctx->r15 == 0) {
        // 0x805D81D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D8360;
    }
    goto skip_0;
    // 0x805D81D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805D81D8: lw          $v1, 0x174($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X174);
    // 0x805D81DC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x805D81E0: lbu         $t9, 0x77($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X77);
    // 0x805D81E4: beql        $t9, $zero, L_805D8360
    if (ctx->r25 == 0) {
        // 0x805D81E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D8360;
    }
    goto skip_1;
    // 0x805D81E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805D81EC: lw          $a0, 0x174($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X174);
    // 0x805D81F0: lbu         $t1, 0x10($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X10);
    // 0x805D81F4: lbu         $t0, 0x10($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X10);
    // 0x805D81F8: bnel        $t0, $t1, L_805D8360
    if (ctx->r8 != ctx->r9) {
        // 0x805D81FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D8360;
    }
    goto skip_2;
    // 0x805D81FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805D8200: lw          $t2, 0x174($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X174);
    // 0x805D8204: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x805D8208: lh          $t4, 0xA($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XA);
    // 0x805D820C: lw          $t3, 0x70($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X70);
    // 0x805D8210: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x805D8214: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x805D8218: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805D821C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x805D8220: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x805D8224: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x805D8228: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x805D822C: lw          $t5, 0x70($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X70);
    // 0x805D8230: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x805D8234: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x805D8238: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805D823C: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x805D8240: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x805D8244: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805D8248: lwc1        $f8, 0x84($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X84);
    // 0x805D824C: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805D8250: jal         0x80065954
    // 0x805D8254: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x805D8254: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x805D8258: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805D825C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x805D8260: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x805D8264: add.s       $f2, $f18, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x805D8268: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805D826C: nop

    // 0x805D8270: bc1fl       L_805D8360
    if (!c1cs) {
        // 0x805D8274: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D8360;
    }
    goto skip_3;
    // 0x805D8274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x805D8278: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x805D827C: nop

    // 0x805D8280: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x805D8284: nop

    // 0x805D8288: bc1fl       L_805D82FC
    if (!c1cs) {
        // 0x805D828C: lwc1        $f0, 0xC4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_805D82FC;
    }
    goto skip_4;
    // 0x805D828C: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    skip_4:
    // 0x805D8290: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x805D8294: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x805D8298: nop

    // 0x805D829C: bc1fl       L_805D8360
    if (!c1cs) {
        // 0x805D82A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D8360;
    }
    goto skip_5;
    // 0x805D82A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x805D82A4: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    // 0x805D82A8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805D82AC: bne         $t7, $at, L_805D82EC
    if (ctx->r15 != ctx->r1) {
        // 0x805D82B0: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_805D82EC;
    }
    // 0x805D82B0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805D82B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805D82B8: lwc1        $f4, 0xDC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x805D82BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D82C0: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x805D82C4: lw          $a1, 0x138($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X138);
    // 0x805D82C8: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x805D82CC: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    // 0x805D82D0: jal         0x8001D808
    // 0x805D82D4: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    func_8001D808(rdram, ctx);
        goto after_2;
    // 0x805D82D4: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x805D82D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805D82DC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x805D82E0: sw          $v0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r2;
    // 0x805D82E4: b           L_805D835C
    // 0x805D82E8: sw          $v0, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r2;
        goto L_805D835C;
    // 0x805D82E8: sw          $v0, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r2;
L_805D82EC:
    // 0x805D82EC: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x805D82F0: b           L_805D835C
    // 0x805D82F4: swc1        $f10, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f10.u32l;
        goto L_805D835C;
    // 0x805D82F4: swc1        $f10, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f10.u32l;
    // 0x805D82F8: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
L_805D82FC:
    // 0x805D82FC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x805D8300: nop

    // 0x805D8304: bc1fl       L_805D8360
    if (!c1cs) {
        // 0x805D8308: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D8360;
    }
    goto skip_6;
    // 0x805D8308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x805D830C: lbu         $t8, 0x18($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18);
    // 0x805D8310: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805D8314: bne         $t8, $at, L_805D8350
    if (ctx->r24 != ctx->r1) {
        // 0x805D8318: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_805D8350;
    }
    // 0x805D8318: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805D831C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805D8320: lwc1        $f16, 0xDC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x805D8324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D8328: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x805D832C: lw          $a1, 0x138($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X138);
    // 0x805D8330: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x805D8334: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x805D8338: jal         0x8001D808
    // 0x805D833C: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
    func_8001D808(rdram, ctx);
        goto after_3;
    // 0x805D833C: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x805D8340: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x805D8344: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805D8348: b           L_805D835C
    // 0x805D834C: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
        goto L_805D835C;
    // 0x805D834C: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
L_805D8350:
    // 0x805D8350: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x805D8354: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x805D8358: swc1        $f8, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f8.u32l;
L_805D835C:
    // 0x805D835C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D8360:
    // 0x805D8360: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D8364: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805D8368: jr          $ra
    // 0x805D836C: nop

    return;
    // 0x805D836C: nop

;}
RECOMP_FUNC void func_805348E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805348E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805348E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805348EC: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x805348F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805348F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805348F8: beq         $v0, $zero, L_80534910
    if (ctx->r2 == 0) {
        // 0x805348FC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80534910;
    }
    // 0x805348FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80534900: jal         0x805350A0
    // 0x80534904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805350A0(rdram, ctx);
        goto after_0;
    // 0x80534904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80534908: jal         0x8053484C
    // 0x8053490C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8053484C(rdram, ctx);
        goto after_1;
    // 0x8053490C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80534910:
    // 0x80534910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80534914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80534918: jr          $ra
    // 0x8053491C: nop

    return;
    // 0x8053491C: nop

;}
RECOMP_FUNC void func_8067FE64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067FE64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067FE68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067FE6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067FE70: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067FE74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067FE78: jal         0x8004700C
    // 0x8067FE7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8067FE7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8067FE80: beq         $v0, $zero, L_8067FF30
    if (ctx->r2 == 0) {
        // 0x8067FE84: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8067FF30;
    }
    // 0x8067FE84: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8067FE88: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8067FE8C: beq         $v1, $zero, L_8067FE9C
    if (ctx->r3 == 0) {
        // 0x8067FE90: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8067FE9C;
    }
    // 0x8067FE90: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8067FE94: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8067FE98: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8067FE9C:
    // 0x8067FE9C: bnel        $v1, $zero, L_8067FF34
    if (ctx->r3 != 0) {
        // 0x8067FEA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8067FF34;
    }
    goto skip_0;
    // 0x8067FEA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8067FEA4: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8067FEA8: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8067FEAC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8067FEB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067FEB4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8067FEB8: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x8067FEBC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8067FEC0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8067FEC4: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8067FEC8: nop

    // 0x8067FECC: bc1fl       L_8067FF34
    if (!c1cs) {
        // 0x8067FED0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8067FF34;
    }
    goto skip_1;
    // 0x8067FED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8067FED4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8067FED8: lw          $t8, -0x77F0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X77F0);
    // 0x8067FEDC: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x8067FEE0: slti        $at, $t9, 0x96
    ctx->r1 = SIGNED(ctx->r25) < 0X96 ? 1 : 0;
    // 0x8067FEE4: beql        $at, $zero, L_8067FF34
    if (ctx->r1 == 0) {
        // 0x8067FEE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8067FF34;
    }
    goto skip_2;
    // 0x8067FEE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8067FEEC: jal         0x80047090
    // 0x8067FEF0: addiu       $a0, $zero, 0x4718
    ctx->r4 = ADD32(0, 0X4718);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x8067FEF0: addiu       $a0, $zero, 0x4718
    ctx->r4 = ADD32(0, 0X4718);
    after_1:
    // 0x8067FEF4: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8067FEF8: beq         $v0, $at, L_8067FF30
    if (ctx->r2 == ctx->r1) {
        // 0x8067FEFC: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8067FF30;
    }
    // 0x8067FEFC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8067FF00: lui         $at, 0x4718
    ctx->r1 = S32(0X4718 << 16);
    // 0x8067FF04: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x8067FF08: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x8067FF0C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x8067FF10: jal         0x8004613C
    // 0x8067FF14: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x8067FF14: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    after_2:
    // 0x8067FF18: beq         $v0, $zero, L_8067FF30
    if (ctx->r2 == 0) {
        // 0x8067FF1C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8067FF30;
    }
    // 0x8067FF1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8067FF20: jal         0x8067FF44
    // 0x8067FF24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8067FF44(rdram, ctx);
        goto after_3;
    // 0x8067FF24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x8067FF28: jal         0x80044194
    // 0x8067FF2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80044194(rdram, ctx);
        goto after_4;
    // 0x8067FF2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
L_8067FF30:
    // 0x8067FF30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067FF34:
    // 0x8067FF34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067FF38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8067FF3C: jr          $ra
    // 0x8067FF40: nop

    return;
    // 0x8067FF40: nop

;}
RECOMP_FUNC void func_80065CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065CD8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80065CDC: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80065CE0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80065CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065CE8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80065CEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80065CF0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065CF4: jal         0x80065954
    // 0x80065CF8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80065CF8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x80065CFC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80065D00: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80065D04: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80065D08: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80065D0C: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80065D10: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    // 0x80065D14: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80065D18: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80065D1C: jal         0x80065954
    // 0x80065D20: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80065D20: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x80065D24: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80065D28: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80065D2C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80065D30: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80065D34: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80065D38: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x80065D3C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80065D40: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80065D44: jal         0x80065954
    // 0x80065D48: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80065D48: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_2:
    // 0x80065D4C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80065D50: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80065D54: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x80065D58: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80065D5C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80065D60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80065D64: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80065D68: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80065D6C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80065D70: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80065D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065D78: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80065D7C: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x80065D80: nop

    // 0x80065D84: bc1f        L_80065D90
    if (!c1cs) {
        // 0x80065D88: nop
    
            goto L_80065D90;
    }
    // 0x80065D88: nop

    // 0x80065D8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80065D90:
    // 0x80065D90: beql        $v1, $zero, L_80065DDC
    if (ctx->r3 == 0) {
        // 0x80065D94: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80065DDC;
    }
    goto skip_0;
    // 0x80065D94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x80065D98: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80065D9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80065DA0: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x80065DA4: nop

    // 0x80065DA8: bc1f        L_80065DB4
    if (!c1cs) {
        // 0x80065DAC: nop
    
            goto L_80065DB4;
    }
    // 0x80065DAC: nop

    // 0x80065DB0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80065DB4:
    // 0x80065DB4: beql        $v1, $zero, L_80065DDC
    if (ctx->r3 == 0) {
        // 0x80065DB8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80065DDC;
    }
    goto skip_1;
    // 0x80065DB8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x80065DBC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80065DC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80065DC4: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80065DC8: nop

    // 0x80065DCC: bc1fl       L_80065DDC
    if (!c1cs) {
        // 0x80065DD0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80065DDC;
    }
    goto skip_2;
    // 0x80065DD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_2:
    // 0x80065DD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80065DD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80065DDC:
    // 0x80065DDC: jr          $ra
    // 0x80065DE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80065DE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_807AA3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AA3A0: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x807AA3A4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x807AA3A8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x807AA3AC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x807AA3B0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x807AA3B4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x807AA3B8: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x807AA3BC: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x807AA3C0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x807AA3C4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x807AA3C8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x807AA3CC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x807AA3D0: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x807AA3D4: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
    // 0x807AA3D8: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x807AA3DC: lwc1        $f30, 0x6C($a0)
    ctx->f30.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807AA3E0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x807AA3E4: swc1        $f4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f4.u32l;
    // 0x807AA3E8: lwc1        $f22, 0x50($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807AA3EC: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x807AA3F0: jal         0x80066DE4
    // 0x807AA3F4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x807AA3F4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x807AA3F8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x807AA3FC: jal         0x80066E88
    // 0x807AA400: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x807AA400: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x807AA404: lw          $t6, 0x174($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X174);
    // 0x807AA408: lwc1        $f16, 0x88($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X88);
    // 0x807AA40C: lw          $a2, 0xE8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE8);
    // 0x807AA410: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x807AA414: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x807AA418: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807AA41C: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x807AA420: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x807AA424: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x807AA428: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x807AA42C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807AA430: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x807AA434: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807AA438: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x807AA43C: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x807AA440: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x807AA444: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x807AA448: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x807AA44C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x807AA450: lwc1        $f18, 0x84($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X84);
    // 0x807AA454: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807AA458: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    // 0x807AA45C: lwc1        $f6, 0x88($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X88);
    // 0x807AA460: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807AA464: mul.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x807AA468: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x807AA46C: lw          $a1, 0x1F4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X1F4);
    // 0x807AA470: mul.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x807AA474: addiu       $s1, $a1, 0x4
    ctx->r17 = ADD32(ctx->r5, 0X4);
    // 0x807AA478: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    // 0x807AA47C: jal         0x80049018
    // 0x807AA480: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x807AA480: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x807AA484: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x807AA488: beq         $v0, $zero, L_807AA4BC
    if (ctx->r2 == 0) {
        // 0x807AA48C: lwc1        $f14, 0x88($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X88);
            goto L_807AA4BC;
    }
    // 0x807AA48C: lwc1        $f14, 0x88($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X88);
    // 0x807AA490: lw          $t0, 0x174($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X174);
    // 0x807AA494: lwc1        $f18, 0x84($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X84);
    // 0x807AA498: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x807AA49C: lh          $t2, 0x4($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4);
    // 0x807AA4A0: lw          $t1, 0x70($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X70);
    // 0x807AA4A4: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x807AA4A8: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x807AA4AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807AA4B0: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x807AA4B4: b           L_807AA4E4
    // 0x807AA4B8: sub.s       $f28, $f18, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = ctx->f18.fl - ctx->f16.fl;
        goto L_807AA4E4;
    // 0x807AA4B8: sub.s       $f28, $f18, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = ctx->f18.fl - ctx->f16.fl;
L_807AA4BC:
    // 0x807AA4BC: lw          $t3, 0x174($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X174);
    // 0x807AA4C0: lwc1        $f18, 0x84($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X84);
    // 0x807AA4C4: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x807AA4C8: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x807AA4CC: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x807AA4D0: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x807AA4D4: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x807AA4D8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807AA4DC: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x807AA4E0: add.s       $f28, $f10, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f10.fl + ctx->f18.fl;
L_807AA4E4:
    // 0x807AA4E4: lbu         $t6, 0x18($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X18);
    // 0x807AA4E8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x807AA4EC: beql        $t6, $at, L_807AA5E4
    if (ctx->r14 == ctx->r1) {
        // 0x807AA4F0: lhu         $v0, 0xC($s3)
        ctx->r2 = MEM_HU(ctx->r19, 0XC);
            goto L_807AA5E4;
    }
    goto skip_0;
    // 0x807AA4F0: lhu         $v0, 0xC($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0XC);
    skip_0:
    // 0x807AA4F4: lhu         $t7, 0xC($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0XC);
    // 0x807AA4F8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807AA4FC: bne         $t7, $at, L_807AA758
    if (ctx->r15 != ctx->r1) {
        // 0x807AA500: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_807AA758;
    }
    // 0x807AA500: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807AA504: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807AA508: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807AA50C: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
    // 0x807AA510: mul.s       $f0, $f16, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x807AA514: add.s       $f24, $f12, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x807AA518: add.s       $f26, $f14, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = ctx->f14.fl + ctx->f0.fl;
L_807AA51C:
    // 0x807AA51C: swc1        $f24, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f24.u32l;
    // 0x807AA520: swc1        $f26, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f26.u32l;
    // 0x807AA524: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x807AA528: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x807AA52C: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x807AA530: mul.s       $f0, $f8, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f30.fl);
    // 0x807AA534: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x807AA538: mul.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x807AA53C: nop

    // 0x807AA540: mul.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x807AA544: nop

    // 0x807AA548: mul.s       $f18, $f2, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x807AA54C: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x807AA550: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x807AA554: nop

    // 0x807AA558: mul.s       $f18, $f2, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x807AA55C: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x807AA560: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x807AA564: sub.s       $f12, $f6, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f28.fl;
    // 0x807AA568: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x807AA56C: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x807AA570: swc1        $f12, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f12.u32l;
    // 0x807AA574: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x807AA578: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x807AA57C: jal         0x80065954
    // 0x807AA580: swc1        $f18, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f18.u32l;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x807AA580: swc1        $f18, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x807AA584: lwc1        $f16, 0xC8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x807AA588: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x807AA58C: nop

    // 0x807AA590: bc1fl       L_807AA5D0
    if (!c1cs) {
        // 0x807AA594: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_807AA5D0;
    }
    goto skip_1;
    // 0x807AA594: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x807AA598: jal         0x80065954
    // 0x807AA59C: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x807AA59C: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    after_4:
    // 0x807AA5A0: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x807AA5A4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x807AA5A8: nop

    // 0x807AA5AC: bc1f        L_807AA5CC
    if (!c1cs) {
        // 0x807AA5B0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807AA5CC;
    }
    // 0x807AA5B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807AA5B4: lw          $a1, 0xE8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE8);
    // 0x807AA5B8: addiu       $a2, $sp, 0xD4
    ctx->r6 = ADD32(ctx->r29, 0XD4);
    // 0x807AA5BC: jal         0x8002F6E4
    // 0x807AA5C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_5;
    // 0x807AA5C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x807AA5C4: b           L_807AA75C
    // 0x807AA5C8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_807AA75C;
    // 0x807AA5C8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_807AA5CC:
    // 0x807AA5CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_807AA5D0:
    // 0x807AA5D0: bne         $s0, $s2, L_807AA51C
    if (ctx->r16 != ctx->r18) {
        // 0x807AA5D4: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_807AA51C;
    }
    // 0x807AA5D4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807AA5D8: b           L_807AA75C
    // 0x807AA5DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_807AA75C;
    // 0x807AA5DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x807AA5E0: lhu         $v0, 0xC($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0XC);
L_807AA5E4:
    // 0x807AA5E4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807AA5E8: beq         $v0, $at, L_807AA758
    if (ctx->r2 == ctx->r1) {
        // 0x807AA5EC: addiu       $at, $zero, 0x4018
        ctx->r1 = ADD32(0, 0X4018);
            goto L_807AA758;
    }
    // 0x807AA5EC: addiu       $at, $zero, 0x4018
    ctx->r1 = ADD32(0, 0X4018);
    // 0x807AA5F0: beq         $v0, $at, L_807AA758
    if (ctx->r2 == ctx->r1) {
        // 0x807AA5F4: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_807AA758;
    }
    // 0x807AA5F4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807AA5F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807AA5FC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807AA600: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
    // 0x807AA604: mul.s       $f0, $f6, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f30.fl);
    // 0x807AA608: add.s       $f24, $f12, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x807AA60C: add.s       $f26, $f14, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = ctx->f14.fl + ctx->f0.fl;
L_807AA610:
    // 0x807AA610: swc1        $f24, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f24.u32l;
    // 0x807AA614: swc1        $f26, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f26.u32l;
    // 0x807AA618: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x807AA61C: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x807AA620: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x807AA624: mul.s       $f0, $f10, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x807AA628: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x807AA62C: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x807AA630: nop

    // 0x807AA634: mul.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x807AA638: nop

    // 0x807AA63C: mul.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x807AA640: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x807AA644: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x807AA648: nop

    // 0x807AA64C: mul.s       $f8, $f2, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x807AA650: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x807AA654: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x807AA658: sub.s       $f12, $f18, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f28.fl;
    // 0x807AA65C: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x807AA660: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x807AA664: swc1        $f12, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f12.u32l;
    // 0x807AA668: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x807AA66C: sub.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x807AA670: jal         0x80065954
    // 0x807AA674: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    func_80065954(rdram, ctx);
        goto after_6;
    // 0x807AA674: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x807AA678: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x807AA67C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x807AA680: nop

    // 0x807AA684: bc1fl       L_807AA750
    if (!c1cs) {
        // 0x807AA688: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_807AA750;
    }
    goto skip_2;
    // 0x807AA688: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x807AA68C: jal         0x80065954
    // 0x807AA690: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    func_80065954(rdram, ctx);
        goto after_7;
    // 0x807AA690: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    after_7:
    // 0x807AA694: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x807AA698: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x807AA69C: nop

    // 0x807AA6A0: bc1fl       L_807AA750
    if (!c1cs) {
        // 0x807AA6A4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_807AA750;
    }
    goto skip_3;
    // 0x807AA6A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x807AA6A8: lhu         $t8, 0xC($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0XC);
    // 0x807AA6AC: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x807AA6B0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x807AA6B4: bne         $t8, $at, L_807AA700
    if (ctx->r24 != ctx->r1) {
        // 0x807AA6B8: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_807AA700;
    }
    // 0x807AA6B8: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x807AA6BC: lw          $v0, -0x72E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E8);
    // 0x807AA6C0: beql        $v0, $zero, L_807AA704
    if (ctx->r2 == 0) {
        // 0x807AA6C4: lwc1        $f18, 0x3C($s3)
        ctx->f18.u32l = MEM_W(ctx->r19, 0X3C);
            goto L_807AA704;
    }
    goto skip_4;
    // 0x807AA6C4: lwc1        $f18, 0x3C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X3C);
    skip_4:
    // 0x807AA6C8: lw          $s0, 0x1F4($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X1F4);
    // 0x807AA6CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807AA6D0: jalr        $v0
    // 0x807AA6D4: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x807AA6D4: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    after_8:
    // 0x807AA6D8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x807AA6DC: lw          $a1, 0x34($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X34);
    // 0x807AA6E0: lw          $a2, 0x38($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X38);
    // 0x807AA6E4: jal         0x80067D5C
    // 0x807AA6E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_80067D5C(rdram, ctx);
        goto after_9;
    // 0x807AA6E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_9:
    // 0x807AA6EC: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x807AA6F0: jal         0x80067818
    // 0x807AA6F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x807AA6F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x807AA6F8: b           L_807AA73C
    // 0x807AA6FC: nop

        goto L_807AA73C;
    // 0x807AA6FC: nop

L_807AA700:
    // 0x807AA700: lwc1        $f18, 0x3C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X3C);
L_807AA704:
    // 0x807AA704: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(853, 0X1C00) << 16);
    // 0x807AA708: lwc1        $f8, -0x47C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(853, 0X1C00));
    // 0x807AA70C: swc1        $f18, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f18.u32l;
    // 0x807AA710: lwc1        $f16, 0x40($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X40);
    // 0x807AA714: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x807AA718: swc1        $f8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f8.u32l;
    // 0x807AA71C: swc1        $f16, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f16.u32l;
    // 0x807AA720: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x807AA724: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x807AA728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807AA72C: lw          $t9, 0x18($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X18);
    // 0x807AA730: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x807AA734: jalr        $t9
    // 0x807AA738: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x807AA738: nop

    after_11:
L_807AA73C:
    // 0x807AA73C: jal         0x800447C8
    // 0x807AA740: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800447C8(rdram, ctx);
        goto after_12;
    // 0x807AA740: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x807AA744: b           L_807AA75C
    // 0x807AA748: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_807AA75C;
    // 0x807AA748: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x807AA74C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_807AA750:
    // 0x807AA750: bne         $s0, $s2, L_807AA610
    if (ctx->r16 != ctx->r18) {
        // 0x807AA754: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_807AA610;
    }
    // 0x807AA754: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_807AA758:
    // 0x807AA758: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_807AA75C:
    // 0x807AA75C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x807AA760: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x807AA764: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x807AA768: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x807AA76C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x807AA770: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x807AA774: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x807AA778: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x807AA77C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x807AA780: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x807AA784: jr          $ra
    // 0x807AA788: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x807AA788: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_80076B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B44: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80076B48: jr          $ra
    // 0x80076B4C: nop

    return;
    // 0x80076B4C: nop

;}
RECOMP_FUNC void func_80069508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069508: blez        $a2, L_80069584
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8006950C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80069584;
    }
    // 0x8006950C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80069510: andi        $t1, $a2, 0x3
    ctx->r9 = ctx->r6 & 0X3;
    // 0x80069514: beq         $t1, $zero, L_80069544
    if (ctx->r9 == 0) {
        // 0x80069518: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_80069544;
    }
    // 0x80069518: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8006951C: sll         $t6, $zero, 1
    ctx->r14 = S32(0 << 1);
    // 0x80069520: addu        $a3, $a1, $t6
    ctx->r7 = ADD32(ctx->r5, ctx->r14);
    // 0x80069524: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80069528:
    // 0x80069528: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x8006952C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80069530: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80069534: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80069538: bne         $t0, $v0, L_80069528
    if (ctx->r8 != ctx->r2) {
        // 0x8006953C: sb          $t7, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r15;
            goto L_80069528;
    }
    // 0x8006953C: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
    // 0x80069540: beq         $v0, $a2, L_80069584
    if (ctx->r2 == ctx->r6) {
        // 0x80069544: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_80069584;
    }
L_80069544:
    // 0x80069544: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80069548: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x8006954C: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x80069550: addu        $a3, $a1, $t8
    ctx->r7 = ADD32(ctx->r5, ctx->r24);
    // 0x80069554: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
L_80069558:
    // 0x80069558: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x8006955C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80069560: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80069564: sb          $t2, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r10;
    // 0x80069568: lh          $t3, -0x6($a3)
    ctx->r11 = MEM_H(ctx->r7, -0X6);
    // 0x8006956C: sb          $t3, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r11;
    // 0x80069570: lh          $t4, -0x4($a3)
    ctx->r12 = MEM_H(ctx->r7, -0X4);
    // 0x80069574: sb          $t4, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r12;
    // 0x80069578: lh          $t5, -0x2($a3)
    ctx->r13 = MEM_H(ctx->r7, -0X2);
    // 0x8006957C: bne         $a3, $t0, L_80069558
    if (ctx->r7 != ctx->r8) {
        // 0x80069580: sb          $t5, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r13;
            goto L_80069558;
    }
    // 0x80069580: sb          $t5, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r13;
L_80069584:
    // 0x80069584: jr          $ra
    // 0x80069588: nop

    return;
    // 0x80069588: nop

;}
RECOMP_FUNC void func_8000D398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D398: addiu       $t6, $a2, -0xF2
    ctx->r14 = ADD32(ctx->r6, -0XF2);
    // 0x8000D39C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000D3A0: sltiu       $at, $t6, 0xE
    ctx->r1 = ctx->r14 < 0XE ? 1 : 0;
    // 0x8000D3A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D3A8: beq         $at, $zero, L_8000D560
    if (ctx->r1 == 0) {
        // 0x8000D3AC: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8000D560;
    }
    // 0x8000D3AC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8000D3B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000D3B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000D3B8: addu        $at, $at, $t6
    gpr jr_addend_8000D3C0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000D3BC: lw          $t6, -0x4290($at)
    ctx->r14 = ADD32(ctx->r1, -0X4290);
    // 0x8000D3C0: jr          $t6
    // 0x8000D3C4: nop

    switch (jr_addend_8000D3C0 >> 2) {
        case 0: goto L_8000D520; break;
        case 1: goto L_8000D520; break;
        case 2: goto L_8000D520; break;
        case 3: goto L_8000D4CC; break;
        case 4: goto L_8000D4BC; break;
        case 5: goto L_8000D474; break;
        case 6: goto L_8000D444; break;
        case 7: goto L_8000D4CC; break;
        case 8: goto L_8000D4CC; break;
        case 9: goto L_8000D4CC; break;
        case 10: goto L_8000D410; break;
        case 11: goto L_8000D3F8; break;
        case 12: goto L_8000D408; break;
        case 13: goto L_8000D3C8; break;
        default: switch_error(__func__, 0x8000D3C0, 0x800ABD70);
    }
    // 0x8000D3C4: nop

L_8000D3C8:
    // 0x8000D3C8: lbu         $v0, 0x18($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X18);
    // 0x8000D3CC: bne         $v0, $zero, L_8000D3DC
    if (ctx->r2 != 0) {
        // 0x8000D3D0: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_8000D3DC;
    }
    // 0x8000D3D0: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8000D3D4: b           L_8000D564
    // 0x8000D3D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000D564;
    // 0x8000D3D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000D3DC:
    // 0x8000D3DC: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8000D3E0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8000D3E4: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8000D3E8: sb          $v1, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r3;
    // 0x8000D3EC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8000D3F0: b           L_8000D560
    // 0x8000D3F4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_8000D560;
    // 0x8000D3F4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_8000D3F8:
    // 0x8000D3F8: jal         0x8000DD00
    // 0x8000D3FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8000DD00(rdram, ctx);
        goto after_0;
    // 0x8000D3FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8000D400: b           L_8000D568
    // 0x8000D404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000D568;
    // 0x8000D404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000D408:
    // 0x8000D408: b           L_8000D564
    // 0x8000D40C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8000D564;
    // 0x8000D40C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000D410:
    // 0x8000D410: lbu         $v0, 0x18($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X18);
    // 0x8000D414: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8000D418: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x8000D41C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8000D420: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x8000D424: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x8000D428: lbu         $t3, 0x18($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X18);
    // 0x8000D42C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000D430: sb          $t4, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r12;
    // 0x8000D434: lw          $t5, 0x18($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X18);
    // 0x8000D438: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8000D43C: b           L_8000D560
    // 0x8000D440: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_8000D560;
    // 0x8000D440: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_8000D444:
    // 0x8000D444: lbu         $v0, 0x18($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X18);
    // 0x8000D448: addu        $t8, $a1, $v0
    ctx->r24 = ADD32(ctx->r5, ctx->r2);
    // 0x8000D44C: sb          $a3, 0x14($t8)
    MEM_B(0X14, ctx->r24) = ctx->r7;
    // 0x8000D450: lbu         $t1, 0x18($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X18);
    // 0x8000D454: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8000D458: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x8000D45C: addu        $t2, $a1, $t0
    ctx->r10 = ADD32(ctx->r5, ctx->r8);
    // 0x8000D460: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8000D464: lbu         $t3, 0x18($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X18);
    // 0x8000D468: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000D46C: b           L_8000D560
    // 0x8000D470: sb          $t4, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r12;
        goto L_8000D560;
    // 0x8000D470: sb          $t4, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r12;
L_8000D474:
    // 0x8000D474: lbu         $t5, 0x18($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X18);
    // 0x8000D478: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
    // 0x8000D47C: lbu         $t6, 0x13($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X13);
    // 0x8000D480: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000D484: sb          $t7, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r15;
    // 0x8000D488: lbu         $v0, 0x18($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X18);
    // 0x8000D48C: addu        $t8, $a1, $v0
    ctx->r24 = ADD32(ctx->r5, ctx->r2);
    // 0x8000D490: lbu         $t1, 0x13($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X13);
    // 0x8000D494: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000D498: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8000D49C: beq         $t1, $zero, L_8000D4B4
    if (ctx->r9 == 0) {
        // 0x8000D4A0: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8000D4B4;
    }
    // 0x8000D4A0: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8000D4A4: addu        $t9, $a1, $t0
    ctx->r25 = ADD32(ctx->r5, ctx->r8);
    // 0x8000D4A8: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8000D4AC: b           L_8000D560
    // 0x8000D4B0: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
        goto L_8000D560;
    // 0x8000D4B0: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_8000D4B4:
    // 0x8000D4B4: b           L_8000D560
    // 0x8000D4B8: sb          $t3, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r11;
        goto L_8000D560;
    // 0x8000D4B8: sb          $t3, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r11;
L_8000D4BC:
    // 0x8000D4BC: lbu         $t4, 0x18($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X18);
    // 0x8000D4C0: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8000D4C4: b           L_8000D560
    // 0x8000D4C8: sb          $t5, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r13;
        goto L_8000D560;
    // 0x8000D4C8: sb          $t5, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r13;
L_8000D4CC:
    // 0x8000D4CC: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x8000D4D0: bnel        $v0, $at, L_8000D4E4
    if (ctx->r2 != ctx->r1) {
        // 0x8000D4D4: addiu       $at, $zero, 0xF9
        ctx->r1 = ADD32(0, 0XF9);
            goto L_8000D4E4;
    }
    goto skip_0;
    // 0x8000D4D4: addiu       $at, $zero, 0xF9
    ctx->r1 = ADD32(0, 0XF9);
    skip_0:
    // 0x8000D4D8: lb          $t6, 0x19($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X19);
    // 0x8000D4DC: bne         $t6, $zero, L_8000D560
    if (ctx->r14 != 0) {
        // 0x8000D4E0: addiu       $at, $zero, 0xF9
        ctx->r1 = ADD32(0, 0XF9);
            goto L_8000D560;
    }
    // 0x8000D4E0: addiu       $at, $zero, 0xF9
    ctx->r1 = ADD32(0, 0XF9);
L_8000D4E4:
    // 0x8000D4E4: bnel        $v0, $at, L_8000D4F8
    if (ctx->r2 != ctx->r1) {
        // 0x8000D4E8: addiu       $at, $zero, 0xF5
        ctx->r1 = ADD32(0, 0XF5);
            goto L_8000D4F8;
    }
    goto skip_1;
    // 0x8000D4E8: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    skip_1:
    // 0x8000D4EC: lb          $t7, 0x19($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X19);
    // 0x8000D4F0: bgez        $t7, L_8000D560
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000D4F4: addiu       $at, $zero, 0xF5
        ctx->r1 = ADD32(0, 0XF5);
            goto L_8000D560;
    }
    // 0x8000D4F4: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
L_8000D4F8:
    // 0x8000D4F8: bnel        $v0, $at, L_8000D510
    if (ctx->r2 != ctx->r1) {
        // 0x8000D4FC: lw          $t1, 0x18($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X18);
            goto L_8000D510;
    }
    goto skip_2;
    // 0x8000D4FC: lw          $t1, 0x18($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X18);
    skip_2:
    // 0x8000D500: lb          $t8, 0x19($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X19);
    // 0x8000D504: bltzl       $t8, L_8000D564
    if (SIGNED(ctx->r24) < 0) {
        // 0x8000D508: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000D564;
    }
    goto skip_3;
    // 0x8000D508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8000D50C: lw          $t1, 0x18($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X18);
L_8000D510:
    // 0x8000D510: andi        $t0, $a3, 0xFFFF
    ctx->r8 = ctx->r7 & 0XFFFF;
    // 0x8000D514: addu        $t9, $t1, $t0
    ctx->r25 = ADD32(ctx->r9, ctx->r8);
    // 0x8000D518: b           L_8000D560
    // 0x8000D51C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_8000D560;
    // 0x8000D51C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_8000D520:
    // 0x8000D520: addiu       $at, $zero, 0xF3
    ctx->r1 = ADD32(0, 0XF3);
    // 0x8000D524: bnel        $v0, $at, L_8000D538
    if (ctx->r2 != ctx->r1) {
        // 0x8000D528: addiu       $at, $zero, 0xF2
        ctx->r1 = ADD32(0, 0XF2);
            goto L_8000D538;
    }
    goto skip_4;
    // 0x8000D528: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
    skip_4:
    // 0x8000D52C: lb          $t2, 0x19($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X19);
    // 0x8000D530: bne         $t2, $zero, L_8000D560
    if (ctx->r10 != 0) {
        // 0x8000D534: addiu       $at, $zero, 0xF2
        ctx->r1 = ADD32(0, 0XF2);
            goto L_8000D560;
    }
    // 0x8000D534: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
L_8000D538:
    // 0x8000D538: bnel        $v0, $at, L_8000D550
    if (ctx->r2 != ctx->r1) {
        // 0x8000D53C: lw          $t4, 0x0($a1)
        ctx->r12 = MEM_W(ctx->r5, 0X0);
            goto L_8000D550;
    }
    goto skip_5;
    // 0x8000D53C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    skip_5:
    // 0x8000D540: lb          $t3, 0x19($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X19);
    // 0x8000D544: bgezl       $t3, L_8000D564
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000D548: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000D564;
    }
    goto skip_6;
    // 0x8000D548: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x8000D54C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
L_8000D550:
    // 0x8000D550: sll         $t6, $a3, 24
    ctx->r14 = S32(ctx->r7 << 24);
    // 0x8000D554: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8000D558: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8000D55C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_8000D560:
    // 0x8000D560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000D564:
    // 0x8000D564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000D568:
    // 0x8000D568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000D56C: jr          $ra
    // 0x8000D570: nop

    return;
    // 0x8000D570: nop

;}
RECOMP_FUNC void func_80580650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580650: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580654: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80580658: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8058065C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80580660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580664: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80580668: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8058066C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80580670: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80580674: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80580678: lui         $t2, 0x8058
    ctx->r10 = S32(RELOC_HI16(399, 0X4550) << 16);
    // 0x8058067C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80580680: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80580684: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80580688: lw          $t2, 0x3360($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(399, 0X4550));
    // 0x8058068C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80580690: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80580694: jal         0x80580438
    // 0x80580698: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580438(rdram, ctx);
        goto after_0;
    // 0x80580698: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8058069C: jal         0x80580494
    // 0x805806A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80580494(rdram, ctx);
        goto after_1;
    // 0x805806A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805806A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805806A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805806AC: jr          $ra
    // 0x805806B0: nop

    return;
    // 0x805806B0: nop

;}
RECOMP_FUNC void func_804526B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804526B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804526B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804526BC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x804526C0: jal         0x804525A8
    // 0x804526C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804525A8(rdram, ctx);
        goto after_0;
    // 0x804526C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x804526C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804526CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804526D0: jr          $ra
    // 0x804526D4: nop

    return;
    // 0x804526D4: nop

;}
RECOMP_FUNC void func_8001BF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BF80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001BF84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001BF88: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001BF8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001BF90: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001BF94: lw          $a0, 0x16C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16C);
    // 0x8001BF98: addiu       $s0, $s0, -0xA
    ctx->r16 = ADD32(ctx->r16, -0XA);
    // 0x8001BF9C: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8001BFA0: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8001BFA4: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
    // 0x8001BFA8: jal         0x8001BEF0
    // 0x8001BFAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8001BEF0(rdram, ctx);
        goto after_0;
    // 0x8001BFAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001BFB0: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8001BFB4: lbu         $a3, 0x27($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X27);
    // 0x8001BFB8: bne         $at, $zero, L_8001BFDC
    if (ctx->r1 != 0) {
        // 0x8001BFBC: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8001BFDC;
    }
    // 0x8001BFBC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8001BFC0:
    // 0x8001BFC0: addiu       $s0, $v0, -0xA
    ctx->r16 = ADD32(ctx->r2, -0XA);
    // 0x8001BFC4: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8001BFC8: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8001BFCC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001BFD0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8001BFD4: beq         $at, $zero, L_8001BFC0
    if (ctx->r1 == 0) {
        // 0x8001BFD8: andi        $a3, $a3, 0xFF
        ctx->r7 = ctx->r7 & 0XFF;
            goto L_8001BFC0;
    }
    // 0x8001BFD8: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
L_8001BFDC:
    // 0x8001BFDC: bne         $a3, $zero, L_8001BFE8
    if (ctx->r7 != 0) {
        // 0x8001BFE0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8001BFE8;
    }
    // 0x8001BFE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001BFE4: addiu       $a3, $zero, 0x2D
    ctx->r7 = ADD32(0, 0X2D);
L_8001BFE8:
    // 0x8001BFE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001BFEC: jal         0x8001BE40
    // 0x8001BFF0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8001BE40(rdram, ctx);
        goto after_1;
    // 0x8001BFF0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x8001BFF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001BFF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001BFFC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8001C000: jal         0x8001BE40
    // 0x8001C004: andi        $a3, $s0, 0xFFFF
    ctx->r7 = ctx->r16 & 0XFFFF;
    func_8001BE40(rdram, ctx);
        goto after_2;
    // 0x8001C004: andi        $a3, $s0, 0xFFFF
    ctx->r7 = ctx->r16 & 0XFFFF;
    after_2:
    // 0x8001C008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C00C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C010: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001C014: jr          $ra
    // 0x8001C018: nop

    return;
    // 0x8001C018: nop

;}
RECOMP_FUNC void func_80449FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449FFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044A000: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044A004: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8044A008: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8044A00C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x8044A010: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044A014: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X133BC) << 16);
    // 0x8044A018: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044A01C: lw          $v1, 0x6CC4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CC4);
    // 0x8044A020: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x8044A024: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8044A028: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8044A02C: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8044A030: lw          $t0, 0x779C($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X133BC));
    // 0x8044A034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044A038: beql        $t0, $zero, L_8044A04C
    if (ctx->r8 == 0) {
        // 0x8044A03C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8044A04C;
    }
    goto skip_0;
    // 0x8044A03C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8044A040: jalr        $t0
    // 0x8044A044: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x8044A044: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8044A048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8044A04C:
    // 0x8044A04C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044A050: jr          $ra
    // 0x8044A054: nop

    return;
    // 0x8044A054: nop

;}
RECOMP_FUNC void func_8052C648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052C648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8052C64C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052C650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8052C654: lh          $t7, 0xF28($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XF28);
    // 0x8052C658: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8052C65C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8052C660: bnel        $t7, $at, L_8052C690
    if (ctx->r15 != ctx->r1) {
        // 0x8052C664: lw          $a0, 0x34($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X34);
            goto L_8052C690;
    }
    goto skip_0;
    // 0x8052C664: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    skip_0:
    // 0x8052C668: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8052C66C: jal         0x80067BBC
    // 0x8052C670: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8052C670: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_0:
    // 0x8052C674: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8052C678: jal         0x80067F78
    // 0x8052C67C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8052C67C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8052C680: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8052C684: b           L_8052C6AC
    // 0x8052C688: sh          $v0, 0xF28($t8)
    MEM_H(0XF28, ctx->r24) = ctx->r2;
        goto L_8052C6AC;
    // 0x8052C688: sh          $v0, 0xF28($t8)
    MEM_H(0XF28, ctx->r24) = ctx->r2;
    // 0x8052C68C: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
L_8052C690:
    // 0x8052C690: jal         0x80067BBC
    // 0x8052C694: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8052C694: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_2:
    // 0x8052C698: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8052C69C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8052C6A0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8052C6A4: jal         0x800678F0
    // 0x8052C6A8: lh          $a1, 0xF28($t9)
    ctx->r5 = MEM_H(ctx->r25, 0XF28);
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x8052C6A8: lh          $a1, 0xF28($t9)
    ctx->r5 = MEM_H(ctx->r25, 0XF28);
    after_3:
L_8052C6AC:
    // 0x8052C6AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052C6B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052C6B4: jr          $ra
    // 0x8052C6B8: nop

    return;
    // 0x8052C6B8: nop

;}
RECOMP_FUNC void func_8001D8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D8A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D8A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D8A8: jal         0x8004924C
    // 0x8001D8AC: nop

    func_8004924C(rdram, ctx);
        goto after_0;
    // 0x8001D8AC: nop

    after_0:
    // 0x8001D8B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D8B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D8B8: jr          $ra
    // 0x8001D8BC: nop

    return;
    // 0x8001D8BC: nop

;}
RECOMP_FUNC void func_8066B1C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B1C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B1C8: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8066B1CC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(514, 0X26F8) << 16);
    // 0x8066B1D0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8066B1D4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8066B1D8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8066B1DC: nop

    // 0x8066B1E0: bc1fl       L_8066B220
    if (!c1cs) {
        // 0x8066B1E4: lwc1        $f0, 0x4($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
            goto L_8066B220;
    }
    goto skip_0;
    // 0x8066B1E4: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x8066B1E8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8066B1EC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(514, 0X26F0) << 16);
    // 0x8066B1F0: lwc1        $f8, -0x2CB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(514, 0X26F0));
    // 0x8066B1F4: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8066B1F8: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(514, 0X26F4) << 16);
    // 0x8066B1FC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8066B200: nop

    // 0x8066B204: bc1f        L_8066B244
    if (!c1cs) {
        // 0x8066B208: nop
    
            goto L_8066B244;
    }
    // 0x8066B208: nop

    // 0x8066B20C: lwc1        $f10, -0x2CAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(514, 0X26F4));
    // 0x8066B210: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8066B214: jr          $ra
    // 0x8066B218: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x8066B218: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8066B21C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_8066B220:
    // 0x8066B220: lwc1        $f18, -0x2CA8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(514, 0X26F8));
    // 0x8066B224: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(514, 0X26FC) << 16);
    // 0x8066B228: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8066B22C: nop

    // 0x8066B230: bc1f        L_8066B244
    if (!c1cs) {
        // 0x8066B234: nop
    
            goto L_8066B244;
    }
    // 0x8066B234: nop

    // 0x8066B238: lwc1        $f4, -0x2CA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(514, 0X26FC));
    // 0x8066B23C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8066B240: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_8066B244:
    // 0x8066B244: jr          $ra
    // 0x8066B248: nop

    return;
    // 0x8066B248: nop

;}
RECOMP_FUNC void func_80709A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709A50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80709A54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80709A58: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80709A5C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80709A60: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80709A64: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80709A68: jal         0x807095E4
    // 0x80709A6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_807095E4(rdram, ctx);
        goto after_0;
    // 0x80709A6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80709A70: bne         $v0, $zero, L_80709B34
    if (ctx->r2 != 0) {
        // 0x80709A74: addiu       $a0, $s1, 0xC4
        ctx->r4 = ADD32(ctx->r17, 0XC4);
            goto L_80709B34;
    }
    // 0x80709A74: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    // 0x80709A78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80709A7C: jal         0x80048F84
    // 0x80709A80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80709A80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80709A84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80709A88: jal         0x80048F84
    // 0x80709A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x80709A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80709A90: jal         0x80709860
    // 0x80709A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80709860(rdram, ctx);
        goto after_3;
    // 0x80709A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80709A98: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
    // 0x80709A9C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80709AA0: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x80709AA4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80709AA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80709AAC: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x80709AB0: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
    // 0x80709AB4: jal         0x807099D8
    // 0x80709AB8: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    func_807099D8(rdram, ctx);
        goto after_4;
    // 0x80709AB8: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x80709ABC: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    // 0x80709AC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80709AC4: bnel        $t6, $zero, L_80709B00
    if (ctx->r14 != 0) {
        // 0x80709AC8: lwc1        $f4, 0x50($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
            goto L_80709B00;
    }
    goto skip_0;
    // 0x80709AC8: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
    skip_0:
    // 0x80709ACC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80709AD0: lwc1        $f16, 0x50($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X50);
    // 0x80709AD4: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80709AD8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80709ADC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80709AE0: nop

    // 0x80709AE4: bc1f        L_80709B24
    if (!c1cs) {
        // 0x80709AE8: nop
    
            goto L_80709B24;
    }
    // 0x80709AE8: nop

    // 0x80709AEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80709AF0: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x80709AF4: b           L_80709B24
    // 0x80709AF8: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
        goto L_80709B24;
    // 0x80709AF8: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x80709AFC: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
L_80709B00:
    // 0x80709B00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80709B04: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80709B08: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80709B0C: nop

    // 0x80709B10: bc1f        L_80709B24
    if (!c1cs) {
        // 0x80709B14: nop
    
            goto L_80709B24;
    }
    // 0x80709B14: nop

    // 0x80709B18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80709B1C: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80709B20: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
L_80709B24:
    // 0x80709B24: jal         0x80709744
    // 0x80709B28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80709744(rdram, ctx);
        goto after_5;
    // 0x80709B28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80709B2C: jal         0x80709620
    // 0x80709B30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80709620(rdram, ctx);
        goto after_6;
    // 0x80709B30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
L_80709B34:
    // 0x80709B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80709B38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80709B3C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80709B40: jr          $ra
    // 0x80709B44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80709B44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806B1F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1F2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806B1F30: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(601, 0X19440) << 16);
    // 0x806B1F34: lwc1        $f4, -0x5270($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(601, 0X19440));
    // 0x806B1F38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806B1F3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806B1F40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806B1F44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806B1F48: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x806B1F4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B1F50: addiu       $t6, $zero, 0x1A40
    ctx->r14 = ADD32(0, 0X1A40);
    // 0x806B1F54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B1F58: addiu       $a2, $zero, 0x1608
    ctx->r6 = ADD32(0, 0X1608);
    // 0x806B1F5C: addiu       $a3, $zero, 0x1914
    ctx->r7 = ADD32(0, 0X1914);
    // 0x806B1F60: addiu       $a1, $zero, 0x1464
    ctx->r5 = ADD32(0, 0X1464);
    // 0x806B1F64: jal         0x806B1C6C
    // 0x806B1F68: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_806B1C6C(rdram, ctx);
        goto after_0;
    // 0x806B1F68: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x806B1F6C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806B1F70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1F74: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806B1F78: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B1F7C: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x806B1F80: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x806B1F84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806B1F88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806B1F8C: jr          $ra
    // 0x806B1F90: nop

    return;
    // 0x806B1F90: nop

;}
RECOMP_FUNC void func_8040F680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040F680: lui         $v0, 0x8041
    ctx->r2 = S32(RELOC_HI16(26, 0X43C) << 16);
    // 0x8040F684: addiu       $v0, $v0, -0x544
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(26, 0X43C));
    // 0x8040F688: jr          $ra
    // 0x8040F68C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8040F68C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806AA2A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA2A4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806AA2A8: lui         $t6, 0x806B
    ctx->r14 = S32(RELOC_HI16(589, 0XAD0) << 16);
    // 0x806AA2AC: addiu       $t6, $t6, -0x5D70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(589, 0XAD0));
    // 0x806AA2B0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806AA2B4: jr          $ra
    // 0x806AA2B8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806AA2B8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80680648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680648: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8068064C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80680650: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80680654: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680658: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8068065C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80680660: jal         0x80062684
    // 0x80680664: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x80680664: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80680668: jal         0x80680540
    // 0x8068066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80680540(rdram, ctx);
        goto after_1;
    // 0x8068066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80680670: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80680674: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80680678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8068067C: lwc1        $f0, 0x8($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80680680: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80680684: nop

    // 0x80680688: bc1fl       L_806806C8
    if (!c1cs) {
        // 0x8068068C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806806C8;
    }
    goto skip_0;
    // 0x8068068C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80680690: jal         0x806804A0
    // 0x80680694: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    func_806804A0(rdram, ctx);
        goto after_2;
    // 0x80680694: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x80680698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8068069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806806A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806806A4: jal         0x80680D04
    // 0x806806A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80680D04(rdram, ctx);
        goto after_3;
    // 0x806806A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x806806AC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806806B0: jal         0x80067BBC
    // 0x806806B4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806806B4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x806806B8: addiu       $a0, $zero, 0x214
    ctx->r4 = ADD32(0, 0X214);
    // 0x806806BC: jal         0x80067818
    // 0x806806C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806806C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806806C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806806C8:
    // 0x806806C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806806CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806806D0: jr          $ra
    // 0x806806D4: nop

    return;
    // 0x806806D4: nop

;}
RECOMP_FUNC void func_80037EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037EC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037EC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037ECC: jal         0x80021958
    // 0x80037ED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80037ED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80037ED4: bne         $v0, $zero, L_80037EE4
    if (ctx->r2 != 0) {
        // 0x80037ED8: nop
    
            goto L_80037EE4;
    }
    // 0x80037ED8: nop

    // 0x80037EDC: b           L_80037F18
    // 0x80037EE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037F18;
    // 0x80037EE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037EE4:
    // 0x80037EE4: jal         0x800415FC
    // 0x80037EE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80037EE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80037EEC: beq         $v0, $zero, L_80037EFC
    if (ctx->r2 == 0) {
        // 0x80037EF0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80037EFC;
    }
    // 0x80037EF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80037EF4: b           L_80037F18
    // 0x80037EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037F18;
    // 0x80037EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037EFC:
    // 0x80037EFC: jal         0x800376A4
    // 0x80037F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800376A4(rdram, ctx);
        goto after_2;
    // 0x80037F00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80037F04: bnel        $v0, $zero, L_80037F18
    if (ctx->r2 != 0) {
        // 0x80037F08: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80037F18;
    }
    goto skip_0;
    // 0x80037F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80037F0C: b           L_80037F18
    // 0x80037F10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037F18;
    // 0x80037F10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80037F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80037F18:
    // 0x80037F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80037F20: jr          $ra
    // 0x80037F24: nop

    return;
    // 0x80037F24: nop

;}
RECOMP_FUNC void func_806AEA24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEA24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806AEA28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AEA2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AEA30: jal         0x8004700C
    // 0x806AEA34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806AEA34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806AEA38: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806AEA3C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806AEA40: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806AEA44: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x806AEA48: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x806AEA4C: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x806AEA50: addiu       $v1, $t7, 0x1
    ctx->r3 = ADD32(ctx->r15, 0X1);
    // 0x806AEA54: bne         $v1, $at, L_806AEA8C
    if (ctx->r3 != ctx->r1) {
        // 0x806AEA58: sw          $v1, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r3;
            goto L_806AEA8C;
    }
    // 0x806AEA58: sw          $v1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r3;
    // 0x806AEA5C: jal         0x80067930
    // 0x806AEA60: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    func_80067930(rdram, ctx);
        goto after_1;
    // 0x806AEA60: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    after_1:
    // 0x806AEA64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806AEA68: bne         $v0, $at, L_806AEA80
    if (ctx->r2 != ctx->r1) {
        // 0x806AEA6C: addiu       $a0, $zero, 0x67
        ctx->r4 = ADD32(0, 0X67);
            goto L_806AEA80;
    }
    // 0x806AEA6C: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x806AEA70: jal         0x80067878
    // 0x806AEA74: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_2;
    // 0x806AEA74: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    after_2:
    // 0x806AEA78: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x806AEA7C: sh          $t9, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r25;
L_806AEA80:
    // 0x806AEA80: jal         0x800677F8
    // 0x806AEA84: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800677F8(rdram, ctx);
        goto after_3;
    // 0x806AEA84: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_3:
    // 0x806AEA88: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
L_806AEA8C:
    // 0x806AEA8C: slti        $at, $v1, 0x45
    ctx->r1 = SIGNED(ctx->r3) < 0X45 ? 1 : 0;
    // 0x806AEA90: bne         $at, $zero, L_806AEAD8
    if (ctx->r1 != 0) {
        // 0x806AEA94: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_806AEAD8;
    }
    // 0x806AEA94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806AEA98: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x806AEA9C: sb          $t0, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = ctx->r8;
    // 0x806AEAA0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806AEAA4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x806AEAA8: lui         $t1, 0x806B
    ctx->r9 = S32(RELOC_HI16(595, 0XADC) << 16);
    // 0x806AEAAC: addiu       $t1, $t1, -0x17E4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(595, 0XADC));
    // 0x806AEAB0: sw          $t1, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r9;
    // 0x806AEAB4: jal         0x8002FE38
    // 0x806AEAB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8002FE38(rdram, ctx);
        goto after_4;
    // 0x806AEAB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x806AEABC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806AEAC0: sb          $t3, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r11;
    // 0x806AEAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AEAC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AEACC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806AEAD0: jal         0x806AF64C
    // 0x806AEAD4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AF64C(rdram, ctx);
        goto after_5;
    // 0x806AEAD4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
L_806AEAD8:
    // 0x806AEAD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806AEADC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AEAE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806AEAE4: jr          $ra
    // 0x806AEAE8: nop

    return;
    // 0x806AEAE8: nop

;}
RECOMP_FUNC void func_807AF8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF8BC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807AF8C0: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(868, 0XC8) << 16);
    // 0x807AF8C4: addiu       $t6, $t6, -0x948
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(868, 0XC8));
    // 0x807AF8C8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807AF8CC: jr          $ra
    // 0x807AF8D0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x807AF8D0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80023D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023D08: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x80023D0C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80023D10: beql        $t6, $zero, L_80023D2C
    if (ctx->r14 == 0) {
        // 0x80023D14: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80023D2C;
    }
    goto skip_0;
    // 0x80023D14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x80023D18: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80023D1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80023D20: jr          $ra
    // 0x80023D24: swc1        $f4, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80023D24: swc1        $f4, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f4.u32l;
    // 0x80023D28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80023D2C:
    // 0x80023D2C: nop

    // 0x80023D30: swc1        $f6, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f6.u32l;
    // 0x80023D34: jr          $ra
    // 0x80023D38: nop

    return;
    // 0x80023D38: nop

;}
RECOMP_FUNC void func_804A2650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A2650: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X309C) << 16);
    // 0x804A2654: lwc1        $f2, 0x34DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X309C));
    // 0x804A2658: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804A265C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804A2660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A2664: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x804A2668: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804A266C: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A2670: addiu       $a0, $zero, 0x276
    ctx->r4 = ADD32(0, 0X276);
    // 0x804A2674: bc1f        L_804A2698
    if (!c1cs) {
        // 0x804A2678: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_804A2698;
    }
    // 0x804A2678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804A267C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804A2680: jal         0x80067818
    // 0x804A2684: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x804A2684: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x804A2688: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X309C) << 16);
    // 0x804A268C: lwc1        $f2, 0x34DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X309C));
    // 0x804A2690: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804A2694: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
L_804A2698:
    // 0x804A2698: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804A269C: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x804A26A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804A26A4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804A26A8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x804A26AC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A26B0: nop

    // 0x804A26B4: bc1f        L_804A26C4
    if (!c1cs) {
        // 0x804A26B8: nop
    
            goto L_804A26C4;
    }
    // 0x804A26B8: nop

    // 0x804A26BC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x804A26C0: sw          $zero, -0x71E0($at)
    MEM_W(-0X71E0, ctx->r1) = 0;
L_804A26C4:
    // 0x804A26C4: jal         0x804A25E8
    // 0x804A26C8: swc1        $f0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f0.u32l;
    func_804A25E8(rdram, ctx);
        goto after_1;
    // 0x804A26C8: swc1        $f0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f0.u32l;
    after_1:
    // 0x804A26CC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x804A26D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804A26D4: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X309C) << 16);
    // 0x804A26D8: lwc1        $f2, 0x34DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X309C));
    // 0x804A26DC: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X31B0) << 16);
    // 0x804A26E0: lwc1        $f6, 0x35F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X31B0));
    // 0x804A26E4: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X309C) << 16);
    // 0x804A26E8: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x804A26EC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x804A26F0: swc1        $f2, 0x34DC($at)
    MEM_W((int16_t)RELOC_LO16(173, 0X309C), ctx->r1) = ctx->f2.u32l;
    // 0x804A26F4: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X309C) << 16);
    // 0x804A26F8: bc1fl       L_804A2708
    if (!c1cs) {
        // 0x804A26FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A2708;
    }
    goto skip_0;
    // 0x804A26FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A2700: swc1        $f0, 0x34DC($at)
    MEM_W((int16_t)RELOC_LO16(173, 0X309C), ctx->r1) = ctx->f0.u32l;
    // 0x804A2704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A2708:
    // 0x804A2708: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804A270C: jr          $ra
    // 0x804A2710: nop

    return;
    // 0x804A2710: nop

;}
RECOMP_FUNC void func_805747F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805747F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805747F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805747FC: sll         $s1, $a1, 16
    ctx->r17 = S32(ctx->r5 << 16);
    // 0x80574800: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80574804: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80574808: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8057480C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80574810: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80574814: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80574818: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8057481C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80574820: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80574824: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80574828: beq         $s1, $zero, L_805748E8
    if (ctx->r17 == 0) {
        // 0x8057482C: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_805748E8;
    }
    // 0x8057482C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80574830: addiu       $s7, $zero, 0x4001
    ctx->r23 = ADD32(0, 0X4001);
    // 0x80574834: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
    // 0x80574838: addiu       $s5, $zero, 0xB
    ctx->r21 = ADD32(0, 0XB);
    // 0x8057483C: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80574840: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80574844: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80574848:
    // 0x80574848: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8057484C: beq         $v1, $zero, L_805748E0
    if (ctx->r3 == 0) {
        // 0x80574850: nop
    
            goto L_805748E0;
    }
    // 0x80574850: nop

    // 0x80574854: beql        $s2, $v1, L_805748D8
    if (ctx->r18 == ctx->r3) {
        // 0x80574858: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_805748D8;
    }
    goto skip_0;
    // 0x80574858: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_0:
    // 0x8057485C: lh          $a1, 0x184($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X184);
    // 0x80574860: beql        $a1, $zero, L_80574884
    if (ctx->r5 == 0) {
        // 0x80574864: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_80574884;
    }
    goto skip_1;
    // 0x80574864: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80574868: jal         0x805747F4
    // 0x8057486C: addiu       $a0, $v1, 0x188
    ctx->r4 = ADD32(ctx->r3, 0X188);
    func_805747F4(rdram, ctx);
        goto after_0;
    // 0x8057486C: addiu       $a0, $v1, 0x188
    ctx->r4 = ADD32(ctx->r3, 0X188);
    after_0:
    // 0x80574870: beql        $v0, $zero, L_80574884
    if (ctx->r2 == 0) {
        // 0x80574874: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_80574884;
    }
    goto skip_2;
    // 0x80574874: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80574878: b           L_805748F0
    // 0x8057487C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_805748F0;
    // 0x8057487C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80574880: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80574884:
    // 0x80574884: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80574888: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x8057488C: bnel        $s3, $t7, L_805748D8
    if (ctx->r19 != ctx->r15) {
        // 0x80574890: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_805748D8;
    }
    goto skip_3;
    // 0x80574890: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_3:
    // 0x80574894: lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XE);
    // 0x80574898: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x8057489C: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x805748A0: beql        $s4, $v0, L_805748C4
    if (ctx->r20 == ctx->r2) {
        // 0x805748A4: lhu         $t8, 0xC($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0XC);
            goto L_805748C4;
    }
    goto skip_4;
    // 0x805748A4: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    skip_4:
    // 0x805748A8: beql        $s5, $v0, L_805748C4
    if (ctx->r21 == ctx->r2) {
        // 0x805748AC: lhu         $t8, 0xC($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0XC);
            goto L_805748C4;
    }
    goto skip_5;
    // 0x805748AC: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    skip_5:
    // 0x805748B0: beql        $v0, $zero, L_805748C4
    if (ctx->r2 == 0) {
        // 0x805748B4: lhu         $t8, 0xC($v1)
        ctx->r24 = MEM_HU(ctx->r3, 0XC);
            goto L_805748C4;
    }
    goto skip_6;
    // 0x805748B4: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
    skip_6:
    // 0x805748B8: bnel        $s6, $v0, L_805748D8
    if (ctx->r22 != ctx->r2) {
        // 0x805748BC: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_805748D8;
    }
    goto skip_7;
    // 0x805748BC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_7:
    // 0x805748C0: lhu         $t8, 0xC($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XC);
L_805748C4:
    // 0x805748C4: beql        $s7, $t8, L_805748D8
    if (ctx->r23 == ctx->r24) {
        // 0x805748C8: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_805748D8;
    }
    goto skip_8;
    // 0x805748C8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_8:
    // 0x805748CC: b           L_805748EC
    // 0x805748D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_805748EC;
    // 0x805748D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x805748D4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_805748D8:
    // 0x805748D8: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x805748DC: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
L_805748E0:
    // 0x805748E0: bne         $s1, $zero, L_80574848
    if (ctx->r17 != 0) {
        // 0x805748E4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80574848;
    }
    // 0x805748E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_805748E8:
    // 0x805748E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805748EC:
    // 0x805748EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_805748F0:
    // 0x805748F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805748F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805748F8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x805748FC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80574900: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80574904: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80574908: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8057490C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80574910: jr          $ra
    // 0x80574914: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80574914: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
