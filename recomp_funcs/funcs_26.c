#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80067A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067A18: jal         0x80018E68
    // 0x80067A1C: nop

    func_80018E68(rdram, ctx);
        goto after_0;
    // 0x80067A1C: nop

    after_0:
    // 0x80067A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067A24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067A28: jr          $ra
    // 0x80067A2C: nop

    return;
    // 0x80067A2C: nop

;}
RECOMP_FUNC void func_8064C054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C05C: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064C060: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064C064: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C068: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064C06C: nop

    // 0x8064C070: bc1fl       L_8064C0B8
    if (!c1cs) {
        // 0x8064C074: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C0B8;
    }
    goto skip_0;
    // 0x8064C074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C078: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064C07C: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C080: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8064C084: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064C088: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064C08C: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8064C090: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C094: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8064C098: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064C09C: nop

    // 0x8064C0A0: bc1fl       L_8064C0B8
    if (!c1cs) {
        // 0x8064C0A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C0B8;
    }
    goto skip_1;
    // 0x8064C0A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064C0A8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064C0AC: jal         0x8064C5D8
    // 0x8064C0B0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064C5D8(rdram, ctx);
        goto after_0;
    // 0x8064C0B0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064C0B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C0B8:
    // 0x8064C0B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C0BC: jr          $ra
    // 0x8064C0C0: nop

    return;
    // 0x8064C0C0: nop

;}
RECOMP_FUNC void func_804C9174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C9174: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C9178: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C917C: jal         0x804C911C
    // 0x804C9180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C911C(rdram, ctx);
        goto after_0;
    // 0x804C9180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C9184: beq         $v0, $zero, L_804C91E8
    if (ctx->r2 == 0) {
        // 0x804C9188: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804C91E8;
    }
    // 0x804C9188: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C918C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804C9190: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804C9194: lui         $t7, 0x804D
    ctx->r15 = S32(RELOC_HI16(225, 0X900) << 16);
    // 0x804C9198: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804C919C: addiu       $t7, $t7, -0x6DC0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(225, 0X900));
    // 0x804C91A0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804C91A4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804C91A8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804C91AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C91B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C91B4: jal         0x804C91F8
    // 0x804C91B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804C91F8(rdram, ctx);
        goto after_1;
    // 0x804C91B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x804C91BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C91C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C91C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804C91C8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804C91CC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804C91D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804C91D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804C91D8: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x804C91DC: swc1        $f0, 0x104($a0)
    MEM_W(0X104, ctx->r4) = ctx->f0.u32l;
    // 0x804C91E0: swc1        $f0, 0x100($a0)
    MEM_W(0X100, ctx->r4) = ctx->f0.u32l;
    // 0x804C91E4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
L_804C91E8:
    // 0x804C91E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C91EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C91F0: jr          $ra
    // 0x804C91F4: nop

    return;
    // 0x804C91F4: nop

;}
RECOMP_FUNC void func_8043F504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F504: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043F508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043F50C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043F510: jal         0x8004700C
    // 0x8043F514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043F514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8043F518: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8043F51C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x8043F520: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8043F524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043F528: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043F52C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8043F530: jal         0x80442188
    // 0x8043F534: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80442188(rdram, ctx);
        goto after_1;
    // 0x8043F534: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x8043F538: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4E8C) << 16);
    // 0x8043F53C: lwc1        $f2, 0x3D8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4E8C));
    // 0x8043F540: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8043F544: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8043F548: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8043F54C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x8043F550: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8043F554: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8043F558: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8043F55C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8043F560: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8043F564: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8043F568: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8043F56C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4E90) << 16);
    // 0x8043F570: swc1        $f2, 0x1C24($v1)
    MEM_W(0X1C24, ctx->r3) = ctx->f2.u32l;
    // 0x8043F574: swc1        $f2, 0x1C28($v1)
    MEM_W(0X1C28, ctx->r3) = ctx->f2.u32l;
    // 0x8043F578: lwc1        $f4, 0x3D90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4E90));
    // 0x8043F57C: swc1        $f12, 0x1C88($v1)
    MEM_W(0X1C88, ctx->r3) = ctx->f12.u32l;
    // 0x8043F580: swc1        $f12, 0x1C8C($v1)
    MEM_W(0X1C8C, ctx->r3) = ctx->f12.u32l;
    // 0x8043F584: beq         $t0, $zero, L_8043F5B0
    if (ctx->r8 == 0) {
        // 0x8043F588: swc1        $f4, 0x1C74($v1)
        MEM_W(0X1C74, ctx->r3) = ctx->f4.u32l;
            goto L_8043F5B0;
    }
    // 0x8043F588: swc1        $f4, 0x1C74($v1)
    MEM_W(0X1C74, ctx->r3) = ctx->f4.u32l;
    // 0x8043F58C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8043F590: lwc1        $f8, 0x3C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x8043F594: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8043F598: swc1        $f10, 0x1C80($v1)
    MEM_W(0X1C80, ctx->r3) = ctx->f10.u32l;
    // 0x8043F59C: lwc1        $f18, 0x40($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X40);
    // 0x8043F5A0: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8043F5A4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8043F5A8: b           L_8043F5B8
    // 0x8043F5AC: swc1        $f4, 0x1C84($v1)
    MEM_W(0X1C84, ctx->r3) = ctx->f4.u32l;
        goto L_8043F5B8;
    // 0x8043F5AC: swc1        $f4, 0x1C84($v1)
    MEM_W(0X1C84, ctx->r3) = ctx->f4.u32l;
L_8043F5B0:
    // 0x8043F5B0: swc1        $f0, 0x1C80($v1)
    MEM_W(0X1C80, ctx->r3) = ctx->f0.u32l;
    // 0x8043F5B4: swc1        $f0, 0x1C84($v1)
    MEM_W(0X1C84, ctx->r3) = ctx->f0.u32l;
L_8043F5B8:
    // 0x8043F5B8: jal         0x8043F310
    // 0x8043F5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F310(rdram, ctx);
        goto after_2;
    // 0x8043F5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043F5C0: jal         0x8043F42C
    // 0x8043F5C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F42C(rdram, ctx);
        goto after_3;
    // 0x8043F5C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043F5C8: jal         0x8043F1A0
    // 0x8043F5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F1A0(rdram, ctx);
        goto after_4;
    // 0x8043F5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8043F5D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043F5D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043F5D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043F5DC: jr          $ra
    // 0x8043F5E0: nop

    return;
    // 0x8043F5E0: nop

;}
RECOMP_FUNC void func_806E4B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E4B48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E4B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E4B50: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E4B54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806E4B58: jal         0x806E3DD0
    // 0x806E4B5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_806E3DD0(rdram, ctx);
        goto after_0;
    // 0x806E4B5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x806E4B60: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806E4B64: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x806E4B68: lw          $t6, 0x58($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X58);
    // 0x806E4B6C: bnel        $t6, $zero, L_806E4C4C
    if (ctx->r14 != 0) {
        // 0x806E4B70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E4C4C;
    }
    goto skip_0;
    // 0x806E4B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E4B74: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x806E4B78: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(649, 0X1D98) << 16);
    // 0x806E4B7C: beq         $v1, $zero, L_806E4B8C
    if (ctx->r3 == 0) {
        // 0x806E4B80: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_806E4B8C;
    }
    // 0x806E4B80: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x806E4B84: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x806E4B88: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_806E4B8C:
    // 0x806E4B8C: bnel        $v1, $zero, L_806E4C4C
    if (ctx->r3 != 0) {
        // 0x806E4B90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E4C4C;
    }
    goto skip_1;
    // 0x806E4B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806E4B94: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x806E4B98: lui         $t9, 0x806E
    ctx->r25 = S32(RELOC_HI16(649, 0X1D80) << 16);
    // 0x806E4B9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806E4BA0: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x806E4BA4: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x806E4BA8: lw          $t8, 0x5598($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(649, 0X1D98));
    // 0x806E4BAC: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x806E4BB0: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x806E4BB4: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
    // 0x806E4BB8: lw          $t9, 0x5580($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(649, 0X1D80));
    // 0x806E4BBC: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
    // 0x806E4BC0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x806E4BC4: bne         $t0, $at, L_806E4BE0
    if (ctx->r8 != ctx->r1) {
        // 0x806E4BC8: sw          $t9, 0x3C($v0)
        MEM_W(0X3C, ctx->r2) = ctx->r25;
            goto L_806E4BE0;
    }
    // 0x806E4BC8: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x806E4BCC: lw          $t1, 0x138($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X138);
    // 0x806E4BD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806E4BD4: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x806E4BD8: sw          $t3, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->r11;
    // 0x806E4BDC: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
L_806E4BE0:
    // 0x806E4BE0: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x806E4BE4: bne         $at, $zero, L_806E4C48
    if (ctx->r1 != 0) {
        // 0x806E4BE8: addiu       $t4, $zero, 0x8
        ctx->r12 = ADD32(0, 0X8);
            goto L_806E4C48;
    }
    // 0x806E4BE8: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x806E4BEC: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x806E4BF0: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x806E4BF4: sw          $t4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r12;
    // 0x806E4BF8: slti        $at, $t6, 0x17
    ctx->r1 = SIGNED(ctx->r14) < 0X17 ? 1 : 0;
    // 0x806E4BFC: sw          $t5, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r13;
    // 0x806E4C00: beq         $at, $zero, L_806E4C38
    if (ctx->r1 == 0) {
        // 0x806E4C04: sw          $zero, 0x34($v0)
        MEM_W(0X34, ctx->r2) = 0;
            goto L_806E4C38;
    }
    // 0x806E4C04: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x806E4C08: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    // 0x806E4C0C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806E4C10: bnel        $t7, $zero, L_806E4C3C
    if (ctx->r15 != 0) {
        // 0x806E4C14: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_806E4C3C;
    }
    goto skip_2;
    // 0x806E4C14: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_2:
    // 0x806E4C18: jal         0x806E4144
    // 0x806E4C1C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_806E4144(rdram, ctx);
        goto after_1;
    // 0x806E4C1C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x806E4C20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E4C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4C28: jal         0x806E511C
    // 0x806E4C2C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806E511C(rdram, ctx);
        goto after_2;
    // 0x806E4C2C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x806E4C30: b           L_806E4C4C
    // 0x806E4C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806E4C4C;
    // 0x806E4C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E4C38:
    // 0x806E4C38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_806E4C3C:
    // 0x806E4C3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4C40: jal         0x806E511C
    // 0x806E4C44: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_806E511C(rdram, ctx);
        goto after_3;
    // 0x806E4C44: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
L_806E4C48:
    // 0x806E4C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E4C4C:
    // 0x806E4C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E4C50: jr          $ra
    // 0x806E4C54: nop

    return;
    // 0x806E4C54: nop

;}
RECOMP_FUNC void func_804F3AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3AEC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804F3AF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804F3AF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804F3AF8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804F3AFC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804F3B00: lui         $t7, 0x804F
    ctx->r15 = S32(RELOC_HI16(270, 0XD80) << 16);
    // 0x804F3B04: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804F3B08: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804F3B0C: addiu       $t7, $t7, 0x40B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(270, 0XD80));
    // 0x804F3B10: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804F3B14: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804F3B18: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804F3B1C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804F3B20: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x804F3B24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804F3B28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804F3B2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804F3B30: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804F3B34: jal         0x80045A34
    // 0x804F3B38: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804F3B38: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x804F3B3C: lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XC);
    // 0x804F3B40: lui         $t1, 0x804F
    ctx->r9 = S32(RELOC_HI16(270, 0X790) << 16);
    // 0x804F3B44: addiu       $t1, $t1, 0x3AC0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(270, 0X790));
    // 0x804F3B48: addiu       $at, $zero, 0x404C
    ctx->r1 = ADD32(0, 0X404C);
    // 0x804F3B4C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804F3B50: beq         $v1, $at, L_804F3B84
    if (ctx->r3 == ctx->r1) {
        // 0x804F3B54: sw          $t1, 0x1F8($s0)
        MEM_W(0X1F8, ctx->r16) = ctx->r9;
            goto L_804F3B84;
    }
    // 0x804F3B54: sw          $t1, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r9;
    // 0x804F3B58: addiu       $at, $zero, 0x404D
    ctx->r1 = ADD32(0, 0X404D);
    // 0x804F3B5C: beq         $v1, $at, L_804F3BAC
    if (ctx->r3 == ctx->r1) {
        // 0x804F3B60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804F3BAC;
    }
    // 0x804F3B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F3B64: addiu       $at, $zero, 0x404E
    ctx->r1 = ADD32(0, 0X404E);
    // 0x804F3B68: beq         $v1, $at, L_804F3C04
    if (ctx->r3 == ctx->r1) {
        // 0x804F3B6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804F3C04;
    }
    // 0x804F3B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F3B70: addiu       $at, $zero, 0x404F
    ctx->r1 = ADD32(0, 0X404F);
    // 0x804F3B74: beq         $v1, $at, L_804F3C28
    if (ctx->r3 == ctx->r1) {
        // 0x804F3B78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804F3C28;
    }
    // 0x804F3B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F3B7C: b           L_804F3C88
    // 0x804F3B80: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
        goto L_804F3C88;
    // 0x804F3B80: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_804F3B84:
    // 0x804F3B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F3B88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F3B8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804F3B90: jal         0x804F3EF0
    // 0x804F3B94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804F3EF0(rdram, ctx);
        goto after_1;
    // 0x804F3B94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804F3B98: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x804F3B9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804F3BA0: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x804F3BA4: b           L_804F3C84
    // 0x804F3BA8: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
        goto L_804F3C84;
    // 0x804F3BA8: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
L_804F3BAC:
    // 0x804F3BAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F3BB0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804F3BB4: jal         0x804F3EF0
    // 0x804F3BB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804F3EF0(rdram, ctx);
        goto after_2;
    // 0x804F3BB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804F3BBC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x804F3BC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804F3BC4: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x804F3BC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804F3BCC: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804F3BD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x804F3BD4: sh          $t2, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r10;
    // 0x804F3BD8: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x804F3BDC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x804F3BE0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804F3BE4: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804F3BE8: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x804F3BEC: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x804F3BF0: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x804F3BF4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804F3BF8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x804F3BFC: b           L_804F3C84
    // 0x804F3C00: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
        goto L_804F3C84;
    // 0x804F3C00: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
L_804F3C04:
    // 0x804F3C04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F3C08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804F3C0C: jal         0x804F3EF0
    // 0x804F3C10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_804F3EF0(rdram, ctx);
        goto after_3;
    // 0x804F3C10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x804F3C14: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x804F3C18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804F3C1C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x804F3C20: b           L_804F3C84
    // 0x804F3C24: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
        goto L_804F3C84;
    // 0x804F3C24: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
L_804F3C28:
    // 0x804F3C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F3C2C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804F3C30: jal         0x804F3EF0
    // 0x804F3C34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_804F3EF0(rdram, ctx);
        goto after_4;
    // 0x804F3C34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x804F3C38: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x804F3C3C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804F3C40: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x804F3C44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804F3C48: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804F3C4C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x804F3C50: sh          $t3, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r11;
    // 0x804F3C54: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x804F3C58: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x804F3C5C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x804F3C60: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804F3C64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804F3C68: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804F3C6C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804F3C70: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x804F3C74: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x804F3C78: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804F3C7C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x804F3C80: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
L_804F3C84:
    // 0x804F3C84: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_804F3C88:
    // 0x804F3C88: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x804F3C8C: jal         0x80058958
    // 0x804F3C90: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80058958(rdram, ctx);
        goto after_5;
    // 0x804F3C90: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_5:
    // 0x804F3C94: beq         $v0, $zero, L_804F3D0C
    if (ctx->r2 == 0) {
        // 0x804F3C98: lui         $t4, 0x8010
        ctx->r12 = S32(0X8010 << 16);
            goto L_804F3D0C;
    }
    // 0x804F3C98: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x804F3C9C: lw          $t4, -0x7BC4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7BC4);
    // 0x804F3CA0: lw          $t5, 0x10C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10C);
    // 0x804F3CA4: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x804F3CA8: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x804F3CAC: beql        $t7, $zero, L_804F3D10
    if (ctx->r15 == 0) {
        // 0x804F3CB0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804F3D10;
    }
    goto skip_0;
    // 0x804F3CB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x804F3CB4: jal         0x80056564
    // 0x804F3CB8: nop

    func_80056564(rdram, ctx);
        goto after_6;
    // 0x804F3CB8: nop

    after_6:
    // 0x804F3CBC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x804F3CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F3CC4: beq         $v0, $zero, L_804F3D0C
    if (ctx->r2 == 0) {
        // 0x804F3CC8: sw          $v0, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r2;
            goto L_804F3D0C;
    }
    // 0x804F3CC8: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x804F3CCC: jal         0x800457A0
    // 0x804F3CD0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_7;
    // 0x804F3CD0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x804F3CD4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x804F3CD8: addiu       $t0, $zero, 0x29
    ctx->r8 = ADD32(0, 0X29);
    // 0x804F3CDC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x804F3CE0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x804F3CE4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x804F3CE8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x804F3CEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x804F3CF0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804F3CF4: jal         0x80056584
    // 0x804F3CF8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_8;
    // 0x804F3CF8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_8:
    // 0x804F3CFC: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x804F3D00: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x804F3D04: addiu       $t2, $t2, 0x784C
    ctx->r10 = ADD32(ctx->r10, 0X784C);
    // 0x804F3D08: sw          $t2, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r10;
L_804F3D0C:
    // 0x804F3D0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804F3D10:
    // 0x804F3D10: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804F3D14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804F3D18: jr          $ra
    // 0x804F3D1C: nop

    return;
    // 0x804F3D1C: nop

;}
RECOMP_FUNC void func_805DC010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DC010: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DC014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DC018: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805DC01C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DC020: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x805DC024: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805DC028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DC02C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805DC030: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x805DC034: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x805DC038: jal         0x805DD234
    // 0x805DC03C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_805DD234(rdram, ctx);
        goto after_0;
    // 0x805DC03C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x805DC040: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X285C) << 16);
    // 0x805DC044: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805DC048: lwc1        $f4, -0x2AA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X285C));
    // 0x805DC04C: jal         0x80062D14
    // 0x805DC050: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    func_80062D14(rdram, ctx);
        goto after_1;
    // 0x805DC050: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x805DC054: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x805DC058: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X2860) << 16);
    // 0x805DC05C: lwc1        $f8, -0x2AA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X2860));
    // 0x805DC060: lwc1        $f6, 0x60($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X60);
    // 0x805DC064: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805DC068: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x805DC06C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805DC070: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805DC074: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805DC078: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805DC07C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805DC080: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x805DC084: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805DC088: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x805DC08C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805DC090: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805DC094: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    // 0x805DC098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DC09C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DC0A0: jr          $ra
    // 0x805DC0A4: nop

    return;
    // 0x805DC0A4: nop

;}
RECOMP_FUNC void func_8043A830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043A830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043A834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043A838: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8043A83C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8043A840: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(83, 0X1180) << 16);
    // 0x8043A844: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043A848: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8043A84C: lw          $t8, -0x4820($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(83, 0X1180));
    // 0x8043A850: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8043A854: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8043A858: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8043A85C: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8043A860: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8043A864: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8043A868: beql        $v1, $zero, L_8043A89C
    if (ctx->r3 == 0) {
        // 0x8043A86C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043A89C;
    }
    goto skip_0;
    // 0x8043A86C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043A870: jalr        $v1
    // 0x8043A874: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8043A874: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043A878: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043A87C: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8043A880: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8043A884: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8043A888: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8043A88C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8043A890: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8043A894: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8043A898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043A89C:
    // 0x8043A89C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043A8A0: jr          $ra
    // 0x8043A8A4: nop

    return;
    // 0x8043A8A4: nop

;}
RECOMP_FUNC void func_80521424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052142C: jal         0x805213D0
    // 0x80521430: nop

    func_805213D0(rdram, ctx);
        goto after_0;
    // 0x80521430: nop

    after_0:
    // 0x80521434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052143C: jr          $ra
    // 0x80521440: nop

    return;
    // 0x80521440: nop

;}
RECOMP_FUNC void func_8044A3F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A3F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044A3F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044A3FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8044A400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A404: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044A408: bne         $a2, $zero, L_8044A444
    if (ctx->r6 != 0) {
        // 0x8044A40C: lw          $v0, 0x1F4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X1F4);
            goto L_8044A444;
    }
    // 0x8044A40C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044A410: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x8044A414: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A418: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x8044A41C: bgtz        $t7, L_8044A434
    if (SIGNED(ctx->r15) > 0) {
        // 0x8044A420: sw          $t7, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->r15;
            goto L_8044A434;
    }
    // 0x8044A420: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x8044A424: jal         0x80446C74
    // 0x8044A428: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446C74(rdram, ctx);
        goto after_0;
    // 0x8044A428: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8044A42C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A430: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_8044A434:
    // 0x8044A434: jal         0x8044A060
    // 0x8044A438: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    func_8044A060(rdram, ctx);
        goto after_1;
    // 0x8044A438: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    after_1:
    // 0x8044A43C: b           L_8044A488
    // 0x8044A440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044A488;
    // 0x8044A440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A444:
    // 0x8044A444: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044A448: bne         $a2, $at, L_8044A470
    if (ctx->r6 != ctx->r1) {
        // 0x8044A44C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044A470;
    }
    // 0x8044A44C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044A450: jal         0x80446C40
    // 0x8044A454: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446C40(rdram, ctx);
        goto after_2;
    // 0x8044A454: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8044A458: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A45C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A460: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x8044A464: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044A468: b           L_8044A484
    // 0x8044A46C: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_8044A484;
    // 0x8044A46C: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_8044A470:
    // 0x8044A470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8044A474: bnel        $a2, $at, L_8044A488
    if (ctx->r6 != ctx->r1) {
        // 0x8044A478: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044A488;
    }
    goto skip_0;
    // 0x8044A478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044A47C: jal         0x80446C74
    // 0x8044A480: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80446C74(rdram, ctx);
        goto after_3;
    // 0x8044A480: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
L_8044A484:
    // 0x8044A484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A488:
    // 0x8044A488: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044A48C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8044A490: jr          $ra
    // 0x8044A494: nop

    return;
    // 0x8044A494: nop

;}
RECOMP_FUNC void func_80453644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453644: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80453648: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045364C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80453650: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80453654: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80453658: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045365C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80453660: swc1        $f4, 0x6F00($at)
    MEM_W(0X6F00, ctx->r1) = ctx->f4.u32l;
    // 0x80453664: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453668: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8045366C: sw          $a1, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r5;
    // 0x80453670: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80453674: jal         0x8044EFA0
    // 0x80453678: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80453678: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8045367C: jal         0x8044DED8
    // 0x80453680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044DED8(rdram, ctx);
        goto after_1;
    // 0x80453680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80453684: jal         0x80444C94
    // 0x80453688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80444C94(rdram, ctx);
        goto after_2;
    // 0x80453688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8045368C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80453690: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80453694: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80453698: jal         0x8044FE40
    // 0x8045369C: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    func_8044FE40(rdram, ctx);
        goto after_3;
    // 0x8045369C: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    after_3:
    // 0x804536A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804536A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804536A8: jal         0x8044FE64
    // 0x804536AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_8044FE64(rdram, ctx);
        goto after_4;
    // 0x804536AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x804536B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804536B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804536B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804536BC: jr          $ra
    // 0x804536C0: nop

    return;
    // 0x804536C0: nop

;}
RECOMP_FUNC void func_8000CC58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CC58: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000CC5C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8000CC60: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8000CC64: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8000CC68: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8000CC6C: nop

    // 0x8000CC70: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000CC74: srl         $v1, $t9, 10
    ctx->r3 = S32(U32(ctx->r25) >> 10);
    // 0x8000CC78: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x8000CC7C: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x8000CC80: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8000CC84: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8000CC88: lh          $v0, 0x0($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X0);
    // 0x8000CC8C: sra         $v0, $v0, 8
    ctx->r2 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8000CC90: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8000CC94: jr          $ra
    // 0x8000CC98: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x8000CC98: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_800500AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800500AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800500B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800500B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800500B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800500BC: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800500C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800500C4: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x800500C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800500CC: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
    // 0x800500D0: lw          $t6, 0x970($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X970);
L_800500D4:
    // 0x800500D4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800500D8: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800500DC: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800500E0: beql        $v0, $zero, L_80050108
    if (ctx->r2 == 0) {
        // 0x800500E4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80050108;
    }
    goto skip_0;
    // 0x800500E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800500E8: lw          $a0, 0x16C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X16C);
    // 0x800500EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800500F0: lw          $t9, 0x1B8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1B8);
    // 0x800500F4: beql        $t9, $zero, L_80050108
    if (ctx->r25 == 0) {
        // 0x800500F8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80050108;
    }
    goto skip_1;
    // 0x800500F8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x800500FC: jal         0x8004FE44
    // 0x80050100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8004FE44(rdram, ctx);
        goto after_0;
    // 0x80050100: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80050104: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80050108:
    // 0x80050108: bnel        $s0, $s2, L_800500D4
    if (ctx->r16 != ctx->r18) {
        // 0x8005010C: lw          $t6, 0x970($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X970);
            goto L_800500D4;
    }
    goto skip_2;
    // 0x8005010C: lw          $t6, 0x970($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X970);
    skip_2:
    // 0x80050110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80050114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80050118: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005011C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80050120: jr          $ra
    // 0x80050124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80050124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80790350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790350: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80790354: addiu       $at, $zero, 0x41A4
    ctx->r1 = ADD32(0, 0X41A4);
    // 0x80790358: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(817, 0X3560) << 16);
    // 0x8079035C: bne         $t6, $at, L_80790370
    if (ctx->r14 != ctx->r1) {
        // 0x80790360: addiu       $v0, $v0, 0x38B0
        ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(817, 0X3560));
            goto L_80790370;
    }
    // 0x80790360: addiu       $v0, $v0, 0x38B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(817, 0X3560));
    // 0x80790364: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(817, 0X3560) << 16);
    // 0x80790368: jr          $ra
    // 0x8079036C: addiu       $v0, $v0, 0x38B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(817, 0X3560));
    return;
    // 0x8079036C: addiu       $v0, $v0, 0x38B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(817, 0X3560));
L_80790370:
    // 0x80790370: jr          $ra
    // 0x80790374: nop

    return;
    // 0x80790374: nop

;}
RECOMP_FUNC void func_807C66CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C66CC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807C66D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807C66D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x807C66D8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807C66DC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807C66E0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807C66E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807C66E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807C66EC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807C66F0: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(913, 0X934) << 16);
    // 0x807C66F4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807C66F8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807C66FC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807C6700: lw          $t1, 0x6724($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(913, 0X934));
    // 0x807C6704: jr          $ra
    // 0x807C6708: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807C6708: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x807C670C: nop

;}
RECOMP_FUNC void func_8001D8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D8C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D8C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8001D8CC: lw          $t7, 0x1F4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1F4);
    // 0x8001D8D0: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8001D8D4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8001D8D8: lbu         $t8, 0x22($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X22);
    // 0x8001D8DC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8001D8E0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8001D8E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001D8E8: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8001D8EC: lw          $a1, -0x68AC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X68AC);
    // 0x8001D8F0: jal         0x800655F4
    // 0x8001D8F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800655F4(rdram, ctx);
        goto after_0;
    // 0x8001D8F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8001D8F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D8FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D900: jr          $ra
    // 0x8001D904: nop

    return;
    // 0x8001D904: nop

;}
RECOMP_FUNC void ViMode_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EA30: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
    // 0x8007EA34: sw          $zero, 0x54($a0)
    MEM_W(0X54, ctx->r4) = 0;
    // 0x8007EA38: sw          $zero, 0x50($a0)
    MEM_W(0X50, ctx->r4) = 0;
    // 0x8007EA3C: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x8007EA40: sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // 0x8007EA44: sw          $zero, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = 0;
    // 0x8007EA48: sw          $zero, 0x58($a0)
    MEM_W(0X58, ctx->r4) = 0;
    // 0x8007EA4C: jr          $ra
    // 0x8007EA50: nop

    return;
    // 0x8007EA50: nop

;}
RECOMP_FUNC void func_80580C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580C70: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80580C74: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80580C78: lw          $t6, 0x478($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X478);
    // 0x80580C7C: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47E4) << 16);
    // 0x80580C80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80580C84: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80580C88: swc1        $f0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f0.u32l;
    // 0x80580C8C: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x80580C90: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x80580C94: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80580C98: swc1        $f0, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f0.u32l;
    // 0x80580C9C: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x80580CA0: lw          $t8, 0x478($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X478);
    // 0x80580CA4: lwc1        $f6, 0x35F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47E4));
    // 0x80580CA8: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47E8) << 16);
    // 0x80580CAC: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80580CB0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80580CB4: swc1        $f0, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f0.u32l;
    // 0x80580CB8: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x80580CBC: lwc1        $f8, 0x35F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47E8));
    // 0x80580CC0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47EC) << 16);
    // 0x80580CC4: swc1        $f8, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f8.u32l;
    // 0x80580CC8: lwc1        $f10, 0x35FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47EC));
    // 0x80580CCC: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X47F0) << 16);
    // 0x80580CD0: swc1        $f10, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f10.u32l;
    // 0x80580CD4: lwc1        $f16, 0x3600($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X47F0));
    // 0x80580CD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80580CDC: swc1        $f16, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->f16.u32l;
    // 0x80580CE0: jr          $ra
    // 0x80580CE4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    return;
    // 0x80580CE4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void func_805A7620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7620: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A7624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A7628: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A762C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805A7630: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x805A7634: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    // 0x805A7638: beql        $a0, $t6, L_805A7674
    if (ctx->r4 == ctx->r14) {
        // 0x805A763C: lw          $v1, 0xC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XC);
            goto L_805A7674;
    }
    goto skip_0;
    // 0x805A763C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x805A7640: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A7644: lw          $a2, 0x88($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X88);
    // 0x805A7648: lw          $a1, 0x84($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X84);
    // 0x805A764C: lw          $a0, 0x1D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1D8);
    // 0x805A7650: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x805A7654: jal         0x80048C18
    // 0x805A7658: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80048C18(rdram, ctx);
        goto after_0;
    // 0x805A7658: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A765C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x805A7660: jal         0x80048C00
    // 0x805A7664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80048C00(rdram, ctx);
        goto after_1;
    // 0x805A7664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805A7668: b           L_805A76FC
    // 0x805A766C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805A76FC;
    // 0x805A766C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805A7670: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
L_805A7674:
    // 0x805A7674: beq         $v1, $zero, L_805A7684
    if (ctx->r3 == 0) {
        // 0x805A7678: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_805A7684;
    }
    // 0x805A7678: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x805A767C: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x805A7680: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_805A7684:
    // 0x805A7684: bnel        $v1, $zero, L_805A76C8
    if (ctx->r3 != 0) {
        // 0x805A7688: lw          $v1, 0x4($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X4);
            goto L_805A76C8;
    }
    goto skip_1;
    // 0x805A7688: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x805A768C: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x805A7690: lui         $t0, 0x805B
    ctx->r8 = S32(RELOC_HI16(426, 0X16D8) << 16);
    // 0x805A7694: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x805A7698: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x805A769C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x805A76A0: lh          $t0, -0x75D8($t0)
    ctx->r8 = MEM_H(ctx->r8, (int16_t)RELOC_LO16(426, 0X16D8));
    // 0x805A76A4: sh          $t0, 0x144($a3)
    MEM_H(0X144, ctx->r7) = ctx->r8;
    // 0x805A76A8: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x805A76AC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x805A76B0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x805A76B4: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x805A76B8: bne         $at, $zero, L_805A76C4
    if (ctx->r1 != 0) {
        // 0x805A76BC: sw          $t2, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r10;
            goto L_805A76C4;
    }
    // 0x805A76BC: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x805A76C0: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
L_805A76C4:
    // 0x805A76C4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
L_805A76C8:
    // 0x805A76C8: beql        $v1, $zero, L_805A76FC
    if (ctx->r3 == 0) {
        // 0x805A76CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805A76FC;
    }
    goto skip_2;
    // 0x805A76CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x805A76D0: lw          $t5, 0x138($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X138);
    // 0x805A76D4: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(426, 0X16F0) << 16);
    // 0x805A76D8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x805A76DC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x805A76E0: lwc1        $f4, -0x75C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(426, 0X16F0));
    // 0x805A76E4: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x805A76E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A76EC: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x805A76F0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x805A76F4: swc1        $f6, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f6.u32l;
    // 0x805A76F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A76FC:
    // 0x805A76FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A7700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A7704: jr          $ra
    // 0x805A7708: nop

    return;
    // 0x805A7708: nop

;}
RECOMP_FUNC void func_8044ACFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044ACFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044AD00: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X134C4) << 16);
    // 0x8044AD04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AD08: addiu       $t6, $t6, 0x78A4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X134C4));
    // 0x8044AD0C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044AD10: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044AD14: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044AD18: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044AD1C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044AD20: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044AD24: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044AD28: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044AD2C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044AD30: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044AD34: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044AD38: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044AD3C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044AD40: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044AD44: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044AD48: jal         0x80050A50
    // 0x8044AD4C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044AD4C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044AD50: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044AD54: jalr        $v0
    // 0x8044AD58: sw          $v0, 0x6A88($v1)
    MEM_W(0X6A88, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044AD58: sw          $v0, 0x6A88($v1)
    MEM_W(0X6A88, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044AD5C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AD60: sw          $v0, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r2;
    // 0x8044AD64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044AD68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044AD6C: jr          $ra
    // 0x8044AD70: nop

    return;
    // 0x8044AD70: nop

;}
RECOMP_FUNC void func_805E0E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E0E20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805E0E24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805E0E28: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x805E0E2C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x805E0E30: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x805E0E34: lw          $s1, 0x174($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X174);
    // 0x805E0E38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E0E3C: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x805E0E40: jal         0x80049D74
    // 0x805E0E44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x805E0E44: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x805E0E48: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x805E0E4C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x805E0E50: lw          $v0, 0x40($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X40);
    // 0x805E0E54: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x805E0E58: beql        $v1, $zero, L_805E0FE8
    if (ctx->r3 == 0) {
        // 0x805E0E5C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805E0FE8;
    }
    goto skip_0;
    // 0x805E0E5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x805E0E60: beql        $v1, $at, L_805E0FE8
    if (ctx->r3 == ctx->r1) {
        // 0x805E0E64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805E0FE8;
    }
    goto skip_1;
    // 0x805E0E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x805E0E68: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x805E0E6C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x805E0E70: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x805E0E74: beq         $v1, $at, L_805E0FE4
    if (ctx->r3 == ctx->r1) {
        // 0x805E0E78: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_805E0FE4;
    }
    // 0x805E0E78: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x805E0E7C: beq         $v1, $at, L_805E0FE4
    if (ctx->r3 == ctx->r1) {
        // 0x805E0E80: addiu       $s1, $s0, 0xC4
        ctx->r17 = ADD32(ctx->r16, 0XC4);
            goto L_805E0FE4;
    }
    // 0x805E0E80: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x805E0E84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805E0E88: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x805E0E8C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805E0E90: nop

    // 0x805E0E94: bc1fl       L_805E0FE8
    if (!c1cs) {
        // 0x805E0E98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805E0FE8;
    }
    goto skip_2;
    // 0x805E0E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x805E0E9C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805E0EA0: jal         0x80067BBC
    // 0x805E0EA4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x805E0EA4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x805E0EA8: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    // 0x805E0EAC: jal         0x80067818
    // 0x805E0EB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x805E0EB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x805E0EB4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805E0EB8: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x805E0EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E0EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805E0EC4: jal         0x8004D1F0
    // 0x805E0EC8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D1F0(rdram, ctx);
        goto after_3;
    // 0x805E0EC8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x805E0ECC: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x805E0ED0: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x805E0ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E0ED8: jal         0x8004D698
    // 0x805E0EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004D698(rdram, ctx);
        goto after_4;
    // 0x805E0EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x805E0EE0: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x805E0EE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805E0EE8: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x805E0EEC: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(483, 0X6A8) << 16);
    // 0x805E0EF0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805E0EF4: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x805E0EF8: lwc1        $f18, 0x1338($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(483, 0X6A8));
    // 0x805E0EFC: jal         0x800653D8
    // 0x805E0F00: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x805E0F00: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    after_5:
    // 0x805E0F04: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x805E0F08: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x805E0F0C: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(483, 0X6AC) << 16);
    // 0x805E0F10: lwc1        $f8, 0x133C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(483, 0X6AC));
    // 0x805E0F14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805E0F18: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x805E0F1C: addiu       $at, $zero, 0x453A
    ctx->r1 = ADD32(0, 0X453A);
    // 0x805E0F20: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805E0F24: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805E0F28: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x805E0F2C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    // 0x805E0F30: lhu         $t8, 0xC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XC);
    // 0x805E0F34: bnel        $t8, $at, L_805E0F78
    if (ctx->r24 != ctx->r1) {
        // 0x805E0F38: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_805E0F78;
    }
    goto skip_3;
    // 0x805E0F38: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_3:
    // 0x805E0F3C: lh          $t9, 0x144($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X144);
    // 0x805E0F40: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805E0F44: bnel        $t9, $zero, L_805E0F78
    if (ctx->r25 != 0) {
        // 0x805E0F48: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_805E0F78;
    }
    goto skip_4;
    // 0x805E0F48: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_4:
    // 0x805E0F4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805E0F50: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x805E0F54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805E0F58: nop

    // 0x805E0F5C: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x805E0F60: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x805E0F64: nop

    // 0x805E0F68: bc1fl       L_805E0F78
    if (!c1cs) {
        // 0x805E0F6C: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_805E0F78;
    }
    goto skip_5;
    // 0x805E0F6C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_5:
    // 0x805E0F70: sub.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x805E0F74: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_805E0F78:
    // 0x805E0F78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805E0F7C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805E0F80: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805E0F84: c.le.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl <= ctx->f6.fl;
    // 0x805E0F88: nop

    // 0x805E0F8C: bc1tl       L_805E0FC8
    if (c1cs) {
        // 0x805E0F90: sw          $t0, 0x138($s0)
        MEM_W(0X138, ctx->r16) = ctx->r8;
            goto L_805E0FC8;
    }
    goto skip_6;
    // 0x805E0F90: sw          $t0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r8;
    skip_6:
    // 0x805E0F94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805E0F98: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x805E0F9C: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x805E0FA0: nop

    // 0x805E0FA4: bc1f        L_805E0FDC
    if (!c1cs) {
        // 0x805E0FA8: nop
    
            goto L_805E0FDC;
    }
    // 0x805E0FA8: nop

    // 0x805E0FAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805E0FB0: nop

    // 0x805E0FB4: c.le.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl <= ctx->f16.fl;
    // 0x805E0FB8: nop

    // 0x805E0FBC: bc1f        L_805E0FDC
    if (!c1cs) {
        // 0x805E0FC0: nop
    
            goto L_805E0FDC;
    }
    // 0x805E0FC0: nop

    // 0x805E0FC4: sw          $t0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r8;
L_805E0FC8:
    // 0x805E0FC8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805E0FCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805E0FD0: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x805E0FD4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x805E0FD8: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
L_805E0FDC:
    // 0x805E0FDC: b           L_805E0FE8
    // 0x805E0FE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805E0FE8;
    // 0x805E0FE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805E0FE4:
    // 0x805E0FE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805E0FE8:
    // 0x805E0FE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805E0FEC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x805E0FF0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x805E0FF4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x805E0FF8: jr          $ra
    // 0x805E0FFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805E0FFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806AA290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA290: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x806AA294: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806AA298: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806AA29C: jr          $ra
    // 0x806AA2A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x806AA2A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void func_800349E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800349E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800349E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800349EC: jal         0x800348A4
    // 0x800349F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800348A4(rdram, ctx);
        goto after_0;
    // 0x800349F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800349F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800349F8: jal         0x80065954
    // 0x800349FC: lwc1        $f12, 0xC4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC4);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x800349FC: lwc1        $f12, 0xC4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC4);
    after_1:
    // 0x80034A00: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80034A04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034A08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80034A0C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80034A10: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80034A14: jal         0x80041214
    // 0x80034A18: nop

    func_80041214(rdram, ctx);
        goto after_2;
    // 0x80034A18: nop

    after_2:
    // 0x80034A1C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80034A20: lbu         $a1, -0x7684($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X7684);
    // 0x80034A24: jal         0x800411AC
    // 0x80034A28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800411AC(rdram, ctx);
        goto after_3;
    // 0x80034A28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80034A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034A30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80034A34: jr          $ra
    // 0x80034A38: nop

    return;
    // 0x80034A38: nop

;}
RECOMP_FUNC void func_8073C170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073C170: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8073C174: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8073C178: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8073C17C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8073C180: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8073C184: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8073C188: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8073C18C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8073C190: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8073C194: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8073C198: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073C19C: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x8073C1A0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8073C1A4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8073C1A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8073C1AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073C1B0: jal         0x8004921C
    // 0x8073C1B4: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8073C1B4: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    after_0:
    // 0x8073C1B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073C1BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073C1C0: jal         0x8004921C
    // 0x8073C1C4: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8073C1C4: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    after_1:
    // 0x8073C1C8: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x8073C1CC: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(742, 0X860) << 16);
    // 0x8073C1D0: addiu       $t7, $t7, -0x3640
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(742, 0X860));
    // 0x8073C1D4: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
    // 0x8073C1D8: addiu       $s3, $sp, 0xB8
    ctx->r19 = ADD32(ctx->r29, 0XB8);
    // 0x8073C1DC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8073C1E0: sw          $t8, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r24;
    // 0x8073C1E4: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x8073C1E8: lw          $s2, 0x88($v1)
    ctx->r18 = MEM_W(ctx->r3, 0X88);
    // 0x8073C1EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8073C1F0: lw          $t9, 0x14($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X14);
    // 0x8073C1F4: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8073C1F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073C1FC: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x8073C200: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8073C204: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8073C208: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8073C20C: sw          $t0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r8;
    // 0x8073C210: jal         0x80077338
    // 0x8073C214: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x8073C214: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    after_2:
    // 0x8073C218: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C21C: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x8073C220: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x8073C224: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8073C228: lw          $ra, 0xB4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XB4);
    // 0x8073C22C: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x8073C230: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8073C234: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x8073C238: ori         $t7, $t7, 0xACB0
    ctx->r15 = ctx->r15 | 0XACB0;
    // 0x8073C23C: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x8073C240: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8073C244: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8073C248: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C24C: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x8073C250: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x8073C254: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8073C258: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x8073C25C: ori         $a1, $a1, 0x3048
    ctx->r5 = ctx->r5 | 0X3048;
    // 0x8073C260: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x8073C264: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8073C268: sw          $a1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r5;
    // 0x8073C26C: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C270: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8073C274: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8073C278: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8073C27C: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x8073C280: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x8073C284: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8073C288: sw          $ra, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r31;
    // 0x8073C28C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8073C290: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8073C294: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8073C298: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8073C29C: sw          $t0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r8;
    // 0x8073C2A0: jal         0x8007711C
    // 0x8073C2A4: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8073C2A4: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    after_3:
    // 0x8073C2A8: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x8073C2AC: lui         $a1, 0x8074
    ctx->r5 = S32(RELOC_HI16(742, 0XD48) << 16);
    // 0x8073C2B0: lui         $a0, 0x8074
    ctx->r4 = S32(RELOC_HI16(742, 0XF68) << 16);
    // 0x8073C2B4: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x8073C2B8: lw          $ra, 0xB4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XB4);
    // 0x8073C2BC: addiu       $a0, $a0, -0x2F38
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(742, 0XF68));
    // 0x8073C2C0: addiu       $a1, $a1, -0x3158
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(742, 0XD48));
    // 0x8073C2C4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8073C2C8: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
L_8073C2CC:
    // 0x8073C2CC: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(742, 0XD28) << 16);
    // 0x8073C2D0: addiu       $v0, $v0, -0x3178
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(742, 0XD28));
    // 0x8073C2D4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8073C2D8:
    // 0x8073C2D8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8073C2DC: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8073C2E0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8073C2E4: lw          $t7, 0x14($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X14);
    // 0x8073C2E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8073C2EC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8073C2F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8073C2F4: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8073C2F8: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8073C2FC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8073C300: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8073C304: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8073C308: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8073C30C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8073C310: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8073C314: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8073C318: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8073C31C: nop

    // 0x8073C320: sh          $t7, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r15;
    // 0x8073C324: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x8073C328: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8073C32C: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8073C330: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8073C334: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8073C338: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8073C33C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8073C340: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8073C344: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8073C348: bne         $at, $zero, L_8073C2D8
    if (ctx->r1 != 0) {
        // 0x8073C34C: sh          $t6, 0x12($v1)
        MEM_H(0X12, ctx->r3) = ctx->r14;
            goto L_8073C2D8;
    }
    // 0x8073C34C: sh          $t6, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r14;
    // 0x8073C350: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8073C354: slti        $at, $t1, 0xC
    ctx->r1 = SIGNED(ctx->r9) < 0XC ? 1 : 0;
    // 0x8073C358: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x8073C35C: bne         $at, $zero, L_8073C2CC
    if (ctx->r1 != 0) {
        // 0x8073C360: addiu       $t0, $t0, 0x18
        ctx->r8 = ADD32(ctx->r8, 0X18);
            goto L_8073C2CC;
    }
    // 0x8073C360: addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
    // 0x8073C364: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C368: multu       $ra, $s1
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8073C36C: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8073C370: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8073C374: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x8073C378: ori         $t9, $t9, 0x30BF
    ctx->r25 = ctx->r25 | 0X30BF;
    // 0x8073C37C: addiu       $t6, $t5, 0x20
    ctx->r14 = ADD32(ctx->r13, 0X20);
    // 0x8073C380: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8073C384: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8073C388: lw          $a3, 0x14($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X14);
    // 0x8073C38C: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(742, 0XE50) << 16);
    // 0x8073C390: addiu       $t8, $t8, -0x3050
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(742, 0XE50));
    // 0x8073C394: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8073C398: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8073C39C: addiu       $t9, $ra, -0x1
    ctx->r25 = ADD32(ctx->r31, -0X1);
    // 0x8073C3A0: or          $v1, $ra, $zero
    ctx->r3 = ctx->r31 | 0;
    // 0x8073C3A4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8073C3A8: addu        $t4, $t7, $t8
    ctx->r12 = ADD32(ctx->r15, ctx->r24);
    // 0x8073C3AC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8073C3B0: addiu       $s2, $v1, 0x7
    ctx->r18 = ADD32(ctx->r3, 0X7);
    // 0x8073C3B4: sra         $s2, $s2, 3
    ctx->r18 = S32(SIGNED(ctx->r18) >> 3);
    // 0x8073C3B8: addiu       $t9, $s1, -0x1
    ctx->r25 = ADD32(ctx->r17, -0X1);
    // 0x8073C3BC: mflo        $s0
    ctx->r16 = lo;
    // 0x8073C3C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8073C3C4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8073C3C8: andi        $s2, $s2, 0x1FF
    ctx->r18 = ctx->r18 & 0X1FF;
    // 0x8073C3CC: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8073C3D0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8073C3D4: sll         $s2, $s2, 9
    ctx->r18 = S32(ctx->r18 << 9);
    // 0x8073C3D8: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8073C3DC: lui         $t3, 0x8074
    ctx->r11 = S32(RELOC_HI16(742, 0XE08) << 16);
    // 0x8073C3E0: addiu       $t3, $t3, -0x3098
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(742, 0XE08));
    // 0x8073C3E4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8073C3E8: or          $s3, $t8, $t7
    ctx->r19 = ctx->r24 | ctx->r15;
    // 0x8073C3EC: lui         $s1, 0xFD50
    ctx->r17 = S32(0XFD50 << 16);
    // 0x8073C3F0: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
    // 0x8073C3F4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8073C3F8: or          $t0, $t5, $zero
    ctx->r8 = ctx->r13 | 0;
    // 0x8073C3FC: bgez        $v1, L_8073C40C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8073C400: sra         $t2, $v1, 3
        ctx->r10 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8073C40C;
    }
    // 0x8073C400: sra         $t2, $v1, 3
    ctx->r10 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8073C404: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8073C408: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_8073C40C:
    // 0x8073C40C: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8073C410: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
    // 0x8073C414: lui         $fp, 0xE700
    ctx->r30 = S32(0XE700 << 16);
    // 0x8073C418: lui         $s7, 0xF300
    ctx->r23 = S32(0XF300 << 16);
    // 0x8073C41C: lui         $s6, 0xE600
    ctx->r22 = S32(0XE600 << 16);
    // 0x8073C420: lui         $s5, 0xF550
    ctx->r21 = S32(0XF550 << 16);
    // 0x8073C424: addiu       $s4, $zero, 0x240
    ctx->r20 = ADD32(0, 0X240);
L_8073C428:
    // 0x8073C428: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x8073C42C: slti        $at, $s0, 0x7FF
    ctx->r1 = SIGNED(ctx->r16) < 0X7FF ? 1 : 0;
    // 0x8073C430: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x8073C434: sh          $t9, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r25;
    // 0x8073C438: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C43C: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x8073C440: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8073C444: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8073C448: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x8073C44C: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8073C450: lh          $t7, 0x18($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X18);
    // 0x8073C454: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x8073C458: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8073C45C: mflo        $t9
    ctx->r25 = lo;
    // 0x8073C460: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8073C464: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8073C468: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C46C: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8073C470: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x8073C474: sw          $s5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r21;
    // 0x8073C478: sw          $ra, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r31;
    // 0x8073C47C: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C480: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8073C484: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x8073C488: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
    // 0x8073C48C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8073C490: sw          $s6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r22;
    // 0x8073C494: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C498: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8073C49C: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x8073C4A0: sw          $s7, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r23;
    // 0x8073C4A4: beq         $at, $zero, L_8073C4B4
    if (ctx->r1 == 0) {
        // 0x8073C4A8: or          $t5, $t7, $zero
        ctx->r13 = ctx->r15 | 0;
            goto L_8073C4B4;
    }
    // 0x8073C4A8: or          $t5, $t7, $zero
    ctx->r13 = ctx->r15 | 0;
    // 0x8073C4AC: b           L_8073C4B4
    // 0x8073C4B0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
        goto L_8073C4B4;
    // 0x8073C4B0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
L_8073C4B4:
    // 0x8073C4B4: bgtz        $t2, L_8073C4C4
    if (SIGNED(ctx->r10) > 0) {
        // 0x8073C4B8: nop
    
            goto L_8073C4C4;
    }
    // 0x8073C4B8: nop

    // 0x8073C4BC: b           L_8073C4C4
    // 0x8073C4C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8073C4C4;
    // 0x8073C4C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8073C4C4:
    // 0x8073C4C4: bgtz        $t2, L_8073C4D4
    if (SIGNED(ctx->r10) > 0) {
        // 0x8073C4C8: addiu       $t6, $t1, 0x7FF
        ctx->r14 = ADD32(ctx->r9, 0X7FF);
            goto L_8073C4D4;
    }
    // 0x8073C4C8: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8073C4CC: b           L_8073C4D4
    // 0x8073C4D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8073C4D4;
    // 0x8073C4D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8073C4D4:
    // 0x8073C4D4: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x8073C4D8: mflo        $t8
    ctx->r24 = lo;
    // 0x8073C4DC: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8073C4E0: bne         $a1, $zero, L_8073C4EC
    if (ctx->r5 != 0) {
        // 0x8073C4E4: nop
    
            goto L_8073C4EC;
    }
    // 0x8073C4E4: nop

    // 0x8073C4E8: break       7
    do_break(2155070696);
L_8073C4EC:
    // 0x8073C4EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8073C4F0: bne         $a1, $at, L_8073C504
    if (ctx->r5 != ctx->r1) {
        // 0x8073C4F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8073C504;
    }
    // 0x8073C4F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8073C4F8: bne         $t6, $at, L_8073C504
    if (ctx->r14 != ctx->r1) {
        // 0x8073C4FC: nop
    
            goto L_8073C504;
    }
    // 0x8073C4FC: nop

    // 0x8073C500: break       6
    do_break(2155070720);
L_8073C504:
    // 0x8073C504: andi        $t6, $a3, 0xFFF
    ctx->r14 = ctx->r7 & 0XFFF;
    // 0x8073C508: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8073C50C: or          $t9, $t7, $ra
    ctx->r25 = ctx->r15 | ctx->r31;
    // 0x8073C510: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8073C514: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8073C518: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C51C: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8073C520: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x8073C524: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8073C528: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x8073C52C: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8073C530: sw          $fp, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r30;
    // 0x8073C534: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C538: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8073C53C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8073C540: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    // 0x8073C544: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8073C548: sw          $s2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r18;
    // 0x8073C54C: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C550: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8073C554: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8073C558: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8073C55C: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x8073C560: sw          $s3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r19;
    // 0x8073C564: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8073C568: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C56C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8073C570: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(742, 0XE50) << 16);
    // 0x8073C574: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8073C578: sw          $t6, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r14;
    // 0x8073C57C: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x8073C580: addiu       $t3, $t3, 0x18
    ctx->r11 = ADD32(ctx->r11, 0X18);
    // 0x8073C584: addiu       $t8, $t8, -0x3050
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(742, 0XE50));
    // 0x8073C588: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8073C58C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8073C590: bne         $t3, $t8, L_8073C428
    if (ctx->r11 != ctx->r24) {
        // 0x8073C594: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_8073C428;
    }
    // 0x8073C594: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8073C598: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x8073C59C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8073C5A0: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
    // 0x8073C5A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8073C5A8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8073C5AC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8073C5B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8073C5B4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8073C5B8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8073C5BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8073C5C0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8073C5C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8073C5C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073C5CC: jr          $ra
    // 0x8073C5D0: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8073C5D0: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_80072FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072FF8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072FFC: addiu       $a0, $a0, -0x27B0
    ctx->r4 = ADD32(ctx->r4, -0X27B0);
    // 0x80073000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80073004: jal         0x800824B0
    // 0x80073008: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80073008: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007300C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80073010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80073014: jr          $ra
    // 0x80073018: nop

    return;
    // 0x80073018: nop

;}
RECOMP_FUNC void func_804E7A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E7A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E7A9C: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804E7AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804E7AA4: beq         $t6, $zero, L_804E7AE0
    if (ctx->r14 == 0) {
        // 0x804E7AA8: nop
    
            goto L_804E7AE0;
    }
    // 0x804E7AA8: nop

    // 0x804E7AAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804E7AB0: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804E7AB4: jalr        $t9
    // 0x804E7AB8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804E7AB8: nop

    after_0:
    // 0x804E7ABC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804E7AC0: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804E7AC4: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804E7AC8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804E7ACC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804E7AD0: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804E7AD4: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804E7AD8: b           L_804E7AE0
    // 0x804E7ADC: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804E7AE0;
    // 0x804E7ADC: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804E7AE0:
    // 0x804E7AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E7AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E7AE8: jr          $ra
    // 0x804E7AEC: nop

    return;
    // 0x804E7AEC: nop

;}
RECOMP_FUNC void func_805D196C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D196C: jr          $ra
    // 0x805D1970: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805D1970: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800232C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800232C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800232C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800232C8: jal         0x80022FE4
    // 0x800232CC: nop

    func_80022FE4(rdram, ctx);
        goto after_0;
    // 0x800232CC: nop

    after_0:
    // 0x800232D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800232D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800232D8: jr          $ra
    // 0x800232DC: nop

    return;
    // 0x800232DC: nop

;}
RECOMP_FUNC void func_806FE250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FE250: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806FE254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FE258: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x806FE25C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x806FE260: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x806FE264: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x806FE268: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806FE26C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806FE270: bne         $t6, $at, L_806FE2D0
    if (ctx->r14 != ctx->r1) {
        // 0x806FE274: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_806FE2D0;
    }
    // 0x806FE274: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806FE278: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806FE27C: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x806FE280: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806FE284: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x806FE288: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x806FE28C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x806FE290: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x806FE294: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x806FE298: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x806FE29C: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    // 0x806FE2A0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x806FE2A4: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x806FE2A8: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806FE2AC: jalr        $t9
    // 0x806FE2B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806FE2B0: nop

    after_0:
    // 0x806FE2B4: jal         0x800447C8
    // 0x806FE2B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806FE2B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x806FE2BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806FE2C0: jal         0x806FD4FC
    // 0x806FE2C4: addiu       $a1, $zero, 0xBA
    ctx->r5 = ADD32(0, 0XBA);
    func_806FD4FC(rdram, ctx);
        goto after_2;
    // 0x806FE2C4: addiu       $a1, $zero, 0xBA
    ctx->r5 = ADD32(0, 0XBA);
    after_2:
    // 0x806FE2C8: jal         0x806FD7B0
    // 0x806FE2CC: nop

    func_806FD7B0(rdram, ctx);
        goto after_3;
    // 0x806FE2CC: nop

    after_3:
L_806FE2D0:
    // 0x806FE2D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FE2D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806FE2D8: jr          $ra
    // 0x806FE2DC: nop

    return;
    // 0x806FE2DC: nop

;}
RECOMP_FUNC void func_805269F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805269F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805269FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526A00: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80526A04: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80526A08: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80526A0C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80526A10: jal         0x80067BBC
    // 0x80526A14: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80526A14: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80526A18: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    // 0x80526A1C: jal         0x80067818
    // 0x80526A20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80526A20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80526A24: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80526A28: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6144) << 16);
    // 0x80526A2C: lwc1        $f4, -0x3FBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6144));
    // 0x80526A30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80526A34: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(327, 0X2AE4) << 16);
    // 0x80526A38: addiu       $v0, $v0, -0x761C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(327, 0X2AE4));
    // 0x80526A3C: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(327, 0XB74) << 16);
    // 0x80526A40: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80526A44: addiu       $t7, $t7, 0x6A74
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(327, 0XB74));
    // 0x80526A48: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80526A4C: sw          $t6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r14;
    // 0x80526A50: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80526A54: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80526A58: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80526A5C: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80526A60: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x80526A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80526A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526A6C: jr          $ra
    // 0x80526A70: nop

    return;
    // 0x80526A70: nop

;}
RECOMP_FUNC void func_804C4180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C4180: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x804C4184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C4188: sw          $a0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r4;
    // 0x804C418C: lw          $t3, 0x1F4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C4190: jal         0x8004700C
    // 0x804C4194: sw          $t3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r11;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804C4194: sw          $t3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r11;
    after_0:
    // 0x804C4198: jal         0x800582CC
    // 0x804C419C: sw          $v0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r2;
    func_800582CC(rdram, ctx);
        goto after_1;
    // 0x804C419C: sw          $v0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r2;
    after_1:
    // 0x804C41A0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x804C41A4: lw          $t8, -0x6DA8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6DA8);
    // 0x804C41A8: lw          $a0, 0x138($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X138);
    // 0x804C41AC: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x804C41B0: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x804C41B4: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x804C41B8: addiu       $t6, $t8, 0xC0
    ctx->r14 = ADD32(ctx->r24, 0XC0);
L_804C41BC:
    // 0x804C41BC: lw          $t5, 0x58($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X58);
    // 0x804C41C0: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x804C41C4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x804C41C8: sw          $t5, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r13;
    // 0x804C41CC: lw          $t9, 0x50($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X50);
    // 0x804C41D0: sw          $t9, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r25;
    // 0x804C41D4: lw          $t5, 0x54($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X54);
    // 0x804C41D8: bne         $t8, $t6, L_804C41BC
    if (ctx->r24 != ctx->r14) {
        // 0x804C41DC: sw          $t5, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r13;
            goto L_804C41BC;
    }
    // 0x804C41DC: sw          $t5, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r13;
    // 0x804C41E0: lw          $t5, 0x58($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X58);
    // 0x804C41E4: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x804C41E8: lw          $t9, 0x5C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X5C);
    // 0x804C41EC: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x804C41F0: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x804C41F4: beql        $v1, $zero, L_804C422C
    if (ctx->r3 == 0) {
        // 0x804C41F8: sw          $t2, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->r10;
            goto L_804C422C;
    }
    goto skip_0;
    // 0x804C41F8: sw          $t2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r10;
    skip_0:
    // 0x804C41FC: lhu         $t6, 0xC($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XC);
    // 0x804C4200: addiu       $at, $zero, 0x41EC
    ctx->r1 = ADD32(0, 0X41EC);
    // 0x804C4204: bne         $t6, $at, L_804C4228
    if (ctx->r14 != ctx->r1) {
        // 0x804C4208: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_804C4228;
    }
    // 0x804C4208: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C420C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804C4210: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(209, 0XE68) << 16);
    // 0x804C4214: lwc1        $f6, 0x4E58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(209, 0XE68));
    // 0x804C4218: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804C421C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804C4220: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x804C4224: swc1        $f10, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f10.u32l;
L_804C4228:
    // 0x804C4228: sw          $t2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r10;
L_804C422C:
    // 0x804C422C: jal         0x804C4000
    // 0x804C4230: sw          $t3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r11;
    func_804C4000(rdram, ctx);
        goto after_2;
    // 0x804C4230: sw          $t3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r11;
    after_2:
    // 0x804C4234: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x804C4238: addiu       $at, $zero, 0x405E
    ctx->r1 = ADD32(0, 0X405E);
    // 0x804C423C: lw          $t2, 0x108($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X108);
    // 0x804C4240: lhu         $t7, 0xC($t8)
    ctx->r15 = MEM_HU(ctx->r24, 0XC);
    // 0x804C4244: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x804C4248: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x804C424C: bnel        $t7, $at, L_804C426C
    if (ctx->r15 != ctx->r1) {
        // 0x804C4250: lhu         $t9, 0x14($t3)
        ctx->r25 = MEM_HU(ctx->r11, 0X14);
            goto L_804C426C;
    }
    goto skip_1;
    // 0x804C4250: lhu         $t9, 0x14($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X14);
    skip_1:
    // 0x804C4254: sw          $t2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r10;
    // 0x804C4258: jal         0x804C40B8
    // 0x804C425C: sw          $t3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r11;
    func_804C40B8(rdram, ctx);
        goto after_3;
    // 0x804C425C: sw          $t3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r11;
    after_3:
    // 0x804C4260: lw          $t2, 0x108($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X108);
    // 0x804C4264: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x804C4268: lhu         $t9, 0x14($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X14);
L_804C426C:
    // 0x804C426C: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x804C4270: andi        $t5, $t9, 0x1
    ctx->r13 = ctx->r25 & 0X1;
    // 0x804C4274: beql        $t5, $zero, L_804C44A8
    if (ctx->r13 == 0) {
        // 0x804C4278: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C44A8;
    }
    goto skip_2;
    // 0x804C4278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804C427C: beql        $t6, $zero, L_804C44A8
    if (ctx->r14 == 0) {
        // 0x804C4280: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C44A8;
    }
    goto skip_3;
    // 0x804C4280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x804C4284: sw          $t2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r10;
    // 0x804C4288: jal         0x80058958
    // 0x804C428C: sw          $t3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r11;
    func_80058958(rdram, ctx);
        goto after_4;
    // 0x804C428C: sw          $t3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r11;
    after_4:
    // 0x804C4290: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804C4294: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804C4298: lw          $t2, 0x108($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X108);
    // 0x804C429C: beq         $v0, $zero, L_804C44A4
    if (ctx->r2 == 0) {
        // 0x804C42A0: lw          $t3, 0x134($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X134);
            goto L_804C44A4;
    }
    // 0x804C42A0: lw          $t3, 0x134($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X134);
    // 0x804C42A4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x804C42A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804C42AC: lwc1        $f4, 0x18($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X18);
    // 0x804C42B0: addiu       $v1, $sp, 0xF8
    ctx->r3 = ADD32(ctx->r29, 0XF8);
    // 0x804C42B4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x804C42B8: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804C42BC: addiu       $a0, $sp, 0x104
    ctx->r4 = ADD32(ctx->r29, 0X104);
    // 0x804C42C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804C42C4: beq         $v1, $a0, L_804C42F0
    if (ctx->r3 == ctx->r4) {
        // 0x804C42C8: lw          $t7, 0x8($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X8);
            goto L_804C42F0;
    }
    // 0x804C42C8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
L_804C42CC:
    // 0x804C42CC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x804C42D0: lwc1        $f12, 0x18($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X18);
    // 0x804C42D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804C42D8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804C42DC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804C42E0: mul.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x804C42E4: swc1        $f12, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f12.u32l;
    // 0x804C42E8: bne         $v1, $a0, L_804C42CC
    if (ctx->r3 != ctx->r4) {
        // 0x804C42EC: lw          $t7, 0x8($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X8);
            goto L_804C42CC;
    }
    // 0x804C42EC: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
L_804C42F0:
    // 0x804C42F0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x804C42F4: lwc1        $f12, 0x18($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X18);
    // 0x804C42F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804C42FC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804C4300: mul.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x804C4304: swc1        $f12, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f12.u32l;
    // 0x804C4308: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x804C430C: addiu       $at, $zero, 0x405E
    ctx->r1 = ADD32(0, 0X405E);
    // 0x804C4310: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x804C4314: lhu         $t9, 0xC($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0XC);
    // 0x804C4318: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x804C431C: addiu       $t4, $sp, 0x90
    ctx->r12 = ADD32(ctx->r29, 0X90);
    // 0x804C4320: bne         $t9, $at, L_804C43E4
    if (ctx->r25 != ctx->r1) {
        // 0x804C4324: addiu       $a3, $sp, 0x104
        ctx->r7 = ADD32(ctx->r29, 0X104);
            goto L_804C43E4;
    }
    // 0x804C4324: addiu       $a3, $sp, 0x104
    ctx->r7 = ADD32(ctx->r29, 0X104);
    // 0x804C4328: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(209, 0XE6C) << 16);
    // 0x804C432C: lwc1        $f16, 0x4E5C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(209, 0XE6C));
    // 0x804C4330: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x804C4334: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x804C4338: addiu       $t4, $sp, 0x90
    ctx->r12 = ADD32(ctx->r29, 0X90);
    // 0x804C433C: addiu       $a3, $sp, 0x104
    ctx->r7 = ADD32(ctx->r29, 0X104);
L_804C4340:
    // 0x804C4340: lwc1        $f8, 0x68($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X68);
    // 0x804C4344: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x804C4348: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x804C434C: addiu       $v1, $sp, 0xF8
    ctx->r3 = ADD32(ctx->r29, 0XF8);
    // 0x804C4350: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804C4354: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x804C4358: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x804C435C: nop

    // 0x804C4360: mul.s       $f2, $f4, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x804C4364: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x804C4368: nop

    // 0x804C436C: bc1f        L_804C43D4
    if (!c1cs) {
        // 0x804C4370: nop
    
            goto L_804C43D4;
    }
    // 0x804C4370: nop

    // 0x804C4374: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x804C4378: addu        $v0, $t2, $t1
    ctx->r2 = ADD32(ctx->r10, ctx->r9);
    // 0x804C437C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804C4380: bc1fl       L_804C4394
    if (!c1cs) {
        // 0x804C4384: div.s       $f0, $f14, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
            goto L_804C4394;
    }
    goto skip_4;
    // 0x804C4384: div.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    skip_4:
    // 0x804C4388: b           L_804C4394
    // 0x804C438C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_804C4394;
    // 0x804C438C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x804C4390: div.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
L_804C4394:
    // 0x804C4394: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804C4398: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x804C439C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804C43A0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804C43A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x804C43A8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804C43AC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x804C43B0: nop

    // 0x804C43B4: addu        $v0, $t6, $a2
    ctx->r2 = ADD32(ctx->r14, ctx->r6);
    // 0x804C43B8: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x804C43BC: bnel        $at, $zero, L_804C43CC
    if (ctx->r1 != 0) {
        // 0x804C43C0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_804C43CC;
    }
    goto skip_5;
    // 0x804C43C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_5:
    // 0x804C43C4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x804C43C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_804C43CC:
    // 0x804C43CC: bne         $v1, $a3, L_804C4394
    if (ctx->r3 != ctx->r7) {
        // 0x804C43D0: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_804C4394;
    }
    // 0x804C43D0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_804C43D4:
    // 0x804C43D4: bne         $t0, $t4, L_804C4340
    if (ctx->r8 != ctx->r12) {
        // 0x804C43D8: addiu       $t1, $t1, 0x3
        ctx->r9 = ADD32(ctx->r9, 0X3);
            goto L_804C4340;
    }
    // 0x804C43D8: addiu       $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x804C43DC: b           L_804C449C
    // 0x804C43E0: lhu         $t9, 0x14($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X14);
        goto L_804C449C;
    // 0x804C43E0: lhu         $t9, 0x14($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X14);
L_804C43E4:
    // 0x804C43E4: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(209, 0XE70) << 16);
    // 0x804C43E8: lwc1        $f16, 0x4E60($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(209, 0XE70));
L_804C43EC:
    // 0x804C43EC: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x804C43F0: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x804C43F4: lwc1        $f8, 0x68($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X68);
    // 0x804C43F8: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x804C43FC: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804C4400: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x804C4404: addiu       $v1, $sp, 0xF8
    ctx->r3 = ADD32(ctx->r29, 0XF8);
    // 0x804C4408: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804C440C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x804C4410: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x804C4414: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x804C4418: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804C441C: mul.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x804C4420: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x804C4424: nop

    // 0x804C4428: bc1f        L_804C4490
    if (!c1cs) {
        // 0x804C442C: nop
    
            goto L_804C4490;
    }
    // 0x804C442C: nop

    // 0x804C4430: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x804C4434: addu        $v0, $t2, $t1
    ctx->r2 = ADD32(ctx->r10, ctx->r9);
    // 0x804C4438: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804C443C: bc1fl       L_804C4450
    if (!c1cs) {
        // 0x804C4440: div.s       $f0, $f14, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
            goto L_804C4450;
    }
    goto skip_6;
    // 0x804C4440: div.s       $f0, $f14, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
    skip_6:
    // 0x804C4444: b           L_804C4450
    // 0x804C4448: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_804C4450;
    // 0x804C4448: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x804C444C: div.s       $f0, $f14, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
L_804C4450:
    // 0x804C4450: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804C4454: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x804C4458: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804C445C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x804C4460: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x804C4464: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804C4468: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x804C446C: nop

    // 0x804C4470: addu        $v0, $t8, $a2
    ctx->r2 = ADD32(ctx->r24, ctx->r6);
    // 0x804C4474: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x804C4478: bnel        $at, $zero, L_804C4488
    if (ctx->r1 != 0) {
        // 0x804C447C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_804C4488;
    }
    goto skip_7;
    // 0x804C447C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_7:
    // 0x804C4480: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x804C4484: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_804C4488:
    // 0x804C4488: bne         $v1, $a3, L_804C4450
    if (ctx->r3 != ctx->r7) {
        // 0x804C448C: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_804C4450;
    }
    // 0x804C448C: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_804C4490:
    // 0x804C4490: bne         $t0, $t4, L_804C43EC
    if (ctx->r8 != ctx->r12) {
        // 0x804C4494: addiu       $t1, $t1, 0x3
        ctx->r9 = ADD32(ctx->r9, 0X3);
            goto L_804C43EC;
    }
    // 0x804C4494: addiu       $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x804C4498: lhu         $t9, 0x14($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X14);
L_804C449C:
    // 0x804C449C: andi        $t5, $t9, 0xFFFE
    ctx->r13 = ctx->r25 & 0XFFFE;
    // 0x804C44A0: sh          $t5, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r13;
L_804C44A4:
    // 0x804C44A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C44A8:
    // 0x804C44A8: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // 0x804C44AC: jr          $ra
    // 0x804C44B0: nop

    return;
    // 0x804C44B0: nop

;}
RECOMP_FUNC void func_807986FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807986FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80798700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80798704: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80798708: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8079870C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80798710: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80798714: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80798718: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8079871C: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(820, 0X300) << 16);
    // 0x80798720: lwc1        $f10, -0x7710($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(820, 0X300));
    // 0x80798724: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80798728: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8079872C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80798730: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80798734: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80798738: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8079873C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80798740: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80798744: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80798748: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8079874C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80798750: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80798754: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80798758: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8079875C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80798760: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80798764: jalr        $t9
    // 0x80798768: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80798768: nop

    after_0:
    // 0x8079876C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80798770: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80798774: jr          $ra
    // 0x80798778: nop

    return;
    // 0x80798778: nop

;}
RECOMP_FUNC void func_807B9118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B911C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9120: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B9124: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x807B9128: addiu       $a1, $a1, -0x71A8
    ctx->r5 = ADD32(ctx->r5, -0X71A8);
    // 0x807B912C: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x807B9130: jal         0x8008B800
    // 0x807B9134: addiu       $a0, $v0, 0x4C
    ctx->r4 = ADD32(ctx->r2, 0X4C);
    _bcmp(rdram, ctx);
        goto after_0;
    // 0x807B9134: addiu       $a0, $v0, 0x4C
    ctx->r4 = ADD32(ctx->r2, 0X4C);
    after_0:
    // 0x807B9138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B913C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B9140: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x807B9144: jr          $ra
    // 0x807B9148: nop

    return;
    // 0x807B9148: nop

;}
RECOMP_FUNC void func_80065474(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065474: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80065478: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006547C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80065480: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80065484: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80065488: jr          $ra
    // 0x8006548C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x8006548C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_805157F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805157F4: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(276, 0X113C) << 16);
    // 0x805157F8: lw          $v0, 0x65DC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(276, 0X113C));
    // 0x805157FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80515800: addiu       $at, $zero, -0x9A
    ctx->r1 = ADD32(0, -0X9A);
    // 0x80515804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80515808: beq         $v0, $at, L_80515824
    if (ctx->r2 == ctx->r1) {
        // 0x8051580C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80515824;
    }
    // 0x8051580C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80515810: addiu       $at, $zero, -0x7D
    ctx->r1 = ADD32(0, -0X7D);
    // 0x80515814: bnel        $v0, $at, L_8051585C
    if (ctx->r2 != ctx->r1) {
        // 0x80515818: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8051585C;
    }
    goto skip_0;
    // 0x80515818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8051581C: b           L_80515828
    // 0x80515820: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
        goto L_80515828;
    // 0x80515820: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
L_80515824:
    // 0x80515824: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
L_80515828:
    // 0x80515828: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x8051582C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80515830: bne         $a1, $at, L_80515850
    if (ctx->r5 != ctx->r1) {
        // 0x80515834: nop
    
            goto L_80515850;
    }
    // 0x80515834: nop

    // 0x80515838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8051583C: jal         0x80067F78
    // 0x80515840: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067F78(rdram, ctx);
        goto after_0;
    // 0x80515840: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80515844: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80515848: b           L_80515858
    // 0x8051584C: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
        goto L_80515858;
    // 0x8051584C: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
L_80515850:
    // 0x80515850: jal         0x800678F0
    // 0x80515854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800678F0(rdram, ctx);
        goto after_1;
    // 0x80515854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80515858:
    // 0x80515858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051585C:
    // 0x8051585C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80515860: jr          $ra
    // 0x80515864: nop

    return;
    // 0x80515864: nop

;}
RECOMP_FUNC void func_8044CCE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044CCE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044CCE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044CCEC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8044CCF0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8044CCF4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8044CCF8: jal         0x8044CA18
    // 0x8044CCFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8044CA18(rdram, ctx);
        goto after_0;
    // 0x8044CCFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8044CD00: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8044CD04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8044CD08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8044CD0C: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8044CD10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044CD14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8044CD18: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x8044CD1C: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8044CD20: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8044CD24: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8044CD28: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8044CD2C: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8044CD30: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8044CD34: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8044CD38: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8044CD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044CD40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044CD44: jr          $ra
    // 0x8044CD48: nop

    return;
    // 0x8044CD48: nop

;}
RECOMP_FUNC void func_8042CD68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042CD68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8042CD6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042CD70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042CD74: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042CD78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8042CD7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042CD80: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8042CD84: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8042CD88: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8042CD8C: jal         0x8042A9DC
    // 0x8042CD90: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_8042A9DC(rdram, ctx);
        goto after_0;
    // 0x8042CD90: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x8042CD94: jal         0x8042BB3C
    // 0x8042CD98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BB3C(rdram, ctx);
        goto after_1;
    // 0x8042CD98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8042CD9C: jal         0x8042BA84
    // 0x8042CDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042BA84(rdram, ctx);
        goto after_2;
    // 0x8042CDA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8042CDA4: lh          $t6, 0x144($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X144);
    // 0x8042CDA8: bne         $t6, $zero, L_8042CDC0
    if (ctx->r14 != 0) {
        // 0x8042CDAC: nop
    
            goto L_8042CDC0;
    }
    // 0x8042CDAC: nop

    // 0x8042CDB0: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042CDB4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8042CDB8: b           L_8042CDC8
    // 0x8042CDBC: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
        goto L_8042CDC8;
    // 0x8042CDBC: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
L_8042CDC0:
    // 0x8042CDC0: jal         0x8042B810
    // 0x8042CDC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042B810(rdram, ctx);
        goto after_3;
    // 0x8042CDC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8042CDC8:
    // 0x8042CDC8: jal         0x8042B410
    // 0x8042CDCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042B410(rdram, ctx);
        goto after_4;
    // 0x8042CDCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8042CDD0: lw          $t9, 0x1E0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E0);
    // 0x8042CDD4: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8042CDD8: bnel        $at, $zero, L_8042CE4C
    if (ctx->r1 != 0) {
        // 0x8042CDDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8042CE4C;
    }
    goto skip_0;
    // 0x8042CDDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8042CDE0: jal         0x800653D8
    // 0x8042CDE4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x8042CDE4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    after_5:
    // 0x8042CDE8: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8042CDEC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8042CDF0: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8042CDF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042CDF8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042CDFC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8042CE00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8042CE04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8042CE08: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x8042CE0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042CE10: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8042CE14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042CE18: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8042CE1C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8042CE20: bne         $t1, $at, L_8042CE40
    if (ctx->r9 != ctx->r1) {
        // 0x8042CE24: swc1        $f10, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
            goto L_8042CE40;
    }
    // 0x8042CE24: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x8042CE28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042CE2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042CE30: jal         0x8042D50C
    // 0x8042CE34: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8042D50C(rdram, ctx);
        goto after_6;
    // 0x8042CE34: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_6:
    // 0x8042CE38: b           L_8042CE4C
    // 0x8042CE3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042CE4C;
    // 0x8042CE3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042CE40:
    // 0x8042CE40: jal         0x8042D50C
    // 0x8042CE44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8042D50C(rdram, ctx);
        goto after_7;
    // 0x8042CE44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8042CE48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042CE4C:
    // 0x8042CE4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042CE50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8042CE54: jr          $ra
    // 0x8042CE58: nop

    return;
    // 0x8042CE58: nop

;}
RECOMP_FUNC void func_8000A3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A3B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A3BC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000A3C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A3C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000A3C8: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8000A3CC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8000A3D0: jal         0x8000A2F4
    // 0x8000A3D4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8000A2F4(rdram, ctx);
        goto after_0;
    // 0x8000A3D4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8000A3D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A3DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A3E0: jr          $ra
    // 0x8000A3E4: nop

    return;
    // 0x8000A3E4: nop

;}
RECOMP_FUNC void func_800694BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800694BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800694C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800694C4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800694C8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800694CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800694D0: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800694D4: jal         0x800679D0
    // 0x800694D8: lw          $a0, 0x6F10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6F10);
    func_800679D0(rdram, ctx);
        goto after_0;
    // 0x800694D8: lw          $a0, 0x6F10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6F10);
    after_0:
    // 0x800694DC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800694E0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800694E4: lbu         $t2, 0xFB8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XFB8);
    // 0x800694E8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800694EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800694F0: andi        $t3, $t2, 0xFF3F
    ctx->r11 = ctx->r10 & 0XFF3F;
    // 0x800694F4: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x800694F8: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x800694FC: sb          $t4, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r12;
    // 0x80069500: jr          $ra
    // 0x80069504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80473234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473234: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X1470) << 16);
    // 0x80473238: lwc1        $f0, 0x4600($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X1470));
    // 0x8047323C: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x80473240: jr          $ra
    // 0x80473244: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80473244: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_806B28BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B28BC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B28C0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B28C4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B28C8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B28CC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B28D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B28D4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B28D8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B28DC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B28E0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B28E4: jr          $ra
    // 0x806B28E8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B28E8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804F42B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F42B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804F42BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804F42C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804F42C4: jal         0x804F43E8
    // 0x804F42C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804F43E8(rdram, ctx);
        goto after_0;
    // 0x804F42C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804F42CC: beq         $v0, $zero, L_804F4358
    if (ctx->r2 == 0) {
        // 0x804F42D0: nop
    
            goto L_804F4358;
    }
    // 0x804F42D0: nop

    // 0x804F42D4: jal         0x804F4484
    // 0x804F42D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804F4484(rdram, ctx);
        goto after_1;
    // 0x804F42D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804F42DC: jal         0x80051194
    // 0x804F42E0: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    func_80051194(rdram, ctx);
        goto after_2;
    // 0x804F42E0: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    after_2:
    // 0x804F42E4: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x804F42E8: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804F42EC: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804F42F0: lui         $t7, 0x8051
    ctx->r15 = S32(RELOC_HI16(273, 0X20868) << 16);
    // 0x804F42F4: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x804F42F8: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x804F42FC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804F4300: addiu       $t7, $t7, 0x4AF8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(273, 0X20868));
    // 0x804F4304: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804F4308: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x804F430C: lui         $t9, 0x804F
    ctx->r25 = S32(RELOC_HI16(273, 0X954) << 16);
    // 0x804F4310: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804F4314: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804F4318: addiu       $t9, $t9, 0x4BE4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(273, 0X954));
    // 0x804F431C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F4320: jal         0x804F42A0
    // 0x804F4324: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_804F42A0(rdram, ctx);
        goto after_3;
    // 0x804F4324: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_3:
    // 0x804F4328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F432C: jal         0x80057640
    // 0x804F4330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80057640(rdram, ctx);
        goto after_4;
    // 0x804F4330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x804F4334: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804F4338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804F433C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804F4340: sw          $v0, 0x64($t1)
    MEM_W(0X64, ctx->r9) = ctx->r2;
    // 0x804F4344: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x804F4348: jal         0x804F5CE8
    // 0x804F434C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804F5CE8(rdram, ctx);
        goto after_5;
    // 0x804F434C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x804F4350: b           L_804F4364
    // 0x804F4354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804F4364;
    // 0x804F4354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F4358:
    // 0x804F4358: jal         0x800445A4
    // 0x804F435C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x804F435C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804F4360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804F4364:
    // 0x804F4364: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804F4368: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804F436C: jr          $ra
    // 0x804F4370: nop

    return;
    // 0x804F4370: nop

;}
RECOMP_FUNC void func_804606DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804606DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804606E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804606E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804606E8: lh          $a2, 0x1F0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1F0);
    // 0x804606EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804606F0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x804606F4: beq         $a2, $at, L_80460720
    if (ctx->r6 == ctx->r1) {
        // 0x804606F8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80460720;
    }
    // 0x804606F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804606FC: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80460700: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80460704: jal         0x80067930
    // 0x80460708: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80460708: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8046070C: beq         $v0, $zero, L_80460720
    if (ctx->r2 == 0) {
        // 0x80460710: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80460720;
    }
    // 0x80460710: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80460714: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80460718: jal         0x80067878
    // 0x8046071C: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x8046071C: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_1:
L_80460720:
    // 0x80460720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460728: jr          $ra
    // 0x8046072C: nop

    return;
    // 0x8046072C: nop

;}
RECOMP_FUNC void func_805AC41C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC41C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AC420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC424: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805AC428: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AC42C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805AC430: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x805AC434: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805AC438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805AC43C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x805AC440: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x805AC444: jal         0x8004D150
    // 0x805AC448: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_8004D150(rdram, ctx);
        goto after_0;
    // 0x805AC448: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x805AC44C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805AC450: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x805AC454: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x805AC458: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x805AC45C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805AC460: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805AC464: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x805AC468: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x805AC46C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805AC470: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x805AC474: lbu         $t1, 0x14($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X14);
    // 0x805AC478: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x805AC47C: beql        $t1, $zero, L_805AC4AC
    if (ctx->r9 == 0) {
        // 0x805AC480: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AC4AC;
    }
    goto skip_0;
    // 0x805AC480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805AC484: jal         0x8004D618
    // 0x805AC488: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8004D618(rdram, ctx);
        goto after_1;
    // 0x805AC488: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x805AC48C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x805AC490: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805AC494: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805AC498: sw          $t2, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r10;
    // 0x805AC49C: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x805AC4A0: ori         $t5, $t4, 0xF00
    ctx->r13 = ctx->r12 | 0XF00;
    // 0x805AC4A4: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x805AC4A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AC4AC:
    // 0x805AC4AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805AC4B0: jr          $ra
    // 0x805AC4B4: nop

    return;
    // 0x805AC4B4: nop

;}
RECOMP_FUNC void func_80049110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80049118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004911C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80049120: jal         0x800490A8
    // 0x80049124: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800490A8(rdram, ctx);
        goto after_0;
    // 0x80049124: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80049128: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8004912C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80049130: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80049134: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80049138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004913C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049140: jr          $ra
    // 0x80049144: nop

    return;
    // 0x80049144: nop

;}
RECOMP_FUNC void func_806B226C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B226C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B2270: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B2274: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B2278: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B227C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B2280: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B2284: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B2288: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B228C: addiu       $t6, $zero, 0xDD4
    ctx->r14 = ADD32(0, 0XDD4);
    // 0x806B2290: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B2294: addiu       $a2, $zero, 0xA50
    ctx->r6 = ADD32(0, 0XA50);
    // 0x806B2298: addiu       $a3, $zero, 0xC6C
    ctx->r7 = ADD32(0, 0XC6C);
    // 0x806B229C: addiu       $a1, $zero, 0x99C
    ctx->r5 = ADD32(0, 0X99C);
    // 0x806B22A0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x806B22A4: jal         0x806B195C
    // 0x806B22A8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_806B195C(rdram, ctx);
        goto after_0;
    // 0x806B22A8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x806B22AC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B22B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B22B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B22B8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B22BC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806B22C0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B22C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B22C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B22CC: jr          $ra
    // 0x806B22D0: nop

    return;
    // 0x806B22D0: nop

;}
RECOMP_FUNC void func_807A6D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6D34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A6D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6D3C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807A6D40: blez        $v0, L_807A6D50
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807A6D44: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807A6D50;
    }
    // 0x807A6D44: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807A6D48: b           L_807A6D84
    // 0x807A6D4C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_807A6D84;
    // 0x807A6D4C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807A6D50:
    // 0x807A6D50: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807A6D54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807A6D58: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x807A6D5C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x807A6D60: addiu       $a1, $t8, 0x1
    ctx->r5 = ADD32(ctx->r24, 0X1);
    // 0x807A6D64: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x807A6D68: bne         $at, $zero, L_807A6D78
    if (ctx->r1 != 0) {
        // 0x807A6D6C: sw          $a1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r5;
            goto L_807A6D78;
    }
    // 0x807A6D6C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x807A6D70: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x807A6D74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_807A6D78:
    // 0x807A6D78: jal         0x807A61F0
    // 0x807A6D7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A61F0(rdram, ctx);
        goto after_0;
    // 0x807A6D7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A6D80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_807A6D84:
    // 0x807A6D84: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    // 0x807A6D88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807A6D8C: beql        $a2, $at, L_807A6DA0
    if (ctx->r6 == ctx->r1) {
        // 0x807A6D90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807A6DA0;
    }
    goto skip_0;
    // 0x807A6D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807A6D94: jal         0x807A7138
    // 0x807A6D98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A7138(rdram, ctx);
        goto after_1;
    // 0x807A6D98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x807A6D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A6DA0:
    // 0x807A6DA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A6DA4: jr          $ra
    // 0x807A6DA8: nop

    return;
    // 0x807A6DA8: nop

;}
RECOMP_FUNC void func_804BD178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BD17C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD180: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804BD184: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804BD188: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X4098) << 16);
    // 0x804BD18C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BD190: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804BD194: lw          $t8, -0x638($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(191, 0X4098));
    // 0x804BD198: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804BD19C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804BD1A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804BD1A4: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804BD1A8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804BD1AC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804BD1B0: beql        $v1, $zero, L_804BD1E4
    if (ctx->r3 == 0) {
        // 0x804BD1B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BD1E4;
    }
    goto skip_0;
    // 0x804BD1B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BD1B8: jalr        $v1
    // 0x804BD1BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804BD1BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BD1C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BD1C4: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804BD1C8: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804BD1CC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804BD1D0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804BD1D4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804BD1D8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804BD1DC: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804BD1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BD1E4:
    // 0x804BD1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BD1E8: jr          $ra
    // 0x804BD1EC: nop

    return;
    // 0x804BD1EC: nop

;}
RECOMP_FUNC void func_8000CC9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CC9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000CCA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000CCA4: lhu         $v0, 0x1A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1A);
    // 0x8000CCA8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000CCAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CCB0: beq         $v0, $zero, L_8000CCC8
    if (ctx->r2 == 0) {
        // 0x8000CCB4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8000CCC8;
    }
    // 0x8000CCB4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8000CCB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CCBC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000CCC0: b           L_8000CE80
    // 0x8000CCC4: sh          $t6, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r14;
        goto L_8000CE80;
    // 0x8000CCC4: sh          $t6, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r14;
L_8000CCC8:
    // 0x8000CCC8: beql        $v1, $at, L_8000CE1C
    if (ctx->r3 == ctx->r1) {
        // 0x8000CCCC: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8000CE1C;
    }
    goto skip_0;
    // 0x8000CCCC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x8000CCD0: lhu         $v0, 0x18($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X18);
    // 0x8000CCD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000CCD8: beql        $v0, $zero, L_8000CD3C
    if (ctx->r2 == 0) {
        // 0x8000CCDC: lwc1        $f10, 0xC($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
            goto L_8000CD3C;
    }
    goto skip_1;
    // 0x8000CCDC: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    skip_1:
    // 0x8000CCE0: bne         $v0, $at, L_8000CD04
    if (ctx->r2 != ctx->r1) {
        // 0x8000CCE4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000CD04;
    }
    // 0x8000CCE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000CCE8: lhu         $t7, 0x16($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X16);
    // 0x8000CCEC: lhu         $v0, 0x18($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X18);
    // 0x8000CCF0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8000CCF4: nop

    // 0x8000CCF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000CCFC: b           L_8000CD2C
    // 0x8000CD00: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
        goto L_8000CD2C;
    // 0x8000CD00: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
L_8000CD04:
    // 0x8000CD04: lhu         $t8, 0x16($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X16);
    // 0x8000CD08: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x8000CD0C: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000CD10: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8000CD14: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000CD18: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000CD1C: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8000CD20: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000CD24: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8000CD28: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
L_8000CD2C:
    // 0x8000CD2C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8000CD30: b           L_8000CD74
    // 0x8000CD34: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
        goto L_8000CD74;
    // 0x8000CD34: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    // 0x8000CD38: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
L_8000CD3C:
    // 0x8000CD3C: lhu         $t2, 0x16($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X16);
    // 0x8000CD40: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8000CD44: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x8000CD48: nop

    // 0x8000CD4C: beql        $t1, $t2, L_8000CD78
    if (ctx->r9 == ctx->r10) {
        // 0x8000CD50: lhu         $v0, 0x16($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0X16);
            goto L_8000CD78;
    }
    goto skip_2;
    // 0x8000CD50: lhu         $v0, 0x16($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X16);
    skip_2:
    // 0x8000CD54: lhu         $v0, 0x1A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1A);
    // 0x8000CD58: bne         $v0, $zero, L_8000CD74
    if (ctx->r2 != 0) {
        // 0x8000CD5C: sh          $v0, 0x18($a0)
        MEM_H(0X18, ctx->r4) = ctx->r2;
            goto L_8000CD74;
    }
    // 0x8000CD5C: sh          $v0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r2;
    // 0x8000CD60: lhu         $t3, 0x16($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X16);
    // 0x8000CD64: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8000CD68: nop

    // 0x8000CD6C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000CD70: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
L_8000CD74:
    // 0x8000CD74: lhu         $v0, 0x16($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X16);
L_8000CD78:
    // 0x8000CD78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000CD7C: beql        $v0, $zero, L_8000CDE0
    if (ctx->r2 == 0) {
        // 0x8000CD80: lwc1        $f18, 0x10($a0)
        ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
            goto L_8000CDE0;
    }
    goto skip_3;
    // 0x8000CD80: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    skip_3:
    // 0x8000CD84: bne         $v0, $at, L_8000CDA8
    if (ctx->r2 != ctx->r1) {
        // 0x8000CD88: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000CDA8;
    }
    // 0x8000CD88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000CD8C: lhu         $t4, 0x14($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X14);
    // 0x8000CD90: lhu         $v0, 0x16($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X16);
    // 0x8000CD94: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8000CD98: nop

    // 0x8000CD9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000CDA0: b           L_8000CDD0
    // 0x8000CDA4: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
        goto L_8000CDD0;
    // 0x8000CDA4: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
L_8000CDA8:
    // 0x8000CDA8: lhu         $t5, 0x14($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X14);
    // 0x8000CDAC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8000CDB0: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000CDB4: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8000CDB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000CDBC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000CDC0: sub.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8000CDC4: div.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000CDC8: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8000CDCC: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
L_8000CDD0:
    // 0x8000CDD0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8000CDD4: b           L_8000CE18
    // 0x8000CDD8: sh          $t6, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r14;
        goto L_8000CE18;
    // 0x8000CDD8: sh          $t6, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r14;
    // 0x8000CDDC: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
L_8000CDE0:
    // 0x8000CDE0: lhu         $t9, 0x14($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X14);
    // 0x8000CDE4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8000CDE8: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8000CDEC: nop

    // 0x8000CDF0: beql        $t8, $t9, L_8000CE1C
    if (ctx->r24 == ctx->r25) {
        // 0x8000CDF4: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8000CE1C;
    }
    goto skip_4;
    // 0x8000CDF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_4:
    // 0x8000CDF8: lhu         $v0, 0x18($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X18);
    // 0x8000CDFC: bne         $v0, $zero, L_8000CE18
    if (ctx->r2 != 0) {
        // 0x8000CE00: sh          $v0, 0x16($a0)
        MEM_H(0X16, ctx->r4) = ctx->r2;
            goto L_8000CE18;
    }
    // 0x8000CE00: sh          $v0, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r2;
    // 0x8000CE04: lhu         $t0, 0x14($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X14);
    // 0x8000CE08: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8000CE0C: nop

    // 0x8000CE10: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000CE14: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_8000CE18:
    // 0x8000CE18: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8000CE1C:
    // 0x8000CE1C: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000CE20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CE24: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8000CE28: nop

    // 0x8000CE2C: bc1f        L_8000CE40
    if (!c1cs) {
        // 0x8000CE30: nop
    
            goto L_8000CE40;
    }
    // 0x8000CE30: nop

    // 0x8000CE34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000CE38: b           L_8000CE84
    // 0x8000CE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000CE84;
    // 0x8000CE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000CE40:
    // 0x8000CE40: jal         0x8000CC58
    // 0x8000CE44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8000CC58(rdram, ctx);
        goto after_0;
    // 0x8000CE44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000CE48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000CE4C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000CE50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000CE54: lui         $at, 0x3980
    ctx->r1 = S32(0X3980 << 16);
    // 0x8000CE58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000CE5C: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000CE60: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8000CE64: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8000CE68: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8000CE6C: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000CE70: lwc1        $f16, 0x63D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X63D4);
    // 0x8000CE74: sub.s       $f6, $f16, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x8000CE78: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8000CE7C: add.s       $f0, $f8, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f14.fl;
L_8000CE80:
    // 0x8000CE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000CE84:
    // 0x8000CE84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000CE88: jr          $ra
    // 0x8000CE8C: nop

    return;
    // 0x8000CE8C: nop

;}
RECOMP_FUNC void func_8041DA9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041DA9C: jr          $ra
    // 0x8041DAA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8041DAA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806656B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806656B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806656BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806656C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806656C4: jal         0x8004700C
    // 0x806656C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806656C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806656CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x806656D0: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x806656D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806656D8: jal         0x80665110
    // 0x806656DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80665110(rdram, ctx);
        goto after_1;
    // 0x806656DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x806656E0: jal         0x80664D40
    // 0x806656E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80664D40(rdram, ctx);
        goto after_2;
    // 0x806656E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806656E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806656EC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x806656F0: beql        $a1, $zero, L_80665744
    if (ctx->r5 == 0) {
        // 0x806656F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80665744;
    }
    goto skip_0;
    // 0x806656F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806656F8: lbu         $t6, 0x7EA5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7EA5);
    // 0x806656FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80665700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80665704: beq         $t6, $at, L_80665740
    if (ctx->r14 == ctx->r1) {
        // 0x80665708: addiu       $t7, $zero, 0x41
        ctx->r15 = ADD32(0, 0X41);
            goto L_80665740;
    }
    // 0x80665708: addiu       $t7, $zero, 0x41
    ctx->r15 = ADD32(0, 0X41);
    // 0x8066570C: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x80665710: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    // 0x80665714: sb          $v0, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r2;
    // 0x80665718: jal         0x8002FE38
    // 0x8066571C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8002FE38(rdram, ctx);
        goto after_3;
    // 0x8066571C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80665720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80665724: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80665728: jal         0x8066622C
    // 0x8066572C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8066622C(rdram, ctx);
        goto after_4;
    // 0x8066572C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_4:
    // 0x80665730: jal         0x80664DB0
    // 0x80665734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80664DB0(rdram, ctx);
        goto after_5;
    // 0x80665734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80665738: jal         0x800677F8
    // 0x8066573C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800677F8(rdram, ctx);
        goto after_6;
    // 0x8066573C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_6:
L_80665740:
    // 0x80665740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80665744:
    // 0x80665744: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80665748: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8066574C: jr          $ra
    // 0x80665750: nop

    return;
    // 0x80665750: nop

;}
RECOMP_FUNC void func_80446C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446C0C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446C10: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446C14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80446C18: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80446C1C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446C20: sw          $t6, 0x6CC8($at)
    MEM_W(0X6CC8, ctx->r1) = ctx->r14;
    // 0x80446C24: addiu       $t7, $zero, 0x3C0
    ctx->r15 = ADD32(0, 0X3C0);
    // 0x80446C28: addiu       $t8, $zero, 0x744
    ctx->r24 = ADD32(0, 0X744);
    // 0x80446C2C: addiu       $t9, $zero, 0xAC8
    ctx->r25 = ADD32(0, 0XAC8);
    // 0x80446C30: sw          $t7, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r15;
    // 0x80446C34: sw          $t8, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r24;
    // 0x80446C38: jr          $ra
    // 0x80446C3C: sw          $t9, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r25;
    return;
    // 0x80446C3C: sw          $t9, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_8064EAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EAC8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8064EACC: beql        $at, $zero, L_8064EAE4
    if (ctx->r1 == 0) {
        // 0x8064EAD0: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8064EAE4;
    }
    goto skip_0;
    // 0x8064EAD0: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x8064EAD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8064EAD8: jr          $ra
    // 0x8064EADC: nop

    return;
    // 0x8064EADC: nop

    // 0x8064EAE0: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_8064EAE4:
    // 0x8064EAE4: beq         $at, $zero, L_8064EB14
    if (ctx->r1 == 0) {
        // 0x8064EAE8: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_8064EB14;
    }
    // 0x8064EAE8: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x8064EAEC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8064EAF0: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8064EAF4: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x8064EAF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8064EAFC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8064EB00: nop

    // 0x8064EB04: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8064EB08: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8064EB0C: jr          $ra
    // 0x8064EB10: div.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    return;
    // 0x8064EB10: div.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
L_8064EB14:
    // 0x8064EB14: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8064EB18: beq         $at, $zero, L_8064EB28
    if (ctx->r1 == 0) {
        // 0x8064EB1C: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_8064EB28;
    }
    // 0x8064EB1C: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8064EB20: jr          $ra
    // 0x8064EB24: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x8064EB24: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
L_8064EB28:
    // 0x8064EB28: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8064EB2C: beq         $at, $zero, L_8064EB60
    if (ctx->r1 == 0) {
        // 0x8064EB30: subu        $t8, $a0, $a3
        ctx->r24 = SUB32(ctx->r4, ctx->r7);
            goto L_8064EB60;
    }
    // 0x8064EB30: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x8064EB34: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8064EB38: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8064EB3C: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x8064EB40: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8064EB44: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8064EB48: nop

    // 0x8064EB4C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8064EB50: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8064EB54: div.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8064EB58: jr          $ra
    // 0x8064EB5C: sub.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f16.fl;
    return;
    // 0x8064EB5C: sub.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f16.fl;
L_8064EB60:
    // 0x8064EB60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8064EB64: nop

    // 0x8064EB68: jr          $ra
    // 0x8064EB6C: nop

    return;
    // 0x8064EB6C: nop

;}
RECOMP_FUNC void func_80735A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735A60: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80735A64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80735A68: addiu       $t7, $t6, -0x4628
    ctx->r15 = ADD32(ctx->r14, -0X4628);
    // 0x80735A6C: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x80735A70: beq         $at, $zero, L_80735AE0
    if (ctx->r1 == 0) {
        // 0x80735A74: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80735AE0;
    }
    // 0x80735A74: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80735A78: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3AF0) << 16);
    // 0x80735A7C: addu        $at, $at, $t7
    gpr jr_addend_80735A84 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80735A80: lw          $t7, -0x6AB0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(736, 0X3AF0));
    // 0x80735A84: jr          $t7
    // 0x80735A88: nop

    switch (jr_addend_80735A84 >> 2) {
        case 0: goto L_80735A8C; break;
        case 1: goto L_80735A98; break;
        case 2: goto L_80735ABC; break;
        case 3: goto L_80735AA4; break;
        case 4: goto L_80735AB0; break;
        case 5: goto L_80735AC8; break;
        case 6: goto L_80735AD4; break;
        default: switch_error(__func__, 0x80735A84, 0x80739550);
    }
    // 0x80735A88: nop

L_80735A8C:
    // 0x80735A8C: lui         $v0, 0x8073
    ctx->r2 = S32(RELOC_HI16(736, 0X254C) << 16);
    // 0x80735A90: jr          $ra
    // 0x80735A94: addiu       $v0, $v0, 0x7FAC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X254C));
    return;
    // 0x80735A94: addiu       $v0, $v0, 0x7FAC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X254C));
L_80735A98:
    // 0x80735A98: lui         $v0, 0x8073
    ctx->r2 = S32(RELOC_HI16(736, 0X268) << 16);
    // 0x80735A9C: jr          $ra
    // 0x80735AA0: addiu       $v0, $v0, 0x5CC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X268));
    return;
    // 0x80735AA0: addiu       $v0, $v0, 0x5CC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X268));
L_80735AA4:
    // 0x80735AA4: lui         $v0, 0x8073
    ctx->r2 = S32(RELOC_HI16(736, 0X1D4) << 16);
    // 0x80735AA8: jr          $ra
    // 0x80735AAC: addiu       $v0, $v0, 0x5C34
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X1D4));
    return;
    // 0x80735AAC: addiu       $v0, $v0, 0x5C34
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X1D4));
L_80735AB0:
    // 0x80735AB0: lui         $v0, 0x8073
    ctx->r2 = S32(RELOC_HI16(736, 0X2FC) << 16);
    // 0x80735AB4: jr          $ra
    // 0x80735AB8: addiu       $v0, $v0, 0x5D5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X2FC));
    return;
    // 0x80735AB8: addiu       $v0, $v0, 0x5D5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X2FC));
L_80735ABC:
    // 0x80735ABC: lui         $v0, 0x8073
    ctx->r2 = S32(RELOC_HI16(736, 0X1218) << 16);
    // 0x80735AC0: jr          $ra
    // 0x80735AC4: addiu       $v0, $v0, 0x6C78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X1218));
    return;
    // 0x80735AC4: addiu       $v0, $v0, 0x6C78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X1218));
L_80735AC8:
    // 0x80735AC8: lui         $v0, 0x8073
    ctx->r2 = S32(RELOC_HI16(736, 0X1320) << 16);
    // 0x80735ACC: jr          $ra
    // 0x80735AD0: addiu       $v0, $v0, 0x6D80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X1320));
    return;
    // 0x80735AD0: addiu       $v0, $v0, 0x6D80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X1320));
L_80735AD4:
    // 0x80735AD4: lui         $v0, 0x8073
    ctx->r2 = S32(RELOC_HI16(736, 0X13B4) << 16);
    // 0x80735AD8: jr          $ra
    // 0x80735ADC: addiu       $v0, $v0, 0x6E14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X13B4));
    return;
    // 0x80735ADC: addiu       $v0, $v0, 0x6E14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X13B4));
L_80735AE0:
    // 0x80735AE0: jr          $ra
    // 0x80735AE4: nop

    return;
    // 0x80735AE4: nop

;}
RECOMP_FUNC void func_8006C9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C9DC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8006C9E0: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8006C9E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C9E8: bne         $a1, $zero, L_8006CA04
    if (ctx->r5 != 0) {
        // 0x8006C9EC: lhu         $v1, 0x64($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X64);
            goto L_8006CA04;
    }
    // 0x8006C9EC: lhu         $v1, 0x64($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X64);
    // 0x8006C9F0: andi        $t6, $v1, 0x4
    ctx->r14 = ctx->r3 & 0X4;
    // 0x8006C9F4: beql        $t6, $zero, L_8006CA10
    if (ctx->r14 == 0) {
        // 0x8006C9F8: lwc1        $f6, 0x5C($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
            goto L_8006CA10;
    }
    goto skip_0;
    // 0x8006C9F8: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    skip_0:
    // 0x8006C9FC: jr          $ra
    // 0x8006CA00: nop

    return;
    // 0x8006CA00: nop

L_8006CA04:
    // 0x8006CA04: bne         $a1, $at, L_8006CA6C
    if (ctx->r5 != ctx->r1) {
        // 0x8006CA08: nop
    
            goto L_8006CA6C;
    }
    // 0x8006CA08: nop

    // 0x8006CA0C: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
L_8006CA10:
    // 0x8006CA10: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8006CA14: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006CA18: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8006CA1C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8006CA20: nop

    // 0x8006CA24: beq         $t9, $a1, L_8006CA6C
    if (ctx->r25 == ctx->r5) {
        // 0x8006CA28: nop
    
            goto L_8006CA6C;
    }
    // 0x8006CA28: nop

    // 0x8006CA2C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8006CA30: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8006CA34: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x8006CA38: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8006CA3C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x8006CA40: nop

    // 0x8006CA44: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006CA48: beql        $at, $zero, L_8006CA5C
    if (ctx->r1 == 0) {
        // 0x8006CA4C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8006CA5C;
    }
    goto skip_1;
    // 0x8006CA4C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    skip_1:
    // 0x8006CA50: b           L_8006CA60
    // 0x8006CA54: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_8006CA60;
    // 0x8006CA54: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8006CA58: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8006CA5C:
    // 0x8006CA5C: andi        $v1, $v1, 0xFFFD
    ctx->r3 = ctx->r3 & 0XFFFD;
L_8006CA60:
    // 0x8006CA60: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x8006CA64: swc1        $f12, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f12.u32l;
    // 0x8006CA68: sh          $v1, 0x64($v0)
    MEM_H(0X64, ctx->r2) = ctx->r3;
L_8006CA6C:
    // 0x8006CA6C: jr          $ra
    // 0x8006CA70: nop

    return;
    // 0x8006CA70: nop

;}
RECOMP_FUNC void func_807BC4D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC4D4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807BC4D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807BC4DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x807BC4E0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807BC4E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807BC4E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807BC4EC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807BC4F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807BC4F4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807BC4F8: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(898, 0X6E28) << 16);
    // 0x807BC4FC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807BC500: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807BC504: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807BC508: lw          $t1, 0x2AE8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(898, 0X6E28));
    // 0x807BC50C: jr          $ra
    // 0x807BC510: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807BC510: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_806CCCE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CCCE4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CCCE8: lui         $t8, 0x806D
    ctx->r24 = S32(RELOC_HI16(604, 0X3B00) << 16);
    // 0x806CCCEC: lui         $t1, 0x806D
    ctx->r9 = S32(RELOC_HI16(604, 0X3AF0) << 16);
    // 0x806CCCF0: sh          $zero, 0x86E($v0)
    MEM_H(0X86E, ctx->r2) = 0;
    // 0x806CCCF4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806CCCF8: lbu         $t9, 0x86D($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X86D);
    // 0x806CCCFC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x806CCD00: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806CCD04: lh          $t8, -0xDE0($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(604, 0X3B00));
    // 0x806CCD08: sb          $t9, 0x86C($v0)
    MEM_B(0X86C, ctx->r2) = ctx->r25;
    // 0x806CCD0C: sh          $t8, 0x870($v0)
    MEM_H(0X870, ctx->r2) = ctx->r24;
    // 0x806CCD10: lbu         $t0, 0x30($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X30);
    // 0x806CCD14: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806CCD18: lbu         $t1, -0xDF0($t1)
    ctx->r9 = MEM_BU(ctx->r9, (int16_t)RELOC_LO16(604, 0X3AF0));
    // 0x806CCD1C: jr          $ra
    // 0x806CCD20: sb          $t1, 0x86D($v0)
    MEM_B(0X86D, ctx->r2) = ctx->r9;
    return;
    // 0x806CCD20: sb          $t1, 0x86D($v0)
    MEM_B(0X86D, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void func_8049F81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F81C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8049F820: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8049F824: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8049F828: beql        $a1, $zero, L_8049F83C
    if (ctx->r5 == 0) {
        // 0x8049F82C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8049F83C;
    }
    goto skip_0;
    // 0x8049F82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8049F830: jal         0x800568E0
    // 0x8049F834: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800568E0(rdram, ctx);
        goto after_0;
    // 0x8049F834: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8049F838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8049F83C:
    // 0x8049F83C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8049F840: jr          $ra
    // 0x8049F844: nop

    return;
    // 0x8049F844: nop

;}
RECOMP_FUNC void func_8003BE44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BE44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BE48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BE4C: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8003BE50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003BE54: bnel        $t6, $at, L_8003BEB8
    if (ctx->r14 != ctx->r1) {
        // 0x8003BE58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003BEB8;
    }
    goto skip_0;
    // 0x8003BE58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8003BE5C: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8003BE60: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8003BE64: beql        $t7, $at, L_8003BEB8
    if (ctx->r15 == ctx->r1) {
        // 0x8003BE68: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003BEB8;
    }
    goto skip_1;
    // 0x8003BE68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8003BE6C: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003BE70: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8003BE74: lbu         $t9, 0x12C9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X12C9);
    // 0x8003BE78: bnel        $t9, $zero, L_8003BEB8
    if (ctx->r25 != 0) {
        // 0x8003BE7C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003BEB8;
    }
    goto skip_2;
    // 0x8003BE7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8003BE80: lw          $t0, 0x7EA8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7EA8);
    // 0x8003BE84: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x8003BE88: andi        $t2, $t1, 0x200F
    ctx->r10 = ctx->r9 & 0X200F;
    // 0x8003BE8C: beql        $t2, $zero, L_8003BEB8
    if (ctx->r10 == 0) {
        // 0x8003BE90: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8003BEB8;
    }
    goto skip_3;
    // 0x8003BE90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8003BE94: jal         0x800403E4
    // 0x8003BE98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800403E4(rdram, ctx);
        goto after_0;
    // 0x8003BE98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003BE9C: beq         $v0, $zero, L_8003BEB4
    if (ctx->r2 == 0) {
        // 0x8003BEA0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8003BEB4;
    }
    // 0x8003BEA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003BEA4: jal         0x8002EF78
    // 0x8003BEA8: nop

    func_8002EF78(rdram, ctx);
        goto after_1;
    // 0x8003BEA8: nop

    after_1:
    // 0x8003BEAC: b           L_8003BEB8
    // 0x8003BEB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003BEB8;
    // 0x8003BEB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003BEB4:
    // 0x8003BEB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003BEB8:
    // 0x8003BEB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BEBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003BEC0: jr          $ra
    // 0x8003BEC4: nop

    return;
    // 0x8003BEC4: nop

;}
RECOMP_FUNC void func_80054614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054614: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005461C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80054620: jal         0x80064D1C
    // 0x80054624: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x80054624: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_0:
    // 0x80054628: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8005462C: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80054630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80054638: jr          $ra
    // 0x8005463C: nop

    return;
    // 0x8005463C: nop

;}
RECOMP_FUNC void func_806CEAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CEAE4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806CEAE8: lui         $t6, 0x806D
    ctx->r14 = S32(RELOC_HI16(604, 0X303C) << 16);
    // 0x806CEAEC: addiu       $t6, $t6, -0x18A4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(604, 0X303C));
    // 0x806CEAF0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806CEAF4: jr          $ra
    // 0x806CEAF8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806CEAF8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8073F070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073F074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073F078: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8073F07C: jal         0x80047090
    // 0x8073F080: addiu       $a0, $zero, 0x4644
    ctx->r4 = ADD32(0, 0X4644);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8073F080: addiu       $a0, $zero, 0x4644
    ctx->r4 = ADD32(0, 0X4644);
    after_0:
    // 0x8073F084: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073F088: lui         $at, 0x4644
    ctx->r1 = S32(0X4644 << 16);
    // 0x8073F08C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8073F090: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8073F094: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8073F098: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8073F09C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8073F0A0: jal         0x8004613C
    // 0x8073F0A4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8073F0A4: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x8073F0A8: bne         $v0, $zero, L_8073F0B8
    if (ctx->r2 != 0) {
        // 0x8073F0AC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8073F0B8;
    }
    // 0x8073F0AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8073F0B0: b           L_8073F0E8
    // 0x8073F0B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073F0E8;
    // 0x8073F0B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073F0B8:
    // 0x8073F0B8: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x8073F0BC: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x8073F0C0: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8073F0C4: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x8073F0C8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8073F0CC: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x8073F0D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8073F0D4: jal         0x80047F9C
    // 0x8073F0D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8073F0D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8073F0DC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8073F0E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8073F0E4: sb          $t2, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = ctx->r10;
L_8073F0E8:
    // 0x8073F0E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073F0EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073F0F0: jr          $ra
    // 0x8073F0F4: nop

    return;
    // 0x8073F0F4: nop

;}
RECOMP_FUNC void func_80430198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430198: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043019C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804301A0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BD4) << 16);
    // 0x804301A4: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x804301A8: lwc1        $f8, 0x1CB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BD4));
    // 0x804301AC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804301B0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804301B4: jr          $ra
    // 0x804301B8: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x804301B8: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80515868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80515868: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(276, 0X113C) << 16);
    // 0x8051586C: lw          $v0, 0x65DC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(276, 0X113C));
    // 0x80515870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80515874: addiu       $at, $zero, -0x9A
    ctx->r1 = ADD32(0, -0X9A);
    // 0x80515878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051587C: beq         $v0, $at, L_80515898
    if (ctx->r2 == ctx->r1) {
        // 0x80515880: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80515898;
    }
    // 0x80515880: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80515884: addiu       $at, $zero, -0x7D
    ctx->r1 = ADD32(0, -0X7D);
    // 0x80515888: bnel        $v0, $at, L_805158A8
    if (ctx->r2 != ctx->r1) {
        // 0x8051588C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805158A8;
    }
    goto skip_0;
    // 0x8051588C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80515890: b           L_8051589C
    // 0x80515894: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
        goto L_8051589C;
    // 0x80515894: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
L_80515898:
    // 0x80515898: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
L_8051589C:
    // 0x8051589C: jal         0x80067878
    // 0x805158A0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x805158A0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    after_0:
    // 0x805158A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805158A8:
    // 0x805158A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805158AC: jr          $ra
    // 0x805158B0: nop

    return;
    // 0x805158B0: nop

;}
RECOMP_FUNC void func_805802D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805802D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805802DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805802E0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805802E4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x805802E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805802EC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x805802F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805802F4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x805802F8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805802FC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80580300: lui         $t2, 0x8058
    ctx->r10 = S32(RELOC_HI16(399, 0X44D8) << 16);
    // 0x80580304: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80580308: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8058030C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80580310: lw          $t2, 0x32E8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(399, 0X44D8));
    // 0x80580314: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80580318: jal         0x8057F770
    // 0x8058031C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_8057F770(rdram, ctx);
        goto after_0;
    // 0x8058031C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x80580320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580328: jr          $ra
    // 0x8058032C: nop

    return;
    // 0x8058032C: nop

;}
RECOMP_FUNC void func_8002D208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D208: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002D20C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D210: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D214: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D218: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D21C: jal         0x8002D1CC
    // 0x8002D220: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8002D1CC(rdram, ctx);
        goto after_0;
    // 0x8002D220: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002D224: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    // 0x8002D228: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002D22C: lui         $t0, 0x8003
    ctx->r8 = S32(0X8003 << 16);
    // 0x8002D230: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8002D234: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8002D238: addiu       $t9, $zero, 0x11
    ctx->r25 = ADD32(0, 0X11);
    // 0x8002D23C: addiu       $t0, $t0, 0x33C
    ctx->r8 = ADD32(ctx->r8, 0X33C);
    // 0x8002D240: sb          $t8, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r24;
    // 0x8002D244: sb          $t9, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r25;
    // 0x8002D248: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
    // 0x8002D24C: jal         0x8002301C
    // 0x8002D250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002301C(rdram, ctx);
        goto after_1;
    // 0x8002D250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002D254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002D258: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002D25C: addiu       $a1, $a1, -0x2CFC
    ctx->r5 = ADD32(ctx->r5, -0X2CFC);
    // 0x8002D260: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002D264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002D268: jal         0x80028118
    // 0x8002D26C: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    func_80028118(rdram, ctx);
        goto after_2;
    // 0x8002D26C: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8002D270: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8002D274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D278: jal         0x80067838
    // 0x8002D27C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x8002D27C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8002D280: jal         0x8001D770
    // 0x8002D284: nop

    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x8002D284: nop

    after_4:
    // 0x8002D288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002D28C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002D290: jal         0x80067BF8
    // 0x8002D294: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_5;
    // 0x8002D294: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8002D298: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    // 0x8002D29C: jal         0x80067818
    // 0x8002D2A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8002D2A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8002D2A4: jal         0x800677F8
    // 0x8002D2A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800677F8(rdram, ctx);
        goto after_7;
    // 0x8002D2A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x8002D2AC: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x8002D2B0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002D2B4: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x8002D2B8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002D2BC: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8002D2C0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8002D2C4: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x8002D2C8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002D2CC: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x8002D2D0: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
    // 0x8002D2D4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8002D2D8: sw          $t4, 0xD8($t5)
    MEM_W(0XD8, ctx->r13) = ctx->r12;
    // 0x8002D2DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D2E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D2E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002D2E8: jr          $ra
    // 0x8002D2EC: nop

    return;
    // 0x8002D2EC: nop

;}
RECOMP_FUNC void func_806CB9B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CB9B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x806CB9BC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x806CB9C0: lui         $t0, 0x806D
    ctx->r8 = S32(RELOC_HI16(604, 0X3A58) << 16);
    // 0x806CB9C4: addiu       $t0, $t0, -0xE88
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(604, 0X3A58));
    // 0x806CB9C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x806CB9CC: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x806CB9D0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x806CB9D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806CB9D8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806CB9DC: addu        $t1, $v0, $a3
    ctx->r9 = ADD32(ctx->r2, ctx->r7);
    // 0x806CB9E0: lb          $t2, 0x0($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X0);
    // 0x806CB9E4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x806CB9E8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x806CB9EC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x806CB9F0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x806CB9F4: addiu       $t3, $zero, 0x3E8
    ctx->r11 = ADD32(0, 0X3E8);
    // 0x806CB9F8: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x806CB9FC: subu        $t4, $t3, $a2
    ctx->r12 = SUB32(ctx->r11, ctx->r6);
    // 0x806CBA00: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x806CBA04: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x806CBA08: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x806CBA0C: addu        $t5, $v1, $a3
    ctx->r13 = ADD32(ctx->r3, ctx->r7);
    // 0x806CBA10: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806CBA14: lb          $t6, 0x0($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X0);
    // 0x806CBA18: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x806CBA1C: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x806CBA20: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x806CBA24: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CBA28: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C08) << 16);
    // 0x806CBA2C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806CBA30: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x806CBA34: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806CBA38: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806CBA3C: beq         $t7, $zero, L_806CBA58
    if (ctx->r15 == 0) {
        // 0x806CBA40: add.s       $f2, $f16, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f10.fl;
            goto L_806CBA58;
    }
    // 0x806CBA40: add.s       $f2, $f16, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x806CBA44: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C04) << 16);
    // 0x806CBA48: lwc1        $f18, -0xCDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C04));
    // 0x806CBA4C: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x806CBA50: jr          $ra
    // 0x806CBA54: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x806CBA54: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_806CBA58:
    // 0x806CBA58: lwc1        $f8, -0xCD8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C08));
    // 0x806CBA5C: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x806CBA60: nop

    // 0x806CBA64: jr          $ra
    // 0x806CBA68: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x806CBA68: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_8005B238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B238: andi        $a3, $a1, 0xFF
    ctx->r7 = ctx->r5 & 0XFF;
    // 0x8005B23C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8005B240: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8005B244: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8005B248: lw          $t9, 0x616C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X616C);
    // 0x8005B24C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B254: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005B258: jalr        $t9
    // 0x8005B25C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8005B25C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8005B260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B268: jr          $ra
    // 0x8005B26C: nop

    return;
    // 0x8005B26C: nop

;}
RECOMP_FUNC void func_804BB4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BB4C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BB4C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x804BB4CC: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x804BB4D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BB4D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB4D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804BB4DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804BB4E0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804BB4E4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804BB4E8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804BB4EC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x804BB4F0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804BB4F4: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(188, 0XB18) << 16);
    // 0x804BB4F8: sb          $a3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r7;
    // 0x804BB4FC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804BB500: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804BB504: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804BB508: lw          $t1, -0x4988($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(188, 0XB18));
    // 0x804BB50C: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x804BB510: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x804BB514: jal         0x804BB534
    // 0x804BB518: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804BB534(rdram, ctx);
        goto after_0;
    // 0x804BB518: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BB51C: jal         0x804BB598
    // 0x804BB520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804BB598(rdram, ctx);
        goto after_1;
    // 0x804BB520: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804BB524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BB528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BB52C: jr          $ra
    // 0x804BB530: nop

    return;
    // 0x804BB530: nop

;}
RECOMP_FUNC void func_80699028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699028: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8069902C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80699030: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80699034: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80699038: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069903C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80699040: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80699044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80699048: jal         0x80048F84
    // 0x8069904C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8069904C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80699050: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80699054: jal         0x80048F84
    // 0x80699058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80699058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8069905C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80699060: jal         0x80698F2C
    // 0x80699064: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    func_80698F2C(rdram, ctx);
        goto after_2;
    // 0x80699064: lw          $a1, 0x1F4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1F4);
    after_2:
    // 0x80699068: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8069906C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80699070: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x80699074: lbu         $t0, 0x2C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2C);
    // 0x80699078: beql        $t0, $zero, L_806990CC
    if (ctx->r8 == 0) {
        // 0x8069907C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806990CC;
    }
    goto skip_0;
    // 0x8069907C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80699080: jal         0x8004700C
    // 0x80699084: nop

    func_8004700C(rdram, ctx);
        goto after_3;
    // 0x80699084: nop

    after_3:
    // 0x80699088: beq         $v0, $zero, L_806990B8
    if (ctx->r2 == 0) {
        // 0x8069908C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806990B8;
    }
    // 0x8069908C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80699090: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80699094: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80699098: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8069909C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806990A0: nop

    // 0x806990A4: bc1fl       L_806990B8
    if (!c1cs) {
        // 0x806990A8: sw          $zero, 0x138($s0)
        MEM_W(0X138, ctx->r16) = 0;
            goto L_806990B8;
    }
    goto skip_1;
    // 0x806990A8: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    skip_1:
    // 0x806990AC: b           L_806990B8
    // 0x806990B0: sw          $t1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r9;
        goto L_806990B8;
    // 0x806990B0: sw          $t1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r9;
    // 0x806990B4: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
L_806990B8:
    // 0x806990B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806990BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806990C0: jal         0x80699250
    // 0x806990C4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80699250(rdram, ctx);
        goto after_4;
    // 0x806990C4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x806990C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806990CC:
    // 0x806990CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806990D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806990D4: jr          $ra
    // 0x806990D8: nop

    return;
    // 0x806990D8: nop

;}
RECOMP_FUNC void func_805580E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805580E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805580EC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x805580F0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x805580F4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x805580F8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x805580FC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80558100: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80558104: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80558108: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8055810C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80558110: lw          $s7, 0x174($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X174);
    // 0x80558114: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80558118: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8055811C: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80558120: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80558124: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x80558128: jal         0x80049D74
    // 0x8055812C: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x8055812C: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    after_0:
    // 0x80558130: beq         $s0, $zero, L_805581B4
    if (ctx->r16 == 0) {
        // 0x80558134: sll         $s1, $s0, 2
        ctx->r17 = S32(ctx->r16 << 2);
            goto L_805581B4;
    }
    // 0x80558134: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x80558138: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8055813C: lui         $s5, 0x8056
    ctx->r21 = S32(RELOC_HI16(363, 0X1E90) << 16);
    // 0x80558140: addiu       $s5, $s5, -0x6620
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(363, 0X1E90));
    // 0x80558144: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x80558148: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
    // 0x8055814C: addiu       $s3, $zero, 0x38
    ctx->r19 = ADD32(0, 0X38);
    // 0x80558150: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x80558154: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
L_80558158:
    // 0x80558158: addiu       $s1, $s1, -0x18
    ctx->r17 = ADD32(ctx->r17, -0X18);
    // 0x8055815C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80558160: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80558164: addu        $v0, $t8, $s1
    ctx->r2 = ADD32(ctx->r24, ctx->r17);
    // 0x80558168: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8055816C: beq         $v1, $zero, L_805581AC
    if (ctx->r3 == 0) {
        // 0x80558170: nop
    
            goto L_805581AC;
    }
    // 0x80558170: nop

    // 0x80558174: beq         $s2, $v1, L_805581AC
    if (ctx->r18 == ctx->r3) {
        // 0x80558178: nop
    
            goto L_805581AC;
    }
    // 0x80558178: nop

    // 0x8055817C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80558180: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x80558184: beq         $s3, $v1, L_805581AC
    if (ctx->r19 == ctx->r3) {
        // 0x80558188: nop
    
            goto L_805581AC;
    }
    // 0x80558188: nop

    // 0x8055818C: beq         $s4, $v1, L_805581AC
    if (ctx->r20 == ctx->r3) {
        // 0x80558190: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_805581AC;
    }
    // 0x80558190: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80558194: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x80558198: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8055819C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x805581A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805581A4: jalr        $t9
    // 0x805581A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x805581A8: nop

    after_1:
L_805581AC:
    // 0x805581AC: bnel        $s0, $zero, L_80558158
    if (ctx->r16 != 0) {
        // 0x805581B0: lw          $t7, 0x0($s7)
        ctx->r15 = MEM_W(ctx->r23, 0X0);
            goto L_80558158;
    }
    goto skip_0;
    // 0x805581B0: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    skip_0:
L_805581B4:
    // 0x805581B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x805581B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805581BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805581C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x805581C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x805581C8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x805581CC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x805581D0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x805581D4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x805581D8: jr          $ra
    // 0x805581DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x805581DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80580794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8058079C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805807A0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805807A4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805807A8: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(399, 0X4584) << 16);
    // 0x805807AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805807B0: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805807B4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805807B8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805807BC: lw          $t8, 0x3394($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(399, 0X4584));
    // 0x805807C0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805807C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805807C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805807CC: jal         0x80048490
    // 0x805807D0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805807D0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805807D4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805807D8: jal         0x80048378
    // 0x805807DC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x805807DC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x805807E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805807E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805807E8: jr          $ra
    // 0x805807EC: nop

    return;
    // 0x805807EC: nop

;}
RECOMP_FUNC void func_80467E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80467E20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80467E24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80467E28: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80467E2C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80467E30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80467E34: jal         0x80467610
    // 0x80467E38: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80467610(rdram, ctx);
        goto after_0;
    // 0x80467E38: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80467E3C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80467E40: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80467E44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80467E48: lh          $a0, 0x18($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X18);
    // 0x80467E4C: lh          $a1, 0x1A($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X1A);
    // 0x80467E50: lw          $t7, 0x1FA0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1FA0);
    // 0x80467E54: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80467E58: multu       $a1, $a0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467E5C: mflo        $t6
    ctx->r14 = lo;
    // 0x80467E60: nop

    // 0x80467E64: nop

    // 0x80467E68: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80467E6C: mflo        $t8
    ctx->r24 = lo;
    // 0x80467E70: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x80467E74: jal         0x80055A68
    // 0x80467E78: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    func_80055A68(rdram, ctx);
        goto after_1;
    // 0x80467E78: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_1:
    // 0x80467E7C: jal         0x80467D9C
    // 0x80467E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80467D9C(rdram, ctx);
        goto after_2;
    // 0x80467E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80467E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80467E88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80467E8C: jal         0x804686B4
    // 0x80467E90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_804686B4(rdram, ctx);
        goto after_3;
    // 0x80467E90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x80467E94: jal         0x80466950
    // 0x80467E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80466950(rdram, ctx);
        goto after_4;
    // 0x80467E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80467E9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80467EA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80467EA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80467EA8: jr          $ra
    // 0x80467EAC: nop

    return;
    // 0x80467EAC: nop

;}
RECOMP_FUNC void func_80531090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531090: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80531094: lw          $t6, 0x168($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X168);
    // 0x80531098: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8053109C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x805310A0: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x805310A4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805310A8: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x805310AC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805310B0: sll         $t8, $t8, 7
    ctx->r24 = S32(ctx->r24 << 7);
    // 0x805310B4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805310B8: lui         $t3, 0xFD50
    ctx->r11 = S32(0XFD50 << 16);
    // 0x805310BC: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x805310C0: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x805310C4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x805310C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805310CC: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x805310D0: lui         $t5, 0xF550
    ctx->r13 = S32(0XF550 << 16);
    // 0x805310D4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x805310D8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x805310DC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805310E0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x805310E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805310E8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x805310EC: lui         $t4, 0x713
    ctx->r12 = S32(0X713 << 16);
    // 0x805310F0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805310F4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x805310F8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805310FC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80531100: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80531104: ori         $t4, $t4, 0xF19A
    ctx->r12 = ctx->r12 | 0XF19A;
    // 0x80531108: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8053110C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80531110: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80531114: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80531118: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8053111C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80531120: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80531124: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x80531128: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8053112C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80531130: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80531134: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80531138: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8053113C: ori         $t8, $t8, 0xA00
    ctx->r24 = ctx->r24 | 0XA00;
    // 0x80531140: lui         $t4, 0x9
    ctx->r12 = S32(0X9 << 16);
    // 0x80531144: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80531148: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8053114C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80531150: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80531154: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80531158: ori         $t4, $t4, 0xC03C
    ctx->r12 = ctx->r12 | 0XC03C;
    // 0x8053115C: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x80531160: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80531164: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80531168: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8053116C: jr          $ra
    // 0x80531170: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    return;
    // 0x80531170: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_804CF440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF440: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CF444: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CF448: jr          $ra
    // 0x804CF44C: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x804CF44C: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_805336B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805336B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805336B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805336BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805336C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805336C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805336C8: jal         0x800692D4
    // 0x805336CC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_800692D4(rdram, ctx);
        goto after_0;
    // 0x805336CC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805336D0: jal         0x80532CFC
    // 0x805336D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80532CFC(rdram, ctx);
        goto after_1;
    // 0x805336D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x805336D8: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x805336DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805336E0: nop

    // 0x805336E4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x805336E8: nop

    // 0x805336EC: bc1f        L_80533768
    if (!c1cs) {
        // 0x805336F0: nop
    
            goto L_80533768;
    }
    // 0x805336F0: nop

    // 0x805336F4: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x805336F8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x805336FC: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x80533700: jal         0x80066DE4
    // 0x80533704: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x80533704: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    after_2:
    // 0x80533708: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8053370C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80533710: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80533714: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80533718: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8053371C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80533720: jal         0x80066E88
    // 0x80533724: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x80533724: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    after_3:
    // 0x80533728: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8053372C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80533730: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80533734: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80533738: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8053373C: addiu       $v0, $s1, 0xC4
    ctx->r2 = ADD32(ctx->r17, 0XC4);
    // 0x80533740: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80533744: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80533748: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8053374C: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80533750: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80533754: lwc1        $f16, 0x40($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80533758: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8053375C: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80533760: b           L_80533770
    // 0x80533764: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
        goto L_80533770;
    // 0x80533764: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
L_80533768:
    // 0x80533768: jal         0x80533444
    // 0x8053376C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80533444(rdram, ctx);
        goto after_4;
    // 0x8053376C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_80533770:
    // 0x80533770: jal         0x80533170
    // 0x80533774: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80533170(rdram, ctx);
        goto after_5;
    // 0x80533774: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80533778: jal         0x80532B50
    // 0x8053377C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80532B50(rdram, ctx);
        goto after_6;
    // 0x8053377C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80533780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80533784: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80533788: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8053378C: jr          $ra
    // 0x80533790: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80533790: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806EAF14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EAF14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806EAF18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806EAF1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806EAF20: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EAF24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EAF28: jal         0x8004700C
    // 0x806EAF2C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806EAF2C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x806EAF30: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x806EAF34: jal         0x806EA9C0
    // 0x806EAF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EA9C0(rdram, ctx);
        goto after_1;
    // 0x806EAF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EAF3C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x806EAF40: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x806EAF44: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806EAF48: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x806EAF4C: bne         $at, $zero, L_806EB048
    if (ctx->r1 != 0) {
        // 0x806EAF50: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_806EB048;
    }
    // 0x806EAF50: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x806EAF54: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x806EAF58: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x806EAF5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EAF60: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x806EAF64: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x806EAF68: bne         $at, $zero, L_806EB034
    if (ctx->r1 != 0) {
        // 0x806EAF6C: sw          $t0, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r8;
            goto L_806EB034;
    }
    // 0x806EAF6C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x806EAF70: jal         0x806EAAC8
    // 0x806EAF74: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_806EAAC8(rdram, ctx);
        goto after_2;
    // 0x806EAF74: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_2:
    // 0x806EAF78: beq         $v0, $zero, L_806EB014
    if (ctx->r2 == 0) {
        // 0x806EAF7C: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_806EB014;
    }
    // 0x806EAF7C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x806EAF80: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x806EAF84: beql        $a0, $zero, L_806EAFFC
    if (ctx->r4 == 0) {
        // 0x806EAF88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EAFFC;
    }
    goto skip_0;
    // 0x806EAF88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x806EAF8C: jal         0x806EAA74
    // 0x806EAF90: nop

    func_806EAA74(rdram, ctx);
        goto after_3;
    // 0x806EAF90: nop

    after_3:
    // 0x806EAF94: beq         $v0, $zero, L_806EAFF8
    if (ctx->r2 == 0) {
        // 0x806EAF98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EAFF8;
    }
    // 0x806EAF98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EAF9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EAFA0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EAFA4: jal         0x806EB43C
    // 0x806EAFA8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EB43C(rdram, ctx);
        goto after_4;
    // 0x806EAFA8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806EAFAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806EAFB0: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x806EAFB4: lw          $t2, -0x76F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X76F8);
    // 0x806EAFB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x806EAFBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x806EAFC0: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x806EAFC4: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x806EAFC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806EAFCC: lw          $t9, 0x40($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X40);
    // 0x806EAFD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EAFD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806EAFD8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x806EAFDC: jalr        $t9
    // 0x806EAFE0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x806EAFE0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_5:
    // 0x806EAFE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EAFE8: jal         0x806EA988
    // 0x806EAFEC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_806EA988(rdram, ctx);
        goto after_6;
    // 0x806EAFEC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_6:
    // 0x806EAFF0: b           L_806EB04C
    // 0x806EAFF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806EB04C;
    // 0x806EAFF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806EAFF8:
    // 0x806EAFF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806EAFFC:
    // 0x806EAFFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EB000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806EB004: jal         0x806EB43C
    // 0x806EB008: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EB43C(rdram, ctx);
        goto after_7;
    // 0x806EB008: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x806EB00C: b           L_806EB04C
    // 0x806EB010: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806EB04C;
    // 0x806EB010: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806EB014:
    // 0x806EB014: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x806EB018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EB01C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EB020: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x806EB024: bne         $at, $zero, L_806EB034
    if (ctx->r1 != 0) {
        // 0x806EB028: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_806EB034;
    }
    // 0x806EB028: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806EB02C: jal         0x806EB43C
    // 0x806EB030: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EB43C(rdram, ctx);
        goto after_8;
    // 0x806EB030: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_8:
L_806EB034:
    // 0x806EB034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EB038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EB03C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806EB040: jal         0x806EB43C
    // 0x806EB044: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EB43C(rdram, ctx);
        goto after_9;
    // 0x806EB044: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_9:
L_806EB048:
    // 0x806EB048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806EB04C:
    // 0x806EB04C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806EB050: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x806EB054: jr          $ra
    // 0x806EB058: nop

    return;
    // 0x806EB058: nop

;}
RECOMP_FUNC void func_80463B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80463B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80463B24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80463B28: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80463B2C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80463B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80463B34: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80463B38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80463B3C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80463B40: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80463B44: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80463B48: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(122, 0X39B8) << 16);
    // 0x80463B4C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80463B50: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80463B54: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80463B58: lw          $t2, 0x3F48($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(122, 0X39B8));
    // 0x80463B5C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80463B60: jal         0x804632B8
    // 0x80463B64: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804632B8(rdram, ctx);
        goto after_0;
    // 0x80463B64: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x80463B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80463B6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80463B70: jr          $ra
    // 0x80463B74: nop

    return;
    // 0x80463B74: nop

    // 0x80463B78: nop

    // 0x80463B7C: nop

;}
RECOMP_FUNC void func_80566CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80566CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566CC8: jal         0x80566674
    // 0x80566CCC: nop

    func_80566674(rdram, ctx);
        goto after_0;
    // 0x80566CCC: nop

    after_0:
    // 0x80566CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566CD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80566CD8: jr          $ra
    // 0x80566CDC: nop

    return;
    // 0x80566CDC: nop

;}
RECOMP_FUNC void func_8046790C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046790C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80467910: lw          $a2, 0x2880($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X2880);
    // 0x80467914: lw          $a3, 0x2410($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X2410);
    // 0x80467918: addiu       $v1, $v0, 0x2884
    ctx->r3 = ADD32(ctx->r2, 0X2884);
    // 0x8046791C: addiu       $a1, $v0, 0x2A78
    ctx->r5 = ADD32(ctx->r2, 0X2A78);
    // 0x80467920: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80467924: beql        $at, $zero, L_80467A20
    if (ctx->r1 == 0) {
        // 0x80467928: mtc1        $a3, $f6
        ctx->f6.u32l = ctx->r7;
            goto L_80467A20;
    }
    goto skip_0;
    // 0x80467928: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    skip_0:
    // 0x8046792C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80467930: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80467934: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80467938: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8046793C: sw          $a3, 0x2C6C($v0)
    MEM_W(0X2C6C, ctx->r2) = ctx->r7;
    // 0x80467940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80467944: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80467948: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8046794C: blez        $a3, L_80467B04
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80467950: div.s       $f0, $f6, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
            goto L_80467B04;
    }
    // 0x80467950: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80467954: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80467958: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8046795C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80467960: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80467964: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
L_80467968:
    // 0x80467968: lbu         $t8, 0x1FA4($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X1FA4);
    // 0x8046796C: lwc1        $f12, 0x2CF4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X2CF4);
    // 0x80467970: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80467974: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80467978: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8046797C: sub.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80467980: addu        $a2, $v0, $t7
    ctx->r6 = ADD32(ctx->r2, ctx->r15);
    // 0x80467984: lbu         $t9, 0x2414($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X2414);
    // 0x80467988: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8046798C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80467990: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80467994: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80467998: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8046799C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x804679A0: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x804679A4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804679A8: add.s       $f18, $f14, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x804679AC: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x804679B0: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x804679B4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804679B8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x804679BC: nop

    // 0x804679C0: sb          $t1, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r9;
    // 0x804679C4: lbu         $t2, 0x2197($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X2197);
    // 0x804679C8: lwc1        $f12, 0x2CF4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X2CF4);
    // 0x804679CC: lbu         $t3, 0x2608($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X2608);
    // 0x804679D0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x804679D4: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x804679D8: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804679DC: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x804679E0: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x804679E4: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804679E8: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x804679EC: mul.s       $f18, $f6, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x804679F0: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804679F4: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804679F8: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x804679FC: nop

    // 0x80467A00: sb          $t5, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r13;
    // 0x80467A04: lw          $t6, 0x2C6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C6C);
    // 0x80467A08: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80467A0C: bnel        $at, $zero, L_80467968
    if (ctx->r1 != 0) {
        // 0x80467A10: trunc.w.s   $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80467968;
    }
    goto skip_1;
    // 0x80467A10: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_1:
    // 0x80467A14: jr          $ra
    // 0x80467A18: nop

    return;
    // 0x80467A18: nop

    // 0x80467A1C: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
L_80467A20:
    // 0x80467A20: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80467A24: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80467A28: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80467A2C: sw          $a2, 0x2C6C($v0)
    MEM_W(0X2C6C, ctx->r2) = ctx->r6;
    // 0x80467A30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80467A34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80467A38: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80467A3C: blez        $a2, L_80467B04
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80467A40: div.s       $f0, $f18, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
            goto L_80467B04;
    }
    // 0x80467A40: div.s       $f0, $f18, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80467A44: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80467A48: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80467A4C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80467A50: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80467A54: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
L_80467A58:
    // 0x80467A58: lwc1        $f12, 0x2CF4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X2CF4);
    // 0x80467A5C: lbu         $t0, 0x2414($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X2414);
    // 0x80467A60: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80467A64: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80467A68: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80467A6C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80467A70: addu        $a2, $v0, $t8
    ctx->r6 = ADD32(ctx->r2, ctx->r24);
    // 0x80467A74: lbu         $t9, 0x1FA4($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1FA4);
    // 0x80467A78: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80467A7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80467A80: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80467A84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80467A88: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80467A8C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80467A90: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80467A94: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80467A98: add.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80467A9C: mul.s       $f18, $f4, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80467AA0: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80467AA4: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80467AA8: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80467AAC: nop

    // 0x80467AB0: sb          $t2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r10;
    // 0x80467AB4: lbu         $t3, 0x2198($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X2198);
    // 0x80467AB8: lwc1        $f12, 0x2CF4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X2CF4);
    // 0x80467ABC: lbu         $t4, 0x2607($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X2607);
    // 0x80467AC0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80467AC4: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80467AC8: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80467ACC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80467AD0: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80467AD4: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80467AD8: add.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80467ADC: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80467AE0: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80467AE4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80467AE8: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80467AEC: nop

    // 0x80467AF0: sb          $t6, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r14;
    // 0x80467AF4: lw          $t7, 0x2C6C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C6C);
    // 0x80467AF8: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80467AFC: bnel        $at, $zero, L_80467A58
    if (ctx->r1 != 0) {
        // 0x80467B00: trunc.w.s   $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_80467A58;
    }
    goto skip_2;
    // 0x80467B00: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_2:
L_80467B04:
    // 0x80467B04: jr          $ra
    // 0x80467B08: nop

    return;
    // 0x80467B08: nop

;}
RECOMP_FUNC void func_805565EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805565EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805565F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805565F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805565F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805565FC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80556600: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80556604: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80556608: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8055660C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80556610: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80556614: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80556618: jal         0x805563A0
    // 0x8055661C: nop

    func_805563A0(rdram, ctx);
        goto after_0;
    // 0x8055661C: nop

    after_0:
    // 0x80556620: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80556624: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80556628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8055662C: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80556630: nop

    // 0x80556634: bc1f        L_80556650
    if (!c1cs) {
        // 0x80556638: nop
    
            goto L_80556650;
    }
    // 0x80556638: nop

    // 0x8055663C: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80556640: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80556644: nop

    // 0x80556648: bc1tl       L_8055665C
    if (c1cs) {
        // 0x8055664C: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8055665C;
    }
    goto skip_0;
    // 0x8055664C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
L_80556650:
    // 0x80556650: jal         0x805564FC
    // 0x80556654: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_805564FC(rdram, ctx);
        goto after_1;
    // 0x80556654: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80556658: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_8055665C:
    // 0x8055665C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80556660: jal         0x80048F84
    // 0x80556664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x80556664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80556668: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8055666C: jal         0x80048F84
    // 0x80556670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x80556670: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80556674: jal         0x800653D8
    // 0x80556678: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x80556678: nop

    after_4:
    // 0x8055667C: andi        $t6, $v0, 0x1F
    ctx->r14 = ctx->r2 & 0X1F;
    // 0x80556680: bnel        $t6, $zero, L_805566E4
    if (ctx->r14 != 0) {
        // 0x80556684: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805566E4;
    }
    goto skip_1;
    // 0x80556684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80556688: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8055668C: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19F4) << 16);
    // 0x80556690: lwc1        $f8, 0x68E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(357, 0X19F4));
    // 0x80556694: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x80556698: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8055669C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x805566A0: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x805566A4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x805566A8: jal         0x800653D8
    // 0x805566AC: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x805566AC: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x805566B0: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x805566B4: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x805566B8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805566BC: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x805566C0: mfhi        $a2
    ctx->r6 = hi;
    // 0x805566C4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x805566C8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x805566CC: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    // 0x805566D0: addiu       $a3, $zero, 0x45E9
    ctx->r7 = ADD32(0, 0X45E9);
    // 0x805566D4: lw          $t9, 0x44($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X44);
    // 0x805566D8: jalr        $t9
    // 0x805566DC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x805566DC: nop

    after_6:
    // 0x805566E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_805566E4:
    // 0x805566E4: jal         0x80554F80
    // 0x805566E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80554F80(rdram, ctx);
        goto after_7;
    // 0x805566E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x805566EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805566F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805566F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805566F8: jr          $ra
    // 0x805566FC: nop

    return;
    // 0x805566FC: nop

;}
RECOMP_FUNC void func_80026CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026CDC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026CE0: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80026CE4: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80026CE8: lw          $t6, 0x9C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X9C);
    // 0x80026CEC: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x80026CF0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80026CF4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80026CF8: lw          $t7, 0xA0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XA0);
    // 0x80026CFC: addiu       $t9, $t9, 0x6C84
    ctx->r25 = ADD32(ctx->r25, 0X6C84);
    // 0x80026D00: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80026D04: sb          $t8, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r24;
    // 0x80026D08: jr          $ra
    // 0x80026D0C: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
    return;
    // 0x80026D0C: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_8042F9F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F9F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042F9F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042F9F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042F9FC: jal         0x8004700C
    // 0x8042FA00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8042FA00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8042FA04: beql        $v0, $zero, L_8042FA8C
    if (ctx->r2 == 0) {
        // 0x8042FA08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8042FA8C;
    }
    goto skip_0;
    // 0x8042FA08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8042FA0C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042FA10: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8042FA14: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042FA18: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8042FA1C: lwc1        $f2, 0x3C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8042FA20: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8042FA24: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8042FA28: nop

    // 0x8042FA2C: bc1fl       L_8042FA8C
    if (!c1cs) {
        // 0x8042FA30: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8042FA8C;
    }
    goto skip_1;
    // 0x8042FA30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8042FA34: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8042FA38: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8042FA3C: nop

    // 0x8042FA40: bc1fl       L_8042FA8C
    if (!c1cs) {
        // 0x8042FA44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8042FA8C;
    }
    goto skip_2;
    // 0x8042FA44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8042FA48: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x8042FA4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8042FA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042FA54: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8042FA58: jal         0x8005FCA8
    // 0x8042FA5C: sh          $t7, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r15;
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x8042FA5C: sh          $t7, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r15;
    after_1:
    // 0x8042FA60: jal         0x8042F9D8
    // 0x8042FA64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042F9D8(rdram, ctx);
        goto after_2;
    // 0x8042FA64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8042FA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042FA6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042FA70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042FA74: jal         0x804303F0
    // 0x8042FA78: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804303F0(rdram, ctx);
        goto after_3;
    // 0x8042FA78: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x8042FA7C: lui         $t0, 0x8043
    ctx->r8 = S32(RELOC_HI16(56, 0X18C8) << 16);
    // 0x8042FA80: addiu       $t0, $t0, -0x658
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(56, 0X18C8));
    // 0x8042FA84: sw          $t0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r8;
    // 0x8042FA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042FA8C:
    // 0x8042FA8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042FA90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042FA94: jr          $ra
    // 0x8042FA98: nop

    return;
    // 0x8042FA98: nop

;}
RECOMP_FUNC void func_80026EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026EE8: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80026EEC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80026EF0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80026EF4: addiu       $t8, $t8, 0x6E44
    ctx->r24 = ADD32(ctx->r24, 0X6E44);
    // 0x80026EF8: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80026EFC: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
    // 0x80026F00: sw          $t7, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r15;
    // 0x80026F04: jr          $ra
    // 0x80026F08: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    return;
    // 0x80026F08: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_805A64A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A64A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A64AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805A64B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x805A64B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805A64B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A64BC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x805A64C0: jal         0x80045A34
    // 0x805A64C4: addiu       $a1, $zero, 0x280
    ctx->r5 = ADD32(0, 0X280);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805A64C4: addiu       $a1, $zero, 0x280
    ctx->r5 = ADD32(0, 0X280);
    after_0:
    // 0x805A64C8: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805A64CC: bne         $v0, $zero, L_805A64E4
    if (ctx->r2 != 0) {
        // 0x805A64D0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_805A64E4;
    }
    // 0x805A64D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x805A64D4: jal         0x800445A4
    // 0x805A64D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x805A64D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A64DC: b           L_805A65AC
    // 0x805A64E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A65AC;
    // 0x805A64E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A64E4:
    // 0x805A64E4: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(417, 0X11BC) << 16);
    // 0x805A64E8: addiu       $t6, $t6, 0x647C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(417, 0X11BC));
    // 0x805A64EC: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x805A64F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A64F4: addiu       $a1, $zero, 0x280
    ctx->r5 = ADD32(0, 0X280);
    // 0x805A64F8: jal         0x80065728
    // 0x805A64FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x805A64FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x805A6500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A6504: jal         0x8005D730
    // 0x805A6508: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8005D730(rdram, ctx);
        goto after_3;
    // 0x805A6508: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x805A650C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x805A6510: sw          $zero, 0x268($s1)
    MEM_W(0X268, ctx->r17) = 0;
    // 0x805A6514: jal         0x80058958
    // 0x805A6518: sw          $t7, 0x27C($s1)
    MEM_W(0X27C, ctx->r17) = ctx->r15;
    func_80058958(rdram, ctx);
        goto after_4;
    // 0x805A6518: sw          $t7, 0x27C($s1)
    MEM_W(0X27C, ctx->r17) = ctx->r15;
    after_4:
    // 0x805A651C: beq         $v0, $zero, L_805A65A8
    if (ctx->r2 == 0) {
        // 0x805A6520: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_805A65A8;
    }
    // 0x805A6520: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x805A6524: lw          $t8, -0x7BC4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BC4);
    // 0x805A6528: lw          $t9, 0x10C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10C);
    // 0x805A652C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x805A6530: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x805A6534: beql        $t1, $zero, L_805A65AC
    if (ctx->r9 == 0) {
        // 0x805A6538: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_805A65AC;
    }
    goto skip_0;
    // 0x805A6538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x805A653C: jal         0x80056564
    // 0x805A6540: nop

    func_80056564(rdram, ctx);
        goto after_5;
    // 0x805A6540: nop

    after_5:
    // 0x805A6544: beq         $v0, $zero, L_805A65A8
    if (ctx->r2 == 0) {
        // 0x805A6548: sw          $v0, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r2;
            goto L_805A65A8;
    }
    // 0x805A6548: sw          $v0, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r2;
    // 0x805A654C: lw          $v0, 0x16C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X16C);
    // 0x805A6550: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x805A6554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A6558: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805A655C: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x805A6560: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
    // 0x805A6564: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x805A6568: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    // 0x805A656C: jal         0x800457A0
    // 0x805A6570: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    func_800457A0(rdram, ctx);
        goto after_6;
    // 0x805A6570: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    after_6:
    // 0x805A6574: lw          $a0, 0x268($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X268);
    // 0x805A6578: addiu       $t3, $zero, 0x29
    ctx->r11 = ADD32(0, 0X29);
    // 0x805A657C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805A6580: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x805A6584: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x805A6588: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805A658C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805A6590: jal         0x80056584
    // 0x805A6594: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_7;
    // 0x805A6594: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_7:
    // 0x805A6598: lw          $t6, 0x16C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X16C);
    // 0x805A659C: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x805A65A0: addiu       $t5, $t5, 0x7890
    ctx->r13 = ADD32(ctx->r13, 0X7890);
    // 0x805A65A4: sw          $t5, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r13;
L_805A65A8:
    // 0x805A65A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805A65AC:
    // 0x805A65AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805A65B0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x805A65B4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x805A65B8: jr          $ra
    // 0x805A65BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805A65BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805614C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805614C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805614C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805614C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805614CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805614D0: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x805614D4: lw          $a0, 0x87C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X87C);
    // 0x805614D8: jal         0x80067878
    // 0x805614DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x805614DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x805614E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805614E4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x805614E8: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
    // 0x805614EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805614F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805614F4: jr          $ra
    // 0x805614F8: nop

    return;
    // 0x805614F8: nop

;}
RECOMP_FUNC void func_80064C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064C8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064C94: jal         0x80064C14
    // 0x80064C98: nop

    func_80064C14(rdram, ctx);
        goto after_0;
    // 0x80064C98: nop

    after_0:
    // 0x80064C9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80064CA0: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x80064CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064CA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064CAC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80064CB0: jr          $ra
    // 0x80064CB4: nop

    return;
    // 0x80064CB4: nop

;}
RECOMP_FUNC void func_8064EDE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EDE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064EDEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8064EDF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8064EDF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8064EDF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8064EDFC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8064EE00: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8064EE04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064EE08: addiu       $t6, $zero, 0x1D4C
    ctx->r14 = ADD32(0, 0X1D4C);
    // 0x8064EE0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8064EE10: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8064EE14: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x8064EE18: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8064EE1C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8064EE20: jal         0x8064EA0C
    // 0x8064EE24: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8064EA0C(rdram, ctx);
        goto after_0;
    // 0x8064EE24: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8064EE28: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8064EE2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064EE30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064EE34: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8064EE38: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8064EE3C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8064EE40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8064EE44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064EE48: jr          $ra
    // 0x8064EE4C: nop

    return;
    // 0x8064EE4C: nop

;}
RECOMP_FUNC void func_807897BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807897BC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807897C0: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(787, 0X2E24) << 16);
    // 0x807897C4: addiu       $t6, $t6, -0x679C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(787, 0X2E24));
    // 0x807897C8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807897CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807897D0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807897D4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807897D8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807897DC: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x807897E0: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x807897E4: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807897E8: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807897EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807897F0: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x807897F4: lui         $t8, 0x8079
    ctx->r24 = S32(RELOC_HI16(787, 0X1B88) << 16);
    // 0x807897F8: addiu       $t8, $t8, -0x7A38
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(787, 0X1B88));
    // 0x807897FC: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x80789800: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x80789804: jr          $ra
    // 0x80789808: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x80789808: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_804BA380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BA380: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804BA384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BA388: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BA38C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804BA390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804BA394: jal         0x8004921C
    // 0x804BA398: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804BA398: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x804BA39C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x804BA3A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804BA3A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804BA3A8: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804BA3AC: jal         0x8004921C
    // 0x804BA3B0: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804BA3B0: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x804BA3B4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x804BA3B8: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804BA3BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804BA3C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804BA3C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x804BA3C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BA3CC: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x804BA3D0: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x804BA3D4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x804BA3D8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x804BA3DC: addiu       $a3, $zero, 0x5C0
    ctx->r7 = ADD32(0, 0X5C0);
    // 0x804BA3E0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x804BA3E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804BA3E8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x804BA3EC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804BA3F0: mul.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x804BA3F4: sb          $a2, 0x977($t3)
    MEM_B(0X977, ctx->r11) = ctx->r6;
    // 0x804BA3F8: sb          $a1, 0x976($t3)
    MEM_B(0X976, ctx->r11) = ctx->r5;
    // 0x804BA3FC: sb          $zero, 0x975($t3)
    MEM_B(0X975, ctx->r11) = 0;
    // 0x804BA400: sb          $zero, 0x974($t3)
    MEM_B(0X974, ctx->r11) = 0;
    // 0x804BA404: mul.s       $f14, $f4, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x804BA408: sh          $zero, 0x972($t3)
    MEM_H(0X972, ctx->r11) = 0;
    // 0x804BA40C: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x804BA410: sh          $zero, 0x970($t3)
    MEM_H(0X970, ctx->r11) = 0;
    // 0x804BA414: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x804BA418: sh          $zero, 0x96E($t3)
    MEM_H(0X96E, ctx->r11) = 0;
    // 0x804BA41C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x804BA420: sh          $zero, 0x96C($t3)
    MEM_H(0X96C, ctx->r11) = 0;
    // 0x804BA424: addiu       $t3, $t3, 0x968
    ctx->r11 = ADD32(ctx->r11, 0X968);
    // 0x804BA428: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x804BA42C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x804BA430: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804BA434: sh          $a3, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r7;
    // 0x804BA438: sb          $a2, 0x1F($t3)
    MEM_B(0X1F, ctx->r11) = ctx->r6;
    // 0x804BA43C: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x804BA440: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x804BA444: sb          $a1, 0x1E($t3)
    MEM_B(0X1E, ctx->r11) = ctx->r5;
    // 0x804BA448: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804BA44C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x804BA450: sb          $zero, 0x1D($t3)
    MEM_B(0X1D, ctx->r11) = 0;
    // 0x804BA454: sb          $zero, 0x1C($t3)
    MEM_B(0X1C, ctx->r11) = 0;
    // 0x804BA458: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x804BA45C: sh          $zero, 0x18($t3)
    MEM_H(0X18, ctx->r11) = 0;
    // 0x804BA460: sh          $zero, 0x16($t3)
    MEM_H(0X16, ctx->r11) = 0;
    // 0x804BA464: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
    // 0x804BA468: sh          $a3, 0x1E8($t3)
    MEM_H(0X1E8, ctx->r11) = ctx->r7;
    // 0x804BA46C: sb          $a2, 0x1EF($t3)
    MEM_B(0X1EF, ctx->r11) = ctx->r6;
    // 0x804BA470: sb          $a1, 0x1EE($t3)
    MEM_B(0X1EE, ctx->r11) = ctx->r5;
    // 0x804BA474: sb          $zero, 0x1ED($t3)
    MEM_B(0X1ED, ctx->r11) = 0;
    // 0x804BA478: sb          $zero, 0x1EC($t3)
    MEM_B(0X1EC, ctx->r11) = 0;
    // 0x804BA47C: sh          $zero, 0x1EA($t3)
    MEM_H(0X1EA, ctx->r11) = 0;
    // 0x804BA480: sh          $zero, 0x1E6($t3)
    MEM_H(0X1E6, ctx->r11) = 0;
    // 0x804BA484: sh          $zero, 0x1E4($t3)
    MEM_H(0X1E4, ctx->r11) = 0;
    // 0x804BA488: sh          $a3, 0x1F8($t3)
    MEM_H(0X1F8, ctx->r11) = ctx->r7;
    // 0x804BA48C: sh          $a3, 0x1FA($t3)
    MEM_H(0X1FA, ctx->r11) = ctx->r7;
    // 0x804BA490: sb          $a2, 0x1FF($t3)
    MEM_B(0X1FF, ctx->r11) = ctx->r6;
    // 0x804BA494: sb          $a1, 0x1FE($t3)
    MEM_B(0X1FE, ctx->r11) = ctx->r5;
    // 0x804BA498: sb          $zero, 0x1FD($t3)
    MEM_B(0X1FD, ctx->r11) = 0;
    // 0x804BA49C: sb          $zero, 0x1FC($t3)
    MEM_B(0X1FC, ctx->r11) = 0;
    // 0x804BA4A0: sh          $zero, 0x1F6($t3)
    MEM_H(0X1F6, ctx->r11) = 0;
    // 0x804BA4A4: sh          $zero, 0x1F4($t3)
    MEM_H(0X1F4, ctx->r11) = 0;
    // 0x804BA4A8: sh          $v1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r3;
    // 0x804BA4AC: sh          $v1, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r3;
    // 0x804BA4B0: sh          $t1, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r9;
    // 0x804BA4B4: sh          $t1, 0x1E2($t3)
    MEM_H(0X1E2, ctx->r11) = ctx->r9;
    // 0x804BA4B8: sh          $t2, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r10;
    // 0x804BA4BC: sh          $t2, 0x1F2($t3)
    MEM_H(0X1F2, ctx->r11) = ctx->r10;
    // 0x804BA4C0: sh          $a0, 0x1E0($t3)
    MEM_H(0X1E0, ctx->r11) = ctx->r4;
    // 0x804BA4C4: sh          $a0, 0x1F0($t3)
    MEM_H(0X1F0, ctx->r11) = ctx->r4;
L_804BA4C8:
    // 0x804BA4C8: bne         $t4, $zero, L_804BA4D8
    if (ctx->r12 != 0) {
        // 0x804BA4CC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_804BA4D8;
    }
    // 0x804BA4CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804BA4D0: b           L_804BA4D8
    // 0x804BA4D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
        goto L_804BA4D8;
    // 0x804BA4D4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
L_804BA4D8:
    // 0x804BA4D8: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x804BA4DC: beq         $at, $zero, L_804BA5B8
    if (ctx->r1 == 0) {
        // 0x804BA4E0: sll         $t7, $t4, 3
        ctx->r15 = S32(ctx->r12 << 3);
            goto L_804BA5B8;
    }
    // 0x804BA4E0: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x804BA4E4: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x804BA4E8: sll         $t6, $t9, 6
    ctx->r14 = S32(ctx->r25 << 6);
    // 0x804BA4EC: addu        $v0, $t6, $t3
    ctx->r2 = ADD32(ctx->r14, ctx->r11);
L_804BA4F0:
    // 0x804BA4F0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804BA4F4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x804BA4F8: slti        $at, $t0, 0x1C
    ctx->r1 = SIGNED(ctx->r8) < 0X1C ? 1 : 0;
    // 0x804BA4FC: sh          $t1, -0x1E($v0)
    MEM_H(-0X1E, ctx->r2) = ctx->r9;
    // 0x804BA500: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x804BA504: sh          $zero, -0x1C($v0)
    MEM_H(-0X1C, ctx->r2) = 0;
    // 0x804BA508: sh          $zero, -0x1A($v0)
    MEM_H(-0X1A, ctx->r2) = 0;
    // 0x804BA50C: sh          $a3, -0x18($v0)
    MEM_H(-0X18, ctx->r2) = ctx->r7;
    // 0x804BA510: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x804BA514: sh          $zero, -0x16($v0)
    MEM_H(-0X16, ctx->r2) = 0;
    // 0x804BA518: sb          $zero, -0x14($v0)
    MEM_B(-0X14, ctx->r2) = 0;
    // 0x804BA51C: sb          $zero, -0x13($v0)
    MEM_B(-0X13, ctx->r2) = 0;
    // 0x804BA520: sb          $a1, -0x12($v0)
    MEM_B(-0X12, ctx->r2) = ctx->r5;
    // 0x804BA524: sb          $a2, -0x11($v0)
    MEM_B(-0X11, ctx->r2) = ctx->r6;
    // 0x804BA528: sh          $t2, -0xE($v0)
    MEM_H(-0XE, ctx->r2) = ctx->r10;
    // 0x804BA52C: sh          $zero, -0xC($v0)
    MEM_H(-0XC, ctx->r2) = 0;
    // 0x804BA530: sh          $zero, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = 0;
    // 0x804BA534: sh          $a3, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r7;
    // 0x804BA538: sh          $a3, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r7;
    // 0x804BA53C: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x804BA540: sb          $zero, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = 0;
    // 0x804BA544: sb          $a1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r5;
    // 0x804BA548: sb          $a2, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r6;
    // 0x804BA54C: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x804BA550: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x804BA554: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x804BA558: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x804BA55C: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x804BA560: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x804BA564: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x804BA568: sb          $a1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r5;
    // 0x804BA56C: sb          $a2, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r6;
    // 0x804BA570: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x804BA574: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x804BA578: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x804BA57C: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x804BA580: sh          $a3, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r7;
    // 0x804BA584: sb          $zero, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = 0;
    // 0x804BA588: sb          $zero, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = 0;
    // 0x804BA58C: sb          $a1, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r5;
    // 0x804BA590: sb          $a2, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r6;
    // 0x804BA594: sh          $v1, -0x20($v0)
    MEM_H(-0X20, ctx->r2) = ctx->r3;
    // 0x804BA598: sh          $v1, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r3;
    // 0x804BA59C: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x804BA5A0: beq         $at, $zero, L_804BA5B8
    if (ctx->r1 == 0) {
        // 0x804BA5A4: sh          $v1, 0x10($v0)
        MEM_H(0X10, ctx->r2) = ctx->r3;
            goto L_804BA5B8;
    }
    // 0x804BA5A4: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x804BA5A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x804BA5AC: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x804BA5B0: bne         $at, $zero, L_804BA4F0
    if (ctx->r1 != 0) {
        // 0x804BA5B4: addiu       $v0, $v0, 0x40
        ctx->r2 = ADD32(ctx->r2, 0X40);
            goto L_804BA4F0;
    }
    // 0x804BA5B4: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
L_804BA5B8:
    // 0x804BA5B8: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x804BA5BC: bne         $at, $zero, L_804BA5CC
    if (ctx->r1 != 0) {
        // 0x804BA5C0: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_804BA5CC;
    }
    // 0x804BA5C0: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x804BA5C4: bne         $t4, $t5, L_804BA4C8
    if (ctx->r12 != ctx->r13) {
        // 0x804BA5C8: nop
    
            goto L_804BA4C8;
    }
    // 0x804BA5C8: nop

L_804BA5CC:
    // 0x804BA5CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BA5D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804BA5D4: jr          $ra
    // 0x804BA5D8: nop

    return;
    // 0x804BA5D8: nop

;}
RECOMP_FUNC void func_807AC8D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC8D0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AC8D4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AC8D8: lui         $t7, 0x104
    ctx->r15 = S32(0X104 << 16);
    // 0x807AC8DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x807AC8E0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x807AC8E4: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x807AC8E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x807AC8EC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x807AC8F0: lui         $t4, 0x400
    ctx->r12 = S32(0X400 << 16);
    // 0x807AC8F4: ori         $t4, $t4, 0x7DEF
    ctx->r12 = ctx->r12 | 0X7DEF;
    // 0x807AC8F8: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x807AC8FC: addu        $t1, $v1, $t9
    ctx->r9 = ADD32(ctx->r3, ctx->r25);
    // 0x807AC900: addiu       $t2, $t1, 0x3E8
    ctx->r10 = ADD32(ctx->r9, 0X3E8);
    // 0x807AC904: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x807AC908: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AC90C: lui         $t1, 0xB100
    ctx->r9 = S32(0XB100 << 16);
    // 0x807AC910: ori         $t1, $t1, 0x204
    ctx->r9 = ctx->r9 | 0X204;
    // 0x807AC914: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x807AC918: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x807AC91C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x807AC920: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x807AC924: addiu       $t2, $zero, 0x406
    ctx->r10 = ADD32(0, 0X406);
    // 0x807AC928: lui         $t4, 0xB100
    ctx->r12 = S32(0XB100 << 16);
    // 0x807AC92C: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x807AC930: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x807AC934: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x807AC938: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x807AC93C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x807AC940: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x807AC944: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AC948: addiu       $t5, $zero, 0x80A
    ctx->r13 = ADD32(0, 0X80A);
    // 0x807AC94C: ori         $t4, $t4, 0x608
    ctx->r12 = ctx->r12 | 0X608;
    // 0x807AC950: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x807AC954: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x807AC958: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x807AC95C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x807AC960: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AC964: lui         $t7, 0xB100
    ctx->r15 = S32(0XB100 << 16);
    // 0x807AC968: ori         $t7, $t7, 0xA0C
    ctx->r15 = ctx->r15 | 0XA0C;
    // 0x807AC96C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x807AC970: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x807AC974: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x807AC978: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x807AC97C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AC980: addiu       $t8, $zero, 0xC0E
    ctx->r24 = ADD32(0, 0XC0E);
    // 0x807AC984: lui         $t1, 0xB100
    ctx->r9 = S32(0XB100 << 16);
    // 0x807AC988: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x807AC98C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x807AC990: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x807AC994: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x807AC998: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AC99C: ori         $t1, $t1, 0xE10
    ctx->r9 = ctx->r9 | 0XE10;
    // 0x807AC9A0: addiu       $t2, $zero, 0x1012
    ctx->r10 = ADD32(0, 0X1012);
    // 0x807AC9A4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x807AC9A8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x807AC9AC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x807AC9B0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x807AC9B4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AC9B8: lui         $t4, 0xB100
    ctx->r12 = S32(0XB100 << 16);
    // 0x807AC9BC: ori         $t4, $t4, 0x1214
    ctx->r12 = ctx->r12 | 0X1214;
    // 0x807AC9C0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x807AC9C4: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x807AC9C8: addiu       $t5, $zero, 0x1416
    ctx->r13 = ADD32(0, 0X1416);
    // 0x807AC9CC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x807AC9D0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x807AC9D4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AC9D8: lui         $t7, 0xB100
    ctx->r15 = S32(0XB100 << 16);
    // 0x807AC9DC: ori         $t7, $t7, 0x1618
    ctx->r15 = ctx->r15 | 0X1618;
    // 0x807AC9E0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x807AC9E4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x807AC9E8: addiu       $t8, $zero, 0x181A
    ctx->r24 = ADD32(0, 0X181A);
    // 0x807AC9EC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x807AC9F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x807AC9F4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807AC9F8: lui         $t1, 0xB100
    ctx->r9 = S32(0XB100 << 16);
    // 0x807AC9FC: ori         $t1, $t1, 0x1A1C
    ctx->r9 = ctx->r9 | 0X1A1C;
    // 0x807ACA00: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x807ACA04: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x807ACA08: addiu       $t2, $zero, 0x1C1E
    ctx->r10 = ADD32(0, 0X1C1E);
    // 0x807ACA0C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x807ACA10: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x807ACA14: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807ACA18: lui         $t4, 0xB100
    ctx->r12 = S32(0XB100 << 16);
    // 0x807ACA1C: ori         $t4, $t4, 0x1E20
    ctx->r12 = ctx->r12 | 0X1E20;
    // 0x807ACA20: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x807ACA24: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x807ACA28: addiu       $t5, $zero, 0x2022
    ctx->r13 = ADD32(0, 0X2022);
    // 0x807ACA2C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x807ACA30: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x807ACA34: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807ACA38: lui         $t7, 0xB100
    ctx->r15 = S32(0XB100 << 16);
    // 0x807ACA3C: ori         $t7, $t7, 0x2224
    ctx->r15 = ctx->r15 | 0X2224;
    // 0x807ACA40: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x807ACA44: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x807ACA48: addiu       $t8, $zero, 0x2426
    ctx->r24 = ADD32(0, 0X2426);
    // 0x807ACA4C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x807ACA50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x807ACA54: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807ACA58: lui         $t1, 0xB100
    ctx->r9 = S32(0XB100 << 16);
    // 0x807ACA5C: ori         $t1, $t1, 0x2628
    ctx->r9 = ctx->r9 | 0X2628;
    // 0x807ACA60: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x807ACA64: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x807ACA68: addiu       $t2, $zero, 0x282A
    ctx->r10 = ADD32(0, 0X282A);
    // 0x807ACA6C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x807ACA70: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x807ACA74: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807ACA78: lui         $t4, 0xB100
    ctx->r12 = S32(0XB100 << 16);
    // 0x807ACA7C: ori         $t4, $t4, 0x2A2C
    ctx->r12 = ctx->r12 | 0X2A2C;
    // 0x807ACA80: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x807ACA84: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x807ACA88: addiu       $t5, $zero, 0x2C2E
    ctx->r13 = ADD32(0, 0X2C2E);
    // 0x807ACA8C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x807ACA90: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x807ACA94: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807ACA98: lui         $t7, 0xB100
    ctx->r15 = S32(0XB100 << 16);
    // 0x807ACA9C: ori         $t7, $t7, 0x2E30
    ctx->r15 = ctx->r15 | 0X2E30;
    // 0x807ACAA0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x807ACAA4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x807ACAA8: addiu       $t8, $zero, 0x3032
    ctx->r24 = ADD32(0, 0X3032);
    // 0x807ACAAC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x807ACAB0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x807ACAB4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807ACAB8: lui         $t1, 0xB100
    ctx->r9 = S32(0XB100 << 16);
    // 0x807ACABC: ori         $t1, $t1, 0x3234
    ctx->r9 = ctx->r9 | 0X3234;
    // 0x807ACAC0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x807ACAC4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x807ACAC8: addiu       $t2, $zero, 0x3436
    ctx->r10 = ADD32(0, 0X3436);
    // 0x807ACACC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x807ACAD0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x807ACAD4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807ACAD8: lui         $t4, 0xB100
    ctx->r12 = S32(0XB100 << 16);
    // 0x807ACADC: ori         $t4, $t4, 0x3638
    ctx->r12 = ctx->r12 | 0X3638;
    // 0x807ACAE0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x807ACAE4: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x807ACAE8: addiu       $t5, $zero, 0x383A
    ctx->r13 = ADD32(0, 0X383A);
    // 0x807ACAEC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x807ACAF0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x807ACAF4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807ACAF8: lui         $t7, 0xB100
    ctx->r15 = S32(0XB100 << 16);
    // 0x807ACAFC: ori         $t7, $t7, 0x3A3C
    ctx->r15 = ctx->r15 | 0X3A3C;
    // 0x807ACB00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x807ACB04: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x807ACB08: addiu       $t8, $zero, 0x3C02
    ctx->r24 = ADD32(0, 0X3C02);
    // 0x807ACB0C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x807ACB10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x807ACB14: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x807ACB18: lui         $t1, 0xBD00
    ctx->r9 = S32(0XBD00 << 16);
    // 0x807ACB1C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x807ACB20: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x807ACB24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x807ACB28: jr          $ra
    // 0x807ACB2C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    return;
    // 0x807ACB2C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void func_806AE270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AE270: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x806AE274: lui         $t9, 0x806B
    ctx->r25 = S32(RELOC_HI16(595, 0X1DEC) << 16);
    // 0x806AE278: addiu       $t9, $t9, -0x4D4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(595, 0X1DEC));
    // 0x806AE27C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806AE280: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806AE284: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806AE288: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x806AE28C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x806AE290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AE294: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AE298: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x806AE29C: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x806AE2A0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x806AE2A4: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x806AE2A8: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x806AE2AC: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x806AE2B0: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x806AE2B4: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x806AE2B8: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x806AE2BC: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x806AE2C0: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x806AE2C4: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x806AE2C8: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x806AE2CC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x806AE2D0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x806AE2D4: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x806AE2D8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x806AE2DC: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x806AE2E0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x806AE2E4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x806AE2E8: sltu        $at, $t4, $t9
    ctx->r1 = ctx->r12 < ctx->r25 ? 1 : 0;
    // 0x806AE2EC: bnel        $at, $zero, L_806AE324
    if (ctx->r1 != 0) {
        // 0x806AE2F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806AE324;
    }
    goto skip_0;
    // 0x806AE2F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806AE2F4: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x806AE2F8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x806AE2FC: lbu         $t1, 0x8($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X8);
    // 0x806AE300: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x806AE304: sltu        $at, $t6, $t1
    ctx->r1 = ctx->r14 < ctx->r9 ? 1 : 0;
    // 0x806AE308: bne         $at, $zero, L_806AE318
    if (ctx->r1 != 0) {
        // 0x806AE30C: nop
    
            goto L_806AE318;
    }
    // 0x806AE30C: nop

    // 0x806AE310: b           L_806AE324
    // 0x806AE314: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
        goto L_806AE324;
    // 0x806AE314: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_806AE318:
    // 0x806AE318: b           L_806AE324
    // 0x806AE31C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806AE324;
    // 0x806AE31C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806AE320: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806AE324:
    // 0x806AE324: jr          $ra
    // 0x806AE328: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806AE328: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804B8864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8864: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B8868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B886C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804B8870: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804B8874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B8878: jal         0x8004921C
    // 0x804B887C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804B887C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x804B8880: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x804B8884: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804B8888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B888C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804B8890: jal         0x8004921C
    // 0x804B8894: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804B8894: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x804B8898: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x804B889C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804B88A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804B88A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804B88A8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x804B88AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804B88B0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x804B88B4: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x804B88B8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x804B88BC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x804B88C0: addiu       $a3, $zero, 0x5C0
    ctx->r7 = ADD32(0, 0X5C0);
    // 0x804B88C4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x804B88C8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804B88CC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x804B88D0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804B88D4: mul.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x804B88D8: sb          $a2, 0x207($t3)
    MEM_B(0X207, ctx->r11) = ctx->r6;
    // 0x804B88DC: sb          $a1, 0x206($t3)
    MEM_B(0X206, ctx->r11) = ctx->r5;
    // 0x804B88E0: sb          $zero, 0x205($t3)
    MEM_B(0X205, ctx->r11) = 0;
    // 0x804B88E4: sb          $zero, 0x204($t3)
    MEM_B(0X204, ctx->r11) = 0;
    // 0x804B88E8: mul.s       $f14, $f4, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x804B88EC: sh          $zero, 0x202($t3)
    MEM_H(0X202, ctx->r11) = 0;
    // 0x804B88F0: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x804B88F4: sh          $zero, 0x200($t3)
    MEM_H(0X200, ctx->r11) = 0;
    // 0x804B88F8: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x804B88FC: sh          $zero, 0x1FE($t3)
    MEM_H(0X1FE, ctx->r11) = 0;
    // 0x804B8900: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x804B8904: sh          $zero, 0x1FC($t3)
    MEM_H(0X1FC, ctx->r11) = 0;
    // 0x804B8908: addiu       $t3, $t3, 0x1F8
    ctx->r11 = ADD32(ctx->r11, 0X1F8);
    // 0x804B890C: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x804B8910: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x804B8914: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804B8918: sh          $a3, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r7;
    // 0x804B891C: sb          $a2, 0x1F($t3)
    MEM_B(0X1F, ctx->r11) = ctx->r6;
    // 0x804B8920: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x804B8924: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x804B8928: sb          $a1, 0x1E($t3)
    MEM_B(0X1E, ctx->r11) = ctx->r5;
    // 0x804B892C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804B8930: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x804B8934: sb          $zero, 0x1D($t3)
    MEM_B(0X1D, ctx->r11) = 0;
    // 0x804B8938: sb          $zero, 0x1C($t3)
    MEM_B(0X1C, ctx->r11) = 0;
    // 0x804B893C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x804B8940: sh          $zero, 0x18($t3)
    MEM_H(0X18, ctx->r11) = 0;
    // 0x804B8944: sh          $zero, 0x16($t3)
    MEM_H(0X16, ctx->r11) = 0;
    // 0x804B8948: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
    // 0x804B894C: sh          $a3, 0x1E8($t3)
    MEM_H(0X1E8, ctx->r11) = ctx->r7;
    // 0x804B8950: sb          $a2, 0x1EF($t3)
    MEM_B(0X1EF, ctx->r11) = ctx->r6;
    // 0x804B8954: sb          $a1, 0x1EE($t3)
    MEM_B(0X1EE, ctx->r11) = ctx->r5;
    // 0x804B8958: sb          $zero, 0x1ED($t3)
    MEM_B(0X1ED, ctx->r11) = 0;
    // 0x804B895C: sb          $zero, 0x1EC($t3)
    MEM_B(0X1EC, ctx->r11) = 0;
    // 0x804B8960: sh          $zero, 0x1EA($t3)
    MEM_H(0X1EA, ctx->r11) = 0;
    // 0x804B8964: sh          $zero, 0x1E6($t3)
    MEM_H(0X1E6, ctx->r11) = 0;
    // 0x804B8968: sh          $zero, 0x1E4($t3)
    MEM_H(0X1E4, ctx->r11) = 0;
    // 0x804B896C: sh          $a3, 0x1F8($t3)
    MEM_H(0X1F8, ctx->r11) = ctx->r7;
    // 0x804B8970: sh          $a3, 0x1FA($t3)
    MEM_H(0X1FA, ctx->r11) = ctx->r7;
    // 0x804B8974: sb          $a2, 0x1FF($t3)
    MEM_B(0X1FF, ctx->r11) = ctx->r6;
    // 0x804B8978: sb          $a1, 0x1FE($t3)
    MEM_B(0X1FE, ctx->r11) = ctx->r5;
    // 0x804B897C: sb          $zero, 0x1FD($t3)
    MEM_B(0X1FD, ctx->r11) = 0;
    // 0x804B8980: sb          $zero, 0x1FC($t3)
    MEM_B(0X1FC, ctx->r11) = 0;
    // 0x804B8984: sh          $zero, 0x1F6($t3)
    MEM_H(0X1F6, ctx->r11) = 0;
    // 0x804B8988: sh          $zero, 0x1F4($t3)
    MEM_H(0X1F4, ctx->r11) = 0;
    // 0x804B898C: sh          $v1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r3;
    // 0x804B8990: sh          $v1, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r3;
    // 0x804B8994: sh          $t1, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r9;
    // 0x804B8998: sh          $t1, 0x1E2($t3)
    MEM_H(0X1E2, ctx->r11) = ctx->r9;
    // 0x804B899C: sh          $t2, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r10;
    // 0x804B89A0: sh          $t2, 0x1F2($t3)
    MEM_H(0X1F2, ctx->r11) = ctx->r10;
    // 0x804B89A4: sh          $a0, 0x1E0($t3)
    MEM_H(0X1E0, ctx->r11) = ctx->r4;
    // 0x804B89A8: sh          $a0, 0x1F0($t3)
    MEM_H(0X1F0, ctx->r11) = ctx->r4;
L_804B89AC:
    // 0x804B89AC: bne         $t4, $zero, L_804B89BC
    if (ctx->r12 != 0) {
        // 0x804B89B0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_804B89BC;
    }
    // 0x804B89B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804B89B4: b           L_804B89BC
    // 0x804B89B8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
        goto L_804B89BC;
    // 0x804B89B8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
L_804B89BC:
    // 0x804B89BC: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x804B89C0: beq         $at, $zero, L_804B8A9C
    if (ctx->r1 == 0) {
        // 0x804B89C4: sll         $t7, $t4, 3
        ctx->r15 = S32(ctx->r12 << 3);
            goto L_804B8A9C;
    }
    // 0x804B89C4: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x804B89C8: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x804B89CC: sll         $t6, $t9, 6
    ctx->r14 = S32(ctx->r25 << 6);
    // 0x804B89D0: addu        $v0, $t6, $t3
    ctx->r2 = ADD32(ctx->r14, ctx->r11);
L_804B89D4:
    // 0x804B89D4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x804B89D8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x804B89DC: slti        $at, $t0, 0x1C
    ctx->r1 = SIGNED(ctx->r8) < 0X1C ? 1 : 0;
    // 0x804B89E0: sh          $t1, -0x1E($v0)
    MEM_H(-0X1E, ctx->r2) = ctx->r9;
    // 0x804B89E4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x804B89E8: sh          $zero, -0x1C($v0)
    MEM_H(-0X1C, ctx->r2) = 0;
    // 0x804B89EC: sh          $zero, -0x1A($v0)
    MEM_H(-0X1A, ctx->r2) = 0;
    // 0x804B89F0: sh          $a3, -0x18($v0)
    MEM_H(-0X18, ctx->r2) = ctx->r7;
    // 0x804B89F4: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x804B89F8: sh          $zero, -0x16($v0)
    MEM_H(-0X16, ctx->r2) = 0;
    // 0x804B89FC: sb          $zero, -0x14($v0)
    MEM_B(-0X14, ctx->r2) = 0;
    // 0x804B8A00: sb          $zero, -0x13($v0)
    MEM_B(-0X13, ctx->r2) = 0;
    // 0x804B8A04: sb          $a1, -0x12($v0)
    MEM_B(-0X12, ctx->r2) = ctx->r5;
    // 0x804B8A08: sb          $a2, -0x11($v0)
    MEM_B(-0X11, ctx->r2) = ctx->r6;
    // 0x804B8A0C: sh          $t2, -0xE($v0)
    MEM_H(-0XE, ctx->r2) = ctx->r10;
    // 0x804B8A10: sh          $zero, -0xC($v0)
    MEM_H(-0XC, ctx->r2) = 0;
    // 0x804B8A14: sh          $zero, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = 0;
    // 0x804B8A18: sh          $a3, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r7;
    // 0x804B8A1C: sh          $a3, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r7;
    // 0x804B8A20: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x804B8A24: sb          $zero, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = 0;
    // 0x804B8A28: sb          $a1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r5;
    // 0x804B8A2C: sb          $a2, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r6;
    // 0x804B8A30: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x804B8A34: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x804B8A38: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x804B8A3C: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x804B8A40: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x804B8A44: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x804B8A48: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x804B8A4C: sb          $a1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r5;
    // 0x804B8A50: sb          $a2, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r6;
    // 0x804B8A54: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x804B8A58: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x804B8A5C: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x804B8A60: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x804B8A64: sh          $a3, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r7;
    // 0x804B8A68: sb          $zero, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = 0;
    // 0x804B8A6C: sb          $zero, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = 0;
    // 0x804B8A70: sb          $a1, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r5;
    // 0x804B8A74: sb          $a2, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r6;
    // 0x804B8A78: sh          $v1, -0x20($v0)
    MEM_H(-0X20, ctx->r2) = ctx->r3;
    // 0x804B8A7C: sh          $v1, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r3;
    // 0x804B8A80: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x804B8A84: beq         $at, $zero, L_804B8A9C
    if (ctx->r1 == 0) {
        // 0x804B8A88: sh          $v1, 0x10($v0)
        MEM_H(0X10, ctx->r2) = ctx->r3;
            goto L_804B8A9C;
    }
    // 0x804B8A88: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x804B8A8C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x804B8A90: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x804B8A94: bne         $at, $zero, L_804B89D4
    if (ctx->r1 != 0) {
        // 0x804B8A98: addiu       $v0, $v0, 0x40
        ctx->r2 = ADD32(ctx->r2, 0X40);
            goto L_804B89D4;
    }
    // 0x804B8A98: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
L_804B8A9C:
    // 0x804B8A9C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x804B8AA0: bne         $at, $zero, L_804B8AB0
    if (ctx->r1 != 0) {
        // 0x804B8AA4: addiu       $t4, $t4, 0x1
        ctx->r12 = ADD32(ctx->r12, 0X1);
            goto L_804B8AB0;
    }
    // 0x804B8AA4: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x804B8AA8: bne         $t4, $t5, L_804B89AC
    if (ctx->r12 != ctx->r13) {
        // 0x804B8AAC: nop
    
            goto L_804B89AC;
    }
    // 0x804B8AAC: nop

L_804B8AB0:
    // 0x804B8AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B8AB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B8AB8: jr          $ra
    // 0x804B8ABC: nop

    return;
    // 0x804B8ABC: nop

;}
RECOMP_FUNC void func_80742240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742240: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(754, 0XE60) << 16);
    // 0x80742244: jr          $ra
    // 0x80742248: addiu       $v0, $v0, 0x30A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(754, 0XE60));
    return;
    // 0x80742248: addiu       $v0, $v0, 0x30A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(754, 0XE60));
;}
RECOMP_FUNC void func_806657A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806657A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806657A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806657A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806657AC: lw          $a2, 0x174($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X174);
    // 0x806657B0: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x806657B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806657B8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x806657BC: lw          $t0, 0x14($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X14);
    // 0x806657C0: lw          $a3, 0x2C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X2C);
    // 0x806657C4: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x806657C8: beq         $t0, $zero, L_806657D8
    if (ctx->r8 == 0) {
        // 0x806657CC: lw          $a1, 0x34($v0)
        ctx->r5 = MEM_W(ctx->r2, 0X34);
            goto L_806657D8;
    }
    // 0x806657CC: lw          $a1, 0x34($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X34);
    // 0x806657D0: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x806657D4: sw          $t6, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r14;
L_806657D8:
    // 0x806657D8: beq         $a3, $zero, L_80665BAC
    if (ctx->r7 == 0) {
        // 0x806657DC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80665BAC;
    }
    // 0x806657DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806657E0: andi        $t1, $a3, 0x3
    ctx->r9 = ctx->r7 & 0X3;
    // 0x806657E4: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x806657E8: beq         $t1, $zero, L_806658D8
    if (ctx->r9 == 0) {
        // 0x806657EC: addu        $t0, $t1, $a3
        ctx->r8 = ADD32(ctx->r9, ctx->r7);
            goto L_806658D8;
    }
    // 0x806657EC: addu        $t0, $t1, $a3
    ctx->r8 = ADD32(ctx->r9, ctx->r7);
    // 0x806657F0: sll         $v0, $zero, 2
    ctx->r2 = S32(0 << 2);
    // 0x806657F4: subu        $v0, $v0, $zero
    ctx->r2 = SUB32(ctx->r2, 0);
    // 0x806657F8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x806657FC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80665800: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665804: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80665808: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x8066580C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80665810: lh          $t3, 0x0($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X0);
    // 0x80665814: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80665818: nop

    // 0x8066581C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665820: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665824: beql        $t0, $a3, L_8066589C
    if (ctx->r8 == ctx->r7) {
        // 0x80665828: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_8066589C;
    }
    goto skip_0;
    // 0x80665828: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_0:
    // 0x8066582C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80665830:
    // 0x80665830: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80665834: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665838: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8066583C: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80665840: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80665844: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80665848: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8066584C: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x80665850: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665854: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80665858: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x8066585C: nop

    // 0x80665860: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665864: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665868: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8066586C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80665870: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665874: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x80665878: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8066587C: lh          $t3, 0x0($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X0);
    // 0x80665880: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80665884: nop

    // 0x80665888: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8066588C: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665890: bnel        $t0, $a3, L_80665830
    if (ctx->r8 != ctx->r7) {
        // 0x80665894: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80665830;
    }
    goto skip_1;
    // 0x80665894: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_1:
    // 0x80665898: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_8066589C:
    // 0x8066589C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x806658A0: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x806658A4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806658A8: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x806658AC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x806658B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x806658B4: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x806658B8: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x806658BC: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x806658C0: mtc1        $t7, $f14
    ctx->f14.u32l = ctx->r15;
    // 0x806658C4: nop

    // 0x806658C8: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x806658CC: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x806658D0: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x806658D4: beq         $a3, $zero, L_80665BAC
    if (ctx->r7 == 0) {
        // 0x806658D8: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_80665BAC;
    }
L_806658D8:
    // 0x806658D8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x806658DC: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x806658E0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x806658E4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x806658E8: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806658EC: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x806658F0: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x806658F4: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x806658F8: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x806658FC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80665900: nop

    // 0x80665904: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665908: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8066590C: beql        $a3, $zero, L_80665A7C
    if (ctx->r7 == 0) {
        // 0x80665910: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80665A7C;
    }
    goto skip_2;
    // 0x80665910: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_2:
    // 0x80665914: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80665918:
    // 0x80665918: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8066591C: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665920: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x80665924: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x80665928: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8066592C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80665930: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80665934: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80665938: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x8066593C: mtc1        $t8, $f14
    ctx->f14.u32l = ctx->r24;
    // 0x80665940: nop

    // 0x80665944: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665948: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8066594C: swc1        $f14, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->f14.u32l;
    // 0x80665950: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80665954: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665958: lw          $t3, 0x3C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X3C);
    // 0x8066595C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80665960: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80665964: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80665968: nop

    // 0x8066596C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665970: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665974: swc1        $f16, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f16.u32l;
    // 0x80665978: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8066597C: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665980: lw          $t7, 0x3C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3C);
    // 0x80665984: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80665988: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x8066598C: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665990: mtc1        $t9, $f14
    ctx->f14.u32l = ctx->r25;
    // 0x80665994: nop

    // 0x80665998: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8066599C: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x806659A0: swc1        $f14, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f14.u32l;
    // 0x806659A4: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x806659A8: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806659AC: lw          $t4, 0x3C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X3C);
    // 0x806659B0: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x806659B4: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x806659B8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x806659BC: nop

    // 0x806659C0: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x806659C4: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x806659C8: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x806659CC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x806659D0: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x806659D4: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x806659D8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x806659DC: lh          $t3, 0x2($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X2);
    // 0x806659E0: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x806659E4: mtc1        $t3, $f14
    ctx->f14.u32l = ctx->r11;
    // 0x806659E8: nop

    // 0x806659EC: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x806659F0: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x806659F4: swc1        $f14, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f14.u32l;
    // 0x806659F8: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x806659FC: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665A00: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80665A04: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80665A08: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80665A0C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80665A10: nop

    // 0x80665A14: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665A18: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665A1C: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80665A20: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80665A24: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665A28: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x80665A2C: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80665A30: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80665A34: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665A38: mtc1        $t4, $f14
    ctx->f14.u32l = ctx->r12;
    // 0x80665A3C: nop

    // 0x80665A40: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665A44: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665A48: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x80665A4C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80665A50: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665A54: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x80665A58: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80665A5C: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x80665A60: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80665A64: nop

    // 0x80665A68: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665A6C: mul.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665A70: bnel        $a3, $zero, L_80665918
    if (ctx->r7 != 0) {
        // 0x80665A74: swc1        $f18, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
            goto L_80665918;
    }
    goto skip_3;
    // 0x80665A74: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    skip_3:
    // 0x80665A78: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_80665A7C:
    // 0x80665A7C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80665A80: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665A84: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80665A88: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x80665A8C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80665A90: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80665A94: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80665A98: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665A9C: mtc1        $t8, $f14
    ctx->f14.u32l = ctx->r24;
    // 0x80665AA0: nop

    // 0x80665AA4: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665AA8: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665AAC: swc1        $f14, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->f14.u32l;
    // 0x80665AB0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80665AB4: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665AB8: lw          $t3, 0x3C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X3C);
    // 0x80665ABC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80665AC0: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80665AC4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80665AC8: nop

    // 0x80665ACC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665AD0: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665AD4: swc1        $f16, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f16.u32l;
    // 0x80665AD8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80665ADC: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665AE0: lw          $t7, 0x3C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X3C);
    // 0x80665AE4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80665AE8: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80665AEC: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665AF0: mtc1        $t9, $f14
    ctx->f14.u32l = ctx->r25;
    // 0x80665AF4: nop

    // 0x80665AF8: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665AFC: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665B00: swc1        $f14, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f14.u32l;
    // 0x80665B04: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80665B08: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665B0C: lw          $t4, 0x3C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X3C);
    // 0x80665B10: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80665B14: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80665B18: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80665B1C: nop

    // 0x80665B20: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665B24: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665B28: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x80665B2C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80665B30: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665B34: lw          $t8, 0x3C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X3C);
    // 0x80665B38: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80665B3C: lh          $t3, 0x2($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X2);
    // 0x80665B40: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665B44: mtc1        $t3, $f14
    ctx->f14.u32l = ctx->r11;
    // 0x80665B48: nop

    // 0x80665B4C: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665B50: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665B54: swc1        $f14, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->f14.u32l;
    // 0x80665B58: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80665B5C: lwc1        $f14, 0x6C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80665B60: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80665B64: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80665B68: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80665B6C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80665B70: nop

    // 0x80665B74: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80665B78: mul.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80665B7C: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80665B80: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80665B84: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80665B88: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x80665B8C: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80665B90: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80665B94: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80665B98: mtc1        $t4, $f14
    ctx->f14.u32l = ctx->r12;
    // 0x80665B9C: nop

    // 0x80665BA0: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x80665BA4: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80665BA8: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
L_80665BAC:
    // 0x80665BAC: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80665BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80665BB4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80665BB8: jal         0x80048F84
    // 0x80665BBC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80665BBC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x80665BC0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80665BC4: lui         $t9, 0x8066
    ctx->r25 = S32(RELOC_HI16(504, 0X2CB8) << 16);
    // 0x80665BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80665BCC: lw          $t5, 0x1C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X1C);
    // 0x80665BD0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80665BD4: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80665BD8: lw          $t9, 0x7988($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(504, 0X2CB8));
    // 0x80665BDC: jalr        $t9
    // 0x80665BE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80665BE0: nop

    after_1:
    // 0x80665BE4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80665BE8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80665BEC: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80665BF0: lbu         $t3, 0x2C($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X2C);
    // 0x80665BF4: beq         $t3, $zero, L_80665C04
    if (ctx->r11 == 0) {
        // 0x80665BF8: nop
    
            goto L_80665C04;
    }
    // 0x80665BF8: nop

    // 0x80665BFC: jal         0x806650A8
    // 0x80665C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806650A8(rdram, ctx);
        goto after_2;
    // 0x80665C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80665C04:
    // 0x80665C04: jal         0x80665110
    // 0x80665C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80665110(rdram, ctx);
        goto after_3;
    // 0x80665C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80665C0C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80665C10: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80665C14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80665C18: lw          $t5, 0x20($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20);
    // 0x80665C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80665C20: beql        $t5, $zero, L_80665C70
    if (ctx->r13 == 0) {
        // 0x80665C24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80665C70;
    }
    goto skip_4;
    // 0x80665C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80665C28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80665C2C: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    // 0x80665C30: sb          $t9, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r25;
    // 0x80665C34: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x80665C38: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x80665C3C: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    // 0x80665C40: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x80665C44: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80665C48: jal         0x8005FD1C
    // 0x80665C4C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    func_8005FD1C(rdram, ctx);
        goto after_4;
    // 0x80665C4C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    after_4:
    // 0x80665C50: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x80665C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80665C58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80665C5C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80665C60: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80665C64: jal         0x8066622C
    // 0x80665C68: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    func_8066622C(rdram, ctx);
        goto after_5;
    // 0x80665C68: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    after_5:
    // 0x80665C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80665C70:
    // 0x80665C70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80665C74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80665C78: jr          $ra
    // 0x80665C7C: nop

    return;
    // 0x80665C7C: nop

;}
RECOMP_FUNC void func_8046AE98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046AE98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8046AE9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046AEA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046AEA4: jal         0x8004700C
    // 0x8046AEA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8046AEA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8046AEAC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8046AEB0: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8046AEB4: beq         $v0, $zero, L_8046AF6C
    if (ctx->r2 == 0) {
        // 0x8046AEB8: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_8046AF6C;
    }
    // 0x8046AEB8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8046AEBC: jal         0x8046B08C
    // 0x8046AEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046B08C(rdram, ctx);
        goto after_1;
    // 0x8046AEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8046AEC4: jal         0x8046AE04
    // 0x8046AEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046AE04(rdram, ctx);
        goto after_2;
    // 0x8046AEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8046AECC: jal         0x8046A4A4
    // 0x8046AED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046A4A4(rdram, ctx);
        goto after_3;
    // 0x8046AED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8046AED4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8046AED8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8046AEDC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8046AEE0: jal         0x80469D08
    // 0x8046AEE4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80469D08(rdram, ctx);
        goto after_4;
    // 0x8046AEE4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_4:
    // 0x8046AEE8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8046AEEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8046AEF0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8046AEF4: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8046AEF8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8046AEFC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8046AF00: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8046AF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046AF08: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8046AF0C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8046AF10: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8046AF14: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x8046AF18: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8046AF1C: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8046AF20: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8046AF24: jal         0x80469F34
    // 0x8046AF28: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    func_80469F34(rdram, ctx);
        goto after_5;
    // 0x8046AF28: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    after_5:
    // 0x8046AF2C: beq         $v0, $zero, L_8046AF50
    if (ctx->r2 == 0) {
        // 0x8046AF30: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_8046AF50;
    }
    // 0x8046AF30: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8046AF34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046AF38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046AF3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8046AF40: jal         0x8046B2D8
    // 0x8046AF44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8046B2D8(rdram, ctx);
        goto after_6;
    // 0x8046AF44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8046AF48: b           L_8046AF70
    // 0x8046AF4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8046AF70;
    // 0x8046AF4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046AF50:
    // 0x8046AF50: lw          $t8, 0x180($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X180);
    // 0x8046AF54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8046AF58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8046AF5C: bne         $s0, $t8, L_8046AF6C
    if (ctx->r16 != ctx->r24) {
        // 0x8046AF60: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8046AF6C;
    }
    // 0x8046AF60: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8046AF64: jal         0x8046B2D8
    // 0x8046AF68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8046B2D8(rdram, ctx);
        goto after_7;
    // 0x8046AF68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_8046AF6C:
    // 0x8046AF6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046AF70:
    // 0x8046AF70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046AF74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8046AF78: jr          $ra
    // 0x8046AF7C: nop

    return;
    // 0x8046AF7C: nop

;}
RECOMP_FUNC void func_8002835C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002835C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028364: lui         $at, 0x4484
    ctx->r1 = S32(0X4484 << 16);
    // 0x80028368: lwc1        $f0, 0x88($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8002836C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028370: lui         $at, 0x4482
    ctx->r1 = S32(0X4482 << 16);
    // 0x80028374: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80028378: nop

    // 0x8002837C: bc1fl       L_80028398
    if (!c1cs) {
        // 0x80028380: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80028398;
    }
    goto skip_0;
    // 0x80028380: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x80028384: jal         0x800677F8
    // 0x80028388: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x80028388: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x8002838C: b           L_800283B8
    // 0x80028390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800283B8;
    // 0x80028390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028394: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80028398:
    // 0x80028398: nop

    // 0x8002839C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800283A0: nop

    // 0x800283A4: bc1fl       L_800283B8
    if (!c1cs) {
        // 0x800283A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800283B8;
    }
    goto skip_1;
    // 0x800283A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800283AC: jal         0x800677F8
    // 0x800283B0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x800283B0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_1:
    // 0x800283B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800283B8:
    // 0x800283B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800283BC: jr          $ra
    // 0x800283C0: nop

    return;
    // 0x800283C0: nop

;}
RECOMP_FUNC void func_805216C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805216C0: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(309, 0X10) << 16);
    // 0x805216C4: addiu       $v0, $v0, 0x16D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(309, 0X10));
    // 0x805216C8: jr          $ra
    // 0x805216CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805216CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80674448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80674448: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8067444C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80674450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80674454: jal         0x8004700C
    // 0x80674458: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80674458: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8067445C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80674460: jal         0x806741B8
    // 0x80674464: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_806741B8(rdram, ctx);
        goto after_1;
    // 0x80674464: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80674468: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8067446C: beql        $v1, $zero, L_806744D0
    if (ctx->r3 == 0) {
        // 0x80674470: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806744D0;
    }
    goto skip_0;
    // 0x80674470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80674474: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80674478: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8067447C: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x80674480: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80674484: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80674488: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8067448C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80674490: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80674494: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80674498: nop

    // 0x8067449C: bc1fl       L_806744D0
    if (!c1cs) {
        // 0x806744A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806744D0;
    }
    goto skip_1;
    // 0x806744A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806744A4: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x806744A8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x806744AC: jal         0x8067302C
    // 0x806744B0: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    func_8067302C(rdram, ctx);
        goto after_2;
    // 0x806744B0: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    after_2:
    // 0x806744B4: sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
    // 0x806744B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806744BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806744C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806744C4: jal         0x806748E4
    // 0x806744C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806748E4(rdram, ctx);
        goto after_3;
    // 0x806744C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x806744CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806744D0:
    // 0x806744D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806744D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806744D8: jr          $ra
    // 0x806744DC: nop

    return;
    // 0x806744DC: nop

;}
RECOMP_FUNC void func_80076BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076BF0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80076BF4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80076BF8: bltz        $a3, L_80076D04
    if (SIGNED(ctx->r7) < 0) {
        // 0x80076BFC: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80076D04;
    }
    // 0x80076BFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80076C00: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
    // 0x80076C04: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80076C08: lui         $v1, 0xE700
    ctx->r3 = S32(0XE700 << 16);
    // 0x80076C0C: bltz        $a1, L_80076D04
    if (SIGNED(ctx->r5) < 0) {
        // 0x80076C10: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80076D04;
    }
    // 0x80076C10: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076C14: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80076C18: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80076C1C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80076C20: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80076C24: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x80076C28: lui         $t7, 0x30
    ctx->r15 = S32(0X30 << 16);
    // 0x80076C2C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80076C30: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80076C34: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076C38: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80076C3C: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80076C40: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x80076C44: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80076C48: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80076C4C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076C50: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80076C54: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80076C58: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x80076C5C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80076C60: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80076C64: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076C68: lhu         $t0, 0x16($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X16);
    // 0x80076C6C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80076C70: sll         $t3, $t0, 16
    ctx->r11 = S32(ctx->r8 << 16);
    // 0x80076C74: or          $t4, $t3, $t0
    ctx->r12 = ctx->r11 | ctx->r8;
    // 0x80076C78: lui         $t2, 0xF700
    ctx->r10 = S32(0XF700 << 16);
    // 0x80076C7C: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80076C80: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x80076C84: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076C88: andi        $t5, $a3, 0x3FF
    ctx->r13 = ctx->r7 & 0X3FF;
    // 0x80076C8C: sll         $t6, $t5, 14
    ctx->r14 = S32(ctx->r13 << 14);
    // 0x80076C90: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x80076C94: andi        $t8, $a1, 0x3FF
    ctx->r24 = ctx->r5 & 0X3FF;
    // 0x80076C98: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80076C9C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80076CA0: or          $t2, $t7, $t9
    ctx->r10 = ctx->r15 | ctx->r25;
    // 0x80076CA4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80076CA8: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80076CAC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80076CB0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076CB4: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x80076CB8: bgez        $t3, L_80076CC8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80076CBC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80076CC8;
    }
    // 0x80076CBC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80076CC0: b           L_80076CCC
    // 0x80076CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80076CCC;
    // 0x80076CC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80076CC8:
    // 0x80076CC8: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
L_80076CCC:
    // 0x80076CCC: bgez        $t4, L_80076CDC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80076CD0: andi        $t8, $a1, 0x3FF
        ctx->r24 = ctx->r5 & 0X3FF;
            goto L_80076CDC;
    }
    // 0x80076CD0: andi        $t8, $a1, 0x3FF
    ctx->r24 = ctx->r5 & 0X3FF;
    // 0x80076CD4: b           L_80076CE0
    // 0x80076CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80076CE0;
    // 0x80076CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80076CDC:
    // 0x80076CDC: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
L_80076CE0:
    // 0x80076CE0: andi        $t5, $a2, 0x3FF
    ctx->r13 = ctx->r6 & 0X3FF;
    // 0x80076CE4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80076CE8: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x80076CEC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80076CF0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80076CF4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076CF8: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x80076CFC: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80076D00: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80076D04:
    // 0x80076D04: jr          $ra
    // 0x80076D08: nop

    return;
    // 0x80076D08: nop

;}
