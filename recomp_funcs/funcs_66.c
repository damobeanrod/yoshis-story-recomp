#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80790D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790D90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80790D94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80790D98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80790D9C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80790DA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80790DA4: jal         0x80790CB4
    // 0x80790DA8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_80790CB4(rdram, ctx);
        goto after_0;
    // 0x80790DA8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x80790DAC: jal         0x80790A1C
    // 0x80790DB0: nop

    func_80790A1C(rdram, ctx);
        goto after_1;
    // 0x80790DB0: nop

    after_1:
    // 0x80790DB4: beq         $v0, $zero, L_80790DD4
    if (ctx->r2 == 0) {
        // 0x80790DB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80790DD4;
    }
    // 0x80790DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80790DC0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80790DC4: jal         0x8079393C
    // 0x80790DC8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80790DC8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
    // 0x80790DCC: b           L_80790E10
    // 0x80790DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80790E10;
    // 0x80790DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80790DD4:
    // 0x80790DD4: jal         0x80790714
    // 0x80790DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_3;
    // 0x80790DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80790DDC: beq         $v0, $zero, L_80790E0C
    if (ctx->r2 == 0) {
        // 0x80790DE0: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80790E0C;
    }
    // 0x80790DE0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80790DE4: lbu         $a1, 0x10($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X10);
    // 0x80790DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790DEC: jal         0x80790CD8
    // 0x80790DF0: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    func_80790CD8(rdram, ctx);
        goto after_4;
    // 0x80790DF0: sb          $a1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r5;
    after_4:
    // 0x80790DF4: bne         $v0, $zero, L_80790E0C
    if (ctx->r2 != 0) {
        // 0x80790DF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80790E0C;
    }
    // 0x80790DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790DFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80790E00: lbu         $a2, 0x27($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X27);
    // 0x80790E04: jal         0x8079393C
    // 0x80790E08: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_5;
    // 0x80790E08: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
L_80790E0C:
    // 0x80790E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80790E10:
    // 0x80790E10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80790E14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80790E18: jr          $ra
    // 0x80790E1C: nop

    return;
    // 0x80790E1C: nop

;}
RECOMP_FUNC void func_8001DD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DD60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001DD64: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001DD68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DD6C: lbu         $t7, 0x22($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X22);
    // 0x8001DD70: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8001DD74: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8001DD78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001DD7C: beql        $t6, $t7, L_8001DD94
    if (ctx->r14 == ctx->r15) {
        // 0x8001DD80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001DD94;
    }
    goto skip_0;
    // 0x8001DD80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001DD84: sb          $t6, 0x22($a1)
    MEM_B(0X22, ctx->r5) = ctx->r14;
    // 0x8001DD88: jal         0x8001DC5C
    // 0x8001DD8C: lbu         $a2, -0x764C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X764C);
    func_8001DC5C(rdram, ctx);
        goto after_0;
    // 0x8001DD8C: lbu         $a2, -0x764C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X764C);
    after_0:
    // 0x8001DD90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001DD94:
    // 0x8001DD94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001DD98: jr          $ra
    // 0x8001DD9C: nop

    return;
    // 0x8001DD9C: nop

;}
RECOMP_FUNC void func_8069E3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069E3D0: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(577, 0X834) << 16);
    // 0x8069E3D4: addiu       $v0, $v0, -0x13FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(577, 0X834));
    // 0x8069E3D8: jr          $ra
    // 0x8069E3DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8069E3DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806F7FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7FB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F7FB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F7FBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806F7FC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806F7FC4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x806F7FC8: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x806F7FCC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x806F7FD0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x806F7FD4: lw          $t9, 0x168($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X168);
    // 0x806F7FD8: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x806F7FDC: lw          $t0, 0x88($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X88);
    // 0x806F7FE0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x806F7FE4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x806F7FE8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806F7FEC: jal         0x806F7B28
    // 0x806F7FF0: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    func_806F7B28(rdram, ctx);
        goto after_0;
    // 0x806F7FF0: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    after_0:
    // 0x806F7FF4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x806F7FF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806F7FFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806F8000: jal         0x8007711C
    // 0x806F8004: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x806F8004: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806F8008: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x806F800C: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x806F8010: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x806F8014: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x806F8018: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x806F801C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x806F8020: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x806F8024: jal         0x806F7D04
    // 0x806F8028: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_806F7D04(rdram, ctx);
        goto after_2;
    // 0x806F8028: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x806F802C: lui         $a1, 0x8070
    ctx->r5 = S32(RELOC_HI16(694, 0X1A88) << 16);
    // 0x806F8030: addiu       $a1, $a1, -0x6D68
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(694, 0X1A88));
    // 0x806F8034: jal         0x806F7AE4
    // 0x806F8038: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_806F7AE4(rdram, ctx);
        goto after_3;
    // 0x806F8038: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x806F803C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806F8040: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x806F8044: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x806F8048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F804C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F8050: jr          $ra
    // 0x806F8054: nop

    return;
    // 0x806F8054: nop

;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80086EA4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80086EA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80086EAC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80086EB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80086EB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80086EB8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80086EBC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80086EC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80086EC4:
    // 0x80086EC4: bnel        $v0, $zero, L_80086ED8
    if (ctx->r2 != 0) {
        // 0x80086EC8: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_80086ED8;
    }
    goto skip_0;
    // 0x80086EC8: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x80086ECC: b           L_80086ED8
    // 0x80086ED0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_80086ED8;
    // 0x80086ED0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80086ED4: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_80086ED8:
    // 0x80086ED8: bnel        $v0, $a0, L_80086EEC
    if (ctx->r2 != ctx->r4) {
        // 0x80086EDC: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_80086EEC;
    }
    goto skip_1;
    // 0x80086EDC: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x80086EE0: b           L_80086EEC
    // 0x80086EE4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_80086EEC;
    // 0x80086EE4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80086EE8: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_80086EEC:
    // 0x80086EEC: bnel        $v0, $a1, L_80086F00
    if (ctx->r2 != ctx->r5) {
        // 0x80086EF0: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_80086F00;
    }
    goto skip_2;
    // 0x80086EF0: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x80086EF4: b           L_80086F00
    // 0x80086EF8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_80086F00;
    // 0x80086EF8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80086EFC: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_80086F00:
    // 0x80086F00: bnel        $v0, $a2, L_80086F14
    if (ctx->r2 != ctx->r6) {
        // 0x80086F04: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_80086F14;
    }
    goto skip_3;
    // 0x80086F04: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x80086F08: b           L_80086F14
    // 0x80086F0C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_80086F14;
    // 0x80086F0C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80086F10: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_80086F14:
    // 0x80086F14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80086F18: bne         $v0, $a3, L_80086EC4
    if (ctx->r2 != ctx->r7) {
        // 0x80086F1C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80086EC4;
    }
    // 0x80086F1C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80086F20: jr          $ra
    // 0x80086F24: nop

    return;
    // 0x80086F24: nop

;}
RECOMP_FUNC void func_806CD5CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD5CC: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x806CD5D0: lui         $t8, 0x806D
    ctx->r24 = S32(RELOC_HI16(604, 0X3B2C) << 16);
    // 0x806CD5D4: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C48) << 16);
    // 0x806CD5D8: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x806CD5DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806CD5E0: lbu         $t8, -0xDB4($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(604, 0X3B2C));
    // 0x806CD5E4: lwc1        $f8, -0xC98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C48));
    // 0x806CD5E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CD5EC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x806CD5F0: lw          $v1, 0x880($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X880);
    // 0x806CD5F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CD5F8: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806CD5FC: swc1        $f0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f0.u32l;
    // 0x806CD600: lw          $v1, 0x884($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X884);
    // 0x806CD604: jr          $ra
    // 0x806CD608: swc1        $f0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x806CD608: swc1        $f0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800529E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800529E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800529E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800529EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800529F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800529F4: jal         0x8005BC68
    // 0x800529F8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_8005BC68(rdram, ctx);
        goto after_0;
    // 0x800529F8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x800529FC: beq         $v0, $zero, L_80052A18
    if (ctx->r2 == 0) {
        // 0x80052A00: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80052A18;
    }
    // 0x80052A00: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80052A04: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80052A08: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80052A0C: sb          $t7, 0x75($t8)
    MEM_B(0X75, ctx->r24) = ctx->r15;
    // 0x80052A10: jal         0x80062564
    // 0x80052A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80062564(rdram, ctx);
        goto after_1;
    // 0x80052A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80052A18:
    // 0x80052A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80052A20: jr          $ra
    // 0x80052A24: nop

    return;
    // 0x80052A24: nop

;}
RECOMP_FUNC void func_80048CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048CF8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80048CFC: lw          $t6, -0x72B4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X72B4);
    // 0x80048D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048D08: bne         $t6, $zero, L_80048D20
    if (ctx->r14 != 0) {
        // 0x80048D0C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80048D20;
    }
    // 0x80048D0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80048D10: jal         0x80048CC0
    // 0x80048D14: nop

    func_80048CC0(rdram, ctx);
        goto after_0;
    // 0x80048D14: nop

    after_0:
    // 0x80048D18: b           L_80048D40
    // 0x80048D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048D40;
    // 0x80048D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048D20:
    // 0x80048D20: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80048D24: lui         $a3, 0x8005
    ctx->r7 = S32(0X8005 << 16);
    // 0x80048D28: addiu       $a3, $a3, -0x739C
    ctx->r7 = ADD32(ctx->r7, -0X739C);
    // 0x80048D2C: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x80048D30: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80048D34: jal         0x80057F74
    // 0x80048D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80057F74(rdram, ctx);
        goto after_1;
    // 0x80048D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80048D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048D40:
    // 0x80048D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048D44: jr          $ra
    // 0x80048D48: nop

    return;
    // 0x80048D48: nop

;}
RECOMP_FUNC void func_8042FAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FAE8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8042FAEC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8042FAF0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8042FAF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042FAF8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FAFC: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BA8) << 16);
    // 0x8042FB00: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8042FB04: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8042FB08: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8042FB0C: lwc1        $f10, 0x1C88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BA8));
    // 0x8042FB10: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8042FB14: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8042FB18: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
    // 0x8042FB1C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8042FB20: jr          $ra
    // 0x8042FB24: swc1        $f16, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x8042FB24: swc1        $f16, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_800310D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800310D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800310D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800310D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800310DC: jal         0x80028220
    // 0x800310E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80028220(rdram, ctx);
        goto after_0;
    // 0x800310E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800310E4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800310E8: sw          $v0, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->r2;
    // 0x800310EC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800310F0: jal         0x80065954
    // 0x800310F4: lwc1        $f12, 0xC4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XC4);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x800310F4: lwc1        $f12, 0xC4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XC4);
    after_1:
    // 0x800310F8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800310FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80031100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80031104: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80031108: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003110C: jal         0x80041214
    // 0x80031110: nop

    func_80041214(rdram, ctx);
        goto after_2;
    // 0x80031110: nop

    after_2:
    // 0x80031114: jal         0x80023EA0
    // 0x80031118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80023EA0(rdram, ctx);
        goto after_3;
    // 0x80031118: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8003111C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031124: jr          $ra
    // 0x80031128: nop

    return;
    // 0x80031128: nop

;}
RECOMP_FUNC void func_80060ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060ED8: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x80060EDC: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80060EE0: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80060EE4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80060EE8: sw          $t7, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r15;
    // 0x80060EEC: lwc1        $f6, 0x84($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X84);
    // 0x80060EF0: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80060EF4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80060EF8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80060EFC: swc1        $f8, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f8.u32l;
    // 0x80060F00: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80060F04: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80060F08: lwc1        $f16, 0x88($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X88);
    // 0x80060F0C: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80060F10: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80060F14: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x80060F18: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x80060F1C: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80060F20: lwc1        $f6, 0x8C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x80060F24: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80060F28: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80060F2C: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x80060F30: lw          $a1, 0x3C($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X3C);
    // 0x80060F34: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x80060F38: jal         0x80048114
    // 0x80060F3C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80048114(rdram, ctx);
        goto after_0;
    // 0x80060F3C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80060F40: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80060F44: jal         0x8005FBC0
    // 0x80060F48: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    func_8005FBC0(rdram, ctx);
        goto after_1;
    // 0x80060F48: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    after_1:
    // 0x80060F4C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80060F50: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x80060F54: lw          $t2, 0x40($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X40);
    // 0x80060F58: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80060F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060F64: jr          $ra
    // 0x80060F68: nop

    return;
    // 0x80060F68: nop

;}
RECOMP_FUNC void func_8002EF78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EF78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002EF7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002EF80: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002EF84: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8002EF88: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002EF8C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8002EF90: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8002EF94: addiu       $t8, $t8, -0x4078
    ctx->r24 = ADD32(ctx->r24, -0X4078);
    // 0x8002EF98: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8002EF9C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8002EFA0: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002EFA4: sw          $zero, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = 0;
    // 0x8002EFA8: addiu       $a2, $a2, -0x30B4
    ctx->r6 = ADD32(ctx->r6, -0X30B4);
    // 0x8002EFAC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8002EFB0: jal         0x800280F4
    // 0x8002EFB4: addiu       $a1, $v0, 0x80
    ctx->r5 = ADD32(ctx->r2, 0X80);
    func_800280F4(rdram, ctx);
        goto after_0;
    // 0x8002EFB4: addiu       $a1, $v0, 0x80
    ctx->r5 = ADD32(ctx->r2, 0X80);
    after_0:
    // 0x8002EFB8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002EFBC: sb          $zero, 0x21($v0)
    MEM_B(0X21, ctx->r2) = 0;
    // 0x8002EFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002EFC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002EFC8: jr          $ra
    // 0x8002EFCC: nop

    return;
    // 0x8002EFCC: nop

;}
RECOMP_FUNC void func_80554594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80554594: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80554598: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8055459C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805545A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805545A4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x805545A8: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x805545AC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805545B0: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x805545B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805545B8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x805545BC: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x805545C0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805545C4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805545C8: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x805545CC: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    // 0x805545D0: addiu       $a1, $s1, 0x6C
    ctx->r5 = ADD32(ctx->r17, 0X6C);
    // 0x805545D4: jal         0x80553FF0
    // 0x805545D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80553FF0(rdram, ctx);
        goto after_0;
    // 0x805545D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x805545DC: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    // 0x805545E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805545E4: jal         0x80048F84
    // 0x805545E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x805545E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x805545EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805545F0: jal         0x80048F84
    // 0x805545F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805545F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x805545F8: lw          $v1, 0xDF8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XDF8);
    // 0x805545FC: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4184) << 16);
    // 0x80554600: beq         $v1, $zero, L_8055460C
    if (ctx->r3 == 0) {
        // 0x80554604: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_8055460C;
    }
    // 0x80554604: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80554608: sw          $t9, 0xDF8($s0)
    MEM_W(0XDF8, ctx->r16) = ctx->r25;
L_8055460C:
    // 0x8055460C: lw          $v0, 0xDE4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDE4);
    // 0x80554610: beq         $v0, $zero, L_8055461C
    if (ctx->r2 == 0) {
        // 0x80554614: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8055461C;
    }
    // 0x80554614: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80554618: sw          $t0, 0xDE4($s0)
    MEM_W(0XDE4, ctx->r16) = ctx->r8;
L_8055461C:
    // 0x8055461C: lw          $t1, 0xDF8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XDF8);
    // 0x80554620: beql        $t1, $zero, L_80554660
    if (ctx->r9 == 0) {
        // 0x80554624: lwc1        $f0, 0xFFC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XFFC);
            goto L_80554660;
    }
    goto skip_0;
    // 0x80554624: lwc1        $f0, 0xFFC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XFFC);
    skip_0:
    // 0x80554628: lw          $v0, 0xDE4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDE4);
    // 0x8055462C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80554630: beq         $v0, $zero, L_80554650
    if (ctx->r2 == 0) {
        // 0x80554634: sra         $t2, $v0, 2
        ctx->r10 = S32(SIGNED(ctx->r2) >> 2);
            goto L_80554650;
    }
    // 0x80554634: sra         $t2, $v0, 2
    ctx->r10 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80554638: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8055463C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80554640: nop

    // 0x80554644: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80554648: b           L_805546BC
    // 0x8055464C: swc1        $f6, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f6.u32l;
        goto L_805546BC;
    // 0x8055464C: swc1        $f6, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f6.u32l;
L_80554650:
    // 0x80554650: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80554654: b           L_805546BC
    // 0x80554658: swc1        $f8, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f8.u32l;
        goto L_805546BC;
    // 0x80554658: swc1        $f8, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f8.u32l;
    // 0x8055465C: lwc1        $f0, 0xFFC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XFFC);
L_80554660:
    // 0x80554660: lwc1        $f10, 0x4CA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4184));
    // 0x80554664: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4188) << 16);
    // 0x80554668: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8055466C: nop

    // 0x80554670: bc1t        L_80554688
    if (c1cs) {
        // 0x80554674: nop
    
            goto L_80554688;
    }
    // 0x80554674: nop

    // 0x80554678: lwc1        $f16, 0x4CA8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4188));
    // 0x8055467C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80554680: nop

    // 0x80554684: bc1f        L_805546A4
    if (!c1cs) {
        // 0x80554688: lui         $at, 0x8055
        ctx->r1 = S32(RELOC_HI16(354, 0X418C) << 16);
            goto L_805546A4;
    }
L_80554688:
    // 0x80554688: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X418C) << 16);
    // 0x8055468C: lwc1        $f18, 0x4CAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X418C));
    // 0x80554690: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4190) << 16);
    // 0x80554694: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80554698: nop

    // 0x8055469C: bc1f        L_805546B0
    if (!c1cs) {
        // 0x805546A0: nop
    
            goto L_805546B0;
    }
    // 0x805546A0: nop

L_805546A4:
    // 0x805546A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805546A8: b           L_805546BC
    // 0x805546AC: swc1        $f4, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f4.u32l;
        goto L_805546BC;
    // 0x805546AC: swc1        $f4, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f4.u32l;
L_805546B0:
    // 0x805546B0: lwc1        $f6, 0x4CB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4190));
    // 0x805546B4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x805546B8: swc1        $f8, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f8.u32l;
L_805546BC:
    // 0x805546BC: jal         0x805514AC
    // 0x805546C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805514AC(rdram, ctx);
        goto after_3;
    // 0x805546C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x805546C4: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4194) << 16);
    // 0x805546C8: lwc1        $f16, 0x4CB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4194));
    // 0x805546CC: lwc1        $f10, 0x6C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x805546D0: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4198) << 16);
    // 0x805546D4: lwc1        $f18, 0x4CB8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4198));
    // 0x805546D8: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805546DC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x805546E0: nop

    // 0x805546E4: bc1fl       L_80554718
    if (!c1cs) {
        // 0x805546E8: swc1        $f0, 0x6C($s1)
        MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
            goto L_80554718;
    }
    goto skip_1;
    // 0x805546E8: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    skip_1:
    // 0x805546EC: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x805546F0: jal         0x80067BBC
    // 0x805546F4: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x805546F4: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_4:
    // 0x805546F8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x805546FC: jal         0x80067818
    // 0x80554700: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x80554700: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80554704: jal         0x800447C8
    // 0x80554708: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x80554708: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8055470C: b           L_8055483C
    // 0x80554710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8055483C;
    // 0x80554710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80554714: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
L_80554718:
    // 0x80554718: swc1        $f0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f0.u32l;
    // 0x8055471C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80554720: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80554724: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80554728: swc1        $f0, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f0.u32l;
    // 0x8055472C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80554730: swc1        $f0, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->f0.u32l;
    // 0x80554734: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80554738: swc1        $f0, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f0.u32l;
    // 0x8055473C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80554740: swc1        $f0, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f0.u32l;
    // 0x80554744: lw          $v0, 0xD54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD54);
    // 0x80554748: bne         $v0, $zero, L_80554834
    if (ctx->r2 != 0) {
        // 0x8055474C: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80554834;
    }
    // 0x8055474C: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80554750: sw          $t8, 0xD54($s0)
    MEM_W(0XD54, ctx->r16) = ctx->r24;
    // 0x80554754: jal         0x800653D8
    // 0x80554758: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x80554758: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_7:
    // 0x8055475C: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x80554760: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80554764: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80554768: lwc1        $f6, 0xDF0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XDF0);
    // 0x8055476C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80554770: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80554774: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80554778: jal         0x800653D8
    // 0x8055477C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_800653D8(rdram, ctx);
        goto after_8;
    // 0x8055477C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x80554780: andi        $t1, $v0, 0x8
    ctx->r9 = ctx->r2 & 0X8;
    // 0x80554784: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80554788: lwc1        $f4, 0x40($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8055478C: lwc1        $f6, 0xDF4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XDF4);
    // 0x80554790: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80554794: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80554798: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8055479C: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X419C) << 16);
    // 0x805547A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805547A4: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805547A8: lwc1        $f6, 0x4CBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X419C));
    // 0x805547AC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805547B0: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x805547B4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805547B8: lw          $t2, -0x76F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X76F8);
    // 0x805547BC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x805547C0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x805547C4: lwc1        $f4, 0x44($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X44);
    // 0x805547C8: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805547CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805547D0: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X41A0) << 16);
    // 0x805547D4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x805547D8: lwc1        $f8, 0x6C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x805547DC: lwc1        $f16, 0x4CC0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X41A0));
    // 0x805547E0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x805547E4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x805547E8: lwc1        $f18, 0x70($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X70);
    // 0x805547EC: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x805547F0: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x805547F4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x805547F8: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x805547FC: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x80554800: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80554804: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80554808: lw          $t9, 0x28($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X28);
    // 0x8055480C: jalr        $t9
    // 0x80554810: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x80554810: nop

    after_9:
    // 0x80554814: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x80554818: jal         0x80067BBC
    // 0x8055481C: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_10;
    // 0x8055481C: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_10:
    // 0x80554820: addiu       $a0, $zero, 0x71
    ctx->r4 = ADD32(0, 0X71);
    // 0x80554824: jal         0x80067818
    // 0x80554828: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x80554828: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x8055482C: b           L_8055483C
    // 0x80554830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8055483C;
    // 0x80554830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80554834:
    // 0x80554834: sw          $t4, 0xD54($s0)
    MEM_W(0XD54, ctx->r16) = ctx->r12;
    // 0x80554838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8055483C:
    // 0x8055483C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80554840: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80554844: jr          $ra
    // 0x80554848: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80554848: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80433024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433024: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80433028: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8043302C: lhu         $a1, 0x6C($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6C);
    // 0x80433030: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80433034: blez        $a1, L_804330EC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80433038: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_804330EC;
    }
    // 0x80433038: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8043303C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80433040:
    // 0x80433040: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80433044: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x80433048: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
L_8043304C:
    // 0x8043304C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80433050: lw          $t8, 0x188($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X188);
    // 0x80433054: bnel        $t8, $t2, L_80433068
    if (ctx->r24 != ctx->r10) {
        // 0x80433058: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80433068;
    }
    goto skip_0;
    // 0x80433058: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x8043305C: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80433060: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80433064: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80433068:
    // 0x80433068: slti        $at, $t0, 0x14
    ctx->r1 = SIGNED(ctx->r8) < 0X14 ? 1 : 0;
    // 0x8043306C: bnel        $at, $zero, L_8043304C
    if (ctx->r1 != 0) {
        // 0x80433070: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_8043304C;
    }
    goto skip_1;
    // 0x80433070: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    skip_1:
    // 0x80433074: beq         $a3, $zero, L_804330D8
    if (ctx->r7 == 0) {
        // 0x80433078: addiu       $t9, $a2, -0x1
        ctx->r25 = ADD32(ctx->r6, -0X1);
            goto L_804330D8;
    }
    // 0x80433078: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x8043307C: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80433080: beq         $at, $zero, L_804330B4
    if (ctx->r1 == 0) {
        // 0x80433084: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_804330B4;
    }
    // 0x80433084: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80433088: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8043308C: addu        $a2, $v0, $t3
    ctx->r6 = ADD32(ctx->r2, ctx->r11);
    // 0x80433090: lw          $t4, 0x20($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X20);
L_80433094:
    // 0x80433094: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80433098: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8043309C: sw          $t4, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r12;
    // 0x804330A0: lhu         $a1, 0x6C($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6C);
    // 0x804330A4: addiu       $t5, $a1, -0x1
    ctx->r13 = ADD32(ctx->r5, -0X1);
    // 0x804330A8: slt         $at, $t0, $t5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x804330AC: bnel        $at, $zero, L_80433094
    if (ctx->r1 != 0) {
        // 0x804330B0: lw          $t4, 0x20($a2)
        ctx->r12 = MEM_W(ctx->r6, 0X20);
            goto L_80433094;
    }
    goto skip_2;
    // 0x804330B0: lw          $t4, 0x20($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X20);
    skip_2:
L_804330B4:
    // 0x804330B4: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x804330B8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x804330BC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804330C0: sh          $t6, 0x6C($v0)
    MEM_H(0X6C, ctx->r2) = ctx->r14;
    // 0x804330C4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804330C8: sw          $zero, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = 0;
    // 0x804330CC: lhu         $a1, 0x6C($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6C);
    // 0x804330D0: b           L_804330E0
    // 0x804330D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
        goto L_804330E0;
    // 0x804330D4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_804330D8:
    // 0x804330D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x804330DC: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_804330E0:
    // 0x804330E0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x804330E4: bnel        $at, $zero, L_80433040
    if (ctx->r1 != 0) {
        // 0x804330E8: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80433040;
    }
    goto skip_3;
    // 0x804330E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    skip_3:
L_804330EC:
    // 0x804330EC: jr          $ra
    // 0x804330F0: nop

    return;
    // 0x804330F0: nop

;}
RECOMP_FUNC void func_806F8278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8278: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F827C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F8280: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F8284: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x806F8288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F828C: lw          $s0, 0x1F4($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X1F4);
    // 0x806F8290: bne         $v0, $t6, L_806F8378
    if (ctx->r2 != ctx->r14) {
        // 0x806F8294: lui         $t7, 0x8010
        ctx->r15 = S32(0X8010 << 16);
            goto L_806F8378;
    }
    // 0x806F8294: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x806F8298: lh          $t7, -0x7680($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X7680);
    // 0x806F829C: slti        $at, $t7, 0x24
    ctx->r1 = SIGNED(ctx->r15) < 0X24 ? 1 : 0;
    // 0x806F82A0: bnel        $at, $zero, L_806F837C
    if (ctx->r1 != 0) {
        // 0x806F82A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806F837C;
    }
    goto skip_0;
    // 0x806F82A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806F82A8: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x806F82AC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x806F82B0: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x806F82B4: beql        $t0, $zero, L_806F837C
    if (ctx->r8 == 0) {
        // 0x806F82B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806F837C;
    }
    goto skip_1;
    // 0x806F82B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x806F82BC: lw          $t1, 0x12EC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X12EC);
    // 0x806F82C0: bnel        $t1, $zero, L_806F837C
    if (ctx->r9 != 0) {
        // 0x806F82C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806F837C;
    }
    goto skip_2;
    // 0x806F82C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x806F82C8: lbu         $t2, 0x154($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X154);
    // 0x806F82CC: bnel        $t2, $zero, L_806F837C
    if (ctx->r10 != 0) {
        // 0x806F82D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806F837C;
    }
    goto skip_3;
    // 0x806F82D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x806F82D4: lbu         $t3, 0x155($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X155);
    // 0x806F82D8: bnel        $t3, $zero, L_806F837C
    if (ctx->r11 != 0) {
        // 0x806F82DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806F837C;
    }
    goto skip_4;
    // 0x806F82DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x806F82E0: lbu         $t4, 0x1F8($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1F8);
    // 0x806F82E4: bnel        $t4, $zero, L_806F837C
    if (ctx->r12 != 0) {
        // 0x806F82E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806F837C;
    }
    goto skip_5;
    // 0x806F82E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x806F82EC: lh          $t5, 0x144($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X144);
    // 0x806F82F0: beql        $v0, $t5, L_806F8304
    if (ctx->r2 == ctx->r13) {
        // 0x806F82F4: lbu         $v0, 0x12C8($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X12C8);
            goto L_806F8304;
    }
    goto skip_6;
    // 0x806F82F4: lbu         $v0, 0x12C8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X12C8);
    skip_6:
    // 0x806F82F8: b           L_806F837C
    // 0x806F82FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806F837C;
    // 0x806F82FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F8300: lbu         $v0, 0x12C8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X12C8);
L_806F8304:
    // 0x806F8304: lhu         $a0, 0x12BE($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X12BE);
    // 0x806F8308: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x806F830C: beq         $v0, $zero, L_806F8378
    if (ctx->r2 == 0) {
        // 0x806F8310: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_806F8378;
    }
    // 0x806F8310: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x806F8314: addiu       $a0, $zero, 0x4301
    ctx->r4 = ADD32(0, 0X4301);
    // 0x806F8318: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_806F831C:
    // 0x806F831C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x806F8320: addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // 0x806F8324: andi        $a1, $a1, 0x7
    ctx->r5 = ctx->r5 & 0X7;
    // 0x806F8328: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x806F832C: multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806F8330: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806F8334: mflo        $t6
    ctx->r14 = lo;
    // 0x806F8338: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x806F833C: lw          $t8, 0x11FC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X11FC);
    // 0x806F8340: lhu         $t9, 0xC($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XC);
    // 0x806F8344: bne         $a0, $t9, L_806F8370
    if (ctx->r4 != ctx->r25) {
        // 0x806F8348: nop
    
            goto L_806F8370;
    }
    // 0x806F8348: nop

    // 0x806F834C: jal         0x80040964
    // 0x806F8350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040964(rdram, ctx);
        goto after_0;
    // 0x806F8350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x806F8354: jal         0x80067E68
    // 0x806F8358: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80067E68(rdram, ctx);
        goto after_1;
    // 0x806F8358: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x806F835C: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F8360: jal         0x80067818
    // 0x806F8364: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x806F8364: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x806F8368: b           L_806F837C
    // 0x806F836C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806F837C;
    // 0x806F836C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806F8370:
    // 0x806F8370: bnel        $v0, $zero, L_806F831C
    if (ctx->r2 != 0) {
        // 0x806F8374: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_806F831C;
    }
    goto skip_7;
    // 0x806F8374: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_7:
L_806F8378:
    // 0x806F8378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F837C:
    // 0x806F837C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8380: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F8384: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F8388: jr          $ra
    // 0x806F838C: nop

    return;
    // 0x806F838C: nop

;}
RECOMP_FUNC void func_8067AD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067AD9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8067ADA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067ADA4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8067ADA8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8067ADAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8067ADB0: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x8067ADB4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067ADB8: lbu         $a2, 0x3F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3F);
    // 0x8067ADBC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067ADC0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8067ADC4: andi        $a2, $a2, 0x3F
    ctx->r6 = ctx->r6 & 0X3F;
    // 0x8067ADC8: addiu       $a2, $a2, -0x11
    ctx->r6 = ADD32(ctx->r6, -0X11);
    // 0x8067ADCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8067ADD0: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x8067ADD4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067ADD8: sll         $t8, $a2, 6
    ctx->r24 = S32(ctx->r6 << 6);
    // 0x8067ADDC: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x8067ADE0: beq         $a3, $zero, L_8067AE2C
    if (ctx->r7 == 0) {
        // 0x8067ADE4: lwc1        $f0, 0x8($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
            goto L_8067AE2C;
    }
    // 0x8067ADE4: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8067ADE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067ADEC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8067ADF0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8067ADF4: ctc1        $a3, $FpcCsr
    set_cop1_cs(ctx->r7);
    // 0x8067ADF8: nop

    // 0x8067ADFC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8067AE00: cfc1        $a3, $FpcCsr
    ctx->r7 = get_cop1_cs();
    // 0x8067AE04: nop

    // 0x8067AE08: andi        $a3, $a3, 0x78
    ctx->r7 = ctx->r7 & 0X78;
    // 0x8067AE0C: bne         $a3, $zero, L_8067AE24
    if (ctx->r7 != 0) {
        // 0x8067AE10: nop
    
            goto L_8067AE24;
    }
    // 0x8067AE10: nop

    // 0x8067AE14: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8067AE18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067AE1C: b           L_8067AE3C
    // 0x8067AE20: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
        goto L_8067AE3C;
    // 0x8067AE20: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
L_8067AE24:
    // 0x8067AE24: b           L_8067AE3C
    // 0x8067AE28: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
        goto L_8067AE3C;
    // 0x8067AE28: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8067AE2C:
    // 0x8067AE2C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8067AE30: nop

    // 0x8067AE34: bltz        $a3, L_8067AE24
    if (SIGNED(ctx->r7) < 0) {
        // 0x8067AE38: nop
    
            goto L_8067AE24;
    }
    // 0x8067AE38: nop

L_8067AE3C:
    // 0x8067AE3C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8067AE40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8067AE44: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8067AE48: andi        $a3, $a3, 0xF
    ctx->r7 = ctx->r7 & 0XF;
    // 0x8067AE4C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067AE50: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8067AE54: sltiu       $a3, $a3, 0x8
    ctx->r7 = ctx->r7 < 0X8 ? 1 : 0;
    // 0x8067AE58: xori        $a3, $a3, 0x1
    ctx->r7 = ctx->r7 ^ 0X1;
    // 0x8067AE5C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8067AE60: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067AE64: sll         $t2, $a3, 3
    ctx->r10 = S32(ctx->r7 << 3);
    // 0x8067AE68: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8067AE6C: nop

    // 0x8067AE70: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8067AE74: beql        $t0, $zero, L_8067AEC4
    if (ctx->r8 == 0) {
        // 0x8067AE78: mfc1        $t0, $f10
        ctx->r8 = (int32_t)ctx->f10.u32l;
            goto L_8067AEC4;
    }
    goto skip_0;
    // 0x8067AE78: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x8067AE7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8067AE80: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8067AE84: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8067AE88: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8067AE8C: nop

    // 0x8067AE90: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8067AE94: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8067AE98: nop

    // 0x8067AE9C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x8067AEA0: bne         $t0, $zero, L_8067AEB8
    if (ctx->r8 != 0) {
        // 0x8067AEA4: nop
    
            goto L_8067AEB8;
    }
    // 0x8067AEA4: nop

    // 0x8067AEA8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8067AEAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067AEB0: b           L_8067AED0
    // 0x8067AEB4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8067AED0;
    // 0x8067AEB4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8067AEB8:
    // 0x8067AEB8: b           L_8067AED0
    // 0x8067AEBC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8067AED0;
    // 0x8067AEBC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8067AEC0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
L_8067AEC4:
    // 0x8067AEC4: nop

    // 0x8067AEC8: bltz        $t0, L_8067AEB8
    if (SIGNED(ctx->r8) < 0) {
        // 0x8067AECC: nop
    
            goto L_8067AEB8;
    }
    // 0x8067AECC: nop

L_8067AED0:
    // 0x8067AED0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8067AED4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067AED8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8067AEDC: andi        $t0, $t0, 0xF
    ctx->r8 = ctx->r8 & 0XF;
    // 0x8067AEE0: sltiu       $t0, $t0, 0x8
    ctx->r8 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x8067AEE4: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8067AEE8: xori        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 ^ 0X1;
    // 0x8067AEEC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8067AEF0: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8067AEF4: bc1fl       L_8067AF08
    if (!c1cs) {
        // 0x8067AEF8: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8067AF08;
    }
    goto skip_1;
    // 0x8067AEF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x8067AEFC: b           L_8067AF40
    // 0x8067AF00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8067AF40;
    // 0x8067AF00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8067AF04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8067AF08:
    // 0x8067AF08: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8067AF0C: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x8067AF10: nop

    // 0x8067AF14: bc1fl       L_8067AF28
    if (!c1cs) {
        // 0x8067AF18: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8067AF28;
    }
    goto skip_2;
    // 0x8067AF18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_2:
    // 0x8067AF1C: b           L_8067AF40
    // 0x8067AF20: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8067AF40;
    // 0x8067AF20: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8067AF24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8067AF28:
    // 0x8067AF28: nop

    // 0x8067AF2C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8067AF30: nop

    // 0x8067AF34: bc1fl       L_8067AF44
    if (!c1cs) {
        // 0x8067AF38: sll         $t9, $v0, 4
        ctx->r25 = S32(ctx->r2 << 4);
            goto L_8067AF44;
    }
    goto skip_3;
    // 0x8067AF38: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    skip_3:
    // 0x8067AF3C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8067AF40:
    // 0x8067AF40: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
L_8067AF44:
    // 0x8067AF44: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8067AF48: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8067AF4C: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x8067AF50: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(541, 0X27C8) << 16);
    // 0x8067AF54: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8067AF58: lw          $t9, -0x3B88($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(541, 0X27C8));
    // 0x8067AF5C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8067AF60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8067AF64: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8067AF68: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8067AF6C: jalr        $t9
    // 0x8067AF70: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8067AF70: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8067AF74: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8067AF78: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8067AF7C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8067AF80: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8067AF84: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8067AF88: sll         $t5, $a2, 6
    ctx->r13 = S32(ctx->r6 << 6);
    // 0x8067AF8C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8067AF90: sll         $t8, $a3, 3
    ctx->r24 = S32(ctx->r7 << 3);
    // 0x8067AF94: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8067AF98: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X28C8) << 16);
    // 0x8067AF9C: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8067AFA0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8067AFA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8067AFA8: lwc1        $f6, -0x3A88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X28C8));
    // 0x8067AFAC: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    // 0x8067AFB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067AFB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8067AFB8: jr          $ra
    // 0x8067AFBC: nop

    return;
    // 0x8067AFBC: nop

;}
RECOMP_FUNC void func_8040EB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EB60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040EB64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EB68: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8040EB6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8040EB70: beq         $t6, $zero, L_8040EBF0
    if (ctx->r14 == 0) {
        // 0x8040EB74: nop
    
            goto L_8040EBF0;
    }
    // 0x8040EB74: nop

    // 0x8040EB78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040EB7C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8040EB80: jalr        $t9
    // 0x8040EB84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040EB84: nop

    after_0:
    // 0x8040EB88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040EB8C: lui         $v1, 0x8041
    ctx->r3 = S32(RELOC_HI16(23, 0XD00) << 16);
    // 0x8040EB90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8040EB94: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8040EB98: lw          $t0, 0x12C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X12C);
    // 0x8040EB9C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8040EBA0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8040EBA4: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8040EBA8: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8040EBAC: lw          $v1, -0xB60($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(23, 0XD00));
    // 0x8040EBB0: beql        $v1, $zero, L_8040EBD0
    if (ctx->r3 == 0) {
        // 0x8040EBB4: lw          $t3, 0x15C($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X15C);
            goto L_8040EBD0;
    }
    goto skip_0;
    // 0x8040EBB4: lw          $t3, 0x15C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X15C);
    skip_0:
    // 0x8040EBB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040EBBC: jalr        $v1
    // 0x8040EBC0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x8040EBC0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8040EBC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8040EBC8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8040EBCC: lw          $t3, 0x15C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X15C);
L_8040EBD0:
    // 0x8040EBD0: lw          $t5, 0x14C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14C);
    // 0x8040EBD4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8040EBD8: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8040EBDC: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8040EBE0: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x8040EBE4: lhu         $t7, 0x0($t9)
    ctx->r15 = MEM_HU(ctx->r25, 0X0);
    // 0x8040EBE8: b           L_8040EBF0
    // 0x8040EBEC: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
        goto L_8040EBF0;
    // 0x8040EBEC: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
L_8040EBF0:
    // 0x8040EBF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040EBF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040EBF8: jr          $ra
    // 0x8040EBFC: nop

    return;
    // 0x8040EBFC: nop

;}
RECOMP_FUNC void func_8007FFA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FFA4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007FFA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FFAC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8007FFB0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8007FFB4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8007FFB8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8007FFBC: jal         0x800818E8
    // 0x8007FFC0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    MtxConv_L2F(rdram, ctx);
        goto after_0;
    // 0x8007FFC0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8007FFC4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007FFC8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8007FFCC: jal         0x80080798
    // 0x8007FFD0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    func_80080798(rdram, ctx);
        goto after_1;
    // 0x8007FFD0: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x8007FFD4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8007FFD8: jal         0x800817A0
    // 0x8007FFDC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    MtxConv_F2L(rdram, ctx);
        goto after_2;
    // 0x8007FFDC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8007FFE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FFE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8007FFE8: jr          $ra
    // 0x8007FFEC: nop

    return;
    // 0x8007FFEC: nop

;}
RECOMP_FUNC void func_805844DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805844DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805844E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805844E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805844E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805844EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805844F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805844F4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805844F8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805844FC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80584500: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80584504: addiu       $t6, $zero, 0x1D4C
    ctx->r14 = ADD32(0, 0X1D4C);
    // 0x80584508: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8058450C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80584510: addiu       $a3, $zero, 0x1CD4
    ctx->r7 = ADD32(0, 0X1CD4);
    // 0x80584514: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80584518: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8058451C: jal         0x80583CCC
    // 0x80584520: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_80583CCC(rdram, ctx);
        goto after_0;
    // 0x80584520: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80584524: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80584528: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8058452C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80584530: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80584534: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80584538: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x8058453C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80584540: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80584544: jr          $ra
    // 0x80584548: nop

    return;
    // 0x80584548: nop

;}
RECOMP_FUNC void func_80534030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534030: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80534034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80534038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8053403C: jal         0x80533D14
    // 0x80534040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80533D14(rdram, ctx);
        goto after_0;
    // 0x80534040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80534044: jal         0x80533D84
    // 0x80534048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80533D84(rdram, ctx);
        goto after_1;
    // 0x80534048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8053404C: blez        $v0, L_80534060
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80534050: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80534060;
    }
    // 0x80534050: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80534054: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80534058: addiu       $t6, $t6, -0x7218
    ctx->r14 = ADD32(ctx->r14, -0X7218);
    // 0x8053405C: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
L_80534060:
    // 0x80534060: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80534064: bne         $at, $zero, L_805340AC
    if (ctx->r1 != 0) {
        // 0x80534068: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805340AC;
    }
    // 0x80534068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8053406C: jal         0x80533DD8
    // 0x80534070: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80533DD8(rdram, ctx);
        goto after_2;
    // 0x80534070: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80534074: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80534078: bne         $at, $zero, L_80534098
    if (ctx->r1 != 0) {
        // 0x8053407C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80534098;
    }
    // 0x8053407C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80534080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80534084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80534088: jal         0x805341DC
    // 0x8053408C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_805341DC(rdram, ctx);
        goto after_3;
    // 0x8053408C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x80534090: b           L_805340B0
    // 0x80534094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805340B0;
    // 0x80534094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80534098:
    // 0x80534098: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8053409C: bnel        $at, $zero, L_805340B0
    if (ctx->r1 != 0) {
        // 0x805340A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805340B0;
    }
    goto skip_0;
    // 0x805340A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805340A4: jal         0x800447C8
    // 0x805340A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x805340A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_805340AC:
    // 0x805340AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805340B0:
    // 0x805340B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805340B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805340B8: jr          $ra
    // 0x805340BC: nop

    return;
    // 0x805340BC: nop

;}
RECOMP_FUNC void func_80034A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034A70: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80034A74: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80034A78: lw          $t6, 0x78($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X78);
    // 0x80034A7C: beq         $t6, $zero, L_80034A98
    if (ctx->r14 == 0) {
        // 0x80034A80: nop
    
            goto L_80034A98;
    }
    // 0x80034A80: nop

    // 0x80034A84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034A88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034A8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034A90: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x80034A94: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
L_80034A98:
    // 0x80034A98: jr          $ra
    // 0x80034A9C: nop

    return;
    // 0x80034A9C: nop

;}
RECOMP_FUNC void func_8067AFC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067AFC0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067AFC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067AFC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067AFCC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8067AFD0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8067AFD4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8067AFD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8067AFDC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8067AFE0: beq         $v0, $t6, L_8067AFEC
    if (ctx->r2 == ctx->r14) {
        // 0x8067AFE4: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_8067AFEC;
    }
    // 0x8067AFE4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8067AFE8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8067AFEC:
    // 0x8067AFEC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x8067AFF0: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(541, 0X29C8) << 16);
    // 0x8067AFF4: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8067AFF8: lw          $t9, -0x3988($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(541, 0X29C8));
    // 0x8067AFFC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8067B000: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8067B004: jalr        $t9
    // 0x8067B008: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8067B008: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    after_0:
    // 0x8067B00C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8067B010: lui         $t7, 0x8068
    ctx->r15 = S32(RELOC_HI16(541, 0X2A48) << 16);
    // 0x8067B014: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8067B018: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8067B01C: lw          $t7, -0x3908($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(541, 0X2A48));
    // 0x8067B020: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X3D80) << 16);
    // 0x8067B024: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x8067B028: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8067B02C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8067B030: lwc1        $f6, -0x25D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X3D80));
    // 0x8067B034: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8067B038: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8067B03C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8067B040: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8067B044: jal         0x8008D250
    // 0x8067B048: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x8067B048: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8067B04C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8067B050: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8067B054: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8067B058: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8067B05C: jal         0x80082730
    // 0x8067B060: swc1        $f18, 0xC4($t8)
    MEM_W(0XC4, ctx->r24) = ctx->f18.u32l;
    fsin(rdram, ctx);
        goto after_2;
    // 0x8067B060: swc1        $f18, 0xC4($t8)
    MEM_W(0XC4, ctx->r24) = ctx->f18.u32l;
    after_2:
    // 0x8067B064: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8067B068: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8067B06C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8067B070: swc1        $f6, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->f6.u32l;
    // 0x8067B074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067B078: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067B07C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8067B080: jr          $ra
    // 0x8067B084: nop

    return;
    // 0x8067B084: nop

;}
RECOMP_FUNC void func_8040B020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040B024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B028: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8040B02C: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8040B030: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8040B034: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8040B038: bne         $v0, $at, L_8040B0A4
    if (ctx->r2 != ctx->r1) {
        // 0x8040B03C: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_8040B0A4;
    }
    // 0x8040B03C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8040B040: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040B044: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8040B048: sh          $t7, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r15;
    // 0x8040B04C: lwc1        $f6, 0x3C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x8040B050: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8040B054: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8040B058: nop

    // 0x8040B05C: bc1fl       L_8040B070
    if (!c1cs) {
        // 0x8040B060: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8040B070;
    }
    goto skip_0;
    // 0x8040B060: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x8040B064: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040B068: sh          $zero, 0x2($t9)
    MEM_H(0X2, ctx->r25) = 0;
    // 0x8040B06C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8040B070:
    // 0x8040B070: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8040B074: jal         0x8040B8E4
    // 0x8040B078: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8040B8E4(rdram, ctx);
        goto after_0;
    // 0x8040B078: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x8040B07C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8040B080: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8040B084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040B088: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x8040B08C: sb          $t0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r8;
    // 0x8040B090: jalr        $t9
    // 0x8040B094: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8040B094: nop

    after_1:
    // 0x8040B098: jal         0x8040AF20
    // 0x8040B09C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8040AF20(rdram, ctx);
        goto after_2;
    // 0x8040B09C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8040B0A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_8040B0A4:
    // 0x8040B0A4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8040B0A8: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x8040B0AC: bnel        $t1, $at, L_8040B0C0
    if (ctx->r9 != ctx->r1) {
        // 0x8040B0B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040B0C0;
    }
    goto skip_1;
    // 0x8040B0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8040B0B4: jal         0x8040B9B8
    // 0x8040B0B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8040B9B8(rdram, ctx);
        goto after_3;
    // 0x8040B0B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_3:
    // 0x8040B0BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040B0C0:
    // 0x8040B0C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040B0C4: jr          $ra
    // 0x8040B0C8: nop

    return;
    // 0x8040B0C8: nop

;}
RECOMP_FUNC void func_80033E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033E54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033E5C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80033E60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80033E64: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80033E68: jal         0x80033760
    // 0x80033E6C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80033760(rdram, ctx);
        goto after_0;
    // 0x80033E6C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80033E70: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80033E74: jal         0x80033AE4
    // 0x80033E78: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80033AE4(rdram, ctx);
        goto after_1;
    // 0x80033E78: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80033E7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80033E80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80033E84: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x80033E88: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80033E8C: jal         0x8003A6F0
    // 0x80033E90: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
    func_8003A6F0(rdram, ctx);
        goto after_2;
    // 0x80033E90: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
    after_2:
    // 0x80033E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033E98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80033E9C: jr          $ra
    // 0x80033EA0: nop

    return;
    // 0x80033EA0: nop

;}
RECOMP_FUNC void func_8076E458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076E458: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8076E45C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076E460: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8076E464: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8076E468: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076E46C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8076E470: bnel        $t6, $zero, L_8076E4D0
    if (ctx->r14 != 0) {
        // 0x8076E474: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8076E4D0;
    }
    goto skip_0;
    // 0x8076E474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8076E478: lbu         $v1, 0x18($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X18);
    // 0x8076E47C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8076E480: beql        $v1, $at, L_8076E4D0
    if (ctx->r3 == ctx->r1) {
        // 0x8076E484: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8076E4D0;
    }
    goto skip_1;
    // 0x8076E484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8076E488: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x8076E48C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8076E490: bnel        $t7, $at, L_8076E4D0
    if (ctx->r15 != ctx->r1) {
        // 0x8076E494: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8076E4D0;
    }
    goto skip_2;
    // 0x8076E494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8076E498: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8076E49C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8076E4A0: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8076E4A4: beql        $a2, $t8, L_8076E4D0
    if (ctx->r6 == ctx->r24) {
        // 0x8076E4A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8076E4D0;
    }
    goto skip_3;
    // 0x8076E4A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8076E4AC: beq         $at, $zero, L_8076E4C8
    if (ctx->r1 == 0) {
        // 0x8076E4B0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8076E4C8;
    }
    // 0x8076E4B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8076E4B4: jal         0x8076CBF0
    // 0x8076E4B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8076CBF0(rdram, ctx);
        goto after_0;
    // 0x8076E4B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8076E4BC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8076E4C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8076E4C4: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
L_8076E4C8:
    // 0x8076E4C8: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8076E4CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8076E4D0:
    // 0x8076E4D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8076E4D4: jr          $ra
    // 0x8076E4D8: nop

    return;
    // 0x8076E4D8: nop

;}
RECOMP_FUNC void func_806775AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806775AC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806775B0: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(535, 0X1C38) << 16);
    // 0x806775B4: addiu       $t6, $t6, 0x72F8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(535, 0X1C38));
    // 0x806775B8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806775BC: jr          $ra
    // 0x806775C0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806775C0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804488D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804488D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804488D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804488D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804488DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804488E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804488E4: bne         $a2, $zero, L_8044890C
    if (ctx->r6 != 0) {
        // 0x804488E8: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_8044890C;
    }
    // 0x804488E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804488EC: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x804488F0: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x804488F4: bgtz        $t7, L_8044894C
    if (SIGNED(ctx->r15) > 0) {
        // 0x804488F8: sw          $t7, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r15;
            goto L_8044894C;
    }
    // 0x804488F8: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x804488FC: jal         0x80446634
    // 0x80448900: nop

    func_80446634(rdram, ctx);
        goto after_0;
    // 0x80448900: nop

    after_0:
    // 0x80448904: b           L_80448950
    // 0x80448908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448950;
    // 0x80448908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044890C:
    // 0x8044890C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80448910: bnel        $a2, $at, L_8044893C
    if (ctx->r6 != ctx->r1) {
        // 0x80448914: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8044893C;
    }
    goto skip_0;
    // 0x80448914: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80448918: jal         0x804465DC
    // 0x8044891C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804465DC(rdram, ctx);
        goto after_1;
    // 0x8044891C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80448920: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448924: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448928: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8044892C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448930: b           L_8044894C
    // 0x80448934: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_8044894C;
    // 0x80448934: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x80448938: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8044893C:
    // 0x8044893C: bnel        $a2, $at, L_80448950
    if (ctx->r6 != ctx->r1) {
        // 0x80448940: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448950;
    }
    goto skip_1;
    // 0x80448940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80448944: jal         0x80446634
    // 0x80448948: nop

    func_80446634(rdram, ctx);
        goto after_2;
    // 0x80448948: nop

    after_2:
L_8044894C:
    // 0x8044894C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448950:
    // 0x80448950: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80448954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448958: jr          $ra
    // 0x8044895C: nop

    return;
    // 0x8044895C: nop

;}
RECOMP_FUNC void func_8042C9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C9FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8042CA00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042CA04: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8042CA08: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8042CA0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042CA10: jal         0x8004700C
    // 0x8042CA14: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8042CA14: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8042CA18: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3060) << 16);
    // 0x8042CA1C: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x8042CA20: lwc1        $f0, -0x2700($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3060));
    // 0x8042CA24: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8042CA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042CA2C: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // 0x8042CA30: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8042CA34: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8042CA38: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8042CA3C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8042CA40: beq         $v0, $zero, L_8042CA60
    if (ctx->r2 == 0) {
        // 0x8042CA44: swc1        $f10, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
            goto L_8042CA60;
    }
    // 0x8042CA44: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8042CA48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042CA4C: addiu       $a1, $v0, 0x84
    ctx->r5 = ADD32(ctx->r2, 0X84);
    // 0x8042CA50: jal         0x8042BD04
    // 0x8042CA54: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8042BD04(rdram, ctx);
        goto after_1;
    // 0x8042CA54: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x8042CA58: b           L_8042CA6C
    // 0x8042CA5C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
        goto L_8042CA6C;
    // 0x8042CA5C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_8042CA60:
    // 0x8042CA60: jal         0x8042BD04
    // 0x8042CA64: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8042BD04(rdram, ctx);
        goto after_2;
    // 0x8042CA64: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x8042CA68: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_8042CA6C:
    // 0x8042CA6C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8042CA70: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8042CA74: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8042CA78: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x8042CA7C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042CA80: jal         0x8042A9DC
    // 0x8042CA84: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_8042A9DC(rdram, ctx);
        goto after_3;
    // 0x8042CA84: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x8042CA88: jal         0x8042BB3C
    // 0x8042CA8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BB3C(rdram, ctx);
        goto after_4;
    // 0x8042CA8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8042CA90: jal         0x8042BA84
    // 0x8042CA94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BA84(rdram, ctx);
        goto after_5;
    // 0x8042CA94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8042CA98: lh          $t7, 0x144($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X144);
    // 0x8042CA9C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8042CAA0: bne         $t7, $at, L_8042CAB8
    if (ctx->r15 != ctx->r1) {
        // 0x8042CAA4: nop
    
            goto L_8042CAB8;
    }
    // 0x8042CAA4: nop

    // 0x8042CAA8: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042CAAC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8042CAB0: b           L_8042CAC0
    // 0x8042CAB4: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
        goto L_8042CAC0;
    // 0x8042CAB4: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
L_8042CAB8:
    // 0x8042CAB8: jal         0x8042B810
    // 0x8042CABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042B810(rdram, ctx);
        goto after_6;
    // 0x8042CABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_8042CAC0:
    // 0x8042CAC0: jal         0x8042B410
    // 0x8042CAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042B410(rdram, ctx);
        goto after_7;
    // 0x8042CAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8042CAC8: lw          $t0, 0x1E0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042CACC: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8042CAD0: bnel        $at, $zero, L_8042CB80
    if (ctx->r1 != 0) {
        // 0x8042CAD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8042CB80;
    }
    goto skip_0;
    // 0x8042CAD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8042CAD8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8042CADC: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x8042CAE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8042CAE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042CAE8: sb          $t1, 0x30($t2)
    MEM_B(0X30, ctx->r10) = ctx->r9;
    // 0x8042CAEC: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    // 0x8042CAF0: jal         0x80049018
    // 0x8042CAF4: sb          $zero, 0x17C($t3)
    MEM_B(0X17C, ctx->r11) = 0;
    func_80049018(rdram, ctx);
        goto after_8;
    // 0x8042CAF4: sb          $zero, 0x17C($t3)
    MEM_B(0X17C, ctx->r11) = 0;
    after_8:
    // 0x8042CAF8: beq         $v0, $zero, L_8042CB14
    if (ctx->r2 == 0) {
        // 0x8042CAFC: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_8042CB14;
    }
    // 0x8042CAFC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8042CB00: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8042CB04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042CB08: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x8042CB0C: b           L_8042CB20
    // 0x8042CB10: swc1        $f4, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f4.u32l;
        goto L_8042CB20;
    // 0x8042CB10: swc1        $f4, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f4.u32l;
L_8042CB14:
    // 0x8042CB14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042CB18: lw          $t5, 0x24($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X24);
    // 0x8042CB1C: swc1        $f6, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f6.u32l;
L_8042CB20:
    // 0x8042CB20: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x8042CB24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042CB28: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x8042CB2C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8042CB30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042CB34: swc1        $f8, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f8.u32l;
    // 0x8042CB38: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x8042CB3C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8042CB40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042CB44: swc1        $f10, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f10.u32l;
    // 0x8042CB48: lw          $t8, 0xC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XC);
    // 0x8042CB4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042CB50: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8042CB54: bne         $t8, $at, L_8042CB74
    if (ctx->r24 != ctx->r1) {
        // 0x8042CB58: nop
    
            goto L_8042CB74;
    }
    // 0x8042CB58: nop

    // 0x8042CB5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042CB60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042CB64: jal         0x8042D50C
    // 0x8042CB68: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8042D50C(rdram, ctx);
        goto after_9;
    // 0x8042CB68: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_9:
    // 0x8042CB6C: b           L_8042CB80
    // 0x8042CB70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042CB80;
    // 0x8042CB70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042CB74:
    // 0x8042CB74: jal         0x8042D50C
    // 0x8042CB78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042D50C(rdram, ctx);
        goto after_10;
    // 0x8042CB78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x8042CB7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042CB80:
    // 0x8042CB80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8042CB84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8042CB88: jr          $ra
    // 0x8042CB8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8042CB8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807091E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807091E0: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(718, 0X14E8) << 16);
    // 0x807091E4: lw          $t6, -0x5938($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(718, 0X14E8));
    // 0x807091E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807091EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807091F0: bne         $t6, $zero, L_80709234
    if (ctx->r14 != 0) {
        // 0x807091F4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80709234;
    }
    // 0x807091F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807091F8: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(718, 0X1680) << 16);
    // 0x807091FC: lui         $a1, 0x8071
    ctx->r5 = S32(RELOC_HI16(718, 0X168C) << 16);
    // 0x80709200: addiu       $a1, $a1, -0x5794
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(718, 0X168C));
    // 0x80709204: addiu       $a0, $a0, -0x57A0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(718, 0X1680));
    // 0x80709208: jal         0x8004667C
    // 0x8070920C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8070920C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x80709210: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(718, 0X258C) << 16);
    // 0x80709214: lui         $a1, 0x8071
    ctx->r5 = S32(RELOC_HI16(718, 0X2598) << 16);
    // 0x80709218: addiu       $a1, $a1, -0x4888
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(718, 0X2598));
    // 0x8070921C: addiu       $a0, $a0, -0x4894
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(718, 0X258C));
    // 0x80709220: jal         0x8004667C
    // 0x80709224: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8004667C(rdram, ctx);
        goto after_1;
    // 0x80709224: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x80709228: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8070922C: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(718, 0X14E8) << 16);
    // 0x80709230: sw          $t7, -0x5938($at)
    MEM_W((int16_t)RELOC_LO16(718, 0X14E8), ctx->r1) = ctx->r15;
L_80709234:
    // 0x80709234: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80709238: addiu       $at, $zero, 0x4019
    ctx->r1 = ADD32(0, 0X4019);
    // 0x8070923C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80709240: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80709244: lui         $t0, 0x8071
    ctx->r8 = S32(RELOC_HI16(718, 0X3498) << 16);
    // 0x80709248: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8070924C: bne         $t9, $at, L_80709264
    if (ctx->r25 != ctx->r1) {
        // 0x80709250: addiu       $t0, $t0, -0x3988
        ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(718, 0X3498));
            goto L_80709264;
    }
    // 0x80709250: addiu       $t0, $t0, -0x3988
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(718, 0X3498));
    // 0x80709254: lui         $t1, 0x8071
    ctx->r9 = S32(RELOC_HI16(718, 0XB14) << 16);
    // 0x80709258: sw          $t0, 0xE94($v0)
    MEM_W(0XE94, ctx->r2) = ctx->r8;
    // 0x8070925C: addiu       $t1, $t1, -0x630C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(718, 0XB14));
    // 0x80709260: sw          $t1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r9;
L_80709264:
    // 0x80709264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80709268: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(718, 0X98) << 16);
    // 0x8070926C: addiu       $v0, $v0, -0x6D88
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(718, 0X98));
    // 0x80709270: jr          $ra
    // 0x80709274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80709274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8045254C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045254C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80452550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452554: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452558: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8045255C: jal         0x804524DC
    // 0x80452560: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_804524DC(rdram, ctx);
        goto after_0;
    // 0x80452560: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80452564: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80452568: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045256C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80452570: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80452574: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80452578: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045257C: lwc1        $f4, 0x6F10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6F10);
    // 0x80452580: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452584: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80452588: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8045258C: swc1        $f8, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f8.u32l;
    // 0x80452590: jal         0x8044E9C0
    // 0x80452594: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    func_8044E9C0(rdram, ctx);
        goto after_1;
    // 0x80452594: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    after_1:
    // 0x80452598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045259C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804525A0: jr          $ra
    // 0x804525A4: nop

    return;
    // 0x804525A4: nop

;}
RECOMP_FUNC void func_80703E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80703E30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80703E34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80703E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80703E3C: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x80703E40: nop

    // 0x80703E44: bc1fl       L_80703E58
    if (!c1cs) {
        // 0x80703E48: swc1        $f12, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
            goto L_80703E58;
    }
    goto skip_0;
    // 0x80703E48: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x80703E4C: b           L_80703E7C
    // 0x80703E50: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80703E7C;
    // 0x80703E50: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80703E54: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
L_80703E58:
    // 0x80703E58: jal         0x80065414
    // 0x80703E5C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80065414(rdram, ctx);
        goto after_0;
    // 0x80703E5C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80703E60: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x80703E64: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80703E68: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80703E6C: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80703E70: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80703E74: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80703E78: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
L_80703E7C:
    // 0x80703E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80703E80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80703E84: jr          $ra
    // 0x80703E88: nop

    return;
    // 0x80703E88: nop

;}
RECOMP_FUNC void func_8001A4F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A4F4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001A4F8: addiu       $a1, $a1, 0x5A0
    ctx->r5 = ADD32(ctx->r5, 0X5A0);
    // 0x8001A4FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A500: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_8001A504:
    // 0x8001A504: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x8001A508: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001A50C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A510: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001A514: bne         $a0, $t7, L_8001A520
    if (ctx->r4 != ctx->r15) {
        // 0x8001A518: sra         $v0, $v0, 16
        ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
            goto L_8001A520;
    }
    // 0x8001A518: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001A51C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8001A520:
    // 0x8001A520: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8001A524: bnel        $at, $zero, L_8001A504
    if (ctx->r1 != 0) {
        // 0x8001A528: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8001A504;
    }
    goto skip_0;
    // 0x8001A528: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    skip_0:
    // 0x8001A52C: jr          $ra
    // 0x8001A530: nop

    return;
    // 0x8001A530: nop

;}
RECOMP_FUNC void bcmp_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B800: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x8008B804: bne         $at, $zero, L_8008B8E4
    if (ctx->r1 != 0) {
        // 0x8008B808: xor         $v0, $a0, $a1
        ctx->r2 = ctx->r4 ^ ctx->r5;
            goto L_8008B8E4;
    }
    // 0x8008B808: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x8008B80C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8008B810: bne         $v0, $zero, L_8008B878
    if (ctx->r2 != 0) {
        // 0x8008B814: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_8008B878;
    }
    // 0x8008B814: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x8008B818: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x8008B81C: beq         $t8, $zero, L_8008B83C
    if (ctx->r24 == 0) {
        // 0x8008B820: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_8008B83C;
    }
    // 0x8008B820: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x8008B824: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008B828: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x8008B82C: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x8008B830: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8008B834: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8008B838: bne         $v0, $v1, L_8008B914
    if (ctx->r2 != ctx->r3) {
        // 0x8008B83C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_8008B914;
    }
L_8008B83C:
    // 0x8008B83C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008B840: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x8008B844: beq         $a3, $zero, L_8008B8E4
    if (ctx->r7 == 0) {
        // 0x8008B848: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8008B8E4;
    }
    // 0x8008B848: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8008B84C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B850: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8008B854:
    // 0x8008B854: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008B858: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008B85C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008B860: bne         $v0, $v1, L_8008B914
    if (ctx->r2 != ctx->r3) {
        // 0x8008B864: nop
    
            goto L_8008B914;
    }
    // 0x8008B864: nop

    // 0x8008B868: bnel        $a0, $a3, L_8008B854
    if (ctx->r4 != ctx->r7) {
        // 0x8008B86C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8008B854;
    }
    goto skip_0;
    // 0x8008B86C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8008B870: b           L_8008B8E4
    // 0x8008B874: nop

        goto L_8008B8E4;
    // 0x8008B874: nop

L_8008B878:
    // 0x8008B878: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x8008B87C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x8008B880: beq         $a3, $zero, L_8008B8AC
    if (ctx->r7 == 0) {
        // 0x8008B884: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8008B8AC;
    }
    // 0x8008B884: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8008B888: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B88C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_8008B890:
    // 0x8008B890: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8008B894: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008B898: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008B89C: bne         $v0, $v1, L_8008B914
    if (ctx->r2 != ctx->r3) {
        // 0x8008B8A0: nop
    
            goto L_8008B914;
    }
    // 0x8008B8A0: nop

    // 0x8008B8A4: bnel        $a0, $a3, L_8008B890
    if (ctx->r4 != ctx->r7) {
        // 0x8008B8A8: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_8008B890;
    }
    goto skip_1;
    // 0x8008B8A8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_8008B8AC:
    // 0x8008B8AC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008B8B0: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x8008B8B4: beq         $a3, $zero, L_8008B8E4
    if (ctx->r7 == 0) {
        // 0x8008B8B8: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8008B8E4;
    }
    // 0x8008B8B8: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8008B8BC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x8008B8C0: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
L_8008B8C4:
    // 0x8008B8C4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8008B8C8: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x8008B8CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008B8D0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008B8D4: bne         $v0, $v1, L_8008B914
    if (ctx->r2 != ctx->r3) {
        // 0x8008B8D8: nop
    
            goto L_8008B914;
    }
    // 0x8008B8D8: nop

    // 0x8008B8DC: bnel        $a0, $a3, L_8008B8C4
    if (ctx->r4 != ctx->r7) {
        // 0x8008B8E0: lwl         $v0, 0x0($a0)
        ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
            goto L_8008B8C4;
    }
    goto skip_2;
    // 0x8008B8E0: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    skip_2:
L_8008B8E4:
    // 0x8008B8E4: blez        $a2, L_8008B90C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008B8E8: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_8008B90C;
    }
    // 0x8008B8E8: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x8008B8EC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_8008B8F0:
    // 0x8008B8F0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8008B8F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008B8F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008B8FC: bne         $v0, $v1, L_8008B914
    if (ctx->r2 != ctx->r3) {
        // 0x8008B900: nop
    
            goto L_8008B914;
    }
    // 0x8008B900: nop

    // 0x8008B904: bnel        $a0, $a3, L_8008B8F0
    if (ctx->r4 != ctx->r7) {
        // 0x8008B908: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_8008B8F0;
    }
    goto skip_3;
    // 0x8008B908: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_8008B90C:
    // 0x8008B90C: jr          $ra
    // 0x8008B910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8008B910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008B914:
    // 0x8008B914: jr          $ra
    // 0x8008B918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8008B918: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008B91C: nop

;}
RECOMP_FUNC void func_80073AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073AD4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80073AD8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80073ADC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80073AE0: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80073AE4: lui         $t2, 0xF500
    ctx->r10 = S32(0XF500 << 16);
    // 0x80073AE8: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x80073AEC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073AF0: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x80073AF4: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80073AF8: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x80073AFC: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x80073B00: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x80073B04: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x80073B08: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80073B0C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80073B10: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073B14: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80073B18: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80073B1C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80073B20: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80073B24: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073B28: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x80073B2C: addiu       $t4, $t0, 0x7
    ctx->r12 = ADD32(ctx->r8, 0X7);
    // 0x80073B30: sra         $t5, $t4, 3
    ctx->r13 = S32(SIGNED(ctx->r12) >> 3);
    // 0x80073B34: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80073B38: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x80073B3C: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x80073B40: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80073B44: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80073B48: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80073B4C: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x80073B50: sll         $t7, $t6, 9
    ctx->r15 = S32(ctx->r14 << 9);
    // 0x80073B54: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x80073B58: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80073B5C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80073B60: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073B64: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80073B68: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80073B6C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80073B70: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80073B74: addiu       $t4, $t0, -0x1
    ctx->r12 = ADD32(ctx->r8, -0X1);
    // 0x80073B78: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80073B7C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80073B80: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80073B84: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x80073B88: sll         $t3, $t6, 12
    ctx->r11 = S32(ctx->r14 << 12);
    // 0x80073B8C: andi        $t4, $t9, 0xFFF
    ctx->r12 = ctx->r25 & 0XFFF;
    // 0x80073B90: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80073B94: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80073B98: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073B9C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80073BA0: jr          $ra
    // 0x80073BA4: nop

    return;
    // 0x80073BA4: nop

;}
RECOMP_FUNC void func_8043E448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043E44C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E450: jal         0x8004700C
    // 0x8043E454: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043E454: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043E458: beql        $v0, $zero, L_8043E484
    if (ctx->r2 == 0) {
        // 0x8043E45C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043E484;
    }
    goto skip_0;
    // 0x8043E45C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043E460: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
    // 0x8043E464: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(92, 0X1A00) << 16);
    // 0x8043E468: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8043E46C: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x8043E470: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8043E474: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8043E478: lw          $t9, -0x15C0($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(92, 0X1A00));
    // 0x8043E47C: sw          $t9, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->r25;
    // 0x8043E480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043E484:
    // 0x8043E484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043E488: jr          $ra
    // 0x8043E48C: nop

    return;
    // 0x8043E48C: nop

;}
RECOMP_FUNC void bcopy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1F0: beq         $a2, $zero, L_8008C25C
    if (ctx->r6 == 0) {
        // 0x8008C1F4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8008C25C;
    }
    // 0x8008C1F4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8008C1F8: beq         $a0, $a1, L_8008C25C
    if (ctx->r4 == ctx->r5) {
        // 0x8008C1FC: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8008C25C;
    }
    // 0x8008C1FC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8008C200: bnel        $at, $zero, L_8008C224
    if (ctx->r1 != 0) {
        // 0x8008C204: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8008C224;
    }
    goto skip_0;
    // 0x8008C204: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x8008C208: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x8008C20C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008C210: beql        $at, $zero, L_8008C224
    if (ctx->r1 == 0) {
        // 0x8008C214: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8008C224;
    }
    goto skip_1;
    // 0x8008C214: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x8008C218: b           L_8008C388
    // 0x8008C21C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_8008C388;
    // 0x8008C21C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x8008C220: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8008C224:
    // 0x8008C224: bne         $at, $zero, L_8008C23C
    if (ctx->r1 != 0) {
        // 0x8008C228: nop
    
            goto L_8008C23C;
    }
    // 0x8008C228: nop

    // 0x8008C22C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x8008C230: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8008C234: beq         $v0, $v1, L_8008C264
    if (ctx->r2 == ctx->r3) {
        // 0x8008C238: nop
    
            goto L_8008C264;
    }
    // 0x8008C238: nop

L_8008C23C:
    // 0x8008C23C: beq         $a2, $zero, L_8008C25C
    if (ctx->r6 == 0) {
        // 0x8008C240: nop
    
            goto L_8008C25C;
    }
    // 0x8008C240: nop

    // 0x8008C244: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_8008C248:
    // 0x8008C248: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8008C24C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008C250: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008C254: bne         $a0, $v1, L_8008C248
    if (ctx->r4 != ctx->r3) {
        // 0x8008C258: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_8008C248;
    }
    // 0x8008C258: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_8008C25C:
    // 0x8008C25C: jr          $ra
    // 0x8008C260: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x8008C260: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8008C264:
    // 0x8008C264: beq         $v0, $zero, L_8008C2C8
    if (ctx->r2 == 0) {
        // 0x8008C268: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008C2C8;
    }
    // 0x8008C268: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C26C: beq         $v0, $at, L_8008C2AC
    if (ctx->r2 == ctx->r1) {
        // 0x8008C270: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008C2AC;
    }
    // 0x8008C270: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008C274: beql        $v0, $at, L_8008C298
    if (ctx->r2 == ctx->r1) {
        // 0x8008C278: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_8008C298;
    }
    goto skip_2;
    // 0x8008C278: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x8008C27C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8008C280: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008C284: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008C288: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8008C28C: b           L_8008C2C8
    // 0x8008C290: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_8008C2C8;
    // 0x8008C290: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x8008C294: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_8008C298:
    // 0x8008C298: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8008C29C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8008C2A0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x8008C2A4: b           L_8008C2C8
    // 0x8008C2A8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_8008C2C8;
    // 0x8008C2A8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_8008C2AC:
    // 0x8008C2AC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8008C2B0: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x8008C2B4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8008C2B8: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x8008C2BC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x8008C2C0: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x8008C2C4: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_8008C2C8:
    // 0x8008C2C8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8008C2CC: bnel        $at, $zero, L_8008C328
    if (ctx->r1 != 0) {
        // 0x8008C2D0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8008C328;
    }
    goto skip_3;
    // 0x8008C2D0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x8008C2D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008C2D8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8008C2DC: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8008C2E0: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8008C2E4: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x8008C2E8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8008C2EC: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x8008C2F0: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x8008C2F4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8008C2F8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8008C2FC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x8008C300: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x8008C304: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x8008C308: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x8008C30C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x8008C310: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x8008C314: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x8008C318: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x8008C31C: b           L_8008C2C8
    // 0x8008C320: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_8008C2C8;
    // 0x8008C320: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_8008C324:
    // 0x8008C324: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8008C328:
    // 0x8008C328: bnel        $at, $zero, L_8008C364
    if (ctx->r1 != 0) {
        // 0x8008C32C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_8008C364;
    }
    goto skip_4;
    // 0x8008C32C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x8008C330: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008C334: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8008C338: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8008C33C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8008C340: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8008C344: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8008C348: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8008C34C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x8008C350: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x8008C354: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x8008C358: b           L_8008C324
    // 0x8008C35C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_8008C324;
    // 0x8008C35C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_8008C360:
    // 0x8008C360: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_8008C364:
    // 0x8008C364: bne         $at, $zero, L_8008C23C
    if (ctx->r1 != 0) {
        // 0x8008C368: nop
    
            goto L_8008C23C;
    }
    // 0x8008C368: nop

    // 0x8008C36C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008C370: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008C374: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008C378: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8008C37C: b           L_8008C360
    // 0x8008C380: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_8008C360;
    // 0x8008C380: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x8008C384: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8008C388:
    // 0x8008C388: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8008C38C: bne         $at, $zero, L_8008C3A4
    if (ctx->r1 != 0) {
        // 0x8008C390: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_8008C3A4;
    }
    // 0x8008C390: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x8008C394: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x8008C398: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8008C39C: beq         $v0, $v1, L_8008C3D4
    if (ctx->r2 == ctx->r3) {
        // 0x8008C3A0: nop
    
            goto L_8008C3D4;
    }
    // 0x8008C3A0: nop

L_8008C3A4:
    // 0x8008C3A4: beq         $a2, $zero, L_8008C25C
    if (ctx->r6 == 0) {
        // 0x8008C3A8: nop
    
            goto L_8008C25C;
    }
    // 0x8008C3A8: nop

    // 0x8008C3AC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8008C3B0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8008C3B4: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_8008C3B8:
    // 0x8008C3B8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8008C3BC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8008C3C0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8008C3C4: bne         $a0, $v1, L_8008C3B8
    if (ctx->r4 != ctx->r3) {
        // 0x8008C3C8: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_8008C3B8;
    }
    // 0x8008C3C8: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x8008C3CC: jr          $ra
    // 0x8008C3D0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x8008C3D0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8008C3D4:
    // 0x8008C3D4: beq         $v0, $zero, L_8008C438
    if (ctx->r2 == 0) {
        // 0x8008C3D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8008C438;
    }
    // 0x8008C3D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008C3DC: beq         $v0, $at, L_8008C41C
    if (ctx->r2 == ctx->r1) {
        // 0x8008C3E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008C41C;
    }
    // 0x8008C3E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008C3E4: beql        $v0, $at, L_8008C408
    if (ctx->r2 == ctx->r1) {
        // 0x8008C3E8: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_8008C408;
    }
    goto skip_5;
    // 0x8008C3E8: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x8008C3EC: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x8008C3F0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8008C3F4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8008C3F8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8008C3FC: b           L_8008C438
    // 0x8008C400: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_8008C438;
    // 0x8008C400: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8008C404: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_8008C408:
    // 0x8008C408: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8008C40C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x8008C410: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x8008C414: b           L_8008C438
    // 0x8008C418: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_8008C438;
    // 0x8008C418: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_8008C41C:
    // 0x8008C41C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x8008C420: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x8008C424: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x8008C428: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x8008C42C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x8008C430: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x8008C434: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_8008C438:
    // 0x8008C438: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8008C43C: bnel        $at, $zero, L_8008C498
    if (ctx->r1 != 0) {
        // 0x8008C440: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_8008C498;
    }
    goto skip_6;
    // 0x8008C440: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x8008C444: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8008C448: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x8008C44C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x8008C450: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x8008C454: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x8008C458: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x8008C45C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x8008C460: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x8008C464: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x8008C468: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x8008C46C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x8008C470: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x8008C474: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x8008C478: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x8008C47C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x8008C480: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x8008C484: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x8008C488: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x8008C48C: b           L_8008C438
    // 0x8008C490: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_8008C438;
    // 0x8008C490: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_8008C494:
    // 0x8008C494: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_8008C498:
    // 0x8008C498: bnel        $at, $zero, L_8008C4D4
    if (ctx->r1 != 0) {
        // 0x8008C49C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_8008C4D4;
    }
    goto skip_7;
    // 0x8008C49C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x8008C4A0: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8008C4A4: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x8008C4A8: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x8008C4AC: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x8008C4B0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x8008C4B4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x8008C4B8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8008C4BC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x8008C4C0: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x8008C4C4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x8008C4C8: b           L_8008C494
    // 0x8008C4CC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_8008C494;
    // 0x8008C4CC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_8008C4D0:
    // 0x8008C4D0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_8008C4D4:
    // 0x8008C4D4: bne         $at, $zero, L_8008C3A4
    if (ctx->r1 != 0) {
        // 0x8008C4D8: nop
    
            goto L_8008C3A4;
    }
    // 0x8008C4D8: nop

    // 0x8008C4DC: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8008C4E0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8008C4E4: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8008C4E8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8008C4EC: b           L_8008C4D0
    // 0x8008C4F0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8008C4D0;
    // 0x8008C4F0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8008C4F4: nop

    // 0x8008C4F8: nop

    // 0x8008C4FC: nop

;}
RECOMP_FUNC void func_80516FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80516FB8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80516FBC: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80516FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80516FC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80516FC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80516FCC: lui         $t8, 0x8051
    ctx->r24 = S32(RELOC_HI16(282, 0X264) << 16);
    // 0x80516FD0: sb          $a2, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r6;
    // 0x80516FD4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80516FD8: lw          $t8, 0x7094($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(282, 0X264));
    // 0x80516FDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80516FE0: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80516FE4: jal         0x80516F00
    // 0x80516FE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80516F00(rdram, ctx);
        goto after_0;
    // 0x80516FE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80516FEC: jal         0x80516F5C
    // 0x80516FF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80516F5C(rdram, ctx);
        goto after_1;
    // 0x80516FF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80516FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80516FF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80516FFC: jr          $ra
    // 0x80517000: nop

    return;
    // 0x80517000: nop

    // 0x80517004: nop

    // 0x80517008: nop

    // 0x8051700C: nop

;}
RECOMP_FUNC void func_805AC68C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC68C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AC690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC694: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AC698: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x805AC69C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x805AC6A0: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x805AC6A4: addiu       $t7, $t7, -0x7218
    ctx->r15 = ADD32(ctx->r15, -0X7218);
    // 0x805AC6A8: lw          $t6, 0x180($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X180);
    // 0x805AC6AC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x805AC6B0: beq         $a0, $t6, L_805AC6D0
    if (ctx->r4 == ctx->r14) {
        // 0x805AC6B4: nop
    
            goto L_805AC6D0;
    }
    // 0x805AC6B4: nop

    // 0x805AC6B8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x805AC6BC: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x805AC6C0: jal         0x80048C00
    // 0x805AC6C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80048C00(rdram, ctx);
        goto after_0;
    // 0x805AC6C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x805AC6C8: b           L_805AC734
    // 0x805AC6CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805AC734;
    // 0x805AC6CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805AC6D0:
    // 0x805AC6D0: beql        $a3, $zero, L_805AC734
    if (ctx->r7 == 0) {
        // 0x805AC6D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805AC734;
    }
    goto skip_0;
    // 0x805AC6D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x805AC6D8: lw          $v0, 0x1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C);
    // 0x805AC6DC: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x805AC6E0: bnel        $at, $zero, L_805AC6F0
    if (ctx->r1 != 0) {
        // 0x805AC6E4: lw          $t8, 0x138($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X138);
            goto L_805AC6F0;
    }
    goto skip_1;
    // 0x805AC6E4: lw          $t8, 0x138($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X138);
    skip_1:
    // 0x805AC6E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805AC6EC: lw          $t8, 0x138($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X138);
L_805AC6F0:
    // 0x805AC6F0: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x805AC6F4: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(441, 0X1224) << 16);
    // 0x805AC6F8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x805AC6FC: beq         $t8, $zero, L_805AC718
    if (ctx->r24 == 0) {
        // 0x805AC700: lwc1        $f0, -0x2BEC($at)
        ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(441, 0X1224));
            goto L_805AC718;
    }
    // 0x805AC700: lwc1        $f0, -0x2BEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(441, 0X1224));
    // 0x805AC704: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805AC708: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805AC70C: nop

    // 0x805AC710: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x805AC714: nop

L_805AC718:
    // 0x805AC718: swc1        $f0, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f0.u32l;
    // 0x805AC71C: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(441, 0X1244) << 16);
    // 0x805AC720: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x805AC724: lwc1        $f6, -0x2BCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(441, 0X1244));
    // 0x805AC728: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x805AC72C: swc1        $f6, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f6.u32l;
    // 0x805AC730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805AC734:
    // 0x805AC734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AC738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AC73C: jr          $ra
    // 0x805AC740: nop

    return;
    // 0x805AC740: nop

;}
RECOMP_FUNC void func_80558624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558624: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80558628: lui         $t6, 0x8055
    ctx->r14 = S32(RELOC_HI16(363, 0X50) << 16);
    // 0x8055862C: addiu       $t6, $t6, 0x7BA0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(363, 0X50));
    // 0x80558630: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80558634: jr          $ra
    // 0x80558638: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80558638: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8057BB68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BB68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057BB6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057BB70: lw          $t6, 0x1E4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E4);
    // 0x8057BB74: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8057BB78: lh          $a3, 0x1F0($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X1F0);
    // 0x8057BB7C: beq         $t6, $zero, L_8057BC38
    if (ctx->r14 == 0) {
        // 0x8057BB80: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8057BC38;
    }
    // 0x8057BB80: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8057BB84: bne         $a3, $at, L_8057BBF0
    if (ctx->r7 != ctx->r1) {
        // 0x8057BB88: sll         $a1, $a3, 16
        ctx->r5 = S32(ctx->r7 << 16);
            goto L_8057BBF0;
    }
    // 0x8057BB88: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8057BB8C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8057BB90: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8057BB94: jal         0x80067BBC
    // 0x8057BB98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8057BB98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8057BB9C: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x8057BBA0: jal         0x80067F78
    // 0x8057BBA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8057BBA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8057BBA8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8057BBAC: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8057BBB0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8057BBB4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8057BBB8: beq         $v0, $at, L_8057BC38
    if (ctx->r2 == ctx->r1) {
        // 0x8057BBBC: sh          $v0, 0x1F0($a2)
        MEM_H(0X1F0, ctx->r6) = ctx->r2;
            goto L_8057BC38;
    }
    // 0x8057BBBC: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
    // 0x8057BBC0: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8057BBC4: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8057BBC8: jal         0x80067BBC
    // 0x8057BBCC: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8057BBCC: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_2:
    // 0x8057BBD0: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8057BBD4: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x8057BBD8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8057BBDC: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8057BBE0: jal         0x80067838
    // 0x8057BBE4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x8057BBE4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x8057BBE8: b           L_8057BC3C
    // 0x8057BBEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8057BC3C;
    // 0x8057BBEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057BBF0:
    // 0x8057BBF0: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x8057BBF4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057BBF8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8057BBFC: jal         0x80067930
    // 0x8057BC00: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_4;
    // 0x8057BC00: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_4:
    // 0x8057BC04: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8057BC08: beq         $v0, $zero, L_8057BC38
    if (ctx->r2 == 0) {
        // 0x8057BC0C: lh          $a3, 0x1E($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X1E);
            goto L_8057BC38;
    }
    // 0x8057BC0C: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8057BC10: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8057BC14: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8057BC18: jal         0x80067BBC
    // 0x8057BC1C: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8057BC1C: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_5:
    // 0x8057BC20: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8057BC24: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x8057BC28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8057BC2C: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8057BC30: jal         0x800678F0
    // 0x8057BC34: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x8057BC34: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_6:
L_8057BC38:
    // 0x8057BC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057BC3C:
    // 0x8057BC3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057BC40: jr          $ra
    // 0x8057BC44: nop

    return;
    // 0x8057BC44: nop

;}
RECOMP_FUNC void func_80707788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80707788: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8070778C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80707790: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80707794: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80707798: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8070779C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807077A0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807077A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807077A8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807077AC: lui         $t1, 0x8070
    ctx->r9 = S32(RELOC_HI16(712, 0X640) << 16);
    // 0x807077B0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807077B4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807077B8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807077BC: lw          $t1, 0x77E0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(712, 0X640));
    // 0x807077C0: jr          $ra
    // 0x807077C4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807077C4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x807077C8: nop

    // 0x807077CC: nop

;}
RECOMP_FUNC void func_804754B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804754B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804754B4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804754B8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804754BC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804754C0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804754C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804754C8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804754CC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804754D0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804754D4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804754D8: jr          $ra
    // 0x804754DC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804754DC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80067D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D28: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067D2C: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067D30: jr          $ra
    // 0x80067D34: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    return;
    // 0x80067D34: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_8007FD6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FD6C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8007FD70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FD74: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x8007FD78: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8007FD7C: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x8007FD80: jal         0x800818E8
    // 0x8007FD84: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    MtxConv_L2F(rdram, ctx);
        goto after_0;
    // 0x8007FD84: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x8007FD88: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007FD8C: jal         0x800818E8
    // 0x8007FD90: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    MtxConv_L2F(rdram, ctx);
        goto after_1;
    // 0x8007FD90: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    after_1:
    // 0x8007FD94: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8007FD98: jal         0x800800CC
    // 0x8007FD9C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800800CC(rdram, ctx);
        goto after_2;
    // 0x8007FD9C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8007FDA0: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x8007FDA4: jal         0x800817A0
    // 0x8007FDA8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    MtxConv_F2L(rdram, ctx);
        goto after_3;
    // 0x8007FDA8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_3:
    // 0x8007FDAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FDB0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x8007FDB4: jr          $ra
    // 0x8007FDB8: nop

    return;
    // 0x8007FDB8: nop

;}
RECOMP_FUNC void func_806EAAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EAAC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EAACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EAAD0: jal         0x8004700C
    // 0x806EAAD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EAAD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EAAD8: bne         $v0, $zero, L_806EAAE8
    if (ctx->r2 != 0) {
        // 0x806EAADC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806EAAE8;
    }
    // 0x806EAADC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EAAE0: b           L_806EAB38
    // 0x806EAAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EAB38;
    // 0x806EAAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EAAE8:
    // 0x806EAAE8: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x806EAAEC: bnel        $t6, $zero, L_806EAB18
    if (ctx->r14 != 0) {
        // 0x806EAAF0: lwc1        $f8, 0x84($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
            goto L_806EAB18;
    }
    goto skip_0;
    // 0x806EAAF0: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    skip_0:
    // 0x806EAAF4: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806EAAF8: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806EAAFC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806EAB00: nop

    // 0x806EAB04: bc1fl       L_806EAB38
    if (!c1cs) {
        // 0x806EAB08: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806EAB38;
    }
    goto skip_1;
    // 0x806EAB08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x806EAB0C: b           L_806EAB38
    // 0x806EAB10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EAB38;
    // 0x806EAB10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EAB14: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
L_806EAB18:
    // 0x806EAB18: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806EAB1C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806EAB20: nop

    // 0x806EAB24: bc1fl       L_806EAB38
    if (!c1cs) {
        // 0x806EAB28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806EAB38;
    }
    goto skip_2;
    // 0x806EAB28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x806EAB2C: b           L_806EAB38
    // 0x806EAB30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EAB38;
    // 0x806EAB30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EAB34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EAB38:
    // 0x806EAB38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EAB3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EAB40: jr          $ra
    // 0x806EAB44: nop

    return;
    // 0x806EAB44: nop

;}
RECOMP_FUNC void func_8052E5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052E5F4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052E5F8: lhu         $v1, 0x119E($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X119E);
    // 0x8052E5FC: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x8052E600: beq         $t6, $zero, L_8052E614
    if (ctx->r14 == 0) {
        // 0x8052E604: andi        $t8, $v1, 0xFFFB
        ctx->r24 = ctx->r3 & 0XFFFB;
            goto L_8052E614;
    }
    // 0x8052E604: andi        $t8, $v1, 0xFFFB
    ctx->r24 = ctx->r3 & 0XFFFB;
    // 0x8052E608: ori         $t7, $v1, 0x4
    ctx->r15 = ctx->r3 | 0X4;
    // 0x8052E60C: b           L_8052E618
    // 0x8052E610: sh          $t7, 0x119E($v0)
    MEM_H(0X119E, ctx->r2) = ctx->r15;
        goto L_8052E618;
    // 0x8052E610: sh          $t7, 0x119E($v0)
    MEM_H(0X119E, ctx->r2) = ctx->r15;
L_8052E614:
    // 0x8052E614: sh          $t8, 0x119E($v0)
    MEM_H(0X119E, ctx->r2) = ctx->r24;
L_8052E618:
    // 0x8052E618: lhu         $t9, 0x119E($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X119E);
    // 0x8052E61C: andi        $t0, $t9, 0xFFFD
    ctx->r8 = ctx->r25 & 0XFFFD;
    // 0x8052E620: jr          $ra
    // 0x8052E624: sh          $t0, 0x119E($v0)
    MEM_H(0X119E, ctx->r2) = ctx->r8;
    return;
    // 0x8052E624: sh          $t0, 0x119E($v0)
    MEM_H(0X119E, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AD80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8008AD84: beq         $a2, $zero, L_8008ADA4
    if (ctx->r6 == 0) {
        // 0x8008AD88: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8008ADA4;
    }
    // 0x8008AD88: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8008AD8C:
    // 0x8008AD8C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8008AD90: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8008AD94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008AD98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008AD9C: bne         $a2, $zero, L_8008AD8C
    if (ctx->r6 != 0) {
        // 0x8008ADA0: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_8008AD8C;
    }
    // 0x8008ADA0: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_8008ADA4:
    // 0x8008ADA4: jr          $ra
    // 0x8008ADA8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8008ADA8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_804682B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804682B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804682B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804682BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804682C0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804682C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804682C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804682CC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x804682D0: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x804682D4: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x804682D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804682DC: jal         0x804686B4
    // 0x804682E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804686B4(rdram, ctx);
        goto after_0;
    // 0x804682E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x804682E4: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x804682E8: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x804682EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804682F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804682F4: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x804682F8: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
    // 0x804682FC: lui         $t9, 0x8047
    ctx->r25 = S32(RELOC_HI16(132, 0X1DF0) << 16);
    // 0x80468300: addiu       $t9, $t9, -0x78D0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(132, 0X1DF0));
    // 0x80468304: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80468308: sw          $zero, 0x68($v0)
    MEM_W(0X68, ctx->r2) = 0;
    // 0x8046830C: sw          $zero, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = 0;
    // 0x80468310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80468314: jal         0x80045A34
    // 0x80468318: addiu       $a1, $zero, 0x2D80
    ctx->r5 = ADD32(0, 0X2D80);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80468318: addiu       $a1, $zero, 0x2D80
    ctx->r5 = ADD32(0, 0X2D80);
    after_1:
    // 0x8046831C: bne         $v0, $zero, L_8046834C
    if (ctx->r2 != 0) {
        // 0x80468320: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8046834C;
    }
    // 0x80468320: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80468324: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x80468328: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8046832C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80468330: jal         0x80048060
    // 0x80468334: sh          $t6, 0x144($t7)
    MEM_H(0X144, ctx->r15) = ctx->r14;
    func_80048060(rdram, ctx);
        goto after_2;
    // 0x80468334: sh          $t6, 0x144($t7)
    MEM_H(0X144, ctx->r15) = ctx->r14;
    after_2:
    // 0x80468338: jal         0x800447C8
    // 0x8046833C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x8046833C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80468340: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80468344: b           L_804686A0
    // 0x80468348: sb          $zero, 0x165($t8)
    MEM_B(0X165, ctx->r24) = 0;
        goto L_804686A0;
    // 0x80468348: sb          $zero, 0x165($t8)
    MEM_B(0X165, ctx->r24) = 0;
L_8046834C:
    // 0x8046834C: lui         $t9, 0x8047
    ctx->r25 = S32(RELOC_HI16(132, 0X1948) << 16);
    // 0x80468350: addiu       $t9, $t9, -0x7D78
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(132, 0X1948));
    // 0x80468354: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x80468358: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046835C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80468360: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80468364: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80468368: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
    // 0x8046836C: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x80468370: sw          $t6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r14;
    // 0x80468374: lh          $t7, 0x144($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X144);
    // 0x80468378: sh          $t7, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r15;
    // 0x8046837C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80468380: bnel        $t8, $t6, L_8046839C
    if (ctx->r24 != ctx->r14) {
        // 0x80468384: lw          $a0, 0x10($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X10);
            goto L_8046839C;
    }
    goto skip_0;
    // 0x80468384: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x80468388: lw          $t9, 0x1E0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E0);
    // 0x8046838C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80468390: b           L_804683A4
    // 0x80468394: sh          $t9, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r25;
        goto L_804683A4;
    // 0x80468394: sh          $t9, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r25;
    // 0x80468398: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
L_8046839C:
    // 0x8046839C: lh          $t5, 0x144($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X144);
    // 0x804683A0: sh          $t5, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r13;
L_804683A4:
    // 0x804683A4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x804683A8: sw          $zero, 0x1FA0($v1)
    MEM_W(0X1FA0, ctx->r3) = 0;
    // 0x804683AC: sw          $zero, 0x1F9C($v1)
    MEM_W(0X1F9C, ctx->r3) = 0;
    // 0x804683B0: lh          $a1, 0x13C($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X13C);
    // 0x804683B4: lh          $a2, 0x13C($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X13C);
    // 0x804683B8: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x804683BC: beql        $at, $zero, L_804683D4
    if (ctx->r1 == 0) {
        // 0x804683C0: sh          $a1, 0x18($v1)
        MEM_H(0X18, ctx->r3) = ctx->r5;
            goto L_804683D4;
    }
    goto skip_1;
    // 0x804683C0: sh          $a1, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r5;
    skip_1:
    // 0x804683C4: sh          $a2, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r6;
    // 0x804683C8: b           L_804683D8
    // 0x804683CC: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
        goto L_804683D8;
    // 0x804683CC: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x804683D0: sh          $a1, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r5;
L_804683D4:
    // 0x804683D4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_804683D8:
    // 0x804683D8: lh          $a1, 0x13E($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X13E);
    // 0x804683DC: lh          $a2, 0x13E($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X13E);
    // 0x804683E0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x804683E4: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x804683E8: beql        $at, $zero, L_804683FC
    if (ctx->r1 == 0) {
        // 0x804683EC: sh          $a1, 0x1A($v1)
        MEM_H(0X1A, ctx->r3) = ctx->r5;
            goto L_804683FC;
    }
    goto skip_2;
    // 0x804683EC: sh          $a1, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r5;
    skip_2:
    // 0x804683F0: b           L_804683FC
    // 0x804683F4: sh          $a2, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r6;
        goto L_804683FC;
    // 0x804683F4: sh          $a2, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r6;
    // 0x804683F8: sh          $a1, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r5;
L_804683FC:
    // 0x804683FC: lh          $a0, 0x18($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X18);
    // 0x80468400: lh          $a3, 0x1A($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X1A);
    // 0x80468404: sh          $zero, 0x2D04($v1)
    MEM_H(0X2D04, ctx->r3) = 0;
    // 0x80468408: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
    // 0x8046840C: bgez        $a1, L_80468418
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80468410: addu        $at, $a1, $zero
        ctx->r1 = ADD32(ctx->r5, 0);
            goto L_80468418;
    }
    // 0x80468410: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x80468414: addiu       $at, $a1, 0x1
    ctx->r1 = ADD32(ctx->r5, 0X1);
L_80468418:
    // 0x80468418: sra         $a1, $at, 1
    ctx->r5 = S32(SIGNED(ctx->r1) >> 1);
    // 0x8046841C: negu        $t0, $a3
    ctx->r8 = SUB32(0, ctx->r7);
    // 0x80468420: sll         $a2, $a0, 7
    ctx->r6 = S32(ctx->r4 << 7);
    // 0x80468424: sra         $t1, $a3, 1
    ctx->r9 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80468428: sll         $t1, $t1, 7
    ctx->r9 = S32(ctx->r9 << 7);
    // 0x8046842C: sh          $a1, 0x2D00($v1)
    MEM_H(0X2D00, ctx->r3) = ctx->r5;
    // 0x80468430: bgez        $t0, L_8046843C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80468434: addu        $at, $t0, $zero
        ctx->r1 = ADD32(ctx->r8, 0);
            goto L_8046843C;
    }
    // 0x80468434: addu        $at, $t0, $zero
    ctx->r1 = ADD32(ctx->r8, 0);
    // 0x80468438: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
L_8046843C:
    // 0x8046843C: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
    // 0x80468440: sh          $t0, 0x2D02($v1)
    MEM_H(0X2D02, ctx->r3) = ctx->r8;
    // 0x80468444: sh          $zero, 0x2D06($v1)
    MEM_H(0X2D06, ctx->r3) = 0;
    // 0x80468448: sh          $zero, 0x2D08($v1)
    MEM_H(0X2D08, ctx->r3) = 0;
    // 0x8046844C: sh          $zero, 0x2D0A($v1)
    MEM_H(0X2D0A, ctx->r3) = 0;
    // 0x80468450: sb          $v0, 0x2D0C($v1)
    MEM_B(0X2D0C, ctx->r3) = ctx->r2;
    // 0x80468454: sb          $v0, 0x2D0D($v1)
    MEM_B(0X2D0D, ctx->r3) = ctx->r2;
    // 0x80468458: sb          $v0, 0x2D0E($v1)
    MEM_B(0X2D0E, ctx->r3) = ctx->r2;
    // 0x8046845C: sb          $v0, 0x2D0F($v1)
    MEM_B(0X2D0F, ctx->r3) = ctx->r2;
    // 0x80468460: bgez        $a0, L_80468470
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80468464: sra         $t2, $a0, 1
        ctx->r10 = S32(SIGNED(ctx->r4) >> 1);
            goto L_80468470;
    }
    // 0x80468464: sra         $t2, $a0, 1
    ctx->r10 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80468468: addiu       $at, $a0, 0x1
    ctx->r1 = ADD32(ctx->r4, 0X1);
    // 0x8046846C: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_80468470:
    // 0x80468470: sh          $t2, 0x2D10($v1)
    MEM_H(0X2D10, ctx->r3) = ctx->r10;
    // 0x80468474: sh          $t0, 0x2D12($v1)
    MEM_H(0X2D12, ctx->r3) = ctx->r8;
    // 0x80468478: sh          $a2, 0x2D18($v1)
    MEM_H(0X2D18, ctx->r3) = ctx->r6;
    // 0x8046847C: sh          $zero, 0x2D14($v1)
    MEM_H(0X2D14, ctx->r3) = 0;
    // 0x80468480: sh          $zero, 0x2D16($v1)
    MEM_H(0X2D16, ctx->r3) = 0;
    // 0x80468484: sh          $zero, 0x2D1A($v1)
    MEM_H(0X2D1A, ctx->r3) = 0;
    // 0x80468488: sb          $v0, 0x2D1C($v1)
    MEM_B(0X2D1C, ctx->r3) = ctx->r2;
    // 0x8046848C: sb          $v0, 0x2D1D($v1)
    MEM_B(0X2D1D, ctx->r3) = ctx->r2;
    // 0x80468490: sb          $v0, 0x2D1E($v1)
    MEM_B(0X2D1E, ctx->r3) = ctx->r2;
    // 0x80468494: sb          $v0, 0x2D1F($v1)
    MEM_B(0X2D1F, ctx->r3) = ctx->r2;
    // 0x80468498: sh          $t2, 0x2D20($v1)
    MEM_H(0X2D20, ctx->r3) = ctx->r10;
    // 0x8046849C: sh          $t1, 0x2D2A($v1)
    MEM_H(0X2D2A, ctx->r3) = ctx->r9;
    // 0x804684A0: sh          $a2, 0x2D28($v1)
    MEM_H(0X2D28, ctx->r3) = ctx->r6;
    // 0x804684A4: sh          $zero, 0x2D22($v1)
    MEM_H(0X2D22, ctx->r3) = 0;
    // 0x804684A8: sh          $zero, 0x2D24($v1)
    MEM_H(0X2D24, ctx->r3) = 0;
    // 0x804684AC: sh          $zero, 0x2D26($v1)
    MEM_H(0X2D26, ctx->r3) = 0;
    // 0x804684B0: sb          $v0, 0x2D2C($v1)
    MEM_B(0X2D2C, ctx->r3) = ctx->r2;
    // 0x804684B4: sb          $v0, 0x2D2D($v1)
    MEM_B(0X2D2D, ctx->r3) = ctx->r2;
    // 0x804684B8: sb          $v0, 0x2D2E($v1)
    MEM_B(0X2D2E, ctx->r3) = ctx->r2;
    // 0x804684BC: sb          $v0, 0x2D2F($v1)
    MEM_B(0X2D2F, ctx->r3) = ctx->r2;
    // 0x804684C0: sh          $t1, 0x2D3A($v1)
    MEM_H(0X2D3A, ctx->r3) = ctx->r9;
    // 0x804684C4: sh          $a1, 0x2D30($v1)
    MEM_H(0X2D30, ctx->r3) = ctx->r5;
    // 0x804684C8: sh          $t3, 0x2D32($v1)
    MEM_H(0X2D32, ctx->r3) = ctx->r11;
    // 0x804684CC: sh          $zero, 0x2D34($v1)
    MEM_H(0X2D34, ctx->r3) = 0;
    // 0x804684D0: sh          $zero, 0x2D36($v1)
    MEM_H(0X2D36, ctx->r3) = 0;
    // 0x804684D4: sh          $zero, 0x2D38($v1)
    MEM_H(0X2D38, ctx->r3) = 0;
    // 0x804684D8: sb          $v0, 0x2D3C($v1)
    MEM_B(0X2D3C, ctx->r3) = ctx->r2;
    // 0x804684DC: sb          $v0, 0x2D3D($v1)
    MEM_B(0X2D3D, ctx->r3) = ctx->r2;
    // 0x804684E0: sb          $v0, 0x2D3E($v1)
    MEM_B(0X2D3E, ctx->r3) = ctx->r2;
    // 0x804684E4: sb          $v0, 0x2D3F($v1)
    MEM_B(0X2D3F, ctx->r3) = ctx->r2;
    // 0x804684E8: sh          $a1, 0x2D40($v1)
    MEM_H(0X2D40, ctx->r3) = ctx->r5;
    // 0x804684EC: sh          $t3, 0x2D42($v1)
    MEM_H(0X2D42, ctx->r3) = ctx->r11;
    // 0x804684F0: sh          $zero, 0x2D44($v1)
    MEM_H(0X2D44, ctx->r3) = 0;
    // 0x804684F4: sh          $zero, 0x2D46($v1)
    MEM_H(0X2D46, ctx->r3) = 0;
    // 0x804684F8: sh          $zero, 0x2D48($v1)
    MEM_H(0X2D48, ctx->r3) = 0;
    // 0x804684FC: sh          $t4, 0x2D4A($v1)
    MEM_H(0X2D4A, ctx->r3) = ctx->r12;
    // 0x80468500: sb          $v0, 0x2D4C($v1)
    MEM_B(0X2D4C, ctx->r3) = ctx->r2;
    // 0x80468504: sb          $v0, 0x2D4D($v1)
    MEM_B(0X2D4D, ctx->r3) = ctx->r2;
    // 0x80468508: sb          $v0, 0x2D4E($v1)
    MEM_B(0X2D4E, ctx->r3) = ctx->r2;
    // 0x8046850C: sb          $v0, 0x2D4F($v1)
    MEM_B(0X2D4F, ctx->r3) = ctx->r2;
    // 0x80468510: sh          $t2, 0x2D50($v1)
    MEM_H(0X2D50, ctx->r3) = ctx->r10;
    // 0x80468514: sh          $a2, 0x2D58($v1)
    MEM_H(0X2D58, ctx->r3) = ctx->r6;
    // 0x80468518: sh          $zero, 0x2D52($v1)
    MEM_H(0X2D52, ctx->r3) = 0;
    // 0x8046851C: sh          $zero, 0x2D54($v1)
    MEM_H(0X2D54, ctx->r3) = 0;
    // 0x80468520: sh          $zero, 0x2D56($v1)
    MEM_H(0X2D56, ctx->r3) = 0;
    // 0x80468524: sh          $t4, 0x2D5A($v1)
    MEM_H(0X2D5A, ctx->r3) = ctx->r12;
    // 0x80468528: sb          $v0, 0x2D5C($v1)
    MEM_B(0X2D5C, ctx->r3) = ctx->r2;
    // 0x8046852C: sb          $v0, 0x2D5D($v1)
    MEM_B(0X2D5D, ctx->r3) = ctx->r2;
    // 0x80468530: sb          $v0, 0x2D5E($v1)
    MEM_B(0X2D5E, ctx->r3) = ctx->r2;
    // 0x80468534: sb          $v0, 0x2D5F($v1)
    MEM_B(0X2D5F, ctx->r3) = ctx->r2;
    // 0x80468538: addiu       $a0, $v1, 0x2D60
    ctx->r4 = ADD32(ctx->r3, 0X2D60);
    // 0x8046853C: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x80468540: lh          $t6, 0x1A($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1A);
    // 0x80468544: sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    // 0x80468548: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x8046854C: bgez        $t6, L_8046855C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80468550: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8046855C;
    }
    // 0x80468550: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80468554: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80468558: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8046855C:
    // 0x8046855C: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x80468560: lh          $t8, 0x18($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X18);
    // 0x80468564: sll         $t9, $t8, 7
    ctx->r25 = S32(ctx->r24 << 7);
    // 0x80468568: sh          $t9, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r25;
    // 0x8046856C: lh          $t5, 0x1A($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1A);
    // 0x80468570: sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
    // 0x80468574: sb          $v0, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r2;
    // 0x80468578: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8046857C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80468580: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x80468584: sh          $t8, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r24;
    // 0x80468588: sb          $v0, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r2;
    // 0x8046858C: sb          $v0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r2;
    // 0x80468590: lh          $t9, 0x18($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X18);
    // 0x80468594: lh          $a3, 0x1A($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X1A);
    // 0x80468598: sb          $v0, 0x2D7F($v1)
    MEM_B(0X2D7F, ctx->r3) = ctx->r2;
    // 0x8046859C: negu        $t5, $t9
    ctx->r13 = SUB32(0, ctx->r25);
    // 0x804685A0: bgez        $t5, L_804685B0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x804685A4: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_804685B0;
    }
    // 0x804685A4: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x804685A8: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x804685AC: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_804685B0:
    // 0x804685B0: sra         $t8, $a3, 1
    ctx->r24 = S32(SIGNED(ctx->r7) >> 1);
    // 0x804685B4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x804685B8: sll         $t5, $t9, 7
    ctx->r13 = S32(ctx->r25 << 7);
    // 0x804685BC: sh          $t5, 0x2D7A($v1)
    MEM_H(0X2D7A, ctx->r3) = ctx->r13;
    // 0x804685C0: sh          $t6, 0x2D70($v1)
    MEM_H(0X2D70, ctx->r3) = ctx->r14;
    // 0x804685C4: bgez        $a3, L_804685D4
    if (SIGNED(ctx->r7) >= 0) {
        // 0x804685C8: sra         $t7, $a3, 1
        ctx->r15 = S32(SIGNED(ctx->r7) >> 1);
            goto L_804685D4;
    }
    // 0x804685C8: sra         $t7, $a3, 1
    ctx->r15 = S32(SIGNED(ctx->r7) >> 1);
    // 0x804685CC: addiu       $at, $a3, 0x1
    ctx->r1 = ADD32(ctx->r7, 0X1);
    // 0x804685D0: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_804685D4:
    // 0x804685D4: sh          $t7, 0x2D72($v1)
    MEM_H(0X2D72, ctx->r3) = ctx->r15;
    // 0x804685D8: sb          $v0, 0x2D7E($v1)
    MEM_B(0X2D7E, ctx->r3) = ctx->r2;
    // 0x804685DC: sb          $v0, 0x2D7D($v1)
    MEM_B(0X2D7D, ctx->r3) = ctx->r2;
    // 0x804685E0: sb          $v0, 0x2D7C($v1)
    MEM_B(0X2D7C, ctx->r3) = ctx->r2;
    // 0x804685E4: sh          $zero, 0x2D78($v1)
    MEM_H(0X2D78, ctx->r3) = 0;
    // 0x804685E8: sh          $zero, 0x2D76($v1)
    MEM_H(0X2D76, ctx->r3) = 0;
    // 0x804685EC: sh          $zero, 0x2D74($v1)
    MEM_H(0X2D74, ctx->r3) = 0;
    // 0x804685F0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x804685F4: jal         0x80058958
    // 0x804685F8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80058958(rdram, ctx);
        goto after_4;
    // 0x804685F8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_4:
    // 0x804685FC: beq         $v0, $zero, L_8046868C
    if (ctx->r2 == 0) {
        // 0x80468600: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_8046868C;
    }
    // 0x80468600: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80468604: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80468608: lw          $t6, -0x7BC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BC4);
    // 0x8046860C: lw          $t7, 0x10C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10C);
    // 0x80468610: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80468614: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x80468618: beql        $t9, $zero, L_80468690
    if (ctx->r25 == 0) {
        // 0x8046861C: lw          $t7, 0x16C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X16C);
            goto L_80468690;
    }
    goto skip_3;
    // 0x8046861C: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    skip_3:
    // 0x80468620: jal         0x80056564
    // 0x80468624: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80056564(rdram, ctx);
        goto after_5;
    // 0x80468624: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x80468628: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8046862C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80468630: beq         $v0, $zero, L_8046867C
    if (ctx->r2 == 0) {
        // 0x80468634: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8046867C;
    }
    // 0x80468634: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80468638: lh          $t5, 0x1A($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1A);
    // 0x8046863C: lh          $a3, 0x18($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X18);
    // 0x80468640: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80468644: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80468648: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8046864C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80468650: bgez        $t5, L_80468660
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80468654: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_80468660;
    }
    // 0x80468654: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80468658: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8046865C: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80468660:
    // 0x80468660: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80468664: jal         0x80056584
    // 0x80468668: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_80056584(rdram, ctx);
        goto after_6;
    // 0x80468668: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_6:
    // 0x8046866C: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
    // 0x80468670: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(132, 0XBBC) << 16);
    // 0x80468674: addiu       $t9, $t9, 0x74FC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(132, 0XBBC));
    // 0x80468678: sw          $t9, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r25;
L_8046867C:
    // 0x8046867C: jal         0x8005FCA8
    // 0x80468680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FCA8(rdram, ctx);
        goto after_7;
    // 0x80468680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80468684: b           L_804686A0
    // 0x80468688: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
        goto L_804686A0;
    // 0x80468688: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_8046868C:
    // 0x8046868C: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
L_80468690:
    // 0x80468690: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(132, 0XB5C) << 16);
    // 0x80468694: addiu       $t6, $t6, 0x749C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(132, 0XB5C));
    // 0x80468698: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x8046869C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_804686A0:
    // 0x804686A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804686A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804686A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804686AC: jr          $ra
    // 0x804686B0: nop

    return;
    // 0x804686B0: nop

;}
RECOMP_FUNC void func_80026484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002648C: jal         0x800263B4
    // 0x80026490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800263B4(rdram, ctx);
        goto after_0;
    // 0x80026490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80026494: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80026498: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8002649C: addiu       $t6, $t6, 0x63B4
    ctx->r14 = ADD32(ctx->r14, 0X63B4);
    // 0x800264A0: sw          $t6, 0x160($t7)
    MEM_W(0X160, ctx->r15) = ctx->r14;
    // 0x800264A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800264A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800264AC: jr          $ra
    // 0x800264B0: nop

    return;
    // 0x800264B0: nop

;}
RECOMP_FUNC void func_8001A600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A600: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001A604: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001A608: addiu       $a1, $a1, 0x5B0
    ctx->r5 = ADD32(ctx->r5, 0X5B0);
    // 0x8001A60C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A610: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
L_8001A614:
    // 0x8001A614: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x8001A618: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8001A61C: bne         $t7, $zero, L_8001A630
    if (ctx->r15 != 0) {
        // 0x8001A620: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8001A630;
    }
    // 0x8001A620: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001A624: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x8001A628: jr          $ra
    // 0x8001A62C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8001A62C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8001A630:
    // 0x8001A630: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A634: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8001A638: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001A63C: bnel        $at, $zero, L_8001A614
    if (ctx->r1 != 0) {
        // 0x8001A640: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_8001A614;
    }
    goto skip_0;
    // 0x8001A640: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    skip_0:
    // 0x8001A644: jr          $ra
    // 0x8001A648: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001A648: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8006BF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF6C: jr          $ra
    // 0x8006BF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006BF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006BF74: nop

    // 0x8006BF78: nop

    // 0x8006BF7C: nop

;}
RECOMP_FUNC void func_80006D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006D64: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80006D68: lh          $t6, 0x6E4A($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6E4A);
    // 0x80006D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006D74: bne         $a0, $t6, L_80006D8C
    if (ctx->r4 != ctx->r14) {
        // 0x80006D78: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80006D8C;
    }
    // 0x80006D78: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80006D7C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80006D80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80006D84: b           L_80006DA8
    // 0x80006D88: sh          $t7, 0x6E4A($at)
    MEM_H(0X6E4A, ctx->r1) = ctx->r15;
        goto L_80006DA8;
    // 0x80006D88: sh          $t7, 0x6E4A($at)
    MEM_H(0X6E4A, ctx->r1) = ctx->r15;
L_80006D8C:
    // 0x80006D8C: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80006D90: lh          $t8, 0x6E56($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X6E56);
    // 0x80006D94: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80006D98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80006D9C: bne         $a2, $t8, L_80006DA8
    if (ctx->r6 != ctx->r24) {
        // 0x80006DA0: nop
    
            goto L_80006DA8;
    }
    // 0x80006DA0: nop

    // 0x80006DA4: sh          $t9, 0x6E56($at)
    MEM_H(0X6E56, ctx->r1) = ctx->r25;
L_80006DA8:
    // 0x80006DA8: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x80006DAC: lw          $t1, 0x6D58($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6D58);
    // 0x80006DB0: lui         $t0, 0x800B
    ctx->r8 = S32(0X800B << 16);
    // 0x80006DB4: addiu       $t0, $t0, 0x6D58
    ctx->r8 = ADD32(ctx->r8, 0X6D58);
    // 0x80006DB8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80006DBC: beq         $t1, $zero, L_80006DF4
    if (ctx->r9 == 0) {
        // 0x80006DC0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80006DF4;
    }
    // 0x80006DC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80006DC4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80006DC8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80006DCC: lh          $t2, 0x1E($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1E);
L_80006DD0:
    // 0x80006DD0: bnel        $a2, $t2, L_80006DE0
    if (ctx->r6 != ctx->r10) {
        // 0x80006DD4: lw          $t3, 0x0($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X0);
            goto L_80006DE0;
    }
    goto skip_0;
    // 0x80006DD4: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80006DD8: sh          $a1, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r5;
    // 0x80006DDC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
L_80006DE0:
    // 0x80006DE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80006DE4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80006DE8: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x80006DEC: bnel        $at, $zero, L_80006DD0
    if (ctx->r1 != 0) {
        // 0x80006DF0: lh          $t2, 0x1E($v0)
        ctx->r10 = MEM_H(ctx->r2, 0X1E);
            goto L_80006DD0;
    }
    goto skip_1;
    // 0x80006DF0: lh          $t2, 0x1E($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1E);
    skip_1:
L_80006DF4:
    // 0x80006DF4: jal         0x8000344C
    // 0x80006DF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8000344C(rdram, ctx);
        goto after_0;
    // 0x80006DF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80006DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006E04: jr          $ra
    // 0x80006E08: nop

    return;
    // 0x80006E08: nop

;}
RECOMP_FUNC void func_805805EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805805EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805805F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805805F4: jal         0x80580568
    // 0x805805F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580568(rdram, ctx);
        goto after_0;
    // 0x805805F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805805FC: jal         0x8058050C
    // 0x80580600: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8058050C(rdram, ctx);
        goto after_1;
    // 0x80580600: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80580604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8058060C: jr          $ra
    // 0x80580610: nop

    return;
    // 0x80580610: nop

;}
RECOMP_FUNC void func_80791224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791224: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80791228: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079122C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80791230: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80791234: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80791238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8079123C: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x80791240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80791244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791248: jal         0x807903C4
    // 0x8079124C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x8079124C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80791250: jal         0x80790714
    // 0x80791254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80791254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80791258: bne         $v0, $zero, L_80791270
    if (ctx->r2 != 0) {
        // 0x8079125C: nop
    
            goto L_80791270;
    }
    // 0x8079125C: nop

    // 0x80791260: jal         0x80790A1C
    // 0x80791264: nop

    func_80790A1C(rdram, ctx);
        goto after_2;
    // 0x80791264: nop

    after_2:
    // 0x80791268: beql        $v0, $zero, L_80791320
    if (ctx->r2 == 0) {
        // 0x8079126C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80791320;
    }
    goto skip_0;
    // 0x8079126C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80791270:
    // 0x80791270: jal         0x80790BD0
    // 0x80791274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790BD0(rdram, ctx);
        goto after_3;
    // 0x80791274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80791278: beql        $v0, $zero, L_807912E8
    if (ctx->r2 == 0) {
        // 0x8079127C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807912E8;
    }
    goto skip_1;
    // 0x8079127C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80791280: jal         0x800653D8
    // 0x80791284: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x80791284: nop

    after_4:
    // 0x80791288: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8079128C: bne         $t7, $zero, L_807912E4
    if (ctx->r15 != 0) {
        // 0x80791290: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807912E4;
    }
    // 0x80791290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791298: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8079129C: jal         0x8079393C
    // 0x807912A0: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_8079393C(rdram, ctx);
        goto after_5;
    // 0x807912A0: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_5:
    // 0x807912A4: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x807912A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x807912AC: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x807912B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807912B4: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x807912B8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7ABC) << 16);
    // 0x807912BC: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x807912C0: lwc1        $f8, 0x7E0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7ABC));
    // 0x807912C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807912C8: jal         0x80790C34
    // 0x807912CC: swc1        $f8, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f8.u32l;
    func_80790C34(rdram, ctx);
        goto after_6;
    // 0x807912CC: swc1        $f8, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f8.u32l;
    after_6:
    // 0x807912D0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AC0) << 16);
    // 0x807912D4: lwc1        $f10, 0x7E10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AC0));
    // 0x807912D8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x807912DC: b           L_8079131C
    // 0x807912E0: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
        goto L_8079131C;
    // 0x807912E0: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
L_807912E4:
    // 0x807912E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_807912E8:
    // 0x807912E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807912EC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x807912F0: jal         0x8079393C
    // 0x807912F4: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_8079393C(rdram, ctx);
        goto after_7;
    // 0x807912F4: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_7:
    // 0x807912F8: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x807912FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80791300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791304: jal         0x80790C34
    // 0x80791308: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    func_80790C34(rdram, ctx);
        goto after_8;
    // 0x80791308: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    after_8:
    // 0x8079130C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AC4) << 16);
    // 0x80791310: lwc1        $f4, 0x7E14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AC4));
    // 0x80791314: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80791318: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_8079131C:
    // 0x8079131C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80791320:
    // 0x80791320: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80791324: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80791328: jr          $ra
    // 0x8079132C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8079132C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806B07E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B07E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806B07EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B07F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806B07F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806B07F8: lwc1        $f12, 0x120($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X120);
    // 0x806B07FC: jal         0x80066E88
    // 0x806B0800: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x806B0800: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x806B0804: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806B0808: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806B080C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B0810: lwc1        $f4, 0xC4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x806B0814: lwc1        $f6, 0x100($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X100);
    // 0x806B0818: lwc1        $f16, 0x10C($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10C);
    // 0x806B081C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806B0820: nop

    // 0x806B0824: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806B0828: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x806B082C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x806B0830: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806B0834: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806B0838: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x806B083C: nop

    // 0x806B0840: bc1f        L_806B088C
    if (!c1cs) {
        // 0x806B0844: nop
    
            goto L_806B088C;
    }
    // 0x806B0844: nop

    // 0x806B0848: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x806B084C: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x806B0850: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B0854: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x806B0858: bne         $t7, $zero, L_806B088C
    if (ctx->r15 != 0) {
        // 0x806B085C: addiu       $a1, $sp, 0x1C
        ctx->r5 = ADD32(ctx->r29, 0X1C);
            goto L_806B088C;
    }
    // 0x806B085C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x806B0860: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x806B0864: jal         0x80047534
    // 0x806B0868: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80047534(rdram, ctx);
        goto after_1;
    // 0x806B0868: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_1:
    // 0x806B086C: bne         $v0, $zero, L_806B08D8
    if (ctx->r2 != 0) {
        // 0x806B0870: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_806B08D8;
    }
    // 0x806B0870: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806B0874: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B0878: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806B087C: jal         0x806B0760
    // 0x806B0880: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_806B0760(rdram, ctx);
        goto after_2;
    // 0x806B0880: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x806B0884: b           L_806B08DC
    // 0x806B0888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806B08DC;
    // 0x806B0888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B088C:
    // 0x806B088C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x806B0890: nop

    // 0x806B0894: bc1fl       L_806B08DC
    if (!c1cs) {
        // 0x806B0898: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806B08DC;
    }
    goto skip_0;
    // 0x806B0898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806B089C: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x806B08A0: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x806B08A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B08A8: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x806B08AC: bne         $t9, $zero, L_806B08D8
    if (ctx->r25 != 0) {
        // 0x806B08B0: addiu       $a1, $sp, 0x1C
        ctx->r5 = ADD32(ctx->r29, 0X1C);
            goto L_806B08D8;
    }
    // 0x806B08B0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x806B08B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806B08B8: jal         0x800474D8
    // 0x806B08BC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800474D8(rdram, ctx);
        goto after_3;
    // 0x806B08BC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_3:
    // 0x806B08C0: bne         $v0, $zero, L_806B08D8
    if (ctx->r2 != 0) {
        // 0x806B08C4: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_806B08D8;
    }
    // 0x806B08C4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806B08C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B08CC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806B08D0: jal         0x806B0760
    // 0x806B08D4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_806B0760(rdram, ctx);
        goto after_4;
    // 0x806B08D4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_4:
L_806B08D8:
    // 0x806B08D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B08DC:
    // 0x806B08DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806B08E0: jr          $ra
    // 0x806B08E4: nop

    return;
    // 0x806B08E4: nop

;}
RECOMP_FUNC void func_805C74EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C74EC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x805C74F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C74F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C74F8: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x805C74FC: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C7500: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
    // 0x805C7504: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x805C7508: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x805C750C: bne         $at, $zero, L_805C752C
    if (ctx->r1 != 0) {
        // 0x805C7510: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805C752C;
    }
    // 0x805C7510: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805C7514: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3BEC) << 16);
    // 0x805C7518: lwc1        $f6, -0x5F24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3BEC));
    // 0x805C751C: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x805C7520: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x805C7524: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805C7528: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
L_805C752C:
    // 0x805C752C: beq         $v0, $zero, L_805C7808
    if (ctx->r2 == 0) {
        // 0x805C7530: lw          $t8, 0x78($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X78);
            goto L_805C7808;
    }
    // 0x805C7530: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x805C7534: lbu         $t9, 0x30($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X30);
    // 0x805C7538: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x805C753C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x805C7540: bne         $t9, $at, L_805C7604
    if (ctx->r25 != ctx->r1) {
        // 0x805C7544: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_805C7604;
    }
    // 0x805C7544: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805C7548: jal         0x80047AB8
    // 0x805C754C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x805C754C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_0:
    // 0x805C7550: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x805C7554: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x805C7558: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x805C755C: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x805C7560: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x805C7564: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x805C7568: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x805C756C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x805C7570: jal         0x80067114
    // 0x805C7574: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    func_80067114(rdram, ctx);
        goto after_1;
    // 0x805C7574: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x805C7578: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x805C757C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805C7580: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805C7584: lw          $t1, 0x138($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X138);
    // 0x805C7588: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x805C758C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x805C7590: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x805C7594: beq         $t1, $zero, L_805C75AC
    if (ctx->r9 == 0) {
        // 0x805C7598: add.s       $f2, $f0, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f10.fl;
            goto L_805C75AC;
    }
    // 0x805C7598: add.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x805C759C: jal         0x80067114
    // 0x805C75A0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_80067114(rdram, ctx);
        goto after_2;
    // 0x805C75A0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_2:
    // 0x805C75A4: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x805C75A8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_805C75AC:
    // 0x805C75AC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x805C75B0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805C75B4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x805C75B8: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x805C75BC: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x805C75C0: bc1fl       L_805C75D8
    if (!c1cs) {
        // 0x805C75C4: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_805C75D8;
    }
    goto skip_0;
    // 0x805C75C4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x805C75C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805C75CC: nop

    // 0x805C75D0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x805C75D4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_805C75D8:
    // 0x805C75D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805C75DC: nop

    // 0x805C75E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805C75E4: nop

    // 0x805C75E8: bc1fl       L_805C75F8
    if (!c1cs) {
        // 0x805C75EC: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_805C75F8;
    }
    goto skip_1;
    // 0x805C75EC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_1:
    // 0x805C75F0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x805C75F4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_805C75F8:
    // 0x805C75F8: jal         0x805C70B0
    // 0x805C75FC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_805C70B0(rdram, ctx);
        goto after_3;
    // 0x805C75FC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_3:
    // 0x805C7600: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
L_805C7604:
    // 0x805C7604: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x805C7608: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805C760C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805C7610: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x805C7614: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
    // 0x805C7618: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x805C761C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805C7620: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805C7624: lw          $t3, 0x138($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X138);
    // 0x805C7628: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x805C762C: bnel        $t3, $zero, L_805C7640
    if (ctx->r11 != 0) {
        // 0x805C7630: lwc1        $f12, 0x50($t4)
        ctx->f12.u32l = MEM_W(ctx->r12, 0X50);
            goto L_805C7640;
    }
    goto skip_2;
    // 0x805C7630: lwc1        $f12, 0x50($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X50);
    skip_2:
    // 0x805C7634: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805C7638: nop

    // 0x805C763C: lwc1        $f12, 0x50($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X50);
L_805C7640:
    // 0x805C7640: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x805C7644: jal         0x80066E88
    // 0x805C7648: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x805C7648: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_4:
    // 0x805C764C: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x805C7650: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805C7654: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805C7658: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x805C765C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x805C7660: lwc1        $f10, 0x3C($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X3C);
    // 0x805C7664: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805C7668: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x805C766C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x805C7670: jal         0x80066DE4
    // 0x805C7674: lwc1        $f12, 0x50($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x805C7674: lwc1        $f12, 0x50($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X50);
    after_5:
    // 0x805C7678: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x805C767C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805C7680: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805C7684: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x805C7688: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x805C768C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805C7690: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x805C7694: lwc1        $f4, 0x40($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X40);
    // 0x805C7698: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x805C769C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C76A0: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x805C76A4: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x805C76A8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x805C76AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C76B0: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x805C76B4: lwc1        $f2, 0x3C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C76B8: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C76BC: sub.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x805C76C0: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x805C76C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C76C8: sub.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x805C76CC: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x805C76D0: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x805C76D4: add.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x805C76D8: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x805C76DC: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x805C76E0: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x805C76E4: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x805C76E8: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x805C76EC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x805C76F0: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x805C76F4: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x805C76F8: nop

    // 0x805C76FC: bc1f        L_805C772C
    if (!c1cs) {
        // 0x805C7700: nop
    
            goto L_805C772C;
    }
    // 0x805C7700: nop

    // 0x805C7704: lw          $t7, 0x48($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X48);
    // 0x805C7708: bne         $t7, $zero, L_805C772C
    if (ctx->r15 != 0) {
        // 0x805C770C: nop
    
            goto L_805C772C;
    }
    // 0x805C770C: nop

    // 0x805C7710: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x805C7714: sll         $v1, $zero, 2
    ctx->r3 = S32(0 << 2);
    // 0x805C7718: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x805C771C: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x805C7720: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x805C7724: b           L_805C773C
    // 0x805C7728: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
        goto L_805C773C;
    // 0x805C7728: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
L_805C772C:
    // 0x805C772C: jal         0x800447C8
    // 0x805C7730: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x805C7730: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    after_6:
    // 0x805C7734: b           L_805C780C
    // 0x805C7738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C780C;
    // 0x805C7738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C773C:
    // 0x805C773C: lh          $a1, 0x184($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X184);
    // 0x805C7740: beql        $a1, $zero, L_805C7790
    if (ctx->r5 == 0) {
        // 0x805C7744: lwc1        $f0, 0x70($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X70);
            goto L_805C7790;
    }
    goto skip_3;
    // 0x805C7744: lwc1        $f0, 0x70($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X70);
    skip_3:
    // 0x805C7748: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
L_805C774C:
    // 0x805C774C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x805C7750: beq         $v0, $zero, L_805C777C
    if (ctx->r2 == 0) {
        // 0x805C7754: nop
    
            goto L_805C777C;
    }
    // 0x805C7754: nop

    // 0x805C7758: lwc1        $f0, 0x6C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x805C775C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x805C7760: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x805C7764: nop

    // 0x805C7768: bc1f        L_805C777C
    if (!c1cs) {
        // 0x805C776C: nop
    
            goto L_805C777C;
    }
    // 0x805C776C: nop

    // 0x805C7770: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x805C7774: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x805C7778: swc1        $f10, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f10.u32l;
L_805C777C:
    // 0x805C777C: beq         $a1, $zero, L_805C778C
    if (ctx->r5 == 0) {
        // 0x805C7780: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_805C778C;
    }
    // 0x805C7780: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x805C7784: bnel        $v1, $a2, L_805C774C
    if (ctx->r3 != ctx->r6) {
        // 0x805C7788: lw          $v0, 0x188($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X188);
            goto L_805C774C;
    }
    goto skip_4;
    // 0x805C7788: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    skip_4:
L_805C778C:
    // 0x805C778C: lwc1        $f0, 0x70($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X70);
L_805C7790:
    // 0x805C7790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805C7794: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x805C7798: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x805C779C: addu        $a0, $s0, $v1
    ctx->r4 = ADD32(ctx->r16, ctx->r3);
    // 0x805C77A0: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x805C77A4: bc1fl       L_805C77BC
    if (!c1cs) {
        // 0x805C77A8: lh          $a1, 0x184($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X184);
            goto L_805C77BC;
    }
    goto skip_5;
    // 0x805C77A8: lh          $a1, 0x184($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X184);
    skip_5:
    // 0x805C77AC: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x805C77B0: sub.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x805C77B4: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x805C77B8: lh          $a1, 0x184($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X184);
L_805C77BC:
    // 0x805C77BC: beql        $a1, $zero, L_805C780C
    if (ctx->r5 == 0) {
        // 0x805C77C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805C780C;
    }
    goto skip_6;
    // 0x805C77C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x805C77C4: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
L_805C77C8:
    // 0x805C77C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x805C77CC: beq         $v0, $zero, L_805C77F8
    if (ctx->r2 == 0) {
        // 0x805C77D0: nop
    
            goto L_805C77F8;
    }
    // 0x805C77D0: nop

    // 0x805C77D4: lwc1        $f0, 0x70($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X70);
    // 0x805C77D8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x805C77DC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x805C77E0: nop

    // 0x805C77E4: bc1f        L_805C77F8
    if (!c1cs) {
        // 0x805C77E8: nop
    
            goto L_805C77F8;
    }
    // 0x805C77E8: nop

    // 0x805C77EC: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x805C77F0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x805C77F4: swc1        $f10, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f10.u32l;
L_805C77F8:
    // 0x805C77F8: beq         $a1, $zero, L_805C7808
    if (ctx->r5 == 0) {
        // 0x805C77FC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_805C7808;
    }
    // 0x805C77FC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x805C7800: bnel        $v1, $a2, L_805C77C8
    if (ctx->r3 != ctx->r6) {
        // 0x805C7804: lw          $v0, 0x188($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X188);
            goto L_805C77C8;
    }
    goto skip_7;
    // 0x805C7804: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    skip_7:
L_805C7808:
    // 0x805C7808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C780C:
    // 0x805C780C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C7810: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x805C7814: jr          $ra
    // 0x805C7818: nop

    return;
    // 0x805C7818: nop

;}
RECOMP_FUNC void func_8044A6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A6F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044A6F8: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13454) << 16);
    // 0x8044A6FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A700: addiu       $t6, $t6, 0x7834
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13454));
    // 0x8044A704: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044A708: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044A70C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044A710: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044A714: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044A718: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A71C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044A720: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044A724: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044A728: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044A72C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044A730: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044A734: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044A738: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044A73C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044A740: jal         0x80050A50
    // 0x8044A744: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044A744: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044A748: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044A74C: jalr        $v0
    // 0x8044A750: sw          $v0, 0x6A50($v1)
    MEM_W(0X6A50, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044A750: sw          $v0, 0x6A50($v1)
    MEM_W(0X6A50, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044A754: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A758: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8044A75C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044A760: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044A764: jr          $ra
    // 0x8044A768: nop

    return;
    // 0x8044A768: nop

;}
RECOMP_FUNC void func_805D0010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D0010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D0014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D0018: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805D001C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x805D0020: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805D0024: jal         0x80048F84
    // 0x805D0028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x805D0028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x805D002C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805D0030: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805D0034: lw          $t6, 0x1E0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1E0);
    // 0x805D0038: bnel        $t6, $at, L_805D0074
    if (ctx->r14 != ctx->r1) {
        // 0x805D003C: lw          $t0, 0x1E0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X1E0);
            goto L_805D0074;
    }
    goto skip_0;
    // 0x805D003C: lw          $t0, 0x1E0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X1E0);
    skip_0:
    // 0x805D0040: lh          $t7, 0x144($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X144);
    // 0x805D0044: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x805D0048: sw          $zero, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = 0;
    // 0x805D004C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x805D0050: sh          $t8, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r24;
    // 0x805D0054: lh          $t9, 0x144($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X144);
    // 0x805D0058: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805D005C: bnel        $t9, $at, L_805D0074
    if (ctx->r25 != ctx->r1) {
        // 0x805D0060: lw          $t0, 0x1E0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X1E0);
            goto L_805D0074;
    }
    goto skip_1;
    // 0x805D0060: lw          $t0, 0x1E0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X1E0);
    skip_1:
    // 0x805D0064: jal         0x800447C8
    // 0x805D0068: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x805D0068: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x805D006C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805D0070: lw          $t0, 0x1E0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X1E0);
L_805D0074:
    // 0x805D0074: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x805D0078: sw          $t1, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r9;
    // 0x805D007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D0080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D0084: jr          $ra
    // 0x805D0088: nop

    return;
    // 0x805D0088: nop

;}
RECOMP_FUNC void func_8042E7AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E7AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042E7B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E7B4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042E7B8: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8042E7BC: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X32B0) << 16);
    // 0x8042E7C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042E7C4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042E7C8: lw          $t8, 0x1390($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X32B0));
    // 0x8042E7CC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042E7D0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8042E7D4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8042E7D8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8042E7DC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042E7E0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8042E7E4: beql        $v1, $zero, L_8042E818
    if (ctx->r3 == 0) {
        // 0x8042E7E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042E818;
    }
    goto skip_0;
    // 0x8042E7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042E7EC: jalr        $v1
    // 0x8042E7F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8042E7F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042E7F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042E7F8: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8042E7FC: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8042E800: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8042E804: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8042E808: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8042E80C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8042E810: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8042E814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042E818:
    // 0x8042E818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042E81C: jr          $ra
    // 0x8042E820: nop

    return;
    // 0x8042E820: nop

;}
RECOMP_FUNC void func_8044A9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A9FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044AA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AA04: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044AA08: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044AA0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044AA10: jal         0x8044A558
    // 0x8044AA14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044AA14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8044AA18: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AA1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044AA20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044AA24: bne         $v0, $zero, L_8044AA3C
    if (ctx->r2 != 0) {
        // 0x8044AA28: nop
    
            goto L_8044AA3C;
    }
    // 0x8044AA28: nop

    // 0x8044AA2C: jal         0x804461C0
    // 0x8044AA30: nop

    func_804461C0(rdram, ctx);
        goto after_1;
    // 0x8044AA30: nop

    after_1:
    // 0x8044AA34: b           L_8044AA60
    // 0x8044AA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044AA60;
    // 0x8044AA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AA3C:
    // 0x8044AA3C: bne         $v0, $at, L_8044AA54
    if (ctx->r2 != ctx->r1) {
        // 0x8044AA40: nop
    
            goto L_8044AA54;
    }
    // 0x8044AA40: nop

    // 0x8044AA44: jal         0x8044620C
    // 0x8044AA48: nop

    func_8044620C(rdram, ctx);
        goto after_2;
    // 0x8044AA48: nop

    after_2:
    // 0x8044AA4C: b           L_8044AA60
    // 0x8044AA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044AA60;
    // 0x8044AA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AA54:
    // 0x8044AA54: jal         0x8044625C
    // 0x8044AA58: nop

    func_8044625C(rdram, ctx);
        goto after_3;
    // 0x8044AA58: nop

    after_3:
    // 0x8044AA5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AA60:
    // 0x8044AA60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044AA64: jr          $ra
    // 0x8044AA68: nop

    return;
    // 0x8044AA68: nop

;}
RECOMP_FUNC void func_805A3FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3FE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A3FEC: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1D84) << 16);
    // 0x805A3FF0: lwc1        $f2, 0x5114($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1D84));
    // 0x805A3FF4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805A3FF8: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x805A3FFC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805A4000: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x805A4004: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805A4008: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x805A400C: nop

    // 0x805A4010: bc1f        L_805A4020
    if (!c1cs) {
        // 0x805A4014: nop
    
            goto L_805A4020;
    }
    // 0x805A4014: nop

    // 0x805A4018: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x805A401C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_805A4020:
    // 0x805A4020: jr          $ra
    // 0x805A4024: nop

    return;
    // 0x805A4024: nop

;}
RECOMP_FUNC void func_8003AD58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AD58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003AD5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003AD60: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003AD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AD68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003AD6C: beq         $a1, $at, L_8003AD90
    if (ctx->r5 == ctx->r1) {
        // 0x8003AD70: lw          $v0, 0x174($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X174);
            goto L_8003AD90;
    }
    // 0x8003AD70: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8003AD74: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8003AD78: bnel        $a1, $at, L_8003ADF4
    if (ctx->r5 != ctx->r1) {
        // 0x8003AD7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003ADF4;
    }
    goto skip_0;
    // 0x8003AD7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003AD80: jal         0x8003B540
    // 0x8003AD84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8003B540(rdram, ctx);
        goto after_0;
    // 0x8003AD84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8003AD88: b           L_8003ADF4
    // 0x8003AD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003ADF4;
    // 0x8003AD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003AD90:
    // 0x8003AD90: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    // 0x8003AD94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003AD98: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003AD9C: bne         $a1, $at, L_8003ADB4
    if (ctx->r5 != ctx->r1) {
        // 0x8003ADA0: sb          $t6, 0x18($a0)
        MEM_B(0X18, ctx->r4) = ctx->r14;
            goto L_8003ADB4;
    }
    // 0x8003ADA0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8003ADA4: jal         0x8003B540
    // 0x8003ADA8: nop

    func_8003B540(rdram, ctx);
        goto after_1;
    // 0x8003ADA8: nop

    after_1:
    // 0x8003ADAC: b           L_8003ADF4
    // 0x8003ADB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003ADF4;
    // 0x8003ADB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003ADB4:
    // 0x8003ADB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003ADB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8003ADBC: jal         0x8003B540
    // 0x8003ADC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8003B540(rdram, ctx);
        goto after_2;
    // 0x8003ADC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8003ADC4: jal         0x8003AF20
    // 0x8003ADC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8003AF20(rdram, ctx);
        goto after_3;
    // 0x8003ADC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8003ADCC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003ADD0: addiu       $t7, $zero, 0x102
    ctx->r15 = ADD32(0, 0X102);
    // 0x8003ADD4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8003ADD8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003ADDC: addiu       $t9, $t9, -0x6030
    ctx->r25 = ADD32(ctx->r25, -0X6030);
    // 0x8003ADE0: sh          $t7, 0x4C($t8)
    MEM_H(0X4C, ctx->r24) = ctx->r15;
    // 0x8003ADE4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003ADE8: sw          $t9, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r25;
    // 0x8003ADEC: sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
    // 0x8003ADF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003ADF4:
    // 0x8003ADF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003ADF8: jr          $ra
    // 0x8003ADFC: nop

    return;
    // 0x8003ADFC: nop

;}
RECOMP_FUNC void guMtxCatL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B2E0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8008B2E4: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x8008B2E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8008B2EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B2F0: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x8008B2F4: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x8008B2F8: jal         0x80086F58
    // 0x8008B2FC: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    guMtxL2F(rdram, ctx);
        goto after_0;
    // 0x8008B2FC: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    after_0:
    // 0x8008B300: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8008B304: jal         0x80086F58
    // 0x8008B308: lw          $a1, 0xDC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XDC);
    guMtxL2F(rdram, ctx);
        goto after_1;
    // 0x8008B308: lw          $a1, 0xDC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XDC);
    after_1:
    // 0x8008B30C: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x8008B310: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8008B314: jal         0x8008B3E0
    // 0x8008B318: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    guMtxCatF(rdram, ctx);
        goto after_2;
    // 0x8008B318: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8008B31C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8008B320: jal         0x80086DA0
    // 0x8008B324: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    guMtxF2L(rdram, ctx);
        goto after_3;
    // 0x8008B324: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_3:
    // 0x8008B328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B32C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x8008B330: jr          $ra
    // 0x8008B334: nop

    return;
    // 0x8008B334: nop

;}
RECOMP_FUNC void func_8002EE98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EE98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002EE9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002EEA0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002EEA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002EEA8: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x8002EEAC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002EEB0: jal         0x8002B9E4
    // 0x8002EEB4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002EEB4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8002EEB8: jal         0x8002DAF0
    // 0x8002EEBC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8002DAF0(rdram, ctx);
        goto after_1;
    // 0x8002EEBC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002EEC0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002EEC4: sb          $zero, 0x1AD($t7)
    MEM_B(0X1AD, ctx->r15) = 0;
    // 0x8002EEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002EECC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002EED0: jr          $ra
    // 0x8002EED4: nop

    return;
    // 0x8002EED4: nop

;}
RECOMP_FUNC void func_804CF834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CF838: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CF83C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CF840: jal         0x8004700C
    // 0x804CF844: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804CF844: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804CF848: beql        $v0, $zero, L_804CF8C4
    if (ctx->r2 == 0) {
        // 0x804CF84C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CF8C4;
    }
    goto skip_0;
    // 0x804CF84C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804CF850: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x804CF854: bne         $s0, $t6, L_804CF88C
    if (ctx->r16 != ctx->r14) {
        // 0x804CF858: nop
    
            goto L_804CF88C;
    }
    // 0x804CF858: nop

    // 0x804CF85C: jal         0x804CF608
    // 0x804CF860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF608(rdram, ctx);
        goto after_1;
    // 0x804CF860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804CF864: lui         $a1, 0x804D
    ctx->r5 = S32(RELOC_HI16(240, 0X1408) << 16);
    // 0x804CF868: addiu       $a1, $a1, -0x948
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(240, 0X1408));
    // 0x804CF86C: jal         0x800628E4
    // 0x804CF870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800628E4(rdram, ctx);
        goto after_2;
    // 0x804CF870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804CF874: jal         0x804CF450
    // 0x804CF878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF450(rdram, ctx);
        goto after_3;
    // 0x804CF878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804CF87C: jal         0x804CF440
    // 0x804CF880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF440(rdram, ctx);
        goto after_4;
    // 0x804CF880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804CF884: b           L_804CF8B8
    // 0x804CF888: nop

        goto L_804CF8B8;
    // 0x804CF888: nop

L_804CF88C:
    // 0x804CF88C: jal         0x804CF4E4
    // 0x804CF890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF4E4(rdram, ctx);
        goto after_5;
    // 0x804CF890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804CF894: jal         0x804CF450
    // 0x804CF898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF450(rdram, ctx);
        goto after_6;
    // 0x804CF898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804CF89C: jal         0x804CF440
    // 0x804CF8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF440(rdram, ctx);
        goto after_7;
    // 0x804CF8A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x804CF8A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CF8A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CF8AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CF8B0: jal         0x804CFBB8
    // 0x804CF8B4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804CFBB8(rdram, ctx);
        goto after_8;
    // 0x804CF8B4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_8:
L_804CF8B8:
    // 0x804CF8B8: jal         0x804CF3A4
    // 0x804CF8BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CF3A4(rdram, ctx);
        goto after_9;
    // 0x804CF8BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x804CF8C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CF8C4:
    // 0x804CF8C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CF8C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CF8CC: jr          $ra
    // 0x804CF8D0: nop

    return;
    // 0x804CF8D0: nop

;}
RECOMP_FUNC void func_80422C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422C1C: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x80422C20: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(35, 0X2E48) << 16);
    // 0x80422C24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80422C28: addiu       $t7, $t7, 0x5848
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(35, 0X2E48));
    // 0x80422C2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80422C30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80422C34: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80422C38: addiu       $t6, $sp, 0xAC
    ctx->r14 = ADD32(ctx->r29, 0XAC);
L_80422C3C:
    // 0x80422C3C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80422C40: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80422C44: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80422C48: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80422C4C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80422C50: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80422C54: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80422C58: bne         $t7, $t0, L_80422C3C
    if (ctx->r15 != ctx->r8) {
        // 0x80422C5C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80422C3C;
    }
    // 0x80422C5C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80422C60: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(35, 0X2E84) << 16);
    // 0x80422C64: addiu       $t2, $t2, 0x5884
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(35, 0X2E84));
    // 0x80422C68: addiu       $t5, $t2, 0x3C
    ctx->r13 = ADD32(ctx->r10, 0X3C);
    // 0x80422C6C: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
L_80422C70:
    // 0x80422C70: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80422C74: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80422C78: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80422C7C: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80422C80: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80422C84: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80422C88: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80422C8C: bne         $t2, $t5, L_80422C70
    if (ctx->r10 != ctx->r13) {
        // 0x80422C90: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80422C70;
    }
    // 0x80422C90: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80422C94: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(35, 0X2EC0) << 16);
    // 0x80422C98: addiu       $t7, $t7, 0x58C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(35, 0X2EC0));
    // 0x80422C9C: addiu       $t9, $t7, 0x3C
    ctx->r25 = ADD32(ctx->r15, 0X3C);
    // 0x80422CA0: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
L_80422CA4:
    // 0x80422CA4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80422CA8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80422CAC: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80422CB0: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x80422CB4: lw          $t6, -0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, -0X8);
    // 0x80422CB8: sw          $t6, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r14;
    // 0x80422CBC: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80422CC0: bne         $t7, $t9, L_80422CA4
    if (ctx->r15 != ctx->r25) {
        // 0x80422CC4: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_80422CA4;
    }
    // 0x80422CC4: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x80422CC8: jal         0x80422BDC
    // 0x80422CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80422BDC(rdram, ctx);
        goto after_0;
    // 0x80422CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80422CD0: jal         0x8004700C
    // 0x80422CD4: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x80422CD4: nop

    after_1:
    // 0x80422CD8: beq         $v0, $zero, L_80422DA0
    if (ctx->r2 == 0) {
        // 0x80422CDC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80422DA0;
    }
    // 0x80422CDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80422CE0: jal         0x80047AB8
    // 0x80422CE4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x80422CE4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80422CE8: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80422CEC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80422CF0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80422CF4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80422CF8: nop

    // 0x80422CFC: bc1fl       L_80422D2C
    if (!c1cs) {
        // 0x80422D00: c.lt.s      $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
            goto L_80422D2C;
    }
    goto skip_0;
    // 0x80422D00: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    skip_0:
    // 0x80422D04: lh          $t5, 0x144($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X144);
    // 0x80422D08: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80422D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80422D10: beql        $t5, $at, L_80422DA4
    if (ctx->r13 == ctx->r1) {
        // 0x80422D14: lh          $t1, 0x144($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X144);
            goto L_80422DA4;
    }
    goto skip_1;
    // 0x80422D14: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
    skip_1:
    // 0x80422D18: jal         0x80422BF4
    // 0x80422D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80422BF4(rdram, ctx);
        goto after_3;
    // 0x80422D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80422D20: b           L_80422DA4
    // 0x80422D24: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
        goto L_80422DA4;
    // 0x80422D24: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
    // 0x80422D28: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
L_80422D2C:
    // 0x80422D2C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80422D30: bc1fl       L_80422D5C
    if (!c1cs) {
        // 0x80422D34: c.eq.s      $f0, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
            goto L_80422D5C;
    }
    goto skip_2;
    // 0x80422D34: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    skip_2:
    // 0x80422D38: lh          $t2, 0x144($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X144);
    // 0x80422D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80422D40: beql        $t2, $zero, L_80422DA4
    if (ctx->r10 == 0) {
        // 0x80422D44: lh          $t1, 0x144($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X144);
            goto L_80422DA4;
    }
    goto skip_3;
    // 0x80422D44: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
    skip_3:
    // 0x80422D48: jal         0x80422BF4
    // 0x80422D4C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80422BF4(rdram, ctx);
        goto after_4;
    // 0x80422D4C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_4:
    // 0x80422D50: b           L_80422DA4
    // 0x80422D54: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
        goto L_80422DA4;
    // 0x80422D54: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
    // 0x80422D58: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
L_80422D5C:
    // 0x80422D5C: nop

    // 0x80422D60: bc1fl       L_80422DA4
    if (!c1cs) {
        // 0x80422D64: lh          $t1, 0x144($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X144);
            goto L_80422DA4;
    }
    goto skip_4;
    // 0x80422D64: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
    skip_4:
    // 0x80422D68: lh          $v0, 0x144($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X144);
    // 0x80422D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80422D70: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80422D74: beql        $at, $zero, L_80422D90
    if (ctx->r1 == 0) {
        // 0x80422D78: slti        $at, $v0, 0x8
        ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_80422D90;
    }
    goto skip_5;
    // 0x80422D78: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    skip_5:
    // 0x80422D7C: jal         0x80422BF4
    // 0x80422D80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80422BF4(rdram, ctx);
        goto after_5;
    // 0x80422D80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80422D84: b           L_80422DA4
    // 0x80422D88: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
        goto L_80422DA4;
    // 0x80422D88: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
    // 0x80422D8C: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
L_80422D90:
    // 0x80422D90: bne         $at, $zero, L_80422DA0
    if (ctx->r1 != 0) {
        // 0x80422D94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80422DA0;
    }
    // 0x80422D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80422D98: jal         0x80422BF4
    // 0x80422D9C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80422BF4(rdram, ctx);
        goto after_6;
    // 0x80422D9C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_6:
L_80422DA0:
    // 0x80422DA0: lh          $t1, 0x144($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X144);
L_80422DA4:
    // 0x80422DA4: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80422DA8: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80422DAC: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80422DB0: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80422DB4: lwc1        $f16, 0xAC($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XAC);
    // 0x80422DB8: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36C4) << 16);
    // 0x80422DBC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80422DC0: swc1        $f18, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f18.u32l;
    // 0x80422DC4: lh          $t9, 0x144($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X144);
    // 0x80422DC8: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80422DCC: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80422DD0: addu        $t0, $sp, $t7
    ctx->r8 = ADD32(ctx->r29, ctx->r15);
    // 0x80422DD4: lwc1        $f6, 0x70($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X70);
    // 0x80422DD8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80422DDC: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    // 0x80422DE0: lwc1        $f10, 0x60C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(35, 0X36C4));
    // 0x80422DE4: swc1        $f10, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f10.u32l;
    // 0x80422DE8: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80422DEC: swc1        $f16, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f16.u32l;
    // 0x80422DF0: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80422DF4: swc1        $f18, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f18.u32l;
    // 0x80422DF8: lh          $t6, 0x144($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X144);
    // 0x80422DFC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80422E00: addu        $t5, $sp, $t8
    ctx->r13 = ADD32(ctx->r29, ctx->r24);
    // 0x80422E04: lwc1        $f4, 0x34($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X34);
    // 0x80422E08: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80422E0C: swc1        $f6, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f6.u32l;
    // 0x80422E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80422E14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80422E18: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x80422E1C: jr          $ra
    // 0x80422E20: nop

    return;
    // 0x80422E20: nop

;}
RECOMP_FUNC void func_807997F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807997F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807997F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807997F8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807997FC: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(826, 0X2500) << 16);
    // 0x80799800: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80799804: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80799808: addiu       $t6, $t6, -0x4FE0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(826, 0X2500));
    // 0x8079980C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80799810: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80799814: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80799818: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8079981C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80799820: jal         0x80799840
    // 0x80799824: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80799840(rdram, ctx);
        goto after_0;
    // 0x80799824: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80799828: jal         0x80799780
    // 0x8079982C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80799780(rdram, ctx);
        goto after_1;
    // 0x8079982C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80799830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80799838: jr          $ra
    // 0x8079983C: nop

    return;
    // 0x8079983C: nop

;}
RECOMP_FUNC void func_806FDAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FDAE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FDAEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FDAF0: jal         0x806FD768
    // 0x806FDAF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806FD768(rdram, ctx);
        goto after_0;
    // 0x806FDAF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FDAF8: beq         $v0, $zero, L_806FDB20
    if (ctx->r2 == 0) {
        // 0x806FDAFC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806FDB20;
    }
    // 0x806FDAFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FDB00: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806FDB04: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x806FDB08: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x806FDB0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDB10: jal         0x806FE468
    // 0x806FDB14: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806FE468(rdram, ctx);
        goto after_1;
    // 0x806FDB14: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x806FDB18: b           L_806FDB44
    // 0x806FDB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806FDB44;
    // 0x806FDB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FDB20:
    // 0x806FDB20: jal         0x806FD720
    // 0x806FDB24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806FD720(rdram, ctx);
        goto after_2;
    // 0x806FDB24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x806FDB28: beq         $v0, $zero, L_806FDB40
    if (ctx->r2 == 0) {
        // 0x806FDB2C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806FDB40;
    }
    // 0x806FDB2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FDB30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FDB34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806FDB38: jal         0x806FE468
    // 0x806FDB3C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806FE468(rdram, ctx);
        goto after_3;
    // 0x806FDB3C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_3:
L_806FDB40:
    // 0x806FDB40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FDB44:
    // 0x806FDB44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FDB48: jr          $ra
    // 0x806FDB4C: nop

    return;
    // 0x806FDB4C: nop

;}
RECOMP_FUNC void func_807B80D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B80D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B80D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B80DC: jal         0x807B7F90
    // 0x807B80E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807B7F90(rdram, ctx);
        goto after_0;
    // 0x807B80E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807B80E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B80E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B80EC: jal         0x807B810C
    // 0x807B80F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807B810C(rdram, ctx);
        goto after_1;
    // 0x807B80F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x807B80F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x807B80F8: sw          $zero, 0x24($t6)
    MEM_W(0X24, ctx->r14) = 0;
    // 0x807B80FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B8100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B8104: jr          $ra
    // 0x807B8108: nop

    return;
    // 0x807B8108: nop

;}
RECOMP_FUNC void func_806F55E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F55E8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x806F55EC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x806F55F0: lw          $t7, -0x77F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X77F8);
    // 0x806F55F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x806F55F8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x806F55FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x806F5600: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x806F5604: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x806F5608: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F560C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806F5610: lh          $t6, -0x77FE($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X77FE);
    // 0x806F5614: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x806F5618: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x806F561C: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x806F5620: subu        $v0, $t6, $t8
    ctx->r2 = SUB32(ctx->r14, ctx->r24);
    // 0x806F5624: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x806F5628: beq         $at, $zero, L_806F564C
    if (ctx->r1 == 0) {
        // 0x806F562C: lui         $s3, 0x806F
        ctx->r19 = S32(RELOC_HI16(685, 0X1198) << 16);
            goto L_806F564C;
    }
    // 0x806F562C: lui         $s3, 0x806F
    ctx->r19 = S32(RELOC_HI16(685, 0X1198) << 16);
    // 0x806F5630: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_806F5634:
    // 0x806F5634: addiu       $t9, $s2, 0x5
    ctx->r25 = ADD32(ctx->r18, 0X5);
    // 0x806F5638: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x806F563C: bnel        $at, $zero, L_806F5634
    if (ctx->r1 != 0) {
        // 0x806F5640: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806F5634;
    }
    goto skip_0;
    // 0x806F5640: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x806F5644: beql        $s2, $zero, L_806F5634
    if (ctx->r18 == 0) {
        // 0x806F5648: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_806F5634;
    }
    goto skip_1;
    // 0x806F5648: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_1:
L_806F564C:
    // 0x806F564C: blez        $s2, L_806F56E8
    if (SIGNED(ctx->r18) <= 0) {
        // 0x806F5650: addiu       $s3, $s3, 0x64F8
        ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(685, 0X1198));
            goto L_806F56E8;
    }
    // 0x806F5650: addiu       $s3, $s3, 0x64F8
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(685, 0X1198));
    // 0x806F5654: lui         $t0, 0x806F
    ctx->r8 = S32(RELOC_HI16(685, 0X11AC) << 16);
    // 0x806F5658: addiu       $s1, $t0, 0x650C
    ctx->r17 = ADD32(ctx->r8, (int16_t)RELOC_LO16(685, 0X11AC));
    // 0x806F565C: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x806F5660: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x806F5664: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x806F5668: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
L_806F566C:
    // 0x806F566C: lwc1        $f6, 0x84($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X84);
    // 0x806F5670: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x806F5674: lwc1        $f16, 0x88($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X88);
    // 0x806F5678: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F567C: lui         $a0, 0x45EF
    ctx->r4 = S32(0X45EF << 16);
    // 0x806F5680: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x806F5684: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806F5688: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x806F568C: ori         $a3, $a3, 0x7AE
    ctx->r7 = ctx->r7 | 0X7AE;
    // 0x806F5690: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x806F5694: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x806F5698: jal         0x8004613C
    // 0x806F569C: nop

    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x806F569C: nop

    after_0:
    // 0x806F56A0: beq         $v0, $zero, L_806F56D4
    if (ctx->r2 == 0) {
        // 0x806F56A4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806F56D4;
    }
    // 0x806F56A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806F56A8: jal         0x80047090
    // 0x806F56AC: addiu       $a0, $zero, 0x45EF
    ctx->r4 = ADD32(0, 0X45EF);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x806F56AC: addiu       $a0, $zero, 0x45EF
    ctx->r4 = ADD32(0, 0X45EF);
    after_1:
    // 0x806F56B0: lhu         $t5, 0xE($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XE);
    // 0x806F56B4: andi        $t4, $v0, 0x3FF
    ctx->r12 = ctx->r2 & 0X3FF;
    // 0x806F56B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F56BC: andi        $t7, $t5, 0xFC00
    ctx->r15 = ctx->r13 & 0XFC00;
    // 0x806F56C0: or          $t6, $t4, $t7
    ctx->r14 = ctx->r12 | ctx->r15;
    // 0x806F56C4: jal         0x80044194
    // 0x806F56C8: sh          $t6, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r14;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x806F56C8: sh          $t6, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r14;
    after_2:
    // 0x806F56CC: jal         0x806F62CC
    // 0x806F56D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F62CC(rdram, ctx);
        goto after_3;
    // 0x806F56D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_806F56D4:
    // 0x806F56D4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x806F56D8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806F56DC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x806F56E0: bnel        $s1, $t8, L_806F566C
    if (ctx->r17 != ctx->r24) {
        // 0x806F56E4: lwc1        $f4, 0x0($s3)
        ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
            goto L_806F566C;
    }
    goto skip_2;
    // 0x806F56E4: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    skip_2:
L_806F56E8:
    // 0x806F56E8: lui         $t9, 0x806F
    ctx->r25 = S32(RELOC_HI16(685, 0XF8) << 16);
    // 0x806F56EC: addiu       $t9, $t9, 0x5458
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(685, 0XF8));
    // 0x806F56F0: sw          $t9, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->r25;
    // 0x806F56F4: lw          $a0, 0x34($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X34);
    // 0x806F56F8: jal         0x80067BBC
    // 0x806F56FC: lw          $a1, 0x38($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806F56FC: lw          $a1, 0x38($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X38);
    after_4:
    // 0x806F5700: lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0XC);
    // 0x806F5704: addiu       $at, $zero, 0x45EE
    ctx->r1 = ADD32(0, 0X45EE);
    // 0x806F5708: beq         $v1, $at, L_806F5910
    if (ctx->r3 == ctx->r1) {
        // 0x806F570C: addiu       $at, $zero, 0x4603
        ctx->r1 = ADD32(0, 0X4603);
            goto L_806F5910;
    }
    // 0x806F570C: addiu       $at, $zero, 0x4603
    ctx->r1 = ADD32(0, 0X4603);
    // 0x806F5710: beq         $v1, $at, L_806F5758
    if (ctx->r3 == ctx->r1) {
        // 0x806F5714: addiu       $t1, $zero, 0x4034
        ctx->r9 = ADD32(0, 0X4034);
            goto L_806F5758;
    }
    // 0x806F5714: addiu       $t1, $zero, 0x4034
    ctx->r9 = ADD32(0, 0X4034);
    // 0x806F5718: addiu       $at, $zero, 0x4604
    ctx->r1 = ADD32(0, 0X4604);
    // 0x806F571C: beq         $v1, $at, L_806F57CC
    if (ctx->r3 == ctx->r1) {
        // 0x806F5720: lui         $a0, 0x403A
        ctx->r4 = S32(0X403A << 16);
            goto L_806F57CC;
    }
    // 0x806F5720: lui         $a0, 0x403A
    ctx->r4 = S32(0X403A << 16);
    // 0x806F5724: addiu       $at, $zero, 0x464C
    ctx->r1 = ADD32(0, 0X464C);
    // 0x806F5728: beq         $v1, $at, L_806F5880
    if (ctx->r3 == ctx->r1) {
        // 0x806F572C: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_806F5880;
    }
    // 0x806F572C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x806F5730: addiu       $at, $zero, 0x464D
    ctx->r1 = ADD32(0, 0X464D);
    // 0x806F5734: beq         $v1, $at, L_806F58D8
    if (ctx->r3 == ctx->r1) {
        // 0x806F5738: addiu       $at, $zero, 0x4676
        ctx->r1 = ADD32(0, 0X4676);
            goto L_806F58D8;
    }
    // 0x806F5738: addiu       $at, $zero, 0x4676
    ctx->r1 = ADD32(0, 0X4676);
    // 0x806F573C: beq         $v1, $at, L_806F5824
    if (ctx->r3 == ctx->r1) {
        // 0x806F5740: lui         $a0, 0x45E6
        ctx->r4 = S32(0X45E6 << 16);
            goto L_806F5824;
    }
    // 0x806F5740: lui         $a0, 0x45E6
    ctx->r4 = S32(0X45E6 << 16);
    // 0x806F5744: addiu       $at, $zero, 0x467B
    ctx->r1 = ADD32(0, 0X467B);
    // 0x806F5748: beq         $v1, $at, L_806F58AC
    if (ctx->r3 == ctx->r1) {
        // 0x806F574C: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_806F58AC;
    }
    // 0x806F574C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x806F5750: b           L_806F5914
    // 0x806F5754: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
        goto L_806F5914;
    // 0x806F5754: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
L_806F5758:
    // 0x806F5758: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x806F575C: sh          $t1, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r9;
    // 0x806F5760: lwc1        $f4, 0x84($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X84);
    // 0x806F5764: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x806F5768: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806F576C: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x806F5770: lwc1        $f6, 0x88($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X88);
    // 0x806F5774: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806F5778: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x806F577C: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x806F5780: lwc1        $f8, 0x8C($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X8C);
    // 0x806F5784: lw          $t2, -0x76F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X76F8);
    // 0x806F5788: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806F578C: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x806F5790: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x806F5794: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x806F5798: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x806F579C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x806F57A0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x806F57A4: lw          $t9, 0x54($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X54);
    // 0x806F57A8: jalr        $t9
    // 0x806F57AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x806F57AC: nop

    after_5:
    // 0x806F57B0: jal         0x80067E68
    // 0x806F57B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_6;
    // 0x806F57B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x806F57B8: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F57BC: jal         0x80067818
    // 0x806F57C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x806F57C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x806F57C4: b           L_806F5914
    // 0x806F57C8: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
        goto L_806F5914;
    // 0x806F57C8: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
L_806F57CC:
    // 0x806F57CC: lw          $a1, 0x3C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X3C);
    // 0x806F57D0: lw          $a2, 0x40($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X40);
    // 0x806F57D4: jal         0x8004613C
    // 0x806F57D8: lw          $a3, 0x44($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X44);
    func_8004613C(rdram, ctx);
        goto after_8;
    // 0x806F57D8: lw          $a3, 0x44($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X44);
    after_8:
    // 0x806F57DC: beq         $v0, $zero, L_806F5808
    if (ctx->r2 == 0) {
        // 0x806F57E0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806F5808;
    }
    // 0x806F57E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806F57E4: jal         0x80047090
    // 0x806F57E8: addiu       $a0, $zero, 0x403A
    ctx->r4 = ADD32(0, 0X403A);
    func_80047090(rdram, ctx);
        goto after_9;
    // 0x806F57E8: addiu       $a0, $zero, 0x403A
    ctx->r4 = ADD32(0, 0X403A);
    after_9:
    // 0x806F57EC: lhu         $t7, 0xE($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XE);
    // 0x806F57F0: andi        $t4, $v0, 0x3FF
    ctx->r12 = ctx->r2 & 0X3FF;
    // 0x806F57F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F57F8: andi        $t6, $t7, 0xFC00
    ctx->r14 = ctx->r15 & 0XFC00;
    // 0x806F57FC: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x806F5800: jal         0x80044194
    // 0x806F5804: sh          $t8, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r24;
    func_80044194(rdram, ctx);
        goto after_10;
    // 0x806F5804: sh          $t8, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r24;
    after_10:
L_806F5808:
    // 0x806F5808: jal         0x80067E68
    // 0x806F580C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_80067E68(rdram, ctx);
        goto after_11;
    // 0x806F580C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_11:
    // 0x806F5810: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F5814: jal         0x80067818
    // 0x806F5818: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_12;
    // 0x806F5818: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x806F581C: b           L_806F5914
    // 0x806F5820: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
        goto L_806F5914;
    // 0x806F5820: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
L_806F5824:
    // 0x806F5824: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x806F5828: lw          $a1, 0x3C($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X3C);
    // 0x806F582C: lw          $a2, 0x40($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X40);
    // 0x806F5830: jal         0x8004613C
    // 0x806F5834: lw          $a3, 0x44($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X44);
    func_8004613C(rdram, ctx);
        goto after_13;
    // 0x806F5834: lw          $a3, 0x44($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X44);
    after_13:
    // 0x806F5838: beq         $v0, $zero, L_806F5864
    if (ctx->r2 == 0) {
        // 0x806F583C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806F5864;
    }
    // 0x806F583C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806F5840: jal         0x80047090
    // 0x806F5844: addiu       $a0, $zero, 0x45E6
    ctx->r4 = ADD32(0, 0X45E6);
    func_80047090(rdram, ctx);
        goto after_14;
    // 0x806F5844: addiu       $a0, $zero, 0x45E6
    ctx->r4 = ADD32(0, 0X45E6);
    after_14:
    // 0x806F5848: lhu         $t2, 0xE($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XE);
    // 0x806F584C: andi        $t0, $v0, 0x3FF
    ctx->r8 = ctx->r2 & 0X3FF;
    // 0x806F5850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F5854: andi        $t3, $t2, 0xFC00
    ctx->r11 = ctx->r10 & 0XFC00;
    // 0x806F5858: or          $t9, $t0, $t3
    ctx->r25 = ctx->r8 | ctx->r11;
    // 0x806F585C: jal         0x80044194
    // 0x806F5860: sh          $t9, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r25;
    func_80044194(rdram, ctx);
        goto after_15;
    // 0x806F5860: sh          $t9, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r25;
    after_15:
L_806F5864:
    // 0x806F5864: jal         0x80067E68
    // 0x806F5868: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_80067E68(rdram, ctx);
        goto after_16;
    // 0x806F5868: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_16:
    // 0x806F586C: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F5870: jal         0x80067818
    // 0x806F5874: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_17;
    // 0x806F5874: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x806F5878: b           L_806F5914
    // 0x806F587C: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
        goto L_806F5914;
    // 0x806F587C: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
L_806F5880:
    // 0x806F5880: lw          $t9, -0x72C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72C8);
    // 0x806F5884: addiu       $a0, $s4, 0x84
    ctx->r4 = ADD32(ctx->r20, 0X84);
    // 0x806F5888: jalr        $t9
    // 0x806F588C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_18;
    // 0x806F588C: nop

    after_18:
    // 0x806F5890: jal         0x80067E68
    // 0x806F5894: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80067E68(rdram, ctx);
        goto after_19;
    // 0x806F5894: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x806F5898: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F589C: jal         0x80067818
    // 0x806F58A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_20;
    // 0x806F58A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_20:
    // 0x806F58A4: b           L_806F5914
    // 0x806F58A8: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
        goto L_806F5914;
    // 0x806F58A8: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
L_806F58AC:
    // 0x806F58AC: lw          $t9, -0x72A4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72A4);
    // 0x806F58B0: addiu       $a0, $s4, 0x84
    ctx->r4 = ADD32(ctx->r20, 0X84);
    // 0x806F58B4: jalr        $t9
    // 0x806F58B8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_21;
    // 0x806F58B8: nop

    after_21:
    // 0x806F58BC: jal         0x80067E68
    // 0x806F58C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80067E68(rdram, ctx);
        goto after_22;
    // 0x806F58C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x806F58C4: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F58C8: jal         0x80067818
    // 0x806F58CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_23;
    // 0x806F58CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_23:
    // 0x806F58D0: b           L_806F5914
    // 0x806F58D4: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
        goto L_806F5914;
    // 0x806F58D4: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
L_806F58D8:
    // 0x806F58D8: jal         0x80058A14
    // 0x806F58DC: nop

    func_80058A14(rdram, ctx);
        goto after_24;
    // 0x806F58DC: nop

    after_24:
    // 0x806F58E0: beq         $v0, $zero, L_806F5910
    if (ctx->r2 == 0) {
        // 0x806F58E4: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_806F5910;
    }
    // 0x806F58E4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x806F58E8: lw          $t9, -0x72BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72BC);
    // 0x806F58EC: lwc1        $f12, 0x84($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X84);
    // 0x806F58F0: lwc1        $f14, 0x88($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0X88);
    // 0x806F58F4: jalr        $t9
    // 0x806F58F8: lw          $a2, 0x8C($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X8C);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_25;
    // 0x806F58F8: lw          $a2, 0x8C($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X8C);
    after_25:
    // 0x806F58FC: jal         0x80067E68
    // 0x806F5900: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80067E68(rdram, ctx);
        goto after_26;
    // 0x806F5900: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_26:
    // 0x806F5904: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F5908: jal         0x80067818
    // 0x806F590C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_27;
    // 0x806F590C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_27:
L_806F5910:
    // 0x806F5910: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
L_806F5914:
    // 0x806F5914: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F5918: sb          $t5, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r13;
    // 0x806F591C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x806F5920: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F5924: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x806F5928: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x806F592C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F5930: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x806F5934: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F5938: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806F593C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806F5940: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x806F5944: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x806F5948: sb          $t4, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r12;
    // 0x806F594C: jr          $ra
    // 0x806F5950: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x806F5950: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8044BB3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BB3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BB40: jr          $ra
    // 0x8044BB44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BB44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_8064C180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C188: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064C18C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064C190: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C194: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064C198: nop

    // 0x8064C19C: bc1fl       L_8064C1F4
    if (!c1cs) {
        // 0x8064C1A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C1F4;
    }
    goto skip_0;
    // 0x8064C1A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C1A4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064C1A8: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C1AC: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x8064C1B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064C1B4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064C1B8: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(495, 0X3650) << 16);
    // 0x8064C1BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C1C0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064C1C4: nop

    // 0x8064C1C8: bc1fl       L_8064C1F4
    if (!c1cs) {
        // 0x8064C1CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C1F4;
    }
    goto skip_1;
    // 0x8064C1CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064C1D0: lwc1        $f4, -0x28E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(495, 0X3650));
    // 0x8064C1D4: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(495, 0X3654) << 16);
    // 0x8064C1D8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8064C1DC: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8064C1E0: lwc1        $f6, -0x28DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(495, 0X3654));
    // 0x8064C1E4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064C1E8: jal         0x8064C5D8
    // 0x8064C1EC: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    func_8064C5D8(rdram, ctx);
        goto after_0;
    // 0x8064C1EC: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x8064C1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C1F4:
    // 0x8064C1F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C1F8: jr          $ra
    // 0x8064C1FC: nop

    return;
    // 0x8064C1FC: nop

;}
RECOMP_FUNC void func_80048680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048680: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80048684: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    // 0x80048688: jr          $ra
    // 0x8004868C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8004868C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_805C74C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C74C8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x805C74CC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x805C74D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C74D4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C74D8: swc1        $f12, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f12.u32l;
    // 0x805C74DC: swc1        $f14, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f14.u32l;
    // 0x805C74E0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805C74E4: jr          $ra
    // 0x805C74E8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x805C74E8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_805A6120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A6124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A6128: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A612C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805A6130: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805A6134: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805A6138: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A613C: lwc1        $f0, 0x274($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X274);
    // 0x805A6140: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(417, 0X153C) << 16);
    // 0x805A6144: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x805A6148: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x805A614C: nop

    // 0x805A6150: bc1fl       L_805A6160
    if (!c1cs) {
        // 0x805A6154: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_805A6160;
    }
    goto skip_0;
    // 0x805A6154: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    skip_0:
    // 0x805A6158: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805A615C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
L_805A6160:
    // 0x805A6160: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805A6164: lwc1        $f6, 0x67FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(417, 0X153C));
    // 0x805A6168: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x805A616C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x805A6170: nop

    // 0x805A6174: bc1fl       L_805A6194
    if (!c1cs) {
        // 0x805A6178: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_805A6194;
    }
    goto skip_1;
    // 0x805A6178: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x805A617C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_805A6180:
    // 0x805A6180: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x805A6184: nop

    // 0x805A6188: bc1tl       L_805A6180
    if (c1cs) {
        // 0x805A618C: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_805A6180;
    }
    goto skip_2;
    // 0x805A618C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x805A6190: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_805A6194:
    // 0x805A6194: jal         0x805A6098
    // 0x805A6198: swc1        $f0, 0x274($v0)
    MEM_W(0X274, ctx->r2) = ctx->f0.u32l;
    func_805A6098(rdram, ctx);
        goto after_0;
    // 0x805A6198: swc1        $f0, 0x274($v0)
    MEM_W(0X274, ctx->r2) = ctx->f0.u32l;
    after_0:
    // 0x805A619C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A61A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A61A4: jr          $ra
    // 0x805A61A8: nop

    return;
    // 0x805A61A8: nop

;}
RECOMP_FUNC void func_8004C9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C9F4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004C9F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004C9FC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8004CA00: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8004CA04: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8004CA08: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8004CA0C: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8004CA10: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x8004CA14: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8004CA18: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8004CA1C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8004CA20: addiu       $t1, $sp, 0x46
    ctx->r9 = ADD32(ctx->r29, 0X46);
    // 0x8004CA24: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8004CA28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004CA2C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8004CA30: addu        $t0, $t9, $t3
    ctx->r8 = ADD32(ctx->r25, ctx->r11);
    // 0x8004CA34: lhu         $t4, 0x0($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X0);
    // 0x8004CA38: sh          $t4, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r12;
    // 0x8004CA3C: lbu         $t8, 0x1($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1);
    // 0x8004CA40: lbu         $t5, 0x0($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X0);
    // 0x8004CA44: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x8004CA48: xori        $t3, $t9, 0x4
    ctx->r11 = ctx->r25 ^ 0X4;
    // 0x8004CA4C: sltu        $t3, $zero, $t3
    ctx->r11 = 0 < ctx->r11 ? 1 : 0;
    // 0x8004CA50: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8004CA54: and         $t4, $t6, $t3
    ctx->r12 = ctx->r14 & ctx->r11;
    // 0x8004CA58: beql        $t4, $zero, L_8004CC14
    if (ctx->r12 == 0) {
        // 0x8004CA5C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004CC14;
    }
    goto skip_0;
    // 0x8004CA5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8004CA60: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    // 0x8004CA64: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x8004CA68: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8004CA6C: jal         0x80049864
    // 0x8004CA70: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    func_80049864(rdram, ctx);
        goto after_0;
    // 0x8004CA70: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004CA74: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8004CA78: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8004CA7C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8004CA80: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8004CA84: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8004CA88: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8004CA8C: lw          $t6, 0x34($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X34);
    // 0x8004CA90: addiu       $t1, $sp, 0x46
    ctx->r9 = ADD32(ctx->r29, 0X46);
    // 0x8004CA94: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x8004CA98: addu        $t4, $t6, $t3
    ctx->r12 = ADD32(ctx->r14, ctx->r11);
    // 0x8004CA9C: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8004CAA0: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8004CAA4: srl         $t8, $v0, 6
    ctx->r24 = S32(U32(ctx->r2) >> 6);
    // 0x8004CAA8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004CAAC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8004CAB0: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8004CAB4: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8004CAB8: trunc.w.s   $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8004CABC: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8004CAC0: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x8004CAC4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004CAC8: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8004CACC: lw          $t7, 0xA24($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XA24);
    // 0x8004CAD0: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8004CAD4: andi        $t2, $t2, 0xF
    ctx->r10 = ctx->r10 & 0XF;
    // 0x8004CAD8: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8004CADC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8004CAE0: addu        $t5, $t7, $t2
    ctx->r13 = ADD32(ctx->r15, ctx->r10);
    // 0x8004CAE4: lhu         $v1, 0x0($t5)
    ctx->r3 = MEM_HU(ctx->r13, 0X0);
    // 0x8004CAE8: andi        $t9, $t6, 0xF
    ctx->r25 = ctx->r14 & 0XF;
    // 0x8004CAEC: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8004CAF0: sllv        $t3, $v1, $t9
    ctx->r11 = S32(ctx->r3 << (ctx->r25 & 31));
    // 0x8004CAF4: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x8004CAF8: beq         $t4, $zero, L_8004CC10
    if (ctx->r12 == 0) {
        // 0x8004CAFC: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_8004CC10;
    }
    // 0x8004CAFC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8004CB00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004CB04: sb          $t7, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r15;
    // 0x8004CB08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004CB0C: lwc1        $f16, 0x8D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X8D0);
    // 0x8004CB10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004CB14: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8004CB18: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8004CB1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004CB20: addiu       $t5, $t0, 0xC
    ctx->r13 = ADD32(ctx->r8, 0XC);
    // 0x8004CB24: bc1tl       L_8004CB54
    if (c1cs) {
        // 0x8004CB28: sub.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_8004CB54;
    }
    goto skip_1;
    // 0x8004CB28: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    skip_1:
    // 0x8004CB2C: lwc1        $f18, 0x8D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X8D4);
    // 0x8004CB30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004CB34: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8004CB38: nop

    // 0x8004CB3C: bc1tl       L_8004CB54
    if (c1cs) {
        // 0x8004CB40: sub.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_8004CB54;
    }
    goto skip_2;
    // 0x8004CB40: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    skip_2:
    // 0x8004CB44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004CB48: b           L_8004CC1C
    // 0x8004CB4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004CC1C;
    // 0x8004CB4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004CB50: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
L_8004CB54:
    // 0x8004CB54: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8004CB58: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8004CB5C: jal         0x800534C0
    // 0x8004CB60: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    func_800534C0(rdram, ctx);
        goto after_1;
    // 0x8004CB60: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8004CB64: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8004CB68: addiu       $t1, $sp, 0x46
    ctx->r9 = ADD32(ctx->r29, 0X46);
    // 0x8004CB6C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8004CB70: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004CB74: beq         $t8, $zero, L_8004CC10
    if (ctx->r24 == 0) {
        // 0x8004CB78: sh          $v0, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r2;
            goto L_8004CC10;
    }
    // 0x8004CB78: sh          $v0, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r2;
    // 0x8004CB7C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004CB80: beql        $t8, $at, L_8004CC14
    if (ctx->r24 == ctx->r1) {
        // 0x8004CB84: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004CC14;
    }
    goto skip_3;
    // 0x8004CB84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x8004CB88: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x8004CB8C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004CB90: andi        $v0, $v1, 0xF8
    ctx->r2 = ctx->r3 & 0XF8;
    // 0x8004CB94: beq         $v0, $at, L_8004CC10
    if (ctx->r2 == ctx->r1) {
        // 0x8004CB98: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004CC10;
    }
    // 0x8004CB98: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004CB9C: beql        $v0, $at, L_8004CC14
    if (ctx->r2 == ctx->r1) {
        // 0x8004CBA0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004CC14;
    }
    goto skip_4;
    // 0x8004CBA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_4:
    // 0x8004CBA4: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x8004CBA8: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8004CBAC: andi        $a0, $v0, 0x3F
    ctx->r4 = ctx->r2 & 0X3F;
    // 0x8004CBB0: xori        $t9, $a0, 0x4
    ctx->r25 = ctx->r4 ^ 0X4;
    // 0x8004CBB4: sltu        $t9, $zero, $t9
    ctx->r25 = 0 < ctx->r25 ? 1 : 0;
    // 0x8004CBB8: and         $t3, $t6, $t9
    ctx->r11 = ctx->r14 & ctx->r25;
    // 0x8004CBBC: beq         $t3, $zero, L_8004CC10
    if (ctx->r11 == 0) {
        // 0x8004CBC0: srl         $t4, $v0, 6
        ctx->r12 = S32(U32(ctx->r2) >> 6);
            goto L_8004CC10;
    }
    // 0x8004CBC0: srl         $t4, $v0, 6
    ctx->r12 = S32(U32(ctx->r2) >> 6);
    // 0x8004CBC4: sll         $t7, $t4, 8
    ctx->r15 = S32(ctx->r12 << 8);
    // 0x8004CBC8: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8004CBCC: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x8004CBD0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8004CBD4: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8004CBD8: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8004CBDC: lw          $t6, 0xA24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XA24);
    // 0x8004CBE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004CBE4: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8004CBE8: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x8004CBEC: lhu         $v1, 0x0($t9)
    ctx->r3 = MEM_HU(ctx->r25, 0X0);
    // 0x8004CBF0: andi        $t7, $t4, 0xF
    ctx->r15 = ctx->r12 & 0XF;
    // 0x8004CBF4: sllv        $t5, $v1, $t7
    ctx->r13 = S32(ctx->r3 << (ctx->r15 & 31));
    // 0x8004CBF8: andi        $t8, $t5, 0x8000
    ctx->r24 = ctx->r13 & 0X8000;
    // 0x8004CBFC: beql        $t8, $zero, L_8004CC14
    if (ctx->r24 == 0) {
        // 0x8004CC00: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004CC14;
    }
    goto skip_5;
    // 0x8004CC00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_5:
    // 0x8004CC04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004CC08: b           L_8004CC1C
    // 0x8004CC0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004CC1C;
    // 0x8004CC0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004CC10:
    // 0x8004CC10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8004CC14:
    // 0x8004CC14: nop

    // 0x8004CC18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004CC1C:
    // 0x8004CC1C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8004CC20: jr          $ra
    // 0x8004CC24: nop

    return;
    // 0x8004CC24: nop

;}
RECOMP_FUNC void func_805A4028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A4028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A402C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A4030: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x805A4034: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x805A4038: beql        $v1, $zero, L_805A405C
    if (ctx->r3 == 0) {
        // 0x805A403C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A405C;
    }
    goto skip_0;
    // 0x805A403C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A4040: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x805A4044: jal         0x80064E84
    // 0x805A4048: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x805A4048: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x805A404C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x805A4050: jal         0x80064E84
    // 0x805A4054: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x805A4054: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    after_1:
    // 0x805A4058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A405C:
    // 0x805A405C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A4060: jr          $ra
    // 0x805A4064: nop

    return;
    // 0x805A4064: nop

;}
RECOMP_FUNC void func_8057F1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F1E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057F1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F1F0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057F1F4: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x8057F1F8: jal         0x800447C8
    // 0x8057F1FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x8057F1FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8057F200: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8057F204: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x8057F208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F20C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057F210: jr          $ra
    // 0x8057F214: nop

    return;
    // 0x8057F214: nop

;}
RECOMP_FUNC void func_805A3F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3F90: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x805A3F94: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x805A3F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A3F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A3FA0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805A3FA4: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805A3FA8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805A3FAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A3FB0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805A3FB4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805A3FB8: jal         0x805A3F88
    // 0x805A3FBC: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    func_805A3F88(rdram, ctx);
        goto after_0;
    // 0x805A3FBC: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    after_0:
    // 0x805A3FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A3FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A3FC8: jr          $ra
    // 0x805A3FCC: nop

    return;
    // 0x805A3FCC: nop

;}
RECOMP_FUNC void func_8075FB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075FB90: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8075FB94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8075FB98: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8075FB9C: beql        $v1, $zero, L_8075FBB8
    if (ctx->r3 == 0) {
        // 0x8075FBA0: lw          $v1, 0x10($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X10);
            goto L_8075FBB8;
    }
    goto skip_0;
    // 0x8075FBA0: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x8075FBA4: beq         $v1, $at, L_8075FC3C
    if (ctx->r3 == ctx->r1) {
        // 0x8075FBA8: nop
    
            goto L_8075FC3C;
    }
    // 0x8075FBA8: nop

    // 0x8075FBAC: jr          $ra
    // 0x8075FBB0: nop

    return;
    // 0x8075FBB0: nop

    // 0x8075FBB4: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
L_8075FBB8:
    // 0x8075FBB8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8075FBBC: lui         $t2, 0x8076
    ctx->r10 = S32(RELOC_HI16(760, 0X410) << 16);
    // 0x8075FBC0: beq         $v1, $zero, L_8075FBD0
    if (ctx->r3 == 0) {
        // 0x8075FBC4: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8075FBD0;
    }
    // 0x8075FBC4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8075FBC8: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x8075FBCC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8075FBD0:
    // 0x8075FBD0: bne         $v1, $zero, L_8075FC3C
    if (ctx->r3 != 0) {
        // 0x8075FBD4: nop
    
            goto L_8075FC3C;
    }
    // 0x8075FBD4: nop

    // 0x8075FBD8: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x8075FBDC: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8075FBE0: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x8075FBE4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x8075FBE8: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8075FBEC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8075FBF0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8075FBF4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8075FBF8: lw          $t2, -0x70($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(760, 0X410));
    // 0x8075FBFC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8075FC00: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x8075FC04: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8075FC08: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8075FC0C: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x8075FC10: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8075FC14: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x8075FC18: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x8075FC1C: bnel        $at, $zero, L_8075FC30
    if (ctx->r1 != 0) {
        // 0x8075FC20: slti        $at, $a1, 0xE
        ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
            goto L_8075FC30;
    }
    goto skip_1;
    // 0x8075FC20: slti        $at, $a1, 0xE
    ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    skip_1:
    // 0x8075FC24: sw          $t5, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r13;
    // 0x8075FC28: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    // 0x8075FC2C: slti        $at, $a1, 0xE
    ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
L_8075FC30:
    // 0x8075FC30: bne         $at, $zero, L_8075FC3C
    if (ctx->r1 != 0) {
        // 0x8075FC34: nop
    
            goto L_8075FC3C;
    }
    // 0x8075FC34: nop

    // 0x8075FC38: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
L_8075FC3C:
    // 0x8075FC3C: jr          $ra
    // 0x8075FC40: nop

    return;
    // 0x8075FC40: nop

;}
RECOMP_FUNC void func_80067A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067A54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067A58: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80067A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067A60: jal         0x80018C98
    // 0x80067A64: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_80018C98(rdram, ctx);
        goto after_0;
    // 0x80067A64: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x80067A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067A70: jr          $ra
    // 0x80067A74: nop

    return;
    // 0x80067A74: nop

;}
RECOMP_FUNC void func_80450568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450568: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8045056C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450570: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450574: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80450578: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8045057C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80450580: lw          $a1, 0x6A94($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6A94);
    // 0x80450584: jal         0x8044BFA8
    // 0x80450588: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8044BFA8(rdram, ctx);
        goto after_0;
    // 0x80450588: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8045058C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80450590: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80450594: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80450598: jal         0x8006C56C
    // 0x8045059C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_8006C56C(rdram, ctx);
        goto after_1;
    // 0x8045059C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x804505A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804505A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x804505A8: jr          $ra
    // 0x804505AC: nop

    return;
    // 0x804505AC: nop

;}
RECOMP_FUNC void func_8002F574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F574: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F57C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002F584: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x8002F588: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002F58C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8002F590: jal         0x8002B9E4
    // 0x8002F594: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002F594: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002F598: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002F59C: jal         0x8002F4B0
    // 0x8002F5A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002F4B0(rdram, ctx);
        goto after_1;
    // 0x8002F5A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002F5A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F5A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F5AC: jr          $ra
    // 0x8002F5B0: nop

    return;
    // 0x8002F5B0: nop

;}
RECOMP_FUNC void func_80026F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026F0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80026F10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026F14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80026F18: jal         0x80024748
    // 0x80026F1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x80026F1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80026F20: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80026F24: lw          $t6, 0x154($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X154);
    // 0x80026F28: bnel        $t6, $zero, L_80026F6C
    if (ctx->r14 != 0) {
        // 0x80026F2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80026F6C;
    }
    goto skip_0;
    // 0x80026F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80026F30: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x80026F34: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80026F38: bnel        $t7, $at, L_80026F6C
    if (ctx->r15 != ctx->r1) {
        // 0x80026F3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80026F6C;
    }
    goto skip_1;
    // 0x80026F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80026F40: jal         0x8001D770
    // 0x80026F44: nop

    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80026F44: nop

    after_1:
    // 0x80026F48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80026F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80026F50: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80026F54: jal         0x80067CE4
    // 0x80026F58: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067CE4(rdram, ctx);
        goto after_2;
    // 0x80026F58: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80026F5C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80026F60: jal         0x80067818
    // 0x80026F64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80026F64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80026F68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80026F6C:
    // 0x80026F6C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80026F70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80026F74: jr          $ra
    // 0x80026F78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80026F78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80001088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001088: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000108C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80001090: lui         $at, 0x1200
    ctx->r1 = S32(0X1200 << 16);
    // 0x80001094: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80001098: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x8000109C: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x800010A0: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800010A4: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x800010A8: sll         $t2, $a3, 16
    ctx->r10 = S32(ctx->r7 << 16);
    // 0x800010AC: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800010B0: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800010B4: jr          $ra
    // 0x800010B8: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    return;
    // 0x800010B8: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void func_806E5CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E5CE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E5CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E5CF0: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x806E5CF4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E5CF8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806E5CFC: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806E5D00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806E5D04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806E5D08: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x806E5D0C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x806E5D10: jal         0x8004D150
    // 0x806E5D14: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8004D150(rdram, ctx);
        goto after_0;
    // 0x806E5D14: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x806E5D18: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806E5D1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806E5D20: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x806E5D24: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x806E5D28: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806E5D2C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806E5D30: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x806E5D34: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x806E5D38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E5D3C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x806E5D40: lbu         $t1, 0x14($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X14);
    // 0x806E5D44: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x806E5D48: beql        $t1, $zero, L_806E5D9C
    if (ctx->r9 == 0) {
        // 0x806E5D4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E5D9C;
    }
    goto skip_0;
    // 0x806E5D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E5D50: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x806E5D54: jal         0x8004D618
    // 0x806E5D58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D618(rdram, ctx);
        goto after_1;
    // 0x806E5D58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x806E5D5C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x806E5D60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E5D64: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806E5D68: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806E5D6C: sw          $t2, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r10;
    // 0x806E5D70: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806E5D74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806E5D78: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806E5D7C: swc1        $f4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f4.u32l;
    // 0x806E5D80: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x806E5D84: ori         $t4, $t3, 0xF00
    ctx->r12 = ctx->r11 | 0XF00;
    // 0x806E5D88: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x806E5D8C: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x806E5D90: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806E5D94: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x806E5D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E5D9C:
    // 0x806E5D9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E5DA0: jr          $ra
    // 0x806E5DA4: nop

    return;
    // 0x806E5DA4: nop

;}
RECOMP_FUNC void func_8005BA80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BA80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005BA84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BA88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005BA8C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005BA90: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005BA94: jal         0x8005BA30
    // 0x8005BA98: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8005BA30(rdram, ctx);
        goto after_0;
    // 0x8005BA98: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8005BA9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BAA0: beq         $v0, $at, L_8005BB18
    if (ctx->r2 == ctx->r1) {
        // 0x8005BAA4: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8005BB18;
    }
    // 0x8005BAA4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8005BAA8: lhu         $a2, 0x2E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2E);
    // 0x8005BAAC: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x8005BAB0: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8005BAB4: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x8005BAB8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8005BABC: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
    // 0x8005BAC0: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8005BAC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8005BAC8: jal         0x80064D1C
    // 0x8005BACC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x8005BACC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8005BAD0: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8005BAD4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8005BAD8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8005BADC: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8005BAE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005BAE4: jal         0x800675D0
    // 0x8005BAE8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x8005BAE8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8005BAEC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005BAF0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005BAF4: lhu         $t9, 0x2E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2E);
    // 0x8005BAF8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005BAFC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005BB00: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005BB04: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8005BB08: addiu       $t8, $t8, -0x4BB0
    ctx->r24 = ADD32(ctx->r24, -0X4BB0);
    // 0x8005BB0C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8005BB10: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005BB14: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
L_8005BB18:
    // 0x8005BB18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BB1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005BB20: jr          $ra
    // 0x8005BB24: nop

    return;
    // 0x8005BB24: nop

;}
RECOMP_FUNC void func_807BA848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BA84C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BA850: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BA854: jal         0x800577D8
    // 0x807BA858: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x807BA858: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x807BA85C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BA860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BA864: jr          $ra
    // 0x807BA868: nop

    return;
    // 0x807BA868: nop

;}
RECOMP_FUNC void func_8051B630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051B630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051B634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051B638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8051B63C: jal         0x80045A34
    // 0x8051B640: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8051B640: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8051B644: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051B648: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8051B64C: bne         $v0, $zero, L_8051B664
    if (ctx->r2 != 0) {
        // 0x8051B650: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8051B664;
    }
    // 0x8051B650: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8051B654: jal         0x800445A4
    // 0x8051B658: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8051B658: nop

    after_1:
    // 0x8051B65C: b           L_8051B678
    // 0x8051B660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8051B678;
    // 0x8051B660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8051B664:
    // 0x8051B664: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8051B668: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8051B66C: jal         0x80065728
    // 0x8051B670: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8051B670: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8051B674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8051B678:
    // 0x8051B678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051B67C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051B680: jr          $ra
    // 0x8051B684: nop

    return;
    // 0x8051B684: nop

;}
RECOMP_FUNC void func_80010558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010558: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001055C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010560: jal         0x80018FF8
    // 0x80010564: nop

    func_80018FF8(rdram, ctx);
        goto after_0;
    // 0x80010564: nop

    after_0:
    // 0x80010568: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001056C: lh          $v0, -0x6D98($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6D98);
    // 0x80010570: bltz        $v0, L_8001059C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80010574: nop
    
            goto L_8001059C;
    }
    // 0x80010574: nop

    // 0x80010578: bnel        $v0, $zero, L_80010594
    if (ctx->r2 != 0) {
        // 0x8001057C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80010594;
    }
    goto skip_0;
    // 0x8001057C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    skip_0:
    // 0x80010580: jal         0x80011C64
    // 0x80010584: nop

    func_80011C64(rdram, ctx);
        goto after_1;
    // 0x80010584: nop

    after_1:
    // 0x80010588: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001058C: lh          $v0, -0x6D98($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6D98);
    // 0x80010590: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
L_80010594:
    // 0x80010594: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010598: sh          $t6, -0x6D98($at)
    MEM_H(-0X6D98, ctx->r1) = ctx->r14;
L_8001059C:
    // 0x8001059C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800105A0: lh          $v0, -0x6D94($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X6D94);
    // 0x800105A4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800105A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800105AC: beq         $v0, $at, L_80010600
    if (ctx->r2 == ctx->r1) {
        // 0x800105B0: addiu       $a0, $zero, 0x76
        ctx->r4 = ADD32(0, 0X76);
            goto L_80010600;
    }
    // 0x800105B0: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    // 0x800105B4: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x800105B8: jal         0x80011928
    // 0x800105BC: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    func_80011928(rdram, ctx);
        goto after_2;
    // 0x800105BC: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    after_2:
    // 0x800105C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800105C4: beq         $v0, $at, L_800105E4
    if (ctx->r2 == ctx->r1) {
        // 0x800105C8: addiu       $a0, $zero, 0x76
        ctx->r4 = ADD32(0, 0X76);
            goto L_800105E4;
    }
    // 0x800105C8: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    // 0x800105CC: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    // 0x800105D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800105D4: jal         0x80015E74
    // 0x800105D8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_80015E74(rdram, ctx);
        goto after_3;
    // 0x800105D8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x800105DC: b           L_800105F4
    // 0x800105E0: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
        goto L_800105F4;
    // 0x800105E0: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
L_800105E4:
    // 0x800105E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800105E8: jal         0x8001759C
    // 0x800105EC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8001759C(rdram, ctx);
        goto after_4;
    // 0x800105EC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x800105F0: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
L_800105F4:
    // 0x800105F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800105F8: b           L_80010630
    // 0x800105FC: sh          $t7, -0x6D94($at)
    MEM_H(-0X6D94, ctx->r1) = ctx->r15;
        goto L_80010630;
    // 0x800105FC: sh          $t7, -0x6D94($at)
    MEM_H(-0X6D94, ctx->r1) = ctx->r15;
L_80010600:
    // 0x80010600: jal         0x80011928
    // 0x80010604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011928(rdram, ctx);
        goto after_5;
    // 0x80010604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80010608: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001060C: bne         $v0, $at, L_80010630
    if (ctx->r2 != ctx->r1) {
        // 0x80010610: lui         $t8, 0x800A
        ctx->r24 = S32(0X800A << 16);
            goto L_80010630;
    }
    // 0x80010610: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80010614: lh          $t8, -0x6D94($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X6D94);
    // 0x80010618: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001061C: lw          $a0, -0x4860($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4860);
    // 0x80010620: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80010624: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x80010628: jal         0x8001BC68
    // 0x8001062C: sh          $t8, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r24;
    func_8001BC68(rdram, ctx);
        goto after_6;
    // 0x8001062C: sh          $t8, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r24;
    after_6:
L_80010630:
    // 0x80010630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010634: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80010638: jr          $ra
    // 0x8001063C: nop

    return;
    // 0x8001063C: nop

;}
RECOMP_FUNC void func_80737BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737BEC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80737BF0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3BA0) << 16);
    // 0x80737BF4: lwc1        $f4, -0x6A00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3BA0));
    // 0x80737BF8: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80737BFC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80737C00: nop

    // 0x80737C04: bc1fl       L_80737C44
    if (!c1cs) {
        // 0x80737C08: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80737C44;
    }
    goto skip_0;
    // 0x80737C08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80737C0C: lwc1        $f2, 0x3C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80737C10: lwc1        $f12, 0x38($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80737C14: lui         $at, 0x46C8
    ctx->r1 = S32(0X46C8 << 16);
    // 0x80737C18: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80737C1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80737C20: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80737C24: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80737C28: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80737C2C: nop

    // 0x80737C30: bc1fl       L_80737C44
    if (!c1cs) {
        // 0x80737C34: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80737C44;
    }
    goto skip_1;
    // 0x80737C34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80737C38: jr          $ra
    // 0x80737C3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80737C3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80737C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80737C44:
    // 0x80737C44: jr          $ra
    // 0x80737C48: nop

    return;
    // 0x80737C48: nop

;}
RECOMP_FUNC void func_8064BB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BB24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BB28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BB2C: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064BB30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064BB34: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064BB38: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064BB3C: nop

    // 0x8064BB40: bc1fl       L_8064BB90
    if (!c1cs) {
        // 0x8064BB44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064BB90;
    }
    goto skip_0;
    // 0x8064BB44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064BB48: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064BB4C: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064BB50: lui         $at, 0x429C
    ctx->r1 = S32(0X429C << 16);
    // 0x8064BB54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064BB58: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064BB5C: lui         $at, 0x8065
    ctx->r1 = S32(RELOC_HI16(495, 0X364C) << 16);
    // 0x8064BB60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064BB64: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064BB68: nop

    // 0x8064BB6C: bc1fl       L_8064BB90
    if (!c1cs) {
        // 0x8064BB70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064BB90;
    }
    goto skip_1;
    // 0x8064BB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064BB74: lwc1        $f0, -0x28E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(495, 0X364C));
    // 0x8064BB78: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8064BB7C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064BB80: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8064BB84: jal         0x8064BF74
    // 0x8064BB88: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    func_8064BF74(rdram, ctx);
        goto after_0;
    // 0x8064BB88: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x8064BB8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064BB90:
    // 0x8064BB90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BB94: jr          $ra
    // 0x8064BB98: nop

    return;
    // 0x8064BB98: nop

;}
RECOMP_FUNC void func_8079EC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079EC7C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8079EC80: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8079EC84: lbu         $t6, 0xF5C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF5C);
    // 0x8079EC88: lbu         $t8, 0xF5D($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF5D);
    // 0x8079EC8C: lw          $v0, 0xCF0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XCF0);
    // 0x8079EC90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079EC94: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8079EC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079EC9C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8079ECA0: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079ECA4: bne         $a1, $t9, L_8079ED68
    if (ctx->r5 != ctx->r25) {
        // 0x8079ECA8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8079ED68;
    }
    // 0x8079ECA8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8079ECAC: bltz        $v0, L_8079EDA8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8079ECB0: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_8079EDA8;
    }
    // 0x8079ECB0: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8079ECB4: beql        $at, $zero, L_8079EDAC
    if (ctx->r1 == 0) {
        // 0x8079ECB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079EDAC;
    }
    goto skip_0;
    // 0x8079ECB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8079ECBC: lw          $t0, 0x114($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X114);
    // 0x8079ECC0: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8079ECC4: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8079ECC8: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8079ECCC: bne         $at, $zero, L_8079ED14
    if (ctx->r1 != 0) {
        // 0x8079ECD0: addu        $v1, $a2, $t2
        ctx->r3 = ADD32(ctx->r6, ctx->r10);
            goto L_8079ED14;
    }
    // 0x8079ECD0: addu        $v1, $a2, $t2
    ctx->r3 = ADD32(ctx->r6, ctx->r10);
    // 0x8079ECD4: addu        $v1, $a2, $t1
    ctx->r3 = ADD32(ctx->r6, ctx->r9);
    // 0x8079ECD8: lw          $a0, 0x100($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X100);
    // 0x8079ECDC: beql        $a0, $zero, L_8079ECFC
    if (ctx->r4 == 0) {
        // 0x8079ECE0: lw          $a0, 0xEC($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XEC);
            goto L_8079ECFC;
    }
    goto skip_1;
    // 0x8079ECE0: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    skip_1:
    // 0x8079ECE4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8079ECE8: jal         0x8079EC38
    // 0x8079ECEC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8079EC38(rdram, ctx);
        goto after_0;
    // 0x8079ECEC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x8079ECF0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8079ECF4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8079ECF8: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
L_8079ECFC:
    // 0x8079ECFC: beql        $a0, $zero, L_8079ED50
    if (ctx->r4 == 0) {
        // 0x8079ED00: lw          $t3, 0x114($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X114);
            goto L_8079ED50;
    }
    goto skip_2;
    // 0x8079ED00: lw          $t3, 0x114($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X114);
    skip_2:
    // 0x8079ED04: jal         0x8079EC38
    // 0x8079ED08: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8079EC38(rdram, ctx);
        goto after_1;
    // 0x8079ED08: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x8079ED0C: b           L_8079ED4C
    // 0x8079ED10: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
        goto L_8079ED4C;
    // 0x8079ED10: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_8079ED14:
    // 0x8079ED14: lw          $a0, 0x100($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X100);
    // 0x8079ED18: beql        $a0, $zero, L_8079ED38
    if (ctx->r4 == 0) {
        // 0x8079ED1C: lw          $a0, 0xEC($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XEC);
            goto L_8079ED38;
    }
    goto skip_3;
    // 0x8079ED1C: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    skip_3:
    // 0x8079ED20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8079ED24: jal         0x8079EC5C
    // 0x8079ED28: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8079EC5C(rdram, ctx);
        goto after_2;
    // 0x8079ED28: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x8079ED2C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8079ED30: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8079ED34: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
L_8079ED38:
    // 0x8079ED38: beql        $a0, $zero, L_8079ED50
    if (ctx->r4 == 0) {
        // 0x8079ED3C: lw          $t3, 0x114($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X114);
            goto L_8079ED50;
    }
    goto skip_4;
    // 0x8079ED3C: lw          $t3, 0x114($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X114);
    skip_4:
    // 0x8079ED40: jal         0x8079EC5C
    // 0x8079ED44: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8079EC5C(rdram, ctx);
        goto after_3;
    // 0x8079ED44: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x8079ED48: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_8079ED4C:
    // 0x8079ED4C: lw          $t3, 0x114($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X114);
L_8079ED50:
    // 0x8079ED50: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8079ED54: slti        $at, $t4, 0x1F
    ctx->r1 = SIGNED(ctx->r12) < 0X1F ? 1 : 0;
    // 0x8079ED58: bne         $at, $zero, L_8079EDA8
    if (ctx->r1 != 0) {
        // 0x8079ED5C: sw          $t4, 0x114($a2)
        MEM_W(0X114, ctx->r6) = ctx->r12;
            goto L_8079EDA8;
    }
    // 0x8079ED5C: sw          $t4, 0x114($a2)
    MEM_W(0X114, ctx->r6) = ctx->r12;
    // 0x8079ED60: b           L_8079EDA8
    // 0x8079ED64: sw          $zero, 0x114($a2)
    MEM_W(0X114, ctx->r6) = 0;
        goto L_8079EDA8;
    // 0x8079ED64: sw          $zero, 0x114($a2)
    MEM_W(0X114, ctx->r6) = 0;
L_8079ED68:
    // 0x8079ED68: bltz        $v0, L_8079EDA8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8079ED6C: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_8079EDA8;
    }
    // 0x8079ED6C: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8079ED70: beq         $at, $zero, L_8079EDA8
    if (ctx->r1 == 0) {
        // 0x8079ED74: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8079EDA8;
    }
    // 0x8079ED74: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8079ED78: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x8079ED7C: lw          $a0, 0x100($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X100);
    // 0x8079ED80: beql        $a0, $zero, L_8079ED98
    if (ctx->r4 == 0) {
        // 0x8079ED84: lw          $a0, 0xEC($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XEC);
            goto L_8079ED98;
    }
    goto skip_5;
    // 0x8079ED84: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    skip_5:
    // 0x8079ED88: jal         0x8079EC5C
    // 0x8079ED8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8079EC5C(rdram, ctx);
        goto after_4;
    // 0x8079ED8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_4:
    // 0x8079ED90: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8079ED94: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
L_8079ED98:
    // 0x8079ED98: beql        $a0, $zero, L_8079EDAC
    if (ctx->r4 == 0) {
        // 0x8079ED9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079EDAC;
    }
    goto skip_6;
    // 0x8079ED9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8079EDA0: jal         0x8079EC5C
    // 0x8079EDA4: nop

    func_8079EC5C(rdram, ctx);
        goto after_5;
    // 0x8079EDA4: nop

    after_5:
L_8079EDA8:
    // 0x8079EDA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079EDAC:
    // 0x8079EDAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8079EDB0: jr          $ra
    // 0x8079EDB4: nop

    return;
    // 0x8079EDB4: nop

;}
RECOMP_FUNC void func_805AB3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB3F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AB3F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805AB3FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805AB400: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805AB404: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805AB408: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x805AB40C: jal         0x800443EC
    // 0x805AB410: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800443EC(rdram, ctx);
        goto after_0;
    // 0x805AB410: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x805AB414: beq         $v0, $zero, L_805AB4C4
    if (ctx->r2 == 0) {
        // 0x805AB418: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_805AB4C4;
    }
    // 0x805AB418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805AB41C: lwc1        $f4, 0x84($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X84);
    // 0x805AB420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805AB424: jal         0x8004921C
    // 0x805AB428: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x805AB428: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x805AB42C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x805AB430: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805AB434: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805AB438: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805AB43C: lwc1        $f18, 0x70($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X70);
    // 0x805AB440: lwc1        $f6, 0x88($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X88);
    // 0x805AB444: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XB18) << 16);
    // 0x805AB448: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x805AB44C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805AB450: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805AB454: nop

    // 0x805AB458: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x805AB45C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x805AB460: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x805AB464: lwc1        $f18, -0x45A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB18));
    // 0x805AB468: lwc1        $f10, 0x8C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8C);
    // 0x805AB46C: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XB20) << 16);
    // 0x805AB470: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x805AB474: nop

    // 0x805AB478: bc1f        L_805AB48C
    if (!c1cs) {
        // 0x805AB47C: nop
    
            goto L_805AB48C;
    }
    // 0x805AB47C: nop

    // 0x805AB480: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XB1C) << 16);
    // 0x805AB484: b           L_805AB490
    // 0x805AB488: lwc1        $f0, -0x45A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB1C));
        goto L_805AB490;
    // 0x805AB488: lwc1        $f0, -0x45A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB1C));
L_805AB48C:
    // 0x805AB48C: lwc1        $f0, -0x45A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB20));
L_805AB490:
    // 0x805AB490: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x805AB494: jal         0x80047AB8
    // 0x805AB498: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x805AB498: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    after_2:
    // 0x805AB49C: jal         0x80040C0C
    // 0x805AB4A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040C0C(rdram, ctx);
        goto after_3;
    // 0x805AB4A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805AB4A4: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x805AB4A8: addiu       $t6, $t6, 0x33B4
    ctx->r14 = ADD32(ctx->r14, 0X33B4);
    // 0x805AB4AC: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x805AB4B0: lw          $t7, 0x1F4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1F4);
    // 0x805AB4B4: addiu       $a0, $zero, 0x1FC
    ctx->r4 = ADD32(0, 0X1FC);
    // 0x805AB4B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805AB4BC: jal         0x80067818
    // 0x805AB4C0: sw          $zero, 0x264($t7)
    MEM_W(0X264, ctx->r15) = 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x805AB4C0: sw          $zero, 0x264($t7)
    MEM_W(0X264, ctx->r15) = 0;
    after_4:
L_805AB4C4:
    // 0x805AB4C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805AB4C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805AB4CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805AB4D0: jr          $ra
    // 0x805AB4D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805AB4D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_805366B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805366B4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805366B8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805366BC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805366C0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805366C4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805366C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805366CC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805366D0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805366D4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805366D8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805366DC: jr          $ra
    // 0x805366E0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805366E0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8066D868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066D868: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066D86C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066D870: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8066D874: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8066D878: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8066D87C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D880: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8066D884: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8066D888: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x8066D88C: bc1fl       L_8066D8CC
    if (!c1cs) {
        // 0x8066D890: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066D8CC;
    }
    goto skip_0;
    // 0x8066D890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066D894: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8066D898: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8066D89C: jal         0x8004D1F0
    // 0x8066D8A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x8066D8A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066D8A4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D8A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8066D8AC: addiu       $a2, $a2, -0x2B90
    ctx->r6 = ADD32(ctx->r6, -0X2B90);
    // 0x8066D8B0: jal         0x8004D698
    // 0x8066D8B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x8066D8B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8066D8B8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8066D8BC: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8066D8C0: ori         $t7, $t6, 0xF000
    ctx->r15 = ctx->r14 | 0XF000;
    // 0x8066D8C4: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8066D8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066D8CC:
    // 0x8066D8CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066D8D0: jr          $ra
    // 0x8066D8D4: nop

    return;
    // 0x8066D8D4: nop

;}
RECOMP_FUNC void func_8044903C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044903C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80449040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80449044: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80449048: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8044904C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80449050: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80449054: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X13380) << 16);
    // 0x80449058: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044905C: lw          $v1, 0x6CB8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CB8);
    // 0x80449060: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x80449064: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80449068: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8044906C: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80449070: lw          $t0, 0x7760($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X13380));
    // 0x80449074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80449078: beql        $t0, $zero, L_8044908C
    if (ctx->r8 == 0) {
        // 0x8044907C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8044908C;
    }
    goto skip_0;
    // 0x8044907C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80449080: jalr        $t0
    // 0x80449084: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x80449084: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80449088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8044908C:
    // 0x8044908C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80449090: jr          $ra
    // 0x80449094: nop

    return;
    // 0x80449094: nop

;}
RECOMP_FUNC void func_8006CC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CC8C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006CC90: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006CC94: lwc1        $f6, 0x1084($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1084);
    // 0x8006CC98: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006CC9C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8006CCA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006CCA4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006CCA8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006CCAC: jr          $ra
    // 0x8006CCB0: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x8006CCB0: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_804409F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804409F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804409FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80440A00: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80440A04: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80440A08: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80440A0C: jal         0x8043F33C
    // 0x80440A10: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8043F33C(rdram, ctx);
        goto after_0;
    // 0x80440A10: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80440A14: jal         0x8043FBDC
    // 0x80440A18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8043FBDC(rdram, ctx);
        goto after_1;
    // 0x80440A18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80440A1C: jal         0x8043F150
    // 0x80440A20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8043F150(rdram, ctx);
        goto after_2;
    // 0x80440A20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80440A24: jal         0x804400F0
    // 0x80440A28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804400F0(rdram, ctx);
        goto after_3;
    // 0x80440A28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80440A2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80440A30: jal         0x8043EFF8
    // 0x80440A34: lw          $a1, 0x262C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X262C);
    func_8043EFF8(rdram, ctx);
        goto after_4;
    // 0x80440A34: lw          $a1, 0x262C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X262C);
    after_4:
    // 0x80440A38: jal         0x80440950
    // 0x80440A3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80440950(rdram, ctx);
        goto after_5;
    // 0x80440A3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80440A40: lw          $t6, 0x262C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X262C);
    // 0x80440A44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80440A48: slti        $at, $t6, 0x96
    ctx->r1 = SIGNED(ctx->r14) < 0X96 ? 1 : 0;
    // 0x80440A4C: bnel        $at, $zero, L_80440A68
    if (ctx->r1 != 0) {
        // 0x80440A50: lw          $t7, 0x2628($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X2628);
            goto L_80440A68;
    }
    goto skip_0;
    // 0x80440A50: lw          $t7, 0x2628($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2628);
    skip_0:
    // 0x80440A54: jal         0x8043F914
    // 0x80440A58: sw          $zero, 0x2628($s0)
    MEM_W(0X2628, ctx->r16) = 0;
    func_8043F914(rdram, ctx);
        goto after_6;
    // 0x80440A58: sw          $zero, 0x2628($s0)
    MEM_W(0X2628, ctx->r16) = 0;
    after_6:
    // 0x80440A5C: b           L_80440D84
    // 0x80440A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80440D84;
    // 0x80440A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80440A64: lw          $t7, 0x2628($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2628);
L_80440A68:
    // 0x80440A68: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80440A6C: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x80440A70: bne         $at, $zero, L_80440D80
    if (ctx->r1 != 0) {
        // 0x80440A74: sw          $t8, 0x2628($s0)
        MEM_W(0X2628, ctx->r16) = ctx->r24;
            goto L_80440D80;
    }
    // 0x80440A74: sw          $t8, 0x2628($s0)
    MEM_W(0X2628, ctx->r16) = ctx->r24;
    // 0x80440A78: lw          $t1, 0x262C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X262C);
    // 0x80440A7C: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x80440A80: sw          $zero, 0x2628($s0)
    MEM_W(0X2628, ctx->r16) = 0;
    // 0x80440A84: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440A88: lw          $t0, 0x180($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X180);
    // 0x80440A8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80440A90: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80440A94: lwc1        $f4, 0x3C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x80440A98: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80440A9C: mflo        $t2
    ctx->r10 = lo;
    // 0x80440AA0: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80440AA4: swc1        $f4, -0x2C($t3)
    MEM_W(-0X2C, ctx->r11) = ctx->f4.u32l;
    // 0x80440AA8: lw          $t5, 0x262C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X262C);
    // 0x80440AAC: lw          $t4, 0x180($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X180);
    // 0x80440AB0: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440AB4: lwc1        $f6, 0x40($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X40);
    // 0x80440AB8: mflo        $t6
    ctx->r14 = lo;
    // 0x80440ABC: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80440AC0: swc1        $f6, -0x28($t7)
    MEM_W(-0X28, ctx->r15) = ctx->f6.u32l;
    // 0x80440AC4: lw          $t8, 0x262C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X262C);
    // 0x80440AC8: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440ACC: mflo        $t9
    ctx->r25 = lo;
    // 0x80440AD0: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80440AD4: swc1        $f0, -0x24($t0)
    MEM_W(-0X24, ctx->r8) = ctx->f0.u32l;
    // 0x80440AD8: lw          $t1, 0x262C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X262C);
    // 0x80440ADC: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440AE0: mflo        $t2
    ctx->r10 = lo;
    // 0x80440AE4: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80440AE8: swc1        $f0, -0x20($t3)
    MEM_W(-0X20, ctx->r11) = ctx->f0.u32l;
    // 0x80440AEC: lw          $t5, 0x262C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X262C);
    // 0x80440AF0: lw          $t4, 0x180($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X180);
    // 0x80440AF4: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440AF8: lwc1        $f8, 0x3C($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X3C);
    // 0x80440AFC: mflo        $t6
    ctx->r14 = lo;
    // 0x80440B00: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80440B04: swc1        $f8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f8.u32l;
    // 0x80440B08: lw          $t9, 0x262C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X262C);
    // 0x80440B0C: lw          $t8, 0x180($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X180);
    // 0x80440B10: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440B14: lwc1        $f10, 0x40($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X40);
    // 0x80440B18: mflo        $t0
    ctx->r8 = lo;
    // 0x80440B1C: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80440B20: swc1        $f10, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f10.u32l;
    // 0x80440B24: lw          $t2, 0x262C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X262C);
    // 0x80440B28: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440B2C: mflo        $t3
    ctx->r11 = lo;
    // 0x80440B30: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80440B34: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x80440B38: lw          $t5, 0x262C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X262C);
    // 0x80440B3C: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440B40: mflo        $t6
    ctx->r14 = lo;
    // 0x80440B44: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80440B48: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
    // 0x80440B4C: lw          $t9, 0x262C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X262C);
    // 0x80440B50: lw          $t8, 0x180($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X180);
    // 0x80440B54: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440B58: lwc1        $f16, 0x3C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X3C);
    // 0x80440B5C: mflo        $t0
    ctx->r8 = lo;
    // 0x80440B60: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80440B64: swc1        $f16, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f16.u32l;
    // 0x80440B68: lw          $t3, 0x262C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X262C);
    // 0x80440B6C: lw          $t2, 0x180($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X180);
    // 0x80440B70: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440B74: lwc1        $f18, 0x40($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X40);
    // 0x80440B78: mflo        $t4
    ctx->r12 = lo;
    // 0x80440B7C: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80440B80: swc1        $f18, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->f18.u32l;
    // 0x80440B84: lw          $t6, 0x262C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X262C);
    // 0x80440B88: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440B8C: mflo        $t7
    ctx->r15 = lo;
    // 0x80440B90: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80440B94: swc1        $f0, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f0.u32l;
    // 0x80440B98: lw          $t9, 0x262C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X262C);
    // 0x80440B9C: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440BA0: mflo        $t0
    ctx->r8 = lo;
    // 0x80440BA4: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80440BA8: swc1        $f0, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f0.u32l;
L_80440BAC:
    // 0x80440BAC: lw          $t3, 0x262C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X262C);
    // 0x80440BB0: lw          $t2, 0x180($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X180);
    // 0x80440BB4: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80440BB8: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440BBC: lwc1        $f4, 0x3C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X3C);
    // 0x80440BC0: mflo        $t5
    ctx->r13 = lo;
    // 0x80440BC4: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x80440BC8: swc1        $f4, -0x2C($t6)
    MEM_W(-0X2C, ctx->r14) = ctx->f4.u32l;
    // 0x80440BCC: lw          $t8, 0x262C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X262C);
    // 0x80440BD0: lw          $t7, 0x180($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X180);
    // 0x80440BD4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80440BD8: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440BDC: lwc1        $f6, 0x40($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X40);
    // 0x80440BE0: mflo        $t0
    ctx->r8 = lo;
    // 0x80440BE4: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80440BE8: swc1        $f6, -0x28($t1)
    MEM_W(-0X28, ctx->r9) = ctx->f6.u32l;
    // 0x80440BEC: lw          $t2, 0x262C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X262C);
    // 0x80440BF0: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80440BF4: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440BF8: mflo        $t4
    ctx->r12 = lo;
    // 0x80440BFC: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80440C00: swc1        $f0, -0x24($t5)
    MEM_W(-0X24, ctx->r13) = ctx->f0.u32l;
    // 0x80440C04: lw          $t6, 0x262C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X262C);
    // 0x80440C08: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80440C0C: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440C10: mflo        $t8
    ctx->r24 = lo;
    // 0x80440C14: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80440C18: swc1        $f0, -0x20($t9)
    MEM_W(-0X20, ctx->r25) = ctx->f0.u32l;
    // 0x80440C1C: lw          $t1, 0x262C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X262C);
    // 0x80440C20: lw          $t0, 0x180($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X180);
    // 0x80440C24: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80440C28: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440C2C: lwc1        $f8, 0x3C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x80440C30: mflo        $t3
    ctx->r11 = lo;
    // 0x80440C34: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80440C38: swc1        $f8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f8.u32l;
    // 0x80440C3C: lw          $t6, 0x262C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X262C);
    // 0x80440C40: lw          $t5, 0x180($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X180);
    // 0x80440C44: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80440C48: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440C4C: lwc1        $f10, 0x40($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X40);
    // 0x80440C50: mflo        $t8
    ctx->r24 = lo;
    // 0x80440C54: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80440C58: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
    // 0x80440C5C: lw          $t0, 0x262C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X262C);
    // 0x80440C60: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80440C64: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440C68: mflo        $t2
    ctx->r10 = lo;
    // 0x80440C6C: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80440C70: swc1        $f0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f0.u32l;
    // 0x80440C74: lw          $t4, 0x262C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X262C);
    // 0x80440C78: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80440C7C: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440C80: mflo        $t6
    ctx->r14 = lo;
    // 0x80440C84: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80440C88: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
    // 0x80440C8C: lw          $t9, 0x262C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X262C);
    // 0x80440C90: lw          $t8, 0x180($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X180);
    // 0x80440C94: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80440C98: multu       $t0, $v1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440C9C: lwc1        $f16, 0x3C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X3C);
    // 0x80440CA0: mflo        $t1
    ctx->r9 = lo;
    // 0x80440CA4: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x80440CA8: swc1        $f16, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f16.u32l;
    // 0x80440CAC: lw          $t4, 0x262C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X262C);
    // 0x80440CB0: lw          $t3, 0x180($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X180);
    // 0x80440CB4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80440CB8: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440CBC: lwc1        $f18, 0x40($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X40);
    // 0x80440CC0: mflo        $t6
    ctx->r14 = lo;
    // 0x80440CC4: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80440CC8: swc1        $f18, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f18.u32l;
    // 0x80440CCC: lw          $t8, 0x262C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X262C);
    // 0x80440CD0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80440CD4: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440CD8: mflo        $t0
    ctx->r8 = lo;
    // 0x80440CDC: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80440CE0: swc1        $f0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f0.u32l;
    // 0x80440CE4: lw          $t2, 0x262C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X262C);
    // 0x80440CE8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80440CEC: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440CF0: mflo        $t4
    ctx->r12 = lo;
    // 0x80440CF4: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80440CF8: swc1        $f0, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f0.u32l;
    // 0x80440CFC: lw          $t7, 0x262C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X262C);
    // 0x80440D00: lw          $t6, 0x180($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X180);
    // 0x80440D04: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80440D08: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440D0C: lwc1        $f4, 0x3C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x80440D10: mflo        $t9
    ctx->r25 = lo;
    // 0x80440D14: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80440D18: swc1        $f4, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f4.u32l;
    // 0x80440D1C: lw          $t2, 0x262C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X262C);
    // 0x80440D20: lw          $t1, 0x180($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X180);
    // 0x80440D24: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80440D28: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440D2C: lwc1        $f6, 0x40($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X40);
    // 0x80440D30: mflo        $t4
    ctx->r12 = lo;
    // 0x80440D34: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x80440D38: swc1        $f6, 0x68($t5)
    MEM_W(0X68, ctx->r13) = ctx->f6.u32l;
    // 0x80440D3C: lw          $t6, 0x262C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X262C);
    // 0x80440D40: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80440D44: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440D48: mflo        $t8
    ctx->r24 = lo;
    // 0x80440D4C: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80440D50: swc1        $f0, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f0.u32l;
    // 0x80440D54: lw          $t0, 0x262C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X262C);
    // 0x80440D58: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80440D5C: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80440D60: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80440D64: mflo        $t2
    ctx->r10 = lo;
    // 0x80440D68: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80440D6C: bne         $v0, $a0, L_80440BAC
    if (ctx->r2 != ctx->r4) {
        // 0x80440D70: swc1        $f0, 0x70($t3)
        MEM_W(0X70, ctx->r11) = ctx->f0.u32l;
            goto L_80440BAC;
    }
    // 0x80440D70: swc1        $f0, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f0.u32l;
    // 0x80440D74: lw          $t4, 0x262C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X262C);
    // 0x80440D78: addiu       $t5, $t4, 0xF
    ctx->r13 = ADD32(ctx->r12, 0XF);
    // 0x80440D7C: sw          $t5, 0x262C($s0)
    MEM_W(0X262C, ctx->r16) = ctx->r13;
L_80440D80:
    // 0x80440D80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80440D84:
    // 0x80440D84: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80440D88: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80440D8C: jr          $ra
    // 0x80440D90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80440D90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80076AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80076AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076AA8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076AAC: sw          $a0, -0x7AF0($at)
    MEM_W(-0X7AF0, ctx->r1) = ctx->r4;
    // 0x80076AB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076AB4: sw          $zero, -0x7AEC($at)
    MEM_W(-0X7AEC, ctx->r1) = 0;
    // 0x80076AB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076ABC: jal         0x8007691C
    // 0x80076AC0: sw          $zero, -0x7AE8($at)
    MEM_W(-0X7AE8, ctx->r1) = 0;
    func_8007691C(rdram, ctx);
        goto after_0;
    // 0x80076AC0: sw          $zero, -0x7AE8($at)
    MEM_W(-0X7AE8, ctx->r1) = 0;
    after_0:
    // 0x80076AC4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80076AC8: lui         $a1, 0x3
    ctx->r5 = S32(0X3 << 16);
    // 0x80076ACC: ori         $a1, $a1, 0x36F0
    ctx->r5 = ctx->r5 | 0X36F0;
    // 0x80076AD0: jal         0x80084820
    // 0x80076AD4: addiu       $a0, $a0, 0x40C0
    ctx->r4 = ADD32(ctx->r4, 0X40C0);
    _blkclr(rdram, ctx);
        goto after_1;
    // 0x80076AD4: addiu       $a0, $a0, 0x40C0
    ctx->r4 = ADD32(ctx->r4, 0X40C0);
    after_1:
    // 0x80076AD8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80076ADC: jal         0x80078E40
    // 0x80076AE0: addiu       $a0, $a0, -0x269C
    ctx->r4 = ADD32(ctx->r4, -0X269C);
    func_80078E40(rdram, ctx);
        goto after_2;
    // 0x80076AE0: addiu       $a0, $a0, -0x269C
    ctx->r4 = ADD32(ctx->r4, -0X269C);
    after_2:
    // 0x80076AE4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80076AE8: jal         0x80076B20
    // 0x80076AEC: addiu       $a0, $a0, -0x2698
    ctx->r4 = ADD32(ctx->r4, -0X2698);
    func_80076B20(rdram, ctx);
        goto after_3;
    // 0x80076AEC: addiu       $a0, $a0, -0x2698
    ctx->r4 = ADD32(ctx->r4, -0X2698);
    after_3:
    // 0x80076AF0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80076AF4: jal         0x8007EA54
    // 0x80076AF8: addiu       $a0, $a0, -0x2690
    ctx->r4 = ADD32(ctx->r4, -0X2690);
    ViMode_Init(rdram, ctx);
        goto after_4;
    // 0x80076AF8: addiu       $a0, $a0, -0x2690
    ctx->r4 = ADD32(ctx->r4, -0X2690);
    after_4:
    // 0x80076AFC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80076B00: jal         0x8007914C
    // 0x80076B04: addiu       $a0, $a0, -0x2600
    ctx->r4 = ADD32(ctx->r4, -0X2600);
    func_8007914C(rdram, ctx);
        goto after_5;
    // 0x80076B04: addiu       $a0, $a0, -0x2600
    ctx->r4 = ADD32(ctx->r4, -0X2600);
    after_5:
    // 0x80076B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80076B10: jr          $ra
    // 0x80076B14: nop

    return;
    // 0x80076B14: nop

    // 0x80076B18: nop

    // 0x80076B1C: nop

;}
