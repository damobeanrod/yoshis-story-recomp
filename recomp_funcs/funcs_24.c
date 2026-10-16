#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80699184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699184: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069918C: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80699190: bnel        $t6, $zero, L_8069923C
    if (ctx->r14 != 0) {
        // 0x80699194: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8069923C;
    }
    goto skip_0;
    // 0x80699194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80699198: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8069919C: addiu       $t7, $zero, 0x6107
    ctx->r15 = ADD32(0, 0X6107);
    // 0x806991A0: addiu       $t9, $zero, 0xC1
    ctx->r25 = ADD32(0, 0XC1);
    // 0x806991A4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x806991A8: addiu       $t1, $zero, 0x2222
    ctx->r9 = ADD32(0, 0X2222);
    // 0x806991AC: addiu       $t3, $zero, 0x2244
    ctx->r11 = ADD32(0, 0X2244);
    // 0x806991B0: sh          $t7, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r15;
    // 0x806991B4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x806991B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x806991BC: sh          $t9, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r25;
    // 0x806991C0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x806991C4: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    // 0x806991C8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x806991CC: sh          $t3, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r11;
    // 0x806991D0: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806991D4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806991D8: sh          $t5, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r13;
    // 0x806991DC: jal         0x8005FCA8
    // 0x806991E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x806991E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806991E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806991E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806991EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806991F0: jal         0x80699250
    // 0x806991F4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_80699250(rdram, ctx);
        goto after_1;
    // 0x806991F4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x806991F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806991FC: lui         $t1, 0x806A
    ctx->r9 = S32(RELOC_HI16(556, 0X580) << 16);
    // 0x80699200: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80699204: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x80699208: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8069920C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80699210: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80699214: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(556, 0X5D4) << 16);
    // 0x80699218: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8069921C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80699220: lh          $t1, -0x6D60($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(556, 0X580));
    // 0x80699224: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x80699228: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x8069922C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x80699230: lwc1        $f8, -0x6D0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(556, 0X5D4));
    // 0x80699234: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x80699238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8069923C:
    // 0x8069923C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699240: jr          $ra
    // 0x80699244: nop

    return;
    // 0x80699244: nop

;}
RECOMP_FUNC void func_80407D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80407D10: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80407D14: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80407D18: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80407D1C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80407D20: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80407D24: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80407D28: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80407D2C: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80407D30: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80407D34: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80407D38: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80407D3C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80407D40: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80407D44: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80407D48: jal         0x80047AB8
    // 0x80407D4C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x80407D4C: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_0:
    // 0x80407D50: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80407D54: jal         0x80047AB8
    // 0x80407D58: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x80407D58: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    after_1:
    // 0x80407D5C: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80407D60: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80407D64: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x80407D68: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80407D6C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80407D70: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80407D74: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80407D78: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80407D7C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80407D80: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80407D84: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80407D88: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80407D8C: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80407D90: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80407D94: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80407D98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80407D9C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80407DA0: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80407DA4: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80407DA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80407DAC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80407DB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80407DB4: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x80407DB8: nop

    // 0x80407DBC: bc1f        L_80407EC8
    if (!c1cs) {
        // 0x80407DC0: nop
    
            goto L_80407EC8;
    }
    // 0x80407DC0: nop

    // 0x80407DC4: lw          $a1, 0x24($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X24);
    // 0x80407DC8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80407DCC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80407DD0: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x80407DD4: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80407DD8: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x80407DDC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80407DE0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80407DE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80407DE8: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80407DEC: blez        $a0, L_80407E6C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80407DF0: sub.s       $f14, $f6, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
            goto L_80407E6C;
    }
    // 0x80407DF0: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80407DF4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80407DF8: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80407DFC: neg.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = -ctx->f24.fl;
L_80407E00:
    // 0x80407E00: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80407E04: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80407E08: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80407E0C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80407E10: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80407E14: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80407E18: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80407E1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80407E20: add.s       $f18, $f14, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f24.fl;
    // 0x80407E24: add.s       $f2, $f10, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80407E28: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80407E2C: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80407E30: sub.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80407E34: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80407E38: div.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80407E3C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80407E40: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80407E44: add.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80407E48: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80407E4C: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
    // 0x80407E50: nop

    // 0x80407E54: bc1f        L_80407E64
    if (!c1cs) {
        // 0x80407E58: nop
    
            goto L_80407E64;
    }
    // 0x80407E58: nop

    // 0x80407E5C: b           L_80407EC8
    // 0x80407E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80407EC8;
    // 0x80407E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80407E64:
    // 0x80407E64: bne         $at, $zero, L_80407E00
    if (ctx->r1 != 0) {
        // 0x80407E68: mov.s       $f14, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
            goto L_80407E00;
    }
    // 0x80407E68: mov.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = ctx->f18.fl;
L_80407E6C:
    // 0x80407E6C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80407E70: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80407E74: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80407E78: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80407E7C: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80407E80: neg.s       $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = -ctx->f24.fl;
    // 0x80407E84: add.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80407E88: sub.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80407E8C: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80407E90: div.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80407E94: sub.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80407E98: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80407E9C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80407EA0: add.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80407EA4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80407EA8: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
    // 0x80407EAC: nop

    // 0x80407EB0: bc1f        L_80407EC0
    if (!c1cs) {
        // 0x80407EB4: nop
    
            goto L_80407EC0;
    }
    // 0x80407EB4: nop

    // 0x80407EB8: b           L_80407EC8
    // 0x80407EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80407EC8;
    // 0x80407EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80407EC0:
    // 0x80407EC0: b           L_80407EC8
    // 0x80407EC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80407EC8;
    // 0x80407EC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80407EC8:
    // 0x80407EC8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80407ECC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80407ED0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80407ED4: jr          $ra
    // 0x80407ED8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80407ED8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_806EC16C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC16C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EC170: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EC174: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EC178: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x806EC17C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806EC180: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EC184: bne         $a1, $at, L_806EC1A8
    if (ctx->r5 != ctx->r1) {
        // 0x806EC188: nop
    
            goto L_806EC1A8;
    }
    // 0x806EC188: nop

    // 0x806EC18C: jal         0x80067E78
    // 0x806EC190: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067E78(rdram, ctx);
        goto after_0;
    // 0x806EC190: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806EC194: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x806EC198: jal         0x80067F78
    // 0x806EC19C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x806EC19C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806EC1A0: b           L_806EC1F8
    // 0x806EC1A4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_806EC1F8;
    // 0x806EC1A4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_806EC1A8:
    // 0x806EC1A8: jal         0x80067930
    // 0x806EC1AC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x806EC1AC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_2:
    // 0x806EC1B0: beq         $v0, $zero, L_806EC1E0
    if (ctx->r2 == 0) {
        // 0x806EC1B4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_806EC1E0;
    }
    // 0x806EC1B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806EC1B8: bnel        $v0, $at, L_806EC1FC
    if (ctx->r2 != ctx->r1) {
        // 0x806EC1BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EC1FC;
    }
    goto skip_0;
    // 0x806EC1BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EC1C0: jal         0x80067E78
    // 0x806EC1C4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_3;
    // 0x806EC1C4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x806EC1C8: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x806EC1CC: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x806EC1D0: jal         0x800678F0
    // 0x806EC1D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x806EC1D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x806EC1D8: b           L_806EC1FC
    // 0x806EC1DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EC1FC;
    // 0x806EC1DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EC1E0:
    // 0x806EC1E0: jal         0x80067E78
    // 0x806EC1E4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_5;
    // 0x806EC1E4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x806EC1E8: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x806EC1EC: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x806EC1F0: jal         0x80067838
    // 0x806EC1F4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_6;
    // 0x806EC1F4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_806EC1F8:
    // 0x806EC1F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EC1FC:
    // 0x806EC1FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EC200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EC204: jr          $ra
    // 0x806EC208: nop

    return;
    // 0x806EC208: nop

;}
RECOMP_FUNC void func_8056834C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056834C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80568350: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80568354: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80568358: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8056835C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80568360: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568364: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80568368: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8056836C: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568370: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80568374: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80568378: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21B4) << 16);
    // 0x8056837C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80568380: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80568384: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80568388: nop

    // 0x8056838C: bc1fl       L_805683A8
    if (!c1cs) {
        // 0x80568390: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805683A8;
    }
    goto skip_0;
    // 0x80568390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80568394: lwc1        $f18, -0x689C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21B4));
    // 0x80568398: add.s       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8056839C: b           L_805683B4
    // 0x805683A0: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
        goto L_805683B4;
    // 0x805683A0: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x805683A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805683A8:
    // 0x805683A8: jal         0x80569310
    // 0x805683AC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80569310(rdram, ctx);
        goto after_0;
    // 0x805683AC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x805683B0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_805683B4:
    // 0x805683B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805683B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805683BC: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x805683C0: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x805683C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805683C8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x805683CC: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x805683D0: nop

    // 0x805683D4: bc1fl       L_805683F8
    if (!c1cs) {
        // 0x805683D8: lw          $t6, 0x20($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X20);
            goto L_805683F8;
    }
    goto skip_1;
    // 0x805683D8: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    skip_1:
    // 0x805683DC: jal         0x80567DD4
    // 0x805683E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80567DD4(rdram, ctx);
        goto after_1;
    // 0x805683E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x805683E4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805683E8: jal         0x80048F84
    // 0x805683EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805683EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x805683F0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805683F4: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
L_805683F8:
    // 0x805683F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805683FC: beq         $t6, $zero, L_8056840C
    if (ctx->r14 == 0) {
        // 0x80568400: nop
    
            goto L_8056840C;
    }
    // 0x80568400: nop

    // 0x80568404: jal         0x80569310
    // 0x80568408: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80569310(rdram, ctx);
        goto after_3;
    // 0x80568408: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_3:
L_8056840C:
    // 0x8056840C: jal         0x805677F4
    // 0x80568410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805677F4(rdram, ctx);
        goto after_4;
    // 0x80568410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80568414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80568418: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8056841C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80568420: jr          $ra
    // 0x80568424: nop

    return;
    // 0x80568424: nop

;}
RECOMP_FUNC void func_80533D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533D84: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80533D88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80533D8C: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x80533D90: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80533D94: bnel        $t6, $zero, L_80533DA4
    if (ctx->r14 != 0) {
        // 0x80533D98: lw          $t7, 0x4($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X4);
            goto L_80533DA4;
    }
    goto skip_0;
    // 0x80533D98: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x80533D9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80533DA0: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
L_80533DA4:
    // 0x80533DA4: bnel        $t7, $zero, L_80533DB4
    if (ctx->r15 != 0) {
        // 0x80533DA8: lw          $t8, 0x8($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X8);
            goto L_80533DB4;
    }
    goto skip_1;
    // 0x80533DA8: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x80533DAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80533DB0: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
L_80533DB4:
    // 0x80533DB4: bnel        $t8, $zero, L_80533DC4
    if (ctx->r24 != 0) {
        // 0x80533DB8: lw          $t9, 0xC($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XC);
            goto L_80533DC4;
    }
    goto skip_2;
    // 0x80533DB8: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    skip_2:
    // 0x80533DBC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80533DC0: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
L_80533DC4:
    // 0x80533DC4: bne         $t9, $zero, L_80533DD0
    if (ctx->r25 != 0) {
        // 0x80533DC8: nop
    
            goto L_80533DD0;
    }
    // 0x80533DC8: nop

    // 0x80533DCC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80533DD0:
    // 0x80533DD0: jr          $ra
    // 0x80533DD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80533DD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80062C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062C70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062C74: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80062C78: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x80062C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062C80: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80062C84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80062C88: jal         0x80081C64
    // 0x80062C8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80062C8C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80062C90: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80062C94: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x80062C98: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80062C9C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80062CA0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80062CA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80062CA8: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80062CAC: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80062CB0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80062CB4: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80062CB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80062CBC: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80062CC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80062CC4: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80062CC8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80062CCC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80062CD0: add.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80062CD4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80062CD8: div.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80062CDC: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80062CE0: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x80062CE4: div.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80062CE8: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80062CEC: lwc1        $f8, 0x28($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80062CF0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80062CF4: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80062CF8: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x80062CFC: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x80062D00: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x80062D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062D08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80062D0C: jr          $ra
    // 0x80062D10: nop

    return;
    // 0x80062D10: nop

;}
RECOMP_FUNC void func_804330F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804330F4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804330F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x804330FC: lhu         $a1, 0x6C($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6C);
    // 0x80433100: blez        $a1, L_80433114
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80433104: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80433114;
    }
    // 0x80433104: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80433108:
    // 0x80433108: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8043310C: bnel        $at, $zero, L_80433108
    if (ctx->r1 != 0) {
        // 0x80433110: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80433108;
    }
    goto skip_0;
    // 0x80433110: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_80433114:
    // 0x80433114: jr          $ra
    // 0x80433118: nop

    return;
    // 0x80433118: nop

;}
RECOMP_FUNC void func_8003B890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B890: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8003B894: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8003B898: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8003B89C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8003B8A0: addiu       $t7, $t7, -0x1400
    ctx->r15 = ADD32(ctx->r15, -0X1400);
    // 0x8003B8A4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8003B8A8: jr          $ra
    // 0x8003B8AC: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    return;
    // 0x8003B8AC: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8046C7C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C7C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046C7C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046C7CC: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x8046C7D0: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(143, 0X1200) << 16);
    // 0x8046C7D4: addiu       $t8, $t8, -0x29B0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(143, 0X1200));
    // 0x8046C7D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8046C7DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8046C7E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8046C7E4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8046C7E8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8046C7EC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8046C7F0: beql        $v1, $zero, L_8046C844
    if (ctx->r3 == 0) {
        // 0x8046C7F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046C844;
    }
    goto skip_0;
    // 0x8046C7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8046C7F8: jalr        $v1
    // 0x8046C7FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8046C7FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046C800: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046C804: lui         $t7, 0x8047
    ctx->r15 = S32(RELOC_HI16(143, 0X1354) << 16);
    // 0x8046C808: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x8046C80C: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x8046C810: lw          $t5, 0x134($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X134);
    // 0x8046C814: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8046C818: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8046C81C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8046C820: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8046C824: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8046C828: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8046C82C: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046C830: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x8046C834: lw          $t7, -0x285C($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(143, 0X1354));
    // 0x8046C838: jal         0x8046C78C
    // 0x8046C83C: sw          $t7, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r15;
    func_8046C78C(rdram, ctx);
        goto after_1;
    // 0x8046C83C: sw          $t7, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r15;
    after_1:
    // 0x8046C840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046C844:
    // 0x8046C844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046C848: jr          $ra
    // 0x8046C84C: nop

    return;
    // 0x8046C84C: nop

;}
RECOMP_FUNC void func_80070848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070848: lui         $t1, 0xFFFA
    ctx->r9 = S32(0XFFFA << 16);
    // 0x8007084C: or          $t2, $sp, $zero
    ctx->r10 = ctx->r29 | 0;
    // 0x80070850: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80070854: ori         $t1, $t1, 0x5A5A
    ctx->r9 = ctx->r9 | 0X5A5A;
L_80070858:
    // 0x80070858: addiu       $t2, $t2, -0x8
    ctx->r10 = ADD32(ctx->r10, -0X8);
    // 0x8007085C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80070860: bne         $t2, $sp, L_80070858
    if (ctx->r10 != ctx->r29) {
        // 0x80070864: sw          $t1, 0x4($t2)
        MEM_W(0X4, ctx->r10) = ctx->r9;
            goto L_80070858;
    }
    // 0x80070864: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80070868: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007086C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80070870: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80070874: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80070878: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8007087C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80070880: sh          $t6, -0x7B94($at)
    MEM_H(-0X7B94, ctx->r1) = ctx->r14;
    // 0x80070884: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x80070888: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x8007088C: lw          $v1, 0xC($t7)
    ctx->r3 = MEM_W(ctx->r15, 0XC);
    // 0x80070890: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80070894: subu        $t8, $a3, $v0
    ctx->r24 = SUB32(ctx->r7, ctx->r2);
    // 0x80070898: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8007089C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800708A0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x800708A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800708A8: lh          $t0, 0x4($t7)
    ctx->r8 = MEM_H(ctx->r15, 0X4);
    // 0x800708AC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800708B0: addiu       $a2, $a2, 0x17C0
    ctx->r6 = ADD32(ctx->r6, 0X17C0);
    // 0x800708B4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800708B8: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x800708BC: jal         0x8006F884
    // 0x800708C0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    Fault_Printf(rdram, ctx);
        goto after_0;
    // 0x800708C0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x800708C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800708C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800708CC: jr          $ra
    // 0x800708D0: nop

    return;
    // 0x800708D0: nop

;}
RECOMP_FUNC void func_8006915C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006915C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80069160: sb          $zero, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = 0;
    // 0x80069164: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80069168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006916C: sb          $zero, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = 0;
    // 0x80069170: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069174: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80069178: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006917C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80069180: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    // 0x80069184: jal         0x800748B0
    // 0x80069188: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    func_800748B0(rdram, ctx);
        goto after_0;
    // 0x80069188: addiu       $a0, $a0, -0x20C0
    ctx->r4 = ADD32(ctx->r4, -0X20C0);
    after_0:
    // 0x8006918C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069194: jr          $ra
    // 0x80069198: nop

    return;
    // 0x80069198: nop

;}
RECOMP_FUNC void func_80067AF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80067AFC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80067B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067B04: jal         0x80018C80
    // 0x80067B08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_80018C80(rdram, ctx);
        goto after_0;
    // 0x80067B08: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x80067B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067B14: jr          $ra
    // 0x80067B18: nop

    return;
    // 0x80067B18: nop

;}
RECOMP_FUNC void func_80581854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581854: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x80581858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8058185C: beq         $v1, $zero, L_80581878
    if (ctx->r3 == 0) {
        // 0x80581860: nop
    
            goto L_80581878;
    }
    // 0x80581860: nop

    // 0x80581864: lw          $a0, 0x1F4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F4);
    // 0x80581868: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8058186C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80581870: jr          $ra
    // 0x80581874: lw          $v0, 0x6EFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6EFC);
    return;
    // 0x80581874: lw          $v0, 0x6EFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6EFC);
L_80581878:
    // 0x80581878: jr          $ra
    // 0x8058187C: nop

    return;
    // 0x8058187C: nop

;}
RECOMP_FUNC void func_8078D758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D758: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078D75C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078D760: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078D764: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8078D768: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078D76C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8078D770: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8078D774: beq         $t7, $zero, L_8078D798
    if (ctx->r15 == 0) {
        // 0x8078D778: nop
    
            goto L_8078D798;
    }
    // 0x8078D778: nop

    // 0x8078D77C: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x8078D780: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8078D784: beq         $t8, $zero, L_8078D798
    if (ctx->r24 == 0) {
        // 0x8078D788: nop
    
            goto L_8078D798;
    }
    // 0x8078D788: nop

    // 0x8078D78C: lw          $t0, -0x72B0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X72B0);
    // 0x8078D790: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8078D794: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_8078D798:
    // 0x8078D798: jal         0x8078D2D4
    // 0x8078D79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078D2D4(rdram, ctx);
        goto after_0;
    // 0x8078D79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8078D7A0: jal         0x8078D340
    // 0x8078D7A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078D340(rdram, ctx);
        goto after_1;
    // 0x8078D7A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8078D7A8: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8078D7AC: lw          $t1, -0x72B0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X72B0);
    // 0x8078D7B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8078D7B4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8078D7B8: bnel        $t2, $at, L_8078D7F0
    if (ctx->r10 != ctx->r1) {
        // 0x8078D7BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078D7F0;
    }
    goto skip_0;
    // 0x8078D7BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8078D7C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8078D7C4: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x8078D7C8: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x8078D7CC: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x8078D7D0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8078D7D4: jal         0x80067878
    // 0x8078D7D8: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_2;
    // 0x8078D7D8: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    after_2:
    // 0x8078D7DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8078D7E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078D7E4: jal         0x8078DA34
    // 0x8078D7E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8078DA34(rdram, ctx);
        goto after_3;
    // 0x8078D7E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x8078D7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078D7F0:
    // 0x8078D7F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078D7F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078D7F8: jr          $ra
    // 0x8078D7FC: nop

    return;
    // 0x8078D7FC: nop

;}
RECOMP_FUNC void func_80708D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80708D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80708D24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80708D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80708D2C: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(715, 0X230) << 16);
    // 0x80708D30: lui         $a1, 0x8071
    ctx->r5 = S32(RELOC_HI16(715, 0X240) << 16);
    // 0x80708D34: addiu       $a1, $a1, -0x70A0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(715, 0X240));
    // 0x80708D38: addiu       $a0, $a0, -0x70B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(715, 0X230));
    // 0x80708D3C: jal         0x8004667C
    // 0x80708D40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80708D40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80708D44: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80708D48: lui         $a2, 0x8071
    ctx->r6 = S32(RELOC_HI16(715, 0X170) << 16);
    // 0x80708D4C: addiu       $a2, $a2, -0x7170
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(715, 0X170));
    // 0x80708D50: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x80708D54: jal         0x80057B28
    // 0x80708D58: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x80708D58: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_1:
    // 0x80708D5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80708D60: lui         $v0, 0x8071
    ctx->r2 = S32(RELOC_HI16(715, 0XDC) << 16);
    // 0x80708D64: addiu       $v0, $v0, -0x7204
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(715, 0XDC));
    // 0x80708D68: jr          $ra
    // 0x80708D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80708D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004590C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004590C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80045910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045914: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x80045918: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004591C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80045920: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80045924: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80045928: beq         $t7, $zero, L_80045954
    if (ctx->r15 == 0) {
        // 0x8004592C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80045954;
    }
    // 0x8004592C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045930: addiu       $a0, $a0, 0x670
    ctx->r4 = ADD32(ctx->r4, 0X670);
    // 0x80045934: addiu       $a1, $zero, 0x1B3
    ctx->r5 = ADD32(0, 0X1B3);
    // 0x80045938: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8004593C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80045940: jal         0x80071380
    // 0x80045944: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80045944: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80045948: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8004594C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80045950: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80045954:
    // 0x80045954: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80045958: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004595C: beql        $a3, $t8, L_80045970
    if (ctx->r7 == ctx->r24) {
        // 0x80045960: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80045970;
    }
    goto skip_0;
    // 0x80045960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80045964: jal         0x80045508
    // 0x80045968: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80045508(rdram, ctx);
        goto after_1;
    // 0x80045968: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x8004596C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80045970:
    // 0x80045970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80045974: jr          $ra
    // 0x80045978: nop

    return;
    // 0x80045978: nop

;}
RECOMP_FUNC void func_804498C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804498C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804498C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804498CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804498D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804498D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804498D8: bne         $a2, $zero, L_80449918
    if (ctx->r6 != 0) {
        // 0x804498DC: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80449918;
    }
    // 0x804498DC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804498E0: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x804498E4: lw          $v1, 0x54($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X54);
    // 0x804498E8: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x804498EC: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x804498F0: bne         $at, $zero, L_80449958
    if (ctx->r1 != 0) {
        // 0x804498F4: sw          $t7, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r15;
            goto L_80449958;
    }
    // 0x804498F4: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x804498F8: jal         0x804469FC
    // 0x804498FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804469FC(rdram, ctx);
        goto after_0;
    // 0x804498FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80449900: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449904: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449908: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8044990C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449910: b           L_80449958
    // 0x80449914: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80449958;
    // 0x80449914: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_80449918:
    // 0x80449918: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044991C: bnel        $a2, $at, L_80449948
    if (ctx->r6 != ctx->r1) {
        // 0x80449920: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80449948;
    }
    goto skip_0;
    // 0x80449920: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80449924: jal         0x804469FC
    // 0x80449928: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804469FC(rdram, ctx);
        goto after_1;
    // 0x80449928: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8044992C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449930: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449934: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80449938: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044993C: b           L_80449958
    // 0x80449940: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80449958;
    // 0x80449940: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80449944: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80449948:
    // 0x80449948: bnel        $a2, $at, L_8044995C
    if (ctx->r6 != ctx->r1) {
        // 0x8044994C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044995C;
    }
    goto skip_1;
    // 0x8044994C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80449950: jal         0x80446A50
    // 0x80449954: nop

    func_80446A50(rdram, ctx);
        goto after_2;
    // 0x80449954: nop

    after_2:
L_80449958:
    // 0x80449958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044995C:
    // 0x8044995C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80449960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449964: jr          $ra
    // 0x80449968: nop

    return;
    // 0x80449968: nop

;}
RECOMP_FUNC void func_8079D8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079D8EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8079D8F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079D8F4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8079D8F8: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8079D8FC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8079D900: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8079D904: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8079D908: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8079D90C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(832, 0X2F0) << 16);
    // 0x8079D910: lwc1        $f10, -0x2570($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(832, 0X2F0));
    // 0x8079D914: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8079D918: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8079D91C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8079D920: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8079D924: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8079D928: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8079D92C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8079D930: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8079D934: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8079D938: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8079D93C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8079D940: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8079D944: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8079D948: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8079D94C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8079D950: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8079D954: jalr        $t9
    // 0x8079D958: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8079D958: nop

    after_0:
    // 0x8079D95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079D960: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8079D964: jr          $ra
    // 0x8079D968: nop

    return;
    // 0x8079D968: nop

;}
RECOMP_FUNC void func_80559458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80559458: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8055945C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80559460: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80559464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80559468: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8055946C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80559470: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80559474: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80559478: jal         0x80048F84
    // 0x8055947C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8055947C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80559480: jal         0x805580E8
    // 0x80559484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805580E8(rdram, ctx);
        goto after_1;
    // 0x80559484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80559488: jal         0x8005FD1C
    // 0x8055948C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FD1C(rdram, ctx);
        goto after_2;
    // 0x8055948C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80559490: jal         0x8005FD1C
    // 0x80559494: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_8005FD1C(rdram, ctx);
        goto after_3;
    // 0x80559494: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_3:
    // 0x80559498: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8055949C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805594A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805594A4: lh          $t7, 0x13C($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X13C);
    // 0x805594A8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x805594AC: sh          $t7, 0x13C($s1)
    MEM_H(0X13C, ctx->r17) = ctx->r15;
    // 0x805594B0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x805594B4: lh          $t9, 0x13E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X13E);
    // 0x805594B8: sh          $t9, 0x13E($s1)
    MEM_H(0X13E, ctx->r17) = ctx->r25;
    // 0x805594BC: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x805594C0: lwc1        $f4, 0x6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x805594C4: swc1        $f4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f4.u32l;
    // 0x805594C8: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x805594CC: lwc1        $f6, 0x70($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X70);
    // 0x805594D0: jal         0x80559928
    // 0x805594D4: swc1        $f6, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f6.u32l;
    func_80559928(rdram, ctx);
        goto after_4;
    // 0x805594D4: swc1        $f6, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f6.u32l;
    after_4:
    // 0x805594D8: sw          $zero, 0x1E4($s1)
    MEM_W(0X1E4, ctx->r17) = 0;
    // 0x805594DC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x805594E0: sw          $zero, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = 0;
    // 0x805594E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805594E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805594EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805594F0: jr          $ra
    // 0x805594F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x805594F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8007816C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007816C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80078170: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80078174: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x80078178: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007817C: jr          $ra
    // 0x80078180: nop

    return;
    // 0x80078180: nop

;}
RECOMP_FUNC void func_8059F190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8059F194: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8059F198: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8059F19C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8059F1A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059F1A4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8059F1A8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8059F1AC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8059F1B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8059F1B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8059F1B8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8059F1BC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8059F1C0: lui         $t2, 0x805A
    ctx->r10 = S32(RELOC_HI16(405, 0X840) << 16);
    // 0x8059F1C4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8059F1C8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8059F1CC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8059F1D0: lw          $t2, -0xD70($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(405, 0X840));
    // 0x8059F1D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8059F1D8: jal         0x8059EBBC
    // 0x8059F1DC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8059EBBC(rdram, ctx);
        goto after_0;
    // 0x8059F1DC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x8059F1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8059F1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8059F1E8: jr          $ra
    // 0x8059F1EC: nop

    return;
    // 0x8059F1EC: nop

;}
RECOMP_FUNC void func_8044CB6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044CB6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044CB70: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8044CB74: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8044CB78: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8044CB7C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8044CB80: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    // 0x8044CB84: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8044CB88: bc1tl       L_8044CBC8
    if (c1cs) {
        // 0x8044CB8C: c.eq.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
            goto L_8044CBC8;
    }
    goto skip_0;
    // 0x8044CB8C: c.eq.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
    skip_0:
    // 0x8044CB90: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8044CB94: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8044CB98: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8044CB9C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8044CBA0: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8044CBA4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8044CBA8: nop

    // 0x8044CBAC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8044CBB0: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8044CBB4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8044CBB8: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8044CBBC: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x8044CBC0: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x8044CBC4: c.eq.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
L_8044CBC8:
    // 0x8044CBC8: nop

    // 0x8044CBCC: bc1tl       L_8044CC0C
    if (c1cs) {
        // 0x8044CBD0: c.eq.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
            goto L_8044CC0C;
    }
    goto skip_1;
    // 0x8044CBD0: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
    skip_1:
    // 0x8044CBD4: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8044CBD8: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8044CBDC: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8044CBE0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8044CBE4: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8044CBE8: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8044CBEC: nop

    // 0x8044CBF0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8044CBF4: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x8044CBF8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8044CBFC: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x8044CC00: swc1        $f6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f6.u32l;
    // 0x8044CC04: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x8044CC08: c.eq.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl == ctx->f14.fl;
L_8044CC0C:
    // 0x8044CC0C: nop

    // 0x8044CC10: bc1t        L_8044CC4C
    if (c1cs) {
        // 0x8044CC14: nop
    
            goto L_8044CC4C;
    }
    // 0x8044CC14: nop

    // 0x8044CC18: lwc1        $f16, 0x20($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8044CC1C: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8044CC20: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8044CC24: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8044CC28: lwc1        $f16, 0x2C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8044CC2C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8044CC30: nop

    // 0x8044CC34: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8044CC38: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x8044CC3C: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8044CC40: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8044CC44: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    // 0x8044CC48: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
L_8044CC4C:
    // 0x8044CC4C: jr          $ra
    // 0x8044CC50: nop

    return;
    // 0x8044CC50: nop

;}
RECOMP_FUNC void lceilf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082030: ceil.w.s    $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = S32(ceilf(ctx->f12.fl));
    // 0x80082034: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80082038: jr          $ra
    // 0x8008203C: nop

    return;
    // 0x8008203C: nop

;}
RECOMP_FUNC void func_8057E9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057E9DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8057E9E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057E9E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057E9E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057E9EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8057E9F0: jal         0x8057E480
    // 0x8057E9F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8057E480(rdram, ctx);
        goto after_0;
    // 0x8057E9F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8057E9F8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8057E9FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8057EA00: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8057EA04: lw          $v1, 0x2BC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2BC);
    // 0x8057EA08: bne         $v1, $zero, L_8057EA30
    if (ctx->r3 != 0) {
        // 0x8057EA0C: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_8057EA30;
    }
    // 0x8057EA0C: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x8057EA10: lw          $t6, 0x2B8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2B8);
    // 0x8057EA14: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8057EA18: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x8057EA1C: bne         $at, $zero, L_8057EA28
    if (ctx->r1 != 0) {
        // 0x8057EA20: sw          $t7, 0x2B8($v0)
        MEM_W(0X2B8, ctx->r2) = ctx->r15;
            goto L_8057EA28;
    }
    // 0x8057EA20: sw          $t7, 0x2B8($v0)
    MEM_W(0X2B8, ctx->r2) = ctx->r15;
    // 0x8057EA24: sw          $zero, 0x2B8($v0)
    MEM_W(0X2B8, ctx->r2) = 0;
L_8057EA28:
    // 0x8057EA28: b           L_8057EA34
    // 0x8057EA2C: sw          $t9, 0x2BC($v0)
    MEM_W(0X2BC, ctx->r2) = ctx->r25;
        goto L_8057EA34;
    // 0x8057EA2C: sw          $t9, 0x2BC($v0)
    MEM_W(0X2BC, ctx->r2) = ctx->r25;
L_8057EA30:
    // 0x8057EA30: sw          $t0, 0x2BC($v0)
    MEM_W(0X2BC, ctx->r2) = ctx->r8;
L_8057EA34:
    // 0x8057EA34: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8057EA38: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8057EA3C: nop

    // 0x8057EA40: bc1fl       L_8057EA60
    if (!c1cs) {
        // 0x8057EA44: lw          $t1, 0x2B4($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X2B4);
            goto L_8057EA60;
    }
    goto skip_0;
    // 0x8057EA44: lw          $t1, 0x2B4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2B4);
    skip_0:
    // 0x8057EA48: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8057EA4C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8057EA50: nop

    // 0x8057EA54: bc1t        L_8057EAA0
    if (c1cs) {
        // 0x8057EA58: nop
    
            goto L_8057EAA0;
    }
    // 0x8057EA58: nop

    // 0x8057EA5C: lw          $t1, 0x2B4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2B4);
L_8057EA60:
    // 0x8057EA60: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8057EA64: sw          $t2, 0x2B4($v0)
    MEM_W(0X2B4, ctx->r2) = ctx->r10;
    // 0x8057EA68: bgez        $t2, L_8057EA78
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8057EA6C: or          $a1, $t2, $zero
        ctx->r5 = ctx->r10 | 0;
            goto L_8057EA78;
    }
    // 0x8057EA6C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8057EA70: addiu       $a1, $t2, 0x3C
    ctx->r5 = ADD32(ctx->r10, 0X3C);
    // 0x8057EA74: sw          $a1, 0x2B4($v0)
    MEM_W(0X2B4, ctx->r2) = ctx->r5;
L_8057EA78:
    // 0x8057EA78: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8057EA7C: sll         $t4, $a1, 3
    ctx->r12 = S32(ctx->r5 << 3);
    // 0x8057EA80: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x8057EA84: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8057EA88: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8057EA8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057EA90: jal         0x8057DB50
    // 0x8057EA94: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    func_8057DB50(rdram, ctx);
        goto after_1;
    // 0x8057EA94: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    after_1:
    // 0x8057EA98: b           L_8057EAAC
    // 0x8057EA9C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
        goto L_8057EAAC;
    // 0x8057EA9C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_8057EAA0:
    // 0x8057EAA0: jal         0x8057DBC0
    // 0x8057EAA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057DBC0(rdram, ctx);
        goto after_2;
    // 0x8057EAA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8057EAA8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_8057EAAC:
    // 0x8057EAAC: jal         0x80048F84
    // 0x8057EAB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x8057EAB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8057EAB4: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    // 0x8057EAB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057EABC: lw          $t6, 0x2C8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2C8);
    // 0x8057EAC0: lw          $t5, 0x2D4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X2D4);
    // 0x8057EAC4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8057EAC8: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8057EACC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8057EAD0: jalr        $t9
    // 0x8057EAD4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8057EAD4: nop

    after_4:
    // 0x8057EAD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057EADC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057EAE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8057EAE4: jr          $ra
    // 0x8057EAE8: nop

    return;
    // 0x8057EAE8: nop

;}
RECOMP_FUNC void func_805A62CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A62CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A62D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A62D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A62D8: jal         0x8004700C
    // 0x805A62DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805A62DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805A62E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x805A62E4: jal         0x805A5DF0
    // 0x805A62E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A5DF0(rdram, ctx);
        goto after_1;
    // 0x805A62E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A62EC: jal         0x805A6120
    // 0x805A62F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A6120(rdram, ctx);
        goto after_2;
    // 0x805A62F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805A62F4: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x805A62F8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x805A62FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A6300: lwc1        $f6, 0x274($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X274);
    // 0x805A6304: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805A6308: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805A630C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805A6310: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x805A6314: bc1fl       L_805A636C
    if (!c1cs) {
        // 0x805A6318: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A636C;
    }
    goto skip_0;
    // 0x805A6318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805A631C: jal         0x8002F7AC
    // 0x805A6320: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_8002F7AC(rdram, ctx);
        goto after_3;
    // 0x805A6320: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_3:
    // 0x805A6324: jal         0x8005FE48
    // 0x805A6328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_4;
    // 0x805A6328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A632C: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x805A6330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A6334: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x805A6338: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805A633C: sb          $zero, 0x74($t8)
    MEM_B(0X74, ctx->r24) = 0;
    // 0x805A6340: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x805A6344: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805A6348: jal         0x805A6730
    // 0x805A634C: sb          $zero, 0x75($t0)
    MEM_B(0X75, ctx->r8) = 0;
    func_805A6730(rdram, ctx);
        goto after_5;
    // 0x805A634C: sb          $zero, 0x75($t0)
    MEM_B(0X75, ctx->r8) = 0;
    after_5:
    // 0x805A6350: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805A6354: jal         0x80067BBC
    // 0x805A6358: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x805A6358: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x805A635C: addiu       $a0, $zero, 0x272
    ctx->r4 = ADD32(0, 0X272);
    // 0x805A6360: jal         0x80067818
    // 0x805A6364: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x805A6364: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x805A6368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A636C:
    // 0x805A636C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A6370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805A6374: jr          $ra
    // 0x805A6378: nop

    return;
    // 0x805A6378: nop

;}
RECOMP_FUNC void func_805A757C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A757C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805A7580: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(426, 0X244) << 16);
    // 0x805A7584: addiu       $t6, $t6, 0x7594
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(426, 0X244));
    // 0x805A7588: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805A758C: jr          $ra
    // 0x805A7590: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x805A7590: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80051838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051838: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005183C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80051840: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80051844: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80051848: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005184C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80051850: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80051854: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80051858: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005185C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80051860: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80051864: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80051868: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x8005186C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80051870: beq         $t6, $zero, L_800518CC
    if (ctx->r14 == 0) {
        // 0x80051874: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800518CC;
    }
    // 0x80051874: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80051878: beq         $a2, $zero, L_800518CC
    if (ctx->r6 == 0) {
        // 0x8005187C: addiu       $s6, $zero, 0xA5
        ctx->r22 = ADD32(0, 0XA5);
            goto L_800518CC;
    }
    // 0x8005187C: addiu       $s6, $zero, 0xA5
    ctx->r22 = ADD32(0, 0XA5);
    // 0x80051880: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80051884: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x80051888: lhu         $t7, 0x3C($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X3C);
L_8005188C:
    // 0x8005188C: bnel        $s5, $t7, L_800518AC
    if (ctx->r21 != ctx->r15) {
        // 0x80051890: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_800518AC;
    }
    goto skip_0;
    // 0x80051890: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80051894: jal         0x800517F4
    // 0x80051898: lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X0);
    func_800517F4(rdram, ctx);
        goto after_0;
    // 0x80051898: lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X0);
    after_0:
    // 0x8005189C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800518A0: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800518A4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800518A8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_800518AC:
    // 0x800518AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800518B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800518B4: beql        $a0, $zero, L_800518D0
    if (ctx->r4 == 0) {
        // 0x800518B8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800518D0;
    }
    goto skip_1;
    // 0x800518B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x800518BC: beql        $s2, $zero, L_800518D0
    if (ctx->r18 == 0) {
        // 0x800518C0: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800518D0;
    }
    goto skip_2;
    // 0x800518C0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x800518C4: bnel        $s1, $s6, L_8005188C
    if (ctx->r17 != ctx->r22) {
        // 0x800518C8: lhu         $t7, 0x3C($a0)
        ctx->r15 = MEM_HU(ctx->r4, 0X3C);
            goto L_8005188C;
    }
    goto skip_3;
    // 0x800518C8: lhu         $t7, 0x3C($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X3C);
    skip_3:
L_800518CC:
    // 0x800518CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800518D0:
    // 0x800518D0: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800518D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800518D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800518DC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800518E0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800518E4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800518E8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800518EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800518F0: jr          $ra
    // 0x800518F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800518F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80461F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461F3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80461F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80461F44: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80461F48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80461F4C: jal         0x80461D10
    // 0x80461F50: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80461D10(rdram, ctx);
        goto after_0;
    // 0x80461F50: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80461F54: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80461F58: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A44) << 16);
    // 0x80461F5C: lwc1        $f4, 0x3FD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A44));
    // 0x80461F60: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80461F64: lui         $a1, 0x3C03
    ctx->r5 = S32(0X3C03 << 16);
    // 0x80461F68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80461F6C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80461F70: ori         $a1, $a1, 0x126F
    ctx->r5 = ctx->r5 | 0X126F;
    // 0x80461F74: lui         $a2, 0x3B03
    ctx->r6 = S32(0X3B03 << 16);
    // 0x80461F78: bc1f        L_80461F9C
    if (!c1cs) {
        // 0x80461F7C: nop
    
            goto L_80461F9C;
    }
    // 0x80461F7C: nop

    // 0x80461F80: lui         $a1, 0x3BE5
    ctx->r5 = S32(0X3BE5 << 16);
    // 0x80461F84: lui         $a2, 0x3BC4
    ctx->r6 = S32(0X3BC4 << 16);
    // 0x80461F88: ori         $a2, $a2, 0x9BA6
    ctx->r6 = ctx->r6 | 0X9BA6;
    // 0x80461F8C: jal         0x80461D60
    // 0x80461F90: ori         $a1, $a1, 0x6042
    ctx->r5 = ctx->r5 | 0X6042;
    func_80461D60(rdram, ctx);
        goto after_1;
    // 0x80461F90: ori         $a1, $a1, 0x6042
    ctx->r5 = ctx->r5 | 0X6042;
    after_1:
    // 0x80461F94: b           L_80461FA8
    // 0x80461F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80461FA8;
    // 0x80461F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80461F9C:
    // 0x80461F9C: jal         0x80461D60
    // 0x80461FA0: ori         $a2, $a2, 0x126F
    ctx->r6 = ctx->r6 | 0X126F;
    func_80461D60(rdram, ctx);
        goto after_2;
    // 0x80461FA0: ori         $a2, $a2, 0x126F
    ctx->r6 = ctx->r6 | 0X126F;
    after_2:
    // 0x80461FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80461FA8:
    // 0x80461FA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80461FAC: jr          $ra
    // 0x80461FB0: nop

    return;
    // 0x80461FB0: nop

;}
RECOMP_FUNC void func_80681514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681514: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80681518: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(550, 0XB80) << 16);
    // 0x8068151C: addiu       $t6, $t6, 0xF90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(550, 0XB80));
    // 0x80681520: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80681524: jr          $ra
    // 0x80681528: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80681528: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80067B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067B20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067B24: jal         0x80071D40
    // 0x80067B28: nop

    func_80071D40(rdram, ctx);
        goto after_0;
    // 0x80067B28: nop

    after_0:
    // 0x80067B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067B34: jr          $ra
    // 0x80067B38: nop

    return;
    // 0x80067B38: nop

;}
RECOMP_FUNC void func_8078A084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078A088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078A08C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8078A090: jal         0x80045A34
    // 0x8078A094: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8078A094: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x8078A098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078A09C: bne         $v0, $zero, L_8078A0AC
    if (ctx->r2 != 0) {
        // 0x8078A0A0: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8078A0AC;
    }
    // 0x8078A0A0: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8078A0A4: b           L_8078A0B8
    // 0x8078A0A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8078A0B8;
    // 0x8078A0A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078A0AC:
    // 0x8078A0AC: jal         0x8078A06C
    // 0x8078A0B0: nop

    func_8078A06C(rdram, ctx);
        goto after_1;
    // 0x8078A0B0: nop

    after_1:
    // 0x8078A0B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8078A0B8:
    // 0x8078A0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078A0BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078A0C0: jr          $ra
    // 0x8078A0C4: nop

    return;
    // 0x8078A0C4: nop

;}
RECOMP_FUNC void func_8076D250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D250: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8076D254: beq         $v0, $zero, L_8076D264
    if (ctx->r2 == 0) {
        // 0x8076D258: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8076D264;
    }
    // 0x8076D258: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8076D25C: b           L_8076D2A8
    // 0x8076D260: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
        goto L_8076D2A8;
    // 0x8076D260: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
L_8076D264:
    // 0x8076D264: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8076D268: lui         $t1, 0x8077
    ctx->r9 = S32(RELOC_HI16(766, 0X3970) << 16);
    // 0x8076D26C: addiu       $t1, $t1, 0x160
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(766, 0X3970));
    // 0x8076D270: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8076D274: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8076D278: bne         $at, $zero, L_8076D290
    if (ctx->r1 != 0) {
        // 0x8076D27C: sw          $v0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r2;
            goto L_8076D290;
    }
    // 0x8076D27C: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x8076D280: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8076D284: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
    // 0x8076D288: jr          $ra
    // 0x8076D28C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8076D28C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8076D290:
    // 0x8076D290: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x8076D294: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x8076D298: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8076D29C: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    // 0x8076D2A0: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x8076D2A4: sw          $t3, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r11;
L_8076D2A8:
    // 0x8076D2A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8076D2AC: jr          $ra
    // 0x8076D2B0: nop

    return;
    // 0x8076D2B0: nop

;}
RECOMP_FUNC void func_807A6934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6934: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A6938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A693C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A6940: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6944: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A6948: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x807A694C: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x807A6950: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x807A6954: jal         0x80065ABC
    // 0x807A6958: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x807A6958: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    after_0:
    // 0x807A695C: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x807A6960: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x807A6964: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x807A6968: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X15A8) << 16);
    // 0x807A696C: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x807A6970: lwc1        $f10, 0x72A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X15A8));
    // 0x807A6974: lwc1        $f16, 0xC4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x807A6978: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807A697C: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x807A6980: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807A6984: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x807A6988: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x807A698C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807A6990: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x807A6994: jal         0x800659EC
    // 0x807A6998: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x807A6998: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x807A699C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x807A69A0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X15AC) << 16);
    // 0x807A69A4: lwc1        $f10, 0x72AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X15AC));
    // 0x807A69A8: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x807A69AC: jal         0x800659EC
    // 0x807A69B0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_800659EC(rdram, ctx);
        goto after_2;
    // 0x807A69B0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x807A69B4: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x807A69B8: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X15B0) << 16);
    // 0x807A69BC: lwc1        $f18, 0x72B0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X15B0));
    // 0x807A69C0: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x807A69C4: jal         0x800659EC
    // 0x807A69C8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    func_800659EC(rdram, ctx);
        goto after_3;
    // 0x807A69C8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_3:
    // 0x807A69CC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x807A69D0: jal         0x807A5E50
    // 0x807A69D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A5E50(rdram, ctx);
        goto after_4;
    // 0x807A69D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807A69D8: beql        $v0, $zero, L_807A69EC
    if (ctx->r2 == 0) {
        // 0x807A69DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807A69EC;
    }
    goto skip_0;
    // 0x807A69DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807A69E0: jal         0x800447C8
    // 0x807A69E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x807A69E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807A69E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A69EC:
    // 0x807A69EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A69F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A69F4: jr          $ra
    // 0x807A69F8: nop

    return;
    // 0x807A69F8: nop

;}
RECOMP_FUNC void func_805304A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805304A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805304A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805304A8: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x805304AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805304B0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x805304B4: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x805304B8: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x805304BC: sw          $t7, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r15;
    // 0x805304C0: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    // 0x805304C4: jal         0x80530834
    // 0x805304C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80530834(rdram, ctx);
        goto after_0;
    // 0x805304C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x805304CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805304D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805304D4: jr          $ra
    // 0x805304D8: nop

    return;
    // 0x805304D8: nop

;}
RECOMP_FUNC void func_80450818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450818: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045081C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450820: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450824: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450828: addiu       $t7, $zero, -0x64
    ctx->r15 = ADD32(0, -0X64);
    // 0x8045082C: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80450830: lw          $t6, 0x6A28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6A28);
    // 0x80450834: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80450838: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8045083C: sw          $zero, 0x6A20($v0)
    MEM_W(0X6A20, ctx->r2) = 0;
    // 0x80450840: sw          $t7, 0x6A28($v0)
    MEM_W(0X6A28, ctx->r2) = ctx->r15;
    // 0x80450844: sw          $t8, 0x6A2C($v0)
    MEM_W(0X6A2C, ctx->r2) = ctx->r24;
    // 0x80450848: sw          $t9, 0x6A30($v0)
    MEM_W(0X6A30, ctx->r2) = ctx->r25;
    // 0x8045084C: sw          $t6, 0x6A24($v0)
    MEM_W(0X6A24, ctx->r2) = ctx->r14;
    // 0x80450850: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80450854: jal         0x8044EFA0
    // 0x80450858: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80450858: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8045085C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80450860: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80450864: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450868: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8045086C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80450870: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    // 0x80450874: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450878: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8045087C: sw          $zero, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = 0;
    // 0x80450880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80450884: jal         0x80457164
    // 0x80450888: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80457164(rdram, ctx);
        goto after_1;
    // 0x80450888: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x8045088C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80450890: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80450894: jr          $ra
    // 0x80450898: nop

    return;
    // 0x80450898: nop

;}
RECOMP_FUNC void func_80743064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80743064: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80743068: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8074306C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80743070: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80743074: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80743078: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8074307C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80743080: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80743084: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80743088: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8074308C: jr          $ra
    // 0x80743090: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80743090: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80743094: nop

    // 0x80743098: nop

    // 0x8074309C: nop

;}
RECOMP_FUNC void pad_push_also(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FB34: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8007FB38: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8007FB3C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8007FB40: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x8007FB44: xor         $v0, $t7, $a1
    ctx->r2 = ctx->r15 ^ ctx->r5;
    // 0x8007FB48: jr          $ra
    // 0x8007FB4C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8007FB4C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80709CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709CB8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80709CBC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80709CC0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80709CC4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80709CC8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80709CCC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80709CD0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80709CD4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80709CD8: lui         $t1, 0x8071
    ctx->r9 = S32(RELOC_HI16(718, 0X1510) << 16);
    // 0x80709CDC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80709CE0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80709CE4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80709CE8: lw          $t1, -0x5910($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(718, 0X1510));
    // 0x80709CEC: jr          $ra
    // 0x80709CF0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80709CF0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8073EE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EE40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073EE44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EE48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8073EE4C: jal         0x80047090
    // 0x8073EE50: addiu       $a0, $zero, 0x4641
    ctx->r4 = ADD32(0, 0X4641);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8073EE50: addiu       $a0, $zero, 0x4641
    ctx->r4 = ADD32(0, 0X4641);
    after_0:
    // 0x8073EE54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073EE58: lui         $at, 0x4641
    ctx->r1 = S32(0X4641 << 16);
    // 0x8073EE5C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8073EE60: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8073EE64: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8073EE68: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8073EE6C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8073EE70: jal         0x8004613C
    // 0x8073EE74: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8073EE74: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x8073EE78: bne         $v0, $zero, L_8073EE88
    if (ctx->r2 != 0) {
        // 0x8073EE7C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8073EE88;
    }
    // 0x8073EE7C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8073EE80: b           L_8073EEC0
    // 0x8073EE84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073EEC0;
    // 0x8073EE84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073EE88:
    // 0x8073EE88: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x8073EE8C: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x8073EE90: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8073EE94: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x8073EE98: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8073EE9C: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x8073EEA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8073EEA4: jal         0x80047F9C
    // 0x8073EEA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8073EEA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8073EEAC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8073EEB0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8073EEB4: jal         0x8005FDC4
    // 0x8073EEB8: sb          $t2, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r10;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x8073EEB8: sb          $t2, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r10;
    after_3:
    // 0x8073EEBC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8073EEC0:
    // 0x8073EEC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EEC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073EEC8: jr          $ra
    // 0x8073EECC: nop

    return;
    // 0x8073EECC: nop

;}
RECOMP_FUNC void func_8052E0E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052E0E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8052E0E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052E0EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8052E0F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8052E0F4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8052E0F8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8052E0FC: jal         0x8052DE04
    // 0x8052E100: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_8052DE04(rdram, ctx);
        goto after_0;
    // 0x8052E100: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8052E104: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8052E108: jal         0x8052DF90
    // 0x8052E10C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8052DF90(rdram, ctx);
        goto after_1;
    // 0x8052E10C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8052E110: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8052E114: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8052E118: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8052E11C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8052E120: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8052E124: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8052E128: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8052E12C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8052E130: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8052E134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052E138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8052E13C: jr          $ra
    // 0x8052E140: nop

    return;
    // 0x8052E140: nop

;}
RECOMP_FUNC void func_8003E304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E304: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003E308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E30C: lbu         $t7, 0x165($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X165);
    // 0x8003E310: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8003E314: addiu       $t6, $zero, 0x67
    ctx->r14 = ADD32(0, 0X67);
    // 0x8003E318: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003E31C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8003E320: beq         $t7, $at, L_8003E344
    if (ctx->r15 == ctx->r1) {
        // 0x8003E324: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8003E344;
    }
    // 0x8003E324: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8003E328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003E32C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8003E330: jal         0x8003D894
    // 0x8003E334: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8003D894(rdram, ctx);
        goto after_0;
    // 0x8003E334: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003E338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003E33C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E340: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
L_8003E344:
    // 0x8003E344: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8003E348: addiu       $t8, $t8, -0x1E08
    ctx->r24 = ADD32(ctx->r24, -0X1E08);
    // 0x8003E34C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8003E350: sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
    // 0x8003E354: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003E358: jal         0x8003E120
    // 0x8003E35C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8003E120(rdram, ctx);
        goto after_1;
    // 0x8003E35C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8003E360: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003E364: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003E368: lwc1        $f0, 0x240($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X240);
    // 0x8003E36C: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003E370: lwc1        $f8, 0x7C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003E374: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003E378: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003E37C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8003E380: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8003E384: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003E388: addiu       $t9, $t9, -0x71F4
    ctx->r25 = ADD32(ctx->r25, -0X71F4);
    // 0x8003E38C: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x8003E390: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x8003E394: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8003E398: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x8003E39C: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8003E3A0: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8003E3A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8003E3A8: lw          $t1, 0x48($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X48);
    // 0x8003E3AC: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x8003E3B0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8003E3B4: lh          $t3, 0x10($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X10);
    // 0x8003E3B8: beql        $t3, $zero, L_8003E3C8
    if (ctx->r11 == 0) {
        // 0x8003E3BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003E3C8;
    }
    goto skip_0;
    // 0x8003E3BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003E3C0: sw          $t4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r12;
    // 0x8003E3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E3C8:
    // 0x8003E3C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003E3CC: jr          $ra
    // 0x8003E3D0: nop

    return;
    // 0x8003E3D0: nop

;}
RECOMP_FUNC void func_8078D750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D750: jr          $ra
    // 0x8078D754: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8078D754: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006DAF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DAF4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8006DAF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006DAFC: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8006DB00: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x8006DB04: lbu         $t6, 0xA($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XA);
    // 0x8006DB08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006DB0C: andi        $a1, $v0, 0x3
    ctx->r5 = ctx->r2 & 0X3;
    // 0x8006DB10: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x8006DB14: blez        $v0, L_8006DC2C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006DB18: sb          $t7, 0xA($sp)
        MEM_B(0XA, ctx->r29) = ctx->r15;
            goto L_8006DC2C;
    }
    // 0x8006DB18: sb          $t7, 0xA($sp)
    MEM_B(0XA, ctx->r29) = ctx->r15;
    // 0x8006DB1C: beq         $a1, $zero, L_8006DB64
    if (ctx->r5 == 0) {
        // 0x8006DB20: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8006DB64;
    }
    // 0x8006DB20: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8006DB24:
    // 0x8006DB24: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8006DB28: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8006DB2C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006DB30: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8006DB34: lbu         $t9, 0x6($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X6);
    // 0x8006DB38: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x8006DB3C: sb          $t0, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r8;
    // 0x8006DB40: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8006DB44: bne         $t1, $t2, L_8006DB54
    if (ctx->r9 != ctx->r10) {
        // 0x8006DB48: nop
    
            goto L_8006DB54;
    }
    // 0x8006DB48: nop

    // 0x8006DB4C: b           L_8006DC30
    // 0x8006DB50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8006DC30;
    // 0x8006DB50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8006DB54:
    // 0x8006DB54: bne         $a0, $a2, L_8006DB24
    if (ctx->r4 != ctx->r6) {
        // 0x8006DB58: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8006DB24;
    }
    // 0x8006DB58: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8006DB5C: beql        $a2, $v0, L_8006DC30
    if (ctx->r6 == ctx->r2) {
        // 0x8006DB60: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006DC30;
    }
    goto skip_0;
    // 0x8006DB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_8006DB64:
    // 0x8006DB64: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8006DB68: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8006DB6C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8006DB70: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8006DB74: lbu         $t4, 0x6($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X6);
    // 0x8006DB78: andi        $t5, $t4, 0xFF03
    ctx->r13 = ctx->r12 & 0XFF03;
    // 0x8006DB7C: sb          $t5, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r13;
    // 0x8006DB80: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8006DB84: bnel        $t6, $t7, L_8006DB98
    if (ctx->r14 != ctx->r15) {
        // 0x8006DB88: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_8006DB98;
    }
    goto skip_1;
    // 0x8006DB88: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_1:
    // 0x8006DB8C: b           L_8006DC30
    // 0x8006DB90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8006DC30;
    // 0x8006DB90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006DB94: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_8006DB98:
    // 0x8006DB98: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8006DB9C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8006DBA0: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8006DBA4: lbu         $t9, 0x6($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X6);
    // 0x8006DBA8: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x8006DBAC: sb          $t0, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r8;
    // 0x8006DBB0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8006DBB4: bnel        $t1, $t2, L_8006DBC8
    if (ctx->r9 != ctx->r10) {
        // 0x8006DBB8: lw          $t3, 0x10($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X10);
            goto L_8006DBC8;
    }
    goto skip_2;
    // 0x8006DBB8: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    skip_2:
    // 0x8006DBBC: b           L_8006DC30
    // 0x8006DBC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8006DC30;
    // 0x8006DBC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006DBC4: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
L_8006DBC8:
    // 0x8006DBC8: lw          $t7, 0x8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8);
    // 0x8006DBCC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8006DBD0: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8006DBD4: lbu         $t4, 0x6($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X6);
    // 0x8006DBD8: andi        $t5, $t4, 0xFF03
    ctx->r13 = ctx->r12 & 0XFF03;
    // 0x8006DBDC: sb          $t5, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r13;
    // 0x8006DBE0: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8006DBE4: bnel        $t6, $t7, L_8006DBF8
    if (ctx->r14 != ctx->r15) {
        // 0x8006DBE8: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_8006DBF8;
    }
    goto skip_3;
    // 0x8006DBE8: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_3:
    // 0x8006DBEC: b           L_8006DC30
    // 0x8006DBF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8006DC30;
    // 0x8006DBF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006DBF4: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_8006DBF8:
    // 0x8006DBF8: lw          $t2, 0x8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8);
    // 0x8006DBFC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8006DC00: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8006DC04: lbu         $t9, 0x6($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X6);
    // 0x8006DC08: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x8006DC0C: sb          $t0, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r8;
    // 0x8006DC10: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x8006DC14: bne         $t1, $t2, L_8006DC24
    if (ctx->r9 != ctx->r10) {
        // 0x8006DC18: nop
    
            goto L_8006DC24;
    }
    // 0x8006DC18: nop

    // 0x8006DC1C: b           L_8006DC30
    // 0x8006DC20: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8006DC30;
    // 0x8006DC20: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8006DC24:
    // 0x8006DC24: bne         $a2, $v0, L_8006DB64
    if (ctx->r6 != ctx->r2) {
        // 0x8006DC28: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8006DB64;
    }
    // 0x8006DC28: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8006DC2C:
    // 0x8006DC2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006DC30:
    // 0x8006DC30: jr          $ra
    // 0x8006DC34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006DC34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80066428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066428: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8006642C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80066430: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80066434: swc1        $f12, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f12.u32l;
    // 0x80066438: swc1        $f14, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f14.u32l;
    // 0x8006643C: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80066440: jr          $ra
    // 0x80066444: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80066444: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_807C6810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6810: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(916, 0X148) << 16);
    // 0x807C6814: addiu       $t6, $t6, 0x6958
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(916, 0X148));
    // 0x807C6818: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807C681C: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(916, 0X20) << 16);
    // 0x807C6820: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x807C6824: sw          $t6, -0x71E4($at)
    MEM_W(-0X71E4, ctx->r1) = ctx->r14;
    // 0x807C6828: jr          $ra
    // 0x807C682C: addiu       $v0, $v0, 0x6830
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(916, 0X20));
    return;
    // 0x807C682C: addiu       $v0, $v0, 0x6830
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(916, 0X20));
;}
RECOMP_FUNC void func_8043B064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B064: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8043B068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043B06C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043B070: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    // 0x8043B074: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8043B078: jal         0x8004700C
    // 0x8043B07C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043B07C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8043B080: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8043B084: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8043B088: beq         $v0, $zero, L_8043B134
    if (ctx->r2 == 0) {
        // 0x8043B08C: addiu       $v1, $a1, 0x14
        ctx->r3 = ADD32(ctx->r5, 0X14);
            goto L_8043B134;
    }
    // 0x8043B08C: addiu       $v1, $a1, 0x14
    ctx->r3 = ADD32(ctx->r5, 0X14);
    // 0x8043B090: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8043B094: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8043B098: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8043B09C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8043B0A0: jal         0x80047AB8
    // 0x8043B0A4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x8043B0A4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x8043B0A8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8043B0AC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8043B0B0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8043B0B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8043B0B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8043B0BC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_8043B0C0:
    // 0x8043B0C0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8043B0C4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8043B0C8: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8043B0CC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8043B0D0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043B0D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8043B0D8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8043B0DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8043B0E0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8043B0E4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8043B0E8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8043B0EC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8043B0F0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8043B0F4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8043B0F8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8043B0FC: nop

    // 0x8043B100: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8043B104: add.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8043B108: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8043B10C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8043B110: nop

    // 0x8043B114: bc1f        L_8043B12C
    if (!c1cs) {
        // 0x8043B118: nop
    
            goto L_8043B12C;
    }
    // 0x8043B118: nop

    // 0x8043B11C: jal         0x8002FC3C
    // 0x8043B120: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8002FC3C(rdram, ctx);
        goto after_2;
    // 0x8043B120: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x8043B124: b           L_8043B138
    // 0x8043B128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8043B138;
    // 0x8043B128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043B12C:
    // 0x8043B12C: bnel        $a0, $a1, L_8043B0C0
    if (ctx->r4 != ctx->r5) {
        // 0x8043B130: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_8043B0C0;
    }
    goto skip_0;
    // 0x8043B130: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    skip_0:
L_8043B134:
    // 0x8043B134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043B138:
    // 0x8043B138: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8043B13C: jr          $ra
    // 0x8043B140: nop

    return;
    // 0x8043B140: nop

;}
RECOMP_FUNC void func_80673964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673964: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80673968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067396C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80673970: jal         0x80673808
    // 0x80673974: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80673808(rdram, ctx);
        goto after_0;
    // 0x80673974: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80673978: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8067397C: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80673980: jal         0x80065ABC
    // 0x80673984: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x80673984: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_1:
    // 0x80673988: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8067398C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673990: jal         0x80049D74
    // 0x80673994: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x80673994: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_2:
    // 0x80673998: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8067399C: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x806739A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806739A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806739A8: jal         0x8004D150
    // 0x806739AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x806739AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x806739B0: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x806739B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806739B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806739BC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806739C0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806739C4: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x806739C8: lbu         $t9, 0x2C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2C);
    // 0x806739CC: beql        $t9, $zero, L_80673A6C
    if (ctx->r25 == 0) {
        // 0x806739D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80673A6C;
    }
    goto skip_0;
    // 0x806739D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806739D4: jal         0x8004D618
    // 0x806739D8: addiu       $a2, $a2, -0x2BEC
    ctx->r6 = ADD32(ctx->r6, -0X2BEC);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x806739D8: addiu       $a2, $a2, -0x2BEC
    ctx->r6 = ADD32(ctx->r6, -0X2BEC);
    after_4:
    // 0x806739DC: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x806739E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806739E4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806739E8: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x806739EC: jal         0x8004A97C
    // 0x806739F0: lhu         $a0, 0x18($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X18);
    func_8004A97C(rdram, ctx);
        goto after_5;
    // 0x806739F0: lhu         $a0, 0x18($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X18);
    after_5:
    // 0x806739F4: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C34) << 16);
    // 0x806739F8: lwc1        $f4, 0x4C14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C34));
    // 0x806739FC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80673A00: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C38) << 16);
    // 0x80673A04: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80673A08: nop

    // 0x80673A0C: bc1t        L_80673A38
    if (c1cs) {
        // 0x80673A10: nop
    
            goto L_80673A38;
    }
    // 0x80673A10: nop

    // 0x80673A14: lwc1        $f6, 0x4C18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C38));
    // 0x80673A18: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80673A1C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80673A20: nop

    // 0x80673A24: bc1t        L_80673A38
    if (c1cs) {
        // 0x80673A28: nop
    
            goto L_80673A38;
    }
    // 0x80673A28: nop

    // 0x80673A2C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80673A30: b           L_80673A48
    // 0x80673A34: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
        goto L_80673A48;
    // 0x80673A34: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
L_80673A38:
    // 0x80673A38: jal         0x800659EC
    // 0x80673A3C: nop

    func_800659EC(rdram, ctx);
        goto after_6;
    // 0x80673A3C: nop

    after_6:
    // 0x80673A40: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80673A44: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
L_80673A48:
    // 0x80673A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673A4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80673A50: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80673A54: jal         0x80673F0C
    // 0x80673A58: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_80673F0C(rdram, ctx);
        goto after_7;
    // 0x80673A58: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x80673A5C: jal         0x80673590
    // 0x80673A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80673590(rdram, ctx);
        goto after_8;
    // 0x80673A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80673A64: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80673A68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80673A6C:
    // 0x80673A6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80673A70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80673A74: jr          $ra
    // 0x80673A78: nop

    return;
    // 0x80673A78: nop

;}
RECOMP_FUNC void func_80074E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074E04: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80074E08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074E0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074E10: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80074E14: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80074E18: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80074E1C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80074E20: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80074E24: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80074E28: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80074E2C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80074E30: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074E34: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x80074E38: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80074E3C: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80074E40: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80074E44: addiu       $s1, $s1, -0x7B30
    ctx->r17 = ADD32(ctx->r17, -0X7B30);
    // 0x80074E48: addiu       $s2, $s2, -0x53C0
    ctx->r18 = ADD32(ctx->r18, -0X53C0);
    // 0x80074E4C: addiu       $s4, $s0, 0x58
    ctx->r20 = ADD32(ctx->r16, 0X58);
    // 0x80074E50: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x80074E54: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x80074E58: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80074E5C: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x80074E60: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
L_80074E64:
    // 0x80074E64: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80074E68: bnel        $at, $zero, L_80074ECC
    if (ctx->r1 != 0) {
        // 0x80074E6C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80074ECC;
    }
    goto skip_0;
    // 0x80074E6C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
    // 0x80074E70: lw          $t7, 0x60($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X60);
    // 0x80074E74: bnel        $t7, $zero, L_80074ECC
    if (ctx->r15 != 0) {
        // 0x80074E78: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80074ECC;
    }
    goto skip_1;
    // 0x80074E78: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_1:
    // 0x80074E7C: jal         0x8008B920
    // 0x80074E80: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80074E80: nop

    after_0:
    // 0x80074E84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074E88: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80074E8C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074E90: jal         0x80082D88
    // 0x80074E94: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80074E94: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_1:
    // 0x80074E98: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80074E9C: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x80074EA0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80074EA4: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x80074EA8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074EAC: jal         0x80082C88
    // 0x80074EB0: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_2;
    // 0x80074EB0: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_2:
    // 0x80074EB4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074EB8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80074EBC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80074EC0: jal         0x80082C88
    // 0x80074EC4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_3;
    // 0x80074EC4: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_3:
    // 0x80074EC8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80074ECC:
    // 0x80074ECC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80074ED0: jal         0x800824B0
    // 0x80074ED4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80074ED4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_4:
    // 0x80074ED8: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80074EDC: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    // 0x80074EE0: beql        $a0, $s6, L_80074F04
    if (ctx->r4 == ctx->r22) {
        // 0x80074EE4: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_80074F04;
    }
    goto skip_2;
    // 0x80074EE4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x80074EE8: beql        $a0, $s7, L_80074FDC
    if (ctx->r4 == ctx->r23) {
        // 0x80074EEC: or          $s3, $s6, $zero
        ctx->r19 = ctx->r22 | 0;
            goto L_80074FDC;
    }
    goto skip_3;
    // 0x80074EEC: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
    skip_3:
    // 0x80074EF0: beq         $a0, $fp, L_80074FC8
    if (ctx->r4 == ctx->r30) {
        // 0x80074EF4: nop
    
            goto L_80074FC8;
    }
    // 0x80074EF4: nop

    // 0x80074EF8: b           L_80074FDC
    // 0x80074EFC: nop

        goto L_80074FDC;
    // 0x80074EFC: nop

    // 0x80074F00: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_80074F04:
    // 0x80074F04: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80074F08: bne         $at, $zero, L_80074F5C
    if (ctx->r1 != 0) {
        // 0x80074F0C: nop
    
            goto L_80074F5C;
    }
    // 0x80074F0C: nop

    // 0x80074F10: jal         0x8008B920
    // 0x80074F14: nop

    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x80074F14: nop

    after_5:
    // 0x80074F18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074F1C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80074F20: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074F24: jal         0x80082D88
    // 0x80074F28: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_6;
    // 0x80074F28: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_6:
    // 0x80074F2C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80074F30: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x80074F34: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80074F38: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x80074F3C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074F40: jal         0x80082C88
    // 0x80074F44: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_7;
    // 0x80074F44: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_7:
    // 0x80074F48: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074F4C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80074F50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80074F54: jal         0x80082C88
    // 0x80074F58: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_8;
    // 0x80074F58: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_8:
L_80074F5C:
    // 0x80074F5C: jal         0x80074AE8
    // 0x80074F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80074AE8(rdram, ctx);
        goto after_9;
    // 0x80074F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80074F64: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80074F68: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80074F6C: bne         $at, $zero, L_80074FDC
    if (ctx->r1 != 0) {
        // 0x80074F70: nop
    
            goto L_80074FDC;
    }
    // 0x80074F70: nop

    // 0x80074F74: jal         0x8008B920
    // 0x80074F78: nop

    osGetTime_recomp(rdram, ctx);
        goto after_10;
    // 0x80074F78: nop

    after_10:
    // 0x80074F7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074F80: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80074F84: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074F88: jal         0x80082D88
    // 0x80074F8C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ll_mul_recomp(rdram, ctx);
        goto after_11;
    // 0x80074F8C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_11:
    // 0x80074F90: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80074F94: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x80074F98: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80074F9C: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x80074FA0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80074FA4: jal         0x80082C88
    // 0x80074FA8: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_12;
    // 0x80074FA8: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_12:
    // 0x80074FAC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80074FB0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80074FB4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80074FB8: jal         0x80082C88
    // 0x80074FBC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_13;
    // 0x80074FBC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_13:
    // 0x80074FC0: b           L_80074FDC
    // 0x80074FC4: nop

        goto L_80074FDC;
    // 0x80074FC4: nop

L_80074FC8:
    // 0x80074FC8: jal         0x80074C64
    // 0x80074FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80074C64(rdram, ctx);
        goto after_14;
    // 0x80074FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80074FD0: b           L_80074FDC
    // 0x80074FD4: nop

        goto L_80074FDC;
    // 0x80074FD4: nop

    // 0x80074FD8: or          $s3, $s6, $zero
    ctx->r19 = ctx->r22 | 0;
L_80074FDC:
    // 0x80074FDC: beql        $s3, $zero, L_80074E64
    if (ctx->r19 == 0) {
        // 0x80074FE0: lw          $t6, 0x0($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X0);
            goto L_80074E64;
    }
    goto skip_4;
    // 0x80074FE0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    skip_4:
    // 0x80074FE4: lw          $a0, 0x78($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X78);
    // 0x80074FE8: jal         0x80075170
    // 0x80074FEC: addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    func_80075170(rdram, ctx);
        goto after_15;
    // 0x80074FEC: addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    after_15:
    // 0x80074FF0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80074FF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074FF8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80074FFC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80075000: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80075004: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80075008: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007500C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80075010: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80075014: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80075018: jr          $ra
    // 0x8007501C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8007501C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_805278CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805278CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805278D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805278D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805278D8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x805278DC: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x805278E0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805278E4: jal         0x80067BBC
    // 0x805278E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805278E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x805278EC: addiu       $a0, $zero, 0x9B
    ctx->r4 = ADD32(0, 0X9B);
    // 0x805278F0: jal         0x80067818
    // 0x805278F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805278F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805278F8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x805278FC: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6188) << 16);
    // 0x80527900: lwc1        $f4, -0x3F78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6188));
    // 0x80527904: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x80527908: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052790C: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(327, 0X5670) << 16);
    // 0x80527910: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(327, 0X5688) << 16);
    // 0x80527914: lui         $t0, 0x8052
    ctx->r8 = S32(RELOC_HI16(327, 0X1A5C) << 16);
    // 0x80527918: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8052791C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80527920: addiu       $t8, $t8, -0x4A90
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(327, 0X5670));
    // 0x80527924: addiu       $t9, $t9, -0x4A78
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(327, 0X5688));
    // 0x80527928: addiu       $t0, $t0, 0x795C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(327, 0X1A5C));
    // 0x8052792C: sw          $t6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r14;
    // 0x80527930: sw          $t7, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r15;
    // 0x80527934: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x80527938: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8052793C: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x80527940: sw          $t0, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r8;
    // 0x80527944: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80527948: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x8052794C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80527950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527954: jr          $ra
    // 0x80527958: nop

    return;
    // 0x80527958: nop

;}
RECOMP_FUNC void func_8001CB64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CB64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001CB68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CB6C: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x8001CB70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001CB74: addiu       $t7, $t7, -0x3890
    ctx->r15 = ADD32(ctx->r15, -0X3890);
    // 0x8001CB78: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8001CB7C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8001CB80: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8001CB84: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8001CB88: jal         0x8001C648
    // 0x8001CB8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001C648(rdram, ctx);
        goto after_0;
    // 0x8001CB8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001CB90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001CB94: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x8001CB98: addiu       $t8, $t8, -0x34CC
    ctx->r24 = ADD32(ctx->r24, -0X34CC);
    // 0x8001CB9C: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x8001CBA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CBA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001CBA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001CBAC: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x8001CBB0: jr          $ra
    // 0x8001CBB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001CBB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80671E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671E18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80671E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80671E20: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80671E24: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80671E28: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80671E2C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80671E30: jal         0x80671D4C
    // 0x80671E34: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x80671E34: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80671E38: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80671E3C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80671E40: lw          $t6, 0x1E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1E0);
    // 0x80671E44: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80671E48: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80671E4C: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x80671E50: bne         $at, $zero, L_80671E70
    if (ctx->r1 != 0) {
        // 0x80671E54: sw          $t7, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r15;
            goto L_80671E70;
    }
    // 0x80671E54: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x80671E58: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80671E5C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80671E60: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80671E64: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80671E68: jal         0x80672C80
    // 0x80671E6C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    func_80672C80(rdram, ctx);
        goto after_1;
    // 0x80671E6C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    after_1:
L_80671E70:
    // 0x80671E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80671E74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80671E78: jr          $ra
    // 0x80671E7C: nop

    return;
    // 0x80671E7C: nop

;}
RECOMP_FUNC void func_805D17F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D17F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D17F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D17FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D1800: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805D1804: jal         0x80047090
    // 0x805D1808: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805D1808: lhu         $a0, 0x1E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1E);
    after_0:
    // 0x805D180C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805D1810: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x805D1814: beq         $v0, $at, L_805D1854
    if (ctx->r2 == ctx->r1) {
        // 0x805D1818: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805D1854;
    }
    // 0x805D1818: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805D181C: lhu         $t6, 0x1E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1E);
    // 0x805D1820: lw          $a1, 0x3C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X3C);
    // 0x805D1824: lw          $a2, 0x40($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X40);
    // 0x805D1828: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x805D182C: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x805D1830: or          $a0, $t8, $v1
    ctx->r4 = ctx->r24 | ctx->r3;
    // 0x805D1834: jal         0x8004613C
    // 0x805D1838: lw          $a3, 0x44($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X44);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x805D1838: lw          $a3, 0x44($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X44);
    after_1:
    // 0x805D183C: beq         $v0, $zero, L_805D1854
    if (ctx->r2 == 0) {
        // 0x805D1840: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805D1854;
    }
    // 0x805D1840: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805D1844: jal         0x80044194
    // 0x805D1848: nop

    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805D1848: nop

    after_2:
    // 0x805D184C: b           L_805D1858
    // 0x805D1850: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805D1858;
    // 0x805D1850: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805D1854:
    // 0x805D1854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D1858:
    // 0x805D1858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D185C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D1860: jr          $ra
    // 0x805D1864: nop

    return;
    // 0x805D1864: nop

;}
RECOMP_FUNC void func_806990DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806990DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806990E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806990E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806990E8: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x806990EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806990F0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806990F4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x806990F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806990FC: jal         0x80048F84
    // 0x80699100: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80699100: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80699104: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80699108: jal         0x80048F84
    // 0x8069910C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8069910C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80699110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80699114: jal         0x80698F2C
    // 0x80699118: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    func_80698F2C(rdram, ctx);
        goto after_2;
    // 0x80699118: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    after_2:
    // 0x8069911C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80699120: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(556, 0X59C) << 16);
    // 0x80699124: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80699128: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8069912C: lbu         $t0, 0x2C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2C);
    // 0x80699130: beql        $t0, $zero, L_80699174
    if (ctx->r8 == 0) {
        // 0x80699134: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80699174;
    }
    goto skip_0;
    // 0x80699134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80699138: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x8069913C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80699140: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80699144: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80699148: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8069914C: lwc1        $f4, -0x6D44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(556, 0X59C));
    // 0x80699150: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80699154: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80699158: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8069915C: jal         0x80067BBC
    // 0x80699160: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x80699160: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x80699164: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x80699168: jal         0x80067818
    // 0x8069916C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8069916C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80699170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80699174:
    // 0x80699174: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80699178: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8069917C: jr          $ra
    // 0x80699180: nop

    return;
    // 0x80699180: nop

;}
RECOMP_FUNC void func_804CAE90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CAE90: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804CAE94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CAE98: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804CAE9C: jal         0x8004700C
    // 0x804CAEA0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804CAEA0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x804CAEA4: beq         $v0, $zero, L_804CB198
    if (ctx->r2 == 0) {
        // 0x804CAEA8: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_804CB198;
    }
    // 0x804CAEA8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x804CAEAC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13C8) << 16);
    // 0x804CAEB0: lwc1        $f4, -0x40F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13C8));
    // 0x804CAEB4: lwc1        $f12, 0xC4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x804CAEB8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x804CAEBC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13CC) << 16);
    // 0x804CAEC0: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x804CAEC4: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x804CAEC8: bc1t        L_804CAEE0
    if (c1cs) {
        // 0x804CAECC: nop
    
            goto L_804CAEE0;
    }
    // 0x804CAECC: nop

    // 0x804CAED0: lwc1        $f6, -0x40F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13CC));
    // 0x804CAED4: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x804CAED8: nop

    // 0x804CAEDC: bc1f        L_804CAF04
    if (!c1cs) {
        // 0x804CAEE0: lui         $at, 0x804D
        ctx->r1 = S32(RELOC_HI16(231, 0X12D0) << 16);
            goto L_804CAF04;
    }
L_804CAEE0:
    // 0x804CAEE0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X12D0) << 16);
    // 0x804CAEE4: lwc1        $f8, -0x41F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X12D0));
    // 0x804CAEE8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x804CAEEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804CAEF0: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x804CAEF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804CAEF8: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804CAEFC: b           L_804CAF14
    // 0x804CAF00: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
        goto L_804CAF14;
    // 0x804CAF00: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
L_804CAF04:
    // 0x804CAF04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804CAF08: nop

    // 0x804CAF0C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x804CAF10: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
L_804CAF14:
    // 0x804CAF14: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13D0) << 16);
    // 0x804CAF18: lbu         $t6, 0x12E8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X12E8);
    // 0x804CAF1C: bne         $t6, $zero, L_804CAF50
    if (ctx->r14 != 0) {
        // 0x804CAF20: nop
    
            goto L_804CAF50;
    }
    // 0x804CAF20: nop

    // 0x804CAF24: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x804CAF28: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804CAF2C: bc1fl       L_804CAF48
    if (!c1cs) {
        // 0x804CAF30: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_804CAF48;
    }
    goto skip_0;
    // 0x804CAF30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x804CAF34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804CAF38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804CAF3C: b           L_804CB014
    // 0x804CAF40: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
        goto L_804CB014;
    // 0x804CAF40: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x804CAF44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_804CAF48:
    // 0x804CAF48: b           L_804CB014
    // 0x804CAF4C: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
        goto L_804CB014;
    // 0x804CAF4C: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
L_804CAF50:
    // 0x804CAF50: lwc1        $f12, -0x40F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13D0));
    // 0x804CAF54: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13D4) << 16);
    // 0x804CAF58: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x804CAF5C: nop

    // 0x804CAF60: bc1f        L_804CAF80
    if (!c1cs) {
        // 0x804CAF64: nop
    
            goto L_804CAF80;
    }
    // 0x804CAF64: nop

    // 0x804CAF68: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x804CAF6C: nop

    // 0x804CAF70: bc1f        L_804CAF80
    if (!c1cs) {
        // 0x804CAF74: nop
    
            goto L_804CAF80;
    }
    // 0x804CAF74: nop

    // 0x804CAF78: b           L_804CAFA8
    // 0x804CAF7C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
        goto L_804CAFA8;
    // 0x804CAF7C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_804CAF80:
    // 0x804CAF80: lwc1        $f12, -0x40EC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13D4));
    // 0x804CAF84: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x804CAF88: nop

    // 0x804CAF8C: bc1fl       L_804CAFAC
    if (!c1cs) {
        // 0x804CAF90: lbu         $t7, 0xF4($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0XF4);
            goto L_804CAFAC;
    }
    goto skip_1;
    // 0x804CAF90: lbu         $t7, 0xF4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF4);
    skip_1:
    // 0x804CAF94: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x804CAF98: nop

    // 0x804CAF9C: bc1fl       L_804CAFAC
    if (!c1cs) {
        // 0x804CAFA0: lbu         $t7, 0xF4($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0XF4);
            goto L_804CAFAC;
    }
    goto skip_2;
    // 0x804CAFA0: lbu         $t7, 0xF4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF4);
    skip_2:
    // 0x804CAFA4: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_804CAFA8:
    // 0x804CAFA8: lbu         $t7, 0xF4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF4);
L_804CAFAC:
    // 0x804CAFAC: beql        $t7, $zero, L_804CAFF4
    if (ctx->r15 == 0) {
        // 0x804CAFB0: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_804CAFF4;
    }
    goto skip_3;
    // 0x804CAFB0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_3:
    // 0x804CAFB4: lwc1        $f6, 0xC8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x804CAFB8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x804CAFBC: nop

    // 0x804CAFC0: bc1fl       L_804CAFF4
    if (!c1cs) {
        // 0x804CAFC4: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_804CAFF4;
    }
    goto skip_4;
    // 0x804CAFC4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_4:
    // 0x804CAFC8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x804CAFCC: jal         0x80066DE4
    // 0x804CAFD0: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x804CAFD0: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x804CAFD4: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1300) << 16);
    // 0x804CAFD8: lwc1        $f8, -0x41C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1300));
    // 0x804CAFDC: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804CAFE0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x804CAFE4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804CAFE8: b           L_804CB014
    // 0x804CAFEC: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
        goto L_804CB014;
    // 0x804CAFEC: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x804CAFF0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_804CAFF4:
    // 0x804CAFF4: jal         0x80066DE4
    // 0x804CAFF8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x804CAFF8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x804CAFFC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X12E8) << 16);
    // 0x804CB000: lwc1        $f16, -0x41D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X12E8));
    // 0x804CB004: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804CB008: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x804CB00C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804CB010: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
L_804CB014:
    // 0x804CB014: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X1318) << 16);
    // 0x804CB018: lwc1        $f12, -0x41A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X1318));
    // 0x804CB01C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804CB020: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x804CB024: nop

    // 0x804CB028: bc1fl       L_804CB03C
    if (!c1cs) {
        // 0x804CB02C: neg.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
            goto L_804CB03C;
    }
    goto skip_5;
    // 0x804CB02C: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
    skip_5:
    // 0x804CB030: b           L_804CB05C
    // 0x804CB034: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_804CB05C;
    // 0x804CB034: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x804CB038: neg.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = -ctx->f12.fl;
L_804CB03C:
    // 0x804CB03C: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x804CB040: nop

    // 0x804CB044: bc1fl       L_804CB058
    if (!c1cs) {
        // 0x804CB048: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_804CB058;
    }
    goto skip_6;
    // 0x804CB048: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_6:
    // 0x804CB04C: b           L_804CB058
    // 0x804CB050: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_804CB058;
    // 0x804CB050: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x804CB054: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_804CB058:
    // 0x804CB058: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_804CB05C:
    // 0x804CB05C: sub.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x804CB060: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804CB064: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x804CB068: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x804CB06C: nop

    // 0x804CB070: bc1fl       L_804CB084
    if (!c1cs) {
        // 0x804CB074: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_804CB084;
    }
    goto skip_7;
    // 0x804CB074: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_7:
    // 0x804CB078: b           L_804CB0A8
    // 0x804CB07C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_804CB0A8;
    // 0x804CB07C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x804CB080: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_804CB084:
    // 0x804CB084: nop

    // 0x804CB088: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x804CB08C: nop

    // 0x804CB090: bc1fl       L_804CB0A4
    if (!c1cs) {
        // 0x804CB094: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_804CB0A4;
    }
    goto skip_8;
    // 0x804CB094: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_8:
    // 0x804CB098: b           L_804CB0A4
    // 0x804CB09C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_804CB0A4;
    // 0x804CB09C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804CB0A0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_804CB0A4:
    // 0x804CB0A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_804CB0A8:
    // 0x804CB0A8: swc1        $f20, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f20.u32l;
    // 0x804CB0AC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x804CB0B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CB0B4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x804CB0B8: lw          $t9, 0x138($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X138);
    // 0x804CB0BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x804CB0C0: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x804CB0C4: beql        $t9, $zero, L_804CB100
    if (ctx->r25 == 0) {
        // 0x804CB0C8: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_804CB100;
    }
    goto skip_9;
    // 0x804CB0C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_9:
    // 0x804CB0CC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x804CB0D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804CB0D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804CB0D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804CB0DC: nop

    // 0x804CB0E0: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x804CB0E4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804CB0E8: nop

    // 0x804CB0EC: bc1fl       L_804CB128
    if (!c1cs) {
        // 0x804CB0F0: swc1        $f2, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
            goto L_804CB128;
    }
    goto skip_10;
    // 0x804CB0F0: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    skip_10:
    // 0x804CB0F4: b           L_804CB124
    // 0x804CB0F8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_804CB124;
    // 0x804CB0F8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x804CB0FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_804CB100:
    // 0x804CB100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804CB104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804CB108: nop

    // 0x804CB10C: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x804CB110: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804CB114: nop

    // 0x804CB118: bc1fl       L_804CB128
    if (!c1cs) {
        // 0x804CB11C: swc1        $f2, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
            goto L_804CB128;
    }
    goto skip_11;
    // 0x804CB11C: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    skip_11:
    // 0x804CB120: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_804CB124:
    // 0x804CB124: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
L_804CB128:
    // 0x804CB128: jal         0x80066DE4
    // 0x804CB12C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x804CB12C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x804CB130: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x804CB134: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804CB138: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x804CB13C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x804CB140: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804CB144: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804CB148: lwc1        $f14, 0x6C($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X6C);
    // 0x804CB14C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x804CB150: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x804CB154: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x804CB158: nop

    // 0x804CB15C: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x804CB160: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x804CB164: jal         0x80066E88
    // 0x804CB168: swc1        $f6, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f6.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x804CB168: swc1        $f6, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f6.u32l;
    after_4:
    // 0x804CB16C: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x804CB170: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804CB174: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x804CB178: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x804CB17C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804CB180: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x804CB184: lwc1        $f2, 0x70($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X70);
    // 0x804CB188: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x804CB18C: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x804CB190: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804CB194: swc1        $f6, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f6.u32l;
L_804CB198:
    // 0x804CB198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804CB19C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804CB1A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x804CB1A4: jr          $ra
    // 0x804CB1A8: nop

    return;
    // 0x804CB1A8: nop

;}
RECOMP_FUNC void func_807A008C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A008C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807A0090: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(838, 0X990) << 16);
    // 0x807A0094: addiu       $t6, $t6, -0x10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(838, 0X990));
    // 0x807A0098: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807A009C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807A00A0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x807A00A4: jr          $ra
    // 0x807A00A8: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
    return;
    // 0x807A00A8: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_80057EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057EB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80057EB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80057EB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80057EBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80057EC0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80057EC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80057EC8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80057ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80057ED0: jal         0x80057E04
    // 0x80057ED4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80057E04(rdram, ctx);
        goto after_0;
    // 0x80057ED4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80057ED8: addiu       $s2, $sp, 0x2C
    ctx->r18 = ADD32(ctx->r29, 0X2C);
    // 0x80057EDC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80057EE0: jal         0x80057E04
    // 0x80057EE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80057E04(rdram, ctx);
        goto after_1;
    // 0x80057EE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80057EE8: bnel        $v0, $zero, L_80057F10
    if (ctx->r2 != 0) {
        // 0x80057EEC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80057F10;
    }
    goto skip_0;
    // 0x80057EEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_80057EF0:
    // 0x80057EF0: jalr        $s1
    // 0x80057EF4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    LOOKUP_FUNC(ctx->r17)(rdram, ctx);
        goto after_2;
    // 0x80057EF4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80057EF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80057EFC: jal         0x80057E04
    // 0x80057F00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80057E04(rdram, ctx);
        goto after_3;
    // 0x80057F00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80057F04: beq         $v0, $zero, L_80057EF0
    if (ctx->r2 == 0) {
        // 0x80057F08: nop
    
            goto L_80057EF0;
    }
    // 0x80057F08: nop

    // 0x80057F0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80057F10:
    // 0x80057F10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80057F14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80057F18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80057F1C: jr          $ra
    // 0x80057F20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80057F20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_805C9478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C9478: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805C947C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C9480: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C9484: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C9488: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C948C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x805C9490: bnel        $t6, $zero, L_805C94F0
    if (ctx->r14 != 0) {
        // 0x805C9494: lw          $t8, 0x2C($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X2C);
            goto L_805C94F0;
    }
    goto skip_0;
    // 0x805C9494: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    skip_0:
    // 0x805C9498: jal         0x805C7BAC
    // 0x805C949C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_805C7BAC(rdram, ctx);
        goto after_0;
    // 0x805C949C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C94A0: beq         $v0, $zero, L_805C94EC
    if (ctx->r2 == 0) {
        // 0x805C94A4: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_805C94EC;
    }
    // 0x805C94A4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805C94A8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x805C94AC: lui         $a1, 0x3CF5
    ctx->r5 = S32(0X3CF5 << 16);
    // 0x805C94B0: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x805C94B4: bne         $t7, $zero, L_805C94EC
    if (ctx->r15 != 0) {
        // 0x805C94B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805C94EC;
    }
    // 0x805C94B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C94BC: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x805C94C0: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x805C94C4: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x805C94C8: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x805C94CC: jal         0x805C74C8
    // 0x805C94D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_805C74C8(rdram, ctx);
        goto after_1;
    // 0x805C94D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x805C94D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C94D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C94DC: jal         0x805C9D10
    // 0x805C94E0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_805C9D10(rdram, ctx);
        goto after_2;
    // 0x805C94E0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_2:
    // 0x805C94E4: b           L_805C953C
    // 0x805C94E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C953C;
    // 0x805C94E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C94EC:
    // 0x805C94EC: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
L_805C94F0:
    // 0x805C94F0: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x805C94F4: bne         $at, $zero, L_805C950C
    if (ctx->r1 != 0) {
        // 0x805C94F8: nop
    
            goto L_805C950C;
    }
    // 0x805C94F8: nop

    // 0x805C94FC: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x805C9500: bne         $t9, $zero, L_805C950C
    if (ctx->r25 != 0) {
        // 0x805C9504: nop
    
            goto L_805C950C;
    }
    // 0x805C9504: nop

    // 0x805C9508: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
L_805C950C:
    // 0x805C950C: jal         0x805C74EC
    // 0x805C9510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C74EC(rdram, ctx);
        goto after_3;
    // 0x805C9510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805C9514: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805C9518: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805C951C: jal         0x80048F84
    // 0x805C9520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x805C9520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x805C9524: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805C9528: jal         0x80048F84
    // 0x805C952C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x805C952C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x805C9530: jal         0x805C7ABC
    // 0x805C9534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7ABC(rdram, ctx);
        goto after_6;
    // 0x805C9534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805C9538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C953C:
    // 0x805C953C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C9540: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805C9544: jr          $ra
    // 0x805C9548: nop

    return;
    // 0x805C9548: nop

;}
RECOMP_FUNC void func_8002C4F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C4F0: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8002C4F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002C4F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002C4FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002C500: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x8002C504: lwc1        $f6, -0x70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X70);
    // 0x8002C508: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8002C50C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C510: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C514: jr          $ra
    // 0x8002C518: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x8002C518: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8040C43C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C43C: jr          $ra
    // 0x8040C440: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8040C440: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8043752C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043752C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80437530: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437534: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80437538: jr          $ra
    // 0x8043753C: sw          $t6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r14;
    return;
    // 0x8043753C: sw          $t6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8044CA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044CA18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044CA1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044CA20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8044CA24: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8044CA28: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8044CA2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8044CA30: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8044CA34: nop

    // 0x8044CA38: bc1t        L_8044CA44
    if (c1cs) {
        // 0x8044CA3C: nop
    
            goto L_8044CA44;
    }
    // 0x8044CA3C: nop

    // 0x8044CA40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8044CA44:
    // 0x8044CA44: beq         $v0, $zero, L_8044CAD8
    if (ctx->r2 == 0) {
        // 0x8044CA48: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8044CAD8;
    }
    // 0x8044CA48: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8044CA4C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8044CA50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8044CA54: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8044CA58: nop

    // 0x8044CA5C: bc1t        L_8044CA68
    if (c1cs) {
        // 0x8044CA60: nop
    
            goto L_8044CA68;
    }
    // 0x8044CA60: nop

    // 0x8044CA64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8044CA68:
    // 0x8044CA68: beq         $v0, $zero, L_8044CAA4
    if (ctx->r2 == 0) {
        // 0x8044CA6C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8044CAA4;
    }
    // 0x8044CA6C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8044CA70: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8044CA74: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8044CA78: nop

    // 0x8044CA7C: bc1t        L_8044CA94
    if (c1cs) {
        // 0x8044CA80: nop
    
            goto L_8044CA94;
    }
    // 0x8044CA80: nop

    // 0x8044CA84: jal         0x8044C4C8
    // 0x8044CA88: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    func_8044C4C8(rdram, ctx);
        goto after_0;
    // 0x8044CA88: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    after_0:
    // 0x8044CA8C: b           L_8044CB60
    // 0x8044CA90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044CB60;
    // 0x8044CA90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044CA94:
    // 0x8044CA94: jal         0x8044C5F4
    // 0x8044CA98: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    func_8044C5F4(rdram, ctx);
        goto after_1;
    // 0x8044CA98: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    after_1:
    // 0x8044CA9C: b           L_8044CB60
    // 0x8044CAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044CB60;
    // 0x8044CAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044CAA4:
    // 0x8044CAA4: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8044CAA8: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8044CAAC: nop

    // 0x8044CAB0: bc1t        L_8044CAC8
    if (c1cs) {
        // 0x8044CAB4: nop
    
            goto L_8044CAC8;
    }
    // 0x8044CAB4: nop

    // 0x8044CAB8: jal         0x8044C6B4
    // 0x8044CABC: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    func_8044C6B4(rdram, ctx);
        goto after_2;
    // 0x8044CABC: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    after_2:
    // 0x8044CAC0: b           L_8044CB60
    // 0x8044CAC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044CB60;
    // 0x8044CAC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044CAC8:
    // 0x8044CAC8: jal         0x8044C778
    // 0x8044CACC: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    func_8044C778(rdram, ctx);
        goto after_3;
    // 0x8044CACC: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    after_3:
    // 0x8044CAD0: b           L_8044CB60
    // 0x8044CAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044CB60;
    // 0x8044CAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044CAD8:
    // 0x8044CAD8: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8044CADC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8044CAE0: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8044CAE4: nop

    // 0x8044CAE8: bc1t        L_8044CAF4
    if (c1cs) {
        // 0x8044CAEC: nop
    
            goto L_8044CAF4;
    }
    // 0x8044CAEC: nop

    // 0x8044CAF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8044CAF4:
    // 0x8044CAF4: beq         $v0, $zero, L_8044CB30
    if (ctx->r2 == 0) {
        // 0x8044CAF8: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8044CB30;
    }
    // 0x8044CAF8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8044CAFC: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8044CB00: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x8044CB04: nop

    // 0x8044CB08: bc1t        L_8044CB20
    if (c1cs) {
        // 0x8044CB0C: nop
    
            goto L_8044CB20;
    }
    // 0x8044CB0C: nop

    // 0x8044CB10: jal         0x8044C7FC
    // 0x8044CB14: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    func_8044C7FC(rdram, ctx);
        goto after_4;
    // 0x8044CB14: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    after_4:
    // 0x8044CB18: b           L_8044CB60
    // 0x8044CB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044CB60;
    // 0x8044CB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044CB20:
    // 0x8044CB20: jal         0x8044C8BC
    // 0x8044CB24: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    func_8044C8BC(rdram, ctx);
        goto after_5;
    // 0x8044CB24: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    after_5:
    // 0x8044CB28: b           L_8044CB60
    // 0x8044CB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044CB60;
    // 0x8044CB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044CB30:
    // 0x8044CB30: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8044CB34: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8044CB38: nop

    // 0x8044CB3C: bc1t        L_8044CB54
    if (c1cs) {
        // 0x8044CB40: nop
    
            goto L_8044CB54;
    }
    // 0x8044CB40: nop

    // 0x8044CB44: jal         0x8044C948
    // 0x8044CB48: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    func_8044C948(rdram, ctx);
        goto after_6;
    // 0x8044CB48: addiu       $a1, $a2, -0x8
    ctx->r5 = ADD32(ctx->r6, -0X8);
    after_6:
    // 0x8044CB4C: b           L_8044CB60
    // 0x8044CB50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044CB60;
    // 0x8044CB50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044CB54:
    // 0x8044CB54: jal         0x8044C9D0
    // 0x8044CB58: nop

    func_8044C9D0(rdram, ctx);
        goto after_7;
    // 0x8044CB58: nop

    after_7:
    // 0x8044CB5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044CB60:
    // 0x8044CB60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044CB64: jr          $ra
    // 0x8044CB68: nop

    return;
    // 0x8044CB68: nop

;}
RECOMP_FUNC void func_8069E68C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069E68C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069E690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069E694: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069E698: lui         $a2, 0x806A
    ctx->r6 = S32(RELOC_HI16(577, 0X8F8) << 16);
    // 0x8069E69C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8069E6A0: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x8069E6A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8069E6A8: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X940) << 16);
    // 0x8069E6AC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8069E6B0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8069E6B4: lw          $a2, -0x1338($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(577, 0X8F8));
    // 0x8069E6B8: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8069E6BC: lui         $t2, 0x806A
    ctx->r10 = S32(RELOC_HI16(577, 0X904) << 16);
    // 0x8069E6C0: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x8069E6C4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8069E6C8: lwc1        $f4, -0x12F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X940));
    // 0x8069E6CC: addu        $t1, $a0, $v1
    ctx->r9 = ADD32(ctx->r4, ctx->r3);
    // 0x8069E6D0: lwc1        $f0, 0x6C($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X6C);
    // 0x8069E6D4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8069E6D8: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x8069E6DC: lw          $t2, -0x132C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(577, 0X904));
    // 0x8069E6E0: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X948) << 16);
    // 0x8069E6E4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8069E6E8: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
    // 0x8069E6EC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8069E6F0: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8069E6F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069E6F8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8069E6FC: nop

    // 0x8069E700: bc1fl       L_8069E714
    if (!c1cs) {
        // 0x8069E704: swc1        $f0, 0x6C($t1)
        MEM_W(0X6C, ctx->r9) = ctx->f0.u32l;
            goto L_8069E714;
    }
    goto skip_0;
    // 0x8069E704: swc1        $f0, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f0.u32l;
    skip_0:
    // 0x8069E708: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8069E70C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8069E710: swc1        $f0, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f0.u32l;
L_8069E714:
    // 0x8069E714: lwc1        $f8, -0x12E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X948));
    // 0x8069E718: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x8069E71C: lwc1        $f0, 0x6C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x8069E720: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8069E724: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X9EC) << 16);
    // 0x8069E728: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8069E72C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8069E730: nop

    // 0x8069E734: bc1fl       L_8069E748
    if (!c1cs) {
        // 0x8069E738: swc1        $f0, 0x6C($v1)
        MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
            goto L_8069E748;
    }
    goto skip_1;
    // 0x8069E738: swc1        $f0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
    skip_1:
    // 0x8069E73C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8069E740: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8069E744: swc1        $f0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
L_8069E748:
    // 0x8069E748: lwc1        $f16, -0x1244($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X9EC));
    // 0x8069E74C: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X9F0) << 16);
    // 0x8069E750: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8069E754: nop

    // 0x8069E758: bc1f        L_8069E788
    if (!c1cs) {
        // 0x8069E75C: nop
    
            goto L_8069E788;
    }
    // 0x8069E75C: nop

    // 0x8069E760: lwc1        $f0, -0x1240($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X9F0));
    // 0x8069E764: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X9F4) << 16);
    // 0x8069E768: lwc1        $f18, -0x123C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X9F4));
    // 0x8069E76C: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8069E770: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8069E774: nop

    // 0x8069E778: bc1fl       L_8069E788
    if (!c1cs) {
        // 0x8069E77C: swc1        $f2, 0x10($a3)
        MEM_W(0X10, ctx->r7) = ctx->f2.u32l;
            goto L_8069E788;
    }
    goto skip_2;
    // 0x8069E77C: swc1        $f2, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f2.u32l;
    skip_2:
    // 0x8069E780: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8069E784: swc1        $f2, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f2.u32l;
L_8069E788:
    // 0x8069E788: bne         $t0, $zero, L_8069E7B0
    if (ctx->r8 != 0) {
        // 0x8069E78C: nop
    
            goto L_8069E7B0;
    }
    // 0x8069E78C: nop

    // 0x8069E790: jal         0x8069EC9C
    // 0x8069E794: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8069EC9C(rdram, ctx);
        goto after_0;
    // 0x8069E794: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8069E798: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8069E79C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8069E7A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8069E7A4: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8069E7A8: sw          $t6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r14;
    // 0x8069E7AC: swc1        $f12, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f12.u32l;
L_8069E7B0:
    // 0x8069E7B0: jal         0x8069E654
    // 0x8069E7B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8069E654(rdram, ctx);
        goto after_1;
    // 0x8069E7B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8069E7B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069E7BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069E7C0: jr          $ra
    // 0x8069E7C4: nop

    return;
    // 0x8069E7C4: nop

;}
RECOMP_FUNC void func_805AE234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE234: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE238: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE23C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE240: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE244: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE248: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE24C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE250: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE254: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE258: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE25C: jr          $ra
    // 0x805AE260: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE260: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8073F8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F8C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8073F8CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073F8D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073F8D4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8073F8D8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073F8DC: lw          $s0, 0xC($v1)
    ctx->r16 = MEM_W(ctx->r3, 0XC);
    // 0x8073F8E0: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x8073F8E4: beql        $s0, $zero, L_8073F97C
    if (ctx->r16 == 0) {
        // 0x8073F8E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073F97C;
    }
    goto skip_0;
    // 0x8073F8E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8073F8EC: beq         $v0, $zero, L_8073F978
    if (ctx->r2 == 0) {
        // 0x8073F8F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8073F978;
    }
    // 0x8073F8F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073F8F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8073F8F8: jal         0x8004816C
    // 0x8073F8FC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_8004816C(rdram, ctx);
        goto after_0;
    // 0x8073F8FC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8073F900: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8073F904: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8073F908: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8073F90C: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
    // 0x8073F910: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8073F914: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    // 0x8073F918: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8073F91C: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8073F920: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8073F924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073F928: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073F92C: lwc1        $f4, 0x8C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x8073F930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073F934: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8073F938: swc1        $f8, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f8.u32l;
    // 0x8073F93C: lwc1        $f16, 0x88($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8073F940: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8073F944: swc1        $f18, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f18.u32l;
    // 0x8073F948: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8073F94C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073F950: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x8073F954: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x8073F958: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8073F95C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x8073F960: lwc1        $f10, 0xC4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC4);
    // 0x8073F964: jal         0x8073EB14
    // 0x8073F968: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    func_8073EB14(rdram, ctx);
        goto after_1;
    // 0x8073F968: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x8073F96C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8073F970: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8073F974: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
L_8073F978:
    // 0x8073F978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073F97C:
    // 0x8073F97C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073F980: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8073F984: jr          $ra
    // 0x8073F988: nop

    return;
    // 0x8073F988: nop

;}
RECOMP_FUNC void func_80676368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676368: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8067636C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80676370: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x80676374: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676378: beq         $v1, $zero, L_806763E4
    if (ctx->r3 == 0) {
        // 0x8067637C: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_806763E4;
    }
    // 0x8067637C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80676380: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80676384: jal         0x80675DD8
    // 0x80676388: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80675DD8(rdram, ctx);
        goto after_0;
    // 0x80676388: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8067638C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80676390: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80676394: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80676398: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067639C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806763A0: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x806763A4: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x806763A8: beql        $t0, $zero, L_806763E8
    if (ctx->r8 == 0) {
        // 0x806763AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806763E8;
    }
    goto skip_0;
    // 0x806763AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806763B0: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x806763B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806763B8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806763BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806763C0: swc1        $f4, 0x3F8($v0)
    MEM_W(0X3F8, ctx->r2) = ctx->f4.u32l;
    // 0x806763C4: jal         0x80677A88
    // 0x806763C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80677A88(rdram, ctx);
        goto after_1;
    // 0x806763C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x806763CC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x806763D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806763D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806763D8: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x806763DC: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x806763E0: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
L_806763E4:
    // 0x806763E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806763E8:
    // 0x806763E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806763EC: jr          $ra
    // 0x806763F0: nop

    return;
    // 0x806763F0: nop

;}
RECOMP_FUNC void func_80050674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050678: bne         $a0, $zero, L_80050698
    if (ctx->r4 != 0) {
        // 0x8005067C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80050698;
    }
    // 0x8005067C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050680: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80050684: addiu       $a0, $a0, 0x9C0
    ctx->r4 = ADD32(ctx->r4, 0X9C0);
    // 0x80050688: jal         0x80071380
    // 0x8005068C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8005068C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_0:
    // 0x80050690: b           L_800506A4
    // 0x80050694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800506A4;
    // 0x80050694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050698:
    // 0x80050698: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8005069C: xor         $v0, $a1, $t6
    ctx->r2 = ctx->r5 ^ ctx->r14;
    // 0x800506A0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800506A4:
    // 0x800506A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800506A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800506AC: jr          $ra
    // 0x800506B0: nop

    return;
    // 0x800506B0: nop

;}
RECOMP_FUNC void func_804B6E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6E30: jal         0x804B6BF8
    // 0x804B6E34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804B6BF8(rdram, ctx);
        goto after_0;
    // 0x804B6E34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B6E38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6E3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6E40: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804B6E44: jal         0x804B6FF0
    // 0x804B6E48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B6E48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804B6E4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6E50: lui         $t6, 0x804B
    ctx->r14 = S32(RELOC_HI16(182, 0XB50) << 16);
    // 0x804B6E54: addiu       $t6, $t6, 0x6DF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(182, 0XB50));
    // 0x804B6E58: jal         0x80057978
    // 0x804B6E5C: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    func_80057978(rdram, ctx);
        goto after_2;
    // 0x804B6E5C: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    after_2:
    // 0x804B6E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6E64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6E68: jr          $ra
    // 0x804B6E6C: nop

    return;
    // 0x804B6E6C: nop

;}
RECOMP_FUNC void func_80475090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475090: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475094: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475098: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047509C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804750A0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804750A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804750A8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804750AC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804750B0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804750B4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804750B8: jr          $ra
    // 0x804750BC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804750BC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805D2004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2004: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805D2008: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805D200C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x805D2010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805D2014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805D2018: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x805D201C: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(471, 0X2A40) << 16);
    // 0x805D2020: lui         $a1, 0x4046
    ctx->r5 = S32(0X4046 << 16);
    // 0x805D2024: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x805D2028: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x805D202C: ori         $a1, $a1, 0x2C00
    ctx->r5 = ctx->r5 | 0X2C00;
    // 0x805D2030: addiu       $a0, $a0, 0x4470
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(471, 0X2A40));
    // 0x805D2034: jal         0x80046804
    // 0x805D2038: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x805D2038: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x805D203C: bne         $v0, $zero, L_805D204C
    if (ctx->r2 != 0) {
        // 0x805D2040: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805D204C;
    }
    // 0x805D2040: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805D2044: b           L_805D207C
    // 0x805D2048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805D207C;
    // 0x805D2048: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D204C:
    // 0x805D204C: jal         0x80047090
    // 0x805D2050: addiu       $a0, $zero, 0x4046
    ctx->r4 = ADD32(0, 0X4046);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x805D2050: addiu       $a0, $zero, 0x4046
    ctx->r4 = ADD32(0, 0X4046);
    after_1:
    // 0x805D2054: lhu         $t9, 0xE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XE);
    // 0x805D2058: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x805D205C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D2060: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x805D2064: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x805D2068: jal         0x80044194
    // 0x805D206C: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805D206C: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    after_2:
    // 0x805D2070: jal         0x80052BA4
    // 0x805D2074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_3;
    // 0x805D2074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805D2078: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_805D207C:
    // 0x805D207C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805D2080: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805D2084: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805D2088: jr          $ra
    // 0x805D208C: nop

    return;
    // 0x805D208C: nop

;}
RECOMP_FUNC void func_805AA784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AA788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA78C: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x805AA790: bnel        $v1, $zero, L_805AA7DC
    if (ctx->r3 != 0) {
        // 0x805AA794: lhu         $v0, 0xC($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0XC);
            goto L_805AA7DC;
    }
    goto skip_0;
    // 0x805AA794: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    skip_0:
    // 0x805AA798: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x805AA79C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805AA7A0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x805AA7A4: sh          $v0, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r2;
    // 0x805AA7A8: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x805AA7AC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805AA7B0: sh          $v0, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r2;
    // 0x805AA7B4: jal         0x8005FDC4
    // 0x805AA7B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x805AA7B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AA7BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AA7C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AA7C4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805AA7C8: jal         0x805AABAC
    // 0x805AA7CC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_805AABAC(rdram, ctx);
        goto after_1;
    // 0x805AA7CC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x805AA7D0: b           L_805AA834
    // 0x805AA7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805AA834;
    // 0x805AA7D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AA7D8: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
L_805AA7DC:
    // 0x805AA7DC: addiu       $at, $zero, 0x40B0
    ctx->r1 = ADD32(0, 0X40B0);
    // 0x805AA7E0: beq         $v0, $at, L_805AA830
    if (ctx->r2 == ctx->r1) {
        // 0x805AA7E4: addiu       $at, $zero, 0x45F0
        ctx->r1 = ADD32(0, 0X45F0);
            goto L_805AA830;
    }
    // 0x805AA7E4: addiu       $at, $zero, 0x45F0
    ctx->r1 = ADD32(0, 0X45F0);
    // 0x805AA7E8: beq         $v0, $at, L_805AA830
    if (ctx->r2 == ctx->r1) {
        // 0x805AA7EC: addiu       $at, $zero, 0x4638
        ctx->r1 = ADD32(0, 0X4638);
            goto L_805AA830;
    }
    // 0x805AA7EC: addiu       $at, $zero, 0x4638
    ctx->r1 = ADD32(0, 0X4638);
    // 0x805AA7F0: beql        $v0, $at, L_805AA834
    if (ctx->r2 == ctx->r1) {
        // 0x805AA7F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AA834;
    }
    goto skip_1;
    // 0x805AA7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805AA7F8: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x805AA7FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805AA800: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x805AA804: sh          $v0, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r2;
    // 0x805AA808: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x805AA80C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x805AA810: sh          $v0, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r2;
    // 0x805AA814: jal         0x8005FDC4
    // 0x805AA818: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FDC4(rdram, ctx);
        goto after_2;
    // 0x805AA818: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x805AA81C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AA820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AA824: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805AA828: jal         0x805AABAC
    // 0x805AA82C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_805AABAC(rdram, ctx);
        goto after_3;
    // 0x805AA82C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_3:
L_805AA830:
    // 0x805AA830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AA834:
    // 0x805AA834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AA838: jr          $ra
    // 0x805AA83C: nop

    return;
    // 0x805AA83C: nop

;}
RECOMP_FUNC void func_80471CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471CC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80471CC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80471CC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80471CCC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80471CD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80471CD4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80471CD8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80471CDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80471CE0: jal         0x80048F84
    // 0x80471CE4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80471CE4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80471CE8: jal         0x80471BCC
    // 0x80471CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80471BCC(rdram, ctx);
        goto after_1;
    // 0x80471CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80471CF0: jal         0x80471C10
    // 0x80471CF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80471C10(rdram, ctx);
        goto after_2;
    // 0x80471CF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80471CF8: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x80471CFC: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x80471D00: andi        $t8, $v0, 0xF0
    ctx->r24 = ctx->r2 & 0XF0;
    // 0x80471D04: bne         $t8, $zero, L_80471D14
    if (ctx->r24 != 0) {
        // 0x80471D08: andi        $t9, $v0, 0xF
        ctx->r25 = ctx->r2 & 0XF;
            goto L_80471D14;
    }
    // 0x80471D08: andi        $t9, $v0, 0xF
    ctx->r25 = ctx->r2 & 0XF;
    // 0x80471D0C: beql        $t9, $zero, L_80471D28
    if (ctx->r25 == 0) {
        // 0x80471D10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80471D28;
    }
    goto skip_0;
    // 0x80471D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80471D14:
    // 0x80471D14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80471D18: nop

    // 0x80471D1C: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x80471D20: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x80471D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80471D28:
    // 0x80471D28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80471D2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80471D30: jr          $ra
    // 0x80471D34: nop

    return;
    // 0x80471D34: nop

;}
RECOMP_FUNC void func_807BC128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC128: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x807BC12C: lui         $t0, 0x807C
    ctx->r8 = S32(RELOC_HI16(898, 0X6C08) << 16);
    // 0x807BC130: addiu       $t0, $t0, 0x28C8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(898, 0X6C08));
    // 0x807BC134: beq         $v0, $zero, L_807BC144
    if (ctx->r2 == 0) {
        // 0x807BC138: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807BC144;
    }
    // 0x807BC138: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807BC13C: jr          $ra
    // 0x807BC140: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
    return;
    // 0x807BC140: sw          $t6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r14;
L_807BC144:
    // 0x807BC144: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x807BC148: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x807BC14C: slti        $at, $v0, 0x37
    ctx->r1 = SIGNED(ctx->r2) < 0X37 ? 1 : 0;
    // 0x807BC150: bne         $at, $zero, L_807BC160
    if (ctx->r1 != 0) {
        // 0x807BC154: sw          $v0, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->r2;
            goto L_807BC160;
    }
    // 0x807BC154: sw          $v0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r2;
    // 0x807BC158: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    // 0x807BC15C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807BC160:
    // 0x807BC160: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x807BC164: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x807BC168: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x807BC16C: sw          $t1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r9;
    // 0x807BC170: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x807BC174: sw          $t2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r10;
    // 0x807BC178: jr          $ra
    // 0x807BC17C: nop

    return;
    // 0x807BC17C: nop

;}
RECOMP_FUNC void func_8004DC08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DC08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004DC0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004DC10: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004DC14: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004DC18: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8004DC1C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8004DC20: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8004DC24: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x8004DC28: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004DC2C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004DC30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004DC34: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x8004DC38: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004DC3C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8004DC40: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004DC44: beql        $v1, $zero, L_8004DD18
    if (ctx->r3 == 0) {
        // 0x8004DC48: lw          $t0, 0xC($s1)
        ctx->r8 = MEM_W(ctx->r17, 0XC);
            goto L_8004DD18;
    }
    goto skip_0;
    // 0x8004DC48: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    skip_0:
    // 0x8004DC4C: beql        $v1, $at, L_8004DD18
    if (ctx->r3 == ctx->r1) {
        // 0x8004DC50: lw          $t0, 0xC($s1)
        ctx->r8 = MEM_W(ctx->r17, 0XC);
            goto L_8004DD18;
    }
    goto skip_1;
    // 0x8004DC50: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    skip_1:
    // 0x8004DC54: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8004DC58: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004DC5C: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x8004DC60: beq         $v1, $at, L_8004DD14
    if (ctx->r3 == ctx->r1) {
        // 0x8004DC64: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004DD14;
    }
    // 0x8004DC64: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004DC68: beq         $v1, $at, L_8004DD14
    if (ctx->r3 == ctx->r1) {
        // 0x8004DC6C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004DD14;
    }
    // 0x8004DC6C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004DC70: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004DC74: jal         0x8004CEF8
    // 0x8004DC78: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8004CEF8(rdram, ctx);
        goto after_0;
    // 0x8004DC78: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8004DC7C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8004DC80: lbu         $t0, 0x14($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X14);
    // 0x8004DC84: beql        $t0, $zero, L_8004DD18
    if (ctx->r8 == 0) {
        // 0x8004DC88: lw          $t0, 0xC($s1)
        ctx->r8 = MEM_W(ctx->r17, 0XC);
            goto L_8004DD18;
    }
    goto skip_2;
    // 0x8004DC88: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    skip_2:
    // 0x8004DC8C: lbu         $t1, 0x15($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X15);
    // 0x8004DC90: bnel        $t1, $zero, L_8004DCA8
    if (ctx->r9 != 0) {
        // 0x8004DC94: lbu         $t4, 0x18($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X18);
            goto L_8004DCA8;
    }
    goto skip_3;
    // 0x8004DC94: lbu         $t4, 0x18($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X18);
    skip_3:
    // 0x8004DC98: lbu         $t2, 0x11($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X11);
    // 0x8004DC9C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8004DCA0: sb          $t3, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r11;
    // 0x8004DCA4: lbu         $t4, 0x18($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X18);
L_8004DCA8:
    // 0x8004DCA8: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8004DCAC: bne         $t4, $at, L_8004DCC0
    if (ctx->r12 != ctx->r1) {
        // 0x8004DCB0: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_8004DCC0;
    }
    // 0x8004DCB0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8004DCB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004DCB8: b           L_8004DD04
    // 0x8004DCBC: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
        goto L_8004DD04;
    // 0x8004DCBC: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
L_8004DCC0:
    // 0x8004DCC0: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8004DCC4: lhu         $v0, 0x4C($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X4C);
    // 0x8004DCC8: andi        $t6, $v0, 0x40
    ctx->r14 = ctx->r2 & 0X40;
    // 0x8004DCCC: beq         $t6, $zero, L_8004DCE4
    if (ctx->r14 == 0) {
        // 0x8004DCD0: andi        $t7, $v0, 0x80
        ctx->r15 = ctx->r2 & 0X80;
            goto L_8004DCE4;
    }
    // 0x8004DCD0: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x8004DCD4: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004DCD8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8004DCDC: b           L_8004DD04
    // 0x8004DCE0: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
        goto L_8004DD04;
    // 0x8004DCE0: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
L_8004DCE4:
    // 0x8004DCE4: beq         $t7, $zero, L_8004DCF8
    if (ctx->r15 == 0) {
        // 0x8004DCE8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8004DCF8;
    }
    // 0x8004DCE8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004DCEC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004DCF0: b           L_8004DD04
    // 0x8004DCF4: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
        goto L_8004DD04;
    // 0x8004DCF4: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
L_8004DCF8:
    // 0x8004DCF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004DCFC: nop

    // 0x8004DD00: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
L_8004DD04:
    // 0x8004DD04: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x8004DD08: ori         $t8, $t9, 0xF00
    ctx->r24 = ctx->r25 | 0XF00;
    // 0x8004DD0C: b           L_8004DDC0
    // 0x8004DD10: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
        goto L_8004DDC0;
    // 0x8004DD10: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
L_8004DD14:
    // 0x8004DD14: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
L_8004DD18:
    // 0x8004DD18: andi        $t1, $t0, 0xF00
    ctx->r9 = ctx->r8 & 0XF00;
    // 0x8004DD1C: beql        $t1, $zero, L_8004DDC4
    if (ctx->r9 == 0) {
        // 0x8004DD20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004DDC4;
    }
    goto skip_4;
    // 0x8004DD20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8004DD24: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8004DD28: lhu         $v0, 0x4C($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X4C);
    // 0x8004DD2C: andi        $t3, $v0, 0xC00
    ctx->r11 = ctx->r2 & 0XC00;
    // 0x8004DD30: beql        $t3, $zero, L_8004DDC4
    if (ctx->r11 == 0) {
        // 0x8004DD34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004DDC4;
    }
    goto skip_5;
    // 0x8004DD34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8004DD38: lw          $t4, 0x180($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X180);
    // 0x8004DD3C: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8004DD40: bnel        $t4, $zero, L_8004DD60
    if (ctx->r12 != 0) {
        // 0x8004DD44: lw          $v1, 0x130($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X130);
            goto L_8004DD60;
    }
    goto skip_6;
    // 0x8004DD44: lw          $v1, 0x130($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X130);
    skip_6:
    // 0x8004DD48: jal         0x80065490
    // 0x8004DD4C: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8004DD4C: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    after_1:
    // 0x8004DD50: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8004DD54: b           L_8004DD90
    // 0x8004DD58: lhu         $v0, 0x4C($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X4C);
        goto L_8004DD90;
    // 0x8004DD58: lhu         $v0, 0x4C($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X4C);
    // 0x8004DD5C: lw          $v1, 0x130($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X130);
L_8004DD60:
    // 0x8004DD60: beql        $v1, $zero, L_8004DD94
    if (ctx->r3 == 0) {
        // 0x8004DD64: andi        $t7, $v0, 0x400
        ctx->r15 = ctx->r2 & 0X400;
            goto L_8004DD94;
    }
    goto skip_7;
    // 0x8004DD64: andi        $t7, $v0, 0x400
    ctx->r15 = ctx->r2 & 0X400;
    skip_7:
    // 0x8004DD68: lwc1        $f18, 0xC4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004DD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004DD70: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8004DD74: jalr        $v1
    // 0x8004DD78: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_2;
    // 0x8004DD78: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8004DD7C: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004DD80: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8004DD84: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x8004DD88: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8004DD8C: lhu         $v0, 0x4C($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X4C);
L_8004DD90:
    // 0x8004DD90: andi        $t7, $v0, 0x400
    ctx->r15 = ctx->r2 & 0X400;
L_8004DD94:
    // 0x8004DD94: beq         $t7, $zero, L_8004DDAC
    if (ctx->r15 == 0) {
        // 0x8004DD98: andi        $t9, $v0, 0x800
        ctx->r25 = ctx->r2 & 0X800;
            goto L_8004DDAC;
    }
    // 0x8004DD98: andi        $t9, $v0, 0x800
    ctx->r25 = ctx->r2 & 0X800;
    // 0x8004DD9C: jal         0x8004DA60
    // 0x8004DDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004DA60(rdram, ctx);
        goto after_3;
    // 0x8004DDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8004DDA4: b           L_8004DDC4
    // 0x8004DDA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8004DDC4;
    // 0x8004DDA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004DDAC:
    // 0x8004DDAC: beql        $t9, $zero, L_8004DDC4
    if (ctx->r25 == 0) {
        // 0x8004DDB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004DDC4;
    }
    goto skip_8;
    // 0x8004DDB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8004DDB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004DDB8: nop

    // 0x8004DDBC: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
L_8004DDC0:
    // 0x8004DDC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004DDC4:
    // 0x8004DDC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004DDC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004DDCC: jr          $ra
    // 0x8004DDD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004DDD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8064A43C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A43C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A444: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8064A448: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8064A44C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064A450: jal         0x8005FCA8
    // 0x8064A454: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x8064A454: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    after_0:
    // 0x8064A458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064A45C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A460: jr          $ra
    // 0x8064A464: nop

    return;
    // 0x8064A464: nop

;}
RECOMP_FUNC void func_8055413C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8055413C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80554140: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80554144: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80554148: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8055414C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80554150: addiu       $a1, $a2, 0x6C
    ctx->r5 = ADD32(ctx->r6, 0X6C);
    // 0x80554154: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80554158: jal         0x80553FF0
    // 0x8055415C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80553FF0(rdram, ctx);
        goto after_0;
    // 0x8055415C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80554160: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80554164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80554168: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8055416C: jal         0x80048F84
    // 0x80554170: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80554170: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80554174: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80554178: jal         0x80048F84
    // 0x8055417C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8055417C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80554180: lw          $t6, 0xDE8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XDE8);
    // 0x80554184: bne         $t6, $zero, L_805541C0
    if (ctx->r14 != 0) {
        // 0x80554188: nop
    
            goto L_805541C0;
    }
    // 0x80554188: nop

    // 0x8055418C: jal         0x8005FD1C
    // 0x80554190: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8005FD1C(rdram, ctx);
        goto after_3;
    // 0x80554190: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80554194: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80554198: lw          $t8, 0x174($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X174);
    // 0x8055419C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x805541A0: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x805541A4: jal         0x8005FD1C
    // 0x805541A8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_8005FD1C(rdram, ctx);
        goto after_4;
    // 0x805541A8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_4:
    // 0x805541AC: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x805541B0: lw          $t1, 0x174($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X174);
    // 0x805541B4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x805541B8: b           L_805541C8
    // 0x805541BC: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
        goto L_805541C8;
    // 0x805541BC: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
L_805541C0:
    // 0x805541C0: jal         0x80553D2C
    // 0x805541C4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80553D2C(rdram, ctx);
        goto after_5;
    // 0x805541C4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_5:
L_805541C8:
    // 0x805541C8: lw          $v0, 0xDF8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDF8);
    // 0x805541CC: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4174) << 16);
    // 0x805541D0: beq         $v0, $zero, L_805541DC
    if (ctx->r2 == 0) {
        // 0x805541D4: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_805541DC;
    }
    // 0x805541D4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x805541D8: sw          $t3, 0xDF8($s0)
    MEM_W(0XDF8, ctx->r16) = ctx->r11;
L_805541DC:
    // 0x805541DC: lw          $v0, 0xDE4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDE4);
    // 0x805541E0: beq         $v0, $zero, L_805541EC
    if (ctx->r2 == 0) {
        // 0x805541E4: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_805541EC;
    }
    // 0x805541E4: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x805541E8: sw          $t4, 0xDE4($s0)
    MEM_W(0XDE4, ctx->r16) = ctx->r12;
L_805541EC:
    // 0x805541EC: lw          $t5, 0xDF8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XDF8);
    // 0x805541F0: beql        $t5, $zero, L_80554230
    if (ctx->r13 == 0) {
        // 0x805541F4: lwc1        $f0, 0xFFC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XFFC);
            goto L_80554230;
    }
    goto skip_0;
    // 0x805541F4: lwc1        $f0, 0xFFC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XFFC);
    skip_0:
    // 0x805541F8: lw          $v0, 0xDE4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDE4);
    // 0x805541FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80554200: beq         $v0, $zero, L_80554220
    if (ctx->r2 == 0) {
        // 0x80554204: sra         $t6, $v0, 2
        ctx->r14 = S32(SIGNED(ctx->r2) >> 2);
            goto L_80554220;
    }
    // 0x80554204: sra         $t6, $v0, 2
    ctx->r14 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80554208: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8055420C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80554210: nop

    // 0x80554214: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80554218: b           L_8055428C
    // 0x8055421C: swc1        $f6, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f6.u32l;
        goto L_8055428C;
    // 0x8055421C: swc1        $f6, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f6.u32l;
L_80554220:
    // 0x80554220: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80554224: b           L_8055428C
    // 0x80554228: swc1        $f12, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f12.u32l;
        goto L_8055428C;
    // 0x80554228: swc1        $f12, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f12.u32l;
    // 0x8055422C: lwc1        $f0, 0xFFC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XFFC);
L_80554230:
    // 0x80554230: lwc1        $f8, 0x4C94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4174));
    // 0x80554234: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4178) << 16);
    // 0x80554238: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8055423C: nop

    // 0x80554240: bc1t        L_80554258
    if (c1cs) {
        // 0x80554244: nop
    
            goto L_80554258;
    }
    // 0x80554244: nop

    // 0x80554248: lwc1        $f10, 0x4C98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4178));
    // 0x8055424C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80554250: nop

    // 0x80554254: bc1f        L_80554274
    if (!c1cs) {
        // 0x80554258: lui         $at, 0x8055
        ctx->r1 = S32(RELOC_HI16(354, 0X417C) << 16);
            goto L_80554274;
    }
L_80554258:
    // 0x80554258: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X417C) << 16);
    // 0x8055425C: lwc1        $f16, 0x4C9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X417C));
    // 0x80554260: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(354, 0X4180) << 16);
    // 0x80554264: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80554268: nop

    // 0x8055426C: bc1f        L_80554280
    if (!c1cs) {
        // 0x80554270: nop
    
            goto L_80554280;
    }
    // 0x80554270: nop

L_80554274:
    // 0x80554274: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80554278: b           L_8055428C
    // 0x8055427C: swc1        $f18, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f18.u32l;
        goto L_8055428C;
    // 0x8055427C: swc1        $f18, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f18.u32l;
L_80554280:
    // 0x80554280: lwc1        $f4, 0x4CA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(354, 0X4180));
    // 0x80554284: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80554288: swc1        $f6, 0xFFC($s0)
    MEM_W(0XFFC, ctx->r16) = ctx->f6.u32l;
L_8055428C:
    // 0x8055428C: jal         0x805514AC
    // 0x80554290: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_805514AC(rdram, ctx);
        goto after_6;
    // 0x80554290: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_6:
    // 0x80554294: lwc1        $f2, 0xD60($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XD60);
    // 0x80554298: lwc1        $f0, 0xD5C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XD5C);
    // 0x8055429C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805542A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805542A4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x805542A8: addiu       $v0, $s0, 0x908
    ctx->r2 = ADD32(ctx->r16, 0X908);
    // 0x805542AC: addiu       $v1, $s0, 0x910
    ctx->r3 = ADD32(ctx->r16, 0X910);
    // 0x805542B0: bc1tl       L_805543B4
    if (c1cs) {
        // 0x805542B4: lw          $t8, 0xDCC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XDCC);
            goto L_805543B4;
    }
    goto skip_1;
    // 0x805542B4: lw          $t8, 0xDCC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XDCC);
    skip_1:
    // 0x805542B8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805542BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805542C0: bc1fl       L_80554348
    if (!c1cs) {
        // 0x805542C4: sub.s       $f10, $f0, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80554348;
    }
    goto skip_2;
    // 0x805542C4: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x805542C8: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x805542CC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805542D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805542D4: nop

    // 0x805542D8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x805542DC: nop

    // 0x805542E0: bc1fl       L_80554310
    if (!c1cs) {
        // 0x805542E4: sub.s       $f4, $f0, $f12
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_80554310;
    }
    goto skip_3;
    // 0x805542E4: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    skip_3:
    // 0x805542E8: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x805542EC: swc1        $f16, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f16.u32l;
    // 0x805542F0: lwc1        $f18, 0xD5C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XD5C);
    // 0x805542F4: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x805542F8: nop

    // 0x805542FC: bc1fl       L_805543B4
    if (!c1cs) {
        // 0x80554300: lw          $t8, 0xDCC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XDCC);
            goto L_805543B4;
    }
    goto skip_4;
    // 0x80554300: lw          $t8, 0xDCC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XDCC);
    skip_4:
    // 0x80554304: b           L_805543B0
    // 0x80554308: swc1        $f2, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f2.u32l;
        goto L_805543B0;
    // 0x80554308: swc1        $f2, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f2.u32l;
    // 0x8055430C: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
L_80554310:
    // 0x80554310: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80554314: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80554318: swc1        $f4, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f4.u32l;
    // 0x8055431C: lwc1        $f0, 0xD5C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XD5C);
    // 0x80554320: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80554324: nop

    // 0x80554328: bc1fl       L_805543B4
    if (!c1cs) {
        // 0x8055432C: lw          $t8, 0xDCC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XDCC);
            goto L_805543B4;
    }
    goto skip_5;
    // 0x8055432C: lw          $t8, 0xDCC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XDCC);
    skip_5:
    // 0x80554330: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80554334: nop

    // 0x80554338: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8055433C: b           L_805543B0
    // 0x80554340: swc1        $f8, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f8.u32l;
        goto L_805543B0;
    // 0x80554340: swc1        $f8, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f8.u32l;
    // 0x80554344: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
L_80554348:
    // 0x80554348: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8055434C: nop

    // 0x80554350: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80554354: nop

    // 0x80554358: bc1fl       L_80554388
    if (!c1cs) {
        // 0x8055435C: add.s       $f6, $f0, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_80554388;
    }
    goto skip_6;
    // 0x8055435C: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    skip_6:
    // 0x80554360: sub.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80554364: swc1        $f18, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f18.u32l;
    // 0x80554368: lwc1        $f4, 0xD5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD5C);
    // 0x8055436C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80554370: nop

    // 0x80554374: bc1fl       L_805543B4
    if (!c1cs) {
        // 0x80554378: lw          $t8, 0xDCC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XDCC);
            goto L_805543B4;
    }
    goto skip_7;
    // 0x80554378: lw          $t8, 0xDCC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XDCC);
    skip_7:
    // 0x8055437C: b           L_805543B0
    // 0x80554380: swc1        $f2, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f2.u32l;
        goto L_805543B0;
    // 0x80554380: swc1        $f2, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f2.u32l;
    // 0x80554384: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
L_80554388:
    // 0x80554388: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8055438C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80554390: swc1        $f6, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f6.u32l;
    // 0x80554394: lwc1        $f0, 0xD5C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XD5C);
    // 0x80554398: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8055439C: nop

    // 0x805543A0: bc1fl       L_805543B4
    if (!c1cs) {
        // 0x805543A4: lw          $t8, 0xDCC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XDCC);
            goto L_805543B4;
    }
    goto skip_8;
    // 0x805543A4: lw          $t8, 0xDCC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XDCC);
    skip_8:
    // 0x805543A8: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x805543AC: swc1        $f8, 0xD5C($s0)
    MEM_W(0XD5C, ctx->r16) = ctx->f8.u32l;
L_805543B0:
    // 0x805543B0: lw          $t8, 0xDCC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XDCC);
L_805543B4:
    // 0x805543B4: bnel        $t8, $zero, L_805544A0
    if (ctx->r24 != 0) {
        // 0x805543B8: lwc1        $f4, 0x0($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
            goto L_805544A0;
    }
    goto skip_9;
    // 0x805543B8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    skip_9:
    // 0x805543BC: lw          $v0, 0xD54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD54);
    // 0x805543C0: bne         $v0, $zero, L_80554454
    if (ctx->r2 != 0) {
        // 0x805543C4: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80554454;
    }
    // 0x805543C4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x805543C8: lw          $v0, 0xD58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD58);
    // 0x805543CC: swc1        $f12, 0xDB8($s0)
    MEM_W(0XDB8, ctx->r16) = ctx->f12.u32l;
    // 0x805543D0: slti        $at, $v0, 0x120
    ctx->r1 = SIGNED(ctx->r2) < 0X120 ? 1 : 0;
    // 0x805543D4: beq         $at, $zero, L_805543E4
    if (ctx->r1 == 0) {
        // 0x805543D8: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_805543E4;
    }
    // 0x805543D8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x805543DC: b           L_80554410
    // 0x805543E0: sw          $t9, 0xD58($s0)
    MEM_W(0XD58, ctx->r16) = ctx->r25;
        goto L_80554410;
    // 0x805543E0: sw          $t9, 0xD58($s0)
    MEM_W(0XD58, ctx->r16) = ctx->r25;
L_805543E4:
    // 0x805543E4: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x805543E8: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    // 0x805543EC: jal         0x80067BBC
    // 0x805543F0: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_7;
    // 0x805543F0: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    after_7:
    // 0x805543F4: addiu       $a0, $zero, 0x1FE
    ctx->r4 = ADD32(0, 0X1FE);
    // 0x805543F8: jal         0x80067818
    // 0x805543FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x805543FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x80554400: addiu       $t0, $zero, 0x120
    ctx->r8 = ADD32(0, 0X120);
    // 0x80554404: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x80554408: sw          $t0, 0xD58($s0)
    MEM_W(0XD58, ctx->r16) = ctx->r8;
    // 0x8055440C: sw          $t1, 0xD54($s0)
    MEM_W(0XD54, ctx->r16) = ctx->r9;
L_80554410:
    // 0x80554410: lw          $t2, 0xD50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XD50);
    // 0x80554414: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80554418: sw          $t3, 0xD50($s0)
    MEM_W(0XD50, ctx->r16) = ctx->r11;
    // 0x8055441C: bgez        $t3, L_8055442C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80554420: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_8055442C;
    }
    // 0x80554420: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80554424: addiu       $v1, $t3, 0x120
    ctx->r3 = ADD32(ctx->r11, 0X120);
    // 0x80554428: sw          $v1, 0xD50($s0)
    MEM_W(0XD50, ctx->r16) = ctx->r3;
L_8055442C:
    // 0x8055442C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80554430: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x80554434: addu        $v0, $s0, $t5
    ctx->r2 = ADD32(ctx->r16, ctx->r13);
    // 0x80554438: lwc1        $f10, 0x3C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X3C);
    // 0x8055443C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80554440: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80554444: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80554448: lwc1        $f16, 0x40($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X40);
    // 0x8055444C: b           L_80554540
    // 0x80554450: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
        goto L_80554540;
    // 0x80554450: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_80554454:
    // 0x80554454: lw          $t9, 0xD58($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XD58);
    // 0x80554458: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8055445C: sw          $t8, 0xD54($s0)
    MEM_W(0XD54, ctx->r16) = ctx->r24;
    // 0x80554460: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80554464: slti        $at, $t0, 0x18
    ctx->r1 = SIGNED(ctx->r8) < 0X18 ? 1 : 0;
    // 0x80554468: sw          $t0, 0xD58($s0)
    MEM_W(0XD58, ctx->r16) = ctx->r8;
    // 0x8055446C: beq         $at, $zero, L_80554540
    if (ctx->r1 == 0) {
        // 0x80554470: swc1        $f18, 0xDB8($s0)
        MEM_W(0XDB8, ctx->r16) = ctx->f18.u32l;
            goto L_80554540;
    }
    // 0x80554470: swc1        $f18, 0xDB8($s0)
    MEM_W(0XDB8, ctx->r16) = ctx->f18.u32l;
    // 0x80554474: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80554478: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    // 0x8055447C: jal         0x80067BBC
    // 0x80554480: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_9;
    // 0x80554480: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    after_9:
    // 0x80554484: addiu       $a0, $zero, 0x1FF
    ctx->r4 = ADD32(0, 0X1FF);
    // 0x80554488: jal         0x80067818
    // 0x8055448C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x8055448C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80554490: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x80554494: b           L_80554540
    // 0x80554498: sw          $t2, 0xD58($s0)
    MEM_W(0XD58, ctx->r16) = ctx->r10;
        goto L_80554540;
    // 0x80554498: sw          $t2, 0xD58($s0)
    MEM_W(0XD58, ctx->r16) = ctx->r10;
    // 0x8055449C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
L_805544A0:
    // 0x805544A0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x805544A4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805544A8: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x805544AC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805544B0: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x805544B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805544B8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805544BC: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x805544C0: nop

    // 0x805544C4: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x805544C8: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x805544CC: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x805544D0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x805544D4: nop

    // 0x805544D8: bc1f        L_80554524
    if (!c1cs) {
        // 0x805544DC: nop
    
            goto L_80554524;
    }
    // 0x805544DC: nop

    // 0x805544E0: lw          $v0, 0xDD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDD0);
    // 0x805544E4: beq         $v0, $zero, L_805544F4
    if (ctx->r2 == 0) {
        // 0x805544E8: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_805544F4;
    }
    // 0x805544E8: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x805544EC: b           L_80554540
    // 0x805544F0: sw          $t3, 0xDD0($s0)
    MEM_W(0XDD0, ctx->r16) = ctx->r11;
        goto L_80554540;
    // 0x805544F0: sw          $t3, 0xDD0($s0)
    MEM_W(0XDD0, ctx->r16) = ctx->r11;
L_805544F4:
    // 0x805544F4: lw          $t4, 0xDE8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XDE8);
    // 0x805544F8: sw          $zero, 0xDCC($s0)
    MEM_W(0XDCC, ctx->r16) = 0;
    // 0x805544FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80554500: bnel        $t4, $zero, L_80554544
    if (ctx->r12 != 0) {
        // 0x80554504: lw          $t0, 0xDB4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0XDB4);
            goto L_80554544;
    }
    goto skip_10;
    // 0x80554504: lw          $t0, 0xDB4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XDB4);
    skip_10:
    // 0x80554508: sw          $zero, 0xD54($s0)
    MEM_W(0XD54, ctx->r16) = 0;
    // 0x8055450C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80554510: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80554514: jal         0x8055484C
    // 0x80554518: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8055484C(rdram, ctx);
        goto after_11;
    // 0x80554518: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_11:
    // 0x8055451C: b           L_80554584
    // 0x80554520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80554584;
    // 0x80554520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80554524:
    // 0x80554524: lw          $t6, 0xD58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XD58);
    // 0x80554528: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x8055452C: addiu       $t7, $t6, -0xA
    ctx->r15 = ADD32(ctx->r14, -0XA);
    // 0x80554530: slti        $at, $t7, 0x18
    ctx->r1 = SIGNED(ctx->r15) < 0X18 ? 1 : 0;
    // 0x80554534: beq         $at, $zero, L_80554540
    if (ctx->r1 == 0) {
        // 0x80554538: sw          $t7, 0xD58($s0)
        MEM_W(0XD58, ctx->r16) = ctx->r15;
            goto L_80554540;
    }
    // 0x80554538: sw          $t7, 0xD58($s0)
    MEM_W(0XD58, ctx->r16) = ctx->r15;
    // 0x8055453C: sw          $t9, 0xD58($s0)
    MEM_W(0XD58, ctx->r16) = ctx->r25;
L_80554540:
    // 0x80554540: lw          $t0, 0xDB4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XDB4);
L_80554544:
    // 0x80554544: lui         $t9, 0x8055
    ctx->r25 = S32(RELOC_HI16(354, 0X411C) << 16);
    // 0x80554548: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8055454C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80554550: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x80554554: lw          $t9, 0x4C3C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(354, 0X411C));
    // 0x80554558: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8055455C: jalr        $t9
    // 0x80554560: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_12;
    // 0x80554560: nop

    after_12:
    // 0x80554564: lw          $t2, 0xDE8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XDE8);
    // 0x80554568: beql        $t2, $zero, L_80554584
    if (ctx->r10 == 0) {
        // 0x8055456C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80554584;
    }
    goto skip_11;
    // 0x8055456C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80554570: jal         0x80553DAC
    // 0x80554574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80553DAC(rdram, ctx);
        goto after_13;
    // 0x80554574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80554578: jal         0x80553EB0
    // 0x8055457C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80553EB0(rdram, ctx);
        goto after_14;
    // 0x8055457C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80554580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80554584:
    // 0x80554584: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80554588: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8055458C: jr          $ra
    // 0x80554590: nop

    return;
    // 0x80554590: nop

;}
RECOMP_FUNC void func_8078FE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078FE4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8078FE50: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8078FE54: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8078FE58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078FE5C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8078FE60: lui         $a0, 0x8079
    ctx->r4 = S32(RELOC_HI16(814, 0XF30) << 16);
    // 0x8078FE64: lui         $a1, 0x401F
    ctx->r5 = S32(0X401F << 16);
    // 0x8078FE68: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8078FE6C: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8078FE70: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(814, 0XF30));
    // 0x8078FE74: jal         0x80046804
    // 0x8078FE78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x8078FE78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8078FE7C: beq         $v0, $zero, L_8078FEA4
    if (ctx->r2 == 0) {
        // 0x8078FE80: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8078FEA4;
    }
    // 0x8078FE80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8078FE84: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8078FE88: addiu       $t6, $t6, -0x71F4
    ctx->r14 = ADD32(ctx->r14, -0X71F4);
    // 0x8078FE8C: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x8078FE90: jal         0x80052BA4
    // 0x8078FE94: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80052BA4(rdram, ctx);
        goto after_1;
    // 0x8078FE94: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8078FE98: jal         0x80044194
    // 0x8078FE9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x8078FE9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8078FEA0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_8078FEA4:
    // 0x8078FEA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078FEA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8078FEAC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8078FEB0: jr          $ra
    // 0x8078FEB4: nop

    return;
    // 0x8078FEB4: nop

    // 0x8078FEB8: nop

    // 0x8078FEBC: nop

;}
RECOMP_FUNC void func_8004EEB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EEB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004EEBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004EEC0: beq         $a0, $zero, L_8004EEDC
    if (ctx->r4 == 0) {
        // 0x8004EEC4: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8004EEDC;
    }
    // 0x8004EEC4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8004EEC8: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x8004EECC: jal         0x80064E84
    // 0x8004EED0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8004EED0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004EED4: jal         0x80064E84
    // 0x8004EED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8004EED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_8004EEDC:
    // 0x8004EEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004EEE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004EEE4: jr          $ra
    // 0x8004EEE8: nop

    return;
    // 0x8004EEE8: nop

;}
RECOMP_FUNC void guLookAtF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087080: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80087084: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80087088: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8008708C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80087090: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80087094: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80087098: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8008709C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800870A0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800870A4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800870A8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800870AC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800870B0: jal         0x80086EA0
    // 0x800870B4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800870B4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800870B8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800870BC: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800870C0: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800870C4: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800870C8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800870CC: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800870D0: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800870D4: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800870D8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800870DC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800870E0: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800870E4: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800870E8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800870EC: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800870F0: jal         0x80089DE0
    // 0x800870F4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800870F4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800870F8: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800870FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80087100: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80087104: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80087108: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8008710C: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80087110: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80087114: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x80087118: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8008711C: nop

    // 0x80087120: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80087124: nop

    // 0x80087128: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8008712C: nop

    // 0x80087130: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80087134: nop

    // 0x80087138: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8008713C: sub.s       $f26, $f8, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80087140: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80087144: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80087148: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8008714C: sub.s       $f28, $f8, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80087150: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80087154: nop

    // 0x80087158: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8008715C: sub.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80087160: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80087164: nop

    // 0x80087168: mul.s       $f6, $f28, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8008716C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80087170: mul.s       $f10, $f30, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x80087174: jal         0x80089DE0
    // 0x80087178: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80087178: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x8008717C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80087180: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80087184: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80087188: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8008718C: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80087190: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x80087194: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x80087198: nop

    // 0x8008719C: mul.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x800871A0: nop

    // 0x800871A4: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x800871A8: nop

    // 0x800871AC: mul.s       $f10, $f22, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x800871B0: nop

    // 0x800871B4: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x800871B8: nop

    // 0x800871BC: mul.s       $f6, $f24, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x800871C0: nop

    // 0x800871C4: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x800871C8: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800871CC: mul.s       $f10, $f20, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x800871D0: nop

    // 0x800871D4: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x800871D8: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800871DC: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800871E0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800871E4: nop

    // 0x800871E8: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800871EC: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x800871F0: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800871F4: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800871F8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800871FC: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x80087200: jal         0x80089DE0
    // 0x80087204: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80087204: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_3:
    // 0x80087208: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8008720C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80087210: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80087214: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80087218: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8008721C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x80087220: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80087224: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80087228: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008722C: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80087230: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80087234: nop

    // 0x80087238: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8008723C: nop

    // 0x80087240: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80087244: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x80087248: swc1        $f26, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f26.u32l;
    // 0x8008724C: swc1        $f28, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f28.u32l;
    // 0x80087250: swc1        $f30, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f30.u32l;
    // 0x80087254: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80087258: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8008725C: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80087260: nop

    // 0x80087264: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x80087268: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8008726C: swc1        $f14, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
    // 0x80087270: swc1        $f12, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f12.u32l;
    // 0x80087274: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80087278: mul.s       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x8008727C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80087280: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x80087284: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x80087288: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8008728C: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x80087290: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x80087294: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80087298: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8008729C: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800872A0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800872A4: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800872A8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800872AC: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    // 0x800872B0: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800872B4: swc1        $f22, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f22.u32l;
    // 0x800872B8: swc1        $f24, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f24.u32l;
    // 0x800872BC: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800872C0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800872C4: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800872C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800872CC: nop

    // 0x800872D0: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800872D4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800872D8: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800872DC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800872E0: mul.s       $f8, $f14, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800872E4: nop

    // 0x800872E8: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x800872EC: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800872F0: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x800872F4: mul.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800872F8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800872FC: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80087300: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80087304: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x80087308: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x8008730C: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x80087310: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80087314: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80087318: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8008731C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80087320: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80087324: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80087328: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8008732C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80087330: jr          $ra
    // 0x80087334: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80087334: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8007C844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C844: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007C848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C84C: jal         0x80086880
    // 0x8007C850: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_0;
    // 0x8007C850: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8007C854: jal         0x8008B920
    // 0x8007C858: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8007C858: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8007C85C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007C860: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8007C864: jal         0x800825F0
    // 0x8007C868: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x8007C868: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8007C86C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8007C870: addiu       $a1, $a1, -0x65F0
    ctx->r5 = ADD32(ctx->r5, -0X65F0);
    // 0x8007C874: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8007C878: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8007C87C: beql        $t6, $zero, L_8007C91C
    if (ctx->r14 == 0) {
        // 0x8007C880: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8007C91C;
    }
    goto skip_0;
    // 0x8007C880: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8007C884: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8007C888: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8007C88C: addiu       $t9, $t9, -0x1C60
    ctx->r25 = ADD32(ctx->r25, -0X1C60);
    // 0x8007C890: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8007C894: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8007C898: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8007C89C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8007C8A0: lhu         $t0, 0x4($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X4);
    // 0x8007C8A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007C8A8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8007C8AC: bnel        $t0, $at, L_8007C91C
    if (ctx->r8 != ctx->r1) {
        // 0x8007C8B0: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8007C91C;
    }
    goto skip_1;
    // 0x8007C8B0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8007C8B4: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    // 0x8007C8B8: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8007C8BC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C8C0: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8007C8C4: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x8007C8C8: lw          $t4, 0x18($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X18);
    // 0x8007C8CC: lw          $t5, 0x1C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C);
    // 0x8007C8D0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8007C8D4: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x8007C8D8: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8007C8DC: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x8007C8E0: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8007C8E4: sltu        $at, $t9, $t7
    ctx->r1 = ctx->r25 < ctx->r15 ? 1 : 0;
    // 0x8007C8E8: addu        $t8, $at, $t4
    ctx->r24 = ADD32(ctx->r1, ctx->r12);
    // 0x8007C8EC: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8007C8F0: subu        $t2, $t8, $t0
    ctx->r10 = SUB32(ctx->r24, ctx->r8);
    // 0x8007C8F4: sltu        $at, $t9, $t1
    ctx->r1 = ctx->r25 < ctx->r9 ? 1 : 0;
    // 0x8007C8F8: subu        $t2, $t2, $at
    ctx->r10 = SUB32(ctx->r10, ctx->r1);
    // 0x8007C8FC: sw          $t2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r10;
    // 0x8007C900: subu        $t3, $t9, $t1
    ctx->r11 = SUB32(ctx->r25, ctx->r9);
    // 0x8007C904: sw          $t3, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r11;
    // 0x8007C908: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x8007C90C: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
    // 0x8007C910: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x8007C914: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x8007C918: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8007C91C:
    // 0x8007C91C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8007C920: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007C924: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x8007C928: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8007C92C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8007C930: addiu       $t7, $t7, -0x1C60
    ctx->r15 = ADD32(ctx->r15, -0X1C60);
    // 0x8007C934: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C938: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8007C93C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8007C940: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x8007C944: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    // 0x8007C948: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8007C94C: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8007C950: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8007C954: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x8007C958: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x8007C95C: jal         0x800825F0
    // 0x8007C960: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x8007C960: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    after_3:
    // 0x8007C964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C968: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007C96C: jr          $ra
    // 0x8007C970: nop

    return;
    // 0x8007C970: nop

;}
RECOMP_FUNC void func_8067B7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067B7D8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8067B7DC: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x8067B7E0: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x8067B7E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8067B7E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8067B7EC: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8067B7F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8067B7F4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8067B7F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8067B7FC: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x8067B800: lui         $t1, 0xFFFC
    ctx->r9 = S32(0XFFFC << 16);
    // 0x8067B804: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8067B808: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8067B80C: ori         $t1, $t1, 0xF279
    ctx->r9 = ctx->r9 | 0XF279;
    // 0x8067B810: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8067B814: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8067B818: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8067B81C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8067B820: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8067B824: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x8067B828: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8067B82C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8067B830: ori         $t4, $t4, 0xAC80
    ctx->r12 = ctx->r12 | 0XAC80;
    // 0x8067B834: ori         $t3, $t3, 0x18
    ctx->r11 = ctx->r11 | 0X18;
    // 0x8067B838: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8067B83C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8067B840: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8067B844: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x8067B848: lui         $a3, 0x55
    ctx->r7 = S32(0X55 << 16);
    // 0x8067B84C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8067B850: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8067B854: ori         $a3, $a3, 0x3048
    ctx->r7 = ctx->r7 | 0X3048;
    // 0x8067B858: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x8067B85C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8067B860: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x8067B864: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8067B868: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8067B86C: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8067B870: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8067B874: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8067B878: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x8067B87C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8067B880: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8067B884: addiu       $t1, $zero, 0x2204
    ctx->r9 = ADD32(0, 0X2204);
    // 0x8067B888: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x8067B88C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8067B890: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8067B894: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8067B898: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8067B89C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8067B8A0: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8067B8A4: lui         $t3, 0xBB00
    ctx->r11 = S32(0XBB00 << 16);
    // 0x8067B8A8: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8067B8AC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8067B8B0: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x8067B8B4: ori         $t4, $t4, 0x8000
    ctx->r12 = ctx->r12 | 0X8000;
    // 0x8067B8B8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8067B8BC: jr          $ra
    // 0x8067B8C0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    return;
    // 0x8067B8C0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void func_800489D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800489D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800489D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800489D8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800489DC: lbu         $t7, 0x7EA5($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7EA5);
    // 0x800489E0: lbu         $t6, 0x10($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X10);
    // 0x800489E4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800489E8: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800489EC: beql        $at, $zero, L_80048A00
    if (ctx->r1 == 0) {
        // 0x800489F0: lw          $a0, 0x180($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X180);
            goto L_80048A00;
    }
    goto skip_0;
    // 0x800489F0: lw          $a0, 0x180($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X180);
    skip_0:
    // 0x800489F4: b           L_80048A20
    // 0x800489F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80048A20;
    // 0x800489F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800489FC: lw          $a0, 0x180($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X180);
L_80048A00:
    // 0x80048A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80048A04: beq         $a0, $zero, L_80048A20
    if (ctx->r4 == 0) {
        // 0x80048A08: nop
    
            goto L_80048A20;
    }
    // 0x80048A08: nop

    // 0x80048A0C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80048A10: jalr        $t9
    // 0x80048A14: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80048A14: nop

    after_0:
    // 0x80048A18: b           L_80048A24
    // 0x80048A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048A24;
    // 0x80048A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048A20:
    // 0x80048A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048A24:
    // 0x80048A24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048A28: jr          $ra
    // 0x80048A2C: nop

    return;
    // 0x80048A2C: nop

;}
RECOMP_FUNC void func_8000D330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000D334: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000D338: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000D33C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8000D340: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8000D344: lbu         $v0, -0x72F0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X72F0);
    // 0x8000D348: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D34C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D350: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8000D354: bne         $t7, $at, L_8000D384
    if (ctx->r15 != ctx->r1) {
        // 0x8000D358: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000D384;
    }
    // 0x8000D358: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000D35C: andi        $t8, $v0, 0x80
    ctx->r24 = ctx->r2 & 0X80;
    // 0x8000D360: bne         $t8, $zero, L_8000D378
    if (ctx->r24 != 0) {
        // 0x8000D364: nop
    
            goto L_8000D378;
    }
    // 0x8000D364: nop

    // 0x8000D368: jal         0x8000DCB4
    // 0x8000D36C: nop

    func_8000DCB4(rdram, ctx);
        goto after_0;
    // 0x8000D36C: nop

    after_0:
    // 0x8000D370: b           L_8000D384
    // 0x8000D374: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
        goto L_8000D384;
    // 0x8000D374: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8000D378:
    // 0x8000D378: jal         0x8000DCC8
    // 0x8000D37C: nop

    func_8000DCC8(rdram, ctx);
        goto after_1;
    // 0x8000D37C: nop

    after_1:
    // 0x8000D380: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
L_8000D384:
    // 0x8000D384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000D388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000D38C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000D390: jr          $ra
    // 0x8000D394: nop

    return;
    // 0x8000D394: nop

;}
RECOMP_FUNC void func_8076D4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D4E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8076D4E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076D4E8: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076D4EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8076D4F0: lui         $t9, 0x8077
    ctx->r25 = S32(RELOC_HI16(766, 0X3A30) << 16);
    // 0x8076D4F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8076D4F8: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x8076D4FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8076D500: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8076D504: lw          $t9, 0x220($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(766, 0X3A30));
    // 0x8076D508: jalr        $t9
    // 0x8076D50C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8076D50C: nop

    after_0:
    // 0x8076D510: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8076D514: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8076D518: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x8076D51C: bnel        $t8, $at, L_8076D568
    if (ctx->r24 != ctx->r1) {
        // 0x8076D520: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8076D568;
    }
    goto skip_0;
    // 0x8076D520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8076D524: jal         0x8004700C
    // 0x8076D528: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x8076D528: nop

    after_1:
    // 0x8076D52C: beql        $v0, $zero, L_8076D568
    if (ctx->r2 == 0) {
        // 0x8076D530: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8076D568;
    }
    goto skip_1;
    // 0x8076D530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8076D534: lw          $t0, 0x180($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X180);
    // 0x8076D538: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8076D53C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8076D540: bnel        $t0, $zero, L_8076D568
    if (ctx->r8 != 0) {
        // 0x8076D544: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8076D568;
    }
    goto skip_2;
    // 0x8076D544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8076D548: jal         0x80047AB8
    // 0x8076D54C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x8076D54C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x8076D550: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8076D554: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8076D558: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x8076D55C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8076D560: swc1        $f6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f6.u32l;
    // 0x8076D564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8076D568:
    // 0x8076D568: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8076D56C: jr          $ra
    // 0x8076D570: nop

    return;
    // 0x8076D570: nop

;}
RECOMP_FUNC void func_80526E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526E7C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80526E80: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X615C) << 16);
    // 0x80526E84: lwc1        $f6, -0x3FA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X615C));
    // 0x80526E88: lwc1        $f2, 0x30($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80526E8C: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80526E90: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6160) << 16);
    // 0x80526E94: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80526E98: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80526E9C: nop

    // 0x80526EA0: bc1tl       L_80526F08
    if (c1cs) {
        // 0x80526EA4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80526F08;
    }
    goto skip_0;
    // 0x80526EA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80526EA8: lwc1        $f8, -0x3FA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6160));
    // 0x80526EAC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80526EB0: nop

    // 0x80526EB4: bc1tl       L_80526F08
    if (c1cs) {
        // 0x80526EB8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80526F08;
    }
    goto skip_1;
    // 0x80526EB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80526EBC: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80526EC0: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80526EC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80526EC8: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x80526ECC: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80526ED0: bgez        $v0, L_80526EE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80526ED4: swc1        $f10, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
            goto L_80526EE8;
    }
    // 0x80526ED4: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
    // 0x80526ED8: jal         0x80527038
    // 0x80526EDC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80527038(rdram, ctx);
        goto after_0;
    // 0x80526EDC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80526EE0: b           L_80526F1C
    // 0x80526EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80526F1C;
    // 0x80526EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526EE8:
    // 0x80526EE8: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80526EEC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80526EF0: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80526EF4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80526EF8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80526EFC: b           L_80526F18
    // 0x80526F00: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80526F18;
    // 0x80526F00: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80526F04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80526F08:
    // 0x80526F08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80526F0C: nop

    // 0x80526F10: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80526F14: swc1        $f18, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f18.u32l;
L_80526F18:
    // 0x80526F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526F1C:
    // 0x80526F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526F20: jr          $ra
    // 0x80526F24: nop

    return;
    // 0x80526F24: nop

;}
RECOMP_FUNC void func_807B0704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0704: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807B0708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B070C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B0710: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807B0714: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x807B0718: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x807B071C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x807B0720: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x807B0724: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x807B0728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B072C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x807B0730: jal         0x8004921C
    // 0x807B0734: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x807B0734: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    after_0:
    // 0x807B0738: sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // 0x807B073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B0740: jal         0x8004921C
    // 0x807B0744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x807B0744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x807B0748: lbu         $t1, 0x23($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X23);
    // 0x807B074C: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x807B0750: lbu         $t3, 0x145($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X145);
    // 0x807B0754: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B0758: lw          $t5, 0x168($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X168);
    // 0x807B075C: lw          $a2, 0x16C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X16C);
    // 0x807B0760: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x807B0764: lw          $t6, 0x80($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X80);
    // 0x807B0768: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x807B076C: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    // 0x807B0770: mflo        $t2
    ctx->r10 = lo;
    // 0x807B0774: nop

    // 0x807B0778: nop

    // 0x807B077C: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B0780: mflo        $t4
    ctx->r12 = lo;
    // 0x807B0784: addu        $a3, $t4, $t6
    ctx->r7 = ADD32(ctx->r12, ctx->r14);
    // 0x807B0788: jal         0x807B03A4
    // 0x807B078C: nop

    func_807B03A4(rdram, ctx);
        goto after_2;
    // 0x807B078C: nop

    after_2:
    // 0x807B0790: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x807B0794: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x807B0798: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x807B079C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B07A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B07A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x807B07A8: jr          $ra
    // 0x807B07AC: nop

    return;
    // 0x807B07AC: nop

;}
RECOMP_FUNC void func_80470274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80470274: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80470278: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8047027C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80470280: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80470284: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80470288: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8047028C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80470290: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80470294: lw          $s1, 0x1F4($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X1F4);
    // 0x80470298: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8047029C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804702A0: lw          $t6, 0xF38($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XF38);
    // 0x804702A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804702A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804702AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804702B0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804702B4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x804702B8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804702BC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x804702C0: addu        $s4, $s1, $t7
    ctx->r20 = ADD32(ctx->r17, ctx->r15);
    // 0x804702C4: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x804702C8: jal         0x8007711C
    // 0x804702CC: lw          $a3, 0x1098($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1098);
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x804702CC: lw          $a3, 0x1098($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1098);
    after_0:
    // 0x804702D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804702D4: lui         $a3, 0xE600
    ctx->r7 = S32(0XE600 << 16);
    // 0x804702D8: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x804702DC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x804702E0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x804702E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804702E8: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x804702EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804702F0: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x804702F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x804702F8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x804702FC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80470300: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80470304: lw          $t7, 0x1094($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1094);
    // 0x80470308: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8047030C: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
    // 0x80470310: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80470314: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80470318: addiu       $s5, $zero, 0x480
    ctx->r21 = ADD32(0, 0X480);
    // 0x8047031C: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80470320: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80470324: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x80470328: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8047032C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80470330: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80470334: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80470338: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8047033C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80470340: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x80470344: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80470348: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x8047034C: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x80470350: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80470354: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80470358: lw          $t9, 0x10A0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X10A0);
    // 0x8047035C: lw          $v1, 0x109C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X109C);
    // 0x80470360: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80470364: mflo        $a0
    ctx->r4 = lo;
    // 0x80470368: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8047036C: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80470370: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80470374: slti        $at, $a0, 0x7FF
    ctx->r1 = SIGNED(ctx->r4) < 0X7FF ? 1 : 0;
    // 0x80470378: beq         $at, $zero, L_80470388
    if (ctx->r1 == 0) {
        // 0x8047037C: nop
    
            goto L_80470388;
    }
    // 0x8047037C: nop

    // 0x80470380: b           L_80470388
    // 0x80470384: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
        goto L_80470388;
    // 0x80470384: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_80470388:
    // 0x80470388: bgez        $v1, L_80470398
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8047038C: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80470398;
    }
    // 0x8047038C: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80470390: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80470394: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80470398:
    // 0x80470398: bgtz        $v0, L_804703A8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8047039C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_804703A8;
    }
    // 0x8047039C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x804703A0: b           L_804703A8
    // 0x804703A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_804703A8;
    // 0x804703A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_804703A8:
    // 0x804703A8: bgtz        $v0, L_804703B8
    if (SIGNED(ctx->r2) > 0) {
        // 0x804703AC: addiu       $t6, $t0, 0x7FF
        ctx->r14 = ADD32(ctx->r8, 0X7FF);
            goto L_804703B8;
    }
    // 0x804703AC: addiu       $t6, $t0, 0x7FF
    ctx->r14 = ADD32(ctx->r8, 0X7FF);
    // 0x804703B0: b           L_804703BC
    // 0x804703B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_804703BC;
    // 0x804703B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_804703B8:
    // 0x804703B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_804703BC:
    // 0x804703BC: div         $zero, $t6, $a2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r6)));
    // 0x804703C0: mflo        $t7
    ctx->r15 = lo;
    // 0x804703C4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x804703C8: bne         $a2, $zero, L_804703D4
    if (ctx->r6 != 0) {
        // 0x804703CC: nop
    
            goto L_804703D4;
    }
    // 0x804703CC: nop

    // 0x804703D0: break       7
    do_break(2152137680);
L_804703D4:
    // 0x804703D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x804703D8: bne         $a2, $at, L_804703EC
    if (ctx->r6 != ctx->r1) {
        // 0x804703DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_804703EC;
    }
    // 0x804703DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804703E0: bne         $t6, $at, L_804703EC
    if (ctx->r14 != ctx->r1) {
        // 0x804703E4: nop
    
            goto L_804703EC;
    }
    // 0x804703E4: nop

    // 0x804703E8: break       6
    do_break(2152137704);
L_804703EC:
    // 0x804703EC: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x804703F0: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x804703F4: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x804703F8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x804703FC: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x80470400: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80470404: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80470408: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8047040C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80470410: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80470414: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80470418: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8047041C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80470420: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80470424: lui         $s4, 0x400
    ctx->r20 = S32(0X400 << 16);
    // 0x80470428: ori         $s4, $s4, 0x6DAF
    ctx->r20 = ctx->r20 | 0X6DAF;
    // 0x8047042C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80470430: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80470434: lw          $t8, 0x109C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X109C);
    // 0x80470438: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8047043C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80470440: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x80470444: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80470448: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8047044C: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x80470450: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80470454: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80470458: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8047045C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80470460: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80470464: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80470468: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8047046C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80470470: lw          $t8, 0x10A0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X10A0);
    // 0x80470474: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80470478: lui         $t3, 0xBF00
    ctx->r11 = S32(0XBF00 << 16);
    // 0x8047047C: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80470480: lw          $t8, 0x109C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X109C);
    // 0x80470484: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80470488: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8047048C: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x80470490: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80470494: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80470498: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8047049C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x804704A0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x804704A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804704A8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_804704AC:
    // 0x804704AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804704B0: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x804704B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804704B8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x804704BC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x804704C0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x804704C4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x804704C8: addiu       $t2, $zero, 0x12
    ctx->r10 = ADD32(0, 0X12);
    // 0x804704CC: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x804704D0: sw          $s4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r20;
L_804704D4:
    // 0x804704D4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_804704D8:
    // 0x804704D8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804704DC: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x804704E0: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x804704E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x804704E8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x804704EC: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x804704F0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x804704F4: or          $t8, $a0, $t9
    ctx->r24 = ctx->r4 | ctx->r25;
    // 0x804704F8: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
    // 0x804704FC: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x80470500: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80470504: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80470508: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8047050C: sll         $t9, $a1, 8
    ctx->r25 = S32(ctx->r5 << 8);
    // 0x80470510: or          $t8, $a0, $t9
    ctx->r24 = ctx->r4 | ctx->r25;
    // 0x80470514: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80470518: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8047051C: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x80470520: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80470524: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80470528: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8047052C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80470530: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80470534: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80470538: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x8047053C: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x80470540: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80470544: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80470548: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x8047054C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80470550: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80470554: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
    // 0x80470558: or          $t6, $a0, $t7
    ctx->r14 = ctx->r4 | ctx->r15;
    // 0x8047055C: or          $t9, $t6, $a1
    ctx->r25 = ctx->r14 | ctx->r5;
    // 0x80470560: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80470564: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80470568: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8047056C: sll         $t7, $a1, 8
    ctx->r15 = S32(ctx->r5 << 8);
    // 0x80470570: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80470574: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80470578: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8047057C: andi        $t9, $t2, 0xFF
    ctx->r25 = ctx->r10 & 0XFF;
    // 0x80470580: or          $t6, $a0, $t7
    ctx->r14 = ctx->r4 | ctx->r15;
    // 0x80470584: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80470588: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8047058C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80470590: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80470594: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80470598: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8047059C: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x804705A0: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x804705A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x804705A8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x804705AC: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x804705B0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x804705B4: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x804705B8: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
    // 0x804705BC: or          $t8, $a0, $t9
    ctx->r24 = ctx->r4 | ctx->r25;
    // 0x804705C0: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x804705C4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x804705C8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x804705CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804705D0: sll         $t9, $a1, 8
    ctx->r25 = S32(ctx->r5 << 8);
    // 0x804705D4: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x804705D8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x804705DC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x804705E0: andi        $t7, $t2, 0xFF
    ctx->r15 = ctx->r10 & 0XFF;
    // 0x804705E4: or          $t8, $a0, $t9
    ctx->r24 = ctx->r4 | ctx->r25;
    // 0x804705E8: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x804705EC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x804705F0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x804705F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804705F8: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x804705FC: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80470600: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x80470604: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x80470608: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8047060C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80470610: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80470614: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80470618: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8047061C: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
    // 0x80470620: or          $t6, $a0, $t7
    ctx->r14 = ctx->r4 | ctx->r15;
    // 0x80470624: or          $t9, $t6, $a1
    ctx->r25 = ctx->r14 | ctx->r5;
    // 0x80470628: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8047062C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80470630: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80470634: sll         $t7, $a1, 8
    ctx->r15 = S32(ctx->r5 << 8);
    // 0x80470638: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x8047063C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80470640: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80470644: andi        $t9, $t2, 0xFF
    ctx->r25 = ctx->r10 & 0XFF;
    // 0x80470648: or          $t6, $a0, $t7
    ctx->r14 = ctx->r4 | ctx->r15;
    // 0x8047064C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80470650: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80470654: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80470658: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x8047065C: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80470660: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80470664: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80470668: bne         $t4, $t5, L_804704D8
    if (ctx->r12 != ctx->r13) {
        // 0x8047066C: sw          $t3, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r11;
            goto L_804704D8;
    }
    // 0x8047066C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80470670: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x80470674: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80470678: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8047067C: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x80470680: bne         $ra, $s1, L_804704D4
    if (ctx->r31 != ctx->r17) {
        // 0x80470684: addiu       $t2, $t2, 0x2
        ctx->r10 = ADD32(ctx->r10, 0X2);
            goto L_804704D4;
    }
    // 0x80470684: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x80470688: addiu       $s2, $s2, 0x120
    ctx->r18 = ADD32(ctx->r18, 0X120);
    // 0x8047068C: bne         $s2, $s5, L_804704AC
    if (ctx->r18 != ctx->r21) {
        // 0x80470690: addiu       $s3, $s3, 0x120
        ctx->r19 = ADD32(ctx->r19, 0X120);
            goto L_804704AC;
    }
    // 0x80470690: addiu       $s3, $s3, 0x120
    ctx->r19 = ADD32(ctx->r19, 0X120);
    // 0x80470694: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80470698: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8047069C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804706A0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x804706A4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x804706A8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x804706AC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x804706B0: jr          $ra
    // 0x804706B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804706B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80434EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434EF4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80434EF8: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x80434EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80434F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80434F04: beq         $t6, $zero, L_80434F24
    if (ctx->r14 == 0) {
        // 0x80434F08: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80434F24;
    }
    // 0x80434F08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80434F0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80434F10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80434F14: jal         0x804351E8
    // 0x80434F18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804351E8(rdram, ctx);
        goto after_0;
    // 0x80434F18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80434F1C: jal         0x804347CC
    // 0x80434F20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804347CC(rdram, ctx);
        goto after_1;
    // 0x80434F20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80434F24:
    // 0x80434F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80434F28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80434F2C: jr          $ra
    // 0x80434F30: nop

    return;
    // 0x80434F30: nop

;}
RECOMP_FUNC void func_80029D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029D84: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x80029D88: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x80029D8C: beq         $v0, $zero, L_80029DE0
    if (ctx->r2 == 0) {
        // 0x80029D90: nop
    
            goto L_80029DE0;
    }
    // 0x80029D90: nop

    // 0x80029D94: lhu         $t7, 0xC($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XC);
    // 0x80029D98: addiu       $at, $zero, 0x4128
    ctx->r1 = ADD32(0, 0X4128);
    // 0x80029D9C: bne         $t7, $at, L_80029DE0
    if (ctx->r15 != ctx->r1) {
        // 0x80029DA0: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_80029DE0;
    }
    // 0x80029DA0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80029DA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80029DA8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80029DAC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80029DB0: nop

    // 0x80029DB4: bc1f        L_80029DE0
    if (!c1cs) {
        // 0x80029DB8: nop
    
            goto L_80029DE0;
    }
    // 0x80029DB8: nop

    // 0x80029DBC: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80029DC0: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80029DC4: lhu         $t9, 0x64($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X64);
    // 0x80029DC8: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80029DCC: bne         $t0, $zero, L_80029DE0
    if (ctx->r8 != 0) {
        // 0x80029DD0: nop
    
            goto L_80029DE0;
    }
    // 0x80029DD0: nop

    // 0x80029DD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80029DD8: nop

    // 0x80029DDC: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
L_80029DE0:
    // 0x80029DE0: jr          $ra
    // 0x80029DE4: nop

    return;
    // 0x80029DE4: nop

;}
RECOMP_FUNC void func_805257BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805257BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x805257C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805257C4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x805257C8: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x805257CC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x805257D0: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x805257D4: jal         0x8004700C
    // 0x805257D8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805257D8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    after_0:
    // 0x805257DC: beq         $v0, $zero, L_8052597C
    if (ctx->r2 == 0) {
        // 0x805257E0: lw          $a2, 0x44($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X44);
            goto L_8052597C;
    }
    // 0x805257E0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x805257E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x805257E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805257EC: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x805257F0: jal         0x80047AB8
    // 0x805257F4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x805257F4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x805257F8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x805257FC: jal         0x80047AB8
    // 0x80525800: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x80525800: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x80525804: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80525808: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8052580C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80525810: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80525814: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80525818: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(324, 0X8AC) << 16);
    // 0x8052581C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80525820: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80525824: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80525828: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x8052582C: lwc1        $f8, 0x5DBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(324, 0X8AC));
    // 0x80525830: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(324, 0X8BC) << 16);
    // 0x80525834: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80525838: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8052583C: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80525840: bc1f        L_80525904
    if (!c1cs) {
        // 0x80525844: nop
    
            goto L_80525904;
    }
    // 0x80525844: nop

    // 0x80525848: lwc1        $f10, 0x5DCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(324, 0X8BC));
    // 0x8052584C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80525850: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80525854: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80525858: nop

    // 0x8052585C: bc1f        L_80525884
    if (!c1cs) {
        // 0x80525860: nop
    
            goto L_80525884;
    }
    // 0x80525860: nop

    // 0x80525864: jal         0x80525698
    // 0x80525868: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_80525698(rdram, ctx);
        goto after_3;
    // 0x80525868: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_3:
    // 0x8052586C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80525870: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80525874: jal         0x805256DC
    // 0x80525878: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_805256DC(rdram, ctx);
        goto after_4;
    // 0x80525878: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x8052587C: b           L_80525980
    // 0x80525880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80525980;
    // 0x80525880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80525884:
    // 0x80525884: bne         $t8, $zero, L_805258BC
    if (ctx->r24 != 0) {
        // 0x80525888: lui         $t9, 0x8052
        ctx->r25 = S32(RELOC_HI16(324, 0X8DC) << 16);
            goto L_805258BC;
    }
    // 0x80525888: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(324, 0X8DC) << 16);
    // 0x8052588C: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(324, 0X8CC) << 16);
    // 0x80525890: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80525894: lwc1        $f16, 0x5DDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(324, 0X8CC));
    // 0x80525898: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8052589C: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x805258A0: nop

    // 0x805258A4: bc1fl       L_80525980
    if (!c1cs) {
        // 0x805258A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80525980;
    }
    goto skip_0;
    // 0x805258A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805258AC: jal         0x80525784
    // 0x805258B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80525784(rdram, ctx);
        goto after_5;
    // 0x805258B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_5:
    // 0x805258B4: b           L_80525980
    // 0x805258B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80525980;
    // 0x805258B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805258BC:
    // 0x805258BC: addiu       $t9, $t9, 0x5DEC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(324, 0X8DC));
    // 0x805258C0: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x805258C4: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805258C8: lui         $t0, 0x8052
    ctx->r8 = S32(RELOC_HI16(324, 0X8E4) << 16);
    // 0x805258CC: addiu       $t0, $t0, 0x5DF4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(324, 0X8E4));
    // 0x805258D0: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x805258D4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x805258D8: sltu        $at, $v0, $t0
    ctx->r1 = ctx->r2 < ctx->r8 ? 1 : 0;
    // 0x805258DC: bc1f        L_805258F4
    if (!c1cs) {
        // 0x805258E0: nop
    
            goto L_805258F4;
    }
    // 0x805258E0: nop

    // 0x805258E4: jal         0x80525630
    // 0x805258E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80525630(rdram, ctx);
        goto after_6;
    // 0x805258E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_6:
    // 0x805258EC: b           L_80525980
    // 0x805258F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80525980;
    // 0x805258F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805258F4:
    // 0x805258F4: bne         $at, $zero, L_8052597C
    if (ctx->r1 != 0) {
        // 0x805258F8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8052597C;
    }
    // 0x805258F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805258FC: b           L_8052597C
    // 0x80525900: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
        goto L_8052597C;
    // 0x80525900: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
L_80525904:
    // 0x80525904: bne         $t2, $zero, L_80525958
    if (ctx->r10 != 0) {
        // 0x80525908: lui         $at, 0x8052
        ctx->r1 = S32(RELOC_HI16(324, 0X8CC) << 16);
            goto L_80525958;
    }
    // 0x80525908: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(324, 0X8CC) << 16);
    // 0x8052590C: lui         $t3, 0x8052
    ctx->r11 = S32(RELOC_HI16(324, 0X8DC) << 16);
    // 0x80525910: addiu       $t3, $t3, 0x5DEC
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(324, 0X8DC));
    // 0x80525914: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x80525918: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8052591C: lui         $t4, 0x8052
    ctx->r12 = S32(RELOC_HI16(324, 0X8E4) << 16);
    // 0x80525920: addiu       $t4, $t4, 0x5DF4
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(324, 0X8E4));
    // 0x80525924: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80525928: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8052592C: sltu        $at, $v0, $t4
    ctx->r1 = ctx->r2 < ctx->r12 ? 1 : 0;
    // 0x80525930: bc1f        L_80525948
    if (!c1cs) {
        // 0x80525934: nop
    
            goto L_80525948;
    }
    // 0x80525934: nop

    // 0x80525938: jal         0x80525630
    // 0x8052593C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80525630(rdram, ctx);
        goto after_7;
    // 0x8052593C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_7:
    // 0x80525940: b           L_80525980
    // 0x80525944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80525980;
    // 0x80525944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80525948:
    // 0x80525948: bne         $at, $zero, L_8052597C
    if (ctx->r1 != 0) {
        // 0x8052594C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8052597C;
    }
    // 0x8052594C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80525950: b           L_8052597C
    // 0x80525954: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
        goto L_8052597C;
    // 0x80525954: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
L_80525958:
    // 0x80525958: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8052595C: lwc1        $f6, 0x5DDC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(324, 0X8CC));
    // 0x80525960: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80525964: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80525968: nop

    // 0x8052596C: bc1fl       L_80525980
    if (!c1cs) {
        // 0x80525970: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80525980;
    }
    goto skip_1;
    // 0x80525970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80525974: jal         0x80525784
    // 0x80525978: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80525784(rdram, ctx);
        goto after_8;
    // 0x80525978: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
L_8052597C:
    // 0x8052597C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80525980:
    // 0x80525980: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80525984: jr          $ra
    // 0x80525988: nop

    return;
    // 0x80525988: nop

;}
RECOMP_FUNC void func_8001AE64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE64: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8001AE68: beq         $a0, $zero, L_8001AE74
    if (ctx->r4 == 0) {
        // 0x8001AE6C: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_8001AE74;
    }
    // 0x8001AE6C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8001AE70: sh          $a1, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r5;
L_8001AE74:
    // 0x8001AE74: jr          $ra
    // 0x8001AE78: nop

    return;
    // 0x8001AE78: nop

;}
RECOMP_FUNC void func_805A01A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A01A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A01AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A01B0: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x805A01B4: beql        $a1, $zero, L_805A01C8
    if (ctx->r5 == 0) {
        // 0x805A01B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A01C8;
    }
    goto skip_0;
    // 0x805A01B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A01BC: jal         0x800545F4
    // 0x805A01C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800545F4(rdram, ctx);
        goto after_0;
    // 0x805A01C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x805A01C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A01C8:
    // 0x805A01C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A01CC: jr          $ra
    // 0x805A01D0: nop

    return;
    // 0x805A01D0: nop

;}
RECOMP_FUNC void func_8040B168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040B16C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B170: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040B174: lui         $t1, 0x8041
    ctx->r9 = S32(RELOC_HI16(14, 0XFA8) << 16);
    // 0x8040B178: addiu       $t1, $t1, -0x44F8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(14, 0XFA8));
    // 0x8040B17C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8040B180: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8040B184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040B188: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8040B18C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8040B190: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8040B194: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8040B198: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8040B19C: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x8040B1A0: jal         0x8040B0CC
    // 0x8040B1A4: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    func_8040B0CC(rdram, ctx);
        goto after_0;
    // 0x8040B1A4: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_0:
    // 0x8040B1A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040B1AC: lw          $t2, 0x180($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X180);
    // 0x8040B1B0: lbu         $t3, 0x30($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X30);
    // 0x8040B1B4: lbu         $a1, 0x30($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X30);
    // 0x8040B1B8: beql        $t3, $a1, L_8040B1CC
    if (ctx->r11 == ctx->r5) {
        // 0x8040B1BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040B1CC;
    }
    goto skip_0;
    // 0x8040B1BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040B1C0: jal         0x8040B2F0
    // 0x8040B1C4: nop

    func_8040B2F0(rdram, ctx);
        goto after_1;
    // 0x8040B1C4: nop

    after_1:
    // 0x8040B1C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040B1CC:
    // 0x8040B1CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040B1D0: jr          $ra
    // 0x8040B1D4: nop

    return;
    // 0x8040B1D4: nop

;}
RECOMP_FUNC void func_8069E410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069E410: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069E414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069E418: lh          $a3, 0x1F0($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X1F0);
    // 0x8069E41C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8069E420: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8069E424: bne         $a3, $at, L_8069E490
    if (ctx->r7 != ctx->r1) {
        // 0x8069E428: sll         $a1, $a3, 16
        ctx->r5 = S32(ctx->r7 << 16);
            goto L_8069E490;
    }
    // 0x8069E428: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8069E42C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8069E430: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8069E434: jal         0x80067BBC
    // 0x8069E438: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8069E438: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8069E43C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x8069E440: jal         0x80067F78
    // 0x8069E444: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8069E444: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8069E448: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8069E44C: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8069E450: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8069E454: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8069E458: beq         $v0, $at, L_8069E4D8
    if (ctx->r2 == ctx->r1) {
        // 0x8069E45C: sh          $v0, 0x1F0($a2)
        MEM_H(0X1F0, ctx->r6) = ctx->r2;
            goto L_8069E4D8;
    }
    // 0x8069E45C: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
    // 0x8069E460: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8069E464: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8069E468: jal         0x80067BBC
    // 0x8069E46C: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8069E46C: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_2:
    // 0x8069E470: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8069E474: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x8069E478: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8069E47C: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8069E480: jal         0x80067838
    // 0x8069E484: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x8069E484: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x8069E488: b           L_8069E4DC
    // 0x8069E48C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8069E4DC;
    // 0x8069E48C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8069E490:
    // 0x8069E490: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x8069E494: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8069E498: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8069E49C: jal         0x80067930
    // 0x8069E4A0: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_4;
    // 0x8069E4A0: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_4:
    // 0x8069E4A4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8069E4A8: beq         $v0, $zero, L_8069E4D8
    if (ctx->r2 == 0) {
        // 0x8069E4AC: lh          $a3, 0x1E($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X1E);
            goto L_8069E4D8;
    }
    // 0x8069E4AC: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8069E4B0: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8069E4B4: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8069E4B8: jal         0x80067BBC
    // 0x8069E4BC: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8069E4BC: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_5:
    // 0x8069E4C0: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x8069E4C4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x8069E4C8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8069E4CC: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x8069E4D0: jal         0x800678F0
    // 0x8069E4D4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x8069E4D4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_6:
L_8069E4D8:
    // 0x8069E4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8069E4DC:
    // 0x8069E4DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069E4E0: jr          $ra
    // 0x8069E4E4: nop

    return;
    // 0x8069E4E4: nop

;}
RECOMP_FUNC void func_8064EF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EF88: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064EF8C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064EF90: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064EF94: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064EF98: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064EF9C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064EFA0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064EFA4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064EFA8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064EFAC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064EFB0: jr          $ra
    // 0x8064EFB4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064EFB4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void __osGetActiveQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C130: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8008C134: jr          $ra
    // 0x8008C138: lw          $v0, -0x53F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X53F4);
    return;
    // 0x8008C138: lw          $v0, -0x53F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X53F4);
;}
RECOMP_FUNC void func_806D069C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D069C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D06A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D06A4: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x806D06A8: lui         $t8, 0x806D
    ctx->r24 = S32(RELOC_HI16(607, 0X19BC) << 16);
    // 0x806D06AC: addiu       $t8, $t8, 0x115C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(607, 0X19BC));
    // 0x806D06B0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D06B4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806D06B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806D06BC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x806D06C0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806D06C4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806D06C8: beql        $v1, $zero, L_806D0700
    if (ctx->r3 == 0) {
        // 0x806D06CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D0700;
    }
    goto skip_0;
    // 0x806D06CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806D06D0: jalr        $v1
    // 0x806D06D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806D06D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D06D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D06DC: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x806D06E0: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x806D06E4: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x806D06E8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x806D06EC: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x806D06F0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x806D06F4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x806D06F8: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x806D06FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D0700:
    // 0x806D0700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D0704: jr          $ra
    // 0x806D0708: nop

    return;
    // 0x806D0708: nop

;}
RECOMP_FUNC void func_80474EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474EB0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474EB4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474EB8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474EBC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474EC0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474EC4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474EC8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474ECC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474ED0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474ED4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474ED8: jr          $ra
    // 0x80474EDC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474EDC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80455B58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455B58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80455B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80455B60: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455B64: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455B68: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80455B6C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455B70: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x80455B74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80455B78: jal         0x8044EFA0
    // 0x80455B7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80455B7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80455B80: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80455B84: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455B88: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80455B8C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455B90: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x80455B94: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D6C) << 16);
    // 0x80455B98: lw          $t9, -0x7EB4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D6C));
    // 0x80455B9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80455BA0: jalr        $t9
    // 0x80455BA4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80455BA4: nop

    after_1:
    // 0x80455BA8: jal         0x804559B4
    // 0x80455BAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804559B4(rdram, ctx);
        goto after_2;
    // 0x80455BAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80455BB0: jal         0x80445CBC
    // 0x80455BB4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80445CBC(rdram, ctx);
        goto after_3;
    // 0x80455BB4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x80455BB8: jal         0x80445CC4
    // 0x80455BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_4;
    // 0x80455BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80455BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455BC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80455BC8: jr          $ra
    // 0x80455BCC: nop

    return;
    // 0x80455BCC: nop

;}
RECOMP_FUNC void func_804293FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804293FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80429400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429404: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80429408: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8042940C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80429410: jal         0x80047090
    // 0x80429414: addiu       $a0, $zero, 0x41C5
    ctx->r4 = ADD32(0, 0X41C5);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80429414: addiu       $a0, $zero, 0x41C5
    ctx->r4 = ADD32(0, 0X41C5);
    after_0:
    // 0x80429418: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8042941C: beq         $v0, $at, L_80429458
    if (ctx->r2 == ctx->r1) {
        // 0x80429420: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80429458;
    }
    // 0x80429420: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80429424: lui         $at, 0x41C5
    ctx->r1 = S32(0X41C5 << 16);
    // 0x80429428: ori         $at, $at, 0x400
    ctx->r1 = ctx->r1 | 0X400;
    // 0x8042942C: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80429430: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80429434: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80429438: jal         0x8004613C
    // 0x8042943C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8042943C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x80429440: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80429444: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80429448: jal         0x80047F9C
    // 0x8042944C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8042944C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80429450: jal         0x8005FDC4
    // 0x80429454: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x80429454: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_80429458:
    // 0x80429458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042945C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80429460: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80429464: jr          $ra
    // 0x80429468: nop

    return;
    // 0x80429468: nop

;}
RECOMP_FUNC void func_8067E690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E690: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8067E694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067E698: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067E69C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067E6A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067E6A4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8067E6A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8067E6AC: jal         0x8067DF94
    // 0x8067E6B0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8067DF94(rdram, ctx);
        goto after_0;
    // 0x8067E6B0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8067E6B4: jal         0x8067E420
    // 0x8067E6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E420(rdram, ctx);
        goto after_1;
    // 0x8067E6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8067E6BC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8067E6C0: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8067E6C4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8067E6C8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8067E6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067E6D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067E6D4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8067E6D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8067E6DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8067E6E0: bc1f        L_8067E6FC
    if (!c1cs) {
        // 0x8067E6E4: nop
    
            goto L_8067E6FC;
    }
    // 0x8067E6E4: nop

    // 0x8067E6E8: jal         0x8067EAE0
    // 0x8067E6EC: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    func_8067EAE0(rdram, ctx);
        goto after_2;
    // 0x8067E6EC: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    after_2:
    // 0x8067E6F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067E6F4: jal         0x8067E3E8
    // 0x8067E6F8: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    func_8067E3E8(rdram, ctx);
        goto after_3;
    // 0x8067E6F8: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_3:
L_8067E6FC:
    // 0x8067E6FC: jal         0x8067E480
    // 0x8067E700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E480(rdram, ctx);
        goto after_4;
    // 0x8067E700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8067E704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067E708: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067E70C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8067E710: jr          $ra
    // 0x8067E714: nop

    return;
    // 0x8067E714: nop

;}
