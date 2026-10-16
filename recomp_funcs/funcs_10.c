#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804A0460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0460: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x804A0464: lw          $v0, -0x720C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X720C);
    // 0x804A0468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A046C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A0470: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x804A0474: beq         $t6, $zero, L_804A0480
    if (ctx->r14 == 0) {
        // 0x804A0478: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_804A0480;
    }
    // 0x804A0478: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804A047C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_804A0480:
    // 0x804A0480: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x804A0484: beq         $t7, $zero, L_804A0490
    if (ctx->r15 == 0) {
        // 0x804A0488: andi        $t8, $v0, 0x4
        ctx->r24 = ctx->r2 & 0X4;
            goto L_804A0490;
    }
    // 0x804A0488: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x804A048C: ori         $a0, $a0, 0x4
    ctx->r4 = ctx->r4 | 0X4;
L_804A0490:
    // 0x804A0490: beq         $t8, $zero, L_804A049C
    if (ctx->r24 == 0) {
        // 0x804A0494: andi        $t9, $v0, 0x8
        ctx->r25 = ctx->r2 & 0X8;
            goto L_804A049C;
    }
    // 0x804A0494: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
    // 0x804A0498: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
L_804A049C:
    // 0x804A049C: beq         $t9, $zero, L_804A04A8
    if (ctx->r25 == 0) {
        // 0x804A04A0: andi        $t0, $v0, 0x10
        ctx->r8 = ctx->r2 & 0X10;
            goto L_804A04A8;
    }
    // 0x804A04A0: andi        $t0, $v0, 0x10
    ctx->r8 = ctx->r2 & 0X10;
    // 0x804A04A4: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
L_804A04A8:
    // 0x804A04A8: beq         $t0, $zero, L_804A04B4
    if (ctx->r8 == 0) {
        // 0x804A04AC: andi        $t1, $v0, 0x20
        ctx->r9 = ctx->r2 & 0X20;
            goto L_804A04B4;
    }
    // 0x804A04AC: andi        $t1, $v0, 0x20
    ctx->r9 = ctx->r2 & 0X20;
    // 0x804A04B0: ori         $a0, $a0, 0x80
    ctx->r4 = ctx->r4 | 0X80;
L_804A04B4:
    // 0x804A04B4: beq         $t1, $zero, L_804A04C0
    if (ctx->r9 == 0) {
        // 0x804A04B8: andi        $t2, $v0, 0x40
        ctx->r10 = ctx->r2 & 0X40;
            goto L_804A04C0;
    }
    // 0x804A04B8: andi        $t2, $v0, 0x40
    ctx->r10 = ctx->r2 & 0X40;
    // 0x804A04BC: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
L_804A04C0:
    // 0x804A04C0: beq         $t2, $zero, L_804A04CC
    if (ctx->r10 == 0) {
        // 0x804A04C4: andi        $t3, $v0, 0x80
        ctx->r11 = ctx->r2 & 0X80;
            goto L_804A04CC;
    }
    // 0x804A04C4: andi        $t3, $v0, 0x80
    ctx->r11 = ctx->r2 & 0X80;
    // 0x804A04C8: ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
L_804A04CC:
    // 0x804A04CC: beq         $t3, $zero, L_804A04D8
    if (ctx->r11 == 0) {
        // 0x804A04D0: nop
    
            goto L_804A04D8;
    }
    // 0x804A04D0: nop

    // 0x804A04D4: ori         $a0, $a0, 0x40
    ctx->r4 = ctx->r4 | 0X40;
L_804A04D8:
    // 0x804A04D8: jal         0x80067A30
    // 0x804A04DC: nop

    func_80067A30(rdram, ctx);
        goto after_0;
    // 0x804A04DC: nop

    after_0:
    // 0x804A04E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A04E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A04E8: jr          $ra
    // 0x804A04EC: nop

    return;
    // 0x804A04EC: nop

;}
RECOMP_FUNC void func_8003C710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C710: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003C714: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8003C718: srl         $t6, $a0, 6
    ctx->r14 = S32(U32(ctx->r4) >> 6);
    // 0x8003C71C: andi        $t8, $a0, 0x3F
    ctx->r24 = ctx->r4 & 0X3F;
    // 0x8003C720: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003C724: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8003C728: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8003C72C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8003C730: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8003C734: andi        $t2, $a2, 0xF
    ctx->r10 = ctx->r6 & 0XF;
    // 0x8003C738: lw          $t1, 0xA24($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XA24);
    // 0x8003C73C: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8003C740: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8003C744: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8003C748: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x8003C74C: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x8003C750: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x8003C754: srav        $t9, $t7, $a1
    ctx->r25 = S32(SIGNED(ctx->r15) >> (ctx->r5 & 31));
    // 0x8003C758: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8003C75C: jr          $ra
    // 0x8003C760: and         $v0, $t8, $t0
    ctx->r2 = ctx->r24 & ctx->r8;
    return;
    // 0x8003C760: and         $v0, $t8, $t0
    ctx->r2 = ctx->r24 & ctx->r8;
;}
RECOMP_FUNC void func_80716BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80716BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80716BF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80716BF4: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80716BF8: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80716BFC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80716C00: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80716C04: lw          $v1, 0x6E30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E30);
    // 0x80716C08: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80716C0C: beql        $v1, $zero, L_80716C28
    if (ctx->r3 == 0) {
        // 0x80716C10: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80716C28;
    }
    goto skip_0;
    // 0x80716C10: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80716C14: jal         0x80716A88
    // 0x80716C18: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    func_80716A88(rdram, ctx);
        goto after_0;
    // 0x80716C18: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    after_0:
    // 0x80716C1C: b           L_80716C4C
    // 0x80716C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80716C4C;
    // 0x80716C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80716C24: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80716C28:
    // 0x80716C28: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80716C2C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80716C30: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80716C34: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80716C38: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80716C3C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80716C40: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80716C44: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80716C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80716C4C:
    // 0x80716C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80716C50: jr          $ra
    // 0x80716C54: nop

    return;
    // 0x80716C54: nop

;}
RECOMP_FUNC void func_805AAAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AAAC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805AAACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AAAD0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805AAAD4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805AAAD8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805AAADC: jal         0x80048F84
    // 0x805AAAE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x805AAAE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x805AAAE4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x805AAAE8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805AAAEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805AAAF0: lwc1        $f4, 0xC4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC4);
    // 0x805AAAF4: lwc1        $f10, 0x50($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X50);
    // 0x805AAAF8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x805AAAFC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805AAB00: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805AAB04: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x805AAB08: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x805AAB0C: nop

    // 0x805AAB10: bc1fl       L_805AAB2C
    if (!c1cs) {
        // 0x805AAB14: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_805AAB2C;
    }
    goto skip_0;
    // 0x805AAB14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x805AAB18: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805AAB1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805AAB20: b           L_805AAB44
    // 0x805AAB24: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_805AAB44;
    // 0x805AAB24: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x805AAB28: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_805AAB2C:
    // 0x805AAB2C: nop

    // 0x805AAB30: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x805AAB34: nop

    // 0x805AAB38: bc1f        L_805AAB44
    if (!c1cs) {
        // 0x805AAB3C: nop
    
            goto L_805AAB44;
    }
    // 0x805AAB3C: nop

    // 0x805AAB40: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_805AAB44:
    // 0x805AAB44: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(432, 0XB24) << 16);
    // 0x805AAB48: lwc1        $f2, -0x51EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(432, 0XB24));
    // 0x805AAB4C: lwc1        $f18, 0x6C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x805AAB50: swc1        $f0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f0.u32l;
    // 0x805AAB54: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x805AAB58: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x805AAB5C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805AAB60: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x805AAB64: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x805AAB68: lwc1        $f6, 0x70($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X70);
    // 0x805AAB6C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x805AAB70: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x805AAB74: bc1f        L_805AAB8C
    if (!c1cs) {
        // 0x805AAB78: swc1        $f10, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
            goto L_805AAB8C;
    }
    // 0x805AAB78: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x805AAB7C: swc1        $f8, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f8.u32l;
    // 0x805AAB80: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x805AAB84: b           L_805AAB94
    // 0x805AAB88: swc1        $f16, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f16.u32l;
        goto L_805AAB94;
    // 0x805AAB88: swc1        $f16, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f16.u32l;
L_805AAB8C:
    // 0x805AAB8C: swc1        $f12, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f12.u32l;
    // 0x805AAB90: swc1        $f12, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f12.u32l;
L_805AAB94:
    // 0x805AAB94: jal         0x805AA6F4
    // 0x805AAB98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_805AA6F4(rdram, ctx);
        goto after_1;
    // 0x805AAB98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x805AAB9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AABA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805AABA4: jr          $ra
    // 0x805AABA8: nop

    return;
    // 0x805AABA8: nop

;}
RECOMP_FUNC void func_800410B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800410B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800410B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800410B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800410BC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800410C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800410C4: jal         0x8006593C
    // 0x800410C8: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x800410C8: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    after_0:
    // 0x800410CC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800410D0: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x800410D4: jal         0x8006593C
    // 0x800410D8: lh          $a0, -0x7662($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7662);
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x800410D8: lh          $a0, -0x7662($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7662);
    after_1:
    // 0x800410DC: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x800410E0: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800410E4: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800410E8: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x800410EC: bgez        $t9, L_80041118
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800410F0: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_80041118;
    }
    // 0x800410F0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800410F4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800410F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800410FC: lwc1        $f6, 0xC4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC4);
    // 0x80041100: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80041104: nop

    // 0x80041108: bc1fl       L_8004111C
    if (!c1cs) {
        // 0x8004110C: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_8004111C;
    }
    goto skip_0;
    // 0x8004110C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80041110: b           L_8004114C
    // 0x80041114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004114C;
    // 0x80041114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80041118:
    // 0x80041118: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8004111C:
    // 0x8004111C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80041120: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80041124: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80041128: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x8004112C: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80041130: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80041134: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80041138: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x8004113C: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x80041140: jalr        $t9
    // 0x80041144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80041144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80041148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004114C:
    // 0x8004114C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041150: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80041154: jr          $ra
    // 0x80041158: nop

    return;
    // 0x80041158: nop

;}
RECOMP_FUNC void func_805AB6D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB6D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AB6D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AB6D8: jal         0x80064D1C
    // 0x805AB6DC: addiu       $a0, $zero, 0x27C
    ctx->r4 = ADD32(0, 0X27C);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x805AB6DC: addiu       $a0, $zero, 0x27C
    ctx->r4 = ADD32(0, 0X27C);
    after_0:
    // 0x805AB6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AB6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AB6E8: jr          $ra
    // 0x805AB6EC: nop

    return;
    // 0x805AB6EC: nop

;}
RECOMP_FUNC void func_804BE044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BE044: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BE048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BE04C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BE050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804BE054: jal         0x8004700C
    // 0x804BE058: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804BE058: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x804BE05C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x804BE060: lw          $a0, 0x1F4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F4);
    // 0x804BE064: beq         $v0, $zero, L_804BE16C
    if (ctx->r2 == 0) {
        // 0x804BE068: addiu       $a0, $a0, 0x350
        ctx->r4 = ADD32(ctx->r4, 0X350);
            goto L_804BE16C;
    }
    // 0x804BE068: addiu       $a0, $a0, 0x350
    ctx->r4 = ADD32(ctx->r4, 0X350);
    // 0x804BE06C: lh          $v1, 0x36($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X36);
    // 0x804BE070: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BE074: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x804BE078: bne         $a1, $v1, L_804BE0C4
    if (ctx->r5 != ctx->r3) {
        // 0x804BE07C: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_804BE0C4;
    }
    // 0x804BE07C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x804BE080: lh          $t6, 0x28($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X28);
    // 0x804BE084: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BE088: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(191, 0X2B78) << 16);
    // 0x804BE08C: beq         $t6, $zero, L_804BE0A8
    if (ctx->r14 == 0) {
        // 0x804BE090: addiu       $t1, $t1, -0x1B58
        ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(191, 0X2B78));
            goto L_804BE0A8;
    }
    // 0x804BE090: addiu       $t1, $t1, -0x1B58
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(191, 0X2B78));
    // 0x804BE094: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x804BE098: lw          $t8, 0x1F4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1F4);
    // 0x804BE09C: sh          $zero, 0xE4($t8)
    MEM_H(0XE4, ctx->r24) = 0;
    // 0x804BE0A0: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x804BE0A4: lh          $v1, 0x36($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X36);
L_804BE0A8:
    // 0x804BE0A8: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x804BE0AC: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
    // 0x804BE0B0: sh          $a1, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r5;
    // 0x804BE0B4: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x804BE0B8: sh          $t0, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r8;
    // 0x804BE0BC: b           L_804BE158
    // 0x804BE0C0: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
        goto L_804BE158;
    // 0x804BE0C0: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
L_804BE0C4:
    // 0x804BE0C4: lh          $t2, 0x2A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2A);
    // 0x804BE0C8: beql        $t2, $zero, L_804BE15C
    if (ctx->r10 == 0) {
        // 0x804BE0CC: lw          $t9, 0x44($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X44);
            goto L_804BE15C;
    }
    goto skip_0;
    // 0x804BE0CC: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    skip_0:
    // 0x804BE0D0: lh          $t3, 0x2C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2C);
    // 0x804BE0D4: bnel        $t3, $zero, L_804BE15C
    if (ctx->r11 != 0) {
        // 0x804BE0D8: lw          $t9, 0x44($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X44);
            goto L_804BE15C;
    }
    goto skip_1;
    // 0x804BE0D8: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    skip_1:
    // 0x804BE0DC: lh          $t4, 0x32($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X32);
    // 0x804BE0E0: blezl       $t4, L_804BE15C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x804BE0E4: lw          $t9, 0x44($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X44);
            goto L_804BE15C;
    }
    goto skip_2;
    // 0x804BE0E4: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    skip_2:
    // 0x804BE0E8: lbu         $t5, 0x18($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X18);
    // 0x804BE0EC: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x804BE0F0: beql        $at, $zero, L_804BE15C
    if (ctx->r1 == 0) {
        // 0x804BE0F4: lw          $t9, 0x44($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X44);
            goto L_804BE15C;
    }
    goto skip_3;
    // 0x804BE0F4: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    skip_3:
    // 0x804BE0F8: lbu         $t6, 0x30($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X30);
    // 0x804BE0FC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x804BE100: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(191, 0X2B78) << 16);
    // 0x804BE104: bne         $t6, $at, L_804BE158
    if (ctx->r14 != ctx->r1) {
        // 0x804BE108: addiu       $t1, $t1, -0x1B58
        ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(191, 0X2B78));
            goto L_804BE158;
    }
    // 0x804BE108: addiu       $t1, $t1, -0x1B58
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(191, 0X2B78));
    // 0x804BE10C: lh          $t8, 0x28($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X28);
    // 0x804BE110: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x804BE114: sw          $t7, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r15;
    // 0x804BE118: beq         $t8, $zero, L_804BE12C
    if (ctx->r24 == 0) {
        // 0x804BE11C: sh          $zero, 0x38($s0)
        MEM_H(0X38, ctx->r16) = 0;
            goto L_804BE12C;
    }
    // 0x804BE11C: sh          $zero, 0x38($s0)
    MEM_H(0X38, ctx->r16) = 0;
    // 0x804BE120: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x804BE124: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x804BE128: sh          $zero, 0xE4($t0)
    MEM_H(0XE4, ctx->r8) = 0;
L_804BE12C:
    // 0x804BE12C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x804BE130: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BE134: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804BE138: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
    // 0x804BE13C: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x804BE140: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    // 0x804BE144: jal         0x80067BBC
    // 0x804BE148: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x804BE148: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    after_1:
    // 0x804BE14C: addiu       $a0, $zero, 0x273
    ctx->r4 = ADD32(0, 0X273);
    // 0x804BE150: jal         0x80067818
    // 0x804BE154: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x804BE154: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_804BE158:
    // 0x804BE158: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
L_804BE15C:
    // 0x804BE15C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BE160: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x804BE164: jalr        $t9
    // 0x804BE168: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x804BE168: nop

    after_3:
L_804BE16C:
    // 0x804BE16C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BE170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BE174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BE178: jr          $ra
    // 0x804BE17C: nop

    return;
    // 0x804BE17C: nop

;}
RECOMP_FUNC void func_804A0954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A0958: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x804A095C: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x804A0960: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804A0964: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804A0968: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x804A096C: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x804A0970: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x804A0974: beq         $v0, $zero, L_804A09E0
    if (ctx->r2 == 0) {
        // 0x804A0978: sub.s       $f12, $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
            goto L_804A09E0;
    }
    // 0x804A0978: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x804A097C: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0980: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A0984: nop

    // 0x804A0988: bc1fl       L_804A09E4
    if (!c1cs) {
        // 0x804A098C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A09E4;
    }
    goto skip_0;
    // 0x804A098C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x804A0990: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A0994: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804A0998: sub.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x804A099C: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A09A0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A09A4: bc1fl       L_804A09E4
    if (!c1cs) {
        // 0x804A09A8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A09E4;
    }
    goto skip_1;
    // 0x804A09A8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x804A09AC: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A09B0: neg.s       $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = -ctx->f22.fl;
    // 0x804A09B4: sub.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x804A09B8: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x804A09BC: nop

    // 0x804A09C0: bc1fl       L_804A09E4
    if (!c1cs) {
        // 0x804A09C4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A09E4;
    }
    goto skip_2;
    // 0x804A09C4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_2:
    // 0x804A09C8: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A09CC: nop

    // 0x804A09D0: bc1fl       L_804A09E4
    if (!c1cs) {
        // 0x804A09D4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A09E4;
    }
    goto skip_3;
    // 0x804A09D4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_3:
    // 0x804A09D8: b           L_804A0C88
    // 0x804A09DC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0C88;
    // 0x804A09DC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_804A09E0:
    // 0x804A09E0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A09E4:
    // 0x804A09E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804A09E8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A09EC: beql        $v0, $zero, L_804A0A58
    if (ctx->r2 == 0) {
        // 0x804A09F0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0A58;
    }
    goto skip_4;
    // 0x804A09F0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_4:
    // 0x804A09F4: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A09F8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A09FC: nop

    // 0x804A0A00: bc1fl       L_804A0A58
    if (!c1cs) {
        // 0x804A0A04: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0A58;
    }
    goto skip_5;
    // 0x804A0A04: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_5:
    // 0x804A0A08: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A0A0C: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x804A0A10: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A0A14: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0A18: bc1fl       L_804A0A58
    if (!c1cs) {
        // 0x804A0A1C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0A58;
    }
    goto skip_6;
    // 0x804A0A1C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_6:
    // 0x804A0A20: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0A24: neg.s       $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
    // 0x804A0A28: sub.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x804A0A2C: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x804A0A30: nop

    // 0x804A0A34: bc1fl       L_804A0A58
    if (!c1cs) {
        // 0x804A0A38: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0A58;
    }
    goto skip_7;
    // 0x804A0A38: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_7:
    // 0x804A0A3C: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A0A40: nop

    // 0x804A0A44: bc1fl       L_804A0A58
    if (!c1cs) {
        // 0x804A0A48: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0A58;
    }
    goto skip_8;
    // 0x804A0A48: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_8:
    // 0x804A0A4C: b           L_804A0C88
    // 0x804A0A50: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0C88;
    // 0x804A0A50: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0A54: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0A58:
    // 0x804A0A58: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0A5C: beql        $v0, $zero, L_804A0AC8
    if (ctx->r2 == 0) {
        // 0x804A0A60: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0AC8;
    }
    goto skip_9;
    // 0x804A0A60: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_9:
    // 0x804A0A64: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0A68: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A0A6C: nop

    // 0x804A0A70: bc1fl       L_804A0AC8
    if (!c1cs) {
        // 0x804A0A74: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0AC8;
    }
    goto skip_10;
    // 0x804A0A74: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x804A0A78: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A0A7C: sub.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x804A0A80: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A0A84: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0A88: bc1fl       L_804A0AC8
    if (!c1cs) {
        // 0x804A0A8C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0AC8;
    }
    goto skip_11;
    // 0x804A0A8C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_11:
    // 0x804A0A90: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0A94: neg.s       $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = -ctx->f22.fl;
    // 0x804A0A98: sub.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x804A0A9C: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x804A0AA0: nop

    // 0x804A0AA4: bc1fl       L_804A0AC8
    if (!c1cs) {
        // 0x804A0AA8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0AC8;
    }
    goto skip_12;
    // 0x804A0AA8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_12:
    // 0x804A0AAC: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A0AB0: nop

    // 0x804A0AB4: bc1fl       L_804A0AC8
    if (!c1cs) {
        // 0x804A0AB8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0AC8;
    }
    goto skip_13;
    // 0x804A0AB8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_13:
    // 0x804A0ABC: b           L_804A0C88
    // 0x804A0AC0: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0C88;
    // 0x804A0AC0: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0AC4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0AC8:
    // 0x804A0AC8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0ACC: beql        $v0, $zero, L_804A0B38
    if (ctx->r2 == 0) {
        // 0x804A0AD0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0B38;
    }
    goto skip_14;
    // 0x804A0AD0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_14:
    // 0x804A0AD4: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0AD8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A0ADC: nop

    // 0x804A0AE0: bc1fl       L_804A0B38
    if (!c1cs) {
        // 0x804A0AE4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0B38;
    }
    goto skip_15;
    // 0x804A0AE4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_15:
    // 0x804A0AE8: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A0AEC: sub.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x804A0AF0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A0AF4: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0AF8: bc1fl       L_804A0B38
    if (!c1cs) {
        // 0x804A0AFC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0B38;
    }
    goto skip_16;
    // 0x804A0AFC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_16:
    // 0x804A0B00: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0B04: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
    // 0x804A0B08: sub.s       $f2, $f8, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x804A0B0C: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x804A0B10: nop

    // 0x804A0B14: bc1fl       L_804A0B38
    if (!c1cs) {
        // 0x804A0B18: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0B38;
    }
    goto skip_17;
    // 0x804A0B18: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_17:
    // 0x804A0B1C: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A0B20: nop

    // 0x804A0B24: bc1fl       L_804A0B38
    if (!c1cs) {
        // 0x804A0B28: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0B38;
    }
    goto skip_18;
    // 0x804A0B28: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_18:
    // 0x804A0B2C: b           L_804A0C88
    // 0x804A0B30: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0C88;
    // 0x804A0B30: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0B34: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0B38:
    // 0x804A0B38: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0B3C: beql        $v0, $zero, L_804A0BA8
    if (ctx->r2 == 0) {
        // 0x804A0B40: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0BA8;
    }
    goto skip_19;
    // 0x804A0B40: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_19:
    // 0x804A0B44: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0B48: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A0B4C: nop

    // 0x804A0B50: bc1fl       L_804A0BA8
    if (!c1cs) {
        // 0x804A0B54: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0BA8;
    }
    goto skip_20;
    // 0x804A0B54: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_20:
    // 0x804A0B58: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A0B5C: sub.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x804A0B60: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A0B64: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0B68: bc1fl       L_804A0BA8
    if (!c1cs) {
        // 0x804A0B6C: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0BA8;
    }
    goto skip_21;
    // 0x804A0B6C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_21:
    // 0x804A0B70: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0B74: neg.s       $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = -ctx->f22.fl;
    // 0x804A0B78: sub.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x804A0B7C: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x804A0B80: nop

    // 0x804A0B84: bc1fl       L_804A0BA8
    if (!c1cs) {
        // 0x804A0B88: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0BA8;
    }
    goto skip_22;
    // 0x804A0B88: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_22:
    // 0x804A0B8C: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A0B90: nop

    // 0x804A0B94: bc1fl       L_804A0BA8
    if (!c1cs) {
        // 0x804A0B98: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0BA8;
    }
    goto skip_23;
    // 0x804A0B98: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_23:
    // 0x804A0B9C: b           L_804A0C88
    // 0x804A0BA0: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0C88;
    // 0x804A0BA0: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0BA4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0BA8:
    // 0x804A0BA8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0BAC: beql        $v0, $zero, L_804A0C18
    if (ctx->r2 == 0) {
        // 0x804A0BB0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0C18;
    }
    goto skip_24;
    // 0x804A0BB0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_24:
    // 0x804A0BB4: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0BB8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A0BBC: nop

    // 0x804A0BC0: bc1fl       L_804A0C18
    if (!c1cs) {
        // 0x804A0BC4: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0C18;
    }
    goto skip_25;
    // 0x804A0BC4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_25:
    // 0x804A0BC8: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A0BCC: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x804A0BD0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A0BD4: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0BD8: bc1fl       L_804A0C18
    if (!c1cs) {
        // 0x804A0BDC: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0C18;
    }
    goto skip_26;
    // 0x804A0BDC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_26:
    // 0x804A0BE0: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0BE4: neg.s       $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
    // 0x804A0BE8: sub.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x804A0BEC: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x804A0BF0: nop

    // 0x804A0BF4: bc1fl       L_804A0C18
    if (!c1cs) {
        // 0x804A0BF8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0C18;
    }
    goto skip_27;
    // 0x804A0BF8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_27:
    // 0x804A0BFC: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A0C00: nop

    // 0x804A0C04: bc1fl       L_804A0C18
    if (!c1cs) {
        // 0x804A0C08: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_804A0C18;
    }
    goto skip_28;
    // 0x804A0C08: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_28:
    // 0x804A0C0C: b           L_804A0C88
    // 0x804A0C10: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0C88;
    // 0x804A0C10: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0C14: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_804A0C18:
    // 0x804A0C18: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804A0C1C: beql        $v0, $zero, L_804A0C88
    if (ctx->r2 == 0) {
        // 0x804A0C20: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_804A0C88;
    }
    goto skip_29;
    // 0x804A0C20: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_29:
    // 0x804A0C24: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A0C28: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x804A0C2C: nop

    // 0x804A0C30: bc1fl       L_804A0C88
    if (!c1cs) {
        // 0x804A0C34: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_804A0C88;
    }
    goto skip_30;
    // 0x804A0C34: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_30:
    // 0x804A0C38: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x804A0C3C: sub.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x804A0C40: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x804A0C44: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x804A0C48: bc1fl       L_804A0C88
    if (!c1cs) {
        // 0x804A0C4C: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_804A0C88;
    }
    goto skip_31;
    // 0x804A0C4C: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_31:
    // 0x804A0C50: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A0C54: neg.s       $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = -ctx->f22.fl;
    // 0x804A0C58: sub.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x804A0C5C: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x804A0C60: nop

    // 0x804A0C64: bc1fl       L_804A0C88
    if (!c1cs) {
        // 0x804A0C68: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_804A0C88;
    }
    goto skip_32;
    // 0x804A0C68: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_32:
    // 0x804A0C6C: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804A0C70: nop

    // 0x804A0C74: bc1fl       L_804A0C88
    if (!c1cs) {
        // 0x804A0C78: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_804A0C88;
    }
    goto skip_33;
    // 0x804A0C78: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_33:
    // 0x804A0C7C: b           L_804A0C88
    // 0x804A0C80: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804A0C88;
    // 0x804A0C80: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804A0C84: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_804A0C88:
    // 0x804A0C88: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x804A0C8C: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x804A0C90: jr          $ra
    // 0x804A0C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804A0C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806A7A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A7A20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A7A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A7A28: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806A7A2C: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(586, 0X430) << 16);
    // 0x806A7A30: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806A7A34: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806A7A38: addiu       $t6, $t6, 0x7DF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(586, 0X430));
    // 0x806A7A3C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806A7A40: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806A7A44: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x806A7A48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806A7A4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A7A50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806A7A54: jal         0x806A7CF0
    // 0x806A7A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806A7CF0(rdram, ctx);
        goto after_0;
    // 0x806A7A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x806A7A5C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806A7A60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806A7A64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806A7A68: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(586, 0X460) << 16);
    // 0x806A7A6C: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x806A7A70: lwc1        $f6, 0x7E20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(586, 0X460));
    // 0x806A7A74: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x806A7A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A7A7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806A7A80: jr          $ra
    // 0x806A7A84: nop

    return;
    // 0x806A7A84: nop

;}
RECOMP_FUNC void func_805A5628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5628: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A562C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A5630: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A5634: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A5638: lw          $t6, 0x27C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X27C);
    // 0x805A563C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A5640: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x805A5644: jal         0x805A6730
    // 0x805A5648: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_805A6730(rdram, ctx);
        goto after_0;
    // 0x805A5648: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x805A564C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805A5650: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x805A5654: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A5658: sw          $zero, 0x270($v0)
    MEM_W(0X270, ctx->r2) = 0;
    // 0x805A565C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x805A5660: swc1        $f4, 0x26C($v0)
    MEM_W(0X26C, ctx->r2) = ctx->f4.u32l;
    // 0x805A5664: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x805A5668: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x805A566C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805A5670: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805A5674: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x805A5678: sw          $t7, 0x5BC($t2)
    MEM_W(0X5BC, ctx->r10) = ctx->r15;
    // 0x805A567C: sw          $zero, 0x278($v0)
    MEM_W(0X278, ctx->r2) = 0;
    // 0x805A5680: lw          $t3, 0x5B8($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X5B8);
    // 0x805A5684: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x805A5688: jal         0x800495D4
    // 0x805A568C: sw          $t4, 0x5B8($t0)
    MEM_W(0X5B8, ctx->r8) = ctx->r12;
    func_800495D4(rdram, ctx);
        goto after_1;
    // 0x805A568C: sw          $t4, 0x5B8($t0)
    MEM_W(0X5B8, ctx->r8) = ctx->r12;
    after_1:
    // 0x805A5690: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x805A5694: addiu       $v0, $v0, 0x7EAC
    ctx->r2 = ADD32(ctx->r2, 0X7EAC);
    // 0x805A5698: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_805A569C:
    // 0x805A569C: lw          $t5, 0x5BC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X5BC);
    // 0x805A56A0: bnel        $t5, $zero, L_805A56B8
    if (ctx->r13 != 0) {
        // 0x805A56A4: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_805A56B8;
    }
    goto skip_0;
    // 0x805A56A4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x805A56A8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x805A56AC: bgez        $v1, L_805A569C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x805A56B0: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_805A569C;
    }
    // 0x805A56B0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x805A56B4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
L_805A56B8:
    // 0x805A56B8: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x805A56BC: bnel        $at, $zero, L_805A574C
    if (ctx->r1 != 0) {
        // 0x805A56C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A574C;
    }
    goto skip_1;
    // 0x805A56C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805A56C4: jal         0x8004700C
    // 0x805A56C8: nop

    func_8004700C(rdram, ctx);
        goto after_2;
    // 0x805A56C8: nop

    after_2:
    // 0x805A56CC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x805A56D0: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x805A56D4: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x805A56D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805A56DC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x805A56E0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x805A56E4: addu        $t7, $t0, $t9
    ctx->r15 = ADD32(ctx->r8, ctx->r25);
    // 0x805A56E8: addiu       $t2, $t7, 0x5CC
    ctx->r10 = ADD32(ctx->r15, 0X5CC);
    // 0x805A56EC: sw          $t2, 0x62C($t0)
    MEM_W(0X62C, ctx->r8) = ctx->r10;
    // 0x805A56F0: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x805A56F4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x805A56F8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x805A56FC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x805A5700: lw          $t3, 0x174($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X174);
    // 0x805A5704: lw          $v1, 0x1D8($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X1D8);
    // 0x805A5708: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x805A570C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x805A5710: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x805A5714: lh          $t7, 0x1A($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X1A);
    // 0x805A5718: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x805A571C: lw          $a1, -0x6580($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6580);
    // 0x805A5720: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x805A5724: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x805A5728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805A572C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805A5730: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x805A5734: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x805A5738: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x805A573C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x805A5740: jal         0x80048C2C
    // 0x805A5744: nop

    func_80048C2C(rdram, ctx);
        goto after_3;
    // 0x805A5744: nop

    after_3:
    // 0x805A5748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A574C:
    // 0x805A574C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A5750: jr          $ra
    // 0x805A5754: nop

    return;
    // 0x805A5754: nop

;}
RECOMP_FUNC void func_8001C960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C960: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001C964: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001C968: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001C96C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001C970: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001C974: jal         0x8001C648
    // 0x8001C978: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8001C648(rdram, ctx);
        goto after_0;
    // 0x8001C978: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8001C97C: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8001C980: beq         $v0, $zero, L_8001C990
    if (ctx->r2 == 0) {
        // 0x8001C984: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8001C990;
    }
    // 0x8001C984: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8001C988: b           L_8001CA2C
    // 0x8001C98C: sw          $t6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r14;
        goto L_8001CA2C;
    // 0x8001C98C: sw          $t6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r14;
L_8001C990:
    // 0x8001C990: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x8001C994: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x8001C998: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001C99C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8001C9A0: nop

    // 0x8001C9A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001C9A8: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001C9AC: jal         0x80066DE4
    // 0x8001C9B0: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8001C9B0: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8001C9B4: lui         $at, 0xC190
    ctx->r1 = S32(0XC190 << 16);
    // 0x8001C9B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001C9BC: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8001C9C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001C9C4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8001C9C8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001C9CC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001C9D0: jal         0x80066E88
    // 0x8001C9D4: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8001C9D4: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    after_2:
    // 0x8001C9D8: lui         $at, 0xC190
    ctx->r1 = S32(0XC190 << 16);
    // 0x8001C9DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001C9E0: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8001C9E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001C9E8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001C9EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001C9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001C9F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8001C9F8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001C9FC: swc1        $f16, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f16.u32l;
    // 0x8001CA00: lwc1        $f18, -0x46C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X46C);
    // 0x8001CA04: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001CA08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001CA0C: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x8001CA10: jal         0x8001CBB8
    // 0x8001CA14: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    func_8001CBB8(rdram, ctx);
        goto after_3;
    // 0x8001CA14: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8001CA18: lw          $t8, 0x180($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X180);
    // 0x8001CA1C: beql        $t8, $zero, L_8001CA30
    if (ctx->r24 == 0) {
        // 0x8001CA20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001CA30;
    }
    goto skip_0;
    // 0x8001CA20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001CA24: jal         0x8004816C
    // 0x8001CA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004816C(rdram, ctx);
        goto after_4;
    // 0x8001CA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8001CA2C:
    // 0x8001CA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001CA30:
    // 0x8001CA30: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001CA34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001CA38: jr          $ra
    // 0x8001CA3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001CA3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806FBCDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FBCDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806FBCE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FBCE4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x806FBCE8: lw          $v0, 0x14CC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14CC);
    // 0x806FBCEC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806FBCF0: beq         $v0, $zero, L_806FBD00
    if (ctx->r2 == 0) {
        // 0x806FBCF4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806FBD00;
    }
    // 0x806FBCF4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806FBCF8: b           L_806FBDAC
    // 0x806FBCFC: sw          $t6, 0x14CC($a1)
    MEM_W(0X14CC, ctx->r5) = ctx->r14;
        goto L_806FBDAC;
    // 0x806FBCFC: sw          $t6, 0x14CC($a1)
    MEM_W(0X14CC, ctx->r5) = ctx->r14;
L_806FBD00:
    // 0x806FBD00: lw          $v0, 0x14C4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14C4);
    // 0x806FBD04: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(700, 0X2850) << 16);
    // 0x806FBD08: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806FBD0C: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x806FBD10: beq         $at, $zero, L_806FBDA8
    if (ctx->r1 == 0) {
        // 0x806FBD14: addiu       $a0, $v0, 0x1
        ctx->r4 = ADD32(ctx->r2, 0X1);
            goto L_806FBDA8;
    }
    // 0x806FBD14: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x806FBD18: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x806FBD1C: addiu       $t9, $t9, -0x3B80
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(700, 0X2850));
    // 0x806FBD20: sw          $a0, 0x14C4($a1)
    MEM_W(0X14C4, ctx->r5) = ctx->r4;
    // 0x806FBD24: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x806FBD28: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x806FBD2C: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x806FBD30: lui         $t2, 0x8070
    ctx->r10 = S32(RELOC_HI16(700, 0X2754) << 16);
    // 0x806FBD34: sll         $t1, $a2, 3
    ctx->r9 = S32(ctx->r6 << 3);
    // 0x806FBD38: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806FBD3C: sw          $t0, 0x14CC($a1)
    MEM_W(0X14CC, ctx->r5) = ctx->r8;
    // 0x806FBD40: lw          $t2, -0x3C7C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(700, 0X2754));
    // 0x806FBD44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806FBD48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x806FBD4C: bne         $a0, $at, L_806FBD74
    if (ctx->r4 != ctx->r1) {
        // 0x806FBD50: sw          $t2, 0x14C8($a1)
        MEM_W(0X14C8, ctx->r5) = ctx->r10;
            goto L_806FBD74;
    }
    // 0x806FBD50: sw          $t2, 0x14C8($a1)
    MEM_W(0X14C8, ctx->r5) = ctx->r10;
    // 0x806FBD54: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x806FBD58: jal         0x80067BBC
    // 0x806FBD5C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806FBD5C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_0:
    // 0x806FBD60: addiu       $a0, $zero, 0x23F
    ctx->r4 = ADD32(0, 0X23F);
    // 0x806FBD64: jal         0x80067818
    // 0x806FBD68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806FBD68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806FBD6C: b           L_806FBDB0
    // 0x806FBD70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806FBDB0;
    // 0x806FBD70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FBD74:
    // 0x806FBD74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806FBD78: beq         $v0, $at, L_806FBD88
    if (ctx->r2 == ctx->r1) {
        // 0x806FBD7C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_806FBD88;
    }
    // 0x806FBD7C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806FBD80: bnel        $v0, $at, L_806FBDB0
    if (ctx->r2 != ctx->r1) {
        // 0x806FBD84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806FBDB0;
    }
    goto skip_0;
    // 0x806FBD84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_806FBD88:
    // 0x806FBD88: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x806FBD8C: jal         0x80067BBC
    // 0x806FBD90: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806FBD90: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x806FBD94: addiu       $a0, $zero, 0x240
    ctx->r4 = ADD32(0, 0X240);
    // 0x806FBD98: jal         0x80067818
    // 0x806FBD9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806FBD9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x806FBDA0: b           L_806FBDB0
    // 0x806FBDA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806FBDB0;
    // 0x806FBDA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FBDA8:
    // 0x806FBDA8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
L_806FBDAC:
    // 0x806FBDAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FBDB0:
    // 0x806FBDB0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x806FBDB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806FBDB8: jr          $ra
    // 0x806FBDBC: nop

    return;
    // 0x806FBDBC: nop

;}
RECOMP_FUNC void func_80067EB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067EBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067EC0: jal         0x80067C30
    // 0x80067EC4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_80067C30(rdram, ctx);
        goto after_0;
    // 0x80067EC4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_0:
    // 0x80067EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067ECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067ED0: jr          $ra
    // 0x80067ED4: nop

    return;
    // 0x80067ED4: nop

;}
RECOMP_FUNC void func_8040E904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040E908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E90C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8040E910: lh          $t6, 0x144($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X144);
    // 0x8040E914: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8040E918: bnel        $t6, $at, L_8040E938
    if (ctx->r14 != ctx->r1) {
        // 0x8040E91C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040E938;
    }
    goto skip_0;
    // 0x8040E91C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040E920: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
    // 0x8040E924: bnel        $t7, $zero, L_8040E938
    if (ctx->r15 != 0) {
        // 0x8040E928: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040E938;
    }
    goto skip_1;
    // 0x8040E928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8040E92C: jal         0x8040E8D0
    // 0x8040E930: nop

    func_8040E8D0(rdram, ctx);
        goto after_0;
    // 0x8040E930: nop

    after_0:
    // 0x8040E934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E938:
    // 0x8040E938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040E93C: jr          $ra
    // 0x8040E940: nop

    return;
    // 0x8040E940: nop

;}
RECOMP_FUNC void func_8042E880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042E884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E888: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042E88C: jal         0x8042E6BC
    // 0x8042E890: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042E6BC(rdram, ctx);
        goto after_0;
    // 0x8042E890: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042E894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042E898: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3B84) << 16);
    // 0x8042E89C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8042E8A0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x8042E8A4: lwc1        $f6, 0x1C64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3B84));
    // 0x8042E8A8: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042E8AC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8042E8B0: nop

    // 0x8042E8B4: bc1fl       L_8042E8C8
    if (!c1cs) {
        // 0x8042E8B8: sw          $zero, 0x138($a0)
        MEM_W(0X138, ctx->r4) = 0;
            goto L_8042E8C8;
    }
    goto skip_0;
    // 0x8042E8B8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    skip_0:
    // 0x8042E8BC: b           L_8042E8C8
    // 0x8042E8C0: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
        goto L_8042E8C8;
    // 0x8042E8C0: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x8042E8C4: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
L_8042E8C8:
    // 0x8042E8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042E8CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042E8D0: jr          $ra
    // 0x8042E8D4: nop

    return;
    // 0x8042E8D4: nop

;}
RECOMP_FUNC void func_80056518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005651C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056520: jal         0x80064E84
    // 0x80056524: nop

    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80056524: nop

    after_0:
    // 0x80056528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005652C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80056530: jr          $ra
    // 0x80056534: nop

    return;
    // 0x80056534: nop

;}
RECOMP_FUNC void func_80791168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80791168: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079116C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80791170: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80791174: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80791178: jal         0x80790CB4
    // 0x8079117C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_80790CB4(rdram, ctx);
        goto after_0;
    // 0x8079117C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80791180: jal         0x80790714
    // 0x80791184: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80791184: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80791188: beq         $v0, $zero, L_807911A4
    if (ctx->r2 == 0) {
        // 0x8079118C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_807911A4;
    }
    // 0x8079118C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80791190: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80791194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791198: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8079119C: jal         0x8079393C
    // 0x807911A0: lbu         $a2, 0x10($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X10);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x807911A0: lbu         $a2, 0x10($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X10);
    after_2:
L_807911A4:
    // 0x807911A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807911A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807911AC: jr          $ra
    // 0x807911B0: nop

    return;
    // 0x807911B0: nop

;}
RECOMP_FUNC void func_80027D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027D78: lw          $v1, 0x15C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X15C);
    // 0x80027D7C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80027D80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80027D84: beql        $v0, $zero, L_80027D94
    if (ctx->r2 == 0) {
        // 0x80027D88: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80027D94;
    }
    goto skip_0;
    // 0x80027D88: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    skip_0:
    // 0x80027D8C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80027D90: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80027D94:
    // 0x80027D94: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80027D98: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80027D9C: lw          $t7, -0x3A10($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3A10);
    // 0x80027DA0: lw          $t8, 0x15C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X15C);
    // 0x80027DA4: jr          $ra
    // 0x80027DA8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    return;
    // 0x80027DA8: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void func_8001B200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B208: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001B20C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8001B210: sw          $t6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r14;
    // 0x8001B214: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8001B218: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001B21C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001B220: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001B224: jal         0x80019E98
    // 0x8001B228: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    func_80019E98(rdram, ctx);
        goto after_0;
    // 0x8001B228: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    after_0:
    // 0x8001B22C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001B234: jr          $ra
    // 0x8001B238: nop

    return;
    // 0x8001B238: nop

;}
RECOMP_FUNC void func_80715378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8071537C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80715380: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80715384: jal         0x80714DD4
    // 0x80715388: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80714DD4(rdram, ctx);
        goto after_0;
    // 0x80715388: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8071538C: jal         0x80714E64
    // 0x80715390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714E64(rdram, ctx);
        goto after_1;
    // 0x80715390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80715394: jal         0x80714D40
    // 0x80715398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714D40(rdram, ctx);
        goto after_2;
    // 0x80715398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8071539C: jal         0x80714B20
    // 0x807153A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714B20(rdram, ctx);
        goto after_3;
    // 0x807153A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807153A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807153A8: bne         $v0, $at, L_807153CC
    if (ctx->r2 != ctx->r1) {
        // 0x807153AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807153CC;
    }
    // 0x807153AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807153B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807153B4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x807153B8: jal         0x80715C24
    // 0x807153BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80715C24(rdram, ctx);
        goto after_4;
    // 0x807153BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x807153C0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x807153C4: jal         0x80714A38
    // 0x807153C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80714A38(rdram, ctx);
        goto after_5;
    // 0x807153C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_807153CC:
    // 0x807153CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807153D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807153D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807153D8: jr          $ra
    // 0x807153DC: nop

    return;
    // 0x807153DC: nop

;}
RECOMP_FUNC void func_806747EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806747EC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806747F0: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(529, 0X16D4) << 16);
    // 0x806747F4: addiu       $t6, $t6, 0x46B4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(529, 0X16D4));
    // 0x806747F8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806747FC: jr          $ra
    // 0x80674800: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80674800: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80032C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032C14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032C18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032C1C: jal         0x800348A4
    // 0x80032C20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800348A4(rdram, ctx);
        goto after_0;
    // 0x80032C20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80032C24: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80032C28: jal         0x80065954
    // 0x80032C2C: lwc1        $f12, 0xC4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC4);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80032C2C: lwc1        $f12, 0xC4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC4);
    after_1:
    // 0x80032C30: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80032C34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80032C38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80032C3C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80032C40: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80032C44: jal         0x80041214
    // 0x80032C48: nop

    func_80041214(rdram, ctx);
        goto after_2;
    // 0x80032C48: nop

    after_2:
    // 0x80032C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032C50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032C54: jr          $ra
    // 0x80032C58: nop

    return;
    // 0x80032C58: nop

;}
RECOMP_FUNC void func_807C2F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C2F48: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x807C2F4C: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x807C2F50: lw          $v0, 0x59C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X59C);
    // 0x807C2F54: lw          $t6, 0x60($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X60);
    // 0x807C2F58: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x807C2F5C: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x807C2F60: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x807C2F64: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x807C2F68: beq         $a1, $zero, L_807C3084
    if (ctx->r5 == 0) {
        // 0x807C2F6C: andi        $v0, $a1, 0x3
        ctx->r2 = ctx->r5 & 0X3;
            goto L_807C3084;
    }
    // 0x807C2F6C: andi        $v0, $a1, 0x3
    ctx->r2 = ctx->r5 & 0X3;
    // 0x807C2F70: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x807C2F74: beq         $v0, $zero, L_807C2FC0
    if (ctx->r2 == 0) {
        // 0x807C2F78: addu        $a2, $v0, $a1
        ctx->r6 = ADD32(ctx->r2, ctx->r5);
            goto L_807C2FC0;
    }
    // 0x807C2F78: addu        $a2, $v0, $a1
    ctx->r6 = ADD32(ctx->r2, ctx->r5);
    // 0x807C2F7C: addiu       $t2, $zero, 0x45ED
    ctx->r10 = ADD32(0, 0X45ED);
    // 0x807C2F80: addiu       $t1, $zero, 0x406F
    ctx->r9 = ADD32(0, 0X406F);
    // 0x807C2F84: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_807C2F88:
    // 0x807C2F88: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x807C2F8C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x807C2F90: beq         $t0, $t7, L_807C2FB4
    if (ctx->r8 == ctx->r15) {
        // 0x807C2F94: nop
    
            goto L_807C2FB4;
    }
    // 0x807C2F94: nop

    // 0x807C2F98: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x807C2F9C: beq         $t1, $v1, L_807C2FAC
    if (ctx->r9 == ctx->r3) {
        // 0x807C2FA0: nop
    
            goto L_807C2FAC;
    }
    // 0x807C2FA0: nop

    // 0x807C2FA4: bne         $t2, $v1, L_807C2FB4
    if (ctx->r10 != ctx->r3) {
        // 0x807C2FA8: nop
    
            goto L_807C2FB4;
    }
    // 0x807C2FA8: nop

L_807C2FAC:
    // 0x807C2FAC: jr          $ra
    // 0x807C2FB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x807C2FB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807C2FB4:
    // 0x807C2FB4: bne         $a2, $a1, L_807C2F88
    if (ctx->r6 != ctx->r5) {
        // 0x807C2FB8: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_807C2F88;
    }
    // 0x807C2FB8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x807C2FBC: beq         $a1, $zero, L_807C3084
    if (ctx->r5 == 0) {
        // 0x807C2FC0: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_807C3084;
    }
L_807C2FC0:
    // 0x807C2FC0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x807C2FC4: addiu       $t1, $zero, 0x406F
    ctx->r9 = ADD32(0, 0X406F);
    // 0x807C2FC8: addiu       $t2, $zero, 0x45ED
    ctx->r10 = ADD32(0, 0X45ED);
L_807C2FCC:
    // 0x807C2FCC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x807C2FD0: beql        $t0, $t8, L_807C2FF8
    if (ctx->r8 == ctx->r24) {
        // 0x807C2FD4: lw          $t9, 0x10($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X10);
            goto L_807C2FF8;
    }
    goto skip_0;
    // 0x807C2FD4: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    skip_0:
    // 0x807C2FD8: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x807C2FDC: beq         $t1, $v1, L_807C2FEC
    if (ctx->r9 == ctx->r3) {
        // 0x807C2FE0: nop
    
            goto L_807C2FEC;
    }
    // 0x807C2FE0: nop

    // 0x807C2FE4: bnel        $t2, $v1, L_807C2FF8
    if (ctx->r10 != ctx->r3) {
        // 0x807C2FE8: lw          $t9, 0x10($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X10);
            goto L_807C2FF8;
    }
    goto skip_1;
    // 0x807C2FE8: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    skip_1:
L_807C2FEC:
    // 0x807C2FEC: jr          $ra
    // 0x807C2FF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x807C2FF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807C2FF4: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
L_807C2FF8:
    // 0x807C2FF8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x807C2FFC: beql        $t0, $t9, L_807C3024
    if (ctx->r8 == ctx->r25) {
        // 0x807C3000: lw          $t3, 0x10($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X10);
            goto L_807C3024;
    }
    goto skip_2;
    // 0x807C3000: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    skip_2:
    // 0x807C3004: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x807C3008: beq         $t1, $v1, L_807C3018
    if (ctx->r9 == ctx->r3) {
        // 0x807C300C: nop
    
            goto L_807C3018;
    }
    // 0x807C300C: nop

    // 0x807C3010: bnel        $t2, $v1, L_807C3024
    if (ctx->r10 != ctx->r3) {
        // 0x807C3014: lw          $t3, 0x10($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X10);
            goto L_807C3024;
    }
    goto skip_3;
    // 0x807C3014: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    skip_3:
L_807C3018:
    // 0x807C3018: jr          $ra
    // 0x807C301C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x807C301C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807C3020: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
L_807C3024:
    // 0x807C3024: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x807C3028: beql        $t0, $t3, L_807C3050
    if (ctx->r8 == ctx->r11) {
        // 0x807C302C: lw          $t4, 0x10($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X10);
            goto L_807C3050;
    }
    goto skip_4;
    // 0x807C302C: lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X10);
    skip_4:
    // 0x807C3030: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x807C3034: beq         $t1, $v1, L_807C3044
    if (ctx->r9 == ctx->r3) {
        // 0x807C3038: nop
    
            goto L_807C3044;
    }
    // 0x807C3038: nop

    // 0x807C303C: bnel        $t2, $v1, L_807C3050
    if (ctx->r10 != ctx->r3) {
        // 0x807C3040: lw          $t4, 0x10($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X10);
            goto L_807C3050;
    }
    goto skip_5;
    // 0x807C3040: lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X10);
    skip_5:
L_807C3044:
    // 0x807C3044: jr          $ra
    // 0x807C3048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x807C3048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807C304C: lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X10);
L_807C3050:
    // 0x807C3050: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x807C3054: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x807C3058: beq         $t0, $t4, L_807C307C
    if (ctx->r8 == ctx->r12) {
        // 0x807C305C: nop
    
            goto L_807C307C;
    }
    // 0x807C305C: nop

    // 0x807C3060: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x807C3064: beq         $t1, $v1, L_807C3074
    if (ctx->r9 == ctx->r3) {
        // 0x807C3068: nop
    
            goto L_807C3074;
    }
    // 0x807C3068: nop

    // 0x807C306C: bne         $t2, $v1, L_807C307C
    if (ctx->r10 != ctx->r3) {
        // 0x807C3070: nop
    
            goto L_807C307C;
    }
    // 0x807C3070: nop

L_807C3074:
    // 0x807C3074: jr          $ra
    // 0x807C3078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x807C3078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807C307C:
    // 0x807C307C: bne         $a1, $zero, L_807C2FCC
    if (ctx->r5 != 0) {
        // 0x807C3080: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_807C2FCC;
    }
    // 0x807C3080: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_807C3084:
    // 0x807C3084: lw          $v0, 0x970($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X970);
    // 0x807C3088: addiu       $t1, $zero, 0x406F
    ctx->r9 = ADD32(0, 0X406F);
    // 0x807C308C: addiu       $t2, $zero, 0x45ED
    ctx->r10 = ADD32(0, 0X45ED);
    // 0x807C3090: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    // 0x807C3094: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807C3098: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x807C309C: beql        $a1, $zero, L_807C30E8
    if (ctx->r5 == 0) {
        // 0x807C30A0: lh          $a1, 0x9A6($a3)
        ctx->r5 = MEM_H(ctx->r7, 0X9A6);
            goto L_807C30E8;
    }
    goto skip_6;
    // 0x807C30A0: lh          $a1, 0x9A6($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X9A6);
    skip_6:
L_807C30A4:
    // 0x807C30A4: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x807C30A8: beq         $a2, $zero, L_807C30DC
    if (ctx->r6 == 0) {
        // 0x807C30AC: nop
    
            goto L_807C30DC;
    }
    // 0x807C30AC: nop

    // 0x807C30B0: beq         $t0, $a2, L_807C30D4
    if (ctx->r8 == ctx->r6) {
        // 0x807C30B4: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_807C30D4;
    }
    // 0x807C30B4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x807C30B8: lhu         $v0, 0xC($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XC);
    // 0x807C30BC: beq         $t1, $v0, L_807C30CC
    if (ctx->r9 == ctx->r2) {
        // 0x807C30C0: nop
    
            goto L_807C30CC;
    }
    // 0x807C30C0: nop

    // 0x807C30C4: bnel        $t2, $v0, L_807C30D8
    if (ctx->r10 != ctx->r2) {
        // 0x807C30C8: sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5 << 16);
            goto L_807C30D8;
    }
    goto skip_7;
    // 0x807C30C8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    skip_7:
L_807C30CC:
    // 0x807C30CC: jr          $ra
    // 0x807C30D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x807C30D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807C30D4:
    // 0x807C30D4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
L_807C30D8:
    // 0x807C30D8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_807C30DC:
    // 0x807C30DC: bne         $a1, $zero, L_807C30A4
    if (ctx->r5 != 0) {
        // 0x807C30E0: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_807C30A4;
    }
    // 0x807C30E0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807C30E4: lh          $a1, 0x9A6($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X9A6);
L_807C30E8:
    // 0x807C30E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807C30EC: lw          $a0, 0x9B0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X9B0);
    // 0x807C30F0: beql        $a1, $zero, L_807C313C
    if (ctx->r5 == 0) {
        // 0x807C30F4: lh          $a1, 0x992($a3)
        ctx->r5 = MEM_H(ctx->r7, 0X992);
            goto L_807C313C;
    }
    goto skip_8;
    // 0x807C30F4: lh          $a1, 0x992($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X992);
    skip_8:
L_807C30F8:
    // 0x807C30F8: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x807C30FC: beq         $a2, $zero, L_807C3130
    if (ctx->r6 == 0) {
        // 0x807C3100: nop
    
            goto L_807C3130;
    }
    // 0x807C3100: nop

    // 0x807C3104: beq         $t0, $a2, L_807C3128
    if (ctx->r8 == ctx->r6) {
        // 0x807C3108: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_807C3128;
    }
    // 0x807C3108: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x807C310C: lhu         $v0, 0xC($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XC);
    // 0x807C3110: beq         $t1, $v0, L_807C3120
    if (ctx->r9 == ctx->r2) {
        // 0x807C3114: nop
    
            goto L_807C3120;
    }
    // 0x807C3114: nop

    // 0x807C3118: bnel        $t2, $v0, L_807C312C
    if (ctx->r10 != ctx->r2) {
        // 0x807C311C: sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5 << 16);
            goto L_807C312C;
    }
    goto skip_9;
    // 0x807C311C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    skip_9:
L_807C3120:
    // 0x807C3120: jr          $ra
    // 0x807C3124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x807C3124: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807C3128:
    // 0x807C3128: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
L_807C312C:
    // 0x807C312C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_807C3130:
    // 0x807C3130: bne         $a1, $zero, L_807C30F8
    if (ctx->r5 != 0) {
        // 0x807C3134: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_807C30F8;
    }
    // 0x807C3134: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807C3138: lh          $a1, 0x992($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X992);
L_807C313C:
    // 0x807C313C: lw          $a0, 0x99C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X99C);
    // 0x807C3140: beql        $a1, $zero, L_807C318C
    if (ctx->r5 == 0) {
        // 0x807C3144: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_807C318C;
    }
    goto skip_10;
    // 0x807C3144: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_10:
L_807C3148:
    // 0x807C3148: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x807C314C: beq         $a2, $zero, L_807C3180
    if (ctx->r6 == 0) {
        // 0x807C3150: nop
    
            goto L_807C3180;
    }
    // 0x807C3150: nop

    // 0x807C3154: beq         $t0, $a2, L_807C3178
    if (ctx->r8 == ctx->r6) {
        // 0x807C3158: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_807C3178;
    }
    // 0x807C3158: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x807C315C: lhu         $v0, 0xC($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XC);
    // 0x807C3160: beq         $t1, $v0, L_807C3170
    if (ctx->r9 == ctx->r2) {
        // 0x807C3164: nop
    
            goto L_807C3170;
    }
    // 0x807C3164: nop

    // 0x807C3168: bnel        $t2, $v0, L_807C317C
    if (ctx->r10 != ctx->r2) {
        // 0x807C316C: sll         $a1, $a1, 16
        ctx->r5 = S32(ctx->r5 << 16);
            goto L_807C317C;
    }
    goto skip_11;
    // 0x807C316C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    skip_11:
L_807C3170:
    // 0x807C3170: jr          $ra
    // 0x807C3174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x807C3174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807C3178:
    // 0x807C3178: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
L_807C317C:
    // 0x807C317C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_807C3180:
    // 0x807C3180: bne         $a1, $zero, L_807C3148
    if (ctx->r5 != 0) {
        // 0x807C3184: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_807C3148;
    }
    // 0x807C3184: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807C3188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807C318C:
    // 0x807C318C: jr          $ra
    // 0x807C3190: nop

    return;
    // 0x807C3190: nop

;}
RECOMP_FUNC void func_8045BF84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045BF84: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8045BF88: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8045BF8C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8045BF90: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8045BF94: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8045BF98: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8045BF9C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8045BFA0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8045BFA4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8045BFA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8045BFAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045BFB0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8045BFB4: lw          $s3, 0x8($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X8);
    // 0x8045BFB8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8045BFBC: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x8045BFC0: lw          $s2, 0x4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X4);
    // 0x8045BFC4: jal         0x80066DE4
    // 0x8045BFC8: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8045BFC8: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    after_0:
    // 0x8045BFCC: lwc1        $f4, 0x28($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X28);
    // 0x8045BFD0: lwc1        $f14, 0x0($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8045BFD4: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8045BFD8: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8045BFDC: add.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8045BFE0: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8045BFE4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8045BFE8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8045BFEC: mfc1        $s5, $f8
    ctx->r21 = (int32_t)ctx->f8.u32l;
    // 0x8045BFF0: mfc1        $s6, $f16
    ctx->r22 = (int32_t)ctx->f16.u32l;
    // 0x8045BFF4: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8045BFF8: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8045BFFC: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8045C000: jal         0x80066E88
    // 0x8045C004: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8045C004: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    after_1:
    // 0x8045C008: lwc1        $f18, 0x28($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X28);
    // 0x8045C00C: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8045C010: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8045C014: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8045C018: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x8045C01C: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x8045C020: sb          $s1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r17;
    // 0x8045C024: sb          $s1, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r17;
    // 0x8045C028: sb          $s1, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r17;
    // 0x8045C02C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8045C030: sb          $s1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r17;
    // 0x8045C034: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x8045C038: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8045C03C: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x8045C040: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8045C044: add.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8045C048: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8045C04C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8045C050: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8045C054: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // 0x8045C058: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x8045C05C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8045C060: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8045C064: sh          $s5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r21;
    // 0x8045C068: sh          $v1, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r3;
    // 0x8045C06C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8045C070: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8045C074: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8045C078: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8045C07C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8045C080: sh          $a0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r4;
    // 0x8045C084: sh          $a1, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r5;
    // 0x8045C088: sh          $t1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r9;
    // 0x8045C08C: sb          $s1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r17;
    // 0x8045C090: sb          $s1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r17;
    // 0x8045C094: sb          $s1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r17;
    // 0x8045C098: sb          $s1, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = ctx->r17;
    // 0x8045C09C: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x8045C0A0: sh          $zero, 0x16($s0)
    MEM_H(0X16, ctx->r16) = 0;
    // 0x8045C0A4: sh          $s6, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r22;
    // 0x8045C0A8: lw          $t2, 0x30($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X30);
    // 0x8045C0AC: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8045C0B0: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x8045C0B4: sltiu       $at, $t2, 0x2
    ctx->r1 = ctx->r10 < 0X2 ? 1 : 0;
    // 0x8045C0B8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8045C0BC: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x8045C0C0: bne         $at, $zero, L_8045C1D4
    if (ctx->r1 != 0) {
        // 0x8045C0C4: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_8045C1D4;
    }
    // 0x8045C0C4: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_8045C0C8:
    // 0x8045C0C8: jal         0x80066DE4
    // 0x8045C0CC: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8045C0CC: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    after_2:
    // 0x8045C0D0: lwc1        $f4, 0x28($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X28);
    // 0x8045C0D4: lwc1        $f14, 0x0($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8045C0D8: lwc1        $f12, 0x0($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8045C0DC: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8045C0E0: add.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8045C0E4: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8045C0E8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8045C0EC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8045C0F0: mfc1        $s5, $f8
    ctx->r21 = (int32_t)ctx->f8.u32l;
    // 0x8045C0F4: mfc1        $s6, $f16
    ctx->r22 = (int32_t)ctx->f16.u32l;
    // 0x8045C0F8: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8045C0FC: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x8045C100: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x8045C104: jal         0x80066E88
    // 0x8045C108: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8045C108: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    after_3:
    // 0x8045C10C: lwc1        $f18, 0x28($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X28);
    // 0x8045C110: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8045C114: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8045C118: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8045C11C: sll         $v0, $s7, 5
    ctx->r2 = S32(ctx->r23 << 5);
    // 0x8045C120: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x8045C124: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x8045C128: sb          $s1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r17;
    // 0x8045C12C: sb          $s1, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r17;
    // 0x8045C130: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8045C134: sb          $s1, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r17;
    // 0x8045C138: sb          $s1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r17;
    // 0x8045C13C: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8045C140: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x8045C144: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x8045C148: add.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8045C14C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8045C150: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8045C154: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8045C158: sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // 0x8045C15C: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x8045C160: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8045C164: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8045C168: sh          $s5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r21;
    // 0x8045C16C: sh          $v1, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r3;
    // 0x8045C170: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8045C174: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8045C178: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8045C17C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8045C180: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8045C184: sh          $a0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r4;
    // 0x8045C188: sh          $a1, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r5;
    // 0x8045C18C: sh          $t8, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r24;
    // 0x8045C190: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // 0x8045C194: sb          $s1, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = ctx->r17;
    // 0x8045C198: sb          $s1, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r17;
    // 0x8045C19C: sb          $s1, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r17;
    // 0x8045C1A0: sb          $s1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r17;
    // 0x8045C1A4: sh          $zero, 0x16($s0)
    MEM_H(0X16, ctx->r16) = 0;
    // 0x8045C1A8: sh          $s6, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r22;
    // 0x8045C1AC: lw          $t9, 0x30($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X30);
    // 0x8045C1B0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8045C1B4: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // 0x8045C1B8: sll         $s7, $s7, 16
    ctx->r23 = S32(ctx->r23 << 16);
    // 0x8045C1BC: sltu        $at, $fp, $t9
    ctx->r1 = ctx->r30 < ctx->r25 ? 1 : 0;
    // 0x8045C1C0: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8045C1C4: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // 0x8045C1C8: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8045C1CC: bne         $at, $zero, L_8045C0C8
    if (ctx->r1 != 0) {
        // 0x8045C1D0: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8045C0C8;
    }
    // 0x8045C1D0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8045C1D4:
    // 0x8045C1D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8045C1D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045C1DC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8045C1E0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8045C1E4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8045C1E8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8045C1EC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8045C1F0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8045C1F4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8045C1F8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8045C1FC: jr          $ra
    // 0x8045C200: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8045C200: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8004CFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CFE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004CFE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004CFEC: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004CFF0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8004CFF4: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004CFF8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004CFFC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004D000: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004D004: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004D008: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8004D00C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004D010: jal         0x8004C9F4
    // 0x8004D014: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8004C9F4(rdram, ctx);
        goto after_0;
    // 0x8004D014: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004D018: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8004D01C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004D020: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8004D024: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x8004D028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004D02C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004D030: jr          $ra
    // 0x8004D034: nop

    return;
    // 0x8004D034: nop

;}
RECOMP_FUNC void func_800007B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800007B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800007B4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800007B8: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x800007BC: addiu       $s5, $s5, 0x4D10
    ctx->r21 = ADD32(ctx->r21, 0X4D10);
    // 0x800007C0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800007C4: lh          $s4, 0x1D88($s5)
    ctx->r20 = MEM_H(ctx->r21, 0X1D88);
    // 0x800007C8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800007CC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800007D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800007D4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800007D8: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x800007DC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800007E0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800007E4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800007E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800007EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800007F0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800007F4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800007F8: blez        $s4, L_80000824
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800007FC: or          $fp, $a0, $zero
        ctx->r30 = ctx->r4 | 0;
            goto L_80000824;
    }
    // 0x800007FC: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
L_80000800:
    // 0x80000800: addiu       $s0, $s4, -0x1
    ctx->r16 = ADD32(ctx->r20, -0X1);
    // 0x80000804: jal         0x8001012C
    // 0x80000808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001012C(rdram, ctx);
        goto after_0;
    // 0x80000808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000080C: lh          $t6, 0x1D88($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X1D88);
    // 0x80000810: jal         0x80000724
    // 0x80000814: subu        $a0, $t6, $s4
    ctx->r4 = SUB32(ctx->r14, ctx->r20);
    func_80000724(rdram, ctx);
        goto after_1;
    // 0x80000814: subu        $a0, $t6, $s4
    ctx->r4 = SUB32(ctx->r14, ctx->r20);
    after_1:
    // 0x80000818: bgtz        $s0, L_80000800
    if (SIGNED(ctx->r16) > 0) {
        // 0x8000081C: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_80000800;
    }
    // 0x8000081C: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x80000820: lh          $s4, 0x1D88($s5)
    ctx->r20 = MEM_H(ctx->r21, 0X1D88);
L_80000824:
    // 0x80000824: or          $s7, $s1, $zero
    ctx->r23 = ctx->r17 | 0;
    // 0x80000828: blez        $s4, L_8000091C
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8000082C: sw          $zero, 0x10($s5)
        MEM_W(0X10, ctx->r21) = 0;
            goto L_8000091C;
    }
    // 0x8000082C: sw          $zero, 0x10($s5)
    MEM_W(0X10, ctx->r21) = 0;
L_80000830:
    // 0x80000830: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80000834: lh          $s2, 0x1D88($s5)
    ctx->r18 = MEM_H(ctx->r21, 0X1D88);
    // 0x80000838: bne         $s4, $at, L_80000848
    if (ctx->r20 != ctx->r1) {
        // 0x8000083C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80000848;
    }
    // 0x8000083C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80000840: b           L_800008A8
    // 0x80000844: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
        goto L_800008A8;
    // 0x80000844: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
L_80000848:
    // 0x80000848: div         $zero, $s6, $s4
    lo = S32(S64(S32(ctx->r22)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r22)) % S64(S32(ctx->r20)));
    // 0x8000084C: bne         $s4, $zero, L_80000858
    if (ctx->r20 != 0) {
        // 0x80000850: nop
    
            goto L_80000858;
    }
    // 0x80000850: nop

    // 0x80000854: break       7
    do_break(2147485780);
L_80000858:
    // 0x80000858: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000085C: bne         $s4, $at, L_80000870
    if (ctx->r20 != ctx->r1) {
        // 0x80000860: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80000870;
    }
    // 0x80000860: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80000864: bne         $s6, $at, L_80000870
    if (ctx->r22 != ctx->r1) {
        // 0x80000868: nop
    
            goto L_80000870;
    }
    // 0x80000868: nop

    // 0x8000086C: break       6
    do_break(2147485804);
L_80000870:
    // 0x80000870: lh          $v1, 0x1D8C($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X1D8C);
    // 0x80000874: mflo        $v0
    ctx->r2 = lo;
    // 0x80000878: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000087C: bnel        $at, $zero, L_80000890
    if (ctx->r1 != 0) {
        // 0x80000880: lh          $v1, 0x1D8E($s5)
        ctx->r3 = MEM_H(ctx->r21, 0X1D8E);
            goto L_80000890;
    }
    goto skip_0;
    // 0x80000880: lh          $v1, 0x1D8E($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X1D8E);
    skip_0:
    // 0x80000884: b           L_800008A8
    // 0x80000888: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
        goto L_800008A8;
    // 0x80000888: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x8000088C: lh          $v1, 0x1D8E($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X1D8E);
L_80000890:
    // 0x80000890: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80000894: bnel        $at, $zero, L_800008A8
    if (ctx->r1 != 0) {
        // 0x80000898: lh          $s3, 0x1D8A($s5)
        ctx->r19 = MEM_H(ctx->r21, 0X1D8A);
            goto L_800008A8;
    }
    goto skip_1;
    // 0x80000898: lh          $s3, 0x1D8A($s5)
    ctx->r19 = MEM_H(ctx->r21, 0X1D8A);
    skip_1:
    // 0x8000089C: b           L_800008A8
    // 0x800008A0: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
        goto L_800008A8;
    // 0x800008A0: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x800008A4: lh          $s3, 0x1D8A($s5)
    ctx->r19 = MEM_H(ctx->r21, 0X1D8A);
L_800008A8:
    // 0x800008A8: lb          $v0, 0x1($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X1);
    // 0x800008AC: blezl       $v0, L_800008F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800008B0: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_800008F4;
    }
    goto skip_2;
    // 0x800008B0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_2:
    // 0x800008B4: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800008B8: addiu       $s0, $s0, 0x4D10
    ctx->r16 = ADD32(ctx->r16, 0X4D10);
L_800008BC:
    // 0x800008BC: lbu         $t7, 0x19($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X19);
    // 0x800008C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800008C4: subu        $a1, $s2, $s4
    ctx->r5 = SUB32(ctx->r18, ctx->r20);
    // 0x800008C8: beql        $t7, $zero, L_800008E4
    if (ctx->r15 == 0) {
        // 0x800008CC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800008E4;
    }
    goto skip_3;
    // 0x800008CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x800008D0: jal         0x80000470
    // 0x800008D4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80000470(rdram, ctx);
        goto after_2;
    // 0x800008D4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x800008D8: lh          $s2, 0x1D88($s5)
    ctx->r18 = MEM_H(ctx->r21, 0X1D88);
    // 0x800008DC: lb          $v0, 0x1($s5)
    ctx->r2 = MEM_B(ctx->r21, 0X1);
    // 0x800008E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800008E4:
    // 0x800008E4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800008E8: bne         $at, $zero, L_800008BC
    if (ctx->r1 != 0) {
        // 0x800008EC: addiu       $s0, $s0, 0x158
        ctx->r16 = ADD32(ctx->r16, 0X158);
            goto L_800008BC;
    }
    // 0x800008EC: addiu       $s0, $s0, 0x158
    ctx->r16 = ADD32(ctx->r16, 0X158);
    // 0x800008F0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_800008F4:
    // 0x800008F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800008F8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800008FC: jal         0x800016A8
    // 0x80000900: subu        $a3, $s2, $s4
    ctx->r7 = SUB32(ctx->r18, ctx->r20);
    func_800016A8(rdram, ctx);
        goto after_3;
    // 0x80000900: subu        $a3, $s2, $s4
    ctx->r7 = SUB32(ctx->r18, ctx->r20);
    after_3:
    // 0x80000904: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80000908: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x8000090C: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80000910: subu        $s6, $s6, $s3
    ctx->r22 = SUB32(ctx->r22, ctx->r19);
    // 0x80000914: bgtz        $s4, L_80000830
    if (SIGNED(ctx->r20) > 0) {
        // 0x80000918: addu        $s7, $s7, $t8
        ctx->r23 = ADD32(ctx->r23, ctx->r24);
            goto L_80000830;
    }
    // 0x80000918: addu        $s7, $s7, $t8
    ctx->r23 = ADD32(ctx->r23, ctx->r24);
L_8000091C:
    // 0x8000091C: lb          $t9, 0x1($s5)
    ctx->r25 = MEM_B(ctx->r21, 0X1);
    // 0x80000920: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80000924: addiu       $s0, $s0, 0x4D10
    ctx->r16 = ADD32(ctx->r16, 0X4D10);
    // 0x80000928: blez        $t9, L_80000964
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8000092C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80000964;
    }
    // 0x8000092C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80000930: lbu         $v0, 0x1A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A);
L_80000934:
    // 0x80000934: beq         $v0, $zero, L_80000940
    if (ctx->r2 == 0) {
        // 0x80000938: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80000940;
    }
    // 0x80000938: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8000093C: sb          $t0, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r8;
L_80000940:
    // 0x80000940: lbu         $t1, 0x1B($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1B);
    // 0x80000944: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80000948: addiu       $s0, $s0, 0x158
    ctx->r16 = ADD32(ctx->r16, 0X158);
    // 0x8000094C: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x80000950: sb          $t2, -0x13D($s0)
    MEM_B(-0X13D, ctx->r16) = ctx->r10;
    // 0x80000954: lb          $t3, 0x1($s5)
    ctx->r11 = MEM_B(ctx->r21, 0X1);
    // 0x80000958: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8000095C: bnel        $at, $zero, L_80000934
    if (ctx->r1 != 0) {
        // 0x80000960: lbu         $v0, 0x1A($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X1A);
            goto L_80000934;
    }
    goto skip_4;
    // 0x80000960: lbu         $v0, 0x1A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1A);
    skip_4:
L_80000964:
    // 0x80000964: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80000968: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8000096C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80000970: subu        $t5, $fp, $t4
    ctx->r13 = SUB32(ctx->r30, ctx->r12);
    // 0x80000974: sra         $t6, $t5, 3
    ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80000978: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8000097C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80000980: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80000984: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80000988: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000098C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80000990: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000994: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000998: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000099C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800009A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800009A4: jr          $ra
    // 0x800009A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800009A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80665264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665264: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80665268: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x8066526C: lui         $t6, 0x8066
    ctx->r14 = S32(RELOC_HI16(504, 0X2B10) << 16);
    // 0x80665270: lw          $t6, 0x77E0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(504, 0X2B10));
    // 0x80665274: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80665278: sw          $t7, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r15;
    // 0x8066527C: sw          $zero, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = 0;
    // 0x80665280: jr          $ra
    // 0x80665284: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    return;
    // 0x80665284: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
;}
RECOMP_FUNC void func_8077FCDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FCDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8077FCE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077FCE4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8077FCE8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8077FCEC: beq         $v0, $zero, L_8077FCFC
    if (ctx->r2 == 0) {
        // 0x8077FCF0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8077FCFC;
    }
    // 0x8077FCF0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8077FCF4: b           L_8077FD2C
    // 0x8077FCF8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8077FD2C;
    // 0x8077FCF8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8077FCFC:
    // 0x8077FCFC: jal         0x8004700C
    // 0x8077FD00: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8077FD00: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8077FD04: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8077FD08: beq         $v0, $zero, L_8077FD2C
    if (ctx->r2 == 0) {
        // 0x8077FD0C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8077FD2C;
    }
    // 0x8077FD0C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8077FD10: lw          $t8, 0x1F4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1F4);
    // 0x8077FD14: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8077FD18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8077FD1C: sb          $t7, 0x1B4($t8)
    MEM_B(0X1B4, ctx->r24) = ctx->r15;
    // 0x8077FD20: lw          $t9, 0x260($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X260);
    // 0x8077FD24: jal         0x80062DD4
    // 0x8077FD28: lbu         $a0, 0x15($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X15);
    func_80062DD4(rdram, ctx);
        goto after_1;
    // 0x8077FD28: lbu         $a0, 0x15($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X15);
    after_1:
L_8077FD2C:
    // 0x8077FD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8077FD30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8077FD34: jr          $ra
    // 0x8077FD38: nop

    return;
    // 0x8077FD38: nop

;}
RECOMP_FUNC void func_80521498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8052149C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805214A0: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x805214A4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805214A8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805214AC: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(306, 0X23C) << 16);
    // 0x805214B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805214B4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805214B8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805214BC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805214C0: lw          $t8, 0x15FC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(306, 0X23C));
    // 0x805214C4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805214C8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805214CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805214D0: jal         0x80048490
    // 0x805214D4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805214D4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805214D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805214DC: jal         0x80048378
    // 0x805214E0: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x805214E0: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x805214E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805214E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805214EC: jr          $ra
    // 0x805214F0: nop

    return;
    // 0x805214F0: nop

;}
RECOMP_FUNC void func_804A1978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A197C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A1980: jal         0x804A1820
    // 0x804A1984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A1820(rdram, ctx);
        goto after_0;
    // 0x804A1984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A1988: bne         $v0, $zero, L_804A19C8
    if (ctx->r2 != 0) {
        // 0x804A198C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A19C8;
    }
    // 0x804A198C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A1990: jal         0x804A2910
    // 0x804A1994: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A2910(rdram, ctx);
        goto after_1;
    // 0x804A1994: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x804A1998: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A199C: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x804A19A0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804A19A4: slti        $at, $t7, 0x28
    ctx->r1 = SIGNED(ctx->r15) < 0X28 ? 1 : 0;
    // 0x804A19A8: bne         $at, $zero, L_804A19C8
    if (ctx->r1 != 0) {
        // 0x804A19AC: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_804A19C8;
    }
    // 0x804A19AC: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x804A19B0: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x804A19B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A19B8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x804A19BC: sb          $t0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r8;
    // 0x804A19C0: jal         0x804A27A0
    // 0x804A19C4: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    func_804A27A0(rdram, ctx);
        goto after_2;
    // 0x804A19C4: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
    after_2:
L_804A19C8:
    // 0x804A19C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A19CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A19D0: jr          $ra
    // 0x804A19D4: nop

    return;
    // 0x804A19D4: nop

;}
RECOMP_FUNC void func_8001C88C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C88C: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8001C890: lw          $v1, -0x76BC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X76BC);
    // 0x8001C894: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001C898: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001C89C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8001C8A0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001C8A4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001C8A8: lwc1        $f2, -0x6998($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6998);
    // 0x8001C8AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001C8B0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001C8B4: lwc1        $f4, -0x69A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X69A8);
    // 0x8001C8B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C8BC: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8001C8C0: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8001C8C4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001C8C8: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x8001C8CC: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8001C8D0: lw          $a2, 0x1F4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1F4);
    // 0x8001C8D4: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8001C8D8: lbu         $a3, 0x28($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X28);
    // 0x8001C8DC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001C8E0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8001C8E4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8001C8E8: jal         0x8001C748
    // 0x8001C8EC: sb          $a3, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r7;
    func_8001C748(rdram, ctx);
        goto after_0;
    // 0x8001C8EC: sb          $a3, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001C8F0: lbu         $a3, 0x1F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1F);
    // 0x8001C8F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001C8F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001C8FC: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001C900: beq         $a3, $at, L_8001C918
    if (ctx->r7 == ctx->r1) {
        // 0x8001C904: lwc1        $f2, 0x2C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8001C918;
    }
    // 0x8001C904: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001C908: jal         0x8001CBB8
    // 0x8001C90C: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    func_8001CBB8(rdram, ctx);
        goto after_1;
    // 0x8001C90C: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_1:
    // 0x8001C910: b           L_8001C954
    // 0x8001C914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001C954;
    // 0x8001C914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001C918:
    // 0x8001C918: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001C91C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001C920: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001C924: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001C928: nop

    // 0x8001C92C: bc1fl       L_8001C94C
    if (!c1cs) {
        // 0x8001C930: swc1        $f0, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
            goto L_8001C94C;
    }
    goto skip_0;
    // 0x8001C930: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x8001C934: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001C938: jal         0x8001CBB8
    // 0x8001C93C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_8001CBB8(rdram, ctx);
        goto after_2;
    // 0x8001C93C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8001C940: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001C944: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001C948: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
L_8001C94C:
    // 0x8001C94C: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x8001C950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001C954:
    // 0x8001C954: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001C958: jr          $ra
    // 0x8001C95C: nop

    return;
    // 0x8001C95C: nop

;}
RECOMP_FUNC void func_8005A71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A71C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005A720: lwc1        $f2, 0xBEC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XBEC);
    // 0x8005A724: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8005A728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A72C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005A730: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8005A734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A738: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005A73C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8005A740: sb          $a1, 0xA8($a0)
    MEM_B(0XA8, ctx->r4) = ctx->r5;
    // 0x8005A744: swc1        $f0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
    // 0x8005A748: swc1        $f0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f0.u32l;
    // 0x8005A74C: bc1t        L_8005A794
    if (c1cs) {
        // 0x8005A750: swc1        $f0, 0xB4($a0)
        MEM_W(0XB4, ctx->r4) = ctx->f0.u32l;
            goto L_8005A794;
    }
    // 0x8005A750: swc1        $f0, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f0.u32l;
    // 0x8005A754: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005A758: lwc1        $f0, 0xBF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XBF0);
    // 0x8005A75C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8005A760: nop

    // 0x8005A764: bc1tl       L_8005A798
    if (c1cs) {
        // 0x8005A768: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_8005A798;
    }
    goto skip_0;
    // 0x8005A768: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_0:
    // 0x8005A76C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8005A770: nop

    // 0x8005A774: bc1tl       L_8005A798
    if (c1cs) {
        // 0x8005A778: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_8005A798;
    }
    goto skip_1;
    // 0x8005A778: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_1:
    // 0x8005A77C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8005A780: nop

    // 0x8005A784: bc1tl       L_8005A798
    if (c1cs) {
        // 0x8005A788: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_8005A798;
    }
    goto skip_2;
    // 0x8005A788: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_2:
    // 0x8005A78C: b           L_8005A814
    // 0x8005A790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A814;
    // 0x8005A790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A794:
    // 0x8005A794: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_8005A798:
    // 0x8005A798: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005A79C: lwc1        $f0, 0xBF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XBF4);
    // 0x8005A7A0: bc1tl       L_8005A7BC
    if (c1cs) {
        // 0x8005A7A4: swc1        $f12, 0xAC($a0)
        MEM_W(0XAC, ctx->r4) = ctx->f12.u32l;
            goto L_8005A7BC;
    }
    goto skip_3;
    // 0x8005A7A4: swc1        $f12, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f12.u32l;
    skip_3:
    // 0x8005A7A8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8005A7AC: nop

    // 0x8005A7B0: bc1fl       L_8005A7C0
    if (!c1cs) {
        // 0x8005A7B4: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_8005A7C0;
    }
    goto skip_4;
    // 0x8005A7B4: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_4:
    // 0x8005A7B8: swc1        $f12, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f12.u32l;
L_8005A7BC:
    // 0x8005A7BC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_8005A7C0:
    // 0x8005A7C0: nop

    // 0x8005A7C4: bc1tl       L_8005A7E0
    if (c1cs) {
        // 0x8005A7C8: swc1        $f14, 0xB0($a0)
        MEM_W(0XB0, ctx->r4) = ctx->f14.u32l;
            goto L_8005A7E0;
    }
    goto skip_5;
    // 0x8005A7C8: swc1        $f14, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f14.u32l;
    skip_5:
    // 0x8005A7CC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8005A7D0: nop

    // 0x8005A7D4: bc1fl       L_8005A7E4
    if (!c1cs) {
        // 0x8005A7D8: lwc1        $f12, 0x0($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
            goto L_8005A7E4;
    }
    goto skip_6;
    // 0x8005A7D8: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    skip_6:
    // 0x8005A7DC: swc1        $f14, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f14.u32l;
L_8005A7E0:
    // 0x8005A7E0: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
L_8005A7E4:
    // 0x8005A7E4: lwc1        $f14, 0xAC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x8005A7E8: jal         0x80065388
    // 0x8005A7EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065388(rdram, ctx);
        goto after_0;
    // 0x8005A7EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005A7F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005A7F4: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8005A7F8: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8005A7FC: jal         0x80065388
    // 0x8005A800: lwc1        $f14, 0xB0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XB0);
    func_80065388(rdram, ctx);
        goto after_1;
    // 0x8005A800: lwc1        $f14, 0xB0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XB0);
    after_1:
    // 0x8005A804: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005A808: jal         0x8005A52C
    // 0x8005A80C: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    func_8005A52C(rdram, ctx);
        goto after_2;
    // 0x8005A80C: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x8005A810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A814:
    // 0x8005A814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A81C: jr          $ra
    // 0x8005A820: nop

    return;
    // 0x8005A820: nop

;}
RECOMP_FUNC void func_807B998C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B998C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B9990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9994: jal         0x807B8D30
    // 0x807B9998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807B8D30(rdram, ctx);
        goto after_0;
    // 0x807B9998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807B999C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x807B99A0: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x807B99A4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x807B99A8: addiu       $a0, $zero, 0x203
    ctx->r4 = ADD32(0, 0X203);
    // 0x807B99AC: lhu         $v0, 0xC($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0XC);
    // 0x807B99B0: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x807B99B4: bne         $t7, $at, L_807B9A10
    if (ctx->r15 != ctx->r1) {
        // 0x807B99B8: andi        $t3, $v0, 0x4000
        ctx->r11 = ctx->r2 & 0X4000;
            goto L_807B9A10;
    }
    // 0x807B99B8: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x807B99BC: jal         0x80067818
    // 0x807B99C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807B99C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807B99C4: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x807B99C8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B99CC: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x807B99D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B99D4: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x807B99D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B99DC: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x807B99E0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B99E4: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x807B99E8: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
    // 0x807B99EC: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B99F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807B99F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B99F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B99FC: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x807B9A00: jal         0x807B9E2C
    // 0x807B9A04: sw          $t1, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r9;
    func_807B9E2C(rdram, ctx);
        goto after_2;
    // 0x807B9A04: sw          $t1, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r9;
    after_2:
    // 0x807B9A08: b           L_807B9A60
    // 0x807B9A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807B9A60;
    // 0x807B9A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B9A10:
    // 0x807B9A10: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x807B9A14: bne         $t3, $at, L_807B9A5C
    if (ctx->r11 != ctx->r1) {
        // 0x807B9A18: addiu       $a0, $zero, 0x205
        ctx->r4 = ADD32(0, 0X205);
            goto L_807B9A5C;
    }
    // 0x807B9A18: addiu       $a0, $zero, 0x205
    ctx->r4 = ADD32(0, 0X205);
    // 0x807B9A1C: jal         0x80067818
    // 0x807B9A20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x807B9A20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x807B9A24: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x807B9A28: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9A2C: sb          $t4, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r12;
    // 0x807B9A30: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9A34: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x807B9A38: sb          $t5, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r13;
    // 0x807B9A3C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9A40: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x807B9A44: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    // 0x807B9A48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B9A4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B9A50: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B9A54: jal         0x807B9E2C
    // 0x807B9A58: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_807B9E2C(rdram, ctx);
        goto after_4;
    // 0x807B9A58: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
L_807B9A5C:
    // 0x807B9A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B9A60:
    // 0x807B9A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B9A64: jr          $ra
    // 0x807B9A68: nop

    return;
    // 0x807B9A68: nop

;}
RECOMP_FUNC void func_8002DC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DC30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DC34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DC38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002DC3C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DC40: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8002DC44: lbu         $a2, 0x27($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X27);
    // 0x8002DC48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002DC4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002DC50: jal         0x8002B9E4
    // 0x8002DC54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002DC54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002DC58: jal         0x80021E8C
    // 0x8002DC5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80021E8C(rdram, ctx);
        goto after_1;
    // 0x8002DC5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8002DC60: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DC64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002DC68: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x8002DC6C: sb          $t6, 0x1AD($v0)
    MEM_B(0X1AD, ctx->r2) = ctx->r14;
    // 0x8002DC70: sh          $t7, 0x1AE($v0)
    MEM_H(0X1AE, ctx->r2) = ctx->r15;
    // 0x8002DC74: sb          $zero, 0x21($v0)
    MEM_B(0X21, ctx->r2) = 0;
    // 0x8002DC78: sw          $zero, 0xE0($v0)
    MEM_W(0XE0, ctx->r2) = 0;
    // 0x8002DC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DC80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DC84: jr          $ra
    // 0x8002DC88: nop

    return;
    // 0x8002DC88: nop

;}
RECOMP_FUNC void func_80563D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80563D04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80563D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80563D0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80563D10: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80563D14: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80563D18: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80563D1C: jal         0x80563890
    // 0x80563D20: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80563890(rdram, ctx);
        goto after_0;
    // 0x80563D20: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x80563D24: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80563D28: jal         0x80563990
    // 0x80563D2C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80563990(rdram, ctx);
        goto after_1;
    // 0x80563D2C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80563D30: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80563D34: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80563D38: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80563D3C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80563D40: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80563D44: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x80563D48: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80563D4C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80563D50: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80563D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80563D58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80563D5C: jr          $ra
    // 0x80563D60: nop

    return;
    // 0x80563D60: nop

;}
RECOMP_FUNC void func_80742F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742F64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80742F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80742F6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80742F70: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80742F74: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80742F78: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80742F7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80742F80: lw          $v1, 0x6E68($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E68);
    // 0x80742F84: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80742F88: beql        $v1, $zero, L_80742FA4
    if (ctx->r3 == 0) {
        // 0x80742F8C: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80742FA4;
    }
    goto skip_0;
    // 0x80742F8C: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80742F90: jal         0x80742A34
    // 0x80742F94: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_80742A34(rdram, ctx);
        goto after_0;
    // 0x80742F94: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_0:
    // 0x80742F98: b           L_80742FC8
    // 0x80742F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80742FC8;
    // 0x80742F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80742FA0: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80742FA4:
    // 0x80742FA4: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80742FA8: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80742FAC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80742FB0: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80742FB4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80742FB8: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80742FBC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80742FC0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80742FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742FC8:
    // 0x80742FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80742FCC: jr          $ra
    // 0x80742FD0: nop

    return;
    // 0x80742FD0: nop

;}
RECOMP_FUNC void func_8052FB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052FB34: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8052FB38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8052FB3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8052FB40: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8052FB44: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(333, 0X2380) << 16);
    // 0x8052FB48: addiu       $t6, $t6, 0x140
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(333, 0X2380));
    // 0x8052FB4C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8052FB50: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8052FB54: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8052FB58: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8052FB5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8052FB60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8052FB64: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8052FB68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8052FB6C: jal         0x805300EC
    // 0x8052FB70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805300EC(rdram, ctx);
        goto after_0;
    // 0x8052FB70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8052FB74: lw          $t4, 0x16C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X16C);
    // 0x8052FB78: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(333, 0X324) << 16);
    // 0x8052FB7C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8052FB80: addiu       $t9, $t9, -0x1F1C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(333, 0X324));
    // 0x8052FB84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052FB88: jal         0x8052FB04
    // 0x8052FB8C: sw          $t9, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r25;
    func_8052FB04(rdram, ctx);
        goto after_1;
    // 0x8052FB8C: sw          $t9, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r25;
    after_1:
    // 0x8052FB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052FB94: jal         0x80045A34
    // 0x8052FB98: addiu       $a1, $zero, 0x11A0
    ctx->r5 = ADD32(0, 0X11A0);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x8052FB98: addiu       $a1, $zero, 0x11A0
    ctx->r5 = ADD32(0, 0X11A0);
    after_2:
    // 0x8052FB9C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8052FBA0: sh          $zero, 0x119E($v0)
    MEM_H(0X119E, ctx->r2) = 0;
    // 0x8052FBA4: lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XC);
    // 0x8052FBA8: addiu       $at, $zero, 0x41A8
    ctx->r1 = ADD32(0, 0X41A8);
    // 0x8052FBAC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8052FBB0: beq         $v1, $at, L_8052FBDC
    if (ctx->r3 == ctx->r1) {
        // 0x8052FBB4: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8052FBDC;
    }
    // 0x8052FBB4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8052FBB8: addiu       $at, $zero, 0x41A9
    ctx->r1 = ADD32(0, 0X41A9);
    // 0x8052FBBC: beq         $v1, $at, L_8052FC48
    if (ctx->r3 == ctx->r1) {
        // 0x8052FBC0: addiu       $at, $zero, 0x41AA
        ctx->r1 = ADD32(0, 0X41AA);
            goto L_8052FC48;
    }
    // 0x8052FBC0: addiu       $at, $zero, 0x41AA
    ctx->r1 = ADD32(0, 0X41AA);
    // 0x8052FBC4: beq         $v1, $at, L_8052FCB4
    if (ctx->r3 == ctx->r1) {
        // 0x8052FBC8: addiu       $at, $zero, 0x41AB
        ctx->r1 = ADD32(0, 0X41AB);
            goto L_8052FCB4;
    }
    // 0x8052FBC8: addiu       $at, $zero, 0x41AB
    ctx->r1 = ADD32(0, 0X41AB);
    // 0x8052FBCC: beql        $v1, $at, L_8052FD30
    if (ctx->r3 == ctx->r1) {
        // 0x8052FBD0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8052FD30;
    }
    goto skip_0;
    // 0x8052FBD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8052FBD4: b           L_8052FD94
    // 0x8052FBD8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
        goto L_8052FD94;
    // 0x8052FBD8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_8052FBDC:
    // 0x8052FBDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052FBE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052FBE4: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    // 0x8052FBE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052FBEC: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2460) << 16);
    // 0x8052FBF0: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8052FBF4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8052FBF8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8052FBFC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8052FC00: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8052FC04: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8052FC08: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8052FC0C: swc1        $f8, 0xF68($v0)
    MEM_W(0XF68, ctx->r2) = ctx->f8.u32l;
    // 0x8052FC10: lwc1        $f10, 0x220($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2460));
    // 0x8052FC14: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2464) << 16);
    // 0x8052FC18: swc1        $f10, 0x1158($v0)
    MEM_W(0X1158, ctx->r2) = ctx->f10.u32l;
    // 0x8052FC1C: lwc1        $f16, 0x224($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2464));
    // 0x8052FC20: swc1        $f16, 0x115C($v0)
    MEM_W(0X115C, ctx->r2) = ctx->f16.u32l;
    // 0x8052FC24: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8052FC28: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8052FC2C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8052FC30: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8052FC34: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8052FC38: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8052FC3C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8052FC40: b           L_8052FD94
    // 0x8052FC44: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_8052FD94;
    // 0x8052FC44: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8052FC48:
    // 0x8052FC48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052FC4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8052FC50: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    // 0x8052FC54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052FC58: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2468) << 16);
    // 0x8052FC5C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8052FC60: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8052FC64: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x8052FC68: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8052FC6C: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x8052FC70: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8052FC74: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8052FC78: swc1        $f6, 0xF68($v0)
    MEM_W(0XF68, ctx->r2) = ctx->f6.u32l;
    // 0x8052FC7C: lwc1        $f8, 0x228($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2468));
    // 0x8052FC80: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X246C) << 16);
    // 0x8052FC84: swc1        $f8, 0x1158($v0)
    MEM_W(0X1158, ctx->r2) = ctx->f8.u32l;
    // 0x8052FC88: lwc1        $f10, 0x22C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X246C));
    // 0x8052FC8C: swc1        $f10, 0x115C($v0)
    MEM_W(0X115C, ctx->r2) = ctx->f10.u32l;
    // 0x8052FC90: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8052FC94: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x8052FC98: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8052FC9C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8052FCA0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8052FCA4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8052FCA8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8052FCAC: b           L_8052FD94
    // 0x8052FCB0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
        goto L_8052FD94;
    // 0x8052FCB0: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8052FCB4:
    // 0x8052FCB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052FCB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8052FCBC: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    // 0x8052FCC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8052FCC4: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2470) << 16);
    // 0x8052FCC8: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8052FCCC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8052FCD0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8052FCD4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8052FCD8: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8052FCDC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8052FCE0: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8052FCE4: swc1        $f4, 0xF68($v0)
    MEM_W(0XF68, ctx->r2) = ctx->f4.u32l;
    // 0x8052FCE8: lwc1        $f6, 0x230($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2470));
    // 0x8052FCEC: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2474) << 16);
    // 0x8052FCF0: swc1        $f6, 0x1158($v0)
    MEM_W(0X1158, ctx->r2) = ctx->f6.u32l;
    // 0x8052FCF4: lwc1        $f8, 0x234($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2474));
    // 0x8052FCF8: swc1        $f8, 0x115C($v0)
    MEM_W(0X115C, ctx->r2) = ctx->f8.u32l;
    // 0x8052FCFC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8052FD00: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8052FD04: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8052FD08: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8052FD0C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8052FD10: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8052FD14: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8052FD18: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8052FD1C: lhu         $t8, 0x119E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X119E);
    // 0x8052FD20: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8052FD24: b           L_8052FD94
    // 0x8052FD28: sh          $t9, 0x119E($v0)
    MEM_H(0X119E, ctx->r2) = ctx->r25;
        goto L_8052FD94;
    // 0x8052FD28: sh          $t9, 0x119E($v0)
    MEM_H(0X119E, ctx->r2) = ctx->r25;
    // 0x8052FD2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8052FD30:
    // 0x8052FD30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8052FD34: lui         $at, 0x3C80
    ctx->r1 = S32(0X3C80 << 16);
    // 0x8052FD38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8052FD3C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2478) << 16);
    // 0x8052FD40: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x8052FD44: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8052FD48: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8052FD4C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8052FD50: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8052FD54: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8052FD58: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x8052FD5C: swc1        $f18, 0xF68($v0)
    MEM_W(0XF68, ctx->r2) = ctx->f18.u32l;
    // 0x8052FD60: lwc1        $f4, 0x238($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2478));
    // 0x8052FD64: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X247C) << 16);
    // 0x8052FD68: swc1        $f4, 0x1158($v0)
    MEM_W(0X1158, ctx->r2) = ctx->f4.u32l;
    // 0x8052FD6C: lwc1        $f6, 0x23C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X247C));
    // 0x8052FD70: swc1        $f6, 0x115C($v0)
    MEM_W(0X115C, ctx->r2) = ctx->f6.u32l;
    // 0x8052FD74: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8052FD78: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8052FD7C: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8052FD80: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8052FD84: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8052FD88: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8052FD8C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8052FD90: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_8052FD94:
    // 0x8052FD94: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x8052FD98: addiu       $t4, $zero, 0x29
    ctx->r12 = ADD32(0, 0X29);
    // 0x8052FD9C: sw          $t9, 0x1160($v0)
    MEM_W(0X1160, ctx->r2) = ctx->r25;
    // 0x8052FDA0: sw          $t4, 0x1164($v0)
    MEM_W(0X1164, ctx->r2) = ctx->r12;
    // 0x8052FDA4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8052FDA8: addiu       $t2, $zero, 0xF60
    ctx->r10 = ADD32(0, 0XF60);
L_8052FDAC:
    // 0x8052FDAC: lw          $t5, 0x1164($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1164);
    // 0x8052FDB0: addiu       $t0, $t0, 0x520
    ctx->r8 = ADD32(ctx->r8, 0X520);
    // 0x8052FDB4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8052FDB8: blez        $t5, L_8052FE68
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8052FDBC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8052FE68;
    }
    // 0x8052FDBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8052FDC0: sll         $a2, $t3, 2
    ctx->r6 = S32(ctx->r11 << 2);
    // 0x8052FDC4: subu        $a2, $a2, $t3
    ctx->r6 = SUB32(ctx->r6, ctx->r11);
    // 0x8052FDC8: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x8052FDCC: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x8052FDD0: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8052FDD4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x8052FDD8: addiu       $a0, $zero, -0x1F40
    ctx->r4 = ADD32(0, -0X1F40);
    // 0x8052FDDC: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
L_8052FDE0:
    // 0x8052FDE0: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x8052FDE4: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x8052FDE8: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x8052FDEC: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x8052FDF0: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x8052FDF4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8052FDF8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8052FDFC: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8052FE00: sb          $t6, -0x14($v1)
    MEM_B(-0X14, ctx->r3) = ctx->r14;
    // 0x8052FE04: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8052FE08: sb          $t7, -0x13($v1)
    MEM_B(-0X13, ctx->r3) = ctx->r15;
    // 0x8052FE0C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8052FE10: sb          $t8, -0x12($v1)
    MEM_B(-0X12, ctx->r3) = ctx->r24;
    // 0x8052FE14: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8052FE18: sh          $zero, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = 0;
    // 0x8052FE1C: sh          $zero, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = 0;
    // 0x8052FE20: sh          $zero, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = 0;
    // 0x8052FE24: sh          $zero, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = 0;
    // 0x8052FE28: sh          $a2, -0xE($v1)
    MEM_H(-0XE, ctx->r3) = ctx->r6;
    // 0x8052FE2C: sh          $a0, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r4;
    // 0x8052FE30: sb          $t9, -0x11($v1)
    MEM_B(-0X11, ctx->r3) = ctx->r25;
    // 0x8052FE34: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8052FE38: addiu       $a0, $a0, 0x190
    ctx->r4 = ADD32(ctx->r4, 0X190);
    // 0x8052FE3C: sb          $t4, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r12;
    // 0x8052FE40: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8052FE44: sb          $t5, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r13;
    // 0x8052FE48: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8052FE4C: sb          $t6, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r14;
    // 0x8052FE50: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8052FE54: sb          $t7, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r15;
    // 0x8052FE58: lw          $t8, 0x1164($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X1164);
    // 0x8052FE5C: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8052FE60: bnel        $at, $zero, L_8052FDE0
    if (ctx->r1 != 0) {
        // 0x8052FE64: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_8052FDE0;
    }
    goto skip_1;
    // 0x8052FE64: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    skip_1:
L_8052FE68:
    // 0x8052FE68: bne         $t0, $t2, L_8052FDAC
    if (ctx->r8 != ctx->r10) {
        // 0x8052FE6C: addiu       $t1, $t1, 0x520
        ctx->r9 = ADD32(ctx->r9, 0X520);
            goto L_8052FDAC;
    }
    // 0x8052FE6C: addiu       $t1, $t1, 0x520
    ctx->r9 = ADD32(ctx->r9, 0X520);
    // 0x8052FE70: jal         0x8052FAAC
    // 0x8052FE74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8052FAAC(rdram, ctx);
        goto after_3;
    // 0x8052FE74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8052FE78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8052FE7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8052FE80: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8052FE84: jr          $ra
    // 0x8052FE88: nop

    return;
    // 0x8052FE88: nop

;}
RECOMP_FUNC void func_8002BC6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BC6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002BC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BC74: jal         0x8002BC1C
    // 0x8002BC78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002BC1C(rdram, ctx);
        goto after_0;
    // 0x8002BC78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002BC7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002BC80: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002BC84: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8002BC88: addiu       $t7, $t7, 0x1AE4
    ctx->r15 = ADD32(ctx->r15, 0X1AE4);
    // 0x8002BC8C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8002BC90: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8002BC94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BC98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002BC9C: jr          $ra
    // 0x8002BCA0: nop

    return;
    // 0x8002BCA0: nop

;}
RECOMP_FUNC void func_800421B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800421B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800421B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800421BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800421C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800421C4: jal         0x80042148
    // 0x800421C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80042148(rdram, ctx);
        goto after_0;
    // 0x800421C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800421CC: bne         $v0, $zero, L_800421DC
    if (ctx->r2 != 0) {
        // 0x800421D0: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_800421DC;
    }
    // 0x800421D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800421D4: b           L_8004227C
    // 0x800421D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004227C;
    // 0x800421D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800421DC:
    // 0x800421DC: lbu         $t6, 0xDD($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XDD);
    // 0x800421E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800421E4: bnel        $v1, $t6, L_8004227C
    if (ctx->r3 != ctx->r14) {
        // 0x800421E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004227C;
    }
    goto skip_0;
    // 0x800421E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800421EC: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    // 0x800421F0: lw          $v0, 0x178($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X178);
    // 0x800421F4: bnel        $v1, $t7, L_8004227C
    if (ctx->r3 != ctx->r15) {
        // 0x800421F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004227C;
    }
    goto skip_1;
    // 0x800421F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x800421FC: beq         $v0, $zero, L_80042278
    if (ctx->r2 == 0) {
        // 0x80042200: slti        $at, $v0, 0x8
        ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_80042278;
    }
    // 0x80042200: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80042204: bne         $at, $zero, L_8004222C
    if (ctx->r1 != 0) {
        // 0x80042208: sw          $zero, 0x178($a1)
        MEM_W(0X178, ctx->r5) = 0;
            goto L_8004222C;
    }
    // 0x80042208: sw          $zero, 0x178($a1)
    MEM_W(0X178, ctx->r5) = 0;
    // 0x8004220C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80042210: jal         0x80021A44
    // 0x80042214: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80021A44(rdram, ctx);
        goto after_1;
    // 0x80042214: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80042218: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004221C: jal         0x8002F364
    // 0x80042220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002F364(rdram, ctx);
        goto after_2;
    // 0x80042220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80042224: b           L_8004227C
    // 0x80042228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004227C;
    // 0x80042228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004222C:
    // 0x8004222C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80042230: bne         $at, $zero, L_80042254
    if (ctx->r1 != 0) {
        // 0x80042234: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80042254;
    }
    // 0x80042234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80042238: jal         0x80021A44
    // 0x8004223C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80021A44(rdram, ctx);
        goto after_3;
    // 0x8004223C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_3:
    // 0x80042240: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80042244: jal         0x8002F318
    // 0x80042248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002F318(rdram, ctx);
        goto after_4;
    // 0x80042248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8004224C: b           L_8004227C
    // 0x80042250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004227C;
    // 0x80042250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80042254:
    // 0x80042254: bgez        $v0, L_80042278
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80042258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80042278;
    }
    // 0x80042258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004225C: jal         0x80021A44
    // 0x80042260: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80021A44(rdram, ctx);
        goto after_5;
    // 0x80042260: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_5:
    // 0x80042264: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80042268: jal         0x8002F3B0
    // 0x8004226C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002F3B0(rdram, ctx);
        goto after_6;
    // 0x8004226C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80042270: b           L_8004227C
    // 0x80042274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004227C;
    // 0x80042274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80042278:
    // 0x80042278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004227C:
    // 0x8004227C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042280: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80042284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042288: jr          $ra
    // 0x8004228C: nop

    return;
    // 0x8004228C: nop

;}
RECOMP_FUNC void func_806AF2BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AF2BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806AF2C0: jr          $ra
    // 0x806AF2C4: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x806AF2C4: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80671D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671D4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80671D50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80671D54: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80671D58: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80671D5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80671D60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80671D64: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80671D68: lw          $s3, 0x0($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X0);
    // 0x80671D6C: addiu       $t7, $zero, 0x70
    ctx->r15 = ADD32(0, 0X70);
    // 0x80671D70: lw          $t8, 0x1E0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1E0);
    // 0x80671D74: sll         $t6, $s3, 4
    ctx->r14 = S32(ctx->r19 << 4);
    // 0x80671D78: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80671D7C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80671D80: sw          $t9, 0x1E0($v0)
    MEM_W(0X1E0, ctx->r2) = ctx->r25;
    // 0x80671D84: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80671D88: subu        $s1, $t7, $t6
    ctx->r17 = SUB32(ctx->r15, ctx->r14);
    // 0x80671D8C: lw          $t0, 0x1E0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1E0);
    // 0x80671D90: slti        $at, $t0, 0x14
    ctx->r1 = SIGNED(ctx->r8) < 0X14 ? 1 : 0;
    // 0x80671D94: bne         $at, $zero, L_80671DA0
    if (ctx->r1 != 0) {
        // 0x80671D98: nop
    
            goto L_80671DA0;
    }
    // 0x80671D98: nop

    // 0x80671D9C: sw          $zero, 0x1E0($v0)
    MEM_W(0X1E0, ctx->r2) = 0;
L_80671DA0:
    // 0x80671DA0: blez        $s3, L_80671DC4
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80671DA4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80671DC4;
    }
    // 0x80671DA4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80671DA8:
    // 0x80671DA8: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    // 0x80671DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80671DB0: jal         0x80671C98
    // 0x80671DB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80671C98(rdram, ctx);
        goto after_0;
    // 0x80671DB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x80671DB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80671DBC: bne         $s0, $s3, L_80671DA8
    if (ctx->r16 != ctx->r19) {
        // 0x80671DC0: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80671DA8;
    }
    // 0x80671DC0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80671DC4:
    // 0x80671DC4: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    // 0x80671DC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80671DCC: lw          $t1, 0x1E0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1E0);
    // 0x80671DD0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80671DD4: sw          $t2, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r10;
    // 0x80671DD8: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    // 0x80671DDC: lw          $t3, 0x1E0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1E0);
    // 0x80671DE0: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x80671DE4: bne         $at, $zero, L_80671DF4
    if (ctx->r1 != 0) {
        // 0x80671DE8: nop
    
            goto L_80671DF4;
    }
    // 0x80671DE8: nop

    // 0x80671DEC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80671DF0: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
L_80671DF4:
    // 0x80671DF4: jal         0x80671BE4
    // 0x80671DF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80671BE4(rdram, ctx);
        goto after_1;
    // 0x80671DF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80671DFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80671E00: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80671E04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80671E08: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80671E0C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80671E10: jr          $ra
    // 0x80671E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80671E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80715B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80715B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80715B78: jal         0x80714914
    // 0x80715B7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80714914(rdram, ctx);
        goto after_0;
    // 0x80715B7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80715B80: jal         0x80045BD8
    // 0x80715B84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80715B84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80715B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80715B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80715B90: jr          $ra
    // 0x80715B94: nop

    return;
    // 0x80715B94: nop

;}
RECOMP_FUNC void func_80536204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536204: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536208: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053620C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536210: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536214: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536218: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053621C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536220: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536224: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536228: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053622C: jr          $ra
    // 0x80536230: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536230: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void ViMode_ConfigureFeatures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EAC8: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8007EACC: beq         $t6, $zero, L_8007EAD8
    if (ctx->r14 == 0) {
        // 0x8007EAD0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_8007EAD8;
    }
    // 0x8007EAD0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007EAD4: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
L_8007EAD8:
    // 0x8007EAD8: andi        $t7, $a1, 0x2
    ctx->r15 = ctx->r5 & 0X2;
    // 0x8007EADC: beq         $t7, $zero, L_8007EAEC
    if (ctx->r15 == 0) {
        // 0x8007EAE0: andi        $t8, $a1, 0x4
        ctx->r24 = ctx->r5 & 0X4;
            goto L_8007EAEC;
    }
    // 0x8007EAE0: andi        $t8, $a1, 0x4
    ctx->r24 = ctx->r5 & 0X4;
    // 0x8007EAE4: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007EAE8: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
L_8007EAEC:
    // 0x8007EAEC: beq         $t8, $zero, L_8007EAF8
    if (ctx->r24 == 0) {
        // 0x8007EAF0: andi        $t9, $a1, 0x8
        ctx->r25 = ctx->r5 & 0X8;
            goto L_8007EAF8;
    }
    // 0x8007EAF0: andi        $t9, $a1, 0x8
    ctx->r25 = ctx->r5 & 0X8;
    // 0x8007EAF4: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
L_8007EAF8:
    // 0x8007EAF8: beq         $t9, $zero, L_8007EB08
    if (ctx->r25 == 0) {
        // 0x8007EAFC: andi        $t0, $a1, 0x10
        ctx->r8 = ctx->r5 & 0X10;
            goto L_8007EB08;
    }
    // 0x8007EAFC: andi        $t0, $a1, 0x10
    ctx->r8 = ctx->r5 & 0X10;
    // 0x8007EB00: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x8007EB04: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
L_8007EB08:
    // 0x8007EB08: beq         $t0, $zero, L_8007EB14
    if (ctx->r8 == 0) {
        // 0x8007EB0C: andi        $t1, $a1, 0x20
        ctx->r9 = ctx->r5 & 0X20;
            goto L_8007EB14;
    }
    // 0x8007EB0C: andi        $t1, $a1, 0x20
    ctx->r9 = ctx->r5 & 0X20;
    // 0x8007EB10: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
L_8007EB14:
    // 0x8007EB14: beq         $t1, $zero, L_8007EB20
    if (ctx->r9 == 0) {
        // 0x8007EB18: addiu       $at, $zero, -0x11
        ctx->r1 = ADD32(0, -0X11);
            goto L_8007EB20;
    }
    // 0x8007EB18: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x8007EB1C: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
L_8007EB20:
    // 0x8007EB20: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8007EB24: jr          $ra
    // 0x8007EB28: nop

    return;
    // 0x8007EB28: nop

;}
RECOMP_FUNC void func_8057C5F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C5F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057C5FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C600: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8057C604: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8057C608: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(387, 0XE90) << 16);
    // 0x8057C60C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8057C610: addiu       $t7, $t7, -0x3660
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(387, 0XE90));
    // 0x8057C614: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8057C618: lui         $t9, 0x8058
    ctx->r25 = S32(RELOC_HI16(387, 0XAC0) << 16);
    // 0x8057C61C: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8057C620: addiu       $t9, $t9, -0x3A30
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(387, 0XAC0));
    // 0x8057C624: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8057C628: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x8057C62C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8057C630: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x8057C634: sh          $t0, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r8;
    // 0x8057C638: jal         0x8057C5B8
    // 0x8057C63C: sw          $t1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r9;
    func_8057C5B8(rdram, ctx);
        goto after_0;
    // 0x8057C63C: sw          $t1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r9;
    after_0:
    // 0x8057C640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C644: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8057C648: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8057C64C: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x8057C650: jr          $ra
    // 0x8057C654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8057C654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80566D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566D2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80566D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566D34: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80566D38: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x80566D3C: addiu       $a2, $zero, 0x417C
    ctx->r6 = ADD32(0, 0X417C);
    // 0x80566D40: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80566D44: beq         $v1, $zero, L_80566D54
    if (ctx->r3 == 0) {
        // 0x80566D48: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80566D54;
    }
    // 0x80566D48: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80566D4C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80566D50: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80566D54:
    // 0x80566D54: bne         $v1, $zero, L_80566D78
    if (ctx->r3 != 0) {
        // 0x80566D58: nop
    
            goto L_80566D78;
    }
    // 0x80566D58: nop

    // 0x80566D5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80566D60: jal         0x8056698C
    // 0x80566D64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8056698C(rdram, ctx);
        goto after_0;
    // 0x80566D64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80566D68: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80566D6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80566D70: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80566D74: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80566D78:
    // 0x80566D78: jal         0x80566674
    // 0x80566D7C: nop

    func_80566674(rdram, ctx);
        goto after_1;
    // 0x80566D7C: nop

    after_1:
    // 0x80566D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566D84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80566D88: jr          $ra
    // 0x80566D8C: nop

    return;
    // 0x80566D8C: nop

;}
RECOMP_FUNC void func_80432E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432E48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80432E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80432E50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80432E54: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80432E58: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80432E5C: beql        $a1, $at, L_80432E94
    if (ctx->r5 == ctx->r1) {
        // 0x80432E60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80432E94;
    }
    goto skip_0;
    // 0x80432E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80432E64: jal         0x80067930
    // 0x80432E68: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80432E68: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_0:
    // 0x80432E6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80432E70: bne         $v0, $at, L_80432E84
    if (ctx->r2 != ctx->r1) {
        // 0x80432E74: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80432E84;
    }
    // 0x80432E74: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80432E78: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x80432E7C: jal         0x80067878
    // 0x80432E80: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80432E80: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    after_1:
L_80432E84:
    // 0x80432E84: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80432E88: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80432E8C: sh          $t8, 0x1F0($t9)
    MEM_H(0X1F0, ctx->r25) = ctx->r24;
    // 0x80432E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80432E94:
    // 0x80432E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80432E98: jr          $ra
    // 0x80432E9C: nop

    return;
    // 0x80432E9C: nop

;}
RECOMP_FUNC void func_8073A9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073A9BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8073A9C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073A9C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073A9C8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8073A9CC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073A9D0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1F44) << 16);
    // 0x8073A9D4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8073A9D8: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x8073A9DC: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x8073A9E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8073A9E4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8073A9E8: lwc1        $f4, -0x468C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1F44));
    // 0x8073A9EC: swc1        $f4, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f4.u32l;
    // 0x8073A9F0: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8073A9F4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8073A9F8: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8073A9FC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8073AA00: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8073AA04: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8073AA08: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8073AA0C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8073AA10: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8073AA14: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8073AA18: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8073AA1C: jal         0x8073A604
    // 0x8073AA20: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    func_8073A604(rdram, ctx);
        goto after_0;
    // 0x8073AA20: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_0:
    // 0x8073AA24: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8073AA28: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8073AA2C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8073AA30: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    // 0x8073AA34: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8073AA38: nop

    // 0x8073AA3C: bc1fl       L_8073AA4C
    if (!c1cs) {
        // 0x8073AA40: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8073AA4C;
    }
    goto skip_0;
    // 0x8073AA40: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x8073AA44: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8073AA48: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8073AA4C:
    // 0x8073AA4C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8073AA50: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8073AA54: nop

    // 0x8073AA58: bc1fl       L_8073AA68
    if (!c1cs) {
        // 0x8073AA5C: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8073AA68;
    }
    goto skip_1;
    // 0x8073AA5C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8073AA60: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x8073AA64: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
L_8073AA68:
    // 0x8073AA68: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x8073AA6C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8073AA70: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8073AA74: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8073AA78: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8073AA7C: nop

    // 0x8073AA80: beq         $t5, $t6, L_8073AA98
    if (ctx->r13 == ctx->r14) {
        // 0x8073AA84: sw          $t5, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r13;
            goto L_8073AA98;
    }
    // 0x8073AA84: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x8073AA88: jal         0x80067818
    // 0x8073AA8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8073AA8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8073AA90: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8073AA94: nop

L_8073AA98:
    // 0x8073AA98: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8073AA9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8073AAA0: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8073AAA4: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    // 0x8073AAA8: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8073AAAC: nop

    // 0x8073AAB0: bc1fl       L_8073AAC0
    if (!c1cs) {
        // 0x8073AAB4: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8073AAC0;
    }
    goto skip_2;
    // 0x8073AAB4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_2:
    // 0x8073AAB8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8073AABC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
L_8073AAC0:
    // 0x8073AAC0: nop

    // 0x8073AAC4: bc1fl       L_8073AAD4
    if (!c1cs) {
        // 0x8073AAC8: trunc.w.s   $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_8073AAD4;
    }
    goto skip_3;
    // 0x8073AAC8: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_3:
    // 0x8073AACC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8073AAD0: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
L_8073AAD4:
    // 0x8073AAD4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8073AAD8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8073AADC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8073AAE0: nop

    // 0x8073AAE4: beq         $t8, $t0, L_8073AAFC
    if (ctx->r24 == ctx->r8) {
        // 0x8073AAE8: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_8073AAFC;
    }
    // 0x8073AAE8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8073AAEC: jal         0x80067818
    // 0x8073AAF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8073AAF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8073AAF4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8073AAF8: nop

L_8073AAFC:
    // 0x8073AAFC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8073AB00: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x8073AB04: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8073AB08: beql        $at, $zero, L_8073ABB8
    if (ctx->r1 == 0) {
        // 0x8073AB0C: lw          $v1, 0xC($s0)
        ctx->r3 = MEM_W(ctx->r16, 0XC);
            goto L_8073ABB8;
    }
    goto skip_4;
    // 0x8073AB0C: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    skip_4:
    // 0x8073AB10: lw          $t2, 0x7EA8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7EA8);
    // 0x8073AB14: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8073AB18: lhu         $v0, 0xC($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XC);
    // 0x8073AB1C: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x8073AB20: bne         $t3, $at, L_8073AB50
    if (ctx->r11 != ctx->r1) {
        // 0x8073AB24: andi        $t5, $v0, 0x4000
        ctx->r13 = ctx->r2 & 0X4000;
            goto L_8073AB50;
    }
    // 0x8073AB24: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
    // 0x8073AB28: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    // 0x8073AB2C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8073AB30: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x8073AB34: beql        $at, $zero, L_8073AB74
    if (ctx->r1 == 0) {
        // 0x8073AB38: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_8073AB74;
    }
    goto skip_5;
    // 0x8073AB38: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_5:
    // 0x8073AB3C: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x8073AB40: jal         0x8073B8CC
    // 0x8073AB44: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8073B8CC(rdram, ctx);
        goto after_3;
    // 0x8073AB44: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x8073AB48: b           L_8073AB74
    // 0x8073AB4C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
        goto L_8073AB74;
    // 0x8073AB4C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_8073AB50:
    // 0x8073AB50: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x8073AB54: bnel        $t5, $at, L_8073AB74
    if (ctx->r13 != ctx->r1) {
        // 0x8073AB58: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_8073AB74;
    }
    goto skip_6;
    // 0x8073AB58: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
    // 0x8073AB5C: jal         0x8073A940
    // 0x8073AB60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073A940(rdram, ctx);
        goto after_4;
    // 0x8073AB60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8073AB64: addiu       $a0, $zero, 0x205
    ctx->r4 = ADD32(0, 0X205);
    // 0x8073AB68: jal         0x80067818
    // 0x8073AB6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x8073AB6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8073AB70: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_8073AB74:
    // 0x8073AB74: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1EC0) << 16);
    // 0x8073AB78: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x8073AB7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8073AB80: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8073AB84: lwc1        $f18, -0x4710($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1EC0));
    // 0x8073AB88: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1EF4) << 16);
    // 0x8073AB8C: swc1        $f18, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f18.u32l;
    // 0x8073AB90: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8073AB94: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x8073AB98: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8073AB9C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8073ABA0: lwc1        $f4, -0x46DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1EF4));
    // 0x8073ABA4: swc1        $f4, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f4.u32l;
    // 0x8073ABA8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8073ABAC: b           L_8073AC30
    // 0x8073ABB0: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
        goto L_8073AC30;
    // 0x8073ABB0: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x8073ABB4: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
L_8073ABB8:
    // 0x8073ABB8: lui         $a2, 0x8074
    ctx->r6 = S32(RELOC_HI16(739, 0X1F08) << 16);
    // 0x8073ABBC: addiu       $a2, $a2, -0x46C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(739, 0X1F08));
    // 0x8073ABC0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8073ABC4: sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3 << 3);
    // 0x8073ABC8: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x8073ABCC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8073ABD0: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x8073ABD4: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x8073ABD8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1F30) << 16);
    // 0x8073ABDC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8073ABE0: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x8073ABE4: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8073ABE8: swc1        $f16, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f16.u32l;
    // 0x8073ABEC: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x8073ABF0: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x8073ABF4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8073ABF8: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x8073ABFC: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8073AC00: swc1        $f18, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f18.u32l;
    // 0x8073AC04: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8073AC08: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x8073AC0C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8073AC10: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8073AC14: lwc1        $f4, -0x46A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1F30));
    // 0x8073AC18: swc1        $f4, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f4.u32l;
    // 0x8073AC1C: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8073AC20: lwc1        $f6, 0x6C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8073AC24: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    // 0x8073AC28: jal         0x8073B8CC
    // 0x8073AC2C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8073B8CC(rdram, ctx);
        goto after_6;
    // 0x8073AC2C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_6:
L_8073AC30:
    // 0x8073AC30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073AC34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073AC38: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8073AC3C: jr          $ra
    // 0x8073AC40: nop

    return;
    // 0x8073AC40: nop

;}
RECOMP_FUNC void func_8003B6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B6F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B6FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B700: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8003B704: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x8003B708: addiu       $t7, $t7, -0x5548
    ctx->r15 = ADD32(ctx->r15, -0X5548);
    // 0x8003B70C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8003B710: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8003B714: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8003B718: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8003B71C: lw          $t8, 0x7F78($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7F78);
    // 0x8003B720: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003B724: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8003B728: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003B72C: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003B730: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8003B734: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8003B738: jal         0x80052BA4
    // 0x8003B73C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80052BA4(rdram, ctx);
        goto after_0;
    // 0x8003B73C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B740: jal         0x8005FDC4
    // 0x8003B744: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x8003B744: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003B748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B74C: jal         0x8003A060
    // 0x8003B750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8003A060(rdram, ctx);
        goto after_2;
    // 0x8003B750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8003B754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B75C: jr          $ra
    // 0x8003B760: nop

    return;
    // 0x8003B760: nop

;}
RECOMP_FUNC void func_804C5B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5B1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5B20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5B24: jal         0x800545F4
    // 0x804C5B28: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800545F4(rdram, ctx);
        goto after_0;
    // 0x804C5B28: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x804C5B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C5B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5B34: jr          $ra
    // 0x804C5B38: nop

    return;
    // 0x804C5B38: nop

;}
RECOMP_FUNC void func_805DC8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC8F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805DC8F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DC8F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DC8FC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DC900: addiu       $at, $zero, 0x4194
    ctx->r1 = ADD32(0, 0X4194);
    // 0x805DC904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805DC908: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x805DC90C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805DC910: lw          $a1, 0x180($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X180);
    // 0x805DC914: beq         $v0, $at, L_805DC930
    if (ctx->r2 == ctx->r1) {
        // 0x805DC918: lw          $v1, 0x1F4($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X1F4);
            goto L_805DC930;
    }
    // 0x805DC918: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x805DC91C: addiu       $at, $zero, 0x4195
    ctx->r1 = ADD32(0, 0X4195);
    // 0x805DC920: beql        $v0, $at, L_805DC998
    if (ctx->r2 == ctx->r1) {
        // 0x805DC924: lw          $t8, 0x70($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X70);
            goto L_805DC998;
    }
    goto skip_0;
    // 0x805DC924: lw          $t8, 0x70($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X70);
    skip_0:
    // 0x805DC928: b           L_805DC9F4
    // 0x805DC92C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_805DC9F4;
    // 0x805DC92C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805DC930:
    // 0x805DC930: lw          $t7, 0x70($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X70);
    // 0x805DC934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DC938: bnel        $t7, $zero, L_805DC954
    if (ctx->r15 != 0) {
        // 0x805DC93C: lbu         $v0, 0x30($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X30);
            goto L_805DC954;
    }
    goto skip_1;
    // 0x805DC93C: lbu         $v0, 0x30($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X30);
    skip_1:
    // 0x805DC940: jal         0x805DB0C0
    // 0x805DC944: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    func_805DB0C0(rdram, ctx);
        goto after_0;
    // 0x805DC944: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    after_0:
    // 0x805DC948: b           L_805DC9F4
    // 0x805DC94C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_805DC9F4;
    // 0x805DC94C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DC950: lbu         $v0, 0x30($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X30);
L_805DC954:
    // 0x805DC954: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805DC958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DC95C: beq         $v0, $at, L_805DC974
    if (ctx->r2 == ctx->r1) {
        // 0x805DC960: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_805DC974;
    }
    // 0x805DC960: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805DC964: beq         $v0, $at, L_805DC984
    if (ctx->r2 == ctx->r1) {
        // 0x805DC968: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DC984;
    }
    // 0x805DC968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DC96C: b           L_805DC9F4
    // 0x805DC970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_805DC9F4;
    // 0x805DC970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805DC974:
    // 0x805DC974: jal         0x805DB054
    // 0x805DC978: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    func_805DB054(rdram, ctx);
        goto after_1;
    // 0x805DC978: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_1:
    // 0x805DC97C: b           L_805DC9F4
    // 0x805DC980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_805DC9F4;
    // 0x805DC980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805DC984:
    // 0x805DC984: jal         0x805DB054
    // 0x805DC988: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_805DB054(rdram, ctx);
        goto after_2;
    // 0x805DC988: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_2:
    // 0x805DC98C: b           L_805DC9F4
    // 0x805DC990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_805DC9F4;
    // 0x805DC990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DC994: lw          $t8, 0x70($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X70);
L_805DC998:
    // 0x805DC998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DC99C: bnel        $t8, $zero, L_805DC9B8
    if (ctx->r24 != 0) {
        // 0x805DC9A0: lbu         $v0, 0x30($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X30);
            goto L_805DC9B8;
    }
    goto skip_2;
    // 0x805DC9A0: lbu         $v0, 0x30($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X30);
    skip_2:
    // 0x805DC9A4: jal         0x805DB0C0
    // 0x805DC9A8: addiu       $a1, $zero, 0x27E
    ctx->r5 = ADD32(0, 0X27E);
    func_805DB0C0(rdram, ctx);
        goto after_3;
    // 0x805DC9A8: addiu       $a1, $zero, 0x27E
    ctx->r5 = ADD32(0, 0X27E);
    after_3:
    // 0x805DC9AC: b           L_805DC9F4
    // 0x805DC9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_805DC9F4;
    // 0x805DC9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DC9B4: lbu         $v0, 0x30($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X30);
L_805DC9B8:
    // 0x805DC9B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805DC9BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DC9C0: beq         $v0, $at, L_805DC9D8
    if (ctx->r2 == ctx->r1) {
        // 0x805DC9C4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_805DC9D8;
    }
    // 0x805DC9C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805DC9C8: beq         $v0, $at, L_805DC9E8
    if (ctx->r2 == ctx->r1) {
        // 0x805DC9CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DC9E8;
    }
    // 0x805DC9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DC9D0: b           L_805DC9F4
    // 0x805DC9D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_805DC9F4;
    // 0x805DC9D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805DC9D8:
    // 0x805DC9D8: jal         0x805DB054
    // 0x805DC9DC: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    func_805DB054(rdram, ctx);
        goto after_4;
    // 0x805DC9DC: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    after_4:
    // 0x805DC9E0: b           L_805DC9F4
    // 0x805DC9E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_805DC9F4;
    // 0x805DC9E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805DC9E8:
    // 0x805DC9E8: jal         0x805DB054
    // 0x805DC9EC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    func_805DB054(rdram, ctx);
        goto after_5;
    // 0x805DC9EC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_5:
    // 0x805DC9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805DC9F4:
    // 0x805DC9F4: jal         0x805DC750
    // 0x805DC9F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805DC750(rdram, ctx);
        goto after_6;
    // 0x805DC9F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x805DC9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DCA00: jal         0x805DC750
    // 0x805DCA04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_805DC750(rdram, ctx);
        goto after_7;
    // 0x805DCA04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x805DCA08: jal         0x805DAF08
    // 0x805DCA0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DAF08(rdram, ctx);
        goto after_8;
    // 0x805DCA0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x805DCA10: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x805DCA14: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x805DCA18: beql        $v0, $zero, L_805DCA48
    if (ctx->r2 == 0) {
        // 0x805DCA1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DCA48;
    }
    goto skip_3;
    // 0x805DCA1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x805DCA20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805DCA24: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x805DCA28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805DCA2C: swc1        $f4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f4.u32l;
    // 0x805DCA30: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x805DCA34: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x805DCA38: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805DCA3C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x805DCA40: swc1        $f10, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f10.u32l;
    // 0x805DCA44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DCA48:
    // 0x805DCA48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DCA4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805DCA50: jr          $ra
    // 0x805DCA54: nop

    return;
    // 0x805DCA54: nop

;}
RECOMP_FUNC void osDriveRomInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E80: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80085E84: lw          $t6, 0x1DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1DC);
    // 0x80085E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80085E8C: lui         $at, 0xA600
    ctx->r1 = S32(0XA600 << 16);
    // 0x80085E90: bne         $t6, $at, L_80085EA4
    if (ctx->r14 != ctx->r1) {
        // 0x80085E94: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80085EA4;
    }
    // 0x80085E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085E98: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80085E9C: b           L_80085F48
    // 0x80085EA0: addiu       $v0, $v0, 0x1D0
    ctx->r2 = ADD32(ctx->r2, 0X1D0);
        goto L_80085F48;
    // 0x80085EA0: addiu       $v0, $v0, 0x1D0
    ctx->r2 = ADD32(ctx->r2, 0X1D0);
L_80085EA4:
    // 0x80085EA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80085EA8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80085EAC: sb          $t7, 0x1D4($at)
    MEM_B(0X1D4, ctx->r1) = ctx->r15;
    // 0x80085EB0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80085EB4: lui         $t8, 0xA600
    ctx->r24 = S32(0XA600 << 16);
    // 0x80085EB8: sw          $t8, 0x1DC($at)
    MEM_W(0X1DC, ctx->r1) = ctx->r24;
    // 0x80085EBC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80085EC0: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80085EC4: sb          $t9, 0x1D5($at)
    MEM_B(0X1D5, ctx->r1) = ctx->r25;
    // 0x80085EC8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80085ECC: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80085ED0: sb          $t0, 0x1D8($at)
    MEM_B(0X1D8, ctx->r1) = ctx->r8;
    // 0x80085ED4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80085ED8: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80085EDC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80085EE0: sb          $t1, 0x1D6($at)
    MEM_B(0X1D6, ctx->r1) = ctx->r9;
    // 0x80085EE4: sb          $t2, 0x1D7($at)
    MEM_B(0X1D7, ctx->r1) = ctx->r10;
    // 0x80085EE8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80085EEC: sb          $zero, 0x1D9($at)
    MEM_B(0X1D9, ctx->r1) = 0;
    // 0x80085EF0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80085EF4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80085EF8: addiu       $a0, $a0, 0x1D0
    ctx->r4 = ADD32(ctx->r4, 0X1D0);
    // 0x80085EFC: sw          $zero, 0x1E0($at)
    MEM_W(0X1E0, ctx->r1) = 0;
    // 0x80085F00: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x80085F04: jal         0x80084820
    // 0x80085F08: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x80085F08: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_0:
    // 0x80085F0C: jal         0x8008CD40
    // 0x80085F10: nop

    __osDisableInt_recomp(rdram, ctx);
        goto after_1;
    // 0x80085F10: nop

    after_1:
    // 0x80085F14: lui         $t3, 0x800B
    ctx->r11 = S32(0X800B << 16);
    // 0x80085F18: lw          $t3, -0x4654($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4654);
    // 0x80085F1C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80085F20: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x80085F24: sw          $t3, 0x1D0($at)
    MEM_W(0X1D0, ctx->r1) = ctx->r11;
    // 0x80085F28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80085F2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80085F30: addiu       $t4, $t4, 0x1D0
    ctx->r12 = ADD32(ctx->r12, 0X1D0);
    // 0x80085F34: sw          $t4, -0x4654($at)
    MEM_W(-0X4654, ctx->r1) = ctx->r12;
    // 0x80085F38: jal         0x8008CD60
    // 0x80085F3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_2;
    // 0x80085F3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80085F40: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80085F44: addiu       $v0, $v0, 0x1D0
    ctx->r2 = ADD32(ctx->r2, 0X1D0);
L_80085F48:
    // 0x80085F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80085F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80085F50: jr          $ra
    // 0x80085F54: nop

    return;
    // 0x80085F54: nop

;}
RECOMP_FUNC void func_80067530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067538: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006753C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80067540: addiu       $a1, $a1, 0x4E0
    ctx->r5 = ADD32(ctx->r5, 0X4E0);
    // 0x80067544: addiu       $a0, $a0, 0x4C8
    ctx->r4 = ADD32(ctx->r4, 0X4C8);
    // 0x80067548: jal         0x8008AE20
    // 0x8006754C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8006754C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80067550: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80067554: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80067558: addiu       $a1, $a1, 0x4A8
    ctx->r5 = ADD32(ctx->r5, 0X4A8);
    // 0x8006755C: addiu       $a0, $a0, 0x4B0
    ctx->r4 = ADD32(ctx->r4, 0X4B0);
    // 0x80067560: jal         0x8008AE20
    // 0x80067564: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80067564: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80067568: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8006756C: addiu       $a1, $a1, 0x4B0
    ctx->r5 = ADD32(ctx->r5, 0X4B0);
    // 0x80067570: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80067574: jal         0x80089D70
    // 0x80067578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80067578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8006757C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067580: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067584: jr          $ra
    // 0x80067588: nop

    return;
    // 0x80067588: nop

;}
RECOMP_FUNC void func_80555E44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80555E44: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80555E48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80555E4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80555E50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80555E54: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x80555E58: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80555E5C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80555E60: jal         0x80049D74
    // 0x80555E64: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x80555E64: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_0:
    // 0x80555E68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80555E6C: lwc1        $f6, 0xC8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x80555E70: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80555E74: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x80555E78: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80555E7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80555E80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80555E84: bc1fl       L_80556148
    if (!c1cs) {
        // 0x80555E88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80556148;
    }
    goto skip_0;
    // 0x80555E88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80555E8C: jal         0x8004D150
    // 0x80555E90: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x80555E90: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_1:
    // 0x80555E94: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80555E98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80555E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80555EA0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80555EA4: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80555EA8: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19E4) << 16);
    // 0x80555EAC: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80555EB0: lbu         $t9, 0x14($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X14);
    // 0x80555EB4: beq         $t9, $zero, L_805560EC
    if (ctx->r25 == 0) {
        // 0x80555EB8: nop
    
            goto L_805560EC;
    }
    // 0x80555EB8: nop

    // 0x80555EBC: jal         0x8004D618
    // 0x80555EC0: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_2;
    // 0x80555EC0: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_2:
    // 0x80555EC4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80555EC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80555ECC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80555ED0: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x80555ED4: jal         0x8004A97C
    // 0x80555ED8: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    func_8004A97C(rdram, ctx);
        goto after_3;
    // 0x80555ED8: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    after_3:
    // 0x80555EDC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80555EE0: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80555EE4: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19D8) << 16);
    // 0x80555EE8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80555EEC: lw          $t5, 0x40($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X40);
    // 0x80555EF0: lbu         $t6, 0x15($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X15);
    // 0x80555EF4: bne         $t6, $zero, L_805560CC
    if (ctx->r14 != 0) {
        // 0x80555EF8: nop
    
            goto L_805560CC;
    }
    // 0x80555EF8: nop

    // 0x80555EFC: lwc1        $f2, 0x68C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(357, 0X19D8));
    // 0x80555F00: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19DC) << 16);
    // 0x80555F04: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80555F08: nop

    // 0x80555F0C: bc1f        L_80555F24
    if (!c1cs) {
        // 0x80555F10: nop
    
            goto L_80555F24;
    }
    // 0x80555F10: nop

    // 0x80555F14: lwc1        $f8, 0x550($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X550);
    // 0x80555F18: swc1        $f8, 0x54C($s0)
    MEM_W(0X54C, ctx->r16) = ctx->f8.u32l;
    // 0x80555F1C: b           L_80555FBC
    // 0x80555F20: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
        goto L_80555FBC;
    // 0x80555F20: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
L_80555F24:
    // 0x80555F24: lwc1        $f12, 0x68CC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(357, 0X19DC));
    // 0x80555F28: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80555F2C: nop

    // 0x80555F30: bc1fl       L_80555F50
    if (!c1cs) {
        // 0x80555F34: lwc1        $f0, 0x54C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
            goto L_80555F50;
    }
    goto skip_1;
    // 0x80555F34: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
    skip_1:
    // 0x80555F38: lwc1        $f10, 0x550($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X550);
    // 0x80555F3C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80555F40: swc1        $f16, 0x54C($s0)
    MEM_W(0X54C, ctx->r16) = ctx->f16.u32l;
    // 0x80555F44: b           L_80555FBC
    // 0x80555F48: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
        goto L_80555FBC;
    // 0x80555F48: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
    // 0x80555F4C: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
L_80555F50:
    // 0x80555F50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80555F54: nop

    // 0x80555F58: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x80555F5C: nop

    // 0x80555F60: bc1fl       L_80555F80
    if (!c1cs) {
        // 0x80555F64: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80555F80;
    }
    goto skip_2;
    // 0x80555F64: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_2:
    // 0x80555F68: lwc1        $f4, 0x550($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X550);
    // 0x80555F6C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80555F70: swc1        $f6, 0x54C($s0)
    MEM_W(0X54C, ctx->r16) = ctx->f6.u32l;
    // 0x80555F74: b           L_80555FBC
    // 0x80555F78: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
        goto L_80555FBC;
    // 0x80555F78: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
    // 0x80555F7C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80555F80:
    // 0x80555F80: nop

    // 0x80555F84: bc1fl       L_80555FA4
    if (!c1cs) {
        // 0x80555F88: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_80555FA4;
    }
    goto skip_3;
    // 0x80555F88: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_3:
    // 0x80555F8C: lwc1        $f8, 0x550($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X550);
    // 0x80555F90: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80555F94: swc1        $f10, 0x54C($s0)
    MEM_W(0X54C, ctx->r16) = ctx->f10.u32l;
    // 0x80555F98: b           L_80555FBC
    // 0x80555F9C: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
        goto L_80555FBC;
    // 0x80555F9C: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
    // 0x80555FA0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_80555FA4:
    // 0x80555FA4: nop

    // 0x80555FA8: bc1fl       L_80555FC0
    if (!c1cs) {
        // 0x80555FAC: lwc1        $f18, 0xC4($s1)
        ctx->f18.u32l = MEM_W(ctx->r17, 0XC4);
            goto L_80555FC0;
    }
    goto skip_4;
    // 0x80555FAC: lwc1        $f18, 0xC4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC4);
    skip_4:
    // 0x80555FB0: lwc1        $f16, 0x550($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X550);
    // 0x80555FB4: swc1        $f16, 0x54C($s0)
    MEM_W(0X54C, ctx->r16) = ctx->f16.u32l;
    // 0x80555FB8: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
L_80555FBC:
    // 0x80555FBC: lwc1        $f18, 0xC4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC4);
L_80555FC0:
    // 0x80555FC0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80555FC4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80555FC8: nop

    // 0x80555FCC: bc1f        L_80555FE0
    if (!c1cs) {
        // 0x80555FD0: nop
    
            goto L_80555FE0;
    }
    // 0x80555FD0: nop

    // 0x80555FD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80555FD8: nop

    // 0x80555FDC: swc1        $f6, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f6.u32l;
L_80555FE0:
    // 0x80555FE0: jal         0x80059278
    // 0x80555FE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80059278(rdram, ctx);
        goto after_4;
    // 0x80555FE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80555FE8: beq         $v0, $zero, L_805560CC
    if (ctx->r2 == 0) {
        // 0x80555FEC: nop
    
            goto L_805560CC;
    }
    // 0x80555FEC: nop

    // 0x80555FF0: lwc1        $f8, 0x3C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80555FF4: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19E0) << 16);
    // 0x80555FF8: lwc1        $f18, 0x68D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(357, 0X19E0));
    // 0x80555FFC: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80556000: lwc1        $f10, 0x40($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80556004: addiu       $at, $zero, 0x41C8
    ctx->r1 = ADD32(0, 0X41C8);
    // 0x80556008: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8055600C: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x80556010: lwc1        $f16, 0x44($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80556014: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80556018: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x8055601C: lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XC);
    // 0x80556020: beq         $v0, $at, L_80556038
    if (ctx->r2 == ctx->r1) {
        // 0x80556024: addiu       $at, $zero, 0x45DD
        ctx->r1 = ADD32(0, 0X45DD);
            goto L_80556038;
    }
    // 0x80556024: addiu       $at, $zero, 0x45DD
    ctx->r1 = ADD32(0, 0X45DD);
    // 0x80556028: beql        $v0, $at, L_80556068
    if (ctx->r2 == ctx->r1) {
        // 0x8055602C: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_80556068;
    }
    goto skip_5;
    // 0x8055602C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    skip_5:
    // 0x80556030: b           L_805560CC
    // 0x80556034: nop

        goto L_805560CC;
    // 0x80556034: nop

L_80556038:
    // 0x80556038: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8055603C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80556040: addiu       $a1, $s1, 0x6C
    ctx->r5 = ADD32(ctx->r17, 0X6C);
    // 0x80556044: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80556048: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x8055604C: addiu       $a3, $zero, 0x4529
    ctx->r7 = ADD32(0, 0X4529);
    // 0x80556050: lw          $t9, 0x44($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X44);
    // 0x80556054: jalr        $t9
    // 0x80556058: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80556058: nop

    after_5:
    // 0x8055605C: b           L_805560CC
    // 0x80556060: nop

        goto L_805560CC;
    // 0x80556060: nop

    // 0x80556064: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_80556068:
    // 0x80556068: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8055606C: lwc1        $f6, 0x6C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x80556070: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80556074: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x80556078: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8055607C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80556080: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80556084: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80556088: addiu       $a3, $zero, 0x45E9
    ctx->r7 = ADD32(0, 0X45E9);
    // 0x8055608C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80556090: lwc1        $f10, 0x70($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X70);
    // 0x80556094: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80556098: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8055609C: lwc1        $f18, 0x74($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X74);
    // 0x805560A0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x805560A4: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x805560A8: lw          $t9, 0x44($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X44);
    // 0x805560AC: jalr        $t9
    // 0x805560B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x805560B0: nop

    after_6:
    // 0x805560B4: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x805560B8: jal         0x80067BBC
    // 0x805560BC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_7;
    // 0x805560BC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_7:
    // 0x805560C0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x805560C4: jal         0x80067818
    // 0x805560C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x805560C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
L_805560CC:
    // 0x805560CC: jal         0x80065954
    // 0x805560D0: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    func_80065954(rdram, ctx);
        goto after_9;
    // 0x805560D0: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_9:
    // 0x805560D4: jal         0x80066E88
    // 0x805560D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_10;
    // 0x805560D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_10:
    // 0x805560DC: lwc1        $f4, 0x54C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54C);
    // 0x805560E0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x805560E4: b           L_80556144
    // 0x805560E8: swc1        $f6, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f6.u32l;
        goto L_80556144;
    // 0x805560E8: swc1        $f6, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f6.u32l;
L_805560EC:
    // 0x805560EC: lwc1        $f2, 0x68D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(357, 0X19E4));
    // 0x805560F0: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
    // 0x805560F4: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19EC) << 16);
    // 0x805560F8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805560FC: nop

    // 0x80556100: bc1f        L_8055611C
    if (!c1cs) {
        // 0x80556104: nop
    
            goto L_8055611C;
    }
    // 0x80556104: nop

    // 0x80556108: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19E8) << 16);
    // 0x8055610C: lwc1        $f8, 0x68D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(357, 0X19E8));
    // 0x80556110: swc1        $f8, 0x54C($s0)
    MEM_W(0X54C, ctx->r16) = ctx->f8.u32l;
    // 0x80556114: b           L_80556140
    // 0x80556118: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
        goto L_80556140;
    // 0x80556118: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
L_8055611C:
    // 0x8055611C: lwc1        $f12, 0x68DC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(357, 0X19EC));
    // 0x80556120: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19F0) << 16);
    // 0x80556124: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80556128: nop

    // 0x8055612C: bc1fl       L_80556144
    if (!c1cs) {
        // 0x80556130: swc1        $f0, 0xDC($s1)
        MEM_W(0XDC, ctx->r17) = ctx->f0.u32l;
            goto L_80556144;
    }
    goto skip_6;
    // 0x80556130: swc1        $f0, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f0.u32l;
    skip_6:
    // 0x80556134: lwc1        $f10, 0x68E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(357, 0X19F0));
    // 0x80556138: swc1        $f10, 0x54C($s0)
    MEM_W(0X54C, ctx->r16) = ctx->f10.u32l;
    // 0x8055613C: lwc1        $f0, 0x54C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54C);
L_80556140:
    // 0x80556140: swc1        $f0, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f0.u32l;
L_80556144:
    // 0x80556144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80556148:
    // 0x80556148: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8055614C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80556150: jr          $ra
    // 0x80556154: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80556154: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_804EF6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF6FC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804EF700: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(267, 0X10B0) << 16);
    // 0x804EF704: addiu       $t8, $t8, -0x1C0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(267, 0X10B0));
    // 0x804EF708: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x804EF70C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804EF710: beq         $v1, $zero, L_804EF74C
    if (ctx->r3 == 0) {
        // 0x804EF714: nop
    
            goto L_804EF74C;
    }
    // 0x804EF714: nop

    // 0x804EF718: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x804EF71C: lw          $v0, 0x16C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X16C);
    // 0x804EF720: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x804EF724: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804EF728: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804EF72C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x804EF730: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
L_804EF734:
    // 0x804EF734: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x804EF738: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x804EF73C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x804EF740: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x804EF744: bne         $a2, $v1, L_804EF734
    if (ctx->r6 != ctx->r3) {
        // 0x804EF748: sb          $t9, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r25;
            goto L_804EF734;
    }
    // 0x804EF748: sb          $t9, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r25;
L_804EF74C:
    // 0x804EF74C: jr          $ra
    // 0x804EF750: nop

    return;
    // 0x804EF750: nop

;}
RECOMP_FUNC void func_800288E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800288E8: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800288EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800288F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800288F4: beq         $t6, $t0, L_8002890C
    if (ctx->r14 == ctx->r8) {
        // 0x800288F8: lbu         $v0, 0x20($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X20);
            goto L_8002890C;
    }
    // 0x800288F8: lbu         $v0, 0x20($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X20);
    // 0x800288FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80028900: beq         $t6, $a2, L_8002890C
    if (ctx->r14 == ctx->r6) {
        // 0x80028904: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8002890C;
    }
    // 0x80028904: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80028908: bne         $t6, $at, L_8002891C
    if (ctx->r14 != ctx->r1) {
        // 0x8002890C: addiu       $t7, $zero, 0x1E
        ctx->r15 = ADD32(0, 0X1E);
            goto L_8002891C;
    }
L_8002890C:
    // 0x8002890C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80028910: sw          $zero, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = 0;
    // 0x80028914: jr          $ra
    // 0x80028918: sw          $t7, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r15;
    return;
    // 0x80028918: sw          $t7, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r15;
L_8002891C:
    // 0x8002891C: lw          $v1, 0xD0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XD0);
    // 0x80028920: beq         $v0, $v1, L_80028A70
    if (ctx->r2 == ctx->r3) {
        // 0x80028924: nop
    
            goto L_80028A70;
    }
    // 0x80028924: nop

    // 0x80028928: beql        $v1, $zero, L_8002894C
    if (ctx->r3 == 0) {
        // 0x8002892C: lw          $v1, 0xCC($a0)
        ctx->r3 = MEM_W(ctx->r4, 0XCC);
            goto L_8002894C;
    }
    goto skip_0;
    // 0x8002892C: lw          $v1, 0xCC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XCC);
    skip_0:
    // 0x80028930: beq         $v1, $t0, L_8002896C
    if (ctx->r3 == ctx->r8) {
        // 0x80028934: nop
    
            goto L_8002896C;
    }
    // 0x80028934: nop

    // 0x80028938: beq         $v1, $a2, L_800289D8
    if (ctx->r3 == ctx->r6) {
        // 0x8002893C: lw          $t6, 0x4($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4);
            goto L_800289D8;
    }
    // 0x8002893C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80028940: jr          $ra
    // 0x80028944: nop

    return;
    // 0x80028944: nop

    // 0x80028948: lw          $v1, 0xCC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XCC);
L_8002894C:
    // 0x8002894C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80028950: bne         $v1, $zero, L_80028964
    if (ctx->r3 != 0) {
        // 0x80028954: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_80028964;
    }
    // 0x80028954: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x80028958: sw          $v0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->r2;
    // 0x8002895C: jr          $ra
    // 0x80028960: sw          $t8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r24;
    return;
    // 0x80028960: sw          $t8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r24;
L_80028964:
    // 0x80028964: jr          $ra
    // 0x80028968: sw          $t9, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r25;
    return;
    // 0x80028968: sw          $t9, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r25;
L_8002896C:
    // 0x8002896C: bne         $v0, $zero, L_800289AC
    if (ctx->r2 != 0) {
        // 0x80028970: lw          $t1, 0x4($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X4);
            goto L_800289AC;
    }
    // 0x80028970: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80028974: lw          $t2, 0x38($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X38);
    // 0x80028978: slti        $at, $t2, 0xAB
    ctx->r1 = SIGNED(ctx->r10) < 0XAB ? 1 : 0;
    // 0x8002897C: bne         $at, $zero, L_800289AC
    if (ctx->r1 != 0) {
        // 0x80028980: nop
    
            goto L_800289AC;
    }
    // 0x80028980: nop

    // 0x80028984: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80028988: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8002898C: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x80028990: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80028994: nop

    // 0x80028998: bc1f        L_800289AC
    if (!c1cs) {
        // 0x8002899C: nop
    
            goto L_800289AC;
    }
    // 0x8002899C: nop

    // 0x800289A0: sw          $v0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->r2;
    // 0x800289A4: jr          $ra
    // 0x800289A8: sw          $t3, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r11;
    return;
    // 0x800289A8: sw          $t3, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r11;
L_800289AC:
    // 0x800289AC: bne         $v0, $a2, L_80028A70
    if (ctx->r2 != ctx->r6) {
        // 0x800289B0: nop
    
            goto L_80028A70;
    }
    // 0x800289B0: nop

    // 0x800289B4: lw          $v1, 0xCC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XCC);
    // 0x800289B8: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x800289BC: bne         $v1, $zero, L_800289D0
    if (ctx->r3 != 0) {
        // 0x800289C0: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_800289D0;
    }
    // 0x800289C0: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x800289C4: sw          $v0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->r2;
    // 0x800289C8: jr          $ra
    // 0x800289CC: sw          $t4, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r12;
    return;
    // 0x800289CC: sw          $t4, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r12;
L_800289D0:
    // 0x800289D0: jr          $ra
    // 0x800289D4: sw          $t5, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r13;
    return;
    // 0x800289D4: sw          $t5, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r13;
L_800289D8:
    // 0x800289D8: lw          $t7, 0x38($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X38);
    // 0x800289DC: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x800289E0: slti        $at, $t7, 0x3B
    ctx->r1 = SIGNED(ctx->r15) < 0X3B ? 1 : 0;
    // 0x800289E4: beql        $at, $zero, L_80028A6C
    if (ctx->r1 == 0) {
        // 0x800289E8: sw          $v0, 0xD0($a0)
        MEM_W(0XD0, ctx->r4) = ctx->r2;
            goto L_80028A6C;
    }
    goto skip_1;
    // 0x800289E8: sw          $v0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->r2;
    skip_1:
    // 0x800289EC: bne         $v0, $t0, L_80028A04
    if (ctx->r2 != ctx->r8) {
        // 0x800289F0: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80028A04;
    }
    // 0x800289F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800289F4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x800289F8: sw          $v0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->r2;
    // 0x800289FC: jr          $ra
    // 0x80028A00: sw          $t8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r24;
    return;
    // 0x80028A00: sw          $t8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r24;
L_80028A04:
    // 0x80028A04: lwc1        $f2, -0x244($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X244);
    // 0x80028A08: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80028A0C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028A10: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80028A14: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80028A18: nop

    // 0x80028A1C: bc1tl       L_80028A60
    if (c1cs) {
        // 0x80028A20: sw          $v0, 0xD0($a0)
        MEM_W(0XD0, ctx->r4) = ctx->r2;
            goto L_80028A60;
    }
    goto skip_2;
    // 0x80028A20: sw          $v0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->r2;
    skip_2:
    // 0x80028A24: lwc1        $f12, -0x240($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X240);
    // 0x80028A28: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80028A2C: nop

    // 0x80028A30: bc1tl       L_80028A60
    if (c1cs) {
        // 0x80028A34: sw          $v0, 0xD0($a0)
        MEM_W(0XD0, ctx->r4) = ctx->r2;
            goto L_80028A60;
    }
    goto skip_3;
    // 0x80028A34: sw          $v0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->r2;
    skip_3:
    // 0x80028A38: lwc1        $f0, 0x4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80028A3C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80028A40: nop

    // 0x80028A44: bc1tl       L_80028A60
    if (c1cs) {
        // 0x80028A48: sw          $v0, 0xD0($a0)
        MEM_W(0XD0, ctx->r4) = ctx->r2;
            goto L_80028A60;
    }
    goto skip_4;
    // 0x80028A48: sw          $v0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->r2;
    skip_4:
    // 0x80028A4C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80028A50: nop

    // 0x80028A54: bc1f        L_80028A70
    if (!c1cs) {
        // 0x80028A58: nop
    
            goto L_80028A70;
    }
    // 0x80028A58: nop

    // 0x80028A5C: sw          $v0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->r2;
L_80028A60:
    // 0x80028A60: jr          $ra
    // 0x80028A64: sw          $t9, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r25;
    return;
    // 0x80028A64: sw          $t9, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r25;
    // 0x80028A68: sw          $v0, 0xD0($a0)
    MEM_W(0XD0, ctx->r4) = ctx->r2;
L_80028A6C:
    // 0x80028A6C: sw          $t1, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->r9;
L_80028A70:
    // 0x80028A70: jr          $ra
    // 0x80028A74: nop

    return;
    // 0x80028A74: nop

;}
RECOMP_FUNC void func_804536E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804536E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804536E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804536EC: jal         0x80453644
    // 0x804536F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80453644(rdram, ctx);
        goto after_0;
    // 0x804536F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x804536F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804536F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804536FC: jr          $ra
    // 0x80453700: nop

    return;
    // 0x80453700: nop

;}
RECOMP_FUNC void func_805AA3E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA3E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AA3E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA3EC: jal         0x805AA510
    // 0x805AA3F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AA510(rdram, ctx);
        goto after_0;
    // 0x805AA3F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AA3F4: beq         $v0, $zero, L_805AA460
    if (ctx->r2 == 0) {
        // 0x805AA3F8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805AA460;
    }
    // 0x805AA3F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AA3FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805AA400: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AA404: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805AA408: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805AA40C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x805AA410: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AA414: lui         $t0, 0x805B
    ctx->r8 = S32(RELOC_HI16(432, 0XAA0) << 16);
    // 0x805AA418: addiu       $t0, $t0, -0x5270
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(432, 0XAA0));
    // 0x805AA41C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x805AA420: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AA424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AA428: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805AA42C: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
    // 0x805AA430: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
    // 0x805AA434: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x805AA438: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805AA43C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x805AA440: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805AA444: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x805AA448: jal         0x805AABAC
    // 0x805AA44C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AABAC(rdram, ctx);
        goto after_1;
    // 0x805AA44C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x805AA450: jal         0x805AA338
    // 0x805AA454: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805AA338(rdram, ctx);
        goto after_2;
    // 0x805AA454: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x805AA458: b           L_805AA46C
    // 0x805AA45C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805AA46C;
    // 0x805AA45C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AA460:
    // 0x805AA460: jal         0x800445A4
    // 0x805AA464: nop

    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x805AA464: nop

    after_3:
    // 0x805AA468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AA46C:
    // 0x805AA46C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AA470: jr          $ra
    // 0x805AA474: nop

    return;
    // 0x805AA474: nop

;}
RECOMP_FUNC void func_8056183C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056183C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80561840: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80561844: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80561848: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8056184C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80561850: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80561854: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80561858: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8056185C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80561860: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80561864: lwc1        $f22, 0x3C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80561868: lwc1        $f24, 0x40($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8056186C: addiu       $a1, $zero, 0x880
    ctx->r5 = ADD32(0, 0X880);
    // 0x80561870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80561874: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80561878: jal         0x80065728
    // 0x8056187C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8056187C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80561880: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80561884: sw          $zero, 0x714($s1)
    MEM_W(0X714, ctx->r17) = 0;
    // 0x80561888: sw          $zero, 0x710($s1)
    MEM_W(0X710, ctx->r17) = 0;
    // 0x8056188C: sw          $zero, 0x708($s1)
    MEM_W(0X708, ctx->r17) = 0;
    // 0x80561890: swc1        $f4, 0x724($s1)
    MEM_W(0X724, ctx->r17) = ctx->f4.u32l;
    // 0x80561894: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80561898: addiu       $at, $zero, 0x41CA
    ctx->r1 = ADD32(0, 0X41CA);
    // 0x8056189C: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(366, 0X22D0) << 16);
    // 0x805618A0: beq         $v0, $at, L_805618D4
    if (ctx->r2 == ctx->r1) {
        // 0x805618A4: addiu       $t6, $t6, 0x3720
        ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(366, 0X22D0));
            goto L_805618D4;
    }
    // 0x805618A4: addiu       $t6, $t6, 0x3720
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(366, 0X22D0));
    // 0x805618A8: addiu       $at, $zero, 0x41CB
    ctx->r1 = ADD32(0, 0X41CB);
    // 0x805618AC: beq         $v0, $at, L_80561910
    if (ctx->r2 == ctx->r1) {
        // 0x805618B0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80561910;
    }
    // 0x805618B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805618B4: addiu       $at, $zero, 0x41CC
    ctx->r1 = ADD32(0, 0X41CC);
    // 0x805618B8: beq         $v0, $at, L_80561990
    if (ctx->r2 == ctx->r1) {
        // 0x805618BC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80561990;
    }
    // 0x805618BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805618C0: addiu       $at, $zero, 0x41CD
    ctx->r1 = ADD32(0, 0X41CD);
    // 0x805618C4: beq         $v0, $at, L_80561950
    if (ctx->r2 == ctx->r1) {
        // 0x805618C8: lui         $t4, 0x8056
        ctx->r12 = S32(RELOC_HI16(366, 0X22D8) << 16);
            goto L_80561950;
    }
    // 0x805618C8: lui         $t4, 0x8056
    ctx->r12 = S32(RELOC_HI16(366, 0X22D8) << 16);
    // 0x805618CC: b           L_805619D0
    // 0x805618D0: lw          $t3, 0x70C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X70C);
        goto L_805619D0;
    // 0x805618D0: lw          $t3, 0x70C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X70C);
L_805618D4:
    // 0x805618D4: sw          $zero, 0x70C($s1)
    MEM_W(0X70C, ctx->r17) = 0;
    // 0x805618D8: sh          $zero, 0x72C($s1)
    MEM_H(0X72C, ctx->r17) = 0;
    // 0x805618DC: sw          $t6, 0x720($s1)
    MEM_W(0X720, ctx->r17) = ctx->r14;
    // 0x805618E0: sh          $zero, 0x72E($s1)
    MEM_H(0X72E, ctx->r17) = 0;
    // 0x805618E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805618E8: jal         0x8004921C
    // 0x805618EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x805618EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805618F0: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(366, 0X17C4) << 16);
    // 0x805618F4: sll         $t7, $v0, 6
    ctx->r15 = S32(ctx->r2 << 6);
    // 0x805618F8: addiu       $t8, $t8, 0x2C14
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(366, 0X17C4));
    // 0x805618FC: addiu       $t9, $zero, 0x43
    ctx->r25 = ADD32(0, 0X43);
    // 0x80561900: sh          $t7, 0x730($s1)
    MEM_H(0X730, ctx->r17) = ctx->r15;
    // 0x80561904: sw          $t8, 0x878($s1)
    MEM_W(0X878, ctx->r17) = ctx->r24;
    // 0x80561908: b           L_805619CC
    // 0x8056190C: sw          $t9, 0x87C($s1)
    MEM_W(0X87C, ctx->r17) = ctx->r25;
        goto L_805619CC;
    // 0x8056190C: sw          $t9, 0x87C($s1)
    MEM_W(0X87C, ctx->r17) = ctx->r25;
L_80561910:
    // 0x80561910: lui         $t0, 0x8056
    ctx->r8 = S32(RELOC_HI16(366, 0X22D0) << 16);
    // 0x80561914: addiu       $t0, $t0, 0x3720
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(366, 0X22D0));
    // 0x80561918: sw          $a1, 0x70C($s1)
    MEM_W(0X70C, ctx->r17) = ctx->r5;
    // 0x8056191C: sh          $a1, 0x72C($s1)
    MEM_H(0X72C, ctx->r17) = ctx->r5;
    // 0x80561920: sw          $t0, 0x720($s1)
    MEM_W(0X720, ctx->r17) = ctx->r8;
    // 0x80561924: jal         0x8004921C
    // 0x80561928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x80561928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8056192C: lui         $t2, 0x8056
    ctx->r10 = S32(RELOC_HI16(366, 0X17C4) << 16);
    // 0x80561930: sll         $t1, $v0, 6
    ctx->r9 = S32(ctx->r2 << 6);
    // 0x80561934: addiu       $t2, $t2, 0x2C14
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(366, 0X17C4));
    // 0x80561938: addiu       $t3, $zero, 0x43
    ctx->r11 = ADD32(0, 0X43);
    // 0x8056193C: sh          $t1, 0x72E($s1)
    MEM_H(0X72E, ctx->r17) = ctx->r9;
    // 0x80561940: sh          $zero, 0x730($s1)
    MEM_H(0X730, ctx->r17) = 0;
    // 0x80561944: sw          $t2, 0x878($s1)
    MEM_W(0X878, ctx->r17) = ctx->r10;
    // 0x80561948: b           L_805619CC
    // 0x8056194C: sw          $t3, 0x87C($s1)
    MEM_W(0X87C, ctx->r17) = ctx->r11;
        goto L_805619CC;
    // 0x8056194C: sw          $t3, 0x87C($s1)
    MEM_W(0X87C, ctx->r17) = ctx->r11;
L_80561950:
    // 0x80561950: addiu       $t4, $t4, 0x3728
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(366, 0X22D8));
    // 0x80561954: sw          $zero, 0x70C($s1)
    MEM_W(0X70C, ctx->r17) = 0;
    // 0x80561958: sh          $zero, 0x72C($s1)
    MEM_H(0X72C, ctx->r17) = 0;
    // 0x8056195C: sw          $t4, 0x720($s1)
    MEM_W(0X720, ctx->r17) = ctx->r12;
    // 0x80561960: sh          $zero, 0x72E($s1)
    MEM_H(0X72E, ctx->r17) = 0;
    // 0x80561964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80561968: jal         0x8004921C
    // 0x8056196C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x8056196C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80561970: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(366, 0X1CB0) << 16);
    // 0x80561974: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x80561978: addiu       $t6, $t6, 0x3100
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(366, 0X1CB0));
    // 0x8056197C: addiu       $t7, $zero, 0x41
    ctx->r15 = ADD32(0, 0X41);
    // 0x80561980: sh          $t5, 0x730($s1)
    MEM_H(0X730, ctx->r17) = ctx->r13;
    // 0x80561984: sw          $t6, 0x878($s1)
    MEM_W(0X878, ctx->r17) = ctx->r14;
    // 0x80561988: b           L_805619CC
    // 0x8056198C: sw          $t7, 0x87C($s1)
    MEM_W(0X87C, ctx->r17) = ctx->r15;
        goto L_805619CC;
    // 0x8056198C: sw          $t7, 0x87C($s1)
    MEM_W(0X87C, ctx->r17) = ctx->r15;
L_80561990:
    // 0x80561990: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(366, 0X22E0) << 16);
    // 0x80561994: addiu       $t8, $t8, 0x3730
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(366, 0X22E0));
    // 0x80561998: sw          $zero, 0x70C($s1)
    MEM_W(0X70C, ctx->r17) = 0;
    // 0x8056199C: sh          $a1, 0x72C($s1)
    MEM_H(0X72C, ctx->r17) = ctx->r5;
    // 0x805619A0: sw          $t8, 0x720($s1)
    MEM_W(0X720, ctx->r17) = ctx->r24;
    // 0x805619A4: jal         0x8004921C
    // 0x805619A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x805619A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805619AC: lui         $t0, 0x8056
    ctx->r8 = S32(RELOC_HI16(366, 0X1A34) << 16);
    // 0x805619B0: sll         $t9, $v0, 6
    ctx->r25 = S32(ctx->r2 << 6);
    // 0x805619B4: addiu       $t0, $t0, 0x2E84
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(366, 0X1A34));
    // 0x805619B8: addiu       $t1, $zero, 0x41
    ctx->r9 = ADD32(0, 0X41);
    // 0x805619BC: sh          $t9, 0x72E($s1)
    MEM_H(0X72E, ctx->r17) = ctx->r25;
    // 0x805619C0: sh          $zero, 0x730($s1)
    MEM_H(0X730, ctx->r17) = 0;
    // 0x805619C4: sw          $t0, 0x878($s1)
    MEM_W(0X878, ctx->r17) = ctx->r8;
    // 0x805619C8: sw          $t1, 0x87C($s1)
    MEM_W(0X87C, ctx->r17) = ctx->r9;
L_805619CC:
    // 0x805619CC: lw          $t3, 0x70C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X70C);
L_805619D0:
    // 0x805619D0: lw          $t2, 0x720($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X720);
    // 0x805619D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x805619D8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x805619DC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x805619E0: lwc1        $f0, 0x0($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X0);
    // 0x805619E4: swc1        $f0, 0x718($s1)
    MEM_W(0X718, ctx->r17) = ctx->f0.u32l;
    // 0x805619E8: swc1        $f0, 0x71C($s1)
    MEM_W(0X71C, ctx->r17) = ctx->f0.u32l;
L_805619EC:
    // 0x805619EC: jal         0x80066E88
    // 0x805619F0: lwc1        $f12, 0x718($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X718);
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x805619F0: lwc1        $f12, 0x718($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X718);
    after_5:
    // 0x805619F4: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x805619F8: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x805619FC: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80561A00: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80561A04: add.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x80561A08: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
    // 0x80561A0C: jal         0x80066DE4
    // 0x80561A10: lwc1        $f12, 0x718($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X718);
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x80561A10: lwc1        $f12, 0x718($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X718);
    after_6:
    // 0x80561A14: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80561A18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80561A1C: slti        $at, $s0, 0xD8
    ctx->r1 = SIGNED(ctx->r16) < 0XD8 ? 1 : 0;
    // 0x80561A20: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80561A24: add.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x80561A28: bne         $at, $zero, L_805619EC
    if (ctx->r1 != 0) {
        // 0x80561A2C: swc1        $f4, -0x4($s2)
        MEM_W(-0X4, ctx->r18) = ctx->f4.u32l;
            goto L_805619EC;
    }
    // 0x80561A2C: swc1        $f4, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->f4.u32l;
    // 0x80561A30: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80561A34: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80561A38: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x80561A3C: slti        $at, $v1, 0xD8
    ctx->r1 = SIGNED(ctx->r3) < 0XD8 ? 1 : 0;
    // 0x80561A40: addiu       $a0, $s1, 0x6C8
    ctx->r4 = ADD32(ctx->r17, 0X6C8);
    // 0x80561A44: swc1        $f6, 0x6C0($s1)
    MEM_W(0X6C0, ctx->r17) = ctx->f6.u32l;
    // 0x80561A48: bne         $at, $zero, L_80561A54
    if (ctx->r1 != 0) {
        // 0x80561A4C: swc1        $f8, 0x6C4($s1)
        MEM_W(0X6C4, ctx->r17) = ctx->f8.u32l;
            goto L_80561A54;
    }
    // 0x80561A4C: swc1        $f8, 0x6C4($s1)
    MEM_W(0X6C4, ctx->r17) = ctx->f8.u32l;
    // 0x80561A50: addiu       $v1, $v1, -0xD8
    ctx->r3 = ADD32(ctx->r3, -0XD8);
L_80561A54:
    // 0x80561A54: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80561A58: addu        $v0, $s1, $t6
    ctx->r2 = ADD32(ctx->r17, ctx->r14);
    // 0x80561A5C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80561A60: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80561A64: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
L_80561A68:
    // 0x80561A68: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80561A6C: slti        $at, $v1, 0xD8
    ctx->r1 = SIGNED(ctx->r3) < 0XD8 ? 1 : 0;
    // 0x80561A70: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80561A74: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80561A78: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80561A7C: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // 0x80561A80: bne         $at, $zero, L_80561A90
    if (ctx->r1 != 0) {
        // 0x80561A84: swc1        $f16, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f16.u32l;
            goto L_80561A90;
    }
    // 0x80561A84: swc1        $f16, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80561A88: addiu       $v1, $v1, -0xD8
    ctx->r3 = ADD32(ctx->r3, -0XD8);
    // 0x80561A8C: addiu       $v0, $v0, -0x6C0
    ctx->r2 = ADD32(ctx->r2, -0X6C0);
L_80561A90:
    // 0x80561A90: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80561A94: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80561A98: slti        $at, $v1, 0xD8
    ctx->r1 = SIGNED(ctx->r3) < 0XD8 ? 1 : 0;
    // 0x80561A9C: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80561AA0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80561AA4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80561AA8: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // 0x80561AAC: bne         $at, $zero, L_80561ABC
    if (ctx->r1 != 0) {
        // 0x80561AB0: swc1        $f4, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
            goto L_80561ABC;
    }
    // 0x80561AB0: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80561AB4: addiu       $v1, $v1, -0xD8
    ctx->r3 = ADD32(ctx->r3, -0XD8);
    // 0x80561AB8: addiu       $v0, $v0, -0x6C0
    ctx->r2 = ADD32(ctx->r2, -0X6C0);
L_80561ABC:
    // 0x80561ABC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80561AC0: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80561AC4: slti        $at, $v1, 0xD8
    ctx->r1 = SIGNED(ctx->r3) < 0XD8 ? 1 : 0;
    // 0x80561AC8: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80561ACC: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80561AD0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80561AD4: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // 0x80561AD8: bne         $at, $zero, L_80561AE8
    if (ctx->r1 != 0) {
        // 0x80561ADC: swc1        $f8, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
            goto L_80561AE8;
    }
    // 0x80561ADC: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80561AE0: addiu       $v1, $v1, -0xD8
    ctx->r3 = ADD32(ctx->r3, -0XD8);
    // 0x80561AE4: addiu       $v0, $v0, -0x6C0
    ctx->r2 = ADD32(ctx->r2, -0X6C0);
L_80561AE8:
    // 0x80561AE8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80561AEC: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80561AF0: slti        $at, $v1, 0xD8
    ctx->r1 = SIGNED(ctx->r3) < 0XD8 ? 1 : 0;
    // 0x80561AF4: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80561AF8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80561AFC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80561B00: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // 0x80561B04: bne         $at, $zero, L_80561B14
    if (ctx->r1 != 0) {
        // 0x80561B08: swc1        $f16, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f16.u32l;
            goto L_80561B14;
    }
    // 0x80561B08: swc1        $f16, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80561B0C: addiu       $v1, $v1, -0xD8
    ctx->r3 = ADD32(ctx->r3, -0XD8);
    // 0x80561B10: addiu       $v0, $v0, -0x6C0
    ctx->r2 = ADD32(ctx->r2, -0X6C0);
L_80561B14:
    // 0x80561B14: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80561B18: bnel        $s0, $a1, L_80561A68
    if (ctx->r16 != ctx->r5) {
        // 0x80561B1C: lwc1        $f10, 0x0($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
            goto L_80561A68;
    }
    goto skip_0;
    // 0x80561B1C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80561B20: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80561B24: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80561B28: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80561B2C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80561B30: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80561B34: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80561B38: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80561B3C: jr          $ra
    // 0x80561B40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80561B40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80553668(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553668: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8055366C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80553670: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80553674: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80553678: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8055367C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80553680: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80553684: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80553688: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8055368C: jal         0x80047AB8
    // 0x80553690: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80553690: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80553694: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80553698: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8055369C: lw          $v0, 0x40($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X40);
    // 0x805536A0: lhu         $v1, 0x48($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X48);
    // 0x805536A4: beq         $v1, $zero, L_8055375C
    if (ctx->r3 == 0) {
        // 0x805536A8: nop
    
            goto L_8055375C;
    }
    // 0x805536A8: nop

    // 0x805536AC: beq         $v1, $at, L_8055375C
    if (ctx->r3 == ctx->r1) {
        // 0x805536B0: nop
    
            goto L_8055375C;
    }
    // 0x805536B0: nop

    // 0x805536B4: lbu         $v1, 0x48($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X48);
    // 0x805536B8: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x805536BC: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x805536C0: beq         $v1, $at, L_8055375C
    if (ctx->r3 == ctx->r1) {
        // 0x805536C4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8055375C;
    }
    // 0x805536C4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x805536C8: beq         $v1, $at, L_8055375C
    if (ctx->r3 == ctx->r1) {
        // 0x805536CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8055375C;
    }
    // 0x805536CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805536D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x805536D4: addiu       $a2, $v0, 0x48
    ctx->r6 = ADD32(ctx->r2, 0X48);
    // 0x805536D8: jal         0x8004D11C
    // 0x805536DC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_8004D11C(rdram, ctx);
        goto after_1;
    // 0x805536DC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x805536E0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x805536E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805536E8: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x805536EC: lbu         $t0, 0x5C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X5C);
    // 0x805536F0: beq         $t0, $zero, L_8055375C
    if (ctx->r8 == 0) {
        // 0x805536F4: nop
    
            goto L_8055375C;
    }
    // 0x805536F4: nop

    // 0x805536F8: jal         0x8004D3C4
    // 0x805536FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8004D3C4(rdram, ctx);
        goto after_2;
    // 0x805536FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80553700: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80553704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80553708: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8055370C: jal         0x8004A97C
    // 0x80553710: lhu         $a0, 0x48($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X48);
    func_8004A97C(rdram, ctx);
        goto after_3;
    // 0x80553710: lhu         $a0, 0x48($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X48);
    after_3:
    // 0x80553714: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80553718: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8055371C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80553720: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80553724: nop

    // 0x80553728: bc1fl       L_80553744
    if (!c1cs) {
        // 0x8055372C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80553744;
    }
    goto skip_0;
    // 0x8055372C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80553730: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80553734: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80553738: b           L_80553750
    // 0x8055373C: swc1        $f6, 0xD60($t3)
    MEM_W(0XD60, ctx->r11) = ctx->f6.u32l;
        goto L_80553750;
    // 0x8055373C: swc1        $f6, 0xD60($t3)
    MEM_W(0XD60, ctx->r11) = ctx->f6.u32l;
    // 0x80553740: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80553744:
    // 0x80553744: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80553748: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8055374C: swc1        $f10, 0xD60($t4)
    MEM_W(0XD60, ctx->r12) = ctx->f10.u32l;
L_80553750:
    // 0x80553750: lw          $t5, 0x8($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X8);
    // 0x80553754: ori         $t6, $t5, 0xF
    ctx->r14 = ctx->r13 | 0XF;
    // 0x80553758: sw          $t6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r14;
L_8055375C:
    // 0x8055375C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80553760: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x80553764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80553768: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8055376C: jal         0x8004D150
    // 0x80553770: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_8004D150(rdram, ctx);
        goto after_4;
    // 0x80553770: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_4:
    // 0x80553774: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80553778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8055377C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80553780: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80553784: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80553788: lbu         $t9, 0x2C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2C);
    // 0x8055378C: beql        $t9, $zero, L_805537C4
    if (ctx->r25 == 0) {
        // 0x80553790: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805537C4;
    }
    goto skip_1;
    // 0x80553790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80553794: jal         0x8004D618
    // 0x80553798: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_5;
    // 0x80553798: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_5:
    // 0x8055379C: jal         0x80553838
    // 0x805537A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80553838(rdram, ctx);
        goto after_6;
    // 0x805537A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805537A4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805537A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805537AC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x805537B0: swc1        $f16, 0xD60($t0)
    MEM_W(0XD60, ctx->r8) = ctx->f16.u32l;
    // 0x805537B4: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x805537B8: ori         $t2, $t1, 0xF00
    ctx->r10 = ctx->r9 | 0XF00;
    // 0x805537BC: sw          $t2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r10;
    // 0x805537C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805537C4:
    // 0x805537C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805537C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805537CC: jr          $ra
    // 0x805537D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x805537D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8066A230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A230: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066A234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A238: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066A23C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8066A240: jal         0x80669E80
    // 0x8066A244: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80669E80(rdram, ctx);
        goto after_0;
    // 0x8066A244: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8066A248: jal         0x80669FA4
    // 0x8066A24C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80669FA4(rdram, ctx);
        goto after_1;
    // 0x8066A24C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8066A250: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8066A254: addiu       $at, $zero, 0x4555
    ctx->r1 = ADD32(0, 0X4555);
    // 0x8066A258: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8066A25C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8066A260: beq         $v0, $at, L_8066A278
    if (ctx->r2 == ctx->r1) {
        // 0x8066A264: addiu       $at, $zero, 0x455C
        ctx->r1 = ADD32(0, 0X455C);
            goto L_8066A278;
    }
    // 0x8066A264: addiu       $at, $zero, 0x455C
    ctx->r1 = ADD32(0, 0X455C);
    // 0x8066A268: beq         $v0, $at, L_8066A2B4
    if (ctx->r2 == ctx->r1) {
        // 0x8066A26C: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_8066A2B4;
    }
    // 0x8066A26C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8066A270: b           L_8066A2EC
    // 0x8066A274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8066A2EC;
    // 0x8066A274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A278:
    // 0x8066A278: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8066A27C: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8066A280: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8066A284: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8066A288: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8066A28C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A290: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8066A294: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8066A298: nop

    // 0x8066A29C: bc1fl       L_8066A2EC
    if (!c1cs) {
        // 0x8066A2A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A2EC;
    }
    goto skip_0;
    // 0x8066A2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066A2A4: jal         0x8066A790
    // 0x8066A2A8: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8066A790(rdram, ctx);
        goto after_2;
    // 0x8066A2A8: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
    // 0x8066A2AC: b           L_8066A2EC
    // 0x8066A2B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8066A2EC;
    // 0x8066A2B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A2B4:
    // 0x8066A2B4: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8066A2B8: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8066A2BC: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8066A2C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8066A2C4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8066A2C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066A2CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8066A2D0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8066A2D4: nop

    // 0x8066A2D8: bc1fl       L_8066A2EC
    if (!c1cs) {
        // 0x8066A2DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066A2EC;
    }
    goto skip_1;
    // 0x8066A2DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8066A2E0: jal         0x8066A790
    // 0x8066A2E4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8066A790(rdram, ctx);
        goto after_3;
    // 0x8066A2E4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_3:
    // 0x8066A2E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066A2EC:
    // 0x8066A2EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066A2F0: jr          $ra
    // 0x8066A2F4: nop

    return;
    // 0x8066A2F4: nop

;}
RECOMP_FUNC void func_80532104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532104: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80532108: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8053210C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80532110: jal         0x8004700C
    // 0x80532114: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80532114: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80532118: beq         $v0, $zero, L_80532230
    if (ctx->r2 == 0) {
        // 0x8053211C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80532230;
    }
    // 0x8053211C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80532120: lw          $t7, 0x174($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X174);
    // 0x80532124: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80532128: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x8053212C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80532130: lw          $a2, 0x1F4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X1F4);
    // 0x80532134: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80532138: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x8053213C: lwc1        $f4, 0x268($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X268);
    // 0x80532140: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80532144: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80532148: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8053214C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80532150: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80532154: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80532158: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8053215C: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80532160: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80532164: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x80532168: nop

    // 0x8053216C: bc1fl       L_8053218C
    if (!c1cs) {
        // 0x80532170: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8053218C;
    }
    goto skip_0;
    // 0x80532170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80532174: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80532178: jal         0x80531880
    // 0x8053217C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80531880(rdram, ctx);
        goto after_1;
    // 0x8053217C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80532180: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80532184: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80532188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8053218C:
    // 0x8053218C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80532190: jal         0x80531774
    // 0x80532194: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80531774(rdram, ctx);
        goto after_2;
    // 0x80532194: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80532198: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8053219C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x805321A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805321A4: nop

    // 0x805321A8: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x805321AC: nop

    // 0x805321B0: bc1fl       L_80532234
    if (!c1cs) {
        // 0x805321B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80532234;
    }
    goto skip_1;
    // 0x805321B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805321B8: jal         0x8002F8AC
    // 0x805321BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002F8AC(rdram, ctx);
        goto after_3;
    // 0x805321BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805321C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x805321C4: jal         0x805323E8
    // 0x805321C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_805323E8(rdram, ctx);
        goto after_4;
    // 0x805321C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x805321CC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x805321D0: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A24) << 16);
    // 0x805321D4: lwc1        $f8, 0x2814($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A24));
    // 0x805321D8: lwc1        $f6, 0x8C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x805321DC: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A2C) << 16);
    // 0x805321E0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x805321E4: nop

    // 0x805321E8: bc1f        L_805321FC
    if (!c1cs) {
        // 0x805321EC: nop
    
            goto L_805321FC;
    }
    // 0x805321EC: nop

    // 0x805321F0: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A28) << 16);
    // 0x805321F4: b           L_80532200
    // 0x805321F8: lwc1        $f0, 0x2818($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A28));
        goto L_80532200;
    // 0x805321F8: lwc1        $f0, 0x2818($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A28));
L_805321FC:
    // 0x805321FC: lwc1        $f0, 0x281C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A2C));
L_80532200:
    // 0x80532200: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80532204: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80532208: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8053220C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80532210: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x80532214: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80532218: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8053221C: jal         0x80047AB8
    // 0x80532220: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    func_80047AB8(rdram, ctx);
        goto after_5;
    // 0x80532220: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    after_5:
    // 0x80532224: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80532228: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8053222C: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
L_80532230:
    // 0x80532230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80532234:
    // 0x80532234: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80532238: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8053223C: jr          $ra
    // 0x80532240: nop

    return;
    // 0x80532240: nop

;}
RECOMP_FUNC void func_8006CF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CF94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CF98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CF9C: jal         0x8006CC24
    // 0x8006CFA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006CC24(rdram, ctx);
        goto after_0;
    // 0x8006CFA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006CFA4: jal         0x8006C3F0
    // 0x8006CFA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006C3F0(rdram, ctx);
        goto after_1;
    // 0x8006CFA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006CFAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CFB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CFB4: jr          $ra
    // 0x8006CFB8: nop

    return;
    // 0x8006CFB8: nop

    // 0x8006CFBC: nop

;}
RECOMP_FUNC void func_806DFE34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DFE34: lw          $t6, 0x180($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X180);
    // 0x806DFE38: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x806DFE3C: bnel        $a0, $t6, L_806DFEF8
    if (ctx->r4 != ctx->r14) {
        // 0x806DFE40: lwc1        $f0, 0x84($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X84);
            goto L_806DFEF8;
    }
    goto skip_0;
    // 0x806DFE40: lwc1        $f0, 0x84($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X84);
    skip_0:
    // 0x806DFE44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806DFE48: lwc1        $f0, 0x3C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x806DFE4C: addiu       $v1, $a1, 0xC4
    ctx->r3 = ADD32(ctx->r5, 0XC4);
    // 0x806DFE50: lui         $at, 0xC1D0
    ctx->r1 = S32(0XC1D0 << 16);
    // 0x806DFE54: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806DFE58: nop

    // 0x806DFE5C: bc1fl       L_806DFEA4
    if (!c1cs) {
        // 0x806DFE60: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806DFEA4;
    }
    goto skip_1;
    // 0x806DFE60: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x806DFE64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806DFE68: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806DFE6C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x806DFE70: nop

    // 0x806DFE74: bc1f        L_806DFEEC
    if (!c1cs) {
        // 0x806DFE78: nop
    
            goto L_806DFEEC;
    }
    // 0x806DFE78: nop

    // 0x806DFE7C: swc1        $f2, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f2.u32l;
    // 0x806DFE80: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x806DFE84: lw          $a0, 0x1F4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1F4);
    // 0x806DFE88: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x806DFE8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806DFE90: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x806DFE94: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x806DFE98: jr          $ra
    // 0x806DFE9C: sw          $t8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r24;
    return;
    // 0x806DFE9C: sw          $t8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r24;
    // 0x806DFEA0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806DFEA4:
    // 0x806DFEA4: addiu       $v1, $a1, 0xC4
    ctx->r3 = ADD32(ctx->r5, 0XC4);
    // 0x806DFEA8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806DFEAC: nop

    // 0x806DFEB0: bc1f        L_806DFEEC
    if (!c1cs) {
        // 0x806DFEB4: nop
    
            goto L_806DFEEC;
    }
    // 0x806DFEB4: nop

    // 0x806DFEB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806DFEBC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806DFEC0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x806DFEC4: nop

    // 0x806DFEC8: bc1f        L_806DFEEC
    if (!c1cs) {
        // 0x806DFECC: nop
    
            goto L_806DFEEC;
    }
    // 0x806DFECC: nop

    // 0x806DFED0: swc1        $f2, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f2.u32l;
    // 0x806DFED4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x806DFED8: lw          $a0, 0x1F4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1F4);
    // 0x806DFEDC: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x806DFEE0: lw          $t9, 0x34($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X34);
    // 0x806DFEE4: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x806DFEE8: sw          $t0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r8;
L_806DFEEC:
    // 0x806DFEEC: jr          $ra
    // 0x806DFEF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x806DFEF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806DFEF4: lwc1        $f0, 0x84($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X84);
L_806DFEF8:
    // 0x806DFEF8: lwc1        $f8, 0x84($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X84);
    // 0x806DFEFC: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x806DFF00: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806DFF04: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806DFF08: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x806DFF0C: nop

    // 0x806DFF10: bc1fl       L_806DFF7C
    if (!c1cs) {
        // 0x806DFF14: lwc1        $f10, 0x3C($a1)
        ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
            goto L_806DFF7C;
    }
    goto skip_2;
    // 0x806DFF14: lwc1        $f10, 0x3C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
    skip_2:
    // 0x806DFF18: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806DFF1C: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806DFF20: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x806DFF24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806DFF28: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806DFF2C: addiu       $v1, $a1, 0xC4
    ctx->r3 = ADD32(ctx->r5, 0XC4);
    // 0x806DFF30: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806DFF34: nop

    // 0x806DFF38: bc1fl       L_806DFF7C
    if (!c1cs) {
        // 0x806DFF3C: lwc1        $f10, 0x3C($a1)
        ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
            goto L_806DFF7C;
    }
    goto skip_3;
    // 0x806DFF3C: lwc1        $f10, 0x3C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
    skip_3:
    // 0x806DFF40: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806DFF44: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806DFF48: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x806DFF4C: nop

    // 0x806DFF50: bc1fl       L_806DFFFC
    if (!c1cs) {
        // 0x806DFF54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806DFFFC;
    }
    goto skip_4;
    // 0x806DFF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x806DFF58: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x806DFF5C: lw          $a0, 0x1F4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1F4);
    // 0x806DFF60: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x806DFF64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806DFF68: lw          $t1, 0x34($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X34);
    // 0x806DFF6C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x806DFF70: jr          $ra
    // 0x806DFF74: sw          $t2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r10;
    return;
    // 0x806DFF74: sw          $t2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r10;
    // 0x806DFF78: lwc1        $f10, 0x3C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
L_806DFF7C:
    // 0x806DFF7C: lui         $at, 0xC1D0
    ctx->r1 = S32(0XC1D0 << 16);
    // 0x806DFF80: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806DFF84: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x806DFF88: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x806DFF8C: nop

    // 0x806DFF90: bc1fl       L_806DFFFC
    if (!c1cs) {
        // 0x806DFF94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806DFFFC;
    }
    goto skip_5;
    // 0x806DFF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x806DFF98: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806DFF9C: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806DFFA0: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x806DFFA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806DFFA8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806DFFAC: addiu       $v1, $a1, 0xC4
    ctx->r3 = ADD32(ctx->r5, 0XC4);
    // 0x806DFFB0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806DFFB4: nop

    // 0x806DFFB8: bc1fl       L_806DFFFC
    if (!c1cs) {
        // 0x806DFFBC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806DFFFC;
    }
    goto skip_6;
    // 0x806DFFBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x806DFFC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806DFFC4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806DFFC8: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x806DFFCC: nop

    // 0x806DFFD0: bc1fl       L_806DFFFC
    if (!c1cs) {
        // 0x806DFFD4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806DFFFC;
    }
    goto skip_7;
    // 0x806DFFD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x806DFFD8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x806DFFDC: lw          $a0, 0x1F4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1F4);
    // 0x806DFFE0: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x806DFFE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806DFFE8: lw          $t3, 0x34($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X34);
    // 0x806DFFEC: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x806DFFF0: jr          $ra
    // 0x806DFFF4: sw          $t4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r12;
    return;
    // 0x806DFFF4: sw          $t4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r12;
    // 0x806DFFF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806DFFFC:
    // 0x806DFFFC: jr          $ra
    // 0x806E0000: nop

    return;
    // 0x806E0000: nop

;}
RECOMP_FUNC void func_80536654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536654: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536658: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053665C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536660: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536664: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536668: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053666C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536670: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536674: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536678: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053667C: jr          $ra
    // 0x80536680: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536680: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807A1ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1ED0: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(844, 0X170) << 16);
    // 0x807A1ED4: lw          $t6, 0x2040($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(844, 0X170));
    // 0x807A1ED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A1EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A1EE0: bne         $t6, $zero, L_807A1F24
    if (ctx->r14 != 0) {
        // 0x807A1EE4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_807A1F24;
    }
    // 0x807A1EE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807A1EE8: lui         $a0, 0x807A
    ctx->r4 = S32(RELOC_HI16(844, 0X220) << 16);
    // 0x807A1EEC: lui         $a1, 0x807A
    ctx->r5 = S32(RELOC_HI16(844, 0X230) << 16);
    // 0x807A1EF0: addiu       $a1, $a1, 0x2100
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(844, 0X230));
    // 0x807A1EF4: addiu       $a0, $a0, 0x20F0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(844, 0X220));
    // 0x807A1EF8: jal         0x8004667C
    // 0x807A1EFC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x807A1EFC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x807A1F00: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x807A1F04: lui         $a2, 0x807A
    ctx->r6 = S32(RELOC_HI16(844, 0XFC) << 16);
    // 0x807A1F08: addiu       $a2, $a2, 0x1FCC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(844, 0XFC));
    // 0x807A1F0C: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x807A1F10: jal         0x80057B28
    // 0x807A1F14: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x807A1F14: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_1:
    // 0x807A1F18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807A1F1C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(844, 0X170) << 16);
    // 0x807A1F20: sw          $t7, 0x2040($at)
    MEM_W((int16_t)RELOC_LO16(844, 0X170), ctx->r1) = ctx->r15;
L_807A1F24:
    // 0x807A1F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A1F28: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(844, 0X68) << 16);
    // 0x807A1F2C: addiu       $v0, $v0, 0x1F38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(844, 0X68));
    // 0x807A1F30: jr          $ra
    // 0x807A1F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807A1F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80532554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8053255C: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80532560: lw          $t0, 0x1E0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1E0);
    // 0x80532564: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80532568: lw          $v0, 0x88($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X88);
    // 0x8053256C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80532570: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80532574: addiu       $t9, $t9, 0x5284
    ctx->r25 = ADD32(ctx->r25, 0X5284);
    // 0x80532578: sll         $t1, $t0, 9
    ctx->r9 = S32(ctx->r8 << 9);
    // 0x8053257C: sw          $t7, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r15;
    // 0x80532580: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80532584: sb          $t8, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r24;
    // 0x80532588: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8053258C: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80532590: jal         0x8004590C
    // 0x80532594: addu        $a1, $t1, $v0
    ctx->r5 = ADD32(ctx->r9, ctx->r2);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x80532594: addu        $a1, $t1, $v0
    ctx->r5 = ADD32(ctx->r9, ctx->r2);
    after_0:
    // 0x80532598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8053259C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805325A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805325A4: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x805325A8: jr          $ra
    // 0x805325AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805325AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80708E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80708E90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80708E94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80708E98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80708E9C: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(715, 0X230) << 16);
    // 0x80708EA0: lui         $a1, 0x460C
    ctx->r5 = S32(0X460C << 16);
    // 0x80708EA4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80708EA8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80708EAC: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x80708EB0: addiu       $a0, $a0, -0x70B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(715, 0X230));
    // 0x80708EB4: jal         0x80046804
    // 0x80708EB8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x80708EB8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80708EBC: bne         $v0, $zero, L_80708ECC
    if (ctx->r2 != 0) {
        // 0x80708EC0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80708ECC;
    }
    // 0x80708EC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80708EC4: b           L_80708ED0
    // 0x80708EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80708ED0;
    // 0x80708EC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80708ECC:
    // 0x80708ECC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80708ED0:
    // 0x80708ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80708ED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80708ED8: jr          $ra
    // 0x80708EDC: nop

    return;
    // 0x80708EDC: nop

;}
RECOMP_FUNC void func_8045F55C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F55C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8045F560: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8045F564: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8045F568: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8045F56C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8045F570: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045F574: lw          $t6, 0x3C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X3C);
    // 0x8045F578: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8045F57C: lwc1        $f24, 0x50($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8045F580: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8045F584: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8045F588: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8045F58C: jal         0x80066DE4
    // 0x8045F590: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8045F590: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8045F594: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8045F598: jal         0x80066E88
    // 0x8045F59C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8045F59C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_1:
    // 0x8045F5A0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8045F5A4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8045F5A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8045F5AC: lw          $t7, 0x8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X8);
    // 0x8045F5B0: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8045F5B4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(113, 0XAC8) << 16);
    // 0x8045F5B8: beq         $t7, $zero, L_8045F70C
    if (ctx->r15 == 0) {
        // 0x8045F5BC: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_8045F70C;
    }
    // 0x8045F5BC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8045F5C0: lwc1        $f20, -0x418($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(113, 0XAC8));
L_8045F5C4:
    // 0x8045F5C4: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
    // 0x8045F5C8: lw          $a0, 0xC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC);
    // 0x8045F5CC: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x8045F5D0: beq         $t8, $zero, L_8045F664
    if (ctx->r24 == 0) {
        // 0x8045F5D4: andi        $t9, $v1, 0x2
        ctx->r25 = ctx->r3 & 0X2;
            goto L_8045F664;
    }
    // 0x8045F5D4: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x8045F5D8: beql        $t9, $zero, L_8045F638
    if (ctx->r25 == 0) {
        // 0x8045F5DC: lh          $t2, 0x0($v0)
        ctx->r10 = MEM_H(ctx->r2, 0X0);
            goto L_8045F638;
    }
    goto skip_0;
    // 0x8045F5DC: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    skip_0:
    // 0x8045F5E0: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x8045F5E4: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x8045F5E8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8045F5EC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8045F5F0: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8045F5F4: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8045F5F8: mul.s       $f8, $f14, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x8045F5FC: nop

    // 0x8045F600: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8045F604: nop

    // 0x8045F608: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8045F60C: nop

    // 0x8045F610: mul.s       $f6, $f16, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8045F614: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8045F618: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8045F61C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8045F620: mul.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8045F624: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    // 0x8045F628: swc1        $f12, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f12.u32l;
    // 0x8045F62C: b           L_8045F664
    // 0x8045F630: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
        goto L_8045F664;
    // 0x8045F630: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
    // 0x8045F634: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
L_8045F638:
    // 0x8045F638: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x8045F63C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8045F640: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8045F644: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8045F648: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8045F64C: mul.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8045F650: nop

    // 0x8045F654: mul.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8045F658: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    // 0x8045F65C: swc1        $f12, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f12.u32l;
    // 0x8045F660: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
L_8045F664:
    // 0x8045F664: andi        $t4, $v1, 0x4
    ctx->r12 = ctx->r3 & 0X4;
    // 0x8045F668: beq         $t4, $zero, L_8045F6B0
    if (ctx->r12 == 0) {
        // 0x8045F66C: andi        $t5, $v1, 0x8
        ctx->r13 = ctx->r3 & 0X8;
            goto L_8045F6B0;
    }
    // 0x8045F66C: andi        $t5, $v1, 0x8
    ctx->r13 = ctx->r3 & 0X8;
    // 0x8045F670: beql        $t5, $zero, L_8045F69C
    if (ctx->r13 == 0) {
        // 0x8045F674: lh          $t7, 0x4($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X4);
            goto L_8045F69C;
    }
    goto skip_1;
    // 0x8045F674: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    skip_1:
    // 0x8045F678: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8045F67C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8045F680: nop

    // 0x8045F684: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8045F688: add.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8045F68C: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x8045F690: b           L_8045F6B0
    // 0x8045F694: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
        goto L_8045F6B0;
    // 0x8045F694: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
    // 0x8045F698: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
L_8045F69C:
    // 0x8045F69C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8045F6A0: nop

    // 0x8045F6A4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8045F6A8: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8045F6AC: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
L_8045F6B0:
    // 0x8045F6B0: andi        $t8, $v1, 0x10
    ctx->r24 = ctx->r3 & 0X10;
    // 0x8045F6B4: beql        $t8, $zero, L_8045F6F8
    if (ctx->r24 == 0) {
        // 0x8045F6B8: lw          $t1, 0x8($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X8);
            goto L_8045F6F8;
    }
    goto skip_2;
    // 0x8045F6B8: lw          $t1, 0x8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X8);
    skip_2:
    // 0x8045F6BC: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8045F6C0: lh          $t0, 0x8($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X8);
    // 0x8045F6C4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8045F6C8: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8045F6CC: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8045F6D0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8045F6D4: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8045F6D8: nop

    // 0x8045F6DC: mul.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8045F6E0: nop

    // 0x8045F6E4: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8045F6E8: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x8045F6EC: mul.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8045F6F0: swc1        $f12, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f12.u32l;
    // 0x8045F6F4: lw          $t1, 0x8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X8);
L_8045F6F8:
    // 0x8045F6F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8045F6FC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8045F700: sltu        $at, $a1, $t1
    ctx->r1 = ctx->r5 < ctx->r9 ? 1 : 0;
    // 0x8045F704: bne         $at, $zero, L_8045F5C4
    if (ctx->r1 != 0) {
        // 0x8045F708: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_8045F5C4;
    }
    // 0x8045F708: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8045F70C:
    // 0x8045F70C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8045F710: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8045F714: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8045F718: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8045F71C: jr          $ra
    // 0x8045F720: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8045F720: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80423E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80423E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80423E88: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80423E8C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80423E90: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X3278) << 16);
    // 0x80423E94: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80423E98: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80423E9C: lw          $t8, 0x5C78($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X3278));
    // 0x80423EA0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80423EA4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80423EA8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80423EAC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80423EB0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80423EB4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80423EB8: beql        $v1, $zero, L_80423EEC
    if (ctx->r3 == 0) {
        // 0x80423EBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80423EEC;
    }
    goto skip_0;
    // 0x80423EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80423EC0: jalr        $v1
    // 0x80423EC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80423EC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80423EC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80423ECC: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80423ED0: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80423ED4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80423ED8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80423EDC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80423EE0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80423EE4: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80423EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80423EEC:
    // 0x80423EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80423EF0: jr          $ra
    // 0x80423EF4: nop

    return;
    // 0x80423EF4: nop

;}
RECOMP_FUNC void func_804B6EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6EF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B6EFC: jal         0x804B6CE4
    // 0x804B6F00: addiu       $a1, $zero, 0x45AB
    ctx->r5 = ADD32(0, 0X45AB);
    func_804B6CE4(rdram, ctx);
        goto after_0;
    // 0x804B6F00: addiu       $a1, $zero, 0x45AB
    ctx->r5 = ADD32(0, 0X45AB);
    after_0:
    // 0x804B6F04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6F08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6F0C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804B6F10: jal         0x804B6FF0
    // 0x804B6F14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B6F14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804B6F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6F20: jr          $ra
    // 0x804B6F24: nop

    return;
    // 0x804B6F24: nop

;}
RECOMP_FUNC void func_8042D1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042D1C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042D1CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042D1D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042D1D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8042D1D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8042D1DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8042D1E0: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8042D1E4: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8042D1E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8042D1EC: bne         $v0, $at, L_8042D294
    if (ctx->r2 != ctx->r1) {
        // 0x8042D1F0: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8042D294;
    }
    // 0x8042D1F0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8042D1F4: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x8042D1F8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8042D1FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8042D200: bnel        $t6, $at, L_8042D298
    if (ctx->r14 != ctx->r1) {
        // 0x8042D204: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042D298;
    }
    goto skip_0;
    // 0x8042D204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042D208: sb          $t7, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r15;
    // 0x8042D20C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8042D210: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8042D214: lw          $t9, 0x1C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1C);
    // 0x8042D218: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8042D21C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042D220: jalr        $t9
    // 0x8042D224: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042D224: nop

    after_0:
    // 0x8042D228: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8042D22C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8042D230: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8042D234: lwc1        $f4, 0x84($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8042D238: lwc1        $f6, 0x84($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X84);
    // 0x8042D23C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8042D240: nop

    // 0x8042D244: bc1fl       L_8042D260
    if (!c1cs) {
        // 0x8042D248: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8042D260;
    }
    goto skip_1;
    // 0x8042D248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x8042D24C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8042D250: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042D254: b           L_8042D268
    // 0x8042D258: swc1        $f8, 0xC4($a2)
    MEM_W(0XC4, ctx->r6) = ctx->f8.u32l;
        goto L_8042D268;
    // 0x8042D258: swc1        $f8, 0xC4($a2)
    MEM_W(0XC4, ctx->r6) = ctx->f8.u32l;
    // 0x8042D25C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8042D260:
    // 0x8042D260: nop

    // 0x8042D264: swc1        $f10, 0xC4($a2)
    MEM_W(0XC4, ctx->r6) = ctx->f10.u32l;
L_8042D268:
    // 0x8042D268: jal         0x8042D090
    // 0x8042D26C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8042D090(rdram, ctx);
        goto after_1;
    // 0x8042D26C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8042D270: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x8042D274: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8042D278: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x8042D27C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8042D280: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x8042D284: sb          $t0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r8;
    // 0x8042D288: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8042D28C: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8042D290: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
L_8042D294:
    // 0x8042D294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042D298:
    // 0x8042D298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042D29C: jr          $ra
    // 0x8042D2A0: nop

    return;
    // 0x8042D2A0: nop

;}
RECOMP_FUNC void func_806F7160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7160: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F7164: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F7168: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806F716C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806F7170: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x806F7174: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806F7178: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F717C: bne         $t6, $zero, L_806F71C0
    if (ctx->r14 != 0) {
        // 0x806F7180: addiu       $s0, $s1, 0xC4
        ctx->r16 = ADD32(ctx->r17, 0XC4);
            goto L_806F71C0;
    }
    // 0x806F7180: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x806F7184: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x806F7188: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F718C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806F7190: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x806F7194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F7198: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806F719C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F71A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x806F71A4: bc1fl       L_806F71F8
    if (!c1cs) {
        // 0x806F71A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806F71F8;
    }
    goto skip_0;
    // 0x806F71A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x806F71AC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x806F71B0: jal         0x806F73DC
    // 0x806F71B4: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    func_806F73DC(rdram, ctx);
        goto after_0;
    // 0x806F71B4: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    after_0:
    // 0x806F71B8: b           L_806F71F8
    // 0x806F71BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_806F71F8;
    // 0x806F71BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806F71C0:
    // 0x806F71C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F71C4: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806F71C8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x806F71CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F71D0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x806F71D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F71D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F71DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806F71E0: bc1fl       L_806F71F8
    if (!c1cs) {
        // 0x806F71E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806F71F8;
    }
    goto skip_1;
    // 0x806F71E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x806F71E8: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x806F71EC: jal         0x806F73DC
    // 0x806F71F0: sb          $t8, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r24;
    func_806F73DC(rdram, ctx);
        goto after_1;
    // 0x806F71F0: sb          $t8, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r24;
    after_1:
    // 0x806F71F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806F71F8:
    // 0x806F71F8: jal         0x806F6E20
    // 0x806F71FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806F6E20(rdram, ctx);
        goto after_2;
    // 0x806F71FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x806F7200: jal         0x806F6F08
    // 0x806F7204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806F6F08(rdram, ctx);
        goto after_3;
    // 0x806F7204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x806F7208: jal         0x806F6F64
    // 0x806F720C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806F6F64(rdram, ctx);
        goto after_4;
    // 0x806F720C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x806F7210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F7214: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806F7218: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806F721C: jr          $ra
    // 0x806F7220: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806F7220: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000C560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C560: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000C564: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000C568: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C56C: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x8000C570: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000C574: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x8000C578: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8000C57C: beq         $t6, $zero, L_8000C5D8
    if (ctx->r14 == 0) {
        // 0x8000C580: andi        $t9, $v0, 0x2
        ctx->r25 = ctx->r2 & 0X2;
            goto L_8000C5D8;
    }
    // 0x8000C580: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x8000C584: lw          $a2, 0x2C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X2C);
    // 0x8000C588: beq         $a2, $zero, L_8000C5D8
    if (ctx->r6 == 0) {
        // 0x8000C58C: nop
    
            goto L_8000C5D8;
    }
    // 0x8000C58C: nop

    // 0x8000C590: lw          $t7, 0x40($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X40);
    // 0x8000C594: bne         $a0, $t7, L_8000C5D8
    if (ctx->r4 != ctx->r15) {
        // 0x8000C598: nop
    
            goto L_8000C5D8;
    }
    // 0x8000C598: nop

    // 0x8000C59C: lw          $t8, 0x48($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X48);
    // 0x8000C5A0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C5A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8000C5A8: bne         $t8, $at, L_8000C5D8
    if (ctx->r24 != ctx->r1) {
        // 0x8000C5AC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8000C5D8;
    }
    // 0x8000C5AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C5B0: jal         0x8000C3A0
    // 0x8000C5B4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8000C3A0(rdram, ctx);
        goto after_0;
    // 0x8000C5B4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000C5B8: jal         0x8000C170
    // 0x8000C5BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8000C170(rdram, ctx);
        goto after_1;
    // 0x8000C5BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8000C5C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8000C5C4: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    // 0x8000C5C8: jal         0x8000DB94
    // 0x8000C5CC: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    func_8000DB94(rdram, ctx);
        goto after_2;
    // 0x8000C5CC: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_2:
    // 0x8000C5D0: b           L_8000C7CC
    // 0x8000C5D4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_8000C7CC;
    // 0x8000C5D4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8000C5D8:
    // 0x8000C5D8: beq         $t9, $zero, L_8000C62C
    if (ctx->r25 == 0) {
        // 0x8000C5DC: andi        $t0, $v0, 0x4
        ctx->r8 = ctx->r2 & 0X4;
            goto L_8000C62C;
    }
    // 0x8000C5DC: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x8000C5E0: addiu       $a0, $v1, 0x8C
    ctx->r4 = ADD32(ctx->r3, 0X8C);
    // 0x8000C5E4: jal         0x8000C3CC
    // 0x8000C5E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000C3CC(rdram, ctx);
        goto after_3;
    // 0x8000C5E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8000C5EC: bne         $v0, $zero, L_8000C624
    if (ctx->r2 != 0) {
        // 0x8000C5F0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C624;
    }
    // 0x8000C5F0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C5F4: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000C5F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C5FC: jal         0x8000C418
    // 0x8000C600: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    func_8000C418(rdram, ctx);
        goto after_4;
    // 0x8000C600: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    after_4:
    // 0x8000C604: bne         $v0, $zero, L_8000C624
    if (ctx->r2 != 0) {
        // 0x8000C608: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C624;
    }
    // 0x8000C608: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C60C: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000C610: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C614: jal         0x8000C468
    // 0x8000C618: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    func_8000C468(rdram, ctx);
        goto after_5;
    // 0x8000C618: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    after_5:
    // 0x8000C61C: beq         $v0, $zero, L_8000C7BC
    if (ctx->r2 == 0) {
        // 0x8000C620: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C7BC;
    }
    // 0x8000C620: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8000C624:
    // 0x8000C624: b           L_8000C7CC
    // 0x8000C628: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_8000C7CC;
    // 0x8000C628: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8000C62C:
    // 0x8000C62C: beq         $t0, $zero, L_8000C6D4
    if (ctx->r8 == 0) {
        // 0x8000C630: andi        $t4, $v0, 0x8
        ctx->r12 = ctx->r2 & 0X8;
            goto L_8000C6D4;
    }
    // 0x8000C630: andi        $t4, $v0, 0x8
    ctx->r12 = ctx->r2 & 0X8;
    // 0x8000C634: addiu       $a0, $v1, 0x8C
    ctx->r4 = ADD32(ctx->r3, 0X8C);
    // 0x8000C638: jal         0x8000C3CC
    // 0x8000C63C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000C3CC(rdram, ctx);
        goto after_6;
    // 0x8000C63C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8000C640: bne         $v0, $zero, L_8000C6CC
    if (ctx->r2 != 0) {
        // 0x8000C644: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C6CC;
    }
    // 0x8000C644: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C648: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x8000C64C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C650: lw          $a0, 0x4C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4C);
    // 0x8000C654: jal         0x8000C3CC
    // 0x8000C658: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    func_8000C3CC(rdram, ctx);
        goto after_7;
    // 0x8000C658: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_7:
    // 0x8000C65C: bne         $v0, $zero, L_8000C6CC
    if (ctx->r2 != 0) {
        // 0x8000C660: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C6CC;
    }
    // 0x8000C660: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C664: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000C668: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C66C: jal         0x8000C418
    // 0x8000C670: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    func_8000C418(rdram, ctx);
        goto after_8;
    // 0x8000C670: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    after_8:
    // 0x8000C674: bne         $v0, $zero, L_8000C6CC
    if (ctx->r2 != 0) {
        // 0x8000C678: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C6CC;
    }
    // 0x8000C678: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C67C: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x8000C680: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C684: lw          $a0, 0x4C($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4C);
    // 0x8000C688: jal         0x8000C418
    // 0x8000C68C: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    func_8000C418(rdram, ctx);
        goto after_9;
    // 0x8000C68C: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_9:
    // 0x8000C690: bne         $v0, $zero, L_8000C6CC
    if (ctx->r2 != 0) {
        // 0x8000C694: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C6CC;
    }
    // 0x8000C694: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C698: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000C69C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C6A0: jal         0x8000C468
    // 0x8000C6A4: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    func_8000C468(rdram, ctx);
        goto after_10;
    // 0x8000C6A4: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    after_10:
    // 0x8000C6A8: bne         $v0, $zero, L_8000C6CC
    if (ctx->r2 != 0) {
        // 0x8000C6AC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C6CC;
    }
    // 0x8000C6AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C6B0: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x8000C6B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C6B8: lw          $a0, 0x4C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4C);
    // 0x8000C6BC: jal         0x8000C468
    // 0x8000C6C0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    func_8000C468(rdram, ctx);
        goto after_11;
    // 0x8000C6C0: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_11:
    // 0x8000C6C4: beq         $v0, $zero, L_8000C7BC
    if (ctx->r2 == 0) {
        // 0x8000C6C8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C7BC;
    }
    // 0x8000C6C8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8000C6CC:
    // 0x8000C6CC: b           L_8000C7CC
    // 0x8000C6D0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_8000C7CC;
    // 0x8000C6D0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8000C6D4:
    // 0x8000C6D4: beq         $t4, $zero, L_8000C72C
    if (ctx->r12 == 0) {
        // 0x8000C6D8: addiu       $a0, $v1, 0x8C
        ctx->r4 = ADD32(ctx->r3, 0X8C);
            goto L_8000C72C;
    }
    // 0x8000C6D8: addiu       $a0, $v1, 0x8C
    ctx->r4 = ADD32(ctx->r3, 0X8C);
    // 0x8000C6DC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000C6E0: addiu       $a0, $a0, -0x63B4
    ctx->r4 = ADD32(ctx->r4, -0X63B4);
    // 0x8000C6E4: jal         0x8000C3CC
    // 0x8000C6E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000C3CC(rdram, ctx);
        goto after_12;
    // 0x8000C6E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x8000C6EC: bne         $v0, $zero, L_8000C724
    if (ctx->r2 != 0) {
        // 0x8000C6F0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C724;
    }
    // 0x8000C6F0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C6F4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000C6F8: addiu       $a0, $a0, -0x63B4
    ctx->r4 = ADD32(ctx->r4, -0X63B4);
    // 0x8000C6FC: jal         0x8000C418
    // 0x8000C700: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000C418(rdram, ctx);
        goto after_13;
    // 0x8000C700: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x8000C704: bne         $v0, $zero, L_8000C724
    if (ctx->r2 != 0) {
        // 0x8000C708: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C724;
    }
    // 0x8000C708: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C70C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000C710: addiu       $a0, $a0, -0x63B4
    ctx->r4 = ADD32(ctx->r4, -0X63B4);
    // 0x8000C714: jal         0x8000C468
    // 0x8000C718: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000C468(rdram, ctx);
        goto after_14;
    // 0x8000C718: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x8000C71C: beq         $v0, $zero, L_8000C7BC
    if (ctx->r2 == 0) {
        // 0x8000C720: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C7BC;
    }
    // 0x8000C720: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8000C724:
    // 0x8000C724: b           L_8000C7CC
    // 0x8000C728: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_8000C7CC;
    // 0x8000C728: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8000C72C:
    // 0x8000C72C: jal         0x8000C3CC
    // 0x8000C730: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000C3CC(rdram, ctx);
        goto after_15;
    // 0x8000C730: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
    // 0x8000C734: bne         $v0, $zero, L_8000C7B4
    if (ctx->r2 != 0) {
        // 0x8000C738: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C7B4;
    }
    // 0x8000C738: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C73C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000C740: addiu       $a0, $a0, -0x63B4
    ctx->r4 = ADD32(ctx->r4, -0X63B4);
    // 0x8000C744: jal         0x8000C3CC
    // 0x8000C748: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000C3CC(rdram, ctx);
        goto after_16;
    // 0x8000C748: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x8000C74C: bne         $v0, $zero, L_8000C7B4
    if (ctx->r2 != 0) {
        // 0x8000C750: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C7B4;
    }
    // 0x8000C750: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C754: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000C758: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C75C: jal         0x8000C418
    // 0x8000C760: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    func_8000C418(rdram, ctx);
        goto after_17;
    // 0x8000C760: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    after_17:
    // 0x8000C764: bne         $v0, $zero, L_8000C7B4
    if (ctx->r2 != 0) {
        // 0x8000C768: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C7B4;
    }
    // 0x8000C768: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C76C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000C770: addiu       $a0, $a0, -0x63B4
    ctx->r4 = ADD32(ctx->r4, -0X63B4);
    // 0x8000C774: jal         0x8000C418
    // 0x8000C778: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000C418(rdram, ctx);
        goto after_18;
    // 0x8000C778: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
    // 0x8000C77C: bne         $v0, $zero, L_8000C7B4
    if (ctx->r2 != 0) {
        // 0x8000C780: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C7B4;
    }
    // 0x8000C780: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C784: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000C788: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000C78C: jal         0x8000C468
    // 0x8000C790: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    func_8000C468(rdram, ctx);
        goto after_19;
    // 0x8000C790: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    after_19:
    // 0x8000C794: bne         $v0, $zero, L_8000C7B4
    if (ctx->r2 != 0) {
        // 0x8000C798: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C7B4;
    }
    // 0x8000C798: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000C79C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000C7A0: addiu       $a0, $a0, -0x63B4
    ctx->r4 = ADD32(ctx->r4, -0X63B4);
    // 0x8000C7A4: jal         0x8000C468
    // 0x8000C7A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000C468(rdram, ctx);
        goto after_20;
    // 0x8000C7A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_20:
    // 0x8000C7AC: beq         $v0, $zero, L_8000C7BC
    if (ctx->r2 == 0) {
        // 0x8000C7B0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8000C7BC;
    }
    // 0x8000C7B0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8000C7B4:
    // 0x8000C7B4: b           L_8000C7CC
    // 0x8000C7B8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_8000C7CC;
    // 0x8000C7B8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8000C7BC:
    // 0x8000C7BC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8000C7C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C7C4: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x8000C7C8: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
L_8000C7CC:
    // 0x8000C7CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C7D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000C7D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000C7D8: jr          $ra
    // 0x8000C7DC: nop

    return;
    // 0x8000C7DC: nop

;}
RECOMP_FUNC void func_806B2A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2A6C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2A70: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2A74: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2A78: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2A7C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2A80: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2A84: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2A88: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2A8C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2A90: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2A94: jr          $ra
    // 0x806B2A98: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2A98: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804C0AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0AB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C0AB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C0AB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C0ABC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804C0AC0: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(200, 0X400) << 16);
    // 0x804C0AC4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804C0AC8: addiu       $t6, $t6, 0xE60
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(200, 0X400));
    // 0x804C0ACC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804C0AD0: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804C0AD4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x804C0AD8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804C0ADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C0AE0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804C0AE4: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x804C0AE8: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x804C0AEC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x804C0AF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C0AF4: jal         0x804C0D70
    // 0x804C0AF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804C0D70(rdram, ctx);
        goto after_0;
    // 0x804C0AF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x804C0AFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804C0B00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804C0B04: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804C0B08: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804C0B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C0B10: bnel        $t1, $zero, L_804C0B28
    if (ctx->r9 != 0) {
        // 0x804C0B14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804C0B28;
    }
    goto skip_0;
    // 0x804C0B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x804C0B18: jal         0x80045A34
    // 0x804C0B1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x804C0B1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x804C0B20: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804C0B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_804C0B28:
    // 0x804C0B28: jal         0x80057640
    // 0x804C0B2C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80057640(rdram, ctx);
        goto after_2;
    // 0x804C0B2C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x804C0B30: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x804C0B34: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x804C0B38: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x804C0B3C: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x804C0B40: jal         0x8005772C
    // 0x804C0B44: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    func_8005772C(rdram, ctx);
        goto after_3;
    // 0x804C0B44: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_3:
    // 0x804C0B48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C0B4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C0B50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C0B54: jr          $ra
    // 0x804C0B58: nop

    return;
    // 0x804C0B58: nop

;}
RECOMP_FUNC void func_807C6180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6180: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807C6184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C6188: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807C618C: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C6190: jal         0x8004700C
    // 0x807C6194: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807C6194: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x807C6198: beq         $v0, $zero, L_807C6324
    if (ctx->r2 == 0) {
        // 0x807C619C: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_807C6324;
    }
    // 0x807C619C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x807C61A0: lbu         $a0, 0x18($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X18);
    // 0x807C61A4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x807C61A8: bne         $a1, $a0, L_807C61F8
    if (ctx->r5 != ctx->r4) {
        // 0x807C61AC: nop
    
            goto L_807C61F8;
    }
    // 0x807C61AC: nop

    // 0x807C61B0: lw          $t7, 0x10($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X10);
    // 0x807C61B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807C61B8: bne         $t7, $zero, L_807C61F0
    if (ctx->r15 != 0) {
        // 0x807C61BC: nop
    
            goto L_807C61F0;
    }
    // 0x807C61BC: nop

    // 0x807C61C0: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x807C61C4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x807C61C8: beq         $v1, $at, L_807C61F0
    if (ctx->r3 == ctx->r1) {
        // 0x807C61CC: nop
    
            goto L_807C61F0;
    }
    // 0x807C61CC: nop

    // 0x807C61D0: beq         $a1, $v1, L_807C61F0
    if (ctx->r5 == ctx->r3) {
        // 0x807C61D4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_807C61F0;
    }
    // 0x807C61D4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x807C61D8: beq         $v1, $at, L_807C61F0
    if (ctx->r3 == ctx->r1) {
        // 0x807C61DC: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_807C61F0;
    }
    // 0x807C61DC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x807C61E0: beq         $v1, $at, L_807C61F0
    if (ctx->r3 == ctx->r1) {
        // 0x807C61E4: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_807C61F0;
    }
    // 0x807C61E4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x807C61E8: bne         $v1, $at, L_807C61F8
    if (ctx->r3 != ctx->r1) {
        // 0x807C61EC: nop
    
            goto L_807C61F8;
    }
    // 0x807C61EC: nop

L_807C61F0:
    // 0x807C61F0: b           L_807C6324
    // 0x807C61F4: sw          $t8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r24;
        goto L_807C6324;
    // 0x807C61F4: sw          $t8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r24;
L_807C61F8:
    // 0x807C61F8: bne         $a1, $a0, L_807C6270
    if (ctx->r5 != ctx->r4) {
        // 0x807C61FC: nop
    
            goto L_807C6270;
    }
    // 0x807C61FC: nop

    // 0x807C6200: lw          $t9, 0x10($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X10);
    // 0x807C6204: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807C6208: bne         $t9, $zero, L_807C6268
    if (ctx->r25 != 0) {
        // 0x807C620C: nop
    
            goto L_807C6268;
    }
    // 0x807C620C: nop

    // 0x807C6210: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x807C6214: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x807C6218: beq         $v1, $zero, L_807C6268
    if (ctx->r3 == 0) {
        // 0x807C621C: nop
    
            goto L_807C6268;
    }
    // 0x807C621C: nop

    // 0x807C6220: beq         $v1, $at, L_807C6268
    if (ctx->r3 == ctx->r1) {
        // 0x807C6224: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_807C6268;
    }
    // 0x807C6224: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x807C6228: beq         $v1, $at, L_807C6268
    if (ctx->r3 == ctx->r1) {
        // 0x807C622C: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_807C6268;
    }
    // 0x807C622C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x807C6230: beq         $v1, $at, L_807C6268
    if (ctx->r3 == ctx->r1) {
        // 0x807C6234: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_807C6268;
    }
    // 0x807C6234: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x807C6238: beq         $v1, $at, L_807C6268
    if (ctx->r3 == ctx->r1) {
        // 0x807C623C: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_807C6268;
    }
    // 0x807C623C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x807C6240: beq         $v1, $at, L_807C6268
    if (ctx->r3 == ctx->r1) {
        // 0x807C6244: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_807C6268;
    }
    // 0x807C6244: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x807C6248: beq         $v1, $at, L_807C6268
    if (ctx->r3 == ctx->r1) {
        // 0x807C624C: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_807C6268;
    }
    // 0x807C624C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x807C6250: beq         $v1, $at, L_807C6268
    if (ctx->r3 == ctx->r1) {
        // 0x807C6254: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_807C6268;
    }
    // 0x807C6254: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x807C6258: beq         $v1, $at, L_807C6268
    if (ctx->r3 == ctx->r1) {
        // 0x807C625C: addiu       $at, $zero, 0x1D
        ctx->r1 = ADD32(0, 0X1D);
            goto L_807C6268;
    }
    // 0x807C625C: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x807C6260: bne         $v1, $at, L_807C6270
    if (ctx->r3 != ctx->r1) {
        // 0x807C6264: nop
    
            goto L_807C6270;
    }
    // 0x807C6264: nop

L_807C6268:
    // 0x807C6268: b           L_807C6324
    // 0x807C626C: sw          $t0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r8;
        goto L_807C6324;
    // 0x807C626C: sw          $t0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r8;
L_807C6270:
    // 0x807C6270: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x807C6274: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x807C6278: lw          $t1, 0xE88($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XE88);
    // 0x807C627C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x807C6280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C6284: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x807C6288: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807C628C: bnel        $t2, $at, L_807C62A8
    if (ctx->r10 != ctx->r1) {
        // 0x807C6290: lw          $v0, 0x478($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X478);
            goto L_807C62A8;
    }
    goto skip_0;
    // 0x807C6290: lw          $v0, 0x478($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X478);
    skip_0:
    // 0x807C6294: jal         0x807C66CC
    // 0x807C6298: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_807C66CC(rdram, ctx);
        goto after_1;
    // 0x807C6298: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x807C629C: b           L_807C6328
    // 0x807C62A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807C6328;
    // 0x807C62A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C62A4: lw          $v0, 0x478($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X478);
L_807C62A8:
    // 0x807C62A8: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x807C62AC: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x807C62B0: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x807C62B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807C62B8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x807C62BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807C62C0: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(913, 0X964) << 16);
    // 0x807C62C4: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x807C62C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C62CC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x807C62D0: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x807C62D4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807C62D8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807C62DC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x807C62E0: swc1        $f4, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f4.u32l;
    // 0x807C62E4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x807C62E8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x807C62EC: swc1        $f6, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f6.u32l;
    // 0x807C62F0: lw          $v1, 0x8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X8);
    // 0x807C62F4: beq         $v1, $zero, L_807C6304
    if (ctx->r3 == 0) {
        // 0x807C62F8: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_807C6304;
    }
    // 0x807C62F8: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x807C62FC: sw          $t5, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r13;
    // 0x807C6300: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_807C6304:
    // 0x807C6304: bnel        $v1, $zero, L_807C6328
    if (ctx->r3 != 0) {
        // 0x807C6308: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807C6328;
    }
    goto skip_1;
    // 0x807C6308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x807C630C: lwc1        $f8, 0x6754($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(913, 0X964));
    // 0x807C6310: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
    // 0x807C6314: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x807C6318: swc1        $f8, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f8.u32l;
    // 0x807C631C: jal         0x807C66CC
    // 0x807C6320: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_807C66CC(rdram, ctx);
        goto after_2;
    // 0x807C6320: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
L_807C6324:
    // 0x807C6324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807C6328:
    // 0x807C6328: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807C632C: jr          $ra
    // 0x807C6330: nop

    return;
    // 0x807C6330: nop

;}
RECOMP_FUNC void func_8079A860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A860: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8079A864: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8079A868: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8079A86C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8079A870: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8079A874: nop

    // 0x8079A878: bc1f        L_8079A888
    if (!c1cs) {
        // 0x8079A87C: nop
    
            goto L_8079A888;
    }
    // 0x8079A87C: nop

    // 0x8079A880: jr          $ra
    // 0x8079A884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8079A884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8079A888:
    // 0x8079A888: jr          $ra
    // 0x8079A88C: nop

    return;
    // 0x8079A88C: nop

;}
RECOMP_FUNC void func_805ACB0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ACB0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805ACB10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805ACB14: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805ACB18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805ACB1C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805ACB20: jal         0x805AC884
    // 0x805ACB24: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_805AC884(rdram, ctx);
        goto after_0;
    // 0x805ACB24: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805ACB28: jal         0x805AC528
    // 0x805ACB2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805AC528(rdram, ctx);
        goto after_1;
    // 0x805ACB2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x805ACB30: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x805ACB34: beq         $v0, $zero, L_805ACB44
    if (ctx->r2 == 0) {
        // 0x805ACB38: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805ACB44;
    }
    // 0x805ACB38: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805ACB3C: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x805ACB40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_805ACB44:
    // 0x805ACB44: bnel        $v0, $zero, L_805ACC10
    if (ctx->r2 != 0) {
        // 0x805ACB48: addiu       $a0, $s1, 0xC4
        ctx->r4 = ADD32(ctx->r17, 0XC4);
            goto L_805ACC10;
    }
    goto skip_0;
    // 0x805ACB48: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    skip_0:
    // 0x805ACB4C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x805ACB50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805ACB54: lui         $t7, 0x805B
    ctx->r15 = S32(RELOC_HI16(441, 0X1264) << 16);
    // 0x805ACB58: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x805ACB5C: bne         $at, $zero, L_805ACB7C
    if (ctx->r1 != 0) {
        // 0x805ACB60: sll         $v1, $v0, 2
        ctx->r3 = S32(ctx->r2 << 2);
            goto L_805ACB7C;
    }
    // 0x805ACB60: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x805ACB64: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x805ACB68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805ACB6C: jal         0x805AD274
    // 0x805ACB70: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_805AD274(rdram, ctx);
        goto after_2;
    // 0x805ACB70: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x805ACB74: b           L_805ACC1C
    // 0x805ACB78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805ACC1C;
    // 0x805ACB78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805ACB7C:
    // 0x805ACB7C: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x805ACB80: lw          $t7, -0x2BAC($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(441, 0X1264));
    // 0x805ACB84: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805ACB88: beq         $t7, $zero, L_805ACBBC
    if (ctx->r15 == 0) {
        // 0x805ACB8C: nop
    
            goto L_805ACBBC;
    }
    // 0x805ACB8C: nop

    // 0x805ACB90: lw          $t8, 0x138($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X138);
    // 0x805ACB94: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x805ACB98: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x805ACB9C: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x805ACBA0: jal         0x80067BBC
    // 0x805ACBA4: sw          $t0, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->r8;
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x805ACBA4: sw          $t0, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->r8;
    after_3:
    // 0x805ACBA8: addiu       $a0, $zero, 0x23E
    ctx->r4 = ADD32(0, 0X23E);
    // 0x805ACBAC: jal         0x80067818
    // 0x805ACBB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x805ACBB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x805ACBB4: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x805ACBB8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_805ACBBC:
    // 0x805ACBBC: lui         $t1, 0x805B
    ctx->r9 = S32(RELOC_HI16(441, 0X12AC) << 16);
    // 0x805ACBC0: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x805ACBC4: lw          $t1, -0x2B64($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(441, 0X12AC));
    // 0x805ACBC8: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x805ACBCC: lui         $t3, 0x805B
    ctx->r11 = S32(RELOC_HI16(441, 0X11E8) << 16);
    // 0x805ACBD0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x805ACBD4: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
    // 0x805ACBD8: lh          $t3, -0x2C28($t3)
    ctx->r11 = MEM_H(ctx->r11, (int16_t)RELOC_LO16(441, 0X11E8));
    // 0x805ACBDC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x805ACBE0: sh          $t3, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r11;
    // 0x805ACBE4: lw          $t4, 0x1C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C);
    // 0x805ACBE8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x805ACBEC: bne         $t5, $at, L_805ACC0C
    if (ctx->r13 != ctx->r1) {
        // 0x805ACBF0: sw          $t5, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->r13;
            goto L_805ACC0C;
    }
    // 0x805ACBF0: sw          $t5, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r13;
    // 0x805ACBF4: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x805ACBF8: jal         0x80067BBC
    // 0x805ACBFC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x805ACBFC: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_5:
    // 0x805ACC00: addiu       $a0, $zero, 0x25C
    ctx->r4 = ADD32(0, 0X25C);
    // 0x805ACC04: jal         0x80067818
    // 0x805ACC08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x805ACC08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
L_805ACC0C:
    // 0x805ACC0C: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
L_805ACC10:
    // 0x805ACC10: jal         0x80048F84
    // 0x805ACC14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x805ACC14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x805ACC18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805ACC1C:
    // 0x805ACC1C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805ACC20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805ACC24: jr          $ra
    // 0x805ACC28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805ACC28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80400040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400040: lui         $v0, 0x8040
    ctx->r2 = S32(RELOC_HI16(8, 0X19C) << 16);
    // 0x80400044: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80400048: jr          $ra
    // 0x8040004C: addiu       $v0, $v0, 0x1DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(8, 0X19C));
    return;
    // 0x8040004C: addiu       $v0, $v0, 0x1DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(8, 0X19C));
;}
RECOMP_FUNC void func_80464CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80464CD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80464CD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80464CDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80464CE0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80464CE4: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
    // 0x80464CE8: jal         0x800653D8
    // 0x80464CEC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80464CEC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x80464CF0: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x80464CF4: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80464CF8: mfhi        $t8
    ctx->r24 = hi;
    // 0x80464CFC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80464D00: nop

    // 0x80464D04: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80464D08: jal         0x800653D8
    // 0x80464D0C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x80464D0C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80464D10: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80464D14: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80464D18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80464D1C: lwc1        $f6, 0xC8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC8);
    // 0x80464D20: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80464D24: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80464D28: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80464D2C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80464D30: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80464D34: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x80464D38: addiu       $v1, $v1, 0x1254
    ctx->r3 = ADD32(ctx->r3, 0X1254);
    // 0x80464D3C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80464D40: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80464D44: nop

    // 0x80464D48: div         $zero, $v0, $t1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r9)));
    // 0x80464D4C: bne         $t1, $zero, L_80464D58
    if (ctx->r9 != 0) {
        // 0x80464D50: nop
    
            goto L_80464D58;
    }
    // 0x80464D50: nop

    // 0x80464D54: break       7
    do_break(2152090964);
L_80464D58:
    // 0x80464D58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80464D5C: bne         $t1, $at, L_80464D70
    if (ctx->r9 != ctx->r1) {
        // 0x80464D60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80464D70;
    }
    // 0x80464D60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80464D64: bne         $v0, $at, L_80464D70
    if (ctx->r2 != ctx->r1) {
        // 0x80464D68: nop
    
            goto L_80464D70;
    }
    // 0x80464D68: nop

    // 0x80464D6C: break       6
    do_break(2152090988);
L_80464D70:
    // 0x80464D70: mfhi        $t2
    ctx->r10 = hi;
    // 0x80464D74: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80464D78: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80464D7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80464D80: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80464D84: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80464D88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80464D8C: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80464D90: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80464D94: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x80464D98: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80464D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80464DA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80464DA4: jr          $ra
    // 0x80464DA8: nop

    return;
    // 0x80464DA8: nop

;}
RECOMP_FUNC void func_805692A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805692A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805692A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805692AC: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x805692B0: lui         $t8, 0x8057
    ctx->r24 = S32(RELOC_HI16(378, 0X1FCC) << 16);
    // 0x805692B4: addiu       $t8, $t8, -0x6A84
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(378, 0X1FCC));
    // 0x805692B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805692BC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805692C0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805692C4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x805692C8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805692CC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805692D0: beql        $v1, $zero, L_80569304
    if (ctx->r3 == 0) {
        // 0x805692D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80569304;
    }
    goto skip_0;
    // 0x805692D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805692D8: jalr        $v1
    // 0x805692DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805692DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805692E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805692E4: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x805692E8: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x805692EC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x805692F0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x805692F4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x805692F8: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x805692FC: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x80569300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80569304:
    // 0x80569304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80569308: jr          $ra
    // 0x8056930C: nop

    return;
    // 0x8056930C: nop

;}
RECOMP_FUNC void func_8004894C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004894C: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80048950: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x80048954: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80048958: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8004895C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80048960: jr          $ra
    // 0x80048964: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    return;
    // 0x80048964: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
;}
RECOMP_FUNC void func_80475990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475990: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475994: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475998: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047599C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804759A0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804759A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804759A8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804759AC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804759B0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804759B4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804759B8: jr          $ra
    // 0x804759BC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804759BC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806B25EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B25EC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B25F0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B25F4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B25F8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B25FC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2600: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2604: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2608: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B260C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2610: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2614: jr          $ra
    // 0x806B2618: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2618: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8041F770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041F770: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8041F774: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x8041F778: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8041F77C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041F780: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8041F784: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8041F788: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8041F78C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8041F790: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8041F794: lwc1        $f2, 0x88($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8041F798: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8041F79C: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8041F7A0: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8041F7A4: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8041F7A8: nop

    // 0x8041F7AC: bc1fl       L_8041F7CC
    if (!c1cs) {
        // 0x8041F7B0: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8041F7CC;
    }
    goto skip_0;
    // 0x8041F7B0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    skip_0:
    // 0x8041F7B4: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8041F7B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041F7BC: lwc1        $f2, 0x88($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8041F7C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8041F7C4: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x8041F7C8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
L_8041F7CC:
    // 0x8041F7CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041F7D0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8041F7D4: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8041F7D8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8041F7DC: nop

    // 0x8041F7E0: bc1f        L_8041F7FC
    if (!c1cs) {
        // 0x8041F7E4: nop
    
            goto L_8041F7FC;
    }
    // 0x8041F7E4: nop

    // 0x8041F7E8: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8041F7EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041F7F0: nop

    // 0x8041F7F4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8041F7F8: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
L_8041F7FC:
    // 0x8041F7FC: jr          $ra
    // 0x8041F800: nop

    return;
    // 0x8041F800: nop

;}
RECOMP_FUNC void func_8001CC20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CC20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001CC24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001CC28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001CC2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CC30: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001CC34: lui         $a1, 0x4011
    ctx->r5 = S32(0X4011 << 16);
    // 0x8001CC38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001CC3C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001CC40: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8001CC44: addiu       $a0, $a0, 0x1540
    ctx->r4 = ADD32(ctx->r4, 0X1540);
    // 0x8001CC48: jal         0x80046804
    // 0x8001CC4C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x8001CC4C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8001CC50: beq         $v0, $zero, L_8001CD10
    if (ctx->r2 == 0) {
        // 0x8001CC54: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8001CD10;
    }
    // 0x8001CC54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8001CC58: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x8001CC5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001CC60: bnel        $t6, $zero, L_8001CC9C
    if (ctx->r14 != 0) {
        // 0x8001CC64: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8001CC9C;
    }
    goto skip_0;
    // 0x8001CC64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x8001CC68: jal         0x8001CBDC
    // 0x8001CC6C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8001CBDC(rdram, ctx);
        goto after_1;
    // 0x8001CC6C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001CC70: bne         $v0, $zero, L_8001CC80
    if (ctx->r2 != 0) {
        // 0x8001CC74: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_8001CC80;
    }
    // 0x8001CC74: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CC78: b           L_8001CD14
    // 0x8001CC7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001CD14;
    // 0x8001CC7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001CC80:
    // 0x8001CC80: lw          $t9, 0x16C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X16C);
    // 0x8001CC84: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8001CC88: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8001CC8C: sw          $t7, 0x124($a1)
    MEM_W(0X124, ctx->r5) = ctx->r15;
    // 0x8001CC90: addiu       $t8, $t8, -0x69B0
    ctx->r24 = ADD32(ctx->r24, -0X69B0);
    // 0x8001CC94: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8001CC98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_8001CC9C:
    // 0x8001CC9C: lw          $t0, 0x16C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X16C);
    // 0x8001CCA0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001CCA4: addiu       $t1, $t0, 0xD
    ctx->r9 = ADD32(ctx->r8, 0XD);
    // 0x8001CCA8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8001CCAC: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x8001CCB0: sw          $v1, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r3;
    // 0x8001CCB4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001CCB8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8001CCBC: jal         0x80047F9C
    // 0x8001CCC0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8001CCC0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x8001CCC4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001CCC8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8001CCCC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CCD0: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8001CCD4: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8001CCD8: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x8001CCDC: sw          $a1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r5;
    // 0x8001CCE0: sb          $zero, 0x28($t4)
    MEM_B(0X28, ctx->r12) = 0;
    // 0x8001CCE4: lw          $t5, 0x20($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X20);
    // 0x8001CCE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001CCEC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001CCF0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001CCF4: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x8001CCF8: sb          $t7, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r15;
    // 0x8001CCFC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8001CD00: sb          $t8, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r24;
    // 0x8001CD04: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001CD08: lw          $t1, 0x1F4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X1F4);
    // 0x8001CD0C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_8001CD10:
    // 0x8001CD10: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8001CD14:
    // 0x8001CD14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CD18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001CD1C: jr          $ra
    // 0x8001CD20: nop

    return;
    // 0x8001CD20: nop

;}
RECOMP_FUNC void func_8057EF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057EF98: jr          $ra
    // 0x8057EF9C: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    return;
    // 0x8057EF9C: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
;}
RECOMP_FUNC void func_805DA32C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA32C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DA330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA334: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805DA338: jal         0x80047090
    // 0x805DA33C: addiu       $a0, $zero, 0x4719
    ctx->r4 = ADD32(0, 0X4719);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805DA33C: addiu       $a0, $zero, 0x4719
    ctx->r4 = ADD32(0, 0X4719);
    after_0:
    // 0x805DA340: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805DA344: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x805DA348: beq         $v0, $at, L_805DA3A0
    if (ctx->r2 == ctx->r1) {
        // 0x805DA34C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805DA3A0;
    }
    // 0x805DA34C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805DA350: lui         $at, 0x4719
    ctx->r1 = S32(0X4719 << 16);
    // 0x805DA354: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x805DA358: lw          $t6, 0x1F4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X1F4);
    // 0x805DA35C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x805DA360: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DA364: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x805DA368: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805DA36C: lwc1        $f4, 0x84($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X84);
    // 0x805DA370: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x805DA374: lw          $a3, 0x8C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8C);
    // 0x805DA378: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805DA37C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805DA380: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x805DA384: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x805DA388: jal         0x8004613C
    // 0x805DA38C: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805DA38C: nop

    after_1:
    // 0x805DA390: beq         $v0, $zero, L_805DA3A0
    if (ctx->r2 == 0) {
        // 0x805DA394: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805DA3A0;
    }
    // 0x805DA394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805DA398: jal         0x80044194
    // 0x805DA39C: nop

    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805DA39C: nop

    after_2:
L_805DA3A0:
    // 0x805DA3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DA3A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DA3A8: jr          $ra
    // 0x805DA3AC: nop

    return;
    // 0x805DA3AC: nop

;}
RECOMP_FUNC void func_8076DFB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076DFB0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8076DFB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8076DFB8: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8076DFBC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8076DFC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8076DFC4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8076DFC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8076DFCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8076DFD0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8076DFD4: bc1f        L_8076DFF4
    if (!c1cs) {
        // 0x8076DFD8: addiu       $a2, $a0, 0x10
        ctx->r6 = ADD32(ctx->r4, 0X10);
            goto L_8076DFF4;
    }
    // 0x8076DFD8: addiu       $a2, $a0, 0x10
    ctx->r6 = ADD32(ctx->r4, 0X10);
    // 0x8076DFDC: lui         $a0, 0x8077
    ctx->r4 = S32(RELOC_HI16(766, 0X3AB0) << 16);
    // 0x8076DFE0: addiu       $a0, $a0, 0x2A0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(766, 0X3AB0));
    // 0x8076DFE4: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8076DFE8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8076DFEC: b           L_8076E008
    // 0x8076DFF0: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
        goto L_8076E008;
    // 0x8076DFF0: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_8076DFF4:
    // 0x8076DFF4: lui         $a0, 0x8077
    ctx->r4 = S32(RELOC_HI16(766, 0X3AB0) << 16);
    // 0x8076DFF8: addiu       $a0, $a0, 0x2A0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(766, 0X3AB0));
    // 0x8076DFFC: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x8076E000: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8076E004: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
L_8076E008:
    // 0x8076E008: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8076E00C: lui         $a1, 0x8077
    ctx->r5 = S32(RELOC_HI16(766, 0X3AB0) << 16);
    // 0x8076E010: lui         $t3, 0x8077
    ctx->r11 = S32(RELOC_HI16(766, 0X3ABC) << 16);
    // 0x8076E014: lui         $t1, 0x8077
    ctx->r9 = S32(RELOC_HI16(766, 0X3AA0) << 16);
    // 0x8076E018: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8076E01C: addiu       $t1, $t1, 0x290
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(766, 0X3AA0));
    // 0x8076E020: addiu       $t3, $t3, 0x2AC
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(766, 0X3ABC));
    // 0x8076E024: addiu       $a1, $a1, 0x2A0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(766, 0X3AB0));
    // 0x8076E028: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x8076E02C: addiu       $t0, $sp, 0x10
    ctx->r8 = ADD32(ctx->r29, 0X10);
    // 0x8076E030: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8076E034: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8076E038: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8076E03C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8076E040: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8076E044: lw          $t7, 0xC($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XC);
    // 0x8076E048: lw          $t8, 0x8($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X8);
    // 0x8076E04C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8076E050: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
    // 0x8076E054: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x8076E058: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8076E05C: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x8076E060: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x8076E064: beq         $a1, $t3, L_8076E11C
    if (ctx->r5 == ctx->r11) {
        // 0x8076E068: lw          $t4, 0x8($t0)
        ctx->r12 = MEM_W(ctx->r8, 0X8);
            goto L_8076E11C;
    }
    // 0x8076E068: lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X8);
L_8076E06C:
    // 0x8076E06C: sw          $t4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r12;
    // 0x8076E070: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x8076E074: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8076E078: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8076E07C: sw          $t9, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r25;
    // 0x8076E080: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8076E084: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x8076E088: sw          $t6, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->r14;
    // 0x8076E08C: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8076E090: sw          $t5, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->r13;
    // 0x8076E094: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x8076E098: sw          $t6, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r14;
    // 0x8076E09C: lw          $t5, 0xC($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XC);
    // 0x8076E0A0: sw          $t5, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r13;
    // 0x8076E0A4: lwc1        $f18, -0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, -0X8);
    // 0x8076E0A8: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8076E0AC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8076E0B0: nop

    // 0x8076E0B4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8076E0B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8076E0BC: sh          $a0, -0x20($a2)
    MEM_H(-0X20, ctx->r6) = ctx->r4;
    // 0x8076E0C0: sh          $a0, -0x20($v1)
    MEM_H(-0X20, ctx->r3) = ctx->r4;
    // 0x8076E0C4: sh          $v0, -0x18($a2)
    MEM_H(-0X18, ctx->r6) = ctx->r2;
    // 0x8076E0C8: lh          $t8, -0x18($a2)
    ctx->r24 = MEM_H(ctx->r6, -0X18);
    // 0x8076E0CC: sh          $a3, -0x1E($a2)
    MEM_H(-0X1E, ctx->r6) = ctx->r7;
    // 0x8076E0D0: sh          $t2, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = ctx->r10;
    // 0x8076E0D4: sh          $t8, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r24;
    // 0x8076E0D8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8076E0DC: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8076E0E0: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x8076E0E4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8076E0E8: lw          $t8, 0x8($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X8);
    // 0x8076E0EC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8076E0F0: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8076E0F4: lw          $t7, 0xC($t1)
    ctx->r15 = MEM_W(ctx->r9, 0XC);
    // 0x8076E0F8: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x8076E0FC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8076E100: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
    // 0x8076E104: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8076E108: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x8076E10C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8076E110: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x8076E114: bne         $a1, $t3, L_8076E06C
    if (ctx->r5 != ctx->r11) {
        // 0x8076E118: lw          $t4, 0x8($t0)
        ctx->r12 = MEM_W(ctx->r8, 0X8);
            goto L_8076E06C;
    }
    // 0x8076E118: lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X8);
L_8076E11C:
    // 0x8076E11C: sw          $t4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r12;
    // 0x8076E120: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x8076E124: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8076E128: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x8076E12C: sw          $t9, -0x14($a2)
    MEM_W(-0X14, ctx->r6) = ctx->r25;
    // 0x8076E130: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8076E134: sw          $t6, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = ctx->r14;
    // 0x8076E138: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x8076E13C: sw          $t5, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->r13;
    // 0x8076E140: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x8076E144: sw          $t6, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r14;
    // 0x8076E148: lw          $t5, 0xC($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XC);
    // 0x8076E14C: sw          $t5, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r13;
    // 0x8076E150: lwc1        $f18, -0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8076E154: trunc.w.s   $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8076E158: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8076E15C: nop

    // 0x8076E160: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8076E164: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8076E168: sh          $a0, -0x20($a2)
    MEM_H(-0X20, ctx->r6) = ctx->r4;
    // 0x8076E16C: sh          $a0, -0x20($v1)
    MEM_H(-0X20, ctx->r3) = ctx->r4;
    // 0x8076E170: sh          $v0, -0x18($a2)
    MEM_H(-0X18, ctx->r6) = ctx->r2;
    // 0x8076E174: lh          $t8, -0x18($a2)
    ctx->r24 = MEM_H(ctx->r6, -0X18);
    // 0x8076E178: sh          $a3, -0x1E($a2)
    MEM_H(-0X1E, ctx->r6) = ctx->r7;
    // 0x8076E17C: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // 0x8076E180: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8076E184: sh          $t2, -0x16($v1)
    MEM_H(-0X16, ctx->r3) = ctx->r10;
    // 0x8076E188: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8076E18C: sh          $t8, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r24;
    // 0x8076E190: jr          $ra
    // 0x8076E194: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8076E194: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80671E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671E80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80671E84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80671E88: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80671E8C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80671E90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80671E94: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80671E98: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80671E9C: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x80671EA0: jal         0x80671D4C
    // 0x80671EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x80671EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80671EA8: lw          $t6, 0x1E0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1E0);
    // 0x80671EAC: addiu       $a1, $s0, 0x30
    ctx->r5 = ADD32(ctx->r16, 0X30);
    // 0x80671EB0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80671EB4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80671EB8: blez        $t7, L_80671EE8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80671EBC: sw          $t7, 0x1E0($s2)
        MEM_W(0X1E0, ctx->r18) = ctx->r15;
            goto L_80671EE8;
    }
    // 0x80671EBC: sw          $t7, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = ctx->r15;
    // 0x80671EC0: sw          $zero, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = 0;
    // 0x80671EC4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80671EC8: jal         0x80671954
    // 0x80671ECC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80671954(rdram, ctx);
        goto after_1;
    // 0x80671ECC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_1:
    // 0x80671ED0: beq         $v0, $zero, L_80671EDC
    if (ctx->r2 == 0) {
        // 0x80671ED4: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_80671EDC;
    }
    // 0x80671ED4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80671ED8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_80671EDC:
    // 0x80671EDC: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80671EE0: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x80671EE4: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
L_80671EE8:
    // 0x80671EE8: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80671EEC: beq         $at, $zero, L_80671F00
    if (ctx->r1 == 0) {
        // 0x80671EF0: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80671F00;
    }
    // 0x80671EF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80671EF4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80671EF8: jal         0x80671C98
    // 0x80671EFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_80671C98(rdram, ctx);
        goto after_2;
    // 0x80671EFC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
L_80671F00:
    // 0x80671F00: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80671F04: bne         $at, $zero, L_80671F20
    if (ctx->r1 != 0) {
        // 0x80671F08: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80671F20;
    }
    // 0x80671F08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80671F0C: jal         0x80672C80
    // 0x80671F10: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80672C80(rdram, ctx);
        goto after_3;
    // 0x80671F10: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80671F14: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    // 0x80671F18: jal         0x80067818
    // 0x80671F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80671F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80671F20:
    // 0x80671F20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80671F24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80671F28: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80671F2C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80671F30: jr          $ra
    // 0x80671F34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80671F34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80427FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80427FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80427FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80427FC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80427FC8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80427FCC: jal         0x804288A0
    // 0x80427FD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804288A0(rdram, ctx);
        goto after_0;
    // 0x80427FD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80427FD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80427FD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80427FDC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80427FE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80427FE4: swc1        $f18, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f18.u32l;
    // 0x80427FE8: jal         0x80427BEC
    // 0x80427FEC: swc1        $f16, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f16.u32l;
    func_80427BEC(rdram, ctx);
        goto after_1;
    // 0x80427FEC: swc1        $f16, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f16.u32l;
    after_1:
    // 0x80427FF0: jal         0x80427D4C
    // 0x80427FF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80427D4C(rdram, ctx);
        goto after_2;
    // 0x80427FF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80427FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80427FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80428000: jr          $ra
    // 0x80428004: nop

    return;
    // 0x80428004: nop

;}
RECOMP_FUNC void func_804205D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804205D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804205DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804205E0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804205E4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804205E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804205EC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804205F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804205F4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804205F8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804205FC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80420600: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(29, 0X34BC) << 16);
    // 0x80420604: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80420608: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8042060C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80420610: lw          $t2, 0xB1C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(29, 0X34BC));
    // 0x80420614: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80420618: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8042061C: jal         0x8041FFDC
    // 0x80420620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8041FFDC(rdram, ctx);
        goto after_0;
    // 0x80420620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80420624: jal         0x80420038
    // 0x80420628: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80420038(rdram, ctx);
        goto after_1;
    // 0x80420628: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8042062C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80420630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80420634: jr          $ra
    // 0x80420638: nop

    return;
    // 0x80420638: nop

    // 0x8042063C: nop

;}
RECOMP_FUNC void func_805D8804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D8804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D8808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D880C: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805D8810: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805D8814: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805D8818: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x805D881C: nop

    // 0x805D8820: bc1tl       L_805D8860
    if (c1cs) {
        // 0x805D8824: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D8860;
    }
    goto skip_0;
    // 0x805D8824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805D8828: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x805D882C: bnel        $t6, $zero, L_805D8860
    if (ctx->r14 != 0) {
        // 0x805D8830: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D8860;
    }
    goto skip_1;
    // 0x805D8830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805D8834: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805D8838: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x805D883C: jal         0x80067BBC
    // 0x805D8840: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805D8840: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x805D8844: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x805D8848: jal         0x80011D1C
    // 0x805D884C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80011D1C(rdram, ctx);
        goto after_1;
    // 0x805D884C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805D8850: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805D8854: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x805D8858: sw          $t7, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r15;
    // 0x805D885C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D8860:
    // 0x805D8860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D8864: jr          $ra
    // 0x805D8868: nop

    return;
    // 0x805D8868: nop

;}
RECOMP_FUNC void func_80032CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80032CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032CA8: jal         0x80032C5C
    // 0x80032CAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80032C5C(rdram, ctx);
        goto after_0;
    // 0x80032CAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80032CB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80032CB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80032CB8: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x80032CBC: bnel        $t6, $at, L_80032D10
    if (ctx->r14 != ctx->r1) {
        // 0x80032CC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032D10;
    }
    goto skip_0;
    // 0x80032CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80032CC4: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x80032CC8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80032CCC: bnel        $t7, $at, L_80032D10
    if (ctx->r15 != ctx->r1) {
        // 0x80032CD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032D10;
    }
    goto skip_1;
    // 0x80032CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80032CD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80032CD8: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80032CDC: lui         $t1, 0x8002
    ctx->r9 = S32(0X8002 << 16);
    // 0x80032CE0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80032CE4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80032CE8: addiu       $t1, $t1, 0x4748
    ctx->r9 = ADD32(ctx->r9, 0X4748);
    // 0x80032CEC: bc1fl       L_80032D10
    if (!c1cs) {
        // 0x80032CF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032D10;
    }
    goto skip_2;
    // 0x80032CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80032CF4: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x80032CF8: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80032CFC: sb          $t0, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r8;
    // 0x80032D00: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80032D04: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x80032D08: sw          $t1, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r9;
    // 0x80032D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80032D10:
    // 0x80032D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032D14: jr          $ra
    // 0x80032D18: nop

    return;
    // 0x80032D18: nop

;}
RECOMP_FUNC void func_8040EFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EFF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040EFFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040F000: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040F004: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8040F008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040F00C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8040F010: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8040F014: jal         0x80045A34
    // 0x8040F018: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8040F018: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x8040F01C: bne         $v0, $zero, L_8040F034
    if (ctx->r2 != 0) {
        // 0x8040F020: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8040F034;
    }
    // 0x8040F020: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8040F024: jal         0x800445A4
    // 0x8040F028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8040F028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8040F02C: b           L_8040F0A8
    // 0x8040F030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8040F0A8;
    // 0x8040F030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040F034:
    // 0x8040F034: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040F038: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8040F03C: jal         0x800657CC
    // 0x8040F040: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_2;
    // 0x8040F040: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8040F044: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8040F048: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(23, 0XC64) << 16);
    // 0x8040F04C: addiu       $t7, $t7, -0xBFC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(23, 0XC64));
    // 0x8040F050: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8040F054: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040F058: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8040F05C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040F060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040F064: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x8040F068: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040F06C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8040F070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040F074: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8040F078: swc1        $f6, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f6.u32l;
    // 0x8040F07C: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040F080: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8040F084: jal         0x8040F0B8
    // 0x8040F088: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    func_8040F0B8(rdram, ctx);
        goto after_3;
    // 0x8040F088: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    after_3:
    // 0x8040F08C: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x8040F090: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x8040F094: sw          $t2, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r10;
    // 0x8040F098: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8040F09C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8040F0A0: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
    // 0x8040F0A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040F0A8:
    // 0x8040F0A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040F0AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040F0B0: jr          $ra
    // 0x8040F0B4: nop

    return;
    // 0x8040F0B4: nop

;}
RECOMP_FUNC void func_8043F8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F8C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043F8C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F8CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F8D0: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x8043F8D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F8D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8043F8DC: jal         0x80442188
    // 0x8043F8E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80442188(rdram, ctx);
        goto after_0;
    // 0x8043F8E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043F8E4: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EA4) << 16);
    // 0x8043F8E8: lwc1        $f0, 0x3DA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EA4));
    // 0x8043F8EC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8043F8F0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EA8) << 16);
    // 0x8043F8F4: swc1        $f0, 0x1C24($v0)
    MEM_W(0X1C24, ctx->r2) = ctx->f0.u32l;
    // 0x8043F8F8: swc1        $f0, 0x1C28($v0)
    MEM_W(0X1C28, ctx->r2) = ctx->f0.u32l;
    // 0x8043F8FC: lwc1        $f4, 0x3DA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EA8));
    // 0x8043F900: swc1        $f4, 0x1C2C($v0)
    MEM_W(0X1C2C, ctx->r2) = ctx->f4.u32l;
    // 0x8043F904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043F908: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043F90C: jr          $ra
    // 0x8043F910: nop

    return;
    // 0x8043F910: nop

;}
RECOMP_FUNC void func_8040E89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E89C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040E8A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E8A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8040E8A8: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8040E8AC: jal         0x80067BBC
    // 0x8040E8B0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8040E8B0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8040E8B4: addiu       $a0, $zero, 0x287
    ctx->r4 = ADD32(0, 0X287);
    // 0x8040E8B8: jal         0x80067818
    // 0x8040E8BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8040E8BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8040E8C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040E8C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040E8C8: jr          $ra
    // 0x8040E8CC: nop

    return;
    // 0x8040E8CC: nop

;}
RECOMP_FUNC void func_80036478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003647C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036480: jal         0x80021958
    // 0x80036484: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80036484: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80036488: bne         $v0, $zero, L_80036498
    if (ctx->r2 != 0) {
        // 0x8003648C: nop
    
            goto L_80036498;
    }
    // 0x8003648C: nop

    // 0x80036490: b           L_800364CC
    // 0x80036494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800364CC;
    // 0x80036494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036498:
    // 0x80036498: jal         0x800415FC
    // 0x8003649C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x8003649C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800364A0: beq         $v0, $zero, L_800364B0
    if (ctx->r2 == 0) {
        // 0x800364A4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800364B0;
    }
    // 0x800364A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800364A8: b           L_800364CC
    // 0x800364AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800364CC;
    // 0x800364AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800364B0:
    // 0x800364B0: jal         0x800351BC
    // 0x800364B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800351BC(rdram, ctx);
        goto after_2;
    // 0x800364B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x800364B8: bnel        $v0, $zero, L_800364CC
    if (ctx->r2 != 0) {
        // 0x800364BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800364CC;
    }
    goto skip_0;
    // 0x800364BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800364C0: b           L_800364CC
    // 0x800364C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800364CC;
    // 0x800364C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800364C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800364CC:
    // 0x800364CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800364D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800364D4: jr          $ra
    // 0x800364D8: nop

    return;
    // 0x800364D8: nop

;}
RECOMP_FUNC void func_80024C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024C1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80024C20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024C24: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80024C28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80024C2C: jal         0x8002491C
    // 0x80024C30: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8002491C(rdram, ctx);
        goto after_0;
    // 0x80024C30: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80024C34: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80024C38: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80024C3C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80024C40: lw          $v0, 0x14C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X14C);
    // 0x80024C44: bnel        $v0, $at, L_80024C80
    if (ctx->r2 != ctx->r1) {
        // 0x80024C48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80024C80;
    }
    goto skip_0;
    // 0x80024C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80024C4C: beql        $t7, $v0, L_80024C80
    if (ctx->r15 == ctx->r2) {
        // 0x80024C50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80024C80;
    }
    goto skip_1;
    // 0x80024C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80024C54: jal         0x8001D770
    // 0x80024C58: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80024C58: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80024C5C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80024C60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80024C64: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80024C68: jal         0x80067BF8
    // 0x80024C6C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x80024C6C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80024C70: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80024C74: jal         0x80067818
    // 0x80024C78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80024C78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80024C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80024C80:
    // 0x80024C80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80024C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80024C88: jr          $ra
    // 0x80024C8C: nop

    return;
    // 0x80024C8C: nop

;}
