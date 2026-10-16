#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_805221A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805221A0: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(318, 0X30) << 16);
    // 0x805221A4: addiu       $v0, $v0, 0x21D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(318, 0X30));
    // 0x805221A8: jr          $ra
    // 0x805221AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805221AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80439BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439BAC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80439BB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80439BB4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80439BB8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80439BBC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80439BC0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80439BC4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80439BC8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80439BCC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80439BD0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80439BD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80439BD8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80439BDC: lw          $s4, 0x14C($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X14C);
    // 0x80439BE0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80439BE4: lw          $a3, 0x970($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X970);
    // 0x80439BE8: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
    // 0x80439BEC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80439BF0: xori        $a3, $a3, 0x1
    ctx->r7 = ctx->r7 ^ 0X1;
    // 0x80439BF4: andi        $a3, $a3, 0x1
    ctx->r7 = ctx->r7 & 0X1;
    // 0x80439BF8: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80439BFC: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x80439C00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80439C04: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x80439C08: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80439C0C: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x80439C10: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80439C14: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80439C18: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x80439C1C: lw          $s7, 0x16C($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X16C);
    // 0x80439C20: sw          $a3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r7;
    // 0x80439C24: addiu       $fp, $zero, 0x260
    ctx->r30 = ADD32(0, 0X260);
    // 0x80439C28: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80439C2C: addiu       $s5, $v0, 0xAB0
    ctx->r21 = ADD32(ctx->r2, 0XAB0);
L_80439C30:
    // 0x80439C30: lw          $t8, 0x15C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X15C);
    // 0x80439C34: sll         $t0, $s4, 1
    ctx->r8 = S32(ctx->r20 << 1);
    // 0x80439C38: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x80439C3C: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80439C40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80439C44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80439C48: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80439C4C: lbu         $s3, 0x1($t1)
    ctx->r19 = MEM_BU(ctx->r9, 0X1);
    // 0x80439C50: jal         0x80438CE0
    // 0x80439C54: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80438CE0(rdram, ctx);
        goto after_0;
    // 0x80439C54: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_0:
    // 0x80439C58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80439C5C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80439C60: jal         0x80439498
    // 0x80439C64: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    func_80439498(rdram, ctx);
        goto after_1;
    // 0x80439C64: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    after_1:
    // 0x80439C68: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x80439C6C: bltz        $t2, L_80439C90
    if (SIGNED(ctx->r10) < 0) {
        // 0x80439C70: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80439C90;
    }
    // 0x80439C70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80439C74:
    // 0x80439C74: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80439C78: jal         0x804395D0
    // 0x80439C7C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_804395D0(rdram, ctx);
        goto after_2;
    // 0x80439C7C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80439C80: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80439C84: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80439C88: bgezl       $t3, L_80439C74
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80439C8C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80439C74;
    }
    goto skip_0;
    // 0x80439C8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_80439C90:
    // 0x80439C90: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80439C94: sltiu       $at, $s4, 0xE
    ctx->r1 = ctx->r20 < 0XE ? 1 : 0;
    // 0x80439C98: bne         $at, $zero, L_80439CA4
    if (ctx->r1 != 0) {
        // 0x80439C9C: addiu       $s6, $s6, 0x4C
        ctx->r22 = ADD32(ctx->r22, 0X4C);
            goto L_80439CA4;
    }
    // 0x80439C9C: addiu       $s6, $s6, 0x4C
    ctx->r22 = ADD32(ctx->r22, 0X4C);
    // 0x80439CA0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80439CA4:
    // 0x80439CA4: bne         $s6, $fp, L_80439C30
    if (ctx->r22 != ctx->r30) {
        // 0x80439CA8: addiu       $s5, $s5, 0x4C
        ctx->r21 = ADD32(ctx->r21, 0X4C);
            goto L_80439C30;
    }
    // 0x80439CA8: addiu       $s5, $s5, 0x4C
    ctx->r21 = ADD32(ctx->r21, 0X4C);
    // 0x80439CAC: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80439CB0: lui         $t6, 0xB800
    ctx->r14 = S32(0XB800 << 16);
    // 0x80439CB4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80439CB8: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x80439CBC: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80439CC0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80439CC4: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80439CC8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80439CCC: sw          $t7, 0x970($t8)
    MEM_W(0X970, ctx->r24) = ctx->r15;
    // 0x80439CD0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80439CD4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80439CD8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80439CDC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80439CE0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80439CE4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80439CE8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80439CEC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80439CF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80439CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80439CF8: jr          $ra
    // 0x80439CFC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80439CFC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80584B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584B4C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584B50: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584B54: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584B58: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584B5C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584B60: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584B64: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584B68: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584B6C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584B70: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584B74: jr          $ra
    // 0x80584B78: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584B78: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80535F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535F54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80535F58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80535F5C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80535F60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80535F64: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80535F68: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80535F6C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80535F70: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535F74: addiu       $t6, $zero, 0x1E3C
    ctx->r14 = ADD32(0, 0X1E3C);
    // 0x80535F78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80535F7C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80535F80: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80535F84: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x80535F88: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80535F8C: jal         0x8053589C
    // 0x80535F90: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8053589C(rdram, ctx);
        goto after_0;
    // 0x80535F90: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80535F94: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80535F98: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80535F9C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80535FA0: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x80535FA4: addiu       $t8, $zero, 0x1E3C
    ctx->r24 = ADD32(0, 0X1E3C);
    // 0x80535FA8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80535FAC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80535FB0: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x80535FB4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80535FB8: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80535FBC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80535FC0: jal         0x8053589C
    // 0x80535FC4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8053589C(rdram, ctx);
        goto after_1;
    // 0x80535FC4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80535FC8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80535FCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535FD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535FD4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535FD8: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535FDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80535FE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80535FE4: jr          $ra
    // 0x80535FE8: nop

    return;
    // 0x80535FE8: nop

;}
RECOMP_FUNC void func_800303FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800303FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80030400: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80030404: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80030408: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003040C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80030410: jal         0x80021A44
    // 0x80030414: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80021A44(rdram, ctx);
        goto after_0;
    // 0x80030414: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80030418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003041C: jal         0x80042880
    // 0x80030420: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80042880(rdram, ctx);
        goto after_1;
    // 0x80030420: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80030424: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80030428: lw          $t8, 0x78($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X78);
    // 0x8003042C: beq         $t8, $zero, L_80030444
    if (ctx->r24 == 0) {
        // 0x80030430: nop
    
            goto L_80030444;
    }
    // 0x80030430: nop

    // 0x80030434: jal         0x8002E7C8
    // 0x80030438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E7C8(rdram, ctx);
        goto after_2;
    // 0x80030438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003043C: b           L_8003047C
    // 0x80030440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003047C;
    // 0x80030440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80030444:
    // 0x80030444: jal         0x80028220
    // 0x80030448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_3;
    // 0x80030448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8003044C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80030450: sw          $v0, 0x78($t9)
    MEM_W(0X78, ctx->r25) = ctx->r2;
    // 0x80030454: jal         0x80065954
    // 0x80030458: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x80030458: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    after_4:
    // 0x8003045C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80030460: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80030464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80030468: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003046C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80030470: jal         0x80041214
    // 0x80030474: nop

    func_80041214(rdram, ctx);
        goto after_5;
    // 0x80030474: nop

    after_5:
    // 0x80030478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003047C:
    // 0x8003047C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80030480: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80030484: jr          $ra
    // 0x80030488: nop

    return;
    // 0x80030488: nop

;}
RECOMP_FUNC void func_800273A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800273A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800273A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800273A8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800273AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800273B0: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x800273B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800273B8: nop

    // 0x800273BC: bc1fl       L_800273D0
    if (!c1cs) {
        // 0x800273C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800273D0;
    }
    goto skip_0;
    // 0x800273C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800273C4: jal         0x80027384
    // 0x800273C8: nop

    func_80027384(rdram, ctx);
        goto after_0;
    // 0x800273C8: nop

    after_0:
    // 0x800273CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800273D0:
    // 0x800273D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800273D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800273D8: jr          $ra
    // 0x800273DC: nop

    return;
    // 0x800273DC: nop

;}
RECOMP_FUNC void func_807AF2D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF2D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807AF2DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AF2E0: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x807AF2E4: lwc1        $f12, 0x3C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x807AF2E8: lwc1        $f14, 0x40($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807AF2EC: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x807AF2F0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AF2F4: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x807AF2F8: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x807AF2FC: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x807AF300: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807AF304: sub.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x807AF308: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x807AF30C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x807AF310: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x807AF314: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x807AF318: jal         0x80067114
    // 0x807AF31C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x807AF31C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x807AF320: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x807AF324: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807AF328: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807AF32C: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807AF330: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x807AF334: div.s       $f16, $f12, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
    // 0x807AF338: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807AF33C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807AF340: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x807AF344: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x807AF348: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807AF34C: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x807AF350: div.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x807AF354: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    // 0x807AF358: swc1        $f18, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f18.u32l;
    // 0x807AF35C: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x807AF360: bnel        $t7, $zero, L_807AF37C
    if (ctx->r15 != 0) {
        // 0x807AF364: lw          $t0, 0x180($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X180);
            goto L_807AF37C;
    }
    goto skip_0;
    // 0x807AF364: lw          $t0, 0x180($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X180);
    skip_0:
    // 0x807AF368: lw          $t9, 0x180($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X180);
    // 0x807AF36C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807AF370: b           L_807AF394
    // 0x807AF374: sw          $t8, 0x1E0($t9)
    MEM_W(0X1E0, ctx->r25) = ctx->r24;
        goto L_807AF394;
    // 0x807AF374: sw          $t8, 0x1E0($t9)
    MEM_W(0X1E0, ctx->r25) = ctx->r24;
    // 0x807AF378: lw          $t0, 0x180($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X180);
L_807AF37C:
    // 0x807AF37C: lbu         $t1, 0x30($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X30);
    // 0x807AF380: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x807AF384: bnel        $at, $zero, L_807AF398
    if (ctx->r1 != 0) {
        // 0x807AF388: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807AF398;
    }
    goto skip_1;
    // 0x807AF388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x807AF38C: jal         0x807AF508
    // 0x807AF390: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_807AF508(rdram, ctx);
        goto after_1;
    // 0x807AF390: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_807AF394:
    // 0x807AF394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807AF398:
    // 0x807AF398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807AF39C: jr          $ra
    // 0x807AF3A0: nop

    return;
    // 0x807AF3A0: nop

;}
RECOMP_FUNC void func_804C995C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C995C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C9960: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x804C9964: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x804C9968: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x804C996C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804C9970: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x804C9974: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C9978: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x804C997C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x804C9980: jal         0x800653D8
    // 0x804C9984: lw          $s2, -0x7CE8($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X7CE8);
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x804C9984: lw          $s2, -0x7CE8($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X7CE8);
    after_0:
    // 0x804C9988: andi        $t6, $v0, 0x10
    ctx->r14 = ctx->r2 & 0X10;
    // 0x804C998C: beq         $t6, $zero, L_804C99AC
    if (ctx->r14 == 0) {
        // 0x804C9990: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_804C99AC;
    }
    // 0x804C9990: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x804C9994: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x804C9998: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C999C: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x804C99A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804C99A4: b           L_804C99C0
    // 0x804C99A8: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
        goto L_804C99C0;
    // 0x804C99A8: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
L_804C99AC:
    // 0x804C99AC: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x804C99B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804C99B4: lwc1        $f10, 0x18($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X18);
    // 0x804C99B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x804C99BC: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_804C99C0:
    // 0x804C99C0: andi        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 & 0X3;
    // 0x804C99C4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x804C99C8: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X7B8) << 16);
    // 0x804C99CC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x804C99D0: lwc1        $f4, -0x6508($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X7B8));
    // 0x804C99D4: lwc1        $f6, 0x88($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X88);
    // 0x804C99D8: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X7F8) << 16);
    // 0x804C99DC: slti        $t8, $v0, 0x4
    ctx->r24 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x804C99E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804C99E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C99E8: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x804C99EC: lwc1        $f10, -0x64C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X7F8));
    // 0x804C99F0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(228, 0X7D8) << 16);
    // 0x804C99F4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x804C99F8: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x804C99FC: lwc1        $f20, -0x64E8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(228, 0X7D8));
    // 0x804C9A00: lwc1        $f12, 0x30($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X30);
    // 0x804C9A04: jal         0x80053924
    // 0x804C9A08: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    func_80053924(rdram, ctx);
        goto after_1;
    // 0x804C9A08: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x804C9A0C: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x804C9A10: bnel        $s1, $v0, L_804C9A3C
    if (ctx->r17 != ctx->r2) {
        // 0x804C9A14: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_804C9A3C;
    }
    goto skip_0;
    // 0x804C9A14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x804C9A18: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
L_804C9A1C:
    // 0x804C9A1C: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x804C9A20: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x804C9A24: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804C9A28: jal         0x80053924
    // 0x804C9A2C: lwc1        $f12, 0x30($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X30);
    func_80053924(rdram, ctx);
        goto after_2;
    // 0x804C9A2C: lwc1        $f12, 0x30($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X30);
    after_2:
    // 0x804C9A30: beql        $s1, $v0, L_804C9A1C
    if (ctx->r17 == ctx->r2) {
        // 0x804C9A34: lwc1        $f16, 0x4($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
            goto L_804C9A1C;
    }
    goto skip_1;
    // 0x804C9A34: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x804C9A38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_804C9A3C:
    // 0x804C9A3C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804C9A40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804C9A44: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x804C9A48: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x804C9A4C: jr          $ra
    // 0x804C9A50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804C9A50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80048AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048AE8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x80048AEC: lbu         $t7, 0x7EA5($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7EA5);
    // 0x80048AF0: lbu         $t6, 0x10($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X10);
    // 0x80048AF4: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80048AF8: bnel        $at, $zero, L_80048B18
    if (ctx->r1 != 0) {
        // 0x80048AFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80048B18;
    }
    goto skip_0;
    // 0x80048AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80048B00: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x80048B04: beql        $v0, $zero, L_80048B18
    if (ctx->r2 == 0) {
        // 0x80048B08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80048B18;
    }
    goto skip_1;
    // 0x80048B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80048B0C: jalr        $v0
    // 0x80048B10: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80048B10: nop

    after_0:
    // 0x80048B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048B18:
    // 0x80048B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048B1C: jr          $ra
    // 0x80048B20: nop

    return;
    // 0x80048B20: nop

;}
RECOMP_FUNC void func_805D8AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D8AF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D8AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D8B00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805D8B04: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805D8B08: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805D8B0C: jal         0x80047090
    // 0x805D8B10: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805D8B10: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x805D8B14: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805D8B18: beq         $v0, $at, L_805D8B60
    if (ctx->r2 == ctx->r1) {
        // 0x805D8B1C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805D8B60;
    }
    // 0x805D8B1C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805D8B20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805D8B24: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x805D8B28: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x805D8B2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805D8B30: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x805D8B34: ori         $t8, $t7, 0x2400
    ctx->r24 = ctx->r15 | 0X2400;
    // 0x805D8B38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805D8B3C: jal         0x8004613C
    // 0x805D8B40: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805D8B40: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    after_1:
    // 0x805D8B44: beq         $v0, $zero, L_805D8B60
    if (ctx->r2 == 0) {
        // 0x805D8B48: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_805D8B60;
    }
    // 0x805D8B48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805D8B4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805D8B50: jal         0x80047F9C
    // 0x805D8B54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x805D8B54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x805D8B58: b           L_805D8B64
    // 0x805D8B5C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_805D8B64;
    // 0x805D8B5C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_805D8B60:
    // 0x805D8B60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D8B64:
    // 0x805D8B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D8B68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D8B6C: jr          $ra
    // 0x805D8B70: nop

    return;
    // 0x805D8B70: nop

    // 0x805D8B74: nop

    // 0x805D8B78: nop

    // 0x805D8B7C: nop

;}
RECOMP_FUNC void func_8002E428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E42C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E430: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002E434: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002E438: jal         0x8002E22C
    // 0x8002E43C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_8002E22C(rdram, ctx);
        goto after_0;
    // 0x8002E43C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8002E440: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E444: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8002E448: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8002E44C: jal         0x8002E274
    // 0x8002E450: swc1        $f4, 0x58($a1)
    MEM_W(0X58, ctx->r5) = ctx->f4.u32l;
    func_8002E274(rdram, ctx);
        goto after_1;
    // 0x8002E450: swc1        $f4, 0x58($a1)
    MEM_W(0X58, ctx->r5) = ctx->f4.u32l;
    after_1:
    // 0x8002E454: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8002E458: lw          $t6, 0x138($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X138);
    // 0x8002E45C: lwc1        $f0, 0x120($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X120);
    // 0x8002E460: beql        $t6, $zero, L_8002E474
    if (ctx->r14 == 0) {
        // 0x8002E464: neg.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
            goto L_8002E474;
    }
    goto skip_0;
    // 0x8002E464: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    skip_0:
    // 0x8002E468: b           L_8002E478
    // 0x8002E46C: swc1        $f0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
        goto L_8002E478;
    // 0x8002E46C: swc1        $f0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
    // 0x8002E470: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
L_8002E474:
    // 0x8002E474: swc1        $f6, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f6.u32l;
L_8002E478:
    // 0x8002E478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E47C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002E480: jr          $ra
    // 0x8002E484: nop

    return;
    // 0x8002E484: nop

;}
RECOMP_FUNC void func_8056353C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056353C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80563540: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80563544: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80563548: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8056354C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80563550: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80563554: lw          $t9, 0x878($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X878);
    // 0x80563558: lw          $t6, 0x710($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X710);
    // 0x8056355C: jalr        $t9
    // 0x80563560: sw          $t6, 0x714($s0)
    MEM_W(0X714, ctx->r16) = ctx->r14;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80563560: sw          $t6, 0x714($s0)
    MEM_W(0X714, ctx->r16) = ctx->r14;
    after_0:
    // 0x80563564: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80563568: lwc1        $f0, 0x724($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X724);
    // 0x8056356C: sw          $v0, 0x710($s0)
    MEM_W(0X710, ctx->r16) = ctx->r2;
    // 0x80563570: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x80563574: nop

    // 0x80563578: bc1tl       L_80563594
    if (c1cs) {
        // 0x8056357C: c.eq.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
            goto L_80563594;
    }
    goto skip_0;
    // 0x8056357C: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    skip_0:
    // 0x80563580: jal         0x805614FC
    // 0x80563584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805614FC(rdram, ctx);
        goto after_1;
    // 0x80563584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80563588: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8056358C: lwc1        $f0, 0x724($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X724);
    // 0x80563590: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
L_80563594:
    // 0x80563594: nop

    // 0x80563598: bc1tl       L_805635D8
    if (c1cs) {
        // 0x8056359C: lwc1        $f2, 0x71C($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X71C);
            goto L_805635D8;
    }
    goto skip_1;
    // 0x8056359C: lwc1        $f2, 0x71C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X71C);
    skip_1:
    // 0x805635A0: lw          $t7, 0x708($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X708);
    // 0x805635A4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x805635A8: sw          $t8, 0x708($s0)
    MEM_W(0X708, ctx->r16) = ctx->r24;
    // 0x805635AC: bgez        $t8, L_805635BC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x805635B0: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_805635BC;
    }
    // 0x805635B0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x805635B4: addiu       $v1, $t8, 0xD8
    ctx->r3 = ADD32(ctx->r24, 0XD8);
    // 0x805635B8: sw          $v1, 0x708($s0)
    MEM_W(0X708, ctx->r16) = ctx->r3;
L_805635BC:
    // 0x805635BC: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x805635C0: sll         $t1, $v1, 3
    ctx->r9 = S32(ctx->r3 << 3);
    // 0x805635C4: addu        $v0, $s0, $t1
    ctx->r2 = ADD32(ctx->r16, ctx->r9);
    // 0x805635C8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x805635CC: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x805635D0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x805635D4: lwc1        $f2, 0x71C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X71C);
L_805635D8:
    // 0x805635D8: lwc1        $f0, 0x718($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X718);
    // 0x805635DC: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x805635E0: nop

    // 0x805635E4: bc1tl       L_80563658
    if (c1cs) {
        // 0x805635E8: lw          $t2, 0x710($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X710);
            goto L_80563658;
    }
    goto skip_2;
    // 0x805635E8: lw          $t2, 0x710($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X710);
    skip_2:
    // 0x805635EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805635F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805635F4: bc1fl       L_80563630
    if (!c1cs) {
        // 0x805635F8: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80563630;
    }
    goto skip_3;
    // 0x805635F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_3:
    // 0x805635FC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80563600: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80563604: nop

    // 0x80563608: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8056360C: swc1        $f10, 0x718($s0)
    MEM_W(0X718, ctx->r16) = ctx->f10.u32l;
    // 0x80563610: lwc1        $f16, 0x718($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X718);
    // 0x80563614: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80563618: nop

    // 0x8056361C: bc1fl       L_80563658
    if (!c1cs) {
        // 0x80563620: lw          $t2, 0x710($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X710);
            goto L_80563658;
    }
    goto skip_4;
    // 0x80563620: lw          $t2, 0x710($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X710);
    skip_4:
    // 0x80563624: b           L_80563654
    // 0x80563628: swc1        $f2, 0x718($s0)
    MEM_W(0X718, ctx->r16) = ctx->f2.u32l;
        goto L_80563654;
    // 0x80563628: swc1        $f2, 0x718($s0)
    MEM_W(0X718, ctx->r16) = ctx->f2.u32l;
    // 0x8056362C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80563630:
    // 0x80563630: nop

    // 0x80563634: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80563638: swc1        $f4, 0x718($s0)
    MEM_W(0X718, ctx->r16) = ctx->f4.u32l;
    // 0x8056363C: lwc1        $f6, 0x718($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X718);
    // 0x80563640: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80563644: nop

    // 0x80563648: bc1fl       L_80563658
    if (!c1cs) {
        // 0x8056364C: lw          $t2, 0x710($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X710);
            goto L_80563658;
    }
    goto skip_5;
    // 0x8056364C: lw          $t2, 0x710($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X710);
    skip_5:
    // 0x80563650: swc1        $f2, 0x718($s0)
    MEM_W(0X718, ctx->r16) = ctx->f2.u32l;
L_80563654:
    // 0x80563654: lw          $t2, 0x710($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X710);
L_80563658:
    // 0x80563658: beq         $t2, $zero, L_80563690
    if (ctx->r10 == 0) {
        // 0x8056365C: nop
    
            goto L_80563690;
    }
    // 0x8056365C: nop

    // 0x80563660: lw          $t3, 0x714($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X714);
    // 0x80563664: bne         $t3, $zero, L_80563690
    if (ctx->r11 != 0) {
        // 0x80563668: nop
    
            goto L_80563690;
    }
    // 0x80563668: nop

    // 0x8056366C: lwc1        $f8, 0x724($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X724);
    // 0x80563670: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80563674: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
    // 0x80563678: nop

    // 0x8056367C: bc1f        L_80563690
    if (!c1cs) {
        // 0x80563680: nop
    
            goto L_80563690;
    }
    // 0x80563680: nop

    // 0x80563684: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80563688: nop

    // 0x8056368C: swc1        $f10, 0x724($s0)
    MEM_W(0X724, ctx->r16) = ctx->f10.u32l;
L_80563690:
    // 0x80563690: jal         0x80066E88
    // 0x80563694: lwc1        $f12, 0x718($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X718);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80563694: lwc1        $f12, 0x718($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X718);
    after_2:
    // 0x80563698: lwc1        $f16, 0x724($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X724);
    // 0x8056369C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x805636A0: swc1        $f18, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f18.u32l;
    // 0x805636A4: jal         0x80066DE4
    // 0x805636A8: lwc1        $f12, 0x718($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X718);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x805636A8: lwc1        $f12, 0x718($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X718);
    after_3:
    // 0x805636AC: lwc1        $f6, 0x724($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X724);
    // 0x805636B0: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x805636B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805636B8: swc1        $f8, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f8.u32l;
    // 0x805636BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805636C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805636C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805636C8: jr          $ra
    // 0x805636CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805636CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8058178C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058178C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80581790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581794: jal         0x805815A4
    // 0x80581798: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_805815A4(rdram, ctx);
        goto after_0;
    // 0x80581798: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8058179C: bne         $v0, $zero, L_805817B4
    if (ctx->r2 != 0) {
        // 0x805817A0: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_805817B4;
    }
    // 0x805817A0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x805817A4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805817A8: lw          $t6, -0x7490($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7490);
    // 0x805817AC: b           L_80581828
    // 0x805817B0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
        goto L_80581828;
    // 0x805817B0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_805817B4:
    // 0x805817B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805817B8: bne         $v0, $at, L_805817CC
    if (ctx->r2 != ctx->r1) {
        // 0x805817BC: lui         $t7, 0x8010
        ctx->r15 = S32(0X8010 << 16);
            goto L_805817CC;
    }
    // 0x805817BC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805817C0: lw          $t7, -0x748C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X748C);
    // 0x805817C4: b           L_80581828
    // 0x805817C8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
        goto L_80581828;
    // 0x805817C8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_805817CC:
    // 0x805817CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805817D0: bne         $v0, $at, L_805817E4
    if (ctx->r2 != ctx->r1) {
        // 0x805817D4: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_805817E4;
    }
    // 0x805817D4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x805817D8: lw          $t8, -0x7488($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7488);
    // 0x805817DC: b           L_80581828
    // 0x805817E0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
        goto L_80581828;
    // 0x805817E0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_805817E4:
    // 0x805817E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805817E8: bne         $v0, $at, L_805817FC
    if (ctx->r2 != ctx->r1) {
        // 0x805817EC: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_805817FC;
    }
    // 0x805817EC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x805817F0: lw          $t9, -0x7484($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7484);
    // 0x805817F4: b           L_80581828
    // 0x805817F8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
        goto L_80581828;
    // 0x805817F8: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_805817FC:
    // 0x805817FC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80581800: bne         $v0, $at, L_80581814
    if (ctx->r2 != ctx->r1) {
        // 0x80581804: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_80581814;
    }
    // 0x80581804: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80581808: lw          $t0, -0x7480($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7480);
    // 0x8058180C: b           L_80581828
    // 0x80581810: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
        goto L_80581828;
    // 0x80581810: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_80581814:
    // 0x80581814: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80581818: bne         $v0, $at, L_80581828
    if (ctx->r2 != ctx->r1) {
        // 0x8058181C: lui         $t1, 0x8010
        ctx->r9 = S32(0X8010 << 16);
            goto L_80581828;
    }
    // 0x8058181C: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x80581820: lw          $t1, -0x747C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X747C);
    // 0x80581824: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_80581828:
    // 0x80581828: jal         0x805815D0
    // 0x8058182C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_805815D0(rdram, ctx);
        goto after_1;
    // 0x8058182C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80581830: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80581834: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80581838: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8058183C: jal         0x80581660
    // 0x80581840: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80581660(rdram, ctx);
        goto after_2;
    // 0x80581840: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80581844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581848: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8058184C: jr          $ra
    // 0x80581850: nop

    return;
    // 0x80581850: nop

;}
RECOMP_FUNC void func_804500F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804500F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804500FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450100: jal         0x80444408
    // 0x80450104: addiu       $a1, $zero, 0x4505
    ctx->r5 = ADD32(0, 0X4505);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x80450104: addiu       $a1, $zero, 0x4505
    ctx->r5 = ADD32(0, 0X4505);
    after_0:
    // 0x80450108: beq         $v0, $zero, L_80450118
    if (ctx->r2 == 0) {
        // 0x8045010C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80450118;
    }
    // 0x8045010C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80450110: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80450114: lw          $a0, 0x5C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X5C);
L_80450118:
    // 0x80450118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045011C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80450120: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80450124: jr          $ra
    // 0x80450128: nop

    return;
    // 0x80450128: nop

;}
RECOMP_FUNC void func_804A20DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A20DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804A20E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A20E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A20E8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804A20EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804A20F0: jal         0x804A2910
    // 0x804A20F4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_804A2910(rdram, ctx);
        goto after_0;
    // 0x804A20F4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x804A20F8: beql        $v0, $zero, L_804A21A0
    if (ctx->r2 == 0) {
        // 0x804A20FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804A21A0;
    }
    goto skip_0;
    // 0x804A20FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804A2100: lh          $t7, 0x184($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X184);
    // 0x804A2104: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x804A2108: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x804A210C: beql        $at, $zero, L_804A2150
    if (ctx->r1 == 0) {
        // 0x804A2110: lw          $t1, 0x0($t0)
        ctx->r9 = MEM_W(ctx->r8, 0X0);
            goto L_804A2150;
    }
    goto skip_1;
    // 0x804A2110: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    skip_1:
    // 0x804A2114: jal         0x800653D8
    // 0x804A2118: nop

    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x804A2118: nop

    after_1:
    // 0x804A211C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x804A2120: sw          $t8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r24;
    // 0x804A2124: jal         0x804A1D18
    // 0x804A2128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804A1D18(rdram, ctx);
        goto after_2;
    // 0x804A2128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804A212C: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A2130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A2134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A2138: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804A213C: jal         0x804A27A0
    // 0x804A2140: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    func_804A27A0(rdram, ctx);
        goto after_3;
    // 0x804A2140: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    after_3:
    // 0x804A2144: b           L_804A21A0
    // 0x804A2148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804A21A0;
    // 0x804A2148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804A214C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
L_804A2150:
    // 0x804A2150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A2154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A2158: bgezl       $t1, L_804A21A0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x804A215C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804A21A0;
    }
    goto skip_2;
    // 0x804A215C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x804A2160: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A2164: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x804A2168: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804A216C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x804A2170: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804A2174: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x804A2178: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x804A217C: nop

    // 0x804A2180: bc1fl       L_804A2194
    if (!c1cs) {
        // 0x804A2184: sw          $zero, 0x138($s0)
        MEM_W(0X138, ctx->r16) = 0;
            goto L_804A2194;
    }
    goto skip_3;
    // 0x804A2184: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    skip_3:
    // 0x804A2188: b           L_804A2194
    // 0x804A218C: sw          $t3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r11;
        goto L_804A2194;
    // 0x804A218C: sw          $t3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r11;
    // 0x804A2190: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
L_804A2194:
    // 0x804A2194: jal         0x804A27A0
    // 0x804A2198: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_804A27A0(rdram, ctx);
        goto after_4;
    // 0x804A2198: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x804A219C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804A21A0:
    // 0x804A21A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A21A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804A21A8: jr          $ra
    // 0x804A21AC: nop

    return;
    // 0x804A21AC: nop

;}
RECOMP_FUNC void func_806E5E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E5E54: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x806E5E58: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x806E5E5C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x806E5E60: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x806E5E64: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x806E5E68: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x806E5E6C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x806E5E70: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x806E5E74: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x806E5E78: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x806E5E7C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x806E5E80: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x806E5E84: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806E5E88: jal         0x8004700C
    // 0x806E5E8C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806E5E8C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x806E5E90: beq         $v0, $zero, L_806E5F74
    if (ctx->r2 == 0) {
        // 0x806E5E94: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_806E5F74;
    }
    // 0x806E5E94: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x806E5E98: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(655, 0X1090) << 16);
    // 0x806E5E9C: lwc1        $f24, 0x6D50($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(655, 0X1090));
    // 0x806E5EA0: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(655, 0X1094) << 16);
    // 0x806E5EA4: lwc1        $f22, 0x6D54($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(655, 0X1094));
    // 0x806E5EA8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x806E5EAC: lui         $s2, 0x806E
    ctx->r18 = S32(RELOC_HI16(655, 0X1010) << 16);
    // 0x806E5EB0: lui         $s3, 0x806E
    ctx->r19 = S32(RELOC_HI16(655, 0X1020) << 16);
    // 0x806E5EB4: lui         $s4, 0x806E
    ctx->r20 = S32(RELOC_HI16(655, 0X1050) << 16);
    // 0x806E5EB8: lui         $s5, 0x806E
    ctx->r21 = S32(RELOC_HI16(655, 0X1030) << 16);
    // 0x806E5EBC: lui         $s0, 0x806E
    ctx->r16 = S32(RELOC_HI16(655, 0X1040) << 16);
    // 0x806E5EC0: lui         $fp, 0x806E
    ctx->r30 = S32(RELOC_HI16(655, 0X1050) << 16);
    // 0x806E5EC4: lui         $s7, 0x800F
    ctx->r23 = S32(0X800F << 16);
    // 0x806E5EC8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806E5ECC: addiu       $s7, $s7, 0x7EA0
    ctx->r23 = ADD32(ctx->r23, 0X7EA0);
    // 0x806E5ED0: addiu       $fp, $fp, 0x6D10
    ctx->r30 = ADD32(ctx->r30, (int16_t)RELOC_LO16(655, 0X1050));
    // 0x806E5ED4: addiu       $s0, $s0, 0x6D00
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(655, 0X1040));
    // 0x806E5ED8: addiu       $s5, $s5, 0x6CF0
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(655, 0X1030));
    // 0x806E5EDC: addiu       $s4, $s4, 0x6D10
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(655, 0X1050));
    // 0x806E5EE0: addiu       $s3, $s3, 0x6CE0
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(655, 0X1020));
    // 0x806E5EE4: addiu       $s2, $s2, 0x6CD0
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(655, 0X1010));
    // 0x806E5EE8: addiu       $s6, $sp, 0x74
    ctx->r22 = ADD32(ctx->r29, 0X74);
L_806E5EEC:
    // 0x806E5EEC: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x806E5EF0: lwc1        $f6, 0x84($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806E5EF4: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x806E5EF8: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x806E5EFC: lw          $t6, 0xA68($s7)
    ctx->r14 = MEM_W(ctx->r23, 0XA68);
    // 0x806E5F00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806E5F04: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x806E5F08: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x806E5F0C: lwc1        $f16, 0x88($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X88);
    // 0x806E5F10: lwc1        $f8, 0x0($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
    // 0x806E5F14: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806E5F18: lwc1        $f16, 0x0($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X0);
    // 0x806E5F1C: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x806E5F20: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806E5F24: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x806E5F28: lwc1        $f6, 0x8C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8C);
    // 0x806E5F2C: swc1        $f8, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f8.u32l;
    // 0x806E5F30: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x806E5F34: swc1        $f22, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f22.u32l;
    // 0x806E5F38: swc1        $f24, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f24.u32l;
    // 0x806E5F3C: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x806E5F40: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x806E5F44: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x806E5F48: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    // 0x806E5F4C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806E5F50: lw          $t9, 0x28($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X28);
    // 0x806E5F54: jalr        $t9
    // 0x806E5F58: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x806E5F58: nop

    after_1:
    // 0x806E5F5C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806E5F60: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x806E5F64: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x806E5F68: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x806E5F6C: bne         $s0, $fp, L_806E5EEC
    if (ctx->r16 != ctx->r30) {
        // 0x806E5F70: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_806E5EEC;
    }
    // 0x806E5F70: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_806E5F74:
    // 0x806E5F74: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x806E5F78: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806E5F7C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806E5F80: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x806E5F84: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x806E5F88: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x806E5F8C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x806E5F90: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x806E5F94: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x806E5F98: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x806E5F9C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x806E5FA0: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x806E5FA4: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x806E5FA8: jr          $ra
    // 0x806E5FAC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x806E5FAC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_80068F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068F10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80068F14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068F18: jal         0x80068ED4
    // 0x80068F1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80068ED4(rdram, ctx);
        goto after_0;
    // 0x80068F1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80068F20: jal         0x80064BAC
    // 0x80068F24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_80064BAC(rdram, ctx);
        goto after_1;
    // 0x80068F24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80068F28: jal         0x800676F8
    // 0x80068F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800676F8(rdram, ctx);
        goto after_2;
    // 0x80068F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80068F30: jal         0x800653CC
    // 0x80068F34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800653CC(rdram, ctx);
        goto after_3;
    // 0x80068F34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80068F38: jal         0x80065408
    // 0x80068F3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80065408(rdram, ctx);
        goto after_4;
    // 0x80068F3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80068F40: jal         0x8006767C
    // 0x80068F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006767C(rdram, ctx);
        goto after_5;
    // 0x80068F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80068F48: jal         0x80064AD4
    // 0x80068F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80064AD4(rdram, ctx);
        goto after_6;
    // 0x80068F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80068F50: jal         0x80068418
    // 0x80068F54: nop

    func_80068418(rdram, ctx);
        goto after_7;
    // 0x80068F54: nop

    after_7:
    // 0x80068F58: jal         0x8006C95C
    // 0x80068F5C: addiu       $a0, $s0, 0x3F4
    ctx->r4 = ADD32(ctx->r16, 0X3F4);
    func_8006C95C(rdram, ctx);
        goto after_8;
    // 0x80068F5C: addiu       $a0, $s0, 0x3F4
    ctx->r4 = ADD32(ctx->r16, 0X3F4);
    after_8:
    // 0x80068F60: jal         0x80051C24
    // 0x80068F64: addiu       $a0, $s0, 0x634
    ctx->r4 = ADD32(ctx->r16, 0X634);
    func_80051C24(rdram, ctx);
        goto after_9;
    // 0x80068F64: addiu       $a0, $s0, 0x634
    ctx->r4 = ADD32(ctx->r16, 0X634);
    after_9:
    // 0x80068F68: jal         0x800505F0
    // 0x80068F6C: nop

    func_800505F0(rdram, ctx);
        goto after_10;
    // 0x80068F6C: nop

    after_10:
    // 0x80068F70: jal         0x8005AA68
    // 0x80068F74: addiu       $a0, $s0, 0x478
    ctx->r4 = ADD32(ctx->r16, 0X478);
    func_8005AA68(rdram, ctx);
        goto after_11;
    // 0x80068F74: addiu       $a0, $s0, 0x478
    ctx->r4 = ADD32(ctx->r16, 0X478);
    after_11:
    // 0x80068F78: jal         0x80044E38
    // 0x80068F7C: addiu       $a0, $s0, 0x958
    ctx->r4 = ADD32(ctx->r16, 0X958);
    func_80044E38(rdram, ctx);
        goto after_12;
    // 0x80068F7C: addiu       $a0, $s0, 0x958
    ctx->r4 = ADD32(ctx->r16, 0X958);
    after_12:
    // 0x80068F80: jal         0x8006DF14
    // 0x80068F84: addiu       $a0, $s0, 0x57C
    ctx->r4 = ADD32(ctx->r16, 0X57C);
    func_8006DF14(rdram, ctx);
        goto after_13;
    // 0x80068F84: addiu       $a0, $s0, 0x57C
    ctx->r4 = ADD32(ctx->r16, 0X57C);
    after_13:
    // 0x80068F88: jal         0x80058160
    // 0x80068F8C: addiu       $a0, $s0, 0xA68
    ctx->r4 = ADD32(ctx->r16, 0XA68);
    func_80058160(rdram, ctx);
        goto after_14;
    // 0x80068F8C: addiu       $a0, $s0, 0xA68
    ctx->r4 = ADD32(ctx->r16, 0XA68);
    after_14:
    // 0x80068F90: jal         0x8005D420
    // 0x80068F94: addiu       $a0, $s0, 0x8D0
    ctx->r4 = ADD32(ctx->r16, 0X8D0);
    func_8005D420(rdram, ctx);
        goto after_15;
    // 0x80068F94: addiu       $a0, $s0, 0x8D0
    ctx->r4 = ADD32(ctx->r16, 0X8D0);
    after_15:
    // 0x80068F98: jal         0x8005F930
    // 0x80068F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005F930(rdram, ctx);
        goto after_16;
    // 0x80068F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80068FA0: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80068FA4: addiu       $t6, $t6, -0x7A54
    ctx->r14 = ADD32(ctx->r14, -0X7A54);
    // 0x80068FA8: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x80068FAC: jal         0x800522B8
    // 0x80068FB0: addiu       $a0, $s0, 0xAA0
    ctx->r4 = ADD32(ctx->r16, 0XAA0);
    func_800522B8(rdram, ctx);
        goto after_17;
    // 0x80068FB0: addiu       $a0, $s0, 0xAA0
    ctx->r4 = ADD32(ctx->r16, 0XAA0);
    after_17:
    // 0x80068FB4: jal         0x8006D1C0
    // 0x80068FB8: nop

    func_8006D1C0(rdram, ctx);
        goto after_18;
    // 0x80068FB8: nop

    after_18:
    // 0x80068FBC: jal         0x80067B1C
    // 0x80068FC0: nop

    func_80067B1C(rdram, ctx);
        goto after_19;
    // 0x80068FC0: nop

    after_19:
    // 0x80068FC4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068FC8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068FCC: sw          $zero, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = 0;
    // 0x80068FD0: sw          $zero, 0x3F0($v0)
    MEM_W(0X3F0, ctx->r2) = 0;
    // 0x80068FD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80068FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80068FDC: jal         0x8006E0FC
    // 0x80068FE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8006E0FC(rdram, ctx);
        goto after_20;
    // 0x80068FE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80068FE4: jal         0x80068C74
    // 0x80068FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80068C74(rdram, ctx);
        goto after_21;
    // 0x80068FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80068FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068FF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068FF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80068FF8: jr          $ra
    // 0x80068FFC: nop

    return;
    // 0x80068FFC: nop

;}
RECOMP_FUNC void func_805369D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805369D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805369DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805369E0: jal         0x80536830
    // 0x805369E4: nop

    func_80536830(rdram, ctx);
        goto after_0;
    // 0x805369E4: nop

    after_0:
    // 0x805369E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805369EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805369F0: jr          $ra
    // 0x805369F4: nop

    return;
    // 0x805369F4: nop

;}
RECOMP_FUNC void func_8045B64C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B64C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045B650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045B654: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x8045B658: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(104, 0XD38) << 16);
    // 0x8045B65C: addiu       $t8, $t8, -0x48B8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(104, 0XD38));
    // 0x8045B660: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8045B664: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8045B668: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8045B66C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8045B670: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8045B674: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8045B678: beql        $v1, $zero, L_8045B6B0
    if (ctx->r3 == 0) {
        // 0x8045B67C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045B6B0;
    }
    goto skip_0;
    // 0x8045B67C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8045B680: jalr        $v1
    // 0x8045B684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8045B684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045B688: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045B68C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x8045B690: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x8045B694: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x8045B698: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8045B69C: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x8045B6A0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8045B6A4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8045B6A8: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x8045B6AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045B6B0:
    // 0x8045B6B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045B6B4: jr          $ra
    // 0x8045B6B8: nop

    return;
    // 0x8045B6B8: nop

    // 0x8045B6BC: nop

;}
RECOMP_FUNC void func_80046448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004644C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046450: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80046454: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80046458: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004645C: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80046460: sll         $t8, $t8, 7
    ctx->r24 = S32(ctx->r24 << 7);
    // 0x80046464: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    // 0x80046468: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8004646C: jal         0x800463B4
    // 0x80046470: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800463B4(rdram, ctx);
        goto after_0;
    // 0x80046470: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80046474: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80046478: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8004647C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80046480: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80046484: sb          $a1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r5;
    // 0x80046488: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8004648C: addiu       $v0, $a2, 0x4
    ctx->r2 = ADD32(ctx->r6, 0X4);
    // 0x80046490: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    // 0x80046494: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80046498: sb          $t0, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r8;
    // 0x8004649C: sh          $t1, 0x17E($v0)
    MEM_H(0X17E, ctx->r2) = ctx->r9;
    // 0x800464A0: sb          $a1, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r5;
    // 0x800464A4: sb          $a1, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r5;
    // 0x800464A8: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x800464AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800464B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800464B4: jr          $ra
    // 0x800464B8: nop

    return;
    // 0x800464B8: nop

;}
RECOMP_FUNC void func_807A1304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1304: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A1308: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A130C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A1310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A1314: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x807A1318: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807A131C: jal         0x807A0FFC
    // 0x807A1320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A0FFC(rdram, ctx);
        goto after_0;
    // 0x807A1320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x807A1324: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x807A1328: blez        $v0, L_807A1334
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807A132C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807A1334;
    }
    // 0x807A132C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807A1330: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_807A1334:
    // 0x807A1334: jal         0x807A10CC
    // 0x807A1338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A10CC(rdram, ctx);
        goto after_1;
    // 0x807A1338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807A133C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x807A1340: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807A1344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A1348: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807A134C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A1350: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x807A1354: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807A1358: nop

    // 0x807A135C: bc1fl       L_807A1370
    if (!c1cs) {
        // 0x807A1360: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807A1370;
    }
    goto skip_0;
    // 0x807A1360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807A1364: jal         0x807A1AE4
    // 0x807A1368: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    func_807A1AE4(rdram, ctx);
        goto after_2;
    // 0x807A1368: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    after_2:
    // 0x807A136C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A1370:
    // 0x807A1370: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A1374: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A1378: jr          $ra
    // 0x807A137C: nop

    return;
    // 0x807A137C: nop

;}
RECOMP_FUNC void func_80065E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E4C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80065E50: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80065E54: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80065E58: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80065E5C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80065E60: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80065E64: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80065E68: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80065E6C: bc1f        L_80065E78
    if (!c1cs) {
        // 0x80065E70: lwc1        $f8, 0x8($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
            goto L_80065E78;
    }
    // 0x80065E70: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80065E74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80065E78:
    // 0x80065E78: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80065E7C: lwc1        $f10, 0x8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80065E80: lwc1        $f16, 0xC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80065E84: bc1fl       L_80065E98
    if (!c1cs) {
        // 0x80065E88: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_80065E98;
    }
    goto skip_0;
    // 0x80065E88: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_0:
    // 0x80065E8C: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x80065E90: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80065E94: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_80065E98:
    // 0x80065E98: nop

    // 0x80065E9C: bc1fl       L_80065EB0
    if (!c1cs) {
        // 0x80065EA0: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80065EB0;
    }
    goto skip_1;
    // 0x80065EA0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_1:
    // 0x80065EA4: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x80065EA8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80065EAC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80065EB0:
    // 0x80065EB0: nop

    // 0x80065EB4: bc1fl       L_80065EC8
    if (!c1cs) {
        // 0x80065EB8: c.lt.s      $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
            goto L_80065EC8;
    }
    goto skip_2;
    // 0x80065EB8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    skip_2:
    // 0x80065EBC: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x80065EC0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80065EC4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
L_80065EC8:
    // 0x80065EC8: nop

    // 0x80065ECC: bc1fl       L_80065EE0
    if (!c1cs) {
        // 0x80065ED0: c.lt.s      $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
            goto L_80065EE0;
    }
    goto skip_3;
    // 0x80065ED0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    skip_3:
    // 0x80065ED4: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x80065ED8: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80065EDC: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
L_80065EE0:
    // 0x80065EE0: nop

    // 0x80065EE4: bc1fl       L_80065EF8
    if (!c1cs) {
        // 0x80065EE8: c.eq.s      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl == ctx->f12.fl;
            goto L_80065EF8;
    }
    goto skip_4;
    // 0x80065EE8: c.eq.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl == ctx->f12.fl;
    skip_4:
    // 0x80065EEC: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // 0x80065EF0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80065EF4: c.eq.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl == ctx->f12.fl;
L_80065EF8:
    // 0x80065EF8: nop

    // 0x80065EFC: bc1f        L_80065F28
    if (!c1cs) {
        // 0x80065F00: nop
    
            goto L_80065F28;
    }
    // 0x80065F00: nop

    // 0x80065F04: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    // 0x80065F08: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80065F0C: bc1f        L_80065F28
    if (!c1cs) {
        // 0x80065F10: nop
    
            goto L_80065F28;
    }
    // 0x80065F10: nop

    // 0x80065F14: c.eq.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl == ctx->f18.fl;
    // 0x80065F18: nop

    // 0x80065F1C: bc1f        L_80065F28
    if (!c1cs) {
        // 0x80065F20: nop
    
            goto L_80065F28;
    }
    // 0x80065F20: nop

    // 0x80065F24: addiu       $v1, $zero, 0x3F
    ctx->r3 = ADD32(0, 0X3F);
L_80065F28:
    // 0x80065F28: jr          $ra
    // 0x80065F2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80065F2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8002F2D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F2D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F2D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F2DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002F2E0: jal         0x8002F15C
    // 0x8002F2E4: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    func_8002F15C(rdram, ctx);
        goto after_0;
    // 0x8002F2E4: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    after_0:
    // 0x8002F2E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002F2EC: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x8002F2F0: jal         0x8001D78C
    // 0x8002F2F4: xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    func_8001D78C(rdram, ctx);
        goto after_1;
    // 0x8002F2F4: xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    after_1:
    // 0x8002F2F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002F2FC: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8002F300: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8002F304: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    // 0x8002F308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F30C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F310: jr          $ra
    // 0x8002F314: nop

    return;
    // 0x8002F314: nop

;}
RECOMP_FUNC void func_800518F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800518F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800518FC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80051900: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80051904: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051908: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005190C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80051910: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80051914: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80051918: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005191C: beq         $a1, $zero, L_8005198C
    if (ctx->r5 == 0) {
        // 0x80051920: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8005198C;
    }
    // 0x80051920: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80051924: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x80051928: addiu       $s3, $s3, 0xA7C
    ctx->r19 = ADD32(ctx->r19, 0XA7C);
    // 0x8005192C: addiu       $s4, $zero, 0xA5
    ctx->r20 = ADD32(0, 0XA5);
    // 0x80051930: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80051934:
    // 0x80051934: beql        $a0, $zero, L_8005197C
    if (ctx->r4 == 0) {
        // 0x80051938: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005197C;
    }
    goto skip_0;
    // 0x80051938: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8005193C: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x80051940: bnel        $t6, $zero, L_8005197C
    if (ctx->r14 != 0) {
        // 0x80051944: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005197C;
    }
    goto skip_1;
    // 0x80051944: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80051948: jal         0x800517A0
    // 0x8005194C: lhu         $a1, 0x3C($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X3C);
    func_800517A0(rdram, ctx);
        goto after_0;
    // 0x8005194C: lhu         $a1, 0x3C($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X3C);
    after_0:
    // 0x80051950: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80051954: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80051958: sw          $v0, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->r2;
    // 0x8005195C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80051960: lw          $t9, 0x44($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X44);
    // 0x80051964: bnel        $t9, $zero, L_80051978
    if (ctx->r25 != 0) {
        // 0x80051968: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_80051978;
    }
    goto skip_2;
    // 0x80051968: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_2:
    // 0x8005196C: jal         0x80071380
    // 0x80051970: addiu       $a1, $zero, 0x24C
    ctx->r5 = ADD32(0, 0X24C);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80051970: addiu       $a1, $zero, 0x24C
    ctx->r5 = ADD32(0, 0X24C);
    after_1:
    // 0x80051974: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80051978:
    // 0x80051978: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8005197C:
    // 0x8005197C: beq         $s2, $zero, L_8005198C
    if (ctx->r18 == 0) {
        // 0x80051980: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8005198C;
    }
    // 0x80051980: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80051984: bnel        $s1, $s4, L_80051934
    if (ctx->r17 != ctx->r20) {
        // 0x80051988: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80051934;
    }
    goto skip_3;
    // 0x80051988: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_8005198C:
    // 0x8005198C: beq         $s2, $zero, L_800519A0
    if (ctx->r18 == 0) {
        // 0x80051990: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800519A0;
    }
    // 0x80051990: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80051994: addiu       $a0, $a0, 0xA8C
    ctx->r4 = ADD32(ctx->r4, 0XA8C);
    // 0x80051998: jal         0x80071380
    // 0x8005199C: addiu       $a1, $zero, 0x25F
    ctx->r5 = ADD32(0, 0X25F);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8005199C: addiu       $a1, $zero, 0x25F
    ctx->r5 = ADD32(0, 0X25F);
    after_2:
L_800519A0:
    // 0x800519A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800519A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800519A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800519AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800519B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800519B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800519B8: jr          $ra
    // 0x800519BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800519BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800744B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800744B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800744B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800744B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800744BC: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x800744C0: lw          $t6, -0x7B30($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B30);
    // 0x800744C4: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x800744C8: bnel        $at, $zero, L_800744DC
    if (ctx->r1 != 0) {
        // 0x800744CC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800744DC;
    }
    goto skip_0;
    // 0x800744CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x800744D0: jal         0x80086880
    // 0x800744D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_0;
    // 0x800744D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800744D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_800744DC:
    // 0x800744DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800744E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800744E4: jal         0x800824B0
    // 0x800744E8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800744E8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
    // 0x800744EC: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x800744F0: lw          $t7, -0x7B30($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7B30);
    // 0x800744F4: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x800744F8: bnel        $at, $zero, L_8007450C
    if (ctx->r1 != 0) {
        // 0x800744FC: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_8007450C;
    }
    goto skip_1;
    // 0x800744FC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80074500: jal         0x80086880
    // 0x80074504: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_2;
    // 0x80074504: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80074508: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8007450C:
    // 0x8007450C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074510: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80074514: jr          $ra
    // 0x80074518: nop

    return;
    // 0x80074518: nop

;}
RECOMP_FUNC void func_80036B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036B50: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80036B54: lwc1        $f6, -0x7678($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7678);
    // 0x80036B58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036B5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036B60: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80036B64: nop

    // 0x80036B68: bc1t        L_80036B78
    if (c1cs) {
        // 0x80036B6C: nop
    
            goto L_80036B78;
    }
    // 0x80036B6C: nop

    // 0x80036B70: jr          $ra
    // 0x80036B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80036B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036B78:
    // 0x80036B78: jr          $ra
    // 0x80036B7C: nop

    return;
    // 0x80036B7C: nop

;}
RECOMP_FUNC void func_804A2910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A2910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A2914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A2918: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804A291C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804A2920: beql        $t6, $zero, L_804A2960
    if (ctx->r14 == 0) {
        // 0x804A2924: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A2960;
    }
    goto skip_0;
    // 0x804A2924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A2928: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804A292C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804A2930: jalr        $t9
    // 0x804A2934: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804A2934: nop

    after_0:
    // 0x804A2938: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A293C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x804A2940: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804A2944: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804A2948: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804A294C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804A2950: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804A2954: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804A2958: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x804A295C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A2960:
    // 0x804A2960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A2964: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x804A2968: jr          $ra
    // 0x804A296C: nop

    return;
    // 0x804A296C: nop

;}
RECOMP_FUNC void func_80433E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433E8C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80433E90: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80433E94: lw          $a2, -0x7CE8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CE8);
    // 0x80433E98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80433E9C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80433EA0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80433EA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80433EA8: lwc1        $f6, 0x38($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X38);
    // 0x80433EAC: lwc1        $f2, 0xC4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80433EB0: lwc1        $f14, 0xC8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80433EB4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80433EB8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80433EBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80433EC0: addiu       $v0, $a1, 0x7AC
    ctx->r2 = ADD32(ctx->r5, 0X7AC);
    // 0x80433EC4: addiu       $v1, $a1, 0xB6C
    ctx->r3 = ADD32(ctx->r5, 0XB6C);
    // 0x80433EC8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80433ECC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80433ED0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80433ED4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80433ED8: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80433EDC: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80433EE0: jal         0x80081C64
    // 0x80433EE4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80433EE4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80433EE8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80433EEC: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80433EF0: lw          $a1, 0x3F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X3F4);
    // 0x80433EF4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80433EF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80433EFC: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80433F00: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80433F04: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80433F08: div.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80433F0C: lw          $t6, 0x478($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X478);
    // 0x80433F10: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80433F14: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80433F18: lwc1        $f8, 0xAC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XAC);
    // 0x80433F1C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80433F20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80433F24: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80433F28: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80433F2C: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80433F30: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80433F34: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80433F38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80433F3C: nop

    // 0x80433F40: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80433F44: jal         0x80081C64
    // 0x80433F48: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x80433F48: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80433F4C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80433F50: lw          $a1, -0x7D6C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D6C);
    // 0x80433F54: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80433F58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80433F5C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80433F60: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80433F64: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80433F68: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80433F6C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80433F70: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80433F74: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80433F78: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80433F7C: lwc1        $f6, 0xB0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XB0);
    // 0x80433F80: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80433F84: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80433F88: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80433F8C: addiu       $a0, $zero, 0x77
    ctx->r4 = ADD32(0, 0X77);
    // 0x80433F90: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80433F94: lwc1        $f8, 0x30($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X30);
    // 0x80433F98: div.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80433F9C: swc1        $f8, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f8.u32l;
    // 0x80433FA0: lwc1        $f10, 0x34($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X34);
    // 0x80433FA4: swc1        $f10, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f10.u32l;
    // 0x80433FA8: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80433FAC: nop

L_80433FB0:
    // 0x80433FB0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80433FB4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80433FB8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80433FBC: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80433FC0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80433FC4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80433FC8: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80433FCC: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80433FD0: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80433FD4: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80433FD8: lwc1        $f4, -0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80433FDC: add.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80433FE0: sub.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x80433FE4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80433FE8: bgez        $a0, L_80433FB0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80433FEC: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80433FB0;
    }
    // 0x80433FEC: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80433FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80433FF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80433FF8: jr          $ra
    // 0x80433FFC: nop

    return;
    // 0x80433FFC: nop

;}
RECOMP_FUNC void func_804D8F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8F20: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804D8F24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804D8F28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804D8F2C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x804D8F30: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804D8F34: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804D8F38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804D8F3C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x804D8F40: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x804D8F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804D8F48: jal         0x8004921C
    // 0x804D8F4C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804D8F4C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    after_0:
    // 0x804D8F50: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x804D8F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804D8F58: jal         0x8004921C
    // 0x804D8F5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804D8F5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804D8F60: lbu         $t0, 0x2B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2B);
    // 0x804D8F64: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x804D8F68: lbu         $t2, 0x145($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X145);
    // 0x804D8F6C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804D8F70: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x804D8F74: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x804D8F78: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x804D8F7C: lw          $t4, 0x80($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X80);
    // 0x804D8F80: lw          $a2, 0x88($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X88);
    // 0x804D8F84: mflo        $t1
    ctx->r9 = lo;
    // 0x804D8F88: nop

    // 0x804D8F8C: nop

    // 0x804D8F90: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804D8F94: mflo        $t3
    ctx->r11 = lo;
    // 0x804D8F98: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x804D8F9C: jal         0x80062E30
    // 0x804D8FA0: nop

    func_80062E30(rdram, ctx);
        goto after_2;
    // 0x804D8FA0: nop

    after_2:
    // 0x804D8FA4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x804D8FA8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x804D8FAC: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x804D8FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804D8FB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804D8FB8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x804D8FBC: jr          $ra
    // 0x804D8FC0: nop

    return;
    // 0x804D8FC0: nop

;}
RECOMP_FUNC void func_80448350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448350: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80448354: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80448358: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044835C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448360: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80448364: bne         $a2, $zero, L_804483A0
    if (ctx->r6 != 0) {
        // 0x80448368: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804483A0;
    }
    // 0x80448368: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044836C: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x80448370: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80448374: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80448378: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x8044837C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80448380: bne         $at, $zero, L_804483E0
    if (ctx->r1 != 0) {
        // 0x80448384: sw          $t7, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r15;
            goto L_804483E0;
    }
    // 0x80448384: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x80448388: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044838C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448390: jal         0x804464B4
    // 0x80448394: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    func_804464B4(rdram, ctx);
        goto after_0;
    // 0x80448394: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    after_0:
    // 0x80448398: b           L_804483E4
    // 0x8044839C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804483E4;
    // 0x8044839C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804483A0:
    // 0x804483A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804483A4: bnel        $a2, $at, L_804483D0
    if (ctx->r6 != ctx->r1) {
        // 0x804483A8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804483D0;
    }
    goto skip_0;
    // 0x804483A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x804483AC: jal         0x804464B4
    // 0x804483B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804464B4(rdram, ctx);
        goto after_1;
    // 0x804483B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804483B4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804483B8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804483BC: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x804483C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804483C4: b           L_804483E0
    // 0x804483C8: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_804483E0;
    // 0x804483C8: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x804483CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_804483D0:
    // 0x804483D0: bnel        $a2, $at, L_804483E4
    if (ctx->r6 != ctx->r1) {
        // 0x804483D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804483E4;
    }
    goto skip_1;
    // 0x804483D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804483D8: jal         0x80446518
    // 0x804483DC: nop

    func_80446518(rdram, ctx);
        goto after_2;
    // 0x804483DC: nop

    after_2:
L_804483E0:
    // 0x804483E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804483E4:
    // 0x804483E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804483E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804483EC: jr          $ra
    // 0x804483F0: nop

    return;
    // 0x804483F0: nop

;}
RECOMP_FUNC void func_80467F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80467F28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80467F2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80467F30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80467F34: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x80467F38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80467F3C: jal         0x80467610
    // 0x80467F40: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    func_80467610(rdram, ctx);
        goto after_0;
    // 0x80467F40: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    after_0:
    // 0x80467F44: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80467F48: lh          $t8, 0x1A($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X1A);
    // 0x80467F4C: lh          $t9, 0x18($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X18);
    // 0x80467F50: lw          $t4, 0x1FA0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X1FA0);
    // 0x80467F54: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x80467F58: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467F5C: addiu       $a2, $t2, 0x18
    ctx->r6 = ADD32(ctx->r10, 0X18);
    // 0x80467F60: lw          $t7, 0x168($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X168);
    // 0x80467F64: addiu       $a3, $t2, 0x2C70
    ctx->r7 = ADD32(ctx->r10, 0X2C70);
    // 0x80467F68: lw          $a0, 0x88($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X88);
    // 0x80467F6C: mflo        $t3
    ctx->r11 = lo;
    // 0x80467F70: nop

    // 0x80467F74: nop

    // 0x80467F78: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467F7C: mflo        $t5
    ctx->r13 = lo;
    // 0x80467F80: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    // 0x80467F84: jal         0x80055D6C
    // 0x80467F88: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    func_80055D6C(rdram, ctx);
        goto after_1;
    // 0x80467F88: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_1:
    // 0x80467F8C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80467F90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80467F94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80467F98: lw          $t1, 0x2C6C($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X2C6C);
    // 0x80467F9C: lbu         $a3, 0x1B($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X1B);
    // 0x80467FA0: addiu       $a0, $t2, 0x2A78
    ctx->r4 = ADD32(ctx->r10, 0X2A78);
    // 0x80467FA4: blezl       $t1, L_80467FE8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80467FA8: sb          $a3, 0x2CF0($t2)
        MEM_B(0X2CF0, ctx->r10) = ctx->r7;
            goto L_80467FE8;
    }
    goto skip_0;
    // 0x80467FA8: sb          $a3, 0x2CF0($t2)
    MEM_B(0X2CF0, ctx->r10) = ctx->r7;
    skip_0:
L_80467FAC:
    // 0x80467FAC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80467FB0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80467FB4: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80467FB8: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80467FBC: beq         $at, $zero, L_80467FC8
    if (ctx->r1 == 0) {
        // 0x80467FC0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80467FC8;
    }
    // 0x80467FC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80467FC4: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_80467FC8:
    // 0x80467FC8: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80467FCC: beq         $at, $zero, L_80467FD8
    if (ctx->r1 == 0) {
        // 0x80467FD0: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_80467FD8;
    }
    // 0x80467FD0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80467FD4: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
L_80467FD8:
    // 0x80467FD8: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80467FDC: bne         $at, $zero, L_80467FAC
    if (ctx->r1 != 0) {
        // 0x80467FE0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80467FAC;
    }
    // 0x80467FE0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80467FE4: sb          $a3, 0x2CF0($t2)
    MEM_B(0X2CF0, ctx->r10) = ctx->r7;
L_80467FE8:
    // 0x80467FE8: sb          $t0, 0x2CF1($t2)
    MEM_B(0X2CF1, ctx->r10) = ctx->r8;
    // 0x80467FEC: jal         0x80467EB0
    // 0x80467FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80467EB0(rdram, ctx);
        goto after_2;
    // 0x80467FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80467FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80467FF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80467FFC: jal         0x804686B4
    // 0x80468000: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_804686B4(rdram, ctx);
        goto after_3;
    // 0x80468000: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_3:
    // 0x80468004: jal         0x80466950
    // 0x80468008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80466950(rdram, ctx);
        goto after_4;
    // 0x80468008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8046800C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80468010: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80468014: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80468018: jr          $ra
    // 0x8046801C: nop

    return;
    // 0x8046801C: nop

;}
RECOMP_FUNC void func_8005A4AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A4AC: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8005A4B0: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x8005A4B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A4B8: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8005A4BC: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8005A4C0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8005A4C4: nop

    // 0x8005A4C8: bc1t        L_8005A4D4
    if (c1cs) {
        // 0x8005A4CC: nop
    
            goto L_8005A4D4;
    }
    // 0x8005A4CC: nop

    // 0x8005A4D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A4D4:
    // 0x8005A4D4: bne         $v0, $zero, L_8005A524
    if (ctx->r2 != 0) {
        // 0x8005A4D8: nop
    
            goto L_8005A524;
    }
    // 0x8005A4D8: nop

    // 0x8005A4DC: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8005A4E0: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8005A4E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A4E8: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8005A4EC: nop

    // 0x8005A4F0: bc1t        L_8005A4FC
    if (c1cs) {
        // 0x8005A4F4: nop
    
            goto L_8005A4FC;
    }
    // 0x8005A4F4: nop

    // 0x8005A4F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A4FC:
    // 0x8005A4FC: bne         $v0, $zero, L_8005A524
    if (ctx->r2 != 0) {
        // 0x8005A500: nop
    
            goto L_8005A524;
    }
    // 0x8005A500: nop

    // 0x8005A504: lwc1        $f16, 0x44($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8005A508: lwc1        $f18, 0x38($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X38);
    // 0x8005A50C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A510: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8005A514: nop

    // 0x8005A518: bc1t        L_8005A524
    if (c1cs) {
        // 0x8005A51C: nop
    
            goto L_8005A524;
    }
    // 0x8005A51C: nop

    // 0x8005A520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A524:
    // 0x8005A524: jr          $ra
    // 0x8005A528: nop

    return;
    // 0x8005A528: nop

;}
RECOMP_FUNC void func_800247E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800247E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800247E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800247EC: jal         0x80024668
    // 0x800247F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024668(rdram, ctx);
        goto after_0;
    // 0x800247F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800247F4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800247F8: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x800247FC: addiu       $t6, $t6, 0x4748
    ctx->r14 = ADD32(ctx->r14, 0X4748);
    // 0x80024800: sw          $t6, 0x160($t7)
    MEM_W(0X160, ctx->r15) = ctx->r14;
    // 0x80024804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024808: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002480C: jr          $ra
    // 0x80024810: nop

    return;
    // 0x80024810: nop

;}
RECOMP_FUNC void func_805CACCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CACCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CACD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805CACD4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x805CACD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CACDC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x805CACE0: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(453, 0X71C) << 16);
    // 0x805CACE4: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x805CACE8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805CACEC: lw          $t7, -0x5094($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(453, 0X71C));
    // 0x805CACF0: jal         0x805CA8A0
    // 0x805CACF4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    func_805CA8A0(rdram, ctx);
        goto after_0;
    // 0x805CACF4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    after_0:
    // 0x805CACF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CACFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805CAD00: jr          $ra
    // 0x805CAD04: nop

    return;
    // 0x805CAD04: nop

;}
RECOMP_FUNC void func_8003E520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E520: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8003E524: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8003E528: beq         $v0, $at, L_8003E540
    if (ctx->r2 == ctx->r1) {
        // 0x8003E52C: addiu       $at, $zero, 0x4144
        ctx->r1 = ADD32(0, 0X4144);
            goto L_8003E540;
    }
    // 0x8003E52C: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x8003E530: beq         $v0, $at, L_8003E548
    if (ctx->r2 == ctx->r1) {
        // 0x8003E534: nop
    
            goto L_8003E548;
    }
    // 0x8003E534: nop

    // 0x8003E538: b           L_8003E550
    // 0x8003E53C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003E550;
    // 0x8003E53C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003E540:
    // 0x8003E540: jr          $ra
    // 0x8003E544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8003E544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003E548:
    // 0x8003E548: jr          $ra
    // 0x8003E54C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8003E54C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003E550:
    // 0x8003E550: jr          $ra
    // 0x8003E554: nop

    return;
    // 0x8003E554: nop

;}
RECOMP_FUNC void func_80454CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454CD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80454CD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80454CD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80454CDC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454CE0: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80454CE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80454CE8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454CEC: lw          $t6, 0x6A28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A28);
    // 0x80454CF0: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x80454CF4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80454CF8: bne         $t6, $at, L_80454D24
    if (ctx->r14 != ctx->r1) {
        // 0x80454CFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80454D24;
    }
    // 0x80454CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80454D00: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80454D04: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80454D08: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80454D0C: jal         0x8044EDC4
    // 0x80454D10: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8044EDC4(rdram, ctx);
        goto after_0;
    // 0x80454D10: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80454D14: jal         0x80446D70
    // 0x80454D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80446D70(rdram, ctx);
        goto after_1;
    // 0x80454D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80454D1C: b           L_80454D34
    // 0x80454D20: nop

        goto L_80454D34;
    // 0x80454D20: nop

L_80454D24:
    // 0x80454D24: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454D28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80454D2C: jal         0x804536E4
    // 0x80454D30: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    func_804536E4(rdram, ctx);
        goto after_2;
    // 0x80454D30: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    after_2:
L_80454D34:
    // 0x80454D34: jal         0x80454664
    // 0x80454D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80454664(rdram, ctx);
        goto after_3;
    // 0x80454D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80454D3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80454D40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80454D44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80454D48: jr          $ra
    // 0x80454D4C: nop

    return;
    // 0x80454D4C: nop

;}
RECOMP_FUNC void func_8042EC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EC7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042EC80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042EC84: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8042EC88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8042EC8C: beq         $t6, $zero, L_8042ECC8
    if (ctx->r14 == 0) {
        // 0x8042EC90: nop
    
            goto L_8042ECC8;
    }
    // 0x8042EC90: nop

    // 0x8042EC94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042EC98: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8042EC9C: jalr        $t9
    // 0x8042ECA0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042ECA0: nop

    after_0:
    // 0x8042ECA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042ECA8: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8042ECAC: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8042ECB0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8042ECB4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8042ECB8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8042ECBC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8042ECC0: b           L_8042ECC8
    // 0x8042ECC4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8042ECC8;
    // 0x8042ECC4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8042ECC8:
    // 0x8042ECC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042ECCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042ECD0: jr          $ra
    // 0x8042ECD4: nop

    return;
    // 0x8042ECD4: nop

;}
RECOMP_FUNC void func_804A40B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A40B8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804A40BC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x804A40C0: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x804A40C4: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x804A40C8: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x804A40CC: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x804A40D0: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804A40D4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804A40D8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804A40DC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804A40E0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804A40E4: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804A40E8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804A40EC: lwc1        $f26, 0x3C($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A40F0: addiu       $s0, $v0, 0x188
    ctx->r16 = ADD32(ctx->r2, 0X188);
    // 0x804A40F4: lwc1        $f28, 0x40($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A40F8: bne         $s0, $zero, L_804A4108
    if (ctx->r16 != 0) {
        // 0x804A40FC: lh          $s1, 0x184($v0)
        ctx->r17 = MEM_H(ctx->r2, 0X184);
            goto L_804A4108;
    }
    // 0x804A40FC: lh          $s1, 0x184($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X184);
    // 0x804A4100: b           L_804A41B4
    // 0x804A4104: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_804A41B4;
    // 0x804A4104: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_804A4108:
    // 0x804A4108: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A410C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x804A4110: beq         $s1, $zero, L_804A4190
    if (ctx->r17 == 0) {
        // 0x804A4114: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_804A4190;
    }
    // 0x804A4114: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_804A4118:
    // 0x804A4118: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804A411C: beq         $v0, $zero, L_804A4188
    if (ctx->r2 == 0) {
        // 0x804A4120: nop
    
            goto L_804A4188;
    }
    // 0x804A4120: nop

    // 0x804A4124: lwc1        $f14, 0x3C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A4128: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x804A412C: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x804A4130: c.lt.s      $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f14.fl < ctx->f26.fl;
    // 0x804A4134: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804A4138: lwc1        $f20, 0x40($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A413C: bc1t        L_804A4154
    if (c1cs) {
        // 0x804A4140: nop
    
            goto L_804A4154;
    }
    // 0x804A4140: nop

    // 0x804A4144: c.lt.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl < ctx->f20.fl;
    // 0x804A4148: nop

    // 0x804A414C: bc1f        L_804A4188
    if (!c1cs) {
        // 0x804A4150: nop
    
            goto L_804A4188;
    }
    // 0x804A4150: nop

L_804A4154:
    // 0x804A4154: jal         0x804A3C08
    // 0x804A4158: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_804A3C08(rdram, ctx);
        goto after_0;
    // 0x804A4158: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_0:
    // 0x804A415C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x804A4160: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x804A4164: jal         0x804A3C08
    // 0x804A4168: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_804A3C08(rdram, ctx);
        goto after_1;
    // 0x804A4168: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x804A416C: add.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x804A4170: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x804A4174: nop

    // 0x804A4178: bc1f        L_804A4188
    if (!c1cs) {
        // 0x804A417C: nop
    
            goto L_804A4188;
    }
    // 0x804A417C: nop

    // 0x804A4180: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x804A4184: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_804A4188:
    // 0x804A4188: bne         $s1, $zero, L_804A4118
    if (ctx->r17 != 0) {
        // 0x804A418C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_804A4118;
    }
    // 0x804A418C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_804A4190:
    // 0x804A4190: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A4194: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A4198: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x804A419C: c.le.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl <= ctx->f24.fl;
    // 0x804A41A0: nop

    // 0x804A41A4: bc1f        L_804A41B4
    if (!c1cs) {
        // 0x804A41A8: nop
    
            goto L_804A41B4;
    }
    // 0x804A41A8: nop

    // 0x804A41AC: b           L_804A41B4
    // 0x804A41B0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_804A41B4;
    // 0x804A41B0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_804A41B4:
    // 0x804A41B4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x804A41B8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804A41BC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804A41C0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804A41C4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804A41C8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x804A41CC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x804A41D0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x804A41D4: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x804A41D8: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x804A41DC: jr          $ra
    // 0x804A41E0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x804A41E0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8043D9A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D9A4: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(92, 0X8D4) << 16);
    // 0x8043D9A8: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8043D9AC: andi        $v1, $zero, 0xFF
    ctx->r3 = 0 & 0XFF;
    // 0x8043D9B0: addiu       $t7, $t7, -0x26EC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(92, 0X8D4));
    // 0x8043D9B4: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8043D9B8: sw          $v1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r3;
    // 0x8043D9BC: sw          $v1, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r3;
    // 0x8043D9C0: sb          $zero, 0x158($a0)
    MEM_B(0X158, ctx->r4) = 0;
    // 0x8043D9C4: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    // 0x8043D9C8: jr          $ra
    // 0x8043D9CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8043D9CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8057F5FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F5FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057F600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F604: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057F608: lw          $t6, 0x60($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X60);
    // 0x8057F60C: beql        $t6, $zero, L_8057F638
    if (ctx->r14 == 0) {
        // 0x8057F610: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057F638;
    }
    goto skip_0;
    // 0x8057F610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8057F614: jal         0x8057EFC4
    // 0x8057F618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8057EFC4(rdram, ctx);
        goto after_0;
    // 0x8057F618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057F61C: jal         0x8057F0F4
    // 0x8057F620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8057F0F4(rdram, ctx);
        goto after_1;
    // 0x8057F620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8057F624: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8057F628: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057F62C: jal         0x8057F680
    // 0x8057F630: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8057F680(rdram, ctx);
        goto after_2;
    // 0x8057F630: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8057F634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057F638:
    // 0x8057F638: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057F63C: jr          $ra
    // 0x8057F640: nop

    return;
    // 0x8057F640: nop

;}
RECOMP_FUNC void func_80019040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019048: jal         0x80019AC4
    // 0x8001904C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x8001904C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80019050: beq         $v0, $zero, L_80019094
    if (ctx->r2 == 0) {
        // 0x80019054: addiu       $t6, $zero, 0x13
        ctx->r14 = ADD32(0, 0X13);
            goto L_80019094;
    }
    // 0x80019054: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x80019058: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001905C: lh          $t7, 0x1A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1A);
    // 0x80019060: jal         0x8001AF80
    // 0x80019064: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
    func_8001AF80(rdram, ctx);
        goto after_1;
    // 0x80019064: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
    after_1:
    // 0x80019068: jal         0x80019F90
    // 0x8001906C: nop

    func_80019F90(rdram, ctx);
        goto after_2;
    // 0x8001906C: nop

    after_2:
    // 0x80019070: lui         $a0, 0x8300
    ctx->r4 = S32(0X8300 << 16);
    // 0x80019074: jal         0x8000A364
    // 0x80019078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000A364(rdram, ctx);
        goto after_3;
    // 0x80019078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8001907C: lui         $a0, 0x8301
    ctx->r4 = S32(0X8301 << 16);
    // 0x80019080: jal         0x8000A364
    // 0x80019084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000A364(rdram, ctx);
        goto after_4;
    // 0x80019084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80019088: lui         $a0, 0x8302
    ctx->r4 = S32(0X8302 << 16);
    // 0x8001908C: jal         0x8000A364
    // 0x80019090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000A364(rdram, ctx);
        goto after_5;
    // 0x80019090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_80019094:
    // 0x80019094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001909C: jr          $ra
    // 0x800190A0: nop

    return;
    // 0x800190A0: nop

;}
RECOMP_FUNC void func_804BEF30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BEF30: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x804BEF34: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x804BEF38: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x804BEF3C: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x804BEF40: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x804BEF44: jr          $ra
    // 0x804BEF48: swc1        $f8, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x804BEF48: swc1        $f8, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void gfxprint_close(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FA7C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007FA80: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8007FA84: jr          $ra
    // 0x8007FA88: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    return;
    // 0x8007FA88: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80434634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80434638: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8043463C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80434640: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80434644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80434648: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8043464C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80434650: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80434654: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80434658: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8043465C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80434660: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80434664: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(71, 0X2958) << 16);
    // 0x80434668: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8043466C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80434670: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80434674: lw          $t2, 0x6408($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(71, 0X2958));
    // 0x80434678: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8043467C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80434680: jal         0x80433B7C
    // 0x80434684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80433B7C(rdram, ctx);
        goto after_0;
    // 0x80434684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80434688: jal         0x80433B04
    // 0x8043468C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80433B04(rdram, ctx);
        goto after_1;
    // 0x8043468C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80434690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80434694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80434698: jr          $ra
    // 0x8043469C: nop

    return;
    // 0x8043469C: nop

;}
RECOMP_FUNC void func_80049C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049C70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80049C74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80049C78: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80049C7C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80049C80: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80049C84: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80049C88: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80049C8C: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80049C90: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x80049C94: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80049C98: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80049C9C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80049CA0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80049CA4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80049CA8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80049CAC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80049CB0: jal         0x80049864
    // 0x80049CB4: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    func_80049864(rdram, ctx);
        goto after_0;
    // 0x80049CB4: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    after_0:
    // 0x80049CB8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80049CBC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80049CC0: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80049CC4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80049CC8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80049CCC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80049CD0: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x80049CD4: lwc1        $f6, 0x4($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80049CD8: addiu       $t9, $t6, 0xC
    ctx->r25 = ADD32(ctx->r14, 0XC);
    // 0x80049CDC: addu        $t0, $t5, $t8
    ctx->r8 = ADD32(ctx->r13, ctx->r24);
    // 0x80049CE0: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80049CE4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80049CE8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80049CEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80049CF0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80049CF4: jal         0x800534C0
    // 0x80049CF8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_800534C0(rdram, ctx);
        goto after_1;
    // 0x80049CF8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80049CFC: sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // 0x80049D00: lbu         $t2, 0x22($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X22);
    // 0x80049D04: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80049D08: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80049D0C: andi        $t3, $t2, 0xF8
    ctx->r11 = ctx->r10 & 0XF8;
    // 0x80049D10: bne         $t3, $at, L_80049D1C
    if (ctx->r11 != ctx->r1) {
        // 0x80049D14: andi        $t7, $v0, 0x7FF
        ctx->r15 = ctx->r2 & 0X7FF;
            goto L_80049D1C;
    }
    // 0x80049D14: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x80049D18: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
L_80049D1C:
    // 0x80049D1C: lhu         $t5, 0x22($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X22);
    // 0x80049D20: jal         0x80049C54
    // 0x80049D24: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    func_80049C54(rdram, ctx);
        goto after_2;
    // 0x80049D24: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    after_2:
    // 0x80049D28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80049D2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80049D30: jr          $ra
    // 0x80049D34: nop

    return;
    // 0x80049D34: nop

;}
RECOMP_FUNC void func_80048548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048548: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004854C: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80048550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80048554: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80048558: nop

    // 0x8004855C: bc1t        L_80048568
    if (c1cs) {
        // 0x80048560: nop
    
            goto L_80048568;
    }
    // 0x80048560: nop

    // 0x80048564: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80048568:
    // 0x80048568: bne         $v0, $zero, L_800485B0
    if (ctx->r2 != 0) {
        // 0x8004856C: nop
    
            goto L_800485B0;
    }
    // 0x8004856C: nop

    // 0x80048570: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80048574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80048578: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8004857C: nop

    // 0x80048580: bc1t        L_8004858C
    if (c1cs) {
        // 0x80048584: nop
    
            goto L_8004858C;
    }
    // 0x80048584: nop

    // 0x80048588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004858C:
    // 0x8004858C: bne         $v0, $zero, L_800485B0
    if (ctx->r2 != 0) {
        // 0x80048590: nop
    
            goto L_800485B0;
    }
    // 0x80048590: nop

    // 0x80048594: lwc1        $f8, 0xCC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x80048598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004859C: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x800485A0: nop

    // 0x800485A4: bc1t        L_800485B0
    if (c1cs) {
        // 0x800485A8: nop
    
            goto L_800485B0;
    }
    // 0x800485A8: nop

    // 0x800485AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800485B0:
    // 0x800485B0: jr          $ra
    // 0x800485B4: nop

    return;
    // 0x800485B4: nop

;}
RECOMP_FUNC void func_80031FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031FD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031FE0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031FE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80031FE8: jal         0x800310A0
    // 0x80031FEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031FEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031FF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031FF4: jal         0x800310D0
    // 0x80031FF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800310D0(rdram, ctx);
        goto after_1;
    // 0x80031FF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80031FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032000: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032004: jr          $ra
    // 0x80032008: nop

    return;
    // 0x80032008: nop

;}
RECOMP_FUNC void func_8043F1A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F1A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F1A4: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x8043F1A8: lh          $v1, 0x144($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X144);
    // 0x8043F1AC: lwc1        $f0, 0x1C88($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C88);
    // 0x8043F1B0: beq         $t6, $zero, L_8043F1CC
    if (ctx->r14 == 0) {
        // 0x8043F1B4: lwc1        $f2, 0x1C8C($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X1C8C);
            goto L_8043F1CC;
    }
    // 0x8043F1B4: lwc1        $f2, 0x1C8C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C8C);
    // 0x8043F1B8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8043F1BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8043F1C0: nop

    // 0x8043F1C4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8043F1C8: nop

L_8043F1CC:
    // 0x8043F1CC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8043F1D0: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8043F1D4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8043F1D8: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8043F1DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8043F1E0: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8043F1E4: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(95, 0X3E14) << 16);
    // 0x8043F1E8: addiu       $t8, $t8, 0x2D14
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(95, 0X3E14));
    // 0x8043F1EC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8043F1F0: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    // 0x8043F1F4: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8043F1F8: addiu       $a2, $zero, 0x1BF0
    ctx->r6 = ADD32(0, 0X1BF0);
    // 0x8043F1FC: addiu       $a3, $v0, 0x1BF0
    ctx->r7 = ADD32(ctx->r2, 0X1BF0);
L_8043F200:
    // 0x8043F200: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8043F204: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x8043F208: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8043F20C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8043F210: addiu       $a2, $a2, -0x30
    ctx->r6 = ADD32(ctx->r6, -0X30);
    // 0x8043F214: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8043F218: swc1        $f8, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f8.u32l;
    // 0x8043F21C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8043F220: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8043F224: bgez        $a0, L_8043F230
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8043F228: swc1        $f16, 0x30($a3)
        MEM_W(0X30, ctx->r7) = ctx->f16.u32l;
            goto L_8043F230;
    }
    // 0x8043F228: swc1        $f16, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->f16.u32l;
    // 0x8043F22C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
L_8043F230:
    // 0x8043F230: bgez        $a2, L_8043F200
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8043F234: addiu       $a3, $a3, -0x30
        ctx->r7 = ADD32(ctx->r7, -0X30);
            goto L_8043F200;
    }
    // 0x8043F234: addiu       $a3, $a3, -0x30
    ctx->r7 = ADD32(ctx->r7, -0X30);
    // 0x8043F238: jr          $ra
    // 0x8043F23C: nop

    return;
    // 0x8043F23C: nop

;}
RECOMP_FUNC void func_8073DD60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073DD60: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8073DD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073DD68: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8073DD6C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8073DD70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8073DD74: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8073DD78: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8073DD7C: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8073DD80: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8073DD84: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8073DD88: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8073DD8C: jal         0x8004700C
    // 0x8073DD90: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8073DD90: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8073DD94: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8073DD98: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8073DD9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073DDA0: lw          $a3, 0x1F4($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X1F4);
    // 0x8073DDA4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x8073DDA8: jal         0x80048F84
    // 0x8073DDAC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8073DDAC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x8073DDB0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1470) << 16);
    // 0x8073DDB4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8073DDB8: lwc1        $f12, -0x19C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1470));
    // 0x8073DDBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8073DDC0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8073DDC4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8073DDC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8073DDCC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8073DDD0: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_8073DDD4:
    // 0x8073DDD4: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8073DDD8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8073DDDC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8073DDE0: nop

    // 0x8073DDE4: bc1fl       L_8073DE14
    if (!c1cs) {
        // 0x8073DDE8: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8073DE14;
    }
    goto skip_0;
    // 0x8073DDE8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x8073DDEC: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8073DDF0: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8073DDF4: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8073DDF8: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x8073DDFC: nop

    // 0x8073DE00: bc1f        L_8073DE40
    if (!c1cs) {
        // 0x8073DE04: nop
    
            goto L_8073DE40;
    }
    // 0x8073DE04: nop

    // 0x8073DE08: b           L_8073DE40
    // 0x8073DE0C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
        goto L_8073DE40;
    // 0x8073DE0C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x8073DE10: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8073DE14:
    // 0x8073DE14: nop

    // 0x8073DE18: bc1f        L_8073DE40
    if (!c1cs) {
        // 0x8073DE1C: nop
    
            goto L_8073DE40;
    }
    // 0x8073DE1C: nop

    // 0x8073DE20: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8073DE24: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x8073DE28: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8073DE2C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8073DE30: nop

    // 0x8073DE34: bc1f        L_8073DE40
    if (!c1cs) {
        // 0x8073DE38: nop
    
            goto L_8073DE40;
    }
    // 0x8073DE38: nop

    // 0x8073DE3C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_8073DE40:
    // 0x8073DE40: bne         $a0, $v0, L_8073DDD4
    if (ctx->r4 != ctx->r2) {
        // 0x8073DE44: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8073DDD4;
    }
    // 0x8073DE44: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8073DE48: lw          $v0, 0x34($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X34);
    // 0x8073DE4C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8073DE50: beq         $v0, $zero, L_8073DE60
    if (ctx->r2 == 0) {
        // 0x8073DE54: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8073DE60;
    }
    // 0x8073DE54: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8073DE58: b           L_8073DF40
    // 0x8073DE5C: sw          $t6, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r14;
        goto L_8073DF40;
    // 0x8073DE5C: sw          $t6, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r14;
L_8073DE60:
    // 0x8073DE60: beq         $t7, $zero, L_8073DE80
    if (ctx->r15 == 0) {
        // 0x8073DE64: lwc1        $f10, 0x34($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8073DE80;
    }
    // 0x8073DE64: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8073DE68: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8073DE6C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8073DE70: jal         0x80047AB8
    // 0x8073DE74: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x8073DE74: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x8073DE78: b           L_8073DE8C
    // 0x8073DE7C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
        goto L_8073DE8C;
    // 0x8073DE7C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
L_8073DE80:
    // 0x8073DE80: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8073DE84: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8073DE88: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
L_8073DE8C:
    // 0x8073DE8C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8073DE90: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8073DE94: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8073DE98: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8073DE9C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073DEA0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8073DEA4: sub.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8073DEA8: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x8073DEAC: jal         0x80067114
    // 0x8073DEB0: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    func_80067114(rdram, ctx);
        goto after_3;
    // 0x8073DEB0: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x8073DEB4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8073DEB8: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8073DEBC: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8073DEC0: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8073DEC4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8073DEC8: beql        $t8, $zero, L_8073DF44
    if (ctx->r24 == 0) {
        // 0x8073DECC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073DF44;
    }
    goto skip_1;
    // 0x8073DECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8073DED0: jal         0x80065954
    // 0x8073DED4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x8073DED4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_4:
    // 0x8073DED8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8073DEDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8073DEE0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8073DEE4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8073DEE8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8073DEEC: nop

    // 0x8073DEF0: bc1fl       L_8073DF30
    if (!c1cs) {
        // 0x8073DEF4: lw          $t9, 0x28($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X28);
            goto L_8073DF30;
    }
    goto skip_2;
    // 0x8073DEF4: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    skip_2:
    // 0x8073DEF8: jal         0x80065954
    // 0x8073DEFC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80065954(rdram, ctx);
        goto after_5;
    // 0x8073DEFC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_5:
    // 0x8073DF00: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8073DF04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8073DF08: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8073DF0C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8073DF10: nop

    // 0x8073DF14: bc1fl       L_8073DF30
    if (!c1cs) {
        // 0x8073DF18: lw          $t9, 0x28($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X28);
            goto L_8073DF30;
    }
    goto skip_3;
    // 0x8073DF18: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
    skip_3:
    // 0x8073DF1C: jal         0x8073DC90
    // 0x8073DF20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8073DC90(rdram, ctx);
        goto after_6;
    // 0x8073DF20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x8073DF24: b           L_8073DF44
    // 0x8073DF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8073DF44;
    // 0x8073DF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073DF2C: lw          $t9, 0x28($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X28);
L_8073DF30:
    // 0x8073DF30: beql        $t9, $zero, L_8073DF44
    if (ctx->r25 == 0) {
        // 0x8073DF34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073DF44;
    }
    goto skip_4;
    // 0x8073DF34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8073DF38: jal         0x8073DC90
    // 0x8073DF3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8073DC90(rdram, ctx);
        goto after_7;
    // 0x8073DF3C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_7:
L_8073DF40:
    // 0x8073DF40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8073DF44:
    // 0x8073DF44: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8073DF48: jr          $ra
    // 0x8073DF4C: nop

    return;
    // 0x8073DF4C: nop

;}
RECOMP_FUNC void func_805ADE44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADE44: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADE48: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADE4C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADE50: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADE54: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADE58: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADE5C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADE60: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADE64: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADE68: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADE6C: jr          $ra
    // 0x805ADE70: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADE70: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80454C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454C44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80454C48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80454C4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80454C50: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X13904) << 16);
    // 0x80454C54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80454C58: jal         0x804548E4
    // 0x80454C5C: lw          $a1, 0x7CE4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13904));
    func_804548E4(rdram, ctx);
        goto after_0;
    // 0x80454C5C: lw          $a1, 0x7CE4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13904));
    after_0:
    // 0x80454C60: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80454C64: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454C68: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80454C6C: addu        $a0, $v1, $at
    ctx->r4 = ADD32(ctx->r3, ctx->r1);
    // 0x80454C70: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454C74: ori         $at, $at, 0x6D3C
    ctx->r1 = ctx->r1 | 0X6D3C;
    // 0x80454C78: addu        $a1, $v1, $at
    ctx->r5 = ADD32(ctx->r3, ctx->r1);
    // 0x80454C7C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454C80: ori         $at, $at, 0x6D40
    ctx->r1 = ctx->r1 | 0X6D40;
    // 0x80454C84: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80454C88: addu        $a2, $v1, $at
    ctx->r6 = ADD32(ctx->r3, ctx->r1);
    // 0x80454C8C: jal         0x804549D4
    // 0x80454C90: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804549D4(rdram, ctx);
        goto after_1;
    // 0x80454C90: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80454C94: beq         $v0, $zero, L_80454CBC
    if (ctx->r2 == 0) {
        // 0x80454C98: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80454CBC;
    }
    // 0x80454C98: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80454C9C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454CA0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80454CA4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80454CA8: sw          $t6, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r14;
    // 0x80454CAC: jal         0x804457C0
    // 0x80454CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804457C0(rdram, ctx);
        goto after_2;
    // 0x80454CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80454CB4: jal         0x8045352C
    // 0x80454CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8045352C(rdram, ctx);
        goto after_3;
    // 0x80454CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80454CBC:
    // 0x80454CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80454CC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80454CC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80454CC8: jr          $ra
    // 0x80454CCC: nop

    return;
    // 0x80454CCC: nop

;}
RECOMP_FUNC void func_80676C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676C00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80676C04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80676C08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80676C0C: jal         0x80676B74
    // 0x80676C10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80676B74(rdram, ctx);
        goto after_0;
    // 0x80676C10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80676C14: beq         $v0, $zero, L_80676C2C
    if (ctx->r2 == 0) {
        // 0x80676C18: nop
    
            goto L_80676C2C;
    }
    // 0x80676C18: nop

    // 0x80676C1C: jal         0x800447C8
    // 0x80676C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80676C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80676C24: b           L_80676C58
    // 0x80676C28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80676C58;
    // 0x80676C28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80676C2C:
    // 0x80676C2C: jal         0x80676B18
    // 0x80676C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80676B18(rdram, ctx);
        goto after_2;
    // 0x80676C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80676C34: jal         0x806763F4
    // 0x80676C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806763F4(rdram, ctx);
        goto after_3;
    // 0x80676C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80676C3C: jal         0x80676640
    // 0x80676C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80676640(rdram, ctx);
        goto after_4;
    // 0x80676C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80676C44: jal         0x80676A08
    // 0x80676C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80676A08(rdram, ctx);
        goto after_5;
    // 0x80676C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80676C4C: jal         0x8067641C
    // 0x80676C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067641C(rdram, ctx);
        goto after_6;
    // 0x80676C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80676C54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80676C58:
    // 0x80676C58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80676C5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80676C60: jr          $ra
    // 0x80676C64: nop

    return;
    // 0x80676C64: nop

;}
RECOMP_FUNC void func_80790BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80790BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80790BD8: jal         0x8004700C
    // 0x80790BDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80790BDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80790BE0: beq         $v0, $zero, L_80790C20
    if (ctx->r2 == 0) {
        // 0x80790BE4: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80790C20;
    }
    // 0x80790BE4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80790BE8: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80790BEC: lwc1        $f6, 0x84($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X84);
    // 0x80790BF0: jal         0x80065954
    // 0x80790BF4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80790BF4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x80790BF8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80790BFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80790C00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80790C04: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80790C08: nop

    // 0x80790C0C: bc1fl       L_80790C28
    if (!c1cs) {
        // 0x80790C10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80790C28;
    }
    goto skip_0;
    // 0x80790C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80790C14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80790C18: b           L_80790C28
    // 0x80790C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80790C28;
    // 0x80790C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80790C20:
    // 0x80790C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80790C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80790C28:
    // 0x80790C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80790C2C: jr          $ra
    // 0x80790C30: nop

    return;
    // 0x80790C30: nop

;}
RECOMP_FUNC void func_804C605C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C605C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C6060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C6064: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C6068: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x804C606C: bnel        $t6, $zero, L_804C6094
    if (ctx->r14 != 0) {
        // 0x804C6070: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_804C6094;
    }
    goto skip_0;
    // 0x804C6070: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x804C6074: jal         0x80045A34
    // 0x804C6078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804C6078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C607C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C6080: bne         $v0, $zero, L_804C6090
    if (ctx->r2 != 0) {
        // 0x804C6084: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804C6090;
    }
    // 0x804C6084: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804C6088: b           L_804C6094
    // 0x804C608C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C6094;
    // 0x804C608C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C6090:
    // 0x804C6090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804C6094:
    // 0x804C6094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C6098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C609C: jr          $ra
    // 0x804C60A0: nop

    return;
    // 0x804C60A0: nop

;}
RECOMP_FUNC void func_807B8EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8EE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B8EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B8EF0: jal         0x80047090
    // 0x807B8EF4: addiu       $a0, $zero, 0x4710
    ctx->r4 = ADD32(0, 0X4710);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807B8EF4: addiu       $a0, $zero, 0x4710
    ctx->r4 = ADD32(0, 0X4710);
    after_0:
    // 0x807B8EF8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807B8EFC: bne         $v0, $at, L_807B8F0C
    if (ctx->r2 != ctx->r1) {
        // 0x807B8F00: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_807B8F0C;
    }
    // 0x807B8F00: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x807B8F04: b           L_807B8F5C
    // 0x807B8F08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B8F5C;
    // 0x807B8F08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B8F0C:
    // 0x807B8F0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B8F10: lui         $at, 0x4710
    ctx->r1 = S32(0X4710 << 16);
    // 0x807B8F14: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807B8F18: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807B8F1C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807B8F20: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x807B8F24: or          $a0, $t0, $at
    ctx->r4 = ctx->r8 | ctx->r1;
    // 0x807B8F28: jal         0x8004613C
    // 0x807B8F2C: sh          $t0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r8;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807B8F2C: sh          $t0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r8;
    after_1:
    // 0x807B8F30: lhu         $t0, 0x1A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X1A);
    // 0x807B8F34: bne         $v0, $zero, L_807B8F44
    if (ctx->r2 != 0) {
        // 0x807B8F38: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_807B8F44;
    }
    // 0x807B8F38: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x807B8F3C: b           L_807B8F5C
    // 0x807B8F40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B8F5C;
    // 0x807B8F40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B8F44:
    // 0x807B8F44: lhu         $t8, 0xE($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XE);
    // 0x807B8F48: andi        $t7, $t0, 0x3FF
    ctx->r15 = ctx->r8 & 0X3FF;
    // 0x807B8F4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x807B8F50: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x807B8F54: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x807B8F58: sh          $t1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r9;
L_807B8F5C:
    // 0x807B8F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B8F60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B8F64: jr          $ra
    // 0x807B8F68: nop

    return;
    // 0x807B8F68: nop

;}
RECOMP_FUNC void func_806FD768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD76C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD770: jal         0x806FD700
    // 0x806FD774: nop

    func_806FD700(rdram, ctx);
        goto after_0;
    // 0x806FD774: nop

    after_0:
    // 0x806FD778: bne         $v0, $zero, L_806FD788
    if (ctx->r2 != 0) {
        // 0x806FD77C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806FD788;
    }
    // 0x806FD77C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FD780: b           L_806FD7A8
    // 0x806FD784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806FD7A8;
    // 0x806FD784: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806FD788:
    // 0x806FD788: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x806FD78C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806FD790: lhu         $t8, 0x10($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X10);
    // 0x806FD794: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x806FD798: beq         $t9, $zero, L_806FD7A8
    if (ctx->r25 == 0) {
        // 0x806FD79C: nop
    
            goto L_806FD7A8;
    }
    // 0x806FD79C: nop

    // 0x806FD7A0: b           L_806FD7A8
    // 0x806FD7A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806FD7A8;
    // 0x806FD7A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806FD7A8:
    // 0x806FD7A8: jr          $ra
    // 0x806FD7AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806FD7AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80027D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027D2C: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x80027D30: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80027D34: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80027D38: xori        $v0, $v0, 0x19
    ctx->r2 = ctx->r2 ^ 0X19;
    // 0x80027D3C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80027D40: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80027D44: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80027D48: lw          $t7, -0x3A18($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3A18);
    // 0x80027D4C: addiu       $t8, $t8, 0x7CDC
    ctx->r24 = ADD32(ctx->r24, 0X7CDC);
    // 0x80027D50: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    // 0x80027D54: jr          $ra
    // 0x80027D58: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
    return;
    // 0x80027D58: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800364DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800364DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800364E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800364E4: jal         0x80021958
    // 0x800364E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x800364E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800364EC: bne         $v0, $zero, L_800364FC
    if (ctx->r2 != 0) {
        // 0x800364F0: nop
    
            goto L_800364FC;
    }
    // 0x800364F0: nop

    // 0x800364F4: b           L_80036530
    // 0x800364F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036530;
    // 0x800364F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800364FC:
    // 0x800364FC: jal         0x800415FC
    // 0x80036500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80036500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80036504: beq         $v0, $zero, L_80036514
    if (ctx->r2 == 0) {
        // 0x80036508: nop
    
            goto L_80036514;
    }
    // 0x80036508: nop

    // 0x8003650C: b           L_80036530
    // 0x80036510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036530;
    // 0x80036510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036514:
    // 0x80036514: jal         0x80035E28
    // 0x80036518: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80035E28(rdram, ctx);
        goto after_2;
    // 0x80036518: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8003651C: bnel        $v0, $zero, L_80036530
    if (ctx->r2 != 0) {
        // 0x80036520: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80036530;
    }
    goto skip_0;
    // 0x80036520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80036524: b           L_80036530
    // 0x80036528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036530;
    // 0x80036528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003652C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036530:
    // 0x80036530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036538: jr          $ra
    // 0x8003653C: nop

    return;
    // 0x8003653C: nop

;}
RECOMP_FUNC void func_8041FA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041FA20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8041FA24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041FA28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8041FA2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8041FA30: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8041FA34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041FA38: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8041FA3C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041FA40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041FA44: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8041FA48: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x8041FA4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8041FA50: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8041FA54: jal         0x8041E9A8
    // 0x8041FA58: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_8041E9A8(rdram, ctx);
        goto after_0;
    // 0x8041FA58: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8041FA5C: beq         $v0, $zero, L_8041FB00
    if (ctx->r2 == 0) {
        // 0x8041FA60: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_8041FB00;
    }
    // 0x8041FA60: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8041FA64: beq         $v1, $zero, L_8041FACC
    if (ctx->r3 == 0) {
        // 0x8041FA68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8041FACC;
    }
    // 0x8041FA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041FA6C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X352C) << 16);
    // 0x8041FA70: lwc1        $f10, 0xB8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X352C));
    // 0x8041FA74: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8041FA78: lwc1        $f0, 0x40($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8041FA7C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3530) << 16);
    // 0x8041FA80: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8041FA84: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8041FA88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041FA8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041FA90: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x8041FA94: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8041FA98: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x8041FA9C: lwc1        $f6, 0xB90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3530));
    // 0x8041FAA0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8041FAA4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8041FAA8: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8041FAAC: nop

    // 0x8041FAB0: bc1f        L_8041FAE4
    if (!c1cs) {
        // 0x8041FAB4: nop
    
            goto L_8041FAE4;
    }
    // 0x8041FAB4: nop

    // 0x8041FAB8: sh          $t6, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r14;
    // 0x8041FABC: jal         0x8041FE10
    // 0x8041FAC0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_1;
    // 0x8041FAC0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_1:
    // 0x8041FAC4: b           L_8041FAE4
    // 0x8041FAC8: nop

        goto L_8041FAE4;
    // 0x8041FAC8: nop

L_8041FACC:
    // 0x8041FACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041FAD0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8041FAD4: jal         0x8041FE10
    // 0x8041FAD8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_2;
    // 0x8041FAD8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8041FADC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8041FAE0: sh          $t7, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r15;
L_8041FAE4:
    // 0x8041FAE4: jal         0x8041F594
    // 0x8041FAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041F594(rdram, ctx);
        goto after_3;
    // 0x8041FAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8041FAEC: jal         0x8041E5E8
    // 0x8041FAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_4;
    // 0x8041FAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8041FAF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041FAF8: jal         0x8041E430
    // 0x8041FAFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E430(rdram, ctx);
        goto after_5;
    // 0x8041FAFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
L_8041FB00:
    // 0x8041FB00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041FB04: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8041FB08: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8041FB0C: jr          $ra
    // 0x8041FB10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8041FB10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8073C988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073C988: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8073C98C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8073C990: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8073C994: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8073C998: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8073C99C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8073C9A0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8073C9A4: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(742, 0XF90) << 16);
    // 0x8073C9A8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8073C9AC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8073C9B0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8073C9B4: lw          $t1, -0x2F10($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(742, 0XF90));
    // 0x8073C9B8: jr          $ra
    // 0x8073C9BC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8073C9BC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80522344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80522348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052234C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80522350: addiu       $at, $zero, 0x4147
    ctx->r1 = ADD32(0, 0X4147);
    // 0x80522354: beq         $v0, $at, L_8052237C
    if (ctx->r2 == ctx->r1) {
        // 0x80522358: addiu       $at, $zero, 0x414A
        ctx->r1 = ADD32(0, 0X414A);
            goto L_8052237C;
    }
    // 0x80522358: addiu       $at, $zero, 0x414A
    ctx->r1 = ADD32(0, 0X414A);
    // 0x8052235C: beq         $v0, $at, L_8052238C
    if (ctx->r2 == ctx->r1) {
        // 0x80522360: addiu       $at, $zero, 0x414B
        ctx->r1 = ADD32(0, 0X414B);
            goto L_8052238C;
    }
    // 0x80522360: addiu       $at, $zero, 0x414B
    ctx->r1 = ADD32(0, 0X414B);
    // 0x80522364: beq         $v0, $at, L_8052239C
    if (ctx->r2 == ctx->r1) {
        // 0x80522368: addiu       $at, $zero, 0x4719
        ctx->r1 = ADD32(0, 0X4719);
            goto L_8052239C;
    }
    // 0x80522368: addiu       $at, $zero, 0x4719
    ctx->r1 = ADD32(0, 0X4719);
    // 0x8052236C: beq         $v0, $at, L_805223AC
    if (ctx->r2 == ctx->r1) {
        // 0x80522370: nop
    
            goto L_805223AC;
    }
    // 0x80522370: nop

    // 0x80522374: b           L_805223B8
    // 0x80522378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805223B8;
    // 0x80522378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052237C:
    // 0x8052237C: jal         0x80523294
    // 0x80522380: nop

    func_80523294(rdram, ctx);
        goto after_0;
    // 0x80522380: nop

    after_0:
    // 0x80522384: b           L_805223B8
    // 0x80522388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805223B8;
    // 0x80522388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052238C:
    // 0x8052238C: jal         0x805233E4
    // 0x80522390: nop

    func_805233E4(rdram, ctx);
        goto after_1;
    // 0x80522390: nop

    after_1:
    // 0x80522394: b           L_805223B8
    // 0x80522398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805223B8;
    // 0x80522398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052239C:
    // 0x8052239C: jal         0x80523560
    // 0x805223A0: nop

    func_80523560(rdram, ctx);
        goto after_2;
    // 0x805223A0: nop

    after_2:
    // 0x805223A4: b           L_805223B8
    // 0x805223A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805223B8;
    // 0x805223A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805223AC:
    // 0x805223AC: jal         0x805236D4
    // 0x805223B0: nop

    func_805236D4(rdram, ctx);
        goto after_3;
    // 0x805223B0: nop

    after_3:
    // 0x805223B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805223B8:
    // 0x805223B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805223BC: jr          $ra
    // 0x805223C0: nop

    return;
    // 0x805223C0: nop

;}
RECOMP_FUNC void func_8044B214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B214: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044B218: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13514) << 16);
    // 0x8044B21C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B220: addiu       $t6, $t6, 0x78F4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13514));
    // 0x8044B224: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044B228: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044B22C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044B230: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044B234: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044B238: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B23C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044B240: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044B244: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044B248: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044B24C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044B250: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044B254: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B258: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044B25C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044B260: jal         0x80050A50
    // 0x8044B264: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044B264: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044B268: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044B26C: jalr        $v0
    // 0x8044B270: sw          $v0, 0x6A70($v1)
    MEM_W(0X6A70, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044B270: sw          $v0, 0x6A70($v1)
    MEM_W(0X6A70, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044B274: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B278: sw          $v0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r2;
    // 0x8044B27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B280: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044B284: jr          $ra
    // 0x8044B288: nop

    return;
    // 0x8044B288: nop

;}
RECOMP_FUNC void func_8005B8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B8D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005B8D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005B8DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005B8E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8005B8E4: bne         $a0, $zero, L_8005B8F4
    if (ctx->r4 != 0) {
        // 0x8005B8E8: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_8005B8F4;
    }
    // 0x8005B8E8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8005B8EC: b           L_8005B930
    // 0x8005B8F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005B930;
    // 0x8005B8F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005B8F4:
    // 0x8005B8F4: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x8005B8F8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8005B8FC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8005B900: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8005B904: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8005B908: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8005B90C: lw          $t9, 0x618C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X618C);
    // 0x8005B910: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8005B914: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B918: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8005B91C: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x8005B920: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005B924: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8005B928: jalr        $t9
    // 0x8005B92C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005B92C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
L_8005B930:
    // 0x8005B930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005B934: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005B938: jr          $ra
    // 0x8005B93C: nop

    return;
    // 0x8005B93C: nop

;}
RECOMP_FUNC void func_80033C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033C28: jal         0x80021B44
    // 0x80033C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021B44(rdram, ctx);
        goto after_0;
    // 0x80033C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80033C30: bne         $v0, $zero, L_80033C40
    if (ctx->r2 != 0) {
        // 0x80033C34: nop
    
            goto L_80033C40;
    }
    // 0x80033C34: nop

    // 0x80033C38: b           L_80033C8C
    // 0x80033C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033C8C;
    // 0x80033C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033C40:
    // 0x80033C40: jal         0x80033494
    // 0x80033C44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033494(rdram, ctx);
        goto after_1;
    // 0x80033C44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80033C48: bne         $v0, $zero, L_80033C58
    if (ctx->r2 != 0) {
        // 0x80033C4C: nop
    
            goto L_80033C58;
    }
    // 0x80033C4C: nop

    // 0x80033C50: b           L_80033C8C
    // 0x80033C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033C8C;
    // 0x80033C54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033C58:
    // 0x80033C58: jal         0x80033160
    // 0x80033C5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033160(rdram, ctx);
        goto after_2;
    // 0x80033C5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80033C60: beq         $v0, $zero, L_80033C70
    if (ctx->r2 == 0) {
        // 0x80033C64: nop
    
            goto L_80033C70;
    }
    // 0x80033C64: nop

    // 0x80033C68: b           L_80033C8C
    // 0x80033C6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033C8C;
    // 0x80033C6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033C70:
    // 0x80033C70: jal         0x800336A8
    // 0x80033C74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800336A8(rdram, ctx);
        goto after_3;
    // 0x80033C74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80033C78: bnel        $v0, $zero, L_80033C8C
    if (ctx->r2 != 0) {
        // 0x80033C7C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80033C8C;
    }
    goto skip_0;
    // 0x80033C7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80033C80: b           L_80033C8C
    // 0x80033C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033C8C;
    // 0x80033C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80033C88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80033C8C:
    // 0x80033C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033C94: jr          $ra
    // 0x80033C98: nop

    return;
    // 0x80033C98: nop

;}
RECOMP_FUNC void func_80435BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435BB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80435BBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80435BC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80435BC4: jal         0x80435B50
    // 0x80435BC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80435B50(rdram, ctx);
        goto after_0;
    // 0x80435BC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80435BCC: jal         0x8043535C
    // 0x80435BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043535C(rdram, ctx);
        goto after_1;
    // 0x80435BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80435BD4: jal         0x80435328
    // 0x80435BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80435328(rdram, ctx);
        goto after_2;
    // 0x80435BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80435BDC: jal         0x80435470
    // 0x80435BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80435470(rdram, ctx);
        goto after_3;
    // 0x80435BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80435BE4: jal         0x804355DC
    // 0x80435BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804355DC(rdram, ctx);
        goto after_4;
    // 0x80435BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80435BEC: jal         0x804357E4
    // 0x80435BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804357E4(rdram, ctx);
        goto after_5;
    // 0x80435BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80435BF4: jal         0x804358AC
    // 0x80435BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804358AC(rdram, ctx);
        goto after_6;
    // 0x80435BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80435BFC: jal         0x80435868
    // 0x80435C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80435868(rdram, ctx);
        goto after_7;
    // 0x80435C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80435C04: beq         $v0, $zero, L_80435C1C
    if (ctx->r2 == 0) {
        // 0x80435C08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80435C1C;
    }
    // 0x80435C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435C0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80435C10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80435C14: jal         0x80436234
    // 0x80435C18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80436234(rdram, ctx);
        goto after_8;
    // 0x80435C18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
L_80435C1C:
    // 0x80435C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80435C20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80435C24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80435C28: jr          $ra
    // 0x80435C2C: nop

    return;
    // 0x80435C2C: nop

;}
RECOMP_FUNC void func_80067838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067838: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006783C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067840: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067844: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067848: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006784C: jal         0x800677CC
    // 0x80067850: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    func_800677CC(rdram, ctx);
        goto after_0;
    // 0x80067850: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    after_0:
    // 0x80067854: beq         $v0, $zero, L_80067868
    if (ctx->r2 == 0) {
        // 0x80067858: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80067868;
    }
    // 0x80067858: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006785C: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x80067860: jal         0x80015E74
    // 0x80067864: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_80015E74(rdram, ctx);
        goto after_1;
    // 0x80067864: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80067868:
    // 0x80067868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006786C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067870: jr          $ra
    // 0x80067874: nop

    return;
    // 0x80067874: nop

;}
RECOMP_FUNC void func_806AA490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA490: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806AA494: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x806AA498: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x806AA49C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x806AA4A0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x806AA4A4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x806AA4A8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x806AA4AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x806AA4B0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x806AA4B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806AA4B8: jal         0x806AA2C8
    // 0x806AA4BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_806AA2C8(rdram, ctx);
        goto after_0;
    // 0x806AA4BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x806AA4C0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x806AA4C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AA4C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806AA4CC: jal         0x806AA784
    // 0x806AA4D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806AA4D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806AA4D4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x806AA4D8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x806AA4DC: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x806AA4E0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_806AA4E4:
    // 0x806AA4E4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x806AA4E8: addiu       $a1, $zero, 0x4598
    ctx->r5 = ADD32(0, 0X4598);
    // 0x806AA4EC: jal         0x806AA3FC
    // 0x806AA4F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_806AA3FC(rdram, ctx);
        goto after_2;
    // 0x806AA4F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x806AA4F4: beq         $s3, $s5, L_806AA514
    if (ctx->r19 == ctx->r21) {
        // 0x806AA4F8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_806AA514;
    }
    // 0x806AA4F8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x806AA4FC: jal         0x8005FDC4
    // 0x806AA500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x806AA500: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x806AA504: jal         0x806AA590
    // 0x806AA508: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_806AA590(rdram, ctx);
        goto after_4;
    // 0x806AA508: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x806AA50C: b           L_806AA520
    // 0x806AA510: lw          $v0, 0x1F4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1F4);
        goto L_806AA520;
    // 0x806AA510: lw          $v0, 0x1F4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1F4);
L_806AA514:
    // 0x806AA514: jal         0x806AA6DC
    // 0x806AA518: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_806AA6DC(rdram, ctx);
        goto after_5;
    // 0x806AA518: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x806AA51C: lw          $v0, 0x1F4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1F4);
L_806AA520:
    // 0x806AA520: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x806AA524: blez        $s4, L_806AA544
    if (SIGNED(ctx->r20) <= 0) {
        // 0x806AA528: sh          $s3, 0x8($v0)
        MEM_H(0X8, ctx->r2) = ctx->r19;
            goto L_806AA544;
    }
    // 0x806AA528: sh          $s3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r19;
L_806AA52C:
    // 0x806AA52C: jal         0x806A99EC
    // 0x806AA530: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_806A99EC(rdram, ctx);
        goto after_6;
    // 0x806AA530: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x806AA534: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806AA538: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x806AA53C: bne         $at, $zero, L_806AA52C
    if (ctx->r1 != 0) {
        // 0x806AA540: nop
    
            goto L_806AA52C;
    }
    // 0x806AA540: nop

L_806AA544:
    // 0x806AA544: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x806AA548: bne         $s3, $s6, L_806AA4E4
    if (ctx->r19 != ctx->r22) {
        // 0x806AA54C: addiu       $s4, $s4, 0x14
        ctx->r20 = ADD32(ctx->r20, 0X14);
            goto L_806AA4E4;
    }
    // 0x806AA54C: addiu       $s4, $s4, 0x14
    ctx->r20 = ADD32(ctx->r20, 0X14);
    // 0x806AA550: lw          $t6, 0x168($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X168);
    // 0x806AA554: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x806AA558: lw          $a1, 0x88($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X88);
    // 0x806AA55C: jal         0x8004590C
    // 0x806AA560: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    func_8004590C(rdram, ctx);
        goto after_7;
    // 0x806AA560: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    after_7:
    // 0x806AA564: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x806AA568: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806AA56C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806AA570: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x806AA574: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x806AA578: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x806AA57C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x806AA580: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x806AA584: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x806AA588: jr          $ra
    // 0x806AA58C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x806AA58C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800398CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800398CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800398D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800398D4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x800398D8: beq         $v0, $zero, L_80039900
    if (ctx->r2 == 0) {
        // 0x800398DC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80039900;
    }
    // 0x800398DC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800398E0: bne         $t6, $zero, L_8003990C
    if (ctx->r14 != 0) {
        // 0x800398E4: sw          $t6, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r14;
            goto L_8003990C;
    }
    // 0x800398E4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x800398E8: jal         0x800447C8
    // 0x800398EC: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x800398EC: nop

    after_0:
    // 0x800398F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800398F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800398F8: b           L_80039914
    // 0x800398FC: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
        goto L_80039914;
    // 0x800398FC: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
L_80039900:
    // 0x80039900: jal         0x80039828
    // 0x80039904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80039828(rdram, ctx);
        goto after_1;
    // 0x80039904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80039908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8003990C:
    // 0x8003990C: jal         0x80038FEC
    // 0x80039910: nop

    func_80038FEC(rdram, ctx);
        goto after_2;
    // 0x80039910: nop

    after_2:
L_80039914:
    // 0x80039914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003991C: jr          $ra
    // 0x80039920: nop

    return;
    // 0x80039920: nop

;}
RECOMP_FUNC void func_804B97A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B97A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B97A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B97A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B97AC: jal         0x80045A34
    // 0x804B97B0: addiu       $a1, $zero, 0x7A8
    ctx->r5 = ADD32(0, 0X7A8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804B97B0: addiu       $a1, $zero, 0x7A8
    ctx->r5 = ADD32(0, 0X7A8);
    after_0:
    // 0x804B97B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B97B8: bne         $v0, $zero, L_804B97C8
    if (ctx->r2 != 0) {
        // 0x804B97BC: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804B97C8;
    }
    // 0x804B97BC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804B97C0: b           L_804B97D4
    // 0x804B97C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804B97D4;
    // 0x804B97C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804B97C8:
    // 0x804B97C8: jal         0x804B9750
    // 0x804B97CC: nop

    func_804B9750(rdram, ctx);
        goto after_1;
    // 0x804B97CC: nop

    after_1:
    // 0x804B97D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804B97D4:
    // 0x804B97D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B97D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B97DC: jr          $ra
    // 0x804B97E0: nop

    return;
    // 0x804B97E0: nop

;}
RECOMP_FUNC void func_805598AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805598AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805598B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805598B4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805598B8: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(363, 0X9450) << 16);
    // 0x805598BC: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x805598C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805598C4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805598C8: lw          $t8, 0xFA0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(363, 0X9450));
    // 0x805598CC: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
    // 0x805598D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805598D4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x805598D8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805598DC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805598E0: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x805598E4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805598E8: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x805598EC: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x805598F0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x805598F4: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x805598F8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x805598FC: sw          $a1, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r5;
    // 0x80559900: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80559904: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x80559908: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8055990C: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80559910: jal         0x80048378
    // 0x80559914: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80559914: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    after_0:
    // 0x80559918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8055991C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80559920: jr          $ra
    // 0x80559924: nop

    return;
    // 0x80559924: nop

;}
RECOMP_FUNC void func_804A3A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A3A00: lui         $v0, 0x804A
    ctx->r2 = S32(RELOC_HI16(176, 0X10) << 16);
    // 0x804A3A04: addiu       $v0, $v0, 0x3A10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(176, 0X10));
    // 0x804A3A08: jr          $ra
    // 0x804A3A0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804A3A0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8002F1D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F1D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F1D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002F1DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002F1E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002F1E4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F1E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002F1EC: lbu         $t6, 0x111($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X111);
    // 0x8002F1F0: bnel        $t6, $zero, L_8002F234
    if (ctx->r14 != 0) {
        // 0x8002F1F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8002F234;
    }
    goto skip_0;
    // 0x8002F1F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8002F1F8: jal         0x8003271C
    // 0x8002F1FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003271C(rdram, ctx);
        goto after_0;
    // 0x8002F1FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8002F200: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002F204: jal         0x80040C48
    // 0x8002F208: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80040C48(rdram, ctx);
        goto after_1;
    // 0x8002F208: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8002F20C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8002F210: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8002F214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002F218: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8002F21C: lw          $v0, 0x78($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X78);
    // 0x8002F220: beql        $v0, $zero, L_8002F234
    if (ctx->r2 == 0) {
        // 0x8002F224: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8002F234;
    }
    goto skip_1;
    // 0x8002F224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x8002F228: jalr        $v0
    // 0x8002F22C: lw          $a0, 0x108($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X108);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x8002F22C: lw          $a0, 0x108($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X108);
    after_2:
    // 0x8002F230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8002F234:
    // 0x8002F234: jal         0x8002F15C
    // 0x8002F238: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    func_8002F15C(rdram, ctx);
        goto after_3;
    // 0x8002F238: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_3:
    // 0x8002F23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002F240: jal         0x8002F108
    // 0x8002F244: lw          $a1, 0x174($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X174);
    func_8002F108(rdram, ctx);
        goto after_4;
    // 0x8002F244: lw          $a1, 0x174($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X174);
    after_4:
    // 0x8002F248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002F24C: jal         0x8002E274
    // 0x8002F250: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8002E274(rdram, ctx);
        goto after_5;
    // 0x8002F250: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x8002F254: sb          $zero, 0x1AD($s0)
    MEM_B(0X1AD, ctx->r16) = 0;
    // 0x8002F258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F25C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002F260: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002F264: jr          $ra
    // 0x8002F268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002F268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806EB3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EB3DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EB3E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EB3E4: jal         0x806EB364
    // 0x806EB3E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806EB364(rdram, ctx);
        goto after_0;
    // 0x806EB3E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EB3EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EB3F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EB3F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806EB3F8: jal         0x806EB43C
    // 0x806EB3FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806EB43C(rdram, ctx);
        goto after_1;
    // 0x806EB3FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806EB400: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EB404: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806EB408: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EB40C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EB410: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806EB414: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806EB418: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x806EB41C: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806EB420: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x806EB424: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806EB428: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x806EB42C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EB430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EB434: jr          $ra
    // 0x806EB438: nop

    return;
    // 0x806EB438: nop

;}
RECOMP_FUNC void func_8000A1C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A1C0: bne         $a1, $zero, L_8000A1CC
    if (ctx->r5 != 0) {
        // 0x8000A1C4: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8000A1CC;
    }
    // 0x8000A1C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8000A1C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8000A1CC:
    // 0x8000A1CC: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8000A1D0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000A1D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000A1D8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000A1DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000A1E0: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8000A1E4: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x8000A1E8: addiu       $t8, $t8, 0x4D10
    ctx->r24 = ADD32(ctx->r24, 0X4D10);
    // 0x8000A1EC: addiu       $t7, $t6, 0x2A30
    ctx->r15 = ADD32(ctx->r14, 0X2A30);
    // 0x8000A1F0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8000A1F4: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000A1F8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000A1FC: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8000A200: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000A204: sh          $a1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r5;
    // 0x8000A208: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8000A20C: jr          $ra
    // 0x8000A210: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x8000A210: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_807A1F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1F88: jr          $ra
    // 0x807A1F8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807A1F8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80006A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006A44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006A48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006A4C: slti        $at, $a1, 0x7F
    ctx->r1 = SIGNED(ctx->r5) < 0X7F ? 1 : 0;
    // 0x80006A50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80006A54: beq         $at, $zero, L_80006ACC
    if (ctx->r1 == 0) {
        // 0x80006A58: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80006ACC;
    }
    // 0x80006A58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80006A5C: jal         0x8000B808
    // 0x80006A60: nop

    func_8000B808(rdram, ctx);
        goto after_0;
    // 0x80006A60: nop

    after_0:
    // 0x80006A64: bne         $v0, $zero, L_80006A74
    if (ctx->r2 != 0) {
        // 0x80006A68: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80006A74;
    }
    // 0x80006A68: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80006A6C: b           L_80006B00
    // 0x80006A70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80006B00;
    // 0x80006A70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80006A74:
    // 0x80006A74: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80006A78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80006A7C: beql        $t6, $zero, L_80006A98
    if (ctx->r14 == 0) {
        // 0x80006A80: lw          $a0, 0x10($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X10);
            goto L_80006A98;
    }
    goto skip_0;
    // 0x80006A80: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x80006A84: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80006A88: jal         0x80006960
    // 0x80006A8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80006960(rdram, ctx);
        goto after_1;
    // 0x80006A8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80006A90: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80006A94: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
L_80006A98:
    // 0x80006A98: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80006A9C: jal         0x80006960
    // 0x80006AA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80006960(rdram, ctx);
        goto after_2;
    // 0x80006AA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80006AA4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80006AA8: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80006AAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80006AB0: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x80006AB4: beql        $t7, $at, L_80006B04
    if (ctx->r15 == ctx->r1) {
        // 0x80006AB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80006B04;
    }
    goto skip_1;
    // 0x80006AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80006ABC: jal         0x80006960
    // 0x80006AC0: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    func_80006960(rdram, ctx);
        goto after_3;
    // 0x80006AC0: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    after_3:
    // 0x80006AC4: b           L_80006B04
    // 0x80006AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80006B04;
    // 0x80006AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80006ACC:
    // 0x80006ACC: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80006AD0: bne         $a1, $at, L_80006B00
    if (ctx->r5 != ctx->r1) {
        // 0x80006AD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80006B00;
    }
    // 0x80006AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006AD8: jal         0x8000B8DC
    // 0x80006ADC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8000B8DC(rdram, ctx);
        goto after_4;
    // 0x80006ADC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x80006AE0: bne         $v0, $zero, L_80006AF0
    if (ctx->r2 != 0) {
        // 0x80006AE4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80006AF0;
    }
    // 0x80006AE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80006AE8: b           L_80006B00
    // 0x80006AEC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80006B00;
    // 0x80006AEC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80006AF0:
    // 0x80006AF0: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80006AF4: jal         0x80006960
    // 0x80006AF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80006960(rdram, ctx);
        goto after_5;
    // 0x80006AF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80006AFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006B00:
    // 0x80006B00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80006B04:
    // 0x80006B04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006B08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80006B0C: jr          $ra
    // 0x80006B10: nop

    return;
    // 0x80006B10: nop

;}
RECOMP_FUNC void func_806F8B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8B68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F8B6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F8B70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806F8B74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806F8B78: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F8B7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F8B80: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B44) << 16);
    // 0x806F8B84: lw          $a1, 0x264($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X264);
    // 0x806F8B88: beql        $a1, $zero, L_806F8C3C
    if (ctx->r5 == 0) {
        // 0x806F8B8C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_806F8C3C;
    }
    goto skip_0;
    // 0x806F8B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x806F8B90: lwc1        $f4, 0x8C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x806F8B94: lwc1        $f6, -0x6CAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B44));
    // 0x806F8B98: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B4C) << 16);
    // 0x806F8B9C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806F8BA0: nop

    // 0x806F8BA4: bc1f        L_806F8BB8
    if (!c1cs) {
        // 0x806F8BA8: nop
    
            goto L_806F8BB8;
    }
    // 0x806F8BA8: nop

    // 0x806F8BAC: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B48) << 16);
    // 0x806F8BB0: b           L_806F8BBC
    // 0x806F8BB4: lwc1        $f0, -0x6CA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B48));
        goto L_806F8BBC;
    // 0x806F8BB4: lwc1        $f0, -0x6CA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B48));
L_806F8BB8:
    // 0x806F8BB8: lwc1        $f0, -0x6CA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B4C));
L_806F8BBC:
    // 0x806F8BBC: lh          $t6, 0x13E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X13E);
    // 0x806F8BC0: lw          $t7, 0x174($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X174);
    // 0x806F8BC4: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806F8BC8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x806F8BCC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806F8BD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806F8BD4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806F8BD8: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x806F8BDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806F8BE0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x806F8BE4: lwc1        $f4, 0x10($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X10);
    // 0x806F8BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F8BEC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x806F8BF0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806F8BF4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x806F8BF8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x806F8BFC: jal         0x806F864C
    // 0x806F8C00: nop

    func_806F864C(rdram, ctx);
        goto after_0;
    // 0x806F8C00: nop

    after_0:
    // 0x806F8C04: lui         $t1, 0x8070
    ctx->r9 = S32(RELOC_HI16(694, 0X14C4) << 16);
    // 0x806F8C08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F8C0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806F8C10: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x806F8C14: addiu       $t1, $t1, -0x732C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(694, 0X14C4));
    // 0x806F8C18: sb          $t0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r8;
    // 0x806F8C1C: sw          $t1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r9;
    // 0x806F8C20: sw          $zero, 0x264($s1)
    MEM_W(0X264, ctx->r17) = 0;
    // 0x806F8C24: addiu       $a0, $s1, 0x268
    ctx->r4 = ADD32(ctx->r17, 0X268);
    // 0x806F8C28: jal         0x806F85F8
    // 0x806F8C2C: swc1        $f16, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->f16.u32l;
    func_806F85F8(rdram, ctx);
        goto after_1;
    // 0x806F8C2C: swc1        $f16, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->f16.u32l;
    after_1:
    // 0x806F8C30: b           L_806F8C48
    // 0x806F8C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F8C48;
    // 0x806F8C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8C38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_806F8C3C:
    // 0x806F8C3C: jal         0x8005D87C
    // 0x806F8C40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8005D87C(rdram, ctx);
        goto after_2;
    // 0x806F8C40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x806F8C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F8C48:
    // 0x806F8C48: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806F8C4C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806F8C50: jr          $ra
    // 0x806F8C54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806F8C54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_805C9778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C9778: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x805C977C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805C9780: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x805C9784: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x805C9788: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805C978C: jal         0x8004700C
    // 0x805C9790: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805C9790: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805C9794: beq         $v0, $zero, L_805C9904
    if (ctx->r2 == 0) {
        // 0x805C9798: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_805C9904;
    }
    // 0x805C9798: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x805C979C: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x805C97A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805C97A4: bnel        $t6, $zero, L_805C9840
    if (ctx->r14 != 0) {
        // 0x805C97A8: lw          $t5, 0x2C($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X2C);
            goto L_805C9840;
    }
    goto skip_0;
    // 0x805C97A8: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
    skip_0:
    // 0x805C97AC: jal         0x805C7BAC
    // 0x805C97B0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    func_805C7BAC(rdram, ctx);
        goto after_1;
    // 0x805C97B0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // 0x805C97B4: beq         $v0, $zero, L_805C983C
    if (ctx->r2 == 0) {
        // 0x805C97B8: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_805C983C;
    }
    // 0x805C97B8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x805C97BC: addiu       $t7, $zero, 0x2710
    ctx->r15 = ADD32(0, 0X2710);
    // 0x805C97C0: addiu       $t8, $zero, 0x78
    ctx->r24 = ADD32(0, 0X78);
    // 0x805C97C4: sw          $t7, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r15;
    // 0x805C97C8: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x805C97CC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x805C97D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805C97D4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x805C97D8: lw          $t3, 0xA68($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XA68);
    // 0x805C97DC: lw          $t1, 0x138($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X138);
    // 0x805C97E0: lw          $t9, 0xF10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XF10);
    // 0x805C97E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x805C97E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x805C97EC: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x805C97F0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805C97F4: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(447, 0X3950) << 16);
    // 0x805C97F8: lw          $t9, 0x40($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X40);
    // 0x805C97FC: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x805C9800: lw          $v0, -0x61C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(447, 0X3950));
    // 0x805C9804: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(447, 0X3948) << 16);
    // 0x805C9808: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x805C980C: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x805C9810: lw          $a2, -0x61C8($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(447, 0X3948));
    // 0x805C9814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805C9818: lui         $a3, 0xC214
    ctx->r7 = S32(0XC214 << 16);
    // 0x805C981C: jalr        $t9
    // 0x805C9820: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x805C9820: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_2:
    // 0x805C9824: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805C9828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C982C: jal         0x805C9D10
    // 0x805C9830: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_805C9D10(rdram, ctx);
        goto after_3;
    // 0x805C9830: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_3:
    // 0x805C9834: b           L_805C9908
    // 0x805C9838: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_805C9908;
    // 0x805C9838: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805C983C:
    // 0x805C983C: lw          $t5, 0x2C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2C);
L_805C9840:
    // 0x805C9840: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805C9844: bnel        $t5, $at, L_805C9854
    if (ctx->r13 != ctx->r1) {
        // 0x805C9848: lwc1        $f12, 0x50($s1)
        ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
            goto L_805C9854;
    }
    goto skip_1;
    // 0x805C9848: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    skip_1:
    // 0x805C984C: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x805C9850: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
L_805C9854:
    // 0x805C9854: jal         0x80066E88
    // 0x805C9858: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x805C9858: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_4:
    // 0x805C985C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805C9860: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C9864: lwc1        $f6, 0x3C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x805C9868: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x805C986C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x805C9870: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x805C9874: jal         0x80066DE4
    // 0x805C9878: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x805C9878: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    after_5:
    // 0x805C987C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x805C9880: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x805C9884: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x805C9888: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
    // 0x805C988C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805C9890: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805C9894: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x805C9898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805C989C: lwc1        $f18, 0x40($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X40);
    // 0x805C98A0: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    // 0x805C98A4: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x805C98A8: div.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x805C98AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805C98B0: add.s       $f2, $f18, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x805C98B4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x805C98B8: lwc1        $f18, 0x88($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X88);
    // 0x805C98BC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x805C98C0: sub.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x805C98C4: div.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x805C98C8: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x805C98CC: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
    // 0x805C98D0: lwc1        $f18, 0x88($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X88);
    // 0x805C98D4: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805C98D8: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x805C98DC: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x805C98E0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x805C98E4: swc1        $f6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f6.u32l;
    // 0x805C98E8: jal         0x80048F84
    // 0x805C98EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x805C98EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_6:
    // 0x805C98F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805C98F4: jal         0x80048F84
    // 0x805C98F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x805C98F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x805C98FC: jal         0x805C7ABC
    // 0x805C9900: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805C7ABC(rdram, ctx);
        goto after_8;
    // 0x805C9900: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_805C9904:
    // 0x805C9904: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_805C9908:
    // 0x805C9908: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x805C990C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x805C9910: jr          $ra
    // 0x805C9914: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x805C9914: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8001C464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C464: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8001C468: addiu       $v0, $v0, -0x3B8C
    ctx->r2 = ADD32(ctx->r2, -0X3B8C);
    // 0x8001C46C: jr          $ra
    // 0x8001C470: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8001C470: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80704550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80704550: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80704554: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80704558: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8070455C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80704560: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80704564: jal         0x8004700C
    // 0x80704568: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80704568: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8070456C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80704570: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80704574: beq         $v0, $zero, L_8070465C
    if (ctx->r2 == 0) {
        // 0x80704578: lw          $v1, 0x7F78($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X7F78);
            goto L_8070465C;
    }
    // 0x80704578: lw          $v1, 0x7F78($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7F78);
    // 0x8070457C: andi        $t7, $v1, 0x7F
    ctx->r15 = ctx->r3 & 0X7F;
    // 0x80704580: bnel        $t7, $zero, L_807045A4
    if (ctx->r15 != 0) {
        // 0x80704584: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_807045A4;
    }
    goto skip_0;
    // 0x80704584: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80704588: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8070458C: jal         0x80067BBC
    // 0x80704590: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x80704590: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x80704594: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    // 0x80704598: jal         0x80067818
    // 0x8070459C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8070459C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x807045A0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
L_807045A4:
    // 0x807045A4: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x807045A8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x807045AC: lwc1        $f6, 0x84($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X84);
    // 0x807045B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807045B4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x807045B8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807045BC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x807045C0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x807045C4: nop

    // 0x807045C8: bc1fl       L_80704644
    if (!c1cs) {
        // 0x807045CC: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_80704644;
    }
    goto skip_1;
    // 0x807045CC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_1:
    // 0x807045D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x807045D4: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x807045D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x807045DC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x807045E0: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x807045E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807045E8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x807045EC: lw          $t9, 0x40($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X40);
    // 0x807045F0: lui         $a2, 0xC040
    ctx->r6 = S32(0XC040 << 16);
    // 0x807045F4: lui         $a3, 0xC1D0
    ctx->r7 = S32(0XC1D0 << 16);
    // 0x807045F8: jalr        $t9
    // 0x807045FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x807045FC: nop

    after_3:
    // 0x80704600: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80704604: jal         0x80067BBC
    // 0x80704608: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x80704608: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x8070460C: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    // 0x80704610: jal         0x80067818
    // 0x80704614: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x80704614: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80704618: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8070461C: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x80704620: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80704624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80704628: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070462C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80704630: sw          $t1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r9;
    // 0x80704634: sw          $t2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r10;
    // 0x80704638: jal         0x80705A5C
    // 0x8070463C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    func_80705A5C(rdram, ctx);
        goto after_6;
    // 0x8070463C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    after_6:
    // 0x80704640: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_80704644:
    // 0x80704644: jal         0x80048F84
    // 0x80704648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x80704648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8070464C: jal         0x8070384C
    // 0x80704650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8070384C(rdram, ctx);
        goto after_8;
    // 0x80704650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80704654: jal         0x80703F10
    // 0x80704658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80703F10(rdram, ctx);
        goto after_9;
    // 0x80704658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_8070465C:
    // 0x8070465C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80704660: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80704664: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80704668: jr          $ra
    // 0x8070466C: nop

    return;
    // 0x8070466C: nop

;}
RECOMP_FUNC void func_8070F834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070F834: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8070F838: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8070F83C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8070F840: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8070F844: lw          $s0, 0xCD0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XCD0);
    // 0x8070F848: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8070F84C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8070F850: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8070F854: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8070F858: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8070F85C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8070F860: lbu         $t7, 0xF5C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF5C);
    // 0x8070F864: lw          $t8, 0xCCC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XCCC);
    // 0x8070F868: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070F86C: addiu       $s3, $sp, 0x50
    ctx->r19 = ADD32(ctx->r29, 0X50);
    // 0x8070F870: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8070F874: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8070F878: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8070F87C: sb          $t7, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r15;
    // 0x8070F880: jal         0x8070F740
    // 0x8070F884: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    func_8070F740(rdram, ctx);
        goto after_0;
    // 0x8070F884: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    after_0:
    // 0x8070F888: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x8070F88C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8070F890: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8070F894: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x8070F898: jal         0x8070F668
    // 0x8070F89C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8070F668(rdram, ctx);
        goto after_1;
    // 0x8070F89C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_1:
    // 0x8070F8A0: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8070F8A4: lw          $s0, -0x748C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X748C);
    // 0x8070F8A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8070F8AC: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
    // 0x8070F8B0: jal         0x8070F740
    // 0x8070F8B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8070F740(rdram, ctx);
        goto after_2;
    // 0x8070F8B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8070F8B8: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
    // 0x8070F8BC: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x8070F8C0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8070F8C4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8070F8C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8070F8CC: jal         0x8070F668
    // 0x8070F8D0: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    func_8070F668(rdram, ctx);
        goto after_3;
    // 0x8070F8D0: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_3:
    // 0x8070F8D4: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8070F8D8: lw          $s0, -0x7488($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7488);
    // 0x8070F8DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8070F8E0: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
    // 0x8070F8E4: jal         0x8070F740
    // 0x8070F8E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8070F740(rdram, ctx);
        goto after_4;
    // 0x8070F8E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8070F8EC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8070F8F0: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x8070F8F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8070F8F8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8070F8FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8070F900: jal         0x8070F668
    // 0x8070F904: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    func_8070F668(rdram, ctx);
        goto after_5;
    // 0x8070F904: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_5:
    // 0x8070F908: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8070F90C: lw          $s0, -0x7484($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7484);
    // 0x8070F910: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8070F914: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
    // 0x8070F918: jal         0x8070F740
    // 0x8070F91C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8070F740(rdram, ctx);
        goto after_6;
    // 0x8070F91C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8070F920: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8070F924: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x8070F928: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8070F92C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8070F930: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8070F934: jal         0x8070F668
    // 0x8070F938: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    func_8070F668(rdram, ctx);
        goto after_7;
    // 0x8070F938: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_7:
    // 0x8070F93C: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8070F940: lw          $s0, -0x7480($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7480);
    // 0x8070F944: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8070F948: jal         0x8070F740
    // 0x8070F94C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8070F740(rdram, ctx);
        goto after_8;
    // 0x8070F94C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x8070F950: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8070F954: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x8070F958: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8070F95C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8070F960: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8070F964: jal         0x8070F668
    // 0x8070F968: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    func_8070F668(rdram, ctx);
        goto after_9;
    // 0x8070F968: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_9:
    // 0x8070F96C: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8070F970: lw          $s0, -0x747C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X747C);
    // 0x8070F974: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8070F978: jal         0x8070F740
    // 0x8070F97C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8070F740(rdram, ctx);
        goto after_10;
    // 0x8070F97C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x8070F980: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x8070F984: addiu       $a3, $s1, 0x10
    ctx->r7 = ADD32(ctx->r17, 0X10);
    // 0x8070F988: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8070F98C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8070F990: jal         0x8070F668
    // 0x8070F994: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    func_8070F668(rdram, ctx);
        goto after_11;
    // 0x8070F994: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    after_11:
    // 0x8070F998: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x8070F99C: lw          $s2, -0x7474($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X7474);
    // 0x8070F9A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8070F9A4: jal         0x8070F740
    // 0x8070F9A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8070F740(rdram, ctx);
        goto after_12;
    // 0x8070F9A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_12:
    // 0x8070F9AC: lw          $a0, 0xC($s4)
    ctx->r4 = MEM_W(ctx->r20, 0XC);
    // 0x8070F9B0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8070F9B4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8070F9B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8070F9BC: jal         0x8070F668
    // 0x8070F9C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8070F668(rdram, ctx);
        goto after_13;
    // 0x8070F9C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x8070F9C4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8070F9C8: lhu         $v0, -0x71A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X71A0);
    // 0x8070F9CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8070F9D0: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8070F9D4: beq         $at, $zero, L_8070F9E0
    if (ctx->r1 == 0) {
        // 0x8070F9D8: nop
    
            goto L_8070F9E0;
    }
    // 0x8070F9D8: nop

    // 0x8070F9DC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8070F9E0:
    // 0x8070F9E0: jal         0x8070F740
    // 0x8070F9E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8070F740(rdram, ctx);
        goto after_14;
    // 0x8070F9E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_14:
    // 0x8070F9E8: lw          $a0, 0x10($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X10);
    // 0x8070F9EC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8070F9F0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8070F9F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8070F9F8: jal         0x8070F668
    // 0x8070F9FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8070F668(rdram, ctx);
        goto after_15;
    // 0x8070F9FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x8070FA00: lbu         $t9, 0x67($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X67);
    // 0x8070FA04: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8070FA08: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8070FA0C: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x8070FA10: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x8070FA14: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8070FA18: beql        $at, $zero, L_8070FA2C
    if (ctx->r1 == 0) {
        // 0x8070FA1C: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_8070FA2C;
    }
    goto skip_0;
    // 0x8070FA1C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    skip_0:
    // 0x8070FA20: jal         0x8070F740
    // 0x8070FA24: addiu       $a0, $s4, 0x30
    ctx->r4 = ADD32(ctx->r20, 0X30);
    func_8070F740(rdram, ctx);
        goto after_16;
    // 0x8070FA24: addiu       $a0, $s4, 0x30
    ctx->r4 = ADD32(ctx->r20, 0X30);
    after_16:
    // 0x8070FA28: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
L_8070FA2C:
    // 0x8070FA2C: jal         0x80710C50
    // 0x8070FA30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80710C50(rdram, ctx);
        goto after_17;
    // 0x8070FA30: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x8070FA34: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8070FA38: sb          $zero, 0x165($t3)
    MEM_B(0X165, ctx->r11) = 0;
    // 0x8070FA3C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8070FA40: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8070FA44: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8070FA48: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8070FA4C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8070FA50: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8070FA54: jr          $ra
    // 0x8070FA58: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8070FA58: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80532D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532D58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80532D5C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80532D60: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80532D64: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80532D68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80532D6C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80532D70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80532D74: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80532D78: nop

    // 0x80532D7C: bc1f        L_80532D8C
    if (!c1cs) {
        // 0x80532D80: nop
    
            goto L_80532D8C;
    }
    // 0x80532D80: nop

    // 0x80532D84: jr          $ra
    // 0x80532D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80532D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80532D8C:
    // 0x80532D8C: jr          $ra
    // 0x80532D90: nop

    return;
    // 0x80532D90: nop

;}
RECOMP_FUNC void func_80675B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675B9C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80675BA0: lui         $v1, 0x8067
    ctx->r3 = S32(RELOC_HI16(535, 0X2508) << 16);
    // 0x80675BA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675BA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80675BAC: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80675BB0: lw          $v1, 0x7BC8($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(535, 0X2508));
    // 0x80675BB4: beq         $v1, $zero, L_80675C28
    if (ctx->r3 == 0) {
        // 0x80675BB8: nop
    
            goto L_80675C28;
    }
    // 0x80675BB8: nop

    // 0x80675BBC: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80675BC0: lui         $t0, 0x8067
    ctx->r8 = S32(RELOC_HI16(535, 0X2490) << 16);
    // 0x80675BC4: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X25D8) << 16);
    // 0x80675BC8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80675BCC: lbu         $a1, 0x0($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X0);
    // 0x80675BD0: lwc1        $f0, 0x7C98($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X25D8));
    // 0x80675BD4: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80675BD8: sll         $a2, $a1, 1
    ctx->r6 = S32(ctx->r5 << 1);
    // 0x80675BDC: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x80675BE0: lh          $t0, 0x7B50($t0)
    ctx->r8 = MEM_H(ctx->r8, (int16_t)RELOC_LO16(535, 0X2490));
    // 0x80675BE4: lui         $t1, 0x8067
    ctx->r9 = S32(RELOC_HI16(535, 0X24B0) << 16);
    // 0x80675BE8: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x80675BEC: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80675BF0: lwc1        $f18, 0x7C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x80675BF4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80675BF8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80675BFC: nop

    // 0x80675C00: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80675C04: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x80675C08: lh          $t1, 0x7B70($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(535, 0X24B0));
    // 0x80675C0C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80675C10: nop

    // 0x80675C14: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80675C18: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80675C1C: nop

    // 0x80675C20: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80675C24: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
L_80675C28:
    // 0x80675C28: jr          $ra
    // 0x80675C2C: nop

    return;
    // 0x80675C2C: nop

;}
RECOMP_FUNC void func_80071D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071DA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80071DA4: jal         0x80010520
    // 0x80071DA8: nop

    func_80010520(rdram, ctx);
        goto after_0;
    // 0x80071DA8: nop

    after_0:
    // 0x80071DAC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071DB0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071DB4: addiu       $a1, $a1, -0x58C4
    ctx->r5 = ADD32(ctx->r5, -0X58C4);
    // 0x80071DB8: addiu       $a0, $a0, -0x58E8
    ctx->r4 = ADD32(ctx->r4, -0X58E8);
    // 0x80071DBC: jal         0x8008AE20
    // 0x80071DC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80071DC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80071DC4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071DC8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80071DCC: addiu       $a2, $a2, -0x58E8
    ctx->r6 = ADD32(ctx->r6, -0X58E8);
    // 0x80071DD0: addiu       $a1, $a1, -0x58D0
    ctx->r5 = ADD32(ctx->r5, -0X58D0);
    // 0x80071DD4: jal         0x80075120
    // 0x80071DD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80075120(rdram, ctx);
        goto after_2;
    // 0x80071DD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80071DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071DE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071DE4: jr          $ra
    // 0x80071DE8: nop

    return;
    // 0x80071DE8: nop

;}
RECOMP_FUNC void func_80430CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430CC0: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80430CC4: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80430CC8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80430CCC: nop

    // 0x80430CD0: bc1fl       L_80430D04
    if (!c1cs) {
        // 0x80430CD4: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80430D04;
    }
    goto skip_0;
    // 0x80430CD4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x80430CD8: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80430CDC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80430CE0: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x80430CE4: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80430CE8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80430CEC: nop

    // 0x80430CF0: bc1f        L_80430D34
    if (!c1cs) {
        // 0x80430CF4: nop
    
            goto L_80430D34;
    }
    // 0x80430CF4: nop

    // 0x80430CF8: jr          $ra
    // 0x80430CFC: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x80430CFC: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x80430D00: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80430D04:
    // 0x80430D04: nop

    // 0x80430D08: bc1f        L_80430D34
    if (!c1cs) {
        // 0x80430D0C: nop
    
            goto L_80430D34;
    }
    // 0x80430D0C: nop

    // 0x80430D10: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80430D14: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80430D18: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80430D1C: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80430D20: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x80430D24: nop

    // 0x80430D28: bc1f        L_80430D34
    if (!c1cs) {
        // 0x80430D2C: nop
    
            goto L_80430D34;
    }
    // 0x80430D2C: nop

    // 0x80430D30: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
L_80430D34:
    // 0x80430D34: jr          $ra
    // 0x80430D38: nop

    return;
    // 0x80430D38: nop

;}
RECOMP_FUNC void func_8046C8CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C8CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046C8D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046C8D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8046C8D8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8046C8DC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8046C8E0: jal         0x80048F84
    // 0x8046C8E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8046C8E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8046C8E8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8046C8EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046C8F0: lw          $t6, 0x1E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1E0);
    // 0x8046C8F4: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x8046C8F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8046C8FC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8046C900: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x8046C904: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x8046C908: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8046C90C: bnel        $at, $zero, L_8046C920
    if (ctx->r1 != 0) {
        // 0x8046C910: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046C920;
    }
    goto skip_0;
    // 0x8046C910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8046C914: jal         0x8046D3E8
    // 0x8046C918: lbu         $a2, 0xC($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0XC);
    func_8046D3E8(rdram, ctx);
        goto after_1;
    // 0x8046C918: lbu         $a2, 0xC($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0XC);
    after_1:
    // 0x8046C91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046C920:
    // 0x8046C920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046C924: jr          $ra
    // 0x8046C928: nop

    return;
    // 0x8046C928: nop

;}
RECOMP_FUNC void func_80445F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445F04: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80445F08: jr          $ra
    // 0x80445F0C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    return;
    // 0x80445F0C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void func_805AE0B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE0B4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE0B8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE0BC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE0C0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE0C4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE0C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE0CC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE0D0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE0D4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE0D8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE0DC: jr          $ra
    // 0x805AE0E0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE0E0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804CE99C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE99C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CE9A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804CE9A4: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804CE9A8: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804CE9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CE9B0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804CE9B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804CE9B8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x804CE9BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804CE9C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804CE9C4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804CE9C8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804CE9CC: lui         $t2, 0x804D
    ctx->r10 = S32(RELOC_HI16(240, 0X1A34) << 16);
    // 0x804CE9D0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804CE9D4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804CE9D8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804CE9DC: lw          $t2, -0x31C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(240, 0X1A34));
    // 0x804CE9E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804CE9E4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804CE9E8: jal         0x804CE798
    // 0x804CE9EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804CE798(rdram, ctx);
        goto after_0;
    // 0x804CE9EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CE9F0: jal         0x804CE834
    // 0x804CE9F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804CE834(rdram, ctx);
        goto after_1;
    // 0x804CE9F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804CE9F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CE9FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CEA00: jr          $ra
    // 0x804CEA04: nop

    return;
    // 0x804CEA04: nop

;}
RECOMP_FUNC void func_8076C860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076C860: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8076C864: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076C868: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8076C86C: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x8076C870: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8076C874: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8076C878: bnel        $t6, $at, L_8076C8A4
    if (ctx->r14 != ctx->r1) {
        // 0x8076C87C: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8076C8A4;
    }
    goto skip_0;
    // 0x8076C87C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x8076C880: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8076C884: jal         0x80067BBC
    // 0x8076C888: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8076C888: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x8076C88C: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8076C890: jal         0x80067F78
    // 0x8076C894: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8076C894: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8076C898: b           L_8076C8BC
    // 0x8076C89C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8076C8BC;
    // 0x8076C89C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8076C8A0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_8076C8A4:
    // 0x8076C8A4: jal         0x80067BBC
    // 0x8076C8A8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8076C8A8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8076C8AC: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x8076C8B0: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8076C8B4: jal         0x800678F0
    // 0x8076C8B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x8076C8B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_8076C8BC:
    // 0x8076C8BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8076C8C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8076C8C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8076C8C8: jr          $ra
    // 0x8076C8CC: nop

    return;
    // 0x8076C8CC: nop

;}
RECOMP_FUNC void func_8073EC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EC8C: jr          $ra
    // 0x8073EC90: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8073EC90: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80075348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007534C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075350: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80075354: addiu       $t7, $t7, -0x7B20
    ctx->r15 = ADD32(ctx->r15, -0X7B20);
    // 0x80075358: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007535C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80075360: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80075364: sb          $t8, 0x24C($a0)
    MEM_B(0X24C, ctx->r4) = ctx->r24;
    // 0x80075368: jal         0x800751FC
    // 0x8007536C: addiu       $a1, $a0, 0x40
    ctx->r5 = ADD32(ctx->r4, 0X40);
    func_800751FC(rdram, ctx);
        goto after_0;
    // 0x8007536C: addiu       $a1, $a0, 0x40
    ctx->r5 = ADD32(ctx->r4, 0X40);
    after_0:
    // 0x80075370: jal         0x80075328
    // 0x80075374: nop

    func_80075328(rdram, ctx);
        goto after_1;
    // 0x80075374: nop

    after_1:
    // 0x80075378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007537C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075380: jr          $ra
    // 0x80075384: nop

    return;
    // 0x80075384: nop

;}
RECOMP_FUNC void func_8044BAF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BAF4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BAF8: jr          $ra
    // 0x8044BAFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BAFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_804754E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804754E0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804754E4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804754E8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804754EC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804754F0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804754F4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804754F8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804754FC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475500: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475504: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475508: jr          $ra
    // 0x8047550C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047550C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8004A950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A950: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8004A954: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004A958: jr          $ra
    // 0x8004A95C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8004A95C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8002AF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AF8C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8002AF90: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8002AF94: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8002AF98: jr          $ra
    // 0x8002AF9C: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    return;
    // 0x8002AF9C: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
;}
RECOMP_FUNC void func_800652B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652B4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800652B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800652BC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800652C0: beq         $a2, $zero, L_800652FC
    if (ctx->r6 == 0) {
        // 0x800652C4: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800652FC;
    }
    // 0x800652C4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800652C8:
    // 0x800652C8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800652CC: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x800652D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800652D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800652D8: xor         $a3, $t6, $t7
    ctx->r7 = ctx->r14 ^ ctx->r15;
    // 0x800652DC: sltu        $a3, $zero, $a3
    ctx->r7 = 0 < ctx->r7 ? 1 : 0;
    // 0x800652E0: beql        $a3, $zero, L_800652F4
    if (ctx->r7 == 0) {
        // 0x800652E4: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800652F4;
    }
    goto skip_0;
    // 0x800652E4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    skip_0:
    // 0x800652E8: jr          $ra
    // 0x800652EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800652EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800652F0: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_800652F4:
    // 0x800652F4: bne         $a2, $zero, L_800652C8
    if (ctx->r6 != 0) {
        // 0x800652F8: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800652C8;
    }
    // 0x800652F8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800652FC:
    // 0x800652FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80065300: jr          $ra
    // 0x80065304: nop

    return;
    // 0x80065304: nop

;}
RECOMP_FUNC void func_8045FDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FDDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045FDE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045FDE4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8045FDE8: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8045FDEC: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(116, 0X380) << 16);
    // 0x8045FDF0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8045FDF4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8045FDF8: lw          $t8, 0x50($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(116, 0X380));
    // 0x8045FDFC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8045FE00: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8045FE04: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8045FE08: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8045FE0C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8045FE10: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8045FE14: beql        $v1, $zero, L_8045FE48
    if (ctx->r3 == 0) {
        // 0x8045FE18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045FE48;
    }
    goto skip_0;
    // 0x8045FE18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8045FE1C: jalr        $v1
    // 0x8045FE20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8045FE20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045FE24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8045FE28: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8045FE2C: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8045FE30: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8045FE34: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8045FE38: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8045FE3C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8045FE40: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8045FE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045FE48:
    // 0x8045FE48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045FE4C: jr          $ra
    // 0x8045FE50: nop

    return;
    // 0x8045FE50: nop

;}
RECOMP_FUNC void func_8003BEC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BEC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BED0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003BED4: lbu         $t6, 0x1F8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1F8);
    // 0x8003BED8: beq         $t6, $zero, L_8003BEF0
    if (ctx->r14 == 0) {
        // 0x8003BEDC: nop
    
            goto L_8003BEF0;
    }
    // 0x8003BEDC: nop

    // 0x8003BEE0: jal         0x8003BD60
    // 0x8003BEE4: nop

    func_8003BD60(rdram, ctx);
        goto after_0;
    // 0x8003BEE4: nop

    after_0:
    // 0x8003BEE8: b           L_8003BEFC
    // 0x8003BEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003BEFC;
    // 0x8003BEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003BEF0:
    // 0x8003BEF0: jal         0x8003BE44
    // 0x8003BEF4: nop

    func_8003BE44(rdram, ctx);
        goto after_1;
    // 0x8003BEF4: nop

    after_1:
    // 0x8003BEF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003BEFC:
    // 0x8003BEFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003BF00: jr          $ra
    // 0x8003BF04: nop

    return;
    // 0x8003BF04: nop

;}
RECOMP_FUNC void func_8046A0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A0DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046A0E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046A0E4: lw          $a2, 0x180($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X180);
    // 0x8046A0E8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046A0EC: beql        $a2, $zero, L_8046A174
    if (ctx->r6 == 0) {
        // 0x8046A0F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046A174;
    }
    goto skip_0;
    // 0x8046A0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8046A0F4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8046A0F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8046A0FC: jal         0x80469F9C
    // 0x8046A100: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80469F9C(rdram, ctx);
        goto after_0;
    // 0x8046A100: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8046A104: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8046A108: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8046A10C: beq         $v0, $zero, L_8046A144
    if (ctx->r2 == 0) {
        // 0x8046A110: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8046A144;
    }
    // 0x8046A110: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8046A114: lbu         $t6, 0x64($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X64);
    // 0x8046A118: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8046A11C: bne         $t6, $at, L_8046A170
    if (ctx->r14 != ctx->r1) {
        // 0x8046A120: lui         $at, 0x8047
        ctx->r1 = S32(RELOC_HI16(138, 0X2948) << 16);
            goto L_8046A170;
    }
    // 0x8046A120: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2948) << 16);
    // 0x8046A124: lwc1        $f4, -0x3F78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2948));
    // 0x8046A128: lui         $a1, 0xBE23
    ctx->r5 = S32(0XBE23 << 16);
    // 0x8046A12C: ori         $a1, $a1, 0xD800
    ctx->r5 = ctx->r5 | 0XD800;
    // 0x8046A130: swc1        $f4, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f4.u32l;
    // 0x8046A134: jal         0x8046A018
    // 0x8046A138: sb          $zero, 0x64($v1)
    MEM_B(0X64, ctx->r3) = 0;
    func_8046A018(rdram, ctx);
        goto after_1;
    // 0x8046A138: sb          $zero, 0x64($v1)
    MEM_B(0X64, ctx->r3) = 0;
    after_1:
    // 0x8046A13C: b           L_8046A174
    // 0x8046A140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8046A174;
    // 0x8046A140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046A144:
    // 0x8046A144: lbu         $t7, 0x64($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X64);
    // 0x8046A148: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X294C) << 16);
    // 0x8046A14C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8046A150: bnel        $t7, $zero, L_8046A174
    if (ctx->r15 != 0) {
        // 0x8046A154: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046A174;
    }
    goto skip_1;
    // 0x8046A154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8046A158: lwc1        $f6, -0x3F74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X294C));
    // 0x8046A15C: lui         $a1, 0x3E23
    ctx->r5 = S32(0X3E23 << 16);
    // 0x8046A160: ori         $a1, $a1, 0xD800
    ctx->r5 = ctx->r5 | 0XD800;
    // 0x8046A164: swc1        $f6, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f6.u32l;
    // 0x8046A168: jal         0x8046A018
    // 0x8046A16C: sb          $t8, 0x64($v1)
    MEM_B(0X64, ctx->r3) = ctx->r24;
    func_8046A018(rdram, ctx);
        goto after_2;
    // 0x8046A16C: sb          $t8, 0x64($v1)
    MEM_B(0X64, ctx->r3) = ctx->r24;
    after_2:
L_8046A170:
    // 0x8046A170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046A174:
    // 0x8046A174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046A178: jr          $ra
    // 0x8046A17C: nop

    return;
    // 0x8046A17C: nop

;}
