#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8005ACD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005ACD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005ACD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005ACDC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8005ACE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005ACE4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8005ACE8: beq         $v0, $at, L_8005AD20
    if (ctx->r2 == ctx->r1) {
        // 0x8005ACEC: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8005AD20;
    }
    // 0x8005ACEC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8005ACF0: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8005ACF4: lw          $t9, 0x6150($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6150);
    // 0x8005ACF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005ACFC: jalr        $t9
    // 0x8005AD00: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005AD00: nop

    after_0:
    // 0x8005AD04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005AD08: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8005AD0C: jal         0x80065728
    // 0x8005AD10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x8005AD10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8005AD14: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8005AD18: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8005AD1C: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_8005AD20:
    // 0x8005AD20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005AD24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005AD28: jr          $ra
    // 0x8005AD2C: nop

    return;
    // 0x8005AD2C: nop

;}
RECOMP_FUNC void func_80040D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040D78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040D80: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    // 0x80040D84: jal         0x80066E88
    // 0x80040D88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80040D88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80040D8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80040D90: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80040D94: lwc1        $f6, 0x100($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X100);
    // 0x80040D98: lwc1        $f16, 0x10C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x80040D9C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80040DA0: nop

    // 0x80040DA4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80040DA8: jal         0x80065954
    // 0x80040DAC: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80040DAC: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_1:
    // 0x80040DB0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80040DB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80040DB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80040DBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80040DC0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80040DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040DC8: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x80040DCC: bc1f        L_80040DDC
    if (!c1cs) {
        // 0x80040DD0: nop
    
            goto L_80040DDC;
    }
    // 0x80040DD0: nop

    // 0x80040DD4: b           L_80040E1C
    // 0x80040DD8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80040E1C;
    // 0x80040DD8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80040DDC:
    // 0x80040DDC: lwc1        $f4, 0x2E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2E4);
    // 0x80040DE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80040DE4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80040DE8: nop

    // 0x80040DEC: bc1f        L_80040DFC
    if (!c1cs) {
        // 0x80040DF0: nop
    
            goto L_80040DFC;
    }
    // 0x80040DF0: nop

    // 0x80040DF4: b           L_80040E1C
    // 0x80040DF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80040E1C;
    // 0x80040DF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80040DFC:
    // 0x80040DFC: beq         $v1, $at, L_80040E14
    if (ctx->r3 == ctx->r1) {
        // 0x80040E00: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80040E14;
    }
    // 0x80040E00: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80040E04: beq         $v1, $at, L_80040E14
    if (ctx->r3 == ctx->r1) {
        // 0x80040E08: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80040E14;
    }
    // 0x80040E08: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80040E0C: bne         $v1, $at, L_80040E1C
    if (ctx->r3 != ctx->r1) {
        // 0x80040E10: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80040E1C;
    }
    // 0x80040E10: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80040E14:
    // 0x80040E14: b           L_80040E1C
    // 0x80040E18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80040E1C;
    // 0x80040E18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80040E1C:
    // 0x80040E1C: jr          $ra
    // 0x80040E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80040E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804667D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804667D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804667D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804667D8: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x804667DC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804667E0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804667E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804667E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804667EC: jal         0x8046687C
    // 0x804667F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8046687C(rdram, ctx);
        goto after_0;
    // 0x804667F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x804667F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804667F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804667FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80466800: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80466804: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x80466808: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8046680C: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(129, 0X10) << 16);
    // 0x80466810: addiu       $t7, $t7, 0x6610
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(129, 0X10));
    // 0x80466814: sw          $t7, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r15;
    // 0x80466818: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x8046681C: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(129, 0X2C8) << 16);
    // 0x80466820: addiu       $t9, $t9, 0x68C8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(129, 0X2C8));
    // 0x80466824: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80466828: jal         0x80045A34
    // 0x8046682C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8046682C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    after_1:
    // 0x80466830: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80466834: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80466838: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8046683C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80466840: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80466844: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80466848: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8046684C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80466850: sh          $t1, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r9;
    // 0x80466854: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(129, 0X2D4) << 16);
    // 0x80466858: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8046685C: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80466860: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80466864: lwc1        $f10, 0x68D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(129, 0X2D4));
    // 0x80466868: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8046686C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80466870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80466874: jr          $ra
    // 0x80466878: nop

    return;
    // 0x80466878: nop

;}
RECOMP_FUNC void func_804544F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804544F8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804544FC: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x80454500: addiu       $a1, $zero, 0x1B6C
    ctx->r5 = ADD32(0, 0X1B6C);
    // 0x80454504: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x80454508: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8045450C: sw          $v1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r3;
    // 0x80454510: sw          $a1, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r5;
    // 0x80454514: sw          $v1, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r3;
    // 0x80454518: sw          $a1, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->r5;
    // 0x8045451C: jr          $ra
    // 0x80454520: sw          $t6, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->r14;
    return;
    // 0x80454520: sw          $t6, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_804424DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804424DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804424E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804424E4: jal         0x8004700C
    // 0x804424E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804424E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804424EC: bne         $v0, $zero, L_804424FC
    if (ctx->r2 != 0) {
        // 0x804424F0: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_804424FC;
    }
    // 0x804424F0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x804424F4: b           L_80442574
    // 0x804424F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80442574;
    // 0x804424F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804424FC:
    // 0x804424FC: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80442500: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80442504: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x80442508: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8044250C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80442510: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80442514: lwc1        $f10, 0x88($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80442518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8044251C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80442520: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80442524: bc1f        L_80442574
    if (!c1cs) {
        // 0x80442528: nop
    
            goto L_80442574;
    }
    // 0x80442528: nop

    // 0x8044252C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80442530: nop

    // 0x80442534: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80442538: nop

    // 0x8044253C: bc1f        L_80442574
    if (!c1cs) {
        // 0x80442540: nop
    
            goto L_80442574;
    }
    // 0x80442540: nop

    // 0x80442544: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80442548: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8044254C: bc1f        L_80442574
    if (!c1cs) {
        // 0x80442550: nop
    
            goto L_80442574;
    }
    // 0x80442550: nop

    // 0x80442554: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80442558: nop

    // 0x8044255C: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80442560: nop

    // 0x80442564: bc1f        L_80442574
    if (!c1cs) {
        // 0x80442568: nop
    
            goto L_80442574;
    }
    // 0x80442568: nop

    // 0x8044256C: b           L_80442574
    // 0x80442570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80442574;
    // 0x80442570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80442574:
    // 0x80442574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80442578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044257C: jr          $ra
    // 0x80442580: nop

    return;
    // 0x80442580: nop

;}
RECOMP_FUNC void func_80050258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005025C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050260: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80050264: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80050268: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8005026C: lbu         $v1, 0x68($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X68);
    // 0x80050270: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80050274: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80050278: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8005027C: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80050280: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80050284: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80050288: bne         $at, $zero, L_800502A8
    if (ctx->r1 != 0) {
        // 0x8005028C: sra         $a3, $a3, 16
        ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
            goto L_800502A8;
    }
    // 0x8005028C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80050290: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80050294: addiu       $a0, $a0, 0x954
    ctx->r4 = ADD32(ctx->r4, 0X954);
    // 0x80050298: jal         0x80071380
    // 0x8005029C: addiu       $a1, $zero, 0x4C4
    ctx->r5 = ADD32(0, 0X4C4);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8005029C: addiu       $a1, $zero, 0x4C4
    ctx->r5 = ADD32(0, 0X4C4);
    after_0:
    // 0x800502A0: b           L_800502DC
    // 0x800502A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800502DC;
    // 0x800502A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800502A8:
    // 0x800502A8: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x800502AC: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800502B0: sh          $a1, 0x6C($v0)
    MEM_H(0X6C, ctx->r2) = ctx->r5;
    // 0x800502B4: sh          $a2, 0x6E($v0)
    MEM_H(0X6E, ctx->r2) = ctx->r6;
    // 0x800502B8: sh          $a3, 0x74($v0)
    MEM_H(0X74, ctx->r2) = ctx->r7;
    // 0x800502BC: lh          $t7, 0x2A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2A);
    // 0x800502C0: sh          $t7, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r15;
    // 0x800502C4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800502C8: sw          $t8, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r24;
    // 0x800502CC: lbu         $t9, 0x68($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X68);
    // 0x800502D0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800502D4: sb          $t0, 0x68($a0)
    MEM_B(0X68, ctx->r4) = ctx->r8;
    // 0x800502D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800502DC:
    // 0x800502DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800502E0: jr          $ra
    // 0x800502E4: nop

    return;
    // 0x800502E4: nop

;}
RECOMP_FUNC void func_8044493C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044493C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80444940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80444944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80444948: jal         0x80047090
    // 0x8044494C: addiu       $a0, $zero, 0x4505
    ctx->r4 = ADD32(0, 0X4505);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8044494C: addiu       $a0, $zero, 0x4505
    ctx->r4 = ADD32(0, 0X4505);
    after_0:
    // 0x80444950: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80444954: beq         $v0, $at, L_80444988
    if (ctx->r2 == ctx->r1) {
        // 0x80444958: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80444988;
    }
    // 0x80444958: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8044495C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80444960: lui         $at, 0x4505
    ctx->r1 = S32(0X4505 << 16);
    // 0x80444964: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80444968: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8044496C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80444970: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80444974: jal         0x8004613C
    // 0x80444978: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80444978: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x8044497C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80444980: jal         0x80047F9C
    // 0x80444984: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80444984: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_80444988:
    // 0x80444988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044498C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80444990: jr          $ra
    // 0x80444994: nop

    return;
    // 0x80444994: nop

;}
RECOMP_FUNC void func_80407BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80407BF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80407BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80407BFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80407C00: jal         0x80045A34
    // 0x80407C04: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80407C04: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_0:
    // 0x80407C08: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80407C0C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x80407C10: bne         $v0, $zero, L_80407C20
    if (ctx->r2 != 0) {
        // 0x80407C14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80407C20;
    }
    // 0x80407C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80407C18: b           L_80407C24
    // 0x80407C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80407C24;
    // 0x80407C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80407C20:
    // 0x80407C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80407C24:
    // 0x80407C24: jr          $ra
    // 0x80407C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80407C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005E884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E884: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8005E888: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005E88C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8005E890: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8005E894: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8005E898: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8005E89C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8005E8A0: lw          $s1, 0x16C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X16C);
    // 0x8005E8A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005E8A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005E8AC: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x8005E8B0: bnel        $v0, $at, L_8005E8C4
    if (ctx->r2 != ctx->r1) {
        // 0x8005E8B4: lbu         $t6, 0x165($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X165);
            goto L_8005E8C4;
    }
    goto skip_0;
    // 0x8005E8B4: lbu         $t6, 0x165($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X165);
    skip_0:
    // 0x8005E8B8: b           L_8005EA2C
    // 0x8005E8BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005EA2C;
    // 0x8005E8BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005E8C0: lbu         $t6, 0x165($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X165);
L_8005E8C4:
    // 0x8005E8C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E8C8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8005E8CC: beq         $t6, $at, L_8005EA28
    if (ctx->r14 == ctx->r1) {
        // 0x8005E8D0: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8005EA28;
    }
    // 0x8005E8D0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8005E8D4: lw          $t7, -0x76D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76D0);
    // 0x8005E8D8: lw          $t9, 0x34($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X34);
    // 0x8005E8DC: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8005E8E0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8005E8E4: lwc1        $f20, 0x9C($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X9C);
    // 0x8005E8E8: lwc1        $f22, 0xA0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x8005E8EC: addu        $s2, $t7, $t8
    ctx->r18 = ADD32(ctx->r15, ctx->r24);
    // 0x8005E8F0: sw          $t9, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r25;
    // 0x8005E8F4: lw          $t0, 0x38($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X38);
    // 0x8005E8F8: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x8005E8FC: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x8005E900: jal         0x80058CC0
    // 0x8005E904: sw          $t0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r8;
    func_80058CC0(rdram, ctx);
        goto after_0;
    // 0x8005E904: sw          $t0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r8;
    after_0:
    // 0x8005E908: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8005E90C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8005E910: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x8005E914: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005E918: lw          $a2, 0xA4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA4);
    // 0x8005E91C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8005E920: jal         0x80066468
    // 0x8005E924: nop

    func_80066468(rdram, ctx);
        goto after_1;
    // 0x8005E924: nop

    after_1:
    // 0x8005E928: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8005E92C: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x8005E930: addiu       $t6, $s0, 0x48
    ctx->r14 = ADD32(ctx->r16, 0X48);
    // 0x8005E934: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8005E938: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005E93C: addiu       $t7, $s0, 0x54
    ctx->r15 = ADD32(ctx->r16, 0X54);
    // 0x8005E940: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8005E944: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8005E948: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8005E94C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005E950: andi        $a2, $v0, 0x2
    ctx->r6 = ctx->r2 & 0X2;
    // 0x8005E954: srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
    // 0x8005E958: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8005E95C: addiu       $a3, $s0, 0x90
    ctx->r7 = ADD32(ctx->r16, 0X90);
    // 0x8005E960: jal         0x8005DF6C
    // 0x8005E964: andi        $a1, $v0, 0x1
    ctx->r5 = ctx->r2 & 0X1;
    func_8005DF6C(rdram, ctx);
        goto after_2;
    // 0x8005E964: andi        $a1, $v0, 0x1
    ctx->r5 = ctx->r2 & 0X1;
    after_2:
    // 0x8005E968: lw          $t8, 0x20($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X20);
    // 0x8005E96C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8005E970: addiu       $t9, $t9, 0x6438
    ctx->r25 = ADD32(ctx->r25, 0X6438);
    // 0x8005E974: beql        $t8, $zero, L_8005E9DC
    if (ctx->r24 == 0) {
        // 0x8005E978: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8005E9DC;
    }
    goto skip_1;
    // 0x8005E978: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x8005E97C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8005E980: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8005E984: addiu       $a1, $s0, 0x13C
    ctx->r5 = ADD32(ctx->r16, 0X13C);
    // 0x8005E988: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8005E98C: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8005E990: addiu       $a2, $s1, 0x18
    ctx->r6 = ADD32(ctx->r17, 0X18);
    // 0x8005E994: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x8005E998: swc1        $f20, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f20.u32l;
    // 0x8005E99C: swc1        $f22, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f22.u32l;
    // 0x8005E9A0: lw          $t9, 0x20($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X20);
    // 0x8005E9A4: jalr        $t9
    // 0x8005E9A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8005E9A8: nop

    after_3:
    // 0x8005E9AC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8005E9B0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8005E9B4: jal         0x80080798
    // 0x8005E9B8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    func_80080798(rdram, ctx);
        goto after_4;
    // 0x8005E9B8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    after_4:
    // 0x8005E9BC: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8005E9C0: lwc1        $f10, 0x1C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005E9C4: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x8005E9C8: mul.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x8005E9CC: nop

    // 0x8005E9D0: mul.s       $f22, $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x8005E9D4: nop

    // 0x8005E9D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8005E9DC:
    // 0x8005E9DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E9E0: nop

    // 0x8005E9E4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x8005E9E8: nop

    // 0x8005E9EC: bc1fl       L_8005EA08
    if (!c1cs) {
        // 0x8005E9F0: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_8005EA08;
    }
    goto skip_2;
    // 0x8005E9F0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_2:
    // 0x8005E9F4: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x8005E9F8: nop

    // 0x8005E9FC: bc1tl       L_8005EA18
    if (c1cs) {
        // 0x8005EA00: lw          $a0, 0x18($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X18);
            goto L_8005EA18;
    }
    goto skip_3;
    // 0x8005EA00: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    skip_3:
    // 0x8005EA04: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_8005EA08:
    // 0x8005EA08: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8005EA0C: jal         0x80080440
    // 0x8005EA10: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_80080440(rdram, ctx);
        goto after_5;
    // 0x8005EA10: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x8005EA14: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
L_8005EA18:
    // 0x8005EA18: jal         0x800817A0
    // 0x8005EA1C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    MtxConv_F2L(rdram, ctx);
        goto after_6;
    // 0x8005EA1C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_6:
    // 0x8005EA20: b           L_8005EA2C
    // 0x8005EA24: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_8005EA2C;
    // 0x8005EA24: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8005EA28:
    // 0x8005EA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005EA2C:
    // 0x8005EA2C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005EA30: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8005EA34: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8005EA38: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8005EA3C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8005EA40: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8005EA44: jr          $ra
    // 0x8005EA48: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8005EA48: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_804423F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804423F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804423F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804423FC: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x80442400: jal         0x80049D74
    // 0x80442404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x80442404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80442408: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8044240C: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x80442410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80442414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80442418: jal         0x8004D150
    // 0x8044241C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x8044241C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_1:
    // 0x80442420: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80442424: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x80442428: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8044242C: jal         0x8004D618
    // 0x80442430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004D618(rdram, ctx);
        goto after_2;
    // 0x80442430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80442434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80442438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044243C: jr          $ra
    // 0x80442440: nop

    return;
    // 0x80442440: nop

;}
RECOMP_FUNC void func_80068B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068B2C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80068B30: lw          $v1, 0x6EC0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6EC0);
    // 0x80068B34: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80068B38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068B3C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80068B40: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80068B44: lw          $t9, 0x6EC4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6EC4);
    // 0x80068B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068B4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80068B50: jalr        $t9
    // 0x80068B54: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80068B54: nop

    after_0:
    // 0x80068B58: bne         $v0, $zero, L_80068B68
    if (ctx->r2 != 0) {
        // 0x80068B5C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80068B68;
    }
    // 0x80068B5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80068B60: b           L_80068BB0
    // 0x80068B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80068BB0;
    // 0x80068B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80068B68:
    // 0x80068B68: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80068B6C: lw          $v1, 0x6EC0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6EC0);
    // 0x80068B70: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80068B74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80068B78: sw          $v1, 0x6EC0($at)
    MEM_W(0X6EC0, ctx->r1) = ctx->r3;
    // 0x80068B7C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80068B80: beql        $at, $zero, L_80068B94
    if (ctx->r1 == 0) {
        // 0x80068B84: lw          $t9, 0xD4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XD4);
            goto L_80068B94;
    }
    goto skip_0;
    // 0x80068B84: lw          $t9, 0xD4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XD4);
    skip_0:
    // 0x80068B88: b           L_80068BB0
    // 0x80068B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80068BB0;
    // 0x80068B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80068B90: lw          $t9, 0xD4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XD4);
L_80068B94:
    // 0x80068B94: jalr        $t9
    // 0x80068B98: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80068B98: nop

    after_1:
    // 0x80068B9C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80068BA0: sb          $zero, 0x7EA3($at)
    MEM_B(0X7EA3, ctx->r1) = 0;
    // 0x80068BA4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80068BA8: sw          $zero, 0x6EC0($at)
    MEM_W(0X6EC0, ctx->r1) = 0;
    // 0x80068BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80068BB0:
    // 0x80068BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068BB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068BB8: jr          $ra
    // 0x80068BBC: nop

    return;
    // 0x80068BBC: nop

;}
RECOMP_FUNC void func_805AB178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB178: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805AB17C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805AB180: lwc1        $f0, 0x278($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X278);
    // 0x805AB184: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x805AB188: div.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x805AB18C: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x805AB190: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x805AB194: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x805AB198: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x805AB19C: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x805AB1A0: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x805AB1A4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805AB1A8: jr          $ra
    // 0x805AB1AC: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x805AB1AC: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_8064A6AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A6AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A6B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A6B4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064A6B8: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064A6BC: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8064A6C0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064A6C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064A6C8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8064A6CC: nop

    // 0x8064A6D0: bc1fl       L_8064A700
    if (!c1cs) {
        // 0x8064A6D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064A700;
    }
    goto skip_0;
    // 0x8064A6D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064A6D8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064A6DC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064A6E0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064A6E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064A6E8: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x8064A6EC: jal         0x8064A97C
    // 0x8064A6F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8064A97C(rdram, ctx);
        goto after_0;
    // 0x8064A6F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064A6F4: jal         0x8064A40C
    // 0x8064A6F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8064A40C(rdram, ctx);
        goto after_1;
    // 0x8064A6F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8064A6FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064A700:
    // 0x8064A700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A704: jr          $ra
    // 0x8064A708: nop

    return;
    // 0x8064A708: nop

;}
RECOMP_FUNC void func_8046136C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046136C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80461370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80461374: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80461378: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x8046137C: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x80461380: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80461384: lb          $t8, 0x2($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X2);
    // 0x80461388: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8046138C: nop

    // 0x80461390: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80461394: jal         0x8046118C
    // 0x80461398: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_8046118C(rdram, ctx);
        goto after_0;
    // 0x80461398: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8046139C: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804613A0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x804613A4: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
    // 0x804613A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804613AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804613B0: jr          $ra
    // 0x804613B4: nop

    return;
    // 0x804613B4: nop

;}
RECOMP_FUNC void func_806815B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806815B8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806815BC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806815C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806815C4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806815C8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806815CC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806815D0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806815D4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806815D8: lui         $t1, 0x8068
    ctx->r9 = S32(RELOC_HI16(550, 0X21F0) << 16);
    // 0x806815DC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806815E0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806815E4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806815E8: lw          $t1, 0x2600($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(550, 0X21F0));
    // 0x806815EC: jr          $ra
    // 0x806815F0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806815F0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80031AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031AE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80031AE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031AEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80031AF0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031AF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80031AF8: jal         0x80042148
    // 0x80031AFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80042148(rdram, ctx);
        goto after_0;
    // 0x80031AFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031B00: beq         $v0, $zero, L_80031B24
    if (ctx->r2 == 0) {
        // 0x80031B04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80031B24;
    }
    // 0x80031B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031B08: jal         0x800310A0
    // 0x80031B0C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800310A0(rdram, ctx);
        goto after_1;
    // 0x80031B0C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80031B10: jal         0x80021A44
    // 0x80031B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021A44(rdram, ctx);
        goto after_2;
    // 0x80031B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80031B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031B1C: jal         0x800310D0
    // 0x80031B20: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800310D0(rdram, ctx);
        goto after_3;
    // 0x80031B20: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
L_80031B24:
    // 0x80031B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80031B28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80031B2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80031B30: jr          $ra
    // 0x80031B34: nop

    return;
    // 0x80031B34: nop

;}
RECOMP_FUNC void func_8078ABA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078ABA0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8078ABA4: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(793, 0X394) << 16);
    // 0x8078ABA8: addiu       $t6, $t6, -0x5A2C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(793, 0X394));
    // 0x8078ABAC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8078ABB0: jr          $ra
    // 0x8078ABB4: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x8078ABB4: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80714914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80714914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80714918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8071491C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80714920: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80714924: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80714928: beql        $a1, $at, L_80714960
    if (ctx->r5 == ctx->r1) {
        // 0x8071492C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80714960;
    }
    goto skip_0;
    // 0x8071492C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80714930: jal         0x80067930
    // 0x80714934: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80714934: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_0:
    // 0x80714938: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8071493C: bne         $v0, $at, L_80714950
    if (ctx->r2 != ctx->r1) {
        // 0x80714940: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80714950;
    }
    // 0x80714940: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80714944: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80714948: jal         0x80067878
    // 0x8071494C: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x8071494C: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    after_1:
L_80714950:
    // 0x80714950: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80714954: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80714958: sh          $t8, 0x1F0($t9)
    MEM_H(0X1F0, ctx->r25) = ctx->r24;
    // 0x8071495C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80714960:
    // 0x80714960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80714964: jr          $ra
    // 0x80714968: nop

    return;
    // 0x80714968: nop

;}
RECOMP_FUNC void func_80445B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445B78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80445B7C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80445B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445B84: jal         0x80067AF4
    // 0x80445B88: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_80067AF4(rdram, ctx);
        goto after_0;
    // 0x80445B88: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x80445B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445B90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445B94: jr          $ra
    // 0x80445B98: nop

    return;
    // 0x80445B98: nop

;}
RECOMP_FUNC void func_804F5928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F5928: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804F592C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F5930: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F5934: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804F5938: jal         0x804F4F50
    // 0x804F593C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804F4F50(rdram, ctx);
        goto after_0;
    // 0x804F593C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804F5940: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804F5944: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804F5948: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x804F594C: beq         $t6, $zero, L_804F599C
    if (ctx->r14 == 0) {
        // 0x804F5950: nop
    
            goto L_804F599C;
    }
    // 0x804F5950: nop

    // 0x804F5954: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x804F5958: addiu       $v1, $t7, 0x1
    ctx->r3 = ADD32(ctx->r15, 0X1);
    // 0x804F595C: slti        $at, $v1, 0x32
    ctx->r1 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // 0x804F5960: bne         $at, $zero, L_804F5980
    if (ctx->r1 != 0) {
        // 0x804F5964: sw          $v1, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r3;
            goto L_804F5980;
    }
    // 0x804F5964: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x804F5968: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x804F596C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x804F5970: blez        $v1, L_804F59A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x804F5974: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_804F59A4;
    }
    // 0x804F5974: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x804F5978: b           L_804F59A4
    // 0x804F597C: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
        goto L_804F59A4;
    // 0x804F597C: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_804F5980:
    // 0x804F5980: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x804F5984: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x804F5988: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x804F598C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x804F5990: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x804F5994: b           L_804F59A4
    // 0x804F5998: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_804F59A4;
    // 0x804F5998: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_804F599C:
    // 0x804F599C: jal         0x804F59B4
    // 0x804F59A0: nop

    func_804F59B4(rdram, ctx);
        goto after_1;
    // 0x804F59A0: nop

    after_1:
L_804F59A4:
    // 0x804F59A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F59A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804F59AC: jr          $ra
    // 0x804F59B0: nop

    return;
    // 0x804F59B0: nop

;}
RECOMP_FUNC void func_8003C9C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C9C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003C9CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C9D0: jal         0x8003C8F0
    // 0x8003C9D4: nop

    func_8003C8F0(rdram, ctx);
        goto after_0;
    // 0x8003C9D4: nop

    after_0:
    // 0x8003C9D8: beq         $v0, $zero, L_8003CA48
    if (ctx->r2 == 0) {
        // 0x8003C9DC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003CA48;
    }
    // 0x8003C9DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003C9E0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8003C9E4: jal         0x80045A34
    // 0x8003C9E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8003C9E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003C9EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C9F0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003C9F4: bne         $v0, $zero, L_8003CA0C
    if (ctx->r2 != 0) {
        // 0x8003C9F8: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8003CA0C;
    }
    // 0x8003C9F8: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8003C9FC: jal         0x800445A4
    // 0x8003CA00: nop

    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x8003CA00: nop

    after_2:
    // 0x8003CA04: b           L_8003CA4C
    // 0x8003CA08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003CA4C;
    // 0x8003CA08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003CA0C:
    // 0x8003CA0C: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003CA10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003CA14: addiu       $t6, $t6, -0x368C
    ctx->r14 = ADD32(ctx->r14, -0X368C);
    // 0x8003CA18: sb          $v0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r2;
    // 0x8003CA1C: sw          $t6, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->r14;
    // 0x8003CA20: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8003CA24: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x8003CA28: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8003CA2C: addiu       $t8, $t8, -0x1340
    ctx->r24 = ADD32(ctx->r24, -0X1340);
    // 0x8003CA30: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8003CA34: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003CA38: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8003CA3C: addiu       $t1, $t1, -0x3650
    ctx->r9 = ADD32(ctx->r9, -0X3650);
    // 0x8003CA40: sb          $v0, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r2;
    // 0x8003CA44: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
L_8003CA48:
    // 0x8003CA48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8003CA4C:
    // 0x8003CA4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003CA50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003CA54: jr          $ra
    // 0x8003CA58: nop

    return;
    // 0x8003CA58: nop

;}
RECOMP_FUNC void func_807BB2BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB2BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BB2C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BB2C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807BB2C8: jal         0x807BA848
    // 0x807BB2CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807BA848(rdram, ctx);
        goto after_0;
    // 0x807BB2CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807BB2D0: jal         0x807BAC0C
    // 0x807BB2D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAC0C(rdram, ctx);
        goto after_1;
    // 0x807BB2D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807BB2D8: jal         0x807BAF34
    // 0x807BB2DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAF34(rdram, ctx);
        goto after_2;
    // 0x807BB2DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807BB2E0: jal         0x807BAB94
    // 0x807BB2E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAB94(rdram, ctx);
        goto after_3;
    // 0x807BB2E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807BB2E8: jal         0x807BAA20
    // 0x807BB2EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAA20(rdram, ctx);
        goto after_4;
    // 0x807BB2EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807BB2F0: beql        $v0, $zero, L_807BB334
    if (ctx->r2 == 0) {
        // 0x807BB2F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807BB334;
    }
    goto skip_0;
    // 0x807BB2F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807BB2F8: lw          $t6, 0x12C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X12C);
    // 0x807BB2FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BB300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BB304: bne         $t6, $zero, L_807BB328
    if (ctx->r14 != 0) {
        // 0x807BB308: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_807BB328;
    }
    // 0x807BB308: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x807BB30C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BB310: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BB314: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x807BB318: jal         0x807BB7A4
    // 0x807BB31C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_807BB7A4(rdram, ctx);
        goto after_5;
    // 0x807BB31C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x807BB320: b           L_807BB334
    // 0x807BB324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807BB334;
    // 0x807BB324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807BB328:
    // 0x807BB328: jal         0x807BB7A4
    // 0x807BB32C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807BB7A4(rdram, ctx);
        goto after_6;
    // 0x807BB32C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x807BB330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807BB334:
    // 0x807BB334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807BB338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807BB33C: jr          $ra
    // 0x807BB340: nop

    return;
    // 0x807BB340: nop

;}
RECOMP_FUNC void func_807ACCFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ACCFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807ACD00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ACD04: jal         0x807ACCB8
    // 0x807ACD08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807ACCB8(rdram, ctx);
        goto after_0;
    // 0x807ACD08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807ACD0C: bne         $v0, $zero, L_807ACD24
    if (ctx->r2 != 0) {
        // 0x807ACD10: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807ACD24;
    }
    // 0x807ACD10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807ACD14: jal         0x800447C8
    // 0x807ACD18: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x807ACD18: nop

    after_1:
    // 0x807ACD1C: b           L_807ACD68
    // 0x807ACD20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807ACD68;
    // 0x807ACD20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807ACD24:
    // 0x807ACD24: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807ACD28: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(859, 0X4D0) << 16);
    // 0x807ACD2C: addiu       $t6, $t6, -0x34D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(859, 0X4D0));
    // 0x807ACD30: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x807ACD34: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x807ACD38: lui         $t8, 0x807B
    ctx->r24 = S32(RELOC_HI16(859, 0X25E0) << 16);
    // 0x807ACD3C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807ACD40: addiu       $t8, $t8, -0x13C0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(859, 0X25E0));
    // 0x807ACD44: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x807ACD48: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807ACD4C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807ACD50: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807ACD54: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807ACD58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807ACD5C: jal         0x807ACD74
    // 0x807ACD60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807ACD74(rdram, ctx);
        goto after_2;
    // 0x807ACD60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x807ACD64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807ACD68:
    // 0x807ACD68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807ACD6C: jr          $ra
    // 0x807ACD70: nop

    return;
    // 0x807ACD70: nop

;}
RECOMP_FUNC void func_80074C64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80074C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80074C6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80074C70: jal         0x800748B0
    // 0x80074C74: sb          $t6, 0x45E($a0)
    MEM_B(0X45E, ctx->r4) = ctx->r14;
    func_800748B0(rdram, ctx);
        goto after_0;
    // 0x80074C74: sb          $t6, 0x45E($a0)
    MEM_B(0X45E, ctx->r4) = ctx->r14;
    after_0:
    // 0x80074C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80074C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80074C80: jr          $ra
    // 0x80074C84: nop

    return;
    // 0x80074C84: nop

;}
RECOMP_FUNC void func_807604DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807604DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807604E0: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(763, 0XC348) << 16);
    // 0x807604E4: lwc1        $f0, -0x3C28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(763, 0XC348));
    // 0x807604E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807604EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807604F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x807604F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807604F8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x807604FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80760500: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x80760504: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80760508: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8076050C: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x80760510: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80760514: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80760518: jal         0x8076009C
    // 0x8076051C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8076009C(rdram, ctx);
        goto after_0;
    // 0x8076051C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80760520: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80760524: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(763, 0XC34C) << 16);
    // 0x80760528: addiu       $t7, $zero, 0xAC8
    ctx->r15 = ADD32(0, 0XAC8);
    // 0x8076052C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80760530: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80760534: lwc1        $f4, -0x3C24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(763, 0XC34C));
    // 0x80760538: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(763, 0XC350) << 16);
    // 0x8076053C: lwc1        $f6, -0x3C20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(763, 0XC350));
    // 0x80760540: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80760544: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80760548: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8076054C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80760550: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x80760554: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80760558: jal         0x8076009C
    // 0x8076055C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_8076009C(rdram, ctx);
        goto after_1;
    // 0x8076055C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80760560: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80760564: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x80760568: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8076056C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80760570: jr          $ra
    // 0x80760574: nop

    return;
    // 0x80760574: nop

;}
RECOMP_FUNC void func_80031A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031A0C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80031A10: bne         $v0, $zero, L_80031A40
    if (ctx->r2 != 0) {
        // 0x80031A14: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80031A40;
    }
    // 0x80031A14: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80031A18: jal         0x80028220
    // 0x80031A1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80028220(rdram, ctx);
        goto after_0;
    // 0x80031A1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80031A20: beq         $v0, $zero, L_80031A44
    if (ctx->r2 == 0) {
        // 0x80031A24: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80031A44;
    }
    // 0x80031A24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80031A28: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x80031A2C: addiu       $t6, $t6, 0x1A54
    ctx->r14 = ADD32(ctx->r14, 0X1A54);
    // 0x80031A30: addiu       $t7, $zero, 0x60
    ctx->r15 = ADD32(0, 0X60);
    // 0x80031A34: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x80031A38: b           L_80031A44
    // 0x80031A3C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
        goto L_80031A44;
    // 0x80031A3C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
L_80031A40:
    // 0x80031A40: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
L_80031A44:
    // 0x80031A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031A48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031A4C: jr          $ra
    // 0x80031A50: nop

    return;
    // 0x80031A50: nop

;}
RECOMP_FUNC void func_8070C8FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070C8FC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8070C900: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8070C904: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8070C908: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8070C90C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8070C910: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8070C914: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8070C918: lui         $t1, 0x8071
    ctx->r9 = S32(RELOC_HI16(721, 0XBE4) << 16);
    // 0x8070C91C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8070C920: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8070C924: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8070C928: lw          $t1, -0x2D8C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(721, 0XBE4));
    // 0x8070C92C: jr          $ra
    // 0x8070C930: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8070C930: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8040F760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040F760: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040F764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040F768: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8040F76C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8040F770: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8040F774: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8040F778: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x8040F77C: jal         0x804103C0
    // 0x8040F780: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_804103C0(rdram, ctx);
        goto after_0;
    // 0x8040F780: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_0:
    // 0x8040F784: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8040F788: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8040F78C: jal         0x80410AF4
    // 0x8040F790: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    func_80410AF4(rdram, ctx);
        goto after_1;
    // 0x8040F790: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x8040F794: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8040F798: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x8040F79C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8040F7A0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8040F7A4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8040F7A8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8040F7AC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8040F7B0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8040F7B4: sw          $t3, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r11;
    // 0x8040F7B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040F7BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040F7C0: jr          $ra
    // 0x8040F7C4: nop

    return;
    // 0x8040F7C4: nop

;}
RECOMP_FUNC void func_80428750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428750: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80428754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80428758: jal         0x80427DC8
    // 0x8042875C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80427DC8(rdram, ctx);
        goto after_0;
    // 0x8042875C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80428760: bne         $v0, $zero, L_804287B4
    if (ctx->r2 != 0) {
        // 0x80428764: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804287B4;
    }
    // 0x80428764: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80428768: jal         0x8004700C
    // 0x8042876C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x8042876C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80428770: bne         $v0, $zero, L_80428788
    if (ctx->r2 != 0) {
        // 0x80428774: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80428788;
    }
    // 0x80428774: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80428778: jal         0x80428698
    // 0x8042877C: nop

    func_80428698(rdram, ctx);
        goto after_2;
    // 0x8042877C: nop

    after_2:
    // 0x80428780: b           L_804287C0
    // 0x80428784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804287C0;
    // 0x80428784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80428788:
    // 0x80428788: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8042878C: bne         $a0, $t6, L_804287A4
    if (ctx->r4 != ctx->r14) {
        // 0x80428790: nop
    
            goto L_804287A4;
    }
    // 0x80428790: nop

    // 0x80428794: jal         0x80428008
    // 0x80428798: nop

    func_80428008(rdram, ctx);
        goto after_3;
    // 0x80428798: nop

    after_3:
    // 0x8042879C: b           L_804287C0
    // 0x804287A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804287C0;
    // 0x804287A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804287A4:
    // 0x804287A4: jal         0x80428698
    // 0x804287A8: nop

    func_80428698(rdram, ctx);
        goto after_4;
    // 0x804287A8: nop

    after_4:
    // 0x804287AC: b           L_804287C0
    // 0x804287B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804287C0;
    // 0x804287B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804287B4:
    // 0x804287B4: jal         0x80427F5C
    // 0x804287B8: nop

    func_80427F5C(rdram, ctx);
        goto after_5;
    // 0x804287B8: nop

    after_5:
    // 0x804287BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804287C0:
    // 0x804287C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804287C4: jr          $ra
    // 0x804287C8: nop

    return;
    // 0x804287C8: nop

;}
RECOMP_FUNC void func_8064B0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B0BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B0C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B0C4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064B0C8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8064B0CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B0D0: blez        $v0, L_8064B0E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064B0D4: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_8064B0E4;
    }
    // 0x8064B0D4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8064B0D8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064B0DC: b           L_8064B0F4
    // 0x8064B0E0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064B0F4;
    // 0x8064B0E0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064B0E4:
    // 0x8064B0E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064B0E8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064B0EC: jal         0x8064B3E0
    // 0x8064B0F0: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    func_8064B3E0(rdram, ctx);
        goto after_0;
    // 0x8064B0F0: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    after_0:
L_8064B0F4:
    // 0x8064B0F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064B0F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B0FC: jr          $ra
    // 0x8064B100: nop

    return;
    // 0x8064B100: nop

;}
RECOMP_FUNC void func_80062564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062564: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80062568: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006256C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062570: lhu         $t6, 0xE($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XE);
    // 0x80062574: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80062578: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8006257C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80062580: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80062584: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80062588: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8006258C: addiu       $t0, $t9, 0x50
    ctx->r8 = ADD32(ctx->r25, 0X50);
    // 0x80062590: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80062594: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    // 0x80062598: jal         0x8005BCB8
    // 0x8006259C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_8005BCB8(rdram, ctx);
        goto after_0;
    // 0x8006259C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x800625A0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800625A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800625A8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x800625AC: sw          $v0, 0x60($t1)
    MEM_W(0X60, ctx->r9) = ctx->r2;
    // 0x800625B0: jal         0x800655F4
    // 0x800625B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800655F4(rdram, ctx);
        goto after_1;
    // 0x800625B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800625B8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800625BC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800625C0: lwc1        $f4, 0x98($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X98);
    // 0x800625C4: swc1        $f4, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f4.u32l;
    // 0x800625C8: lhu         $v0, 0xE($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0XE);
    // 0x800625CC: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x800625D0: andi        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 & 0X10;
    // 0x800625D4: beq         $t3, $zero, L_80062640
    if (ctx->r11 == 0) {
        // 0x800625D8: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_80062640;
    }
    // 0x800625D8: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x800625DC: sltiu       $at, $t4, 0xB
    ctx->r1 = ctx->r12 < 0XB ? 1 : 0;
    // 0x800625E0: beq         $at, $zero, L_80062634
    if (ctx->r1 == 0) {
        // 0x800625E4: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80062634;
    }
    // 0x800625E4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800625E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800625EC: addu        $at, $at, $t4
    gpr jr_addend_800625F4 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800625F0: lw          $t4, 0xD6C($at)
    ctx->r12 = ADD32(ctx->r1, 0XD6C);
    // 0x800625F4: jr          $t4
    // 0x800625F8: nop

    switch (jr_addend_800625F4 >> 2) {
        case 0: goto L_800625FC; break;
        case 1: goto L_800625FC; break;
        case 2: goto L_80062610; break;
        case 3: goto L_80062624; break;
        case 4: goto L_80062634; break;
        case 5: goto L_80062634; break;
        case 6: goto L_800625FC; break;
        case 7: goto L_800625FC; break;
        case 8: goto L_800625FC; break;
        case 9: goto L_800625FC; break;
        case 10: goto L_800625FC; break;
        default: switch_error(__func__, 0x800625F4, 0x800B0D6C);
    }
    // 0x800625F8: nop

L_800625FC:
    // 0x800625FC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80062600: lui         $t5, 0x8006
    ctx->r13 = S32(0X8006 << 16);
    // 0x80062604: addiu       $t5, $t5, 0x17DC
    ctx->r13 = ADD32(ctx->r13, 0X17DC);
    // 0x80062608: b           L_80062634
    // 0x8006260C: sw          $t5, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r13;
        goto L_80062634;
    // 0x8006260C: sw          $t5, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r13;
L_80062610:
    // 0x80062610: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80062614: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80062618: addiu       $t7, $t7, 0x1C78
    ctx->r15 = ADD32(ctx->r15, 0X1C78);
    // 0x8006261C: b           L_80062634
    // 0x80062620: sw          $t7, 0x64($t8)
    MEM_W(0X64, ctx->r24) = ctx->r15;
        goto L_80062634;
    // 0x80062620: sw          $t7, 0x64($t8)
    MEM_W(0X64, ctx->r24) = ctx->r15;
L_80062624:
    // 0x80062624: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80062628: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x8006262C: addiu       $t9, $t9, 0x1EFC
    ctx->r25 = ADD32(ctx->r25, 0X1EFC);
    // 0x80062630: sw          $t9, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->r25;
L_80062634:
    // 0x80062634: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80062638: b           L_8006265C
    // 0x8006263C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
        goto L_8006265C;
    // 0x8006263C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_80062640:
    // 0x80062640: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80062644: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80062648: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8006264C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062650: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80062654: lw          $t1, 0x6508($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6508);
    // 0x80062658: sw          $t1, 0x64($t2)
    MEM_W(0X64, ctx->r10) = ctx->r9;
L_8006265C:
    // 0x8006265C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80062660: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x80062664: lw          $t3, 0x6538($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6538);
    // 0x80062668: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006266C: sw          $t3, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->r11;
    // 0x80062670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062674: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062678: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006267C: jr          $ra
    // 0x80062680: nop

    return;
    // 0x80062680: nop

;}
RECOMP_FUNC void func_8051B6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051B6C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051B6CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051B6D0: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8051B6D4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8051B6D8: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(297, 0X400) << 16);
    // 0x8051B6DC: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8051B6E0: addiu       $t7, $t7, -0x48D0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(297, 0X400));
    // 0x8051B6E4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8051B6E8: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(297, 0X2C4) << 16);
    // 0x8051B6EC: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8051B6F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8051B6F4: addiu       $t9, $t9, -0x4A0C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(297, 0X2C4));
    // 0x8051B6F8: addiu       $t0, $t0, -0x71F4
    ctx->r8 = ADD32(ctx->r8, -0X71F4);
    // 0x8051B6FC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8051B700: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8051B704: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x8051B708: sb          $v0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r2;
    // 0x8051B70C: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x8051B710: jal         0x8051B404
    // 0x8051B714: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    func_8051B404(rdram, ctx);
        goto after_0;
    // 0x8051B714: sw          $t0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r8;
    after_0:
    // 0x8051B718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051B71C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8051B720: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8051B724: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x8051B728: jr          $ra
    // 0x8051B72C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8051B72C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005FBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FBC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FBC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FBC8: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8005FBCC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005FBD0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8005FBD4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005FBD8: lbu         $t7, 0x79($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X79);
    // 0x8005FBDC: beql        $t7, $zero, L_8005FC00
    if (ctx->r15 == 0) {
        // 0x8005FBE0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FC00;
    }
    goto skip_0;
    // 0x8005FBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005FBE4: jal         0x8005F9F4
    // 0x8005FBE8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8005F9F4(rdram, ctx);
        goto after_0;
    // 0x8005FBE8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005FBEC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8005FBF0: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x8005FBF4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8005FBF8: sb          $zero, 0x79($t9)
    MEM_B(0X79, ctx->r25) = 0;
    // 0x8005FBFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FC00:
    // 0x8005FC00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005FC04: jr          $ra
    // 0x8005FC08: nop

    return;
    // 0x8005FC08: nop

;}
RECOMP_FUNC void func_8004D56C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D56C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004D570: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8004D574: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8004D578: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004D57C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004D580: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004D584: addu        $a2, $t7, $v1
    ctx->r6 = ADD32(ctx->r15, ctx->r3);
    // 0x8004D588: lbu         $t8, 0x14($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X14);
    // 0x8004D58C: beq         $t8, $zero, L_8004D5C0
    if (ctx->r24 == 0) {
        // 0x8004D590: nop
    
            goto L_8004D5C0;
    }
    // 0x8004D590: nop

    // 0x8004D594: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x8004D598: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8004D59C: bne         $t0, $zero, L_8004D5C0
    if (ctx->r8 != 0) {
        // 0x8004D5A0: nop
    
            goto L_8004D5C0;
    }
    // 0x8004D5A0: nop

    // 0x8004D5A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004D5A8: nop

    // 0x8004D5AC: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8004D5B0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8004D5B4: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8004D5B8: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8004D5BC: sb          $zero, 0x14($t3)
    MEM_B(0X14, ctx->r11) = 0;
L_8004D5C0:
    // 0x8004D5C0: jr          $ra
    // 0x8004D5C4: nop

    return;
    // 0x8004D5C4: nop

;}
RECOMP_FUNC void func_80447808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447808: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044780C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447810: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80447814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447818: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044781C: bne         $a2, $zero, L_80447860
    if (ctx->r6 != 0) {
        // 0x80447820: lw          $v1, 0x1F4($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X1F4);
            goto L_80447860;
    }
    // 0x80447820: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x80447824: lw          $v0, 0xF8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XF8);
    // 0x80447828: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8044782C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80447830: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80447834: beq         $at, $zero, L_8044784C
    if (ctx->r1 == 0) {
        // 0x80447838: addiu       $v0, $v1, 0x8
        ctx->r2 = ADD32(ctx->r3, 0X8);
            goto L_8044784C;
    }
    // 0x80447838: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8044783C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80447840: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x80447844: b           L_804478AC
    // 0x80447848: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_804478AC;
    // 0x80447848: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8044784C:
    // 0x8044784C: jal         0x80446170
    // 0x80447850: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80446170(rdram, ctx);
        goto after_0;
    // 0x80447850: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80447854: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80447858: b           L_804478AC
    // 0x8044785C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
        goto L_804478AC;
    // 0x8044785C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_80447860:
    // 0x80447860: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447864: bne         $a2, $at, L_80447890
    if (ctx->r6 != ctx->r1) {
        // 0x80447868: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80447890;
    }
    // 0x80447868: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044786C: jal         0x8044610C
    // 0x80447870: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8044610C(rdram, ctx);
        goto after_1;
    // 0x80447870: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80447874: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80447878: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044787C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80447880: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80447884: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x80447888: b           L_804478AC
    // 0x8044788C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
        goto L_804478AC;
    // 0x8044788C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_80447890:
    // 0x80447890: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80447894: bne         $a2, $at, L_804478AC
    if (ctx->r6 != ctx->r1) {
        // 0x80447898: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_804478AC;
    }
    // 0x80447898: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044789C: jal         0x80446170
    // 0x804478A0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80446170(rdram, ctx);
        goto after_2;
    // 0x804478A0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x804478A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804478A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_804478AC:
    // 0x804478AC: jal         0x804475C0
    // 0x804478B0: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    func_804475C0(rdram, ctx);
        goto after_3;
    // 0x804478B0: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    after_3:
    // 0x804478B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804478B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804478BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804478C0: jr          $ra
    // 0x804478C4: nop

    return;
    // 0x804478C4: nop

;}
RECOMP_FUNC void func_80535C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80535C1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80535C20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80535C24: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80535C28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535C2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80535C30: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80535C34: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(351, 0X12F8) << 16);
    // 0x80535C38: lui         $a1, 0x8053
    ctx->r5 = S32(RELOC_HI16(351, 0X1310) << 16);
    // 0x80535C3C: addiu       $a1, $a1, 0x6BA0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(351, 0X1310));
    // 0x80535C40: addiu       $a2, $a2, 0x6B88
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(351, 0X12F8));
    // 0x80535C44: jal         0x80535958
    // 0x80535C48: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_80535958(rdram, ctx);
        goto after_0;
    // 0x80535C48: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x80535C4C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80535C50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535C54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535C58: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535C5C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80535C60: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80535C68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80535C6C: jr          $ra
    // 0x80535C70: nop

    return;
    // 0x80535C70: nop

;}
RECOMP_FUNC void func_805DCE84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCE84: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805DCE88: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x805DCE8C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x805DCE90: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x805DCE94: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x805DCE98: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x805DCE9C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x805DCEA0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x805DCEA4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x805DCEA8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x805DCEAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DCEB0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x805DCEB4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x805DCEB8: lw          $fp, 0x1F4($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DCEBC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x805DCEC0: andi        $s6, $a2, 0xFFFF
    ctx->r22 = ctx->r6 & 0XFFFF;
    // 0x805DCEC4: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x805DCEC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x805DCECC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x805DCED0: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x805DCED4: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
L_805DCED8:
    // 0x805DCED8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x805DCEDC: jal         0x805DB140
    // 0x805DCEE0: andi        $a1, $s6, 0xFFFF
    ctx->r5 = ctx->r22 & 0XFFFF;
    func_805DB140(rdram, ctx);
        goto after_0;
    // 0x805DCEE0: andi        $a1, $s6, 0xFFFF
    ctx->r5 = ctx->r22 & 0XFFFF;
    after_0:
    // 0x805DCEE4: beq         $v0, $zero, L_805DCF28
    if (ctx->r2 == 0) {
        // 0x805DCEE8: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_805DCF28;
    }
    // 0x805DCEE8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x805DCEEC: sll         $t6, $s1, 1
    ctx->r14 = S32(ctx->r17 << 1);
    // 0x805DCEF0: addu        $s2, $s7, $t6
    ctx->r18 = ADD32(ctx->r23, ctx->r14);
    // 0x805DCEF4: jal         0x805DCE24
    // 0x805DCEF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_805DCE24(rdram, ctx);
        goto after_1;
    // 0x805DCEF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x805DCEFC: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x805DCF00: beql        $a1, $zero, L_805DCF14
    if (ctx->r5 == 0) {
        // 0x805DCF04: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_805DCF14;
    }
    goto skip_0;
    // 0x805DCF04: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x805DCF08: jal         0x805DB22C
    // 0x805DCF0C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_805DB22C(rdram, ctx);
        goto after_2;
    // 0x805DCF0C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x805DCF10: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_805DCF14:
    // 0x805DCF14: sb          $s3, 0x165($t7)
    MEM_B(0X165, ctx->r15) = ctx->r19;
    // 0x805DCF18: jal         0x8005FE48
    // 0x805DCF1C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x805DCF1C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x805DCF20: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x805DCF24: sw          $zero, 0x130($t8)
    MEM_W(0X130, ctx->r24) = 0;
L_805DCF28:
    // 0x805DCF28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x805DCF2C: bne         $s1, $s4, L_805DCED8
    if (ctx->r17 != ctx->r20) {
        // 0x805DCF30: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_805DCED8;
    }
    // 0x805DCF30: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x805DCF34: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x805DCF38: swc1        $f4, 0x5C($fp)
    MEM_W(0X5C, ctx->r30) = ctx->f4.u32l;
    // 0x805DCF3C: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x805DCF40: swc1        $f6, 0x60($fp)
    MEM_W(0X60, ctx->r30) = ctx->f6.u32l;
    // 0x805DCF44: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x805DCF48: swc1        $f8, 0x64($fp)
    MEM_W(0X64, ctx->r30) = ctx->f8.u32l;
    // 0x805DCF4C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x805DCF50: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x805DCF54: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x805DCF58: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x805DCF5C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x805DCF60: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x805DCF64: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x805DCF68: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x805DCF6C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x805DCF70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DCF74: jr          $ra
    // 0x805DCF78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x805DCF78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8066B7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B7C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066B7C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066B7C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066B7CC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8066B7D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8066B7D4: jal         0x8066B570
    // 0x8066B7D8: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    func_8066B570(rdram, ctx);
        goto after_0;
    // 0x8066B7D8: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    after_0:
    // 0x8066B7DC: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8066B7E0: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(514, 0X2690) << 16);
    // 0x8066B7E4: addiu       $t7, $t7, -0x2D10
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(514, 0X2690));
    // 0x8066B7E8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8066B7EC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8066B7F0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8066B7F4: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8066B7F8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8066B7FC: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x8066B800: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8066B804: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8066B808: jal         0x80048378
    // 0x8066B80C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8066B80C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    after_1:
    // 0x8066B810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066B814: jal         0x80045A34
    // 0x8066B818: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x8066B818: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    after_2:
    // 0x8066B81C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8066B820: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x8066B824: jal         0x8066B608
    // 0x8066B828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B608(rdram, ctx);
        goto after_3;
    // 0x8066B828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8066B82C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8066B830: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066B834: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066B838: jr          $ra
    // 0x8066B83C: nop

    return;
    // 0x8066B83C: nop

;}
RECOMP_FUNC void func_807ADB40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ADB40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807ADB44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807ADB48: lw          $v0, 0xE8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XE8);
    // 0x807ADB4C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26DC) << 16);
    // 0x807ADB50: lwc1        $f12, -0x12C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26DC));
    // 0x807ADB54: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x807ADB58: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26E0) << 16);
    // 0x807ADB5C: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x807ADB60: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x807ADB64: nop

    // 0x807ADB68: bc1tl       L_807ADBC4
    if (c1cs) {
        // 0x807ADB6C: swc1        $f0, 0xAC($a0)
        MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
            goto L_807ADBC4;
    }
    goto skip_0;
    // 0x807ADB6C: swc1        $f0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x807ADB70: lwc1        $f14, -0x12C0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26E0));
    // 0x807ADB74: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x807ADB78: nop

    // 0x807ADB7C: bc1tl       L_807ADBC4
    if (c1cs) {
        // 0x807ADB80: swc1        $f0, 0xAC($a0)
        MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
            goto L_807ADBC4;
    }
    goto skip_1;
    // 0x807ADB80: swc1        $f0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x807ADB84: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x807ADB88: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x807ADB8C: nop

    // 0x807ADB90: bc1tl       L_807ADBC4
    if (c1cs) {
        // 0x807ADB94: swc1        $f0, 0xAC($a0)
        MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
            goto L_807ADBC4;
    }
    goto skip_2;
    // 0x807ADB94: swc1        $f0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
    skip_2:
    // 0x807ADB98: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x807ADB9C: nop

    // 0x807ADBA0: bc1tl       L_807ADBC4
    if (c1cs) {
        // 0x807ADBA4: swc1        $f0, 0xAC($a0)
        MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
            goto L_807ADBC4;
    }
    goto skip_3;
    // 0x807ADBA4: swc1        $f0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
    skip_3:
    // 0x807ADBA8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x807ADBAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807ADBB0: swc1        $f2, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f2.u32l;
    // 0x807ADBB4: swc1        $f2, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f2.u32l;
    // 0x807ADBB8: b           L_807ADC00
    // 0x807ADBBC: swc1        $f2, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f2.u32l;
        goto L_807ADC00;
    // 0x807ADBBC: swc1        $f2, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f2.u32l;
    // 0x807ADBC0: swc1        $f0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
L_807ADBC4:
    // 0x807ADBC4: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x807ADBC8: lwc1        $f8, 0xAC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x807ADBCC: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807ADBD0: swc1        $f4, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f4.u32l;
    // 0x807ADBD4: lwc1        $f18, 0xB0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XB0);
    // 0x807ADBD8: lwc1        $f16, 0x88($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807ADBDC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807ADBE0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x807ADBE4: addiu       $a1, $a0, 0x84
    ctx->r5 = ADD32(ctx->r4, 0X84);
    // 0x807ADBE8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x807ADBEC: swc1        $f10, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f10.u32l;
    // 0x807ADBF0: swc1        $f2, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f2.u32l;
    // 0x807ADBF4: jal         0x80065490
    // 0x807ADBF8: swc1        $f4, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f4.u32l;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x807ADBF8: swc1        $f4, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x807ADBFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807ADC00:
    // 0x807ADC00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807ADC04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807ADC08: jr          $ra
    // 0x807ADC0C: nop

    return;
    // 0x807ADC0C: nop

;}
RECOMP_FUNC void func_8053332C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053332C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80533330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80533334: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80533338: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8053333C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80533340: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80533344: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80533348: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8053334C: bc1fl       L_80533398
    if (!c1cs) {
        // 0x80533350: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80533398;
    }
    goto skip_0;
    // 0x80533350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80533354: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80533358: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8053335C: jal         0x80533878
    // 0x80533360: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80533878(rdram, ctx);
        goto after_0;
    // 0x80533360: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80533364: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80533368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8053336C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(345, 0X1920) << 16);
    // 0x80533370: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80533374: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80533378: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8053337C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80533380: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80533384: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80533388: lwc1        $f16, 0x43F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(345, 0X1920));
    // 0x8053338C: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x80533390: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x80533394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80533398:
    // 0x80533398: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8053339C: jr          $ra
    // 0x805333A0: nop

    return;
    // 0x805333A0: nop

;}
RECOMP_FUNC void func_8000C3CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C3CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000C3D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C3D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000C3D8: jal         0x8000DBD4
    // 0x8000C3DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8000DBD4(rdram, ctx);
        goto after_0;
    // 0x8000C3DC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000C3E0: beq         $v0, $zero, L_8000C404
    if (ctx->r2 == 0) {
        // 0x8000C3E4: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_8000C404;
    }
    // 0x8000C3E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000C3E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000C3EC: jal         0x8000C21C
    // 0x8000C3F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8000C21C(rdram, ctx);
        goto after_1;
    // 0x8000C3F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8000C3F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000C3F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C3FC: jal         0x8000C130
    // 0x8000C400: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_8000C130(rdram, ctx);
        goto after_2;
    // 0x8000C400: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_2:
L_8000C404:
    // 0x8000C404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C408: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C40C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C410: jr          $ra
    // 0x8000C414: nop

    return;
    // 0x8000C414: nop

;}
RECOMP_FUNC void func_800292D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800292D4: lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10);
    // 0x800292D8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800292DC: lw          $v1, 0x34($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X34);
    // 0x800292E0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800292E4: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x800292E8: lw          $t6, -0x2234($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2234);
    // 0x800292EC: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800292F0: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x800292F4: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800292F8: bne         $at, $zero, L_80029414
    if (ctx->r1 != 0) {
        // 0x800292FC: addu        $t1, $t1, $t0
        ctx->r9 = ADD32(ctx->r9, ctx->r8);
            goto L_80029414;
    }
    // 0x800292FC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80029300: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80029304: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80029308: lw          $t7, -0x221C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X221C);
    // 0x8002930C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80029310: beq         $at, $zero, L_80029360
    if (ctx->r1 == 0) {
        // 0x80029314: lui         $at, 0xC010
        ctx->r1 = S32(0XC010 << 16);
            goto L_80029360;
    }
    // 0x80029314: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x80029318: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002931C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029320: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x80029324: lwc1        $f4, -0x200($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X200);
    // 0x80029328: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8002932C: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x80029330: bnel        $t8, $zero, L_80029344
    if (ctx->r24 != 0) {
        // 0x80029334: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80029344;
    }
    goto skip_0;
    // 0x80029334: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80029338: jr          $ra
    // 0x8002933C: swc1        $f0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8002933C: swc1        $f0, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f0.u32l;
    // 0x80029340: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80029344:
    // 0x80029344: lwc1        $f6, 0xC0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC0);
    // 0x80029348: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8002934C: nop

    // 0x80029350: bc1f        L_8002956C
    if (!c1cs) {
        // 0x80029354: nop
    
            goto L_8002956C;
    }
    // 0x80029354: nop

    // 0x80029358: jr          $ra
    // 0x8002935C: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8002935C: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
L_80029360:
    // 0x80029360: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80029364: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80029368: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8002936C: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80029370: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80029374: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029378: bc1f        L_800293A0
    if (!c1cs) {
        // 0x8002937C: nop
    
            goto L_800293A0;
    }
    // 0x8002937C: nop

    // 0x80029380: lw          $t9, -0x2204($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2204);
    // 0x80029384: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80029388: beq         $at, $zero, L_8002956C
    if (ctx->r1 == 0) {
        // 0x8002938C: nop
    
            goto L_8002956C;
    }
    // 0x8002938C: nop

    // 0x80029390: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x80029394: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x80029398: jr          $ra
    // 0x8002939C: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8002939C: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
L_800293A0:
    // 0x800293A0: lwc1        $f8, -0x1FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1FC);
    // 0x800293A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800293A8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800293AC: nop

    // 0x800293B0: bc1t        L_8002956C
    if (c1cs) {
        // 0x800293B4: nop
    
            goto L_8002956C;
    }
    // 0x800293B4: nop

    // 0x800293B8: lwc1        $f10, -0x1F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1F8);
    // 0x800293BC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800293C0: nop

    // 0x800293C4: bc1t        L_8002956C
    if (c1cs) {
        // 0x800293C8: nop
    
            goto L_8002956C;
    }
    // 0x800293C8: nop

    // 0x800293CC: lwc1        $f16, 0xAC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x800293D0: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x800293D4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x800293D8: nop

    // 0x800293DC: bc1f        L_8002956C
    if (!c1cs) {
        // 0x800293E0: nop
    
            goto L_8002956C;
    }
    // 0x800293E0: nop

    // 0x800293E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800293E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800293EC: lwc1        $f18, -0x1F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1F4);
    // 0x800293F0: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x800293F4: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x800293F8: lwc1        $f4, 0xC0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC0);
    // 0x800293FC: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80029400: nop

    // 0x80029404: bc1f        L_8002956C
    if (!c1cs) {
        // 0x80029408: nop
    
            goto L_8002956C;
    }
    // 0x80029408: nop

    // 0x8002940C: jr          $ra
    // 0x80029410: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x80029410: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
L_80029414:
    // 0x80029414: lw          $t1, -0x227C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X227C);
    // 0x80029418: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8002941C: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80029420: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80029424: bnel        $at, $zero, L_80029544
    if (ctx->r1 != 0) {
        // 0x80029428: lwc1        $f18, 0x0($a2)
        ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
            goto L_80029544;
    }
    goto skip_1;
    // 0x80029428: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x8002942C: lw          $t2, -0x2264($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2264);
    // 0x80029430: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029434: beq         $at, $zero, L_8002948C
    if (ctx->r1 == 0) {
        // 0x80029438: lui         $at, 0x4010
        ctx->r1 = S32(0X4010 << 16);
            goto L_8002948C;
    }
    // 0x80029438: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8002943C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80029440: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80029444: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029448: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8002944C: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x80029450: bne         $t3, $zero, L_80029468
    if (ctx->r11 != 0) {
        // 0x80029454: nop
    
            goto L_80029468;
    }
    // 0x80029454: nop

    // 0x80029458: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002945C: lwc1        $f8, -0x1F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1F0);
    // 0x80029460: b           L_80029470
    // 0x80029464: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
        goto L_80029470;
    // 0x80029464: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_80029468:
    // 0x80029468: lwc1        $f10, -0x1EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1EC);
    // 0x8002946C: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_80029470:
    // 0x80029470: lwc1        $f16, 0xC0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC0);
    // 0x80029474: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80029478: nop

    // 0x8002947C: bc1f        L_8002956C
    if (!c1cs) {
        // 0x80029480: nop
    
            goto L_8002956C;
    }
    // 0x80029480: nop

    // 0x80029484: jr          $ra
    // 0x80029488: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x80029488: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
L_8002948C:
    // 0x8002948C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80029490: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80029494: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80029498: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x8002949C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800294A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800294A4: bc1f        L_800294CC
    if (!c1cs) {
        // 0x800294A8: nop
    
            goto L_800294CC;
    }
    // 0x800294A8: nop

    // 0x800294AC: lw          $t4, -0x224C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X224C);
    // 0x800294B0: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800294B4: beq         $at, $zero, L_8002956C
    if (ctx->r1 == 0) {
        // 0x800294B8: nop
    
            goto L_8002956C;
    }
    // 0x800294B8: nop

    // 0x800294BC: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x800294C0: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x800294C4: jr          $ra
    // 0x800294C8: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x800294C8: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
L_800294CC:
    // 0x800294CC: lwc1        $f18, -0x1E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1E8);
    // 0x800294D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800294D4: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800294D8: nop

    // 0x800294DC: bc1t        L_8002956C
    if (c1cs) {
        // 0x800294E0: nop
    
            goto L_8002956C;
    }
    // 0x800294E0: nop

    // 0x800294E4: lwc1        $f4, -0x1E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1E4);
    // 0x800294E8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800294EC: nop

    // 0x800294F0: bc1t        L_8002956C
    if (c1cs) {
        // 0x800294F4: nop
    
            goto L_8002956C;
    }
    // 0x800294F4: nop

    // 0x800294F8: lwc1        $f6, 0xAC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x800294FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029500: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80029504: nop

    // 0x80029508: bc1f        L_8002956C
    if (!c1cs) {
        // 0x8002950C: nop
    
            goto L_8002956C;
    }
    // 0x8002950C: nop

    // 0x80029510: lwc1        $f8, -0x1E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1E0);
    // 0x80029514: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80029518: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002951C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80029520: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x80029524: lwc1        $f16, 0xC0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC0);
    // 0x80029528: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8002952C: nop

    // 0x80029530: bc1f        L_8002956C
    if (!c1cs) {
        // 0x80029534: nop
    
            goto L_8002956C;
    }
    // 0x80029534: nop

    // 0x80029538: jr          $ra
    // 0x8002953C: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8002953C: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
    // 0x80029540: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
L_80029544:
    // 0x80029544: lwc1        $f4, 0xAC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x80029548: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002954C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80029550: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80029554: nop

    // 0x80029558: bc1f        L_8002956C
    if (!c1cs) {
        // 0x8002955C: nop
    
            goto L_8002956C;
    }
    // 0x8002955C: nop

    // 0x80029560: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x80029564: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x80029568: swc1        $f2, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->f2.u32l;
L_8002956C:
    // 0x8002956C: jr          $ra
    // 0x80029570: nop

    return;
    // 0x80029570: nop

;}
RECOMP_FUNC void func_800748C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800748C0: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x800748C4: sb          $a2, 0x2B2($t6)
    MEM_B(0X2B2, ctx->r14) = ctx->r6;
    // 0x800748C8: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x800748CC: sb          $t7, 0x45D($a0)
    MEM_B(0X45D, ctx->r4) = ctx->r15;
    // 0x800748D0: jr          $ra
    // 0x800748D4: nop

    return;
    // 0x800748D4: nop

;}
RECOMP_FUNC void func_804758D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804758D0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804758D4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804758D8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804758DC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804758E0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804758E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804758E8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804758EC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804758F0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804758F4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804758F8: jr          $ra
    // 0x804758FC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804758FC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806DF82C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF82C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DF830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF834: jal         0x8004700C
    // 0x806DF838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806DF838: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806DF83C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806DF840: beq         $v0, $zero, L_806DF89C
    if (ctx->r2 == 0) {
        // 0x806DF844: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_806DF89C;
    }
    // 0x806DF844: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806DF848: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x806DF84C: bnel        $a0, $t6, L_806DF878
    if (ctx->r4 != ctx->r14) {
        // 0x806DF850: lw          $t0, 0x8($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X8);
            goto L_806DF878;
    }
    goto skip_0;
    // 0x806DF850: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x806DF854: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x806DF858: addiu       $t8, $zero, 0x15
    ctx->r24 = ADD32(0, 0X15);
    // 0x806DF85C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806DF860: bnel        $t7, $zero, L_806DF890
    if (ctx->r15 != 0) {
        // 0x806DF864: lw          $v0, 0x1E0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1E0);
            goto L_806DF890;
    }
    goto skip_1;
    // 0x806DF864: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    skip_1:
    // 0x806DF868: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x806DF86C: b           L_806DF88C
    // 0x806DF870: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
        goto L_806DF88C;
    // 0x806DF870: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x806DF874: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
L_806DF878:
    // 0x806DF878: addiu       $t1, $zero, 0x15
    ctx->r9 = ADD32(0, 0X15);
    // 0x806DF87C: beql        $t0, $zero, L_806DF890
    if (ctx->r8 == 0) {
        // 0x806DF880: lw          $v0, 0x1E0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1E0);
            goto L_806DF890;
    }
    goto skip_2;
    // 0x806DF880: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    skip_2:
    // 0x806DF884: sw          $t1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r9;
    // 0x806DF888: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
L_806DF88C:
    // 0x806DF88C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
L_806DF890:
    // 0x806DF890: blez        $v0, L_806DF89C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806DF894: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_806DF89C;
    }
    // 0x806DF894: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x806DF898: sw          $t2, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r10;
L_806DF89C:
    // 0x806DF89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DF8A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DF8A4: jr          $ra
    // 0x806DF8A8: nop

    return;
    // 0x806DF8A8: nop

;}
RECOMP_FUNC void func_800066A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800066A8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800066AC: bne         $a0, $at, L_800066BC
    if (ctx->r4 != ctx->r1) {
        // 0x800066B0: lui         $t6, 0x800B
        ctx->r14 = S32(0X800B << 16);
            goto L_800066BC;
    }
    // 0x800066B0: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x800066B4: jr          $ra
    // 0x800066B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800066B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800066BC:
    // 0x800066BC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800066C0: lbu         $t6, 0x76A6($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X76A6);
    // 0x800066C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800066C8: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800066CC: bne         $at, $zero, L_800066DC
    if (ctx->r1 != 0) {
        // 0x800066D0: nop
    
            goto L_800066DC;
    }
    // 0x800066D0: nop

    // 0x800066D4: jr          $ra
    // 0x800066D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800066D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800066DC:
    // 0x800066DC: jr          $ra
    // 0x800066E0: nop

    return;
    // 0x800066E0: nop

;}
RECOMP_FUNC void func_8045B418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B418: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8045B41C: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(104, 0X78C) << 16);
    // 0x8045B420: addiu       $t6, $t6, -0x4E64
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(104, 0X78C));
    // 0x8045B424: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8045B428: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(104, 0X96C) << 16);
    // 0x8045B42C: addiu       $t9, $t9, -0x4C84
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(104, 0X96C));
    // 0x8045B430: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x8045B434: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8045B438: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8045B43C: jr          $ra
    // 0x8045B440: sw          $t9, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r25;
    return;
    // 0x8045B440: sw          $t9, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_80536414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536414: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536418: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053641C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536420: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536424: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536428: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053642C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536430: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536434: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536438: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053643C: jr          $ra
    // 0x80536440: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536440: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806AA3FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA3FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AA400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AA404: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806AA408: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806AA40C: jal         0x80047090
    // 0x806AA410: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806AA410: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x806AA414: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x806AA418: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x806AA41C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(589, 0X11F0) << 16);
    // 0x806AA420: lwc1        $f6, -0x5650($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(589, 0X11F0));
    // 0x806AA424: lwc1        $f4, 0x44($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X44);
    // 0x806AA428: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x806AA42C: lw          $a2, 0x40($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X40);
    // 0x806AA430: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806AA434: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806AA438: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x806AA43C: lw          $a1, 0x3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X3C);
    // 0x806AA440: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x806AA444: jal         0x8004613C
    // 0x806AA448: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806AA448: nop

    after_1:
    // 0x806AA44C: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x806AA450: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x806AA454: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806AA458: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x806AA45C: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x806AA460: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x806AA464: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x806AA468: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x806AA46C: jal         0x80047F9C
    // 0x806AA470: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806AA470: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x806AA474: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x806AA478: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806AA47C: sb          $t2, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r10;
    // 0x806AA480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806AA484: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806AA488: jr          $ra
    // 0x806AA48C: nop

    return;
    // 0x806AA48C: nop

;}
RECOMP_FUNC void func_80439DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439DCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80439DD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80439DD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80439DD8: jal         0x80438EC0
    // 0x80439DDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80438EC0(rdram, ctx);
        goto after_0;
    // 0x80439DDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80439DE0: jal         0x80438E24
    // 0x80439DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80438E24(rdram, ctx);
        goto after_1;
    // 0x80439DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80439DE8: jal         0x80438FEC
    // 0x80439DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80438FEC(rdram, ctx);
        goto after_2;
    // 0x80439DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80439DF0: jal         0x80439218
    // 0x80439DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80439218(rdram, ctx);
        goto after_3;
    // 0x80439DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80439DF8: jal         0x804393DC
    // 0x80439DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804393DC(rdram, ctx);
        goto after_4;
    // 0x80439DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80439E00: jal         0x80439BAC
    // 0x80439E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80439BAC(rdram, ctx);
        goto after_5;
    // 0x80439E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80439E08: jal         0x80438BBC
    // 0x80439E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80438BBC(rdram, ctx);
        goto after_6;
    // 0x80439E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80439E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80439E14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80439E18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80439E1C: jr          $ra
    // 0x80439E20: nop

    return;
    // 0x80439E20: nop

;}
RECOMP_FUNC void func_80028774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028774: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80028778: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x8002877C: beql        $v0, $zero, L_80028878
    if (ctx->r2 == 0) {
        // 0x80028780: lbu         $v0, 0x18($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X18);
            goto L_80028878;
    }
    goto skip_0;
    // 0x80028780: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    skip_0:
    // 0x80028784: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
    // 0x80028788: addiu       $at, $zero, 0x4038
    ctx->r1 = ADD32(0, 0X4038);
    // 0x8002878C: beq         $v1, $at, L_800287B4
    if (ctx->r3 == ctx->r1) {
        // 0x80028790: addiu       $at, $zero, 0x4039
        ctx->r1 = ADD32(0, 0X4039);
            goto L_800287B4;
    }
    // 0x80028790: addiu       $at, $zero, 0x4039
    ctx->r1 = ADD32(0, 0X4039);
    // 0x80028794: beq         $v1, $at, L_800287BC
    if (ctx->r3 == ctx->r1) {
        // 0x80028798: addiu       $at, $zero, 0x407B
        ctx->r1 = ADD32(0, 0X407B);
            goto L_800287BC;
    }
    // 0x80028798: addiu       $at, $zero, 0x407B
    ctx->r1 = ADD32(0, 0X407B);
    // 0x8002879C: beq         $v1, $at, L_800287B4
    if (ctx->r3 == ctx->r1) {
        // 0x800287A0: addiu       $at, $zero, 0x4128
        ctx->r1 = ADD32(0, 0X4128);
            goto L_800287B4;
    }
    // 0x800287A0: addiu       $at, $zero, 0x4128
    ctx->r1 = ADD32(0, 0X4128);
    // 0x800287A4: beq         $v1, $at, L_800287C4
    if (ctx->r3 == ctx->r1) {
        // 0x800287A8: addiu       $at, $zero, 0x4640
        ctx->r1 = ADD32(0, 0X4640);
            goto L_800287C4;
    }
    // 0x800287A8: addiu       $at, $zero, 0x4640
    ctx->r1 = ADD32(0, 0X4640);
    // 0x800287AC: bne         $v1, $at, L_800287CC
    if (ctx->r3 != ctx->r1) {
        // 0x800287B0: nop
    
            goto L_800287CC;
    }
    // 0x800287B0: nop

L_800287B4:
    // 0x800287B4: jr          $ra
    // 0x800287B8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800287B8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800287BC:
    // 0x800287BC: jr          $ra
    // 0x800287C0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x800287C0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800287C4:
    // 0x800287C4: jr          $ra
    // 0x800287C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800287C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800287CC:
    // 0x800287CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800287D0: lwc1        $f2, -0x24C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X24C);
    // 0x800287D4: lwc1        $f0, 0xC4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x800287D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800287DC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800287E0: nop

    // 0x800287E4: bc1t        L_8002886C
    if (c1cs) {
        // 0x800287E8: nop
    
            goto L_8002886C;
    }
    // 0x800287E8: nop

    // 0x800287EC: lwc1        $f12, -0x248($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X248);
    // 0x800287F0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800287F4: nop

    // 0x800287F8: bc1t        L_8002886C
    if (c1cs) {
        // 0x800287FC: nop
    
            goto L_8002886C;
    }
    // 0x800287FC: nop

    // 0x80028800: lwc1        $f0, 0xC8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80028804: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80028808: nop

    // 0x8002880C: bc1t        L_8002886C
    if (c1cs) {
        // 0x80028810: nop
    
            goto L_8002886C;
    }
    // 0x80028810: nop

    // 0x80028814: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80028818: nop

    // 0x8002881C: bc1t        L_8002886C
    if (c1cs) {
        // 0x80028820: nop
    
            goto L_8002886C;
    }
    // 0x80028820: nop

    // 0x80028824: lbu         $t7, 0x1F8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1F8);
    // 0x80028828: beq         $t7, $zero, L_8002886C
    if (ctx->r15 == 0) {
        // 0x8002882C: nop
    
            goto L_8002886C;
    }
    // 0x8002882C: nop

    // 0x80028830: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x80028834: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80028838: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8002883C: beq         $t8, $zero, L_8002886C
    if (ctx->r24 == 0) {
        // 0x80028840: nop
    
            goto L_8002886C;
    }
    // 0x80028840: nop

    // 0x80028844: lw          $t9, 0x3EC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X3EC);
    // 0x80028848: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x8002884C: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80028850: lbu         $v0, 0x598($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X598);
    // 0x80028854: beq         $v0, $at, L_8002886C
    if (ctx->r2 == ctx->r1) {
        // 0x80028858: addiu       $at, $zero, 0xA3
        ctx->r1 = ADD32(0, 0XA3);
            goto L_8002886C;
    }
    // 0x80028858: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x8002885C: beq         $v0, $at, L_8002886C
    if (ctx->r2 == ctx->r1) {
        // 0x80028860: nop
    
            goto L_8002886C;
    }
    // 0x80028860: nop

    // 0x80028864: jr          $ra
    // 0x80028868: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80028868: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8002886C:
    // 0x8002886C: jr          $ra
    // 0x80028870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80028870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80028874: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
L_80028878:
    // 0x80028878: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002887C: beq         $v0, $at, L_8002888C
    if (ctx->r2 == ctx->r1) {
        // 0x80028880: addiu       $at, $zero, 0x68
        ctx->r1 = ADD32(0, 0X68);
            goto L_8002888C;
    }
    // 0x80028880: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80028884: bnel        $v0, $at, L_80028898
    if (ctx->r2 != ctx->r1) {
        // 0x80028888: lbu         $t1, 0x1F8($a1)
        ctx->r9 = MEM_BU(ctx->r5, 0X1F8);
            goto L_80028898;
    }
    goto skip_1;
    // 0x80028888: lbu         $t1, 0x1F8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X1F8);
    skip_1:
L_8002888C:
    // 0x8002888C: jr          $ra
    // 0x80028890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80028890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80028894: lbu         $t1, 0x1F8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X1F8);
L_80028898:
    // 0x80028898: beql        $t1, $zero, L_800288E0
    if (ctx->r9 == 0) {
        // 0x8002889C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800288E0;
    }
    goto skip_2;
    // 0x8002889C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800288A0: lw          $t2, 0x1F4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X1F4);
    // 0x800288A4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800288A8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x800288AC: beql        $t2, $zero, L_800288E0
    if (ctx->r10 == 0) {
        // 0x800288B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800288E0;
    }
    goto skip_3;
    // 0x800288B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x800288B4: lw          $t3, 0x3EC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X3EC);
    // 0x800288B8: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x800288BC: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800288C0: lbu         $v0, 0x598($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X598);
    // 0x800288C4: beq         $v0, $at, L_800288DC
    if (ctx->r2 == ctx->r1) {
        // 0x800288C8: addiu       $at, $zero, 0xA3
        ctx->r1 = ADD32(0, 0XA3);
            goto L_800288DC;
    }
    // 0x800288C8: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x800288CC: beql        $v0, $at, L_800288E0
    if (ctx->r2 == ctx->r1) {
        // 0x800288D0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800288E0;
    }
    goto skip_4;
    // 0x800288D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x800288D4: jr          $ra
    // 0x800288D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800288D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800288DC:
    // 0x800288DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800288E0:
    // 0x800288E0: jr          $ra
    // 0x800288E4: nop

    return;
    // 0x800288E4: nop

;}
RECOMP_FUNC void func_80042314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042314: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80042318: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8004231C: lw          $v1, 0xAA4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XAA4);
    // 0x80042320: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80042324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042328: beq         $v1, $zero, L_80042454
    if (ctx->r3 == 0) {
        // 0x8004232C: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80042454;
    }
    // 0x8004232C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80042330: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80042334: bne         $v1, $zero, L_80042350
    if (ctx->r3 != 0) {
        // 0x80042338: addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
            goto L_80042350;
    }
    // 0x80042338: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8004233C: jal         0x800422CC
    // 0x80042340: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800422CC(rdram, ctx);
        goto after_0;
    // 0x80042340: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80042344: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80042348: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8004234C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_80042350:
    // 0x80042350: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x80042354: bne         $t6, $zero, L_80042454
    if (ctx->r14 != 0) {
        // 0x80042358: sw          $v1, 0xAA4($v0)
        MEM_W(0XAA4, ctx->r2) = ctx->r3;
            goto L_80042454;
    }
    // 0x80042358: sw          $v1, 0xAA4($v0)
    MEM_W(0XAA4, ctx->r2) = ctx->r3;
    // 0x8004235C: lw          $t7, 0xE9C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XE9C);
    // 0x80042360: beq         $t7, $zero, L_80042454
    if (ctx->r15 == 0) {
        // 0x80042364: nop
    
            goto L_80042454;
    }
    // 0x80042364: nop

    // 0x80042368: jal         0x800653D8
    // 0x8004236C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8004236C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80042370: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80042374: andi        $t0, $v0, 0x7
    ctx->r8 = ctx->r2 & 0X7;
    // 0x80042378: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8004237C: lh          $t9, 0x13C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X13C);
    // 0x80042380: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80042384: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80042388: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8004238C: lwc1        $f8, 0x4F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4F8);
    // 0x80042390: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80042394: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80042398: andi        $t2, $v1, 0x8
    ctx->r10 = ctx->r3 & 0X8;
    // 0x8004239C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800423A0: beq         $t2, $zero, L_800423D0
    if (ctx->r10 == 0) {
        // 0x800423A4: swc1        $f10, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
            goto L_800423D0;
    }
    // 0x800423A4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x800423A8: jal         0x800653D8
    // 0x800423AC: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x800423AC: nop

    after_2:
    // 0x800423B0: andi        $t3, $v0, 0x7F
    ctx->r11 = ctx->r2 & 0X7F;
    // 0x800423B4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800423B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800423BC: lwc1        $f4, 0x304($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X304);
    // 0x800423C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800423C4: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800423C8: b           L_800423F8
    // 0x800423CC: nop

        goto L_800423F8;
    // 0x800423CC: nop

L_800423D0:
    // 0x800423D0: jal         0x800653D8
    // 0x800423D4: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x800423D4: nop

    after_3:
    // 0x800423D8: sra         $t4, $v0, 4
    ctx->r12 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800423DC: andi        $t5, $t4, 0x7F
    ctx->r13 = ctx->r12 & 0X7F;
    // 0x800423E0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800423E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800423E8: lwc1        $f10, 0x308($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X308);
    // 0x800423EC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800423F0: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800423F4: nop

L_800423F8:
    // 0x800423F8: jal         0x80066DE4
    // 0x800423FC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x800423FC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x80042400: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80042404: jal         0x80066E88
    // 0x80042408: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x80042408: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8004240C: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80042410: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80042414: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80042418: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004241C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80042420: lwc1        $f6, 0x84($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X84);
    // 0x80042424: lwc1        $f16, 0x8C($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x80042428: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8004242C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80042430: lw          $t9, -0x72C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72C4);
    // 0x80042434: lwc1        $f10, 0x88($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X88);
    // 0x80042438: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004243C: lwc1        $f4, 0x30C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X30C);
    // 0x80042440: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80042444: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80042448: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8004244C: jalr        $t9
    // 0x80042450: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80042450: nop

    after_6:
L_80042454:
    // 0x80042454: jal         0x8002B3A0
    // 0x80042458: nop

    func_8002B3A0(rdram, ctx);
        goto after_7;
    // 0x80042458: nop

    after_7:
    // 0x8004245C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042460: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80042464: jr          $ra
    // 0x80042468: nop

    return;
    // 0x80042468: nop

;}
RECOMP_FUNC void func_8006C0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C0F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006C0F8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8006C0FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006C100: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006C104: lw          $t6, -0x7D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D6C);
    // 0x8006C108: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006C10C: lwc1        $f6, 0x1070($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1070);
    // 0x8006C110: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006C114: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8006C118: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x8006C11C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8006C120: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8006C124: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006C128: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006C12C: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8006C130: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x8006C134: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006C138: addiu       $a0, $a0, 0x570
    ctx->r4 = ADD32(ctx->r4, 0X570);
    // 0x8006C13C: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8006C140: addiu       $a1, $sp, 0x36
    ctx->r5 = ADD32(ctx->r29, 0X36);
    // 0x8006C144: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006C148: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8006C14C: jal         0x80086600
    // 0x8006C150: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspective(rdram, ctx);
        goto after_0;
    // 0x8006C150: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8006C154: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8006C158: lw          $t7, -0x7D6C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D6C);
    // 0x8006C15C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8006C160: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006C164: lwc1        $f16, 0x4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8006C168: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006C16C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006C170: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8006C174: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006C178: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006C17C: addiu       $a0, $a0, 0x570
    ctx->r4 = ADD32(ctx->r4, 0X570);
    // 0x8006C180: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8006C184: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8006C188: jal         0x8007FFF0
    // 0x8006C18C: nop

    func_8007FFF0(rdram, ctx);
        goto after_1;
    // 0x8006C18C: nop

    after_1:
    // 0x8006C190: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8006C194: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8006C198: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006C19C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8006C1A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006C1A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006C1A8: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8006C1AC: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006C1B0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8006C1B4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8006C1B8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006C1BC: addiu       $a0, $a0, 0x5B0
    ctx->r4 = ADD32(ctx->r4, 0X5B0);
    // 0x8006C1C0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8006C1C4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8006C1C8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8006C1CC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8006C1D0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8006C1D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8006C1D8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8006C1DC: jal         0x80087338
    // 0x8006C1E0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    guLookAt(rdram, ctx);
        goto after_2;
    // 0x8006C1E0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8006C1E4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006C1E8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8006C1EC: addiu       $a1, $a1, 0x5B0
    ctx->r5 = ADD32(ctx->r5, 0X5B0);
    // 0x8006C1F0: jal         0x8007FD6C
    // 0x8006C1F4: addiu       $a0, $a0, 0x570
    ctx->r4 = ADD32(ctx->r4, 0X570);
    func_8007FD6C(rdram, ctx);
        goto after_3;
    // 0x8006C1F4: addiu       $a0, $a0, 0x570
    ctx->r4 = ADD32(ctx->r4, 0X570);
    after_3:
    // 0x8006C1F8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8006C1FC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8006C200: addiu       $v0, $v0, -0x7AF0
    ctx->r2 = ADD32(ctx->r2, -0X7AF0);
    // 0x8006C204: addiu       $t9, $t9, 0x570
    ctx->r25 = ADD32(ctx->r25, 0X570);
    // 0x8006C208: addiu       $t2, $t9, 0x3C
    ctx->r10 = ADD32(ctx->r25, 0X3C);
    // 0x8006C20C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_8006C210:
    // 0x8006C210: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8006C214: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8006C218: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8006C21C: sw          $t1, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r9;
    // 0x8006C220: lw          $t0, -0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, -0X8);
    // 0x8006C224: sw          $t0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r8;
    // 0x8006C228: lw          $t1, -0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, -0X4);
    // 0x8006C22C: bne         $t9, $t2, L_8006C210
    if (ctx->r25 != ctx->r10) {
        // 0x8006C230: sw          $t1, 0x1C($t8)
        MEM_W(0X1C, ctx->r24) = ctx->r9;
            goto L_8006C210;
    }
    // 0x8006C230: sw          $t1, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r9;
    // 0x8006C234: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8006C238: sw          $t1, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r9;
    // 0x8006C23C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8006C240: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
    // 0x8006C244: sh          $t3, 0x60($t4)
    MEM_H(0X60, ctx->r12) = ctx->r11;
    // 0x8006C248: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006C24C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8006C250: jr          $ra
    // 0x8006C254: nop

    return;
    // 0x8006C254: nop

;}
RECOMP_FUNC void func_805218D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805218D8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805218DC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805218E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805218E4: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(309, 0X448) << 16);
    // 0x805218E8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805218EC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805218F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805218F4: lw          $t8, 0x1B08($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(309, 0X448));
    // 0x805218F8: jr          $ra
    // 0x805218FC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x805218FC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80040C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040CA4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80040CA8: jal         0x8006593C
    // 0x80040CAC: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80040CAC: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    after_0:
    // 0x80040CB0: slti        $at, $v0, 0x35
    ctx->r1 = SIGNED(ctx->r2) < 0X35 ? 1 : 0;
    // 0x80040CB4: bne         $at, $zero, L_80040CC4
    if (ctx->r1 != 0) {
        // 0x80040CB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80040CC4;
    }
    // 0x80040CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040CBC: b           L_80040CD8
    // 0x80040CC0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80040CD8;
    // 0x80040CC0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80040CC4:
    // 0x80040CC4: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80040CC8: bne         $at, $zero, L_80040CD8
    if (ctx->r1 != 0) {
        // 0x80040CCC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80040CD8;
    }
    // 0x80040CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80040CD0: b           L_80040CD8
    // 0x80040CD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80040CD8;
    // 0x80040CD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80040CD8:
    // 0x80040CD8: jr          $ra
    // 0x80040CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80040CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806751EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806751EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806751F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806751F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806751F8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x806751FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80675200: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80675204: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80675208: jal         0x80066DE4
    // 0x8067520C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8067520C: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80675210: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80675214: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80675218: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x8067521C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80675220: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80675224: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80675228: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8067522C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80675230: jal         0x80066E88
    // 0x80675234: swc1        $f18, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f18.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80675234: swc1        $f18, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f18.u32l;
    after_1:
    // 0x80675238: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8067523C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80675240: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x80675244: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80675248: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8067524C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80675250: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80675254: swc1        $f8, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f8.u32l;
    // 0x80675258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067525C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80675260: jr          $ra
    // 0x80675264: nop

    return;
    // 0x80675264: nop

;}
RECOMP_FUNC void func_807A6558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6558: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x807A655C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807A6560: lw          $v1, -0x762C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X762C);
    // 0x807A6564: lw          $t6, -0x7628($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7628);
    // 0x807A6568: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x807A656C: addiu       $a0, $a0, 0x7EA8
    ctx->r4 = ADD32(ctx->r4, 0X7EA8);
    // 0x807A6570: beq         $v1, $t6, L_807A6580
    if (ctx->r3 == ctx->r14) {
        // 0x807A6574: lui         $v0, 0x800F
        ctx->r2 = S32(0X800F << 16);
            goto L_807A6580;
    }
    // 0x807A6574: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807A6578: jr          $ra
    // 0x807A657C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x807A657C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_807A6580:
    // 0x807A6580: addiu       $v0, $v0, 0x7F18
    ctx->r2 = ADD32(ctx->r2, 0X7F18);
    // 0x807A6584: lw          $t7, 0xB34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB34);
L_807A6588:
    // 0x807A6588: beql        $v1, $t7, L_807A659C
    if (ctx->r3 == ctx->r15) {
        // 0x807A658C: lw          $t8, 0xB38($a0)
        ctx->r24 = MEM_W(ctx->r4, 0XB38);
            goto L_807A659C;
    }
    goto skip_0;
    // 0x807A658C: lw          $t8, 0xB38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XB38);
    skip_0:
    // 0x807A6590: jr          $ra
    // 0x807A6594: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x807A6594: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x807A6598: lw          $t8, 0xB38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XB38);
L_807A659C:
    // 0x807A659C: beql        $v1, $t8, L_807A65B0
    if (ctx->r3 == ctx->r24) {
        // 0x807A65A0: lw          $t9, 0xB3C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XB3C);
            goto L_807A65B0;
    }
    goto skip_1;
    // 0x807A65A0: lw          $t9, 0xB3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XB3C);
    skip_1:
    // 0x807A65A4: jr          $ra
    // 0x807A65A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x807A65A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x807A65AC: lw          $t9, 0xB3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XB3C);
L_807A65B0:
    // 0x807A65B0: beql        $v1, $t9, L_807A65C4
    if (ctx->r3 == ctx->r25) {
        // 0x807A65B4: lw          $t0, 0xB40($a0)
        ctx->r8 = MEM_W(ctx->r4, 0XB40);
            goto L_807A65C4;
    }
    goto skip_2;
    // 0x807A65B4: lw          $t0, 0xB40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XB40);
    skip_2:
    // 0x807A65B8: jr          $ra
    // 0x807A65BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x807A65BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x807A65C0: lw          $t0, 0xB40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XB40);
L_807A65C4:
    // 0x807A65C4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x807A65C8: beq         $v1, $t0, L_807A65D8
    if (ctx->r3 == ctx->r8) {
        // 0x807A65CC: nop
    
            goto L_807A65D8;
    }
    // 0x807A65CC: nop

    // 0x807A65D0: jr          $ra
    // 0x807A65D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x807A65D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_807A65D8:
    // 0x807A65D8: bnel        $a0, $v0, L_807A6588
    if (ctx->r4 != ctx->r2) {
        // 0x807A65DC: lw          $t7, 0xB34($a0)
        ctx->r15 = MEM_W(ctx->r4, 0XB34);
            goto L_807A6588;
    }
    goto skip_3;
    // 0x807A65DC: lw          $t7, 0xB34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB34);
    skip_3:
    // 0x807A65E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x807A65E4: jr          $ra
    // 0x807A65E8: nop

    return;
    // 0x807A65E8: nop

;}
RECOMP_FUNC void func_8006E970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E970: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006E974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E978: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8006E97C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006E980: beql        $v0, $zero, L_8006E9C8
    if (ctx->r2 == 0) {
        // 0x8006E984: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006E9C8;
    }
    goto skip_0;
    // 0x8006E984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006E988: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x8006E98C: addiu       $at, $zero, 0x4040
    ctx->r1 = ADD32(0, 0X4040);
    // 0x8006E990: bnel        $t6, $at, L_8006E9C8
    if (ctx->r14 != ctx->r1) {
        // 0x8006E994: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006E9C8;
    }
    goto skip_1;
    // 0x8006E994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8006E998: lw          $t7, 0x1F4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1F4);
    // 0x8006E99C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006E9A0: sw          $zero, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = 0;
    // 0x8006E9A4: jal         0x80047AB8
    // 0x8006E9A8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8006E9A8: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006E9AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006E9B0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8006E9B4: jal         0x80065490
    // 0x8006E9B8: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8006E9B8: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_1:
    // 0x8006E9BC: jal         0x8004816C
    // 0x8006E9C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8004816C(rdram, ctx);
        goto after_2;
    // 0x8006E9C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8006E9C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006E9C8:
    // 0x8006E9C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006E9CC: jr          $ra
    // 0x8006E9D0: nop

    return;
    // 0x8006E9D0: nop

;}
RECOMP_FUNC void func_804B8558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8558: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B855C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B8560: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B8564: jal         0x8004700C
    // 0x804B8568: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804B8568: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804B856C: beq         $v0, $zero, L_804B85B0
    if (ctx->r2 == 0) {
        // 0x804B8570: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_804B85B0;
    }
    // 0x804B8570: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804B8574: jal         0x804B7E74
    // 0x804B8578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7E74(rdram, ctx);
        goto after_1;
    // 0x804B8578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804B857C: jal         0x804B7FDC
    // 0x804B8580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B7FDC(rdram, ctx);
        goto after_2;
    // 0x804B8580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804B8584: jal         0x804B8038
    // 0x804B8588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B8038(rdram, ctx);
        goto after_3;
    // 0x804B8588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804B858C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804B8590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B8594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B8598: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x804B859C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804B85A0: bnel        $s0, $t7, L_804B85B4
    if (ctx->r16 != ctx->r15) {
        // 0x804B85A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804B85B4;
    }
    goto skip_0;
    // 0x804B85A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804B85A8: jal         0x804B8C00
    // 0x804B85AC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804B8C00(rdram, ctx);
        goto after_4;
    // 0x804B85AC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
L_804B85B0:
    // 0x804B85B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B85B4:
    // 0x804B85B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B85B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B85BC: jr          $ra
    // 0x804B85C0: nop

    return;
    // 0x804B85C0: nop

;}
RECOMP_FUNC void func_8051EB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051EB48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051EB4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051EB50: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x8051EB54: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8051EB58: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8051EB5C: slti        $at, $v1, 0x45A0
    ctx->r1 = SIGNED(ctx->r3) < 0X45A0 ? 1 : 0;
    // 0x8051EB60: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x8051EB64: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8051EB68: bne         $at, $zero, L_8051EB94
    if (ctx->r1 != 0) {
        // 0x8051EB6C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8051EB94;
    }
    // 0x8051EB6C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8051EB70: addiu       $t7, $v1, -0x45DA
    ctx->r15 = ADD32(ctx->r3, -0X45DA);
    // 0x8051EB74: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x8051EB78: beq         $at, $zero, L_8051EC28
    if (ctx->r1 == 0) {
        // 0x8051EB7C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8051EC28;
    }
    // 0x8051EB7C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8051EB80: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(300, 0X594) << 16);
    // 0x8051EB84: addu        $at, $at, $t7
    gpr jr_addend_8051EB8C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8051EB88: lw          $t7, -0x106C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(300, 0X594));
    // 0x8051EB8C: jr          $t7
    // 0x8051EB90: nop

    switch (jr_addend_8051EB8C >> 2) {
        case 0: goto L_8051EBC0; break;
        case 1: goto L_8051EC28; break;
        case 2: goto L_8051EC28; break;
        case 3: goto L_8051EC28; break;
        case 4: goto L_8051EC10; break;
        case 5: goto L_8051EC10; break;
        case 6: goto L_8051EC10; break;
        case 7: goto L_8051EC10; break;
        default: switch_error(__func__, 0x8051EB8C, 0x8051EF94);
    }
    // 0x8051EB90: nop

L_8051EB94:
    // 0x8051EB94: addiu       $at, $zero, 0x459F
    ctx->r1 = ADD32(0, 0X459F);
    // 0x8051EB98: bne         $v0, $at, L_8051EC28
    if (ctx->r2 != ctx->r1) {
        // 0x8051EB9C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8051EC28;
    }
    // 0x8051EB9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8051EBA0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8051EBA4: sw          $v1, -0x71AC($at)
    MEM_W(-0X71AC, ctx->r1) = ctx->r3;
    // 0x8051EBA8: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x8051EBAC: jal         0x8051EA10
    // 0x8051EBB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8051EA10(rdram, ctx);
        goto after_0;
    // 0x8051EBB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051EBB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051EBB8: b           L_8051EC2C
    // 0x8051EBBC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_8051EC2C;
    // 0x8051EBBC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8051EBC0:
    // 0x8051EBC0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8051EBC4: lw          $v0, -0x71A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X71A8);
    // 0x8051EBC8: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(300, 0X560) << 16);
    // 0x8051EBCC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8051EBD0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8051EBD4: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x8051EBD8: bne         $v0, $zero, L_8051EBF4
    if (ctx->r2 != 0) {
        // 0x8051EBDC: addiu       $t8, $t8, -0x10A0
        ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(300, 0X560));
            goto L_8051EBF4;
    }
    // 0x8051EBDC: addiu       $t8, $t8, -0x10A0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(300, 0X560));
    // 0x8051EBE0: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8051EBE4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8051EBE8: lw          $v0, -0x71A8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X71A8);
    // 0x8051EBEC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8051EBF0: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
L_8051EBF4:
    // 0x8051EBF4: bnel        $v1, $v0, L_8051EC04
    if (ctx->r3 != ctx->r2) {
        // 0x8051EBF8: lw          $t9, 0x16C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X16C);
            goto L_8051EC04;
    }
    goto skip_0;
    // 0x8051EBF8: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    skip_0:
    // 0x8051EBFC: sh          $v1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r3;
    // 0x8051EC00: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
L_8051EC04:
    // 0x8051EC04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8051EC08: b           L_8051EC2C
    // 0x8051EC0C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
        goto L_8051EC2C;
    // 0x8051EC0C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_8051EC10:
    // 0x8051EC10: lw          $t2, 0x16C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X16C);
    // 0x8051EC14: addiu       $t0, $v1, -0x45DE
    ctx->r8 = ADD32(ctx->r3, -0X45DE);
    // 0x8051EC18: lui         $t1, 0x8052
    ctx->r9 = S32(RELOC_HI16(300, 0X560) << 16);
    // 0x8051EC1C: sh          $t0, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r8;
    // 0x8051EC20: addiu       $t1, $t1, -0x10A0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(300, 0X560));
    // 0x8051EC24: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_8051EC28:
    // 0x8051EC28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8051EC2C:
    // 0x8051EC2C: jal         0x8051EF30
    // 0x8051EC30: nop

    func_8051EF30(rdram, ctx);
        goto after_1;
    // 0x8051EC30: nop

    after_1:
    // 0x8051EC34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051EC38: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8051EC3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8051EC40: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
    // 0x8051EC44: jr          $ra
    // 0x8051EC48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8051EC48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800314B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800314B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800314B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800314BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800314C0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800314C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800314C8: jal         0x80030F30
    // 0x800314CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80030F30(rdram, ctx);
        goto after_0;
    // 0x800314CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800314D0: beql        $v0, $zero, L_800314FC
    if (ctx->r2 == 0) {
        // 0x800314D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800314FC;
    }
    goto skip_0;
    // 0x800314D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800314D8: jal         0x80041D3C
    // 0x800314DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80041D3C(rdram, ctx);
        goto after_1;
    // 0x800314DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800314E0: jal         0x80021A44
    // 0x800314E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021A44(rdram, ctx);
        goto after_2;
    // 0x800314E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800314E8: jal         0x80028220
    // 0x800314EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_3;
    // 0x800314EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800314F0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800314F4: sw          $v0, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->r2;
    // 0x800314F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800314FC:
    // 0x800314FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80031500: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80031504: jr          $ra
    // 0x80031508: nop

    return;
    // 0x80031508: nop

;}
RECOMP_FUNC void func_8043E364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043E368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E36C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8043E370: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8043E374: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8043E378: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x8043E37C: beql        $t8, $zero, L_8043E398
    if (ctx->r24 == 0) {
        // 0x8043E380: lwc1        $f12, 0xC8($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_8043E398;
    }
    goto skip_0;
    // 0x8043E380: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    skip_0:
    // 0x8043E384: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    // 0x8043E388: jal         0x8043E490
    // 0x8043E38C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043E490(rdram, ctx);
        goto after_0;
    // 0x8043E38C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043E390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043E394: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
L_8043E398:
    // 0x8043E398: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8043E39C: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8043E3A0: jal         0x80065ABC
    // 0x8043E3A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x8043E3A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8043E3A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043E3AC: jal         0x8043DCF4
    // 0x8043E3B0: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    func_8043DCF4(rdram, ctx);
        goto after_2;
    // 0x8043E3B0: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x8043E3B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E3B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043E3BC: jr          $ra
    // 0x8043E3C0: nop

    return;
    // 0x8043E3C0: nop

;}
RECOMP_FUNC void func_800101E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800101E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800101E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800101E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800101EC: lw          $t6, 0xD8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD8);
    // 0x800101F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800101F4: blezl       $t6, L_80010220
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800101F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80010220;
    }
    goto skip_0;
    // 0x800101F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800101FC:
    // 0x800101FC: jal         0x8000F984
    // 0x80010200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000F984(rdram, ctx);
        goto after_0;
    // 0x80010200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80010204: jal         0x8000CAB8
    // 0x80010208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000CAB8(rdram, ctx);
        goto after_1;
    // 0x80010208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001020C: lw          $t7, 0xD8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XD8);
    // 0x80010210: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80010214: bgtz        $t8, L_800101FC
    if (SIGNED(ctx->r24) > 0) {
        // 0x80010218: sw          $t8, 0xD8($s0)
        MEM_W(0XD8, ctx->r16) = ctx->r24;
            goto L_800101FC;
    }
    // 0x80010218: sw          $t8, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r24;
    // 0x8001021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80010220:
    // 0x80010220: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80010224: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80010228: jr          $ra
    // 0x8001022C: nop

    return;
    // 0x8001022C: nop

;}
RECOMP_FUNC void func_804BBD44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BBD44: lw          $v0, 0x350($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X350);
    // 0x804BBD48: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X3FF8) << 16);
    // 0x804BBD4C: bnel        $a1, $v0, L_804BBD60
    if (ctx->r5 != ctx->r2) {
        // 0x804BBD50: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_804BBD60;
    }
    goto skip_0;
    // 0x804BBD50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x804BBD54: jr          $ra
    // 0x804BBD58: lwc1        $f0, -0x6D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X3FF8));
    return;
    // 0x804BBD58: lwc1        $f0, -0x6D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X3FF8));
    // 0x804BBD5C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_804BBD60:
    // 0x804BBD60: bne         $a1, $v0, L_804BBD7C
    if (ctx->r5 != ctx->r2) {
        // 0x804BBD64: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_804BBD7C;
    }
    // 0x804BBD64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804BBD68: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x804BBD6C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X3FF8) << 16);
    // 0x804BBD70: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x804BBD74: jr          $ra
    // 0x804BBD78: lwc1        $f0, -0x6D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X3FF8));
    return;
    // 0x804BBD78: lwc1        $f0, -0x6D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X3FF8));
L_804BBD7C:
    // 0x804BBD7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x804BBD80: bne         $a1, $v0, L_804BBD98
    if (ctx->r5 != ctx->r2) {
        // 0x804BBD84: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_804BBD98;
    }
    // 0x804BBD84: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x804BBD88: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X3FFC) << 16);
    // 0x804BBD8C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x804BBD90: jr          $ra
    // 0x804BBD94: lwc1        $f0, -0x6D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X3FFC));
    return;
    // 0x804BBD94: lwc1        $f0, -0x6D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X3FFC));
L_804BBD98:
    // 0x804BBD98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x804BBD9C: bne         $a1, $v0, L_804BBDB4
    if (ctx->r5 != ctx->r2) {
        // 0x804BBDA0: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_804BBDB4;
    }
    // 0x804BBDA0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x804BBDA4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4000) << 16);
    // 0x804BBDA8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x804BBDAC: jr          $ra
    // 0x804BBDB0: lwc1        $f0, -0x6D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4000));
    return;
    // 0x804BBDB0: lwc1        $f0, -0x6D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4000));
L_804BBDB4:
    // 0x804BBDB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x804BBDB8: bne         $a1, $v0, L_804BBDD0
    if (ctx->r5 != ctx->r2) {
        // 0x804BBDBC: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_804BBDD0;
    }
    // 0x804BBDBC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x804BBDC0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4004) << 16);
    // 0x804BBDC4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x804BBDC8: jr          $ra
    // 0x804BBDCC: lwc1        $f0, -0x6CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4004));
    return;
    // 0x804BBDCC: lwc1        $f0, -0x6CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4004));
L_804BBDD0:
    // 0x804BBDD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804BBDD4: nop

    // 0x804BBDD8: jr          $ra
    // 0x804BBDDC: nop

    return;
    // 0x804BBDDC: nop

;}
RECOMP_FUNC void func_800582CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800582CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800582D0: jr          $ra
    // 0x800582D4: addiu       $v0, $v0, -0x4C10
    ctx->r2 = ADD32(ctx->r2, -0X4C10);
    return;
    // 0x800582D4: addiu       $v0, $v0, -0x4C10
    ctx->r2 = ADD32(ctx->r2, -0X4C10);
;}
RECOMP_FUNC void func_800387C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800387C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800387C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800387C8: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800387CC: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800387D0: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x800387D4: lw          $t6, 0x78($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X78);
    // 0x800387D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800387DC: beq         $t6, $zero, L_80038840
    if (ctx->r14 == 0) {
        // 0x800387E0: nop
    
            goto L_80038840;
    }
    // 0x800387E0: nop

    // 0x800387E4: lh          $v1, 0xAE0($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XAE0);
    // 0x800387E8: lh          $a2, 0xADE($a3)
    ctx->r6 = MEM_H(ctx->r7, 0XADE);
    // 0x800387EC: lw          $v0, 0x60($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X60);
    // 0x800387F0: slt         $t2, $zero, $v1
    ctx->r10 = SIGNED(0) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800387F4: sltu        $t9, $zero, $v1
    ctx->r25 = 0 < ctx->r3 ? 1 : 0;
    // 0x800387F8: sltu        $t8, $zero, $a2
    ctx->r24 = 0 < ctx->r6 ? 1 : 0;
    // 0x800387FC: xor         $t3, $v0, $t2
    ctx->r11 = ctx->r2 ^ ctx->r10;
    // 0x80038800: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80038804: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80038808: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8003880C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80038810: xori        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 ^ 0X1;
    // 0x80038814: sw          $t7, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->r15;
    // 0x80038818: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x8003881C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80038820: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80038824: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80038828: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8003882C: lw          $t9, -0x1448($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1448);
    // 0x80038830: jalr        $t9
    // 0x80038834: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80038834: nop

    after_0:
    // 0x80038838: b           L_80038840
    // 0x8003883C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038840;
    // 0x8003883C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038840:
    // 0x80038840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038848: jr          $ra
    // 0x8003884C: nop

    return;
    // 0x8003884C: nop

;}
RECOMP_FUNC void func_807C5080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C5080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C5084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C5088: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C508C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807C5090: lui         $t7, 0x807C
    ctx->r15 = S32(RELOC_HI16(910, 0XF28) << 16);
    // 0x807C5094: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x807C5098: beq         $v1, $zero, L_807C50A8
    if (ctx->r3 == 0) {
        // 0x807C509C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_807C50A8;
    }
    // 0x807C509C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x807C50A0: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x807C50A4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_807C50A8:
    // 0x807C50A8: bne         $v1, $zero, L_807C5170
    if (ctx->r3 != 0) {
        // 0x807C50AC: nop
    
            goto L_807C5170;
    }
    // 0x807C50AC: nop

    // 0x807C50B0: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x807C50B4: lui         $t8, 0x807C
    ctx->r24 = S32(RELOC_HI16(910, 0XF10) << 16);
    // 0x807C50B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807C50BC: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x807C50C0: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x807C50C4: lw          $t7, 0x58E8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(910, 0XF28));
    // 0x807C50C8: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x807C50CC: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x807C50D0: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x807C50D4: lw          $t8, 0x58D0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(910, 0XF10));
    // 0x807C50D8: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x807C50DC: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x807C50E0: bne         $t9, $at, L_807C50FC
    if (ctx->r25 != ctx->r1) {
        // 0x807C50E4: sw          $t8, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->r24;
            goto L_807C50FC;
    }
    // 0x807C50E4: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x807C50E8: lw          $t0, 0x138($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X138);
    // 0x807C50EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807C50F0: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x807C50F4: sw          $t2, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->r10;
    // 0x807C50F8: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
L_807C50FC:
    // 0x807C50FC: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x807C5100: bne         $at, $zero, L_807C5170
    if (ctx->r1 != 0) {
        // 0x807C5104: addiu       $t3, $zero, 0x32
        ctx->r11 = ADD32(0, 0X32);
            goto L_807C5170;
    }
    // 0x807C5104: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x807C5108: lw          $t4, 0x24($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X24);
    // 0x807C510C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x807C5110: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x807C5114: bne         $t4, $zero, L_807C5158
    if (ctx->r12 != 0) {
        // 0x807C5118: sw          $t3, 0x28($v0)
        MEM_W(0X28, ctx->r2) = ctx->r11;
            goto L_807C5158;
    }
    // 0x807C5118: sw          $t3, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r11;
    // 0x807C511C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x807C5120: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807C5124: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x807C5128: addiu       $v1, $a3, 0xC4
    ctx->r3 = ADD32(ctx->r7, 0XC4);
    // 0x807C512C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(910, 0X1344) << 16);
    // 0x807C5130: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x807C5134: lwc1        $f6, 0x5D04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(910, 0X1344));
    // 0x807C5138: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807C513C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C5140: swc1        $f6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f6.u32l;
    // 0x807C5144: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x807C5148: jal         0x807C5464
    // 0x807C514C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_807C5464(rdram, ctx);
        goto after_0;
    // 0x807C514C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x807C5150: b           L_807C5170
    // 0x807C5154: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_807C5170;
    // 0x807C5154: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_807C5158:
    // 0x807C5158: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807C515C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C5160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807C5164: jal         0x807C5464
    // 0x807C5168: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_807C5464(rdram, ctx);
        goto after_1;
    // 0x807C5168: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x807C516C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_807C5170:
    // 0x807C5170: jal         0x807C49D0
    // 0x807C5174: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_807C49D0(rdram, ctx);
        goto after_2;
    // 0x807C5174: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x807C5178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C517C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C5180: jr          $ra
    // 0x807C5184: nop

    return;
    // 0x807C5184: nop

;}
RECOMP_FUNC void func_8001A900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A904: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001A908: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001A90C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001A910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A914: beq         $a0, $zero, L_8001A96C
    if (ctx->r4 == 0) {
        // 0x8001A918: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8001A96C;
    }
    // 0x8001A918: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001A91C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8001A920: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001A924: beql        $v0, $zero, L_8001A940
    if (ctx->r2 == 0) {
        // 0x8001A928: lh          $a0, 0x0($a2)
        ctx->r4 = MEM_H(ctx->r6, 0X0);
            goto L_8001A940;
    }
    goto skip_0;
    // 0x8001A928: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    skip_0:
    // 0x8001A92C: beq         $v0, $at, L_8001A93C
    if (ctx->r2 == ctx->r1) {
        // 0x8001A930: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8001A93C;
    }
    // 0x8001A930: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001A934: bne         $v0, $at, L_8001A964
    if (ctx->r2 != ctx->r1) {
        // 0x8001A938: nop
    
            goto L_8001A964;
    }
    // 0x8001A938: nop

L_8001A93C:
    // 0x8001A93C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
L_8001A940:
    // 0x8001A940: jal         0x80019D78
    // 0x8001A944: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80019D78(rdram, ctx);
        goto after_0;
    // 0x8001A944: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001A948: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001A94C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8001A950: jal         0x8001A568
    // 0x8001A954: sw          $t6, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r14;
    func_8001A568(rdram, ctx);
        goto after_1;
    // 0x8001A954: sw          $t6, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r14;
    after_1:
    // 0x8001A958: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001A95C: b           L_8001A96C
    // 0x8001A960: sw          $v0, 0x590($at)
    MEM_W(0X590, ctx->r1) = ctx->r2;
        goto L_8001A96C;
    // 0x8001A960: sw          $v0, 0x590($at)
    MEM_W(0X590, ctx->r1) = ctx->r2;
L_8001A964:
    // 0x8001A964: jal         0x8001A9B0
    // 0x8001A968: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8001A9B0(rdram, ctx);
        goto after_2;
    // 0x8001A968: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_8001A96C:
    // 0x8001A96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A974: jr          $ra
    // 0x8001A978: nop

    return;
    // 0x8001A978: nop

;}
RECOMP_FUNC void func_800726C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800726C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800726C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800726C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800726CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800726D0: lw          $t6, 0x70($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X70);
    // 0x800726D4: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x800726D8: bne         $t6, $zero, L_800726E8
    if (ctx->r14 != 0) {
        // 0x800726DC: nop
    
            goto L_800726E8;
    }
    // 0x800726DC: nop

    // 0x800726E0: beq         $t7, $zero, L_80072720
    if (ctx->r15 == 0) {
        // 0x800726E4: nop
    
            goto L_80072720;
    }
    // 0x800726E4: nop

L_800726E8:
    // 0x800726E8: jal         0x8008B920
    // 0x800726EC: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x800726EC: nop

    after_0:
    // 0x800726F0: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x800726F4: sw          $v1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r3;
    // 0x800726F8: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x800726FC: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80072700: lw          $t0, 0x70($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X70);
    // 0x80072704: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80072708: subu        $t2, $t8, $t0
    ctx->r10 = SUB32(ctx->r24, ctx->r8);
    // 0x8007270C: sltu        $at, $t9, $t1
    ctx->r1 = ctx->r25 < ctx->r9 ? 1 : 0;
    // 0x80072710: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x80072714: sw          $t2, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r10;
    // 0x80072718: subu        $t3, $t9, $t1
    ctx->r11 = SUB32(ctx->r25, ctx->r9);
    // 0x8007271C: sw          $t3, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r11;
L_80072720:
    // 0x80072720: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x80072724: addiu       $t4, $t4, -0x4D94
    ctx->r12 = ADD32(ctx->r12, -0X4D94);
    // 0x80072728: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x8007272C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80072730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80072734: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072738: beq         $v0, $at, L_8007275C
    if (ctx->r2 == ctx->r1) {
        // 0x8007273C: addiu       $a0, $a0, -0x5928
        ctx->r4 = ADD32(ctx->r4, -0X5928);
            goto L_8007275C;
    }
    // 0x8007273C: addiu       $a0, $a0, -0x5928
    ctx->r4 = ADD32(ctx->r4, -0X5928);
    // 0x80072740: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80072744: beq         $v0, $at, L_80072798
    if (ctx->r2 == ctx->r1) {
        // 0x80072748: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80072798;
    }
    // 0x80072748: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007274C: beql        $v0, $at, L_8007279C
    if (ctx->r2 == ctx->r1) {
        // 0x80072750: addiu       $t5, $zero, 0x4
        ctx->r13 = ADD32(0, 0X4);
            goto L_8007279C;
    }
    goto skip_0;
    // 0x80072750: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    skip_0:
    // 0x80072754: b           L_8007279C
    // 0x80072758: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
        goto L_8007279C;
    // 0x80072758: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
L_8007275C:
    // 0x8007275C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80072760: addiu       $v0, $v0, -0x25F0
    ctx->r2 = ADD32(ctx->r2, -0X25F0);
    // 0x80072764: lw          $t6, 0x48($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X48);
    // 0x80072768: lw          $t7, 0x4C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4C);
    // 0x8007276C: lw          $t8, 0x80($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X80);
    // 0x80072770: lw          $t9, 0x84($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X84);
    // 0x80072774: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80072778: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007277C: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x80072780: sltu        $at, $t1, $t9
    ctx->r1 = ctx->r9 < ctx->r25 ? 1 : 0;
    // 0x80072784: addu        $t0, $at, $t6
    ctx->r8 = ADD32(ctx->r1, ctx->r14);
    // 0x80072788: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8007278C: sw          $t0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r8;
    // 0x80072790: jal         0x800824B0
    // 0x80072794: sw          $t1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r9;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80072794: sw          $t1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r9;
    after_1:
L_80072798:
    // 0x80072798: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
L_8007279C:
    // 0x8007279C: sw          $t5, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r13;
    // 0x800727A0: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x800727A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800727A8: beq         $t2, $zero, L_800727BC
    if (ctx->r10 == 0) {
        // 0x800727AC: nop
    
            goto L_800727BC;
    }
    // 0x800727AC: nop

    // 0x800727B0: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x800727B4: jal         0x80082210
    // 0x800727B8: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800727B8: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    after_2:
L_800727BC:
    // 0x800727BC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800727C0: addiu       $a0, $a0, -0x59E0
    ctx->r4 = ADD32(ctx->r4, -0X59E0);
    // 0x800727C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800727C8: jal         0x80082210
    // 0x800727CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800727CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800727D0: jal         0x80071C60
    // 0x800727D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80071C60(rdram, ctx);
        goto after_4;
    // 0x800727D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800727D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800727DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800727E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800727E4: jr          $ra
    // 0x800727E8: nop

    return;
    // 0x800727E8: nop

;}
RECOMP_FUNC void func_80667DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80667DC4: jr          $ra
    // 0x80667DC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80667DC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80068D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80068D98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068D9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068DA0: lw          $t6, 0x478($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X478);
    // 0x80068DA4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80068DA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80068DAC: sb          $zero, -0x7D76($at)
    MEM_B(-0X7D76, ctx->r1) = 0;
    // 0x80068DB0: jal         0x80068340
    // 0x80068DB4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80068340(rdram, ctx);
        goto after_0;
    // 0x80068DB4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80068DB8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068DBC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068DC0: lbu         $t7, 0x7($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X7);
    // 0x80068DC4: beq         $t7, $zero, L_80068DD8
    if (ctx->r15 == 0) {
        // 0x80068DC8: nop
    
            goto L_80068DD8;
    }
    // 0x80068DC8: nop

    // 0x80068DCC: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x80068DD0: bne         $t8, $zero, L_80068DE8
    if (ctx->r24 != 0) {
        // 0x80068DD4: nop
    
            goto L_80068DE8;
    }
    // 0x80068DD4: nop

L_80068DD8:
    // 0x80068DD8: jal         0x8006C848
    // 0x80068DDC: lw          $a0, 0x3F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3F4);
    func_8006C848(rdram, ctx);
        goto after_1;
    // 0x80068DDC: lw          $a0, 0x3F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3F4);
    after_1:
    // 0x80068DE0: jal         0x8005A894
    // 0x80068DE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8005A894(rdram, ctx);
        goto after_2;
    // 0x80068DE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
L_80068DE8:
    // 0x80068DE8: jal         0x8005A484
    // 0x80068DEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8005A484(rdram, ctx);
        goto after_3;
    // 0x80068DEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80068DF0: jal         0x80044A54
    // 0x80068DF4: addiu       $a0, $s0, 0x958
    ctx->r4 = ADD32(ctx->r16, 0X958);
    func_80044A54(rdram, ctx);
        goto after_4;
    // 0x80068DF4: addiu       $a0, $s0, 0x958
    ctx->r4 = ADD32(ctx->r16, 0X958);
    after_4:
    // 0x80068DF8: jal         0x8005F7D8
    // 0x80068DFC: addiu       $a0, $s0, 0x9C8
    ctx->r4 = ADD32(ctx->r16, 0X9C8);
    func_8005F7D8(rdram, ctx);
        goto after_5;
    // 0x80068DFC: addiu       $a0, $s0, 0x9C8
    ctx->r4 = ADD32(ctx->r16, 0X9C8);
    after_5:
    // 0x80068E00: jal         0x80068320
    // 0x80068E04: nop

    func_80068320(rdram, ctx);
        goto after_6;
    // 0x80068E04: nop

    after_6:
    // 0x80068E08: jal         0x8006820C
    // 0x80068E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006820C(rdram, ctx);
        goto after_7;
    // 0x80068E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80068E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068E14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068E18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80068E1C: jr          $ra
    // 0x80068E20: nop

    return;
    // 0x80068E20: nop

;}
RECOMP_FUNC void func_8064A530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A538: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064A53C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8064A540: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064A544: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064A548: nop

    // 0x8064A54C: bc1fl       L_8064A594
    if (!c1cs) {
        // 0x8064A550: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064A594;
    }
    goto skip_0;
    // 0x8064A550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064A554: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064A558: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064A55C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8064A560: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064A564: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064A568: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8064A56C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064A570: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8064A574: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064A578: nop

    // 0x8064A57C: bc1fl       L_8064A594
    if (!c1cs) {
        // 0x8064A580: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064A594;
    }
    goto skip_1;
    // 0x8064A580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064A584: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064A588: jal         0x8064A97C
    // 0x8064A58C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064A97C(rdram, ctx);
        goto after_0;
    // 0x8064A58C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064A590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064A594:
    // 0x8064A594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A598: jr          $ra
    // 0x8064A59C: nop

    return;
    // 0x8064A59C: nop

;}
RECOMP_FUNC void func_8051A858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051A85C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051A860: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x8051A864: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(294, 0XBF4) << 16);
    // 0x8051A868: addiu       $t8, $t8, -0x4EEC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(294, 0XBF4));
    // 0x8051A86C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8051A870: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8051A874: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8051A878: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8051A87C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8051A880: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8051A884: beql        $v1, $zero, L_8051A8D4
    if (ctx->r3 == 0) {
        // 0x8051A888: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8051A8D4;
    }
    goto skip_0;
    // 0x8051A888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8051A88C: jalr        $v1
    // 0x8051A890: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8051A890: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051A894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051A898: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(294, 0XC44) << 16);
    // 0x8051A89C: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x8051A8A0: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x8051A8A4: lw          $t5, 0x134($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X134);
    // 0x8051A8A8: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8051A8AC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8051A8B0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8051A8B4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8051A8B8: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8051A8BC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8051A8C0: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8051A8C4: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x8051A8C8: lw          $t7, -0x4E9C($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(294, 0XC44));
    // 0x8051A8CC: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x8051A8D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051A8D4:
    // 0x8051A8D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051A8D8: jr          $ra
    // 0x8051A8DC: nop

    return;
    // 0x8051A8DC: nop

;}
RECOMP_FUNC void func_805AE444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE444: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE448: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE44C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE450: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE454: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE458: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE45C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE460: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE464: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE468: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE46C: jr          $ra
    // 0x805AE470: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE470: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80737EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737EE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80737EEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80737EF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80737EF4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80737EF8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80737EFC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80737F00: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80737F04: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80737F08: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80737F0C: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80737F10: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80737F14: sw          $zero, 0x44($v0)
    MEM_W(0X44, ctx->r2) = 0;
    // 0x80737F18: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80737F1C: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x80737F20: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80737F24: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x80737F28: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x80737F2C: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x80737F30: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x80737F34: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x80737F38: jr          $ra
    // 0x80737F3C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x80737F3C: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_807A64F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A64F0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A64F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807A64F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807A64FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807A6500: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x807A6504: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x807A6508: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x807A650C: jr          $ra
    // 0x807A6510: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x807A6510: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800762E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800762E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800762EC: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x800762F0: addiu       $a3, $a3, -0x7AD8
    ctx->r7 = ADD32(ctx->r7, -0X7AD8);
    // 0x800762F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800762F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800762FC: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80076300: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80076304: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80076308: beq         $a1, $t6, L_8007637C
    if (ctx->r5 == ctx->r14) {
        // 0x8007630C: lui         $t0, 0xB400
        ctx->r8 = S32(0XB400 << 16);
            goto L_8007637C;
    }
    // 0x8007630C: lui         $t0, 0xB400
    ctx->r8 = S32(0XB400 << 16);
    // 0x80076310: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80076314: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80076318: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x8007631C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80076320: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80076324: addiu       $t2, $t2, -0x65D0
    ctx->r10 = ADD32(ctx->r10, -0X65D0);
    // 0x80076328: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x8007632C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80076330: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80076334: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x80076338: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x8007633C: lui         $t6, 0xAF00
    ctx->r14 = S32(0XAF00 << 16);
    // 0x80076340: ori         $t6, $t6, 0x7FF
    ctx->r14 = ctx->r14 | 0X7FF;
    // 0x80076344: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x80076348: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8007634C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80076350: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80076354: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80076358: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8007635C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80076360: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80076364: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x80076368: jal         0x80075DAC
    // 0x8007636C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80075DAC(rdram, ctx);
        goto after_0;
    // 0x8007636C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80076370: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80076374: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80076378: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8007637C:
    // 0x8007637C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80076384: jr          $ra
    // 0x80076388: nop

    return;
    // 0x80076388: nop

;}
RECOMP_FUNC void func_80021A44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021A44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80021A48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80021A4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80021A50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80021A54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80021A58: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80021A5C: lw          $s2, 0x174($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X174);
    // 0x80021A60: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80021A64: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x80021A68: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80021A6C: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80021A70: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80021A74: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x80021A78: jal         0x80020820
    // 0x80021A7C: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    func_80020820(rdram, ctx);
        goto after_0;
    // 0x80021A7C: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    after_0:
    // 0x80021A80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021A84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80021A88: jal         0x80020ADC
    // 0x80021A8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80020ADC(rdram, ctx);
        goto after_1;
    // 0x80021A8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80021A90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021A94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80021A98: jal         0x80020DBC
    // 0x80021A9C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80020DBC(rdram, ctx);
        goto after_2;
    // 0x80021A9C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x80021AA0: lbu         $t8, 0x18($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X18);
    // 0x80021AA4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80021AA8: bne         $t8, $at, L_80021AC0
    if (ctx->r24 != ctx->r1) {
        // 0x80021AAC: nop
    
            goto L_80021AC0;
    }
    // 0x80021AAC: nop

    // 0x80021AB0: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80021AB4: andi        $t0, $t9, 0x700
    ctx->r8 = ctx->r25 & 0X700;
    // 0x80021AB8: bnel        $t0, $zero, L_80021ACC
    if (ctx->r8 != 0) {
        // 0x80021ABC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80021ACC;
    }
    goto skip_0;
    // 0x80021ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80021AC0:
    // 0x80021AC0: jal         0x8002181C
    // 0x80021AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8002181C(rdram, ctx);
        goto after_3;
    // 0x80021AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80021AC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80021ACC:
    // 0x80021ACC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80021AD0: jal         0x8001F904
    // 0x80021AD4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8001F904(rdram, ctx);
        goto after_4;
    // 0x80021AD4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x80021AD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021ADC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80021AE0: jal         0x80021884
    // 0x80021AE4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80021884(rdram, ctx);
        goto after_5;
    // 0x80021AE4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_5:
    // 0x80021AE8: lw          $t1, 0x4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X4);
    // 0x80021AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021AF0: beql        $t1, $zero, L_80021B08
    if (ctx->r9 == 0) {
        // 0x80021AF4: lw          $t4, 0x38($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X38);
            goto L_80021B08;
    }
    goto skip_1;
    // 0x80021AF4: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    skip_1:
    // 0x80021AF8: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x80021AFC: ori         $t3, $t2, 0x700
    ctx->r11 = ctx->r10 | 0X700;
    // 0x80021B00: sw          $t3, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r11;
    // 0x80021B04: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
L_80021B08:
    // 0x80021B08: lw          $t5, 0x34($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X34);
    // 0x80021B0C: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80021B10: sw          $t4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r12;
    // 0x80021B14: jal         0x8001EA24
    // 0x80021B18: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    func_8001EA24(rdram, ctx);
        goto after_6;
    // 0x80021B18: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    after_6:
    // 0x80021B1C: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80021B20: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x80021B24: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80021B28: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x80021B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80021B30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80021B34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80021B38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021B3C: jr          $ra
    // 0x80021B40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80021B40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8049FC64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049FC64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8049FC68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8049FC6C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8049FC70: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8049FC74: lui         $t8, 0x804A
    ctx->r24 = S32(RELOC_HI16(167, 0X1298) << 16);
    // 0x8049FC78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8049FC7C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8049FC80: lw          $t8, -0x1E8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(167, 0X1298));
    // 0x8049FC84: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8049FC88: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8049FC8C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8049FC90: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8049FC94: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8049FC98: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8049FC9C: beql        $v1, $zero, L_8049FCD4
    if (ctx->r3 == 0) {
        // 0x8049FCA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8049FCD4;
    }
    goto skip_0;
    // 0x8049FCA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8049FCA4: jalr        $v1
    // 0x8049FCA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8049FCA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8049FCAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8049FCB0: lh          $t1, 0x144($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X144);
    // 0x8049FCB4: lw          $t2, 0x15C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X15C);
    // 0x8049FCB8: sw          $t1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r9;
    // 0x8049FCBC: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8049FCC0: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    // 0x8049FCC4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8049FCC8: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8049FCCC: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
    // 0x8049FCD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8049FCD4:
    // 0x8049FCD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8049FCD8: jr          $ra
    // 0x8049FCDC: nop

    return;
    // 0x8049FCDC: nop

;}
RECOMP_FUNC void func_8071545C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8071545C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80715460: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80715464: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x80715468: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x8071546C: lh          $t8, 0x5E0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X5E0);
    // 0x80715470: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x80715474: slti        $at, $a2, 0xA0
    ctx->r1 = SIGNED(ctx->r6) < 0XA0 ? 1 : 0;
    // 0x80715478: bne         $at, $zero, L_80715490
    if (ctx->r1 != 0) {
        // 0x8071547C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80715490;
    }
    // 0x8071547C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80715480: addiu       $a1, $a1, -0xA0
    ctx->r5 = ADD32(ctx->r5, -0XA0);
L_80715484:
    // 0x80715484: slti        $at, $a1, 0xA0
    ctx->r1 = SIGNED(ctx->r5) < 0XA0 ? 1 : 0;
    // 0x80715488: beql        $at, $zero, L_80715484
    if (ctx->r1 == 0) {
        // 0x8071548C: addiu       $a1, $a1, -0xA0
        ctx->r5 = ADD32(ctx->r5, -0XA0);
            goto L_80715484;
    }
    goto skip_0;
    // 0x8071548C: addiu       $a1, $a1, -0xA0
    ctx->r5 = ADD32(ctx->r5, -0XA0);
    skip_0:
L_80715490:
    // 0x80715490: lhu         $t9, 0x5FE($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X5FE);
    // 0x80715494: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80715498: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8071549C: bne         $t9, $at, L_807154A8
    if (ctx->r25 != ctx->r1) {
        // 0x807154A0: sll         $t0, $a1, 2
        ctx->r8 = S32(ctx->r5 << 2);
            goto L_807154A8;
    }
    // 0x807154A0: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x807154A4: addiu       $a3, $a2, 0xA0
    ctx->r7 = ADD32(ctx->r6, 0XA0);
L_807154A8:
    // 0x807154A8: slti        $at, $a3, 0xAA
    ctx->r1 = SIGNED(ctx->r7) < 0XAA ? 1 : 0;
    // 0x807154AC: bne         $at, $zero, L_807154B8
    if (ctx->r1 != 0) {
        // 0x807154B0: addu        $a2, $v1, $t0
        ctx->r6 = ADD32(ctx->r3, ctx->r8);
            goto L_807154B8;
    }
    // 0x807154B0: addu        $a2, $v1, $t0
    ctx->r6 = ADD32(ctx->r3, ctx->r8);
    // 0x807154B4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
L_807154B8:
    // 0x807154B8: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x807154BC: addu        $t1, $v1, $a1
    ctx->r9 = ADD32(ctx->r3, ctx->r5);
    // 0x807154C0: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x807154C4: lwc1        $f6, 0x280($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X280);
    // 0x807154C8: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x807154CC: lbu         $t2, 0x500($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X500);
    // 0x807154D0: jr          $ra
    // 0x807154D4: sb          $t2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r10;
    return;
    // 0x807154D4: sb          $t2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r10;
;}
RECOMP_FUNC void func_805DA824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA824: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DA828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA82C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x805DA830: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x805DA834: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805DA838: blez        $v0, L_805DA848
    if (SIGNED(ctx->r2) <= 0) {
        // 0x805DA83C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805DA848;
    }
    // 0x805DA83C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805DA840: b           L_805DA8C4
    // 0x805DA844: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_805DA8C4;
    // 0x805DA844: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_805DA848:
    // 0x805DA848: lw          $t7, -0x71F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71F0);
    // 0x805DA84C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x805DA850: beq         $t8, $zero, L_805DA8BC
    if (ctx->r24 == 0) {
        // 0x805DA854: nop
    
            goto L_805DA8BC;
    }
    // 0x805DA854: nop

    // 0x805DA858: jal         0x8004700C
    // 0x805DA85C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805DA85C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x805DA860: beq         $v0, $zero, L_805DA8C4
    if (ctx->r2 == 0) {
        // 0x805DA864: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_805DA8C4;
    }
    // 0x805DA864: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x805DA868: lw          $t9, 0x1F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1F4);
    // 0x805DA86C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x805DA870: lw          $t0, 0x12EC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X12EC);
    // 0x805DA874: bnel        $t0, $zero, L_805DA8C8
    if (ctx->r8 != 0) {
        // 0x805DA878: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805DA8C8;
    }
    goto skip_0;
    // 0x805DA878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805DA87C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x805DA880: jal         0x800677F8
    // 0x805DA884: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x805DA884: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x805DA888: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x805DA88C: lw          $t1, -0x71F0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X71F0);
    // 0x805DA890: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805DA894: jal         0x8002FF38
    // 0x805DA898: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_8002FF38(rdram, ctx);
        goto after_2;
    // 0x805DA898: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_2:
    // 0x805DA89C: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x805DA8A0: lw          $t3, -0x72D8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X72D8);
    // 0x805DA8A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805DA8A8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x805DA8AC: jal         0x800447C8
    // 0x805DA8B0: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x805DA8B0: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    after_3:
    // 0x805DA8B4: b           L_805DA8C8
    // 0x805DA8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805DA8C8;
    // 0x805DA8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805DA8BC:
    // 0x805DA8BC: jal         0x800447C8
    // 0x805DA8C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x805DA8C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
L_805DA8C4:
    // 0x805DA8C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805DA8C8:
    // 0x805DA8C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DA8CC: jr          $ra
    // 0x805DA8D0: nop

    return;
    // 0x805DA8D0: nop

;}
RECOMP_FUNC void func_804C1B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1B6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C1B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1B74: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C1B78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804C1B7C: jal         0x804C192C
    // 0x804C1B80: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_804C192C(rdram, ctx);
        goto after_0;
    // 0x804C1B80: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x804C1B84: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x804C1B88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804C1B8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804C1B90: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x804C1B94: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804C1B98: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x804C1B9C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x804C1BA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C1BA4: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x804C1BA8: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x804C1BAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C1BB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C1BB4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804C1BB8: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x804C1BBC: nop

    // 0x804C1BC0: bc1fl       L_804C1BD8
    if (!c1cs) {
        // 0x804C1BC4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C1BD8;
    }
    goto skip_0;
    // 0x804C1BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C1BC8: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x804C1BCC: jal         0x804C1F2C
    // 0x804C1BD0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_804C1F2C(rdram, ctx);
        goto after_1;
    // 0x804C1BD0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x804C1BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C1BD8:
    // 0x804C1BD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C1BDC: jr          $ra
    // 0x804C1BE0: nop

    return;
    // 0x804C1BE0: nop

;}
RECOMP_FUNC void func_806EF504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EF508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EF50C: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806EF510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EF514: beq         $t6, $zero, L_806EF550
    if (ctx->r14 == 0) {
        // 0x806EF518: nop
    
            goto L_806EF550;
    }
    // 0x806EF518: nop

    // 0x806EF51C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806EF520: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806EF524: jalr        $t9
    // 0x806EF528: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806EF528: nop

    after_0:
    // 0x806EF52C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EF530: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806EF534: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806EF538: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x806EF53C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x806EF540: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806EF544: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x806EF548: b           L_806EF550
    // 0x806EF54C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806EF550;
    // 0x806EF54C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806EF550:
    // 0x806EF550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EF554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EF558: jr          $ra
    // 0x806EF55C: nop

    return;
    // 0x806EF55C: nop

;}
RECOMP_FUNC void func_8040D560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040D564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040D568: jal         0x8040C758
    // 0x8040D56C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040C758(rdram, ctx);
        goto after_0;
    // 0x8040D56C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040D570: jal         0x8040D4A0
    // 0x8040D574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8040D4A0(rdram, ctx);
        goto after_1;
    // 0x8040D574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8040D578: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040D57C: jal         0x80062748
    // 0x8040D580: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_2;
    // 0x8040D580: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_2:
    // 0x8040D584: jal         0x8040D230
    // 0x8040D588: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8040D230(rdram, ctx);
        goto after_3;
    // 0x8040D588: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8040D58C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040D590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040D594: jr          $ra
    // 0x8040D598: nop

    return;
    // 0x8040D598: nop

;}
RECOMP_FUNC void func_80025B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025B50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80025B54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80025B58: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80025B5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80025B60: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80025B64: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80025B68: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80025B6C: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x80025B70: bne         $t8, $zero, L_80025B94
    if (ctx->r24 != 0) {
        // 0x80025B74: nop
    
            goto L_80025B94;
    }
    // 0x80025B74: nop

    // 0x80025B78: jal         0x8006593C
    // 0x80025B7C: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80025B7C: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    after_0:
    // 0x80025B80: sltiu       $at, $v0, 0x14
    ctx->r1 = ctx->r2 < 0X14 ? 1 : 0;
    // 0x80025B84: beq         $at, $zero, L_80025D3C
    if (ctx->r1 == 0) {
        // 0x80025B88: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80025D3C;
    }
    // 0x80025B88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80025B8C: b           L_80025D3C
    // 0x80025B90: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
        goto L_80025D3C;
    // 0x80025B90: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80025B94:
    // 0x80025B94: lh          $t9, -0x7682($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X7682);
    // 0x80025B98: beq         $t9, $zero, L_80025C6C
    if (ctx->r25 == 0) {
        // 0x80025B9C: nop
    
            goto L_80025C6C;
    }
    // 0x80025B9C: nop

    // 0x80025BA0: jal         0x80066E88
    // 0x80025BA4: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80025BA4: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    after_1:
    // 0x80025BA8: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80025BAC: lwc1        $f6, 0x100($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X100);
    // 0x80025BB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80025BB4: nop

    // 0x80025BB8: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80025BBC: jal         0x80065954
    // 0x80025BC0: nop

    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80025BC0: nop

    after_2:
    // 0x80025BC4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80025BC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80025BCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025BD0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80025BD4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80025BD8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80025BDC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80025BE0: nop

    // 0x80025BE4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80025BE8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80025BEC: nop

    // 0x80025BF0: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80025BF4: beql        $v0, $zero, L_80025C54
    if (ctx->r2 == 0) {
        // 0x80025BF8: mfc1        $v0, $f18
        ctx->r2 = (int32_t)ctx->f18.u32l;
            goto L_80025C54;
    }
    goto skip_0;
    // 0x80025BF8: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80025BFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80025C00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025C04: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80025C08: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80025C0C: nop

    // 0x80025C10: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80025C14: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80025C18: nop

    // 0x80025C1C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80025C20: bnel        $v0, $zero, L_80025C44
    if (ctx->r2 != 0) {
        // 0x80025C24: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80025C44;
    }
    goto skip_1;
    // 0x80025C24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x80025C28: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80025C2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80025C30: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80025C34: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x80025C38: b           L_80025D2C
    // 0x80025C3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80025D2C;
    // 0x80025C3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80025C40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80025C44:
    // 0x80025C44: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80025C48: b           L_80025D2C
    // 0x80025C4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80025D2C;
    // 0x80025C4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80025C50: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
L_80025C54:
    // 0x80025C54: nop

    // 0x80025C58: bltzl       $v0, L_80025C44
    if (SIGNED(ctx->r2) < 0) {
        // 0x80025C5C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80025C44;
    }
    goto skip_2;
    // 0x80025C5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_2:
    // 0x80025C60: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80025C64: b           L_80025D2C
    // 0x80025C68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80025D2C;
    // 0x80025C68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80025C6C:
    // 0x80025C6C: jal         0x80066E88
    // 0x80025C70: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x80025C70: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    after_3:
    // 0x80025C74: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80025C78: lwc1        $f6, 0x100($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X100);
    // 0x80025C7C: lwc1        $f16, 0x10C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80025C80: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80025C84: nop

    // 0x80025C88: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80025C8C: jal         0x80065954
    // 0x80025C90: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x80025C90: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_4:
    // 0x80025C94: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80025C98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80025C9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025CA0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80025CA4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80025CA8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80025CAC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80025CB0: nop

    // 0x80025CB4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80025CB8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80025CBC: nop

    // 0x80025CC0: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80025CC4: beql        $v0, $zero, L_80025D14
    if (ctx->r2 == 0) {
        // 0x80025CC8: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_80025D14;
    }
    goto skip_3;
    // 0x80025CC8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x80025CCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80025CD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025CD4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80025CD8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80025CDC: nop

    // 0x80025CE0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80025CE4: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80025CE8: nop

    // 0x80025CEC: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80025CF0: bne         $v0, $zero, L_80025D08
    if (ctx->r2 != 0) {
        // 0x80025CF4: nop
    
            goto L_80025D08;
    }
    // 0x80025CF4: nop

    // 0x80025CF8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80025CFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80025D00: b           L_80025D20
    // 0x80025D04: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80025D20;
    // 0x80025D04: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80025D08:
    // 0x80025D08: b           L_80025D20
    // 0x80025D0C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80025D20;
    // 0x80025D0C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80025D10: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_80025D14:
    // 0x80025D14: nop

    // 0x80025D18: bltz        $v0, L_80025D08
    if (SIGNED(ctx->r2) < 0) {
        // 0x80025D1C: nop
    
            goto L_80025D08;
    }
    // 0x80025D1C: nop

L_80025D20:
    // 0x80025D20: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80025D24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80025D28: nop

L_80025D2C:
    // 0x80025D2C: sltiu       $at, $v0, 0x14
    ctx->r1 = ctx->r2 < 0X14 ? 1 : 0;
    // 0x80025D30: beql        $at, $zero, L_80025D40
    if (ctx->r1 == 0) {
        // 0x80025D34: addiu       $t2, $zero, 0xA
        ctx->r10 = ADD32(0, 0XA);
            goto L_80025D40;
    }
    goto skip_4;
    // 0x80025D34: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    skip_4:
    // 0x80025D38: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80025D3C:
    // 0x80025D3C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_80025D40:
    // 0x80025D40: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80025D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80025D48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80025D4C: jal         0x80024D30
    // 0x80025D50: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80024D30(rdram, ctx);
        goto after_5;
    // 0x80025D50: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80025D54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80025D58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80025D5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80025D60: jr          $ra
    // 0x80025D64: nop

    return;
    // 0x80025D64: nop

;}
RECOMP_FUNC void func_80799878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799878: jr          $ra
    // 0x8079987C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8079987C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80735D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735D5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80735D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80735D64: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80735D68: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(736, 0X3940) << 16);
    // 0x80735D6C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80735D70: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80735D74: addiu       $t6, $t6, -0x6C60
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(736, 0X3940));
    // 0x80735D78: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80735D7C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80735D80: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80735D84: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x80735D88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80735D8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80735D90: jal         0x80735DA8
    // 0x80735D94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80735DA8(rdram, ctx);
        goto after_0;
    // 0x80735D94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80735D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80735D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80735DA0: jr          $ra
    // 0x80735DA4: nop

    return;
    // 0x80735DA4: nop

;}
RECOMP_FUNC void func_806F6714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F671C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806F6720: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x806F6724: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(688, 0X624) << 16);
    // 0x806F6728: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F672C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806F6730: lw          $t8, 0x6CC4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(688, 0X624));
    // 0x806F6734: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806F6738: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806F673C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x806F6740: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x806F6744: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806F6748: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806F674C: beql        $v1, $zero, L_806F6780
    if (ctx->r3 == 0) {
        // 0x806F6750: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F6780;
    }
    goto skip_0;
    // 0x806F6750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F6754: jalr        $v1
    // 0x806F6758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806F6758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F675C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F6760: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x806F6764: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x806F6768: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x806F676C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x806F6770: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x806F6774: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x806F6778: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x806F677C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F6780:
    // 0x806F6780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F6784: jr          $ra
    // 0x806F6788: nop

    return;
    // 0x806F6788: nop

;}
RECOMP_FUNC void func_8052795C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052795C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527964: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80527968: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X618C) << 16);
    // 0x8052796C: lwc1        $f6, -0x3F74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X618C));
    // 0x80527970: lwc1        $f2, 0x30($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80527974: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80527978: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6190) << 16);
    // 0x8052797C: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80527980: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80527984: nop

    // 0x80527988: bc1tl       L_805279F0
    if (c1cs) {
        // 0x8052798C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_805279F0;
    }
    goto skip_0;
    // 0x8052798C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80527990: lwc1        $f8, -0x3F70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6190));
    // 0x80527994: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80527998: nop

    // 0x8052799C: bc1tl       L_805279F0
    if (c1cs) {
        // 0x805279A0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_805279F0;
    }
    goto skip_1;
    // 0x805279A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x805279A4: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x805279A8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805279AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805279B0: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x805279B4: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x805279B8: bgez        $v0, L_805279D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805279BC: swc1        $f10, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
            goto L_805279D0;
    }
    // 0x805279BC: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
    // 0x805279C0: jal         0x80527424
    // 0x805279C4: nop

    func_80527424(rdram, ctx);
        goto after_0;
    // 0x805279C4: nop

    after_0:
    // 0x805279C8: b           L_80527A04
    // 0x805279CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80527A04;
    // 0x805279CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805279D0:
    // 0x805279D0: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x805279D4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x805279D8: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x805279DC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805279E0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x805279E4: b           L_80527A00
    // 0x805279E8: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80527A00;
    // 0x805279E8: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x805279EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_805279F0:
    // 0x805279F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805279F4: nop

    // 0x805279F8: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x805279FC: swc1        $f18, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f18.u32l;
L_80527A00:
    // 0x80527A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527A04:
    // 0x80527A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527A08: jr          $ra
    // 0x80527A0C: nop

    return;
    // 0x80527A0C: nop

;}
RECOMP_FUNC void func_806B2BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2BEC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2BF0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2BF4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2BF8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2BFC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2C00: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2C04: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2C08: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2C0C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2C10: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2C14: jr          $ra
    // 0x806B2C18: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2C18: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8041EDAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041EDAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8041EDB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041EDB4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8041EDB8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8041EDBC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8041EDC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041EDC4: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8041EDC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041EDCC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8041EDD0: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8041EDD4: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041EDD8: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x8041EDDC: jal         0x8041DB1C
    // 0x8041EDE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041EDE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8041EDE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EDE8: jal         0x8041E9A8
    // 0x8041EDEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E9A8(rdram, ctx);
        goto after_1;
    // 0x8041EDEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8041EDF0: beq         $v0, $zero, L_8041EF10
    if (ctx->r2 == 0) {
        // 0x8041EDF4: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8041EF10;
    }
    // 0x8041EDF4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8041EDF8: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3510) << 16);
    // 0x8041EDFC: lwc1        $f2, 0xB70($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3510));
    // 0x8041EE00: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8041EE04: lwc1        $f0, 0x40($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X40);
    // 0x8041EE08: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3514) << 16);
    // 0x8041EE0C: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8041EE10: lwc1        $f14, 0xB74($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3514));
    // 0x8041EE14: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8041EE18: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X351C) << 16);
    // 0x8041EE1C: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8041EE20: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8041EE24: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8041EE28: nop

    // 0x8041EE2C: bc1f        L_8041EED0
    if (!c1cs) {
        // 0x8041EE30: nop
    
            goto L_8041EED0;
    }
    // 0x8041EE30: nop

    // 0x8041EE34: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3518) << 16);
    // 0x8041EE38: lwc1        $f12, 0xB78($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3518));
    // 0x8041EE3C: lwc1        $f6, 0x6C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x8041EE40: swc1        $f0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f0.u32l;
    // 0x8041EE44: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8041EE48: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8041EE4C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8041EE50: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8041EE54: lwc1        $f10, 0x70($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X70);
    // 0x8041EE58: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8041EE5C: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x8041EE60: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8041EE64: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8041EE68: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8041EE6C: bc1fl       L_8041EEC4
    if (!c1cs) {
        // 0x8041EE70: swc1        $f6, 0x6C($a2)
        MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
            goto L_8041EEC4;
    }
    goto skip_0;
    // 0x8041EE70: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
    skip_0:
    // 0x8041EE74: swc1        $f2, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f2.u32l;
    // 0x8041EE78: jal         0x8004816C
    // 0x8041EE7C: swc1        $f2, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f2.u32l;
    func_8004816C(rdram, ctx);
        goto after_2;
    // 0x8041EE7C: swc1        $f2, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f2.u32l;
    after_2:
    // 0x8041EE80: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x8041EE84: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8041EE88: jal         0x80067BBC
    // 0x8041EE8C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8041EE8C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x8041EE90: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8041EE94: jal         0x80067818
    // 0x8041EE98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8041EE98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8041EE9C: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8041EEA0: sh          $t6, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r14;
    // 0x8041EEA4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8041EEA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EEAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041EEB0: jal         0x8041FE10
    // 0x8041EEB4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8041FE10(rdram, ctx);
        goto after_5;
    // 0x8041EEB4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_5:
    // 0x8041EEB8: b           L_8041EEF0
    // 0x8041EEBC: nop

        goto L_8041EEF0;
    // 0x8041EEBC: nop

    // 0x8041EEC0: swc1        $f6, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f6.u32l;
L_8041EEC4:
    // 0x8041EEC4: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8041EEC8: b           L_8041EEF0
    // 0x8041EECC: swc1        $f8, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f8.u32l;
        goto L_8041EEF0;
    // 0x8041EECC: swc1        $f8, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f8.u32l;
L_8041EED0:
    // 0x8041EED0: lwc1        $f12, 0xB7C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X351C));
    // 0x8041EED4: lwc1        $f10, 0x6C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x8041EED8: lwc1        $f18, 0x70($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X70);
    // 0x8041EEDC: swc1        $f0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f0.u32l;
    // 0x8041EEE0: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8041EEE4: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8041EEE8: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x8041EEEC: swc1        $f4, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f4.u32l;
L_8041EEF0:
    // 0x8041EEF0: jal         0x8041E5E8
    // 0x8041EEF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_6;
    // 0x8041EEF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8041EEF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EEFC: jal         0x8041E430
    // 0x8041EF00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E430(rdram, ctx);
        goto after_7;
    // 0x8041EF00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8041EF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EF08: jal         0x8041E7D4
    // 0x8041EF0C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E7D4(rdram, ctx);
        goto after_8;
    // 0x8041EF0C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
L_8041EF10:
    // 0x8041EF10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041EF14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8041EF18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8041EF1C: jr          $ra
    // 0x8041EF20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8041EF20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80531E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531E20: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80531E24: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(342, 0X6D0) << 16);
    // 0x80531E28: addiu       $t6, $t6, 0x14C0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(342, 0X6D0));
    // 0x80531E2C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80531E30: jr          $ra
    // 0x80531E34: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x80531E34: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80059BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059BE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059BEC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80059BF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059BF4: lwc1        $f0, 0xBB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XBB8);
    // 0x80059BF8: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80059BFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059C00: lw          $v0, 0xD8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XD8);
    // 0x80059C04: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80059C08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059C0C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80059C10: bc1t        L_80059C34
    if (c1cs) {
        // 0x80059C14: nop
    
            goto L_80059C34;
    }
    // 0x80059C14: nop

    // 0x80059C18: lwc1        $f4, 0xBBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XBBC);
    // 0x80059C1C: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x80059C20: nop

    // 0x80059C24: bc1t        L_80059C34
    if (c1cs) {
        // 0x80059C28: nop
    
            goto L_80059C34;
    }
    // 0x80059C28: nop

    // 0x80059C2C: b           L_80059C90
    // 0x80059C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80059C90;
    // 0x80059C30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059C34:
    // 0x80059C34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059C38: lwc1        $f6, 0xBC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XBC0);
    // 0x80059C3C: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x80059C40: nop

    // 0x80059C44: bc1fl       L_80059C68
    if (!c1cs) {
        // 0x80059C48: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_80059C68;
    }
    goto skip_0;
    // 0x80059C48: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_0:
    // 0x80059C4C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80059C50: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80059C54: jal         0x80059B78
    // 0x80059C58: lwc1        $f14, 0x40($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X40);
    func_80059B78(rdram, ctx);
        goto after_0;
    // 0x80059C58: lwc1        $f14, 0x40($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X40);
    after_0:
    // 0x80059C5C: b           L_80059C94
    // 0x80059C60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80059C94;
    // 0x80059C60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059C64: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_80059C68:
    // 0x80059C68: nop

    // 0x80059C6C: bc1fl       L_80059C90
    if (!c1cs) {
        // 0x80059C70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80059C90;
    }
    goto skip_1;
    // 0x80059C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80059C74: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80059C78: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80059C7C: jal         0x80059BB0
    // 0x80059C80: lwc1        $f14, 0x44($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X44);
    func_80059BB0(rdram, ctx);
        goto after_1;
    // 0x80059C80: lwc1        $f14, 0x44($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X44);
    after_1:
    // 0x80059C84: b           L_80059C94
    // 0x80059C88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80059C94;
    // 0x80059C88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059C90:
    // 0x80059C90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80059C94:
    // 0x80059C94: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80059C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80059C9C: jr          $ra
    // 0x80059CA0: nop

    return;
    // 0x80059CA0: nop

;}
RECOMP_FUNC void func_80050820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050828: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x8005082C: jal         0x80050720
    // 0x80050830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80050720(rdram, ctx);
        goto after_0;
    // 0x80050830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80050834: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80050838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005083C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80050840: jr          $ra
    // 0x80050844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80050844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805A5C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5C3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A5C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A5C44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805A5C48: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805A5C4C: lw          $a0, 0x264($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X264);
    // 0x805A5C50: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x805A5C54: jal         0x800443EC
    // 0x805A5C58: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800443EC(rdram, ctx);
        goto after_0;
    // 0x805A5C58: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A5C5C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x805A5C60: bne         $v0, $zero, L_805A5C70
    if (ctx->r2 != 0) {
        // 0x805A5C64: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_805A5C70;
    }
    // 0x805A5C64: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805A5C68: b           L_805A5D48
    // 0x805A5C6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A5D48;
    // 0x805A5C6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A5C70:
    // 0x805A5C70: lh          $t7, 0x13E($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X13E);
    // 0x805A5C74: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805A5C78: lwc1        $f4, 0x84($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X84);
    // 0x805A5C7C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x805A5C80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A5C84: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x805A5C88: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805A5C8C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x805A5C90: swc1        $f4, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f4.u32l;
    // 0x805A5C94: lw          $t8, 0x478($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X478);
    // 0x805A5C98: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(417, 0X1580) << 16);
    // 0x805A5C9C: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x805A5CA0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805A5CA4: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x805A5CA8: addiu       $a0, $a2, 0x84
    ctx->r4 = ADD32(ctx->r6, 0X84);
    // 0x805A5CAC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x805A5CB0: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x805A5CB4: swc1        $f4, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f4.u32l;
    // 0x805A5CB8: lwc1        $f8, 0x6840($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(417, 0X1580));
    // 0x805A5CBC: lwc1        $f6, 0x8C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8C);
    // 0x805A5CC0: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(417, 0X14F4) << 16);
    // 0x805A5CC4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x805A5CC8: nop

    // 0x805A5CCC: bc1fl       L_805A5CDC
    if (!c1cs) {
        // 0x805A5CD0: sll         $t0, $t9, 2
        ctx->r8 = S32(ctx->r25 << 2);
            goto L_805A5CDC;
    }
    goto skip_0;
    // 0x805A5CD0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    skip_0:
    // 0x805A5CD4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805A5CD8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
L_805A5CDC:
    // 0x805A5CDC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x805A5CE0: lwc1        $f10, 0x67B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(417, 0X14F4));
    // 0x805A5CE4: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x805A5CE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805A5CEC: swc1        $f10, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->f10.u32l;
    // 0x805A5CF0: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x805A5CF4: swc1        $f18, 0xC8($a2)
    MEM_W(0XC8, ctx->r6) = ctx->f18.u32l;
    // 0x805A5CF8: lw          $t1, 0x3EC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X3EC);
    // 0x805A5CFC: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x805A5D00: lbu         $t3, 0x598($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X598);
    // 0x805A5D04: bne         $t3, $at, L_805A5D28
    if (ctx->r11 != ctx->r1) {
        // 0x805A5D08: nop
    
            goto L_805A5D28;
    }
    // 0x805A5D08: nop

    // 0x805A5D0C: lhu         $t4, 0xC($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0XC);
    // 0x805A5D10: addiu       $at, $zero, 0x4509
    ctx->r1 = ADD32(0, 0X4509);
    // 0x805A5D14: bne         $t4, $at, L_805A5D28
    if (ctx->r12 != ctx->r1) {
        // 0x805A5D18: nop
    
            goto L_805A5D28;
    }
    // 0x805A5D18: nop

    // 0x805A5D1C: lw          $t6, 0x174($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X174);
    // 0x805A5D20: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805A5D24: sb          $t5, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r13;
L_805A5D28:
    // 0x805A5D28: jal         0x80047AB8
    // 0x805A5D2C: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x805A5D2C: sb          $zero, 0x165($a2)
    MEM_B(0X165, ctx->r6) = 0;
    after_1:
    // 0x805A5D30: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x805A5D34: addiu       $a0, $zero, 0x276
    ctx->r4 = ADD32(0, 0X276);
    // 0x805A5D38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A5D3C: jal         0x80067818
    // 0x805A5D40: sw          $zero, 0x264($t7)
    MEM_W(0X264, ctx->r15) = 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x805A5D40: sw          $zero, 0x264($t7)
    MEM_W(0X264, ctx->r15) = 0;
    after_2:
    // 0x805A5D44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805A5D48:
    // 0x805A5D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A5D4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A5D50: jr          $ra
    // 0x805A5D54: nop

    return;
    // 0x805A5D54: nop

;}
RECOMP_FUNC void func_8002CC3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CC3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002CC40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002CC44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002CC48: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CC4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002CC50: jal         0x8002B00C
    // 0x8002CC54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8002B00C(rdram, ctx);
        goto after_0;
    // 0x8002CC54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002CC58: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002CC5C: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002CC60: addiu       $a1, $a1, -0x39E0
    ctx->r5 = ADD32(ctx->r5, -0X39E0);
    // 0x8002CC64: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8002CC68: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x8002CC6C: addiu       $t8, $t8, 0x1778
    ctx->r24 = ADD32(ctx->r24, 0X1778);
    // 0x8002CC70: sb          $t6, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r14;
    // 0x8002CC74: sb          $t7, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r15;
    // 0x8002CC78: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x8002CC7C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002CC80: jal         0x80028118
    // 0x8002CC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028118(rdram, ctx);
        goto after_1;
    // 0x8002CC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002CC88: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002CC8C: jal         0x8002BB90
    // 0x8002CC90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002BB90(rdram, ctx);
        goto after_2;
    // 0x8002CC90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8002CC94: jal         0x8002AF54
    // 0x8002CC98: nop

    func_8002AF54(rdram, ctx);
        goto after_3;
    // 0x8002CC98: nop

    after_3:
    // 0x8002CC9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002CCA0: nop

    // 0x8002CCA4: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8002CCA8: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x8002CCAC: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8002CCB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CCB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002CCB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002CCBC: jr          $ra
    // 0x8002CCC0: nop

    return;
    // 0x8002CCC0: nop

;}
RECOMP_FUNC void func_807AE774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AE778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AE77C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807AE780: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x807AE784: blez        $v0, L_807AE7C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807AE788: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807AE7C4;
    }
    // 0x807AE788: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807AE78C: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x807AE790: mfhi        $t8
    ctx->r24 = hi;
    // 0x807AE794: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x807AE798: bne         $t8, $zero, L_807AE7F0
    if (ctx->r24 != 0) {
        // 0x807AE79C: addiu       $t9, $zero, 0x32
        ctx->r25 = ADD32(0, 0X32);
            goto L_807AE7F0;
    }
    // 0x807AE79C: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x807AE7A0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE7A4: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x807AE7A8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE7AC: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x807AE7B0: sb          $t0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r8;
    // 0x807AE7B4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807AE7B8: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x807AE7BC: b           L_807AE7F0
    // 0x807AE7C0: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
        goto L_807AE7F0;
    // 0x807AE7C0: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
L_807AE7C4:
    // 0x807AE7C4: jal         0x807ADA98
    // 0x807AE7C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807ADA98(rdram, ctx);
        goto after_0;
    // 0x807AE7C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807AE7CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AE7D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE7D4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x807AE7D8: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AE7DC: jal         0x807AEA24
    // 0x807AE7E0: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    func_807AEA24(rdram, ctx);
        goto after_1;
    // 0x807AE7E0: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    after_1:
    // 0x807AE7E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AE7E8: addiu       $t3, $zero, 0x96
    ctx->r11 = ADD32(0, 0X96);
    // 0x807AE7EC: sw          $t3, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r11;
L_807AE7F0:
    // 0x807AE7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AE7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AE7F8: jr          $ra
    // 0x807AE7FC: nop

    return;
    // 0x807AE7FC: nop

;}
RECOMP_FUNC void func_80445E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445E94: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80445E98: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80445E9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80445EA0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80445EA4: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80445EA8: sw          $t6, 0x6C9C($v1)
    MEM_W(0X6C9C, ctx->r3) = ctx->r14;
    // 0x80445EAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80445EB0: addiu       $t7, $zero, 0x3C0
    ctx->r15 = ADD32(0, 0X3C0);
    // 0x80445EB4: addiu       $t8, $zero, 0x1EF0
    ctx->r24 = ADD32(0, 0X1EF0);
    // 0x80445EB8: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x80445EBC: sw          $t8, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r24;
    // 0x80445EC0: jr          $ra
    // 0x80445EC4: swc1        $f4, 0x6AA0($v1)
    MEM_W(0X6AA0, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x80445EC4: swc1        $f4, 0x6AA0($v1)
    MEM_W(0X6AA0, ctx->r3) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_804BD6C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD6C4: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X1EFC) << 16);
    // 0x804BD6C8: addiu       $t6, $t6, -0x27D4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X1EFC));
    // 0x804BD6CC: sh          $zero, 0x30($a0)
    MEM_H(0X30, ctx->r4) = 0;
    // 0x804BD6D0: jr          $ra
    // 0x804BD6D4: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
    return;
    // 0x804BD6D4: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8078F964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F964: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078F968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078F96C: jal         0x8004700C
    // 0x8078F970: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078F970: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078F974: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8078F978: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8078F97C: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8078F980: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8078F984: jal         0x80065ABC
    // 0x8078F988: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x8078F988: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8078F98C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8078F990: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8078F994: lui         $t8, 0x8079
    ctx->r24 = S32(RELOC_HI16(814, 0XD30) << 16);
    // 0x8078F998: beq         $v1, $zero, L_8078F9D0
    if (ctx->r3 == 0) {
        // 0x8078F99C: swc1        $f0, 0xC8($a0)
        MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
            goto L_8078F9D0;
    }
    // 0x8078F99C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8078F9A0: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8078F9A4: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8078F9A8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x8078F9AC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8078F9B0: nop

    // 0x8078F9B4: bc1fl       L_8078F9C4
    if (!c1cs) {
        // 0x8078F9B8: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_8078F9C4;
    }
    goto skip_0;
    // 0x8078F9B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    skip_0:
    // 0x8078F9BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8078F9C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
L_8078F9C4:
    // 0x8078F9C4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8078F9C8: lw          $t8, -0x140($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(814, 0XD30));
    // 0x8078F9CC: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
L_8078F9D0:
    // 0x8078F9D0: jal         0x8078F6E8
    // 0x8078F9D4: nop

    func_8078F6E8(rdram, ctx);
        goto after_2;
    // 0x8078F9D4: nop

    after_2:
    // 0x8078F9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078F9DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078F9E0: jr          $ra
    // 0x8078F9E4: nop

    return;
    // 0x8078F9E4: nop

;}
