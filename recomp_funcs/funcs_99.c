#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8004A498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A498: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004A49C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8004A4A0: lw          $t1, 0x70($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X70);
    // 0x8004A4A4: lw          $v1, 0x2C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X2C);
    // 0x8004A4A8: lw          $a2, 0x30($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X30);
    // 0x8004A4AC: lw          $a3, 0x34($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X34);
    // 0x8004A4B0: lw          $t0, 0x38($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X38);
    // 0x8004A4B4: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8004A4B8: lwc1        $f2, 0x4($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8004A4BC: beq         $v1, $zero, L_8004A6A4
    if (ctx->r3 == 0) {
        // 0x8004A4C0: lwc1        $f12, 0x8($t1)
        ctx->f12.u32l = MEM_W(ctx->r9, 0X8);
            goto L_8004A6A4;
    }
    // 0x8004A4C0: lwc1        $f12, 0x8($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8004A4C4: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x8004A4C8: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004A4CC: beq         $a0, $zero, L_8004A554
    if (ctx->r4 == 0) {
        // 0x8004A4D0: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_8004A554;
    }
    // 0x8004A4D0: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x8004A4D4: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8004A4D8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004A4DC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A4E0: beql        $v0, $v1, L_8004A528
    if (ctx->r2 == ctx->r3) {
        // 0x8004A4E4: swc1        $f18, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
            goto L_8004A528;
    }
    goto skip_0;
    // 0x8004A4E4: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    skip_0:
    // 0x8004A4E8: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_8004A4EC:
    // 0x8004A4EC: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8004A4F0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8004A4F4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8004A4F8: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A4FC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8004A500: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8004A504: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8004A508: lwc1        $f16, -0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X4);
    // 0x8004A50C: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A510: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8004A514: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8004A518: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A51C: bnel        $v0, $v1, L_8004A4EC
    if (ctx->r2 != ctx->r3) {
        // 0x8004A520: swc1        $f18, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
            goto L_8004A4EC;
    }
    goto skip_1;
    // 0x8004A520: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    skip_1:
    // 0x8004A524: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_8004A528:
    // 0x8004A528: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8004A52C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8004A530: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8004A534: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A538: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8004A53C: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8004A540: lwc1        $f16, -0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X4);
    // 0x8004A544: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A548: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8004A54C: beq         $v1, $zero, L_8004A6A4
    if (ctx->r3 == 0) {
        // 0x8004A550: nop
    
            goto L_8004A6A4;
    }
    // 0x8004A550: nop

L_8004A554:
    // 0x8004A554: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8004A558: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8004A55C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A560: beql        $v1, $zero, L_8004A614
    if (ctx->r3 == 0) {
        // 0x8004A564: swc1        $f18, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
            goto L_8004A614;
    }
    goto skip_2;
    // 0x8004A564: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    skip_2:
    // 0x8004A568: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_8004A56C:
    // 0x8004A56C: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8004A570: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8004A574: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8004A578: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A57C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8004A580: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8004A584: swc1        $f16, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f16.u32l;
    // 0x8004A588: lwc1        $f16, -0x10($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X10);
    // 0x8004A58C: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A590: swc1        $f16, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f16.u32l;
    // 0x8004A594: lwc1        $f16, -0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0XC);
    // 0x8004A598: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A59C: swc1        $f16, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->f16.u32l;
    // 0x8004A5A0: lwc1        $f16, -0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, -0XC);
    // 0x8004A5A4: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A5A8: swc1        $f16, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f16.u32l;
    // 0x8004A5AC: lwc1        $f16, -0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0XC);
    // 0x8004A5B0: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A5B4: swc1        $f16, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f16.u32l;
    // 0x8004A5B8: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x8004A5BC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A5C0: swc1        $f16, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f16.u32l;
    // 0x8004A5C4: lwc1        $f16, -0x8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, -0X8);
    // 0x8004A5C8: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A5CC: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x8004A5D0: lwc1        $f16, -0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X8);
    // 0x8004A5D4: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A5D8: swc1        $f16, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f16.u32l;
    // 0x8004A5DC: lwc1        $f16, -0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8004A5E0: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A5E4: swc1        $f16, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8004A5E8: lwc1        $f16, -0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, -0X4);
    // 0x8004A5EC: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A5F0: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8004A5F4: lwc1        $f16, -0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X4);
    // 0x8004A5F8: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A5FC: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8004A600: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8004A604: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A608: bnel        $v1, $zero, L_8004A56C
    if (ctx->r3 != 0) {
        // 0x8004A60C: swc1        $f18, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
            goto L_8004A56C;
    }
    goto skip_3;
    // 0x8004A60C: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    skip_3:
    // 0x8004A610: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_8004A614:
    // 0x8004A614: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8004A618: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8004A61C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8004A620: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A624: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8004A628: swc1        $f16, -0x10($a3)
    MEM_W(-0X10, ctx->r7) = ctx->f16.u32l;
    // 0x8004A62C: lwc1        $f16, -0x10($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X10);
    // 0x8004A630: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A634: swc1        $f16, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->f16.u32l;
    // 0x8004A638: lwc1        $f16, -0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0XC);
    // 0x8004A63C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A640: swc1        $f16, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->f16.u32l;
    // 0x8004A644: lwc1        $f16, -0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, -0XC);
    // 0x8004A648: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A64C: swc1        $f16, -0xC($a3)
    MEM_W(-0XC, ctx->r7) = ctx->f16.u32l;
    // 0x8004A650: lwc1        $f16, -0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0XC);
    // 0x8004A654: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A658: swc1        $f16, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->f16.u32l;
    // 0x8004A65C: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x8004A660: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A664: swc1        $f16, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f16.u32l;
    // 0x8004A668: lwc1        $f16, -0x8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, -0X8);
    // 0x8004A66C: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A670: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x8004A674: lwc1        $f16, -0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X8);
    // 0x8004A678: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A67C: swc1        $f16, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->f16.u32l;
    // 0x8004A680: lwc1        $f16, -0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8004A684: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8004A688: swc1        $f16, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f16.u32l;
    // 0x8004A68C: lwc1        $f16, -0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, -0X4);
    // 0x8004A690: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8004A694: swc1        $f16, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8004A698: lwc1        $f16, -0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X4);
    // 0x8004A69C: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8004A6A0: swc1        $f16, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f16.u32l;
L_8004A6A4:
    // 0x8004A6A4: jr          $ra
    // 0x8004A6A8: nop

    return;
    // 0x8004A6A8: nop

;}
RECOMP_FUNC void eepmgr_Read(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CFB0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007CFB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CFB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007CFBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007CFC0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8007CFC4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8007CFC8: jal         0x8007CDA0
    // 0x8007CFCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007CDA0(rdram, ctx);
        goto after_0;
    // 0x8007CFCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007CFD0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007CFD4: jal         0x8008B920
    // 0x8007CFD8: sb          $t6, 0x225($s0)
    MEM_B(0X225, ctx->r16) = ctx->r14;
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x8007CFD8: sb          $t6, 0x225($s0)
    MEM_B(0X225, ctx->r16) = ctx->r14;
    after_1:
    // 0x8007CFDC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007CFE0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8007CFE4: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8007CFE8: lbu         $a1, 0x4F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X4F);
    // 0x8007CFEC: jal         0x80091190
    // 0x8007CFF0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    osEepromRead_recomp(rdram, ctx);
        goto after_2;
    // 0x8007CFF0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x8007CFF4: jal         0x8008B920
    // 0x8007CFF8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x8007CFF8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_3:
    // 0x8007CFFC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8007D000: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8007D004: sb          $zero, 0x225($s0)
    MEM_B(0X225, ctx->r16) = 0;
    // 0x8007D008: jal         0x8007CDCC
    // 0x8007D00C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007CDCC(rdram, ctx);
        goto after_4;
    // 0x8007D00C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8007D010: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8007D014: addiu       $s0, $s0, -0x65E0
    ctx->r16 = ADD32(ctx->r16, -0X65E0);
    // 0x8007D018: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8007D01C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007D020: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007D024: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8007D028: bne         $at, $zero, L_8007D088
    if (ctx->r1 != 0) {
        // 0x8007D02C: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_8007D088;
    }
    // 0x8007D02C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8007D030: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8007D034: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    // 0x8007D038: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007D03C: sltu        $at, $t9, $t1
    ctx->r1 = ctx->r25 < ctx->r9 ? 1 : 0;
    // 0x8007D040: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x8007D044: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x8007D048: jal         0x80082D88
    // 0x8007D04C: subu        $a1, $t9, $t1
    ctx->r5 = SUB32(ctx->r25, ctx->r9);
    __ll_mul_recomp(rdram, ctx);
        goto after_5;
    // 0x8007D04C: subu        $a1, $t9, $t1
    ctx->r5 = SUB32(ctx->r25, ctx->r9);
    after_5:
    // 0x8007D050: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8007D054: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8007D058: lw          $a1, -0x53BC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X53BC);
    // 0x8007D05C: lw          $a0, -0x53C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53C0);
    // 0x8007D060: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007D064: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8007D068: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8007D06C: jal         0x80082C88
    // 0x8007D070: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_6;
    // 0x8007D070: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_6:
    // 0x8007D074: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007D078: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8007D07C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8007D080: jal         0x80082C88
    // 0x8007D084: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ull_div_recomp(rdram, ctx);
        goto after_7;
    // 0x8007D084: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_7:
L_8007D088:
    // 0x8007D088: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8007D08C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007D094: beq         $t2, $zero, L_8007D0A4
    if (ctx->r10 == 0) {
        // 0x8007D098: nop
    
            goto L_8007D0A4;
    }
    // 0x8007D098: nop

    // 0x8007D09C: b           L_8007D0A4
    // 0x8007D0A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007D0A4;
    // 0x8007D0A0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007D0A4:
    // 0x8007D0A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007D0A8: jr          $ra
    // 0x8007D0AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007D0AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_804697CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804697CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804697D0: jr          $ra
    // 0x804697D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x804697D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80019D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019D78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019D80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019D84: jal         0x80019AC4
    // 0x80019D88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x80019D88: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80019D8C: beq         $v0, $zero, L_80019DA8
    if (ctx->r2 == 0) {
        // 0x80019D90: lh          $t6, 0x1A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X1A);
            goto L_80019DA8;
    }
    // 0x80019D90: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x80019D94: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
    // 0x80019D98: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x80019D9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80019DA0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80019DA4: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
L_80019DA8:
    // 0x80019DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019DB0: jr          $ra
    // 0x80019DB4: nop

    return;
    // 0x80019DB4: nop

;}
RECOMP_FUNC void func_800046C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800046C8: lui         $t8, 0x8009
    ctx->r24 = S32(0X8009 << 16);
    // 0x800046CC: addiu       $t8, $t8, 0x7448
    ctx->r24 = ADD32(ctx->r24, 0X7448);
    // 0x800046D0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800046D4: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x800046D8: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x800046DC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800046E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800046E4:
    // 0x800046E4: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800046E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800046EC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800046F0: sh          $t9, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r25;
    // 0x800046F4: lh          $t0, 0x2($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X2);
    // 0x800046F8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800046FC: sh          $t0, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r8;
    // 0x80004700: lh          $t1, -0x4($a2)
    ctx->r9 = MEM_H(ctx->r6, -0X4);
    // 0x80004704: sh          $t1, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r9;
    // 0x80004708: lh          $t2, -0x2($a2)
    ctx->r10 = MEM_H(ctx->r6, -0X2);
    // 0x8000470C: bne         $v0, $a0, L_800046E4
    if (ctx->r2 != ctx->r4) {
        // 0x80004710: sh          $t2, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r10;
            goto L_800046E4;
    }
    // 0x80004710: sh          $t2, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r10;
    // 0x80004714: jr          $ra
    // 0x80004718: nop

    return;
    // 0x80004718: nop

;}
RECOMP_FUNC void func_805A637C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A637C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A6380: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A6384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A6388: jal         0x805A5DF0
    // 0x805A638C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_805A5DF0(rdram, ctx);
        goto after_0;
    // 0x805A638C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x805A6390: jal         0x805A6120
    // 0x805A6394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A6120(rdram, ctx);
        goto after_1;
    // 0x805A6394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A6398: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x805A639C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x805A63A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A63A4: lwc1        $f6, 0x274($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X274);
    // 0x805A63A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A63AC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805A63B0: nop

    // 0x805A63B4: bc1fl       L_805A63D8
    if (!c1cs) {
        // 0x805A63B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A63D8;
    }
    goto skip_0;
    // 0x805A63B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805A63BC: jal         0x805A6730
    // 0x805A63C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_805A6730(rdram, ctx);
        goto after_2;
    // 0x805A63C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x805A63C4: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x805A63C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805A63CC: nop

    // 0x805A63D0: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x805A63D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A63D8:
    // 0x805A63D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A63DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A63E0: jr          $ra
    // 0x805A63E4: nop

    return;
    // 0x805A63E4: nop

;}
RECOMP_FUNC void func_806EE124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EE128: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806EE12C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EE130: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806EE134: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806EE138: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x806EE13C: jal         0x80062AEC
    // 0x806EE140: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x806EE140: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x806EE144: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806EE148: beq         $v0, $at, L_806EE174
    if (ctx->r2 == ctx->r1) {
        // 0x806EE14C: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_806EE174;
    }
    // 0x806EE14C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806EE150: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806EE154: beq         $v0, $at, L_806EE1A8
    if (ctx->r2 == ctx->r1) {
        // 0x806EE158: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_806EE1A8;
    }
    // 0x806EE158: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806EE15C: beq         $v0, $at, L_806EE1DC
    if (ctx->r2 == ctx->r1) {
        // 0x806EE160: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_806EE1DC;
    }
    // 0x806EE160: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806EE164: beq         $v0, $at, L_806EE210
    if (ctx->r2 == ctx->r1) {
        // 0x806EE168: nop
    
            goto L_806EE210;
    }
    // 0x806EE168: nop

    // 0x806EE16C: b           L_806EE248
    // 0x806EE170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EE248;
    // 0x806EE170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EE174:
    // 0x806EE174: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CF0) << 16);
    // 0x806EE178: lwc1        $f4, 0xC40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CF0));
    // 0x806EE17C: lwc1        $f0, 0xC4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x806EE180: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806EE184: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806EE188: nop

    // 0x806EE18C: bc1fl       L_806EE248
    if (!c1cs) {
        // 0x806EE190: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806EE248;
    }
    goto skip_0;
    // 0x806EE190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806EE194: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806EE198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806EE19C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806EE1A0: b           L_806EE248
    // 0x806EE1A4: swc1        $f8, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f8.u32l;
        goto L_806EE248;
    // 0x806EE1A4: swc1        $f8, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f8.u32l;
L_806EE1A8:
    // 0x806EE1A8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CF4) << 16);
    // 0x806EE1AC: lwc1        $f10, 0xC44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CF4));
    // 0x806EE1B0: lwc1        $f0, 0xC4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x806EE1B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806EE1B8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806EE1BC: nop

    // 0x806EE1C0: bc1fl       L_806EE248
    if (!c1cs) {
        // 0x806EE1C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806EE248;
    }
    goto skip_1;
    // 0x806EE1C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x806EE1C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806EE1CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806EE1D0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x806EE1D4: b           L_806EE248
    // 0x806EE1D8: swc1        $f18, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f18.u32l;
        goto L_806EE248;
    // 0x806EE1D8: swc1        $f18, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f18.u32l;
L_806EE1DC:
    // 0x806EE1DC: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CF8) << 16);
    // 0x806EE1E0: lwc1        $f4, 0xC48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CF8));
    // 0x806EE1E4: lwc1        $f0, 0xC8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x806EE1E8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806EE1EC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806EE1F0: nop

    // 0x806EE1F4: bc1fl       L_806EE248
    if (!c1cs) {
        // 0x806EE1F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806EE248;
    }
    goto skip_2;
    // 0x806EE1F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x806EE1FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806EE200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806EE204: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x806EE208: b           L_806EE248
    // 0x806EE20C: swc1        $f8, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f8.u32l;
        goto L_806EE248;
    // 0x806EE20C: swc1        $f8, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f8.u32l;
L_806EE210:
    // 0x806EE210: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CFC) << 16);
    // 0x806EE214: lwc1        $f10, 0xC4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CFC));
    // 0x806EE218: lwc1        $f0, 0xC8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x806EE21C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806EE220: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806EE224: nop

    // 0x806EE228: bc1fl       L_806EE248
    if (!c1cs) {
        // 0x806EE22C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806EE248;
    }
    goto skip_3;
    // 0x806EE22C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x806EE230: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806EE234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806EE238: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x806EE23C: b           L_806EE248
    // 0x806EE240: swc1        $f18, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f18.u32l;
        goto L_806EE248;
    // 0x806EE240: swc1        $f18, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f18.u32l;
    // 0x806EE244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EE248:
    // 0x806EE248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EE24C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EE250: jr          $ra
    // 0x806EE254: nop

    return;
    // 0x806EE254: nop

;}
RECOMP_FUNC void func_80050A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050A2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050A34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050A38: jal         0x80050928
    // 0x80050A3C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80050928(rdram, ctx);
        goto after_0;
    // 0x80050A3C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80050A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050A44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050A48: jr          $ra
    // 0x80050A4C: nop

    return;
    // 0x80050A4C: nop

;}
RECOMP_FUNC void func_805351A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805351A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805351AC: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805351B0: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x805351B4: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x805351B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805351BC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805351C0: jr          $ra
    // 0x805351C4: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x805351C4: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_80025348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025348: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8002534C: addiu       $t6, $t6, 0x511C
    ctx->r14 = ADD32(ctx->r14, 0X511C);
    // 0x80025350: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80025354: jr          $ra
    // 0x80025358: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80025358: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8003B37C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B37C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B384: jal         0x8003A5BC
    // 0x8003B388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8003A5BC(rdram, ctx);
        goto after_0;
    // 0x8003B388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B38C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B390: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003B394: lwc1        $f6, 0x7C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003B398: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x8003B39C: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x8003B3A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B3A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B3A8: jr          $ra
    // 0x8003B3AC: nop

    return;
    // 0x8003B3AC: nop

;}
RECOMP_FUNC void func_8066B874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066B878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066B87C: jal         0x8066B7C0
    // 0x8066B880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8066B7C0(rdram, ctx);
        goto after_0;
    // 0x8066B880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066B884: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066B888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B88C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8066B890: jal         0x8066B970
    // 0x8066B894: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8066B970(rdram, ctx);
        goto after_1;
    // 0x8066B894: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8066B898: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066B89C: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(514, 0X2708) << 16);
    // 0x8066B8A0: lwc1        $f4, -0x2C98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(514, 0X2708));
    // 0x8066B8A4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B8A8: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8066B8AC: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8066B8B0: jal         0x8066B570
    // 0x8066B8B4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    func_8066B570(rdram, ctx);
        goto after_2;
    // 0x8066B8B4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    after_2:
    // 0x8066B8B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066B8BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066B8C0: jr          $ra
    // 0x8066B8C4: nop

    return;
    // 0x8066B8C4: nop

;}
RECOMP_FUNC void func_80039C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039C88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039C8C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039C90: addiu       $a0, $a0, 0x74D0
    ctx->r4 = ADD32(ctx->r4, 0X74D0);
    // 0x80039C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039C98: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80039C9C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80039CA0: sw          $a0, 0x427C($at)
    MEM_W(0X427C, ctx->r1) = ctx->r4;
    // 0x80039CA4: addiu       $a1, $a1, 0x74E0
    ctx->r5 = ADD32(ctx->r5, 0X74E0);
    // 0x80039CA8: jal         0x8004667C
    // 0x80039CAC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80039CAC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80039CB0: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039CB4: addiu       $a0, $a0, 0x74E0
    ctx->r4 = ADD32(ctx->r4, 0X74E0);
    // 0x80039CB8: jal         0x80039ABC
    // 0x80039CBC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80039ABC(rdram, ctx);
        goto after_1;
    // 0x80039CBC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80039CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039CC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039CC8: jr          $ra
    // 0x80039CCC: nop

    return;
    // 0x80039CCC: nop

;}
RECOMP_FUNC void func_8057BC88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BC88: lbu         $t6, 0x158($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X158);
    // 0x8057BC8C: bnel        $t6, $zero, L_8057BCA0
    if (ctx->r14 != 0) {
        // 0x8057BC90: lw          $t7, 0x154($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X154);
            goto L_8057BCA0;
    }
    goto skip_0;
    // 0x8057BC90: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
    skip_0:
    // 0x8057BC94: jr          $ra
    // 0x8057BC98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x8057BC98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8057BC9C: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
L_8057BCA0:
    // 0x8057BCA0: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x8057BCA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8057BCA8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8057BCAC: sw          $t8, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r24;
    // 0x8057BCB0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8057BCB4: sltu        $at, $t8, $t1
    ctx->r1 = ctx->r24 < ctx->r9 ? 1 : 0;
    // 0x8057BCB8: bne         $at, $zero, L_8057BCEC
    if (ctx->r1 != 0) {
        // 0x8057BCBC: nop
    
            goto L_8057BCEC;
    }
    // 0x8057BCBC: nop

    // 0x8057BCC0: lbu         $t2, 0x158($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X158);
    // 0x8057BCC4: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8057BCC8: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8057BCCC: bne         $t4, $zero, L_8057BCDC
    if (ctx->r12 != 0) {
        // 0x8057BCD0: sb          $t3, 0x158($a0)
        MEM_B(0X158, ctx->r4) = ctx->r11;
            goto L_8057BCDC;
    }
    // 0x8057BCD0: sb          $t3, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r11;
    // 0x8057BCD4: jr          $ra
    // 0x8057BCD8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x8057BCD8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8057BCDC:
    // 0x8057BCDC: lw          $t5, 0x14C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14C);
    // 0x8057BCE0: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8057BCE4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8057BCE8: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
L_8057BCEC:
    // 0x8057BCEC: jr          $ra
    // 0x8057BCF0: nop

    return;
    // 0x8057BCF0: nop

;}
RECOMP_FUNC void func_8003F660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F660: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003F664: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003F668: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003F66C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003F670: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003F674: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8003F678: jal         0x8003EBD4
    // 0x8003F67C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003EBD4(rdram, ctx);
        goto after_0;
    // 0x8003F67C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8003F680: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003F684: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x8003F688: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x8003F68C: jalr        $t9
    // 0x8003F690: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8003F690: nop

    after_1:
    // 0x8003F694: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003F698: addiu       $t6, $t6, -0x1A14
    ctx->r14 = ADD32(ctx->r14, -0X1A14);
    // 0x8003F69C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F6A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F6A4: lhu         $a1, 0x2A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X2A);
    // 0x8003F6A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003F6AC: jal         0x8003E6C4
    // 0x8003F6B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8003E6C4(rdram, ctx);
        goto after_2;
    // 0x8003F6B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8003F6B4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8003F6B8: addiu       $a2, $a2, -0x7C48
    ctx->r6 = ADD32(ctx->r6, -0X7C48);
    // 0x8003F6BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003F6C0: jal         0x8003F14C
    // 0x8003F6C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8003F14C(rdram, ctx);
        goto after_3;
    // 0x8003F6C4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8003F6C8: jal         0x800447C8
    // 0x8003F6CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x8003F6CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8003F6D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003F6D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003F6D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003F6DC: jr          $ra
    // 0x8003F6E0: nop

    return;
    // 0x8003F6E0: nop

;}
RECOMP_FUNC void func_806F3A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F3A1C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806F3A20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F3A24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F3A28: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x806F3A2C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x806F3A30: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F3A34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F3A38: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x806F3A3C: bne         $t6, $zero, L_806F3A7C
    if (ctx->r14 != 0) {
        // 0x806F3A40: lui         $t8, 0x806F
        ctx->r24 = S32(RELOC_HI16(682, 0X900) << 16);
            goto L_806F3A7C;
    }
    // 0x806F3A40: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(682, 0X900) << 16);
    // 0x806F3A44: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x806F3A48: sw          $t7, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r15;
    // 0x806F3A4C: addiu       $t8, $t8, 0x3D50
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(682, 0X900));
    // 0x806F3A50: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806F3A54: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x806F3A58: jal         0x80045A34
    // 0x806F3A5C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806F3A5C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x806F3A60: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x806F3A64: bne         $v0, $zero, L_806F3A7C
    if (ctx->r2 != 0) {
        // 0x806F3A68: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_806F3A7C;
    }
    // 0x806F3A68: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806F3A6C: jal         0x800445A4
    // 0x806F3A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806F3A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F3A74: b           L_806F3B14
    // 0x806F3A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F3B14;
    // 0x806F3A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F3A7C:
    // 0x806F3A7C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x806F3A80: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x806F3A84: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x806F3A88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F3A8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806F3A90: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X908) << 16);
    // 0x806F3A94: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x806F3A98: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x806F3A9C: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x806F3AA0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x806F3AA4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806F3AA8: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x806F3AAC: lwc1        $f0, 0x3D58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X908));
    // 0x806F3AB0: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x806F3AB4: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x806F3AB8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x806F3ABC: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x806F3AC0: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x806F3AC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806F3AC8: jal         0x80065490
    // 0x806F3ACC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x806F3ACC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_2:
    // 0x806F3AD0: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x806F3AD4: jal         0x80065490
    // 0x806F3AD8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x806F3AD8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x806F3ADC: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x806F3AE0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x806F3AE4: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x806F3AE8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x806F3AEC: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806F3AF0: sw          $t2, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->r10;
    // 0x806F3AF4: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x806F3AF8: lhu         $t6, 0xC($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0XC);
    // 0x806F3AFC: bnel        $t6, $at, L_806F3B14
    if (ctx->r14 != ctx->r1) {
        // 0x806F3B00: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806F3B14;
    }
    goto skip_0;
    // 0x806F3B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x806F3B04: lw          $t7, 0x1F4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X1F4);
    // 0x806F3B08: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x806F3B0C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x806F3B10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806F3B14:
    // 0x806F3B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F3B18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F3B1C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x806F3B20: jr          $ra
    // 0x806F3B24: nop

    return;
    // 0x806F3B24: nop

;}
RECOMP_FUNC void func_8000AA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AA84: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x8000AA88: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8000AA8C: sltiu       $at, $t7, 0xB
    ctx->r1 = ctx->r15 < 0XB ? 1 : 0;
    // 0x8000AA90: beq         $at, $zero, L_8000ABE4
    if (ctx->r1 == 0) {
        // 0x8000AA94: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8000ABE4;
    }
    // 0x8000AA94: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000AA98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000AA9C: addu        $at, $at, $t7
    gpr jr_addend_8000AAA4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8000AAA0: lw          $t7, -0x4320($at)
    ctx->r15 = ADD32(ctx->r1, -0X4320);
    // 0x8000AAA4: jr          $t7
    // 0x8000AAA8: nop

    switch (jr_addend_8000AAA4 >> 2) {
        case 0: goto L_8000AAAC; break;
        case 1: goto L_8000AAD8; break;
        case 2: goto L_8000AB04; break;
        case 3: goto L_8000AB28; break;
        case 4: goto L_8000AB54; break;
        case 5: goto L_8000AB6C; break;
        case 6: goto L_8000ABE4; break;
        case 7: goto L_8000AB8C; break;
        case 8: goto L_8000ABAC; break;
        case 9: goto L_8000ABB8; break;
        case 10: goto L_8000ABD0; break;
        default: switch_error(__func__, 0x8000AAA4, 0x800ABCE0);
    }
    // 0x8000AAA8: nop

L_8000AAAC:
    // 0x8000AAAC: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000AAB0: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8000AAB4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8000AAB8: nop

    // 0x8000AABC: bc1t        L_8000ABE4
    if (c1cs) {
        // 0x8000AAC0: nop
    
            goto L_8000ABE4;
    }
    // 0x8000AAC0: nop

    // 0x8000AAC4: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8000AAC8: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x8000AACC: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x8000AAD0: jr          $ra
    // 0x8000AAD4: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
    return;
    // 0x8000AAD4: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
L_8000AAD8:
    // 0x8000AAD8: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000AADC: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8000AAE0: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8000AAE4: nop

    // 0x8000AAE8: bc1t        L_8000ABE4
    if (c1cs) {
        // 0x8000AAEC: nop
    
            goto L_8000ABE4;
    }
    // 0x8000AAEC: nop

    // 0x8000AAF0: lbu         $t2, 0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X1);
    // 0x8000AAF4: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8000AAF8: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x8000AAFC: jr          $ra
    // 0x8000AB00: sb          $t3, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r11;
    return;
    // 0x8000AB00: sb          $t3, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r11;
L_8000AB04:
    // 0x8000AB04: lb          $v0, 0x4($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X4);
    // 0x8000AB08: lbu         $t4, 0xA($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XA);
    // 0x8000AB0C: beq         $v0, $t4, L_8000ABE4
    if (ctx->r2 == ctx->r12) {
        // 0x8000AB10: nop
    
            goto L_8000ABE4;
    }
    // 0x8000AB10: nop

    // 0x8000AB14: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x8000AB18: sb          $v0, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r2;
    // 0x8000AB1C: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8000AB20: jr          $ra
    // 0x8000AB24: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    return;
    // 0x8000AB24: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
L_8000AB28:
    // 0x8000AB28: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000AB2C: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8000AB30: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x8000AB34: nop

    // 0x8000AB38: bc1t        L_8000ABE4
    if (c1cs) {
        // 0x8000AB3C: nop
    
            goto L_8000ABE4;
    }
    // 0x8000AB3C: nop

    // 0x8000AB40: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8000AB44: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8000AB48: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8000AB4C: jr          $ra
    // 0x8000AB50: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
    return;
    // 0x8000AB50: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
L_8000AB54:
    // 0x8000AB54: lb          $v0, 0x4($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X4);
    // 0x8000AB58: lbu         $t1, 0x4($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X4);
    // 0x8000AB5C: beq         $v0, $t1, L_8000ABE4
    if (ctx->r2 == ctx->r9) {
        // 0x8000AB60: nop
    
            goto L_8000ABE4;
    }
    // 0x8000AB60: nop

    // 0x8000AB64: jr          $ra
    // 0x8000AB68: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    return;
    // 0x8000AB68: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
L_8000AB6C:
    // 0x8000AB6C: lbu         $v0, 0x3($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3);
    // 0x8000AB70: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8000AB74: beq         $at, $zero, L_8000ABE4
    if (ctx->r1 == 0) {
        // 0x8000AB78: nop
    
            goto L_8000ABE4;
    }
    // 0x8000AB78: nop

    // 0x8000AB7C: lb          $t2, 0x4($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X4);
    // 0x8000AB80: addu        $t3, $a0, $v0
    ctx->r11 = ADD32(ctx->r4, ctx->r2);
    // 0x8000AB84: jr          $ra
    // 0x8000AB88: sb          $t2, 0xCC($t3)
    MEM_B(0XCC, ctx->r11) = ctx->r10;
    return;
    // 0x8000AB88: sb          $t2, 0xCC($t3)
    MEM_B(0XCC, ctx->r11) = ctx->r10;
L_8000AB8C:
    // 0x8000AB8C: lb          $t5, 0x4($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X4);
    // 0x8000AB90: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x8000AB94: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8000AB98: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8000AB9C: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x8000ABA0: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8000ABA4: jr          $ra
    // 0x8000ABA8: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    return;
    // 0x8000ABA8: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
L_8000ABAC:
    // 0x8000ABAC: lb          $t1, 0x4($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X4);
    // 0x8000ABB0: jr          $ra
    // 0x8000ABB4: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
    return;
    // 0x8000ABB4: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
L_8000ABB8:
    // 0x8000ABB8: lbu         $t2, 0x4($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X4);
    // 0x8000ABBC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000ABC0: sh          $t4, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r12;
    // 0x8000ABC4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8000ABC8: jr          $ra
    // 0x8000ABCC: sh          $t3, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r11;
    return;
    // 0x8000ABCC: sh          $t3, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r11;
L_8000ABD0:
    // 0x8000ABD0: lbu         $t5, 0x4($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X4);
    // 0x8000ABD4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000ABD8: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x8000ABDC: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x8000ABE0: sh          $t6, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r14;
L_8000ABE4:
    // 0x8000ABE4: jr          $ra
    // 0x8000ABE8: nop

    return;
    // 0x8000ABE8: nop

;}
RECOMP_FUNC void func_8073E8FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073E8FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073E900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073E904: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8073E908: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8073E90C: jal         0x800447C8
    // 0x8073E910: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x8073E910: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8073E914: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8073E918: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8073E91C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8073E920: lui         $a2, 0x8074
    ctx->r6 = S32(RELOC_HI16(748, 0X2354) << 16);
    // 0x8073E924: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8073E928: addiu       $a2, $a2, 0xB44
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(748, 0X2354));
    // 0x8073E92C: addiu       $a0, $zero, 0x4008
    ctx->r4 = ADD32(0, 0X4008);
    // 0x8073E930: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8073E934: addiu       $a1, $a3, 0x84
    ctx->r5 = ADD32(ctx->r7, 0X84);
    // 0x8073E938: jalr        $t9
    // 0x8073E93C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8073E93C: nop

    after_1:
    // 0x8073E940: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8073E944: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8073E948: beql        $v1, $zero, L_8073E960
    if (ctx->r3 == 0) {
        // 0x8073E94C: lw          $a0, 0x34($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X34);
            goto L_8073E960;
    }
    goto skip_0;
    // 0x8073E94C: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    skip_0:
    // 0x8073E950: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x8073E954: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8073E958: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8073E95C: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
L_8073E960:
    // 0x8073E960: jal         0x80067BBC
    // 0x8073E964: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8073E964: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x8073E968: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8073E96C: jal         0x80067818
    // 0x8073E970: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8073E970: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8073E974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073E978: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073E97C: jr          $ra
    // 0x8073E980: nop

    return;
    // 0x8073E980: nop

;}
RECOMP_FUNC void func_8000A340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A348: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A34C: jal         0x8000A2F4
    // 0x8000A350: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8000A2F4(rdram, ctx);
        goto after_0;
    // 0x8000A350: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8000A354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A35C: jr          $ra
    // 0x8000A360: nop

    return;
    // 0x8000A360: nop

;}
RECOMP_FUNC void func_804CE8CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE8CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CE8D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CE8D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CE8D8: jal         0x80045A34
    // 0x804CE8DC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804CE8DC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x804CE8E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CE8E4: bne         $v0, $zero, L_804CE8F4
    if (ctx->r2 != 0) {
        // 0x804CE8E8: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804CE8F4;
    }
    // 0x804CE8E8: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804CE8EC: b           L_804CE900
    // 0x804CE8F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CE900;
    // 0x804CE8F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CE8F4:
    // 0x804CE8F4: jal         0x804CE8AC
    // 0x804CE8F8: nop

    func_804CE8AC(rdram, ctx);
        goto after_1;
    // 0x804CE8F8: nop

    after_1:
    // 0x804CE8FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804CE900:
    // 0x804CE900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CE904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CE908: jr          $ra
    // 0x804CE90C: nop

    return;
    // 0x804CE90C: nop

;}
RECOMP_FUNC void func_8052764C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052764C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527654: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80527658: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8052765C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80527660: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80527664: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80527668: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8052766C: nop

    // 0x80527670: bc1fl       L_805276C4
    if (!c1cs) {
        // 0x80527674: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_805276C4;
    }
    goto skip_0;
    // 0x80527674: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80527678: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x8052767C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80527680: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80527684: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80527688: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x8052768C: bne         $at, $zero, L_805276A4
    if (ctx->r1 != 0) {
        // 0x80527690: swc1        $f6, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
            goto L_805276A4;
    }
    // 0x80527690: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x80527694: jal         0x805276E0
    // 0x80527698: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_805276E0(rdram, ctx);
        goto after_0;
    // 0x80527698: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8052769C: b           L_805276D4
    // 0x805276A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805276D4;
    // 0x805276A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805276A4:
    // 0x805276A4: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x805276A8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x805276AC: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x805276B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805276B4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x805276B8: b           L_805276D0
    // 0x805276BC: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_805276D0;
    // 0x805276BC: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x805276C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_805276C4:
    // 0x805276C4: nop

    // 0x805276C8: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x805276CC: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_805276D0:
    // 0x805276D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805276D4:
    // 0x805276D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805276D8: jr          $ra
    // 0x805276DC: nop

    return;
    // 0x805276DC: nop

;}
RECOMP_FUNC void func_806D3DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3DC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D3DC4: jr          $ra
    // 0x806D3DC8: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x806D3DC8: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80421C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421C00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80421C04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80421C08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80421C0C: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x80421C10: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80421C14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80421C18: bnel        $t6, $at, L_80421C44
    if (ctx->r14 != ctx->r1) {
        // 0x80421C1C: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_80421C44;
    }
    goto skip_0;
    // 0x80421C1C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80421C20: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80421C24: jal         0x80067BBC
    // 0x80421C28: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80421C28: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x80421C2C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80421C30: jal         0x80067F78
    // 0x80421C34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80421C34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80421C38: b           L_80421C5C
    // 0x80421C3C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80421C5C;
    // 0x80421C3C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x80421C40: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_80421C44:
    // 0x80421C44: jal         0x80067BBC
    // 0x80421C48: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80421C48: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80421C4C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80421C50: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80421C54: jal         0x800678F0
    // 0x80421C58: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x80421C58: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_80421C5C:
    // 0x80421C5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80421C60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80421C64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80421C68: jr          $ra
    // 0x80421C6C: nop

    return;
    // 0x80421C6C: nop

;}
RECOMP_FUNC void func_80034174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003417C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80034180: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80034184: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80034188: lbu         $t6, 0xF5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF5);
    // 0x8003418C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80034190: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80034194: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80034198: lwc1        $f0, -0x1584($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1584);
    // 0x8003419C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800341A0: nop

    // 0x800341A4: bc1f        L_800341C4
    if (!c1cs) {
        // 0x800341A8: nop
    
            goto L_800341C4;
    }
    // 0x800341A8: nop

    // 0x800341AC: jal         0x8002DB14
    // 0x800341B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002DB14(rdram, ctx);
        goto after_0;
    // 0x800341B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800341B4: jal         0x80034160
    // 0x800341B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80034160(rdram, ctx);
        goto after_1;
    // 0x800341B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800341BC: b           L_800341FC
    // 0x800341C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800341FC;
    // 0x800341C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800341C4:
    // 0x800341C4: lbu         $t8, -0x766B($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X766B);
    // 0x800341C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800341CC: bne         $t8, $zero, L_800341EC
    if (ctx->r24 != 0) {
        // 0x800341D0: nop
    
            goto L_800341EC;
    }
    // 0x800341D0: nop

    // 0x800341D4: jal         0x8002DB14
    // 0x800341D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002DB14(rdram, ctx);
        goto after_2;
    // 0x800341D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x800341DC: jal         0x80034160
    // 0x800341E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80034160(rdram, ctx);
        goto after_3;
    // 0x800341E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800341E4: b           L_800341FC
    // 0x800341E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800341FC;
    // 0x800341E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800341EC:
    // 0x800341EC: lwc1        $f6, 0x98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X98);
    // 0x800341F0: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    // 0x800341F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800341F8: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
L_800341FC:
    // 0x800341FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034204: jr          $ra
    // 0x80034208: nop

    return;
    // 0x80034208: nop

;}
RECOMP_FUNC void func_805A42E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A42E0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A42E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805A42E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A42EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x805A42F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805A42F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805A42F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805A42FC: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1D90) << 16);
    // 0x805A4300: sh          $t6, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r14;
    // 0x805A4304: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x805A4308: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x805A430C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x805A4310: lwc1        $f10, 0x5120($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1D90));
    // 0x805A4314: jr          $ra
    // 0x805A4318: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x805A4318: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_807BC180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BC184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BC188: jal         0x80059278
    // 0x807BC18C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80059278(rdram, ctx);
        goto after_0;
    // 0x807BC18C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807BC190: bne         $v0, $zero, L_807BC1B8
    if (ctx->r2 != 0) {
        // 0x807BC194: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807BC1B8;
    }
    // 0x807BC194: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807BC198: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x807BC19C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x807BC1A0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807BC1A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BC1A8: jal         0x807BC4D4
    // 0x807BC1AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_807BC4D4(rdram, ctx);
        goto after_1;
    // 0x807BC1AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x807BC1B0: b           L_807BC1BC
    // 0x807BC1B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807BC1BC;
    // 0x807BC1B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807BC1B8:
    // 0x807BC1B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807BC1BC:
    // 0x807BC1BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BC1C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BC1C4: jr          $ra
    // 0x807BC1C8: nop

    return;
    // 0x807BC1C8: nop

;}
RECOMP_FUNC void func_8052746C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052746C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527474: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80527478: jal         0x800653D8
    // 0x8052747C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8052747C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80527480: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80527484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80527488: beq         $t6, $zero, L_805274A0
    if (ctx->r14 == 0) {
        // 0x8052748C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_805274A0;
    }
    // 0x8052748C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80527490: jal         0x805269F8
    // 0x80527494: nop

    func_805269F8(rdram, ctx);
        goto after_1;
    // 0x80527494: nop

    after_1:
    // 0x80527498: b           L_805274AC
    // 0x8052749C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805274AC;
    // 0x8052749C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805274A0:
    // 0x805274A0: jal         0x80526DE8
    // 0x805274A4: nop

    func_80526DE8(rdram, ctx);
        goto after_2;
    // 0x805274A4: nop

    after_2:
    // 0x805274A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805274AC:
    // 0x805274AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805274B0: jr          $ra
    // 0x805274B4: nop

    return;
    // 0x805274B4: nop

;}
RECOMP_FUNC void func_80429F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429F8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429F94: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80429F98: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80429F9C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80429FA0: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(47, 0X9C8) << 16);
    // 0x80429FA4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80429FA8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80429FAC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80429FB0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80429FB4: lw          $t8, -0x5868($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(47, 0X9C8));
    // 0x80429FB8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80429FBC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80429FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80429FC4: jal         0x80048490
    // 0x80429FC8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80429FC8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80429FCC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80429FD0: jal         0x80048378
    // 0x80429FD4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80429FD4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80429FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80429FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80429FE0: jr          $ra
    // 0x80429FE4: nop

    return;
    // 0x80429FE4: nop

;}
RECOMP_FUNC void func_80046D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046D30: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80046D34: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x80046D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80046D40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80046D44: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80046D48: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80046D4C: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    // 0x80046D50: jal         0x80046C58
    // 0x80046D54: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    func_80046C58(rdram, ctx);
        goto after_0;
    // 0x80046D54: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    after_0:
    // 0x80046D58: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x80046D5C: beq         $v0, $zero, L_80046D6C
    if (ctx->r2 == 0) {
        // 0x80046D60: addiu       $t0, $t0, 0x7EA0
        ctx->r8 = ADD32(ctx->r8, 0X7EA0);
            goto L_80046D6C;
    }
    // 0x80046D60: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x80046D64: b           L_80046D84
    // 0x80046D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80046D84;
    // 0x80046D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80046D6C:
    // 0x80046D6C: lw          $a0, 0x9B0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X9B0);
    // 0x80046D70: lh          $a1, 0x9A6($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X9A6);
    // 0x80046D74: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80046D78: jal         0x80046C58
    // 0x80046D7C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    func_80046C58(rdram, ctx);
        goto after_1;
    // 0x80046D7C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80046D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80046D84:
    // 0x80046D84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046D88: jr          $ra
    // 0x80046D8C: nop

    return;
    // 0x80046D8C: nop

;}
RECOMP_FUNC void func_80029E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029E68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80029E6C: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80029E70: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80029E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029E78: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80029E7C: nop

    // 0x80029E80: bc1fl       L_80029EE8
    if (!c1cs) {
        // 0x80029E84: lw          $t9, 0x0($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X0);
            goto L_80029EE8;
    }
    goto skip_0;
    // 0x80029E84: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80029E88: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80029E8C: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80029E90: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80029E94: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80029E98: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80029E9C: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80029EA0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80029EA4: swc1        $f16, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f16.u32l;
    // 0x80029EA8: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80029EAC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80029EB0: nop

    // 0x80029EB4: bc1f        L_80029EDC
    if (!c1cs) {
        // 0x80029EB8: nop
    
            goto L_80029EDC;
    }
    // 0x80029EB8: nop

    // 0x80029EBC: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80029EC0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80029EC4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80029EC8: nop

    // 0x80029ECC: bc1fl       L_80029F38
    if (!c1cs) {
        // 0x80029ED0: lwc1        $f12, 0x8($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
            goto L_80029F38;
    }
    goto skip_1;
    // 0x80029ED0: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x80029ED4: b           L_80029F34
    // 0x80029ED8: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
        goto L_80029F34;
    // 0x80029ED8: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
L_80029EDC:
    // 0x80029EDC: b           L_80029F34
    // 0x80029EE0: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
        goto L_80029F34;
    // 0x80029EE0: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x80029EE4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
L_80029EE8:
    // 0x80029EE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80029EEC: lwc1        $f2, -0x1BC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X1BC);
    // 0x80029EF0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80029EF4: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
    // 0x80029EF8: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80029EFC: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80029F00: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80029F04: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80029F08: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80029F0C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80029F10: swc1        $f8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f8.u32l;
    // 0x80029F14: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80029F18: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80029F1C: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80029F20: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80029F24: nop

    // 0x80029F28: bc1fl       L_80029F38
    if (!c1cs) {
        // 0x80029F2C: lwc1        $f12, 0x8($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
            goto L_80029F38;
    }
    goto skip_2;
    // 0x80029F2C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    skip_2:
    // 0x80029F30: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
L_80029F34:
    // 0x80029F34: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
L_80029F38:
    // 0x80029F38: jal         0x8006C9DC
    // 0x80029F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8006C9DC(rdram, ctx);
        goto after_0;
    // 0x80029F3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80029F40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80029F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029F48: jal         0x8006CA74
    // 0x80029F4C: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    func_8006CA74(rdram, ctx);
        goto after_1;
    // 0x80029F4C: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    after_1:
    // 0x80029F50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80029F54: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80029F58: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80029F5C: swc1        $f18, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->f18.u32l;
    // 0x80029F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029F68: jr          $ra
    // 0x80029F6C: nop

    return;
    // 0x80029F6C: nop

;}
RECOMP_FUNC void func_80553DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553DAC: lw          $t6, 0xD88($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD88);
    // 0x80553DB0: lui         $t1, 0x8055
    ctx->r9 = S32(RELOC_HI16(354, 0X40B8) << 16);
    // 0x80553DB4: addiu       $v0, $a0, 0xD78
    ctx->r2 = ADD32(ctx->r4, 0XD78);
    // 0x80553DB8: bne         $t6, $zero, L_80553E34
    if (ctx->r14 != 0) {
        // 0x80553DBC: addiu       $t1, $t1, 0x4BD8
        ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(354, 0X40B8));
            goto L_80553E34;
    }
    // 0x80553DBC: addiu       $t1, $t1, 0x4BD8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(354, 0X40B8));
    // 0x80553DC0: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80553DC4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80553DC8: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x80553DCC: addiu       $a1, $t8, 0x1
    ctx->r5 = ADD32(ctx->r24, 0X1);
    // 0x80553DD0: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x80553DD4: bne         $at, $zero, L_80553DE4
    if (ctx->r1 != 0) {
        // 0x80553DD8: sw          $a1, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r5;
            goto L_80553DE4;
    }
    // 0x80553DD8: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x80553DDC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80553DE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80553DE4:
    // 0x80553DE4: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80553DE8: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x80553DEC: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80553DF0: addiu       $v1, $a0, 0xDA0
    ctx->r3 = ADD32(ctx->r4, 0XDA0);
    // 0x80553DF4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80553DF8: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80553DFC: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80553E00: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80553E04: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x80553E08: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80553E0C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80553E10: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80553E14: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80553E18: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x80553E1C: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x80553E20: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80553E24: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80553E28: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80553E2C: jr          $ra
    // 0x80553E30: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    return;
    // 0x80553E30: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80553E34:
    // 0x80553E34: addiu       $v0, $a0, 0xD78
    ctx->r2 = ADD32(ctx->r4, 0XD78);
    // 0x80553E38: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x80553E3C: addiu       $t4, $t5, -0x1
    ctx->r12 = ADD32(ctx->r13, -0X1);
    // 0x80553E40: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    // 0x80553E44: jr          $ra
    // 0x80553E48: nop

    return;
    // 0x80553E48: nop

;}
RECOMP_FUNC void func_806B1F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1F94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B1F98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B1F9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B1FA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B1FA4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B1FA8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B1FAC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B1FB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B1FB4: addiu       $t6, $zero, 0x1E00
    ctx->r14 = ADD32(0, 0X1E00);
    // 0x806B1FB8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B1FBC: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x806B1FC0: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x806B1FC4: addiu       $a1, $zero, 0x168
    ctx->r5 = ADD32(0, 0X168);
    // 0x806B1FC8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x806B1FCC: jal         0x806B195C
    // 0x806B1FD0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_806B195C(rdram, ctx);
        goto after_0;
    // 0x806B1FD0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806B1FD4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B1FD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1FDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B1FE0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B1FE4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806B1FE8: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B1FEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B1FF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B1FF4: jr          $ra
    // 0x806B1FF8: nop

    return;
    // 0x806B1FF8: nop

;}
RECOMP_FUNC void func_807B07B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B07B0: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x807B07B4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x807B07B8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x807B07BC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x807B07C0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x807B07C4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x807B07C8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x807B07CC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x807B07D0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x807B07D4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x807B07D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807B07DC: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x807B07E0: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B07E4: lui         $t0, 0x807B
    ctx->r8 = S32(RELOC_HI16(871, 0X3220) << 16);
    // 0x807B07E8: addiu       $t0, $t0, 0x2D70
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(871, 0X3220));
    // 0x807B07EC: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x807B07F0: addiu       $v0, $a3, 0x12C
    ctx->r2 = ADD32(ctx->r7, 0X12C);
    // 0x807B07F4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x807B07F8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x807B07FC: lui         $s4, 0x807B
    ctx->r20 = S32(RELOC_HI16(871, 0X32FC) << 16);
    // 0x807B0800: lui         $s5, 0x807B
    ctx->r21 = S32(RELOC_HI16(871, 0X3404) << 16);
    // 0x807B0804: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x807B0808: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807B080C: lh          $t8, 0x1C($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X1C);
    // 0x807B0810: addiu       $s4, $s4, 0x2E4C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(871, 0X32FC));
    // 0x807B0814: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x807B0818: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807B081C: addu        $t2, $a1, $t9
    ctx->r10 = ADD32(ctx->r5, ctx->r25);
    // 0x807B0820: lw          $a2, 0x10($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X10);
    // 0x807B0824: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x807B0828: addiu       $s5, $s5, 0x2F54
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(871, 0X3404));
    // 0x807B082C: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x807B0830: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
    // 0x807B0834: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807B0838: addiu       $s1, $a3, 0x178
    ctx->r17 = ADD32(ctx->r7, 0X178);
    // 0x807B083C: addiu       $s0, $a2, 0x20
    ctx->r16 = ADD32(ctx->r6, 0X20);
    // 0x807B0840: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x807B0844: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x807B0848: nop

    // 0x807B084C: sh          $t6, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r14;
    // 0x807B0850: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807B0854: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x807B0858: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x807B085C: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x807B0860: nop

    // 0x807B0864: sh          $t8, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r24;
    // 0x807B0868: lh          $t9, 0xD0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XD0);
    // 0x807B086C: sh          $t9, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r25;
    // 0x807B0870: lh          $t2, 0xD2($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XD2);
    // 0x807B0874: sb          $t1, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r9;
    // 0x807B0878: sb          $zero, 0xE($a2)
    MEM_B(0XE, ctx->r6) = 0;
    // 0x807B087C: sb          $zero, 0xD($a2)
    MEM_B(0XD, ctx->r6) = 0;
    // 0x807B0880: sb          $zero, 0xC($a2)
    MEM_B(0XC, ctx->r6) = 0;
    // 0x807B0884: sh          $t2, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r10;
    // 0x807B0888: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807B088C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x807B0890: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x807B0894: nop

    // 0x807B0898: sh          $t4, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r12;
    // 0x807B089C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807B08A0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x807B08A4: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x807B08A8: nop

    // 0x807B08AC: sh          $t6, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r14;
    // 0x807B08B0: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807B08B4: sh          $zero, 0x16($a2)
    MEM_H(0X16, ctx->r6) = 0;
    // 0x807B08B8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x807B08BC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x807B08C0: nop

    // 0x807B08C4: sh          $t8, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r24;
    // 0x807B08C8: lh          $t9, 0xD8($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XD8);
    // 0x807B08CC: sh          $t9, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r25;
    // 0x807B08D0: lh          $t2, 0xDA($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XDA);
    // 0x807B08D4: sb          $t1, 0x1F($a2)
    MEM_B(0X1F, ctx->r6) = ctx->r9;
    // 0x807B08D8: sb          $zero, 0x1E($a2)
    MEM_B(0X1E, ctx->r6) = 0;
    // 0x807B08DC: sb          $zero, 0x1D($a2)
    MEM_B(0X1D, ctx->r6) = 0;
    // 0x807B08E0: sb          $zero, 0x1C($a2)
    MEM_B(0X1C, ctx->r6) = 0;
    // 0x807B08E4: sh          $t2, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r10;
    // 0x807B08E8: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
    // 0x807B08EC: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x807B08F0: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
L_807B08F4:
    // 0x807B08F4: lw          $v1, 0xA8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA8);
    // 0x807B08F8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x807B08FC: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x807B0900: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x807B0904: addiu       $t8, $v1, 0x2
    ctx->r24 = ADD32(ctx->r3, 0X2);
    // 0x807B0908: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x807B090C: lw          $t4, 0x1F4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1F4);
    // 0x807B0910: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x807B0914: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807B0918: lw          $t5, 0x138($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X138);
    // 0x807B091C: lw          $s2, 0x0($t5)
    ctx->r18 = MEM_W(ctx->r13, 0X0);
    // 0x807B0920: bgez        $t0, L_807B0934
    if (SIGNED(ctx->r8) >= 0) {
        // 0x807B0924: andi        $t6, $t0, 0xF
        ctx->r14 = ctx->r8 & 0XF;
            goto L_807B0934;
    }
    // 0x807B0924: andi        $t6, $t0, 0xF
    ctx->r14 = ctx->r8 & 0XF;
    // 0x807B0928: beq         $t6, $zero, L_807B0934
    if (ctx->r14 == 0) {
        // 0x807B092C: nop
    
            goto L_807B0934;
    }
    // 0x807B092C: nop

    // 0x807B0930: addiu       $t6, $t6, -0x10
    ctx->r14 = ADD32(ctx->r14, -0X10);
L_807B0934:
    // 0x807B0934: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B0938: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x807B093C: mflo        $t7
    ctx->r15 = lo;
    // 0x807B0940: addu        $s6, $v0, $t7
    ctx->r22 = ADD32(ctx->r2, ctx->r15);
    // 0x807B0944: bgez        $t8, L_807B0958
    if (SIGNED(ctx->r24) >= 0) {
        // 0x807B0948: andi        $t9, $t8, 0xF
        ctx->r25 = ctx->r24 & 0XF;
            goto L_807B0958;
    }
    // 0x807B0948: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x807B094C: beq         $t9, $zero, L_807B0958
    if (ctx->r25 == 0) {
        // 0x807B0950: nop
    
            goto L_807B0958;
    }
    // 0x807B0950: nop

    // 0x807B0954: addiu       $t9, $t9, -0x10
    ctx->r25 = ADD32(ctx->r25, -0X10);
L_807B0958:
    // 0x807B0958: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B095C: mflo        $t2
    ctx->r10 = lo;
    // 0x807B0960: addu        $s7, $v0, $t2
    ctx->r23 = ADD32(ctx->r2, ctx->r10);
    // 0x807B0964: nop

L_807B0968:
    // 0x807B0968: addiu       $t3, $sp, 0x74
    ctx->r11 = ADD32(ctx->r29, 0X74);
    // 0x807B096C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x807B0970: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B0974: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x807B0978: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x807B097C: jal         0x8006671C
    // 0x807B0980: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    func_8006671C(rdram, ctx);
        goto after_0;
    // 0x807B0980: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_0:
    // 0x807B0984: lh          $t4, 0x74($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X74);
    // 0x807B0988: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x807B098C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x807B0990: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x807B0994: lh          $t5, 0x76($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X76);
    // 0x807B0998: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B099C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x807B09A0: sh          $t5, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r13;
    // 0x807B09A4: lh          $t6, 0x78($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X78);
    // 0x807B09A8: sh          $zero, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = 0;
    // 0x807B09AC: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x807B09B0: sh          $t6, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r14;
    // 0x807B09B4: lh          $t7, -0x4($s4)
    ctx->r15 = MEM_H(ctx->r20, -0X4);
    // 0x807B09B8: sh          $t7, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r15;
    // 0x807B09BC: lh          $t8, -0x2($s4)
    ctx->r24 = MEM_H(ctx->r20, -0X2);
    // 0x807B09C0: sh          $t8, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r24;
    // 0x807B09C4: lh          $t9, -0x8($s1)
    ctx->r25 = MEM_H(ctx->r17, -0X8);
    // 0x807B09C8: sb          $t9, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r25;
    // 0x807B09CC: lh          $t2, -0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, -0X6);
    // 0x807B09D0: sb          $t2, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r10;
    // 0x807B09D4: lh          $t3, -0x4($s1)
    ctx->r11 = MEM_H(ctx->r17, -0X4);
    // 0x807B09D8: sb          $t3, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r11;
    // 0x807B09DC: lh          $t4, -0x2($s1)
    ctx->r12 = MEM_H(ctx->r17, -0X2);
    // 0x807B09E0: bne         $s3, $fp, L_807B0968
    if (ctx->r19 != ctx->r30) {
        // 0x807B09E4: sb          $t4, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r12;
            goto L_807B0968;
    }
    // 0x807B09E4: sb          $t4, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r12;
    // 0x807B09E8: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x807B09EC: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x807B09F0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x807B09F4: addiu       $t6, $t5, 0x6
    ctx->r14 = ADD32(ctx->r13, 0X6);
    // 0x807B09F8: sw          $t6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r14;
    // 0x807B09FC: bne         $at, $zero, L_807B08F4
    if (ctx->r1 != 0) {
        // 0x807B0A00: sw          $v0, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r2;
            goto L_807B08F4;
    }
    // 0x807B0A00: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x807B0A04: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x807B0A08: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x807B0A0C: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x807B0A10: addiu       $t6, $v0, 0x2
    ctx->r14 = ADD32(ctx->r2, 0X2);
    // 0x807B0A14: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x807B0A18: lw          $t8, 0x1F4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1F4);
    // 0x807B0A1C: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x807B0A20: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x807B0A24: lw          $t9, 0x138($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X138);
    // 0x807B0A28: lw          $s2, 0x0($t9)
    ctx->r18 = MEM_W(ctx->r25, 0X0);
    // 0x807B0A2C: bgez        $t3, L_807B0A40
    if (SIGNED(ctx->r11) >= 0) {
        // 0x807B0A30: andi        $t4, $t3, 0xF
        ctx->r12 = ctx->r11 & 0XF;
            goto L_807B0A40;
    }
    // 0x807B0A30: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x807B0A34: beq         $t4, $zero, L_807B0A40
    if (ctx->r12 == 0) {
        // 0x807B0A38: nop
    
            goto L_807B0A40;
    }
    // 0x807B0A38: nop

    // 0x807B0A3C: addiu       $t4, $t4, -0x10
    ctx->r12 = ADD32(ctx->r12, -0X10);
L_807B0A40:
    // 0x807B0A40: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B0A44: addiu       $t9, $sp, 0x74
    ctx->r25 = ADD32(ctx->r29, 0X74);
    // 0x807B0A48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x807B0A4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B0A50: mflo        $t5
    ctx->r13 = lo;
    // 0x807B0A54: addu        $s6, $v1, $t5
    ctx->r22 = ADD32(ctx->r3, ctx->r13);
    // 0x807B0A58: bgez        $t6, L_807B0A6C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x807B0A5C: andi        $t7, $t6, 0xF
        ctx->r15 = ctx->r14 & 0XF;
            goto L_807B0A6C;
    }
    // 0x807B0A5C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x807B0A60: beq         $t7, $zero, L_807B0A6C
    if (ctx->r15 == 0) {
        // 0x807B0A64: nop
    
            goto L_807B0A6C;
    }
    // 0x807B0A64: nop

    // 0x807B0A68: addiu       $t7, $t7, -0x10
    ctx->r15 = ADD32(ctx->r15, -0X10);
L_807B0A6C:
    // 0x807B0A6C: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B0A70: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x807B0A74: mflo        $t8
    ctx->r24 = lo;
    // 0x807B0A78: addu        $a3, $v1, $t8
    ctx->r7 = ADD32(ctx->r3, ctx->r24);
    // 0x807B0A7C: jal         0x8006671C
    // 0x807B0A80: nop

    func_8006671C(rdram, ctx);
        goto after_1;
    // 0x807B0A80: nop

    after_1:
    // 0x807B0A84: lh          $t2, 0x74($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X74);
    // 0x807B0A88: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B0A8C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x807B0A90: sh          $t2, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r10;
    // 0x807B0A94: lh          $t3, 0x76($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X76);
    // 0x807B0A98: sh          $t3, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r11;
    // 0x807B0A9C: lh          $t4, 0x78($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X78);
    // 0x807B0AA0: sh          $zero, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = 0;
    // 0x807B0AA4: sh          $t4, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r12;
    // 0x807B0AA8: lh          $t5, 0x4($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X4);
    // 0x807B0AAC: sh          $t5, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r13;
    // 0x807B0AB0: lh          $t6, 0x6($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X6);
    // 0x807B0AB4: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x807B0AB8: sh          $t6, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r14;
    // 0x807B0ABC: lh          $t7, -0x8($s1)
    ctx->r15 = MEM_H(ctx->r17, -0X8);
    // 0x807B0AC0: sb          $t7, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r15;
    // 0x807B0AC4: lh          $t8, -0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, -0X6);
    // 0x807B0AC8: sb          $t8, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r24;
    // 0x807B0ACC: lh          $t9, -0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, -0X4);
    // 0x807B0AD0: sb          $t9, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r25;
    // 0x807B0AD4: lh          $t2, -0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, -0X2);
    // 0x807B0AD8: sb          $t2, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r10;
    // 0x807B0ADC: sw          $zero, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = 0;
L_807B0AE0:
    // 0x807B0AE0: lw          $v0, 0xA8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA8);
    // 0x807B0AE4: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x807B0AE8: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x807B0AEC: addiu       $t7, $v0, 0x9
    ctx->r15 = ADD32(ctx->r2, 0X9);
    // 0x807B0AF0: addiu       $t2, $v0, 0xA
    ctx->r10 = ADD32(ctx->r2, 0XA);
    // 0x807B0AF4: lw          $t4, 0x1F4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1F4);
    // 0x807B0AF8: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x807B0AFC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x807B0B00: lw          $t5, 0x138($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X138);
    // 0x807B0B04: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x807B0B08: lw          $s2, 0x0($t5)
    ctx->r18 = MEM_W(ctx->r13, 0X0);
    // 0x807B0B0C: bgez        $t7, L_807B0B20
    if (SIGNED(ctx->r15) >= 0) {
        // 0x807B0B10: andi        $t8, $t7, 0xF
        ctx->r24 = ctx->r15 & 0XF;
            goto L_807B0B20;
    }
    // 0x807B0B10: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x807B0B14: beq         $t8, $zero, L_807B0B20
    if (ctx->r24 == 0) {
        // 0x807B0B18: nop
    
            goto L_807B0B20;
    }
    // 0x807B0B18: nop

    // 0x807B0B1C: addiu       $t8, $t8, -0x10
    ctx->r24 = ADD32(ctx->r24, -0X10);
L_807B0B20:
    // 0x807B0B20: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B0B24: mflo        $t9
    ctx->r25 = lo;
    // 0x807B0B28: addu        $s6, $a1, $t9
    ctx->r22 = ADD32(ctx->r5, ctx->r25);
    // 0x807B0B2C: bgez        $t2, L_807B0B40
    if (SIGNED(ctx->r10) >= 0) {
        // 0x807B0B30: andi        $t3, $t2, 0xF
        ctx->r11 = ctx->r10 & 0XF;
            goto L_807B0B40;
    }
    // 0x807B0B30: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x807B0B34: beq         $t3, $zero, L_807B0B40
    if (ctx->r11 == 0) {
        // 0x807B0B38: nop
    
            goto L_807B0B40;
    }
    // 0x807B0B38: nop

    // 0x807B0B3C: addiu       $t3, $t3, -0x10
    ctx->r11 = ADD32(ctx->r11, -0X10);
L_807B0B40:
    // 0x807B0B40: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B0B44: mflo        $t4
    ctx->r12 = lo;
    // 0x807B0B48: addu        $s7, $a1, $t4
    ctx->r23 = ADD32(ctx->r5, ctx->r12);
    // 0x807B0B4C: nop

L_807B0B50:
    // 0x807B0B50: addiu       $t5, $sp, 0x74
    ctx->r13 = ADD32(ctx->r29, 0X74);
    // 0x807B0B54: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x807B0B58: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B0B5C: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x807B0B60: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x807B0B64: jal         0x8006671C
    // 0x807B0B68: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    func_8006671C(rdram, ctx);
        goto after_2;
    // 0x807B0B68: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_2:
    // 0x807B0B6C: lh          $t6, 0x74($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X74);
    // 0x807B0B70: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x807B0B74: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x807B0B78: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x807B0B7C: lh          $t7, 0x76($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X76);
    // 0x807B0B80: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B0B84: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x807B0B88: sh          $t7, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r15;
    // 0x807B0B8C: lh          $t8, 0x78($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X78);
    // 0x807B0B90: sh          $zero, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = 0;
    // 0x807B0B94: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x807B0B98: sh          $t8, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r24;
    // 0x807B0B9C: lh          $t9, -0x4($s5)
    ctx->r25 = MEM_H(ctx->r21, -0X4);
    // 0x807B0BA0: sh          $t9, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r25;
    // 0x807B0BA4: lh          $t2, -0x2($s5)
    ctx->r10 = MEM_H(ctx->r21, -0X2);
    // 0x807B0BA8: sh          $t2, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r10;
    // 0x807B0BAC: lh          $t3, -0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, -0X8);
    // 0x807B0BB0: sb          $t3, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r11;
    // 0x807B0BB4: lh          $t4, -0x6($s1)
    ctx->r12 = MEM_H(ctx->r17, -0X6);
    // 0x807B0BB8: sb          $t4, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r12;
    // 0x807B0BBC: lh          $t5, -0x4($s1)
    ctx->r13 = MEM_H(ctx->r17, -0X4);
    // 0x807B0BC0: sb          $t5, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r13;
    // 0x807B0BC4: lh          $t6, -0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, -0X2);
    // 0x807B0BC8: bne         $s3, $fp, L_807B0B50
    if (ctx->r19 != ctx->r30) {
        // 0x807B0BCC: sb          $t6, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r14;
            goto L_807B0B50;
    }
    // 0x807B0BCC: sb          $t6, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r14;
    // 0x807B0BD0: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x807B0BD4: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x807B0BD8: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x807B0BDC: addiu       $t8, $t7, 0x6
    ctx->r24 = ADD32(ctx->r15, 0X6);
    // 0x807B0BE0: sw          $t2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r10;
    // 0x807B0BE4: bne         $t2, $s4, L_807B0AE0
    if (ctx->r10 != ctx->r20) {
        // 0x807B0BE8: sw          $t8, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r24;
            goto L_807B0AE0;
    }
    // 0x807B0BE8: sw          $t8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r24;
    // 0x807B0BEC: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x807B0BF0: addiu       $t8, $t2, 0x9
    ctx->r24 = ADD32(ctx->r10, 0X9);
    // 0x807B0BF4: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x807B0BF8: lw          $t4, 0x1F4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1F4);
    // 0x807B0BFC: or          $t7, $t2, $zero
    ctx->r15 = ctx->r10 | 0;
    // 0x807B0C00: addiu       $t3, $t7, 0xA
    ctx->r11 = ADD32(ctx->r15, 0XA);
    // 0x807B0C04: lw          $t5, 0x138($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X138);
    // 0x807B0C08: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x807B0C0C: addiu       $t6, $sp, 0x74
    ctx->r14 = ADD32(ctx->r29, 0X74);
    // 0x807B0C10: lw          $s2, 0x0($t5)
    ctx->r18 = MEM_W(ctx->r13, 0X0);
    // 0x807B0C14: bgez        $t8, L_807B0C28
    if (SIGNED(ctx->r24) >= 0) {
        // 0x807B0C18: andi        $t9, $t8, 0xF
        ctx->r25 = ctx->r24 & 0XF;
            goto L_807B0C28;
    }
    // 0x807B0C18: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x807B0C1C: beq         $t9, $zero, L_807B0C28
    if (ctx->r25 == 0) {
        // 0x807B0C20: nop
    
            goto L_807B0C28;
    }
    // 0x807B0C20: nop

    // 0x807B0C24: addiu       $t9, $t9, -0x10
    ctx->r25 = ADD32(ctx->r25, -0X10);
L_807B0C28:
    // 0x807B0C28: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x807B0C2C: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x807B0C30: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x807B0C34: addu        $s6, $a1, $t2
    ctx->r22 = ADD32(ctx->r5, ctx->r10);
    // 0x807B0C38: bgez        $t3, L_807B0C4C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x807B0C3C: andi        $t4, $t3, 0xF
        ctx->r12 = ctx->r11 & 0XF;
            goto L_807B0C4C;
    }
    // 0x807B0C3C: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x807B0C40: beq         $t4, $zero, L_807B0C4C
    if (ctx->r12 == 0) {
        // 0x807B0C44: nop
    
            goto L_807B0C4C;
    }
    // 0x807B0C44: nop

    // 0x807B0C48: addiu       $t4, $t4, -0x10
    ctx->r12 = ADD32(ctx->r12, -0X10);
L_807B0C4C:
    // 0x807B0C4C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x807B0C50: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x807B0C54: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x807B0C58: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x807B0C5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807B0C60: addu        $a3, $a1, $t5
    ctx->r7 = ADD32(ctx->r5, ctx->r13);
    // 0x807B0C64: jal         0x8006671C
    // 0x807B0C68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8006671C(rdram, ctx);
        goto after_3;
    // 0x807B0C68: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x807B0C6C: lh          $t8, 0x74($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X74);
    // 0x807B0C70: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x807B0C74: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x807B0C78: lh          $t9, 0x76($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X76);
    // 0x807B0C7C: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x807B0C80: lh          $t2, 0x78($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X78);
    // 0x807B0C84: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x807B0C88: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    // 0x807B0C8C: lh          $t7, 0x4($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X4);
    // 0x807B0C90: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x807B0C94: lh          $t3, 0x6($s5)
    ctx->r11 = MEM_H(ctx->r21, 0X6);
    // 0x807B0C98: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x807B0C9C: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x807B0CA0: sb          $t4, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r12;
    // 0x807B0CA4: lh          $t5, 0x2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2);
    // 0x807B0CA8: sb          $t5, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r13;
    // 0x807B0CAC: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x807B0CB0: sb          $t6, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r14;
    // 0x807B0CB4: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x807B0CB8: sb          $t8, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r24;
    // 0x807B0CBC: lh          $t2, 0x1C($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1C);
    // 0x807B0CC0: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x807B0CC4: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x807B0CC8: sh          $t7, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r15;
    // 0x807B0CCC: lh          $t3, 0x1C($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X1C);
    // 0x807B0CD0: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    // 0x807B0CD4: slti        $at, $t3, 0x3
    ctx->r1 = SIGNED(ctx->r11) < 0X3 ? 1 : 0;
    // 0x807B0CD8: bnel        $at, $zero, L_807B0CE8
    if (ctx->r1 != 0) {
        // 0x807B0CDC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_807B0CE8;
    }
    goto skip_0;
    // 0x807B0CDC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x807B0CE0: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
    // 0x807B0CE4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_807B0CE8:
    // 0x807B0CE8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807B0CEC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x807B0CF0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x807B0CF4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x807B0CF8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x807B0CFC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x807B0D00: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x807B0D04: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x807B0D08: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x807B0D0C: jr          $ra
    // 0x807B0D10: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x807B0D10: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_806F5458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F545C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F5460: jal         0x800447C8
    // 0x806F5464: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x806F5464: nop

    after_0:
    // 0x806F5468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F546C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F5470: jr          $ra
    // 0x806F5474: nop

    return;
    // 0x806F5474: nop

;}
RECOMP_FUNC void func_80790818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079081C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80790820: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80790824: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80790828: lh          $a2, 0x1F0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1F0);
    // 0x8079082C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80790830: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80790834: beq         $a2, $at, L_80790868
    if (ctx->r6 == ctx->r1) {
        // 0x80790838: sll         $a1, $a2, 16
        ctx->r5 = S32(ctx->r6 << 16);
            goto L_80790868;
    }
    // 0x80790838: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x8079083C: jal         0x80067930
    // 0x80790840: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80790840: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_0:
    // 0x80790844: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80790848: bne         $v0, $at, L_80790868
    if (ctx->r2 != ctx->r1) {
        // 0x8079084C: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80790868;
    }
    // 0x8079084C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80790850: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80790854: jal         0x80067878
    // 0x80790858: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80790858: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    after_1:
    // 0x8079085C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80790860: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80790864: sh          $t8, 0x1F0($t9)
    MEM_H(0X1F0, ctx->r25) = ctx->r24;
L_80790868:
    // 0x80790868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079086C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80790870: jr          $ra
    // 0x80790874: nop

    return;
    // 0x80790874: nop

;}
RECOMP_FUNC void func_8006D1C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D1C0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006D1C4: jr          $ra
    // 0x8006D1C8: sw          $zero, -0x7B34($at)
    MEM_W(-0X7B34, ctx->r1) = 0;
    return;
    // 0x8006D1C8: sw          $zero, -0x7B34($at)
    MEM_W(-0X7B34, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80448684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448684: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80448688: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044868C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80448690: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80448694: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80448698: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044869C: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X13358) << 16);
    // 0x804486A0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804486A4: lw          $v1, 0x6CB0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CB0);
    // 0x804486A8: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x804486AC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x804486B0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x804486B4: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x804486B8: lw          $t0, 0x7738($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X13358));
    // 0x804486BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804486C0: beql        $t0, $zero, L_804486D4
    if (ctx->r8 == 0) {
        // 0x804486C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804486D4;
    }
    goto skip_0;
    // 0x804486C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804486C8: jalr        $t0
    // 0x804486CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x804486CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x804486D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804486D4:
    // 0x804486D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804486D8: jr          $ra
    // 0x804486DC: nop

    return;
    // 0x804486DC: nop

;}
RECOMP_FUNC void func_804D87A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D87A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804D87AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804D87B0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804D87B4: jr          $ra
    // 0x804D87B8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x804D87B8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void func_80522ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522ABC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80522AC0: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(321, 0X72C) << 16);
    // 0x80522AC4: addiu       $t6, $t6, 0x29DC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(321, 0X72C));
    // 0x80522AC8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80522ACC: jr          $ra
    // 0x80522AD0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80522AD0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8044453C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044453C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80444540: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80444544: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80444548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044454C: sb          $zero, 0xF5C($v0)
    MEM_B(0XF5C, ctx->r2) = 0;
    // 0x80444550: jal         0x804444D4
    // 0x80444554: sb          $zero, 0xF5D($v0)
    MEM_B(0XF5D, ctx->r2) = 0;
    func_804444D4(rdram, ctx);
        goto after_0;
    // 0x80444554: sb          $zero, 0xF5D($v0)
    MEM_B(0XF5D, ctx->r2) = 0;
    after_0:
    // 0x80444558: jal         0x8006CFC0
    // 0x8044455C: nop

    func_8006CFC0(rdram, ctx);
        goto after_1;
    // 0x8044455C: nop

    after_1:
    // 0x80444560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80444564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80444568: jr          $ra
    // 0x8044456C: nop

    return;
    // 0x8044456C: nop

;}
RECOMP_FUNC void func_80454E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80454E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80454E88: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X1390C) << 16);
    // 0x80454E8C: jal         0x804547C0
    // 0x80454E90: lw          $a1, 0x7CEC($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X1390C));
    func_804547C0(rdram, ctx);
        goto after_0;
    // 0x80454E90: lw          $a1, 0x7CEC($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X1390C));
    after_0:
    // 0x80454E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80454E98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80454E9C: jr          $ra
    // 0x80454EA0: nop

    return;
    // 0x80454EA0: nop

;}
RECOMP_FUNC void func_80667D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80667D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80667D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80667D74: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80667D78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80667D7C: lui         $t7, 0x8066
    ctx->r15 = S32(RELOC_HI16(507, 0X1F0) << 16);
    // 0x80667D80: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80667D84: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80667D88: addiu       $t7, $t7, 0x7EC0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(507, 0X1F0));
    // 0x80667D8C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80667D90: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80667D94: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80667D98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80667D9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80667DA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80667DA4: jal         0x80667DCC
    // 0x80667DA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80667DCC(rdram, ctx);
        goto after_0;
    // 0x80667DA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80667DAC: jal         0x80667D30
    // 0x80667DB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80667D30(rdram, ctx);
        goto after_1;
    // 0x80667DB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80667DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80667DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80667DBC: jr          $ra
    // 0x80667DC0: nop

    return;
    // 0x80667DC0: nop

;}
RECOMP_FUNC void guS2DEmuBgRect1Cyc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083394: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80083398: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008339C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800833A0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800833A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800833A8: lhu         $t6, 0x1C($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X1C);
    // 0x800833AC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800833B0: addiu       $t1, $zero, -0x4
    ctx->r9 = ADD32(0, -0X4);
    // 0x800833B4: sh          $t6, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = ctx->r14;
    // 0x800833B8: lhu         $t5, 0x2($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X2);
    // 0x800833BC: lh          $t8, 0xC2($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XC2);
    // 0x800833C0: lhu         $ra, 0xA($s1)
    ctx->r31 = MEM_HU(ctx->r17, 0XA);
    // 0x800833C4: sll         $t7, $t5, 10
    ctx->r15 = S32(ctx->r13 << 10);
    // 0x800833C8: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x800833CC: lh          $s2, 0x1E($a1)
    ctx->r18 = MEM_H(ctx->r5, 0X1E);
    // 0x800833D0: mflo        $t9
    ctx->r25 = lo;
    // 0x800833D4: lhu         $v1, 0x6($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X6);
    // 0x800833D8: lhu         $t0, 0xE($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0XE);
    // 0x800833DC: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800833E0: and         $a2, $t6, $t1
    ctx->r6 = ctx->r14 & ctx->r9;
    // 0x800833E4: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x800833E8: sll         $a3, $t0, 16
    ctx->r7 = S32(ctx->r8 << 16);
    // 0x800833EC: sra         $t6, $t3, 16
    ctx->r14 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800833F0: subu        $a2, $v1, $a2
    ctx->r6 = SUB32(ctx->r3, ctx->r6);
    // 0x800833F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800833F8: bne         $t8, $zero, L_80083404
    if (ctx->r24 != 0) {
        // 0x800833FC: nop
    
            goto L_80083404;
    }
    // 0x800833FC: nop

    // 0x80083400: break       7
    do_break(2148021248);
L_80083404:
    // 0x80083404: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083408: bne         $t8, $at, L_8008341C
    if (ctx->r24 != ctx->r1) {
        // 0x8008340C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008341C;
    }
    // 0x8008340C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80083410: bne         $t7, $at, L_8008341C
    if (ctx->r15 != ctx->r1) {
        // 0x80083414: nop
    
            goto L_8008341C;
    }
    // 0x80083414: nop

    // 0x80083418: break       6
    do_break(2148021272);
L_8008341C:
    // 0x8008341C: sll         $t7, $ra, 10
    ctx->r15 = S32(ctx->r31 << 10);
    // 0x80083420: div         $zero, $t7, $s2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r18)));
    // 0x80083424: mflo        $t8
    ctx->r24 = lo;
    // 0x80083428: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8008342C: bne         $s2, $zero, L_80083438
    if (ctx->r18 != 0) {
        // 0x80083430: nop
    
            goto L_80083438;
    }
    // 0x80083430: nop

    // 0x80083434: break       7
    do_break(2148021300);
L_80083438:
    // 0x80083438: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008343C: bne         $s2, $at, L_80083450
    if (ctx->r18 != ctx->r1) {
        // 0x80083440: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80083450;
    }
    // 0x80083440: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80083444: bne         $t7, $at, L_80083450
    if (ctx->r15 != ctx->r1) {
        // 0x80083448: nop
    
            goto L_80083450;
    }
    // 0x80083448: nop

    // 0x8008344C: break       6
    do_break(2148021324);
L_80083450:
    // 0x80083450: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80083454: and         $v0, $t9, $t1
    ctx->r2 = ctx->r25 & ctx->r9;
    // 0x80083458: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
    // 0x8008345C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80083460: lh          $t4, 0x4($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4);
    // 0x80083464: bgez        $a2, L_80083470
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80083468: lh          $t2, 0xC($s1)
        ctx->r10 = MEM_H(ctx->r17, 0XC);
            goto L_80083470;
    }
    // 0x80083468: lh          $t2, 0xC($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XC);
    // 0x8008346C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80083470:
    // 0x80083470: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x80083474: bgez        $v0, L_80083480
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80083478: subu        $t3, $t3, $a2
        ctx->r11 = SUB32(ctx->r11, ctx->r6);
            goto L_80083480;
    }
    // 0x80083478: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x8008347C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80083480:
    // 0x80083480: lhu         $a1, 0x1A($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X1A);
    // 0x80083484: sll         $t8, $t3, 16
    ctx->r24 = S32(ctx->r11 << 16);
    // 0x80083488: sra         $t3, $t8, 16
    ctx->r11 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8008348C: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // 0x80083490: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80083494: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80083498: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008349C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800834A0: sh          $t3, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r11;
    // 0x800834A4: beq         $t8, $zero, L_800834B8
    if (ctx->r24 == 0) {
        // 0x800834A8: sh          $t4, 0xD6($sp)
        MEM_H(0XD6, ctx->r29) = ctx->r12;
            goto L_800834B8;
    }
    // 0x800834A8: sh          $t4, 0xD6($sp)
    MEM_H(0XD6, ctx->r29) = ctx->r12;
    // 0x800834AC: addu        $t6, $t4, $a2
    ctx->r14 = ADD32(ctx->r12, ctx->r6);
    // 0x800834B0: sh          $t6, 0xD6($sp)
    MEM_H(0XD6, ctx->r29) = ctx->r14;
    // 0x800834B4: sh          $t3, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r11;
L_800834B8:
    // 0x800834B8: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x800834BC: lhu         $t6, -0x544C($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X544C);
    // 0x800834C0: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x800834C4: lh          $a0, 0x94($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X94);
    // 0x800834C8: lhu         $t9, -0x5448($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X5448);
    // 0x800834CC: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x800834D0: lh          $a2, 0xD6($sp)
    ctx->r6 = MEM_H(ctx->r29, 0XD6);
    // 0x800834D4: lhu         $t7, -0x5450($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X5450);
    // 0x800834D8: subu        $t3, $t6, $t2
    ctx->r11 = SUB32(ctx->r14, ctx->r10);
    // 0x800834DC: subu        $t6, $a0, $t9
    ctx->r14 = SUB32(ctx->r4, ctx->r25);
    // 0x800834E0: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x800834E4: lhu         $t9, -0x5444($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X5444);
    // 0x800834E8: subu        $v0, $t7, $a2
    ctx->r2 = SUB32(ctx->r15, ctx->r6);
    // 0x800834EC: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x800834F0: addu        $t0, $t6, $a2
    ctx->r8 = ADD32(ctx->r14, ctx->r6);
    // 0x800834F4: sra         $t3, $t7, 16
    ctx->r11 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800834F8: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800834FC: subu        $t6, $a3, $t9
    ctx->r14 = SUB32(ctx->r7, ctx->r25);
    // 0x80083500: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80083504: sra         $t0, $t7, 16
    ctx->r8 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80083508: addu        $v1, $t6, $t2
    ctx->r3 = ADD32(ctx->r14, ctx->r10);
    // 0x8008350C: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80083510: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80083514: bgez        $v0, L_80083520
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80083518: sra         $v1, $t7, 16
        ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80083520;
    }
    // 0x80083518: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8008351C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80083520:
    // 0x80083520: bgez        $t3, L_8008352C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80083524: subu        $t9, $a0, $v0
        ctx->r25 = SUB32(ctx->r4, ctx->r2);
            goto L_8008352C;
    }
    // 0x80083524: subu        $t9, $a0, $v0
    ctx->r25 = SUB32(ctx->r4, ctx->r2);
    // 0x80083528: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_8008352C:
    // 0x8008352C: bgez        $t0, L_80083538
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80083530: subu        $t8, $a3, $t3
        ctx->r24 = SUB32(ctx->r7, ctx->r11);
            goto L_80083538;
    }
    // 0x80083530: subu        $t8, $a3, $t3
    ctx->r24 = SUB32(ctx->r7, ctx->r11);
    // 0x80083534: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80083538:
    // 0x80083538: bgez        $v1, L_80083544
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008353C: subu        $a0, $t9, $t0
        ctx->r4 = SUB32(ctx->r25, ctx->r8);
            goto L_80083544;
    }
    // 0x8008353C: subu        $a0, $t9, $t0
    ctx->r4 = SUB32(ctx->r25, ctx->r8);
    // 0x80083540: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80083544:
    // 0x80083544: subu        $a3, $t8, $v1
    ctx->r7 = SUB32(ctx->r24, ctx->r3);
    // 0x80083548: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x8008354C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80083550: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80083554: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80083558: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8008355C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80083560: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x80083564: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80083568: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8008356C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80083570: blez        $a0, L_80083DB4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80083574: or          $t2, $t6, $zero
        ctx->r10 = ctx->r14 | 0;
            goto L_80083DB4;
    }
    // 0x80083574: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x80083578: sh          $a0, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r4;
    // 0x8008357C: blez        $a3, L_80083DB4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80083580: sh          $t8, 0xD6($sp)
        MEM_H(0XD6, ctx->r29) = ctx->r24;
            goto L_80083DB4;
    }
    // 0x80083580: sh          $t8, 0xD6($sp)
    MEM_H(0XD6, ctx->r29) = ctx->r24;
    // 0x80083584: sra         $t4, $t6, 2
    ctx->r12 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80083588: sll         $t7, $t4, 16
    ctx->r15 = S32(ctx->r12 << 16);
    // 0x8008358C: sra         $t4, $t7, 16
    ctx->r12 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80083590: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80083594: sll         $t7, $a2, 19
    ctx->r15 = S32(ctx->r6 << 19);
    // 0x80083598: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8008359C: lh          $t7, 0x94($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X94);
    // 0x800835A0: lh          $t8, 0xC2($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XC2);
    // 0x800835A4: sra         $t1, $a3, 2
    ctx->r9 = S32(SIGNED(ctx->r7) >> 2);
    // 0x800835A8: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x800835AC: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800835B0: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800835B4: or          $a0, $ra, $zero
    ctx->r4 = ctx->r31 | 0;
    // 0x800835B8: sll         $t9, $a0, 19
    ctx->r25 = S32(ctx->r4 << 19);
    // 0x800835BC: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800835C0: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x800835C4: lbu         $v1, -0x5440($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5440);
    // 0x800835C8: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x800835CC: lui         $ra, 0x8011
    ctx->r31 = S32(0X8011 << 16);
    // 0x800835D0: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800835D4: mflo        $t9
    ctx->r25 = lo;
    // 0x800835D8: sra         $t6, $t9, 7
    ctx->r14 = S32(SIGNED(ctx->r25) >> 7);
    // 0x800835DC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800835E0: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800835E4: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x800835E8: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800835EC: sh          $t7, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r15;
    // 0x800835F0: beq         $a1, $zero, L_80083618
    if (ctx->r5 == 0) {
        // 0x800835F4: sw          $t9, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r25;
            goto L_80083618;
    }
    // 0x800835F4: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800835F8: multu       $t0, $t8
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800835FC: lhu         $t9, 0x0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X0);
    // 0x80083600: mflo        $t6
    ctx->r14 = lo;
    // 0x80083604: sra         $t7, $t6, 7
    ctx->r15 = S32(SIGNED(ctx->r14) >> 7);
    // 0x80083608: addu        $a1, $t9, $t7
    ctx->r5 = ADD32(ctx->r25, ctx->r15);
    // 0x8008360C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80083610: b           L_80083638
    // 0x80083614: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
        goto L_80083638;
    // 0x80083614: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
L_80083618:
    // 0x80083618: lh          $t7, 0xC2($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XC2);
    // 0x8008361C: lhu         $t9, 0x0($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X0);
    // 0x80083620: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083624: mflo        $t8
    ctx->r24 = lo;
    // 0x80083628: sra         $t6, $t8, 7
    ctx->r14 = S32(SIGNED(ctx->r24) >> 7);
    // 0x8008362C: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x80083630: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x80083634: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
L_80083638:
    // 0x80083638: multu       $t3, $s2
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008363C: lhu         $t9, 0x8($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X8);
    // 0x80083640: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80083644: lw          $v1, 0x20($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X20);
    // 0x80083648: addiu       $ra, $ra, -0xEF8
    ctx->r31 = ADD32(ctx->r31, -0XEF8);
    // 0x8008364C: mflo        $t6
    ctx->r14 = lo;
    // 0x80083650: sra         $t7, $t6, 7
    ctx->r15 = S32(SIGNED(ctx->r14) >> 7);
    // 0x80083654: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x80083658: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8008365C: bne         $at, $zero, L_80083688
    if (ctx->r1 != 0) {
        // 0x80083660: sra         $v0, $t8, 16
        ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80083688;
    }
    // 0x80083660: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
L_80083664:
    // 0x80083664: subu        $a1, $a1, $a2
    ctx->r5 = SUB32(ctx->r5, ctx->r6);
    // 0x80083668: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x8008366C: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80083670: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80083674: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80083678: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8008367C: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80083680: beq         $at, $zero, L_80083664
    if (ctx->r1 == 0) {
        // 0x80083684: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_80083664;
    }
    // 0x80083684: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
L_80083688:
    // 0x80083688: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8008368C: bne         $at, $zero, L_800836AC
    if (ctx->r1 != 0) {
        // 0x80083690: lh          $t8, 0xCA($sp)
        ctx->r24 = MEM_H(ctx->r29, 0XCA);
            goto L_800836AC;
    }
    // 0x80083690: lh          $t8, 0xCA($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XCA);
L_80083694:
    // 0x80083694: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80083698: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8008369C: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800836A0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800836A4: beq         $at, $zero, L_80083694
    if (ctx->r1 == 0) {
        // 0x800836A8: subu        $v1, $v1, $a0
        ctx->r3 = SUB32(ctx->r3, ctx->r4);
            goto L_80083694;
    }
    // 0x800836A8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
L_800836AC:
    // 0x800836AC: addu        $t6, $a1, $t8
    ctx->r14 = ADD32(ctx->r5, ctx->r24);
    // 0x800836B0: slt         $t9, $t6, $a2
    ctx->r25 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800836B4: xori        $t9, $t9, 0x1
    ctx->r25 = ctx->r25 ^ 0X1;
    // 0x800836B8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800836BC: sh          $t9, -0xEF4($at)
    MEM_H(-0XEF4, ctx->r1) = ctx->r25;
    // 0x800836C0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800836C4: sra         $t7, $a0, 5
    ctx->r15 = S32(SIGNED(ctx->r4) >> 5);
    // 0x800836C8: sh          $t7, -0xEEC($at)
    MEM_H(-0XEEC, ctx->r1) = ctx->r15;
    // 0x800836CC: lbu         $t8, 0x16($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X16);
    // 0x800836D0: lbu         $a3, 0x17($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X17);
    // 0x800836D4: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x800836D8: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x800836DC: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x800836E0: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x800836E4: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800836E8: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800836EC: lh          $t7, -0x5430($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X5430);
    // 0x800836F0: lh          $t8, -0x5428($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X5428);
    // 0x800836F4: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800836F8: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800836FC: sh          $t7, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r15;
    // 0x80083700: sh          $t8, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r24;
    // 0x80083704: lhu         $t6, 0x6($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X6);
    // 0x80083708: lh          $t9, 0xC2($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XC2);
    // 0x8008370C: lh          $t5, -0x543C($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X543C);
    // 0x80083710: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083714: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80083718: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x8008371C: mflo        $t7
    ctx->r15 = lo;
    // 0x80083720: sra         $t8, $t7, 7
    ctx->r24 = S32(SIGNED(ctx->r15) >> 7);
    // 0x80083724: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80083728: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8008372C: beql        $at, $zero, L_8008373C
    if (ctx->r1 == 0) {
        // 0x80083730: lh          $t7, 0x84($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X84);
            goto L_8008373C;
    }
    goto skip_0;
    // 0x80083730: lh          $t7, 0x84($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X84);
    skip_0:
    // 0x80083734: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80083738: lh          $t7, 0x84($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X84);
L_8008373C:
    // 0x8008373C: lh          $t8, 0x82($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X82);
    // 0x80083740: subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
    // 0x80083744: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x80083748: div         $zero, $t6, $t8
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r24)));
    // 0x8008374C: mflo        $t9
    ctx->r25 = lo;
    // 0x80083750: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80083754: bne         $t8, $zero, L_80083760
    if (ctx->r24 != 0) {
        // 0x80083758: nop
    
            goto L_80083760;
    }
    // 0x80083758: nop

    // 0x8008375C: break       7
    do_break(2148022108);
L_80083760:
    // 0x80083760: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083764: bne         $t8, $at, L_80083778
    if (ctx->r24 != ctx->r1) {
        // 0x80083768: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80083778;
    }
    // 0x80083768: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008376C: bne         $t6, $at, L_80083778
    if (ctx->r14 != ctx->r1) {
        // 0x80083770: nop
    
            goto L_80083778;
    }
    // 0x80083770: nop

    // 0x80083774: break       6
    do_break(2148022132);
L_80083778:
    // 0x80083778: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8008377C: div         $zero, $t5, $t6
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r14)));
    // 0x80083780: or          $t8, $t6, $zero
    ctx->r24 = ctx->r14 | 0;
    // 0x80083784: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x80083788: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008378C: mflo        $a0
    ctx->r4 = lo;
    // 0x80083790: sh          $t7, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r15;
    // 0x80083794: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80083798: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8008379C: subu        $t2, $t7, $t6
    ctx->r10 = SUB32(ctx->r15, ctx->r14);
    // 0x800837A0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800837A4: bne         $t8, $zero, L_800837B0
    if (ctx->r24 != 0) {
        // 0x800837A8: nop
    
            goto L_800837B0;
    }
    // 0x800837A8: nop

    // 0x800837AC: break       7
    do_break(2148022188);
L_800837B0:
    // 0x800837B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800837B4: bne         $t8, $at, L_800837C8
    if (ctx->r24 != ctx->r1) {
        // 0x800837B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800837C8;
    }
    // 0x800837B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800837BC: bne         $t5, $at, L_800837C8
    if (ctx->r13 != ctx->r1) {
        // 0x800837C0: nop
    
            goto L_800837C8;
    }
    // 0x800837C0: nop

    // 0x800837C4: break       6
    do_break(2148022212);
L_800837C8:
    // 0x800837C8: sll         $t8, $t2, 16
    ctx->r24 = S32(ctx->r10 << 16);
    // 0x800837CC: sll         $t7, $a3, 5
    ctx->r15 = S32(ctx->r7 << 5);
    // 0x800837D0: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800837D4: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x800837D8: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800837DC: bgez        $t7, L_800837EC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800837E0: or          $t3, $t7, $zero
        ctx->r11 = ctx->r15 | 0;
            goto L_800837EC;
    }
    // 0x800837E0: or          $t3, $t7, $zero
    ctx->r11 = ctx->r15 | 0;
    // 0x800837E4: subu        $t3, $a3, $s2
    ctx->r11 = SUB32(ctx->r7, ctx->r18);
    // 0x800837E8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_800837EC:
    // 0x800837EC: div         $zero, $t3, $s2
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r18)));
    // 0x800837F0: mflo        $a3
    ctx->r7 = lo;
    // 0x800837F4: sll         $t6, $a3, 10
    ctx->r14 = S32(ctx->r7 << 10);
    // 0x800837F8: bne         $s2, $zero, L_80083804
    if (ctx->r18 != 0) {
        // 0x800837FC: nop
    
            goto L_80083804;
    }
    // 0x800837FC: nop

    // 0x80083800: break       7
    do_break(2148022272);
L_80083804:
    // 0x80083804: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083808: bne         $s2, $at, L_8008381C
    if (ctx->r18 != ctx->r1) {
        // 0x8008380C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008381C;
    }
    // 0x8008380C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80083810: bne         $t3, $at, L_8008381C
    if (ctx->r11 != ctx->r1) {
        // 0x80083814: nop
    
            goto L_8008381C;
    }
    // 0x80083814: nop

    // 0x80083818: break       6
    do_break(2148022296);
L_8008381C:
    // 0x8008381C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80083820: bltzl       $t6, L_80083890
    if (SIGNED(ctx->r14) < 0) {
        // 0x80083824: sll         $t9, $t2, 20
        ctx->r25 = S32(ctx->r10 << 20);
            goto L_80083890;
    }
    goto skip_1;
    // 0x80083824: sll         $t9, $t2, 20
    ctx->r25 = S32(ctx->r10 << 20);
    skip_1:
    // 0x80083828: sll         $t8, $t2, 20
    ctx->r24 = S32(ctx->r10 << 20);
    // 0x8008382C: div         $zero, $t8, $s2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r18)));
    // 0x80083830: mflo        $t5
    ctx->r13 = lo;
    // 0x80083834: bne         $s2, $zero, L_80083840
    if (ctx->r18 != 0) {
        // 0x80083838: nop
    
            goto L_80083840;
    }
    // 0x80083838: nop

    // 0x8008383C: break       7
    do_break(2148022332);
L_80083840:
    // 0x80083840: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083844: bne         $s2, $at, L_80083858
    if (ctx->r18 != ctx->r1) {
        // 0x80083848: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80083858;
    }
    // 0x80083848: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008384C: bne         $t8, $at, L_80083858
    if (ctx->r24 != ctx->r1) {
        // 0x80083850: nop
    
            goto L_80083858;
    }
    // 0x80083850: nop

    // 0x80083854: break       6
    do_break(2148022356);
L_80083858:
    // 0x80083858: div         $zero, $a3, $t5
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r13)));
    // 0x8008385C: mflo        $t0
    ctx->r8 = lo;
    // 0x80083860: bne         $t5, $zero, L_8008386C
    if (ctx->r13 != 0) {
        // 0x80083864: nop
    
            goto L_8008386C;
    }
    // 0x80083864: nop

    // 0x80083868: break       7
    do_break(2148022376);
L_8008386C:
    // 0x8008386C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083870: bne         $t5, $at, L_80083884
    if (ctx->r13 != ctx->r1) {
        // 0x80083874: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80083884;
    }
    // 0x80083874: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80083878: bne         $a3, $at, L_80083884
    if (ctx->r7 != ctx->r1) {
        // 0x8008387C: nop
    
            goto L_80083884;
    }
    // 0x8008387C: nop

    // 0x80083880: break       6
    do_break(2148022400);
L_80083884:
    // 0x80083884: b           L_800838F0
    // 0x80083888: nop

        goto L_800838F0;
    // 0x80083888: nop

    // 0x8008388C: sll         $t9, $t2, 20
    ctx->r25 = S32(ctx->r10 << 20);
L_80083890:
    // 0x80083890: div         $zero, $t9, $s2
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r18)));
    // 0x80083894: mflo        $t5
    ctx->r13 = lo;
    // 0x80083898: subu        $t7, $a3, $t5
    ctx->r15 = SUB32(ctx->r7, ctx->r13);
    // 0x8008389C: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800838A0: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x800838A4: bne         $s2, $zero, L_800838B0
    if (ctx->r18 != 0) {
        // 0x800838A8: nop
    
            goto L_800838B0;
    }
    // 0x800838A8: nop

    // 0x800838AC: break       7
    do_break(2148022444);
L_800838B0:
    // 0x800838B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800838B4: bne         $s2, $at, L_800838C8
    if (ctx->r18 != ctx->r1) {
        // 0x800838B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800838C8;
    }
    // 0x800838B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800838BC: bne         $t9, $at, L_800838C8
    if (ctx->r25 != ctx->r1) {
        // 0x800838C0: nop
    
            goto L_800838C8;
    }
    // 0x800838C0: nop

    // 0x800838C4: break       6
    do_break(2148022468);
L_800838C8:
    // 0x800838C8: mflo        $t0
    ctx->r8 = lo;
    // 0x800838CC: bne         $t5, $zero, L_800838D8
    if (ctx->r13 != 0) {
        // 0x800838D0: nop
    
            goto L_800838D8;
    }
    // 0x800838D0: nop

    // 0x800838D4: break       7
    do_break(2148022484);
L_800838D8:
    // 0x800838D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800838DC: bne         $t5, $at, L_800838F0
    if (ctx->r13 != ctx->r1) {
        // 0x800838E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800838F0;
    }
    // 0x800838E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800838E4: bne         $t6, $at, L_800838F0
    if (ctx->r14 != ctx->r1) {
        // 0x800838E8: nop
    
            goto L_800838F0;
    }
    // 0x800838E8: nop

    // 0x800838EC: break       6
    do_break(2148022508);
L_800838F0:
    // 0x800838F0: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800838F4: addiu       $at, $zero, -0x400
    ctx->r1 = ADD32(0, -0X400);
    // 0x800838F8: mflo        $t8
    ctx->r24 = lo;
    // 0x800838FC: and         $t7, $t8, $at
    ctx->r15 = ctx->r24 & ctx->r1;
    // 0x80083900: subu        $t6, $a3, $t7
    ctx->r14 = SUB32(ctx->r7, ctx->r15);
    // 0x80083904: sra         $t9, $t6, 10
    ctx->r25 = S32(SIGNED(ctx->r14) >> 10);
    // 0x80083908: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008390C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80083910: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x80083914: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80083918: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x8008391C: addiu       $a3, $a3, -0xEF0
    ctx->r7 = ADD32(ctx->r7, -0XEF0);
    // 0x80083920: mflo        $v0
    ctx->r2 = lo;
    // 0x80083924: sra         $t7, $v0, 5
    ctx->r15 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80083928: andi        $t6, $t7, 0x1F
    ctx->r14 = ctx->r15 & 0X1F;
    // 0x8008392C: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083930: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x80083934: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
    // 0x80083938: sra         $t8, $v0, 10
    ctx->r24 = S32(SIGNED(ctx->r2) >> 10);
    // 0x8008393C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80083940: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80083944: addiu       $t0, $t0, -0xEF6
    ctx->r8 = ADD32(ctx->r8, -0XEF6);
    // 0x80083948: mflo        $t9
    ctx->r25 = lo;
    // 0x8008394C: bgez        $t7, L_8008395C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80083950: sra         $t6, $t7, 5
        ctx->r14 = S32(SIGNED(ctx->r15) >> 5);
            goto L_8008395C;
    }
    // 0x80083950: sra         $t6, $t7, 5
    ctx->r14 = S32(SIGNED(ctx->r15) >> 5);
    // 0x80083954: addiu       $at, $t7, 0x1F
    ctx->r1 = ADD32(ctx->r15, 0X1F);
    // 0x80083958: sra         $t6, $at, 5
    ctx->r14 = S32(SIGNED(ctx->r1) >> 5);
L_8008395C:
    // 0x8008395C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80083960: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80083964: addu        $a0, $t8, $t7
    ctx->r4 = ADD32(ctx->r24, ctx->r15);
    // 0x80083968: sll         $ra, $a0, 16
    ctx->r31 = S32(ctx->r4 << 16);
    // 0x8008396C: sra         $t9, $ra, 16
    ctx->r25 = S32(SIGNED(ctx->r31) >> 16);
    // 0x80083970: bgez        $t9, L_80083988
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80083974: sh          $a0, 0xA4($sp)
        MEM_H(0XA4, ctx->r29) = ctx->r4;
            goto L_80083988;
    }
    // 0x80083974: sh          $a0, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r4;
    // 0x80083978: lhu         $t6, 0xA($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0XA);
    // 0x8008397C: sra         $t8, $t6, 2
    ctx->r24 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80083980: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80083984: sh          $t7, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r15;
L_80083988:
    // 0x80083988: lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XA);
    // 0x8008398C: lh          $t6, 0xA4($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XA4);
    // 0x80083990: lui         $ra, 0x8011
    ctx->r31 = S32(0X8011 << 16);
    // 0x80083994: sra         $t9, $v0, 2
    ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80083998: slt         $at, $t6, $t9
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8008399C: bne         $at, $zero, L_800839AC
    if (ctx->r1 != 0) {
        // 0x800839A0: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_800839AC;
    }
    // 0x800839A0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800839A4: subu        $t8, $t6, $t9
    ctx->r24 = SUB32(ctx->r14, ctx->r25);
    // 0x800839A8: sh          $t8, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r24;
L_800839AC:
    // 0x800839AC: lh          $t9, 0x82($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X82);
    // 0x800839B0: lw          $t7, 0x10($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X10);
    // 0x800839B4: addiu       $ra, $ra, -0xEF2
    ctx->r31 = ADD32(ctx->r31, -0XEF2);
    // 0x800839B8: div         $zero, $a2, $t9
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r25)));
    // 0x800839BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800839C0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800839C4: lh          $t7, 0x82($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X82);
    // 0x800839C8: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800839CC: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x800839D0: div         $zero, $a1, $t7
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r15)));
    // 0x800839D4: bne         $t9, $zero, L_800839E0
    if (ctx->r25 != 0) {
        // 0x800839D8: nop
    
            goto L_800839E0;
    }
    // 0x800839D8: nop

    // 0x800839DC: break       7
    do_break(2148022748);
L_800839E0:
    // 0x800839E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800839E4: bne         $t9, $at, L_800839F8
    if (ctx->r25 != ctx->r1) {
        // 0x800839E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800839F8;
    }
    // 0x800839E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800839EC: bne         $a2, $at, L_800839F8
    if (ctx->r6 != ctx->r1) {
        // 0x800839F0: nop
    
            goto L_800839F8;
    }
    // 0x800839F0: nop

    // 0x800839F4: break       6
    do_break(2148022772);
L_800839F8:
    // 0x800839F8: mflo        $t9
    ctx->r25 = lo;
    // 0x800839FC: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x80083A00: lh          $t8, 0xA4($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XA4);
    // 0x80083A04: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x80083A08: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80083A0C: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083A10: sh          $t6, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r14;
    // 0x80083A14: bne         $t7, $zero, L_80083A20
    if (ctx->r15 != 0) {
        // 0x80083A18: nop
    
            goto L_80083A20;
    }
    // 0x80083A18: nop

    // 0x80083A1C: break       7
    do_break(2148022812);
L_80083A20:
    // 0x80083A20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80083A24: bne         $t7, $at, L_80083A38
    if (ctx->r15 != ctx->r1) {
        // 0x80083A28: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80083A38;
    }
    // 0x80083A28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80083A2C: bne         $a1, $at, L_80083A38
    if (ctx->r5 != ctx->r1) {
        // 0x80083A30: nop
    
            goto L_80083A38;
    }
    // 0x80083A30: nop

    // 0x80083A34: break       6
    do_break(2148022836);
L_80083A38:
    // 0x80083A38: lhu         $t8, 0x0($ra)
    ctx->r24 = MEM_HU(ctx->r31, 0X0);
    // 0x80083A3C: mflo        $t7
    ctx->r15 = lo;
    // 0x80083A40: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80083A44: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80083A48: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x80083A4C: lh          $t9, 0x84($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X84);
    // 0x80083A50: lhu         $t6, 0x1A($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X1A);
    // 0x80083A54: lui         $at, 0xFD0F
    ctx->r1 = S32(0XFD0F << 16);
    // 0x80083A58: and         $v1, $a1, $t9
    ctx->r3 = ctx->r5 & ctx->r25;
    // 0x80083A5C: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x80083A60: beq         $t8, $zero, L_80083A7C
    if (ctx->r24 == 0) {
        // 0x80083A64: andi        $a0, $v1, 0xFFFF
        ctx->r4 = ctx->r3 & 0XFFFF;
            goto L_80083A7C;
    }
    // 0x80083A64: andi        $a0, $v1, 0xFFFF
    ctx->r4 = ctx->r3 & 0XFFFF;
    // 0x80083A68: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80083A6C: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    // 0x80083A70: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80083A74: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80083A78: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_80083A7C:
    // 0x80083A7C: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80083A80: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80083A84: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80083A88: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x80083A8C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80083A90: sw          $t7, -0xF00($at)
    MEM_W(-0XF00, ctx->r1) = ctx->r15;
    // 0x80083A94: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80083A98: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80083A9C: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x80083AA0: addiu       $v1, $v1, -0xEFC
    ctx->r3 = ADD32(ctx->r3, -0XEFC);
    // 0x80083AA4: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x80083AA8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80083AAC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80083AB0: lh          $a1, 0xD6($sp)
    ctx->r5 = MEM_H(ctx->r29, 0XD6);
    // 0x80083AB4: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80083AB8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80083ABC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80083AC0: lui         $at, 0x7
    ctx->r1 = S32(0X7 << 16);
    // 0x80083AC4: ori         $at, $at, 0xC1F0
    ctx->r1 = ctx->r1 | 0XC1F0;
    // 0x80083AC8: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x80083ACC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80083AD0: sll         $ra, $a1, 12
    ctx->r31 = S32(ctx->r5 << 12);
    // 0x80083AD4: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80083AD8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80083ADC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80083AE0: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80083AE4: lbu         $t6, 0x17($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X17);
    // 0x80083AE8: lbu         $t7, 0x16($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X16);
    // 0x80083AEC: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x80083AF0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80083AF4: sll         $t9, $t7, 5
    ctx->r25 = S32(ctx->r15 << 5);
    // 0x80083AF8: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80083AFC: sb          $t7, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r15;
    // 0x80083B00: lhu         $t9, 0x18($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X18);
    // 0x80083B04: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80083B08: sll         $t8, $t9, 20
    ctx->r24 = S32(ctx->r25 << 20);
    // 0x80083B0C: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80083B10: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80083B14: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80083B18: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80083B1C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80083B20: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x80083B24: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80083B28: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80083B2C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80083B30: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80083B34: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80083B38: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80083B3C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x80083B40: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80083B44: lh          $t9, 0xA4($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XA4);
    // 0x80083B48: lh          $t6, -0xEEC($t6)
    ctx->r14 = MEM_H(ctx->r14, -0XEEC);
    // 0x80083B4C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80083B50: subu        $t8, $t6, $t9
    ctx->r24 = SUB32(ctx->r14, ctx->r25);
    // 0x80083B54: sh          $t8, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r24;
    // 0x80083B58: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80083B5C: subu        $a3, $t2, $t7
    ctx->r7 = SUB32(ctx->r10, ctx->r15);
    // 0x80083B60: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80083B64: andi        $t7, $t8, 0x3FF
    ctx->r15 = ctx->r24 & 0X3FF;
    // 0x80083B68: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80083B6C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80083B70: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x80083B74: lh          $t7, 0xC2($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XC2);
    // 0x80083B78: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80083B7C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80083B80: lh          $t8, 0x94($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X94);
    // 0x80083B84: subu        $t0, $t6, $t9
    ctx->r8 = SUB32(ctx->r14, ctx->r25);
    // 0x80083B88: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80083B8C: or          $t9, $t6, $s2
    ctx->r25 = ctx->r14 | ctx->r18;
    // 0x80083B90: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x80083B94: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80083B98: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80083B9C: sra         $t9, $t6, 16
    ctx->r25 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80083BA0: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80083BA4: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80083BA8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_80083BAC:
    // 0x80083BAC: sra         $v0, $t0, 10
    ctx->r2 = S32(SIGNED(ctx->r8) >> 10);
    // 0x80083BB0: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80083BB4: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80083BB8: sra         $t6, $v1, 16
    ctx->r14 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80083BBC: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80083BC0: lh          $a0, 0x62($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X62);
    // 0x80083BC4: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x80083BC8: bgtz        $t8, L_80083C3C
    if (SIGNED(ctx->r24) > 0) {
        // 0x80083BCC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80083C3C;
    }
    // 0x80083BCC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80083BD0: subu        $a0, $a0, $a3
    ctx->r4 = SUB32(ctx->r4, ctx->r7);
    // 0x80083BD4: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80083BD8: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80083BDC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80083BE0: blez        $a0, L_80083BFC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80083BE4: lhu         $v0, -0xEF6($v0)
        ctx->r2 = MEM_HU(ctx->r2, -0XEF6);
            goto L_80083BFC;
    }
    // 0x80083BE4: lhu         $v0, -0xEF6($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0XEF6);
    // 0x80083BE8: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083BEC: mflo        $t9
    ctx->r25 = lo;
    // 0x80083BF0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x80083BF4: b           L_80083C34
    // 0x80083BF8: sh          $a0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r4;
        goto L_80083C34;
    // 0x80083BF8: sh          $a0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r4;
L_80083BFC:
    // 0x80083BFC: multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083C00: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80083C04: lw          $t8, -0xEF0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XEF0);
    // 0x80083C08: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80083C0C: lhu         $t9, -0xEF2($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0XEF2);
    // 0x80083C10: mflo        $t7
    ctx->r15 = lo;
    // 0x80083C14: subu        $t6, $t8, $t7
    ctx->r14 = SUB32(ctx->r24, ctx->r15);
    // 0x80083C18: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80083C1C: lh          $t8, -0xEEC($t8)
    ctx->r24 = MEM_H(ctx->r24, -0XEEC);
    // 0x80083C20: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    // 0x80083C24: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80083C28: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80083C2C: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80083C30: sh          $a0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r4;
L_80083C34:
    // 0x80083C34: b           L_80083D9C
    // 0x80083C38: sw          $a1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r5;
        goto L_80083D9C;
    // 0x80083C38: sw          $a1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r5;
L_80083C3C:
    // 0x80083C3C: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x80083C40: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x80083C44: andi        $t9, $t0, 0x3FF
    ctx->r25 = ctx->r8 & 0X3FF;
    // 0x80083C48: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80083C4C: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x80083C50: bgez        $t7, L_80083C98
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80083C54: or          $t1, $t7, $zero
        ctx->r9 = ctx->r15 | 0;
            goto L_80083C98;
    }
    // 0x80083C54: or          $t1, $t7, $zero
    ctx->r9 = ctx->r15 | 0;
    // 0x80083C58: multu       $t7, $s2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80083C5C: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80083C60: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80083C64: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80083C68: mflo        $t8
    ctx->r24 = lo;
    // 0x80083C6C: sra         $t7, $t8, 10
    ctx->r15 = S32(SIGNED(ctx->r24) >> 10);
    // 0x80083C70: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x80083C74: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80083C78: sll         $t6, $a3, 16
    ctx->r14 = S32(ctx->r7 << 16);
    // 0x80083C7C: sra         $a3, $t6, 16
    ctx->r7 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80083C80: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80083C84: beq         $at, $zero, L_80083C98
    if (ctx->r1 == 0) {
        // 0x80083C88: nop
    
            goto L_80083C98;
    }
    // 0x80083C88: nop

    // 0x80083C8C: sll         $a3, $t2, 16
    ctx->r7 = S32(ctx->r10 << 16);
    // 0x80083C90: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80083C94: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_80083C98:
    // 0x80083C98: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80083C9C: lbu         $t7, -0x5440($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X5440);
    // 0x80083CA0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80083CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083CA8: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x80083CAC: addiu       $a2, $sp, 0x62
    ctx->r6 = ADD32(ctx->r29, 0X62);
    // 0x80083CB0: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    // 0x80083CB4: sw          $t0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r8;
    // 0x80083CB8: sh          $t1, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = ctx->r9;
    // 0x80083CBC: sh          $t2, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = ctx->r10;
    // 0x80083CC0: sh          $t3, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r11;
    // 0x80083CC4: sh          $t4, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = ctx->r12;
    // 0x80083CC8: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x80083CCC: jal         0x80083038
    // 0x80083CD0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    tmemLoad(rdram, ctx);
        goto after_0;
    // 0x80083CD0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80083CD4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80083CD8: lh          $v1, 0x5E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5E);
    // 0x80083CDC: lh          $t1, 0xD0($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XD0);
    // 0x80083CE0: lhu         $t3, 0xAC($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0XAC);
    // 0x80083CE4: lh          $t4, 0xD2($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XD2);
    // 0x80083CE8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80083CEC: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x80083CF0: lh          $t2, 0xB8($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XB8);
    // 0x80083CF4: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80083CF8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80083CFC: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80083D00: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80083D04: addu        $a0, $t4, $v1
    ctx->r4 = ADD32(ctx->r12, ctx->r3);
    // 0x80083D08: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80083D0C: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80083D10: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80083D14: sra         $t7, $t8, 16
    ctx->r15 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80083D18: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80083D1C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80083D20: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80083D24: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80083D28: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80083D2C: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80083D30: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80083D34: or          $t6, $ra, $t9
    ctx->r14 = ctx->r31 | ctx->r25;
    // 0x80083D38: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x80083D3C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x80083D40: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80083D44: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x80083D48: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80083D4C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80083D50: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x80083D54: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80083D58: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80083D5C: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x80083D60: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80083D64: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80083D68: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80083D6C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x80083D70: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80083D74: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80083D78: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80083D7C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80083D80: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x80083D84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80083D88: sra         $t8, $t4, 16
    ctx->r24 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80083D8C: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x80083D90: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80083D94: blez        $t1, L_80083DB4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80083D98: sw          $t6, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r14;
            goto L_80083DB4;
    }
    // 0x80083D98: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
L_80083D9C:
    // 0x80083D9C: sll         $a3, $t2, 16
    ctx->r7 = S32(ctx->r10 << 16);
    // 0x80083DA0: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80083DA4: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x80083DA8: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80083DAC: b           L_80083BAC
    // 0x80083DB0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
        goto L_80083BAC;
    // 0x80083DB0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80083DB4:
    // 0x80083DB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80083DB8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80083DBC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80083DC0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80083DC4: jr          $ra
    // 0x80083DC8: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80083DC8: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x80083DCC: nop

;}
RECOMP_FUNC void func_805D0154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D0154: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805D0158: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D015C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x805D0160: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x805D0164: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x805D0168: jal         0x80047090
    // 0x805D016C: addiu       $a0, $zero, 0x44FE
    ctx->r4 = ADD32(0, 0X44FE);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805D016C: addiu       $a0, $zero, 0x44FE
    ctx->r4 = ADD32(0, 0X44FE);
    after_0:
    // 0x805D0170: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x805D0174: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x805D0178: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x805D017C: bne         $a0, $v0, L_805D018C
    if (ctx->r4 != ctx->r2) {
        // 0x805D0180: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_805D018C;
    }
    // 0x805D0180: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x805D0184: b           L_805D023C
    // 0x805D0188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805D023C;
    // 0x805D0188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D018C:
    // 0x805D018C: beq         $a0, $v1, L_805D0238
    if (ctx->r4 == ctx->r3) {
        // 0x805D0190: lui         $at, 0x44FE
        ctx->r1 = S32(0X44FE << 16);
            goto L_805D0238;
    }
    // 0x805D0190: lui         $at, 0x44FE
    ctx->r1 = S32(0X44FE << 16);
    // 0x805D0194: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x805D0198: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(462, 0X3F0) << 16);
    // 0x805D019C: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x805D01A0: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x805D01A4: addiu       $a0, $a0, 0x360
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(462, 0X3F0));
    // 0x805D01A8: or          $a1, $t0, $at
    ctx->r5 = ctx->r8 | ctx->r1;
    // 0x805D01AC: jal         0x80046804
    // 0x805D01B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x805D01B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x805D01B4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x805D01B8: beq         $v0, $zero, L_805D0238
    if (ctx->r2 == 0) {
        // 0x805D01BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805D0238;
    }
    // 0x805D01BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805D01C0: lw          $t6, 0x168($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X168);
    // 0x805D01C4: beq         $t2, $zero, L_805D01E4
    if (ctx->r10 == 0) {
        // 0x805D01C8: lw          $v1, 0x88($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X88);
            goto L_805D01E4;
    }
    // 0x805D01C8: lw          $v1, 0x88($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X88);
    // 0x805D01CC: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x805D01D0: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x805D01D4: lwc1        $f8, 0x4($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X4);
    // 0x805D01D8: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x805D01DC: lwc1        $f10, 0x8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X8);
    // 0x805D01E0: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_805D01E4:
    // 0x805D01E4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x805D01E8: jal         0x80044194
    // 0x805D01EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805D01EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x805D01F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x805D01F4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805D01F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805D01FC: beq         $a0, $at, L_805D0218
    if (ctx->r4 == ctx->r1) {
        // 0x805D0200: addiu       $a1, $v1, 0x200
        ctx->r5 = ADD32(ctx->r3, 0X200);
            goto L_805D0218;
    }
    // 0x805D0200: addiu       $a1, $v1, 0x200
    ctx->r5 = ADD32(ctx->r3, 0X200);
    // 0x805D0204: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805D0208: beq         $a0, $at, L_805D0228
    if (ctx->r4 == ctx->r1) {
        // 0x805D020C: addiu       $a1, $v1, 0x400
        ctx->r5 = ADD32(ctx->r3, 0X400);
            goto L_805D0228;
    }
    // 0x805D020C: addiu       $a1, $v1, 0x400
    ctx->r5 = ADD32(ctx->r3, 0X400);
    // 0x805D0210: b           L_805D0230
    // 0x805D0214: nop

        goto L_805D0230;
    // 0x805D0214: nop

L_805D0218:
    // 0x805D0218: jal         0x8004590C
    // 0x805D021C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8004590C(rdram, ctx);
        goto after_3;
    // 0x805D021C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x805D0220: b           L_805D0230
    // 0x805D0224: nop

        goto L_805D0230;
    // 0x805D0224: nop

L_805D0228:
    // 0x805D0228: jal         0x8004590C
    // 0x805D022C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8004590C(rdram, ctx);
        goto after_4;
    // 0x805D022C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_805D0230:
    // 0x805D0230: b           L_805D023C
    // 0x805D0234: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_805D023C;
    // 0x805D0234: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_805D0238:
    // 0x805D0238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D023C:
    // 0x805D023C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805D0240: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805D0244: jr          $ra
    // 0x805D0248: nop

    return;
    // 0x805D0248: nop

    // 0x805D024C: nop

;}
RECOMP_FUNC void func_80554A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80554A50: jr          $ra
    // 0x80554A54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80554A54: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80434FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434FF4: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80434FF8: lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X8);
    // 0x80434FFC: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(71, 0X27F0) << 16);
    // 0x80435000: lw          $t6, 0x5C0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C0);
    // 0x80435004: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80435008: addiu       $t8, $t8, 0x62A0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(71, 0X27F0));
    // 0x8043500C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80435010: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80435014: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80435018: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x8043501C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80435020: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80435024: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80435028: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x8043502C: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    // 0x80435030: sw          $a2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r6;
    // 0x80435034: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80435038: addiu       $v1, $t0, 0x8
    ctx->r3 = ADD32(ctx->r8, 0X8);
    // 0x8043503C: jr          $ra
    // 0x80435040: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    return;
    // 0x80435040: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_8004D698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D69C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D6A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004D6A4: jalr        $a2
    // 0x8004D6A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r6)(rdram, ctx);
        goto after_0;
    // 0x8004D6A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004D6AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8004D6B0: jal         0x8004D3C4
    // 0x8004D6B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8004D3C4(rdram, ctx);
        goto after_1;
    // 0x8004D6B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8004D6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004D6BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004D6C0: jr          $ra
    // 0x8004D6C4: nop

    return;
    // 0x8004D6C4: nop

;}
RECOMP_FUNC void func_80441C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441C44: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80441C48: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80441C4C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80441C50: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80441C54: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80441C58: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80441C5C: beq         $v0, $zero, L_80441C6C
    if (ctx->r2 == 0) {
        // 0x80441C60: lui         $t4, 0xE700
        ctx->r12 = S32(0XE700 << 16);
            goto L_80441C6C;
    }
    // 0x80441C60: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80441C64: b           L_80441C70
    // 0x80441C68: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
        goto L_80441C70;
    // 0x80441C68: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
L_80441C6C:
    // 0x80441C6C: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
L_80441C70:
    // 0x80441C70: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80441C74: lbu         $v0, 0xD($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XD);
    // 0x80441C78: lbu         $a0, 0xE($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XE);
    // 0x80441C7C: lbu         $a1, 0xF($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0XF);
    // 0x80441C80: lbu         $a2, 0x10($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X10);
    // 0x80441C84: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80441C88: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80441C8C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80441C90: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80441C94: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80441C98: andi        $t9, $v0, 0xF8
    ctx->r25 = ctx->r2 & 0XF8;
    // 0x80441C9C: sll         $t6, $t9, 8
    ctx->r14 = S32(ctx->r25 << 8);
    // 0x80441CA0: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x80441CA4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80441CA8: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80441CAC: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80441CB0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80441CB4: andi        $t7, $a0, 0xF8
    ctx->r15 = ctx->r4 & 0XF8;
    // 0x80441CB8: lui         $t5, 0xF700
    ctx->r13 = S32(0XF700 << 16);
    // 0x80441CBC: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80441CC0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80441CC4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80441CC8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80441CCC: andi        $t7, $a1, 0xF8
    ctx->r15 = ctx->r5 & 0XF8;
    // 0x80441CD0: srl         $t6, $t7, 2
    ctx->r14 = S32(U32(ctx->r15) >> 2);
    // 0x80441CD4: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80441CD8: andi        $t7, $a2, 0x80
    ctx->r15 = ctx->r6 & 0X80;
    // 0x80441CDC: srl         $t9, $t7, 7
    ctx->r25 = S32(U32(ctx->r15) >> 7);
    // 0x80441CE0: or          $v1, $t8, $t9
    ctx->r3 = ctx->r24 | ctx->r25;
    // 0x80441CE4: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80441CE8: or          $a3, $t6, $v1
    ctx->r7 = ctx->r14 | ctx->r3;
    // 0x80441CEC: sw          $a3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r7;
    // 0x80441CF0: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80441CF4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80441CF8: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x80441CFC: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x80441D00: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x80441D04: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80441D08: sw          $a3, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r7;
    // 0x80441D0C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x80441D10: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80441D14: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80441D18: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80441D1C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80441D20: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80441D24: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80441D28: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80441D2C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80441D30: jr          $ra
    // 0x80441D34: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80441D34: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8001AF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AF80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001AF84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001AF88: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001AF8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001AF90: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8001AF94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001AF98: addiu       $s1, $s1, 0x660
    ctx->r17 = ADD32(ctx->r17, 0X660);
    // 0x8001AF9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001AFA0: addiu       $s2, $zero, 0x48
    ctx->r18 = ADD32(0, 0X48);
L_8001AFA4:
    // 0x8001AFA4: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AFA8: mflo        $t6
    ctx->r14 = lo;
    // 0x8001AFAC: addu        $a0, $s1, $t6
    ctx->r4 = ADD32(ctx->r17, ctx->r14);
    // 0x8001AFB0: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8001AFB4: beql        $t7, $zero, L_8001AFC8
    if (ctx->r15 == 0) {
        // 0x8001AFB8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001AFC8;
    }
    goto skip_0;
    // 0x8001AFB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8001AFBC: jal         0x80019C4C
    // 0x8001AFC0: nop

    func_80019C4C(rdram, ctx);
        goto after_0;
    // 0x8001AFC0: nop

    after_0:
    // 0x8001AFC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001AFC8:
    // 0x8001AFC8: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8001AFCC: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8001AFD0: slti        $at, $s0, 0x32
    ctx->r1 = SIGNED(ctx->r16) < 0X32 ? 1 : 0;
    // 0x8001AFD4: bne         $at, $zero, L_8001AFA4
    if (ctx->r1 != 0) {
        // 0x8001AFD8: nop
    
            goto L_8001AFA4;
    }
    // 0x8001AFD8: nop

    // 0x8001AFDC: jal         0x8001B5DC
    // 0x8001AFE0: nop

    func_8001B5DC(rdram, ctx);
        goto after_1;
    // 0x8001AFE0: nop

    after_1:
    // 0x8001AFE4: jal         0x8001B140
    // 0x8001AFE8: nop

    func_8001B140(rdram, ctx);
        goto after_2;
    // 0x8001AFE8: nop

    after_2:
    // 0x8001AFEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001AFF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001AFF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AFF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001AFFC: jr          $ra
    // 0x8001B000: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001B000: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806DEEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DEEA4: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806DEEA8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806DEEAC: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(637, 0X170) << 16);
    // 0x806DEEB0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806DEEB4: addiu       $t7, $t7, -0x1060
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(637, 0X170));
    // 0x806DEEB8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806DEEBC: lui         $t9, 0x806E
    ctx->r25 = S32(RELOC_HI16(637, 0X38) << 16);
    // 0x806DEEC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806DEEC4: addiu       $t9, $t9, -0x1198
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(637, 0X38));
    // 0x806DEEC8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806DEECC: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x806DEED0: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806DEED4: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x806DEED8: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x806DEEDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806DEEE0: jr          $ra
    // 0x806DEEE4: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    return;
    // 0x806DEEE4: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_8066B57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B57C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066B580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066B584: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8066B588: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(514, 0X2690) << 16);
    // 0x8066B58C: addiu       $t6, $t6, -0x2D10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(514, 0X2690));
    // 0x8066B590: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8066B594: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8066B598: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8066B59C: sw          $zero, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = 0;
    // 0x8066B5A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B5A4: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8066B5A8: jal         0x8066B970
    // 0x8066B5AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8066B970(rdram, ctx);
        goto after_0;
    // 0x8066B5AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8066B5B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066B5B4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8066B5B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8066B5BC: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8066B5C0: jr          $ra
    // 0x8066B5C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8066B5C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8003BC2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BC2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003BC30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003BC34: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8003BC38: addiu       $t6, $zero, 0x401D
    ctx->r14 = ADD32(0, 0X401D);
    // 0x8003BC3C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8003BC40: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003BC44: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8003BC48: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003BC4C: jal         0x8003BB94
    // 0x8003BC50: lw          $a3, 0x4278($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4278);
    func_8003BB94(rdram, ctx);
        goto after_0;
    // 0x8003BC50: lw          $a3, 0x4278($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X4278);
    after_0:
    // 0x8003BC54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BC58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003BC5C: jr          $ra
    // 0x8003BC60: nop

    return;
    // 0x8003BC60: nop

;}
RECOMP_FUNC void func_804BB534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BB538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB53C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804BB540: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(188, 0XB68) << 16);
    // 0x804BB544: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804BB548: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BB54C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804BB550: lw          $t8, -0x4938($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(188, 0XB68));
    // 0x804BB554: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804BB558: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x804BB55C: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x804BB560: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x804BB564: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x804BB568: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x804BB56C: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x804BB570: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x804BB574: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x804BB578: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x804BB57C: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x804BB580: jal         0x80048378
    // 0x804BB584: sw          $t8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r24;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x804BB584: sw          $t8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r24;
    after_0:
    // 0x804BB588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BB58C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BB590: jr          $ra
    // 0x804BB594: nop

    return;
    // 0x804BB594: nop

;}
RECOMP_FUNC void func_8003CDF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CDF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CDF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003CDF8: jal         0x8004700C
    // 0x8003CDFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003CDFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003CE00: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8003CE04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003CE08: beq         $v0, $zero, L_8003CE78
    if (ctx->r2 == 0) {
        // 0x8003CE0C: lbu         $v1, 0x30($t6)
        ctx->r3 = MEM_BU(ctx->r14, 0X30);
            goto L_8003CE78;
    }
    // 0x8003CE0C: lbu         $v1, 0x30($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X30);
    // 0x8003CE10: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003CE14: lbu         $t7, 0x111($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X111);
    // 0x8003CE18: beql        $t7, $zero, L_8003CE2C
    if (ctx->r15 == 0) {
        // 0x8003CE1C: lbu         $t8, 0xF4($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0XF4);
            goto L_8003CE2C;
    }
    goto skip_0;
    // 0x8003CE1C: lbu         $t8, 0xF4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF4);
    skip_0:
    // 0x8003CE20: b           L_8003CE78
    // 0x8003CE24: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
        goto L_8003CE78;
    // 0x8003CE24: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x8003CE28: lbu         $t8, 0xF4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF4);
L_8003CE2C:
    // 0x8003CE2C: bnel        $t8, $zero, L_8003CE40
    if (ctx->r24 != 0) {
        // 0x8003CE30: lbu         $t9, 0x30($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X30);
            goto L_8003CE40;
    }
    goto skip_1;
    // 0x8003CE30: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
    skip_1:
    // 0x8003CE34: b           L_8003CE78
    // 0x8003CE38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8003CE78;
    // 0x8003CE38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003CE3C: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
L_8003CE40:
    // 0x8003CE40: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x8003CE44: bnel        $t9, $at, L_8003CE58
    if (ctx->r25 != ctx->r1) {
        // 0x8003CE48: lwc1        $f4, 0xC8($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
            goto L_8003CE58;
    }
    goto skip_2;
    // 0x8003CE48: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
    skip_2:
    // 0x8003CE4C: b           L_8003CE78
    // 0x8003CE50: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_8003CE78;
    // 0x8003CE50: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8003CE54: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
L_8003CE58:
    // 0x8003CE58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003CE5C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8003CE60: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003CE64: nop

    // 0x8003CE68: bc1f        L_8003CE78
    if (!c1cs) {
        // 0x8003CE6C: nop
    
            goto L_8003CE78;
    }
    // 0x8003CE6C: nop

    // 0x8003CE70: b           L_8003CE78
    // 0x8003CE74: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
        goto L_8003CE78;
    // 0x8003CE74: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
L_8003CE78:
    // 0x8003CE78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8003CE7C: jr          $ra
    // 0x8003CE80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003CE80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005D87C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D87C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8005D880: lbu         $t6, -0x7D78($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7D78);
    // 0x8005D884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D88C: bnel        $t6, $zero, L_8005D8A8
    if (ctx->r14 != 0) {
        // 0x8005D890: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005D8A8;
    }
    goto skip_0;
    // 0x8005D890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005D894: beql        $a1, $zero, L_8005D8A8
    if (ctx->r5 == 0) {
        // 0x8005D898: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005D8A8;
    }
    goto skip_1;
    // 0x8005D898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8005D89C: jal         0x8005D83C
    // 0x8005D8A0: nop

    func_8005D83C(rdram, ctx);
        goto after_0;
    // 0x8005D8A0: nop

    after_0:
    // 0x8005D8A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D8A8:
    // 0x8005D8A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D8AC: jr          $ra
    // 0x8005D8B0: nop

    return;
    // 0x8005D8B0: nop

    // 0x8005D8B4: nop

    // 0x8005D8B8: nop

    // 0x8005D8BC: nop

;}
RECOMP_FUNC void func_8077FD3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FD3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8077FD40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8077FD44: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8077FD48: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8077FD4C: beq         $v0, $zero, L_8077FD5C
    if (ctx->r2 == 0) {
        // 0x8077FD50: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8077FD5C;
    }
    // 0x8077FD50: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8077FD54: b           L_8077FD8C
    // 0x8077FD58: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8077FD8C;
    // 0x8077FD58: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8077FD5C:
    // 0x8077FD5C: jal         0x8004700C
    // 0x8077FD60: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8077FD60: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8077FD64: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8077FD68: beq         $v0, $zero, L_8077FD8C
    if (ctx->r2 == 0) {
        // 0x8077FD6C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8077FD8C;
    }
    // 0x8077FD6C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8077FD70: lw          $t8, 0x1F4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1F4);
    // 0x8077FD74: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8077FD78: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8077FD7C: sb          $t7, 0x1B4($t8)
    MEM_B(0X1B4, ctx->r24) = ctx->r15;
    // 0x8077FD80: lw          $t9, 0x260($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X260);
    // 0x8077FD84: jal         0x80062DD4
    // 0x8077FD88: lbu         $a0, 0x15($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X15);
    func_80062DD4(rdram, ctx);
        goto after_1;
    // 0x8077FD88: lbu         $a0, 0x15($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X15);
    after_1:
L_8077FD8C:
    // 0x8077FD8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8077FD90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8077FD94: jr          $ra
    // 0x8077FD98: nop

    return;
    // 0x8077FD98: nop

;}
RECOMP_FUNC void func_8057F6B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F6B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057F6BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F6C0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8057F6C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8057F6C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057F6CC: jal         0x8057F680
    // 0x8057F6D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8057F680(rdram, ctx);
        goto after_0;
    // 0x8057F6D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8057F6D4: jal         0x8057F644
    // 0x8057F6D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8057F644(rdram, ctx);
        goto after_1;
    // 0x8057F6D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8057F6DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8057F6E0: sw          $zero, 0x130($t6)
    MEM_W(0X130, ctx->r14) = 0;
    // 0x8057F6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057F6EC: jr          $ra
    // 0x8057F6F0: nop

    return;
    // 0x8057F6F0: nop

;}
RECOMP_FUNC void func_8006D340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D340: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8006D344: jr          $ra
    // 0x8006D348: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x8006D348: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8078FAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078FAE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078FAEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078FAF0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078FAF4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8078FAF8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8078FAFC: bnel        $t6, $zero, L_8078FB2C
    if (ctx->r14 != 0) {
        // 0x8078FB00: lw          $a0, 0x1F4($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X1F4);
            goto L_8078FB2C;
    }
    goto skip_0;
    // 0x8078FB00: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    skip_0:
    // 0x8078FB04: jal         0x80045A34
    // 0x8078FB08: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8078FB08: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8078FB0C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8078FB10: bne         $v0, $zero, L_8078FB28
    if (ctx->r2 != 0) {
        // 0x8078FB14: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_8078FB28;
    }
    // 0x8078FB14: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x8078FB18: jal         0x800445A4
    // 0x8078FB1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8078FB1C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8078FB20: b           L_8078FB3C
    // 0x8078FB24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8078FB3C;
    // 0x8078FB24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078FB28:
    // 0x8078FB28: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
L_8078FB2C:
    // 0x8078FB2C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8078FB30: jal         0x80065728
    // 0x8078FB34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8078FB34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8078FB38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8078FB3C:
    // 0x8078FB3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078FB40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078FB44: jr          $ra
    // 0x8078FB48: nop

    return;
    // 0x8078FB48: nop

;}
RECOMP_FUNC void func_80036FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036FC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036FC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036FCC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80036FD0: jal         0x80036DE4
    // 0x80036FD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80036DE4(rdram, ctx);
        goto after_0;
    // 0x80036FD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80036FD8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80036FDC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80036FE0: lbu         $t6, 0x113($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X113);
    // 0x80036FE4: beq         $t6, $zero, L_80036FFC
    if (ctx->r14 == 0) {
        // 0x80036FE8: nop
    
            goto L_80036FFC;
    }
    // 0x80036FE8: nop

    // 0x80036FEC: jal         0x80036FA4
    // 0x80036FF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80036FA4(rdram, ctx);
        goto after_1;
    // 0x80036FF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80036FF4: b           L_8003701C
    // 0x80036FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003701C;
    // 0x80036FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036FFC:
    // 0x80036FFC: lbu         $t7, -0x766A($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X766A);
    // 0x80037000: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80037004: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80037008: beql        $t7, $zero, L_8003701C
    if (ctx->r15 == 0) {
        // 0x8003700C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003701C;
    }
    goto skip_0;
    // 0x8003700C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80037010: sb          $t8, 0x113($a1)
    MEM_B(0X113, ctx->r5) = ctx->r24;
    // 0x80037014: sw          $t9, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->r25;
    // 0x80037018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003701C:
    // 0x8003701C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80037020: jr          $ra
    // 0x80037024: nop

    return;
    // 0x80037024: nop

;}
RECOMP_FUNC void gMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F28: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80086F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086F30: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80086F34: jal         0x80086EA0
    // 0x80086F38: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80086F38: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80086F3C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80086F40: jal         0x80086DA0
    // 0x80086F44: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x80086F44: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x80086F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086F4C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80086F50: jr          $ra
    // 0x80086F54: nop

    return;
    // 0x80086F54: nop

;}
RECOMP_FUNC void func_8077751C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077751C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80777520: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80777524: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80777528: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8077752C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80777530: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80777534: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80777538: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8077753C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80777540: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80777544: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80777548: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8077754C: jal         0x80053924
    // 0x80777550: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x80777550: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    after_0:
    // 0x80777554: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80777558: lw          $t6, 0x1E0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1E0);
    // 0x8077755C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80777560: slti        $at, $t7, 0x50
    ctx->r1 = SIGNED(ctx->r15) < 0X50 ? 1 : 0;
    // 0x80777564: beq         $at, $zero, L_80777590
    if (ctx->r1 == 0) {
        // 0x80777568: sw          $t7, 0x1E0($s1)
        MEM_W(0X1E0, ctx->r17) = ctx->r15;
            goto L_80777590;
    }
    // 0x80777568: sw          $t7, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r15;
    // 0x8077756C: lhu         $t9, 0x26($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X26);
    // 0x80777570: lbu         $t0, 0x26($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X26);
    // 0x80777574: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80777578: beq         $t9, $at, L_80777590
    if (ctx->r25 == ctx->r1) {
        // 0x8077757C: andi        $t1, $t0, 0xF8
        ctx->r9 = ctx->r8 & 0XF8;
            goto L_80777590;
    }
    // 0x8077757C: andi        $t1, $t0, 0xF8
    ctx->r9 = ctx->r8 & 0XF8;
    // 0x80777580: xori        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 ^ 0X10;
    // 0x80777584: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80777588: bne         $t2, $zero, L_807775A0
    if (ctx->r10 != 0) {
        // 0x8077758C: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_807775A0;
    }
    // 0x8077758C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80777590:
    // 0x80777590: jal         0x800447C8
    // 0x80777594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80777594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80777598: b           L_80777658
    // 0x8077759C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80777658;
    // 0x8077759C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807775A0:
    // 0x807775A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807775A4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x807775A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807775AC: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x807775B0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x807775B4: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x807775B8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x807775BC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x807775C0: nop

    // 0x807775C4: bc1f        L_807775D8
    if (!c1cs) {
        // 0x807775C8: nop
    
            goto L_807775D8;
    }
    // 0x807775C8: nop

    // 0x807775CC: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x807775D0: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x807775D4: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
L_807775D8:
    // 0x807775D8: jal         0x80066DE4
    // 0x807775DC: nop

    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x807775DC: nop

    after_2:
    // 0x807775E0: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x807775E4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807775E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807775EC: swc1        $f10, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f10.u32l;
    // 0x807775F0: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x807775F4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x807775F8: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x807775FC: jal         0x80066DE4
    // 0x80777600: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x80777600: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x80777604: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(775, 0X4C0) << 16);
    // 0x80777608: lwc1        $f4, 0x78D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(775, 0X4C0));
    // 0x8077760C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80777610: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80777614: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80777618: lwc1        $f16, 0x78($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
    // 0x8077761C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80777620: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80777624: swc1        $f18, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f18.u32l;
    // 0x80777628: jal         0x80066DE4
    // 0x8077762C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8077762C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_4:
    // 0x80777630: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80777634: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80777638: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(775, 0X4C4) << 16);
    // 0x8077763C: lwc1        $f6, 0x78D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(775, 0X4C4));
    // 0x80777640: lwc1        $f16, 0x7C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x80777644: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80777648: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8077764C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80777650: swc1        $f18, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f18.u32l;
    // 0x80777654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80777658:
    // 0x80777658: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8077765C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80777660: jr          $ra
    // 0x80777664: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80777664: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005074C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005074C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050754: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x80050758: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8005075C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80050760: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80050764: beq         $t8, $zero, L_80050774
    if (ctx->r24 == 0) {
        // 0x80050768: sb          $t7, 0x8($a0)
        MEM_B(0X8, ctx->r4) = ctx->r15;
            goto L_80050774;
    }
    // 0x80050768: sb          $t7, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r15;
    // 0x8005076C: b           L_80050780
    // 0x80050770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050780;
    // 0x80050770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050774:
    // 0x80050774: jal         0x80065728
    // 0x80050778: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80050778: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8005077C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80050780:
    // 0x80050780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050788: jr          $ra
    // 0x8005078C: nop

    return;
    // 0x8005078C: nop

;}
RECOMP_FUNC void func_80048B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048B5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048B64: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80048B68: addiu       $a1, $zero, 0xC45
    ctx->r5 = ADD32(0, 0XC45);
    // 0x80048B6C: bne         $v0, $zero, L_80048B88
    if (ctx->r2 != 0) {
        // 0x80048B70: nop
    
            goto L_80048B88;
    }
    // 0x80048B70: nop

    // 0x80048B74: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80048B78: jal         0x80071380
    // 0x80048B7C: addiu       $a0, $a0, 0x850
    ctx->r4 = ADD32(ctx->r4, 0X850);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80048B7C: addiu       $a0, $a0, 0x850
    ctx->r4 = ADD32(ctx->r4, 0X850);
    after_0:
    // 0x80048B80: b           L_80048B94
    // 0x80048B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048B94;
    // 0x80048B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048B88:
    // 0x80048B88: jalr        $v0
    // 0x80048B8C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80048B8C: nop

    after_1:
    // 0x80048B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048B94:
    // 0x80048B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048B98: jr          $ra
    // 0x80048B9C: nop

    return;
    // 0x80048B9C: nop

;}
RECOMP_FUNC void func_80584E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584E5C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584E60: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584E64: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584E68: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584E6C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584E70: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584E74: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584E78: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584E7C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584E80: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584E84: jr          $ra
    // 0x80584E88: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584E88: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8042EA3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EA3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042EA40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042EA44: jal         0x8042E298
    // 0x8042EA48: nop

    func_8042E298(rdram, ctx);
        goto after_0;
    // 0x8042EA48: nop

    after_0:
    // 0x8042EA4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042EA50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042EA54: jr          $ra
    // 0x8042EA58: nop

    return;
    // 0x8042EA58: nop

;}
RECOMP_FUNC void func_80675D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675D48: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80675D4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80675D50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80675D54: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x80675D58: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675D5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80675D60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80675D64: jal         0x80049D74
    // 0x80675D68: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x80675D68: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80675D6C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80675D70: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x80675D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80675D78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80675D7C: jal         0x8004D150
    // 0x80675D80: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x80675D80: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x80675D84: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80675D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80675D8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80675D90: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80675D94: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80675D98: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x80675D9C: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x80675DA0: beql        $t0, $zero, L_80675DC8
    if (ctx->r8 == 0) {
        // 0x80675DA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80675DC8;
    }
    goto skip_0;
    // 0x80675DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80675DA8: jal         0x80677A88
    // 0x80675DAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80677A88(rdram, ctx);
        goto after_2;
    // 0x80675DAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80675DB0: jal         0x80675B9C
    // 0x80675DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675B9C(rdram, ctx);
        goto after_3;
    // 0x80675DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80675DB8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80675DBC: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x80675DC0: sh          $t1, 0x2($t2)
    MEM_H(0X2, ctx->r10) = ctx->r9;
    // 0x80675DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80675DC8:
    // 0x80675DC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80675DCC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80675DD0: jr          $ra
    // 0x80675DD4: nop

    return;
    // 0x80675DD4: nop

;}
RECOMP_FUNC void func_80452D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452D28: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452D2C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452D30: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80452D34: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x80452D38: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452D3C: ori         $at, $at, 0x6DB4
    ctx->r1 = ctx->r1 | 0X6DB4;
    // 0x80452D40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80452D44: jal         0x80452A64
    // 0x80452D48: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    func_80452A64(rdram, ctx);
        goto after_0;
    // 0x80452D48: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    after_0:
    // 0x80452D4C: bne         $v0, $zero, L_80452D64
    if (ctx->r2 != 0) {
        // 0x80452D50: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80452D64;
    }
    // 0x80452D50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80452D54: jal         0x80452A14
    // 0x80452D58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80452A14(rdram, ctx);
        goto after_1;
    // 0x80452D58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80452D5C: b           L_80452D70
    // 0x80452D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452D70;
    // 0x80452D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452D64:
    // 0x80452D64: jal         0x80452720
    // 0x80452D68: nop

    func_80452720(rdram, ctx);
        goto after_2;
    // 0x80452D68: nop

    after_2:
    // 0x80452D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452D70:
    // 0x80452D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452D74: jr          $ra
    // 0x80452D78: nop

    return;
    // 0x80452D78: nop

;}
RECOMP_FUNC void __osPfsDeclearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FD4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80087FD8: lbu         $t6, 0x63($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X63);
    // 0x80087FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087FE0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80087FE4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80087FE8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80087FEC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80087FF0: blez        $t6, L_80088004
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80087FF4: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_80088004;
    }
    // 0x80087FF4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80087FF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80087FFC: b           L_80088010
    // 0x80088000: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
        goto L_80088010;
    // 0x80088000: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_80088004:
    // 0x80088004: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80088008: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x8008800C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_80088010:
    // 0x80088010: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80088014: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x80088018: beq         $at, $zero, L_80088054
    if (ctx->r1 == 0) {
        // 0x8008801C: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_80088054;
    }
    // 0x8008801C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_80088020:
    // 0x80088020: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80088024: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80088028: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008802C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80088030: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80088034: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x80088038: beq         $t5, $at, L_80088054
    if (ctx->r13 == ctx->r1) {
        // 0x8008803C: nop
    
            goto L_80088054;
    }
    // 0x8008803C: nop

    // 0x80088040: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80088044: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80088048: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x8008804C: bne         $at, $zero, L_80088020
    if (ctx->r1 != 0) {
        // 0x80088050: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_80088020;
    }
    // 0x80088050: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_80088054:
    // 0x80088054: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80088058: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8008805C: bne         $t8, $at, L_80088078
    if (ctx->r24 != ctx->r1) {
        // 0x80088060: nop
    
            goto L_80088078;
    }
    // 0x80088060: nop

    // 0x80088064: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80088068: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008806C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80088070: b           L_80088228
    // 0x80088074: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80088228;
    // 0x80088074: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80088078:
    // 0x80088078: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8008807C:
    // 0x8008807C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80088080: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x80088084: sb          $zero, 0x24($t1)
    MEM_B(0X24, ctx->r9) = 0;
    // 0x80088088: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8008808C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80088090: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x80088094: bne         $at, $zero, L_8008807C
    if (ctx->r1 != 0) {
        // 0x80088098: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_8008807C;
    }
    // 0x80088098: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8008809C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800880A0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800880A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800880A8: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x800880AC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800880B0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800880B4: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800880B8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800880BC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800880C0: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800880C4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800880C8: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x800880CC: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800880D0: beq         $at, $zero, L_800881A4
    if (ctx->r1 == 0) {
        // 0x800880D4: slti        $at, $t9, 0x80
        ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
            goto L_800881A4;
    }
    // 0x800880D4: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800880D8: beq         $at, $zero, L_800881A4
    if (ctx->r1 == 0) {
        // 0x800880DC: nop
    
            goto L_800881A4;
    }
    // 0x800880DC: nop

L_800880E0:
    // 0x800880E0: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800880E4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800880E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800880EC: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800880F0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800880F4: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800880F8: bne         $t7, $at, L_80088170
    if (ctx->r15 != ctx->r1) {
        // 0x800880FC: nop
    
            goto L_80088170;
    }
    // 0x800880FC: nop

    // 0x80088100: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80088104: lbu         $t8, 0x63($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X63);
    // 0x80088108: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8008810C: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x80088110: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x80088114: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x80088118: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8008811C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80088120: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80088124: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80088128: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8008812C: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x80088130: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x80088134: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80088138: jal         0x80088238
    // 0x8008813C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    static_4_80088238(rdram, ctx);
        goto after_0;
    // 0x8008813C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x80088140: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80088144: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80088148: beq         $t2, $zero, L_80088158
    if (ctx->r10 == 0) {
        // 0x8008814C: nop
    
            goto L_80088158;
    }
    // 0x8008814C: nop

    // 0x80088150: b           L_80088228
    // 0x80088154: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_80088228;
    // 0x80088154: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80088158:
    // 0x80088158: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8008815C: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80088160: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80088164: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80088168: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x8008816C: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
L_80088170:
    // 0x80088170: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80088174: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80088178: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8008817C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x80088180: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80088184: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80088188: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8008818C: beq         $at, $zero, L_800881A4
    if (ctx->r1 == 0) {
        // 0x80088190: nop
    
            goto L_800881A4;
    }
    // 0x80088190: nop

    // 0x80088194: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80088198: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x8008819C: bne         $at, $zero, L_800880E0
    if (ctx->r1 != 0) {
        // 0x800881A0: nop
    
            goto L_800880E0;
    }
    // 0x800881A0: nop

L_800881A4:
    // 0x800881A4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800881A8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800881AC: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800881B0: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800881B4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800881B8: bne         $t1, $at, L_800881EC
    if (ctx->r9 != ctx->r1) {
        // 0x800881BC: nop
    
            goto L_800881EC;
    }
    // 0x800881BC: nop

    // 0x800881C0: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800881C4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800881C8: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x800881CC: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800881D0: beq         $at, $zero, L_800881EC
    if (ctx->r1 == 0) {
        // 0x800881D4: nop
    
            goto L_800881EC;
    }
    // 0x800881D4: nop

    // 0x800881D8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800881DC: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800881E0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800881E4: b           L_80088228
    // 0x800881E8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_80088228;
    // 0x800881E8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800881EC:
    // 0x800881EC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800881F0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800881F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800881F8: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800881FC: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x80088200: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x80088204: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x80088208: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8008820C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80088210: jal         0x80088238
    // 0x80088214: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    static_4_80088238(rdram, ctx);
        goto after_1;
    // 0x80088214: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80088218: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8008821C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80088220: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x80088224: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80088228:
    // 0x80088228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008822C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80088230: jr          $ra
    // 0x80088234: nop

    return;
    // 0x80088234: nop

;}
RECOMP_FUNC void func_806F9C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9C30: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(700, 0X10) << 16);
    // 0x806F9C34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x806F9C38: jr          $ra
    // 0x806F9C3C: addiu       $v0, $v0, -0x63C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X10));
    return;
    // 0x806F9C3C: addiu       $v0, $v0, -0x63C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(700, 0X10));
;}
RECOMP_FUNC void func_8064BC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BC7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BC80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BC84: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064BC88: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064BC8C: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8064BC90: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064BC94: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8064BC98: nop

    // 0x8064BC9C: bc1fl       L_8064BCD8
    if (!c1cs) {
        // 0x8064BCA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064BCD8;
    }
    goto skip_0;
    // 0x8064BCA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064BCA4: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064BCA8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064BCAC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064BCB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064BCB4: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8064BCB8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064BCBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064BCC0: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x8064BCC4: jal         0x8064BF74
    // 0x8064BCC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8064BF74(rdram, ctx);
        goto after_0;
    // 0x8064BCC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064BCCC: jal         0x8064A40C
    // 0x8064BCD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8064A40C(rdram, ctx);
        goto after_1;
    // 0x8064BCD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8064BCD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064BCD8:
    // 0x8064BCD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BCDC: jr          $ra
    // 0x8064BCE0: nop

    return;
    // 0x8064BCE0: nop

;}
RECOMP_FUNC void func_805AB308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB308: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805AB30C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805AB310: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805AB314: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805AB318: jal         0x8004700C
    // 0x805AB31C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805AB31C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x805AB320: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x805AB324: jal         0x805AAF60
    // 0x805AB328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805AAF60(rdram, ctx);
        goto after_1;
    // 0x805AB328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805AB32C: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x805AB330: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x805AB334: jal         0x80065ABC
    // 0x805AB338: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_2;
    // 0x805AB338: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_2:
    // 0x805AB33C: beq         $s1, $zero, L_805AB39C
    if (ctx->r17 == 0) {
        // 0x805AB340: swc1        $f0, 0xC8($s0)
        MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
            goto L_805AB39C;
    }
    // 0x805AB340: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x805AB344: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XB10) << 16);
    // 0x805AB348: lwc1        $f4, -0x45B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB10));
    // 0x805AB34C: lwc1        $f0, 0xEC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x805AB350: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XB14) << 16);
    // 0x805AB354: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x805AB358: nop

    // 0x805AB35C: bc1tl       L_805AB3A0
    if (c1cs) {
        // 0x805AB360: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_805AB3A0;
    }
    goto skip_0;
    // 0x805AB360: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x805AB364: lwc1        $f6, -0x45AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB14));
    // 0x805AB368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AB36C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AB370: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x805AB374: nop

    // 0x805AB378: bc1tl       L_805AB3A0
    if (c1cs) {
        // 0x805AB37C: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_805AB3A0;
    }
    goto skip_1;
    // 0x805AB37C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x805AB380: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x805AB384: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805AB388: jal         0x805AB914
    // 0x805AB38C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_805AB914(rdram, ctx);
        goto after_3;
    // 0x805AB38C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_3:
    // 0x805AB390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805AB394: jal         0x805AB24C
    // 0x805AB398: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_805AB24C(rdram, ctx);
        goto after_4;
    // 0x805AB398: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
L_805AB39C:
    // 0x805AB39C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_805AB3A0:
    // 0x805AB3A0: lwc1        $f8, 0xC8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x805AB3A4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805AB3A8: nop

    // 0x805AB3AC: bc1fl       L_805AB3E4
    if (!c1cs) {
        // 0x805AB3B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805AB3E4;
    }
    goto skip_2;
    // 0x805AB3B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805AB3B4: lwc1        $f10, 0xD4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XD4);
    // 0x805AB3B8: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x805AB3BC: nop

    // 0x805AB3C0: bc1fl       L_805AB3E4
    if (!c1cs) {
        // 0x805AB3C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805AB3E4;
    }
    goto skip_3;
    // 0x805AB3C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x805AB3C8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805AB3CC: jal         0x80067BBC
    // 0x805AB3D0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x805AB3D0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x805AB3D4: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    // 0x805AB3D8: jal         0x80067818
    // 0x805AB3DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x805AB3DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x805AB3E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805AB3E4:
    // 0x805AB3E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805AB3E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805AB3EC: jr          $ra
    // 0x805AB3F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805AB3F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80008378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008378: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000837C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80008380: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80008384: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80008388: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000838C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80008390: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80008394: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80008398: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x8000839C: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800083A0: lui         $s7, 0x800B
    ctx->r23 = S32(0X800B << 16);
    // 0x800083A4: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800083A8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800083AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800083B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800083B4: lw          $s6, 0x6A7C($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X6A7C);
    // 0x800083B8: addiu       $s7, $s7, 0x4DD0
    ctx->r23 = ADD32(ctx->r23, 0X4DD0);
    // 0x800083BC: addiu       $s2, $s2, 0x4D10
    ctx->r18 = ADD32(ctx->r18, 0X4D10);
    // 0x800083C0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800083C4: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800083C8: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x800083CC: lw          $v0, 0x12DC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X12DC);
L_800083D0:
    // 0x800083D0: beql        $v0, $s3, L_80008404
    if (ctx->r2 == ctx->r19) {
        // 0x800083D4: addiu       $s0, $s2, 0x12CC
        ctx->r16 = ADD32(ctx->r18, 0X12CC);
            goto L_80008404;
    }
    goto skip_0;
    // 0x800083D4: addiu       $s0, $s2, 0x12CC
    ctx->r16 = ADD32(ctx->r18, 0X12CC);
    skip_0:
    // 0x800083D8: bne         $v0, $s4, L_800084C8
    if (ctx->r2 != ctx->r20) {
        // 0x800083DC: addiu       $s0, $s2, 0x12CC
        ctx->r16 = ADD32(ctx->r18, 0X12CC);
            goto L_800084C8;
    }
    // 0x800083DC: addiu       $s0, $s2, 0x12CC
    ctx->r16 = ADD32(ctx->r18, 0X12CC);
    // 0x800083E0: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800083E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800083E8: jal         0x800824B0
    // 0x800083EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800083EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_0:
    // 0x800083F0: beql        $fp, $zero, L_80008404
    if (ctx->r30 == 0) {
        // 0x800083F4: addiu       $s0, $s2, 0x12CC
        ctx->r16 = ADD32(ctx->r18, 0X12CC);
            goto L_80008404;
    }
    goto skip_1;
    // 0x800083F4: addiu       $s0, $s2, 0x12CC
    ctx->r16 = ADD32(ctx->r18, 0X12CC);
    skip_1:
    // 0x800083F8: b           L_800084C8
    // 0x800083FC: sw          $s5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r21;
        goto L_800084C8;
    // 0x800083FC: sw          $s5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r21;
    // 0x80008400: addiu       $s0, $s2, 0x12CC
    ctx->r16 = ADD32(ctx->r18, 0X12CC);
L_80008404:
    // 0x80008404: lw          $s1, 0x14($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X14);
    // 0x80008408: sw          $s4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r20;
    // 0x8000840C: bne         $s1, $zero, L_8000842C
    if (ctx->r17 != 0) {
        // 0x80008410: slti        $at, $s1, 0x400
        ctx->r1 = SIGNED(ctx->r17) < 0X400 ? 1 : 0;
            goto L_8000842C;
    }
    // 0x80008410: slti        $at, $s1, 0x400
    ctx->r1 = SIGNED(ctx->r17) < 0X400 ? 1 : 0;
    // 0x80008414: jal         0x80008304
    // 0x80008418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80008304(rdram, ctx);
        goto after_1;
    // 0x80008418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000841C: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x80008420: sw          $s5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r21;
    // 0x80008424: b           L_800084C8
    // 0x80008428: sb          $s3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r19;
        goto L_800084C8;
    // 0x80008428: sb          $s3, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r19;
L_8000842C:
    // 0x8000842C: beql        $at, $zero, L_80008474
    if (ctx->r1 == 0) {
        // 0x80008430: lbu         $t8, 0x0($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X0);
            goto L_80008474;
    }
    goto skip_2;
    // 0x80008430: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    skip_2:
    // 0x80008434: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80008438: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000843C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80008440: bne         $s3, $t7, L_80008460
    if (ctx->r19 != ctx->r15) {
        // 0x80008444: nop
    
            goto L_80008460;
    }
    // 0x80008444: nop

    // 0x80008448: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8000844C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80008450: jal         0x80008588
    // 0x80008454: lh          $a3, 0x2($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X2);
    func_80008588(rdram, ctx);
        goto after_2;
    // 0x80008454: lh          $a3, 0x2($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X2);
    after_2:
    // 0x80008458: b           L_80008468
    // 0x8000845C: nop

        goto L_80008468;
    // 0x8000845C: nop

L_80008460:
    // 0x80008460: jal         0x80008504
    // 0x80008464: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80008504(rdram, ctx);
        goto after_3;
    // 0x80008464: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_80008468:
    // 0x80008468: b           L_800084C8
    // 0x8000846C: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
        goto L_800084C8;
    // 0x8000846C: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80008470: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
L_80008474:
    // 0x80008474: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80008478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000847C: bne         $s3, $t8, L_8000849C
    if (ctx->r19 != ctx->r24) {
        // 0x80008480: nop
    
            goto L_8000849C;
    }
    // 0x80008480: nop

    // 0x80008484: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80008488: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8000848C: jal         0x80008588
    // 0x80008490: lh          $a3, 0x2($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X2);
    func_80008588(rdram, ctx);
        goto after_4;
    // 0x80008490: lh          $a3, 0x2($s6)
    ctx->r7 = MEM_H(ctx->r22, 0X2);
    after_4:
    // 0x80008494: b           L_800084A8
    // 0x80008498: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
        goto L_800084A8;
    // 0x80008498: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
L_8000849C:
    // 0x8000849C: jal         0x80008504
    // 0x800084A0: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_80008504(rdram, ctx);
        goto after_5;
    // 0x800084A0: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_5:
    // 0x800084A4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
L_800084A8:
    // 0x800084A8: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x800084AC: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x800084B0: addiu       $t0, $t9, -0x400
    ctx->r8 = ADD32(ctx->r25, -0X400);
    // 0x800084B4: addiu       $t2, $t1, 0x400
    ctx->r10 = ADD32(ctx->r9, 0X400);
    // 0x800084B8: addiu       $t4, $t3, 0x400
    ctx->r12 = ADD32(ctx->r11, 0X400);
    // 0x800084BC: sw          $t0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r8;
    // 0x800084C0: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800084C4: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
L_800084C8:
    // 0x800084C8: addiu       $s2, $s2, 0x60
    ctx->r18 = ADD32(ctx->r18, 0X60);
    // 0x800084CC: bnel        $s2, $s7, L_800083D0
    if (ctx->r18 != ctx->r23) {
        // 0x800084D0: lw          $v0, 0x12DC($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X12DC);
            goto L_800083D0;
    }
    goto skip_3;
    // 0x800084D0: lw          $v0, 0x12DC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X12DC);
    skip_3:
    // 0x800084D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800084D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800084DC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800084E0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800084E4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800084E8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800084EC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800084F0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800084F4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800084F8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800084FC: jr          $ra
    // 0x80008500: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80008500: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80023310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023318: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8002331C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80023320: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80023324: beql        $t6, $zero, L_80023340
    if (ctx->r14 == 0) {
        // 0x80023328: lbu         $t8, 0x18($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X18);
            goto L_80023340;
    }
    goto skip_0;
    // 0x80023328: lbu         $t8, 0x18($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18);
    skip_0:
    // 0x8002332C: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x80023330: jal         0x80061170
    // 0x80023334: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80061170(rdram, ctx);
        goto after_0;
    // 0x80023334: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80023338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002333C: lbu         $t8, 0x18($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18);
L_80023340:
    // 0x80023340: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80023344: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80023348: beql        $t8, $at, L_800233A8
    if (ctx->r24 == ctx->r1) {
        // 0x8002334C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800233A8;
    }
    goto skip_1;
    // 0x8002334C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80023350: lw          $t9, 0x34($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X34);
    // 0x80023354: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x80023358: lwc1        $f2, 0xB4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XB4);
    // 0x8002335C: slti        $at, $t9, 0xA0
    ctx->r1 = SIGNED(ctx->r25) < 0XA0 ? 1 : 0;
    // 0x80023360: beq         $at, $zero, L_80023380
    if (ctx->r1 == 0) {
        // 0x80023364: lwc1        $f0, 0x3C($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_80023380;
    }
    // 0x80023364: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80023368: lui         $at, 0xC310
    ctx->r1 = S32(0XC310 << 16);
    // 0x8002336C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80023370: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80023374: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80023378: b           L_80023394
    // 0x8002337C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
        goto L_80023394;
    // 0x8002337C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
L_80023380:
    // 0x80023380: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x80023384: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80023388: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8002338C: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80023390: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
L_80023394:
    // 0x80023394: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80023398: sub.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x8002339C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800233A0: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x800233A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800233A8:
    // 0x800233A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800233AC: jr          $ra
    // 0x800233B0: nop

    return;
    // 0x800233B0: nop

;}
RECOMP_FUNC void func_80033160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033160: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80033164: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x80033168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003316C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033170: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x80033174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80033178: andi        $t8, $t7, 0x600F
    ctx->r24 = ctx->r15 & 0X600F;
    // 0x8003317C: beq         $t8, $zero, L_80033194
    if (ctx->r24 == 0) {
        // 0x80033180: nop
    
            goto L_80033194;
    }
    // 0x80033180: nop

    // 0x80033184: jal         0x8002D76C
    // 0x80033188: nop

    func_8002D76C(rdram, ctx);
        goto after_0;
    // 0x80033188: nop

    after_0:
    // 0x8003318C: b           L_80033194
    // 0x80033190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80033194;
    // 0x80033190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80033194:
    // 0x80033194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003319C: jr          $ra
    // 0x800331A0: nop

    return;
    // 0x800331A0: nop

;}
RECOMP_FUNC void func_80561804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80561804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80561808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8056180C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80561810: jal         0x80045A34
    // 0x80561814: addiu       $a1, $zero, 0x880
    ctx->r5 = ADD32(0, 0X880);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80561814: addiu       $a1, $zero, 0x880
    ctx->r5 = ADD32(0, 0X880);
    after_0:
    // 0x80561818: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8056181C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x80561820: bne         $v0, $zero, L_80561830
    if (ctx->r2 != 0) {
        // 0x80561824: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80561830;
    }
    // 0x80561824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80561828: b           L_80561834
    // 0x8056182C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80561834;
    // 0x8056182C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80561830:
    // 0x80561830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80561834:
    // 0x80561834: jr          $ra
    // 0x80561838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80561838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8069D784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D78C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8069D790: jal         0x80045A34
    // 0x8069D794: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8069D794: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x8069D798: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8069D79C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8069D7A0: bne         $v0, $zero, L_8069D7B0
    if (ctx->r2 != 0) {
        // 0x8069D7A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8069D7B0;
    }
    // 0x8069D7A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D7A8: b           L_8069D7B4
    // 0x8069D7AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8069D7B4;
    // 0x8069D7AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8069D7B0:
    // 0x8069D7B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8069D7B4:
    // 0x8069D7B4: jr          $ra
    // 0x8069D7B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8069D7B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80461778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046177C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80461780: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80461784: jal         0x80047090
    // 0x80461788: addiu       $a0, $zero, 0x4500
    ctx->r4 = ADD32(0, 0X4500);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80461788: addiu       $a0, $zero, 0x4500
    ctx->r4 = ADD32(0, 0X4500);
    after_0:
    // 0x8046178C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80461790: bne         $v0, $at, L_804617A0
    if (ctx->r2 != ctx->r1) {
        // 0x80461794: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804617A0;
    }
    // 0x80461794: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80461798: b           L_80461810
    // 0x8046179C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80461810;
    // 0x8046179C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804617A0:
    // 0x804617A0: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x804617A4: lui         $a3, 0x3B03
    ctx->r7 = S32(0X3B03 << 16);
    // 0x804617A8: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x804617AC: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804617B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x804617B4: lui         $a2, 0xC30C
    ctx->r6 = S32(0XC30C << 16);
    // 0x804617B8: jal         0x8004613C
    // 0x804617BC: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804617BC: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x804617C0: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x804617C4: bne         $v0, $zero, L_804617D4
    if (ctx->r2 != 0) {
        // 0x804617C8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804617D4;
    }
    // 0x804617C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804617CC: b           L_80461810
    // 0x804617D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80461810;
    // 0x804617D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804617D4:
    // 0x804617D4: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x804617D8: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x804617DC: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x804617E0: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x804617E4: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x804617E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804617EC: jal         0x80047F9C
    // 0x804617F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804617F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x804617F4: jal         0x804625EC
    // 0x804617F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_804625EC(rdram, ctx);
        goto after_3;
    // 0x804617F8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x804617FC: bnel        $v0, $zero, L_80461810
    if (ctx->r2 != 0) {
        // 0x80461800: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80461810;
    }
    goto skip_0;
    // 0x80461800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80461804: b           L_80461810
    // 0x80461808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80461810;
    // 0x80461808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8046180C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80461810:
    // 0x80461810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80461814: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80461818: jr          $ra
    // 0x8046181C: nop

    return;
    // 0x8046181C: nop

;}
RECOMP_FUNC void func_80038CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038CB8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80038CBC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80038CC0: lui         $s2, 0x800F
    ctx->r18 = S32(0X800F << 16);
    // 0x80038CC4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80038CC8: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x80038CCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80038CD0: addiu       $s2, $s2, 0x7EA0
    ctx->r18 = ADD32(ctx->r18, 0X7EA0);
    // 0x80038CD4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80038CD8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80038CDC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80038CE0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80038CE4: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80038CE8: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80038CEC: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80038CF0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80038CF4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80038CF8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80038CFC: lwc1        $f20, 0xAF0($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0XAF0);
    // 0x80038D00: lwc1        $f24, 0x68($a2)
    ctx->f24.u32l = MEM_W(ctx->r6, 0X68);
    // 0x80038D04: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x80038D08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80038D0C: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x80038D10: lwc1        $f30, 0x144($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X144);
    // 0x80038D14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80038D18: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80038D1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80038D20: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80038D24: lwc1        $f28, 0x148($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X148);
    // 0x80038D28: addiu       $s3, $sp, 0x68
    ctx->r19 = ADD32(ctx->r29, 0X68);
    // 0x80038D2C: lwc1        $f0, 0xAE8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XAE8);
L_80038D30:
    // 0x80038D30: c.lt.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl < ctx->f0.fl;
    // 0x80038D34: nop

    // 0x80038D38: bc1t        L_80038D60
    if (c1cs) {
        // 0x80038D3C: nop
    
            goto L_80038D60;
    }
    // 0x80038D3C: nop

    // 0x80038D40: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x80038D44: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80038D48: bc1t        L_80038D60
    if (c1cs) {
        // 0x80038D4C: nop
    
            goto L_80038D60;
    }
    // 0x80038D4C: nop

    // 0x80038D50: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80038D54: swc1        $f26, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f26.u32l;
    // 0x80038D58: b           L_80038DD0
    // 0x80038D5C: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
        goto L_80038DD0;
    // 0x80038D5C: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
L_80038D60:
    // 0x80038D60: jal         0x80066E88
    // 0x80038D64: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80038D64: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80038D68: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80038D6C: lwc1        $f16, 0x78($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
    // 0x80038D70: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80038D74: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80038D78: nop

    // 0x80038D7C: mul.s       $f22, $f0, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80038D80: jal         0x80066DE4
    // 0x80038D84: nop

    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80038D84: nop

    after_1:
    // 0x80038D88: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80038D8C: lwc1        $f8, 0x7C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x80038D90: c.lt.s      $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f24.fl < ctx->f26.fl;
    // 0x80038D94: swc1        $f22, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f22.u32l;
    // 0x80038D98: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80038D9C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80038DA0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80038DA4: nop

    // 0x80038DA8: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80038DAC: bc1f        L_80038DCC
    if (!c1cs) {
        // 0x80038DB0: swc1        $f2, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
            goto L_80038DCC;
    }
    // 0x80038DB0: swc1        $f2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
    // 0x80038DB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80038DB8: nop

    // 0x80038DBC: add.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x80038DC0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80038DC4: b           L_80038DD0
    // 0x80038DC8: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
        goto L_80038DD0;
    // 0x80038DC8: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
L_80038DCC:
    // 0x80038DCC: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
L_80038DD0:
    // 0x80038DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80038DD4: jal         0x80038BD0
    // 0x80038DD8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80038BD0(rdram, ctx);
        goto after_2;
    // 0x80038DD8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80038DDC: beql        $v0, $zero, L_80038D30
    if (ctx->r2 == 0) {
        // 0x80038DE0: lwc1        $f0, 0xAE8($s2)
        ctx->f0.u32l = MEM_W(ctx->r18, 0XAE8);
            goto L_80038D30;
    }
    goto skip_0;
    // 0x80038DE0: lwc1        $f0, 0xAE8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XAE8);
    skip_0:
    // 0x80038DE4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80038DE8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80038DEC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80038DF0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80038DF4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80038DF8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80038DFC: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80038E00: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80038E04: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80038E08: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80038E0C: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80038E10: jr          $ra
    // 0x80038E14: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80038E14: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80462454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80462458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046245C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80462460: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80462464: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80462468: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X3820) << 16);
    // 0x8046246C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80462470: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80462474: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80462478: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8046247C: lw          $t8, 0x3DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(122, 0X3820));
    // 0x80462480: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80462484: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80462488: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8046248C: jal         0x80048490
    // 0x80462490: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80462490: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80462494: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80462498: jal         0x80048378
    // 0x8046249C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8046249C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804624A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804624A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804624A8: jr          $ra
    // 0x804624AC: nop

    return;
    // 0x804624AC: nop

;}
RECOMP_FUNC void func_806F9580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9580: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(697, 0X4A0) << 16);
    // 0x806F9584: addiu       $t6, $t6, -0x65E0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(697, 0X4A0));
    // 0x806F9588: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F958C: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(697, 0X3FC) << 16);
    // 0x806F9590: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x806F9594: sw          $t6, -0x72D4($at)
    MEM_W(-0X72D4, ctx->r1) = ctx->r14;
    // 0x806F9598: jr          $ra
    // 0x806F959C: addiu       $v0, $v0, -0x6684
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(697, 0X3FC));
    return;
    // 0x806F959C: addiu       $v0, $v0, -0x6684
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(697, 0X3FC));
;}
RECOMP_FUNC void func_8069E7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069E7C8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8069E7CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069E7D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8069E7D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8069E7D8: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069E7DC: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(577, 0X8F8) << 16);
    // 0x8069E7E0: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(577, 0X904) << 16);
    // 0x8069E7E4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8069E7E8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8069E7EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069E7F0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8069E7F4: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8069E7F8: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8069E7FC: lw          $t6, -0x1338($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(577, 0X8F8));
    // 0x8069E800: lw          $t7, -0x132C($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(577, 0X904));
    // 0x8069E804: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8069E808: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8069E80C: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8069E810: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8069E814: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8069E818: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8069E81C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8069E820: jal         0x8069E410
    // 0x8069E824: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    func_8069E410(rdram, ctx);
        goto after_0;
    // 0x8069E824: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    after_0:
    // 0x8069E828: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x8069E82C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8069E830: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8069E834: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8069E838: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8069E83C: bne         $t0, $zero, L_8069E8A0
    if (ctx->r8 != 0) {
        // 0x8069E840: sw          $t0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r8;
            goto L_8069E8A0;
    }
    // 0x8069E840: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x8069E844: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8069E848: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8069E84C: jal         0x800653D8
    // 0x8069E850: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x8069E850: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8069E854: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x8069E858: lw          $t4, -0x76F8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76F8);
    // 0x8069E85C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8069E860: andi        $t2, $v0, 0x3
    ctx->r10 = ctx->r2 & 0X3;
    // 0x8069E864: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8069E868: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8069E86C: lui         $a1, 0x806A
    ctx->r5 = S32(RELOC_HI16(577, 0X970) << 16);
    // 0x8069E870: lw          $t9, 0x6C($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X6C);
    // 0x8069E874: lui         $a2, 0x806A
    ctx->r6 = S32(RELOC_HI16(577, 0X97C) << 16);
    // 0x8069E878: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x8069E87C: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8069E880: lw          $a1, -0x12C0($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(577, 0X970));
    // 0x8069E884: lw          $a2, -0x12B4($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(577, 0X97C));
    // 0x8069E888: jalr        $t9
    // 0x8069E88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8069E88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8069E890: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8069E894: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8069E898: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8069E89C: sw          $t6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r14;
L_8069E8A0:
    // 0x8069E8A0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8069E8A4: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X960) << 16);
    // 0x8069E8A8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8069E8AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8069E8B0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8069E8B4: lwc1        $f4, -0x12D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X960));
    // 0x8069E8B8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8069E8BC: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x8069E8C0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8069E8C4: lwc1        $f0, 0x6C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x8069E8C8: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X950) << 16);
    // 0x8069E8CC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8069E8D0: lwc1        $f12, -0x12E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X950));
    // 0x8069E8D4: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X968) << 16);
    // 0x8069E8D8: lui         $t3, 0x806A
    ctx->r11 = S32(RELOC_HI16(577, 0X958) << 16);
    // 0x8069E8DC: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8069E8E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8069E8E4: addiu       $t3, $t3, -0x12D8
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(577, 0X958));
    // 0x8069E8E8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8069E8EC: nop

    // 0x8069E8F0: bc1fl       L_8069E904
    if (!c1cs) {
        // 0x8069E8F4: swc1        $f0, 0x6C($v1)
        MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
            goto L_8069E904;
    }
    goto skip_0;
    // 0x8069E8F4: swc1        $f0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
    skip_0:
    // 0x8069E8F8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8069E8FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8069E900: swc1        $f0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
L_8069E904:
    // 0x8069E904: lwc1        $f8, -0x12C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X968));
    // 0x8069E908: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8069E90C: lui         $t2, 0x806A
    ctx->r10 = S32(RELOC_HI16(577, 0X958) << 16);
    // 0x8069E910: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8069E914: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8069E918: addu        $a0, $s0, $t1
    ctx->r4 = ADD32(ctx->r16, ctx->r9);
    // 0x8069E91C: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8069E920: addiu       $t2, $t2, -0x12D8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(577, 0X958));
    // 0x8069E924: addu        $a1, $v0, $t2
    ctx->r5 = ADD32(ctx->r2, ctx->r10);
    // 0x8069E928: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8069E92C: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8069E930: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X9F8) << 16);
    // 0x8069E934: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8069E938: nop

    // 0x8069E93C: bc1f        L_8069E94C
    if (!c1cs) {
        // 0x8069E940: nop
    
            goto L_8069E94C;
    }
    // 0x8069E940: nop

    // 0x8069E944: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8069E948: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_8069E94C:
    // 0x8069E94C: bne         $a1, $t3, L_8069E9C4
    if (ctx->r5 != ctx->r11) {
        // 0x8069E950: swc1        $f0, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
            goto L_8069E9C4;
    }
    // 0x8069E950: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x8069E954: lwc1        $f16, -0x1238($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X9F8));
    // 0x8069E958: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0X9FC) << 16);
    // 0x8069E95C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069E960: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8069E964: nop

    // 0x8069E968: bc1f        L_8069E998
    if (!c1cs) {
        // 0x8069E96C: nop
    
            goto L_8069E998;
    }
    // 0x8069E96C: nop

    // 0x8069E970: lwc1        $f0, -0x1234($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0X9FC));
    // 0x8069E974: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(577, 0XA00) << 16);
    // 0x8069E978: lwc1        $f18, -0x1230($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(577, 0XA00));
    // 0x8069E97C: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8069E980: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8069E984: nop

    // 0x8069E988: bc1fl       L_8069E998
    if (!c1cs) {
        // 0x8069E98C: swc1        $f2, 0x10($s1)
        MEM_W(0X10, ctx->r17) = ctx->f2.u32l;
            goto L_8069E998;
    }
    goto skip_1;
    // 0x8069E98C: swc1        $f2, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f2.u32l;
    skip_1:
    // 0x8069E990: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8069E994: swc1        $f2, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f2.u32l;
L_8069E998:
    // 0x8069E998: bne         $a3, $zero, L_8069EA04
    if (ctx->r7 != 0) {
        // 0x8069E99C: nop
    
            goto L_8069EA04;
    }
    // 0x8069E99C: nop

    // 0x8069E9A0: jal         0x8069EC9C
    // 0x8069E9A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8069EC9C(rdram, ctx);
        goto after_3;
    // 0x8069E9A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8069E9A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8069E9AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8069E9B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069E9B4: jal         0x8069E4E8
    // 0x8069E9B8: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    func_8069E4E8(rdram, ctx);
        goto after_4;
    // 0x8069E9B8: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    after_4:
    // 0x8069E9BC: b           L_8069EA04
    // 0x8069E9C0: nop

        goto L_8069EA04;
    // 0x8069E9C0: nop

L_8069E9C4:
    // 0x8069E9C4: bne         $a3, $zero, L_8069EA04
    if (ctx->r7 != 0) {
        // 0x8069E9C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8069EA04;
    }
    // 0x8069E9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069E9CC: jal         0x8069EC9C
    // 0x8069E9D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8069EC9C(rdram, ctx);
        goto after_5;
    // 0x8069E9D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8069E9D4: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x8069E9D8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8069E9DC: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
    // 0x8069E9E0: sb          $t5, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r13;
    // 0x8069E9E4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8069E9E8: jal         0x80067BBC
    // 0x8069E9EC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x8069E9EC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x8069E9F0: addiu       $a0, $zero, 0x221
    ctx->r4 = ADD32(0, 0X221);
    // 0x8069E9F4: jal         0x80067818
    // 0x8069E9F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8069E9F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8069E9FC: jal         0x8069E4E8
    // 0x8069EA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8069E4E8(rdram, ctx);
        goto after_8;
    // 0x8069EA00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_8069EA04:
    // 0x8069EA04: jal         0x8069E654
    // 0x8069EA08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8069E654(rdram, ctx);
        goto after_9;
    // 0x8069EA08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8069EA0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8069EA10: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8069EA14: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8069EA18: jr          $ra
    // 0x8069EA1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8069EA1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_805814C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805814C4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805814C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805814CC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x805814D0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805814D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805814D8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805814DC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805814E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805814E4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805814E8: lui         $t1, 0x8058
    ctx->r9 = S32(RELOC_HI16(399, 0X4640) << 16);
    // 0x805814EC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805814F0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805814F4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805814F8: lw          $t1, 0x3450($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(399, 0X4640));
    // 0x805814FC: jr          $ra
    // 0x80581500: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80581500: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80672780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672780: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80672784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80672788: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067278C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80672790: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x80672794: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80672798: jal         0x80672750
    // 0x8067279C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80672750(rdram, ctx);
        goto after_0;
    // 0x8067279C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806727A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x806727A4: addiu       $v1, $zero, 0x3E8
    ctx->r3 = ADD32(0, 0X3E8);
    // 0x806727A8: lw          $t6, 0x1E0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1E0);
    // 0x806727AC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806727B0: slti        $at, $t7, 0x3C
    ctx->r1 = SIGNED(ctx->r15) < 0X3C ? 1 : 0;
    // 0x806727B4: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x806727B8: bne         $at, $zero, L_806728E0
    if (ctx->r1 != 0) {
        // 0x806727BC: sw          $t7, 0x1E0($a2)
        MEM_W(0X1E0, ctx->r6) = ctx->r15;
            goto L_806728E0;
    }
    // 0x806727BC: sw          $t7, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = ctx->r15;
    // 0x806727C0: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x806727C4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x806727C8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x806727CC: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x806727D0: bne         $v1, $zero, L_806727DC
    if (ctx->r3 != 0) {
        // 0x806727D4: nop
    
            goto L_806727DC;
    }
    // 0x806727D4: nop

    // 0x806727D8: break       7
    do_break(2154244056);
L_806727DC:
    // 0x806727DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806727E0: bne         $v1, $at, L_806727F4
    if (ctx->r3 != ctx->r1) {
        // 0x806727E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806727F4;
    }
    // 0x806727E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806727E8: bne         $v0, $at, L_806727F4
    if (ctx->r2 != ctx->r1) {
        // 0x806727EC: nop
    
            goto L_806727F4;
    }
    // 0x806727EC: nop

    // 0x806727F0: break       6
    do_break(2154244080);
L_806727F4:
    // 0x806727F4: mfhi        $v0
    ctx->r2 = hi;
    // 0x806727F8: mflo        $t9
    ctx->r25 = lo;
    // 0x806727FC: sw          $t9, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r25;
    // 0x80672800: nop

    // 0x80672804: div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // 0x80672808: bne         $a1, $zero, L_80672814
    if (ctx->r5 != 0) {
        // 0x8067280C: nop
    
            goto L_80672814;
    }
    // 0x8067280C: nop

    // 0x80672810: break       7
    do_break(2154244112);
L_80672814:
    // 0x80672814: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80672818: bne         $a1, $at, L_8067282C
    if (ctx->r5 != ctx->r1) {
        // 0x8067281C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8067282C;
    }
    // 0x8067281C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80672820: bne         $v0, $at, L_8067282C
    if (ctx->r2 != ctx->r1) {
        // 0x80672824: nop
    
            goto L_8067282C;
    }
    // 0x80672824: nop

    // 0x80672828: break       6
    do_break(2154244136);
L_8067282C:
    // 0x8067282C: mfhi        $v0
    ctx->r2 = hi;
    // 0x80672830: mflo        $t0
    ctx->r8 = lo;
    // 0x80672834: sw          $t0, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->r8;
    // 0x80672838: nop

    // 0x8067283C: div         $zero, $v0, $a3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r7)));
    // 0x80672840: bne         $a3, $zero, L_8067284C
    if (ctx->r7 != 0) {
        // 0x80672844: nop
    
            goto L_8067284C;
    }
    // 0x80672844: nop

    // 0x80672848: break       7
    do_break(2154244168);
L_8067284C:
    // 0x8067284C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80672850: bne         $a3, $at, L_80672864
    if (ctx->r7 != ctx->r1) {
        // 0x80672854: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80672864;
    }
    // 0x80672854: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80672858: bne         $v0, $at, L_80672864
    if (ctx->r2 != ctx->r1) {
        // 0x8067285C: nop
    
            goto L_80672864;
    }
    // 0x8067285C: nop

    // 0x80672860: break       6
    do_break(2154244192);
L_80672864:
    // 0x80672864: mflo        $t1
    ctx->r9 = lo;
    // 0x80672868: mfhi        $v0
    ctx->r2 = hi;
    // 0x8067286C: sw          $t1, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r9;
    // 0x80672870: sw          $v0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r2;
    // 0x80672874: lw          $a0, 0x1F4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1F4);
    // 0x80672878: jal         0x80671738
    // 0x8067287C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80671738(rdram, ctx);
        goto after_1;
    // 0x8067287C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80672880: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80672884: jal         0x80672C80
    // 0x80672888: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80672C80(rdram, ctx);
        goto after_2;
    // 0x80672888: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_2:
    // 0x8067288C: addiu       $a0, $zero, 0x206
    ctx->r4 = ADD32(0, 0X206);
    // 0x80672890: jal         0x80067818
    // 0x80672894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80672894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80672898: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8067289C: beql        $v0, $zero, L_806728B4
    if (ctx->r2 == 0) {
        // 0x806728A0: lw          $t3, 0x1C($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X1C);
            goto L_806728B4;
    }
    goto skip_0;
    // 0x806728A0: lw          $t3, 0x1C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C);
    skip_0:
    // 0x806728A4: lw          $t2, 0x1F4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1F4);
    // 0x806728A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806728AC: sw          $v1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r3;
    // 0x806728B0: lw          $t3, 0x1C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C);
L_806728B4:
    // 0x806728B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806728B8: lw          $t4, 0x1F4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1F4);
    // 0x806728BC: sw          $v1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r3;
    // 0x806728C0: lw          $t5, 0x20($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X20);
    // 0x806728C4: lw          $t6, 0x1F4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X1F4);
    // 0x806728C8: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x806728CC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x806728D0: beql        $v0, $zero, L_806728E4
    if (ctx->r2 == 0) {
        // 0x806728D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806728E4;
    }
    goto skip_1;
    // 0x806728D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806728D8: lw          $t7, 0x1F4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1F4);
    // 0x806728DC: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
L_806728E0:
    // 0x806728E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806728E4:
    // 0x806728E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806728E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806728EC: jr          $ra
    // 0x806728F0: nop

    return;
    // 0x806728F0: nop

;}
RECOMP_FUNC void func_80680D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680D5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80680D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680D64: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680D68: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80680D6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80680D70: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x80680D74: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80680D78: sll         $t6, $v1, 6
    ctx->r14 = S32(ctx->r3 << 6);
    // 0x80680D7C: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x80680D80: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80680D84: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80680D88: jal         0x80086F28
    // 0x80680D8C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    gMtxIdent(rdram, ctx);
        goto after_0;
    // 0x80680D8C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80680D90: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80680D94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80680D98: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80680D9C: jal         0x8007FE74
    // 0x80680DA0: lw          $a2, 0x88($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X88);
    func_8007FE74(rdram, ctx);
        goto after_1;
    // 0x80680DA0: lw          $a2, 0x88($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X88);
    after_1:
    // 0x80680DA4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80680DA8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80680DAC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80680DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80680DB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80680DB8: jr          $ra
    // 0x80680DBC: nop

    return;
    // 0x80680DBC: nop

;}
RECOMP_FUNC void func_80043C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80043C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043C14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80043C18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80043C1C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80043C20: jal         0x80043830
    // 0x80043C24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80043830(rdram, ctx);
        goto after_0;
    // 0x80043C24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80043C28: bne         $v0, $zero, L_80043C48
    if (ctx->r2 != 0) {
        // 0x80043C2C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80043C48;
    }
    // 0x80043C2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80043C30: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043C34: addiu       $a0, $a0, 0x370
    ctx->r4 = ADD32(ctx->r4, 0X370);
    // 0x80043C38: jal         0x80071380
    // 0x80043C3C: addiu       $a1, $zero, 0x23D
    ctx->r5 = ADD32(0, 0X23D);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80043C3C: addiu       $a1, $zero, 0x23D
    ctx->r5 = ADD32(0, 0X23D);
    after_1:
    // 0x80043C40: b           L_80043C84
    // 0x80043C44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80043C84;
    // 0x80043C44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80043C48:
    // 0x80043C48: lh          $a1, 0x1E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1E);
    // 0x80043C4C: jal         0x80057B28
    // 0x80043C50: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_80057B28(rdram, ctx);
        goto after_2;
    // 0x80043C50: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80043C54: bne         $v0, $zero, L_80043C68
    if (ctx->r2 != 0) {
        // 0x80043C58: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80043C68;
    }
    // 0x80043C58: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043C5C: addiu       $a0, $a0, 0x380
    ctx->r4 = ADD32(ctx->r4, 0X380);
    // 0x80043C60: jal         0x80071380
    // 0x80043C64: addiu       $a1, $zero, 0x249
    ctx->r5 = ADD32(0, 0X249);
    Fault_HungUp(rdram, ctx);
        goto after_3;
    // 0x80043C64: addiu       $a1, $zero, 0x249
    ctx->r5 = ADD32(0, 0X249);
    after_3:
L_80043C68:
    // 0x80043C68: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x80043C6C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80043C70: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80043C74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80043C78: sh          $t6, 0x17E($t7)
    MEM_H(0X17E, ctx->r15) = ctx->r14;
    // 0x80043C7C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80043C80: sb          $t8, 0x17C($t9)
    MEM_B(0X17C, ctx->r25) = ctx->r24;
L_80043C84:
    // 0x80043C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043C88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80043C8C: jr          $ra
    // 0x80043C90: nop

    return;
    // 0x80043C90: nop

;}
RECOMP_FUNC void func_805C8988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C8988: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805C898C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C8990: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C8994: lui         $at, 0x43B5
    ctx->r1 = S32(0X43B5 << 16);
    // 0x805C8998: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805C899C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805C89A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C89A4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C89A8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805C89AC: nop

    // 0x805C89B0: bc1fl       L_805C8A10
    if (!c1cs) {
        // 0x805C89B4: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805C8A10;
    }
    goto skip_0;
    // 0x805C89B4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x805C89B8: jal         0x805C6A70
    // 0x805C89BC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_805C6A70(rdram, ctx);
        goto after_0;
    // 0x805C89BC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C89C0: beq         $v0, $zero, L_805C8A0C
    if (ctx->r2 == 0) {
        // 0x805C89C4: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_805C8A0C;
    }
    // 0x805C89C4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805C89C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C89CC: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x805C89D0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x805C89D4: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    // 0x805C89D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805C89DC: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x805C89E0: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x805C89E4: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x805C89E8: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x805C89EC: sw          $t6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r14;
    // 0x805C89F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x805C89F4: jal         0x805C74C8
    // 0x805C89F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C74C8(rdram, ctx);
        goto after_1;
    // 0x805C89F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805C89FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8A04: jal         0x805C9D10
    // 0x805C8A08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805C9D10(rdram, ctx);
        goto after_2;
    // 0x805C8A08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_805C8A0C:
    // 0x805C8A0C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_805C8A10:
    // 0x805C8A10: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805C8A14: jal         0x80048F84
    // 0x805C8A18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805C8A18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x805C8A1C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805C8A20: jal         0x80048F84
    // 0x805C8A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x805C8A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x805C8A28: jal         0x805C7844
    // 0x805C8A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7844(rdram, ctx);
        goto after_5;
    // 0x805C8A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805C8A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805C8A34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C8A38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805C8A3C: jr          $ra
    // 0x805C8A40: nop

    return;
    // 0x805C8A40: nop

;}
RECOMP_FUNC void func_807B3998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B3998: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807B399C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807B39A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807B39A4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807B39A8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807B39AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B39B0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807B39B4: lui         $t1, 0x807B
    ctx->r9 = S32(RELOC_HI16(874, 0X1E0) << 16);
    // 0x807B39B8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807B39BC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807B39C0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807B39C4: lw          $t1, 0x39E0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(874, 0X1E0));
    // 0x807B39C8: jr          $ra
    // 0x807B39CC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807B39CC: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void Overlay_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    yoshi_overlay_load(rdram, ctx);
    // 0x8008169C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800816A0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800816A4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800816A8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800816AC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800816B0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800816B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800816B8: subu        $a2, $t7, $a1
    ctx->r6 = SUB32(ctx->r15, ctx->r5);
    // 0x800816BC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800816C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800816C4: jal         0x8007DF0C
    // 0x800816C8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    DmaMgr_RequestSync(rdram, ctx);
        goto after_0;
    // 0x800816C8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x800816CC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800816D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800816D4: addu        $a3, $a0, $a2
    ctx->r7 = ADD32(ctx->r4, ctx->r6);
    // 0x800816D8: lw          $t8, -0x4($a3)
    ctx->r24 = MEM_W(ctx->r7, -0X4);
    // 0x800816DC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800816E0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800816E4: subu        $a1, $a3, $t8
    ctx->r5 = SUB32(ctx->r7, ctx->r24);
    // 0x800816E8: jal         0x80081430
    // 0x800816EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    DoRelocation(rdram, ctx);
        goto after_1;
    // 0x800816EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x800816F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800816F4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800816F8: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    // 0x800816FC: beql        $a1, $zero, L_80081710
    if (ctx->r5 == 0) {
        // 0x80081700: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80081710;
    }
    goto skip_0;
    // 0x80081700: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80081704: jal         0x80084820
    // 0x80081708: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _blkclr(rdram, ctx);
        goto after_2;
    // 0x80081708: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x8008170C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_80081710:
    // 0x80081710: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80081714: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80081718: subu        $a1, $t0, $t1
    ctx->r5 = SUB32(ctx->r8, ctx->r9);
    // 0x8008171C: jal         0x80085FE0
    // 0x80081720: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_3;
    // 0x80081720: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x80081724: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80081728: jal         0x8008AE50
    // 0x8008172C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    osInvalICache_recomp(rdram, ctx);
        goto after_4;
    // 0x8008172C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80081730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081734: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80081738: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008173C: jr          $ra
    // 0x80081740: nop

    return;
    // 0x80081740: nop

;}
RECOMP_FUNC void func_8043ADE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043ADE4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8043ADE8: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(83, 0X248) << 16);
    // 0x8043ADEC: addiu       $t6, $t6, -0x5758
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(83, 0X248));
    // 0x8043ADF0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8043ADF4: jr          $ra
    // 0x8043ADF8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8043ADF8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8005B704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B704: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005B708: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005B70C: lh          $t7, 0x4E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4E);
    // 0x8005B710: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8005B714: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8005B718: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8005B71C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8005B720: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8005B724: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005B728: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005B72C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8005B730: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8005B734: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8005B738: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8005B73C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8005B740: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8005B744: jal         0x8005B54C
    // 0x8005B748: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    func_8005B54C(rdram, ctx);
        goto after_0;
    // 0x8005B748: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    after_0:
    // 0x8005B74C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8005B750: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8005B754: jr          $ra
    // 0x8005B758: nop

    return;
    // 0x8005B758: nop

;}
RECOMP_FUNC void func_8059F6C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F6C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8059F6C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059F6CC: jal         0x8004700C
    // 0x8059F6D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8059F6D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8059F6D4: beq         $v0, $zero, L_8059F73C
    if (ctx->r2 == 0) {
        // 0x8059F6D8: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8059F73C;
    }
    // 0x8059F6D8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8059F6DC: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8059F6E0: lwc1        $f6, 0x88($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8059F6E4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8059F6E8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8059F6EC: nop

    // 0x8059F6F0: bc1fl       L_8059F704
    if (!c1cs) {
        // 0x8059F6F4: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_8059F704;
    }
    goto skip_0;
    // 0x8059F6F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x8059F6F8: b           L_8059F740
    // 0x8059F6FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8059F740;
    // 0x8059F6FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8059F700: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_8059F704:
    // 0x8059F704: lwc1        $f0, 0x84($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8059F708: lwc1        $f2, 0x84($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8059F70C: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8059F710: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8059F714: nop

    // 0x8059F718: bc1t        L_8059F734
    if (c1cs) {
        // 0x8059F71C: nop
    
            goto L_8059F734;
    }
    // 0x8059F71C: nop

    // 0x8059F720: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8059F724: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8059F728: nop

    // 0x8059F72C: bc1fl       L_8059F740
    if (!c1cs) {
        // 0x8059F730: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8059F740;
    }
    goto skip_1;
    // 0x8059F730: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
L_8059F734:
    // 0x8059F734: b           L_8059F740
    // 0x8059F738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8059F740;
    // 0x8059F738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8059F73C:
    // 0x8059F73C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8059F740:
    // 0x8059F740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8059F744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8059F748: jr          $ra
    // 0x8059F74C: nop

    return;
    // 0x8059F74C: nop

;}
RECOMP_FUNC void func_8044A684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A684: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044A688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A68C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044A690: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044A694: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044A698: jal         0x8044A558
    // 0x8044A69C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044A69C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8044A6A0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A6A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044A6A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044A6AC: bne         $v0, $zero, L_8044A6C4
    if (ctx->r2 != 0) {
        // 0x8044A6B0: nop
    
            goto L_8044A6C4;
    }
    // 0x8044A6B0: nop

    // 0x8044A6B4: jal         0x80445E5C
    // 0x8044A6B8: nop

    func_80445E5C(rdram, ctx);
        goto after_1;
    // 0x8044A6B8: nop

    after_1:
    // 0x8044A6BC: b           L_8044A6E8
    // 0x8044A6C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044A6E8;
    // 0x8044A6C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A6C4:
    // 0x8044A6C4: bne         $v0, $at, L_8044A6DC
    if (ctx->r2 != ctx->r1) {
        // 0x8044A6C8: nop
    
            goto L_8044A6DC;
    }
    // 0x8044A6C8: nop

    // 0x8044A6CC: jal         0x80445E94
    // 0x8044A6D0: nop

    func_80445E94(rdram, ctx);
        goto after_2;
    // 0x8044A6D0: nop

    after_2:
    // 0x8044A6D4: b           L_8044A6E8
    // 0x8044A6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044A6E8;
    // 0x8044A6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A6DC:
    // 0x8044A6DC: jal         0x80445EC8
    // 0x8044A6E0: nop

    func_80445EC8(rdram, ctx);
        goto after_3;
    // 0x8044A6E0: nop

    after_3:
    // 0x8044A6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A6E8:
    // 0x8044A6E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044A6EC: jr          $ra
    // 0x8044A6F0: nop

    return;
    // 0x8044A6F0: nop

;}
RECOMP_FUNC void func_804F5608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F5608: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804F560C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F5610: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F5614: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x804F5618: jal         0x804F4F50
    // 0x804F561C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_804F4F50(rdram, ctx);
        goto after_0;
    // 0x804F561C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804F5620: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x804F5624: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804F5628: lwc1        $f2, 0x44($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X44);
    // 0x804F562C: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804F5630: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x804F5634: nop

    // 0x804F5638: bc1fl       L_804F5650
    if (!c1cs) {
        // 0x804F563C: swc1        $f0, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
            goto L_804F5650;
    }
    goto skip_0;
    // 0x804F563C: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x804F5640: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804F5644: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x804F5648: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x804F564C: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
L_804F5650:
    // 0x804F5650: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x804F5654: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x804F5658: slti        $at, $v1, 0x1E
    ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x804F565C: bne         $at, $zero, L_804F56B0
    if (ctx->r1 != 0) {
        // 0x804F5660: sw          $v1, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r3;
            goto L_804F56B0;
    }
    // 0x804F5660: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x804F5664: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x804F5668: addiu       $t8, $a0, 0xC4
    ctx->r24 = ADD32(ctx->r4, 0XC4);
    // 0x804F566C: addiu       $t1, $zero, 0x1D
    ctx->r9 = ADD32(0, 0X1D);
    // 0x804F5670: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x804F5674: nop

    // 0x804F5678: bc1f        L_804F56A8
    if (!c1cs) {
        // 0x804F567C: nop
    
            goto L_804F56A8;
    }
    // 0x804F567C: nop

    // 0x804F5680: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x804F5684: jal         0x804F589C
    // 0x804F5688: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_804F589C(rdram, ctx);
        goto after_1;
    // 0x804F5688: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804F568C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x804F5690: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x804F5694: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x804F5698: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x804F569C: swc1        $f8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f8.u32l;
    // 0x804F56A0: b           L_804F570C
    // 0x804F56A4: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
        goto L_804F570C;
    // 0x804F56A4: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
L_804F56A8:
    // 0x804F56A8: b           L_804F570C
    // 0x804F56AC: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
        goto L_804F570C;
    // 0x804F56AC: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
L_804F56B0:
    // 0x804F56B0: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x804F56B4: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x804F56B8: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x804F56BC: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x804F56C0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804F56C4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x804F56C8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x804F56CC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x804F56D0: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(273, 0X208C4) << 16);
    // 0x804F56D4: lwc1        $f18, 0x4B54($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(273, 0X208C4));
    // 0x804F56D8: lw          $t5, 0x64($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X64);
    // 0x804F56DC: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(273, 0X208C8) << 16);
    // 0x804F56E0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804F56E4: swc1        $f4, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->f4.u32l;
    // 0x804F56E8: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x804F56EC: lwc1        $f10, 0x4B58($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(273, 0X208C8));
    // 0x804F56F0: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(273, 0X208CC) << 16);
    // 0x804F56F4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x804F56F8: lwc1        $f18, 0x4B5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(273, 0X208CC));
    // 0x804F56FC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804F5700: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804F5704: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804F5708: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
L_804F570C:
    // 0x804F570C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F5710: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804F5714: jr          $ra
    // 0x804F5718: nop

    return;
    // 0x804F5718: nop

;}
RECOMP_FUNC void func_8052D95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D95C: lw          $v0, 0xF18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XF18);
    // 0x8052D960: bne         $v0, $zero, L_8052D9E8
    if (ctx->r2 != 0) {
        // 0x8052D964: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_8052D9E8;
    }
    // 0x8052D964: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x8052D968: lw          $v0, 0xF24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XF24);
    // 0x8052D96C: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(330, 0X16E8) << 16);
    // 0x8052D970: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8052D974: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8052D978: beq         $at, $zero, L_8052D9D8
    if (ctx->r1 == 0) {
        // 0x8052D97C: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8052D9D8;
    }
    // 0x8052D97C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8052D980: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8052D984: sw          $t6, 0xF24($a1)
    MEM_W(0XF24, ctx->r5) = ctx->r14;
    // 0x8052D988: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8052D98C: lh          $t9, -0x2348($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(330, 0X16E8));
    // 0x8052D990: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8052D994: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8052D998: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x8052D99C: lw          $t0, 0xF24($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XF24);
    // 0x8052D9A0: bne         $t0, $at, L_8052D9D0
    if (ctx->r8 != ctx->r1) {
        // 0x8052D9A4: nop
    
            goto L_8052D9D0;
    }
    // 0x8052D9A4: nop

    // 0x8052D9A8: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8052D9AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8052D9B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8052D9B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8052D9B8: nop

    // 0x8052D9BC: bc1fl       L_8052D9D0
    if (!c1cs) {
        // 0x8052D9C0: sw          $t1, 0x138($a0)
        MEM_W(0X138, ctx->r4) = ctx->r9;
            goto L_8052D9D0;
    }
    goto skip_0;
    // 0x8052D9C0: sw          $t1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r9;
    skip_0:
    // 0x8052D9C4: b           L_8052D9D0
    // 0x8052D9C8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
        goto L_8052D9D0;
    // 0x8052D9C8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8052D9CC: sw          $t1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r9;
L_8052D9D0:
    // 0x8052D9D0: jr          $ra
    // 0x8052D9D4: sw          $t2, 0xF18($a1)
    MEM_W(0XF18, ctx->r5) = ctx->r10;
    return;
    // 0x8052D9D4: sw          $t2, 0xF18($a1)
    MEM_W(0XF18, ctx->r5) = ctx->r10;
L_8052D9D8:
    // 0x8052D9D8: sw          $zero, 0xF24($a1)
    MEM_W(0XF24, ctx->r5) = 0;
    // 0x8052D9DC: sw          $t3, 0xF18($a1)
    MEM_W(0XF18, ctx->r5) = ctx->r11;
    // 0x8052D9E0: jr          $ra
    // 0x8052D9E4: sw          $zero, 0xF20($a1)
    MEM_W(0XF20, ctx->r5) = 0;
    return;
    // 0x8052D9E4: sw          $zero, 0xF20($a1)
    MEM_W(0XF20, ctx->r5) = 0;
L_8052D9E8:
    // 0x8052D9E8: sw          $t4, 0xF18($a1)
    MEM_W(0XF18, ctx->r5) = ctx->r12;
    // 0x8052D9EC: jr          $ra
    // 0x8052D9F0: nop

    return;
    // 0x8052D9F0: nop

;}
RECOMP_FUNC void func_80522948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522948: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8052294C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80522950: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80522954: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80522958: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8052295C: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x80522960: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80522964: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80522968: bne         $t6, $at, L_805229CC
    if (ctx->r14 != ctx->r1) {
        // 0x8052296C: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_805229CC;
    }
    // 0x8052296C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80522970: lbu         $t7, 0x165($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X165);
    // 0x80522974: bnel        $t7, $zero, L_805229D0
    if (ctx->r15 != 0) {
        // 0x80522978: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805229D0;
    }
    goto skip_0;
    // 0x80522978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8052297C: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80522980: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80522984: bnel        $t8, $zero, L_805229D0
    if (ctx->r24 != 0) {
        // 0x80522988: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805229D0;
    }
    goto skip_1;
    // 0x80522988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8052298C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80522990: jal         0x800677F8
    // 0x80522994: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x80522994: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80522998: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8052299C: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x805229A0: jal         0x80067BBC
    // 0x805229A4: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x805229A4: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x805229A8: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    // 0x805229AC: jal         0x80067818
    // 0x805229B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x805229B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x805229B4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x805229B8: lw          $t9, -0x72D8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72D8);
    // 0x805229BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805229C0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x805229C4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x805229C8: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
L_805229CC:
    // 0x805229CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805229D0:
    // 0x805229D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805229D4: jr          $ra
    // 0x805229D8: nop

    return;
    // 0x805229D8: nop

;}
RECOMP_FUNC void func_804A27A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A27A0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x804A27A4: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x804A27A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A27AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804A27B0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804A27B4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x804A27B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A27BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804A27C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804A27C4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804A27C8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804A27CC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804A27D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804A27D4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804A27D8: lui         $t1, 0x804A
    ctx->r9 = S32(RELOC_HI16(173, 0X30B8) << 16);
    // 0x804A27DC: sb          $a3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r7;
    // 0x804A27E0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804A27E4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804A27E8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804A27EC: lw          $t1, 0x34F8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(173, 0X30B8));
    // 0x804A27F0: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x804A27F4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x804A27F8: jal         0x804A2818
    // 0x804A27FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A2818(rdram, ctx);
        goto after_0;
    // 0x804A27FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A2800: jal         0x804A28A4
    // 0x804A2804: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804A28A4(rdram, ctx);
        goto after_1;
    // 0x804A2804: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804A2808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A280C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A2810: jr          $ra
    // 0x804A2814: nop

    return;
    // 0x804A2814: nop

;}
RECOMP_FUNC void func_80439090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80439090: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80439094: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(80, 0X19D4) << 16);
    // 0x80439098: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8043909C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x804390A0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x804390A4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x804390A8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x804390AC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x804390B0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x804390B4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x804390B8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x804390BC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x804390C0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x804390C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x804390C8: addiu       $t6, $t6, -0x5B6C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(80, 0X19D4));
    // 0x804390CC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x804390D0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804390D4: addiu       $s6, $sp, 0x68
    ctx->r22 = ADD32(ctx->r29, 0X68);
    // 0x804390D8: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x804390DC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x804390E0: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x804390E4: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x804390E8: sw          $t7, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r15;
    // 0x804390EC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x804390F0: lw          $s5, 0x478($s3)
    ctx->r21 = MEM_W(ctx->r19, 0X478);
    // 0x804390F4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x804390F8: sw          $t8, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r24;
    // 0x804390FC: lwc1        $f4, 0x30($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X30);
    // 0x80439100: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80439104: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80439108: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8043910C: lwc1        $f6, 0x34($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X34);
    // 0x80439110: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80439114: addiu       $s4, $zero, 0x11
    ctx->r20 = ADD32(0, 0X11);
    // 0x80439118: addiu       $s0, $v0, 0xA1C
    ctx->r16 = ADD32(ctx->r2, 0XA1C);
    // 0x8043911C: addiu       $s2, $v0, 0xD10
    ctx->r18 = ADD32(ctx->r2, 0XD10);
    // 0x80439120: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
L_80439124:
    // 0x80439124: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80439128: lw          $t2, 0x478($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X478);
    // 0x8043912C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80439130: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x80439134: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80439138: lwc1        $f10, 0x38($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X38);
    // 0x8043913C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80439140: jal         0x80081C64
    // 0x80439144: add.s       $f12, $f16, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f24.fl;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80439144: add.s       $f12, $f16, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f24.fl;
    after_0:
    // 0x80439148: lw          $s1, 0x3F4($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X3F4);
    // 0x8043914C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80439150: lw          $t6, 0x478($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X478);
    // 0x80439154: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80439158: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8043915C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80439160: div.s       $f20, $f26, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = DIV_S(ctx->f26.fl, ctx->f18.fl);
    // 0x80439164: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x80439168: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8043916C: lwc1        $f16, 0xAC($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0XAC);
    // 0x80439170: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80439174: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80439178: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8043917C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80439180: div.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80439184: add.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x80439188: mul.s       $f22, $f10, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8043918C: jal         0x80081C64
    // 0x80439190: nop

    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x80439190: nop

    after_1:
    // 0x80439194: lw          $s1, 0x3F4($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X3F4);
    // 0x80439198: lwc1        $f6, 0xB0($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0XB0);
    // 0x8043919C: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x804391A0: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x804391A4: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x804391A8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x804391AC: div.s       $f20, $f26, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f26.fl, ctx->f8.fl);
    // 0x804391B0: lwc1        $f8, -0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, -0X8);
    // 0x804391B4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x804391B8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x804391BC: sub.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x804391C0: swc1        $f10, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->f10.u32l;
    // 0x804391C4: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x804391C8: lwc1        $f16, -0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, -0X4);
    // 0x804391CC: div.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f20.fl, ctx->f18.fl);
    // 0x804391D0: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804391D4: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x804391D8: bgez        $s4, L_80439124
    if (SIGNED(ctx->r20) >= 0) {
        // 0x804391DC: swc1        $f18, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f18.u32l;
            goto L_80439124;
    }
    // 0x804391DC: swc1        $f18, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f18.u32l;
    // 0x804391E0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x804391E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804391E8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804391EC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804391F0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804391F4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x804391F8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x804391FC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80439200: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80439204: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80439208: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8043920C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80439210: jr          $ra
    // 0x80439214: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80439214: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8046AF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046AF80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046AF84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046AF88: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8046AF8C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8046AF90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8046AF94: beq         $a1, $at, L_8046AFB8
    if (ctx->r5 == ctx->r1) {
        // 0x8046AF98: addiu       $a0, $zero, 0x3A
        ctx->r4 = ADD32(0, 0X3A);
            goto L_8046AFB8;
    }
    // 0x8046AF98: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x8046AF9C: jal         0x80067930
    // 0x8046AFA0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x8046AFA0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8046AFA4: beq         $v0, $zero, L_8046AFB8
    if (ctx->r2 == 0) {
        // 0x8046AFA8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8046AFB8;
    }
    // 0x8046AFA8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8046AFAC: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x8046AFB0: jal         0x80067878
    // 0x8046AFB4: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x8046AFB4: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    after_1:
L_8046AFB8:
    // 0x8046AFB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046AFBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046AFC0: jr          $ra
    // 0x8046AFC4: nop

    return;
    // 0x8046AFC4: nop

;}
RECOMP_FUNC void func_806F2554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2558: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F255C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806F2560: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806F2564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2568: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806F256C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806F2570: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806F2574: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806F2578: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806F257C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806F2580: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806F2584: lui         $t2, 0x806F
    ctx->r10 = S32(RELOC_HI16(679, 0X1B04) << 16);
    // 0x806F2588: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806F258C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806F2590: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806F2594: lw          $t2, 0x3084($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(679, 0X1B04));
    // 0x806F2598: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806F259C: jal         0x806F2318
    // 0x806F25A0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_806F2318(rdram, ctx);
        goto after_0;
    // 0x806F25A0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x806F25A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F25A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F25AC: jr          $ra
    // 0x806F25B0: nop

    return;
    // 0x806F25B0: nop

;}
