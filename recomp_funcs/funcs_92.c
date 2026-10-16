#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804C50B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C50B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C50B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C50BC: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804C50C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804C50C4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804C50C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804C50CC: nop

    // 0x804C50D0: bc1fl       L_804C514C
    if (!c1cs) {
        // 0x804C50D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C514C;
    }
    goto skip_0;
    // 0x804C50D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C50D8: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x804C50DC: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x804C50E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804C50E4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x804C50E8: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x804C50EC: beql        $t8, $zero, L_804C514C
    if (ctx->r24 == 0) {
        // 0x804C50F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C514C;
    }
    goto skip_1;
    // 0x804C50F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804C50F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804C50F8: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C50FC: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x804C5100: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
    // 0x804C5104: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x804C5108: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x804C510C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x804C5110: addiu       $a0, $zero, 0x4008
    ctx->r4 = ADD32(0, 0X4008);
    // 0x804C5114: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x804C5118: addiu       $a1, $a3, 0x3C
    ctx->r5 = ADD32(ctx->r7, 0X3C);
    // 0x804C511C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C5120: lw          $t9, 0x14($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X14);
    // 0x804C5124: jalr        $t9
    // 0x804C5128: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804C5128: nop

    after_0:
    // 0x804C512C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x804C5130: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x804C5134: jal         0x80067BBC
    // 0x804C5138: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x804C5138: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_1:
    // 0x804C513C: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    // 0x804C5140: jal         0x80067818
    // 0x804C5144: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x804C5144: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x804C5148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C514C:
    // 0x804C514C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5150: jr          $ra
    // 0x804C5154: nop

    return;
    // 0x804C5154: nop

;}
RECOMP_FUNC void func_80683044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80683044: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80683048: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8068304C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80683050: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80683054: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80683058: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8068305C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80683060: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80683064: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80683068: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8068306C: jr          $ra
    // 0x80683070: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80683070: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805274D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805274D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805274DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805274E0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x805274E4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805274E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805274EC: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x805274F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805274F4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x805274F8: nop

    // 0x805274FC: bc1fl       L_805275B0
    if (!c1cs) {
        // 0x80527500: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_805275B0;
    }
    goto skip_0;
    // 0x80527500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80527504: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80527508: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8052750C: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80527510: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80527514: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80527518: bne         $at, $zero, L_80527590
    if (ctx->r1 != 0) {
        // 0x8052751C: swc1        $f6, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
            goto L_80527590;
    }
    // 0x8052751C: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x80527520: lw          $t8, 0x78($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X78);
    // 0x80527524: blezl       $t8, L_8052754C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80527528: lhu         $v0, 0xC($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0XC);
            goto L_8052754C;
    }
    goto skip_1;
    // 0x80527528: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    skip_1:
    // 0x8052752C: lw          $t0, 0x78($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X78);
    // 0x80527530: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80527534: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x80527538: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8052753C: sw          $t1, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r9;
    // 0x80527540: b           L_805275BC
    // 0x80527544: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_805275BC;
    // 0x80527544: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80527548: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
L_8052754C:
    // 0x8052754C: addiu       $at, $zero, 0x41ED
    ctx->r1 = ADD32(0, 0X41ED);
    // 0x80527550: beq         $v0, $at, L_80527580
    if (ctx->r2 == ctx->r1) {
        // 0x80527554: addiu       $at, $zero, 0x41EF
        ctx->r1 = ADD32(0, 0X41EF);
            goto L_80527580;
    }
    // 0x80527554: addiu       $at, $zero, 0x41EF
    ctx->r1 = ADD32(0, 0X41EF);
    // 0x80527558: beq         $v0, $at, L_80527570
    if (ctx->r2 == ctx->r1) {
        // 0x8052755C: addiu       $at, $zero, 0x41F0
        ctx->r1 = ADD32(0, 0X41F0);
            goto L_80527570;
    }
    // 0x8052755C: addiu       $at, $zero, 0x41F0
    ctx->r1 = ADD32(0, 0X41F0);
    // 0x80527560: beq         $v0, $at, L_80527580
    if (ctx->r2 == ctx->r1) {
        // 0x80527564: addiu       $at, $zero, 0x4583
        ctx->r1 = ADD32(0, 0X4583);
            goto L_80527580;
    }
    // 0x80527564: addiu       $at, $zero, 0x4583
    ctx->r1 = ADD32(0, 0X4583);
    // 0x80527568: bne         $v0, $at, L_80527580
    if (ctx->r2 != ctx->r1) {
        // 0x8052756C: nop
    
            goto L_80527580;
    }
    // 0x8052756C: nop

L_80527570:
    // 0x80527570: jal         0x805274B8
    // 0x80527574: nop

    func_805274B8(rdram, ctx);
        goto after_0;
    // 0x80527574: nop

    after_0:
    // 0x80527578: b           L_805275C0
    // 0x8052757C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805275C0;
    // 0x8052757C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527580:
    // 0x80527580: jal         0x8052746C
    // 0x80527584: nop

    func_8052746C(rdram, ctx);
        goto after_1;
    // 0x80527584: nop

    after_1:
    // 0x80527588: b           L_805275C0
    // 0x8052758C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805275C0;
    // 0x8052758C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527590:
    // 0x80527590: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x80527594: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80527598: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x8052759C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x805275A0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x805275A4: b           L_805275BC
    // 0x805275A8: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
        goto L_805275BC;
    // 0x805275A8: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x805275AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_805275B0:
    // 0x805275B0: nop

    // 0x805275B4: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x805275B8: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_805275BC:
    // 0x805275BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805275C0:
    // 0x805275C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805275C4: jr          $ra
    // 0x805275C8: nop

    return;
    // 0x805275C8: nop

;}
RECOMP_FUNC void func_800513F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800513F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800513FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051400: jal         0x80051368
    // 0x80051404: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051368(rdram, ctx);
        goto after_0;
    // 0x80051404: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x80051408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005140C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051410: jr          $ra
    // 0x80051414: nop

    return;
    // 0x80051414: nop

;}
RECOMP_FUNC void func_8057F7CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F7CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057F7D0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8057F7D4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8057F7D8: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8057F7DC: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8057F7E0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47CC) << 16);
    // 0x8057F7E4: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8057F7E8: lwc1        $f16, 0x35DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47CC));
    // 0x8057F7EC: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8057F7F0: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8057F7F4: nop

    // 0x8057F7F8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8057F7FC: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8057F800: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8057F804: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8057F808: jr          $ra
    // 0x8057F80C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8057F80C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8042F190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F198: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042F19C: jal         0x8042E6BC
    // 0x8042F1A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042E6BC(rdram, ctx);
        goto after_0;
    // 0x8042F1A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042F1A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042F1A8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3B8C) << 16);
    // 0x8042F1AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8042F1B0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x8042F1B4: lwc1        $f6, 0x1C6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3B8C));
    // 0x8042F1B8: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042F1BC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8042F1C0: nop

    // 0x8042F1C4: bc1fl       L_8042F1D8
    if (!c1cs) {
        // 0x8042F1C8: sw          $zero, 0x138($a0)
        MEM_W(0X138, ctx->r4) = 0;
            goto L_8042F1D8;
    }
    goto skip_0;
    // 0x8042F1C8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    skip_0:
    // 0x8042F1CC: b           L_8042F1D8
    // 0x8042F1D0: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
        goto L_8042F1D8;
    // 0x8042F1D0: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x8042F1D4: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
L_8042F1D8:
    // 0x8042F1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042F1DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F1E0: jr          $ra
    // 0x8042F1E4: nop

    return;
    // 0x8042F1E4: nop

;}
RECOMP_FUNC void func_80011928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011928: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001192C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80011930: slti        $at, $a0, 0x77
    ctx->r1 = SIGNED(ctx->r4) < 0X77 ? 1 : 0;
    // 0x80011934: bne         $at, $zero, L_80011944
    if (ctx->r1 != 0) {
        // 0x80011938: sra         $a1, $a1, 16
        ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
            goto L_80011944;
    }
    // 0x80011938: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001193C: jr          $ra
    // 0x80011940: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80011940: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011944:
    // 0x80011944: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80011948: bne         $at, $zero, L_80011958
    if (ctx->r1 != 0) {
        // 0x8001194C: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80011958;
    }
    // 0x8001194C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80011950: jr          $ra
    // 0x80011954: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x80011954: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80011958:
    // 0x80011958: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001195C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80011960: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80011964: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80011968: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8001196C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80011970: lw          $t9, -0x5AD0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5AD0);
    // 0x80011974: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80011978: bne         $t9, $zero, L_80011988
    if (ctx->r25 != 0) {
        // 0x8001197C: nop
    
            goto L_80011988;
    }
    // 0x8001197C: nop

    // 0x80011980: jr          $ra
    // 0x80011984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80011984: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80011988:
    // 0x80011988: jr          $ra
    // 0x8001198C: nop

    return;
    // 0x8001198C: nop

;}
RECOMP_FUNC void func_8001F478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F480: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8001F484: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x8001F488: bne         $t6, $at, L_8001F49C
    if (ctx->r14 != ctx->r1) {
        // 0x8001F48C: nop
    
            goto L_8001F49C;
    }
    // 0x8001F48C: nop

    // 0x8001F490: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x8001F494: bnel        $t7, $zero, L_8001F4A8
    if (ctx->r15 != 0) {
        // 0x8001F498: lbu         $t8, 0x159($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X159);
            goto L_8001F4A8;
    }
    goto skip_0;
    // 0x8001F498: lbu         $t8, 0x159($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X159);
    skip_0:
L_8001F49C:
    // 0x8001F49C: b           L_8001F550
    // 0x8001F4A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8001F550;
    // 0x8001F4A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001F4A4: lbu         $t8, 0x159($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X159);
L_8001F4A8:
    // 0x8001F4A8: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x8001F4AC: bnel        $t8, $zero, L_8001F4C8
    if (ctx->r24 != 0) {
        // 0x8001F4B0: lwc1        $f0, 0x174($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X174);
            goto L_8001F4C8;
    }
    goto skip_1;
    // 0x8001F4B0: lwc1        $f0, 0x174($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X174);
    skip_1:
    // 0x8001F4B4: jal         0x8002DFF8
    // 0x8001F4B8: nop

    func_8002DFF8(rdram, ctx);
        goto after_0;
    // 0x8001F4B8: nop

    after_0:
    // 0x8001F4BC: b           L_8001F550
    // 0x8001F4C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F550;
    // 0x8001F4C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F4C4: lwc1        $f0, 0x174($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X174);
L_8001F4C8:
    // 0x8001F4C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001F4CC: lw          $v1, 0x2C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X2C);
    // 0x8001F4D0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8001F4D4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8001F4D8: nop

    // 0x8001F4DC: bc1fl       L_8001F4F0
    if (!c1cs) {
        // 0x8001F4E0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8001F4F0;
    }
    goto skip_2;
    // 0x8001F4E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_2:
    // 0x8001F4E4: b           L_8001F50C
    // 0x8001F4E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F50C;
    // 0x8001F4E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001F4EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8001F4F0:
    // 0x8001F4F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001F4F4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8001F4F8: nop

    // 0x8001F4FC: bc1f        L_8001F50C
    if (!c1cs) {
        // 0x8001F500: nop
    
            goto L_8001F50C;
    }
    // 0x8001F500: nop

    // 0x8001F504: b           L_8001F50C
    // 0x8001F508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8001F50C;
    // 0x8001F508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001F50C:
    // 0x8001F50C: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8001F510: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8001F514: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8001F518: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8001F51C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8001F520: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8001F524: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001F528: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8001F52C: lw          $t3, -0x6680($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6680);
    // 0x8001F530: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001F534: and         $t4, $t3, $v1
    ctx->r12 = ctx->r11 & ctx->r3;
    // 0x8001F538: beq         $t4, $zero, L_8001F550
    if (ctx->r12 == 0) {
        // 0x8001F53C: nop
    
            goto L_8001F550;
    }
    // 0x8001F53C: nop

    // 0x8001F540: jal         0x8002DFF8
    // 0x8001F544: nop

    func_8002DFF8(rdram, ctx);
        goto after_1;
    // 0x8001F544: nop

    after_1:
    // 0x8001F548: b           L_8001F550
    // 0x8001F54C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001F550;
    // 0x8001F54C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F550:
    // 0x8001F550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001F558: jr          $ra
    // 0x8001F55C: nop

    return;
    // 0x8001F55C: nop

;}
RECOMP_FUNC void func_8078A3BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A3BC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8078A3C0: lw          $t6, 0x168($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X168);
    // 0x8078A3C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8078A3C8: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8078A3CC: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x8078A3D0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8078A3D4: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x8078A3D8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8078A3DC: sll         $t8, $t8, 7
    ctx->r24 = S32(ctx->r24 << 7);
    // 0x8078A3E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8078A3E4: lui         $t3, 0xFD50
    ctx->r11 = S32(0XFD50 << 16);
    // 0x8078A3E8: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x8078A3EC: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8078A3F0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8078A3F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8078A3F8: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8078A3FC: lui         $t5, 0xF550
    ctx->r13 = S32(0XF550 << 16);
    // 0x8078A400: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8078A404: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8078A408: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8078A40C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8078A410: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8078A414: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8078A418: lui         $t4, 0x713
    ctx->r12 = S32(0X713 << 16);
    // 0x8078A41C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8078A420: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8078A424: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8078A428: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8078A42C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8078A430: ori         $t4, $t4, 0xF400
    ctx->r12 = ctx->r12 | 0XF400;
    // 0x8078A434: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8078A438: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8078A43C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8078A440: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8078A444: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8078A448: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8078A44C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8078A450: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x8078A454: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8078A458: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8078A45C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8078A460: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8078A464: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8078A468: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x8078A46C: lui         $t4, 0x3
    ctx->r12 = S32(0X3 << 16);
    // 0x8078A470: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8078A474: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8078A478: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8078A47C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8078A480: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8078A484: ori         $t4, $t4, 0xC09C
    ctx->r12 = ctx->r12 | 0XC09C;
    // 0x8078A488: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x8078A48C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8078A490: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8078A494: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8078A498: jr          $ra
    // 0x8078A49C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    return;
    // 0x8078A49C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_80677674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80677674: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80677678: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x8067767C: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80677680: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80677684: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80677688: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8067768C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80677690: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80677694: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x80677698: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x8067769C: swc1        $f0, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = ctx->f0.u32l;
    // 0x806776A0: swc1        $f0, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f0.u32l;
    // 0x806776A4: swc1        $f0, 0x2F4($v0)
    MEM_W(0X2F4, ctx->r2) = ctx->f0.u32l;
    // 0x806776A8: swc1        $f0, 0x370($v0)
    MEM_W(0X370, ctx->r2) = ctx->f0.u32l;
    // 0x806776AC: swc1        $f0, 0x2F8($v0)
    MEM_W(0X2F8, ctx->r2) = ctx->f0.u32l;
    // 0x806776B0: swc1        $f0, 0x374($v0)
    MEM_W(0X374, ctx->r2) = ctx->f0.u32l;
L_806776B4:
    // 0x806776B4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806776B8: swc1        $f0, 0x2F4($a0)
    MEM_W(0X2F4, ctx->r4) = ctx->f0.u32l;
    // 0x806776BC: swc1        $f0, 0x370($a0)
    MEM_W(0X370, ctx->r4) = ctx->f0.u32l;
    // 0x806776C0: swc1        $f0, 0x2F8($a0)
    MEM_W(0X2F8, ctx->r4) = ctx->f0.u32l;
    // 0x806776C4: swc1        $f0, 0x374($a0)
    MEM_W(0X374, ctx->r4) = ctx->f0.u32l;
    // 0x806776C8: swc1        $f0, 0x2FC($a0)
    MEM_W(0X2FC, ctx->r4) = ctx->f0.u32l;
    // 0x806776CC: swc1        $f0, 0x378($a0)
    MEM_W(0X378, ctx->r4) = ctx->f0.u32l;
    // 0x806776D0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x806776D4: swc1        $f0, 0x2E0($a0)
    MEM_W(0X2E0, ctx->r4) = ctx->f0.u32l;
    // 0x806776D8: bne         $v1, $a1, L_806776B4
    if (ctx->r3 != ctx->r5) {
        // 0x806776DC: swc1        $f0, 0x35C($a0)
        MEM_W(0X35C, ctx->r4) = ctx->f0.u32l;
            goto L_806776B4;
    }
    // 0x806776DC: swc1        $f0, 0x35C($a0)
    MEM_W(0X35C, ctx->r4) = ctx->f0.u32l;
    // 0x806776E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806776E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806776E8: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x806776EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806776F0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x806776F4: addiu       $a3, $v0, 0x174
    ctx->r7 = ADD32(ctx->r2, 0X174);
    // 0x806776F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806776FC: sw          $zero, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = 0;
    // 0x80677700: sw          $zero, 0x2E8($v0)
    MEM_W(0X2E8, ctx->r2) = 0;
    // 0x80677704: swc1        $f0, 0x3F4($v0)
    MEM_W(0X3F4, ctx->r2) = ctx->f0.u32l;
    // 0x80677708: sh          $zero, 0x408($v0)
    MEM_H(0X408, ctx->r2) = 0;
    // 0x8067770C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80677710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80677714: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80677718: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x8067771C: addiu       $s2, $zero, 0x174
    ctx->r18 = ADD32(0, 0X174);
    // 0x80677720: addiu       $s1, $zero, 0x3E
    ctx->r17 = ADD32(0, 0X3E);
    // 0x80677724: swc1        $f2, 0x3E8($v0)
    MEM_W(0X3E8, ctx->r2) = ctx->f2.u32l;
    // 0x80677728: swc1        $f2, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f2.u32l;
    // 0x8067772C: swc1        $f2, 0x3F8($v0)
    MEM_W(0X3F8, ctx->r2) = ctx->f2.u32l;
    // 0x80677730: swc1        $f2, 0x3FC($v0)
    MEM_W(0X3FC, ctx->r2) = ctx->f2.u32l;
    // 0x80677734: swc1        $f2, 0x400($v0)
    MEM_W(0X400, ctx->r2) = ctx->f2.u32l;
    // 0x80677738: swc1        $f4, 0x3F0($v0)
    MEM_W(0X3F0, ctx->r2) = ctx->f4.u32l;
L_8067773C:
    // 0x8067773C: lwc1        $f6, 0x3F0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3F0);
    // 0x80677740: lwc1        $f16, 0x2F0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X2F0);
    // 0x80677744: lwc1        $f18, 0x3E8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80677748: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8067774C: lwc1        $f10, 0x3EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x80677750: mul.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80677754: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80677758: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8067775C: mul.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80677760: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80677764: addiu       $t2, $a2, 0x4
    ctx->r10 = ADD32(ctx->r6, 0X4);
    // 0x80677768: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8067776C: addiu       $t3, $a3, 0x4
    ctx->r11 = ADD32(ctx->r7, 0X4);
    // 0x80677770: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80677774: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80677778: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8067777C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80677780: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80677784: nop

    // 0x80677788: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x8067778C: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80677790: lwc1        $f18, 0x3E8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80677794: lwc1        $f16, 0x2F0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X2F0);
    // 0x80677798: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8067779C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x806777A0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x806777A4: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x806777A8: nop

    // 0x806777AC: sh          $t6, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r14;
    // 0x806777B0: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x806777B4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x806777B8: lwc1        $f18, 0x2F0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2F0);
    // 0x806777BC: beq         $t0, $s1, L_80677880
    if (ctx->r8 == ctx->r17) {
        // 0x806777C0: lwc1        $f16, 0x3E8($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X3E8);
            goto L_80677880;
    }
    // 0x806777C0: lwc1        $f16, 0x3E8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x806777C4: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_806777C8:
    // 0x806777C8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x806777CC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x806777D0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x806777D4: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x806777D8: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x806777DC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x806777E0: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x806777E4: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x806777E8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806777EC: mfc1        $t8, $f14
    ctx->r24 = (int32_t)ctx->f14.u32l;
    // 0x806777F0: nop

    // 0x806777F4: sh          $t8, -0x8($t2)
    MEM_H(-0X8, ctx->r10) = ctx->r24;
    // 0x806777F8: sh          $t1, -0x8($t3)
    MEM_H(-0X8, ctx->r11) = ctx->r9;
    // 0x806777FC: lwc1        $f14, 0x2E8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X2E8);
    // 0x80677800: lwc1        $f10, 0x3E8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80677804: sub.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80677808: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8067780C: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80677810: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80677814: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80677818: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8067781C: sh          $t7, -0x6($t2)
    MEM_H(-0X6, ctx->r10) = ctx->r15;
    // 0x80677820: sh          $t1, -0x6($t3)
    MEM_H(-0X6, ctx->r11) = ctx->r9;
    // 0x80677824: lwc1        $f10, 0x2EC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2EC);
    // 0x80677828: lwc1        $f8, 0x3E8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x8067782C: mfc1        $t1, $f14
    ctx->r9 = (int32_t)ctx->f14.u32l;
    // 0x80677830: add.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80677834: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80677838: trunc.w.s   $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8067783C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80677840: nop

    // 0x80677844: sh          $t9, -0x4($t2)
    MEM_H(-0X4, ctx->r10) = ctx->r25;
    // 0x80677848: sh          $t1, -0x4($t3)
    MEM_H(-0X4, ctx->r11) = ctx->r9;
    // 0x8067784C: lwc1        $f8, 0x2EC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2EC);
    // 0x80677850: lwc1        $f10, 0x3E8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80677854: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80677858: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8067785C: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80677860: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80677864: nop

    // 0x80677868: sh          $t8, -0x2($t2)
    MEM_H(-0X2, ctx->r10) = ctx->r24;
    // 0x8067786C: sh          $t1, -0x2($t3)
    MEM_H(-0X2, ctx->r11) = ctx->r9;
    // 0x80677870: lwc1        $f18, 0x2F0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2F0);
    // 0x80677874: lwc1        $f16, 0x3E8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80677878: bnel        $t0, $s1, L_806777C8
    if (ctx->r8 != ctx->r17) {
        // 0x8067787C: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_806777C8;
    }
    goto skip_0;
    // 0x8067787C: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_0:
L_80677880:
    // 0x80677880: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80677884: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80677888: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x8067788C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80677890: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80677894: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x80677898: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8067789C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x806778A0: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806778A4: mfc1        $t8, $f14
    ctx->r24 = (int32_t)ctx->f14.u32l;
    // 0x806778A8: nop

    // 0x806778AC: sh          $t8, -0x8($t2)
    MEM_H(-0X8, ctx->r10) = ctx->r24;
    // 0x806778B0: sh          $t1, -0x8($t3)
    MEM_H(-0X8, ctx->r11) = ctx->r9;
    // 0x806778B4: lwc1        $f10, 0x3E8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x806778B8: lwc1        $f14, 0x2E8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X2E8);
    // 0x806778BC: sub.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x806778C0: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x806778C4: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x806778C8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x806778CC: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806778D0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x806778D4: nop

    // 0x806778D8: sh          $t7, -0x6($t2)
    MEM_H(-0X6, ctx->r10) = ctx->r15;
    // 0x806778DC: sh          $t1, -0x6($t3)
    MEM_H(-0X6, ctx->r11) = ctx->r9;
    // 0x806778E0: lwc1        $f8, 0x3E8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x806778E4: lwc1        $f10, 0x2EC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2EC);
    // 0x806778E8: mfc1        $t1, $f14
    ctx->r9 = (int32_t)ctx->f14.u32l;
    // 0x806778EC: add.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x806778F0: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x806778F4: trunc.w.s   $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x806778F8: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x806778FC: nop

    // 0x80677900: sh          $t9, -0x4($t2)
    MEM_H(-0X4, ctx->r10) = ctx->r25;
    // 0x80677904: sh          $t1, -0x4($t3)
    MEM_H(-0X4, ctx->r11) = ctx->r9;
    // 0x80677908: lwc1        $f10, 0x3E8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x8067790C: lwc1        $f8, 0x2EC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2EC);
    // 0x80677910: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80677914: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80677918: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8067791C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80677920: nop

    // 0x80677924: sh          $t8, -0x2($t2)
    MEM_H(-0X2, ctx->r10) = ctx->r24;
    // 0x80677928: sh          $t1, -0x2($t3)
    MEM_H(-0X2, ctx->r11) = ctx->r9;
    // 0x8067792C: addiu       $a1, $a1, 0x7C
    ctx->r5 = ADD32(ctx->r5, 0X7C);
    // 0x80677930: addiu       $a2, $a2, 0x7C
    ctx->r6 = ADD32(ctx->r6, 0X7C);
    // 0x80677934: addiu       $a3, $a3, 0x7C
    ctx->r7 = ADD32(ctx->r7, 0X7C);
    // 0x80677938: addiu       $t4, $t4, 0x7C
    ctx->r12 = ADD32(ctx->r12, 0X7C);
    // 0x8067793C: bne         $a1, $s2, L_8067773C
    if (ctx->r5 != ctx->r18) {
        // 0x80677940: addiu       $s0, $s0, 0x7C
        ctx->r16 = ADD32(ctx->r16, 0X7C);
            goto L_8067773C;
    }
    // 0x80677940: addiu       $s0, $s0, 0x7C
    ctx->r16 = ADD32(ctx->r16, 0X7C);
    // 0x80677944: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80677948: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x8067794C: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80677950: jr          $ra
    // 0x80677954: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80677954: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8058463C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058463C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584640: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584644: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584648: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058464C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584650: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584654: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584658: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058465C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584660: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584664: jr          $ra
    // 0x80584668: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584668: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80716DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80716DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80716E00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80716E04: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80716E08: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80716E0C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80716E10: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80716E14: lw          $v1, 0x6E34($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E34);
    // 0x80716E18: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80716E1C: beql        $v1, $zero, L_80716E38
    if (ctx->r3 == 0) {
        // 0x80716E20: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80716E38;
    }
    goto skip_0;
    // 0x80716E20: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80716E24: jal         0x80716A28
    // 0x80716E28: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    func_80716A28(rdram, ctx);
        goto after_0;
    // 0x80716E28: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    after_0:
    // 0x80716E2C: b           L_80716E5C
    // 0x80716E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80716E5C;
    // 0x80716E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80716E34: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80716E38:
    // 0x80716E38: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80716E3C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80716E40: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80716E44: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80716E48: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80716E4C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80716E50: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80716E54: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80716E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80716E5C:
    // 0x80716E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80716E60: jr          $ra
    // 0x80716E64: nop

    return;
    // 0x80716E64: nop

;}
RECOMP_FUNC void func_8064B7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B7C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064B7CC: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064B7D0: jr          $ra
    // 0x8064B7D4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8064B7D4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_805DADD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DADD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DADD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DADDC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805DADE0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805DADE4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805DADE8: lui         $t8, 0x805E
    ctx->r24 = S32(RELOC_HI16(480, 0X26AC) << 16);
    // 0x805DADEC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805DADF0: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805DADF4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805DADF8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805DADFC: lw          $t8, -0x2C54($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(480, 0X26AC));
    // 0x805DAE00: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805DAE04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805DAE08: jal         0x80048490
    // 0x805DAE0C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805DAE0C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805DAE10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DAE14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DAE18: jr          $ra
    // 0x805DAE1C: nop

    return;
    // 0x805DAE1C: nop

;}
RECOMP_FUNC void func_80422558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042255C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80422560: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80422564: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80422568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042256C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80422570: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80422574: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80422578: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042257C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80422580: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(32, 0X173C) << 16);
    // 0x80422584: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80422588: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8042258C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80422590: lw          $t2, 0x27FC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(32, 0X173C));
    // 0x80422594: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80422598: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8042259C: jal         0x80421758
    // 0x804225A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80421758(rdram, ctx);
        goto after_0;
    // 0x804225A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804225A4: jal         0x804217B4
    // 0x804225A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804217B4(rdram, ctx);
        goto after_1;
    // 0x804225A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804225AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804225B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804225B4: jr          $ra
    // 0x804225B8: nop

    return;
    // 0x804225B8: nop

    // 0x804225BC: nop

;}
RECOMP_FUNC void func_8045AC6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045AC6C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8045AC70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045AC74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045AC78: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045AC7C: jal         0x8045AA4C
    // 0x8045AC80: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_8045AA4C(rdram, ctx);
        goto after_0;
    // 0x8045AC80: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045AC84: jal         0x8045AAC0
    // 0x8045AC88: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8045AAC0(rdram, ctx);
        goto after_1;
    // 0x8045AC88: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x8045AC8C: jal         0x8045ABB8
    // 0x8045AC90: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8045ABB8(rdram, ctx);
        goto after_2;
    // 0x8045AC90: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x8045AC94: lhu         $t6, 0x1C($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X1C);
    // 0x8045AC98: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8045AC9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8045ACA0: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x8045ACA4: beq         $t7, $zero, L_8045AECC
    if (ctx->r15 == 0) {
        // 0x8045ACA8: addiu       $v0, $a0, 0xC4
        ctx->r2 = ADD32(ctx->r4, 0XC4);
            goto L_8045AECC;
    }
    // 0x8045ACA8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8045ACAC: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045ACB0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8045ACB4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(104, 0XD50) << 16);
    // 0x8045ACB8: lhu         $t9, 0x40($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X40);
    // 0x8045ACBC: andi        $t0, $t9, 0x8
    ctx->r8 = ctx->r25 & 0X8;
    // 0x8045ACC0: beql        $t0, $zero, L_8045ACF4
    if (ctx->r8 == 0) {
        // 0x8045ACC4: lwc1        $f4, 0x0($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8045ACF4;
    }
    goto skip_0;
    // 0x8045ACC4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8045ACC8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8045ACCC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8045ACD0: swc1        $f16, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f16.u32l;
    // 0x8045ACD4: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x8045ACD8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8045ACDC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045ACE0: lhu         $t1, 0x40($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X40);
    // 0x8045ACE4: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x8045ACE8: b           L_8045AD78
    // 0x8045ACEC: sh          $t2, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r10;
        goto L_8045AD78;
    // 0x8045ACEC: sh          $t2, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r10;
    // 0x8045ACF0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
L_8045ACF4:
    // 0x8045ACF4: lwc1        $f6, -0x48A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0XD50));
    // 0x8045ACF8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8045ACFC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8045AD00: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8045AD04: jal         0x80066DE4
    // 0x8045AD08: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8045AD08: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x8045AD0C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8045AD10: jal         0x80066E88
    // 0x8045AD14: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8045AD14: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_4:
    // 0x8045AD18: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8045AD1C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8045AD20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8045AD24: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8045AD28: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8045AD2C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8045AD30: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x8045AD34: jal         0x80066E88
    // 0x8045AD38: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x8045AD38: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_5:
    // 0x8045AD3C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8045AD40: jal         0x80066DE4
    // 0x8045AD44: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x8045AD44: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_6:
    // 0x8045AD48: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8045AD4C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8045AD50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8045AD54: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8045AD58: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(104, 0XD54) << 16);
    // 0x8045AD5C: lwc1        $f6, -0x489C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0XD54));
    // 0x8045AD60: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8045AD64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8045AD68: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8045AD6C: nop

    // 0x8045AD70: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8045AD74: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
L_8045AD78:
    // 0x8045AD78: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8045AD7C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(104, 0XD58) << 16);
    // 0x8045AD80: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8045AD84: nop

    // 0x8045AD88: bc1fl       L_8045ADB8
    if (!c1cs) {
        // 0x8045AD8C: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_8045ADB8;
    }
    goto skip_1;
    // 0x8045AD8C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x8045AD90: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8045AD94: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8045AD98: nop

    // 0x8045AD9C: bc1fl       L_8045ADD8
    if (!c1cs) {
        // 0x8045ADA0: lwc1        $f8, 0x24($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
            goto L_8045ADD8;
    }
    goto skip_2;
    // 0x8045ADA0: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    skip_2:
    // 0x8045ADA4: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8045ADA8: add.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8045ADAC: b           L_8045ADD4
    // 0x8045ADB0: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
        goto L_8045ADD4;
    // 0x8045ADB0: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8045ADB4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_8045ADB8:
    // 0x8045ADB8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8045ADBC: nop

    // 0x8045ADC0: bc1fl       L_8045ADD8
    if (!c1cs) {
        // 0x8045ADC4: lwc1        $f8, 0x24($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
            goto L_8045ADD8;
    }
    goto skip_3;
    // 0x8045ADC4: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    skip_3:
    // 0x8045ADC8: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8045ADCC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8045ADD0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_8045ADD4:
    // 0x8045ADD4: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
L_8045ADD8:
    // 0x8045ADD8: lwc1        $f10, -0x4898($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0XD58));
    // 0x8045ADDC: lhu         $v0, 0x40($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X40);
    // 0x8045ADE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8045ADE4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8045ADE8: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x8045ADEC: bne         $t3, $at, L_8045AF10
    if (ctx->r11 != ctx->r1) {
        // 0x8045ADF0: swc1        $f18, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
            goto L_8045AF10;
    }
    // 0x8045ADF0: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8045ADF4: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8045ADF8: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8045ADFC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(104, 0XD5C) << 16);
    // 0x8045AE00: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8045AE04: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8045AE08: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8045AE0C: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8045AE10: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8045AE14: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8045AE18: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8045AE1C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8045AE20: lwc1        $f4, -0x4894($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0XD5C));
    // 0x8045AE24: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(104, 0XD60) << 16);
    // 0x8045AE28: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8045AE2C: nop

    // 0x8045AE30: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8045AE34: add.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8045AE38: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8045AE3C: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8045AE40: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8045AE44: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8045AE48: bc1f        L_8045AE68
    if (!c1cs) {
        // 0x8045AE4C: nop
    
            goto L_8045AE68;
    }
    // 0x8045AE4C: nop

    // 0x8045AE50: lwc1        $f6, -0x4890($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0XD60));
    // 0x8045AE54: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8045AE58: nop

    // 0x8045AE5C: bc1fl       L_8045AE6C
    if (!c1cs) {
        // 0x8045AE60: lwc1        $f12, 0x3C($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_8045AE6C;
    }
    goto skip_4;
    // 0x8045AE60: lwc1        $f12, 0x3C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X3C);
    skip_4:
    // 0x8045AE64: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8045AE68:
    // 0x8045AE68: lwc1        $f12, 0x3C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X3C);
L_8045AE6C:
    // 0x8045AE6C: jal         0x80066E88
    // 0x8045AE70: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x8045AE70: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_7:
    // 0x8045AE74: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8045AE78: jal         0x80066DE4
    // 0x8045AE7C: lwc1        $f12, 0x3C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X3C);
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x8045AE7C: lwc1        $f12, 0x3C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X3C);
    after_8:
    // 0x8045AE80: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8045AE84: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8045AE88: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8045AE8C: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8045AE90: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8045AE94: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8045AE98: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8045AE9C: add.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8045AEA0: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8045AEA4: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8045AEA8: bc1fl       L_8045AEC4
    if (!c1cs) {
        // 0x8045AEAC: swc1        $f14, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f14.u32l;
            goto L_8045AEC4;
    }
    goto skip_5;
    // 0x8045AEAC: swc1        $f14, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f14.u32l;
    skip_5:
    // 0x8045AEB0: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x8045AEB4: lhu         $v0, 0x40($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X40);
    // 0x8045AEB8: b           L_8045AF10
    // 0x8045AEBC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_8045AF10;
    // 0x8045AEBC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x8045AEC0: swc1        $f14, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f14.u32l;
L_8045AEC4:
    // 0x8045AEC4: b           L_8045AF10
    // 0x8045AEC8: lhu         $v0, 0x40($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X40);
        goto L_8045AF10;
    // 0x8045AEC8: lhu         $v0, 0x40($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X40);
L_8045AECC:
    // 0x8045AECC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8045AED0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8045AED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045AED8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8045AEDC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8045AEE0: nop

    // 0x8045AEE4: bc1f        L_8045AEF0
    if (!c1cs) {
        // 0x8045AEE8: nop
    
            goto L_8045AEF0;
    }
    // 0x8045AEE8: nop

    // 0x8045AEEC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8045AEF0:
    // 0x8045AEF0: jal         0x8045B594
    // 0x8045AEF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8045B594(rdram, ctx);
        goto after_9;
    // 0x8045AEF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x8045AEF8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(104, 0XD64) << 16);
    // 0x8045AEFC: lwc1        $f8, -0x488C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0XD64));
    // 0x8045AF00: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8045AF04: lhu         $v0, 0x40($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X40);
    // 0x8045AF08: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8045AF0C: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_8045AF10:
    // 0x8045AF10: lhu         $t4, 0x1C($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X1C);
    // 0x8045AF14: ori         $t6, $v0, 0x1
    ctx->r14 = ctx->r2 | 0X1;
    // 0x8045AF18: andi        $t7, $v0, 0xFFFE
    ctx->r15 = ctx->r2 & 0XFFFE;
    // 0x8045AF1C: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x8045AF20: beql        $t5, $zero, L_8045AF34
    if (ctx->r13 == 0) {
        // 0x8045AF24: sh          $t7, 0x40($s0)
        MEM_H(0X40, ctx->r16) = ctx->r15;
            goto L_8045AF34;
    }
    goto skip_6;
    // 0x8045AF24: sh          $t7, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r15;
    skip_6:
    // 0x8045AF28: b           L_8045AF34
    // 0x8045AF2C: sh          $t6, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r14;
        goto L_8045AF34;
    // 0x8045AF2C: sh          $t6, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r14;
    // 0x8045AF30: sh          $t7, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r15;
L_8045AF34:
    // 0x8045AF34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8045AF38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045AF3C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8045AF40: jr          $ra
    // 0x8045AF44: nop

    return;
    // 0x8045AF44: nop

;}
RECOMP_FUNC void func_8003CE84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CE84: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003CE88: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003CE8C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003CE90: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8003CE94: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8003CE98: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8003CE9C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003CEA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003CEA4: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8003CEA8: lwc1        $f22, 0x174($a1)
    ctx->f22.u32l = MEM_W(ctx->r5, 0X174);
    // 0x8003CEAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003CEB0: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003CEB4: jal         0x80066DE4
    // 0x8003CEB8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8003CEB8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x8003CEBC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8003CEC0: jal         0x80066E88
    // 0x8003CEC4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8003CEC4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x8003CEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003CECC: jal         0x8003CDF0
    // 0x8003CED0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_8003CDF0(rdram, ctx);
        goto after_2;
    // 0x8003CED0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8003CED4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8003CED8: sb          $v0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r2;
    // 0x8003CEDC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8003CEE0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8003CEE4: jal         0x8003CC14
    // 0x8003CEE8: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_8003CC14(rdram, ctx);
        goto after_3;
    // 0x8003CEE8: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_3:
    // 0x8003CEEC: lw          $v0, 0x138($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X138);
    // 0x8003CEF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003CEF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003CEF8: beq         $v0, $zero, L_8003CF18
    if (ctx->r2 == 0) {
        // 0x8003CEFC: lwc1        $f2, 0x38($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8003CF18;
    }
    // 0x8003CEFC: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8003CF00: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003CF04: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    // 0x8003CF08: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8003CF0C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003CF10: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x8003CF14: lw          $v0, 0x138($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X138);
L_8003CF18:
    // 0x8003CF18: mul.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8003CF1C: swc1        $f22, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f22.u32l;
    // 0x8003CF20: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003CF24: mul.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8003CF28: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003CF2C: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x8003CF30: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8003CF34: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003CF38: mul.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8003CF3C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8003CF40: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x8003CF44: beq         $v0, $zero, L_8003CF50
    if (ctx->r2 == 0) {
        // 0x8003CF48: lw          $t7, 0x54($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X54);
            goto L_8003CF50;
    }
    // 0x8003CF48: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8003CF4C: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_8003CF50:
    // 0x8003CF50: lw          $t8, 0x15C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X15C);
    // 0x8003CF54: swc1        $f20, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f20.u32l;
    // 0x8003CF58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003CF5C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003CF60: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8003CF64: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8003CF68: jr          $ra
    // 0x8003CF6C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8003CF6C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_807B5D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B5D4C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807B5D50: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807B5D54: lbu         $t6, 0xF5C($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XF5C);
    // 0x807B5D58: lbu         $t8, 0xF5D($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF5D);
    // 0x807B5D5C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x807B5D60: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B5D64: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B5D68: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x807B5D6C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x807B5D70: or          $s0, $sp, $zero
    ctx->r16 = ctx->r29 | 0;
    // 0x807B5D74: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B5D78: addiu       $s0, $s0, 0x77
    ctx->r16 = ADD32(ctx->r16, 0X77);
    // 0x807B5D7C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x807B5D80: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B5D84: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807B5D88: srl         $s0, $s0, 3
    ctx->r16 = S32(U32(ctx->r16) >> 3);
    // 0x807B5D8C: lui         $s1, 0x8006
    ctx->r17 = S32(0X8006 << 16);
    // 0x807B5D90: lui         $t1, 0x361
    ctx->r9 = S32(0X361 << 16);
    // 0x807B5D94: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x807B5D98: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B5D9C: addiu       $t1, $t1, -0x2570
    ctx->r9 = ADD32(ctx->r9, -0X2570);
    // 0x807B5DA0: addiu       $s1, $s1, 0x758C
    ctx->r17 = ADD32(ctx->r17, 0X758C);
    // 0x807B5DA4: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x807B5DA8: addiu       $t0, $t9, 0x9C0
    ctx->r8 = ADD32(ctx->r25, 0X9C0);
    // 0x807B5DAC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x807B5DB0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x807B5DB4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B5DB8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x807B5DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B5DC0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x807B5DC4: jal         0x800675D0
    // 0x807B5DC8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x807B5DC8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x807B5DCC: or          $s5, $sp, $zero
    ctx->r21 = ctx->r29 | 0;
    // 0x807B5DD0: addiu       $s5, $s5, 0x4B
    ctx->r21 = ADD32(ctx->r21, 0X4B);
    // 0x807B5DD4: srl         $s5, $s5, 3
    ctx->r21 = S32(U32(ctx->r21) >> 3);
    // 0x807B5DD8: sll         $s5, $s5, 3
    ctx->r21 = S32(ctx->r21 << 3);
    // 0x807B5DDC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x807B5DE0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x807B5DE4: lhu         $a2, 0x4($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4);
    // 0x807B5DE8: jal         0x800675D0
    // 0x807B5DEC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x807B5DEC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x807B5DF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B5DF4: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
L_807B5DF8:
    // 0x807B5DF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5DFC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5E00: jal         0x8005C27C
    // 0x807B5E04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x807B5E04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x807B5E08: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5E0C: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B5E10: bnel        $at, $zero, L_807B5DF8
    if (ctx->r1 != 0) {
        // 0x807B5E14: lw          $a0, 0xC($s3)
        ctx->r4 = MEM_W(ctx->r19, 0XC);
            goto L_807B5DF8;
    }
    goto skip_0;
    // 0x807B5E14: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    skip_0:
    // 0x807B5E18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B5E1C: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
L_807B5E20:
    // 0x807B5E20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5E24: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5E28: jal         0x8005C27C
    // 0x807B5E2C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x807B5E2C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_3:
    // 0x807B5E30: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5E34: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B5E38: bnel        $at, $zero, L_807B5E20
    if (ctx->r1 != 0) {
        // 0x807B5E3C: lw          $a0, 0xC($s3)
        ctx->r4 = MEM_W(ctx->r19, 0XC);
            goto L_807B5E20;
    }
    goto skip_1;
    // 0x807B5E3C: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    skip_1:
    // 0x807B5E40: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807B5E44: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B5E48: addiu       $s4, $zero, 0x1000
    ctx->r20 = ADD32(0, 0X1000);
    // 0x807B5E4C: sll         $t2, $s1, 1
    ctx->r10 = S32(ctx->r17 << 1);
L_807B5E50:
    // 0x807B5E50: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x807B5E54: lhu         $s0, 0x0($t3)
    ctx->r16 = MEM_HU(ctx->r11, 0X0);
    // 0x807B5E58: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x807B5E5C: subu        $a2, $s1, $s2
    ctx->r6 = SUB32(ctx->r17, ctx->r18);
    // 0x807B5E60: bne         $s4, $s0, L_807B5E84
    if (ctx->r20 != ctx->r16) {
        // 0x807B5E64: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_807B5E84;
    }
    // 0x807B5E64: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x807B5E68: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x807B5E6C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x807B5E70: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B5E74: jal         0x8005C27C
    // 0x807B5E78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_4;
    // 0x807B5E78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x807B5E7C: b           L_807B5EDC
    // 0x807B5E80: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
        goto L_807B5EDC;
    // 0x807B5E80: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
L_807B5E84:
    // 0x807B5E84: beq         $s2, $zero, L_807B5EAC
    if (ctx->r18 == 0) {
        // 0x807B5E88: andi        $a1, $s0, 0xFFFF
        ctx->r5 = ctx->r16 & 0XFFFF;
            goto L_807B5EAC;
    }
    // 0x807B5E88: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x807B5E8C: subu        $a2, $s1, $s2
    ctx->r6 = SUB32(ctx->r17, ctx->r18);
    // 0x807B5E90: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x807B5E94: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x807B5E98: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B5E9C: jal         0x8005C27C
    // 0x807B5EA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x807B5EA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x807B5EA4: b           L_807B5EE0
    // 0x807B5EA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_807B5EE0;
    // 0x807B5EA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_807B5EAC:
    // 0x807B5EAC: beq         $v0, $zero, L_807B5EDC
    if (ctx->r2 == 0) {
        // 0x807B5EB0: addiu       $a1, $zero, 0x3B
        ctx->r5 = ADD32(0, 0X3B);
            goto L_807B5EDC;
    }
    // 0x807B5EB0: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x807B5EB4: addiu       $s2, $s1, 0x1
    ctx->r18 = ADD32(ctx->r17, 0X1);
    // 0x807B5EB8: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B5EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B5EC0: jal         0x8005C27C
    // 0x807B5EC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x807B5EC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x807B5EC8: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x807B5ECC: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x807B5ED0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x807B5ED4: jal         0x8005C27C
    // 0x807B5ED8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_7;
    // 0x807B5ED8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_807B5EDC:
    // 0x807B5EDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_807B5EE0:
    // 0x807B5EE0: slti        $at, $s1, 0xE
    ctx->r1 = SIGNED(ctx->r17) < 0XE ? 1 : 0;
    // 0x807B5EE4: bnel        $at, $zero, L_807B5E50
    if (ctx->r1 != 0) {
        // 0x807B5EE8: sll         $t2, $s1, 1
        ctx->r10 = S32(ctx->r17 << 1);
            goto L_807B5E50;
    }
    goto skip_2;
    // 0x807B5EE8: sll         $t2, $s1, 1
    ctx->r10 = S32(ctx->r17 << 1);
    skip_2:
    // 0x807B5EEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807B5EF0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B5EF4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B5EF8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B5EFC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B5F00: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x807B5F04: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x807B5F08: jr          $ra
    // 0x807B5F0C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x807B5F0C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8005177C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005177C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051784: lw          $a1, 0x4C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4C);
    // 0x80051788: jal         0x800516D0
    // 0x8005178C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800516D0(rdram, ctx);
        goto after_0;
    // 0x8005178C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80051790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051798: jr          $ra
    // 0x8005179C: nop

    return;
    // 0x8005179C: nop

;}
RECOMP_FUNC void func_804103C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804103C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804103C4: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x804103C8: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x804103CC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x804103D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804103D4: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x804103D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804103DC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x804103E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804103E4: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x804103E8: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x804103EC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804103F0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804103F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804103F8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x804103FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410400: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x80410404: ori         $t3, $t3, 0x2C80
    ctx->r11 = ctx->r11 | 0X2C80;
    // 0x80410408: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8041040C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80410410: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x80410414: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80410418: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8041041C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410420: lui         $a3, 0x55
    ctx->r7 = S32(0X55 << 16);
    // 0x80410424: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x80410428: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8041042C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80410430: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x80410434: ori         $a3, $a3, 0x2048
    ctx->r7 = ctx->r7 | 0X2048;
    // 0x80410438: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8041043C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80410440: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410444: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x80410448: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8041044C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80410450: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80410454: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x80410458: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8041045C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410460: lui         $t0, 0xFFFC
    ctx->r8 = S32(0XFFFC << 16);
    // 0x80410464: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80410468: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8041046C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80410470: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80410474: ori         $t0, $t0, 0xF279
    ctx->r8 = ctx->r8 | 0XF279;
    // 0x80410478: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8041047C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80410480: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80410484: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x80410488: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x8041048C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80410490: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80410494: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80410498: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8041049C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804104A0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x804104A4: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x804104A8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x804104AC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x804104B0: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x804104B4: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x804104B8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x804104BC: jr          $ra
    // 0x804104C0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x804104C0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_8070FB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070FB48: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x8070FB4C: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x8070FB50: lbu         $v1, 0xF5C($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XF5C);
    // 0x8070FB54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070FB58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070FB5C: sltiu       $at, $v1, 0x6
    ctx->r1 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8070FB60: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8070FB64: beq         $at, $zero, L_8070FBC8
    if (ctx->r1 == 0) {
        // 0x8070FB68: lw          $v0, 0xCCC($a2)
        ctx->r2 = MEM_W(ctx->r6, 0XCCC);
            goto L_8070FBC8;
    }
    // 0x8070FB68: lw          $v0, 0xCCC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XCCC);
    // 0x8070FB6C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8070FB70: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(724, 0X1910) << 16);
    // 0x8070FB74: addu        $at, $at, $t6
    gpr jr_addend_8070FB7C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8070FB78: lw          $t6, 0xD00($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(724, 0X1910));
    // 0x8070FB7C: jr          $t6
    // 0x8070FB80: nop

    switch (jr_addend_8070FB7C >> 2) {
        case 0: goto L_8070FB84; break;
        case 1: goto L_8070FB90; break;
        case 2: goto L_8070FB9C; break;
        case 3: goto L_8070FBA8; break;
        case 4: goto L_8070FBB4; break;
        case 5: goto L_8070FBC0; break;
        default: switch_error(__func__, 0x8070FB7C, 0x80710D00);
    }
    // 0x8070FB80: nop

L_8070FB84:
    // 0x8070FB84: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8070FB88: b           L_8070FBC8
    // 0x8070FB8C: sw          $v0, -0x7490($at)
    MEM_W(-0X7490, ctx->r1) = ctx->r2;
        goto L_8070FBC8;
    // 0x8070FB8C: sw          $v0, -0x7490($at)
    MEM_W(-0X7490, ctx->r1) = ctx->r2;
L_8070FB90:
    // 0x8070FB90: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8070FB94: b           L_8070FBC8
    // 0x8070FB98: sw          $v0, -0x748C($at)
    MEM_W(-0X748C, ctx->r1) = ctx->r2;
        goto L_8070FBC8;
    // 0x8070FB98: sw          $v0, -0x748C($at)
    MEM_W(-0X748C, ctx->r1) = ctx->r2;
L_8070FB9C:
    // 0x8070FB9C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8070FBA0: b           L_8070FBC8
    // 0x8070FBA4: sw          $v0, -0x7488($at)
    MEM_W(-0X7488, ctx->r1) = ctx->r2;
        goto L_8070FBC8;
    // 0x8070FBA4: sw          $v0, -0x7488($at)
    MEM_W(-0X7488, ctx->r1) = ctx->r2;
L_8070FBA8:
    // 0x8070FBA8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8070FBAC: b           L_8070FBC8
    // 0x8070FBB0: sw          $v0, -0x7484($at)
    MEM_W(-0X7484, ctx->r1) = ctx->r2;
        goto L_8070FBC8;
    // 0x8070FBB0: sw          $v0, -0x7484($at)
    MEM_W(-0X7484, ctx->r1) = ctx->r2;
L_8070FBB4:
    // 0x8070FBB4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8070FBB8: b           L_8070FBC8
    // 0x8070FBBC: sw          $v0, -0x7480($at)
    MEM_W(-0X7480, ctx->r1) = ctx->r2;
        goto L_8070FBC8;
    // 0x8070FBBC: sw          $v0, -0x7480($at)
    MEM_W(-0X7480, ctx->r1) = ctx->r2;
L_8070FBC0:
    // 0x8070FBC0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8070FBC4: sw          $v0, -0x747C($at)
    MEM_W(-0X747C, ctx->r1) = ctx->r2;
L_8070FBC8:
    // 0x8070FBC8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8070FBCC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8070FBD0: lw          $a1, -0x7490($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7490);
    // 0x8070FBD4: lw          $t7, -0x748C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X748C);
    // 0x8070FBD8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8070FBDC: lw          $t8, -0x7488($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7488);
    // 0x8070FBE0: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8070FBE4: lw          $t9, -0x7484($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7484);
    // 0x8070FBE8: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8070FBEC: lw          $t0, -0x7480($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7480);
    // 0x8070FBF0: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8070FBF4: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8070FBF8: lw          $t1, -0x747C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X747C);
    // 0x8070FBFC: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8070FC00: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8070FC04: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8070FC08: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x8070FC0C: sw          $a1, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r5;
    // 0x8070FC10: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8070FC14: sw          $a1, -0x7474($at)
    MEM_W(-0X7474, ctx->r1) = ctx->r5;
    // 0x8070FC18: jal         0x8070F740
    // 0x8070FC1C: addiu       $a0, $a3, 0x30
    ctx->r4 = ADD32(ctx->r7, 0X30);
    func_8070F740(rdram, ctx);
        goto after_0;
    // 0x8070FC1C: addiu       $a0, $a3, 0x30
    ctx->r4 = ADD32(ctx->r7, 0X30);
    after_0:
    // 0x8070FC20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070FC24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070FC28: jr          $ra
    // 0x8070FC2C: nop

    return;
    // 0x8070FC2C: nop

;}
RECOMP_FUNC void func_80675354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675354: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80675358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067535C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80675360: jal         0x80045A34
    // 0x80675364: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80675364: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80675368: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8067536C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80675370: bne         $v0, $zero, L_80675388
    if (ctx->r2 != 0) {
        // 0x80675374: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_80675388;
    }
    // 0x80675374: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x80675378: jal         0x800445A4
    // 0x8067537C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8067537C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80675380: b           L_806753BC
    // 0x80675384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806753BC;
    // 0x80675384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80675388:
    // 0x80675388: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x8067538C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80675390: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80675394: jal         0x80065728
    // 0x80675398: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x80675398: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8067539C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806753A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x806753A4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x806753A8: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(532, 0X634) << 16);
    // 0x806753AC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806753B0: lwc1        $f4, 0x5584($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(532, 0X634));
    // 0x806753B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806753B8: swc1        $f4, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f4.u32l;
L_806753BC:
    // 0x806753BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806753C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806753C4: jr          $ra
    // 0x806753C8: nop

    return;
    // 0x806753C8: nop

;}
RECOMP_FUNC void func_806CEAFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CEAFC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806CEB00: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(604, 0X31B0) << 16);
    // 0x806CEB04: addiu       $t6, $t6, -0x1730
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(604, 0X31B0));
    // 0x806CEB08: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806CEB0C: jr          $ra
    // 0x806CEB10: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806CEB10: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8073F438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F438: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073F43C: lui         $a1, 0x8074
    ctx->r5 = S32(RELOC_HI16(748, 0X22C4) << 16);
    // 0x8073F440: addiu       $a1, $a1, 0xAB4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(748, 0X22C4));
    // 0x8073F444: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x8073F448: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x8073F44C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8073F450: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8073F454: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8073F458: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x8073F45C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8073F460: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8073F464: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8073F468: bne         $at, $zero, L_8073F488
    if (ctx->r1 != 0) {
        // 0x8073F46C: slti        $at, $t2, 0x8
        ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
            goto L_8073F488;
    }
    // 0x8073F46C: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x8073F470: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8073F474: sw          $t2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r10;
    // 0x8073F478: bne         $at, $zero, L_8073F488
    if (ctx->r1 != 0) {
        // 0x8073F47C: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_8073F488;
    }
    // 0x8073F47C: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x8073F480: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8073F484: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8073F488:
    // 0x8073F488: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x8073F48C: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x8073F490: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8073F494: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(748, 0X1650) << 16);
    // 0x8073F498: addiu       $t7, $t7, -0x1C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(748, 0X1650));
    // 0x8073F49C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8073F4A0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8073F4A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8073F4A8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8073F4AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8073F4B0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8073F4B4: jr          $ra
    // 0x8073F4B8: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    return;
    // 0x8073F4B8: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_804C5B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5B3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C5B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5B44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804C5B48: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804C5B4C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804C5B50: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x804C5B54: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x804C5B58: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804C5B5C: jal         0x80053EE4
    // 0x804C5B60: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    func_80053EE4(rdram, ctx);
        goto after_0;
    // 0x804C5B60: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x804C5B64: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x804C5B68: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x804C5B6C: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x804C5B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C5B74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C5B78: jr          $ra
    // 0x804C5B7C: nop

    return;
    // 0x804C5B7C: nop

;}
RECOMP_FUNC void func_8043DA9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DA9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043DAA0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8043DAA4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8043DAA8: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8043DAAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043DAB0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8043DAB4: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x8043DAB8: bne         $a1, $zero, L_8043DAC8
    if (ctx->r5 != 0) {
        // 0x8043DABC: lwc1        $f2, 0x1FC($t7)
        ctx->f2.u32l = MEM_W(ctx->r15, 0X1FC);
            goto L_8043DAC8;
    }
    // 0x8043DABC: lwc1        $f2, 0x1FC($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X1FC);
    // 0x8043DAC0: b           L_8043DAD4
    // 0x8043DAC4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
        goto L_8043DAD4;
    // 0x8043DAC4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_8043DAC8:
    // 0x8043DAC8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8043DACC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8043DAD0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_8043DAD4:
    // 0x8043DAD4: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x8043DAD8: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8043DADC: lwc1        $f0, 0x1FC($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X1FC);
    // 0x8043DAE0: jal         0x80065954
    // 0x8043DAE4: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8043DAE4: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    after_0:
    // 0x8043DAE8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8043DAEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8043DAF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8043DAF4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8043DAF8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8043DAFC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8043DB00: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8043DB04: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8043DB08: nop

    // 0x8043DB0C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8043DB10: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8043DB14: nop

    // 0x8043DB18: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8043DB1C: beql        $v0, $zero, L_8043DB6C
    if (ctx->r2 == 0) {
        // 0x8043DB20: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_8043DB6C;
    }
    goto skip_0;
    // 0x8043DB20: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x8043DB24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043DB28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8043DB2C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8043DB30: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8043DB34: nop

    // 0x8043DB38: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8043DB3C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8043DB40: nop

    // 0x8043DB44: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8043DB48: bne         $v0, $zero, L_8043DB60
    if (ctx->r2 != 0) {
        // 0x8043DB4C: nop
    
            goto L_8043DB60;
    }
    // 0x8043DB4C: nop

    // 0x8043DB50: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8043DB54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8043DB58: b           L_8043DB78
    // 0x8043DB5C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_8043DB78;
    // 0x8043DB5C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8043DB60:
    // 0x8043DB60: b           L_8043DB78
    // 0x8043DB64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8043DB78;
    // 0x8043DB64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8043DB68: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_8043DB6C:
    // 0x8043DB6C: nop

    // 0x8043DB70: bltz        $v0, L_8043DB60
    if (SIGNED(ctx->r2) < 0) {
        // 0x8043DB74: nop
    
            goto L_8043DB60;
    }
    // 0x8043DB74: nop

L_8043DB78:
    // 0x8043DB78: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8043DB7C: sltiu       $at, $v0, 0x50
    ctx->r1 = ctx->r2 < 0X50 ? 1 : 0;
    // 0x8043DB80: beq         $at, $zero, L_8043DB8C
    if (ctx->r1 == 0) {
        // 0x8043DB84: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8043DB8C;
    }
    // 0x8043DB84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8043DB88: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
L_8043DB8C:
    // 0x8043DB8C: jal         0x8043DA34
    // 0x8043DB90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8043DA34(rdram, ctx);
        goto after_1;
    // 0x8043DB90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8043DB94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8043DB98: sltiu       $at, $a1, 0x4
    ctx->r1 = ctx->r5 < 0X4 ? 1 : 0;
    // 0x8043DB9C: bnel        $at, $zero, L_8043DBB0
    if (ctx->r1 != 0) {
        // 0x8043DBA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043DBB0;
    }
    goto skip_1;
    // 0x8043DBA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8043DBA4: jal         0x8043D618
    // 0x8043DBA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8043D618(rdram, ctx);
        goto after_2;
    // 0x8043DBA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8043DBAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043DBB0:
    // 0x8043DBB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043DBB4: jr          $ra
    // 0x8043DBB8: nop

    return;
    // 0x8043DBB8: nop

;}
RECOMP_FUNC void func_8064B2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B2A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B2A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064B2AC: jal         0x80045A34
    // 0x8064B2B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8064B2B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8064B2B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064B2B8: bne         $v0, $zero, L_8064B2C8
    if (ctx->r2 != 0) {
        // 0x8064B2BC: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8064B2C8;
    }
    // 0x8064B2BC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8064B2C0: b           L_8064B2D4
    // 0x8064B2C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8064B2D4;
    // 0x8064B2C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064B2C8:
    // 0x8064B2C8: jal         0x8064B290
    // 0x8064B2CC: nop

    func_8064B290(rdram, ctx);
        goto after_1;
    // 0x8064B2CC: nop

    after_1:
    // 0x8064B2D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8064B2D4:
    // 0x8064B2D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064B2D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B2DC: jr          $ra
    // 0x8064B2E0: nop

    return;
    // 0x8064B2E0: nop

;}
RECOMP_FUNC void func_80526CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526CE4: jal         0x80527B20
    // 0x80526CE8: nop

    func_80527B20(rdram, ctx);
        goto after_0;
    // 0x80526CE8: nop

    after_0:
    // 0x80526CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80526CF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526CF4: jr          $ra
    // 0x80526CF8: nop

    return;
    // 0x80526CF8: nop

;}
RECOMP_FUNC void func_80518DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80518DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80518DDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80518DE0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80518DE4: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80518DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80518DEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80518DF0: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80518DF4: bne         $a1, $zero, L_80518E04
    if (ctx->r5 != 0) {
        // 0x80518DF8: lwc1        $f2, 0x1FC($t7)
        ctx->f2.u32l = MEM_W(ctx->r15, 0X1FC);
            goto L_80518E04;
    }
    // 0x80518DF8: lwc1        $f2, 0x1FC($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X1FC);
    // 0x80518DFC: b           L_80518E10
    // 0x80518E00: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
        goto L_80518E10;
    // 0x80518E00: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80518E04:
    // 0x80518E04: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80518E08: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80518E0C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_80518E10:
    // 0x80518E10: sll         $t8, $a1, 4
    ctx->r24 = S32(ctx->r5 << 4);
    // 0x80518E14: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80518E18: lwc1        $f0, 0x1FC($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X1FC);
    // 0x80518E1C: jal         0x80065954
    // 0x80518E20: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80518E20: sub.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f0.fl;
    after_0:
    // 0x80518E24: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80518E28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80518E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80518E30: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80518E34: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80518E38: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80518E3C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80518E40: nop

    // 0x80518E44: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80518E48: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80518E4C: nop

    // 0x80518E50: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80518E54: beql        $v0, $zero, L_80518EA4
    if (ctx->r2 == 0) {
        // 0x80518E58: mfc1        $v0, $f8
        ctx->r2 = (int32_t)ctx->f8.u32l;
            goto L_80518EA4;
    }
    goto skip_0;
    // 0x80518E58: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80518E5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80518E60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80518E64: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80518E68: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80518E6C: nop

    // 0x80518E70: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80518E74: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80518E78: nop

    // 0x80518E7C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80518E80: bne         $v0, $zero, L_80518E98
    if (ctx->r2 != 0) {
        // 0x80518E84: nop
    
            goto L_80518E98;
    }
    // 0x80518E84: nop

    // 0x80518E88: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80518E8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80518E90: b           L_80518EB0
    // 0x80518E94: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80518EB0;
    // 0x80518E94: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80518E98:
    // 0x80518E98: b           L_80518EB0
    // 0x80518E9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80518EB0;
    // 0x80518E9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80518EA0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
L_80518EA4:
    // 0x80518EA4: nop

    // 0x80518EA8: bltz        $v0, L_80518E98
    if (SIGNED(ctx->r2) < 0) {
        // 0x80518EAC: nop
    
            goto L_80518E98;
    }
    // 0x80518EAC: nop

L_80518EB0:
    // 0x80518EB0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80518EB4: sltiu       $at, $v0, 0x50
    ctx->r1 = ctx->r2 < 0X50 ? 1 : 0;
    // 0x80518EB8: beq         $at, $zero, L_80518EC4
    if (ctx->r1 == 0) {
        // 0x80518EBC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80518EC4;
    }
    // 0x80518EBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80518EC0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
L_80518EC4:
    // 0x80518EC4: jal         0x80518D68
    // 0x80518EC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80518D68(rdram, ctx);
        goto after_1;
    // 0x80518EC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80518ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80518ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80518ED4: jr          $ra
    // 0x80518ED8: nop

    return;
    // 0x80518ED8: nop

;}
RECOMP_FUNC void func_80665664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665664: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80665668: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8066566C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80665670: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80665674: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80665678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066567C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80665680: beq         $v0, $zero, L_80665690
    if (ctx->r2 == 0) {
        // 0x80665684: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80665690;
    }
    // 0x80665684: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80665688: b           L_806656A8
    // 0x8066568C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_806656A8;
    // 0x8066568C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_80665690:
    // 0x80665690: jal         0x8066622C
    // 0x80665694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8066622C(rdram, ctx);
        goto after_0;
    // 0x80665694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80665698: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066569C: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x806656A0: jal         0x80664D40
    // 0x806656A4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    func_80664D40(rdram, ctx);
        goto after_1;
    // 0x806656A4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    after_1:
L_806656A8:
    // 0x806656A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806656AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806656B0: jr          $ra
    // 0x806656B4: nop

    return;
    // 0x806656B4: nop

;}
RECOMP_FUNC void func_804F54F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F54F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804F54F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804F54FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804F5500: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F5504: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x804F5508: lw          $t7, -0x6DA8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6DA8);
    // 0x804F550C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x804F5510: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804F5514: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804F5518: jal         0x804F4F50
    // 0x804F551C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    func_804F4F50(rdram, ctx);
        goto after_0;
    // 0x804F551C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_0:
    // 0x804F5520: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x804F5524: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804F5528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F552C: lwc1        $f2, 0x4C($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x804F5530: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804F5534: nop

    // 0x804F5538: bc1fl       L_804F5584
    if (!c1cs) {
        // 0x804F553C: swc1        $f0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
            goto L_804F5584;
    }
    goto skip_0;
    // 0x804F553C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x804F5540: jal         0x804F5598
    // 0x804F5544: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    func_804F5598(rdram, ctx);
        goto after_1;
    // 0x804F5544: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x804F5548: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x804F554C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804F5550: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x804F5554: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x804F5558: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x804F555C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x804F5560: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x804F5564: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804F5568: lw          $v0, 0x1F4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X1F4);
    // 0x804F556C: lw          $t9, 0x1164($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1164);
    // 0x804F5570: addiu       $a0, $v0, 0x1150
    ctx->r4 = ADD32(ctx->r2, 0X1150);
    // 0x804F5574: jalr        $t9
    // 0x804F5578: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x804F5578: nop

    after_2:
    // 0x804F557C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804F5580: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
L_804F5584:
    // 0x804F5584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804F5588: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804F558C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804F5590: jr          $ra
    // 0x804F5594: nop

    return;
    // 0x804F5594: nop

;}
RECOMP_FUNC void func_804BD76C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD76C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BD770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD774: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41A4) << 16);
    // 0x804BD778: lwc1        $f4, -0x52C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41A4));
    // 0x804BD77C: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x804BD780: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BD784: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41A8) << 16);
    // 0x804BD788: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804BD78C: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BD790: bc1t        L_804BD81C
    if (c1cs) {
        // 0x804BD794: lw          $a1, 0x370($t7)
        ctx->r5 = MEM_W(ctx->r15, 0X370);
            goto L_804BD81C;
    }
    // 0x804BD794: lw          $a1, 0x370($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X370);
    // 0x804BD798: lwc1        $f6, -0x528($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41A8));
    // 0x804BD79C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804BD7A0: nop

    // 0x804BD7A4: bc1tl       L_804BD820
    if (c1cs) {
        // 0x804BD7A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BD820;
    }
    goto skip_0;
    // 0x804BD7A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BD7AC: lh          $t8, 0x2E($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2E);
    // 0x804BD7B0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x804BD7B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804BD7B8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x804BD7BC: sh          $t9, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r25;
    // 0x804BD7C0: lh          $v0, 0x2E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2E);
    // 0x804BD7C4: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x804BD7C8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x804BD7CC: bnel        $at, $zero, L_804BD80C
    if (ctx->r1 != 0) {
        // 0x804BD7D0: sll         $t1, $v0, 1
        ctx->r9 = S32(ctx->r2 << 1);
            goto L_804BD80C;
    }
    goto skip_1;
    // 0x804BD7D0: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    skip_1:
    // 0x804BD7D4: lh          $v1, 0x30($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X30);
    // 0x804BD7D8: sh          $zero, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = 0;
    // 0x804BD7DC: bne         $v1, $zero, L_804BD800
    if (ctx->r3 != 0) {
        // 0x804BD7E0: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_804BD800;
    }
    // 0x804BD7E0: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x804BD7E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804BD7E8: jal         0x804BD6D8
    // 0x804BD7EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_804BD6D8(rdram, ctx);
        goto after_0;
    // 0x804BD7EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x804BD7F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804BD7F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x804BD7F8: b           L_804BD808
    // 0x804BD7FC: lh          $v0, 0x2E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2E);
        goto L_804BD808;
    // 0x804BD7FC: lh          $v0, 0x2E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2E);
L_804BD800:
    // 0x804BD800: sh          $t0, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r8;
    // 0x804BD804: lh          $v0, 0x2E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2E);
L_804BD808:
    // 0x804BD808: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
L_804BD80C:
    // 0x804BD80C: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(191, 0X3DA0) << 16);
    // 0x804BD810: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804BD814: lh          $t2, -0x930($t2)
    ctx->r10 = MEM_H(ctx->r10, (int16_t)RELOC_LO16(191, 0X3DA0));
    // 0x804BD818: sh          $t2, 0x144($a1)
    MEM_H(0X144, ctx->r5) = ctx->r10;
L_804BD81C:
    // 0x804BD81C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BD820:
    // 0x804BD820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BD824: jr          $ra
    // 0x804BD828: nop

    return;
    // 0x804BD828: nop

;}
RECOMP_FUNC void func_80666418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80666418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066641C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80666420: jal         0x8005FCA8
    // 0x80666424: nop

    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x80666424: nop

    after_0:
    // 0x80666428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066642C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80666430: jr          $ra
    // 0x80666434: nop

    return;
    // 0x80666434: nop

;}
RECOMP_FUNC void func_804CE408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE408: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CE40C: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x804CE410: jr          $ra
    // 0x804CE414: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    return;
    // 0x804CE414: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_800340DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800340DC: lbu         $t6, 0xF4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XF4);
    // 0x800340E0: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x800340E4: beq         $t6, $zero, L_800340F0
    if (ctx->r14 == 0) {
        // 0x800340E8: nop
    
            goto L_800340F0;
    }
    // 0x800340E8: nop

    // 0x800340EC: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
L_800340F0:
    // 0x800340F0: jr          $ra
    // 0x800340F4: nop

    return;
    // 0x800340F4: nop

;}
RECOMP_FUNC void func_807158D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807158D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807158D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807158D8: jal         0x80715864
    // 0x807158DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80715864(rdram, ctx);
        goto after_0;
    // 0x807158DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807158E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807158E4: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(730, 0X1550) << 16);
    // 0x807158E8: addiu       $t6, $t6, 0x5D70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(730, 0X1550));
    // 0x807158EC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807158F0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807158F4: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x807158F8: sw          $t6, 0x5F8($v0)
    MEM_W(0X5F8, ctx->r2) = ctx->r14;
    // 0x807158FC: sh          $t7, 0x5FC($v0)
    MEM_H(0X5FC, ctx->r2) = ctx->r15;
    // 0x80715900: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80715904: addiu       $at, $zero, 0x4621
    ctx->r1 = ADD32(0, 0X4621);
    // 0x80715908: beq         $v1, $at, L_80715920
    if (ctx->r3 == ctx->r1) {
        // 0x8071590C: addiu       $at, $zero, 0x4622
        ctx->r1 = ADD32(0, 0X4622);
            goto L_80715920;
    }
    // 0x8071590C: addiu       $at, $zero, 0x4622
    ctx->r1 = ADD32(0, 0X4622);
    // 0x80715910: beq         $v1, $at, L_80715928
    if (ctx->r3 == ctx->r1) {
        // 0x80715914: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_80715928;
    }
    // 0x80715914: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80715918: b           L_80715930
    // 0x8071591C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80715930;
    // 0x8071591C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80715920:
    // 0x80715920: b           L_8071592C
    // 0x80715924: sw          $zero, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = 0;
        goto L_8071592C;
    // 0x80715924: sw          $zero, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = 0;
L_80715928:
    // 0x80715928: sw          $t8, 0x5EC($v0)
    MEM_W(0X5EC, ctx->r2) = ctx->r24;
L_8071592C:
    // 0x8071592C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80715930:
    // 0x80715930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715934: jr          $ra
    // 0x80715938: nop

    return;
    // 0x80715938: nop

;}
RECOMP_FUNC void func_80567AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567AC4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80567AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80567ACC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80567AD0: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80567AD4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2184) << 16);
    // 0x80567AD8: lwc1        $f10, -0x68CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2184));
    // 0x80567ADC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80567AE0: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80567AE4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2188) << 16);
    // 0x80567AE8: lwc1        $f4, -0x68C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2188));
    // 0x80567AEC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80567AF0: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80567AF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80567AF8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80567AFC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80567B00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80567B04: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80567B08: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80567B0C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80567B10: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80567B14: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80567B18: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80567B1C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80567B20: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80567B24: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80567B28: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80567B2C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80567B30: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80567B34: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80567B38: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80567B3C: jalr        $t9
    // 0x80567B40: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80567B40: nop

    after_0:
    // 0x80567B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80567B48: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80567B4C: jr          $ra
    // 0x80567B50: nop

    return;
    // 0x80567B50: nop

;}
RECOMP_FUNC void func_8044260C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044260C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80442610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80442614: jal         0x80442444
    // 0x80442618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80442444(rdram, ctx);
        goto after_0;
    // 0x80442618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8044261C: jal         0x804423F4
    // 0x80442620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804423F4(rdram, ctx);
        goto after_1;
    // 0x80442620: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80442624: jal         0x80442478
    // 0x80442628: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80442478(rdram, ctx);
        goto after_2;
    // 0x80442628: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8044262C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80442630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80442634: jr          $ra
    // 0x80442638: nop

    return;
    // 0x80442638: nop

;}
RECOMP_FUNC void func_8003449C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003449C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800344A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800344A4: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800344A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800344AC: jal         0x800340F8
    // 0x800344B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800340F8(rdram, ctx);
        goto after_0;
    // 0x800344B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800344B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800344B8: beq         $v0, $zero, L_800344C8
    if (ctx->r2 == 0) {
        // 0x800344BC: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800344C8;
    }
    // 0x800344BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800344C0: b           L_80034560
    // 0x800344C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034560;
    // 0x800344C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800344C8:
    // 0x800344C8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800344CC: lbu         $t6, -0x766B($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X766B);
    // 0x800344D0: bnel        $t6, $zero, L_800344EC
    if (ctx->r14 != 0) {
        // 0x800344D4: lw          $t7, 0x174($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X174);
            goto L_800344EC;
    }
    goto skip_0;
    // 0x800344D4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    skip_0:
    // 0x800344D8: jal         0x8002DB78
    // 0x800344DC: nop

    func_8002DB78(rdram, ctx);
        goto after_1;
    // 0x800344DC: nop

    after_1:
    // 0x800344E0: b           L_80034560
    // 0x800344E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034560;
    // 0x800344E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800344E8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
L_800344EC:
    // 0x800344EC: lbu         $t8, 0x12($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X12);
    // 0x800344F0: beql        $t8, $zero, L_80034528
    if (ctx->r24 == 0) {
        // 0x800344F4: lw          $t9, 0x24($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X24);
            goto L_80034528;
    }
    goto skip_1;
    // 0x800344F4: lw          $t9, 0x24($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X24);
    skip_1:
    // 0x800344F8: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x800344FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80034500: nop

    // 0x80034504: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80034508: nop

    // 0x8003450C: bc1fl       L_80034528
    if (!c1cs) {
        // 0x80034510: lw          $t9, 0x24($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X24);
            goto L_80034528;
    }
    goto skip_2;
    // 0x80034510: lw          $t9, 0x24($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X24);
    skip_2:
    // 0x80034514: jal         0x8002F1D4
    // 0x80034518: nop

    func_8002F1D4(rdram, ctx);
        goto after_2;
    // 0x80034518: nop

    after_2:
    // 0x8003451C: b           L_80034560
    // 0x80034520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80034560;
    // 0x80034520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034524: lw          $t9, 0x24($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X24);
L_80034528:
    // 0x80034528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003452C: beq         $t9, $zero, L_80034560
    if (ctx->r25 == 0) {
        // 0x80034530: nop
    
            goto L_80034560;
    }
    // 0x80034530: nop

    // 0x80034534: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80034538: jal         0x8002DB78
    // 0x8003453C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8002DB78(rdram, ctx);
        goto after_3;
    // 0x8003453C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x80034540: jal         0x80034160
    // 0x80034544: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80034160(rdram, ctx);
        goto after_4;
    // 0x80034544: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80034548: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8003454C: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
    // 0x80034550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034554: sb          $zero, 0xF7($a1)
    MEM_B(0XF7, ctx->r5) = 0;
    // 0x80034558: b           L_80034560
    // 0x8003455C: sw          $t0, 0xF8($a1)
    MEM_W(0XF8, ctx->r5) = ctx->r8;
        goto L_80034560;
    // 0x8003455C: sw          $t0, 0xF8($a1)
    MEM_W(0XF8, ctx->r5) = ctx->r8;
L_80034560:
    // 0x80034560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034564: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80034568: jr          $ra
    // 0x8003456C: nop

    return;
    // 0x8003456C: nop

;}
RECOMP_FUNC void func_8051B3BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051B3BC: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x8051B3C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8051B3C4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8051B3C8: sltiu       $at, $t7, 0x4
    ctx->r1 = ctx->r15 < 0X4 ? 1 : 0;
    // 0x8051B3CC: bne         $at, $zero, L_8051B3FC
    if (ctx->r1 != 0) {
        // 0x8051B3D0: sw          $t7, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r15;
            goto L_8051B3FC;
    }
    // 0x8051B3D0: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x8051B3D4: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x8051B3D8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8051B3DC: sh          $t0, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r8;
    // 0x8051B3E0: lh          $t1, 0x144($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X144);
    // 0x8051B3E4: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x8051B3E8: bnel        $at, $zero, L_8051B3FC
    if (ctx->r1 != 0) {
        // 0x8051B3EC: sw          $zero, 0x154($a0)
        MEM_W(0X154, ctx->r4) = 0;
            goto L_8051B3FC;
    }
    goto skip_0;
    // 0x8051B3EC: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    skip_0:
    // 0x8051B3F0: jr          $ra
    // 0x8051B3F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8051B3F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8051B3F8: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
L_8051B3FC:
    // 0x8051B3FC: jr          $ra
    // 0x8051B400: nop

    return;
    // 0x8051B400: nop

;}
RECOMP_FUNC void func_80427B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427B1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80427B20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80427B24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80427B28: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80427B2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80427B30: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80427B34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80427B38: jal         0x80065954
    // 0x80427B3C: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80427B3C: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    after_0:
    // 0x80427B40: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80427B44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80427B48: nop

    // 0x80427B4C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80427B50: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80427B54: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80427B58: nop

    // 0x80427B5C: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x80427B60: bnel        $at, $zero, L_80427B70
    if (ctx->r1 != 0) {
        // 0x80427B64: lh          $t7, 0x1F0($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X1F0);
            goto L_80427B70;
    }
    goto skip_0;
    // 0x80427B64: lh          $t7, 0x1F0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1F0);
    skip_0:
    // 0x80427B68: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x80427B6C: lh          $t7, 0x1F0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1F0);
L_80427B70:
    // 0x80427B70: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80427B74: bne         $t7, $at, L_80427BAC
    if (ctx->r15 != ctx->r1) {
        // 0x80427B78: nop
    
            goto L_80427BAC;
    }
    // 0x80427B78: nop

    // 0x80427B7C: jal         0x8001D770
    // 0x80427B80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80427B80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80427B84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80427B88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80427B8C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80427B90: jal         0x80067D94
    // 0x80427B94: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067D94(rdram, ctx);
        goto after_2;
    // 0x80427B94: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80427B98: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x80427B9C: jal         0x80067F78
    // 0x80427BA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_3;
    // 0x80427BA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80427BA4: b           L_80427BD8
    // 0x80427BA8: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80427BD8;
    // 0x80427BA8: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_80427BAC:
    // 0x80427BAC: jal         0x8001D770
    // 0x80427BB0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x80427BB0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x80427BB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80427BB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80427BBC: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80427BC0: jal         0x80067D94
    // 0x80427BC4: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067D94(rdram, ctx);
        goto after_5;
    // 0x80427BC4: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80427BC8: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x80427BCC: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80427BD0: jal         0x800678F0
    // 0x80427BD4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x80427BD4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_80427BD8:
    // 0x80427BD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80427BDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80427BE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80427BE4: jr          $ra
    // 0x80427BE8: nop

    return;
    // 0x80427BE8: nop

;}
RECOMP_FUNC void func_800426F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800426F8: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800426FC: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x80042700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042708: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004270C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x80042710: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80042714: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80042718: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8004271C: bnel        $t8, $at, L_80042784
    if (ctx->r24 != ctx->r1) {
        // 0x80042720: lw          $t1, 0x14($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X14);
            goto L_80042784;
    }
    goto skip_0;
    // 0x80042720: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    skip_0:
    // 0x80042724: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80042728: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004272C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042730: bnel        $t9, $at, L_80042768
    if (ctx->r25 != ctx->r1) {
        // 0x80042734: lui         $at, 0x43A0
        ctx->r1 = S32(0X43A0 << 16);
            goto L_80042768;
    }
    goto skip_1;
    // 0x80042734: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    skip_1:
    // 0x80042738: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x8004273C: jal         0x80067930
    // 0x80042740: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80042740: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_0:
    // 0x80042744: beq         $v0, $zero, L_80042754
    if (ctx->r2 == 0) {
        // 0x80042748: addiu       $a0, $zero, 0x3D
        ctx->r4 = ADD32(0, 0X3D);
            goto L_80042754;
    }
    // 0x80042748: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x8004274C: jal         0x80067878
    // 0x80042750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80042750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80042754:
    // 0x80042754: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80042758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004275C: jal         0x80067838
    // 0x80042760: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80067838(rdram, ctx);
        goto after_2;
    // 0x80042760: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80042764: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
L_80042768:
    // 0x80042768: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004276C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80042770: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80042774: sh          $t0, 0x14A($s0)
    MEM_H(0X14A, ctx->r16) = ctx->r8;
    // 0x80042778: b           L_800427C4
    // 0x8004277C: swc1        $f4, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f4.u32l;
        goto L_800427C4;
    // 0x8004277C: swc1        $f4, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f4.u32l;
    // 0x80042780: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
L_80042784:
    // 0x80042784: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80042788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004278C: bnel        $t1, $zero, L_800427C0
    if (ctx->r9 != 0) {
        // 0x80042790: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800427C0;
    }
    goto skip_2;
    // 0x80042790: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_2:
    // 0x80042794: jal         0x80067930
    // 0x80042798: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    func_80067930(rdram, ctx);
        goto after_3;
    // 0x80042798: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    after_3:
    // 0x8004279C: beq         $v0, $zero, L_800427AC
    if (ctx->r2 == 0) {
        // 0x800427A0: addiu       $a0, $zero, 0x3C
        ctx->r4 = ADD32(0, 0X3C);
            goto L_800427AC;
    }
    // 0x800427A0: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800427A4: jal         0x80067878
    // 0x800427A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_4;
    // 0x800427A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_800427AC:
    // 0x800427AC: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x800427B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800427B4: jal         0x80067838
    // 0x800427B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80067838(rdram, ctx);
        goto after_5;
    // 0x800427B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x800427BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800427C0:
    // 0x800427C0: sw          $t2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r10;
L_800427C4:
    // 0x800427C4: lw          $t3, 0x18($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X18);
    // 0x800427C8: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x800427CC: beql        $t3, $zero, L_8004280C
    if (ctx->r11 == 0) {
        // 0x800427D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004280C;
    }
    goto skip_3;
    // 0x800427D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800427D4: jal         0x80067930
    // 0x800427D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_6;
    // 0x800427D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800427DC: beq         $v0, $zero, L_800427EC
    if (ctx->r2 == 0) {
        // 0x800427E0: addiu       $a0, $zero, 0x3D
        ctx->r4 = ADD32(0, 0X3D);
            goto L_800427EC;
    }
    // 0x800427E0: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x800427E4: jal         0x80067878
    // 0x800427E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_7;
    // 0x800427E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_800427EC:
    // 0x800427EC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800427F0: jal         0x80067930
    // 0x800427F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_8;
    // 0x800427F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800427F8: beq         $v0, $zero, L_80042808
    if (ctx->r2 == 0) {
        // 0x800427FC: addiu       $a0, $zero, 0x3C
        ctx->r4 = ADD32(0, 0X3C);
            goto L_80042808;
    }
    // 0x800427FC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80042800: jal         0x80067878
    // 0x80042804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_9;
    // 0x80042804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
L_80042808:
    // 0x80042808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004280C:
    // 0x8004280C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80042810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042814: jr          $ra
    // 0x80042818: nop

    return;
    // 0x80042818: nop

;}
RECOMP_FUNC void func_80441788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441788: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044178C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80441790: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80441794: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80441798: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8044179C: jal         0x8043F33C
    // 0x804417A0: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8043F33C(rdram, ctx);
        goto after_0;
    // 0x804417A0: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x804417A4: jal         0x8043FDF0
    // 0x804417A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FDF0(rdram, ctx);
        goto after_1;
    // 0x804417A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804417AC: jal         0x8043F150
    // 0x804417B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_2;
    // 0x804417B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804417B4: jal         0x8044045C
    // 0x804417B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044045C(rdram, ctx);
        goto after_3;
    // 0x804417B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804417BC: lw          $t6, 0x2628($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2628);
    // 0x804417C0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x804417C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804417C8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x804417CC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x804417D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804417D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804417D8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804417DC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804417E0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804417E4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x804417E8: nop

    // 0x804417EC: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x804417F0: bne         $at, $zero, L_804417FC
    if (ctx->r1 != 0) {
        // 0x804417F4: nop
    
            goto L_804417FC;
    }
    // 0x804417F4: nop

    // 0x804417F8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
L_804417FC:
    // 0x804417FC: jal         0x8043EF80
    // 0x80441800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043EF80(rdram, ctx);
        goto after_4;
    // 0x80441800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80441804: jal         0x8043F360
    // 0x80441808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F360(rdram, ctx);
        goto after_5;
    // 0x80441808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8044180C: beq         $v0, $zero, L_80441840
    if (ctx->r2 == 0) {
        // 0x80441810: nop
    
            goto L_80441840;
    }
    // 0x80441810: nop

    // 0x80441814: jal         0x80440950
    // 0x80441818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80440950(rdram, ctx);
        goto after_6;
    // 0x80441818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8044181C: lw          $t8, 0x2628($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2628);
    // 0x80441820: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80441824: slti        $at, $t9, 0x3D
    ctx->r1 = SIGNED(ctx->r25) < 0X3D ? 1 : 0;
    // 0x80441828: bne         $at, $zero, L_80441848
    if (ctx->r1 != 0) {
        // 0x8044182C: sw          $t9, 0x2628($s1)
        MEM_W(0X2628, ctx->r17) = ctx->r25;
            goto L_80441848;
    }
    // 0x8044182C: sw          $t9, 0x2628($s1)
    MEM_W(0X2628, ctx->r17) = ctx->r25;
    // 0x80441830: jal         0x8043F780
    // 0x80441834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F780(rdram, ctx);
        goto after_7;
    // 0x80441834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80441838: b           L_8044184C
    // 0x8044183C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8044184C;
    // 0x8044183C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441840:
    // 0x80441840: jal         0x8043F93C
    // 0x80441844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_8;
    // 0x80441844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80441848:
    // 0x80441848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8044184C:
    // 0x8044184C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80441850: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80441854: jr          $ra
    // 0x80441858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80441858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80067C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067C70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067C74: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067C78: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80067C7C: jal         0x80067BBC
    // 0x80067C80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80067C80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80067C84: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80067C88: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067C8C: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067C90: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80067C94: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80067C98: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80067C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067CA4: jr          $ra
    // 0x80067CA8: nop

    return;
    // 0x80067CA8: nop

;}
RECOMP_FUNC void func_80580BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580BA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80580BAC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80580BB0: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80580BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580BB8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80580BBC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80580BC0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80580BC4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80580BC8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80580BCC: lui         $t2, 0x8058
    ctx->r10 = S32(RELOC_HI16(399, 0X460C) << 16);
    // 0x80580BD0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80580BD4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80580BD8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80580BDC: lw          $t2, 0x341C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(399, 0X460C));
    // 0x80580BE0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80580BE4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80580BE8: jal         0x80580A18
    // 0x80580BEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580A18(rdram, ctx);
        goto after_0;
    // 0x80580BEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80580BF0: jal         0x80580A74
    // 0x80580BF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80580A74(rdram, ctx);
        goto after_1;
    // 0x80580BF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80580BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580C00: jr          $ra
    // 0x80580C04: nop

    return;
    // 0x80580C04: nop

;}
RECOMP_FUNC void func_80568708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568708: jr          $ra
    // 0x8056870C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8056870C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806E6F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E6F88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E6F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E6F90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806E6F94: jal         0x80045A34
    // 0x806E6F98: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806E6F98: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x806E6F9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E6FA0: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(658, 0X1B0) << 16);
    // 0x806E6FA4: bne         $v0, $zero, L_806E6FBC
    if (ctx->r2 != 0) {
        // 0x806E6FA8: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806E6FBC;
    }
    // 0x806E6FA8: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806E6FAC: jal         0x800445A4
    // 0x806E6FB0: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806E6FB0: nop

    after_1:
    // 0x806E6FB4: b           L_806E7004
    // 0x806E6FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806E7004;
    // 0x806E6FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E6FBC:
    // 0x806E6FBC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806E6FC0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806E6FC4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806E6FC8: addiu       $t6, $t6, 0x7050
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(658, 0X1B0));
    // 0x806E6FCC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806E6FD0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E6FD4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806E6FD8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x806E6FDC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806E6FE0: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x806E6FE4: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806E6FE8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x806E6FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E6FF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806E6FF4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806E6FF8: jal         0x806E7010
    // 0x806E6FFC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    func_806E7010(rdram, ctx);
        goto after_2;
    // 0x806E6FFC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    after_2:
    // 0x806E7000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E7004:
    // 0x806E7004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E7008: jr          $ra
    // 0x806E700C: nop

    return;
    // 0x806E700C: nop

;}
RECOMP_FUNC void func_80460ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460ACC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80460AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460AD4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80460AD8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80460ADC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80460AE0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80460AE4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80460AE8: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80460AEC: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80460AF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80460AF4: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80460AF8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80460AFC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80460B00: jal         0x80081E8C
    // 0x80460B04: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    fatan2(rdram, ctx);
        goto after_0;
    // 0x80460B04: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80460B08: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80460B0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80460B10: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39D4) << 16);
    // 0x80460B14: lwc1        $f8, 0x3F64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39D4));
    // 0x80460B18: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80460B1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80460B20: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80460B24: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x80460B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460B2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80460B30: jr          $ra
    // 0x80460B34: nop

    return;
    // 0x80460B34: nop

;}
RECOMP_FUNC void func_80557D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80557D44: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80557D48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80557D4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80557D50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80557D54: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80557D58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80557D5C: jal         0x80062AEC
    // 0x80557D60: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x80557D60: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80557D64: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80557D68: lhu         $t6, 0xC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC);
    // 0x80557D6C: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80557D70: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80557D74: bne         $t6, $at, L_80557E78
    if (ctx->r14 != ctx->r1) {
        // 0x80557D78: addiu       $t7, $zero, 0x50
        ctx->r15 = ADD32(0, 0X50);
            goto L_80557E78;
    }
    // 0x80557D78: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80557D7C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80557D80: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x80557D84: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80557D88: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80557D8C: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x80557D90: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80557D94: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80557D98: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x80557D9C: lw          $t1, 0x180($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X180);
    // 0x80557DA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80557DA4: lw          $a3, 0x1F4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X1F4);
    // 0x80557DA8: lw          $t2, 0x30($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X30);
    // 0x80557DAC: bnel        $t2, $zero, L_80557ECC
    if (ctx->r10 != 0) {
        // 0x80557DB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80557ECC;
    }
    goto skip_0;
    // 0x80557DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80557DB4: beq         $v0, $v1, L_80557DC0
    if (ctx->r2 == ctx->r3) {
        // 0x80557DB8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80557DC0;
    }
    // 0x80557DB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80557DBC: bne         $v0, $at, L_80557E78
    if (ctx->r2 != ctx->r1) {
        // 0x80557DC0: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80557E78;
    }
L_80557DC0:
    // 0x80557DC0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80557DC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80557DC8: sw          $v1, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r3;
    // 0x80557DCC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80557DD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80557DD4: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80557DD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80557DDC: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80557DE0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80557DE4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80557DE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80557DEC: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
    // 0x80557DF0: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    // 0x80557DF4: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    // 0x80557DF8: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x80557DFC: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x80557E00: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x80557E04: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80557E08: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80557E0C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80557E10: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80557E14: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80557E18: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x80557E1C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80557E20: lw          $t9, 0x18($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X18);
    // 0x80557E24: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x80557E28: jalr        $t9
    // 0x80557E2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80557E2C: nop

    after_1:
    // 0x80557E30: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80557E34: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80557E38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80557E3C: lw          $v1, 0x24($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X24);
    // 0x80557E40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80557E44: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80557E48: beq         $at, $zero, L_80557E70
    if (ctx->r1 == 0) {
        // 0x80557E4C: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_80557E70;
    }
    // 0x80557E4C: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x80557E50: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x80557E54: sh          $t6, 0x144($t0)
    MEM_H(0X144, ctx->r8) = ctx->r14;
    // 0x80557E58: lw          $a0, 0x180($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X180);
    // 0x80557E5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80557E60: jal         0x80559928
    // 0x80557E64: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80559928(rdram, ctx);
        goto after_2;
    // 0x80557E64: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_2:
    // 0x80557E68: b           L_80557E7C
    // 0x80557E6C: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
        goto L_80557E7C;
    // 0x80557E6C: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
L_80557E70:
    // 0x80557E70: jal         0x80559928
    // 0x80557E74: lw          $a0, 0x180($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X180);
    func_80559928(rdram, ctx);
        goto after_3;
    // 0x80557E74: lw          $a0, 0x180($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X180);
    after_3:
L_80557E78:
    // 0x80557E78: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
L_80557E7C:
    // 0x80557E7C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80557E80: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80557E84: bne         $t7, $at, L_80557EC8
    if (ctx->r15 != ctx->r1) {
        // 0x80557E88: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_80557EC8;
    }
    // 0x80557E88: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80557E8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80557E90: beq         $t8, $at, L_80557EC8
    if (ctx->r24 == ctx->r1) {
        // 0x80557E94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80557EC8;
    }
    // 0x80557E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80557E98: beq         $t8, $v1, L_80557EB0
    if (ctx->r24 == ctx->r3) {
        // 0x80557E9C: lui         $a2, 0xC020
        ctx->r6 = S32(0XC020 << 16);
            goto L_80557EB0;
    }
    // 0x80557E9C: lui         $a2, 0xC020
    ctx->r6 = S32(0XC020 << 16);
    // 0x80557EA0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80557EA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80557EA8: b           L_80557EC0
    // 0x80557EAC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_80557EC0;
    // 0x80557EAC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80557EB0:
    // 0x80557EB0: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80557EB4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80557EB8: nop

    // 0x80557EBC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80557EC0:
    // 0x80557EC0: jal         0x8002F96C
    // 0x80557EC4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8002F96C(rdram, ctx);
        goto after_4;
    // 0x80557EC4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_4:
L_80557EC8:
    // 0x80557EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80557ECC:
    // 0x80557ECC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80557ED0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80557ED4: jr          $ra
    // 0x80557ED8: nop

    return;
    // 0x80557ED8: nop

;}
RECOMP_FUNC void func_8064F354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F354: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064F358: slti        $at, $a0, 0xB4
    ctx->r1 = SIGNED(ctx->r4) < 0XB4 ? 1 : 0;
    // 0x8064F35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064F360: beq         $at, $zero, L_8064F378
    if (ctx->r1 == 0) {
        // 0x8064F364: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8064F378;
    }
    // 0x8064F364: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8064F368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064F36C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8064F370: b           L_8064F3C0
    // 0x8064F374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8064F3C0;
    // 0x8064F374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064F378:
    // 0x8064F378: jal         0x80066DE4
    // 0x8064F37C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8064F37C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8064F380: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8064F384: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064F388: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8064F38C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8064F390: jal         0x80066E88
    // 0x8064F394: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8064F394: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x8064F398: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(501, 0X15D50) << 16);
    // 0x8064F39C: lwc1        $f8, 0x4750($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(501, 0X15D50));
    // 0x8064F3A0: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8064F3A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064F3A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064F3AC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8064F3B0: nop

    // 0x8064F3B4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8064F3B8: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8064F3BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064F3C0:
    // 0x8064F3C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064F3C4: jr          $ra
    // 0x8064F3C8: nop

    return;
    // 0x8064F3C8: nop

;}
RECOMP_FUNC void func_80029F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029F70: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80029F74: lhu         $t7, 0x64($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X64);
    // 0x80029F78: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80029F7C: bne         $t8, $zero, L_80029F9C
    if (ctx->r24 != 0) {
        // 0x80029F80: nop
    
            goto L_80029F9C;
    }
    // 0x80029F80: nop

    // 0x80029F84: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80029F88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80029F8C: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x80029F90: bne         $t9, $zero, L_80029F9C
    if (ctx->r25 != 0) {
        // 0x80029F94: nop
    
            goto L_80029F9C;
    }
    // 0x80029F94: nop

    // 0x80029F98: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_80029F9C:
    // 0x80029F9C: jr          $ra
    // 0x80029FA0: nop

    return;
    // 0x80029FA0: nop

;}
RECOMP_FUNC void func_805CA8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA8C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CA8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CA8C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805CA8CC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x805CA8D0: beq         $v1, $zero, L_805CA8E4
    if (ctx->r3 == 0) {
        // 0x805CA8D4: nop
    
            goto L_805CA8E4;
    }
    // 0x805CA8D4: nop

    // 0x805CA8D8: jalr        $v1
    // 0x805CA8DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805CA8DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805CA8E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_805CA8E4:
    // 0x805CA8E4: jal         0x800447C8
    // 0x805CA8E8: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x805CA8E8: nop

    after_1:
    // 0x805CA8EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CA8F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805CA8F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805CA8F8: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x805CA8FC: jr          $ra
    // 0x805CA900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805CA900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80558C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558C50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80558C54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80558C58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80558C5C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80558C60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80558C64: jal         0x8004700C
    // 0x80558C68: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80558C68: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80558C6C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80558C70: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80558C74: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80558C78: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80558C7C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80558C80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558C84: jal         0x80048F84
    // 0x80558C88: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80558C88: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
    after_1:
    // 0x80558C8C: jal         0x805580E8
    // 0x80558C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_2;
    // 0x80558C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80558C94: jal         0x805582E0
    // 0x80558C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805582E0(rdram, ctx);
        goto after_3;
    // 0x80558C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80558C9C: lw          $t8, 0x1E0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E0);
    // 0x80558CA0: lw          $t0, 0x1E4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1E4);
    // 0x80558CA4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80558CA8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80558CAC: bne         $t0, $at, L_80558CBC
    if (ctx->r8 != ctx->r1) {
        // 0x80558CB0: sw          $t9, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r25;
            goto L_80558CBC;
    }
    // 0x80558CB0: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x80558CB4: jal         0x800677F8
    // 0x80558CB8: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800677F8(rdram, ctx);
        goto after_4;
    // 0x80558CB8: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_4:
L_80558CBC:
    // 0x80558CBC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80558CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558CC4: beql        $t1, $zero, L_80558CEC
    if (ctx->r9 == 0) {
        // 0x80558CC8: lw          $t4, 0x1E0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X1E0);
            goto L_80558CEC;
    }
    goto skip_0;
    // 0x80558CC8: lw          $t4, 0x1E0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x80558CCC: lw          $t2, 0x1E4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E4);
    // 0x80558CD0: lui         $t3, 0x8056
    ctx->r11 = S32(RELOC_HI16(363, 0X1038) << 16);
    // 0x80558CD4: addiu       $t3, $t3, -0x7478
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(363, 0X1038));
    // 0x80558CD8: bnel        $t2, $zero, L_80558CEC
    if (ctx->r10 != 0) {
        // 0x80558CDC: lw          $t4, 0x1E0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X1E0);
            goto L_80558CEC;
    }
    goto skip_1;
    // 0x80558CDC: lw          $t4, 0x1E0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E0);
    skip_1:
    // 0x80558CE0: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
    // 0x80558CE4: sw          $t3, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r11;
    // 0x80558CE8: lw          $t4, 0x1E0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E0);
L_80558CEC:
    // 0x80558CEC: slti        $at, $t4, 0x15
    ctx->r1 = SIGNED(ctx->r12) < 0X15 ? 1 : 0;
    // 0x80558CF0: bnel        $at, $zero, L_80558D14
    if (ctx->r1 != 0) {
        // 0x80558CF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80558D14;
    }
    goto skip_2;
    // 0x80558CF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80558CF8: lw          $t5, 0x1E4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1E4);
    // 0x80558CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558D00: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80558D04: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80558D08: jal         0x80559928
    // 0x80558D0C: sw          $t6, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r14;
    func_80559928(rdram, ctx);
        goto after_5;
    // 0x80558D0C: sw          $t6, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r14;
    after_5:
    // 0x80558D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80558D14:
    // 0x80558D14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80558D18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80558D1C: jr          $ra
    // 0x80558D20: nop

    return;
    // 0x80558D20: nop

;}
RECOMP_FUNC void func_80682BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682BF4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682BF8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682BFC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682C00: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682C04: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682C08: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682C0C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682C10: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682C14: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682C18: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682C1C: jr          $ra
    // 0x80682C20: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682C20: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80011920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011920: jr          $ra
    // 0x80011924: nop

    return;
    // 0x80011924: nop

;}
RECOMP_FUNC void func_80080090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080090: or          $t8, $a1, $zero
    ctx->r24 = ctx->r5 | 0;
    // 0x80080094: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x80080098: addiu       $t0, $a1, 0x3C
    ctx->r8 = ADD32(ctx->r5, 0X3C);
L_8008009C:
    // 0x8008009C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800800A0: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800800A4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800800A8: sw          $t7, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r15;
    // 0x800800AC: lw          $t6, -0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X8);
    // 0x800800B0: sw          $t6, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r14;
    // 0x800800B4: lw          $t7, -0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, -0X4);
    // 0x800800B8: bne         $t8, $t0, L_8008009C
    if (ctx->r24 != ctx->r8) {
        // 0x800800BC: sw          $t7, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r15;
            goto L_8008009C;
    }
    // 0x800800BC: sw          $t7, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r15;
    // 0x800800C0: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800800C4: jr          $ra
    // 0x800800C8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    return;
    // 0x800800C8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
;}
RECOMP_FUNC void func_8044EF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044EF50: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8044EF54: lui         $t9, 0x8045
    ctx->r25 = S32(RELOC_HI16(98, 0X135AC) << 16);
    // 0x8044EF58: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8044EF5C: lw          $t9, 0x798C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X135AC));
    // 0x8044EF60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044EF64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044EF68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044EF6C: jalr        $t9
    // 0x8044EF70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8044EF70: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8044EF74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044EF78: lui         $t9, 0x8045
    ctx->r25 = S32(RELOC_HI16(98, 0X135DC) << 16);
    // 0x8044EF7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044EF80: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8044EF84: lw          $t9, 0x79BC($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X135DC));
    // 0x8044EF88: jalr        $t9
    // 0x8044EF8C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8044EF8C: nop

    after_1:
    // 0x8044EF90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044EF94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044EF98: jr          $ra
    // 0x8044EF9C: nop

    return;
    // 0x8044EF9C: nop

;}
RECOMP_FUNC void func_806EEA40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EEA40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806EEA44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EEA48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EEA4C: jal         0x8004700C
    // 0x806EEA50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EEA50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EEA54: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x806EEA58: jal         0x806EC16C
    // 0x806EEA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC16C(rdram, ctx);
        goto after_1;
    // 0x806EEA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EEA60: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EEA64: jal         0x800577D8
    // 0x806EEA68: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_2;
    // 0x806EEA68: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x806EEA6C: jal         0x806EE5E4
    // 0x806EEA70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE5E4(rdram, ctx);
        goto after_3;
    // 0x806EEA70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EEA74: jal         0x806EE664
    // 0x806EEA78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE664(rdram, ctx);
        goto after_4;
    // 0x806EEA78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EEA7C: jal         0x806EE6AC
    // 0x806EEA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE6AC(rdram, ctx);
        goto after_5;
    // 0x806EEA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EEA84: jal         0x806EE720
    // 0x806EEA88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE720(rdram, ctx);
        goto after_6;
    // 0x806EEA88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806EEA8C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x806EEA90: beql        $t7, $zero, L_806EEBA8
    if (ctx->r15 == 0) {
        // 0x806EEA94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EEBA8;
    }
    goto skip_0;
    // 0x806EEA94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EEA98: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x806EEA9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EEAA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EEAA4: blez        $v1, L_806EEB9C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x806EEAA8: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_806EEB9C;
    }
    // 0x806EEAA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EEAAC: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
    // 0x806EEAB0: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x806EEAB4: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x806EEAB8: lw          $t9, 0x1F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1F4);
    // 0x806EEABC: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806EEAC0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806EEAC4: lwc1        $f10, 0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X8);
    // 0x806EEAC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806EEACC: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806EEAD0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806EEAD4: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806EEAD8: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806EEADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EEAE0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x806EEAE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EEAE8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806EEAEC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x806EEAF0: bc1f        L_806EEB24
    if (!c1cs) {
        // 0x806EEAF4: sub.s       $f0, $f4, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_806EEB24;
    }
    // 0x806EEAF4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806EEAF8: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x806EEAFC: jal         0x806EF4A0
    // 0x806EEB00: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_806EF4A0(rdram, ctx);
        goto after_7;
    // 0x806EEB00: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_7:
    // 0x806EEB04: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806EEB08: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D24) << 16);
    // 0x806EEB0C: lwc1        $f14, 0xC74($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D24));
    // 0x806EEB10: jal         0x806EC03C
    // 0x806EEB14: lwc1        $f12, 0x28($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X28);
    func_806EC03C(rdram, ctx);
        goto after_8;
    // 0x806EEB14: lwc1        $f12, 0x28($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X28);
    after_8:
    // 0x806EEB18: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806EEB1C: b           L_806EEBA4
    // 0x806EEB20: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
        goto L_806EEBA4;
    // 0x806EEB20: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
L_806EEB24:
    // 0x806EEB24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EEB28: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x806EEB2C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806EEB30: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806EEB34: nop

    // 0x806EEB38: bc1fl       L_806EEB50
    if (!c1cs) {
        // 0x806EEB3C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_806EEB50;
    }
    goto skip_1;
    // 0x806EEB3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x806EEB40: lw          $t0, 0x68($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X68);
    // 0x806EEB44: beql        $t0, $zero, L_806EEB74
    if (ctx->r8 == 0) {
        // 0x806EEB48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EEB74;
    }
    goto skip_2;
    // 0x806EEB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x806EEB4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_806EEB50:
    // 0x806EEB50: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806EEB54: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806EEB58: nop

    // 0x806EEB5C: bc1fl       L_806EEBA8
    if (!c1cs) {
        // 0x806EEB60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EEBA8;
    }
    goto skip_3;
    // 0x806EEB60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806EEB64: lw          $t1, 0x68($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X68);
    // 0x806EEB68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806EEB6C: bne         $t1, $at, L_806EEBA4
    if (ctx->r9 != ctx->r1) {
        // 0x806EEB70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EEBA4;
    }
    // 0x806EEB70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806EEB74:
    // 0x806EEB74: jal         0x806EE640
    // 0x806EEB78: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_806EE640(rdram, ctx);
        goto after_9;
    // 0x806EEB78: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_9:
    // 0x806EEB7C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806EEB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EEB84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EEB88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806EEB8C: jal         0x806EF4A0
    // 0x806EEB90: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    func_806EF4A0(rdram, ctx);
        goto after_10;
    // 0x806EEB90: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    after_10:
    // 0x806EEB94: b           L_806EEBA8
    // 0x806EEB98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EEBA8;
    // 0x806EEB98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EEB9C:
    // 0x806EEB9C: jal         0x806EF4A0
    // 0x806EEBA0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EF4A0(rdram, ctx);
        goto after_11;
    // 0x806EEBA0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_11:
L_806EEBA4:
    // 0x806EEBA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EEBA8:
    // 0x806EEBA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EEBAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806EEBB0: jr          $ra
    // 0x806EEBB4: nop

    return;
    // 0x806EEBB4: nop

;}
RECOMP_FUNC void func_806D9190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D9194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D9198: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x806D919C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806D91A0: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x806D91A4: andi        $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 & 0XF00;
    // 0x806D91A8: beql        $t7, $zero, L_806D9214
    if (ctx->r15 == 0) {
        // 0x806D91AC: lw          $t9, 0x4($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X4);
            goto L_806D9214;
    }
    goto skip_0;
    // 0x806D91AC: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x806D91B0: lbu         $t8, 0x11($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X11);
    // 0x806D91B4: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x806D91B8: beq         $at, $zero, L_806D91D8
    if (ctx->r1 == 0) {
        // 0x806D91BC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_806D91D8;
    }
    // 0x806D91BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806D91C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806D91C4: lwc1        $f0, 0xC8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806D91C8: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(628, 0X774) << 16);
    // 0x806D91CC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806D91D0: nop

    // 0x806D91D4: bc1f        L_806D91EC
    if (!c1cs) {
        // 0x806D91D8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_806D91EC;
    }
L_806D91D8:
    // 0x806D91D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806D91DC: jal         0x806D9168
    // 0x806D91E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_806D9168(rdram, ctx);
        goto after_0;
    // 0x806D91E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x806D91E4: b           L_806D922C
    // 0x806D91E8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
        goto L_806D922C;
    // 0x806D91E8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_806D91EC:
    // 0x806D91EC: lwc1        $f6, 0xC4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC4);
    // 0x806D91F0: lwc1        $f8, -0x69CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(628, 0X774));
    // 0x806D91F4: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(628, 0X778) << 16);
    // 0x806D91F8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806D91FC: swc1        $f10, 0xC4($a2)
    MEM_W(0XC4, ctx->r6) = ctx->f10.u32l;
    // 0x806D9200: lwc1        $f16, -0x69C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(628, 0X778));
    // 0x806D9204: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x806D9208: b           L_806D922C
    // 0x806D920C: swc1        $f18, 0xC8($a2)
    MEM_W(0XC8, ctx->r6) = ctx->f18.u32l;
        goto L_806D922C;
    // 0x806D920C: swc1        $f18, 0xC8($a2)
    MEM_W(0XC8, ctx->r6) = ctx->f18.u32l;
    // 0x806D9210: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
L_806D9214:
    // 0x806D9214: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806D9218: beql        $t9, $zero, L_806D9230
    if (ctx->r25 == 0) {
        // 0x806D921C: addiu       $a0, $a2, 0xC4
        ctx->r4 = ADD32(ctx->r6, 0XC4);
            goto L_806D9230;
    }
    goto skip_1;
    // 0x806D921C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    skip_1:
    // 0x806D9220: jal         0x806D9168
    // 0x806D9224: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_806D9168(rdram, ctx);
        goto after_1;
    // 0x806D9224: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x806D9228: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_806D922C:
    // 0x806D922C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
L_806D9230:
    // 0x806D9230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D9234: jal         0x80048F84
    // 0x806D9238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x806D9238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x806D923C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D9240: jal         0x80048F84
    // 0x806D9244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x806D9244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x806D9248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D924C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D9250: jr          $ra
    // 0x806D9254: nop

    return;
    // 0x806D9254: nop

;}
RECOMP_FUNC void func_8042EEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EEF4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8042EEF8: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0XC50) << 16);
    // 0x8042EEFC: addiu       $t6, $t6, -0x12D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0XC50));
    // 0x8042EF00: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8042EF04: jr          $ra
    // 0x8042EF08: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8042EF08: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80671F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671F38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80671F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80671F40: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80671F44: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80671F48: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80671F4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80671F50: jal         0x80671D4C
    // 0x80671F54: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x80671F54: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80671F58: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80671F5C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80671F60: lw          $t6, 0x1E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1E0);
    // 0x80671F64: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80671F68: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80671F6C: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x80671F70: bne         $at, $zero, L_80671F90
    if (ctx->r1 != 0) {
        // 0x80671F74: sw          $t7, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r15;
            goto L_80671F90;
    }
    // 0x80671F74: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x80671F78: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80671F7C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80671F80: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80671F84: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80671F88: jal         0x80672C80
    // 0x80671F8C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    func_80672C80(rdram, ctx);
        goto after_1;
    // 0x80671F8C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    after_1:
L_80671F90:
    // 0x80671F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80671F94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80671F98: jr          $ra
    // 0x80671F9C: nop

    return;
    // 0x80671F9C: nop

;}
RECOMP_FUNC void func_804323C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804323C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804323C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804323C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804323CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804323D0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x804323D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804323D8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804323DC: lw          $v1, 0xC($t9)
    ctx->r3 = MEM_W(ctx->r25, 0XC);
    // 0x804323E0: beql        $v1, $zero, L_80432458
    if (ctx->r3 == 0) {
        // 0x804323E4: sw          $zero, 0x0($v0)
        MEM_W(0X0, ctx->r2) = 0;
            goto L_80432458;
    }
    goto skip_0;
    // 0x804323E4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    skip_0:
    // 0x804323E8: lbu         $t0, 0x30($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X30);
    // 0x804323EC: addiu       $a0, $v1, 0xC4
    ctx->r4 = ADD32(ctx->r3, 0XC4);
    // 0x804323F0: bnel        $t0, $zero, L_8043245C
    if (ctx->r8 != 0) {
        // 0x804323F4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8043245C;
    }
    goto skip_1;
    // 0x804323F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x804323F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x804323FC: jal         0x80048378
    // 0x80432400: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80432400: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80432404: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80432408: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8043240C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80432410: sb          $t1, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r9;
    // 0x80432414: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80432418: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8043241C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80432420: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80432424: bne         $at, $zero, L_80432430
    if (ctx->r1 != 0) {
        // 0x80432428: sw          $t3, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r11;
            goto L_80432430;
    }
    // 0x80432428: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8043242C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80432430:
    // 0x80432430: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80432434: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    // 0x80432438: jal         0x80067BBC
    // 0x8043243C: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8043243C: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    after_1:
    // 0x80432440: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80432444: jal         0x80067818
    // 0x80432448: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80432448: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8043244C: b           L_8043245C
    // 0x80432450: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_8043245C;
    // 0x80432450: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80432454: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80432458:
    // 0x80432458: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8043245C:
    // 0x8043245C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80432460: jal         0x804326C4
    // 0x80432464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804326C4(rdram, ctx);
        goto after_3;
    // 0x80432464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80432468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043246C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80432470: jr          $ra
    // 0x80432474: nop

    return;
    // 0x80432474: nop

;}
RECOMP_FUNC void func_8002626C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002626C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026270: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80026274: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80026278: addiu       $t7, $t7, 0x6238
    ctx->r15 = ADD32(ctx->r15, 0X6238);
    // 0x8002627C: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x80026280: sw          $zero, 0x80($v0)
    MEM_W(0X80, ctx->r2) = 0;
    // 0x80026284: sb          $t6, 0x8C($v0)
    MEM_B(0X8C, ctx->r2) = ctx->r14;
    // 0x80026288: jr          $ra
    // 0x8002628C: sw          $t7, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r15;
    return;
    // 0x8002628C: sw          $t7, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_8046B238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046B238: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046B23C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046B240: jal         0x8046B1CC
    // 0x8046B244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8046B1CC(rdram, ctx);
        goto after_0;
    // 0x8046B244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046B248: bne         $v0, $zero, L_8046B258
    if (ctx->r2 != 0) {
        // 0x8046B24C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8046B258;
    }
    // 0x8046B24C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046B250: b           L_8046B2C8
    // 0x8046B254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8046B2C8;
    // 0x8046B254: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8046B258:
    // 0x8046B258: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
    // 0x8046B25C: lui         $t7, 0x8047
    ctx->r15 = S32(RELOC_HI16(138, 0X1AD0) << 16);
    // 0x8046B260: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8046B264: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8046B268: addiu       $t7, $t7, -0x4DF0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(138, 0X1AD0));
    // 0x8046B26C: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x8046B270: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8046B274: lui         $t0, 0x8047
    ctx->r8 = S32(RELOC_HI16(138, 0X2824) << 16);
    // 0x8046B278: sh          $t6, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r14;
    // 0x8046B27C: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x8046B280: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    // 0x8046B284: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
    // 0x8046B288: addiu       $t0, $t0, -0x409C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(138, 0X2824));
    // 0x8046B28C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8046B290: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8046B294: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8046B298: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8046B29C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046B2A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046B2A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8046B2A8: jal         0x8046B2D8
    // 0x8046B2AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8046B2D8(rdram, ctx);
        goto after_1;
    // 0x8046B2AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8046B2B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046B2B4: lui         $t2, 0x8047
    ctx->r10 = S32(RELOC_HI16(138, 0X8C) << 16);
    // 0x8046B2B8: addiu       $t2, $t2, -0x6834
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(138, 0X8C));
    // 0x8046B2BC: lw          $t3, 0x16C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X16C);
    // 0x8046B2C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8046B2C4: sw          $t2, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r10;
L_8046B2C8:
    // 0x8046B2C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046B2CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046B2D0: jr          $ra
    // 0x8046B2D4: nop

    return;
    // 0x8046B2D4: nop

;}
RECOMP_FUNC void func_804BEB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BEB18: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804BEB1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BEB20: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804BEB24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804BEB28: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804BEB2C: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804BEB30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804BEB34: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x804BEB38: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BEB3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804BEB40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804BEB44: lwc1        $f0, 0xE8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x804BEB48: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x804BEB4C: nop

    // 0x804BEB50: bc1t        L_804BEB6C
    if (c1cs) {
        // 0x804BEB54: nop
    
            goto L_804BEB6C;
    }
    // 0x804BEB54: nop

    // 0x804BEB58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804BEB5C: nop

    // 0x804BEB60: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x804BEB64: b           L_804BEC68
    // 0x804BEB68: swc1        $f10, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f10.u32l;
        goto L_804BEC68;
    // 0x804BEB68: swc1        $f10, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f10.u32l;
L_804BEB6C:
    // 0x804BEB6C: jal         0x800653D8
    // 0x804BEB70: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x804BEB70: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x804BEB74: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x804BEB78: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x804BEB7C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804BEB80: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804BEB84: mul.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x804BEB88: jal         0x800653D8
    // 0x804BEB8C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x804BEB8C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x804BEB90: andi        $t7, $v0, 0x1F
    ctx->r15 = ctx->r2 & 0X1F;
    // 0x804BEB94: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x804BEB98: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804BEB9C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804BEBA0: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804BEBA4: jal         0x800653D8
    // 0x804BEBA8: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x804BEBA8: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x804BEBAC: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x804BEBB0: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x804BEBB4: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804BEBB8: beq         $t8, $zero, L_804BEBD4
    if (ctx->r24 == 0) {
        // 0x804BEBBC: lwc1        $f2, 0x38($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
            goto L_804BEBD4;
    }
    // 0x804BEBBC: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x804BEBC0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804BEBC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804BEBC8: nop

    // 0x804BEBCC: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804BEBD0: nop

L_804BEBD4:
    // 0x804BEBD4: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x804BEBD8: beq         $t9, $zero, L_804BEBF0
    if (ctx->r25 == 0) {
        // 0x804BEBDC: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_804BEBF0;
    }
    // 0x804BEBDC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804BEBE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804BEBE4: nop

    // 0x804BEBE8: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x804BEBEC: nop

L_804BEBF0:
    // 0x804BEBF0: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804BEBF4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4204) << 16);
    // 0x804BEBF8: lwc1        $f16, -0x4CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4204));
    // 0x804BEBFC: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x804BEC00: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x804BEC04: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x804BEC08: lui         $a1, 0x804C
    ctx->r5 = S32(RELOC_HI16(191, 0X3D0C) << 16);
    // 0x804BEC0C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x804BEC10: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804BEC14: addiu       $a1, $a1, -0x9C4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(191, 0X3D0C));
    // 0x804BEC18: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x804BEC1C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x804BEC20: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x804BEC24: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x804BEC28: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804BEC2C: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x804BEC30: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x804BEC34: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x804BEC38: jalr        $t9
    // 0x804BEC3C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804BEC3C: nop

    after_3:
    // 0x804BEC40: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x804BEC44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BEC48: nop

    // 0x804BEC4C: swc1        $f4, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f4.u32l;
    // 0x804BEC50: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x804BEC54: jal         0x80067BBC
    // 0x804BEC58: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x804BEC58: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_4:
    // 0x804BEC5C: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x804BEC60: jal         0x80067818
    // 0x804BEC64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x804BEC64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
L_804BEC68:
    // 0x804BEC68: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4208) << 16);
    // 0x804BEC6C: lwc1        $f2, -0x4C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4208));
    // 0x804BEC70: lwc1        $f0, 0xEC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x804BEC74: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X420C) << 16);
    // 0x804BEC78: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804BEC7C: nop

    // 0x804BEC80: bc1fl       L_804BECD4
    if (!c1cs) {
        // 0x804BEC84: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_804BECD4;
    }
    goto skip_0;
    // 0x804BEC84: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x804BEC88: lwc1        $f6, -0x4C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X420C));
    // 0x804BEC8C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x804BEC90: swc1        $f8, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f8.u32l;
    // 0x804BEC94: lwc1        $f0, 0xEC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x804BEC98: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804BEC9C: nop

    // 0x804BECA0: bc1fl       L_804BECB4
    if (!c1cs) {
        // 0x804BECA4: lwc1        $f10, 0x78($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
            goto L_804BECB4;
    }
    goto skip_1;
    // 0x804BECA4: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    skip_1:
    // 0x804BECA8: swc1        $f2, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f2.u32l;
    // 0x804BECAC: lwc1        $f0, 0xEC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x804BECB0: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
L_804BECB4:
    // 0x804BECB4: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x804BECB8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x804BECBC: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    // 0x804BECC0: lwc1        $f4, 0xEC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x804BECC4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804BECC8: b           L_804BECF0
    // 0x804BECCC: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
        goto L_804BECF0;
    // 0x804BECCC: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x804BECD0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_804BECD4:
    // 0x804BECD4: jal         0x80067BBC
    // 0x804BECD8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x804BECD8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x804BECDC: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x804BECE0: jal         0x80067818
    // 0x804BECE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x804BECE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x804BECE8: jal         0x800447C8
    // 0x804BECEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_8;
    // 0x804BECEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_804BECF0:
    // 0x804BECF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BECF4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804BECF8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804BECFC: jr          $ra
    // 0x804BED00: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x804BED00: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80798E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798E38: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80798E3C: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(826, 0X2470) << 16);
    // 0x80798E40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80798E44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80798E48: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80798E4C: addiu       $t7, $t7, -0x5070
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(826, 0X2470));
    // 0x80798E50: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80798E54: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80798E58: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x80798E5C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80798E60: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80798E64: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80798E68: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80798E6C: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(826, 0X2488) << 16);
    // 0x80798E70: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80798E74: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80798E78: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80798E7C: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80798E80: addiu       $t1, $t1, -0x5058
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(826, 0X2488));
    // 0x80798E84: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80798E88: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80798E8C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80798E90: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80798E94: addiu       $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x80798E98: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80798E9C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80798EA0: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80798EA4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80798EA8: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80798EAC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80798EB0: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80798EB4: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80798EB8: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80798EBC: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80798EC0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80798EC4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80798EC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80798ECC: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x80798ED0: jal         0x80798C80
    // 0x80798ED4: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    func_80798C80(rdram, ctx);
        goto after_0;
    // 0x80798ED4: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    after_0:
    // 0x80798ED8: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x80798EDC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80798EE0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80798EE4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80798EE8: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x80798EEC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80798EF0: jal         0x80798C80
    // 0x80798EF4: lwc1        $f12, 0x50($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X50);
    func_80798C80(rdram, ctx);
        goto after_1;
    // 0x80798EF4: lwc1        $f12, 0x50($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X50);
    after_1:
    // 0x80798EF8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80798EFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80798F00: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80798F04: jal         0x80066E88
    // 0x80798F08: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80798F08: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_2:
    // 0x80798F0C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80798F10: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80798F14: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80798F18: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80798F1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80798F20: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80798F24: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80798F28: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80798F2C: jal         0x80066DE4
    // 0x80798F30: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x80798F30: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_3:
    // 0x80798F34: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80798F38: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x80798F3C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80798F40: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80798F44: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80798F48: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X25D8) << 16);
    // 0x80798F4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80798F50: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    // 0x80798F54: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80798F58: lwc1        $f8, -0x4F08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X25D8));
    // 0x80798F5C: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80798F60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80798F64: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x80798F68: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x80798F6C: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    // 0x80798F70: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x80798F74: beql        $t7, $zero, L_80798F9C
    if (ctx->r15 == 0) {
        // 0x80798F78: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80798F9C;
    }
    goto skip_0;
    // 0x80798F78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80798F7C: jal         0x80798BFC
    // 0x80798F80: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80798BFC(rdram, ctx);
        goto after_4;
    // 0x80798F80: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80798F84: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80798F88: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80798F8C: lwc1        $f16, 0x38($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X38);
    // 0x80798F90: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x80798F94: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80798F98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80798F9C:
    // 0x80798F9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80798FA0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80798FA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80798FA8: jal         0x80798C80
    // 0x80798FAC: nop

    func_80798C80(rdram, ctx);
        goto after_5;
    // 0x80798FAC: nop

    after_5:
    // 0x80798FB0: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x80798FB4: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x80798FB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80798FBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80798FC0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80798FC4: jr          $ra
    // 0x80798FC8: nop

    return;
    // 0x80798FC8: nop

;}
RECOMP_FUNC void func_80709BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709BAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80709BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80709BB4: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80709BB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80709BBC: jal         0x807095E4
    // 0x80709BC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_807095E4(rdram, ctx);
        goto after_0;
    // 0x80709BC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80709BC4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80709BC8: bne         $v0, $zero, L_80709CA8
    if (ctx->r2 != 0) {
        // 0x80709BCC: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_80709CA8;
    }
    // 0x80709BCC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80709BD0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80709BD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80709BD8: jal         0x80709B48
    // 0x80709BDC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80709B48(rdram, ctx);
        goto after_1;
    // 0x80709BDC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x80709BE0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80709BE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80709BE8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80709BEC: lwc1        $f0, 0x50($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X50);
    // 0x80709BF0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80709BF4: nop

    // 0x80709BF8: bc1tl       L_80709C6C
    if (c1cs) {
        // 0x80709BFC: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80709C6C;
    }
    goto skip_0;
    // 0x80709BFC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80709C00: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80709C04: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80709C08: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80709C0C: nop

    // 0x80709C10: bc1fl       L_80709C44
    if (!c1cs) {
        // 0x80709C14: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80709C44;
    }
    goto skip_1;
    // 0x80709C14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x80709C18: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80709C1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80709C20: nop

    // 0x80709C24: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80709C28: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80709C2C: nop

    // 0x80709C30: bc1f        L_80709C60
    if (!c1cs) {
        // 0x80709C34: nop
    
            goto L_80709C60;
    }
    // 0x80709C34: nop

    // 0x80709C38: b           L_80709C60
    // 0x80709C3C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80709C60;
    // 0x80709C3C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80709C40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80709C44:
    // 0x80709C44: nop

    // 0x80709C48: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80709C4C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80709C50: nop

    // 0x80709C54: bc1f        L_80709C60
    if (!c1cs) {
        // 0x80709C58: nop
    
            goto L_80709C60;
    }
    // 0x80709C58: nop

    // 0x80709C5C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80709C60:
    // 0x80709C60: b           L_80709CA0
    // 0x80709C64: swc1        $f0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f0.u32l;
        goto L_80709CA0;
    // 0x80709C64: swc1        $f0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f0.u32l;
    // 0x80709C68: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80709C6C:
    // 0x80709C6C: nop

    // 0x80709C70: swc1        $f2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f2.u32l;
    // 0x80709C74: beq         $v0, $zero, L_80709CA0
    if (ctx->r2 == 0) {
        // 0x80709C78: swc1        $f2, 0x14($a1)
        MEM_W(0X14, ctx->r5) = ctx->f2.u32l;
            goto L_80709CA0;
    }
    // 0x80709C78: swc1        $f2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f2.u32l;
    // 0x80709C7C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80709C80: swc1        $f2, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->f2.u32l;
    // 0x80709C84: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80709C88: jal         0x8004816C
    // 0x80709C8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8004816C(rdram, ctx);
        goto after_2;
    // 0x80709C8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x80709C90: jal         0x807095C4
    // 0x80709C94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_807095C4(rdram, ctx);
        goto after_3;
    // 0x80709C94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80709C98: b           L_80709CAC
    // 0x80709C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80709CAC;
    // 0x80709C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80709CA0:
    // 0x80709CA0: jal         0x80709744
    // 0x80709CA4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80709744(rdram, ctx);
        goto after_4;
    // 0x80709CA4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
L_80709CA8:
    // 0x80709CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80709CAC:
    // 0x80709CAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80709CB0: jr          $ra
    // 0x80709CB4: nop

    return;
    // 0x80709CB4: nop

;}
RECOMP_FUNC void func_804CDB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CDB58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CDB5C: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x804CDB60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CDB64: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804CDB68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CDB6C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x804CDB70: jal         0x80065954
    // 0x804CDB74: sub.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f4.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x804CDB74: sub.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f4.fl;
    after_0:
    // 0x804CDB78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CDB7C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804CDB80: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804CDB84: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804CDB88: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x804CDB8C: nop

    // 0x804CDB90: bc1fl       L_804CDBE8
    if (!c1cs) {
        // 0x804CDB94: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_804CDBE8;
    }
    goto skip_0;
    // 0x804CDB94: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_0:
    // 0x804CDB98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804CDB9C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(237, 0X1CB4) << 16);
    // 0x804CDBA0: lwc1        $f6, -0x1EDC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(237, 0X1CB4));
    // 0x804CDBA4: add.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x804CDBA8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x804CDBAC: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x804CDBB0: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x804CDBB4: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804CDBB8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x804CDBBC: nop

    // 0x804CDBC0: bc1fl       L_804CDC40
    if (!c1cs) {
        // 0x804CDBC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDC40;
    }
    goto skip_1;
    // 0x804CDBC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804CDBC8: sub.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x804CDBCC: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x804CDBD0: nop

    // 0x804CDBD4: bc1fl       L_804CDC40
    if (!c1cs) {
        // 0x804CDBD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDC40;
    }
    goto skip_2;
    // 0x804CDBD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804CDBDC: b           L_804CDC3C
    // 0x804CDBE0: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
        goto L_804CDC3C;
    // 0x804CDBE0: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
    // 0x804CDBE4: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_804CDBE8:
    // 0x804CDBE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804CDBEC: bc1fl       L_804CDC40
    if (!c1cs) {
        // 0x804CDBF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDC40;
    }
    goto skip_3;
    // 0x804CDBF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x804CDBF4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804CDBF8: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(237, 0X1CB8) << 16);
    // 0x804CDBFC: lwc1        $f4, -0x1ED8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(237, 0X1CB8));
    // 0x804CDC00: add.s       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x804CDC04: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804CDC08: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x804CDC0C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x804CDC10: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x804CDC14: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x804CDC18: nop

    // 0x804CDC1C: bc1fl       L_804CDC40
    if (!c1cs) {
        // 0x804CDC20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDC40;
    }
    goto skip_4;
    // 0x804CDC20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x804CDC24: sub.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x804CDC28: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x804CDC2C: nop

    // 0x804CDC30: bc1fl       L_804CDC40
    if (!c1cs) {
        // 0x804CDC34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CDC40;
    }
    goto skip_5;
    // 0x804CDC34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x804CDC38: swc1        $f14, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f14.u32l;
L_804CDC3C:
    // 0x804CDC3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CDC40:
    // 0x804CDC40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CDC44: jr          $ra
    // 0x804CDC48: nop

    return;
    // 0x804CDC48: nop

;}
RECOMP_FUNC void func_80076B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B20: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80076B24: addiu       $t6, $zero, 0x9B
    ctx->r14 = ADD32(0, 0X9B);
    // 0x80076B28: addiu       $t7, $zero, 0x37
    ctx->r15 = ADD32(0, 0X37);
    // 0x80076B2C: sb          $t7, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r15;
    // 0x80076B30: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80076B34: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x80076B38: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
    // 0x80076B3C: jr          $ra
    // 0x80076B40: nop

    return;
    // 0x80076B40: nop

;}
RECOMP_FUNC void func_805ADA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADA44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ADA48: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805ADA4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805ADA50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805ADA54: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805ADA58: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805ADA5C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805ADA60: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805ADA64: addiu       $t6, $zero, 0x1EB4
    ctx->r14 = ADD32(0, 0X1EB4);
    // 0x805ADA68: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805ADA6C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805ADA70: addiu       $a3, $zero, 0x1DC4
    ctx->r7 = ADD32(0, 0X1DC4);
    // 0x805ADA74: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x805ADA78: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x805ADA7C: jal         0x805AD70C
    // 0x805ADA80: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_805AD70C(rdram, ctx);
        goto after_0;
    // 0x805ADA80: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805ADA84: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805ADA88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ADA8C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805ADA90: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805ADA94: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x805ADA98: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x805ADA9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ADAA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ADAA4: jr          $ra
    // 0x805ADAA8: nop

    return;
    // 0x805ADAA8: nop

;}
RECOMP_FUNC void func_80052300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80052304: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80052308: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8005230C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80052310: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80052314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80052318: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x8005231C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_80052320:
    // 0x80052320: bnel        $v0, $v1, L_80052320
    if (ctx->r2 != ctx->r3) {
        // 0x80052324: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_80052320;
    }
    goto skip_0;
    // 0x80052324: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    skip_0:
    // 0x80052328: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8005232C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052330: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    // 0x80052334: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80052338: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005233C: jal         0x8008699C
    // 0x80052340: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_0;
    // 0x80052340: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_0:
    // 0x80052344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052348: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005234C: jr          $ra
    // 0x80052350: nop

    return;
    // 0x80052350: nop

;}
RECOMP_FUNC void func_8005C174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C174: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005C178: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005C17C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005C180: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8005C184: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8005C188: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8005C18C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8005C190: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8005C194: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8005C198: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x8005C19C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C1A0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005C1A4: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8005C1A8: lh          $s0, 0x13C($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X13C);
    // 0x8005C1AC: lw          $t0, 0x20($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X20);
    // 0x8005C1B0: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x8005C1B4: bgez        $s0, L_8005C1C4
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8005C1B8: sra         $t8, $s0, 1
        ctx->r24 = S32(SIGNED(ctx->r16) >> 1);
            goto L_8005C1C4;
    }
    // 0x8005C1B8: sra         $t8, $s0, 1
    ctx->r24 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8005C1BC: addiu       $at, $s0, 0x1
    ctx->r1 = ADD32(ctx->r16, 0X1);
    // 0x8005C1C0: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8005C1C4:
    // 0x8005C1C4: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C1C8: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x8005C1CC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8005C1D0: mflo        $t9
    ctx->r25 = lo;
    // 0x8005C1D4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8005C1D8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8005C1DC: addu        $v1, $t3, $t9
    ctx->r3 = ADD32(ctx->r11, ctx->r25);
    // 0x8005C1E0: addu        $a0, $v1, $t0
    ctx->r4 = ADD32(ctx->r3, ctx->r8);
    // 0x8005C1E4: beql        $t2, $zero, L_8005C240
    if (ctx->r10 == 0) {
        // 0x8005C1E8: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_8005C240;
    }
    goto skip_0;
    // 0x8005C1E8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x8005C1EC: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x8005C1F0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005C1F4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8005C1F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8005C1FC: jal         0x8005C060
    // 0x8005C200: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_8005C060(rdram, ctx);
        goto after_0;
    // 0x8005C200: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x8005C204: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8005C208: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8005C20C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8005C210: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005C214: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8005C218: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x8005C21C: lh          $a3, 0x13C($t5)
    ctx->r7 = MEM_H(ctx->r13, 0X13C);
    // 0x8005C220: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005C224: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C228: jal         0x8005C060
    // 0x8005C22C: addu        $a0, $v1, $t1
    ctx->r4 = ADD32(ctx->r3, ctx->r9);
    func_8005C060(rdram, ctx);
        goto after_1;
    // 0x8005C22C: addu        $a0, $v1, $t1
    ctx->r4 = ADD32(ctx->r3, ctx->r9);
    after_1:
    // 0x8005C230: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8005C234: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8005C238: lh          $s0, 0x13C($t6)
    ctx->r16 = MEM_H(ctx->r14, 0X13C);
    // 0x8005C23C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
L_8005C240:
    // 0x8005C240: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8005C244: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8005C248: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x8005C24C: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x8005C250: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x8005C254: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8005C258: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005C25C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C260: jal         0x8005C060
    // 0x8005C264: addu        $a0, $t3, $t9
    ctx->r4 = ADD32(ctx->r11, ctx->r25);
    func_8005C060(rdram, ctx);
        goto after_2;
    // 0x8005C264: addu        $a0, $t3, $t9
    ctx->r4 = ADD32(ctx->r11, ctx->r25);
    after_2:
    // 0x8005C268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005C26C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005C270: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8005C274: jr          $ra
    // 0x8005C278: nop

    return;
    // 0x8005C278: nop

;}
RECOMP_FUNC void func_8005C9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C9F4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8005C9F8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8005C9FC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8005CA00: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8005CA04: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8005CA08: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8005CA0C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8005CA10: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8005CA14: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005CA18: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005CA1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005CA20: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8005CA24: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8005CA28: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8005CA2C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005CA30: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8005CA34: lh          $t7, 0x13E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X13E);
    // 0x8005CA38: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8005CA3C: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x8005CA40: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x8005CA44: bgez        $t8, L_8005CA54
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8005CA48: sra         $t9, $t8, 4
        ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
            goto L_8005CA54;
    }
    // 0x8005CA48: sra         $t9, $t8, 4
    ctx->r25 = S32(SIGNED(ctx->r24) >> 4);
    // 0x8005CA4C: addiu       $at, $t8, 0xF
    ctx->r1 = ADD32(ctx->r24, 0XF);
    // 0x8005CA50: sra         $t9, $at, 4
    ctx->r25 = S32(SIGNED(ctx->r1) >> 4);
L_8005CA54:
    // 0x8005CA54: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x8005CA58: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x8005CA5C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8005CA60: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x8005CA64: lw          $t2, 0x20($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X20);
    // 0x8005CA68: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x8005CA6C: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x8005CA70: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8005CA74: lh          $s5, 0x13C($t6)
    ctx->r21 = MEM_H(ctx->r14, 0X13C);
    // 0x8005CA78: sh          $t4, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r12;
    // 0x8005CA7C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8005CA80: lw          $s3, 0xC($v0)
    ctx->r19 = MEM_W(ctx->r2, 0XC);
    // 0x8005CA84: lw          $s6, 0x18($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X18);
    // 0x8005CA88: lw          $s7, 0x14($v0)
    ctx->r23 = MEM_W(ctx->r2, 0X14);
    // 0x8005CA8C: sw          $t5, 0x1E0($t7)
    MEM_W(0X1E0, ctx->r15) = ctx->r13;
    // 0x8005CA90: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8005CA94: sll         $s0, $s3, 1
    ctx->r16 = S32(ctx->r19 << 1);
    // 0x8005CA98: blezl       $t8, L_8005CBA8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005CA9C: lw          $t3, 0x68($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X68);
            goto L_8005CBA8;
    }
    goto skip_0;
    // 0x8005CA9C: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    skip_0:
    // 0x8005CAA0: bgez        $s5, L_8005CAB0
    if (SIGNED(ctx->r21) >= 0) {
        // 0x8005CAA4: sra         $fp, $s5, 1
        ctx->r30 = S32(SIGNED(ctx->r21) >> 1);
            goto L_8005CAB0;
    }
    // 0x8005CAA4: sra         $fp, $s5, 1
    ctx->r30 = S32(SIGNED(ctx->r21) >> 1);
    // 0x8005CAA8: addiu       $at, $s5, 0x1
    ctx->r1 = ADD32(ctx->r21, 0X1);
    // 0x8005CAAC: sra         $fp, $at, 1
    ctx->r30 = S32(SIGNED(ctx->r1) >> 1);
L_8005CAB0:
    // 0x8005CAB0: sll         $fp, $fp, 4
    ctx->r30 = S32(ctx->r30 << 4);
    // 0x8005CAB4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
L_8005CAB8:
    // 0x8005CAB8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8005CABC: beq         $t1, $zero, L_8005CB1C
    if (ctx->r9 == 0) {
        // 0x8005CAC0: nop
    
            goto L_8005CB1C;
    }
    // 0x8005CAC0: nop

    // 0x8005CAC4: multu       $fp, $s4
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005CAC8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8005CACC: addu        $s2, $s0, $s7
    ctx->r18 = ADD32(ctx->r16, ctx->r23);
    // 0x8005CAD0: sll         $a3, $s5, 16
    ctx->r7 = S32(ctx->r21 << 16);
    // 0x8005CAD4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005CAD8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8005CADC: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8005CAE0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8005CAE4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8005CAE8: mflo        $s1
    ctx->r17 = lo;
    // 0x8005CAEC: addu        $a0, $t2, $s1
    ctx->r4 = ADD32(ctx->r10, ctx->r17);
    // 0x8005CAF0: jal         0x8005C060
    // 0x8005CAF4: nop

    func_8005C060(rdram, ctx);
        goto after_0;
    // 0x8005CAF4: nop

    after_0:
    // 0x8005CAF8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8005CAFC: sll         $a3, $s5, 16
    ctx->r7 = S32(ctx->r21 << 16);
    // 0x8005CB00: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8005CB04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005CB08: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8005CB0C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8005CB10: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8005CB14: jal         0x8005C060
    // 0x8005CB18: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    func_8005C060(rdram, ctx);
        goto after_1;
    // 0x8005CB18: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    after_1:
L_8005CB1C:
    // 0x8005CB1C: multu       $fp, $s4
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005CB20: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8005CB24: sll         $a3, $s5, 16
    ctx->r7 = S32(ctx->r21 << 16);
    // 0x8005CB28: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8005CB2C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8005CB30: addu        $a2, $s0, $s7
    ctx->r6 = ADD32(ctx->r16, ctx->r23);
    // 0x8005CB34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005CB38: mflo        $t5
    ctx->r13 = lo;
    // 0x8005CB3C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x8005CB40: jal         0x8005C060
    // 0x8005CB44: nop

    func_8005C060(rdram, ctx);
        goto after_2;
    // 0x8005CB44: nop

    after_2:
    // 0x8005CB48: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x8005CB4C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8005CB50: sll         $s0, $s3, 1
    ctx->r16 = S32(ctx->r19 << 1);
    // 0x8005CB54: addu        $t7, $s7, $s0
    ctx->r15 = ADD32(ctx->r23, ctx->r16);
    // 0x8005CB58: lhu         $v1, 0x0($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X0);
    // 0x8005CB5C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005CB60: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8005CB64: bnel        $v1, $at, L_8005CB7C
    if (ctx->r3 != ctx->r1) {
        // 0x8005CB68: slti        $at, $v1, 0x2000
        ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
            goto L_8005CB7C;
    }
    goto skip_1;
    // 0x8005CB68: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    skip_1:
    // 0x8005CB6C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8005CB70: b           L_8005CBA4
    // 0x8005CB74: sw          $zero, 0x1E0($t8)
    MEM_W(0X1E0, ctx->r24) = 0;
        goto L_8005CBA4;
    // 0x8005CB74: sw          $zero, 0x1E0($t8)
    MEM_W(0X1E0, ctx->r24) = 0;
    // 0x8005CB78: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
L_8005CB7C:
    // 0x8005CB7C: bne         $at, $zero, L_8005CB94
    if (ctx->r1 != 0) {
        // 0x8005CB80: addiu       $t9, $v1, -0x2000
        ctx->r25 = ADD32(ctx->r3, -0X2000);
            goto L_8005CB94;
    }
    // 0x8005CB80: addiu       $t9, $v1, -0x2000
    ctx->r25 = ADD32(ctx->r3, -0X2000);
    // 0x8005CB84: lw          $t2, 0x1F4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1F4);
    // 0x8005CB88: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8005CB8C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8005CB90: sh          $t9, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r25;
L_8005CB94:
    // 0x8005CB94: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8005CB98: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8005CB9C: bnel        $s4, $t0, L_8005CAB8
    if (ctx->r20 != ctx->r8) {
        // 0x8005CBA0: lw          $t9, 0x64($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X64);
            goto L_8005CAB8;
    }
    goto skip_2;
    // 0x8005CBA0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    skip_2:
L_8005CBA4:
    // 0x8005CBA4: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
L_8005CBA8:
    // 0x8005CBA8: lw          $t6, 0x1F4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X1F4);
    // 0x8005CBAC: sw          $s3, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r19;
    // 0x8005CBB0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8005CBB4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8005CBB8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8005CBBC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8005CBC0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8005CBC4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8005CBC8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CBCC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005CBD0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005CBD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005CBD8: jr          $ra
    // 0x8005CBDC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8005CBDC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80059BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059BB0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80059BB4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059BB8: lwc1        $f4, 0xBB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XBB4);
    // 0x80059BBC: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80059BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059BC4: add.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x80059BC8: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x80059BCC: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80059BD0: nop

    // 0x80059BD4: bc1f        L_80059BE0
    if (!c1cs) {
        // 0x80059BD8: nop
    
            goto L_80059BE0;
    }
    // 0x80059BD8: nop

    // 0x80059BDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059BE0:
    // 0x80059BE0: jr          $ra
    // 0x80059BE4: nop

    return;
    // 0x80059BE4: nop

;}
RECOMP_FUNC void func_8006E06C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E06C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006E078: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006E07C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8006E080: jal         0x8006DFC4
    // 0x8006E084: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    func_8006DFC4(rdram, ctx);
        goto after_0;
    // 0x8006E084: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
    // 0x8006E088: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006E08C: lbu         $v0, 0x7EA1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7EA1);
    // 0x8006E090: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006E094: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8006E098: beq         $v0, $at, L_8006E0B4
    if (ctx->r2 == ctx->r1) {
        // 0x8006E09C: addiu       $a0, $a0, -0x78D4
        ctx->r4 = ADD32(ctx->r4, -0X78D4);
            goto L_8006E0B4;
    }
    // 0x8006E09C: addiu       $a0, $a0, -0x78D4
    ctx->r4 = ADD32(ctx->r4, -0X78D4);
    // 0x8006E0A0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006E0A4: beq         $v0, $at, L_8006E0B4
    if (ctx->r2 == ctx->r1) {
        // 0x8006E0A8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006E0B4;
    }
    // 0x8006E0A8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006E0AC: bne         $v0, $at, L_8006E0D0
    if (ctx->r2 != ctx->r1) {
        // 0x8006E0B0: lui         $a1, 0x8007
        ctx->r5 = S32(0X8007 << 16);
            goto L_8006E0D0;
    }
    // 0x8006E0B0: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
L_8006E0B4:
    // 0x8006E0B4: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006E0B8: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x8006E0BC: addiu       $a2, $a2, -0x7770
    ctx->r6 = ADD32(ctx->r6, -0X7770);
    // 0x8006E0C0: jal         0x80068CF8
    // 0x8006E0C4: addiu       $a1, $a1, -0x7848
    ctx->r5 = ADD32(ctx->r5, -0X7848);
    func_80068CF8(rdram, ctx);
        goto after_1;
    // 0x8006E0C4: addiu       $a1, $a1, -0x7848
    ctx->r5 = ADD32(ctx->r5, -0X7848);
    after_1:
    // 0x8006E0C8: b           L_8006E0EC
    // 0x8006E0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006E0EC;
    // 0x8006E0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006E0D0:
    // 0x8006E0D0: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8006E0D4: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8006E0D8: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x8006E0DC: addiu       $a0, $a0, -0x78D4
    ctx->r4 = ADD32(ctx->r4, -0X78D4);
    // 0x8006E0E0: jal         0x80068CF8
    // 0x8006E0E4: addiu       $a1, $a1, -0x7848
    ctx->r5 = ADD32(ctx->r5, -0X7848);
    func_80068CF8(rdram, ctx);
        goto after_2;
    // 0x8006E0E4: addiu       $a1, $a1, -0x7848
    ctx->r5 = ADD32(ctx->r5, -0X7848);
    after_2:
    // 0x8006E0E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006E0EC:
    // 0x8006E0EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E0F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006E0F4: jr          $ra
    // 0x8006E0F8: nop

    return;
    // 0x8006E0F8: nop

;}
RECOMP_FUNC void pad_cleanup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB00: jr          $ra
    // 0x8007FB04: nop

    return;
    // 0x8007FB04: nop

;}
RECOMP_FUNC void func_8064CC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064CC60: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8064CC64: lui         $t6, 0x8065
    ctx->r14 = S32(RELOC_HI16(495, 0X29F4) << 16);
    // 0x8064CC68: addiu       $t6, $t6, -0x353C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(495, 0X29F4));
    // 0x8064CC6C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064CC70: jr          $ra
    // 0x8064CC74: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8064CC74: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8006D5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D5F0: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x8006D5F4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006D5F8: bnel        $t6, $at, L_8006D60C
    if (ctx->r14 != ctx->r1) {
        // 0x8006D5FC: lbu         $t7, 0x0($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X0);
            goto L_8006D60C;
    }
    goto skip_0;
    // 0x8006D5FC: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    skip_0:
    // 0x8006D600: jr          $ra
    // 0x8006D604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006D604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006D608: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
L_8006D60C:
    // 0x8006D60C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8006D610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006D614: bne         $t7, $zero, L_8006D628
    if (ctx->r15 != 0) {
        // 0x8006D618: nop
    
            goto L_8006D628;
    }
    // 0x8006D618: nop

    // 0x8006D61C: sb          $t8, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r24;
    // 0x8006D620: jr          $ra
    // 0x8006D624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006D624: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006D628:
    // 0x8006D628: jr          $ra
    // 0x8006D62C: nop

    return;
    // 0x8006D62C: nop

;}
RECOMP_FUNC void func_80026398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026398: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x8002639C: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x800263A0: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x800263A4: addiu       $t7, $t7, 0x62D8
    ctx->r15 = ADD32(ctx->r15, 0X62D8);
    // 0x800263A8: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800263AC: jr          $ra
    // 0x800263B0: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    return;
    // 0x800263B0: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8005B350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B350: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8005B354: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8005B358: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8005B35C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8005B360: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x8005B364: jr          $ra
    // 0x8005B368: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
    return;
    // 0x8005B368: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void func_80438C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438C7C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80438C80: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80438C84: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80438C88: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80438C8C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80438C90: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80438C94: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80438C98: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80438C9C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80438CA0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80438CA4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80438CA8: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x80438CAC: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80438CB0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80438CB4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80438CB8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80438CBC: lbu         $t1, 0x13($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X13);
    // 0x80438CC0: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80438CC4: sll         $t2, $a1, 24
    ctx->r10 = S32(ctx->r5 << 24);
    // 0x80438CC8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80438CCC: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80438CD0: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80438CD4: or          $t3, $t8, $t1
    ctx->r11 = ctx->r24 | ctx->r9;
    // 0x80438CD8: jr          $ra
    // 0x80438CDC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    return;
    // 0x80438CDC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void func_80474DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474DF0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474DF4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474DF8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474DFC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474E00: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474E04: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474E08: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474E0C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474E10: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474E14: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474E18: jr          $ra
    // 0x80474E1C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474E1C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8006EE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006EE78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006EE7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006EE80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006EE84: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8006EE88: jal         0x80048F84
    // 0x8006EE8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8006EE8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8006EE90: jal         0x8006E7F0
    // 0x8006EE94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006E7F0(rdram, ctx);
        goto after_1;
    // 0x8006EE94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006EE98: jal         0x8006E84C
    // 0x8006EE9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006E84C(rdram, ctx);
        goto after_2;
    // 0x8006EE9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8006EEA0: beql        $v0, $zero, L_8006EF24
    if (ctx->r2 == 0) {
        // 0x8006EEA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006EF24;
    }
    goto skip_0;
    // 0x8006EEA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8006EEA8: lw          $v0, 0x174($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174);
    // 0x8006EEAC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006EEB0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8006EEB4: sh          $t6, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r14;
    // 0x8006EEB8: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8006EEBC: beq         $t8, $zero, L_8006EF04
    if (ctx->r24 == 0) {
        // 0x8006EEC0: nop
    
            goto L_8006EF04;
    }
    // 0x8006EEC0: nop

    // 0x8006EEC4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8006EEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006EECC: lh          $t9, 0x10($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X10);
    // 0x8006EED0: beql        $t9, $zero, L_8006EEEC
    if (ctx->r25 == 0) {
        // 0x8006EED4: lh          $t0, 0x12($v1)
        ctx->r8 = MEM_H(ctx->r3, 0X12);
            goto L_8006EEEC;
    }
    goto skip_1;
    // 0x8006EED4: lh          $t0, 0x12($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X12);
    skip_1:
    // 0x8006EED8: jal         0x8005FA48
    // 0x8006EEDC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8005FA48(rdram, ctx);
        goto after_3;
    // 0x8006EEDC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x8006EEE0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8006EEE4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8006EEE8: lh          $t0, 0x12($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X12);
L_8006EEEC:
    // 0x8006EEEC: beql        $t0, $zero, L_8006EF10
    if (ctx->r8 == 0) {
        // 0x8006EEF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8006EF10;
    }
    goto skip_2;
    // 0x8006EEF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8006EEF4: jal         0x8005FAE0
    // 0x8006EEF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FAE0(rdram, ctx);
        goto after_4;
    // 0x8006EEF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8006EEFC: b           L_8006EF10
    // 0x8006EF00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8006EF10;
    // 0x8006EF00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8006EF04:
    // 0x8006EF04: jal         0x8005FCA8
    // 0x8006EF08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FCA8(rdram, ctx);
        goto after_5;
    // 0x8006EF08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8006EF0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8006EF10:
    // 0x8006EF10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006EF14: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8006EF18: jal         0x8006F070
    // 0x8006EF1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8006F070(rdram, ctx);
        goto after_6;
    // 0x8006EF1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8006EF20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006EF24:
    // 0x8006EF24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006EF28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006EF2C: jr          $ra
    // 0x8006EF30: nop

    return;
    // 0x8006EF30: nop

;}
RECOMP_FUNC void func_800366FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800366FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036704: jal         0x80021958
    // 0x80036708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80036708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003670C: bne         $v0, $zero, L_8003671C
    if (ctx->r2 != 0) {
        // 0x80036710: nop
    
            goto L_8003671C;
    }
    // 0x80036710: nop

    // 0x80036714: b           L_80036750
    // 0x80036718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036750;
    // 0x80036718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003671C:
    // 0x8003671C: jal         0x800415FC
    // 0x80036720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80036720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80036724: beq         $v0, $zero, L_80036734
    if (ctx->r2 == 0) {
        // 0x80036728: nop
    
            goto L_80036734;
    }
    // 0x80036728: nop

    // 0x8003672C: b           L_80036750
    // 0x80036730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036750;
    // 0x80036730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036734:
    // 0x80036734: jal         0x800361A8
    // 0x80036738: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800361A8(rdram, ctx);
        goto after_2;
    // 0x80036738: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8003673C: bnel        $v0, $zero, L_80036750
    if (ctx->r2 != 0) {
        // 0x80036740: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80036750;
    }
    goto skip_0;
    // 0x80036740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80036744: b           L_80036750
    // 0x80036748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036750;
    // 0x80036748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003674C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036750:
    // 0x80036750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036758: jr          $ra
    // 0x8003675C: nop

    return;
    // 0x8003675C: nop

;}
RECOMP_FUNC void func_8042EA5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EA5C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8042EA60: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X7F8) << 16);
    // 0x8042EA64: addiu       $t6, $t6, -0x1728
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X7F8));
    // 0x8042EA68: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8042EA6C: jr          $ra
    // 0x8042EA70: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8042EA70: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806D03E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D03E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D03EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D03F0: jal         0x806CFF8C
    // 0x806D03F4: nop

    func_806CFF8C(rdram, ctx);
        goto after_0;
    // 0x806D03F4: nop

    after_0:
    // 0x806D03F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D03FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D0400: jr          $ra
    // 0x806D0404: nop

    return;
    // 0x806D0404: nop

;}
RECOMP_FUNC void func_8005BBC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BBC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005BBCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005BBD0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005BBD4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8005BBD8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8005BBDC: jal         0x8005BA30
    // 0x8005BBE0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8005BA30(rdram, ctx);
        goto after_0;
    // 0x8005BBE0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8005BBE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005BBE8: beq         $v0, $at, L_8005BC58
    if (ctx->r2 == ctx->r1) {
        // 0x8005BBEC: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8005BC58;
    }
    // 0x8005BBEC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8005BBF0: lhu         $a2, 0x2E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2E);
    // 0x8005BBF4: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x8005BBF8: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x8005BBFC: subu        $a2, $a2, $at
    ctx->r6 = SUB32(ctx->r6, ctx->r1);
    // 0x8005BC00: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8005BC04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8005BC08: jal         0x80064D1C
    // 0x8005BC0C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x8005BC0C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8005BC10: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x8005BC14: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8005BC18: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8005BC1C: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x8005BC20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005BC24: jal         0x800675D0
    // 0x8005BC28: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x8005BC28: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8005BC2C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8005BC30: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005BC34: lhu         $t9, 0x2E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2E);
    // 0x8005BC38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005BC3C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005BC40: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005BC44: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8005BC48: addiu       $t8, $t8, -0x4BB0
    ctx->r24 = ADD32(ctx->r24, -0X4BB0);
    // 0x8005BC4C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8005BC50: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x8005BC54: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
L_8005BC58:
    // 0x8005BC58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005BC5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005BC60: jr          $ra
    // 0x8005BC64: nop

    return;
    // 0x8005BC64: nop

;}
RECOMP_FUNC void func_805DCAF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCAF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805DCAF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DCAFC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805DCB00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805DCB04: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x805DCB08: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805DCB0C: lui         $t7, 0x805E
    ctx->r15 = S32(RELOC_HI16(480, 0X2720) << 16);
    // 0x805DCB10: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805DCB14: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805DCB18: addiu       $t7, $t7, -0x2BE0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(480, 0X2720));
    // 0x805DCB1C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805DCB20: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805DCB24: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805DCB28: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805DCB2C: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x805DCB30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805DCB34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805DCB38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805DCB3C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x805DCB40: jal         0x80045A34
    // 0x805DCB44: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805DCB44: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x805DCB48: lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XC);
    // 0x805DCB4C: addiu       $at, $zero, 0x4194
    ctx->r1 = ADD32(0, 0X4194);
    // 0x805DCB50: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805DCB54: beq         $v1, $at, L_805DCB70
    if (ctx->r3 == ctx->r1) {
        // 0x805DCB58: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_805DCB70;
    }
    // 0x805DCB58: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x805DCB5C: addiu       $at, $zero, 0x4195
    ctx->r1 = ADD32(0, 0X4195);
    // 0x805DCB60: beq         $v1, $at, L_805DCB80
    if (ctx->r3 == ctx->r1) {
        // 0x805DCB64: nop
    
            goto L_805DCB80;
    }
    // 0x805DCB64: nop

    // 0x805DCB68: b           L_805DCB90
    // 0x805DCB6C: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
        goto L_805DCB90;
    // 0x805DCB6C: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
L_805DCB70:
    // 0x805DCB70: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X28C8) << 16);
    // 0x805DCB74: lwc1        $f4, -0x2A38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X28C8));
    // 0x805DCB78: b           L_805DCB8C
    // 0x805DCB7C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
        goto L_805DCB8C;
    // 0x805DCB7C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
L_805DCB80:
    // 0x805DCB80: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X28CC) << 16);
    // 0x805DCB84: lwc1        $f6, -0x2A34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X28CC));
    // 0x805DCB88: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
L_805DCB8C:
    // 0x805DCB8C: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
L_805DCB90:
    // 0x805DCB90: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805DCB94: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x805DCB98: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x805DCB9C: nop

    // 0x805DCBA0: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
    // 0x805DCBA4: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805DCBA8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x805DCBAC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x805DCBB0: jal         0x800653D8
    // 0x805DCBB4: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x805DCBB4: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
    after_1:
    // 0x805DCBB8: andi        $t5, $v0, 0x1F
    ctx->r13 = ctx->r2 & 0X1F;
    // 0x805DCBBC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x805DCBC0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x805DCBC4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805DCBC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805DCBCC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805DCBD0: jal         0x800653D8
    // 0x805DCBD4: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x805DCBD4: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    after_2:
    // 0x805DCBD8: andi        $t7, $v0, 0x1F
    ctx->r15 = ctx->r2 & 0X1F;
    // 0x805DCBDC: addiu       $t8, $t7, 0x1E
    ctx->r24 = ADD32(ctx->r15, 0X1E);
    // 0x805DCBE0: jal         0x800653D8
    // 0x805DCBE4: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x805DCBE4: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
    after_3:
    // 0x805DCBE8: andi        $t9, $v0, 0x1F
    ctx->r25 = ctx->r2 & 0X1F;
    // 0x805DCBEC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x805DCBF0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x805DCBF4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805DCBF8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805DCBFC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x805DCC00: jal         0x800653D8
    // 0x805DCC04: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x805DCC04: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
    after_4:
    // 0x805DCC08: andi        $t1, $v0, 0x1F
    ctx->r9 = ctx->r2 & 0X1F;
    // 0x805DCC0C: addiu       $t2, $t1, 0x1E
    ctx->r10 = ADD32(ctx->r9, 0X1E);
    // 0x805DCC10: sh          $t2, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r10;
    // 0x805DCC14: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x805DCC18: sh          $t3, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r11;
    // 0x805DCC1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805DCC20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805DCC24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805DCC28: jr          $ra
    // 0x805DCC2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x805DCC2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8079BD84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079BD84: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8079BD88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079BD8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079BD90: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079BD94: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8079BD98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8079BD9C: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x8079BDA0: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x8079BDA4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8079BDA8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8079BDAC: slti        $at, $t8, 0x1F0
    ctx->r1 = SIGNED(ctx->r24) < 0X1F0 ? 1 : 0;
    // 0x8079BDB0: bne         $at, $zero, L_8079BEB0
    if (ctx->r1 != 0) {
        // 0x8079BDB4: sw          $t8, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r24;
            goto L_8079BEB0;
    }
    // 0x8079BDB4: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x8079BDB8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8079BDBC: lw          $t1, 0xE94($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XE94);
    // 0x8079BDC0: addiu       $t0, $zero, 0x4144
    ctx->r8 = ADD32(0, 0X4144);
    // 0x8079BDC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8079BDC8: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x8079BDCC: lw          $t2, 0xE94($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XE94);
    // 0x8079BDD0: swc1        $f0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f0.u32l;
    // 0x8079BDD4: lw          $t3, 0xE94($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XE94);
    // 0x8079BDD8: jal         0x800653D8
    // 0x8079BDDC: swc1        $f0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f0.u32l;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8079BDDC: swc1        $f0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f0.u32l;
    after_0:
    // 0x8079BDE0: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x8079BDE4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8079BDE8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8079BDEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8079BDF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8079BDF4: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    // 0x8079BDF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8079BDFC: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8079BE00: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8079BE04: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x8079BE08: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8079BE0C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8079BE10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8079BE14: lw          $t5, -0x72CC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X72CC);
    // 0x8079BE18: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8079BE1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079BE20: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8079BE24: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8079BE28: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8079BE2C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8079BE30: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x8079BE34: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8079BE38: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x8079BE3C: lw          $t9, 0xC($t5)
    ctx->r25 = MEM_W(ctx->r13, 0XC);
    // 0x8079BE40: jalr        $t9
    // 0x8079BE44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8079BE44: nop

    after_1:
    // 0x8079BE48: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8079BE4C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8079BE50: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(829, 0XB14) << 16);
    // 0x8079BE54: lwc1        $f16, -0x3D7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(829, 0XB14));
    // 0x8079BE58: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8079BE5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8079BE60: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8079BE64: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8079BE68: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8079BE6C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8079BE70: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8079BE74: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8079BE78: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8079BE7C: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8079BE80: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8079BE84: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8079BE88: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8079BE8C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8079BE90: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8079BE94: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8079BE98: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8079BE9C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8079BEA0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8079BEA4: lw          $t9, 0x28($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X28);
    // 0x8079BEA8: jalr        $t9
    // 0x8079BEAC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8079BEAC: nop

    after_2:
L_8079BEB0:
    // 0x8079BEB0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8079BEB4: lw          $t8, -0x7290($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7290);
    // 0x8079BEB8: lbu         $t0, 0x41($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X41);
    // 0x8079BEBC: bnel        $t0, $zero, L_8079BF74
    if (ctx->r8 != 0) {
        // 0x8079BEC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8079BF74;
    }
    goto skip_0;
    // 0x8079BEC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8079BEC4: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8079BEC8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8079BECC: andi        $t1, $v0, 0xF
    ctx->r9 = ctx->r2 & 0XF;
    // 0x8079BED0: bne         $t1, $zero, L_8079BF70
    if (ctx->r9 != 0) {
        // 0x8079BED4: andi        $a1, $v0, 0xE0
        ctx->r5 = ctx->r2 & 0XE0;
            goto L_8079BF70;
    }
    // 0x8079BED4: andi        $a1, $v0, 0xE0
    ctx->r5 = ctx->r2 & 0XE0;
    // 0x8079BED8: sra         $a1, $a1, 5
    ctx->r5 = S32(SIGNED(ctx->r5) >> 5);
    // 0x8079BEDC: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8079BEE0: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8079BEE4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8079BEE8: bnel        $t4, $zero, L_8079BF74
    if (ctx->r12 != 0) {
        // 0x8079BEEC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8079BF74;
    }
    goto skip_1;
    // 0x8079BEEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8079BEF0: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x8079BEF4: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    // 0x8079BEF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8079BEFC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8079BF00: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8079BF04: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8079BF08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8079BF0C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8079BF10: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8079BF14: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8079BF18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8079BF1C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(829, 0XB18) << 16);
    // 0x8079BF20: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8079BF24: lwc1        $f6, -0x3D78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(829, 0XB18));
    // 0x8079BF28: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8079BF2C: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8079BF30: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8079BF34: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8079BF38: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8079BF3C: jal         0x8079B8B0
    // 0x8079BF40: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    func_8079B8B0(rdram, ctx);
        goto after_3;
    // 0x8079BF40: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8079BF44: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8079BF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079BF4C: beq         $v0, $zero, L_8079BF70
    if (ctx->r2 == 0) {
        // 0x8079BF50: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8079BF70;
    }
    // 0x8079BF50: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8079BF54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8079BF58: jal         0x80047F9C
    // 0x8079BF5C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x8079BF5C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x8079BF60: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8079BF64: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8079BF68: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8079BF6C: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
L_8079BF70:
    // 0x8079BF70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079BF74:
    // 0x8079BF74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079BF78: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8079BF7C: jr          $ra
    // 0x8079BF80: nop

    return;
    // 0x8079BF80: nop

;}
RECOMP_FUNC void func_80437B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437B74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80437B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80437B7C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437B80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80437B84: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80437B88: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80437B8C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80437B90: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80437B94: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80437B98: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x80437B9C: jal         0x8004A97C
    // 0x80437BA0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8004A97C(rdram, ctx);
        goto after_0;
    // 0x80437BA0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80437BA4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80437BA8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80437BAC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80437BB0: jal         0x80066DE4
    // 0x80437BB4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80437BB4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80437BB8: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80437BBC: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80437BC0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80437BC4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80437BC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80437BCC: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F70) << 16);
    // 0x80437BD0: lwc1        $f8, -0x77F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F70));
    // 0x80437BD4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80437BD8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80437BDC: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80437BE0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80437BE4: nop

    // 0x80437BE8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80437BEC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80437BF0: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80437BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80437BF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80437BFC: jr          $ra
    // 0x80437C00: nop

    return;
    // 0x80437C00: nop

;}
RECOMP_FUNC void func_800464BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800464BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800464C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800464C4: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800464C8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800464CC: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x800464D0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800464D4: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800464D8: beq         $at, $zero, L_80046518
    if (ctx->r1 == 0) {
        // 0x800464DC: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_80046518;
    }
    // 0x800464DC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800464E0: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800464E4: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x800464E8: addu        $v0, $t6, $a3
    ctx->r2 = ADD32(ctx->r14, ctx->r7);
L_800464EC:
    // 0x800464EC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800464F0: bnel        $t7, $zero, L_8004650C
    if (ctx->r15 != 0) {
        // 0x800464F4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8004650C;
    }
    goto skip_0;
    // 0x800464F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x800464F8: jal         0x80046448
    // 0x800464FC: nop

    func_80046448(rdram, ctx);
        goto after_0;
    // 0x800464FC: nop

    after_0:
    // 0x80046500: b           L_80046554
    // 0x80046504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80046554;
    // 0x80046504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046508: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8004650C:
    // 0x8004650C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80046510: bne         $at, $zero, L_800464EC
    if (ctx->r1 != 0) {
        // 0x80046514: addiu       $v0, $v0, 0x280
        ctx->r2 = ADD32(ctx->r2, 0X280);
            goto L_800464EC;
    }
    // 0x80046514: addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, 0X280);
L_80046518:
    // 0x80046518: blez        $a2, L_8004654C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8004651C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8004654C;
    }
    // 0x8004651C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80046520: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80046524:
    // 0x80046524: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80046528: bnel        $t8, $zero, L_80046544
    if (ctx->r24 != 0) {
        // 0x8004652C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80046544;
    }
    goto skip_1;
    // 0x8004652C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x80046530: jal         0x80046448
    // 0x80046534: nop

    func_80046448(rdram, ctx);
        goto after_1;
    // 0x80046534: nop

    after_1:
    // 0x80046538: b           L_80046554
    // 0x8004653C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80046554;
    // 0x8004653C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046540: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80046544:
    // 0x80046544: bne         $a1, $a2, L_80046524
    if (ctx->r5 != ctx->r6) {
        // 0x80046548: addiu       $v0, $v0, 0x280
        ctx->r2 = ADD32(ctx->r2, 0X280);
            goto L_80046524;
    }
    // 0x80046548: addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, 0X280);
L_8004654C:
    // 0x8004654C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80046550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80046554:
    // 0x80046554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046558: jr          $ra
    // 0x8004655C: nop

    return;
    // 0x8004655C: nop

;}
RECOMP_FUNC void func_800259A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800259A4: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x800259A8: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x800259AC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800259B0: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x800259B4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800259B8: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x800259BC: bnel        $at, $zero, L_800259F4
    if (ctx->r1 != 0) {
        // 0x800259C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800259F4;
    }
    goto skip_0;
    // 0x800259C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800259C4: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x800259C8: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x800259CC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800259D0: sw          $t1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r9;
    // 0x800259D4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800259D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800259DC: sltu        $at, $t1, $t3
    ctx->r1 = ctx->r9 < ctx->r11 ? 1 : 0;
    // 0x800259E0: bnel        $at, $zero, L_800259F4
    if (ctx->r1 != 0) {
        // 0x800259E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800259F4;
    }
    goto skip_1;
    // 0x800259E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800259E8: jr          $ra
    // 0x800259EC: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    return;
    // 0x800259EC: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x800259F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800259F4:
    // 0x800259F4: jr          $ra
    // 0x800259F8: nop

    return;
    // 0x800259F8: nop

;}
RECOMP_FUNC void func_8001B770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B770: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B774: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B778: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B77C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001B780: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001B784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B788: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001B78C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8001B790: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001B794: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x8001B798: jal         0x8001B84C
    // 0x8001B79C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8001B84C(rdram, ctx);
        goto after_0;
    // 0x8001B79C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001B7A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B7A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001B7A8: jr          $ra
    // 0x8001B7AC: nop

    return;
    // 0x8001B7AC: nop

;}
RECOMP_FUNC void bootclear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067400: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80067404: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80067408: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x8006740C: lw          $t6, 0x318($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X318);
    // 0x80067410: addiu       $a0, $a0, 0x2CA0
    ctx->r4 = ADD32(ctx->r4, 0X2CA0);
    // 0x80067414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067418: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8006741C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067420: and         $t7, $a0, $at
    ctx->r15 = ctx->r4 & ctx->r1;
    // 0x80067424: jal         0x80084820
    // 0x80067428: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x80067428: subu        $a1, $t6, $t7
    ctx->r5 = SUB32(ctx->r14, ctx->r15);
    after_0:
    // 0x8006742C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067434: jr          $ra
    // 0x80067438: nop

    return;
    // 0x80067438: nop

;}
RECOMP_FUNC void func_80025564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025564: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80025568: addiu       $t6, $t6, 0x5398
    ctx->r14 = ADD32(ctx->r14, 0X5398);
    // 0x8002556C: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80025570: jr          $ra
    // 0x80025574: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80025574: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80044CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044CA0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80044CA4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80044CA8: lw          $t6, 0x3EC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3EC);
    // 0x80044CAC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80044CB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80044CB4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80044CB8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80044CBC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80044CC0: addiu       $t9, $t8, 0xA04
    ctx->r25 = ADD32(ctx->r24, 0XA04);
    // 0x80044CC4: sw          $t9, -0x776C($at)
    MEM_W(-0X776C, ctx->r1) = ctx->r25;
    // 0x80044CC8: lw          $t0, 0x3EC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X3EC);
    // 0x80044CCC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80044CD0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80044CD4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80044CD8: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80044CDC: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80044CE0: addiu       $t3, $t2, 0xA18
    ctx->r11 = ADD32(ctx->r10, 0XA18);
    // 0x80044CE4: sw          $t3, -0x7768($at)
    MEM_W(-0X7768, ctx->r1) = ctx->r11;
    // 0x80044CE8: lw          $t4, 0x3EC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X3EC);
    // 0x80044CEC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80044CF0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80044CF4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80044CF8: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80044CFC: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80044D00: addiu       $t7, $t6, 0xA2C
    ctx->r15 = ADD32(ctx->r14, 0XA2C);
    // 0x80044D04: sw          $t7, -0x7764($at)
    MEM_W(-0X7764, ctx->r1) = ctx->r15;
    // 0x80044D08: lw          $t8, 0x3EC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3EC);
    // 0x80044D0C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80044D10: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80044D14: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80044D18: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80044D1C: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80044D20: addiu       $t1, $t0, 0xA40
    ctx->r9 = ADD32(ctx->r8, 0XA40);
    // 0x80044D24: jr          $ra
    // 0x80044D28: sw          $t1, -0x7760($at)
    MEM_W(-0X7760, ctx->r1) = ctx->r9;
    return;
    // 0x80044D28: sw          $t1, -0x7760($at)
    MEM_W(-0X7760, ctx->r1) = ctx->r9;
;}
RECOMP_FUNC void func_807B9E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9E2C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807B9E30: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807B9E34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807B9E38: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B9E3C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807B9E40: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807B9E44: sb          $a3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r7;
    // 0x807B9E48: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
    // 0x807B9E4C: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x807B9E50: lui         $t2, 0x807C
    ctx->r10 = S32(RELOC_HI16(886, 0X1D50) << 16);
    // 0x807B9E54: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807B9E58: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807B9E5C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x807B9E60: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x807B9E64: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x807B9E68: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x807B9E6C: lw          $t2, -0x6040($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(886, 0X1D50));
    // 0x807B9E70: jr          $ra
    // 0x807B9E74: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    return;
    // 0x807B9E74: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x807B9E78: nop

    // 0x807B9E7C: nop

;}
RECOMP_FUNC void func_80737120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737120: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80737124: lui         $a1, 0x8074
    ctx->r5 = S32(RELOC_HI16(736, 0X3790) << 16);
    // 0x80737128: addiu       $a1, $a1, -0x6E10
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(736, 0X3790));
    // 0x8073712C: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80737130: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x80737134: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80737138: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x8073713C: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x80737140: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x80737144: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80737148: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8073714C: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80737150: bne         $at, $zero, L_80737170
    if (ctx->r1 != 0) {
        // 0x80737154: slti        $at, $t2, 0x10
        ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
            goto L_80737170;
    }
    // 0x80737154: slti        $at, $t2, 0x10
    ctx->r1 = SIGNED(ctx->r10) < 0X10 ? 1 : 0;
    // 0x80737158: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x8073715C: sw          $t2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r10;
    // 0x80737160: bne         $at, $zero, L_80737170
    if (ctx->r1 != 0) {
        // 0x80737164: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80737170;
    }
    // 0x80737164: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80737168: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x8073716C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80737170:
    // 0x80737170: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x80737174: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x80737178: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8073717C: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(736, 0X2650) << 16);
    // 0x80737180: addiu       $t7, $t7, -0x7F50
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(736, 0X2650));
    // 0x80737184: sll         $t6, $t5, 7
    ctx->r14 = S32(ctx->r13 << 7);
    // 0x80737188: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8073718C: jr          $ra
    // 0x80737190: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    return;
    // 0x80737190: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_804BCF58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BCF58: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804BCF5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BCF60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BCF64: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804BCF68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804BCF6C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x804BCF70: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804BCF74: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x804BCF78: lwc1        $f8, 0x74($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X74);
    // 0x804BCF7C: addiu       $a0, $zero, 0x412A
    ctx->r4 = ADD32(0, 0X412A);
    // 0x804BCF80: jal         0x80047090
    // 0x804BCF84: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804BCF84: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x804BCF88: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804BCF8C: beq         $v0, $at, L_804BD04C
    if (ctx->r2 == ctx->r1) {
        // 0x804BCF90: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804BD04C;
    }
    // 0x804BCF90: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804BCF94: lui         $at, 0x412A
    ctx->r1 = S32(0X412A << 16);
    // 0x804BCF98: ori         $at, $at, 0x800
    ctx->r1 = ctx->r1 | 0X800;
    // 0x804BCF9C: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804BCFA0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4194) << 16);
    // 0x804BCFA4: lwc1        $f10, -0x53C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4194));
    // 0x804BCFA8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804BCFAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804BCFB0: sh          $v1, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r3;
    // 0x804BCFB4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804BCFB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804BCFBC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x804BCFC0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x804BCFC4: jal         0x8004613C
    // 0x804BCFC8: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804BCFC8: nop

    after_1:
    // 0x804BCFCC: lhu         $v1, 0x32($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X32);
    // 0x804BCFD0: beq         $v0, $zero, L_804BD044
    if (ctx->r2 == 0) {
        // 0x804BCFD4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804BD044;
    }
    // 0x804BCFD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804BCFD8: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x804BCFDC: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x804BCFE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BCFE4: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x804BCFE8: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x804BCFEC: sh          $t0, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r8;
    // 0x804BCFF0: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x804BCFF4: sw          $t1, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r9;
    // 0x804BCFF8: jal         0x80047F9C
    // 0x804BCFFC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804BCFFC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_2:
    // 0x804BD000: jal         0x804BD0C8
    // 0x804BD004: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_804BD0C8(rdram, ctx);
        goto after_3;
    // 0x804BD004: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x804BD008: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x804BD00C: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x804BD010: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x804BD014: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804BD018: sw          $a1, 0x370($t2)
    MEM_W(0X370, ctx->r10) = ctx->r5;
    // 0x804BD01C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804BD020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804BD024: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804BD028: swc1        $f6, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f6.u32l;
    // 0x804BD02C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804BD030: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804BD034: swc1        $f10, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f10.u32l;
    // 0x804BD038: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804BD03C: b           L_804BD050
    // 0x804BD040: swc1        $f16, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->f16.u32l;
        goto L_804BD050;
    // 0x804BD040: swc1        $f16, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->f16.u32l;
L_804BD044:
    // 0x804BD044: b           L_804BD050
    // 0x804BD048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BD050;
    // 0x804BD048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BD04C:
    // 0x804BD04C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BD050:
    // 0x804BD050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BD054: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BD058: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804BD05C: jr          $ra
    // 0x804BD060: nop

    return;
    // 0x804BD060: nop

;}
RECOMP_FUNC void func_805A1B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1B90: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805A1B94: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(411, 0X6B8) << 16);
    // 0x805A1B98: addiu       $t6, $t6, 0x1A28
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(411, 0X6B8));
    // 0x805A1B9C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805A1BA0: jr          $ra
    // 0x805A1BA4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x805A1BA4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
