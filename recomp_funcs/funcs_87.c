#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8006E558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E55C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E560: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006E564: jal         0x8006E248
    // 0x8006E568: addiu       $a1, $a1, -0x1BBC
    ctx->r5 = ADD32(ctx->r5, -0X1BBC);
    func_8006E248(rdram, ctx);
        goto after_0;
    // 0x8006E568: addiu       $a1, $a1, -0x1BBC
    ctx->r5 = ADD32(ctx->r5, -0X1BBC);
    after_0:
    // 0x8006E56C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E574: jr          $ra
    // 0x8006E578: nop

    return;
    // 0x8006E578: nop

;}
RECOMP_FUNC void func_804E7CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E7CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E7CD8: jal         0x804E7920
    // 0x804E7CDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804E7920(rdram, ctx);
        goto after_0;
    // 0x804E7CDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804E7CE0: jal         0x804E7C10
    // 0x804E7CE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804E7C10(rdram, ctx);
        goto after_1;
    // 0x804E7CE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804E7CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E7CEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E7CF0: jr          $ra
    // 0x804E7CF4: nop

    return;
    // 0x804E7CF4: nop

;}
RECOMP_FUNC void func_8052F650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052F650: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8052F654: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x8052F658: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8052F65C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8052F660: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052F664: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8052F668: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8052F66C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052F670: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8052F674: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052F678: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8052F67C: lw          $t8, 0x116C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X116C);
    // 0x8052F680: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8052F684: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8052F688: nop

    // 0x8052F68C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8052F690: bltzl       $v1, L_8052F974
    if (SIGNED(ctx->r3) < 0) {
        // 0x8052F694: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8052F974;
    }
    goto skip_0;
    // 0x8052F694: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_0:
    // 0x8052F698: lw          $t9, 0x1160($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1160);
    // 0x8052F69C: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x8052F6A0: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8052F6A4: beql        $at, $zero, L_8052F974
    if (ctx->r1 == 0) {
        // 0x8052F6A8: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8052F974;
    }
    goto skip_1;
    // 0x8052F6A8: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_1:
    // 0x8052F6AC: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8052F6B0: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8052F6B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052F6B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8052F6BC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8052F6C0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8052F6C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052F6C8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8052F6CC: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8052F6D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052F6D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8052F6D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8052F6DC: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8052F6E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8052F6E4: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8052F6E8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8052F6EC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8052F6F0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8052F6F4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8052F6F8: nop

    // 0x8052F6FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8052F700: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8052F704: nop

    // 0x8052F708: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8052F70C: beql        $t4, $zero, L_8052F75C
    if (ctx->r12 == 0) {
        // 0x8052F710: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_8052F75C;
    }
    goto skip_2;
    // 0x8052F710: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x8052F714: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052F718: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8052F71C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8052F720: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8052F724: nop

    // 0x8052F728: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8052F72C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8052F730: nop

    // 0x8052F734: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8052F738: bne         $t4, $zero, L_8052F750
    if (ctx->r12 != 0) {
        // 0x8052F73C: nop
    
            goto L_8052F750;
    }
    // 0x8052F73C: nop

    // 0x8052F740: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8052F744: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8052F748: b           L_8052F768
    // 0x8052F74C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8052F768;
    // 0x8052F74C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8052F750:
    // 0x8052F750: b           L_8052F768
    // 0x8052F754: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8052F768;
    // 0x8052F754: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8052F758: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_8052F75C:
    // 0x8052F75C: nop

    // 0x8052F760: bltz        $t4, L_8052F750
    if (SIGNED(ctx->r12) < 0) {
        // 0x8052F764: nop
    
            goto L_8052F750;
    }
    // 0x8052F764: nop

L_8052F768:
    // 0x8052F768: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8052F76C: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8052F770: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8052F774: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8052F778: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8052F77C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8052F780: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8052F784: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052F788: addu        $t0, $v0, $t6
    ctx->r8 = ADD32(ctx->r2, ctx->r14);
    // 0x8052F78C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052F790: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8052F794: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8052F798: sub.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8052F79C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8052F7A0: lwc1        $f14, 0xF6C($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0XF6C);
    // 0x8052F7A4: lwc1        $f2, 0xF70($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0XF70);
    // 0x8052F7A8: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8052F7AC: nop

    // 0x8052F7B0: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8052F7B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8052F7B8: sub.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8052F7BC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8052F7C0: nop

    // 0x8052F7C4: bc1f        L_8052F970
    if (!c1cs) {
        // 0x8052F7C8: nop
    
            goto L_8052F970;
    }
    // 0x8052F7C8: nop

    // 0x8052F7CC: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8052F7D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052F7D4: lwc1        $f4, 0x115C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X115C);
    // 0x8052F7D8: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2450) << 16);
    // 0x8052F7DC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8052F7E0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8052F7E4: lwc1        $f4, 0xF68($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XF68);
    // 0x8052F7E8: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8052F7EC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8052F7F0: sub.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8052F7F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8052F7F8: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8052F7FC: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8052F800: nop

    // 0x8052F804: bc1f        L_8052F810
    if (!c1cs) {
        // 0x8052F808: nop
    
            goto L_8052F810;
    }
    // 0x8052F808: nop

    // 0x8052F80C: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
L_8052F810:
    // 0x8052F810: mul.s       $f16, $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8052F814: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8052F818: sub.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x8052F81C: mul.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8052F820: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8052F824: blez        $v1, L_8052F884
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8052F828: swc1        $f8, 0xF6C($t0)
        MEM_W(0XF6C, ctx->r8) = ctx->f8.u32l;
            goto L_8052F884;
    }
    // 0x8052F828: swc1        $f8, 0xF6C($t0)
    MEM_W(0XF6C, ctx->r8) = ctx->f8.u32l;
    // 0x8052F82C: lwc1        $f22, 0x210($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2450));
    // 0x8052F830: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8052F834: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8052F838: nop

    // 0x8052F83C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
L_8052F840:
    // 0x8052F840: addu        $t1, $v0, $t7
    ctx->r9 = ADD32(ctx->r2, ctx->r15);
    // 0x8052F844: lwc1        $f14, 0xF68($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0XF68);
    // 0x8052F848: lwc1        $f10, 0xF6C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XF6C);
    // 0x8052F84C: sub.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8052F850: add.s       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8052F854: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8052F858: nop

    // 0x8052F85C: bc1fl       L_8052F87C
    if (!c1cs) {
        // 0x8052F860: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8052F87C;
    }
    goto skip_3;
    // 0x8052F860: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    skip_3:
    // 0x8052F864: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x8052F868: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8052F86C: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8052F870: b           L_8052F87C
    // 0x8052F874: swc1        $f8, 0xF68($t1)
    MEM_W(0XF68, ctx->r9) = ctx->f8.u32l;
        goto L_8052F87C;
    // 0x8052F874: swc1        $f8, 0xF68($t1)
    MEM_W(0XF68, ctx->r9) = ctx->f8.u32l;
    // 0x8052F878: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8052F87C:
    // 0x8052F87C: bgtzl       $a3, L_8052F840
    if (SIGNED(ctx->r7) > 0) {
        // 0x8052F880: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_8052F840;
    }
    goto skip_4;
    // 0x8052F880: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    skip_4:
L_8052F884:
    // 0x8052F884: lwc1        $f10, 0xF70($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XF70);
    // 0x8052F888: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8052F88C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8052F890: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8052F894: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2454) << 16);
    // 0x8052F898: lwc1        $f22, 0x214($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2454));
    // 0x8052F89C: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
    // 0x8052F8A0: swc1        $f4, 0xF70($t0)
    MEM_W(0XF70, ctx->r8) = ctx->f4.u32l;
    // 0x8052F8A4: lw          $a0, 0x1160($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1160);
    // 0x8052F8A8: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
    // 0x8052F8AC: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8052F8B0: beq         $at, $zero, L_8052F908
    if (ctx->r1 == 0) {
        // 0x8052F8B4: sll         $t8, $a3, 2
        ctx->r24 = S32(ctx->r7 << 2);
            goto L_8052F908;
    }
    // 0x8052F8B4: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
L_8052F8B8:
    // 0x8052F8B8: addu        $t1, $v0, $t8
    ctx->r9 = ADD32(ctx->r2, ctx->r24);
    // 0x8052F8BC: lwc1        $f2, 0xF70($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0XF70);
    // 0x8052F8C0: lwc1        $f6, 0xF6C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XF6C);
    // 0x8052F8C4: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8052F8C8: add.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8052F8CC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8052F8D0: nop

    // 0x8052F8D4: bc1fl       L_8052F8FC
    if (!c1cs) {
        // 0x8052F8D8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8052F8FC;
    }
    goto skip_5;
    // 0x8052F8D8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    skip_5:
    // 0x8052F8DC: mul.s       $f10, $f12, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x8052F8E0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8052F8E4: sub.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8052F8E8: swc1        $f4, 0xF70($t1)
    MEM_W(0XF70, ctx->r9) = ctx->f4.u32l;
    // 0x8052F8EC: lw          $a0, 0x1160($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1160);
    // 0x8052F8F0: b           L_8052F8FC
    // 0x8052F8F4: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
        goto L_8052F8FC;
    // 0x8052F8F4: addiu       $a2, $a0, -0x1
    ctx->r6 = ADD32(ctx->r4, -0X1);
    // 0x8052F8F8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_8052F8FC:
    // 0x8052F8FC: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8052F900: bnel        $at, $zero, L_8052F8B8
    if (ctx->r1 != 0) {
        // 0x8052F904: sll         $t8, $a3, 2
        ctx->r24 = S32(ctx->r7 << 2);
            goto L_8052F8B8;
    }
    goto skip_6;
    // 0x8052F904: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    skip_6:
L_8052F908:
    // 0x8052F908: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2458) << 16);
    // 0x8052F90C: lwc1        $f0, 0x218($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2458));
    // 0x8052F910: lwc1        $f2, 0xF70($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0XF70);
    // 0x8052F914: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X245C) << 16);
    // 0x8052F918: lwc1        $f12, 0x21C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X245C));
    // 0x8052F91C: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8052F920: lwc1        $f8, 0xF6C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XF6C);
    // 0x8052F924: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052F928: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    // 0x8052F92C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8052F930: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8052F934: swc1        $f4, 0xF6C($t0)
    MEM_W(0XF6C, ctx->r8) = ctx->f4.u32l;
    // 0x8052F938: lwc1        $f8, 0xF6C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XF6C);
    // 0x8052F93C: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8052F940: nop

    // 0x8052F944: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8052F948: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8052F94C: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8052F950: swc1        $f4, 0xF70($t0)
    MEM_W(0XF70, ctx->r8) = ctx->f4.u32l;
    // 0x8052F954: lwc1        $f8, 0x40($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X40);
    // 0x8052F958: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8052F95C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052F960: swc1        $f10, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f10.u32l;
    // 0x8052F964: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8052F968: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8052F96C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_8052F970:
    // 0x8052F970: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_8052F974:
    // 0x8052F974: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x8052F978: jr          $ra
    // 0x8052F97C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8052F97C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80445930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445938: addiu       $a0, $zero, 0x228
    ctx->r4 = ADD32(0, 0X228);
    // 0x8044593C: jal         0x80067818
    // 0x80445940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x80445940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80445944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044594C: jr          $ra
    // 0x80445950: nop

    return;
    // 0x80445950: nop

;}
RECOMP_FUNC void func_804C94F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C94F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C94F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C94F8: jal         0x800483B8
    // 0x804C94FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800483B8(rdram, ctx);
        goto after_0;
    // 0x804C94FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C9500: jal         0x804C93A4
    // 0x804C9504: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804C93A4(rdram, ctx);
        goto after_1;
    // 0x804C9504: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804C9508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C950C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C9510: jr          $ra
    // 0x804C9514: nop

    return;
    // 0x804C9514: nop

;}
RECOMP_FUNC void func_800520E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800520E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800520E4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800520E8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800520EC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800520F0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800520F4: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800520F8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800520FC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80052100: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80052104: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80052108: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005210C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80052110: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80052114: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80052118: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8005211C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80052120: beq         $a2, $at, L_8005225C
    if (ctx->r6 == ctx->r1) {
        // 0x80052124: lw          $s1, 0xC($a0)
        ctx->r17 = MEM_W(ctx->r4, 0XC);
            goto L_8005225C;
    }
    // 0x80052124: lw          $s1, 0xC($a0)
    ctx->r17 = MEM_W(ctx->r4, 0XC);
    // 0x80052128: bltz        $a2, L_8005225C
    if (SIGNED(ctx->r6) < 0) {
        // 0x8005212C: slti        $at, $a2, 0x7FFF
        ctx->r1 = SIGNED(ctx->r6) < 0X7FFF ? 1 : 0;
            goto L_8005225C;
    }
    // 0x8005212C: slti        $at, $a2, 0x7FFF
    ctx->r1 = SIGNED(ctx->r6) < 0X7FFF ? 1 : 0;
    // 0x80052130: beq         $at, $zero, L_8005225C
    if (ctx->r1 == 0) {
        // 0x80052134: sll         $t7, $s1, 5
        ctx->r15 = S32(ctx->r17 << 5);
            goto L_8005225C;
    }
    // 0x80052134: sll         $t7, $s1, 5
    ctx->r15 = S32(ctx->r17 << 5);
    // 0x80052138: sh          $a2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r6;
    // 0x8005213C: sll         $t8, $a2, 7
    ctx->r24 = S32(ctx->r6 << 7);
    // 0x80052140: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80052144: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x80052148: addu        $s5, $a1, $t8
    ctx->r21 = ADD32(ctx->r5, ctx->r24);
    // 0x8005214C: addu        $s0, $a0, $t9
    ctx->r16 = ADD32(ctx->r4, ctx->r25);
    // 0x80052150: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x80052154: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x80052158: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005215C: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80052160: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x80052164: sll         $t7, $t7, 9
    ctx->r15 = S32(ctx->r15 << 9);
    // 0x80052168: beq         $a1, $t0, L_8005218C
    if (ctx->r5 == ctx->r8) {
        // 0x8005216C: addu        $s6, $t6, $t7
        ctx->r22 = ADD32(ctx->r14, ctx->r15);
            goto L_8005218C;
    }
    // 0x8005216C: addu        $s6, $t6, $t7
    ctx->r22 = ADD32(ctx->r14, ctx->r15);
    // 0x80052170: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80052174: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x80052178: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8005217C: jal         0x800675D0
    // 0x80052180: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x80052180: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_0:
    // 0x80052184: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x80052188: sw          $t1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r9;
L_8005218C:
    // 0x8005218C: lw          $t2, 0x3DC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X3DC);
    // 0x80052190: addiu       $a0, $s6, 0x400
    ctx->r4 = ADD32(ctx->r22, 0X400);
    // 0x80052194: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80052198: beq         $s2, $t2, L_800521B0
    if (ctx->r18 == ctx->r10) {
        // 0x8005219C: addiu       $a2, $zero, 0x200
        ctx->r6 = ADD32(0, 0X200);
            goto L_800521B0;
    }
    // 0x8005219C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    // 0x800521A0: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x800521A4: jal         0x800675D0
    // 0x800521A8: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    func_800675D0(rdram, ctx);
        goto after_1;
    // 0x800521A8: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    after_1:
    // 0x800521AC: sw          $s2, 0x3DC($s0)
    MEM_W(0X3DC, ctx->r16) = ctx->r18;
L_800521B0:
    // 0x800521B0: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800521B4: lw          $t3, 0x5AD0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5AD0);
    // 0x800521B8: beql        $t3, $zero, L_80052260
    if (ctx->r11 == 0) {
        // 0x800521BC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80052260;
    }
    goto skip_0;
    // 0x800521BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800521C0: lbu         $v1, 0x4($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X4);
    // 0x800521C4: addiu       $s0, $s5, 0x8
    ctx->r16 = ADD32(ctx->r21, 0X8);
    // 0x800521C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800521CC: blez        $v1, L_80052240
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800521D0: sll         $t4, $s1, 4
        ctx->r12 = S32(ctx->r17 << 4);
            goto L_80052240;
    }
    // 0x800521D0: sll         $t4, $s1, 4
    ctx->r12 = S32(ctx->r17 << 4);
    // 0x800521D4: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x800521D8: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x800521DC: addu        $s4, $s7, $t4
    ctx->r20 = ADD32(ctx->r23, ctx->r12);
    // 0x800521E0: addiu       $s4, $s4, 0x1C
    ctx->r20 = ADD32(ctx->r20, 0X1C);
L_800521E4:
    // 0x800521E4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800521E8: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800521EC: lui         $s3, 0x8006
    ctx->r19 = S32(0X8006 << 16);
    // 0x800521F0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800521F4: addu        $s1, $t5, $s4
    ctx->r17 = ADD32(ctx->r13, ctx->r20);
    // 0x800521F8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800521FC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80052200: beql        $t6, $t7, L_80052234
    if (ctx->r14 == ctx->r15) {
        // 0x80052204: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80052234;
    }
    goto skip_1;
    // 0x80052204: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80052208: jal         0x80051EC8
    // 0x8005220C: addiu       $s3, $s3, 0x758C
    ctx->r19 = ADD32(ctx->r19, 0X758C);
    func_80051EC8(rdram, ctx);
        goto after_2;
    // 0x8005220C: addiu       $s3, $s3, 0x758C
    ctx->r19 = ADD32(ctx->r19, 0X758C);
    after_2:
    // 0x80052210: addu        $a0, $v0, $s6
    ctx->r4 = ADD32(ctx->r2, ctx->r22);
    // 0x80052214: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80052218: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x8005221C: jal         0x800675D0
    // 0x80052220: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_800675D0(rdram, ctx);
        goto after_3;
    // 0x80052220: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_3:
    // 0x80052224: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80052228: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8005222C: lbu         $v1, 0x4($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X4);
    // 0x80052230: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80052234:
    // 0x80052234: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80052238: bne         $at, $zero, L_800521E4
    if (ctx->r1 != 0) {
        // 0x8005223C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_800521E4;
    }
    // 0x8005223C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80052240:
    // 0x80052240: lw          $t9, 0xC($s7)
    ctx->r25 = MEM_W(ctx->r23, 0XC);
    // 0x80052244: sw          $s6, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r22;
    // 0x80052248: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8005224C: sltiu       $at, $t0, 0x2
    ctx->r1 = ctx->r8 < 0X2 ? 1 : 0;
    // 0x80052250: bne         $at, $zero, L_8005225C
    if (ctx->r1 != 0) {
        // 0x80052254: sw          $t0, 0xC($s7)
        MEM_W(0XC, ctx->r23) = ctx->r8;
            goto L_8005225C;
    }
    // 0x80052254: sw          $t0, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r8;
    // 0x80052258: sw          $zero, 0xC($s7)
    MEM_W(0XC, ctx->r23) = 0;
L_8005225C:
    // 0x8005225C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80052260:
    // 0x80052260: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80052264: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80052268: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8005226C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80052270: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80052274: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80052278: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8005227C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80052280: jr          $ra
    // 0x80052284: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80052284: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80052288: nop

    // 0x8005228C: nop

;}
RECOMP_FUNC void func_8000AC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AC90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000AC94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AC98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000AC9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000ACA0: jal         0x800825F0
    // 0x8000ACA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8000ACA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8000ACA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000ACAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000ACB0: jal         0x8008AED0
    // 0x8000ACB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x8000ACB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8000ACB8: jal         0x800825F0
    // 0x8000ACBC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x8000ACBC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8000ACC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000ACC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000ACC8: jr          $ra
    // 0x8000ACCC: nop

    return;
    // 0x8000ACCC: nop

;}
RECOMP_FUNC void func_804C0B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0B5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C0B60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804C0B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C0B68: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x804C0B6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C0B70: jal         0x80048F84
    // 0x804C0B74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x804C0B74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804C0B78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C0B7C: jal         0x80048F84
    // 0x804C0B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804C0B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804C0B84: jal         0x804C0C2C
    // 0x804C0B88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804C0C2C(rdram, ctx);
        goto after_2;
    // 0x804C0B88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x804C0B8C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x804C0B90: lui         $a1, 0x804C
    ctx->r5 = S32(RELOC_HI16(200, 0X408) << 16);
    // 0x804C0B94: lh          $t8, 0x144($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X144);
    // 0x804C0B98: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x804C0B9C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C0BA0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x804C0BA4: lw          $a1, 0xE68($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(200, 0X408));
    // 0x804C0BA8: jal         0x8005772C
    // 0x804C0BAC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_8005772C(rdram, ctx);
        goto after_3;
    // 0x804C0BAC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x804C0BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C0BB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C0BB8: jr          $ra
    // 0x804C0BBC: nop

    return;
    // 0x804C0BBC: nop

;}
RECOMP_FUNC void func_80029FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029FA4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80029FA8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80029FAC: lw          $t6, -0x7D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D6C);
    // 0x80029FB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80029FB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80029FB8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80029FBC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80029FC0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80029FC4: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80029FC8: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x80029FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80029FD0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80029FD4: lw          $t9, 0x1F4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X1F4);
    // 0x80029FD8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80029FDC: addiu       $a1, $a1, -0x216C
    ctx->r5 = ADD32(ctx->r5, -0X216C);
    // 0x80029FE0: jal         0x80029CC0
    // 0x80029FE4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    func_80029CC0(rdram, ctx);
        goto after_0;
    // 0x80029FE4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    after_0:
    // 0x80029FE8: jal         0x80029CFC
    // 0x80029FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80029CFC(rdram, ctx);
        goto after_1;
    // 0x80029FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80029FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80029FF4: jal         0x80029D84
    // 0x80029FF8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80029D84(rdram, ctx);
        goto after_2;
    // 0x80029FF8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x80029FFC: jal         0x80029DE8
    // 0x8002A000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80029DE8(rdram, ctx);
        goto after_3;
    // 0x8002A000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8002A004: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002A008: addiu       $a2, $a2, -0x215C
    ctx->r6 = ADD32(ctx->r6, -0X215C);
    // 0x8002A00C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002A010: jal         0x80029E60
    // 0x8002A014: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80029E60(rdram, ctx);
        goto after_4;
    // 0x8002A014: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x8002A018: jal         0x80029F70
    // 0x8002A01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80029F70(rdram, ctx);
        goto after_5;
    // 0x8002A01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8002A020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A024: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002A028: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8002A02C: jr          $ra
    // 0x8002A030: nop

    return;
    // 0x8002A030: nop

;}
RECOMP_FUNC void func_8002C29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C29C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C2A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C2A4: jal         0x8002C1E0
    // 0x8002C2A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8002C1E0(rdram, ctx);
        goto after_0;
    // 0x8002C2A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002C2AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C2B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002C2B4: sw          $t6, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r14;
    // 0x8002C2B8: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x8002C2BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C2C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C2C4: jr          $ra
    // 0x8002C2C8: nop

    return;
    // 0x8002C2C8: nop

;}
RECOMP_FUNC void func_8001BE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BE40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001BE44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001BE48: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8001BE4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001BE50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001BE54: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8001BE58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001BE5C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8001BE60: sll         $s1, $a1, 1
    ctx->r17 = S32(ctx->r5 << 1);
    // 0x8001BE64: sll         $s2, $a2, 1
    ctx->r18 = S32(ctx->r6 << 1);
    // 0x8001BE68: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8001BE6C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001BE70: andi        $a3, $s0, 0xFFFF
    ctx->r7 = ctx->r16 & 0XFFFF;
    // 0x8001BE74: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8001BE78: jal         0x80050404
    // 0x8001BE7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80050404(rdram, ctx);
        goto after_0;
    // 0x8001BE7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8001BE80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001BE84: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8001BE88: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x8001BE8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001BE90: andi        $a3, $s0, 0xFFFF
    ctx->r7 = ctx->r16 & 0XFFFF;
    // 0x8001BE94: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001BE98: jal         0x80050404
    // 0x8001BE9C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80050404(rdram, ctx);
        goto after_1;
    // 0x8001BE9C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x8001BEA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001BEA4: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8001BEA8: addiu       $a2, $s2, 0x1
    ctx->r6 = ADD32(ctx->r18, 0X1);
    // 0x8001BEAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001BEB0: andi        $a3, $s0, 0xFFFF
    ctx->r7 = ctx->r16 & 0XFFFF;
    // 0x8001BEB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001BEB8: jal         0x80050404
    // 0x8001BEBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80050404(rdram, ctx);
        goto after_2;
    // 0x8001BEBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8001BEC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001BEC4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001BEC8: andi        $a3, $s0, 0xFFFF
    ctx->r7 = ctx->r16 & 0XFFFF;
    // 0x8001BECC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8001BED0: jal         0x80050404
    // 0x8001BED4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80050404(rdram, ctx);
        goto after_3;
    // 0x8001BED4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8001BED8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001BEDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001BEE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BEE4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001BEE8: jr          $ra
    // 0x8001BEEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001BEEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001BA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001BA94: nop

    // 0x8001BA98: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8001BA9C: nop

    // 0x8001BAA0: bc1fl       L_8001BAB4
    if (!c1cs) {
        // 0x8001BAA4: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001BAB4;
    }
    goto skip_0;
    // 0x8001BAA4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x8001BAA8: jr          $ra
    // 0x8001BAAC: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    return;
    // 0x8001BAAC: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x8001BAB0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001BAB4:
    // 0x8001BAB4: jr          $ra
    // 0x8001BAB8: nop

    return;
    // 0x8001BAB8: nop

;}
RECOMP_FUNC void func_8077FD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FD9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8077FDA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077FDA4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8077FDA8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8077FDAC: beq         $v0, $zero, L_8077FDBC
    if (ctx->r2 == 0) {
        // 0x8077FDB0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8077FDBC;
    }
    // 0x8077FDB0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8077FDB4: b           L_8077FDE4
    // 0x8077FDB8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8077FDE4;
    // 0x8077FDB8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8077FDBC:
    // 0x8077FDBC: jal         0x8004700C
    // 0x8077FDC0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8077FDC0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8077FDC4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8077FDC8: beq         $v0, $zero, L_8077FDE4
    if (ctx->r2 == 0) {
        // 0x8077FDCC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8077FDE4;
    }
    // 0x8077FDCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8077FDD0: jal         0x8002F8EC
    // 0x8077FDD4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8002F8EC(rdram, ctx);
        goto after_1;
    // 0x8077FDD4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8077FDD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8077FDDC: jal         0x807800BC
    // 0x8077FDE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_807800BC(rdram, ctx);
        goto after_2;
    // 0x8077FDE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8077FDE4:
    // 0x8077FDE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8077FDE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8077FDEC: jr          $ra
    // 0x8077FDF0: nop

    return;
    // 0x8077FDF0: nop

;}
RECOMP_FUNC void func_80436F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436F3C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80436F40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80436F44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80436F48: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80436F4C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80436F50: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80436F54: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80436F58: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80436F5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80436F60: div.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80436F64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80436F68: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x80436F6C: nop

    // 0x80436F70: bc1fl       L_80437038
    if (!c1cs) {
        // 0x80436F74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80437038;
    }
    goto skip_0;
    // 0x80436F74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80436F78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80436F7C: nop

    // 0x80436F80: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80436F84: nop

    // 0x80436F88: bc1fl       L_80437038
    if (!c1cs) {
        // 0x80436F8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80437038;
    }
    goto skip_1;
    // 0x80436F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80436F90: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80436F94: jal         0x80081FB0
    // 0x80436F98: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    Math_FAcosF(rdram, ctx);
        goto after_0;
    // 0x80436F98: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80436F9C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F60) << 16);
    // 0x80436FA0: lwc1        $f10, -0x7800($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F60));
    // 0x80436FA4: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F64) << 16);
    // 0x80436FA8: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80436FAC: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80436FB0: lwc1        $f16, -0x77FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F64));
    // 0x80436FB4: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80436FB8: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x80436FBC: jal         0x80066DE4
    // 0x80436FC0: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80436FC0: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80436FC4: jal         0x80065954
    // 0x80436FC8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80436FC8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x80436FCC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80436FD0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80436FD4: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80436FD8: lwc1        $f4, 0xC4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC4);
    // 0x80436FDC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80436FE0: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80436FE4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80436FE8: nop

    // 0x80436FEC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80436FF0: jal         0x80436EAC
    // 0x80436FF4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_80436EAC(rdram, ctx);
        goto after_3;
    // 0x80436FF4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80436FF8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F68) << 16);
    // 0x80436FFC: lwc1        $f4, -0x77F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F68));
    // 0x80437000: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80437004: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80437008: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8043700C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80437010: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80437014: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80437018: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8043701C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80437020: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80437024: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80437028: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8043702C: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80437030: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80437034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80437038:
    // 0x80437038: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043703C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80437040: jr          $ra
    // 0x80437044: nop

    return;
    // 0x80437044: nop

;}
RECOMP_FUNC void func_8046AA28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046AA28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046AA2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046AA30: jal         0x8046A1F8
    // 0x8046AA34: nop

    func_8046A1F8(rdram, ctx);
        goto after_0;
    // 0x8046AA34: nop

    after_0:
    // 0x8046AA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046AA3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046AA40: jr          $ra
    // 0x8046AA44: nop

    return;
    // 0x8046AA44: nop

;}
RECOMP_FUNC void func_800714C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800714C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800714C4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800714C8: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x800714CC: addiu       $s4, $s4, -0x6360
    ctx->r20 = ADD32(ctx->r20, -0X6360);
    // 0x800714D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800714D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800714D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800714DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800714E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800714E4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800714E8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800714EC: addiu       $a1, $a1, 0x1AF4
    ctx->r5 = ADD32(ctx->r5, 0X1AF4);
    // 0x800714F0: jal         0x8007E3D0
    // 0x800714F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8007E3D0(rdram, ctx);
        goto after_0;
    // 0x800714F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x800714F8: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x800714FC: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x80071500: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80071504: addiu       $s0, $s0, -0x25F0
    ctx->r16 = ADD32(ctx->r16, -0X25F0);
    // 0x80071508: addiu       $s2, $s2, -0x7AF0
    ctx->r18 = ADD32(ctx->r18, -0X7AF0);
    // 0x8007150C: addiu       $s3, $s3, -0x6340
    ctx->r19 = ADD32(ctx->r19, -0X6340);
    // 0x80071510: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80071514: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80071518:
    // 0x80071518: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8007151C: jal         0x800824B0
    // 0x80071520: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80071520: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80071524: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80071528: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8007152C: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80071530: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    // 0x80071534: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x80071538: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x8007153C: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x80071540: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80071544: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x80071548: sw          $t0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r8;
    // 0x8007154C: sw          $t1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r9;
    // 0x80071550: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x80071554: lw          $t3, 0x3C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X3C);
    // 0x80071558: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8007155C: sw          $t2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r10;
    // 0x80071560: sw          $t3, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r11;
    // 0x80071564: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x80071568: sw          $t5, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r13;
    // 0x8007156C: lw          $t6, 0x48($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X48);
    // 0x80071570: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x80071574: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80071578: sw          $t6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r14;
    // 0x8007157C: sw          $t7, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r15;
    // 0x80071580: sw          $t8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r24;
    // 0x80071584: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80071588: jal         0x80076828
    // 0x8007158C: sw          $t9, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r25;
    func_80076828(rdram, ctx);
        goto after_2;
    // 0x8007158C: sw          $t9, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r25;
    after_2:
    // 0x80071590: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80071594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071598: jal         0x80082210
    // 0x8007159C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8007159C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800715A0: b           L_80071518
    // 0x800715A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_80071518;
    // 0x800715A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800715A8: nop

    // 0x800715AC: nop

    // 0x800715B0: nop

    // 0x800715B4: nop

    // 0x800715B8: nop

    // 0x800715BC: nop

    // 0x800715C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800715C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800715C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800715CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800715D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800715D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800715D8: jr          $ra
    // 0x800715DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800715DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807AF9A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF9A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AF9A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AF9AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807AF9B0: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(868, 0X2AC) << 16);
    // 0x807AF9B4: addiu       $t6, $t6, -0x764
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(868, 0X2AC));
    // 0x807AF9B8: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x807AF9BC: sb          $v0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r2;
    // 0x807AF9C0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807AF9C4: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x807AF9C8: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x807AF9CC: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x807AF9D0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807AF9D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807AF9D8: jal         0x807AF8D4
    // 0x807AF9DC: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    func_807AF8D4(rdram, ctx);
        goto after_0;
    // 0x807AF9DC: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    after_0:
    // 0x807AF9E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AF9E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AF9E8: jr          $ra
    // 0x807AF9EC: nop

    return;
    // 0x807AF9EC: nop

;}
RECOMP_FUNC void func_8004D0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D0C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004D0CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D0D0: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004D0D4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8004D0D8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004D0DC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004D0E0: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004D0E4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004D0E8: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004D0EC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8004D0F0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004D0F4: jal         0x8004CC28
    // 0x8004D0F8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8004CC28(rdram, ctx);
        goto after_0;
    // 0x8004D0F8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004D0FC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8004D100: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004D104: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8004D108: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x8004D10C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004D110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004D114: jr          $ra
    // 0x8004D118: nop

    return;
    // 0x8004D118: nop

;}
RECOMP_FUNC void func_8006F0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F0DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006F0E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F0E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006F0E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006F0EC: jal         0x80047090
    // 0x8006F0F0: addiu       $a0, $zero, 0x4070
    ctx->r4 = ADD32(0, 0X4070);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8006F0F0: addiu       $a0, $zero, 0x4070
    ctx->r4 = ADD32(0, 0X4070);
    after_0:
    // 0x8006F0F4: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8006F0F8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006F0FC: bne         $v0, $at, L_8006F10C
    if (ctx->r2 != ctx->r1) {
        // 0x8006F100: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8006F10C;
    }
    // 0x8006F100: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8006F104: b           L_8006F168
    // 0x8006F108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006F168;
    // 0x8006F108: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006F10C:
    // 0x8006F10C: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x8006F110: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8006F114: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x8006F118: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8006F11C: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x8006F120: jal         0x8004613C
    // 0x8006F124: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8006F124: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    after_1:
    // 0x8006F128: bne         $v0, $zero, L_8006F138
    if (ctx->r2 != 0) {
        // 0x8006F12C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8006F138;
    }
    // 0x8006F12C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006F130: b           L_8006F168
    // 0x8006F134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006F168;
    // 0x8006F134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006F138:
    // 0x8006F138: jal         0x80044194
    // 0x8006F13C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8006F13C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8006F140: jal         0x8006E9EC
    // 0x8006F144: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8006E9EC(rdram, ctx);
        goto after_3;
    // 0x8006F144: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8006F148: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8006F14C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F150: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006F154: swc1        $f4, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f4.u32l;
    // 0x8006F158: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8006F15C: swc1        $f6, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f6.u32l;
    // 0x8006F160: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8006F164: swc1        $f8, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->f8.u32l;
L_8006F168:
    // 0x8006F168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F16C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006F170: jr          $ra
    // 0x8006F174: nop

    return;
    // 0x8006F174: nop

;}
RECOMP_FUNC void func_80567848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80567848: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8056784C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80567850: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80567854: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80567858: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8056785C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80567860: jal         0x8004700C
    // 0x80567864: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80567864: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80567868: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8056786C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80567870: jal         0x80062AEC
    // 0x80567874: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80062AEC(rdram, ctx);
        goto after_1;
    // 0x80567874: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80567878: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8056787C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80567880: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80567884: beq         $v1, $zero, L_80567A9C
    if (ctx->r3 == 0) {
        // 0x80567888: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80567A9C;
    }
    // 0x80567888: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8056788C: lhu         $t8, 0xC($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XC);
    // 0x80567890: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80567894: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80567898: bnel        $t8, $at, L_80567AA0
    if (ctx->r24 != ctx->r1) {
        // 0x8056789C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80567AA0;
    }
    goto skip_0;
    // 0x8056789C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805678A0: beq         $v0, $a0, L_805678CC
    if (ctx->r2 == ctx->r4) {
        // 0x805678A4: lui         $at, 0x8057
        ctx->r1 = S32(RELOC_HI16(378, 0X216C) << 16);
            goto L_805678CC;
    }
    // 0x805678A4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X216C) << 16);
    // 0x805678A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805678AC: beq         $v0, $at, L_80567920
    if (ctx->r2 == ctx->r1) {
        // 0x805678B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80567920;
    }
    // 0x805678B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805678B4: beq         $v0, $at, L_80567A0C
    if (ctx->r2 == ctx->r1) {
        // 0x805678B8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80567A0C;
    }
    // 0x805678B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x805678BC: beql        $v0, $at, L_8056797C
    if (ctx->r2 == ctx->r1) {
        // 0x805678C0: lbu         $t3, 0x18($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X18);
            goto L_8056797C;
    }
    goto skip_1;
    // 0x805678C0: lbu         $t3, 0x18($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X18);
    skip_1:
    // 0x805678C4: b           L_80567AA0
    // 0x805678C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80567AA0;
    // 0x805678C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805678CC:
    // 0x805678CC: lwc1        $f4, -0x68E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X216C));
    // 0x805678D0: lwc1        $f6, 0xC4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x805678D4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805678D8: nop

    // 0x805678DC: bc1fl       L_8056790C
    if (!c1cs) {
        // 0x805678E0: lw          $v0, 0x1F4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X1F4);
            goto L_8056790C;
    }
    goto skip_2;
    // 0x805678E0: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    skip_2:
    // 0x805678E4: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x805678E8: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x805678EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805678F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805678F4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805678F8: lwc1        $f6, 0x3C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x805678FC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80567900: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80567904: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x80567908: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
L_8056790C:
    // 0x8056790C: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80567910: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x80567914: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80567918: b           L_80567A9C
    // 0x8056791C: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
        goto L_80567A9C;
    // 0x8056791C: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
L_80567920:
    // 0x80567920: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2170) << 16);
    // 0x80567924: lwc1        $f16, -0x68E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2170));
    // 0x80567928: lwc1        $f10, 0xC4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x8056792C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80567930: nop

    // 0x80567934: bc1fl       L_80567964
    if (!c1cs) {
        // 0x80567938: lw          $v0, 0x1F4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X1F4);
            goto L_80567964;
    }
    goto skip_3;
    // 0x80567938: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    skip_3:
    // 0x8056793C: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80567940: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80567944: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80567948: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8056794C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80567950: lwc1        $f16, 0x3C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80567954: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80567958: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8056795C: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x80567960: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
L_80567964:
    // 0x80567964: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x80567968: lw          $t1, 0x34($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X34);
    // 0x8056796C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80567970: b           L_80567A9C
    // 0x80567974: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
        goto L_80567A9C;
    // 0x80567974: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
    // 0x80567978: lbu         $t3, 0x18($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X18);
L_8056797C:
    // 0x8056797C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80567980: beql        $t3, $at, L_80567AA0
    if (ctx->r11 == ctx->r1) {
        // 0x80567984: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80567AA0;
    }
    goto skip_4;
    // 0x80567984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80567988: lw          $t4, 0x174($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X174);
    // 0x8056798C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80567990: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2174) << 16);
    // 0x80567994: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80567998: andi        $t6, $t5, 0xF00
    ctx->r14 = ctx->r13 & 0XF00;
    // 0x8056799C: beql        $t6, $zero, L_805679B0
    if (ctx->r14 == 0) {
        // 0x805679A0: lwc1        $f0, 0xC8($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0XC8);
            goto L_805679B0;
    }
    goto skip_5;
    // 0x805679A0: lwc1        $f0, 0xC8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC8);
    skip_5:
    // 0x805679A4: b           L_80567A9C
    // 0x805679A8: sw          $a0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r4;
        goto L_80567A9C;
    // 0x805679A8: sw          $a0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r4;
    // 0x805679AC: lwc1        $f0, 0xC8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC8);
L_805679B0:
    // 0x805679B0: lwc1        $f6, -0x68DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2174));
    // 0x805679B4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x805679B8: nop

    // 0x805679BC: bc1fl       L_805679FC
    if (!c1cs) {
        // 0x805679C0: lw          $v0, 0x1F4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X1F4);
            goto L_805679FC;
    }
    goto skip_6;
    // 0x805679C0: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    skip_6:
    // 0x805679C4: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x805679C8: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x805679CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805679D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805679D4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x805679D8: lwc1        $f6, 0x40($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X40);
    // 0x805679DC: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2178) << 16);
    // 0x805679E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805679E4: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x805679E8: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x805679EC: lwc1        $f8, -0x68D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2178));
    // 0x805679F0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x805679F4: swc1        $f10, 0xC8($v1)
    MEM_W(0XC8, ctx->r3) = ctx->f10.u32l;
    // 0x805679F8: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
L_805679FC:
    // 0x805679FC: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x80567A00: ori         $t9, $t8, 0x3000
    ctx->r25 = ctx->r24 | 0X3000;
    // 0x80567A04: b           L_80567A9C
    // 0x80567A08: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
        goto L_80567A9C;
    // 0x80567A08: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_80567A0C:
    // 0x80567A0C: lbu         $t0, 0x18($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18);
    // 0x80567A10: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80567A14: beql        $t0, $at, L_80567AA0
    if (ctx->r8 == ctx->r1) {
        // 0x80567A18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80567AA0;
    }
    goto skip_7;
    // 0x80567A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80567A1C: lw          $t1, 0x174($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X174);
    // 0x80567A20: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80567A24: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X217C) << 16);
    // 0x80567A28: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80567A2C: andi        $t3, $t2, 0xF000
    ctx->r11 = ctx->r10 & 0XF000;
    // 0x80567A30: beql        $t3, $zero, L_80567A44
    if (ctx->r11 == 0) {
        // 0x80567A34: lwc1        $f0, 0xC8($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0XC8);
            goto L_80567A44;
    }
    goto skip_8;
    // 0x80567A34: lwc1        $f0, 0xC8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC8);
    skip_8:
    // 0x80567A38: b           L_80567A9C
    // 0x80567A3C: sw          $a0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r4;
        goto L_80567A9C;
    // 0x80567A3C: sw          $a0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r4;
    // 0x80567A40: lwc1        $f0, 0xC8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC8);
L_80567A44:
    // 0x80567A44: lwc1        $f16, -0x68D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X217C));
    // 0x80567A48: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80567A4C: nop

    // 0x80567A50: bc1fl       L_80567A90
    if (!c1cs) {
        // 0x80567A54: lw          $v0, 0x1F4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X1F4);
            goto L_80567A90;
    }
    goto skip_9;
    // 0x80567A54: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    skip_9:
    // 0x80567A58: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80567A5C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80567A60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80567A64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80567A68: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80567A6C: lwc1        $f16, 0x40($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80567A70: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2180) << 16);
    // 0x80567A74: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80567A78: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80567A7C: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
    // 0x80567A80: lwc1        $f6, -0x68D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2180));
    // 0x80567A84: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80567A88: swc1        $f4, 0xC8($v1)
    MEM_W(0XC8, ctx->r3) = ctx->f4.u32l;
    // 0x80567A8C: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
L_80567A90:
    // 0x80567A90: lw          $t5, 0x34($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X34);
    // 0x80567A94: ori         $t6, $t5, 0x700
    ctx->r14 = ctx->r13 | 0X700;
    // 0x80567A98: sw          $t6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r14;
L_80567A9C:
    // 0x80567A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80567AA0:
    // 0x80567AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80567AA4: jr          $ra
    // 0x80567AA8: nop

    return;
    // 0x80567AA8: nop

;}
RECOMP_FUNC void func_800390F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800390F0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800390F4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800390F8: lh          $t6, 0xADE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XADE);
    // 0x800390FC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80039100: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80039104: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80039108: lh          $t7, 0xAE0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XAE0);
    // 0x8003910C: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80039110: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80039114: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039118: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8003911C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80039120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039124: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80039128: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003912C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80039130: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80039134: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80039138: div.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8003913C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80039140: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80039144: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80039148: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003914C: lwc1        $f10, 0x1EC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1EC);
    // 0x80039150: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80039154: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80039158: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8003915C: add.s       $f14, $f0, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80039160: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80039164: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80039168: add.s       $f12, $f2, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8003916C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x80039170: jal         0x80081E8C
    // 0x80039174: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    fatan2(rdram, ctx);
        goto after_0;
    // 0x80039174: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80039178: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003917C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039180: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80039184: lwc1        $f8, 0x158($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X158);
    // 0x80039188: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003918C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80039190: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80039194: lw          $a2, -0x7CE8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CE8);
    // 0x80039198: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003919C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800391A0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800391A4: lwc1        $f12, 0x8C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x800391A8: jal         0x80081C64
    // 0x800391AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x800391AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x800391B0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x800391B4: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x800391B8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800391BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800391C0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800391C4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800391C8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800391CC: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800391D0: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800391D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800391D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800391DC: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800391E0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x800391E4: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x800391E8: lw          $t1, 0x38($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X38);
    // 0x800391EC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800391F0: nop

    // 0x800391F4: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    // 0x800391F8: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800391FC: div.s       $f12, $f2, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80039200: div.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80039204: div.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80039208: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8003920C: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80039210: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80039214: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
    // 0x80039218: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8003921C: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    // 0x80039220: slti        $at, $a1, 0x1E
    ctx->r1 = SIGNED(ctx->r5) < 0X1E ? 1 : 0;
    // 0x80039224: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x80039228: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8003922C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80039230: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80039234: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x80039238: bc1f        L_8003926C
    if (!c1cs) {
        // 0x8003923C: addu        $a3, $t1, $t3
        ctx->r7 = ADD32(ctx->r9, ctx->r11);
            goto L_8003926C;
    }
    // 0x8003923C: addu        $a3, $t1, $t3
    ctx->r7 = ADD32(ctx->r9, ctx->r11);
    // 0x80039240: beq         $at, $zero, L_8003926C
    if (ctx->r1 == 0) {
        // 0x80039244: lui         $at, 0xC302
        ctx->r1 = S32(0XC302 << 16);
            goto L_8003926C;
    }
    // 0x80039244: lui         $at, 0xC302
    ctx->r1 = S32(0XC302 << 16);
    // 0x80039248: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003924C: lwc1        $f6, 0x30($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X30);
    // 0x80039250: lw          $t4, 0x180($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X180);
    // 0x80039254: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80039258: lwc1        $f8, 0x84($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X84);
    // 0x8003925C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80039260: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80039264: b           L_800392A4
    // 0x80039268: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
        goto L_800392A4;
    // 0x80039268: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
L_8003926C:
    // 0x8003926C: c.le.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl <= ctx->f16.fl;
    // 0x80039270: slti        $at, $a1, 0x123
    ctx->r1 = SIGNED(ctx->r5) < 0X123 ? 1 : 0;
    // 0x80039274: bc1fl       L_800392A8
    if (!c1cs) {
        // 0x80039278: c.le.s      $f18, $f14
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl <= ctx->f14.fl;
            goto L_800392A8;
    }
    goto skip_0;
    // 0x80039278: c.le.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl <= ctx->f14.fl;
    skip_0:
    // 0x8003927C: bne         $at, $zero, L_800392A4
    if (ctx->r1 != 0) {
        // 0x80039280: lui         $at, 0x4302
        ctx->r1 = S32(0X4302 << 16);
            goto L_800392A4;
    }
    // 0x80039280: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80039284: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039288: lwc1        $f10, 0x30($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X30);
    // 0x8003928C: lw          $t5, 0x180($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X180);
    // 0x80039290: div.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80039294: lwc1        $f4, 0x84($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X84);
    // 0x80039298: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8003929C: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800392A0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
L_800392A4:
    // 0x800392A4: c.le.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl <= ctx->f14.fl;
L_800392A8:
    // 0x800392A8: slti        $at, $a3, 0x14
    ctx->r1 = SIGNED(ctx->r7) < 0X14 ? 1 : 0;
    // 0x800392AC: bc1fl       L_800392E4
    if (!c1cs) {
        // 0x800392B0: c.le.s      $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
            goto L_800392E4;
    }
    goto skip_1;
    // 0x800392B0: c.le.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
    skip_1:
    // 0x800392B4: beq         $at, $zero, L_800392E0
    if (ctx->r1 == 0) {
        // 0x800392B8: lui         $at, 0xC2C8
        ctx->r1 = S32(0XC2C8 << 16);
            goto L_800392E0;
    }
    // 0x800392B8: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x800392BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800392C0: lwc1        $f8, 0x34($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X34);
    // 0x800392C4: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x800392C8: div.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800392CC: lwc1        $f6, 0x88($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X88);
    // 0x800392D0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800392D4: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800392D8: b           L_80039318
    // 0x800392DC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
        goto L_80039318;
    // 0x800392DC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
L_800392E0:
    // 0x800392E0: c.le.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
L_800392E4:
    // 0x800392E4: slti        $at, $a3, 0xDD
    ctx->r1 = SIGNED(ctx->r7) < 0XDD ? 1 : 0;
    // 0x800392E8: bc1fl       L_8003931C
    if (!c1cs) {
        // 0x800392EC: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8003931C;
    }
    goto skip_2;
    // 0x800392EC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800392F0: bne         $at, $zero, L_80039318
    if (ctx->r1 != 0) {
        // 0x800392F4: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80039318;
    }
    // 0x800392F4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800392F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800392FC: lwc1        $f4, 0x34($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X34);
    // 0x80039300: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x80039304: div.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80039308: lwc1        $f10, 0x88($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X88);
    // 0x8003930C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80039310: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80039314: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
L_80039318:
    // 0x80039318: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
L_8003931C:
    // 0x8003931C: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x80039320: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80039324: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x80039328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003932C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80039330: jr          $ra
    // 0x80039334: nop

    return;
    // 0x80039334: nop

;}
RECOMP_FUNC void func_805C7ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C7ABC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C7AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805C7AC4: lw          $v1, 0x1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C);
    // 0x805C7AC8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x805C7ACC: addiu       $t1, $v0, 0x2
    ctx->r9 = ADD32(ctx->r2, 0X2);
    // 0x805C7AD0: beq         $v1, $zero, L_805C7ADC
    if (ctx->r3 == 0) {
        // 0x805C7AD4: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_805C7ADC;
    }
    // 0x805C7AD4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x805C7AD8: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
L_805C7ADC:
    // 0x805C7ADC: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x805C7AE0: beq         $v1, $zero, L_805C7AEC
    if (ctx->r3 == 0) {
        // 0x805C7AE4: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_805C7AEC;
    }
    // 0x805C7AE4: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x805C7AE8: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
L_805C7AEC:
    // 0x805C7AEC: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x805C7AF0: bnel        $t8, $zero, L_805C7B1C
    if (ctx->r24 != 0) {
        // 0x805C7AF4: lw          $t6, 0x20($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X20);
            goto L_805C7B1C;
    }
    goto skip_0;
    // 0x805C7AF4: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    skip_0:
    // 0x805C7AF8: lw          $t3, 0x18($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18);
    // 0x805C7AFC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x805C7B00: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x805C7B04: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x805C7B08: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x805C7B0C: bne         $at, $zero, L_805C7B18
    if (ctx->r1 != 0) {
        // 0x805C7B10: sw          $t4, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r12;
            goto L_805C7B18;
    }
    // 0x805C7B10: sw          $t4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r12;
    // 0x805C7B14: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
L_805C7B18:
    // 0x805C7B18: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
L_805C7B1C:
    // 0x805C7B1C: lui         $t3, 0x805D
    ctx->r11 = S32(RELOC_HI16(447, 0X38E8) << 16);
    // 0x805C7B20: addiu       $t3, $t3, -0x6228
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(447, 0X38E8));
    // 0x805C7B24: bnel        $t6, $zero, L_805C7B50
    if (ctx->r14 != 0) {
        // 0x805C7B28: lw          $a0, 0x18($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X18);
            goto L_805C7B50;
    }
    goto skip_1;
    // 0x805C7B28: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    skip_1:
    // 0x805C7B2C: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x805C7B30: beq         $v1, $zero, L_805C7B4C
    if (ctx->r3 == 0) {
        // 0x805C7B34: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_805C7B4C;
    }
    // 0x805C7B34: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x805C7B38: beq         $at, $zero, L_805C7B4C
    if (ctx->r1 == 0) {
        // 0x805C7B3C: addiu       $t7, $zero, 0x8
        ctx->r15 = ADD32(0, 0X8);
            goto L_805C7B4C;
    }
    // 0x805C7B3C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x805C7B40: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x805C7B44: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x805C7B48: sw          $t8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r24;
L_805C7B4C:
    // 0x805C7B4C: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
L_805C7B50:
    // 0x805C7B50: lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2C);
    // 0x805C7B54: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(447, 0X38D0) << 16);
    // 0x805C7B58: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x805C7B5C: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x805C7B60: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x805C7B64: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x805C7B68: addiu       $t5, $t4, 0x2
    ctx->r13 = ADD32(ctx->r12, 0X2);
    // 0x805C7B6C: addiu       $t6, $t6, -0x6240
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(447, 0X38D0));
    // 0x805C7B70: addu        $t2, $t5, $t6
    ctx->r10 = ADD32(ctx->r13, ctx->r14);
    // 0x805C7B74: addu        $t0, $t9, $t3
    ctx->r8 = ADD32(ctx->r25, ctx->r11);
    // 0x805C7B78: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_805C7B7C:
    // 0x805C7B7C: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x805C7B80: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x805C7B84: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x805C7B88: sh          $t7, 0x164($a3)
    MEM_H(0X164, ctx->r7) = ctx->r15;
    // 0x805C7B8C: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x805C7B90: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x805C7B94: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x805C7B98: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x805C7B9C: bne         $a1, $v0, L_805C7B7C
    if (ctx->r5 != ctx->r2) {
        // 0x805C7BA0: sh          $t8, 0x164($t1)
        MEM_H(0X164, ctx->r9) = ctx->r24;
            goto L_805C7B7C;
    }
    // 0x805C7BA0: sh          $t8, 0x164($t1)
    MEM_H(0X164, ctx->r9) = ctx->r24;
    // 0x805C7BA4: jr          $ra
    // 0x805C7BA8: nop

    return;
    // 0x805C7BA8: nop

;}
RECOMP_FUNC void func_806CE084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CE084: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C60) << 16);
    // 0x806CE088: lwc1        $f2, -0xC80($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C60));
    // 0x806CE08C: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C64) << 16);
    // 0x806CE090: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x806CE094: lwc1        $f4, -0xC7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C64));
    // 0x806CE098: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x806CE09C: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x806CE0A0: mul.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x806CE0A4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x806CE0A8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806CE0AC: nop

    // 0x806CE0B0: bc1fl       L_806CE0C0
    if (!c1cs) {
        // 0x806CE0B4: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_806CE0C0;
    }
    goto skip_0;
    // 0x806CE0B4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    skip_0:
    // 0x806CE0B8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x806CE0BC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
L_806CE0C0:
    // 0x806CE0C0: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C68) << 16);
    // 0x806CE0C4: lwc1        $f10, -0xC78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C68));
    // 0x806CE0C8: swc1        $f0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f0.u32l;
    // 0x806CE0CC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806CE0D0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806CE0D4: bc1f        L_806CE0E0
    if (!c1cs) {
        // 0x806CE0D8: swc1        $f16, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
            goto L_806CE0E0;
    }
    // 0x806CE0D8: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
    // 0x806CE0DC: swc1        $f2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f2.u32l;
L_806CE0E0:
    // 0x806CE0E0: lwc1        $f18, 0x0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X0);
    // 0x806CE0E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CE0E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806CE0EC: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x806CE0F0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x806CE0F4: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x806CE0F8: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x806CE0FC: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x806CE100: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x806CE104: nop

    // 0x806CE108: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x806CE10C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x806CE110: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x806CE114: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x806CE118: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x806CE11C: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x806CE120: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x806CE124: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806CE128: nop

    // 0x806CE12C: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x806CE130: jr          $ra
    // 0x806CE134: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x806CE134: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8067F7B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067F7B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067F7BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067F7C0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067F7C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8067F7C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8067F7CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8067F7D0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8067F7D4: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(547, 0X10F4) << 16);
    // 0x8067F7D8: beq         $v0, $zero, L_8067F7E8
    if (ctx->r2 == 0) {
        // 0x8067F7DC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8067F7E8;
    }
    // 0x8067F7DC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8067F7E0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8067F7E4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8067F7E8:
    // 0x8067F7E8: bne         $v0, $zero, L_8067F820
    if (ctx->r2 != 0) {
        // 0x8067F7EC: nop
    
            goto L_8067F820;
    }
    // 0x8067F7EC: nop

    // 0x8067F7F0: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8067F7F4: lui         $t0, 0x8068
    ctx->r8 = S32(RELOC_HI16(547, 0X1040) << 16);
    // 0x8067F7F8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8067F7FC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8067F800: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8067F804: lw          $t0, 0x230($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(547, 0X1040));
    // 0x8067F808: sh          $t0, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r8;
    // 0x8067F80C: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8067F810: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8067F814: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8067F818: andi        $t4, $t2, 0x3
    ctx->r12 = ctx->r10 & 0X3;
    // 0x8067F81C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
L_8067F820:
    // 0x8067F820: lwc1        $f12, 0x2E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(547, 0X10F4));
    // 0x8067F824: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8067F828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067F82C: add.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8067F830: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8067F834: nop

    // 0x8067F838: bc1fl       L_8067F848
    if (!c1cs) {
        // 0x8067F83C: lwc1        $f6, 0x70($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
            goto L_8067F848;
    }
    goto skip_0;
    // 0x8067F83C: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    skip_0:
    // 0x8067F840: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8067F844: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
L_8067F848:
    // 0x8067F848: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x8067F84C: add.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8067F850: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8067F854: nop

    // 0x8067F858: bc1fl       L_8067F868
    if (!c1cs) {
        // 0x8067F85C: swc1        $f0, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
            goto L_8067F868;
    }
    goto skip_1;
    // 0x8067F85C: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x8067F860: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8067F864: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
L_8067F868:
    // 0x8067F868: lbu         $v0, 0x1C($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1C);
    // 0x8067F86C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8067F870: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x8067F874: bnel        $at, $zero, L_8067F884
    if (ctx->r1 != 0) {
        // 0x8067F878: sb          $v0, 0x1C($v1)
        MEM_B(0X1C, ctx->r3) = ctx->r2;
            goto L_8067F884;
    }
    goto skip_2;
    // 0x8067F878: sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
    skip_2:
    // 0x8067F87C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8067F880: sb          $v0, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r2;
L_8067F884:
    // 0x8067F884: sb          $v0, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r2;
    // 0x8067F888: sb          $v0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r2;
    // 0x8067F88C: lbu         $v0, 0x20($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X20);
    // 0x8067F890: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x8067F894: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x8067F898: bnel        $at, $zero, L_8067F8A8
    if (ctx->r1 != 0) {
        // 0x8067F89C: lbu         $t5, 0x1E($v1)
        ctx->r13 = MEM_BU(ctx->r3, 0X1E);
            goto L_8067F8A8;
    }
    goto skip_3;
    // 0x8067F89C: lbu         $t5, 0x1E($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1E);
    skip_3:
    // 0x8067F8A0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8067F8A4: lbu         $t5, 0x1E($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1E);
L_8067F8A8:
    // 0x8067F8A8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8067F8AC: sb          $v0, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r2;
    // 0x8067F8B0: sb          $v0, 0x21($v1)
    MEM_B(0X21, ctx->r3) = ctx->r2;
    // 0x8067F8B4: bne         $t5, $at, L_8067F8E0
    if (ctx->r13 != ctx->r1) {
        // 0x8067F8B8: sb          $v0, 0x22($v1)
        MEM_B(0X22, ctx->r3) = ctx->r2;
            goto L_8067F8E0;
    }
    // 0x8067F8B8: sb          $v0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r2;
    // 0x8067F8BC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8067F8C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067F8C4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8067F8C8: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(547, 0X10F8) << 16);
    // 0x8067F8CC: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8067F8D0: lwc1        $f10, 0x2E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(547, 0X10F8));
    // 0x8067F8D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8067F8D8: jal         0x80680194
    // 0x8067F8DC: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    func_80680194(rdram, ctx);
        goto after_0;
    // 0x8067F8DC: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    after_0:
L_8067F8E0:
    // 0x8067F8E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067F8E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067F8E8: jr          $ra
    // 0x8067F8EC: nop

    return;
    // 0x8067F8EC: nop

;}
RECOMP_FUNC void func_806D89B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D89B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D89BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D89C0: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x806D89C4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x806D89C8: lw          $a2, 0x2C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X2C);
    // 0x806D89CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806D89D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806D89D4: jal         0x80049D74
    // 0x806D89D8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x806D89D8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x806D89DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806D89E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806D89E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D89E8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x806D89EC: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x806D89F0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x806D89F4: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x806D89F8: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x806D89FC: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x806D8A00: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x806D8A04: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x806D8A08: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x806D8A0C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x806D8A10: beql        $v1, $zero, L_806D8A58
    if (ctx->r3 == 0) {
        // 0x806D8A14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D8A58;
    }
    goto skip_0;
    // 0x806D8A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806D8A18: beql        $v1, $at, L_806D8A58
    if (ctx->r3 == ctx->r1) {
        // 0x806D8A1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D8A58;
    }
    goto skip_1;
    // 0x806D8A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806D8A20: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x806D8A24: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x806D8A28: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x806D8A2C: beq         $v1, $at, L_806D8A54
    if (ctx->r3 == ctx->r1) {
        // 0x806D8A30: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_806D8A54;
    }
    // 0x806D8A30: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x806D8A34: beq         $v1, $at, L_806D8A54
    if (ctx->r3 == ctx->r1) {
        // 0x806D8A38: sll         $t0, $a2, 2
        ctx->r8 = S32(ctx->r6 << 2);
            goto L_806D8A54;
    }
    // 0x806D8A38: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x806D8A3C: lui         $t9, 0x806E
    ctx->r25 = S32(RELOC_HI16(625, 0X540) << 16);
    // 0x806D8A40: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x806D8A44: lw          $t9, -0x7200($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(625, 0X540));
    // 0x806D8A48: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x806D8A4C: jalr        $t9
    // 0x806D8A50: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x806D8A50: nop

    after_1:
L_806D8A54:
    // 0x806D8A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D8A58:
    // 0x806D8A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D8A5C: jr          $ra
    // 0x806D8A60: nop

    return;
    // 0x806D8A60: nop

;}
RECOMP_FUNC void func_804616CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804616CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804616D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804616D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804616D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804616DC: jal         0x8004700C
    // 0x804616E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804616E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x804616E4: beq         $v0, $zero, L_80461764
    if (ctx->r2 == 0) {
        // 0x804616E8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80461764;
    }
    // 0x804616E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x804616EC: jal         0x804610B4
    // 0x804616F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804610B4(rdram, ctx);
        goto after_1;
    // 0x804616F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804616F4: jal         0x804613B8
    // 0x804616F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804613B8(rdram, ctx);
        goto after_2;
    // 0x804616F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804616FC: jal         0x80461490
    // 0x80461700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80461490(rdram, ctx);
        goto after_3;
    // 0x80461700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80461704: jal         0x804615A8
    // 0x80461708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804615A8(rdram, ctx);
        goto after_4;
    // 0x80461708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8046170C: jal         0x80460EF0
    // 0x80461710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80460EF0(rdram, ctx);
        goto after_5;
    // 0x80461710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80461714: lw          $t6, 0x180($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X180);
    // 0x80461718: beq         $s0, $t6, L_8046175C
    if (ctx->r16 == ctx->r14) {
        // 0x8046171C: nop
    
            goto L_8046175C;
    }
    // 0x8046171C: nop

    // 0x80461720: lwc1        $f4, 0xC4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x80461724: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80461728: lwc1        $f10, 0xC8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8046172C: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    // 0x80461730: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80461734: swc1        $f8, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f8.u32l;
    // 0x80461738: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8046173C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80461740: jal         0x80461430
    // 0x80461744: swc1        $f18, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f18.u32l;
    func_80461430(rdram, ctx);
        goto after_6;
    // 0x80461744: swc1        $f18, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f18.u32l;
    after_6:
    // 0x80461748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046174C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80461750: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80461754: jal         0x80461ACC
    // 0x80461758: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80461ACC(rdram, ctx);
        goto after_7;
    // 0x80461758: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_8046175C:
    // 0x8046175C: jal         0x80460F94
    // 0x80461760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80460F94(rdram, ctx);
        goto after_8;
    // 0x80461760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80461764:
    // 0x80461764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80461768: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8046176C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80461770: jr          $ra
    // 0x80461774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80461774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804C3618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3618: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804C361C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C3620: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804C3624: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804C3628: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804C362C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804C3630: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804C3634: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C3638: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804C363C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804C3640: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(206, 0X13F4) << 16);
    // 0x804C3644: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804C3648: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C364C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804C3650: lw          $t1, 0x3E74($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(206, 0X13F4));
    // 0x804C3654: jr          $ra
    // 0x804C3658: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804C3658: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8064AC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AC90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064AC94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064AC98: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8064AC9C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8064ACA0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064ACA4: lui         $t8, 0x8065
    ctx->r24 = S32(RELOC_HI16(495, 0X2EA4) << 16);
    // 0x8064ACA8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8064ACAC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8064ACB0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8064ACB4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064ACB8: lw          $t8, -0x308C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(495, 0X2EA4));
    // 0x8064ACBC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8064ACC0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8064ACC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064ACC8: jal         0x80048490
    // 0x8064ACCC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8064ACCC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8064ACD0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8064ACD4: jal         0x80048378
    // 0x8064ACD8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8064ACD8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8064ACDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064ACE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064ACE4: jr          $ra
    // 0x8064ACE8: nop

    return;
    // 0x8064ACE8: nop

;}
RECOMP_FUNC void func_8004F3D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F3D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004F3DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004F3E0: jal         0x80064DD0
    // 0x8004F3E4: addiu       $a0, $zero, 0x1C4
    ctx->r4 = ADD32(0, 0X1C4);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x8004F3E4: addiu       $a0, $zero, 0x1C4
    ctx->r4 = ADD32(0, 0X1C4);
    after_0:
    // 0x8004F3E8: bne         $v0, $zero, L_8004F408
    if (ctx->r2 != 0) {
        // 0x8004F3EC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8004F408;
    }
    // 0x8004F3EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8004F3F0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004F3F4: addiu       $a0, $a0, 0x948
    ctx->r4 = ADD32(ctx->r4, 0X948);
    // 0x8004F3F8: jal         0x80071380
    // 0x8004F3FC: addiu       $a1, $zero, 0x19E
    ctx->r5 = ADD32(0, 0X19E);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8004F3FC: addiu       $a1, $zero, 0x19E
    ctx->r5 = ADD32(0, 0X19E);
    after_1:
    // 0x8004F400: b           L_8004F41C
    // 0x8004F404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004F41C;
    // 0x8004F404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004F408:
    // 0x8004F408: addiu       $a1, $zero, 0x1C4
    ctx->r5 = ADD32(0, 0X1C4);
    // 0x8004F40C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004F410: jal         0x80065728
    // 0x8004F414: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8004F414: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8004F418: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8004F41C:
    // 0x8004F41C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004F420: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004F424: jr          $ra
    // 0x8004F428: nop

    return;
    // 0x8004F428: nop

;}
RECOMP_FUNC void func_80430D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430D9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430DA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430DA4: jal         0x80430BE8
    // 0x80430DA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80430BE8(rdram, ctx);
        goto after_0;
    // 0x80430DA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80430DAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80430DB0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80430DB4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430DB8: lh          $v1, 0x1C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1C);
    // 0x80430DBC: bne         $v1, $zero, L_80430DE8
    if (ctx->r3 != 0) {
        // 0x80430DC0: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80430DE8;
    }
    // 0x80430DC0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80430DC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80430DC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80430DCC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80430DD0: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80430DD4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430DD8: jal         0x804311BC
    // 0x80430DDC: lw          $a3, 0x20($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X20);
    func_804311BC(rdram, ctx);
        goto after_1;
    // 0x80430DDC: lw          $a3, 0x20($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X20);
    after_1:
    // 0x80430DE0: b           L_80430DF0
    // 0x80430DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80430DF0;
    // 0x80430DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80430DE8:
    // 0x80430DE8: sh          $t7, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r15;
    // 0x80430DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80430DF0:
    // 0x80430DF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80430DF4: jr          $ra
    // 0x80430DF8: nop

    return;
    // 0x80430DF8: nop

;}
RECOMP_FUNC void func_8003E478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003E484: jal         0x8001D770
    // 0x8003E488: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x8003E488: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003E48C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8003E490: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003E494: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x8003E498: jal         0x80067BF8
    // 0x8003E49C: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x8003E49C: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_1:
    // 0x8003E4A0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x8003E4A4: jal         0x80067818
    // 0x8003E4A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8003E4A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8003E4AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E4B0: jal         0x8003E3D4
    // 0x8003E4B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8003E3D4(rdram, ctx);
        goto after_3;
    // 0x8003E4B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8003E4B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E4BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E4C0: jr          $ra
    // 0x8003E4C4: nop

    return;
    // 0x8003E4C4: nop

;}
RECOMP_FUNC void func_804425BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804425BC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804425C0: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x804425C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804425C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804425CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804425D0: lbu         $v0, 0xF0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XF0);
    // 0x804425D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804425D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804425DC: beql        $v0, $zero, L_80442600
    if (ctx->r2 == 0) {
        // 0x804425E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80442600;
    }
    goto skip_0;
    // 0x804425E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804425E4: jal         0x8044284C
    // 0x804425E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8044284C(rdram, ctx);
        goto after_0;
    // 0x804425E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804425EC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x804425F0: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x804425F4: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x804425F8: sw          $t7, 0x130($t8)
    MEM_W(0X130, ctx->r24) = ctx->r15;
    // 0x804425FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80442600:
    // 0x80442600: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80442604: jr          $ra
    // 0x80442608: nop

    return;
    // 0x80442608: nop

;}
RECOMP_FUNC void func_80460730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046073C: jal         0x804606DC
    // 0x80460740: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_804606DC(rdram, ctx);
        goto after_0;
    // 0x80460740: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_0:
    // 0x80460744: jal         0x80045BD8
    // 0x80460748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80460748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8046074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460754: jr          $ra
    // 0x80460758: nop

    return;
    // 0x80460758: nop

;}
RECOMP_FUNC void func_8078EBE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078EBE8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8078EBEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078EBF0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8078EBF4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8078EBF8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8078EBFC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8078EC00: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8078EC04: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8078EC08: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(811, 0X600) << 16);
    // 0x8078EC0C: lwc1        $f10, -0xF00($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(811, 0X600));
    // 0x8078EC10: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8078EC14: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8078EC18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8078EC1C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8078EC20: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8078EC24: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8078EC28: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8078EC2C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8078EC30: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8078EC34: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8078EC38: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8078EC3C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8078EC40: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8078EC44: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8078EC48: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8078EC4C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8078EC50: jalr        $t9
    // 0x8078EC54: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8078EC54: nop

    after_0:
    // 0x8078EC58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078EC5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8078EC60: jr          $ra
    // 0x8078EC64: nop

    return;
    // 0x8078EC64: nop

;}
RECOMP_FUNC void func_80426610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426610: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80426614: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80426618: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042661C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80426620: jal         0x80051194
    // 0x80426624: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x80426624: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x80426628: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x8042662C: jal         0x80426F20
    // 0x80426630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80426F20(rdram, ctx);
        goto after_1;
    // 0x80426630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80426634: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x80426638: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(38, 0X5B4) << 16);
    // 0x8042663C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x80426640: addiu       $t6, $t6, 0x6BB4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(38, 0X5B4));
    // 0x80426644: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x80426648: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(38, 0X11C8) << 16);
    // 0x8042664C: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x80426650: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x80426654: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80426658: addiu       $t8, $t8, 0x77C8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(38, 0X11C8));
    // 0x8042665C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80426660: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80426664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80426668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042666C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80426670: jal         0x80427118
    // 0x80426674: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80427118(rdram, ctx);
        goto after_2;
    // 0x80426674: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80426678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042667C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80426680: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80426684: jr          $ra
    // 0x80426688: nop

    return;
    // 0x80426688: nop

;}
RECOMP_FUNC void func_806ECA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ECA98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806ECA9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806ECAA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806ECAA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806ECAA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806ECAAC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806ECAB0: jal         0x800577D8
    // 0x806ECAB4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806ECAB4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x806ECAB8: jal         0x806EC444
    // 0x806ECABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC444(rdram, ctx);
        goto after_1;
    // 0x806ECABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806ECAC0: jal         0x806EC4B0
    // 0x806ECAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC4B0(rdram, ctx);
        goto after_2;
    // 0x806ECAC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806ECAC8: jal         0x806EC584
    // 0x806ECACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC584(rdram, ctx);
        goto after_3;
    // 0x806ECACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806ECAD0: bne         $v0, $zero, L_806ECAF0
    if (ctx->r2 != 0) {
        // 0x806ECAD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806ECAF0;
    }
    // 0x806ECAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECAD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECADC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806ECAE0: jal         0x806ED360
    // 0x806ECAE4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_4;
    // 0x806ECAE4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806ECAE8: b           L_806ECB54
    // 0x806ECAEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806ECB54;
    // 0x806ECAEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ECAF0:
    // 0x806ECAF0: jal         0x806EC5D4
    // 0x806ECAF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC5D4(rdram, ctx);
        goto after_5;
    // 0x806ECAF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806ECAF8: beq         $v0, $zero, L_806ECB18
    if (ctx->r2 == 0) {
        // 0x806ECAFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806ECB18;
    }
    // 0x806ECAFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECB00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECB04: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806ECB08: jal         0x806ED360
    // 0x806ECB0C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_6;
    // 0x806ECB0C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806ECB10: b           L_806ECB54
    // 0x806ECB14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806ECB54;
    // 0x806ECB14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ECB18:
    // 0x806ECB18: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806ECB1C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806ECB20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ECB24: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x806ECB28: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x806ECB2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ECB30: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806ECB34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806ECB38: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806ECB3C: nop

    // 0x806ECB40: bc1fl       L_806ECB54
    if (!c1cs) {
        // 0x806ECB44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806ECB54;
    }
    goto skip_0;
    // 0x806ECB44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806ECB48: jal         0x806ED360
    // 0x806ECB4C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_7;
    // 0x806ECB4C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x806ECB50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ECB54:
    // 0x806ECB54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806ECB58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806ECB5C: jr          $ra
    // 0x806ECB60: nop

    return;
    // 0x806ECB60: nop

;}
RECOMP_FUNC void func_80024908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024908: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8002490C: addiu       $t6, $t6, 0x48FC
    ctx->r14 = ADD32(ctx->r14, 0X48FC);
    // 0x80024910: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80024914: jr          $ra
    // 0x80024918: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80024918: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80736C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736C78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80736C7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80736C80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80736C84: jal         0x80736C08
    // 0x80736C88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80736C08(rdram, ctx);
        goto after_0;
    // 0x80736C88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80736C8C: bne         $v0, $zero, L_80736CA4
    if (ctx->r2 != 0) {
        // 0x80736C90: nop
    
            goto L_80736CA4;
    }
    // 0x80736C90: nop

    // 0x80736C94: jal         0x800447C8
    // 0x80736C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80736C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80736C9C: b           L_80736D08
    // 0x80736CA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80736D08;
    // 0x80736CA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80736CA4:
    // 0x80736CA4: jal         0x80736A94
    // 0x80736CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80736A94(rdram, ctx);
        goto after_2;
    // 0x80736CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80736CAC: bne         $v0, $zero, L_80736CC4
    if (ctx->r2 != 0) {
        // 0x80736CB0: nop
    
            goto L_80736CC4;
    }
    // 0x80736CB0: nop

    // 0x80736CB4: jal         0x800447C8
    // 0x80736CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x80736CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80736CBC: b           L_80736D08
    // 0x80736CC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80736D08;
    // 0x80736CC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80736CC4:
    // 0x80736CC4: jal         0x80736C4C
    // 0x80736CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80736C4C(rdram, ctx);
        goto after_4;
    // 0x80736CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80736CCC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80736CD0: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80736CD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80736CD8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80736CDC: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80736CE0: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
    // 0x80736CE4: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x80736CE8: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80736CEC: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x80736CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80736CF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80736CF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80736CFC: jal         0x80736D18
    // 0x80736D00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80736D18(rdram, ctx);
        goto after_5;
    // 0x80736D00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80736D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80736D08:
    // 0x80736D08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80736D0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80736D10: jr          $ra
    // 0x80736D14: nop

    return;
    // 0x80736D14: nop

;}
RECOMP_FUNC void func_807106C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807106C8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x807106CC: lui         $t7, 0x8071
    ctx->r15 = S32(RELOC_HI16(724, 0X18C0) << 16);
    // 0x807106D0: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x807106D4: lbu         $t7, 0xCB0($t7)
    ctx->r15 = MEM_BU(ctx->r15, (int16_t)RELOC_LO16(724, 0X18C0));
    // 0x807106D8: lw          $v0, 0x16C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X16C);
    // 0x807106DC: jr          $ra
    // 0x807106E0: sb          $t7, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r15;
    return;
    // 0x807106E0: sb          $t7, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_80060CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060CF0: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x80060CF4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80060CF8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80060CFC: sll         $s4, $a1, 16
    ctx->r20 = S32(ctx->r5 << 16);
    // 0x80060D00: lui         $s6, 0x800F
    ctx->r22 = S32(0X800F << 16);
    // 0x80060D04: addiu       $s6, $s6, 0x7EA0
    ctx->r22 = ADD32(ctx->r22, 0X7EA0);
    // 0x80060D08: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80060D0C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80060D10: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80060D14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060D18: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80060D1C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80060D20: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80060D24: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80060D28: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80060D2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80060D30: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x80060D34: lw          $s5, 0x9F8($s6)
    ctx->r21 = MEM_W(ctx->r22, 0X9F8);
    // 0x80060D38: beq         $s4, $zero, L_80060EA0
    if (ctx->r20 == 0) {
        // 0x80060D3C: addiu       $s3, $zero, 0x96
        ctx->r19 = ADD32(0, 0X96);
            goto L_80060EA0;
    }
    // 0x80060D3C: addiu       $s3, $zero, 0x96
    ctx->r19 = ADD32(0, 0X96);
    // 0x80060D40: addiu       $fp, $zero, 0x14
    ctx->r30 = ADD32(0, 0X14);
    // 0x80060D44: addiu       $s7, $sp, 0x50
    ctx->r23 = ADD32(ctx->r29, 0X50);
    // 0x80060D48: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80060D4C:
    // 0x80060D4C: beql        $v0, $zero, L_80060E88
    if (ctx->r2 == 0) {
        // 0x80060D50: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_80060E88;
    }
    goto skip_0;
    // 0x80060D50: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    skip_0:
    // 0x80060D54: lw          $s1, 0x174($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X174);
    // 0x80060D58: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80060D5C: bne         $v1, $zero, L_80060E74
    if (ctx->r3 != 0) {
        // 0x80060D60: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_80060E74;
    }
    // 0x80060D60: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80060D64: lbu         $t6, 0x5($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X5);
    // 0x80060D68: beql        $t6, $zero, L_80060D80
    if (ctx->r14 == 0) {
        // 0x80060D6C: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_80060D80;
    }
    goto skip_1;
    // 0x80060D6C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    skip_1:
    // 0x80060D70: lbu         $t7, 0x10($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X10);
    // 0x80060D74: beql        $t7, $zero, L_80060E7C
    if (ctx->r15 == 0) {
        // 0x80060D78: addiu       $s4, $s4, -0x1
        ctx->r20 = ADD32(ctx->r20, -0X1);
            goto L_80060E7C;
    }
    goto skip_2;
    // 0x80060D78: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    skip_2:
    // 0x80060D7C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_80060D80:
    // 0x80060D80: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x80060D84: sw          $fp, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r30;
    // 0x80060D88: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80060D8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80060D90: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x80060D94: lw          $t8, 0x70($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X70);
    // 0x80060D98: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80060D9C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80060DA0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060DA4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80060DA8: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x80060DAC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80060DB0: lh          $t1, 0xC($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XC);
    // 0x80060DB4: lw          $t0, 0x70($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X70);
    // 0x80060DB8: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80060DBC: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80060DC0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80060DC4: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80060DC8: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x80060DCC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80060DD0: lh          $t3, 0xE($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XE);
    // 0x80060DD4: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    // 0x80060DD8: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80060DDC: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80060DE0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80060DE4: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80060DE8: swc1        $f16, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f16.u32l;
    // 0x80060DEC: jal         0x8005FEBC
    // 0x80060DF0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_8005FEBC(rdram, ctx);
        goto after_0;
    // 0x80060DF0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x80060DF4: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80060DF8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80060DFC: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80060E00: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80060E04: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80060E08: lw          $t4, 0x70($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X70);
    // 0x80060E0C: lwc1        $f18, 0x88($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X88);
    // 0x80060E10: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80060E14: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80060E18: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80060E1C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060E20: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80060E24: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80060E28: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    // 0x80060E2C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80060E30: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80060E34: lh          $t8, 0x8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8);
    // 0x80060E38: lw          $t7, 0x70($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X70);
    // 0x80060E3C: lwc1        $f18, 0x8C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8C);
    // 0x80060E40: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80060E44: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80060E48: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060E4C: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80060E50: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80060E54: jal         0x80060A90
    // 0x80060E58: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    func_80060A90(rdram, ctx);
        goto after_1;
    // 0x80060E58: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80060E5C: beq         $v0, $zero, L_80060E78
    if (ctx->r2 == 0) {
        // 0x80060E60: lw          $t0, 0xC0($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XC0);
            goto L_80060E78;
    }
    // 0x80060E60: lw          $t0, 0xC0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC0);
    // 0x80060E64: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80060E68: subu        $t1, $fp, $t0
    ctx->r9 = SUB32(ctx->r30, ctx->r8);
    // 0x80060E6C: b           L_80060E78
    // 0x80060E70: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_80060E78;
    // 0x80060E70: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_80060E74:
    // 0x80060E74: sw          $t3, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r11;
L_80060E78:
    // 0x80060E78: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
L_80060E7C:
    // 0x80060E7C: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80060E80: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80060E84: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_80060E88:
    // 0x80060E88: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x80060E8C: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80060E90: beq         $s4, $zero, L_80060EA0
    if (ctx->r20 == 0) {
        // 0x80060E94: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80060EA0;
    }
    // 0x80060E94: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80060E98: bnel        $s3, $zero, L_80060D4C
    if (ctx->r19 != 0) {
        // 0x80060E9C: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80060D4C;
    }
    goto skip_3;
    // 0x80060E9C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_3:
L_80060EA0:
    // 0x80060EA0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80060EA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060EA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80060EAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80060EB0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80060EB4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80060EB8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80060EBC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80060EC0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80060EC4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80060EC8: jr          $ra
    // 0x80060ECC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x80060ECC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_80574178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574178: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8057417C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80574180: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80574184: addiu       $at, $zero, 0x468C
    ctx->r1 = ADD32(0, 0X468C);
    // 0x80574188: swc1        $f4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f4.u32l;
    // 0x8057418C: lhu         $t7, 0xC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XC);
    // 0x80574190: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80574194: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80574198: bne         $t7, $at, L_805741AC
    if (ctx->r15 != ctx->r1) {
        // 0x8057419C: addiu       $t9, $zero, 0x7
        ctx->r25 = ADD32(0, 0X7);
            goto L_805741AC;
    }
    // 0x8057419C: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x805741A0: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    // 0x805741A4: jr          $ra
    // 0x805741A8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x805741A8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_805741AC:
    // 0x805741AC: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x805741B0: jr          $ra
    // 0x805741B4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x805741B4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
;}
RECOMP_FUNC void func_8073C6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073C6C8: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8073C6CC: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(742, 0X474) << 16);
    // 0x8073C6D0: addiu       $v0, $v0, -0x3A2C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(742, 0X474));
    // 0x8073C6D4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8073C6D8: sw          $v0, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r2;
    // 0x8073C6DC: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x8073C6E0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8073C6E4: jr          $ra
    // 0x8073C6E8: sw          $v0, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r2;
    return;
    // 0x8073C6E8: sw          $v0, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r2;
;}
RECOMP_FUNC void func_805AB914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB914: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805AB918: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x805AB91C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805AB920: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x805AB924: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x805AB928: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x805AB92C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805AB930: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x805AB934: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x805AB938: lui         $t9, 0x805B
    ctx->r25 = S32(RELOC_HI16(435, 0XAD4) << 16);
    // 0x805AB93C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805AB940: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805AB944: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805AB948: lw          $t9, -0x45EC($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(435, 0XAD4));
    // 0x805AB94C: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XB24) << 16);
    // 0x805AB950: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x805AB954: lwc1        $f4, -0x459C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB24));
    // 0x805AB958: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x805AB95C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805AB960: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x805AB964: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x805AB968: jr          $ra
    // 0x805AB96C: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x805AB96C: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_805DA920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA920: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DA924: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x805DA928: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805DA92C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x805DA930: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805DA934: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x805DA938: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x805DA93C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x805DA940: jr          $ra
    // 0x805DA944: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x805DA944: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_805AB970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB970: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AB974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AB978: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805AB97C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805AB980: jal         0x80047090
    // 0x805AB984: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805AB984: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    after_0:
    // 0x805AB988: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805AB98C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x805AB990: beq         $v0, $at, L_805AB9D0
    if (ctx->r2 == ctx->r1) {
        // 0x805AB994: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805AB9D0;
    }
    // 0x805AB994: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805AB998: lhu         $t6, 0x22($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X22);
    // 0x805AB99C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x805AB9A0: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x805AB9A4: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x805AB9A8: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x805AB9AC: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    // 0x805AB9B0: jal         0x8004613C
    // 0x805AB9B4: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805AB9B4: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    after_1:
    // 0x805AB9B8: beq         $v0, $zero, L_805AB9D0
    if (ctx->r2 == 0) {
        // 0x805AB9BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805AB9D0;
    }
    // 0x805AB9BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805AB9C0: jal         0x80044194
    // 0x805AB9C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805AB9C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x805AB9C8: b           L_805AB9D4
    // 0x805AB9CC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_805AB9D4;
    // 0x805AB9CC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_805AB9D0:
    // 0x805AB9D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805AB9D4:
    // 0x805AB9D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AB9D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805AB9DC: jr          $ra
    // 0x805AB9E0: nop

    return;
    // 0x805AB9E0: nop

    // 0x805AB9E4: nop

    // 0x805AB9E8: nop

    // 0x805AB9EC: nop

;}
RECOMP_FUNC void func_80680738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8068073C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680740: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80680744: jal         0x80062684
    // 0x80680748: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x80680748: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x8068074C: jal         0x80680540
    // 0x80680750: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80680540(rdram, ctx);
        goto after_1;
    // 0x80680750: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80680754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80680758: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2238) << 16);
    // 0x8068075C: lwc1        $f6, 0x2648($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2238));
    // 0x80680760: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80680764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80680768: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8068076C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80680770: nop

    // 0x80680774: bc1fl       L_80680788
    if (!c1cs) {
        // 0x80680778: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80680788;
    }
    goto skip_0;
    // 0x80680778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8068077C: jal         0x80680D04
    // 0x80680780: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80680D04(rdram, ctx);
        goto after_2;
    // 0x80680780: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80680784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80680788:
    // 0x80680788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8068078C: jr          $ra
    // 0x80680790: nop

    return;
    // 0x80680790: nop

;}
RECOMP_FUNC void func_8040AC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040AC54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040AC58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040AC5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8040AC60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8040AC64: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8040AC68: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8040AC6C: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x8040AC70: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8040AC74: nop

    // 0x8040AC78: bc1fl       L_8040ACA4
    if (!c1cs) {
        // 0x8040AC7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040ACA4;
    }
    goto skip_0;
    // 0x8040AC7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040AC80: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8040AC84: jal         0x8004D1F0
    // 0x8040AC88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x8040AC88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040AC8C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8040AC90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040AC94: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x8040AC98: jal         0x8004D698
    // 0x8040AC9C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x8040AC9C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8040ACA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040ACA4:
    // 0x8040ACA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040ACA8: jr          $ra
    // 0x8040ACAC: nop

    return;
    // 0x8040ACAC: nop

;}
RECOMP_FUNC void func_80463A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463A1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80463A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80463A24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80463A28: jal         0x80045A34
    // 0x80463A2C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80463A2C: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_0:
    // 0x80463A30: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80463A34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80463A38: bne         $v0, $zero, L_80463A48
    if (ctx->r2 != 0) {
        // 0x80463A3C: sw          $v0, 0x1F4($t6)
        MEM_W(0X1F4, ctx->r14) = ctx->r2;
            goto L_80463A48;
    }
    // 0x80463A3C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x80463A40: b           L_80463A54
    // 0x80463A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80463A54;
    // 0x80463A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80463A48:
    // 0x80463A48: jal         0x80463898
    // 0x80463A4C: nop

    func_80463898(rdram, ctx);
        goto after_1;
    // 0x80463A4C: nop

    after_1:
    // 0x80463A50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80463A54:
    // 0x80463A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80463A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80463A5C: jr          $ra
    // 0x80463A60: nop

    return;
    // 0x80463A60: nop

;}
RECOMP_FUNC void func_80043A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80043A8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80043A90: lhu         $t6, 0x1C($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1C);
    // 0x80043A94: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80043A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043A9C: bne         $t6, $at, L_80043AD4
    if (ctx->r14 != ctx->r1) {
        // 0x80043AA0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80043AD4;
    }
    // 0x80043AA0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80043AA4: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x80043AA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043AAC: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80043AB0: bne         $t8, $at, L_80043ACC
    if (ctx->r24 != ctx->r1) {
        // 0x80043AB4: nop
    
            goto L_80043ACC;
    }
    // 0x80043AB4: nop

    // 0x80043AB8: jal         0x80057BAC
    // 0x80043ABC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80057BAC(rdram, ctx);
        goto after_0;
    // 0x80043ABC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80043AC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80043AC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043AC8: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
L_80043ACC:
    // 0x80043ACC: b           L_80043BFC
    // 0x80043AD0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80043BFC;
    // 0x80043AD0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80043AD4:
    // 0x80043AD4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80043AD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80043ADC: lbu         $t2, 0x1E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1E);
    // 0x80043AE0: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x80043AE4: bne         $t1, $at, L_80043B48
    if (ctx->r9 != ctx->r1) {
        // 0x80043AE8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80043B48;
    }
    // 0x80043AE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80043AEC: beq         $t2, $at, L_80043AFC
    if (ctx->r10 == ctx->r1) {
        // 0x80043AF0: lbu         $t4, 0x1F($sp)
        ctx->r12 = MEM_BU(ctx->r29, 0X1F);
            goto L_80043AFC;
    }
    // 0x80043AF0: lbu         $t4, 0x1F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X1F);
    // 0x80043AF4: bne         $t2, $zero, L_80043B34
    if (ctx->r10 != 0) {
        // 0x80043AF8: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80043B34;
    }
    // 0x80043AF8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_80043AFC:
    // 0x80043AFC: lw          $t3, 0x10($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X10);
    // 0x80043B00: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80043B04: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043B08: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80043B0C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80043B10: addiu       $a0, $a0, 0x350
    ctx->r4 = ADD32(ctx->r4, 0X350);
    // 0x80043B14: beq         $t7, $zero, L_80043B2C
    if (ctx->r15 == 0) {
        // 0x80043B18: nop
    
            goto L_80043B2C;
    }
    // 0x80043B18: nop

    // 0x80043B1C: jal         0x80071380
    // 0x80043B20: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80043B20: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    after_1:
    // 0x80043B24: b           L_80043BFC
    // 0x80043B28: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
        goto L_80043BFC;
    // 0x80043B28: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
L_80043B2C:
    // 0x80043B2C: b           L_80043BFC
    // 0x80043B30: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
        goto L_80043BFC;
    // 0x80043B30: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
L_80043B34:
    // 0x80043B34: addiu       $a0, $a0, 0x360
    ctx->r4 = ADD32(ctx->r4, 0X360);
    // 0x80043B38: addiu       $a1, $zero, 0x21B
    ctx->r5 = ADD32(0, 0X21B);
    // 0x80043B3C: jal         0x80071380
    // 0x80043B40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x80043B40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80043B44: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80043B48:
    // 0x80043B48: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    // 0x80043B4C: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x80043B50: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80043B54: bnel        $t8, $zero, L_80043B68
    if (ctx->r24 != 0) {
        // 0x80043B58: lw          $t9, 0x4($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X4);
            goto L_80043B68;
    }
    goto skip_0;
    // 0x80043B58: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80043B5C: b           L_80043BFC
    // 0x80043B60: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_80043BFC;
    // 0x80043B60: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80043B64: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
L_80043B68:
    // 0x80043B68: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    // 0x80043B6C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    // 0x80043B70: bne         $t9, $zero, L_80043B80
    if (ctx->r25 != 0) {
        // 0x80043B74: addiu       $v1, $zero, 0x8
        ctx->r3 = ADD32(0, 0X8);
            goto L_80043B80;
    }
    // 0x80043B74: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80043B78: b           L_80043BFC
    // 0x80043B7C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80043BFC;
    // 0x80043B7C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80043B80:
    // 0x80043B80: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80043B84: bnel        $t0, $zero, L_80043B9C
    if (ctx->r8 != 0) {
        // 0x80043B88: lw          $t1, 0x4($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X4);
            goto L_80043B9C;
    }
    goto skip_1;
    // 0x80043B88: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x80043B8C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80043B90: b           L_80043BFC
    // 0x80043B94: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80043BFC;
    // 0x80043B94: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80043B98: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
L_80043B9C:
    // 0x80043B9C: bnel        $t1, $zero, L_80043BB8
    if (ctx->r9 != 0) {
        // 0x80043BA0: lw          $t2, 0x8($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X8);
            goto L_80043BB8;
    }
    goto skip_2;
    // 0x80043BA0: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    skip_2:
    // 0x80043BA4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80043BA8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80043BAC: b           L_80043BFC
    // 0x80043BB0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80043BFC;
    // 0x80043BB0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80043BB4: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
L_80043BB8:
    // 0x80043BB8: bnel        $t2, $zero, L_80043BD4
    if (ctx->r10 != 0) {
        // 0x80043BBC: lw          $t4, 0xC($v0)
        ctx->r12 = MEM_W(ctx->r2, 0XC);
            goto L_80043BD4;
    }
    goto skip_3;
    // 0x80043BBC: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    skip_3:
    // 0x80043BC0: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80043BC4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80043BC8: b           L_80043BFC
    // 0x80043BCC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80043BFC;
    // 0x80043BCC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80043BD0: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
L_80043BD4:
    // 0x80043BD4: bnel        $t4, $zero, L_80043BF0
    if (ctx->r12 != 0) {
        // 0x80043BD8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80043BF0;
    }
    goto skip_4;
    // 0x80043BD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_4:
    // 0x80043BDC: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x80043BE0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80043BE4: b           L_80043BFC
    // 0x80043BE8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_80043BFC;
    // 0x80043BE8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80043BEC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80043BF0:
    // 0x80043BF0: bne         $v1, $a0, L_80043B80
    if (ctx->r3 != ctx->r4) {
        // 0x80043BF4: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_80043B80;
    }
    // 0x80043BF4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80043BF8: addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
L_80043BFC:
    // 0x80043BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043C00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80043C04: jr          $ra
    // 0x80043C08: nop

    return;
    // 0x80043C08: nop

;}
RECOMP_FUNC void func_8064A97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A97C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A980: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064A984: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8064A988: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8064A98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A990: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8064A994: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8064A998: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8064A99C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064A9A0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8064A9A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8064A9A8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8064A9AC: lui         $t2, 0x8065
    ctx->r10 = S32(RELOC_HI16(495, 0X2DC4) << 16);
    // 0x8064A9B0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8064A9B4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8064A9B8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8064A9BC: lw          $t2, -0x316C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(495, 0X2DC4));
    // 0x8064A9C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064A9C4: jal         0x8064A764
    // 0x8064A9C8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8064A764(rdram, ctx);
        goto after_0;
    // 0x8064A9C8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8064A9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064A9D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A9D4: jr          $ra
    // 0x8064A9D8: nop

    return;
    // 0x8064A9D8: nop

;}
RECOMP_FUNC void func_804C6C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C6C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C6C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C6C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C6C6C: lui         $a0, 0x804C
    ctx->r4 = S32(RELOC_HI16(221, 0X3B0) << 16);
    // 0x804C6C70: lui         $a1, 0x804C
    ctx->r5 = S32(RELOC_HI16(221, 0X3C0) << 16);
    // 0x804C6C74: addiu       $a1, $a1, 0x7020
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(221, 0X3C0));
    // 0x804C6C78: addiu       $a0, $a0, 0x7010
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(221, 0X3B0));
    // 0x804C6C7C: jal         0x8004667C
    // 0x804C6C80: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804C6C80: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x804C6C84: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x804C6C88: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x804C6C8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C6C90: lui         $a2, 0x804C
    ctx->r6 = S32(RELOC_HI16(221, 0X1F0) << 16);
    // 0x804C6C94: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x804C6C98: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x804C6C9C: bnel        $t7, $zero, L_804C6CB0
    if (ctx->r15 != 0) {
        // 0x804C6CA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C6CB0;
    }
    goto skip_0;
    // 0x804C6CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C6CA4: jal         0x80057B28
    // 0x804C6CA8: addiu       $a2, $a2, 0x6E50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(221, 0X1F0));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x804C6CA8: addiu       $a2, $a2, 0x6E50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(221, 0X1F0));
    after_1:
    // 0x804C6CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C6CB0:
    // 0x804C6CB0: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(221, 0X60) << 16);
    // 0x804C6CB4: addiu       $v0, $v0, 0x6CC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(221, 0X60));
    // 0x804C6CB8: jr          $ra
    // 0x804C6CBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804C6CBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8057FA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057FA74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057FA78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057FA7C: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47D4) << 16);
    // 0x8057FA80: lwc1        $f2, 0x35E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47D4));
    // 0x8057FA84: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8057FA88: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057FA8C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8057FA90: nop

    // 0x8057FA94: bc1fl       L_8057FB10
    if (!c1cs) {
        // 0x8057FA98: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_8057FB10;
    }
    goto skip_0;
    // 0x8057FA98: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_0:
    // 0x8057FA9C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8057FAA0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47D8) << 16);
    // 0x8057FAA4: bnel        $t6, $zero, L_8057FAE4
    if (ctx->r14 != 0) {
        // 0x8057FAA8: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8057FAE4;
    }
    goto skip_1;
    // 0x8057FAA8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x8057FAAC: lwc1        $f2, 0x35E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47D8));
    // 0x8057FAB0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8057FAB4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8057FAB8: nop

    // 0x8057FABC: bc1f        L_8057FAD8
    if (!c1cs) {
        // 0x8057FAC0: nop
    
            goto L_8057FAD8;
    }
    // 0x8057FAC0: nop

    // 0x8057FAC4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8057FAC8: jal         0x8057F914
    // 0x8057FACC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_8057F914(rdram, ctx);
        goto after_0;
    // 0x8057FACC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x8057FAD0: b           L_8057FB1C
    // 0x8057FAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8057FB1C;
    // 0x8057FAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057FAD8:
    // 0x8057FAD8: b           L_8057FB18
    // 0x8057FADC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_8057FB18;
    // 0x8057FADC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8057FAE0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8057FAE4:
    // 0x8057FAE4: nop

    // 0x8057FAE8: bc1f        L_8057FB04
    if (!c1cs) {
        // 0x8057FAEC: nop
    
            goto L_8057FB04;
    }
    // 0x8057FAEC: nop

    // 0x8057FAF0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8057FAF4: jal         0x8057F8C4
    // 0x8057FAF8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_8057F8C4(rdram, ctx);
        goto after_1;
    // 0x8057FAF8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_1:
    // 0x8057FAFC: b           L_8057FB1C
    // 0x8057FB00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8057FB1C;
    // 0x8057FB00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057FB04:
    // 0x8057FB04: b           L_8057FB18
    // 0x8057FB08: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8057FB18;
    // 0x8057FB08: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8057FB0C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_8057FB10:
    // 0x8057FB10: jal         0x8057F914
    // 0x8057FB14: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    func_8057F914(rdram, ctx);
        goto after_2;
    // 0x8057FB14: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_2:
L_8057FB18:
    // 0x8057FB18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057FB1C:
    // 0x8057FB1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057FB20: jr          $ra
    // 0x8057FB24: nop

    return;
    // 0x8057FB24: nop

;}
RECOMP_FUNC void func_8067E780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E780: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8067E784: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8067E788: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(544, 0X1180) << 16);
    // 0x8067E78C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8067E790: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8067E794: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8067E798: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8067E79C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8067E7A0: lwc1        $f24, -0xFC0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(544, 0X1180));
    // 0x8067E7A4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8067E7A8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8067E7AC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8067E7B0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8067E7B4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8067E7B8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8067E7BC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8067E7C0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8067E7C4: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(544, 0X1184) << 16);
    // 0x8067E7C8: lui         $s4, 0x4571
    ctx->r20 = S32(0X4571 << 16);
    // 0x8067E7CC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8067E7D0: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067E7D4: ori         $s4, $s4, 0x2000
    ctx->r20 = ctx->r20 | 0X2000;
    // 0x8067E7D8: lwc1        $f22, -0xFBC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(544, 0X1184));
    // 0x8067E7DC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8067E7E0: addiu       $s6, $zero, 0x3FF
    ctx->r22 = ADD32(0, 0X3FF);
L_8067E7E4:
    // 0x8067E7E4: jal         0x80047090
    // 0x8067E7E8: addiu       $a0, $zero, 0x4571
    ctx->r4 = ADD32(0, 0X4571);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8067E7E8: addiu       $a0, $zero, 0x4571
    ctx->r4 = ADD32(0, 0X4571);
    after_0:
    // 0x8067E7EC: beq         $s6, $v0, L_8067E910
    if (ctx->r22 == ctx->r2) {
        // 0x8067E7F0: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_8067E910;
    }
    // 0x8067E7F0: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x8067E7F4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8067E7F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8067E7FC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8067E800: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8067E804: addu        $s1, $s5, $t7
    ctx->r17 = ADD32(ctx->r21, ctx->r15);
    // 0x8067E808: jal         0x8004613C
    // 0x8067E80C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8067E80C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8067E810: beq         $v0, $zero, L_8067E85C
    if (ctx->r2 == 0) {
        // 0x8067E814: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8067E85C;
    }
    // 0x8067E814: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8067E818: lhu         $t0, 0xE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XE);
    // 0x8067E81C: andi        $t9, $s3, 0x3FF
    ctx->r25 = ctx->r19 & 0X3FF;
    // 0x8067E820: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8067E824: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x8067E828: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8067E82C: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x8067E830: jal         0x80047F9C
    // 0x8067E834: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8067E834: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_2:
    // 0x8067E838: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x8067E83C: jal         0x8067E734
    // 0x8067E840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E734(rdram, ctx);
        goto after_3;
    // 0x8067E840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8067E844: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x8067E848: nop

    // 0x8067E84C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8067E850: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8067E854: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8067E858: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_8067E85C:
    // 0x8067E85C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8067E860: blez        $s2, L_8067E7E4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8067E864: sw          $s0, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->r16;
            goto L_8067E7E4;
    }
    // 0x8067E864: sw          $s0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r16;
    // 0x8067E868: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8067E86C: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
L_8067E870:
    // 0x8067E870: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8067E874: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8067E878: blez        $s2, L_8067E870
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8067E87C: sw          $zero, 0x14($s1)
        MEM_W(0X14, ctx->r17) = 0;
            goto L_8067E870;
    }
    // 0x8067E87C: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8067E880: lui         $s7, 0x4572
    ctx->r23 = S32(0X4572 << 16);
    // 0x8067E884: ori         $s7, $s7, 0x2000
    ctx->r23 = ctx->r23 | 0X2000;
    // 0x8067E888: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8067E88C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_8067E890:
    // 0x8067E890: jal         0x80047090
    // 0x8067E894: addiu       $a0, $zero, 0x4572
    ctx->r4 = ADD32(0, 0X4572);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x8067E894: addiu       $a0, $zero, 0x4572
    ctx->r4 = ADD32(0, 0X4572);
    after_4:
    // 0x8067E898: beq         $s6, $v0, L_8067E910
    if (ctx->r22 == ctx->r2) {
        // 0x8067E89C: andi        $s3, $v0, 0xFFFF
        ctx->r19 = ctx->r2 & 0XFFFF;
            goto L_8067E910;
    }
    // 0x8067E89C: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x8067E8A0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8067E8A4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8067E8A8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8067E8AC: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x8067E8B0: addu        $s1, $s5, $t3
    ctx->r17 = ADD32(ctx->r21, ctx->r11);
    // 0x8067E8B4: jal         0x8004613C
    // 0x8067E8B8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x8067E8B8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_5:
    // 0x8067E8BC: beq         $v0, $zero, L_8067E8FC
    if (ctx->r2 == 0) {
        // 0x8067E8C0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8067E8FC;
    }
    // 0x8067E8C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8067E8C4: lhu         $t6, 0xE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XE);
    // 0x8067E8C8: andi        $t5, $s3, 0x3FF
    ctx->r13 = ctx->r19 & 0X3FF;
    // 0x8067E8CC: lui         $s4, 0x8068
    ctx->r20 = S32(RELOC_HI16(544, 0X860) << 16);
    // 0x8067E8D0: andi        $t7, $t6, 0xFC00
    ctx->r15 = ctx->r14 & 0XFC00;
    // 0x8067E8D4: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8067E8D8: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x8067E8DC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8067E8E0: addiu       $s4, $s4, -0x18E0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(544, 0X860));
    // 0x8067E8E4: jal         0x80047F9C
    // 0x8067E8E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8067E8E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8067E8EC: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x8067E8F0: jal         0x8067E734
    // 0x8067E8F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E734(rdram, ctx);
        goto after_7;
    // 0x8067E8F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8067E8F8: sw          $s4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r20;
L_8067E8FC:
    // 0x8067E8FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8067E900: bne         $s2, $fp, L_8067E890
    if (ctx->r18 != ctx->r30) {
        // 0x8067E904: sw          $s0, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->r16;
            goto L_8067E890;
    }
    // 0x8067E904: sw          $s0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r16;
    // 0x8067E908: sw          $zero, 0x10($s5)
    MEM_W(0X10, ctx->r21) = 0;
    // 0x8067E90C: sw          $zero, 0xC($s5)
    MEM_W(0XC, ctx->r21) = 0;
L_8067E910:
    // 0x8067E910: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8067E914: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8067E918: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8067E91C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8067E920: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8067E924: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8067E928: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8067E92C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8067E930: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8067E934: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8067E938: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8067E93C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8067E940: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8067E944: jr          $ra
    // 0x8067E948: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8067E948: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80530774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80530778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8053077C: jal         0x8004700C
    // 0x80530780: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80530780: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80530784: beq         $v0, $zero, L_805307FC
    if (ctx->r2 == 0) {
        // 0x80530788: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805307FC;
    }
    // 0x80530788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8053078C: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x80530790: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80530794: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80530798: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8053079C: bne         $t6, $at, L_805307FC
    if (ctx->r14 != ctx->r1) {
        // 0x805307A0: sub.s       $f2, $f4, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_805307FC;
    }
    // 0x805307A0: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805307A4: lbu         $t7, 0x30($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X30);
    // 0x805307A8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x805307AC: bne         $t7, $at, L_805307FC
    if (ctx->r15 != ctx->r1) {
        // 0x805307B0: lui         $at, 0x8053
        ctx->r1 = S32(RELOC_HI16(336, 0X40C) << 16);
            goto L_805307FC;
    }
    // 0x805307B0: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(336, 0X40C) << 16);
    // 0x805307B4: lwc1        $f8, 0x89C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(336, 0X40C));
    // 0x805307B8: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x805307BC: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x805307C0: nop

    // 0x805307C4: bc1fl       L_80530800
    if (!c1cs) {
        // 0x805307C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80530800;
    }
    goto skip_0;
    // 0x805307C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805307CC: lw          $t8, 0x174($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X174);
    // 0x805307D0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x805307D4: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x805307D8: beql        $t0, $zero, L_80530800
    if (ctx->r8 == 0) {
        // 0x805307DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80530800;
    }
    goto skip_1;
    // 0x805307DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805307E0: jal         0x805304DC
    // 0x805307E4: nop

    func_805304DC(rdram, ctx);
        goto after_1;
    // 0x805307E4: nop

    after_1:
    // 0x805307E8: jal         0x805306C4
    // 0x805307EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805306C4(rdram, ctx);
        goto after_2;
    // 0x805307EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x805307F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805307F4: jal         0x80530834
    // 0x805307F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80530834(rdram, ctx);
        goto after_3;
    // 0x805307F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_805307FC:
    // 0x805307FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80530800:
    // 0x80530800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80530804: jr          $ra
    // 0x80530808: nop

    return;
    // 0x80530808: nop

;}
RECOMP_FUNC void func_805662F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805662F0: jr          $ra
    // 0x805662F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805662F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805ABE2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABE2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805ABE30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805ABE34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ABE38: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(438, 0X594) << 16);
    // 0x805ABE3C: lwc1        $f6, -0x3EDC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(438, 0X594));
    // 0x805ABE40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805ABE44: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x805ABE48: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x805ABE4C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x805ABE50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805ABE54: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x805ABE58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x805ABE5C: jal         0x805ABD0C
    // 0x805ABE60: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_805ABD0C(rdram, ctx);
        goto after_0;
    // 0x805ABE60: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x805ABE64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ABE68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ABE6C: jr          $ra
    // 0x805ABE70: nop

    return;
    // 0x805ABE70: nop

;}
RECOMP_FUNC void func_805D2F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2F88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D2F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D2F90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805D2F94: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D2F98: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x805D2F9C: jal         0x80058B44
    // 0x805D2FA0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80058B44(rdram, ctx);
        goto after_0;
    // 0x805D2FA0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805D2FA4: bne         $v0, $zero, L_805D2FD8
    if (ctx->r2 != 0) {
        // 0x805D2FA8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_805D2FD8;
    }
    // 0x805D2FA8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805D2FAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805D2FB0: jal         0x805D2090
    // 0x805D2FB4: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    func_805D2090(rdram, ctx);
        goto after_1;
    // 0x805D2FB4: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    after_1:
    // 0x805D2FB8: beq         $v0, $zero, L_805D2FD8
    if (ctx->r2 == 0) {
        // 0x805D2FBC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805D2FD8;
    }
    // 0x805D2FBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805D2FC0: jal         0x80058B98
    // 0x805D2FC4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80058B98(rdram, ctx);
        goto after_2;
    // 0x805D2FC4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x805D2FC8: bne         $v0, $zero, L_805D2FD8
    if (ctx->r2 != 0) {
        // 0x805D2FCC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805D2FD8;
    }
    // 0x805D2FCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D2FD0: jal         0x800447C8
    // 0x805D2FD4: nop

    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x805D2FD4: nop

    after_3:
L_805D2FD8:
    // 0x805D2FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D2FDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D2FE0: jr          $ra
    // 0x805D2FE4: nop

    return;
    // 0x805D2FE4: nop

;}
RECOMP_FUNC void Fault_LogThreadContext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070038: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x8007003C: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x80070040: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80070044: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_80070048:
    // 0x80070048: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x8007004C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80070050: bne         $t9, $sp, L_80070048
    if (ctx->r25 != ctx->r29) {
        // 0x80070054: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_80070048;
    }
    // 0x80070054: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80070058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007005C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80070060: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80070064: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80070068: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8007006C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070070: lw          $s0, 0x120($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X120);
    // 0x80070074: srl         $s0, $s0, 2
    ctx->r16 = S32(U32(ctx->r16) >> 2);
    // 0x80070078: andi        $s0, $s0, 0x1F
    ctx->r16 = ctx->r16 & 0X1F;
    // 0x8007007C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80070080: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80070084: bnel        $s0, $at, L_80070094
    if (ctx->r16 != ctx->r1) {
        // 0x80070088: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_80070094;
    }
    goto skip_0;
    // 0x80070088: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    skip_0:
    // 0x8007008C: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // 0x80070090: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
L_80070094:
    // 0x80070094: bne         $s0, $at, L_800700A0
    if (ctx->r16 != ctx->r1) {
        // 0x80070098: nop
    
            goto L_800700A0;
    }
    // 0x80070098: nop

    // 0x8007009C: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
L_800700A0:
    // 0x800700A0: jal         0x8008AD5C
    // 0x800700A4: addiu       $a0, $a0, 0x1570
    ctx->r4 = ADD32(ctx->r4, 0X1570);
    osSyncPrintf(rdram, ctx);
        goto after_0;
    // 0x800700A4: addiu       $a0, $a0, 0x1570
    ctx->r4 = ADD32(ctx->r4, 0X1570);
    after_0:
    // 0x800700A8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800700AC: addiu       $a0, $a0, 0x1574
    ctx->r4 = ADD32(ctx->r4, 0X1574);
    // 0x800700B0: jal         0x8008AD5C
    // 0x800700B4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    osSyncPrintf(rdram, ctx);
        goto after_1;
    // 0x800700B4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800700B8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800700BC: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x800700C0: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800700C4: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x800700C8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800700CC: addiu       $a0, $a0, 0x1584
    ctx->r4 = ADD32(ctx->r4, 0X1584);
    // 0x800700D0: lw          $a2, -0x7BF4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7BF4);
    // 0x800700D4: jal         0x8008AD5C
    // 0x800700D8: lw          $a1, 0x14($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X14);
    osSyncPrintf(rdram, ctx);
        goto after_2;
    // 0x800700D8: lw          $a1, 0x14($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X14);
    after_2:
    // 0x800700DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800700E0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800700E4: addiu       $a0, $a0, 0x1598
    ctx->r4 = ADD32(ctx->r4, 0X1598);
    // 0x800700E8: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x800700EC: lw          $a3, 0x104($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X104);
    // 0x800700F0: lw          $a2, 0xF8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XF8);
    // 0x800700F4: jal         0x8008AD5C
    // 0x800700F8: lw          $a1, 0xFC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XFC);
    osSyncPrintf(rdram, ctx);
        goto after_3;
    // 0x800700F8: lw          $a1, 0xFC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XFC);
    after_3:
    // 0x800700FC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070100: addiu       $a0, $a0, 0x15B8
    ctx->r4 = ADD32(ctx->r4, 0X15B8);
    // 0x80070104: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80070108: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8007010C: jal         0x8008AD5C
    // 0x80070110: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    osSyncPrintf(rdram, ctx);
        goto after_4;
    // 0x80070110: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_4:
    // 0x80070114: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070118: addiu       $a0, $a0, 0x15D8
    ctx->r4 = ADD32(ctx->r4, 0X15D8);
    // 0x8007011C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80070120: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80070124: jal         0x8008AD5C
    // 0x80070128: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    osSyncPrintf(rdram, ctx);
        goto after_5;
    // 0x80070128: lw          $a3, 0x2C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2C);
    after_5:
    // 0x8007012C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070130: addiu       $a0, $a0, 0x15F8
    ctx->r4 = ADD32(ctx->r4, 0X15F8);
    // 0x80070134: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80070138: lw          $a2, 0x3C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X3C);
    // 0x8007013C: jal         0x8008AD5C
    // 0x80070140: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    osSyncPrintf(rdram, ctx);
        goto after_6;
    // 0x80070140: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    after_6:
    // 0x80070144: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070148: addiu       $a0, $a0, 0x1618
    ctx->r4 = ADD32(ctx->r4, 0X1618);
    // 0x8007014C: lw          $a1, 0x4C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4C);
    // 0x80070150: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80070154: jal         0x8008AD5C
    // 0x80070158: lw          $a3, 0x5C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X5C);
    osSyncPrintf(rdram, ctx);
        goto after_7;
    // 0x80070158: lw          $a3, 0x5C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X5C);
    after_7:
    // 0x8007015C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070160: addiu       $a0, $a0, 0x1638
    ctx->r4 = ADD32(ctx->r4, 0X1638);
    // 0x80070164: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80070168: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    // 0x8007016C: jal         0x8008AD5C
    // 0x80070170: lw          $a3, 0x74($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X74);
    osSyncPrintf(rdram, ctx);
        goto after_8;
    // 0x80070170: lw          $a3, 0x74($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X74);
    after_8:
    // 0x80070174: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070178: addiu       $a0, $a0, 0x1658
    ctx->r4 = ADD32(ctx->r4, 0X1658);
    // 0x8007017C: lw          $a1, 0x7C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7C);
    // 0x80070180: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    // 0x80070184: jal         0x8008AD5C
    // 0x80070188: lw          $a3, 0x8C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8C);
    osSyncPrintf(rdram, ctx);
        goto after_9;
    // 0x80070188: lw          $a3, 0x8C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8C);
    after_9:
    // 0x8007018C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070190: addiu       $a0, $a0, 0x1678
    ctx->r4 = ADD32(ctx->r4, 0X1678);
    // 0x80070194: lw          $a1, 0x94($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X94);
    // 0x80070198: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x8007019C: jal         0x8008AD5C
    // 0x800701A0: lw          $a3, 0xA4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XA4);
    osSyncPrintf(rdram, ctx);
        goto after_10;
    // 0x800701A0: lw          $a3, 0xA4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XA4);
    after_10:
    // 0x800701A4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800701A8: addiu       $a0, $a0, 0x1698
    ctx->r4 = ADD32(ctx->r4, 0X1698);
    // 0x800701AC: lw          $a1, 0xAC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XAC);
    // 0x800701B0: lw          $a2, 0xB4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XB4);
    // 0x800701B4: jal         0x8008AD5C
    // 0x800701B8: lw          $a3, 0xBC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XBC);
    osSyncPrintf(rdram, ctx);
        goto after_11;
    // 0x800701B8: lw          $a3, 0xBC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XBC);
    after_11:
    // 0x800701BC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800701C0: addiu       $a0, $a0, 0x16B8
    ctx->r4 = ADD32(ctx->r4, 0X16B8);
    // 0x800701C4: lw          $a1, 0xC4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC4);
    // 0x800701C8: lw          $a2, 0xCC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XCC);
    // 0x800701CC: jal         0x8008AD5C
    // 0x800701D0: lw          $a3, 0xD4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XD4);
    osSyncPrintf(rdram, ctx);
        goto after_12;
    // 0x800701D0: lw          $a3, 0xD4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XD4);
    after_12:
    // 0x800701D4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800701D8: addiu       $a0, $a0, 0x16D8
    ctx->r4 = ADD32(ctx->r4, 0X16D8);
    // 0x800701DC: lw          $a1, 0xDC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XDC);
    // 0x800701E0: jal         0x8008AD5C
    // 0x800701E4: lw          $a2, 0xE4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE4);
    osSyncPrintf(rdram, ctx);
        goto after_13;
    // 0x800701E4: lw          $a2, 0xE4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE4);
    after_13:
    // 0x800701E8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800701EC: jal         0x8008AD5C
    // 0x800701F0: addiu       $a0, $a0, 0x16F8
    ctx->r4 = ADD32(ctx->r4, 0X16F8);
    osSyncPrintf(rdram, ctx);
        goto after_14;
    // 0x800701F0: addiu       $a0, $a0, 0x16F8
    ctx->r4 = ADD32(ctx->r4, 0X16F8);
    after_14:
    // 0x800701F4: jal         0x8006FB6C
    // 0x800701F8: lw          $a0, 0x10C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10C);
    Fault_LogFPCSR(rdram, ctx);
        goto after_15;
    // 0x800701F8: lw          $a0, 0x10C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10C);
    after_15:
    // 0x800701FC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070200: jal         0x8008AD5C
    // 0x80070204: addiu       $a0, $a0, 0x16FC
    ctx->r4 = ADD32(ctx->r4, 0X16FC);
    osSyncPrintf(rdram, ctx);
        goto after_16;
    // 0x80070204: addiu       $a0, $a0, 0x16FC
    ctx->r4 = ADD32(ctx->r4, 0X16FC);
    after_16:
    // 0x80070208: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007020C: jal         0x8006FA08
    // 0x80070210: addiu       $a1, $s0, 0x114
    ctx->r5 = ADD32(ctx->r16, 0X114);
    Fault_LogFReg(rdram, ctx);
        goto after_17;
    // 0x80070210: addiu       $a1, $s0, 0x114
    ctx->r5 = ADD32(ctx->r16, 0X114);
    after_17:
    // 0x80070214: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80070218: jal         0x8006FA08
    // 0x8007021C: addiu       $a1, $s0, 0x11C
    ctx->r5 = ADD32(ctx->r16, 0X11C);
    Fault_LogFReg(rdram, ctx);
        goto after_18;
    // 0x8007021C: addiu       $a1, $s0, 0x11C
    ctx->r5 = ADD32(ctx->r16, 0X11C);
    after_18:
    // 0x80070220: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070224: jal         0x8008AD5C
    // 0x80070228: addiu       $a0, $a0, 0x1700
    ctx->r4 = ADD32(ctx->r4, 0X1700);
    osSyncPrintf(rdram, ctx);
        goto after_19;
    // 0x80070228: addiu       $a0, $a0, 0x1700
    ctx->r4 = ADD32(ctx->r4, 0X1700);
    after_19:
    // 0x8007022C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80070230: jal         0x8006FA08
    // 0x80070234: addiu       $a1, $s0, 0x124
    ctx->r5 = ADD32(ctx->r16, 0X124);
    Fault_LogFReg(rdram, ctx);
        goto after_20;
    // 0x80070234: addiu       $a1, $s0, 0x124
    ctx->r5 = ADD32(ctx->r16, 0X124);
    after_20:
    // 0x80070238: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8007023C: jal         0x8006FA08
    // 0x80070240: addiu       $a1, $s0, 0x12C
    ctx->r5 = ADD32(ctx->r16, 0X12C);
    Fault_LogFReg(rdram, ctx);
        goto after_21;
    // 0x80070240: addiu       $a1, $s0, 0x12C
    ctx->r5 = ADD32(ctx->r16, 0X12C);
    after_21:
    // 0x80070244: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070248: jal         0x8008AD5C
    // 0x8007024C: addiu       $a0, $a0, 0x1704
    ctx->r4 = ADD32(ctx->r4, 0X1704);
    osSyncPrintf(rdram, ctx);
        goto after_22;
    // 0x8007024C: addiu       $a0, $a0, 0x1704
    ctx->r4 = ADD32(ctx->r4, 0X1704);
    after_22:
    // 0x80070250: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80070254: jal         0x8006FA08
    // 0x80070258: addiu       $a1, $s0, 0x134
    ctx->r5 = ADD32(ctx->r16, 0X134);
    Fault_LogFReg(rdram, ctx);
        goto after_23;
    // 0x80070258: addiu       $a1, $s0, 0x134
    ctx->r5 = ADD32(ctx->r16, 0X134);
    after_23:
    // 0x8007025C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80070260: jal         0x8006FA08
    // 0x80070264: addiu       $a1, $s0, 0x13C
    ctx->r5 = ADD32(ctx->r16, 0X13C);
    Fault_LogFReg(rdram, ctx);
        goto after_24;
    // 0x80070264: addiu       $a1, $s0, 0x13C
    ctx->r5 = ADD32(ctx->r16, 0X13C);
    after_24:
    // 0x80070268: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8007026C: jal         0x8008AD5C
    // 0x80070270: addiu       $a0, $a0, 0x1708
    ctx->r4 = ADD32(ctx->r4, 0X1708);
    osSyncPrintf(rdram, ctx);
        goto after_25;
    // 0x80070270: addiu       $a0, $a0, 0x1708
    ctx->r4 = ADD32(ctx->r4, 0X1708);
    after_25:
    // 0x80070274: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80070278: jal         0x8006FA08
    // 0x8007027C: addiu       $a1, $s0, 0x144
    ctx->r5 = ADD32(ctx->r16, 0X144);
    Fault_LogFReg(rdram, ctx);
        goto after_26;
    // 0x8007027C: addiu       $a1, $s0, 0x144
    ctx->r5 = ADD32(ctx->r16, 0X144);
    after_26:
    // 0x80070280: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80070284: jal         0x8006FA08
    // 0x80070288: addiu       $a1, $s0, 0x14C
    ctx->r5 = ADD32(ctx->r16, 0X14C);
    Fault_LogFReg(rdram, ctx);
        goto after_27;
    // 0x80070288: addiu       $a1, $s0, 0x14C
    ctx->r5 = ADD32(ctx->r16, 0X14C);
    after_27:
    // 0x8007028C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070290: jal         0x8008AD5C
    // 0x80070294: addiu       $a0, $a0, 0x170C
    ctx->r4 = ADD32(ctx->r4, 0X170C);
    osSyncPrintf(rdram, ctx);
        goto after_28;
    // 0x80070294: addiu       $a0, $a0, 0x170C
    ctx->r4 = ADD32(ctx->r4, 0X170C);
    after_28:
    // 0x80070298: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007029C: jal         0x8006FA08
    // 0x800702A0: addiu       $a1, $s0, 0x154
    ctx->r5 = ADD32(ctx->r16, 0X154);
    Fault_LogFReg(rdram, ctx);
        goto after_29;
    // 0x800702A0: addiu       $a1, $s0, 0x154
    ctx->r5 = ADD32(ctx->r16, 0X154);
    after_29:
    // 0x800702A4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x800702A8: jal         0x8006FA08
    // 0x800702AC: addiu       $a1, $s0, 0x15C
    ctx->r5 = ADD32(ctx->r16, 0X15C);
    Fault_LogFReg(rdram, ctx);
        goto after_30;
    // 0x800702AC: addiu       $a1, $s0, 0x15C
    ctx->r5 = ADD32(ctx->r16, 0X15C);
    after_30:
    // 0x800702B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800702B4: jal         0x8008AD5C
    // 0x800702B8: addiu       $a0, $a0, 0x1710
    ctx->r4 = ADD32(ctx->r4, 0X1710);
    osSyncPrintf(rdram, ctx);
        goto after_31;
    // 0x800702B8: addiu       $a0, $a0, 0x1710
    ctx->r4 = ADD32(ctx->r4, 0X1710);
    after_31:
    // 0x800702BC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800702C0: jal         0x8006FA08
    // 0x800702C4: addiu       $a1, $s0, 0x164
    ctx->r5 = ADD32(ctx->r16, 0X164);
    Fault_LogFReg(rdram, ctx);
        goto after_32;
    // 0x800702C4: addiu       $a1, $s0, 0x164
    ctx->r5 = ADD32(ctx->r16, 0X164);
    after_32:
    // 0x800702C8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800702CC: jal         0x8006FA08
    // 0x800702D0: addiu       $a1, $s0, 0x16C
    ctx->r5 = ADD32(ctx->r16, 0X16C);
    Fault_LogFReg(rdram, ctx);
        goto after_33;
    // 0x800702D0: addiu       $a1, $s0, 0x16C
    ctx->r5 = ADD32(ctx->r16, 0X16C);
    after_33:
    // 0x800702D4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800702D8: jal         0x8008AD5C
    // 0x800702DC: addiu       $a0, $a0, 0x1714
    ctx->r4 = ADD32(ctx->r4, 0X1714);
    osSyncPrintf(rdram, ctx);
        goto after_34;
    // 0x800702DC: addiu       $a0, $a0, 0x1714
    ctx->r4 = ADD32(ctx->r4, 0X1714);
    after_34:
    // 0x800702E0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800702E4: jal         0x8006FA08
    // 0x800702E8: addiu       $a1, $s0, 0x174
    ctx->r5 = ADD32(ctx->r16, 0X174);
    Fault_LogFReg(rdram, ctx);
        goto after_35;
    // 0x800702E8: addiu       $a1, $s0, 0x174
    ctx->r5 = ADD32(ctx->r16, 0X174);
    after_35:
    // 0x800702EC: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x800702F0: jal         0x8006FA08
    // 0x800702F4: addiu       $a1, $s0, 0x17C
    ctx->r5 = ADD32(ctx->r16, 0X17C);
    Fault_LogFReg(rdram, ctx);
        goto after_36;
    // 0x800702F4: addiu       $a1, $s0, 0x17C
    ctx->r5 = ADD32(ctx->r16, 0X17C);
    after_36:
    // 0x800702F8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800702FC: jal         0x8008AD5C
    // 0x80070300: addiu       $a0, $a0, 0x1718
    ctx->r4 = ADD32(ctx->r4, 0X1718);
    osSyncPrintf(rdram, ctx);
        goto after_37;
    // 0x80070300: addiu       $a0, $a0, 0x1718
    ctx->r4 = ADD32(ctx->r4, 0X1718);
    after_37:
    // 0x80070304: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80070308: jal         0x8006FA08
    // 0x8007030C: addiu       $a1, $s0, 0x184
    ctx->r5 = ADD32(ctx->r16, 0X184);
    Fault_LogFReg(rdram, ctx);
        goto after_38;
    // 0x8007030C: addiu       $a1, $s0, 0x184
    ctx->r5 = ADD32(ctx->r16, 0X184);
    after_38:
    // 0x80070310: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80070314: jal         0x8006FA08
    // 0x80070318: addiu       $a1, $s0, 0x18C
    ctx->r5 = ADD32(ctx->r16, 0X18C);
    Fault_LogFReg(rdram, ctx);
        goto after_39;
    // 0x80070318: addiu       $a1, $s0, 0x18C
    ctx->r5 = ADD32(ctx->r16, 0X18C);
    after_39:
    // 0x8007031C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80070320: jal         0x8008AD5C
    // 0x80070324: addiu       $a0, $a0, 0x171C
    ctx->r4 = ADD32(ctx->r4, 0X171C);
    osSyncPrintf(rdram, ctx);
        goto after_40;
    // 0x80070324: addiu       $a0, $a0, 0x171C
    ctx->r4 = ADD32(ctx->r4, 0X171C);
    after_40:
    // 0x80070328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007032C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80070330: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80070334: jr          $ra
    // 0x80070338: nop

    return;
    // 0x80070338: nop

;}
RECOMP_FUNC void func_80020F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020F8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020F94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80020F98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80020F9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80020FA0: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80020FA4: addiu       $v0, $a2, 0xC
    ctx->r2 = ADD32(ctx->r6, 0XC);
    // 0x80020FA8: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
L_80020FAC:
    // 0x80020FAC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80020FB0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80020FB4: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x80020FB8: bnel        $t7, $zero, L_80020FCC
    if (ctx->r15 != 0) {
        // 0x80020FBC: addu        $t8, $a3, $v1
        ctx->r24 = ADD32(ctx->r7, ctx->r3);
            goto L_80020FCC;
    }
    goto skip_0;
    // 0x80020FBC: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    skip_0:
    // 0x80020FC0: bnel        $v1, $zero, L_80020FAC
    if (ctx->r3 != 0) {
        // 0x80020FC4: lw          $t6, -0x4($v0)
        ctx->r14 = MEM_W(ctx->r2, -0X4);
            goto L_80020FAC;
    }
    goto skip_1;
    // 0x80020FC4: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    skip_1:
    // 0x80020FC8: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
L_80020FCC:
    // 0x80020FCC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80020FD0: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x80020FD4: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80020FD8: jal         0x8004D698
    // 0x80020FDC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8004D698(rdram, ctx);
        goto after_0;
    // 0x80020FDC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x80020FE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80020FE4: jal         0x80020F24
    // 0x80020FE8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80020F24(rdram, ctx);
        goto after_1;
    // 0x80020FE8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80020FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020FF4: jr          $ra
    // 0x80020FF8: nop

    return;
    // 0x80020FF8: nop

;}
RECOMP_FUNC void pad_flush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB08: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x8007FB0C: sb          $zero, 0xE($a0)
    MEM_B(0XE, ctx->r4) = 0;
    // 0x8007FB10: sb          $zero, 0xF($a0)
    MEM_B(0XF, ctx->r4) = 0;
    // 0x8007FB14: jr          $ra
    // 0x8007FB18: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    return;
    // 0x8007FB18: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80475060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475060: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475064: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475068: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047506C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475070: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475074: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475078: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047507C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475080: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475084: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475088: jr          $ra
    // 0x8047508C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047508C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80453888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453888: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045388C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453890: jal         0x80453784
    // 0x80453894: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80453784(rdram, ctx);
        goto after_0;
    // 0x80453894: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80453898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045389C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804538A0: jr          $ra
    // 0x804538A4: nop

    return;
    // 0x804538A4: nop

;}
RECOMP_FUNC void func_805D00FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D00FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D0100: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805D0104: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805D0108: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x805D010C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D0110: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x805D0114: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805D0118: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x805D011C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805D0120: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x805D0124: lui         $t2, 0x805D
    ctx->r10 = S32(RELOC_HI16(462, 0X340) << 16);
    // 0x805D0128: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805D012C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805D0130: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x805D0134: lw          $t2, 0x2B0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(462, 0X340));
    // 0x805D0138: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805D013C: jal         0x805CFFD0
    // 0x805D0140: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_805CFFD0(rdram, ctx);
        goto after_0;
    // 0x805D0140: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x805D0144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D0148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D014C: jr          $ra
    // 0x805D0150: nop

    return;
    // 0x805D0150: nop

;}
RECOMP_FUNC void func_80068890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068898: jal         0x8004700C
    // 0x8006889C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8006889C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800688A0: beq         $v0, $zero, L_800688BC
    if (ctx->r2 == 0) {
        // 0x800688A4: lui         $t6, 0x800F
        ctx->r14 = S32(0X800F << 16);
            goto L_800688BC;
    }
    // 0x800688A4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800688A8: lbu         $t6, 0x7EA5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7EA5);
    // 0x800688AC: bnel        $t6, $zero, L_800688C0
    if (ctx->r14 != 0) {
        // 0x800688B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800688C0;
    }
    goto skip_0;
    // 0x800688B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800688B4: jal         0x8002ADE4
    // 0x800688B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002ADE4(rdram, ctx);
        goto after_1;
    // 0x800688B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_800688BC:
    // 0x800688BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800688C0:
    // 0x800688C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800688C4: jr          $ra
    // 0x800688C8: nop

    return;
    // 0x800688C8: nop

;}
RECOMP_FUNC void func_806F3C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F3C10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F3C14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806F3C18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F3C1C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x806F3C20: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806F3C24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806F3C28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F3C2C: jal         0x806F3BB8
    // 0x806F3C30: ori         $a1, $a1, 0x7CF
    ctx->r5 = ctx->r5 | 0X7CF;
    func_806F3BB8(rdram, ctx);
        goto after_0;
    // 0x806F3C30: ori         $a1, $a1, 0x7CF
    ctx->r5 = ctx->r5 | 0X7CF;
    after_0:
    // 0x806F3C34: beq         $v0, $zero, L_806F3D30
    if (ctx->r2 == 0) {
        // 0x806F3C38: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_806F3D30;
    }
    // 0x806F3C38: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x806F3C3C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x806F3C40: ori         $a1, $a1, 0x7AE
    ctx->r5 = ctx->r5 | 0X7AE;
    // 0x806F3C44: jal         0x806F3BB8
    // 0x806F3C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_806F3BB8(rdram, ctx);
        goto after_1;
    // 0x806F3C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x806F3C4C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806F3C50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F3C54: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x806F3C58: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x806F3C5C: jal         0x806F3B28
    // 0x806F3C60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F3B28(rdram, ctx);
        goto after_2;
    // 0x806F3C60: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x806F3C64: beql        $v0, $zero, L_806F3D34
    if (ctx->r2 == 0) {
        // 0x806F3C68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F3D34;
    }
    goto skip_0;
    // 0x806F3C68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F3C6C: lw          $t7, 0x174($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X174);
    // 0x806F3C70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806F3C74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F3C78: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806F3C7C: jal         0x80044194
    // 0x806F3C80: sb          $t6, 0x74($t8)
    MEM_B(0X74, ctx->r24) = ctx->r14;
    func_80044194(rdram, ctx);
        goto after_3;
    // 0x806F3C80: sb          $t6, 0x74($t8)
    MEM_B(0X74, ctx->r24) = ctx->r14;
    after_3:
    // 0x806F3C84: beq         $s0, $zero, L_806F3CDC
    if (ctx->r16 == 0) {
        // 0x806F3C88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806F3CDC;
    }
    // 0x806F3C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F3C8C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x806F3C90: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x806F3C94: jal         0x806F3B28
    // 0x806F3C98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806F3B28(rdram, ctx);
        goto after_4;
    // 0x806F3C98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x806F3C9C: beql        $v0, $zero, L_806F3D34
    if (ctx->r2 == 0) {
        // 0x806F3CA0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F3D34;
    }
    goto skip_1;
    // 0x806F3CA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806F3CA4: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x806F3CA8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806F3CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F3CB0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806F3CB4: jal         0x8005FDC4
    // 0x806F3CB8: sb          $t9, 0x74($t1)
    MEM_B(0X74, ctx->r9) = ctx->r25;
    func_8005FDC4(rdram, ctx);
        goto after_5;
    // 0x806F3CB8: sb          $t9, 0x74($t1)
    MEM_B(0X74, ctx->r9) = ctx->r25;
    after_5:
    // 0x806F3CBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F3CC0: jal         0x80047F9C
    // 0x806F3CC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x806F3CC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x806F3CC8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X9B4) << 16);
    // 0x806F3CCC: lwc1        $f0, 0x3E04($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X9B4));
    // 0x806F3CD0: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x806F3CD4: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x806F3CD8: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
L_806F3CDC:
    // 0x806F3CDC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x806F3CE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806F3CE4: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x806F3CE8: bne         $t2, $at, L_806F3D14
    if (ctx->r10 != ctx->r1) {
        // 0x806F3CEC: addiu       $t8, $zero, 0xA
        ctx->r24 = ADD32(0, 0XA);
            goto L_806F3D14;
    }
    // 0x806F3CEC: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x806F3CF0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x806F3CF4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x806F3CF8: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x806F3CFC: lbu         $t3, 0xF0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XF0);
    // 0x806F3D00: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x806F3D04: addiu       $t5, $t4, 0x20
    ctx->r13 = ADD32(ctx->r12, 0X20);
    // 0x806F3D08: sb          $t5, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = ctx->r13;
    // 0x806F3D0C: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
    // 0x806F3D10: sb          $zero, 0xF2($t7)
    MEM_B(0XF2, ctx->r15) = 0;
L_806F3D14:
    // 0x806F3D14: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F3D18: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x806F3D1C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F3D20: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x806F3D24: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F3D28: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x806F3D2C: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
L_806F3D30:
    // 0x806F3D30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F3D34:
    // 0x806F3D34: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806F3D38: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806F3D3C: jr          $ra
    // 0x806F3D40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806F3D40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F3D44: nop

    // 0x806F3D48: nop

    // 0x806F3D4C: nop

;}
RECOMP_FUNC void func_804469FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804469FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80446A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80446A04: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446A08: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446A0C: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X131F8) << 16);
    // 0x80446A10: sw          $t6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r14;
    // 0x80446A14: lw          $v1, 0x75D8($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X131F8));
    // 0x80446A18: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80446A1C: beql        $v1, $zero, L_80446A34
    if (ctx->r3 == 0) {
        // 0x80446A20: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80446A34;
    }
    goto skip_0;
    // 0x80446A20: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_0:
    // 0x80446A24: jalr        $v1
    // 0x80446A28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80446A28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80446A2C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80446A30: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_80446A34:
    // 0x80446A34: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446A38: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80446A3C: sw          $t7, 0x6CC0($at)
    MEM_W(0X6CC0, ctx->r1) = ctx->r15;
    // 0x80446A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80446A44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80446A48: jr          $ra
    // 0x80446A4C: nop

    return;
    // 0x80446A4C: nop

;}
RECOMP_FUNC void func_80424C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424C04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80424C08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80424C0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80424C10: jal         0x804249A0
    // 0x80424C14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804249A0(rdram, ctx);
        goto after_0;
    // 0x80424C14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80424C18: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424C1C: lui         $a1, 0x8042
    ctx->r5 = S32(RELOC_HI16(35, 0X3408) << 16);
    // 0x80424C20: lui         $a2, 0x8042
    ctx->r6 = S32(RELOC_HI16(35, 0X33C4) << 16);
    // 0x80424C24: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80424C28: lw          $a3, 0xE4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XE4);
    // 0x80424C2C: addiu       $a2, $a2, 0x5DC4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(35, 0X33C4));
    // 0x80424C30: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80424C34: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80424C38: addiu       $a1, $a1, 0x5E08
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(35, 0X3408));
    // 0x80424C3C: jal         0x80424824
    // 0x80424C40: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    func_80424824(rdram, ctx);
        goto after_1;
    // 0x80424C40: addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    after_1:
    // 0x80424C44: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424C48: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36E0) << 16);
    // 0x80424C4C: lwc1        $f6, 0x60E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(35, 0X36E0));
    // 0x80424C50: lwc1        $f4, 0xE4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x80424C54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80424C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80424C5C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80424C60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80424C64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80424C68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80424C6C: swc1        $f8, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f8.u32l;
    // 0x80424C70: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424C74: lwc1        $f10, 0xE4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x80424C78: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80424C7C: nop

    // 0x80424C80: bc1fl       L_80424C94
    if (!c1cs) {
        // 0x80424C84: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80424C94;
    }
    goto skip_0;
    // 0x80424C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80424C88: jal         0x80424E54
    // 0x80424C8C: swc1        $f0, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f0.u32l;
    func_80424E54(rdram, ctx);
        goto after_2;
    // 0x80424C8C: swc1        $f0, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = ctx->f0.u32l;
    after_2:
    // 0x80424C90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80424C94:
    // 0x80424C94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80424C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80424C9C: jr          $ra
    // 0x80424CA0: nop

    return;
    // 0x80424CA0: nop

;}
RECOMP_FUNC void func_8040EC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EC38: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8040EC3C: lwc1        $f6, 0xDC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x8040EC40: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8040EC44: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8040EC48: nop

    // 0x8040EC4C: bc1t        L_8040EC64
    if (c1cs) {
        // 0x8040EC50: nop
    
            goto L_8040EC64;
    }
    // 0x8040EC50: nop

    // 0x8040EC54: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8040EC58: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8040EC5C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8040EC60: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_8040EC64:
    // 0x8040EC64: jr          $ra
    // 0x8040EC68: nop

    return;
    // 0x8040EC68: nop

;}
RECOMP_FUNC void func_8004625C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004625C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046264: jal         0x800461F4
    // 0x80046268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800461F4(rdram, ctx);
        goto after_0;
    // 0x80046268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8004626C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046270: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046274: jr          $ra
    // 0x80046278: nop

    return;
    // 0x80046278: nop

;}
RECOMP_FUNC void func_8052FAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052FAAC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052FAB0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8052FAB4: lw          $t6, 0x1160($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1160);
    // 0x8052FAB8: blezl       $t6, L_8052FAEC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8052FABC: sw          $zero, 0xF64($v0)
        MEM_W(0XF64, ctx->r2) = 0;
            goto L_8052FAEC;
    }
    goto skip_0;
    // 0x8052FABC: sw          $zero, 0xF64($v0)
    MEM_W(0XF64, ctx->r2) = 0;
    skip_0:
    // 0x8052FAC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8052FAC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8052FAC8: swc1        $f0, 0xF6C($a1)
    MEM_W(0XF6C, ctx->r5) = ctx->f0.u32l;
L_8052FACC:
    // 0x8052FACC: swc1        $f0, 0x105C($a1)
    MEM_W(0X105C, ctx->r5) = ctx->f0.u32l;
    // 0x8052FAD0: lw          $t7, 0x1160($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1160);
    // 0x8052FAD4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8052FAD8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8052FADC: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8052FAE0: bnel        $at, $zero, L_8052FACC
    if (ctx->r1 != 0) {
        // 0x8052FAE4: swc1        $f0, 0xF6C($a1)
        MEM_W(0XF6C, ctx->r5) = ctx->f0.u32l;
            goto L_8052FACC;
    }
    goto skip_1;
    // 0x8052FAE4: swc1        $f0, 0xF6C($a1)
    MEM_W(0XF6C, ctx->r5) = ctx->f0.u32l;
    skip_1:
    // 0x8052FAE8: sw          $zero, 0xF64($v0)
    MEM_W(0XF64, ctx->r2) = 0;
L_8052FAEC:
    // 0x8052FAEC: sw          $zero, 0xF60($v0)
    MEM_W(0XF60, ctx->r2) = 0;
    // 0x8052FAF0: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8052FAF4: swc1        $f4, 0x114C($v0)
    MEM_W(0X114C, ctx->r2) = ctx->f4.u32l;
    // 0x8052FAF8: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8052FAFC: jr          $ra
    // 0x8052FB00: swc1        $f6, 0x1150($v0)
    MEM_W(0X1150, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8052FB00: swc1        $f6, 0x1150($v0)
    MEM_W(0X1150, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80563990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80563990: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80563994: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80563998: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8056399C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x805639A0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x805639A4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x805639A8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x805639AC: lw          $t0, 0x1F4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1F4);
    // 0x805639B0: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x805639B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805639B8: lw          $t7, 0x2E8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X2E8);
    // 0x805639BC: lui         $v0, 0x8056
    ctx->r2 = S32(RELOC_HI16(369, 0X2488) << 16);
    // 0x805639C0: lui         $v1, 0x8056
    ctx->r3 = S32(RELOC_HI16(369, 0X2478) << 16);
    // 0x805639C4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x805639C8: lw          $t6, 0x16C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X16C);
    // 0x805639CC: sllv        $t5, $t9, $t7
    ctx->r13 = S32(ctx->r25 << (ctx->r15 & 31));
    // 0x805639D0: sllv        $t1, $t8, $t7
    ctx->r9 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x805639D4: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x805639D8: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x805639DC: addiu       $t8, $t6, 0xD
    ctx->r24 = ADD32(ctx->r14, 0XD);
    // 0x805639E0: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x805639E4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x805639E8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805639EC: addu        $s2, $t0, $t9
    ctx->r18 = ADD32(ctx->r8, ctx->r25);
    // 0x805639F0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x805639F4: lbu         $a2, 0x0($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X0);
    // 0x805639F8: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x805639FC: addiu       $v1, $v1, 0x5CD8
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(369, 0X2478));
    // 0x80563A00: addiu       $v0, $v0, 0x5CE8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(369, 0X2488));
    // 0x80563A04: sb          $a2, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r6;
    // 0x80563A08: sb          $a2, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r6;
    // 0x80563A0C: lbu         $a2, 0x1($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X1);
    // 0x80563A10: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80563A14: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80563A18: sb          $a2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r6;
    // 0x80563A1C: sb          $a2, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r6;
    // 0x80563A20: lbu         $a2, 0x2($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X2);
    // 0x80563A24: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80563A28: addiu       $t2, $t0, 0x4E0
    ctx->r10 = ADD32(ctx->r8, 0X4E0);
    // 0x80563A2C: sb          $a2, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r6;
    // 0x80563A30: sb          $a2, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r6;
    // 0x80563A34: lbu         $a2, 0x3($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X3);
    // 0x80563A38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80563A3C: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80563A40: sb          $a2, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r6;
    // 0x80563A44: sb          $a2, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r6;
    // 0x80563A48: lw          $a1, -0x260C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X260C);
    // 0x80563A4C: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x80563A50: andi        $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 & 0XFF;
    // 0x80563A54: lw          $t0, 0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XC);
    // 0x80563A58: addiu       $s3, $s2, 0x174
    ctx->r19 = ADD32(ctx->r18, 0X174);
    // 0x80563A5C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80563A60: addiu       $t0, $t0, -0x3E0
    ctx->r8 = ADD32(ctx->r8, -0X3E0);
    // 0x80563A64: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
    // 0x80563A68: addiu       $s5, $t0, 0x10
    ctx->r21 = ADD32(ctx->r8, 0X10);
    // 0x80563A6C: sw          $t0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r8;
L_80563A70:
    // 0x80563A70: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80563A74: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80563A78: sltiu       $at, $s1, 0x7C
    ctx->r1 = ctx->r17 < 0X7C ? 1 : 0;
    // 0x80563A7C: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x80563A80: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80563A84: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80563A88: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80563A8C: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x80563A90: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80563A94: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x80563A98: addiu       $s5, $s5, 0x20
    ctx->r21 = ADD32(ctx->r21, 0X20);
    // 0x80563A9C: sw          $t9, -0x18($s4)
    MEM_W(-0X18, ctx->r20) = ctx->r25;
    // 0x80563AA0: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x80563AA4: sw          $t7, -0x14($s4)
    MEM_W(-0X14, ctx->r20) = ctx->r15;
    // 0x80563AA8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80563AAC: sw          $t8, -0x20($s5)
    MEM_W(-0X20, ctx->r21) = ctx->r24;
    // 0x80563AB0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80563AB4: sw          $t6, -0x1C($s5)
    MEM_W(-0X1C, ctx->r21) = ctx->r14;
    // 0x80563AB8: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80563ABC: sw          $t8, -0x18($s5)
    MEM_W(-0X18, ctx->r21) = ctx->r24;
    // 0x80563AC0: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80563AC4: sw          $t6, -0x14($s5)
    MEM_W(-0X14, ctx->r21) = ctx->r14;
    // 0x80563AC8: lh          $t7, -0x4($s2)
    ctx->r15 = MEM_H(ctx->r18, -0X4);
    // 0x80563ACC: sh          $t7, -0x20($s4)
    MEM_H(-0X20, ctx->r20) = ctx->r15;
    // 0x80563AD0: lh          $t9, -0x4($s3)
    ctx->r25 = MEM_H(ctx->r19, -0X4);
    // 0x80563AD4: sh          $t9, -0x1E($s4)
    MEM_H(-0X1E, ctx->r20) = ctx->r25;
    // 0x80563AD8: lh          $t6, -0x2($s2)
    ctx->r14 = MEM_H(ctx->r18, -0X2);
    // 0x80563ADC: sh          $t6, -0x10($s4)
    MEM_H(-0X10, ctx->r20) = ctx->r14;
    // 0x80563AE0: lh          $t8, -0x2($s3)
    ctx->r24 = MEM_H(ctx->r19, -0X2);
    // 0x80563AE4: bne         $at, $zero, L_80563A70
    if (ctx->r1 != 0) {
        // 0x80563AE8: sh          $t8, -0xE($s4)
        MEM_H(-0XE, ctx->r20) = ctx->r24;
            goto L_80563A70;
    }
    // 0x80563AE8: sh          $t8, -0xE($s4)
    MEM_H(-0XE, ctx->r20) = ctx->r24;
    // 0x80563AEC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563AF0: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x80563AF4: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(369, 0X2450) << 16);
    // 0x80563AF8: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80563AFC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80563B00: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80563B04: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80563B08: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563B0C: addiu       $t8, $t8, 0x5CB0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(369, 0X2450));
    // 0x80563B10: lui         $t6, 0xFD90
    ctx->r14 = S32(0XFD90 << 16);
    // 0x80563B14: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x80563B18: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80563B1C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80563B20: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80563B24: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563B28: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80563B2C: ori         $t6, $t6, 0x150
    ctx->r14 = ctx->r14 | 0X150;
    // 0x80563B30: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80563B34: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80563B38: lui         $t9, 0xF590
    ctx->r25 = S32(0XF590 << 16);
    // 0x80563B3C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80563B40: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80563B44: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563B48: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80563B4C: ori         $t6, $t6, 0xF200
    ctx->r14 = ctx->r14 | 0XF200;
    // 0x80563B50: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80563B54: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80563B58: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80563B5C: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80563B60: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563B64: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80563B68: lui         $s2, 0x404
    ctx->r18 = S32(0X404 << 16);
    // 0x80563B6C: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80563B70: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80563B74: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80563B78: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80563B7C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563B80: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80563B84: lui         $t6, 0xF588
    ctx->r14 = S32(0XF588 << 16);
    // 0x80563B88: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80563B8C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80563B90: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80563B94: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80563B98: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563B9C: addiu       $t8, $zero, 0x150
    ctx->r24 = ADD32(0, 0X150);
    // 0x80563BA0: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x80563BA4: addiu       $t9, $a1, 0x8
    ctx->r25 = ADD32(ctx->r5, 0X8);
    // 0x80563BA8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80563BAC: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80563BB0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80563BB4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563BB8: lui         $t6, 0x7
    ctx->r14 = S32(0X7 << 16);
    // 0x80563BBC: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x80563BC0: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80563BC4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80563BC8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80563BCC: lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
    // 0x80563BD0: ori         $s1, $s1, 0x81F
    ctx->r17 = ctx->r17 | 0X81F;
    // 0x80563BD4: ori         $s2, $s2, 0x81F
    ctx->r18 = ctx->r18 | 0X81F;
    // 0x80563BD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80563BDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80563BE0: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80563BE4: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80563BE8: addiu       $s5, $zero, 0x604
    ctx->r21 = ADD32(0, 0X604);
    // 0x80563BEC: addiu       $s4, $zero, 0x206
    ctx->r20 = ADD32(0, 0X206);
    // 0x80563BF0: lui         $s3, 0xBF00
    ctx->r19 = S32(0XBF00 << 16);
    // 0x80563BF4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80563BF8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80563BFC: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
L_80563C00:
    // 0x80563C00: and         $t7, $t8, $a2
    ctx->r15 = ctx->r24 & ctx->r6;
    // 0x80563C04: beql        $t7, $zero, L_80563C38
    if (ctx->r15 == 0) {
        // 0x80563C08: lw          $a1, 0x0($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X0);
            goto L_80563C38;
    }
    goto skip_0;
    // 0x80563C08: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80563C0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80563C10:
    // 0x80563C10: sltiu       $at, $v0, 0x1E
    ctx->r1 = ctx->r2 < 0X1E ? 1 : 0;
    // 0x80563C14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80563C18: beq         $at, $zero, L_80563CE4
    if (ctx->r1 == 0) {
        // 0x80563C1C: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80563CE4;
    }
    // 0x80563C1C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80563C20: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x80563C24: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x80563C28: and         $t8, $t6, $a2
    ctx->r24 = ctx->r14 & ctx->r6;
    // 0x80563C2C: bnel        $t8, $zero, L_80563C10
    if (ctx->r24 != 0) {
        // 0x80563C30: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80563C10;
    }
    goto skip_1;
    // 0x80563C30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x80563C34: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
L_80563C38:
    // 0x80563C38: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x80563C3C: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x80563C40: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80563C44: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80563C48: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x80563C4C: sw          $s1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r17;
    // 0x80563C50: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x80563C54: addiu       $t5, $t5, 0x20
    ctx->r13 = ADD32(ctx->r13, 0X20);
    // 0x80563C58: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80563C5C: and         $t6, $t3, $a2
    ctx->r14 = ctx->r11 & ctx->r6;
    // 0x80563C60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80563C64: bne         $t6, $zero, L_80563CD8
    if (ctx->r14 != 0) {
        // 0x80563C68: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80563CD8;
    }
    // 0x80563C68: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80563C6C: and         $t8, $t3, $t1
    ctx->r24 = ctx->r11 & ctx->r9;
    // 0x80563C70: bne         $t8, $zero, L_80563C9C
    if (ctx->r24 != 0) {
        // 0x80563C74: or          $t2, $t1, $zero
        ctx->r10 = ctx->r9 | 0;
            goto L_80563C9C;
    }
    // 0x80563C74: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x80563C78: addu        $a1, $a3, $v0
    ctx->r5 = ADD32(ctx->r7, ctx->r2);
L_80563C7C:
    // 0x80563C7C: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x80563C80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80563C84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80563C88: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x80563C8C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80563C90: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80563C94: beq         $t9, $zero, L_80563C7C
    if (ctx->r25 == 0) {
        // 0x80563C98: addiu       $t5, $t5, 0x20
        ctx->r13 = ADD32(ctx->r13, 0X20);
            goto L_80563C7C;
    }
    // 0x80563C98: addiu       $t5, $t5, 0x20
    ctx->r13 = ADD32(ctx->r13, 0X20);
L_80563C9C:
    // 0x80563C9C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563CA0: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80563CA4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80563CA8: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x80563CAC: sw          $s2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r18;
    // 0x80563CB0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563CB4: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80563CB8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80563CBC: sw          $s4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r20;
    // 0x80563CC0: sw          $s3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r19;
    // 0x80563CC4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80563CC8: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80563CCC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80563CD0: sw          $s5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r21;
    // 0x80563CD4: sw          $s3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r19;
L_80563CD8:
    // 0x80563CD8: sltiu       $at, $v0, 0x1E
    ctx->r1 = ctx->r2 < 0X1E ? 1 : 0;
    // 0x80563CDC: bnel        $at, $zero, L_80563C00
    if (ctx->r1 != 0) {
        // 0x80563CE0: lbu         $t8, 0x0($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X0);
            goto L_80563C00;
    }
    goto skip_2;
    // 0x80563CE0: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    skip_2:
L_80563CE4:
    // 0x80563CE4: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80563CE8: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80563CEC: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80563CF0: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80563CF4: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80563CF8: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80563CFC: jr          $ra
    // 0x80563D00: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80563D00: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80447B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447B88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447B8C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80447B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447B94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447B98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447B9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80447BA0: bne         $a2, $zero, L_80447C10
    if (ctx->r6 != 0) {
        // 0x80447BA4: lw          $v1, 0x1F4($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X1F4);
            goto L_80447C10;
    }
    // 0x80447BA4: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x80447BA8: lui         $v0, 0x8045
    ctx->r2 = S32(RELOC_HI16(98, 0X13240) << 16);
    // 0x80447BAC: lw          $v0, 0x7620($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(98, 0X13240));
    // 0x80447BB0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80447BB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80447BB8: beq         $v0, $zero, L_80447BD8
    if (ctx->r2 == 0) {
        // 0x80447BBC: nop
    
            goto L_80447BD8;
    }
    // 0x80447BBC: nop

    // 0x80447BC0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80447BC4: jalr        $v0
    // 0x80447BC8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80447BC8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80447BCC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80447BD0: b           L_80447BD8
    // 0x80447BD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80447BD8;
    // 0x80447BD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80447BD8:
    // 0x80447BD8: bne         $a0, $zero, L_80447BE8
    if (ctx->r4 != 0) {
        // 0x80447BDC: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_80447BE8;
    }
    // 0x80447BDC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80447BE0: b           L_80447C54
    // 0x80447BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80447C54;
    // 0x80447BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80447BE8:
    // 0x80447BE8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x80447BEC: lw          $v0, 0xFC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XFC);
    // 0x80447BF0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80447BF4: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80447BF8: bne         $at, $zero, L_80447C50
    if (ctx->r1 != 0) {
        // 0x80447BFC: sw          $t9, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r25;
            goto L_80447C50;
    }
    // 0x80447BFC: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x80447C00: jal         0x804462C0
    // 0x80447C04: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_804462C0(rdram, ctx);
        goto after_1;
    // 0x80447C04: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80447C08: b           L_80447C54
    // 0x80447C0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80447C54;
    // 0x80447C0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80447C10:
    // 0x80447C10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447C14: bne         $a2, $at, L_80447C3C
    if (ctx->r6 != ctx->r1) {
        // 0x80447C18: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80447C3C;
    }
    // 0x80447C18: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447C1C: jal         0x8044625C
    // 0x80447C20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8044625C(rdram, ctx);
        goto after_2;
    // 0x80447C20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80447C24: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80447C28: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447C2C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80447C30: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80447C34: b           L_80447C50
    // 0x80447C38: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
        goto L_80447C50;
    // 0x80447C38: sw          $t1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r9;
L_80447C3C:
    // 0x80447C3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80447C40: bnel        $a2, $at, L_80447C54
    if (ctx->r6 != ctx->r1) {
        // 0x80447C44: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80447C54;
    }
    goto skip_0;
    // 0x80447C44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80447C48: jal         0x804462C0
    // 0x80447C4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_804462C0(rdram, ctx);
        goto after_3;
    // 0x80447C4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
L_80447C50:
    // 0x80447C50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80447C54:
    // 0x80447C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80447C58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447C5C: jr          $ra
    // 0x80447C60: nop

    return;
    // 0x80447C60: nop

;}
RECOMP_FUNC void func_8056512C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056512C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80565130: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80565134: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80565138: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8056513C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80565140: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80565144: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80565148: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8056514C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80565150: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80565154: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80565158: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8056515C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80565160: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80565164: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x80565168: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    // 0x8056516C: lhu         $t8, 0xC2($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XC2);
    // 0x80565170: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80565174: lw          $t6, 0x2EC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X2EC);
    // 0x80565178: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x8056517C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80565180: sllv        $fp, $t7, $t6
    ctx->r30 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80565184: beq         $t8, $zero, L_805651B0
    if (ctx->r24 == 0) {
        // 0x80565188: andi        $fp, $fp, 0xFF
        ctx->r30 = ctx->r30 & 0XFF;
            goto L_805651B0;
    }
    // 0x80565188: andi        $fp, $fp, 0xFF
    ctx->r30 = ctx->r30 & 0XFF;
    // 0x8056518C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80565190: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80565194: lwc1        $f6, 0x504($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X504);
    // 0x80565198: lwc1        $f10, 0x508($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X508);
    // 0x8056519C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805651A0: add.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x805651A4: mul.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x805651A8: b           L_805651D8
    // 0x805651AC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
        goto L_805651D8;
    // 0x805651AC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
L_805651B0:
    // 0x805651B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805651B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805651B8: lwc1        $f6, 0x504($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X504);
    // 0x805651BC: lwc1        $f18, 0x508($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X508);
    // 0x805651C0: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805651C4: add.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x805651C8: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x805651CC: mul.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x805651D0: nop

    // 0x805651D4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
L_805651D8:
    // 0x805651D8: mfc1        $s4, $f6
    ctx->r20 = (int32_t)ctx->f6.u32l;
    // 0x805651DC: nop

    // 0x805651E0: bltz        $s4, L_805654DC
    if (SIGNED(ctx->r20) < 0) {
        // 0x805651E4: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_805654DC;
    }
    // 0x805651E4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x805651E8: slti        $at, $s4, 0x1F
    ctx->r1 = SIGNED(ctx->r20) < 0X1F ? 1 : 0;
    // 0x805651EC: beq         $at, $zero, L_805654DC
    if (ctx->r1 == 0) {
        // 0x805651F0: sll         $t0, $s4, 2
        ctx->r8 = S32(ctx->r20 << 2);
            goto L_805654DC;
    }
    // 0x805651F0: sll         $t0, $s4, 2
    ctx->r8 = S32(ctx->r20 << 2);
    // 0x805651F4: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x805651F8: lwc1        $f18, 0x3E8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X3E8);
    // 0x805651FC: addiu       $t1, $s4, 0x6
    ctx->r9 = ADD32(ctx->r20, 0X6);
    // 0x80565200: addiu       $s0, $s4, -0x4
    ctx->r16 = ADD32(ctx->r20, -0X4);
    // 0x80565204: c.lt.s      $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f18.fl < ctx->f22.fl;
    // 0x80565208: addiu       $t2, $s4, 0x6
    ctx->r10 = ADD32(ctx->r20, 0X6);
    // 0x8056520C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80565210: bc1fl       L_80565374
    if (!c1cs) {
        // 0x80565214: mtc1        $zero, $f20
        ctx->f20.u32l = 0;
            goto L_80565374;
    }
    goto skip_0;
    // 0x80565214: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    skip_0:
    // 0x80565218: addiu       $s0, $s4, -0x4
    ctx->r16 = ADD32(ctx->r20, -0X4);
    // 0x8056521C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80565220: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80565224: beq         $at, $zero, L_80565354
    if (ctx->r1 == 0) {
        // 0x80565228: addiu       $s6, $v1, 0x6
        ctx->r22 = ADD32(ctx->r3, 0X6);
            goto L_80565354;
    }
    // 0x80565228: addiu       $s6, $v1, 0x6
    ctx->r22 = ADD32(ctx->r3, 0X6);
    // 0x8056522C: lui         $s7, 0x8056
    ctx->r23 = S32(RELOC_HI16(369, 0X243C) << 16);
    // 0x80565230: addiu       $s7, $s7, 0x5C9C
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(369, 0X243C));
    // 0x80565234: lwc1        $f24, 0xB8($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80565238: addiu       $s5, $sp, 0x78
    ctx->r21 = ADD32(ctx->r29, 0X78);
    // 0x8056523C: slti        $at, $s0, 0x1F
    ctx->r1 = SIGNED(ctx->r16) < 0X1F ? 1 : 0;
L_80565240:
    // 0x80565240: beql        $at, $zero, L_8056534C
    if (ctx->r1 == 0) {
        // 0x80565244: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8056534C;
    }
    goto skip_1;
    // 0x80565244: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80565248: bltz        $s0, L_80565348
    if (SIGNED(ctx->r16) < 0) {
        // 0x8056524C: sll         $t3, $s0, 2
        ctx->r11 = S32(ctx->r16 << 2);
            goto L_80565348;
    }
    // 0x8056524C: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80565250: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80565254: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80565258: slt         $at, $s4, $s0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8056525C: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    // 0x80565260: addu        $s1, $s3, $t5
    ctx->r17 = ADD32(ctx->r19, ctx->r13);
    // 0x80565264: addu        $s2, $s3, $t3
    ctx->r18 = ADD32(ctx->r19, ctx->r11);
    // 0x80565268: beq         $at, $zero, L_8056527C
    if (ctx->r1 == 0) {
        // 0x8056526C: sub.s       $f16, $f24, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f8.fl;
            goto L_8056527C;
    }
    // 0x8056526C: sub.s       $f16, $f24, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x80565270: subu        $v0, $s0, $s4
    ctx->r2 = SUB32(ctx->r16, ctx->r20);
    // 0x80565274: b           L_80565280
    // 0x80565278: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80565280;
    // 0x80565278: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8056527C:
    // 0x8056527C: subu        $v0, $s4, $s0
    ctx->r2 = SUB32(ctx->r20, ctx->r16);
L_80565280:
    // 0x80565280: lwc1        $f12, 0x2F0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X2F0);
    // 0x80565284: lwc1        $f4, 0x3E8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X3E8);
    // 0x80565288: addu        $t7, $s3, $s0
    ctx->r15 = ADD32(ctx->r19, ctx->r16);
    // 0x8056528C: add.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80565290: add.s       $f0, $f16, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80565294: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80565298: sub.s       $f14, $f0, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8056529C: bc1fl       L_8056534C
    if (!c1cs) {
        // 0x805652A0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8056534C;
    }
    goto skip_2;
    // 0x805652A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x805652A4: lbu         $t6, 0x4E0($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X4E0);
    // 0x805652A8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x805652AC: addu        $t0, $s7, $t9
    ctx->r8 = ADD32(ctx->r23, ctx->r25);
    // 0x805652B0: and         $t8, $t6, $fp
    ctx->r24 = ctx->r14 & ctx->r30;
    // 0x805652B4: bnel        $t8, $zero, L_8056534C
    if (ctx->r24 != 0) {
        // 0x805652B8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8056534C;
    }
    goto skip_3;
    // 0x805652B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x805652BC: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x805652C0: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x805652C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805652C8: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x805652CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805652D0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x805652D4: sub.s       $f18, $f12, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x805652D8: bne         $at, $zero, L_805652EC
    if (ctx->r1 != 0) {
        // 0x805652DC: swc1        $f18, 0x2F0($s1)
        MEM_W(0X2F0, ctx->r17) = ctx->f18.u32l;
            goto L_805652EC;
    }
    // 0x805652DC: swc1        $f18, 0x2F0($s1)
    MEM_W(0X2F0, ctx->r17) = ctx->f18.u32l;
    // 0x805652E0: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
    // 0x805652E4: bnel        $at, $zero, L_80565300
    if (ctx->r1 != 0) {
        // 0x805652E8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80565300;
    }
    goto skip_4;
    // 0x805652E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_4:
L_805652EC:
    // 0x805652EC: jal         0x80565074
    // 0x805652F0: lw          $a2, 0x2F0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2F0);
    func_80565074(rdram, ctx);
        goto after_0;
    // 0x805652F0: lw          $a2, 0x2F0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2F0);
    after_0:
    // 0x805652F4: b           L_80565314
    // 0x805652F8: lwc1        $f8, 0x3E8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X3E8);
        goto L_80565314;
    // 0x805652F8: lwc1        $f8, 0x3E8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X3E8);
    // 0x805652FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80565300:
    // 0x80565300: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80565304: lw          $a2, 0x2F0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2F0);
    // 0x80565308: jal         0x80564F88
    // 0x8056530C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_80564F88(rdram, ctx);
        goto after_1;
    // 0x8056530C: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_1:
    // 0x80565310: lwc1        $f8, 0x3E8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X3E8);
L_80565314:
    // 0x80565314: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80565318: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8056531C: swc1        $f10, 0x3E8($s2)
    MEM_W(0X3E8, ctx->r18) = ctx->f10.u32l;
    // 0x80565320: lwc1        $f6, 0x2F0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2F0);
    // 0x80565324: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80565328: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8056532C: swc1        $f8, 0x2F0($s1)
    MEM_W(0X2F0, ctx->r17) = ctx->f8.u32l;
    // 0x80565330: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80565334: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x80565338: nop

    // 0x8056533C: bc1fl       L_8056534C
    if (!c1cs) {
        // 0x80565340: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8056534C;
    }
    goto skip_5;
    // 0x80565340: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_5:
    // 0x80565344: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
L_80565348:
    // 0x80565348: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8056534C:
    // 0x8056534C: bnel        $s0, $s6, L_80565240
    if (ctx->r16 != ctx->r22) {
        // 0x80565350: slti        $at, $s0, 0x1F
        ctx->r1 = SIGNED(ctx->r16) < 0X1F ? 1 : 0;
            goto L_80565240;
    }
    goto skip_6;
    // 0x80565350: slti        $at, $s0, 0x1F
    ctx->r1 = SIGNED(ctx->r16) < 0X1F ? 1 : 0;
    skip_6:
L_80565354:
    // 0x80565354: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80565358: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8056535C: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80565360: jalr        $t9
    // 0x80565364: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80565364: nop

    after_2:
    // 0x80565368: b           L_805654E0
    // 0x8056536C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_805654E0;
    // 0x8056536C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80565370: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_80565374:
    // 0x80565374: beq         $at, $zero, L_805654C4
    if (ctx->r1 == 0) {
        // 0x80565378: addiu       $s6, $v1, 0x6
        ctx->r22 = ADD32(ctx->r3, 0X6);
            goto L_805654C4;
    }
    // 0x80565378: addiu       $s6, $v1, 0x6
    ctx->r22 = ADD32(ctx->r3, 0X6);
    // 0x8056537C: lui         $s7, 0x8056
    ctx->r23 = S32(RELOC_HI16(369, 0X243C) << 16);
    // 0x80565380: addiu       $s7, $s7, 0x5C9C
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(369, 0X243C));
    // 0x80565384: lwc1        $f24, 0xB8($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80565388: addiu       $s5, $sp, 0x78
    ctx->r21 = ADD32(ctx->r29, 0X78);
    // 0x8056538C: slti        $at, $s0, 0x1F
    ctx->r1 = SIGNED(ctx->r16) < 0X1F ? 1 : 0;
L_80565390:
    // 0x80565390: beql        $at, $zero, L_805654BC
    if (ctx->r1 == 0) {
        // 0x80565394: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_805654BC;
    }
    goto skip_7;
    // 0x80565394: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_7:
    // 0x80565398: bltz        $s0, L_805654B8
    if (SIGNED(ctx->r16) < 0) {
        // 0x8056539C: sll         $t2, $s0, 2
        ctx->r10 = S32(ctx->r16 << 2);
            goto L_805654B8;
    }
    // 0x8056539C: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x805653A0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805653A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805653A8: slt         $at, $s4, $s0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x805653AC: sll         $t4, $s0, 3
    ctx->r12 = S32(ctx->r16 << 3);
    // 0x805653B0: addu        $s1, $s3, $t4
    ctx->r17 = ADD32(ctx->r19, ctx->r12);
    // 0x805653B4: addu        $s2, $s3, $t2
    ctx->r18 = ADD32(ctx->r19, ctx->r10);
    // 0x805653B8: beq         $at, $zero, L_805653CC
    if (ctx->r1 == 0) {
        // 0x805653BC: sub.s       $f16, $f24, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f10.fl;
            goto L_805653CC;
    }
    // 0x805653BC: sub.s       $f16, $f24, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x805653C0: subu        $v0, $s0, $s4
    ctx->r2 = SUB32(ctx->r16, ctx->r20);
    // 0x805653C4: b           L_805653D0
    // 0x805653C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_805653D0;
    // 0x805653C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_805653CC:
    // 0x805653CC: subu        $v0, $s4, $s0
    ctx->r2 = SUB32(ctx->r20, ctx->r16);
L_805653D0:
    // 0x805653D0: lwc1        $f12, 0x2F4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X2F4);
    // 0x805653D4: lwc1        $f6, 0x3E8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X3E8);
    // 0x805653D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x805653DC: addu        $t5, $s3, $s0
    ctx->r13 = ADD32(ctx->r19, ctx->r16);
    // 0x805653E0: add.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x805653E4: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x805653E8: add.s       $f0, $f18, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x805653EC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x805653F0: nop

    // 0x805653F4: bc1fl       L_805654BC
    if (!c1cs) {
        // 0x805653F8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_805654BC;
    }
    goto skip_8;
    // 0x805653F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_8:
    // 0x805653FC: lbu         $t7, 0x4E0($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X4E0);
    // 0x80565400: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80565404: addu        $t0, $s7, $t8
    ctx->r8 = ADD32(ctx->r23, ctx->r24);
    // 0x80565408: and         $t6, $t7, $fp
    ctx->r14 = ctx->r15 & ctx->r30;
    // 0x8056540C: bnel        $t6, $zero, L_805654BC
    if (ctx->r14 != 0) {
        // 0x80565410: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_805654BC;
    }
    goto skip_9;
    // 0x80565410: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_9:
    // 0x80565414: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80565418: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8056541C: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80565420: add.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80565424: bne         $at, $zero, L_80565438
    if (ctx->r1 != 0) {
        // 0x80565428: swc1        $f6, 0x2F4($s1)
        MEM_W(0X2F4, ctx->r17) = ctx->f6.u32l;
            goto L_80565438;
    }
    // 0x80565428: swc1        $f6, 0x2F4($s1)
    MEM_W(0X2F4, ctx->r17) = ctx->f6.u32l;
    // 0x8056542C: slti        $at, $s0, 0x1C
    ctx->r1 = SIGNED(ctx->r16) < 0X1C ? 1 : 0;
    // 0x80565430: bnel        $at, $zero, L_80565464
    if (ctx->r1 != 0) {
        // 0x80565434: lwc1        $f4, 0x2F4($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X2F4);
            goto L_80565464;
    }
    goto skip_10;
    // 0x80565434: lwc1        $f4, 0x2F4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2F4);
    skip_10:
L_80565438:
    // 0x80565438: lwc1        $f18, 0x2F4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X2F4);
    // 0x8056543C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80565440: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80565444: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x80565448: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8056544C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80565450: jal         0x80565074
    // 0x80565454: nop

    func_80565074(rdram, ctx);
        goto after_3;
    // 0x80565454: nop

    after_3:
    // 0x80565458: b           L_80565484
    // 0x8056545C: lwc1        $f6, 0x3E8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X3E8);
        goto L_80565484;
    // 0x8056545C: lwc1        $f6, 0x3E8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X3E8);
    // 0x80565460: lwc1        $f4, 0x2F4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2F4);
L_80565464:
    // 0x80565464: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80565468: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8056546C: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x80565470: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80565474: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80565478: jal         0x80564F88
    // 0x8056547C: nop

    func_80564F88(rdram, ctx);
        goto after_4;
    // 0x8056547C: nop

    after_4:
    // 0x80565480: lwc1        $f6, 0x3E8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X3E8);
L_80565484:
    // 0x80565484: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80565488: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8056548C: swc1        $f8, 0x3E8($s2)
    MEM_W(0X3E8, ctx->r18) = ctx->f8.u32l;
    // 0x80565490: lwc1        $f4, 0x2F4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2F4);
    // 0x80565494: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80565498: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8056549C: swc1        $f6, 0x2F4($s1)
    MEM_W(0X2F4, ctx->r17) = ctx->f6.u32l;
    // 0x805654A0: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x805654A4: c.lt.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl < ctx->f18.fl;
    // 0x805654A8: nop

    // 0x805654AC: bc1fl       L_805654BC
    if (!c1cs) {
        // 0x805654B0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_805654BC;
    }
    goto skip_11;
    // 0x805654B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_11:
    // 0x805654B4: mov.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = ctx->f18.fl;
L_805654B8:
    // 0x805654B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_805654BC:
    // 0x805654BC: bnel        $s0, $s6, L_80565390
    if (ctx->r16 != ctx->r22) {
        // 0x805654C0: slti        $at, $s0, 0x1F
        ctx->r1 = SIGNED(ctx->r16) < 0X1F ? 1 : 0;
            goto L_80565390;
    }
    goto skip_12;
    // 0x805654C0: slti        $at, $s0, 0x1F
    ctx->r1 = SIGNED(ctx->r16) < 0X1F ? 1 : 0;
    skip_12:
L_805654C4:
    // 0x805654C4: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x805654C8: neg.s       $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = -ctx->f20.fl;
    // 0x805654CC: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x805654D0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x805654D4: jalr        $t9
    // 0x805654D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x805654D8: nop

    after_5:
L_805654DC:
    // 0x805654DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_805654E0:
    // 0x805654E0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805654E4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805654E8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x805654EC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x805654F0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x805654F4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x805654F8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x805654FC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80565500: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80565504: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80565508: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8056550C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80565510: jr          $ra
    // 0x80565514: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80565514: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_806D2664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D2664: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806D2668: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D266C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D2670: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D2674: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x806D2678: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D267C: lw          $t6, 0xC($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XC);
    // 0x806D2680: lw          $v1, 0x7F78($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7F78);
    // 0x806D2684: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806D2688: bne         $t6, $zero, L_806D271C
    if (ctx->r14 != 0) {
        // 0x806D268C: lw          $v0, 0x0($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X0);
            goto L_806D271C;
    }
    // 0x806D268C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x806D2690: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806D2694: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D2698: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x806D269C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x806D26A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806D26A4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806D26A8: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x806D26AC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806D26B0: nop

    // 0x806D26B4: bc1fl       L_806D27A8
    if (!c1cs) {
        // 0x806D26B8: swc1        $f2, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
            goto L_806D27A8;
    }
    goto skip_0;
    // 0x806D26B8: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    skip_0:
    // 0x806D26BC: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x806D26C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806D26C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806D26C8: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x806D26CC: sw          $t9, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r25;
    // 0x806D26D0: sw          $t9, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r25;
    // 0x806D26D4: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x806D26D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806D26DC: sw          $t1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r9;
    // 0x806D26E0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806D26E4: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X1738) << 16);
    // 0x806D26E8: bc1f        L_806D2714
    if (!c1cs) {
        // 0x806D26EC: nop
    
            goto L_806D2714;
    }
    // 0x806D26EC: nop

    // 0x806D26F0: lwc1        $f2, 0x2CF8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X1738));
    // 0x806D26F4: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x806D26F8: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    // 0x806D26FC: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x806D2700: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x806D2704: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x806D2708: lwc1        $f6, 0x70($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X70);
    // 0x806D270C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x806D2710: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
L_806D2714:
    // 0x806D2714: b           L_806D27A4
    // 0x806D2718: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_806D27A4;
    // 0x806D2718: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_806D271C:
    // 0x806D271C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806D2720: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806D2724: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x806D2728: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806D272C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x806D2730: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x806D2734: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806D2738: nop

    // 0x806D273C: bc1fl       L_806D27A8
    if (!c1cs) {
        // 0x806D2740: swc1        $f2, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
            goto L_806D27A8;
    }
    goto skip_1;
    // 0x806D2740: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    skip_1:
    // 0x806D2744: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x806D2748: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806D274C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806D2750: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x806D2754: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x806D2758: nop

    // 0x806D275C: bc1fl       L_806D27A8
    if (!c1cs) {
        // 0x806D2760: swc1        $f2, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
            goto L_806D27A8;
    }
    goto skip_2;
    // 0x806D2760: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    skip_2:
    // 0x806D2764: lw          $t2, 0x138($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X138);
    // 0x806D2768: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x806D276C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D2770: bne         $t2, $zero, L_806D27A4
    if (ctx->r10 != 0) {
        // 0x806D2774: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806D27A4;
    }
    // 0x806D2774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D2778: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x806D277C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x806D2780: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x806D2784: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x806D2788: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x806D278C: jal         0x806D2BCC
    // 0x806D2790: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_806D2BCC(rdram, ctx);
        goto after_0;
    // 0x806D2790: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x806D2794: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x806D2798: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x806D279C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x806D27A0: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
L_806D27A4:
    // 0x806D27A4: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
L_806D27A8:
    // 0x806D27A8: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
    // 0x806D27AC: bne         $t4, $zero, L_806D27FC
    if (ctx->r12 != 0) {
        // 0x806D27B0: swc1        $f2, 0x6C($v0)
        MEM_W(0X6C, ctx->r2) = ctx->f2.u32l;
            goto L_806D27FC;
    }
    // 0x806D27B0: swc1        $f2, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f2.u32l;
    // 0x806D27B4: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(610, 0X16AC) << 16);
    // 0x806D27B8: lui         $v1, 0x806D
    ctx->r3 = S32(RELOC_HI16(610, 0X16B4) << 16);
    // 0x806D27BC: addiu       $v1, $v1, 0x2C74
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(610, 0X16B4));
    // 0x806D27C0: addiu       $v0, $v0, 0x2C6C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(610, 0X16AC));
L_806D27C4:
    // 0x806D27C4: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x806D27C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x806D27CC: bne         $v0, $v1, L_806D27C4
    if (ctx->r2 != ctx->r3) {
        // 0x806D27D0: swc1        $f6, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
            goto L_806D27C4;
    }
    // 0x806D27D0: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x806D27D4: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x806D27D8: lw          $t5, -0x76F8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X76F8);
    // 0x806D27DC: lui         $a1, 0x806D
    ctx->r5 = S32(RELOC_HI16(610, 0X16AC) << 16);
    // 0x806D27E0: addiu       $a1, $a1, 0x2C6C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(610, 0X16AC));
    // 0x806D27E4: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x806D27E8: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x806D27EC: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806D27F0: lw          $t9, 0x18($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X18);
    // 0x806D27F4: jalr        $t9
    // 0x806D27F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x806D27F8: nop

    after_1:
L_806D27FC:
    // 0x806D27FC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x806D2800: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x806D2804: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x806D2808: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806D280C: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x806D2810: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x806D2814: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x806D2818: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806D281C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806D2820: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x806D2824: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x806D2828: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806D282C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x806D2830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D2834: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D2838: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806D283C: jr          $ra
    // 0x806D2840: nop

    return;
    // 0x806D2840: nop

;}
RECOMP_FUNC void func_80736468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736468: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8073646C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80736470: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80736474: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80736478: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8073647C: jal         0x80735DE4
    // 0x80736480: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80735DE4(rdram, ctx);
        goto after_0;
    // 0x80736480: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80736484: jal         0x80735E58
    // 0x80736488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80735E58(rdram, ctx);
        goto after_1;
    // 0x80736488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8073648C: jal         0x807360A0
    // 0x80736490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807360A0(rdram, ctx);
        goto after_2;
    // 0x80736490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80736494: bnel        $v0, $zero, L_80736540
    if (ctx->r2 != 0) {
        // 0x80736498: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80736540;
    }
    goto skip_0;
    // 0x80736498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8073649C: jal         0x807362A8
    // 0x807364A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807362A8(rdram, ctx);
        goto after_3;
    // 0x807364A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807364A4: jal         0x807362F4
    // 0x807364A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807362F4(rdram, ctx);
        goto after_4;
    // 0x807364A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807364AC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807364B0: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807364B4: lw          $t7, 0xA68($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XA68);
    // 0x807364B8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x807364BC: lw          $v0, 0x70($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X70);
    // 0x807364C0: beql        $v0, $zero, L_80736514
    if (ctx->r2 == 0) {
        // 0x807364C4: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_80736514;
    }
    goto skip_1;
    // 0x807364C4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x807364C8: lw          $t9, 0xD8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XD8);
    // 0x807364CC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x807364D0: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x807364D4: mfhi        $t0
    ctx->r8 = hi;
    // 0x807364D8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B30) << 16);
    // 0x807364DC: bnel        $t0, $zero, L_80736514
    if (ctx->r8 != 0) {
        // 0x807364E0: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_80736514;
    }
    goto skip_2;
    // 0x807364E0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x807364E4: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x807364E8: lwc1        $f6, -0x6A70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B30));
    // 0x807364EC: lwc1        $f12, 0x84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X84);
    // 0x807364F0: lwc1        $f14, 0x88($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X88);
    // 0x807364F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807364F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807364FC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80736500: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80736504: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80736508: jalr        $v0
    // 0x8073650C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x8073650C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x80736510: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_80736514:
    // 0x80736514: lw          $v0, 0xC($t2)
    ctx->r2 = MEM_W(ctx->r10, 0XC);
    // 0x80736518: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x8073651C: bne         $at, $zero, L_8073653C
    if (ctx->r1 != 0) {
        // 0x80736520: slti        $at, $v0, 0x10
        ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
            goto L_8073653C;
    }
    // 0x80736520: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80736524: beq         $at, $zero, L_8073653C
    if (ctx->r1 == 0) {
        // 0x80736528: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8073653C;
    }
    // 0x80736528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073652C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80736530: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80736534: jal         0x80736D18
    // 0x80736538: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_80736D18(rdram, ctx);
        goto after_6;
    // 0x80736538: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
L_8073653C:
    // 0x8073653C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80736540:
    // 0x80736540: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80736544: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80736548: jr          $ra
    // 0x8073654C: nop

    return;
    // 0x8073654C: nop

;}
RECOMP_FUNC void func_8064B164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B16C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064B170: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064B174: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064B178: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8064B17C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8064B180: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064B184: bne         $v0, $at, L_8064B1AC
    if (ctx->r2 != ctx->r1) {
        // 0x8064B188: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8064B1AC;
    }
    // 0x8064B188: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064B18C: jal         0x8064A1C8
    // 0x8064B190: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8064A1C8(rdram, ctx);
        goto after_0;
    // 0x8064B190: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x8064B194: beq         $v0, $zero, L_8064B1AC
    if (ctx->r2 == 0) {
        // 0x8064B198: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8064B1AC;
    }
    // 0x8064B198: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8064B19C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8064B1A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8064B1A4: jal         0x8002F6E4
    // 0x8064B1A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8064B1A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8064B1AC:
    // 0x8064B1AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064B1B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B1B4: jr          $ra
    // 0x8064B1B8: nop

    return;
    // 0x8064B1B8: nop

;}
RECOMP_FUNC void func_8064C0C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C0C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064C0C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064C0CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064C0D0: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064C0D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064C0D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C0DC: blez        $v0, L_8064C0F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064C0E0: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8064C0F0;
    }
    // 0x8064C0E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8064C0E4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064C0E8: b           L_8064C11C
    // 0x8064C0EC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064C11C;
    // 0x8064C0EC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064C0F0:
    // 0x8064C0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064C0F4: jal         0x8064C5D8
    // 0x8064C0F8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8064C5D8(rdram, ctx);
        goto after_0;
    // 0x8064C0F8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_0:
    // 0x8064C0FC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064C100: jal         0x80067BBC
    // 0x8064C104: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8064C104: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8064C108: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8064C10C: jal         0x80067818
    // 0x8064C110: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8064C110: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8064C114: jal         0x8064A43C
    // 0x8064C118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A43C(rdram, ctx);
        goto after_3;
    // 0x8064C118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8064C11C:
    // 0x8064C11C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064C120: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064C124: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064C128: jr          $ra
    // 0x8064C12C: nop

    return;
    // 0x8064C12C: nop

;}
RECOMP_FUNC void func_8003D61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D61C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003D620: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003D624: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003D628: jal         0x8004700C
    // 0x8003D62C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003D62C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8003D630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D634: jal         0x8003D4E4
    // 0x8003D638: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8003D4E4(rdram, ctx);
        goto after_1;
    // 0x8003D638: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8003D63C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003D640: addiu       $t6, $t6, -0x2BBC
    ctx->r14 = ADD32(ctx->r14, -0X2BBC);
    // 0x8003D644: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003D648: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x8003D64C: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
    // 0x8003D650: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003D654: lwc1        $f4, 0x21C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X21C);
    // 0x8003D658: sb          $zero, 0x30($s0)
    MEM_B(0X30, ctx->r16) = 0;
    // 0x8003D65C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D660: jal         0x8003CDF0
    // 0x8003D664: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    func_8003CDF0(rdram, ctx);
        goto after_2;
    // 0x8003D664: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8003D668: sb          $v0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r2;
    // 0x8003D66C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8003D670: lbu         $t8, -0x764C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X764C);
    // 0x8003D674: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003D678: bnel        $t8, $zero, L_8003D6CC
    if (ctx->r24 != 0) {
        // 0x8003D67C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003D6CC;
    }
    goto skip_0;
    // 0x8003D67C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8003D680: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x8003D684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D688: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8003D68C: sh          $v1, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r3;
    // 0x8003D690: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x8003D694: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8003D698: jal         0x8005FCA8
    // 0x8003D69C: sh          $v1, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r3;
    func_8005FCA8(rdram, ctx);
        goto after_3;
    // 0x8003D69C: sh          $v1, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r3;
    after_3:
    // 0x8003D6A0: lw          $t4, 0x174($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X174);
    // 0x8003D6A4: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8003D6A8: addiu       $t3, $t3, -0x3AF0
    ctx->r11 = ADD32(ctx->r11, -0X3AF0);
    // 0x8003D6AC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8003D6B0: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x8003D6B4: addiu       $t6, $t6, 0x5284
    ctx->r14 = ADD32(ctx->r14, 0X5284);
    // 0x8003D6B8: sw          $t3, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r11;
    // 0x8003D6BC: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x8003D6C0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8003D6C4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x8003D6C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D6CC:
    // 0x8003D6CC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003D6D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D6D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003D6D8: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x8003D6DC: jr          $ra
    // 0x8003D6E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003D6E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80471970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471970: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80471974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471978: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8047197C: jal         0x80062748
    // 0x80471980: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x80471980: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x80471984: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80471988: lw          $v0, 0x180($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X180);
    // 0x8047198C: beql        $v0, $zero, L_804719EC
    if (ctx->r2 == 0) {
        // 0x80471990: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804719EC;
    }
    goto skip_0;
    // 0x80471990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80471994: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80471998: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8047199C: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x804719A0: sw          $t6, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r14;
    // 0x804719A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804719A8: jal         0x80471934
    // 0x804719AC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80471934(rdram, ctx);
        goto after_1;
    // 0x804719AC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x804719B0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x804719B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804719B8: lw          $t7, 0x2C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X2C);
    // 0x804719BC: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // 0x804719C0: bnel        $t7, $zero, L_804719EC
    if (ctx->r15 != 0) {
        // 0x804719C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804719EC;
    }
    goto skip_1;
    // 0x804719C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804719C8: beql        $v0, $zero, L_804719EC
    if (ctx->r2 == 0) {
        // 0x804719CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804719EC;
    }
    goto skip_2;
    // 0x804719CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804719D0: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x804719D4: jal         0x80067BBC
    // 0x804719D8: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x804719D8: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_2:
    // 0x804719DC: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    // 0x804719E0: jal         0x80067818
    // 0x804719E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x804719E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x804719E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804719EC:
    // 0x804719EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804719F0: jr          $ra
    // 0x804719F4: nop

    return;
    // 0x804719F4: nop

;}
RECOMP_FUNC void func_80465424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80465428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046542C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80465430: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80465434: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(125, 0X1DD4) << 16);
    // 0x80465438: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8046543C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80465440: lw          $t8, 0x63A4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(125, 0X1DD4));
    // 0x80465444: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80465448: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8046544C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80465450: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80465454: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80465458: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8046545C: beql        $v1, $zero, L_80465490
    if (ctx->r3 == 0) {
        // 0x80465460: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80465490;
    }
    goto skip_0;
    // 0x80465460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80465464: jalr        $v1
    // 0x80465468: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80465468: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046546C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80465470: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80465474: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80465478: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8046547C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80465480: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80465484: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80465488: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8046548C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80465490:
    // 0x80465490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80465494: jr          $ra
    // 0x80465498: nop

    return;
    // 0x80465498: nop

;}
RECOMP_FUNC void func_807BBD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BBD18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BBD1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BBD20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807BBD24: jal         0x80047090
    // 0x807BBD28: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807BBD28: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_0:
    // 0x807BBD2C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807BBD30: beq         $v0, $at, L_807BBD98
    if (ctx->r2 == ctx->r1) {
        // 0x807BBD34: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807BBD98;
    }
    // 0x807BBD34: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807BBD38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807BBD3C: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x807BBD40: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807BBD44: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x807BBD48: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807BBD4C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807BBD50: ori         $a3, $a3, 0x7AE
    ctx->r7 = ctx->r7 | 0X7AE;
    // 0x807BBD54: jal         0x8004613C
    // 0x807BBD58: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807BBD58: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x807BBD5C: beq         $v0, $zero, L_807BBD98
    if (ctx->r2 == 0) {
        // 0x807BBD60: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807BBD98;
    }
    // 0x807BBD60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807BBD64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807BBD68: jal         0x80047F9C
    // 0x807BBD6C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807BBD6C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x807BBD70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807BBD74: lw          $t9, 0x20($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X20);
    // 0x807BBD78: jalr        $t9
    // 0x807BBD7C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x807BBD7C: nop

    after_3:
    // 0x807BBD80: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x807BBD84: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807BBD88: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
    // 0x807BBD8C: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x807BBD90: b           L_807BBD9C
    // 0x807BBD94: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
        goto L_807BBD9C;
    // 0x807BBD94: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
L_807BBD98:
    // 0x807BBD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807BBD9C:
    // 0x807BBD9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BBDA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807BBDA4: jr          $ra
    // 0x807BBDA8: nop

    return;
    // 0x807BBDA8: nop

;}
RECOMP_FUNC void func_80066A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A4C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80066A50: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80066A54: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80066A58: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80066A5C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80066A60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80066A64: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_80066A68:
    // 0x80066A68: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80066A6C: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80066A70: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80066A74: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80066A78: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80066A7C: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80066A80: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80066A84: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80066A88: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80066A8C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80066A90: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80066A94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066A98: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80066A9C: mul.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80066AA0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80066AA4: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80066AA8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80066AAC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80066AB0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80066AB4: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80066AB8: add.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80066ABC: bne         $v0, $t0, L_80066A68
    if (ctx->r2 != ctx->r8) {
        // 0x80066AC0: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_80066A68;
    }
    // 0x80066AC0: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80066AC4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80066AC8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80066ACC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80066AD0: jr          $ra
    // 0x80066AD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80066AD4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8066DDE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066DDE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8066DDE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066DDEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066DDF0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066DDF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8066DDF8: lw          $v0, 0x1C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1C);
    // 0x8066DDFC: beq         $v0, $zero, L_8066DE0C
    if (ctx->r2 == 0) {
        // 0x8066DE00: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8066DE0C;
    }
    // 0x8066DE00: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8066DE04: sw          $t6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r14;
    // 0x8066DE08: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8066DE0C:
    // 0x8066DE0C: bnel        $v0, $zero, L_8066DE7C
    if (ctx->r2 != 0) {
        // 0x8066DE10: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8066DE7C;
    }
    goto skip_0;
    // 0x8066DE10: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x8066DE14: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x8066DE18: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8066DE1C: bnel        $t7, $zero, L_8066DE4C
    if (ctx->r15 != 0) {
        // 0x8066DE20: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8066DE4C;
    }
    goto skip_1;
    // 0x8066DE20: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    skip_1:
    // 0x8066DE24: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8066DE28: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8066DE2C: jal         0x80067BBC
    // 0x8066DE30: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8066DE30: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x8066DE34: addiu       $a0, $zero, 0x23B
    ctx->r4 = ADD32(0, 0X23B);
    // 0x8066DE38: jal         0x80067818
    // 0x8066DE3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8066DE3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8066DE40: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8066DE44: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x8066DE48: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
L_8066DE4C:
    // 0x8066DE4C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8066DE50: lui         $t0, 0x8067
    ctx->r8 = S32(RELOC_HI16(517, 0X2890) << 16);
    // 0x8066DE54: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x8066DE58: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8066DE5C: lw          $t0, -0x1B0($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(517, 0X2890));
    // 0x8066DE60: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x8066DE64: slti        $at, $t1, 0xE
    ctx->r1 = SIGNED(ctx->r9) < 0XE ? 1 : 0;
    // 0x8066DE68: sw          $t1, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r9;
    // 0x8066DE6C: bne         $at, $zero, L_8066DE78
    if (ctx->r1 != 0) {
        // 0x8066DE70: sw          $t0, 0x28($v1)
        MEM_W(0X28, ctx->r3) = ctx->r8;
            goto L_8066DE78;
    }
    // 0x8066DE70: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
    // 0x8066DE74: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
L_8066DE78:
    // 0x8066DE78: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_8066DE7C:
    // 0x8066DE7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8066DE80: jal         0x80048F84
    // 0x8066DE84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8066DE84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8066DE88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8066DE8C: jal         0x80048F84
    // 0x8066DE90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x8066DE90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8066DE94: jal         0x8066DB84
    // 0x8066DE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066DB84(rdram, ctx);
        goto after_4;
    // 0x8066DE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8066DE9C: jal         0x8066D8D8
    // 0x8066DEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066D8D8(rdram, ctx);
        goto after_5;
    // 0x8066DEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8066DEA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8066DEA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066DEAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8066DEB0: jr          $ra
    // 0x8066DEB4: nop

    return;
    // 0x8066DEB4: nop

;}
RECOMP_FUNC void func_80465C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465C2C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80465C30: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x80465C34: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(125, 0X1C28) << 16);
    // 0x80465C38: lw          $t6, 0x1750($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1750);
    // 0x80465C3C: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80465C40: addiu       $t8, $t8, 0x61F8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(125, 0X1C28));
    // 0x80465C44: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80465C48: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80465C4C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80465C50: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80465C54: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80465C58: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80465C5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80465C60: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x80465C64: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80465C68: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80465C6C: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80465C70: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80465C74: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    // 0x80465C78: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x80465C7C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80465C80: addiu       $v1, $t0, 0x8
    ctx->r3 = ADD32(ctx->r8, 0X8);
    // 0x80465C84: jr          $ra
    // 0x80465C88: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    return;
    // 0x80465C88: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_800462E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800462E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800462E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800462E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800462EC: jal         0x800461F4
    // 0x800462F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800461F4(rdram, ctx);
        goto after_0;
    // 0x800462F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800462F4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800462F8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800462FC: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80046300: addiu       $a3, $a3, 0x62C0
    ctx->r7 = ADD32(ctx->r7, 0X62C0);
    // 0x80046304: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x80046308: addiu       $a0, $v0, 0x188
    ctx->r4 = ADD32(ctx->r2, 0X188);
    // 0x8004630C: jal         0x80057F74
    // 0x80046310: lh          $a1, 0x184($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X184);
    func_80057F74(rdram, ctx);
        goto after_1;
    // 0x80046310: lh          $a1, 0x184($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X184);
    after_1:
    // 0x80046314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004631C: jr          $ra
    // 0x80046320: nop

    return;
    // 0x80046320: nop

;}
RECOMP_FUNC void func_80050DB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050DBC: jal         0x80050CF0
    // 0x80050DC0: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    func_80050CF0(rdram, ctx);
        goto after_0;
    // 0x80050DC0: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    after_0:
    // 0x80050DC4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80050DC8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80050DCC: bne         $v0, $zero, L_80050DE0
    if (ctx->r2 != 0) {
        // 0x80050DD0: sw          $v0, 0x30($t7)
        MEM_W(0X30, ctx->r15) = ctx->r2;
            goto L_80050DE0;
    }
    // 0x80050DD0: sw          $v0, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r2;
    // 0x80050DD4: addiu       $a0, $a0, 0xA10
    ctx->r4 = ADD32(ctx->r4, 0XA10);
    // 0x80050DD8: jal         0x80071380
    // 0x80050DDC: addiu       $a1, $zero, 0x28C
    ctx->r5 = ADD32(0, 0X28C);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80050DDC: addiu       $a1, $zero, 0x28C
    ctx->r5 = ADD32(0, 0X28C);
    after_1:
L_80050DE0:
    // 0x80050DE0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80050DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050DE8: lw          $v0, 0x30($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X30);
    // 0x80050DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050DF0: jr          $ra
    // 0x80050DF4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x80050DF4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void func_80475D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475D94: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475D98: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475D9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475DA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475DA4: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26DE8) << 16);
    // 0x80475DA8: addiu       $a2, $a2, -0x4A58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26DE8));
    // 0x80475DAC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80475DB0: jal         0x80475B40
    // 0x80475DB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475B40(rdram, ctx);
        goto after_0;
    // 0x80475DB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475DB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475DBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475DC0: jr          $ra
    // 0x80475DC4: nop

    return;
    // 0x80475DC4: nop

;}
RECOMP_FUNC void func_805A1370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1370: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(411, 0X10) << 16);
    // 0x805A1374: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x805A1378: jr          $ra
    // 0x805A137C: addiu       $v0, $v0, 0x1380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(411, 0X10));
    return;
    // 0x805A137C: addiu       $v0, $v0, 0x1380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(411, 0X10));
;}
RECOMP_FUNC void func_80025634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002563C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80025640: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80025644: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80025648: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8002564C: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
    // 0x80025650: lw          $t7, 0x9C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C);
    // 0x80025654: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80025658: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x8002565C: sw          $v1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r3;
    // 0x80025660: lw          $t8, 0xA0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XA0);
    // 0x80025664: addiu       $t9, $t9, 0x55E4
    ctx->r25 = ADD32(ctx->r25, 0X55E4);
    // 0x80025668: sw          $v1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r3;
    // 0x8002566C: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
    // 0x80025670: jal         0x8001D770
    // 0x80025674: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x80025674: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80025678: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8002567C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80025680: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80025684: jal         0x80067BF8
    // 0x80025688: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x80025688: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_1:
    // 0x8002568C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x80025690: jal         0x80067818
    // 0x80025694: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80025694: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80025698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002569C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800256A0: jr          $ra
    // 0x800256A4: nop

    return;
    // 0x800256A4: nop

;}
RECOMP_FUNC void func_804B7F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B7F14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B7F18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B7F1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B7F20: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x804B7F24: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x804B7F28: beql        $a1, $at, L_804B7F60
    if (ctx->r5 == ctx->r1) {
        // 0x804B7F2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804B7F60;
    }
    goto skip_0;
    // 0x804B7F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804B7F30: jal         0x80067930
    // 0x804B7F34: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x804B7F34: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x804B7F38: bne         $v0, $zero, L_804B7F5C
    if (ctx->r2 != 0) {
        // 0x804B7F3C: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_804B7F5C;
    }
    // 0x804B7F3C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x804B7F40: jal         0x80067E78
    // 0x804B7F44: lw          $a0, 0x34($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X34);
    func_80067E78(rdram, ctx);
        goto after_1;
    // 0x804B7F44: lw          $a0, 0x34($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X34);
    after_1:
    // 0x804B7F48: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x804B7F4C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x804B7F50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x804B7F54: jal         0x80067838
    // 0x804B7F58: lh          $a1, 0x1F0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X1F0);
    func_80067838(rdram, ctx);
        goto after_2;
    // 0x804B7F58: lh          $a1, 0x1F0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X1F0);
    after_2:
L_804B7F5C:
    // 0x804B7F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804B7F60:
    // 0x804B7F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B7F64: jr          $ra
    // 0x804B7F68: nop

    return;
    // 0x804B7F68: nop

;}
RECOMP_FUNC void func_8006F560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F560: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8006F564: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x8006F568: addi        $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006F56C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006F570: add         $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x8006F574: add         $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
L_8006F578:
    // 0x8006F578: bnel        $a2, $zero, L_8006F594
    if (ctx->r6 != 0) {
        // 0x8006F57C: slt         $t1, $t0, $zero
        ctx->r9 = SIGNED(ctx->r8) < SIGNED(0) ? 1 : 0;
            goto L_8006F594;
    }
    goto skip_0;
    // 0x8006F57C: slt         $t1, $t0, $zero
    ctx->r9 = SIGNED(ctx->r8) < SIGNED(0) ? 1 : 0;
    skip_0:
    // 0x8006F580: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8006F584: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8006F588: addi        $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006F58C: sllv        $t0, $t0, $a2
    ctx->r8 = S32(ctx->r8 << (ctx->r6 & 31));
    // 0x8006F590: slt         $t1, $t0, $zero
    ctx->r9 = SIGNED(ctx->r8) < SIGNED(0) ? 1 : 0;
L_8006F594:
    // 0x8006F594: beql        $t1, $zero, L_8006F5B4
    if (ctx->r9 == 0) {
        // 0x8006F598: lhu         $t2, 0x0($a0)
        ctx->r10 = MEM_HU(ctx->r4, 0X0);
            goto L_8006F5B4;
    }
    goto skip_1;
    // 0x8006F598: lhu         $t2, 0x0($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X0);
    skip_1:
    // 0x8006F59C: lb          $t2, 0x0($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X0);
    // 0x8006F5A0: addi        $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x8006F5A4: addi        $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006F5A8: b           L_8006F5E0
    // 0x8006F5AC: sb          $t2, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r10;
        goto L_8006F5E0;
    // 0x8006F5AC: sb          $t2, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r10;
    // 0x8006F5B0: lhu         $t2, 0x0($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X0);
L_8006F5B4:
    // 0x8006F5B4: addi        $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006F5B8: srl         $t3, $t2, 12
    ctx->r11 = S32(U32(ctx->r10) >> 12);
    // 0x8006F5BC: andi        $t2, $t2, 0xFFF
    ctx->r10 = ctx->r10 & 0XFFF;
    // 0x8006F5C0: sub         $t1, $a1, $t2
    ctx->r9 = SUB32(ctx->r5, ctx->r10);
    // 0x8006F5C4: addi        $t3, $t3, 0x3
    ctx->r11 = ADD32(ctx->r11, 0X3);
L_8006F5C8:
    // 0x8006F5C8: lb          $t2, -0x1($t1)
    ctx->r10 = MEM_B(ctx->r9, -0X1);
    // 0x8006F5CC: addi        $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8006F5D0: addi        $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8006F5D4: addi        $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006F5D8: bne         $t3, $zero, L_8006F5C8
    if (ctx->r11 != 0) {
        // 0x8006F5DC: sb          $t2, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r10;
            goto L_8006F5C8;
    }
    // 0x8006F5DC: sb          $t2, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r10;
L_8006F5E0:
    // 0x8006F5E0: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8006F5E4: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8006F5E8: bne         $at, $zero, L_8006F578
    if (ctx->r1 != 0) {
        // 0x8006F5EC: addi        $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8006F578;
    }
    // 0x8006F5EC: addi        $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8006F5F0: jr          $ra
    // 0x8006F5F4: nop

    return;
    // 0x8006F5F4: nop

    // 0x8006F5F8: nop

    // 0x8006F5FC: nop

;}
RECOMP_FUNC void func_806D04C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D04C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D04C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D04C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D04CC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D04D0: jal         0x806D03E8
    // 0x806D04D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_806D03E8(rdram, ctx);
        goto after_0;
    // 0x806D04D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D04D8: jal         0x806D0408
    // 0x806D04DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806D0408(rdram, ctx);
        goto after_1;
    // 0x806D04DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806D04E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D04E4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x806D04E8: bnel        $a3, $zero, L_806D0528
    if (ctx->r7 != 0) {
        // 0x806D04EC: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_806D0528;
    }
    goto skip_0;
    // 0x806D04EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x806D04F0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806D04F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806D04F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D04FC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806D0500: nop

    // 0x806D0504: bc1fl       L_806D0558
    if (!c1cs) {
        // 0x806D0508: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D0558;
    }
    goto skip_1;
    // 0x806D0508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806D050C: jal         0x806D093C
    // 0x806D0510: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_806D093C(rdram, ctx);
        goto after_2;
    // 0x806D0510: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x806D0514: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1B10) << 16);
    // 0x806D0518: lwc1        $f8, 0x12B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1B10));
    // 0x806D051C: b           L_806D0554
    // 0x806D0520: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
        goto L_806D0554;
    // 0x806D0520: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x806D0524: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_806D0528:
    // 0x806D0528: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806D052C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0530: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806D0534: nop

    // 0x806D0538: bc1fl       L_806D0558
    if (!c1cs) {
        // 0x806D053C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D0558;
    }
    goto skip_2;
    // 0x806D053C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806D0540: jal         0x806D093C
    // 0x806D0544: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_806D093C(rdram, ctx);
        goto after_3;
    // 0x806D0544: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x806D0548: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1B14) << 16);
    // 0x806D054C: lwc1        $f18, 0x12B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1B14));
    // 0x806D0550: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
L_806D0554:
    // 0x806D0554: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D0558:
    // 0x806D0558: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D055C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D0560: jr          $ra
    // 0x806D0564: nop

    return;
    // 0x806D0564: nop

;}
RECOMP_FUNC void func_804A2080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A2080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A2084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A2088: jal         0x804A2910
    // 0x804A208C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A2910(rdram, ctx);
        goto after_0;
    // 0x804A208C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A2090: beq         $v0, $zero, L_804A20CC
    if (ctx->r2 == 0) {
        // 0x804A2094: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A20CC;
    }
    // 0x804A2094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A2098: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x804A209C: lui         $t8, 0x804A
    ctx->r24 = S32(RELOC_HI16(173, 0X307C) << 16);
    // 0x804A20A0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x804A20A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804A20A8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804A20AC: lw          $t8, 0x34BC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(173, 0X307C));
    // 0x804A20B0: andi        $t0, $t8, 0x6
    ctx->r8 = ctx->r24 & 0X6;
    // 0x804A20B4: beq         $t0, $zero, L_804A20C4
    if (ctx->r8 == 0) {
        // 0x804A20B8: sw          $t8, 0x138($a0)
        MEM_W(0X138, ctx->r4) = ctx->r24;
            goto L_804A20C4;
    }
    // 0x804A20B8: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
    // 0x804A20BC: b           L_804A20C4
    // 0x804A20C0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
        goto L_804A20C4;
    // 0x804A20C0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
L_804A20C4:
    // 0x804A20C4: jal         0x804A27A0
    // 0x804A20C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_1;
    // 0x804A20C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_804A20CC:
    // 0x804A20CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A20D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A20D4: jr          $ra
    // 0x804A20D8: nop

    return;
    // 0x804A20D8: nop

;}
RECOMP_FUNC void func_807A69FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A69FC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6A00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807A6A04: jr          $ra
    // 0x807A6A08: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x807A6A08: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_804712F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804712F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804712F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804712FC: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x80471300: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
    // 0x80471304: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80471308: jal         0x80471168
    // 0x8047130C: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    func_80471168(rdram, ctx);
        goto after_0;
    // 0x8047130C: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    after_0:
    // 0x80471310: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x80471314: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80471318: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8047131C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80471320: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80471324: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80471328: beq         $at, $zero, L_80471350
    if (ctx->r1 == 0) {
        // 0x8047132C: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80471350;
    }
    // 0x8047132C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80471330: sb          $v1, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r3;
    // 0x80471334: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80471338: sb          $v1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r3;
    // 0x8047133C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80471340: jal         0x8047139C
    // 0x80471344: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    func_8047139C(rdram, ctx);
        goto after_1;
    // 0x80471344: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    after_1:
    // 0x80471348: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x8047134C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80471350:
    // 0x80471350: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80471354: sb          $v0, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r2;
    // 0x80471358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8047135C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80471360: jr          $ra
    // 0x80471364: nop

    return;
    // 0x80471364: nop

;}
RECOMP_FUNC void DmaMgr_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DF74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007DF78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007DF7C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007DF80: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8007DF84: addiu       $a1, $a1, -0x12D8
    ctx->r5 = ADD32(ctx->r5, -0X12D8);
    // 0x8007DF88: addiu       $a0, $a0, -0x12F0
    ctx->r4 = ADD32(ctx->r4, -0X12F0);
    // 0x8007DF8C: jal         0x8008AE20
    // 0x8007DF90: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8007DF90: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x8007DF94: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007DF98: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8007DF9C: addiu       $a1, $a1, -0x1298
    ctx->r5 = ADD32(ctx->r5, -0X1298);
    // 0x8007DFA0: addiu       $a0, $a0, -0x12B0
    ctx->r4 = ADD32(ctx->r4, -0X12B0);
    // 0x8007DFA4: jal         0x8008AE20
    // 0x8007DFA8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8007DFA8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x8007DFAC: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8007DFB0: addiu       $t7, $t7, 0x2E98
    ctx->r15 = ADD32(ctx->r15, 0X2E98);
    // 0x8007DFB4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007DFB8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8007DFBC: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8007DFC0: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x8007DFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8007DFC8: addiu       $a2, $a2, -0x1310
    ctx->r6 = ADD32(ctx->r6, -0X1310);
    // 0x8007DFCC: addiu       $a1, $a1, -0x1610
    ctx->r5 = ADD32(ctx->r5, -0X1610);
    // 0x8007DFD0: addiu       $a0, $a0, -0x1310
    ctx->r4 = ADD32(ctx->r4, -0X1310);
    // 0x8007DFD4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8007DFD8: jal         0x80081910
    // 0x8007DFDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_2;
    // 0x8007DFDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8007DFE0: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8007DFE4: addiu       $t8, $t8, -0x1310
    ctx->r24 = ADD32(ctx->r24, -0X1310);
    // 0x8007DFE8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007DFEC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8007DFF0: addiu       $t9, $zero, 0x12
    ctx->r25 = ADD32(0, 0X12);
    // 0x8007DFF4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8007DFF8: addiu       $a2, $a2, -0x2290
    ctx->r6 = ADD32(ctx->r6, -0X2290);
    // 0x8007DFFC: addiu       $a0, $a0, -0x17C0
    ctx->r4 = ADD32(ctx->r4, -0X17C0);
    // 0x8007E000: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8007E004: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8007E008: jal         0x80085B10
    // 0x8007E00C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8007E00C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8007E010: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007E014: jal         0x80090CC0
    // 0x8007E018: addiu       $a0, $a0, -0x17C0
    ctx->r4 = ADD32(ctx->r4, -0X17C0);
    osStartThread_recomp(rdram, ctx);
        goto after_4;
    // 0x8007E018: addiu       $a0, $a0, -0x17C0
    ctx->r4 = ADD32(ctx->r4, -0X17C0);
    after_4:
    // 0x8007E01C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007E020: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007E024: jr          $ra
    // 0x8007E028: nop

    return;
    // 0x8007E028: nop

;}
RECOMP_FUNC void func_804BC514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BC514: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x804BC518: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x804BC51C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x804BC520: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x804BC524: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x804BC528: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x804BC52C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x804BC530: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x804BC534: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x804BC538: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x804BC53C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804BC540: lw          $v0, 0x35C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X35C);
    // 0x804BC544: lwc1        $f12, 0x2A0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2A0);
    // 0x804BC548: lwc1        $f14, 0x2A4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X2A4);
    // 0x804BC54C: addiu       $s1, $v0, 0x4
    ctx->r17 = ADD32(ctx->r2, 0X4);
    // 0x804BC550: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804BC554: addiu       $s0, $a0, 0x2D0
    ctx->r16 = ADD32(ctx->r4, 0X2D0);
    // 0x804BC558: jal         0x80067114
    // 0x804BC55C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x804BC55C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    after_0:
    // 0x804BC560: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804BC564: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BC568: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4168) << 16);
    // 0x804BC56C: lwc1        $f8, -0x568($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4168));
    // 0x804BC570: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x804BC574: lwc1        $f16, 0x2B0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X2B0);
    // 0x804BC578: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x804BC57C: nop

    // 0x804BC580: mul.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x804BC584: jal         0x80065954
    // 0x804BC588: nop

    func_80065954(rdram, ctx);
        goto after_1;
    // 0x804BC588: nop

    after_1:
    // 0x804BC58C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X416C) << 16);
    // 0x804BC590: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x804BC594: sh          $zero, 0x78($sp)
    MEM_H(0X78, ctx->r29) = 0;
    // 0x804BC598: sh          $zero, 0x76($sp)
    MEM_H(0X76, ctx->r29) = 0;
    // 0x804BC59C: sh          $zero, 0x74($sp)
    MEM_H(0X74, ctx->r29) = 0;
    // 0x804BC5A0: lwc1        $f2, -0x564($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X416C));
    // 0x804BC5A4: lwc1        $f18, 0x2A0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X2A0);
    // 0x804BC5A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x804BC5AC: addiu       $fp, $sp, 0x8C
    ctx->r30 = ADD32(ctx->r29, 0X8C);
    // 0x804BC5B0: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x804BC5B4: addiu       $s7, $sp, 0x86
    ctx->r23 = ADD32(ctx->r29, 0X86);
    // 0x804BC5B8: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
    // 0x804BC5BC: addiu       $s5, $sp, 0x7A
    ctx->r21 = ADD32(ctx->r29, 0X7A);
    // 0x804BC5C0: addiu       $s4, $sp, 0x74
    ctx->r20 = ADD32(ctx->r29, 0X74);
    // 0x804BC5C4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804BC5C8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x804BC5CC: nop

    // 0x804BC5D0: sh          $t7, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r15;
    // 0x804BC5D4: lwc1        $f8, 0x2A4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X2A4);
    // 0x804BC5D8: sub.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x804BC5DC: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804BC5E0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x804BC5E4: nop

    // 0x804BC5E8: sh          $t9, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r25;
    // 0x804BC5EC: lwc1        $f18, 0x2A8($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X2A8);
    // 0x804BC5F0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804BC5F4: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x804BC5F8: nop

    // 0x804BC5FC: sh          $t1, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r9;
    // 0x804BC600: lwc1        $f6, 0x2A0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X2A0);
    // 0x804BC604: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x804BC608: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804BC60C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x804BC610: nop

    // 0x804BC614: sh          $t3, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r11;
    // 0x804BC618: lwc1        $f10, 0x2A4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X2A4);
    // 0x804BC61C: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x804BC620: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804BC624: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x804BC628: nop

    // 0x804BC62C: sh          $t5, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r13;
    // 0x804BC630: lwc1        $f6, 0x2A8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X2A8);
    // 0x804BC634: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804BC638: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x804BC63C: nop

    // 0x804BC640: sh          $t7, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r15;
    // 0x804BC644: lwc1        $f16, 0x2AC($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X2AC);
    // 0x804BC648: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804BC64C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x804BC650: nop

    // 0x804BC654: sh          $t9, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r25;
    // 0x804BC658: lwc1        $f18, 0x2B0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X2B0);
    // 0x804BC65C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804BC660: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x804BC664: nop

    // 0x804BC668: sh          $t1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r9;
    // 0x804BC66C: lwc1        $f6, 0x2B4($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X2B4);
    // 0x804BC670: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804BC674: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x804BC678: nop

    // 0x804BC67C: sh          $t3, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r11;
L_804BC680:
    // 0x804BC680: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804BC684: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x804BC688: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x804BC68C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x804BC690: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x804BC694: jal         0x80066D08
    // 0x804BC698: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    func_80066D08(rdram, ctx);
        goto after_2;
    // 0x804BC698: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    after_2:
    // 0x804BC69C: lh          $t4, 0x8C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X8C);
    // 0x804BC6A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x804BC6A4: slti        $at, $s2, 0xA
    ctx->r1 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x804BC6A8: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x804BC6AC: lh          $t5, 0x8E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X8E);
    // 0x804BC6B0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x804BC6B4: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x804BC6B8: sh          $t5, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r13;
    // 0x804BC6BC: lh          $t6, 0x90($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X90);
    // 0x804BC6C0: bne         $at, $zero, L_804BC680
    if (ctx->r1 != 0) {
        // 0x804BC6C4: sh          $t6, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = ctx->r14;
            goto L_804BC680;
    }
    // 0x804BC6C4: sh          $t6, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r14;
    // 0x804BC6C8: lwc1        $f16, 0x2AC($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X2AC);
    // 0x804BC6CC: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4174) << 16);
    // 0x804BC6D0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x804BC6D4: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804BC6D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x804BC6DC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x804BC6E0: lwc1        $f10, -0x55C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4174));
    // 0x804BC6E4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4178) << 16);
    // 0x804BC6E8: sh          $t8, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r24;
    // 0x804BC6EC: lwc1        $f18, 0x2B0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X2B0);
    // 0x804BC6F0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804BC6F4: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x804BC6F8: nop

    // 0x804BC6FC: sh          $t0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r8;
    // 0x804BC700: lwc1        $f6, 0x2B4($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X2B4);
    // 0x804BC704: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804BC708: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x804BC70C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x804BC710: sh          $t2, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r10;
    // 0x804BC714: lwc1        $f16, 0x2B8($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X2B8);
    // 0x804BC718: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x804BC71C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804BC720: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x804BC724: nop

    // 0x804BC728: sh          $t4, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r12;
    // 0x804BC72C: lwc1        $f6, 0x2BC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X2BC);
    // 0x804BC730: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x804BC734: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x804BC738: lwc1        $f16, -0x558($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4178));
    // 0x804BC73C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x804BC740: nop

    // 0x804BC744: sh          $t6, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r14;
    // 0x804BC748: lwc1        $f18, 0x2C0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X2C0);
    // 0x804BC74C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804BC750: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x804BC754: nop

    // 0x804BC758: sh          $t8, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r24;
    // 0x804BC75C: lwc1        $f6, 0x2B8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X2B8);
    // 0x804BC760: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x804BC764: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804BC768: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x804BC76C: nop

    // 0x804BC770: sh          $t0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r8;
    // 0x804BC774: lwc1        $f4, 0x2BC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X2BC);
    // 0x804BC778: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804BC77C: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804BC780: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x804BC784: nop

    // 0x804BC788: sh          $t2, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r10;
    // 0x804BC78C: lwc1        $f10, 0x2C0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X2C0);
    // 0x804BC790: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804BC794: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x804BC798: nop

    // 0x804BC79C: sh          $t4, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r12;
    // 0x804BC7A0: lwc1        $f4, 0x2C4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X2C4);
    // 0x804BC7A4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804BC7A8: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x804BC7AC: nop

    // 0x804BC7B0: sh          $t6, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r14;
    // 0x804BC7B4: lwc1        $f6, 0x2C8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X2C8);
    // 0x804BC7B8: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804BC7BC: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x804BC7C0: nop

    // 0x804BC7C4: sh          $t8, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r24;
    // 0x804BC7C8: lwc1        $f10, 0x2CC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X2CC);
    // 0x804BC7CC: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x804BC7D0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804BC7D4: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x804BC7D8: nop

    // 0x804BC7DC: sh          $t0, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r8;
L_804BC7E0:
    // 0x804BC7E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804BC7E4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x804BC7E8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x804BC7EC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x804BC7F0: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x804BC7F4: jal         0x80066D08
    // 0x804BC7F8: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    func_80066D08(rdram, ctx);
        goto after_3;
    // 0x804BC7F8: sw          $fp, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r30;
    after_3:
    // 0x804BC7FC: lh          $t1, 0x8C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X8C);
    // 0x804BC800: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x804BC804: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x804BC808: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x804BC80C: lh          $t2, 0x8E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X8E);
    // 0x804BC810: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x804BC814: sh          $t2, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r10;
    // 0x804BC818: lh          $t3, 0x90($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X90);
    // 0x804BC81C: bne         $s2, $s3, L_804BC7E0
    if (ctx->r18 != ctx->r19) {
        // 0x804BC820: sh          $t3, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = ctx->r11;
            goto L_804BC7E0;
    }
    // 0x804BC820: sh          $t3, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r11;
    // 0x804BC824: lh          $t4, 0x86($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X86);
    // 0x804BC828: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x804BC82C: lh          $t5, 0x88($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X88);
    // 0x804BC830: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x804BC834: lh          $t6, 0x8A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8A);
    // 0x804BC838: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
    // 0x804BC83C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x804BC840: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x804BC844: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x804BC848: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x804BC84C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x804BC850: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x804BC854: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x804BC858: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x804BC85C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x804BC860: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804BC864: jr          $ra
    // 0x804BC868: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x804BC868: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8046C78C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C78C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046C790: lw          $t7, 0x14C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14C);
    // 0x8046C794: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
    // 0x8046C798: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8046C79C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8046C7A0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8046C7A4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8046C7A8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046C7AC: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8046C7B0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8046C7B4: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8046C7B8: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8046C7BC: jr          $ra
    // 0x8046C7C0: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8046C7C0: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void ceil_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082024: ceil.w.d    $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = S32(ceil(ctx->f12.d));
    // 0x80082028: jr          $ra
    // 0x8008202C: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
    return;
    // 0x8008202C: cvt.d.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = CVT_D_W(ctx->f12.u32l);
;}
RECOMP_FUNC void func_8002FE78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FE78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FE7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FE80: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FE84: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FE88: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002FE8C: jal         0x8002F678
    // 0x8002FE90: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FE90: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FE94: beq         $v0, $zero, L_8002FEA8
    if (ctx->r2 == 0) {
        // 0x8002FE98: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FEA8;
    }
    // 0x8002FE98: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FE9C: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FEA0: addiu       $t6, $t6, -0x435C
    ctx->r14 = ADD32(ctx->r14, -0X435C);
    // 0x8002FEA4: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FEA8:
    // 0x8002FEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FEAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FEB0: jr          $ra
    // 0x8002FEB4: nop

    return;
    // 0x8002FEB4: nop

;}
