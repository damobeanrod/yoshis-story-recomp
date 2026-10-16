#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_806F98F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F98F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F98F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806F98F8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x806F98FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9900: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806F9904: beq         $a1, $at, L_806F9928
    if (ctx->r5 == ctx->r1) {
        // 0x806F9908: lw          $v0, 0x174($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X174);
            goto L_806F9928;
    }
    // 0x806F9908: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x806F990C: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x806F9910: bnel        $a1, $at, L_806F9970
    if (ctx->r5 != ctx->r1) {
        // 0x806F9914: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F9970;
    }
    goto skip_0;
    // 0x806F9914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F9918: jal         0x806F9A78
    // 0x806F991C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_806F9A78(rdram, ctx);
        goto after_0;
    // 0x806F991C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x806F9920: b           L_806F9970
    // 0x806F9924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806F9970;
    // 0x806F9924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F9928:
    // 0x806F9928: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806F992C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806F9930: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F9934: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x806F9938: jal         0x806F9A78
    // 0x806F993C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806F9A78(rdram, ctx);
        goto after_1;
    // 0x806F993C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806F9940: jal         0x806F9894
    // 0x806F9944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806F9894(rdram, ctx);
        goto after_2;
    // 0x806F9944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x806F9948: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806F994C: addiu       $t7, $zero, 0x102
    ctx->r15 = ADD32(0, 0X102);
    // 0x806F9950: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806F9954: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x806F9958: addiu       $t9, $t9, -0x6030
    ctx->r25 = ADD32(ctx->r25, -0X6030);
    // 0x806F995C: sh          $t7, 0x4C($t8)
    MEM_H(0X4C, ctx->r24) = ctx->r15;
    // 0x806F9960: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x806F9964: sw          $t9, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r25;
    // 0x806F9968: sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
    // 0x806F996C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F9970:
    // 0x806F9970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F9974: jr          $ra
    // 0x806F9978: nop

    return;
    // 0x806F9978: nop

;}
RECOMP_FUNC void func_80439E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439E24: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80439E28: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x80439E2C: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(80, 0X18C0) << 16);
    // 0x80439E30: lw          $t6, 0x970($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X970);
    // 0x80439E34: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80439E38: addiu       $t8, $t8, -0x5C80
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(80, 0X18C0));
    // 0x80439E3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80439E40: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80439E44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80439E48: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80439E4C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80439E50: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x80439E54: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80439E58: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80439E5C: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80439E60: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80439E64: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    // 0x80439E68: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x80439E6C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80439E70: addiu       $v1, $t0, 0x8
    ctx->r3 = ADD32(ctx->r8, 0X8);
    // 0x80439E74: jr          $ra
    // 0x80439E78: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    return;
    // 0x80439E78: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_807AE67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE67C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AE680: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AE684: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AE688: jal         0x807AC734
    // 0x807AE68C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807AC734(rdram, ctx);
        goto after_0;
    // 0x807AE68C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807AE690: beq         $v0, $zero, L_807AE6A8
    if (ctx->r2 == 0) {
        // 0x807AE694: nop
    
            goto L_807AE6A8;
    }
    // 0x807AE694: nop

    // 0x807AE698: jal         0x807AE0E0
    // 0x807AE69C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807AE0E0(rdram, ctx);
        goto after_1;
    // 0x807AE69C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807AE6A0: b           L_807AE764
    // 0x807AE6A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807AE764;
    // 0x807AE6A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AE6A8:
    // 0x807AE6A8: jal         0x807ADD60
    // 0x807AE6AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807ADD60(rdram, ctx);
        goto after_2;
    // 0x807AE6AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807AE6B0: beql        $v0, $zero, L_807AE6D0
    if (ctx->r2 == 0) {
        // 0x807AE6B4: lw          $v0, 0x1E0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E0);
            goto L_807AE6D0;
    }
    goto skip_0;
    // 0x807AE6B4: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x807AE6B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE6BC: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE6C0: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x807AE6C4: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE6C8: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    // 0x807AE6CC: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_807AE6D0:
    // 0x807AE6D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE6D4: blez        $v0, L_807AE6E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807AE6D8: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_807AE6E4;
    }
    // 0x807AE6D8: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x807AE6DC: b           L_807AE760
    // 0x807AE6E0: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
        goto L_807AE760;
    // 0x807AE6E0: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
L_807AE6E4:
    // 0x807AE6E4: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE6E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AE6EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807AE6F0: swc1        $f0, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f0.u32l;
    // 0x807AE6F4: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE6F8: jal         0x807AD0FC
    // 0x807AE6FC: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    func_807AD0FC(rdram, ctx);
        goto after_3;
    // 0x807AE6FC: swc1        $f0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f0.u32l;
    after_3:
    // 0x807AE700: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AE708: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE70C: jal         0x807AD0FC
    // 0x807AE710: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    func_807AD0FC(rdram, ctx);
        goto after_4;
    // 0x807AE710: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    after_4:
    // 0x807AE714: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AE718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AE71C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE720: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807AE724: jal         0x807AEA24
    // 0x807AE728: sw          $v0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r2;
    func_807AEA24(rdram, ctx);
        goto after_5;
    // 0x807AE728: sw          $v0, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r2;
    after_5:
    // 0x807AE72C: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x807AE730: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE734: sb          $t3, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r11;
    // 0x807AE738: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE73C: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x807AE740: sb          $t4, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r12;
    // 0x807AE744: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE748: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x807AE74C: sb          $t5, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r13;
    // 0x807AE750: jal         0x800677F8
    // 0x807AE754: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    func_800677F8(rdram, ctx);
        goto after_6;
    // 0x807AE754: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_6:
    // 0x807AE758: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x807AE75C: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_807AE760:
    // 0x807AE760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807AE764:
    // 0x807AE764: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AE768: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AE76C: jr          $ra
    // 0x807AE770: nop

    return;
    // 0x807AE770: nop

;}
RECOMP_FUNC void func_8064CD50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064CD50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064CD54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064CD58: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8064CD5C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8064CD60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064CD64: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8064CD68: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8064CD6C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8064CD70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064CD74: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8064CD78: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8064CD7C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8064CD80: lui         $t2, 0x8065
    ctx->r10 = S32(RELOC_HI16(495, 0X35C4) << 16);
    // 0x8064CD84: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8064CD88: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8064CD8C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8064CD90: lw          $t2, -0x296C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(495, 0X35C4));
    // 0x8064CD94: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064CD98: jal         0x8064CB1C
    // 0x8064CD9C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8064CB1C(rdram, ctx);
        goto after_0;
    // 0x8064CD9C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8064CDA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064CDA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064CDA8: jr          $ra
    // 0x8064CDAC: nop

    return;
    // 0x8064CDAC: nop

;}
RECOMP_FUNC void func_807B9418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9418: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B941C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9420: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B9424: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x807B9428: lw          $t0, 0x16C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X16C);
    // 0x807B942C: lbu         $v0, 0x10($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X10);
    // 0x807B9430: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807B9434: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x807B9438: jal         0x807B8D30
    // 0x807B943C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_807B8D30(rdram, ctx);
        goto after_0;
    // 0x807B943C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807B9440: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807B9444: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807B9448: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x807B944C: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x807B9450: bgez        $v0, L_807B9470
    if (SIGNED(ctx->r2) >= 0) {
        // 0x807B9454: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_807B9470;
    }
    // 0x807B9454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B9458: sb          $zero, 0x10($t0)
    MEM_B(0X10, ctx->r8) = 0;
    // 0x807B945C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807B9460: jal         0x807B9E2C
    // 0x807B9464: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_807B9E2C(rdram, ctx);
        goto after_1;
    // 0x807B9464: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x807B9468: b           L_807B9478
    // 0x807B946C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807B9478;
    // 0x807B946C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B9470:
    // 0x807B9470: sb          $v0, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r2;
    // 0x807B9474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B9478:
    // 0x807B9478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807B947C: jr          $ra
    // 0x807B9480: nop

    return;
    // 0x807B9480: nop

;}
RECOMP_FUNC void func_807110EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807110EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807110F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807110F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807110F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807110FC: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80711100: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80711104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80711108: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8071110C: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x80711110: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80711114: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80711118: lw          $v1, 0x180($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X180);
    // 0x8071111C: beq         $v1, $zero, L_80711168
    if (ctx->r3 == 0) {
        // 0x80711120: nop
    
            goto L_80711168;
    }
    // 0x80711120: nop

    // 0x80711124: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x80711128: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8071112C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80711130: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x80711134: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80711138: bne         $t9, $at, L_80711158
    if (ctx->r25 != ctx->r1) {
        // 0x8071113C: nop
    
            goto L_80711158;
    }
    // 0x8071113C: nop

    // 0x80711140: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80711144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80711148: jal         0x80053CF8
    // 0x8071114C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_80053CF8(rdram, ctx);
        goto after_0;
    // 0x8071114C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80711150: b           L_80711174
    // 0x80711154: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
        goto L_80711174;
    // 0x80711154: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
L_80711158:
    // 0x80711158: jal         0x80053CF8
    // 0x8071115C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80053CF8(rdram, ctx);
        goto after_1;
    // 0x8071115C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80711160: b           L_80711174
    // 0x80711164: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
        goto L_80711174;
    // 0x80711164: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
L_80711168:
    // 0x80711168: jal         0x80053CF8
    // 0x8071116C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80053CF8(rdram, ctx);
        goto after_2;
    // 0x8071116C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80711170: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
L_80711174:
    // 0x80711174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80711178: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8071117C: jal         0x80053EE4
    // 0x80711180: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    func_80053EE4(rdram, ctx);
        goto after_3;
    // 0x80711180: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_3:
    // 0x80711184: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80711188: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8071118C: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80711190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80711194: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80711198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8071119C: jr          $ra
    // 0x807111A0: nop

    return;
    // 0x807111A0: nop

;}
RECOMP_FUNC void func_807BB238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB238: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BB23C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BB240: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807BB244: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807BB248: jal         0x807BAC0C
    // 0x807BB24C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_807BAC0C(rdram, ctx);
        goto after_0;
    // 0x807BB24C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x807BB250: jal         0x807BAF34
    // 0x807BB254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807BAF34(rdram, ctx);
        goto after_1;
    // 0x807BB254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x807BB258: jal         0x807BAB94
    // 0x807BB25C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807BAB94(rdram, ctx);
        goto after_2;
    // 0x807BB25C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x807BB260: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x807BB264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BB268: jal         0x807BA8F4
    // 0x807BB26C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_807BA8F4(rdram, ctx);
        goto after_3;
    // 0x807BB26C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x807BB270: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x807BB274: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x807BB278: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807BB27C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807BB280: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807BB284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BB288: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807BB28C: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x807BB290: nop

    // 0x807BB294: bc1fl       L_807BB2AC
    if (!c1cs) {
        // 0x807BB298: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807BB2AC;
    }
    goto skip_0;
    // 0x807BB298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807BB29C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x807BB2A0: jal         0x807BB7A4
    // 0x807BB2A4: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_807BB7A4(rdram, ctx);
        goto after_4;
    // 0x807BB2A4: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_4:
    // 0x807BB2A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807BB2AC:
    // 0x807BB2AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807BB2B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807BB2B4: jr          $ra
    // 0x807BB2B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807BB2B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80051734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005173C: lw          $a1, 0x4C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4C);
    // 0x80051740: jal         0x800516D0
    // 0x80051744: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800516D0(rdram, ctx);
        goto after_0;
    // 0x80051744: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80051748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005174C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051750: jr          $ra
    // 0x80051754: nop

    return;
    // 0x80051754: nop

;}
RECOMP_FUNC void func_804481D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804481D8: jr          $ra
    // 0x804481DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804481DC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805A7360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A7364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A7368: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805A736C: slti        $at, $v0, 0x45B5
    ctx->r1 = SIGNED(ctx->r2) < 0X45B5 ? 1 : 0;
    // 0x805A7370: bne         $at, $zero, L_805A7394
    if (ctx->r1 != 0) {
        // 0x805A7374: addiu       $t6, $v0, -0x4182
        ctx->r14 = ADD32(ctx->r2, -0X4182);
            goto L_805A7394;
    }
    // 0x805A7374: addiu       $t6, $v0, -0x4182
    ctx->r14 = ADD32(ctx->r2, -0X4182);
    // 0x805A7378: addiu       $at, $zero, 0x4696
    ctx->r1 = ADD32(0, 0X4696);
    // 0x805A737C: beq         $v0, $at, L_805A73EC
    if (ctx->r2 == ctx->r1) {
        // 0x805A7380: addiu       $at, $zero, 0x4697
        ctx->r1 = ADD32(0, 0X4697);
            goto L_805A73EC;
    }
    // 0x805A7380: addiu       $at, $zero, 0x4697
    ctx->r1 = ADD32(0, 0X4697);
    // 0x805A7384: beq         $v0, $at, L_805A73FC
    if (ctx->r2 == ctx->r1) {
        // 0x805A7388: nop
    
            goto L_805A73FC;
    }
    // 0x805A7388: nop

    // 0x805A738C: b           L_805A7408
    // 0x805A7390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A7408;
    // 0x805A7390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A7394:
    // 0x805A7394: slti        $at, $v0, 0x45B4
    ctx->r1 = SIGNED(ctx->r2) < 0X45B4 ? 1 : 0;
    // 0x805A7398: bne         $at, $zero, L_805A73B0
    if (ctx->r1 != 0) {
        // 0x805A739C: addiu       $at, $zero, 0x45B4
        ctx->r1 = ADD32(0, 0X45B4);
            goto L_805A73B0;
    }
    // 0x805A739C: addiu       $at, $zero, 0x45B4
    ctx->r1 = ADD32(0, 0X45B4);
    // 0x805A73A0: beq         $v0, $at, L_805A73FC
    if (ctx->r2 == ctx->r1) {
        // 0x805A73A4: nop
    
            goto L_805A73FC;
    }
    // 0x805A73A4: nop

    // 0x805A73A8: b           L_805A7408
    // 0x805A73AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A7408;
    // 0x805A73AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A73B0:
    // 0x805A73B0: slti        $at, $v0, 0x418E
    ctx->r1 = SIGNED(ctx->r2) < 0X418E ? 1 : 0;
    // 0x805A73B4: bne         $at, $zero, L_805A73CC
    if (ctx->r1 != 0) {
        // 0x805A73B8: addiu       $at, $zero, 0x45B3
        ctx->r1 = ADD32(0, 0X45B3);
            goto L_805A73CC;
    }
    // 0x805A73B8: addiu       $at, $zero, 0x45B3
    ctx->r1 = ADD32(0, 0X45B3);
    // 0x805A73BC: beq         $v0, $at, L_805A73EC
    if (ctx->r2 == ctx->r1) {
        // 0x805A73C0: nop
    
            goto L_805A73EC;
    }
    // 0x805A73C0: nop

    // 0x805A73C4: b           L_805A7408
    // 0x805A73C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A7408;
    // 0x805A73C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A73CC:
    // 0x805A73CC: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x805A73D0: beq         $at, $zero, L_805A7404
    if (ctx->r1 == 0) {
        // 0x805A73D4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_805A7404;
    }
    // 0x805A73D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805A73D8: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(426, 0X1740) << 16);
    // 0x805A73DC: addu        $at, $at, $t6
    gpr jr_addend_805A73E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x805A73E0: lw          $t6, -0x7570($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(426, 0X1740));
    // 0x805A73E4: jr          $t6
    // 0x805A73E8: nop

    switch (jr_addend_805A73E4 >> 2) {
        case 0: goto L_805A73EC; break;
        case 1: goto L_805A73EC; break;
        case 2: goto L_805A73EC; break;
        case 3: goto L_805A73EC; break;
        case 4: goto L_805A73EC; break;
        case 5: goto L_805A73EC; break;
        case 6: goto L_805A73FC; break;
        case 7: goto L_805A73FC; break;
        case 8: goto L_805A73FC; break;
        case 9: goto L_805A73FC; break;
        case 10: goto L_805A73FC; break;
        case 11: goto L_805A73FC; break;
        default: switch_error(__func__, 0x805A73E4, 0x805A8A90);
    }
    // 0x805A73E8: nop

L_805A73EC:
    // 0x805A73EC: jal         0x805A7E54
    // 0x805A73F0: nop

    func_805A7E54(rdram, ctx);
        goto after_0;
    // 0x805A73F0: nop

    after_0:
    // 0x805A73F4: b           L_805A7408
    // 0x805A73F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A7408;
    // 0x805A73F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A73FC:
    // 0x805A73FC: jal         0x805A82D8
    // 0x805A7400: nop

    func_805A82D8(rdram, ctx);
        goto after_1;
    // 0x805A7400: nop

    after_1:
L_805A7404:
    // 0x805A7404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A7408:
    // 0x805A7408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A740C: jr          $ra
    // 0x805A7410: nop

    return;
    // 0x805A7410: nop

;}
RECOMP_FUNC void func_80420038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80420038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80420040: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80420044: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80420048: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(29, 0X349C) << 16);
    // 0x8042004C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80420050: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80420054: lw          $t8, 0xAFC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(29, 0X349C));
    // 0x80420058: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042005C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80420060: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80420064: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80420068: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042006C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80420070: beql        $v1, $zero, L_804200A4
    if (ctx->r3 == 0) {
        // 0x80420074: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804200A4;
    }
    goto skip_0;
    // 0x80420074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80420078: jalr        $v1
    // 0x8042007C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8042007C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80420080: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80420084: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80420088: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8042008C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80420090: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80420094: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80420098: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8042009C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804200A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804200A4:
    // 0x804200A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804200A8: jr          $ra
    // 0x804200AC: nop

    return;
    // 0x804200AC: nop

;}
RECOMP_FUNC void func_806E87B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E87B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E87BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E87C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806E87C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806E87C8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x806E87CC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x806E87D0: jal         0x806E840C
    // 0x806E87D4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_806E840C(rdram, ctx);
        goto after_0;
    // 0x806E87D4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x806E87D8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x806E87DC: jal         0x806E8508
    // 0x806E87E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_806E8508(rdram, ctx);
        goto after_1;
    // 0x806E87E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x806E87E4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x806E87E8: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x806E87EC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806E87F0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x806E87F4: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x806E87F8: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x806E87FC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x806E8800: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x806E8804: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x806E8808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E880C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E8810: jr          $ra
    // 0x806E8814: nop

    return;
    // 0x806E8814: nop

;}
RECOMP_FUNC void func_8003F03C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F03C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003F040: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003F044: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8003F048: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8003F04C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8003F050: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8003F054: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003F058: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003F05C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003F060: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003F064: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003F068: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003F06C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003F070: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003F074: lbu         $v0, 0x12C8($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X12C8);
    // 0x8003F078: beq         $v0, $zero, L_8003F11C
    if (ctx->r2 == 0) {
        // 0x8003F07C: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8003F11C;
    }
    // 0x8003F07C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8003F080: blez        $v0, L_8003F11C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003F084: lhu         $s5, 0x12BE($s2)
        ctx->r21 = MEM_HU(ctx->r18, 0X12BE);
            goto L_8003F11C;
    }
    // 0x8003F084: lhu         $s5, 0x12BE($s2)
    ctx->r21 = MEM_HU(ctx->r18, 0X12BE);
    // 0x8003F088: addiu       $fp, $zero, 0x4144
    ctx->r30 = ADD32(0, 0X4144);
    // 0x8003F08C: addiu       $s7, $zero, 0x406C
    ctx->r23 = ADD32(0, 0X406C);
    // 0x8003F090: addiu       $s6, $zero, 0x18
    ctx->r22 = ADD32(0, 0X18);
    // 0x8003F094: addu        $t7, $s1, $s5
    ctx->r15 = ADD32(ctx->r17, ctx->r21);
L_8003F098:
    // 0x8003F098: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x8003F09C: multu       $t8, $s6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003F0A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003F0A4: mflo        $t9
    ctx->r25 = lo;
    // 0x8003F0A8: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8003F0AC: lw          $s0, 0x11FC($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X11FC);
    // 0x8003F0B0: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8003F0B4: beq         $v0, $s7, L_8003F0D0
    if (ctx->r2 == ctx->r23) {
        // 0x8003F0B8: nop
    
            goto L_8003F0D0;
    }
    // 0x8003F0B8: nop

    // 0x8003F0BC: beq         $v0, $fp, L_8003F0F0
    if (ctx->r2 == ctx->r30) {
        // 0x8003F0C0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8003F0F0;
    }
    // 0x8003F0C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003F0C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003F0C8: b           L_8003F108
    // 0x8003F0CC: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
        goto L_8003F108;
    // 0x8003F0CC: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
L_8003F0D0:
    // 0x8003F0D0: jal         0x8003EA94
    // 0x8003F0D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003EA94(rdram, ctx);
        goto after_0;
    // 0x8003F0D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8003F0D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003F0DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003F0E0: jal         0x8003F004
    // 0x8003F0E4: andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    func_8003F004(rdram, ctx);
        goto after_1;
    // 0x8003F0E4: andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    after_1:
    // 0x8003F0E8: b           L_8003F10C
    // 0x8003F0EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_8003F10C;
    // 0x8003F0EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8003F0F0:
    // 0x8003F0F0: jal         0x8003EAE0
    // 0x8003F0F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003EAE0(rdram, ctx);
        goto after_2;
    // 0x8003F0F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8003F0F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003F0FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003F100: jal         0x8003F004
    // 0x8003F104: andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    func_8003F004(rdram, ctx);
        goto after_3;
    // 0x8003F104: andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    after_3:
L_8003F108:
    // 0x8003F108: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8003F10C:
    // 0x8003F10C: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x8003F110: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8003F114: bnel        $at, $zero, L_8003F098
    if (ctx->r1 != 0) {
        // 0x8003F118: addu        $t7, $s1, $s5
        ctx->r15 = ADD32(ctx->r17, ctx->r21);
            goto L_8003F098;
    }
    goto skip_0;
    // 0x8003F118: addu        $t7, $s1, $s5
    ctx->r15 = ADD32(ctx->r17, ctx->r21);
    skip_0:
L_8003F11C:
    // 0x8003F11C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003F120: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003F124: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003F128: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003F12C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003F130: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003F134: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F138: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8003F13C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8003F140: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8003F144: jr          $ra
    // 0x8003F148: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8003F148: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_804F589C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F589C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F58A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F58A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F58A8: lui         $a1, 0x8051
    ctx->r5 = S32(RELOC_HI16(273, 0X1BBD8) << 16);
    // 0x804F58AC: addiu       $a1, $a1, -0x198
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(273, 0X1BBD8));
    // 0x804F58B0: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x804F58B4: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x804F58B8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x804F58BC: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x804F58C0: addiu       $at, $zero, 0x41EC
    ctx->r1 = ADD32(0, 0X41EC);
    // 0x804F58C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F58C8: beq         $v1, $at, L_804F58E4
    if (ctx->r3 == ctx->r1) {
        // 0x804F58CC: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_804F58E4;
    }
    // 0x804F58CC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x804F58D0: addiu       $at, $zero, 0x4594
    ctx->r1 = ADD32(0, 0X4594);
    // 0x804F58D4: beql        $v1, $at, L_804F58F8
    if (ctx->r3 == ctx->r1) {
        // 0x804F58D8: lw          $a3, 0x138($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X138);
            goto L_804F58F8;
    }
    goto skip_0;
    // 0x804F58D8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    skip_0:
    // 0x804F58DC: b           L_804F591C
    // 0x804F58E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804F591C;
    // 0x804F58E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F58E4:
    // 0x804F58E4: jal         0x804F5CE8
    // 0x804F58E8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_804F5CE8(rdram, ctx);
        goto after_0;
    // 0x804F58E8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x804F58EC: b           L_804F591C
    // 0x804F58F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804F591C;
    // 0x804F58F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F58F4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
L_804F58F8:
    // 0x804F58F8: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(273, 0X20870) << 16);
    // 0x804F58FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F5900: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x804F5904: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x804F5908: lwc1        $f4, 0x4B00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(273, 0X20870));
    // 0x804F590C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x804F5910: jal         0x804F5CE8
    // 0x804F5914: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    func_804F5CE8(rdram, ctx);
        goto after_1;
    // 0x804F5914: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x804F5918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F591C:
    // 0x804F591C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F5920: jr          $ra
    // 0x804F5924: nop

    return;
    // 0x804F5924: nop

;}
RECOMP_FUNC void func_804369C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804369C8: jr          $ra
    // 0x804369CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804369CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80799038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079903C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799040: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80799044: jal         0x80047090
    // 0x80799048: addiu       $a0, $zero, 0x46D8
    ctx->r4 = ADD32(0, 0X46D8);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80799048: addiu       $a0, $zero, 0x46D8
    ctx->r4 = ADD32(0, 0X46D8);
    after_0:
    // 0x8079904C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80799050: bne         $v0, $at, L_80799060
    if (ctx->r2 != ctx->r1) {
        // 0x80799054: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80799060;
    }
    // 0x80799054: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80799058: b           L_807990DC
    // 0x8079905C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807990DC;
    // 0x8079905C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80799060:
    // 0x80799060: lui         $at, 0x46D8
    ctx->r1 = S32(0X46D8 << 16);
    // 0x80799064: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80799068: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8079906C: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80799070: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X25DC) << 16);
    // 0x80799074: lwc1        $f6, -0x4F04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25DC));
    // 0x80799078: lwc1        $f4, 0x8C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x8079907C: lw          $a1, 0x84($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X84);
    // 0x80799080: lw          $a2, 0x88($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X88);
    // 0x80799084: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80799088: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    // 0x8079908C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80799090: jal         0x8004613C
    // 0x80799094: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80799094: nop

    after_1:
    // 0x80799098: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x8079909C: bne         $v0, $zero, L_807990AC
    if (ctx->r2 != 0) {
        // 0x807990A0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807990AC;
    }
    // 0x807990A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807990A4: b           L_807990DC
    // 0x807990A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807990DC;
    // 0x807990A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807990AC:
    // 0x807990AC: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x807990B0: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x807990B4: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x807990B8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x807990BC: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x807990C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807990C4: jal         0x80047F9C
    // 0x807990C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807990C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x807990CC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x807990D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807990D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807990D8: sb          $t1, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r9;
L_807990DC:
    // 0x807990DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807990E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807990E4: jr          $ra
    // 0x807990E8: nop

    return;
    // 0x807990E8: nop

;}
RECOMP_FUNC void func_80019E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019E98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80019E9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80019EA0: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x80019EA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80019EA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80019EAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80019EB0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80019EB4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80019EB8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80019EBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80019EC0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80019EC4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80019EC8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80019ECC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80019ED0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80019ED4: jal         0x80019EEC
    // 0x80019ED8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80019EEC(rdram, ctx);
        goto after_0;
    // 0x80019ED8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80019EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80019EE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80019EE4: jr          $ra
    // 0x80019EE8: nop

    return;
    // 0x80019EE8: nop

;}
RECOMP_FUNC void func_800474B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800474B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800474B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800474B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800474BC: addiu       $a1, $a2, 0x38
    ctx->r5 = ADD32(ctx->r6, 0X38);
    // 0x800474C0: jal         0x8004742C
    // 0x800474C4: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    func_8004742C(rdram, ctx);
        goto after_0;
    // 0x800474C4: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    after_0:
    // 0x800474C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800474CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800474D0: jr          $ra
    // 0x800474D4: nop

    return;
    // 0x800474D4: nop

;}
RECOMP_FUNC void func_806ECDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ECDDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806ECDE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806ECDE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806ECDE8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ECDEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806ECDF0: jal         0x800577D8
    // 0x806ECDF4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806ECDF4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x806ECDF8: jal         0x806EC584
    // 0x806ECDFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC584(rdram, ctx);
        goto after_1;
    // 0x806ECDFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806ECE00: bne         $v0, $zero, L_806ECE28
    if (ctx->r2 != 0) {
        // 0x806ECE04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806ECE28;
    }
    // 0x806ECE04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECE08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECE0C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806ECE10: jal         0x806ED360
    // 0x806ECE14: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_2;
    // 0x806ECE14: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
    // 0x806ECE18: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x806ECE1C: jal         0x806EBFB8
    // 0x806ECE20: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    func_806EBFB8(rdram, ctx);
        goto after_3;
    // 0x806ECE20: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    after_3:
    // 0x806ECE24: sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
L_806ECE28:
    // 0x806ECE28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806ECE2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806ECE30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806ECE34: jr          $ra
    // 0x806ECE38: nop

    return;
    // 0x806ECE38: nop

;}
RECOMP_FUNC void func_806EC03C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC03C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806EC040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EC044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EC048: c.le.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl <= ctx->f4.fl;
    // 0x806EC04C: nop

    // 0x806EC050: bc1fl       L_806EC064
    if (!c1cs) {
        // 0x806EC054: swc1        $f12, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
            goto L_806EC064;
    }
    goto skip_0;
    // 0x806EC054: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    skip_0:
    // 0x806EC058: b           L_806EC088
    // 0x806EC05C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_806EC088;
    // 0x806EC05C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x806EC060: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
L_806EC064:
    // 0x806EC064: jal         0x80065414
    // 0x806EC068: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_80065414(rdram, ctx);
        goto after_0;
    // 0x806EC068: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x806EC06C: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x806EC070: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806EC074: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806EC078: mul.s       $f2, $f6, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x806EC07C: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x806EC080: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x806EC084: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
L_806EC088:
    // 0x806EC088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EC08C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EC090: jr          $ra
    // 0x806EC094: nop

    return;
    // 0x806EC094: nop

;}
RECOMP_FUNC void func_80442444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80442444: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80442448: lwc1        $f6, 0xE0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x8044244C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80442450: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80442454: nop

    // 0x80442458: bc1t        L_80442470
    if (c1cs) {
        // 0x8044245C: nop
    
            goto L_80442470;
    }
    // 0x8044245C: nop

    // 0x80442460: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80442464: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80442468: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8044246C: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_80442470:
    // 0x80442470: jr          $ra
    // 0x80442474: nop

    return;
    // 0x80442474: nop

;}
RECOMP_FUNC void func_8006F324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F32C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006F330: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8006F334: jal         0x8006F49C
    // 0x8006F338: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8006F49C(rdram, ctx);
        goto after_0;
    // 0x8006F338: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8006F33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F344: jr          $ra
    // 0x8006F348: nop

    return;
    // 0x8006F348: nop

;}
RECOMP_FUNC void func_806CC008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CC008: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x806CC00C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CC010: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CC014: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x806CC018: addiu       $ra, $zero, 0x14
    ctx->r31 = ADD32(0, 0X14);
    // 0x806CC01C: lbu         $v0, 0x86C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X86C);
    // 0x806CC020: lbu         $v1, 0x86D($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X86D);
    // 0x806CC024: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806CC028: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806CC02C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806CC030: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C14) << 16);
    // 0x806CC034: lwc1        $f8, -0xCCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C14));
    // 0x806CC038: lui         $t0, 0x806D
    ctx->r8 = S32(RELOC_HI16(604, 0X3690) << 16);
    // 0x806CC03C: addiu       $t0, $t0, -0x1250
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(604, 0X3690));
    // 0x806CC040: lui         $t2, 0x806D
    ctx->r10 = S32(RELOC_HI16(604, 0X3A7C) << 16);
    // 0x806CC044: addiu       $t2, $t2, -0xE64
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(604, 0X3A7C));
    // 0x806CC048: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CC04C: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x806CC050: mflo        $t6
    ctx->r14 = lo;
    // 0x806CC054: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806CC058: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x806CC05C: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806CC060: lh          $t6, 0x86E($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X86E);
    // 0x806CC064: lwc1        $f14, 0x868($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X868);
    // 0x806CC068: lui         $t3, 0x806D
    ctx->r11 = S32(RELOC_HI16(604, 0X3A98) << 16);
    // 0x806CC06C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x806CC070: addiu       $t3, $t3, -0xE48
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(604, 0X3A98));
    // 0x806CC074: addu        $t6, $t3, $a2
    ctx->r14 = ADD32(ctx->r11, ctx->r6);
    // 0x806CC078: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CC07C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C18) << 16);
    // 0x806CC080: mflo        $t7
    ctx->r15 = lo;
    // 0x806CC084: addu        $t4, $t0, $t7
    ctx->r12 = ADD32(ctx->r8, ctx->r15);
    // 0x806CC088: addu        $t7, $t2, $a1
    ctx->r15 = ADD32(ctx->r10, ctx->r5);
    // 0x806CC08C: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806CC090: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806CC094: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x806CC098: sub.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x806CC09C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806CC0A0: mflo        $t8
    ctx->r24 = lo;
    // 0x806CC0A4: lwc1        $f10, 0x85C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X85C);
    // 0x806CC0A8: nop

    // 0x806CC0AC: multu       $t8, $ra
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806CC0B0: addu        $t8, $t2, $a2
    ctx->r24 = ADD32(ctx->r10, ctx->r6);
    // 0x806CC0B4: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x806CC0B8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x806CC0BC: mflo        $t9
    ctx->r25 = lo;
    // 0x806CC0C0: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x806CC0C4: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x806CC0C8: addu        $t9, $t3, $a1
    ctx->r25 = ADD32(ctx->r11, ctx->r5);
    // 0x806CC0CC: mul.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x806CC0D0: add.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x806CC0D4: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x806CC0D8: swc1        $f6, 0x85C($a3)
    MEM_W(0X85C, ctx->r7) = ctx->f6.u32l;
    // 0x806CC0DC: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x806CC0E0: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x806CC0E4: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806CC0E8: lwc1        $f4, 0x860($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X860);
    // 0x806CC0EC: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x806CC0F0: nop

    // 0x806CC0F4: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x806CC0F8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x806CC0FC: lwc1        $f10, 0x85C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X85C);
    // 0x806CC100: mul.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x806CC104: lwc1        $f14, -0xCC8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C18));
    // 0x806CC108: add.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x806CC10C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x806CC110: nop

    // 0x806CC114: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x806CC118: swc1        $f18, 0x860($a3)
    MEM_W(0X860, ctx->r7) = ctx->f18.u32l;
    // 0x806CC11C: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x806CC120: lwc1        $f4, 0x860($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X860);
    // 0x806CC124: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x806CC128: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x806CC12C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x806CC130: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x806CC134: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x806CC138: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x806CC13C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x806CC140: jal         0x80049018
    // 0x806CC144: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x806CC144: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x806CC148: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x806CC14C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x806CC150: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x806CC154: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x806CC158: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x806CC15C: addiu       $ra, $zero, 0x14
    ctx->r31 = ADD32(0, 0X14);
    // 0x806CC160: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x806CC164: beq         $v0, $zero, L_806CC184
    if (ctx->r2 == 0) {
        // 0x806CC168: lwc1        $f2, 0x24($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
            goto L_806CC184;
    }
    // 0x806CC168: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806CC16C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806CC170: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806CC174: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806CC178: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x806CC17C: b           L_806CC198
    // 0x806CC180: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
        goto L_806CC198;
    // 0x806CC180: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_806CC184:
    // 0x806CC184: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CC188: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806CC18C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806CC190: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x806CC194: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_806CC198:
    // 0x806CC198: lbu         $t9, 0x165($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X165);
    // 0x806CC19C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806CC1A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806CC1A4: beq         $t9, $at, L_806CC2E8
    if (ctx->r25 == ctx->r1) {
        // 0x806CC1A8: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_806CC2E8;
    }
    // 0x806CC1A8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x806CC1AC: addiu       $t3, $sp, 0x30
    ctx->r11 = ADD32(ctx->r29, 0X30);
    // 0x806CC1B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_806CC1B4:
    // 0x806CC1B4: lw          $v0, 0x874($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X874);
    // 0x806CC1B8: beql        $v0, $zero, L_806CC2E0
    if (ctx->r2 == 0) {
        // 0x806CC1BC: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_806CC2E0;
    }
    goto skip_0;
    // 0x806CC1BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x806CC1C0: multu       $a2, $ra
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806CC1C4: mflo        $a0
    ctx->r4 = lo;
    // 0x806CC1C8: addu        $v1, $t5, $a0
    ctx->r3 = ADD32(ctx->r13, ctx->r4);
    // 0x806CC1CC: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x806CC1D0: addu        $a1, $t4, $a0
    ctx->r5 = ADD32(ctx->r12, ctx->r4);
    // 0x806CC1D4: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x806CC1D8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x806CC1DC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x806CC1E0: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806CC1E4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CC1E8: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806CC1EC: lwc1        $f4, 0x85C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X85C);
    // 0x806CC1F0: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x806CC1F4: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x806CC1F8: mul.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x806CC1FC: nop

    // 0x806CC200: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x806CC204: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x806CC208: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x806CC20C: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x806CC210: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x806CC214: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x806CC218: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806CC21C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806CC220: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806CC224: lwc1        $f8, 0x860($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X860);
    // 0x806CC228: mul.s       $f18, $f6, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x806CC22C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x806CC230: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x806CC234: swc1        $f6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f6.u32l;
    // 0x806CC238: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806CC23C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x806CC240: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806CC244: lwc1        $f10, 0x85C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X85C);
    // 0x806CC248: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806CC24C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x806CC250: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x806CC254: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x806CC258: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x806CC25C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x806CC260: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806CC264: lwc1        $f18, 0x860($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X860);
    // 0x806CC268: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x806CC26C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806CC270: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x806CC274: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
    // 0x806CC278: lh          $t6, 0xC($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XC);
    // 0x806CC27C: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x806CC280: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x806CC284: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x806CC288: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806CC28C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806CC290: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806CC294: nop

    // 0x806CC298: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x806CC29C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x806CC2A0: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x806CC2A4: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x806CC2A8: lh          $t8, 0x10($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X10);
    // 0x806CC2AC: sh          $t8, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r24;
    // 0x806CC2B0: lh          $t9, 0x144($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X144);
    // 0x806CC2B4: bne         $t1, $t9, L_806CC2C4
    if (ctx->r9 != ctx->r25) {
        // 0x806CC2B8: nop
    
            goto L_806CC2C4;
    }
    // 0x806CC2B8: nop

    // 0x806CC2BC: b           L_806CC2C8
    // 0x806CC2C0: sb          $t2, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r10;
        goto L_806CC2C8;
    // 0x806CC2C0: sb          $t2, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r10;
L_806CC2C4:
    // 0x806CC2C4: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
L_806CC2C8:
    // 0x806CC2C8: lbu         $t6, 0xE($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XE);
    // 0x806CC2CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806CC2D0: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x806CC2D4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x806CC2D8: sw          $t9, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r25;
    // 0x806CC2DC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_806CC2E0:
    // 0x806CC2E0: bne         $a2, $t1, L_806CC1B4
    if (ctx->r6 != ctx->r9) {
        // 0x806CC2E4: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_806CC1B4;
    }
    // 0x806CC2E4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_806CC2E8:
    // 0x806CC2E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CC2EC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x806CC2F0: jr          $ra
    // 0x806CC2F4: nop

    return;
    // 0x806CC2F4: nop

;}
RECOMP_FUNC void func_806D00C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D00C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D00CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D00D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D00D4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D00D8: jal         0x806CFF8C
    // 0x806D00DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_806CFF8C(rdram, ctx);
        goto after_0;
    // 0x806D00DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D00E0: jal         0x806CFFF4
    // 0x806D00E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806CFFF4(rdram, ctx);
        goto after_1;
    // 0x806D00E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806D00E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D00EC: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x806D00F0: bnel        $a3, $zero, L_806D0130
    if (ctx->r7 != 0) {
        // 0x806D00F4: lwc1        $f10, 0x4($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
            goto L_806D0130;
    }
    goto skip_0;
    // 0x806D00F4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x806D00F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806D00FC: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806D0100: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0104: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806D0108: nop

    // 0x806D010C: bc1fl       L_806D0160
    if (!c1cs) {
        // 0x806D0110: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D0160;
    }
    goto skip_1;
    // 0x806D0110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806D0114: jal         0x806D093C
    // 0x806D0118: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_806D093C(rdram, ctx);
        goto after_2;
    // 0x806D0118: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
    // 0x806D011C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1B00) << 16);
    // 0x806D0120: lwc1        $f8, 0x12A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1B00));
    // 0x806D0124: b           L_806D015C
    // 0x806D0128: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
        goto L_806D015C;
    // 0x806D0128: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x806D012C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
L_806D0130:
    // 0x806D0130: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806D0134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0138: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806D013C: nop

    // 0x806D0140: bc1fl       L_806D0160
    if (!c1cs) {
        // 0x806D0144: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D0160;
    }
    goto skip_2;
    // 0x806D0144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806D0148: jal         0x806D093C
    // 0x806D014C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_806D093C(rdram, ctx);
        goto after_3;
    // 0x806D014C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_3:
    // 0x806D0150: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1B04) << 16);
    // 0x806D0154: lwc1        $f18, 0x12A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1B04));
    // 0x806D0158: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
L_806D015C:
    // 0x806D015C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D0160:
    // 0x806D0160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D0164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D0168: jr          $ra
    // 0x806D016C: nop

    return;
    // 0x806D016C: nop

;}
RECOMP_FUNC void func_80422E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422E24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80422E28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80422E2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80422E30: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80422E34: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80422E38: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(35, 0X2E08) << 16);
    // 0x80422E3C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80422E40: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80422E44: addiu       $t7, $t7, 0x5808
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(35, 0X2E08));
    // 0x80422E48: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80422E4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80422E50: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80422E54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80422E58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80422E5C: jal         0x80422F08
    // 0x80422E60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80422F08(rdram, ctx);
        goto after_0;
    // 0x80422E60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80422E64: jal         0x80047090
    // 0x80422E68: addiu       $a0, $zero, 0x4067
    ctx->r4 = ADD32(0, 0X4067);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x80422E68: addiu       $a0, $zero, 0x4067
    ctx->r4 = ADD32(0, 0X4067);
    after_1:
    // 0x80422E6C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80422E70: bne         $v0, $at, L_80422E88
    if (ctx->r2 != ctx->r1) {
        // 0x80422E74: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80422E88;
    }
    // 0x80422E74: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80422E78: jal         0x800445A4
    // 0x80422E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80422E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80422E80: b           L_80422EF8
    // 0x80422E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80422EF8;
    // 0x80422E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80422E88:
    // 0x80422E88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80422E8C: lui         $at, 0x4067
    ctx->r1 = S32(0X4067 << 16);
    // 0x80422E90: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x80422E94: lui         $a3, 0xBC23
    ctx->r7 = S32(0XBC23 << 16);
    // 0x80422E98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80422E9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80422EA0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80422EA4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80422EA8: jal         0x8004613C
    // 0x80422EAC: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x80422EAC: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    after_3:
    // 0x80422EB0: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x80422EB4: beq         $v0, $zero, L_80422EEC
    if (ctx->r2 == 0) {
        // 0x80422EB8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80422EEC;
    }
    // 0x80422EB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80422EBC: lhu         $t1, 0xE($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XE);
    // 0x80422EC0: andi        $t0, $v1, 0x3FF
    ctx->r8 = ctx->r3 & 0X3FF;
    // 0x80422EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80422EC8: andi        $t2, $t1, 0xFC00
    ctx->r10 = ctx->r9 & 0XFC00;
    // 0x80422ECC: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80422ED0: sh          $t3, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r11;
    // 0x80422ED4: jal         0x80047F9C
    // 0x80422ED8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x80422ED8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_4:
    // 0x80422EDC: jal         0x804255F0
    // 0x80422EE0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_804255F0(rdram, ctx);
        goto after_5;
    // 0x80422EE0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80422EE4: b           L_80422EF8
    // 0x80422EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80422EF8;
    // 0x80422EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80422EEC:
    // 0x80422EEC: jal         0x800445A4
    // 0x80422EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x80422EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80422EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80422EF8:
    // 0x80422EF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80422EFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80422F00: jr          $ra
    // 0x80422F04: nop

    return;
    // 0x80422F04: nop

;}
RECOMP_FUNC void func_805CA5FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA5FC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x805CA600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CA604: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805CA608: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805CA60C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x805CA610: bne         $v1, $zero, L_805CA6AC
    if (ctx->r3 != 0) {
        // 0x805CA614: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_805CA6AC;
    }
    // 0x805CA614: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x805CA618: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x805CA61C: addiu       $at, $zero, 0x4514
    ctx->r1 = ADD32(0, 0X4514);
    // 0x805CA620: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x805CA624: bne         $t6, $at, L_805CA634
    if (ctx->r14 != ctx->r1) {
        // 0x805CA628: addiu       $t8, $zero, 0xF0
        ctx->r24 = ADD32(0, 0XF0);
            goto L_805CA634;
    }
    // 0x805CA628: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x805CA62C: b           L_805CA638
    // 0x805CA630: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_805CA638;
    // 0x805CA630: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_805CA634:
    // 0x805CA634: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_805CA638:
    // 0x805CA638: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805CA63C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805CA640: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x805CA644: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x805CA648: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805CA64C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805CA650: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x805CA654: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x805CA658: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x805CA65C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x805CA660: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x805CA664: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x805CA668: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805CA66C: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x805CA670: lwc1        $f4, 0x44($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X44);
    // 0x805CA674: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x805CA678: lwc1        $f6, 0x6C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X6C);
    // 0x805CA67C: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x805CA680: lwc1        $f8, 0x70($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X70);
    // 0x805CA684: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x805CA688: lwc1        $f10, 0x74($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X74);
    // 0x805CA68C: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x805CA690: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x805CA694: lhu         $a2, 0x4($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X4);
    // 0x805CA698: lw          $t9, 0x3C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X3C);
    // 0x805CA69C: jalr        $t9
    // 0x805CA6A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805CA6A0: nop

    after_0:
    // 0x805CA6A4: b           L_805CA78C
    // 0x805CA6A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805CA78C;
    // 0x805CA6A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CA6AC:
    // 0x805CA6AC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x805CA6B0: lhu         $t2, 0xC($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0XC);
    // 0x805CA6B4: addiu       $at, $zero, 0x45DC
    ctx->r1 = ADD32(0, 0X45DC);
    // 0x805CA6B8: bne         $t2, $at, L_805CA788
    if (ctx->r10 != ctx->r1) {
        // 0x805CA6BC: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_805CA788;
    }
    // 0x805CA6BC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x805CA6C0: bne         $t1, $at, L_805CA788
    if (ctx->r9 != ctx->r1) {
        // 0x805CA6C4: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_805CA788;
    }
    // 0x805CA6C4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x805CA6C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805CA6CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805CA6D0: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x805CA6D4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805CA6D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805CA6DC: lwc1        $f16, 0x3C($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x805CA6E0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x805CA6E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805CA6E8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x805CA6EC: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(450, 0X310) << 16);
    // 0x805CA6F0: lwc1        $f18, -0x5810($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(450, 0X310));
    // 0x805CA6F4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805CA6F8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x805CA6FC: lwc1        $f6, 0x40($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X40);
    // 0x805CA700: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805CA704: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x805CA708: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x805CA70C: lw          $t5, -0x76F8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X76F8);
    // 0x805CA710: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x805CA714: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x805CA718: lwc1        $f16, 0x44($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X44);
    // 0x805CA71C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x805CA720: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805CA724: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(450, 0X314) << 16);
    // 0x805CA728: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x805CA72C: lwc1        $f6, 0x6C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X6C);
    // 0x805CA730: lwc1        $f4, -0x580C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(450, 0X314));
    // 0x805CA734: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x805CA738: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x805CA73C: lwc1        $f10, 0x70($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X70);
    // 0x805CA740: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x805CA744: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x805CA748: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x805CA74C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x805CA750: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x805CA754: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x805CA758: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x805CA75C: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x805CA760: lw          $t9, 0x28($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X28);
    // 0x805CA764: jalr        $t9
    // 0x805CA768: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x805CA768: nop

    after_1:
    // 0x805CA76C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x805CA770: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x805CA774: jal         0x80067BBC
    // 0x805CA778: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805CA778: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x805CA77C: addiu       $a0, $zero, 0x278
    ctx->r4 = ADD32(0, 0X278);
    // 0x805CA780: jal         0x80067818
    // 0x805CA784: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x805CA784: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_805CA788:
    // 0x805CA788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CA78C:
    // 0x805CA78C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x805CA790: jr          $ra
    // 0x805CA794: nop

    return;
    // 0x805CA794: nop

;}
RECOMP_FUNC void func_80048D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048D54: jal         0x80048CC0
    // 0x80048D58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80048CC0(rdram, ctx);
        goto after_0;
    // 0x80048D58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80048D5C: jal         0x800447C8
    // 0x80048D60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80048D60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80048D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048D6C: jr          $ra
    // 0x80048D70: nop

    return;
    // 0x80048D70: nop

;}
RECOMP_FUNC void func_80024680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024688: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002468C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80024690: lbu         $t6, 0xC($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XC);
    // 0x80024694: bnel        $t6, $zero, L_800246A8
    if (ctx->r14 != 0) {
        // 0x80024698: lw          $t7, 0x8($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X8);
            goto L_800246A8;
    }
    goto skip_0;
    // 0x80024698: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x8002469C: b           L_80024738
    // 0x800246A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80024738;
    // 0x800246A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800246A4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
L_800246A8:
    // 0x800246A8: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x800246AC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800246B0: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800246B4: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800246B8: sltu        $at, $t8, $t1
    ctx->r1 = ctx->r24 < ctx->r9 ? 1 : 0;
    // 0x800246BC: bnel        $at, $zero, L_80024738
    if (ctx->r1 != 0) {
        // 0x800246C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80024738;
    }
    goto skip_1;
    // 0x800246C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800246C4: lbu         $t2, 0xC($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XC);
    // 0x800246C8: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800246CC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800246D0: bne         $t4, $zero, L_800246E0
    if (ctx->r12 != 0) {
        // 0x800246D4: sb          $t3, 0xC($a0)
        MEM_B(0XC, ctx->r4) = ctx->r11;
            goto L_800246E0;
    }
    // 0x800246D4: sb          $t3, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r11;
    // 0x800246D8: b           L_80024738
    // 0x800246DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80024738;
    // 0x800246DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800246E0:
    // 0x800246E0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800246E4: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800246E8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800246EC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800246F0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800246F4: beql        $t7, $zero, L_80024738
    if (ctx->r15 == 0) {
        // 0x800246F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80024738;
    }
    goto skip_2;
    // 0x800246F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800246FC: beq         $t6, $a3, L_8002470C
    if (ctx->r14 == ctx->r7) {
        // 0x80024700: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_8002470C;
    }
    // 0x80024700: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80024704: bnel        $t6, $t8, L_80024738
    if (ctx->r14 != ctx->r24) {
        // 0x80024708: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80024738;
    }
    goto skip_3;
    // 0x80024708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
L_8002470C:
    // 0x8002470C: jal         0x8001D770
    // 0x80024710: nop

    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x80024710: nop

    after_0:
    // 0x80024714: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80024718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002471C: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x80024720: jal         0x80067BF8
    // 0x80024724: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x80024724: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_1:
    // 0x80024728: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002472C: jal         0x80067818
    // 0x80024730: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80024730: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80024734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80024738:
    // 0x80024738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002473C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024740: jr          $ra
    // 0x80024744: nop

    return;
    // 0x80024744: nop

;}
RECOMP_FUNC void func_80582040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80582044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80582048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8058204C: jal         0x8057EF14
    // 0x80582050: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    func_8057EF14(rdram, ctx);
        goto after_0;
    // 0x80582050: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    after_0:
    // 0x80582054: beq         $v0, $zero, L_80582080
    if (ctx->r2 == 0) {
        // 0x80582058: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80582080;
    }
    // 0x80582058: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8058205C: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    // 0x80582060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80582064: beql        $a2, $zero, L_80582084
    if (ctx->r6 == 0) {
        // 0x80582068: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80582084;
    }
    goto skip_0;
    // 0x80582068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8058206C: jal         0x805820E0
    // 0x80582070: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_805820E0(rdram, ctx);
        goto after_1;
    // 0x80582070: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80582074: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80582078: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8058207C: sb          $t6, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r14;
L_80582080:
    // 0x80582080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80582084:
    // 0x80582084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80582088: jr          $ra
    // 0x8058208C: nop

    return;
    // 0x8058208C: nop

;}
RECOMP_FUNC void func_80790CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790CD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80790CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80790CE0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80790CE4: jal         0x8004700C
    // 0x80790CE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80790CE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80790CEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80790CF0: beq         $v0, $zero, L_80790D7C
    if (ctx->r2 == 0) {
        // 0x80790CF4: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_80790D7C;
    }
    // 0x80790CF4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80790CF8: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x80790CFC: bnel        $t6, $zero, L_80790D44
    if (ctx->r14 != 0) {
        // 0x80790D00: lwc1        $f8, 0x84($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
            goto L_80790D44;
    }
    goto skip_0;
    // 0x80790D00: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    skip_0:
    // 0x80790D04: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80790D08: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80790D0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80790D10: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80790D14: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80790D18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80790D1C: bc1fl       L_80790D80
    if (!c1cs) {
        // 0x80790D20: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80790D80;
    }
    goto skip_1;
    // 0x80790D20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80790D24: jal         0x8079393C
    // 0x80790D28: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8079393C(rdram, ctx);
        goto after_1;
    // 0x80790D28: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80790D2C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80790D30: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x80790D34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80790D38: b           L_80790D80
    // 0x80790D3C: sb          $t7, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r15;
        goto L_80790D80;
    // 0x80790D3C: sb          $t7, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r15;
    // 0x80790D40: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
L_80790D44:
    // 0x80790D44: lwc1        $f10, 0x84($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80790D48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80790D4C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80790D50: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80790D54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80790D58: bc1fl       L_80790D80
    if (!c1cs) {
        // 0x80790D5C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80790D80;
    }
    goto skip_2;
    // 0x80790D5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80790D60: jal         0x8079393C
    // 0x80790D64: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80790D64: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80790D68: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80790D6C: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x80790D70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80790D74: b           L_80790D80
    // 0x80790D78: sb          $t8, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r24;
        goto L_80790D80;
    // 0x80790D78: sb          $t8, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r24;
L_80790D7C:
    // 0x80790D7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80790D80:
    // 0x80790D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80790D84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80790D88: jr          $ra
    // 0x80790D8C: nop

    return;
    // 0x80790D8C: nop

;}
RECOMP_FUNC void func_80581EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581F04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80581F08: jal         0x80045A34
    // 0x80581F0C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80581F0C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80581F10: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80581F14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80581F18: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80581F1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80581F20: jal         0x800657CC
    // 0x80581F24: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x80581F24: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    after_1:
    // 0x80581F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581F30: jr          $ra
    // 0x80581F34: nop

    return;
    // 0x80581F34: nop

;}
RECOMP_FUNC void func_8044DD48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044DD48: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8044DD4C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8044DD50: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8044DD54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8044DD58: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8044DD5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8044DD60: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8044DD64: bltz        $a3, L_8044DEBC
    if (SIGNED(ctx->r7) < 0) {
        // 0x8044DD68: sw          $a2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r6;
            goto L_8044DEBC;
    }
    // 0x8044DD68: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8044DD6C: slti        $at, $a3, 0xC
    ctx->r1 = SIGNED(ctx->r7) < 0XC ? 1 : 0;
    // 0x8044DD70: beq         $at, $zero, L_8044DEBC
    if (ctx->r1 == 0) {
        // 0x8044DD74: lw          $t3, 0x60($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X60);
            goto L_8044DEBC;
    }
    // 0x8044DD74: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8044DD78: lw          $v0, 0x1F4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X1F4);
    // 0x8044DD7C: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044DD80: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x8044DD84: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044DD88: lw          $v1, 0x6980($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6980);
    // 0x8044DD8C: lui         $t7, 0x8045
    ctx->r15 = S32(RELOC_HI16(98, 0X136D4) << 16);
    // 0x8044DD90: lui         $t1, 0x8045
    ctx->r9 = S32(RELOC_HI16(98, 0X136F0) << 16);
    // 0x8044DD94: addu        $t6, $v1, $t2
    ctx->r14 = ADD32(ctx->r3, ctx->r10);
    // 0x8044DD98: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8044DD9C: sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7 << 1);
    // 0x8044DDA0: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8044DDA4: beq         $a0, $zero, L_8044DEBC
    if (ctx->r4 == 0) {
        // 0x8044DDA8: addu        $t1, $t1, $v1
        ctx->r9 = ADD32(ctx->r9, ctx->r3);
            goto L_8044DEBC;
    }
    // 0x8044DDA8: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x8044DDAC: lh          $t7, 0x7AB4($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(98, 0X136D4));
    // 0x8044DDB0: lh          $t1, 0x7AD0($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(98, 0X136F0));
    // 0x8044DDB4: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X12DE8) << 16);
    // 0x8044DDB8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8044DDBC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8044DDC0: sll         $t4, $t1, 3
    ctx->r12 = S32(ctx->r9 << 3);
    // 0x8044DDC4: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8044DDC8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8044DDCC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8044DDD0: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8044DDD4: addiu       $t6, $t6, 0x71C8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X12DE8));
    // 0x8044DDD8: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8044DDDC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8044DDE0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8044DDE4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8044DDE8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8044DDEC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8044DDF0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8044DDF4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8044DDF8: jal         0x8044DB30
    // 0x8044DDFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044DB30(rdram, ctx);
        goto after_0;
    // 0x8044DDFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8044DE00: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8044DE04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8044DE08: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8044DE0C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8044DE10: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8044DE14: jal         0x8044D9A0
    // 0x8044DE18: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8044D9A0(rdram, ctx);
        goto after_1;
    // 0x8044DE18: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8044DE1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8044DE20: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8044DE24: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8044DE28: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8044DE2C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8044DE30: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8044DE34: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8044DE38: lui         $t7, 0x8045
    ctx->r15 = S32(RELOC_HI16(98, 0X12DE8) << 16);
    // 0x8044DE3C: addiu       $t7, $t7, 0x71C8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(98, 0X12DE8));
    // 0x8044DE40: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8044DE44: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8044DE48: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8044DE4C: lui         $t9, 0x8045
    ctx->r25 = S32(RELOC_HI16(98, 0X13980) << 16);
    // 0x8044DE50: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8044DE54: addiu       $t9, $t9, 0x7D60
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(98, 0X13980));
    // 0x8044DE58: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8044DE5C: addu        $a0, $t2, $t9
    ctx->r4 = ADD32(ctx->r10, ctx->r25);
    // 0x8044DE60: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8044DE64: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8044DE68: beql        $t4, $zero, L_8044DE8C
    if (ctx->r12 == 0) {
        // 0x8044DE6C: lw          $t7, 0x60($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X60);
            goto L_8044DE8C;
    }
    goto skip_0;
    // 0x8044DE6C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    skip_0:
    // 0x8044DE70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8044DE74: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8044DE78: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8044DE7C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8044DE80: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8044DE84: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8044DE88: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
L_8044DE8C:
    // 0x8044DE8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8044DE90: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8044DE94: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8044DE98: jal         0x8044DBBC
    // 0x8044DE9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8044DBBC(rdram, ctx);
        goto after_2;
    // 0x8044DE9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x8044DEA0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8044DEA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8044DEA8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8044DEAC: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8044DEB0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8044DEB4: jal         0x8044D810
    // 0x8044DEB8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8044D810(rdram, ctx);
        goto after_3;
    // 0x8044DEB8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_3:
L_8044DEBC:
    // 0x8044DEBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8044DEC0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8044DEC4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8044DEC8: jr          $ra
    // 0x8044DECC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8044DECC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_805A1CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1CA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A1CA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A1CA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A1CAC: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x805A1CB0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805A1CB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A1CB8: bnel        $t6, $at, L_805A1CE4
    if (ctx->r14 != ctx->r1) {
        // 0x805A1CBC: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_805A1CE4;
    }
    goto skip_0;
    // 0x805A1CBC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x805A1CC0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805A1CC4: jal         0x80067BBC
    // 0x805A1CC8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805A1CC8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x805A1CCC: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x805A1CD0: jal         0x80067F78
    // 0x805A1CD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x805A1CD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805A1CD8: b           L_805A1CFC
    // 0x805A1CDC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_805A1CFC;
    // 0x805A1CDC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x805A1CE0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_805A1CE4:
    // 0x805A1CE4: jal         0x80067BBC
    // 0x805A1CE8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805A1CE8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x805A1CEC: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x805A1CF0: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x805A1CF4: jal         0x800678F0
    // 0x805A1CF8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x805A1CF8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_805A1CFC:
    // 0x805A1CFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A1D00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A1D04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A1D08: jr          $ra
    // 0x805A1D0C: nop

    return;
    // 0x805A1D0C: nop

;}
RECOMP_FUNC void func_805E4548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4548: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805E454C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E4550: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x805E4554: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x805E4558: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x805E455C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x805E4560: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x805E4564: lw          $a2, 0x88($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X88);
    // 0x805E4568: bne         $t9, $zero, L_805E4664
    if (ctx->r25 != 0) {
        // 0x805E456C: sw          $t8, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r24;
            goto L_805E4664;
    }
    // 0x805E456C: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x805E4570: sra         $v0, $t8, 3
    ctx->r2 = S32(SIGNED(ctx->r24) >> 3);
    // 0x805E4574: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x805E4578: beq         $v0, $zero, L_805E45A0
    if (ctx->r2 == 0) {
        // 0x805E457C: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_805E45A0;
    }
    // 0x805E457C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x805E4580: beq         $v0, $at, L_805E45CC
    if (ctx->r2 == ctx->r1) {
        // 0x805E4584: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_805E45CC;
    }
    // 0x805E4584: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x805E4588: beq         $v0, $at, L_805E4604
    if (ctx->r2 == ctx->r1) {
        // 0x805E458C: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_805E4604;
    }
    // 0x805E458C: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x805E4590: beq         $v0, $at, L_805E4628
    if (ctx->r2 == ctx->r1) {
        // 0x805E4594: addiu       $a1, $zero, 0x8B
        ctx->r5 = ADD32(0, 0X8B);
            goto L_805E4628;
    }
    // 0x805E4594: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x805E4598: b           L_805E4668
    // 0x805E459C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805E4668;
    // 0x805E459C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805E45A0:
    // 0x805E45A0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805E45A4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x805E45A8: addiu       $t0, $zero, 0x4644
    ctx->r8 = ADD32(0, 0X4644);
    // 0x805E45AC: addiu       $t2, $zero, 0x4666
    ctx->r10 = ADD32(0, 0X4666);
    // 0x805E45B0: sh          $t0, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r8;
    // 0x805E45B4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x805E45B8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x805E45BC: jal         0x8004590C
    // 0x805E45C0: sh          $t2, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r10;
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x805E45C0: sh          $t2, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r10;
    after_0:
    // 0x805E45C4: b           L_805E4668
    // 0x805E45C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805E4668;
    // 0x805E45C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805E45CC:
    // 0x805E45CC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x805E45D0: addiu       $t4, $zero, 0x4644
    ctx->r12 = ADD32(0, 0X4644);
    // 0x805E45D4: addiu       $t6, $zero, 0x4666
    ctx->r14 = ADD32(0, 0X4666);
    // 0x805E45D8: sh          $t4, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r12;
    // 0x805E45DC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x805E45E0: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    // 0x805E45E4: sh          $t6, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r14;
    // 0x805E45E8: jal         0x8004590C
    // 0x805E45EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x805E45EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x805E45F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805E45F4: jal         0x805E42F4
    // 0x805E45F8: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    func_805E42F4(rdram, ctx);
        goto after_2;
    // 0x805E45F8: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    after_2:
    // 0x805E45FC: b           L_805E4668
    // 0x805E4600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805E4668;
    // 0x805E4600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805E4604:
    // 0x805E4604: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x805E4608: addiu       $t9, $zero, 0x11
    ctx->r25 = ADD32(0, 0X11);
    // 0x805E460C: addiu       $a1, $a2, 0x400
    ctx->r5 = ADD32(ctx->r6, 0X400);
    // 0x805E4610: sh          $zero, 0x18($t8)
    MEM_H(0X18, ctx->r24) = 0;
    // 0x805E4614: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x805E4618: jal         0x8004590C
    // 0x805E461C: sh          $t9, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r25;
    func_8004590C(rdram, ctx);
        goto after_3;
    // 0x805E461C: sh          $t9, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r25;
    after_3:
    // 0x805E4620: b           L_805E4668
    // 0x805E4624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805E4668;
    // 0x805E4624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805E4628:
    // 0x805E4628: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x805E462C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805E4630: jal         0x805E42F4
    // 0x805E4634: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_805E42F4(rdram, ctx);
        goto after_4;
    // 0x805E4634: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_4:
    // 0x805E4638: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x805E463C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x805E4640: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x805E4644: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x805E4648: addiu       $t1, $zero, 0x4644
    ctx->r9 = ADD32(0, 0X4644);
    // 0x805E464C: addiu       $t3, $zero, 0x4666
    ctx->r11 = ADD32(0, 0X4666);
    // 0x805E4650: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    // 0x805E4654: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x805E4658: addiu       $a1, $a2, 0x200
    ctx->r5 = ADD32(ctx->r6, 0X200);
    // 0x805E465C: jal         0x8004590C
    // 0x805E4660: sh          $t3, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r11;
    func_8004590C(rdram, ctx);
        goto after_5;
    // 0x805E4660: sh          $t3, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r11;
    after_5:
L_805E4664:
    // 0x805E4664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805E4668:
    // 0x805E4668: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805E466C: jr          $ra
    // 0x805E4670: nop

    return;
    // 0x805E4670: nop

;}
RECOMP_FUNC void func_8045B890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B890: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(107, 0X28) << 16);
    // 0x8045B894: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8045B898: jr          $ra
    // 0x8045B89C: addiu       $v0, $v0, -0x4748
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(107, 0X28));
    return;
    // 0x8045B89C: addiu       $v0, $v0, -0x4748
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(107, 0X28));
;}
RECOMP_FUNC void func_80533840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80533844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80533848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8053384C: jal         0x80045A34
    // 0x80533850: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80533850: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x80533854: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80533858: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8053385C: bne         $v0, $zero, L_8053386C
    if (ctx->r2 != 0) {
        // 0x80533860: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8053386C;
    }
    // 0x80533860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80533864: b           L_80533870
    // 0x80533868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80533870;
    // 0x80533868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8053386C:
    // 0x8053386C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80533870:
    // 0x80533870: jr          $ra
    // 0x80533874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80533874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8041F1C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041F1C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8041F1C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041F1C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8041F1CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8041F1D0: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8041F1D4: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041F1D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041F1DC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8041F1E0: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8041F1E4: jal         0x8041DB1C
    // 0x8041F1E8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041F1E8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8041F1EC: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8041F1F0: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8041F1F4: lwc1        $f18, 0x18($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8041F1F8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8041F1FC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8041F200: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8041F204: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8041F208: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8041F20C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8041F210: nop

    // 0x8041F214: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8041F218: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8041F21C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8041F220: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8041F224: nop

    // 0x8041F228: bc1f        L_8041F238
    if (!c1cs) {
        // 0x8041F22C: nop
    
            goto L_8041F238;
    }
    // 0x8041F22C: nop

    // 0x8041F230: b           L_8041F23C
    // 0x8041F234: div.s       $f14, $f16, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
        goto L_8041F23C;
    // 0x8041F234: div.s       $f14, $f16, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
L_8041F238:
    // 0x8041F238: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8041F23C:
    // 0x8041F23C: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8041F240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F244: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8041F248: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    // 0x8041F24C: jal         0x8041E5E8
    // 0x8041F250: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    func_8041E5E8(rdram, ctx);
        goto after_1;
    // 0x8041F250: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x8041F254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F258: jal         0x8041E430
    // 0x8041F25C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E430(rdram, ctx);
        goto after_2;
    // 0x8041F25C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8041F260: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8041F264: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8041F268: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8041F26C: nop

    // 0x8041F270: bc1fl       L_8041F2D8
    if (!c1cs) {
        // 0x8041F274: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F2D8;
    }
    goto skip_0;
    // 0x8041F274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8041F278: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8041F27C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8041F280: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8041F284: bc1fl       L_8041F2D8
    if (!c1cs) {
        // 0x8041F288: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F2D8;
    }
    goto skip_1;
    // 0x8041F288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8041F28C: lwc1        $f8, 0x24($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8041F290: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8041F294: nop

    // 0x8041F298: bc1fl       L_8041F2D8
    if (!c1cs) {
        // 0x8041F29C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F2D8;
    }
    goto skip_2;
    // 0x8041F29C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8041F2A0: lwc1        $f10, 0x28($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X28);
    // 0x8041F2A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F2A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041F2AC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8041F2B0: nop

    // 0x8041F2B4: bc1fl       L_8041F2D8
    if (!c1cs) {
        // 0x8041F2B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F2D8;
    }
    goto skip_3;
    // 0x8041F2B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8041F2BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8041F2C0: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8041F2C4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8041F2C8: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    // 0x8041F2CC: jal         0x8041FE10
    // 0x8041F2D0: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    func_8041FE10(rdram, ctx);
        goto after_3;
    // 0x8041F2D0: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x8041F2D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041F2D8:
    // 0x8041F2D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8041F2DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8041F2E0: jr          $ra
    // 0x8041F2E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8041F2E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806CB78C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CB78C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CB790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CB794: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806CB798: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806CB79C: lh          $a2, 0x1F0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1F0);
    // 0x806CB7A0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806CB7A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806CB7A8: beq         $a2, $at, L_806CB7DC
    if (ctx->r6 == ctx->r1) {
        // 0x806CB7AC: sll         $a1, $a2, 16
        ctx->r5 = S32(ctx->r6 << 16);
            goto L_806CB7DC;
    }
    // 0x806CB7AC: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x806CB7B0: jal         0x80067930
    // 0x806CB7B4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x806CB7B4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_0:
    // 0x806CB7B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806CB7BC: bne         $v0, $at, L_806CB7DC
    if (ctx->r2 != ctx->r1) {
        // 0x806CB7C0: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_806CB7DC;
    }
    // 0x806CB7C0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x806CB7C4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806CB7C8: jal         0x80067878
    // 0x806CB7CC: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x806CB7CC: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    after_1:
    // 0x806CB7D0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x806CB7D4: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x806CB7D8: sh          $t8, 0x1F0($t9)
    MEM_H(0X1F0, ctx->r25) = ctx->r24;
L_806CB7DC:
    // 0x806CB7DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CB7E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CB7E4: jr          $ra
    // 0x806CB7E8: nop

    return;
    // 0x806CB7E8: nop

;}
RECOMP_FUNC void func_8040FF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040FF04: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8040FF08: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8040FF0C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8040FF10: addu        $a2, $a0, $at
    ctx->r6 = ADD32(ctx->r4, ctx->r1);
    // 0x8040FF14: lw          $t6, 0x39E4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X39E4);
    // 0x8040FF18: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8040FF1C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8040FF20: beq         $t6, $zero, L_80410004
    if (ctx->r14 == 0) {
        // 0x8040FF24: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80410004;
    }
    // 0x8040FF24: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8040FF28: addu        $a1, $a0, $at
    ctx->r5 = ADD32(ctx->r4, ctx->r1);
    // 0x8040FF2C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8040FF30: lw          $t7, 0x39E8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X39E8);
L_8040FF34:
    // 0x8040FF34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8040FF38: beql        $t7, $zero, L_8040FFF4
    if (ctx->r15 == 0) {
        // 0x8040FF3C: lw          $t3, 0x39E4($a1)
        ctx->r11 = MEM_W(ctx->r5, 0X39E4);
            goto L_8040FFF4;
    }
    goto skip_0;
    // 0x8040FF3C: lw          $t3, 0x39E4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X39E4);
    skip_0:
    // 0x8040FF40: lw          $t8, 0x39E8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X39E8);
L_8040FF44:
    // 0x8040FF44: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x8040FF48: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8040FF4C: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8040FF50: mflo        $t2
    ctx->r10 = lo;
    // 0x8040FF54: addu        $a3, $t2, $v0
    ctx->r7 = ADD32(ctx->r10, ctx->r2);
    // 0x8040FF58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8040FF5C: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8040FF60: mflo        $t3
    ctx->r11 = lo;
    // 0x8040FF64: addu        $t0, $a0, $t3
    ctx->r8 = ADD32(ctx->r4, ctx->r11);
    // 0x8040FF68: lh          $t4, 0x0($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X0);
    // 0x8040FF6C: sh          $t4, -0x40($s0)
    MEM_H(-0X40, ctx->r16) = ctx->r12;
    // 0x8040FF70: lh          $t5, 0x2($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X2);
    // 0x8040FF74: sh          $t5, -0x3E($s0)
    MEM_H(-0X3E, ctx->r16) = ctx->r13;
    // 0x8040FF78: lh          $t6, 0x4($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X4);
    // 0x8040FF7C: sh          $t6, -0x3C($s0)
    MEM_H(-0X3C, ctx->r16) = ctx->r14;
    // 0x8040FF80: lh          $t7, 0xA($t0)
    ctx->r15 = MEM_H(ctx->r8, 0XA);
    // 0x8040FF84: sh          $t7, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r15;
    // 0x8040FF88: lh          $t8, 0xC($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XC);
    // 0x8040FF8C: sh          $t8, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r24;
    // 0x8040FF90: lh          $t9, 0xE($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XE);
    // 0x8040FF94: sh          $t9, -0x1C($s0)
    MEM_H(-0X1C, ctx->r16) = ctx->r25;
    // 0x8040FF98: lw          $t2, 0x39E8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X39E8);
    // 0x8040FF9C: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // 0x8040FFA0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8040FFA4: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8040FFA8: mflo        $t3
    ctx->r11 = lo;
    // 0x8040FFAC: addu        $t0, $a0, $t3
    ctx->r8 = ADD32(ctx->r4, ctx->r11);
    // 0x8040FFB0: lh          $t4, 0x0($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X0);
    // 0x8040FFB4: sh          $t4, -0x30($s0)
    MEM_H(-0X30, ctx->r16) = ctx->r12;
    // 0x8040FFB8: lh          $t5, 0x2($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X2);
    // 0x8040FFBC: sh          $t5, -0x2E($s0)
    MEM_H(-0X2E, ctx->r16) = ctx->r13;
    // 0x8040FFC0: lh          $t6, 0x4($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X4);
    // 0x8040FFC4: sh          $t6, -0x2C($s0)
    MEM_H(-0X2C, ctx->r16) = ctx->r14;
    // 0x8040FFC8: lh          $t7, 0xA($t0)
    ctx->r15 = MEM_H(ctx->r8, 0XA);
    // 0x8040FFCC: sh          $t7, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r15;
    // 0x8040FFD0: lh          $t8, 0xC($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XC);
    // 0x8040FFD4: sh          $t8, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r24;
    // 0x8040FFD8: lh          $t9, 0xE($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XE);
    // 0x8040FFDC: sh          $t9, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r25;
    // 0x8040FFE0: lw          $t2, 0x39E8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X39E8);
    // 0x8040FFE4: sltu        $at, $v0, $t2
    ctx->r1 = ctx->r2 < ctx->r10 ? 1 : 0;
    // 0x8040FFE8: bnel        $at, $zero, L_8040FF44
    if (ctx->r1 != 0) {
        // 0x8040FFEC: lw          $t8, 0x39E8($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X39E8);
            goto L_8040FF44;
    }
    goto skip_1;
    // 0x8040FFEC: lw          $t8, 0x39E8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X39E8);
    skip_1:
    // 0x8040FFF0: lw          $t3, 0x39E4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X39E4);
L_8040FFF4:
    // 0x8040FFF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8040FFF8: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x8040FFFC: bnel        $at, $zero, L_8040FF34
    if (ctx->r1 != 0) {
        // 0x80410000: lw          $t7, 0x39E8($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X39E8);
            goto L_8040FF34;
    }
    goto skip_2;
    // 0x80410000: lw          $t7, 0x39E8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X39E8);
    skip_2:
L_80410004:
    // 0x80410004: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80410008: jr          $ra
    // 0x8041000C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8041000C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8051A9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A9AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051A9B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8051A9B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8051A9B8: jal         0x8051A530
    // 0x8051A9BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8051A530(rdram, ctx);
        goto after_0;
    // 0x8051A9BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8051A9C0: jal         0x8051A8E0
    // 0x8051A9C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051A8E0(rdram, ctx);
        goto after_1;
    // 0x8051A9C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8051A9C8: beq         $v0, $zero, L_8051AA30
    if (ctx->r2 == 0) {
        // 0x8051A9CC: nop
    
            goto L_8051AA30;
    }
    // 0x8051A9CC: nop

    // 0x8051A9D0: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x8051A9D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8051A9D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8051A9DC: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x8051A9E0: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8051A9E4: bne         $at, $zero, L_8051A9FC
    if (ctx->r1 != 0) {
        // 0x8051A9E8: sw          $v0, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r2;
            goto L_8051A9FC;
    }
    // 0x8051A9E8: sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
    // 0x8051A9EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8051A9F0: jal         0x8051ADC0
    // 0x8051A9F4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8051ADC0(rdram, ctx);
        goto after_2;
    // 0x8051A9F4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8051A9F8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8051A9FC:
    // 0x8051A9FC: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8051AA00: bne         $at, $zero, L_8051AA30
    if (ctx->r1 != 0) {
        // 0x8051AA04: nop
    
            goto L_8051AA30;
    }
    // 0x8051AA04: nop

    // 0x8051AA08: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x8051AA0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8051AA10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8051AA14: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8051AA18: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8051AA1C: bne         $t9, $zero, L_8051AA30
    if (ctx->r25 != 0) {
        // 0x8051AA20: nop
    
            goto L_8051AA30;
    }
    // 0x8051AA20: nop

    // 0x8051AA24: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8051AA28: jal         0x8051ADC0
    // 0x8051AA2C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8051ADC0(rdram, ctx);
        goto after_3;
    // 0x8051AA2C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
L_8051AA30:
    // 0x8051AA30: jal         0x8051A95C
    // 0x8051AA34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051A95C(rdram, ctx);
        goto after_4;
    // 0x8051AA34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8051AA38: jal         0x8051A568
    // 0x8051AA3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051A568(rdram, ctx);
        goto after_5;
    // 0x8051AA3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8051AA40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8051AA44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8051AA48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051AA4C: jr          $ra
    // 0x8051AA50: nop

    return;
    // 0x8051AA50: nop

;}
RECOMP_FUNC void func_8079FE34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079FE34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8079FE38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079FE3C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8079FE40: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079FE44: jal         0x8004700C
    // 0x8079FE48: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8079FE48: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8079FE4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8079FE50: lw          $t7, 0x14($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14);
    // 0x8079FE54: lhu         $v1, 0xC($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0XC);
    // 0x8079FE58: addiu       $t8, $v1, -0x46DB
    ctx->r24 = ADD32(ctx->r3, -0X46DB);
    // 0x8079FE5C: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x8079FE60: beq         $at, $zero, L_8079FEC0
    if (ctx->r1 == 0) {
        // 0x8079FE64: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8079FEC0;
    }
    // 0x8079FE64: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8079FE68: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(838, 0X16E8) << 16);
    // 0x8079FE6C: addu        $at, $at, $t8
    gpr jr_addend_8079FE74 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8079FE70: lw          $t8, 0xD48($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(838, 0X16E8));
    // 0x8079FE74: jr          $t8
    // 0x8079FE78: nop

    switch (jr_addend_8079FE74 >> 2) {
        case 0: goto L_8079FE7C; break;
        case 1: goto L_8079FE94; break;
        case 2: goto L_8079FEAC; break;
        case 3: goto L_8079FE7C; break;
        case 4: goto L_8079FE94; break;
        case 5: goto L_8079FEAC; break;
        default: switch_error(__func__, 0x8079FE74, 0x807A0D48);
    }
    // 0x8079FE78: nop

L_8079FE7C:
    // 0x8079FE7C: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(838, 0X16A8) << 16);
    // 0x8079FE80: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
    // 0x8079FE84: addiu       $t9, $t9, 0xD08
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(838, 0X16A8));
    // 0x8079FE88: sw          $t9, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r25;
    // 0x8079FE8C: b           L_8079FEC0
    // 0x8079FE90: lhu         $v1, 0xC($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0XC);
        goto L_8079FEC0;
    // 0x8079FE90: lhu         $v1, 0xC($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0XC);
L_8079FE94:
    // 0x8079FE94: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(838, 0X16AC) << 16);
    // 0x8079FE98: lw          $t2, 0x14($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X14);
    // 0x8079FE9C: addiu       $t1, $t1, 0xD0C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(838, 0X16AC));
    // 0x8079FEA0: sw          $t1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r9;
    // 0x8079FEA4: b           L_8079FEC0
    // 0x8079FEA8: lhu         $v1, 0xC($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0XC);
        goto L_8079FEC0;
    // 0x8079FEA8: lhu         $v1, 0xC($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0XC);
L_8079FEAC:
    // 0x8079FEAC: lw          $t4, 0x14($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X14);
    // 0x8079FEB0: lui         $t3, 0x807A
    ctx->r11 = S32(RELOC_HI16(838, 0X16B0) << 16);
    // 0x8079FEB4: addiu       $t3, $t3, 0xD10
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(838, 0X16B0));
    // 0x8079FEB8: sw          $t3, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r11;
    // 0x8079FEBC: lhu         $v1, 0xC($t4)
    ctx->r3 = MEM_HU(ctx->r12, 0XC);
L_8079FEC0:
    // 0x8079FEC0: addiu       $t5, $v1, -0x46DB
    ctx->r13 = ADD32(ctx->r3, -0X46DB);
    // 0x8079FEC4: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x8079FEC8: beq         $at, $zero, L_8079FEF8
    if (ctx->r1 == 0) {
        // 0x8079FECC: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8079FEF8;
    }
    // 0x8079FECC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8079FED0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(838, 0X1700) << 16);
    // 0x8079FED4: addu        $at, $at, $t5
    gpr jr_addend_8079FEDC = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8079FED8: lw          $t5, 0xD60($at)
    ctx->r13 = ADD32(ctx->r1, (int16_t)RELOC_LO16(838, 0X1700));
    // 0x8079FEDC: jr          $t5
    // 0x8079FEE0: nop

    switch (jr_addend_8079FEDC >> 2) {
        case 0: goto L_8079FEE4; break;
        case 1: goto L_8079FEE4; break;
        case 2: goto L_8079FEE4; break;
        case 3: goto L_8079FEF0; break;
        case 4: goto L_8079FEF0; break;
        case 5: goto L_8079FEF0; break;
        default: switch_error(__func__, 0x8079FEDC, 0x807A0D60);
    }
    // 0x8079FEE0: nop

L_8079FEE4:
    // 0x8079FEE4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8079FEE8: b           L_8079FEF8
    // 0x8079FEEC: sb          $t6, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r14;
        goto L_8079FEF8;
    // 0x8079FEEC: sb          $t6, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r14;
L_8079FEF0:
    // 0x8079FEF0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8079FEF4: sb          $t7, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r15;
L_8079FEF8:
    // 0x8079FEF8: beq         $v0, $zero, L_8079FF2C
    if (ctx->r2 == 0) {
        // 0x8079FEFC: sb          $zero, 0x1C($a1)
        MEM_B(0X1C, ctx->r5) = 0;
            goto L_8079FF2C;
    }
    // 0x8079FEFC: sb          $zero, 0x1C($a1)
    MEM_B(0X1C, ctx->r5) = 0;
    // 0x8079FF00: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8079FF04: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8079FF08: lwc1        $f6, 0x84($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X84);
    // 0x8079FF0C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8079FF10: nop

    // 0x8079FF14: bc1f        L_8079FF24
    if (!c1cs) {
        // 0x8079FF18: nop
    
            goto L_8079FF24;
    }
    // 0x8079FF18: nop

    // 0x8079FF1C: b           L_8079FF30
    // 0x8079FF20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8079FF30;
    // 0x8079FF20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8079FF24:
    // 0x8079FF24: b           L_8079FF30
    // 0x8079FF28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8079FF30;
    // 0x8079FF28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8079FF2C:
    // 0x8079FF2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8079FF30:
    // 0x8079FF30: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8079FF34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079FF38: jal         0x807A0380
    // 0x8079FF3C: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
    func_807A0380(rdram, ctx);
        goto after_1;
    // 0x8079FF3C: lbu         $a2, 0x1F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1F);
    after_1:
    // 0x8079FF40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8079FF44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079FF48: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8079FF4C: jal         0x8079F730
    // 0x8079FF50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8079F730(rdram, ctx);
        goto after_2;
    // 0x8079FF50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8079FF54: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8079FF58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079FF5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8079FF60: nop

    // 0x8079FF64: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x8079FF68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079FF6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8079FF70: jr          $ra
    // 0x8079FF74: nop

    return;
    // 0x8079FF74: nop

;}
RECOMP_FUNC void func_80071740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071748: jal         0x80071878
    // 0x8007174C: nop

    func_80071878(rdram, ctx);
        goto after_0;
    // 0x8007174C: nop

    after_0:
    // 0x80071750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071758: jr          $ra
    // 0x8007175C: nop

    return;
    // 0x8007175C: nop

;}
RECOMP_FUNC void func_8003837C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003837C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038384: jal         0x80021958
    // 0x80038388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80038388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003838C: bne         $v0, $zero, L_8003839C
    if (ctx->r2 != 0) {
        // 0x80038390: nop
    
            goto L_8003839C;
    }
    // 0x80038390: nop

    // 0x80038394: b           L_800383D0
    // 0x80038398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800383D0;
    // 0x80038398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003839C:
    // 0x8003839C: jal         0x800415FC
    // 0x800383A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x800383A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800383A4: beq         $v0, $zero, L_800383B4
    if (ctx->r2 == 0) {
        // 0x800383A8: nop
    
            goto L_800383B4;
    }
    // 0x800383A8: nop

    // 0x800383AC: b           L_800383D0
    // 0x800383B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800383D0;
    // 0x800383B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800383B4:
    // 0x800383B4: jal         0x80037D88
    // 0x800383B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80037D88(rdram, ctx);
        goto after_2;
    // 0x800383B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800383BC: bnel        $v0, $zero, L_800383D0
    if (ctx->r2 != 0) {
        // 0x800383C0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800383D0;
    }
    goto skip_0;
    // 0x800383C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800383C4: b           L_800383D0
    // 0x800383C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800383D0;
    // 0x800383C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800383CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800383D0:
    // 0x800383D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800383D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800383D8: jr          $ra
    // 0x800383DC: nop

    return;
    // 0x800383DC: nop

;}
RECOMP_FUNC void func_8066A410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A418: jal         0x80669E80
    // 0x8066A41C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80669E80(rdram, ctx);
        goto after_0;
    // 0x8066A41C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066A420: jal         0x80669FA4
    // 0x8066A424: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80669FA4(rdram, ctx);
        goto after_1;
    // 0x8066A424: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8066A428: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066A42C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8066A430: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8066A434: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8066A438: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8066A43C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A440: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8066A444: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8066A448: bc1fl       L_8066A460
    if (!c1cs) {
        // 0x8066A44C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A460;
    }
    goto skip_0;
    // 0x8066A44C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066A450: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8066A454: jal         0x8066A790
    // 0x8066A458: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8066A790(rdram, ctx);
        goto after_2;
    // 0x8066A458: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
    // 0x8066A45C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A460:
    // 0x8066A460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A464: jr          $ra
    // 0x8066A468: nop

    return;
    // 0x8066A468: nop

;}
RECOMP_FUNC void func_8003AF4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AF4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003AF50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AF54: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8003AF58: jal         0x8003AF20
    // 0x8003AF5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8003AF20(rdram, ctx);
        goto after_0;
    // 0x8003AF5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003AF60: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003AF64: addiu       $t6, $zero, 0x112
    ctx->r14 = ADD32(0, 0X112);
    // 0x8003AF68: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8003AF6C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003AF70: addiu       $t8, $t8, -0x6030
    ctx->r24 = ADD32(ctx->r24, -0X6030);
    // 0x8003AF74: sh          $t6, 0x4C($t7)
    MEM_H(0X4C, ctx->r15) = ctx->r14;
    // 0x8003AF78: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003AF7C: sw          $t8, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r24;
    // 0x8003AF80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AF84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003AF88: jr          $ra
    // 0x8003AF8C: nop

    return;
    // 0x8003AF8C: nop

;}
RECOMP_FUNC void func_80559928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80559928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8055992C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80559930: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80559934: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80559938: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8055993C: sb          $a3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r7;
    // 0x80559940: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x80559944: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x80559948: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8055994C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80559950: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x80559954: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80559958: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8055995C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80559960: lui         $t2, 0x8056
    ctx->r10 = S32(RELOC_HI16(363, 0X9488) << 16);
    // 0x80559964: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80559968: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8055996C: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x80559970: lw          $t2, 0xFD8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(363, 0X9488));
    // 0x80559974: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x80559978: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8055997C: jal         0x805598AC
    // 0x80559980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805598AC(rdram, ctx);
        goto after_0;
    // 0x80559980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80559984: jal         0x805581E0
    // 0x80559988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805581E0(rdram, ctx);
        goto after_1;
    // 0x80559988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8055998C: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x80559990: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80559994: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80559998: bnel        $t3, $at, L_805599D0
    if (ctx->r11 != ctx->r1) {
        // 0x8055999C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805599D0;
    }
    goto skip_0;
    // 0x8055999C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805599A0: jal         0x80557B60
    // 0x805599A4: addiu       $a1, $zero, 0x286
    ctx->r5 = ADD32(0, 0X286);
    func_80557B60(rdram, ctx);
        goto after_2;
    // 0x805599A4: addiu       $a1, $zero, 0x286
    ctx->r5 = ADD32(0, 0X286);
    after_2:
    // 0x805599A8: addiu       $t4, $zero, 0x46
    ctx->r12 = ADD32(0, 0X46);
    // 0x805599AC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805599B0: sb          $t4, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r12;
    // 0x805599B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805599B8: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x805599BC: sb          $t5, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r13;
    // 0x805599C0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805599C4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x805599C8: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    // 0x805599CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805599D0:
    // 0x805599D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805599D4: jr          $ra
    // 0x805599D8: nop

    return;
    // 0x805599D8: nop

    // 0x805599DC: nop

;}
RECOMP_FUNC void func_80400B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400B50: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80400B54: lui         $t6, 0x8040
    ctx->r14 = S32(RELOC_HI16(8, 0X75CC) << 16);
    // 0x80400B58: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80400B5C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80400B60: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80400B64: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80400B68: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80400B6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80400B70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80400B74: addiu       $t6, $t6, 0x760C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(8, 0X75CC));
    // 0x80400B78: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80400B7C: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
    // 0x80400B80: lui         $t9, 0x8040
    ctx->r25 = S32(RELOC_HI16(8, 0X75E4) << 16);
    // 0x80400B84: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80400B88: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80400B8C: addiu       $t9, $t9, 0x7624
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(8, 0X75E4));
    // 0x80400B90: addiu       $s4, $sp, 0x34
    ctx->r20 = ADD32(ctx->r29, 0X34);
    // 0x80400B94: sw          $t7, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r15;
    // 0x80400B98: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80400B9C: addiu       $s1, $a0, 0xF4
    ctx->r17 = ADD32(ctx->r4, 0XF4);
    // 0x80400BA0: addiu       $s0, $a0, 0x114
    ctx->r16 = ADD32(ctx->r4, 0X114);
    // 0x80400BA4: sw          $t8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r24;
    // 0x80400BA8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80400BAC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80400BB0: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80400BB4: sw          $t7, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r15;
    // 0x80400BB8: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x80400BBC: sw          $t8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r24;
    // 0x80400BC0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80400BC4: sw          $t7, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r15;
    // 0x80400BC8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80400BCC: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
    // 0x80400BD0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80400BD4: sw          $t0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r8;
    // 0x80400BD8: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80400BDC: sw          $t1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r9;
    // 0x80400BE0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80400BE4: sw          $t0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r8;
    // 0x80400BE8: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x80400BEC: sw          $t1, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->r9;
    // 0x80400BF0: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x80400BF4: sw          $t0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->r8;
L_80400BF8:
    // 0x80400BF8: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80400BFC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80400C00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80400C04: addu        $t2, $s4, $v0
    ctx->r10 = ADD32(ctx->r20, ctx->r2);
    // 0x80400C08: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80400C0C: addu        $t5, $s3, $v0
    ctx->r13 = ADD32(ctx->r19, ctx->r2);
    // 0x80400C10: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x80400C14: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80400C18: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    // 0x80400C1C: jalr        $t9
    // 0x80400C20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80400C20: nop

    after_0:
    // 0x80400C24: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80400C28: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80400C2C: bne         $s2, $s5, L_80400BF8
    if (ctx->r18 != ctx->r21) {
        // 0x80400C30: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80400BF8;
    }
    // 0x80400C30: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80400C34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80400C38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80400C3C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80400C40: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80400C44: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80400C48: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80400C4C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80400C50: jr          $ra
    // 0x80400C54: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80400C54: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8064BAD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BAD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BAD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BADC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064BAE0: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064BAE4: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x8064BAE8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064BAEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064BAF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064BAF4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064BAF8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8064BAFC: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064BB00: nop

    // 0x8064BB04: bc1fl       L_8064BB18
    if (!c1cs) {
        // 0x8064BB08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064BB18;
    }
    goto skip_0;
    // 0x8064BB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064BB0C: jal         0x8064BF74
    // 0x8064BB10: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064BF74(rdram, ctx);
        goto after_0;
    // 0x8064BB10: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064BB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064BB18:
    // 0x8064BB18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BB1C: jr          $ra
    // 0x8064BB20: nop

    return;
    // 0x8064BB20: nop

;}
RECOMP_FUNC void func_8046818C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046818C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80468190: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80468194: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80468198: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046819C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804681A0: addiu       $a1, $a2, 0x84
    ctx->r5 = ADD32(ctx->r6, 0X84);
    // 0x804681A4: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x804681A8: sb          $zero, 0x165($t6)
    MEM_B(0X165, ctx->r14) = 0;
    // 0x804681AC: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x804681B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x804681B4: jal         0x80065490
    // 0x804681B8: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x804681B8: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_0:
    // 0x804681BC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x804681C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804681C4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804681C8: sb          $t7, 0x165($t8)
    MEM_B(0X165, ctx->r24) = ctx->r15;
    // 0x804681CC: lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X10);
    // 0x804681D0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804681D4: sw          $t9, 0x130($t0)
    MEM_W(0X130, ctx->r8) = ctx->r25;
    // 0x804681D8: jal         0x80049018
    // 0x804681DC: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_80049018(rdram, ctx);
        goto after_1;
    // 0x804681DC: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_1:
    // 0x804681E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x804681E4: jal         0x80049018
    // 0x804681E8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x804681E8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_2:
    // 0x804681EC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x804681F0: bnel        $v0, $t1, L_80468210
    if (ctx->r2 != ctx->r9) {
        // 0x804681F4: lw          $t4, 0xC($s0)
        ctx->r12 = MEM_W(ctx->r16, 0XC);
            goto L_80468210;
    }
    goto skip_0;
    // 0x804681F4: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x804681F8: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x804681FC: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x80468200: lwc1        $f4, 0x50($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X50);
    // 0x80468204: b           L_80468220
    // 0x80468208: swc1        $f4, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f4.u32l;
        goto L_80468220;
    // 0x80468208: swc1        $f4, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f4.u32l;
    // 0x8046820C: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
L_80468210:
    // 0x80468210: lw          $t5, 0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X10);
    // 0x80468214: lwc1        $f6, 0x50($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X50);
    // 0x80468218: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8046821C: swc1        $f8, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f8.u32l;
L_80468220:
    // 0x80468220: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80468224: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80468228: beql        $v0, $a0, L_80468244
    if (ctx->r2 == ctx->r4) {
        // 0x8046822C: lh          $t6, 0x16($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X16);
            goto L_80468244;
    }
    goto skip_1;
    // 0x8046822C: lh          $t6, 0x16($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16);
    skip_1:
    // 0x80468230: jal         0x800447C8
    // 0x80468234: nop

    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x80468234: nop

    after_3:
    // 0x80468238: b           L_80468254
    // 0x8046823C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80468254;
    // 0x8046823C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80468240: lh          $t6, 0x16($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16);
L_80468244:
    // 0x80468244: sh          $t6, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r14;
    // 0x80468248: jal         0x800447C8
    // 0x8046824C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x8046824C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80468250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80468254:
    // 0x80468254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80468258: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8046825C: jr          $ra
    // 0x80468260: nop

    return;
    // 0x80468260: nop

;}
RECOMP_FUNC void func_80670748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067074C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80670750: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80670754: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80670758: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8067075C: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(520, 0X710) << 16);
    // 0x80670760: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80670764: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80670768: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8067076C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80670770: lw          $t8, 0x990($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(520, 0X710));
    // 0x80670774: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80670778: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8067077C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80670780: jal         0x80048490
    // 0x80670784: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80670784: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80670788: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8067078C: jal         0x80048378
    // 0x80670790: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80670790: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80670794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80670798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067079C: jr          $ra
    // 0x806707A0: nop

    return;
    // 0x806707A0: nop

;}
RECOMP_FUNC void guMtxCatF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B3E0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8008B3E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8008B3E8: addiu       $v1, $sp, 0x1C
    ctx->r3 = ADD32(ctx->r29, 0X1C);
    // 0x8008B3EC: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
    // 0x8008B3F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8008B3F4: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8008B3F8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_8008B3FC:
    // 0x8008B3FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008B400: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8008B404: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x8008B408: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8008B40C: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8008B410: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8008B414: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008B418: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8008B41C: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8008B420: beql        $a0, $t2, L_8008B4A4
    if (ctx->r4 == ctx->r10) {
        // 0x8008B424: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_8008B4A4;
    }
    goto skip_0;
    // 0x8008B424: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x8008B428: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_8008B42C:
    // 0x8008B42C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8008B430: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008B434: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8008B438: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8008B43C: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8008B440: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8008B444: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8008B448: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8008B44C: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8008B450: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x8008B454: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8008B458: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8008B45C: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8008B460: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8008B464: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8008B468: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8008B46C: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8008B470: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x8008B474: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8008B478: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8008B47C: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8008B480: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8008B484: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8008B488: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8008B48C: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8008B490: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8008B494: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8008B498: bnel        $a0, $t2, L_8008B42C
    if (ctx->r4 != ctx->r10) {
        // 0x8008B49C: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_8008B42C;
    }
    goto skip_1;
    // 0x8008B49C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x8008B4A0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_8008B4A4:
    // 0x8008B4A4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008B4A8: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8008B4AC: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8008B4B0: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8008B4B4: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8008B4B8: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8008B4BC: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8008B4C0: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8008B4C4: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x8008B4C8: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8008B4CC: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8008B4D0: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8008B4D4: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8008B4D8: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8008B4DC: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8008B4E0: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x8008B4E4: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8008B4E8: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8008B4EC: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8008B4F0: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8008B4F4: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8008B4F8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8008B4FC: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x8008B500: bne         $at, $zero, L_8008B3FC
    if (ctx->r1 != 0) {
        // 0x8008B504: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8008B3FC;
    }
    // 0x8008B504: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8008B508: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8008B50C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8008B510: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
L_8008B514:
    // 0x8008B514: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8008B518: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8008B51C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8008B520: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x8008B524: lwc1        $f8, -0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, -0XC);
    // 0x8008B528: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x8008B52C: lwc1        $f16, -0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8008B530: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x8008B534: lwc1        $f10, -0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X4);
    // 0x8008B538: bne         $a0, $v0, L_8008B514
    if (ctx->r4 != ctx->r2) {
        // 0x8008B53C: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_8008B514;
    }
    // 0x8008B53C: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8008B540: jr          $ra
    // 0x8008B544: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8008B544: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80445CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445CBC: jr          $ra
    // 0x80445CC0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    return;
    // 0x80445CC0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
;}
RECOMP_FUNC void func_80677958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80677958: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067795C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80677960: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80677964: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80677968: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(535, 0X2530) << 16);
    // 0x8067796C: addiu       $t6, $t6, 0x7BF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(535, 0X2530));
    // 0x80677970: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80677974: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80677978: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8067797C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80677980: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80677984: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80677988: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8067798C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80677990: jal         0x80677AEC
    // 0x80677994: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80677AEC(rdram, ctx);
        goto after_0;
    // 0x80677994: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80677998: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8067799C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806779A0: jal         0x80045A34
    // 0x806779A4: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x806779A4: addiu       $a1, $zero, 0x40C
    ctx->r5 = ADD32(0, 0X40C);
    after_1:
    // 0x806779A8: bne         $v0, $zero, L_806779C0
    if (ctx->r2 != 0) {
        // 0x806779AC: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_806779C0;
    }
    // 0x806779AC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806779B0: jal         0x800445A4
    // 0x806779B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x806779B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806779B8: b           L_80677A78
    // 0x806779BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80677A78;
    // 0x806779BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806779C0:
    // 0x806779C0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x806779C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806779C8: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806779CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806779D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806779D4: jal         0x80677674
    // 0x806779D8: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    func_80677674(rdram, ctx);
        goto after_3;
    // 0x806779D8: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x806779DC: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x806779E0: lui         $t9, 0x8067
    ctx->r25 = S32(RELOC_HI16(535, 0X47C) << 16);
    // 0x806779E4: addiu       $t9, $t9, 0x5B3C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(535, 0X47C));
    // 0x806779E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806779EC: jal         0x80677594
    // 0x806779F0: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_80677594(rdram, ctx);
        goto after_4;
    // 0x806779F0: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_4:
    // 0x806779F4: jal         0x80047090
    // 0x806779F8: addiu       $a0, $zero, 0x4560
    ctx->r4 = ADD32(0, 0X4560);
    func_80047090(rdram, ctx);
        goto after_5;
    // 0x806779F8: addiu       $a0, $zero, 0x4560
    ctx->r4 = ADD32(0, 0X4560);
    after_5:
    // 0x806779FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80677A00: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x80677A04: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x80677A08: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x80677A0C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80677A10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80677A14: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80677A18: lui         $a0, 0x4560
    ctx->r4 = S32(0X4560 << 16);
    // 0x80677A1C: jal         0x8004613C
    // 0x80677A20: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    func_8004613C(rdram, ctx);
        goto after_6;
    // 0x80677A20: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_6:
    // 0x80677A24: beq         $v0, $zero, L_80677A6C
    if (ctx->r2 == 0) {
        // 0x80677A28: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80677A6C;
    }
    // 0x80677A28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80677A2C: lhu         $t3, 0x2A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2A);
    // 0x80677A30: lhu         $t5, 0xE($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XE);
    // 0x80677A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80677A38: andi        $t4, $t3, 0x3FF
    ctx->r12 = ctx->r11 & 0X3FF;
    // 0x80677A3C: andi        $t6, $t5, 0xFC00
    ctx->r14 = ctx->r13 & 0XFC00;
    // 0x80677A40: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80677A44: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
    // 0x80677A48: jal         0x80047F9C
    // 0x80677A4C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x80677A4C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_7:
    // 0x80677A50: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80677A54: sb          $zero, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = 0;
    // 0x80677A58: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80677A5C: jal         0x8005FDC4
    // 0x80677A60: sw          $a0, 0x404($t8)
    MEM_W(0X404, ctx->r24) = ctx->r4;
    func_8005FDC4(rdram, ctx);
        goto after_8;
    // 0x80677A60: sw          $a0, 0x404($t8)
    MEM_W(0X404, ctx->r24) = ctx->r4;
    after_8:
    // 0x80677A64: b           L_80677A78
    // 0x80677A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80677A78;
    // 0x80677A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80677A6C:
    // 0x80677A6C: jal         0x800445A4
    // 0x80677A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x80677A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80677A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80677A78:
    // 0x80677A78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80677A7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80677A80: jr          $ra
    // 0x80677A84: nop

    return;
    // 0x80677A84: nop

;}
RECOMP_FUNC void func_8007FDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FDC4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8007FDC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007FDCC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8007FDD0: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8007FDD4: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8007FDD8: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8007FDDC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8007FDE0: jal         0x800818E8
    // 0x8007FDE4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    MtxConv_L2F(rdram, ctx);
        goto after_0;
    // 0x8007FDE4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8007FDE8: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007FDEC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8007FDF0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8007FDF4: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8007FDF8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8007FDFC: jal         0x80080914
    // 0x8007FE00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80080914(rdram, ctx);
        goto after_1;
    // 0x8007FE00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8007FE04: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8007FE08: jal         0x800817A0
    // 0x8007FE0C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    MtxConv_F2L(rdram, ctx);
        goto after_2;
    // 0x8007FE0C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x8007FE10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007FE14: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8007FE18: jr          $ra
    // 0x8007FE1C: nop

    return;
    // 0x8007FE1C: nop

;}
RECOMP_FUNC void func_804F5830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F5830: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804F5834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F5838: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F583C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804F5840: jal         0x804F4F50
    // 0x804F5844: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804F4F50(rdram, ctx);
        goto after_0;
    // 0x804F5844: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804F5848: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804F584C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804F5850: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x804F5854: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x804F5858: slti        $at, $v1, 0x29
    ctx->r1 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x804F585C: bne         $at, $zero, L_804F5874
    if (ctx->r1 != 0) {
        // 0x804F5860: sw          $v1, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r3;
            goto L_804F5874;
    }
    // 0x804F5860: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x804F5864: jal         0x804F59B4
    // 0x804F5868: nop

    func_804F59B4(rdram, ctx);
        goto after_1;
    // 0x804F5868: nop

    after_1:
    // 0x804F586C: b           L_804F5890
    // 0x804F5870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804F5890;
    // 0x804F5870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F5874:
    // 0x804F5874: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x804F5878: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x804F587C: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x804F5880: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804F5884: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x804F5888: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x804F588C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804F5890:
    // 0x804F5890: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804F5894: jr          $ra
    // 0x804F5898: nop

    return;
    // 0x804F5898: nop

;}
RECOMP_FUNC void func_8057F644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057F648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F64C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8057F650: jal         0x80045A34
    // 0x8057F654: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8057F654: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    after_0:
    // 0x8057F658: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8057F65C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8057F660: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // 0x8057F664: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8057F668: jal         0x800657CC
    // 0x8057F66C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x8057F66C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    after_1:
    // 0x8057F670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057F678: jr          $ra
    // 0x8057F67C: nop

    return;
    // 0x8057F67C: nop

;}
RECOMP_FUNC void func_805A446C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A446C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A4470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A4474: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805A4478: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(414, 0X1D40) << 16);
    // 0x805A447C: addiu       $t6, $t6, 0x50D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(414, 0X1D40));
    // 0x805A4480: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x805A4484: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805A4488: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805A448C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805A4490: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805A4494: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805A4498: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A449C: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x805A44A0: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805A44A4: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805A44A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A44AC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x805A44B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805A44B4: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x805A44B8: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x805A44BC: swc1        $f10, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f10.u32l;
    // 0x805A44C0: jal         0x805A4678
    // 0x805A44C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A4678(rdram, ctx);
        goto after_0;
    // 0x805A44C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A44C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A44CC: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(414, 0X440) << 16);
    // 0x805A44D0: addiu       $t9, $t9, 0x37D0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(414, 0X440));
    // 0x805A44D4: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x805A44D8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805A44DC: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x805A44E0: jal         0x80045A34
    // 0x805A44E4: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x805A44E4: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_1:
    // 0x805A44E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A44EC: jal         0x805A40C8
    // 0x805A44F0: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    func_805A40C8(rdram, ctx);
        goto after_2;
    // 0x805A44F0: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    after_2:
    // 0x805A44F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A44F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A44FC: jr          $ra
    // 0x805A4500: nop

    return;
    // 0x805A4500: nop

;}
RECOMP_FUNC void func_8003AE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AE00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003AE04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AE08: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003AE0C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8003AE10: bnel        $a3, $zero, L_8003AE30
    if (ctx->r7 != 0) {
        // 0x8003AE14: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8003AE30;
    }
    goto skip_0;
    // 0x8003AE14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x8003AE18: jal         0x80045A34
    // 0x8003AE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8003AE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003AE20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003AE24: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8003AE28: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8003AE2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8003AE30:
    // 0x8003AE30: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8003AE34: jal         0x800657CC
    // 0x8003AE38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x8003AE38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8003AE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AE40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003AE44: jr          $ra
    // 0x8003AE48: nop

    return;
    // 0x8003AE48: nop

;}
RECOMP_FUNC void func_805A071C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A071C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A0720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A0724: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805A0728: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805A072C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805A0730: lui         $t8, 0x805A
    ctx->r24 = S32(RELOC_HI16(408, 0X1D94) << 16);
    // 0x805A0734: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805A0738: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805A073C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805A0740: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805A0744: lw          $t8, 0x10F4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(408, 0X1D94));
    // 0x805A0748: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805A074C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805A0750: jal         0x80048490
    // 0x805A0754: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805A0754: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805A0758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A075C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A0760: jr          $ra
    // 0x805A0764: nop

    return;
    // 0x805A0764: nop

;}
RECOMP_FUNC void func_80408254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80408254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80408258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040825C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80408260: jal         0x80045A34
    // 0x80408264: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80408264: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80408268: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8040826C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x80408270: bne         $v0, $zero, L_80408280
    if (ctx->r2 != 0) {
        // 0x80408274: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80408280;
    }
    // 0x80408274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80408278: b           L_80408284
    // 0x8040827C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80408284;
    // 0x8040827C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80408280:
    // 0x80408280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80408284:
    // 0x80408284: jr          $ra
    // 0x80408288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80408288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8041FED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041FED4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8041FED8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041FEDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041FEE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041FEE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8041FEE8: jal         0x80047090
    // 0x8041FEEC: addiu       $a0, $zero, 0x45CB
    ctx->r4 = ADD32(0, 0X45CB);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8041FEEC: addiu       $a0, $zero, 0x45CB
    ctx->r4 = ADD32(0, 0X45CB);
    after_0:
    // 0x8041FEF0: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8041FEF4: beq         $v0, $at, L_8041FF68
    if (ctx->r2 == ctx->r1) {
        // 0x8041FEF8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8041FF68;
    }
    // 0x8041FEF8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8041FEFC: lui         $at, 0x45CB
    ctx->r1 = S32(0X45CB << 16);
    // 0x8041FF00: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8041FF04: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x8041FF08: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8041FF0C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8041FF10: jal         0x8004613C
    // 0x8041FF14: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8041FF14: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x8041FF18: beq         $v0, $zero, L_8041FF68
    if (ctx->r2 == 0) {
        // 0x8041FF1C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8041FF68;
    }
    // 0x8041FF1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8041FF20: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8041FF24: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8041FF28: lw          $t6, 0xE70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XE70);
    // 0x8041FF2C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8041FF30: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x8041FF34: lw          $t7, 0xE70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XE70);
    // 0x8041FF38: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8041FF3C: swc1        $f6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f6.u32l;
    // 0x8041FF40: lw          $t8, 0xE70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE70);
    // 0x8041FF44: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8041FF48: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x8041FF4C: lw          $t0, 0xE70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE70);
    // 0x8041FF50: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8041FF54: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8041FF58: jal         0x80044194
    // 0x8041FF5C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8041FF5C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8041FF60: b           L_8041FF6C
    // 0x8041FF64: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_8041FF6C;
    // 0x8041FF64: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8041FF68:
    // 0x8041FF68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8041FF6C:
    // 0x8041FF6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041FF70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041FF74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8041FF78: jr          $ra
    // 0x8041FF7C: nop

    return;
    // 0x8041FF7C: nop

;}
RECOMP_FUNC void func_805AA2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA2F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AA2F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AA2F8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x805AA2FC: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x805AA300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA304: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x805AA308: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x805AA30C: lui         $a2, 0x805B
    ctx->r6 = S32(RELOC_HI16(432, 0X928) << 16);
    // 0x805AA310: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x805AA314: bnel        $t7, $zero, L_805AA328
    if (ctx->r15 != 0) {
        // 0x805AA318: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AA328;
    }
    goto skip_0;
    // 0x805AA318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805AA31C: jal         0x80057B28
    // 0x805AA320: addiu       $a2, $a2, -0x53E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(432, 0X928));
    func_80057B28(rdram, ctx);
        goto after_0;
    // 0x805AA320: addiu       $a2, $a2, -0x53E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(432, 0X928));
    after_0:
    // 0x805AA324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AA328:
    // 0x805AA328: lui         $v0, 0x805B
    ctx->r2 = S32(RELOC_HI16(432, 0X60) << 16);
    // 0x805AA32C: addiu       $v0, $v0, -0x5CB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(432, 0X60));
    // 0x805AA330: jr          $ra
    // 0x805AA334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805AA334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8046B210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046B210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046B214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046B218: jal         0x8046AF80
    // 0x8046B21C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8046AF80(rdram, ctx);
        goto after_0;
    // 0x8046B21C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046B220: jal         0x80045BD8
    // 0x8046B224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8046B224: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8046B228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046B22C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046B230: jr          $ra
    // 0x8046B234: nop

    return;
    // 0x8046B234: nop

;}
RECOMP_FUNC void func_80056F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056F40: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80056F44: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80056F48: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80056F4C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80056F50: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80056F54: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80056F58: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80056F5C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80056F60: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80056F64: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80056F68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80056F6C: lw          $t7, 0x1B0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1B0);
    // 0x80056F70: lw          $t6, 0x1CC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1CC);
    // 0x80056F74: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80056F78: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80056F7C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056F80: lw          $t7, 0x1B8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1B8);
    // 0x80056F84: lw          $t6, 0x1BC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1BC);
    // 0x80056F88: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80056F8C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80056F90: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x80056F94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056F98: mflo        $t8
    ctx->r24 = lo;
    // 0x80056F9C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80056FA0: addu        $s2, $a0, $t9
    ctx->r18 = ADD32(ctx->r4, ctx->r25);
    // 0x80056FA4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056FA8: mflo        $t8
    ctx->r24 = lo;
    // 0x80056FAC: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80056FB0: lw          $t6, 0x1C0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C0);
    // 0x80056FB4: lw          $t9, 0x1C4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C4);
    // 0x80056FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80056FBC: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056FC0: lui         $t6, 0x1F
    ctx->r14 = S32(0X1F << 16);
    // 0x80056FC4: ori         $t6, $t6, 0x3205
    ctx->r14 = ctx->r14 | 0X3205;
    // 0x80056FC8: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x80056FCC: mflo        $t7
    ctx->r15 = lo;
    // 0x80056FD0: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
    // 0x80056FD4: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80056FD8: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80056FDC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80056FE0: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80056FE4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80056FE8: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80056FEC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80056FF0: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80056FF4: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80056FF8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80056FFC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80057000: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80057004: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057008: ori         $t7, $zero, 0xAC80
    ctx->r15 = 0 | 0XAC80;
    // 0x8005700C: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x80057010: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80057014: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80057018: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8005701C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80057020: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057024: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80057028: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x8005702C: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80057030: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80057034: ori         $a1, $a1, 0x4340
    ctx->r5 = ctx->r5 | 0X4340;
    // 0x80057038: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x8005703C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80057040: sw          $a1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r5;
    // 0x80057044: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057048: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8005704C: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80057050: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80057054: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80057058: sw          $a1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r5;
    // 0x8005705C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80057060: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057064: lui         $t6, 0xFF2F
    ctx->r14 = S32(0XFF2F << 16);
    // 0x80057068: lui         $t9, 0xFC12
    ctx->r25 = S32(0XFC12 << 16);
    // 0x8005706C: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80057070: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80057074: ori         $t9, $t9, 0x1624
    ctx->r25 = ctx->r25 | 0X1624;
    // 0x80057078: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x8005707C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80057080: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80057084: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057088: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8005708C: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x80057090: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80057094: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80057098: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8005709C: lbu         $t6, 0xEB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XEB);
    // 0x800570A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800570A4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800570A8: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800570AC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800570B0: addiu       $t6, $zero, 0x204
    ctx->r14 = ADD32(0, 0X204);
    // 0x800570B4: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800570B8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800570BC: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800570C0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800570C4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800570C8: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800570CC: lui         $t8, 0xBB00
    ctx->r24 = S32(0XBB00 << 16);
    // 0x800570D0: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x800570D4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800570D8: ori         $t8, $t8, 0x1
    ctx->r24 = ctx->r24 | 0X1;
    // 0x800570DC: ori         $t9, $t9, 0x8000
    ctx->r25 = ctx->r25 | 0X8000;
    // 0x800570E0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800570E4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800570E8: jal         0x8007711C
    // 0x800570EC: sw          $t4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r12;
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x800570EC: sw          $t4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r12;
    after_0:
    // 0x800570F0: lw          $t6, 0x1C8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C8);
    // 0x800570F4: lw          $t4, 0xD4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD4);
    // 0x800570F8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800570FC: blez        $t6, L_800574A0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80057100: lw          $v0, 0xC8($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XC8);
            goto L_800574A0;
    }
    // 0x80057100: lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC8);
    // 0x80057104: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80057108: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8005710C: sll         $t7, $v0, 10
    ctx->r15 = S32(ctx->r2 << 10);
    // 0x80057110: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80057114: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x80057118: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8005711C: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80057120: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80057124: lui         $fp, 0xFD50
    ctx->r30 = S32(0XFD50 << 16);
    // 0x80057128: lui         $s7, 0xF200
    ctx->r23 = S32(0XF200 << 16);
    // 0x8005712C: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
    // 0x80057130: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
    // 0x80057134: lui         $t3, 0xBF00
    ctx->r11 = S32(0XBF00 << 16);
L_80057138:
    // 0x80057138: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8005713C: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80057140: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80057144: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80057148: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005714C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80057150: sw          $s2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r18;
    // 0x80057154: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x80057158: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8005715C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057160: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x80057164: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80057168: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005716C: sw          $s5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r21;
    // 0x80057170: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80057174: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057178: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x8005717C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80057180: sw          $fp, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r30;
    // 0x80057184: sw          $s4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r20;
    // 0x80057188: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8005718C: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80057190: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80057194: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80057198: sw          $s6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r22;
    // 0x8005719C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800571A0: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800571A4: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800571A8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800571AC: sw          $s5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r21;
    // 0x800571B0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800571B4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800571B8: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x800571BC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800571C0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800571C4: lw          $t6, 0x1C4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C4);
    // 0x800571C8: lw          $v1, 0x1C0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C0);
    // 0x800571CC: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800571D0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800571D4: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800571D8: mflo        $a0
    ctx->r4 = lo;
    // 0x800571DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800571E0: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800571E4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800571E8: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x800571EC: beq         $at, $zero, L_800571FC
    if (ctx->r1 == 0) {
        // 0x800571F0: nop
    
            goto L_800571FC;
    }
    // 0x800571F0: nop

    // 0x800571F4: b           L_800571FC
    // 0x800571F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
        goto L_800571FC;
    // 0x800571F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_800571FC:
    // 0x800571FC: bgez        $v1, L_8005720C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80057200: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8005720C;
    }
    // 0x80057200: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80057204: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80057208: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8005720C:
    // 0x8005720C: bgtz        $v0, L_8005721C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80057210: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8005721C;
    }
    // 0x80057210: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80057214: b           L_8005721C
    // 0x80057218: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8005721C;
    // 0x80057218: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8005721C:
    // 0x8005721C: bgtz        $v0, L_8005722C
    if (SIGNED(ctx->r2) > 0) {
        // 0x80057220: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_8005722C;
    }
    // 0x80057220: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x80057224: b           L_80057230
    // 0x80057228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80057230;
    // 0x80057228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8005722C:
    // 0x8005722C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80057230:
    // 0x80057230: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x80057234: mflo        $t9
    ctx->r25 = lo;
    // 0x80057238: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8005723C: bne         $a1, $zero, L_80057248
    if (ctx->r5 != 0) {
        // 0x80057240: nop
    
            goto L_80057248;
    }
    // 0x80057240: nop

    // 0x80057244: break       7
    do_break(2147840580);
L_80057248:
    // 0x80057248: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005724C: bne         $a1, $at, L_80057260
    if (ctx->r5 != ctx->r1) {
        // 0x80057250: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80057260;
    }
    // 0x80057250: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80057254: bne         $t7, $at, L_80057260
    if (ctx->r15 != ctx->r1) {
        // 0x80057258: nop
    
            goto L_80057260;
    }
    // 0x80057258: nop

    // 0x8005725C: break       6
    do_break(2147840604);
L_80057260:
    // 0x80057260: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x80057264: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80057268: or          $t8, $t6, $s6
    ctx->r24 = ctx->r14 | ctx->r22;
    // 0x8005726C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80057270: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80057274: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057278: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8005727C: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80057280: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80057284: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80057288: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8005728C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80057290: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057294: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80057298: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005729C: lw          $t6, 0x1C0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C0);
    // 0x800572A0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800572A4: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800572A8: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800572AC: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800572B0: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x800572B4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800572B8: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800572BC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800572C0: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800572C4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800572C8: sw          $s7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r23;
    // 0x800572CC: lw          $t9, 0x1C4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C4);
    // 0x800572D0: lw          $t8, 0x1C0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C0);
    // 0x800572D4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800572D8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800572DC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800572E0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800572E4: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800572E8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800572EC: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800572F0: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800572F4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800572F8: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x800572FC: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80057300: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80057304: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80057308: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8005730C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80057310: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057314: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80057318: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005731C: lh          $t6, 0xA($s2)
    ctx->r14 = MEM_H(ctx->r18, 0XA);
    // 0x80057320: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80057324: srl         $t8, $t6, 7
    ctx->r24 = S32(U32(ctx->r14) >> 7);
    // 0x80057328: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8005732C: lh          $t8, 0x8($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X8);
    // 0x80057330: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80057334: or          $t6, $t9, $s7
    ctx->r14 = ctx->r25 | ctx->r23;
    // 0x80057338: srl         $t7, $t8, 7
    ctx->r15 = S32(U32(ctx->r24) >> 7);
    // 0x8005733C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80057340: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80057344: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80057348: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8005734C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80057350: lh          $t6, 0xA($s2)
    ctx->r14 = MEM_H(ctx->r18, 0XA);
    // 0x80057354: lw          $t8, 0x1C4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C4);
    // 0x80057358: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8005735C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80057360: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80057364: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    // 0x80057368: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8005736C: lw          $t6, 0x1C0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C0);
    // 0x80057370: srl         $t9, $t7, 7
    ctx->r25 = S32(U32(ctx->r15) >> 7);
    // 0x80057374: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80057378: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8005737C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80057380: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80057384: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80057388: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8005738C: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80057390: lw          $v1, 0x1BC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1BC);
    // 0x80057394: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80057398: blezl       $v1, L_80057478
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005739C: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_80057478;
    }
    goto skip_0;
    // 0x8005739C: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    skip_0:
    // 0x800573A0: lw          $v0, 0x1B8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1B8);
L_800573A4:
    // 0x800573A4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800573A8: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800573AC: blez        $t7, L_80057464
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800573B0: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80057464;
    }
    // 0x800573B0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800573B4: sll         $a3, $a2, 1
    ctx->r7 = S32(ctx->r6 << 1);
    // 0x800573B8: addiu       $t2, $a3, 0x2
    ctx->r10 = ADD32(ctx->r7, 0X2);
    // 0x800573BC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_800573C0:
    // 0x800573C0: andi        $v1, $t2, 0xFF
    ctx->r3 = ctx->r10 & 0XFF;
    // 0x800573C4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800573C8: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x800573CC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800573D0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800573D4: lw          $t9, 0x1B8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1B8);
    // 0x800573D8: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x800573DC: addu        $t6, $t9, $a2
    ctx->r14 = ADD32(ctx->r25, ctx->r6);
    // 0x800573E0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800573E4: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x800573E8: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800573EC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800573F0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800573F4: sll         $t9, $v1, 8
    ctx->r25 = S32(ctx->r3 << 8);
    // 0x800573F8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800573FC: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80057400: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80057404: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x80057408: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8005740C: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80057410: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80057414: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80057418: lw          $t7, 0x1B8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1B8);
    // 0x8005741C: addu        $a1, $t7, $a2
    ctx->r5 = ADD32(ctx->r15, ctx->r6);
    // 0x80057420: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80057424: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x80057428: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8005742C: addiu       $t7, $a1, 0x2
    ctx->r15 = ADD32(ctx->r5, 0X2);
    // 0x80057430: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80057434: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x80057438: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8005743C: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80057440: lw          $t9, 0x1B8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X1B8);
    // 0x80057444: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80057448: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8005744C: slt         $at, $t1, $t6
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80057450: bnel        $at, $zero, L_800573C0
    if (ctx->r1 != 0) {
        // 0x80057454: lw          $t0, 0x0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X0);
            goto L_800573C0;
    }
    goto skip_1;
    // 0x80057454: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80057458: lw          $v1, 0x1BC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1BC);
    // 0x8005745C: lw          $v0, 0x1B8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1B8);
    // 0x80057460: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80057464:
    // 0x80057464: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x80057468: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005746C: bne         $at, $zero, L_800573A4
    if (ctx->r1 != 0) {
        // 0x80057470: addu        $t5, $t5, $v0
        ctx->r13 = ADD32(ctx->r13, ctx->r2);
            goto L_800573A4;
    }
    // 0x80057470: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x80057474: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
L_80057478:
    // 0x80057478: lw          $t7, 0x1B8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1B8);
    // 0x8005747C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80057480: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x80057484: lw          $t7, 0x1C8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C8);
    // 0x80057488: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x8005748C: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x80057490: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80057494: addu        $s2, $s2, $t6
    ctx->r18 = ADD32(ctx->r18, ctx->r14);
    // 0x80057498: bne         $at, $zero, L_80057138
    if (ctx->r1 != 0) {
        // 0x8005749C: addu        $s4, $s4, $t8
        ctx->r20 = ADD32(ctx->r20, ctx->r24);
            goto L_80057138;
    }
    // 0x8005749C: addu        $s4, $s4, $t8
    ctx->r20 = ADD32(ctx->r20, ctx->r24);
L_800574A0:
    // 0x800574A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800574A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800574A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800574AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800574B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800574B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800574B8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800574BC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800574C0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800574C4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800574C8: jr          $ra
    // 0x800574CC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800574CC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_80030FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030FAC: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80030FB0: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80030FB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030FB8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80030FBC: nop

    // 0x80030FC0: bc1f        L_80030FD8
    if (!c1cs) {
        // 0x80030FC4: nop
    
            goto L_80030FD8;
    }
    // 0x80030FC4: nop

    // 0x80030FC8: jal         0x8002CB84
    // 0x80030FCC: nop

    func_8002CB84(rdram, ctx);
        goto after_0;
    // 0x80030FCC: nop

    after_0:
    // 0x80030FD0: b           L_80030FD8
    // 0x80030FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80030FD8;
    // 0x80030FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80030FD8:
    // 0x80030FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030FE0: jr          $ra
    // 0x80030FE4: nop

    return;
    // 0x80030FE4: nop

;}
RECOMP_FUNC void func_8041E408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041E40C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041E410: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041E414: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x8041E418: jal         0x80065728
    // 0x8041E41C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8041E41C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8041E420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041E424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041E428: jr          $ra
    // 0x8041E42C: nop

    return;
    // 0x8041E42C: nop

;}
RECOMP_FUNC void func_80463314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80463318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046331C: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80463320: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X39A4) << 16);
    // 0x80463324: addiu       $t8, $t8, 0x3F34
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(122, 0X39A4));
    // 0x80463328: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8046332C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80463330: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80463334: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80463338: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8046333C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80463340: beql        $v1, $zero, L_80463378
    if (ctx->r3 == 0) {
        // 0x80463344: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80463378;
    }
    goto skip_0;
    // 0x80463344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80463348: jalr        $v1
    // 0x8046334C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8046334C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80463350: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80463354: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x80463358: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x8046335C: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x80463360: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80463364: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x80463368: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8046336C: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80463370: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x80463374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80463378:
    // 0x80463378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046337C: jr          $ra
    // 0x80463380: nop

    return;
    // 0x80463380: nop

;}
RECOMP_FUNC void func_807B7C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B7C68: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x807B7C6C: lui         $t7, 0x807C
    ctx->r15 = S32(RELOC_HI16(883, 0X500) << 16);
    // 0x807B7C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B7C74: addiu       $t7, $t7, -0x7EC0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(883, 0X500));
    // 0x807B7C78: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x807B7C7C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B7C80: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x807B7C84: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x807B7C88: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x807B7C8C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x807B7C90: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807B7C94: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x807B7C98: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x807B7C9C: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x807B7CA0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807B7CA4: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x807B7CA8: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x807B7CAC: bne         $at, $zero, L_807B7CBC
    if (ctx->r1 != 0) {
        // 0x807B7CB0: sw          $v0, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->r2;
            goto L_807B7CBC;
    }
    // 0x807B7CB0: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x807B7CB4: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x807B7CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B7CBC:
    // 0x807B7CBC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x807B7CC0: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x807B7CC4: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x807B7CC8: beql        $a1, $zero, L_807B7CEC
    if (ctx->r5 == 0) {
        // 0x807B7CCC: lw          $t4, 0x18($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X18);
            goto L_807B7CEC;
    }
    goto skip_0;
    // 0x807B7CCC: lw          $t4, 0x18($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X18);
    skip_0:
    // 0x807B7CD0: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x807B7CD4: jal         0x80047EB0
    // 0x807B7CD8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    func_80047EB0(rdram, ctx);
        goto after_0;
    // 0x807B7CD8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    after_0:
    // 0x807B7CDC: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x807B7CE0: bne         $v0, $zero, L_807B7E08
    if (ctx->r2 != 0) {
        // 0x807B7CE4: lw          $a2, 0x58($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X58);
            goto L_807B7E08;
    }
    // 0x807B7CE4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x807B7CE8: lw          $t4, 0x18($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X18);
L_807B7CEC:
    // 0x807B7CEC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x807B7CF0: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x807B7CF4: lh          $a1, 0x1C($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X1C);
    // 0x807B7CF8: blez        $a1, L_807B7E08
    if (SIGNED(ctx->r5) <= 0) {
        // 0x807B7CFC: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_807B7E08;
    }
    // 0x807B7CFC: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x807B7D00: sh          $t6, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r14;
    // 0x807B7D04: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x807B7D08: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x807B7D0C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(883, 0X50C) << 16);
    // 0x807B7D10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B7D14: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x807B7D18: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x807B7D1C: lhu         $t9, 0x24($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X24);
    // 0x807B7D20: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x807B7D24: lw          $t5, -0x76F8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X76F8);
    // 0x807B7D28: sh          $t9, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r25;
    // 0x807B7D2C: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x807B7D30: lwc1        $f4, 0x6C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x807B7D34: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x807B7D38: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x807B7D3C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x807B7D40: lwc1        $f6, -0x7EB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(883, 0X50C));
    // 0x807B7D44: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(883, 0X524) << 16);
    // 0x807B7D48: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x807B7D4C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807B7D50: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x807B7D54: lw          $t2, 0x18($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X18);
    // 0x807B7D58: lwc1        $f10, 0x70($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X70);
    // 0x807B7D5C: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x807B7D60: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x807B7D64: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x807B7D68: lwc1        $f16, -0x7E9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(883, 0X524));
    // 0x807B7D6C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(883, 0X58C) << 16);
    // 0x807B7D70: lwc1        $f4, -0x7E34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(883, 0X58C));
    // 0x807B7D74: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x807B7D78: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x807B7D7C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x807B7D80: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x807B7D84: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x807B7D88: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x807B7D8C: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x807B7D90: lw          $t9, 0x54($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X54);
    // 0x807B7D94: jalr        $t9
    // 0x807B7D98: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x807B7D98: nop

    after_1:
    // 0x807B7D9C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x807B7DA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807B7DA4: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x807B7DA8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807B7DAC: addu        $t0, $v1, $t8
    ctx->r8 = ADD32(ctx->r3, ctx->r24);
    // 0x807B7DB0: beq         $v0, $zero, L_807B7E08
    if (ctx->r2 == 0) {
        // 0x807B7DB4: sw          $v0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r2;
            goto L_807B7E08;
    }
    // 0x807B7DB4: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x807B7DB8: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
    // 0x807B7DBC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x807B7DC0: jal         0x8005FDC4
    // 0x807B7DC4: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    func_8005FDC4(rdram, ctx);
        goto after_2;
    // 0x807B7DC4: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_2:
    // 0x807B7DC8: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(883, 0X590) << 16);
    // 0x807B7DCC: lwc1        $f0, -0x7E30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(883, 0X590));
    // 0x807B7DD0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807B7DD4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x807B7DD8: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x807B7DDC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x807B7DE0: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x807B7DE4: lw          $t2, 0x18($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X18);
    // 0x807B7DE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807B7DEC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x807B7DF0: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x807B7DF4: sh          $t1, 0x28($t4)
    MEM_H(0X28, ctx->r12) = ctx->r9;
    // 0x807B7DF8: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x807B7DFC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x807B7E00: addu        $t9, $v1, $t6
    ctx->r25 = ADD32(ctx->r3, ctx->r14);
    // 0x807B7E04: swc1        $f6, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f6.u32l;
L_807B7E08:
    // 0x807B7E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B7E0C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x807B7E10: jr          $ra
    // 0x807B7E14: nop

    return;
    // 0x807B7E14: nop

;}
RECOMP_FUNC void func_8004EDD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EDD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004EDDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004EDE0: jal         0x80064DD0
    // 0x8004EDE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x8004EDE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004EDE8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8004EDEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004EDF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004EDF4: bgtz        $a1, L_8004EE14
    if (SIGNED(ctx->r5) > 0) {
        // 0x8004EDF8: nop
    
            goto L_8004EE14;
    }
    // 0x8004EDF8: nop

    // 0x8004EDFC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004EE00: addiu       $a0, $a0, 0x90C
    ctx->r4 = ADD32(ctx->r4, 0X90C);
    // 0x8004EE04: jal         0x80071380
    // 0x8004EE08: addiu       $a1, $zero, 0x9D
    ctx->r5 = ADD32(0, 0X9D);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8004EE08: addiu       $a1, $zero, 0x9D
    ctx->r5 = ADD32(0, 0X9D);
    after_1:
    // 0x8004EE0C: b           L_8004EE20
    // 0x8004EE10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004EE20;
    // 0x8004EE10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004EE14:
    // 0x8004EE14: jal         0x80065728
    // 0x8004EE18: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8004EE18: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8004EE1C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8004EE20:
    // 0x8004EE20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004EE24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004EE28: jr          $ra
    // 0x8004EE2C: nop

    return;
    // 0x8004EE2C: nop

;}
RECOMP_FUNC void func_80461D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461D10: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80461D14: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A30) << 16);
    // 0x80461D18: lwc1        $f4, 0x3FC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A30));
    // 0x80461D1C: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80461D20: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A34) << 16);
    // 0x80461D24: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80461D28: nop

    // 0x80461D2C: bc1f        L_80461D4C
    if (!c1cs) {
        // 0x80461D30: nop
    
            goto L_80461D4C;
    }
    // 0x80461D30: nop

    // 0x80461D34: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80461D38: bne         $t6, $zero, L_80461D58
    if (ctx->r14 != 0) {
        // 0x80461D3C: nop
    
            goto L_80461D58;
    }
    // 0x80461D3C: nop

    // 0x80461D40: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80461D44: jr          $ra
    // 0x80461D48: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x80461D48: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
L_80461D4C:
    // 0x80461D4C: lwc1        $f8, 0x3FC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A34));
    // 0x80461D50: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80461D54: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
L_80461D58:
    // 0x80461D58: jr          $ra
    // 0x80461D5C: nop

    return;
    // 0x80461D5C: nop

;}
RECOMP_FUNC void func_8058245C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058245C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80582460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80582464: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80582468: jal         0x80045A34
    // 0x8058246C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8058246C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80582470: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80582474: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80582478: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8058247C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80582480: jal         0x800657CC
    // 0x80582484: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x80582484: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    after_1:
    // 0x80582488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8058248C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80582490: jr          $ra
    // 0x80582494: nop

    return;
    // 0x80582494: nop

;}
RECOMP_FUNC void func_806740D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806740D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806740DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806740E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806740E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806740E8: jal         0x8067302C
    // 0x806740EC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8067302C(rdram, ctx);
        goto after_0;
    // 0x806740EC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x806740F0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x806740F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806740F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806740FC: addiu       $v1, $v1, 0x14C
    ctx->r3 = ADD32(ctx->r3, 0X14C);
    // 0x80674100: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80674104: jal         0x8067302C
    // 0x80674108: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8067302C(rdram, ctx);
        goto after_1;
    // 0x80674108: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x8067410C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80674110: beq         $v0, $zero, L_80674124
    if (ctx->r2 == 0) {
        // 0x80674114: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80674124;
    }
    // 0x80674114: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80674118: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8067411C: b           L_8067412C
    // 0x80674120: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
        goto L_8067412C;
    // 0x80674120: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
L_80674124:
    // 0x80674124: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80674128: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
L_8067412C:
    // 0x8067412C: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(529, 0X1050) << 16);
    // 0x80674130: addiu       $t8, $t8, 0x4030
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(529, 0X1050));
    // 0x80674134: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    // 0x80674138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067413C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80674140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80674144: jr          $ra
    // 0x80674148: nop

    return;
    // 0x80674148: nop

;}
RECOMP_FUNC void func_804BBDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BBDE0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x804BBDE4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x804BBDE8: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x804BBDEC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x804BBDF0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x804BBDF4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x804BBDF8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x804BBDFC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x804BBE00: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x804BBE04: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x804BBE08: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x804BBE0C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x804BBE10: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x804BBE14: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x804BBE18: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x804BBE1C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x804BBE20: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x804BBE24: lh          $t7, 0x2D0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2D0);
    // 0x804BBE28: lh          $t6, 0x2D6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2D6);
    // 0x804BBE2C: lh          $t3, 0x2D2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2D2);
    // 0x804BBE30: lh          $t9, 0x2D8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2D8);
    // 0x804BBE34: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x804BBE38: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x804BBE3C: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x804BBE40: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x804BBE44: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x804BBE48: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804BBE4C: jal         0x80067114
    // 0x804BBE50: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x804BBE50: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_0:
    // 0x804BBE54: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x804BBE58: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x804BBE5C: nop

    // 0x804BBE60: sub.s       $f8, $f0, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x804BBE64: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804BBE68: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x804BBE6C: nop

    // 0x804BBE70: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x804BBE74: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x804BBE78: slti        $at, $v0, 0xB5
    ctx->r1 = SIGNED(ctx->r2) < 0XB5 ? 1 : 0;
    // 0x804BBE7C: sll         $s4, $v1, 16
    ctx->r20 = S32(ctx->r3 << 16);
    // 0x804BBE80: bne         $at, $zero, L_804BBE98
    if (ctx->r1 != 0) {
        // 0x804BBE84: sra         $s4, $s4, 16
        ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
            goto L_804BBE98;
    }
    // 0x804BBE84: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x804BBE88: addiu       $s4, $v0, -0x168
    ctx->r20 = ADD32(ctx->r2, -0X168);
    // 0x804BBE8C: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x804BBE90: b           L_804BBEB0
    // 0x804BBE94: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
        goto L_804BBEB0;
    // 0x804BBE94: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
L_804BBE98:
    // 0x804BBE98: slti        $at, $v0, -0xB4
    ctx->r1 = SIGNED(ctx->r2) < -0XB4 ? 1 : 0;
    // 0x804BBE9C: beql        $at, $zero, L_804BBEB4
    if (ctx->r1 == 0) {
        // 0x804BBEA0: mtc1        $s4, $f16
        ctx->f16.u32l = ctx->r20;
            goto L_804BBEB4;
    }
    goto skip_0;
    // 0x804BBEA0: mtc1        $s4, $f16
    ctx->f16.u32l = ctx->r20;
    skip_0:
    // 0x804BBEA4: addiu       $s4, $v0, 0x168
    ctx->r20 = ADD32(ctx->r2, 0X168);
    // 0x804BBEA8: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x804BBEAC: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
L_804BBEB0:
    // 0x804BBEB0: mtc1        $s4, $f16
    ctx->f16.u32l = ctx->r20;
L_804BBEB4:
    // 0x804BBEB4: nop

    // 0x804BBEB8: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804BBEBC: jal         0x80066E88
    // 0x804BBEC0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x804BBEC0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x804BBEC4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x804BBEC8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x804BBECC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x804BBED0: mul.s       $f24, $f0, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x804BBED4: jal         0x80066DE4
    // 0x804BBED8: nop

    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x804BBED8: nop

    after_2:
    // 0x804BBEDC: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4160) << 16);
    // 0x804BBEE0: lwc1        $f28, -0x570($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4160));
    // 0x804BBEE4: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x804BBEE8: trunc.w.s   $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    ctx->f18.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x804BBEEC: lh          $a0, 0x2D0($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X2D0);
    // 0x804BBEF0: lh          $a1, 0x2D2($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X2D2);
    // 0x804BBEF4: lh          $t8, 0x2D4($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X2D4);
    // 0x804BBEF8: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x804BBEFC: lh          $t9, 0x2D4($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X2D4);
    // 0x804BBF00: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804BBF04: subu        $a3, $a0, $v1
    ctx->r7 = SUB32(ctx->r4, ctx->r3);
    // 0x804BBF08: addu        $t0, $a0, $v1
    ctx->r8 = ADD32(ctx->r4, ctx->r3);
    // 0x804BBF0C: addiu       $s7, $zero, 0x78
    ctx->r23 = ADD32(0, 0X78);
    // 0x804BBF10: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x804BBF14: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x804BBF18: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x804BBF1C: subu        $t1, $a1, $a2
    ctx->r9 = SUB32(ctx->r5, ctx->r6);
    // 0x804BBF20: addu        $t2, $a1, $a2
    ctx->r10 = ADD32(ctx->r5, ctx->r6);
    // 0x804BBF24: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x804BBF28: sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10 << 16);
    // 0x804BBF2C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x804BBF30: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x804BBF34: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x804BBF38: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x804BBF3C: addiu       $t3, $zero, 0x7C0
    ctx->r11 = ADD32(0, 0X7C0);
    // 0x804BBF40: sh          $t1, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r9;
    // 0x804BBF44: sh          $a3, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r7;
    // 0x804BBF48: sb          $s7, 0xE($s6)
    MEM_B(0XE, ctx->r22) = ctx->r23;
    // 0x804BBF4C: sb          $zero, 0xF($s6)
    MEM_B(0XF, ctx->r22) = 0;
    // 0x804BBF50: sb          $zero, 0xD($s6)
    MEM_B(0XD, ctx->r22) = 0;
    // 0x804BBF54: sb          $zero, 0xC($s6)
    MEM_B(0XC, ctx->r22) = 0;
    // 0x804BBF58: sh          $zero, 0xA($s6)
    MEM_H(0XA, ctx->r22) = 0;
    // 0x804BBF5C: sh          $zero, 0x8($s6)
    MEM_H(0X8, ctx->r22) = 0;
    // 0x804BBF60: sh          $zero, 0x6($s6)
    MEM_H(0X6, ctx->r22) = 0;
    // 0x804BBF64: sh          $t3, 0x18($s6)
    MEM_H(0X18, ctx->r22) = ctx->r11;
    // 0x804BBF68: sh          $t2, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r10;
    // 0x804BBF6C: sh          $t0, 0x10($s6)
    MEM_H(0X10, ctx->r22) = ctx->r8;
    // 0x804BBF70: sb          $s7, 0x1E($s6)
    MEM_B(0X1E, ctx->r22) = ctx->r23;
    // 0x804BBF74: sb          $zero, 0x1F($s6)
    MEM_B(0X1F, ctx->r22) = 0;
    // 0x804BBF78: sb          $zero, 0x1D($s6)
    MEM_B(0X1D, ctx->r22) = 0;
    // 0x804BBF7C: sb          $zero, 0x1C($s6)
    MEM_B(0X1C, ctx->r22) = 0;
    // 0x804BBF80: sh          $zero, 0x1A($s6)
    MEM_H(0X1A, ctx->r22) = 0;
    // 0x804BBF84: sh          $zero, 0x16($s6)
    MEM_H(0X16, ctx->r22) = 0;
    // 0x804BBF88: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x804BBF8C: addiu       $s1, $s6, 0x2D6
    ctx->r17 = ADD32(ctx->r22, 0X2D6);
    // 0x804BBF90: addiu       $s0, $s6, 0x20
    ctx->r16 = ADD32(ctx->r22, 0X20);
    // 0x804BBF94: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x804BBF98: addiu       $fp, $zero, 0x14
    ctx->r30 = ADD32(0, 0X14);
    // 0x804BBF9C: sub.s       $f26, $f22, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f22.fl - ctx->f28.fl;
    // 0x804BBFA0: sh          $t8, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r24;
    // 0x804BBFA4: sh          $t9, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r25;
L_804BBFA8:
    // 0x804BBFA8: lh          $t4, 0x6($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X6);
    // 0x804BBFAC: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x804BBFB0: lh          $t7, 0x8($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X8);
    // 0x804BBFB4: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x804BBFB8: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x804BBFBC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x804BBFC0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x804BBFC4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x804BBFC8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804BBFCC: jal         0x80067114
    // 0x804BBFD0: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_80067114(rdram, ctx);
        goto after_3;
    // 0x804BBFD0: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_3:
    // 0x804BBFD4: sub.s       $f16, $f0, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x804BBFD8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x804BBFDC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804BBFE0: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x804BBFE4: nop

    // 0x804BBFE8: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x804BBFEC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x804BBFF0: slti        $at, $v0, 0xB5
    ctx->r1 = SIGNED(ctx->r2) < 0XB5 ? 1 : 0;
    // 0x804BBFF4: sll         $s2, $v1, 16
    ctx->r18 = S32(ctx->r3 << 16);
    // 0x804BBFF8: bne         $at, $zero, L_804BC010
    if (ctx->r1 != 0) {
        // 0x804BBFFC: sra         $s2, $s2, 16
        ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
            goto L_804BC010;
    }
    // 0x804BBFFC: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x804BC000: addiu       $s2, $v0, -0x168
    ctx->r18 = ADD32(ctx->r2, -0X168);
    // 0x804BC004: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x804BC008: b           L_804BC028
    // 0x804BC00C: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
        goto L_804BC028;
    // 0x804BC00C: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
L_804BC010:
    // 0x804BC010: slti        $at, $v0, -0xB4
    ctx->r1 = SIGNED(ctx->r2) < -0XB4 ? 1 : 0;
    // 0x804BC014: beq         $at, $zero, L_804BC028
    if (ctx->r1 == 0) {
        // 0x804BC018: nop
    
            goto L_804BC028;
    }
    // 0x804BC018: nop

    // 0x804BC01C: addiu       $s2, $v0, 0x168
    ctx->r18 = ADD32(ctx->r2, 0X168);
    // 0x804BC020: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x804BC024: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
L_804BC028:
    // 0x804BC028: jal         0x804BBD44
    // 0x804BC02C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_804BBD44(rdram, ctx);
        goto after_4;
    // 0x804BC02C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x804BC030: subu        $t4, $s4, $s2
    ctx->r12 = SUB32(ctx->r20, ctx->r18);
    // 0x804BC034: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x804BC038: subu        $t6, $s4, $t5
    ctx->r14 = SUB32(ctx->r20, ctx->r13);
    // 0x804BC03C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x804BC040: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x804BC044: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x804BC048: add.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x804BC04C: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804BC050: jal         0x80066E88
    // 0x804BC054: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x804BC054: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_5:
    // 0x804BC058: mul.s       $f24, $f0, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x804BC05C: jal         0x80066DE4
    // 0x804BC060: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x804BC060: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_6:
    // 0x804BC064: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x804BC068: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x804BC06C: lh          $a1, 0x2($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X2);
    // 0x804BC070: sll         $a2, $s5, 6
    ctx->r6 = S32(ctx->r21 << 6);
    // 0x804BC074: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
    // 0x804BC078: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x804BC07C: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x804BC080: addiu       $t6, $zero, 0x7C0
    ctx->r14 = ADD32(0, 0X7C0);
    // 0x804BC084: sll         $s4, $s2, 16
    ctx->r20 = S32(ctx->r18 << 16);
    // 0x804BC088: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804BC08C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x804BC090: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x804BC094: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x804BC098: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x804BC09C: subu        $a3, $a0, $v1
    ctx->r7 = SUB32(ctx->r4, ctx->r3);
    // 0x804BC0A0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x804BC0A4: subu        $t1, $a1, $v0
    ctx->r9 = SUB32(ctx->r5, ctx->r2);
    // 0x804BC0A8: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x804BC0AC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x804BC0B0: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x804BC0B4: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x804BC0B8: sh          $a3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r7;
    // 0x804BC0BC: lh          $t4, 0x4($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4);
    // 0x804BC0C0: addu        $t0, $a0, $v1
    ctx->r8 = ADD32(ctx->r4, ctx->r3);
    // 0x804BC0C4: addu        $t2, $a1, $v0
    ctx->r10 = ADD32(ctx->r5, ctx->r2);
    // 0x804BC0C8: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x804BC0CC: sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10 << 16);
    // 0x804BC0D0: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x804BC0D4: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x804BC0D8: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
    // 0x804BC0DC: sb          $s7, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r23;
    // 0x804BC0E0: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // 0x804BC0E4: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // 0x804BC0E8: sh          $a2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r6;
    // 0x804BC0EC: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x804BC0F0: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x804BC0F4: sh          $t2, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r10;
    // 0x804BC0F8: sh          $t0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r8;
    // 0x804BC0FC: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x804BC100: lh          $t5, 0x4($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X4);
    // 0x804BC104: sb          $zero, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = 0;
    // 0x804BC108: sb          $s7, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r23;
    // 0x804BC10C: sb          $zero, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = 0;
    // 0x804BC110: sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // 0x804BC114: sh          $a2, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r6;
    // 0x804BC118: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
    // 0x804BC11C: sh          $zero, 0x16($s0)
    MEM_H(0X16, ctx->r16) = 0;
    // 0x804BC120: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x804BC124: sub.s       $f26, $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f28.fl;
    // 0x804BC128: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x804BC12C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x804BC130: bne         $s3, $fp, L_804BBFA8
    if (ctx->r19 != ctx->r30) {
        // 0x804BC134: sh          $t5, -0xC($s0)
        MEM_H(-0XC, ctx->r16) = ctx->r13;
            goto L_804BBFA8;
    }
    // 0x804BC134: sh          $t5, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r13;
    // 0x804BC138: mtc1        $s2, $f16
    ctx->f16.u32l = ctx->r18;
    // 0x804BC13C: nop

    // 0x804BC140: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804BC144: jal         0x80066E88
    // 0x804BC148: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x804BC148: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x804BC14C: mul.s       $f24, $f0, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x804BC150: jal         0x80066DE4
    // 0x804BC154: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x804BC154: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_8:
    // 0x804BC158: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x804BC15C: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x804BC160: lh          $a1, 0x2($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X2);
    // 0x804BC164: sll         $a2, $s5, 6
    ctx->r6 = S32(ctx->r21 << 6);
    // 0x804BC168: addiu       $t4, $zero, 0x7C0
    ctx->r12 = ADD32(0, 0X7C0);
    // 0x804BC16C: trunc.w.s   $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    ctx->f18.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x804BC170: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804BC174: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x804BC178: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x804BC17C: subu        $a3, $a0, $v1
    ctx->r7 = SUB32(ctx->r4, ctx->r3);
    // 0x804BC180: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x804BC184: subu        $t1, $a1, $v0
    ctx->r9 = SUB32(ctx->r5, ctx->r2);
    // 0x804BC188: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x804BC18C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x804BC190: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x804BC194: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x804BC198: sh          $a3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r7;
    // 0x804BC19C: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x804BC1A0: addu        $t0, $a0, $v1
    ctx->r8 = ADD32(ctx->r4, ctx->r3);
    // 0x804BC1A4: addu        $t2, $a1, $v0
    ctx->r10 = ADD32(ctx->r5, ctx->r2);
    // 0x804BC1A8: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x804BC1AC: sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10 << 16);
    // 0x804BC1B0: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x804BC1B4: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x804BC1B8: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
    // 0x804BC1BC: sb          $s7, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r23;
    // 0x804BC1C0: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // 0x804BC1C4: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // 0x804BC1C8: sh          $a2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r6;
    // 0x804BC1CC: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x804BC1D0: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x804BC1D4: sh          $t2, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r10;
    // 0x804BC1D8: sh          $t0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r8;
    // 0x804BC1DC: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x804BC1E0: lh          $t3, 0x4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X4);
    // 0x804BC1E4: sb          $zero, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = 0;
    // 0x804BC1E8: sb          $s7, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r23;
    // 0x804BC1EC: sb          $zero, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = 0;
    // 0x804BC1F0: sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // 0x804BC1F4: sh          $a2, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r6;
    // 0x804BC1F8: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
    // 0x804BC1FC: sh          $zero, 0x16($s0)
    MEM_H(0X16, ctx->r16) = 0;
    // 0x804BC200: sh          $t3, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r11;
    // 0x804BC204: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x804BC208: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x804BC20C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x804BC210: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x804BC214: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x804BC218: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x804BC21C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x804BC220: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x804BC224: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x804BC228: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x804BC22C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x804BC230: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x804BC234: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804BC238: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804BC23C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804BC240: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804BC244: jr          $ra
    // 0x804BC248: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x804BC248: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8042BA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042BA84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042BA88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042BA8C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042BA90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8042BA94: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042BA98: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042BA9C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8042BAA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042BAA4: mul.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8042BAA8: bne         $t6, $at, L_8042BAD4
    if (ctx->r14 != ctx->r1) {
        // 0x8042BAAC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8042BAD4;
    }
    // 0x8042BAAC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8042BAB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8042BAB4: nop

    // 0x8042BAB8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8042BABC: nop

    // 0x8042BAC0: bc1f        L_8042BACC
    if (!c1cs) {
        // 0x8042BAC4: nop
    
            goto L_8042BACC;
    }
    // 0x8042BAC4: nop

    // 0x8042BAC8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8042BACC:
    // 0x8042BACC: b           L_8042BAF0
    // 0x8042BAD0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_8042BAF0;
    // 0x8042BAD0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8042BAD4:
    // 0x8042BAD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8042BAD8: nop

    // 0x8042BADC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8042BAE0: nop

    // 0x8042BAE4: bc1fl       L_8042BAF4
    if (!c1cs) {
        // 0x8042BAE8: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8042BAF4;
    }
    goto skip_0;
    // 0x8042BAE8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_0:
    // 0x8042BAEC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8042BAF0:
    // 0x8042BAF0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_8042BAF4:
    // 0x8042BAF4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8042BAF8: nop

    // 0x8042BAFC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8042BB00: nop

    // 0x8042BB04: bc1f        L_8042BB10
    if (!c1cs) {
        // 0x8042BB08: nop
    
            goto L_8042BB10;
    }
    // 0x8042BB08: nop

    // 0x8042BB0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8042BB10:
    // 0x8042BB10: beql        $v1, $zero, L_8042BB24
    if (ctx->r3 == 0) {
        // 0x8042BB14: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_8042BB24;
    }
    goto skip_1;
    // 0x8042BB14: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x8042BB18: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8042BB1C: nop

    // 0x8042BB20: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_8042BB24:
    // 0x8042BB24: jal         0x8042B938
    // 0x8042BB28: nop

    func_8042B938(rdram, ctx);
        goto after_0;
    // 0x8042BB28: nop

    after_0:
    // 0x8042BB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042BB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042BB34: jr          $ra
    // 0x8042BB38: nop

    return;
    // 0x8042BB38: nop

;}
RECOMP_FUNC void func_806F38D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F38D4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806F38D8: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(682, 0X48) << 16);
    // 0x806F38DC: addiu       $t6, $t6, 0x3498
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(682, 0X48));
    // 0x806F38E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806F38E4: jr          $ra
    // 0x806F38E8: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x806F38E8: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8046A424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A424: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8046A428: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046A42C: bne         $a1, $at, L_8046A438
    if (ctx->r5 != ctx->r1) {
        // 0x8046A430: addiu       $v1, $a1, 0x1
        ctx->r3 = ADD32(ctx->r5, 0X1);
            goto L_8046A438;
    }
    // 0x8046A430: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    // 0x8046A434: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8046A438:
    // 0x8046A438: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8046A43C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8046A440: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8046A444: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8046A448: lwc1        $f0, 0x4C($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8046A44C: lwc1        $f2, 0x4C($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x8046A450: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X295C) << 16);
    // 0x8046A454: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8046A458: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8046A45C: nop

    // 0x8046A460: bc1f        L_8046A49C
    if (!c1cs) {
        // 0x8046A464: nop
    
            goto L_8046A49C;
    }
    // 0x8046A464: nop

    // 0x8046A468: lwc1        $f12, -0x3F64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X295C));
    // 0x8046A46C: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8046A470: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8046A474: nop

    // 0x8046A478: bc1t        L_8046A494
    if (c1cs) {
        // 0x8046A47C: nop
    
            goto L_8046A494;
    }
    // 0x8046A47C: nop

    // 0x8046A480: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8046A484: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8046A488: nop

    // 0x8046A48C: bc1f        L_8046A49C
    if (!c1cs) {
        // 0x8046A490: nop
    
            goto L_8046A49C;
    }
    // 0x8046A490: nop

L_8046A494:
    // 0x8046A494: jr          $ra
    // 0x8046A498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8046A498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8046A49C:
    // 0x8046A49C: jr          $ra
    // 0x8046A4A0: nop

    return;
    // 0x8046A4A0: nop

;}
RECOMP_FUNC void func_8001BC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC8C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001BC90: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8001BC94: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001BC98: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001BC9C: beq         $a0, $zero, L_8001BCC8
    if (ctx->r4 == 0) {
        // 0x8001BCA0: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8001BCC8;
    }
    // 0x8001BCA0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001BCA4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8001BCA8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001BCAC: bgez        $a1, L_8001BCC0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8001BCB0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001BCC0;
    }
    // 0x8001BCB0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001BCB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001BCB8: nop

    // 0x8001BCBC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001BCC0:
    // 0x8001BCC0: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x8001BCC4: sh          $a2, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r6;
L_8001BCC8:
    // 0x8001BCC8: jr          $ra
    // 0x8001BCCC: nop

    return;
    // 0x8001BCCC: nop

;}
RECOMP_FUNC void func_800309B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800309B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800309BC: jr          $ra
    // 0x800309C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800309C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_805685BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805685BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805685C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805685C4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21C4) << 16);
    // 0x805685C8: lwc1        $f12, 0x6C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805685CC: lwc1        $f4, -0x688C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21C4));
    // 0x805685D0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805685D4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21C8) << 16);
    // 0x805685D8: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x805685DC: nop

    // 0x805685E0: bc1f        L_8056863C
    if (!c1cs) {
        // 0x805685E4: nop
    
            goto L_8056863C;
    }
    // 0x805685E4: nop

    // 0x805685E8: lwc1        $f6, -0x6888($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21C8));
    // 0x805685EC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x805685F0: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x805685F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805685F8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x805685FC: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80568600: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x80568604: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80568608: bc1fl       L_80568634
    if (!c1cs) {
        // 0x8056860C: sub.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_80568634;
    }
    goto skip_0;
    // 0x8056860C: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    skip_0:
    // 0x80568610: lw          $t6, 0xF10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF10);
    // 0x80568614: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80568618: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8056861C: lw          $t9, 0xF14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XF14);
    // 0x80568620: sltiu       $at, $t9, 0x9
    ctx->r1 = ctx->r25 < 0X9 ? 1 : 0;
    // 0x80568624: bnel        $at, $zero, L_80568634
    if (ctx->r1 != 0) {
        // 0x80568628: sub.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
            goto L_80568634;
    }
    goto skip_1;
    // 0x80568628: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    skip_1:
    // 0x8056862C: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80568630: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
L_80568634:
    // 0x80568634: b           L_80568650
    // 0x80568638: swc1        $f12, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f12.u32l;
        goto L_80568650;
    // 0x80568638: swc1        $f12, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f12.u32l;
L_8056863C:
    // 0x8056863C: jal         0x800610A0
    // 0x80568640: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800610A0(rdram, ctx);
        goto after_0;
    // 0x80568640: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80568644: jal         0x80044658
    // 0x80568648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80044658(rdram, ctx);
        goto after_1;
    // 0x80568648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8056864C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80568650:
    // 0x80568650: jal         0x805677F4
    // 0x80568654: nop

    func_805677F4(rdram, ctx);
        goto after_2;
    // 0x80568654: nop

    after_2:
    // 0x80568658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8056865C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80568660: jr          $ra
    // 0x80568664: nop

    return;
    // 0x80568664: nop

;}
RECOMP_FUNC void func_800264B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800264B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800264B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800264BC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x800264C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800264C4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800264C8: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    // 0x800264CC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800264D0: jal         0x8006593C
    // 0x800264D4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x800264D4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800264D8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800264DC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800264E0: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800264E4: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800264E8: lw          $v1, 0x14C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X14C);
    // 0x800264EC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800264F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800264F4: divu        $zero, $v1, $at
    lo = S32(U32(ctx->r3) / U32(ctx->r1)); hi = S32(U32(ctx->r3) % U32(ctx->r1));
    // 0x800264F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800264FC: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80026500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80026504: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80026508: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002650C: mfhi        $v1
    ctx->r3 = hi;
    // 0x80026510: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80026514: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80026518: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8002651C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80026520: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80026524: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80026528: nop

    // 0x8002652C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80026530: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80026534: nop

    // 0x80026538: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8002653C: beql        $a0, $zero, L_8002658C
    if (ctx->r4 == 0) {
        // 0x80026540: mfc1        $a0, $f4
        ctx->r4 = (int32_t)ctx->f4.u32l;
            goto L_8002658C;
    }
    goto skip_0;
    // 0x80026540: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80026544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80026548: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002654C: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80026550: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80026554: nop

    // 0x80026558: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002655C: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x80026560: nop

    // 0x80026564: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80026568: bne         $a0, $zero, L_80026580
    if (ctx->r4 != 0) {
        // 0x8002656C: nop
    
            goto L_80026580;
    }
    // 0x8002656C: nop

    // 0x80026570: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80026574: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80026578: b           L_80026598
    // 0x8002657C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80026598;
    // 0x8002657C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_80026580:
    // 0x80026580: b           L_80026598
    // 0x80026584: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80026598;
    // 0x80026584: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80026588: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
L_8002658C:
    // 0x8002658C: nop

    // 0x80026590: bltz        $a0, L_80026580
    if (SIGNED(ctx->r4) < 0) {
        // 0x80026594: nop
    
            goto L_80026580;
    }
    // 0x80026594: nop

L_80026598:
    // 0x80026598: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002659C: sltu        $at, $v1, $a0
    ctx->r1 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x800265A0: beql        $at, $zero, L_800265B4
    if (ctx->r1 == 0) {
        // 0x800265A4: sltu        $at, $a0, $v1
        ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
            goto L_800265B4;
    }
    goto skip_1;
    // 0x800265A4: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
    skip_1:
    // 0x800265A8: b           L_800265C0
    // 0x800265AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_800265C0;
    // 0x800265AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800265B0: sltu        $at, $a0, $v1
    ctx->r1 = ctx->r4 < ctx->r3 ? 1 : 0;
L_800265B4:
    // 0x800265B4: beql        $at, $zero, L_800265C4
    if (ctx->r1 == 0) {
        // 0x800265B8: sw          $v1, 0x14C($a1)
        MEM_W(0X14C, ctx->r5) = ctx->r3;
            goto L_800265C4;
    }
    goto skip_2;
    // 0x800265B8: sw          $v1, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->r3;
    skip_2:
    // 0x800265BC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_800265C0:
    // 0x800265C0: sw          $v1, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->r3;
L_800265C4:
    // 0x800265C4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800265C8: lh          $t7, -0x7682($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X7682);
    // 0x800265CC: lw          $t4, 0x138($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X138);
    // 0x800265D0: lbu         $t1, 0x1F8($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X1F8);
    // 0x800265D4: slt         $t8, $zero, $t7
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800265D8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800265DC: sltu        $t2, $zero, $t1
    ctx->r10 = 0 < ctx->r9 ? 1 : 0;
    // 0x800265E0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800265E4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800265E8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800265EC: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x800265F0: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800265F4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800265F8: lw          $t1, -0x3A68($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3A68);
    // 0x800265FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026600: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80026604: sw          $t2, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->r10;
    // 0x80026608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002660C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026610: jr          $ra
    // 0x80026614: nop

    return;
    // 0x80026614: nop

;}
RECOMP_FUNC void func_806EB980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EB980: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x806EB984: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x806EB988: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x806EB98C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x806EB990: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x806EB994: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x806EB998: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x806EB99C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x806EB9A0: lw          $v0, -0x260C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X260C);
    // 0x806EB9A4: lw          $s1, 0xC($a0)
    ctx->r17 = MEM_W(ctx->r4, 0XC);
    // 0x806EB9A8: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x806EB9AC: lw          $s0, 0xC($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XC);
    // 0x806EB9B0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(673, 0X570) << 16);
    // 0x806EB9B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EB9B8: addiu       $a0, $s0, -0x40
    ctx->r4 = ADD32(ctx->r16, -0X40);
    // 0x806EB9BC: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x806EB9C0: lwc1        $f4, -0x4120($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(673, 0X570));
    // 0x806EB9C4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(673, 0X574) << 16);
    // 0x806EB9C8: lwc1        $f6, -0x411C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(673, 0X574));
    // 0x806EB9CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806EB9D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806EB9D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806EB9D8: sw          $a0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r4;
    // 0x806EB9DC: lui         $a2, 0x43A0
    ctx->r6 = S32(0X43A0 << 16);
    // 0x806EB9E0: lui         $a3, 0x4370
    ctx->r7 = S32(0X4370 << 16);
    // 0x806EB9E4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x806EB9E8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x806EB9EC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x806EB9F0: jal         0x8008CCD4
    // 0x806EB9F4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    guOrtho(rdram, ctx);
        goto after_0;
    // 0x806EB9F4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x806EB9F8: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x806EB9FC: lui         $t3, 0x103
    ctx->r11 = S32(0X103 << 16);
    // 0x806EBA00: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x806EBA04: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x806EBA08: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x806EBA0C: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x806EBA10: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x806EBA14: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x806EBA18: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x806EBA1C: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x806EBA20: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBA24: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x806EBA28: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x806EBA2C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x806EBA30: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x806EBA34: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x806EBA38: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x806EBA3C: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBA40: addiu       $t4, $zero, 0x204
    ctx->r12 = ADD32(0, 0X204);
    // 0x806EBA44: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x806EBA48: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x806EBA4C: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x806EBA50: addiu       $t1, $t1, -0x260C
    ctx->r9 = ADD32(ctx->r9, -0X260C);
    // 0x806EBA54: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x806EBA58: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x806EBA5C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x806EBA60: lui         $a0, 0x806F
    ctx->r4 = S32(RELOC_HI16(673, 0X4E8) << 16);
    // 0x806EBA64: addiu       $a0, $a0, -0x41A8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(673, 0X4E8));
    // 0x806EBA68: lw          $s0, 0xC($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XC);
    // 0x806EBA6C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x806EBA70: addiu       $s0, $s0, -0x80
    ctx->r16 = ADD32(ctx->r16, -0X80);
    // 0x806EBA74: sw          $s0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r16;
    // 0x806EBA78: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x806EBA7C: sw          $s0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r16;
    // 0x806EBA80: lw          $s0, 0xC($v0)
    ctx->r16 = MEM_W(ctx->r2, 0XC);
    // 0x806EBA84: addiu       $s0, $s0, -0x80
    ctx->r16 = ADD32(ctx->r16, -0X80);
    // 0x806EBA88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806EBA8C: jal         0x8008C1F0
    // 0x806EBA90: sw          $s0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r16;
    bcopy_recomp(rdram, ctx);
        goto after_1;
    // 0x806EBA90: sw          $s0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r16;
    after_1:
    // 0x806EBA94: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x806EBA98: jal         0x80058CC0
    // 0x806EBA9C: addiu       $a1, $s1, 0x84
    ctx->r5 = ADD32(ctx->r17, 0X84);
    func_80058CC0(rdram, ctx);
        goto after_2;
    // 0x806EBA9C: addiu       $a1, $s1, 0x84
    ctx->r5 = ADD32(ctx->r17, 0X84);
    after_2:
    // 0x806EBAA0: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x806EBAA4: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x806EBAA8: lw          $a2, 0x9C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X9C);
    // 0x806EBAAC: jal         0x8008F188
    // 0x806EBAB0: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    guTranslate(rdram, ctx);
        goto after_3;
    // 0x806EBAB0: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    after_3:
    // 0x806EBAB4: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x806EBAB8: lw          $a1, 0x6C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X6C);
    // 0x806EBABC: lw          $a2, 0x70($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X70);
    // 0x806EBAC0: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x806EBAC4: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x806EBAC8: jal         0x800826E4
    // 0x806EBACC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    guScale(rdram, ctx);
        goto after_4;
    // 0x806EBACC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x806EBAD0: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBAD4: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x806EBAD8: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x806EBADC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x806EBAE0: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x806EBAE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806EBAE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806EBAEC: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x806EBAF0: jal         0x80077338
    // 0x806EBAF4: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    func_80077338(rdram, ctx);
        goto after_5;
    // 0x806EBAF4: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    after_5:
    // 0x806EBAF8: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBAFC: lui         $t9, 0xFC63
    ctx->r25 = S32(0XFC63 << 16);
    // 0x806EBB00: lui         $t2, 0x11FF
    ctx->r10 = S32(0X11FF << 16);
    // 0x806EBB04: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806EBB08: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x806EBB0C: ori         $t2, $t2, 0xF3F9
    ctx->r10 = ctx->r10 | 0XF3F9;
    // 0x806EBB10: ori         $t9, $t9, 0x7EC6
    ctx->r25 = ctx->r25 | 0X7EC6;
    // 0x806EBB14: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x806EBB18: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x806EBB1C: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBB20: lui         $t5, 0xFD90
    ctx->r13 = S32(0XFD90 << 16);
    // 0x806EBB24: lui         $t2, 0xF590
    ctx->r10 = S32(0XF590 << 16);
    // 0x806EBB28: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x806EBB2C: sw          $t4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r12;
    // 0x806EBB30: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x806EBB34: lw          $t6, 0x168($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X168);
    // 0x806EBB38: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x806EBB3C: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x806EBB40: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x806EBB44: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x806EBB48: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBB4C: lui         $t3, 0x708
    ctx->r11 = S32(0X708 << 16);
    // 0x806EBB50: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x806EBB54: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806EBB58: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x806EBB5C: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x806EBB60: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x806EBB64: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBB68: lui         $t2, 0x73F
    ctx->r10 = S32(0X73F << 16);
    // 0x806EBB6C: ori         $t2, $t2, 0xF200
    ctx->r10 = ctx->r10 | 0XF200;
    // 0x806EBB70: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x806EBB74: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
    // 0x806EBB78: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x806EBB7C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x806EBB80: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBB84: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x806EBB88: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x806EBB8C: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x806EBB90: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x806EBB94: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x806EBB98: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBB9C: lui         $t7, 0xF580
    ctx->r15 = S32(0XF580 << 16);
    // 0x806EBBA0: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x806EBBA4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x806EBBA8: sw          $t4, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r12;
    // 0x806EBBAC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x806EBBB0: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x806EBBB4: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBBB8: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x806EBBBC: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x806EBBC0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x806EBBC4: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x806EBBC8: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x806EBBCC: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x806EBBD0: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBBD4: lui         $t4, 0xF
    ctx->r12 = S32(0XF << 16);
    // 0x806EBBD8: ori         $t4, $t4, 0xC0FC
    ctx->r12 = ctx->r12 | 0XC0FC;
    // 0x806EBBDC: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x806EBBE0: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x806EBBE4: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x806EBBE8: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x806EBBEC: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x806EBBF0: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBBF4: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x806EBBF8: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x806EBBFC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x806EBC00: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x806EBC04: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x806EBC08: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x806EBC0C: lui         $t3, 0x100
    ctx->r11 = S32(0X100 << 16);
    // 0x806EBC10: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x806EBC14: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x806EBC18: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBC1C: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x806EBC20: ori         $t7, $t7, 0x207F
    ctx->r15 = ctx->r15 | 0X207F;
    // 0x806EBC24: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x806EBC28: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x806EBC2C: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x806EBC30: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x806EBC34: lui         $t3, 0x2
    ctx->r11 = S32(0X2 << 16);
    // 0x806EBC38: lui         $t2, 0xB102
    ctx->r10 = S32(0XB102 << 16);
    // 0x806EBC3C: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x806EBC40: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBC44: ori         $t2, $t2, 0x406
    ctx->r10 = ctx->r10 | 0X406;
    // 0x806EBC48: ori         $t3, $t3, 0x600
    ctx->r11 = ctx->r11 | 0X600;
    // 0x806EBC4C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x806EBC50: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x806EBC54: sw          $s0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r16;
    // 0x806EBC58: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x806EBC5C: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBC60: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806EBC64: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x806EBC68: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x806EBC6C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x806EBC70: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBC74: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x806EBC78: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x806EBC7C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x806EBC80: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
    // 0x806EBC84: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x806EBC88: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x806EBC8C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBC90: addiu       $t9, $zero, -0x202
    ctx->r25 = ADD32(0, -0X202);
    // 0x806EBC94: lui         $t4, 0xB10A
    ctx->r12 = S32(0XB10A << 16);
    // 0x806EBC98: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x806EBC9C: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x806EBCA0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x806EBCA4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x806EBCA8: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBCAC: lui         $t5, 0xA
    ctx->r13 = S32(0XA << 16);
    // 0x806EBCB0: ori         $t5, $t5, 0x8
    ctx->r13 = ctx->r13 | 0X8;
    // 0x806EBCB4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x806EBCB8: sw          $t3, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r11;
    // 0x806EBCBC: ori         $t4, $t4, 0x200
    ctx->r12 = ctx->r12 | 0X200;
    // 0x806EBCC0: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x806EBCC4: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x806EBCC8: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBCCC: lui         $t8, 0xB10C
    ctx->r24 = S32(0XB10C << 16);
    // 0x806EBCD0: lui         $t9, 0xC
    ctx->r25 = S32(0XC << 16);
    // 0x806EBCD4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x806EBCD8: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x806EBCDC: ori         $t9, $t9, 0x20A
    ctx->r25 = ctx->r25 | 0X20A;
    // 0x806EBCE0: ori         $t8, $t8, 0x402
    ctx->r24 = ctx->r24 | 0X402;
    // 0x806EBCE4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x806EBCE8: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x806EBCEC: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBCF0: lui         $t5, 0xE
    ctx->r13 = S32(0XE << 16);
    // 0x806EBCF4: lui         $t4, 0xB10E
    ctx->r12 = S32(0XB10E << 16);
    // 0x806EBCF8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x806EBCFC: sw          $t3, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r11;
    // 0x806EBD00: ori         $t4, $t4, 0x604
    ctx->r12 = ctx->r12 | 0X604;
    // 0x806EBD04: ori         $t5, $t5, 0x40C
    ctx->r13 = ctx->r13 | 0X40C;
    // 0x806EBD08: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x806EBD0C: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x806EBD10: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBD14: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x806EBD18: lui         $t8, 0xB108
    ctx->r24 = S32(0XB108 << 16);
    // 0x806EBD1C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x806EBD20: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x806EBD24: ori         $t8, $t8, 0x6
    ctx->r24 = ctx->r24 | 0X6;
    // 0x806EBD28: ori         $t9, $t9, 0x60E
    ctx->r25 = ctx->r25 | 0X60E;
    // 0x806EBD2C: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x806EBD30: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x806EBD34: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBD38: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x806EBD3C: sw          $t3, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r11;
    // 0x806EBD40: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x806EBD44: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x806EBD48: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x806EBD4C: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x806EBD50: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
    // 0x806EBD54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x806EBD58: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x806EBD5C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x806EBD60: jr          $ra
    // 0x806EBD64: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x806EBD64: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_80676A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676A08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80676A0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80676A10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80676A14: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676A18: lw          $t6, 0x2E8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2E8);
    // 0x80676A1C: lw          $s0, 0x404($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X404);
    // 0x80676A20: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80676A24: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80676A28: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80676A2C: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x80676A30: beq         $s0, $zero, L_80676B04
    if (ctx->r16 == 0) {
        // 0x80676A34: addiu       $a2, $v1, 0x174
        ctx->r6 = ADD32(ctx->r3, 0X174);
            goto L_80676B04;
    }
    // 0x80676A34: addiu       $a2, $v1, 0x174
    ctx->r6 = ADD32(ctx->r3, 0X174);
    // 0x80676A38: lh          $t8, 0x66($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X66);
    // 0x80676A3C: lh          $t9, 0x7A($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X7A);
    // 0x80676A40: lh          $t1, 0x7A($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X7A);
    // 0x80676A44: lh          $t2, 0x66($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X66);
    // 0x80676A48: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80676A4C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80676A50: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80676A54: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80676A58: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80676A5C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80676A60: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80676A64: jal         0x80067114
    // 0x80676A68: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x80676A68: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_0:
    // 0x80676A6C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80676A70: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80676A74: jal         0x80066DE4
    // 0x80676A78: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80676A78: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80676A7C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80676A80: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80676A84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80676A88: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80676A8C: lh          $t4, 0x7A($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X7A);
    // 0x80676A90: lh          $t5, 0x78($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X78);
    // 0x80676A94: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80676A98: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X25F8) << 16);
    // 0x80676A9C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80676AA0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80676AA4: lwc1        $f8, 0x7CB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X25F8));
    // 0x80676AA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80676AAC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80676AB0: nop

    // 0x80676AB4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80676AB8: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80676ABC: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x80676AC0: jal         0x80066E88
    // 0x80676AC4: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80676AC4: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80676AC8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80676ACC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80676AD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80676AD4: lh          $t8, 0x7A($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X7A);
    // 0x80676AD8: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80676ADC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X25FC) << 16);
    // 0x80676AE0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80676AE4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80676AE8: lwc1        $f6, 0x7CBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X25FC));
    // 0x80676AEC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80676AF0: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80676AF4: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x80676AF8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80676AFC: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80676B00: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
L_80676B04:
    // 0x80676B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80676B08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80676B0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80676B10: jr          $ra
    // 0x80676B14: nop

    return;
    // 0x80676B14: nop

;}
RECOMP_FUNC void func_80432588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432588: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043258C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80432590: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80432594: jal         0x80047090
    // 0x80432598: addiu       $a0, $zero, 0x40C7
    ctx->r4 = ADD32(0, 0X40C7);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80432598: addiu       $a0, $zero, 0x40C7
    ctx->r4 = ADD32(0, 0X40C7);
    after_0:
    // 0x8043259C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804325A0: lui         $a0, 0x40C7
    ctx->r4 = S32(0X40C7 << 16);
    // 0x804325A4: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x804325A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804325AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x804325B0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x804325B4: jal         0x8004613C
    // 0x804325B8: ori         $a0, $a0, 0x1C00
    ctx->r4 = ctx->r4 | 0X1C00;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804325B8: ori         $a0, $a0, 0x1C00
    ctx->r4 = ctx->r4 | 0X1C00;
    after_1:
    // 0x804325BC: bne         $v0, $zero, L_804325CC
    if (ctx->r2 != 0) {
        // 0x804325C0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804325CC;
    }
    // 0x804325C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804325C4: b           L_804325F8
    // 0x804325C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804325F8;
    // 0x804325C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804325CC:
    // 0x804325CC: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x804325D0: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x804325D4: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x804325D8: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x804325DC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x804325E0: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x804325E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804325E8: jal         0x80047F9C
    // 0x804325EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804325EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x804325F0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804325F4: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
L_804325F8:
    // 0x804325F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804325FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80432600: jr          $ra
    // 0x80432604: nop

    return;
    // 0x80432604: nop

;}
RECOMP_FUNC void func_806EF638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF638: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x806EF63C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EF640: lwc1        $f14, 0x50($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806EF644: lbu         $v1, 0x30($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X30);
    // 0x806EF648: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D5C) << 16);
    // 0x806EF64C: beq         $v1, $zero, L_806EF684
    if (ctx->r3 == 0) {
        // 0x806EF650: nop
    
            goto L_806EF684;
    }
    // 0x806EF650: nop

    // 0x806EF654: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806EF658: beq         $v1, $at, L_806EF698
    if (ctx->r3 == ctx->r1) {
        // 0x806EF65C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_806EF698;
    }
    // 0x806EF65C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806EF660: beq         $v1, $at, L_806EF6B8
    if (ctx->r3 == ctx->r1) {
        // 0x806EF664: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_806EF6B8;
    }
    // 0x806EF664: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806EF668: beq         $v1, $at, L_806EF6D4
    if (ctx->r3 == ctx->r1) {
        // 0x806EF66C: lui         $at, 0x806F
        ctx->r1 = S32(RELOC_HI16(676, 0X4D54) << 16);
            goto L_806EF6D4;
    }
    // 0x806EF66C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D54) << 16);
    // 0x806EF670: lwc1        $f2, 0xCA4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D54));
    // 0x806EF674: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D58) << 16);
    // 0x806EF678: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EF67C: b           L_806EF6EC
    // 0x806EF680: lwc1        $f12, 0xCA8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D58));
        goto L_806EF6EC;
    // 0x806EF680: lwc1        $f12, 0xCA8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D58));
L_806EF684:
    // 0x806EF684: lwc1        $f2, 0xCAC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D5C));
    // 0x806EF688: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EF68C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D60) << 16);
    // 0x806EF690: b           L_806EF6EC
    // 0x806EF694: lwc1        $f12, 0xCB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D60));
        goto L_806EF6EC;
    // 0x806EF694: lwc1        $f12, 0xCB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D60));
L_806EF698:
    // 0x806EF698: lui         $at, 0xC1D0
    ctx->r1 = S32(0XC1D0 << 16);
    // 0x806EF69C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806EF6A0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D64) << 16);
    // 0x806EF6A4: lwc1        $f2, 0xCB4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D64));
    // 0x806EF6A8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806EF6AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806EF6B0: b           L_806EF6F0
    // 0x806EF6B4: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
        goto L_806EF6F0;
    // 0x806EF6B4: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
L_806EF6B8:
    // 0x806EF6B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806EF6BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806EF6C0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D68) << 16);
    // 0x806EF6C4: lwc1        $f2, 0xCB8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D68));
    // 0x806EF6C8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D6C) << 16);
    // 0x806EF6CC: b           L_806EF6EC
    // 0x806EF6D0: lwc1        $f12, 0xCBC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D6C));
        goto L_806EF6EC;
    // 0x806EF6D0: lwc1        $f12, 0xCBC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D6C));
L_806EF6D4:
    // 0x806EF6D4: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x806EF6D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806EF6DC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D70) << 16);
    // 0x806EF6E0: lwc1        $f2, 0xCC0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D70));
    // 0x806EF6E4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D74) << 16);
    // 0x806EF6E8: lwc1        $f12, 0xCC4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D74));
L_806EF6EC:
    // 0x806EF6EC: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
L_806EF6F0:
    // 0x806EF6F0: bnel        $t7, $zero, L_806EF72C
    if (ctx->r15 != 0) {
        // 0x806EF6F4: neg.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
            goto L_806EF72C;
    }
    goto skip_0;
    // 0x806EF6F4: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    skip_0:
    // 0x806EF6F8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x806EF6FC: nop

    // 0x806EF700: bc1fl       L_806EF71C
    if (!c1cs) {
        // 0x806EF704: lwc1        $f8, 0x4($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
            goto L_806EF71C;
    }
    goto skip_1;
    // 0x806EF704: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x806EF708: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EF70C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x806EF710: b           L_806EF758
    // 0x806EF714: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
        goto L_806EF758;
    // 0x806EF714: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x806EF718: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
L_806EF71C:
    // 0x806EF71C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x806EF720: b           L_806EF758
    // 0x806EF724: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
        goto L_806EF758;
    // 0x806EF724: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x806EF728: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
L_806EF72C:
    // 0x806EF72C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x806EF730: nop

    // 0x806EF734: bc1fl       L_806EF750
    if (!c1cs) {
        // 0x806EF738: lwc1        $f6, 0x4($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
            goto L_806EF750;
    }
    goto skip_2;
    // 0x806EF738: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    skip_2:
    // 0x806EF73C: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EF740: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x806EF744: b           L_806EF758
    // 0x806EF748: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_806EF758;
    // 0x806EF748: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x806EF74C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
L_806EF750:
    // 0x806EF750: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x806EF754: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
L_806EF758:
    // 0x806EF758: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EF75C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x806EF760: nop

    // 0x806EF764: bc1fl       L_806EF77C
    if (!c1cs) {
        // 0x806EF768: neg.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
            goto L_806EF77C;
    }
    goto skip_3;
    // 0x806EF768: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    skip_3:
    // 0x806EF76C: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x806EF770: b           L_806EF794
    // 0x806EF774: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
        goto L_806EF794;
    // 0x806EF774: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EF778: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_806EF77C:
    // 0x806EF77C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806EF780: nop

    // 0x806EF784: bc1fl       L_806EF798
    if (!c1cs) {
        // 0x806EF788: add.s       $f14, $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
            goto L_806EF798;
    }
    goto skip_4;
    // 0x806EF788: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    skip_4:
    // 0x806EF78C: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x806EF790: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_806EF794:
    // 0x806EF794: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
L_806EF798:
    // 0x806EF798: jr          $ra
    // 0x806EF79C: swc1        $f14, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x806EF79C: swc1        $f14, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_800371DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800371DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800371E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800371E4: jal         0x80024260
    // 0x800371E8: nop

    func_80024260(rdram, ctx);
        goto after_0;
    // 0x800371E8: nop

    after_0:
    // 0x800371EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800371F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800371F4: jr          $ra
    // 0x800371F8: nop

    return;
    // 0x800371F8: nop

;}
RECOMP_FUNC void func_804F4C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F4C94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F4C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F4C9C: jal         0x8004700C
    // 0x804F4CA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804F4CA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804F4CA4: beq         $v0, $zero, L_804F4CE4
    if (ctx->r2 == 0) {
        // 0x804F4CA8: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_804F4CE4;
    }
    // 0x804F4CA8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x804F4CAC: lwc1        $f0, 0x84($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X84);
    // 0x804F4CB0: lwc1        $f2, 0x84($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X84);
    // 0x804F4CB4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804F4CB8: nop

    // 0x804F4CBC: bc1fl       L_804F4CD0
    if (!c1cs) {
        // 0x804F4CC0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_804F4CD0;
    }
    goto skip_0;
    // 0x804F4CC0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x804F4CC4: b           L_804F4CE8
    // 0x804F4CC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804F4CE8;
    // 0x804F4CC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804F4CCC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_804F4CD0:
    // 0x804F4CD0: nop

    // 0x804F4CD4: bc1fl       L_804F4CE8
    if (!c1cs) {
        // 0x804F4CD8: lw          $v0, 0x138($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X138);
            goto L_804F4CE8;
    }
    goto skip_1;
    // 0x804F4CD8: lw          $v0, 0x138($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X138);
    skip_1:
    // 0x804F4CDC: b           L_804F4CE8
    // 0x804F4CE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804F4CE8;
    // 0x804F4CE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804F4CE4:
    // 0x804F4CE4: lw          $v0, 0x138($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X138);
L_804F4CE8:
    // 0x804F4CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F4CEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F4CF0: jr          $ra
    // 0x804F4CF4: nop

    return;
    // 0x804F4CF4: nop

;}
RECOMP_FUNC void func_8067478C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067478C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80674790: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80674794: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80674798: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8067479C: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x806747A0: jr          $ra
    // 0x806747A4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x806747A4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80065984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006598C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065990: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80065994: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80065998: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8006599C: jal         0x80066E88
    // 0x800659A0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x800659A0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x800659A4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800659A8: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800659AC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800659B0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800659B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800659B8: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x800659BC: jal         0x80066DE4
    // 0x800659C0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x800659C0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800659C4: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800659C8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800659CC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800659D0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800659D4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800659D8: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x800659DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800659E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800659E4: jr          $ra
    // 0x800659E8: nop

    return;
    // 0x800659E8: nop

;}
RECOMP_FUNC void func_8064ADD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064ADD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064ADD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064ADD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064ADDC: lh          $t6, 0xC2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC2);
    // 0x8064ADE0: lui         $at, 0x432E
    ctx->r1 = S32(0X432E << 16);
    // 0x8064ADE4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8064ADE8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8064ADEC: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8064ADF0: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8064ADF4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8064ADF8: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064ADFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064AE00: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8064AE04: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8064AE08: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8064AE0C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8064AE10: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8064AE14: swc1        $f10, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f10.u32l;
    // 0x8064AE18: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8064AE1C: jal         0x8064AD74
    // 0x8064AE20: sh          $t8, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r24;
    func_8064AD74(rdram, ctx);
        goto after_0;
    // 0x8064AE20: sh          $t8, 0xC2($a0)
    MEM_H(0XC2, ctx->r4) = ctx->r24;
    after_0:
    // 0x8064AE24: bne         $v0, $zero, L_8064AE3C
    if (ctx->r2 != 0) {
        // 0x8064AE28: lui         $t9, 0x8065
        ctx->r25 = S32(RELOC_HI16(495, 0XC1C) << 16);
            goto L_8064AE3C;
    }
    // 0x8064AE28: lui         $t9, 0x8065
    ctx->r25 = S32(RELOC_HI16(495, 0XC1C) << 16);
    // 0x8064AE2C: jal         0x800445A4
    // 0x8064AE30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8064AE30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8064AE34: b           L_8064AE98
    // 0x8064AE38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8064AE98;
    // 0x8064AE38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064AE3C:
    // 0x8064AE3C: addiu       $t9, $t9, -0x5314
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(495, 0XC1C));
    // 0x8064AE40: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8064AE44: jal         0x8064A468
    // 0x8064AE48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A468(rdram, ctx);
        goto after_2;
    // 0x8064AE48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8064AE4C: jal         0x8064ADB8
    // 0x8064AE50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064ADB8(rdram, ctx);
        goto after_3;
    // 0x8064AE50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8064AE54: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8064AE58: lui         $t0, 0x8065
    ctx->r8 = S32(RELOC_HI16(495, 0X2EBC) << 16);
    // 0x8064AE5C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8064AE60: addiu       $t0, $t0, -0x3074
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(495, 0X2EBC));
    // 0x8064AE64: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8064AE68: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8064AE6C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8064AE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064AE74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064AE78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064AE7C: jal         0x8064AEA8
    // 0x8064AE80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8064AEA8(rdram, ctx);
        goto after_4;
    // 0x8064AE80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8064AE84: jal         0x8064A158
    // 0x8064AE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A158(rdram, ctx);
        goto after_5;
    // 0x8064AE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8064AE8C: jal         0x8064A40C
    // 0x8064AE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A40C(rdram, ctx);
        goto after_6;
    // 0x8064AE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8064AE94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064AE98:
    // 0x8064AE98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064AE9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064AEA0: jr          $ra
    // 0x8064AEA4: nop

    return;
    // 0x8064AEA4: nop

;}
RECOMP_FUNC void func_805C7844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C7844: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C7848: lw          $v1, 0x1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C);
    // 0x805C784C: beq         $v1, $zero, L_805C785C
    if (ctx->r3 == 0) {
        // 0x805C7850: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_805C785C;
    }
    // 0x805C7850: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x805C7854: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x805C7858: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_805C785C:
    // 0x805C785C: bnel        $v1, $zero, L_805C7918
    if (ctx->r3 != 0) {
        // 0x805C7860: lbu         $t4, 0x30($a0)
        ctx->r12 = MEM_BU(ctx->r4, 0X30);
            goto L_805C7918;
    }
    goto skip_0;
    // 0x805C7860: lbu         $t4, 0x30($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X30);
    skip_0:
    // 0x805C7864: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x805C7868: lui         $t8, 0x805D
    ctx->r24 = S32(RELOC_HI16(447, 0X38D0) << 16);
    // 0x805C786C: addiu       $t8, $t8, -0x6240
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(447, 0X38D0));
    // 0x805C7870: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x805C7874: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x805C7878: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x805C787C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x805C7880: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x805C7884: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x805C7888: sh          $t9, 0x168($v0)
    MEM_H(0X168, ctx->r2) = ctx->r25;
    // 0x805C788C: lh          $t0, 0x2($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X2);
    // 0x805C7890: sh          $t0, 0x16A($v0)
    MEM_H(0X16A, ctx->r2) = ctx->r8;
    // 0x805C7894: lh          $t1, 0x4($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X4);
    // 0x805C7898: sh          $t1, 0x16C($v0)
    MEM_H(0X16C, ctx->r2) = ctx->r9;
    // 0x805C789C: lh          $t2, 0x6($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X6);
    // 0x805C78A0: sw          $t3, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r11;
    // 0x805C78A4: sh          $t2, 0x16E($v0)
    MEM_H(0X16E, ctx->r2) = ctx->r10;
    // 0x805C78A8: lbu         $t4, 0x30($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X30);
    // 0x805C78AC: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x805C78B0: bnel        $at, $zero, L_805C78C0
    if (ctx->r1 != 0) {
        // 0x805C78B4: lw          $t6, 0x28($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X28);
            goto L_805C78C0;
    }
    goto skip_1;
    // 0x805C78B4: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    skip_1:
    // 0x805C78B8: sw          $t5, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r13;
    // 0x805C78BC: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
L_805C78C0:
    // 0x805C78C0: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x805C78C4: bnel        $at, $zero, L_805C78F4
    if (ctx->r1 != 0) {
        // 0x805C78C8: lw          $t9, 0x18($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X18);
            goto L_805C78F4;
    }
    goto skip_2;
    // 0x805C78C8: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    skip_2:
    // 0x805C78CC: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x805C78D0: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x805C78D4: beql        $at, $zero, L_805C78F4
    if (ctx->r1 == 0) {
        // 0x805C78D8: lw          $t9, 0x18($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X18);
            goto L_805C78F4;
    }
    goto skip_3;
    // 0x805C78D8: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    skip_3:
    // 0x805C78DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805C78E0: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x805C78E4: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x805C78E8: swc1        $f4, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f4.u32l;
    // 0x805C78EC: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x805C78F0: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
L_805C78F4:
    // 0x805C78F4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x805C78F8: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x805C78FC: bne         $at, $zero, L_805C7914
    if (ctx->r1 != 0) {
        // 0x805C7900: sw          $t0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r8;
            goto L_805C7914;
    }
    // 0x805C7900: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    // 0x805C7904: lw          $t2, 0x28($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X28);
    // 0x805C7908: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x805C790C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x805C7910: sw          $t3, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r11;
L_805C7914:
    // 0x805C7914: lbu         $t4, 0x30($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X30);
L_805C7918:
    // 0x805C7918: slti        $at, $t4, 0xD
    ctx->r1 = SIGNED(ctx->r12) < 0XD ? 1 : 0;
    // 0x805C791C: beq         $at, $zero, L_805C79AC
    if (ctx->r1 == 0) {
        // 0x805C7920: nop
    
            goto L_805C79AC;
    }
    // 0x805C7920: nop

    // 0x805C7924: lw          $v1, 0x28($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X28);
    // 0x805C7928: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3BF0) << 16);
    // 0x805C792C: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x805C7930: beq         $t5, $zero, L_805C7970
    if (ctx->r13 == 0) {
        // 0x805C7934: nop
    
            goto L_805C7970;
    }
    // 0x805C7934: nop

    // 0x805C7938: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805C793C: lwc1        $f6, -0x5F20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3BF0));
    // 0x805C7940: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3BF4) << 16);
    // 0x805C7944: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x805C7948: nop

    // 0x805C794C: bc1f        L_805C79AC
    if (!c1cs) {
        // 0x805C7950: nop
    
            goto L_805C79AC;
    }
    // 0x805C7950: nop

    // 0x805C7954: lwc1        $f2, -0x5F1C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3BF4));
    // 0x805C7958: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x805C795C: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x805C7960: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x805C7964: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x805C7968: jr          $ra
    // 0x805C796C: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x805C796C: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
L_805C7970:
    // 0x805C7970: beq         $v1, $zero, L_805C79AC
    if (ctx->r3 == 0) {
        // 0x805C7974: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_805C79AC;
    }
    // 0x805C7974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805C7978: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805C797C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C7980: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3BF8) << 16);
    // 0x805C7984: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x805C7988: nop

    // 0x805C798C: bc1f        L_805C79AC
    if (!c1cs) {
        // 0x805C7990: nop
    
            goto L_805C79AC;
    }
    // 0x805C7990: nop

    // 0x805C7994: lwc1        $f2, -0x5F18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3BF8));
    // 0x805C7998: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x805C799C: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x805C79A0: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x805C79A4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x805C79A8: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
L_805C79AC:
    // 0x805C79AC: jr          $ra
    // 0x805C79B0: nop

    return;
    // 0x805C79B0: nop

;}
RECOMP_FUNC void func_8046C610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C610: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(143, 0X1598) << 16);
    // 0x8046C614: lwc1        $f0, -0x2618($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(143, 0X1598));
    // 0x8046C618: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x8046C61C: jr          $ra
    // 0x8046C620: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8046C620: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80517854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517854: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80517858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051785C: jal         0x805175E4
    // 0x80517860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805175E4(rdram, ctx);
        goto after_0;
    // 0x80517860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80517864: jal         0x80517590
    // 0x80517868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80517590(rdram, ctx);
        goto after_1;
    // 0x80517868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8051786C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80517870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80517874: jr          $ra
    // 0x80517878: nop

    return;
    // 0x80517878: nop

;}
RECOMP_FUNC void func_807107B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807107B0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x807107B4: lw          $t7, -0x7470($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7470);
    // 0x807107B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807107BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807107C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807107C4: beq         $t7, $zero, L_80710810
    if (ctx->r15 == 0) {
        // 0x807107C8: lw          $a2, 0x1F4($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X1F4);
            goto L_80710810;
    }
    // 0x807107C8: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x807107CC: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x807107D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807107D4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x807107D8: andi        $a1, $t9, 0x10
    ctx->r5 = ctx->r25 & 0X10;
    // 0x807107DC: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x807107E0: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    // 0x807107E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807107E8: jal         0x807106C8
    // 0x807107EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_807106C8(rdram, ctx);
        goto after_0;
    // 0x807107EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x807107F0: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x807107F4: lw          $t0, -0x7470($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7470);
    // 0x807107F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807107FC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80710800: bne         $t0, $at, L_80710810
    if (ctx->r8 != ctx->r1) {
        // 0x80710804: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80710810;
    }
    // 0x80710804: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80710808: jal         0x807106E4
    // 0x8071080C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_807106E4(rdram, ctx);
        goto after_1;
    // 0x8071080C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_80710810:
    // 0x80710810: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x80710814: lw          $t1, 0x7EA8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7EA8);
    // 0x80710818: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8071081C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80710820: lhu         $v0, 0xC($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0XC);
    // 0x80710824: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x80710828: beq         $t2, $at, L_80710848
    if (ctx->r10 == ctx->r1) {
        // 0x8071082C: andi        $t3, $v0, 0x4000
        ctx->r11 = ctx->r2 & 0X4000;
            goto L_80710848;
    }
    // 0x8071082C: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x80710830: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80710834: beq         $t3, $at, L_80710848
    if (ctx->r11 == ctx->r1) {
        // 0x80710838: andi        $t4, $v0, 0x1000
        ctx->r12 = ctx->r2 & 0X1000;
            goto L_80710848;
    }
    // 0x80710838: andi        $t4, $v0, 0x1000
    ctx->r12 = ctx->r2 & 0X1000;
    // 0x8071083C: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80710840: bnel        $t4, $at, L_80710854
    if (ctx->r12 != ctx->r1) {
        // 0x80710844: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80710854;
    }
    goto skip_0;
    // 0x80710844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80710848:
    // 0x80710848: jal         0x80710C50
    // 0x8071084C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80710C50(rdram, ctx);
        goto after_2;
    // 0x8071084C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_2:
    // 0x80710850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80710854:
    // 0x80710854: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80710858: jr          $ra
    // 0x8071085C: nop

    return;
    // 0x8071085C: nop

;}
RECOMP_FUNC void func_80671B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671B88: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80671B8C: lbu         $t6, -0x7D78($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7D78);
    // 0x80671B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80671B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80671B98: bnel        $t6, $zero, L_80671BD8
    if (ctx->r14 != 0) {
        // 0x80671B9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80671BD8;
    }
    goto skip_0;
    // 0x80671B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80671BA0: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x80671BA4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80671BA8: blez        $t8, L_80671BD4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80671BAC: sw          $t8, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r24;
            goto L_80671BD4;
    }
    // 0x80671BAC: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x80671BB0: lbu         $t0, 0x18($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X18);
    // 0x80671BB4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80671BB8: sb          $t1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r9;
    // 0x80671BBC: jal         0x80672C80
    // 0x80671BC0: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
    func_80672C80(rdram, ctx);
        goto after_0;
    // 0x80671BC0: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
    after_0:
    // 0x80671BC4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80671BC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80671BCC: jal         0x80067838
    // 0x80671BD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80067838(rdram, ctx);
        goto after_1;
    // 0x80671BD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80671BD4:
    // 0x80671BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80671BD8:
    // 0x80671BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80671BDC: jr          $ra
    // 0x80671BE0: nop

    return;
    // 0x80671BE0: nop

;}
RECOMP_FUNC void func_8069C7B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069C7B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8069C7B4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8069C7B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069C7BC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8069C7C0: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8069C7C4: jal         0x80066E88
    // 0x8069C7C8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8069C7C8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069C7CC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8069C7D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8069C7D4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8069C7D8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8069C7DC: lwc1        $f8, 0x84($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8069C7E0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8069C7E4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8069C7E8: jal         0x80066DE4
    // 0x8069C7EC: lwc1        $f12, 0x50($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8069C7EC: lwc1        $f12, 0x50($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X50);
    after_1:
    // 0x8069C7F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8069C7F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8069C7F8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8069C7FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8069C800: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8069C804: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8069C808: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8069C80C: lwc1        $f4, 0x88($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X88);
    // 0x8069C810: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8069C814: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8069C818: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8069C81C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8069C820: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8069C824: lwc1        $f8, 0x8C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8C);
    // 0x8069C828: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8069C82C: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x8069C830: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8069C834: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8069C838: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8069C83C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8069C840: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8069C844: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8069C848: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8069C84C: jalr        $t9
    // 0x8069C850: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8069C850: nop

    after_2:
    // 0x8069C854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069C858: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8069C85C: jr          $ra
    // 0x8069C860: nop

    return;
    // 0x8069C860: nop

;}
RECOMP_FUNC void func_80716370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716370: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(733, 0XCA0) << 16);
    // 0x80716374: jr          $ra
    // 0x80716378: addiu       $v0, $v0, 0x7010
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(733, 0XCA0));
    return;
    // 0x80716378: addiu       $v0, $v0, 0x7010
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(733, 0XCA0));
;}
RECOMP_FUNC void func_8002DFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DFF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002DFFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E000: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002E004: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002E008: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002E00C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8002E010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002E014: lw          $t6, 0x15C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X15C);
    // 0x8002E018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E01C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8002E020: lw          $v0, 0x180($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X180);
    // 0x8002E024: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8002E028: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002E02C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8002E030: jal         0x8002B9E4
    // 0x8002E034: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002E034: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_0:
    // 0x8002E038: jal         0x8002DAF0
    // 0x8002E03C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002DAF0(rdram, ctx);
        goto after_1;
    // 0x8002E03C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8002E040: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002E044: lwc1        $f16, -0x58($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X58);
    // 0x8002E048: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002E04C: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8002E050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002E054: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8002E058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E05C: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x8002E060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002E064: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x8002E068: sb          $zero, 0x1AD($s1)
    MEM_B(0X1AD, ctx->r17) = 0;
    // 0x8002E06C: jal         0x8003D76C
    // 0x8002E070: sb          $zero, 0x154($s1)
    MEM_B(0X154, ctx->r17) = 0;
    func_8003D76C(rdram, ctx);
        goto after_2;
    // 0x8002E070: sb          $zero, 0x154($s1)
    MEM_B(0X154, ctx->r17) = 0;
    after_2:
    // 0x8002E074: jal         0x8001D770
    // 0x8002E078: sb          $zero, 0x156($s1)
    MEM_B(0X156, ctx->r17) = 0;
    func_8001D770(rdram, ctx);
        goto after_3;
    // 0x8002E078: sb          $zero, 0x156($s1)
    MEM_B(0X156, ctx->r17) = 0;
    after_3:
    // 0x8002E07C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002E080: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002E084: jal         0x80067BF8
    // 0x8002E088: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_4;
    // 0x8002E088: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x8002E08C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002E090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002E094: jal         0x80067838
    // 0x8002E098: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_5;
    // 0x8002E098: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x8002E09C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E0A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002E0A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002E0A8: jr          $ra
    // 0x8002E0AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002E0AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804C52D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C52D0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x804C52D4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x804C52D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C52DC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x804C52E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C52E4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x804C52E8: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(212, 0X8E0) << 16);
    // 0x804C52EC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804C52F0: addiu       $t7, $t7, 0x5820
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(212, 0X8E0));
    // 0x804C52F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x804C52F8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x804C52FC: jal         0x80048490
    // 0x804C5300: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804C5300: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C5304: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x804C5308: jal         0x80048378
    // 0x804C530C: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804C530C: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    after_1:
    // 0x804C5310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C5314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5318: jr          $ra
    // 0x804C531C: nop

    return;
    // 0x804C531C: nop

;}
RECOMP_FUNC void func_8042C1F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C1F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042C1FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042C200: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3044) << 16);
    // 0x8042C204: lwc1        $f0, -0x271C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3044));
    // 0x8042C208: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042C20C: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8042C210: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042C214: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8042C218: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x8042C21C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8042C220: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x8042C224: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x8042C228: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8042C22C: jal         0x8042BFF4
    // 0x8042C230: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8042BFF4(rdram, ctx);
        goto after_0;
    // 0x8042C230: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8042C234: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8042C238: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3048) << 16);
    // 0x8042C23C: lwc1        $f18, -0x2718($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3048));
    // 0x8042C240: lwc1        $f16, 0x20($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8042C244: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8042C248: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8042C24C: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
    // 0x8042C250: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8042C254: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8042C258: slti        $at, $t7, 0x79
    ctx->r1 = SIGNED(ctx->r15) < 0X79 ? 1 : 0;
    // 0x8042C25C: bne         $at, $zero, L_8042C2D0
    if (ctx->r1 != 0) {
        // 0x8042C260: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8042C2D0;
    }
    // 0x8042C260: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8042C264: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8042C268: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8042C26C: jal         0x800653D8
    // 0x8042C270: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8042C270: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8042C274: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8042C278: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8042C27C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8042C280: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8042C284: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8042C288: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8042C28C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8042C290: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042C294: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x8042C298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8042C29C: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8042C2A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C2A4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8042C2A8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8042C2AC: bne         $t0, $at, L_8042C2C8
    if (ctx->r8 != ctx->r1) {
        // 0x8042C2B0: swc1        $f16, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
            goto L_8042C2C8;
    }
    // 0x8042C2B0: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x8042C2B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042C2B8: jal         0x8042D50C
    // 0x8042C2BC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8042D50C(rdram, ctx);
        goto after_2;
    // 0x8042C2BC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_2:
    // 0x8042C2C0: b           L_8042C2D4
    // 0x8042C2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8042C2D4;
    // 0x8042C2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042C2C8:
    // 0x8042C2C8: jal         0x8042D50C
    // 0x8042C2CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042D50C(rdram, ctx);
        goto after_3;
    // 0x8042C2CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
L_8042C2D0:
    // 0x8042C2D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042C2D4:
    // 0x8042C2D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042C2D8: jr          $ra
    // 0x8042C2DC: nop

    return;
    // 0x8042C2DC: nop

;}
RECOMP_FUNC void func_804A3C08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A3C08: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x804A3C0C: nop

    // 0x804A3C10: bc1fl       L_804A3C24
    if (!c1cs) {
        // 0x804A3C14: sub.s       $f14, $f12, $f14
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f14.fl;
            goto L_804A3C24;
    }
    goto skip_0;
    // 0x804A3C14: sub.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f14.fl;
    skip_0:
    // 0x804A3C18: jr          $ra
    // 0x804A3C1C: sub.s       $f0, $f14, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f12.fl;
    return;
    // 0x804A3C1C: sub.s       $f0, $f14, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x804A3C20: sub.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f14.fl;
L_804A3C24:
    // 0x804A3C24: jr          $ra
    // 0x804A3C28: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    return;
    // 0x804A3C28: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
;}
