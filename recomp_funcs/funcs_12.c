#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80036614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003661C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80036620: jal         0x800411AC
    // 0x80036624: lbu         $a1, -0x7684($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X7684);
    func_800411AC(rdram, ctx);
        goto after_0;
    // 0x80036624: lbu         $a1, -0x7684($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X7684);
    after_0:
    // 0x80036628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003662C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036630: jr          $ra
    // 0x80036634: nop

    return;
    // 0x80036634: nop

;}
RECOMP_FUNC void func_804CB1AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CB1AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804CB1B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CB1B4: jal         0x8004700C
    // 0x804CB1B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804CB1B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CB1BC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13D8) << 16);
    // 0x804CB1C0: lwc1        $f4, -0x40E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13D8));
    // 0x804CB1C4: lwc1        $f0, 0xC4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x804CB1C8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x804CB1CC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13DC) << 16);
    // 0x804CB1D0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804CB1D4: lwc1        $f12, 0x50($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X50);
    // 0x804CB1D8: bc1t        L_804CB1F0
    if (c1cs) {
        // 0x804CB1DC: nop
    
            goto L_804CB1F0;
    }
    // 0x804CB1DC: nop

    // 0x804CB1E0: lwc1        $f6, -0x40E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13DC));
    // 0x804CB1E4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804CB1E8: nop

    // 0x804CB1EC: bc1f        L_804CB214
    if (!c1cs) {
        // 0x804CB1F0: lui         $at, 0x804D
        ctx->r1 = S32(RELOC_HI16(231, 0X1330) << 16);
            goto L_804CB214;
    }
L_804CB1F0:
    // 0x804CB1F0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1330) << 16);
    // 0x804CB1F4: lwc1        $f8, -0x4190($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1330));
    // 0x804CB1F8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x804CB1FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804CB200: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804CB204: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804CB208: mul.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x804CB20C: b           L_804CB224
    // 0x804CB210: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
        goto L_804CB224;
    // 0x804CB210: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
L_804CB214:
    // 0x804CB214: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804CB218: nop

    // 0x804CB21C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x804CB220: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
L_804CB224:
    // 0x804CB224: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13E0) << 16);
    // 0x804CB228: lbu         $t7, 0x12E8($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X12E8);
    // 0x804CB22C: bne         $t7, $zero, L_804CB260
    if (ctx->r15 != 0) {
        // 0x804CB230: nop
    
            goto L_804CB260;
    }
    // 0x804CB230: nop

    // 0x804CB234: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x804CB238: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804CB23C: bc1fl       L_804CB258
    if (!c1cs) {
        // 0x804CB240: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_804CB258;
    }
    goto skip_0;
    // 0x804CB240: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x804CB244: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804CB248: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804CB24C: b           L_804CB324
    // 0x804CB250: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
        goto L_804CB324;
    // 0x804CB250: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x804CB254: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_804CB258:
    // 0x804CB258: b           L_804CB324
    // 0x804CB25C: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
        goto L_804CB324;
    // 0x804CB25C: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
L_804CB260:
    // 0x804CB260: lwc1        $f14, -0x40E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13E0));
    // 0x804CB264: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13E4) << 16);
    // 0x804CB268: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x804CB26C: nop

    // 0x804CB270: bc1f        L_804CB290
    if (!c1cs) {
        // 0x804CB274: nop
    
            goto L_804CB290;
    }
    // 0x804CB274: nop

    // 0x804CB278: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804CB27C: nop

    // 0x804CB280: bc1f        L_804CB290
    if (!c1cs) {
        // 0x804CB284: nop
    
            goto L_804CB290;
    }
    // 0x804CB284: nop

    // 0x804CB288: b           L_804CB2B8
    // 0x804CB28C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_804CB2B8;
    // 0x804CB28C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_804CB290:
    // 0x804CB290: lwc1        $f14, -0x40DC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13E4));
    // 0x804CB294: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x804CB298: nop

    // 0x804CB29C: bc1fl       L_804CB2BC
    if (!c1cs) {
        // 0x804CB2A0: lbu         $t8, 0xF4($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0XF4);
            goto L_804CB2BC;
    }
    goto skip_1;
    // 0x804CB2A0: lbu         $t8, 0xF4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF4);
    skip_1:
    // 0x804CB2A4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x804CB2A8: nop

    // 0x804CB2AC: bc1fl       L_804CB2BC
    if (!c1cs) {
        // 0x804CB2B0: lbu         $t8, 0xF4($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0XF4);
            goto L_804CB2BC;
    }
    goto skip_2;
    // 0x804CB2B0: lbu         $t8, 0xF4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF4);
    skip_2:
    // 0x804CB2B4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_804CB2B8:
    // 0x804CB2B8: lbu         $t8, 0xF4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF4);
L_804CB2BC:
    // 0x804CB2BC: beql        $t8, $zero, L_804CB304
    if (ctx->r24 == 0) {
        // 0x804CB2C0: swc1        $f2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
            goto L_804CB304;
    }
    goto skip_3;
    // 0x804CB2C0: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    skip_3:
    // 0x804CB2C4: lwc1        $f8, 0xC8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x804CB2C8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x804CB2CC: nop

    // 0x804CB2D0: bc1fl       L_804CB304
    if (!c1cs) {
        // 0x804CB2D4: swc1        $f2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
            goto L_804CB304;
    }
    goto skip_4;
    // 0x804CB2D4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    skip_4:
    // 0x804CB2D8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x804CB2DC: jal         0x80066DE4
    // 0x804CB2E0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x804CB2E0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x804CB2E4: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1360) << 16);
    // 0x804CB2E8: lwc1        $f10, -0x4160($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1360));
    // 0x804CB2EC: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804CB2F0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804CB2F4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804CB2F8: b           L_804CB324
    // 0x804CB2FC: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
        goto L_804CB324;
    // 0x804CB2FC: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x804CB300: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
L_804CB304:
    // 0x804CB304: jal         0x80066DE4
    // 0x804CB308: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x804CB308: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x804CB30C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1348) << 16);
    // 0x804CB310: lwc1        $f4, -0x4178($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1348));
    // 0x804CB314: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804CB318: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804CB31C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804CB320: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
L_804CB324:
    // 0x804CB324: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1378) << 16);
    // 0x804CB328: lwc1        $f14, -0x4148($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1378));
    // 0x804CB32C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804CB330: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x804CB334: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x804CB338: nop

    // 0x804CB33C: bc1fl       L_804CB350
    if (!c1cs) {
        // 0x804CB340: neg.s       $f16, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
            goto L_804CB350;
    }
    goto skip_5;
    // 0x804CB340: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
    skip_5:
    // 0x804CB344: b           L_804CB370
    // 0x804CB348: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_804CB370;
    // 0x804CB348: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x804CB34C: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
L_804CB350:
    // 0x804CB350: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x804CB354: nop

    // 0x804CB358: bc1fl       L_804CB36C
    if (!c1cs) {
        // 0x804CB35C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_804CB36C;
    }
    goto skip_6;
    // 0x804CB35C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_6:
    // 0x804CB360: b           L_804CB36C
    // 0x804CB364: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804CB36C;
    // 0x804CB364: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804CB368: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_804CB36C:
    // 0x804CB36C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_804CB370:
    // 0x804CB370: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x804CB374: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804CB378: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x804CB37C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x804CB380: nop

    // 0x804CB384: bc1fl       L_804CB398
    if (!c1cs) {
        // 0x804CB388: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_804CB398;
    }
    goto skip_7;
    // 0x804CB388: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_7:
    // 0x804CB38C: b           L_804CB3BC
    // 0x804CB390: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_804CB3BC;
    // 0x804CB390: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x804CB394: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_804CB398:
    // 0x804CB398: nop

    // 0x804CB39C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x804CB3A0: nop

    // 0x804CB3A4: bc1fl       L_804CB3B8
    if (!c1cs) {
        // 0x804CB3A8: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_804CB3B8;
    }
    goto skip_8;
    // 0x804CB3A8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_8:
    // 0x804CB3AC: b           L_804CB3B8
    // 0x804CB3B0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_804CB3B8;
    // 0x804CB3B0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804CB3B4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_804CB3B8:
    // 0x804CB3B8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_804CB3BC:
    // 0x804CB3BC: swc1        $f12, 0x50($t9)
    MEM_W(0X50, ctx->r25) = ctx->f12.u32l;
    // 0x804CB3C0: jal         0x80066DE4
    // 0x804CB3C4: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x804CB3C4: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x804CB3C8: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804CB3CC: jal         0x80066E88
    // 0x804CB3D0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x804CB3D0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x804CB3D4: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804CB3D8: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x804CB3DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804CB3E0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x804CB3E4: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x804CB3E8: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x804CB3EC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x804CB3F0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x804CB3F4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x804CB3F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804CB3FC: swc1        $f18, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f18.u32l;
    // 0x804CB400: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x804CB404: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x804CB408: swc1        $f10, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f10.u32l;
    // 0x804CB40C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CB410: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804CB414: jr          $ra
    // 0x804CB418: nop

    return;
    // 0x804CB418: nop

;}
RECOMP_FUNC void func_80048E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048EA4: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x80048EA8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80048EAC: bne         $t6, $at, L_80048EBC
    if (ctx->r14 != ctx->r1) {
        // 0x80048EB0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80048EBC;
    }
    // 0x80048EB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80048EB4: b           L_80048ECC
    // 0x80048EB8: sw          $a1, -0x6580($at)
    MEM_W(-0X6580, ctx->r1) = ctx->r5;
        goto L_80048ECC;
    // 0x80048EB8: sw          $a1, -0x6580($at)
    MEM_W(-0X6580, ctx->r1) = ctx->r5;
L_80048EBC:
    // 0x80048EBC: jal         0x80048BD8
    // 0x80048EC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80048BD8(rdram, ctx);
        goto after_0;
    // 0x80048EC0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80048EC4: jal         0x8006D340
    // 0x80048EC8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8006D340(rdram, ctx);
        goto after_1;
    // 0x80048EC8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80048ECC:
    // 0x80048ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80048ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048ED4: jr          $ra
    // 0x80048ED8: nop

    return;
    // 0x80048ED8: nop

;}
RECOMP_FUNC void func_80064BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064BAC: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80064BB0: addiu       $a2, $a2, -0x6C08
    ctx->r6 = ADD32(ctx->r6, -0X6C08);
    // 0x80064BB4: lui         $t6, 0x8020
    ctx->r14 = S32(0X8020 << 16);
    // 0x80064BB8: addiu       $t6, $t6, 0x78B0
    ctx->r14 = ADD32(ctx->r14, 0X78B0);
    // 0x80064BBC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80064BC0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80064BC4: addiu       $a1, $a1, -0x6C0C
    ctx->r5 = ADD32(ctx->r5, -0X6C0C);
    // 0x80064BC8: addiu       $a0, $a0, -0x6C10
    ctx->r4 = ADD32(ctx->r4, -0X6C10);
    // 0x80064BCC: addiu       $a3, $zero, 0x913
    ctx->r7 = ADD32(0, 0X913);
    // 0x80064BD0: lui         $t7, 0x8040
    ctx->r15 = S32(0X8040 << 16);
    // 0x80064BD4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80064BD8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80064BDC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80064BE0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80064BE4: sh          $a3, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r7;
    // 0x80064BE8: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x80064BEC: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80064BF0: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x80064BF4: sw          $t9, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r25;
    // 0x80064BF8: subu        $t1, $t7, $t6
    ctx->r9 = SUB32(ctx->r15, ctx->r14);
    // 0x80064BFC: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x80064C00: sh          $a3, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r7;
    // 0x80064C04: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x80064C08: sw          $a2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r6;
    // 0x80064C0C: jr          $ra
    // 0x80064C10: sw          $a2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r6;
    return;
    // 0x80064C10: sw          $a2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r6;
;}
RECOMP_FUNC void func_807B908C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B908C: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x807B9090: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x807B9094: lw          $v1, 0xFB8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XFB8);
    // 0x807B9098: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B909C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x807B90A0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x807B90A4: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x807B90A8: bne         $v1, $zero, L_807B90C4
    if (ctx->r3 != 0) {
        // 0x807B90AC: nop
    
            goto L_807B90C4;
    }
    // 0x807B90AC: nop

    // 0x807B90B0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x807B90B4: lbu         $t6, 0xFB8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XFB8);
    // 0x807B90B8: andi        $t7, $t6, 0xFFF3
    ctx->r15 = ctx->r14 & 0XFFF3;
    // 0x807B90BC: jr          $ra
    // 0x807B90C0: sb          $t7, 0xFB8($a1)
    MEM_B(0XFB8, ctx->r5) = ctx->r15;
    return;
    // 0x807B90C0: sb          $t7, 0xFB8($a1)
    MEM_B(0XFB8, ctx->r5) = ctx->r15;
L_807B90C4:
    // 0x807B90C4: bne         $a0, $v1, L_807B90E0
    if (ctx->r4 != ctx->r3) {
        // 0x807B90C8: nop
    
            goto L_807B90E0;
    }
    // 0x807B90C8: nop

    // 0x807B90CC: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x807B90D0: lbu         $t8, 0xFB8($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XFB8);
    // 0x807B90D4: andi        $t9, $t8, 0xFFF3
    ctx->r25 = ctx->r24 & 0XFFF3;
    // 0x807B90D8: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x807B90DC: sb          $t0, 0xFB8($a1)
    MEM_B(0XFB8, ctx->r5) = ctx->r8;
L_807B90E0:
    // 0x807B90E0: jr          $ra
    // 0x807B90E4: nop

    return;
    // 0x807B90E4: nop

;}
RECOMP_FUNC void func_80059CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059CA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059CA8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80059CAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059CB0: lwc1        $f0, 0xBC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XBC4);
    // 0x80059CB4: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80059CB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059CBC: lw          $v0, 0xD8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XD8);
    // 0x80059CC0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80059CC4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059CC8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80059CCC: bc1t        L_80059CF0
    if (c1cs) {
        // 0x80059CD0: nop
    
            goto L_80059CF0;
    }
    // 0x80059CD0: nop

    // 0x80059CD4: lwc1        $f4, 0xBC8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XBC8);
    // 0x80059CD8: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x80059CDC: nop

    // 0x80059CE0: bc1t        L_80059CF0
    if (c1cs) {
        // 0x80059CE4: nop
    
            goto L_80059CF0;
    }
    // 0x80059CE4: nop

    // 0x80059CE8: b           L_80059D4C
    // 0x80059CEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80059D4C;
    // 0x80059CEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059CF0:
    // 0x80059CF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059CF4: lwc1        $f6, 0xBCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XBCC);
    // 0x80059CF8: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x80059CFC: nop

    // 0x80059D00: bc1fl       L_80059D24
    if (!c1cs) {
        // 0x80059D04: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_80059D24;
    }
    goto skip_0;
    // 0x80059D04: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_0:
    // 0x80059D08: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80059D0C: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80059D10: jal         0x80059B78
    // 0x80059D14: lwc1        $f14, 0x50($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X50);
    func_80059B78(rdram, ctx);
        goto after_0;
    // 0x80059D14: lwc1        $f14, 0x50($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X50);
    after_0:
    // 0x80059D18: b           L_80059D50
    // 0x80059D1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80059D50;
    // 0x80059D1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059D20: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_80059D24:
    // 0x80059D24: nop

    // 0x80059D28: bc1fl       L_80059D4C
    if (!c1cs) {
        // 0x80059D2C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80059D4C;
    }
    goto skip_1;
    // 0x80059D2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80059D30: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80059D34: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80059D38: jal         0x80059BB0
    // 0x80059D3C: lwc1        $f14, 0x54($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X54);
    func_80059BB0(rdram, ctx);
        goto after_1;
    // 0x80059D3C: lwc1        $f14, 0x54($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X54);
    after_1:
    // 0x80059D40: b           L_80059D50
    // 0x80059D44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80059D50;
    // 0x80059D44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059D48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059D4C:
    // 0x80059D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80059D50:
    // 0x80059D50: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80059D54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80059D58: jr          $ra
    // 0x80059D5C: nop

    return;
    // 0x80059D5C: nop

;}
RECOMP_FUNC void func_8044FEC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044FEC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044FEC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044FECC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8044FED0: jal         0x80444408
    // 0x8044FED4: addiu       $a1, $zero, 0x40F5
    ctx->r5 = ADD32(0, 0X40F5);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x8044FED4: addiu       $a1, $zero, 0x40F5
    ctx->r5 = ADD32(0, 0X40F5);
    after_0:
    // 0x8044FED8: beq         $v0, $zero, L_8044FEE4
    if (ctx->r2 == 0) {
        // 0x8044FEDC: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_8044FEE4;
    }
    // 0x8044FEDC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8044FEE0: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
L_8044FEE4:
    // 0x8044FEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044FEE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044FEEC: jr          $ra
    // 0x8044FEF0: nop

    return;
    // 0x8044FEF0: nop

;}
RECOMP_FUNC void func_806DF4BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF4BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DF4C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF4C4: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x806DF4C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806DF4CC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806DF4D0: beq         $a1, $at, L_806DF4F4
    if (ctx->r5 == ctx->r1) {
        // 0x806DF4D4: addiu       $a0, $zero, 0x55
        ctx->r4 = ADD32(0, 0X55);
            goto L_806DF4F4;
    }
    // 0x806DF4D4: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x806DF4D8: jal         0x80067930
    // 0x806DF4DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x806DF4DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x806DF4E0: beq         $v0, $zero, L_806DF4F4
    if (ctx->r2 == 0) {
        // 0x806DF4E4: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_806DF4F4;
    }
    // 0x806DF4E4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806DF4E8: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x806DF4EC: jal         0x80067878
    // 0x806DF4F0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x806DF4F0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    after_1:
L_806DF4F4:
    // 0x806DF4F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DF4F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DF4FC: jr          $ra
    // 0x806DF500: nop

    return;
    // 0x806DF500: nop

;}
RECOMP_FUNC void func_8077056C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077056C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80770570: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80770574: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80770578: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8077057C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80770580: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80770584: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80770588: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8077058C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80770590: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80770594: jr          $ra
    // 0x80770598: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80770598: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8003B1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B1F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B1F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B1F8: jal         0x8003B004
    // 0x8003B1FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003B004(rdram, ctx);
        goto after_0;
    // 0x8003B1FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B200: jal         0x8003B6F8
    // 0x8003B204: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003B6F8(rdram, ctx);
        goto after_1;
    // 0x8003B204: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003B208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B20C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B210: jr          $ra
    // 0x8003B214: nop

    return;
    // 0x8003B214: nop

;}
RECOMP_FUNC void func_8006C530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C530: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006C534: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8006C538: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006C53C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8006C540: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006C544: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8006C548: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006C54C: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x8006C550: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8006C554: swc1        $f10, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f10.u32l;
    // 0x8006C558: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8006C55C: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    // 0x8006C560: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006C564: jr          $ra
    // 0x8006C568: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x8006C568: swc1        $f18, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void Fault_ResumeThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070EA0: lui         $t0, 0xFFFA
    ctx->r8 = S32(0XFFFA << 16);
    // 0x80070EA4: or          $t1, $sp, $zero
    ctx->r9 = ctx->r29 | 0;
    // 0x80070EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070EAC: ori         $t0, $t0, 0x5A5A
    ctx->r8 = ctx->r8 | 0X5A5A;
L_80070EB0:
    // 0x80070EB0: addiu       $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x80070EB4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80070EB8: bne         $t1, $sp, L_80070EB0
    if (ctx->r9 != ctx->r29) {
        // 0x80070EBC: sw          $t0, 0x4($t1)
        MEM_W(0X4, ctx->r9) = ctx->r8;
            goto L_80070EB0;
    }
    // 0x80070EBC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x80070EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070EC4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80070EC8: lw          $t6, 0x11C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X11C);
    // 0x80070ECC: sw          $zero, 0x120($a2)
    MEM_W(0X120, ctx->r6) = 0;
    // 0x80070ED0: sw          $zero, 0x12C($a2)
    MEM_W(0X12C, ctx->r6) = 0;
    // 0x80070ED4: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x80070ED8: sw          $t7, 0x11C($a2)
    MEM_W(0X11C, ctx->r6) = ctx->r15;
    // 0x80070EDC: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x80070EE0: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80070EE4: lw          $a0, 0x11C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X11C);
    // 0x80070EE8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80070EEC: jal         0x80085FE0
    // 0x80070EF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80070EF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80070EF4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80070EF8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80070EFC: jal         0x8008AE50
    // 0x80070F00: lw          $a0, 0x11C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X11C);
    osInvalICache_recomp(rdram, ctx);
        goto after_1;
    // 0x80070F00: lw          $a0, 0x11C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X11C);
    after_1:
    // 0x80070F04: jal         0x80090CC0
    // 0x80070F08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80070F08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80070F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070F14: jr          $ra
    // 0x80070F18: nop

    return;
    // 0x80070F18: nop

;}
RECOMP_FUNC void func_8064B290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B290: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064B294: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064B298: jr          $ra
    // 0x8064B29C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8064B29C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_806CD900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD900: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CD904: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CD908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CD90C: jal         0x806CCF00
    // 0x806CD910: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CCF00(rdram, ctx);
        goto after_0;
    // 0x806CD910: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CD914: jal         0x806CD3D4
    // 0x806CD918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CD3D4(rdram, ctx);
        goto after_1;
    // 0x806CD918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CD91C: jal         0x806CCE38
    // 0x806CD920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCE38(rdram, ctx);
        goto after_2;
    // 0x806CD920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806CD924: beq         $v0, $zero, L_806CD944
    if (ctx->r2 == 0) {
        // 0x806CD928: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806CD944;
    }
    // 0x806CD928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD92C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CD930: jal         0x806CED40
    // 0x806CD934: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_806CED40(rdram, ctx);
        goto after_3;
    // 0x806CD934: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_3:
    // 0x806CD938: jal         0x806CCCE4
    // 0x806CD93C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCCE4(rdram, ctx);
        goto after_4;
    // 0x806CD93C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806CD940: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_806CD944:
    // 0x806CD944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806CD948: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CD94C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CD950: jr          $ra
    // 0x806CD954: nop

    return;
    // 0x806CD954: nop

;}
RECOMP_FUNC void func_80710448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80710448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8071044C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80710450: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x80710454: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80710458: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8071045C: lbu         $t6, 0x34($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X34);
    // 0x80710460: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80710464: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80710468: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8071046C: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x80710470: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80710474: lw          $a1, 0x1E4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X1E4);
    // 0x80710478: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x8071047C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80710480: jal         0x8070FCFC
    // 0x80710484: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8070FCFC(rdram, ctx);
        goto after_0;
    // 0x80710484: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80710488: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8071048C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80710490: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80710494: jal         0x8070FDDC
    // 0x80710498: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    func_8070FDDC(rdram, ctx);
        goto after_1;
    // 0x80710498: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, 0X120);
    after_1:
    // 0x8071049C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807104A0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x807104A4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x807104A8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x807104AC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x807104B0: lw          $t2, 0x1E0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X1E0);
    // 0x807104B4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x807104B8: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x807104BC: bne         $at, $zero, L_807104DC
    if (ctx->r1 != 0) {
        // 0x807104C0: sw          $t3, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r11;
            goto L_807104DC;
    }
    // 0x807104C0: sw          $t3, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r11;
    // 0x807104C4: lw          $t5, 0x1E4($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X1E4);
    // 0x807104C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807104CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x807104D0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x807104D4: jal         0x80710C50
    // 0x807104D8: sw          $t6, 0x1E4($a3)
    MEM_W(0X1E4, ctx->r7) = ctx->r14;
    func_80710C50(rdram, ctx);
        goto after_2;
    // 0x807104D8: sw          $t6, 0x1E4($a3)
    MEM_W(0X1E4, ctx->r7) = ctx->r14;
    after_2:
L_807104DC:
    // 0x807104DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807104E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807104E4: jr          $ra
    // 0x807104E8: nop

    return;
    // 0x807104E8: nop

;}
RECOMP_FUNC void func_80047488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047488: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004748C: lwc1        $f4, 0x8A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8A0);
    // 0x80047490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047498: jal         0x8004742C
    // 0x8004749C: swc1        $f4, 0xB0($a2)
    MEM_W(0XB0, ctx->r6) = ctx->f4.u32l;
    func_8004742C(rdram, ctx);
        goto after_0;
    // 0x8004749C: swc1        $f4, 0xB0($a2)
    MEM_W(0XB0, ctx->r6) = ctx->f4.u32l;
    after_0:
    // 0x800474A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800474A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800474A8: jr          $ra
    // 0x800474AC: nop

    return;
    // 0x800474AC: nop

;}
RECOMP_FUNC void func_8076D438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D438: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x8076D43C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8076D440: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8076D444: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8076D448: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8076D44C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8076D450: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8076D454: nop

    // 0x8076D458: bc1fl       L_8076D4D4
    if (!c1cs) {
        // 0x8076D45C: swc1        $f12, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
            goto L_8076D4D4;
    }
    goto skip_0;
    // 0x8076D45C: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    skip_0:
    // 0x8076D460: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8076D464: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8076D468: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8076D46C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8076D470: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8076D474: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8076D478: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8076D47C: nop

    // 0x8076D480: bc1fl       L_8076D494
    if (!c1cs) {
        // 0x8076D484: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8076D494;
    }
    goto skip_1;
    // 0x8076D484: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_1:
    // 0x8076D488: b           L_8076D4AC
    // 0x8076D48C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_8076D4AC;
    // 0x8076D48C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8076D490: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_8076D494:
    // 0x8076D494: nop

    // 0x8076D498: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8076D49C: nop

    // 0x8076D4A0: bc1fl       L_8076D4B0
    if (!c1cs) {
        // 0x8076D4A4: add.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_8076D4B0;
    }
    goto skip_2;
    // 0x8076D4A4: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    skip_2:
    // 0x8076D4A8: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_8076D4AC:
    // 0x8076D4AC: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
L_8076D4B0:
    // 0x8076D4B0: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8076D4B4: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8076D4B8: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8076D4BC: nop

    // 0x8076D4C0: bc1f        L_8076D4D8
    if (!c1cs) {
        // 0x8076D4C4: nop
    
            goto L_8076D4D8;
    }
    // 0x8076D4C4: nop

    // 0x8076D4C8: jr          $ra
    // 0x8076D4CC: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    return;
    // 0x8076D4CC: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    // 0x8076D4D0: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
L_8076D4D4:
    // 0x8076D4D4: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
L_8076D4D8:
    // 0x8076D4D8: jr          $ra
    // 0x8076D4DC: nop

    return;
    // 0x8076D4DC: nop

;}
RECOMP_FUNC void func_806FE468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FE468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FE46C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806FE470: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806FE474: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FE478: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806FE47C: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x806FE480: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806FE484: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(706, 0X1278) << 16);
    // 0x806FE488: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806FE48C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x806FE490: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806FE494: lw          $t9, -0x1928($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(706, 0X1278));
    // 0x806FE498: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806FE49C: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x806FE4A0: jal         0x806FD5C0
    // 0x806FE4A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806FD5C0(rdram, ctx);
        goto after_0;
    // 0x806FE4A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FE4A8: jal         0x806FD688
    // 0x806FE4AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806FD688(rdram, ctx);
        goto after_1;
    // 0x806FE4AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806FE4B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FE4B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FE4B8: jr          $ra
    // 0x806FE4BC: nop

    return;
    // 0x806FE4BC: nop

;}
RECOMP_FUNC void func_8046D100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046D100: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8046D104: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046D108: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046D10C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8046D110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8046D114: jal         0x8046C850
    // 0x8046D118: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8046C850(rdram, ctx);
        goto after_0;
    // 0x8046D118: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8046D11C: beql        $v0, $zero, L_8046D140
    if (ctx->r2 == 0) {
        // 0x8046D120: lw          $t7, 0x12C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X12C);
            goto L_8046D140;
    }
    goto skip_0;
    // 0x8046D120: lw          $t7, 0x12C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X12C);
    skip_0:
    // 0x8046D124: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8046D128: jal         0x80067BBC
    // 0x8046D12C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8046D12C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8046D130: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x8046D134: jal         0x80067818
    // 0x8046D138: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8046D138: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8046D13C: lw          $t7, 0x12C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X12C);
L_8046D140:
    // 0x8046D140: lui         $t9, 0x8047
    ctx->r25 = S32(RELOC_HI16(143, 0X139C) << 16);
    // 0x8046D144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046D148: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8046D14C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8046D150: lw          $t9, -0x2814($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(143, 0X139C));
    // 0x8046D154: jalr        $t9
    // 0x8046D158: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8046D158: nop

    after_3:
    // 0x8046D15C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8046D160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046D164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046D168: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8046D16C: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x8046D170: beql        $t2, $zero, L_8046D19C
    if (ctx->r10 == 0) {
        // 0x8046D174: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8046D19C;
    }
    goto skip_1;
    // 0x8046D174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8046D178: jal         0x8046D3E8
    // 0x8046D17C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_8046D3E8(rdram, ctx);
        goto after_4;
    // 0x8046D17C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_4:
    // 0x8046D180: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8046D184: jal         0x80067BBC
    // 0x8046D188: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8046D188: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8046D18C: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8046D190: jal         0x80067818
    // 0x8046D194: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8046D194: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8046D198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046D19C:
    // 0x8046D19C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046D1A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8046D1A4: jr          $ra
    // 0x8046D1A8: nop

    return;
    // 0x8046D1A8: nop

;}
RECOMP_FUNC void func_8069C8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069C8D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069C8D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8069C8DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8069C8E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069C8E4: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x8069C8E8: jal         0x80067878
    // 0x8069C8EC: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8069C8EC: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    after_0:
    // 0x8069C8F0: jal         0x80045BD8
    // 0x8069C8F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8069C8F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8069C8F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069C8FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069C900: jr          $ra
    // 0x8069C904: nop

    return;
    // 0x8069C904: nop

;}
RECOMP_FUNC void func_80535958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535958: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8053595C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80535960: addu        $t7, $a2, $v0
    ctx->r15 = ADD32(ctx->r6, ctx->r2);
    // 0x80535964: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80535968: bnel        $at, $zero, L_8053597C
    if (ctx->r1 != 0) {
        // 0x8053596C: lw          $t8, -0x4($t7)
        ctx->r24 = MEM_W(ctx->r15, -0X4);
            goto L_8053597C;
    }
    goto skip_0;
    // 0x8053596C: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    skip_0:
    // 0x80535970: jr          $ra
    // 0x80535974: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    return;
    // 0x80535974: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80535978: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
L_8053597C:
    // 0x8053597C: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x80535980: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80535984: bnel        $at, $zero, L_80535998
    if (ctx->r1 != 0) {
        // 0x80535988: slti        $at, $a3, 0x2
        ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_80535998;
    }
    goto skip_1;
    // 0x80535988: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    skip_1:
    // 0x8053598C: jr          $ra
    // 0x80535990: lwc1        $f0, -0x4($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, -0X4);
    return;
    // 0x80535990: lwc1        $f0, -0x4($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, -0X4);
    // 0x80535994: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
L_80535998:
    // 0x80535998: bne         $at, $zero, L_80535AF4
    if (ctx->r1 != 0) {
        // 0x8053599C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80535AF4;
    }
    // 0x8053599C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805359A0: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // 0x805359A4: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x805359A8: beql        $v1, $zero, L_80535A20
    if (ctx->r3 == 0) {
        // 0x805359AC: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_80535A20;
    }
    goto skip_2;
    // 0x805359AC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    skip_2:
    // 0x805359B0: addiu       $v0, $a2, 0x4
    ctx->r2 = ADD32(ctx->r6, 0X4);
    // 0x805359B4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x805359B8: bnel        $a0, $t0, L_805359CC
    if (ctx->r4 != ctx->r8) {
        // 0x805359BC: lw          $v1, -0x4($v0)
        ctx->r3 = MEM_W(ctx->r2, -0X4);
            goto L_805359CC;
    }
    goto skip_3;
    // 0x805359BC: lw          $v1, -0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X4);
    skip_3:
    // 0x805359C0: jr          $ra
    // 0x805359C4: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    return;
    // 0x805359C4: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x805359C8: lw          $v1, -0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X4);
L_805359CC:
    // 0x805359CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x805359D0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x805359D4: beq         $at, $zero, L_80535A18
    if (ctx->r1 == 0) {
        // 0x805359D8: slt         $at, $a0, $t0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80535A18;
    }
    // 0x805359D8: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x805359DC: beq         $at, $zero, L_80535A18
    if (ctx->r1 == 0) {
        // 0x805359E0: subu        $t3, $a0, $v1
        ctx->r11 = SUB32(ctx->r4, ctx->r3);
            goto L_80535A18;
    }
    // 0x805359E0: subu        $t3, $a0, $v1
    ctx->r11 = SUB32(ctx->r4, ctx->r3);
    // 0x805359E4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x805359E8: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x805359EC: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x805359F0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805359F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805359F8: subu        $t4, $t0, $v1
    ctx->r12 = SUB32(ctx->r8, ctx->r3);
    // 0x805359FC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80535A00: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80535A04: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80535A08: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80535A0C: div.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80535A10: jr          $ra
    // 0x80535A14: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    return;
    // 0x80535A14: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
L_80535A18:
    // 0x80535A18: beq         $v0, $a3, L_80535AF4
    if (ctx->r2 == ctx->r7) {
        // 0x80535A1C: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_80535AF4;
    }
    // 0x80535A1C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
L_80535A20:
    // 0x80535A20: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
L_80535A24:
    // 0x80535A24: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80535A28: bne         $a0, $a2, L_80535A38
    if (ctx->r4 != ctx->r6) {
        // 0x80535A2C: addu        $t5, $a1, $t0
        ctx->r13 = ADD32(ctx->r5, ctx->r8);
            goto L_80535A38;
    }
    // 0x80535A2C: addu        $t5, $a1, $t0
    ctx->r13 = ADD32(ctx->r5, ctx->r8);
    // 0x80535A30: jr          $ra
    // 0x80535A34: lwc1        $f0, 0x0($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X0);
    return;
    // 0x80535A34: lwc1        $f0, 0x0($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X0);
L_80535A38:
    // 0x80535A38: lw          $v1, -0x4($t1)
    ctx->r3 = MEM_W(ctx->r9, -0X4);
    // 0x80535A3C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80535A40: beq         $at, $zero, L_80535A84
    if (ctx->r1 == 0) {
        // 0x80535A44: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80535A84;
    }
    // 0x80535A44: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80535A48: beq         $at, $zero, L_80535A84
    if (ctx->r1 == 0) {
        // 0x80535A4C: subu        $t6, $a0, $v1
        ctx->r14 = SUB32(ctx->r4, ctx->r3);
            goto L_80535A84;
    }
    // 0x80535A4C: subu        $t6, $a0, $v1
    ctx->r14 = SUB32(ctx->r4, ctx->r3);
    // 0x80535A50: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80535A54: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x80535A58: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80535A5C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80535A60: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80535A64: subu        $t7, $a2, $v1
    ctx->r15 = SUB32(ctx->r6, ctx->r3);
    // 0x80535A68: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80535A6C: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80535A70: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80535A74: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80535A78: div.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80535A7C: jr          $ra
    // 0x80535A80: add.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f2.fl;
    return;
    // 0x80535A80: add.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f2.fl;
L_80535A84:
    // 0x80535A84: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80535A88: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80535A8C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80535A90: bne         $a0, $t2, L_80535AA4
    if (ctx->r4 != ctx->r10) {
        // 0x80535A94: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_80535AA4;
    }
    // 0x80535A94: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80535A98: addu        $t8, $a1, $t0
    ctx->r24 = ADD32(ctx->r5, ctx->r8);
    // 0x80535A9C: jr          $ra
    // 0x80535AA0: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
    return;
    // 0x80535AA0: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
L_80535AA4:
    // 0x80535AA4: beq         $at, $zero, L_80535AEC
    if (ctx->r1 == 0) {
        // 0x80535AA8: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_80535AEC;
    }
    // 0x80535AA8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80535AAC: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80535AB0: beq         $at, $zero, L_80535AEC
    if (ctx->r1 == 0) {
        // 0x80535AB4: subu        $t9, $a0, $v1
        ctx->r25 = SUB32(ctx->r4, ctx->r3);
            goto L_80535AEC;
    }
    // 0x80535AB4: subu        $t9, $a0, $v1
    ctx->r25 = SUB32(ctx->r4, ctx->r3);
    // 0x80535AB8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80535ABC: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x80535AC0: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80535AC4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80535AC8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80535ACC: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x80535AD0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80535AD4: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80535AD8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80535ADC: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80535AE0: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80535AE4: jr          $ra
    // 0x80535AE8: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    return;
    // 0x80535AE8: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
L_80535AEC:
    // 0x80535AEC: bne         $v0, $a3, L_80535A24
    if (ctx->r2 != ctx->r7) {
        // 0x80535AF0: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_80535A24;
    }
    // 0x80535AF0: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_80535AF4:
    // 0x80535AF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80535AF8: nop

    // 0x80535AFC: jr          $ra
    // 0x80535B00: nop

    return;
    // 0x80535B00: nop

;}
RECOMP_FUNC void func_80472C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80472C94: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80472C98: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80472C9C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80472CA0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80472CA4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80472CA8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80472CAC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80472CB0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80472CB4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80472CB8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80472CBC: lui         $t1, 0x8047
    ctx->r9 = S32(RELOC_HI16(158, 0X1ABC) << 16);
    // 0x80472CC0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80472CC4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80472CC8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80472CCC: lw          $t1, 0x2F7C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(158, 0X1ABC));
    // 0x80472CD0: jr          $ra
    // 0x80472CD4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80472CD4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8076D808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D808: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8076D80C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076D810: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8076D814: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8076D818: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076D81C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8076D820: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8076D824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076D828: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x8076D82C: jal         0x8076D1EC
    // 0x8076D830: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_8076D1EC(rdram, ctx);
        goto after_0;
    // 0x8076D830: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8076D834: beql        $v0, $zero, L_8076D8D0
    if (ctx->r2 == 0) {
        // 0x8076D838: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8076D8D0;
    }
    goto skip_0;
    // 0x8076D838: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8076D83C: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x8076D840: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8076D844: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8076D848: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X3970) << 16);
    // 0x8076D84C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8076D850: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X3970));
    // 0x8076D854: beql        $t9, $at, L_8076D894
    if (ctx->r25 == ctx->r1) {
        // 0x8076D858: lw          $t2, 0x0($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X0);
            goto L_8076D894;
    }
    goto skip_1;
    // 0x8076D858: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x8076D85C: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X34C8) << 16);
    // 0x8076D860: addiu       $v0, $v0, -0x348
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X34C8));
    // 0x8076D864: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8076D868: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8076D86C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076D870: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
    // 0x8076D874: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8076D878: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8076D87C: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
    // 0x8076D880: jal         0x8076DD8C
    // 0x8076D884: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_1;
    // 0x8076D884: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_1:
    // 0x8076D888: b           L_8076D8D0
    // 0x8076D88C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_8076D8D0;
    // 0x8076D88C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8076D890: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
L_8076D894:
    // 0x8076D894: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8076D898: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076D89C: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
    // 0x8076D8A0: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8076D8A4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8076D8A8: sw          $t3, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r11;
    // 0x8076D8AC: jal         0x8076DD8C
    // 0x8076D8B0: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_2;
    // 0x8076D8B0: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_2:
    // 0x8076D8B4: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8076D8B8: jal         0x80067BBC
    // 0x8076D8BC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8076D8BC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_3:
    // 0x8076D8C0: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x8076D8C4: jal         0x80067818
    // 0x8076D8C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8076D8C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8076D8CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8076D8D0:
    // 0x8076D8D0: jal         0x8076CD88
    // 0x8076D8D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8076CD88(rdram, ctx);
        goto after_5;
    // 0x8076D8D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8076D8D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8076D8DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8076D8E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8076D8E4: jr          $ra
    // 0x8076D8E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8076D8E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8002FD78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FD78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FD7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FD80: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FD84: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FD88: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8002FD8C: jal         0x8002F678
    // 0x8002FD90: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FD90: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FD94: beq         $v0, $zero, L_8002FDA8
    if (ctx->r2 == 0) {
        // 0x8002FD98: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FDA8;
    }
    // 0x8002FD98: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FD9C: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FDA0: addiu       $t6, $t6, -0x333C
    ctx->r14 = ADD32(ctx->r14, -0X333C);
    // 0x8002FDA4: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FDA8:
    // 0x8002FDA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FDAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FDB0: jr          $ra
    // 0x8002FDB4: nop

    return;
    // 0x8002FDB4: nop

;}
RECOMP_FUNC void func_804C5A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5A80: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C5A84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5A88: addiu       $t6, $sp, 0x0
    ctx->r14 = ADD32(ctx->r29, 0X0);
    // 0x804C5A8C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x804C5A90: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x804C5A94: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C5A98: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804C5A9C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804C5AA0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804C5AA4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x804C5AA8: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x804C5AAC: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x804C5AB0: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x804C5AB4: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x804C5AB8: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x804C5ABC: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804C5AC0: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x804C5AC4: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x804C5AC8: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x804C5ACC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x804C5AD0: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x804C5AD4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x804C5AD8: addu        $t8, $t3, $t5
    ctx->r24 = ADD32(ctx->r11, ctx->r13);
    // 0x804C5ADC: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x804C5AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5AE4: jr          $ra
    // 0x804C5AE8: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
    return;
    // 0x804C5AE8: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_8001D300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D300: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8001D304: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8001D308: lw          $t6, 0xF10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XF10);
    // 0x8001D30C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D314: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D318: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8001D31C: lw          $v0, 0xF14($t8)
    ctx->r2 = MEM_W(ctx->r24, 0XF14);
    // 0x8001D320: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D324: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001D328: jal         0x8001D0FC
    // 0x8001D32C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8001D0FC(rdram, ctx);
        goto after_0;
    // 0x8001D32C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001D330: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8001D334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D338: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x8001D33C: bne         $at, $zero, L_8001D35C
    if (ctx->r1 != 0) {
        // 0x8001D340: nop
    
            goto L_8001D35C;
    }
    // 0x8001D340: nop

    // 0x8001D344: jal         0x8001D698
    // 0x8001D348: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8001D698(rdram, ctx);
        goto after_1;
    // 0x8001D348: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8001D34C: jal         0x8001CE8C
    // 0x8001D350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001CE8C(rdram, ctx);
        goto after_2;
    // 0x8001D350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8001D354: b           L_8001D37C
    // 0x8001D358: nop

        goto L_8001D37C;
    // 0x8001D358: nop

L_8001D35C:
    // 0x8001D35C: bne         $v0, $zero, L_8001D374
    if (ctx->r2 != 0) {
        // 0x8001D360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001D374;
    }
    // 0x8001D360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D364: jal         0x8001D698
    // 0x8001D368: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8001D698(rdram, ctx);
        goto after_3;
    // 0x8001D368: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8001D36C: b           L_8001D37C
    // 0x8001D370: nop

        goto L_8001D37C;
    // 0x8001D370: nop

L_8001D374:
    // 0x8001D374: jal         0x8001CE8C
    // 0x8001D378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001CE8C(rdram, ctx);
        goto after_4;
    // 0x8001D378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8001D37C:
    // 0x8001D37C: jal         0x8001D148
    // 0x8001D380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001D148(rdram, ctx);
        goto after_5;
    // 0x8001D380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8001D384: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D388: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001D38C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D390: jr          $ra
    // 0x8001D394: nop

    return;
    // 0x8001D394: nop

;}
RECOMP_FUNC void func_80682BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80682BAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80682BB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80682BB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80682BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80682BBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80682BC0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80682BC4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80682BC8: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80682BCC: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80682BD0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80682BD4: jal         0x8068293C
    // 0x80682BD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8068293C(rdram, ctx);
        goto after_0;
    // 0x80682BD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80682BDC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80682BE0: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x80682BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80682BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80682BEC: jr          $ra
    // 0x80682BF0: nop

    return;
    // 0x80682BF0: nop

;}
RECOMP_FUNC void func_80030300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030300: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80030304: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80030308: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x8003030C: beq         $t7, $zero, L_80030334
    if (ctx->r15 == 0) {
        // 0x80030310: nop
    
            goto L_80030334;
    }
    // 0x80030310: nop

    // 0x80030314: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x80030318: lui         $t1, 0x8006
    ctx->r9 = S32(0X8006 << 16);
    // 0x8003031C: addiu       $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
    // 0x80030320: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x80030324: bne         $t9, $zero, L_80030334
    if (ctx->r25 != 0) {
        // 0x80030328: addiu       $t1, $t1, 0x5284
        ctx->r9 = ADD32(ctx->r9, 0X5284);
            goto L_80030334;
    }
    // 0x80030328: addiu       $t1, $t1, 0x5284
    ctx->r9 = ADD32(ctx->r9, 0X5284);
    // 0x8003032C: sw          $t0, 0x1A4($v0)
    MEM_W(0X1A4, ctx->r2) = ctx->r8;
    // 0x80030330: sw          $t1, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->r9;
L_80030334:
    // 0x80030334: jr          $ra
    // 0x80030338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80030338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8066B154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066B158: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066B15C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066B160: jal         0x8066B050
    // 0x8066B164: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8066B050(rdram, ctx);
        goto after_0;
    // 0x8066B164: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066B168: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8066B16C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8066B170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8066B174: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x8066B178: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8066B17C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B180: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8066B184: nop

    // 0x8066B188: bc1f        L_8066B1A8
    if (!c1cs) {
        // 0x8066B18C: nop
    
            goto L_8066B1A8;
    }
    // 0x8066B18C: nop

    // 0x8066B190: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8066B194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B198: jal         0x8066B970
    // 0x8066B19C: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_8066B970(rdram, ctx);
        goto after_1;
    // 0x8066B19C: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_1:
    // 0x8066B1A0: b           L_8066B1B4
    // 0x8066B1A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8066B1B4;
    // 0x8066B1A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066B1A8:
    // 0x8066B1A8: jal         0x8066AD18
    // 0x8066B1AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066AD18(rdram, ctx);
        goto after_2;
    // 0x8066B1AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8066B1B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066B1B4:
    // 0x8066B1B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066B1B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066B1BC: jr          $ra
    // 0x8066B1C0: nop

    return;
    // 0x8066B1C0: nop

;}
RECOMP_FUNC void func_8043E6D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E6D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043E6DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8043E6E0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8043E6E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8043E6E8: beq         $a1, $at, L_8043E714
    if (ctx->r5 == ctx->r1) {
        // 0x8043E6EC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8043E714;
    }
    // 0x8043E6EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E6F0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8043E6F4: beq         $a1, $at, L_8043E73C
    if (ctx->r5 == ctx->r1) {
        // 0x8043E6F8: addiu       $at, $zero, 0x69
        ctx->r1 = ADD32(0, 0X69);
            goto L_8043E73C;
    }
    // 0x8043E6F8: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8043E6FC: beq         $a1, $at, L_8043E728
    if (ctx->r5 == ctx->r1) {
        // 0x8043E700: addiu       $at, $zero, 0x6B
        ctx->r1 = ADD32(0, 0X6B);
            goto L_8043E728;
    }
    // 0x8043E700: addiu       $at, $zero, 0x6B
    ctx->r1 = ADD32(0, 0X6B);
    // 0x8043E704: beq         $a1, $at, L_8043E74C
    if (ctx->r5 == ctx->r1) {
        // 0x8043E708: nop
    
            goto L_8043E74C;
    }
    // 0x8043E708: nop

    // 0x8043E70C: b           L_8043E758
    // 0x8043E710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043E758;
    // 0x8043E710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043E714:
    // 0x8043E714: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    // 0x8043E718: jal         0x8043E490
    // 0x8043E71C: lw          $a2, 0x12C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X12C);
    func_8043E490(rdram, ctx);
        goto after_0;
    // 0x8043E71C: lw          $a2, 0x12C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X12C);
    after_0:
    // 0x8043E720: b           L_8043E758
    // 0x8043E724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043E758;
    // 0x8043E724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043E728:
    // 0x8043E728: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    // 0x8043E72C: jal         0x8043E514
    // 0x8043E730: lw          $a2, 0x12C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X12C);
    func_8043E514(rdram, ctx);
        goto after_1;
    // 0x8043E730: lw          $a2, 0x12C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X12C);
    after_1:
    // 0x8043E734: b           L_8043E758
    // 0x8043E738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043E758;
    // 0x8043E738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043E73C:
    // 0x8043E73C: jal         0x8043E5BC
    // 0x8043E740: nop

    func_8043E5BC(rdram, ctx);
        goto after_2;
    // 0x8043E740: nop

    after_2:
    // 0x8043E744: b           L_8043E758
    // 0x8043E748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043E758;
    // 0x8043E748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043E74C:
    // 0x8043E74C: jal         0x8043D154
    // 0x8043E750: nop

    func_8043D154(rdram, ctx);
        goto after_3;
    // 0x8043E750: nop

    after_3:
    // 0x8043E754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043E758:
    // 0x8043E758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043E75C: jr          $ra
    // 0x8043E760: nop

    return;
    // 0x8043E760: nop

;}
RECOMP_FUNC void func_80736A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736A94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80736A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736A9C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80736AA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80736AA4: jal         0x80736984
    // 0x80736AA8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80736984(rdram, ctx);
        goto after_0;
    // 0x80736AA8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80736AAC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80736AB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80736AB4: jal         0x80736A0C
    // 0x80736AB8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    func_80736A0C(rdram, ctx);
        goto after_1;
    // 0x80736AB8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    after_1:
    // 0x80736ABC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80736AC0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80736AC4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80736AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736ACC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80736AD0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80736AD4: beq         $v0, $zero, L_80736AE8
    if (ctx->r2 == 0) {
        // 0x80736AD8: nop
    
            goto L_80736AE8;
    }
    // 0x80736AD8: nop

    // 0x80736ADC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80736AE0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80736AE4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80736AE8:
    // 0x80736AE8: jr          $ra
    // 0x80736AEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80736AEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800492C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800492C0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800492C4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x800492C8: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x800492CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800492D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800492D4: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800492D8: lw          $t6, 0xA68($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XA68);
    // 0x800492DC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800492E0: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x800492E4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800492E8: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800492EC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x800492F0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800492F4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800492F8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800492FC: lw          $t9, 0x20($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X20);
    // 0x80049300: jalr        $t9
    // 0x80049304: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80049304: nop

    after_0:
    // 0x80049308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004930C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80049310: jr          $ra
    // 0x80049314: nop

    return;
    // 0x80049314: nop

;}
RECOMP_FUNC void func_80047058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047058: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8004705C: lw          $v1, -0x77D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X77D8);
    // 0x80047060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047068: beq         $v1, $zero, L_80047078
    if (ctx->r3 == 0) {
        // 0x8004706C: nop
    
            goto L_80047078;
    }
    // 0x8004706C: nop

    // 0x80047070: b           L_80047080
    // 0x80047074: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80047080;
    // 0x80047074: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80047078:
    // 0x80047078: jal         0x8004700C
    // 0x8004707C: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8004707C: nop

    after_0:
L_80047080:
    // 0x80047080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80047084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80047088: jr          $ra
    // 0x8004708C: nop

    return;
    // 0x8004708C: nop

;}
RECOMP_FUNC void func_806B0760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B0760: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806B0764: lw          $t6, -0x7BC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BC4);
    // 0x806B0768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B076C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B0770: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x806B0774: lwc1        $f6, 0x3C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x806B0778: lwc1        $f4, 0x3C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x806B077C: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x806B0780: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x806B0784: jal         0x806B02D4
    // 0x806B0788: swc1        $f10, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f10.u32l;
    func_806B02D4(rdram, ctx);
        goto after_0;
    // 0x806B0788: swc1        $f10, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f10.u32l;
    after_0:
    // 0x806B078C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B0790: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B0794: jr          $ra
    // 0x806B0798: nop

    return;
    // 0x806B0798: nop

;}
RECOMP_FUNC void func_806F5478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F547C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F5480: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x806F5484: slti        $at, $v0, 0x258
    ctx->r1 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // 0x806F5488: bne         $at, $zero, L_806F54A0
    if (ctx->r1 != 0) {
        // 0x806F548C: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_806F54A0;
    }
    // 0x806F548C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x806F5490: jal         0x80044658
    // 0x806F5494: nop

    func_80044658(rdram, ctx);
        goto after_0;
    // 0x806F5494: nop

    after_0:
    // 0x806F5498: b           L_806F54A8
    // 0x806F549C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806F54A8;
    // 0x806F549C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F54A0:
    // 0x806F54A0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x806F54A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F54A8:
    // 0x806F54A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F54AC: jr          $ra
    // 0x806F54B0: nop

    return;
    // 0x806F54B0: nop

;}
RECOMP_FUNC void func_8007FCF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FCF0: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8007FCF4: addiu       $t6, $t6, -0x5CF0
    ctx->r14 = ADD32(ctx->r14, -0X5CF0);
    // 0x8007FCF8: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8007FCFC: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_8007FD00:
    // 0x8007FD00: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8007FD04: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8007FD08: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8007FD0C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8007FD10: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8007FD14: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8007FD18: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8007FD1C: bne         $t6, $t0, L_8007FD00
    if (ctx->r14 != ctx->r8) {
        // 0x8007FD20: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8007FD00;
    }
    // 0x8007FD20: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8007FD24: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8007FD28: jr          $ra
    // 0x8007FD2C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    return;
    // 0x8007FD2C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
;}
RECOMP_FUNC void func_8078F888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F888: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078F88C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078F890: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078F894: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8078F898: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078F89C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8078F8A0: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x8078F8A4: beql        $t8, $zero, L_8078F930
    if (ctx->r24 == 0) {
        // 0x8078F8A8: lwc1        $f12, 0xC8($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_8078F930;
    }
    goto skip_0;
    // 0x8078F8A8: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x8078F8AC: jal         0x8004700C
    // 0x8078F8B0: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078F8B0: nop

    after_0:
    // 0x8078F8B4: beq         $v0, $zero, L_8078F91C
    if (ctx->r2 == 0) {
        // 0x8078F8B8: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8078F91C;
    }
    // 0x8078F8B8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8078F8BC: lwc1        $f0, 0x84($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8078F8C0: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8078F8C4: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x8078F8C8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XD80) << 16);
    // 0x8078F8CC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8078F8D0: lui         $t3, 0x8079
    ctx->r11 = S32(RELOC_HI16(814, 0XD30) << 16);
    // 0x8078F8D4: bc1fl       L_8078F8E4
    if (!c1cs) {
        // 0x8078F8D8: sll         $t0, $t9, 2
        ctx->r8 = S32(ctx->r25 << 2);
            goto L_8078F8E4;
    }
    goto skip_1;
    // 0x8078F8D8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    skip_1:
    // 0x8078F8DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8078F8E0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
L_8078F8E4:
    // 0x8078F8E4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8078F8E8: lwc1        $f6, -0xF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XD80));
    // 0x8078F8EC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8078F8F0: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
    // 0x8078F8F4: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8078F8F8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8078F8FC: nop

    // 0x8078F900: bc1fl       L_8078F910
    if (!c1cs) {
        // 0x8078F904: sll         $t2, $t1, 2
        ctx->r10 = S32(ctx->r9 << 2);
            goto L_8078F910;
    }
    goto skip_2;
    // 0x8078F904: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    skip_2:
    // 0x8078F908: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8078F90C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
L_8078F910:
    // 0x8078F910: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8078F914: lw          $t3, -0x140($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(814, 0XD30));
    // 0x8078F918: sw          $t3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r11;
L_8078F91C:
    // 0x8078F91C: jal         0x80048F84
    // 0x8078F920: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8078F920: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8078F924: jal         0x8078F3F4
    // 0x8078F928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078F3F4(rdram, ctx);
        goto after_2;
    // 0x8078F928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8078F92C: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
L_8078F930:
    // 0x8078F930: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8078F934: jal         0x80065ABC
    // 0x8078F938: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x8078F938: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x8078F93C: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8078F940: jal         0x8078F86C
    // 0x8078F944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078F86C(rdram, ctx);
        goto after_4;
    // 0x8078F944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8078F948: jal         0x8078F1D8
    // 0x8078F94C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078F1D8(rdram, ctx);
        goto after_5;
    // 0x8078F94C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8078F950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078F954: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078F958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078F95C: jr          $ra
    // 0x8078F960: nop

    return;
    // 0x8078F960: nop

;}
RECOMP_FUNC void func_804526FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804526FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452704: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80452708: jal         0x804525A8
    // 0x8045270C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_804525A8(rdram, ctx);
        goto after_0;
    // 0x8045270C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80452710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452718: jr          $ra
    // 0x8045271C: nop

    return;
    // 0x8045271C: nop

;}
RECOMP_FUNC void func_80777410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80777410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80777414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80777418: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8077741C: addiu       $at, $zero, 0x4651
    ctx->r1 = ADD32(0, 0X4651);
    // 0x80777420: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(775, 0X2E8) << 16);
    // 0x80777424: bne         $t6, $at, L_80777478
    if (ctx->r14 != ctx->r1) {
        // 0x80777428: addiu       $v0, $v0, 0x76F8
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(775, 0X2E8));
            goto L_80777478;
    }
    // 0x80777428: addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(775, 0X2E8));
    // 0x8077742C: lui         $t8, 0x8077
    ctx->r24 = S32(RELOC_HI16(775, 0X4B0) << 16);
    // 0x80777430: lw          $t8, 0x78C0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(775, 0X4B0));
    // 0x80777434: lui         $t7, 0x8077
    ctx->r15 = S32(RELOC_HI16(775, 0X78) << 16);
    // 0x80777438: addiu       $t7, $t7, 0x7488
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(775, 0X78));
    // 0x8077743C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80777440: bne         $t8, $zero, L_8077746C
    if (ctx->r24 != 0) {
        // 0x80777444: sw          $t7, -0x72C0($at)
        MEM_W(-0X72C0, ctx->r1) = ctx->r15;
            goto L_8077746C;
    }
    // 0x80777444: sw          $t7, -0x72C0($at)
    MEM_W(-0X72C0, ctx->r1) = ctx->r15;
    // 0x80777448: lui         $a0, 0x8077
    ctx->r4 = S32(RELOC_HI16(775, 0X5C0) << 16);
    // 0x8077744C: lui         $a1, 0x8077
    ctx->r5 = S32(RELOC_HI16(775, 0X5D0) << 16);
    // 0x80777450: addiu       $a1, $a1, 0x79E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(775, 0X5D0));
    // 0x80777454: addiu       $a0, $a0, 0x79D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(775, 0X5C0));
    // 0x80777458: jal         0x8004667C
    // 0x8077745C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8077745C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x80777460: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80777464: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(775, 0X4B0) << 16);
    // 0x80777468: sw          $t9, 0x78C0($at)
    MEM_W((int16_t)RELOC_LO16(775, 0X4B0), ctx->r1) = ctx->r25;
L_8077746C:
    // 0x8077746C: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(775, 0X2E8) << 16);
    // 0x80777470: b           L_80777478
    // 0x80777474: addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(775, 0X2E8));
        goto L_80777478;
    // 0x80777474: addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(775, 0X2E8));
L_80777478:
    // 0x80777478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8077747C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80777480: jr          $ra
    // 0x80777484: nop

    return;
    // 0x80777484: nop

;}
RECOMP_FUNC void func_8006C380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006C38C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8006C390: jal         0x80065728
    // 0x8006C394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8006C394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006C398: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8006C39C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006C3A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006C3A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006C3A8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8006C3AC: lwc1        $f6, 0x1078($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1078);
    // 0x8006C3B0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x8006C3B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C3B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C3BC: jr          $ra
    // 0x8006C3C0: nop

    return;
    // 0x8006C3C0: nop

;}
RECOMP_FUNC void func_8002AFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AFA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AFA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AFA8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8002AFAC: jal         0x8002ADE4
    // 0x8002AFB0: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    func_8002ADE4(rdram, ctx);
        goto after_0;
    // 0x8002AFB0: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    after_0:
    // 0x8002AFB4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8002AFB8: lbu         $t6, 0x7EA5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7EA5);
    // 0x8002AFBC: beql        $t6, $zero, L_8002AFD0
    if (ctx->r14 == 0) {
        // 0x8002AFC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002AFD0;
    }
    goto skip_0;
    // 0x8002AFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002AFC4: jal         0x8002AF8C
    // 0x8002AFC8: nop

    func_8002AF8C(rdram, ctx);
        goto after_1;
    // 0x8002AFC8: nop

    after_1:
    // 0x8002AFCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002AFD0:
    // 0x8002AFD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AFD4: jr          $ra
    // 0x8002AFD8: nop

    return;
    // 0x8002AFD8: nop

;}
RECOMP_FUNC void func_8000376C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000376C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80003770: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80003774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003778: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000377C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80003780: addiu       $a1, $a1, 0x77B0
    ctx->r5 = ADD32(ctx->r5, 0X77B0);
    // 0x80003784: addiu       $a0, $a0, 0x6BD8
    ctx->r4 = ADD32(ctx->r4, 0X6BD8);
    // 0x80003788: jal         0x800036F0
    // 0x8000378C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800036F0(rdram, ctx);
        goto after_0;
    // 0x8000378C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80003790: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80003794: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80003798: lw          $t7, -0x3C4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3C4C);
    // 0x8000379C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x800037A0: addiu       $t6, $t6, 0x77B0
    ctx->r14 = ADD32(ctx->r14, 0X77B0);
    // 0x800037A4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800037A8: addiu       $a0, $a0, 0x6BB8
    ctx->r4 = ADD32(ctx->r4, 0X6BB8);
    // 0x800037AC: addu        $a1, $a3, $t6
    ctx->r5 = ADD32(ctx->r7, ctx->r14);
    // 0x800037B0: jal         0x800036F0
    // 0x800037B4: subu        $a2, $t7, $a3
    ctx->r6 = SUB32(ctx->r15, ctx->r7);
    func_800036F0(rdram, ctx);
        goto after_1;
    // 0x800037B4: subu        $a2, $t7, $a3
    ctx->r6 = SUB32(ctx->r15, ctx->r7);
    after_1:
    // 0x800037B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800037BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800037C0: sw          $zero, 0x6BC8($at)
    MEM_W(0X6BC8, ctx->r1) = 0;
    // 0x800037C4: jr          $ra
    // 0x800037C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800037C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80714E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80714E64: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80714E68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80714E6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80714E70: lh          $t6, 0x5E0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X5E0);
    // 0x80714E74: lw          $a2, 0x5F8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X5F8);
    // 0x80714E78: lw          $v1, 0x5A0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5A0);
    // 0x80714E7C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80714E80: sh          $t7, 0x5E0($v0)
    MEM_H(0X5E0, ctx->r2) = ctx->r15;
    // 0x80714E84: lh          $a3, 0x5E0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X5E0);
    // 0x80714E88: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80714E8C: slti        $at, $a3, 0xA0
    ctx->r1 = SIGNED(ctx->r7) < 0XA0 ? 1 : 0;
    // 0x80714E90: bne         $at, $zero, L_80714EB8
    if (ctx->r1 != 0) {
        // 0x80714E94: nop
    
            goto L_80714EB8;
    }
    // 0x80714E94: nop

    // 0x80714E98: sh          $t8, 0x5FE($v0)
    MEM_H(0X5FE, ctx->r2) = ctx->r24;
    // 0x80714E9C: addiu       $t9, $a3, -0xA0
    ctx->r25 = ADD32(ctx->r7, -0XA0);
L_80714EA0:
    // 0x80714EA0: sh          $t9, 0x5E0($v0)
    MEM_H(0X5E0, ctx->r2) = ctx->r25;
    // 0x80714EA4: lh          $a3, 0x5E0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X5E0);
    // 0x80714EA8: slti        $at, $a3, 0xA0
    ctx->r1 = SIGNED(ctx->r7) < 0XA0 ? 1 : 0;
    // 0x80714EAC: beql        $at, $zero, L_80714EA0
    if (ctx->r1 == 0) {
        // 0x80714EB0: addiu       $t9, $a3, -0xA0
        ctx->r25 = ADD32(ctx->r7, -0XA0);
            goto L_80714EA0;
    }
    goto skip_0;
    // 0x80714EB0: addiu       $t9, $a3, -0xA0
    ctx->r25 = ADD32(ctx->r7, -0XA0);
    skip_0:
    // 0x80714EB4: lw          $a2, 0x5F8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X5F8);
L_80714EB8:
    // 0x80714EB8: beq         $a2, $zero, L_80714F04
    if (ctx->r6 == 0) {
        // 0x80714EBC: addu        $t9, $v0, $a3
        ctx->r25 = ADD32(ctx->r2, ctx->r7);
            goto L_80714F04;
    }
    // 0x80714EBC: addu        $t9, $v0, $a3
    ctx->r25 = ADD32(ctx->r2, ctx->r7);
    // 0x80714EC0: lw          $t1, 0x5EC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X5EC);
    // 0x80714EC4: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x80714EC8: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80714ECC: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x80714ED0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80714ED4: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80714ED8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80714EDC: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80714EE0: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x80714EE4: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
    // 0x80714EE8: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80714EEC: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x80714EF0: lh          $t7, 0x5E0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X5E0);
    // 0x80714EF4: lbu         $t6, 0x1D($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1D);
    // 0x80714EF8: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80714EFC: b           L_80714F08
    // 0x80714F00: sb          $t6, 0x500($t8)
    MEM_B(0X500, ctx->r24) = ctx->r14;
        goto L_80714F08;
    // 0x80714F00: sb          $t6, 0x500($t8)
    MEM_B(0X500, ctx->r24) = ctx->r14;
L_80714F04:
    // 0x80714F04: sb          $zero, 0x500($t9)
    MEM_B(0X500, ctx->r25) = 0;
L_80714F08:
    // 0x80714F08: lh          $t1, 0x5E0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X5E0);
    // 0x80714F0C: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80714F10: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80714F14: addu        $t0, $v0, $t2
    ctx->r8 = ADD32(ctx->r2, ctx->r10);
    // 0x80714F18: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80714F1C: lh          $t3, 0x5E0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X5E0);
    // 0x80714F20: lwc1        $f6, 0x88($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80714F24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80714F28: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80714F2C: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80714F30: jr          $ra
    // 0x80714F34: swc1        $f6, 0x280($t5)
    MEM_W(0X280, ctx->r13) = ctx->f6.u32l;
    return;
    // 0x80714F34: swc1        $f6, 0x280($t5)
    MEM_W(0X280, ctx->r13) = ctx->f6.u32l;
;}
RECOMP_FUNC void guMtxXFML(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B280: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8008B284: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8008B288: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8008B28C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008B290: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8008B294: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8008B298: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8008B29C: jal         0x80086F58
    // 0x8008B2A0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    guMtxL2F(rdram, ctx);
        goto after_0;
    // 0x8008B2A0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8008B2A4: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8008B2A8: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8008B2AC: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8008B2B0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8008B2B4: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8008B2B8: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x8008B2BC: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x8008B2C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008B2C4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8008B2C8: jal         0x8008B340
    // 0x8008B2CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    guMtxXFMF(rdram, ctx);
        goto after_1;
    // 0x8008B2CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x8008B2D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008B2D4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8008B2D8: jr          $ra
    // 0x8008B2DC: nop

    return;
    // 0x8008B2DC: nop

;}
RECOMP_FUNC void func_80438E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438E24: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80438E28: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80438E2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80438E30: lwc1        $f0, 0xA08($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XA08);
    // 0x80438E34: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80438E38: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80438E3C: nop

    // 0x80438E40: bc1fl       L_80438E5C
    if (!c1cs) {
        // 0x80438E44: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80438E5C;
    }
    goto skip_0;
    // 0x80438E44: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    skip_0:
    // 0x80438E48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80438E4C: nop

    // 0x80438E50: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80438E54: swc1        $f8, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->f8.u32l;
    // 0x80438E58: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80438E5C:
    // 0x80438E5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80438E60: lwc1        $f0, 0xA10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XA10);
    // 0x80438E64: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80438E68: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80438E6C: nop

    // 0x80438E70: bc1fl       L_80438E8C
    if (!c1cs) {
        // 0x80438E74: lui         $at, 0x3E00
        ctx->r1 = S32(0X3E00 << 16);
            goto L_80438E8C;
    }
    goto skip_1;
    // 0x80438E74: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    skip_1:
    // 0x80438E78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80438E7C: nop

    // 0x80438E80: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80438E84: swc1        $f18, 0xA10($v0)
    MEM_W(0XA10, ctx->r2) = ctx->f18.u32l;
    // 0x80438E88: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
L_80438E8C:
    // 0x80438E8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80438E90: lwc1        $f0, 0xA18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XA18);
    // 0x80438E94: lui         $at, 0x3D80
    ctx->r1 = S32(0X3D80 << 16);
    // 0x80438E98: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80438E9C: nop

    // 0x80438EA0: bc1f        L_80438EB8
    if (!c1cs) {
        // 0x80438EA4: nop
    
            goto L_80438EB8;
    }
    // 0x80438EA4: nop

    // 0x80438EA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80438EAC: nop

    // 0x80438EB0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80438EB4: swc1        $f8, 0xA18($v0)
    MEM_W(0XA18, ctx->r2) = ctx->f8.u32l;
L_80438EB8:
    // 0x80438EB8: jr          $ra
    // 0x80438EBC: nop

    return;
    // 0x80438EBC: nop

;}
RECOMP_FUNC void func_807813F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807813F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807813F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807813F8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x807813FC: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x80781400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80781404: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80781408: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x8078140C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80781410: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80781414: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80781418: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8078141C: lui         $t2, 0x8078
    ctx->r10 = S32(RELOC_HI16(784, 0X6568) << 16);
    // 0x80781420: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x80781424: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80781428: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8078142C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80781430: lw          $t2, 0x6758($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(784, 0X6568));
    // 0x80781434: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80781438: jal         0x80781364
    // 0x8078143C: sw          $t2, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r10;
    func_80781364(rdram, ctx);
        goto after_0;
    // 0x8078143C: sw          $t2, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r10;
    after_0:
    // 0x80781440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80781444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80781448: jr          $ra
    // 0x8078144C: nop

    return;
    // 0x8078144C: nop

;}
RECOMP_FUNC void func_806D357C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D357C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D3580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D3584: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806D3588: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806D358C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806D3590: jal         0x80067BBC
    // 0x806D3594: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806D3594: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806D3598: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806D359C: jal         0x80067818
    // 0x806D35A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806D35A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806D35A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D35A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D35AC: jr          $ra
    // 0x806D35B0: nop

    return;
    // 0x806D35B0: nop

;}
RECOMP_FUNC void func_804BB0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB0C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804BB0CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BB0D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BB0D4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BB0D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804BB0DC: lui         $a0, 0x4014
    ctx->r4 = S32(0X4014 << 16);
    // 0x804BB0E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804BB0E4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x804BB0E8: lui         $a1, 0x4320
    ctx->r5 = S32(0X4320 << 16);
    // 0x804BB0EC: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    // 0x804BB0F0: bgez        $t6, L_804BB1A8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x804BB0F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804BB1A8;
    }
    // 0x804BB0F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804BB0F8: lui         $a3, 0x7F7F
    ctx->r7 = S32(0X7F7F << 16);
    // 0x804BB0FC: jal         0x8004613C
    // 0x804BB100: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x804BB100: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    after_0:
    // 0x804BB104: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x804BB108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BB10C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804BB110: jal         0x80047F9C
    // 0x804BB114: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x804BB114: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    after_1:
    // 0x804BB118: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x804BB11C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804BB120: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804BB124: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x804BB128: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x804BB12C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BB130: sb          $v1, 0x17C($t9)
    MEM_B(0X17C, ctx->r25) = ctx->r3;
    // 0x804BB134: sb          $v1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r3;
    // 0x804BB138: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x804BB13C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x804BB140: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x804BB144: beq         $v0, $at, L_804BB15C
    if (ctx->r2 == ctx->r1) {
        // 0x804BB148: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_804BB15C;
    }
    // 0x804BB148: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x804BB14C: beql        $v0, $at, L_804BB170
    if (ctx->r2 == ctx->r1) {
        // 0x804BB150: lw          $t0, 0x138($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X138);
            goto L_804BB170;
    }
    goto skip_0;
    // 0x804BB150: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    skip_0:
    // 0x804BB154: b           L_804BB1A8
    // 0x804BB158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804BB1A8;
    // 0x804BB158: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804BB15C:
    // 0x804BB15C: jal         0x804BB4C4
    // 0x804BB160: sw          $v1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r3;
    func_804BB4C4(rdram, ctx);
        goto after_2;
    // 0x804BB160: sw          $v1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r3;
    after_2:
    // 0x804BB164: b           L_804BB1A8
    // 0x804BB168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804BB1A8;
    // 0x804BB168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804BB16C: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
L_804BB170:
    // 0x804BB170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BB174: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x804BB178: beq         $t0, $zero, L_804BB198
    if (ctx->r8 == 0) {
        // 0x804BB17C: addiu       $a2, $zero, 0x7
        ctx->r6 = ADD32(0, 0X7);
            goto L_804BB198;
    }
    // 0x804BB17C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x804BB180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BB184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB188: jal         0x804BB4C4
    // 0x804BB18C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_804BB4C4(rdram, ctx);
        goto after_3;
    // 0x804BB18C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x804BB190: b           L_804BB1A8
    // 0x804BB194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804BB1A8;
    // 0x804BB194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804BB198:
    // 0x804BB198: jal         0x804BB4C4
    // 0x804BB19C: sw          $v1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r3;
    func_804BB4C4(rdram, ctx);
        goto after_4;
    // 0x804BB19C: sw          $v1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r3;
    after_4:
    // 0x804BB1A0: b           L_804BB1A8
    // 0x804BB1A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804BB1A8;
    // 0x804BB1A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804BB1A8:
    // 0x804BB1A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BB1AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BB1B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804BB1B4: jr          $ra
    // 0x804BB1B8: nop

    return;
    // 0x804BB1B8: nop

;}
RECOMP_FUNC void func_80742354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742354: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80742358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8074235C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80742360: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80742364: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80742368: jal         0x80066DE4
    // 0x8074236C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8074236C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80742370: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80742374: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80742378: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8074237C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80742380: jal         0x80066E88
    // 0x80742384: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80742384: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80742388: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8074238C: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80742390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80742394: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80742398: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8074239C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807423A0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x807423A4: jr          $ra
    // 0x807423A8: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    return;
    // 0x807423A8: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
;}
RECOMP_FUNC void func_8002D1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D1CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002D1D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D1D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D1D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002D1DC: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x8002D1E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002D1E4: jal         0x8002D198
    // 0x8002D1E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002D198(rdram, ctx);
        goto after_0;
    // 0x8002D1E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x8002D1EC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8002D1F0: jal         0x8002BBF4
    // 0x8002D1F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8002BBF4(rdram, ctx);
        goto after_1;
    // 0x8002D1F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002D1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D1FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D200: jr          $ra
    // 0x8002D204: nop

    return;
    // 0x8002D204: nop

;}
RECOMP_FUNC void func_80447520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447520: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80447524: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80447528: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8044752C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80447530: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80447534: addiu       $t0, $zero, 0x1B6C
    ctx->r8 = ADD32(0, 0X1B6C);
    // 0x80447538: subu        $t1, $t0, $a3
    ctx->r9 = SUB32(ctx->r8, ctx->r7);
    // 0x8044753C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80447540: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x80447544: slti        $at, $t8, 0x3C0
    ctx->r1 = SIGNED(ctx->r24) < 0X3C0 ? 1 : 0;
    // 0x80447548: beq         $at, $zero, L_80447554
    if (ctx->r1 == 0) {
        // 0x8044754C: sw          $t8, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r24;
            goto L_80447554;
    }
    // 0x8044754C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80447550: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_80447554:
    // 0x80447554: jr          $ra
    // 0x80447558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80447558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8045B3F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B3F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045B3FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045B400: jal         0x80052CB0
    // 0x8045B404: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    func_80052CB0(rdram, ctx);
        goto after_0;
    // 0x8045B404: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    after_0:
    // 0x8045B408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045B40C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045B410: jr          $ra
    // 0x8045B414: nop

    return;
    // 0x8045B414: nop

;}
RECOMP_FUNC void func_805214F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805214F4: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(306, 0X278) << 16);
    // 0x805214F8: lw          $v0, 0x1638($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(306, 0X278));
    // 0x805214FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80521504: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80521508: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8052150C: beql        $v1, $zero, L_80521540
    if (ctx->r3 == 0) {
        // 0x80521510: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80521540;
    }
    goto skip_0;
    // 0x80521510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80521514: jalr        $v1
    // 0x80521518: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80521518: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8052151C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80521520: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80521524: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x80521528: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8052152C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80521530: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80521534: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80521538: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x8052153C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80521540:
    // 0x80521540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80521544: jr          $ra
    // 0x80521548: nop

    return;
    // 0x80521548: nop

;}
RECOMP_FUNC void func_805815D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805815D0: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x805815D4: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x805815D8: mfhi        $a1
    ctx->r5 = hi;
    // 0x805815DC: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x805815E0: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x805815E4: div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // 0x805815E8: bne         $v0, $zero, L_805815F4
    if (ctx->r2 != 0) {
        // 0x805815EC: nop
    
            goto L_805815F4;
    }
    // 0x805815EC: nop

    // 0x805815F0: break       7
    do_break(2153256432);
L_805815F4:
    // 0x805815F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805815F8: bne         $v0, $at, L_8058160C
    if (ctx->r2 != ctx->r1) {
        // 0x805815FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8058160C;
    }
    // 0x805815FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80581600: bne         $a1, $at, L_8058160C
    if (ctx->r5 != ctx->r1) {
        // 0x80581604: nop
    
            goto L_8058160C;
    }
    // 0x80581604: nop

    // 0x80581608: break       6
    do_break(2153256456);
L_8058160C:
    // 0x8058160C: mfhi        $a1
    ctx->r5 = hi;
    // 0x80581610: mflo        $t6
    ctx->r14 = lo;
    // 0x80581614: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x80581618: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8058161C: div         $zero, $a1, $v1
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r3)));
    // 0x80581620: bne         $v1, $zero, L_8058162C
    if (ctx->r3 != 0) {
        // 0x80581624: nop
    
            goto L_8058162C;
    }
    // 0x80581624: nop

    // 0x80581628: break       7
    do_break(2153256488);
L_8058162C:
    // 0x8058162C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80581630: bne         $v1, $at, L_80581644
    if (ctx->r3 != ctx->r1) {
        // 0x80581634: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80581644;
    }
    // 0x80581634: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80581638: bne         $a1, $at, L_80581644
    if (ctx->r5 != ctx->r1) {
        // 0x8058163C: nop
    
            goto L_80581644;
    }
    // 0x8058163C: nop

    // 0x80581640: break       6
    do_break(2153256512);
L_80581644:
    // 0x80581644: mflo        $t8
    ctx->r24 = lo;
    // 0x80581648: mfhi        $a1
    ctx->r5 = hi;
    // 0x8058164C: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x80581650: addiu       $t0, $a1, 0x10
    ctx->r8 = ADD32(ctx->r5, 0X10);
    // 0x80581654: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80581658: jr          $ra
    // 0x8058165C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    return;
    // 0x8058165C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void Math_FTanF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081C30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80081C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081C38: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80081C3C: jal         0x80082730
    // 0x80081C40: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    fsin(rdram, ctx);
        goto after_0;
    // 0x80081C40: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80081C44: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80081C48: jal         0x8008D250
    // 0x80081C4C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    fcos(rdram, ctx);
        goto after_1;
    // 0x80081C4C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80081C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081C54: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80081C58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80081C5C: jr          $ra
    // 0x80081C60: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    return;
    // 0x80081C60: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
;}
RECOMP_FUNC void func_806F997C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F997C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9984: jal         0x806F9840
    // 0x806F9988: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F9840(rdram, ctx);
        goto after_0;
    // 0x806F9988: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F998C: beq         $v0, $zero, L_806F9A10
    if (ctx->r2 == 0) {
        // 0x806F9990: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806F9A10;
    }
    // 0x806F9990: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F9994: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806F9998: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806F999C: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(697, 0X5B0) << 16);
    // 0x806F99A0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806F99A4: addiu       $t7, $t7, -0x64D0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(697, 0X5B0));
    // 0x806F99A8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806F99AC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806F99B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F99B4: lui         $t0, 0x8070
    ctx->r8 = S32(RELOC_HI16(697, 0XEC) << 16);
    // 0x806F99B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806F99BC: addiu       $t0, $t0, -0x6994
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(697, 0XEC));
    // 0x806F99C0: sb          $t9, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r25;
    // 0x806F99C4: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806F99C8: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x806F99CC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F99D0: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(697, 0X5E4) << 16);
    // 0x806F99D4: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x806F99D8: lwc1        $f6, -0x649C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(697, 0X5E4));
    // 0x806F99DC: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x806F99E0: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x806F99E4: sw          $t1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r9;
    // 0x806F99E8: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x806F99EC: jal         0x806F9894
    // 0x806F99F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F9894(rdram, ctx);
        goto after_1;
    // 0x806F99F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x806F99F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F99F8: lui         $t2, 0x8070
    ctx->r10 = S32(RELOC_HI16(697, 0X370) << 16);
    // 0x806F99FC: addiu       $t2, $t2, -0x6710
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(697, 0X370));
    // 0x806F9A00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806F9A04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F9A08: sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    // 0x806F9A0C: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
L_806F9A10:
    // 0x806F9A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F9A14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F9A18: jr          $ra
    // 0x806F9A1C: nop

    return;
    // 0x806F9A1C: nop

;}
RECOMP_FUNC void func_8003BF08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BF08: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x8003BF0C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003BF10: addiu       $t7, $t7, 0x3450
    ctx->r15 = ADD32(ctx->r15, 0X3450);
    // 0x8003BF14: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8003BF18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003BF1C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8003BF20: jr          $ra
    // 0x8003BF24: sb          $t8, 0x1F8($a1)
    MEM_B(0X1F8, ctx->r5) = ctx->r24;
    return;
    // 0x8003BF24: sb          $t8, 0x1F8($a1)
    MEM_B(0X1F8, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void func_806EDFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EDFF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EDFF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EDFFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EE000: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EE004: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EE008: jal         0x800577D8
    // 0x806EE00C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EE00C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x806EE010: jal         0x806ED6C4
    // 0x806EE014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED6C4(rdram, ctx);
        goto after_1;
    // 0x806EE014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EE018: bne         $v0, $zero, L_806EE040
    if (ctx->r2 != 0) {
        // 0x806EE01C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EE040;
    }
    // 0x806EE01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EE020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EE024: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806EE028: jal         0x806EE584
    // 0x806EE02C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_2;
    // 0x806EE02C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
    // 0x806EE030: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x806EE034: jal         0x806EBFB8
    // 0x806EE038: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    func_806EBFB8(rdram, ctx);
        goto after_3;
    // 0x806EE038: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    after_3:
    // 0x806EE03C: sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
L_806EE040:
    // 0x806EE040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EE044: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EE048: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EE04C: jr          $ra
    // 0x806EE050: nop

    return;
    // 0x806EE050: nop

;}
RECOMP_FUNC void func_80581DDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581DDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80581DE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80581DE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80581DE8: jal         0x80581B84
    // 0x80581DEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80581B84(rdram, ctx);
        goto after_0;
    // 0x80581DEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80581DF0: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x80581DF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80581DF8: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80581DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80581E00: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80581E04: nop

    // 0x80581E08: bc1fl       L_80581EB0
    if (!c1cs) {
        // 0x80581E0C: lwc1        $f6, 0xC8($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80581EB0;
    }
    goto skip_0;
    // 0x80581E0C: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x80581E10: jal         0x8057EF14
    // 0x80581E14: addiu       $a1, $zero, 0x40F1
    ctx->r5 = ADD32(0, 0X40F1);
    func_8057EF14(rdram, ctx);
        goto after_1;
    // 0x80581E14: addiu       $a1, $zero, 0x40F1
    ctx->r5 = ADD32(0, 0X40F1);
    after_1:
    // 0x80581E18: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80581E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80581E20: jal         0x8057EF14
    // 0x80581E24: addiu       $a1, $zero, 0x40F2
    ctx->r5 = ADD32(0, 0X40F2);
    func_8057EF14(rdram, ctx);
        goto after_2;
    // 0x80581E24: addiu       $a1, $zero, 0x40F2
    ctx->r5 = ADD32(0, 0X40F2);
    after_2:
    // 0x80581E28: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80581E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80581E30: jal         0x8057EF14
    // 0x80581E34: addiu       $a1, $zero, 0x4021
    ctx->r5 = ADD32(0, 0X4021);
    func_8057EF14(rdram, ctx);
        goto after_3;
    // 0x80581E34: addiu       $a1, $zero, 0x4021
    ctx->r5 = ADD32(0, 0X4021);
    after_3:
    // 0x80581E38: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80581E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80581E40: jal         0x8057EF14
    // 0x80581E44: addiu       $a1, $zero, 0x4022
    ctx->r5 = ADD32(0, 0X4022);
    func_8057EF14(rdram, ctx);
        goto after_4;
    // 0x80581E44: addiu       $a1, $zero, 0x4022
    ctx->r5 = ADD32(0, 0X4022);
    after_4:
    // 0x80581E48: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80581E4C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80581E50: beql        $a0, $zero, L_80581E64
    if (ctx->r4 == 0) {
        // 0x80581E54: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80581E64;
    }
    goto skip_1;
    // 0x80581E54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80581E58: jal         0x8005C9A8
    // 0x80581E5C: nop

    func_8005C9A8(rdram, ctx);
        goto after_5;
    // 0x80581E5C: nop

    after_5:
    // 0x80581E60: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80581E64:
    // 0x80581E64: beql        $a0, $zero, L_80581E78
    if (ctx->r4 == 0) {
        // 0x80581E68: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80581E78;
    }
    goto skip_2;
    // 0x80581E68: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80581E6C: jal         0x8005C9A8
    // 0x80581E70: nop

    func_8005C9A8(rdram, ctx);
        goto after_6;
    // 0x80581E70: nop

    after_6:
    // 0x80581E74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80581E78:
    // 0x80581E78: beql        $a0, $zero, L_80581E8C
    if (ctx->r4 == 0) {
        // 0x80581E7C: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_80581E8C;
    }
    goto skip_3;
    // 0x80581E7C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    skip_3:
    // 0x80581E80: jal         0x8005C9A8
    // 0x80581E84: nop

    func_8005C9A8(rdram, ctx);
        goto after_7;
    // 0x80581E84: nop

    after_7:
    // 0x80581E88: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
L_80581E8C:
    // 0x80581E8C: beq         $t6, $zero, L_80581E9C
    if (ctx->r14 == 0) {
        // 0x80581E90: nop
    
            goto L_80581E9C;
    }
    // 0x80581E90: nop

    // 0x80581E94: jal         0x8005C9A8
    // 0x80581E98: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8005C9A8(rdram, ctx);
        goto after_8;
    // 0x80581E98: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_8:
L_80581E9C:
    // 0x80581E9C: jal         0x800447C8
    // 0x80581EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_9;
    // 0x80581EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80581EA4: b           L_80581EEC
    // 0x80581EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80581EEC;
    // 0x80581EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80581EAC: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
L_80581EB0:
    // 0x80581EB0: lwc1        $f8, 0xE0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x80581EB4: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80581EB8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80581EBC: nop

    // 0x80581EC0: bc1fl       L_80581EE0
    if (!c1cs) {
        // 0x80581EC4: lwc1        $f4, 0xC8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80581EE0;
    }
    goto skip_4;
    // 0x80581EC4: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    skip_4:
    // 0x80581EC8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80581ECC: lwc1        $f16, 0x34($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80581ED0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80581ED4: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80581ED8: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80581EDC: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
L_80581EE0:
    // 0x80581EE0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80581EE4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80581EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80581EEC:
    // 0x80581EEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80581EF0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80581EF4: jr          $ra
    // 0x80581EF8: nop

    return;
    // 0x80581EF8: nop

;}
RECOMP_FUNC void StackCheck_Cleanup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800819C8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800819CC: bnel        $v0, $zero, L_800819E8
    if (ctx->r2 != 0) {
        // 0x800819D0: lw          $t7, 0x0($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X0);
            goto L_800819E8;
    }
    goto skip_0;
    // 0x800819D0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800819D4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800819D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800819DC: b           L_800819EC
    // 0x800819E0: sw          $t6, -0x5C60($at)
    MEM_W(-0X5C60, ctx->r1) = ctx->r14;
        goto L_800819EC;
    // 0x800819E0: sw          $t6, -0x5C60($at)
    MEM_W(-0X5C60, ctx->r1) = ctx->r14;
    // 0x800819E4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
L_800819E8:
    // 0x800819E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800819EC:
    // 0x800819EC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800819F0: bne         $t8, $zero, L_80081A04
    if (ctx->r24 != 0) {
        // 0x800819F4: nop
    
            goto L_80081A04;
    }
    // 0x800819F4: nop

    // 0x800819F8: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800819FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80081A00: sw          $t9, -0x5C5C($at)
    MEM_W(-0X5C5C, ctx->r1) = ctx->r25;
L_80081A04:
    // 0x80081A04: jr          $ra
    // 0x80081A08: nop

    return;
    // 0x80081A08: nop

;}
RECOMP_FUNC void func_8069B924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069B924: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069B928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069B92C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8069B930: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069B934: jal         0x80045A34
    // 0x8069B938: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8069B938: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    after_0:
    // 0x8069B93C: bne         $v0, $zero, L_8069B954
    if (ctx->r2 != 0) {
        // 0x8069B940: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8069B954;
    }
    // 0x8069B940: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8069B944: jal         0x800445A4
    // 0x8069B948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8069B948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8069B94C: b           L_8069BC24
    // 0x8069B950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069BC24;
    // 0x8069B950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069B954:
    // 0x8069B954: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x8069B958: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(565, 0X1904) << 16);
    // 0x8069B95C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8069B960: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8069B964: addiu       $t6, $t6, -0x3A2C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(565, 0X1904));
    // 0x8069B968: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8069B96C: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x8069B970: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8069B974: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x8069B978: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8069B97C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8069B980: lui         $a0, 0x806A
    ctx->r4 = S32(RELOC_HI16(565, 0X1078) << 16);
    // 0x8069B984: lui         $a2, 0x806A
    ctx->r6 = S32(RELOC_HI16(565, 0X1088) << 16);
    // 0x8069B988: lui         $t0, 0x806A
    ctx->r8 = S32(RELOC_HI16(565, 0X1098) << 16);
    // 0x8069B98C: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(565, 0X10A8) << 16);
    // 0x8069B990: lui         $t2, 0x806A
    ctx->r10 = S32(RELOC_HI16(565, 0X1128) << 16);
    // 0x8069B994: addiu       $t2, $t2, -0x4208
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(565, 0X1128));
    // 0x8069B998: addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(565, 0X10A8));
    // 0x8069B99C: addiu       $t0, $t0, -0x4298
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(565, 0X1098));
    // 0x8069B9A0: addiu       $a2, $a2, -0x42A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(565, 0X1088));
    // 0x8069B9A4: addiu       $a0, $a0, -0x42B8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(565, 0X1078));
    // 0x8069B9A8: sw          $zero, 0x14($t3)
    MEM_W(0X14, ctx->r11) = 0;
    // 0x8069B9AC: sw          $zero, 0x10($t3)
    MEM_W(0X10, ctx->r11) = 0;
    // 0x8069B9B0: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    // 0x8069B9B4: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    // 0x8069B9B8: addiu       $v1, $t3, 0x18
    ctx->r3 = ADD32(ctx->r11, 0X18);
    // 0x8069B9BC: addiu       $a1, $t3, 0x28
    ctx->r5 = ADD32(ctx->r11, 0X28);
    // 0x8069B9C0: addiu       $a3, $t3, 0x38
    ctx->r7 = ADD32(ctx->r11, 0X38);
    // 0x8069B9C4: addiu       $t1, $t3, 0x48
    ctx->r9 = ADD32(ctx->r11, 0X48);
    // 0x8069B9C8: swc1        $f0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f0.u32l;
    // 0x8069B9CC: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
L_8069B9D0:
    // 0x8069B9D0: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8069B9D4: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8069B9D8: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x8069B9DC: sw          $t5, -0x40($v1)
    MEM_W(-0X40, ctx->r3) = ctx->r13;
    // 0x8069B9E0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8069B9E4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8069B9E8: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x8069B9EC: sw          $t9, -0x3C($v1)
    MEM_W(-0X3C, ctx->r3) = ctx->r25;
    // 0x8069B9F0: lw          $t5, -0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X38);
    // 0x8069B9F4: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x8069B9F8: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x8069B9FC: sw          $t5, -0x38($v1)
    MEM_W(-0X38, ctx->r3) = ctx->r13;
    // 0x8069BA00: lw          $t9, -0x34($a0)
    ctx->r25 = MEM_W(ctx->r4, -0X34);
    // 0x8069BA04: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x8069BA08: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
    // 0x8069BA0C: sw          $t9, -0x34($v1)
    MEM_W(-0X34, ctx->r3) = ctx->r25;
    // 0x8069BA10: lw          $t7, -0x40($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X40);
    // 0x8069BA14: sw          $t7, -0x40($a1)
    MEM_W(-0X40, ctx->r5) = ctx->r15;
    // 0x8069BA18: lw          $t6, -0x3C($a2)
    ctx->r14 = MEM_W(ctx->r6, -0X3C);
    // 0x8069BA1C: sw          $t6, -0x3C($a1)
    MEM_W(-0X3C, ctx->r5) = ctx->r14;
    // 0x8069BA20: lw          $t7, -0x38($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X38);
    // 0x8069BA24: sw          $t7, -0x38($a1)
    MEM_W(-0X38, ctx->r5) = ctx->r15;
    // 0x8069BA28: lw          $t6, -0x34($a2)
    ctx->r14 = MEM_W(ctx->r6, -0X34);
    // 0x8069BA2C: sw          $t6, -0x34($a1)
    MEM_W(-0X34, ctx->r5) = ctx->r14;
    // 0x8069BA30: lw          $t9, -0x40($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X40);
    // 0x8069BA34: sw          $t9, -0x40($a3)
    MEM_W(-0X40, ctx->r7) = ctx->r25;
    // 0x8069BA38: lw          $t8, -0x3C($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X3C);
    // 0x8069BA3C: sw          $t8, -0x3C($a3)
    MEM_W(-0X3C, ctx->r7) = ctx->r24;
    // 0x8069BA40: lw          $t9, -0x38($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X38);
    // 0x8069BA44: sw          $t9, -0x38($a3)
    MEM_W(-0X38, ctx->r7) = ctx->r25;
    // 0x8069BA48: lw          $t8, -0x34($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X34);
    // 0x8069BA4C: sw          $t8, -0x34($a3)
    MEM_W(-0X34, ctx->r7) = ctx->r24;
    // 0x8069BA50: lw          $t6, -0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X40);
    // 0x8069BA54: sw          $t6, -0x40($t1)
    MEM_W(-0X40, ctx->r9) = ctx->r14;
    // 0x8069BA58: lw          $t5, -0x3C($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X3C);
    // 0x8069BA5C: sw          $t5, -0x3C($t1)
    MEM_W(-0X3C, ctx->r9) = ctx->r13;
    // 0x8069BA60: lw          $t6, -0x38($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X38);
    // 0x8069BA64: sw          $t6, -0x38($t1)
    MEM_W(-0X38, ctx->r9) = ctx->r14;
    // 0x8069BA68: lw          $t5, -0x34($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X34);
    // 0x8069BA6C: bne         $v0, $t2, L_8069B9D0
    if (ctx->r2 != ctx->r10) {
        // 0x8069BA70: sw          $t5, -0x34($t1)
        MEM_W(-0X34, ctx->r9) = ctx->r13;
            goto L_8069B9D0;
    }
    // 0x8069BA70: sw          $t5, -0x34($t1)
    MEM_W(-0X34, ctx->r9) = ctx->r13;
    // 0x8069BA74: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8069BA78: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(565, 0X10) << 16);
    // 0x8069BA7C: addiu       $t7, $t7, -0x5320
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(565, 0X10));
    // 0x8069BA80: sw          $t7, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r15;
    // 0x8069BA84: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    // 0x8069BA88: lhu         $t5, 0xC($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0XC);
    // 0x8069BA8C: addiu       $t6, $t5, -0x4585
    ctx->r14 = ADD32(ctx->r13, -0X4585);
    // 0x8069BA90: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8069BA94: beq         $at, $zero, L_8069BC10
    if (ctx->r1 == 0) {
        // 0x8069BA98: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8069BC10;
    }
    // 0x8069BA98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8069BA9C: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(565, 0X193C) << 16);
    // 0x8069BAA0: addu        $at, $at, $t6
    gpr jr_addend_8069BAA8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8069BAA4: lw          $t6, -0x39F4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(565, 0X193C));
    // 0x8069BAA8: jr          $t6
    // 0x8069BAAC: nop

    switch (jr_addend_8069BAA8 >> 2) {
        case 0: goto L_8069BAB0; break;
        case 1: goto L_8069BAD0; break;
        case 2: goto L_8069BAF0; break;
        case 3: goto L_8069BB20; break;
        case 4: goto L_8069BB4C; break;
        case 5: goto L_8069BB78; break;
        case 6: goto L_8069BBA4; break;
        case 7: goto L_8069BBF0; break;
        case 8: goto L_8069BBD0; break;
        default: switch_error(__func__, 0x8069BAA8, 0x8069C60C);
    }
    // 0x8069BAAC: nop

L_8069BAB0:
    // 0x8069BAB0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8069BAB4: sw          $t7, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r15;
    // 0x8069BAB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069BABC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069BAC0: jal         0x8069BC34
    // 0x8069BAC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8069BC34(rdram, ctx);
        goto after_2;
    // 0x8069BAC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8069BAC8: b           L_8069BC24
    // 0x8069BACC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069BC24;
    // 0x8069BACC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069BAD0:
    // 0x8069BAD0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8069BAD4: sw          $t8, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r24;
    // 0x8069BAD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069BADC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069BAE0: jal         0x8069BC34
    // 0x8069BAE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8069BC34(rdram, ctx);
        goto after_3;
    // 0x8069BAE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8069BAE8: b           L_8069BC24
    // 0x8069BAEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069BC24;
    // 0x8069BAEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069BAF0:
    // 0x8069BAF0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8069BAF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8069BAF8: sw          $t9, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r25;
    // 0x8069BAFC: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
    // 0x8069BB00: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8069BB04: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    // 0x8069BB08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069BB0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069BB10: jal         0x8069BC34
    // 0x8069BB14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8069BC34(rdram, ctx);
        goto after_4;
    // 0x8069BB14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8069BB18: b           L_8069BC24
    // 0x8069BB1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069BC24;
    // 0x8069BB1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069BB20:
    // 0x8069BB20: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(565, 0X1960) << 16);
    // 0x8069BB24: lwc1        $f4, -0x39D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(565, 0X1960));
    // 0x8069BB28: addiu       $t7, $zero, 0x309
    ctx->r15 = ADD32(0, 0X309);
    // 0x8069BB2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069BB30: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x8069BB34: sw          $t7, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r15;
    // 0x8069BB38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069BB3C: jal         0x8069BC34
    // 0x8069BB40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8069BC34(rdram, ctx);
        goto after_5;
    // 0x8069BB40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8069BB44: b           L_8069BC24
    // 0x8069BB48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069BC24;
    // 0x8069BB48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069BB4C:
    // 0x8069BB4C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x8069BB50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8069BB54: addiu       $t8, $zero, 0x309
    ctx->r24 = ADD32(0, 0X309);
    // 0x8069BB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069BB5C: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x8069BB60: sw          $t8, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r24;
    // 0x8069BB64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069BB68: jal         0x8069BC34
    // 0x8069BB6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8069BC34(rdram, ctx);
        goto after_6;
    // 0x8069BB6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8069BB70: b           L_8069BC24
    // 0x8069BB74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069BC24;
    // 0x8069BB74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069BB78:
    // 0x8069BB78: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8069BB7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8069BB80: addiu       $t9, $zero, 0x309
    ctx->r25 = ADD32(0, 0X309);
    // 0x8069BB84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069BB88: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x8069BB8C: sw          $t9, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r25;
    // 0x8069BB90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069BB94: jal         0x8069BC34
    // 0x8069BB98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8069BC34(rdram, ctx);
        goto after_7;
    // 0x8069BB98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8069BB9C: b           L_8069BC24
    // 0x8069BBA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069BC24;
    // 0x8069BBA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069BBA4:
    // 0x8069BBA4: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x8069BBA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8069BBAC: addiu       $t5, $zero, 0x309
    ctx->r13 = ADD32(0, 0X309);
    // 0x8069BBB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069BBB4: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x8069BBB8: sw          $t5, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r13;
    // 0x8069BBBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069BBC0: jal         0x8069BC34
    // 0x8069BBC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8069BC34(rdram, ctx);
        goto after_8;
    // 0x8069BBC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8069BBC8: b           L_8069BC24
    // 0x8069BBCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069BC24;
    // 0x8069BBCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069BBD0:
    // 0x8069BBD0: addiu       $t6, $zero, 0x309
    ctx->r14 = ADD32(0, 0X309);
    // 0x8069BBD4: sw          $t6, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r14;
    // 0x8069BBD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069BBDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069BBE0: jal         0x8069BC34
    // 0x8069BBE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8069BC34(rdram, ctx);
        goto after_9;
    // 0x8069BBE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x8069BBE8: b           L_8069BC24
    // 0x8069BBEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069BC24;
    // 0x8069BBEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069BBF0:
    // 0x8069BBF0: addiu       $t7, $zero, 0x309
    ctx->r15 = ADD32(0, 0X309);
    // 0x8069BBF4: sw          $t7, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r15;
    // 0x8069BBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069BBFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069BC00: jal         0x8069BC34
    // 0x8069BC04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8069BC34(rdram, ctx);
        goto after_10;
    // 0x8069BC04: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x8069BC08: b           L_8069BC24
    // 0x8069BC0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069BC24;
    // 0x8069BC0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069BC10:
    // 0x8069BC10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069BC14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069BC18: jal         0x8069BC34
    // 0x8069BC1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8069BC34(rdram, ctx);
        goto after_11;
    // 0x8069BC1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8069BC20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069BC24:
    // 0x8069BC24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069BC28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069BC2C: jr          $ra
    // 0x8069BC30: nop

    return;
    // 0x8069BC30: nop

;}
RECOMP_FUNC void func_80579C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80579C6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80579C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80579C74: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80579C78: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80579C7C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80579C80: beq         $a1, $at, L_80579CA0
    if (ctx->r5 == ctx->r1) {
        // 0x80579C84: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80579CA0;
    }
    // 0x80579C84: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80579C88: lw          $a0, 0x48C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48C);
    // 0x80579C8C: jal         0x80067878
    // 0x80579C90: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80579C90: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80579C94: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80579C98: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80579C9C: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_80579CA0:
    // 0x80579CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80579CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80579CA8: jr          $ra
    // 0x80579CAC: nop

    return;
    // 0x80579CAC: nop

;}
RECOMP_FUNC void func_8004667C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004667C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80046680: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80046684: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80046688: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004668C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80046690: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80046694: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80046698: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004669C: lw          $a0, -0x7784($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7784);
    // 0x800466A0: jal         0x80057AC0
    // 0x800466A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80057AC0(rdram, ctx);
        goto after_0;
    // 0x800466A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800466A8: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x800466AC: bne         $v0, $at, L_8004671C
    if (ctx->r2 != ctx->r1) {
        // 0x800466B0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8004671C;
    }
    // 0x800466B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800466B4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800466B8: jal         0x80065728
    // 0x800466BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x800466BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x800466C0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800466C4: sw          $s0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r16;
    // 0x800466C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800466CC: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800466D0: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800466D4: sll         $a1, $a1, 7
    ctx->r5 = S32(ctx->r5 << 7);
    // 0x800466D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800466DC: jal         0x80065728
    // 0x800466E0: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x800466E0: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    after_2:
    // 0x800466E4: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x800466E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800466EC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800466F0: blez        $t6, L_80046714
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800466F4: nop
    
            goto L_80046714;
    }
    // 0x800466F4: nop

    // 0x800466F8: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
L_800466FC:
    // 0x800466FC: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x80046700: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80046704: addiu       $s0, $s0, 0x280
    ctx->r16 = ADD32(ctx->r16, 0X280);
    // 0x80046708: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8004670C: bnel        $at, $zero, L_800466FC
    if (ctx->r1 != 0) {
        // 0x80046710: sb          $v1, 0x9($s0)
        MEM_B(0X9, ctx->r16) = ctx->r3;
            goto L_800466FC;
    }
    goto skip_0;
    // 0x80046710: sb          $v1, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r3;
    skip_0:
L_80046714:
    // 0x80046714: jal         0x8004661C
    // 0x80046718: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8004661C(rdram, ctx);
        goto after_3;
    // 0x80046718: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_8004671C:
    // 0x8004671C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80046720: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80046724: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80046728: jr          $ra
    // 0x8004672C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004672C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80566DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566DF4: jr          $ra
    // 0x80566DF8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80566DF8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8042FC98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FC98: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BB0) << 16);
    // 0x8042FC9C: lwc1        $f4, 0x1C90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BB0));
    // 0x8042FCA0: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042FCA4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8042FCA8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8042FCAC: nop

    // 0x8042FCB0: bc1fl       L_8042FCEC
    if (!c1cs) {
        // 0x8042FCB4: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8042FCEC;
    }
    goto skip_0;
    // 0x8042FCB4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x8042FCB8: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8042FCBC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042FCC0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8042FCC4: nop

    // 0x8042FCC8: bc1fl       L_8042FCE0
    if (!c1cs) {
        // 0x8042FCCC: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8042FCE0;
    }
    goto skip_1;
    // 0x8042FCCC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_1:
    // 0x8042FCD0: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8042FCD4: b           L_8042FCE8
    // 0x8042FCD8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_8042FCE8;
    // 0x8042FCD8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8042FCDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8042FCE0:
    // 0x8042FCE0: nop

    // 0x8042FCE4: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_8042FCE8:
    // 0x8042FCE8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8042FCEC:
    // 0x8042FCEC: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8042FCF0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8042FCF4: nop

    // 0x8042FCF8: bc1fl       L_8042FD2C
    if (!c1cs) {
        // 0x8042FCFC: swc1        $f2, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
            goto L_8042FD2C;
    }
    goto skip_2;
    // 0x8042FCFC: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
    skip_2:
    // 0x8042FD00: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FD04: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BB4) << 16);
    // 0x8042FD08: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8042FD0C: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8042FD10: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x8042FD14: lwc1        $f4, 0x1C94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BB4));
    // 0x8042FD18: lwc1        $f18, 0x2C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8042FD1C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8042FD20: jr          $ra
    // 0x8042FD24: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8042FD24: swc1        $f6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x8042FD28: swc1        $f2, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f2.u32l;
L_8042FD2C:
    // 0x8042FD2C: jr          $ra
    // 0x8042FD30: nop

    return;
    // 0x8042FD30: nop

;}
RECOMP_FUNC void func_80033494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033494: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003349C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x800334A0: lw          $v0, 0x19C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X19C);
    // 0x800334A4: beq         $v0, $zero, L_800334B4
    if (ctx->r2 == 0) {
        // 0x800334A8: nop
    
            goto L_800334B4;
    }
    // 0x800334A8: nop

    // 0x800334AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800334B0: sw          $v0, 0x19C($v1)
    MEM_W(0X19C, ctx->r3) = ctx->r2;
L_800334B4:
    // 0x800334B4: bne         $v0, $zero, L_800334CC
    if (ctx->r2 != 0) {
        // 0x800334B8: sll         $a1, $v0, 16
        ctx->r5 = S32(ctx->r2 << 16);
            goto L_800334CC;
    }
    // 0x800334B8: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x800334BC: jal         0x8002D76C
    // 0x800334C0: nop

    func_8002D76C(rdram, ctx);
        goto after_0;
    // 0x800334C0: nop

    after_0:
    // 0x800334C4: b           L_800334DC
    // 0x800334C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800334DC;
    // 0x800334C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800334CC:
    // 0x800334CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800334D0: jal         0x80067ACC
    // 0x800334D4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067ACC(rdram, ctx);
        goto after_1;
    // 0x800334D4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_1:
    // 0x800334D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800334DC:
    // 0x800334DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800334E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800334E4: jr          $ra
    // 0x800334E8: nop

    return;
    // 0x800334E8: nop

;}
RECOMP_FUNC void func_8003D894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D894: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D898: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003D89C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003D8A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D8A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003D8A8: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8003D8AC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8003D8B0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8003D8B4: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8003D8B8: addiu       $a3, $a3, -0x277C
    ctx->r7 = ADD32(ctx->r7, -0X277C);
    // 0x8003D8BC: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x8003D8C0: addiu       $a0, $t8, 0x188
    ctx->r4 = ADD32(ctx->r24, 0X188);
    // 0x8003D8C4: jal         0x80057F74
    // 0x8003D8C8: lh          $a1, 0x184($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X184);
    func_80057F74(rdram, ctx);
        goto after_0;
    // 0x8003D8C8: lh          $a1, 0x184($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X184);
    after_0:
    // 0x8003D8CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D8D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D8D4: jr          $ra
    // 0x8003D8D8: nop

    return;
    // 0x8003D8D8: nop

;}
RECOMP_FUNC void func_8049FBAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049FBAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8049FBB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8049FBB4: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8049FBB8: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8049FBBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8049FBC0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8049FBC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8049FBC8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8049FBCC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8049FBD0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8049FBD4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8049FBD8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8049FBDC: lui         $t2, 0x804A
    ctx->r10 = S32(RELOC_HI16(167, 0X1170) << 16);
    // 0x8049FBE0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8049FBE4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8049FBE8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8049FBEC: lw          $t2, -0x310($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(167, 0X1170));
    // 0x8049FBF0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8049FBF4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8049FBF8: jal         0x8049FC18
    // 0x8049FBFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8049FC18(rdram, ctx);
        goto after_0;
    // 0x8049FBFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8049FC00: jal         0x8049FC64
    // 0x8049FC04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8049FC64(rdram, ctx);
        goto after_1;
    // 0x8049FC04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8049FC08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8049FC0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8049FC10: jr          $ra
    // 0x8049FC14: nop

    return;
    // 0x8049FC14: nop

;}
RECOMP_FUNC void func_8057F218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F218: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8057F21C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F220: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8057F224: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057F228: addiu       $t3, $a3, 0x14
    ctx->r11 = ADD32(ctx->r7, 0X14);
    // 0x8057F22C: addiu       $t4, $a3, 0x1C
    ctx->r12 = ADD32(ctx->r7, 0X1C);
    // 0x8057F230: addiu       $t2, $a3, 0x2C
    ctx->r10 = ADD32(ctx->r7, 0X2C);
    // 0x8057F234: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8057F238: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8057F23C: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x8057F240: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8057F244: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8057F248: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8057F24C: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x8057F250: jal         0x8057EFA0
    // 0x8057F254: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_8057EFA0(rdram, ctx);
        goto after_0;
    // 0x8057F254: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x8057F258: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8057F25C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8057F260: jal         0x80047AB8
    // 0x8057F264: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x8057F264: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x8057F268: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8057F26C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8057F270: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8057F274: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8057F278: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8057F27C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8057F280: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8057F284: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8057F288: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8057F28C: bltz        $t5, L_8057F474
    if (SIGNED(ctx->r13) < 0) {
        // 0x8057F290: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8057F474;
    }
    // 0x8057F290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8057F294: addiu       $v0, $t5, 0x1
    ctx->r2 = ADD32(ctx->r13, 0X1);
    // 0x8057F298: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8057F29C: beq         $v0, $zero, L_8057F340
    if (ctx->r2 == 0) {
        // 0x8057F2A0: lwc1        $f6, 0x34($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8057F340;
    }
    // 0x8057F2A0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8057F2A4: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8057F2A8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8057F2AC: addiu       $v1, $a3, 0x4
    ctx->r3 = ADD32(ctx->r7, 0X4);
    // 0x8057F2B0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8057F2B4: addiu       $t0, $t3, 0x2
    ctx->r8 = ADD32(ctx->r11, 0X2);
    // 0x8057F2B8: addiu       $t1, $t4, 0x4
    ctx->r9 = ADD32(ctx->r12, 0X4);
    // 0x8057F2BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8057F2C0: swc1        $f8, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f8.u32l;
    // 0x8057F2C4: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8057F2C8: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8057F2CC: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x8057F2D0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8057F2D4: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8057F2D8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8057F2DC: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8057F2E0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8057F2E4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8057F2E8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8057F2EC: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x8057F2F0: sh          $t7, 0x144($t8)
    MEM_H(0X144, ctx->r24) = ctx->r15;
    // 0x8057F2F4: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x8057F2F8: beql        $t9, $zero, L_8057F330
    if (ctx->r25 == 0) {
        // 0x8057F2FC: lw          $t7, 0x0($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X0);
            goto L_8057F330;
    }
    goto skip_0;
    // 0x8057F2FC: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x8057F300: lw          $t6, 0x68($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X68);
    // 0x8057F304: bnel        $t6, $zero, L_8057F320
    if (ctx->r14 != 0) {
        // 0x8057F308: lw          $t6, 0x0($a3)
        ctx->r14 = MEM_W(ctx->r7, 0X0);
            goto L_8057F320;
    }
    goto skip_1;
    // 0x8057F308: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x8057F30C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8057F310: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8057F314: b           L_8057F334
    // 0x8057F318: sb          $t7, 0x30($t8)
    MEM_B(0X30, ctx->r24) = ctx->r15;
        goto L_8057F334;
    // 0x8057F318: sb          $t7, 0x30($t8)
    MEM_B(0X30, ctx->r24) = ctx->r15;
    // 0x8057F31C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
L_8057F320:
    // 0x8057F320: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8057F324: b           L_8057F334
    // 0x8057F328: sb          $t9, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r25;
        goto L_8057F334;
    // 0x8057F328: sb          $t9, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r25;
    // 0x8057F32C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
L_8057F330:
    // 0x8057F330: sb          $zero, 0x30($t7)
    MEM_B(0X30, ctx->r15) = 0;
L_8057F334:
    // 0x8057F334: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x8057F338: beq         $t8, $a0, L_8057F474
    if (ctx->r24 == ctx->r4) {
        // 0x8057F33C: addiu       $a2, $t2, 0xC
        ctx->r6 = ADD32(ctx->r10, 0XC);
            goto L_8057F474;
    }
    // 0x8057F33C: addiu       $a2, $t2, 0xC
    ctx->r6 = ADD32(ctx->r10, 0XC);
L_8057F340:
    // 0x8057F340: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8057F344: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8057F348: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8057F34C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8057F350: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8057F354: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x8057F358: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8057F35C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8057F360: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8057F364: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8057F368: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8057F36C: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8057F370: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8057F374: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8057F378: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    // 0x8057F37C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8057F380: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x8057F384: sh          $t9, 0x144($t6)
    MEM_H(0X144, ctx->r14) = ctx->r25;
    // 0x8057F388: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8057F38C: beql        $t7, $zero, L_8057F3C4
    if (ctx->r15 == 0) {
        // 0x8057F390: lw          $t9, 0x0($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X0);
            goto L_8057F3C4;
    }
    goto skip_2;
    // 0x8057F390: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x8057F394: lw          $t8, 0x68($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X68);
    // 0x8057F398: bnel        $t8, $zero, L_8057F3B4
    if (ctx->r24 != 0) {
        // 0x8057F39C: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_8057F3B4;
    }
    goto skip_3;
    // 0x8057F39C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x8057F3A0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8057F3A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8057F3A8: b           L_8057F3C8
    // 0x8057F3AC: sb          $t9, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r25;
        goto L_8057F3C8;
    // 0x8057F3AC: sb          $t9, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r25;
    // 0x8057F3B0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_8057F3B4:
    // 0x8057F3B4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8057F3B8: b           L_8057F3C8
    // 0x8057F3BC: sb          $t7, 0x30($t8)
    MEM_B(0X30, ctx->r24) = ctx->r15;
        goto L_8057F3C8;
    // 0x8057F3BC: sb          $t7, 0x30($t8)
    MEM_B(0X30, ctx->r24) = ctx->r15;
    // 0x8057F3C0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
L_8057F3C4:
    // 0x8057F3C4: sb          $zero, 0x30($t9)
    MEM_B(0X30, ctx->r25) = 0;
L_8057F3C8:
    // 0x8057F3C8: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8057F3CC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8057F3D0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8057F3D4: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8057F3D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8057F3DC: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8057F3E0: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8057F3E4: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8057F3E8: swc1        $f8, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f8.u32l;
    // 0x8057F3EC: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8057F3F0: lwc1        $f10, -0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X8);
    // 0x8057F3F4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8057F3F8: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8057F3FC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8057F400: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8057F404: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x8057F408: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8057F40C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8057F410: lwc1        $f4, -0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8057F414: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8057F418: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8057F41C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8057F420: lh          $t6, -0x2($t0)
    ctx->r14 = MEM_H(ctx->r8, -0X2);
    // 0x8057F424: sh          $t6, 0x144($t7)
    MEM_H(0X144, ctx->r15) = ctx->r14;
    // 0x8057F428: lw          $t8, -0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, -0X4);
    // 0x8057F42C: beql        $t8, $zero, L_8057F464
    if (ctx->r24 == 0) {
        // 0x8057F430: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_8057F464;
    }
    goto skip_4;
    // 0x8057F430: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x8057F434: lw          $t9, 0x68($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X68);
    // 0x8057F438: bnel        $t9, $zero, L_8057F454
    if (ctx->r25 != 0) {
        // 0x8057F43C: lw          $t9, 0x0($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X0);
            goto L_8057F454;
    }
    goto skip_5;
    // 0x8057F43C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    skip_5:
    // 0x8057F440: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8057F444: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8057F448: b           L_8057F468
    // 0x8057F44C: sb          $t6, 0x30($t7)
    MEM_B(0X30, ctx->r15) = ctx->r14;
        goto L_8057F468;
    // 0x8057F44C: sb          $t6, 0x30($t7)
    MEM_B(0X30, ctx->r15) = ctx->r14;
    // 0x8057F450: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
L_8057F454:
    // 0x8057F454: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8057F458: b           L_8057F468
    // 0x8057F45C: sb          $t8, 0x30($t9)
    MEM_B(0X30, ctx->r25) = ctx->r24;
        goto L_8057F468;
    // 0x8057F45C: sb          $t8, 0x30($t9)
    MEM_B(0X30, ctx->r25) = ctx->r24;
    // 0x8057F460: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8057F464:
    // 0x8057F464: sb          $zero, 0x30($t6)
    MEM_B(0X30, ctx->r14) = 0;
L_8057F468:
    // 0x8057F468: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8057F46C: bne         $t7, $a0, L_8057F340
    if (ctx->r15 != ctx->r4) {
        // 0x8057F470: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8057F340;
    }
    // 0x8057F470: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8057F474:
    // 0x8057F474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F478: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8057F47C: jr          $ra
    // 0x8057F480: nop

    return;
    // 0x8057F480: nop

;}
RECOMP_FUNC void func_805D2170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D2174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D2178: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805D217C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805D2180: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x805D2184: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805D2188: jal         0x80067BBC
    // 0x805D218C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805D218C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x805D2190: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805D2194: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805D2198: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x805D219C: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    // 0x805D21A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805D21A4: bnel        $a1, $at, L_805D21CC
    if (ctx->r5 != ctx->r1) {
        // 0x805D21A8: sw          $a2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r6;
            goto L_805D21CC;
    }
    goto skip_0;
    // 0x805D21A8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    skip_0:
    // 0x805D21AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805D21B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805D21B4: jal         0x80067F78
    // 0x805D21B8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x805D21B8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x805D21BC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805D21C0: b           L_805D21F0
    // 0x805D21C4: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
        goto L_805D21F0;
    // 0x805D21C4: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
    // 0x805D21C8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
L_805D21CC:
    // 0x805D21CC: jal         0x80067930
    // 0x805D21D0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x805D21D0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x805D21D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805D21D8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x805D21DC: bne         $v0, $at, L_805D21F0
    if (ctx->r2 != ctx->r1) {
        // 0x805D21E0: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_805D21F0;
    }
    // 0x805D21E0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805D21E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805D21E8: jal         0x800678F0
    // 0x805D21EC: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x805D21EC: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_3:
L_805D21F0:
    // 0x805D21F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D21F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D21F8: jr          $ra
    // 0x805D21FC: nop

    return;
    // 0x805D21FC: nop

;}
RECOMP_FUNC void func_804A0C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0C98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A0C9C: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x804A0CA0: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x804A0CA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804A0CA8: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x804A0CAC: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x804A0CB0: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x804A0CB4: beq         $v0, $zero, L_804A0D24
    if (ctx->r2 == 0) {
        // 0x804A0CB8: add.s       $f12, $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f14.fl;
            goto L_804A0D24;
    }
    // 0x804A0CB8: add.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x804A0CBC: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0CC0: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0CC4: nop

    // 0x804A0CC8: bc1fl       L_804A0D28
    if (!c1cs) {
        // 0x804A0CCC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0D28;
    }
    goto skip_0;
    // 0x804A0CCC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x804A0CD0: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0CD4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x804A0CD8: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804A0CDC: sub.s       $f16, $f12, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x804A0CE0: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A0CE4: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0CE8: bc1fl       L_804A0D28
    if (!c1cs) {
        // 0x804A0CEC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0D28;
    }
    goto skip_1;
    // 0x804A0CEC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x804A0CF0: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0CF4: neg.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = -ctx->f20.fl;
    // 0x804A0CF8: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x804A0CFC: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x804A0D00: nop

    // 0x804A0D04: bc1fl       L_804A0D28
    if (!c1cs) {
        // 0x804A0D08: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0D28;
    }
    goto skip_2;
    // 0x804A0D08: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_2:
    // 0x804A0D0C: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A0D10: nop

    // 0x804A0D14: bc1fl       L_804A0D28
    if (!c1cs) {
        // 0x804A0D18: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0D28;
    }
    goto skip_3;
    // 0x804A0D18: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_3:
    // 0x804A0D1C: b           L_804A0FCC
    // 0x804A0D20: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0FCC;
    // 0x804A0D20: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_804A0D24:
    // 0x804A0D24: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0D28:
    // 0x804A0D28: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x804A0D2C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804A0D30: beq         $v0, $zero, L_804A0D98
    if (ctx->r2 == 0) {
        // 0x804A0D34: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_804A0D98;
    }
    // 0x804A0D34: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0D38: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0D3C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0D40: nop

    // 0x804A0D44: bc1fl       L_804A0D9C
    if (!c1cs) {
        // 0x804A0D48: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0D9C;
    }
    goto skip_4;
    // 0x804A0D48: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_4:
    // 0x804A0D4C: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0D50: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x804A0D54: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A0D58: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0D5C: bc1fl       L_804A0D9C
    if (!c1cs) {
        // 0x804A0D60: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0D9C;
    }
    goto skip_5;
    // 0x804A0D60: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_5:
    // 0x804A0D64: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0D68: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x804A0D6C: sub.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x804A0D70: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x804A0D74: nop

    // 0x804A0D78: bc1fl       L_804A0D9C
    if (!c1cs) {
        // 0x804A0D7C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0D9C;
    }
    goto skip_6;
    // 0x804A0D7C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_6:
    // 0x804A0D80: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A0D84: nop

    // 0x804A0D88: bc1fl       L_804A0D9C
    if (!c1cs) {
        // 0x804A0D8C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0D9C;
    }
    goto skip_7;
    // 0x804A0D8C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_7:
    // 0x804A0D90: b           L_804A0FCC
    // 0x804A0D94: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0FCC;
    // 0x804A0D94: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_804A0D98:
    // 0x804A0D98: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0D9C:
    // 0x804A0D9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0DA0: beql        $v0, $zero, L_804A0E0C
    if (ctx->r2 == 0) {
        // 0x804A0DA4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0E0C;
    }
    goto skip_8;
    // 0x804A0DA4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_8:
    // 0x804A0DA8: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0DAC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0DB0: nop

    // 0x804A0DB4: bc1fl       L_804A0E0C
    if (!c1cs) {
        // 0x804A0DB8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0E0C;
    }
    goto skip_9;
    // 0x804A0DB8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_9:
    // 0x804A0DBC: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0DC0: sub.s       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x804A0DC4: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A0DC8: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0DCC: bc1fl       L_804A0E0C
    if (!c1cs) {
        // 0x804A0DD0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0E0C;
    }
    goto skip_10;
    // 0x804A0DD0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x804A0DD4: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0DD8: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x804A0DDC: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x804A0DE0: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x804A0DE4: nop

    // 0x804A0DE8: bc1fl       L_804A0E0C
    if (!c1cs) {
        // 0x804A0DEC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0E0C;
    }
    goto skip_11;
    // 0x804A0DEC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_11:
    // 0x804A0DF0: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A0DF4: nop

    // 0x804A0DF8: bc1fl       L_804A0E0C
    if (!c1cs) {
        // 0x804A0DFC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0E0C;
    }
    goto skip_12;
    // 0x804A0DFC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_12:
    // 0x804A0E00: b           L_804A0FCC
    // 0x804A0E04: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0FCC;
    // 0x804A0E04: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0E08: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0E0C:
    // 0x804A0E0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0E10: beql        $v0, $zero, L_804A0E7C
    if (ctx->r2 == 0) {
        // 0x804A0E14: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0E7C;
    }
    goto skip_13;
    // 0x804A0E14: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_13:
    // 0x804A0E18: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0E1C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0E20: nop

    // 0x804A0E24: bc1fl       L_804A0E7C
    if (!c1cs) {
        // 0x804A0E28: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0E7C;
    }
    goto skip_14;
    // 0x804A0E28: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_14:
    // 0x804A0E2C: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0E30: sub.s       $f16, $f12, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x804A0E34: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A0E38: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0E3C: bc1fl       L_804A0E7C
    if (!c1cs) {
        // 0x804A0E40: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0E7C;
    }
    goto skip_15;
    // 0x804A0E40: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_15:
    // 0x804A0E44: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0E48: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
    // 0x804A0E4C: sub.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x804A0E50: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x804A0E54: nop

    // 0x804A0E58: bc1fl       L_804A0E7C
    if (!c1cs) {
        // 0x804A0E5C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0E7C;
    }
    goto skip_16;
    // 0x804A0E5C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_16:
    // 0x804A0E60: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A0E64: nop

    // 0x804A0E68: bc1fl       L_804A0E7C
    if (!c1cs) {
        // 0x804A0E6C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0E7C;
    }
    goto skip_17;
    // 0x804A0E6C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_17:
    // 0x804A0E70: b           L_804A0FCC
    // 0x804A0E74: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0FCC;
    // 0x804A0E74: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0E78: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0E7C:
    // 0x804A0E7C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0E80: beql        $v0, $zero, L_804A0EEC
    if (ctx->r2 == 0) {
        // 0x804A0E84: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0EEC;
    }
    goto skip_18;
    // 0x804A0E84: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_18:
    // 0x804A0E88: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0E8C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0E90: nop

    // 0x804A0E94: bc1fl       L_804A0EEC
    if (!c1cs) {
        // 0x804A0E98: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0EEC;
    }
    goto skip_19;
    // 0x804A0E98: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_19:
    // 0x804A0E9C: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0EA0: sub.s       $f16, $f12, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x804A0EA4: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A0EA8: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0EAC: bc1fl       L_804A0EEC
    if (!c1cs) {
        // 0x804A0EB0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0EEC;
    }
    goto skip_20;
    // 0x804A0EB0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_20:
    // 0x804A0EB4: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0EB8: neg.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = -ctx->f20.fl;
    // 0x804A0EBC: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x804A0EC0: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x804A0EC4: nop

    // 0x804A0EC8: bc1fl       L_804A0EEC
    if (!c1cs) {
        // 0x804A0ECC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0EEC;
    }
    goto skip_21;
    // 0x804A0ECC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_21:
    // 0x804A0ED0: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A0ED4: nop

    // 0x804A0ED8: bc1fl       L_804A0EEC
    if (!c1cs) {
        // 0x804A0EDC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0EEC;
    }
    goto skip_22;
    // 0x804A0EDC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_22:
    // 0x804A0EE0: b           L_804A0FCC
    // 0x804A0EE4: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0FCC;
    // 0x804A0EE4: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0EE8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0EEC:
    // 0x804A0EEC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0EF0: beql        $v0, $zero, L_804A0F5C
    if (ctx->r2 == 0) {
        // 0x804A0EF4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0F5C;
    }
    goto skip_23;
    // 0x804A0EF4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_23:
    // 0x804A0EF8: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0EFC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0F00: nop

    // 0x804A0F04: bc1fl       L_804A0F5C
    if (!c1cs) {
        // 0x804A0F08: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0F5C;
    }
    goto skip_24;
    // 0x804A0F08: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_24:
    // 0x804A0F0C: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0F10: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x804A0F14: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A0F18: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0F1C: bc1fl       L_804A0F5C
    if (!c1cs) {
        // 0x804A0F20: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0F5C;
    }
    goto skip_25;
    // 0x804A0F20: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_25:
    // 0x804A0F24: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0F28: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x804A0F2C: sub.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x804A0F30: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x804A0F34: nop

    // 0x804A0F38: bc1fl       L_804A0F5C
    if (!c1cs) {
        // 0x804A0F3C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0F5C;
    }
    goto skip_26;
    // 0x804A0F3C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_26:
    // 0x804A0F40: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A0F44: nop

    // 0x804A0F48: bc1fl       L_804A0F5C
    if (!c1cs) {
        // 0x804A0F4C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0F5C;
    }
    goto skip_27;
    // 0x804A0F4C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_27:
    // 0x804A0F50: b           L_804A0FCC
    // 0x804A0F54: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0FCC;
    // 0x804A0F54: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0F58: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0F5C:
    // 0x804A0F5C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0F60: beql        $v0, $zero, L_804A0FCC
    if (ctx->r2 == 0) {
        // 0x804A0F64: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_804A0FCC;
    }
    goto skip_28;
    // 0x804A0F64: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_28:
    // 0x804A0F68: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0F6C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804A0F70: nop

    // 0x804A0F74: bc1fl       L_804A0FCC
    if (!c1cs) {
        // 0x804A0F78: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_804A0FCC;
    }
    goto skip_29;
    // 0x804A0F78: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_29:
    // 0x804A0F7C: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x804A0F80: sub.s       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x804A0F84: c.le.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl <= ctx->f16.fl;
    // 0x804A0F88: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0F8C: bc1fl       L_804A0FCC
    if (!c1cs) {
        // 0x804A0F90: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_804A0FCC;
    }
    goto skip_30;
    // 0x804A0F90: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_30:
    // 0x804A0F94: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0F98: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x804A0F9C: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x804A0FA0: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x804A0FA4: nop

    // 0x804A0FA8: bc1fl       L_804A0FCC
    if (!c1cs) {
        // 0x804A0FAC: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_804A0FCC;
    }
    goto skip_31;
    // 0x804A0FAC: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_31:
    // 0x804A0FB0: c.le.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl <= ctx->f20.fl;
    // 0x804A0FB4: nop

    // 0x804A0FB8: bc1fl       L_804A0FCC
    if (!c1cs) {
        // 0x804A0FBC: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_804A0FCC;
    }
    goto skip_32;
    // 0x804A0FBC: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_32:
    // 0x804A0FC0: b           L_804A0FCC
    // 0x804A0FC4: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0FCC;
    // 0x804A0FC4: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0FC8: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_804A0FCC:
    // 0x804A0FCC: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x804A0FD0: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x804A0FD4: jr          $ra
    // 0x804A0FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804A0FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806AF278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AF278: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806AF27C: lui         $t6, 0x806B
    ctx->r14 = S32(RELOC_HI16(595, 0X129C) << 16);
    // 0x806AF280: addiu       $t6, $t6, -0x1024
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(595, 0X129C));
    // 0x806AF284: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806AF288: jr          $ra
    // 0x806AF28C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806AF28C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8051974C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051974C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80519750: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80519754: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80519758: jal         0x80517CA8
    // 0x8051975C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80517CA8(rdram, ctx);
        goto after_0;
    // 0x8051975C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80519760: jal         0x80519124
    // 0x80519764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519124(rdram, ctx);
        goto after_1;
    // 0x80519764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80519768: jal         0x80519340
    // 0x8051976C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519340(rdram, ctx);
        goto after_2;
    // 0x8051976C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80519770: jal         0x80518CC8
    // 0x80519774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80518CC8(rdram, ctx);
        goto after_3;
    // 0x80519774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80519778: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x8051977C: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80519780: beql        $at, $zero, L_80519794
    if (ctx->r1 == 0) {
        // 0x80519784: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80519794;
    }
    goto skip_0;
    // 0x80519784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80519788: jal         0x805196C8
    // 0x8051978C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805196C8(rdram, ctx);
        goto after_4;
    // 0x8051978C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80519790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80519794:
    // 0x80519794: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80519798: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051979C: jr          $ra
    // 0x805197A0: nop

    return;
    // 0x805197A0: nop

;}
RECOMP_FUNC void func_8001AF00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AF00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001AF04: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001AF08: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001AF0C: jr          $ra
    // 0x8001AF10: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x8001AF10: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void func_804A0100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0100: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804A0104: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804A0108: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804A010C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804A0110: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804A0114: lui         $t7, 0x804A
    ctx->r15 = S32(RELOC_HI16(170, 0X2E0) << 16);
    // 0x804A0118: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804A011C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804A0120: addiu       $t7, $t7, 0x340
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(170, 0X2E0));
    // 0x804A0124: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804A0128: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804A012C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804A0130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A0134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804A0138: jal         0x804A0214
    // 0x804A013C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804A0214(rdram, ctx);
        goto after_0;
    // 0x804A013C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804A0140: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804A0144: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804A0148: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x804A014C: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x804A0150: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804A0154: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804A0158: jal         0x80048378
    // 0x804A015C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804A015C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    after_1:
    // 0x804A0160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A0164: jal         0x80045A34
    // 0x804A0168: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x804A0168: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x804A016C: lui         $t1, 0x804A
    ctx->r9 = S32(RELOC_HI16(170, 0X80) << 16);
    // 0x804A0170: addiu       $t1, $t1, 0xE0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(170, 0X80));
    // 0x804A0174: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804A0178: sw          $t1, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r9;
    // 0x804A017C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x804A0180: jal         0x80058958
    // 0x804A0184: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_80058958(rdram, ctx);
        goto after_3;
    // 0x804A0184: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_3:
    // 0x804A0188: beq         $v0, $zero, L_804A0200
    if (ctx->r2 == 0) {
        // 0x804A018C: lui         $t2, 0x8010
        ctx->r10 = S32(0X8010 << 16);
            goto L_804A0200;
    }
    // 0x804A018C: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x804A0190: lw          $t2, -0x7BC4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7BC4);
    // 0x804A0194: lw          $t3, 0x10C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10C);
    // 0x804A0198: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x804A019C: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x804A01A0: beql        $t5, $zero, L_804A0204
    if (ctx->r13 == 0) {
        // 0x804A01A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804A0204;
    }
    goto skip_0;
    // 0x804A01A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x804A01A8: jal         0x80056564
    // 0x804A01AC: nop

    func_80056564(rdram, ctx);
        goto after_4;
    // 0x804A01AC: nop

    after_4:
    // 0x804A01B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x804A01B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A01B8: beq         $v0, $zero, L_804A0200
    if (ctx->r2 == 0) {
        // 0x804A01BC: sw          $v0, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->r2;
            goto L_804A0200;
    }
    // 0x804A01BC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x804A01C0: jal         0x800457A0
    // 0x804A01C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_5;
    // 0x804A01C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x804A01C8: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A01CC: addiu       $t8, $zero, 0x29
    ctx->r24 = ADD32(0, 0X29);
    // 0x804A01D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804A01D4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x804A01D8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x804A01DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x804A01E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804A01E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804A01E8: jal         0x80056584
    // 0x804A01EC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_6;
    // 0x804A01EC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_6:
    // 0x804A01F0: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x804A01F4: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x804A01F8: addiu       $t0, $t0, 0x784C
    ctx->r8 = ADD32(ctx->r8, 0X784C);
    // 0x804A01FC: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
L_804A0200:
    // 0x804A0200: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804A0204:
    // 0x804A0204: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804A0208: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804A020C: jr          $ra
    // 0x804A0210: nop

    return;
    // 0x804A0210: nop

;}
RECOMP_FUNC void func_80527724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052772C: jal         0x805278CC
    // 0x80527730: nop

    func_805278CC(rdram, ctx);
        goto after_0;
    // 0x80527730: nop

    after_0:
    // 0x80527734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80527738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052773C: jr          $ra
    // 0x80527740: nop

    return;
    // 0x80527740: nop

;}
RECOMP_FUNC void func_8057F718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057F71C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F720: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8057F724: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8057F728: jal         0x80067BBC
    // 0x8057F72C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8057F72C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8057F730: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    // 0x8057F734: jal         0x80067818
    // 0x8057F738: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8057F738: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8057F73C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057F744: jr          $ra
    // 0x8057F748: nop

    return;
    // 0x8057F748: nop

;}
RECOMP_FUNC void func_80463898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463898: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8046389C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804638A0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804638A4: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x804638A8: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x804638AC: addiu       $t1, $zero, 0x5C0
    ctx->r9 = ADD32(0, 0X5C0);
    // 0x804638B0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x804638B4: addiu       $a3, $zero, -0xC
    ctx->r7 = ADD32(0, -0XC);
L_804638B8:
    // 0x804638B8: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    // 0x804638BC: sh          $v1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r3;
    // 0x804638C0: sh          $v1, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r3;
    // 0x804638C4: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x804638C8: sh          $a1, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r5;
    // 0x804638CC: sh          $a1, 0x32($a2)
    MEM_H(0X32, ctx->r6) = ctx->r5;
    // 0x804638D0: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    // 0x804638D4: sh          $v1, 0x42($a2)
    MEM_H(0X42, ctx->r6) = ctx->r3;
    // 0x804638D8: sh          $v1, 0x62($a2)
    MEM_H(0X62, ctx->r6) = ctx->r3;
    // 0x804638DC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x804638E0: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x804638E4: sh          $a1, 0x52($a2)
    MEM_H(0X52, ctx->r6) = ctx->r5;
    // 0x804638E8: sh          $a1, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r5;
    // 0x804638EC: sh          $a3, 0x40($a2)
    MEM_H(0X40, ctx->r6) = ctx->r7;
    // 0x804638F0: sh          $zero, 0x44($a2)
    MEM_H(0X44, ctx->r6) = 0;
    // 0x804638F4: sh          $zero, 0x46($a2)
    MEM_H(0X46, ctx->r6) = 0;
    // 0x804638F8: sh          $zero, 0x48($a2)
    MEM_H(0X48, ctx->r6) = 0;
    // 0x804638FC: sh          $zero, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = 0;
    // 0x80463900: sb          $t0, 0x4C($a2)
    MEM_B(0X4C, ctx->r6) = ctx->r8;
    // 0x80463904: sb          $t0, 0x4D($a2)
    MEM_B(0X4D, ctx->r6) = ctx->r8;
    // 0x80463908: sb          $t0, 0x4E($a2)
    MEM_B(0X4E, ctx->r6) = ctx->r8;
    // 0x8046390C: sb          $t0, 0x4F($a2)
    MEM_B(0X4F, ctx->r6) = ctx->r8;
    // 0x80463910: sh          $a3, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r7;
    // 0x80463914: sh          $zero, 0x54($a2)
    MEM_H(0X54, ctx->r6) = 0;
    // 0x80463918: sh          $zero, 0x56($a2)
    MEM_H(0X56, ctx->r6) = 0;
    // 0x8046391C: sh          $zero, 0x58($a2)
    MEM_H(0X58, ctx->r6) = 0;
    // 0x80463920: sh          $t1, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r9;
    // 0x80463924: sb          $t0, 0x5C($a2)
    MEM_B(0X5C, ctx->r6) = ctx->r8;
    // 0x80463928: sb          $t0, 0x5D($a2)
    MEM_B(0X5D, ctx->r6) = ctx->r8;
    // 0x8046392C: sb          $t0, 0x5E($a2)
    MEM_B(0X5E, ctx->r6) = ctx->r8;
    // 0x80463930: sb          $t0, 0x5F($a2)
    MEM_B(0X5F, ctx->r6) = ctx->r8;
    // 0x80463934: sh          $t2, 0x60($a2)
    MEM_H(0X60, ctx->r6) = ctx->r10;
    // 0x80463938: sh          $zero, 0x64($a2)
    MEM_H(0X64, ctx->r6) = 0;
    // 0x8046393C: sh          $zero, 0x66($a2)
    MEM_H(0X66, ctx->r6) = 0;
    // 0x80463940: sh          $t1, 0x68($a2)
    MEM_H(0X68, ctx->r6) = ctx->r9;
    // 0x80463944: sh          $zero, 0x6A($a2)
    MEM_H(0X6A, ctx->r6) = 0;
    // 0x80463948: sb          $t0, 0x6C($a2)
    MEM_B(0X6C, ctx->r6) = ctx->r8;
    // 0x8046394C: sb          $t0, 0x6D($a2)
    MEM_B(0X6D, ctx->r6) = ctx->r8;
    // 0x80463950: sb          $t0, 0x6E($a2)
    MEM_B(0X6E, ctx->r6) = ctx->r8;
    // 0x80463954: sb          $t0, 0x6F($a2)
    MEM_B(0X6F, ctx->r6) = ctx->r8;
    // 0x80463958: sh          $t2, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r10;
    // 0x8046395C: sh          $zero, 0x74($a2)
    MEM_H(0X74, ctx->r6) = 0;
    // 0x80463960: sh          $zero, 0x76($a2)
    MEM_H(0X76, ctx->r6) = 0;
    // 0x80463964: sh          $t1, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r9;
    // 0x80463968: sh          $t1, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r9;
    // 0x8046396C: sb          $t0, 0x7C($a2)
    MEM_B(0X7C, ctx->r6) = ctx->r8;
    // 0x80463970: sb          $t0, 0x7D($a2)
    MEM_B(0X7D, ctx->r6) = ctx->r8;
    // 0x80463974: sb          $t0, 0x7E($a2)
    MEM_B(0X7E, ctx->r6) = ctx->r8;
    // 0x80463978: sb          $t0, 0x7F($a2)
    MEM_B(0X7F, ctx->r6) = ctx->r8;
    // 0x8046397C: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    // 0x80463980: sh          $a3, -0x80($a2)
    MEM_H(-0X80, ctx->r6) = ctx->r7;
    // 0x80463984: sh          $zero, -0x7C($a2)
    MEM_H(-0X7C, ctx->r6) = 0;
    // 0x80463988: sh          $zero, -0x7A($a2)
    MEM_H(-0X7A, ctx->r6) = 0;
    // 0x8046398C: sh          $zero, -0x78($a2)
    MEM_H(-0X78, ctx->r6) = 0;
    // 0x80463990: sh          $zero, -0x76($a2)
    MEM_H(-0X76, ctx->r6) = 0;
    // 0x80463994: sb          $t0, -0x74($a2)
    MEM_B(-0X74, ctx->r6) = ctx->r8;
    // 0x80463998: sb          $t0, -0x73($a2)
    MEM_B(-0X73, ctx->r6) = ctx->r8;
    // 0x8046399C: sb          $t0, -0x72($a2)
    MEM_B(-0X72, ctx->r6) = ctx->r8;
    // 0x804639A0: sb          $t0, -0x71($a2)
    MEM_B(-0X71, ctx->r6) = ctx->r8;
    // 0x804639A4: sh          $a3, -0x70($a2)
    MEM_H(-0X70, ctx->r6) = ctx->r7;
    // 0x804639A8: sh          $zero, -0x6C($a2)
    MEM_H(-0X6C, ctx->r6) = 0;
    // 0x804639AC: sh          $zero, -0x6A($a2)
    MEM_H(-0X6A, ctx->r6) = 0;
    // 0x804639B0: sh          $zero, -0x68($a2)
    MEM_H(-0X68, ctx->r6) = 0;
    // 0x804639B4: sh          $t1, -0x66($a2)
    MEM_H(-0X66, ctx->r6) = ctx->r9;
    // 0x804639B8: sb          $t0, -0x64($a2)
    MEM_B(-0X64, ctx->r6) = ctx->r8;
    // 0x804639BC: sb          $t0, -0x63($a2)
    MEM_B(-0X63, ctx->r6) = ctx->r8;
    // 0x804639C0: sb          $t0, -0x62($a2)
    MEM_B(-0X62, ctx->r6) = ctx->r8;
    // 0x804639C4: sb          $t0, -0x61($a2)
    MEM_B(-0X61, ctx->r6) = ctx->r8;
    // 0x804639C8: sh          $t2, -0x60($a2)
    MEM_H(-0X60, ctx->r6) = ctx->r10;
    // 0x804639CC: sh          $zero, -0x5C($a2)
    MEM_H(-0X5C, ctx->r6) = 0;
    // 0x804639D0: sh          $zero, -0x5A($a2)
    MEM_H(-0X5A, ctx->r6) = 0;
    // 0x804639D4: sh          $t1, -0x58($a2)
    MEM_H(-0X58, ctx->r6) = ctx->r9;
    // 0x804639D8: sh          $zero, -0x56($a2)
    MEM_H(-0X56, ctx->r6) = 0;
    // 0x804639DC: sb          $t0, -0x54($a2)
    MEM_B(-0X54, ctx->r6) = ctx->r8;
    // 0x804639E0: sb          $t0, -0x53($a2)
    MEM_B(-0X53, ctx->r6) = ctx->r8;
    // 0x804639E4: sb          $t0, -0x52($a2)
    MEM_B(-0X52, ctx->r6) = ctx->r8;
    // 0x804639E8: sb          $t0, -0x51($a2)
    MEM_B(-0X51, ctx->r6) = ctx->r8;
    // 0x804639EC: sh          $t2, -0x50($a2)
    MEM_H(-0X50, ctx->r6) = ctx->r10;
    // 0x804639F0: sh          $zero, -0x4C($a2)
    MEM_H(-0X4C, ctx->r6) = 0;
    // 0x804639F4: sh          $zero, -0x4A($a2)
    MEM_H(-0X4A, ctx->r6) = 0;
    // 0x804639F8: sh          $t1, -0x48($a2)
    MEM_H(-0X48, ctx->r6) = ctx->r9;
    // 0x804639FC: sh          $t1, -0x46($a2)
    MEM_H(-0X46, ctx->r6) = ctx->r9;
    // 0x80463A00: sb          $t0, -0x44($a2)
    MEM_B(-0X44, ctx->r6) = ctx->r8;
    // 0x80463A04: sb          $t0, -0x43($a2)
    MEM_B(-0X43, ctx->r6) = ctx->r8;
    // 0x80463A08: sb          $t0, -0x42($a2)
    MEM_B(-0X42, ctx->r6) = ctx->r8;
    // 0x80463A0C: bne         $v0, $t3, L_804638B8
    if (ctx->r2 != ctx->r11) {
        // 0x80463A10: sb          $t0, -0x41($a2)
        MEM_B(-0X41, ctx->r6) = ctx->r8;
            goto L_804638B8;
    }
    // 0x80463A10: sb          $t0, -0x41($a2)
    MEM_B(-0X41, ctx->r6) = ctx->r8;
    // 0x80463A14: jr          $ra
    // 0x80463A18: nop

    return;
    // 0x80463A18: nop

;}
RECOMP_FUNC void func_80446528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446528: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044652C: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x80446530: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446534: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80446538: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x8044653C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446540: jr          $ra
    // 0x80446544: sw          $t7, 0x6CB0($at)
    MEM_W(0X6CB0, ctx->r1) = ctx->r15;
    return;
    // 0x80446544: sw          $t7, 0x6CB0($at)
    MEM_W(0X6CB0, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8046CD2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046CD2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8046CD30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8046CD34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8046CD38: jal         0x8004700C
    // 0x8046CD3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8046CD3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8046CD40: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8046CD44: jal         0x8046C850
    // 0x8046CD48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046C850(rdram, ctx);
        goto after_1;
    // 0x8046CD48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8046CD4C: beql        $v0, $zero, L_8046CD70
    if (ctx->r2 == 0) {
        // 0x8046CD50: lw          $t6, 0x12C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X12C);
            goto L_8046CD70;
    }
    goto skip_0;
    // 0x8046CD50: lw          $t6, 0x12C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X12C);
    skip_0:
    // 0x8046CD54: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8046CD58: jal         0x80067BBC
    // 0x8046CD5C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8046CD5C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8046CD60: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x8046CD64: jal         0x80067818
    // 0x8046CD68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8046CD68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8046CD6C: lw          $t6, 0x12C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X12C);
L_8046CD70:
    // 0x8046CD70: lui         $t9, 0x8047
    ctx->r25 = S32(RELOC_HI16(143, 0X139C) << 16);
    // 0x8046CD74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CD78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8046CD7C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8046CD80: lw          $t9, -0x2814($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(143, 0X139C));
    // 0x8046CD84: jalr        $t9
    // 0x8046CD88: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8046CD88: nop

    after_4:
    // 0x8046CD8C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8046CD90: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x8046CD94: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8046CD98: lw          $a3, 0x40($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X40);
    // 0x8046CD9C: lwc1        $f12, 0x3C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8046CDA0: lw          $a2, 0x40($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X40);
    // 0x8046CDA4: jal         0x8046C92C
    // 0x8046CDA8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8046C92C(rdram, ctx);
        goto after_5;
    // 0x8046CDA8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_5:
    // 0x8046CDAC: beq         $v0, $zero, L_8046CE20
    if (ctx->r2 == 0) {
        // 0x8046CDB0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8046CE20;
    }
    // 0x8046CDB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CDB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CDB8: jal         0x8046D3E8
    // 0x8046CDBC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8046D3E8(rdram, ctx);
        goto after_6;
    // 0x8046CDBC: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_6:
    // 0x8046CDC0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8046CDC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8046CDC8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8046CDCC: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8046CDD0: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x8046CDD4: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x8046CDD8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8046CDDC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8046CDE0: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x8046CDE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CDE8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8046CDEC: lw          $t9, 0x40($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X40);
    // 0x8046CDF0: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x8046CDF4: lui         $a3, 0xC180
    ctx->r7 = S32(0XC180 << 16);
    // 0x8046CDF8: jalr        $t9
    // 0x8046CDFC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8046CDFC: nop

    after_7:
    // 0x8046CE00: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8046CE04: jal         0x80067BBC
    // 0x8046CE08: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_8;
    // 0x8046CE08: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_8:
    // 0x8046CE0C: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x8046CE10: jal         0x80067818
    // 0x8046CE14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x8046CE14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x8046CE18: b           L_8046CE8C
    // 0x8046CE1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8046CE8C;
    // 0x8046CE1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8046CE20:
    // 0x8046CE20: lw          $t2, 0x1E0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1E0);
    // 0x8046CE24: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8046CE28: slti        $at, $t3, 0x64
    ctx->r1 = SIGNED(ctx->r11) < 0X64 ? 1 : 0;
    // 0x8046CE2C: bne         $at, $zero, L_8046CE88
    if (ctx->r1 != 0) {
        // 0x8046CE30: sw          $t3, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r11;
            goto L_8046CE88;
    }
    // 0x8046CE30: sw          $t3, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r11;
    // 0x8046CE34: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046CE38: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8046CE3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CE40: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8046CE44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046CE48: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8046CE4C: bne         $at, $zero, L_8046CE68
    if (ctx->r1 != 0) {
        // 0x8046CE50: nop
    
            goto L_8046CE68;
    }
    // 0x8046CE50: nop

    // 0x8046CE54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046CE58: jal         0x8046D3E8
    // 0x8046CE5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8046D3E8(rdram, ctx);
        goto after_10;
    // 0x8046CE5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8046CE60: b           L_8046CE74
    // 0x8046CE64: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
        goto L_8046CE74;
    // 0x8046CE64: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
L_8046CE68:
    // 0x8046CE68: jal         0x8046D3E8
    // 0x8046CE6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8046D3E8(rdram, ctx);
        goto after_11;
    // 0x8046CE6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x8046CE70: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
L_8046CE74:
    // 0x8046CE74: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8046CE78: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046CE7C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8046CE80: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8046CE84: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
L_8046CE88:
    // 0x8046CE88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8046CE8C:
    // 0x8046CE8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8046CE90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8046CE94: jr          $ra
    // 0x8046CE98: nop

    return;
    // 0x8046CE98: nop

;}
RECOMP_FUNC void func_800010EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800010EC: sra         $t6, $a2, 4
    ctx->r14 = S32(SIGNED(ctx->r6) >> 4);
    // 0x800010F0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800010F4: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800010F8: lui         $at, 0x1500
    ctx->r1 = S32(0X1500 << 16);
    // 0x800010FC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80001100: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x80001104: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80001108: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8000110C: jr          $ra
    // 0x80001110: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    return;
    // 0x80001110: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_8000C468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C468: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000C46C: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8000C470: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8000C474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000C478: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000C47C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000C480: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8000C484: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8000C488: lw          $t8, 0x50($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X50);
    // 0x8000C48C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000C490: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000C494: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8000C498: lbu         $a1, 0x5($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X5);
    // 0x8000C49C: jal         0x8000C19C
    // 0x8000C4A0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_8000C19C(rdram, ctx);
        goto after_0;
    // 0x8000C4A0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000C4A4: beq         $v0, $zero, L_8000C4B4
    if (ctx->r2 == 0) {
        // 0x8000C4A8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8000C4B4;
    }
    // 0x8000C4A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000C4AC: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
    // 0x8000C4B0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8000C4B4:
    // 0x8000C4B4: lw          $t0, 0x50($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X50);
    // 0x8000C4B8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x8000C4BC: lbu         $a1, 0x5($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X5);
    // 0x8000C4C0: jal         0x8000C19C
    // 0x8000C4C4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8000C19C(rdram, ctx);
        goto after_1;
    // 0x8000C4C4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_1:
    // 0x8000C4C8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8000C4CC: beq         $v0, $zero, L_8000C4DC
    if (ctx->r2 == 0) {
        // 0x8000C4D0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000C4DC;
    }
    // 0x8000C4D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000C4D4: lbu         $t1, 0x30($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X30);
    // 0x8000C4D8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_8000C4DC:
    // 0x8000C4DC: bne         $v1, $zero, L_8000C4F4
    if (ctx->r3 != 0) {
        // 0x8000C4E0: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_8000C4F4;
    }
    // 0x8000C4E0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000C4E4: bnel        $v0, $zero, L_8000C4F8
    if (ctx->r2 != 0) {
        // 0x8000C4E8: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_8000C4F8;
    }
    goto skip_0;
    // 0x8000C4E8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8000C4EC: b           L_8000C54C
    // 0x8000C4F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C54C;
    // 0x8000C4F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C4F4:
    // 0x8000C4F4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_8000C4F8:
    // 0x8000C4F8: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8000C4FC: beql        $at, $zero, L_8000C53C
    if (ctx->r1 == 0) {
        // 0x8000C500: sw          $s1, 0x48($v1)
        MEM_W(0X48, ctx->r3) = ctx->r17;
            goto L_8000C53C;
    }
    goto skip_1;
    // 0x8000C500: sw          $s1, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r17;
    skip_1:
    // 0x8000C504: jal         0x8000C170
    // 0x8000C508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000C170(rdram, ctx);
        goto after_2;
    // 0x8000C508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8000C50C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000C510: jal         0x8000C36C
    // 0x8000C514: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000C36C(rdram, ctx);
        goto after_3;
    // 0x8000C514: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8000C518: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8000C51C: jal         0x8000DB94
    // 0x8000C520: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000DB94(rdram, ctx);
        goto after_4;
    // 0x8000C520: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8000C524: lw          $t4, 0x50($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X50);
    // 0x8000C528: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8000C52C: lbu         $t5, 0x5($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X5);
    // 0x8000C530: b           L_8000C54C
    // 0x8000C534: sb          $t5, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r13;
        goto L_8000C54C;
    // 0x8000C534: sb          $t5, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r13;
    // 0x8000C538: sw          $s1, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r17;
L_8000C53C:
    // 0x8000C53C: lw          $t6, 0x50($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X50);
    // 0x8000C540: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000C544: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x8000C548: sb          $t7, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r15;
L_8000C54C:
    // 0x8000C54C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C550: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000C554: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000C558: jr          $ra
    // 0x8000C55C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000C55C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805AE3B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE3B4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE3B8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE3BC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE3C0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE3C4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE3C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE3CC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE3D0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE3D4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE3D8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE3DC: jr          $ra
    // 0x805AE3E0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE3E0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804B91DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B91DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B91E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B91E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B91E8: jal         0x8004700C
    // 0x804B91EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804B91EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804B91F0: beq         $v0, $zero, L_804B9234
    if (ctx->r2 == 0) {
        // 0x804B91F4: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_804B9234;
    }
    // 0x804B91F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804B91F8: jal         0x804B7E74
    // 0x804B91FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7E74(rdram, ctx);
        goto after_1;
    // 0x804B91FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804B9200: jal         0x804B8C58
    // 0x804B9204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B8C58(rdram, ctx);
        goto after_2;
    // 0x804B9204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804B9208: jal         0x804B8CB4
    // 0x804B920C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B8CB4(rdram, ctx);
        goto after_3;
    // 0x804B920C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804B9210: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804B9214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B9218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B921C: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x804B9220: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804B9224: bnel        $s0, $t7, L_804B9238
    if (ctx->r16 != ctx->r15) {
        // 0x804B9228: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804B9238;
    }
    goto skip_0;
    // 0x804B9228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804B922C: jal         0x804B9890
    // 0x804B9230: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804B9890(rdram, ctx);
        goto after_4;
    // 0x804B9230: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
L_804B9234:
    // 0x804B9234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B9238:
    // 0x804B9238: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B923C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B9240: jr          $ra
    // 0x804B9244: nop

    return;
    // 0x804B9244: nop

;}
RECOMP_FUNC void func_80041D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041D3C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80041D40: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80041D44: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80041D48: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80041D4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80041D50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80041D54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80041D58: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x80041D5C: lbu         $s0, 0x12C8($s4)
    ctx->r16 = MEM_BU(ctx->r20, 0X12C8);
    // 0x80041D60: beql        $s0, $zero, L_80041EA4
    if (ctx->r16 == 0) {
        // 0x80041D64: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80041EA4;
    }
    goto skip_0;
    // 0x80041D64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80041D68: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x80041D6C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80041D70: addiu       $s3, $zero, 0x18
    ctx->r19 = ADD32(0, 0X18);
    // 0x80041D74: bne         $a1, $v0, L_80041D90
    if (ctx->r5 != ctx->r2) {
        // 0x80041D78: addiu       $s2, $sp, 0x38
        ctx->r18 = ADD32(ctx->r29, 0X38);
            goto L_80041D90;
    }
    // 0x80041D78: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x80041D7C: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x80041D80: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80041D84: beq         $v1, $at, L_80041DA8
    if (ctx->r3 == ctx->r1) {
        // 0x80041D88: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80041DA8;
    }
    // 0x80041D88: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80041D8C: beq         $v1, $at, L_80041DA8
    if (ctx->r3 == ctx->r1) {
        // 0x80041D90: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80041DA8;
    }
L_80041D90:
    // 0x80041D90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80041D94: bne         $v0, $at, L_80041DB8
    if (ctx->r2 != ctx->r1) {
        // 0x80041D98: lui         $t8, 0x800A
        ctx->r24 = S32(0X800A << 16);
            goto L_80041DB8;
    }
    // 0x80041D98: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80041D9C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80041DA0: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80041DA4: bne         $t6, $at, L_80041DB8
    if (ctx->r14 != ctx->r1) {
        // 0x80041DA8: lui         $t7, 0x800A
        ctx->r15 = S32(0X800A << 16);
            goto L_80041DB8;
    }
L_80041DA8:
    // 0x80041DA8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80041DAC: addiu       $t7, $t7, -0xA2C
    ctx->r15 = ADD32(ctx->r15, -0XA2C);
    // 0x80041DB0: b           L_80041DC0
    // 0x80041DB4: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
        goto L_80041DC0;
    // 0x80041DB4: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_80041DB8:
    // 0x80041DB8: addiu       $t8, $t8, -0xA44
    ctx->r24 = ADD32(ctx->r24, -0XA44);
    // 0x80041DBC: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_80041DC0:
    // 0x80041DC0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80041DC4: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80041DC8: lhu         $t9, 0x12BE($s4)
    ctx->r25 = MEM_HU(ctx->r20, 0X12BE);
    // 0x80041DCC: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80041DD0: sh          $t9, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r25;
    // 0x80041DD4: lhu         $t0, 0x12BC($s4)
    ctx->r8 = MEM_HU(ctx->r20, 0X12BC);
    // 0x80041DD8: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x80041DDC: lwc1        $f4, 0x12CC($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X12CC);
    // 0x80041DE0: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80041DE4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80041DE8: lw          $t1, 0x34($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X34);
    // 0x80041DEC: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x80041DF0: lw          $t2, 0x38($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X38);
    // 0x80041DF4: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x80041DF8: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80041DFC: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80041E00: lbu         $t3, 0x18($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X18);
    // 0x80041E04: xor         $t4, $a1, $t3
    ctx->r12 = ctx->r5 ^ ctx->r11;
    // 0x80041E08: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80041E0C: sb          $t4, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r12;
    // 0x80041E10: lbu         $t7, 0x1F9($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X1F9);
    // 0x80041E14: lbu         $t5, 0x1FA($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X1FA);
    // 0x80041E18: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    // 0x80041E1C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80041E20: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80041E24: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80041E28: addu        $s1, $s1, $t9
    ctx->r17 = ADD32(ctx->r17, ctx->r25);
    // 0x80041E2C: beq         $s0, $zero, L_80041E94
    if (ctx->r16 == 0) {
        // 0x80041E30: lw          $s1, -0xA54($s1)
        ctx->r17 = MEM_W(ctx->r17, -0XA54);
            goto L_80041E94;
    }
    // 0x80041E30: lw          $s1, -0xA54($s1)
    ctx->r17 = MEM_W(ctx->r17, -0XA54);
L_80041E34:
    // 0x80041E34: lhu         $t1, 0x40($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X40);
    // 0x80041E38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80041E3C: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80041E40: mflo        $t2
    ctx->r10 = lo;
    // 0x80041E44: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x80041E48: lbu         $t4, 0x1202($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1202);
    // 0x80041E4C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80041E50: addu        $t7, $s1, $t5
    ctx->r15 = ADD32(ctx->r17, ctx->r13);
    // 0x80041E54: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80041E58: jalr        $t9
    // 0x80041E5C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80041E5C: nop

    after_0:
    // 0x80041E60: lhu         $t6, 0x40($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X40);
    // 0x80041E64: lhu         $t1, 0x42($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X42);
    // 0x80041E68: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80041E6C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80041E70: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80041E74: andi        $t0, $t8, 0x7
    ctx->r8 = ctx->r24 & 0X7;
    // 0x80041E78: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x80041E7C: addiu       $t2, $t1, 0xC
    ctx->r10 = ADD32(ctx->r9, 0XC);
    // 0x80041E80: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80041E84: sh          $t0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r8;
    // 0x80041E88: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80041E8C: bne         $s0, $zero, L_80041E34
    if (ctx->r16 != 0) {
        // 0x80041E90: sw          $t4, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r12;
            goto L_80041E34;
    }
    // 0x80041E90: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
L_80041E94:
    // 0x80041E94: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041E98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80041E9C: sb          $t5, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r13;
    // 0x80041EA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80041EA4:
    // 0x80041EA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80041EA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80041EAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80041EB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80041EB4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80041EB8: jr          $ra
    // 0x80041EBC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80041EBC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8078A4A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A4A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8078A4A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078A4A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8078A4AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8078A4B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8078A4B4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8078A4B8: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x8078A4BC: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8078A4C0: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8078A4C4: lw          $t8, 0x168($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X168);
    // 0x8078A4C8: lh          $t0, 0x144($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X144);
    // 0x8078A4CC: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x8078A4D0: lw          $t9, 0x88($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X88);
    // 0x8078A4D4: sll         $t1, $t0, 9
    ctx->r9 = S32(ctx->r8 << 9);
    // 0x8078A4D8: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8078A4DC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8078A4E0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8078A4E4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8078A4E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078A4EC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8078A4F0: jal         0x8078A2D0
    // 0x8078A4F4: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    func_8078A2D0(rdram, ctx);
        goto after_0;
    // 0x8078A4F4: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    after_0:
    // 0x8078A4F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078A4FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8078A500: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8078A504: jal         0x8007711C
    // 0x8078A508: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x8078A508: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8078A50C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8078A510: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8078A514: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078A518: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8078A51C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8078A520: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8078A524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8078A528: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8078A52C: jal         0x8078A3BC
    // 0x8078A530: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    func_8078A3BC(rdram, ctx);
        goto after_2;
    // 0x8078A530: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    after_2:
    // 0x8078A534: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078A538: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8078A53C: jal         0x8078A268
    // 0x8078A540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8078A268(rdram, ctx);
        goto after_3;
    // 0x8078A540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8078A544: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8078A548: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x8078A54C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078A550: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x8078A554: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8078A558: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8078A55C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8078A560: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8078A564: jal         0x8078A3BC
    // 0x8078A568: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    func_8078A3BC(rdram, ctx);
        goto after_4;
    // 0x8078A568: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    after_4:
    // 0x8078A56C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078A570: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8078A574: jal         0x8078A268
    // 0x8078A578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8078A268(rdram, ctx);
        goto after_5;
    // 0x8078A578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8078A57C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8078A580: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8078A584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078A588: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x8078A58C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8078A590: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8078A594: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8078A598: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8078A59C: jal         0x8078A3BC
    // 0x8078A5A0: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    func_8078A3BC(rdram, ctx);
        goto after_6;
    // 0x8078A5A0: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    after_6:
    // 0x8078A5A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8078A5A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8078A5AC: jal         0x8078A268
    // 0x8078A5B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8078A268(rdram, ctx);
        goto after_7;
    // 0x8078A5B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_7:
    // 0x8078A5B4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8078A5B8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8078A5BC: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
    // 0x8078A5C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078A5C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8078A5C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8078A5CC: jr          $ra
    // 0x8078A5D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8078A5D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807C6918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6918: jr          $ra
    // 0x807C691C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807C691C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80045B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80045B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045B6C: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x80045B70: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80045B74: bne         $t6, $at, L_80045B80
    if (ctx->r14 != ctx->r1) {
        // 0x80045B78: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_80045B80;
    }
    // 0x80045B78: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80045B7C: sw          $zero, -0x77D8($at)
    MEM_W(-0X77D8, ctx->r1) = 0;
L_80045B80:
    // 0x80045B80: lbu         $t7, 0x164($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X164);
    // 0x80045B84: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80045B88: beql        $t7, $at, L_80045BA0
    if (ctx->r15 == ctx->r1) {
        // 0x80045B8C: lw          $t8, 0x174($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X174);
            goto L_80045BA0;
    }
    goto skip_0;
    // 0x80045B8C: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    skip_0:
    // 0x80045B90: jal         0x80045414
    // 0x80045B94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045414(rdram, ctx);
        goto after_0;
    // 0x80045B94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80045B98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80045B9C: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
L_80045BA0:
    // 0x80045BA0: beql        $t8, $zero, L_80045BB8
    if (ctx->r24 == 0) {
        // 0x80045BA4: lw          $t9, 0x1F4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X1F4);
            goto L_80045BB8;
    }
    goto skip_1;
    // 0x80045BA4: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    skip_1:
    // 0x80045BA8: jal         0x800528C8
    // 0x80045BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800528C8(rdram, ctx);
        goto after_1;
    // 0x80045BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80045BB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80045BB4: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
L_80045BB8:
    // 0x80045BB8: beql        $t9, $zero, L_80045BCC
    if (ctx->r25 == 0) {
        // 0x80045BBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80045BCC;
    }
    goto skip_2;
    // 0x80045BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80045BC0: jal         0x8004597C
    // 0x80045BC4: nop

    func_8004597C(rdram, ctx);
        goto after_2;
    // 0x80045BC4: nop

    after_2:
    // 0x80045BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80045BCC:
    // 0x80045BCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045BD0: jr          $ra
    // 0x80045BD4: nop

    return;
    // 0x80045BD4: nop

;}
RECOMP_FUNC void func_8057C6EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C6EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8057C6F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057C6F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057C6F8: lui         $a0, 0x8058
    ctx->r4 = S32(RELOC_HI16(387, 0X1220) << 16);
    // 0x8057C6FC: lui         $a1, 0x4015
    ctx->r5 = S32(0X4015 << 16);
    // 0x8057C700: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8057C704: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8057C708: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8057C70C: addiu       $a0, $a0, -0x32D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(387, 0X1220));
    // 0x8057C710: jal         0x80046804
    // 0x8057C714: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x8057C714: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8057C718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057C71C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057C720: jr          $ra
    // 0x8057C724: nop

    return;
    // 0x8057C724: nop

;}
RECOMP_FUNC void func_806734B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806734B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806734B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806734BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806734C0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x806734C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806734C8: jal         0x8067302C
    // 0x806734CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8067302C(rdram, ctx);
        goto after_0;
    // 0x806734CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x806734D0: beq         $v0, $zero, L_806734F4
    if (ctx->r2 == 0) {
        // 0x806734D4: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_806734F4;
    }
    // 0x806734D4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806734D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806734DC: beq         $v0, $at, L_8067351C
    if (ctx->r2 == ctx->r1) {
        // 0x806734E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8067351C;
    }
    // 0x806734E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806734E4: beq         $v0, $at, L_80673534
    if (ctx->r2 == ctx->r1) {
        // 0x806734E8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80673534;
    }
    // 0x806734E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806734EC: b           L_80673554
    // 0x806734F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80673554;
    // 0x806734F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806734F4:
    // 0x806734F4: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C2C) << 16);
    // 0x806734F8: lwc1        $f0, 0x4C0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C2C));
    // 0x806734FC: lui         $a1, 0x8067
    ctx->r5 = S32(RELOC_HI16(529, 0X1970) << 16);
    // 0x80673500: addiu       $a1, $a1, 0x4950
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(529, 0X1970));
    // 0x80673504: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80673508: swc1        $f0, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f0.u32l;
    // 0x8067350C: jal         0x8067323C
    // 0x80673510: swc1        $f0, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f0.u32l;
    func_8067323C(rdram, ctx);
        goto after_1;
    // 0x80673510: swc1        $f0, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f0.u32l;
    after_1:
    // 0x80673514: b           L_80673554
    // 0x80673518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80673554;
    // 0x80673518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8067351C:
    // 0x8067351C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80673520: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80673524: nop

    // 0x80673528: swc1        $f0, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f0.u32l;
    // 0x8067352C: b           L_80673550
    // 0x80673530: swc1        $f0, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f0.u32l;
        goto L_80673550;
    // 0x80673530: swc1        $f0, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f0.u32l;
L_80673534:
    // 0x80673534: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C30) << 16);
    // 0x80673538: lwc1        $f0, 0x4C10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C30));
    // 0x8067353C: lui         $a1, 0x8067
    ctx->r5 = S32(RELOC_HI16(529, 0X1970) << 16);
    // 0x80673540: addiu       $a1, $a1, 0x4950
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(529, 0X1970));
    // 0x80673544: swc1        $f0, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f0.u32l;
    // 0x80673548: jal         0x8067323C
    // 0x8067354C: swc1        $f0, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f0.u32l;
    func_8067323C(rdram, ctx);
        goto after_2;
    // 0x8067354C: swc1        $f0, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f0.u32l;
    after_2:
L_80673550:
    // 0x80673550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80673554:
    // 0x80673554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80673558: jr          $ra
    // 0x8067355C: nop

    return;
    // 0x8067355C: nop

;}
RECOMP_FUNC void func_8070384C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070384C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80703850: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80703854: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80703858: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8070385C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80703860: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80703864: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80703868: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8070386C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80703870: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80703874: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80703878: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070387C: lw          $s7, 0x174($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X174);
    // 0x80703880: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80703884: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x80703888: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8070388C: beq         $v1, $zero, L_8070389C
    if (ctx->r3 == 0) {
        // 0x80703890: lw          $s0, 0x2C($t6)
        ctx->r16 = MEM_W(ctx->r14, 0X2C);
            goto L_8070389C;
    }
    // 0x80703890: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x80703894: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80703898: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
L_8070389C:
    // 0x8070389C: jal         0x80703480
    // 0x807038A0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_80703480(rdram, ctx);
        goto after_0;
    // 0x807038A0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_0:
    // 0x807038A4: beq         $s0, $zero, L_80703938
    if (ctx->r16 == 0) {
        // 0x807038A8: sw          $zero, 0x8($s7)
        MEM_W(0X8, ctx->r23) = 0;
            goto L_80703938;
    }
    // 0x807038A8: sw          $zero, 0x8($s7)
    MEM_W(0X8, ctx->r23) = 0;
    // 0x807038AC: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x807038B0: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x807038B4: lui         $s6, 0x8070
    ctx->r22 = S32(RELOC_HI16(709, 0X2630) << 16);
    // 0x807038B8: addiu       $s6, $s6, 0x5AA0
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(709, 0X2630));
    // 0x807038BC: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x807038C0: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x807038C4: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
    // 0x807038C8: addiu       $s3, $zero, 0x38
    ctx->r19 = ADD32(0, 0X38);
    // 0x807038CC: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x807038D0: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
L_807038D4:
    // 0x807038D4: addiu       $s1, $s1, -0x18
    ctx->r17 = ADD32(ctx->r17, -0X18);
    // 0x807038D8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x807038DC: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x807038E0: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x807038E4: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x807038E8: beq         $v1, $zero, L_80703930
    if (ctx->r3 == 0) {
        // 0x807038EC: nop
    
            goto L_80703930;
    }
    // 0x807038EC: nop

    // 0x807038F0: beq         $s2, $v1, L_80703930
    if (ctx->r18 == ctx->r3) {
        // 0x807038F4: nop
    
            goto L_80703930;
    }
    // 0x807038F4: nop

    // 0x807038F8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x807038FC: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x80703900: beq         $s3, $v1, L_80703930
    if (ctx->r19 == ctx->r3) {
        // 0x80703904: nop
    
            goto L_80703930;
    }
    // 0x80703904: nop

    // 0x80703908: beq         $s4, $v1, L_80703930
    if (ctx->r20 == ctx->r3) {
        // 0x8070390C: nop
    
            goto L_80703930;
    }
    // 0x8070390C: nop

    // 0x80703910: beq         $s0, $s5, L_80703930
    if (ctx->r16 == ctx->r21) {
        // 0x80703914: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_80703930;
    }
    // 0x80703914: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80703918: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x8070391C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80703920: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80703924: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80703928: jalr        $t9
    // 0x8070392C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8070392C: nop

    after_1:
L_80703930:
    // 0x80703930: bnel        $s0, $zero, L_807038D4
    if (ctx->r16 != 0) {
        // 0x80703934: lw          $t8, 0x0($s7)
        ctx->r24 = MEM_W(ctx->r23, 0X0);
            goto L_807038D4;
    }
    goto skip_0;
    // 0x80703934: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    skip_0:
L_80703938:
    // 0x80703938: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8070393C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80703940: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80703944: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80703948: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8070394C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80703950: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80703954: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80703958: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8070395C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80703960: jr          $ra
    // 0x80703964: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80703964: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80008304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000830C: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x80008310: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80008314: beql        $t6, $zero, L_8000836C
    if (ctx->r14 == 0) {
        // 0x80008318: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000836C;
    }
    goto skip_0;
    // 0x80008318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8000831C: lbu         $a0, 0x1($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1);
    // 0x80008320: lbu         $a1, 0x2($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X2);
    // 0x80008324: jal         0x80008298
    // 0x80008328: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80008298(rdram, ctx);
        goto after_0;
    // 0x80008328: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000832C: beq         $v0, $zero, L_80008368
    if (ctx->r2 == 0) {
        // 0x80008330: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80008368;
    }
    // 0x80008330: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80008334: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80008338: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x8000833C: sw          $t8, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r24;
    // 0x80008340: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80008344: sw          $t7, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r15;
    // 0x80008348: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8000834C: sw          $t8, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r24;
    // 0x80008350: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80008354: sw          $t7, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r15;
    // 0x80008358: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8000835C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80008360: andi        $t1, $t0, 0xFFF3
    ctx->r9 = ctx->r8 & 0XFFF3;
    // 0x80008364: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_80008368:
    // 0x80008368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000836C:
    // 0x8000836C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80008370: jr          $ra
    // 0x80008374: nop

    return;
    // 0x80008374: nop

;}
RECOMP_FUNC void func_805DC750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC750: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805DC754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DC758: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DC75C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x805DC760: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DC764: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x805DC768: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x805DC76C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x805DC770: addu        $v0, $t6, $t1
    ctx->r2 = ADD32(ctx->r14, ctx->r9);
    // 0x805DC774: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x805DC778: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x805DC77C: addu        $t8, $a0, $t0
    ctx->r24 = ADD32(ctx->r4, ctx->r8);
    // 0x805DC780: lwc1        $f0, 0x3C($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X3C);
    // 0x805DC784: subu        $t2, $v1, $a2
    ctx->r10 = SUB32(ctx->r3, ctx->r6);
    // 0x805DC788: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x805DC78C: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x805DC790: addu        $v0, $s0, $t0
    ctx->r2 = ADD32(ctx->r16, ctx->r8);
    // 0x805DC794: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805DC798: addu        $t5, $a2, $v1
    ctx->r13 = ADD32(ctx->r6, ctx->r3);
    // 0x805DC79C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x805DC7A0: nop

    // 0x805DC7A4: bc1fl       L_805DC830
    if (!c1cs) {
        // 0x805DC7A8: mtc1        $t5, $f4
        ctx->f4.u32l = ctx->r13;
            goto L_805DC830;
    }
    goto skip_0;
    // 0x805DC7A8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    skip_0:
    // 0x805DC7AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x805DC7B0: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805DC7B4: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x805DC7B8: nop

    // 0x805DC7BC: bc1fl       L_805DC830
    if (!c1cs) {
        // 0x805DC7C0: mtc1        $t5, $f4
        ctx->f4.u32l = ctx->r13;
            goto L_805DC830;
    }
    goto skip_1;
    // 0x805DC7C0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    skip_1:
    // 0x805DC7C4: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    // 0x805DC7C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DC7CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805DC7D0: bnel        $a3, $zero, L_805DC7FC
    if (ctx->r7 != 0) {
        // 0x805DC7D4: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_805DC7FC;
    }
    goto skip_2;
    // 0x805DC7D4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    skip_2:
    // 0x805DC7D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DC7DC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805DC7E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x805DC7E4: jal         0x805DD234
    // 0x805DC7E8: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_805DD234(rdram, ctx);
        goto after_0;
    // 0x805DC7E8: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_0:
    // 0x805DC7EC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805DC7F0: b           L_805DC80C
    // 0x805DC7F4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
        goto L_805DC80C;
    // 0x805DC7F4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x805DC7F8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_805DC7FC:
    // 0x805DC7FC: jal         0x805DD234
    // 0x805DC800: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_805DD234(rdram, ctx);
        goto after_1;
    // 0x805DC800: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_1:
    // 0x805DC804: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805DC808: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_805DC80C:
    // 0x805DC80C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x805DC810: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X28C0) << 16);
    // 0x805DC814: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x805DC818: lwc1        $f16, 0x10($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X10);
    // 0x805DC81C: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x805DC820: lwc1        $f18, -0x2A40($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X28C0));
    // 0x805DC824: b           L_805DC8D0
    // 0x805DC828: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
        goto L_805DC8D0;
    // 0x805DC828: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x805DC82C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
L_805DC830:
    // 0x805DC830: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x805DC834: addu        $v0, $s0, $t0
    ctx->r2 = ADD32(ctx->r16, ctx->r8);
    // 0x805DC838: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805DC83C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x805DC840: nop

    // 0x805DC844: bc1fl       L_805DC8D4
    if (!c1cs) {
        // 0x805DC848: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DC8D4;
    }
    goto skip_3;
    // 0x805DC848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x805DC84C: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805DC850: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x805DC854: nop

    // 0x805DC858: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x805DC85C: nop

    // 0x805DC860: bc1fl       L_805DC8D4
    if (!c1cs) {
        // 0x805DC864: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DC8D4;
    }
    goto skip_4;
    // 0x805DC864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x805DC868: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    // 0x805DC86C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DC870: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805DC874: bnel        $a3, $zero, L_805DC8A0
    if (ctx->r7 != 0) {
        // 0x805DC878: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_805DC8A0;
    }
    goto skip_5;
    // 0x805DC878: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    skip_5:
    // 0x805DC87C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DC880: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805DC884: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x805DC888: jal         0x805DD234
    // 0x805DC88C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_805DD234(rdram, ctx);
        goto after_2;
    // 0x805DC88C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_2:
    // 0x805DC890: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805DC894: b           L_805DC8B0
    // 0x805DC898: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
        goto L_805DC8B0;
    // 0x805DC898: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x805DC89C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
L_805DC8A0:
    // 0x805DC8A0: jal         0x805DD234
    // 0x805DC8A4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_805DD234(rdram, ctx);
        goto after_3;
    // 0x805DC8A4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_3:
    // 0x805DC8A8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805DC8AC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_805DC8B0:
    // 0x805DC8B0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x805DC8B4: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X28C4) << 16);
    // 0x805DC8B8: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x805DC8BC: lwc1        $f16, 0x10($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X10);
    // 0x805DC8C0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x805DC8C4: swc1        $f18, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
    // 0x805DC8C8: lwc1        $f4, -0x2A3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X28C4));
    // 0x805DC8CC: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
L_805DC8D0:
    // 0x805DC8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805DC8D4:
    // 0x805DC8D4: jal         0x805DAE20
    // 0x805DC8D8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_805DAE20(rdram, ctx);
        goto after_4;
    // 0x805DC8D8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x805DC8DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805DC8E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DC8E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805DC8E8: jr          $ra
    // 0x805DC8EC: nop

    return;
    // 0x805DC8EC: nop

;}
RECOMP_FUNC void func_8002BC1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BC1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002BC20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BC24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002BC28: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002BC2C: jal         0x8002AF54
    // 0x8002BC30: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8002AF54(rdram, ctx);
        goto after_0;
    // 0x8002BC30: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8002BC34: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002BC38: addiu       $a1, $a1, -0x39E0
    ctx->r5 = ADD32(ctx->r5, -0X39E0);
    // 0x8002BC3C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002BC40: jal         0x80028118
    // 0x8002BC44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80028118(rdram, ctx);
        goto after_1;
    // 0x8002BC44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8002BC48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002BC4C: jal         0x8002AFDC
    // 0x8002BC50: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002AFDC(rdram, ctx);
        goto after_2;
    // 0x8002BC50: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8002BC54: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002BC58: sw          $zero, 0x130($t8)
    MEM_W(0X130, ctx->r24) = 0;
    // 0x8002BC5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BC60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002BC64: jr          $ra
    // 0x8002BC68: nop

    return;
    // 0x8002BC68: nop

;}
RECOMP_FUNC void func_807BBEFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BBEFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BBF00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BBF04: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BBF08: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x807BBF0C: bnel        $t6, $zero, L_807BBF34
    if (ctx->r14 != 0) {
        // 0x807BBF10: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_807BBF34;
    }
    goto skip_0;
    // 0x807BBF10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x807BBF14: jal         0x80045A34
    // 0x807BBF18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807BBF18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807BBF1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807BBF20: bne         $v0, $zero, L_807BBF30
    if (ctx->r2 != 0) {
        // 0x807BBF24: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_807BBF30;
    }
    // 0x807BBF24: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807BBF28: b           L_807BBF34
    // 0x807BBF2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807BBF34;
    // 0x807BBF2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807BBF30:
    // 0x807BBF30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807BBF34:
    // 0x807BBF34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BBF38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BBF3C: jr          $ra
    // 0x807BBF40: nop

    return;
    // 0x807BBF40: nop

;}
RECOMP_FUNC void func_804C5B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5B80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804C5B84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804C5B88: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804C5B8C: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x804C5B90: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x804C5B94: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(215, 0X434) << 16);
    // 0x804C5B98: addiu       $t6, $v0, 0xD
    ctx->r14 = ADD32(ctx->r2, 0XD);
    // 0x804C5B9C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x804C5BA0: sw          $t7, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r15;
    // 0x804C5BA4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804C5BA8: addiu       $t8, $t8, 0x5E44
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(215, 0X434));
    // 0x804C5BAC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x804C5BB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C5BB4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804C5BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C5BBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C5BC0: jal         0x804C5C54
    // 0x804C5BC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804C5C54(rdram, ctx);
        goto after_0;
    // 0x804C5BC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804C5BC8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804C5BCC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804C5BD0: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x804C5BD4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804C5BD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804C5BDC: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804C5BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C5BE4: jal         0x80045A34
    // 0x804C5BE8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x804C5BE8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_1:
    // 0x804C5BEC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804C5BF0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x804C5BF4: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(215, 0X43C) << 16);
    // 0x804C5BF8: addiu       $t2, $t2, 0x5E4C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(215, 0X43C));
    // 0x804C5BFC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x804C5C00: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x804C5C04: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x804C5C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C5C0C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x804C5C10: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x804C5C14: jal         0x80054530
    // 0x804C5C18: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_80054530(rdram, ctx);
        goto after_2;
    // 0x804C5C18: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_2:
    // 0x804C5C1C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x804C5C20: lui         $t4, 0x804C
    ctx->r12 = S32(RELOC_HI16(215, 0X10C) << 16);
    // 0x804C5C24: addiu       $t4, $t4, 0x5B1C
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(215, 0X10C));
    // 0x804C5C28: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x804C5C2C: lw          $t6, 0x16C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X16C);
    // 0x804C5C30: lui         $t5, 0x804C
    ctx->r13 = S32(RELOC_HI16(215, 0X12C) << 16);
    // 0x804C5C34: sw          $t4, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r12;
    // 0x804C5C38: addiu       $t5, $t5, 0x5B3C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(215, 0X12C));
    // 0x804C5C3C: sw          $t5, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r13;
    // 0x804C5C40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804C5C44: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804C5C48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804C5C4C: jr          $ra
    // 0x804C5C50: nop

    return;
    // 0x804C5C50: nop

;}
RECOMP_FUNC void func_80048BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048BD8: sw          $a1, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r5;
    // 0x80048BDC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80048BE0: jr          $ra
    // 0x80048BE4: sw          $t7, 0x1DC($a0)
    MEM_W(0X1DC, ctx->r4) = ctx->r15;
    return;
    // 0x80048BE4: sw          $t7, 0x1DC($a0)
    MEM_W(0X1DC, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_805A5480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A5484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A5488: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A548C: beql        $v0, $zero, L_805A54A0
    if (ctx->r2 == 0) {
        // 0x805A5490: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A54A0;
    }
    goto skip_0;
    // 0x805A5490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A5494: jal         0x800577D8
    // 0x805A5498: lw          $a0, 0x268($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X268);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x805A5498: lw          $a0, 0x268($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X268);
    after_0:
    // 0x805A549C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A54A0:
    // 0x805A54A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A54A4: jr          $ra
    // 0x805A54A8: nop

    return;
    // 0x805A54A8: nop

;}
RECOMP_FUNC void func_807B8BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8BF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B8BF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807B8BFC: bne         $a2, $at, L_807B8C30
    if (ctx->r6 != ctx->r1) {
        // 0x807B8C00: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_807B8C30;
    }
    // 0x807B8C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B8C04: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x807B8C08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B8C0C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x807B8C10: bgez        $t7, L_807B8C20
    if (SIGNED(ctx->r15) >= 0) {
        // 0x807B8C14: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_807B8C20;
    }
    // 0x807B8C14: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x807B8C18: b           L_807B8C68
    // 0x807B8C1C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_807B8C68;
    // 0x807B8C1C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_807B8C20:
    // 0x807B8C20: jal         0x80067818
    // 0x807B8C24: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x807B8C24: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    after_0:
    // 0x807B8C28: b           L_807B8C6C
    // 0x807B8C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807B8C6C;
    // 0x807B8C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B8C30:
    // 0x807B8C30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807B8C34: bnel        $a2, $at, L_807B8C6C
    if (ctx->r6 != ctx->r1) {
        // 0x807B8C38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807B8C6C;
    }
    goto skip_0;
    // 0x807B8C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807B8C3C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x807B8C40: addiu       $t2, $a1, -0x1
    ctx->r10 = ADD32(ctx->r5, -0X1);
    // 0x807B8C44: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x807B8C48: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x807B8C4C: bne         $at, $zero, L_807B8C5C
    if (ctx->r1 != 0) {
        // 0x807B8C50: sw          $t0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r8;
            goto L_807B8C5C;
    }
    // 0x807B8C50: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x807B8C54: b           L_807B8C68
    // 0x807B8C58: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
        goto L_807B8C68;
    // 0x807B8C58: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_807B8C5C:
    // 0x807B8C5C: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    // 0x807B8C60: jal         0x80067818
    // 0x807B8C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807B8C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_807B8C68:
    // 0x807B8C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B8C6C:
    // 0x807B8C6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B8C70: jr          $ra
    // 0x807B8C74: nop

    return;
    // 0x807B8C74: nop

;}
RECOMP_FUNC void func_8007A900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A900: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x8007A904: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8007A908: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8007A90C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8007A910: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8007A914: lwc1        $f20, 0x16C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X16C);
    // 0x8007A918: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8007A91C: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8007A920: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8007A924: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8007A928: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8007A92C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8007A930: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8007A934: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8007A938: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8007A93C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8007A940: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8007A944: sw          $a0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r4;
    // 0x8007A948: sw          $a1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r5;
    // 0x8007A94C: sw          $a2, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r6;
    // 0x8007A950: sw          $a3, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r7;
    // 0x8007A954: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x8007A958: lwc1        $f0, 0x170($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8007A95C: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8007A960: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8007A964: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007A968: sw          $t7, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r15;
    // 0x8007A96C: jal         0x80081FE0
    // 0x8007A970: swc1        $f0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f0.u32l;
    floorf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A970: swc1        $f0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8007A974: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007A978: lwc1        $f6, 0x170($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8007A97C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8007A980: div.s       $f12, $f22, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8007A984: jal         0x80081FE0
    // 0x8007A988: sw          $t9, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r25;
    floorf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A988: sw          $t9, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r25;
    after_1:
    // 0x8007A98C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8007A990: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007A994: lw          $t5, 0x15C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X15C);
    // 0x8007A998: lwc1        $f16, 0x170($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X170);
    // 0x8007A99C: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x8007A9A0: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x8007A9A4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8007A9A8: bc1f        L_8007AA1C
    if (!c1cs) {
        // 0x8007A9AC: sw          $t4, 0x11C($sp)
        MEM_W(0X11C, ctx->r29) = ctx->r12;
            goto L_8007AA1C;
    }
    // 0x8007A9AC: sw          $t4, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r12;
    // 0x8007A9B0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8007A9B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007A9B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8007A9BC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007A9C0: lwc1        $f2, 0x164($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8007A9C4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8007A9C8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8007A9CC: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x8007A9D0: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x8007A9D4: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8007A9D8: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x8007A9DC: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8007A9E0: mul.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8007A9E4: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007A9E8: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007A9EC: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8007A9F0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8007A9F4: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8007A9F8: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8007A9FC: nop

    // 0x8007AA00: sw          $t8, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r24;
    // 0x8007AA04: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8007AA08: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x8007AA0C: sw          $t8, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r24;
    // 0x8007AA10: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8007AA14: b           L_8007AA94
    // 0x8007AA18: sw          $t3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r11;
        goto L_8007AA94;
    // 0x8007AA18: sw          $t3, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r11;
L_8007AA1C:
    // 0x8007AA1C: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x8007AA20: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007AA24: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8007AA28: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x8007AA2C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8007AA30: lwc1        $f2, 0x164($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X164);
    // 0x8007AA34: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8007AA38: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007AA3C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8007AA40: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x8007AA44: lw          $t6, 0x158($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X158);
    // 0x8007AA48: addu        $t3, $t9, $t8
    ctx->r11 = ADD32(ctx->r25, ctx->r24);
    // 0x8007AA4C: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8007AA50: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8007AA54: mul.s       $f0, $f18, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8007AA58: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007AA5C: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007AA60: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8007AA64: nop

    // 0x8007AA68: mul.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8007AA6C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8007AA70: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8007AA74: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8007AA78: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8007AA7C: sw          $t5, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r13;
    // 0x8007AA80: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x8007AA84: sw          $t7, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r15;
    // 0x8007AA88: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8007AA8C: addiu       $t9, $t7, 0x10
    ctx->r25 = ADD32(ctx->r15, 0X10);
    // 0x8007AA90: sw          $t9, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r25;
L_8007AA94:
    // 0x8007AA94: lw          $s6, 0x160($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X160);
    // 0x8007AA98: lwc1        $f10, 0x128($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8007AA9C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8007AAA0: addiu       $t8, $s6, -0x1
    ctx->r24 = ADD32(ctx->r22, -0X1);
    // 0x8007AAA4: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x8007AAA8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8007AAAC: lwc1        $f22, 0x168($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8007AAB0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8007AAB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007AAB8: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
    // 0x8007AABC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007AAC0: nop

    // 0x8007AAC4: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8007AAC8: bc1f        L_8007AEC4
    if (!c1cs) {
        // 0x8007AACC: sub.s       $f22, $f22, $f4
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f4.fl;
            goto L_8007AEC4;
    }
    // 0x8007AACC: sub.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f4.fl;
    // 0x8007AAD0: lw          $t4, 0x178($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X178);
    // 0x8007AAD4: lw          $t5, 0x174($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X174);
    // 0x8007AAD8: lw          $t7, 0x11C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X11C);
    // 0x8007AADC: addiu       $t9, $s6, -0x1
    ctx->r25 = ADD32(ctx->r22, -0X1);
    // 0x8007AAE0: div         $zero, $t4, $t5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r13)));
    // 0x8007AAE4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8007AAE8: bne         $t5, $zero, L_8007AAF4
    if (ctx->r13 != 0) {
        // 0x8007AAEC: nop
    
            goto L_8007AAF4;
    }
    // 0x8007AAEC: nop

    // 0x8007AAF0: break       7
    do_break(2147986160);
L_8007AAF4:
    // 0x8007AAF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007AAF8: bne         $t5, $at, L_8007AB0C
    if (ctx->r13 != ctx->r1) {
        // 0x8007AAFC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007AB0C;
    }
    // 0x8007AAFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007AB00: bne         $t4, $at, L_8007AB0C
    if (ctx->r12 != ctx->r1) {
        // 0x8007AB04: nop
    
            goto L_8007AB0C;
    }
    // 0x8007AB04: nop

    // 0x8007AB08: break       6
    do_break(2147986184);
L_8007AB0C:
    // 0x8007AB0C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007AB10: lui         $at, 0x3A80
    ctx->r1 = S32(0X3A80 << 16);
    // 0x8007AB14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007AB18: mflo        $t6
    ctx->r14 = lo;
    // 0x8007AB1C: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x8007AB20: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    // 0x8007AB24: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007AB28: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8007AB2C: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
L_8007AB30:
    // 0x8007AB30: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8007AB34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007AB38: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007AB3C: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x8007AB40: or          $s5, $s6, $zero
    ctx->r21 = ctx->r22 | 0;
    // 0x8007AB44: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007AB48: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8007AB4C: mfc1        $fp, $f8
    ctx->r30 = (int32_t)ctx->f8.u32l;
    // 0x8007AB50: nop

    // 0x8007AB54: sra         $s3, $fp, 5
    ctx->r19 = S32(SIGNED(ctx->r30) >> 5);
    // 0x8007AB58: addu        $v0, $s3, $t3
    ctx->r2 = ADD32(ctx->r19, ctx->r11);
    // 0x8007AB5C: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8007AB60: beq         $at, $zero, L_8007AB70
    if (ctx->r1 == 0) {
        // 0x8007AB64: nop
    
            goto L_8007AB70;
    }
    // 0x8007AB64: nop

    // 0x8007AB68: b           L_8007AB70
    // 0x8007AB6C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
        goto L_8007AB70;
    // 0x8007AB6C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_8007AB70:
    // 0x8007AB70: addiu       $s7, $s5, -0x1
    ctx->r23 = ADD32(ctx->r21, -0X1);
    // 0x8007AB74: mtc1        $s7, $f10
    ctx->f10.u32l = ctx->r23;
    // 0x8007AB78: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8007AB7C: swc1        $f2, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f2.u32l;
    // 0x8007AB80: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007AB84: div.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007AB88: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8007AB8C: jal         0x80081FE0
    // 0x8007AB90: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    floorf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007AB90: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x8007AB94: lwc1        $f2, 0x134($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8007AB98: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8007AB9C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007ABA0: nop

    // 0x8007ABA4: bc1fl       L_8007ABC0
    if (!c1cs) {
        // 0x8007ABA8: add.s       $f4, $f22, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f20.fl;
            goto L_8007ABC0;
    }
    goto skip_0;
    // 0x8007ABA8: add.s       $f4, $f22, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f20.fl;
    skip_0:
    // 0x8007ABAC: jal         0x80081FE0
    // 0x8007ABB0: swc1        $f2, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f2.u32l;
    floorf_recomp(rdram, ctx);
        goto after_3;
    // 0x8007ABB0: swc1        $f2, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8007ABB4: lwc1        $f2, 0x134($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8007ABB8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007ABBC: add.s       $f4, $f22, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f20.fl;
L_8007ABC0:
    // 0x8007ABC0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8007ABC4: lw          $v0, -0x7AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7AF0);
    // 0x8007ABC8: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8007ABCC: lhu         $t5, 0x1A($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X1A);
    // 0x8007ABD0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8007ABD4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8007ABD8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8007ABDC: nop

    // 0x8007ABE0: slt         $at, $t0, $t6
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007ABE4: bnel        $at, $zero, L_8007AEAC
    if (ctx->r1 != 0) {
        // 0x8007ABE8: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_8007AEAC;
    }
    goto skip_1;
    // 0x8007ABE8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_1:
    // 0x8007ABEC: add.s       $f10, $f22, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f2.fl;
    // 0x8007ABF0: lhu         $t9, 0x1E($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1E);
    // 0x8007ABF4: lw          $v0, 0x150($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X150);
    // 0x8007ABF8: lw          $a2, 0x148($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X148);
    // 0x8007ABFC: mul.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8007AC00: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007AC04: lw          $a3, 0x14C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X14C);
    // 0x8007AC08: addiu       $a0, $sp, 0x13C
    ctx->r4 = ADD32(ctx->r29, 0X13C);
    // 0x8007AC0C: lw          $t3, 0x174($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X174);
    // 0x8007AC10: lw          $t5, 0x144($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X144);
    // 0x8007AC14: subu        $t6, $s5, $s3
    ctx->r14 = SUB32(ctx->r21, ctx->r19);
    // 0x8007AC18: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8007AC1C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8007AC20: nop

    // 0x8007AC24: slt         $at, $t8, $t2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007AC28: bnel        $at, $zero, L_8007AEAC
    if (ctx->r1 != 0) {
        // 0x8007AC2C: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_8007AEAC;
    }
    goto skip_2;
    // 0x8007AC2C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    skip_2:
    // 0x8007AC30: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AC34: lw          $t3, 0x11C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X11C);
    // 0x8007AC38: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x8007AC3C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8007AC40: andi        $t6, $a2, 0x7
    ctx->r14 = ctx->r6 & 0X7;
    // 0x8007AC44: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8007AC48: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x8007AC4C: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x8007AC50: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007AC54: lw          $s2, 0x15C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X15C);
    // 0x8007AC58: mflo        $t4
    ctx->r12 = lo;
    // 0x8007AC5C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x8007AC60: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8007AC64: or          $t5, $t8, $t4
    ctx->r13 = ctx->r24 | ctx->r12;
    // 0x8007AC68: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x8007AC6C: sllv        $t5, $v0, $a3
    ctx->r13 = S32(ctx->r2 << (ctx->r7 & 31));
    // 0x8007AC70: andi        $t3, $a3, 0x3
    ctx->r11 = ctx->r7 & 0X3;
    // 0x8007AC74: sll         $t8, $t3, 19
    ctx->r24 = S32(ctx->r11 << 19);
    // 0x8007AC78: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8007AC7C: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8007AC80: addiu       $t3, $t7, 0x7
    ctx->r11 = ADD32(ctx->r15, 0X7);
    // 0x8007AC84: or          $t4, $t9, $t8
    ctx->r12 = ctx->r25 | ctx->r24;
    // 0x8007AC88: sra         $t9, $t3, 3
    ctx->r25 = S32(SIGNED(ctx->r11) >> 3);
    // 0x8007AC8C: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8007AC90: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x8007AC94: andi        $s2, $s2, 0xFFF
    ctx->r18 = ctx->r18 & 0XFFF;
    // 0x8007AC98: sll         $t5, $t8, 9
    ctx->r13 = S32(ctx->r24 << 9);
    // 0x8007AC9C: or          $s1, $t4, $t5
    ctx->r17 = ctx->r12 | ctx->r13;
    // 0x8007ACA0: sll         $s2, $s2, 12
    ctx->r18 = S32(ctx->r18 << 12);
    // 0x8007ACA4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007ACA8: lh          $s0, 0xFE($sp)
    ctx->r16 = MEM_H(ctx->r29, 0XFE);
    // 0x8007ACAC: lh          $s4, 0x106($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X106);
    // 0x8007ACB0: sw          $t0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r8;
    // 0x8007ACB4: jal         0x80077038
    // 0x8007ACB8: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    func_80077038(rdram, ctx);
        goto after_4;
    // 0x8007ACB8: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    after_4:
    // 0x8007ACBC: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x8007ACC0: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x8007ACC4: lw          $t6, 0x13C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X13C);
    // 0x8007ACC8: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x8007ACCC: ori         $t3, $t3, 0x200
    ctx->r11 = ctx->r11 | 0X200;
    // 0x8007ACD0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007ACD4: sw          $t7, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r15;
    // 0x8007ACD8: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x8007ACDC: sw          $s1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r17;
    // 0x8007ACE0: lw          $v1, 0x13C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X13C);
    // 0x8007ACE4: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x8007ACE8: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x8007ACEC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8007ACF0: sw          $t8, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r24;
    // 0x8007ACF4: andi        $t3, $t7, 0xFFF
    ctx->r11 = ctx->r15 & 0XFFF;
    // 0x8007ACF8: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x8007ACFC: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8007AD00: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8007AD04: or          $t9, $s2, $t3
    ctx->r25 = ctx->r18 | ctx->r11;
    // 0x8007AD08: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007AD0C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007AD10: lw          $v0, 0x13C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X13C);
    // 0x8007AD14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007AD18: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007AD1C: blez        $s0, L_8007AD2C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8007AD20: sw          $v0, 0x13C($sp)
        MEM_W(0X13C, ctx->r29) = ctx->r2;
            goto L_8007AD2C;
    }
    // 0x8007AD20: sw          $v0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r2;
    // 0x8007AD24: b           L_8007AD30
    // 0x8007AD28: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
        goto L_8007AD30;
    // 0x8007AD28: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_8007AD2C:
    // 0x8007AD2C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007AD30:
    // 0x8007AD30: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x8007AD34: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007AD38: blez        $a0, L_8007AD48
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007AD3C: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_8007AD48;
    }
    // 0x8007AD3C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8007AD40: b           L_8007AD4C
    // 0x8007AD44: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007AD4C;
    // 0x8007AD44: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007AD48:
    // 0x8007AD48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007AD4C:
    // 0x8007AD4C: andi        $t8, $v0, 0xFFF
    ctx->r24 = ctx->r2 & 0XFFF;
    // 0x8007AD50: andi        $t5, $v1, 0xFFF
    ctx->r13 = ctx->r3 & 0XFFF;
    // 0x8007AD54: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x8007AD58: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x8007AD5C: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8007AD60: blez        $s4, L_8007AD70
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8007AD64: sw          $t7, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r15;
            goto L_8007AD70;
    }
    // 0x8007AD64: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007AD68: b           L_8007AD74
    // 0x8007AD6C: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
        goto L_8007AD74;
    // 0x8007AD6C: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
L_8007AD70:
    // 0x8007AD70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007AD74:
    // 0x8007AD74: sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10 << 16);
    // 0x8007AD78: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007AD7C: blez        $a0, L_8007AD8C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007AD80: andi        $t9, $v1, 0xFFF
        ctx->r25 = ctx->r3 & 0XFFF;
            goto L_8007AD8C;
    }
    // 0x8007AD80: andi        $t9, $v1, 0xFFF
    ctx->r25 = ctx->r3 & 0XFFF;
    // 0x8007AD84: b           L_8007AD90
    // 0x8007AD88: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007AD90;
    // 0x8007AD88: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007AD8C:
    // 0x8007AD8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007AD90:
    // 0x8007AD90: andi        $t3, $v0, 0xFFF
    ctx->r11 = ctx->r2 & 0XFFF;
    // 0x8007AD94: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8007AD98: or          $t5, $t3, $t8
    ctx->r13 = ctx->r11 | ctx->r24;
    // 0x8007AD9C: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8007ADA0: lw          $a2, 0x13C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X13C);
    // 0x8007ADA4: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8007ADA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007ADAC: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x8007ADB0: sw          $t6, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r14;
    // 0x8007ADB4: bgez        $s4, L_8007AE08
    if (SIGNED(ctx->r20) >= 0) {
        // 0x8007ADB8: sw          $t7, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r15;
            goto L_8007AE08;
    }
    // 0x8007ADB8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007ADBC: lh          $v0, 0x122($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X122);
    // 0x8007ADC0: multu       $s4, $v0
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007ADC4: mflo        $v1
    ctx->r3 = lo;
    // 0x8007ADC8: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8007ADCC: bgez        $v0, L_8007ADEC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007ADD0: nop
    
            goto L_8007ADEC;
    }
    // 0x8007ADD0: nop

    // 0x8007ADD4: blez        $v1, L_8007ADE4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007ADD8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007ADE4;
    }
    // 0x8007ADD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007ADDC: b           L_8007AE08
    // 0x8007ADE0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8007AE08;
    // 0x8007ADE0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8007ADE4:
    // 0x8007ADE4: b           L_8007AE08
    // 0x8007ADE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8007AE08;
    // 0x8007ADE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8007ADEC:
    // 0x8007ADEC: bgez        $v1, L_8007ADFC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007ADF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007ADFC;
    }
    // 0x8007ADF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007ADF4: b           L_8007ADFC
    // 0x8007ADF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8007ADFC;
    // 0x8007ADF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8007ADFC:
    // 0x8007ADFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007AE00: b           L_8007AE08
    // 0x8007AE04: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8007AE08;
    // 0x8007AE04: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8007AE08:
    // 0x8007AE08: bgez        $t2, L_8007AE70
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007AE0C: lw          $t8, 0x118($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X118);
            goto L_8007AE70;
    }
    // 0x8007AE0C: lw          $t8, 0x118($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X118);
    // 0x8007AE10: lh          $v1, 0x11E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X11E);
    // 0x8007AE14: bgez        $v1, L_8007AE44
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007AE18: nop
    
            goto L_8007AE44;
    }
    // 0x8007AE18: nop

    // 0x8007AE1C: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AE20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007AE24: mflo        $v0
    ctx->r2 = lo;
    // 0x8007AE28: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8007AE2C: blez        $v0, L_8007AE3C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007AE30: nop
    
            goto L_8007AE3C;
    }
    // 0x8007AE30: nop

    // 0x8007AE34: b           L_8007AE78
    // 0x8007AE38: subu        $t9, $fp, $v0
    ctx->r25 = SUB32(ctx->r30, ctx->r2);
        goto L_8007AE78;
    // 0x8007AE38: subu        $t9, $fp, $v0
    ctx->r25 = SUB32(ctx->r30, ctx->r2);
L_8007AE3C:
    // 0x8007AE3C: b           L_8007AE74
    // 0x8007AE40: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007AE74;
    // 0x8007AE40: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007AE44:
    // 0x8007AE44: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AE48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007AE4C: mflo        $v0
    ctx->r2 = lo;
    // 0x8007AE50: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8007AE54: bgez        $v0, L_8007AE64
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007AE58: nop
    
            goto L_8007AE64;
    }
    // 0x8007AE58: nop

    // 0x8007AE5C: b           L_8007AE64
    // 0x8007AE60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8007AE64;
    // 0x8007AE60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8007AE64:
    // 0x8007AE64: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8007AE68: b           L_8007AE74
    // 0x8007AE6C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8007AE74;
    // 0x8007AE6C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8007AE70:
    // 0x8007AE70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007AE74:
    // 0x8007AE74: subu        $t9, $fp, $v0
    ctx->r25 = SUB32(ctx->r30, ctx->r2);
L_8007AE78:
    // 0x8007AE78: subu        $t4, $t8, $a1
    ctx->r12 = SUB32(ctx->r24, ctx->r5);
    // 0x8007AE7C: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x8007AE80: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x8007AE84: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x8007AE88: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8007AE8C: lw          $t9, 0x13C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X13C);
    // 0x8007AE90: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x8007AE94: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8007AE98: sw          $t8, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r24;
    // 0x8007AE9C: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x8007AEA0: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x8007AEA4: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x8007AEA8: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
L_8007AEAC:
    // 0x8007AEAC: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x8007AEB0: slt         $at, $s7, $t3
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007AEB4: bnel        $at, $zero, L_8007AB30
    if (ctx->r1 != 0) {
        // 0x8007AEB8: lwc1        $f0, 0x94($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
            goto L_8007AB30;
    }
    goto skip_3;
    // 0x8007AEB8: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    skip_3:
    // 0x8007AEBC: b           L_8007B298
    // 0x8007AEC0: lw          $t4, 0x13C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X13C);
        goto L_8007B298;
    // 0x8007AEC0: lw          $t4, 0x13C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X13C);
L_8007AEC4:
    // 0x8007AEC4: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x8007AEC8: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x8007AECC: bc1fl       L_8007B298
    if (!c1cs) {
        // 0x8007AED0: lw          $t4, 0x13C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X13C);
            goto L_8007B298;
    }
    goto skip_4;
    // 0x8007AED0: lw          $t4, 0x13C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X13C);
    skip_4:
    // 0x8007AED4: lw          $t7, 0x174($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X174);
    // 0x8007AED8: lw          $t8, 0x11C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X11C);
    // 0x8007AEDC: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x8007AEE0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8007AEE4: bne         $t7, $zero, L_8007AEF0
    if (ctx->r15 != 0) {
        // 0x8007AEE8: nop
    
            goto L_8007AEF0;
    }
    // 0x8007AEE8: nop

    // 0x8007AEEC: break       7
    do_break(2147987180);
L_8007AEF0:
    // 0x8007AEF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007AEF4: bne         $t7, $at, L_8007AF08
    if (ctx->r15 != ctx->r1) {
        // 0x8007AEF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007AF08;
    }
    // 0x8007AEF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007AEFC: bne         $t6, $at, L_8007AF08
    if (ctx->r14 != ctx->r1) {
        // 0x8007AF00: nop
    
            goto L_8007AF08;
    }
    // 0x8007AF00: nop

    // 0x8007AF04: break       6
    do_break(2147987204);
L_8007AF08:
    // 0x8007AF08: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007AF0C: lui         $at, 0xBA80
    ctx->r1 = S32(0XBA80 << 16);
    // 0x8007AF10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007AF14: mflo        $t9
    ctx->r25 = lo;
    // 0x8007AF18: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8007AF1C: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007AF20: nop

L_8007AF24:
    // 0x8007AF24: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007AF28: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8007AF2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007AF30: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8007AF34: lw          $v0, -0x7AF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7AF0);
    // 0x8007AF38: lw          $t4, 0x98($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X98);
    // 0x8007AF3C: or          $s5, $s6, $zero
    ctx->r21 = ctx->r22 | 0;
    // 0x8007AF40: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007AF44: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
    // 0x8007AF48: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8007AF4C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8007AF50: mfc1        $s7, $f8
    ctx->r23 = (int32_t)ctx->f8.u32l;
    // 0x8007AF54: nop

    // 0x8007AF58: sra         $t1, $s7, 5
    ctx->r9 = S32(SIGNED(ctx->r23) >> 5);
    // 0x8007AF5C: addu        $v1, $t1, $t4
    ctx->r3 = ADD32(ctx->r9, ctx->r12);
    // 0x8007AF60: slt         $at, $v1, $s6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8007AF64: beq         $at, $zero, L_8007AF74
    if (ctx->r1 == 0) {
        // 0x8007AF68: nop
    
            goto L_8007AF74;
    }
    // 0x8007AF68: nop

    // 0x8007AF6C: b           L_8007AF74
    // 0x8007AF70: or          $s5, $v1, $zero
    ctx->r21 = ctx->r3 | 0;
        goto L_8007AF74;
    // 0x8007AF70: or          $s5, $v1, $zero
    ctx->r21 = ctx->r3 | 0;
L_8007AF74:
    // 0x8007AF74: addiu       $t3, $s5, -0x1
    ctx->r11 = ADD32(ctx->r21, -0X1);
    // 0x8007AF78: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8007AF7C: nop

    // 0x8007AF80: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007AF84: div.s       $f20, $f18, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007AF88: add.s       $f4, $f22, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x8007AF8C: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8007AF90: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8007AF94: mfc1        $s3, $f8
    ctx->r19 = (int32_t)ctx->f8.u32l;
    // 0x8007AF98: nop

    // 0x8007AF9C: slt         $at, $s3, $a0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007AFA0: bnel        $at, $zero, L_8007B28C
    if (ctx->r1 != 0) {
        // 0x8007AFA4: slt         $at, $s5, $s6
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_8007B28C;
    }
    goto skip_5;
    // 0x8007AFA4: slt         $at, $s5, $s6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
    skip_5:
    // 0x8007AFA8: add.s       $f10, $f22, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f2.fl;
    // 0x8007AFAC: lhu         $t9, 0x1E($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1E);
    // 0x8007AFB0: lw          $v0, 0x150($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X150);
    // 0x8007AFB4: lw          $a2, 0x148($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X148);
    // 0x8007AFB8: mul.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8007AFBC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007AFC0: lw          $a3, 0x14C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X14C);
    // 0x8007AFC4: addiu       $a0, $sp, 0x13C
    ctx->r4 = ADD32(ctx->r29, 0X13C);
    // 0x8007AFC8: subu        $t0, $s6, $s5
    ctx->r8 = SUB32(ctx->r22, ctx->r21);
    // 0x8007AFCC: lw          $t5, 0x174($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X174);
    // 0x8007AFD0: lw          $t3, 0x144($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X144);
    // 0x8007AFD4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8007AFD8: subu        $t6, $s5, $t1
    ctx->r14 = SUB32(ctx->r21, ctx->r9);
    // 0x8007AFDC: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8007AFE0: nop

    // 0x8007AFE4: slt         $at, $t8, $t2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007AFE8: bnel        $at, $zero, L_8007B28C
    if (ctx->r1 != 0) {
        // 0x8007AFEC: slt         $at, $s5, $s6
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_8007B28C;
    }
    goto skip_6;
    // 0x8007AFEC: slt         $at, $s5, $s6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
    skip_6:
    // 0x8007AFF0: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AFF4: lw          $t5, 0x11C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X11C);
    // 0x8007AFF8: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x8007AFFC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8007B000: andi        $t6, $a2, 0x7
    ctx->r14 = ctx->r6 & 0X7;
    // 0x8007B004: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8007B008: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x8007B00C: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x8007B010: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007B014: lw          $s2, 0x15C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X15C);
    // 0x8007B018: mflo        $t4
    ctx->r12 = lo;
    // 0x8007B01C: addu        $a1, $t4, $t3
    ctx->r5 = ADD32(ctx->r12, ctx->r11);
    // 0x8007B020: andi        $t4, $t5, 0xFFFF
    ctx->r12 = ctx->r13 & 0XFFFF;
    // 0x8007B024: or          $t3, $t8, $t4
    ctx->r11 = ctx->r24 | ctx->r12;
    // 0x8007B028: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x8007B02C: sllv        $t3, $v0, $a3
    ctx->r11 = S32(ctx->r2 << (ctx->r7 & 31));
    // 0x8007B030: andi        $t5, $a3, 0x3
    ctx->r13 = ctx->r7 & 0X3;
    // 0x8007B034: sll         $t8, $t5, 19
    ctx->r24 = S32(ctx->r13 << 19);
    // 0x8007B038: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x8007B03C: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8007B040: addiu       $t5, $t7, 0x7
    ctx->r13 = ADD32(ctx->r15, 0X7);
    // 0x8007B044: or          $t4, $t9, $t8
    ctx->r12 = ctx->r25 | ctx->r24;
    // 0x8007B048: sra         $t9, $t5, 3
    ctx->r25 = S32(SIGNED(ctx->r13) >> 3);
    // 0x8007B04C: lw          $fp, 0x94($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X94);
    // 0x8007B050: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8007B054: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x8007B058: andi        $s2, $s2, 0xFFF
    ctx->r18 = ctx->r18 & 0XFFF;
    // 0x8007B05C: sll         $t3, $t8, 9
    ctx->r11 = S32(ctx->r24 << 9);
    // 0x8007B060: or          $s1, $t4, $t3
    ctx->r17 = ctx->r12 | ctx->r11;
    // 0x8007B064: sll         $s2, $s2, 12
    ctx->r18 = S32(ctx->r18 << 12);
    // 0x8007B068: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007B06C: lh          $s0, 0xFE($sp)
    ctx->r16 = MEM_H(ctx->r29, 0XFE);
    // 0x8007B070: lh          $s4, 0x106($sp)
    ctx->r20 = MEM_H(ctx->r29, 0X106);
    // 0x8007B074: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    // 0x8007B078: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x8007B07C: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    // 0x8007B080: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8007B084: jal         0x80077038
    // 0x8007B088: sll         $fp, $fp, 5
    ctx->r30 = S32(ctx->r30 << 5);
    func_80077038(rdram, ctx);
        goto after_5;
    // 0x8007B088: sll         $fp, $fp, 5
    ctx->r30 = S32(ctx->r30 << 5);
    after_5:
    // 0x8007B08C: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x8007B090: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8007B094: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x8007B098: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007B09C: lw          $t6, 0x13C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X13C);
    // 0x8007B0A0: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x8007B0A4: ori         $t5, $t5, 0x200
    ctx->r13 = ctx->r13 | 0X200;
    // 0x8007B0A8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8007B0AC: sw          $t7, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r15;
    // 0x8007B0B0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8007B0B4: sw          $s1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r17;
    // 0x8007B0B8: lw          $v1, 0x13C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X13C);
    // 0x8007B0BC: subu        $t7, $s6, $t1
    ctx->r15 = SUB32(ctx->r22, ctx->r9);
    // 0x8007B0C0: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8007B0C4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8007B0C8: sw          $t8, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r24;
    // 0x8007B0CC: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x8007B0D0: andi        $t3, $t4, 0xFFF
    ctx->r11 = ctx->r12 & 0XFFF;
    // 0x8007B0D4: andi        $t9, $t5, 0xFFF
    ctx->r25 = ctx->r13 & 0XFFF;
    // 0x8007B0D8: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x8007B0DC: or          $t6, $t3, $at
    ctx->r14 = ctx->r11 | ctx->r1;
    // 0x8007B0E0: or          $t8, $s2, $t9
    ctx->r24 = ctx->r18 | ctx->r25;
    // 0x8007B0E4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007B0E8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007B0EC: lw          $v0, 0x13C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X13C);
    // 0x8007B0F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007B0F4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007B0F8: blez        $s0, L_8007B108
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8007B0FC: sw          $v0, 0x13C($sp)
        MEM_W(0X13C, ctx->r29) = ctx->r2;
            goto L_8007B108;
    }
    // 0x8007B0FC: sw          $v0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r2;
    // 0x8007B100: b           L_8007B10C
    // 0x8007B104: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
        goto L_8007B10C;
    // 0x8007B104: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_8007B108:
    // 0x8007B108: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007B10C:
    // 0x8007B10C: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8007B110: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B114: blez        $a0, L_8007B124
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007B118: lui         $at, 0xE400
        ctx->r1 = S32(0XE400 << 16);
            goto L_8007B124;
    }
    // 0x8007B118: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8007B11C: b           L_8007B128
    // 0x8007B120: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007B128;
    // 0x8007B120: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B124:
    // 0x8007B124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B128:
    // 0x8007B128: andi        $t4, $v0, 0xFFF
    ctx->r12 = ctx->r2 & 0XFFF;
    // 0x8007B12C: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x8007B130: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007B134: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x8007B138: or          $t5, $t3, $t7
    ctx->r13 = ctx->r11 | ctx->r15;
    // 0x8007B13C: blez        $s4, L_8007B14C
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8007B140: sw          $t5, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r13;
            goto L_8007B14C;
    }
    // 0x8007B140: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8007B144: b           L_8007B150
    // 0x8007B148: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
        goto L_8007B150;
    // 0x8007B148: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
L_8007B14C:
    // 0x8007B14C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007B150:
    // 0x8007B150: sll         $a0, $t2, 16
    ctx->r4 = S32(ctx->r10 << 16);
    // 0x8007B154: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8007B158: blez        $a0, L_8007B168
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007B15C: andi        $t8, $v1, 0xFFF
        ctx->r24 = ctx->r3 & 0XFFF;
            goto L_8007B168;
    }
    // 0x8007B15C: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x8007B160: b           L_8007B16C
    // 0x8007B164: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007B16C;
    // 0x8007B164: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B168:
    // 0x8007B168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B16C:
    // 0x8007B16C: andi        $t9, $v0, 0xFFF
    ctx->r25 = ctx->r2 & 0XFFF;
    // 0x8007B170: sll         $t4, $t8, 12
    ctx->r12 = S32(ctx->r24 << 12);
    // 0x8007B174: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x8007B178: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007B17C: lw          $a2, 0x13C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X13C);
    // 0x8007B180: lui         $t5, 0xB400
    ctx->r13 = S32(0XB400 << 16);
    // 0x8007B184: subu        $t8, $fp, $s7
    ctx->r24 = SUB32(ctx->r30, ctx->r23);
    // 0x8007B188: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x8007B18C: sw          $t7, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r15;
    // 0x8007B190: bgez        $s4, L_8007B1E4
    if (SIGNED(ctx->r20) >= 0) {
        // 0x8007B194: sw          $t5, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r13;
            goto L_8007B1E4;
    }
    // 0x8007B194: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x8007B198: lh          $v0, 0x122($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X122);
    // 0x8007B19C: multu       $s4, $v0
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B1A0: mflo        $v1
    ctx->r3 = lo;
    // 0x8007B1A4: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8007B1A8: bgez        $v0, L_8007B1C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007B1AC: nop
    
            goto L_8007B1C8;
    }
    // 0x8007B1AC: nop

    // 0x8007B1B0: blez        $v1, L_8007B1C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007B1B4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007B1C0;
    }
    // 0x8007B1B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007B1B8: b           L_8007B1E8
    // 0x8007B1BC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8007B1E8;
    // 0x8007B1BC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8007B1C0:
    // 0x8007B1C0: b           L_8007B1E8
    // 0x8007B1C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8007B1E8;
    // 0x8007B1C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8007B1C8:
    // 0x8007B1C8: bgez        $v1, L_8007B1D8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007B1CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007B1D8;
    }
    // 0x8007B1CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007B1D0: b           L_8007B1D8
    // 0x8007B1D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8007B1D8;
    // 0x8007B1D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8007B1D8:
    // 0x8007B1D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007B1DC: b           L_8007B1E8
    // 0x8007B1E0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_8007B1E8;
    // 0x8007B1E0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8007B1E4:
    // 0x8007B1E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8007B1E8:
    // 0x8007B1E8: bgez        $t2, L_8007B250
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007B1EC: lw          $t6, 0x118($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X118);
            goto L_8007B250;
    }
    // 0x8007B1EC: lw          $t6, 0x118($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X118);
    // 0x8007B1F0: lh          $v1, 0x11E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X11E);
    // 0x8007B1F4: bgez        $v1, L_8007B224
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007B1F8: nop
    
            goto L_8007B224;
    }
    // 0x8007B1F8: nop

    // 0x8007B1FC: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007B204: mflo        $v0
    ctx->r2 = lo;
    // 0x8007B208: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8007B20C: blez        $v0, L_8007B21C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B210: nop
    
            goto L_8007B21C;
    }
    // 0x8007B210: nop

    // 0x8007B214: b           L_8007B258
    // 0x8007B218: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
        goto L_8007B258;
    // 0x8007B218: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
L_8007B21C:
    // 0x8007B21C: b           L_8007B254
    // 0x8007B220: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8007B254;
    // 0x8007B220: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007B224:
    // 0x8007B224: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007B22C: mflo        $v0
    ctx->r2 = lo;
    // 0x8007B230: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8007B234: bgez        $v0, L_8007B244
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007B238: nop
    
            goto L_8007B244;
    }
    // 0x8007B238: nop

    // 0x8007B23C: b           L_8007B244
    // 0x8007B240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8007B244;
    // 0x8007B240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8007B244:
    // 0x8007B244: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8007B248: b           L_8007B254
    // 0x8007B24C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8007B254;
    // 0x8007B24C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8007B250:
    // 0x8007B250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B254:
    // 0x8007B254: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
L_8007B258:
    // 0x8007B258: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x8007B25C: sll         $t5, $t7, 16
    ctx->r13 = S32(ctx->r15 << 16);
    // 0x8007B260: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x8007B264: or          $t8, $t4, $t5
    ctx->r24 = ctx->r12 | ctx->r13;
    // 0x8007B268: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8007B26C: lw          $t9, 0x13C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X13C);
    // 0x8007B270: lui         $t3, 0xB300
    ctx->r11 = S32(0XB300 << 16);
    // 0x8007B274: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8007B278: sw          $t6, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r14;
    // 0x8007B27C: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x8007B280: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8007B284: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8007B288: slt         $at, $s5, $s6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r22) ? 1 : 0;
L_8007B28C:
    // 0x8007B28C: bne         $at, $zero, L_8007AF24
    if (ctx->r1 != 0) {
        // 0x8007B290: mov.s       $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
            goto L_8007AF24;
    }
    // 0x8007B290: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x8007B294: lw          $t4, 0x13C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X13C);
L_8007B298:
    // 0x8007B298: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x8007B29C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8007B2A0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8007B2A4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8007B2A8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8007B2AC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8007B2B0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8007B2B4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8007B2B8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8007B2BC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8007B2C0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8007B2C4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8007B2C8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8007B2CC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8007B2D0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8007B2D4: jr          $ra
    // 0x8007B2D8: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x8007B2D8: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
