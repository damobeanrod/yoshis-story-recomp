#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8001B730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B734: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B738: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B73C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001B740: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001B744: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B748: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001B74C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8001B750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001B754: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x8001B758: jal         0x8001B7B0
    // 0x8001B75C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8001B7B0(rdram, ctx);
        goto after_0;
    // 0x8001B75C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001B760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B764: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B768: jr          $ra
    // 0x8001B76C: nop

    return;
    // 0x8001B76C: nop

;}
RECOMP_FUNC void func_80026A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026A1C: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80026A20: addiu       $t6, $t6, 0x6934
    ctx->r14 = ADD32(ctx->r14, 0X6934);
    // 0x80026A24: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80026A28: jr          $ra
    // 0x80026A2C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80026A2C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80670310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670310: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80670314: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80670318: addiu       $at, $zero, 0x407D
    ctx->r1 = ADD32(0, 0X407D);
    // 0x8067031C: beq         $a0, $at, L_80670334
    if (ctx->r4 == ctx->r1) {
        // 0x80670320: addiu       $at, $zero, 0x407E
        ctx->r1 = ADD32(0, 0X407E);
            goto L_80670334;
    }
    // 0x80670320: addiu       $at, $zero, 0x407E
    ctx->r1 = ADD32(0, 0X407E);
    // 0x80670324: beq         $a0, $at, L_80670334
    if (ctx->r4 == ctx->r1) {
        // 0x80670328: addiu       $at, $zero, 0x407F
        ctx->r1 = ADD32(0, 0X407F);
            goto L_80670334;
    }
    // 0x80670328: addiu       $at, $zero, 0x407F
    ctx->r1 = ADD32(0, 0X407F);
    // 0x8067032C: bne         $a0, $at, L_8067033C
    if (ctx->r4 != ctx->r1) {
        // 0x80670330: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8067033C;
    }
    // 0x80670330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80670334:
    // 0x80670334: jr          $ra
    // 0x80670338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80670338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8067033C:
    // 0x8067033C: jr          $ra
    // 0x80670340: nop

    return;
    // 0x80670340: nop

;}
RECOMP_FUNC void func_80027454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027454: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80027458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002745C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80027460: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80027464: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80027468: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x8002746C: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    // 0x80027470: jal         0x80024680
    // 0x80027474: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x80027474: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_0:
    // 0x80027478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002747C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80027480: jr          $ra
    // 0x80027484: nop

    return;
    // 0x80027484: nop

;}
RECOMP_FUNC void func_804EF7AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF7AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF7B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF7B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804EF7B8: jal         0x80045A34
    // 0x804EF7BC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804EF7BC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x804EF7C0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x804EF7C4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x804EF7C8: bne         $v0, $zero, L_804EF7D8
    if (ctx->r2 != 0) {
        // 0x804EF7CC: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_804EF7D8;
    }
    // 0x804EF7CC: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x804EF7D0: b           L_804EF7E8
    // 0x804EF7D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804EF7E8;
    // 0x804EF7D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804EF7D8:
    // 0x804EF7D8: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x804EF7DC: jal         0x800657CC
    // 0x804EF7E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x804EF7E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x804EF7E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804EF7E8:
    // 0x804EF7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF7EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF7F0: jr          $ra
    // 0x804EF7F4: nop

    return;
    // 0x804EF7F4: nop

;}
RECOMP_FUNC void func_804BA180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BA180: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804BA184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BA188: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x804BA18C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804BA190: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x804BA194: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804BA198: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x804BA19C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804BA1A0: lw          $t8, 0x960($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X960);
    // 0x804BA1A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804BA1A8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804BA1AC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804BA1B0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x804BA1B4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804BA1B8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x804BA1BC: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x804BA1C0: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x804BA1C4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x804BA1C8: lw          $t1, 0x168($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X168);
    // 0x804BA1CC: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x804BA1D0: lw          $t2, 0x88($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X88);
    // 0x804BA1D4: jal         0x80077338
    // 0x804BA1D8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x804BA1D8: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    after_0:
    // 0x804BA1DC: jal         0x80058958
    // 0x804BA1E0: nop

    func_80058958(rdram, ctx);
        goto after_1;
    // 0x804BA1E0: nop

    after_1:
    // 0x804BA1E4: beq         $v0, $zero, L_804BA244
    if (ctx->r2 == 0) {
        // 0x804BA1E8: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_804BA244;
    }
    // 0x804BA1E8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x804BA1EC: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x804BA1F0: lw          $t3, -0x7BC4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7BC4);
    // 0x804BA1F4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x804BA1F8: lui         $t9, 0xFC11
    ctx->r25 = S32(0XFC11 << 16);
    // 0x804BA1FC: lw          $t4, 0x10C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10C);
    // 0x804BA200: ori         $t9, $t9, 0xFE23
    ctx->r25 = ctx->r25 | 0XFE23;
    // 0x804BA204: addiu       $t0, $zero, -0xC07
    ctx->r8 = ADD32(0, -0XC07);
    // 0x804BA208: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x804BA20C: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x804BA210: beq         $t6, $zero, L_804BA244
    if (ctx->r14 == 0) {
        // 0x804BA214: addiu       $t8, $t7, 0x8
        ctx->r24 = ADD32(ctx->r15, 0X8);
            goto L_804BA244;
    }
    // 0x804BA214: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804BA218: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x804BA21C: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x804BA220: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x804BA224: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x804BA228: lui         $t4, 0x7A84
    ctx->r12 = S32(0X7A84 << 16);
    // 0x804BA22C: ori         $t4, $t4, 0x7AFF
    ctx->r12 = ctx->r12 | 0X7AFF;
    // 0x804BA230: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x804BA234: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x804BA238: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x804BA23C: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x804BA240: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
L_804BA244:
    // 0x804BA244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804BA248: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804BA24C: jal         0x8007711C
    // 0x804BA250: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8007711C(rdram, ctx);
        goto after_2;
    // 0x804BA250: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x804BA254: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x804BA258: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804BA25C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x804BA260: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x804BA264: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x804BA268: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x804BA26C: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x804BA270: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804BA274: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x804BA278: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x804BA27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BA280: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804BA284: jr          $ra
    // 0x804BA288: nop

    return;
    // 0x804BA288: nop

;}
RECOMP_FUNC void func_8000BDF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BDF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000BDF4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000BDF8: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x8000BDFC: addiu       $s3, $s3, -0x63B4
    ctx->r19 = ADD32(ctx->r19, -0X63B4);
    // 0x8000BE00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000BE04: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000BE08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000BE0C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000BE10: jal         0x8000BDA0
    // 0x8000BE14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8000BDA0(rdram, ctx);
        goto after_0;
    // 0x8000BE14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x8000BE18: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x8000BE1C: addiu       $s1, $s1, 0x4D10
    ctx->r17 = ADD32(ctx->r17, 0X4D10);
    // 0x8000BE20: lw          $t6, 0x1DAC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1DAC);
    // 0x8000BE24: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000BE28: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000BE2C: blezl       $t6, L_8000BE7C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000BE30: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000BE7C;
    }
    goto skip_0;
    // 0x8000BE30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8000BE34: lw          $v0, 0x2A2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2A2C);
L_8000BE38:
    // 0x8000BE38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000BE3C: addu        $t7, $s0, $v0
    ctx->r15 = ADD32(ctx->r16, ctx->r2);
    // 0x8000BE40: addu        $t8, $v0, $s0
    ctx->r24 = ADD32(ctx->r2, ctx->r16);
    // 0x8000BE44: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8000BE48: lw          $t9, 0x2A2C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X2A2C);
    // 0x8000BE4C: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000BE50: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8000BE54: lw          $t1, 0x2A2C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X2A2C);
    // 0x8000BE58: jal         0x8000DB94
    // 0x8000BE5C: addu        $a1, $s0, $t1
    ctx->r5 = ADD32(ctx->r16, ctx->r9);
    func_8000DB94(rdram, ctx);
        goto after_1;
    // 0x8000BE5C: addu        $a1, $s0, $t1
    ctx->r5 = ADD32(ctx->r16, ctx->r9);
    after_1:
    // 0x8000BE60: lw          $t2, 0x1DAC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1DAC);
    // 0x8000BE64: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000BE68: addiu       $s0, $s0, 0xD0
    ctx->r16 = ADD32(ctx->r16, 0XD0);
    // 0x8000BE6C: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8000BE70: bnel        $at, $zero, L_8000BE38
    if (ctx->r1 != 0) {
        // 0x8000BE74: lw          $v0, 0x2A2C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X2A2C);
            goto L_8000BE38;
    }
    goto skip_1;
    // 0x8000BE74: lw          $v0, 0x2A2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2A2C);
    skip_1:
    // 0x8000BE78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000BE7C:
    // 0x8000BE7C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000BE80: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000BE84: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BE88: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000BE8C: jr          $ra
    // 0x8000BE90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000BE90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80022F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022F24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022F28: lwc1        $f4, -0x350($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X350);
    // 0x80022F2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022F30: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80022F34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022F38: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022F3C: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x80022F40: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x80022F44: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x80022F48: swc1        $f6, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f6.u32l;
    // 0x80022F4C: lwc1        $f8, -0x34C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X34C);
    // 0x80022F50: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80022F54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022F58: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x80022F5C: jr          $ra
    // 0x80022F60: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80022F60: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80581C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581C44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581C48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581C4C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80581C50: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80581C54: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80581C58: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(399, 0X46D0) << 16);
    // 0x80581C5C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80581C60: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80581C64: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80581C68: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80581C6C: lw          $t8, 0x34E0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(399, 0X46D0));
    // 0x80581C70: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80581C74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80581C78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80581C7C: jal         0x80048490
    // 0x80581C80: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80581C80: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80581C84: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80581C88: jal         0x80048378
    // 0x80581C8C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80581C8C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80581C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581C98: jr          $ra
    // 0x80581C9C: nop

    return;
    // 0x80581C9C: nop

;}
RECOMP_FUNC void func_8051F644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F644: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8051F648: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8051F64C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8051F650: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8051F654: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8051F658: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8051F65C: lbu         $t6, 0x10($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10);
    // 0x8051F660: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8051F664: addiu       $t7, $t6, -0x20
    ctx->r15 = ADD32(ctx->r14, -0X20);
    // 0x8051F668: sb          $t7, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r15;
    // 0x8051F66C: jal         0x80048F84
    // 0x8051F670: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8051F670: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051F674: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8051F678: jal         0x80048F84
    // 0x8051F67C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8051F67C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8051F680: jal         0x8051F4A8
    // 0x8051F684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051F4A8(rdram, ctx);
        goto after_2;
    // 0x8051F684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8051F688: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8051F68C: bnel        $v0, $at, L_8051F6C0
    if (ctx->r2 != ctx->r1) {
        // 0x8051F690: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8051F6C0;
    }
    goto skip_0;
    // 0x8051F690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8051F694: lw          $t8, 0x154($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X154);
    // 0x8051F698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8051F69C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8051F6A0: bne         $t8, $zero, L_8051F6BC
    if (ctx->r24 != 0) {
        // 0x8051F6A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8051F6BC;
    }
    // 0x8051F6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8051F6A8: sb          $v0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r2;
    // 0x8051F6AC: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x8051F6B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8051F6B4: jal         0x8051F6D0
    // 0x8051F6B8: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_8051F6D0(rdram, ctx);
        goto after_3;
    // 0x8051F6B8: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_3:
L_8051F6BC:
    // 0x8051F6BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8051F6C0:
    // 0x8051F6C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8051F6C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8051F6C8: jr          $ra
    // 0x8051F6CC: nop

    return;
    // 0x8051F6CC: nop

;}
RECOMP_FUNC void func_8001BC68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC68: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001BC6C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8001BC70: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001BC74: beq         $a0, $zero, L_8001BC84
    if (ctx->r4 == 0) {
        // 0x8001BC78: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8001BC84;
    }
    // 0x8001BC78: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001BC7C: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
    // 0x8001BC80: sh          $a2, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r6;
L_8001BC84:
    // 0x8001BC84: jr          $ra
    // 0x8001BC88: nop

    return;
    // 0x8001BC88: nop

;}
RECOMP_FUNC void func_80462C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462C54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80462C58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80462C5C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80462C60: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80462C64: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80462C68: jal         0x80062684
    // 0x80462C6C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x80462C6C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80462C70: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80462C74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80462C78: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80462C7C: beql        $v0, $zero, L_80462D60
    if (ctx->r2 == 0) {
        // 0x80462C80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80462D60;
    }
    goto skip_0;
    // 0x80462C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80462C84: lw          $a1, 0x1F4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1F4);
    // 0x80462C88: beql        $a1, $zero, L_80462D60
    if (ctx->r5 == 0) {
        // 0x80462C8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80462D60;
    }
    goto skip_1;
    // 0x80462C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80462C90: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80462C94: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80462C98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80462C9C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80462CA0: nop

    // 0x80462CA4: bc1fl       L_80462CC4
    if (!c1cs) {
        // 0x80462CA8: lbu         $t6, 0x30($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X30);
            goto L_80462CC4;
    }
    goto skip_2;
    // 0x80462CA8: lbu         $t6, 0x30($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X30);
    skip_2:
    // 0x80462CAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80462CB0: jal         0x80463260
    // 0x80462CB4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_80463260(rdram, ctx);
        goto after_1;
    // 0x80462CB4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x80462CB8: b           L_80462D60
    // 0x80462CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80462D60;
    // 0x80462CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80462CC0: lbu         $t6, 0x30($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X30);
L_80462CC4:
    // 0x80462CC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80462CC8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80462CCC: bne         $t6, $at, L_80462D40
    if (ctx->r14 != ctx->r1) {
        // 0x80462CD0: lui         $at, 0x8046
        ctx->r1 = S32(RELOC_HI16(122, 0X3A70) << 16);
            goto L_80462D40;
    }
    // 0x80462CD0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A70) << 16);
    // 0x80462CD4: lwc1        $f8, 0x4000($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A70));
    // 0x80462CD8: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80462CDC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A74) << 16);
    // 0x80462CE0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80462CE4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80462CE8: nop

    // 0x80462CEC: bc1fl       L_80462D24
    if (!c1cs) {
        // 0x80462CF0: lwc1        $f12, 0x4($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80462D24;
    }
    goto skip_3;
    // 0x80462CF0: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    skip_3:
    // 0x80462CF4: lwc1        $f10, 0x4004($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A74));
    // 0x80462CF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80462CFC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80462D00: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80462D04: nop

    // 0x80462D08: bc1fl       L_80462D24
    if (!c1cs) {
        // 0x80462D0C: lwc1        $f12, 0x4($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80462D24;
    }
    goto skip_4;
    // 0x80462D0C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    skip_4:
    // 0x80462D10: jal         0x80463260
    // 0x80462D14: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_80463260(rdram, ctx);
        goto after_2;
    // 0x80462D14: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_2:
    // 0x80462D18: b           L_80462D60
    // 0x80462D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80462D60;
    // 0x80462D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80462D20: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
L_80462D24:
    // 0x80462D24: lwc1        $f14, 0x28($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80462D28: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x80462D2C: jal         0x80065ABC
    // 0x80462D30: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x80462D30: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80462D34: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80462D38: b           L_80462D5C
    // 0x80462D3C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
        goto L_80462D5C;
    // 0x80462D3C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_80462D40:
    // 0x80462D40: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80462D44: lwc1        $f14, 0x28($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80462D48: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x80462D4C: jal         0x80065ABC
    // 0x80462D50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80065ABC(rdram, ctx);
        goto after_4;
    // 0x80462D50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80462D54: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80462D58: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_80462D5C:
    // 0x80462D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80462D60:
    // 0x80462D60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80462D64: jr          $ra
    // 0x80462D68: nop

    return;
    // 0x80462D68: nop

;}
RECOMP_FUNC void func_80453744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045374C: jal         0x80453644
    // 0x80453750: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80453644(rdram, ctx);
        goto after_0;
    // 0x80453750: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80453754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045375C: jr          $ra
    // 0x80453760: nop

    return;
    // 0x80453760: nop

;}
RECOMP_FUNC void func_804F43B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F43B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F43BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F43C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804F43C4: jal         0x80064E84
    // 0x804F43C8: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x804F43C8: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x804F43CC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x804F43D0: jal         0x80064E84
    // 0x804F43D4: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x804F43D4: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    after_1:
    // 0x804F43D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F43DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F43E0: jr          $ra
    // 0x804F43E4: nop

    return;
    // 0x804F43E4: nop

;}
RECOMP_FUNC void func_805195EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805195EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805195F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805195F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805195F8: jal         0x80519124
    // 0x805195FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80519124(rdram, ctx);
        goto after_0;
    // 0x805195FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80519600: jal         0x80517DB0
    // 0x80519604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80517DB0(rdram, ctx);
        goto after_1;
    // 0x80519604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80519608: jal         0x80519340
    // 0x8051960C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519340(rdram, ctx);
        goto after_2;
    // 0x8051960C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80519610: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x80519614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80519618: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8051961C: slti        $at, $t6, 0x5A
    ctx->r1 = SIGNED(ctx->r14) < 0X5A ? 1 : 0;
    // 0x80519620: beq         $at, $zero, L_8051964C
    if (ctx->r1 == 0) {
        // 0x80519624: nop
    
            goto L_8051964C;
    }
    // 0x80519624: nop

    // 0x80519628: jal         0x80519AFC
    // 0x8051962C: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    func_80519AFC(rdram, ctx);
        goto after_3;
    // 0x8051962C: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x80519630: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80519634: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(291, 0X2600) << 16);
    // 0x80519638: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x8051963C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x80519640: lwc1        $f4, -0x5D90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(291, 0X2600));
    // 0x80519644: b           L_80519654
    // 0x80519648: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
        goto L_80519654;
    // 0x80519648: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
L_8051964C:
    // 0x8051964C: jal         0x80519594
    // 0x80519650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519594(rdram, ctx);
        goto after_4;
    // 0x80519650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80519654:
    // 0x80519654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80519658: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8051965C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80519660: jr          $ra
    // 0x80519664: nop

    return;
    // 0x80519664: nop

;}
RECOMP_FUNC void func_80582144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582144: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80582148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8058214C: nop

    // 0x80582150: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80582154: div.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80582158: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8058215C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80582160: jr          $ra
    // 0x80582164: nop

    return;
    // 0x80582164: nop

;}
RECOMP_FUNC void func_805AC7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC7F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AC7FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC800: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AC804: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805AC808: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805AC80C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805AC810: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x805AC814: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x805AC818: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805AC81C: bnel        $t6, $at, L_805AC838
    if (ctx->r14 != ctx->r1) {
        // 0x805AC820: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AC838;
    }
    goto skip_0;
    // 0x805AC820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805AC824: jal         0x8003C358
    // 0x805AC828: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_8003C358(rdram, ctx);
        goto after_0;
    // 0x805AC828: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x805AC82C: jal         0x805AC77C
    // 0x805AC830: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805AC77C(rdram, ctx);
        goto after_1;
    // 0x805AC830: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805AC834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AC838:
    // 0x805AC838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AC83C: jr          $ra
    // 0x805AC840: nop

    return;
    // 0x805AC840: nop

;}
RECOMP_FUNC void func_8007914C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007914C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80079150: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80079154: jr          $ra
    // 0x80079158: nop

    return;
    // 0x80079158: nop

    // 0x8007915C: nop

;}
RECOMP_FUNC void func_805A63E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A63E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A63EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A63F0: jal         0x805A5DF0
    // 0x805A63F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A5DF0(rdram, ctx);
        goto after_0;
    // 0x805A63F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A63F8: jal         0x805A61AC
    // 0x805A63FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805A61AC(rdram, ctx);
        goto after_1;
    // 0x805A63FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805A6400: bne         $v0, $zero, L_805A6410
    if (ctx->r2 != 0) {
        // 0x805A6404: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805A6410;
    }
    // 0x805A6404: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A6408: jal         0x805A6730
    // 0x805A640C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_805A6730(rdram, ctx);
        goto after_2;
    // 0x805A640C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_805A6410:
    // 0x805A6410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A6414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A6418: jr          $ra
    // 0x805A641C: nop

    return;
    // 0x805A641C: nop

;}
RECOMP_FUNC void func_806F3828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F3828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F382C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F3830: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x806F3834: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X924) << 16);
    // 0x806F3838: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x806F383C: bne         $v0, $zero, L_806F3854
    if (ctx->r2 != 0) {
        // 0x806F3840: sw          $v0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r2;
            goto L_806F3854;
    }
    // 0x806F3840: sw          $v0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r2;
    // 0x806F3844: jal         0x806F37A8
    // 0x806F3848: nop

    func_806F37A8(rdram, ctx);
        goto after_0;
    // 0x806F3848: nop

    after_0:
    // 0x806F384C: b           L_806F3878
    // 0x806F3850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806F3878;
    // 0x806F3850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F3854:
    // 0x806F3854: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x806F3858: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x806F385C: lwc1        $f4, 0x3D74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X924));
    // 0x806F3860: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x806F3864: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806F3868: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
    // 0x806F386C: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x806F3870: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x806F3874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F3878:
    // 0x806F3878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F387C: jr          $ra
    // 0x806F3880: nop

    return;
    // 0x806F3880: nop

;}
RECOMP_FUNC void func_8001137C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001137C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80011384: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80011388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001138C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80011390: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80011394: jal         0x8001A900
    // 0x80011398: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    func_8001A900(rdram, ctx);
        goto after_0;
    // 0x80011398: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    after_0:
    // 0x8001139C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800113A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800113A4: sw          $zero, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = 0;
    // 0x800113A8: jr          $ra
    // 0x800113AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800113AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005896C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005896C: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80058970: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x80058974: lw          $t6, 0x59C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X59C);
    // 0x80058978: lw          $v1, 0x13B8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X13B8);
    // 0x8005897C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80058980: lw          $a0, 0x10C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X10C);
    // 0x80058984: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x80058988: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x8005898C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80058990: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80058994: bne         $a2, $t8, L_80058A04
    if (ctx->r6 != ctx->r24) {
        // 0x80058998: sll         $a1, $a0, 3
        ctx->r5 = S32(ctx->r4 << 3);
            goto L_80058A04;
    }
    // 0x80058998: sll         $a1, $a0, 3
    ctx->r5 = S32(ctx->r4 << 3);
    // 0x8005899C: srl         $a1, $a1, 30
    ctx->r5 = S32(U32(ctx->r5) >> 30);
    // 0x800589A0: beq         $a1, $zero, L_800589C4
    if (ctx->r5 == 0) {
        // 0x800589A4: addiu       $t2, $t2, -0x76DC
        ctx->r10 = ADD32(ctx->r10, -0X76DC);
            goto L_800589C4;
    }
    // 0x800589A4: addiu       $t2, $t2, -0x76DC
    ctx->r10 = ADD32(ctx->r10, -0X76DC);
    // 0x800589A8: beq         $a1, $a2, L_800589D8
    if (ctx->r5 == ctx->r6) {
        // 0x800589AC: addiu       $t0, $zero, 0x32
        ctx->r8 = ADD32(0, 0X32);
            goto L_800589D8;
    }
    // 0x800589AC: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x800589B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800589B4: beq         $a1, $at, L_800589E8
    if (ctx->r5 == ctx->r1) {
        // 0x800589B8: addiu       $t1, $zero, 0x46
        ctx->r9 = ADD32(0, 0X46);
            goto L_800589E8;
    }
    // 0x800589B8: addiu       $t1, $zero, 0x46
    ctx->r9 = ADD32(0, 0X46);
    // 0x800589BC: b           L_800589F8
    // 0x800589C0: sw          $t2, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r10;
        goto L_800589F8;
    // 0x800589C0: sw          $t2, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r10;
L_800589C4:
    // 0x800589C4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800589C8: sb          $t9, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r25;
    // 0x800589CC: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800589D0: b           L_800589F4
    // 0x800589D4: lw          $v1, -0x6DA8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6DA8);
        goto L_800589F4;
    // 0x800589D4: lw          $v1, -0x6DA8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6DA8);
L_800589D8:
    // 0x800589D8: sb          $t0, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r8;
    // 0x800589DC: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800589E0: b           L_800589F4
    // 0x800589E4: lw          $v1, -0x6DA8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6DA8);
        goto L_800589F4;
    // 0x800589E4: lw          $v1, -0x6DA8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6DA8);
L_800589E8:
    // 0x800589E8: sb          $t1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r9;
    // 0x800589EC: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x800589F0: lw          $v1, -0x6DA8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6DA8);
L_800589F4:
    // 0x800589F4: sw          $t2, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r10;
L_800589F8:
    // 0x800589F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800589FC: jr          $ra
    // 0x80058A00: sb          $t3, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r11;
    return;
    // 0x80058A00: sb          $t3, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r11;
L_80058A04:
    // 0x80058A04: sw          $zero, 0x58($v1)
    MEM_W(0X58, ctx->r3) = 0;
    // 0x80058A08: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x80058A0C: jr          $ra
    // 0x80058A10: nop

    return;
    // 0x80058A10: nop

;}
RECOMP_FUNC void func_806D2994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D2994: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806D2998: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D299C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D29A0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D29A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D29A8: bne         $v1, $zero, L_806D29C0
    if (ctx->r3 != 0) {
        // 0x806D29AC: nop
    
            goto L_806D29C0;
    }
    // 0x806D29AC: nop

    // 0x806D29B0: jal         0x80045A34
    // 0x806D29B4: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806D29B4: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_0:
    // 0x806D29B8: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806D29BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_806D29C0:
    // 0x806D29C0: bne         $v1, $zero, L_806D29D8
    if (ctx->r3 != 0) {
        // 0x806D29C4: lui         $t6, 0x806D
        ctx->r14 = S32(RELOC_HI16(610, 0X1650) << 16);
            goto L_806D29D8;
    }
    // 0x806D29C4: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(610, 0X1650) << 16);
    // 0x806D29C8: jal         0x800445A4
    // 0x806D29CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806D29CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D29D0: b           L_806D2BBC
    // 0x806D29D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D2BBC;
    // 0x806D29D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D29D8:
    // 0x806D29D8: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x806D29DC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806D29E0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806D29E4: addiu       $t6, $t6, 0x2C10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(610, 0X1650));
    // 0x806D29E8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806D29EC: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x806D29F0: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806D29F4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x806D29F8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806D29FC: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x806D2A00: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x806D2A04: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x806D2A08: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x806D2A0C: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806D2A10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D2A14: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x806D2A18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806D2A1C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806D2A20: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806D2A24: addiu       $t9, $zero, 0x898
    ctx->r25 = ADD32(0, 0X898);
    // 0x806D2A28: addiu       $a0, $zero, 0x45A9
    ctx->r4 = ADD32(0, 0X45A9);
    // 0x806D2A2C: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x806D2A30: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806D2A34: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
    // 0x806D2A38: lhu         $t0, 0xC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XC);
    // 0x806D2A3C: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x806D2A40: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x806D2A44: addiu       $t1, $t0, -0x45F6
    ctx->r9 = ADD32(ctx->r8, -0X45F6);
    // 0x806D2A48: slti        $at, $t1, 0xB
    ctx->r1 = SIGNED(ctx->r9) < 0XB ? 1 : 0;
    // 0x806D2A4C: sw          $t1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r9;
    // 0x806D2A50: bne         $at, $zero, L_806D2A80
    if (ctx->r1 != 0) {
        // 0x806D2A54: sw          $v0, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->r2;
            goto L_806D2A80;
    }
    // 0x806D2A54: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x806D2A58: lhu         $t4, 0xC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XC);
    // 0x806D2A5C: sb          $t3, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r11;
    // 0x806D2A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D2A64: addiu       $t5, $t4, -0x465E
    ctx->r13 = ADD32(ctx->r12, -0X465E);
    // 0x806D2A68: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x806D2A6C: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x806D2A70: sw          $t5, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r13;
    // 0x806D2A74: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x806D2A78: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x806D2A7C: sw          $t7, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r15;
L_806D2A80:
    // 0x806D2A80: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806D2A84: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806D2A88: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x806D2A8C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806D2A90: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x806D2A94: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x806D2A98: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x806D2A9C: bnel        $at, $zero, L_806D2AB0
    if (ctx->r1 != 0) {
        // 0x806D2AA0: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_806D2AB0;
    }
    goto skip_0;
    // 0x806D2AA0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    skip_0:
    // 0x806D2AA4: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x806D2AA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806D2AAC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
L_806D2AB0:
    // 0x806D2AB0: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x806D2AB4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806D2AB8: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x806D2ABC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x806D2AC0: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x806D2AC4: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
    // 0x806D2AC8: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x806D2ACC: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x806D2AD0: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x806D2AD4: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x806D2AD8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806D2ADC: jal         0x80047090
    // 0x806D2AE0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80047090(rdram, ctx);
        goto after_2;
    // 0x806D2AE0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x806D2AE4: lui         $at, 0x45A9
    ctx->r1 = S32(0X45A9 << 16);
    // 0x806D2AE8: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x806D2AEC: lui         $a3, 0xBC23
    ctx->r7 = S32(0XBC23 << 16);
    // 0x806D2AF0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x806D2AF4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x806D2AF8: lui         $a1, 0xC000
    ctx->r5 = S32(0XC000 << 16);
    // 0x806D2AFC: jal         0x8004613C
    // 0x806D2B00: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    func_8004613C(rdram, ctx);
        goto after_3;
    // 0x806D2B00: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_3:
    // 0x806D2B04: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x806D2B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D2B0C: bne         $v0, $zero, L_806D2B24
    if (ctx->r2 != 0) {
        // 0x806D2B10: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_806D2B24;
    }
    // 0x806D2B10: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x806D2B14: jal         0x800445A4
    // 0x806D2B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x806D2B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806D2B1C: b           L_806D2BBC
    // 0x806D2B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D2BBC;
    // 0x806D2B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D2B24:
    // 0x806D2B24: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x806D2B28: jal         0x80047F9C
    // 0x806D2B2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x806D2B2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x806D2B30: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x806D2B34: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x806D2B38: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x806D2B3C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x806D2B40: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X173C) << 16);
    // 0x806D2B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D2B48: sb          $t1, 0x17C($t2)
    MEM_B(0X17C, ctx->r10) = ctx->r9;
    // 0x806D2B4C: lw          $t3, 0x24($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X24);
    // 0x806D2B50: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x806D2B54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D2B58: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x806D2B5C: nop

    // 0x806D2B60: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806D2B64: swc1        $f8, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f8.u32l;
    // 0x806D2B68: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x806D2B6C: sb          $t5, 0x165($t6)
    MEM_B(0X165, ctx->r14) = ctx->r13;
    // 0x806D2B70: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806D2B74: bne         $t7, $zero, L_806D2B8C
    if (ctx->r15 != 0) {
        // 0x806D2B78: nop
    
            goto L_806D2B8C;
    }
    // 0x806D2B78: nop

    // 0x806D2B7C: jal         0x806D2BCC
    // 0x806D2B80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_806D2BCC(rdram, ctx);
        goto after_6;
    // 0x806D2B80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x806D2B84: b           L_806D2BBC
    // 0x806D2B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D2BBC;
    // 0x806D2B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D2B8C:
    // 0x806D2B8C: lwc1        $f0, 0x2CFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X173C));
    // 0x806D2B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D2B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D2B98: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x806D2B9C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x806D2BA0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806D2BA4: swc1        $f0, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f0.u32l;
    // 0x806D2BA8: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x806D2BAC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x806D2BB0: jal         0x806D2BCC
    // 0x806D2BB4: swc1        $f0, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f0.u32l;
    func_806D2BCC(rdram, ctx);
        goto after_7;
    // 0x806D2BB4: swc1        $f0, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f0.u32l;
    after_7:
    // 0x806D2BB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D2BBC:
    // 0x806D2BBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D2BC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806D2BC4: jr          $ra
    // 0x806D2BC8: nop

    return;
    // 0x806D2BC8: nop

;}
RECOMP_FUNC void func_80051758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005175C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051760: lw          $a1, 0x4C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4C);
    // 0x80051764: jal         0x800516D0
    // 0x80051768: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800516D0(rdram, ctx);
        goto after_0;
    // 0x80051768: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x8005176C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051774: jr          $ra
    // 0x80051778: nop

    return;
    // 0x80051778: nop

;}
RECOMP_FUNC void func_805D1550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D1554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D1558: jal         0x805D1078
    // 0x805D155C: nop

    func_805D1078(rdram, ctx);
        goto after_0;
    // 0x805D155C: nop

    after_0:
    // 0x805D1560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D1564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D1568: jr          $ra
    // 0x805D156C: nop

    return;
    // 0x805D156C: nop

;}
RECOMP_FUNC void func_80060030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060038: jal         0x80049018
    // 0x8006003C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8006003C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80060040: beq         $v0, $zero, L_8006006C
    if (ctx->r2 == 0) {
        // 0x80060044: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8006006C;
    }
    // 0x80060044: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80060048: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006004C: lh          $t7, 0x50($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X50);
    // 0x80060050: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x80060054: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80060058: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8006005C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060060: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80060064: b           L_8006008C
    // 0x80060068: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_8006008C;
    // 0x80060068: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8006006C:
    // 0x8006006C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060070: lh          $t9, 0x50($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X50);
    // 0x80060074: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x80060078: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8006007C: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80060080: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80060084: mul.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80060088: nop

L_8006008C:
    // 0x8006008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060094: jr          $ra
    // 0x80060098: nop

    return;
    // 0x80060098: nop

;}
RECOMP_FUNC void func_804C53C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C53C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C53C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C53CC: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804C53D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804C53D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804C53D8: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x804C53DC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804C53E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C53E4: bc1f        L_804C5418
    if (!c1cs) {
        // 0x804C53E8: nop
    
            goto L_804C5418;
    }
    // 0x804C53E8: nop

    // 0x804C53EC: jal         0x804C537C
    // 0x804C53F0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_804C537C(rdram, ctx);
        goto after_0;
    // 0x804C53F0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x804C53F4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804C53F8: lw          $t6, 0x15C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X15C);
    // 0x804C53FC: lw          $t8, 0x14C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X14C);
    // 0x804C5400: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x804C5404: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x804C5408: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804C540C: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x804C5410: b           L_804C5420
    // 0x804C5414: sh          $t1, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r9;
        goto L_804C5420;
    // 0x804C5414: sh          $t1, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r9;
L_804C5418:
    // 0x804C5418: jal         0x804C5320
    // 0x804C541C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_804C5320(rdram, ctx);
        goto after_1;
    // 0x804C541C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_804C5420:
    // 0x804C5420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C5424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5428: jr          $ra
    // 0x804C542C: nop

    return;
    // 0x804C542C: nop

;}
RECOMP_FUNC void func_8068293C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8068293C: slti        $at, $a0, 0x3C
    ctx->r1 = SIGNED(ctx->r4) < 0X3C ? 1 : 0;
    // 0x80682940: beql        $at, $zero, L_80682958
    if (ctx->r1 == 0) {
        // 0x80682944: slti        $at, $a0, 0x3C0
        ctx->r1 = SIGNED(ctx->r4) < 0X3C0 ? 1 : 0;
            goto L_80682958;
    }
    goto skip_0;
    // 0x80682944: slti        $at, $a0, 0x3C0
    ctx->r1 = SIGNED(ctx->r4) < 0X3C0 ? 1 : 0;
    skip_0:
    // 0x80682948: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8068294C: jr          $ra
    // 0x80682950: nop

    return;
    // 0x80682950: nop

    // 0x80682954: slti        $at, $a0, 0x3C0
    ctx->r1 = SIGNED(ctx->r4) < 0X3C0 ? 1 : 0;
L_80682958:
    // 0x80682958: beq         $at, $zero, L_80682978
    if (ctx->r1 == 0) {
        // 0x8068295C: addiu       $t6, $a0, -0x3C
        ctx->r14 = ADD32(ctx->r4, -0X3C);
            goto L_80682978;
    }
    // 0x8068295C: addiu       $t6, $a0, -0x3C
    ctx->r14 = ADD32(ctx->r4, -0X3C);
    // 0x80682960: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80682964: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x80682968: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8068296C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80682970: jr          $ra
    // 0x80682974: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    return;
    // 0x80682974: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
L_80682978:
    // 0x80682978: slti        $at, $a0, 0x1B6C
    ctx->r1 = SIGNED(ctx->r4) < 0X1B6C ? 1 : 0;
    // 0x8068297C: beq         $at, $zero, L_80682990
    if (ctx->r1 == 0) {
        // 0x80682980: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80682990;
    }
    // 0x80682980: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80682984: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80682988: jr          $ra
    // 0x8068298C: nop

    return;
    // 0x8068298C: nop

L_80682990:
    // 0x80682990: slti        $at, $a0, 0x1EF0
    ctx->r1 = SIGNED(ctx->r4) < 0X1EF0 ? 1 : 0;
    // 0x80682994: beq         $at, $zero, L_806829C0
    if (ctx->r1 == 0) {
        // 0x80682998: addiu       $t7, $a0, -0x1B6C
        ctx->r15 = ADD32(ctx->r4, -0X1B6C);
            goto L_806829C0;
    }
    // 0x80682998: addiu       $t7, $a0, -0x1B6C
    ctx->r15 = ADD32(ctx->r4, -0X1B6C);
    // 0x8068299C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x806829A0: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x806829A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806829A8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x806829AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806829B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806829B4: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x806829B8: jr          $ra
    // 0x806829BC: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    return;
    // 0x806829BC: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
L_806829C0:
    // 0x806829C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806829C4: nop

    // 0x806829C8: jr          $ra
    // 0x806829CC: nop

    return;
    // 0x806829CC: nop

;}
RECOMP_FUNC void func_8077F97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077F97C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8077F980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8077F984: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8077F988: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8077F98C: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x8077F990: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8077F994: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8077F998: bne         $t7, $at, L_8077F9D8
    if (ctx->r15 != ctx->r1) {
        // 0x8077F99C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8077F9D8;
    }
    // 0x8077F99C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8077F9A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8077F9A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8077F9A8: jal         0x8002F7AC
    // 0x8077F9AC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_8002F7AC(rdram, ctx);
        goto after_0;
    // 0x8077F9AC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x8077F9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8077F9B4: jal         0x80780098
    // 0x8077F9B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80780098(rdram, ctx);
        goto after_1;
    // 0x8077F9B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8077F9BC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8077F9C0: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x8077F9C4: jal         0x8005FE48
    // 0x8077F9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x8077F9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8077F9CC: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x8077F9D0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8077F9D4: sb          $zero, 0x74($t0)
    MEM_B(0X74, ctx->r8) = 0;
L_8077F9D8:
    // 0x8077F9D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8077F9DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8077F9E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8077F9E4: jr          $ra
    // 0x8077F9E8: nop

    return;
    // 0x8077F9E8: nop

;}
RECOMP_FUNC void func_80011A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011A1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80011A20: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_80011A24:
    // 0x80011A24: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80011A28: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80011A2C: addiu       $t7, $t7, -0x5AD0
    ctx->r15 = ADD32(ctx->r15, -0X5AD0);
    // 0x80011A30: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80011A34: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80011A38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80011A3C:
    // 0x80011A3C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80011A40: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80011A44: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80011A48: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80011A4C: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80011A50: bne         $at, $zero, L_80011A3C
    if (ctx->r1 != 0) {
        // 0x80011A54: sw          $zero, 0x0($t9)
        MEM_W(0X0, ctx->r25) = 0;
            goto L_80011A3C;
    }
    // 0x80011A54: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x80011A58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80011A5C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80011A60: slti        $at, $v0, 0x77
    ctx->r1 = SIGNED(ctx->r2) < 0X77 ? 1 : 0;
    // 0x80011A64: bnel        $at, $zero, L_80011A24
    if (ctx->r1 != 0) {
        // 0x80011A68: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80011A24;
    }
    goto skip_0;
    // 0x80011A68: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    skip_0:
    // 0x80011A6C: jr          $ra
    // 0x80011A70: nop

    return;
    // 0x80011A70: nop

;}
RECOMP_FUNC void func_8044A4F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A4F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044A4F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044A4FC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8044A500: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8044A504: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x8044A508: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044A50C: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X13430) << 16);
    // 0x8044A510: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044A514: lw          $v1, 0x6CC8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CC8);
    // 0x8044A518: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x8044A51C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8044A520: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8044A524: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8044A528: lw          $t0, 0x7810($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X13430));
    // 0x8044A52C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044A530: beql        $t0, $zero, L_8044A544
    if (ctx->r8 == 0) {
        // 0x8044A534: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8044A544;
    }
    goto skip_0;
    // 0x8044A534: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8044A538: jalr        $t0
    // 0x8044A53C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x8044A53C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8044A540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8044A544:
    // 0x8044A544: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044A548: jr          $ra
    // 0x8044A54C: nop

    return;
    // 0x8044A54C: nop

;}
RECOMP_FUNC void func_8067389C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067389C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806738A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806738A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806738A8: jal         0x80673808
    // 0x806738AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80673808(rdram, ctx);
        goto after_0;
    // 0x806738AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806738B0: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806738B4: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x806738B8: jal         0x80065ABC
    // 0x806738BC: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x806738BC: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_1:
    // 0x806738C0: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806738C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806738C8: jal         0x80049D74
    // 0x806738CC: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x806738CC: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_2:
    // 0x806738D0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806738D4: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806738D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806738DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806738E0: jal         0x8004D150
    // 0x806738E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x806738E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x806738E8: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x806738EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806738F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806738F4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806738F8: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x806738FC: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80673900: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x80673904: beql        $t9, $zero, L_80673954
    if (ctx->r25 == 0) {
        // 0x80673908: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80673954;
    }
    goto skip_0;
    // 0x80673908: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8067390C: jal         0x8004D618
    // 0x80673910: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x80673910: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_4:
    // 0x80673914: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x80673918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8067391C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80673920: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x80673924: jal         0x8004A97C
    // 0x80673928: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    func_8004A97C(rdram, ctx);
        goto after_5;
    // 0x80673928: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    after_5:
    // 0x8067392C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80673930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673934: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80673938: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8067393C: jal         0x80673F0C
    // 0x80673940: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_80673F0C(rdram, ctx);
        goto after_6;
    // 0x80673940: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x80673944: jal         0x80673590
    // 0x80673948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80673590(rdram, ctx);
        goto after_7;
    // 0x80673948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8067394C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80673950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80673954:
    // 0x80673954: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80673958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067395C: jr          $ra
    // 0x80673960: nop

    return;
    // 0x80673960: nop

;}
RECOMP_FUNC void func_805E4998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4998: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805E499C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E49A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E49A4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E49A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E49AC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805E49B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E49B4: jal         0x805E4378
    // 0x805E49B8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_805E4378(rdram, ctx);
        goto after_0;
    // 0x805E49B8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x805E49BC: jal         0x805E4460
    // 0x805E49C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4460(rdram, ctx);
        goto after_1;
    // 0x805E49C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805E49C4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x805E49C8: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805E49CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E49D0: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x805E49D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E49D8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x805E49DC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805E49E0: nop

    // 0x805E49E4: bc1f        L_805E49F4
    if (!c1cs) {
        // 0x805E49E8: nop
    
            goto L_805E49F4;
    }
    // 0x805E49E8: nop

    // 0x805E49EC: jal         0x805E4D78
    // 0x805E49F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805E4D78(rdram, ctx);
        goto after_2;
    // 0x805E49F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
L_805E49F4:
    // 0x805E49F4: jal         0x805E4674
    // 0x805E49F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4674(rdram, ctx);
        goto after_3;
    // 0x805E49F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805E49FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E4A00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E4A04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805E4A08: jr          $ra
    // 0x805E4A0C: nop

    return;
    // 0x805E4A0C: nop

;}
RECOMP_FUNC void func_8005D730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D730: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005D734: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8005D738: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x8005D73C: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x8005D740: lw          $a2, 0x8D0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8D0);
    // 0x8005D744: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005D748: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005D74C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005D750: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005D754: lw          $v0, 0x80($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X80);
    // 0x8005D758: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8005D75C: beql        $v0, $zero, L_8005D7DC
    if (ctx->r2 == 0) {
        // 0x8005D760: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005D7DC;
    }
    goto skip_0;
    // 0x8005D760: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8005D764: beql        $a2, $zero, L_8005D7DC
    if (ctx->r6 == 0) {
        // 0x8005D768: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005D7DC;
    }
    goto skip_1;
    // 0x8005D768: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8005D76C: lw          $t6, 0x78($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X78);
    // 0x8005D770: beql        $t6, $zero, L_8005D7DC
    if (ctx->r14 == 0) {
        // 0x8005D774: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005D7DC;
    }
    goto skip_2;
    // 0x8005D774: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8005D778: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8005D77C: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x8005D780: addiu       $s0, $a1, 0x4
    ctx->r16 = ADD32(ctx->r5, 0X4);
    // 0x8005D784: bnel        $t7, $t8, L_8005D7DC
    if (ctx->r15 != ctx->r24) {
        // 0x8005D788: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005D7DC;
    }
    goto skip_3;
    // 0x8005D788: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8005D78C: jal         0x8005D29C
    // 0x8005D790: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8005D29C(rdram, ctx);
        goto after_0;
    // 0x8005D790: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8005D794: beq         $v0, $zero, L_8005D7D8
    if (ctx->r2 == 0) {
        // 0x8005D798: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8005D7D8;
    }
    // 0x8005D798: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005D79C: addiu       $s2, $zero, 0x4001
    ctx->r18 = ADD32(0, 0X4001);
L_8005D7A0:
    // 0x8005D7A0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8005D7A4: lhu         $t9, 0xC($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XC);
    // 0x8005D7A8: bnel        $s2, $t9, L_8005D7BC
    if (ctx->r18 != ctx->r25) {
        // 0x8005D7AC: lh          $t0, 0x0($s1)
        ctx->r8 = MEM_H(ctx->r17, 0X0);
            goto L_8005D7BC;
    }
    goto skip_4;
    // 0x8005D7AC: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    skip_4:
    // 0x8005D7B0: jal         0x8002BEB0
    // 0x8005D7B4: nop

    func_8002BEB0(rdram, ctx);
        goto after_1;
    // 0x8005D7B4: nop

    after_1:
    // 0x8005D7B8: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
L_8005D7BC:
    // 0x8005D7BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8005D7C0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005D7C4: sh          $t1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r9;
    // 0x8005D7C8: jal         0x8005D29C
    // 0x8005D7CC: lw          $a0, 0x8D0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X8D0);
    func_8005D29C(rdram, ctx);
        goto after_2;
    // 0x8005D7CC: lw          $a0, 0x8D0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X8D0);
    after_2:
    // 0x8005D7D0: bne         $v0, $zero, L_8005D7A0
    if (ctx->r2 != 0) {
        // 0x8005D7D4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8005D7A0;
    }
    // 0x8005D7D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8005D7D8:
    // 0x8005D7D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005D7DC:
    // 0x8005D7DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005D7E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005D7E4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D7E8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005D7EC: jr          $ra
    // 0x8005D7F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005D7F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80056584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056584: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80056588: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8005658C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80056590: sw          $a2, 0x1BC($a0)
    MEM_W(0X1BC, ctx->r4) = ctx->r6;
    // 0x80056594: sw          $a1, 0x1B8($a0)
    MEM_W(0X1B8, ctx->r4) = ctx->r5;
    // 0x80056598: sw          $a3, 0x1C0($a0)
    MEM_W(0X1C0, ctx->r4) = ctx->r7;
    // 0x8005659C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800565A0: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800565A4: addiu       $t0, $a2, -0x1
    ctx->r8 = ADD32(ctx->r6, -0X1);
    // 0x800565A8: sw          $t6, 0x1C4($a0)
    MEM_W(0X1C4, ctx->r4) = ctx->r14;
    // 0x800565AC: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800565B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800565B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800565B8: sw          $t7, 0x1C8($a0)
    MEM_W(0X1C8, ctx->r4) = ctx->r15;
    // 0x800565BC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800565C0: sw          $zero, 0x1B0($a0)
    MEM_W(0X1B0, ctx->r4) = 0;
    // 0x800565C4: sw          $zero, 0x1B4($a0)
    MEM_W(0X1B4, ctx->r4) = 0;
    // 0x800565C8: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800565CC: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x800565D0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800565D4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800565D8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x800565DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800565E0: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x800565E4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800565E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800565EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800565F0: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800565F4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800565F8: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800565FC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80056600: mflo        $t6
    ctx->r14 = lo;
    // 0x80056604: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80056608: sw          $t7, 0x1CC($a0)
    MEM_W(0X1CC, ctx->r4) = ctx->r15;
    // 0x8005660C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80056610: sra         $t6, $a3, 1
    ctx->r14 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80056614: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80056618: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8005661C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80056620: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80056624: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80056628: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005662C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80056630: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056634: negu        $t6, $t8
    ctx->r14 = SUB32(0, ctx->r24);
    // 0x80056638: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8005663C: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80056640: mflo        $t8
    ctx->r24 = lo;
    // 0x80056644: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x80056648: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8005664C: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
    // 0x80056650: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80056654: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
L_80056658:
    // 0x80056658: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8005665C: lw          $a3, 0x1CC($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1CC);
    // 0x80056660: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80056664: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x80056668: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005666C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80056670: mflo        $t6
    ctx->r14 = lo;
    // 0x80056674: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80056678: addu        $t6, $t8, $t2
    ctx->r14 = ADD32(ctx->r24, ctx->r10);
    // 0x8005667C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80056680: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x80056684: blez        $a3, L_8005688C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80056688: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8005688C;
    }
    // 0x80056688: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
L_8005668C:
    // 0x8005668C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80056690: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80056694: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x80056698: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005669C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800566A0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800566A4: andi        $t5, $a1, 0x3
    ctx->r13 = ctx->r5 & 0X3;
    // 0x800566A8: blez        $a1, L_8005686C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800566AC: cvt.s.w     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8005686C;
    }
    // 0x800566AC: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800566B0: beql        $t5, $zero, L_80056730
    if (ctx->r13 == 0) {
        // 0x800566B4: trunc.w.s   $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80056730;
    }
    goto skip_0;
    // 0x800566B4: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_0:
    // 0x800566B8: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800566BC: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x800566C0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800566C4: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800566C8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800566CC: sll         $t3, $t3, 7
    ctx->r11 = S32(ctx->r11 << 7);
L_800566D0:
    // 0x800566D0: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800566D4: sh          $t0, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r8;
    // 0x800566D8: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
    // 0x800566DC: trunc.w.s   $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800566E0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800566E4: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x800566E8: sh          $t3, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r11;
    // 0x800566EC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800566F0: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x800566F4: sh          $t8, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r24;
    // 0x800566F8: sb          $s0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r16;
    // 0x800566FC: sb          $s0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r16;
    // 0x80056700: sb          $s0, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r16;
    // 0x80056704: sb          $s1, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r17;
    // 0x80056708: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x8005670C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80056710: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80056714: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80056718: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8005671C: bne         $t4, $a3, L_800566D0
    if (ctx->r12 != ctx->r7) {
        // 0x80056720: add.s       $f14, $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
            goto L_800566D0;
    }
    // 0x80056720: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80056724: beql        $a3, $a1, L_80056870
    if (ctx->r7 == ctx->r5) {
        // 0x80056728: lw          $t7, 0x1CC($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X1CC);
            goto L_80056870;
    }
    goto skip_1;
    // 0x80056728: lw          $t7, 0x1CC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1CC);
    skip_1:
    // 0x8005672C: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
L_80056730:
    // 0x80056730: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80056734: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80056738: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8005673C: sll         $t3, $t3, 7
    ctx->r11 = S32(ctx->r11 << 7);
L_80056740:
    // 0x80056740: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80056744: sh          $t0, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r8;
    // 0x80056748: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
    // 0x8005674C: trunc.w.s   $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80056750: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80056754: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80056758: sh          $t3, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r11;
    // 0x8005675C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80056760: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x80056764: sh          $t7, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r15;
    // 0x80056768: sb          $s0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r16;
    // 0x8005676C: sb          $s0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r16;
    // 0x80056770: sb          $s0, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r16;
    // 0x80056774: sb          $s1, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r17;
    // 0x80056778: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8005677C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80056780: sb          $s1, 0x1F($a2)
    MEM_B(0X1F, ctx->r6) = ctx->r17;
    // 0x80056784: sb          $s0, 0x1E($a2)
    MEM_B(0X1E, ctx->r6) = ctx->r16;
    // 0x80056788: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x8005678C: sb          $s0, 0x1D($a2)
    MEM_B(0X1D, ctx->r6) = ctx->r16;
    // 0x80056790: sb          $s0, 0x1C($a2)
    MEM_B(0X1C, ctx->r6) = ctx->r16;
    // 0x80056794: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80056798: sh          $t3, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r11;
    // 0x8005679C: sh          $zero, 0x16($a2)
    MEM_H(0X16, ctx->r6) = 0;
    // 0x800567A0: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800567A4: sh          $zero, 0x14($a2)
    MEM_H(0X14, ctx->r6) = 0;
    // 0x800567A8: sh          $t0, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r8;
    // 0x800567AC: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800567B0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800567B4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800567B8: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x800567BC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800567C0: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x800567C4: sh          $t8, -0x28($a2)
    MEM_H(-0X28, ctx->r6) = ctx->r24;
    // 0x800567C8: sh          $t9, -0x30($a2)
    MEM_H(-0X30, ctx->r6) = ctx->r25;
    // 0x800567CC: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800567D0: sb          $s1, -0x11($a2)
    MEM_B(-0X11, ctx->r6) = ctx->r17;
    // 0x800567D4: sb          $s0, -0x12($a2)
    MEM_B(-0X12, ctx->r6) = ctx->r16;
    // 0x800567D8: add.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x800567DC: sb          $s0, -0x13($a2)
    MEM_B(-0X13, ctx->r6) = ctx->r16;
    // 0x800567E0: sb          $s0, -0x14($a2)
    MEM_B(-0X14, ctx->r6) = ctx->r16;
    // 0x800567E4: add.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x800567E8: sh          $t3, -0x16($a2)
    MEM_H(-0X16, ctx->r6) = ctx->r11;
    // 0x800567EC: sh          $zero, -0x1A($a2)
    MEM_H(-0X1A, ctx->r6) = 0;
    // 0x800567F0: trunc.w.s   $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800567F4: sh          $zero, -0x1C($a2)
    MEM_H(-0X1C, ctx->r6) = 0;
    // 0x800567F8: sh          $t0, -0x1E($a2)
    MEM_H(-0X1E, ctx->r6) = ctx->r8;
    // 0x800567FC: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80056800: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80056804: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80056808: sll         $t9, $t8, 7
    ctx->r25 = S32(ctx->r24 << 7);
    // 0x8005680C: sh          $t9, -0x18($a2)
    MEM_H(-0X18, ctx->r6) = ctx->r25;
    // 0x80056810: sh          $t6, -0x20($a2)
    MEM_H(-0X20, ctx->r6) = ctx->r14;
    // 0x80056814: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80056818: sb          $s1, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r17;
    // 0x8005681C: sb          $s0, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r16;
    // 0x80056820: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80056824: sb          $s0, -0x3($a2)
    MEM_B(-0X3, ctx->r6) = ctx->r16;
    // 0x80056828: sb          $s0, -0x4($a2)
    MEM_B(-0X4, ctx->r6) = ctx->r16;
    // 0x8005682C: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x80056830: sh          $t3, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r11;
    // 0x80056834: sh          $zero, -0xA($a2)
    MEM_H(-0XA, ctx->r6) = 0;
    // 0x80056838: trunc.w.s   $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8005683C: sh          $zero, -0xC($a2)
    MEM_H(-0XC, ctx->r6) = 0;
    // 0x80056840: sh          $t0, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r8;
    // 0x80056844: trunc.w.s   $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    ctx->f10.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80056848: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8005684C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80056850: sll         $t6, $t9, 7
    ctx->r14 = S32(ctx->r25 << 7);
    // 0x80056854: sh          $t6, -0x8($a2)
    MEM_H(-0X8, ctx->r6) = ctx->r14;
    // 0x80056858: sh          $t7, -0x10($a2)
    MEM_H(-0X10, ctx->r6) = ctx->r15;
    // 0x8005685C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80056860: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x80056864: bne         $a3, $a1, L_80056740
    if (ctx->r7 != ctx->r5) {
        // 0x80056868: add.s       $f14, $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
            goto L_80056740;
    }
    // 0x80056868: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
L_8005686C:
    // 0x8005686C: lw          $t7, 0x1CC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1CC);
L_80056870:
    // 0x80056870: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80056874: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80056878: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005687C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80056880: bne         $at, $zero, L_8005668C
    if (ctx->r1 != 0) {
        // 0x80056884: add.s       $f2, $f2, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
            goto L_8005668C;
    }
    // 0x80056884: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80056888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005688C:
    // 0x8005688C: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80056890: bnel        $at, $zero, L_80056658
    if (ctx->r1 != 0) {
        // 0x80056894: sw          $zero, 0x14($sp)
        MEM_W(0X14, ctx->r29) = 0;
            goto L_80056658;
    }
    goto skip_2;
    // 0x80056894: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    skip_2:
    // 0x80056898: lw          $a3, 0x1CC($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1CC);
    // 0x8005689C: addiu       $a1, $a0, 0x1D0
    ctx->r5 = ADD32(ctx->r4, 0X1D0);
    // 0x800568A0: blezl       $a3, L_800568D4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800568A4: lw          $s0, 0x8($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X8);
            goto L_800568D4;
    }
    goto skip_3;
    // 0x800568A4: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    skip_3:
    // 0x800568A8: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
L_800568AC:
    // 0x800568AC: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x800568B0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x800568B4: sb          $s1, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r17;
    // 0x800568B8: lw          $t8, 0x1CC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1CC);
    // 0x800568BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800568C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800568C4: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800568C8: bnel        $at, $zero, L_800568AC
    if (ctx->r1 != 0) {
        // 0x800568CC: sb          $zero, 0x2($a1)
        MEM_B(0X2, ctx->r5) = 0;
            goto L_800568AC;
    }
    goto skip_4;
    // 0x800568CC: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    skip_4:
    // 0x800568D0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_800568D4:
    // 0x800568D4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800568D8: jr          $ra
    // 0x800568DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800568DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80799840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799840: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80799844: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80799848: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8079984C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80799850: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80799854: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80799858: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8079985C: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(826, 0X2520) << 16);
    // 0x80799860: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80799864: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80799868: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8079986C: lw          $t1, -0x4FC0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(826, 0X2520));
    // 0x80799870: jr          $ra
    // 0x80799874: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80799874: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80469900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469900: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80469904: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80469908: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8046990C: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80469910: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80469914: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80469918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8046991C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80469920: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80469924: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x80469928: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8046992C: bc1fl       L_8046993C
    if (!c1cs) {
        // 0x80469930: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_8046993C;
    }
    goto skip_0;
    // 0x80469930: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    skip_0:
    // 0x80469934: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80469938: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
L_8046993C:
    // 0x8046993C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80469940: lwc1        $f0, 0x1C($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80469944: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80469948: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8046994C: nop

    // 0x80469950: bc1fl       L_80469964
    if (!c1cs) {
        // 0x80469954: lwc1        $f10, 0x20($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
            goto L_80469964;
    }
    goto skip_1;
    // 0x80469954: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    skip_1:
    // 0x80469958: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8046995C: lwc1        $f0, 0x1C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80469960: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
L_80469964:
    // 0x80469964: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80469968: nop

    // 0x8046996C: bc1fl       L_80469988
    if (!c1cs) {
        // 0x80469970: lwc1        $f16, 0x24($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
            goto L_80469988;
    }
    goto skip_2;
    // 0x80469970: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
    skip_2:
    // 0x80469974: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x80469978: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x8046997C: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80469980: lwc1        $f0, 0x1C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80469984: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
L_80469988:
    // 0x80469988: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8046998C: nop

    // 0x80469990: bc1fl       L_804699AC
    if (!c1cs) {
        // 0x80469994: lwc1        $f18, 0x28($a0)
        ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
            goto L_804699AC;
    }
    goto skip_3;
    // 0x80469994: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    skip_3:
    // 0x80469998: addiu       $a1, $v1, 0x2
    ctx->r5 = ADD32(ctx->r3, 0X2);
    // 0x8046999C: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x804699A0: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x804699A4: lwc1        $f0, 0x1C($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x804699A8: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
L_804699AC:
    // 0x804699AC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x804699B0: nop

    // 0x804699B4: bc1fl       L_804699C4
    if (!c1cs) {
        // 0x804699B8: slti        $at, $a1, 0x6
        ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
            goto L_804699C4;
    }
    goto skip_4;
    // 0x804699B8: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    skip_4:
    // 0x804699BC: addiu       $a1, $v1, 0x3
    ctx->r5 = ADD32(ctx->r3, 0X3);
    // 0x804699C0: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
L_804699C4:
    // 0x804699C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804699C8: bne         $at, $zero, L_804699D4
    if (ctx->r1 != 0) {
        // 0x804699CC: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_804699D4;
    }
    // 0x804699CC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x804699D0: addiu       $v1, $a0, -0x6
    ctx->r3 = ADD32(ctx->r4, -0X6);
L_804699D4:
    // 0x804699D4: bne         $v1, $a3, L_804699E0
    if (ctx->r3 != ctx->r7) {
        // 0x804699D8: addiu       $a0, $v1, 0x1
        ctx->r4 = ADD32(ctx->r3, 0X1);
            goto L_804699E0;
    }
    // 0x804699D8: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x804699DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_804699E0:
    // 0x804699E0: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x804699E4: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x804699E8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x804699EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804699F0: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x804699F4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x804699F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x804699FC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80469A00: addu        $a2, $a1, $a0
    ctx->r6 = ADD32(ctx->r5, ctx->r4);
    // 0x80469A04: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80469A08: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x80469A0C: bc1f        L_80469A30
    if (!c1cs) {
        // 0x80469A10: nop
    
            goto L_80469A30;
    }
    // 0x80469A10: nop

    // 0x80469A14: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80469A18: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80469A1C: nop

    // 0x80469A20: bc1f        L_80469A30
    if (!c1cs) {
        // 0x80469A24: nop
    
            goto L_80469A30;
    }
    // 0x80469A24: nop

    // 0x80469A28: jr          $ra
    // 0x80469A2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80469A2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80469A30:
    // 0x80469A30: bne         $at, $zero, L_80469A3C
    if (ctx->r1 != 0) {
        // 0x80469A34: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80469A3C;
    }
    // 0x80469A34: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80469A38: addiu       $v1, $a2, -0x6
    ctx->r3 = ADD32(ctx->r6, -0X6);
L_80469A3C:
    // 0x80469A3C: bne         $v1, $a3, L_80469A48
    if (ctx->r3 != ctx->r7) {
        // 0x80469A40: addiu       $a0, $v1, 0x1
        ctx->r4 = ADD32(ctx->r3, 0X1);
            goto L_80469A48;
    }
    // 0x80469A40: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80469A44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80469A48:
    // 0x80469A48: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80469A4C: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80469A50: lwc1        $f8, 0x1C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80469A54: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80469A58: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x80469A5C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80469A60: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x80469A64: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80469A68: bc1f        L_80469A8C
    if (!c1cs) {
        // 0x80469A6C: nop
    
            goto L_80469A8C;
    }
    // 0x80469A6C: nop

    // 0x80469A70: lwc1        $f10, 0x1C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80469A74: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80469A78: nop

    // 0x80469A7C: bc1f        L_80469A8C
    if (!c1cs) {
        // 0x80469A80: nop
    
            goto L_80469A8C;
    }
    // 0x80469A80: nop

    // 0x80469A84: jr          $ra
    // 0x80469A88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80469A88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80469A8C:
    // 0x80469A8C: bne         $at, $zero, L_80469A98
    if (ctx->r1 != 0) {
        // 0x80469A90: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80469A98;
    }
    // 0x80469A90: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80469A94: addiu       $v1, $a0, -0x6
    ctx->r3 = ADD32(ctx->r4, -0X6);
L_80469A98:
    // 0x80469A98: bne         $v1, $a3, L_80469AA4
    if (ctx->r3 != ctx->r7) {
        // 0x80469A9C: addiu       $a0, $v1, 0x1
        ctx->r4 = ADD32(ctx->r3, 0X1);
            goto L_80469AA4;
    }
    // 0x80469A9C: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80469AA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80469AA4:
    // 0x80469AA4: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80469AA8: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80469AAC: lwc1        $f16, 0x1C($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80469AB0: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80469AB4: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80469AB8: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80469ABC: addiu       $a0, $a2, 0x2
    ctx->r4 = ADD32(ctx->r6, 0X2);
    // 0x80469AC0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80469AC4: bc1f        L_80469AE8
    if (!c1cs) {
        // 0x80469AC8: nop
    
            goto L_80469AE8;
    }
    // 0x80469AC8: nop

    // 0x80469ACC: lwc1        $f18, 0x1C($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80469AD0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80469AD4: nop

    // 0x80469AD8: bc1f        L_80469AE8
    if (!c1cs) {
        // 0x80469ADC: nop
    
            goto L_80469AE8;
    }
    // 0x80469ADC: nop

    // 0x80469AE0: jr          $ra
    // 0x80469AE4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80469AE4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80469AE8:
    // 0x80469AE8: bne         $at, $zero, L_80469AF4
    if (ctx->r1 != 0) {
        // 0x80469AEC: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80469AF4;
    }
    // 0x80469AEC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80469AF0: addiu       $v1, $a0, -0x6
    ctx->r3 = ADD32(ctx->r4, -0X6);
L_80469AF4:
    // 0x80469AF4: bne         $v1, $a3, L_80469B00
    if (ctx->r3 != ctx->r7) {
        // 0x80469AF8: addiu       $a0, $v1, 0x1
        ctx->r4 = ADD32(ctx->r3, 0X1);
            goto L_80469B00;
    }
    // 0x80469AF8: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80469AFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80469B00:
    // 0x80469B00: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80469B04: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80469B08: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80469B0C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80469B10: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80469B14: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80469B18: addiu       $a0, $a2, 0x3
    ctx->r4 = ADD32(ctx->r6, 0X3);
    // 0x80469B1C: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x80469B20: bc1f        L_80469B44
    if (!c1cs) {
        // 0x80469B24: nop
    
            goto L_80469B44;
    }
    // 0x80469B24: nop

    // 0x80469B28: lwc1        $f6, 0x1C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80469B2C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80469B30: nop

    // 0x80469B34: bc1f        L_80469B44
    if (!c1cs) {
        // 0x80469B38: nop
    
            goto L_80469B44;
    }
    // 0x80469B38: nop

    // 0x80469B3C: jr          $ra
    // 0x80469B40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80469B40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80469B44:
    // 0x80469B44: bne         $at, $zero, L_80469B50
    if (ctx->r1 != 0) {
        // 0x80469B48: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80469B50;
    }
    // 0x80469B48: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80469B4C: addiu       $v1, $a0, -0x6
    ctx->r3 = ADD32(ctx->r4, -0X6);
L_80469B50:
    // 0x80469B50: bne         $v1, $a3, L_80469B5C
    if (ctx->r3 != ctx->r7) {
        // 0x80469B54: addiu       $a0, $v1, 0x1
        ctx->r4 = ADD32(ctx->r3, 0X1);
            goto L_80469B5C;
    }
    // 0x80469B54: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80469B58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80469B5C:
    // 0x80469B5C: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x80469B60: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80469B64: lwc1        $f8, 0x1C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80469B68: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80469B6C: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80469B70: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80469B74: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80469B78: bc1f        L_80469B9C
    if (!c1cs) {
        // 0x80469B7C: nop
    
            goto L_80469B9C;
    }
    // 0x80469B7C: nop

    // 0x80469B80: lwc1        $f10, 0x1C($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80469B84: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80469B88: nop

    // 0x80469B8C: bc1f        L_80469B9C
    if (!c1cs) {
        // 0x80469B90: nop
    
            goto L_80469B9C;
    }
    // 0x80469B90: nop

    // 0x80469B94: jr          $ra
    // 0x80469B98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80469B98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80469B9C:
    // 0x80469B9C: jr          $ra
    // 0x80469BA0: nop

    return;
    // 0x80469BA0: nop

;}
RECOMP_FUNC void func_807B966C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B966C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B9670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9674: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B9678: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807B967C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B9680: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x807B9684: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B9688: sb          $t6, 0x165($t7)
    MEM_B(0X165, ctx->r15) = ctx->r14;
    // 0x807B968C: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x807B9690: blez        $v1, L_807B96A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x807B9694: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_807B96A0;
    }
    // 0x807B9694: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x807B9698: b           L_807B96A8
    // 0x807B969C: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
        goto L_807B96A8;
    // 0x807B969C: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
L_807B96A0:
    // 0x807B96A0: jal         0x807B9E2C
    // 0x807B96A4: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    func_807B9E2C(rdram, ctx);
        goto after_0;
    // 0x807B96A4: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    after_0:
L_807B96A8:
    // 0x807B96A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B96AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B96B0: jr          $ra
    // 0x807B96B4: nop

    return;
    // 0x807B96B4: nop

;}
RECOMP_FUNC void func_805A1DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1DB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A1DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A1DBC: jal         0x805A1848
    // 0x805A1DC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A1848(rdram, ctx);
        goto after_0;
    // 0x805A1DC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A1DC4: jal         0x805A1BA8
    // 0x805A1DC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805A1BA8(rdram, ctx);
        goto after_1;
    // 0x805A1DC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805A1DCC: jal         0x805A1D44
    // 0x805A1DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805A1D44(rdram, ctx);
        goto after_2;
    // 0x805A1DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x805A1DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A1DD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A1DDC: jr          $ra
    // 0x805A1DE0: nop

    return;
    // 0x805A1DE0: nop

;}
RECOMP_FUNC void func_805DCDB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCDB8: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(480, 0X2014) << 16);
    // 0x805DCDBC: addiu       $t6, $t6, -0x32EC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(480, 0X2014));
    // 0x805DCDC0: jr          $ra
    // 0x805DCDC4: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
    return;
    // 0x805DCDC4: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8004A940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A940: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8004A944: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004A948: jr          $ra
    // 0x8004A94C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8004A94C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80742B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742B24: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742B28: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742B2C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742B30: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742B34: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742B38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742B3C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742B40: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742B44: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742B48: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742B4C: jr          $ra
    // 0x80742B50: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742B50: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80716438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716438: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8071643C: beql        $at, $zero, L_80716450
    if (ctx->r1 == 0) {
        // 0x80716440: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80716450;
    }
    goto skip_0;
    // 0x80716440: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x80716444: jr          $ra
    // 0x80716448: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    return;
    // 0x80716448: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8071644C: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_80716450:
    // 0x80716450: beq         $at, $zero, L_80716488
    if (ctx->r1 == 0) {
        // 0x80716454: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_80716488;
    }
    // 0x80716454: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x80716458: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8071645C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80716460: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80716464: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80716468: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x8071646C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80716470: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80716474: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80716478: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8071647C: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80716480: jr          $ra
    // 0x80716484: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x80716484: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_80716488:
    // 0x80716488: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8071648C: beq         $at, $zero, L_807164C8
    if (ctx->r1 == 0) {
        // 0x80716490: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_807164C8;
    }
    // 0x80716490: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80716494: subu        $t8, $a0, $a2
    ctx->r24 = SUB32(ctx->r4, ctx->r6);
    // 0x80716498: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8071649C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x807164A0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x807164A4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807164A8: subu        $t9, $a3, $a2
    ctx->r25 = SUB32(ctx->r7, ctx->r6);
    // 0x807164AC: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x807164B0: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x807164B4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807164B8: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x807164BC: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x807164C0: jr          $ra
    // 0x807164C4: add.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f12.fl;
    return;
    // 0x807164C4: add.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f12.fl;
L_807164C8:
    // 0x807164C8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x807164CC: beq         $at, $zero, L_80716508
    if (ctx->r1 == 0) {
        // 0x807164D0: subu        $t0, $a0, $a3
        ctx->r8 = SUB32(ctx->r4, ctx->r7);
            goto L_80716508;
    }
    // 0x807164D0: subu        $t0, $a0, $a3
    ctx->r8 = SUB32(ctx->r4, ctx->r7);
    // 0x807164D4: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x807164D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807164DC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807164E0: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x807164E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807164E8: subu        $t1, $v0, $a3
    ctx->r9 = SUB32(ctx->r2, ctx->r7);
    // 0x807164EC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x807164F0: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x807164F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807164F8: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x807164FC: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80716500: jr          $ra
    // 0x80716504: add.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f2.fl;
    return;
    // 0x80716504: add.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f2.fl;
L_80716508:
    // 0x80716508: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8071650C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80716510: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80716514: beq         $at, $zero, L_80716528
    if (ctx->r1 == 0) {
        // 0x80716518: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80716528;
    }
    // 0x80716518: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8071651C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80716520: jr          $ra
    // 0x80716524: nop

    return;
    // 0x80716524: nop

L_80716528:
    // 0x80716528: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8071652C: beq         $at, $zero, L_80716568
    if (ctx->r1 == 0) {
        // 0x80716530: subu        $t2, $a0, $v0
        ctx->r10 = SUB32(ctx->r4, ctx->r2);
            goto L_80716568;
    }
    // 0x80716530: subu        $t2, $a0, $v0
    ctx->r10 = SUB32(ctx->r4, ctx->r2);
    // 0x80716534: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80716538: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8071653C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80716540: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80716544: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80716548: subu        $t3, $v1, $v0
    ctx->r11 = SUB32(ctx->r3, ctx->r2);
    // 0x8071654C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80716550: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80716554: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80716558: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8071655C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80716560: jr          $ra
    // 0x80716564: sub.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f18.fl;
    return;
    // 0x80716564: sub.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f18.fl;
L_80716568:
    // 0x80716568: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8071656C: subu        $t4, $a0, $v1
    ctx->r12 = SUB32(ctx->r4, ctx->r3);
    // 0x80716570: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80716574: beql        $at, $zero, L_807165B0
    if (ctx->r1 == 0) {
        // 0x80716578: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_807165B0;
    }
    goto skip_1;
    // 0x80716578: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x8071657C: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80716580: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80716584: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80716588: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8071658C: subu        $t5, $v0, $v1
    ctx->r13 = SUB32(ctx->r2, ctx->r3);
    // 0x80716590: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80716594: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80716598: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8071659C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x807165A0: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x807165A4: jr          $ra
    // 0x807165A8: sub.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f6.fl;
    return;
    // 0x807165A8: sub.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x807165AC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_807165B0:
    // 0x807165B0: subu        $t6, $a0, $v0
    ctx->r14 = SUB32(ctx->r4, ctx->r2);
    // 0x807165B4: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807165B8: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x807165BC: beq         $at, $zero, L_807165F4
    if (ctx->r1 == 0) {
        // 0x807165C0: nop
    
            goto L_807165F4;
    }
    // 0x807165C0: nop

    // 0x807165C4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x807165C8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807165CC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807165D0: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807165D4: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x807165D8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x807165DC: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x807165E0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807165E4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x807165E8: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x807165EC: jr          $ra
    // 0x807165F0: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x807165F0: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_807165F4:
    // 0x807165F4: jr          $ra
    // 0x807165F8: nop

    return;
    // 0x807165F8: nop

;}
RECOMP_FUNC void func_80536294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536294: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536298: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053629C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805362A0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805362A4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805362A8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805362AC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805362B0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805362B4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805362B8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805362BC: jr          $ra
    // 0x805362C0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805362C0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804B8B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B8B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B8B18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B8B1C: jal         0x80045A34
    // 0x804B8B20: addiu       $a1, $zero, 0x478
    ctx->r5 = ADD32(0, 0X478);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804B8B20: addiu       $a1, $zero, 0x478
    ctx->r5 = ADD32(0, 0X478);
    after_0:
    // 0x804B8B24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B8B28: bne         $v0, $zero, L_804B8B38
    if (ctx->r2 != 0) {
        // 0x804B8B2C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804B8B38;
    }
    // 0x804B8B2C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804B8B30: b           L_804B8B44
    // 0x804B8B34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804B8B44;
    // 0x804B8B34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804B8B38:
    // 0x804B8B38: jal         0x804B8AC0
    // 0x804B8B3C: nop

    func_804B8AC0(rdram, ctx);
        goto after_1;
    // 0x804B8B3C: nop

    after_1:
    // 0x804B8B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804B8B44:
    // 0x804B8B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B8B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B8B4C: jr          $ra
    // 0x804B8B50: nop

    return;
    // 0x804B8B50: nop

;}
RECOMP_FUNC void func_804630D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804630D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804630DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804630E0: jal         0x80462F34
    // 0x804630E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80462F34(rdram, ctx);
        goto after_0;
    // 0x804630E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804630E8: bne         $v0, $zero, L_804630F8
    if (ctx->r2 != 0) {
        // 0x804630EC: nop
    
            goto L_804630F8;
    }
    // 0x804630EC: nop

    // 0x804630F0: b           L_80463114
    // 0x804630F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80463114;
    // 0x804630F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804630F8:
    // 0x804630F8: jal         0x80462FE4
    // 0x804630FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80462FE4(rdram, ctx);
        goto after_1;
    // 0x804630FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80463100: bnel        $v0, $zero, L_80463114
    if (ctx->r2 != 0) {
        // 0x80463104: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80463114;
    }
    goto skip_0;
    // 0x80463104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80463108: b           L_80463114
    // 0x8046310C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80463114;
    // 0x8046310C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80463110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80463114:
    // 0x80463114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80463118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046311C: jr          $ra
    // 0x80463120: nop

    return;
    // 0x80463120: nop

;}
RECOMP_FUNC void func_8044B464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B464: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044B468: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13534) << 16);
    // 0x8044B46C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B470: addiu       $t6, $t6, 0x7914
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13534));
    // 0x8044B474: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044B478: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044B47C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044B480: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044B484: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044B488: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B48C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044B490: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044B494: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044B498: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044B49C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044B4A0: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044B4A4: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B4A8: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044B4AC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044B4B0: jal         0x80050A50
    // 0x8044B4B4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044B4B4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044B4B8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044B4BC: jalr        $v0
    // 0x8044B4C0: sw          $v0, 0x6A78($v1)
    MEM_W(0X6A78, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044B4C0: sw          $v0, 0x6A78($v1)
    MEM_W(0X6A78, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044B4C4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B4C8: sw          $v0, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->r2;
    // 0x8044B4CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B4D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044B4D4: jr          $ra
    // 0x8044B4D8: nop

    return;
    // 0x8044B4D8: nop

;}
RECOMP_FUNC void func_80680794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680794: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80680798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8068079C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806807A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806807A4: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x806807A8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x806807AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806807B0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806807B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806807B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806807BC: jal         0x80062AEC
    // 0x806807C0: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x806807C0: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    after_0:
    // 0x806807C4: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x806807C8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806807CC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x806807D0: bne         $t7, $at, L_8068091C
    if (ctx->r15 != ctx->r1) {
        // 0x806807D4: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_8068091C;
    }
    // 0x806807D4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x806807D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806807DC: beq         $v0, $at, L_806807FC
    if (ctx->r2 == ctx->r1) {
        // 0x806807E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_806807FC;
    }
    // 0x806807E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806807E4: beq         $v0, $at, L_80680854
    if (ctx->r2 == ctx->r1) {
        // 0x806807E8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80680854;
    }
    // 0x806807E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806807EC: beql        $v0, $at, L_806808B0
    if (ctx->r2 == ctx->r1) {
        // 0x806807F0: lw          $t2, 0x174($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X174);
            goto L_806808B0;
    }
    goto skip_0;
    // 0x806807F0: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    skip_0:
    // 0x806807F4: b           L_80680920
    // 0x806807F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80680920;
    // 0x806807F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806807FC:
    // 0x806807FC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X223C) << 16);
    // 0x80680800: lwc1        $f4, 0x264C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X223C));
    // 0x80680804: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80680808: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8068080C: nop

    // 0x80680810: bc1fl       L_80680840
    if (!c1cs) {
        // 0x80680814: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80680840;
    }
    goto skip_1;
    // 0x80680814: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x80680818: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8068081C: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80680820: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80680824: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80680828: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8068082C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80680830: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80680834: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80680838: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x8068083C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80680840:
    // 0x80680840: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80680844: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x80680848: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8068084C: b           L_8068091C
    // 0x80680850: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
        goto L_8068091C;
    // 0x80680850: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_80680854:
    // 0x80680854: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2240) << 16);
    // 0x80680858: lwc1        $f16, 0x2650($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2240));
    // 0x8068085C: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80680860: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80680864: nop

    // 0x80680868: bc1fl       L_80680898
    if (!c1cs) {
        // 0x8068086C: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80680898;
    }
    goto skip_2;
    // 0x8068086C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_2:
    // 0x80680870: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80680874: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80680878: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8068087C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80680880: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80680884: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80680888: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8068088C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80680890: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x80680894: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80680898:
    // 0x80680898: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8068089C: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x806808A0: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x806808A4: b           L_8068091C
    // 0x806808A8: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
        goto L_8068091C;
    // 0x806808A8: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
    // 0x806808AC: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
L_806808B0:
    // 0x806808B0: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2244) << 16);
    // 0x806808B4: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x806808B8: bnel        $t3, $zero, L_80680920
    if (ctx->r11 != 0) {
        // 0x806808BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80680920;
    }
    goto skip_3;
    // 0x806808BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806808C0: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806808C4: lwc1        $f6, 0x2654($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2244));
    // 0x806808C8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806808CC: nop

    // 0x806808D0: bc1fl       L_80680910
    if (!c1cs) {
        // 0x806808D4: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80680910;
    }
    goto skip_4;
    // 0x806808D4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_4:
    // 0x806808D8: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806808DC: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806808E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806808E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806808E8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x806808EC: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806808F0: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2248) << 16);
    // 0x806808F4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806808F8: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x806808FC: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x80680900: lwc1        $f8, 0x2658($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2248));
    // 0x80680904: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80680908: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    // 0x8068090C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80680910:
    // 0x80680910: lw          $t4, 0x34($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X34);
    // 0x80680914: ori         $t5, $t4, 0x3000
    ctx->r13 = ctx->r12 | 0X3000;
    // 0x80680918: sw          $t5, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r13;
L_8068091C:
    // 0x8068091C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80680920:
    // 0x80680920: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80680924: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80680928: jr          $ra
    // 0x8068092C: nop

    return;
    // 0x8068092C: nop

;}
RECOMP_FUNC void func_80472BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80472BFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80472C00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80472C04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80472C08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80472C0C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80472C10: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80472C14: lwc1        $f20, 0x6C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80472C18: jal         0x80471530
    // 0x80472C1C: lw          $a1, 0x24($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X24);
    func_80471530(rdram, ctx);
        goto after_0;
    // 0x80472C1C: lw          $a1, 0x24($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X24);
    after_0:
    // 0x80472C20: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80472C24: jal         0x80048F84
    // 0x80472C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80472C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80472C2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80472C30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80472C34: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(158, 0X1B00) << 16);
    // 0x80472C38: lwc1        $f4, 0x2FC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(158, 0X1B00));
    // 0x80472C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80472C40: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x80472C44: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80472C48: nop

    // 0x80472C4C: bc1fl       L_80472C74
    if (!c1cs) {
        // 0x80472C50: swc1        $f20, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
            goto L_80472C74;
    }
    goto skip_0;
    // 0x80472C50: swc1        $f20, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x80472C54: jal         0x804715A4
    // 0x80472C58: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_804715A4(rdram, ctx);
        goto after_2;
    // 0x80472C58: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x80472C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80472C60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80472C64: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80472C68: jal         0x80472C94
    // 0x80472C6C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80472C94(rdram, ctx);
        goto after_3;
    // 0x80472C6C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x80472C70: swc1        $f20, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
L_80472C74:
    // 0x80472C74: swc1        $f20, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f20.u32l;
    // 0x80472C78: jal         0x804726F4
    // 0x80472C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804726F4(rdram, ctx);
        goto after_4;
    // 0x80472C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80472C80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80472C84: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80472C88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80472C8C: jr          $ra
    // 0x80472C90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80472C90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80006720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006720: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80006724: bne         $a0, $at, L_80006734
    if (ctx->r4 != ctx->r1) {
        // 0x80006728: lui         $t6, 0x800B
        ctx->r14 = S32(0X800B << 16);
            goto L_80006734;
    }
    // 0x80006728: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8000672C: jr          $ra
    // 0x80006730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80006730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80006734:
    // 0x80006734: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80006738: lbu         $t6, 0x7660($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7660);
    // 0x8000673C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80006740: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80006744: bne         $at, $zero, L_80006754
    if (ctx->r1 != 0) {
        // 0x80006748: nop
    
            goto L_80006754;
    }
    // 0x80006748: nop

    // 0x8000674C: jr          $ra
    // 0x80006750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80006750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80006754:
    // 0x80006754: jr          $ra
    // 0x80006758: nop

    return;
    // 0x80006758: nop

;}
RECOMP_FUNC void func_8079968C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079968C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80799690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799694: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80799698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8079969C: beq         $t6, $zero, L_807996D8
    if (ctx->r14 == 0) {
        // 0x807996A0: nop
    
            goto L_807996D8;
    }
    // 0x807996A0: nop

    // 0x807996A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807996A8: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x807996AC: jalr        $t9
    // 0x807996B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x807996B0: nop

    after_0:
    // 0x807996B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807996B8: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x807996BC: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x807996C0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x807996C4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x807996C8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x807996CC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x807996D0: b           L_807996D8
    // 0x807996D4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_807996D8;
    // 0x807996D4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_807996D8:
    // 0x807996D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807996DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807996E0: jr          $ra
    // 0x807996E4: nop

    return;
    // 0x807996E4: nop

;}
RECOMP_FUNC void func_80799DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80799DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799DAC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80799DB0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80799DB4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80799DB8: lui         $t8, 0x807A
    ctx->r24 = S32(RELOC_HI16(826, 0X244C) << 16);
    // 0x80799DBC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80799DC0: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80799DC4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80799DC8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80799DCC: lw          $t8, -0x5094($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(826, 0X244C));
    // 0x80799DD0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80799DD4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80799DD8: jal         0x80048490
    // 0x80799DDC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80799DDC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80799DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80799DE8: jr          $ra
    // 0x80799DEC: nop

    return;
    // 0x80799DEC: nop

;}
RECOMP_FUNC void func_804C0364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0364: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C0368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C036C: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804C0370: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804C0374: jal         0x804C0188
    // 0x804C0378: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804C0188(rdram, ctx);
        goto after_0;
    // 0x804C0378: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804C037C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804C0380: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(194, 0X334) << 16);
    // 0x804C0384: lwc1        $f8, 0x444($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(194, 0X334));
    // 0x804C0388: lh          $t6, 0x13C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X13C);
    // 0x804C038C: lwc1        $f16, 0x70($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X70);
    // 0x804C0390: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804C0394: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x804C0398: nop

    // 0x804C039C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804C03A0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804C03A4: nop

    // 0x804C03A8: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x804C03AC: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x804C03B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C03B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C03B8: jr          $ra
    // 0x804C03BC: nop

    return;
    // 0x804C03BC: nop

;}
RECOMP_FUNC void func_80038850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038858: jal         0x80021958
    // 0x8003885C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x8003885C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038860: bne         $v0, $zero, L_80038870
    if (ctx->r2 != 0) {
        // 0x80038864: nop
    
            goto L_80038870;
    }
    // 0x80038864: nop

    // 0x80038868: b           L_800388A4
    // 0x8003886C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800388A4;
    // 0x8003886C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038870:
    // 0x80038870: jal         0x80033FB0
    // 0x80038874: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033FB0(rdram, ctx);
        goto after_1;
    // 0x80038874: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80038878: beq         $v0, $zero, L_80038888
    if (ctx->r2 == 0) {
        // 0x8003887C: nop
    
            goto L_80038888;
    }
    // 0x8003887C: nop

    // 0x80038880: b           L_800388A4
    // 0x80038884: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800388A4;
    // 0x80038884: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038888:
    // 0x80038888: jal         0x800387C0
    // 0x8003888C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800387C0(rdram, ctx);
        goto after_2;
    // 0x8003888C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80038890: bnel        $v0, $zero, L_800388A4
    if (ctx->r2 != 0) {
        // 0x80038894: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800388A4;
    }
    goto skip_0;
    // 0x80038894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80038898: b           L_800388A4
    // 0x8003889C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800388A4;
    // 0x8003889C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800388A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800388A4:
    // 0x800388A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800388A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800388AC: jr          $ra
    // 0x800388B0: nop

    return;
    // 0x800388B0: nop

;}
RECOMP_FUNC void func_800495AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800495AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800495B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800495B4: jal         0x800494C4
    // 0x800495B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800494C4(rdram, ctx);
        goto after_0;
    // 0x800495B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800495BC: jal         0x80049524
    // 0x800495C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80049524(rdram, ctx);
        goto after_1;
    // 0x800495C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800495C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800495C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800495CC: jr          $ra
    // 0x800495D0: nop

    return;
    // 0x800495D0: nop

;}
RECOMP_FUNC void func_8067BF5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BF5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067BF60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067BF64: jal         0x8067A070
    // 0x8067BF68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8067A070(rdram, ctx);
        goto after_0;
    // 0x8067BF68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8067BF6C: jal         0x80045BD8
    // 0x8067BF70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8067BF70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8067BF74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067BF78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067BF7C: jr          $ra
    // 0x8067BF80: nop

    return;
    // 0x8067BF80: nop

;}
RECOMP_FUNC void func_8046A018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A018: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8046A01C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046A020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046A024: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046A028: jal         0x8004700C
    // 0x8046A02C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8046A02C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8046A030: beq         $v0, $zero, L_8046A0CC
    if (ctx->r2 == 0) {
        // 0x8046A034: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8046A0CC;
    }
    // 0x8046A034: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8046A038: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8046A03C: lw          $t7, 0x180($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X180);
    // 0x8046A040: bnel        $t6, $t7, L_8046A0D0
    if (ctx->r14 != ctx->r15) {
        // 0x8046A044: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046A0D0;
    }
    goto skip_0;
    // 0x8046A044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8046A048: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8046A04C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8046A050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8046A054: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8046A058: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8046A05C: swc1        $f6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f6.u32l;
L_8046A060:
    // 0x8046A060: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x8046A064: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8046A068: beql        $v1, $zero, L_8046A080
    if (ctx->r3 == 0) {
        // 0x8046A06C: lw          $v1, 0x18C($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X18C);
            goto L_8046A080;
    }
    goto skip_1;
    // 0x8046A06C: lw          $v1, 0x18C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18C);
    skip_1:
    // 0x8046A070: lwc1        $f8, 0x44($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8046A074: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8046A078: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
    // 0x8046A07C: lw          $v1, 0x18C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18C);
L_8046A080:
    // 0x8046A080: beql        $v1, $zero, L_8046A098
    if (ctx->r3 == 0) {
        // 0x8046A084: lw          $v1, 0x190($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X190);
            goto L_8046A098;
    }
    goto skip_2;
    // 0x8046A084: lw          $v1, 0x190($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X190);
    skip_2:
    // 0x8046A088: lwc1        $f16, 0x44($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8046A08C: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8046A090: swc1        $f18, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f18.u32l;
    // 0x8046A094: lw          $v1, 0x190($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X190);
L_8046A098:
    // 0x8046A098: beql        $v1, $zero, L_8046A0B0
    if (ctx->r3 == 0) {
        // 0x8046A09C: lw          $v1, 0x194($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X194);
            goto L_8046A0B0;
    }
    goto skip_3;
    // 0x8046A09C: lw          $v1, 0x194($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X194);
    skip_3:
    // 0x8046A0A0: lwc1        $f4, 0x44($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8046A0A4: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8046A0A8: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x8046A0AC: lw          $v1, 0x194($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X194);
L_8046A0B0:
    // 0x8046A0B0: beq         $v1, $zero, L_8046A0C4
    if (ctx->r3 == 0) {
        // 0x8046A0B4: nop
    
            goto L_8046A0C4;
    }
    // 0x8046A0B4: nop

    // 0x8046A0B8: lwc1        $f8, 0x44($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X44);
    // 0x8046A0BC: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8046A0C0: swc1        $f10, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f10.u32l;
L_8046A0C4:
    // 0x8046A0C4: bne         $a1, $a2, L_8046A060
    if (ctx->r5 != ctx->r6) {
        // 0x8046A0C8: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8046A060;
    }
    // 0x8046A0C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_8046A0CC:
    // 0x8046A0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046A0D0:
    // 0x8046A0D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046A0D4: jr          $ra
    // 0x8046A0D8: nop

    return;
    // 0x8046A0D8: nop

;}
RECOMP_FUNC void func_804A3D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A3D4C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804A3D50: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x804A3D54: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x804A3D58: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x804A3D5C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x804A3D60: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x804A3D64: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804A3D68: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804A3D6C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804A3D70: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804A3D74: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804A3D78: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804A3D7C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804A3D80: lwc1        $f28, 0x3C($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A3D84: addiu       $s0, $v0, 0x188
    ctx->r16 = ADD32(ctx->r2, 0X188);
    // 0x804A3D88: lwc1        $f26, 0x40($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A3D8C: bne         $s0, $zero, L_804A3D9C
    if (ctx->r16 != 0) {
        // 0x804A3D90: lh          $s1, 0x184($v0)
        ctx->r17 = MEM_H(ctx->r2, 0X184);
            goto L_804A3D9C;
    }
    // 0x804A3D90: lh          $s1, 0x184($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X184);
    // 0x804A3D94: b           L_804A3E3C
    // 0x804A3D98: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_804A3E3C;
    // 0x804A3D98: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_804A3D9C:
    // 0x804A3D9C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A3DA0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x804A3DA4: beq         $s1, $zero, L_804A3E18
    if (ctx->r17 == 0) {
        // 0x804A3DA8: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_804A3E18;
    }
    // 0x804A3DA8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_804A3DAC:
    // 0x804A3DAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804A3DB0: beq         $v0, $zero, L_804A3E10
    if (ctx->r2 == 0) {
        // 0x804A3DB4: nop
    
            goto L_804A3E10;
    }
    // 0x804A3DB4: nop

    // 0x804A3DB8: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A3DBC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x804A3DC0: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x804A3DC4: c.lt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl < ctx->f0.fl;
    // 0x804A3DC8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804A3DCC: bc1f        L_804A3E10
    if (!c1cs) {
        // 0x804A3DD0: nop
    
            goto L_804A3E10;
    }
    // 0x804A3DD0: nop

    // 0x804A3DD4: lwc1        $f14, 0x3C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A3DD8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x804A3DDC: jal         0x804A3C08
    // 0x804A3DE0: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_804A3C08(rdram, ctx);
        goto after_0;
    // 0x804A3DE0: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_0:
    // 0x804A3DE4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x804A3DE8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x804A3DEC: jal         0x804A3C08
    // 0x804A3DF0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_804A3C08(rdram, ctx);
        goto after_1;
    // 0x804A3DF0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x804A3DF4: add.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x804A3DF8: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x804A3DFC: nop

    // 0x804A3E00: bc1f        L_804A3E10
    if (!c1cs) {
        // 0x804A3E04: nop
    
            goto L_804A3E10;
    }
    // 0x804A3E04: nop

    // 0x804A3E08: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x804A3E0C: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_804A3E10:
    // 0x804A3E10: bne         $s1, $zero, L_804A3DAC
    if (ctx->r17 != 0) {
        // 0x804A3E14: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_804A3DAC;
    }
    // 0x804A3E14: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_804A3E18:
    // 0x804A3E18: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A3E1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A3E20: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x804A3E24: c.le.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl <= ctx->f24.fl;
    // 0x804A3E28: nop

    // 0x804A3E2C: bc1f        L_804A3E3C
    if (!c1cs) {
        // 0x804A3E30: nop
    
            goto L_804A3E3C;
    }
    // 0x804A3E30: nop

    // 0x804A3E34: b           L_804A3E3C
    // 0x804A3E38: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_804A3E3C;
    // 0x804A3E38: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_804A3E3C:
    // 0x804A3E3C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x804A3E40: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804A3E44: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804A3E48: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804A3E4C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804A3E50: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x804A3E54: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x804A3E58: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x804A3E5C: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x804A3E60: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x804A3E64: jr          $ra
    // 0x804A3E68: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x804A3E68: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8076CD88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076CD88: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8076CD8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076CD90: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8076CD94: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8076CD98: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x8076CD9C: lw          $v0, 0x1F4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1F4);
    // 0x8076CDA0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8076CDA4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8076CDA8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8076CDAC: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8076CDB0: lwc1        $f14, 0x6C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8076CDB4: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8076CDB8: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    // 0x8076CDBC: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    // 0x8076CDC0: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x8076CDC4: jal         0x80066DE4
    // 0x8076CDC8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8076CDC8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8076CDCC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8076CDD0: jal         0x80066E88
    // 0x8076CDD4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8076CDD4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8076CDD8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8076CDDC: lui         $t0, 0x8077
    ctx->r8 = S32(RELOC_HI16(766, 0X1E48) << 16);
    // 0x8076CDE0: addiu       $t0, $t0, -0x19C8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(766, 0X1E48));
    // 0x8076CDE4: lw          $t8, 0x10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10);
    // 0x8076CDE8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8076CDEC: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8076CDF0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8076CDF4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8076CDF8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8076CDFC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8076CE00: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8076CE04: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x8076CE08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8076CE0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8076CE10:
    // 0x8076CE10: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8076CE14: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x8076CE18: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8076CE1C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8076CE20: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8076CE24: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8076CE28: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8076CE2C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8076CE30: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8076CE34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8076CE38: mul.s       $f2, $f10, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8076CE3C: nop

    // 0x8076CE40: mul.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8076CE44: nop

    // 0x8076CE48: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8076CE4C: nop

    // 0x8076CE50: mul.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8076CE54: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8076CE58: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8076CE5C: nop

    // 0x8076CE60: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8076CE64: swc1        $f4, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f4.u32l;
    // 0x8076CE68: lw          $t4, -0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X4);
    // 0x8076CE6C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8076CE70: swc1        $f10, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f10.u32l;
    // 0x8076CE74: lwc1        $f4, -0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X10);
    // 0x8076CE78: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x8076CE7C: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8076CE80: swc1        $f6, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f6.u32l;
    // 0x8076CE84: lwc1        $f8, -0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8076CE88: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x8076CE8C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8076CE90: swc1        $f10, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f10.u32l;
    // 0x8076CE94: lwc1        $f4, -0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X8);
    // 0x8076CE98: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x8076CE9C: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8076CEA0: swc1        $f6, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f6.u32l;
    // 0x8076CEA4: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x8076CEA8: lw          $t8, -0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X4);
    // 0x8076CEAC: bne         $a0, $a1, L_8076CE10
    if (ctx->r4 != ctx->r5) {
        // 0x8076CEB0: sw          $t8, 0x138($t9)
        MEM_W(0X138, ctx->r25) = ctx->r24;
            goto L_8076CE10;
    }
    // 0x8076CEB0: sw          $t8, 0x138($t9)
    MEM_W(0X138, ctx->r25) = ctx->r24;
    // 0x8076CEB4: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8076CEB8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8076CEBC: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8076CEC0: swc1        $f8, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f8.u32l;
    // 0x8076CEC4: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8076CEC8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8076CECC: swc1        $f10, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f10.u32l;
    // 0x8076CED0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8076CED4: swc1        $f14, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f14.u32l;
    // 0x8076CED8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8076CEDC: swc1        $f16, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f16.u32l;
    // 0x8076CEE0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8076CEE4: swc1        $f20, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f20.u32l;
    // 0x8076CEE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8076CEEC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8076CEF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8076CEF4: jr          $ra
    // 0x8076CEF8: nop

    return;
    // 0x8076CEF8: nop

;}
RECOMP_FUNC void func_80039DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039DF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039DF8: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80039DFC: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80039E00: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80039E04: sltiu       $at, $t7, 0x2
    ctx->r1 = ctx->r15 < 0X2 ? 1 : 0;
    // 0x80039E08: bne         $at, $zero, L_80039E5C
    if (ctx->r1 != 0) {
        // 0x80039E0C: sw          $t7, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r15;
            goto L_80039E5C;
    }
    // 0x80039E0C: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80039E10: lbu         $v1, 0x158($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X158);
    // 0x80039E14: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80039E18: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x80039E1C: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x80039E20: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x80039E24: lw          $t9, -0x13D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X13D0);
    // 0x80039E28: xori        $t0, $v1, 0x1
    ctx->r8 = ctx->r3 ^ 0X1;
    // 0x80039E2C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80039E30: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80039E34: beq         $at, $zero, L_80039E44
    if (ctx->r1 == 0) {
        // 0x80039E38: nop
    
            goto L_80039E44;
    }
    // 0x80039E38: nop

    // 0x80039E3C: bgtzl       $v0, L_80039E58
    if (SIGNED(ctx->r2) > 0) {
        // 0x80039E40: sw          $zero, 0x154($a0)
        MEM_W(0X154, ctx->r4) = 0;
            goto L_80039E58;
    }
    goto skip_0;
    // 0x80039E40: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    skip_0:
L_80039E44:
    // 0x80039E44: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80039E48: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80039E4C: lw          $v0, -0x13C8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X13C8);
    // 0x80039E50: sb          $t0, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r8;
    // 0x80039E54: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
L_80039E58:
    // 0x80039E58: sw          $v0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r2;
L_80039E5C:
    // 0x80039E5C: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x80039E60: addiu       $t3, $t3, -0x13F8
    ctx->r11 = ADD32(ctx->r11, -0X13F8);
    // 0x80039E64: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80039E68: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80039E6C: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80039E70: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80039E74: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x80039E78: lw          $t4, 0x174($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X174);
    // 0x80039E7C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80039E80: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x80039E84: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80039E88: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80039E8C: beq         $t4, $zero, L_80039E9C
    if (ctx->r12 == 0) {
        // 0x80039E90: swc1        $f18, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
            goto L_80039E9C;
    }
    // 0x80039E90: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
    // 0x80039E94: jal         0x800498D4
    // 0x80039E98: nop

    func_800498D4(rdram, ctx);
        goto after_0;
    // 0x80039E98: nop

    after_0:
L_80039E9C:
    // 0x80039E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039EA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039EA4: jr          $ra
    // 0x80039EA8: nop

    return;
    // 0x80039EA8: nop

;}
RECOMP_FUNC void func_804753F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804753F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804753F4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804753F8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804753FC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475400: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475404: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475408: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047540C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475410: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475414: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475418: jr          $ra
    // 0x8047541C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047541C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8045BB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045BB48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045BB4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045BB50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8045BB54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045BB58: jal         0x80051194
    // 0x8045BB5C: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x8045BB5C: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x8045BB60: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x8045BB64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BB68: jal         0x8045BBF4
    // 0x8045BB6C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_8045BBF4(rdram, ctx);
        goto after_1;
    // 0x8045BB6C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_1:
    // 0x8045BB70: beq         $v0, $zero, L_8045BB9C
    if (ctx->r2 == 0) {
        // 0x8045BB74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8045BB9C;
    }
    // 0x8045BB74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BB78: jal         0x8045BED4
    // 0x8045BB7C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_8045BED4(rdram, ctx);
        goto after_2;
    // 0x8045BB7C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_2:
    // 0x8045BB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BB84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045BB88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8045BB8C: jal         0x8045D680
    // 0x8045BB90: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8045D680(rdram, ctx);
        goto after_3;
    // 0x8045BB90: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x8045BB94: b           L_8045BBA8
    // 0x8045BB98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8045BBA8;
    // 0x8045BB98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045BB9C:
    // 0x8045BB9C: jal         0x800445A4
    // 0x8045BBA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8045BBA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8045BBA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045BBA8:
    // 0x8045BBA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045BBAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045BBB0: jr          $ra
    // 0x8045BBB4: nop

    return;
    // 0x8045BBB4: nop

;}
RECOMP_FUNC void func_8003EBD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EBD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003EBD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003EBDC: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8003EBE0: addiu       $at, $zero, 0x4004
    ctx->r1 = ADD32(0, 0X4004);
    // 0x8003EBE4: beq         $v0, $at, L_8003EC08
    if (ctx->r2 == ctx->r1) {
        // 0x8003EBE8: addiu       $at, $zero, 0x406C
        ctx->r1 = ADD32(0, 0X406C);
            goto L_8003EC08;
    }
    // 0x8003EBE8: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8003EBEC: beq         $v0, $at, L_8003EC10
    if (ctx->r2 == ctx->r1) {
        // 0x8003EBF0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8003EC10;
    }
    // 0x8003EBF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003EBF4: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x8003EBF8: beq         $v0, $at, L_8003EC18
    if (ctx->r2 == ctx->r1) {
        // 0x8003EBFC: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_8003EC18;
    }
    // 0x8003EBFC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003EC00: b           L_8003EC20
    // 0x8003EC04: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
        goto L_8003EC20;
    // 0x8003EC04: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_8003EC08:
    // 0x8003EC08: b           L_8003EC1C
    // 0x8003EC0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
        goto L_8003EC1C;
    // 0x8003EC0C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8003EC10:
    // 0x8003EC10: b           L_8003EC1C
    // 0x8003EC14: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_8003EC1C;
    // 0x8003EC14: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_8003EC18:
    // 0x8003EC18: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8003EC1C:
    // 0x8003EC1C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_8003EC20:
    // 0x8003EC20: sltu        $t0, $zero, $a0
    ctx->r8 = 0 < ctx->r4 ? 1 : 0;
    // 0x8003EC24: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8003EC28: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8003EC2C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8003EC30: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8003EC34: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8003EC38: lw          $t9, -0x1098($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1098);
    // 0x8003EC3C: jalr        $t9
    // 0x8003EC40: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8003EC40: nop

    after_0:
    // 0x8003EC44: beq         $v0, $zero, L_8003EC70
    if (ctx->r2 == 0) {
        // 0x8003EC48: lui         $at, 0xC080
        ctx->r1 = S32(0XC080 << 16);
            goto L_8003EC70;
    }
    // 0x8003EC48: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8003EC4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003EC50: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8003EC54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003EC58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003EC5C: swc1        $f6, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f6.u32l;
    // 0x8003EC60: swc1        $f4, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f4.u32l;
    // 0x8003EC64: swc1        $f8, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->f8.u32l;
    // 0x8003EC68: b           L_8003EC74
    // 0x8003EC6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003EC74;
    // 0x8003EC6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003EC70:
    // 0x8003EC70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003EC74:
    // 0x8003EC74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003EC78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003EC7C: jr          $ra
    // 0x8003EC80: nop

    return;
    // 0x8003EC80: nop

;}
RECOMP_FUNC void func_80069C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80069C14: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80069C18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80069C1C: addiu       $t7, $t7, 0xEC4
    ctx->r15 = ADD32(ctx->r15, 0XEC4);
    // 0x80069C20: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80069C24: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80069C28: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80069C2C: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x80069C30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80069C34: addiu       $a2, $a2, -0x5D08
    ctx->r6 = ADD32(ctx->r6, -0X5D08);
    // 0x80069C38: addiu       $a1, $a1, -0x6008
    ctx->r5 = ADD32(ctx->r5, -0X6008);
    // 0x80069C3C: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    // 0x80069C40: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80069C44: jal         0x80081910
    // 0x80069C48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_0;
    // 0x80069C48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80069C4C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80069C50: addiu       $t0, $t0, -0x5D08
    ctx->r8 = ADD32(ctx->r8, -0X5D08);
    // 0x80069C54: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80069C58: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80069C5C: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x80069C60: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80069C64: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80069C68: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80069C6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80069C70: addiu       $a3, $a3, -0x5D08
    ctx->r7 = ADD32(ctx->r7, -0X5D08);
    // 0x80069C74: addiu       $a1, $a1, -0x20C0
    ctx->r5 = ADD32(ctx->r5, -0X20C0);
    // 0x80069C78: addiu       $a0, $a0, -0x6A30
    ctx->r4 = ADD32(ctx->r4, -0X6A30);
    // 0x80069C7C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80069C80: jal         0x8007D488
    // 0x80069C84: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    eepmgr_Create(rdram, ctx);
        goto after_1;
    // 0x80069C84: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80069C88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80069C8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80069C90: jr          $ra
    // 0x80069C94: nop

    return;
    // 0x80069C94: nop

;}
RECOMP_FUNC void func_80698F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80698F2C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80698F30: lui         $t1, 0x806A
    ctx->r9 = S32(RELOC_HI16(556, 0X580) << 16);
    // 0x80698F34: beq         $v0, $zero, L_80698F48
    if (ctx->r2 == 0) {
        // 0x80698F38: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80698F48;
    }
    // 0x80698F38: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80698F3C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80698F40: b           L_80698F6C
    // 0x80698F44: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
        goto L_80698F6C;
    // 0x80698F44: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
L_80698F48:
    // 0x80698F48: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80698F4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80698F50: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80698F54: addiu       $v1, $t8, 0x1
    ctx->r3 = ADD32(ctx->r24, 0X1);
    // 0x80698F58: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80698F5C: bne         $at, $zero, L_80698F6C
    if (ctx->r1 != 0) {
        // 0x80698F60: sw          $v1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r3;
            goto L_80698F6C;
    }
    // 0x80698F60: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80698F64: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80698F68: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80698F6C:
    // 0x80698F6C: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x80698F70: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80698F74: lh          $t1, -0x6D60($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(556, 0X580));
    // 0x80698F78: jr          $ra
    // 0x80698F7C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    return;
    // 0x80698F7C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8001CF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF94: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8001CF98: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8001CF9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001CFA0: lw          $t6, 0xF10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XF10);
    // 0x8001CFA4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001CFA8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001CFAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001CFB0: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8001CFB4: lw          $t9, 0xF14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XF14);
    // 0x8001CFB8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001CFBC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001CFC0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001CFC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001CFC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001CFCC: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001CFD0: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8001CFD4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001CFD8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8001CFDC: lw          $t1, -0x6948($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6948);
    // 0x8001CFE0: lw          $v0, 0x20($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X20);
    // 0x8001CFE4: subu        $s2, $v0, $t1
    ctx->r18 = SUB32(ctx->r2, ctx->r9);
    // 0x8001CFE8: bgez        $s2, L_8001D000
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8001CFEC: nop
    
            goto L_8001D000;
    }
    // 0x8001CFEC: nop

    // 0x8001CFF0: jal         0x8001CC20
    // 0x8001CFF4: nop

    func_8001CC20(rdram, ctx);
        goto after_0;
    // 0x8001CFF4: nop

    after_0:
    // 0x8001CFF8: b           L_8001D074
    // 0x8001CFFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8001D074;
    // 0x8001CFFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001D000:
    // 0x8001D000: blez        $s2, L_8001D070
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8001D004: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_8001D070;
    }
    // 0x8001D004: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8001D008: beq         $s2, $zero, L_8001D064
    if (ctx->r18 == 0) {
        // 0x8001D00C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001D064;
    }
    // 0x8001D00C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001D010: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8001D014: addu        $s1, $s4, $t2
    ctx->r17 = ADD32(ctx->r20, ctx->r10);
    // 0x8001D018: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_8001D01C:
    // 0x8001D01C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001D020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001D024: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8001D028: sb          $s5, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r21;
    // 0x8001D02C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D030: jalr        $t9
    // 0x8001D034: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8001D034: nop

    after_1:
    // 0x8001D038: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x8001D03C: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x8001D040: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8001D044: sw          $s3, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r19;
    // 0x8001D048: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8001D04C: lw          $t4, 0x20($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X20);
    // 0x8001D050: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x8001D054: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8001D058: bne         $s2, $zero, L_8001D01C
    if (ctx->r18 != 0) {
        // 0x8001D05C: sw          $t5, 0x20($s4)
        MEM_W(0X20, ctx->r20) = ctx->r13;
            goto L_8001D01C;
    }
    // 0x8001D05C: sw          $t5, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->r13;
    // 0x8001D060: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8001D064:
    // 0x8001D064: bnel        $v0, $zero, L_8001D074
    if (ctx->r2 != 0) {
        // 0x8001D068: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001D074;
    }
    goto skip_0;
    // 0x8001D068: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8001D06C: sw          $s3, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->r19;
L_8001D070:
    // 0x8001D070: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001D074:
    // 0x8001D074: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001D078: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001D07C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D080: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001D084: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001D088: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001D08C: jr          $ra
    // 0x8001D090: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001D090: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80430EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430EA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80430EA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80430EA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80430EAC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430EB0: jal         0x80430BE8
    // 0x80430EB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80430BE8(rdram, ctx);
        goto after_0;
    // 0x80430EB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80430EB8: jal         0x80430C44
    // 0x80430EBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80430C44(rdram, ctx);
        goto after_1;
    // 0x80430EBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80430EC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80430EC4: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80430EC8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80430ECC: nop

    // 0x80430ED0: bc1f        L_80430F20
    if (!c1cs) {
        // 0x80430ED4: nop
    
            goto L_80430F20;
    }
    // 0x80430ED4: nop

    // 0x80430ED8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80430EDC: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80430EE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80430EE4: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80430EE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80430EEC: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80430EF0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80430EF4: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80430EF8: nop

    // 0x80430EFC: bc1f        L_80430F20
    if (!c1cs) {
        // 0x80430F00: nop
    
            goto L_80430F20;
    }
    // 0x80430F00: nop

    // 0x80430F04: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80430F08: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80430F0C: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80430F10: sh          $t6, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r14;
    // 0x80430F14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80430F18: jal         0x804311BC
    // 0x80430F1C: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    func_804311BC(rdram, ctx);
        goto after_2;
    // 0x80430F1C: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    after_2:
L_80430F20:
    // 0x80430F20: jal         0x80430CC0
    // 0x80430F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80430CC0(rdram, ctx);
        goto after_3;
    // 0x80430F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80430F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80430F2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80430F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80430F34: jr          $ra
    // 0x80430F38: nop

    return;
    // 0x80430F38: nop

;}
RECOMP_FUNC void func_8005AF18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AF18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005AF1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005AF20: lw          $a1, 0x10($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X10);
    // 0x8005AF24: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8005AF28: beq         $a1, $zero, L_8005AF78
    if (ctx->r5 == 0) {
        // 0x8005AF2C: sll         $t6, $a1, 4
        ctx->r14 = S32(ctx->r5 << 4);
            goto L_8005AF78;
    }
    // 0x8005AF2C: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8005AF30: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8005AF34: beq         $t7, $zero, L_8005AF4C
    if (ctx->r15 == 0) {
        // 0x8005AF38: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8005AF4C;
    }
    // 0x8005AF38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8005AF3C: jal         0x80050970
    // 0x8005AF40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80050970(rdram, ctx);
        goto after_0;
    // 0x8005AF40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8005AF44: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8005AF48: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
L_8005AF4C:
    // 0x8005AF4C: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    // 0x8005AF50: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x8005AF54: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x8005AF58: beql        $t9, $zero, L_8005AF7C
    if (ctx->r25 == 0) {
        // 0x8005AF5C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005AF7C;
    }
    goto skip_0;
    // 0x8005AF5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8005AF60: jal         0x8005AE40
    // 0x8005AF64: nop

    func_8005AE40(rdram, ctx);
        goto after_1;
    // 0x8005AF64: nop

    after_1:
    // 0x8005AF68: bnel        $v0, $zero, L_8005AF7C
    if (ctx->r2 != 0) {
        // 0x8005AF6C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005AF7C;
    }
    goto skip_1;
    // 0x8005AF6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8005AF70: b           L_8005AF7C
    // 0x8005AF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005AF7C;
    // 0x8005AF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005AF78:
    // 0x8005AF78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005AF7C:
    // 0x8005AF7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005AF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005AF84: jr          $ra
    // 0x8005AF88: nop

    return;
    // 0x8005AF88: nop

;}
RECOMP_FUNC void func_80051C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051C80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051C84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051C88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80051C8C: jal         0x80050AFC
    // 0x80051C90: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_80050AFC(rdram, ctx);
        goto after_0;
    // 0x80051C90: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_0:
    // 0x80051C94: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80051C98: jal         0x8005BA40
    // 0x80051C9C: lhu         $a0, 0x18($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X18);
    func_8005BA40(rdram, ctx);
        goto after_1;
    // 0x80051C9C: lhu         $a0, 0x18($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X18);
    after_1:
    // 0x80051CA0: jal         0x80064E84
    // 0x80051CA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x80051CA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80051CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051CB0: jr          $ra
    // 0x80051CB4: nop

    return;
    // 0x80051CB4: nop

;}
RECOMP_FUNC void func_8059FAEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059FAEC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8059FAF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8059FAF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8059FAF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8059FAFC: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8059FB00: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8059FB04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8059FB08: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x8059FB0C: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059FB10: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8059FB14: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8059FB18: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8059FB1C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x8059FB20: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059FB24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8059FB28: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x8059FB2C: lhu         $v0, 0x8($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X8);
    // 0x8059FB30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8059FB34: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x8059FB38: beq         $t0, $zero, L_8059FBE4
    if (ctx->r8 == 0) {
        // 0x8059FB3C: andi        $t2, $v0, 0x4
        ctx->r10 = ctx->r2 & 0X4;
            goto L_8059FBE4;
    }
    // 0x8059FB3C: andi        $t2, $v0, 0x4
    ctx->r10 = ctx->r2 & 0X4;
    // 0x8059FB40: beq         $t2, $zero, L_8059FB50
    if (ctx->r10 == 0) {
        // 0x8059FB44: addiu       $a0, $a0, 0xC4
        ctx->r4 = ADD32(ctx->r4, 0XC4);
            goto L_8059FB50;
    }
    // 0x8059FB44: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8059FB48: jal         0x80048F84
    // 0x8059FB4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8059FB4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_8059FB50:
    // 0x8059FB50: jal         0x8059F608
    // 0x8059FB54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8059F608(rdram, ctx);
        goto after_1;
    // 0x8059FB54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8059FB58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8059FB5C: beq         $v0, $at, L_8059FB74
    if (ctx->r2 == ctx->r1) {
        // 0x8059FB60: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8059FB74;
    }
    // 0x8059FB60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8059FB64: beq         $v0, $at, L_8059FBC8
    if (ctx->r2 == ctx->r1) {
        // 0x8059FB68: nop
    
            goto L_8059FBC8;
    }
    // 0x8059FB68: nop

    // 0x8059FB6C: b           L_8059FDB0
    // 0x8059FB70: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
        goto L_8059FDB0;
    // 0x8059FB70: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
L_8059FB74:
    // 0x8059FB74: jal         0x8059F3CC
    // 0x8059FB78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8059F3CC(rdram, ctx);
        goto after_2;
    // 0x8059FB78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8059FB7C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8059FB80: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8059FB84: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x8059FB88: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8059FB8C: bnel        $t4, $at, L_8059FDB0
    if (ctx->r12 != ctx->r1) {
        // 0x8059FB90: lw          $v0, 0x1F4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X1F4);
            goto L_8059FDB0;
    }
    goto skip_0;
    // 0x8059FB90: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
    skip_0:
    // 0x8059FB94: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8059FB98: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(408, 0X1E00) << 16);
    // 0x8059FB9C: lwc1        $f10, 0x1160($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(408, 0X1E00));
    // 0x8059FBA0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8059FBA4: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8059FBA8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8059FBAC: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8059FBB0: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8059FBB4: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
    // 0x8059FBB8: lhu         $t5, 0x8($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FBBC: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x8059FBC0: b           L_8059FDAC
    // 0x8059FBC4: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
        goto L_8059FDAC;
    // 0x8059FBC4: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
L_8059FBC8:
    // 0x8059FBC8: jal         0x8059F3CC
    // 0x8059FBCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8059F3CC(rdram, ctx);
        goto after_3;
    // 0x8059FBCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8059FBD0: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
    // 0x8059FBD4: lhu         $t7, 0x8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FBD8: andi        $t8, $t7, 0xFFFD
    ctx->r24 = ctx->r15 & 0XFFFD;
    // 0x8059FBDC: b           L_8059FDAC
    // 0x8059FBE0: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
        goto L_8059FDAC;
    // 0x8059FBE0: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
L_8059FBE4:
    // 0x8059FBE4: jal         0x80048F84
    // 0x8059FBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x8059FBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8059FBEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8059FBF0: jal         0x80049D74
    // 0x8059FBF4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80049D74(rdram, ctx);
        goto after_5;
    // 0x8059FBF4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_5:
    // 0x8059FBF8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8059FBFC: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x8059FC00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8059FC04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8059FC08: jal         0x8004D150
    // 0x8059FC0C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D150(rdram, ctx);
        goto after_6;
    // 0x8059FC0C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_6:
    // 0x8059FC10: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8059FC14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8059FC18: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8059FC1C: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x8059FC20: lbu         $t2, 0x14($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X14);
    // 0x8059FC24: beq         $t2, $zero, L_8059FCF4
    if (ctx->r10 == 0) {
        // 0x8059FC28: nop
    
            goto L_8059FCF4;
    }
    // 0x8059FC28: nop

    // 0x8059FC2C: jal         0x8059FAA0
    // 0x8059FC30: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    func_8059FAA0(rdram, ctx);
        goto after_7;
    // 0x8059FC30: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    after_7:
    // 0x8059FC34: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8059FC38: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x8059FC3C: addiu       $a0, $s1, 0x84
    ctx->r4 = ADD32(ctx->r17, 0X84);
    // 0x8059FC40: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8059FC44: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8059FC48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8059FC4C: lw          $t9, 0x4C($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4C);
    // 0x8059FC50: jalr        $t9
    // 0x8059FC54: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8059FC54: nop

    after_8:
    // 0x8059FC58: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8059FC5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8059FC60: lhu         $t5, 0xA($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XA);
    // 0x8059FC64: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8059FC68: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8059FC6C: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8059FC70: bne         $at, $zero, L_8059FC90
    if (ctx->r1 != 0) {
        // 0x8059FC74: sh          $t6, 0xA($v1)
        MEM_H(0XA, ctx->r3) = ctx->r14;
            goto L_8059FC90;
    }
    // 0x8059FC74: sh          $t6, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r14;
    // 0x8059FC78: jal         0x8059FAA0
    // 0x8059FC7C: addiu       $a1, $zero, 0xB1
    ctx->r5 = ADD32(0, 0XB1);
    func_8059FAA0(rdram, ctx);
        goto after_9;
    // 0x8059FC7C: addiu       $a1, $zero, 0xB1
    ctx->r5 = ADD32(0, 0XB1);
    after_9:
    // 0x8059FC80: jal         0x800447C8
    // 0x8059FC84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800447C8(rdram, ctx);
        goto after_10;
    // 0x8059FC84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8059FC88: b           L_8059FDC0
    // 0x8059FC8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8059FDC0;
    // 0x8059FC8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8059FC90:
    // 0x8059FC90: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
    // 0x8059FC94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8059FC98: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8059FC9C: lhu         $t8, 0x8($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FCA0: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x8059FCA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8059FCA8: ori         $t0, $t8, 0x2
    ctx->r8 = ctx->r24 | 0X2;
    // 0x8059FCAC: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    // 0x8059FCB0: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
    // 0x8059FCB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8059FCB8: lhu         $t1, 0x8($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FCBC: andi        $t2, $t1, 0xFFFB
    ctx->r10 = ctx->r9 & 0XFFFB;
    // 0x8059FCC0: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x8059FCC4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8059FCC8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8059FCCC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8059FCD0: jal         0x8004D618
    // 0x8059FCD4: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    func_8004D618(rdram, ctx);
        goto after_11;
    // 0x8059FCD4: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    after_11:
    // 0x8059FCD8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8059FCDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8059FCE0: lhu         $t4, 0xA($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XA);
    // 0x8059FCE4: bne         $t4, $at, L_8059FCF4
    if (ctx->r12 != ctx->r1) {
        // 0x8059FCE8: nop
    
            goto L_8059FCF4;
    }
    // 0x8059FCE8: nop

    // 0x8059FCEC: jal         0x8059F750
    // 0x8059FCF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8059F750(rdram, ctx);
        goto after_12;
    // 0x8059FCF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
L_8059FCF4:
    // 0x8059FCF4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8059FCF8: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x8059FCFC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8059FD00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8059FD04: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8059FD08: jal         0x8004D150
    // 0x8059FD0C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D150(rdram, ctx);
        goto after_13;
    // 0x8059FD0C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_13:
    // 0x8059FD10: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8059FD14: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8059FD18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8059FD1C: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8059FD20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8059FD24: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x8059FD28: lbu         $t7, 0x5C($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5C);
    // 0x8059FD2C: beq         $t7, $zero, L_8059FD60
    if (ctx->r15 == 0) {
        // 0x8059FD30: nop
    
            goto L_8059FD60;
    }
    // 0x8059FD30: nop

    // 0x8059FD34: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8059FD38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8059FD3C: nop

    // 0x8059FD40: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8059FD44: nop

    // 0x8059FD48: bc1f        L_8059FD60
    if (!c1cs) {
        // 0x8059FD4C: nop
    
            goto L_8059FD60;
    }
    // 0x8059FD4C: nop

    // 0x8059FD50: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8059FD54: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x8059FD58: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8059FD5C: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
L_8059FD60:
    // 0x8059FD60: jal         0x8004D150
    // 0x8059FD64: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D150(rdram, ctx);
        goto after_14;
    // 0x8059FD64: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_14:
    // 0x8059FD68: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8059FD6C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8059FD70: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x8059FD74: lbu         $t2, 0x74($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X74);
    // 0x8059FD78: beql        $t2, $zero, L_8059FDB0
    if (ctx->r10 == 0) {
        // 0x8059FD7C: lw          $v0, 0x1F4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X1F4);
            goto L_8059FDB0;
    }
    goto skip_1;
    // 0x8059FD7C: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
    skip_1:
    // 0x8059FD80: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8059FD84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8059FD88: nop

    // 0x8059FD8C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8059FD90: nop

    // 0x8059FD94: bc1fl       L_8059FDB0
    if (!c1cs) {
        // 0x8059FD98: lw          $v0, 0x1F4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X1F4);
            goto L_8059FDB0;
    }
    goto skip_2;
    // 0x8059FD98: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
    skip_2:
    // 0x8059FD9C: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x8059FDA0: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8059FDA4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8059FDA8: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
L_8059FDAC:
    // 0x8059FDAC: lw          $v0, 0x1F4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1F4);
L_8059FDB0:
    // 0x8059FDB0: lhu         $t3, 0x8($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FDB4: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x8059FDB8: sh          $t4, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r12;
    // 0x8059FDBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8059FDC0:
    // 0x8059FDC0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8059FDC4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8059FDC8: jr          $ra
    // 0x8059FDCC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8059FDCC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80433974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80433978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043397C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80433980: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80433984: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(68, 0X218) << 16);
    // 0x80433988: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043398C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80433990: lw          $t8, 0x3A48($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(68, 0X218));
    // 0x80433994: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80433998: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8043399C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804339A0: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804339A4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804339A8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804339AC: beql        $v1, $zero, L_804339E0
    if (ctx->r3 == 0) {
        // 0x804339B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804339E0;
    }
    goto skip_0;
    // 0x804339B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804339B4: jalr        $v1
    // 0x804339B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804339B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804339BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804339C0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804339C4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804339C8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804339CC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804339D0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804339D4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804339D8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804339DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804339E0:
    // 0x804339E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804339E4: jr          $ra
    // 0x804339E8: nop

    return;
    // 0x804339E8: nop

    // 0x804339EC: nop

;}
RECOMP_FUNC void func_80581504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8058150C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80581510: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80581514: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(399, 0X4658) << 16);
    // 0x80581518: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8058151C: addiu       $t7, $t7, 0x3468
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(399, 0X4658));
    // 0x80581520: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80581524: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80581528: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8058152C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80581530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80581534: jal         0x805814C4
    // 0x80581538: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805814C4(rdram, ctx);
        goto after_0;
    // 0x80581538: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8058153C: jal         0x80581488
    // 0x80581540: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80581488(rdram, ctx);
        goto after_1;
    // 0x80581540: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80581544: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80581548: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8058154C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80581550: lui         $at, 0xC2F2
    ctx->r1 = S32(0XC2F2 << 16);
    // 0x80581554: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80581558: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8058155C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80581560: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80581564: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80581568: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x8058156C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80581570: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80581574: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80581578: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x8058157C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80581580: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80581584: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80581588: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x8058158C: sb          $t9, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r25;
    // 0x80581590: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x80581594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8058159C: jr          $ra
    // 0x805815A0: nop

    return;
    // 0x805815A0: nop

;}
RECOMP_FUNC void func_80425680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80425680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80425684: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80425688: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8042568C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80425690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80425694: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80425698: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8042569C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804256A0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804256A4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804256A8: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(35, 0X3694) << 16);
    // 0x804256AC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804256B0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804256B4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804256B8: lw          $t2, 0x6094($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(35, 0X3694));
    // 0x804256BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804256C0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804256C4: jal         0x80425474
    // 0x804256C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80425474(rdram, ctx);
        goto after_0;
    // 0x804256C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804256CC: jal         0x804254D0
    // 0x804256D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804254D0(rdram, ctx);
        goto after_1;
    // 0x804256D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804256D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804256D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804256DC: jr          $ra
    // 0x804256E0: nop

    return;
    // 0x804256E0: nop

    // 0x804256E4: nop

    // 0x804256E8: nop

    // 0x804256EC: nop

;}
RECOMP_FUNC void func_804628D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804628D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804628D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804628DC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804628E0: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804628E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804628E8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804628EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804628F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804628F4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804628F8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804628FC: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(122, 0X3894) << 16);
    // 0x80462900: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80462904: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80462908: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8046290C: lw          $t2, 0x3E24($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(122, 0X3894));
    // 0x80462910: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80462914: jal         0x804626D8
    // 0x80462918: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804626D8(rdram, ctx);
        goto after_0;
    // 0x80462918: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8046291C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80462920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80462924: jr          $ra
    // 0x80462928: nop

    return;
    // 0x80462928: nop

;}
RECOMP_FUNC void func_8003A6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A6F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003A6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A6F8: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8003A6FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003A700: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8003A704: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8003A708: bne         $at, $zero, L_8003A7A0
    if (ctx->r1 != 0) {
        // 0x8003A70C: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8003A7A0;
    }
    // 0x8003A70C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8003A710: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003A714: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8003A718: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x8003A71C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8003A720: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A724: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003A728: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003A72C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8003A730: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x8003A734: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8003A738: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8003A73C: lwc1        $f10, 0x58($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8003A740: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003A744: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8003A748: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8003A74C: lwc1        $f4, 0x5C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x8003A750: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003A754: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8003A758: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8003A75C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8003A760: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8003A764: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8003A768: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x8003A76C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8003A770: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8003A774: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8003A778: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8003A77C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8003A780: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8003A784: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8003A788: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8003A78C: lw          $t9, 0x10($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X10);
    // 0x8003A790: jalr        $t9
    // 0x8003A794: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8003A794: nop

    after_0:
    // 0x8003A798: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8003A79C: sw          $zero, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = 0;
L_8003A7A0:
    // 0x8003A7A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A7A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8003A7A8: jr          $ra
    // 0x8003A7AC: nop

    return;
    // 0x8003A7AC: nop

;}
RECOMP_FUNC void func_807AEA6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AEA6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AEA70: jr          $ra
    // 0x807AEA74: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    return;
    // 0x807AEA74: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_8066A790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A794: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8066A798: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8066A79C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8066A7A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A7A4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8066A7A8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8066A7AC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8066A7B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8066A7B4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8066A7B8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8066A7BC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8066A7C0: lui         $t2, 0x8067
    ctx->r10 = S32(RELOC_HI16(511, 0XD04) << 16);
    // 0x8066A7C4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8066A7C8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8066A7CC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8066A7D0: lw          $t2, -0x557C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(511, 0XD04));
    // 0x8066A7D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8066A7D8: jal         0x8066A50C
    // 0x8066A7DC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8066A50C(rdram, ctx);
        goto after_0;
    // 0x8066A7DC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8066A7E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066A7E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A7E8: jr          $ra
    // 0x8066A7EC: nop

    return;
    // 0x8066A7EC: nop

;}
RECOMP_FUNC void func_80792FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80792FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80792FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80792FC0: jal         0x80790CB4
    // 0x80792FC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80790CB4(rdram, ctx);
        goto after_0;
    // 0x80792FC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80792FC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80792FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792FD0: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x80792FD4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80792FD8: blez        $v0, L_80792FE8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80792FDC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80792FE8;
    }
    // 0x80792FDC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80792FE0: b           L_80793000
    // 0x80792FE4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_80793000;
    // 0x80792FE4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_80792FE8:
    // 0x80792FE8: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x80792FEC: jal         0x8079393C
    // 0x80792FF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8079393C(rdram, ctx);
        goto after_1;
    // 0x80792FF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80792FF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80792FF8: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x80792FFC: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
L_80793000:
    // 0x80793000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80793004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80793008: jr          $ra
    // 0x8079300C: nop

    return;
    // 0x8079300C: nop

;}
RECOMP_FUNC void func_805A65D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A65D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A65DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A65E0: jal         0x805A5440
    // 0x805A65E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A5440(rdram, ctx);
        goto after_0;
    // 0x805A65E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A65E8: jal         0x80045BD8
    // 0x805A65EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x805A65EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805A65F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A65F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A65F8: jr          $ra
    // 0x805A65FC: nop

    return;
    // 0x805A65FC: nop

;}
RECOMP_FUNC void func_800655F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800655F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800655F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800655FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065600: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80065604: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80065608: jal         0x800654B4
    // 0x8006560C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800654B4(rdram, ctx);
        goto after_0;
    // 0x8006560C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80065610: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80065614: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80065618: bne         $v0, $zero, L_80065648
    if (ctx->r2 != 0) {
        // 0x8006561C: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80065648;
    }
    // 0x8006561C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80065620: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80065624: addiu       $a0, $a0, 0xDB8
    ctx->r4 = ADD32(ctx->r4, 0XDB8);
    // 0x80065628: addiu       $a1, $zero, 0x1E4
    ctx->r5 = ADD32(0, 0X1E4);
    // 0x8006562C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80065630: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80065634: jal         0x80071380
    // 0x80065638: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80065638: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x8006563C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80065640: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80065644: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_80065648:
    // 0x80065648: beq         $a2, $zero, L_800656AC
    if (ctx->r6 == 0) {
        // 0x8006564C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800656AC;
    }
    // 0x8006564C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80065650: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x80065654: beq         $a1, $zero, L_8006567C
    if (ctx->r5 == 0) {
        // 0x80065658: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8006567C;
    }
    // 0x80065658: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8006565C:
    // 0x8006565C: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x80065660: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80065664: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80065668: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8006566C: bne         $a0, $v0, L_8006565C
    if (ctx->r4 != ctx->r2) {
        // 0x80065670: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_8006565C;
    }
    // 0x80065670: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x80065674: beql        $v0, $a2, L_800656B0
    if (ctx->r2 == ctx->r6) {
        // 0x80065678: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800656B0;
    }
    goto skip_0;
    // 0x80065678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8006567C:
    // 0x8006567C: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x80065680: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80065684: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80065688: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x8006568C: lbu         $t8, 0x1($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X1);
    // 0x80065690: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80065694: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x80065698: lbu         $t9, -0x2($t0)
    ctx->r25 = MEM_BU(ctx->r8, -0X2);
    // 0x8006569C: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x800656A0: lbu         $t1, -0x1($t0)
    ctx->r9 = MEM_BU(ctx->r8, -0X1);
    // 0x800656A4: bne         $v0, $a2, L_8006567C
    if (ctx->r2 != ctx->r6) {
        // 0x800656A8: sb          $t1, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r9;
            goto L_8006567C;
    }
    // 0x800656A8: sb          $t1, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r9;
L_800656AC:
    // 0x800656AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800656B0:
    // 0x800656B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800656B4: jr          $ra
    // 0x800656B8: nop

    return;
    // 0x800656B8: nop

;}
RECOMP_FUNC void func_80680F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680F38: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680F3C: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x80680F40: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80680F44: lui         $at, 0x4328
    ctx->r1 = S32(0X4328 << 16);
    // 0x80680F48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80680F4C: lwc1        $f4, 0x88($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80680F50: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80680F54: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80680F58: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80680F5C: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80680F60: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80680F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80680F68: sub.s       $f12, $f16, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x80680F6C: add.s       $f2, $f10, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80680F70: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80680F74: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80680F78: nop

    // 0x80680F7C: bc1f        L_80680F88
    if (!c1cs) {
        // 0x80680F80: nop
    
            goto L_80680F88;
    }
    // 0x80680F80: nop

    // 0x80680F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80680F88:
    // 0x80680F88: jr          $ra
    // 0x80680F8C: nop

    return;
    // 0x80680F8C: nop

;}
RECOMP_FUNC void func_804EEE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EEE08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EEE0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EEE10: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804EEE14: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804EEE18: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804EEE1C: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(267, 0X101C) << 16);
    // 0x804EEE20: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804EEE24: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804EEE28: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804EEE2C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804EEE30: lw          $t8, -0x254($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(267, 0X101C));
    // 0x804EEE34: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804EEE38: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804EEE3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804EEE40: jal         0x80048490
    // 0x804EEE44: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804EEE44: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804EEE48: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804EEE4C: jal         0x80048378
    // 0x804EEE50: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804EEE50: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804EEE54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EEE58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EEE5C: jr          $ra
    // 0x804EEE60: nop

    return;
    // 0x804EEE60: nop

;}
RECOMP_FUNC void func_80436234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80436238: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8043623C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80436240: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80436244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436248: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8043624C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80436250: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80436254: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80436258: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8043625C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80436260: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80436264: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(71, 0X2AA8) << 16);
    // 0x80436268: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8043626C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80436270: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80436274: lw          $t2, 0x6558($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(71, 0X2AA8));
    // 0x80436278: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8043627C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80436280: jal         0x804352CC
    // 0x80436284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804352CC(rdram, ctx);
        goto after_0;
    // 0x80436284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80436288: jal         0x80435254
    // 0x8043628C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80435254(rdram, ctx);
        goto after_1;
    // 0x8043628C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80436290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80436294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80436298: jr          $ra
    // 0x8043629C: nop

    return;
    // 0x8043629C: nop

;}
RECOMP_FUNC void func_8044AB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AB94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044AB98: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13494) << 16);
    // 0x8044AB9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044ABA0: addiu       $t6, $t6, 0x7874
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13494));
    // 0x8044ABA4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044ABA8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044ABAC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044ABB0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044ABB4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044ABB8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044ABBC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044ABC0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044ABC4: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044ABC8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044ABCC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044ABD0: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044ABD4: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044ABD8: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044ABDC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044ABE0: jal         0x80050A50
    // 0x8044ABE4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044ABE4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044ABE8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044ABEC: jalr        $v0
    // 0x8044ABF0: sw          $v0, 0x6A80($v1)
    MEM_W(0X6A80, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044ABF0: sw          $v0, 0x6A80($v1)
    MEM_W(0X6A80, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044ABF4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044ABF8: sw          $v0, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r2;
    // 0x8044ABFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044AC00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044AC04: jr          $ra
    // 0x8044AC08: nop

    return;
    // 0x8044AC08: nop

;}
RECOMP_FUNC void func_8067433C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067433C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80674340: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80674344: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80674348: jal         0x806741B8
    // 0x8067434C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806741B8(rdram, ctx);
        goto after_0;
    // 0x8067434C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80674350: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80674354: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80674358: jal         0x80065ABC
    // 0x8067435C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x8067435C: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_1:
    // 0x80674360: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80674364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80674368: jal         0x80049D74
    // 0x8067436C: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x8067436C: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_2:
    // 0x80674370: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80674374: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x80674378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067437C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80674380: jal         0x8004D150
    // 0x80674384: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x80674384: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80674388: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x8067438C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80674390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80674394: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80674398: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8067439C: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x806743A0: lbu         $t9, 0x2C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2C);
    // 0x806743A4: beql        $t9, $zero, L_80674438
    if (ctx->r25 == 0) {
        // 0x806743A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80674438;
    }
    goto skip_0;
    // 0x806743A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806743AC: jal         0x8004D618
    // 0x806743B0: addiu       $a2, $a2, -0x2BEC
    ctx->r6 = ADD32(ctx->r6, -0X2BEC);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x806743B0: addiu       $a2, $a2, -0x2BEC
    ctx->r6 = ADD32(ctx->r6, -0X2BEC);
    after_4:
    // 0x806743B4: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x806743B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806743BC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806743C0: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x806743C4: jal         0x8004A97C
    // 0x806743C8: lhu         $a0, 0x18($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X18);
    func_8004A97C(rdram, ctx);
        goto after_5;
    // 0x806743C8: lhu         $a0, 0x18($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X18);
    after_5:
    // 0x806743CC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C4C) << 16);
    // 0x806743D0: lwc1        $f4, 0x4C2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C4C));
    // 0x806743D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x806743D8: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C50) << 16);
    // 0x806743DC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806743E0: nop

    // 0x806743E4: bc1t        L_80674410
    if (c1cs) {
        // 0x806743E8: nop
    
            goto L_80674410;
    }
    // 0x806743E8: nop

    // 0x806743EC: lwc1        $f6, 0x4C30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C50));
    // 0x806743F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806743F4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806743F8: nop

    // 0x806743FC: bc1t        L_80674410
    if (c1cs) {
        // 0x80674400: nop
    
            goto L_80674410;
    }
    // 0x80674400: nop

    // 0x80674404: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80674408: b           L_80674420
    // 0x8067440C: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
        goto L_80674420;
    // 0x8067440C: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
L_80674410:
    // 0x80674410: jal         0x800659EC
    // 0x80674414: nop

    func_800659EC(rdram, ctx);
        goto after_6;
    // 0x80674414: nop

    after_6:
    // 0x80674418: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8067441C: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
L_80674420:
    // 0x80674420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80674424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80674428: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8067442C: jal         0x806748E4
    // 0x80674430: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806748E4(rdram, ctx);
        goto after_7;
    // 0x80674430: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x80674434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80674438:
    // 0x80674438: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067443C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80674440: jr          $ra
    // 0x80674444: nop

    return;
    // 0x80674444: nop

;}
RECOMP_FUNC void func_8046CCF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046CCF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046CCFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046CD00: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8046CD04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046CD08: jal         0x80048F84
    // 0x8046CD0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8046CD0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8046CD10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046CD14: jal         0x80048F84
    // 0x8046CD18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8046CD18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8046CD1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046CD20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046CD24: jr          $ra
    // 0x8046CD28: nop

    return;
    // 0x8046CD28: nop

;}
RECOMP_FUNC void func_804750C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804750C0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804750C4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804750C8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804750CC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804750D0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804750D4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804750D8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804750DC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804750E0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804750E4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804750E8: jr          $ra
    // 0x804750EC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804750EC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80432564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80432568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043256C: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    // 0x80432570: jal         0x804326C4
    // 0x80432574: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804326C4(rdram, ctx);
        goto after_0;
    // 0x80432574: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80432578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043257C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80432580: jr          $ra
    // 0x80432584: nop

    return;
    // 0x80432584: nop

;}
RECOMP_FUNC void func_8070C934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070C934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8070C938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070C93C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070C940: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8070C944: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8070C948: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8070C94C: jal         0x80066DE4
    // 0x8070C950: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8070C950: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x8070C954: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8070C958: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8070C95C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8070C960: jal         0x80066E88
    // 0x8070C964: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8070C964: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x8070C968: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8070C96C: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD44) << 16);
    // 0x8070C970: lwc1        $f2, -0x2C2C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD44));
    // 0x8070C974: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD48) << 16);
    // 0x8070C978: lwc1        $f6, -0x2C28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD48));
    // 0x8070C97C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8070C980: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8070C984: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8070C988: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8070C98C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8070C990: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8070C994: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8070C998: nop

    // 0x8070C99C: bc1fl       L_8070C9B0
    if (!c1cs) {
        // 0x8070C9A0: lwc1        $f10, 0x6C($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
            goto L_8070C9B0;
    }
    goto skip_0;
    // 0x8070C9A0: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    skip_0:
    // 0x8070C9A4: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x8070C9A8: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8070C9AC: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
L_8070C9B0:
    // 0x8070C9B0: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8070C9B4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8070C9B8: add.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8070C9BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8070C9C0: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x8070C9C4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8070C9C8: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8070C9CC: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8070C9D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8070C9D4: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8070C9D8: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8070C9DC: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8070C9E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8070C9E4: sub.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8070C9E8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8070C9EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8070C9F0: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8070C9F4: sub.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8070C9F8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8070C9FC: mul.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8070CA00: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8070CA04: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8070CA08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8070CA0C: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8070CA10: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8070CA14: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8070CA18: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8070CA1C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8070CA20: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x8070CA24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070CA28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8070CA2C: jr          $ra
    // 0x8070CA30: nop

    return;
    // 0x8070CA30: nop

;}
RECOMP_FUNC void func_806E4F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E4F18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806E4F1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806E4F20: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x806E4F24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806E4F28: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x806E4F2C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x806E4F30: jal         0x80045A34
    // 0x806E4F34: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806E4F34: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    after_0:
    // 0x806E4F38: bne         $v0, $zero, L_806E4F50
    if (ctx->r2 != 0) {
        // 0x806E4F3C: sw          $v0, 0x1F4($s1)
        MEM_W(0X1F4, ctx->r17) = ctx->r2;
            goto L_806E4F50;
    }
    // 0x806E4F3C: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x806E4F40: jal         0x800445A4
    // 0x806E4F44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806E4F44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x806E4F48: b           L_806E5108
    // 0x806E4F4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806E5108;
    // 0x806E4F4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806E4F50:
    // 0x806E4F50: lw          $t7, 0x16C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X16C);
    // 0x806E4F54: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(649, 0X2188) << 16);
    // 0x806E4F58: sw          $zero, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = 0;
    // 0x806E4F5C: sb          $zero, 0x165($s1)
    MEM_B(0X165, ctx->r17) = 0;
    // 0x806E4F60: addiu       $t6, $t6, 0x5988
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(649, 0X2188));
    // 0x806E4F64: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806E4F68: lhu         $t0, 0xC($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0XC);
    // 0x806E4F6C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806E4F70: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x806E4F74: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806E4F78: addiu       $at, $zero, 0x45C1
    ctx->r1 = ADD32(0, 0X45C1);
    // 0x806E4F7C: sw          $t8, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->r24;
    // 0x806E4F80: bne         $t0, $at, L_806E50E4
    if (ctx->r8 != ctx->r1) {
        // 0x806E4F84: sw          $t9, 0x130($s1)
        MEM_W(0X130, ctx->r17) = ctx->r25;
            goto L_806E50E4;
    }
    // 0x806E4F84: sw          $t9, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->r25;
    // 0x806E4F88: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x806E4F8C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806E4F90: sb          $t1, 0x165($s1)
    MEM_B(0X165, ctx->r17) = ctx->r9;
    // 0x806E4F94: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x806E4F98: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
    // 0x806E4F9C: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x806E4FA0: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x806E4FA4: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x806E4FA8: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x806E4FAC: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x806E4FB0: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x806E4FB4: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x806E4FB8: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x806E4FBC: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x806E4FC0: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x806E4FC4: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x806E4FC8: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x806E4FCC: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x806E4FD0: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x806E4FD4: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    // 0x806E4FD8: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x806E4FDC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X21F8) << 16);
    // 0x806E4FE0: swc1        $f20, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f20.u32l;
    // 0x806E4FE4: swc1        $f20, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f20.u32l;
    // 0x806E4FE8: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x806E4FEC: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x806E4FF0: swc1        $f20, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f20.u32l;
    // 0x806E4FF4: swc1        $f20, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f20.u32l;
    // 0x806E4FF8: swc1        $f20, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f20.u32l;
    // 0x806E4FFC: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x806E5000: lwc1        $f6, 0x59F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X21F8));
    // 0x806E5004: addiu       $v0, $s1, 0xC4
    ctx->r2 = ADD32(ctx->r17, 0XC4);
    // 0x806E5008: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X21FC) << 16);
    // 0x806E500C: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x806E5010: lwc1        $f8, 0x59FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X21FC));
    // 0x806E5014: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806E5018: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806E501C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E5020: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x806E5024: jal         0x806E3DB8
    // 0x806E5028: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    func_806E3DB8(rdram, ctx);
        goto after_2;
    // 0x806E5028: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    after_2:
    // 0x806E502C: jal         0x80047090
    // 0x806E5030: addiu       $a0, $zero, 0x46EA
    ctx->r4 = ADD32(0, 0X46EA);
    func_80047090(rdram, ctx);
        goto after_3;
    // 0x806E5030: addiu       $a0, $zero, 0x46EA
    ctx->r4 = ADD32(0, 0X46EA);
    after_3:
    // 0x806E5034: lui         $at, 0x46EA
    ctx->r1 = S32(0X46EA << 16);
    // 0x806E5038: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x806E503C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x806E5040: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806E5044: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x806E5048: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x806E504C: jal         0x8004613C
    // 0x806E5050: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x806E5050: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_4:
    // 0x806E5054: bne         $v0, $zero, L_806E506C
    if (ctx->r2 != 0) {
        // 0x806E5058: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_806E506C;
    }
    // 0x806E5058: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x806E505C: jal         0x800445A4
    // 0x806E5060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x806E5060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x806E5064: b           L_806E5108
    // 0x806E5068: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806E5108;
    // 0x806E5068: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806E506C:
    // 0x806E506C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E5070: jal         0x80047F9C
    // 0x806E5074: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x806E5074: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x806E5078: jal         0x80047090
    // 0x806E507C: addiu       $a0, $zero, 0x45C2
    ctx->r4 = ADD32(0, 0X45C2);
    func_80047090(rdram, ctx);
        goto after_7;
    // 0x806E507C: addiu       $a0, $zero, 0x45C2
    ctx->r4 = ADD32(0, 0X45C2);
    after_7:
    // 0x806E5080: lui         $at, 0x45C2
    ctx->r1 = S32(0X45C2 << 16);
    // 0x806E5084: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x806E5088: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x806E508C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806E5090: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x806E5094: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x806E5098: jal         0x8004613C
    // 0x806E509C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_8;
    // 0x806E509C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_8:
    // 0x806E50A0: bne         $v0, $zero, L_806E50B8
    if (ctx->r2 != 0) {
        // 0x806E50A4: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_806E50B8;
    }
    // 0x806E50A4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x806E50A8: jal         0x800445A4
    // 0x806E50AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x806E50AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x806E50B0: b           L_806E5108
    // 0x806E50B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806E5108;
    // 0x806E50B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806E50B8:
    // 0x806E50B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E50BC: jal         0x80047F9C
    // 0x806E50C0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_10;
    // 0x806E50C0: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_10:
    // 0x806E50C4: jal         0x80057978
    // 0x806E50C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80057978(rdram, ctx);
        goto after_11;
    // 0x806E50C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x806E50CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E50D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E50D4: jal         0x806E511C
    // 0x806E50D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_806E511C(rdram, ctx);
        goto after_12;
    // 0x806E50D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x806E50DC: b           L_806E5108
    // 0x806E50E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806E5108;
    // 0x806E50E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806E50E4:
    // 0x806E50E4: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X2200) << 16);
    // 0x806E50E8: lwc1        $f0, 0x5A00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X2200));
    // 0x806E50EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806E50F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E50F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806E50F8: swc1        $f0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f0.u32l;
    // 0x806E50FC: jal         0x806E511C
    // 0x806E5100: swc1        $f0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f0.u32l;
    func_806E511C(rdram, ctx);
        goto after_13;
    // 0x806E5100: swc1        $f0, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f0.u32l;
    after_13:
    // 0x806E5104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806E5108:
    // 0x806E5108: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x806E510C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x806E5110: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x806E5114: jr          $ra
    // 0x806E5118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806E5118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806E7FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7FF4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806E7FF8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806E7FFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806E8000: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806E8004: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806E8008: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806E800C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806E8010: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806E8014: lui         $t1, 0x806F
    ctx->r9 = S32(RELOC_HI16(664, 0XEE0) << 16);
    // 0x806E8018: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806E801C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806E8020: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806E8024: lw          $t1, -0x7EE0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(664, 0XEE0));
    // 0x806E8028: jr          $ra
    // 0x806E802C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806E802C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_800361A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800361A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800361AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800361B0: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x800361B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800361B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800361BC: jal         0x800351BC
    // 0x800361C0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800351BC(rdram, ctx);
        goto after_0;
    // 0x800361C0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800361C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800361C8: bne         $v0, $zero, L_800361D8
    if (ctx->r2 != 0) {
        // 0x800361CC: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_800361D8;
    }
    // 0x800361CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800361D0: b           L_80036250
    // 0x800361D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036250;
    // 0x800361D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800361D8:
    // 0x800361D8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800361DC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800361E0: lw          $t7, 0xF10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XF10);
    // 0x800361E4: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x800361E8: lw          $t6, 0x144($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X144);
    // 0x800361EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800361F0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800361F4: lw          $t0, 0xF14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XF14);
    // 0x800361F8: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x800361FC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80036200: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80036204: lw          $t2, 0x110($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X110);
    // 0x80036208: slt         $at, $t6, $t2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003620C: bne         $at, $zero, L_80036220
    if (ctx->r1 != 0) {
        // 0x80036210: nop
    
            goto L_80036220;
    }
    // 0x80036210: nop

    // 0x80036214: lbu         $t3, 0x155($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X155);
    // 0x80036218: beql        $t3, $zero, L_80036234
    if (ctx->r11 == 0) {
        // 0x8003621C: lw          $t4, 0x14($a2)
        ctx->r12 = MEM_W(ctx->r6, 0X14);
            goto L_80036234;
    }
    goto skip_0;
    // 0x8003621C: lw          $t4, 0x14($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X14);
    skip_0:
L_80036220:
    // 0x80036220: jal         0x8002DBE4
    // 0x80036224: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_1;
    // 0x80036224: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x80036228: b           L_80036250
    // 0x8003622C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036250;
    // 0x8003622C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036230: lw          $t4, 0x14($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X14);
L_80036234:
    // 0x80036234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80036238: bne         $t4, $zero, L_80036250
    if (ctx->r12 != 0) {
        // 0x8003623C: nop
    
            goto L_80036250;
    }
    // 0x8003623C: nop

    // 0x80036240: jal         0x800360A0
    // 0x80036244: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800360A0(rdram, ctx);
        goto after_2;
    // 0x80036244: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x80036248: b           L_80036250
    // 0x8003624C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036250;
    // 0x8003624C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036250:
    // 0x80036250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036254: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80036258: jr          $ra
    // 0x8003625C: nop

    return;
    // 0x8003625C: nop

;}
RECOMP_FUNC void func_8045A5AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045A5AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8045A5B0: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8045A5B4: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8045A5B8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8045A5BC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8045A5C0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8045A5C4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8045A5C8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8045A5CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8045A5D0: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8045A5D4: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8045A5D8: lui         $s0, 0x2
    ctx->r16 = S32(0X2 << 16);
    // 0x8045A5DC: lui         $s1, 0x4
    ctx->r17 = S32(0X4 << 16);
    // 0x8045A5E0: lui         $s2, 0x6
    ctx->r18 = S32(0X6 << 16);
    // 0x8045A5E4: lui         $s3, 0x8
    ctx->r19 = S32(0X8 << 16);
    // 0x8045A5E8: lui         $s4, 0x8
    ctx->r20 = S32(0X8 << 16);
    // 0x8045A5EC: lui         $s5, 0x8
    ctx->r21 = S32(0X8 << 16);
    // 0x8045A5F0: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x8045A5F4: lw          $t1, 0x1F4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1F4);
    // 0x8045A5F8: ori         $t3, $t3, 0x248F
    ctx->r11 = ctx->r11 | 0X248F;
    // 0x8045A5FC: ori         $s5, $s5, 0x100E
    ctx->r21 = ctx->r21 | 0X100E;
    // 0x8045A600: ori         $s4, $s4, 0xA10
    ctx->r20 = ctx->r20 | 0XA10;
    // 0x8045A604: ori         $s3, $s3, 0xE0C
    ctx->r19 = ctx->r19 | 0XE0C;
    // 0x8045A608: ori         $s2, $s2, 0x80C
    ctx->r18 = ctx->r18 | 0X80C;
    // 0x8045A60C: ori         $s1, $s1, 0xA08
    ctx->r17 = ctx->r17 | 0XA08;
    // 0x8045A610: ori         $s0, $s0, 0x408
    ctx->r16 = ctx->r16 | 0X408;
    // 0x8045A614: addiu       $s6, $zero, 0x32
    ctx->r22 = ADD32(0, 0X32);
    // 0x8045A618: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8045A61C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8045A620: addiu       $t5, $zero, 0x806
    ctx->r13 = ADD32(0, 0X806);
    // 0x8045A624: addiu       $t4, $zero, 0x208
    ctx->r12 = ADD32(0, 0X208);
    // 0x8045A628: addiu       $t2, $zero, 0x90
    ctx->r10 = ADD32(0, 0X90);
    // 0x8045A62C: lui         $v1, 0xBF00
    ctx->r3 = S32(0XBF00 << 16);
L_8045A630:
    // 0x8045A630: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x8045A634: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8045A638: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8045A63C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8045A640: beql        $t9, $zero, L_8045A710
    if (ctx->r25 == 0) {
        // 0x8045A644: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8045A710;
    }
    goto skip_0;
    // 0x8045A644: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
    // 0x8045A648: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8045A64C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A650: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8045A654: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8045A658: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8045A65C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8045A660: mflo        $t7
    ctx->r15 = lo;
    // 0x8045A664: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x8045A668: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8045A66C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A670: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8045A674: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8045A678: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8045A67C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8045A680: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A684: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8045A688: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8045A68C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8045A690: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8045A694: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A698: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8045A69C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8045A6A0: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x8045A6A4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8045A6A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A6AC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8045A6B0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8045A6B4: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8045A6B8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8045A6BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A6C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8045A6C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8045A6C8: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x8045A6CC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8045A6D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A6D4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8045A6D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8045A6DC: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x8045A6E0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8045A6E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A6E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8045A6EC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8045A6F0: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x8045A6F4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8045A6F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A6FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8045A700: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8045A704: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x8045A708: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8045A70C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8045A710:
    // 0x8045A710: bne         $a3, $s6, L_8045A630
    if (ctx->r7 != ctx->r22) {
        // 0x8045A714: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_8045A630;
    }
    // 0x8045A714: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8045A718: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8045A71C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8045A720: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8045A724: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8045A728: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8045A72C: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8045A730: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8045A734: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8045A738: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8045A73C: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8045A740: jr          $ra
    // 0x8045A744: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8045A744: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_805A5368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A536C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A5370: lh          $a3, 0x1F0($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X1F0);
    // 0x805A5374: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805A5378: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805A537C: bne         $a3, $at, L_805A53E8
    if (ctx->r7 != ctx->r1) {
        // 0x805A5380: sll         $a1, $a3, 16
        ctx->r5 = S32(ctx->r7 << 16);
            goto L_805A53E8;
    }
    // 0x805A5380: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x805A5384: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805A5388: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x805A538C: jal         0x80067BBC
    // 0x805A5390: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805A5390: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x805A5394: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x805A5398: jal         0x80067F78
    // 0x805A539C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x805A539C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805A53A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x805A53A4: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x805A53A8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805A53AC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x805A53B0: beq         $v0, $at, L_805A5430
    if (ctx->r2 == ctx->r1) {
        // 0x805A53B4: sh          $v0, 0x1F0($a2)
        MEM_H(0X1F0, ctx->r6) = ctx->r2;
            goto L_805A5430;
    }
    // 0x805A53B4: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
    // 0x805A53B8: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x805A53BC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x805A53C0: jal         0x80067BBC
    // 0x805A53C4: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805A53C4: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_2:
    // 0x805A53C8: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x805A53CC: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x805A53D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x805A53D4: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x805A53D8: jal         0x80067838
    // 0x805A53DC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x805A53DC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x805A53E0: b           L_805A5434
    // 0x805A53E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A5434;
    // 0x805A53E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A53E8:
    // 0x805A53E8: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x805A53EC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x805A53F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805A53F4: jal         0x80067930
    // 0x805A53F8: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_4;
    // 0x805A53F8: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_4:
    // 0x805A53FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x805A5400: beq         $v0, $zero, L_805A5430
    if (ctx->r2 == 0) {
        // 0x805A5404: lh          $a3, 0x1E($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X1E);
            goto L_805A5430;
    }
    // 0x805A5404: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x805A5408: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x805A540C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x805A5410: jal         0x80067BBC
    // 0x805A5414: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x805A5414: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_5:
    // 0x805A5418: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x805A541C: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x805A5420: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x805A5424: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x805A5428: jal         0x800678F0
    // 0x805A542C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x805A542C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_6:
L_805A5430:
    // 0x805A5430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A5434:
    // 0x805A5434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A5438: jr          $ra
    // 0x805A543C: nop

    return;
    // 0x805A543C: nop

;}
RECOMP_FUNC void func_80442774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80442774: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80442778: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044277C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80442780: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80442784: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80442788: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(95, 0X4DE4) << 16);
    // 0x8044278C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80442790: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80442794: addiu       $t7, $t7, 0x3CE4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(95, 0X4DE4));
    // 0x80442798: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8044279C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804427A0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804427A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804427A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804427AC: jal         0x8044284C
    // 0x804427B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8044284C(rdram, ctx);
        goto after_0;
    // 0x804427B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804427B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804427B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804427BC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x804427C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804427C4: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804427C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804427CC: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x804427D0: jal         0x80441FF4
    // 0x804427D4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    func_80441FF4(rdram, ctx);
        goto after_1;
    // 0x804427D4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x804427D8: bne         $v0, $zero, L_804427F0
    if (ctx->r2 != 0) {
        // 0x804427DC: nop
    
            goto L_804427F0;
    }
    // 0x804427DC: nop

    // 0x804427E0: jal         0x800445A4
    // 0x804427E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x804427E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804427E8: b           L_8044283C
    // 0x804427EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8044283C;
    // 0x804427EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804427F0:
    // 0x804427F0: jal         0x80442380
    // 0x804427F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80442380(rdram, ctx);
        goto after_3;
    // 0x804427F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804427F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804427FC: jal         0x80045A34
    // 0x80442800: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_4;
    // 0x80442800: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_4:
    // 0x80442804: bne         $v0, $zero, L_8044281C
    if (ctx->r2 != 0) {
        // 0x80442808: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8044281C;
    }
    // 0x80442808: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8044280C: jal         0x800445A4
    // 0x80442810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x80442810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80442814: b           L_8044283C
    // 0x80442818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8044283C;
    // 0x80442818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8044281C:
    // 0x8044281C: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x80442820: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80442824: jal         0x800657CC
    // 0x80442828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_6;
    // 0x80442828: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8044282C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80442830: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80442834: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80442838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8044283C:
    // 0x8044283C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80442840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80442844: jr          $ra
    // 0x80442848: nop

    return;
    // 0x80442848: nop

;}
RECOMP_FUNC void lfloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082008: floor.w.d   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = S32(floor(ctx->f12.d));
    // 0x8008200C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80082010: jr          $ra
    // 0x80082014: nop

    return;
    // 0x80082014: nop

;}
RECOMP_FUNC void func_80557EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80557EDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80557EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80557EE4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80557EE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80557EEC: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x80557EF0: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x80557EF4: bne         $t6, $zero, L_80557F78
    if (ctx->r14 != 0) {
        // 0x80557EF8: ori         $t7, $v1, 0x1
        ctx->r15 = ctx->r3 | 0X1;
            goto L_80557F78;
    }
    // 0x80557EF8: ori         $t7, $v1, 0x1
    ctx->r15 = ctx->r3 | 0X1;
    // 0x80557EFC: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x80557F00: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x80557F04: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80557F08: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x80557F0C: beq         $t8, $zero, L_80557F48
    if (ctx->r24 == 0) {
        // 0x80557F10: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80557F48;
    }
    // 0x80557F10: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80557F14: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80557F18: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x80557F1C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80557F20: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80557F24: jal         0x8004D1F0
    // 0x80557F28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x80557F28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80557F2C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80557F30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80557F34: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x80557F38: jal         0x8004D698
    // 0x80557F3C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x80557F3C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80557F40: b           L_80557F7C
    // 0x80557F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80557F7C;
    // 0x80557F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80557F48:
    // 0x80557F48: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80557F4C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80557F50: jal         0x8004D1F0
    // 0x80557F54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x80557F54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80557F58: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80557F5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80557F60: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x80557F64: jal         0x8004D698
    // 0x80557F68: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x80557F68: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80557F6C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80557F70: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80557F74: sw          $t9, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r25;
L_80557F78:
    // 0x80557F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80557F7C:
    // 0x80557F7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80557F80: jr          $ra
    // 0x80557F84: nop

    return;
    // 0x80557F84: nop

;}
RECOMP_FUNC void func_805D1000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D1004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D1008: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805D100C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x805D1010: lui         $t8, 0x805D
    ctx->r24 = S32(RELOC_HI16(465, 0X6B0) << 16);
    // 0x805D1014: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805D1018: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805D101C: lw          $t8, 0x16A0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(465, 0X6B0));
    // 0x805D1020: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805D1024: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x805D1028: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x805D102C: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x805D1030: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805D1034: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805D1038: beql        $v1, $zero, L_805D106C
    if (ctx->r3 == 0) {
        // 0x805D103C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D106C;
    }
    goto skip_0;
    // 0x805D103C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805D1040: jalr        $v1
    // 0x805D1044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805D1044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D1048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D104C: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x805D1050: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x805D1054: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x805D1058: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x805D105C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x805D1060: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x805D1064: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x805D1068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D106C:
    // 0x805D106C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D1070: jr          $ra
    // 0x805D1074: nop

    return;
    // 0x805D1074: nop

;}
RECOMP_FUNC void func_8079E800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079E800: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079E804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079E808: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079E80C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8079E810: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8079E814: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8079E818: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8079E81C: beq         $t6, $zero, L_8079E850
    if (ctx->r14 == 0) {
        // 0x8079E820: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8079E850;
    }
    // 0x8079E820: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8079E824: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8079E828: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1980) << 16);
    // 0x8079E82C: lw          $v0, 0x7C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X7C);
    // 0x8079E830: lwc1        $f4, -0xB90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1980));
    // 0x8079E834: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8079E838: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8079E83C: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x8079E840: lw          $t7, 0x80($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X80);
    // 0x8079E844: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8079E848: b           L_8079E874
    // 0x8079E84C: swc1        $f6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f6.u32l;
        goto L_8079E874;
    // 0x8079E84C: swc1        $f6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f6.u32l;
L_8079E850:
    // 0x8079E850: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8079E854: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x8079E858: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x8079E85C: lw          $a0, 0x80($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X80);
    // 0x8079E860: swc1        $f8, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f8.u32l;
    // 0x8079E864: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1984) << 16);
    // 0x8079E868: lwc1        $f10, -0xB8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1984));
    // 0x8079E86C: lw          $t0, 0x80($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X80);
    // 0x8079E870: swc1        $f10, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f10.u32l;
L_8079E874:
    // 0x8079E874: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8079E878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8079E87C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8079E880: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8079E884: addu        $t1, $s0, $v1
    ctx->r9 = ADD32(ctx->r16, ctx->r3);
    // 0x8079E888: lw          $a1, 0x18($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X18);
    // 0x8079E88C: jal         0x8005C174
    // 0x8079E890: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8005C174(rdram, ctx);
        goto after_0;
    // 0x8079E890: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8079E894: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x8079E898: lw          $t2, -0x71A8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X71A8);
    // 0x8079E89C: lui         $t5, 0x807A
    ctx->r13 = S32(RELOC_HI16(835, 0X1848) << 16);
    // 0x8079E8A0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8079E8A4: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8079E8A8: srl         $t4, $t3, 30
    ctx->r12 = S32(U32(ctx->r11) >> 30);
    // 0x8079E8AC: bne         $t4, $zero, L_8079E8D4
    if (ctx->r12 != 0) {
        // 0x8079E8B0: addiu       $t5, $t5, -0xCC8
        ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(835, 0X1848));
            goto L_8079E8D4;
    }
    // 0x8079E8B0: addiu       $t5, $t5, -0xCC8
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(835, 0X1848));
    // 0x8079E8B4: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x8079E8B8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8079E8BC: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x8079E8C0: swc1        $f16, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f16.u32l;
    // 0x8079E8C4: lw          $t7, 0x80($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X80);
    // 0x8079E8C8: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8079E8CC: b           L_8079E8F8
    // 0x8079E8D0: swc1        $f18, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f18.u32l;
        goto L_8079E8F8;
    // 0x8079E8D0: swc1        $f18, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f18.u32l;
L_8079E8D4:
    // 0x8079E8D4: lui         $t8, 0x807A
    ctx->r24 = S32(RELOC_HI16(835, 0X17E8) << 16);
    // 0x8079E8D8: addiu       $t8, $t8, -0xD28
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(835, 0X17E8));
    // 0x8079E8DC: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x8079E8E0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8079E8E4: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x8079E8E8: swc1        $f4, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f4.u32l;
    // 0x8079E8EC: lw          $t0, 0x80($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X80);
    // 0x8079E8F0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8079E8F4: swc1        $f6, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f6.u32l;
L_8079E8F8:
    // 0x8079E8F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8079E8FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8079E900: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8079E904: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079E908: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x8079E90C: jr          $ra
    // 0x8079E910: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8079E910: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806F7A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7A58: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x806F7A5C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x806F7A60: sll         $t3, $a2, 7
    ctx->r11 = S32(ctx->r6 << 7);
    // 0x806F7A64: lw          $v1, 0x26C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X26C);
    // 0x806F7A68: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x806F7A6C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806F7A70: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x806F7A74: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x806F7A78: sll         $t8, $t8, 7
    ctx->r24 = S32(ctx->r24 << 7);
    // 0x806F7A7C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806F7A80: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x806F7A84: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x806F7A88: ori         $t7, $t7, 0x207F
    ctx->r15 = ctx->r15 | 0X207F;
    // 0x806F7A8C: addiu       $t5, $t4, 0x2F0
    ctx->r13 = ADD32(ctx->r12, 0X2F0);
    // 0x806F7A90: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x806F7A94: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x806F7A98: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x806F7A9C: lui         $t7, 0xB100
    ctx->r15 = S32(0XB100 << 16);
    // 0x806F7AA0: lui         $t8, 0x6
    ctx->r24 = S32(0X6 << 16);
    // 0x806F7AA4: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x806F7AA8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806F7AAC: ori         $t8, $t8, 0x4
    ctx->r24 = ctx->r24 | 0X4;
    // 0x806F7AB0: ori         $t7, $t7, 0x204
    ctx->r15 = ctx->r15 | 0X204;
    // 0x806F7AB4: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x806F7AB8: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x806F7ABC: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x806F7AC0: lui         $t4, 0xE
    ctx->r12 = S32(0XE << 16);
    // 0x806F7AC4: lui         $t3, 0xB108
    ctx->r11 = S32(0XB108 << 16);
    // 0x806F7AC8: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x806F7ACC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806F7AD0: ori         $t3, $t3, 0xA0C
    ctx->r11 = ctx->r11 | 0XA0C;
    // 0x806F7AD4: ori         $t4, $t4, 0x80C
    ctx->r12 = ctx->r12 | 0X80C;
    // 0x806F7AD8: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x806F7ADC: jr          $ra
    // 0x806F7AE0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    return;
    // 0x806F7AE0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
;}
