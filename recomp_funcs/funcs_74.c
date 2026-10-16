#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80424F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424F1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80424F20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80424F24: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80424F28: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80424F2C: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X3658) << 16);
    // 0x80424F30: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80424F34: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80424F38: lw          $t8, 0x6058($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X3658));
    // 0x80424F3C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80424F40: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80424F44: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80424F48: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80424F4C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80424F50: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80424F54: beql        $v1, $zero, L_80424F88
    if (ctx->r3 == 0) {
        // 0x80424F58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80424F88;
    }
    goto skip_0;
    // 0x80424F58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80424F5C: jalr        $v1
    // 0x80424F60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80424F60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80424F64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80424F68: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80424F6C: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80424F70: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80424F74: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80424F78: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80424F7C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80424F80: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80424F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80424F88:
    // 0x80424F88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80424F8C: jr          $ra
    // 0x80424F90: nop

    return;
    // 0x80424F90: nop

;}
RECOMP_FUNC void func_8052EBAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052EBAC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8052EBB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052EBB4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8052EBB8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8052EBBC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8052EBC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052EBC4: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8052EBC8: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8052EBCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052EBD0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8052EBD4: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052EBD8: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x8052EBDC: lw          $t9, 0x116C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X116C);
    // 0x8052EBE0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8052EBE4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8052EBE8: nop

    // 0x8052EBEC: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8052EBF0: bltzl       $t1, L_8052F0B8
    if (SIGNED(ctx->r9) < 0) {
        // 0x8052EBF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052F0B8;
    }
    goto skip_0;
    // 0x8052EBF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8052EBF8: lw          $t2, 0x1160($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X1160);
    // 0x8052EBFC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8052EC00: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8052EC04: beql        $at, $zero, L_8052F0B8
    if (ctx->r1 == 0) {
        // 0x8052EC08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052F0B8;
    }
    goto skip_1;
    // 0x8052EC08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8052EC0C: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8052EC10: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8052EC14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052EC18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052EC1C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8052EC20: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8052EC24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052EC28: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8052EC2C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8052EC30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052EC34: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8052EC38: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8052EC3C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8052EC40: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8052EC44: add.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x8052EC48: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8052EC4C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8052EC50: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8052EC54: nop

    // 0x8052EC58: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8052EC5C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8052EC60: nop

    // 0x8052EC64: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8052EC68: beql        $t5, $zero, L_8052ECB8
    if (ctx->r13 == 0) {
        // 0x8052EC6C: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_8052ECB8;
    }
    goto skip_2;
    // 0x8052EC6C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x8052EC70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052EC74: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8052EC78: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8052EC7C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8052EC80: nop

    // 0x8052EC84: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8052EC88: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8052EC8C: nop

    // 0x8052EC90: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x8052EC94: bne         $t5, $zero, L_8052ECAC
    if (ctx->r13 != 0) {
        // 0x8052EC98: nop
    
            goto L_8052ECAC;
    }
    // 0x8052EC98: nop

    // 0x8052EC9C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8052ECA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8052ECA4: b           L_8052ECC4
    // 0x8052ECA8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_8052ECC4;
    // 0x8052ECA8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_8052ECAC:
    // 0x8052ECAC: b           L_8052ECC4
    // 0x8052ECB0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8052ECC4;
    // 0x8052ECB0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8052ECB4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_8052ECB8:
    // 0x8052ECB8: nop

    // 0x8052ECBC: bltz        $t5, L_8052ECAC
    if (SIGNED(ctx->r13) < 0) {
        // 0x8052ECC0: nop
    
            goto L_8052ECAC;
    }
    // 0x8052ECC0: nop

L_8052ECC4:
    // 0x8052ECC4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8052ECC8: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8052ECCC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8052ECD0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8052ECD4: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8052ECD8: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8052ECDC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8052ECE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052ECE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052ECE8: addu        $a2, $t0, $t8
    ctx->r6 = ADD32(ctx->r8, ctx->r24);
    // 0x8052ECEC: lwc1        $f18, 0xF6C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XF6C);
    // 0x8052ECF0: lwc1        $f12, 0xF70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0XF70);
    // 0x8052ECF4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8052ECF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052ECFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052ED00: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8052ED04: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8052ED08: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8052ED0C: nop

    // 0x8052ED10: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8052ED14: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8052ED18: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8052ED1C: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8052ED20: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x8052ED24: bc1f        L_8052F0B4
    if (!c1cs) {
        // 0x8052ED28: nop
    
            goto L_8052F0B4;
    }
    // 0x8052ED28: nop

    // 0x8052ED2C: add.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x8052ED30: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8052ED34: lwc1        $f6, 0xF68($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XF68);
    // 0x8052ED38: lwc1        $f0, 0x115C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X115C);
    // 0x8052ED3C: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8052ED40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052ED44: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8052ED48: lw          $a1, 0x1F4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X1F4);
    // 0x8052ED4C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8052ED50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8052ED54: nop

    // 0x8052ED58: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8052ED5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8052ED60: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8052ED64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052ED68: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8052ED6C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8052ED70: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8052ED74: bc1fl       L_8052ED8C
    if (!c1cs) {
        // 0x8052ED78: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_8052ED8C;
    }
    goto skip_3;
    // 0x8052ED78: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x8052ED7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052ED80: nop

    // 0x8052ED84: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8052ED88: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
L_8052ED8C:
    // 0x8052ED8C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8052ED90: lbu         $t3, 0x30($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X30);
    // 0x8052ED94: bnel        $t3, $at, L_8052EE00
    if (ctx->r11 != ctx->r1) {
        // 0x8052ED98: lhu         $t2, 0x119E($t0)
        ctx->r10 = MEM_HU(ctx->r8, 0X119E);
            goto L_8052EE00;
    }
    goto skip_4;
    // 0x8052ED98: lhu         $t2, 0x119E($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X119E);
    skip_4:
    // 0x8052ED9C: lhu         $v1, 0x119E($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X119E);
    // 0x8052EDA0: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8052EDA4: beq         $t6, $zero, L_8052EDF0
    if (ctx->r14 == 0) {
        // 0x8052EDA8: ori         $t9, $v1, 0x1
        ctx->r25 = ctx->r3 | 0X1;
            goto L_8052EDF0;
    }
    // 0x8052EDA8: ori         $t9, $v1, 0x1
    ctx->r25 = ctx->r3 | 0X1;
    // 0x8052EDAC: lw          $a0, 0x1170($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1170);
    // 0x8052EDB0: andi        $t4, $v1, 0xFFFE
    ctx->r12 = ctx->r3 & 0XFFFE;
    // 0x8052EDB4: sltiu       $at, $a0, 0x15
    ctx->r1 = ctx->r4 < 0X15 ? 1 : 0;
    // 0x8052EDB8: bnel        $at, $zero, L_8052EDE8
    if (ctx->r1 != 0) {
        // 0x8052EDBC: addiu       $t8, $a0, 0x1
        ctx->r24 = ADD32(ctx->r4, 0X1);
            goto L_8052EDE8;
    }
    goto skip_5;
    // 0x8052EDBC: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    skip_5:
    // 0x8052EDC0: sh          $t4, 0x119E($t0)
    MEM_H(0X119E, ctx->r8) = ctx->r12;
    // 0x8052EDC4: lw          $t5, 0x34($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X34);
    // 0x8052EDC8: ori         $t7, $t5, 0x700
    ctx->r15 = ctx->r13 | 0X700;
    // 0x8052EDCC: sw          $t7, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r15;
    // 0x8052EDD0: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x8052EDD4: swc1        $f16, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f16.u32l;
    // 0x8052EDD8: swc1        $f16, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f16.u32l;
    // 0x8052EDDC: lw          $a0, 0x1170($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1170);
    // 0x8052EDE0: addiu       $v0, $v0, 0xC4
    ctx->r2 = ADD32(ctx->r2, 0XC4);
    // 0x8052EDE4: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
L_8052EDE8:
    // 0x8052EDE8: b           L_8052EE7C
    // 0x8052EDEC: sw          $t8, 0x1170($t0)
    MEM_W(0X1170, ctx->r8) = ctx->r24;
        goto L_8052EE7C;
    // 0x8052EDEC: sw          $t8, 0x1170($t0)
    MEM_W(0X1170, ctx->r8) = ctx->r24;
L_8052EDF0:
    // 0x8052EDF0: sh          $t9, 0x119E($t0)
    MEM_H(0X119E, ctx->r8) = ctx->r25;
    // 0x8052EDF4: b           L_8052EE7C
    // 0x8052EDF8: sw          $zero, 0x1170($t0)
    MEM_W(0X1170, ctx->r8) = 0;
        goto L_8052EE7C;
    // 0x8052EDF8: sw          $zero, 0x1170($t0)
    MEM_W(0X1170, ctx->r8) = 0;
    // 0x8052EDFC: lhu         $t2, 0x119E($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X119E);
L_8052EE00:
    // 0x8052EE00: sw          $zero, 0x1170($t0)
    MEM_W(0X1170, ctx->r8) = 0;
    // 0x8052EE04: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x8052EE08: sh          $t3, 0x119E($t0)
    MEM_H(0X119E, ctx->r8) = ctx->r11;
    // 0x8052EE0C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8052EE10: lwc1        $f6, 0xC8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC8);
    // 0x8052EE14: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x8052EE18: nop

    // 0x8052EE1C: bc1fl       L_8052EE60
    if (!c1cs) {
        // 0x8052EE20: lw          $v0, 0x54($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X54);
            goto L_8052EE60;
    }
    goto skip_6;
    // 0x8052EE20: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    skip_6:
    // 0x8052EE24: lw          $t4, 0x34($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X34);
    // 0x8052EE28: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X241C) << 16);
    // 0x8052EE2C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8052EE30: ori         $t5, $t4, 0x700
    ctx->r13 = ctx->r12 | 0X700;
    // 0x8052EE34: sw          $t5, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r13;
    // 0x8052EE38: lwc1        $f8, 0x1DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X241C));
    // 0x8052EE3C: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8052EE40: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2420) << 16);
    // 0x8052EE44: lwc1        $f6, 0x1E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2420));
    // 0x8052EE48: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8052EE4C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8052EE50: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8052EE54: swc1        $f10, 0x100($t7)
    MEM_W(0X100, ctx->r15) = ctx->f10.u32l;
    // 0x8052EE58: sb          $t8, 0xDF($a1)
    MEM_B(0XDF, ctx->r5) = ctx->r24;
    // 0x8052EE5C: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
L_8052EE60:
    // 0x8052EE60: lwc1        $f8, 0xC8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x8052EE64: addiu       $v0, $v0, 0xC4
    ctx->r2 = ADD32(ctx->r2, 0XC4);
    // 0x8052EE68: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8052EE6C: nop

    // 0x8052EE70: bc1fl       L_8052EE80
    if (!c1cs) {
        // 0x8052EE74: lw          $t9, 0x2C($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X2C);
            goto L_8052EE80;
    }
    goto skip_7;
    // 0x8052EE74: lw          $t9, 0x2C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2C);
    skip_7:
    // 0x8052EE78: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
L_8052EE7C:
    // 0x8052EE7C: lw          $t9, 0x2C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2C);
L_8052EE80:
    // 0x8052EE80: lw          $t3, 0x28($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X28);
    // 0x8052EE84: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8052EE88: andi        $t2, $t9, 0x3000
    ctx->r10 = ctx->r25 & 0X3000;
    // 0x8052EE8C: andi        $t6, $t3, 0x3000
    ctx->r14 = ctx->r11 & 0X3000;
    // 0x8052EE90: or          $t4, $t2, $t6
    ctx->r12 = ctx->r10 | ctx->r14;
    // 0x8052EE94: beq         $t4, $zero, L_8052EEA4
    if (ctx->r12 == 0) {
        // 0x8052EE98: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8052EEA4;
    }
    // 0x8052EE98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052EE9C: b           L_8052EEAC
    // 0x8052EEA0: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
        goto L_8052EEAC;
    // 0x8052EEA0: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
L_8052EEA4:
    // 0x8052EEA4: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8052EEA8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
L_8052EEAC:
    // 0x8052EEAC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8052EEB0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8052EEB4: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8052EEB8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8052EEBC: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8052EEC0: lwc1        $f10, 0xF6C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XF6C);
    // 0x8052EEC4: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2424) << 16);
    // 0x8052EEC8: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8052EECC: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8052EED0: blez        $t1, L_8052EF30
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8052EED4: swc1        $f8, 0xF6C($a2)
        MEM_W(0XF6C, ctx->r6) = ctx->f8.u32l;
            goto L_8052EF30;
    }
    // 0x8052EED4: swc1        $f8, 0xF6C($a2)
    MEM_W(0XF6C, ctx->r6) = ctx->f8.u32l;
    // 0x8052EED8: lwc1        $f14, 0x1E4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2424));
    // 0x8052EEDC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8052EEE0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8052EEE4: nop

    // 0x8052EEE8: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
L_8052EEEC:
    // 0x8052EEEC: addu        $v0, $t0, $t5
    ctx->r2 = ADD32(ctx->r8, ctx->r13);
    // 0x8052EEF0: lwc1        $f2, 0xF68($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XF68);
    // 0x8052EEF4: lwc1        $f4, 0xF6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XF6C);
    // 0x8052EEF8: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8052EEFC: add.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8052EF00: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8052EF04: nop

    // 0x8052EF08: bc1fl       L_8052EF28
    if (!c1cs) {
        // 0x8052EF0C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8052EF28;
    }
    goto skip_8;
    // 0x8052EF0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_8:
    // 0x8052EF10: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8052EF14: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8052EF18: sub.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8052EF1C: b           L_8052EF28
    // 0x8052EF20: swc1        $f8, 0xF68($v0)
    MEM_W(0XF68, ctx->r2) = ctx->f8.u32l;
        goto L_8052EF28;
    // 0x8052EF20: swc1        $f8, 0xF68($v0)
    MEM_W(0XF68, ctx->r2) = ctx->f8.u32l;
    // 0x8052EF24: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8052EF28:
    // 0x8052EF28: bgtzl       $v1, L_8052EEEC
    if (SIGNED(ctx->r3) > 0) {
        // 0x8052EF2C: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_8052EEEC;
    }
    goto skip_9;
    // 0x8052EF2C: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    skip_9:
L_8052EF30:
    // 0x8052EF30: lwc1        $f4, 0xF70($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XF70);
    // 0x8052EF34: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8052EF38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8052EF3C: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8052EF40: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2428) << 16);
    // 0x8052EF44: lwc1        $f14, 0x1E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2428));
    // 0x8052EF48: addiu       $v1, $t1, 0x1
    ctx->r3 = ADD32(ctx->r9, 0X1);
    // 0x8052EF4C: swc1        $f6, 0xF70($a2)
    MEM_W(0XF70, ctx->r6) = ctx->f6.u32l;
    // 0x8052EF50: lw          $a0, 0x1160($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1160);
    // 0x8052EF54: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x8052EF58: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8052EF5C: beq         $at, $zero, L_8052EFB4
    if (ctx->r1 == 0) {
        // 0x8052EF60: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8052EFB4;
    }
    // 0x8052EF60: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
L_8052EF64:
    // 0x8052EF64: addu        $v0, $t0, $t7
    ctx->r2 = ADD32(ctx->r8, ctx->r15);
    // 0x8052EF68: lwc1        $f2, 0xF70($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XF70);
    // 0x8052EF6C: lwc1        $f10, 0xF6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XF6C);
    // 0x8052EF70: sub.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8052EF74: add.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8052EF78: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8052EF7C: nop

    // 0x8052EF80: bc1fl       L_8052EFA8
    if (!c1cs) {
        // 0x8052EF84: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8052EFA8;
    }
    goto skip_10;
    // 0x8052EF84: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    skip_10:
    // 0x8052EF88: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8052EF8C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8052EF90: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8052EF94: swc1        $f6, 0xF70($v0)
    MEM_W(0XF70, ctx->r2) = ctx->f6.u32l;
    // 0x8052EF98: lw          $a0, 0x1160($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1160);
    // 0x8052EF9C: b           L_8052EFA8
    // 0x8052EFA0: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
        goto L_8052EFA8;
    // 0x8052EFA0: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x8052EFA4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8052EFA8:
    // 0x8052EFA8: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8052EFAC: bnel        $at, $zero, L_8052EF64
    if (ctx->r1 != 0) {
        // 0x8052EFB0: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8052EF64;
    }
    goto skip_11;
    // 0x8052EFB0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    skip_11:
L_8052EFB4:
    // 0x8052EFB4: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X242C) << 16);
    // 0x8052EFB8: lwc1        $f0, 0x1EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X242C));
    // 0x8052EFBC: lwc1        $f12, 0xF70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0XF70);
    // 0x8052EFC0: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2430) << 16);
    // 0x8052EFC4: lwc1        $f2, 0x1F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2430));
    // 0x8052EFC8: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8052EFCC: lwc1        $f8, 0xF6C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XF6C);
    // 0x8052EFD0: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8052EFD4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8052EFD8: swc1        $f6, 0xF6C($a2)
    MEM_W(0XF6C, ctx->r6) = ctx->f6.u32l;
    // 0x8052EFDC: lwc1        $f8, 0xF6C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XF6C);
    // 0x8052EFE0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8052EFE4: nop

    // 0x8052EFE8: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8052EFEC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8052EFF0: swc1        $f6, 0xF70($a2)
    MEM_W(0XF70, ctx->r6) = ctx->f6.u32l;
    // 0x8052EFF4: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8052EFF8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8052EFFC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8052F000: mul.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8052F004: lwc1        $f4, 0x40($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X40);
    // 0x8052F008: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8052F00C: swc1        $f6, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f6.u32l;
    // 0x8052F010: lhu         $t9, 0x119E($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X119E);
    // 0x8052F014: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8052F018: andi        $t3, $t9, 0x4
    ctx->r11 = ctx->r25 & 0X4;
    // 0x8052F01C: beq         $t3, $zero, L_8052F09C
    if (ctx->r11 == 0) {
        // 0x8052F020: addiu       $v0, $t2, 0xC4
        ctx->r2 = ADD32(ctx->r10, 0XC4);
            goto L_8052F09C;
    }
    // 0x8052F020: addiu       $v0, $t2, 0xC4
    ctx->r2 = ADD32(ctx->r10, 0XC4);
    // 0x8052F024: lwc1        $f8, 0x3C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X3C);
    // 0x8052F028: lwc1        $f10, 0x1154($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X1154);
    // 0x8052F02C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8052F030: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8052F034: jal         0x80067114
    // 0x8052F038: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x8052F038: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_0:
    // 0x8052F03C: jal         0x80066E88
    // 0x8052F040: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8052F040: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x8052F044: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8052F048: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8052F04C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8052F050: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8052F054: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8052F058: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2434) << 16);
    // 0x8052F05C: bc1f        L_8052F068
    if (!c1cs) {
        // 0x8052F060: nop
    
            goto L_8052F068;
    }
    // 0x8052F060: nop

    // 0x8052F064: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_8052F068:
    // 0x8052F068: lwc1        $f4, 0x1F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2434));
    // 0x8052F06C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2438) << 16);
    // 0x8052F070: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8052F074: nop

    // 0x8052F078: bc1fl       L_8052F088
    if (!c1cs) {
        // 0x8052F07C: lwc1        $f6, 0x3C($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
            goto L_8052F088;
    }
    goto skip_12;
    // 0x8052F07C: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    skip_12:
    // 0x8052F080: lwc1        $f2, 0x1F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2438));
    // 0x8052F084: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
L_8052F088:
    // 0x8052F088: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8052F08C: nop

    // 0x8052F090: bc1fl       L_8052F0A0
    if (!c1cs) {
        // 0x8052F094: lw          $t6, 0x54($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X54);
            goto L_8052F0A0;
    }
    goto skip_13;
    // 0x8052F094: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    skip_13:
    // 0x8052F098: swc1        $f2, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f2.u32l;
L_8052F09C:
    // 0x8052F09C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
L_8052F0A0:
    // 0x8052F0A0: lhu         $t4, 0x119E($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X119E);
    // 0x8052F0A4: lwc1        $f8, 0x3C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x8052F0A8: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x8052F0AC: sh          $t5, 0x119E($t0)
    MEM_H(0X119E, ctx->r8) = ctx->r13;
    // 0x8052F0B0: swc1        $f8, 0x1154($t0)
    MEM_W(0X1154, ctx->r8) = ctx->f8.u32l;
L_8052F0B4:
    // 0x8052F0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052F0B8:
    // 0x8052F0B8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8052F0BC: jr          $ra
    // 0x8052F0C0: nop

    return;
    // 0x8052F0C0: nop

;}
RECOMP_FUNC void func_80050720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050720: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80050724: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80050728: bnel        $t6, $zero, L_8005073C
    if (ctx->r14 != 0) {
        // 0x8005072C: lbu         $t7, 0x8($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X8);
            goto L_8005073C;
    }
    goto skip_0;
    // 0x8005072C: lbu         $t7, 0x8($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X8);
    skip_0:
    // 0x80050730: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80050734: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80050738: lbu         $t7, 0x8($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X8);
L_8005073C:
    // 0x8005073C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80050740: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80050744: jr          $ra
    // 0x80050748: sb          $t8, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r24;
    return;
    // 0x80050748: sb          $t8, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80029A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029A90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80029A94: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80029A98: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80029A9C: addiu       $a1, $a2, 0x1D0
    ctx->r5 = ADD32(ctx->r6, 0X1D0);
    // 0x80029AA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029AA4: addiu       $a2, $a2, 0x1D8
    ctx->r6 = ADD32(ctx->r6, 0X1D8);
    // 0x80029AA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80029AAC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80029AB0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80029AB4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80029AB8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80029ABC: jal         0x80029574
    // 0x80029AC0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80029574(rdram, ctx);
        goto after_0;
    // 0x80029AC0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x80029AC4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80029AC8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80029ACC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80029AD0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80029AD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029AD8: jal         0x80029774
    // 0x80029ADC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    func_80029774(rdram, ctx);
        goto after_1;
    // 0x80029ADC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80029AE0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80029AE4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80029AE8: jal         0x80029220
    // 0x80029AEC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_80029220(rdram, ctx);
        goto after_2;
    // 0x80029AEC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80029AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80029AF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80029AF8: jr          $ra
    // 0x80029AFC: nop

    return;
    // 0x80029AFC: nop

;}
RECOMP_FUNC void func_804D895C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D895C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D8960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D8964: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804D8968: lui         $t8, 0x804E
    ctx->r24 = S32(RELOC_HI16(255, 0X894) << 16);
    // 0x804D896C: addiu       $t8, $t8, -0x743C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(255, 0X894));
    // 0x804D8970: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804D8974: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804D8978: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804D897C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804D8980: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804D8984: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804D8988: beql        $v1, $zero, L_804D89C0
    if (ctx->r3 == 0) {
        // 0x804D898C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804D89C0;
    }
    goto skip_0;
    // 0x804D898C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804D8990: jalr        $v1
    // 0x804D8994: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804D8994: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804D8998: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D899C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804D89A0: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804D89A4: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804D89A8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804D89AC: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x804D89B0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804D89B4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x804D89B8: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x804D89BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D89C0:
    // 0x804D89C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D89C4: jr          $ra
    // 0x804D89C8: nop

    return;
    // 0x804D89C8: nop

;}
RECOMP_FUNC void func_80452950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452950: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452954: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452958: addiu       $t6, $zero, 0x1B
    ctx->r14 = ADD32(0, 0X1B);
    // 0x8045295C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80452960: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80452964: sw          $t6, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r14;
    // 0x80452968: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045296C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80452970: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    // 0x80452974: jr          $ra
    // 0x80452978: sw          $zero, 0xA50($v0)
    MEM_W(0XA50, ctx->r2) = 0;
    return;
    // 0x80452978: sw          $zero, 0xA50($v0)
    MEM_W(0XA50, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80527D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527D68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527D6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527D70: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80527D74: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80527D78: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80527D7C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80527D80: jal         0x80067BBC
    // 0x80527D84: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80527D84: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80527D88: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    // 0x80527D8C: jal         0x80067818
    // 0x80527D90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80527D90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80527D94: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80527D98: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X61A8) << 16);
    // 0x80527D9C: lwc1        $f4, -0x3F58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X61A8));
    // 0x80527DA0: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x80527DA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80527DA8: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(327, 0X5BB0) << 16);
    // 0x80527DAC: addiu       $v0, $v0, -0x4550
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(327, 0X5BB0));
    // 0x80527DB0: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(327, 0X1EEC) << 16);
    // 0x80527DB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80527DB8: addiu       $t7, $t7, 0x7DEC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(327, 0X1EEC));
    // 0x80527DBC: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80527DC0: sw          $t6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r14;
    // 0x80527DC4: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80527DC8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80527DCC: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x80527DD0: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80527DD4: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80527DD8: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x80527DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80527DE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527DE4: jr          $ra
    // 0x80527DE8: nop

    return;
    // 0x80527DE8: nop

;}
RECOMP_FUNC void func_804CE8AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE8AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804CE8B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CE8B4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x804CE8B8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x804CE8BC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x804CE8C0: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x804CE8C4: jr          $ra
    // 0x804CE8C8: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    return;
    // 0x804CE8C8: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_807B9504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9504: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B9508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B950C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B9510: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B9514: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807B9518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807B951C: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x807B9520: sb          $t6, 0x165($t7)
    MEM_B(0X165, ctx->r15) = ctx->r14;
    // 0x807B9524: lw          $t8, 0x40($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X40);
    // 0x807B9528: addiu       $a1, $t8, -0x10
    ctx->r5 = ADD32(ctx->r24, -0X10);
    // 0x807B952C: bgez        $a1, L_807B95B8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x807B9530: sw          $a1, 0x40($v0)
        MEM_W(0X40, ctx->r2) = ctx->r5;
            goto L_807B95B8;
    }
    // 0x807B9530: sw          $a1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r5;
    // 0x807B9534: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x807B9538: blez        $v1, L_807B9548
    if (SIGNED(ctx->r3) <= 0) {
        // 0x807B953C: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_807B9548;
    }
    // 0x807B953C: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x807B9540: b           L_807B95C8
    // 0x807B9544: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
        goto L_807B95C8;
    // 0x807B9544: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
L_807B9548:
    // 0x807B9548: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x807B954C: lui         $v1, 0x807C
    ctx->r3 = S32(RELOC_HI16(886, 0X1D24) << 16);
    // 0x807B9550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B9554: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x807B9558: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x807B955C: lw          $v1, -0x606C($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(886, 0X1D24));
    // 0x807B9560: beql        $v1, $zero, L_807B9584
    if (ctx->r3 == 0) {
        // 0x807B9564: sw          $zero, 0x40($v0)
        MEM_W(0X40, ctx->r2) = 0;
            goto L_807B9584;
    }
    goto skip_0;
    // 0x807B9564: sw          $zero, 0x40($v0)
    MEM_W(0X40, ctx->r2) = 0;
    skip_0:
    // 0x807B9568: jalr        $v1
    // 0x807B956C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x807B956C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x807B9570: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x807B9574: lw          $t3, 0x44($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X44);
    // 0x807B9578: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x807B957C: sw          $t4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r12;
    // 0x807B9580: sw          $zero, 0x40($v0)
    MEM_W(0X40, ctx->r2) = 0;
L_807B9584:
    // 0x807B9584: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x807B9588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B958C: jal         0x807B93C0
    // 0x807B9590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_807B93C0(rdram, ctx);
        goto after_1;
    // 0x807B9590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807B9594: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x807B9598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B959C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B95A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x807B95A4: jal         0x807B9E2C
    // 0x807B95A8: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    func_807B9E2C(rdram, ctx);
        goto after_2;
    // 0x807B95A8: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    after_2:
    // 0x807B95AC: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x807B95B0: b           L_807B95C8
    // 0x807B95B4: sw          $t5, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r13;
        goto L_807B95C8;
    // 0x807B95B4: sw          $t5, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r13;
L_807B95B8:
    // 0x807B95B8: jal         0x807B93C0
    // 0x807B95BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B93C0(rdram, ctx);
        goto after_3;
    // 0x807B95BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807B95C0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x807B95C4: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_807B95C8:
    // 0x807B95C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B95CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B95D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807B95D4: jr          $ra
    // 0x807B95D8: nop

    return;
    // 0x807B95D8: nop

;}
RECOMP_FUNC void func_80020FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020FFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021004: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80021008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002100C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80021010: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80021014: jal         0x80049C70
    // 0x80021018: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80049C70(rdram, ctx);
        goto after_0;
    // 0x80021018: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x8002101C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80021020: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80021024: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80021028: jal         0x80049C70
    // 0x8002102C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80049C70(rdram, ctx);
        goto after_1;
    // 0x8002102C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80021030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80021034: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80021038: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8002103C: jal         0x80049C70
    // 0x80021040: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_80049C70(rdram, ctx);
        goto after_2;
    // 0x80021040: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80021044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002104C: jr          $ra
    // 0x80021050: nop

    return;
    // 0x80021050: nop

;}
RECOMP_FUNC void func_807AF500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF500: jr          $ra
    // 0x807AF504: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807AF504: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805D7EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7EBC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805D7EC0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805D7EC4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805D7EC8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805D7ECC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805D7ED0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805D7ED4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x805D7ED8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805D7EDC: lui         $t1, 0x805E
    ctx->r9 = S32(RELOC_HI16(474, 0X250C) << 16);
    // 0x805D7EE0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805D7EE4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805D7EE8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805D7EEC: lw          $t1, -0x61F4($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(474, 0X250C));
    // 0x805D7EF0: jr          $ra
    // 0x805D7EF4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805D7EF4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8005D1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D1C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D1CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005D1D0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8005D1D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D1D8: bne         $a1, $zero, L_8005D1F8
    if (ctx->r5 != 0) {
        // 0x8005D1DC: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8005D1F8;
    }
    // 0x8005D1DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005D1E0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005D1E4: addiu       $a0, $a0, 0xCA0
    ctx->r4 = ADD32(ctx->r4, 0XCA0);
    // 0x8005D1E8: jal         0x80071380
    // 0x8005D1EC: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8005D1EC: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    after_0:
    // 0x8005D1F0: b           L_8005D28C
    // 0x8005D1F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8005D28C;
    // 0x8005D1F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8005D1F8:
    // 0x8005D1F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D1FC: bne         $s0, $at, L_8005D218
    if (ctx->r16 != ctx->r1) {
        // 0x8005D200: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8005D218;
    }
    // 0x8005D200: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005D204: addiu       $a0, $a0, 0xCB0
    ctx->r4 = ADD32(ctx->r4, 0XCB0);
    // 0x8005D208: jal         0x80071380
    // 0x8005D20C: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8005D20C: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    after_1:
    // 0x8005D210: b           L_8005D28C
    // 0x8005D214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8005D28C;
    // 0x8005D214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8005D218:
    // 0x8005D218: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x8005D21C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005D220: addiu       $a0, $a0, 0xCC0
    ctx->r4 = ADD32(ctx->r4, 0XCC0);
    // 0x8005D224: beq         $t6, $zero, L_8005D23C
    if (ctx->r14 == 0) {
        // 0x8005D228: nop
    
            goto L_8005D23C;
    }
    // 0x8005D228: nop

    // 0x8005D22C: jal         0x80071380
    // 0x8005D230: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8005D230: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_2:
    // 0x8005D234: b           L_8005D28C
    // 0x8005D238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8005D28C;
    // 0x8005D238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8005D23C:
    // 0x8005D23C: jal         0x8004627C
    // 0x8005D240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004627C(rdram, ctx);
        goto after_3;
    // 0x8005D240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8005D244: lh          $t7, 0x17E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X17E);
    // 0x8005D248: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x8005D24C: beql        $t7, $at, L_8005D260
    if (ctx->r15 == ctx->r1) {
        // 0x8005D250: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8005D260;
    }
    goto skip_0;
    // 0x8005D250: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x8005D254: jal         0x8004457C
    // 0x8005D258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004457C(rdram, ctx);
        goto after_4;
    // 0x8005D258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8005D25C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8005D260:
    // 0x8005D260: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005D264: jal         0x80043D34
    // 0x8005D268: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80043D34(rdram, ctx);
        goto after_5;
    // 0x8005D268: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_5:
    // 0x8005D26C: lhu         $t8, 0xC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XC);
    // 0x8005D270: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8005D274: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8005D278: bne         $t8, $at, L_8005D288
    if (ctx->r24 != ctx->r1) {
        // 0x8005D27C: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_8005D288;
    }
    // 0x8005D27C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8005D280: lw          $t0, -0x7890($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7890);
    // 0x8005D284: sw          $t9, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->r25;
L_8005D288:
    // 0x8005D288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8005D28C:
    // 0x8005D28C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D294: jr          $ra
    // 0x8005D298: nop

    return;
    // 0x8005D298: nop

;}
RECOMP_FUNC void func_8040AD0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040AD0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040AD10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040AD14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8040AD18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8040AD1C: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8040AD20: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8040AD24: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x8040AD28: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8040AD2C: nop

    // 0x8040AD30: bc1fl       L_8040AD5C
    if (!c1cs) {
        // 0x8040AD34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040AD5C;
    }
    goto skip_0;
    // 0x8040AD34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040AD38: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8040AD3C: jal         0x8004D1F0
    // 0x8040AD40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x8040AD40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040AD44: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8040AD48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040AD4C: addiu       $a2, $a2, -0x2B90
    ctx->r6 = ADD32(ctx->r6, -0X2B90);
    // 0x8040AD50: jal         0x8004D698
    // 0x8040AD54: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x8040AD54: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8040AD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040AD5C:
    // 0x8040AD5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040AD60: jr          $ra
    // 0x8040AD64: nop

    return;
    // 0x8040AD64: nop

;}
RECOMP_FUNC void func_8079DA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079DA00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079DA04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079DA08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8079DA0C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8079DA10: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8079DA14: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8079DA18: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8079DA1C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8079DA20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079DA24: jal         0x8079DA3C
    // 0x8079DA28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8079DA3C(rdram, ctx);
        goto after_0;
    // 0x8079DA28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8079DA2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079DA30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079DA34: jr          $ra
    // 0x8079DA38: nop

    return;
    // 0x8079DA38: nop

;}
RECOMP_FUNC void func_80471A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471A5C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80471A60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80471A64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80471A68: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80471A6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80471A70: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80471A74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80471A78: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80471A7C: jal         0x80471B6C
    // 0x80471A80: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    func_80471B6C(rdram, ctx);
        goto after_0;
    // 0x80471A80: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    after_0:
    // 0x80471A84: beq         $v0, $zero, L_80471B50
    if (ctx->r2 == 0) {
        // 0x80471A88: nop
    
            goto L_80471B50;
    }
    // 0x80471A88: nop

    // 0x80471A8C: jal         0x80471BA4
    // 0x80471A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80471BA4(rdram, ctx);
        goto after_1;
    // 0x80471A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80471A94: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80471A98: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80471A9C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80471AA0: lui         $t7, 0x8047
    ctx->r15 = S32(RELOC_HI16(158, 0X1A9C) << 16);
    // 0x80471AA4: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80471AA8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80471AAC: addiu       $t7, $t7, 0x2F5C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(158, 0X1A9C));
    // 0x80471AB0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80471AB4: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x80471AB8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80471ABC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80471AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80471AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80471AC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80471ACC: jal         0x80471D38
    // 0x80471AD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80471D38(rdram, ctx);
        goto after_2;
    // 0x80471AD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80471AD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80471AD8: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80471ADC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80471AE0: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80471AE4: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x80471AE8: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    // 0x80471AEC: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x80471AF0: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x80471AF4: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x80471AF8: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80471AFC: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(158, 0X1AE4) << 16);
    // 0x80471B00: lwc1        $f16, 0x2FA4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(158, 0X1AE4));
    // 0x80471B04: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80471B08: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    // 0x80471B0C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80471B10: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80471B14: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x80471B18: jal         0x80472DA0
    // 0x80471B1C: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    func_80472DA0(rdram, ctx);
        goto after_3;
    // 0x80471B1C: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80471B20: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80471B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80471B28: beq         $v0, $zero, L_80471B40
    if (ctx->r2 == 0) {
        // 0x80471B2C: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80471B40;
    }
    // 0x80471B2C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80471B30: jal         0x80047F9C
    // 0x80471B34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x80471B34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80471B38: b           L_80471B5C
    // 0x80471B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80471B5C;
    // 0x80471B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80471B40:
    // 0x80471B40: jal         0x800445A4
    // 0x80471B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x80471B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80471B48: b           L_80471B5C
    // 0x80471B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80471B5C;
    // 0x80471B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80471B50:
    // 0x80471B50: jal         0x800445A4
    // 0x80471B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x80471B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80471B58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80471B5C:
    // 0x80471B5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80471B60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80471B64: jr          $ra
    // 0x80471B68: nop

    return;
    // 0x80471B68: nop

;}
RECOMP_FUNC void func_800787F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800787F0: jr          $ra
    // 0x800787F4: nop

    return;
    // 0x800787F4: nop

;}
RECOMP_FUNC void func_80068CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068CD4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068CD8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068CDC: lui         $t6, 0x8007
    ctx->r14 = S32(0X8007 << 16);
    // 0x80068CE0: addiu       $t6, $t6, -0x738C
    ctx->r14 = ADD32(ctx->r14, -0X738C);
    // 0x80068CE4: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x80068CE8: sw          $a0, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r4;
    // 0x80068CEC: sw          $a1, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->r5;
    // 0x80068CF0: jr          $ra
    // 0x80068CF4: sw          $a2, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->r6;
    return;
    // 0x80068CF4: sw          $a2, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_80409908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409908: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8040990C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80409910: jr          $ra
    // 0x80409914: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x80409914: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void func_80025398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025398: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8002539C: lh          $t6, -0x7682($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7682);
    // 0x800253A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800253A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800253A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800253AC: beq         $t6, $zero, L_80025478
    if (ctx->r14 == 0) {
        // 0x800253B0: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80025478;
    }
    // 0x800253B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800253B4: jal         0x80066E88
    // 0x800253B8: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x800253B8: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    after_0:
    // 0x800253BC: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800253C0: lwc1        $f6, 0x100($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X100);
    // 0x800253C4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800253C8: nop

    // 0x800253CC: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800253D0: jal         0x80065954
    // 0x800253D4: nop

    func_80065954(rdram, ctx);
        goto after_1;
    // 0x800253D4: nop

    after_1:
    // 0x800253D8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800253DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800253E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800253E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800253E8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800253EC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800253F0: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800253F4: nop

    // 0x800253F8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800253FC: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80025400: nop

    // 0x80025404: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80025408: beql        $a1, $zero, L_80025460
    if (ctx->r5 == 0) {
        // 0x8002540C: mfc1        $a1, $f18
        ctx->r5 = (int32_t)ctx->f18.u32l;
            goto L_80025460;
    }
    goto skip_0;
    // 0x8002540C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80025410: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80025414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80025418: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002541C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80025420: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80025424: nop

    // 0x80025428: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8002542C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80025430: nop

    // 0x80025434: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80025438: bnel        $a1, $zero, L_80025454
    if (ctx->r5 != 0) {
        // 0x8002543C: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_80025454;
    }
    goto skip_1;
    // 0x8002543C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_1:
    // 0x80025440: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80025444: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80025448: b           L_80025538
    // 0x8002544C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_80025538;
    // 0x8002544C: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    // 0x80025450: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
L_80025454:
    // 0x80025454: b           L_80025538
    // 0x80025458: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80025538;
    // 0x80025458: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8002545C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
L_80025460:
    // 0x80025460: nop

    // 0x80025464: bltzl       $a1, L_80025454
    if (SIGNED(ctx->r5) < 0) {
        // 0x80025468: ctc1        $t7, $FpcCsr
        set_cop1_cs(ctx->r15);
            goto L_80025454;
    }
    goto skip_2;
    // 0x80025468: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    skip_2:
    // 0x8002546C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80025470: b           L_8002553C
    // 0x80025474: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
        goto L_8002553C;
    // 0x80025474: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
L_80025478:
    // 0x80025478: jal         0x80066E88
    // 0x8002547C: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8002547C: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    after_2:
    // 0x80025480: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80025484: lwc1        $f6, 0x100($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X100);
    // 0x80025488: lwc1        $f16, 0x10C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x8002548C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80025490: nop

    // 0x80025494: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80025498: jal         0x80065954
    // 0x8002549C: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8002549C: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_3:
    // 0x800254A0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800254A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800254A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800254AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800254B0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800254B4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800254B8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800254BC: nop

    // 0x800254C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800254C4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800254C8: nop

    // 0x800254CC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800254D0: beql        $a1, $zero, L_80025520
    if (ctx->r5 == 0) {
        // 0x800254D4: mfc1        $a1, $f6
        ctx->r5 = (int32_t)ctx->f6.u32l;
            goto L_80025520;
    }
    goto skip_3;
    // 0x800254D4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800254D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800254DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800254E0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800254E4: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800254E8: nop

    // 0x800254EC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800254F0: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800254F4: nop

    // 0x800254F8: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800254FC: bne         $a1, $zero, L_80025514
    if (ctx->r5 != 0) {
        // 0x80025500: nop
    
            goto L_80025514;
    }
    // 0x80025500: nop

    // 0x80025504: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80025508: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002550C: b           L_8002552C
    // 0x80025510: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_8002552C;
    // 0x80025510: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_80025514:
    // 0x80025514: b           L_8002552C
    // 0x80025518: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8002552C;
    // 0x80025518: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8002551C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
L_80025520:
    // 0x80025520: nop

    // 0x80025524: bltz        $a1, L_80025514
    if (SIGNED(ctx->r5) < 0) {
        // 0x80025528: nop
    
            goto L_80025514;
    }
    // 0x80025528: nop

L_8002552C:
    // 0x8002552C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80025530: nop

    // 0x80025534: nop

L_80025538:
    // 0x80025538: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
L_8002553C:
    // 0x8002553C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80025540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80025544: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80025548: jal         0x80024D30
    // 0x8002554C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80024D30(rdram, ctx);
        goto after_4;
    // 0x8002554C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_4:
    // 0x80025550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80025554: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80025558: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002555C: jr          $ra
    // 0x80025560: nop

    return;
    // 0x80025560: nop

;}
RECOMP_FUNC void func_80672FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672FE0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80672FE4: addiu       $t7, $t6, -0x455D
    ctx->r15 = ADD32(ctx->r14, -0X455D);
    // 0x80672FE8: sltiu       $at, $t7, 0x1B
    ctx->r1 = ctx->r15 < 0X1B ? 1 : 0;
    // 0x80672FEC: beq         $at, $zero, L_80673020
    if (ctx->r1 == 0) {
        // 0x80672FF0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80673020;
    }
    // 0x80672FF0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80672FF4: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1BB0) << 16);
    // 0x80672FF8: addu        $at, $at, $t7
    gpr jr_addend_80673000 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80672FFC: lw          $t7, 0x4B90($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(529, 0X1BB0));
    // 0x80673000: jr          $t7
    // 0x80673004: nop

    switch (jr_addend_80673000 >> 2) {
        case 0: goto L_80673008; break;
        case 1: goto L_80673020; break;
        case 2: goto L_80673020; break;
        case 3: goto L_80673020; break;
        case 4: goto L_80673020; break;
        case 5: goto L_80673020; break;
        case 6: goto L_80673020; break;
        case 7: goto L_80673020; break;
        case 8: goto L_80673020; break;
        case 9: goto L_80673020; break;
        case 10: goto L_80673008; break;
        case 11: goto L_80673014; break;
        case 12: goto L_80673020; break;
        case 13: goto L_80673020; break;
        case 14: goto L_80673020; break;
        case 15: goto L_80673020; break;
        case 16: goto L_80673020; break;
        case 17: goto L_80673020; break;
        case 18: goto L_80673020; break;
        case 19: goto L_80673020; break;
        case 20: goto L_80673020; break;
        case 21: goto L_80673020; break;
        case 22: goto L_80673020; break;
        case 23: goto L_80673020; break;
        case 24: goto L_80673020; break;
        case 25: goto L_80673008; break;
        case 26: goto L_80673008; break;
        default: switch_error(__func__, 0x80673000, 0x80674B90);
    }
    // 0x80673004: nop

L_80673008:
    // 0x80673008: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(529, 0XE14) << 16);
    // 0x8067300C: jr          $ra
    // 0x80673010: addiu       $v0, $v0, 0x3DF4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(529, 0XE14));
    return;
    // 0x80673010: addiu       $v0, $v0, 0x3DF4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(529, 0XE14));
L_80673014:
    // 0x80673014: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(529, 0X1894) << 16);
    // 0x80673018: jr          $ra
    // 0x8067301C: addiu       $v0, $v0, 0x4874
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(529, 0X1894));
    return;
    // 0x8067301C: addiu       $v0, $v0, 0x4874
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(529, 0X1894));
L_80673020:
    // 0x80673020: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80673024: jr          $ra
    // 0x80673028: nop

    return;
    // 0x80673028: nop

;}
RECOMP_FUNC void func_806D2E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D2E50: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(613, 0X34) << 16);
    // 0x806D2E54: addiu       $v0, $v0, 0x2E84
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(613, 0X34));
    // 0x806D2E58: jr          $ra
    // 0x806D2E5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806D2E5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80421AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421AB4: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(32, 0X1730) << 16);
    // 0x80421AB8: addiu       $t6, $t6, 0x27F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(32, 0X1730));
    // 0x80421ABC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80421AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80421AC4: addiu       $v1, $sp, 0xC
    ctx->r3 = ADD32(ctx->r29, 0XC);
    // 0x80421AC8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80421ACC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80421AD0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80421AD4: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(32, 0X176C) << 16);
    // 0x80421AD8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80421ADC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80421AE0: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80421AE4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80421AE8: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80421AEC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80421AF0: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80421AF4: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80421AF8: mul.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80421AFC: beq         $v0, $zero, L_80421BF8
    if (ctx->r2 == 0) {
        // 0x80421B00: nop
    
            goto L_80421BF8;
    }
    // 0x80421B00: nop

    // 0x80421B04: lwc1        $f12, 0x282C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(32, 0X176C));
    // 0x80421B08: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80421B0C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80421B10: nop

    // 0x80421B14: bc1tl       L_80421B58
    if (c1cs) {
        // 0x80421B18: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80421B58;
    }
    goto skip_0;
    // 0x80421B18: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x80421B1C: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80421B20: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80421B24: nop

    // 0x80421B28: bc1tl       L_80421B58
    if (c1cs) {
        // 0x80421B2C: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80421B58;
    }
    goto skip_1;
    // 0x80421B2C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x80421B30: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x80421B34: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80421B38: sltiu       $at, $v0, 0x2
    ctx->r1 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80421B3C: beq         $at, $zero, L_80421B4C
    if (ctx->r1 == 0) {
        // 0x80421B40: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_80421B4C;
    }
    // 0x80421B40: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80421B44: b           L_80421BF8
    // 0x80421B48: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_80421BF8;
    // 0x80421B48: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_80421B4C:
    // 0x80421B4C: b           L_80421BF8
    // 0x80421B50: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_80421BF8;
    // 0x80421B50: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80421B54: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80421B58:
    // 0x80421B58: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(32, 0X1770) << 16);
    // 0x80421B5C: bc1fl       L_80421BAC
    if (!c1cs) {
        // 0x80421B60: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80421BAC;
    }
    goto skip_2;
    // 0x80421B60: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_2:
    // 0x80421B64: lwc1        $f10, 0x2830($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(32, 0X1770));
    // 0x80421B68: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80421B6C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80421B70: nop

    // 0x80421B74: bc1fl       L_80421B88
    if (!c1cs) {
        // 0x80421B78: swc1        $f0, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
            goto L_80421B88;
    }
    goto skip_3;
    // 0x80421B78: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    skip_3:
    // 0x80421B7C: b           L_80421BF8
    // 0x80421B80: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
        goto L_80421BF8;
    // 0x80421B80: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x80421B84: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
L_80421B88:
    // 0x80421B88: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80421B8C: sltiu       $at, $v0, 0x2
    ctx->r1 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80421B90: beq         $at, $zero, L_80421BA0
    if (ctx->r1 == 0) {
        // 0x80421B94: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80421BA0;
    }
    // 0x80421B94: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80421B98: b           L_80421BF8
    // 0x80421B9C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
        goto L_80421BF8;
    // 0x80421B9C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_80421BA0:
    // 0x80421BA0: b           L_80421BF8
    // 0x80421BA4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_80421BF8;
    // 0x80421BA4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80421BA8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80421BAC:
    // 0x80421BAC: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(32, 0X1774) << 16);
    // 0x80421BB0: bc1f        L_80421BF8
    if (!c1cs) {
        // 0x80421BB4: nop
    
            goto L_80421BF8;
    }
    // 0x80421BB4: nop

    // 0x80421BB8: lwc1        $f16, 0x2834($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(32, 0X1774));
    // 0x80421BBC: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80421BC0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80421BC4: nop

    // 0x80421BC8: bc1fl       L_80421BDC
    if (!c1cs) {
        // 0x80421BCC: swc1        $f0, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
            goto L_80421BDC;
    }
    goto skip_4;
    // 0x80421BCC: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    skip_4:
    // 0x80421BD0: b           L_80421BF8
    // 0x80421BD4: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
        goto L_80421BF8;
    // 0x80421BD4: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x80421BD8: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
L_80421BDC:
    // 0x80421BDC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80421BE0: sltiu       $at, $v0, 0x2
    ctx->r1 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80421BE4: beq         $at, $zero, L_80421BF4
    if (ctx->r1 == 0) {
        // 0x80421BE8: addiu       $t3, $v0, 0x1
        ctx->r11 = ADD32(ctx->r2, 0X1);
            goto L_80421BF4;
    }
    // 0x80421BE8: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x80421BEC: b           L_80421BF8
    // 0x80421BF0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
        goto L_80421BF8;
    // 0x80421BF0: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_80421BF4:
    // 0x80421BF4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80421BF8:
    // 0x80421BF8: jr          $ra
    // 0x80421BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80421BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_807B4800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B4804: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807B4808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B480C: lui         $a0, 0x807B
    ctx->r4 = S32(RELOC_HI16(880, 0X31B0) << 16);
    // 0x807B4810: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(880, 0X31C0) << 16);
    // 0x807B4814: addiu       $a1, $a1, 0x79C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(880, 0X31C0));
    // 0x807B4818: addiu       $a0, $a0, 0x79B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(880, 0X31B0));
    // 0x807B481C: jal         0x8004667C
    // 0x807B4820: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x807B4820: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x807B4824: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x807B4828: lui         $a2, 0x807B
    ctx->r6 = S32(RELOC_HI16(880, 0X2BD4) << 16);
    // 0x807B482C: addiu       $a2, $a2, 0x73D4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(880, 0X2BD4));
    // 0x807B4830: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x807B4834: jal         0x80057B28
    // 0x807B4838: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x807B4838: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_1:
    // 0x807B483C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B4840: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(880, 0X1F78) << 16);
    // 0x807B4844: addiu       $v0, $v0, 0x6778
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(880, 0X1F78));
    // 0x807B4848: jr          $ra
    // 0x807B484C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x807B484C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8003BD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BD18: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8003BD1C: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x8003BD20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BD24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BD28: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x8003BD2C: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x8003BD30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003BD34: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x8003BD38: bne         $t8, $at, L_8003BD50
    if (ctx->r24 != ctx->r1) {
        // 0x8003BD3C: nop
    
            goto L_8003BD50;
    }
    // 0x8003BD3C: nop

    // 0x8003BD40: jal         0x80040C48
    // 0x8003BD44: nop

    func_80040C48(rdram, ctx);
        goto after_0;
    // 0x8003BD44: nop

    after_0:
    // 0x8003BD48: b           L_8003BD50
    // 0x8003BD4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003BD50;
    // 0x8003BD4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003BD50:
    // 0x8003BD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BD54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003BD58: jr          $ra
    // 0x8003BD5C: nop

    return;
    // 0x8003BD5C: nop

;}
RECOMP_FUNC void func_805DA948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DA94C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA950: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805DA954: jal         0x80045A34
    // 0x805DA958: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805DA958: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x805DA95C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805DA960: bne         $v0, $zero, L_805DA970
    if (ctx->r2 != 0) {
        // 0x805DA964: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_805DA970;
    }
    // 0x805DA964: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x805DA968: b           L_805DA97C
    // 0x805DA96C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805DA97C;
    // 0x805DA96C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805DA970:
    // 0x805DA970: jal         0x805DA920
    // 0x805DA974: nop

    func_805DA920(rdram, ctx);
        goto after_1;
    // 0x805DA974: nop

    after_1:
    // 0x805DA978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805DA97C:
    // 0x805DA97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DA980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DA984: jr          $ra
    // 0x805DA988: nop

    return;
    // 0x805DA988: nop

;}
RECOMP_FUNC void func_8079AE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079AE38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079AE3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079AE40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079AE44: jal         0x8079ADA0
    // 0x8079AE48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8079ADA0(rdram, ctx);
        goto after_0;
    // 0x8079AE48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8079AE4C: bne         $v0, $zero, L_8079AE64
    if (ctx->r2 != 0) {
        // 0x8079AE50: nop
    
            goto L_8079AE64;
    }
    // 0x8079AE50: nop

    // 0x8079AE54: jal         0x800445A4
    // 0x8079AE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8079AE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8079AE5C: b           L_8079AECC
    // 0x8079AE60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8079AECC;
    // 0x8079AE60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079AE64:
    // 0x8079AE64: jal         0x8079ADE4
    // 0x8079AE68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079ADE4(rdram, ctx);
        goto after_2;
    // 0x8079AE68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8079AE6C: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(826, 0X22F0) << 16);
    // 0x8079AE70: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8079AE74: addiu       $t7, $t7, -0x51F0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(826, 0X22F0));
    // 0x8079AE78: sh          $t6, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r14;
    // 0x8079AE7C: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x8079AE80: jal         0x8079AC9C
    // 0x8079AE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079AC9C(rdram, ctx);
        goto after_3;
    // 0x8079AE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8079AE88: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x8079AE8C: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x8079AE90: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x8079AE94: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(826, 0X2460) << 16);
    // 0x8079AE98: sw          $t8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r24;
    // 0x8079AE9C: addiu       $t9, $t9, -0x5080
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(826, 0X2460));
    // 0x8079AEA0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8079AEA4: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8079AEA8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8079AEAC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8079AEB0: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x8079AEB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079AEB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079AEBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8079AEC0: jal         0x8079AEDC
    // 0x8079AEC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079AEDC(rdram, ctx);
        goto after_4;
    // 0x8079AEC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8079AEC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079AECC:
    // 0x8079AECC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079AED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079AED4: jr          $ra
    // 0x8079AED8: nop

    return;
    // 0x8079AED8: nop

;}
RECOMP_FUNC void func_807C2CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C2CE0: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(901, 0X124) << 16);
    // 0x807C2CE4: addiu       $t6, $t6, 0x2E04
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(901, 0X124));
    // 0x807C2CE8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807C2CEC: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(901, 0X70) << 16);
    // 0x807C2CF0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x807C2CF4: sw          $t6, -0x7254($at)
    MEM_W(-0X7254, ctx->r1) = ctx->r14;
    // 0x807C2CF8: jr          $ra
    // 0x807C2CFC: addiu       $v0, $v0, 0x2D50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(901, 0X70));
    return;
    // 0x807C2CFC: addiu       $v0, $v0, 0x2D50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(901, 0X70));
;}
RECOMP_FUNC void func_80051EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051EE4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80051EE8: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80051EEC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80051EF0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80051EF4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80051EF8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80051EFC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80051F00: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80051F04: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80051F08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80051F0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80051F10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051F14: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80051F18: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x80051F1C: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80051F20: lw          $s4, 0x8($a1)
    ctx->r20 = MEM_W(ctx->r5, 0X8);
    // 0x80051F24: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80051F28: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
    // 0x80051F2C: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80051F30: sll         $v0, $a2, 7
    ctx->r2 = S32(ctx->r6 << 7);
    // 0x80051F34: lui         $s5, 0x8006
    ctx->r21 = S32(0X8006 << 16);
    // 0x80051F38: addiu       $t8, $a0, 0x1C
    ctx->r24 = ADD32(ctx->r4, 0X1C);
    // 0x80051F3C: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80051F40: addiu       $s5, $s5, 0x758C
    ctx->r21 = ADD32(ctx->r21, 0X758C);
    // 0x80051F44: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80051F48: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80051F4C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80051F50: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80051F54: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_80051F58:
    // 0x80051F58: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x80051F5C: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80051F60: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80051F64: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80051F68: addu        $s4, $s4, $v0
    ctx->r20 = ADD32(ctx->r20, ctx->r2);
    // 0x80051F6C: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x80051F70: addu        $s3, $t9, $s6
    ctx->r19 = ADD32(ctx->r25, ctx->r22);
    // 0x80051F74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80051F78: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80051F7C: jal         0x800675D0
    // 0x80051F80: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x80051F80: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_0:
    // 0x80051F84: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80051F88: addiu       $a0, $s3, 0x400
    ctx->r4 = ADD32(ctx->r19, 0X400);
    // 0x80051F8C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    // 0x80051F90: sw          $t0, 0x14($s7)
    MEM_W(0X14, ctx->r23) = ctx->r8;
    // 0x80051F94: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80051F98: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80051F9C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80051FA0: jal         0x800675D0
    // 0x80051FA4: lw          $a1, 0x28($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X28);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x80051FA4: lw          $a1, 0x28($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X28);
    after_1:
    // 0x80051FA8: lbu         $t3, 0x4($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X4);
    // 0x80051FAC: addiu       $s0, $s4, 0x8
    ctx->r16 = ADD32(ctx->r20, 0X8);
    // 0x80051FB0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80051FB4: blezl       $t3, L_8005200C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80051FB8: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8005200C;
    }
    goto skip_0;
    // 0x80051FB8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    skip_0:
L_80051FBC:
    // 0x80051FBC: jal         0x80051EC8
    // 0x80051FC0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_80051EC8(rdram, ctx);
        goto after_2;
    // 0x80051FC0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_2:
    // 0x80051FC4: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x80051FC8: addu        $a0, $v0, $s3
    ctx->r4 = ADD32(ctx->r2, ctx->r19);
    // 0x80051FCC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80051FD0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80051FD4: srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
    // 0x80051FD8: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x80051FDC: jal         0x800675D0
    // 0x80051FE0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_800675D0(rdram, ctx);
        goto after_3;
    // 0x80051FE0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_3:
    // 0x80051FE4: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80051FE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80051FEC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80051FF0: sw          $t4, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r12;
    // 0x80051FF4: lbu         $t5, 0x4($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X4);
    // 0x80051FF8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80051FFC: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80052000: bne         $at, $zero, L_80051FBC
    if (ctx->r1 != 0) {
        // 0x80052004: nop
    
            goto L_80051FBC;
    }
    // 0x80052004: nop

    // 0x80052008: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8005200C:
    // 0x8005200C: ori         $at, $zero, 0xF600
    ctx->r1 = 0 | 0XF600;
    // 0x80052010: addu        $s6, $s6, $at
    ctx->r22 = ADD32(ctx->r22, ctx->r1);
    // 0x80052014: addiu       $at, $zero, 0x3C0
    ctx->r1 = ADD32(0, 0X3C0);
    // 0x80052018: addiu       $fp, $fp, 0x1E0
    ctx->r30 = ADD32(ctx->r30, 0X1E0);
    // 0x8005201C: addiu       $t7, $t6, 0x1E0
    ctx->r15 = ADD32(ctx->r14, 0X1E0);
    // 0x80052020: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80052024: bne         $fp, $at, L_80051F58
    if (ctx->r30 != ctx->r1) {
        // 0x80052028: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_80051F58;
    }
    // 0x80052028: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8005202C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80052030: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052034: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80052038: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005203C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80052040: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80052044: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80052048: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8005204C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80052050: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80052054: jr          $ra
    // 0x80052058: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80052058: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80788424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80788424: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80788428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078842C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80788430: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80788434: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80788438: jal         0x80787414
    // 0x8078843C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_80787414(rdram, ctx);
        goto after_0;
    // 0x8078843C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80788440: jal         0x80787598
    // 0x80788444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80787598(rdram, ctx);
        goto after_1;
    // 0x80788444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80788448: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8078844C: lhu         $t8, 0x52F0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X52F0);
    // 0x80788450: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80788454: beq         $t9, $zero, L_8078846C
    if (ctx->r25 == 0) {
        // 0x80788458: nop
    
            goto L_8078846C;
    }
    // 0x80788458: nop

    // 0x8078845C: jal         0x80787D9C
    // 0x80788460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80787D9C(rdram, ctx);
        goto after_2;
    // 0x80788460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80788464: b           L_80788478
    // 0x80788468: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
        goto L_80788478;
    // 0x80788468: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_8078846C:
    // 0x8078846C: jal         0x80787EA4
    // 0x80788470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80787EA4(rdram, ctx);
        goto after_3;
    // 0x80788470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80788474: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_80788478:
    // 0x80788478: blezl       $v0, L_80788490
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8078847C: lw          $v0, 0x52E0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X52E0);
            goto L_80788490;
    }
    goto skip_0;
    // 0x8078847C: lw          $v0, 0x52E0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X52E0);
    skip_0:
    // 0x80788480: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80788484: b           L_807885B4
    // 0x80788488: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
        goto L_807885B4;
    // 0x80788488: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    // 0x8078848C: lw          $v0, 0x52E0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X52E0);
L_80788490:
    // 0x80788490: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80788494: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x80788498: beq         $at, $zero, L_80788500
    if (ctx->r1 == 0) {
        // 0x8078849C: nop
    
            goto L_80788500;
    }
    // 0x8078849C: nop

    // 0x807884A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807884A4: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x807884A8: mfhi        $t1
    ctx->r9 = hi;
    // 0x807884AC: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x807884B0: jal         0x800653D8
    // 0x807884B4: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x807884B4: nop

    after_4:
    // 0x807884B8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x807884BC: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x807884C0: mfhi        $t2
    ctx->r10 = hi;
    // 0x807884C4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x807884C8: bne         $v1, $zero, L_807884D4
    if (ctx->r3 != 0) {
        // 0x807884CC: nop
    
            goto L_807884D4;
    }
    // 0x807884CC: nop

    // 0x807884D0: break       7
    do_break(2155381968);
L_807884D4:
    // 0x807884D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x807884D8: bne         $v1, $at, L_807884EC
    if (ctx->r3 != ctx->r1) {
        // 0x807884DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_807884EC;
    }
    // 0x807884DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x807884E0: bne         $v0, $at, L_807884EC
    if (ctx->r2 != ctx->r1) {
        // 0x807884E4: nop
    
            goto L_807884EC;
    }
    // 0x807884E4: nop

    // 0x807884E8: break       6
    do_break(2155381992);
L_807884EC:
    // 0x807884EC: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807884F0: mflo        $t4
    ctx->r12 = lo;
    // 0x807884F4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x807884F8: b           L_80788580
    // 0x807884FC: sw          $t5, 0x52E0($s1)
    MEM_W(0X52E0, ctx->r17) = ctx->r13;
        goto L_80788580;
    // 0x807884FC: sw          $t5, 0x52E0($s1)
    MEM_W(0X52E0, ctx->r17) = ctx->r13;
L_80788500:
    // 0x80788500: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x80788504: mfhi        $t6
    ctx->r14 = hi;
    // 0x80788508: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x8078850C: bne         $v1, $zero, L_80788518
    if (ctx->r3 != 0) {
        // 0x80788510: nop
    
            goto L_80788518;
    }
    // 0x80788510: nop

    // 0x80788514: break       7
    do_break(2155382036);
L_80788518:
    // 0x80788518: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8078851C: bne         $v1, $at, L_80788530
    if (ctx->r3 != ctx->r1) {
        // 0x80788520: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80788530;
    }
    // 0x80788520: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80788524: bne         $v0, $at, L_80788530
    if (ctx->r2 != ctx->r1) {
        // 0x80788528: nop
    
            goto L_80788530;
    }
    // 0x80788528: nop

    // 0x8078852C: break       6
    do_break(2155382060);
L_80788530:
    // 0x80788530: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80788534: jal         0x800653D8
    // 0x80788538: nop

    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x80788538: nop

    after_5:
    // 0x8078853C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80788540: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x80788544: mfhi        $t8
    ctx->r24 = hi;
    // 0x80788548: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8078854C: bne         $v1, $zero, L_80788558
    if (ctx->r3 != 0) {
        // 0x80788550: nop
    
            goto L_80788558;
    }
    // 0x80788550: nop

    // 0x80788554: break       7
    do_break(2155382100);
L_80788558:
    // 0x80788558: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8078855C: bne         $v1, $at, L_80788570
    if (ctx->r3 != ctx->r1) {
        // 0x80788560: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80788570;
    }
    // 0x80788560: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80788564: bne         $v0, $at, L_80788570
    if (ctx->r2 != ctx->r1) {
        // 0x80788568: nop
    
            goto L_80788570;
    }
    // 0x80788568: nop

    // 0x8078856C: break       6
    do_break(2155382124);
L_80788570:
    // 0x80788570: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80788574: mflo        $t0
    ctx->r8 = lo;
    // 0x80788578: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8078857C: sw          $t1, 0x52E0($s1)
    MEM_W(0X52E0, ctx->r17) = ctx->r9;
L_80788580:
    // 0x80788580: lh          $t3, 0x52C6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X52C6);
    // 0x80788584: addiu       $t2, $zero, -0x8C
    ctx->r10 = ADD32(0, -0X8C);
    // 0x80788588: beql        $t3, $zero, L_8078859C
    if (ctx->r11 == 0) {
        // 0x8078858C: sh          $zero, 0x52C2($s1)
        MEM_H(0X52C2, ctx->r17) = 0;
            goto L_8078859C;
    }
    goto skip_1;
    // 0x8078858C: sh          $zero, 0x52C2($s1)
    MEM_H(0X52C2, ctx->r17) = 0;
    skip_1:
    // 0x80788590: b           L_8078859C
    // 0x80788594: sh          $t2, 0x52C2($s1)
    MEM_H(0X52C2, ctx->r17) = ctx->r10;
        goto L_8078859C;
    // 0x80788594: sh          $t2, 0x52C2($s1)
    MEM_H(0X52C2, ctx->r17) = ctx->r10;
    // 0x80788598: sh          $zero, 0x52C2($s1)
    MEM_H(0X52C2, ctx->r17) = 0;
L_8078859C:
    // 0x8078859C: jal         0x807870C0
    // 0x807885A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807870C0(rdram, ctx);
        goto after_6;
    // 0x807885A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x807885A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807885A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807885AC: jal         0x8078980C
    // 0x807885B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8078980C(rdram, ctx);
        goto after_7;
    // 0x807885B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
L_807885B4:
    // 0x807885B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807885B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807885BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807885C0: jr          $ra
    // 0x807885C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807885C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80799AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799AC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80799ACC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80799AD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80799AD4: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80799AD8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80799ADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80799AE0: bne         $a1, $at, L_80799B04
    if (ctx->r5 != ctx->r1) {
        // 0x80799AE4: nop
    
            goto L_80799B04;
    }
    // 0x80799AE4: nop

    // 0x80799AE8: jal         0x80067E78
    // 0x80799AEC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067E78(rdram, ctx);
        goto after_0;
    // 0x80799AEC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x80799AF0: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x80799AF4: jal         0x80067F78
    // 0x80799AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80799AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80799AFC: b           L_80799B54
    // 0x80799B00: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80799B54;
    // 0x80799B00: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_80799B04:
    // 0x80799B04: jal         0x80067930
    // 0x80799B08: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x80799B08: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_2:
    // 0x80799B0C: beq         $v0, $zero, L_80799B3C
    if (ctx->r2 == 0) {
        // 0x80799B10: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80799B3C;
    }
    // 0x80799B10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80799B14: bnel        $v0, $at, L_80799B58
    if (ctx->r2 != ctx->r1) {
        // 0x80799B18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80799B58;
    }
    goto skip_0;
    // 0x80799B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80799B1C: jal         0x80067E78
    // 0x80799B20: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_3;
    // 0x80799B20: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x80799B24: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x80799B28: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80799B2C: jal         0x800678F0
    // 0x80799B30: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x80799B30: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x80799B34: b           L_80799B58
    // 0x80799B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80799B58;
    // 0x80799B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80799B3C:
    // 0x80799B3C: jal         0x80067E78
    // 0x80799B40: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_5;
    // 0x80799B40: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x80799B44: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x80799B48: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80799B4C: jal         0x80067838
    // 0x80799B50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_6;
    // 0x80799B50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_80799B54:
    // 0x80799B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80799B58:
    // 0x80799B58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80799B5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80799B60: jr          $ra
    // 0x80799B64: nop

    return;
    // 0x80799B64: nop

;}
RECOMP_FUNC void func_8004EFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EFDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004EFE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004EFE4: lw          $a3, 0x168($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X168);
    // 0x8004EFE8: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8004EFEC: lw          $t6, 0x88($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X88);
    // 0x8004EFF0: addiu       $a3, $a3, 0x48
    ctx->r7 = ADD32(ctx->r7, 0X48);
    // 0x8004EFF4: lw          $v1, 0x1B8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1B8);
    // 0x8004EFF8: beql        $t6, $zero, L_8004F138
    if (ctx->r14 == 0) {
        // 0x8004EFFC: lw          $t7, 0x1BC($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X1BC);
            goto L_8004F138;
    }
    goto skip_0;
    // 0x8004EFFC: lw          $t7, 0x1BC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1BC);
    skip_0:
    // 0x8004F000: lw          $t8, 0x1BC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F004: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8004F008: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004F00C: sb          $t7, 0x8($t8)
    MEM_B(0X8, ctx->r24) = ctx->r15;
    // 0x8004F010: lw          $t0, 0x1BC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F014: sb          $t9, 0x9($t0)
    MEM_B(0X9, ctx->r8) = ctx->r25;
    // 0x8004F018: lw          $t2, 0x1BC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F01C: lh          $t1, 0x56($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X56);
    // 0x8004F020: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x8004F024: sh          $t1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r9;
    // 0x8004F028: lh          $t3, 0x58($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X58);
    // 0x8004F02C: lw          $t5, 0x1BC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F030: addiu       $t4, $t3, -0x2
    ctx->r12 = ADD32(ctx->r11, -0X2);
    // 0x8004F034: sh          $t4, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r12;
    // 0x8004F038: lw          $t7, 0x1BC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F03C: lw          $t6, 0x60($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X60);
    // 0x8004F040: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8004F044: lw          $t9, 0x1BC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F048: lw          $t8, 0x40($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X40);
    // 0x8004F04C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8004F050: lw          $t1, 0x1BC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F054: sh          $t0, 0xE($t1)
    MEM_H(0XE, ctx->r9) = ctx->r8;
    // 0x8004F058: lw          $t2, 0x1BC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F05C: sh          $zero, 0x1C($t2)
    MEM_H(0X1C, ctx->r10) = 0;
    // 0x8004F060: lw          $t3, 0x1BC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F064: sh          $zero, 0x1E($t3)
    MEM_H(0X1E, ctx->r11) = 0;
    // 0x8004F068: lw          $t5, 0x1BC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F06C: lh          $t4, 0x56($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X56);
    // 0x8004F070: sh          $t4, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r12;
    // 0x8004F074: lh          $t6, 0x58($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X58);
    // 0x8004F078: lw          $t8, 0x1BC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F07C: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x8004F080: sh          $t7, 0x1A($t8)
    MEM_H(0X1A, ctx->r24) = ctx->r15;
    // 0x8004F084: lw          $t9, 0x1BC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F088: sw          $zero, 0x10($t9)
    MEM_W(0X10, ctx->r25) = 0;
    // 0x8004F08C: lw          $t0, 0x1BC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F090: sw          $zero, 0x14($t0)
    MEM_W(0X14, ctx->r8) = 0;
    // 0x8004F094: lw          $a0, 0x1BC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F098: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8004F09C: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    // 0x8004F0A0: jal         0x800734F0
    // 0x8004F0A4: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    func_800734F0(rdram, ctx);
        goto after_0;
    // 0x8004F0A4: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    after_0:
    // 0x8004F0A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F0AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004F0B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004F0B4: lw          $t1, 0x1BC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F0B8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8004F0BC: sw          $zero, 0x20($t1)
    MEM_W(0X20, ctx->r9) = 0;
    // 0x8004F0C0: lw          $t2, 0x1BC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F0C4: sw          $zero, 0x24($t2)
    MEM_W(0X24, ctx->r10) = 0;
    // 0x8004F0C8: lw          $t3, 0x1BC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F0CC: swc1        $f0, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->f0.u32l;
    // 0x8004F0D0: lw          $t4, 0x1BC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F0D4: swc1        $f0, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f0.u32l;
    // 0x8004F0D8: lw          $t5, 0x1BC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F0DC: sw          $zero, 0x30($t5)
    MEM_W(0X30, ctx->r13) = 0;
    // 0x8004F0E0: lw          $t6, 0x1BC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F0E4: sw          $zero, 0x34($t6)
    MEM_W(0X34, ctx->r14) = 0;
    // 0x8004F0E8: lw          $t7, 0x1BC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F0EC: sb          $zero, 0x38($t7)
    MEM_B(0X38, ctx->r15) = 0;
    // 0x8004F0F0: lw          $t8, 0x1BC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F0F4: sb          $v1, 0x3C($t8)
    MEM_B(0X3C, ctx->r24) = ctx->r3;
    // 0x8004F0F8: lw          $t9, 0x1BC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F0FC: sb          $v1, 0x3D($t9)
    MEM_B(0X3D, ctx->r25) = ctx->r3;
    // 0x8004F100: lw          $t0, 0x1BC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F104: sb          $v1, 0x3E($t0)
    MEM_B(0X3E, ctx->r8) = ctx->r3;
    // 0x8004F108: lw          $t1, 0x1BC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F10C: sb          $v1, 0x3F($t1)
    MEM_B(0X3F, ctx->r9) = ctx->r3;
    // 0x8004F110: lw          $t2, 0x1BC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F114: sb          $zero, 0x40($t2)
    MEM_B(0X40, ctx->r10) = 0;
    // 0x8004F118: lw          $t3, 0x1BC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F11C: sb          $zero, 0x41($t3)
    MEM_B(0X41, ctx->r11) = 0;
    // 0x8004F120: lw          $t4, 0x1BC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F124: sb          $zero, 0x42($t4)
    MEM_B(0X42, ctx->r12) = 0;
    // 0x8004F128: lw          $t5, 0x1BC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F12C: b           L_8004F25C
    // 0x8004F130: sb          $zero, 0x43($t5)
    MEM_B(0X43, ctx->r13) = 0;
        goto L_8004F25C;
    // 0x8004F130: sb          $zero, 0x43($t5)
    MEM_B(0X43, ctx->r13) = 0;
    // 0x8004F134: lw          $t7, 0x1BC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1BC);
L_8004F138:
    // 0x8004F138: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8004F13C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004F140: sb          $t6, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r14;
    // 0x8004F144: lw          $t9, 0x1BC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F148: sb          $t8, 0x9($t9)
    MEM_B(0X9, ctx->r25) = ctx->r24;
    // 0x8004F14C: lw          $t1, 0x1BC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F150: lh          $t0, 0x56($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X56);
    // 0x8004F154: sh          $t0, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r8;
    // 0x8004F158: lh          $t2, 0x58($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X58);
    // 0x8004F15C: lw          $t4, 0x1BC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F160: addiu       $t3, $t2, -0x2
    ctx->r11 = ADD32(ctx->r10, -0X2);
    // 0x8004F164: sh          $t3, 0xC($t4)
    MEM_H(0XC, ctx->r12) = ctx->r11;
    // 0x8004F168: lw          $t6, 0x1BC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F16C: lw          $t5, 0x60($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X60);
    // 0x8004F170: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8004F174: lw          $t7, 0x1BC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F178: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8004F17C: lw          $t8, 0x1BC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F180: sh          $zero, 0xE($t8)
    MEM_H(0XE, ctx->r24) = 0;
    // 0x8004F184: lw          $t9, 0x1BC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F188: sh          $zero, 0x1C($t9)
    MEM_H(0X1C, ctx->r25) = 0;
    // 0x8004F18C: lw          $t0, 0x1BC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F190: sh          $zero, 0x1E($t0)
    MEM_H(0X1E, ctx->r8) = 0;
    // 0x8004F194: lw          $t2, 0x1BC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F198: lh          $t1, 0x56($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X56);
    // 0x8004F19C: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    // 0x8004F1A0: lh          $t3, 0x58($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X58);
    // 0x8004F1A4: lw          $t5, 0x1BC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F1A8: addiu       $t4, $t3, -0x2
    ctx->r12 = ADD32(ctx->r11, -0X2);
    // 0x8004F1AC: sh          $t4, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = ctx->r12;
    // 0x8004F1B0: lw          $t6, 0x1BC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F1B4: sw          $zero, 0x10($t6)
    MEM_W(0X10, ctx->r14) = 0;
    // 0x8004F1B8: lw          $t7, 0x1BC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F1BC: sw          $zero, 0x14($t7)
    MEM_W(0X14, ctx->r15) = 0;
    // 0x8004F1C0: lw          $a0, 0x1BC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F1C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8004F1C8: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    // 0x8004F1CC: jal         0x800734F0
    // 0x8004F1D0: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    func_800734F0(rdram, ctx);
        goto after_1;
    // 0x8004F1D0: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x8004F1D4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F1D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004F1DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004F1E0: lw          $t8, 0x1BC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F1E4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8004F1E8: sw          $zero, 0x20($t8)
    MEM_W(0X20, ctx->r24) = 0;
    // 0x8004F1EC: lw          $t9, 0x1BC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F1F0: sw          $zero, 0x24($t9)
    MEM_W(0X24, ctx->r25) = 0;
    // 0x8004F1F4: lw          $t0, 0x1BC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F1F8: swc1        $f0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f0.u32l;
    // 0x8004F1FC: lw          $t1, 0x1BC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F200: swc1        $f0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->f0.u32l;
    // 0x8004F204: lw          $t2, 0x1BC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F208: sw          $zero, 0x30($t2)
    MEM_W(0X30, ctx->r10) = 0;
    // 0x8004F20C: lw          $t3, 0x1BC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F210: sw          $zero, 0x34($t3)
    MEM_W(0X34, ctx->r11) = 0;
    // 0x8004F214: lw          $t4, 0x1BC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F218: sb          $zero, 0x38($t4)
    MEM_B(0X38, ctx->r12) = 0;
    // 0x8004F21C: lw          $t5, 0x1BC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F220: sb          $v1, 0x3C($t5)
    MEM_B(0X3C, ctx->r13) = ctx->r3;
    // 0x8004F224: lw          $t6, 0x1BC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F228: sb          $v1, 0x3D($t6)
    MEM_B(0X3D, ctx->r14) = ctx->r3;
    // 0x8004F22C: lw          $t7, 0x1BC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F230: sb          $v1, 0x3E($t7)
    MEM_B(0X3E, ctx->r15) = ctx->r3;
    // 0x8004F234: lw          $t8, 0x1BC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F238: sb          $v1, 0x3F($t8)
    MEM_B(0X3F, ctx->r24) = ctx->r3;
    // 0x8004F23C: lw          $t9, 0x1BC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F240: sb          $zero, 0x40($t9)
    MEM_B(0X40, ctx->r25) = 0;
    // 0x8004F244: lw          $t0, 0x1BC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F248: sb          $zero, 0x41($t0)
    MEM_B(0X41, ctx->r8) = 0;
    // 0x8004F24C: lw          $t1, 0x1BC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F250: sb          $zero, 0x42($t1)
    MEM_B(0X42, ctx->r9) = 0;
    // 0x8004F254: lw          $t2, 0x1BC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1BC);
    // 0x8004F258: sb          $zero, 0x43($t2)
    MEM_B(0X43, ctx->r10) = 0;
L_8004F25C:
    // 0x8004F25C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004F260: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004F264: jr          $ra
    // 0x8004F268: nop

    return;
    // 0x8004F268: nop

;}
RECOMP_FUNC void func_806DB520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB520: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806DB524: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(634, 0X298) << 16);
    // 0x806DB528: addiu       $t6, $t6, -0x48A8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(634, 0X298));
    // 0x806DB52C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806DB530: jr          $ra
    // 0x806DB534: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806DB534: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8005C3B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C3B4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8005C3B8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8005C3BC: lw          $t6, 0x478($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X478);
    // 0x8005C3C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C3C4: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005C3C8: swc1        $f0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f0.u32l;
    // 0x8005C3CC: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x8005C3D0: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x8005C3D4: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8005C3D8: swc1        $f0, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f0.u32l;
    // 0x8005C3DC: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x8005C3E0: lw          $t8, 0x478($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X478);
    // 0x8005C3E4: lwc1        $f6, 0xC90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XC90);
    // 0x8005C3E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C3EC: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8005C3F0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005C3F4: swc1        $f0, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f0.u32l;
    // 0x8005C3F8: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x8005C3FC: lwc1        $f8, 0xC94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XC94);
    // 0x8005C400: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C404: swc1        $f8, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f8.u32l;
    // 0x8005C408: lwc1        $f10, 0xC98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XC98);
    // 0x8005C40C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005C410: swc1        $f10, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f10.u32l;
    // 0x8005C414: lwc1        $f16, 0xC9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC9C);
    // 0x8005C418: jr          $ra
    // 0x8005C41C: swc1        $f16, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x8005C41C: swc1        $f16, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_806DF080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF080: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806DF084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF088: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806DF08C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806DF090: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806DF094: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x806DF098: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x806DF09C: addiu       $at, $zero, 0x45BB
    ctx->r1 = ADD32(0, 0X45BB);
    // 0x806DF0A0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x806DF0A4: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x806DF0A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806DF0AC: bnel        $t8, $at, L_806DF0C8
    if (ctx->r24 != ctx->r1) {
        // 0x806DF0B0: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_806DF0C8;
    }
    goto skip_0;
    // 0x806DF0B0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x806DF0B4: jal         0x806DF010
    // 0x806DF0B8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_806DF010(rdram, ctx);
        goto after_0;
    // 0x806DF0B8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_0:
    // 0x806DF0BC: bnel        $v0, $zero, L_806DF0F0
    if (ctx->r2 != 0) {
        // 0x806DF0C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806DF0F0;
    }
    goto skip_1;
    // 0x806DF0C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806DF0C4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_806DF0C8:
    // 0x806DF0C8: addiu       $at, $zero, 0x45BD
    ctx->r1 = ADD32(0, 0X45BD);
    // 0x806DF0CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x806DF0D0: lhu         $t0, 0xC($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0XC);
    // 0x806DF0D4: bne         $t0, $at, L_806DF0EC
    if (ctx->r8 != ctx->r1) {
        // 0x806DF0D8: nop
    
            goto L_806DF0EC;
    }
    // 0x806DF0D8: nop

    // 0x806DF0DC: jal         0x806DF050
    // 0x806DF0E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_806DF050(rdram, ctx);
        goto after_1;
    // 0x806DF0E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x806DF0E4: bnel        $v0, $zero, L_806DF0F0
    if (ctx->r2 != 0) {
        // 0x806DF0E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806DF0F0;
    }
    goto skip_2;
    // 0x806DF0E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_806DF0EC:
    // 0x806DF0EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806DF0F0:
    // 0x806DF0F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806DF0F4: jr          $ra
    // 0x806DF0F8: nop

    return;
    // 0x806DF0F8: nop

;}
RECOMP_FUNC void func_807ABA78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ABA78: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x807ABA7C: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x807ABA80: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x807ABA84: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x807ABA88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807ABA8C: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x807ABA90: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x807ABA94: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x807ABA98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x807ABA9C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x807ABAA0: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x807ABAA4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x807ABAA8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x807ABAAC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807ABAB0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x807ABAB4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x807ABAB8: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x807ABABC: ori         $t3, $zero, 0xAC80
    ctx->r11 = 0 | 0XAC80;
    // 0x807ABAC0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x807ABAC4: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x807ABAC8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x807ABACC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x807ABAD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x807ABAD4: lui         $a3, 0x55
    ctx->r7 = S32(0X55 << 16);
    // 0x807ABAD8: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x807ABADC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x807ABAE0: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x807ABAE4: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x807ABAE8: ori         $a3, $a3, 0x3048
    ctx->r7 = ctx->r7 | 0X3048;
    // 0x807ABAEC: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x807ABAF0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x807ABAF4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x807ABAF8: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x807ABAFC: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x807ABB00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x807ABB04: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807ABB08: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x807ABB0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x807ABB10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x807ABB14: lui         $t0, 0xFFFC
    ctx->r8 = S32(0XFFFC << 16);
    // 0x807ABB18: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x807ABB1C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x807ABB20: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x807ABB24: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x807ABB28: ori         $t0, $t0, 0xF279
    ctx->r8 = ctx->r8 | 0XF279;
    // 0x807ABB2C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x807ABB30: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x807ABB34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x807ABB38: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x807ABB3C: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x807ABB40: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x807ABB44: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x807ABB48: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x807ABB4C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x807ABB50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x807ABB54: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x807ABB58: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x807ABB5C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x807ABB60: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x807ABB64: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x807ABB68: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x807ABB6C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x807ABB70: jr          $ra
    // 0x807ABB74: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    return;
    // 0x807ABB74: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_80534678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8053467C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80534680: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80534684: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80534688: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8053468C: jal         0x80067BBC
    // 0x80534690: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80534690: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80534694: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80534698: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8053469C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x805346A0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x805346A4: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x805346A8: bne         $a1, $at, L_805346CC
    if (ctx->r5 != ctx->r1) {
        // 0x805346AC: nop
    
            goto L_805346CC;
    }
    // 0x805346AC: nop

    // 0x805346B0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x805346B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805346B8: jal         0x80067F78
    // 0x805346BC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x805346BC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x805346C0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805346C4: b           L_805346D4
    // 0x805346C8: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
        goto L_805346D4;
    // 0x805346C8: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
L_805346CC:
    // 0x805346CC: jal         0x800678F0
    // 0x805346D0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_800678F0(rdram, ctx);
        goto after_2;
    // 0x805346D0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_2:
L_805346D4:
    // 0x805346D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805346D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805346DC: jr          $ra
    // 0x805346E0: nop

    return;
    // 0x805346E0: nop

;}
RECOMP_FUNC void func_80525630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525630: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80525634: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80525638: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8052563C: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // 0x80525640: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x80525644: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80525648: sb          $zero, 0x10($t6)
    MEM_B(0X10, ctx->r14) = 0;
    // 0x8052564C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80525650: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80525654: bne         $t7, $zero, L_80525674
    if (ctx->r15 != 0) {
        // 0x80525658: nop
    
            goto L_80525674;
    }
    // 0x80525658: nop

    // 0x8052565C: lh          $t8, -0x7680($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X7680);
    // 0x80525660: slti        $at, $t8, -0x5
    ctx->r1 = SIGNED(ctx->r24) < -0X5 ? 1 : 0;
    // 0x80525664: beq         $at, $zero, L_80525690
    if (ctx->r1 == 0) {
        // 0x80525668: nop
    
            goto L_80525690;
    }
    // 0x80525668: nop

    // 0x8052566C: jr          $ra
    // 0x80525670: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    return;
    // 0x80525670: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
L_80525674:
    // 0x80525674: bne         $at, $zero, L_8052568C
    if (ctx->r1 != 0) {
        // 0x80525678: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_8052568C;
    }
    // 0x80525678: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8052567C: lh          $t9, -0x7680($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X7680);
    // 0x80525680: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80525684: bne         $at, $zero, L_80525690
    if (ctx->r1 != 0) {
        // 0x80525688: nop
    
            goto L_80525690;
    }
    // 0x80525688: nop

L_8052568C:
    // 0x8052568C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_80525690:
    // 0x80525690: jr          $ra
    // 0x80525694: nop

    return;
    // 0x80525694: nop

;}
RECOMP_FUNC void func_8003D090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003D094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D098: jal         0x8005780C
    // 0x8003D09C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    func_8005780C(rdram, ctx);
        goto after_0;
    // 0x8003D09C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8003D0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D0A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003D0A8: jr          $ra
    // 0x8003D0AC: nop

    return;
    // 0x8003D0AC: nop

;}
RECOMP_FUNC void func_807B989C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B989C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B98A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B98A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B98A8: jal         0x807B8D30
    // 0x807B98AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807B8D30(rdram, ctx);
        goto after_0;
    // 0x807B98AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807B98B0: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x807B98B4: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x807B98B8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x807B98BC: addiu       $a0, $zero, 0x203
    ctx->r4 = ADD32(0, 0X203);
    // 0x807B98C0: lhu         $v0, 0xC($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0XC);
    // 0x807B98C4: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x807B98C8: bne         $t7, $at, L_807B9920
    if (ctx->r15 != ctx->r1) {
        // 0x807B98CC: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_807B9920;
    }
    // 0x807B98CC: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x807B98D0: jal         0x80067818
    // 0x807B98D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807B98D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807B98D8: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x807B98DC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B98E0: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x807B98E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B98E8: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x807B98EC: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x807B98F0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B98F4: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x807B98F8: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
    // 0x807B98FC: jal         0x807B9034
    // 0x807B9900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B9034(rdram, ctx);
        goto after_2;
    // 0x807B9900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807B9904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B9908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B990C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B9910: jal         0x807B9E2C
    // 0x807B9914: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_807B9E2C(rdram, ctx);
        goto after_3;
    // 0x807B9914: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x807B9918: b           L_807B997C
    // 0x807B991C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807B997C;
    // 0x807B991C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B9920:
    // 0x807B9920: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x807B9924: bnel        $t1, $at, L_807B997C
    if (ctx->r9 != ctx->r1) {
        // 0x807B9928: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807B997C;
    }
    goto skip_0;
    // 0x807B9928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807B992C: jal         0x807B908C
    // 0x807B9930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B908C(rdram, ctx);
        goto after_4;
    // 0x807B9930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807B9934: addiu       $a0, $zero, 0x205
    ctx->r4 = ADD32(0, 0X205);
    // 0x807B9938: jal         0x80067818
    // 0x807B993C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x807B993C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x807B9940: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x807B9944: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9948: sb          $t2, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r10;
    // 0x807B994C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9950: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x807B9954: sb          $t3, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r11;
    // 0x807B9958: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B995C: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x807B9960: sb          $t4, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r12;
    // 0x807B9964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B9968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B996C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B9970: jal         0x807B9E2C
    // 0x807B9974: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_807B9E2C(rdram, ctx);
        goto after_6;
    // 0x807B9974: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_6:
    // 0x807B9978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B997C:
    // 0x807B997C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B9980: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B9984: jr          $ra
    // 0x807B9988: nop

    return;
    // 0x807B9988: nop

;}
RECOMP_FUNC void func_805C6900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C6900: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805C6904: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C6908: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805C690C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805C6910: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x805C6914: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x805C6918: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x805C691C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C6920: jal         0x8004700C
    // 0x805C6924: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805C6924: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805C6928: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x805C692C: beq         $v0, $zero, L_805C6A5C
    if (ctx->r2 == 0) {
        // 0x805C6930: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_805C6A5C;
    }
    // 0x805C6930: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x805C6934: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x805C6938: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805C693C: bnel        $t6, $at, L_805C6A60
    if (ctx->r14 != ctx->r1) {
        // 0x805C6940: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805C6A60;
    }
    goto skip_0;
    // 0x805C6940: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805C6944: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x805C6948: bnel        $t7, $zero, L_805C6A60
    if (ctx->r15 != 0) {
        // 0x805C694C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805C6A60;
    }
    goto skip_1;
    // 0x805C694C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805C6950: lw          $t8, 0x24($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X24);
    // 0x805C6954: bnel        $t8, $zero, L_805C6A60
    if (ctx->r24 != 0) {
        // 0x805C6958: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805C6A60;
    }
    goto skip_2;
    // 0x805C6958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805C695C: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x805C6960: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x805C6964: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x805C6968: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x805C696C: bne         $at, $zero, L_805C697C
    if (ctx->r1 != 0) {
        // 0x805C6970: addiu       $t1, $zero, 0x5
        ctx->r9 = ADD32(0, 0X5);
            goto L_805C697C;
    }
    // 0x805C6970: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x805C6974: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x805C6978: bne         $v0, $at, L_805C6A5C
    if (ctx->r2 != ctx->r1) {
        // 0x805C697C: lui         $at, 0x8010
        ctx->r1 = S32(0X8010 << 16);
            goto L_805C6A5C;
    }
L_805C697C:
    // 0x805C697C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805C6980: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x805C6984: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805C6988: sb          $t0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r8;
    // 0x805C698C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805C6990: jal         0x8002FBBC
    // 0x805C6994: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
    func_8002FBBC(rdram, ctx);
        goto after_1;
    // 0x805C6994: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
    after_1:
    // 0x805C6998: jal         0x805C781C
    // 0x805C699C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C781C(rdram, ctx);
        goto after_2;
    // 0x805C699C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805C69A0: jal         0x80066E88
    // 0x805C69A4: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x805C69A4: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    after_3:
    // 0x805C69A8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805C69AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805C69B0: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C69B4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x805C69B8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x805C69BC: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x805C69C0: jal         0x80066DE4
    // 0x805C69C4: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x805C69C4: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    after_4:
    // 0x805C69C8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x805C69CC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x805C69D0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805C69D4: lwc1        $f8, 0x84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805C69D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805C69DC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x805C69E0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x805C69E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C69E8: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C69EC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x805C69F0: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x805C69F4: div.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x805C69F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C69FC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x805C6A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C6A04: add.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x805C6A08: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
    // 0x805C6A0C: lwc1        $f16, 0x88($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X88);
    // 0x805C6A10: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805C6A14: sub.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x805C6A18: div.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x805C6A1C: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    // 0x805C6A20: lbu         $t2, 0x30($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X30);
    // 0x805C6A24: bnel        $t2, $at, L_805C6A40
    if (ctx->r10 != ctx->r1) {
        // 0x805C6A28: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_805C6A40;
    }
    goto skip_3;
    // 0x805C6A28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x805C6A2C: jal         0x805C9D10
    // 0x805C6A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C9D10(rdram, ctx);
        goto after_5;
    // 0x805C6A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805C6A34: b           L_805C6A60
    // 0x805C6A38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C6A60;
    // 0x805C6A38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805C6A3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_805C6A40:
    // 0x805C6A40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C6A44: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x805C6A48: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x805C6A4C: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x805C6A50: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805C6A54: jal         0x805C9D10
    // 0x805C6A58: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    func_805C9D10(rdram, ctx);
        goto after_6;
    // 0x805C6A58: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    after_6:
L_805C6A5C:
    // 0x805C6A5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C6A60:
    // 0x805C6A60: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805C6A64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805C6A68: jr          $ra
    // 0x805C6A6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x805C6A6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Idle_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067284: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067288: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006728C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80067290: jal         0x80090E20
    // 0x80067294: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_0;
    // 0x80067294: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_0:
    // 0x80067298: jal         0x80067390
    // 0x8006729C: nop

    Idle_InitVideo(rdram, ctx);
        goto after_1;
    // 0x8006729C: nop

    after_1:
    // 0x800672A0: jal         0x8008D3F0
    // 0x800672A4: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_2;
    // 0x800672A4: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_2:
    // 0x800672A8: jal         0x800867A0
    // 0x800672AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_3;
    // 0x800672AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800672B0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800672B4: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800672B8: addiu       $a2, $a2, 0x470
    ctx->r6 = ADD32(ctx->r6, 0X470);
    // 0x800672BC: addiu       $a1, $a1, 0x490
    ctx->r5 = ADD32(ctx->r5, 0X490);
    // 0x800672C0: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x800672C4: jal         0x800894A0
    // 0x800672C8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_4;
    // 0x800672C8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_4:
    // 0x800672CC: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x800672D0: addiu       $t7, $t7, 0xDDC
    ctx->r15 = ADD32(ctx->r15, 0XDDC);
    // 0x800672D4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800672D8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800672DC: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x800672E0: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x800672E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800672E8: addiu       $a2, $a2, -0x348
    ctx->r6 = ADD32(ctx->r6, -0X348);
    // 0x800672EC: addiu       $a1, $a1, -0x2A48
    ctx->r5 = ADD32(ctx->r5, -0X2A48);
    // 0x800672F0: addiu       $a0, $a0, -0x348
    ctx->r4 = ADD32(ctx->r4, -0X348);
    // 0x800672F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800672F8: jal         0x80081910
    // 0x800672FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_5;
    // 0x800672FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80067300: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80067304: addiu       $t8, $t8, -0x348
    ctx->r24 = ADD32(ctx->r24, -0X348);
    // 0x80067308: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006730C: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80067310: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80067314: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80067318: addiu       $a2, $a2, -0x7000
    ctx->r6 = ADD32(ctx->r6, -0X7000);
    // 0x8006731C: addiu       $a0, $a0, -0x2BF8
    ctx->r4 = ADD32(ctx->r4, -0X2BF8);
    // 0x80067320: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80067324: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80067328: jal         0x80085B10
    // 0x8006732C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    osCreateThread_recomp(rdram, ctx);
        goto after_6;
    // 0x8006732C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80067330: lui         $t0, 0xA400
    ctx->r8 = S32(0XA400 << 16);
    // 0x80067334: lw          $t1, 0x1000($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1000);
    // 0x80067338: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8006733C: lui         $t2, 0xA400
    ctx->r10 = S32(0XA400 << 16);
    // 0x80067340: sw          $t1, -0x79DC($at)
    MEM_W(-0X79DC, ctx->r1) = ctx->r9;
    // 0x80067344: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80067348: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8006734C: jal         0x8006F500
    // 0x80067350: sw          $t3, -0x79D8($at)
    MEM_W(-0X79D8, ctx->r1) = ctx->r11;
    func_8006F500(rdram, ctx);
        goto after_7;
    // 0x80067350: sw          $t3, -0x79D8($at)
    MEM_W(-0X79D8, ctx->r1) = ctx->r11;
    after_7:
    // 0x80067354: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80067358: jal         0x80090CC0
    // 0x8006735C: addiu       $a0, $a0, -0x2BF8
    ctx->r4 = ADD32(ctx->r4, -0X2BF8);
    osStartThread_recomp(rdram, ctx);
        goto after_8;
    // 0x8006735C: addiu       $a0, $a0, -0x2BF8
    ctx->r4 = ADD32(ctx->r4, -0X2BF8);
    after_8:
    // 0x80067360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80067364: jal         0x8008B130
    // 0x80067368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_9;
    // 0x80067368: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
L_8006736C:
    // 0x8006736C: b           L_8006736C
    pause_self(rdram);
    // 0x80067370: nop

    // 0x80067374: nop

    // 0x80067378: nop

    // 0x8006737C: nop

    // 0x80067380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80067384: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067388: jr          $ra
    // 0x8006738C: nop

    return;
    // 0x8006738C: nop

;}
RECOMP_FUNC void func_80021194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80021198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002119C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800211A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800211A4: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x800211A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800211AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800211B0: bne         $t6, $at, L_800211F0
    if (ctx->r14 != ctx->r1) {
        // 0x800211B4: nop
    
            goto L_800211F0;
    }
    // 0x800211B4: nop

    // 0x800211B8: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x800211BC: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x800211C0: bne         $t7, $at, L_800211F0
    if (ctx->r15 != ctx->r1) {
        // 0x800211C4: nop
    
            goto L_800211F0;
    }
    // 0x800211C4: nop

    // 0x800211C8: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800211CC: lwc1        $f6, 0xA8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x800211D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800211D4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800211D8: nop

    // 0x800211DC: bc1f        L_8002122C
    if (!c1cs) {
        // 0x800211E0: nop
    
            goto L_8002122C;
    }
    // 0x800211E0: nop

    // 0x800211E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800211E8: b           L_8002122C
    // 0x800211EC: nop

        goto L_8002122C;
    // 0x800211EC: nop

L_800211F0:
    // 0x800211F0: jal         0x80066E88
    // 0x800211F4: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x800211F4: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    after_0:
    // 0x800211F8: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800211FC: lwc1        $f10, 0x100($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X100);
    // 0x80021200: lwc1        $f4, 0x10C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80021204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021208: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8002120C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80021210: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80021214: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80021218: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8002121C: nop

    // 0x80021220: bc1f        L_8002122C
    if (!c1cs) {
        // 0x80021224: nop
    
            goto L_8002122C;
    }
    // 0x80021224: nop

    // 0x80021228: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002122C:
    // 0x8002122C: beq         $v0, $zero, L_80021280
    if (ctx->r2 == 0) {
        // 0x80021230: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80021280;
    }
    // 0x80021230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021234: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x80021238: addiu       $s1, $s1, -0x2F38
    ctx->r17 = ADD32(ctx->r17, -0X2F38);
    // 0x8002123C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021244: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80021248: jal         0x8004D23C
    // 0x8002124C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_1;
    // 0x8002124C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80021250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021254: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80021258: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002125C: jal         0x8004D23C
    // 0x80021260: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_2;
    // 0x80021260: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80021264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021268: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8002126C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021270: jal         0x8004D23C
    // 0x80021274: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_3;
    // 0x80021274: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80021278: b           L_800212C4
    // 0x8002127C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800212C4;
    // 0x8002127C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80021280:
    // 0x80021280: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x80021284: addiu       $s1, $s1, -0x2F38
    ctx->r17 = ADD32(ctx->r17, -0X2F38);
    // 0x80021288: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002128C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80021290: jal         0x8004D23C
    // 0x80021294: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_4;
    // 0x80021294: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_4:
    // 0x80021298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002129C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800212A0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800212A4: jal         0x8004D23C
    // 0x800212A8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_5;
    // 0x800212A8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x800212AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800212B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800212B4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800212B8: jal         0x8004D23C
    // 0x800212BC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_6;
    // 0x800212BC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_6:
    // 0x800212C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800212C4:
    // 0x800212C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800212C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800212CC: jr          $ra
    // 0x800212D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800212D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806EF87C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF87C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EF880: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EF884: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806EF888: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806EF88C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806EF890: jal         0x806EC16C
    // 0x806EF894: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806EF894: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x806EF898: lw          $t6, 0x1F4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1F4);
    // 0x806EF89C: jal         0x800577D8
    // 0x806EF8A0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806EF8A0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806EF8A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806EF8A8: lui         $v1, 0x806F
    ctx->r3 = S32(RELOC_HI16(676, 0X4C04) << 16);
    // 0x806EF8AC: addiu       $v1, $v1, 0xB54
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(676, 0X4C04));
    // 0x806EF8B0: swc1        $f4, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f4.u32l;
    // 0x806EF8B4: lh          $t7, 0x12($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X12);
    // 0x806EF8B8: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x806EF8BC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x806EF8C0: sh          $t8, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r24;
    // 0x806EF8C4: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x806EF8C8: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x806EF8CC: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x806EF8D0: lh          $t9, 0x12($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X12);
    // 0x806EF8D4: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x806EF8D8: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x806EF8DC: bne         $at, $zero, L_806EF97C
    if (ctx->r1 != 0) {
        // 0x806EF8E0: nop
    
            goto L_806EF97C;
    }
    // 0x806EF8E0: nop

    // 0x806EF8E4: sh          $t3, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r11;
    // 0x806EF8E8: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x806EF8EC: sh          $zero, 0x12($s0)
    MEM_H(0X12, ctx->r16) = 0;
    // 0x806EF8F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806EF8F4: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x806EF8F8: bne         $at, $zero, L_806EF920
    if (ctx->r1 != 0) {
        // 0x806EF8FC: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_806EF920;
    }
    // 0x806EF8FC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x806EF900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EF904: lbu         $a2, 0x8($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X8);
    // 0x806EF908: jal         0x806F0348
    // 0x806EF90C: lw          $a3, 0x12C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_2;
    // 0x806EF90C: lw          $a3, 0x12C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X12C);
    after_2:
    // 0x806EF910: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x806EF914: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x806EF918: b           L_806EF97C
    // 0x806EF91C: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
        goto L_806EF97C;
    // 0x806EF91C: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
L_806EF920:
    // 0x806EF920: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x806EF924: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x806EF928: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806EF92C: sh          $t6, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r14;
    // 0x806EF930: lh          $t7, 0x10($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X10);
    // 0x806EF934: bne         $t7, $at, L_806EF97C
    if (ctx->r15 != ctx->r1) {
        // 0x806EF938: nop
    
            goto L_806EF97C;
    }
    // 0x806EF938: nop

    // 0x806EF93C: lw          $t8, 0x12C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X12C);
    // 0x806EF940: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EF944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806EF948: bne         $t8, $zero, L_806EF960
    if (ctx->r24 != 0) {
        // 0x806EF94C: nop
    
            goto L_806EF960;
    }
    // 0x806EF94C: nop

    // 0x806EF950: jal         0x806F008C
    // 0x806EF954: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806F008C(rdram, ctx);
        goto after_3;
    // 0x806EF954: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x806EF958: b           L_806EF96C
    // 0x806EF95C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
        goto L_806EF96C;
    // 0x806EF95C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_806EF960:
    // 0x806EF960: jal         0x806F008C
    // 0x806EF964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806F008C(rdram, ctx);
        goto after_4;
    // 0x806EF964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x806EF968: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_806EF96C:
    // 0x806EF96C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806EF970: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806EF974: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806EF978: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
L_806EF97C:
    // 0x806EF97C: jal         0x806EF584
    // 0x806EF980: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806EF584(rdram, ctx);
        goto after_5;
    // 0x806EF980: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x806EF984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806EF988: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806EF98C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806EF990: jr          $ra
    // 0x806EF994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806EF994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80032948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003294C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032950: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80032954: lbu         $t6, 0x159($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X159);
    // 0x80032958: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003295C: bne         $t6, $zero, L_80032974
    if (ctx->r14 != 0) {
        // 0x80032960: nop
    
            goto L_80032974;
    }
    // 0x80032960: nop

    // 0x80032964: jal         0x8002DFF8
    // 0x80032968: nop

    func_8002DFF8(rdram, ctx);
        goto after_0;
    // 0x80032968: nop

    after_0:
    // 0x8003296C: b           L_80032974
    // 0x80032970: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80032974;
    // 0x80032970: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80032974:
    // 0x80032974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003297C: jr          $ra
    // 0x80032980: nop

    return;
    // 0x80032980: nop

;}
RECOMP_FUNC void func_8051ED9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051ED9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051EDA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051EDA4: jal         0x8051EC54
    // 0x8051EDA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8051EC54(rdram, ctx);
        goto after_0;
    // 0x8051EDA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051EDAC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8051EDB0: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x8051EDB4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8051EDB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051EDBC: lhu         $v0, 0xC($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0XC);
    // 0x8051EDC0: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x8051EDC4: beq         $t7, $at, L_8051EDD8
    if (ctx->r15 == ctx->r1) {
        // 0x8051EDC8: andi        $t8, $v0, 0x1000
        ctx->r24 = ctx->r2 & 0X1000;
            goto L_8051EDD8;
    }
    // 0x8051EDC8: andi        $t8, $v0, 0x1000
    ctx->r24 = ctx->r2 & 0X1000;
    // 0x8051EDCC: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8051EDD0: bnel        $t8, $at, L_8051EE14
    if (ctx->r24 != ctx->r1) {
        // 0x8051EDD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8051EE14;
    }
    goto skip_0;
    // 0x8051EDD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8051EDD8:
    // 0x8051EDD8: jal         0x8051EF30
    // 0x8051EDDC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8051EF30(rdram, ctx);
        goto after_1;
    // 0x8051EDDC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x8051EDE0: addiu       $a0, $zero, 0x203
    ctx->r4 = ADD32(0, 0X203);
    // 0x8051EDE4: jal         0x80067818
    // 0x8051EDE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8051EDE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8051EDEC: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x8051EDF0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8051EDF4: sb          $t9, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r25;
    // 0x8051EDF8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8051EDFC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8051EE00: sb          $t0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r8;
    // 0x8051EE04: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8051EE08: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8051EE0C: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
    // 0x8051EE10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051EE14:
    // 0x8051EE14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051EE18: jr          $ra
    // 0x8051EE1C: nop

    return;
    // 0x8051EE1C: nop

;}
RECOMP_FUNC void func_8046BC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046BC14: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8046BC18: lui         $a2, 0xB800
    ctx->r6 = S32(0XB800 << 16);
    // 0x8046BC1C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8046BC20: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8046BC24: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8046BC28: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x8046BC2C: jr          $ra
    // 0x8046BC30: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    return;
    // 0x8046BC30: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
;}
RECOMP_FUNC void func_80790F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790F54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80790F58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80790F5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80790F60: jal         0x8004700C
    // 0x80790F64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80790F64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80790F68: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80790F6C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80790F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790F74: jal         0x80790CB4
    // 0x80790F78: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80790CB4(rdram, ctx);
        goto after_1;
    // 0x80790F78: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_1:
    // 0x80790F7C: jal         0x80790714
    // 0x80790F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_2;
    // 0x80790F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80790F84: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x80790F88: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80790F8C: bnel        $v1, $at, L_80790FD0
    if (ctx->r3 != ctx->r1) {
        // 0x80790F90: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_80790FD0;
    }
    goto skip_0;
    // 0x80790F90: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80790F94: jal         0x80011C3C
    // 0x80790F98: nop

    func_80011C3C(rdram, ctx);
        goto after_3;
    // 0x80790F98: nop

    after_3:
    // 0x80790F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790FA0: jal         0x80790878
    // 0x80790FA4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    func_80790878(rdram, ctx);
        goto after_4;
    // 0x80790FA4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    after_4:
    // 0x80790FA8: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x80790FAC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80790FB0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80790FB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80790FB8: sb          $t7, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r15;
    // 0x80790FBC: sb          $zero, 0x7EA5($at)
    MEM_B(0X7EA5, ctx->r1) = 0;
    // 0x80790FC0: jal         0x800492C0
    // 0x80790FC4: addiu       $a0, $zero, -0x68
    ctx->r4 = ADD32(0, -0X68);
    func_800492C0(rdram, ctx);
        goto after_5;
    // 0x80790FC4: addiu       $a0, $zero, -0x68
    ctx->r4 = ADD32(0, -0X68);
    after_5:
    // 0x80790FC8: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x80790FCC: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_80790FD0:
    // 0x80790FD0: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80790FD4: bne         $t9, $at, L_80791028
    if (ctx->r25 != ctx->r1) {
        // 0x80790FD8: sw          $t9, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r25;
            goto L_80791028;
    }
    // 0x80790FD8: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x80790FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80790FE0: jal         0x80790818
    // 0x80790FE4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    func_80790818(rdram, ctx);
        goto after_6;
    // 0x80790FE4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    after_6:
    // 0x80790FE8: jal         0x800677F8
    // 0x80790FEC: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_800677F8(rdram, ctx);
        goto after_7;
    // 0x80790FEC: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_7:
    // 0x80790FF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80790FF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80790FF8: sb          $t1, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = ctx->r9;
    // 0x80790FFC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x80791000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80791004: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791008: jal         0x8079393C
    // 0x8079100C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8079393C(rdram, ctx);
        goto after_8;
    // 0x8079100C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x80791010: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80791014: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80791018: sw          $t2, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->r10;
    // 0x8079101C: lw          $t4, 0x1E4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E4);
    // 0x80791020: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80791024: sw          $t5, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r13;
L_80791028:
    // 0x80791028: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8079102C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80791030: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80791034: jr          $ra
    // 0x80791038: nop

    return;
    // 0x80791038: nop

;}
RECOMP_FUNC void func_8078F6E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F6E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078F6EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078F6F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078F6F4: jal         0x8004700C
    // 0x8078F6F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078F6F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8078F6FC: beql        $v0, $zero, L_8078F7B0
    if (ctx->r2 == 0) {
        // 0x8078F700: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078F7B0;
    }
    goto skip_0;
    // 0x8078F700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8078F704: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x8078F708: lw          $a2, 0x1F4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F4);
    // 0x8078F70C: lhu         $a1, 0x4($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X4);
    // 0x8078F710: lhu         $t8, 0x12BC($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X12BC);
    // 0x8078F714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078F718: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8078F71C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8078F720: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8078F724: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x8078F728: lhu         $t7, 0x1200($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1200);
    // 0x8078F72C: lbu         $t9, 0x1202($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1202);
    // 0x8078F730: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x8078F734: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8078F738: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8078F73C: beq         $at, $zero, L_8078F754
    if (ctx->r1 == 0) {
        // 0x8078F740: andi        $a3, $a3, 0xFFFF
        ctx->r7 = ctx->r7 & 0XFFFF;
            goto L_8078F754;
    }
    // 0x8078F740: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8078F744: jal         0x8078F524
    // 0x8078F748: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    func_8078F524(rdram, ctx);
        goto after_1;
    // 0x8078F748: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    after_1:
    // 0x8078F74C: b           L_8078F7B0
    // 0x8078F750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078F7B0;
    // 0x8078F750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078F754:
    // 0x8078F754: sll         $t0, $a3, 4
    ctx->r8 = S32(ctx->r7 << 4);
    // 0x8078F758: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
    // 0x8078F75C: lbu         $t2, 0x209($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X209);
    // 0x8078F760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078F764: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x8078F768: bnel        $t3, $zero, L_8078F784
    if (ctx->r11 != 0) {
        // 0x8078F76C: lbu         $t4, 0x1FA($a2)
        ctx->r12 = MEM_BU(ctx->r6, 0X1FA);
            goto L_8078F784;
    }
    goto skip_1;
    // 0x8078F76C: lbu         $t4, 0x1FA($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1FA);
    skip_1:
    // 0x8078F770: jal         0x8078F6A4
    // 0x8078F774: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8078F6A4(rdram, ctx);
        goto after_2;
    // 0x8078F774: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x8078F778: b           L_8078F7B0
    // 0x8078F77C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078F7B0;
    // 0x8078F77C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078F780: lbu         $t4, 0x1FA($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1FA);
L_8078F784:
    // 0x8078F784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078F788: bne         $t4, $zero, L_8078F7A4
    if (ctx->r12 != 0) {
        // 0x8078F78C: nop
    
            goto L_8078F7A4;
    }
    // 0x8078F78C: nop

    // 0x8078F790: lbu         $t5, 0x1F9($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X1F9);
    // 0x8078F794: bne         $t5, $zero, L_8078F7A4
    if (ctx->r13 != 0) {
        // 0x8078F798: nop
    
            goto L_8078F7A4;
    }
    // 0x8078F798: nop

    // 0x8078F79C: b           L_8078F7AC
    // 0x8078F7A0: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
        goto L_8078F7AC;
    // 0x8078F7A0: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
L_8078F7A4:
    // 0x8078F7A4: jal         0x8078F584
    // 0x8078F7A8: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    func_8078F584(rdram, ctx);
        goto after_3;
    // 0x8078F7A8: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    after_3:
L_8078F7AC:
    // 0x8078F7AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078F7B0:
    // 0x8078F7B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078F7B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078F7B8: jr          $ra
    // 0x8078F7BC: nop

    return;
    // 0x8078F7BC: nop

;}
RECOMP_FUNC void func_8073A940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073A940: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073A944: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073A948: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073A94C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x8073A950: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8073A954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073A958: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8073A95C: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8073A960: lhu         $t7, 0x1A($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1A);
    // 0x8073A964: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8073A968: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8073A96C: beq         $t7, $zero, L_8073A97C
    if (ctx->r15 == 0) {
        // 0x8073A970: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8073A97C;
    }
    // 0x8073A970: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8073A974: b           L_8073A998
    // 0x8073A978: sh          $zero, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = 0;
        goto L_8073A998;
    // 0x8073A978: sh          $zero, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = 0;
L_8073A97C:
    // 0x8073A97C: bgez        $t8, L_8073A98C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8073A980: sw          $t8, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r24;
            goto L_8073A98C;
    }
    // 0x8073A980: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8073A984: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8073A988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073A98C:
    // 0x8073A98C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8073A990: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x8073A994: sh          $zero, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = 0;
L_8073A998:
    // 0x8073A998: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8073A99C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8073A9A0: jal         0x8005C27C
    // 0x8073A9A4: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x8073A9A4: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    after_0:
    // 0x8073A9A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073A9AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073A9B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073A9B4: jr          $ra
    // 0x8073A9B8: nop

    return;
    // 0x8073A9B8: nop

;}
RECOMP_FUNC void func_804D2B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D2B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D2B14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D2B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D2B1C: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(249, 0X5E0) << 16);
    // 0x804D2B20: lui         $a1, 0x804D
    ctx->r5 = S32(RELOC_HI16(249, 0X5F0) << 16);
    // 0x804D2B24: addiu       $a1, $a1, 0x3100
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(249, 0X5F0));
    // 0x804D2B28: addiu       $a0, $a0, 0x30F0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(249, 0X5E0));
    // 0x804D2B2C: jal         0x8004667C
    // 0x804D2B30: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804D2B30: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x804D2B34: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x804D2B38: lui         $a2, 0x804D
    ctx->r6 = S32(RELOC_HI16(249, 0X388) << 16);
    // 0x804D2B3C: addiu       $a2, $a2, 0x2E98
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(249, 0X388));
    // 0x804D2B40: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x804D2B44: jal         0x80057B28
    // 0x804D2B48: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x804D2B48: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x804D2B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D2B50: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(249, 0X50) << 16);
    // 0x804D2B54: addiu       $v0, $v0, 0x2B60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(249, 0X50));
    // 0x804D2B58: jr          $ra
    // 0x804D2B5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804D2B5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80022E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022E4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80022E50: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80022E54: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80022E58: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80022E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022E60: addiu       $t6, $t6, 0x2E0C
    ctx->r14 = ADD32(ctx->r14, 0X2E0C);
    // 0x80022E64: jalr        $t6
    // 0x80022E68: sw          $t6, 0xAD8($v0)
    MEM_W(0XAD8, ctx->r2) = ctx->r14;
    LOOKUP_FUNC(ctx->r14)(rdram, ctx);
        goto after_0;
    // 0x80022E68: sw          $t6, 0xAD8($v0)
    MEM_W(0XAD8, ctx->r2) = ctx->r14;
    after_0:
    // 0x80022E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022E70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80022E74: jr          $ra
    // 0x80022E78: nop

    return;
    // 0x80022E78: nop

;}
RECOMP_FUNC void func_804E7B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E7B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E7B54: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804E7B58: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804E7B5C: lui         $t8, 0x804E
    ctx->r24 = S32(RELOC_HI16(261, 0X67C) << 16);
    // 0x804E7B60: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804E7B64: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804E7B68: lw          $t8, 0x7EDC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(261, 0X67C));
    // 0x804E7B6C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804E7B70: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804E7B74: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804E7B78: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804E7B7C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804E7B80: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804E7B84: beql        $v1, $zero, L_804E7BB8
    if (ctx->r3 == 0) {
        // 0x804E7B88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804E7BB8;
    }
    goto skip_0;
    // 0x804E7B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804E7B8C: jalr        $v1
    // 0x804E7B90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804E7B90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804E7B94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804E7B98: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804E7B9C: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804E7BA0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804E7BA4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804E7BA8: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804E7BAC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804E7BB0: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804E7BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804E7BB8:
    // 0x804E7BB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E7BBC: jr          $ra
    // 0x804E7BC0: nop

    return;
    // 0x804E7BC0: nop

;}
RECOMP_FUNC void func_80678D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80678D78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80678D7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80678D80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80678D84: jal         0x806785F8
    // 0x80678D88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806785F8(rdram, ctx);
        goto after_0;
    // 0x80678D88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80678D8C: jal         0x80678A9C
    // 0x80678D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80678A9C(rdram, ctx);
        goto after_1;
    // 0x80678D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80678D94: jal         0x80678620
    // 0x80678D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80678620(rdram, ctx);
        goto after_2;
    // 0x80678D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80678D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80678DA0: jal         0x80678868
    // 0x80678DA4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80678868(rdram, ctx);
        goto after_3;
    // 0x80678DA4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x80678DA8: jal         0x806789CC
    // 0x80678DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806789CC(rdram, ctx);
        goto after_4;
    // 0x80678DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80678DB0: jal         0x80678C88
    // 0x80678DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80678C88(rdram, ctx);
        goto after_5;
    // 0x80678DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80678DB8: jal         0x80678CF4
    // 0x80678DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80678CF4(rdram, ctx);
        goto after_6;
    // 0x80678DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80678DC0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80678DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80678DC8: lhu         $t6, 0x424($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X424);
    // 0x80678DCC: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80678DD0: jal         0x80678048
    // 0x80678DD4: sh          $t7, 0x424($v0)
    MEM_H(0X424, ctx->r2) = ctx->r15;
    func_80678048(rdram, ctx);
        goto after_7;
    // 0x80678DD4: sh          $t7, 0x424($v0)
    MEM_H(0X424, ctx->r2) = ctx->r15;
    after_7:
    // 0x80678DD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80678DDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80678DE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80678DE4: jr          $ra
    // 0x80678DE8: nop

    return;
    // 0x80678DE8: nop

;}
RECOMP_FUNC void func_8045EED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045EED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045EED4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8045EED8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8045EEDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045EEE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8045EEE4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8045EEE8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8045EEEC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8045EEF0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8045EEF4: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(110, 0X1290) << 16);
    // 0x8045EEF8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8045EEFC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8045EF00: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8045EF04: lw          $t1, -0x1060($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(110, 0X1290));
    // 0x8045EF08: jal         0x8045EF20
    // 0x8045EF0C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_8045EF20(rdram, ctx);
        goto after_0;
    // 0x8045EF0C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x8045EF10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045EF14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045EF18: jr          $ra
    // 0x8045EF1C: nop

    return;
    // 0x8045EF1C: nop

;}
RECOMP_FUNC void func_807C3194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3194: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x807C3198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807C319C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807C31A0: jal         0x807C2F48
    // 0x807C31A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807C2F48(rdram, ctx);
        goto after_0;
    // 0x807C31A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807C31A8: bnel        $v0, $zero, L_807C32B0
    if (ctx->r2 != 0) {
        // 0x807C31AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807C32B0;
    }
    goto skip_0;
    // 0x807C31AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807C31B0: jal         0x80067E68
    // 0x807C31B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_1;
    // 0x807C31B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x807C31B8: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x807C31BC: jal         0x80067818
    // 0x807C31C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x807C31C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x807C31C4: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x807C31C8: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x807C31CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807C31D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x807C31D4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x807C31D8: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x807C31DC: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(904, 0X410) << 16);
    // 0x807C31E0: lwc1        $f10, 0x3310($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(904, 0X410));
    // 0x807C31E4: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x807C31E8: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x807C31EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C31F0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807C31F4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x807C31F8: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x807C31FC: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x807C3200: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x807C3204: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x807C3208: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x807C320C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x807C3210: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x807C3214: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x807C3218: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x807C321C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x807C3220: lw          $t9, 0x28($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X28);
    // 0x807C3224: jalr        $t9
    // 0x807C3228: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x807C3228: nop

    after_3:
    // 0x807C322C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x807C3230: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x807C3234: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C3238: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x807C323C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x807C3240: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x807C3244: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x807C3248: addiu       $t8, $zero, 0x4034
    ctx->r24 = ADD32(0, 0X4034);
    // 0x807C324C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x807C3250: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x807C3254: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x807C3258: sh          $t8, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r24;
    // 0x807C325C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x807C3260: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x807C3264: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x807C3268: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x807C326C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x807C3270: lw          $t9, 0x54($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X54);
    // 0x807C3274: jalr        $t9
    // 0x807C3278: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x807C3278: nop

    after_4:
    // 0x807C327C: beq         $v0, $zero, L_807C329C
    if (ctx->r2 == 0) {
        // 0x807C3280: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_807C329C;
    }
    // 0x807C3280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807C3284: lw          $a2, 0x1DC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1DC);
    // 0x807C3288: lw          $a1, 0x1D8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1D8);
    // 0x807C328C: jal         0x80048BE8
    // 0x807C3290: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_5;
    // 0x807C3290: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_5:
    // 0x807C3294: b           L_807C32A4
    // 0x807C3298: nop

        goto L_807C32A4;
    // 0x807C3298: nop

L_807C329C:
    // 0x807C329C: jal         0x80048CC0
    // 0x807C32A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048CC0(rdram, ctx);
        goto after_6;
    // 0x807C32A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_807C32A4:
    // 0x807C32A4: jal         0x800447C8
    // 0x807C32A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x807C32A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x807C32AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807C32B0:
    // 0x807C32B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807C32B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x807C32B8: jr          $ra
    // 0x807C32BC: nop

    return;
    // 0x807C32BC: nop

;}
RECOMP_FUNC void func_804C462C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C462C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x804C4630: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x804C4634: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x804C4638: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x804C463C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804C4640: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804C4644: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804C4648: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804C464C: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x804C4650: lw          $t7, 0x1B4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1B4);
    // 0x804C4654: lw          $t6, 0x1CC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1CC);
    // 0x804C4658: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x804C465C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x804C4660: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C4664: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x804C4668: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x804C466C: lw          $v1, 0xB0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB0);
    // 0x804C4670: mflo        $t8
    ctx->r24 = lo;
    // 0x804C4674: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x804C4678: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x804C467C: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x804C4680: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C4684: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x804C4688: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804C468C: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x804C4690: beq         $at, $zero, L_804C46C0
    if (ctx->r1 == 0) {
        // 0x804C4694: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_804C46C0;
    }
    // 0x804C4694: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_804C4698:
    // 0x804C4698: mtc1        $t8, $f26
    ctx->f26.u32l = ctx->r24;
    // 0x804C469C: lwc1        $f24, 0x18($t0)
    ctx->f24.u32l = MEM_W(ctx->r8, 0X18);
    // 0x804C46A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804C46A4: cvt.s.w     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.fl = CVT_S_W(ctx->f26.u32l);
    // 0x804C46A8: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x804C46AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804C46B0: mul.s       $f24, $f26, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x804C46B4: swc1        $f24, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f24.u32l;
    // 0x804C46B8: bne         $at, $zero, L_804C4698
    if (ctx->r1 != 0) {
        // 0x804C46BC: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_804C4698;
    }
    // 0x804C46BC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_804C46C0:
    // 0x804C46C0: mtc1        $t8, $f26
    ctx->f26.u32l = ctx->r24;
    // 0x804C46C4: lwc1        $f24, 0x18($t0)
    ctx->f24.u32l = MEM_W(ctx->r8, 0X18);
    // 0x804C46C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804C46CC: cvt.s.w     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.fl = CVT_S_W(ctx->f26.u32l);
    // 0x804C46D0: mul.s       $f24, $f26, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x804C46D4: swc1        $f24, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f24.u32l;
    // 0x804C46D8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x804C46DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C46E0: lwc1        $f4, 0x18($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X18);
    // 0x804C46E4: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    // 0x804C46E8: sw          $t5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r13;
    // 0x804C46EC: mul.s       $f26, $f4, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804C46F0: jal         0x80066E88
    // 0x804C46F4: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x804C46F4: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    after_0:
    // 0x804C46F8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x804C46FC: jal         0x80066DE4
    // 0x804C4700: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x804C4700: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    after_1:
    // 0x804C4704: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804C4708: jal         0x80049018
    // 0x804C470C: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x804C470C: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x804C4710: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x804C4714: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x804C4718: beq         $v0, $zero, L_804C4728
    if (ctx->r2 == 0) {
        // 0x804C471C: lwc1        $f18, 0x70($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
            goto L_804C4728;
    }
    // 0x804C471C: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x804C4720: b           L_804C4734
    // 0x804C4724: lwc1        $f24, 0x6C($s1)
    ctx->f24.u32l = MEM_W(ctx->r17, 0X6C);
        goto L_804C4734;
    // 0x804C4724: lwc1        $f24, 0x6C($s1)
    ctx->f24.u32l = MEM_W(ctx->r17, 0X6C);
L_804C4728:
    // 0x804C4728: lwc1        $f24, 0x6C($s1)
    ctx->f24.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x804C472C: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
    // 0x804C4730: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = -ctx->f24.fl;
L_804C4734:
    // 0x804C4734: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x804C4738: addiu       $at, $zero, 0x405E
    ctx->r1 = ADD32(0, 0X405E);
    // 0x804C473C: lhu         $t6, 0xC($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0XC);
    // 0x804C4740: bnel        $t6, $at, L_804C4854
    if (ctx->r14 != ctx->r1) {
        // 0x804C4744: lw          $t9, 0x1CC($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X1CC);
            goto L_804C4854;
    }
    goto skip_0;
    // 0x804C4744: lw          $t9, 0x1CC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1CC);
    skip_0:
    // 0x804C4748: lw          $t7, 0x1CC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1CC);
    // 0x804C474C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x804C4750: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x804C4754: blez        $t7, L_804C4968
    if (SIGNED(ctx->r15) <= 0) {
        // 0x804C4758: lw          $t0, 0x88($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X88);
            goto L_804C4968;
    }
    // 0x804C4758: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x804C475C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(209, 0XE7C) << 16);
    // 0x804C4760: lwc1        $f22, 0x4E6C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(209, 0XE7C));
    // 0x804C4764: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C4768: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804C476C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x804C4770: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
L_804C4774:
    // 0x804C4774: lh          $t8, 0x2($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X2);
    // 0x804C4778: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x804C477C: lwc1        $f8, 0x70($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X70);
    // 0x804C4780: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x804C4784: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x804C4788: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x804C478C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804C4790: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804C4794: mul.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x804C4798: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804C479C: mul.s       $f12, $f10, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x804C47A0: nop

    // 0x804C47A4: mul.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x804C47A8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x804C47AC: mul.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x804C47B0: add.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x804C47B4: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x804C47B8: nop

    // 0x804C47BC: mul.s       $f14, $f8, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x804C47C0: c.lt.s      $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f14.fl < ctx->f26.fl;
    // 0x804C47C4: nop

    // 0x804C47C8: bc1f        L_804C4830
    if (!c1cs) {
        // 0x804C47CC: nop
    
            goto L_804C4830;
    }
    // 0x804C47CC: nop

    // 0x804C47D0: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x804C47D4: addu        $t1, $a2, $t3
    ctx->r9 = ADD32(ctx->r6, ctx->r11);
    // 0x804C47D8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804C47DC: bc1fl       L_804C47F0
    if (!c1cs) {
        // 0x804C47E0: div.s       $f0, $f16, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
            goto L_804C47F0;
    }
    goto skip_1;
    // 0x804C47E0: div.s       $f0, $f16, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
    skip_1:
    // 0x804C47E4: b           L_804C47F0
    // 0x804C47E8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804C47F0;
    // 0x804C47E8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804C47EC: div.s       $f0, $f16, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f14.fl);
L_804C47F0:
    // 0x804C47F0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804C47F4: lbu         $t7, 0x1D0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1D0);
    // 0x804C47F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804C47FC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804C4800: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804C4804: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x804C4808: nop

    // 0x804C480C: addu        $a0, $t7, $a1
    ctx->r4 = ADD32(ctx->r15, ctx->r5);
    // 0x804C4810: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x804C4814: bnel        $at, $zero, L_804C4824
    if (ctx->r1 != 0) {
        // 0x804C4818: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_804C4824;
    }
    goto skip_2;
    // 0x804C4818: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x804C481C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x804C4820: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_804C4824:
    // 0x804C4824: bne         $v0, $a3, L_804C47F0
    if (ctx->r2 != ctx->r7) {
        // 0x804C4828: sb          $a0, 0x1CF($v1)
        MEM_B(0X1CF, ctx->r3) = ctx->r4;
            goto L_804C47F0;
    }
    // 0x804C4828: sb          $a0, 0x1CF($v1)
    MEM_B(0X1CF, ctx->r3) = ctx->r4;
    // 0x804C482C: sb          $t4, 0x1D3($t1)
    MEM_B(0X1D3, ctx->r9) = ctx->r12;
L_804C4830:
    // 0x804C4830: lw          $t8, 0x1CC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X1CC);
    // 0x804C4834: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x804C4838: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x804C483C: slt         $at, $t2, $t8
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x804C4840: bne         $at, $zero, L_804C4774
    if (ctx->r1 != 0) {
        // 0x804C4844: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_804C4774;
    }
    // 0x804C4844: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x804C4848: b           L_804C496C
    // 0x804C484C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_804C496C;
    // 0x804C484C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x804C4850: lw          $t9, 0x1CC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1CC);
L_804C4854:
    // 0x804C4854: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x804C4858: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x804C485C: blez        $t9, L_804C4968
    if (SIGNED(ctx->r25) <= 0) {
        // 0x804C4860: lw          $t0, 0x88($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X88);
            goto L_804C4968;
    }
    // 0x804C4860: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x804C4864: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(209, 0XE80) << 16);
    // 0x804C4868: lwc1        $f22, 0x4E70($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(209, 0XE80));
    // 0x804C486C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C4870: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804C4874: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x804C4878: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
L_804C487C:
    // 0x804C487C: lh          $t6, 0x2($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X2);
    // 0x804C4880: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x804C4884: lwc1        $f8, 0x70($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X70);
    // 0x804C4888: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x804C488C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x804C4890: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // 0x804C4894: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804C4898: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804C489C: mul.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x804C48A0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x804C48A4: mul.s       $f12, $f4, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x804C48A8: nop

    // 0x804C48AC: mul.s       $f6, $f12, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x804C48B0: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x804C48B4: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x804C48B8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804C48BC: mul.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x804C48C0: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x804C48C4: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x804C48C8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x804C48CC: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x804C48D0: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x804C48D4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x804C48D8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x804C48DC: mul.s       $f2, $f10, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x804C48E0: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x804C48E4: nop

    // 0x804C48E8: bc1f        L_804C4950
    if (!c1cs) {
        // 0x804C48EC: nop
    
            goto L_804C4950;
    }
    // 0x804C48EC: nop

    // 0x804C48F0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x804C48F4: addu        $t1, $a2, $t3
    ctx->r9 = ADD32(ctx->r6, ctx->r11);
    // 0x804C48F8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804C48FC: bc1fl       L_804C4910
    if (!c1cs) {
        // 0x804C4900: div.s       $f0, $f16, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
            goto L_804C4910;
    }
    goto skip_3;
    // 0x804C4900: div.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    skip_3:
    // 0x804C4904: b           L_804C4910
    // 0x804C4908: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804C4910;
    // 0x804C4908: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804C490C: div.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
L_804C4910:
    // 0x804C4910: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804C4914: lbu         $t9, 0x1D0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1D0);
    // 0x804C4918: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804C491C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804C4920: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804C4924: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x804C4928: nop

    // 0x804C492C: addu        $a0, $t9, $a1
    ctx->r4 = ADD32(ctx->r25, ctx->r5);
    // 0x804C4930: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x804C4934: bnel        $at, $zero, L_804C4944
    if (ctx->r1 != 0) {
        // 0x804C4938: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_804C4944;
    }
    goto skip_4;
    // 0x804C4938: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_4:
    // 0x804C493C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x804C4940: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_804C4944:
    // 0x804C4944: bne         $v0, $a3, L_804C4910
    if (ctx->r2 != ctx->r7) {
        // 0x804C4948: sb          $a0, 0x1CF($v1)
        MEM_B(0X1CF, ctx->r3) = ctx->r4;
            goto L_804C4910;
    }
    // 0x804C4948: sb          $a0, 0x1CF($v1)
    MEM_B(0X1CF, ctx->r3) = ctx->r4;
    // 0x804C494C: sb          $t4, 0x1D3($t1)
    MEM_B(0X1D3, ctx->r9) = ctx->r12;
L_804C4950:
    // 0x804C4950: lw          $t6, 0x1CC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1CC);
    // 0x804C4954: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x804C4958: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x804C495C: slt         $at, $t2, $t6
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x804C4960: bne         $at, $zero, L_804C487C
    if (ctx->r1 != 0) {
        // 0x804C4964: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_804C487C;
    }
    // 0x804C4964: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
L_804C4968:
    // 0x804C4968: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_804C496C:
    // 0x804C496C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804C4970: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804C4974: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804C4978: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804C497C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x804C4980: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x804C4984: jr          $ra
    // 0x804C4988: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x804C4988: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_8045A830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045A830: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8045A834: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045A838: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045A83C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8045A840: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x8045A844: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8045A848: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8045A84C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045A850: jal         0x8045A944
    // 0x8045A854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8045A944(rdram, ctx);
        goto after_0;
    // 0x8045A854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8045A858: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8045A85C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8045A860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8045A864: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x8045A868: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8045A86C: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(101, 0X2B8) << 16);
    // 0x8045A870: addiu       $t7, $t7, -0x58B8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(101, 0X2B8));
    // 0x8045A874: sw          $t7, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r15;
    // 0x8045A878: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x8045A87C: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(101, 0X4F8) << 16);
    // 0x8045A880: addiu       $t9, $t9, -0x5678
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(101, 0X4F8));
    // 0x8045A884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045A888: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8045A88C: jal         0x80045A34
    // 0x8045A890: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8045A890: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    after_1:
    // 0x8045A894: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(101, 0X370) << 16);
    // 0x8045A898: addiu       $t1, $t1, -0x5800
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(101, 0X370));
    // 0x8045A89C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8045A8A0: sw          $t1, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r9;
    // 0x8045A8A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8045A8A8: jal         0x80064D1C
    // 0x8045A8AC: addiu       $a0, $zero, 0x1C20
    ctx->r4 = ADD32(0, 0X1C20);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x8045A8AC: addiu       $a0, $zero, 0x1C20
    ctx->r4 = ADD32(0, 0X1C20);
    after_2:
    // 0x8045A8B0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8045A8B4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8045A8B8: jal         0x80064D1C
    // 0x8045A8BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    func_80064D1C(rdram, ctx);
        goto after_3;
    // 0x8045A8BC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    after_3:
    // 0x8045A8C0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8045A8C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8045A8C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8045A8CC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8045A8D0: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8045A8D4: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8045A8D8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8045A8DC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8045A8E0: sh          $zero, 0x2($t3)
    MEM_H(0X2, ctx->r11) = 0;
L_8045A8E4:
    // 0x8045A8E4: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x8045A8E8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8045A8EC: sh          $zero, 0x0($t5)
    MEM_H(0X0, ctx->r13) = 0;
    // 0x8045A8F0: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8045A8F4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8045A8F8: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x8045A8FC: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8045A900: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8045A904: sh          $zero, 0x4($t9)
    MEM_H(0X4, ctx->r25) = 0;
    // 0x8045A908: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8045A90C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8045A910: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8045A914: bne         $v0, $a0, L_8045A8E4
    if (ctx->r2 != ctx->r4) {
        // 0x8045A918: sh          $zero, 0x6($t1)
        MEM_H(0X6, ctx->r9) = 0;
            goto L_8045A8E4;
    }
    // 0x8045A918: sh          $zero, 0x6($t1)
    MEM_H(0X6, ctx->r9) = 0;
    // 0x8045A91C: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8045A920: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8045A924: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x8045A928: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x8045A92C: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    // 0x8045A930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8045A934: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045A938: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8045A93C: jr          $ra
    // 0x8045A940: nop

    return;
    // 0x8045A940: nop

;}
RECOMP_FUNC void func_806D0828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D082C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D0830: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D0834: jal         0x80045A34
    // 0x806D0838: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806D0838: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x806D083C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D0840: bne         $v0, $zero, L_806D0850
    if (ctx->r2 != 0) {
        // 0x806D0844: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806D0850;
    }
    // 0x806D0844: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806D0848: b           L_806D085C
    // 0x806D084C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D085C;
    // 0x806D084C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D0850:
    // 0x806D0850: jal         0x806D07F8
    // 0x806D0854: nop

    func_806D07F8(rdram, ctx);
        goto after_1;
    // 0x806D0854: nop

    after_1:
    // 0x806D0858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806D085C:
    // 0x806D085C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D0860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D0864: jr          $ra
    // 0x806D0868: nop

    return;
    // 0x806D0868: nop

;}
RECOMP_FUNC void func_8057FC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057FC78: jr          $ra
    // 0x8057FC7C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8057FC7C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800663F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800663F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800663F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800663FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066400: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x80066404: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x80066408: swc1        $f2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f2.u32l;
    // 0x8006640C: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x80066410: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x80066414: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x80066418: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8006641C: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80066420: jr          $ra
    // 0x80066424: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80066424: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8078E4A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078E4A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078E4A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078E4AC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078E4B0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8078E4B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8078E4B8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8078E4BC: beq         $v1, $zero, L_8078E4CC
    if (ctx->r3 == 0) {
        // 0x8078E4C0: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8078E4CC;
    }
    // 0x8078E4C0: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8078E4C4: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8078E4C8: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8078E4CC:
    // 0x8078E4CC: bne         $v1, $zero, L_8078E4F0
    if (ctx->r3 != 0) {
        // 0x8078E4D0: nop
    
            goto L_8078E4F0;
    }
    // 0x8078E4D0: nop

    // 0x8078E4D4: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8078E4D8: lh          $t8, 0x144($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X144);
    // 0x8078E4DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8078E4E0: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x8078E4E4: lh          $t0, 0x144($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X144);
    // 0x8078E4E8: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x8078E4EC: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
L_8078E4F0:
    // 0x8078E4F0: jal         0x8078E35C
    // 0x8078E4F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8078E35C(rdram, ctx);
        goto after_0;
    // 0x8078E4F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078E4F8: jal         0x8078DF30
    // 0x8078E4FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8078DF30(rdram, ctx);
        goto after_1;
    // 0x8078E4FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8078E500: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x8078E504: lw          $t2, -0x72B0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X72B0);
    // 0x8078E508: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078E50C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078E510: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8078E514: beql        $t3, $zero, L_8078E528
    if (ctx->r11 == 0) {
        // 0x8078E518: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078E528;
    }
    goto skip_0;
    // 0x8078E518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8078E51C: jal         0x8078E918
    // 0x8078E520: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8078E918(rdram, ctx);
        goto after_2;
    // 0x8078E520: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8078E524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078E528:
    // 0x8078E528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078E52C: jr          $ra
    // 0x8078E530: nop

    return;
    // 0x8078E530: nop

;}
RECOMP_FUNC void func_806D099C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D099C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D09A0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x806D09A4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806D09A8: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x806D09AC: bne         $at, $zero, L_806D09FC
    if (ctx->r1 != 0) {
        // 0x806D09B0: sw          $t7, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r15;
            goto L_806D09FC;
    }
    // 0x806D09B0: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x806D09B4: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x806D09B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806D09BC: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x806D09C0: bnel        $v1, $t9, L_806D09EC
    if (ctx->r3 != ctx->r25) {
        // 0x806D09C4: lw          $t4, 0xC($v0)
        ctx->r12 = MEM_W(ctx->r2, 0XC);
            goto L_806D09EC;
    }
    goto skip_0;
    // 0x806D09C4: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x806D09C8: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x806D09CC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x806D09D0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x806D09D4: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x806D09D8: bne         $at, $zero, L_806D09FC
    if (ctx->r1 != 0) {
        // 0x806D09DC: sw          $t1, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r9;
            goto L_806D09FC;
    }
    // 0x806D09DC: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x806D09E0: jr          $ra
    // 0x806D09E4: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    return;
    // 0x806D09E4: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x806D09E8: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
L_806D09EC:
    // 0x806D09EC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x806D09F0: bgtz        $t5, L_806D09FC
    if (SIGNED(ctx->r13) > 0) {
        // 0x806D09F4: sw          $t5, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r13;
            goto L_806D09FC;
    }
    // 0x806D09F4: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x806D09F8: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
L_806D09FC:
    // 0x806D09FC: jr          $ra
    // 0x806D0A00: nop

    return;
    // 0x806D0A00: nop

;}
RECOMP_FUNC void func_807B97AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B97AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B97B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B97B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B97B8: jal         0x807B8D30
    // 0x807B97BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807B8D30(rdram, ctx);
        goto after_0;
    // 0x807B97BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807B97C0: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x807B97C4: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x807B97C8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x807B97CC: addiu       $a0, $zero, 0x203
    ctx->r4 = ADD32(0, 0X203);
    // 0x807B97D0: lhu         $v0, 0xC($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0XC);
    // 0x807B97D4: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x807B97D8: bne         $t7, $at, L_807B9830
    if (ctx->r15 != ctx->r1) {
        // 0x807B97DC: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_807B9830;
    }
    // 0x807B97DC: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x807B97E0: jal         0x80067818
    // 0x807B97E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807B97E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x807B97E8: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x807B97EC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B97F0: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x807B97F4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B97F8: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x807B97FC: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x807B9800: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9804: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x807B9808: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
    // 0x807B980C: jal         0x807B8F9C
    // 0x807B9810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B8F9C(rdram, ctx);
        goto after_2;
    // 0x807B9810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807B9814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B9818: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B981C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B9820: jal         0x807B9E2C
    // 0x807B9824: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_807B9E2C(rdram, ctx);
        goto after_3;
    // 0x807B9824: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x807B9828: b           L_807B988C
    // 0x807B982C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807B988C;
    // 0x807B982C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B9830:
    // 0x807B9830: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x807B9834: bnel        $t1, $at, L_807B988C
    if (ctx->r9 != ctx->r1) {
        // 0x807B9838: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807B988C;
    }
    goto skip_0;
    // 0x807B9838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807B983C: jal         0x807B8FC0
    // 0x807B9840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B8FC0(rdram, ctx);
        goto after_4;
    // 0x807B9840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807B9844: addiu       $a0, $zero, 0x205
    ctx->r4 = ADD32(0, 0X205);
    // 0x807B9848: jal         0x80067818
    // 0x807B984C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x807B984C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x807B9850: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x807B9854: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9858: sb          $t2, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r10;
    // 0x807B985C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B9860: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x807B9864: sb          $t3, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r11;
    // 0x807B9868: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B986C: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x807B9870: sb          $t4, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r12;
    // 0x807B9874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B9878: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B987C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B9880: jal         0x807B9E2C
    // 0x807B9884: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_807B9E2C(rdram, ctx);
        goto after_6;
    // 0x807B9884: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_6:
    // 0x807B9888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807B988C:
    // 0x807B988C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B9890: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B9894: jr          $ra
    // 0x807B9898: nop

    return;
    // 0x807B9898: nop

;}
RECOMP_FUNC void func_80408564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80408564: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80408568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040856C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80408570: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80408574: beq         $v0, $zero, L_80408598
    if (ctx->r2 == 0) {
        // 0x80408578: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80408598;
    }
    // 0x80408578: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8040857C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80408580: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80408584: jal         0x804082B0
    // 0x80408588: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_804082B0(rdram, ctx);
        goto after_0;
    // 0x80408588: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8040858C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80408590: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80408594: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80408598:
    // 0x80408598: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E0C) << 16);
    // 0x8040859C: lwc1        $f6, -0x5824($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E0C));
    // 0x804085A0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804085A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804085A8: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x804085AC: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804085B0: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x804085B4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x804085B8: nop

    // 0x804085BC: bc1fl       L_804085CC
    if (!c1cs) {
        // 0x804085C0: lwc1        $f16, 0x8($a1)
        ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
            goto L_804085CC;
    }
    goto skip_0;
    // 0x804085C0: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    skip_0:
    // 0x804085C4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x804085C8: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
L_804085CC:
    // 0x804085CC: jal         0x8040A470
    // 0x804085D0: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    func_8040A470(rdram, ctx);
        goto after_1;
    // 0x804085D0: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    after_1:
    // 0x804085D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804085D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804085DC: jr          $ra
    // 0x804085E0: nop

    return;
    // 0x804085E0: nop

;}
RECOMP_FUNC void func_80519DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519DEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519DF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80519DF4: jal         0x80045A34
    // 0x80519DF8: addiu       $a1, $zero, 0x20C
    ctx->r5 = ADD32(0, 0X20C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80519DF8: addiu       $a1, $zero, 0x20C
    ctx->r5 = ADD32(0, 0X20C);
    after_0:
    // 0x80519DFC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80519E00: addiu       $a1, $zero, 0x20C
    ctx->r5 = ADD32(0, 0X20C);
    // 0x80519E04: bne         $v0, $zero, L_80519E1C
    if (ctx->r2 != 0) {
        // 0x80519E08: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_80519E1C;
    }
    // 0x80519E08: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x80519E0C: jal         0x800445A4
    // 0x80519E10: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80519E10: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x80519E14: b           L_80519E2C
    // 0x80519E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80519E2C;
    // 0x80519E18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80519E1C:
    // 0x80519E1C: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x80519E20: jal         0x80065728
    // 0x80519E24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x80519E24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80519E28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80519E2C:
    // 0x80519E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80519E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519E34: jr          $ra
    // 0x80519E38: nop

    return;
    // 0x80519E38: nop

;}
RECOMP_FUNC void func_80436044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436044: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80436048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043604C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80436050: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80436054: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80436058: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8043605C: addiu       $t7, $v0, 0x740
    ctx->r15 = ADD32(ctx->r2, 0X740);
    // 0x80436060: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80436064: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80436068: jal         0x80436024
    // 0x8043606C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80436024(rdram, ctx);
        goto after_0;
    // 0x8043606C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80436070: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80436074: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80436078: lui         $t9, 0x8043
    ctx->r25 = S32(RELOC_HI16(71, 0X21D8) << 16);
    // 0x8043607C: sw          $t8, 0xE80($v0)
    MEM_W(0XE80, ctx->r2) = ctx->r24;
    // 0x80436080: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80436084: addiu       $t9, $t9, 0x5C88
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(71, 0X21D8));
    // 0x80436088: lw          $t1, 0x16C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X16C);
    // 0x8043608C: sw          $t9, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r25;
    // 0x80436090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80436094: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80436098: jr          $ra
    // 0x8043609C: nop

    return;
    // 0x8043609C: nop

;}
RECOMP_FUNC void func_8003B004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B00C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8003B010: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8003B014: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8003B018: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8003B01C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8003B020: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8003B024: addiu       $t7, $t7, -0x1400
    ctx->r15 = ADD32(ctx->r15, -0X1400);
    // 0x8003B028: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8003B02C: jal         0x8003AF20
    // 0x8003B030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003AF20(rdram, ctx);
        goto after_0;
    // 0x8003B030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B038: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8003B03C: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8003B040: addiu       $t9, $t9, -0x5A14
    ctx->r25 = ADD32(ctx->r25, -0X5A14);
    // 0x8003B044: addiu       $t0, $t0, -0x5314
    ctx->r8 = ADD32(ctx->r8, -0X5314);
    // 0x8003B048: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003B04C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003B050: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x8003B054: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x8003B058: jal         0x8004A498
    // 0x8003B05C: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    func_8004A498(rdram, ctx);
        goto after_1;
    // 0x8003B05C: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    after_1:
    // 0x8003B060: jal         0x8003AF90
    // 0x8003B064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003AF90(rdram, ctx);
        goto after_2;
    // 0x8003B064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8003B068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B06C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B070: jr          $ra
    // 0x8003B074: nop

    return;
    // 0x8003B074: nop

;}
RECOMP_FUNC void func_806E7728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7728: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806E772C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E7730: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E7734: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806E7738: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(664, 0XEF0) << 16);
    // 0x806E773C: lwc1        $f8, -0x7ED0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(664, 0XEF0));
    // 0x806E7740: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x806E7744: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806E7748: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E774C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x806E7750: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x806E7754: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806E7758: jal         0x80067BBC
    // 0x806E775C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806E775C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806E7760: addiu       $a0, $zero, 0x1F9
    ctx->r4 = ADD32(0, 0X1F9);
    // 0x806E7764: jal         0x80067818
    // 0x806E7768: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806E7768: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806E776C: jal         0x806E7328
    // 0x806E7770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E7328(rdram, ctx);
        goto after_2;
    // 0x806E7770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806E7774: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806E7778: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x806E777C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x806E7780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806E7784: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806E7788: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806E778C: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x806E7790: jalr        $t9
    // 0x806E7794: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x806E7794: nop

    after_3:
    // 0x806E7798: jal         0x800447C8
    // 0x806E779C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x806E779C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806E77A0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x806E77A4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x806E77A8: lw          $t8, 0xAB8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XAB8);
    // 0x806E77AC: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x806E77B0: jal         0x80049624
    // 0x806E77B4: sw          $t0, 0xAB8($v0)
    MEM_W(0XAB8, ctx->r2) = ctx->r8;
    func_80049624(rdram, ctx);
        goto after_5;
    // 0x806E77B4: sw          $t0, 0xAB8($v0)
    MEM_W(0XAB8, ctx->r2) = ctx->r8;
    after_5:
    // 0x806E77B8: jal         0x8002B428
    // 0x806E77BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_8002B428(rdram, ctx);
        goto after_6;
    // 0x806E77BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_6:
    // 0x806E77C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806E77C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E77C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806E77CC: jr          $ra
    // 0x806E77D0: nop

    return;
    // 0x806E77D0: nop

;}
RECOMP_FUNC void func_80021DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021DB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80021DBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80021DC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80021DC4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80021DC8: lbu         $t6, 0x1AD($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1AD);
    // 0x80021DCC: beql        $t6, $zero, L_80021E7C
    if (ctx->r14 == 0) {
        // 0x80021DD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80021E7C;
    }
    goto skip_0;
    // 0x80021DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80021DD4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80021DD8: lbu         $t8, 0x12($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X12);
    // 0x80021DDC: bnel        $t8, $zero, L_80021E7C
    if (ctx->r24 != 0) {
        // 0x80021DE0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80021E7C;
    }
    goto skip_1;
    // 0x80021DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80021DE4: lw          $v0, 0x1B0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1B0);
    // 0x80021DE8: bne         $v0, $zero, L_80021E74
    if (ctx->r2 != 0) {
        // 0x80021DEC: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80021E74;
    }
    // 0x80021DEC: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80021DF0: lh          $t9, 0x1AE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1AE);
    // 0x80021DF4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80021DF8: beql        $t9, $zero, L_80021E34
    if (ctx->r25 == 0) {
        // 0x80021DFC: lwc1        $f4, 0x54($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
            goto L_80021E34;
    }
    goto skip_2;
    // 0x80021DFC: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    skip_2:
    // 0x80021E00: jal         0x80021C88
    // 0x80021E04: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80021C88(rdram, ctx);
        goto after_0;
    // 0x80021E04: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80021E08: beql        $v0, $zero, L_80021E7C
    if (ctx->r2 == 0) {
        // 0x80021E0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80021E7C;
    }
    goto skip_3;
    // 0x80021E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80021E10: lh          $t0, 0x1AE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1AE);
    // 0x80021E14: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80021E18: jal         0x800653D8
    // 0x80021E1C: sh          $t1, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r9;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x80021E1C: sh          $t1, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r9;
    after_1:
    // 0x80021E20: andi        $t2, $v0, 0x3
    ctx->r10 = ctx->r2 & 0X3;
    // 0x80021E24: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x80021E28: b           L_80021E78
    // 0x80021E2C: sw          $t3, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r11;
        goto L_80021E78;
    // 0x80021E2C: sw          $t3, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r11;
    // 0x80021E30: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
L_80021E34:
    // 0x80021E34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80021E38: nop

    // 0x80021E3C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80021E40: nop

    // 0x80021E44: bc1fl       L_80021E7C
    if (!c1cs) {
        // 0x80021E48: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80021E7C;
    }
    goto skip_4;
    // 0x80021E48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80021E4C: jal         0x800653D8
    // 0x80021E50: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x80021E50: nop

    after_2:
    // 0x80021E54: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x80021E58: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80021E5C: jal         0x800653D8
    // 0x80021E60: sh          $t5, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r13;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x80021E60: sh          $t5, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r13;
    after_3:
    // 0x80021E64: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80021E68: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x80021E6C: b           L_80021E78
    // 0x80021E70: sw          $t7, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r15;
        goto L_80021E78;
    // 0x80021E70: sw          $t7, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r15;
L_80021E74:
    // 0x80021E74: sw          $t8, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r24;
L_80021E78:
    // 0x80021E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80021E7C:
    // 0x80021E7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021E80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80021E84: jr          $ra
    // 0x80021E88: nop

    return;
    // 0x80021E88: nop

;}
RECOMP_FUNC void func_80675268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067526C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80675270: jal         0x806751EC
    // 0x80675274: nop

    func_806751EC(rdram, ctx);
        goto after_0;
    // 0x80675274: nop

    after_0:
    // 0x80675278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067527C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80675280: jr          $ra
    // 0x80675284: nop

    return;
    // 0x80675284: nop

;}
RECOMP_FUNC void func_80067ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067ED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067EE0: jal         0x80067C68
    // 0x80067EE4: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    func_80067C68(rdram, ctx);
        goto after_0;
    // 0x80067EE4: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    after_0:
    // 0x80067EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067EF0: jr          $ra
    // 0x80067EF4: nop

    return;
    // 0x80067EF4: nop

;}
RECOMP_FUNC void func_805AC088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC088: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805AC08C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x805AC090: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805AC094: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x805AC098: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x805AC09C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x805AC0A0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x805AC0A4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x805AC0A8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x805AC0AC: lui         $t9, 0x805B
    ctx->r25 = S32(RELOC_HI16(438, 0X548) << 16);
    // 0x805AC0B0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805AC0B4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805AC0B8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805AC0BC: lw          $t9, -0x3F28($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(438, 0X548));
    // 0x805AC0C0: jr          $ra
    // 0x805AC0C4: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    return;
    // 0x805AC0C4: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x805AC0C8: nop

    // 0x805AC0CC: nop

;}
RECOMP_FUNC void func_8001FA34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FA34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FA38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FA3C: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x8001FA40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FA44: beq         $v0, $at, L_8001FA6C
    if (ctx->r2 == ctx->r1) {
        // 0x8001FA48: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001FA6C;
    }
    // 0x8001FA48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001FA4C: beq         $v0, $at, L_8001FA6C
    if (ctx->r2 == ctx->r1) {
        // 0x8001FA50: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8001FA6C;
    }
    // 0x8001FA50: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8001FA54: beq         $v0, $at, L_8001FA6C
    if (ctx->r2 == ctx->r1) {
        // 0x8001FA58: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8001FA6C;
    }
    // 0x8001FA58: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8001FA5C: beq         $v0, $at, L_8001FA6C
    if (ctx->r2 == ctx->r1) {
        // 0x8001FA60: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8001FA6C;
    }
    // 0x8001FA60: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001FA64: bnel        $v0, $at, L_8001FB0C
    if (ctx->r2 != ctx->r1) {
        // 0x8001FA68: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FB0C;
    }
    goto skip_0;
    // 0x8001FA68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_8001FA6C:
    // 0x8001FA6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001FA70: lbu         $t6, 0xF4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF4);
    // 0x8001FA74: beql        $t6, $zero, L_8001FAA8
    if (ctx->r14 == 0) {
        // 0x8001FA78: lw          $t8, 0x3C($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X3C);
            goto L_8001FAA8;
    }
    goto skip_1;
    // 0x8001FA78: lw          $t8, 0x3C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3C);
    skip_1:
    // 0x8001FA7C: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8001FA80: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x8001FA84: beql        $t7, $at, L_8001FAA8
    if (ctx->r15 == ctx->r1) {
        // 0x8001FA88: lw          $t8, 0x3C($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X3C);
            goto L_8001FAA8;
    }
    goto skip_2;
    // 0x8001FA88: lw          $t8, 0x3C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3C);
    skip_2:
    // 0x8001FA8C: jal         0x80022594
    // 0x8001FA90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80022594(rdram, ctx);
        goto after_0;
    // 0x8001FA90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001FA94: jal         0x8002E290
    // 0x8001FA98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002E290(rdram, ctx);
        goto after_1;
    // 0x8001FA98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8001FA9C: b           L_8001FB0C
    // 0x8001FAA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001FB0C;
    // 0x8001FAA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001FAA4: lw          $t8, 0x3C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3C);
L_8001FAA8:
    // 0x8001FAA8: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x8001FAAC: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8001FAB0: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x8001FAB4: beq         $t9, $zero, L_8001FAF0
    if (ctx->r25 == 0) {
        // 0x8001FAB8: nop
    
            goto L_8001FAF0;
    }
    // 0x8001FAB8: nop

    // 0x8001FABC: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x8001FAC0: andi        $t1, $t0, 0x700
    ctx->r9 = ctx->r8 & 0X700;
    // 0x8001FAC4: bne         $t1, $zero, L_8001FAF0
    if (ctx->r9 != 0) {
        // 0x8001FAC8: nop
    
            goto L_8001FAF0;
    }
    // 0x8001FAC8: nop

    // 0x8001FACC: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8001FAD0: beq         $v1, $at, L_8001FAE0
    if (ctx->r3 == ctx->r1) {
        // 0x8001FAD4: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_8001FAE0;
    }
    // 0x8001FAD4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8001FAD8: bnel        $v1, $at, L_8001FB0C
    if (ctx->r3 != ctx->r1) {
        // 0x8001FADC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FB0C;
    }
    goto skip_3;
    // 0x8001FADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
L_8001FAE0:
    // 0x8001FAE0: jal         0x8002E428
    // 0x8001FAE4: nop

    func_8002E428(rdram, ctx);
        goto after_2;
    // 0x8001FAE4: nop

    after_2:
    // 0x8001FAE8: b           L_8001FB0C
    // 0x8001FAEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001FB0C;
    // 0x8001FAEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001FAF0:
    // 0x8001FAF0: bnel        $v1, $at, L_8001FB0C
    if (ctx->r3 != ctx->r1) {
        // 0x8001FAF4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FB0C;
    }
    goto skip_4;
    // 0x8001FAF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8001FAF8: jal         0x8002E428
    // 0x8001FAFC: nop

    func_8002E428(rdram, ctx);
        goto after_3;
    // 0x8001FAFC: nop

    after_3:
    // 0x8001FB00: b           L_8001FB0C
    // 0x8001FB04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001FB0C;
    // 0x8001FB04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001FB08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001FB0C:
    // 0x8001FB0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FB10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FB14: jr          $ra
    // 0x8001FB18: nop

    return;
    // 0x8001FB18: nop

;}
RECOMP_FUNC void func_80682E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682E34: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682E38: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682E3C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682E40: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682E44: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682E48: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682E4C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682E50: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682E54: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682E58: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682E5C: jr          $ra
    // 0x80682E60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682E60: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80664E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80664E18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80664E1C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80664E20: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80664E24: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80664E28: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80664E2C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80664E30: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80664E34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80664E38: jal         0x80665030
    // 0x80664E3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80665030(rdram, ctx);
        goto after_0;
    // 0x80664E3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80664E40: beq         $v0, $zero, L_80664FDC
    if (ctx->r2 == 0) {
        // 0x80664E44: nop
    
            goto L_80664FDC;
    }
    // 0x80664E44: nop

    // 0x80664E48: jal         0x80665068
    // 0x80664E4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80665068(rdram, ctx);
        goto after_1;
    // 0x80664E4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80664E50: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80664E54: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80664E58: addiu       $t7, $zero, 0x7D
    ctx->r15 = ADD32(0, 0X7D);
    // 0x80664E5C: sw          $t6, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->r14;
    // 0x80664E60: sw          $zero, 0x24($s3)
    MEM_W(0X24, ctx->r19) = 0;
    // 0x80664E64: sb          $zero, 0x165($s3)
    MEM_B(0X165, ctx->r19) = 0;
    // 0x80664E68: sw          $zero, 0x138($s3)
    MEM_W(0X138, ctx->r19) = 0;
    // 0x80664E6C: sw          $t7, 0x1E0($s3)
    MEM_W(0X1E0, ctx->r19) = ctx->r15;
    // 0x80664E70: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80664E74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80664E78: jal         0x8066622C
    // 0x80664E7C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8066622C(rdram, ctx);
        goto after_2;
    // 0x80664E7C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80664E80: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80664E84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80664E88: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D70) << 16);
    // 0x80664E8C: lw          $s4, 0x1F4($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X1F4);
    // 0x80664E90: swc1        $f4, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f4.u32l;
    // 0x80664E94: lwc1        $f6, 0x7A40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D70));
    // 0x80664E98: lui         $t9, 0x8066
    ctx->r25 = S32(RELOC_HI16(504, 0X120) << 16);
    // 0x80664E9C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80664EA0: addiu       $t9, $t9, 0x4DF0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(504, 0X120));
    // 0x80664EA4: sh          $t8, 0x1F0($s3)
    MEM_H(0X1F0, ctx->r19) = ctx->r24;
    // 0x80664EA8: sw          $t9, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r25;
    // 0x80664EAC: swc1        $f6, 0xEC($s3)
    MEM_W(0XEC, ctx->r19) = ctx->f6.u32l;
    // 0x80664EB0: lw          $t0, 0xC($s4)
    ctx->r8 = MEM_W(ctx->r20, 0XC);
    // 0x80664EB4: lui         $t2, 0x8066
    ctx->r10 = S32(RELOC_HI16(504, 0X2768) << 16);
    // 0x80664EB8: addiu       $t2, $t2, 0x7438
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(504, 0X2768));
    // 0x80664EBC: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80664EC0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80664EC4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80664EC8: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x80664ECC: addiu       $s5, $s3, 0x6C
    ctx->r21 = ADD32(ctx->r19, 0X6C);
    // 0x80664ED0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80664ED4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80664ED8: jal         0x806670A8
    // 0x80664EDC: lw          $a2, 0x138($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X138);
    func_806670A8(rdram, ctx);
        goto after_3;
    // 0x80664EDC: lw          $a2, 0x138($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X138);
    after_3:
    // 0x80664EE0: bne         $v0, $zero, L_80664F20
    if (ctx->r2 != 0) {
        // 0x80664EE4: sw          $v0, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r2;
            goto L_80664F20;
    }
    // 0x80664EE4: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80664EE8: jal         0x800445A4
    // 0x80664EEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x80664EEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x80664EF0: jal         0x800677F8
    // 0x80664EF4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800677F8(rdram, ctx);
        goto after_5;
    // 0x80664EF4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_5:
    // 0x80664EF8: jal         0x8004700C
    // 0x80664EFC: nop

    func_8004700C(rdram, ctx);
        goto after_6;
    // 0x80664EFC: nop

    after_6:
    // 0x80664F00: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80664F04: lw          $t9, -0x7288($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7288);
    // 0x80664F08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80664F0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80664F10: jalr        $t9
    // 0x80664F14: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80664F14: nop

    after_7:
    // 0x80664F18: b           L_80665010
    // 0x80664F1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80665010;
    // 0x80664F1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80664F20:
    // 0x80664F20: jal         0x8005FCA8
    // 0x80664F24: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    func_8005FCA8(rdram, ctx);
        goto after_8;
    // 0x80664F24: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_8:
    // 0x80664F28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80664F2C: jal         0x80047F9C
    // 0x80664F30: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x80664F30: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    after_9:
    // 0x80664F34: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
    // 0x80664F38: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x80664F3C: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x80664F40: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80664F44:
    // 0x80664F44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80664F48: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80664F4C: jal         0x806662F4
    // 0x80664F50: lw          $a2, 0x138($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X138);
    func_806662F4(rdram, ctx);
        goto after_10;
    // 0x80664F50: lw          $a2, 0x138($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X138);
    after_10:
    // 0x80664F54: bne         $v0, $zero, L_80664F94
    if (ctx->r2 != 0) {
        // 0x80664F58: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80664F94;
    }
    // 0x80664F58: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80664F5C: jal         0x800445A4
    // 0x80664F60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800445A4(rdram, ctx);
        goto after_11;
    // 0x80664F60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x80664F64: jal         0x800677F8
    // 0x80664F68: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800677F8(rdram, ctx);
        goto after_12;
    // 0x80664F68: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_12:
    // 0x80664F6C: jal         0x8004700C
    // 0x80664F70: nop

    func_8004700C(rdram, ctx);
        goto after_13;
    // 0x80664F70: nop

    after_13:
    // 0x80664F74: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80664F78: lw          $t9, -0x7288($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7288);
    // 0x80664F7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80664F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80664F84: jalr        $t9
    // 0x80664F88: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x80664F88: nop

    after_14:
    // 0x80664F8C: b           L_80665010
    // 0x80664F90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80665010;
    // 0x80664F90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80664F94:
    // 0x80664F94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80664F98: jal         0x80047F9C
    // 0x80664F9C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_15;
    // 0x80664F9C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_15:
    // 0x80664FA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80664FA4: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x80664FA8: bne         $s1, $s4, L_80664F44
    if (ctx->r17 != ctx->r20) {
        // 0x80664FAC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80664F44;
    }
    // 0x80664FAC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80664FB0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80664FB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80664FB8: lwc1        $f8, 0x3C($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x80664FBC: lui         $at, 0x43BC
    ctx->r1 = S32(0X43BC << 16);
    // 0x80664FC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80664FC4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80664FC8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80664FCC: swc1        $f18, 0x40($s3)
    MEM_W(0X40, ctx->r19) = ctx->f18.u32l;
    // 0x80664FD0: swc1        $f16, 0x3C($s3)
    MEM_W(0X3C, ctx->r19) = ctx->f16.u32l;
    // 0x80664FD4: b           L_8066500C
    // 0x80664FD8: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
        goto L_8066500C;
    // 0x80664FD8: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
L_80664FDC:
    // 0x80664FDC: jal         0x800445A4
    // 0x80664FE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800445A4(rdram, ctx);
        goto after_16;
    // 0x80664FE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_16:
    // 0x80664FE4: jal         0x800677F8
    // 0x80664FE8: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800677F8(rdram, ctx);
        goto after_17;
    // 0x80664FE8: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_17:
    // 0x80664FEC: jal         0x8004700C
    // 0x80664FF0: nop

    func_8004700C(rdram, ctx);
        goto after_18;
    // 0x80664FF0: nop

    after_18:
    // 0x80664FF4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80664FF8: lw          $t9, -0x7288($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7288);
    // 0x80664FFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80665000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80665004: jalr        $t9
    // 0x80665008: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x80665008: nop

    after_19:
L_8066500C:
    // 0x8066500C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80665010:
    // 0x80665010: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80665014: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80665018: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8066501C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80665020: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80665024: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80665028: jr          $ra
    // 0x8066502C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8066502C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80445F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445F40: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80445F44: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80445F48: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80445F4C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80445F50: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80445F54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80445F58: jr          $ra
    // 0x80445F5C: sw          $t7, 0x6C9C($at)
    MEM_W(0X6C9C, ctx->r1) = ctx->r15;
    return;
    // 0x80445F5C: sw          $t7, 0x6C9C($at)
    MEM_W(0X6C9C, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80471818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8047181C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471820: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80471824: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(158, 0X1A60) << 16);
    // 0x80471828: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8047182C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80471830: addiu       $t6, $t6, 0x2F20
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(158, 0X1A60));
    // 0x80471834: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80471838: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8047183C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80471840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80471844: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80471848: jal         0x804719F8
    // 0x8047184C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804719F8(rdram, ctx);
        goto after_0;
    // 0x8047184C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80471850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80471854: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80471858: jr          $ra
    // 0x8047185C: nop

    return;
    // 0x8047185C: nop

;}
RECOMP_FUNC void func_80078244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078244: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80078248: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007824C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80078250: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80078254: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80078258: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007825C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80078260: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80078264: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80078268: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
    // 0x8007826C: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80078270: sll         $t0, $v0, 8
    ctx->r8 = S32(ctx->r2 << 8);
    // 0x80078274: srl         $t0, $t0, 24
    ctx->r8 = S32(U32(ctx->r8) >> 24);
    // 0x80078278: srl         $v1, $v0, 24
    ctx->r3 = S32(U32(ctx->r2) >> 24);
    // 0x8007827C: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80078280: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80078284: lw          $t1, 0x4($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4);
    // 0x80078288: sra         $t3, $v1, 1
    ctx->r11 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8007828C: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80078290: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x80078294: sll         $t5, $t1, 24
    ctx->r13 = S32(ctx->r9 << 24);
    // 0x80078298: sra         $t6, $t5, 24
    ctx->r14 = S32(SIGNED(ctx->r13) >> 24);
    // 0x8007829C: sra         $t2, $t9, 24
    ctx->r10 = S32(SIGNED(ctx->r25) >> 24);
    // 0x800782A0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800782A4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800782A8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800782AC: jal         0x8007E200
    // 0x800782B0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_8007E200(rdram, ctx);
        goto after_0;
    // 0x800782B0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_0:
    // 0x800782B4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800782B8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800782BC: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800782C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800782C4: jr          $ra
    // 0x800782C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800782C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804CD390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CD390: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x804CD394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CD398: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CD39C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x804CD3A0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804CD3A4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804CD3A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804CD3AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804CD3B0: jal         0x8004921C
    // 0x804CD3B4: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804CD3B4: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    after_0:
    // 0x804CD3B8: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x804CD3BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CD3C0: jal         0x8004921C
    // 0x804CD3C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804CD3C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804CD3C8: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x804CD3CC: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x804CD3D0: lbu         $t4, 0x145($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X145);
    // 0x804CD3D4: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804CD3D8: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x804CD3DC: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x804CD3E0: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x804CD3E4: lw          $t6, 0x80($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X80);
    // 0x804CD3E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804CD3EC: mflo        $t3
    ctx->r11 = lo;
    // 0x804CD3F0: nop

    // 0x804CD3F4: nop

    // 0x804CD3F8: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804CD3FC: mflo        $t5
    ctx->r13 = lo;
    // 0x804CD400: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x804CD404: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x804CD408: lw          $t8, 0x88($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X88);
    // 0x804CD40C: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x804CD410: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804CD414: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804CD418: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x804CD41C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x804CD420: srl         $t2, $t2, 2
    ctx->r10 = S32(U32(ctx->r10) >> 2);
    // 0x804CD424: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x804CD428: jal         0x80077338
    // 0x804CD42C: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x804CD42C: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    after_2:
    // 0x804CD430: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x804CD434: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804CD438: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CD43C: jal         0x8007711C
    // 0x804CD440: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x804CD440: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    after_3:
    // 0x804CD444: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x804CD448: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x804CD44C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x804CD450: addiu       $t3, $t9, 0x8
    ctx->r11 = ADD32(ctx->r25, 0X8);
    // 0x804CD454: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x804CD458: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x804CD45C: lui         $t4, 0xFD50
    ctx->r12 = S32(0XFD50 << 16);
    // 0x804CD460: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x804CD464: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x804CD468: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x804CD46C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CD470: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x804CD474: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x804CD478: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804CD47C: ori         $t9, $t9, 0x50
    ctx->r25 = ctx->r25 | 0X50;
    // 0x804CD480: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804CD484: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x804CD488: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x804CD48C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x804CD490: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x804CD494: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x804CD498: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x804CD49C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804CD4A0: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x804CD4A4: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x804CD4A8: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x804CD4AC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x804CD4B0: ori         $t9, $t9, 0xF100
    ctx->r25 = ctx->r25 | 0XF100;
    // 0x804CD4B4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804CD4B8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804CD4BC: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x804CD4C0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x804CD4C4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x804CD4C8: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x804CD4CC: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x804CD4D0: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x804CD4D4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804CD4D8: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x804CD4DC: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x804CD4E0: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x804CD4E4: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x804CD4E8: ori         $t8, $t8, 0x1000
    ctx->r24 = ctx->r24 | 0X1000;
    // 0x804CD4EC: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x804CD4F0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x804CD4F4: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x804CD4F8: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x804CD4FC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x804CD500: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x804CD504: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x804CD508: ori         $t6, $t6, 0xC07C
    ctx->r14 = ctx->r14 | 0XC07C;
    // 0x804CD50C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804CD510: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x804CD514: lui         $t5, 0xF200
    ctx->r13 = S32(0XF200 << 16);
    // 0x804CD518: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x804CD51C: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x804CD520: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x804CD524: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x804CD528: lw          $t9, 0x14($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X14);
    // 0x804CD52C: jalr        $t9
    // 0x804CD530: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x804CD530: nop

    after_4:
    // 0x804CD534: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x804CD538: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x804CD53C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804CD540: beq         $t2, $zero, L_804CD668
    if (ctx->r10 == 0) {
        // 0x804CD544: andi        $v0, $t2, 0x3
        ctx->r2 = ctx->r10 & 0X3;
            goto L_804CD668;
    }
    // 0x804CD544: andi        $v0, $t2, 0x3
    ctx->r2 = ctx->r10 & 0X3;
    // 0x804CD548: beq         $v0, $zero, L_804CD59C
    if (ctx->r2 == 0) {
        // 0x804CD54C: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_804CD59C;
    }
    // 0x804CD54C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x804CD550: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(237, 0X1B40) << 16);
    // 0x804CD554: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x804CD558: ori         $a1, $a1, 0x40FF
    ctx->r5 = ctx->r5 | 0X40FF;
    // 0x804CD55C: addiu       $a0, $a0, -0x2050
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(237, 0X1B40));
    // 0x804CD560: lui         $a2, 0x600
    ctx->r6 = S32(0X600 << 16);
L_804CD564:
    // 0x804CD564: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x804CD568: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x804CD56C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804CD570: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x804CD574: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x804CD578: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x804CD57C: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x804CD580: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x804CD584: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804CD588: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x804CD58C: sw          $a0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r4;
    // 0x804CD590: bne         $t1, $a3, L_804CD564
    if (ctx->r9 != ctx->r7) {
        // 0x804CD594: sw          $a2, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r6;
            goto L_804CD564;
    }
    // 0x804CD594: sw          $a2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r6;
    // 0x804CD598: beq         $a3, $t2, L_804CD668
    if (ctx->r7 == ctx->r10) {
        // 0x804CD59C: lui         $a1, 0x400
        ctx->r5 = S32(0X400 << 16);
            goto L_804CD668;
    }
L_804CD59C:
    // 0x804CD59C: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x804CD5A0: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(237, 0X1B40) << 16);
    // 0x804CD5A4: addiu       $a0, $a0, -0x2050
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(237, 0X1B40));
    // 0x804CD5A8: ori         $a1, $a1, 0x40FF
    ctx->r5 = ctx->r5 | 0X40FF;
    // 0x804CD5AC: lui         $a2, 0x600
    ctx->r6 = S32(0X600 << 16);
L_804CD5B0:
    // 0x804CD5B0: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x804CD5B4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x804CD5B8: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x804CD5BC: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x804CD5C0: sw          $t0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r8;
    // 0x804CD5C4: sw          $a1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r5;
    // 0x804CD5C8: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x804CD5CC: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x804CD5D0: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x804CD5D4: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x804CD5D8: sw          $a0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r4;
    // 0x804CD5DC: sw          $a2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r6;
    // 0x804CD5E0: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x804CD5E4: addiu       $t3, $t8, 0x8
    ctx->r11 = ADD32(ctx->r24, 0X8);
    // 0x804CD5E8: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x804CD5EC: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x804CD5F0: sw          $a1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r5;
    // 0x804CD5F4: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x804CD5F8: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x804CD5FC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x804CD600: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x804CD604: sw          $a0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r4;
    // 0x804CD608: sw          $a2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r6;
    // 0x804CD60C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x804CD610: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x804CD614: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x804CD618: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x804CD61C: sw          $a1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r5;
    // 0x804CD620: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x804CD624: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x804CD628: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x804CD62C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x804CD630: sw          $a0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r4;
    // 0x804CD634: sw          $a2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r6;
    // 0x804CD638: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x804CD63C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x804CD640: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x804CD644: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x804CD648: sw          $a1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r5;
    // 0x804CD64C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x804CD650: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x804CD654: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x804CD658: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x804CD65C: sw          $a0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r4;
    // 0x804CD660: bne         $a3, $t2, L_804CD5B0
    if (ctx->r7 != ctx->r10) {
        // 0x804CD664: sw          $a2, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->r6;
            goto L_804CD5B0;
    }
    // 0x804CD664: sw          $a2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r6;
L_804CD668:
    // 0x804CD668: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x804CD66C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x804CD670: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x804CD674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804CD678: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CD67C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x804CD680: jr          $ra
    // 0x804CD684: nop

    return;
    // 0x804CD684: nop

;}
RECOMP_FUNC void func_806EEBB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EEBB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806EEBBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EEBC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EEBC4: jal         0x8004700C
    // 0x806EEBC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EEBC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EEBCC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x806EEBD0: jal         0x806EC16C
    // 0x806EEBD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC16C(rdram, ctx);
        goto after_1;
    // 0x806EEBD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EEBD8: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EEBDC: jal         0x800577D8
    // 0x806EEBE0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_2;
    // 0x806EEBE0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x806EEBE4: jal         0x806EE5E4
    // 0x806EEBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE5E4(rdram, ctx);
        goto after_3;
    // 0x806EEBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EEBEC: jal         0x806EE664
    // 0x806EEBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE664(rdram, ctx);
        goto after_4;
    // 0x806EEBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EEBF4: jal         0x806EE6AC
    // 0x806EEBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE6AC(rdram, ctx);
        goto after_5;
    // 0x806EEBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EEBFC: jal         0x806EE720
    // 0x806EEC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE720(rdram, ctx);
        goto after_6;
    // 0x806EEC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806EEC04: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x806EEC08: beql        $t7, $zero, L_806EED20
    if (ctx->r15 == 0) {
        // 0x806EEC0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EED20;
    }
    goto skip_0;
    // 0x806EEC0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EEC10: lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E0);
    // 0x806EEC14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EEC18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EEC1C: blez        $v1, L_806EED14
    if (SIGNED(ctx->r3) <= 0) {
        // 0x806EEC20: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_806EED14;
    }
    // 0x806EEC20: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EEC24: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
    // 0x806EEC28: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x806EEC2C: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x806EEC30: lw          $t9, 0x1F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1F4);
    // 0x806EEC34: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806EEC38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806EEC3C: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x806EEC40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806EEC44: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806EEC48: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806EEC4C: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806EEC50: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806EEC54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EEC58: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x806EEC5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EEC60: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806EEC64: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x806EEC68: bc1f        L_806EEC9C
    if (!c1cs) {
        // 0x806EEC6C: sub.s       $f0, $f4, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_806EEC9C;
    }
    // 0x806EEC6C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806EEC70: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x806EEC74: jal         0x806EF4A0
    // 0x806EEC78: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_806EF4A0(rdram, ctx);
        goto after_7;
    // 0x806EEC78: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_7:
    // 0x806EEC7C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806EEC80: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D28) << 16);
    // 0x806EEC84: lwc1        $f14, 0xC78($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D28));
    // 0x806EEC88: jal         0x806EC03C
    // 0x806EEC8C: lwc1        $f12, 0x28($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X28);
    func_806EC03C(rdram, ctx);
        goto after_8;
    // 0x806EEC8C: lwc1        $f12, 0x28($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X28);
    after_8:
    // 0x806EEC90: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806EEC94: b           L_806EED1C
    // 0x806EEC98: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
        goto L_806EED1C;
    // 0x806EEC98: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
L_806EEC9C:
    // 0x806EEC9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EECA0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x806EECA4: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806EECA8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806EECAC: nop

    // 0x806EECB0: bc1fl       L_806EECC8
    if (!c1cs) {
        // 0x806EECB4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_806EECC8;
    }
    goto skip_1;
    // 0x806EECB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x806EECB8: lw          $t0, 0x68($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X68);
    // 0x806EECBC: beql        $t0, $zero, L_806EECEC
    if (ctx->r8 == 0) {
        // 0x806EECC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EECEC;
    }
    goto skip_2;
    // 0x806EECC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x806EECC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_806EECC8:
    // 0x806EECC8: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806EECCC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806EECD0: nop

    // 0x806EECD4: bc1fl       L_806EED20
    if (!c1cs) {
        // 0x806EECD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EED20;
    }
    goto skip_3;
    // 0x806EECD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806EECDC: lw          $t1, 0x68($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X68);
    // 0x806EECE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806EECE4: bne         $t1, $at, L_806EED1C
    if (ctx->r9 != ctx->r1) {
        // 0x806EECE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EED1C;
    }
    // 0x806EECE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806EECEC:
    // 0x806EECEC: jal         0x806EE640
    // 0x806EECF0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_806EE640(rdram, ctx);
        goto after_9;
    // 0x806EECF0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_9:
    // 0x806EECF4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806EECF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EECFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EED00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806EED04: jal         0x806EF4A0
    // 0x806EED08: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    func_806EF4A0(rdram, ctx);
        goto after_10;
    // 0x806EED08: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    after_10:
    // 0x806EED0C: b           L_806EED20
    // 0x806EED10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EED20;
    // 0x806EED10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EED14:
    // 0x806EED14: jal         0x806EF4A0
    // 0x806EED18: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EF4A0(rdram, ctx);
        goto after_11;
    // 0x806EED18: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_11:
L_806EED1C:
    // 0x806EED1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EED20:
    // 0x806EED20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EED24: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806EED28: jr          $ra
    // 0x806EED2C: nop

    return;
    // 0x806EED2C: nop

;}
RECOMP_FUNC void func_804CB41C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CB41C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804CB420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CB424: jal         0x8004700C
    // 0x804CB428: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804CB428: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CB42C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13E8) << 16);
    // 0x804CB430: lwc1        $f4, -0x40D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13E8));
    // 0x804CB434: lwc1        $f0, 0xC4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x804CB438: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x804CB43C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13EC) << 16);
    // 0x804CB440: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804CB444: lwc1        $f14, 0x50($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X50);
    // 0x804CB448: bc1t        L_804CB460
    if (c1cs) {
        // 0x804CB44C: nop
    
            goto L_804CB460;
    }
    // 0x804CB44C: nop

    // 0x804CB450: lwc1        $f6, -0x40D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13EC));
    // 0x804CB454: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804CB458: nop

    // 0x804CB45C: bc1f        L_804CB484
    if (!c1cs) {
        // 0x804CB460: lui         $at, 0x804D
        ctx->r1 = S32(RELOC_HI16(231, 0X1330) << 16);
            goto L_804CB484;
    }
L_804CB460:
    // 0x804CB460: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1330) << 16);
    // 0x804CB464: lwc1        $f8, -0x4190($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1330));
    // 0x804CB468: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x804CB46C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804CB470: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804CB474: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804CB478: mul.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x804CB47C: b           L_804CB494
    // 0x804CB480: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
        goto L_804CB494;
    // 0x804CB480: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
L_804CB484:
    // 0x804CB484: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804CB488: nop

    // 0x804CB48C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x804CB490: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
L_804CB494:
    // 0x804CB494: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13F0) << 16);
    // 0x804CB498: lbu         $t7, 0x12E8($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X12E8);
    // 0x804CB49C: bne         $t7, $zero, L_804CB4D0
    if (ctx->r15 != 0) {
        // 0x804CB4A0: nop
    
            goto L_804CB4D0;
    }
    // 0x804CB4A0: nop

    // 0x804CB4A4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x804CB4A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804CB4AC: bc1fl       L_804CB4C8
    if (!c1cs) {
        // 0x804CB4B0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_804CB4C8;
    }
    goto skip_0;
    // 0x804CB4B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x804CB4B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804CB4B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804CB4BC: b           L_804CB574
    // 0x804CB4C0: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
        goto L_804CB574;
    // 0x804CB4C0: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x804CB4C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_804CB4C8:
    // 0x804CB4C8: b           L_804CB574
    // 0x804CB4CC: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
        goto L_804CB574;
    // 0x804CB4CC: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
L_804CB4D0:
    // 0x804CB4D0: lwc1        $f8, -0x40D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13F0));
    // 0x804CB4D4: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13F4) << 16);
    // 0x804CB4D8: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x804CB4DC: nop

    // 0x804CB4E0: bc1fl       L_804CB504
    if (!c1cs) {
        // 0x804CB4E4: lbu         $t8, 0xF4($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0XF4);
            goto L_804CB504;
    }
    goto skip_1;
    // 0x804CB4E4: lbu         $t8, 0xF4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF4);
    skip_1:
    // 0x804CB4E8: lwc1        $f10, -0x40CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13F4));
    // 0x804CB4EC: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x804CB4F0: nop

    // 0x804CB4F4: bc1fl       L_804CB504
    if (!c1cs) {
        // 0x804CB4F8: lbu         $t8, 0xF4($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0XF4);
            goto L_804CB504;
    }
    goto skip_2;
    // 0x804CB4F8: lbu         $t8, 0xF4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF4);
    skip_2:
    // 0x804CB4FC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x804CB500: lbu         $t8, 0xF4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF4);
L_804CB504:
    // 0x804CB504: beql        $t8, $zero, L_804CB550
    if (ctx->r24 == 0) {
        // 0x804CB508: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_804CB550;
    }
    goto skip_3;
    // 0x804CB508: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_3:
    // 0x804CB50C: lwc1        $f18, 0xC8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x804CB510: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x804CB514: nop

    // 0x804CB518: bc1fl       L_804CB550
    if (!c1cs) {
        // 0x804CB51C: mov.s       $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
            goto L_804CB550;
    }
    goto skip_4;
    // 0x804CB51C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    skip_4:
    // 0x804CB520: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x804CB524: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x804CB528: jal         0x80066DE4
    // 0x804CB52C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x804CB52C: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x804CB530: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1360) << 16);
    // 0x804CB534: lwc1        $f4, -0x4160($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1360));
    // 0x804CB538: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804CB53C: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804CB540: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804CB544: b           L_804CB574
    // 0x804CB548: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
        goto L_804CB574;
    // 0x804CB548: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x804CB54C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_804CB550:
    // 0x804CB550: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x804CB554: jal         0x80066DE4
    // 0x804CB558: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x804CB558: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x804CB55C: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1348) << 16);
    // 0x804CB560: lwc1        $f8, -0x4178($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1348));
    // 0x804CB564: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804CB568: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804CB56C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804CB570: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
L_804CB574:
    // 0x804CB574: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1378) << 16);
    // 0x804CB578: lwc1        $f12, -0x4148($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1378));
    // 0x804CB57C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804CB580: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x804CB584: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x804CB588: nop

    // 0x804CB58C: bc1fl       L_804CB5A0
    if (!c1cs) {
        // 0x804CB590: neg.s       $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = -ctx->f12.fl;
            goto L_804CB5A0;
    }
    goto skip_5;
    // 0x804CB590: neg.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = -ctx->f12.fl;
    skip_5:
    // 0x804CB594: b           L_804CB5C0
    // 0x804CB598: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_804CB5C0;
    // 0x804CB598: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x804CB59C: neg.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = -ctx->f12.fl;
L_804CB5A0:
    // 0x804CB5A0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x804CB5A4: nop

    // 0x804CB5A8: bc1fl       L_804CB5BC
    if (!c1cs) {
        // 0x804CB5AC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_804CB5BC;
    }
    goto skip_6;
    // 0x804CB5AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_6:
    // 0x804CB5B0: b           L_804CB5BC
    // 0x804CB5B4: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_804CB5BC;
    // 0x804CB5B4: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x804CB5B8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_804CB5BC:
    // 0x804CB5BC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_804CB5C0:
    // 0x804CB5C0: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x804CB5C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804CB5C8: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x804CB5CC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x804CB5D0: nop

    // 0x804CB5D4: bc1fl       L_804CB5E8
    if (!c1cs) {
        // 0x804CB5D8: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_804CB5E8;
    }
    goto skip_7;
    // 0x804CB5D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_7:
    // 0x804CB5DC: b           L_804CB60C
    // 0x804CB5E0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_804CB60C;
    // 0x804CB5E0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x804CB5E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_804CB5E8:
    // 0x804CB5E8: nop

    // 0x804CB5EC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x804CB5F0: nop

    // 0x804CB5F4: bc1fl       L_804CB608
    if (!c1cs) {
        // 0x804CB5F8: mov.s       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
            goto L_804CB608;
    }
    goto skip_8;
    // 0x804CB5F8: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    skip_8:
    // 0x804CB5FC: b           L_804CB608
    // 0x804CB600: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_804CB608;
    // 0x804CB600: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804CB604: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_804CB608:
    // 0x804CB608: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_804CB60C:
    // 0x804CB60C: swc1        $f14, 0x50($t9)
    MEM_W(0X50, ctx->r25) = ctx->f14.u32l;
    // 0x804CB610: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x804CB614: jal         0x80066DE4
    // 0x804CB618: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x804CB618: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_3:
    // 0x804CB61C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804CB620: jal         0x80066E88
    // 0x804CB624: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x804CB624: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x804CB628: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804CB62C: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x804CB630: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804CB634: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x804CB638: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x804CB63C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x804CB640: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x804CB644: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x804CB648: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x804CB64C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804CB650: swc1        $f6, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f6.u32l;
    // 0x804CB654: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x804CB658: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x804CB65C: swc1        $f4, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f4.u32l;
    // 0x804CB660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CB664: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804CB668: jr          $ra
    // 0x804CB66C: nop

    return;
    // 0x804CB66C: nop

;}
RECOMP_FUNC void func_80523830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80523830: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80523834: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80523838: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8052383C: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(321, 0X1E6C) << 16);
    // 0x80523840: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80523844: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80523848: lw          $t8, 0x411C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(321, 0X1E6C));
    // 0x8052384C: jr          $ra
    // 0x80523850: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x80523850: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80523854: nop

    // 0x80523858: nop

    // 0x8052385C: nop

;}
RECOMP_FUNC void func_80045508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045508: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x8004550C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80045510: sw          $a1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r5;
    // 0x80045514: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80045518: jr          $ra
    // 0x8004551C: sb          $t7, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r15;
    return;
    // 0x8004551C: sb          $t7, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void func_8064A764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A76C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8064A770: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8064A774: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064A778: lui         $t8, 0x8065
    ctx->r24 = S32(RELOC_HI16(495, 0X2DA8) << 16);
    // 0x8064A77C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8064A780: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8064A784: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8064A788: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064A78C: lw          $t8, -0x3188($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(495, 0X2DA8));
    // 0x8064A790: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064A794: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064A798: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064A79C: jal         0x80048490
    // 0x8064A7A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8064A7A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8064A7A4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8064A7A8: jal         0x80048378
    // 0x8064A7AC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8064A7AC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8064A7B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064A7B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A7B8: jr          $ra
    // 0x8064A7BC: nop

    return;
    // 0x8064A7BC: nop

;}
RECOMP_FUNC void func_806DEE68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DEE68: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x806DEE6C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806DEE70: sltiu       $at, $t7, 0x3
    ctx->r1 = ctx->r15 < 0X3 ? 1 : 0;
    // 0x806DEE74: bne         $at, $zero, L_806DEE9C
    if (ctx->r1 != 0) {
        // 0x806DEE78: sw          $t7, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r15;
            goto L_806DEE9C;
    }
    // 0x806DEE78: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x806DEE7C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x806DEE80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806DEE84: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x806DEE88: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x806DEE8C: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x806DEE90: mfhi        $t1
    ctx->r9 = hi;
    // 0x806DEE94: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x806DEE98: nop

L_806DEE9C:
    // 0x806DEE9C: jr          $ra
    // 0x806DEEA0: nop

    return;
    // 0x806DEEA0: nop

;}
RECOMP_FUNC void func_805A01D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A01D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A01D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A01DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A01E0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x805A01E4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x805A01E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805A01EC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x805A01F0: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x805A01F4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805A01F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805A01FC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x805A0200: jal         0x80053CF8
    // 0x805A0204: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80053CF8(rdram, ctx);
        goto after_0;
    // 0x805A0204: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x805A0208: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x805A020C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805A0210: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x805A0214: jal         0x80053EE4
    // 0x805A0218: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    func_80053EE4(rdram, ctx);
        goto after_1;
    // 0x805A0218: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x805A021C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x805A0220: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x805A0224: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x805A0228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A022C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A0230: jr          $ra
    // 0x805A0234: nop

    return;
    // 0x805A0234: nop

;}
RECOMP_FUNC void func_806D1614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D1614: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D1618: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D161C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D1620: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D1624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D1628: jal         0x8004700C
    // 0x806D162C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D162C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x806D1630: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806D1634: beq         $v0, $zero, L_806D17B0
    if (ctx->r2 == 0) {
        // 0x806D1638: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_806D17B0;
    }
    // 0x806D1638: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x806D163C: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x806D1640: lw          $v1, -0x72D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X72D8);
    // 0x806D1644: addiu       $t0, $zero, 0x309
    ctx->r8 = ADD32(0, 0X309);
    // 0x806D1648: lw          $a2, 0x1F4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F4);
    // 0x806D164C: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x806D1650: bnel        $t0, $a0, L_806D166C
    if (ctx->r8 != ctx->r4) {
        // 0x806D1654: lw          $a1, 0x0($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X0);
            goto L_806D166C;
    }
    goto skip_0;
    // 0x806D1654: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x806D1658: jal         0x800447C8
    // 0x806D165C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806D165C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D1660: b           L_806D17B4
    // 0x806D1664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D17B4;
    // 0x806D1664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D1668: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
L_806D166C:
    // 0x806D166C: beql        $a1, $zero, L_806D17B4
    if (ctx->r5 == 0) {
        // 0x806D1670: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D17B4;
    }
    goto skip_1;
    // 0x806D1670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806D1674: lbu         $t6, 0xF4($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XF4);
    // 0x806D1678: beql        $t6, $zero, L_806D174C
    if (ctx->r14 == 0) {
        // 0x806D167C: lw          $t3, 0x24($a3)
        ctx->r11 = MEM_W(ctx->r7, 0X24);
            goto L_806D174C;
    }
    goto skip_2;
    // 0x806D167C: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
    skip_2:
    // 0x806D1680: beql        $t0, $a0, L_806D174C
    if (ctx->r8 == ctx->r4) {
        // 0x806D1684: lw          $t3, 0x24($a3)
        ctx->r11 = MEM_W(ctx->r7, 0X24);
            goto L_806D174C;
    }
    goto skip_3;
    // 0x806D1684: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
    skip_3:
    // 0x806D1688: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806D168C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806D1690: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x806D1694: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x806D1698: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x806D169C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D16A0: bc1fl       L_806D17B4
    if (!c1cs) {
        // 0x806D16A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D17B4;
    }
    goto skip_4;
    // 0x806D16A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x806D16A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x806D16AC: sw          $t8, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r24;
    // 0x806D16B0: jal         0x806D15D0
    // 0x806D16B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_806D15D0(rdram, ctx);
        goto after_2;
    // 0x806D16B4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x806D16B8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806D16BC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x806D16C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D16C4: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x806D16C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D16CC: beql        $t9, $at, L_806D16E8
    if (ctx->r25 == ctx->r1) {
        // 0x806D16D0: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_806D16E8;
    }
    goto skip_5;
    // 0x806D16D0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_5:
    // 0x806D16D4: jal         0x806D2BCC
    // 0x806D16D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_806D2BCC(rdram, ctx);
        goto after_3;
    // 0x806D16D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x806D16DC: b           L_806D17B4
    // 0x806D16E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D17B4;
    // 0x806D16E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D16E4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_806D16E8:
    // 0x806D16E8: jal         0x80067BBC
    // 0x806D16EC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806D16EC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x806D16F0: addiu       $a0, $zero, 0x26E
    ctx->r4 = ADD32(0, 0X26E);
    // 0x806D16F4: jal         0x80067818
    // 0x806D16F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806D16F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806D16FC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x806D1700: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x806D1704: lw          $t1, 0x478($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X478);
    // 0x806D1708: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x806D170C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806D1710: lwc1        $f8, 0x30($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X30);
    // 0x806D1714: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x806D1718: lw          $t2, 0x478($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X478);
    // 0x806D171C: lwc1        $f10, 0x34($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X34);
    // 0x806D1720: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806D1724: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x806D1728: jal         0x8002FDF8
    // 0x806D172C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8002FDF8(rdram, ctx);
        goto after_6;
    // 0x806D172C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x806D1730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D1734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D1738: jal         0x806D2BCC
    // 0x806D173C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806D2BCC(rdram, ctx);
        goto after_7;
    // 0x806D173C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x806D1740: b           L_806D17B4
    // 0x806D1744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D17B4;
    // 0x806D1744: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D1748: lw          $t3, 0x24($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X24);
L_806D174C:
    // 0x806D174C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D1750: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806D1754: bnel        $t3, $zero, L_806D1784
    if (ctx->r11 != 0) {
        // 0x806D1758: lw          $t4, 0x0($a3)
        ctx->r12 = MEM_W(ctx->r7, 0X0);
            goto L_806D1784;
    }
    goto skip_6;
    // 0x806D1758: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    skip_6:
    // 0x806D175C: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x806D1760: jal         0x800677F8
    // 0x806D1764: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800677F8(rdram, ctx);
        goto after_8;
    // 0x806D1764: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_8:
    // 0x806D1768: jal         0x8002FF38
    // 0x806D176C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8002FF38(rdram, ctx);
        goto after_9;
    // 0x806D176C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x806D1770: jal         0x800447C8
    // 0x806D1774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_10;
    // 0x806D1774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x806D1778: b           L_806D17B4
    // 0x806D177C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D17B4;
    // 0x806D177C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D1780: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
L_806D1784:
    // 0x806D1784: lh          $t5, 0x144($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X144);
    // 0x806D1788: subu        $v0, $t5, $a1
    ctx->r2 = SUB32(ctx->r13, ctx->r5);
    // 0x806D178C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x806D1790: bgtz        $v0, L_806D179C
    if (SIGNED(ctx->r2) > 0) {
        // 0x806D1794: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806D179C;
    }
    // 0x806D1794: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D1798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806D179C:
    // 0x806D179C: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x806D17A0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x806D17A4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x806D17A8: jal         0x806D2BCC
    // 0x806D17AC: sw          $t6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r14;
    func_806D2BCC(rdram, ctx);
        goto after_11;
    // 0x806D17AC: sw          $t6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r14;
    after_11:
L_806D17B0:
    // 0x806D17B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D17B4:
    // 0x806D17B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D17B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806D17BC: jr          $ra
    // 0x806D17C0: nop

    return;
    // 0x806D17C0: nop

;}
RECOMP_FUNC void func_8006D0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D0F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006D0F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006D0FC: sll         $a3, $a0, 2
    ctx->r7 = S32(ctx->r4 << 2);
    // 0x8006D100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D104: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006D108: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8006D10C: addiu       $a1, $a1, 0x7770
    ctx->r5 = ADD32(ctx->r5, 0X7770);
    // 0x8006D110: addiu       $a0, $a0, -0x7B94
    ctx->r4 = ADD32(ctx->r4, -0X7B94);
    // 0x8006D114: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8006D118: jal         0x800655F4
    // 0x8006D11C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    func_800655F4(rdram, ctx);
        goto after_0;
    // 0x8006D11C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_0:
    // 0x8006D120: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8006D124: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006D128: addiu       $v1, $v1, 0x77D0
    ctx->r3 = ADD32(ctx->r3, 0X77D0);
    // 0x8006D12C: addu        $t6, $v1, $a3
    ctx->r14 = ADD32(ctx->r3, ctx->r7);
    // 0x8006D130: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8006D134: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006D138: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x8006D13C: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x8006D140: sb          $t7, -0x7B90($at)
    MEM_B(-0X7B90, ctx->r1) = ctx->r15;
    // 0x8006D144: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8006D148: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006D14C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006D150: addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // 0x8006D154: sb          $t9, -0x7B78($at)
    MEM_B(-0X7B78, ctx->r1) = ctx->r25;
    // 0x8006D158: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8006D15C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006D160: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006D164: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x8006D168: sb          $t1, -0x7B60($at)
    MEM_B(-0X7B60, ctx->r1) = ctx->r9;
    // 0x8006D16C: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x8006D170: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006D174: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006D178: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006D17C: sb          $t3, -0x7B48($at)
    MEM_B(-0X7B48, ctx->r1) = ctx->r11;
    // 0x8006D180: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8006D184: sw          $zero, 0x5B8($v0)
    MEM_W(0X5B8, ctx->r2) = 0;
    // 0x8006D188: sw          $zero, 0x5BC($v0)
    MEM_W(0X5BC, ctx->r2) = 0;
    // 0x8006D18C: sw          $zero, 0x5C0($v0)
    MEM_W(0X5C0, ctx->r2) = 0;
    // 0x8006D190: sw          $zero, 0x5C4($v0)
    MEM_W(0X5C4, ctx->r2) = 0;
    // 0x8006D194: sw          $zero, 0x5C8($v0)
    MEM_W(0X5C8, ctx->r2) = 0;
    // 0x8006D198: sw          $zero, 0x62C($v0)
    MEM_W(0X62C, ctx->r2) = 0;
    // 0x8006D19C: sw          $zero, 0x630($v0)
    MEM_W(0X630, ctx->r2) = 0;
    // 0x8006D1A0: addu        $t4, $t4, $a3
    ctx->r12 = ADD32(ctx->r12, ctx->r7);
    // 0x8006D1A4: lw          $t4, 0x7838($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7838);
    // 0x8006D1A8: lw          $t5, 0x478($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X478);
    // 0x8006D1AC: sw          $t4, 0xFC($t5)
    MEM_W(0XFC, ctx->r13) = ctx->r12;
    // 0x8006D1B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D1B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006D1B8: jr          $ra
    // 0x8006D1BC: nop

    return;
    // 0x8006D1BC: nop

;}
RECOMP_FUNC void func_8006B390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B390: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006B394: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8006B398: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006B39C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006B3A0: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x8006B3A4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006B3A8: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8006B3AC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8006B3B0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8006B3B4: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x8006B3B8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006B3BC: lw          $t0, 0x1B0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1B0);
    // 0x8006B3C0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006B3C4: lw          $v0, 0x20($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X20);
    // 0x8006B3C8: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x8006B3CC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8006B3D0: jal         0x8006A99C
    // 0x8006B3D4: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x8006B3D4: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_0:
    // 0x8006B3D8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8006B3DC: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8006B3E0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006B3E4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8006B3E8: nop

    // 0x8006B3EC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006B3F0: jal         0x8006A99C
    // 0x8006B3F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x8006B3F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8006B3F8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8006B3FC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8006B400: addiu       $a2, $sp, 0x2A
    ctx->r6 = ADD32(ctx->r29, 0X2A);
    // 0x8006B404: lh          $a3, 0x26($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X26);
    // 0x8006B408: jal         0x8006AB7C
    // 0x8006B40C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8006AB7C(rdram, ctx);
        goto after_2;
    // 0x8006B40C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x8006B410: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006B414: bne         $v0, $at, L_8006B424
    if (ctx->r2 != ctx->r1) {
        // 0x8006B418: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006B424;
    }
    // 0x8006B418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B41C: b           L_8006B44C
    // 0x8006B420: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_8006B44C;
    // 0x8006B420: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8006B424:
    // 0x8006B424: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8006B428: lh          $t6, 0x2A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2A);
    // 0x8006B42C: lh          $t8, 0x2C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2C);
    // 0x8006B430: lh          $t5, 0x12($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X12);
    // 0x8006B434: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8006B438: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B43C: mflo        $t7
    ctx->r15 = lo;
    // 0x8006B440: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B444: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8006B448: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
L_8006B44C:
    // 0x8006B44C: jr          $ra
    // 0x8006B450: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006B450: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8002AD14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD14: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8002AD18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002AD1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002AD20: lw          $t6, 0xE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE8);
    // 0x8002AD24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002AD28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002AD2C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x8002AD30: swc1        $f0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
    // 0x8002AD34: jal         0x8002A148
    // 0x8002AD38: swc1        $f0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f0.u32l;
    func_8002A148(rdram, ctx);
        goto after_0;
    // 0x8002AD38: swc1        $f0, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x8002AD3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002AD40: jal         0x8002AAF0
    // 0x8002AD44: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_8002AAF0(rdram, ctx);
        goto after_1;
    // 0x8002AD44: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x8002AD48: lwc1        $f12, 0x84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8002AD4C: jal         0x80065388
    // 0x8002AD50: lwc1        $f14, 0xAC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XAC);
    func_80065388(rdram, ctx);
        goto after_2;
    // 0x8002AD50: lwc1        $f14, 0xAC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XAC);
    after_2:
    // 0x8002AD54: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    // 0x8002AD58: lwc1        $f12, 0x88($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8002AD5C: jal         0x80065388
    // 0x8002AD60: lwc1        $f14, 0xB0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XB0);
    func_80065388(rdram, ctx);
        goto after_3;
    // 0x8002AD60: lwc1        $f14, 0xB0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XB0);
    after_3:
    // 0x8002AD64: swc1        $f0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f0.u32l;
    // 0x8002AD68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002AD6C: jal         0x80065490
    // 0x8002AD70: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x8002AD70: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    after_4:
    // 0x8002AD74: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8002AD78: lw          $t7, -0x7D6C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D6C);
    // 0x8002AD7C: lw          $v0, 0xE8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XE8);
    // 0x8002AD80: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002AD84: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8002AD88: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8002AD8C: addiu       $a1, $a1, -0x2164
    ctx->r5 = ADD32(ctx->r5, -0X2164);
    // 0x8002AD90: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8002AD94: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8002AD98: lw          $t8, 0x1F4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1F4);
    // 0x8002AD9C: jal         0x80029CC0
    // 0x8002ADA0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    func_80029CC0(rdram, ctx);
        goto after_5;
    // 0x8002ADA0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    after_5:
    // 0x8002ADA4: jal         0x80029DE8
    // 0x8002ADA8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80029DE8(rdram, ctx);
        goto after_6;
    // 0x8002ADA8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x8002ADAC: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002ADB0: addiu       $a2, $a2, -0x2154
    ctx->r6 = ADD32(ctx->r6, -0X2154);
    // 0x8002ADB4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8002ADB8: jal         0x80029E60
    // 0x8002ADBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80029E60(rdram, ctx);
        goto after_7;
    // 0x8002ADBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8002ADC0: jal         0x80029F70
    // 0x8002ADC4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80029F70(rdram, ctx);
        goto after_8;
    // 0x8002ADC4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_8:
    // 0x8002ADC8: jal         0x8005A52C
    // 0x8002ADCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005A52C(rdram, ctx);
        goto after_9;
    // 0x8002ADCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8002ADD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002ADD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002ADD8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8002ADDC: jr          $ra
    // 0x8002ADE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8002ADE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80515D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80515D70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80515D74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80515D78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80515D7C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80515D80: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80515D84: jal         0x8005C9A8
    // 0x80515D88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8005C9A8(rdram, ctx);
        goto after_0;
    // 0x80515D88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80515D8C: jal         0x800447C8
    // 0x80515D90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80515D90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80515D94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80515D98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80515D9C: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x80515DA0: jal         0x805154F8
    // 0x80515DA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_805154F8(rdram, ctx);
        goto after_2;
    // 0x80515DA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80515DA8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80515DAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80515DB0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80515DB4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80515DB8: beql        $t9, $zero, L_80515DC8
    if (ctx->r25 == 0) {
        // 0x80515DBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80515DC8;
    }
    goto skip_0;
    // 0x80515DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80515DC0: sb          $t0, 0x7EB4($at)
    MEM_B(0X7EB4, ctx->r1) = ctx->r8;
    // 0x80515DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80515DC8:
    // 0x80515DC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80515DCC: jr          $ra
    // 0x80515DD0: nop

    return;
    // 0x80515DD0: nop

;}
RECOMP_FUNC void func_806D086C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D086C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D0870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D0874: jal         0x806D0828
    // 0x806D0878: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806D0828(rdram, ctx);
        goto after_0;
    // 0x806D0878: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D087C: bne         $v0, $zero, L_806D088C
    if (ctx->r2 != 0) {
        // 0x806D0880: nop
    
            goto L_806D088C;
    }
    // 0x806D0880: nop

    // 0x806D0884: b           L_806D0898
    // 0x806D0888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D0898;
    // 0x806D0888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D088C:
    // 0x806D088C: jal         0x806D069C
    // 0x806D0890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806D069C(rdram, ctx);
        goto after_1;
    // 0x806D0890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806D0894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806D0898:
    // 0x806D0898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D089C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D08A0: jr          $ra
    // 0x806D08A4: nop

    return;
    // 0x806D08A4: nop

;}
RECOMP_FUNC void func_8005546C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005546C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80055470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055474: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80055478: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005547C: jal         0x80055370
    // 0x80055480: addiu       $a1, $zero, 0x44E4
    ctx->r5 = ADD32(0, 0X44E4);
    func_80055370(rdram, ctx);
        goto after_0;
    // 0x80055480: addiu       $a1, $zero, 0x44E4
    ctx->r5 = ADD32(0, 0X44E4);
    after_0:
    // 0x80055484: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80055488: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005548C: jal         0x800553F4
    // 0x80055490: lhu         $a1, 0x26($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X26);
    func_800553F4(rdram, ctx);
        goto after_1;
    // 0x80055490: lhu         $a1, 0x26($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X26);
    after_1:
    // 0x80055494: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80055498: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8005549C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800554A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800554A4: jr          $ra
    // 0x800554A8: nop

    return;
    // 0x800554A8: nop

;}
RECOMP_FUNC void func_8045012C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045012C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80450130: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80450134: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80450138: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8045013C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450140: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450144: addu        $v1, $s0, $at
    ctx->r3 = ADD32(ctx->r16, ctx->r1);
    // 0x80450148: lw          $a0, 0x6A28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X6A28);
    // 0x8045014C: jal         0x8044DED0
    // 0x80450150: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8044DED0(rdram, ctx);
        goto after_0;
    // 0x80450150: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80450154: bltz        $v0, L_804501C0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80450158: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_804501C0;
    }
    // 0x80450158: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8045015C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80450160: beq         $at, $zero, L_804501C0
    if (ctx->r1 == 0) {
        // 0x80450164: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_804501C0;
    }
    // 0x80450164: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80450168: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045016C: lwc1        $f4, 0x6F00($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6F00);
    // 0x80450170: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450174: ori         $at, $at, 0x6F00
    ctx->r1 = ctx->r1 | 0X6F00;
    // 0x80450178: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8045017C: addu        $v0, $s0, $at
    ctx->r2 = ADD32(ctx->r16, ctx->r1);
    // 0x80450180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80450184: bc1fl       L_804501AC
    if (!c1cs) {
        // 0x80450188: lwc1        $f8, 0x0($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
            goto L_804501AC;
    }
    goto skip_0;
    // 0x80450188: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8045018C: jal         0x80450000
    // 0x80450190: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80450000(rdram, ctx);
        goto after_1;
    // 0x80450190: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80450194: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450198: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8045019C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804501A0: b           L_804501CC
    // 0x804501A4: sw          $t7, 0x6EF4($at)
    MEM_W(0X6EF4, ctx->r1) = ctx->r15;
        goto L_804501CC;
    // 0x804501A4: sw          $t7, 0x6EF4($at)
    MEM_W(0X6EF4, ctx->r1) = ctx->r15;
    // 0x804501A8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
L_804501AC:
    // 0x804501AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804501B0: nop

    // 0x804501B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804501B8: b           L_804501CC
    // 0x804501BC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_804501CC;
    // 0x804501BC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_804501C0:
    // 0x804501C0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804501C4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804501C8: sw          $zero, 0x6EF4($at)
    MEM_W(0X6EF4, ctx->r1) = 0;
L_804501CC:
    // 0x804501CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804501D0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804501D4: sw          $zero, 0x6EFC($at)
    MEM_W(0X6EFC, ctx->r1) = 0;
    // 0x804501D8: jal         0x804500F8
    // 0x804501DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_804500F8(rdram, ctx);
        goto after_2;
    // 0x804501DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x804501E0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804501E4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804501E8: sw          $v0, 0x6EF8($at)
    MEM_W(0X6EF8, ctx->r1) = ctx->r2;
    // 0x804501EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804501F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804501F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804501F8: jr          $ra
    // 0x804501FC: nop

    return;
    // 0x804501FC: nop

;}
RECOMP_FUNC void func_807903C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807903C4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x807903C8: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x807903CC: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x807903D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807903D4: nop

    // 0x807903D8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x807903DC: nop

    // 0x807903E0: bc1fl       L_80790410
    if (!c1cs) {
        // 0x807903E4: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_80790410;
    }
    goto skip_0;
    // 0x807903E4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x807903E8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807903EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x807903F0: nop

    // 0x807903F4: bc1f        L_8079042C
    if (!c1cs) {
        // 0x807903F8: nop
    
            goto L_8079042C;
    }
    // 0x807903F8: nop

    // 0x807903FC: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80790400: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80790404: jr          $ra
    // 0x80790408: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x80790408: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8079040C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_80790410:
    // 0x80790410: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80790414: nop

    // 0x80790418: bc1f        L_8079042C
    if (!c1cs) {
        // 0x8079041C: nop
    
            goto L_8079042C;
    }
    // 0x8079041C: nop

    // 0x80790420: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80790424: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80790428: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_8079042C:
    // 0x8079042C: jr          $ra
    // 0x80790430: nop

    return;
    // 0x80790430: nop

;}
RECOMP_FUNC void func_8064AB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AB90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064AB94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064AB98: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064AB9C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064ABA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064ABA4: blez        $v0, L_8064ABB8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064ABA8: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_8064ABB8;
    }
    // 0x8064ABA8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8064ABAC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064ABB0: b           L_8064ABC8
    // 0x8064ABB4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064ABC8;
    // 0x8064ABB4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064ABB8:
    // 0x8064ABB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064ABBC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064ABC0: jal         0x8064AEA8
    // 0x8064ABC4: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    func_8064AEA8(rdram, ctx);
        goto after_0;
    // 0x8064ABC4: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    after_0:
L_8064ABC8:
    // 0x8064ABC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064ABCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064ABD0: jr          $ra
    // 0x8064ABD4: nop

    return;
    // 0x8064ABD4: nop

;}
RECOMP_FUNC void func_806CCD24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CCD24: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CCD28: lw          $v1, 0x58C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58C);
    // 0x806CCD2C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x806CCD30: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x806CCD34: sw          $t6, 0x58C($v0)
    MEM_W(0X58C, ctx->r2) = ctx->r14;
    // 0x806CCD38: bne         $at, $zero, L_806CCD44
    if (ctx->r1 != 0) {
        // 0x806CCD3C: sw          $v1, 0x588($v0)
        MEM_W(0X588, ctx->r2) = ctx->r3;
            goto L_806CCD44;
    }
    // 0x806CCD3C: sw          $v1, 0x588($v0)
    MEM_W(0X588, ctx->r2) = ctx->r3;
    // 0x806CCD40: sw          $zero, 0x58C($v0)
    MEM_W(0X58C, ctx->r2) = 0;
L_806CCD44:
    // 0x806CCD44: jr          $ra
    // 0x806CCD48: nop

    return;
    // 0x806CCD48: nop

;}
RECOMP_FUNC void func_804C19BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C19BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804C19C0: addiu       $a0, $zero, 0x4121
    ctx->r4 = ADD32(0, 0X4121);
    // 0x804C19C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804C19C8: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
L_804C19CC:
    // 0x804C19CC: lw          $v0, 0x188($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X188);
    // 0x804C19D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804C19D4: beq         $v0, $zero, L_804C1A14
    if (ctx->r2 == 0) {
        // 0x804C19D8: nop
    
            goto L_804C1A14;
    }
    // 0x804C19D8: nop

    // 0x804C19DC: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x804C19E0: bne         $a0, $t6, L_804C1A14
    if (ctx->r4 != ctx->r14) {
        // 0x804C19E4: nop
    
            goto L_804C1A14;
    }
    // 0x804C19E4: nop

    // 0x804C19E8: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x804C19EC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x804C19F0: beq         $v1, $zero, L_804C1A1C
    if (ctx->r3 == 0) {
        // 0x804C19F4: nop
    
            goto L_804C1A1C;
    }
    // 0x804C19F4: nop

    // 0x804C19F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804C19FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x804C1A00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C1A04: swc1        $f4, 0x6CC($v1)
    MEM_W(0X6CC, ctx->r3) = ctx->f4.u32l;
    // 0x804C1A08: lw          $t7, 0x1F4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1F4);
    // 0x804C1A0C: jr          $ra
    // 0x804C1A10: swc1        $f6, 0x6D0($t7)
    MEM_W(0X6D0, ctx->r15) = ctx->f6.u32l;
    return;
    // 0x804C1A10: swc1        $f6, 0x6D0($t7)
    MEM_W(0X6D0, ctx->r15) = ctx->f6.u32l;
L_804C1A14:
    // 0x804C1A14: bne         $v1, $a2, L_804C19CC
    if (ctx->r3 != ctx->r6) {
        // 0x804C1A18: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_804C19CC;
    }
    // 0x804C1A18: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_804C1A1C:
    // 0x804C1A1C: jr          $ra
    // 0x804C1A20: nop

    return;
    // 0x804C1A20: nop

;}
RECOMP_FUNC void func_804C04D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C04D0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x804C04D4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x804C04D8: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x804C04DC: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x804C04E0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x804C04E4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x804C04E8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x804C04EC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x804C04F0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x804C04F4: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x804C04F8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x804C04FC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x804C0500: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x804C0504: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x804C0508: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x804C050C: lw          $s2, 0x180($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X180);
    // 0x804C0510: lw          $s6, 0x16C($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X16C);
    // 0x804C0514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C0518: lw          $s4, 0x174($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X174);
    // 0x804C051C: bne         $s2, $zero, L_804C0534
    if (ctx->r18 != 0) {
        // 0x804C0520: addiu       $s6, $s6, 0xD
        ctx->r22 = ADD32(ctx->r22, 0XD);
            goto L_804C0534;
    }
    // 0x804C0520: addiu       $s6, $s6, 0xD
    ctx->r22 = ADD32(ctx->r22, 0XD);
    // 0x804C0524: jal         0x800447C8
    // 0x804C0528: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x804C0528: nop

    after_0:
    // 0x804C052C: b           L_804C0828
    // 0x804C0530: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_804C0828;
    // 0x804C0530: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_804C0534:
    // 0x804C0534: lbu         $t6, 0x165($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X165);
    // 0x804C0538: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804C053C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804C0540: bne         $t6, $at, L_804C0550
    if (ctx->r14 != ctx->r1) {
        // 0x804C0544: addiu       $a0, $sp, 0xB0
        ctx->r4 = ADD32(ctx->r29, 0XB0);
            goto L_804C0550;
    }
    // 0x804C0544: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x804C0548: b           L_804C0824
    // 0x804C054C: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
        goto L_804C0824;
    // 0x804C054C: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
L_804C0550:
    // 0x804C0550: jal         0x80047AB8
    // 0x804C0554: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x804C0554: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x804C0558: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x804C055C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(197, 0X520) << 16);
    // 0x804C0560: addiu       $a0, $zero, 0x4001
    ctx->r4 = ADD32(0, 0X4001);
    // 0x804C0564: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x804C0568: lwc1        $f8, 0x9E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(197, 0X520));
    // 0x804C056C: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x804C0570: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804C0574: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x804C0578: lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XC);
    // 0x804C057C: bnel        $a0, $v0, L_804C05F8
    if (ctx->r4 != ctx->r2) {
        // 0x804C0580: lw          $v1, 0x174($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X174);
            goto L_804C05F8;
    }
    goto skip_0;
    // 0x804C0580: lw          $v1, 0x174($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X174);
    skip_0:
    // 0x804C0584: lw          $v0, 0x1F4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1F4);
    // 0x804C0588: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804C058C: lbu         $t8, 0x1AC($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1AC);
    // 0x804C0590: bnel        $t8, $zero, L_804C05A4
    if (ctx->r24 != 0) {
        // 0x804C0594: lw          $t0, 0x24($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X24);
            goto L_804C05A4;
    }
    goto skip_1;
    // 0x804C0594: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    skip_1:
    // 0x804C0598: b           L_804C0824
    // 0x804C059C: sb          $t9, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r25;
        goto L_804C0824;
    // 0x804C059C: sb          $t9, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r25;
    // 0x804C05A0: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
L_804C05A4:
    // 0x804C05A4: andi        $t1, $t0, 0x700
    ctx->r9 = ctx->r8 & 0X700;
    // 0x804C05A8: beql        $t1, $zero, L_804C05F8
    if (ctx->r9 == 0) {
        // 0x804C05AC: lw          $v1, 0x174($s2)
        ctx->r3 = MEM_W(ctx->r18, 0X174);
            goto L_804C05F8;
    }
    goto skip_2;
    // 0x804C05AC: lw          $v1, 0x174($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X174);
    skip_2:
    // 0x804C05B0: lw          $t2, 0x174($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X174);
    // 0x804C05B4: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x804C05B8: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x804C05BC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x804C05C0: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x804C05C4: addiu       $t5, $zero, 0x8C
    ctx->r13 = ADD32(0, 0X8C);
    // 0x804C05C8: lw          $t4, 0x34($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X34);
    // 0x804C05CC: lwc1        $f16, 0x10($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X10);
    // 0x804C05D0: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x804C05D4: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x804C05D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804C05DC: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x804C05E0: lwc1        $f10, 0x120($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X120);
    // 0x804C05E4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x804C05E8: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x804C05EC: b           L_804C0824
    // 0x804C05F0: sb          $t5, 0x3($s6)
    MEM_B(0X3, ctx->r22) = ctx->r13;
        goto L_804C0824;
    // 0x804C05F0: sb          $t5, 0x3($s6)
    MEM_B(0X3, ctx->r22) = ctx->r13;
    // 0x804C05F4: lw          $v1, 0x174($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X174);
L_804C05F8:
    // 0x804C05F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x804C05FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C0600: beq         $v1, $zero, L_804C0610
    if (ctx->r3 == 0) {
        // 0x804C0604: nop
    
            goto L_804C0610;
    }
    // 0x804C0604: nop

    // 0x804C0608: b           L_804C0610
    // 0x804C060C: lbu         $s1, 0x10($v1)
    ctx->r17 = MEM_BU(ctx->r3, 0X10);
        goto L_804C0610;
    // 0x804C060C: lbu         $s1, 0x10($v1)
    ctx->r17 = MEM_BU(ctx->r3, 0X10);
L_804C0610:
    // 0x804C0610: sb          $s1, 0x10($s4)
    MEM_B(0X10, ctx->r20) = ctx->r17;
    // 0x804C0614: lhu         $t6, 0xC($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0XC);
    // 0x804C0618: bne         $a0, $t6, L_804C0640
    if (ctx->r4 != ctx->r14) {
        // 0x804C061C: nop
    
            goto L_804C0640;
    }
    // 0x804C061C: nop

    // 0x804C0620: lw          $t7, 0x174($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X174);
    // 0x804C0624: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x804C0628: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804C062C: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x804C0630: lwc1        $f4, 0x10($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X10);
    // 0x804C0634: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804C0638: b           L_804C0674
    // 0x804C063C: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
        goto L_804C0674;
    // 0x804C063C: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
L_804C0640:
    // 0x804C0640: jal         0x8004921C
    // 0x804C0644: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x804C0644: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x804C0648: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x804C064C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(197, 0X524) << 16);
    // 0x804C0650: lwc1        $f16, 0x9E4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(197, 0X524));
    // 0x804C0654: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804C0658: lwc1        $f4, 0x70($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X70);
    // 0x804C065C: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x804C0660: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804C0664: nop

    // 0x804C0668: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804C066C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x804C0670: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
L_804C0674:
    // 0x804C0674: addiu       $s3, $sp, 0xA4
    ctx->r19 = ADD32(ctx->r29, 0XA4);
    // 0x804C0678: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x804C067C: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x804C0680: lwc1        $f14, 0xB4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x804C0684: jal         0x80053790
    // 0x804C0688: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80053790(rdram, ctx);
        goto after_3;
    // 0x804C0688: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x804C068C: lbu         $a0, 0xA4($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0XA4);
    // 0x804C0690: lwc1        $f22, 0x78($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X78);
    // 0x804C0694: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x804C0698: andi        $t0, $a0, 0x2
    ctx->r8 = ctx->r4 & 0X2;
    // 0x804C069C: bne         $t0, $zero, L_804C0714
    if (ctx->r8 != 0) {
        // 0x804C06A0: lwc1        $f16, 0xB4($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
            goto L_804C0714;
    }
    // 0x804C06A0: lwc1        $f16, 0xB4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x804C06A4: beq         $s1, $zero, L_804C06C0
    if (ctx->r17 == 0) {
        // 0x804C06A8: addiu       $v1, $zero, 0x28
        ctx->r3 = ADD32(0, 0X28);
            goto L_804C06C0;
    }
    // 0x804C06A8: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // 0x804C06AC: andi        $t1, $a0, 0xF8
    ctx->r9 = ctx->r4 & 0XF8;
    // 0x804C06B0: xor         $t2, $v1, $t1
    ctx->r10 = ctx->r3 ^ ctx->r9;
    // 0x804C06B4: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x804C06B8: addiu       $t3, $s1, -0x1
    ctx->r11 = ADD32(ctx->r17, -0X1);
    // 0x804C06BC: bne         $t2, $t3, L_804C0714
    if (ctx->r10 != ctx->r11) {
        // 0x804C06C0: lui         $at, 0x804C
        ctx->r1 = S32(RELOC_HI16(197, 0X528) << 16);
            goto L_804C0714;
    }
L_804C06C0:
    // 0x804C06C0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(197, 0X528) << 16);
    // 0x804C06C4: lwc1        $f0, 0x9E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(197, 0X528));
    // 0x804C06C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x804C06CC: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x804C06D0: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x804C06D4: beq         $at, $zero, L_804C0714
    if (ctx->r1 == 0) {
        // 0x804C06D8: addiu       $v1, $zero, 0x28
        ctx->r3 = ADD32(0, 0X28);
            goto L_804C0714;
    }
    // 0x804C06D8: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // 0x804C06DC: sll         $t5, $s2, 1
    ctx->r13 = S32(ctx->r18 << 1);
    // 0x804C06E0: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x804C06E4: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x804C06E8: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x804C06EC: bnel        $t7, $zero, L_804C0718
    if (ctx->r15 != 0) {
        // 0x804C06F0: mtc1        $s2, $f18
        ctx->f18.u32l = ctx->r18;
            goto L_804C0718;
    }
    goto skip_3;
    // 0x804C06F0: mtc1        $s2, $f18
    ctx->f18.u32l = ctx->r18;
    skip_3:
    // 0x804C06F4: beq         $s1, $zero, L_804C06C0
    if (ctx->r17 == 0) {
        // 0x804C06F8: nop
    
            goto L_804C06C0;
    }
    // 0x804C06F8: nop

    // 0x804C06FC: andi        $t8, $v0, 0xF8
    ctx->r24 = ctx->r2 & 0XF8;
    // 0x804C0700: xor         $t9, $v1, $t8
    ctx->r25 = ctx->r3 ^ ctx->r24;
    // 0x804C0704: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x804C0708: addiu       $t0, $s1, -0x1
    ctx->r8 = ADD32(ctx->r17, -0X1);
    // 0x804C070C: beq         $t9, $t0, L_804C06C0
    if (ctx->r25 == ctx->r8) {
        // 0x804C0710: nop
    
            goto L_804C06C0;
    }
    // 0x804C0710: nop

L_804C0714:
    // 0x804C0714: mtc1        $s2, $f18
    ctx->f18.u32l = ctx->r18;
L_804C0718:
    // 0x804C0718: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804C071C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x804C0720: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804C0724: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x804C0728: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x804C072C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804C0730: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x804C0734: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x804C0738: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x804C073C: lui         $s3, 0x8005
    ctx->r19 = S32(0X8005 << 16);
    // 0x804C0740: lui         $s5, 0x8006
    ctx->r21 = S32(0X8006 << 16);
    // 0x804C0744: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x804C0748: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x804C074C: sb          $t2, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r10;
    // 0x804C0750: addiu       $s5, $s5, 0x5284
    ctx->r21 = ADD32(ctx->r21, 0X5284);
    // 0x804C0754: addiu       $s3, $s3, -0x3108
    ctx->r19 = ADD32(ctx->r19, -0X3108);
    // 0x804C0758: sub.s       $f20, $f4, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f24.fl;
L_804C075C:
    // 0x804C075C: mul.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x804C0760: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x804C0764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C0768: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x804C076C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x804C0770: jal         0x80049D74
    // 0x804C0774: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    func_80049D74(rdram, ctx);
        goto after_4;
    // 0x804C0774: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    after_4:
    // 0x804C0778: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x804C077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C0780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C0784: jal         0x8004D150
    // 0x804C0788: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8004D150(rdram, ctx);
        goto after_5;
    // 0x804C0788: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_5:
    // 0x804C078C: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x804C0790: negu        $s1, $s2
    ctx->r17 = SUB32(0, ctx->r18);
    // 0x804C0794: addu        $at, $s1, $zero
    ctx->r1 = ADD32(ctx->r17, 0);
    // 0x804C0798: lw          $t4, 0x40($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X40);
    // 0x804C079C: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x804C07A0: subu        $s1, $s1, $at
    ctx->r17 = SUB32(ctx->r17, ctx->r1);
    // 0x804C07A4: lbu         $t5, 0x14($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X14);
    // 0x804C07A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C07AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C07B0: beq         $t5, $zero, L_804C07FC
    if (ctx->r13 == 0) {
        // 0x804C07B4: or          $a2, $s5, $zero
        ctx->r6 = ctx->r21 | 0;
            goto L_804C07FC;
    }
    // 0x804C07B4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x804C07B8: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x804C07BC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804C07C0: jal         0x8004D618
    // 0x804C07C4: addiu       $s1, $s1, 0x8C
    ctx->r17 = ADD32(ctx->r17, 0X8C);
    func_8004D618(rdram, ctx);
        goto after_6;
    // 0x804C07C4: addiu       $s1, $s1, 0x8C
    ctx->r17 = ADD32(ctx->r17, 0X8C);
    after_6:
    // 0x804C07C8: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x804C07CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804C07D0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x804C07D4: jal         0x8004A97C
    // 0x804C07D8: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    func_8004A97C(rdram, ctx);
        goto after_7;
    // 0x804C07D8: lhu         $a0, 0x0($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X0);
    after_7:
    // 0x804C07DC: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x804C07E0: swc1        $f22, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f22.u32l;
    // 0x804C07E4: swc1        $f22, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f22.u32l;
    // 0x804C07E8: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x804C07EC: mov.s       $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    ctx->f20.fl = ctx->f30.fl;
    // 0x804C07F0: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x804C07F4: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x804C07F8: sb          $s1, 0x3($s6)
    MEM_B(0X3, ctx->r22) = ctx->r17;
L_804C07FC:
    // 0x804C07FC: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x804C0800: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(197, 0X52C) << 16);
    // 0x804C0804: lwc1        $f8, 0x9EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(197, 0X52C));
    // 0x804C0808: trunc.w.s   $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x804C080C: mul.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x804C0810: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x804C0814: nop

    // 0x804C0818: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x804C081C: bne         $at, $zero, L_804C075C
    if (ctx->r1 != 0) {
        // 0x804C0820: nop
    
            goto L_804C075C;
    }
    // 0x804C0820: nop

L_804C0824:
    // 0x804C0824: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_804C0828:
    // 0x804C0828: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804C082C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804C0830: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804C0834: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804C0838: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x804C083C: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x804C0840: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x804C0844: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x804C0848: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x804C084C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x804C0850: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x804C0854: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x804C0858: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x804C085C: jr          $ra
    // 0x804C0860: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x804C0860: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
