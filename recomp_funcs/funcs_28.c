#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800811D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800811D0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800811D4: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800811D8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800811DC: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800811E0: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800811E4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800811E8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800811EC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800811F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800811F4: bc1tl       L_80081230
    if (c1cs) {
        // 0x800811F8: lwc1        $f0, 0x1C($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
            goto L_80081230;
    }
    goto skip_0;
    // 0x800811F8: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    skip_0:
    // 0x800811FC: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80081200: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80081204: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80081208: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8008120C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80081210: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80081214: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80081218: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8008121C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80081220: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80081224: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80081228: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8008122C: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
L_80081230:
    // 0x80081230: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80081234: nop

    // 0x80081238: bc1tl       L_80081274
    if (c1cs) {
        // 0x8008123C: lwc1        $f0, 0x2C($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
            goto L_80081274;
    }
    goto skip_1;
    // 0x8008123C: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    skip_1:
    // 0x80081240: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80081244: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80081248: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8008124C: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80081250: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80081254: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80081258: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8008125C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80081260: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x80081264: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80081268: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8008126C: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x80081270: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
L_80081274:
    // 0x80081274: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80081278: nop

    // 0x8008127C: bc1tl       L_800812B8
    if (c1cs) {
        // 0x80081280: lwc1        $f0, 0x3C($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_800812B8;
    }
    goto skip_2;
    // 0x80081280: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    skip_2:
    // 0x80081284: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80081288: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8008128C: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80081290: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80081294: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80081298: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8008129C: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800812A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800812A4: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x800812A8: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x800812AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800812B0: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x800812B4: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
L_800812B8:
    // 0x800812B8: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800812BC: nop

    // 0x800812C0: bc1tl       L_8008133C
    if (c1cs) {
        // 0x800812C4: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8008133C;
    }
    goto skip_3;
    // 0x800812C4: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_3:
    // 0x800812C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800812CC: nop

    // 0x800812D0: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x800812D4: nop

    // 0x800812D8: bc1tl       L_80081318
    if (c1cs) {
        // 0x800812DC: lwc1        $f6, 0x30($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
            goto L_80081318;
    }
    goto skip_4;
    // 0x800812DC: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    skip_4:
    // 0x800812E0: mul.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800812E4: lwc1        $f16, 0x30($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800812E8: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800812EC: mul.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800812F0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800812F4: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800812F8: lwc1        $f16, 0x38($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800812FC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80081300: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x80081304: swc1        $f10, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f10.u32l;
    // 0x80081308: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8008130C: b           L_80081338
    // 0x80081310: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
        goto L_80081338;
    // 0x80081310: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80081314: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
L_80081318:
    // 0x80081318: lwc1        $f10, 0x34($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8008131C: lwc1        $f18, 0x38($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80081320: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80081324: add.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80081328: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x8008132C: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x80081330: swc1        $f16, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f16.u32l;
    // 0x80081334: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
L_80081338:
    // 0x80081338: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_8008133C:
    // 0x8008133C: jr          $ra
    // 0x80081340: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80081340: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80449F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449F94: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80449F98: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80449F9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80449FA0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80449FA4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80449FA8: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80449FAC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449FB0: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80449FB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80449FB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80449FBC: lwc1        $f4, 0x6CE0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6CE0);
    // 0x80449FC0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80449FC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80449FC8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80449FCC: swc1        $f8, 0x6CE0($v1)
    MEM_W(0X6CE0, ctx->r3) = ctx->f8.u32l;
    // 0x80449FD0: lwc1        $f16, 0x6CE0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X6CE0);
    // 0x80449FD4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80449FD8: nop

    // 0x80449FDC: bc1f        L_80449FF4
    if (!c1cs) {
        // 0x80449FE0: nop
    
            goto L_80449FF4;
    }
    // 0x80449FE0: nop

    // 0x80449FE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80449FE8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449FEC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449FF0: swc1        $f18, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f18.u32l;
L_80449FF4:
    // 0x80449FF4: jr          $ra
    // 0x80449FF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80449FF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_804C18D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C18D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C18D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C18D8: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804C18DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804C18E0: beq         $t6, $zero, L_804C191C
    if (ctx->r14 == 0) {
        // 0x804C18E4: nop
    
            goto L_804C191C;
    }
    // 0x804C18E4: nop

    // 0x804C18E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C18EC: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804C18F0: jalr        $t9
    // 0x804C18F4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804C18F4: nop

    after_0:
    // 0x804C18F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C18FC: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804C1900: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804C1904: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804C1908: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804C190C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804C1910: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804C1914: b           L_804C191C
    // 0x804C1918: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804C191C;
    // 0x804C1918: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804C191C:
    // 0x804C191C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C1920: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C1924: jr          $ra
    // 0x804C1928: nop

    return;
    // 0x804C1928: nop

;}
RECOMP_FUNC void func_80564C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80564C38: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80564C3C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80564C40: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80564C44: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80564C48: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80564C4C: nop

    // 0x80564C50: bc1fl       L_80564C60
    if (!c1cs) {
        // 0x80564C54: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80564C60;
    }
    goto skip_0;
    // 0x80564C54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80564C58: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80564C5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80564C60:
    // 0x80564C60: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80564C64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80564C68: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80564C6C: nop

    // 0x80564C70: bc1f        L_80564C7C
    if (!c1cs) {
        // 0x80564C74: nop
    
            goto L_80564C7C;
    }
    // 0x80564C74: nop

    // 0x80564C78: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80564C7C:
    // 0x80564C7C: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80564C80: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80564C84: lwc1        $f8, 0x10C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x80564C88: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80564C8C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80564C90: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x80564C94: jr          $ra
    // 0x80564C98: swc1        $f18, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80564C98: swc1        $f18, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_8001D274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D274: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D27C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D280: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001D284: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001D288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D28C: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x8001D290: bnel        $v0, $zero, L_8001D2B0
    if (ctx->r2 != 0) {
        // 0x8001D294: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001D2B0;
    }
    goto skip_0;
    // 0x8001D294: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_0:
    // 0x8001D298: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8001D29C: jal         0x8001D698
    // 0x8001D2A0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8001D698(rdram, ctx);
        goto after_0;
    // 0x8001D2A0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001D2A4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8001D2A8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8001D2AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8001D2B0:
    // 0x8001D2B0: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x8001D2B4: jal         0x8001D0FC
    // 0x8001D2B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001D0FC(rdram, ctx);
        goto after_1;
    // 0x8001D2B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001D2BC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8001D2C0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8001D2C4: lw          $t6, 0xF10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF10);
    // 0x8001D2C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D2CC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8001D2D0: lw          $t9, 0xF14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XF14);
    // 0x8001D2D4: beq         $t9, $zero, L_8001D2E4
    if (ctx->r25 == 0) {
        // 0x8001D2D8: nop
    
            goto L_8001D2E4;
    }
    // 0x8001D2D8: nop

    // 0x8001D2DC: jal         0x8001D1DC
    // 0x8001D2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001D1DC(rdram, ctx);
        goto after_2;
    // 0x8001D2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8001D2E4:
    // 0x8001D2E4: jal         0x8001D148
    // 0x8001D2E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001D148(rdram, ctx);
        goto after_3;
    // 0x8001D2E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8001D2EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D2F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001D2F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D2F8: jr          $ra
    // 0x8001D2FC: nop

    return;
    // 0x8001D2FC: nop

;}
RECOMP_FUNC void func_8002F3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F3B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F3B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F3B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002F3BC: lbu         $t7, 0x111($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X111);
    // 0x8002F3C0: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x8002F3C4: beq         $t7, $zero, L_8002F3DC
    if (ctx->r15 == 0) {
        // 0x8002F3C8: nop
    
            goto L_8002F3DC;
    }
    // 0x8002F3C8: nop

    // 0x8002F3CC: jal         0x8002F15C
    // 0x8002F3D0: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_8002F15C(rdram, ctx);
        goto after_0;
    // 0x8002F3D0: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_0:
    // 0x8002F3D4: b           L_8002F3E8
    // 0x8002F3D8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
        goto L_8002F3E8;
    // 0x8002F3D8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_8002F3DC:
    // 0x8002F3DC: jal         0x8002DBE4
    // 0x8002F3E0: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_1;
    // 0x8002F3E0: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8002F3E4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_8002F3E8:
    // 0x8002F3E8: sw          $zero, 0x1400($t8)
    MEM_W(0X1400, ctx->r24) = 0;
    // 0x8002F3EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F3F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F3F4: jr          $ra
    // 0x8002F3F8: nop

    return;
    // 0x8002F3F8: nop

;}
RECOMP_FUNC void func_8046338C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046338C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80463390: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80463394: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80463398: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8046339C: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x804633A0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x804633A4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804633A8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x804633AC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x804633B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x804633B4: jal         0x80062AEC
    // 0x804633B8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x804633B8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    after_0:
    // 0x804633BC: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x804633C0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804633C4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x804633C8: bne         $t7, $at, L_80463498
    if (ctx->r15 != ctx->r1) {
        // 0x804633CC: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_80463498;
    }
    // 0x804633CC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x804633D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804633D4: beq         $v0, $at, L_804633EC
    if (ctx->r2 == ctx->r1) {
        // 0x804633D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804633EC;
    }
    // 0x804633D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804633DC: beq         $v0, $at, L_80463444
    if (ctx->r2 == ctx->r1) {
        // 0x804633E0: nop
    
            goto L_80463444;
    }
    // 0x804633E0: nop

    // 0x804633E4: b           L_8046349C
    // 0x804633E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8046349C;
    // 0x804633E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804633EC:
    // 0x804633EC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A8C) << 16);
    // 0x804633F0: lwc1        $f4, 0x401C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A8C));
    // 0x804633F4: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x804633F8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804633FC: nop

    // 0x80463400: bc1fl       L_80463430
    if (!c1cs) {
        // 0x80463404: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80463430;
    }
    goto skip_0;
    // 0x80463404: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x80463408: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8046340C: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80463410: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80463414: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80463418: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8046341C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80463420: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80463424: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80463428: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x8046342C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80463430:
    // 0x80463430: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80463434: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x80463438: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8046343C: b           L_80463498
    // 0x80463440: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
        goto L_80463498;
    // 0x80463440: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_80463444:
    // 0x80463444: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A90) << 16);
    // 0x80463448: lwc1        $f16, 0x4020($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A90));
    // 0x8046344C: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80463450: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80463454: nop

    // 0x80463458: bc1fl       L_80463488
    if (!c1cs) {
        // 0x8046345C: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_80463488;
    }
    goto skip_1;
    // 0x8046345C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x80463460: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80463464: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80463468: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8046346C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80463470: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80463474: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80463478: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8046347C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80463480: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x80463484: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_80463488:
    // 0x80463488: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8046348C: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x80463490: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80463494: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
L_80463498:
    // 0x80463498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046349C:
    // 0x8046349C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804634A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804634A4: jr          $ra
    // 0x804634A8: nop

    return;
    // 0x804634A8: nop

;}
RECOMP_FUNC void func_806EF3F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF3F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EF3FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EF400: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EF404: jal         0x806EF314
    // 0x806EF408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EF314(rdram, ctx);
        goto after_0;
    // 0x806EF408: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EF40C: bne         $v0, $zero, L_806EF424
    if (ctx->r2 != 0) {
        // 0x806EF410: lui         $at, 0x41A8
        ctx->r1 = S32(0X41A8 << 16);
            goto L_806EF424;
    }
    // 0x806EF410: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x806EF414: jal         0x800447C8
    // 0x806EF418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806EF418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EF41C: b           L_806EF490
    // 0x806EF420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EF490;
    // 0x806EF420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EF424:
    // 0x806EF424: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EF428: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806EF42C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806EF430: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x806EF434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EF438: jal         0x806EC234
    // 0x806EF43C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_806EC234(rdram, ctx);
        goto after_2;
    // 0x806EF43C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x806EF440: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x806EF444: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(676, 0X4A04) << 16);
    // 0x806EF448: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806EF44C: addiu       $t7, $t7, 0x954
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(676, 0X4A04));
    // 0x806EF450: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806EF454: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806EF458: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806EF45C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EF460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EF464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806EF468: jal         0x806EF4A0
    // 0x806EF46C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806EF4A0(rdram, ctx);
        goto after_3;
    // 0x806EF46C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x806EF470: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x806EF474: sh          $t9, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r25;
    // 0x806EF478: jal         0x806EC0CC
    // 0x806EF47C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC0CC(rdram, ctx);
        goto after_4;
    // 0x806EF47C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EF480: lui         $t0, 0x806F
    ctx->r8 = S32(RELOC_HI16(676, 0X2BC) << 16);
    // 0x806EF484: addiu       $t0, $t0, -0x3DF4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(676, 0X2BC));
    // 0x806EF488: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x806EF48C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EF490:
    // 0x806EF490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EF494: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EF498: jr          $ra
    // 0x806EF49C: nop

    return;
    // 0x806EF49C: nop

;}
RECOMP_FUNC void func_8002EFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EFD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002EFD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002EFD8: jal         0x8003BF08
    // 0x8002EFDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003BF08(rdram, ctx);
        goto after_0;
    // 0x8002EFDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002EFE0: jal         0x80027FBC
    // 0x8002EFE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80027FBC(rdram, ctx);
        goto after_1;
    // 0x8002EFE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002EFE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002EFEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002EFF0: jr          $ra
    // 0x8002EFF4: nop

    return;
    // 0x8002EFF4: nop

;}
RECOMP_FUNC void func_8077059C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077059C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807705A0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x807705A4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x807705A8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x807705AC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x807705B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x807705B4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x807705B8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x807705BC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807705C0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x807705C4: jr          $ra
    // 0x807705C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x807705C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80067F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067F5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067F60: jal         0x80067E24
    // 0x80067F64: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    func_80067E24(rdram, ctx);
        goto after_0;
    // 0x80067F64: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    after_0:
    // 0x80067F68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067F70: jr          $ra
    // 0x80067F74: nop

    return;
    // 0x80067F74: nop

;}
RECOMP_FUNC void func_800433A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800433A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800433A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800433AC: lw          $t6, 0x12EC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X12EC);
    // 0x800433B0: beql        $t6, $zero, L_800433C4
    if (ctx->r14 == 0) {
        // 0x800433B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800433C4;
    }
    goto skip_0;
    // 0x800433B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800433B8: jal         0x800411AC
    // 0x800433BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800411AC(rdram, ctx);
        goto after_0;
    // 0x800433BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800433C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800433C4:
    // 0x800433C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800433C8: jr          $ra
    // 0x800433CC: nop

    return;
    // 0x800433CC: nop

;}
RECOMP_FUNC void func_807AF8A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF8A4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807AF8A8: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(868, 0X6C) << 16);
    // 0x807AF8AC: addiu       $t6, $t6, -0x9A4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(868, 0X6C));
    // 0x807AF8B0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807AF8B4: jr          $ra
    // 0x807AF8B8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x807AF8B8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806EE054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE054: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EE058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EE05C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EE060: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EE064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EE068: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806EE06C: jal         0x800577D8
    // 0x806EE070: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EE070: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x806EE074: jal         0x806ED57C
    // 0x806EE078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED57C(rdram, ctx);
        goto after_1;
    // 0x806EE078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EE07C: jal         0x806ED5F0
    // 0x806EE080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED5F0(rdram, ctx);
        goto after_2;
    // 0x806EE080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EE084: jal         0x806ED6C4
    // 0x806EE088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED6C4(rdram, ctx);
        goto after_3;
    // 0x806EE088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EE08C: bne         $v0, $zero, L_806EE0B0
    if (ctx->r2 != 0) {
        // 0x806EE090: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_806EE0B0;
    }
    // 0x806EE090: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806EE094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EE098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EE09C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EE0A0: jal         0x806EE584
    // 0x806EE0A4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_4;
    // 0x806EE0A4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806EE0A8: b           L_806EE114
    // 0x806EE0AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EE114;
    // 0x806EE0AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EE0B0:
    // 0x806EE0B0: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EE0B4: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x806EE0B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EE0BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EE0C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806EE0C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806EE0C8: bc1f        L_806EE108
    if (!c1cs) {
        // 0x806EE0CC: nop
    
            goto L_806EE108;
    }
    // 0x806EE0CC: nop

    // 0x806EE0D0: jal         0x806EE584
    // 0x806EE0D4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_5;
    // 0x806EE0D4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x806EE0D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806EE0DC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806EE0E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806EE0E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EE0E8: jal         0x806EC03C
    // 0x806EE0EC: nop

    func_806EC03C(rdram, ctx);
        goto after_6;
    // 0x806EE0EC: nop

    after_6:
    // 0x806EE0F0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806EE0F4: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
    // 0x806EE0F8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806EE0FC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EE100: b           L_806EE110
    // 0x806EE104: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
        goto L_806EE110;
    // 0x806EE104: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
L_806EE108:
    // 0x806EE108: jal         0x806ED844
    // 0x806EE10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED844(rdram, ctx);
        goto after_7;
    // 0x806EE10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_806EE110:
    // 0x806EE110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EE114:
    // 0x806EE114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EE118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806EE11C: jr          $ra
    // 0x806EE120: nop

    return;
    // 0x806EE120: nop

;}
RECOMP_FUNC void func_800734F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800734F0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800734F4: bgezl       $v0, L_80073524
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800734F8: lhu         $v1, 0xA($a0)
        ctx->r3 = MEM_HU(ctx->r4, 0XA);
            goto L_80073524;
    }
    goto skip_0;
    // 0x800734F8: lhu         $v1, 0xA($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XA);
    skip_0:
    // 0x800734FC: lhu         $t6, 0xA($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA);
L_80073500:
    // 0x80073500: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80073504: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80073508: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8007350C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80073510: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80073514: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80073518: bltzl       $v0, L_80073500
    if (SIGNED(ctx->r2) < 0) {
        // 0x8007351C: lhu         $t6, 0xA($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0XA);
            goto L_80073500;
    }
    goto skip_1;
    // 0x8007351C: lhu         $t6, 0xA($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA);
    skip_1:
    // 0x80073520: lhu         $v1, 0xA($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XA);
L_80073524:
    // 0x80073524: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80073528: bne         $at, $zero, L_80073554
    if (ctx->r1 != 0) {
        // 0x8007352C: subu        $t0, $v0, $v1
        ctx->r8 = SUB32(ctx->r2, ctx->r3);
            goto L_80073554;
    }
    // 0x8007352C: subu        $t0, $v0, $v1
    ctx->r8 = SUB32(ctx->r2, ctx->r3);
L_80073530:
    // 0x80073530: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80073534: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80073538: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8007353C: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80073540: lhu         $v1, 0xA($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XA);
    // 0x80073544: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80073548: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007354C: beql        $at, $zero, L_80073530
    if (ctx->r1 == 0) {
        // 0x80073550: subu        $t0, $v0, $v1
        ctx->r8 = SUB32(ctx->r2, ctx->r3);
            goto L_80073530;
    }
    goto skip_2;
    // 0x80073550: subu        $t0, $v0, $v1
    ctx->r8 = SUB32(ctx->r2, ctx->r3);
    skip_2:
L_80073554:
    // 0x80073554: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80073558: bgezl       $v0, L_80073578
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007355C: lhu         $v1, 0xC($a0)
        ctx->r3 = MEM_HU(ctx->r4, 0XC);
            goto L_80073578;
    }
    goto skip_3;
    // 0x8007355C: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    skip_3:
L_80073560:
    // 0x80073560: lhu         $t3, 0xC($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0XC);
    // 0x80073564: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80073568: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8007356C: bltz        $t4, L_80073560
    if (SIGNED(ctx->r12) < 0) {
        // 0x80073570: sw          $t4, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r12;
            goto L_80073560;
    }
    // 0x80073570: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80073574: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
L_80073578:
    // 0x80073578: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007357C: bne         $at, $zero, L_8007359C
    if (ctx->r1 != 0) {
        // 0x80073580: subu        $t5, $v0, $v1
        ctx->r13 = SUB32(ctx->r2, ctx->r3);
            goto L_8007359C;
    }
    // 0x80073580: subu        $t5, $v0, $v1
    ctx->r13 = SUB32(ctx->r2, ctx->r3);
L_80073584:
    // 0x80073584: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80073588: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x8007358C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x80073590: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80073594: beql        $at, $zero, L_80073584
    if (ctx->r1 == 0) {
        // 0x80073598: subu        $t5, $v0, $v1
        ctx->r13 = SUB32(ctx->r2, ctx->r3);
            goto L_80073584;
    }
    goto skip_4;
    // 0x80073598: subu        $t5, $v0, $v1
    ctx->r13 = SUB32(ctx->r2, ctx->r3);
    skip_4:
L_8007359C:
    // 0x8007359C: jr          $ra
    // 0x800735A0: nop

    return;
    // 0x800735A0: nop

;}
RECOMP_FUNC void func_806F97A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F97A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F97AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F97B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F97B4: jal         0x806F95A0
    // 0x806F97B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806F95A0(rdram, ctx);
        goto after_0;
    // 0x806F97B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806F97BC: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806F97C0: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x806F97C4: jal         0x80065ABC
    // 0x806F97C8: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x806F97C8: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_1:
    // 0x806F97CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F97D0: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806F97D4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806F97D8: nop

    // 0x806F97DC: bc1fl       L_806F97FC
    if (!c1cs) {
        // 0x806F97E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F97FC;
    }
    goto skip_0;
    // 0x806F97E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F97E4: jal         0x8005FCA8
    // 0x806F97E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FCA8(rdram, ctx);
        goto after_2;
    // 0x806F97E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F97EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F97F0: jal         0x806F9A78
    // 0x806F97F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806F9A78(rdram, ctx);
        goto after_3;
    // 0x806F97F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x806F97F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F97FC:
    // 0x806F97FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F9800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F9804: jr          $ra
    // 0x806F9808: nop

    return;
    // 0x806F9808: nop

;}
RECOMP_FUNC void func_804CAB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CAB88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CAB8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CAB90: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804CAB94: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804CAB98: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804CAB9C: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(231, 0X128C) << 16);
    // 0x804CABA0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804CABA4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804CABA8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804CABAC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804CABB0: lw          $t8, -0x4234($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(231, 0X128C));
    // 0x804CABB4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804CABB8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804CABBC: jal         0x80048490
    // 0x804CABC0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804CABC0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804CABC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CABC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CABCC: jr          $ra
    // 0x804CABD0: nop

    return;
    // 0x804CABD0: nop

;}
RECOMP_FUNC void func_805A2058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A2058: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A205C: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x805A2060: lw          $t6, 0x7F78($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7F78);
    // 0x805A2064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A2068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A206C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A2070: jal         0x805A1D44
    // 0x805A2074: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_805A1D44(rdram, ctx);
        goto after_0;
    // 0x805A2074: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x805A2078: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x805A207C: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x805A2080: bnel        $t8, $zero, L_805A2094
    if (ctx->r24 != 0) {
        // 0x805A2084: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805A2094;
    }
    goto skip_0;
    // 0x805A2084: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x805A2088: jal         0x805A1BFC
    // 0x805A208C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1BFC(rdram, ctx);
        goto after_1;
    // 0x805A208C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A2090: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_805A2094:
    // 0x805A2094: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805A2098: jal         0x80048F84
    // 0x805A209C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805A209C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x805A20A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805A20A4: jal         0x80048F84
    // 0x805A20A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805A20A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x805A20AC: jal         0x805A1848
    // 0x805A20B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1848(rdram, ctx);
        goto after_4;
    // 0x805A20B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A20B4: jal         0x805A1BA8
    // 0x805A20B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1BA8(rdram, ctx);
        goto after_5;
    // 0x805A20B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805A20BC: jal         0x805A1CA0
    // 0x805A20C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1CA0(rdram, ctx);
        goto after_6;
    // 0x805A20C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805A20C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A20C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A20CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805A20D0: jr          $ra
    // 0x805A20D4: nop

    return;
    // 0x805A20D4: nop

;}
RECOMP_FUNC void func_80007B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007B4C: jal         0x80008378
    // 0x80007B50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80008378(rdram, ctx);
        goto after_0;
    // 0x80007B50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80007B54: jal         0x80008FF8
    // 0x80007B58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80008FF8(rdram, ctx);
        goto after_1;
    // 0x80007B58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80007B5C: jal         0x8000877C
    // 0x80007B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8000877C(rdram, ctx);
        goto after_2;
    // 0x80007B60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80007B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007B68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007B6C: jr          $ra
    // 0x80007B70: nop

    return;
    // 0x80007B70: nop

;}
RECOMP_FUNC void func_8073DC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073DC90: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8073DC94: lui         $t0, 0x8074
    ctx->r8 = S32(RELOC_HI16(745, 0X13E8) << 16);
    // 0x8073DC98: addiu       $t0, $t0, -0x1A48
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(745, 0X13E8));
    // 0x8073DC9C: beq         $v0, $zero, L_8073DCAC
    if (ctx->r2 == 0) {
        // 0x8073DCA0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8073DCAC;
    }
    // 0x8073DCA0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8073DCA4: jr          $ra
    // 0x8073DCA8: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
    return;
    // 0x8073DCA8: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
L_8073DCAC:
    // 0x8073DCAC: lw          $t7, 0x28($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X28);
    // 0x8073DCB0: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8073DCB4: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8073DCB8: bne         $at, $zero, L_8073DCC8
    if (ctx->r1 != 0) {
        // 0x8073DCBC: sw          $v0, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->r2;
            goto L_8073DCC8;
    }
    // 0x8073DCBC: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x8073DCC0: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x8073DCC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073DCC8:
    // 0x8073DCC8: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x8073DCCC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x8073DCD0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8073DCD4: sw          $t1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r9;
    // 0x8073DCD8: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x8073DCDC: sw          $t2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r10;
    // 0x8073DCE0: jr          $ra
    // 0x8073DCE4: nop

    return;
    // 0x8073DCE4: nop

;}
RECOMP_FUNC void func_8043EFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043EFF8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8043EFFC: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4E80) << 16);
    // 0x8043F000: lwc1        $f8, 0x3D80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4E80));
    // 0x8043F004: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8043F008: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x8043F00C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8043F010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043F014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043F018: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8043F01C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8043F020: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8043F024: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8043F028: nop

    // 0x8043F02C: slti        $at, $a2, -0x80
    ctx->r1 = SIGNED(ctx->r6) < -0X80 ? 1 : 0;
    // 0x8043F030: beq         $at, $zero, L_8043F03C
    if (ctx->r1 == 0) {
        // 0x8043F034: nop
    
            goto L_8043F03C;
    }
    // 0x8043F034: nop

    // 0x8043F038: addiu       $a2, $zero, -0x80
    ctx->r6 = ADD32(0, -0X80);
L_8043F03C:
    // 0x8043F03C: jal         0x8043EF80
    // 0x8043F040: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8043EF80(rdram, ctx);
        goto after_0;
    // 0x8043F040: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8043F044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043F048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043F04C: jr          $ra
    // 0x8043F050: nop

    return;
    // 0x8043F050: nop

;}
RECOMP_FUNC void func_806CFDA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFDA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CFDAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CFDB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806CFDB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806CFDB8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x806CFDBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CFDC0: jal         0x806D093C
    // 0x806CFDC4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_806D093C(rdram, ctx);
        goto after_0;
    // 0x806CFDC4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x806CFDC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CFDCC: jal         0x806CFE48
    // 0x806CFDD0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_806CFE48(rdram, ctx);
        goto after_1;
    // 0x806CFDD0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x806CFDD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806CFDD8: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(607, 0X17C) << 16);
    // 0x806CFDDC: addiu       $t6, $t6, -0x6E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(607, 0X17C));
    // 0x806CFDE0: jal         0x806CFD94
    // 0x806CFDE4: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    func_806CFD94(rdram, ctx);
        goto after_2;
    // 0x806CFDE4: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    after_2:
    // 0x806CFDE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CFDEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CFDF0: jr          $ra
    // 0x806CFDF4: nop

    return;
    // 0x806CFDF4: nop

;}
RECOMP_FUNC void func_806D99D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D99D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D99D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D99D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806D99DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806D99E0: jal         0x80047090
    // 0x806D99E4: addiu       $a0, $zero, 0x40B2
    ctx->r4 = ADD32(0, 0X40B2);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806D99E4: addiu       $a0, $zero, 0x40B2
    ctx->r4 = ADD32(0, 0X40B2);
    after_0:
    // 0x806D99E8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806D99EC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x806D99F0: beq         $v0, $at, L_806D9A50
    if (ctx->r2 == ctx->r1) {
        // 0x806D99F4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_806D9A50;
    }
    // 0x806D99F4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x806D99F8: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x806D99FC: lui         $a0, 0x806E
    ctx->r4 = S32(RELOC_HI16(631, 0X4A0) << 16);
    // 0x806D9A00: lui         $at, 0x40B2
    ctx->r1 = S32(0X40B2 << 16);
    // 0x806D9A04: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x806D9A08: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x806D9A0C: or          $a1, $v1, $at
    ctx->r5 = ctx->r3 | ctx->r1;
    // 0x806D9A10: addiu       $a0, $a0, -0x6450
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(631, 0X4A0));
    // 0x806D9A14: jal         0x80046804
    // 0x806D9A18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x806D9A18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x806D9A1C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x806D9A20: beq         $v0, $zero, L_806D9A50
    if (ctx->r2 == 0) {
        // 0x806D9A24: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_806D9A50;
    }
    // 0x806D9A24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806D9A28: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x806D9A2C: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x806D9A30: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x806D9A34: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x806D9A38: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x806D9A3C: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
    // 0x806D9A40: jal         0x80044194
    // 0x806D9A44: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x806D9A44: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x806D9A48: b           L_806D9A54
    // 0x806D9A4C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_806D9A54;
    // 0x806D9A4C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_806D9A50:
    // 0x806D9A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D9A54:
    // 0x806D9A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D9A58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806D9A5C: jr          $ra
    // 0x806D9A60: nop

    return;
    // 0x806D9A60: nop

    // 0x806D9A64: nop

    // 0x806D9A68: nop

    // 0x806D9A6C: nop

;}
RECOMP_FUNC void func_80469028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469028: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046902C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80469030: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80469034: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80469038: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8046903C: jal         0x80066DE4
    // 0x80469040: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80469040: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80469044: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80469048: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8046904C: jal         0x80066E88
    // 0x80469050: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80469050: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    after_1:
    // 0x80469054: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80469058: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8046905C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80469060: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x80469064: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x80469068: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8046906C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80469070: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80469074: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80469078: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8046907C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80469080: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x80469084: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x80469088: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x8046908C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80469090: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80469094: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80469098: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8046909C: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804690A0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804690A4: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x804690A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804690AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804690B0: jr          $ra
    // 0x804690B4: nop

    return;
    // 0x804690B4: nop

;}
RECOMP_FUNC void func_804CC2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC2AC: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x804CC2B0: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x804CC2B4: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x804CC2B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CC2BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CC2C0: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x804CC2C4: andi        $t8, $t7, 0x9000
    ctx->r24 = ctx->r15 & 0X9000;
    // 0x804CC2C8: beql        $t8, $zero, L_804CC334
    if (ctx->r24 == 0) {
        // 0x804CC2CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CC334;
    }
    goto skip_0;
    // 0x804CC2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804CC2D0: lbu         $v0, 0x2($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2);
    // 0x804CC2D4: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CC2D8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x804CC2DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804CC2E0: beq         $v0, $at, L_804CC328
    if (ctx->r2 == ctx->r1) {
        // 0x804CC2E4: lbu         $a2, 0x1($t9)
        ctx->r6 = MEM_BU(ctx->r25, 0X1);
            goto L_804CC328;
    }
    // 0x804CC2E4: lbu         $a2, 0x1($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X1);
    // 0x804CC2E8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x804CC2EC: beq         $v0, $at, L_804CC328
    if (ctx->r2 == ctx->r1) {
        // 0x804CC2F0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_804CC328;
    }
    // 0x804CC2F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x804CC2F4: beq         $v0, $at, L_804CC328
    if (ctx->r2 == ctx->r1) {
        // 0x804CC2F8: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_804CC328;
    }
    // 0x804CC2F8: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x804CC2FC: beq         $a2, $at, L_804CC318
    if (ctx->r6 == ctx->r1) {
        // 0x804CC300: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_804CC318;
    }
    // 0x804CC300: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804CC304: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804CC308: jal         0x8006E0FC
    // 0x804CC30C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x804CC30C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x804CC310: b           L_804CC334
    // 0x804CC314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CC334;
    // 0x804CC314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC318:
    // 0x804CC318: jal         0x8006E0FC
    // 0x804CC31C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8006E0FC(rdram, ctx);
        goto after_1;
    // 0x804CC31C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x804CC320: b           L_804CC334
    // 0x804CC324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804CC334;
    // 0x804CC324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC328:
    // 0x804CC328: jal         0x8006E0FC
    // 0x804CC32C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8006E0FC(rdram, ctx);
        goto after_2;
    // 0x804CC32C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x804CC330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CC334:
    // 0x804CC334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CC338: jr          $ra
    // 0x804CC33C: nop

    return;
    // 0x804CC33C: nop

;}
RECOMP_FUNC void func_806FCFE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FCFE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FCFE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FCFE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806FCFEC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806FCFF0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806FCFF4: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(703, 0XA80) << 16);
    // 0x806FCFF8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806FCFFC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806FD000: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806FD004: lw          $t8, -0x2C70($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(703, 0XA80));
    // 0x806FD008: jal         0x806FCF6C
    // 0x806FD00C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    func_806FCF6C(rdram, ctx);
        goto after_0;
    // 0x806FD00C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    after_0:
    // 0x806FD010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FD014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FD018: jr          $ra
    // 0x806FD01C: nop

    return;
    // 0x806FD01C: nop

;}
RECOMP_FUNC void func_8064F3CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F3CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064F3D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064F3D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064F3D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8064F3DC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8064F3E0: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x8064F3E4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8064F3E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064F3EC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8064F3F0: lwc1        $f2, 0x6AF0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6AF0);
    // 0x8064F3F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064F3F8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8064F3FC: jal         0x8064F2E8
    // 0x8064F400: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    func_8064F2E8(rdram, ctx);
        goto after_0;
    // 0x8064F400: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8064F404: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8064F408: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8064F40C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8064F410: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8064F414: jal         0x8064F354
    // 0x8064F418: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8064F354(rdram, ctx);
        goto after_1;
    // 0x8064F418: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8064F41C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064F420: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064F424: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8064F428: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8064F42C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8064F430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064F434: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064F438: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064F43C: jr          $ra
    // 0x8064F440: nop

    return;
    // 0x8064F440: nop

;}
RECOMP_FUNC void func_804BDF38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BDF38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804BDF3C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41CC) << 16);
    // 0x804BDF40: lwc1        $f4, -0x504($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41CC));
    // 0x804BDF44: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x804BDF48: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41D0) << 16);
    // 0x804BDF4C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804BDF50: nop

    // 0x804BDF54: bc1t        L_804BDF7C
    if (c1cs) {
        // 0x804BDF58: nop
    
            goto L_804BDF7C;
    }
    // 0x804BDF58: nop

    // 0x804BDF5C: lwc1        $f6, -0x500($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41D0));
    // 0x804BDF60: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X2654) << 16);
    // 0x804BDF64: addiu       $t6, $t6, -0x207C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(191, 0X2654));
    // 0x804BDF68: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804BDF6C: nop

    // 0x804BDF70: bc1t        L_804BDF7C
    if (c1cs) {
        // 0x804BDF74: nop
    
            goto L_804BDF7C;
    }
    // 0x804BDF74: nop

    // 0x804BDF78: sw          $t6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r14;
L_804BDF7C:
    // 0x804BDF7C: jr          $ra
    // 0x804BDF80: nop

    return;
    // 0x804BDF80: nop

;}
RECOMP_FUNC void func_806F7048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7048: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806F704C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F7050: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F7054: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F7058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F705C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x806F7060: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x806F7064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806F7068: jal         0x806F6E20
    // 0x806F706C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_806F6E20(rdram, ctx);
        goto after_0;
    // 0x806F706C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x806F7070: jal         0x806F6F64
    // 0x806F7074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F6F64(rdram, ctx);
        goto after_1;
    // 0x806F7074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F7078: jal         0x806F6F08
    // 0x806F707C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F6F08(rdram, ctx);
        goto after_2;
    // 0x806F707C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F7080: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806F7084: bne         $v0, $at, L_806F70A4
    if (ctx->r2 != ctx->r1) {
        // 0x806F7088: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806F70A4;
    }
    // 0x806F7088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F708C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x806F7090: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806F7094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F7098: lbu         $a2, 0x8($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X8);
    // 0x806F709C: jal         0x806F73DC
    // 0x806F70A0: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    func_806F73DC(rdram, ctx);
        goto after_3;
    // 0x806F70A0: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    after_3:
L_806F70A4:
    // 0x806F70A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F70A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F70AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806F70B0: jr          $ra
    // 0x806F70B4: nop

    return;
    // 0x806F70B4: nop

;}
RECOMP_FUNC void func_800393C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800393C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800393CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800393D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800393D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800393D8: jal         0x8004700C
    // 0x800393DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x800393DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800393E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800393E4: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
    // 0x800393E8: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800393EC: beql        $t6, $t7, L_80039430
    if (ctx->r14 == ctx->r15) {
        // 0x800393F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80039430;
    }
    goto skip_0;
    // 0x800393F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800393F4: lw          $t8, 0x138($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X138);
    // 0x800393F8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800393FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039400: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80039404: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80039408: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8003940C: jal         0x800659EC
    // 0x80039410: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x80039410: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x80039414: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80039418: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003941C: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x80039420: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80039424: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80039428: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8003942C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80039430:
    // 0x80039430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039434: jr          $ra
    // 0x80039438: nop

    return;
    // 0x80039438: nop

;}
RECOMP_FUNC void func_806FA608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FA608: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806FA60C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806FA610: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806FA614: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806FA618: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806FA61C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806FA620: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806FA624: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806FA628: lui         $t1, 0x8070
    ctx->r9 = S32(RELOC_HI16(700, 0X2A90) << 16);
    // 0x806FA62C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806FA630: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806FA634: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806FA638: lw          $t1, -0x3940($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(700, 0X2A90));
    // 0x806FA63C: jr          $ra
    // 0x806FA640: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806FA640: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8042923C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042923C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80429240: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80429244: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80429248: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042924C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80429250: jal         0x8004700C
    // 0x80429254: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80429254: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80429258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042925C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80429260: jal         0x80062684
    // 0x80429264: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80062684(rdram, ctx);
        goto after_1;
    // 0x80429264: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80429268: jal         0x804291E0
    // 0x8042926C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804291E0(rdram, ctx);
        goto after_2;
    // 0x8042926C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80429270: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80429274: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80429278: beql        $v1, $zero, L_804292EC
    if (ctx->r3 == 0) {
        // 0x8042927C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804292EC;
    }
    goto skip_0;
    // 0x8042927C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80429280: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80429284: bnel        $t7, $zero, L_804292D4
    if (ctx->r15 != 0) {
        // 0x80429288: lw          $t0, 0x180($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X180);
            goto L_804292D4;
    }
    goto skip_1;
    // 0x80429288: lw          $t0, 0x180($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X180);
    skip_1:
    // 0x8042928C: lw          $t8, 0x180($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X180);
    // 0x80429290: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80429294: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80429298: bnel        $s0, $t8, L_804292EC
    if (ctx->r16 != ctx->r24) {
        // 0x8042929C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804292EC;
    }
    goto skip_2;
    // 0x8042929C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x804292A0: jal         0x8006CAE0
    // 0x804292A4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    func_8006CAE0(rdram, ctx);
        goto after_3;
    // 0x804292A4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_3:
    // 0x804292A8: lui         $at, 0x432B
    ctx->r1 = S32(0X432B << 16);
    // 0x804292AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804292B0: jal         0x8006C9DC
    // 0x804292B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8006C9DC(rdram, ctx);
        goto after_4;
    // 0x804292B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x804292B8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804292BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804292C0: jal         0x8006CA74
    // 0x804292C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8006CA74(rdram, ctx);
        goto after_5;
    // 0x804292C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x804292C8: b           L_804292EC
    // 0x804292CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804292EC;
    // 0x804292CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804292D0: lw          $t0, 0x180($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X180);
L_804292D4:
    // 0x804292D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804292D8: beql        $s0, $t0, L_804292EC
    if (ctx->r16 == ctx->r8) {
        // 0x804292DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804292EC;
    }
    goto skip_3;
    // 0x804292DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x804292E0: jal         0x8006CAE0
    // 0x804292E4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_8006CAE0(rdram, ctx);
        goto after_6;
    // 0x804292E4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_6:
    // 0x804292E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804292EC:
    // 0x804292EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804292F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804292F4: jr          $ra
    // 0x804292F8: nop

    return;
    // 0x804292F8: nop

;}
RECOMP_FUNC void func_80534778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8053477C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80534780: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80534784: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80534788: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(348, 0X101C) << 16);
    // 0x8053478C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80534790: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80534794: lw          $t8, 0x562C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(348, 0X101C));
    // 0x80534798: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8053479C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x805347A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x805347A4: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x805347A8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805347AC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805347B0: beql        $v1, $zero, L_805347E4
    if (ctx->r3 == 0) {
        // 0x805347B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805347E4;
    }
    goto skip_0;
    // 0x805347B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805347B8: jalr        $v1
    // 0x805347BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805347BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805347C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805347C4: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x805347C8: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x805347CC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x805347D0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x805347D4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x805347D8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x805347DC: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x805347E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805347E4:
    // 0x805347E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805347E8: jr          $ra
    // 0x805347EC: nop

    return;
    // 0x805347EC: nop

;}
RECOMP_FUNC void func_8043E490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E490: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043E494: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8043E498: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8043E49C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E4A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8043E4A4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8043E4A8: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(92, 0X1B30) << 16);
    // 0x8043E4AC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8043E4B0: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x8043E4B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8043E4B8: lw          $t8, -0x1490($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(92, 0X1B30));
    // 0x8043E4BC: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8043E4C0: sw          $a2, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r6;
    // 0x8043E4C4: sw          $a2, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r6;
    // 0x8043E4C8: sw          $a2, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r6;
    // 0x8043E4CC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8043E4D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8043E4D4: jal         0x8043DD6C
    // 0x8043E4D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8043DD6C(rdram, ctx);
        goto after_0;
    // 0x8043E4D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8043E4DC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8043E4E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043E4E4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8043E4E8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8043E4EC: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8043E4F0: addiu       $t1, $t1, -0x6030
    ctx->r9 = ADD32(ctx->r9, -0X6030);
    // 0x8043E4F4: sh          $t9, 0x4C($t0)
    MEM_H(0X4C, ctx->r8) = ctx->r25;
    // 0x8043E4F8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8043E4FC: jal         0x8043D154
    // 0x8043E500: sw          $t1, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r9;
    func_8043D154(rdram, ctx);
        goto after_1;
    // 0x8043E500: sw          $t1, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r9;
    after_1:
    // 0x8043E504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043E50C: jr          $ra
    // 0x8043E510: nop

    return;
    // 0x8043E510: nop

;}
RECOMP_FUNC void func_8000DCC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DCC8: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8000DCCC: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8000DCD0: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x8000DCD4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8000DCD8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8000DCDC: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8000DCE0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000DCE4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8000DCE8: or          $v1, $t7, $v1
    ctx->r3 = ctx->r15 | ctx->r3;
    // 0x8000DCEC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8000DCF0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8000DCF4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8000DCF8: jr          $ra
    // 0x8000DCFC: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    return;
    // 0x8000DCFC: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
;}
RECOMP_FUNC void func_8064B7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B7D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B7DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B7E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064B7E4: jal         0x80045A34
    // 0x8064B7E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8064B7E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8064B7EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064B7F0: bne         $v0, $zero, L_8064B800
    if (ctx->r2 != 0) {
        // 0x8064B7F4: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8064B800;
    }
    // 0x8064B7F4: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8064B7F8: b           L_8064B80C
    // 0x8064B7FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8064B80C;
    // 0x8064B7FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064B800:
    // 0x8064B800: jal         0x8064B7C8
    // 0x8064B804: nop

    func_8064B7C8(rdram, ctx);
        goto after_1;
    // 0x8064B804: nop

    after_1:
    // 0x8064B808: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8064B80C:
    // 0x8064B80C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064B810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B814: jr          $ra
    // 0x8064B818: nop

    return;
    // 0x8064B818: nop

;}
RECOMP_FUNC void func_80581660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581660: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80581664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80581668: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8058166C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80581670: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80581674: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80581678: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8058167C: jal         0x8057EF14
    // 0x80581680: addiu       $a1, $zero, 0x4023
    ctx->r5 = ADD32(0, 0X4023);
    func_8057EF14(rdram, ctx);
        goto after_0;
    // 0x80581680: addiu       $a1, $zero, 0x4023
    ctx->r5 = ADD32(0, 0X4023);
    after_0:
    // 0x80581684: beq         $v0, $zero, L_80581720
    if (ctx->r2 == 0) {
        // 0x80581688: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80581720;
    }
    // 0x80581688: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8058168C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80581690: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80581694: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80581698: jal         0x8005C27C
    // 0x8058169C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x8058169C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x805816A0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x805816A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805816A8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805816AC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x805816B0: jal         0x8005C27C
    // 0x805816B4: lhu         $a1, 0xA($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XA);
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x805816B4: lhu         $a1, 0xA($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XA);
    after_2:
    // 0x805816B8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805816BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805816C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805816C4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x805816C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805816CC: jal         0x8005C27C
    // 0x805816D0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x805816D0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_3:
    // 0x805816D4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x805816D8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x805816DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805816E0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x805816E4: jal         0x8005C27C
    // 0x805816E8: lhu         $a1, 0x6($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X6);
    func_8005C27C(rdram, ctx);
        goto after_4;
    // 0x805816E8: lhu         $a1, 0x6($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X6);
    after_4:
    // 0x805816EC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x805816F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805816F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805816F8: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x805816FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80581700: jal         0x8005C27C
    // 0x80581704: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x80581704: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_5:
    // 0x80581708: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8058170C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80581710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80581714: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80581718: jal         0x8005C27C
    // 0x8058171C: lhu         $a1, 0x2($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X2);
    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x8058171C: lhu         $a1, 0x2($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X2);
    after_6:
L_80581720:
    // 0x80581720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80581724: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80581728: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8058172C: jr          $ra
    // 0x80581730: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80581730: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8046C6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C6F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046C6F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046C6F8: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8046C6FC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8046C700: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8046C704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046C708: bne         $v0, $at, L_8046C724
    if (ctx->r2 != ctx->r1) {
        // 0x8046C70C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8046C724;
    }
    // 0x8046C70C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8046C710: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(143, 0X1C0) << 16);
    // 0x8046C714: addiu       $t6, $t6, -0x39F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(143, 0X1C0));
    // 0x8046C718: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8046C71C: b           L_8046C778
    // 0x8046C720: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
        goto L_8046C778;
    // 0x8046C720: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
L_8046C724:
    // 0x8046C724: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8046C728: bne         $v0, $at, L_8046C778
    if (ctx->r2 != ctx->r1) {
        // 0x8046C72C: lui         $t7, 0x8005
        ctx->r15 = S32(0X8005 << 16);
            goto L_8046C778;
    }
    // 0x8046C72C: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8046C730: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(143, 0X15A4) << 16);
    // 0x8046C734: lwc1        $f0, -0x260C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(143, 0X15A4));
    // 0x8046C738: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8046C73C: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x8046C740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046C744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046C748: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8046C74C: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x8046C750: jal         0x8046D3E8
    // 0x8046C754: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    func_8046D3E8(rdram, ctx);
        goto after_0;
    // 0x8046C754: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    after_0:
    // 0x8046C758: jal         0x8004700C
    // 0x8046C75C: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x8046C75C: nop

    after_1:
    // 0x8046C760: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8046C764: jal         0x8046C624
    // 0x8046C768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8046C624(rdram, ctx);
        goto after_2;
    // 0x8046C768: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8046C76C: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046C770: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8046C774: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
L_8046C778:
    // 0x8046C778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8046C77C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046C780: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046C784: jr          $ra
    // 0x8046C788: nop

    return;
    // 0x8046C788: nop

;}
RECOMP_FUNC void func_8002BE1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BE1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002BE20: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002BE24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BE28: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002BE2C: addiu       $t6, $t6, 0x1BC8
    ctx->r14 = ADD32(ctx->r14, 0X1BC8);
    // 0x8002BE30: addiu       $a1, $a1, -0x2958
    ctx->r5 = ADD32(ctx->r5, -0X2958);
    // 0x8002BE34: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8002BE38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002BE3C: jal         0x80028118
    // 0x8002BE40: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002BE40: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002BE44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002BE48: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002BE4C: sw          $zero, 0x78($t7)
    MEM_W(0X78, ctx->r15) = 0;
    // 0x8002BE50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BE54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002BE58: jr          $ra
    // 0x8002BE5C: nop

    return;
    // 0x8002BE5C: nop

;}
RECOMP_FUNC void func_807A60A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A60A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807A60AC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807A60B0: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(847, 0X14B0) << 16);
    // 0x807A60B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807A60B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807A60BC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x807A60C0: addiu       $t7, $t7, 0x71B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(847, 0X14B0));
    // 0x807A60C4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x807A60C8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x807A60CC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x807A60D0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x807A60D4: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x807A60D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807A60DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A60E0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x807A60E4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x807A60E8: jal         0x807A5DC8
    // 0x807A60EC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    func_807A5DC8(rdram, ctx);
        goto after_0;
    // 0x807A60EC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    after_0:
    // 0x807A60F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x807A60F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807A60F8: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x807A60FC: jal         0x807A5DC8
    // 0x807A6100: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_807A5DC8(rdram, ctx);
        goto after_1;
    // 0x807A6100: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x807A6104: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x807A6108: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807A610C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x807A6110: jal         0x807A5DC8
    // 0x807A6114: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_807A5DC8(rdram, ctx);
        goto after_2;
    // 0x807A6114: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x807A6118: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x807A611C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1554) << 16);
    // 0x807A6120: lwc1        $f12, 0x7254($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1554));
    // 0x807A6124: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1558) << 16);
    // 0x807A6128: jal         0x807A5DC8
    // 0x807A612C: lwc1        $f14, 0x7258($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1558));
    func_807A5DC8(rdram, ctx);
        goto after_3;
    // 0x807A612C: lwc1        $f14, 0x7258($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1558));
    after_3:
    // 0x807A6130: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x807A6134: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x807A6138: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x807A613C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x807A6140: addu        $t2, $sp, $t1
    ctx->r10 = ADD32(ctx->r29, ctx->r9);
    // 0x807A6144: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807A6148: jal         0x807A5DC8
    // 0x807A614C: lwc1        $f12, 0x38($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X38);
    func_807A5DC8(rdram, ctx);
        goto after_4;
    // 0x807A614C: lwc1        $f12, 0x38($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X38);
    after_4:
    // 0x807A6150: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x807A6154: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807A6158: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x807A615C: jal         0x80066E88
    // 0x807A6160: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x807A6160: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_5:
    // 0x807A6164: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807A6168: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x807A616C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x807A6170: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x807A6174: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807A6178: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x807A617C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x807A6180: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x807A6184: jal         0x80066DE4
    // 0x807A6188: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x807A6188: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_6:
    // 0x807A618C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807A6190: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x807A6194: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x807A6198: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x807A619C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X155C) << 16);
    // 0x807A61A0: lwc1        $f2, 0x725C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X155C));
    // 0x807A61A4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1560) << 16);
    // 0x807A61A8: swc1        $f20, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f20.u32l;
    // 0x807A61AC: swc1        $f20, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f20.u32l;
    // 0x807A61B0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x807A61B4: lwc1        $f8, 0x7260($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(847, 0X1560));
    // 0x807A61B8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807A61BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807A61C0: swc1        $f20, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f20.u32l;
    // 0x807A61C4: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x807A61C8: swc1        $f20, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f20.u32l;
    // 0x807A61CC: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x807A61D0: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    // 0x807A61D4: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    // 0x807A61D8: swc1        $f2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f2.u32l;
    // 0x807A61DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807A61E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807A61E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807A61E8: jr          $ra
    // 0x807A61EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x807A61EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8067641C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067641C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676420: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80676424: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80676428: lwc1        $f4, 0x3F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3F0);
    // 0x8067642C: lwc1        $f10, 0x2F0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x80676430: lwc1        $f16, 0x3E8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80676434: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80676438: lwc1        $f8, 0x3EC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x8067643C: mul.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80676440: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80676444: lw          $t6, 0x2EC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2EC);
    // 0x80676448: mul.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8067644C: addiu       $t0, $v0, 0x4
    ctx->r8 = ADD32(ctx->r2, 0X4);
    // 0x80676450: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80676454: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80676458: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8067645C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80676460: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x80676464: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80676468: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8067646C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80676470: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x80676474: addiu       $v1, $zero, 0x3E
    ctx->r3 = ADD32(0, 0X3E);
    // 0x80676478: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8067647C: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80676480: addiu       $t1, $a2, 0x178
    ctx->r9 = ADD32(ctx->r6, 0X178);
    // 0x80676484: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80676488: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8067648C: nop

    // 0x80676490: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x80676494: sh          $t2, 0x174($a2)
    MEM_H(0X174, ctx->r6) = ctx->r10;
    // 0x80676498: lwc1        $f16, 0x3E8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x8067649C: lwc1        $f10, 0x2F0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2F0);
    // 0x806764A0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806764A4: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x806764A8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806764AC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x806764B0: nop

    // 0x806764B4: sh          $t8, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r24;
    // 0x806764B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806764BC: sh          $t2, 0x176($a2)
    MEM_H(0X176, ctx->r6) = ctx->r10;
    // 0x806764C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806764C4: lwc1        $f18, 0x2F0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X2F0);
    // 0x806764C8: beq         $a1, $v1, L_8067658C
    if (ctx->r5 == ctx->r3) {
        // 0x806764CC: lwc1        $f16, 0x3E8($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X3E8);
            goto L_8067658C;
    }
    // 0x806764CC: lwc1        $f16, 0x3E8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x806764D0: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_806764D4:
    // 0x806764D4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x806764D8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806764DC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x806764E0: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x806764E4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x806764E8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x806764EC: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x806764F0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x806764F4: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806764F8: mfc1        $t6, $f14
    ctx->r14 = (int32_t)ctx->f14.u32l;
    // 0x806764FC: nop

    // 0x80676500: sh          $t6, -0x8($a3)
    MEM_H(-0X8, ctx->r7) = ctx->r14;
    // 0x80676504: sh          $t2, -0x8($t1)
    MEM_H(-0X8, ctx->r9) = ctx->r10;
    // 0x80676508: lwc1        $f14, 0x2E8($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X2E8);
    // 0x8067650C: lwc1        $f10, 0x3E8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80676510: sub.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80676514: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80676518: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8067651C: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80676520: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80676524: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80676528: sh          $t9, -0x6($a3)
    MEM_H(-0X6, ctx->r7) = ctx->r25;
    // 0x8067652C: sh          $t2, -0x6($t1)
    MEM_H(-0X6, ctx->r9) = ctx->r10;
    // 0x80676530: lwc1        $f10, 0x2EC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X2EC);
    // 0x80676534: lwc1        $f8, 0x3E8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80676538: mfc1        $t2, $f14
    ctx->r10 = (int32_t)ctx->f14.u32l;
    // 0x8067653C: add.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80676540: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80676544: trunc.w.s   $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80676548: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8067654C: nop

    // 0x80676550: sh          $t7, -0x4($a3)
    MEM_H(-0X4, ctx->r7) = ctx->r15;
    // 0x80676554: sh          $t2, -0x4($t1)
    MEM_H(-0X4, ctx->r9) = ctx->r10;
    // 0x80676558: lwc1        $f8, 0x2EC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X2EC);
    // 0x8067655C: lwc1        $f10, 0x3E8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80676560: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80676564: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80676568: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8067656C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80676570: nop

    // 0x80676574: sh          $t6, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r14;
    // 0x80676578: sh          $t2, -0x2($t1)
    MEM_H(-0X2, ctx->r9) = ctx->r10;
    // 0x8067657C: lwc1        $f18, 0x2F0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X2F0);
    // 0x80676580: lwc1        $f16, 0x3E8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80676584: bnel        $a1, $v1, L_806764D4
    if (ctx->r5 != ctx->r3) {
        // 0x80676588: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_806764D4;
    }
    goto skip_0;
    // 0x80676588: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_0:
L_8067658C:
    // 0x8067658C: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80676590: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80676594: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80676598: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8067659C: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x806765A0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x806765A4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x806765A8: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x806765AC: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806765B0: mfc1        $t6, $f14
    ctx->r14 = (int32_t)ctx->f14.u32l;
    // 0x806765B4: nop

    // 0x806765B8: sh          $t6, -0x8($a3)
    MEM_H(-0X8, ctx->r7) = ctx->r14;
    // 0x806765BC: sh          $t2, -0x8($t1)
    MEM_H(-0X8, ctx->r9) = ctx->r10;
    // 0x806765C0: lwc1        $f10, 0x3E8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x806765C4: lwc1        $f14, 0x2E8($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X2E8);
    // 0x806765C8: sub.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x806765CC: trunc.w.s   $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x806765D0: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x806765D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x806765D8: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806765DC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x806765E0: nop

    // 0x806765E4: sh          $t9, -0x6($a3)
    MEM_H(-0X6, ctx->r7) = ctx->r25;
    // 0x806765E8: sh          $t2, -0x6($t1)
    MEM_H(-0X6, ctx->r9) = ctx->r10;
    // 0x806765EC: lwc1        $f8, 0x3E8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x806765F0: lwc1        $f10, 0x2EC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X2EC);
    // 0x806765F4: mfc1        $t2, $f14
    ctx->r10 = (int32_t)ctx->f14.u32l;
    // 0x806765F8: add.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x806765FC: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80676600: trunc.w.s   $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80676604: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80676608: nop

    // 0x8067660C: sh          $t7, -0x4($a3)
    MEM_H(-0X4, ctx->r7) = ctx->r15;
    // 0x80676610: sh          $t2, -0x4($t1)
    MEM_H(-0X4, ctx->r9) = ctx->r10;
    // 0x80676614: lwc1        $f10, 0x3E8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3E8);
    // 0x80676618: lwc1        $f8, 0x2EC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X2EC);
    // 0x8067661C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80676620: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80676624: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80676628: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8067662C: nop

    // 0x80676630: sh          $t6, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r14;
    // 0x80676634: sh          $t2, -0x2($t1)
    MEM_H(-0X2, ctx->r9) = ctx->r10;
    // 0x80676638: jr          $ra
    // 0x8067663C: nop

    return;
    // 0x8067663C: nop

;}
RECOMP_FUNC void func_807B1508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B1508: addiu       $sp, $sp, -0x1E0
    ctx->r29 = ADD32(ctx->r29, -0X1E0);
    // 0x807B150C: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x807B1510: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x807B1514: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x807B1518: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x807B151C: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x807B1520: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x807B1524: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x807B1528: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x807B152C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x807B1530: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x807B1534: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x807B1538: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x807B153C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x807B1540: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x807B1544: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x807B1548: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x807B154C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B1550: addiu       $s3, $sp, 0x134
    ctx->r19 = ADD32(ctx->r29, 0X134);
    // 0x807B1554: addiu       $s1, $sp, 0xF4
    ctx->r17 = ADD32(ctx->r29, 0XF4);
    // 0x807B1558: addiu       $s5, $s0, 0x6C
    ctx->r21 = ADD32(ctx->r16, 0X6C);
    // 0x807B155C: sw          $s5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r21;
    // 0x807B1560: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x807B1564: addiu       $s6, $s0, 0x4
    ctx->r22 = ADD32(ctx->r16, 0X4);
    // 0x807B1568: addiu       $s4, $sp, 0xB4
    ctx->r20 = ADD32(ctx->r29, 0XB4);
    // 0x807B156C: sw          $t7, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r15;
    // 0x807B1570: lw          $s7, 0x0($t7)
    ctx->r23 = MEM_W(ctx->r15, 0X0);
    // 0x807B1574: sw          $s6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r22;
    // 0x807B1578: lwc1        $f0, 0x16C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x807B157C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807B1580: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x807B1584: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x807B1588: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B158C: swc1        $f4, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->f4.u32l;
    // 0x807B1590: lwc1        $f2, 0x154($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X154);
    // 0x807B1594: lwc1        $f8, 0x18C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x807B1598: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B159C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x807B15A0: swc1        $f10, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->f10.u32l;
L_807B15A4:
    // 0x807B15A4: lwc1        $f24, 0x0($s5)
    ctx->f24.u32l = MEM_W(ctx->r21, 0X0);
    // 0x807B15A8: lwc1        $f4, 0x158($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X158);
    // 0x807B15AC: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x807B15B0: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x807B15B4: nop

    // 0x807B15B8: bc1fl       L_807B19A0
    if (!c1cs) {
        // 0x807B15BC: sw          $zero, 0x0($s4)
        MEM_W(0X0, ctx->r20) = 0;
            goto L_807B19A0;
    }
    goto skip_0;
    // 0x807B15BC: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    skip_0:
    // 0x807B15C0: lwc1        $f26, 0x4($s5)
    ctx->f26.u32l = MEM_W(ctx->r21, 0X4);
    // 0x807B15C4: lwc1        $f8, 0x15C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x807B15C8: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x807B15CC: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x807B15D0: nop

    // 0x807B15D4: bc1fl       L_807B19A0
    if (!c1cs) {
        // 0x807B15D8: sw          $zero, 0x0($s4)
        MEM_W(0X0, ctx->r20) = 0;
            goto L_807B19A0;
    }
    goto skip_1;
    // 0x807B15D8: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    skip_1:
    // 0x807B15DC: lh          $t0, 0x0($s6)
    ctx->r8 = MEM_H(ctx->r22, 0X0);
    // 0x807B15E0: lh          $t1, 0x2($s6)
    ctx->r9 = MEM_H(ctx->r22, 0X2);
    // 0x807B15E4: lwc1        $f16, 0x12C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B15E8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x807B15EC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x807B15F0: lwc1        $f22, 0x130($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X130);
    // 0x807B15F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807B15F8: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3940) << 16);
    // 0x807B15FC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807B1600: lwc1        $f8, 0x3490($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3940));
    // 0x807B1604: sub.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x807B1608: sub.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x807B160C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B1610: sub.s       $f20, $f24, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f24.fl - ctx->f16.fl;
    // 0x807B1614: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x807B1618: sub.s       $f30, $f26, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f30.fl = ctx->f26.fl - ctx->f22.fl;
    // 0x807B161C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x807B1620: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    // 0x807B1624: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807B1628: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807B162C: mul.s       $f28, $f0, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f28.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x807B1630: jal         0x80081E8C
    // 0x807B1634: nop

    fatan2(rdram, ctx);
        goto after_0;
    // 0x807B1634: nop

    after_0:
    // 0x807B1638: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3944) << 16);
    // 0x807B163C: lwc1        $f10, 0x3494($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3944));
    // 0x807B1640: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x807B1644: jal         0x80066E88
    // 0x807B1648: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x807B1648: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    after_1:
    // 0x807B164C: mul.s       $f6, $f0, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x807B1650: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B1654: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x807B1658: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807B165C: jal         0x80066DE4
    // 0x807B1660: swc1        $f8, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->f8.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x807B1660: swc1        $f8, 0x1B4($sp)
    MEM_W(0X1B4, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x807B1664: mul.s       $f10, $f0, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x807B1668: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3948) << 16);
    // 0x807B166C: lwc1        $f6, 0x3498($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3948));
    // 0x807B1670: lwc1        $f22, 0x130($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X130);
    // 0x807B1674: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X394C) << 16);
    // 0x807B1678: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x807B167C: add.s       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x807B1680: bc1t        L_807B17C4
    if (c1cs) {
        // 0x807B1684: swc1        $f4, 0x1B0($sp)
        MEM_W(0X1B0, ctx->r29) = ctx->f4.u32l;
            goto L_807B17C4;
    }
    // 0x807B1684: swc1        $f4, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->f4.u32l;
    // 0x807B1688: lwc1        $f8, 0x349C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X394C));
    // 0x807B168C: c.lt.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl < ctx->f8.fl;
    // 0x807B1690: nop

    // 0x807B1694: bc1tl       L_807B17C8
    if (c1cs) {
        // 0x807B1698: div.s       $f24, $f30, $f20
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f20.fl);
            goto L_807B17C8;
    }
    goto skip_2;
    // 0x807B1698: div.s       $f24, $f30, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f20.fl);
    skip_2:
    // 0x807B169C: lwc1        $f0, 0x158($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X158);
    // 0x807B16A0: lwc1        $f10, 0x18C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18C);
    // 0x807B16A4: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3950) << 16);
    // 0x807B16A8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x807B16AC: lwc1        $f6, 0x34A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3950));
    // 0x807B16B0: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3954) << 16);
    // 0x807B16B4: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x807B16B8: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x807B16BC: nop

    // 0x807B16C0: bc1tl       L_807B17BC
    if (c1cs) {
        // 0x807B16C4: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_807B17BC;
    }
    goto skip_3;
    // 0x807B16C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x807B16C8: lwc1        $f8, 0x34A4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3954));
    // 0x807B16CC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3958) << 16);
    // 0x807B16D0: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x807B16D4: nop

    // 0x807B16D8: bc1tl       L_807B1704
    if (c1cs) {
        // 0x807B16DC: sqrt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
            goto L_807B1704;
    }
    goto skip_4;
    // 0x807B16DC: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    skip_4:
    // 0x807B16E0: lwc1        $f10, 0x34A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3958));
    // 0x807B16E4: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x807B16E8: nop

    // 0x807B16EC: bc1tl       L_807B1704
    if (c1cs) {
        // 0x807B16F0: sqrt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
            goto L_807B1704;
    }
    goto skip_5;
    // 0x807B16F0: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    skip_5:
    // 0x807B16F4: lwc1        $f4, 0x15C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x807B16F8: b           L_807B1738
    // 0x807B16FC: add.s       $f30, $f22, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f4.fl;
        goto L_807B1738;
    // 0x807B16FC: add.s       $f30, $f22, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f4.fl;
    // 0x807B1700: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
L_807B1704:
    // 0x807B1704: lwc1        $f2, 0x15C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x807B1708: add.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x807B170C: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x807B1710: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x807B1714: nop

    // 0x807B1718: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x807B171C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x807B1720: nop

    // 0x807B1724: bc1f        L_807B1734
    if (!c1cs) {
        // 0x807B1728: nop
    
            goto L_807B1734;
    }
    // 0x807B1728: nop

    // 0x807B172C: b           L_807B1738
    // 0x807B1730: add.s       $f30, $f22, $f14
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f14.fl;
        goto L_807B1738;
    // 0x807B1730: add.s       $f30, $f22, $f14
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f14.fl;
L_807B1734:
    // 0x807B1734: add.s       $f30, $f22, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f16.fl;
L_807B1738:
    // 0x807B1738: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B173C: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x807B1740: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x807B1744: swc1        $f0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f0.u32l;
    // 0x807B1748: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B174C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x807B1750: nop

    // 0x807B1754: sh          $t3, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r11;
    // 0x807B1758: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B175C: bne         $at, $zero, L_807B1790
    if (ctx->r1 != 0) {
        // 0x807B1760: swc1        $f4, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->f4.u32l;
            goto L_807B1790;
    }
    // 0x807B1760: swc1        $f4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f4.u32l;
    // 0x807B1764: slti        $at, $s2, 0xD
    ctx->r1 = SIGNED(ctx->r18) < 0XD ? 1 : 0;
    // 0x807B1768: beq         $at, $zero, L_807B1790
    if (ctx->r1 == 0) {
        // 0x807B176C: lwc1        $f6, 0x1B0($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X1B0);
            goto L_807B1790;
    }
    // 0x807B176C: lwc1        $f6, 0x1B0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x807B1770: c.lt.s      $f6, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f6.fl < ctx->f30.fl;
    // 0x807B1774: nop

    // 0x807B1778: bc1f        L_807B1788
    if (!c1cs) {
        // 0x807B177C: nop
    
            goto L_807B1788;
    }
    // 0x807B177C: nop

    // 0x807B1780: b           L_807B17B0
    // 0x807B1784: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_807B17B0;
    // 0x807B1784: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_807B1788:
    // 0x807B1788: b           L_807B17B0
    // 0x807B178C: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
        goto L_807B17B0;
    // 0x807B178C: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
L_807B1790:
    // 0x807B1790: lwc1        $f8, 0x1B0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x807B1794: c.lt.s      $f30, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f30.fl < ctx->f8.fl;
    // 0x807B1798: nop

    // 0x807B179C: bc1fl       L_807B17B0
    if (!c1cs) {
        // 0x807B17A0: swc1        $f30, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
            goto L_807B17B0;
    }
    goto skip_6;
    // 0x807B17A0: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
    skip_6:
    // 0x807B17A4: b           L_807B17B0
    // 0x807B17A8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_807B17B0;
    // 0x807B17A8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x807B17AC: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
L_807B17B0:
    // 0x807B17B0: b           L_807B19A0
    // 0x807B17B4: sw          $fp, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r30;
        goto L_807B19A0;
    // 0x807B17B4: sw          $fp, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r30;
    // 0x807B17B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_807B17BC:
    // 0x807B17BC: b           L_807B19A0
    // 0x807B17C0: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
        goto L_807B19A0;
    // 0x807B17C0: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
L_807B17C4:
    // 0x807B17C4: div.s       $f24, $f30, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f20.fl);
L_807B17C8:
    // 0x807B17C8: lwc1        $f10, 0x15C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x807B17CC: lwc1        $f6, 0x158($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X158);
    // 0x807B17D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807B17D4: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x807B17D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807B17DC: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X395C) << 16);
    // 0x807B17E0: mul.s       $f8, $f24, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x807B17E4: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807B17E8: lwc1        $f6, 0x194($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X194);
    // 0x807B17EC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807B17F0: lwc1        $f10, 0x34AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X395C));
    // 0x807B17F4: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3960) << 16);
    // 0x807B17F8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x807B17FC: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x807B1800: nop

    // 0x807B1804: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x807B1808: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x807B180C: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x807B1810: nop

    // 0x807B1814: bc1t        L_807B198C
    if (c1cs) {
        // 0x807B1818: nop
    
            goto L_807B198C;
    }
    // 0x807B1818: nop

    // 0x807B181C: lwc1        $f6, 0x34B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3960));
    // 0x807B1820: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3964) << 16);
    // 0x807B1824: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x807B1828: nop

    // 0x807B182C: bc1tl       L_807B1868
    if (c1cs) {
        // 0x807B1830: sqrt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
            goto L_807B1868;
    }
    goto skip_7;
    // 0x807B1830: sqrt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
    skip_7:
    // 0x807B1834: lwc1        $f4, 0x34B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3964));
    // 0x807B1838: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x807B183C: nop

    // 0x807B1840: bc1tl       L_807B1868
    if (c1cs) {
        // 0x807B1844: sqrt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
            goto L_807B1868;
    }
    goto skip_8;
    // 0x807B1844: sqrt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
    skip_8:
    // 0x807B1848: neg.s       $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = -ctx->f14.fl;
    // 0x807B184C: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B1850: div.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x807B1854: mul.s       $f10, $f24, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x807B1858: add.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x807B185C: b           L_807B18D8
    // 0x807B1860: add.s       $f30, $f22, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f10.fl;
        goto L_807B18D8;
    // 0x807B1860: add.s       $f30, $f22, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x807B1864: sqrt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = sqrtf(ctx->f16.fl);
L_807B1868:
    // 0x807B1868: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x807B186C: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x807B1870: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x807B1874: div.s       $f20, $f4, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x807B1878: div.s       $f18, $f8, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x807B187C: mul.s       $f28, $f24, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f28.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x807B1880: nop

    // 0x807B1884: mul.s       $f26, $f24, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x807B1888: nop

    // 0x807B188C: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x807B1890: nop

    // 0x807B1894: mul.s       $f6, $f28, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x807B1898: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x807B189C: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x807B18A0: nop

    // 0x807B18A4: mul.s       $f10, $f26, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x807B18A8: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807B18AC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807B18B0: nop

    // 0x807B18B4: bc1f        L_807B18CC
    if (!c1cs) {
        // 0x807B18B8: nop
    
            goto L_807B18CC;
    }
    // 0x807B18B8: nop

    // 0x807B18BC: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B18C0: add.s       $f30, $f22, $f28
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f28.fl;
    // 0x807B18C4: b           L_807B18D8
    // 0x807B18C8: add.s       $f2, $f8, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f20.fl;
        goto L_807B18D8;
    // 0x807B18C8: add.s       $f2, $f8, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f20.fl;
L_807B18CC:
    // 0x807B18CC: lwc1        $f10, 0x12C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x807B18D0: add.s       $f30, $f22, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f30.fl = ctx->f22.fl + ctx->f26.fl;
    // 0x807B18D4: add.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f18.fl;
L_807B18D8:
    // 0x807B18D8: blez        $s2, L_807B1908
    if (SIGNED(ctx->r18) <= 0) {
        // 0x807B18DC: slti        $at, $s2, 0x9
        ctx->r1 = SIGNED(ctx->r18) < 0X9 ? 1 : 0;
            goto L_807B1908;
    }
    // 0x807B18DC: slti        $at, $s2, 0x9
    ctx->r1 = SIGNED(ctx->r18) < 0X9 ? 1 : 0;
    // 0x807B18E0: beq         $at, $zero, L_807B1908
    if (ctx->r1 == 0) {
        // 0x807B18E4: lwc1        $f0, 0x1B4($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1B4);
            goto L_807B1908;
    }
    // 0x807B18E4: lwc1        $f0, 0x1B4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1B4);
    // 0x807B18E8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x807B18EC: nop

    // 0x807B18F0: bc1f        L_807B1900
    if (!c1cs) {
        // 0x807B18F4: nop
    
            goto L_807B1900;
    }
    // 0x807B18F4: nop

    // 0x807B18F8: b           L_807B1928
    // 0x807B18FC: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
        goto L_807B1928;
    // 0x807B18FC: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
L_807B1900:
    // 0x807B1900: b           L_807B1928
    // 0x807B1904: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
        goto L_807B1928;
    // 0x807B1904: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
L_807B1908:
    // 0x807B1908: lwc1        $f0, 0x1B4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1B4);
    // 0x807B190C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x807B1910: nop

    // 0x807B1914: bc1fl       L_807B1928
    if (!c1cs) {
        // 0x807B1918: swc1        $f2, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
            goto L_807B1928;
    }
    goto skip_9;
    // 0x807B1918: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
    skip_9:
    // 0x807B191C: b           L_807B1928
    // 0x807B1920: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
        goto L_807B1928;
    // 0x807B1920: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x807B1924: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
L_807B1928:
    // 0x807B1928: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x807B192C: bne         $at, $zero, L_807B1964
    if (ctx->r1 != 0) {
        // 0x807B1930: lwc1        $f0, 0x1B0($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X1B0);
            goto L_807B1964;
    }
    // 0x807B1930: lwc1        $f0, 0x1B0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x807B1934: slti        $at, $s2, 0xD
    ctx->r1 = SIGNED(ctx->r18) < 0XD ? 1 : 0;
    // 0x807B1938: beql        $at, $zero, L_807B1968
    if (ctx->r1 == 0) {
        // 0x807B193C: c.lt.s      $f30, $f0
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
            goto L_807B1968;
    }
    goto skip_10;
    // 0x807B193C: c.lt.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
    skip_10:
    // 0x807B1940: lwc1        $f0, 0x1B0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1B0);
    // 0x807B1944: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x807B1948: nop

    // 0x807B194C: bc1f        L_807B195C
    if (!c1cs) {
        // 0x807B1950: nop
    
            goto L_807B195C;
    }
    // 0x807B1950: nop

    // 0x807B1954: b           L_807B1980
    // 0x807B1958: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_807B1980;
    // 0x807B1958: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_807B195C:
    // 0x807B195C: b           L_807B1980
    // 0x807B1960: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
        goto L_807B1980;
    // 0x807B1960: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
L_807B1964:
    // 0x807B1964: c.lt.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl < ctx->f0.fl;
L_807B1968:
    // 0x807B1968: nop

    // 0x807B196C: bc1fl       L_807B1980
    if (!c1cs) {
        // 0x807B1970: swc1        $f30, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
            goto L_807B1980;
    }
    goto skip_11;
    // 0x807B1970: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
    skip_11:
    // 0x807B1974: b           L_807B1980
    // 0x807B1978: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_807B1980;
    // 0x807B1978: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x807B197C: swc1        $f30, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f30.u32l;
L_807B1980:
    // 0x807B1980: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B1984: b           L_807B19A0
    // 0x807B1988: sw          $fp, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r30;
        goto L_807B19A0;
    // 0x807B1988: sw          $fp, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r30;
L_807B198C:
    // 0x807B198C: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x807B1990: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B1994: b           L_807B19A4
    // 0x807B1998: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_807B19A4;
    // 0x807B1998: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x807B199C: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
L_807B19A0:
    // 0x807B19A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_807B19A4:
    // 0x807B19A4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x807B19A8: addiu       $s6, $s6, 0x6
    ctx->r22 = ADD32(ctx->r22, 0X6);
    // 0x807B19AC: addiu       $s7, $s7, 0x6
    ctx->r23 = ADD32(ctx->r23, 0X6);
    // 0x807B19B0: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x807B19B4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x807B19B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807B19BC: bne         $s2, $at, L_807B15A4
    if (ctx->r18 != ctx->r1) {
        // 0x807B19C0: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_807B15A4;
    }
    // 0x807B19C0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x807B19C4: addiu       $t4, $sp, 0xB4
    ctx->r12 = ADD32(ctx->r29, 0XB4);
    // 0x807B19C8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x807B19CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B19D0: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x807B19D4: addiu       $a2, $sp, 0x134
    ctx->r6 = ADD32(ctx->r29, 0X134);
    // 0x807B19D8: jal         0x807B11E8
    // 0x807B19DC: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    func_807B11E8(rdram, ctx);
        goto after_3;
    // 0x807B19DC: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    after_3:
    // 0x807B19E0: lw          $t5, 0x1D0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1D0);
    // 0x807B19E4: addiu       $t6, $sp, 0xF4
    ctx->r14 = ADD32(ctx->r29, 0XF4);
    // 0x807B19E8: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x807B19EC: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x807B19F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x807B19F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807B19F8: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x807B19FC: lw          $a2, 0x9C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X9C);
    // 0x807B1A00: jal         0x807B1100
    // 0x807B1A04: addiu       $a3, $sp, 0x134
    ctx->r7 = ADD32(ctx->r29, 0X134);
    func_807B1100(rdram, ctx);
        goto after_4;
    // 0x807B1A04: addiu       $a3, $sp, 0x134
    ctx->r7 = ADD32(ctx->r29, 0X134);
    after_4:
    // 0x807B1A08: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x807B1A0C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x807B1A10: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x807B1A14: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x807B1A18: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x807B1A1C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x807B1A20: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x807B1A24: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x807B1A28: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x807B1A2C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x807B1A30: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x807B1A34: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x807B1A38: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x807B1A3C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x807B1A40: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x807B1A44: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x807B1A48: jr          $ra
    // 0x807B1A4C: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    return;
    // 0x807B1A4C: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
;}
RECOMP_FUNC void func_8043F780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F780: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043F784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043F788: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043F78C: jal         0x8004700C
    // 0x8043F790: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043F790: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8043F794: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8043F798: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x8043F79C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8043F7A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043F7A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F7A8: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8043F7AC: jal         0x80442188
    // 0x8043F7B0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80442188(rdram, ctx);
        goto after_1;
    // 0x8043F7B0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x8043F7B4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8043F7B8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8043F7BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8043F7C0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8043F7C4: beq         $t0, $zero, L_8043F7E0
    if (ctx->r8 == 0) {
        // 0x8043F7C8: swc1        $f0, 0x1C80($v1)
        MEM_W(0X1C80, ctx->r3) = ctx->f0.u32l;
            goto L_8043F7E0;
    }
    // 0x8043F7C8: swc1        $f0, 0x1C80($v1)
    MEM_W(0X1C80, ctx->r3) = ctx->f0.u32l;
    // 0x8043F7CC: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8043F7D0: lwc1        $f6, 0x40($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X40);
    // 0x8043F7D4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043F7D8: b           L_8043F7E4
    // 0x8043F7DC: swc1        $f8, 0x1C84($v1)
    MEM_W(0X1C84, ctx->r3) = ctx->f8.u32l;
        goto L_8043F7E4;
    // 0x8043F7DC: swc1        $f8, 0x1C84($v1)
    MEM_W(0X1C84, ctx->r3) = ctx->f8.u32l;
L_8043F7E0:
    // 0x8043F7E0: swc1        $f0, 0x1C84($v1)
    MEM_W(0X1C84, ctx->r3) = ctx->f0.u32l;
L_8043F7E4:
    // 0x8043F7E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8043F7E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043F7EC: swc1        $f0, 0x1C88($v1)
    MEM_W(0X1C88, ctx->r3) = ctx->f0.u32l;
    // 0x8043F7F0: jal         0x8043F310
    // 0x8043F7F4: swc1        $f0, 0x1C8C($v1)
    MEM_W(0X1C8C, ctx->r3) = ctx->f0.u32l;
    func_8043F310(rdram, ctx);
        goto after_2;
    // 0x8043F7F4: swc1        $f0, 0x1C8C($v1)
    MEM_W(0X1C8C, ctx->r3) = ctx->f0.u32l;
    after_2:
    // 0x8043F7F8: jal         0x8043F1A0
    // 0x8043F7FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F1A0(rdram, ctx);
        goto after_3;
    // 0x8043F7FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043F800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043F804: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043F808: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043F80C: jr          $ra
    // 0x8043F810: nop

    return;
    // 0x8043F810: nop

;}
RECOMP_FUNC void func_806EEED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EEED0: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x806EEED4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EEED8: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806EEEDC: bne         $t6, $zero, L_806EEF2C
    if (ctx->r14 != 0) {
        // 0x806EEEE0: lui         $at, 0xC170
        ctx->r1 = S32(0XC170 << 16);
            goto L_806EEF2C;
    }
    // 0x806EEEE0: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x806EEEE4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x806EEEE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EEEEC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D44) << 16);
    // 0x806EEEF0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806EEEF4: nop

    // 0x806EEEF8: bc1fl       L_806EEF1C
    if (!c1cs) {
        // 0x806EEEFC: lwc1        $f16, 0x4($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
            goto L_806EEF1C;
    }
    goto skip_0;
    // 0x806EEEFC: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x806EEF00: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D40) << 16);
    // 0x806EEF04: lwc1        $f8, 0xC90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D40));
    // 0x806EEF08: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EEF0C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806EEF10: b           L_806EEF6C
    // 0x806EEF14: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
        goto L_806EEF6C;
    // 0x806EEF14: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x806EEF18: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
L_806EEF1C:
    // 0x806EEF1C: lwc1        $f18, 0xC94($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D44));
    // 0x806EEF20: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806EEF24: b           L_806EEF6C
    // 0x806EEF28: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
        goto L_806EEF6C;
    // 0x806EEF28: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_806EEF2C:
    // 0x806EEF2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806EEF30: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D4C) << 16);
    // 0x806EEF34: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x806EEF38: nop

    // 0x806EEF3C: bc1fl       L_806EEF60
    if (!c1cs) {
        // 0x806EEF40: lwc1        $f18, 0x4($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
            goto L_806EEF60;
    }
    goto skip_1;
    // 0x806EEF40: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x806EEF44: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D48) << 16);
    // 0x806EEF48: lwc1        $f10, 0xC98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D48));
    // 0x806EEF4C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EEF50: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806EEF54: b           L_806EEF6C
    // 0x806EEF58: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
        goto L_806EEF6C;
    // 0x806EEF58: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x806EEF5C: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
L_806EEF60:
    // 0x806EEF60: lwc1        $f4, 0xC9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D4C));
    // 0x806EEF64: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x806EEF68: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_806EEF6C:
    // 0x806EEF6C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x806EEF70: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806EEF74: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EEF78: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x806EEF7C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x806EEF80: nop

    // 0x806EEF84: bc1fl       L_806EEF9C
    if (!c1cs) {
        // 0x806EEF88: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806EEF9C;
    }
    goto skip_2;
    // 0x806EEF88: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_2:
    // 0x806EEF8C: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x806EEF90: b           L_806EEFB8
    // 0x806EEF94: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
        goto L_806EEFB8;
    // 0x806EEF94: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EEF98: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806EEF9C:
    // 0x806EEF9C: nop

    // 0x806EEFA0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806EEFA4: nop

    // 0x806EEFA8: bc1fl       L_806EEFBC
    if (!c1cs) {
        // 0x806EEFAC: add.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_806EEFBC;
    }
    goto skip_3;
    // 0x806EEFAC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    skip_3:
    // 0x806EEFB0: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x806EEFB4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
L_806EEFB8:
    // 0x806EEFB8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_806EEFBC:
    // 0x806EEFBC: jr          $ra
    // 0x806EEFC0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x806EEFC0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_800066E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800066E4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800066E8: bne         $a0, $at, L_800066F8
    if (ctx->r4 != ctx->r1) {
        // 0x800066EC: lui         $t6, 0x800B
        ctx->r14 = S32(0X800B << 16);
            goto L_800066F8;
    }
    // 0x800066EC: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x800066F0: jr          $ra
    // 0x800066F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800066F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800066F8:
    // 0x800066F8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800066FC: lbu         $t6, 0x76EC($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X76EC);
    // 0x80006700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80006704: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80006708: bne         $at, $zero, L_80006718
    if (ctx->r1 != 0) {
        // 0x8000670C: nop
    
            goto L_80006718;
    }
    // 0x8000670C: nop

    // 0x80006710: jr          $ra
    // 0x80006714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80006714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80006718:
    // 0x80006718: jr          $ra
    // 0x8000671C: nop

    return;
    // 0x8000671C: nop

;}
RECOMP_FUNC void func_8002310C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002310C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023110: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80023114: lwc1        $f4, -0x314($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X314);
    // 0x80023118: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002311C: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x80023120: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x80023124: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x80023128: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x8002312C: lwc1        $f6, -0x310($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X310);
    // 0x80023130: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80023134: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023138: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x8002313C: jr          $ra
    // 0x80023140: swc1        $f8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80023140: swc1        $f8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80432DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432DE0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80432DE4: addiu       $at, $zero, 0x4111
    ctx->r1 = ADD32(0, 0X4111);
    // 0x80432DE8: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(65, 0X6F8) << 16);
    // 0x80432DEC: bne         $t6, $at, L_80432E00
    if (ctx->r14 != ctx->r1) {
        // 0x80432DF0: addiu       $v0, $v0, 0x34D8
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(65, 0X6F8));
            goto L_80432E00;
    }
    // 0x80432DF0: addiu       $v0, $v0, 0x34D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(65, 0X6F8));
    // 0x80432DF4: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(65, 0X7F0) << 16);
    // 0x80432DF8: jr          $ra
    // 0x80432DFC: addiu       $v0, $v0, 0x35D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(65, 0X7F0));
    return;
    // 0x80432DFC: addiu       $v0, $v0, 0x35D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(65, 0X7F0));
L_80432E00:
    // 0x80432E00: jr          $ra
    // 0x80432E04: nop

    return;
    // 0x80432E04: nop

;}
RECOMP_FUNC void func_804751B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804751B0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804751B4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804751B8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804751BC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804751C0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804751C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804751C8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804751CC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804751D0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804751D4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804751D8: jr          $ra
    // 0x804751DC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804751DC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void ViMode_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EA54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007EA58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007EA5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007EA60: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x8007EA64: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x8007EA68: addiu       $t8, $zero, 0x42
    ctx->r24 = ADD32(0, 0X42);
    // 0x8007EA6C: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
    // 0x8007EA70: sw          $t6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r14;
    // 0x8007EA74: sw          $t7, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r15;
    // 0x8007EA78: sw          $zero, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = 0;
    // 0x8007EA7C: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    // 0x8007EA80: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x8007EA84: sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // 0x8007EA88: sw          $t8, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r24;
    // 0x8007EA8C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8007EA90: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x8007EA94: sw          $v0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r2;
    // 0x8007EA98: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x8007EA9C: sw          $zero, 0x74($a0)
    MEM_W(0X74, ctx->r4) = 0;
    // 0x8007EAA0: sw          $v0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r2;
    // 0x8007EAA4: jal         0x8007EA24
    // 0x8007EAA8: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    ViMode_Save(rdram, ctx);
        goto after_0;
    // 0x8007EAA8: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    after_0:
    // 0x8007EAAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007EAB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007EAB4: jr          $ra
    // 0x8007EAB8: nop

    return;
    // 0x8007EAB8: nop

;}
RECOMP_FUNC void func_8042DC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042DC30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042DC34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042DC38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042DC3C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8042DC40: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8042DC44: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8042DC48: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(53, 0X3B4) << 16);
    // 0x8042DC4C: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8042DC50: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8042DC54: addiu       $t7, $t7, -0x202C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(53, 0X3B4));
    // 0x8042DC58: lui         $t9, 0x8043
    ctx->r25 = S32(RELOC_HI16(53, 0X2D4) << 16);
    // 0x8042DC5C: addiu       $t9, $t9, -0x210C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(53, 0X2D4));
    // 0x8042DC60: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8042DC64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042DC68: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8042DC6C: sw          $t9, 0x1F8($a0)
    MEM_W(0X1F8, ctx->r4) = ctx->r25;
    // 0x8042DC70: jal         0x80045A34
    // 0x8042DC74: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8042DC74: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x8042DC78: bne         $v0, $zero, L_8042DC90
    if (ctx->r2 != 0) {
        // 0x8042DC7C: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8042DC90;
    }
    // 0x8042DC7C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8042DC80: jal         0x800445A4
    // 0x8042DC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8042DC84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8042DC88: b           L_8042DD48
    // 0x8042DC8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042DD48;
    // 0x8042DC8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042DC90:
    // 0x8042DC90: lui         $t0, 0x8043
    ctx->r8 = S32(RELOC_HI16(53, 0X3D8) << 16);
    // 0x8042DC94: lw          $t0, -0x2008($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(53, 0X3D8));
    // 0x8042DC98: bnel        $t0, $zero, L_8042DCB4
    if (ctx->r8 != 0) {
        // 0x8042DC9C: lw          $t2, 0x1F4($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X1F4);
            goto L_8042DCB4;
    }
    goto skip_0;
    // 0x8042DC9C: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x8042DCA0: jal         0x80064D1C
    // 0x8042DCA4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x8042DCA4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_2:
    // 0x8042DCA8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(53, 0X4B0) << 16);
    // 0x8042DCAC: sw          $v0, -0x1F30($at)
    MEM_W((int16_t)RELOC_LO16(53, 0X4B0), ctx->r1) = ctx->r2;
    // 0x8042DCB0: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
L_8042DCB4:
    // 0x8042DCB4: lui         $v1, 0x8043
    ctx->r3 = S32(RELOC_HI16(53, 0X4B0) << 16);
    // 0x8042DCB8: lui         $t1, 0x8043
    ctx->r9 = S32(RELOC_HI16(53, 0X3D8) << 16);
    // 0x8042DCBC: lw          $v1, -0x1F30($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(53, 0X4B0));
    // 0x8042DCC0: addiu       $t1, $t1, -0x2008
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(53, 0X3D8));
    // 0x8042DCC4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8042DCC8: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042DCCC: lui         $t4, 0x8043
    ctx->r12 = S32(RELOC_HI16(53, 0X3D8) << 16);
    // 0x8042DCD0: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(53, 0X3D8) << 16);
    // 0x8042DCD4: sw          $v1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r3;
    // 0x8042DCD8: lw          $t4, -0x2008($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(53, 0X3D8));
    // 0x8042DCDC: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042DCE0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(53, 0X3D8) << 16);
    // 0x8042DCE4: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8042DCE8: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8042DCEC: sw          $t6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r14;
    // 0x8042DCF0: lw          $t8, -0x2008($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(53, 0X3D8));
    // 0x8042DCF4: lui         $t0, 0x8043
    ctx->r8 = S32(RELOC_HI16(53, 0X3D8) << 16);
    // 0x8042DCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042DCFC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8042DD00: sw          $t9, -0x2008($at)
    MEM_W((int16_t)RELOC_LO16(53, 0X3D8), ctx->r1) = ctx->r25;
    // 0x8042DD04: slti        $at, $t9, 0x15
    ctx->r1 = SIGNED(ctx->r25) < 0X15 ? 1 : 0;
    // 0x8042DD08: bne         $at, $zero, L_8042DD20
    if (ctx->r1 != 0) {
        // 0x8042DD0C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8042DD20;
    }
    // 0x8042DD0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042DD10: jal         0x800445A4
    // 0x8042DD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x8042DD14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8042DD18: b           L_8042DD48
    // 0x8042DD1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042DD48;
    // 0x8042DD1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042DD20:
    // 0x8042DD20: lw          $t0, -0x2008($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(53, 0X3D8));
    // 0x8042DD24: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(53, 0X4B0) << 16);
    // 0x8042DD28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042DD2C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8042DD30: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x8042DD34: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x8042DD38: sw          $v1, -0x1F30($at)
    MEM_W((int16_t)RELOC_LO16(53, 0X4B0), ctx->r1) = ctx->r3;
    // 0x8042DD3C: jal         0x8042DF34
    // 0x8042DD40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042DF34(rdram, ctx);
        goto after_4;
    // 0x8042DD40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8042DD44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042DD48:
    // 0x8042DD48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042DD4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042DD50: jr          $ra
    // 0x8042DD54: nop

    return;
    // 0x8042DD54: nop

;}
RECOMP_FUNC void func_805314C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805314C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805314C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805314C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805314CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805314D0: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x805314D4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805314D8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x805314DC: bnel        $t6, $at, L_80531594
    if (ctx->r14 != ctx->r1) {
        // 0x805314E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80531594;
    }
    goto skip_0;
    // 0x805314E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805314E4: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x805314E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805314EC: bnel        $t7, $at, L_80531594
    if (ctx->r15 != ctx->r1) {
        // 0x805314F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80531594;
    }
    goto skip_1;
    // 0x805314F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805314F4: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x805314F8: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x805314FC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80531500: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x80531504: beql        $t0, $zero, L_80531594
    if (ctx->r8 == 0) {
        // 0x80531508: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80531594;
    }
    goto skip_2;
    // 0x80531508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8053150C: lh          $t1, -0x7680($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X7680);
    // 0x80531510: bgezl       $t1, L_80531594
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80531514: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80531594;
    }
    goto skip_3;
    // 0x80531514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80531518: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8053151C: lw          $t2, 0x12EC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X12EC);
    // 0x80531520: bnel        $t2, $zero, L_80531594
    if (ctx->r10 != 0) {
        // 0x80531524: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80531594;
    }
    goto skip_4;
    // 0x80531524: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80531528: lbu         $t3, 0xF4($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XF4);
    // 0x8053152C: bnel        $t3, $zero, L_80531594
    if (ctx->r11 != 0) {
        // 0x80531530: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80531594;
    }
    goto skip_5;
    // 0x80531530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80531534: lbu         $t4, 0x154($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X154);
    // 0x80531538: bnel        $t4, $zero, L_80531594
    if (ctx->r12 != 0) {
        // 0x8053153C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80531594;
    }
    goto skip_6;
    // 0x8053153C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80531540: lbu         $t5, 0x155($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X155);
    // 0x80531544: bnel        $t5, $zero, L_80531594
    if (ctx->r13 != 0) {
        // 0x80531548: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80531594;
    }
    goto skip_7;
    // 0x80531548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8053154C: lbu         $t6, 0x1F8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1F8);
    // 0x80531550: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80531554: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80531558: bne         $t6, $zero, L_80531590
    if (ctx->r14 != 0) {
        // 0x8053155C: addiu       $a3, $zero, 0x4
        ctx->r7 = ADD32(0, 0X4);
            goto L_80531590;
    }
    // 0x8053155C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80531560: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x80531564: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80531568: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8053156C: jal         0x8002F7AC
    // 0x80531570: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    func_8002F7AC(rdram, ctx);
        goto after_0;
    // 0x80531570: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_0:
    // 0x80531574: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80531578: jal         0x80531FB8
    // 0x8053157C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80531FB8(rdram, ctx);
        goto after_1;
    // 0x8053157C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80531580: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80531584: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80531588: jal         0x80531440
    // 0x8053158C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_80531440(rdram, ctx);
        goto after_2;
    // 0x8053158C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
L_80531590:
    // 0x80531590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80531594:
    // 0x80531594: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80531598: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8053159C: jr          $ra
    // 0x805315A0: nop

    return;
    // 0x805315A0: nop

;}
RECOMP_FUNC void func_805813B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805813B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805813B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805813BC: jal         0x80580C70
    // 0x805813C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580C70(rdram, ctx);
        goto after_0;
    // 0x805813C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805813C4: jal         0x8058121C
    // 0x805813C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8058121C(rdram, ctx);
        goto after_1;
    // 0x805813C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805813CC: jal         0x80581338
    // 0x805813D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80581338(rdram, ctx);
        goto after_2;
    // 0x805813D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x805813D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805813D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805813DC: jr          $ra
    // 0x805813E0: nop

    return;
    // 0x805813E0: nop

;}
RECOMP_FUNC void func_8079B954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079B954: jr          $ra
    // 0x8079B958: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    return;
    // 0x8079B958: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80065BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065BCC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80065BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065BD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065BD8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80065BDC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80065BE0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065BE4: jal         0x8006593C
    // 0x80065BE8: subu        $a0, $a0, $t7
    ctx->r4 = SUB32(ctx->r4, ctx->r15);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80065BE8: subu        $a0, $a0, $t7
    ctx->r4 = SUB32(ctx->r4, ctx->r15);
    after_0:
    // 0x80065BEC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80065BF0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80065BF4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80065BF8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80065BFC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80065C00: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x80065C04: slti        $v0, $v0, 0x0
    ctx->r2 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x80065C08: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80065C0C: beql        $v0, $zero, L_80065C38
    if (ctx->r2 == 0) {
        // 0x80065C10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80065C38;
    }
    goto skip_0;
    // 0x80065C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80065C14: jal         0x8006593C
    // 0x80065C18: subu        $a0, $t1, $t2
    ctx->r4 = SUB32(ctx->r9, ctx->r10);
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x80065C18: subu        $a0, $t1, $t2
    ctx->r4 = SUB32(ctx->r9, ctx->r10);
    after_1:
    // 0x80065C1C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80065C20: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80065C24: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80065C28: subu        $v0, $t5, $v0
    ctx->r2 = SUB32(ctx->r13, ctx->r2);
    // 0x80065C2C: slti        $v0, $v0, 0x0
    ctx->r2 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x80065C30: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80065C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80065C38:
    // 0x80065C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065C3C: jr          $ra
    // 0x80065C40: nop

    return;
    // 0x80065C40: nop

;}
RECOMP_FUNC void func_80020014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020014: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80020018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002001C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80020020: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80020024: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80020028: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002002C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80020030: bne         $v1, $zero, L_80020084
    if (ctx->r3 != 0) {
        // 0x80020034: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80020084;
    }
    // 0x80020034: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80020038: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x8002003C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80020040: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80020044: andi        $v0, $v0, 0x700
    ctx->r2 = ctx->r2 & 0X700;
    // 0x80020048: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x8002004C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80020050: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80020054: lw          $t7, -0x6568($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6568);
    // 0x80020058: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x8002005C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80020060: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80020064: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80020068: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002006C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80020070: lhu         $a2, 0x0($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X0);
    // 0x80020074: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80020078: jal         0x8004A9C4
    // 0x8002007C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8004A9C4(rdram, ctx);
        goto after_0;
    // 0x8002007C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80020080: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_80020084:
    // 0x80020084: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80020088: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002008C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80020090: jal         0x8001F2DC
    // 0x80020094: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8001F2DC(rdram, ctx);
        goto after_1;
    // 0x80020094: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x80020098: bne         $v0, $zero, L_800200A8
    if (ctx->r2 != 0) {
        // 0x8002009C: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_800200A8;
    }
    // 0x8002009C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800200A0: b           L_800202A0
    // 0x800200A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800202A0;
    // 0x800200A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800200A8:
    // 0x800200A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800200AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800200B0: jal         0x8001F478
    // 0x800200B4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8001F478(rdram, ctx);
        goto after_2;
    // 0x800200B4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x800200B8: bne         $v0, $zero, L_800200C8
    if (ctx->r2 != 0) {
        // 0x800200BC: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_800200C8;
    }
    // 0x800200BC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800200C0: b           L_800202A0
    // 0x800200C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800202A0;
    // 0x800200C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800200C8:
    // 0x800200C8: beq         $v1, $zero, L_800200E0
    if (ctx->r3 == 0) {
        // 0x800200CC: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_800200E0;
    }
    // 0x800200CC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800200D0: lhu         $t2, 0xC($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XC);
    // 0x800200D4: addiu       $at, $zero, 0x45BE
    ctx->r1 = ADD32(0, 0X45BE);
    // 0x800200D8: beql        $t2, $at, L_80020114
    if (ctx->r10 == ctx->r1) {
        // 0x800200DC: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80020114;
    }
    goto skip_0;
    // 0x800200DC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_800200E0:
    // 0x800200E0: lbu         $t4, 0x12($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X12);
    // 0x800200E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800200E8: beql        $t4, $zero, L_80020114
    if (ctx->r12 == 0) {
        // 0x800200EC: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80020114;
    }
    goto skip_1;
    // 0x800200EC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x800200F0: jal         0x8001FBE8
    // 0x800200F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001FBE8(rdram, ctx);
        goto after_3;
    // 0x800200F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800200F8: bne         $v0, $zero, L_80020108
    if (ctx->r2 != 0) {
        // 0x800200FC: nop
    
            goto L_80020108;
    }
    // 0x800200FC: nop

    // 0x80020100: b           L_800202A0
    // 0x80020104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800202A0;
    // 0x80020104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80020108:
    // 0x80020108: b           L_800202A0
    // 0x8002010C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800202A0;
    // 0x8002010C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80020110: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
L_80020114:
    // 0x80020114: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020118: lbu         $t6, 0x13($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X13);
    // 0x8002011C: beql        $t6, $zero, L_80020138
    if (ctx->r14 == 0) {
        // 0x80020120: lw          $t7, 0x2C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X2C);
            goto L_80020138;
    }
    goto skip_2;
    // 0x80020120: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    skip_2:
    // 0x80020124: jal         0x8001FD40
    // 0x80020128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001FD40(rdram, ctx);
        goto after_4;
    // 0x80020128: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8002012C: b           L_800202A0
    // 0x80020130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800202A0;
    // 0x80020130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80020134: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
L_80020138:
    // 0x80020138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002013C: andi        $t9, $t7, 0x700
    ctx->r25 = ctx->r15 & 0X700;
    // 0x80020140: beql        $t9, $zero, L_80020164
    if (ctx->r25 == 0) {
        // 0x80020144: lw          $t8, 0x38($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X38);
            goto L_80020164;
    }
    goto skip_3;
    // 0x80020144: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    skip_3:
    // 0x80020148: jal         0x8001FA34
    // 0x8002014C: sw          $zero, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = 0;
    func_8001FA34(rdram, ctx);
        goto after_5;
    // 0x8002014C: sw          $zero, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = 0;
    after_5:
    // 0x80020150: bnel        $v0, $zero, L_80020270
    if (ctx->r2 != 0) {
        // 0x80020154: lw          $t8, 0x2C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X2C);
            goto L_80020270;
    }
    goto skip_4;
    // 0x80020154: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    skip_4:
    // 0x80020158: b           L_800202A0
    // 0x8002015C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800202A0;
    // 0x8002015C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80020160: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
L_80020164:
    // 0x80020164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020168: andi        $t0, $t8, 0x700
    ctx->r8 = ctx->r24 & 0X700;
    // 0x8002016C: beql        $t0, $zero, L_80020190
    if (ctx->r8 == 0) {
        // 0x80020170: lbu         $v0, 0x30($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X30);
            goto L_80020190;
    }
    goto skip_5;
    // 0x80020170: lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X30);
    skip_5:
    // 0x80020174: jal         0x8001FB1C
    // 0x80020178: sw          $zero, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = 0;
    func_8001FB1C(rdram, ctx);
        goto after_6;
    // 0x80020178: sw          $zero, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = 0;
    after_6:
    // 0x8002017C: bnel        $v0, $zero, L_80020270
    if (ctx->r2 != 0) {
        // 0x80020180: lw          $t8, 0x2C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X2C);
            goto L_80020270;
    }
    goto skip_6;
    // 0x80020180: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    skip_6:
    // 0x80020184: b           L_800202A0
    // 0x80020188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800202A0;
    // 0x80020188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002018C: lbu         $v0, 0x30($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X30);
L_80020190:
    // 0x80020190: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80020194: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80020198: beq         $v0, $at, L_800201D0
    if (ctx->r2 == ctx->r1) {
        // 0x8002019C: addiu       $at, $zero, 0x21
        ctx->r1 = ADD32(0, 0X21);
            goto L_800201D0;
    }
    // 0x8002019C: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x800201A0: beql        $v0, $at, L_800201D4
    if (ctx->r2 == ctx->r1) {
        // 0x800201A4: sw          $zero, 0xFC($s0)
        MEM_W(0XFC, ctx->r16) = 0;
            goto L_800201D4;
    }
    goto skip_7;
    // 0x800201A4: sw          $zero, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = 0;
    skip_7:
    // 0x800201A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800201AC: lwc1        $f6, 0xC8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x800201B0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800201B4: nop

    // 0x800201B8: bc1fl       L_800201D4
    if (!c1cs) {
        // 0x800201BC: sw          $zero, 0xFC($s0)
        MEM_W(0XFC, ctx->r16) = 0;
            goto L_800201D4;
    }
    goto skip_8;
    // 0x800201BC: sw          $zero, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = 0;
    skip_8:
    // 0x800201C0: lw          $t1, 0xFC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XFC);
    // 0x800201C4: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800201C8: b           L_800201D4
    // 0x800201CC: sw          $t2, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->r10;
        goto L_800201D4;
    // 0x800201CC: sw          $t2, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->r10;
L_800201D0:
    // 0x800201D0: sw          $zero, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = 0;
L_800201D4:
    // 0x800201D4: lwc1        $f10, 0xC8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x800201D8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800201DC: nop

    // 0x800201E0: bc1fl       L_80020204
    if (!c1cs) {
        // 0x800201E4: lw          $t3, 0x2C($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X2C);
            goto L_80020204;
    }
    goto skip_9;
    // 0x800201E4: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    skip_9:
    // 0x800201E8: jal         0x8001FD9C
    // 0x800201EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001FD9C(rdram, ctx);
        goto after_7;
    // 0x800201EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800201F0: bnel        $v0, $zero, L_80020270
    if (ctx->r2 != 0) {
        // 0x800201F4: lw          $t8, 0x2C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X2C);
            goto L_80020270;
    }
    goto skip_10;
    // 0x800201F4: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    skip_10:
    // 0x800201F8: b           L_800202A0
    // 0x800201FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800202A0;
    // 0x800201FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80020200: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
L_80020204:
    // 0x80020204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020208: andi        $t4, $t3, 0x3000
    ctx->r12 = ctx->r11 & 0X3000;
    // 0x8002020C: bne         $t4, $zero, L_80020224
    if (ctx->r12 != 0) {
        // 0x80020210: nop
    
            goto L_80020224;
    }
    // 0x80020210: nop

    // 0x80020214: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x80020218: andi        $t6, $t5, 0x3000
    ctx->r14 = ctx->r13 & 0X3000;
    // 0x8002021C: beql        $t6, $zero, L_80020240
    if (ctx->r14 == 0) {
        // 0x80020220: lbu         $t7, 0x30($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X30);
            goto L_80020240;
    }
    goto skip_11;
    // 0x80020220: lbu         $t7, 0x30($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X30);
    skip_11:
L_80020224:
    // 0x80020224: jal         0x8001FDE8
    // 0x80020228: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001FDE8(rdram, ctx);
        goto after_8;
    // 0x80020228: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x8002022C: bnel        $v0, $zero, L_80020270
    if (ctx->r2 != 0) {
        // 0x80020230: lw          $t8, 0x2C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X2C);
            goto L_80020270;
    }
    goto skip_12;
    // 0x80020230: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    skip_12:
    // 0x80020234: b           L_800202A0
    // 0x80020238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800202A0;
    // 0x80020238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002023C: lbu         $t7, 0x30($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X30);
L_80020240:
    // 0x80020240: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80020244: bnel        $t7, $at, L_80020270
    if (ctx->r15 != ctx->r1) {
        // 0x80020248: lw          $t8, 0x2C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X2C);
            goto L_80020270;
    }
    goto skip_13;
    // 0x80020248: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    skip_13:
    // 0x8002024C: jal         0x8001FD9C
    // 0x80020250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001FD9C(rdram, ctx);
        goto after_9;
    // 0x80020250: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80020254: bne         $v0, $zero, L_8002026C
    if (ctx->r2 != 0) {
        // 0x80020258: lui         $t9, 0x8002
        ctx->r25 = S32(0X8002 << 16);
            goto L_8002026C;
    }
    // 0x80020258: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x8002025C: addiu       $t9, $t9, 0x33B4
    ctx->r25 = ADD32(ctx->r25, 0X33B4);
    // 0x80020260: sw          $t9, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->r25;
    // 0x80020264: b           L_800202A0
    // 0x80020268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800202A0;
    // 0x80020268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002026C:
    // 0x8002026C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
L_80020270:
    // 0x80020270: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80020274: srl         $t0, $t8, 28
    ctx->r8 = S32(U32(ctx->r24) >> 28);
    // 0x80020278: bne         $t0, $zero, L_80020290
    if (ctx->r8 != 0) {
        // 0x8002027C: nop
    
            goto L_80020290;
    }
    // 0x8002027C: nop

    // 0x80020280: lw          $t1, 0x38($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X38);
    // 0x80020284: and         $t2, $t1, $v0
    ctx->r10 = ctx->r9 & ctx->r2;
    // 0x80020288: beq         $t2, $zero, L_800202A0
    if (ctx->r10 == 0) {
        // 0x8002028C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800202A0;
    }
    // 0x8002028C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80020290:
    // 0x80020290: jal         0x8001FF18
    // 0x80020294: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001FF18(rdram, ctx);
        goto after_10;
    // 0x80020294: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80020298: b           L_800202A4
    // 0x8002029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800202A4;
    // 0x8002029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800202A0:
    // 0x800202A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800202A4:
    // 0x800202A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800202A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800202AC: jr          $ra
    // 0x800202B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800202B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804D015C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D015C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804D0160: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804D0164: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804D0168: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804D016C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804D0170: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804D0174: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804D0178: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804D017C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804D0180: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804D0184: jr          $ra
    // 0x804D0188: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804D0188: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x804D018C: nop

;}
RECOMP_FUNC void func_806F2AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2AA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2AAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2AB0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806F2AB4: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(679, 0X1B84) << 16);
    // 0x806F2AB8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806F2ABC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F2AC0: addiu       $t6, $t6, 0x3104
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(679, 0X1B84));
    // 0x806F2AC4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806F2AC8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806F2ACC: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x806F2AD0: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x806F2AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F2AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F2ADC: jal         0x806F2AF4
    // 0x806F2AE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F2AF4(rdram, ctx);
        goto after_0;
    // 0x806F2AE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x806F2AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F2AEC: jr          $ra
    // 0x806F2AF0: nop

    return;
    // 0x806F2AF0: nop

;}
RECOMP_FUNC void func_800042C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800042C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800042C8: lwc1        $f0, -0x4418($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X4418);
    // 0x800042CC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800042D0: addiu       $a0, $sp, 0x14
    ctx->r4 = ADD32(ctx->r29, 0X14);
    // 0x800042D4: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800042D8: addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
    // 0x800042DC: addiu       $v1, $a2, 0x4
    ctx->r3 = ADD32(ctx->r6, 0X4);
    // 0x800042E0: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800042E4: nop

    // 0x800042E8: mul.s       $f8, $f14, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800042EC: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x800042F0: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800042F4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800042F8: nop

    // 0x800042FC: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80004300: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80004304: add.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x80004308: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8000430C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
L_80004310:
    // 0x80004310: lwc1        $f6, -0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, -0X4);
    // 0x80004314: lwc1        $f10, -0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X8);
    // 0x80004318: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000431C: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80004320: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80004324: mul.s       $f16, $f14, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80004328: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8000432C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80004330: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80004334: nop

    // 0x80004338: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000433C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80004340: nop

    // 0x80004344: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80004348: beql        $t7, $zero, L_80004398
    if (ctx->r15 == 0) {
        // 0x8000434C: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_80004398;
    }
    goto skip_0;
    // 0x8000434C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80004350: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004354: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80004358: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000435C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80004360: nop

    // 0x80004364: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80004368: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000436C: nop

    // 0x80004370: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80004374: bne         $t7, $zero, L_8000438C
    if (ctx->r15 != 0) {
        // 0x80004378: nop
    
            goto L_8000438C;
    }
    // 0x80004378: nop

    // 0x8000437C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80004380: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004384: b           L_800043A4
    // 0x80004388: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800043A4;
    // 0x80004388: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8000438C:
    // 0x8000438C: b           L_800043A4
    // 0x80004390: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800043A4;
    // 0x80004390: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80004394: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_80004398:
    // 0x80004398: nop

    // 0x8000439C: bltz        $t7, L_8000438C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800043A0: nop
    
            goto L_8000438C;
    }
    // 0x800043A0: nop

L_800043A4:
    // 0x800043A4: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x800043A8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800043AC: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800043B0: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800043B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800043B8: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800043BC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800043C0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800043C4: mul.s       $f16, $f14, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800043C8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800043CC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800043D0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800043D4: nop

    // 0x800043D8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800043DC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800043E0: nop

    // 0x800043E4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800043E8: beql        $t9, $zero, L_80004438
    if (ctx->r25 == 0) {
        // 0x800043EC: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_80004438;
    }
    goto skip_1;
    // 0x800043EC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x800043F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800043F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800043F8: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800043FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80004400: nop

    // 0x80004404: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80004408: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000440C: nop

    // 0x80004410: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80004414: bne         $t9, $zero, L_8000442C
    if (ctx->r25 != 0) {
        // 0x80004418: nop
    
            goto L_8000442C;
    }
    // 0x80004418: nop

    // 0x8000441C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80004420: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004424: b           L_80004444
    // 0x80004428: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80004444;
    // 0x80004428: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8000442C:
    // 0x8000442C: b           L_80004444
    // 0x80004430: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80004444;
    // 0x80004430: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80004434: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_80004438:
    // 0x80004438: nop

    // 0x8000443C: bltz        $t9, L_8000442C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80004440: nop
    
            goto L_8000442C;
    }
    // 0x80004440: nop

L_80004444:
    // 0x80004444: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80004448: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000444C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80004450: bne         $at, $zero, L_80004310
    if (ctx->r1 != 0) {
        // 0x80004454: sh          $t9, 0xE($v1)
        MEM_H(0XE, ctx->r3) = ctx->r25;
            goto L_80004310;
    }
    // 0x80004454: sh          $t9, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r25;
    // 0x80004458: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8000445C: addiu       $a0, $sp, 0xC
    ctx->r4 = ADD32(ctx->r29, 0XC);
    // 0x80004460: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
L_80004464:
    // 0x80004464: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80004468: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000446C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80004470: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80004474: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80004478: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000447C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80004480: nop

    // 0x80004484: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80004488: beql        $t1, $zero, L_800044D8
    if (ctx->r9 == 0) {
        // 0x8000448C: mfc1        $t1, $f8
        ctx->r9 = (int32_t)ctx->f8.u32l;
            goto L_800044D8;
    }
    goto skip_2;
    // 0x8000448C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x80004490: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80004494: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80004498: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8000449C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800044A0: nop

    // 0x800044A4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800044A8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800044AC: nop

    // 0x800044B0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800044B4: bne         $t1, $zero, L_800044CC
    if (ctx->r9 != 0) {
        // 0x800044B8: nop
    
            goto L_800044CC;
    }
    // 0x800044B8: nop

    // 0x800044BC: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800044C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800044C4: b           L_800044E4
    // 0x800044C8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800044E4;
    // 0x800044C8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800044CC:
    // 0x800044CC: b           L_800044E4
    // 0x800044D0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800044E4;
    // 0x800044D0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800044D4: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
L_800044D8:
    // 0x800044D8: nop

    // 0x800044DC: bltz        $t1, L_800044CC
    if (SIGNED(ctx->r9) < 0) {
        // 0x800044E0: nop
    
            goto L_800044CC;
    }
    // 0x800044E0: nop

L_800044E4:
    // 0x800044E4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800044E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800044EC: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x800044F0: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800044F4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800044F8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800044FC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80004500: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80004504: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80004508: nop

    // 0x8000450C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80004510: beql        $t3, $zero, L_80004560
    if (ctx->r11 == 0) {
        // 0x80004514: mfc1        $t3, $f16
        ctx->r11 = (int32_t)ctx->f16.u32l;
            goto L_80004560;
    }
    goto skip_3;
    // 0x80004514: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x80004518: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000451C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80004520: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80004524: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80004528: nop

    // 0x8000452C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80004530: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80004534: nop

    // 0x80004538: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8000453C: bne         $t3, $zero, L_80004554
    if (ctx->r11 != 0) {
        // 0x80004540: nop
    
            goto L_80004554;
    }
    // 0x80004540: nop

    // 0x80004544: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80004548: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000454C: b           L_8000456C
    // 0x80004550: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8000456C;
    // 0x80004550: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80004554:
    // 0x80004554: b           L_8000456C
    // 0x80004558: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8000456C;
    // 0x80004558: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8000455C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
L_80004560:
    // 0x80004560: nop

    // 0x80004564: bltz        $t3, L_80004554
    if (SIGNED(ctx->r11) < 0) {
        // 0x80004568: nop
    
            goto L_80004554;
    }
    // 0x80004568: nop

L_8000456C:
    // 0x8000456C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80004570: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
    // 0x80004574: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80004578: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000457C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80004580: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80004584: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80004588: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000458C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80004590: nop

    // 0x80004594: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80004598: beql        $t5, $zero, L_800045E8
    if (ctx->r13 == 0) {
        // 0x8000459C: mfc1        $t5, $f4
        ctx->r13 = (int32_t)ctx->f4.u32l;
            goto L_800045E8;
    }
    goto skip_4;
    // 0x8000459C: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x800045A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800045A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800045A8: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800045AC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800045B0: nop

    // 0x800045B4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800045B8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800045BC: nop

    // 0x800045C0: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800045C4: bne         $t5, $zero, L_800045DC
    if (ctx->r13 != 0) {
        // 0x800045C8: nop
    
            goto L_800045DC;
    }
    // 0x800045C8: nop

    // 0x800045CC: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800045D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800045D4: b           L_800045F4
    // 0x800045D8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800045F4;
    // 0x800045D8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800045DC:
    // 0x800045DC: b           L_800045F4
    // 0x800045E0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800045F4;
    // 0x800045E0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800045E4: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
L_800045E8:
    // 0x800045E8: nop

    // 0x800045EC: bltz        $t5, L_800045DC
    if (SIGNED(ctx->r13) < 0) {
        // 0x800045F0: nop
    
            goto L_800045DC;
    }
    // 0x800045F0: nop

L_800045F4:
    // 0x800045F4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800045F8: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
    // 0x800045FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80004600: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80004604: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80004608: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000460C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80004610: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80004614: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80004618: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000461C: nop

    // 0x80004620: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80004624: beql        $t7, $zero, L_80004674
    if (ctx->r15 == 0) {
        // 0x80004628: mfc1        $t7, $f8
        ctx->r15 = (int32_t)ctx->f8.u32l;
            goto L_80004674;
    }
    goto skip_5;
    // 0x80004628: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    skip_5:
    // 0x8000462C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80004630: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80004634: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80004638: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000463C: nop

    // 0x80004640: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80004644: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80004648: nop

    // 0x8000464C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80004650: bne         $t7, $zero, L_80004668
    if (ctx->r15 != 0) {
        // 0x80004654: nop
    
            goto L_80004668;
    }
    // 0x80004654: nop

    // 0x80004658: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8000465C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004660: b           L_80004680
    // 0x80004664: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80004680;
    // 0x80004664: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80004668:
    // 0x80004668: b           L_80004680
    // 0x8000466C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80004680;
    // 0x8000466C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80004670: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
L_80004674:
    // 0x80004674: nop

    // 0x80004678: bltz        $t7, L_80004668
    if (SIGNED(ctx->r15) < 0) {
        // 0x8000467C: nop
    
            goto L_80004668;
    }
    // 0x8000467C: nop

L_80004680:
    // 0x80004680: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80004684: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x80004688: bne         $a0, $v0, L_80004464
    if (ctx->r4 != ctx->r2) {
        // 0x8000468C: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80004464;
    }
    // 0x8000468C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80004690: jr          $ra
    // 0x80004694: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80004694: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_806FA600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FA600: jr          $ra
    // 0x806FA604: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806FA604: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805A3830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3830: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A3834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A3838: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A383C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x805A3840: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805A3844: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x805A3848: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x805A384C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x805A3850: jal         0x805A50B0
    // 0x805A3854: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    func_805A50B0(rdram, ctx);
        goto after_0;
    // 0x805A3854: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x805A3858: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x805A385C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x805A3860: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x805A3864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A3868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A386C: jr          $ra
    // 0x805A3870: nop

    return;
    // 0x805A3870: nop

;}
RECOMP_FUNC void func_804B9750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B9750: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B9754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B9758: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804B975C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804B9760: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x804B9764: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x804B9768: addiu       $t7, $v0, 0x190
    ctx->r15 = ADD32(ctx->r2, 0X190);
    // 0x804B976C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x804B9770: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x804B9774: jal         0x804B94D4
    // 0x804B9778: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_804B94D4(rdram, ctx);
        goto after_0;
    // 0x804B9778: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x804B977C: jal         0x804B94F4
    // 0x804B9780: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_804B94F4(rdram, ctx);
        goto after_1;
    // 0x804B9780: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x804B9784: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804B9788: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804B978C: sw          $t8, 0x320($v0)
    MEM_W(0X320, ctx->r2) = ctx->r24;
    // 0x804B9790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B9794: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B9798: jr          $ra
    // 0x804B979C: nop

    return;
    // 0x804B979C: nop

;}
RECOMP_FUNC void func_806F02A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F02A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F02A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F02A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F02AC: jal         0x806F01BC
    // 0x806F02B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806F01BC(rdram, ctx);
        goto after_0;
    // 0x806F02B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806F02B4: bne         $v0, $zero, L_806F02CC
    if (ctx->r2 != 0) {
        // 0x806F02B8: lui         $at, 0x41A8
        ctx->r1 = S32(0X41A8 << 16);
            goto L_806F02CC;
    }
    // 0x806F02B8: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x806F02BC: jal         0x800447C8
    // 0x806F02C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806F02C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F02C4: b           L_806F0338
    // 0x806F02C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F0338;
    // 0x806F02C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F02CC:
    // 0x806F02CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F02D0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806F02D4: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806F02D8: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x806F02DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F02E0: jal         0x806EC234
    // 0x806F02E4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_806EC234(rdram, ctx);
        goto after_2;
    // 0x806F02E4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x806F02E8: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x806F02EC: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(676, 0X4BF4) << 16);
    // 0x806F02F0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806F02F4: addiu       $t7, $t7, 0xB44
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(676, 0X4BF4));
    // 0x806F02F8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806F02FC: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806F0300: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806F0304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F0308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F030C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F0310: jal         0x806F0348
    // 0x806F0314: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F0348(rdram, ctx);
        goto after_3;
    // 0x806F0314: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x806F0318: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x806F031C: sh          $t9, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r25;
    // 0x806F0320: jal         0x806EC0CC
    // 0x806F0324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC0CC(rdram, ctx);
        goto after_4;
    // 0x806F0324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806F0328: lui         $t0, 0x806F
    ctx->r8 = S32(RELOC_HI16(676, 0X2BC) << 16);
    // 0x806F032C: addiu       $t0, $t0, -0x3DF4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(676, 0X2BC));
    // 0x806F0330: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x806F0334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F0338:
    // 0x806F0338: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F033C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F0340: jr          $ra
    // 0x806F0344: nop

    return;
    // 0x806F0344: nop

;}
RECOMP_FUNC void func_8078F510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F510: addiu       $t6, $zero, 0x190
    ctx->r14 = ADD32(0, 0X190);
    // 0x8078F514: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8078F518: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8078F51C: jr          $ra
    // 0x8078F520: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    return;
    // 0x8078F520: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80044658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004465C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044660: bne         $a0, $zero, L_80044680
    if (ctx->r4 != 0) {
        // 0x80044664: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80044680;
    }
    // 0x80044664: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80044668: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004466C: addiu       $a0, $a0, 0x4E0
    ctx->r4 = ADD32(ctx->r4, 0X4E0);
    // 0x80044670: jal         0x80071380
    // 0x80044674: addiu       $a1, $zero, 0x500
    ctx->r5 = ADD32(0, 0X500);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80044674: addiu       $a1, $zero, 0x500
    ctx->r5 = ADD32(0, 0X500);
    after_0:
    // 0x80044678: b           L_800447B8
    // 0x8004467C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800447B8;
    // 0x8004467C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80044680:
    // 0x80044680: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80044684: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80044688: beq         $t7, $zero, L_800446A4
    if (ctx->r15 == 0) {
        // 0x8004468C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800446A4;
    }
    // 0x8004468C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044690: addiu       $a0, $a0, 0x4F0
    ctx->r4 = ADD32(ctx->r4, 0X4F0);
    // 0x80044694: jal         0x80071380
    // 0x80044698: addiu       $a1, $zero, 0x508
    ctx->r5 = ADD32(0, 0X508);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80044698: addiu       $a1, $zero, 0x508
    ctx->r5 = ADD32(0, 0X508);
    after_1:
    // 0x8004469C: b           L_800447B8
    // 0x800446A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800447B8;
    // 0x800446A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800446A4:
    // 0x800446A4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800446A8: lui         $at, 0x1997
    ctx->r1 = S32(0X1997 << 16);
    // 0x800446AC: ori         $at, $at, 0x1110
    ctx->r1 = ctx->r1 | 0X1110;
    // 0x800446B0: beq         $t8, $at, L_800446CC
    if (ctx->r24 == ctx->r1) {
        // 0x800446B4: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800446CC;
    }
    // 0x800446B4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800446B8: addiu       $a0, $a0, 0x500
    ctx->r4 = ADD32(ctx->r4, 0X500);
    // 0x800446BC: jal         0x80071380
    // 0x800446C0: addiu       $a1, $zero, 0x511
    ctx->r5 = ADD32(0, 0X511);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x800446C0: addiu       $a1, $zero, 0x511
    ctx->r5 = ADD32(0, 0X511);
    after_2:
    // 0x800446C4: b           L_800447B8
    // 0x800446C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800447B8;
    // 0x800446C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800446CC:
    // 0x800446CC: lbu         $v0, 0x17D($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X17D);
    // 0x800446D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800446D4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800446D8: bne         $v1, $v0, L_800446F4
    if (ctx->r3 != ctx->r2) {
        // 0x800446DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800446F4;
    }
    // 0x800446DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800446E0: addiu       $a0, $a0, 0x510
    ctx->r4 = ADD32(ctx->r4, 0X510);
    // 0x800446E4: jal         0x80071380
    // 0x800446E8: addiu       $a1, $zero, 0x51A
    ctx->r5 = ADD32(0, 0X51A);
    Fault_HungUp(rdram, ctx);
        goto after_3;
    // 0x800446E8: addiu       $a1, $zero, 0x51A
    ctx->r5 = ADD32(0, 0X51A);
    after_3:
    // 0x800446EC: b           L_800447B8
    // 0x800446F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800447B8;
    // 0x800446F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800446F4:
    // 0x800446F4: bne         $v0, $at, L_80044710
    if (ctx->r2 != ctx->r1) {
        // 0x800446F8: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80044710;
    }
    // 0x800446F8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800446FC: addiu       $a0, $a0, 0x520
    ctx->r4 = ADD32(ctx->r4, 0X520);
    // 0x80044700: jal         0x80071380
    // 0x80044704: addiu       $a1, $zero, 0x52C
    ctx->r5 = ADD32(0, 0X52C);
    Fault_HungUp(rdram, ctx);
        goto after_4;
    // 0x80044704: addiu       $a1, $zero, 0x52C
    ctx->r5 = ADD32(0, 0X52C);
    after_4:
    // 0x80044708: b           L_800447B8
    // 0x8004470C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800447B8;
    // 0x8004470C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80044710:
    // 0x80044710: lbu         $t9, 0x4($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X4);
    // 0x80044714: bnel        $v1, $t9, L_80044728
    if (ctx->r3 != ctx->r25) {
        // 0x80044718: lw          $t0, 0x180($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X180);
            goto L_80044728;
    }
    goto skip_0;
    // 0x80044718: lw          $t0, 0x180($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X180);
    skip_0:
    // 0x8004471C: b           L_800447B8
    // 0x80044720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800447B8;
    // 0x80044720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80044724: lw          $t0, 0x180($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X180);
L_80044728:
    // 0x80044728: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8004472C: beql        $t0, $zero, L_80044748
    if (ctx->r8 == 0) {
        // 0x80044730: lh          $t1, 0x17E($a1)
        ctx->r9 = MEM_H(ctx->r5, 0X17E);
            goto L_80044748;
    }
    goto skip_1;
    // 0x80044730: lh          $t1, 0x17E($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X17E);
    skip_1:
    // 0x80044734: jal         0x80048060
    // 0x80044738: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80048060(rdram, ctx);
        goto after_5;
    // 0x80044738: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_5:
    // 0x8004473C: b           L_80044764
    // 0x80044740: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
        goto L_80044764;
    // 0x80044740: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80044744: lh          $t1, 0x17E($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X17E);
L_80044748:
    // 0x80044748: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x8004474C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80044750: beql        $t1, $at, L_80044768
    if (ctx->r9 == ctx->r1) {
        // 0x80044754: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80044768;
    }
    goto skip_2;
    // 0x80044754: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_2:
    // 0x80044758: jal         0x8004457C
    // 0x8004475C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8004457C(rdram, ctx);
        goto after_6;
    // 0x8004475C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_6:
    // 0x80044760: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_80044764:
    // 0x80044764: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80044768:
    // 0x80044768: jal         0x8005FE48
    // 0x8004476C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8005FE48(rdram, ctx);
        goto after_7;
    // 0x8004476C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_7:
    // 0x80044770: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80044774: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80044778: jal         0x80043D34
    // 0x8004477C: addiu       $a0, $a0, -0x77AC
    ctx->r4 = ADD32(ctx->r4, -0X77AC);
    func_80043D34(rdram, ctx);
        goto after_8;
    // 0x8004477C: addiu       $a0, $a0, -0x77AC
    ctx->r4 = ADD32(ctx->r4, -0X77AC);
    after_8:
    // 0x80044780: bne         $v0, $zero, L_800447A0
    if (ctx->r2 != 0) {
        // 0x80044784: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_800447A0;
    }
    // 0x80044784: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80044788: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004478C: addiu       $a0, $a0, 0x530
    ctx->r4 = ADD32(ctx->r4, 0X530);
    // 0x80044790: jal         0x80071380
    // 0x80044794: addiu       $a1, $zero, 0x540
    ctx->r5 = ADD32(0, 0X540);
    Fault_HungUp(rdram, ctx);
        goto after_9;
    // 0x80044794: addiu       $a1, $zero, 0x540
    ctx->r5 = ADD32(0, 0X540);
    after_9:
    // 0x80044798: b           L_800447B8
    // 0x8004479C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800447B8;
    // 0x8004479C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800447A0:
    // 0x800447A0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800447A4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800447A8: sb          $t2, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r10;
    // 0x800447AC: sb          $v1, 0x28($a1)
    MEM_B(0X28, ctx->r5) = ctx->r3;
    // 0x800447B0: sb          $v1, 0x17D($a1)
    MEM_B(0X17D, ctx->r5) = ctx->r3;
    // 0x800447B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800447B8:
    // 0x800447B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800447BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800447C0: jr          $ra
    // 0x800447C4: nop

    return;
    // 0x800447C4: nop

;}
RECOMP_FUNC void func_80001228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001228: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000122C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80001230: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80001234: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80001238: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x8000123C: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80001240: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80001244: jr          $ra
    // 0x80001248: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    return;
    // 0x80001248: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_805824D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805824D8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x805824DC: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x805824E0: div         $zero, $a1, $at
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r1)));
    // 0x805824E4: mfhi        $a1
    ctx->r5 = hi;
    // 0x805824E8: addiu       $a2, $zero, 0x2710
    ctx->r6 = ADD32(0, 0X2710);
    // 0x805824EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805824F0: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x805824F4: mflo        $v1
    ctx->r3 = lo;
    // 0x805824F8: addiu       $t6, $v1, 0x10
    ctx->r14 = ADD32(ctx->r3, 0X10);
    // 0x805824FC: bne         $a2, $zero, L_80582508
    if (ctx->r6 != 0) {
        // 0x80582500: nop
    
            goto L_80582508;
    }
    // 0x80582500: nop

    // 0x80582504: break       7
    do_break(2153260292);
L_80582508:
    // 0x80582508: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8058250C: bne         $a2, $at, L_80582520
    if (ctx->r6 != ctx->r1) {
        // 0x80582510: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80582520;
    }
    // 0x80582510: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80582514: bne         $a1, $at, L_80582520
    if (ctx->r5 != ctx->r1) {
        // 0x80582518: nop
    
            goto L_80582520;
    }
    // 0x80582518: nop

    // 0x8058251C: break       6
    do_break(2153260316);
L_80582520:
    // 0x80582520: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x80582524: beq         $v1, $zero, L_80582534
    if (ctx->r3 == 0) {
        // 0x80582528: addiu       $a3, $zero, 0x3E8
        ctx->r7 = ADD32(0, 0X3E8);
            goto L_80582534;
    }
    // 0x80582528: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x8058252C: b           L_80582538
    // 0x80582530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80582538;
    // 0x80582530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80582534:
    // 0x80582534: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
L_80582538:
    // 0x80582538: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x8058253C: bne         $a2, $zero, L_80582548
    if (ctx->r6 != 0) {
        // 0x80582540: nop
    
            goto L_80582548;
    }
    // 0x80582540: nop

    // 0x80582544: break       7
    do_break(2153260356);
L_80582548:
    // 0x80582548: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8058254C: bne         $a2, $at, L_80582560
    if (ctx->r6 != ctx->r1) {
        // 0x80582550: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80582560;
    }
    // 0x80582550: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80582554: bne         $a1, $at, L_80582560
    if (ctx->r5 != ctx->r1) {
        // 0x80582558: nop
    
            goto L_80582560;
    }
    // 0x80582558: nop

    // 0x8058255C: break       6
    do_break(2153260380);
L_80582560:
    // 0x80582560: mfhi        $a1
    ctx->r5 = hi;
    // 0x80582564: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80582568: nop

    // 0x8058256C: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x80582570: mflo        $v1
    ctx->r3 = lo;
    // 0x80582574: addiu       $t7, $v1, 0x10
    ctx->r15 = ADD32(ctx->r3, 0X10);
    // 0x80582578: bne         $a3, $zero, L_80582584
    if (ctx->r7 != 0) {
        // 0x8058257C: nop
    
            goto L_80582584;
    }
    // 0x8058257C: nop

    // 0x80582580: break       7
    do_break(2153260416);
L_80582584:
    // 0x80582584: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80582588: bne         $a3, $at, L_8058259C
    if (ctx->r7 != ctx->r1) {
        // 0x8058258C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8058259C;
    }
    // 0x8058258C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80582590: bne         $a1, $at, L_8058259C
    if (ctx->r5 != ctx->r1) {
        // 0x80582594: nop
    
            goto L_8058259C;
    }
    // 0x80582594: nop

    // 0x80582598: break       6
    do_break(2153260440);
L_8058259C:
    // 0x8058259C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x805825A0: beq         $v1, $zero, L_805825B0
    if (ctx->r3 == 0) {
        // 0x805825A4: nop
    
            goto L_805825B0;
    }
    // 0x805825A4: nop

    // 0x805825A8: b           L_805825BC
    // 0x805825AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805825BC;
    // 0x805825AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805825B0:
    // 0x805825B0: beq         $v0, $zero, L_805825BC
    if (ctx->r2 == 0) {
        // 0x805825B4: nop
    
            goto L_805825BC;
    }
    // 0x805825B4: nop

    // 0x805825B8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
L_805825BC:
    // 0x805825BC: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x805825C0: bne         $a3, $zero, L_805825CC
    if (ctx->r7 != 0) {
        // 0x805825C4: nop
    
            goto L_805825CC;
    }
    // 0x805825C4: nop

    // 0x805825C8: break       7
    do_break(2153260488);
L_805825CC:
    // 0x805825CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805825D0: bne         $a3, $at, L_805825E4
    if (ctx->r7 != ctx->r1) {
        // 0x805825D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805825E4;
    }
    // 0x805825D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805825D8: bne         $a1, $at, L_805825E4
    if (ctx->r5 != ctx->r1) {
        // 0x805825DC: nop
    
            goto L_805825E4;
    }
    // 0x805825DC: nop

    // 0x805825E0: break       6
    do_break(2153260512);
L_805825E4:
    // 0x805825E4: mfhi        $a1
    ctx->r5 = hi;
    // 0x805825E8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x805825EC: nop

    // 0x805825F0: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x805825F4: mflo        $v1
    ctx->r3 = lo;
    // 0x805825F8: addiu       $t8, $v1, 0x10
    ctx->r24 = ADD32(ctx->r3, 0X10);
    // 0x805825FC: bne         $a2, $zero, L_80582608
    if (ctx->r6 != 0) {
        // 0x80582600: nop
    
            goto L_80582608;
    }
    // 0x80582600: nop

    // 0x80582604: break       7
    do_break(2153260548);
L_80582608:
    // 0x80582608: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8058260C: bne         $a2, $at, L_80582620
    if (ctx->r6 != ctx->r1) {
        // 0x80582610: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80582620;
    }
    // 0x80582610: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80582614: bne         $a1, $at, L_80582620
    if (ctx->r5 != ctx->r1) {
        // 0x80582618: nop
    
            goto L_80582620;
    }
    // 0x80582618: nop

    // 0x8058261C: break       6
    do_break(2153260572);
L_80582620:
    // 0x80582620: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x80582624: beq         $v1, $zero, L_80582634
    if (ctx->r3 == 0) {
        // 0x80582628: nop
    
            goto L_80582634;
    }
    // 0x80582628: nop

    // 0x8058262C: b           L_80582640
    // 0x80582630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80582640;
    // 0x80582630: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80582634:
    // 0x80582634: beq         $v0, $zero, L_80582640
    if (ctx->r2 == 0) {
        // 0x80582638: nop
    
            goto L_80582640;
    }
    // 0x80582638: nop

    // 0x8058263C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
L_80582640:
    // 0x80582640: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x80582644: bne         $a2, $zero, L_80582650
    if (ctx->r6 != 0) {
        // 0x80582648: nop
    
            goto L_80582650;
    }
    // 0x80582648: nop

    // 0x8058264C: break       7
    do_break(2153260620);
L_80582650:
    // 0x80582650: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80582654: bne         $a2, $at, L_80582668
    if (ctx->r6 != ctx->r1) {
        // 0x80582658: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80582668;
    }
    // 0x80582658: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8058265C: bne         $a1, $at, L_80582668
    if (ctx->r5 != ctx->r1) {
        // 0x80582660: nop
    
            goto L_80582668;
    }
    // 0x80582660: nop

    // 0x80582664: break       6
    do_break(2153260644);
L_80582668:
    // 0x80582668: mfhi        $a1
    ctx->r5 = hi;
    // 0x8058266C: nop

    // 0x80582670: nop

    // 0x80582674: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x80582678: mflo        $v1
    ctx->r3 = lo;
    // 0x8058267C: addiu       $t9, $v1, 0x10
    ctx->r25 = ADD32(ctx->r3, 0X10);
    // 0x80582680: bne         $a3, $zero, L_8058268C
    if (ctx->r7 != 0) {
        // 0x80582684: nop
    
            goto L_8058268C;
    }
    // 0x80582684: nop

    // 0x80582688: break       7
    do_break(2153260680);
L_8058268C:
    // 0x8058268C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80582690: bne         $a3, $at, L_805826A4
    if (ctx->r7 != ctx->r1) {
        // 0x80582694: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805826A4;
    }
    // 0x80582694: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80582698: bne         $a1, $at, L_805826A4
    if (ctx->r5 != ctx->r1) {
        // 0x8058269C: nop
    
            goto L_805826A4;
    }
    // 0x8058269C: nop

    // 0x805826A0: break       6
    do_break(2153260704);
L_805826A4:
    // 0x805826A4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x805826A8: bne         $v1, $zero, L_805826BC
    if (ctx->r3 != 0) {
        // 0x805826AC: nop
    
            goto L_805826BC;
    }
    // 0x805826AC: nop

    // 0x805826B0: beq         $v0, $zero, L_805826BC
    if (ctx->r2 == 0) {
        // 0x805826B4: nop
    
            goto L_805826BC;
    }
    // 0x805826B4: nop

    // 0x805826B8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_805826BC:
    // 0x805826BC: div         $zero, $a1, $a3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r7)));
    // 0x805826C0: bne         $a3, $zero, L_805826CC
    if (ctx->r7 != 0) {
        // 0x805826C4: nop
    
            goto L_805826CC;
    }
    // 0x805826C4: nop

    // 0x805826C8: break       7
    do_break(2153260744);
L_805826CC:
    // 0x805826CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805826D0: bne         $a3, $at, L_805826E4
    if (ctx->r7 != ctx->r1) {
        // 0x805826D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805826E4;
    }
    // 0x805826D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805826D8: bne         $a1, $at, L_805826E4
    if (ctx->r5 != ctx->r1) {
        // 0x805826DC: nop
    
            goto L_805826E4;
    }
    // 0x805826DC: nop

    // 0x805826E0: break       6
    do_break(2153260768);
L_805826E4:
    // 0x805826E4: mfhi        $a1
    ctx->r5 = hi;
    // 0x805826E8: addiu       $t0, $a1, 0x10
    ctx->r8 = ADD32(ctx->r5, 0X10);
    // 0x805826EC: jr          $ra
    // 0x805826F0: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    return;
    // 0x805826F0: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void func_804507C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804507C4: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x804507C8: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x804507CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804507D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804507D4: lhu         $v0, 0xC($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0XC);
    // 0x804507D8: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x804507DC: andi        $t7, $v0, 0x1000
    ctx->r15 = ctx->r2 & 0X1000;
    // 0x804507E0: beq         $t7, $at, L_80450800
    if (ctx->r15 == ctx->r1) {
        // 0x804507E4: andi        $t8, $v0, 0x8000
        ctx->r24 = ctx->r2 & 0X8000;
            goto L_80450800;
    }
    // 0x804507E4: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x804507E8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x804507EC: beq         $t8, $at, L_80450800
    if (ctx->r24 == ctx->r1) {
        // 0x804507F0: andi        $t9, $v0, 0x4000
        ctx->r25 = ctx->r2 & 0X4000;
            goto L_80450800;
    }
    // 0x804507F0: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x804507F4: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x804507F8: bnel        $t9, $at, L_8045080C
    if (ctx->r25 != ctx->r1) {
        // 0x804507FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045080C;
    }
    goto skip_0;
    // 0x804507FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80450800:
    // 0x80450800: jal         0x804506FC
    // 0x80450804: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_804506FC(rdram, ctx);
        goto after_0;
    // 0x80450804: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_0:
    // 0x80450808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045080C:
    // 0x8045080C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80450810: jr          $ra
    // 0x80450814: nop

    return;
    // 0x80450814: nop

;}
RECOMP_FUNC void func_8045F120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F120: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8045F124: addiu       $at, $zero, 0x44CD
    ctx->r1 = ADD32(0, 0X44CD);
    // 0x8045F128: beq         $v0, $at, L_8045F140
    if (ctx->r2 == ctx->r1) {
        // 0x8045F12C: addiu       $at, $zero, 0x44D4
        ctx->r1 = ADD32(0, 0X44D4);
            goto L_8045F140;
    }
    // 0x8045F12C: addiu       $at, $zero, 0x44D4
    ctx->r1 = ADD32(0, 0X44D4);
    // 0x8045F130: beq         $v0, $at, L_8045F14C
    if (ctx->r2 == ctx->r1) {
        // 0x8045F134: nop
    
            goto L_8045F14C;
    }
    // 0x8045F134: nop

    // 0x8045F138: b           L_8045F158
    // 0x8045F13C: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(113, 0X830) << 16);
        goto L_8045F158;
    // 0x8045F13C: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(113, 0X830) << 16);
L_8045F140:
    // 0x8045F140: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(113, 0X830) << 16);
    // 0x8045F144: jr          $ra
    // 0x8045F148: addiu       $v0, $v0, -0x6B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(113, 0X830));
    return;
    // 0x8045F148: addiu       $v0, $v0, -0x6B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(113, 0X830));
L_8045F14C:
    // 0x8045F14C: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(113, 0X948) << 16);
    // 0x8045F150: jr          $ra
    // 0x8045F154: addiu       $v0, $v0, -0x598
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(113, 0X948));
    return;
    // 0x8045F154: addiu       $v0, $v0, -0x598
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(113, 0X948));
L_8045F158:
    // 0x8045F158: addiu       $v0, $v0, -0x6B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(113, 0X830));
    // 0x8045F15C: jr          $ra
    // 0x8045F160: nop

    return;
    // 0x8045F160: nop

;}
RECOMP_FUNC void func_8052154C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052154C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521550: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80521554: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80521558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052155C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80521560: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80521564: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(306, 0X27C) << 16);
    // 0x80521568: sb          $a2, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r6;
    // 0x8052156C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80521570: lw          $t8, 0x163C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(306, 0X27C));
    // 0x80521574: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80521578: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8052157C: jal         0x80521498
    // 0x80521580: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80521498(rdram, ctx);
        goto after_0;
    // 0x80521580: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80521584: jal         0x805214F4
    // 0x80521588: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805214F4(rdram, ctx);
        goto after_1;
    // 0x80521588: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8052158C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80521594: jr          $ra
    // 0x80521598: nop

    return;
    // 0x80521598: nop

    // 0x8052159C: nop

;}
RECOMP_FUNC void func_80464610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80464610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80464614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80464618: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8046461C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80464620: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80464624: beq         $a1, $at, L_80464640
    if (ctx->r5 == ctx->r1) {
        // 0x80464628: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80464640;
    }
    // 0x80464628: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8046462C: jal         0x80067878
    // 0x80464630: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80464630: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80464634: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80464638: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8046463C: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_80464640:
    // 0x80464640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80464644: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80464648: jr          $ra
    // 0x8046464C: nop

    return;
    // 0x8046464C: nop

;}
RECOMP_FUNC void func_804C8DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C8DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C8DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C8DC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C8DCC: jal         0x80062684
    // 0x804C8DD0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x804C8DD0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x804C8DD4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804C8DD8: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x804C8DDC: addiu       $t3, $t3, -0x54E0
    ctx->r11 = ADD32(ctx->r11, -0X54E0);
    // 0x804C8DE0: lh          $v1, 0x184($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X184);
    // 0x804C8DE4: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x804C8DE8: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x804C8DEC: beq         $v1, $zero, L_804C8E4C
    if (ctx->r3 == 0) {
        // 0x804C8DF0: addiu       $a0, $a2, 0x188
        ctx->r4 = ADD32(ctx->r6, 0X188);
            goto L_804C8E4C;
    }
    // 0x804C8DF0: addiu       $a0, $a2, 0x188
    ctx->r4 = ADD32(ctx->r6, 0X188);
    // 0x804C8DF4: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x804C8DF8: lui         $a3, 0x8010
    ctx->r7 = S32(0X8010 << 16);
    // 0x804C8DFC: addiu       $a3, $a3, -0x5508
    ctx->r7 = ADD32(ctx->r7, -0X5508);
    // 0x804C8E00: addiu       $t1, $t1, -0x54E4
    ctx->r9 = ADD32(ctx->r9, -0X54E4);
    // 0x804C8E04: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x804C8E08: addiu       $a2, $zero, 0x4001
    ctx->r6 = ADD32(0, 0X4001);
    // 0x804C8E0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_804C8E10:
    // 0x804C8E10: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804C8E14: beq         $v0, $zero, L_804C8E44
    if (ctx->r2 == 0) {
        // 0x804C8E18: nop
    
            goto L_804C8E44;
    }
    // 0x804C8E18: nop

    // 0x804C8E1C: beq         $a1, $v0, L_804C8E3C
    if (ctx->r5 == ctx->r2) {
        // 0x804C8E20: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_804C8E3C;
    }
    // 0x804C8E20: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x804C8E24: lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XC);
    // 0x804C8E28: bnel        $a2, $t6, L_804C8E40
    if (ctx->r6 != ctx->r14) {
        // 0x804C8E2C: sll         $v1, $v1, 16
        ctx->r3 = S32(ctx->r3 << 16);
            goto L_804C8E40;
    }
    goto skip_0;
    // 0x804C8E2C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    skip_0:
    // 0x804C8E30: sb          $t0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r8;
    // 0x804C8E34: sb          $t2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r10;
    // 0x804C8E38: sb          $t4, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r12;
L_804C8E3C:
    // 0x804C8E3C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
L_804C8E40:
    // 0x804C8E40: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_804C8E44:
    // 0x804C8E44: bne         $v1, $zero, L_804C8E10
    if (ctx->r3 != 0) {
        // 0x804C8E48: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_804C8E10;
    }
    // 0x804C8E48: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_804C8E4C:
    // 0x804C8E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C8E50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C8E54: jr          $ra
    // 0x804C8E58: nop

    return;
    // 0x804C8E58: nop

;}
RECOMP_FUNC void func_806F7B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7B28: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x806F7B2C: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x806F7B30: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x806F7B34: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x806F7B38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806F7B3C: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x806F7B40: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x806F7B44: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x806F7B48: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x806F7B4C: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x806F7B50: lui         $t1, 0xFFFC
    ctx->r9 = S32(0XFFFC << 16);
    // 0x806F7B54: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x806F7B58: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806F7B5C: ori         $t1, $t1, 0xF279
    ctx->r9 = ctx->r9 | 0XF279;
    // 0x806F7B60: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x806F7B64: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x806F7B68: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x806F7B6C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x806F7B70: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x806F7B74: lui         $t4, 0x8
    ctx->r12 = S32(0X8 << 16);
    // 0x806F7B78: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x806F7B7C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x806F7B80: ori         $t4, $t4, 0xAC80
    ctx->r12 = ctx->r12 | 0XAC80;
    // 0x806F7B84: ori         $t3, $t3, 0x18
    ctx->r11 = ctx->r11 | 0X18;
    // 0x806F7B88: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x806F7B8C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x806F7B90: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x806F7B94: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x806F7B98: lui         $a3, 0x55
    ctx->r7 = S32(0X55 << 16);
    // 0x806F7B9C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x806F7BA0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x806F7BA4: ori         $a3, $a3, 0x3048
    ctx->r7 = ctx->r7 | 0X3048;
    // 0x806F7BA8: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x806F7BAC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x806F7BB0: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x806F7BB4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x806F7BB8: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x806F7BBC: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x806F7BC0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x806F7BC4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806F7BC8: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x806F7BCC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x806F7BD0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x806F7BD4: addiu       $t1, $zero, 0x2204
    ctx->r9 = ADD32(0, 0X2204);
    // 0x806F7BD8: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x806F7BDC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x806F7BE0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806F7BE4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x806F7BE8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x806F7BEC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x806F7BF0: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x806F7BF4: lui         $t3, 0xBB00
    ctx->r11 = S32(0XBB00 << 16);
    // 0x806F7BF8: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x806F7BFC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x806F7C00: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x806F7C04: ori         $t4, $t4, 0x8000
    ctx->r12 = ctx->r12 | 0X8000;
    // 0x806F7C08: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x806F7C0C: jr          $ra
    // 0x806F7C10: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    return;
    // 0x806F7C10: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void func_8071584C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8071584C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80715850: lui         $t6, 0x8071
    ctx->r14 = S32(RELOC_HI16(730, 0XCC0) << 16);
    // 0x80715854: addiu       $t6, $t6, 0x54E0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(730, 0XCC0));
    // 0x80715858: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8071585C: jr          $ra
    // 0x80715860: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80715860: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804A4C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4C1C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x804A4C20: beql        $at, $zero, L_804A4C34
    if (ctx->r1 == 0) {
        // 0x804A4C24: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_804A4C34;
    }
    goto skip_0;
    // 0x804A4C24: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x804A4C28: jr          $ra
    // 0x804A4C2C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x804A4C2C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x804A4C30: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_804A4C34:
    // 0x804A4C34: beq         $at, $zero, L_804A4C70
    if (ctx->r1 == 0) {
        // 0x804A4C38: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_804A4C70;
    }
    // 0x804A4C38: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x804A4C3C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x804A4C40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804A4C44: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804A4C48: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x804A4C4C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804A4C50: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x804A4C54: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x804A4C58: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x804A4C5C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804A4C60: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804A4C64: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x804A4C68: jr          $ra
    // 0x804A4C6C: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x804A4C6C: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_804A4C70:
    // 0x804A4C70: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x804A4C74: beq         $at, $zero, L_804A4C8C
    if (ctx->r1 == 0) {
        // 0x804A4C78: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_804A4C8C;
    }
    // 0x804A4C78: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x804A4C7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804A4C80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804A4C84: jr          $ra
    // 0x804A4C88: nop

    return;
    // 0x804A4C88: nop

L_804A4C8C:
    // 0x804A4C8C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x804A4C90: beq         $at, $zero, L_804A4CD0
    if (ctx->r1 == 0) {
        // 0x804A4C94: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_804A4CD0;
    }
    // 0x804A4C94: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804A4C98: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x804A4C9C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x804A4CA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804A4CA4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804A4CA8: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804A4CAC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804A4CB0: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x804A4CB4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x804A4CB8: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x804A4CBC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804A4CC0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804A4CC4: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804A4CC8: jr          $ra
    // 0x804A4CCC: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x804A4CCC: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_804A4CD0:
    // 0x804A4CD0: jr          $ra
    // 0x804A4CD4: nop

    return;
    // 0x804A4CD4: nop

;}
RECOMP_FUNC void func_807AF3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF3A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AF3A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AF3AC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AF3B0: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x807AF3B4: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x807AF3B8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807AF3BC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x807AF3C0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x807AF3C4: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x807AF3C8: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x807AF3CC: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807AF3D0: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x807AF3D4: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x807AF3D8: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x807AF3DC: bne         $at, $zero, L_807AF3EC
    if (ctx->r1 != 0) {
        // 0x807AF3E0: swc1        $f0, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
            goto L_807AF3EC;
    }
    // 0x807AF3E0: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x807AF3E4: jal         0x807AF508
    // 0x807AF3E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_807AF508(rdram, ctx);
        goto after_0;
    // 0x807AF3E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
L_807AF3EC:
    // 0x807AF3EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AF3F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AF3F4: jr          $ra
    // 0x807AF3F8: nop

    return;
    // 0x807AF3F8: nop

;}
RECOMP_FUNC void func_8078E344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078E344: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8078E348: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(808, 0X180) << 16);
    // 0x8078E34C: addiu       $t6, $t6, -0x1F60
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(808, 0X180));
    // 0x8078E350: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8078E354: jr          $ra
    // 0x8078E358: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8078E358: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804F43E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F43E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804F43EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F43F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804F43F4: jal         0x80045A34
    // 0x804F43F8: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804F43F8: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    after_0:
    // 0x804F43FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804F4400: lui         $t6, 0x804F
    ctx->r14 = S32(RELOC_HI16(273, 0X128) << 16);
    // 0x804F4404: bne         $v0, $zero, L_804F4414
    if (ctx->r2 != 0) {
        // 0x804F4408: sw          $v0, 0x1F4($a2)
        MEM_W(0X1F4, ctx->r6) = ctx->r2;
            goto L_804F4414;
    }
    // 0x804F4408: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
    // 0x804F440C: b           L_804F4474
    // 0x804F4410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804F4474;
    // 0x804F4410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804F4414:
    // 0x804F4414: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    // 0x804F4418: addiu       $t6, $t6, 0x43B8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(273, 0X128));
    // 0x804F441C: sw          $t6, 0x1F8($a2)
    MEM_W(0X1F8, ctx->r6) = ctx->r14;
    // 0x804F4420: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x804F4424: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x804F4428: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    // 0x804F442C: jal         0x80064D1C
    // 0x804F4430: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x804F4430: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x804F4434: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804F4438: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x804F443C: bne         $v0, $zero, L_804F444C
    if (ctx->r2 != 0) {
        // 0x804F4440: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_804F444C;
    }
    // 0x804F4440: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x804F4444: b           L_804F4474
    // 0x804F4448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804F4474;
    // 0x804F4448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804F444C:
    // 0x804F444C: sw          $t8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r24;
    // 0x804F4450: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x804F4454: jal         0x80064D1C
    // 0x804F4458: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x804F4458: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_2:
    // 0x804F445C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804F4460: bne         $v0, $zero, L_804F4470
    if (ctx->r2 != 0) {
        // 0x804F4464: sw          $v0, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r2;
            goto L_804F4470;
    }
    // 0x804F4464: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x804F4468: b           L_804F4474
    // 0x804F446C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804F4474;
    // 0x804F446C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804F4470:
    // 0x804F4470: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804F4474:
    // 0x804F4474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F4478: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804F447C: jr          $ra
    // 0x804F4480: nop

    return;
    // 0x804F4480: nop

;}
RECOMP_FUNC void func_806FC938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FC938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FC93C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FC940: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806FC944: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(703, 0X710) << 16);
    // 0x806FC948: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806FC94C: addiu       $t6, $t6, -0x2FE0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(703, 0X710));
    // 0x806FC950: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806FC954: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806FC958: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x806FC95C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806FC960: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806FC964: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x806FC968: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806FC96C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806FC970: jal         0x80045A34
    // 0x806FC974: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806FC974: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x806FC978: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FC97C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806FC980: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806FC984: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806FC988: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x806FC98C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806FC990: jal         0x806FC920
    // 0x806FC994: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    func_806FC920(rdram, ctx);
        goto after_1;
    // 0x806FC994: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    after_1:
    // 0x806FC998: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FC99C: jal         0x806FCFE0
    // 0x806FC9A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806FCFE0(rdram, ctx);
        goto after_2;
    // 0x806FC9A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x806FC9A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FC9A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806FC9AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806FC9B0: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806FC9B4: jr          $ra
    // 0x806FC9B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806FC9B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805DC4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC4E0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x805DC4E4: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x805DC4E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DC4EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DC4F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805DC4F4: jal         0x805DC2A0
    // 0x805DC4F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_805DC2A0(rdram, ctx);
        goto after_0;
    // 0x805DC4F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x805DC4FC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805DC500: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805DC504: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805DC508: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x805DC50C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805DC510: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805DC514: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805DC518: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805DC51C: jal         0x805DC410
    // 0x805DC520: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    func_805DC410(rdram, ctx);
        goto after_1;
    // 0x805DC520: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    after_1:
    // 0x805DC524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DC528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DC52C: jr          $ra
    // 0x805DC530: nop

    return;
    // 0x805DC530: nop

;}
RECOMP_FUNC void func_804C224C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C224C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C2250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C2254: jal         0x804C2084
    // 0x804C2258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C2084(rdram, ctx);
        goto after_0;
    // 0x804C2258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C225C: jal         0x804C2114
    // 0x804C2260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804C2114(rdram, ctx);
        goto after_1;
    // 0x804C2260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804C2264: jal         0x804C21F4
    // 0x804C2268: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804C21F4(rdram, ctx);
        goto after_2;
    // 0x804C2268: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x804C226C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C2270: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C2274: jr          $ra
    // 0x804C2278: nop

    return;
    // 0x804C2278: nop

;}
RECOMP_FUNC void func_807B1F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B1F88: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x807B1F8C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B1F90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x807B1F94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x807B1F98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807B1F9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807B1FA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B1FA4: lw          $s3, 0x1F4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B1FA8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x807B1FAC: lw          $t6, 0x170($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X170);
    // 0x807B1FB0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x807B1FB4: addiu       $s0, $s3, 0x6C
    ctx->r16 = ADD32(ctx->r19, 0X6C);
    // 0x807B1FB8: addiu       $s2, $s3, 0x4
    ctx->r18 = ADD32(ctx->r19, 0X4);
    // 0x807B1FBC: beq         $t6, $zero, L_807B2084
    if (ctx->r14 == 0) {
        // 0x807B1FC0: lw          $s1, 0x0($v0)
        ctx->r17 = MEM_W(ctx->r2, 0X0);
            goto L_807B2084;
    }
    // 0x807B1FC0: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x807B1FC4: lwc1        $f12, 0x150($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X150);
    // 0x807B1FC8: jal         0x80081E8C
    // 0x807B1FCC: lwc1        $f14, 0x14C($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X14C);
    fatan2(rdram, ctx);
        goto after_0;
    // 0x807B1FCC: lwc1        $f14, 0x14C($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X14C);
    after_0:
    // 0x807B1FD0: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X398C) << 16);
    // 0x807B1FD4: lwc1        $f4, 0x34DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X398C));
    // 0x807B1FD8: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x807B1FDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807B1FE0: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x807B1FE4: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x807B1FE8: lwc1        $f8, 0x148($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X148);
    // 0x807B1FEC: lwc1        $f6, 0x16C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X16C);
    // 0x807B1FF0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807B1FF4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x807B1FF8: jal         0x80066E88
    // 0x807B1FFC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x807B1FFC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x807B2000: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807B2004: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x807B2008: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x807B200C: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807B2010: jal         0x80066DE4
    // 0x807B2014: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x807B2014: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x807B2018: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(871, 0X3220) << 16);
    // 0x807B201C: addiu       $v0, $v0, 0x2D70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(871, 0X3220));
    // 0x807B2020: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807B2024: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807B2028: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x807B202C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807B2030: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x807B2034: swc1        $f18, 0x12C($s3)
    MEM_W(0X12C, ctx->r19) = ctx->f18.u32l;
    // 0x807B2038: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807B203C: lwc1        $f18, 0x14C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14C);
    // 0x807B2040: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807B2044: mul.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807B2048: lwc1        $f4, 0x150($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X150);
    // 0x807B204C: sub.s       $f2, $f18, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x807B2050: swc1        $f2, 0x158($s3)
    MEM_W(0X158, ctx->r19) = ctx->f2.u32l;
    // 0x807B2054: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x807B2058: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x807B205C: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x807B2060: swc1        $f12, 0x15C($s3)
    MEM_W(0X15C, ctx->r19) = ctx->f12.u32l;
    // 0x807B2064: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B2068: swc1        $f10, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->f10.u32l;
    // 0x807B206C: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807B2070: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807B2074: jal         0x807B1508
    // 0x807B2078: swc1        $f0, 0x154($s3)
    MEM_W(0X154, ctx->r19) = ctx->f0.u32l;
    func_807B1508(rdram, ctx);
        goto after_3;
    // 0x807B2078: swc1        $f0, 0x154($s3)
    MEM_W(0X154, ctx->r19) = ctx->f0.u32l;
    after_3:
    // 0x807B207C: b           L_807B20BC
    // 0x807B2080: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_807B20BC;
    // 0x807B2080: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_807B2084:
    // 0x807B2084: jal         0x807B10B8
    // 0x807B2088: addiu       $a0, $s3, 0x12C
    ctx->r4 = ADD32(ctx->r19, 0X12C);
    func_807B10B8(rdram, ctx);
        goto after_4;
    // 0x807B2088: addiu       $a0, $s3, 0x12C
    ctx->r4 = ADD32(ctx->r19, 0X12C);
    after_4:
    // 0x807B208C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x807B2090: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_807B2094:
    // 0x807B2094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B2098: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x807B209C: jal         0x807B1048
    // 0x807B20A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_807B1048(rdram, ctx);
        goto after_5;
    // 0x807B20A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x807B20A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x807B20A8: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x807B20AC: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x807B20B0: bne         $s3, $s4, L_807B2094
    if (ctx->r19 != ctx->r20) {
        // 0x807B20B4: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_807B2094;
    }
    // 0x807B20B4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x807B20B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_807B20BC:
    // 0x807B20BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B20C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807B20C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807B20C8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x807B20CC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x807B20D0: jr          $ra
    // 0x807B20D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x807B20D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8069D294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D29C: jal         0x8069D170
    // 0x8069D2A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8069D170(rdram, ctx);
        goto after_0;
    // 0x8069D2A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D2A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069D2A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8069D2AC: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(571, 0X714) << 16);
    // 0x8069D2B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069D2B4: addiu       $t6, $t6, -0x2BFC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(571, 0X714));
    // 0x8069D2B8: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(571, 0X774) << 16);
    // 0x8069D2BC: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8069D2C0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8069D2C4: lwc1        $f6, -0x2B9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(571, 0X774));
    // 0x8069D2C8: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(571, 0X36C) << 16);
    // 0x8069D2CC: addiu       $t7, $t7, -0x2FA4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(571, 0X36C));
    // 0x8069D2D0: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8069D2D4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8069D2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D2DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D2E0: jr          $ra
    // 0x8069D2E4: nop

    return;
    // 0x8069D2E4: nop

;}
RECOMP_FUNC void func_8042EFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EFF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042EFF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8042EFFC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8042F000: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8042F004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F008: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8042F00C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8042F010: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8042F014: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8042F018: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8042F01C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042F020: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8042F024: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(56, 0X3404) << 16);
    // 0x8042F028: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8042F02C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8042F030: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8042F034: lw          $t2, 0x14E4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(56, 0X3404));
    // 0x8042F038: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8042F03C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8042F040: jal         0x8042EBA8
    // 0x8042F044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042EBA8(rdram, ctx);
        goto after_0;
    // 0x8042F044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042F048: jal         0x8042EC04
    // 0x8042F04C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8042EC04(rdram, ctx);
        goto after_1;
    // 0x8042F04C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8042F050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042F054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F058: jr          $ra
    // 0x8042F05C: nop

    return;
    // 0x8042F05C: nop

;}
RECOMP_FUNC void func_80682FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682FE4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682FE8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682FEC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682FF0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682FF4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682FF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682FFC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80683000: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80683004: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80683008: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8068300C: jr          $ra
    // 0x80683010: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80683010: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8003262C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003262C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80032634: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032638: lbu         $t6, 0x154($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X154);
    // 0x8003263C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80032640: beql        $t6, $zero, L_800326F8
    if (ctx->r14 == 0) {
        // 0x80032644: lbu         $t5, 0x155($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X155);
            goto L_800326F8;
    }
    goto skip_0;
    // 0x80032644: lbu         $t5, 0x155($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X155);
    skip_0:
    // 0x80032648: lbu         $t7, 0x155($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X155);
    // 0x8003264C: beql        $t7, $zero, L_80032668
    if (ctx->r15 == 0) {
        // 0x80032650: lbu         $t8, 0x18($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X18);
            goto L_80032668;
    }
    goto skip_1;
    // 0x80032650: lbu         $t8, 0x18($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18);
    skip_1:
    // 0x80032654: jal         0x80032564
    // 0x80032658: nop

    func_80032564(rdram, ctx);
        goto after_0;
    // 0x80032658: nop

    after_0:
    // 0x8003265C: b           L_800326EC
    // 0x80032660: nop

        goto L_800326EC;
    // 0x80032660: nop

    // 0x80032664: lbu         $t8, 0x18($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18);
L_80032668:
    // 0x80032668: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003266C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80032670: bne         $t8, $at, L_80032698
    if (ctx->r24 != ctx->r1) {
        // 0x80032674: nop
    
            goto L_80032698;
    }
    // 0x80032674: nop

    // 0x80032678: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x8003267C: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80032680: bne         $t9, $at, L_80032698
    if (ctx->r25 != ctx->r1) {
        // 0x80032684: nop
    
            goto L_80032698;
    }
    // 0x80032684: nop

    // 0x80032688: jal         0x8003D76C
    // 0x8003268C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003D76C(rdram, ctx);
        goto after_1;
    // 0x8003268C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80032690: b           L_800326EC
    // 0x80032694: sb          $zero, 0x156($s0)
    MEM_B(0X156, ctx->r16) = 0;
        goto L_800326EC;
    // 0x80032694: sb          $zero, 0x156($s0)
    MEM_B(0X156, ctx->r16) = 0;
L_80032698:
    // 0x80032698: jal         0x800325F8
    // 0x8003269C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800325F8(rdram, ctx);
        goto after_2;
    // 0x8003269C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x800326A0: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x800326A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800326A8: sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    // 0x800326AC: andi        $t1, $t0, 0x700
    ctx->r9 = ctx->r8 & 0X700;
    // 0x800326B0: beq         $t1, $zero, L_800326DC
    if (ctx->r9 == 0) {
        // 0x800326B4: addiu       $t4, $zero, 0xE
        ctx->r12 = ADD32(0, 0XE);
            goto L_800326DC;
    }
    // 0x800326B4: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x800326B8: lbu         $t2, 0x20($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X20);
    // 0x800326BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800326C0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800326C4: bne         $t2, $at, L_800326D4
    if (ctx->r10 != ctx->r1) {
        // 0x800326C8: nop
    
            goto L_800326D4;
    }
    // 0x800326C8: nop

    // 0x800326CC: b           L_800326E0
    // 0x800326D0: sb          $t3, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r11;
        goto L_800326E0;
    // 0x800326D0: sb          $t3, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r11;
L_800326D4:
    // 0x800326D4: b           L_800326E0
    // 0x800326D8: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
        goto L_800326E0;
    // 0x800326D8: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
L_800326DC:
    // 0x800326DC: sb          $t4, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r12;
L_800326E0:
    // 0x800326E0: jal         0x8003D76C
    // 0x800326E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003D76C(rdram, ctx);
        goto after_3;
    // 0x800326E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800326E8: sb          $zero, 0x156($s0)
    MEM_B(0X156, ctx->r16) = 0;
L_800326EC:
    // 0x800326EC: b           L_80032708
    // 0x800326F0: sb          $zero, 0x154($s0)
    MEM_B(0X154, ctx->r16) = 0;
        goto L_80032708;
    // 0x800326F0: sb          $zero, 0x154($s0)
    MEM_B(0X154, ctx->r16) = 0;
    // 0x800326F4: lbu         $t5, 0x155($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X155);
L_800326F8:
    // 0x800326F8: beql        $t5, $zero, L_8003270C
    if (ctx->r13 == 0) {
        // 0x800326FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003270C;
    }
    goto skip_2;
    // 0x800326FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80032700: jal         0x80032C5C
    // 0x80032704: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80032C5C(rdram, ctx);
        goto after_4;
    // 0x80032704: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
L_80032708:
    // 0x80032708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003270C:
    // 0x8003270C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80032710: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032714: jr          $ra
    // 0x80032718: nop

    return;
    // 0x80032718: nop

;}
RECOMP_FUNC void func_8003ECCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ECCC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003ECD0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003ECD4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8003ECD8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8003ECDC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8003ECE0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8003ECE4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8003ECE8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8003ECEC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8003ECF0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8003ECF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003ECF8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8003ECFC: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003ED00: addiu       $s7, $zero, 0x401C
    ctx->r23 = ADD32(0, 0X401C);
    // 0x8003ED04: addiu       $fp, $zero, 0x401D
    ctx->r30 = ADD32(0, 0X401D);
    // 0x8003ED08: lbu         $v0, 0x12C8($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X12C8);
    // 0x8003ED0C: lhu         $v1, 0x12BE($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X12BE);
    // 0x8003ED10: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x8003ED14: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8003ED18: beq         $s2, $zero, L_8003EE3C
    if (ctx->r18 == 0) {
        // 0x8003ED1C: or          $s3, $v1, $zero
        ctx->r19 = ctx->r3 | 0;
            goto L_8003EE3C;
    }
    // 0x8003ED1C: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x8003ED20: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003ED24: addiu       $s6, $zero, 0x4004
    ctx->r22 = ADD32(0, 0X4004);
    // 0x8003ED28: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
L_8003ED2C:
    // 0x8003ED2C: multu       $s3, $s5
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003ED30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003ED34: mflo        $t6
    ctx->r14 = lo;
    // 0x8003ED38: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x8003ED3C: lw          $s1, 0x11FC($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X11FC);
    // 0x8003ED40: lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XC);
    // 0x8003ED44: beq         $v0, $s6, L_8003ED8C
    if (ctx->r2 == ctx->r22) {
        // 0x8003ED48: nop
    
            goto L_8003ED8C;
    }
    // 0x8003ED48: nop

    // 0x8003ED4C: beq         $v0, $s7, L_8003EDFC
    if (ctx->r2 == ctx->r23) {
        // 0x8003ED50: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8003EDFC;
    }
    // 0x8003ED50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003ED54: beq         $v0, $fp, L_8003EDFC
    if (ctx->r2 == ctx->r30) {
        // 0x8003ED58: addiu       $at, $zero, 0x401F
        ctx->r1 = ADD32(0, 0X401F);
            goto L_8003EDFC;
    }
    // 0x8003ED58: addiu       $at, $zero, 0x401F
    ctx->r1 = ADD32(0, 0X401F);
    // 0x8003ED5C: beq         $v0, $at, L_8003EDFC
    if (ctx->r2 == ctx->r1) {
        // 0x8003ED60: addiu       $at, $zero, 0x406C
        ctx->r1 = ADD32(0, 0X406C);
            goto L_8003EDFC;
    }
    // 0x8003ED60: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8003ED64: beq         $v0, $at, L_8003EDBC
    if (ctx->r2 == ctx->r1) {
        // 0x8003ED68: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8003EDBC;
    }
    // 0x8003ED68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003ED6C: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x8003ED70: beq         $v0, $at, L_8003EDDC
    if (ctx->r2 == ctx->r1) {
        // 0x8003ED74: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8003EDDC;
    }
    // 0x8003ED74: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003ED78: addiu       $at, $zero, 0x4301
    ctx->r1 = ADD32(0, 0X4301);
    // 0x8003ED7C: beq         $v0, $at, L_8003EDFC
    if (ctx->r2 == ctx->r1) {
        // 0x8003ED80: nop
    
            goto L_8003EDFC;
    }
    // 0x8003ED80: nop

    // 0x8003ED84: b           L_8003EE20
    // 0x8003ED88: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_8003EE20;
    // 0x8003ED88: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8003ED8C:
    // 0x8003ED8C: jal         0x8003E8C0
    // 0x8003ED90: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8003E8C0(rdram, ctx);
        goto after_0;
    // 0x8003ED90: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8003ED94: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003ED98: jal         0x800447C8
    // 0x8003ED9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8003ED9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8003EDA0: beq         $s0, $zero, L_8003EE1C
    if (ctx->r16 == 0) {
        // 0x8003EDA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003EE1C;
    }
    // 0x8003EDA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003EDA8: addiu       $a1, $s2, -0x1
    ctx->r5 = ADD32(ctx->r18, -0X1);
    // 0x8003EDAC: jal         0x8003EC84
    // 0x8003EDB0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    func_8003EC84(rdram, ctx);
        goto after_2;
    // 0x8003EDB0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_2:
    // 0x8003EDB4: b           L_8003EE20
    // 0x8003EDB8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_8003EE20;
    // 0x8003EDB8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8003EDBC:
    // 0x8003EDBC: jal         0x8003EA94
    // 0x8003EDC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003EA94(rdram, ctx);
        goto after_3;
    // 0x8003EDC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8003EDC4: addiu       $a1, $s2, -0x1
    ctx->r5 = ADD32(ctx->r18, -0X1);
    // 0x8003EDC8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003EDCC: jal         0x8003EC84
    // 0x8003EDD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8003EC84(rdram, ctx);
        goto after_4;
    // 0x8003EDD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8003EDD4: b           L_8003EE20
    // 0x8003EDD8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_8003EE20;
    // 0x8003EDD8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8003EDDC:
    // 0x8003EDDC: jal         0x8003EAE0
    // 0x8003EDE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003EAE0(rdram, ctx);
        goto after_5;
    // 0x8003EDE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8003EDE4: addiu       $a1, $s2, -0x1
    ctx->r5 = ADD32(ctx->r18, -0X1);
    // 0x8003EDE8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003EDEC: jal         0x8003EC84
    // 0x8003EDF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8003EC84(rdram, ctx);
        goto after_6;
    // 0x8003EDF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8003EDF4: b           L_8003EE20
    // 0x8003EDF8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_8003EE20;
    // 0x8003EDF8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8003EDFC:
    // 0x8003EDFC: jal         0x8003EB90
    // 0x8003EE00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8003EB90(rdram, ctx);
        goto after_7;
    // 0x8003EE00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8003EE04: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x8003EE08: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8003EE0C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8003EE10: lwc1        $f4, -0x1084($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1084);
    // 0x8003EE14: swc1        $f20, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f20.u32l;
    // 0x8003EE18: swc1        $f4, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f4.u32l;
L_8003EE1C:
    // 0x8003EE1C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8003EE20:
    // 0x8003EE20: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003EE24: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8003EE28: andi        $s3, $s3, 0x7
    ctx->r19 = ctx->r19 & 0X7;
    // 0x8003EE2C: bne         $s2, $zero, L_8003ED2C
    if (ctx->r18 != 0) {
        // 0x8003EE30: andi        $s3, $s3, 0xFFFF
        ctx->r19 = ctx->r19 & 0XFFFF;
            goto L_8003ED2C;
    }
    // 0x8003EE30: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x8003EE34: lbu         $v0, 0x12C8($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X12C8);
    // 0x8003EE38: lhu         $v1, 0x12BE($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X12BE);
L_8003EE3C:
    // 0x8003EE3C: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x8003EE40: andi        $t0, $t9, 0x7
    ctx->r8 = ctx->r25 & 0X7;
    // 0x8003EE44: sh          $t0, 0x12BE($s4)
    MEM_H(0X12BE, ctx->r20) = ctx->r8;
    // 0x8003EE48: sb          $zero, 0x12C8($s4)
    MEM_B(0X12C8, ctx->r20) = 0;
    // 0x8003EE4C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8003EE50: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8003EE54: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8003EE58: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8003EE5C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8003EE60: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8003EE64: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8003EE68: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8003EE6C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8003EE70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003EE74: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8003EE78: jr          $ra
    // 0x8003EE7C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8003EE7C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_806AAC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AAC8C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x806AAC90: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x806AAC94: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x806AAC98: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x806AAC9C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x806AACA0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x806AACA4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x806AACA8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x806AACAC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x806AACB0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x806AACB4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x806AACB8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x806AACBC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x806AACC0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x806AACC4: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x806AACC8: lui         $t9, 0x806B
    ctx->r25 = S32(RELOC_HI16(592, 0X2F40) << 16);
    // 0x806AACCC: addiu       $t9, $t9, -0x24E0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(592, 0X2F40));
    // 0x806AACD0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806AACD4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806AACD8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806AACDC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x806AACE0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x806AACE4: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AACE8: addiu       $t6, $sp, 0x94
    ctx->r14 = ADD32(ctx->r29, 0X94);
    // 0x806AACEC: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x806AACF0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x806AACF4: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x806AACF8: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x806AACFC: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x806AAD00: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x806AAD04: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x806AAD08: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x806AAD0C: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x806AAD10: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x806AAD14: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x806AAD18: lwc1        $f22, 0x6C($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806AAD1C: jal         0x80049018
    // 0x806AAD20: lwc1        $f24, 0x70($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X70);
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x806AAD20: lwc1        $f24, 0x70($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X70);
    after_0:
    // 0x806AAD24: beq         $v0, $zero, L_806AAD44
    if (ctx->r2 == 0) {
        // 0x806AAD28: or          $s1, $s5, $zero
        ctx->r17 = ctx->r21 | 0;
            goto L_806AAD44;
    }
    // 0x806AAD28: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x806AAD2C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806AAD30: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806AAD34: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806AAD38: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x806AAD3C: b           L_806AAD58
    // 0x806AAD40: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
        goto L_806AAD58;
    // 0x806AAD40: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_806AAD44:
    // 0x806AAD44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806AAD48: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x806AAD4C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806AAD50: sw          $t4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r12;
    // 0x806AAD54: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
L_806AAD58:
    // 0x806AAD58: lui         $s6, 0x806B
    ctx->r22 = S32(RELOC_HI16(592, 0XC3C) << 16);
    // 0x806AAD5C: addiu       $s6, $s6, -0x47E4
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(592, 0XC3C));
    // 0x806AAD60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x806AAD64: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x806AAD68: addiu       $s4, $sp, 0x80
    ctx->r20 = ADD32(ctx->r29, 0X80);
    // 0x806AAD6C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x806AAD70: addiu       $s2, $sp, 0x64
    ctx->r18 = ADD32(ctx->r29, 0X64);
L_806AAD74:
    // 0x806AAD74: lh          $t7, 0x4($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X4);
    // 0x806AAD78: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x806AAD7C: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x806AAD80: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x806AAD84: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x806AAD88: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x806AAD8C: sll         $t0, $t6, 1
    ctx->r8 = S32(ctx->r14 << 1);
    // 0x806AAD90: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x806AAD94: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806AAD98: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x806AAD9C: addu        $t2, $s6, $t1
    ctx->r10 = ADD32(ctx->r22, ctx->r9);
    // 0x806AADA0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x806AADA4: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x806AADA8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x806AADAC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x806AADB0: sw          $t4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r12;
    // 0x806AADB4: lw          $t7, 0x8($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X8);
    // 0x806AADB8: sw          $t7, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r15;
    // 0x806AADBC: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x806AADC0: sw          $t4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r12;
    // 0x806AADC4: lw          $t7, 0x10($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X10);
    // 0x806AADC8: beq         $a0, $zero, L_806AAE6C
    if (ctx->r4 == 0) {
        // 0x806AADCC: sw          $t7, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r15;
            goto L_806AAE6C;
    }
    // 0x806AADCC: sw          $t7, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r15;
    // 0x806AADD0: lh          $t5, 0x64($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X64);
    // 0x806AADD4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x806AADD8: nop

    // 0x806AADDC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806AADE0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x806AADE4: nop

    // 0x806AADE8: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x806AADEC: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x806AADF0: lh          $t8, 0x66($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X66);
    // 0x806AADF4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x806AADF8: nop

    // 0x806AADFC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806AAE00: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x806AAE04: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x806AAE08: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x806AAE0C: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x806AAE10: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    // 0x806AAE14: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x806AAE18: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x806AAE1C: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
    // 0x806AAE20: lh          $t9, 0x70($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X70);
    // 0x806AAE24: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x806AAE28: nop

    // 0x806AAE2C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806AAE30: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x806AAE34: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    // 0x806AAE38: lh          $t6, 0x74($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X74);
    // 0x806AAE3C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x806AAE40: lh          $t0, 0x144($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X144);
    // 0x806AAE44: bne         $s7, $t0, L_806AAE54
    if (ctx->r23 != ctx->r8) {
        // 0x806AAE48: nop
    
            goto L_806AAE54;
    }
    // 0x806AAE48: nop

    // 0x806AAE4C: b           L_806AAE58
    // 0x806AAE50: sb          $s3, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r19;
        goto L_806AAE58;
    // 0x806AAE50: sb          $s3, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r19;
L_806AAE54:
    // 0x806AAE54: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
L_806AAE58:
    // 0x806AAE58: lbu         $t1, 0x72($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X72);
    // 0x806AAE5C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x806AAE60: addu        $t3, $s4, $t2
    ctx->r11 = ADD32(ctx->r20, ctx->r10);
    // 0x806AAE64: jal         0x806AAC08
    // 0x806AAE68: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    func_806AAC08(rdram, ctx);
        goto after_1;
    // 0x806AAE68: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    after_1:
L_806AAE6C:
    // 0x806AAE6C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x806AAE70: slti        $at, $s0, 0x28
    ctx->r1 = SIGNED(ctx->r16) < 0X28 ? 1 : 0;
    // 0x806AAE74: bne         $at, $zero, L_806AAD74
    if (ctx->r1 != 0) {
        // 0x806AAE78: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_806AAD74;
    }
    // 0x806AAE78: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806AAE7C: lui         $s6, 0x806B
    ctx->r22 = S32(RELOC_HI16(592, 0X15C4) << 16);
    // 0x806AAE80: addiu       $s6, $s6, -0x3E5C
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(592, 0X15C4));
    // 0x806AAE84: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x806AAE88: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x806AAE8C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x806AAE90: addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
L_806AAE94:
    // 0x806AAE94: lh          $t7, 0x4($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X4);
    // 0x806AAE98: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x806AAE9C: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    // 0x806AAEA0: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x806AAEA4: addu        $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // 0x806AAEA8: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x806AAEAC: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806AAEB0: mflo        $t6
    ctx->r14 = lo;
    // 0x806AAEB4: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x806AAEB8: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x806AAEBC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x806AAEC0: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x806AAEC4: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x806AAEC8: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x806AAECC: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x806AAED0: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x806AAED4: sw          $t3, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r11;
    // 0x806AAED8: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    // 0x806AAEDC: sw          $t7, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r15;
    // 0x806AAEE0: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x806AAEE4: sw          $t3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r11;
    // 0x806AAEE8: lw          $t7, 0x10($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X10);
    // 0x806AAEEC: beq         $a0, $zero, L_806AAF90
    if (ctx->r4 == 0) {
        // 0x806AAEF0: sw          $t7, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r15;
            goto L_806AAF90;
    }
    // 0x806AAEF0: sw          $t7, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r15;
    // 0x806AAEF4: lh          $t4, 0x64($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X64);
    // 0x806AAEF8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x806AAEFC: nop

    // 0x806AAF00: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806AAF04: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x806AAF08: nop

    // 0x806AAF0C: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x806AAF10: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x806AAF14: lh          $t5, 0x66($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X66);
    // 0x806AAF18: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x806AAF1C: nop

    // 0x806AAF20: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806AAF24: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x806AAF28: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x806AAF2C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x806AAF30: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x806AAF34: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x806AAF38: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x806AAF3C: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x806AAF40: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x806AAF44: lh          $t8, 0x70($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X70);
    // 0x806AAF48: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x806AAF4C: nop

    // 0x806AAF50: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x806AAF54: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x806AAF58: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x806AAF5C: lh          $t9, 0x74($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X74);
    // 0x806AAF60: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x806AAF64: lh          $t6, 0x144($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X144);
    // 0x806AAF68: bne         $fp, $t6, L_806AAF78
    if (ctx->r30 != ctx->r14) {
        // 0x806AAF6C: nop
    
            goto L_806AAF78;
    }
    // 0x806AAF6C: nop

    // 0x806AAF70: b           L_806AAF7C
    // 0x806AAF74: sb          $s3, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r19;
        goto L_806AAF7C;
    // 0x806AAF74: sb          $s3, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r19;
L_806AAF78:
    // 0x806AAF78: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
L_806AAF7C:
    // 0x806AAF7C: lbu         $t0, 0x72($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X72);
    // 0x806AAF80: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x806AAF84: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x806AAF88: jal         0x806AAC08
    // 0x806AAF8C: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    func_806AAC08(rdram, ctx);
        goto after_2;
    // 0x806AAF8C: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    after_2:
L_806AAF90:
    // 0x806AAF90: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x806AAF94: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x806AAF98: bne         $s0, $at, L_806AAE94
    if (ctx->r16 != ctx->r1) {
        // 0x806AAF9C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_806AAE94;
    }
    // 0x806AAF9C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806AAFA0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x806AAFA4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x806AAFA8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x806AAFAC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x806AAFB0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x806AAFB4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x806AAFB8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x806AAFBC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x806AAFC0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x806AAFC4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x806AAFC8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x806AAFCC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x806AAFD0: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x806AAFD4: jr          $ra
    // 0x806AAFD8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x806AAFD8: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_806815F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806815F4: jr          $ra
    // 0x806815F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806815F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8005D29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D29C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005D2A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005D2A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005D2A8: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x8005D2AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005D2B0: bne         $v0, $zero, L_8005D2C0
    if (ctx->r2 != 0) {
        // 0x8005D2B4: addiu       $a0, $v0, 0x4
        ctx->r4 = ADD32(ctx->r2, 0X4);
            goto L_8005D2C0;
    }
    // 0x8005D2B4: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8005D2B8: b           L_8005D30C
    // 0x8005D2BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005D30C;
    // 0x8005D2BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005D2C0:
    // 0x8005D2C0: jal         0x80057C9C
    // 0x8005D2C4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80057C9C(rdram, ctx);
        goto after_0;
    // 0x8005D2C4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x8005D2C8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8005D2CC: beq         $v0, $zero, L_8005D304
    if (ctx->r2 == 0) {
        // 0x8005D2D0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8005D304;
    }
    // 0x8005D2D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8005D2D4: jal         0x80043C94
    // 0x8005D2D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80043C94(rdram, ctx);
        goto after_1;
    // 0x8005D2D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8005D2DC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8005D2E0: lw          $t6, 0x62F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X62F0);
    // 0x8005D2E4: beq         $t6, $zero, L_8005D2F4
    if (ctx->r14 == 0) {
        // 0x8005D2E8: nop
    
            goto L_8005D2F4;
    }
    // 0x8005D2E8: nop

    // 0x8005D2EC: jal         0x800462E0
    // 0x8005D2F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800462E0(rdram, ctx);
        goto after_2;
    // 0x8005D2F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8005D2F4:
    // 0x8005D2F4: jal         0x800471A0
    // 0x8005D2F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800471A0(rdram, ctx);
        goto after_3;
    // 0x8005D2F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8005D2FC: b           L_8005D30C
    // 0x8005D300: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8005D30C;
    // 0x8005D300: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8005D304:
    // 0x8005D304: sw          $zero, 0x78($a1)
    MEM_W(0X78, ctx->r5) = 0;
    // 0x8005D308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005D30C:
    // 0x8005D30C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D314: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005D318: jr          $ra
    // 0x8005D31C: nop

    return;
    // 0x8005D31C: nop

;}
RECOMP_FUNC void func_8003DB3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DB3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DB40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003DB44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003DB48: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8003DB4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003DB50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003DB54: beql        $v0, $zero, L_8003DB84
    if (ctx->r2 == 0) {
        // 0x8003DB58: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_8003DB84;
    }
    goto skip_0;
    // 0x8003DB58: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x8003DB5C: lbu         $a0, 0x1C($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1C);
    // 0x8003DB60: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8003DB64: jal         0x80067D5C
    // 0x8003DB68: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x8003DB68: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x8003DB6C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x8003DB70: jal         0x80067818
    // 0x8003DB74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8003DB74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8003DB78: b           L_8003DB98
    // 0x8003DB7C: nop

        goto L_8003DB98;
    // 0x8003DB7C: nop

    // 0x8003DB80: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_8003DB84:
    // 0x8003DB84: jal         0x80067D5C
    // 0x8003DB88: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x8003DB88: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8003DB8C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x8003DB90: jal         0x80067818
    // 0x8003DB94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8003DB94: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_8003DB98:
    // 0x8003DB98: jal         0x8003DAB8
    // 0x8003DB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003DAB8(rdram, ctx);
        goto after_4;
    // 0x8003DB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8003DBA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DBA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003DBA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DBAC: jr          $ra
    // 0x8003DBB0: nop

    return;
    // 0x8003DBB0: nop

;}
RECOMP_FUNC void func_8044BADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BADC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BAE0: jr          $ra
    // 0x8044BAE4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BAE4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80533794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533794: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80533798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8053379C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805337A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805337A4: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x805337A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805337AC: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805337B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805337B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805337B8: jal         0x800692D4
    // 0x805337BC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x805337BC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x805337C0: jal         0x80532CFC
    // 0x805337C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532CFC(rdram, ctx);
        goto after_1;
    // 0x805337C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805337C8: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805337CC: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x805337D0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805337D4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x805337D8: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x805337DC: nop

    // 0x805337E0: bc1t        L_805337F4
    if (c1cs) {
        // 0x805337E4: nop
    
            goto L_805337F4;
    }
    // 0x805337E4: nop

    // 0x805337E8: lwc1        $f18, 0x28($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X28);
    // 0x805337EC: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x805337F0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_805337F4:
    // 0x805337F4: jal         0x80533170
    // 0x805337F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80533170(rdram, ctx);
        goto after_2;
    // 0x805337F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805337FC: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80533800: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80533804: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80533808: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8053380C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80533810: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80533814: nop

    // 0x80533818: bc1f        L_80533824
    if (!c1cs) {
        // 0x8053381C: nop
    
            goto L_80533824;
    }
    // 0x8053381C: nop

    // 0x80533820: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
L_80533824:
    // 0x80533824: jal         0x80532B50
    // 0x80533828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80532B50(rdram, ctx);
        goto after_3;
    // 0x80533828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8053382C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80533830: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80533834: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80533838: jr          $ra
    // 0x8053383C: nop

    return;
    // 0x8053383C: nop

;}
RECOMP_FUNC void func_8002CB84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CB84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002CB88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CB8C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CB90: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002CB94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002CB98: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002CB9C: addiu       $t8, $t8, 0x3450
    ctx->r24 = ADD32(ctx->r24, 0X3450);
    // 0x8002CBA0: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8002CBA4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8002CBA8: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    // 0x8002CBAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002CBB0: jal         0x8002DBE4
    // 0x8002CBB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002DBE4(rdram, ctx);
        goto after_0;
    // 0x8002CBB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8002CBB8: jal         0x80040C0C
    // 0x8002CBBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80040C0C(rdram, ctx);
        goto after_1;
    // 0x8002CBBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8002CBC0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CBC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002CBC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002CBCC: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x8002CBD0: addiu       $t0, $t0, 0x33B4
    ctx->r8 = ADD32(ctx->r8, 0X33B4);
    // 0x8002CBD4: sb          $t9, 0x1AC($v0)
    MEM_B(0X1AC, ctx->r2) = ctx->r25;
    // 0x8002CBD8: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x8002CBDC: sw          $zero, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = 0;
    // 0x8002CBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CBE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002CBE8: jr          $ra
    // 0x8002CBEC: nop

    return;
    // 0x8002CBEC: nop

;}
RECOMP_FUNC void func_8001F7B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F7B4: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8001F7B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001F7BC: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x8001F7C0: lhu         $t7, 0xE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XE);
    // 0x8001F7C4: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8001F7C8: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8001F7CC: beq         $t9, $at, L_8001F7E0
    if (ctx->r25 == ctx->r1) {
        // 0x8001F7D0: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8001F7E0;
    }
    // 0x8001F7D0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001F7D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001F7D8: nop

    // 0x8001F7DC: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
L_8001F7E0:
    // 0x8001F7E0: jr          $ra
    // 0x8001F7E4: nop

    return;
    // 0x8001F7E4: nop

;}
RECOMP_FUNC void func_8040B8E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B8E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040B8E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B8EC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8040B8F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040B8F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040B8F8: jal         0x8040BA40
    // 0x8040B8FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8040BA40(rdram, ctx);
        goto after_0;
    // 0x8040B8FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8040B900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040B904: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8040B908: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8040B90C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8040B910: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8040B914: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8040B918: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040B91C: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x8040B920: beql        $t7, $zero, L_8040B940
    if (ctx->r15 == 0) {
        // 0x8040B924: swc1        $f0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
            goto L_8040B940;
    }
    goto skip_0;
    // 0x8040B924: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    skip_0:
    // 0x8040B928: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8040B92C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040B930: nop

    // 0x8040B934: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8040B938: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8040B93C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8040B940:
    // 0x8040B940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040B944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040B948: jr          $ra
    // 0x8040B94C: nop

    return;
    // 0x8040B94C: nop

;}
RECOMP_FUNC void func_807C4148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C4148: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807C414C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807C4150: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807C4154: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807C4158: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807C415C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807C4160: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807C4164: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(907, 0X1478) << 16);
    // 0x807C4168: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807C416C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807C4170: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807C4174: lw          $t1, 0x47D8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(907, 0X1478));
    // 0x807C4178: jr          $ra
    // 0x807C417C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807C417C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804623F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804623F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804623F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804623F8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804623FC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80462400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80462404: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80462408: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8046240C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80462410: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80462414: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80462418: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(122, 0X37E4) << 16);
    // 0x8046241C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80462420: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80462424: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80462428: lw          $t2, 0x3D74($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(122, 0X37E4));
    // 0x8046242C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80462430: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80462434: jal         0x80461B30
    // 0x80462438: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80461B30(rdram, ctx);
        goto after_0;
    // 0x80462438: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046243C: jal         0x80461B8C
    // 0x80462440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80461B8C(rdram, ctx);
        goto after_1;
    // 0x80462440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80462444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80462448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046244C: jr          $ra
    // 0x80462450: nop

    return;
    // 0x80462450: nop

;}
RECOMP_FUNC void func_8073EC04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EC04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073EC08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EC0C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8073EC10: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(748, 0X237C) << 16);
    // 0x8073EC14: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8073EC18: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8073EC1C: addiu       $t6, $t6, 0xB6C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(748, 0X237C));
    // 0x8073EC20: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8073EC24: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8073EC28: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8073EC2C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8073EC30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073EC34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073EC38: jal         0x8073EC50
    // 0x8073EC3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8073EC50(rdram, ctx);
        goto after_0;
    // 0x8073EC3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8073EC40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EC44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073EC48: jr          $ra
    // 0x8073EC4C: nop

    return;
    // 0x8073EC4C: nop

;}
RECOMP_FUNC void func_807A65EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A65EC: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(847, 0X14BC) << 16);
    // 0x807A65F0: addiu       $t7, $t7, 0x71BC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(847, 0X14BC));
    // 0x807A65F4: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x807A65F8: lw          $a2, 0x16C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X16C);
    // 0x807A65FC: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x807A6600: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x807A6604: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_807A6608:
    // 0x807A6608: lbu         $t8, 0x0($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X0);
    // 0x807A660C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807A6610: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x807A6614: sb          $t8, 0x9($a2)
    MEM_B(0X9, ctx->r6) = ctx->r24;
    // 0x807A6618: lbu         $t9, 0x1($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X1);
    // 0x807A661C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x807A6620: sb          $t9, 0xA($a2)
    MEM_B(0XA, ctx->r6) = ctx->r25;
    // 0x807A6624: lbu         $t0, -0x2($a3)
    ctx->r8 = MEM_BU(ctx->r7, -0X2);
    // 0x807A6628: sb          $t0, 0xB($a2)
    MEM_B(0XB, ctx->r6) = ctx->r8;
    // 0x807A662C: lbu         $t1, -0x1($a3)
    ctx->r9 = MEM_BU(ctx->r7, -0X1);
    // 0x807A6630: bne         $v1, $v0, L_807A6608
    if (ctx->r3 != ctx->r2) {
        // 0x807A6634: sb          $t1, 0xC($a2)
        MEM_B(0XC, ctx->r6) = ctx->r9;
            goto L_807A6608;
    }
    // 0x807A6634: sb          $t1, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r9;
    // 0x807A6638: jr          $ra
    // 0x807A663C: nop

    return;
    // 0x807A663C: nop

;}
RECOMP_FUNC void func_8044CCD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044CCD0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044CCD4: lw          $t6, 0xA60($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA60);
    // 0x8044CCD8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8044CCDC: jr          $ra
    // 0x8044CCE0: sw          $t7, 0xA60($v0)
    MEM_W(0XA60, ctx->r2) = ctx->r15;
    return;
    // 0x8044CCE0: sw          $t7, 0xA60($v0)
    MEM_W(0XA60, ctx->r2) = ctx->r15;
;}
