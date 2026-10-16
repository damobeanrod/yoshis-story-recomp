#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8006F500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F500: lui         $a0, 0xA460
    ctx->r4 = S32(0XA460 << 16);
    // 0x8006F504: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x8006F508: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8006F50C:
    // 0x8006F50C: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8006F510: bnel        $t6, $zero, L_8006F50C
    if (ctx->r14 != 0) {
        // 0x8006F514: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8006F50C;
    }
    goto skip_0;
    // 0x8006F514: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8006F518: lui         $t7, 0xB000
    ctx->r15 = S32(0XB000 << 16);
    // 0x8006F51C: lw          $v1, 0x458($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X458);
    // 0x8006F520: lui         $t9, 0xB000
    ctx->r25 = S32(0XB000 << 16);
    // 0x8006F524: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8006F528: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8006F52C:
    // 0x8006F52C: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8006F530: bnel        $t8, $zero, L_8006F52C
    if (ctx->r24 != 0) {
        // 0x8006F534: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8006F52C;
    }
    goto skip_1;
    // 0x8006F534: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x8006F538: lw          $v0, 0x45C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X45C);
    // 0x8006F53C: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x8006F540: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8006F544: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8006F548: or          $t1, $t0, $v0
    ctx->r9 = ctx->r8 | ctx->r2;
    // 0x8006F54C: jr          $ra
    // 0x8006F550: sw          $t1, -0x79E0($at)
    MEM_W(-0X79E0, ctx->r1) = ctx->r9;
    return;
    // 0x8006F550: sw          $t1, -0x79E0($at)
    MEM_W(-0X79E0, ctx->r1) = ctx->r9;
;}
RECOMP_FUNC void func_8043B22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B22C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043B230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043B234: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8043B238: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043B23C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8043B240: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8043B244: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8043B248: jal         0x80047090
    // 0x8043B24C: addiu       $a0, $zero, 0x40C0
    ctx->r4 = ADD32(0, 0X40C0);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8043B24C: addiu       $a0, $zero, 0x40C0
    ctx->r4 = ADD32(0, 0X40C0);
    after_0:
    // 0x8043B250: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x8043B254: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x8043B258: bne         $a0, $v0, L_8043B268
    if (ctx->r4 != ctx->r2) {
        // 0x8043B25C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8043B268;
    }
    // 0x8043B25C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8043B260: b           L_8043B2F0
    // 0x8043B264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043B2F0;
    // 0x8043B264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043B268:
    // 0x8043B268: beq         $a0, $v1, L_8043B2EC
    if (ctx->r4 == ctx->r3) {
        // 0x8043B26C: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_8043B2EC;
    }
    // 0x8043B26C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8043B270: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8043B274: or          $a0, $t0, $at
    ctx->r4 = ctx->r8 | ctx->r1;
    // 0x8043B278: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8043B27C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8043B280: jal         0x8004613C
    // 0x8043B284: lw          $a3, 0x44($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X44);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8043B284: lw          $a3, 0x44($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X44);
    after_1:
    // 0x8043B288: bne         $v0, $zero, L_8043B298
    if (ctx->r2 != 0) {
        // 0x8043B28C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8043B298;
    }
    // 0x8043B28C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8043B290: b           L_8043B2F0
    // 0x8043B294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043B2F0;
    // 0x8043B294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043B298:
    // 0x8043B298: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8043B29C: jal         0x80047F9C
    // 0x8043B2A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8043B2A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8043B2A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8043B2A8: sb          $t7, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r15;
    // 0x8043B2AC: jal         0x8005FDC4
    // 0x8043B2B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x8043B2B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043B2B4: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8043B2B8: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x8043B2BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043B2C0: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x8043B2C4: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x8043B2C8: jalr        $t9
    // 0x8043B2CC: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8043B2CC: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    after_4:
    // 0x8043B2D0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8043B2D4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8043B2D8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8043B2DC: beql        $v0, $zero, L_8043B2F0
    if (ctx->r2 == 0) {
        // 0x8043B2E0: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_8043B2F0;
    }
    goto skip_0;
    // 0x8043B2E0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8043B2E4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8043B2E8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
L_8043B2EC:
    // 0x8043B2EC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8043B2F0:
    // 0x8043B2F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043B2F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043B2F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043B2FC: jr          $ra
    // 0x8043B300: nop

    return;
    // 0x8043B300: nop

;}
RECOMP_FUNC void func_806AA6DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA6DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AA6E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AA6E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AA6E8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806AA6EC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806AA6F0: lui         $t7, 0x806B
    ctx->r15 = S32(RELOC_HI16(589, 0X1184) << 16);
    // 0x806AA6F4: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806AA6F8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806AA6FC: addiu       $t7, $t7, -0x56BC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(589, 0X1184));
    // 0x806AA700: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806AA704: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806AA708: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806AA70C: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806AA710: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806AA714: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806AA718: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AA71C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806AA720: jal         0x80045A34
    // 0x806AA724: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806AA724: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x806AA728: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806AA72C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(589, 0X11FC) << 16);
    // 0x806AA730: lwc1        $f4, -0x5644($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(589, 0X11FC));
    // 0x806AA734: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806AA738: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806AA73C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x806AA740: jal         0x80048378
    // 0x806AA744: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x806AA744: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    after_1:
    // 0x806AA748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AA74C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AA750: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806AA754: jal         0x806AA784
    // 0x806AA758: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806AA784(rdram, ctx);
        goto after_2;
    // 0x806AA758: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x806AA75C: jal         0x806AA2BC
    // 0x806AA760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AA2BC(rdram, ctx);
        goto after_3;
    // 0x806AA760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806AA764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AA768: jal         0x806AA64C
    // 0x806AA76C: addiu       $a1, $zero, 0x4034
    ctx->r5 = ADD32(0, 0X4034);
    func_806AA64C(rdram, ctx);
        goto after_4;
    // 0x806AA76C: addiu       $a1, $zero, 0x4034
    ctx->r5 = ADD32(0, 0X4034);
    after_4:
    // 0x806AA770: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806AA774: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AA778: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806AA77C: jr          $ra
    // 0x806AA780: nop

    return;
    // 0x806AA780: nop

;}
RECOMP_FUNC void Math_FAbsF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081CD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80081CDC: nop

    // 0x80081CE0: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80081CE4: nop

    // 0x80081CE8: bc1fl       L_80081D00
    if (!c1cs) {
        // 0x80081CEC: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_80081D00;
    }
    goto skip_0;
    // 0x80081CEC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_0:
    // 0x80081CF0: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x80081CF4: jr          $ra
    // 0x80081CF8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80081CF8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80081CFC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_80081D00:
    // 0x80081D00: jr          $ra
    // 0x80081D04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80081D04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_8064BA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BA68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064BA6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064BA70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064BA74: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064BA78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064BA7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064BA80: blez        $v0, L_8064BA94
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064BA84: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8064BA94;
    }
    // 0x8064BA84: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8064BA88: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064BA8C: b           L_8064BAC0
    // 0x8064BA90: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064BAC0;
    // 0x8064BA90: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064BA94:
    // 0x8064BA94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064BA98: jal         0x8064BF74
    // 0x8064BA9C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8064BF74(rdram, ctx);
        goto after_0;
    // 0x8064BA9C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_0:
    // 0x8064BAA0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064BAA4: jal         0x80067BBC
    // 0x8064BAA8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8064BAA8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8064BAAC: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8064BAB0: jal         0x80067818
    // 0x8064BAB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8064BAB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8064BAB8: jal         0x8064A43C
    // 0x8064BABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A43C(rdram, ctx);
        goto after_3;
    // 0x8064BABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8064BAC0:
    // 0x8064BAC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064BAC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064BAC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064BACC: jr          $ra
    // 0x8064BAD0: nop

    return;
    // 0x8064BAD0: nop

;}
RECOMP_FUNC void func_8006CF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF40: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006CF44: lw          $t6, -0x7D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D6C);
    // 0x8006CF48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CF4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CF50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006CF54: lhu         $v0, 0x64($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X64);
    // 0x8006CF58: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8006CF5C: beq         $t7, $zero, L_8006CF74
    if (ctx->r15 == 0) {
        // 0x8006CF60: nop
    
            goto L_8006CF74;
    }
    // 0x8006CF60: nop

    // 0x8006CF64: jal         0x8006CDF4
    // 0x8006CF68: nop

    func_8006CDF4(rdram, ctx);
        goto after_0;
    // 0x8006CF68: nop

    after_0:
    // 0x8006CF6C: b           L_8006CF7C
    // 0x8006CF70: nop

        goto L_8006CF7C;
    // 0x8006CF70: nop

L_8006CF74:
    // 0x8006CF74: jal         0x8006CB78
    // 0x8006CF78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006CB78(rdram, ctx);
        goto after_1;
    // 0x8006CF78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_8006CF7C:
    // 0x8006CF7C: jal         0x8006C3F0
    // 0x8006CF80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006C3F0(rdram, ctx);
        goto after_2;
    // 0x8006CF80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8006CF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CF88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CF8C: jr          $ra
    // 0x8006CF90: nop

    return;
    // 0x8006CF90: nop

;}
RECOMP_FUNC void func_8005B7B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B7B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005B7BC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005B7C0: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x8005B7C4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8005B7C8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8005B7CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005B7D0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8005B7D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005B7D8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8005B7DC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005B7E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005B7E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005B7E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8005B7EC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8005B7F0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8005B7F4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8005B7F8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8005B7FC: jal         0x8005B54C
    // 0x8005B800: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_8005B54C(rdram, ctx);
        goto after_0;
    // 0x8005B800: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_0:
    // 0x8005B804: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B808: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005B80C: jr          $ra
    // 0x8005B810: nop

    return;
    // 0x8005B810: nop

;}
RECOMP_FUNC void func_805AC744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AC748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC74C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805AC750: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805AC754: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x805AC758: jal         0x80067BBC
    // 0x805AC75C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805AC75C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x805AC760: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805AC764: jal         0x80067818
    // 0x805AC768: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805AC768: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805AC76C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AC770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AC774: jr          $ra
    // 0x805AC778: nop

    return;
    // 0x805AC778: nop

;}
RECOMP_FUNC void func_805D1078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D107C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D1080: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x805D1084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805D1088: beq         $t6, $zero, L_805D10C4
    if (ctx->r14 == 0) {
        // 0x805D108C: nop
    
            goto L_805D10C4;
    }
    // 0x805D108C: nop

    // 0x805D1090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D1094: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x805D1098: jalr        $t9
    // 0x805D109C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805D109C: nop

    after_0:
    // 0x805D10A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D10A4: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x805D10A8: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x805D10AC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x805D10B0: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x805D10B4: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x805D10B8: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x805D10BC: b           L_805D10C4
    // 0x805D10C0: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_805D10C4;
    // 0x805D10C0: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_805D10C4:
    // 0x805D10C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D10C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D10CC: jr          $ra
    // 0x805D10D0: nop

    return;
    // 0x805D10D0: nop

;}
RECOMP_FUNC void func_806B14DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B14DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B14E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B14E4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806B14E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806B14EC: beql        $t6, $at, L_806B1518
    if (ctx->r14 == ctx->r1) {
        // 0x806B14F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806B1518;
    }
    goto skip_0;
    // 0x806B14F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806B14F4: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x806B14F8: addiu       $at, $zero, 0x400C
    ctx->r1 = ADD32(0, 0X400C);
    // 0x806B14FC: bnel        $t7, $at, L_806B1518
    if (ctx->r15 != ctx->r1) {
        // 0x806B1500: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806B1518;
    }
    goto skip_1;
    // 0x806B1500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806B1504: jal         0x806B1224
    // 0x806B1508: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_806B1224(rdram, ctx);
        goto after_0;
    // 0x806B1508: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806B150C: jal         0x8005FE48
    // 0x806B1510: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x806B1510: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x806B1514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B1518:
    // 0x806B1518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B151C: jr          $ra
    // 0x806B1520: nop

    return;
    // 0x806B1520: nop

;}
RECOMP_FUNC void func_8005B134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B134: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005B138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B13C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005B140: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005B144: jal         0x80050C8C
    // 0x8005B148: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80050C8C(rdram, ctx);
        goto after_0;
    // 0x8005B148: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x8005B14C: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8005B150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005B154: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8005B158: bne         $a3, $zero, L_8005B178
    if (ctx->r7 != 0) {
        // 0x8005B15C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8005B178;
    }
    // 0x8005B15C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005B160: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005B164: addiu       $a0, $a0, 0xC50
    ctx->r4 = ADD32(ctx->r4, 0XC50);
    // 0x8005B168: jal         0x80071380
    // 0x8005B16C: addiu       $a1, $zero, 0x1EF
    ctx->r5 = ADD32(0, 0X1EF);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8005B16C: addiu       $a1, $zero, 0x1EF
    ctx->r5 = ADD32(0, 0X1EF);
    after_1:
    // 0x8005B170: b           L_8005B1D4
    // 0x8005B174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005B1D4;
    // 0x8005B174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005B178:
    // 0x8005B178: jal         0x80065728
    // 0x8005B17C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8005B17C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8005B180: jal         0x80050C48
    // 0x8005B184: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80050C48(rdram, ctx);
        goto after_3;
    // 0x8005B184: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8005B188: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005B18C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8005B190: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8005B194: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8005B198: lhu         $a1, 0x26($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X26);
    // 0x8005B19C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005B1A0: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8005B1A4: lw          $t9, 0x615C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X615C);
    // 0x8005B1A8: jalr        $t9
    // 0x8005B1AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8005B1AC: nop

    after_4:
    // 0x8005B1B0: bne         $v0, $zero, L_8005B1D0
    if (ctx->r2 != 0) {
        // 0x8005B1B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005B1D0;
    }
    // 0x8005B1B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005B1B8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005B1BC: addiu       $a0, $a0, 0xC60
    ctx->r4 = ADD32(ctx->r4, 0XC60);
    // 0x8005B1C0: addiu       $a1, $zero, 0x1FF
    ctx->r5 = ADD32(0, 0X1FF);
    // 0x8005B1C4: jal         0x80071380
    // 0x8005B1C8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    Fault_HungUp(rdram, ctx);
        goto after_5;
    // 0x8005B1C8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_5:
    // 0x8005B1CC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_8005B1D0:
    // 0x8005B1D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8005B1D4:
    // 0x8005B1D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B1D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005B1DC: jr          $ra
    // 0x8005B1E0: nop

    return;
    // 0x8005B1E0: nop

;}
RECOMP_FUNC void func_800436E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800436E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800436E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800436E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800436EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800436F0: jal         0x80043610
    // 0x800436F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_80043610(rdram, ctx);
        goto after_0;
    // 0x800436F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x800436F8: beql        $v0, $zero, L_80043820
    if (ctx->r2 == 0) {
        // 0x800436FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80043820;
    }
    goto skip_0;
    // 0x800436FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80043700: jal         0x8003CA5C
    // 0x80043704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003CA5C(rdram, ctx);
        goto after_1;
    // 0x80043704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80043708: bne         $v0, $zero, L_80043720
    if (ctx->r2 != 0) {
        // 0x8004370C: lui         $s1, 0x800F
        ctx->r17 = S32(0X800F << 16);
            goto L_80043720;
    }
    // 0x8004370C: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x80043710: jal         0x800445A4
    // 0x80043714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80043714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80043718: b           L_80043820
    // 0x8004371C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80043820;
    // 0x8004371C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80043720:
    // 0x80043720: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80043724: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80043728: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8004372C: sw          $t6, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r14;
    // 0x80043730: addiu       $t7, $t7, -0x6228
    ctx->r15 = ADD32(ctx->r15, -0X6228);
    // 0x80043734: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80043738: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x8004373C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80043740: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80043744: sb          $zero, 0xB14($s1)
    MEM_B(0XB14, ctx->r17) = 0;
    // 0x80043748: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    // 0x8004374C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80043750: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80043754: jal         0x8001DC5C
    // 0x80043758: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8001DC5C(rdram, ctx);
        goto after_3;
    // 0x80043758: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8004375C: jal         0x800436A0
    // 0x80043760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800436A0(rdram, ctx);
        goto after_4;
    // 0x80043760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80043764: jal         0x80057978
    // 0x80043768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80057978(rdram, ctx);
        goto after_5;
    // 0x80043768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8004376C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80043770: sw          $t9, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r25;
    // 0x80043774: jal         0x8002DB14
    // 0x80043778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002DB14(rdram, ctx);
        goto after_6;
    // 0x80043778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8004377C: lw          $t1, 0x478($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X478);
    // 0x80043780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80043784: lui         $t0, 0x8007
    ctx->r8 = S32(0X8007 << 16);
    // 0x80043788: sb          $v0, 0xADC($s1)
    MEM_B(0XADC, ctx->r17) = ctx->r2;
    // 0x8004378C: addiu       $t0, $t0, -0x6DF4
    ctx->r8 = ADD32(ctx->r8, -0X6DF4);
    // 0x80043790: sw          $t0, 0xF4($t1)
    MEM_W(0XF4, ctx->r9) = ctx->r8;
    // 0x80043794: lw          $t2, 0xF10($s1)
    ctx->r10 = MEM_W(ctx->r17, 0XF10);
    // 0x80043798: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004379C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800437A0: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x800437A4: jal         0x800679F0
    // 0x800437A8: sw          $v0, 0xF14($t4)
    MEM_W(0XF14, ctx->r12) = ctx->r2;
    func_800679F0(rdram, ctx);
        goto after_7;
    // 0x800437A8: sw          $v0, 0xF14($t4)
    MEM_W(0XF14, ctx->r12) = ctx->r2;
    after_7:
    // 0x800437AC: sw          $zero, 0xB1C($s1)
    MEM_W(0XB1C, ctx->r17) = 0;
    // 0x800437B0: lui         $t5, 0x8002
    ctx->r13 = S32(0X8002 << 16);
    // 0x800437B4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800437B8: addiu       $t5, $t5, 0x33B4
    ctx->r13 = ADD32(ctx->r13, 0X33B4);
    // 0x800437BC: addiu       $t6, $t6, 0x3450
    ctx->r14 = ADD32(ctx->r14, 0X3450);
    // 0x800437C0: sw          $t5, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r13;
    // 0x800437C4: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x800437C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800437CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800437D0: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x800437D4: lw          $t8, 0x3EC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X3EC);
    // 0x800437D8: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800437DC: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x800437E0: lbu         $t0, 0x598($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X598);
    // 0x800437E4: bne         $t0, $at, L_8004380C
    if (ctx->r8 != ctx->r1) {
        // 0x800437E8: nop
    
            goto L_8004380C;
    }
    // 0x800437E8: nop

    // 0x800437EC: jal         0x8006D2E0
    // 0x800437F0: nop

    func_8006D2E0(rdram, ctx);
        goto after_8;
    // 0x800437F0: nop

    after_8:
    // 0x800437F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800437F8: bne         $v0, $at, L_8004380C
    if (ctx->r2 != ctx->r1) {
        // 0x800437FC: nop
    
            goto L_8004380C;
    }
    // 0x800437FC: nop

    // 0x80043800: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x80043804: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80043808: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
L_8004380C:
    // 0x8004380C: jal         0x8004700C
    // 0x80043810: nop

    func_8004700C(rdram, ctx);
        goto after_9;
    // 0x80043810: nop

    after_9:
    // 0x80043814: lw          $t3, 0x1F4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1F4);
    // 0x80043818: sb          $zero, 0x1404($t3)
    MEM_B(0X1404, ctx->r11) = 0;
    // 0x8004381C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80043820:
    // 0x80043820: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80043824: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80043828: jr          $ra
    // 0x8004382C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004382C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806CFFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFFF4: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AFC) << 16);
    // 0x806CFFF8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806CFFFC: lwc1        $f12, 0x129C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AFC));
    // 0x806D0000: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x806D0004: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x806D0008: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_806D000C:
    // 0x806D000C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806D0010: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x806D0014: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806D0018: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806D001C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x806D0020: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806D0024: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806D0028: nop

    // 0x806D002C: bc1f        L_806D0054
    if (!c1cs) {
        // 0x806D0030: nop
    
            goto L_806D0054;
    }
    // 0x806D0030: nop

    // 0x806D0034: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x806D0038: nop

    // 0x806D003C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x806D0040: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x806D0044: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x806D0048: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x806D004C: b           L_806D0070
    // 0x806D0050: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_806D0070;
    // 0x806D0050: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_806D0054:
    // 0x806D0054: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x806D0058: nop

    // 0x806D005C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x806D0060: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x806D0064: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x806D0068: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806D006C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_806D0070:
    // 0x806D0070: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x806D0074: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806D0078: nop

    // 0x806D007C: bc1fl       L_806D00A4
    if (!c1cs) {
        // 0x806D0080: lwc1        $f8, 0x0($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
            goto L_806D00A4;
    }
    goto skip_0;
    // 0x806D0080: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    skip_0:
    // 0x806D0084: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806D0088: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806D008C: nop

    // 0x806D0090: bc1f        L_806D00B8
    if (!c1cs) {
        // 0x806D0094: nop
    
            goto L_806D00B8;
    }
    // 0x806D0094: nop

    // 0x806D0098: b           L_806D00B8
    // 0x806D009C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_806D00B8;
    // 0x806D009C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x806D00A0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
L_806D00A4:
    // 0x806D00A4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x806D00A8: nop

    // 0x806D00AC: bc1f        L_806D00B8
    if (!c1cs) {
        // 0x806D00B0: nop
    
            goto L_806D00B8;
    }
    // 0x806D00B0: nop

    // 0x806D00B4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_806D00B8:
    // 0x806D00B8: bne         $v1, $v0, L_806D000C
    if (ctx->r3 != ctx->r2) {
        // 0x806D00BC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_806D000C;
    }
    // 0x806D00BC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806D00C0: jr          $ra
    // 0x806D00C4: nop

    return;
    // 0x806D00C4: nop

;}
RECOMP_FUNC void func_804B7FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B7FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B7FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B7FE4: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804B7FE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804B7FEC: beq         $t6, $zero, L_804B8028
    if (ctx->r14 == 0) {
        // 0x804B7FF0: nop
    
            goto L_804B8028;
    }
    // 0x804B7FF0: nop

    // 0x804B7FF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B7FF8: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804B7FFC: jalr        $t9
    // 0x804B8000: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804B8000: nop

    after_0:
    // 0x804B8004: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B8008: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804B800C: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804B8010: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804B8014: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804B8018: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804B801C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804B8020: b           L_804B8028
    // 0x804B8024: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804B8028;
    // 0x804B8024: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804B8028:
    // 0x804B8028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B802C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B8030: jr          $ra
    // 0x804B8034: nop

    return;
    // 0x804B8034: nop

;}
RECOMP_FUNC void func_8005BE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BE50: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x8005BE54: addiu       $v0, $v0, -0x41A0
    ctx->r2 = ADD32(ctx->r2, -0X41A0);
    // 0x8005BE58: jr          $ra
    // 0x8005BE5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8005BE5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80563890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80563890: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80563894: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x80563898: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x8056389C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805638A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805638A4: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x805638A8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805638AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x805638B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805638B4: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x805638B8: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x805638BC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805638C0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805638C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805638C8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x805638CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805638D0: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x805638D4: addiu       $t3, $zero, 0x2C80
    ctx->r11 = ADD32(0, 0X2C80);
    // 0x805638D8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x805638DC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x805638E0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x805638E4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x805638E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805638EC: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x805638F0: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x805638F4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x805638F8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x805638FC: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x80563900: ori         $a3, $a3, 0x41C8
    ctx->r7 = ctx->r7 | 0X41C8;
    // 0x80563904: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80563908: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8056390C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80563910: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80563914: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x80563918: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8056391C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80563920: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80563924: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80563928: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8056392C: lui         $t0, 0xFFFE
    ctx->r8 = S32(0XFFFE << 16);
    // 0x80563930: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80563934: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80563938: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8056393C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80563940: ori         $t0, $t0, 0x7339
    ctx->r8 = ctx->r8 | 0X7339;
    // 0x80563944: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80563948: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8056394C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80563950: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x80563954: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x80563958: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8056395C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80563960: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80563964: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80563968: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8056396C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80563970: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x80563974: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80563978: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8056397C: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x80563980: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x80563984: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80563988: jr          $ra
    // 0x8056398C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x8056398C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_8069E654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069E654: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8069E658: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8069E65C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8069E660: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8069E664: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8069E668: nop

    // 0x8069E66C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8069E670: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8069E674: nop

    // 0x8069E678: bc1f        L_8069E684
    if (!c1cs) {
        // 0x8069E67C: nop
    
            goto L_8069E684;
    }
    // 0x8069E67C: nop

    // 0x8069E680: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8069E684:
    // 0x8069E684: jr          $ra
    // 0x8069E688: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8069E688: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_804A4DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4DD4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A4DD8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A4DDC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A4DE0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A4DE4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A4DE8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A4DEC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A4DF0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A4DF4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A4DF8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A4DFC: jr          $ra
    // 0x804A4E00: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A4E00: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80449DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449DC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80449DC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80449DCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80449DD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449DD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80449DD8: bne         $a2, $zero, L_80449E18
    if (ctx->r6 != 0) {
        // 0x80449DDC: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80449E18;
    }
    // 0x80449DDC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80449DE0: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x80449DE4: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x80449DE8: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80449DEC: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80449DF0: bne         $at, $zero, L_80449E58
    if (ctx->r1 != 0) {
        // 0x80449DF4: sw          $t7, 0x28($v0)
        MEM_W(0X28, ctx->r2) = ctx->r15;
            goto L_80449E58;
    }
    // 0x80449DF4: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
    // 0x80449DF8: jal         0x80446B28
    // 0x80449DFC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446B28(rdram, ctx);
        goto after_0;
    // 0x80449DFC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80449E00: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449E04: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449E08: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80449E0C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449E10: b           L_80449E58
    // 0x80449E14: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80449E58;
    // 0x80449E14: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_80449E18:
    // 0x80449E18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80449E1C: bnel        $a2, $at, L_80449E48
    if (ctx->r6 != ctx->r1) {
        // 0x80449E20: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80449E48;
    }
    goto skip_0;
    // 0x80449E20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80449E24: jal         0x80446B28
    // 0x80449E28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446B28(rdram, ctx);
        goto after_1;
    // 0x80449E28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80449E2C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449E30: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449E34: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80449E38: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449E3C: b           L_80449E58
    // 0x80449E40: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80449E58;
    // 0x80449E40: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80449E44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80449E48:
    // 0x80449E48: bnel        $a2, $at, L_80449E5C
    if (ctx->r6 != ctx->r1) {
        // 0x80449E4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449E5C;
    }
    goto skip_1;
    // 0x80449E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80449E50: jal         0x80446B80
    // 0x80449E54: nop

    func_80446B80(rdram, ctx);
        goto after_2;
    // 0x80449E54: nop

    after_2:
L_80449E58:
    // 0x80449E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449E5C:
    // 0x80449E5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80449E60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449E64: jr          $ra
    // 0x80449E68: nop

    return;
    // 0x80449E68: nop

;}
RECOMP_FUNC void func_80410010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80410010: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80410014: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80410018: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8041001C: addu        $a2, $a0, $at
    ctx->r6 = ADD32(ctx->r4, ctx->r1);
    // 0x80410020: lw          $t6, 0x39E4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X39E4);
    // 0x80410024: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80410028: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8041002C: beq         $t6, $zero, L_80410110
    if (ctx->r14 == 0) {
        // 0x80410030: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80410110;
    }
    // 0x80410030: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80410034: addu        $a1, $a0, $at
    ctx->r5 = ADD32(ctx->r4, ctx->r1);
    // 0x80410038: lw          $t1, 0x39E8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X39E8);
    // 0x8041003C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_80410040:
    // 0x80410040: beq         $t1, $zero, L_804100FC
    if (ctx->r9 == 0) {
        // 0x80410044: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804100FC;
    }
    // 0x80410044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80410048: addiu       $t7, $t1, 0x1
    ctx->r15 = ADD32(ctx->r9, 0X1);
L_8041004C:
    // 0x8041004C: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80410050: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80410054: mflo        $t8
    ctx->r24 = lo;
    // 0x80410058: addu        $a3, $t8, $v0
    ctx->r7 = ADD32(ctx->r24, ctx->r2);
    // 0x8041005C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80410060: multu       $a3, $t2
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80410064: mflo        $t9
    ctx->r25 = lo;
    // 0x80410068: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8041006C: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80410070: sh          $t3, -0x40($s0)
    MEM_H(-0X40, ctx->r16) = ctx->r11;
    // 0x80410074: lh          $t4, 0x2($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X2);
    // 0x80410078: sh          $t4, -0x3E($s0)
    MEM_H(-0X3E, ctx->r16) = ctx->r12;
    // 0x8041007C: lw          $t5, 0x39DC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X39DC);
    // 0x80410080: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80410084: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80410088: mflo        $t8
    ctx->r24 = lo;
    // 0x8041008C: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x80410090: sh          $t3, -0x30($s0)
    MEM_H(-0X30, ctx->r16) = ctx->r11;
    // 0x80410094: lh          $t4, 0x2($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X2);
    // 0x80410098: sh          $t4, -0x2E($s0)
    MEM_H(-0X2E, ctx->r16) = ctx->r12;
    // 0x8041009C: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x804100A0: sh          $t5, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r13;
    // 0x804100A4: lw          $t6, 0x39E0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X39E0);
    // 0x804100A8: lh          $t3, 0x2($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X2);
    // 0x804100AC: multu       $t6, $t2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804100B0: mflo        $t9
    ctx->r25 = lo;
    // 0x804100B4: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x804100B8: sh          $t4, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r12;
    // 0x804100BC: lw          $t5, 0x39DC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X39DC);
    // 0x804100C0: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x804100C4: multu       $t5, $t2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804100C8: mflo        $t8
    ctx->r24 = lo;
    // 0x804100CC: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x804100D0: sh          $t3, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r11;
    // 0x804100D4: lw          $t4, 0x39E0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X39E0);
    // 0x804100D8: lh          $t8, 0x2($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X2);
    // 0x804100DC: multu       $t4, $t2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804100E0: mflo        $t7
    ctx->r15 = lo;
    // 0x804100E4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x804100E8: sh          $t9, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r25;
    // 0x804100EC: lw          $t1, 0x39E8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X39E8);
    // 0x804100F0: sltu        $at, $v0, $t1
    ctx->r1 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x804100F4: bnel        $at, $zero, L_8041004C
    if (ctx->r1 != 0) {
        // 0x804100F8: addiu       $t7, $t1, 0x1
        ctx->r15 = ADD32(ctx->r9, 0X1);
            goto L_8041004C;
    }
    goto skip_0;
    // 0x804100F8: addiu       $t7, $t1, 0x1
    ctx->r15 = ADD32(ctx->r9, 0X1);
    skip_0:
L_804100FC:
    // 0x804100FC: lw          $t3, 0x39E4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X39E4);
    // 0x80410100: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80410104: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x80410108: bne         $at, $zero, L_80410040
    if (ctx->r1 != 0) {
        // 0x8041010C: nop
    
            goto L_80410040;
    }
    // 0x8041010C: nop

L_80410110:
    // 0x80410110: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80410114: jr          $ra
    // 0x80410118: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80410118: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80461B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80461B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80461B94: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80461B98: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80461B9C: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X37DC) << 16);
    // 0x80461BA0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80461BA4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80461BA8: lw          $t8, 0x3D6C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(122, 0X37DC));
    // 0x80461BAC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80461BB0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80461BB4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80461BB8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80461BBC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80461BC0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80461BC4: beql        $v1, $zero, L_80461BF8
    if (ctx->r3 == 0) {
        // 0x80461BC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80461BF8;
    }
    goto skip_0;
    // 0x80461BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80461BCC: jalr        $v1
    // 0x80461BD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80461BD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80461BD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80461BD8: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80461BDC: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80461BE0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80461BE4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80461BE8: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80461BEC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80461BF0: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80461BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80461BF8:
    // 0x80461BF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80461BFC: jr          $ra
    // 0x80461C00: nop

    return;
    // 0x80461C00: nop

;}
RECOMP_FUNC void func_80023E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023E64: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80023E68: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80023E6C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80023E70: nop

    // 0x80023E74: bc1fl       L_80023E88
    if (!c1cs) {
        // 0x80023E78: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80023E88;
    }
    goto skip_0;
    // 0x80023E78: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x80023E7C: jr          $ra
    // 0x80023E80: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    return;
    // 0x80023E80: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x80023E84: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80023E88:
    // 0x80023E88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80023E8C: bc1f        L_80023E98
    if (!c1cs) {
        // 0x80023E90: nop
    
            goto L_80023E98;
    }
    // 0x80023E90: nop

    // 0x80023E94: sw          $t6, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r14;
L_80023E98:
    // 0x80023E98: jr          $ra
    // 0x80023E9C: nop

    return;
    // 0x80023E9C: nop

;}
RECOMP_FUNC void func_807A67B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A67B8: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X15A4) << 16);
    // 0x807A67BC: lwc1        $f0, 0x72A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X15A4));
    // 0x807A67C0: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x807A67C4: jr          $ra
    // 0x807A67C8: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x807A67C8: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void MtxConv_L2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800818E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800818EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800818F0: jal         0x80086F58
    // 0x800818F4: nop

    guMtxL2F(rdram, ctx);
        goto after_0;
    // 0x800818F4: nop

    after_0:
    // 0x800818F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800818FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081900: jr          $ra
    // 0x80081904: nop

    return;
    // 0x80081904: nop

;}
RECOMP_FUNC void func_806F8188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8188: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x806F818C: lw          $v0, -0x74E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74E8);
    // 0x806F8190: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x806F8194: addiu       $v1, $v1, -0x74E4
    ctx->r3 = ADD32(ctx->r3, -0X74E4);
    // 0x806F8198: beq         $v0, $zero, L_806F8240
    if (ctx->r2 == 0) {
        // 0x806F819C: lw          $a1, 0xC($a0)
        ctx->r5 = MEM_W(ctx->r4, 0XC);
            goto L_806F8240;
    }
    // 0x806F819C: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    // 0x806F81A0: andi        $a2, $v0, 0x3
    ctx->r6 = ctx->r2 & 0X3;
    // 0x806F81A4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x806F81A8: beq         $a2, $zero, L_806F81D8
    if (ctx->r6 == 0) {
        // 0x806F81AC: addu        $a0, $a2, $v0
        ctx->r4 = ADD32(ctx->r6, ctx->r2);
            goto L_806F81D8;
    }
    // 0x806F81AC: addu        $a0, $a2, $v0
    ctx->r4 = ADD32(ctx->r6, ctx->r2);
L_806F81B0:
    // 0x806F81B0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x806F81B4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x806F81B8: bne         $a1, $t6, L_806F81C8
    if (ctx->r5 != ctx->r14) {
        // 0x806F81BC: nop
    
            goto L_806F81C8;
    }
    // 0x806F81BC: nop

    // 0x806F81C0: jr          $ra
    // 0x806F81C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x806F81C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806F81C8:
    // 0x806F81C8: bne         $a0, $v0, L_806F81B0
    if (ctx->r4 != ctx->r2) {
        // 0x806F81CC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_806F81B0;
    }
    // 0x806F81CC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806F81D0: beql        $v0, $zero, L_806F8244
    if (ctx->r2 == 0) {
        // 0x806F81D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806F8244;
    }
    goto skip_0;
    // 0x806F81D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_806F81D8:
    // 0x806F81D8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x806F81DC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x806F81E0: bnel        $a1, $t7, L_806F81F4
    if (ctx->r5 != ctx->r15) {
        // 0x806F81E4: lw          $t8, 0x4($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X4);
            goto L_806F81F4;
    }
    goto skip_1;
    // 0x806F81E4: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x806F81E8: jr          $ra
    // 0x806F81EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x806F81EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F81F0: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
L_806F81F4:
    // 0x806F81F4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806F81F8: bnel        $a1, $t8, L_806F820C
    if (ctx->r5 != ctx->r24) {
        // 0x806F81FC: lw          $t9, 0x4($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X4);
            goto L_806F820C;
    }
    goto skip_2;
    // 0x806F81FC: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    skip_2:
    // 0x806F8200: jr          $ra
    // 0x806F8204: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x806F8204: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F8208: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
L_806F820C:
    // 0x806F820C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806F8210: bnel        $a1, $t9, L_806F8224
    if (ctx->r5 != ctx->r25) {
        // 0x806F8214: lw          $t0, 0x4($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X4);
            goto L_806F8224;
    }
    goto skip_3;
    // 0x806F8214: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    skip_3:
    // 0x806F8218: jr          $ra
    // 0x806F821C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x806F821C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F8220: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
L_806F8224:
    // 0x806F8224: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806F8228: bne         $a1, $t0, L_806F8238
    if (ctx->r5 != ctx->r8) {
        // 0x806F822C: nop
    
            goto L_806F8238;
    }
    // 0x806F822C: nop

    // 0x806F8230: jr          $ra
    // 0x806F8234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x806F8234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806F8238:
    // 0x806F8238: bne         $v0, $zero, L_806F81D8
    if (ctx->r2 != 0) {
        // 0x806F823C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_806F81D8;
    }
    // 0x806F823C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_806F8240:
    // 0x806F8240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F8244:
    // 0x806F8244: jr          $ra
    // 0x806F8248: nop

    return;
    // 0x806F8248: nop

;}
RECOMP_FUNC void func_804BD3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD3E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BD3EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804BD3F0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804BD3F4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804BD3F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD3FC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804BD400: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804BD404: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804BD408: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804BD40C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804BD410: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(191, 0X40A0) << 16);
    // 0x804BD414: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804BD418: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804BD41C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804BD420: lw          $t2, -0x630($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(191, 0X40A0));
    // 0x804BD424: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804BD428: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804BD42C: jal         0x804BD11C
    // 0x804BD430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804BD11C(rdram, ctx);
        goto after_0;
    // 0x804BD430: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BD434: jal         0x804BD178
    // 0x804BD438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804BD178(rdram, ctx);
        goto after_1;
    // 0x804BD438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804BD43C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BD440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BD444: jr          $ra
    // 0x804BD448: nop

    return;
    // 0x804BD448: nop

;}
RECOMP_FUNC void func_805350A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805350A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805350A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805350A8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805350AC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x805350B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805350B4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x805350B8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x805350BC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x805350C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805350C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x805350C8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805350CC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x805350D0: lui         $t2, 0x8053
    ctx->r10 = S32(RELOC_HI16(348, 0X1048) << 16);
    // 0x805350D4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805350D8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805350DC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x805350E0: lw          $t2, 0x5658($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(348, 0X1048));
    // 0x805350E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805350E8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x805350EC: jal         0x8053471C
    // 0x805350F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8053471C(rdram, ctx);
        goto after_0;
    // 0x805350F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805350F4: jal         0x80534778
    // 0x805350F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80534778(rdram, ctx);
        goto after_1;
    // 0x805350F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805350FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80535100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80535104: jr          $ra
    // 0x80535108: nop

    return;
    // 0x80535108: nop

;}
RECOMP_FUNC void func_8003EE80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EE80: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003EE84: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003EE88: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8003EE8C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8003EE90: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8003EE94: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8003EE98: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8003EE9C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8003EEA0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003EEA4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003EEA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003EEAC: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003EEB0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003EEB4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8003EEB8: lbu         $v0, 0x12C8($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X12C8);
    // 0x8003EEBC: beql        $v0, $zero, L_8003EFD8
    if (ctx->r2 == 0) {
        // 0x8003EEC0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8003EFD8;
    }
    goto skip_0;
    // 0x8003EEC0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8003EEC4: lhu         $t6, 0x12BE($s3)
    ctx->r14 = MEM_HU(ctx->r19, 0X12BE);
    // 0x8003EEC8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8003EECC: blez        $v0, L_8003EFD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003EED0: sw          $t6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r14;
            goto L_8003EFD4;
    }
    // 0x8003EED0: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8003EED4: addiu       $fp, $zero, 0x406C
    ctx->r30 = ADD32(0, 0X406C);
    // 0x8003EED8: addiu       $s7, $zero, 0x4004
    ctx->r23 = ADD32(0, 0X4004);
    // 0x8003EEDC: addiu       $s6, $zero, 0x18
    ctx->r22 = ADD32(0, 0X18);
    // 0x8003EEE0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_8003EEE4:
    // 0x8003EEE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003EEE8: addu        $t9, $s2, $t7
    ctx->r25 = ADD32(ctx->r18, ctx->r15);
    // 0x8003EEEC: andi        $t0, $t9, 0x7
    ctx->r8 = ctx->r25 & 0X7;
    // 0x8003EEF0: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003EEF4: mflo        $t1
    ctx->r9 = lo;
    // 0x8003EEF8: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8003EEFC: lw          $s0, 0x11FC($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X11FC);
    // 0x8003EF00: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8003EF04: beq         $v0, $s7, L_8003EF38
    if (ctx->r2 == ctx->r23) {
        // 0x8003EF08: nop
    
            goto L_8003EF38;
    }
    // 0x8003EF08: nop

    // 0x8003EF0C: beq         $v0, $fp, L_8003EF68
    if (ctx->r2 == ctx->r30) {
        // 0x8003EF10: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8003EF68;
    }
    // 0x8003EF10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003EF14: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x8003EF18: beq         $v0, $at, L_8003EF88
    if (ctx->r2 == ctx->r1) {
        // 0x8003EF1C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8003EF88;
    }
    // 0x8003EF1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003EF20: addiu       $at, $zero, 0x4301
    ctx->r1 = ADD32(0, 0X4301);
    // 0x8003EF24: beq         $v0, $at, L_8003EFA8
    if (ctx->r2 == ctx->r1) {
        // 0x8003EF28: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8003EFA8;
    }
    // 0x8003EF28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003EF2C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003EF30: b           L_8003EFC0
    // 0x8003EF34: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
        goto L_8003EFC0;
    // 0x8003EF34: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
L_8003EF38:
    // 0x8003EF38: jal         0x8003E8C0
    // 0x8003EF3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003E8C0(rdram, ctx);
        goto after_0;
    // 0x8003EF3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8003EF40: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003EF44: jal         0x800447C8
    // 0x8003EF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8003EF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003EF4C: beq         $s1, $zero, L_8003EFC0
    if (ctx->r17 == 0) {
        // 0x8003EF50: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003EFC0;
    }
    // 0x8003EF50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003EF54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003EF58: jal         0x8003F004
    // 0x8003EF5C: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    func_8003F004(rdram, ctx);
        goto after_2;
    // 0x8003EF5C: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    after_2:
    // 0x8003EF60: b           L_8003EFC4
    // 0x8003EF64: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8003EFC4;
    // 0x8003EF64: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8003EF68:
    // 0x8003EF68: jal         0x8003EA94
    // 0x8003EF6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003EA94(rdram, ctx);
        goto after_3;
    // 0x8003EF6C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8003EF70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003EF74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003EF78: jal         0x8003F004
    // 0x8003EF7C: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    func_8003F004(rdram, ctx);
        goto after_4;
    // 0x8003EF7C: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    after_4:
    // 0x8003EF80: b           L_8003EFC4
    // 0x8003EF84: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8003EFC4;
    // 0x8003EF84: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8003EF88:
    // 0x8003EF88: jal         0x8003EAE0
    // 0x8003EF8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003EAE0(rdram, ctx);
        goto after_5;
    // 0x8003EF8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8003EF90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003EF94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003EF98: jal         0x8003F004
    // 0x8003EF9C: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    func_8003F004(rdram, ctx);
        goto after_6;
    // 0x8003EF9C: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    after_6:
    // 0x8003EFA0: b           L_8003EFC4
    // 0x8003EFA4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8003EFC4;
    // 0x8003EFA4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8003EFA8:
    // 0x8003EFA8: jal         0x8003EB90
    // 0x8003EFAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003EB90(rdram, ctx);
        goto after_7;
    // 0x8003EFAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8003EFB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8003EFB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003EFB8: jal         0x8003F004
    // 0x8003EFBC: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    func_8003F004(rdram, ctx);
        goto after_8;
    // 0x8003EFBC: andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    after_8:
L_8003EFC0:
    // 0x8003EFC0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8003EFC4:
    // 0x8003EFC4: andi        $s4, $s4, 0xFFFF
    ctx->r20 = ctx->r20 & 0XFFFF;
    // 0x8003EFC8: slt         $at, $s4, $s5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8003EFCC: bnel        $at, $zero, L_8003EEE4
    if (ctx->r1 != 0) {
        // 0x8003EFD0: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_8003EEE4;
    }
    goto skip_1;
    // 0x8003EFD0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    skip_1:
L_8003EFD4:
    // 0x8003EFD4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8003EFD8:
    // 0x8003EFD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003EFDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EFE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003EFE4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8003EFE8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003EFEC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8003EFF0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8003EFF4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8003EFF8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8003EFFC: jr          $ra
    // 0x8003F000: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8003F000: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8064A9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A9DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A9E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A9E4: jal         0x8004700C
    // 0x8064A9E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8064A9E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064A9EC: beq         $v0, $zero, L_8064AA4C
    if (ctx->r2 == 0) {
        // 0x8064A9F0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8064AA4C;
    }
    // 0x8064A9F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064A9F4: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064A9F8: blez        $v1, L_8064AA08
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8064A9FC: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8064AA08;
    }
    // 0x8064A9FC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8064AA00: b           L_8064AA4C
    // 0x8064AA04: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064AA4C;
    // 0x8064AA04: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064AA08:
    // 0x8064AA08: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8064AA0C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064AA10: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8064AA14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064AA18: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8064AA1C: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8064AA20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064AA24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8064AA28: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8064AA2C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8064AA30: nop

    // 0x8064AA34: bc1fl       L_8064AA50
    if (!c1cs) {
        // 0x8064AA38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064AA50;
    }
    goto skip_0;
    // 0x8064AA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064AA3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8064AA40: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064AA44: jal         0x8064AEA8
    // 0x8064AA48: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    func_8064AEA8(rdram, ctx);
        goto after_1;
    // 0x8064AA48: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    after_1:
L_8064AA4C:
    // 0x8064AA4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064AA50:
    // 0x8064AA50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064AA54: jr          $ra
    // 0x8064AA58: nop

    return;
    // 0x8064AA58: nop

;}
RECOMP_FUNC void func_8044ED68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044ED68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044ED6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044ED70: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8044ED74: lui         $t8, 0x8045
    ctx->r24 = S32(RELOC_HI16(98, 0X13088) << 16);
    // 0x8044ED78: addiu       $t8, $t8, 0x7468
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(98, 0X13088));
    // 0x8044ED7C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8044ED80: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8044ED84: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8044ED88: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8044ED8C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8044ED90: jal         0x8044EAE0
    // 0x8044ED94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8044EAE0(rdram, ctx);
        goto after_0;
    // 0x8044ED94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8044ED98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8044ED9C: lui         $t0, 0xB800
    ctx->r8 = S32(0XB800 << 16);
    // 0x8044EDA0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8044EDA4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8044EDA8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8044EDAC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8044EDB0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8044EDB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044EDB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044EDBC: jr          $ra
    // 0x8044EDC0: nop

    return;
    // 0x8044EDC0: nop

;}
RECOMP_FUNC void func_8057F914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F914: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8057F918: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8057F91C: addiu       $v0, $a0, 0x6C
    ctx->r2 = ADD32(ctx->r4, 0X6C);
    // 0x8057F920: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8057F924: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8057F928: div.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
L_8057F92C:
    // 0x8057F92C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8057F930: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8057F934: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8057F938: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8057F93C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8057F940: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8057F944: nop

    // 0x8057F948: bc1f        L_8057F954
    if (!c1cs) {
        // 0x8057F94C: nop
    
            goto L_8057F954;
    }
    // 0x8057F94C: nop

    // 0x8057F950: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
L_8057F954:
    // 0x8057F954: bne         $v1, $a0, L_8057F92C
    if (ctx->r3 != ctx->r4) {
        // 0x8057F958: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8057F92C;
    }
    // 0x8057F958: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8057F95C: jr          $ra
    // 0x8057F960: nop

    return;
    // 0x8057F960: nop

;}
RECOMP_FUNC void func_8077DDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077DDE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8077DDE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8077DDE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077DDEC: lui         $a0, 0x8078
    ctx->r4 = S32(RELOC_HI16(778, 0X220) << 16);
    // 0x8077DDF0: lui         $a1, 0x8078
    ctx->r5 = S32(RELOC_HI16(778, 0X230) << 16);
    // 0x8077DDF4: addiu       $a1, $a1, -0x1FF0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(778, 0X230));
    // 0x8077DDF8: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(778, 0X220));
    // 0x8077DDFC: jal         0x8004667C
    // 0x8077DE00: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8077DE00: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x8077DE04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8077DE08: lui         $t6, 0x8078
    ctx->r14 = S32(RELOC_HI16(778, 0X13C) << 16);
    // 0x8077DE0C: addiu       $t6, $t6, -0x20E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(778, 0X13C));
    // 0x8077DE10: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8077DE14: lui         $v0, 0x8078
    ctx->r2 = S32(RELOC_HI16(778, 0XA8) << 16);
    // 0x8077DE18: sw          $t6, -0x72C4($at)
    MEM_W(-0X72C4, ctx->r1) = ctx->r14;
    // 0x8077DE1C: addiu       $v0, $v0, -0x2178
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(778, 0XA8));
    // 0x8077DE20: jr          $ra
    // 0x8077DE24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8077DE24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806EAA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EAA74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EAA78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EAA7C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EAA80: lbu         $t6, 0xF4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF4);
    // 0x806EAA84: bne         $t6, $zero, L_806EAAB0
    if (ctx->r14 != 0) {
        // 0x806EAA88: nop
    
            goto L_806EAAB0;
    }
    // 0x806EAA88: nop

    // 0x806EAA8C: jal         0x80065954
    // 0x806EAA90: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x806EAA90: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    after_0:
    // 0x806EAA94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806EAA98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EAA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EAAA0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806EAAA4: nop

    // 0x806EAAA8: bc1f        L_806EAAB8
    if (!c1cs) {
        // 0x806EAAAC: nop
    
            goto L_806EAAB8;
    }
    // 0x806EAAAC: nop

L_806EAAB0:
    // 0x806EAAB0: b           L_806EAAB8
    // 0x806EAAB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806EAAB8;
    // 0x806EAAB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EAAB8:
    // 0x806EAAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EAABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EAAC0: jr          $ra
    // 0x806EAAC4: nop

    return;
    // 0x806EAAC4: nop

;}
RECOMP_FUNC void func_807B0DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0DF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807B0DF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807B0DF8: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3934) << 16);
    // 0x807B0DFC: lwc1        $f6, 0x3484($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3934));
    // 0x807B0E00: lwc1        $f4, 0x64($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X64);
    // 0x807B0E04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807B0E08: swc1        $f8, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f8.u32l;
    // 0x807B0E0C: lwc1        $f10, 0x64($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X64);
    // 0x807B0E10: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x807B0E14: nop

    // 0x807B0E18: bc1f        L_807B0E28
    if (!c1cs) {
        // 0x807B0E1C: nop
    
            goto L_807B0E28;
    }
    // 0x807B0E1C: nop

    // 0x807B0E20: swc1        $f0, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f0.u32l;
    // 0x807B0E24: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
L_807B0E28:
    // 0x807B0E28: jr          $ra
    // 0x807B0E2C: nop

    return;
    // 0x807B0E2C: nop

;}
RECOMP_FUNC void func_805845DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805845DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805845E0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805845E4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805845E8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805845EC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805845F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805845F4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805845F8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805845FC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584600: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584604: jr          $ra
    // 0x80584608: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584608: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804A2818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A2818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A281C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A2820: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804A2824: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x804A2828: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804A282C: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x804A2830: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x804A2834: beq         $at, $zero, L_804A2874
    if (ctx->r1 == 0) {
        // 0x804A2838: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_804A2874;
    }
    // 0x804A2838: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804A283C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804A2840: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x804A2844: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_804A2848:
    // 0x804A2848: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x804A284C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804A2850: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x804A2854: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x804A2858: bne         $v1, $a0, L_804A2848
    if (ctx->r3 != ctx->r4) {
        // 0x804A285C: swc1        $f0, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
            goto L_804A2848;
    }
    // 0x804A285C: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x804A2860: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804A2864: jal         0x80048378
    // 0x804A2868: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x804A2868: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x804A286C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804A2870: lbu         $v0, 0x30($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X30);
L_804A2874:
    // 0x804A2874: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x804A2878: sll         $t6, $v0, 5
    ctx->r14 = S32(ctx->r2 << 5);
    // 0x804A287C: lui         $t0, 0x804A
    ctx->r8 = S32(RELOC_HI16(173, 0X2550) << 16);
    // 0x804A2880: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804A2884: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x804A2888: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804A288C: lw          $t0, 0x2990($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(173, 0X2550));
    // 0x804A2890: sw          $t0, 0x134($a2)
    MEM_W(0X134, ctx->r6) = ctx->r8;
    // 0x804A2894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A2898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A289C: jr          $ra
    // 0x804A28A0: nop

    return;
    // 0x804A28A0: nop

;}
RECOMP_FUNC void func_80579AF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80579AF4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80579AF8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80579AFC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80579B00: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80579B04: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80579B08: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80579B0C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80579B10: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80579B14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80579B18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80579B1C: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x80579B20: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80579B24: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x80579B28: lw          $s5, 0x38($v0)
    ctx->r21 = MEM_W(ctx->r2, 0X38);
    // 0x80579B2C: jal         0x80047058
    // 0x80579B30: lw          $s6, 0x3C($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X3C);
    func_80047058(rdram, ctx);
        goto after_0;
    // 0x80579B30: lw          $s6, 0x3C($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X3C);
    after_0:
    // 0x80579B34: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80579B38: lw          $t6, -0x7630($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7630);
    // 0x80579B3C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80579B40: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x80579B44: blez        $t6, L_80579BC0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80579B48: sw          $t6, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r14;
            goto L_80579BC0;
    }
    // 0x80579B48: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x80579B4C: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x80579B50: addiu       $s2, $s2, 0x7EA0
    ctx->r18 = ADD32(ctx->r18, 0X7EA0);
L_80579B54:
    // 0x80579B54: lw          $t8, 0xB34($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XB34);
    // 0x80579B58: sh          $t8, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r24;
    // 0x80579B5C: lh          $v1, 0xC($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC);
    // 0x80579B60: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x80579B64: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80579B68: bnel        $at, $zero, L_80579BC4
    if (ctx->r1 != 0) {
        // 0x80579B6C: sll         $t3, $s1, 1
        ctx->r11 = S32(ctx->r17 << 1);
            goto L_80579BC4;
    }
    goto skip_0;
    // 0x80579B6C: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
    skip_0:
    // 0x80579B70: lw          $v0, 0x168($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X168);
    // 0x80579B74: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80579B78: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80579B7C: lh          $t0, 0x7C($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X7C);
    // 0x80579B80: lw          $t9, 0x80($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X80);
    // 0x80579B84: multu       $t0, $v1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80579B88: mflo        $t1
    ctx->r9 = lo;
    // 0x80579B8C: addu        $s3, $t9, $t1
    ctx->r19 = ADD32(ctx->r25, ctx->r9);
    // 0x80579B90: jal         0x8005B350
    // 0x80579B94: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8005B350(rdram, ctx);
        goto after_1;
    // 0x80579B94: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x80579B98: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80579B9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80579BA0: jal         0x8005B350
    // 0x80579BA4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8005B350(rdram, ctx);
        goto after_2;
    // 0x80579BA4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x80579BA8: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80579BAC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80579BB0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80579BB4: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80579BB8: bne         $at, $zero, L_80579B54
    if (ctx->r1 != 0) {
        // 0x80579BBC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80579B54;
    }
    // 0x80579BBC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80579BC0:
    // 0x80579BC0: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
L_80579BC4:
    // 0x80579BC4: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x80579BC8: lh          $t5, 0xC($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XC);
    // 0x80579BCC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80579BD0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80579BD4: beql        $t5, $zero, L_80579BF0
    if (ctx->r13 == 0) {
        // 0x80579BD8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80579BF0;
    }
    goto skip_1;
    // 0x80579BD8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80579BDC: lbu         $t6, -0x7634($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7634);
    // 0x80579BE0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80579BE4: jal         0x8057B444
    // 0x80579BE8: sb          $t6, 0x165($s7)
    MEM_B(0X165, ctx->r23) = ctx->r14;
    func_8057B444(rdram, ctx);
        goto after_3;
    // 0x80579BE8: sb          $t6, 0x165($s7)
    MEM_B(0X165, ctx->r23) = ctx->r14;
    after_3:
    // 0x80579BEC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80579BF0:
    // 0x80579BF0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80579BF4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80579BF8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80579BFC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80579C00: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80579C04: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80579C08: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80579C0C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80579C10: jr          $ra
    // 0x80579C14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80579C14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80522E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522E88: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80522E8C: lw          $t6, -0x72E4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X72E4);
    // 0x80522E90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80522E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80522E98: beql        $t6, $zero, L_80522EB4
    if (ctx->r14 == 0) {
        // 0x80522E9C: lbu         $t8, 0x165($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X165);
            goto L_80522EB4;
    }
    goto skip_0;
    // 0x80522E9C: lbu         $t8, 0x165($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X165);
    skip_0:
    // 0x80522EA0: lbu         $t7, 0x165($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X165);
    // 0x80522EA4: beql        $t7, $zero, L_80522EB4
    if (ctx->r15 == 0) {
        // 0x80522EA8: lbu         $t8, 0x165($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X165);
            goto L_80522EB4;
    }
    goto skip_1;
    // 0x80522EA8: lbu         $t8, 0x165($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X165);
    skip_1:
    // 0x80522EAC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80522EB0: lbu         $t8, 0x165($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X165);
L_80522EB4:
    // 0x80522EB4: bnel        $t8, $zero, L_80522EC8
    if (ctx->r24 != 0) {
        // 0x80522EB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80522EC8;
    }
    goto skip_2;
    // 0x80522EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80522EBC: jal         0x80522AD4
    // 0x80522EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80522AD4(rdram, ctx);
        goto after_0;
    // 0x80522EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80522EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80522EC8:
    // 0x80522EC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80522ECC: jr          $ra
    // 0x80522ED0: nop

    return;
    // 0x80522ED0: nop

;}
RECOMP_FUNC void func_8045297C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045297C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80452980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452984: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452988: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045298C: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x80452990: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80452994: sw          $t6, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r14;
    // 0x80452998: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045299C: jal         0x8045030C
    // 0x804529A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8045030C(rdram, ctx);
        goto after_0;
    // 0x804529A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804529A4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804529A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804529AC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804529B0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804529B4: jal         0x80445B54
    // 0x804529B8: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    func_80445B54(rdram, ctx);
        goto after_1;
    // 0x804529B8: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    after_1:
    // 0x804529BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804529C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804529C4: jr          $ra
    // 0x804529C8: nop

    return;
    // 0x804529C8: nop

;}
RECOMP_FUNC void func_804CAB40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CAB40: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804CAB44: addiu       $at, $zero, 0x4115
    ctx->r1 = ADD32(0, 0X4115);
    // 0x804CAB48: beq         $v0, $at, L_804CAB60
    if (ctx->r2 == ctx->r1) {
        // 0x804CAB4C: addiu       $at, $zero, 0x453C
        ctx->r1 = ADD32(0, 0X453C);
            goto L_804CAB60;
    }
    // 0x804CAB4C: addiu       $at, $zero, 0x453C
    ctx->r1 = ADD32(0, 0X453C);
    // 0x804CAB50: beq         $v0, $at, L_804CAB6C
    if (ctx->r2 == ctx->r1) {
        // 0x804CAB54: nop
    
            goto L_804CAB6C;
    }
    // 0x804CAB54: nop

    // 0x804CAB58: b           L_804CAB78
    // 0x804CAB5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CAB78;
    // 0x804CAB5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CAB60:
    // 0x804CAB60: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(231, 0X238) << 16);
    // 0x804CAB64: jr          $ra
    // 0x804CAB68: addiu       $v0, $v0, -0x5288
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(231, 0X238));
    return;
    // 0x804CAB68: addiu       $v0, $v0, -0x5288
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(231, 0X238));
L_804CAB6C:
    // 0x804CAB6C: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(231, 0X104) << 16);
    // 0x804CAB70: jr          $ra
    // 0x804CAB74: addiu       $v0, $v0, -0x53BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(231, 0X104));
    return;
    // 0x804CAB74: addiu       $v0, $v0, -0x53BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(231, 0X104));
L_804CAB78:
    // 0x804CAB78: jr          $ra
    // 0x804CAB7C: nop

    return;
    // 0x804CAB7C: nop

;}
RECOMP_FUNC void func_805A8D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A8D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A8D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A8D18: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805A8D1C: slti        $at, $v0, 0x41CA
    ctx->r1 = SIGNED(ctx->r2) < 0X41CA ? 1 : 0;
    // 0x805A8D20: bne         $at, $zero, L_805A8D44
    if (ctx->r1 != 0) {
        // 0x805A8D24: addiu       $t6, $v0, -0x418E
        ctx->r14 = ADD32(ctx->r2, -0X418E);
            goto L_805A8D44;
    }
    // 0x805A8D24: addiu       $t6, $v0, -0x418E
    ctx->r14 = ADD32(ctx->r2, -0X418E);
    // 0x805A8D28: addiu       $at, $zero, 0x44E7
    ctx->r1 = ADD32(0, 0X44E7);
    // 0x805A8D2C: beq         $v0, $at, L_805A8D90
    if (ctx->r2 == ctx->r1) {
        // 0x805A8D30: addiu       $at, $zero, 0x45D9
        ctx->r1 = ADD32(0, 0X45D9);
            goto L_805A8D90;
    }
    // 0x805A8D30: addiu       $at, $zero, 0x45D9
    ctx->r1 = ADD32(0, 0X45D9);
    // 0x805A8D34: beq         $v0, $at, L_805A8DA0
    if (ctx->r2 == ctx->r1) {
        // 0x805A8D38: nop
    
            goto L_805A8DA0;
    }
    // 0x805A8D38: nop

    // 0x805A8D3C: b           L_805A8DBC
    // 0x805A8D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A8DBC;
    // 0x805A8D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A8D44:
    // 0x805A8D44: slti        $at, $v0, 0x4194
    ctx->r1 = SIGNED(ctx->r2) < 0X4194 ? 1 : 0;
    // 0x805A8D48: bne         $at, $zero, L_805A8D60
    if (ctx->r1 != 0) {
        // 0x805A8D4C: addiu       $at, $zero, 0x41C9
        ctx->r1 = ADD32(0, 0X41C9);
            goto L_805A8D60;
    }
    // 0x805A8D4C: addiu       $at, $zero, 0x41C9
    ctx->r1 = ADD32(0, 0X41C9);
    // 0x805A8D50: beq         $v0, $at, L_805A8D80
    if (ctx->r2 == ctx->r1) {
        // 0x805A8D54: nop
    
            goto L_805A8D80;
    }
    // 0x805A8D54: nop

    // 0x805A8D58: b           L_805A8DBC
    // 0x805A8D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A8DBC;
    // 0x805A8D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A8D60:
    // 0x805A8D60: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x805A8D64: beq         $at, $zero, L_805A8DB8
    if (ctx->r1 == 0) {
        // 0x805A8D68: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_805A8DB8;
    }
    // 0x805A8D68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805A8D6C: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(429, 0X1460) << 16);
    // 0x805A8D70: addu        $at, $at, $t6
    gpr jr_addend_805A8D78 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x805A8D74: lw          $t6, -0x5EA0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(429, 0X1460));
    // 0x805A8D78: jr          $t6
    // 0x805A8D7C: nop

    switch (jr_addend_805A8D78 >> 2) {
        case 0: goto L_805A8DB0; break;
        case 1: goto L_805A8DB0; break;
        case 2: goto L_805A8DB0; break;
        case 3: goto L_805A8DB0; break;
        case 4: goto L_805A8DB0; break;
        case 5: goto L_805A8DB0; break;
        default: switch_error(__func__, 0x805A8D78, 0x805AA160);
    }
    // 0x805A8D7C: nop

L_805A8D80:
    // 0x805A8D80: jal         0x805A8DC8
    // 0x805A8D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_805A8DC8(rdram, ctx);
        goto after_0;
    // 0x805A8D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x805A8D88: b           L_805A8DBC
    // 0x805A8D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A8DBC;
    // 0x805A8D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A8D90:
    // 0x805A8D90: jal         0x805A8DC8
    // 0x805A8D94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805A8DC8(rdram, ctx);
        goto after_1;
    // 0x805A8D94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805A8D98: b           L_805A8DBC
    // 0x805A8D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A8DBC;
    // 0x805A8D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A8DA0:
    // 0x805A8DA0: jal         0x805A8DC8
    // 0x805A8DA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_805A8DC8(rdram, ctx);
        goto after_2;
    // 0x805A8DA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x805A8DA8: b           L_805A8DBC
    // 0x805A8DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A8DBC;
    // 0x805A8DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A8DB0:
    // 0x805A8DB0: jal         0x805A8DC8
    // 0x805A8DB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_805A8DC8(rdram, ctx);
        goto after_3;
    // 0x805A8DB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_805A8DB8:
    // 0x805A8DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A8DBC:
    // 0x805A8DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A8DC0: jr          $ra
    // 0x805A8DC4: nop

    return;
    // 0x805A8DC4: nop

;}
RECOMP_FUNC void func_80466010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80466010: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80466014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80466018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8046601C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80466020: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80466024: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80466028: jal         0x80047090
    // 0x8046602C: addiu       $a0, $zero, 0x4097
    ctx->r4 = ADD32(0, 0X4097);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8046602C: addiu       $a0, $zero, 0x4097
    ctx->r4 = ADD32(0, 0X4097);
    after_0:
    // 0x80466030: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80466034: beq         $v0, $at, L_80466078
    if (ctx->r2 == ctx->r1) {
        // 0x80466038: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80466078;
    }
    // 0x80466038: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8046603C: lui         $at, 0x4097
    ctx->r1 = S32(0X4097 << 16);
    // 0x80466040: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80466044: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80466048: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8046604C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80466050: jal         0x8004613C
    // 0x80466054: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80466054: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80466058: beq         $v0, $zero, L_80466078
    if (ctx->r2 == 0) {
        // 0x8046605C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80466078;
    }
    // 0x8046605C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80466060: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80466064: jal         0x80047F9C
    // 0x80466068: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80466068: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8046606C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80466070: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80466074: sb          $t6, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r14;
L_80466078:
    // 0x80466078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046607C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80466080: jr          $ra
    // 0x80466084: nop

    return;
    // 0x80466084: nop

    // 0x80466088: nop

    // 0x8046608C: nop

;}
RECOMP_FUNC void Math_FCeilF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081C8C: jal         0x80082018
    // 0x80081C90: nop

    ceilf_recomp(rdram, ctx);
        goto after_0;
    // 0x80081C90: nop

    after_0:
    // 0x80081C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081C98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081C9C: jr          $ra
    // 0x80081CA0: nop

    return;
    // 0x80081CA0: nop

;}
RECOMP_FUNC void func_8002769C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002769C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800276A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800276A4: jal         0x80024748
    // 0x800276A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x800276A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800276AC: beql        $v0, $zero, L_800276D0
    if (ctx->r2 == 0) {
        // 0x800276B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800276D0;
    }
    goto skip_0;
    // 0x800276B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800276B4: jal         0x8002761C
    // 0x800276B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002761C(rdram, ctx);
        goto after_1;
    // 0x800276B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800276BC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800276C0: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x800276C4: addiu       $t6, $t6, 0x7634
    ctx->r14 = ADD32(ctx->r14, 0X7634);
    // 0x800276C8: sw          $t6, 0x160($t7)
    MEM_W(0X160, ctx->r15) = ctx->r14;
    // 0x800276CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800276D0:
    // 0x800276D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800276D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800276D8: jr          $ra
    // 0x800276DC: nop

    return;
    // 0x800276DC: nop

;}
RECOMP_FUNC void func_8043D07C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D07C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043D080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043D084: lh          $a3, 0x1F0($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X1F0);
    // 0x8043D088: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8043D08C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8043D090: bne         $a3, $at, L_8043D0FC
    if (ctx->r7 != ctx->r1) {
        // 0x8043D094: sll         $a1, $a3, 16
        ctx->r5 = S32(ctx->r7 << 16);
            goto L_8043D0FC;
    }
    // 0x8043D094: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8043D098: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8043D09C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8043D0A0: jal         0x80067BBC
    // 0x8043D0A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8043D0A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8043D0A8: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8043D0AC: jal         0x80067F78
    // 0x8043D0B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8043D0B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8043D0B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8043D0B8: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8043D0BC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8043D0C0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8043D0C4: beq         $v0, $at, L_8043D144
    if (ctx->r2 == ctx->r1) {
        // 0x8043D0C8: sh          $v0, 0x1F0($a2)
        MEM_H(0X1F0, ctx->r6) = ctx->r2;
            goto L_8043D144;
    }
    // 0x8043D0C8: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
    // 0x8043D0CC: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8043D0D0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8043D0D4: jal         0x80067BBC
    // 0x8043D0D8: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8043D0D8: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_2:
    // 0x8043D0DC: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8043D0E0: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8043D0E4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8043D0E8: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8043D0EC: jal         0x80067838
    // 0x8043D0F0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x8043D0F0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x8043D0F4: b           L_8043D148
    // 0x8043D0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043D148;
    // 0x8043D0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043D0FC:
    // 0x8043D0FC: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8043D100: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8043D104: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8043D108: jal         0x80067930
    // 0x8043D10C: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_4;
    // 0x8043D10C: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_4:
    // 0x8043D110: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8043D114: beq         $v0, $zero, L_8043D144
    if (ctx->r2 == 0) {
        // 0x8043D118: lh          $a3, 0x1E($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X1E);
            goto L_8043D144;
    }
    // 0x8043D118: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8043D11C: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8043D120: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8043D124: jal         0x80067BBC
    // 0x8043D128: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8043D128: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_5:
    // 0x8043D12C: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8043D130: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8043D134: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8043D138: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8043D13C: jal         0x800678F0
    // 0x8043D140: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x8043D140: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_6:
L_8043D144:
    // 0x8043D144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043D148:
    // 0x8043D148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043D14C: jr          $ra
    // 0x8043D150: nop

    return;
    // 0x8043D150: nop

;}
RECOMP_FUNC void func_8064AD64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AD64: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064AD68: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064AD6C: jr          $ra
    // 0x8064AD70: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8064AD70: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80026FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026FD4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80026FD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026FDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80026FE0: jal         0x80024748
    // 0x80026FE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80024748(rdram, ctx);
        goto after_0;
    // 0x80026FE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80026FE8: beql        $v0, $zero, L_800270B8
    if (ctx->r2 == 0) {
        // 0x80026FEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800270B8;
    }
    goto skip_0;
    // 0x80026FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80026FF0: lw          $a2, 0x1F4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F4);
    // 0x80026FF4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80026FF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80026FFC: lw          $t6, 0x14($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X14);
    // 0x80027000: lw          $v0, 0x44($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X44);
    // 0x80027004: beql        $t6, $zero, L_8002701C
    if (ctx->r14 == 0) {
        // 0x80027008: sw          $v0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r2;
            goto L_8002701C;
    }
    goto skip_1;
    // 0x80027008: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    skip_1:
    // 0x8002700C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80027010: b           L_80027050
    // 0x80027014: sw          $v0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r2;
        goto L_80027050;
    // 0x80027014: sw          $v0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r2;
    // 0x80027018: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
L_8002701C:
    // 0x8002701C: jal         0x800356E8
    // 0x80027020: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    func_800356E8(rdram, ctx);
        goto after_1;
    // 0x80027020: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_1:
    // 0x80027024: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80027028: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002702C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80027030: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x80027034: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80027038: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8002703C: nop

    // 0x80027040: bc1f        L_80027050
    if (!c1cs) {
        // 0x80027044: nop
    
            goto L_80027050;
    }
    // 0x80027044: nop

    // 0x80027048: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002704C: sw          $v0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r2;
L_80027050:
    // 0x80027050: bne         $v0, $zero, L_80027088
    if (ctx->r2 != 0) {
        // 0x80027054: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_80027088;
    }
    // 0x80027054: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80027058: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x8002705C: lw          $t1, 0x15C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X15C);
    // 0x80027060: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80027064: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80027068: addiu       $t9, $t9, 0x4778
    ctx->r25 = ADD32(ctx->r25, 0X4778);
    // 0x8002706C: sw          $t7, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r15;
    // 0x80027070: sb          $t8, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r24;
    // 0x80027074: sw          $t9, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r25;
    // 0x80027078: sw          $zero, 0x154($s0)
    MEM_W(0X154, ctx->r16) = 0;
    // 0x8002707C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80027080: b           L_800270B4
    // 0x80027084: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
        goto L_800270B4;
    // 0x80027084: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
L_80027088:
    // 0x80027088: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x8002708C: sw          $t2, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r10;
    // 0x80027090: jal         0x8001D770
    // 0x80027094: sb          $t3, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r11;
    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x80027094: sb          $t3, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r11;
    after_2:
    // 0x80027098: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002709C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x800270A0: jal         0x80067BF8
    // 0x800270A4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x800270A4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x800270A8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800270AC: jal         0x80067818
    // 0x800270B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x800270B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
L_800270B4:
    // 0x800270B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800270B8:
    // 0x800270B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800270BC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800270C0: jr          $ra
    // 0x800270C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800270C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80461430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461430: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80461434: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80461438: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8046143C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80461440: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80461444: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80461448: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8046144C:
    // 0x8046144C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80461450: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80461454: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80461458: nop

    // 0x8046145C: bc1fl       L_80461470
    if (!c1cs) {
        // 0x80461460: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80461470;
    }
    goto skip_0;
    // 0x80461460: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x80461464: b           L_80461480
    // 0x80461468: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
        goto L_80461480;
    // 0x80461468: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x8046146C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80461470:
    // 0x80461470: nop

    // 0x80461474: bc1f        L_80461480
    if (!c1cs) {
        // 0x80461478: nop
    
            goto L_80461480;
    }
    // 0x80461478: nop

    // 0x8046147C: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
L_80461480:
    // 0x80461480: bne         $v1, $v0, L_8046144C
    if (ctx->r3 != ctx->r2) {
        // 0x80461484: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8046144C;
    }
    // 0x80461484: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80461488: jr          $ra
    // 0x8046148C: nop

    return;
    // 0x8046148C: nop

;}
RECOMP_FUNC void func_8059EC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059EC8C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8059EC90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8059EC94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8059EC98: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059EC9C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8059ECA0: lhu         $a2, 0x0($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X0);
    // 0x8059ECA4: slti        $at, $a2, 0x4128
    ctx->r1 = SIGNED(ctx->r6) < 0X4128 ? 1 : 0;
    // 0x8059ECA8: bne         $at, $zero, L_8059ED00
    if (ctx->r1 != 0) {
        // 0x8059ECAC: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8059ED00;
    }
    // 0x8059ECAC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8059ECB0: addiu       $at, $zero, 0x41FD
    ctx->r1 = ADD32(0, 0X41FD);
    // 0x8059ECB4: beq         $v0, $at, L_8059EF70
    if (ctx->r2 == ctx->r1) {
        // 0x8059ECB8: lui         $v1, 0x800F
        ctx->r3 = S32(0X800F << 16);
            goto L_8059EF70;
    }
    // 0x8059ECB8: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8059ECBC: addiu       $at, $zero, 0x4301
    ctx->r1 = ADD32(0, 0X4301);
    // 0x8059ECC0: beq         $v0, $at, L_8059ED98
    if (ctx->r2 == ctx->r1) {
        // 0x8059ECC4: lui         $v1, 0x800F
        ctx->r3 = S32(0X800F << 16);
            goto L_8059ED98;
    }
    // 0x8059ECC4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8059ECC8: addiu       $at, $zero, 0x4507
    ctx->r1 = ADD32(0, 0X4507);
    // 0x8059ECCC: beq         $v0, $at, L_8059EE44
    if (ctx->r2 == ctx->r1) {
        // 0x8059ECD0: lui         $v1, 0x800F
        ctx->r3 = S32(0X800F << 16);
            goto L_8059EE44;
    }
    // 0x8059ECD0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8059ECD4: addiu       $at, $zero, 0x4508
    ctx->r1 = ADD32(0, 0X4508);
    // 0x8059ECD8: beq         $v0, $at, L_8059EE44
    if (ctx->r2 == ctx->r1) {
        // 0x8059ECDC: addiu       $at, $zero, 0x4509
        ctx->r1 = ADD32(0, 0X4509);
            goto L_8059EE44;
    }
    // 0x8059ECDC: addiu       $at, $zero, 0x4509
    ctx->r1 = ADD32(0, 0X4509);
    // 0x8059ECE0: beq         $v0, $at, L_8059EE44
    if (ctx->r2 == ctx->r1) {
        // 0x8059ECE4: addiu       $at, $zero, 0x450A
        ctx->r1 = ADD32(0, 0X450A);
            goto L_8059EE44;
    }
    // 0x8059ECE4: addiu       $at, $zero, 0x450A
    ctx->r1 = ADD32(0, 0X450A);
    // 0x8059ECE8: beq         $v0, $at, L_8059EE44
    if (ctx->r2 == ctx->r1) {
        // 0x8059ECEC: addiu       $at, $zero, 0x45E6
        ctx->r1 = ADD32(0, 0X45E6);
            goto L_8059EE44;
    }
    // 0x8059ECEC: addiu       $at, $zero, 0x45E6
    ctx->r1 = ADD32(0, 0X45E6);
    // 0x8059ECF0: beq         $v0, $at, L_8059EEDC
    if (ctx->r2 == ctx->r1) {
        // 0x8059ECF4: lui         $v1, 0x800F
        ctx->r3 = S32(0X800F << 16);
            goto L_8059EEDC;
    }
    // 0x8059ECF4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8059ECF8: b           L_8059EFA8
    // 0x8059ECFC: nop

        goto L_8059EFA8;
    // 0x8059ECFC: nop

L_8059ED00:
    // 0x8059ED00: addiu       $at, $zero, 0x401C
    ctx->r1 = ADD32(0, 0X401C);
    // 0x8059ED04: beq         $v0, $at, L_8059EF34
    if (ctx->r2 == ctx->r1) {
        // 0x8059ED08: addiu       $at, $zero, 0x401D
        ctx->r1 = ADD32(0, 0X401D);
            goto L_8059EF34;
    }
    // 0x8059ED08: addiu       $at, $zero, 0x401D
    ctx->r1 = ADD32(0, 0X401D);
    // 0x8059ED0C: beq         $v0, $at, L_8059EEF8
    if (ctx->r2 == ctx->r1) {
        // 0x8059ED10: addiu       $at, $zero, 0x401F
        ctx->r1 = ADD32(0, 0X401F);
            goto L_8059EEF8;
    }
    // 0x8059ED10: addiu       $at, $zero, 0x401F
    ctx->r1 = ADD32(0, 0X401F);
    // 0x8059ED14: beq         $v0, $at, L_8059EEA4
    if (ctx->r2 == ctx->r1) {
        // 0x8059ED18: or          $s0, $a3, $zero
        ctx->r16 = ctx->r7 | 0;
            goto L_8059EEA4;
    }
    // 0x8059ED18: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8059ED1C: addiu       $at, $zero, 0x403A
    ctx->r1 = ADD32(0, 0X403A);
    // 0x8059ED20: beq         $v0, $at, L_8059EE18
    if (ctx->r2 == ctx->r1) {
        // 0x8059ED24: addiu       $at, $zero, 0x4074
        ctx->r1 = ADD32(0, 0X4074);
            goto L_8059EE18;
    }
    // 0x8059ED24: addiu       $at, $zero, 0x4074
    ctx->r1 = ADD32(0, 0X4074);
    // 0x8059ED28: beq         $v0, $at, L_8059EE84
    if (ctx->r2 == ctx->r1) {
        // 0x8059ED2C: addiu       $at, $zero, 0x40B8
        ctx->r1 = ADD32(0, 0X40B8);
            goto L_8059EE84;
    }
    // 0x8059ED2C: addiu       $at, $zero, 0x40B8
    ctx->r1 = ADD32(0, 0X40B8);
    // 0x8059ED30: beq         $v0, $at, L_8059EDE0
    if (ctx->r2 == ctx->r1) {
        // 0x8059ED34: addiu       $at, $zero, 0x40C5
        ctx->r1 = ADD32(0, 0X40C5);
            goto L_8059EDE0;
    }
    // 0x8059ED34: addiu       $at, $zero, 0x40C5
    ctx->r1 = ADD32(0, 0X40C5);
    // 0x8059ED38: beq         $v0, $at, L_8059ED78
    if (ctx->r2 == ctx->r1) {
        // 0x8059ED3C: addiu       $at, $zero, 0x4127
        ctx->r1 = ADD32(0, 0X4127);
            goto L_8059ED78;
    }
    // 0x8059ED3C: addiu       $at, $zero, 0x4127
    ctx->r1 = ADD32(0, 0X4127);
    // 0x8059ED40: bne         $v0, $at, L_8059EFA8
    if (ctx->r2 != ctx->r1) {
        // 0x8059ED44: nop
    
            goto L_8059EFA8;
    }
    // 0x8059ED44: nop

    // 0x8059ED48: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8059ED4C: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(405, 0X860) << 16);
    // 0x8059ED50: lwc1        $f8, -0xD50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(405, 0X860));
    // 0x8059ED54: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8059ED58: lwc1        $f6, 0x40($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8059ED5C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8059ED60: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8059ED64: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8059ED68: jal         0x8059EC18
    // 0x8059ED6C: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    func_8059EC18(rdram, ctx);
        goto after_0;
    // 0x8059ED6C: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    after_0:
    // 0x8059ED70: b           L_8059F014
    // 0x8059ED74: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8059F014;
    // 0x8059ED74: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8059ED78:
    // 0x8059ED78: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8059ED7C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8059ED80: lw          $t9, 0xE98($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE98);
    // 0x8059ED84: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x8059ED88: jalr        $t9
    // 0x8059ED8C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8059ED8C: nop

    after_1:
    // 0x8059ED90: b           L_8059F014
    // 0x8059ED94: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8059F014;
    // 0x8059ED94: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8059ED98:
    // 0x8059ED98: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8059ED9C: lw          $t9, 0xE8C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XE8C);
    // 0x8059EDA0: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x8059EDA4: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8059EDA8: jalr        $t9
    // 0x8059EDAC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8059EDAC: nop

    after_2:
    // 0x8059EDB0: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8059EDB4: beq         $v0, $zero, L_8059F014
    if (ctx->r2 == 0) {
        // 0x8059EDB8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8059F014;
    }
    // 0x8059EDB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8059EDBC: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x8059EDC0: lw          $a1, 0x1D8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X1D8);
    // 0x8059EDC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8059EDC8: jal         0x80048BE8
    // 0x8059EDCC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_3;
    // 0x8059EDCC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_3:
    // 0x8059EDD0: jal         0x80044194
    // 0x8059EDD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_4;
    // 0x8059EDD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8059EDD8: b           L_8059F014
    // 0x8059EDDC: nop

        goto L_8059F014;
    // 0x8059EDDC: nop

L_8059EDE0:
    // 0x8059EDE0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8059EDE4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8059EDE8: lw          $t9, 0xEB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XEB4);
    // 0x8059EDEC: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x8059EDF0: ori         $a2, $a2, 0x30A4
    ctx->r6 = ctx->r6 | 0X30A4;
    // 0x8059EDF4: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8059EDF8: jalr        $t9
    // 0x8059EDFC: lwc1        $f14, 0x40($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X40);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8059EDFC: lwc1        $f14, 0x40($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X40);
    after_5:
    // 0x8059EE00: beq         $v0, $zero, L_8059F014
    if (ctx->r2 == 0) {
        // 0x8059EE04: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8059F014;
    }
    // 0x8059EE04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8059EE08: jal         0x80044194
    // 0x8059EE0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80044194(rdram, ctx);
        goto after_6;
    // 0x8059EE0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8059EE10: b           L_8059F014
    // 0x8059EE14: nop

        goto L_8059F014;
    // 0x8059EE14: nop

L_8059EE18:
    // 0x8059EE18: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8059EE1C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8059EE20: lw          $t8, 0xA68($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XA68);
    // 0x8059EE24: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x8059EE28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8059EE2C: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x8059EE30: lw          $t9, 0x58($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X58);
    // 0x8059EE34: jalr        $t9
    // 0x8059EE38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8059EE38: nop

    after_7:
    // 0x8059EE3C: b           L_8059F014
    // 0x8059EE40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8059F014;
    // 0x8059EE40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8059EE44:
    // 0x8059EE44: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8059EE48: lw          $t9, 0xEC4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XEC4);
    // 0x8059EE4C: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x8059EE50: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    // 0x8059EE54: jalr        $t9
    // 0x8059EE58: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8059EE58: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_8:
    // 0x8059EE5C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8059EE60: beq         $v0, $zero, L_8059F014
    if (ctx->r2 == 0) {
        // 0x8059EE64: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8059F014;
    }
    // 0x8059EE64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8059EE68: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x8059EE6C: lw          $a1, 0x1D8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X1D8);
    // 0x8059EE70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8059EE74: jal         0x80048BE8
    // 0x8059EE78: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_9;
    // 0x8059EE78: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_9:
    // 0x8059EE7C: b           L_8059F014
    // 0x8059EE80: nop

        goto L_8059F014;
    // 0x8059EE80: nop

L_8059EE84:
    // 0x8059EE84: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8059EE88: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8059EE8C: lw          $t9, 0xEBC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XEBC);
    // 0x8059EE90: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x8059EE94: jalr        $t9
    // 0x8059EE98: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x8059EE98: nop

    after_10:
    // 0x8059EE9C: b           L_8059F014
    // 0x8059EEA0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8059F014;
    // 0x8059EEA0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8059EEA4:
    // 0x8059EEA4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8059EEA8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8059EEAC: lw          $t9, 0xEA4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XEA4);
    // 0x8059EEB0: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8059EEB4: lwc1        $f14, 0x40($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8059EEB8: jalr        $t9
    // 0x8059EEBC: lw          $a2, 0x44($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X44);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x8059EEBC: lw          $a2, 0x44($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X44);
    after_11:
    // 0x8059EEC0: jal         0x80067E68
    // 0x8059EEC4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80067E68(rdram, ctx);
        goto after_12;
    // 0x8059EEC4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_12:
    // 0x8059EEC8: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8059EECC: jal         0x80067818
    // 0x8059EED0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_13;
    // 0x8059EED0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8059EED4: b           L_8059F014
    // 0x8059EED8: nop

        goto L_8059F014;
    // 0x8059EED8: nop

L_8059EEDC:
    // 0x8059EEDC: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8059EEE0: lw          $t9, 0xEB8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XEB8);
    // 0x8059EEE4: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x8059EEE8: jalr        $t9
    // 0x8059EEEC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x8059EEEC: nop

    after_14:
    // 0x8059EEF0: b           L_8059F014
    // 0x8059EEF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8059F014;
    // 0x8059EEF4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8059EEF8:
    // 0x8059EEF8: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8059EEFC: lwc1        $f14, 0x40($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8059EF00: jal         0x8003BC2C
    // 0x8059EF04: lw          $a2, 0x44($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X44);
    func_8003BC2C(rdram, ctx);
        goto after_15;
    // 0x8059EF04: lw          $a2, 0x44($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X44);
    after_15:
    // 0x8059EF08: beq         $v0, $zero, L_8059F014
    if (ctx->r2 == 0) {
        // 0x8059EF0C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8059F014;
    }
    // 0x8059EF0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8059EF10: jal         0x80044194
    // 0x8059EF14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80044194(rdram, ctx);
        goto after_16;
    // 0x8059EF14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x8059EF18: jal         0x80067E68
    // 0x8059EF1C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80067E68(rdram, ctx);
        goto after_17;
    // 0x8059EF1C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_17:
    // 0x8059EF20: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8059EF24: jal         0x80067818
    // 0x8059EF28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_18;
    // 0x8059EF28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_18:
    // 0x8059EF2C: b           L_8059F014
    // 0x8059EF30: nop

        goto L_8059F014;
    // 0x8059EF30: nop

L_8059EF34:
    // 0x8059EF34: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8059EF38: lwc1        $f14, 0x40($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8059EF3C: jal         0x8003BBF4
    // 0x8059EF40: lw          $a2, 0x44($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X44);
    func_8003BBF4(rdram, ctx);
        goto after_19;
    // 0x8059EF40: lw          $a2, 0x44($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X44);
    after_19:
    // 0x8059EF44: beq         $v0, $zero, L_8059F014
    if (ctx->r2 == 0) {
        // 0x8059EF48: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8059F014;
    }
    // 0x8059EF48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8059EF4C: jal         0x80044194
    // 0x8059EF50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80044194(rdram, ctx);
        goto after_20;
    // 0x8059EF50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x8059EF54: jal         0x80067E68
    // 0x8059EF58: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80067E68(rdram, ctx);
        goto after_21;
    // 0x8059EF58: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_21:
    // 0x8059EF5C: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x8059EF60: jal         0x80067818
    // 0x8059EF64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_22;
    // 0x8059EF64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_22:
    // 0x8059EF68: b           L_8059F014
    // 0x8059EF6C: nop

        goto L_8059F014;
    // 0x8059EF6C: nop

L_8059EF70:
    // 0x8059EF70: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8059EF74: lbu         $t3, 0xF5C($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF5C);
    // 0x8059EF78: lbu         $t5, 0xF5D($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF5D);
    // 0x8059EF7C: lw          $t9, 0xEC8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XEC8);
    // 0x8059EF80: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8059EF84: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8059EF88: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8059EF8C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8059EF90: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8059EF94: lhu         $a0, 0x630C($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X630C);
    // 0x8059EF98: jalr        $t9
    // 0x8059EF9C: addiu       $a1, $a3, 0x3C
    ctx->r5 = ADD32(ctx->r7, 0X3C);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_23;
    // 0x8059EF9C: addiu       $a1, $a3, 0x3C
    ctx->r5 = ADD32(ctx->r7, 0X3C);
    after_23:
    // 0x8059EFA0: b           L_8059F014
    // 0x8059EFA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8059F014;
    // 0x8059EFA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8059EFA8:
    // 0x8059EFA8: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8059EFAC: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8059EFB0: lw          $t7, 0xE94($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XE94);
    // 0x8059EFB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8059EFB8: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8059EFBC: sh          $a2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r6;
    // 0x8059EFC0: lw          $t8, 0xE94($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XE94);
    // 0x8059EFC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8059EFC8: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x8059EFCC: swc1        $f10, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f10.u32l;
    // 0x8059EFD0: lw          $t0, 0xE94($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XE94);
    // 0x8059EFD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8059EFD8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8059EFDC: swc1        $f16, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f16.u32l;
    // 0x8059EFE0: lwc1        $f18, 0x3C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8059EFE4: lw          $t1, 0xE94($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XE94);
    // 0x8059EFE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8059EFEC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8059EFF0: lwc1        $f4, 0x40($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8059EFF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8059EFF8: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8059EFFC: lwc1        $f10, 0x44($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X44);
    // 0x8059F000: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8059F004: lw          $t9, 0xC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC);
    // 0x8059F008: jalr        $t9
    // 0x8059F00C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_24;
    // 0x8059F00C: nop

    after_24:
    // 0x8059F010: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8059F014:
    // 0x8059F014: beq         $s0, $zero, L_8059F024
    if (ctx->r16 == 0) {
        // 0x8059F018: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8059F024;
    }
    // 0x8059F018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8059F01C: b           L_8059F028
    // 0x8059F020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8059F028;
    // 0x8059F020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8059F024:
    // 0x8059F024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8059F028:
    // 0x8059F028: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8059F02C: jr          $ra
    // 0x8059F030: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8059F030: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_805A6730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6730: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805A6734: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x805A6738: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x805A673C: lui         $t7, 0x805A
    ctx->r15 = S32(RELOC_HI16(417, 0X1548) << 16);
    // 0x805A6740: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x805A6744: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805A6748: lw          $t7, 0x6808($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(417, 0X1548));
    // 0x805A674C: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x805A6750: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(417, 0X1568) << 16);
    // 0x805A6754: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805A6758: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x805A675C: lh          $t9, 0x6828($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(417, 0X1568));
    // 0x805A6760: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x805A6764: sw          $v0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r2;
    // 0x805A6768: sw          $v0, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r2;
    // 0x805A676C: sb          $zero, 0x158($a0)
    MEM_B(0X158, ctx->r4) = 0;
    // 0x805A6770: jr          $ra
    // 0x805A6774: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    return;
    // 0x805A6774: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x805A6778: nop

    // 0x805A677C: nop

;}
RECOMP_FUNC void func_8045ABB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045ABB8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8045ABBC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8045ABC0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8045ABC4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8045ABC8: lw          $t6, -0x6DA8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DA8);
    // 0x8045ABCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045ABD0: lw          $v0, 0x1F4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1F4);
    // 0x8045ABD4: lw          $v1, 0x8($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X8);
    // 0x8045ABD8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8045ABDC: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8045ABE0: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8045ABE4: lw          $a3, 0x1F4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X1F4);
    // 0x8045ABE8: swc1        $f4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f4.u32l;
    // 0x8045ABEC: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    // 0x8045ABF0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8045ABF4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8045ABF8: lwc1        $f8, 0x84($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X84);
    // 0x8045ABFC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8045AC00: lwc1        $f10, 0x88($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X88);
    // 0x8045AC04: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8045AC08: lwc1        $f16, 0x328($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X328);
    // 0x8045AC0C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8045AC10: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8045AC14: lwc1        $f4, 0x32C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X32C);
    // 0x8045AC18: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8045AC1C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8045AC20: lwc1        $f8, 0x50($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X50);
    // 0x8045AC24: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8045AC28: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8045AC2C: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8045AC30: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8045AC34: jal         0x8045AB2C
    // 0x8045AC38: nop

    func_8045AB2C(rdram, ctx);
        goto after_0;
    // 0x8045AC38: nop

    after_0:
    // 0x8045AC3C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8045AC40: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8045AC44: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8045AC48: swc1        $f18, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f18.u32l;
    // 0x8045AC4C: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8045AC50: swc1        $f10, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f10.u32l;
    // 0x8045AC54: lwc1        $f4, 0x50($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X50);
    // 0x8045AC58: swc1        $f4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f4.u32l;
    // 0x8045AC5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045AC60: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8045AC64: jr          $ra
    // 0x8045AC68: nop

    return;
    // 0x8045AC68: nop

;}
RECOMP_FUNC void func_8003A958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003A95C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003A960: jal         0x8003A620
    // 0x8003A964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003A620(rdram, ctx);
        goto after_0;
    // 0x8003A964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003A968: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003A96C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8003A970: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8003A974: jal         0x80065ABC
    // 0x8003A978: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x8003A978: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    after_1:
    // 0x8003A97C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003A980: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8003A984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003A988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003A98C: jr          $ra
    // 0x8003A990: nop

    return;
    // 0x8003A990: nop

;}
RECOMP_FUNC void func_8040B734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B734: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8040B738: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040B73C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040B740: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8040B744: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040B748: jal         0x8040AE28
    // 0x8040B74C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_8040AE28(rdram, ctx);
        goto after_0;
    // 0x8040B74C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8040B750: jal         0x8040B6F0
    // 0x8040B754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040B6F0(rdram, ctx);
        goto after_1;
    // 0x8040B754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8040B758: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8040B75C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8040B760: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8040B764: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8040B768: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8040B76C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x8040B770: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8040B774: nop

    // 0x8040B778: bc1fl       L_8040B78C
    if (!c1cs) {
        // 0x8040B77C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8040B78C;
    }
    goto skip_0;
    // 0x8040B77C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8040B780: b           L_8040B7A4
    // 0x8040B784: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8040B7A4;
    // 0x8040B784: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8040B788: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8040B78C:
    // 0x8040B78C: nop

    // 0x8040B790: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8040B794: nop

    // 0x8040B798: bc1fl       L_8040B7A8
    if (!c1cs) {
        // 0x8040B79C: swc1        $f2, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
            goto L_8040B7A8;
    }
    goto skip_1;
    // 0x8040B79C: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    skip_1:
    // 0x8040B7A0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8040B7A4:
    // 0x8040B7A4: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
L_8040B7A8:
    // 0x8040B7A8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8040B7AC: lw          $t6, 0x68($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X68);
    // 0x8040B7B0: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(14, 0X1338) << 16);
    // 0x8040B7B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040B7B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040B7BC: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8040B7C0: lw          $t9, -0x4168($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(14, 0X1338));
    // 0x8040B7C4: jalr        $t9
    // 0x8040B7C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8040B7C8: nop

    after_2:
    // 0x8040B7CC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8040B7D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8040B7D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040B7D8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8040B7DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040B7E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8040B7E4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8040B7E8: nop

    // 0x8040B7EC: bc1fl       L_8040B810
    if (!c1cs) {
        // 0x8040B7F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040B810;
    }
    goto skip_2;
    // 0x8040B7F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8040B7F4: jal         0x8040BA40
    // 0x8040B7F8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8040BA40(rdram, ctx);
        goto after_3;
    // 0x8040B7F8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x8040B7FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8040B800: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8040B804: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x8040B808: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x8040B80C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040B810:
    // 0x8040B810: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040B814: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8040B818: jr          $ra
    // 0x8040B81C: nop

    return;
    // 0x8040B81C: nop

;}
RECOMP_FUNC void func_805667A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805667A8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805667AC: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(375, 0XC30) << 16);
    // 0x805667B0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805667B4: beq         $v1, $zero, L_805667C4
    if (ctx->r3 == 0) {
        // 0x805667B8: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_805667C4;
    }
    // 0x805667B8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x805667BC: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x805667C0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_805667C4:
    // 0x805667C4: bne         $v1, $zero, L_80566824
    if (ctx->r3 != 0) {
        // 0x805667C8: nop
    
            goto L_80566824;
    }
    // 0x805667C8: nop

    // 0x805667CC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x805667D0: lui         $t0, 0x8056
    ctx->r8 = S32(RELOC_HI16(375, 0XBE8) << 16);
    // 0x805667D4: addiu       $t0, $t0, 0x7138
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(375, 0XBE8));
    // 0x805667D8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x805667DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805667E0: lw          $t8, 0x7180($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(375, 0XC30));
    // 0x805667E4: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x805667E8: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x805667EC: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x805667F0: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x805667F4: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x805667F8: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x805667FC: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80566800: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x80566804: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80566808: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8056680C: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x80566810: bne         $at, $zero, L_80566824
    if (ctx->r1 != 0) {
        // 0x80566814: sw          $t2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r10;
            goto L_80566824;
    }
    // 0x80566814: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80566818: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8056681C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80566820: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_80566824:
    // 0x80566824: jr          $ra
    // 0x80566828: nop

    return;
    // 0x80566828: nop

;}
RECOMP_FUNC void func_8066DA28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066DA28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066DA2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066DA30: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066DA34: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8066DA38: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    // 0x8066DA3C: beql        $a1, $zero, L_8066DAD4
    if (ctx->r5 == 0) {
        // 0x8066DA40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066DAD4;
    }
    goto skip_0;
    // 0x8066DA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066DA44: lw          $t6, 0x180($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X180);
    // 0x8066DA48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8066DA4C: bnel        $a0, $t6, L_8066DAD4
    if (ctx->r4 != ctx->r14) {
        // 0x8066DA50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066DAD4;
    }
    goto skip_1;
    // 0x8066DA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8066DA54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8066DA58: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x8066DA5C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8066DA60: nop

    // 0x8066DA64: bc1fl       L_8066DAD4
    if (!c1cs) {
        // 0x8066DA68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066DAD4;
    }
    goto skip_2;
    // 0x8066DA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8066DA6C: lwc1        $f6, 0x70($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X70);
    // 0x8066DA70: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8066DA74: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8066DA78: nop

    // 0x8066DA7C: bc1fl       L_8066DAD4
    if (!c1cs) {
        // 0x8066DA80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066DAD4;
    }
    goto skip_3;
    // 0x8066DA80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8066DA84: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8066DA88: jal         0x8004816C
    // 0x8066DA8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8004816C(rdram, ctx);
        goto after_0;
    // 0x8066DA8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8066DA90: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8066DA94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8066DA98: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
    // 0x8066DA9C: lw          $t9, 0x174($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X174);
    // 0x8066DAA0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8066DAA4: sh          $t7, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r15;
    // 0x8066DAA8: jal         0x8005FCA8
    // 0x8066DAAC: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x8066DAAC: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    after_1:
    // 0x8066DAB0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8066DAB4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8066DAB8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8066DABC: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    // 0x8066DAC0: lw          $t1, 0x138($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X138);
    // 0x8066DAC4: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8066DAC8: sw          $t1, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r9;
    // 0x8066DACC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8066DAD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066DAD4:
    // 0x8066DAD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066DAD8: jr          $ra
    // 0x8066DADC: nop

    return;
    // 0x8066DADC: nop

;}
RECOMP_FUNC void func_806CD3D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD3D4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CD3D8: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C34) << 16);
    // 0x806CD3DC: lwc1        $f6, -0xCAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C34));
    // 0x806CD3E0: lwc1        $f4, 0x868($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X868);
    // 0x806CD3E4: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C38) << 16);
    // 0x806CD3E8: lwc1        $f10, -0xCA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C38));
    // 0x806CD3EC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806CD3F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806CD3F4: jr          $ra
    // 0x806CD3F8: swc1        $f16, 0x868($v0)
    MEM_W(0X868, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x806CD3F8: swc1        $f16, 0x868($v0)
    MEM_W(0X868, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_805ADF64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADF64: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADF68: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADF6C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADF70: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADF74: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADF78: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADF7C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADF80: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADF84: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADF88: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADF8C: jr          $ra
    // 0x805ADF90: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADF90: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807B6E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B6E50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B6E54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B6E58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B6E5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807B6E60: jal         0x8004700C
    // 0x807B6E64: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807B6E64: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x807B6E68: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x807B6E6C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807B6E70: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807B6E74: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807B6E78: sb          $t7, 0x165($t8)
    MEM_B(0X165, ctx->r24) = ctx->r15;
    // 0x807B6E7C: lbu         $t9, 0x5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5);
    // 0x807B6E80: bnel        $t9, $zero, L_807B7134
    if (ctx->r25 != 0) {
        // 0x807B6E84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807B7134;
    }
    goto skip_0;
    // 0x807B6E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807B6E88: lbu         $t0, 0x6($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X6);
    // 0x807B6E8C: beql        $t0, $zero, L_807B7134
    if (ctx->r8 == 0) {
        // 0x807B6E90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807B7134;
    }
    goto skip_1;
    // 0x807B6E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x807B6E94: beql        $v0, $zero, L_807B7134
    if (ctx->r2 == 0) {
        // 0x807B6E98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807B7134;
    }
    goto skip_2;
    // 0x807B6E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x807B6E9C: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x807B6EA0: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x807B6EA4: lhu         $t2, 0xC($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0XC);
    // 0x807B6EA8: andi        $t3, $t2, 0x1000
    ctx->r11 = ctx->r10 & 0X1000;
    // 0x807B6EAC: bnel        $t3, $at, L_807B7114
    if (ctx->r11 != ctx->r1) {
        // 0x807B6EB0: lw          $t7, 0x478($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X478);
            goto L_807B7114;
    }
    goto skip_3;
    // 0x807B6EB0: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
    skip_3:
    // 0x807B6EB4: jal         0x80067970
    // 0x807B6EB8: nop

    func_80067970(rdram, ctx);
        goto after_1;
    // 0x807B6EB8: nop

    after_1:
    // 0x807B6EBC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807B6EC0: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807B6EC4: lw          $v0, 0xCE8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XCE8);
    // 0x807B6EC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807B6ECC: bne         $v0, $zero, L_807B6F28
    if (ctx->r2 != 0) {
        // 0x807B6ED0: nop
    
            goto L_807B6F28;
    }
    // 0x807B6ED0: nop

    // 0x807B6ED4: lw          $t4, 0xFB8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XFB8);
    // 0x807B6ED8: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x807B6EDC: srl         $t6, $t5, 30
    ctx->r14 = S32(U32(ctx->r13) >> 30);
    // 0x807B6EE0: bne         $t6, $zero, L_807B6F08
    if (ctx->r14 != 0) {
        // 0x807B6EE4: nop
    
            goto L_807B6F08;
    }
    // 0x807B6EE4: nop

    // 0x807B6EE8: jal         0x807B5314
    // 0x807B6EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B5314(rdram, ctx);
        goto after_2;
    // 0x807B6EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807B6EF0: jal         0x807B5598
    // 0x807B6EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B5598(rdram, ctx);
        goto after_3;
    // 0x807B6EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807B6EF8: jal         0x807B4E4C
    // 0x807B6EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B4E4C(rdram, ctx);
        goto after_4;
    // 0x807B6EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807B6F00: b           L_807B6F90
    // 0x807B6F04: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
        goto L_807B6F90;
    // 0x807B6F04: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_807B6F08:
    // 0x807B6F08: jal         0x807B5F10
    // 0x807B6F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B5F10(rdram, ctx);
        goto after_5;
    // 0x807B6F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807B6F10: jal         0x807B61D4
    // 0x807B6F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B61D4(rdram, ctx);
        goto after_6;
    // 0x807B6F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x807B6F18: jal         0x807B5848
    // 0x807B6F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B5848(rdram, ctx);
        goto after_7;
    // 0x807B6F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x807B6F20: b           L_807B6F90
    // 0x807B6F24: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
        goto L_807B6F90;
    // 0x807B6F24: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_807B6F28:
    // 0x807B6F28: bnel        $v0, $at, L_807B7134
    if (ctx->r2 != ctx->r1) {
        // 0x807B6F2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807B7134;
    }
    goto skip_4;
    // 0x807B6F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x807B6F30: lw          $t7, 0xFB8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XFB8);
    // 0x807B6F34: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x807B6F38: srl         $t9, $t8, 30
    ctx->r25 = S32(U32(ctx->r24) >> 30);
    // 0x807B6F3C: bne         $t9, $zero, L_807B6F6C
    if (ctx->r25 != 0) {
        // 0x807B6F40: nop
    
            goto L_807B6F6C;
    }
    // 0x807B6F40: nop

    // 0x807B6F44: jal         0x807B5198
    // 0x807B6F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B5198(rdram, ctx);
        goto after_8;
    // 0x807B6F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x807B6F4C: jal         0x807B5664
    // 0x807B6F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B5664(rdram, ctx);
        goto after_9;
    // 0x807B6F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x807B6F54: jal         0x807B4FD0
    // 0x807B6F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B4FD0(rdram, ctx);
        goto after_10;
    // 0x807B6F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x807B6F5C: jal         0x807B4E00
    // 0x807B6F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B4E00(rdram, ctx);
        goto after_11;
    // 0x807B6F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x807B6F64: b           L_807B6F90
    // 0x807B6F68: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
        goto L_807B6F90;
    // 0x807B6F68: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_807B6F6C:
    // 0x807B6F6C: jal         0x807B5D4C
    // 0x807B6F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B5D4C(rdram, ctx);
        goto after_12;
    // 0x807B6F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x807B6F74: jal         0x807B62DC
    // 0x807B6F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B62DC(rdram, ctx);
        goto after_13;
    // 0x807B6F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x807B6F7C: jal         0x807B5AA8
    // 0x807B6F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B5AA8(rdram, ctx);
        goto after_14;
    // 0x807B6F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x807B6F84: jal         0x807B579C
    // 0x807B6F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B579C(rdram, ctx);
        goto after_15;
    // 0x807B6F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x807B6F8C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_807B6F90:
    // 0x807B6F90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x807B6F94: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x807B6F98: sb          $v0, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r2;
    // 0x807B6F9C: sb          $v0, 0x7EA5($at)
    MEM_B(0X7EA5, ctx->r1) = ctx->r2;
    // 0x807B6FA0: jal         0x80046E88
    // 0x807B6FA4: addiu       $a0, $zero, 0x4013
    ctx->r4 = ADD32(0, 0X4013);
    func_80046E88(rdram, ctx);
        goto after_16;
    // 0x807B6FA4: addiu       $a0, $zero, 0x4013
    ctx->r4 = ADD32(0, 0X4013);
    after_16:
    // 0x807B6FA8: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x807B6FAC: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x807B6FB0: lw          $t1, 0x3EC($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X3EC);
    // 0x807B6FB4: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x807B6FB8: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x807B6FBC: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x807B6FC0: lbu         $v1, 0x598($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X598);
    // 0x807B6FC4: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x807B6FC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B6FCC: beq         $v1, $at, L_807B7024
    if (ctx->r3 == ctx->r1) {
        // 0x807B6FD0: addiu       $at, $zero, 0xA7
        ctx->r1 = ADD32(0, 0XA7);
            goto L_807B7024;
    }
    // 0x807B6FD0: addiu       $at, $zero, 0xA7
    ctx->r1 = ADD32(0, 0XA7);
    // 0x807B6FD4: beq         $v1, $at, L_807B7024
    if (ctx->r3 == ctx->r1) {
        // 0x807B6FD8: addiu       $at, $zero, 0xA8
        ctx->r1 = ADD32(0, 0XA8);
            goto L_807B7024;
    }
    // 0x807B6FD8: addiu       $at, $zero, 0xA8
    ctx->r1 = ADD32(0, 0XA8);
    // 0x807B6FDC: beq         $v1, $at, L_807B7024
    if (ctx->r3 == ctx->r1) {
        // 0x807B6FE0: addiu       $at, $zero, 0xA9
        ctx->r1 = ADD32(0, 0XA9);
            goto L_807B7024;
    }
    // 0x807B6FE0: addiu       $at, $zero, 0xA9
    ctx->r1 = ADD32(0, 0XA9);
    // 0x807B6FE4: beq         $v1, $at, L_807B7024
    if (ctx->r3 == ctx->r1) {
        // 0x807B6FE8: addiu       $at, $zero, 0xA2
        ctx->r1 = ADD32(0, 0XA2);
            goto L_807B7024;
    }
    // 0x807B6FE8: addiu       $at, $zero, 0xA2
    ctx->r1 = ADD32(0, 0XA2);
    // 0x807B6FEC: beq         $v1, $at, L_807B7024
    if (ctx->r3 == ctx->r1) {
        // 0x807B6FF0: addiu       $at, $zero, 0xA4
        ctx->r1 = ADD32(0, 0XA4);
            goto L_807B7024;
    }
    // 0x807B6FF0: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x807B6FF4: beq         $v1, $at, L_807B7024
    if (ctx->r3 == ctx->r1) {
        // 0x807B6FF8: addiu       $at, $zero, 0xA3
        ctx->r1 = ADD32(0, 0XA3);
            goto L_807B7024;
    }
    // 0x807B6FF8: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x807B6FFC: beq         $v1, $at, L_807B7024
    if (ctx->r3 == ctx->r1) {
        // 0x807B7000: addiu       $at, $zero, 0xA5
        ctx->r1 = ADD32(0, 0XA5);
            goto L_807B7024;
    }
    // 0x807B7000: addiu       $at, $zero, 0xA5
    ctx->r1 = ADD32(0, 0XA5);
    // 0x807B7004: beq         $v1, $at, L_807B7024
    if (ctx->r3 == ctx->r1) {
        // 0x807B7008: nop
    
            goto L_807B7024;
    }
    // 0x807B7008: nop

    // 0x807B700C: beq         $v0, $zero, L_807B7024
    if (ctx->r2 == 0) {
        // 0x807B7010: nop
    
            goto L_807B7024;
    }
    // 0x807B7010: nop

    // 0x807B7014: lw          $t3, 0xB20($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XB20);
    // 0x807B7018: bne         $t3, $zero, L_807B7024
    if (ctx->r11 != 0) {
        // 0x807B701C: nop
    
            goto L_807B7024;
    }
    // 0x807B701C: nop

    // 0x807B7020: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
L_807B7024:
    // 0x807B7024: jal         0x8005A994
    // 0x807B7028: lw          $a0, 0x478($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X478);
    func_8005A994(rdram, ctx);
        goto after_17;
    // 0x807B7028: lw          $a0, 0x478($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X478);
    after_17:
    // 0x807B702C: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x807B7030: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x807B7034: lw          $t4, -0x7CE8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7CE8);
    // 0x807B7038: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x807B703C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B7040: swc1        $f12, 0xB0($t4)
    MEM_W(0XB0, ctx->r12) = ctx->f12.u32l;
    // 0x807B7044: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x807B7048: lwc1        $f4, 0xB0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x807B704C: jal         0x8006CA74
    // 0x807B7050: swc1        $f4, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f4.u32l;
    func_8006CA74(rdram, ctx);
        goto after_18;
    // 0x807B7050: swc1        $f4, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f4.u32l;
    after_18:
    // 0x807B7054: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x807B7058: sb          $zero, 0x165($t5)
    MEM_B(0X165, ctx->r13) = 0;
    // 0x807B705C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x807B7060: sb          $zero, 0x165($t6)
    MEM_B(0X165, ctx->r14) = 0;
    // 0x807B7064: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x807B7068: sb          $zero, 0x165($t7)
    MEM_B(0X165, ctx->r15) = 0;
    // 0x807B706C: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x807B7070: sb          $zero, 0x165($t8)
    MEM_B(0X165, ctx->r24) = 0;
    // 0x807B7074: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x807B7078: sb          $zero, 0x165($t9)
    MEM_B(0X165, ctx->r25) = 0;
    // 0x807B707C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x807B7080: beql        $v0, $zero, L_807B7090
    if (ctx->r2 == 0) {
        // 0x807B7084: lw          $v1, 0x1C($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1C);
            goto L_807B7090;
    }
    goto skip_5;
    // 0x807B7084: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    skip_5:
    // 0x807B7088: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    // 0x807B708C: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
L_807B7090:
    // 0x807B7090: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x807B7094: beql        $v1, $zero, L_807B70D4
    if (ctx->r3 == 0) {
        // 0x807B7098: lw          $t2, 0x8($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X8);
            goto L_807B70D4;
    }
    goto skip_6;
    // 0x807B7098: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x807B709C: lw          $v0, -0x76A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X76A8);
    // 0x807B70A0: blez        $v0, L_807B70AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807B70A4: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_807B70AC;
    }
    // 0x807B70A4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x807B70A8: sb          $zero, 0x165($v1)
    MEM_B(0X165, ctx->r3) = 0;
L_807B70AC:
    // 0x807B70AC: bnel        $at, $zero, L_807B70C0
    if (ctx->r1 != 0) {
        // 0x807B70B0: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_807B70C0;
    }
    goto skip_7;
    // 0x807B70B0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    skip_7:
    // 0x807B70B4: lw          $t0, 0x20($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X20);
    // 0x807B70B8: sb          $zero, 0x165($t0)
    MEM_B(0X165, ctx->r8) = 0;
    // 0x807B70BC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_807B70C0:
    // 0x807B70C0: bnel        $at, $zero, L_807B70D4
    if (ctx->r1 != 0) {
        // 0x807B70C4: lw          $t2, 0x8($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X8);
            goto L_807B70D4;
    }
    goto skip_8;
    // 0x807B70C4: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    skip_8:
    // 0x807B70C8: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x807B70CC: sb          $zero, 0x165($t1)
    MEM_B(0X165, ctx->r9) = 0;
    // 0x807B70D0: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
L_807B70D4:
    // 0x807B70D4: sb          $zero, 0x165($t2)
    MEM_B(0X165, ctx->r10) = 0;
    // 0x807B70D8: jal         0x807B67D8
    // 0x807B70DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_807B67D8(rdram, ctx);
        goto after_19;
    // 0x807B70DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_19:
    // 0x807B70E0: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x807B70E4: addiu       $t3, $zero, 0xC0
    ctx->r11 = ADD32(0, 0XC0);
    // 0x807B70E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807B70EC: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x807B70F0: sb          $t3, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r11;
    // 0x807B70F4: jal         0x807B73B0
    // 0x807B70F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_807B73B0(rdram, ctx);
        goto after_20;
    // 0x807B70F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_20:
    // 0x807B70FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807B7100: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807B7104: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807B7108: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807B710C: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x807B7110: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
L_807B7114:
    // 0x807B7114: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x807B7118: lwc1        $f6, 0x30($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X30);
    // 0x807B711C: swc1        $f6, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f6.u32l;
    // 0x807B7120: lw          $t9, 0x478($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X478);
    // 0x807B7124: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x807B7128: lwc1        $f8, 0x34($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X34);
    // 0x807B712C: swc1        $f8, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f8.u32l;
    // 0x807B7130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B7134:
    // 0x807B7134: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B7138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B713C: jr          $ra
    // 0x807B7140: nop

    return;
    // 0x807B7140: nop

;}
RECOMP_FUNC void func_8043BC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043BC50: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8043BC54: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x8043BC58: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x8043BC5C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8043BC60: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8043BC64: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8043BC68: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8043BC6C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8043BC70: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8043BC74: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8043BC78: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8043BC7C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8043BC80: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8043BC84: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8043BC88: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8043BC8C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8043BC90: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x8043BC94: ori         $t3, $t3, 0xACB0
    ctx->r11 = ctx->r11 | 0XACB0;
    // 0x8043BC98: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8043BC9C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8043BCA0: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x8043BCA4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8043BCA8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8043BCAC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8043BCB0: lui         $a3, 0x55
    ctx->r7 = S32(0X55 << 16);
    // 0x8043BCB4: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x8043BCB8: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8043BCBC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8043BCC0: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x8043BCC4: ori         $a3, $a3, 0x3048
    ctx->r7 = ctx->r7 | 0X3048;
    // 0x8043BCC8: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x8043BCCC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8043BCD0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8043BCD4: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8043BCD8: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8043BCDC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8043BCE0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8043BCE4: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x8043BCE8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8043BCEC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8043BCF0: lui         $t0, 0xFFFC
    ctx->r8 = S32(0XFFFC << 16);
    // 0x8043BCF4: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8043BCF8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8043BCFC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8043BD00: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8043BD04: ori         $t0, $t0, 0xF279
    ctx->r8 = ctx->r8 | 0XF279;
    // 0x8043BD08: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8043BD0C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8043BD10: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8043BD14: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8043BD18: lui         $t2, 0xBB00
    ctx->r10 = S32(0XBB00 << 16);
    // 0x8043BD1C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8043BD20: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8043BD24: ori         $t2, $t2, 0x1
    ctx->r10 = ctx->r10 | 0X1;
    // 0x8043BD28: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x8043BD2C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8043BD30: jr          $ra
    // 0x8043BD34: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    return;
    // 0x8043BD34: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
;}
RECOMP_FUNC void gfxprint_locate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F440: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x8007F444: lw          $t9, 0x2C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X2C);
    // 0x8007F448: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8007F44C: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8007F450: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007F454: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8007F458: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    // 0x8007F45C: jr          $ra
    // 0x8007F460: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    return;
    // 0x8007F460: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80699B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699B2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699B34: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80699B38: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80699B3C: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    // 0x80699B40: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80699B44: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80699B48: beq         $v1, $zero, L_80699B5C
    if (ctx->r3 == 0) {
        // 0x80699B4C: lw          $a2, 0x1F4($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X1F4);
            goto L_80699B5C;
    }
    // 0x80699B4C: lw          $a2, 0x1F4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1F4);
    // 0x80699B50: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80699B54: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80699B58: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80699B5C:
    // 0x80699B5C: bne         $v1, $zero, L_80699BAC
    if (ctx->r3 != 0) {
        // 0x80699B60: nop
    
            goto L_80699BAC;
    }
    // 0x80699B60: nop

    // 0x80699B64: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80699B68: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(562, 0X15C8) << 16);
    // 0x80699B6C: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(562, 0X1578) << 16);
    // 0x80699B70: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80699B74: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80699B78: lw          $t7, -0x5568($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(562, 0X15C8));
    // 0x80699B7C: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80699B80: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80699B84: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x80699B88: lw          $t8, -0x55B8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(562, 0X1578));
    // 0x80699B8C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80699B90: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80699B94: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x80699B98: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80699B9C: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x80699BA0: bne         $at, $zero, L_80699BAC
    if (ctx->r1 != 0) {
        // 0x80699BA4: sw          $t1, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r9;
            goto L_80699BAC;
    }
    // 0x80699BA4: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x80699BA8: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_80699BAC:
    // 0x80699BAC: jal         0x80048F84
    // 0x80699BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80699BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80699BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699BBC: jr          $ra
    // 0x80699BC0: nop

    return;
    // 0x80699BC0: nop

;}
RECOMP_FUNC void func_800360A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800360A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800360A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800360A8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800360AC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800360B0: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800360B4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800360B8: jal         0x800356E8
    // 0x800360BC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800356E8(rdram, ctx);
        goto after_0;
    // 0x800360BC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800360C0: addiu       $a0, $sp, 0x47
    ctx->r4 = ADD32(ctx->r29, 0X47);
    // 0x800360C4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800360C8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x800360CC: jal         0x800358B8
    // 0x800360D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800358B8(rdram, ctx);
        goto after_1;
    // 0x800360D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800360D4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800360D8: lbu         $a1, 0x47($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X47);
    // 0x800360DC: jal         0x8002DBE4
    // 0x800360E0: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_2;
    // 0x800360E0: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_2:
    // 0x800360E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800360E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800360EC: jr          $ra
    // 0x800360F0: nop

    return;
    // 0x800360F0: nop

;}
RECOMP_FUNC void func_80032284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032284: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032288: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003228C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032290: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80032294: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80032298: jal         0x80032A8C
    // 0x8003229C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80032A8C(rdram, ctx);
        goto after_0;
    // 0x8003229C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800322A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800322A4: sb          $zero, 0x21($a2)
    MEM_B(0X21, ctx->r6) = 0;
    // 0x800322A8: sb          $zero, 0x154($a2)
    MEM_B(0X154, ctx->r6) = 0;
    // 0x800322AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800322B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800322B4: jr          $ra
    // 0x800322B8: nop

    return;
    // 0x800322B8: nop

;}
RECOMP_FUNC void func_80030BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030BB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80030BB4: lw          $t7, 0x1C0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1C0);
    // 0x80030BB8: lw          $t8, 0x1F4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1F4);
    // 0x80030BBC: jal         0x80030B7C
    // 0x80030BC0: lw          $a1, 0x260($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X260);
    func_80030B7C(rdram, ctx);
        goto after_0;
    // 0x80030BC0: lw          $a1, 0x260($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X260);
    after_0:
    // 0x80030BC4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80030BC8: sb          $zero, 0x1B4($t9)
    MEM_B(0X1B4, ctx->r25) = 0;
    // 0x80030BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030BD4: jr          $ra
    // 0x80030BD8: nop

    return;
    // 0x80030BD8: nop

;}
RECOMP_FUNC void func_806B25BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B25BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B25C0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B25C4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B25C8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B25CC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B25D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B25D4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B25D8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B25DC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B25E0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B25E4: jr          $ra
    // 0x806B25E8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B25E8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806B2A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2A3C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2A40: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2A44: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2A48: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2A4C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2A50: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2A54: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2A58: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2A5C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2A60: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2A64: jr          $ra
    // 0x806B2A68: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2A68: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80716D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716D68: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716D6C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716D70: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716D74: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716D78: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716D7C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716D80: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716D84: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716D88: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716D8C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716D90: jr          $ra
    // 0x80716D94: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716D94: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80798D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798D2C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80798D30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80798D34: jr          $ra
    // 0x80798D38: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x80798D38: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8001C0AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C0AC: jr          $ra
    // 0x8001C0B0: nop

    return;
    // 0x8001C0B0: nop

;}
RECOMP_FUNC void func_80423DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423DB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80423DBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80423DC0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80423DC4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80423DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80423DCC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80423DD0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80423DD4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80423DD8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80423DDC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80423DE0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80423DE4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80423DE8: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(35, 0X31F8) << 16);
    // 0x80423DEC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80423DF0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80423DF4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80423DF8: lw          $t2, 0x5BF8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(35, 0X31F8));
    // 0x80423DFC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80423E00: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80423E04: jal         0x80423044
    // 0x80423E08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80423044(rdram, ctx);
        goto after_0;
    // 0x80423E08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80423E0C: jal         0x804230A0
    // 0x80423E10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804230A0(rdram, ctx);
        goto after_1;
    // 0x80423E10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80423E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80423E18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80423E1C: jr          $ra
    // 0x80423E20: nop

    return;
    // 0x80423E20: nop

;}
RECOMP_FUNC void func_80058098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005809C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800580A0: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800580A4: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x800580A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800580AC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800580B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800580B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800580B8: jal         0x80065728
    // 0x800580BC: sh          $t6, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r14;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x800580BC: sh          $t6, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r14;
    after_0:
    // 0x800580C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800580C4: lh          $t7, 0x1A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1A);
    // 0x800580C8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800580CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800580D0: sh          $t7, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r15;
    // 0x800580D4: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
    // 0x800580D8: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x800580DC: blezl       $t8, L_80058104
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800580E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80058104;
    }
    goto skip_0;
    // 0x800580E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800580E4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800580E8:
    // 0x800580E8: lh          $t9, 0x8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8);
    // 0x800580EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800580F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800580F4: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800580F8: bnel        $at, $zero, L_800580E8
    if (ctx->r1 != 0) {
        // 0x800580FC: sw          $zero, 0x0($v0)
        MEM_W(0X0, ctx->r2) = 0;
            goto L_800580E8;
    }
    goto skip_1;
    // 0x800580FC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    skip_1:
    // 0x80058100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80058104:
    // 0x80058104: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80058108: jr          $ra
    // 0x8005810C: nop

    return;
    // 0x8005810C: nop

;}
RECOMP_FUNC void func_8042FBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FBC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042FBC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FBC8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FBCC: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8042FBD0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8042FBD4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8042FBD8: nop

    // 0x8042FBDC: bc1fl       L_8042FBF0
    if (!c1cs) {
        // 0x8042FBE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042FBF0;
    }
    goto skip_0;
    // 0x8042FBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042FBE4: jal         0x8042FB6C
    // 0x8042FBE8: nop

    func_8042FB6C(rdram, ctx);
        goto after_0;
    // 0x8042FBE8: nop

    after_0:
    // 0x8042FBEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042FBF0:
    // 0x8042FBF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042FBF4: jr          $ra
    // 0x8042FBF8: nop

    return;
    // 0x8042FBF8: nop

;}
RECOMP_FUNC void func_80475630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475630: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475634: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475638: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047563C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475640: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475644: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475648: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047564C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475650: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475654: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475658: jr          $ra
    // 0x8047565C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047565C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804CF608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CF60C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CF610: jal         0x8004700C
    // 0x804CF614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804CF614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CF618: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804CF61C: beq         $v0, $zero, L_804CF6A8
    if (ctx->r2 == 0) {
        // 0x804CF620: lw          $v1, 0x1F4($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X1F4);
            goto L_804CF6A8;
    }
    // 0x804CF620: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x804CF624: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804CF628: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804CF62C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B5C) << 16);
    // 0x804CF630: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804CF634: nop

    // 0x804CF638: bc1f        L_804CF678
    if (!c1cs) {
        // 0x804CF63C: nop
    
            goto L_804CF678;
    }
    // 0x804CF63C: nop

    // 0x804CF640: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B54) << 16);
    // 0x804CF644: lwc1        $f0, -0x1FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B54));
    // 0x804CF648: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B58) << 16);
    // 0x804CF64C: lwc1        $f10, -0x1F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B58));
    // 0x804CF650: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CF654: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804CF658: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
    // 0x804CF65C: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CF660: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x804CF664: nop

    // 0x804CF668: bc1fl       L_804CF6AC
    if (!c1cs) {
        // 0x804CF66C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CF6AC;
    }
    goto skip_0;
    // 0x804CF66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804CF670: b           L_804CF6A8
    // 0x804CF674: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_804CF6A8;
    // 0x804CF674: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
L_804CF678:
    // 0x804CF678: lwc1        $f0, -0x1F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B5C));
    // 0x804CF67C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B60) << 16);
    // 0x804CF680: lwc1        $f6, -0x1F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B60));
    // 0x804CF684: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CF688: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804CF68C: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x804CF690: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CF694: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x804CF698: nop

    // 0x804CF69C: bc1fl       L_804CF6AC
    if (!c1cs) {
        // 0x804CF6A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CF6AC;
    }
    goto skip_1;
    // 0x804CF6A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804CF6A4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
L_804CF6A8:
    // 0x804CF6A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CF6AC:
    // 0x804CF6AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CF6B0: jr          $ra
    // 0x804CF6B4: nop

    return;
    // 0x804CF6B4: nop

;}
RECOMP_FUNC void func_80699FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699FC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699FCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699FD0: jal         0x80699C60
    // 0x80699FD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80699C60(rdram, ctx);
        goto after_0;
    // 0x80699FD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80699FD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80699FDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80699FE0: jal         0x8069A0F0
    // 0x80699FE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8069A0F0(rdram, ctx);
        goto after_1;
    // 0x80699FE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80699FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699FEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699FF0: jr          $ra
    // 0x80699FF4: nop

    return;
    // 0x80699FF4: nop

;}
RECOMP_FUNC void func_80427118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042711C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80427120: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80427124: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80427128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042712C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80427130: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80427134: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80427138: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042713C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80427140: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(38, 0X11F8) << 16);
    // 0x80427144: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80427148: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8042714C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80427150: lw          $t2, 0x77F8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(38, 0X11F8));
    // 0x80427154: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80427158: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8042715C: jal         0x80426AE0
    // 0x80427160: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80426AE0(rdram, ctx);
        goto after_0;
    // 0x80427160: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80427164: jal         0x80426B3C
    // 0x80427168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80426B3C(rdram, ctx);
        goto after_1;
    // 0x80427168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8042716C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80427170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80427174: jr          $ra
    // 0x80427178: nop

    return;
    // 0x80427178: nop

    // 0x8042717C: nop

;}
RECOMP_FUNC void func_8051731C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051731C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80517320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517324: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80517328: lui         $t8, 0x8051
    ctx->r24 = S32(RELOC_HI16(285, 0X398) << 16);
    // 0x8051732C: addiu       $t8, $t8, 0x74A8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(285, 0X398));
    // 0x80517330: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80517334: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80517338: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8051733C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80517340: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80517344: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80517348: beql        $v1, $zero, L_8051737C
    if (ctx->r3 == 0) {
        // 0x8051734C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8051737C;
    }
    goto skip_0;
    // 0x8051734C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80517350: jalr        $v1
    // 0x80517354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80517354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80517358: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051735C: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x80517360: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x80517364: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80517368: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8051736C: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80517370: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80517374: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x80517378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051737C:
    // 0x8051737C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80517380: jr          $ra
    // 0x80517384: nop

    return;
    // 0x80517384: nop

;}
RECOMP_FUNC void func_8005EFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EFE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005EFEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005EFF0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005EFF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005EFF8: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x8005EFFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005F000: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8005F004: bne         $t6, $zero, L_8005F040
    if (ctx->r14 != 0) {
        // 0x8005F008: nop
    
            goto L_8005F040;
    }
    // 0x8005F008: nop

    // 0x8005F00C: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x8005F010: addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    // 0x8005F014: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x8005F018: lw          $t8, 0x14($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X14);
    // 0x8005F01C: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8005F020: jal         0x800734F0
    // 0x8005F024: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
    func_800734F0(rdram, ctx);
        goto after_0;
    // 0x8005F024: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
    after_0:
    // 0x8005F028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F02C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005F030: jal         0x800735A4
    // 0x8005F034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800735A4(rdram, ctx);
        goto after_1;
    // 0x8005F034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8005F038: b           L_8005F0DC
    // 0x8005F03C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8005F0DC;
    // 0x8005F03C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8005F040:
    // 0x8005F040: jal         0x80081FE0
    // 0x8005F044: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    floorf_recomp(rdram, ctx);
        goto after_2;
    // 0x8005F044: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    after_2:
    // 0x8005F048: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005F04C: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8005F050: nop

    // 0x8005F054: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
    // 0x8005F058: jal         0x80081FE0
    // 0x8005F05C: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    floorf_recomp(rdram, ctx);
        goto after_3;
    // 0x8005F05C: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    after_3:
    // 0x8005F060: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8005F064: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8005F068: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005F06C: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8005F070: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005F074: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8005F078: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8005F07C: nop

    // 0x8005F080: sw          $t2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r10;
    // 0x8005F084: jal         0x80081FE0
    // 0x8005F088: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    floorf_recomp(rdram, ctx);
        goto after_4;
    // 0x8005F088: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    after_4:
    // 0x8005F08C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005F090: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8005F094: nop

    // 0x8005F098: sw          $t4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r12;
    // 0x8005F09C: jal         0x80081FE0
    // 0x8005F0A0: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    floorf_recomp(rdram, ctx);
        goto after_5;
    // 0x8005F0A0: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    after_5:
    // 0x8005F0A4: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005F0A8: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8005F0AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005F0B0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8005F0B4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005F0B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F0BC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005F0C0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8005F0C4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005F0C8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8005F0CC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8005F0D0: jal         0x800735EC
    // 0x8005F0D4: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    func_800735EC(rdram, ctx);
        goto after_6;
    // 0x8005F0D4: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    after_6:
    // 0x8005F0D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8005F0DC:
    // 0x8005F0DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005F0E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005F0E4: jr          $ra
    // 0x8005F0E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005F0E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_807AFB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AFB60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AFB64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AFB68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807AFB6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AFB70: jal         0x80051194
    // 0x807AFB74: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x807AFB74: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x807AFB78: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x807AFB7C: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(871, 0X35C4) << 16);
    // 0x807AFB80: lw          $t6, 0x3114($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(871, 0X35C4));
    // 0x807AFB84: bnel        $t6, $zero, L_807AFBAC
    if (ctx->r14 != 0) {
        // 0x807AFB88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807AFBAC;
    }
    goto skip_0;
    // 0x807AFB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x807AFB8C: jal         0x80064D1C
    // 0x807AFB90: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x807AFB90: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_1:
    // 0x807AFB94: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X35C4) << 16);
    // 0x807AFB98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807AFB9C: sw          $v0, 0x3114($at)
    MEM_W((int16_t)RELOC_LO16(871, 0X35C4), ctx->r1) = ctx->r2;
    // 0x807AFBA0: jal         0x800664B0
    // 0x807AFBA4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800664B0(rdram, ctx);
        goto after_2;
    // 0x807AFBA4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x807AFBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_807AFBAC:
    // 0x807AFBAC: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x807AFBB0: jal         0x807B0D14
    // 0x807AFBB4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_807B0D14(rdram, ctx);
        goto after_3;
    // 0x807AFBB4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_3:
    // 0x807AFBB8: lw          $a2, 0x1F4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AFBBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807AFBC0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x807AFBC4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x807AFBC8: addiu       $v1, $a2, 0x6C
    ctx->r3 = ADD32(ctx->r6, 0X6C);
    // 0x807AFBCC: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x807AFBD0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807AFBD4: beq         $a0, $a1, L_807AFCD8
    if (ctx->r4 == ctx->r5) {
        // 0x807AFBD8: lh          $t8, 0x0($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X0);
            goto L_807AFCD8;
    }
    // 0x807AFBD8: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
L_807AFBDC:
    // 0x807AFBDC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x807AFBE0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807AFBE4: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x807AFBE8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFBEC: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x807AFBF0: swc1        $f18, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->f18.u32l;
    // 0x807AFBF4: lh          $t9, -0x16($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X16);
    // 0x807AFBF8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x807AFBFC: nop

    // 0x807AFC00: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFC04: swc1        $f18, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->f18.u32l;
    // 0x807AFC08: lh          $t0, -0x14($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X14);
    // 0x807AFC0C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x807AFC10: nop

    // 0x807AFC14: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFC18: swc1        $f18, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = ctx->f18.u32l;
    // 0x807AFC1C: lh          $t1, -0x12($v0)
    ctx->r9 = MEM_H(ctx->r2, -0X12);
    // 0x807AFC20: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x807AFC24: nop

    // 0x807AFC28: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFC2C: swc1        $f18, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = ctx->f18.u32l;
    // 0x807AFC30: lh          $t2, -0x10($v0)
    ctx->r10 = MEM_H(ctx->r2, -0X10);
    // 0x807AFC34: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x807AFC38: nop

    // 0x807AFC3C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFC40: swc1        $f18, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->f18.u32l;
    // 0x807AFC44: lh          $t3, -0xE($v0)
    ctx->r11 = MEM_H(ctx->r2, -0XE);
    // 0x807AFC48: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x807AFC4C: nop

    // 0x807AFC50: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFC54: swc1        $f18, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x807AFC58: lh          $t4, -0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, -0XC);
    // 0x807AFC5C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x807AFC60: nop

    // 0x807AFC64: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFC68: swc1        $f18, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->f18.u32l;
    // 0x807AFC6C: lh          $t5, -0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, -0XA);
    // 0x807AFC70: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x807AFC74: nop

    // 0x807AFC78: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFC7C: swc1        $f18, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->f18.u32l;
    // 0x807AFC80: lh          $t6, -0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, -0X8);
    // 0x807AFC84: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x807AFC88: nop

    // 0x807AFC8C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFC90: swc1        $f18, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f18.u32l;
    // 0x807AFC94: lh          $t7, -0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X6);
    // 0x807AFC98: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x807AFC9C: nop

    // 0x807AFCA0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFCA4: swc1        $f18, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f18.u32l;
    // 0x807AFCA8: lh          $t8, -0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X4);
    // 0x807AFCAC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x807AFCB0: nop

    // 0x807AFCB4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFCB8: swc1        $f18, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f18.u32l;
    // 0x807AFCBC: lh          $t9, -0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X2);
    // 0x807AFCC0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x807AFCC4: nop

    // 0x807AFCC8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFCCC: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x807AFCD0: bne         $a0, $a1, L_807AFBDC
    if (ctx->r4 != ctx->r5) {
        // 0x807AFCD4: lh          $t8, 0x0($v0)
        ctx->r24 = MEM_H(ctx->r2, 0X0);
            goto L_807AFBDC;
    }
    // 0x807AFCD4: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
L_807AFCD8:
    // 0x807AFCD8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x807AFCDC: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x807AFCE0: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x807AFCE4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFCE8: swc1        $f18, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = ctx->f18.u32l;
    // 0x807AFCEC: lh          $t9, -0x16($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X16);
    // 0x807AFCF0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x807AFCF4: nop

    // 0x807AFCF8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFCFC: swc1        $f18, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->f18.u32l;
    // 0x807AFD00: lh          $t0, -0x14($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X14);
    // 0x807AFD04: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x807AFD08: nop

    // 0x807AFD0C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFD10: swc1        $f18, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = ctx->f18.u32l;
    // 0x807AFD14: lh          $t1, -0x12($v0)
    ctx->r9 = MEM_H(ctx->r2, -0X12);
    // 0x807AFD18: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x807AFD1C: nop

    // 0x807AFD20: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFD24: swc1        $f18, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = ctx->f18.u32l;
    // 0x807AFD28: lh          $t2, -0x10($v0)
    ctx->r10 = MEM_H(ctx->r2, -0X10);
    // 0x807AFD2C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x807AFD30: nop

    // 0x807AFD34: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFD38: swc1        $f18, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->f18.u32l;
    // 0x807AFD3C: lh          $t3, -0xE($v0)
    ctx->r11 = MEM_H(ctx->r2, -0XE);
    // 0x807AFD40: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x807AFD44: nop

    // 0x807AFD48: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFD4C: swc1        $f18, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x807AFD50: lh          $t4, -0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, -0XC);
    // 0x807AFD54: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x807AFD58: nop

    // 0x807AFD5C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFD60: swc1        $f18, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->f18.u32l;
    // 0x807AFD64: lh          $t5, -0xA($v0)
    ctx->r13 = MEM_H(ctx->r2, -0XA);
    // 0x807AFD68: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x807AFD6C: nop

    // 0x807AFD70: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFD74: swc1        $f18, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->f18.u32l;
    // 0x807AFD78: lh          $t6, -0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, -0X8);
    // 0x807AFD7C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x807AFD80: nop

    // 0x807AFD84: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFD88: swc1        $f18, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f18.u32l;
    // 0x807AFD8C: lh          $t7, -0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X6);
    // 0x807AFD90: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x807AFD94: nop

    // 0x807AFD98: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFD9C: swc1        $f18, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f18.u32l;
    // 0x807AFDA0: lh          $t8, -0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X4);
    // 0x807AFDA4: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x807AFDA8: nop

    // 0x807AFDAC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFDB0: swc1        $f18, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f18.u32l;
    // 0x807AFDB4: lh          $t9, -0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X2);
    // 0x807AFDB8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x807AFDBC: nop

    // 0x807AFDC0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807AFDC4: swc1        $f18, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f18.u32l;
    // 0x807AFDC8: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AFDCC: lui         $t0, 0x807B
    ctx->r8 = S32(RELOC_HI16(871, 0X35B0) << 16);
    // 0x807AFDD0: addiu       $t0, $t0, 0x3100
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(871, 0X35B0));
    // 0x807AFDD4: sw          $t0, 0x140($t1)
    MEM_W(0X140, ctx->r9) = ctx->r8;
    // 0x807AFDD8: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AFDDC: lui         $t2, 0x807B
    ctx->r10 = S32(RELOC_HI16(871, 0X35C4) << 16);
    // 0x807AFDE0: addiu       $t2, $t2, 0x3114
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(871, 0X35C4));
    // 0x807AFDE4: sw          $t2, 0x138($t3)
    MEM_W(0X138, ctx->r11) = ctx->r10;
    // 0x807AFDE8: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AFDEC: lui         $t4, 0x807B
    ctx->r12 = S32(RELOC_HI16(871, 0X35C8) << 16);
    // 0x807AFDF0: addiu       $t4, $t4, 0x3118
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(871, 0X35C8));
    // 0x807AFDF4: sw          $t4, 0x13C($t5)
    MEM_W(0X13C, ctx->r13) = ctx->r12;
    // 0x807AFDF8: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AFDFC: lw          $v0, 0x13C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X13C);
    // 0x807AFE00: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x807AFE04: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x807AFE08: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x807AFE0C: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AFE10: sw          $zero, 0x170($t9)
    MEM_W(0X170, ctx->r25) = 0;
    // 0x807AFE14: lw          $a2, 0x1F4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AFE18: lw          $t0, 0x170($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X170);
    // 0x807AFE1C: sw          $t0, 0x174($a2)
    MEM_W(0X174, ctx->r6) = ctx->r8;
    // 0x807AFE20: lw          $a2, 0x1F4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F4);
    // 0x807AFE24: addiu       $a0, $a2, 0x178
    ctx->r4 = ADD32(ctx->r6, 0X178);
    // 0x807AFE28: jal         0x807B2B4C
    // 0x807AFE2C: addiu       $a1, $a2, 0x388
    ctx->r5 = ADD32(ctx->r6, 0X388);
    func_807B2B4C(rdram, ctx);
        goto after_4;
    // 0x807AFE2C: addiu       $a1, $a2, 0x388
    ctx->r5 = ADD32(ctx->r6, 0X388);
    after_4:
    // 0x807AFE30: jal         0x807B07B0
    // 0x807AFE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B07B0(rdram, ctx);
        goto after_5;
    // 0x807AFE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807AFE38: lw          $t4, 0x16C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X16C);
    // 0x807AFE3C: lui         $t1, 0x807B
    ctx->r9 = S32(RELOC_HI16(871, 0X7E8) << 16);
    // 0x807AFE40: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x807AFE44: addiu       $t1, $t1, 0x338
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(871, 0X7E8));
    // 0x807AFE48: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x807AFE4C: lui         $t3, 0x807B
    ctx->r11 = S32(RELOC_HI16(871, 0X35C0) << 16);
    // 0x807AFE50: sw          $t1, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r9;
    // 0x807AFE54: sw          $t2, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r10;
    // 0x807AFE58: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x807AFE5C: addiu       $t3, $t3, 0x3110
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(871, 0X35C0));
    // 0x807AFE60: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x807AFE64: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807AFE68: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x807AFE6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807AFE70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AFE74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x807AFE78: jal         0x807B2D04
    // 0x807AFE7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B2D04(rdram, ctx);
        goto after_6;
    // 0x807AFE7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x807AFE80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807AFE84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AFE88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AFE8C: jr          $ra
    // 0x807AFE90: nop

    return;
    // 0x807AFE90: nop

;}
RECOMP_FUNC void func_8005EBB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EBB8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005EBBC: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8005EBC0: jr          $ra
    // 0x8005EBC4: sb          $t6, 0x38($t7)
    MEM_B(0X38, ctx->r15) = ctx->r14;
    return;
    // 0x8005EBC4: sb          $t6, 0x38($t7)
    MEM_B(0X38, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_80426BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426BE4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80426BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80426BEC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80426BF0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80426BF4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80426BF8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80426BFC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80426C00: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80426C04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80426C08: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80426C0C: lw          $t9, 0x20($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X20);
    // 0x80426C10: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80426C14: jal         0x80077338
    // 0x80426C18: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x80426C18: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    after_0:
    // 0x80426C1C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80426C20: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80426C24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80426C28: jal         0x8007711C
    // 0x80426C2C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x80426C2C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_1:
    // 0x80426C30: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80426C34: lui         $t4, 0xFD50
    ctx->r12 = S32(0XFD50 << 16);
    // 0x80426C38: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x80426C3C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80426C40: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80426C44: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80426C48: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80426C4C: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x80426C50: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x80426C54: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x80426C58: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80426C5C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80426C60: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80426C64: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80426C68: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80426C6C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80426C70: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80426C74: lui         $t8, 0x73E
    ctx->r24 = S32(0X73E << 16);
    // 0x80426C78: ori         $t8, $t8, 0xF156
    ctx->r24 = ctx->r24 | 0XF156;
    // 0x80426C7C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80426C80: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80426C84: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80426C88: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80426C8C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80426C90: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x80426C94: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80426C98: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80426C9C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80426CA0: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80426CA4: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80426CA8: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80426CAC: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80426CB0: ori         $t6, $t6, 0xC00
    ctx->r14 = ctx->r14 | 0XC00;
    // 0x80426CB4: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80426CB8: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x80426CBC: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80426CC0: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80426CC4: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80426CC8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80426CCC: lui         $t2, 0xB
    ctx->r10 = S32(0XB << 16);
    // 0x80426CD0: ori         $t2, $t2, 0xC0A4
    ctx->r10 = ctx->r10 | 0XC0A4;
    // 0x80426CD4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80426CD8: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x80426CDC: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80426CE0: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80426CE4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80426CE8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80426CEC: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x80426CF0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80426CF4: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80426CF8: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x80426CFC: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80426D00: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80426D04: ori         $t5, $t5, 0x289F
    ctx->r13 = ctx->r13 | 0X289F;
    // 0x80426D08: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(38, 0X10B0) << 16);
    // 0x80426D0C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80426D10: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80426D14: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x80426D18: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80426D1C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80426D20: addiu       $t8, $t8, 0x76B0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(38, 0X10B0));
    // 0x80426D24: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x80426D28: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80426D2C: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80426D30: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80426D34: sw          $t0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r8;
    // 0x80426D38: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80426D3C: ori         $t3, $t3, 0x38DF
    ctx->r11 = ctx->r11 | 0X38DF;
    // 0x80426D40: addiu       $t4, $t1, 0x80
    ctx->r12 = ADD32(ctx->r9, 0X80);
    // 0x80426D44: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80426D48: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x80426D4C: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x80426D50: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x80426D54: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80426D58: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(38, 0X10F8) << 16);
    // 0x80426D5C: addiu       $t7, $t7, 0x76F8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(38, 0X10F8));
    // 0x80426D60: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80426D64: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80426D68: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80426D6C: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x80426D70: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80426D74: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80426D78: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80426D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80426D80: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80426D84: jr          $ra
    // 0x80426D88: nop

    return;
    // 0x80426D88: nop

;}
RECOMP_FUNC void func_804BACF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BACF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BACF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BACFC: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x804BAD00: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804BAD04: slti        $at, $t7, 0xF
    ctx->r1 = SIGNED(ctx->r15) < 0XF ? 1 : 0;
    // 0x804BAD08: bne         $at, $zero, L_804BAD34
    if (ctx->r1 != 0) {
        // 0x804BAD0C: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_804BAD34;
    }
    // 0x804BAD0C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x804BAD10: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804BAD14: jal         0x800653D8
    // 0x804BAD18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x804BAD18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BAD1C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x804BAD20: bne         $t9, $zero, L_804BAD34
    if (ctx->r25 != 0) {
        // 0x804BAD24: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804BAD34;
    }
    // 0x804BAD24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BAD28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BAD2C: jal         0x804BB4C4
    // 0x804BAD30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804BB4C4(rdram, ctx);
        goto after_1;
    // 0x804BAD30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_804BAD34:
    // 0x804BAD34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BAD38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BAD3C: jr          $ra
    // 0x804BAD40: nop

    return;
    // 0x804BAD40: nop

;}
RECOMP_FUNC void func_80517CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517CA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80517CAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517CB0: lh          $a3, 0x1F0($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X1F0);
    // 0x80517CB4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80517CB8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80517CBC: bne         $a3, $at, L_80517D28
    if (ctx->r7 != ctx->r1) {
        // 0x80517CC0: sll         $a1, $a3, 16
        ctx->r5 = S32(ctx->r7 << 16);
            goto L_80517D28;
    }
    // 0x80517CC0: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x80517CC4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80517CC8: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80517CCC: jal         0x80067BBC
    // 0x80517CD0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80517CD0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80517CD4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x80517CD8: jal         0x80067F78
    // 0x80517CDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80517CDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80517CE0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80517CE4: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80517CE8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80517CEC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80517CF0: beq         $v0, $at, L_80517D70
    if (ctx->r2 == ctx->r1) {
        // 0x80517CF4: sh          $v0, 0x1F0($a2)
        MEM_H(0X1F0, ctx->r6) = ctx->r2;
            goto L_80517D70;
    }
    // 0x80517CF4: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
    // 0x80517CF8: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x80517CFC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80517D00: jal         0x80067BBC
    // 0x80517D04: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80517D04: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_2:
    // 0x80517D08: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x80517D0C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x80517D10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80517D14: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x80517D18: jal         0x80067838
    // 0x80517D1C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x80517D1C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x80517D20: b           L_80517D74
    // 0x80517D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80517D74;
    // 0x80517D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80517D28:
    // 0x80517D28: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x80517D2C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80517D30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80517D34: jal         0x80067930
    // 0x80517D38: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_4;
    // 0x80517D38: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_4:
    // 0x80517D3C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80517D40: beq         $v0, $zero, L_80517D70
    if (ctx->r2 == 0) {
        // 0x80517D44: lh          $a3, 0x1E($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X1E);
            goto L_80517D70;
    }
    // 0x80517D44: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x80517D48: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x80517D4C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80517D50: jal         0x80067BBC
    // 0x80517D54: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x80517D54: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_5:
    // 0x80517D58: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x80517D5C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x80517D60: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80517D64: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x80517D68: jal         0x800678F0
    // 0x80517D6C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x80517D6C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_6:
L_80517D70:
    // 0x80517D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80517D74:
    // 0x80517D74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80517D78: jr          $ra
    // 0x80517D7C: nop

    return;
    // 0x80517D7C: nop

;}
RECOMP_FUNC void func_804EEF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EEF8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804EEF90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EEF94: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804EEF98: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804EEF9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804EEFA0: jal         0x800653D8
    // 0x804EEFA4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x804EEFA4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x804EEFA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804EEFAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804EEFB0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x804EEFB4: bgez        $v0, L_804EEFC8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x804EEFB8: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_804EEFC8;
    }
    // 0x804EEFB8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x804EEFBC: beq         $t6, $zero, L_804EEFC8
    if (ctx->r14 == 0) {
        // 0x804EEFC0: nop
    
            goto L_804EEFC8;
    }
    // 0x804EEFC0: nop

    // 0x804EEFC4: addiu       $t6, $t6, -0x2
    ctx->r14 = ADD32(ctx->r14, -0X2);
L_804EEFC8:
    // 0x804EEFC8: bne         $t6, $at, L_804EEFF4
    if (ctx->r14 != ctx->r1) {
        // 0x804EEFCC: addiu       $v0, $a0, 0xC4
        ctx->r2 = ADD32(ctx->r4, 0XC4);
            goto L_804EEFF4;
    }
    // 0x804EEFCC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804EEFD0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804EEFD4: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(267, 0X1184) << 16);
    // 0x804EEFD8: lwc1        $f6, -0xEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(267, 0X1184));
    // 0x804EEFDC: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x804EEFE0: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x804EEFE4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804EEFE8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x804EEFEC: b           L_804EF010
    // 0x804EEFF0: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
        goto L_804EF010;
    // 0x804EEFF0: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
L_804EEFF4:
    // 0x804EEFF4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804EEFF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804EEFFC: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x804EF000: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x804EF004: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804EF008: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x804EF00C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_804EF010:
    // 0x804EF010: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x804EF014: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x804EF018: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x804EF01C: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804EF020: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804EF024: jal         0x80067114
    // 0x804EF028: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80067114(rdram, ctx);
        goto after_1;
    // 0x804EF028: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x804EF02C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x804EF030: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804EF034: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804EF038: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x804EF03C: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x804EF040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF044: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804EF048: jr          $ra
    // 0x804EF04C: nop

    return;
    // 0x804EF04C: nop

;}
RECOMP_FUNC void func_804BDD78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BDD78: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804BDD7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BDD80: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x804BDD84: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41BC) << 16);
    // 0x804BDD88: lwc1        $f4, -0x514($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41BC));
    // 0x804BDD8C: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x804BDD90: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BDD94: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804BDD98: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804BDD9C: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BDDA0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41C0) << 16);
    // 0x804BDDA4: bc1t        L_804BDF28
    if (c1cs) {
        // 0x804BDDA8: lw          $a3, 0x370($t7)
        ctx->r7 = MEM_W(ctx->r15, 0X370);
            goto L_804BDF28;
    }
    // 0x804BDDA8: lw          $a3, 0x370($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X370);
    // 0x804BDDAC: lwc1        $f6, -0x510($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41C0));
    // 0x804BDDB0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804BDDB4: nop

    // 0x804BDDB8: bc1tl       L_804BDF2C
    if (c1cs) {
        // 0x804BDDBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BDF2C;
    }
    goto skip_0;
    // 0x804BDDBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BDDC0: lh          $t8, 0x2E($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2E);
    // 0x804BDDC4: lui         $t0, 0x804C
    ctx->r8 = S32(RELOC_HI16(191, 0X3DB0) << 16);
    // 0x804BDDC8: lui         $t4, 0x804C
    ctx->r12 = S32(RELOC_HI16(191, 0X2608) << 16);
    // 0x804BDDCC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x804BDDD0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804BDDD4: lh          $t0, -0x920($t0)
    ctx->r8 = MEM_H(ctx->r8, (int16_t)RELOC_LO16(191, 0X3DB0));
    // 0x804BDDD8: addiu       $t4, $t4, -0x20C8
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(191, 0X2608));
    // 0x804BDDDC: sh          $t0, 0x144($a3)
    MEM_H(0X144, ctx->r7) = ctx->r8;
    // 0x804BDDE0: lh          $t1, 0x2E($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2E);
    // 0x804BDDE4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x804BDDE8: sh          $t2, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r10;
    // 0x804BDDEC: lh          $t3, 0x2E($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2E);
    // 0x804BDDF0: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x804BDDF4: bne         $at, $zero, L_804BDF18
    if (ctx->r1 != 0) {
        // 0x804BDDF8: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_804BDF18;
    }
    // 0x804BDDF8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x804BDDFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804BDE00: sw          $t4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r12;
    // 0x804BDE04: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804BDE08: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x804BDE0C: jal         0x80047AB8
    // 0x804BDE10: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x804BDE10: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x804BDE14: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x804BDE18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BDE1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804BDE20: lwc1        $f10, 0x6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x804BDE24: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x804BDE28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BDE2C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x804BDE30: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x804BDE34: lwc1        $f16, 0x70($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X70);
    // 0x804BDE38: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x804BDE3C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804BDE40: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x804BDE44: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x804BDE48: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x804BDE4C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804BDE50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804BDE54: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41C4) << 16);
    // 0x804BDE58: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x804BDE5C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804BDE60: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x804BDE64: lwc1        $f18, -0x50C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41C4));
    // 0x804BDE68: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x804BDE6C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x804BDE70: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x804BDE74: lw          $t5, -0x76F8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X76F8);
    // 0x804BDE78: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x804BDE7C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x804BDE80: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x804BDE84: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804BDE88: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x804BDE8C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x804BDE90: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x804BDE94: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x804BDE98: jalr        $t9
    // 0x804BDE9C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x804BDE9C: nop

    after_1:
    // 0x804BDEA0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41C8) << 16);
    // 0x804BDEA4: lwc1        $f6, -0x508($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41C8));
    // 0x804BDEA8: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x804BDEAC: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x804BDEB0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x804BDEB4: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x804BDEB8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x804BDEBC: jal         0x804BDC70
    // 0x804BDEC0: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    func_804BDC70(rdram, ctx);
        goto after_2;
    // 0x804BDEC0: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x804BDEC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804BDEC8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x804BDECC: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x804BDED0: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x804BDED4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x804BDED8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x804BDEDC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x804BDEE0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x804BDEE4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x804BDEE8: jalr        $t9
    // 0x804BDEEC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804BDEEC: nop

    after_3:
    // 0x804BDEF0: beql        $v0, $zero, L_804BDF2C
    if (ctx->r2 == 0) {
        // 0x804BDEF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BDF2C;
    }
    goto skip_1;
    // 0x804BDEF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804BDEF8: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    // 0x804BDEFC: jal         0x80067BBC
    // 0x804BDF00: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x804BDF00: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    after_4:
    // 0x804BDF04: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x804BDF08: jal         0x80067818
    // 0x804BDF0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x804BDF0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x804BDF10: b           L_804BDF2C
    // 0x804BDF14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804BDF2C;
    // 0x804BDF14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BDF18:
    // 0x804BDF18: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804BDF1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804BDF20: nop

    // 0x804BDF24: swc1        $f18, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->f18.u32l;
L_804BDF28:
    // 0x804BDF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BDF2C:
    // 0x804BDF2C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x804BDF30: jr          $ra
    // 0x804BDF34: nop

    return;
    // 0x804BDF34: nop

;}
RECOMP_FUNC void func_8042D564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042D564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042D568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042D56C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042D570: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8042D574: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042D578: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(50, 0X2EE0) << 16);
    // 0x8042D57C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042D580: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8042D584: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042D588: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042D58C: lw          $t8, -0x2880($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(50, 0X2EE0));
    // 0x8042D590: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042D594: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042D598: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042D59C: jal         0x80048490
    // 0x8042D5A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8042D5A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8042D5A4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042D5A8: jal         0x80048378
    // 0x8042D5AC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8042D5AC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8042D5B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042D5B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042D5B8: jr          $ra
    // 0x8042D5BC: nop

    return;
    // 0x8042D5BC: nop

;}
RECOMP_FUNC void func_805A69E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A69E0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x805A69E4: addiu       $at, $zero, 0x40B8
    ctx->r1 = ADD32(0, 0X40B8);
    // 0x805A69E8: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(420, 0X344) << 16);
    // 0x805A69EC: beq         $v0, $at, L_805A6A08
    if (ctx->r2 == ctx->r1) {
        // 0x805A69F0: addiu       $t6, $t6, 0x6D24
        ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(420, 0X344));
            goto L_805A6A08;
    }
    // 0x805A69F0: addiu       $t6, $t6, 0x6D24
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(420, 0X344));
    // 0x805A69F4: addiu       $at, $zero, 0x466A
    ctx->r1 = ADD32(0, 0X466A);
    // 0x805A69F8: beq         $v0, $at, L_805A6A1C
    if (ctx->r2 == ctx->r1) {
        // 0x805A69FC: nop
    
            goto L_805A6A1C;
    }
    // 0x805A69FC: nop

    // 0x805A6A00: b           L_805A6A28
    // 0x805A6A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A6A28;
    // 0x805A6A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A6A08:
    // 0x805A6A08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805A6A0C: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(420, 0X2AC) << 16);
    // 0x805A6A10: sw          $t6, -0x72AC($at)
    MEM_W(-0X72AC, ctx->r1) = ctx->r14;
    // 0x805A6A14: jr          $ra
    // 0x805A6A18: addiu       $v0, $v0, 0x6C8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(420, 0X2AC));
    return;
    // 0x805A6A18: addiu       $v0, $v0, 0x6C8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(420, 0X2AC));
L_805A6A1C:
    // 0x805A6A1C: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(420, 0X2AC) << 16);
    // 0x805A6A20: jr          $ra
    // 0x805A6A24: addiu       $v0, $v0, 0x6C8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(420, 0X2AC));
    return;
    // 0x805A6A24: addiu       $v0, $v0, 0x6C8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(420, 0X2AC));
L_805A6A28:
    // 0x805A6A28: jr          $ra
    // 0x805A6A2C: nop

    return;
    // 0x805A6A2C: nop

;}
RECOMP_FUNC void func_80007B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007B80: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80007B84: jr          $ra
    // 0x80007B88: sw          $a0, 0x7E74($at)
    MEM_W(0X7E74, ctx->r1) = ctx->r4;
    return;
    // 0x80007B88: sw          $a0, 0x7E74($at)
    MEM_W(0X7E74, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8045F870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045F874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045F878: jal         0x8045F450
    // 0x8045F87C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8045F450(rdram, ctx);
        goto after_0;
    // 0x8045F87C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045F880: jal         0x8045F55C
    // 0x8045F884: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8045F55C(rdram, ctx);
        goto after_1;
    // 0x8045F884: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8045F888: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8045F88C: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x8045F890: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8045F894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045F898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045F89C: jr          $ra
    // 0x8045F8A0: nop

    return;
    // 0x8045F8A0: nop

;}
RECOMP_FUNC void func_80433634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80433638: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8043363C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80433640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80433644: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80433648: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8043364C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80433650: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80433654: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80433658: lui         $t1, 0x8043
    ctx->r9 = S32(RELOC_HI16(65, 0X920) << 16);
    // 0x8043365C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80433660: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80433664: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80433668: lw          $t1, 0x3700($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(65, 0X920));
    // 0x8043366C: jal         0x80433684
    // 0x80433670: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_80433684(rdram, ctx);
        goto after_0;
    // 0x80433670: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x80433674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80433678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043367C: jr          $ra
    // 0x80433680: nop

    return;
    // 0x80433680: nop

;}
RECOMP_FUNC void func_804619EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804619EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804619F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804619F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804619F8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804619FC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80461A00: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(122, 0X36FC) << 16);
    // 0x80461A04: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80461A08: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80461A0C: addiu       $t7, $t7, 0x3C8C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(122, 0X36FC));
    // 0x80461A10: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80461A14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80461A18: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80461A1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80461A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80461A24: jal         0x80461ACC
    // 0x80461A28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80461ACC(rdram, ctx);
        goto after_0;
    // 0x80461A28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80461A2C: jal         0x80461914
    // 0x80461A30: nop

    func_80461914(rdram, ctx);
        goto after_1;
    // 0x80461A30: nop

    after_1:
    // 0x80461A34: bne         $v0, $zero, L_80461A58
    if (ctx->r2 != 0) {
        // 0x80461A38: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_80461A58;
    }
    // 0x80461A38: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80461A3C: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    // 0x80461A40: beq         $t9, $zero, L_80461A50
    if (ctx->r25 == 0) {
        // 0x80461A44: nop
    
            goto L_80461A50;
    }
    // 0x80461A44: nop

    // 0x80461A48: jal         0x800445A4
    // 0x80461A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80461A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80461A50:
    // 0x80461A50: b           L_80461AB8
    // 0x80461A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80461AB8;
    // 0x80461A54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80461A58:
    // 0x80461A58: jal         0x80461934
    // 0x80461A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80461934(rdram, ctx);
        goto after_3;
    // 0x80461A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80461A60: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x80461A64: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x80461A68: sw          $t0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r8;
    // 0x80461A6C: jal         0x804618C8
    // 0x80461A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804618C8(rdram, ctx);
        goto after_4;
    // 0x80461A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80461A74: bne         $v0, $zero, L_80461A98
    if (ctx->r2 != 0) {
        // 0x80461A78: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80461A98;
    }
    // 0x80461A78: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80461A7C: lw          $t1, 0x180($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X180);
    // 0x80461A80: beq         $t1, $zero, L_80461A90
    if (ctx->r9 == 0) {
        // 0x80461A84: nop
    
            goto L_80461A90;
    }
    // 0x80461A84: nop

    // 0x80461A88: jal         0x800445A4
    // 0x80461A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x80461A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80461A90:
    // 0x80461A90: b           L_80461AB8
    // 0x80461A94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80461AB8;
    // 0x80461A94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80461A98:
    // 0x80461A98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80461A9C: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x80461AA0: lui         $t4, 0x8046
    ctx->r12 = S32(RELOC_HI16(122, 0X1434) << 16);
    // 0x80461AA4: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80461AA8: addiu       $t4, $t4, 0x19C4
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(122, 0X1434));
    // 0x80461AAC: sh          $t3, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r11;
    // 0x80461AB0: sw          $t4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r12;
    // 0x80461AB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80461AB8:
    // 0x80461AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80461ABC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80461AC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80461AC4: jr          $ra
    // 0x80461AC8: nop

    return;
    // 0x80461AC8: nop

;}
RECOMP_FUNC void func_8079F7A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079F7A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079F7A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079F7A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8079F7AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8079F7B0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8079F7B4: jal         0x80067BBC
    // 0x8079F7B8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8079F7B8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8079F7BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8079F7C0: jal         0x80067818
    // 0x8079F7C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8079F7C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8079F7C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079F7CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079F7D0: jr          $ra
    // 0x8079F7D4: nop

    return;
    // 0x8079F7D4: nop

;}
RECOMP_FUNC void func_804747C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804747C0: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(164, 0X1840) << 16);
    // 0x804747C4: jr          $ra
    // 0x804747C8: addiu       $v0, $v0, 0x6000
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(164, 0X1840));
    return;
    // 0x804747C8: addiu       $v0, $v0, 0x6000
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(164, 0X1840));
;}
RECOMP_FUNC void func_80066F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066F2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80066F30: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80066F34: c.eq.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl == ctx->f4.fl;
    // 0x80066F38: nop

    // 0x80066F3C: bc1fl       L_80066F50
    if (!c1cs) {
        // 0x80066F40: div.s       $f6, $f12, $f14
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
            goto L_80066F50;
    }
    goto skip_0;
    // 0x80066F40: div.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    skip_0:
    // 0x80066F44: jr          $ra
    // 0x80066F48: lhu         $v0, 0x65D0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X65D0);
    return;
    // 0x80066F48: lhu         $v0, 0x65D0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X65D0);
    // 0x80066F4C: div.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
L_80066F50:
    // 0x80066F50: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x80066F54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80066F58: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80066F5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80066F60: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80066F64: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80066F68: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80066F6C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80066F70: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80066F74: nop

    // 0x80066F78: slti        $at, $v0, 0x401
    ctx->r1 = SIGNED(ctx->r2) < 0X401 ? 1 : 0;
    // 0x80066F7C: bne         $at, $zero, L_80066F90
    if (ctx->r1 != 0) {
        // 0x80066F80: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_80066F90;
    }
    // 0x80066F80: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80066F84: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80066F88: jr          $ra
    // 0x80066F8C: lhu         $v0, 0x65D0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X65D0);
    return;
    // 0x80066F8C: lhu         $v0, 0x65D0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X65D0);
L_80066F90:
    // 0x80066F90: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80066F94: lhu         $v1, 0x65D0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X65D0);
    // 0x80066F98: jr          $ra
    // 0x80066F9C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80066F9C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8067FB38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067FB38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067FB3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067FB40: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067FB44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8067FB48: jal         0x8004700C
    // 0x8067FB4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8067FB4C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8067FB50: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8067FB54: beq         $v0, $zero, L_8067FC4C
    if (ctx->r2 == 0) {
        // 0x8067FB58: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_8067FC4C;
    }
    // 0x8067FB58: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8067FB5C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8067FB60: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(547, 0X1028) << 16);
    // 0x8067FB64: beq         $a0, $zero, L_8067FB74
    if (ctx->r4 == 0) {
        // 0x8067FB68: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_8067FB74;
    }
    // 0x8067FB68: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8067FB6C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8067FB70: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_8067FB74:
    // 0x8067FB74: bnel        $a0, $zero, L_8067FC50
    if (ctx->r4 != 0) {
        // 0x8067FB78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8067FC50;
    }
    goto skip_0;
    // 0x8067FB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8067FB7C: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8067FB80: lw          $t0, 0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XC);
    // 0x8067FB84: lui         $t4, 0x8068
    ctx->r12 = S32(RELOC_HI16(547, 0XFF0) << 16);
    // 0x8067FB88: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8067FB8C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8067FB90: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8067FB94: lw          $t8, 0x218($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(547, 0X1028));
    // 0x8067FB98: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8067FB9C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8067FBA0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8067FBA4: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8067FBA8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8067FBAC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8067FBB0: lw          $t4, 0x1E0($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(547, 0XFF0));
    // 0x8067FBB4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8067FBB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8067FBBC: sh          $t4, 0x144($a3)
    MEM_H(0X144, ctx->r7) = ctx->r12;
    // 0x8067FBC0: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x8067FBC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067FBC8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8067FBCC: bne         $t6, $at, L_8067FBF8
    if (ctx->r14 != ctx->r1) {
        // 0x8067FBD0: sw          $t6, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r14;
            goto L_8067FBF8;
    }
    // 0x8067FBD0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8067FBD4: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8067FBD8: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8067FBDC: lwc1        $f4, 0x84($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X84);
    // 0x8067FBE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8067FBE4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8067FBE8: nop

    // 0x8067FBEC: bc1fl       L_8067FBFC
    if (!c1cs) {
        // 0x8067FBF0: lw          $t0, 0x4($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X4);
            goto L_8067FBFC;
    }
    goto skip_1;
    // 0x8067FBF0: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x8067FBF4: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
L_8067FBF8:
    // 0x8067FBF8: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
L_8067FBFC:
    // 0x8067FBFC: slti        $at, $t0, 0x7
    ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
    // 0x8067FC00: bnel        $at, $zero, L_8067FC50
    if (ctx->r1 != 0) {
        // 0x8067FC04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8067FC50;
    }
    goto skip_2;
    // 0x8067FC04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8067FC08: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8067FC0C: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(547, 0X10FC) << 16);
    // 0x8067FC10: lwc1        $f8, 0x2EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(547, 0X10FC));
    // 0x8067FC14: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x8067FC18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8067FC1C: addiu       $v0, $a3, 0xC4
    ctx->r2 = ADD32(ctx->r7, 0XC4);
    // 0x8067FC20: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x8067FC24: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x8067FC28: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x8067FC2C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8067FC30: beq         $t1, $zero, L_8067FC44
    if (ctx->r9 == 0) {
        // 0x8067FC34: nop
    
            goto L_8067FC44;
    }
    // 0x8067FC34: nop

    // 0x8067FC38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8067FC3C: nop

    // 0x8067FC40: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
L_8067FC44:
    // 0x8067FC44: jal         0x80680194
    // 0x8067FC48: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80680194(rdram, ctx);
        goto after_1;
    // 0x8067FC48: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
L_8067FC4C:
    // 0x8067FC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8067FC50:
    // 0x8067FC50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067FC54: jr          $ra
    // 0x8067FC58: nop

    return;
    // 0x8067FC58: nop

;}
RECOMP_FUNC void func_80574970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574970: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80574974: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x80574978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057497C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80574980: beq         $t6, $zero, L_8057499C
    if (ctx->r14 == 0) {
        // 0x80574984: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8057499C;
    }
    // 0x80574984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80574988: jal         0x805746D0
    // 0x8057498C: nop

    func_805746D0(rdram, ctx);
        goto after_0;
    // 0x8057498C: nop

    after_0:
    // 0x80574990: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80574994: jal         0x80574A64
    // 0x80574998: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80574A64(rdram, ctx);
        goto after_1;
    // 0x80574998: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
L_8057499C:
    // 0x8057499C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805749A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805749A4: jr          $ra
    // 0x805749A8: nop

    return;
    // 0x805749A8: nop

;}
RECOMP_FUNC void func_804C3190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3190: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804C3194: jr          $ra
    // 0x804C3198: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x804C3198: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80449814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449814: jr          $ra
    // 0x80449818: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80449818: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80777204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80777204: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80777208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8077720C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80777210: jal         0x8077717C
    // 0x80777214: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8077717C(rdram, ctx);
        goto after_0;
    // 0x80777214: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80777218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8077721C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80777220: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80777224: jal         0x8077725C
    // 0x80777228: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8077725C(rdram, ctx);
        goto after_1;
    // 0x80777228: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8077722C: jal         0x80777164
    // 0x80777230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80777164(rdram, ctx);
        goto after_2;
    // 0x80777230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80777234: lui         $t7, 0x8077
    ctx->r15 = S32(RELOC_HI16(772, 0X668) << 16);
    // 0x80777238: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8077723C: addiu       $t7, $t7, 0x7138
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(772, 0X668));
    // 0x80777240: sh          $t6, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r14;
    // 0x80777244: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x80777248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8077724C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80777250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80777254: jr          $ra
    // 0x80777258: nop

    return;
    // 0x80777258: nop

;}
RECOMP_FUNC void func_805AE1D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE1D4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE1D8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE1DC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE1E0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE1E4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE1E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE1EC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE1F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE1F4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE1F8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE1FC: jr          $ra
    // 0x805AE200: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE200: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
