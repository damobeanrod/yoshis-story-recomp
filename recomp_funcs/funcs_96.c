#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_807C4100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C4100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C4104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C4108: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807C410C: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(907, 0X1470) << 16);
    // 0x807C4110: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807C4114: addiu       $t6, $t6, 0x47D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(907, 0X1470));
    // 0x807C4118: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807C411C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807C4120: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
    // 0x807C4124: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807C4128: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807C412C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C4130: jal         0x807C4148
    // 0x807C4134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_807C4148(rdram, ctx);
        goto after_0;
    // 0x807C4134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x807C4138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C413C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C4140: jr          $ra
    // 0x807C4144: nop

    return;
    // 0x807C4144: nop

;}
RECOMP_FUNC void func_806730B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806730B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806730B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806730B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806730BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806730C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806730C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x806730C8: jal         0x80062AEC
    // 0x806730CC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x806730CC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x806730D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806730D4: beq         $v0, $at, L_80673100
    if (ctx->r2 == ctx->r1) {
        // 0x806730D8: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80673100;
    }
    // 0x806730D8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806730DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806730E0: beq         $v0, $at, L_80673134
    if (ctx->r2 == ctx->r1) {
        // 0x806730E4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80673134;
    }
    // 0x806730E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806730E8: beq         $v0, $at, L_80673168
    if (ctx->r2 == ctx->r1) {
        // 0x806730EC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80673168;
    }
    // 0x806730EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806730F0: beq         $v0, $at, L_8067319C
    if (ctx->r2 == ctx->r1) {
        // 0x806730F4: nop
    
            goto L_8067319C;
    }
    // 0x806730F4: nop

    // 0x806730F8: b           L_806731D0
    // 0x806730FC: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
        goto L_806731D0;
    // 0x806730FC: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
L_80673100:
    // 0x80673100: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C1C) << 16);
    // 0x80673104: lwc1        $f4, 0x4BFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C1C));
    // 0x80673108: lwc1        $f0, 0xC4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x8067310C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80673110: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80673114: nop

    // 0x80673118: bc1fl       L_806731D0
    if (!c1cs) {
        // 0x8067311C: lw          $a0, 0x34($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X34);
            goto L_806731D0;
    }
    goto skip_0;
    // 0x8067311C: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    skip_0:
    // 0x80673120: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80673124: nop

    // 0x80673128: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8067312C: b           L_806731CC
    // 0x80673130: swc1        $f8, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f8.u32l;
        goto L_806731CC;
    // 0x80673130: swc1        $f8, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f8.u32l;
L_80673134:
    // 0x80673134: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C20) << 16);
    // 0x80673138: lwc1        $f10, 0x4C00($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C20));
    // 0x8067313C: lwc1        $f0, 0xC4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC4);
    // 0x80673140: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80673144: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80673148: nop

    // 0x8067314C: bc1fl       L_806731D0
    if (!c1cs) {
        // 0x80673150: lw          $a0, 0x34($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X34);
            goto L_806731D0;
    }
    goto skip_1;
    // 0x80673150: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    skip_1:
    // 0x80673154: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80673158: nop

    // 0x8067315C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80673160: b           L_806731CC
    // 0x80673164: swc1        $f18, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f18.u32l;
        goto L_806731CC;
    // 0x80673164: swc1        $f18, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->f18.u32l;
L_80673168:
    // 0x80673168: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C24) << 16);
    // 0x8067316C: lwc1        $f4, 0x4C04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C24));
    // 0x80673170: lwc1        $f0, 0xC8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x80673174: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80673178: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8067317C: nop

    // 0x80673180: bc1fl       L_806731D0
    if (!c1cs) {
        // 0x80673184: lw          $a0, 0x34($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X34);
            goto L_806731D0;
    }
    goto skip_2;
    // 0x80673184: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    skip_2:
    // 0x80673188: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067318C: nop

    // 0x80673190: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80673194: b           L_806731CC
    // 0x80673198: swc1        $f8, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f8.u32l;
        goto L_806731CC;
    // 0x80673198: swc1        $f8, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f8.u32l;
L_8067319C:
    // 0x8067319C: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(529, 0X1C28) << 16);
    // 0x806731A0: lwc1        $f10, 0x4C08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(529, 0X1C28));
    // 0x806731A4: lwc1        $f0, 0xC8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x806731A8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806731AC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x806731B0: nop

    // 0x806731B4: bc1fl       L_806731D0
    if (!c1cs) {
        // 0x806731B8: lw          $a0, 0x34($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X34);
            goto L_806731D0;
    }
    goto skip_3;
    // 0x806731B8: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    skip_3:
    // 0x806731BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806731C0: nop

    // 0x806731C4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x806731C8: swc1        $f18, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f18.u32l;
L_806731CC:
    // 0x806731CC: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
L_806731D0:
    // 0x806731D0: jal         0x80067BBC
    // 0x806731D4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x806731D4: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_1:
    // 0x806731D8: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x806731DC: jal         0x80067818
    // 0x806731E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x806731E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x806731E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806731E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806731EC: jr          $ra
    // 0x806731F0: nop

    return;
    // 0x806731F0: nop

;}
RECOMP_FUNC void func_8057FD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057FD70: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8057FD74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057FD78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057FD7C: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8057FD80: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8057FD84: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8057FD88: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8057FD8C: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8057FD90: jal         0x8057FCCC
    // 0x8057FD94: lh          $a1, 0x144($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X144);
    func_8057FCCC(rdram, ctx);
        goto after_0;
    // 0x8057FD94: lh          $a1, 0x144($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X144);
    after_0:
    // 0x8057FD98: sh          $v0, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r2;
    // 0x8057FD9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FDA0: jal         0x8004921C
    // 0x8057FDA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8057FDA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8057FDA8: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x8057FDAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FDB0: jal         0x8004921C
    // 0x8057FDB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x8057FDB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8057FDB8: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x8057FDBC: lh          $t1, 0x9A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9A);
    // 0x8057FDC0: lw          $t3, 0x168($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X168);
    // 0x8057FDC4: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8057FDC8: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FDCC: lw          $t4, 0x80($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X80);
    // 0x8057FDD0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8057FDD4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8057FDD8: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8057FDDC: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8057FDE0: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8057FDE4: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FDE8: lui         $t3, 0x8
    ctx->r11 = S32(0X8 << 16);
    // 0x8057FDEC: mflo        $t9
    ctx->r25 = lo;
    // 0x8057FDF0: ori         $t3, $t3, 0xAC80
    ctx->r11 = ctx->r11 | 0XAC80;
    // 0x8057FDF4: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x8057FDF8: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8057FDFC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8057FE00: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8057FE04: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x8057FE08: ori         $t1, $t1, 0x18
    ctx->r9 = ctx->r9 | 0X18;
    // 0x8057FE0C: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8057FE10: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8057FE14: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x8057FE18: ori         $a1, $a1, 0x2078
    ctx->r5 = ctx->r5 | 0X2078;
    // 0x8057FE1C: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x8057FE20: mflo        $t2
    ctx->r10 = lo;
    // 0x8057FE24: addu        $t0, $t2, $t4
    ctx->r8 = ADD32(ctx->r10, ctx->r12);
    // 0x8057FE28: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FE2C: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8057FE30: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8057FE34: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x8057FE38: sw          $t4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r12;
    // 0x8057FE3C: sw          $a1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r5;
    // 0x8057FE40: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x8057FE44: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FE48: lui         $t2, 0x1F
    ctx->r10 = S32(0X1F << 16);
    // 0x8057FE4C: ori         $t2, $t2, 0x3205
    ctx->r10 = ctx->r10 | 0X3205;
    // 0x8057FE50: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8057FE54: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x8057FE58: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    // 0x8057FE5C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8057FE60: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FE64: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x8057FE68: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x8057FE6C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8057FE70: sw          $t1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r9;
    // 0x8057FE74: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x8057FE78: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x8057FE7C: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FE80: ori         $t7, $t7, 0x2205
    ctx->r15 = ctx->r15 | 0X2205;
    // 0x8057FE84: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x8057FE88: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8057FE8C: sw          $t5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r13;
    // 0x8057FE90: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8057FE94: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8057FE98: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    // 0x8057FE9C: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8057FEA0: bnel        $t8, $zero, L_8057FED0
    if (ctx->r24 != 0) {
        // 0x8057FEA4: lw          $t4, 0x9C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X9C);
            goto L_8057FED0;
    }
    goto skip_0;
    // 0x8057FEA4: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    skip_0:
    // 0x8057FEA8: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FEAC: lui         $t2, 0x8058
    ctx->r10 = S32(RELOC_HI16(399, 0X4458) << 16);
    // 0x8057FEB0: addiu       $t2, $t2, 0x3268
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(399, 0X4458));
    // 0x8057FEB4: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x8057FEB8: sw          $t1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r9;
    // 0x8057FEBC: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8057FEC0: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x8057FEC4: b           L_8057FEEC
    // 0x8057FEC8: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
        goto L_8057FEEC;
    // 0x8057FEC8: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x8057FECC: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
L_8057FED0:
    // 0x8057FED0: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(399, 0X4498) << 16);
    // 0x8057FED4: addiu       $t7, $t7, 0x32A8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(399, 0X4498));
    // 0x8057FED8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8057FEDC: sw          $t5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r13;
    // 0x8057FEE0: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8057FEE4: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8057FEE8: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
L_8057FEEC:
    // 0x8057FEEC: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FEF0: lui         $t1, 0xFC12
    ctx->r9 = S32(0XFC12 << 16);
    // 0x8057FEF4: ori         $t1, $t1, 0x7E24
    ctx->r9 = ctx->r9 | 0X7E24;
    // 0x8057FEF8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8057FEFC: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x8057FF00: addiu       $t3, $zero, -0xC07
    ctx->r11 = ADD32(0, -0XC07);
    // 0x8057FF04: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8057FF08: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8057FF0C: lw          $t2, 0x168($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X168);
    // 0x8057FF10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8057FF14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8057FF18: lw          $a3, 0x88($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X88);
    // 0x8057FF1C: jal         0x8007711C
    // 0x8057FF20: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8057FF20: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    after_3:
    // 0x8057FF24: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FF28: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x8057FF2C: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8057FF30: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8057FF34: sw          $t5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r13;
    // 0x8057FF38: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8057FF3C: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x8057FF40: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FF44: lui         $t1, 0x700
    ctx->r9 = S32(0X700 << 16);
    // 0x8057FF48: ori         $t1, $t1, 0x3C0F
    ctx->r9 = ctx->r9 | 0X3C0F;
    // 0x8057FF4C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8057FF50: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8057FF54: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8057FF58: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8057FF5C: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x8057FF60: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FF64: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x8057FF68: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8057FF6C: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x8057FF70: sw          $t2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r10;
    // 0x8057FF74: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8057FF78: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x8057FF7C: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x8057FF80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FF84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8057FF88: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8057FF8C: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x8057FF90: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8057FF94: jal         0x8004921C
    // 0x8057FF98: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x8057FF98: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    after_4:
    // 0x8057FF9C: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x8057FFA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FFA4: jal         0x8004921C
    // 0x8057FFA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x8057FFA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8057FFAC: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x8057FFB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FFB4: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8057FFB8: mflo        $t9
    ctx->r25 = lo;
    // 0x8057FFBC: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8057FFC0: sra         $t3, $t1, 1
    ctx->r11 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8057FFC4: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x8057FFC8: slti        $at, $t2, 0x7FF
    ctx->r1 = SIGNED(ctx->r10) < 0X7FF ? 1 : 0;
    // 0x8057FFCC: beq         $at, $zero, L_8058000C
    if (ctx->r1 == 0) {
        // 0x8057FFD0: addiu       $t9, $zero, 0x7FF
        ctx->r25 = ADD32(0, 0X7FF);
            goto L_8058000C;
    }
    // 0x8057FFD0: addiu       $t9, $zero, 0x7FF
    ctx->r25 = ADD32(0, 0X7FF);
    // 0x8057FFD4: jal         0x8004921C
    // 0x8057FFD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_6;
    // 0x8057FFD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8057FFDC: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8057FFE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057FFE4: jal         0x8004921C
    // 0x8057FFE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_7;
    // 0x8057FFE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8057FFEC: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x8057FFF0: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8057FFF4: mflo        $t5
    ctx->r13 = lo;
    // 0x8057FFF8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8057FFFC: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80580000: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80580004: b           L_80580010
    // 0x80580008: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
        goto L_80580010;
    // 0x80580008: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_8058000C:
    // 0x8058000C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_80580010:
    // 0x80580010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80580014: jal         0x8004921C
    // 0x80580018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_8;
    // 0x80580018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8058001C: bgez        $v0, L_8058002C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80580020: sra         $t1, $v0, 3
        ctx->r9 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8058002C;
    }
    // 0x80580020: sra         $t1, $v0, 3
    ctx->r9 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80580024: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80580028: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_8058002C:
    // 0x8058002C: bgtz        $t1, L_8058003C
    if (SIGNED(ctx->r9) > 0) {
        // 0x80580030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8058003C;
    }
    // 0x80580030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80580034: b           L_80580054
    // 0x80580038: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80580054;
    // 0x80580038: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8058003C:
    // 0x8058003C: jal         0x8004921C
    // 0x80580040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_9;
    // 0x80580040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80580044: bgez        $v0, L_80580054
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80580048: sra         $a3, $v0, 3
        ctx->r7 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80580054;
    }
    // 0x80580048: sra         $a3, $v0, 3
    ctx->r7 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8058004C: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80580050: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_80580054:
    // 0x80580054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80580058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8058005C: jal         0x8004921C
    // 0x80580060: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_10;
    // 0x80580060: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_10:
    // 0x80580064: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80580068: bgez        $v0, L_80580078
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8058006C: sra         $t3, $v0, 3
        ctx->r11 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80580078;
    }
    // 0x8058006C: sra         $t3, $v0, 3
    ctx->r11 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80580070: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80580074: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_80580078:
    // 0x80580078: bgtzl       $t3, L_8058008C
    if (SIGNED(ctx->r11) > 0) {
        // 0x8058007C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8058008C;
    }
    goto skip_1;
    // 0x8058007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80580080: b           L_805800AC
    // 0x80580084: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805800AC;
    // 0x80580084: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80580088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8058008C:
    // 0x8058008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80580090: jal         0x8004921C
    // 0x80580094: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_11;
    // 0x80580094: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_11:
    // 0x80580098: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8058009C: bgez        $v0, L_805800AC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x805800A0: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_805800AC;
    }
    // 0x805800A0: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805800A4: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x805800A8: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_805800AC:
    // 0x805800AC: addiu       $t2, $a3, 0x7FF
    ctx->r10 = ADD32(ctx->r7, 0X7FF);
    // 0x805800B0: div         $zero, $t2, $v1
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r3)));
    // 0x805800B4: bne         $v1, $zero, L_805800C0
    if (ctx->r3 != 0) {
        // 0x805800B8: nop
    
            goto L_805800C0;
    }
    // 0x805800B8: nop

    // 0x805800BC: break       7
    do_break(2153251004);
L_805800C0:
    // 0x805800C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805800C4: bne         $v1, $at, L_805800D8
    if (ctx->r3 != ctx->r1) {
        // 0x805800C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805800D8;
    }
    // 0x805800C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805800CC: bne         $t2, $at, L_805800D8
    if (ctx->r10 != ctx->r1) {
        // 0x805800D0: nop
    
            goto L_805800D8;
    }
    // 0x805800D0: nop

    // 0x805800D4: break       6
    do_break(2153251028);
L_805800D8:
    // 0x805800D8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x805800DC: mflo        $t4
    ctx->r12 = lo;
    // 0x805800E0: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x805800E4: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x805800E8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x805800EC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x805800F0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x805800F4: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x805800F8: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x805800FC: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x80580100: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80580104: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80580108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8058010C: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x80580110: sw          $t4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r12;
    // 0x80580114: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80580118: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x8058011C: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80580120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80580124: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80580128: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x8058012C: jal         0x8004921C
    // 0x80580130: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_12;
    // 0x80580130: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    after_12:
    // 0x80580134: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x80580138: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8058013C: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80580140: andi        $t1, $t9, 0x1FF
    ctx->r9 = ctx->r25 & 0X1FF;
    // 0x80580144: sll         $t3, $t1, 9
    ctx->r11 = S32(ctx->r9 << 9);
    // 0x80580148: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8058014C: or          $t2, $t3, $at
    ctx->r10 = ctx->r11 | ctx->r1;
    // 0x80580150: addiu       $t4, $zero, 0x3C0F
    ctx->r12 = ADD32(0, 0X3C0F);
    // 0x80580154: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x80580158: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x8058015C: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x80580160: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80580164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80580168: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x8058016C: sw          $t7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r15;
    // 0x80580170: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80580174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80580178: jal         0x8004921C
    // 0x8058017C: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    func_8004921C(rdram, ctx);
        goto after_13;
    // 0x8058017C: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    after_13:
    // 0x80580180: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80580184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80580188: jal         0x8004921C
    // 0x8058018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_14;
    // 0x8058018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80580190: lh          $t3, 0x36($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X36);
    // 0x80580194: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80580198: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8058019C: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x805801A0: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x805801A4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x805801A8: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x805801AC: sll         $t7, $t5, 12
    ctx->r15 = S32(ctx->r13 << 12);
    // 0x805801B0: andi        $t1, $t9, 0xFFF
    ctx->r9 = ctx->r25 & 0XFFF;
    // 0x805801B4: or          $t8, $t1, $t7
    ctx->r24 = ctx->r9 | ctx->r15;
    // 0x805801B8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x805801BC: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x805801C0: lui         $t4, 0x8058
    ctx->r12 = S32(RELOC_HI16(399, 0X4248) << 16);
    // 0x805801C4: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x805801C8: addiu       $t3, $t9, 0x8
    ctx->r11 = ADD32(ctx->r25, 0X8);
    // 0x805801CC: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
    // 0x805801D0: ori         $t2, $t2, 0x617F
    ctx->r10 = ctx->r10 | 0X617F;
    // 0x805801D4: addiu       $t4, $t4, 0x3058
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(399, 0X4248));
    // 0x805801D8: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x805801DC: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x805801E0: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x805801E4: lui         $t8, 0x6
    ctx->r24 = S32(0X6 << 16);
    // 0x805801E8: lui         $t7, 0xB106
    ctx->r15 = S32(0XB106 << 16);
    // 0x805801EC: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x805801F0: sw          $t1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r9;
    // 0x805801F4: ori         $t7, $t7, 0x204
    ctx->r15 = ctx->r15 | 0X204;
    // 0x805801F8: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x805801FC: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x80580200: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x80580204: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x80580208: lui         $t2, 0xA
    ctx->r10 = S32(0XA << 16);
    // 0x8058020C: lui         $t3, 0xB10A
    ctx->r11 = S32(0XB10A << 16);
    // 0x80580210: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80580214: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x80580218: ori         $t3, $t3, 0xC0E
    ctx->r11 = ctx->r11 | 0XC0E;
    // 0x8058021C: ori         $t2, $t2, 0xE08
    ctx->r10 = ctx->r10 | 0XE08;
    // 0x80580220: sw          $t2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r10;
    // 0x80580224: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x80580228: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x8058022C: lui         $t7, 0x12
    ctx->r15 = S32(0X12 << 16);
    // 0x80580230: lui         $t1, 0xB112
    ctx->r9 = S32(0XB112 << 16);
    // 0x80580234: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80580238: sw          $t5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r13;
    // 0x8058023C: ori         $t1, $t1, 0x1416
    ctx->r9 = ctx->r9 | 0X1416;
    // 0x80580240: ori         $t7, $t7, 0x1610
    ctx->r15 = ctx->r15 | 0X1610;
    // 0x80580244: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80580248: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x8058024C: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80580250: lui         $t3, 0x1E
    ctx->r11 = S32(0X1E << 16);
    // 0x80580254: lui         $t9, 0xB11E
    ctx->r25 = S32(0XB11E << 16);
    // 0x80580258: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8058025C: sw          $t6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r14;
    // 0x80580260: ori         $t9, $t9, 0x1A1C
    ctx->r25 = ctx->r25 | 0X1A1C;
    // 0x80580264: ori         $t3, $t3, 0x1C18
    ctx->r11 = ctx->r11 | 0X1C18;
    // 0x80580268: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8058026C: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80580270: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80580274: lui         $t1, 0x22
    ctx->r9 = S32(0X22 << 16);
    // 0x80580278: lui         $t5, 0xB122
    ctx->r13 = S32(0XB122 << 16);
    // 0x8058027C: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x80580280: sw          $t4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r12;
    // 0x80580284: ori         $t5, $t5, 0x2426
    ctx->r13 = ctx->r13 | 0X2426;
    // 0x80580288: ori         $t1, $t1, 0x2620
    ctx->r9 = ctx->r9 | 0X2620;
    // 0x8058028C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80580290: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x80580294: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x80580298: lui         $t9, 0x2A
    ctx->r25 = S32(0X2A << 16);
    // 0x8058029C: lui         $t6, 0xB12A
    ctx->r14 = S32(0XB12A << 16);
    // 0x805802A0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x805802A4: sw          $t8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r24;
    // 0x805802A8: ori         $t6, $t6, 0x2C2E
    ctx->r14 = ctx->r14 | 0X2C2E;
    // 0x805802AC: ori         $t9, $t9, 0x2E28
    ctx->r25 = ctx->r25 | 0X2E28;
    // 0x805802B0: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x805802B4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805802B8: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x805802BC: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x805802C0: sw          $t3, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r11;
    // 0x805802C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805802C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805802CC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x805802D0: jr          $ra
    // 0x805802D4: nop

    return;
    // 0x805802D4: nop

;}
RECOMP_FUNC void func_806D9100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9100: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(628, 0X2D0) << 16);
    // 0x806D9104: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D9108: addiu       $t7, $t7, -0x6E70
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(628, 0X2D0));
    // 0x806D910C: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x806D9110: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806D9114: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(628, 0X770) << 16);
    // 0x806D9118: lwc1        $f4, -0x69D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(628, 0X770));
    // 0x806D911C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806D9120: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D9124: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x806D9128: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x806D912C: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    // 0x806D9130: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x806D9134: jr          $ra
    // 0x806D9138: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x806D9138: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8052CBF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052CBF8: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8052CBFC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8052CC00: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8052CC04: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8052CC08: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8052CC0C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8052CC10: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8052CC14: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8052CC18: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x8052CC1C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8052CC20: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8052CC24: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8052CC28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8052CC2C: jal         0x8004921C
    // 0x8052CC30: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8052CC30: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    after_0:
    // 0x8052CC34: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8052CC38: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8052CC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CC40: jal         0x8004921C
    // 0x8052CC44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8052CC44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8052CC48: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8052CC4C: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x8052CC50: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8052CC54: lbu         $t7, 0x145($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X145);
    // 0x8052CC58: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x8052CC5C: lw          $a3, 0x1F4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1F4);
    // 0x8052CC60: addiu       $s4, $sp, 0x98
    ctx->r20 = ADD32(ctx->r29, 0X98);
    // 0x8052CC64: lw          $t9, 0x80($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X80);
    // 0x8052CC68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8052CC6C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8052CC70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8052CC74: lw          $s3, 0x88($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X88);
    // 0x8052CC78: mflo        $t6
    ctx->r14 = lo;
    // 0x8052CC7C: addiu       $s5, $a3, 0xC8
    ctx->r21 = ADD32(ctx->r7, 0XC8);
    // 0x8052CC80: nop

    // 0x8052CC84: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8052CC88: mflo        $t8
    ctx->r24 = lo;
    // 0x8052CC8C: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x8052CC90: jal         0x80077338
    // 0x8052CC94: nop

    func_80077338(rdram, ctx);
        goto after_2;
    // 0x8052CC94: nop

    after_2:
    // 0x8052CC98: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8052CC9C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8052CCA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8052CCA4: jal         0x8007711C
    // 0x8052CCA8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8052CCA8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_3:
    // 0x8052CCAC: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8052CCB0: lui         $t8, 0xFD50
    ctx->r24 = S32(0XFD50 << 16);
    // 0x8052CCB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CCB8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8052CCBC: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x8052CCC0: sw          $s2, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r18;
    // 0x8052CCC4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8052CCC8: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8052CCCC: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x8052CCD0: ori         $t8, $t8, 0x60
    ctx->r24 = ctx->r24 | 0X60;
    // 0x8052CCD4: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8052CCD8: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x8052CCDC: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x8052CCE0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8052CCE4: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8052CCE8: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8052CCEC: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8052CCF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8052CCF4: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8052CCF8: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x8052CCFC: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8052CD00: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8052CD04: lw          $s4, 0x98($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X98);
    // 0x8052CD08: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8052CD0C: addiu       $t9, $s4, 0x8
    ctx->r25 = ADD32(ctx->r20, 0X8);
    // 0x8052CD10: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052CD14: jal         0x8004921C
    // 0x8052CD18: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x8052CD18: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    after_4:
    // 0x8052CD1C: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8052CD20: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8052CD24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CD28: jal         0x8004921C
    // 0x8052CD2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x8052CD2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8052CD30: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8052CD34: mflo        $t7
    ctx->r15 = lo;
    // 0x8052CD38: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8052CD3C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8052CD40: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8052CD44: slti        $at, $t6, 0x7FF
    ctx->r1 = SIGNED(ctx->r14) < 0X7FF ? 1 : 0;
    // 0x8052CD48: beq         $at, $zero, L_8052CD84
    if (ctx->r1 == 0) {
        // 0x8052CD4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8052CD84;
    }
    // 0x8052CD4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CD50: jal         0x8004921C
    // 0x8052CD54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_6;
    // 0x8052CD54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8052CD58: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8052CD5C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8052CD60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CD64: jal         0x8004921C
    // 0x8052CD68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_7;
    // 0x8052CD68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8052CD6C: multu       $v0, $s1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8052CD70: mflo        $s3
    ctx->r19 = lo;
    // 0x8052CD74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8052CD78: sra         $s3, $s3, 1
    ctx->r19 = S32(SIGNED(ctx->r19) >> 1);
    // 0x8052CD7C: b           L_8052CD88
    // 0x8052CD80: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
        goto L_8052CD88;
    // 0x8052CD80: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
L_8052CD84:
    // 0x8052CD84: addiu       $s3, $zero, 0x7FF
    ctx->r19 = ADD32(0, 0X7FF);
L_8052CD88:
    // 0x8052CD88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CD8C: jal         0x8004921C
    // 0x8052CD90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_8;
    // 0x8052CD90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8052CD94: bgez        $v0, L_8052CDA4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8052CD98: sra         $t7, $v0, 3
        ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8052CDA4;
    }
    // 0x8052CD98: sra         $t7, $v0, 3
    ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8052CD9C: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8052CDA0: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_8052CDA4:
    // 0x8052CDA4: bgtz        $t7, L_8052CDB4
    if (SIGNED(ctx->r15) > 0) {
        // 0x8052CDA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8052CDB4;
    }
    // 0x8052CDA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CDAC: b           L_8052CDCC
    // 0x8052CDB0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8052CDCC;
    // 0x8052CDB0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8052CDB4:
    // 0x8052CDB4: jal         0x8004921C
    // 0x8052CDB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_9;
    // 0x8052CDB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8052CDBC: bgez        $v0, L_8052CDCC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8052CDC0: sra         $s2, $v0, 3
        ctx->r18 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8052CDCC;
    }
    // 0x8052CDC0: sra         $s2, $v0, 3
    ctx->r18 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8052CDC4: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8052CDC8: sra         $s2, $at, 3
    ctx->r18 = S32(SIGNED(ctx->r1) >> 3);
L_8052CDCC:
    // 0x8052CDCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CDD0: jal         0x8004921C
    // 0x8052CDD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_10;
    // 0x8052CDD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8052CDD8: bgez        $v0, L_8052CDE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8052CDDC: sra         $t8, $v0, 3
        ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8052CDE8;
    }
    // 0x8052CDDC: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8052CDE0: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8052CDE4: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_8052CDE8:
    // 0x8052CDE8: bgtzl       $t8, L_8052CDFC
    if (SIGNED(ctx->r24) > 0) {
        // 0x8052CDEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8052CDFC;
    }
    goto skip_0;
    // 0x8052CDEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8052CDF0: b           L_8052CE14
    // 0x8052CDF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8052CE14;
    // 0x8052CDF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8052CDF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8052CDFC:
    // 0x8052CDFC: jal         0x8004921C
    // 0x8052CE00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_11;
    // 0x8052CE00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8052CE04: bgez        $v0, L_8052CE14
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8052CE08: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_8052CE14;
    }
    // 0x8052CE08: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8052CE0C: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x8052CE10: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_8052CE14:
    // 0x8052CE14: addiu       $t9, $s2, 0x7FF
    ctx->r25 = ADD32(ctx->r18, 0X7FF);
    // 0x8052CE18: div         $zero, $t9, $v1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r3)));
    // 0x8052CE1C: bne         $v1, $zero, L_8052CE28
    if (ctx->r3 != 0) {
        // 0x8052CE20: nop
    
            goto L_8052CE28;
    }
    // 0x8052CE20: nop

    // 0x8052CE24: break       7
    do_break(2152910372);
L_8052CE28:
    // 0x8052CE28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8052CE2C: bne         $v1, $at, L_8052CE40
    if (ctx->r3 != ctx->r1) {
        // 0x8052CE30: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8052CE40;
    }
    // 0x8052CE30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8052CE34: bne         $t9, $at, L_8052CE40
    if (ctx->r25 != ctx->r1) {
        // 0x8052CE38: nop
    
            goto L_8052CE40;
    }
    // 0x8052CE38: nop

    // 0x8052CE3C: break       6
    do_break(2152910396);
L_8052CE40:
    // 0x8052CE40: mflo        $t6
    ctx->r14 = lo;
    // 0x8052CE44: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8052CE48: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8052CE4C: andi        $t9, $s3, 0xFFF
    ctx->r25 = ctx->r19 & 0XFFF;
    // 0x8052CE50: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8052CE54: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8052CE58: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8052CE5C: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x8052CE60: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8052CE64: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8052CE68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CE6C: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8052CE70: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052CE74: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8052CE78: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8052CE7C: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8052CE80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8052CE84: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8052CE88: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052CE8C: jal         0x8004921C
    // 0x8052CE90: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    func_8004921C(rdram, ctx);
        goto after_12;
    // 0x8052CE90: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    after_12:
    // 0x8052CE94: addiu       $t8, $v0, 0x7
    ctx->r24 = ADD32(ctx->r2, 0X7);
    // 0x8052CE98: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8052CE9C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8052CEA0: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x8052CEA4: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8052CEA8: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8052CEAC: addiu       $t6, $zero, 0x60
    ctx->r14 = ADD32(0, 0X60);
    // 0x8052CEB0: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x8052CEB4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8052CEB8: lw          $s2, 0x98($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X98);
    // 0x8052CEBC: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8052CEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CEC4: addiu       $t9, $s2, 0x8
    ctx->r25 = ADD32(ctx->r18, 0X8);
    // 0x8052CEC8: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052CECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8052CED0: jal         0x8004921C
    // 0x8052CED4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_13;
    // 0x8052CED4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    after_13:
    // 0x8052CED8: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x8052CEDC: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8052CEE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8052CEE4: jal         0x8004921C
    // 0x8052CEE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_14;
    // 0x8052CEE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8052CEEC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8052CEF0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8052CEF4: addiu       $t8, $s1, -0x1
    ctx->r24 = ADD32(ctx->r17, -0X1);
    // 0x8052CEF8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8052CEFC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8052CF00: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8052CF04: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8052CF08: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8052CF0C: sw          $t6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r14;
    // 0x8052CF10: jal         0x8052C9FC
    // 0x8052CF14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8052C9FC(rdram, ctx);
        goto after_15;
    // 0x8052CF14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8052CF18: addiu       $s4, $zero, 0x32
    ctx->r20 = ADD32(0, 0X32);
    // 0x8052CF1C: addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
    // 0x8052CF20: lui         $t1, 0xBF00
    ctx->r9 = S32(0XBF00 << 16);
    // 0x8052CF24: slti        $at, $s4, 0x21
    ctx->r1 = SIGNED(ctx->r20) < 0X21 ? 1 : 0;
    // 0x8052CF28: bnel        $at, $zero, L_8052D1C8
    if (ctx->r1 != 0) {
        // 0x8052CF2C: lw          $v0, 0x98($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X98);
            goto L_8052D1C8;
    }
    goto skip_1;
    // 0x8052CF2C: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    skip_1:
L_8052CF30:
    // 0x8052CF30: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8052CF34: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8052CF38: ori         $t8, $t8, 0x81FF
    ctx->r24 = ctx->r24 | 0X81FF;
    // 0x8052CF3C: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8052CF40: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052CF44: sw          $s5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r21;
    // 0x8052CF48: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8052CF4C: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8052CF50: addiu       $t9, $zero, 0x204
    ctx->r25 = ADD32(0, 0X204);
    // 0x8052CF54: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8052CF58: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8052CF5C: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x8052CF60: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8052CF64: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x8052CF68: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x8052CF6C: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x8052CF70: ori         $t7, $t7, 0x604
    ctx->r15 = ctx->r15 | 0X604;
    // 0x8052CF74: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8052CF78: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x8052CF7C: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8052CF80: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8052CF84: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x8052CF88: lui         $t6, 0x4
    ctx->r14 = S32(0X4 << 16);
    // 0x8052CF8C: ori         $t6, $t6, 0x608
    ctx->r14 = ctx->r14 | 0X608;
    // 0x8052CF90: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8052CF94: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052CF98: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8052CF9C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8052CFA0: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8052CFA4: lui         $t8, 0x6
    ctx->r24 = S32(0X6 << 16);
    // 0x8052CFA8: ori         $t8, $t8, 0xA08
    ctx->r24 = ctx->r24 | 0XA08;
    // 0x8052CFAC: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8052CFB0: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052CFB4: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8052CFB8: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x8052CFBC: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x8052CFC0: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x8052CFC4: ori         $t9, $t9, 0xA0C
    ctx->r25 = ctx->r25 | 0XA0C;
    // 0x8052CFC8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8052CFCC: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x8052CFD0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8052CFD4: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x8052CFD8: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x8052CFDC: lui         $t7, 0xA
    ctx->r15 = S32(0XA << 16);
    // 0x8052CFE0: ori         $t7, $t7, 0xE0C
    ctx->r15 = ctx->r15 | 0XE0C;
    // 0x8052CFE4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8052CFE8: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x8052CFEC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8052CFF0: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
L_8052CFF4:
    // 0x8052CFF4: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x8052CFF8: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8052CFFC: addiu       $t2, $a0, 0x2
    ctx->r10 = ADD32(ctx->r4, 0X2);
    // 0x8052D000: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
    // 0x8052D004: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8052D008: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8052D00C: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052D010: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8052D014: sll         $t9, $t2, 8
    ctx->r25 = S32(ctx->r10 << 8);
    // 0x8052D018: addiu       $t3, $a0, 0x4
    ctx->r11 = ADD32(ctx->r4, 0X4);
    // 0x8052D01C: andi        $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 & 0XFF;
    // 0x8052D020: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8052D024: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x8052D028: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8052D02C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8052D030: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x8052D034: addiu       $t6, $a0, 0x6
    ctx->r14 = ADD32(ctx->r4, 0X6);
    // 0x8052D038: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8052D03C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8052D040: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052D044: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x8052D048: sll         $t8, $t2, 16
    ctx->r24 = S32(ctx->r10 << 16);
    // 0x8052D04C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8052D050: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x8052D054: addiu       $a1, $t0, 0x1
    ctx->r5 = ADD32(ctx->r8, 0X1);
    // 0x8052D058: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8052D05C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8052D060: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x8052D064: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x8052D068: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x8052D06C: addiu       $t4, $a1, 0x2
    ctx->r12 = ADD32(ctx->r5, 0X2);
    // 0x8052D070: andi        $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 & 0XFF;
    // 0x8052D074: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8052D078: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8052D07C: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052D080: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8052D084: sll         $t8, $t4, 8
    ctx->r24 = S32(ctx->r12 << 8);
    // 0x8052D088: addiu       $t5, $a1, 0x4
    ctx->r13 = ADD32(ctx->r5, 0X4);
    // 0x8052D08C: andi        $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 & 0XFF;
    // 0x8052D090: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8052D094: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x8052D098: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8052D09C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8052D0A0: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x8052D0A4: addiu       $t6, $a1, 0x6
    ctx->r14 = ADD32(ctx->r5, 0X6);
    // 0x8052D0A8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8052D0AC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8052D0B0: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052D0B4: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8052D0B8: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x8052D0BC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8052D0C0: or          $t7, $t6, $t5
    ctx->r15 = ctx->r14 | ctx->r13;
    // 0x8052D0C4: addiu       $a2, $t0, 0x2
    ctx->r6 = ADD32(ctx->r8, 0X2);
    // 0x8052D0C8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8052D0CC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8052D0D0: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x8052D0D4: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8052D0D8: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8052D0DC: addiu       $ra, $a2, 0x2
    ctx->r31 = ADD32(ctx->r6, 0X2);
    // 0x8052D0E0: andi        $ra, $ra, 0xFF
    ctx->r31 = ctx->r31 & 0XFF;
    // 0x8052D0E4: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x8052D0E8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8052D0EC: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052D0F0: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8052D0F4: sll         $t9, $ra, 8
    ctx->r25 = S32(ctx->r31 << 8);
    // 0x8052D0F8: addiu       $s0, $a2, 0x4
    ctx->r16 = ADD32(ctx->r6, 0X4);
    // 0x8052D0FC: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8052D100: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8052D104: or          $t6, $t8, $s0
    ctx->r14 = ctx->r24 | ctx->r16;
    // 0x8052D108: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8052D10C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8052D110: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x8052D114: addiu       $t6, $a2, 0x6
    ctx->r14 = ADD32(ctx->r6, 0X6);
    // 0x8052D118: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8052D11C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8052D120: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052D124: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x8052D128: sll         $t8, $ra, 16
    ctx->r24 = S32(ctx->r31 << 16);
    // 0x8052D12C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8052D130: or          $t7, $t6, $s0
    ctx->r15 = ctx->r14 | ctx->r16;
    // 0x8052D134: addiu       $a3, $t0, 0x3
    ctx->r7 = ADD32(ctx->r8, 0X3);
    // 0x8052D138: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8052D13C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8052D140: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x8052D144: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x8052D148: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x8052D14C: addiu       $s1, $a3, 0x2
    ctx->r17 = ADD32(ctx->r7, 0X2);
    // 0x8052D150: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8052D154: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x8052D158: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8052D15C: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052D160: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8052D164: sll         $t8, $s1, 8
    ctx->r24 = S32(ctx->r17 << 8);
    // 0x8052D168: addiu       $s2, $a3, 0x4
    ctx->r18 = ADD32(ctx->r7, 0X4);
    // 0x8052D16C: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8052D170: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8052D174: or          $t6, $t9, $s2
    ctx->r14 = ctx->r25 | ctx->r18;
    // 0x8052D178: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8052D17C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8052D180: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x8052D184: addiu       $t6, $a3, 0x6
    ctx->r14 = ADD32(ctx->r7, 0X6);
    // 0x8052D188: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8052D18C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8052D190: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052D194: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x8052D198: sll         $t9, $s1, 16
    ctx->r25 = S32(ctx->r17 << 16);
    // 0x8052D19C: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8052D1A0: or          $t7, $t6, $s2
    ctx->r15 = ctx->r14 | ctx->r18;
    // 0x8052D1A4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8052D1A8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8052D1AC: bne         $t0, $s3, L_8052CFF4
    if (ctx->r8 != ctx->r19) {
        // 0x8052D1B0: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8052CFF4;
    }
    // 0x8052D1B0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8052D1B4: addiu       $s4, $s4, -0x1E
    ctx->r20 = ADD32(ctx->r20, -0X1E);
    // 0x8052D1B8: slti        $at, $s4, 0x21
    ctx->r1 = SIGNED(ctx->r20) < 0X21 ? 1 : 0;
    // 0x8052D1BC: beq         $at, $zero, L_8052CF30
    if (ctx->r1 == 0) {
        // 0x8052D1C0: addiu       $s5, $s5, 0x1E0
        ctx->r21 = ADD32(ctx->r21, 0X1E0);
            goto L_8052CF30;
    }
    // 0x8052D1C0: addiu       $s5, $s5, 0x1E0
    ctx->r21 = ADD32(ctx->r21, 0X1E0);
    // 0x8052D1C4: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
L_8052D1C8:
    // 0x8052D1C8: sll         $t7, $s4, 4
    ctx->r15 = S32(ctx->r20 << 4);
    // 0x8052D1CC: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x8052D1D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8052D1D4: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052D1D8: sll         $t6, $s4, 10
    ctx->r14 = S32(ctx->r20 << 10);
    // 0x8052D1DC: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8052D1E0: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x8052D1E4: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8052D1E8: addiu       $s3, $s4, -0x2
    ctx->r19 = ADD32(ctx->r20, -0X2);
    // 0x8052D1EC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8052D1F0: sra         $s3, $s3, 1
    ctx->r19 = S32(SIGNED(ctx->r19) >> 1);
    // 0x8052D1F4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8052D1F8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8052D1FC: blez        $s3, L_8052D448
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8052D200: sw          $s5, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r21;
            goto L_8052D448;
    }
    // 0x8052D200: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x8052D204: andi        $v0, $s3, 0x3
    ctx->r2 = ctx->r19 & 0X3;
    // 0x8052D208: beq         $v0, $zero, L_8052D288
    if (ctx->r2 == 0) {
        // 0x8052D20C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8052D288;
    }
    // 0x8052D20C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8052D210:
    // 0x8052D210: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x8052D214: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8052D218: addiu       $t2, $a0, 0x2
    ctx->r10 = ADD32(ctx->r4, 0X2);
    // 0x8052D21C: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
    // 0x8052D220: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x8052D224: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8052D228: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052D22C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8052D230: sll         $t9, $t2, 8
    ctx->r25 = S32(ctx->r10 << 8);
    // 0x8052D234: addiu       $t3, $a0, 0x4
    ctx->r11 = ADD32(ctx->r4, 0X4);
    // 0x8052D238: andi        $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 & 0XFF;
    // 0x8052D23C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8052D240: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x8052D244: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8052D248: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8052D24C: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x8052D250: addiu       $t7, $a0, 0x6
    ctx->r15 = ADD32(ctx->r4, 0X6);
    // 0x8052D254: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x8052D258: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8052D25C: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052D260: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x8052D264: sll         $t8, $t2, 16
    ctx->r24 = S32(ctx->r10 << 16);
    // 0x8052D268: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8052D26C: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x8052D270: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8052D274: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8052D278: bne         $a1, $t0, L_8052D210
    if (ctx->r5 != ctx->r8) {
        // 0x8052D27C: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8052D210;
    }
    // 0x8052D27C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8052D280: beql        $t0, $s3, L_8052D44C
    if (ctx->r8 == ctx->r19) {
        // 0x8052D284: lw          $t8, 0x98($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X98);
            goto L_8052D44C;
    }
    goto skip_2;
    // 0x8052D284: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    skip_2:
L_8052D288:
    // 0x8052D288: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x8052D28C: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x8052D290: addiu       $t2, $a0, 0x2
    ctx->r10 = ADD32(ctx->r4, 0X2);
    // 0x8052D294: andi        $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 & 0XFF;
    // 0x8052D298: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x8052D29C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8052D2A0: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052D2A4: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8052D2A8: sll         $t8, $t2, 8
    ctx->r24 = S32(ctx->r10 << 8);
    // 0x8052D2AC: addiu       $t3, $a0, 0x4
    ctx->r11 = ADD32(ctx->r4, 0X4);
    // 0x8052D2B0: andi        $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 & 0XFF;
    // 0x8052D2B4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8052D2B8: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x8052D2BC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8052D2C0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8052D2C4: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x8052D2C8: addiu       $t7, $a0, 0x6
    ctx->r15 = ADD32(ctx->r4, 0X6);
    // 0x8052D2CC: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x8052D2D0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8052D2D4: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052D2D8: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x8052D2DC: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x8052D2E0: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8052D2E4: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x8052D2E8: addiu       $a1, $t0, 0x1
    ctx->r5 = ADD32(ctx->r8, 0X1);
    // 0x8052D2EC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8052D2F0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8052D2F4: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x8052D2F8: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x8052D2FC: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x8052D300: addiu       $t4, $a1, 0x2
    ctx->r12 = ADD32(ctx->r5, 0X2);
    // 0x8052D304: andi        $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 & 0XFF;
    // 0x8052D308: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8052D30C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8052D310: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052D314: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8052D318: sll         $t9, $t4, 8
    ctx->r25 = S32(ctx->r12 << 8);
    // 0x8052D31C: addiu       $t5, $a1, 0x4
    ctx->r13 = ADD32(ctx->r5, 0X4);
    // 0x8052D320: andi        $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 & 0XFF;
    // 0x8052D324: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8052D328: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x8052D32C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8052D330: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8052D334: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x8052D338: addiu       $t7, $a1, 0x6
    ctx->r15 = ADD32(ctx->r5, 0X6);
    // 0x8052D33C: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x8052D340: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8052D344: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052D348: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x8052D34C: sll         $t8, $t4, 16
    ctx->r24 = S32(ctx->r12 << 16);
    // 0x8052D350: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8052D354: or          $t6, $t7, $t5
    ctx->r14 = ctx->r15 | ctx->r13;
    // 0x8052D358: addiu       $a2, $t0, 0x2
    ctx->r6 = ADD32(ctx->r8, 0X2);
    // 0x8052D35C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8052D360: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8052D364: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x8052D368: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8052D36C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8052D370: addiu       $ra, $a2, 0x2
    ctx->r31 = ADD32(ctx->r6, 0X2);
    // 0x8052D374: andi        $ra, $ra, 0xFF
    ctx->r31 = ctx->r31 & 0XFF;
    // 0x8052D378: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8052D37C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8052D380: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052D384: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8052D388: sll         $t8, $ra, 8
    ctx->r24 = S32(ctx->r31 << 8);
    // 0x8052D38C: addiu       $s0, $a2, 0x4
    ctx->r16 = ADD32(ctx->r6, 0X4);
    // 0x8052D390: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x8052D394: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8052D398: or          $t7, $t9, $s0
    ctx->r15 = ctx->r25 | ctx->r16;
    // 0x8052D39C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8052D3A0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8052D3A4: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x8052D3A8: addiu       $t7, $a2, 0x6
    ctx->r15 = ADD32(ctx->r6, 0X6);
    // 0x8052D3AC: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x8052D3B0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8052D3B4: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052D3B8: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x8052D3BC: sll         $t9, $ra, 16
    ctx->r25 = S32(ctx->r31 << 16);
    // 0x8052D3C0: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8052D3C4: or          $t6, $t7, $s0
    ctx->r14 = ctx->r15 | ctx->r16;
    // 0x8052D3C8: addiu       $a3, $t0, 0x3
    ctx->r7 = ADD32(ctx->r8, 0X3);
    // 0x8052D3CC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8052D3D0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8052D3D4: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x8052D3D8: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x8052D3DC: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x8052D3E0: addiu       $s1, $a3, 0x2
    ctx->r17 = ADD32(ctx->r7, 0X2);
    // 0x8052D3E4: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8052D3E8: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x8052D3EC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8052D3F0: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x8052D3F4: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8052D3F8: sll         $t9, $s1, 8
    ctx->r25 = S32(ctx->r17 << 8);
    // 0x8052D3FC: addiu       $s2, $a3, 0x4
    ctx->r18 = ADD32(ctx->r7, 0X4);
    // 0x8052D400: andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // 0x8052D404: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8052D408: or          $t7, $t8, $s2
    ctx->r15 = ctx->r24 | ctx->r18;
    // 0x8052D40C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8052D410: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8052D414: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x8052D418: addiu       $t7, $a3, 0x6
    ctx->r15 = ADD32(ctx->r7, 0X6);
    // 0x8052D41C: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x8052D420: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8052D424: sw          $t9, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r25;
    // 0x8052D428: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x8052D42C: sll         $t8, $s1, 16
    ctx->r24 = S32(ctx->r17 << 16);
    // 0x8052D430: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8052D434: or          $t6, $t7, $s2
    ctx->r14 = ctx->r15 | ctx->r18;
    // 0x8052D438: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8052D43C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8052D440: bne         $t0, $s3, L_8052D288
    if (ctx->r8 != ctx->r19) {
        // 0x8052D444: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8052D288;
    }
    // 0x8052D444: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8052D448:
    // 0x8052D448: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
L_8052D44C:
    // 0x8052D44C: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x8052D450: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8052D454: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8052D458: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8052D45C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8052D460: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8052D464: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8052D468: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8052D46C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8052D470: jr          $ra
    // 0x8052D474: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8052D474: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_806E7E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7E4C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806E7E50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806E7E54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806E7E58: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(664, 0XEBC) << 16);
    // 0x806E7E5C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806E7E60: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806E7E64: lw          $t8, -0x7F04($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(664, 0XEBC));
    // 0x806E7E68: jr          $ra
    // 0x806E7E6C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x806E7E6C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_806CD958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CD958: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806CD95C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806CD960: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806CD964: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x806CD968: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806CD96C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x806CD970: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x806CD974: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x806CD978: jal         0x806CCF00
    // 0x806CD97C: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    func_806CCF00(rdram, ctx);
        goto after_0;
    // 0x806CD97C: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    after_0:
    // 0x806CD980: jal         0x806CD3D4
    // 0x806CD984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CD3D4(rdram, ctx);
        goto after_1;
    // 0x806CD984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CD988: lw          $t9, 0x1E0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E0);
    // 0x806CD98C: addiu       $t0, $zero, 0x1F4
    ctx->r8 = ADD32(0, 0X1F4);
    // 0x806CD990: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C4C) << 16);
    // 0x806CD994: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x806CD998: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x806CD99C: lwc1        $f8, -0xC94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C4C));
    // 0x806CD9A0: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C50) << 16);
    // 0x806CD9A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CD9A8: lwc1        $f16, -0xC90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C50));
    // 0x806CD9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD9B0: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x806CD9B4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806CD9B8: nop

    // 0x806CD9BC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806CD9C0: jal         0x806CB7EC
    // 0x806CD9C4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_806CB7EC(rdram, ctx);
        goto after_2;
    // 0x806CD9C4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x806CD9C8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x806CD9CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806CD9D0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806CD9D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806CD9D8: lui         $a1, 0xBBA3
    ctx->r5 = S32(0XBBA3 << 16);
    // 0x806CD9DC: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x806CD9E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CD9E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806CD9E8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x806CD9EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x806CD9F0: jal         0x806CCF4C
    // 0x806CD9F4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_806CCF4C(rdram, ctx);
        goto after_3;
    // 0x806CD9F4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x806CD9F8: jal         0x806CCE38
    // 0x806CD9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCE38(rdram, ctx);
        goto after_4;
    // 0x806CD9FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806CDA00: beq         $v0, $zero, L_806CDA6C
    if (ctx->r2 == 0) {
        // 0x806CDA04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806CDA6C;
    }
    // 0x806CDA04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CDA08: jal         0x806CB78C
    // 0x806CDA0C: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    func_806CB78C(rdram, ctx);
        goto after_5;
    // 0x806CDA0C: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    after_5:
    // 0x806CDA10: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x806CDA14: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x806CDA18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CDA1C: beq         $v0, $zero, L_806CDA2C
    if (ctx->r2 == 0) {
        // 0x806CDA20: nop
    
            goto L_806CDA2C;
    }
    // 0x806CDA20: nop

    // 0x806CDA24: jal         0x80048060
    // 0x806CDA28: sw          $t2, 0x1E0($v0)
    MEM_W(0X1E0, ctx->r2) = ctx->r10;
    func_80048060(rdram, ctx);
        goto after_6;
    // 0x806CDA28: sw          $t2, 0x1E0($v0)
    MEM_W(0X1E0, ctx->r2) = ctx->r10;
    after_6:
L_806CDA2C:
    // 0x806CDA2C: jal         0x800447C8
    // 0x806CDA30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x806CDA30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806CDA34: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806CDA38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806CDA3C: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x806CDA40: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x806CDA44: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x806CDA48: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x806CDA4C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806CDA50: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x806CDA54: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x806CDA58: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x806CDA5C: lw          $t9, 0x18($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X18);
    // 0x806CDA60: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806CDA64: jalr        $t9
    // 0x806CDA68: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x806CDA68: nop

    after_8:
L_806CDA6C:
    // 0x806CDA6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806CDA70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806CDA74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806CDA78: jr          $ra
    // 0x806CDA7C: nop

    return;
    // 0x806CDA7C: nop

;}
RECOMP_FUNC void func_806B1DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1DB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B1DB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B1DBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B1DC0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B1DC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B1DC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B1DCC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B1DD0: lui         $a2, 0x806B
    ctx->r6 = S32(RELOC_HI16(601, 0X1408) << 16);
    // 0x806B1DD4: lui         $a1, 0x806B
    ctx->r5 = S32(RELOC_HI16(601, 0X1428) << 16);
    // 0x806B1DD8: addiu       $a1, $a1, 0x2D78
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(601, 0X1428));
    // 0x806B1DDC: addiu       $a2, $a2, 0x2D58
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(601, 0X1408));
    // 0x806B1DE0: jal         0x806B1A18
    // 0x806B1DE4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_806B1A18(rdram, ctx);
        goto after_0;
    // 0x806B1DE4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x806B1DE8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x806B1DEC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806B1DF0: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x806B1DF4: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x806B1DF8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x806B1DFC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806B1E00: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x806B1E04: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x806B1E08: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x806B1E0C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x806B1E10: jal         0x806B195C
    // 0x806B1E14: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_806B195C(rdram, ctx);
        goto after_1;
    // 0x806B1E14: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x806B1E18: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B1E1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1E20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B1E24: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B1E28: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B1E2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B1E30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B1E34: jr          $ra
    // 0x806B1E38: nop

    return;
    // 0x806B1E38: nop

;}
RECOMP_FUNC void func_8045F1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F1BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8045F1C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045F1C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045F1C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8045F1CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8045F1D0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8045F1D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045F1D8: lui         $at, 0x427E
    ctx->r1 = S32(0X427E << 16);
    // 0x8045F1DC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8045F1E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045F1E4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8045F1E8: bc1fl       L_8045F1F8
    if (!c1cs) {
        // 0x8045F1EC: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8045F1F8;
    }
    goto skip_0;
    // 0x8045F1EC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x8045F1F0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8045F1F4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8045F1F8:
    // 0x8045F1F8: nop

    // 0x8045F1FC: bc1f        L_8045F208
    if (!c1cs) {
        // 0x8045F200: nop
    
            goto L_8045F208;
    }
    // 0x8045F200: nop

    // 0x8045F204: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8045F208:
    // 0x8045F208: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8045F20C: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x8045F210: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x8045F214: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8045F218: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8045F21C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8045F220: jal         0x80067D5C
    // 0x8045F224: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x8045F224: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045F228: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8045F22C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8045F230: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8045F234: bnel        $a0, $zero, L_8045F250
    if (ctx->r4 != 0) {
        // 0x8045F238: lh          $a1, 0x1F0($a3)
        ctx->r5 = MEM_H(ctx->r7, 0X1F0);
            goto L_8045F250;
    }
    goto skip_1;
    // 0x8045F238: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    skip_1:
    // 0x8045F23C: jal         0x8045F164
    // 0x8045F240: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8045F164(rdram, ctx);
        goto after_1;
    // 0x8045F240: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8045F244: b           L_8045F284
    // 0x8045F248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8045F284;
    // 0x8045F248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045F24C: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
L_8045F250:
    // 0x8045F250: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8045F254: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x8045F258: bne         $a1, $at, L_8045F278
    if (ctx->r5 != ctx->r1) {
        // 0x8045F25C: nop
    
            goto L_8045F278;
    }
    // 0x8045F25C: nop

    // 0x8045F260: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8045F264: jal         0x80067F78
    // 0x8045F268: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_80067F78(rdram, ctx);
        goto after_2;
    // 0x8045F268: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_2:
    // 0x8045F26C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8045F270: b           L_8045F280
    // 0x8045F274: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
        goto L_8045F280;
    // 0x8045F274: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
L_8045F278:
    // 0x8045F278: jal         0x800678F0
    // 0x8045F27C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x8045F27C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_3:
L_8045F280:
    // 0x8045F280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045F284:
    // 0x8045F284: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8045F288: jr          $ra
    // 0x8045F28C: nop

    return;
    // 0x8045F28C: nop

;}
RECOMP_FUNC void func_80043C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043C94: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80043C98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80043C9C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80043CA0: beq         $t7, $zero, L_80043CC0
    if (ctx->r15 == 0) {
        // 0x80043CA4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80043CC0;
    }
    // 0x80043CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043CA8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043CAC: addiu       $a0, $a0, 0x390
    ctx->r4 = ADD32(ctx->r4, 0X390);
    // 0x80043CB0: jal         0x80071380
    // 0x80043CB4: addiu       $a1, $zero, 0x261
    ctx->r5 = ADD32(0, 0X261);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80043CB4: addiu       $a1, $zero, 0x261
    ctx->r5 = ADD32(0, 0X261);
    after_0:
    // 0x80043CB8: b           L_80043CFC
    // 0x80043CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80043CFC;
    // 0x80043CBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80043CC0:
    // 0x80043CC0: lh          $t8, 0x17E($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X17E);
    // 0x80043CC4: addiu       $v1, $zero, 0x96
    ctx->r3 = ADD32(0, 0X96);
    // 0x80043CC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80043CCC: bne         $v1, $t8, L_80043CEC
    if (ctx->r3 != ctx->r24) {
        // 0x80043CD0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80043CEC;
    }
    // 0x80043CD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80043CD4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043CD8: addiu       $a0, $a0, 0x3A0
    ctx->r4 = ADD32(ctx->r4, 0X3A0);
    // 0x80043CDC: jal         0x80071380
    // 0x80043CE0: addiu       $a1, $zero, 0x26B
    ctx->r5 = ADD32(0, 0X26B);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80043CE0: addiu       $a1, $zero, 0x26B
    ctx->r5 = ADD32(0, 0X26B);
    after_1:
    // 0x80043CE4: b           L_80043CFC
    // 0x80043CE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80043CFC;
    // 0x80043CE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80043CEC:
    // 0x80043CEC: sh          $v1, 0x17E($a0)
    MEM_H(0X17E, ctx->r4) = ctx->r3;
    // 0x80043CF0: sb          $zero, 0x17D($a0)
    MEM_B(0X17D, ctx->r4) = 0;
    // 0x80043CF4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80043CF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80043CFC:
    // 0x80043CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80043D04: jr          $ra
    // 0x80043D08: nop

    return;
    // 0x80043D08: nop

;}
RECOMP_FUNC void func_8066E1AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066E1AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066E1B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066E1B4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8066E1B8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8066E1BC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8066E1C0: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(517, 0X1034) << 16);
    // 0x8066E1C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8066E1C8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8066E1CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8066E1D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8066E1D4: lw          $t8, -0x1A0C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(517, 0X1034));
    // 0x8066E1D8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8066E1DC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8066E1E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8066E1E4: jal         0x80048490
    // 0x8066E1E8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8066E1E8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8066E1EC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8066E1F0: jal         0x80048378
    // 0x8066E1F4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8066E1F4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8066E1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066E1FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066E200: jr          $ra
    // 0x8066E204: nop

    return;
    // 0x8066E204: nop

;}
RECOMP_FUNC void func_80564F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80564F88: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80564F8C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80564F90: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80564F94: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80564F98: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80564F9C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80564FA0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80564FA4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80564FA8: bc1fl       L_80564FF8
    if (!c1cs) {
        // 0x80564FAC: lwc1        $f0, 0x464($t8)
        ctx->f0.u32l = MEM_W(ctx->r24, 0X464);
            goto L_80564FF8;
    }
    goto skip_0;
    // 0x80564FAC: lwc1        $f0, 0x464($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X464);
    skip_0:
    // 0x80564FB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80564FB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80564FB8: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X2598) << 16);
    // 0x80564FBC: lwc1        $f10, 0x5DF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X2598));
    // 0x80564FC0: mul.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80564FC4: lwc1        $f8, 0x464($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X464);
    // 0x80564FC8: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X259C) << 16);
    // 0x80564FCC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80564FD0: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80564FD4: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x80564FD8: lwc1        $f6, 0x5DFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X259C));
    // 0x80564FDC: lwc1        $f4, 0x464($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X464);
    // 0x80564FE0: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80564FE4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80564FE8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80564FEC: b           L_80565064
    // 0x80564FF0: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
        goto L_80565064;
    // 0x80564FF0: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
    // 0x80564FF4: lwc1        $f0, 0x464($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X464);
L_80564FF8:
    // 0x80564FF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80564FFC: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X25A8) << 16);
    // 0x80565000: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80565004: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80565008: nop

    // 0x8056500C: bc1fl       L_8056504C
    if (!c1cs) {
        // 0x80565010: sub.s       $f4, $f0, $f12
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_8056504C;
    }
    goto skip_1;
    // 0x80565010: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    skip_1:
    // 0x80565014: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X25A0) << 16);
    // 0x80565018: lwc1        $f4, 0x5E00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X25A0));
    // 0x8056501C: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(369, 0X25A4) << 16);
    // 0x80565020: lwc1        $f8, 0x5E04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X25A4));
    // 0x80565024: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80565028: nop

    // 0x8056502C: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80565030: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80565034: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x80565038: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8056503C: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80565040: b           L_80565064
    // 0x80565044: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
        goto L_80565064;
    // 0x80565044: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80565048: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
L_8056504C:
    // 0x8056504C: lwc1        $f8, 0x5E08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(369, 0X25A8));
    // 0x80565050: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80565054: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x80565058: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8056505C: add.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80565060: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
L_80565064:
    // 0x80565064: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80565068: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8056506C: jr          $ra
    // 0x80565070: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
    return;
    // 0x80565070: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80049C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049C54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80049C58: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x80049C5C: sb          $zero, 0x14($a0)
    MEM_B(0X14, ctx->r4) = 0;
    // 0x80049C60: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80049C64: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80049C68: jr          $ra
    // 0x80049C6C: sb          $t6, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r14;
    return;
    // 0x80049C6C: sb          $t6, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80716DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716DC8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716DCC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716DD0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716DD4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716DD8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716DDC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716DE0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716DE4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716DE8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716DEC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716DF0: jr          $ra
    // 0x80716DF4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716DF4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80789FBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80789FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80789FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80789FC4: jal         0x80789E20
    // 0x80789FC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80789E20(rdram, ctx);
        goto after_0;
    // 0x80789FC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80789FCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80789FD0: beq         $v0, $zero, L_8078A000
    if (ctx->r2 == 0) {
        // 0x80789FD4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8078A000;
    }
    // 0x80789FD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80789FD8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80789FDC: sb          $t6, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r14;
    // 0x80789FE0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80789FE4: lw          $t7, -0x6C78($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6C78);
    // 0x80789FE8: beql        $t7, $zero, L_8078A00C
    if (ctx->r15 == 0) {
        // 0x80789FEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078A00C;
    }
    goto skip_0;
    // 0x80789FEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80789FF0: jal         0x80789E70
    // 0x80789FF4: nop

    func_80789E70(rdram, ctx);
        goto after_1;
    // 0x80789FF4: nop

    after_1:
    // 0x80789FF8: b           L_8078A00C
    // 0x80789FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078A00C;
    // 0x80789FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078A000:
    // 0x8078A000: jal         0x800447C8
    // 0x8078A004: nop

    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8078A004: nop

    after_2:
    // 0x8078A008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078A00C:
    // 0x8078A00C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078A010: jr          $ra
    // 0x8078A014: nop

    return;
    // 0x8078A014: nop

;}
RECOMP_FUNC void func_8007E134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E134: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007E138: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8007E13C: lw          $t4, -0x260C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X260C);
    // 0x8007E140: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007E144: addu        $v1, $a1, $a3
    ctx->r3 = ADD32(ctx->r5, ctx->r7);
    // 0x8007E148: lw          $t3, 0xC($t4)
    ctx->r11 = MEM_W(ctx->r12, 0XC);
    // 0x8007E14C: sll         $t1, $a3, 6
    ctx->r9 = S32(ctx->r7 << 6);
    // 0x8007E150: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x8007E154: addiu       $t3, $t3, -0x40
    ctx->r11 = ADD32(ctx->r11, -0X40);
    // 0x8007E158: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8007E15C: sh          $a1, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r5;
    // 0x8007E160: sh          $a2, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r6;
    // 0x8007E164: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x8007E168: sh          $zero, 0x8($t3)
    MEM_H(0X8, ctx->r11) = 0;
    // 0x8007E16C: sh          $zero, 0xA($t3)
    MEM_H(0XA, ctx->r11) = 0;
    // 0x8007E170: sh          $v1, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r3;
    // 0x8007E174: sh          $a2, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r6;
    // 0x8007E178: sh          $zero, 0x14($t3)
    MEM_H(0X14, ctx->r11) = 0;
    // 0x8007E17C: sh          $t1, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r9;
    // 0x8007E180: sh          $zero, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = 0;
    // 0x8007E184: sh          $v1, 0x20($t3)
    MEM_H(0X20, ctx->r11) = ctx->r3;
    // 0x8007E188: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8007E18C: sh          $t1, 0x28($t3)
    MEM_H(0X28, ctx->r11) = ctx->r9;
    // 0x8007E190: sh          $zero, 0x24($t3)
    MEM_H(0X24, ctx->r11) = 0;
    // 0x8007E194: addu        $t0, $a2, $t6
    ctx->r8 = ADD32(ctx->r6, ctx->r14);
    // 0x8007E198: sh          $t0, 0x22($t3)
    MEM_H(0X22, ctx->r11) = ctx->r8;
    // 0x8007E19C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8007E1A0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007E1A4: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x8007E1A8: sll         $t2, $t2, 6
    ctx->r10 = S32(ctx->r10 << 6);
    // 0x8007E1AC: sh          $t2, 0x2A($t3)
    MEM_H(0X2A, ctx->r11) = ctx->r10;
    // 0x8007E1B0: sh          $a1, 0x30($t3)
    MEM_H(0X30, ctx->r11) = ctx->r5;
    // 0x8007E1B4: sh          $t0, 0x32($t3)
    MEM_H(0X32, ctx->r11) = ctx->r8;
    // 0x8007E1B8: sh          $zero, 0x34($t3)
    MEM_H(0X34, ctx->r11) = 0;
    // 0x8007E1BC: sh          $zero, 0x38($t3)
    MEM_H(0X38, ctx->r11) = 0;
    // 0x8007E1C0: sh          $t2, 0x3A($t3)
    MEM_H(0X3A, ctx->r11) = ctx->r10;
    // 0x8007E1C4: ori         $t7, $t7, 0x103F
    ctx->r15 = ctx->r15 | 0X103F;
    // 0x8007E1C8: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8007E1CC: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x8007E1D0: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x8007E1D4: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x8007E1D8: lui         $t8, 0xB100
    ctx->r24 = S32(0XB100 << 16);
    // 0x8007E1DC: ori         $t8, $t8, 0x204
    ctx->r24 = ctx->r24 | 0X204;
    // 0x8007E1E0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8007E1E4: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8007E1E8: addiu       $t6, $zero, 0x406
    ctx->r14 = ADD32(0, 0X406);
    // 0x8007E1EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007E1F0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8007E1F4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8007E1F8: jr          $ra
    // 0x8007E1FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007E1FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8004D3C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D3C4: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004D3C8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004D3CC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004D3D0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004D3D4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004D3D8: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004D3DC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004D3E0: lbu         $t9, 0x14($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X14);
    // 0x8004D3E4: beq         $t9, $zero, L_8004D40C
    if (ctx->r25 == 0) {
        // 0x8004D3E8: nop
    
            goto L_8004D40C;
    }
    // 0x8004D3E8: nop

    // 0x8004D3EC: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8004D3F0: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8004D3F4: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8004D3F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004D3FC: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8004D400: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8004D404: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004D408: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
L_8004D40C:
    // 0x8004D40C: jr          $ra
    // 0x8004D410: nop

    return;
    // 0x8004D410: nop

;}
RECOMP_FUNC void func_8064A838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A838: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064A83C: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064A840: jr          $ra
    // 0x8064A844: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8064A844: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_8041DBDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041DBDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8041DBE0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8041DBE4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8041DBE8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8041DBEC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8041DBF0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8041DBF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8041DBF8: jal         0x8041E20C
    // 0x8041DBFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8041E20C(rdram, ctx);
        goto after_0;
    // 0x8041DBFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8041DC00: beq         $v0, $zero, L_8041DD1C
    if (ctx->r2 == 0) {
        // 0x8041DC04: nop
    
            goto L_8041DD1C;
    }
    // 0x8041DC04: nop

    // 0x8041DC08: jal         0x8041E244
    // 0x8041DC0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8041E244(rdram, ctx);
        goto after_1;
    // 0x8041DC0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8041DC10: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8041DC14: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8041DC18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8041DC1C: sw          $t6, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->r14;
    // 0x8041DC20: sb          $t7, 0x165($s3)
    MEM_B(0X165, ctx->r19) = ctx->r15;
    // 0x8041DC24: sw          $zero, 0x1E0($s3)
    MEM_W(0X1E0, ctx->r19) = 0;
    // 0x8041DC28: sw          $zero, 0x138($s3)
    MEM_W(0X138, ctx->r19) = 0;
    // 0x8041DC2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8041DC30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041DC34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8041DC38: jal         0x8041FE10
    // 0x8041DC3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8041FE10(rdram, ctx);
        goto after_2;
    // 0x8041DC3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8041DC40: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(29, 0X554) << 16);
    // 0x8041DC44: addiu       $t8, $t8, -0x244C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(29, 0X554));
    // 0x8041DC48: sw          $t8, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r24;
    // 0x8041DC4C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34D4) << 16);
    // 0x8041DC50: lwc1        $f4, 0xB34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34D4));
    // 0x8041DC54: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34D8) << 16);
    // 0x8041DC58: lwc1        $f16, 0x6C($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X6C);
    // 0x8041DC5C: swc1        $f4, 0xE8($s3)
    MEM_W(0XE8, ctx->r19) = ctx->f4.u32l;
    // 0x8041DC60: lwc1        $f6, 0xB38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34D8));
    // 0x8041DC64: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8041DC68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8041DC6C: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8041DC70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041DC74: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8041DC78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8041DC7C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8041DC80: swc1        $f8, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f8.u32l;
    // 0x8041DC84: swc1        $f10, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f10.u32l;
    // 0x8041DC88: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8041DC8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041DC90: lwc1        $f8, 0x70($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X70);
    // 0x8041DC94: swc1        $f6, 0xEC($s3)
    MEM_W(0XEC, ctx->r19) = ctx->f6.u32l;
    // 0x8041DC98: lui         $s2, 0x8042
    ctx->r18 = S32(RELOC_HI16(29, 0X32E0) << 16);
    // 0x8041DC9C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8041DCA0: lui         $s1, 0x8042
    ctx->r17 = S32(RELOC_HI16(29, 0X3290) << 16);
    // 0x8041DCA4: lui         $s4, 0x8042
    ctx->r20 = S32(RELOC_HI16(29, 0X3298) << 16);
    // 0x8041DCA8: lw          $s0, 0x1F4($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X1F4);
    // 0x8041DCAC: addiu       $s4, $s4, 0x8F8
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(29, 0X3298));
    // 0x8041DCB0: addiu       $s1, $s1, 0x8F0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(29, 0X3290));
    // 0x8041DCB4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8041DCB8: addiu       $s2, $s2, 0x940
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(29, 0X32E0));
    // 0x8041DCBC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8041DCC0: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8041DCC4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8041DCC8: sh          $t0, 0x13C($s3)
    MEM_H(0X13C, ctx->r19) = ctx->r8;
    // 0x8041DCCC: sh          $t2, 0x13E($s3)
    MEM_H(0X13E, ctx->r19) = ctx->r10;
L_8041DCD0:
    // 0x8041DCD0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8041DCD4: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x8041DCD8: jal         0x8041FE5C
    // 0x8041DCDC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    func_8041FE5C(rdram, ctx);
        goto after_3;
    // 0x8041DCDC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x8041DCE0: bne         $s0, $zero, L_8041DCF8
    if (ctx->r16 != 0) {
        // 0x8041DCE4: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8041DCF8;
    }
    // 0x8041DCE4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8041DCE8: jal         0x800445A4
    // 0x8041DCEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8041DCEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x8041DCF0: b           L_8041DD28
    // 0x8041DCF4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8041DD28;
    // 0x8041DCF4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8041DCF8:
    // 0x8041DCF8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8041DCFC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8041DD00: bne         $s1, $s4, L_8041DCD0
    if (ctx->r17 != ctx->r20) {
        // 0x8041DD04: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8041DCD0;
    }
    // 0x8041DD04: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8041DD08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8041DD0C: jal         0x8041E430
    // 0x8041DD10: lw          $a1, 0x1F4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1F4);
    func_8041E430(rdram, ctx);
        goto after_5;
    // 0x8041DD10: lw          $a1, 0x1F4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1F4);
    after_5:
    // 0x8041DD14: b           L_8041DD28
    // 0x8041DD18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8041DD28;
    // 0x8041DD18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8041DD1C:
    // 0x8041DD1C: jal         0x800445A4
    // 0x8041DD20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x8041DD20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x8041DD24: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8041DD28:
    // 0x8041DD28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041DD2C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8041DD30: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8041DD34: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8041DD38: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8041DD3C: jr          $ra
    // 0x8041DD40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8041DD40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8052D478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D478: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8052D47C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8052D480: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8052D484: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8052D488: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8052D48C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8052D490: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8052D494: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8052D498: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8052D49C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8052D4A0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8052D4A4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8052D4A8: jal         0x8004700C
    // 0x8052D4AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8052D4AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x8052D4B0: beq         $v0, $zero, L_8052D5C8
    if (ctx->r2 == 0) {
        // 0x8052D4B4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8052D5C8;
    }
    // 0x8052D4B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8052D4B8: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x8052D4BC: lw          $s0, 0x1F4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X1F4);
    // 0x8052D4C0: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8052D4C4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8052D4C8: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x8052D4CC: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x8052D4D0: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x8052D4D4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8052D4D8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8052D4DC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8052D4E0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8052D4E4: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8052D4E8: sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    // 0x8052D4EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8052D4F0: mul.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8052D4F4: nop

    // 0x8052D4F8: mul.s       $f22, $f10, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8052D4FC: jal         0x80047AB8
    // 0x8052D500: nop

    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x8052D500: nop

    after_1:
    // 0x8052D504: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8052D508: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8052D50C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8052D510: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8052D514: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8052D518: addiu       $s3, $zero, 0x19
    ctx->r19 = ADD32(0, 0X19);
L_8052D51C:
    // 0x8052D51C: lwc1        $f6, 0x6C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X6C);
    // 0x8052D520: lwc1        $f8, 0x70($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X70);
    // 0x8052D524: lw          $v0, 0x180($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X180);
    // 0x8052D528: mul.s       $f4, $f6, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x8052D52C: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8052D530: lwc1        $f10, 0x3C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8052D534: mul.s       $f16, $f8, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8052D538: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8052D53C: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8052D540: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8052D544: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8052D548: add.s       $f24, $f4, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8052D54C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8052D550: add.s       $f26, $f16, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8052D554: add.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8052D558: sub.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8052D55C: sub.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8052D560: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x8052D564: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8052D568: jal         0x80065954
    // 0x8052D56C: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8052D56C: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8052D570: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8052D574: nop

    // 0x8052D578: bc1fl       L_8052D5B8
    if (!c1cs) {
        // 0x8052D57C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8052D5B8;
    }
    goto skip_0;
    // 0x8052D57C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8052D580: jal         0x80065954
    // 0x8052D584: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8052D584: lwc1        $f12, 0x80($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X80);
    after_3:
    // 0x8052D588: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x8052D58C: nop

    // 0x8052D590: bc1fl       L_8052D5B8
    if (!c1cs) {
        // 0x8052D594: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8052D5B8;
    }
    goto skip_1;
    // 0x8052D594: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8052D598: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8052D59C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8052D5A0: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x8052D5A4: jal         0x8002F6E4
    // 0x8052D5A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_4;
    // 0x8052D5A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8052D5AC: b           L_8052D5CC
    // 0x8052D5B0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8052D5CC;
    // 0x8052D5B0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8052D5B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8052D5B8:
    // 0x8052D5B8: sub.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f30.fl;
    // 0x8052D5BC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8052D5C0: bne         $s1, $s3, L_8052D51C
    if (ctx->r17 != ctx->r19) {
        // 0x8052D5C4: sub.s       $f22, $f22, $f30
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f30.fl;
            goto L_8052D51C;
    }
    // 0x8052D5C4: sub.s       $f22, $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f30.fl;
L_8052D5C8:
    // 0x8052D5C8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8052D5CC:
    // 0x8052D5CC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8052D5D0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8052D5D4: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8052D5D8: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8052D5DC: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8052D5E0: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8052D5E4: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8052D5E8: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8052D5EC: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8052D5F0: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8052D5F4: jr          $ra
    // 0x8052D5F8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8052D5F8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_8040BA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040BA98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040BA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040BAA0: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8040BAA4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8040BAA8: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(14, 0XF70) << 16);
    // 0x8040BAAC: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8040BAB0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8040BAB4: addiu       $t7, $t7, -0x4530
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(14, 0XF70));
    // 0x8040BAB8: jal         0x8040B5EC
    // 0x8040BABC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    func_8040B5EC(rdram, ctx);
        goto after_0;
    // 0x8040BABC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    after_0:
    // 0x8040BAC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040BAC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040BAC8: jr          $ra
    // 0x8040BACC: nop

    return;
    // 0x8040BACC: nop

;}
RECOMP_FUNC void func_8002FB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FB90: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8002FB94: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002FB98: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FB9C: bne         $t6, $at, L_8002FBB4
    if (ctx->r14 != ctx->r1) {
        // 0x8002FBA0: addiu       $t7, $zero, 0x40
        ctx->r15 = ADD32(0, 0X40);
            goto L_8002FBB4;
    }
    // 0x8002FBA0: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8002FBA4: lui         $t8, 0x8003
    ctx->r24 = S32(0X8003 << 16);
    // 0x8002FBA8: addiu       $t8, $t8, -0x2894
    ctx->r24 = ADD32(ctx->r24, -0X2894);
    // 0x8002FBAC: sw          $t7, 0x1A4($v0)
    MEM_W(0X1A4, ctx->r2) = ctx->r15;
    // 0x8002FBB0: sw          $t8, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->r24;
L_8002FBB4:
    // 0x8002FBB4: jr          $ra
    // 0x8002FBB8: nop

    return;
    // 0x8002FBB8: nop

;}
RECOMP_FUNC void func_800274BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800274BC: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x800274C0: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x800274C4: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x800274C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800274CC: jr          $ra
    // 0x800274D0: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    return;
    // 0x800274D0: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80554A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80554A58: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80554A5C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80554A60: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80554A64: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80554A68: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80554A6C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80554A70: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80554A74: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80554A78: lui         $t1, 0x8055
    ctx->r9 = S32(RELOC_HI16(354, 0X4144) << 16);
    // 0x80554A7C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80554A80: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80554A84: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80554A88: lw          $t1, 0x4C64($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(354, 0X4144));
    // 0x80554A8C: jr          $ra
    // 0x80554A90: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80554A90: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8064B104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B10C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064B110: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064B114: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8064B118: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B11C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B120: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8064B124: nop

    // 0x8064B128: bc1fl       L_8064B158
    if (!c1cs) {
        // 0x8064B12C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064B158;
    }
    goto skip_0;
    // 0x8064B12C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064B130: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064B134: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B138: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064B13C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064B140: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8064B144: jal         0x8064B3E0
    // 0x8064B148: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8064B3E0(rdram, ctx);
        goto after_0;
    // 0x8064B148: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064B14C: jal         0x8064A40C
    // 0x8064B150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8064A40C(rdram, ctx);
        goto after_1;
    // 0x8064B150: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8064B154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064B158:
    // 0x8064B158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B15C: jr          $ra
    // 0x8064B160: nop

    return;
    // 0x8064B160: nop

;}
RECOMP_FUNC void func_80409858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409858: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040985C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80409860: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80409864: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80409868: jal         0x804096C0
    // 0x8040986C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_804096C0(rdram, ctx);
        goto after_0;
    // 0x8040986C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80409870: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80409874: beq         $v0, $zero, L_80409884
    if (ctx->r2 == 0) {
        // 0x80409878: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80409884;
    }
    // 0x80409878: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8040987C: b           L_804098C4
    // 0x80409880: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_804098C4;
    // 0x80409880: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_80409884:
    // 0x80409884: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80409888: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8040988C: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E18) << 16);
    // 0x80409890: beq         $v0, $zero, L_804098C4
    if (ctx->r2 == 0) {
        // 0x80409894: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_804098C4;
    }
    // 0x80409894: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80409898: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x8040989C: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x804098A0: lwc1        $f6, -0x5818($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E18));
    // 0x804098A4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x804098A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804098AC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x804098B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804098B4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x804098B8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x804098BC: jal         0x80409B1C
    // 0x804098C0: nop

    func_80409B1C(rdram, ctx);
        goto after_1;
    // 0x804098C0: nop

    after_1:
L_804098C4:
    // 0x804098C4: jal         0x80409810
    // 0x804098C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80409810(rdram, ctx);
        goto after_2;
    // 0x804098C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804098CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804098D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804098D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804098D8: jr          $ra
    // 0x804098DC: nop

    return;
    // 0x804098DC: nop

;}
RECOMP_FUNC void func_80673DF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673DF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80673DF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80673DFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80673E00: jal         0x80673D90
    // 0x80673E04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80673D90(rdram, ctx);
        goto after_0;
    // 0x80673E04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80673E08: bne         $v0, $zero, L_80673E20
    if (ctx->r2 != 0) {
        // 0x80673E0C: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_80673E20;
    }
    // 0x80673E0C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80673E10: jal         0x800445A4
    // 0x80673E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80673E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80673E18: b           L_80673EFC
    // 0x80673E1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80673EFC;
    // 0x80673E1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80673E20:
    // 0x80673E20: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80673E24: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80673E28: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(529, 0X1A78) << 16);
    // 0x80673E2C: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80673E30: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80673E34: addiu       $t7, $t7, 0x4A58
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(529, 0X1A78));
    // 0x80673E38: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80673E3C: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80673E40: addiu       $at, $zero, 0x455D
    ctx->r1 = ADD32(0, 0X455D);
    // 0x80673E44: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80673E48: beq         $v0, $at, L_80673E7C
    if (ctx->r2 == ctx->r1) {
        // 0x80673E4C: sw          $zero, 0x138($s0)
        MEM_W(0X138, ctx->r16) = 0;
            goto L_80673E7C;
    }
    // 0x80673E4C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80673E50: addiu       $at, $zero, 0x4567
    ctx->r1 = ADD32(0, 0X4567);
    // 0x80673E54: beq         $v0, $at, L_80673E98
    if (ctx->r2 == ctx->r1) {
        // 0x80673E58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80673E98;
    }
    // 0x80673E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673E5C: addiu       $at, $zero, 0x4576
    ctx->r1 = ADD32(0, 0X4576);
    // 0x80673E60: beq         $v0, $at, L_80673EB8
    if (ctx->r2 == ctx->r1) {
        // 0x80673E64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80673EB8;
    }
    // 0x80673E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673E68: addiu       $at, $zero, 0x4577
    ctx->r1 = ADD32(0, 0X4577);
    // 0x80673E6C: beq         $v0, $at, L_80673ED8
    if (ctx->r2 == ctx->r1) {
        // 0x80673E70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80673ED8;
    }
    // 0x80673E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673E74: b           L_80673EFC
    // 0x80673E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80673EFC;
    // 0x80673E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80673E7C:
    // 0x80673E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80673E80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80673E84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80673E88: jal         0x80673F0C
    // 0x80673E8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80673F0C(rdram, ctx);
        goto after_2;
    // 0x80673E8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80673E90: b           L_80673EFC
    // 0x80673E94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80673EFC;
    // 0x80673E94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80673E98:
    // 0x80673E98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80673E9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80673EA0: jal         0x80673F0C
    // 0x80673EA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80673F0C(rdram, ctx);
        goto after_3;
    // 0x80673EA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80673EA8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80673EAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80673EB0: b           L_80673EF8
    // 0x80673EB4: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
        goto L_80673EF8;
    // 0x80673EB4: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
L_80673EB8:
    // 0x80673EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80673EBC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80673EC0: jal         0x80673F0C
    // 0x80673EC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80673F0C(rdram, ctx);
        goto after_4;
    // 0x80673EC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80673EC8: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80673ECC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80673ED0: b           L_80673EF8
    // 0x80673ED4: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
        goto L_80673EF8;
    // 0x80673ED4: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
L_80673ED8:
    // 0x80673ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80673EDC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80673EE0: jal         0x80673F0C
    // 0x80673EE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80673F0C(rdram, ctx);
        goto after_5;
    // 0x80673EE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80673EE8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80673EEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80673EF0: nop

    // 0x80673EF4: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
L_80673EF8:
    // 0x80673EF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80673EFC:
    // 0x80673EFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80673F00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80673F04: jr          $ra
    // 0x80673F08: nop

    return;
    // 0x80673F08: nop

;}
RECOMP_FUNC void func_806EE584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE584: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EE588: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806EE58C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806EE590: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806EE594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EE598: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806EE59C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x806EE5A0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806EE5A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806EE5A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x806EE5AC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806EE5B0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806EE5B4: lui         $t2, 0x806F
    ctx->r10 = S32(RELOC_HI16(676, 0X4894) << 16);
    // 0x806EE5B8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806EE5BC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806EE5C0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806EE5C4: lw          $t2, 0x7E4($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(676, 0X4894));
    // 0x806EE5C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806EE5CC: jal         0x806EE338
    // 0x806EE5D0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_806EE338(rdram, ctx);
        goto after_0;
    // 0x806EE5D0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x806EE5D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EE5D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EE5DC: jr          $ra
    // 0x806EE5E0: nop

    return;
    // 0x806EE5E0: nop

;}
RECOMP_FUNC void func_8051EF30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051EF30: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8051EF34: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8051EF38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8051EF3C: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(300, 0X568) << 16);
    // 0x8051EF40: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8051EF44: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8051EF48: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8051EF4C: lw          $t8, -0x1098($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(300, 0X568));
    // 0x8051EF50: jr          $ra
    // 0x8051EF54: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x8051EF54: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8051EF58: nop

    // 0x8051EF5C: nop

;}
RECOMP_FUNC void func_80046560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046560: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80046564: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80046568: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8004656C: lw          $s0, -0x7784($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7784);
    // 0x80046570: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80046574: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80046578: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004657C: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x80046580: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80046584: lw          $s2, 0x10($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X10);
    // 0x80046588: blezl       $t6, L_800465F4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8004658C: lh          $t2, 0x6($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X6);
            goto L_800465F4;
    }
    goto skip_0;
    // 0x8004658C: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    skip_0:
    // 0x80046590: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x80046594: beql        $t7, $zero, L_800465F4
    if (ctx->r15 == 0) {
        // 0x80046598: lh          $t2, 0x6($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X6);
            goto L_800465F4;
    }
    goto skip_1;
    // 0x80046598: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    skip_1:
    // 0x8004659C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_800465A0:
    // 0x800465A0: beql        $a0, $zero, L_800465D0
    if (ctx->r4 == 0) {
        // 0x800465A4: lh          $t0, 0x8($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X8);
            goto L_800465D0;
    }
    goto skip_2;
    // 0x800465A4: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
    skip_2:
    // 0x800465A8: jal         0x80046324
    // 0x800465AC: nop

    func_80046324(rdram, ctx);
        goto after_0;
    // 0x800465AC: nop

    after_0:
    // 0x800465B0: beq         $v0, $zero, L_800465CC
    if (ctx->r2 == 0) {
        // 0x800465B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800465CC;
    }
    // 0x800465B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800465B8: jal         0x80057BAC
    // 0x800465BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80057BAC(rdram, ctx);
        goto after_1;
    // 0x800465BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800465C0: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800465C4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800465C8: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
L_800465CC:
    // 0x800465CC: lh          $t0, 0x8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X8);
L_800465D0:
    // 0x800465D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800465D4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800465D8: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800465DC: beql        $at, $zero, L_800465F4
    if (ctx->r1 == 0) {
        // 0x800465E0: lh          $t2, 0x6($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X6);
            goto L_800465F4;
    }
    goto skip_3;
    // 0x800465E0: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    skip_3:
    // 0x800465E4: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x800465E8: bnel        $t1, $zero, L_800465A0
    if (ctx->r9 != 0) {
        // 0x800465EC: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_800465A0;
    }
    goto skip_4;
    // 0x800465EC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_4:
    // 0x800465F0: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
L_800465F4:
    // 0x800465F4: bnel        $t2, $zero, L_80046608
    if (ctx->r10 != 0) {
        // 0x800465F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80046608;
    }
    goto skip_5;
    // 0x800465F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800465FC: jal         0x80057B14
    // 0x80046600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80057B14(rdram, ctx);
        goto after_2;
    // 0x80046600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80046604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80046608:
    // 0x80046608: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004660C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80046610: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80046614: jr          $ra
    // 0x80046618: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80046618: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004CF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CF88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004CF8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004CF90: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004CF94: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004CF98: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004CF9C: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004CFA0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004CFA4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004CFA8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8004CFAC: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004CFB0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004CFB4: jal         0x8004BDA4
    // 0x8004CFB8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8004BDA4(rdram, ctx);
        goto after_0;
    // 0x8004CFB8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004CFBC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004CFC0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8004CFC4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004CFC8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8004CFCC: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x8004CFD0: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x8004CFD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004CFD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004CFDC: jr          $ra
    // 0x8004CFE0: nop

    return;
    // 0x8004CFE0: nop

;}
RECOMP_FUNC void func_806FCCDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FCCDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806FCCE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FCCE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806FCCE8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FCCEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806FCCF0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x806FCCF4: jal         0x80062684
    // 0x806FCCF8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x806FCCF8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x806FCCFC: jal         0x806FC9BC
    // 0x806FCD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806FC9BC(rdram, ctx);
        goto after_1;
    // 0x806FCD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806FCD04: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x806FCD08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806FCD0C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806FCD10: beql        $t8, $zero, L_806FCD48
    if (ctx->r24 == 0) {
        // 0x806FCD14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806FCD48;
    }
    goto skip_0;
    // 0x806FCD14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806FCD18: jal         0x806FCFE0
    // 0x806FCD1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_806FCFE0(rdram, ctx);
        goto after_2;
    // 0x806FCD1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x806FCD20: addiu       $v0, $s0, 0x14C
    ctx->r2 = ADD32(ctx->r16, 0X14C);
    // 0x806FCD24: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x806FCD28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806FCD2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806FCD30: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x806FCD34: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806FCD38: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x806FCD3C: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x806FCD40: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x806FCD44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806FCD48:
    // 0x806FCD48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806FCD4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806FCD50: jr          $ra
    // 0x806FCD54: nop

    return;
    // 0x806FCD54: nop

;}
RECOMP_FUNC void func_8059F034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059F034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8059F038: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8059F03C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8059F040: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8059F044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8059F048: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x8059F04C: bnel        $t6, $zero, L_8059F0C4
    if (ctx->r14 != 0) {
        // 0x8059F050: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8059F0C4;
    }
    goto skip_0;
    // 0x8059F050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8059F054: jal         0x80049D74
    // 0x8059F058: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x8059F058: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8059F05C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8059F060: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x8059F064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8059F068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8059F06C: jal         0x8004D150
    // 0x8059F070: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x8059F070: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_1:
    // 0x8059F074: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8059F078: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8059F07C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8059F080: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8059F084: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x8059F088: beql        $t0, $zero, L_8059F0C4
    if (ctx->r8 == 0) {
        // 0x8059F08C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8059F0C4;
    }
    goto skip_1;
    // 0x8059F08C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8059F090: lw          $t1, -0x76F8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X76F8);
    // 0x8059F094: addiu       $a0, $zero, 0x4008
    ctx->r4 = ADD32(0, 0X4008);
    // 0x8059F098: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // 0x8059F09C: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x8059F0A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8059F0A4: lw          $t9, 0x14($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X14);
    // 0x8059F0A8: jalr        $t9
    // 0x8059F0AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8059F0AC: nop

    after_2:
    // 0x8059F0B0: jal         0x8059EC8C
    // 0x8059F0B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8059EC8C(rdram, ctx);
        goto after_3;
    // 0x8059F0B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8059F0B8: jal         0x800447C8
    // 0x8059F0BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x8059F0BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8059F0C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8059F0C4:
    // 0x8059F0C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8059F0C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8059F0CC: jr          $ra
    // 0x8059F0D0: nop

    return;
    // 0x8059F0D0: nop

;}
RECOMP_FUNC void func_8040D9A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D9A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8040D9A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8040D9AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8040D9B0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8040D9B4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D9B8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8040D9BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8040D9C0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8040D9C4: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8040D9C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040D9CC: mul.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8040D9D0: jal         0x80066E88
    // 0x8040D9D4: nop

    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8040D9D4: nop

    after_0:
    // 0x8040D9D8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8040D9DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8040D9E0: lui         $at, 0xC110
    ctx->r1 = S32(0XC110 << 16);
    // 0x8040D9E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040D9E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D9EC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8040D9F0: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x8040D9F4: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8040D9F8: nop

    // 0x8040D9FC: bc1fl       L_8040DA24
    if (!c1cs) {
        // 0x8040DA00: swc1        $f20, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
            goto L_8040DA24;
    }
    goto skip_0;
    // 0x8040DA00: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x8040DA04: jal         0x8040D0EC
    // 0x8040DA08: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    func_8040D0EC(rdram, ctx);
        goto after_1;
    // 0x8040DA08: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    after_1:
    // 0x8040DA0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040DA10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040DA14: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8040DA18: jal         0x8040E254
    // 0x8040DA1C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040DA1C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8040DA20: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
L_8040DA24:
    // 0x8040DA24: jal         0x80066E88
    // 0x8040DA28: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8040DA28: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8040DA2C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8040DA30: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8040DA34: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8040DA38: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8040DA3C: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8040DA40: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8040DA44: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8040DA48: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8040DA4C: jal         0x80066DE4
    // 0x8040DA50: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8040DA50: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8040DA54: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8040DA58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040DA5C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8040DA60: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8040DA64: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8040DA68: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8040DA6C: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8040DA70: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8040DA74: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8040DA78: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8040DA7C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8040DA80: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8040DA84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8040DA88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8040DA8C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8040DA90: jr          $ra
    // 0x8040DA94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8040DA94: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80566D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80566D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566D98: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80566D9C: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x80566DA0: addiu       $a2, $zero, 0x417D
    ctx->r6 = ADD32(0, 0X417D);
    // 0x80566DA4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80566DA8: beq         $v1, $zero, L_80566DB8
    if (ctx->r3 == 0) {
        // 0x80566DAC: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80566DB8;
    }
    // 0x80566DAC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80566DB0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80566DB4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80566DB8:
    // 0x80566DB8: bne         $v1, $zero, L_80566DDC
    if (ctx->r3 != 0) {
        // 0x80566DBC: nop
    
            goto L_80566DDC;
    }
    // 0x80566DBC: nop

    // 0x80566DC0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80566DC4: jal         0x8056698C
    // 0x80566DC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8056698C(rdram, ctx);
        goto after_0;
    // 0x80566DC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80566DCC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80566DD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80566DD4: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80566DD8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80566DDC:
    // 0x80566DDC: jal         0x80566674
    // 0x80566DE0: nop

    func_80566674(rdram, ctx);
        goto after_1;
    // 0x80566DE0: nop

    after_1:
    // 0x80566DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566DE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80566DEC: jr          $ra
    // 0x80566DF0: nop

    return;
    // 0x80566DF0: nop

;}
RECOMP_FUNC void func_80455948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455948: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045594C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80455950: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80455954: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80455958: jal         0x80045A34
    // 0x8045595C: ori         $a1, $a1, 0x6F30
    ctx->r5 = ctx->r5 | 0X6F30;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8045595C: ori         $a1, $a1, 0x6F30
    ctx->r5 = ctx->r5 | 0X6F30;
    after_0:
    // 0x80455960: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80455964: ori         $a1, $a1, 0x6F30
    ctx->r5 = ctx->r5 | 0X6F30;
    // 0x80455968: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8045596C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80455970: jal         0x800657CC
    // 0x80455974: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x80455974: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80455978: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8045597C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80455980: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X11324) << 16);
    // 0x80455984: addiu       $t6, $t6, 0x5704
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X11324));
    // 0x80455988: lui         $t7, 0x8045
    ctx->r15 = S32(RELOC_HI16(98, 0X13564) << 16);
    // 0x8045598C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455990: addiu       $t7, $t7, 0x7944
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(98, 0X13564));
    // 0x80455994: sw          $t6, 0x1F8($v0)
    MEM_W(0X1F8, ctx->r2) = ctx->r14;
    // 0x80455998: sw          $v1, 0x1F4($v0)
    MEM_W(0X1F4, ctx->r2) = ctx->r3;
    // 0x8045599C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804559A0: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
    // 0x804559A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804559A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804559AC: jr          $ra
    // 0x804559B0: nop

    return;
    // 0x804559B0: nop

;}
RECOMP_FUNC void func_806EDEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EDEEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EDEF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EDEF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EDEF8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EDEFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EDF00: jal         0x800577D8
    // 0x806EDF04: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EDF04: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x806EDF08: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806EDF0C: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x806EDF10: jal         0x80065ABC
    // 0x806EDF14: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x806EDF14: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_1:
    // 0x806EDF18: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806EDF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDF20: jal         0x80049D74
    // 0x806EDF24: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_80049D74(rdram, ctx);
        goto after_2;
    // 0x806EDF24: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_2:
    // 0x806EDF28: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806EDF2C: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806EDF30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDF34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806EDF38: jal         0x8004D150
    // 0x806EDF3C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x806EDF3C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x806EDF40: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x806EDF44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDF48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806EDF4C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806EDF50: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x806EDF54: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x806EDF58: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x806EDF5C: beql        $t0, $zero, L_806EDFE4
    if (ctx->r8 == 0) {
        // 0x806EDF60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EDFE4;
    }
    goto skip_0;
    // 0x806EDF60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EDF64: jal         0x8004D618
    // 0x806EDF68: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x806EDF68: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_4:
    // 0x806EDF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDF70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDF74: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806EDF78: jal         0x806EE584
    // 0x806EDF7C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_5;
    // 0x806EDF7C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x806EDF80: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x806EDF84: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x806EDF88: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x806EDF8C: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x806EDF90: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806EDF94: lbu         $t1, 0xF0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XF0);
    // 0x806EDF98: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x806EDF9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EDFA0: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x806EDFA4: addiu       $t3, $t2, 0x20
    ctx->r11 = ADD32(ctx->r10, 0X20);
    // 0x806EDFA8: sb          $t3, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = ctx->r11;
    // 0x806EDFAC: lw          $t4, 0x478($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X478);
    // 0x806EDFB0: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x806EDFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDFB8: sb          $zero, 0xF2($t4)
    MEM_B(0XF2, ctx->r12) = 0;
    // 0x806EDFBC: sb          $t5, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r13;
    // 0x806EDFC0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806EDFC4: sb          $t6, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r14;
    // 0x806EDFC8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806EDFCC: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
    // 0x806EDFD0: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x806EDFD4: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806EDFD8: jal         0x806EC098
    // 0x806EDFDC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    func_806EC098(rdram, ctx);
        goto after_6;
    // 0x806EDFDC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    after_6:
    // 0x806EDFE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDFE4:
    // 0x806EDFE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EDFE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EDFEC: jr          $ra
    // 0x806EDFF0: nop

    return;
    // 0x806EDFF0: nop

;}
RECOMP_FUNC void func_8070C714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070C714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070C718: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8070C71C: beq         $at, $zero, L_8070C72C
    if (ctx->r1 == 0) {
        // 0x8070C720: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8070C72C;
    }
    // 0x8070C720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070C724: b           L_8070C788
    // 0x8070C728: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8070C788;
    // 0x8070C728: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8070C72C:
    // 0x8070C72C: bnel        $a0, $a1, L_8070C740
    if (ctx->r4 != ctx->r5) {
        // 0x8070C730: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8070C740;
    }
    goto skip_0;
    // 0x8070C730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x8070C734: b           L_8070C788
    // 0x8070C738: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8070C788;
    // 0x8070C738: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8070C73C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_8070C740:
    // 0x8070C740: jal         0x800653D8
    // 0x8070C744: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8070C744: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8070C748: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8070C74C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8070C750: subu        $t6, $a1, $a0
    ctx->r14 = SUB32(ctx->r5, ctx->r4);
    // 0x8070C754: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8070C758: div         $zero, $v0, $t7
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r15)));
    // 0x8070C75C: mfhi        $t8
    ctx->r24 = hi;
    // 0x8070C760: bne         $t7, $zero, L_8070C76C
    if (ctx->r15 != 0) {
        // 0x8070C764: nop
    
            goto L_8070C76C;
    }
    // 0x8070C764: nop

    // 0x8070C768: break       7
    do_break(2154874728);
L_8070C76C:
    // 0x8070C76C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8070C770: bne         $t7, $at, L_8070C784
    if (ctx->r15 != ctx->r1) {
        // 0x8070C774: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8070C784;
    }
    // 0x8070C774: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8070C778: bne         $v0, $at, L_8070C784
    if (ctx->r2 != ctx->r1) {
        // 0x8070C77C: nop
    
            goto L_8070C784;
    }
    // 0x8070C77C: nop

    // 0x8070C780: break       6
    do_break(2154874752);
L_8070C784:
    // 0x8070C784: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
L_8070C788:
    // 0x8070C788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070C78C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070C790: jr          $ra
    // 0x8070C794: nop

    return;
    // 0x8070C794: nop

;}
RECOMP_FUNC void func_8001AA4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AA4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001AA50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AA54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001AA58: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001AA5C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001AA60: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8001AA64: sw          $t6, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r14;
    // 0x8001AA68: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
    // 0x8001AA6C: jal         0x8001A68C
    // 0x8001AA70: sw          $a2, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r6;
    func_8001A68C(rdram, ctx);
        goto after_0;
    // 0x8001AA70: sw          $a2, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r6;
    after_0:
    // 0x8001AA74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AA78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001AA7C: jr          $ra
    // 0x8001AA80: nop

    return;
    // 0x8001AA80: nop

;}
RECOMP_FUNC void func_80710C50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80710C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80710C54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80710C58: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80710C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80710C60: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80710C64: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80710C68: lui         $t8, 0x8071
    ctx->r24 = S32(RELOC_HI16(724, 0X18C8) << 16);
    // 0x80710C6C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80710C70: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80710C74: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80710C78: lw          $t8, 0xCB8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(724, 0X18C8));
    // 0x80710C7C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80710C80: bne         $a1, $at, L_80710C90
    if (ctx->r5 != ctx->r1) {
        // 0x80710C84: sw          $t8, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->r24;
            goto L_80710C90;
    }
    // 0x80710C84: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80710C88: jal         0x8070F428
    // 0x80710C8C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    func_8070F428(rdram, ctx);
        goto after_0;
    // 0x80710C8C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    after_0:
L_80710C90:
    // 0x80710C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80710C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80710C98: jr          $ra
    // 0x80710C9C: nop

    return;
    // 0x80710C9C: nop

;}
RECOMP_FUNC void Idle_InitVideo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067390: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80067394: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x80067398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006739C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800673A0: beq         $v0, $zero, L_800673C8
    if (ctx->r2 == 0) {
        // 0x800673A4: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800673C8;
    }
    // 0x800673A4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800673A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800673AC: beq         $v0, $at, L_800673D8
    if (ctx->r2 == ctx->r1) {
        // 0x800673B0: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800673D8;
    }
    // 0x800673B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800673B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800673B8: beq         $v0, $at, L_800673E8
    if (ctx->r2 == ctx->r1) {
        // 0x800673BC: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_800673E8;
    }
    // 0x800673BC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800673C0: b           L_800673F4
    // 0x800673C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800673F4;
    // 0x800673C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800673C8:
    // 0x800673C8: jal         0x80087010
    // 0x800673CC: addiu       $a0, $a0, -0x4EA0
    ctx->r4 = ADD32(ctx->r4, -0X4EA0);
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x800673CC: addiu       $a0, $a0, -0x4EA0
    ctx->r4 = ADD32(ctx->r4, -0X4EA0);
    after_0:
    // 0x800673D0: b           L_800673F4
    // 0x800673D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800673F4;
    // 0x800673D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800673D8:
    // 0x800673D8: jal         0x80087010
    // 0x800673DC: addiu       $a0, $a0, -0x5300
    ctx->r4 = ADD32(ctx->r4, -0X5300);
    osViSetMode_recomp(rdram, ctx);
        goto after_1;
    // 0x800673DC: addiu       $a0, $a0, -0x5300
    ctx->r4 = ADD32(ctx->r4, -0X5300);
    after_1:
    // 0x800673E0: b           L_800673F4
    // 0x800673E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800673F4;
    // 0x800673E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800673E8:
    // 0x800673E8: jal         0x80087010
    // 0x800673EC: addiu       $a0, $a0, -0x4A40
    ctx->r4 = ADD32(ctx->r4, -0X4A40);
    osViSetMode_recomp(rdram, ctx);
        goto after_2;
    // 0x800673EC: addiu       $a0, $a0, -0x4A40
    ctx->r4 = ADD32(ctx->r4, -0X4A40);
    after_2:
    // 0x800673F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800673F4:
    // 0x800673F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800673F8: jr          $ra
    // 0x800673FC: nop

    return;
    // 0x800673FC: nop

;}
RECOMP_FUNC void func_806B27CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B27CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B27D0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B27D4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B27D8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B27DC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B27E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B27E4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B27E8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B27EC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B27F0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B27F4: jr          $ra
    // 0x806B27F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B27F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8076DDD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076DDD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8076DDD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8076DDD8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8076DDDC: lui         $t6, 0x8077
    ctx->r14 = S32(RELOC_HI16(766, 0X3A28) << 16);
    // 0x8076DDE0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8076DDE4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8076DDE8: addiu       $t6, $t6, 0x218
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(766, 0X3A28));
    // 0x8076DDEC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8076DDF0: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8076DDF4: addiu       $at, $zero, 0x4649
    ctx->r1 = ADD32(0, 0X4649);
    // 0x8076DDF8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8076DDFC: beq         $v0, $at, L_8076DE18
    if (ctx->r2 == ctx->r1) {
        // 0x8076DE00: sw          $zero, 0x138($a0)
        MEM_W(0X138, ctx->r4) = 0;
            goto L_8076DE18;
    }
    // 0x8076DE00: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8076DE04: addiu       $at, $zero, 0x464A
    ctx->r1 = ADD32(0, 0X464A);
    // 0x8076DE08: beq         $v0, $at, L_8076DE30
    if (ctx->r2 == ctx->r1) {
        // 0x8076DE0C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8076DE30;
    }
    // 0x8076DE0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076DE10: b           L_8076DE40
    // 0x8076DE14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8076DE40;
    // 0x8076DE14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8076DE18:
    // 0x8076DE18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076DE1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8076DE20: jal         0x8076DD8C
    // 0x8076DE24: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_0;
    // 0x8076DE24: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8076DE28: b           L_8076DE40
    // 0x8076DE2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8076DE40;
    // 0x8076DE2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8076DE30:
    // 0x8076DE30: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8076DE34: jal         0x8076DD8C
    // 0x8076DE38: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_1;
    // 0x8076DE38: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8076DE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8076DE40:
    // 0x8076DE40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8076DE44: jr          $ra
    // 0x8076DE48: nop

    return;
    // 0x8076DE48: nop

;}
RECOMP_FUNC void func_804412BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804412BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804412C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804412C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804412C8: jal         0x8043F33C
    // 0x804412CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8043F33C(rdram, ctx);
        goto after_0;
    // 0x804412CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804412D0: jal         0x8043FDF0
    // 0x804412D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FDF0(rdram, ctx);
        goto after_1;
    // 0x804412D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804412D8: jal         0x8043F150
    // 0x804412DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_2;
    // 0x804412DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804412E0: jal         0x8044045C
    // 0x804412E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044045C(rdram, ctx);
        goto after_3;
    // 0x804412E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804412E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804412EC: jal         0x8043EF80
    // 0x804412F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8043EF80(rdram, ctx);
        goto after_4;
    // 0x804412F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x804412F4: jal         0x804406D0
    // 0x804412F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804406D0(rdram, ctx);
        goto after_5;
    // 0x804412F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804412FC: beq         $v0, $zero, L_80441314
    if (ctx->r2 == 0) {
        // 0x80441300: nop
    
            goto L_80441314;
    }
    // 0x80441300: nop

    // 0x80441304: jal         0x804411A0
    // 0x80441308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804411A0(rdram, ctx);
        goto after_6;
    // 0x80441308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8044130C: b           L_80441320
    // 0x80441310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80441320;
    // 0x80441310: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441314:
    // 0x80441314: jal         0x8043F93C
    // 0x80441318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_7;
    // 0x80441318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8044131C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80441320:
    // 0x80441320: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80441324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80441328: jr          $ra
    // 0x8044132C: nop

    return;
    // 0x8044132C: nop

;}
RECOMP_FUNC void func_80064830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064838: jal         0x80064E84
    // 0x8006483C: nop

    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8006483C: nop

    after_0:
    // 0x80064840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80064844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064848: jr          $ra
    // 0x8006484C: nop

    return;
    // 0x8006484C: nop

;}
RECOMP_FUNC void func_806ED088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806ED08C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ED090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806ED094: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806ED098: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806ED09C: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806ED0A0: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806ED0A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806ED0A8: beq         $v0, $at, L_806ED0C4
    if (ctx->r2 == ctx->r1) {
        // 0x806ED0AC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806ED0C4;
    }
    // 0x806ED0AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806ED0B0: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806ED0B4: beq         $v0, $at, L_806ED0D4
    if (ctx->r2 == ctx->r1) {
        // 0x806ED0B8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_806ED0D4;
    }
    // 0x806ED0B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806ED0BC: b           L_806ED108
    // 0x806ED0C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806ED108;
    // 0x806ED0C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806ED0C4:
    // 0x806ED0C4: jal         0x806ED034
    // 0x806ED0C8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_806ED034(rdram, ctx);
        goto after_0;
    // 0x806ED0C8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x806ED0CC: b           L_806ED108
    // 0x806ED0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806ED108;
    // 0x806ED0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806ED0D4:
    // 0x806ED0D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x806ED0D8: jal         0x806ECF00
    // 0x806ED0DC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_806ECF00(rdram, ctx);
        goto after_1;
    // 0x806ED0DC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_1:
    // 0x806ED0E0: beq         $v0, $zero, L_806ED104
    if (ctx->r2 == 0) {
        // 0x806ED0E4: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_806ED104;
    }
    // 0x806ED0E4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806ED0E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x806ED0EC: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x806ED0F0: jal         0x80067D5C
    // 0x806ED0F4: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x806ED0F4: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_2:
    // 0x806ED0F8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x806ED0FC: jal         0x80067818
    // 0x806ED100: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806ED100: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_806ED104:
    // 0x806ED104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806ED108:
    // 0x806ED108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806ED10C: jr          $ra
    // 0x806ED110: nop

    return;
    // 0x806ED110: nop

;}
RECOMP_FUNC void func_805DCDC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCDC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DCDCC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805DCDD0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x805DCDD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DCDD8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x805DCDDC: bne         $a1, $at, L_805DCE14
    if (ctx->r5 != ctx->r1) {
        // 0x805DCDE0: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_805DCE14;
    }
    // 0x805DCDE0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DCDE4: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x805DCDE8: beql        $a1, $zero, L_805DCE14
    if (ctx->r5 == 0) {
        // 0x805DCDEC: sw          $zero, 0x8($v1)
        MEM_W(0X8, ctx->r3) = 0;
            goto L_805DCE14;
    }
    goto skip_0;
    // 0x805DCDEC: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    skip_0:
    // 0x805DCDF0: jal         0x80047EB0
    // 0x805DCDF4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80047EB0(rdram, ctx);
        goto after_0;
    // 0x805DCDF4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805DCDF8: beq         $v0, $zero, L_805DCE10
    if (ctx->r2 == 0) {
        // 0x805DCDFC: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_805DCE10;
    }
    // 0x805DCDFC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805DCE00: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x805DCE04: jal         0x8004816C
    // 0x805DCE08: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x805DCE08: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x805DCE0C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_805DCE10:
    // 0x805DCE10: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
L_805DCE14:
    // 0x805DCE14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DCE18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DCE1C: jr          $ra
    // 0x805DCE20: nop

    return;
    // 0x805DCE20: nop

;}
RECOMP_FUNC void func_806B0FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B0FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B0FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B0FD4: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x806B0FD8: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806B0FDC: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806B0FE0: jal         0x80065ABC
    // 0x806B0FE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x806B0FE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806B0FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806B0FEC: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x806B0FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B0FF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B0FF8: jr          $ra
    // 0x806B0FFC: nop

    return;
    // 0x806B0FFC: nop

;}
RECOMP_FUNC void func_804533DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804533DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804533E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804533E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804533E8: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x804533EC: lui         $a1, 0x8046
    ctx->r5 = S32(RELOC_HI16(98, 0X13CCC) << 16);
    // 0x804533F0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x804533F4: lw          $v1, 0x6CE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CE4);
    // 0x804533F8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x804533FC: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80453400: lw          $a1, -0x7F54($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13CCC));
    // 0x80453404: jalr        $a1
    // 0x80453408: nop

    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_0;
    // 0x80453408: nop

    after_0:
    // 0x8045340C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453414: jr          $ra
    // 0x80453418: nop

    return;
    // 0x80453418: nop

;}
RECOMP_FUNC void floorf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081FE0: floor.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = S32(floorf(ctx->f12.fl));
    // 0x80081FE4: jr          $ra
    // 0x80081FE8: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
    return;
    // 0x80081FE8: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
;}
RECOMP_FUNC void func_8075F1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075F1B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8075F1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8075F1B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8075F1BC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x8075F1C0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8075F1C4: jal         0x80067BBC
    // 0x8075F1C8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8075F1C8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8075F1CC: addiu       $a0, $zero, 0x75
    ctx->r4 = ADD32(0, 0X75);
    // 0x8075F1D0: jal         0x80067F78
    // 0x8075F1D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8075F1D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8075F1D8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8075F1DC: sh          $v0, 0x1F0($t6)
    MEM_H(0X1F0, ctx->r14) = ctx->r2;
    // 0x8075F1E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8075F1E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8075F1E8: jr          $ra
    // 0x8075F1EC: nop

    return;
    // 0x8075F1EC: nop

;}
RECOMP_FUNC void func_8004E0B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E0B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004E0B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004E0BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8004E0C0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8004E0C4: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8004E0C8: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x8004E0CC: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004E0D0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8004E0D4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004E0D8: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x8004E0DC: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8004E0E0: beql        $v1, $zero, L_8004E118
    if (ctx->r3 == 0) {
        // 0x8004E0E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E118;
    }
    goto skip_0;
    // 0x8004E0E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004E0E8: beql        $v1, $at, L_8004E118
    if (ctx->r3 == ctx->r1) {
        // 0x8004E0EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004E118;
    }
    goto skip_1;
    // 0x8004E0EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004E0F0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8004E0F4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004E0F8: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x8004E0FC: beq         $v1, $at, L_8004E114
    if (ctx->r3 == ctx->r1) {
        // 0x8004E100: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004E114;
    }
    // 0x8004E100: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004E104: beq         $v1, $at, L_8004E114
    if (ctx->r3 == ctx->r1) {
        // 0x8004E108: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004E114;
    }
    // 0x8004E108: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004E10C: jal         0x8004D06C
    // 0x8004E110: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8004D06C(rdram, ctx);
        goto after_0;
    // 0x8004E110: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
L_8004E114:
    // 0x8004E114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004E118:
    // 0x8004E118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004E11C: jr          $ra
    // 0x8004E120: nop

    return;
    // 0x8004E120: nop

;}
RECOMP_FUNC void func_8001AE1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001AE20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001AE24: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001AE28: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001AE2C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8001AE30: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001AE34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AE38: beq         $a0, $zero, L_8001AE54
    if (ctx->r4 == 0) {
        // 0x8001AE3C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8001AE54;
    }
    // 0x8001AE3C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8001AE40: lhu         $a0, 0x20($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X20);
    // 0x8001AE44: jal         0x8001AF28
    // 0x8001AE48: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8001AF28(rdram, ctx);
        goto after_0;
    // 0x8001AE48: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001AE4C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8001AE50: sh          $v0, 0x20($a3)
    MEM_H(0X20, ctx->r7) = ctx->r2;
L_8001AE54:
    // 0x8001AE54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AE58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001AE5C: jr          $ra
    // 0x8001AE60: nop

    return;
    // 0x8001AE60: nop

;}
RECOMP_FUNC void func_80519BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519BE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519BE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80519BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519BF0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80519BF4: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x80519BF8: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80519BFC: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(291, 0X25D8) << 16);
    // 0x80519C00: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x80519C04: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80519C08: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x80519C0C: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80519C10: lw          $t7, -0x5DB8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(291, 0X25D8));
    // 0x80519C14: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(291, 0X25E0) << 16);
    // 0x80519C18: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80519C1C: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
    // 0x80519C20: sw          $v0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r2;
    // 0x80519C24: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
    // 0x80519C28: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x80519C2C: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80519C30: lw          $t8, -0x5DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(291, 0X25E0));
    // 0x80519C34: sw          $t8, 0x204($a2)
    MEM_W(0X204, ctx->r6) = ctx->r24;
    // 0x80519C38: jal         0x805190BC
    // 0x80519C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805190BC(rdram, ctx);
        goto after_0;
    // 0x80519C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80519C40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80519C44: jal         0x80517EBC
    // 0x80519C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80517EBC(rdram, ctx);
        goto after_1;
    // 0x80519C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80519C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80519C50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519C54: jr          $ra
    // 0x80519C58: nop

    return;
    // 0x80519C58: nop

;}
RECOMP_FUNC void func_80067ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067AD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067AD4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80067AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067ADC: jal         0x80018CB0
    // 0x80067AE0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80018CB0(rdram, ctx);
        goto after_0;
    // 0x80067AE0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_0:
    // 0x80067AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067AEC: jr          $ra
    // 0x80067AF0: nop

    return;
    // 0x80067AF0: nop

;}
RECOMP_FUNC void func_8002DB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DB78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DB7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DB80: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DB84: jal         0x8002DB14
    // 0x8002DB88: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8002DB14(rdram, ctx);
        goto after_0;
    // 0x8002DB88: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002DB8C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DB90: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002DB94: sb          $t7, 0xF7($t8)
    MEM_B(0XF7, ctx->r24) = ctx->r15;
    // 0x8002DB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DB9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DBA0: jr          $ra
    // 0x8002DBA4: nop

    return;
    // 0x8002DBA4: nop

;}
RECOMP_FUNC void func_80564A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80564A8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80564A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80564A94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80564A98: jal         0x805640B8
    // 0x80564A9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_805640B8(rdram, ctx);
        goto after_0;
    // 0x80564A9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80564AA0: jal         0x8056417C
    // 0x80564AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8056417C(rdram, ctx);
        goto after_1;
    // 0x80564AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80564AA8: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80564AAC: lhu         $t8, 0x52C($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X52C);
    // 0x80564AB0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80564AB4: beq         $t9, $zero, L_80564ACC
    if (ctx->r25 == 0) {
        // 0x80564AB8: nop
    
            goto L_80564ACC;
    }
    // 0x80564AB8: nop

    // 0x80564ABC: jal         0x80564744
    // 0x80564AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80564744(rdram, ctx);
        goto after_2;
    // 0x80564AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80564AC4: b           L_80564AD8
    // 0x80564AC8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
        goto L_80564AD8;
    // 0x80564AC8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_80564ACC:
    // 0x80564ACC: jal         0x805648B8
    // 0x80564AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805648B8(rdram, ctx);
        goto after_3;
    // 0x80564AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80564AD4: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
L_80564AD8:
    // 0x80564AD8: blezl       $v0, L_80564AF0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80564ADC: lw          $v1, 0x1F4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1F4);
            goto L_80564AF0;
    }
    goto skip_0;
    // 0x80564ADC: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x80564AE0: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80564AE4: b           L_80564C24
    // 0x80564AE8: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
        goto L_80564C24;
    // 0x80564AE8: sw          $t0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r8;
    // 0x80564AEC: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
L_80564AF0:
    // 0x80564AF0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80564AF4: lw          $v0, 0x51C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X51C);
    // 0x80564AF8: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x80564AFC: beq         $at, $zero, L_80564B6C
    if (ctx->r1 == 0) {
        // 0x80564B00: nop
    
            goto L_80564B6C;
    }
    // 0x80564B00: nop

    // 0x80564B04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80564B08: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80564B0C: mfhi        $t1
    ctx->r9 = hi;
    // 0x80564B10: addiu       $t2, $t1, 0x3
    ctx->r10 = ADD32(ctx->r9, 0X3);
    // 0x80564B14: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80564B18: jal         0x800653D8
    // 0x80564B1C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x80564B1C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_4:
    // 0x80564B20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80564B24: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x80564B28: mfhi        $t3
    ctx->r11 = hi;
    // 0x80564B2C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80564B30: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80564B34: bne         $a0, $zero, L_80564B40
    if (ctx->r4 != 0) {
        // 0x80564B38: nop
    
            goto L_80564B40;
    }
    // 0x80564B38: nop

    // 0x80564B3C: break       7
    do_break(2153139004);
L_80564B40:
    // 0x80564B40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80564B44: bne         $a0, $at, L_80564B58
    if (ctx->r4 != ctx->r1) {
        // 0x80564B48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80564B58;
    }
    // 0x80564B48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80564B4C: bne         $v0, $at, L_80564B58
    if (ctx->r2 != ctx->r1) {
        // 0x80564B50: nop
    
            goto L_80564B58;
    }
    // 0x80564B50: nop

    // 0x80564B54: break       6
    do_break(2153139028);
L_80564B58:
    // 0x80564B58: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80564B5C: mflo        $t5
    ctx->r13 = lo;
    // 0x80564B60: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80564B64: b           L_80564BF0
    // 0x80564B68: sw          $t6, 0x51C($v1)
    MEM_W(0X51C, ctx->r3) = ctx->r14;
        goto L_80564BF0;
    // 0x80564B68: sw          $t6, 0x51C($v1)
    MEM_W(0X51C, ctx->r3) = ctx->r14;
L_80564B6C:
    // 0x80564B6C: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x80564B70: mfhi        $t7
    ctx->r15 = hi;
    // 0x80564B74: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80564B78: bne         $a0, $zero, L_80564B84
    if (ctx->r4 != 0) {
        // 0x80564B7C: nop
    
            goto L_80564B84;
    }
    // 0x80564B7C: nop

    // 0x80564B80: break       7
    do_break(2153139072);
L_80564B84:
    // 0x80564B84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80564B88: bne         $a0, $at, L_80564B9C
    if (ctx->r4 != ctx->r1) {
        // 0x80564B8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80564B9C;
    }
    // 0x80564B8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80564B90: bne         $v0, $at, L_80564B9C
    if (ctx->r2 != ctx->r1) {
        // 0x80564B94: nop
    
            goto L_80564B9C;
    }
    // 0x80564B94: nop

    // 0x80564B98: break       6
    do_break(2153139096);
L_80564B9C:
    // 0x80564B9C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80564BA0: jal         0x800653D8
    // 0x80564BA4: nop

    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x80564BA4: nop

    after_5:
    // 0x80564BA8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80564BAC: div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // 0x80564BB0: mfhi        $t8
    ctx->r24 = hi;
    // 0x80564BB4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80564BB8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80564BBC: bne         $a0, $zero, L_80564BC8
    if (ctx->r4 != 0) {
        // 0x80564BC0: nop
    
            goto L_80564BC8;
    }
    // 0x80564BC0: nop

    // 0x80564BC4: break       7
    do_break(2153139140);
L_80564BC8:
    // 0x80564BC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80564BCC: bne         $a0, $at, L_80564BE0
    if (ctx->r4 != ctx->r1) {
        // 0x80564BD0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80564BE0;
    }
    // 0x80564BD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80564BD4: bne         $v0, $at, L_80564BE0
    if (ctx->r2 != ctx->r1) {
        // 0x80564BD8: nop
    
            goto L_80564BE0;
    }
    // 0x80564BD8: nop

    // 0x80564BDC: break       6
    do_break(2153139164);
L_80564BE0:
    // 0x80564BE0: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80564BE4: mflo        $t0
    ctx->r8 = lo;
    // 0x80564BE8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80564BEC: sw          $t1, 0x51C($v1)
    MEM_W(0X51C, ctx->r3) = ctx->r9;
L_80564BF0:
    // 0x80564BF0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80564BF4: jal         0x80067BBC
    // 0x80564BF8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x80564BF8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x80564BFC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80564C00: jal         0x80067818
    // 0x80564C04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x80564C04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80564C08: jal         0x80563D64
    // 0x80564C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80563D64(rdram, ctx);
        goto after_8;
    // 0x80564C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80564C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80564C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80564C18: jal         0x80565C28
    // 0x80564C1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80565C28(rdram, ctx);
        goto after_9;
    // 0x80564C1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80564C20: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
L_80564C24:
    // 0x80564C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80564C28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80564C2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80564C30: jr          $ra
    // 0x80564C34: nop

    return;
    // 0x80564C34: nop

;}
RECOMP_FUNC void func_80432A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80432A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80432A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80432A14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80432A18: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80432A1C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80432A20: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80432A24: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80432A28: bnel        $v0, $at, L_80432A54
    if (ctx->r2 != ctx->r1) {
        // 0x80432A2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80432A54;
    }
    goto skip_0;
    // 0x80432A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80432A30: lh          $t8, 0x144($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X144);
    // 0x80432A34: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80432A38: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80432A3C: slti        $at, $t8, 0xB
    ctx->r1 = SIGNED(ctx->r24) < 0XB ? 1 : 0;
    // 0x80432A40: beq         $at, $zero, L_80432A50
    if (ctx->r1 == 0) {
        // 0x80432A44: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_80432A50;
    }
    // 0x80432A44: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80432A48: jal         0x8002F6E4
    // 0x80432A4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x80432A4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
L_80432A50:
    // 0x80432A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80432A54:
    // 0x80432A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80432A58: jr          $ra
    // 0x80432A5C: nop

    return;
    // 0x80432A5C: nop

;}
RECOMP_FUNC void func_806ED45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED45C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806ED460: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x806ED464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806ED468: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806ED46C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x806ED470: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806ED474: jal         0x806EC03C
    // 0x806ED478: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_806EC03C(rdram, ctx);
        goto after_0;
    // 0x806ED478: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x806ED47C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x806ED480: jal         0x80047090
    // 0x806ED484: addiu       $a0, $zero, 0x45E4
    ctx->r4 = ADD32(0, 0X45E4);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x806ED484: addiu       $a0, $zero, 0x45E4
    ctx->r4 = ADD32(0, 0X45E4);
    after_1:
    // 0x806ED488: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x806ED48C: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x806ED490: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806ED494: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x806ED498: lui         $at, 0x45E4
    ctx->r1 = S32(0X45E4 << 16);
    // 0x806ED49C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x806ED4A0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806ED4A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806ED4A8: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x806ED4AC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806ED4B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806ED4B4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4CE0) << 16);
    // 0x806ED4B8: lwc1        $f6, 0xC30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4CE0));
    // 0x806ED4BC: lwc1        $f4, 0x8C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x806ED4C0: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x806ED4C4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x806ED4C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806ED4CC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806ED4D0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x806ED4D4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x806ED4D8: jal         0x8004613C
    // 0x806ED4DC: nop

    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x806ED4DC: nop

    after_2:
    // 0x806ED4E0: beq         $v0, $zero, L_806ED568
    if (ctx->r2 == 0) {
        // 0x806ED4E4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806ED568;
    }
    // 0x806ED4E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806ED4E8: lhu         $t8, 0x2A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2A);
    // 0x806ED4EC: lhu         $t0, 0xE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XE);
    // 0x806ED4F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806ED4F4: andi        $t9, $t8, 0x3FF
    ctx->r25 = ctx->r24 & 0X3FF;
    // 0x806ED4F8: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x806ED4FC: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x806ED500: sh          $t2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r10;
    // 0x806ED504: jal         0x80047F9C
    // 0x806ED508: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x806ED508: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x806ED50C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x806ED510: sb          $t3, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r11;
    // 0x806ED514: jal         0x8005FDC4
    // 0x806ED518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x806ED518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806ED51C: jal         0x806EF3F8
    // 0x806ED520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF3F8(rdram, ctx);
        goto after_5;
    // 0x806ED520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806ED524: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806ED528: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806ED52C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x806ED530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ED534: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806ED538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ED53C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806ED540: bc1f        L_806ED560
    if (!c1cs) {
        // 0x806ED544: nop
    
            goto L_806ED560;
    }
    // 0x806ED544: nop

    // 0x806ED548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ED54C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ED550: jal         0x806EF4A0
    // 0x806ED554: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_806EF4A0(rdram, ctx);
        goto after_6;
    // 0x806ED554: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x806ED558: b           L_806ED56C
    // 0x806ED55C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806ED56C;
    // 0x806ED55C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ED560:
    // 0x806ED560: jal         0x806EF4A0
    // 0x806ED564: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806EF4A0(rdram, ctx);
        goto after_7;
    // 0x806ED564: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_806ED568:
    // 0x806ED568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ED56C:
    // 0x806ED56C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806ED570: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806ED574: jr          $ra
    // 0x806ED578: nop

    return;
    // 0x806ED578: nop

;}
RECOMP_FUNC void func_80671954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671954: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80671958: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8067195C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80671960: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80671964: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80671968: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8067196C: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x80671970: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80671974: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80671978: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8067197C: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80671980: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80671984: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80671988: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8067198C: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80671990: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x80671994: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80671998: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8067199C: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x806719A0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x806719A4: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    // 0x806719A8: jal         0x8005C27C
    // 0x806719AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x806719AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x806719B0: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x806719B4: bne         $at, $zero, L_806719CC
    if (ctx->r1 != 0) {
        // 0x806719B8: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_806719CC;
    }
    // 0x806719B8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x806719BC: lw          $t1, 0x1F4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X1F4);
    // 0x806719C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806719C4: b           L_80671A9C
    // 0x806719C8: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
        goto L_80671A9C;
    // 0x806719C8: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_806719CC:
    // 0x806719CC: addiu       $t0, $s0, 0x1
    ctx->r8 = ADD32(ctx->r16, 0X1);
    // 0x806719D0: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x806719D4: beq         $at, $zero, L_80671A44
    if (ctx->r1 == 0) {
        // 0x806719D8: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80671A44;
    }
    // 0x806719D8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x806719DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806719E0: subu        $a3, $a2, $a0
    ctx->r7 = SUB32(ctx->r6, ctx->r4);
    // 0x806719E4: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x806719E8: beq         $a3, $zero, L_80671A10
    if (ctx->r7 == 0) {
        // 0x806719EC: addu        $a1, $a3, $a0
        ctx->r5 = ADD32(ctx->r7, ctx->r4);
            goto L_80671A10;
    }
    // 0x806719EC: addu        $a1, $a3, $a0
    ctx->r5 = ADD32(ctx->r7, ctx->r4);
    // 0x806719F0: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x806719F4: addu        $v0, $s1, $t2
    ctx->r2 = ADD32(ctx->r17, ctx->r10);
L_806719F8:
    // 0x806719F8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x806719FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80671A00: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80671A04: bne         $a1, $a0, L_806719F8
    if (ctx->r5 != ctx->r4) {
        // 0x80671A08: addu        $v1, $v1, $t3
        ctx->r3 = ADD32(ctx->r3, ctx->r11);
            goto L_806719F8;
    }
    // 0x80671A08: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80671A0C: beq         $a0, $a2, L_80671A44
    if (ctx->r4 == ctx->r6) {
        // 0x80671A10: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_80671A44;
    }
L_80671A10:
    // 0x80671A10: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80671A14: addu        $v0, $s1, $t4
    ctx->r2 = ADD32(ctx->r17, ctx->r12);
L_80671A18:
    // 0x80671A18: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80671A1C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80671A20: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80671A24: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x80671A28: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80671A2C: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x80671A30: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80671A34: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80671A38: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80671A3C: bne         $a0, $a2, L_80671A18
    if (ctx->r4 != ctx->r6) {
        // 0x80671A40: addu        $v1, $v1, $t8
        ctx->r3 = ADD32(ctx->r3, ctx->r24);
            goto L_80671A18;
    }
    // 0x80671A40: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
L_80671A44:
    // 0x80671A44: beq         $v1, $zero, L_80671A5C
    if (ctx->r3 == 0) {
        // 0x80671A48: slti        $at, $t0, 0x4
        ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
            goto L_80671A5C;
    }
    // 0x80671A48: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x80671A4C: lw          $t9, 0x1F4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X1F4);
    // 0x80671A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80671A54: b           L_80671A9C
    // 0x80671A58: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
        goto L_80671A9C;
    // 0x80671A58: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_80671A5C:
    // 0x80671A5C: beq         $at, $zero, L_80671A90
    if (ctx->r1 == 0) {
        // 0x80671A60: negu        $s0, $t0
        ctx->r16 = SUB32(0, ctx->r8);
            goto L_80671A90;
    }
    // 0x80671A60: negu        $s0, $t0
    ctx->r16 = SUB32(0, ctx->r8);
    // 0x80671A64: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x80671A68: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    // 0x80671A6C: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
    // 0x80671A70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80671A74:
    // 0x80671A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80671A78: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80671A7C: jal         0x8005C27C
    // 0x80671A80: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x80671A80: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
    // 0x80671A84: addiu       $s0, $s0, -0x8
    ctx->r16 = ADD32(ctx->r16, -0X8);
    // 0x80671A88: bnel        $s1, $s0, L_80671A74
    if (ctx->r17 != ctx->r16) {
        // 0x80671A8C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80671A74;
    }
    goto skip_0;
    // 0x80671A8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_80671A90:
    // 0x80671A90: lw          $t1, 0x1F4($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X1F4);
    // 0x80671A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80671A98: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_80671A9C:
    // 0x80671A9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80671AA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80671AA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80671AA8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80671AAC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80671AB0: jr          $ra
    // 0x80671AB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80671AB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806F73DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F73DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F73E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F73E4: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806F73E8: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806F73EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F73F0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806F73F4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806F73F8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806F73FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806F7400: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806F7404: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806F7408: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806F740C: lui         $t2, 0x806F
    ctx->r10 = S32(RELOC_HI16(691, 0X8FC) << 16);
    // 0x806F7410: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806F7414: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806F7418: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806F741C: lw          $t2, 0x768C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(691, 0X8FC));
    // 0x806F7420: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806F7424: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806F7428: jal         0x806F6DD4
    // 0x806F742C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F6DD4(rdram, ctx);
        goto after_0;
    // 0x806F742C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F7430: jal         0x806F6E90
    // 0x806F7434: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806F6E90(rdram, ctx);
        goto after_1;
    // 0x806F7434: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806F7438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F743C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F7440: jr          $ra
    // 0x806F7444: nop

    return;
    // 0x806F7444: nop

    // 0x806F7448: nop

    // 0x806F744C: nop

;}
RECOMP_FUNC void func_8003D884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D884: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8003D888: lbu         $t7, 0x165($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X165);
    // 0x8003D88C: jr          $ra
    // 0x8003D890: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    return;
    // 0x8003D890: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80072150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072150: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80072154: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007215C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80072160: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80072164: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80072168: sw          $t6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r14;
    // 0x8007216C: addiu       $t7, $t7, -0x4D94
    ctx->r15 = ADD32(ctx->r15, -0X4D94);
    // 0x80072170: jal         0x8008B920
    // 0x80072174: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80072174: sw          $s0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r16;
    after_0:
    // 0x80072178: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x8007217C: sw          $v1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r3;
    // 0x80072180: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80072184: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072188: sw          $zero, -0x7AE4($at)
    MEM_W(-0X7AE4, ctx->r1) = 0;
    // 0x8007218C: addiu       $a0, $a0, -0x27B0
    ctx->r4 = ADD32(ctx->r4, -0X27B0);
    // 0x80072190: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80072194: jal         0x80082210
    // 0x80072198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80072198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8007219C: lw          $t8, 0xA0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XA0);
    // 0x800721A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800721A4: addiu       $a0, $a0, -0x5E08
    ctx->r4 = ADD32(ctx->r4, -0X5E08);
    // 0x800721A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800721AC: jal         0x80082210
    // 0x800721B0: lw          $a1, 0x20($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X20);
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800721B0: lw          $a1, 0x20($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X20);
    after_2:
    // 0x800721B4: lw          $t9, 0xA0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XA0);
    // 0x800721B8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800721BC: addiu       $a0, $a0, -0x5948
    ctx->r4 = ADD32(ctx->r4, -0X5948);
    // 0x800721C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800721C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800721C8: jal         0x80082210
    // 0x800721CC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800721CC: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    after_3:
    // 0x800721D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800721D4: addiu       $a0, $a0, -0x2770
    ctx->r4 = ADD32(ctx->r4, -0X2770);
    // 0x800721D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800721DC: jal         0x80082210
    // 0x800721E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800721E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800721E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800721E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800721EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800721F0: jr          $ra
    // 0x800721F4: nop

    return;
    // 0x800721F4: nop

;}
RECOMP_FUNC void func_8064C3FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C3FC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8064C400: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x8064C404: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8064C408: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8064C40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064C410:
    // 0x8064C410: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8064C414: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064C418: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8064C41C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8064C420: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8064C424: bc1f        L_8064C448
    if (!c1cs) {
        // 0x8064C428: swc1        $f8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
            goto L_8064C448;
    }
    // 0x8064C428: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8064C42C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064C430: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8064C434: nop

    // 0x8064C438: bc1fl       L_8064C464
    if (!c1cs) {
        // 0x8064C43C: lwc1        $f18, 0x3C($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
            goto L_8064C464;
    }
    goto skip_0;
    // 0x8064C43C: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    skip_0:
    // 0x8064C440: b           L_8064C460
    // 0x8064C444: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_8064C460;
    // 0x8064C444: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8064C448:
    // 0x8064C448: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064C44C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8064C450: nop

    // 0x8064C454: bc1fl       L_8064C464
    if (!c1cs) {
        // 0x8064C458: lwc1        $f18, 0x3C($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
            goto L_8064C464;
    }
    goto skip_1;
    // 0x8064C458: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    skip_1:
    // 0x8064C45C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8064C460:
    // 0x8064C460: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
L_8064C464:
    // 0x8064C464: lwc1        $f4, 0xC4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x8064C468: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8064C46C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8064C470: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8064C474: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8064C478: bne         $v0, $a0, L_8064C410
    if (ctx->r2 != ctx->r4) {
        // 0x8064C47C: swc1        $f6, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
            goto L_8064C410;
    }
    // 0x8064C47C: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
    // 0x8064C480: jr          $ra
    // 0x8064C484: nop

    return;
    // 0x8064C484: nop

;}
RECOMP_FUNC void func_806EB2F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EB2F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EB2F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EB2FC: jal         0x806EA9C0
    // 0x806EB300: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_806EA9C0(rdram, ctx);
        goto after_0;
    // 0x806EB300: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EB304: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806EB308: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(670, 0XF84) << 16);
    // 0x806EB30C: lwc1        $f0, -0x48AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(670, 0XF84));
    // 0x806EB310: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x806EB314: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806EB318: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806EB31C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806EB320: nop

    // 0x806EB324: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806EB328: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x806EB32C: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x806EB330: jal         0x806EA92C
    // 0x806EB334: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_806EA92C(rdram, ctx);
        goto after_1;
    // 0x806EB334: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x806EB338: beq         $v0, $zero, L_806EB354
    if (ctx->r2 == 0) {
        // 0x806EB33C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_806EB354;
    }
    // 0x806EB33C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806EB340: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806EB344: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EB348: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x806EB34C: jal         0x806EB43C
    // 0x806EB350: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
    func_806EB43C(rdram, ctx);
        goto after_2;
    // 0x806EB350: lw          $a3, 0x68($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X68);
    after_2:
L_806EB354:
    // 0x806EB354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EB358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EB35C: jr          $ra
    // 0x806EB360: nop

    return;
    // 0x806EB360: nop

;}
RECOMP_FUNC void func_804F3754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F3754: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804F3758: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804F375C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804F3760: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804F3764: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804F3768: lh          $a3, 0x184($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X184);
    // 0x804F376C: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x804F3770: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x804F3774: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x804F3778: jal         0x804F36A0
    // 0x804F377C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_804F36A0(rdram, ctx);
        goto after_0;
    // 0x804F377C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_0:
    // 0x804F3780: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x804F3784: sll         $a1, $zero, 2
    ctx->r5 = S32(0 << 2);
    // 0x804F3788: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804F378C: blez        $a3, L_804F3854
    if (SIGNED(ctx->r7) <= 0) {
        // 0x804F3790: addu        $a2, $s2, $a1
        ctx->r6 = ADD32(ctx->r18, ctx->r5);
            goto L_804F3854;
    }
    // 0x804F3790: addu        $a2, $s2, $a1
    ctx->r6 = ADD32(ctx->r18, ctx->r5);
    // 0x804F3794: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x804F3798: lui         $t5, 0x8010
    ctx->r13 = S32(0X8010 << 16);
    // 0x804F379C: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x804F37A0: addiu       $t3, $t3, -0x5508
    ctx->r11 = ADD32(ctx->r11, -0X5508);
    // 0x804F37A4: addiu       $t5, $t5, -0x54E4
    ctx->r13 = ADD32(ctx->r13, -0X54E4);
    // 0x804F37A8: addiu       $s0, $s0, -0x54E0
    ctx->r16 = ADD32(ctx->r16, -0X54E0);
    // 0x804F37AC: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
    // 0x804F37B0: addiu       $ra, $zero, 0xA
    ctx->r31 = ADD32(0, 0XA);
    // 0x804F37B4: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x804F37B8: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x804F37BC: addiu       $t1, $zero, 0x4001
    ctx->r9 = ADD32(0, 0X4001);
    // 0x804F37C0: lw          $v0, 0x188($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X188);
L_804F37C4:
    // 0x804F37C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804F37C8: beql        $v0, $zero, L_804F3844
    if (ctx->r2 == 0) {
        // 0x804F37CC: slti        $at, $a1, 0x50
        ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
            goto L_804F3844;
    }
    goto skip_0;
    // 0x804F37CC: slti        $at, $a1, 0x50
    ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
    skip_0:
    // 0x804F37D0: lw          $a0, 0x174($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X174);
    // 0x804F37D4: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x804F37D8: beql        $a0, $zero, L_804F3844
    if (ctx->r4 == 0) {
        // 0x804F37DC: slti        $at, $a1, 0x50
        ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
            goto L_804F3844;
    }
    goto skip_1;
    // 0x804F37DC: slti        $at, $a1, 0x50
    ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
    skip_1:
    // 0x804F37E0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x804F37E4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x804F37E8: beql        $v1, $zero, L_804F3844
    if (ctx->r3 == 0) {
        // 0x804F37EC: slti        $at, $a1, 0x50
        ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
            goto L_804F3844;
    }
    goto skip_2;
    // 0x804F37EC: slti        $at, $a1, 0x50
    ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
    skip_2:
    // 0x804F37F0: beql        $v1, $at, L_804F3844
    if (ctx->r3 == ctx->r1) {
        // 0x804F37F4: slti        $at, $a1, 0x50
        ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
            goto L_804F3844;
    }
    goto skip_3;
    // 0x804F37F4: slti        $at, $a1, 0x50
    ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
    skip_3:
    // 0x804F37F8: lh          $t6, 0x14($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X14);
    // 0x804F37FC: beql        $t6, $zero, L_804F3844
    if (ctx->r14 == 0) {
        // 0x804F3800: slti        $at, $a1, 0x50
        ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
            goto L_804F3844;
    }
    goto skip_4;
    // 0x804F3800: slti        $at, $a1, 0x50
    ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
    skip_4:
    // 0x804F3804: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
    // 0x804F3808: bne         $t1, $v1, L_804F381C
    if (ctx->r9 != ctx->r3) {
        // 0x804F380C: nop
    
            goto L_804F381C;
    }
    // 0x804F380C: nop

    // 0x804F3810: lw          $a0, 0x1F4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1F4);
    // 0x804F3814: sb          $t2, 0xDF($a0)
    MEM_B(0XDF, ctx->r4) = ctx->r10;
    // 0x804F3818: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
L_804F381C:
    // 0x804F381C: bnel        $t1, $v1, L_804F3834
    if (ctx->r9 != ctx->r3) {
        // 0x804F3820: lwc1        $f4, 0x4($t0)
        ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
            goto L_804F3834;
    }
    goto skip_5;
    // 0x804F3820: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    skip_5:
    // 0x804F3824: sb          $t4, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r12;
    // 0x804F3828: sb          $ra, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r31;
    // 0x804F382C: sb          $s1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r17;
    // 0x804F3830: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
L_804F3834:
    // 0x804F3834: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x804F3838: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804F383C: swc1        $f8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f8.u32l;
    // 0x804F3840: slti        $at, $a1, 0x50
    ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
L_804F3844:
    // 0x804F3844: beq         $at, $zero, L_804F3854
    if (ctx->r1 == 0) {
        // 0x804F3848: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_804F3854;
    }
    // 0x804F3848: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x804F384C: bgtzl       $a3, L_804F37C4
    if (SIGNED(ctx->r7) > 0) {
        // 0x804F3850: lw          $v0, 0x188($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X188);
            goto L_804F37C4;
    }
    goto skip_6;
    // 0x804F3850: lw          $v0, 0x188($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X188);
    skip_6:
L_804F3854:
    // 0x804F3854: lwc1        $f10, 0x50($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X50);
    // 0x804F3858: lwc1        $f16, 0x1C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x804F385C: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(270, 0XE40) << 16);
    // 0x804F3860: lwc1        $f4, 0x4170($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(270, 0XE40));
    // 0x804F3864: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804F3868: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x804F386C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804F3870: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x804F3874: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
    // 0x804F3878: lwc1        $f16, 0x50($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X50);
    // 0x804F387C: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x804F3880: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x804F3884: swc1        $f4, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f4.u32l;
    // 0x804F3888: lwc1        $f8, 0x50($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X50);
    // 0x804F388C: lwc1        $f2, 0x14($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X14);
    // 0x804F3890: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x804F3894: nop

    // 0x804F3898: bc1fl       L_804F38D4
    if (!c1cs) {
        // 0x804F389C: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_804F38D4;
    }
    goto skip_7;
    // 0x804F389C: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_7:
    // 0x804F38A0: swc1        $f2, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f2.u32l;
    // 0x804F38A4: lwc1        $f0, 0x4($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
    // 0x804F38A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804F38AC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804F38B0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804F38B4: nop

    // 0x804F38B8: bc1fl       L_804F38D4
    if (!c1cs) {
        // 0x804F38BC: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_804F38D4;
    }
    goto skip_8;
    // 0x804F38BC: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_8:
    // 0x804F38C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804F38C4: nop

    // 0x804F38C8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804F38CC: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x804F38D0: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
L_804F38D4:
    // 0x804F38D4: lwc1        $f18, 0x50($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X50);
    // 0x804F38D8: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x804F38DC: nop

    // 0x804F38E0: bc1f        L_804F3918
    if (!c1cs) {
        // 0x804F38E4: nop
    
            goto L_804F3918;
    }
    // 0x804F38E4: nop

    // 0x804F38E8: swc1        $f2, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f2.u32l;
    // 0x804F38EC: lwc1        $f0, 0x4($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
    // 0x804F38F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804F38F4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804F38F8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804F38FC: nop

    // 0x804F3900: bc1f        L_804F3918
    if (!c1cs) {
        // 0x804F3904: nop
    
            goto L_804F3918;
    }
    // 0x804F3904: nop

    // 0x804F3908: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804F390C: nop

    // 0x804F3910: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804F3914: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
L_804F3918:
    // 0x804F3918: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(270, 0XE44) << 16);
    // 0x804F391C: lwc1        $f16, 0x4174($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(270, 0XE44));
    // 0x804F3920: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x804F3924: addiu       $at, $zero, 0x4050
    ctx->r1 = ADD32(0, 0X4050);
    // 0x804F3928: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804F392C: swc1        $f18, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f18.u32l;
    // 0x804F3930: lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XC);
    // 0x804F3934: beq         $v0, $at, L_804F394C
    if (ctx->r2 == ctx->r1) {
        // 0x804F3938: addiu       $at, $zero, 0x4051
        ctx->r1 = ADD32(0, 0X4051);
            goto L_804F394C;
    }
    // 0x804F3938: addiu       $at, $zero, 0x4051
    ctx->r1 = ADD32(0, 0X4051);
    // 0x804F393C: beql        $v0, $at, L_804F39A0
    if (ctx->r2 == ctx->r1) {
        // 0x804F3940: lwc1        $f12, 0x50($s2)
        ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
            goto L_804F39A0;
    }
    goto skip_9;
    // 0x804F3940: lwc1        $f12, 0x50($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
    skip_9:
    // 0x804F3944: b           L_804F39EC
    // 0x804F3948: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
        goto L_804F39EC;
    // 0x804F3948: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
L_804F394C:
    // 0x804F394C: lwc1        $f12, 0x50($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
    // 0x804F3950: jal         0x80066E88
    // 0x804F3954: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x804F3954: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x804F3958: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x804F395C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804F3960: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804F3964: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804F3968: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x804F396C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804F3970: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x804F3974: jal         0x80066DE4
    // 0x804F3978: lwc1        $f12, 0x50($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x804F3978: lwc1        $f12, 0x50($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
    after_2:
    // 0x804F397C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804F3980: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804F3984: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804F3988: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x804F398C: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x804F3990: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x804F3994: b           L_804F39E8
    // 0x804F3998: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
        goto L_804F39E8;
    // 0x804F3998: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x804F399C: lwc1        $f12, 0x50($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
L_804F39A0:
    // 0x804F39A0: jal         0x80066E88
    // 0x804F39A4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x804F39A4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_3:
    // 0x804F39A8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x804F39AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804F39B0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804F39B4: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x804F39B8: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x804F39BC: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x804F39C0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x804F39C4: jal         0x80066DE4
    // 0x804F39C8: lwc1        $f12, 0x50($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x804F39C8: lwc1        $f12, 0x50($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X50);
    after_4:
    // 0x804F39CC: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x804F39D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804F39D4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x804F39D8: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804F39DC: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x804F39E0: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804F39E4: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
L_804F39E8:
    // 0x804F39E8: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
L_804F39EC:
    // 0x804F39EC: swc1        $f18, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f18.u32l;
    // 0x804F39F0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x804F39F4: swc1        $f16, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f16.u32l;
    // 0x804F39F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804F39FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x804F3A00: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804F3A04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804F3A08: jr          $ra
    // 0x804F3A0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x804F3A0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_806E73D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E73D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E73D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E73D8: jal         0x806E7328
    // 0x806E73DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806E7328(rdram, ctx);
        goto after_0;
    // 0x806E73DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806E73E0: jal         0x80045BD8
    // 0x806E73E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x806E73E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806E73E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E73EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E73F0: jr          $ra
    // 0x806E73F4: nop

    return;
    // 0x806E73F4: nop

;}
RECOMP_FUNC void func_8079BFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079BFF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079BFF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079BFFC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8079C000: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8079C004: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(829, 0XAF4) << 16);
    // 0x8079C008: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8079C00C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8079C010: addiu       $t7, $t7, -0x3D9C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(829, 0XAF4));
    // 0x8079C014: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8079C018: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8079C01C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8079C020: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8079C024: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x8079C028: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8079C02C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8079C030: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x8079C034: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x8079C038: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(829, 0X814) << 16);
    // 0x8079C03C: addiu       $t1, $t1, -0x407C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(829, 0X814));
    // 0x8079C040: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8079C044: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8079C048: sw          $t1, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r9;
    // 0x8079C04C: jal         0x80048378
    // 0x8079C050: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x8079C050: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079C054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079C058: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8079C05C: nop

    // 0x8079C060: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8079C064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079C068: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079C06C: jr          $ra
    // 0x8079C070: nop

    return;
    // 0x8079C070: nop

;}
RECOMP_FUNC void func_80450F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450F20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80450F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80450F28: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450F2C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450F30: addiu       $t7, $zero, -0x64
    ctx->r15 = ADD32(0, -0X64);
    // 0x80450F34: addu        $v0, $a3, $at
    ctx->r2 = ADD32(ctx->r7, ctx->r1);
    // 0x80450F38: lw          $v1, 0x6A28($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6A28);
    // 0x80450F3C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80450F40: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80450F44: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80450F48: sw          $t6, 0x6A20($v0)
    MEM_W(0X6A20, ctx->r2) = ctx->r14;
    // 0x80450F4C: sw          $t7, 0x6A28($v0)
    MEM_W(0X6A28, ctx->r2) = ctx->r15;
    // 0x80450F50: sw          $t8, 0x6A2C($v0)
    MEM_W(0X6A2C, ctx->r2) = ctx->r24;
    // 0x80450F54: sw          $t9, 0x6A30($v0)
    MEM_W(0X6A30, ctx->r2) = ctx->r25;
    // 0x80450F58: sw          $v1, 0x6A24($v0)
    MEM_W(0X6A24, ctx->r2) = ctx->r3;
    // 0x80450F5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80450F60: jal         0x8044EFA0
    // 0x80450F64: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80450F64: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80450F68: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80450F6C: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80450F70: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80450F74: addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // 0x80450F78: lw          $a0, 0x6A24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A24);
    // 0x80450F7C: jal         0x80446CD0
    // 0x80450F80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80446CD0(rdram, ctx);
        goto after_1;
    // 0x80450F80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80450F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80450F88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80450F8C: jr          $ra
    // 0x80450F90: nop

    return;
    // 0x80450F90: nop

;}
RECOMP_FUNC void func_8002A148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A148: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002A14C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002A150: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002A154: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8002A158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002A15C: jal         0x80081C64
    // 0x8002A160: lwc1        $f12, 0x38($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X38);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8002A160: lwc1        $f12, 0x38($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X38);
    after_0:
    // 0x8002A164: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8002A168: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8002A16C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8002A170: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002A174: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002A178: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8002A17C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A180: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002A184: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002A188: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8002A18C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8002A190: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8002A194: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8002A198: div.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8002A19C: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8002A1A0: jal         0x8002A0D0
    // 0x8002A1A4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    func_8002A0D0(rdram, ctx);
        goto after_1;
    // 0x8002A1A4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8002A1A8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8002A1AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002A1B0: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002A1B4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8002A1B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002A1BC: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002A1C0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002A1C4: mul.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002A1C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002A1CC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8002A1D0: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x8002A1D4: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8002A1D8: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8002A1DC: lwc1        $f6, 0xAC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8002A1E0: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8002A1E4: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x8002A1E8: sub.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8002A1EC: add.s       $f20, $f6, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8002A1F0: jal         0x80081FE0
    // 0x8002A1F4: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    floorf_recomp(rdram, ctx);
        goto after_2;
    // 0x8002A1F4: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_2:
    // 0x8002A1F8: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8002A1FC: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8002A200: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002A204: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002A208: add.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8002A20C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8002A210: jal         0x80081FE0
    // 0x8002A214: sub.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f18.fl;
    floorf_recomp(rdram, ctx);
        goto after_3;
    // 0x8002A214: sub.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f18.fl;
    after_3:
    // 0x8002A218: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8002A21C: lwc1        $f8, 0xAC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8002A220: trunc.w.s   $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8002A224: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8002A228: nop

    // 0x8002A22C: bgez        $a0, L_8002A238
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002A230: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_8002A238;
    }
    // 0x8002A230: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x8002A234: addiu       $at, $a0, 0xF
    ctx->r1 = ADD32(ctx->r4, 0XF);
L_8002A238:
    // 0x8002A238: sra         $a0, $at, 4
    ctx->r4 = S32(SIGNED(ctx->r1) >> 4);
    // 0x8002A23C: jal         0x8006593C
    // 0x8002A240: nop

    func_8006593C(rdram, ctx);
        goto after_4;
    // 0x8002A240: nop

    after_4:
    // 0x8002A244: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8002A248: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8002A24C: jal         0x80053924
    // 0x8002A250: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    func_80053924(rdram, ctx);
        goto after_5;
    // 0x8002A250: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    after_5:
    // 0x8002A254: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8002A258: bne         $v0, $at, L_8002A2CC
    if (ctx->r2 != ctx->r1) {
        // 0x8002A25C: lwc1        $f14, 0x64($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8002A2CC;
    }
    // 0x8002A25C: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8002A260: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002A264: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002A268: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002A26C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8002A270: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8002A274: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8002A278: add.s       $f12, $f20, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x8002A27C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8002A280: jal         0x8002A034
    // 0x8002A284: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8002A034(rdram, ctx);
        goto after_6;
    // 0x8002A284: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8002A288: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8002A28C: jal         0x80082050
    // 0x8002A290: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    truncf_recomp(rdram, ctx);
        goto after_7;
    // 0x8002A290: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x8002A294: trunc.w.s   $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    ctx->f10.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8002A298: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8002A29C: sub.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8002A2A0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8002A2A4: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8002A2A8: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x8002A2AC: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8002A2B0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8002A2B4: nop

    // 0x8002A2B8: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A2BC: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8002A2C0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8002A2C4: b           L_8002A2D8
    // 0x8002A2C8: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
        goto L_8002A2D8;
    // 0x8002A2C8: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
L_8002A2CC:
    // 0x8002A2CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002A2D0: nop

    // 0x8002A2D4: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
L_8002A2D8:
    // 0x8002A2D8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8002A2DC: jal         0x80053924
    // 0x8002A2E0: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    func_80053924(rdram, ctx);
        goto after_8;
    // 0x8002A2E0: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    after_8:
    // 0x8002A2E4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8002A2E8: bnel        $v0, $at, L_8002A368
    if (ctx->r2 != ctx->r1) {
        // 0x8002A2EC: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8002A368;
    }
    goto skip_0;
    // 0x8002A2EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x8002A2F0: trunc.w.s   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8002A2F4: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8002A2F8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002A2FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002A300: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8002A304: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002A308: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8002A30C: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x8002A310: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8002A314: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8002A318: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8002A31C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8002A320: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002A324: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002A328: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8002A32C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002A330: add.s       $f12, $f20, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x8002A334: jal         0x8002A034
    // 0x8002A338: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    func_8002A034(rdram, ctx);
        goto after_9;
    // 0x8002A338: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8002A33C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8002A340: jal         0x80082050
    // 0x8002A344: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    truncf_recomp(rdram, ctx);
        goto after_10;
    // 0x8002A344: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_10:
    // 0x8002A348: sub.s       $f18, $f20, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8002A34C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002A350: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002A354: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8002A358: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002A35C: b           L_8002A370
    // 0x8002A360: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
        goto L_8002A370;
    // 0x8002A360: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8002A364: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8002A368:
    // 0x8002A368: nop

    // 0x8002A36C: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_8002A370:
    // 0x8002A370: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A374: lwc1        $f0, -0x1B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1B8);
    // 0x8002A378: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8002A37C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A380: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002A384: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002A388: nop

    // 0x8002A38C: bc1tl       L_8002A3D4
    if (c1cs) {
        // 0x8002A390: sw          $t0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r8;
            goto L_8002A3D4;
    }
    goto skip_1;
    // 0x8002A390: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    skip_1:
    // 0x8002A394: lwc1        $f18, -0x1B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1B4);
    // 0x8002A398: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002A39C: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8002A3A0: nop

    // 0x8002A3A4: bc1tl       L_8002A3D4
    if (c1cs) {
        // 0x8002A3A8: sw          $t0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r8;
            goto L_8002A3D4;
    }
    goto skip_2;
    // 0x8002A3A8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    skip_2:
    // 0x8002A3AC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8002A3B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A3B4: bc1tl       L_8002A3D4
    if (c1cs) {
        // 0x8002A3B8: sw          $t0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r8;
            goto L_8002A3D4;
    }
    goto skip_3;
    // 0x8002A3B8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    skip_3:
    // 0x8002A3BC: lwc1        $f8, -0x1B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1B0);
    // 0x8002A3C0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8002A3C4: nop

    // 0x8002A3C8: bc1fl       L_8002A3D8
    if (!c1cs) {
        // 0x8002A3CC: lwc1        $f4, 0x30($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
            goto L_8002A3D8;
    }
    goto skip_4;
    // 0x8002A3CC: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x8002A3D0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_8002A3D4:
    // 0x8002A3D4: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
L_8002A3D8:
    // 0x8002A3D8: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8002A3DC: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002A3E0: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8002A3E4: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002A3E8: lwc1        $f4, 0xAC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8002A3EC: sub.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8002A3F0: add.s       $f20, $f4, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A3F4: jal         0x80053924
    // 0x8002A3F8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80053924(rdram, ctx);
        goto after_11;
    // 0x8002A3F8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_11:
    // 0x8002A3FC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8002A400: bne         $v0, $at, L_8002A474
    if (ctx->r2 != ctx->r1) {
        // 0x8002A404: lwc1        $f14, 0x64($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8002A474;
    }
    // 0x8002A404: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8002A408: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002A40C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002A410: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002A414: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8002A418: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8002A41C: lui         $a2, 0xC180
    ctx->r6 = S32(0XC180 << 16);
    // 0x8002A420: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002A424: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8002A428: jal         0x8002A034
    // 0x8002A42C: sub.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f6.fl;
    func_8002A034(rdram, ctx);
        goto after_12;
    // 0x8002A42C: sub.s       $f12, $f20, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f6.fl;
    after_12:
    // 0x8002A430: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8002A434: jal         0x80082050
    // 0x8002A438: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    truncf_recomp(rdram, ctx);
        goto after_13;
    // 0x8002A438: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x8002A43C: trunc.w.s   $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    ctx->f18.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8002A440: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A444: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002A448: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8002A44C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8002A450: sub.s       $f18, $f20, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8002A454: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x8002A458: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8002A45C: nop

    // 0x8002A460: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002A464: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A468: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8002A46C: b           L_8002A47C
    // 0x8002A470: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
        goto L_8002A47C;
    // 0x8002A470: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_8002A474:
    // 0x8002A474: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002A478: nop

L_8002A47C:
    // 0x8002A47C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8002A480: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002A484: jal         0x80053924
    // 0x8002A488: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    func_80053924(rdram, ctx);
        goto after_14;
    // 0x8002A488: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    after_14:
    // 0x8002A48C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8002A490: bne         $v0, $at, L_8002A514
    if (ctx->r2 != ctx->r1) {
        // 0x8002A494: lwc1        $f16, 0x48($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
            goto L_8002A514;
    }
    // 0x8002A494: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8002A498: trunc.w.s   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8002A49C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002A4A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002A4A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A4A8: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8002A4AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002A4B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002A4B4: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x8002A4B8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002A4BC: sub.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x8002A4C0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8002A4C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8002A4C8: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002A4CC: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8002A4D0: lui         $a2, 0xC180
    ctx->r6 = S32(0XC180 << 16);
    // 0x8002A4D4: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x8002A4D8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002A4DC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8002A4E0: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8002A4E4: jal         0x8002A034
    // 0x8002A4E8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    func_8002A034(rdram, ctx);
        goto after_15;
    // 0x8002A4E8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x8002A4EC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8002A4F0: jal         0x80082050
    // 0x8002A4F4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    truncf_recomp(rdram, ctx);
        goto after_16;
    // 0x8002A4F4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x8002A4F8: sub.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8002A4FC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002A500: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002A504: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8002A508: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002A50C: b           L_8002A51C
    // 0x8002A510: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
        goto L_8002A51C;
    // 0x8002A510: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_8002A514:
    // 0x8002A514: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002A518: nop

L_8002A51C:
    // 0x8002A51C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A520: lwc1        $f0, -0x1AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1AC);
    // 0x8002A524: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002A528: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8002A52C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8002A530: nop

    // 0x8002A534: bc1tl       L_8002A578
    if (c1cs) {
        // 0x8002A538: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8002A578;
    }
    goto skip_5;
    // 0x8002A538: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
    // 0x8002A53C: lwc1        $f12, -0x1A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1A8);
    // 0x8002A540: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x8002A544: nop

    // 0x8002A548: bc1tl       L_8002A578
    if (c1cs) {
        // 0x8002A54C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8002A578;
    }
    goto skip_6;
    // 0x8002A54C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_6:
    // 0x8002A550: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8002A554: nop

    // 0x8002A558: bc1tl       L_8002A578
    if (c1cs) {
        // 0x8002A55C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8002A578;
    }
    goto skip_7;
    // 0x8002A55C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_7:
    // 0x8002A560: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8002A564: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8002A568: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002A56C: bc1f        L_8002A5C4
    if (!c1cs) {
        // 0x8002A570: nop
    
            goto L_8002A5C4;
    }
    // 0x8002A570: nop

    // 0x8002A574: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8002A578:
    // 0x8002A578: beql        $t8, $at, L_8002A61C
    if (ctx->r24 == ctx->r1) {
        // 0x8002A57C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002A61C;
    }
    goto skip_8;
    // 0x8002A57C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_8:
    // 0x8002A580: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002A584: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A588: bc1fl       L_8002A5A4
    if (!c1cs) {
        // 0x8002A58C: lwc1        $f8, 0xAC($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XAC);
            goto L_8002A5A4;
    }
    goto skip_9;
    // 0x8002A58C: lwc1        $f8, 0xAC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XAC);
    skip_9:
    // 0x8002A590: lwc1        $f10, 0xAC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8002A594: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8002A598: b           L_8002A5AC
    // 0x8002A59C: swc1        $f4, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f4.u32l;
        goto L_8002A5AC;
    // 0x8002A59C: swc1        $f4, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f4.u32l;
    // 0x8002A5A0: lwc1        $f8, 0xAC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XAC);
L_8002A5A4:
    // 0x8002A5A4: sub.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8002A5A8: swc1        $f6, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f6.u32l;
L_8002A5AC:
    // 0x8002A5AC: lwc1        $f18, 0xAC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8002A5B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002A5B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A5B8: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8002A5BC: b           L_8002A61C
    // 0x8002A5C0: swc1        $f4, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f4.u32l;
        goto L_8002A61C;
    // 0x8002A5C0: swc1        $f4, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f4.u32l;
L_8002A5C4:
    // 0x8002A5C4: bne         $t0, $at, L_8002A618
    if (ctx->r8 != ctx->r1) {
        // 0x8002A5C8: lwc1        $f0, 0x4C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_8002A618;
    }
    // 0x8002A5C8: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002A5CC: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8002A5D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A5D4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8002A5D8: nop

    // 0x8002A5DC: bc1fl       L_8002A5F8
    if (!c1cs) {
        // 0x8002A5E0: lwc1        $f10, 0xAC($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0XAC);
            goto L_8002A5F8;
    }
    goto skip_10;
    // 0x8002A5E0: lwc1        $f10, 0xAC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XAC);
    skip_10:
    // 0x8002A5E4: lwc1        $f6, 0xAC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8002A5E8: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002A5EC: b           L_8002A600
    // 0x8002A5F0: swc1        $f18, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f18.u32l;
        goto L_8002A600;
    // 0x8002A5F0: swc1        $f18, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f18.u32l;
    // 0x8002A5F4: lwc1        $f10, 0xAC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XAC);
L_8002A5F8:
    // 0x8002A5F8: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8002A5FC: swc1        $f4, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f4.u32l;
L_8002A600:
    // 0x8002A600: lwc1        $f6, 0xAC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8002A604: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002A608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002A60C: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8002A610: b           L_8002A61C
    // 0x8002A614: swc1        $f18, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f18.u32l;
        goto L_8002A61C;
    // 0x8002A614: swc1        $f18, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f18.u32l;
L_8002A618:
    // 0x8002A618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A61C:
    // 0x8002A61C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002A620: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8002A624: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002A628: jr          $ra
    // 0x8002A62C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8002A62C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_804348BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804348BC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x804348C0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x804348C4: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x804348C8: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x804348CC: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x804348D0: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x804348D4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x804348D8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x804348DC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x804348E0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x804348E4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x804348E8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804348EC: addiu       $s2, $zero, 0x168
    ctx->r18 = ADD32(0, 0X168);
    // 0x804348F0: lw          $s1, 0xB6C($v1)
    ctx->r17 = MEM_W(ctx->r3, 0XB6C);
    // 0x804348F4: sll         $t6, $s1, 3
    ctx->r14 = S32(ctx->r17 << 3);
    // 0x804348F8: addu        $s0, $v1, $t6
    ctx->r16 = ADD32(ctx->r3, ctx->r14);
    // 0x804348FC: slti        $at, $s1, 0x5A
    ctx->r1 = SIGNED(ctx->r17) < 0X5A ? 1 : 0;
    // 0x80434900: beq         $at, $zero, L_804349F8
    if (ctx->r1 == 0) {
        // 0x80434904: addiu       $s0, $s0, 0x89C
        ctx->r16 = ADD32(ctx->r16, 0X89C);
            goto L_804349F8;
    }
    // 0x80434904: addiu       $s0, $s0, 0x89C
    ctx->r16 = ADD32(ctx->r16, 0X89C);
    // 0x80434908: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2ACC) << 16);
    // 0x8043490C: lwc1        $f30, 0x657C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2ACC));
    // 0x80434910: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2AD0) << 16);
    // 0x80434914: lwc1        $f26, 0x6580($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2AD0));
    // 0x80434918: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2AD4) << 16);
    // 0x8043491C: lwc1        $f24, 0x6584($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2AD4));
L_80434920:
    // 0x80434920: jal         0x800653D8
    // 0x80434924: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80434924: nop

    after_0:
    // 0x80434928: div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // 0x8043492C: mfhi        $t7
    ctx->r15 = hi;
    // 0x80434930: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80434934: lwc1        $f20, 0x0($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80434938: lwc1        $f22, 0x4($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8043493C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80434940: bne         $s2, $zero, L_8043494C
    if (ctx->r18 != 0) {
        // 0x80434944: nop
    
            goto L_8043494C;
    }
    // 0x80434944: nop

    // 0x80434948: break       7
    do_break(2151893320);
L_8043494C:
    // 0x8043494C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80434950: bne         $s2, $at, L_80434964
    if (ctx->r18 != ctx->r1) {
        // 0x80434954: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80434964;
    }
    // 0x80434954: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80434958: bne         $v0, $at, L_80434964
    if (ctx->r2 != ctx->r1) {
        // 0x8043495C: nop
    
            goto L_80434964;
    }
    // 0x8043495C: nop

    // 0x80434960: break       6
    do_break(2151893344);
L_80434964:
    // 0x80434964: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    // 0x80434968: jal         0x80066E88
    // 0x8043496C: addiu       $s0, $s0, 0x0
    ctx->r16 = ADD32(ctx->r16, 0X0);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8043496C: addiu       $s0, $s0, 0x0
    ctx->r16 = ADD32(ctx->r16, 0X0);
    after_1:
    // 0x80434970: mul.s       $f6, $f30, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80434974: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x80434978: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x8043497C: nop

    // 0x80434980: bc1fl       L_80434994
    if (!c1cs) {
        // 0x80434984: c.lt.s      $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
            goto L_80434994;
    }
    goto skip_0;
    // 0x80434984: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    skip_0:
    // 0x80434988: b           L_804349A4
    // 0x8043498C: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
        goto L_804349A4;
    // 0x8043498C: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x80434990: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
L_80434994:
    // 0x80434994: nop

    // 0x80434998: bc1f        L_804349A4
    if (!c1cs) {
        // 0x8043499C: nop
    
            goto L_804349A4;
    }
    // 0x8043499C: nop

    // 0x804349A0: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
L_804349A4:
    // 0x804349A4: jal         0x80066DE4
    // 0x804349A8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x804349A8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_2:
    // 0x804349AC: mul.s       $f8, $f30, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x804349B0: addiu       $s1, $s1, 0x32
    ctx->r17 = ADD32(ctx->r17, 0X32);
    // 0x804349B4: slti        $at, $s1, 0x5A
    ctx->r1 = SIGNED(ctx->r17) < 0X5A ? 1 : 0;
    // 0x804349B8: add.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x804349BC: c.lt.s      $f24, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f24.fl < ctx->f22.fl;
    // 0x804349C0: nop

    // 0x804349C4: bc1fl       L_804349D8
    if (!c1cs) {
        // 0x804349C8: c.lt.s      $f22, $f26
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
            goto L_804349D8;
    }
    goto skip_1;
    // 0x804349C8: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    skip_1:
    // 0x804349CC: b           L_804349E8
    // 0x804349D0: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
        goto L_804349E8;
    // 0x804349D0: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x804349D4: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
L_804349D8:
    // 0x804349D8: nop

    // 0x804349DC: bc1fl       L_804349EC
    if (!c1cs) {
        // 0x804349E0: swc1        $f20, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
            goto L_804349EC;
    }
    goto skip_2;
    // 0x804349E0: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    skip_2:
    // 0x804349E4: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
L_804349E8:
    // 0x804349E8: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
L_804349EC:
    // 0x804349EC: swc1        $f22, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f22.u32l;
    // 0x804349F0: bne         $at, $zero, L_80434920
    if (ctx->r1 != 0) {
        // 0x804349F4: addiu       $s0, $s0, 0x190
        ctx->r16 = ADD32(ctx->r16, 0X190);
            goto L_80434920;
    }
    // 0x804349F4: addiu       $s0, $s0, 0x190
    ctx->r16 = ADD32(ctx->r16, 0X190);
L_804349F8:
    // 0x804349F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x804349FC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80434A00: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80434A04: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80434A08: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80434A0C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80434A10: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80434A14: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80434A18: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80434A1C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80434A20: jr          $ra
    // 0x80434A24: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80434A24: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800495D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800495D4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800495D8: lbu         $t6, 0x5B0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5B0);
    // 0x800495DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800495E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800495E4: bnel        $t6, $zero, L_80049618
    if (ctx->r14 != 0) {
        // 0x800495E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049618;
    }
    goto skip_0;
    // 0x800495E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800495EC: jal         0x80049318
    // 0x800495F0: nop

    func_80049318(rdram, ctx);
        goto after_0;
    // 0x800495F0: nop

    after_0:
    // 0x800495F4: beql        $v0, $zero, L_80049618
    if (ctx->r2 == 0) {
        // 0x800495F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049618;
    }
    goto skip_1;
    // 0x800495F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800495FC: jal         0x800492C0
    // 0x80049600: addiu       $a0, $zero, -0x79
    ctx->r4 = ADD32(0, -0X79);
    func_800492C0(rdram, ctx);
        goto after_1;
    // 0x80049600: addiu       $a0, $zero, -0x79
    ctx->r4 = ADD32(0, -0X79);
    after_1:
    // 0x80049604: beq         $v0, $zero, L_80049614
    if (ctx->r2 == 0) {
        // 0x80049608: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80049614;
    }
    // 0x80049608: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004960C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80049610: sb          $t7, 0x5B0($at)
    MEM_B(0X5B0, ctx->r1) = ctx->r15;
L_80049614:
    // 0x80049614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80049618:
    // 0x80049618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004961C: jr          $ra
    // 0x80049620: nop

    return;
    // 0x80049620: nop

;}
RECOMP_FUNC void func_80408F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80408F40: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80408F44: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80408F48: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80408F4C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80408F50: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80408F54: beql        $t6, $zero, L_804090B0
    if (ctx->r14 == 0) {
        // 0x80408F58: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_804090B0;
    }
    goto skip_0;
    // 0x80408F58: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_0:
    // 0x80408F5C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80408F60: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80408F64: lw          $a3, 0x24($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X24);
    // 0x80408F68: addiu       $v0, $a1, 0xA00
    ctx->r2 = ADD32(ctx->r5, 0XA00);
    // 0x80408F6C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80408F70: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80408F74: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x80408F78: sll         $t2, $a3, 1
    ctx->r10 = S32(ctx->r7 << 1);
    // 0x80408F7C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80408F80: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80408F84: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80408F88: subu        $a2, $t8, $t9
    ctx->r6 = SUB32(ctx->r24, ctx->r25);
    // 0x80408F8C: subu        $t0, $a2, $t4
    ctx->r8 = SUB32(ctx->r6, ctx->r12);
    // 0x80408F90: bgez        $t0, L_80408FA0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80408F94: sra         $t5, $t0, 3
        ctx->r13 = S32(SIGNED(ctx->r8) >> 3);
            goto L_80408FA0;
    }
    // 0x80408F94: sra         $t5, $t0, 3
    ctx->r13 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80408F98: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x80408F9C: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_80408FA0:
    // 0x80408FA0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80408FA4: blez        $t2, L_80409040
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80408FA8: addu        $v1, $v0, $t6
        ctx->r3 = ADD32(ctx->r2, ctx->r14);
            goto L_80409040;
    }
    // 0x80408FA8: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80408FAC: bgez        $t0, L_80408FC0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80408FB0: andi        $t7, $t0, 0x7
        ctx->r15 = ctx->r8 & 0X7;
            goto L_80408FC0;
    }
    // 0x80408FB0: andi        $t7, $t0, 0x7
    ctx->r15 = ctx->r8 & 0X7;
    // 0x80408FB4: beq         $t7, $zero, L_80408FC0
    if (ctx->r15 == 0) {
        // 0x80408FB8: nop
    
            goto L_80408FC0;
    }
    // 0x80408FB8: nop

    // 0x80408FBC: addiu       $t7, $t7, -0x8
    ctx->r15 = ADD32(ctx->r15, -0X8);
L_80408FC0:
    // 0x80408FC0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80408FC4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80408FC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80408FCC: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
L_80408FD0:
    // 0x80408FD0: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80408FD4: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80408FD8: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80408FDC: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80408FE0: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80408FE4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80408FE8: addiu       $t8, $a1, 0xB40
    ctx->r24 = ADD32(ctx->r5, 0XB40);
    // 0x80408FEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80408FF0: div.s       $f0, $f4, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80408FF4: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80408FF8: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80408FFC: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80409000: bne         $at, $zero, L_80409034
    if (ctx->r1 != 0) {
        // 0x80409004: sltu        $at, $v1, $t8
        ctx->r1 = ctx->r3 < ctx->r24 ? 1 : 0;
            goto L_80409034;
    }
    // 0x80409004: sltu        $at, $v1, $t8
    ctx->r1 = ctx->r3 < ctx->r24 ? 1 : 0;
    // 0x80409008: beql        $at, $zero, L_80409038
    if (ctx->r1 == 0) {
        // 0x8040900C: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80409038;
    }
    goto skip_1;
    // 0x8040900C: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_1:
    // 0x80409010: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80409014: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80409018: nop

    // 0x8040901C: bc1fl       L_80409038
    if (!c1cs) {
        // 0x80409020: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80409038;
    }
    goto skip_2;
    // 0x80409020: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    skip_2:
    // 0x80409024: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x80409028: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x8040902C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80409030: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
L_80409034:
    // 0x80409034: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
L_80409038:
    // 0x80409038: bne         $at, $zero, L_80408FD0
    if (ctx->r1 != 0) {
        // 0x8040903C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80408FD0;
    }
    // 0x8040903C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80409040:
    // 0x80409040: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80409044: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80409048: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8040904C: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80409050: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80409054: div.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80409058: bgez        $t0, L_8040906C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8040905C: andi        $t9, $t0, 0x7
        ctx->r25 = ctx->r8 & 0X7;
            goto L_8040906C;
    }
    // 0x8040905C: andi        $t9, $t0, 0x7
    ctx->r25 = ctx->r8 & 0X7;
    // 0x80409060: beq         $t9, $zero, L_8040906C
    if (ctx->r25 == 0) {
        // 0x80409064: nop
    
            goto L_8040906C;
    }
    // 0x80409064: nop

    // 0x80409068: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
L_8040906C:
    // 0x8040906C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80409070: addiu       $t3, $a1, 0xB40
    ctx->r11 = ADD32(ctx->r5, 0XB40);
    // 0x80409074: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80409078: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8040907C: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80409080: mul.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80409084: bne         $at, $zero, L_804090AC
    if (ctx->r1 != 0) {
        // 0x80409088: sltu        $at, $v1, $t3
        ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
            goto L_804090AC;
    }
    // 0x80409088: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x8040908C: beql        $at, $zero, L_804090B0
    if (ctx->r1 == 0) {
        // 0x80409090: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_804090B0;
    }
    goto skip_3;
    // 0x80409090: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_3:
    // 0x80409094: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80409098: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8040909C: nop

    // 0x804090A0: bc1fl       L_804090B0
    if (!c1cs) {
        // 0x804090A4: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_804090B0;
    }
    goto skip_4;
    // 0x804090A4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_4:
    // 0x804090A8: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_804090AC:
    // 0x804090AC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_804090B0:
    // 0x804090B0: jr          $ra
    // 0x804090B4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x804090B4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800564D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800564D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800564D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800564D8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800564DC: lw          $a0, 0x180($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X180);
    // 0x800564E0: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x800564E4: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x800564E8: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x800564EC: addiu       $t7, $t7, 0x6450
    ctx->r15 = ADD32(ctx->r15, 0X6450);
    // 0x800564F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800564F4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800564F8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x800564FC: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
    // 0x80056500: jal         0x8005FE48
    // 0x80056504: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x80056504: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    after_0:
    // 0x80056508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005650C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80056510: jr          $ra
    // 0x80056514: nop

    return;
    // 0x80056514: nop

;}
RECOMP_FUNC void func_8045F164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045F168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045F16C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8045F170: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8045F174: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8045F178: beql        $a1, $at, L_8045F1B0
    if (ctx->r5 == ctx->r1) {
        // 0x8045F17C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045F1B0;
    }
    goto skip_0;
    // 0x8045F17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8045F180: jal         0x80067930
    // 0x8045F184: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x8045F184: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_0:
    // 0x8045F188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8045F18C: bne         $v0, $at, L_8045F1A0
    if (ctx->r2 != ctx->r1) {
        // 0x8045F190: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_8045F1A0;
    }
    // 0x8045F190: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8045F194: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x8045F198: jal         0x80067878
    // 0x8045F19C: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x8045F19C: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    after_1:
L_8045F1A0:
    // 0x8045F1A0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8045F1A4: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8045F1A8: sh          $t8, 0x1F0($t9)
    MEM_H(0X1F0, ctx->r25) = ctx->r24;
    // 0x8045F1AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045F1B0:
    // 0x8045F1B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045F1B4: jr          $ra
    // 0x8045F1B8: nop

    return;
    // 0x8045F1B8: nop

;}
RECOMP_FUNC void func_80077880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077880: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80077884: jr          $ra
    // 0x80077888: nop

    return;
    // 0x80077888: nop

;}
RECOMP_FUNC void func_804079E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804079E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804079E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804079E8: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x804079EC: addiu       $at, $zero, 0x4103
    ctx->r1 = ADD32(0, 0X4103);
    // 0x804079F0: beq         $v0, $at, L_80407A18
    if (ctx->r2 == ctx->r1) {
        // 0x804079F4: addiu       $at, $zero, 0x4104
        ctx->r1 = ADD32(0, 0X4104);
            goto L_80407A18;
    }
    // 0x804079F4: addiu       $at, $zero, 0x4104
    ctx->r1 = ADD32(0, 0X4104);
    // 0x804079F8: beq         $v0, $at, L_80407A28
    if (ctx->r2 == ctx->r1) {
        // 0x804079FC: addiu       $at, $zero, 0x4105
        ctx->r1 = ADD32(0, 0X4105);
            goto L_80407A28;
    }
    // 0x804079FC: addiu       $at, $zero, 0x4105
    ctx->r1 = ADD32(0, 0X4105);
    // 0x80407A00: beq         $v0, $at, L_80407A38
    if (ctx->r2 == ctx->r1) {
        // 0x80407A04: addiu       $at, $zero, 0x4106
        ctx->r1 = ADD32(0, 0X4106);
            goto L_80407A38;
    }
    // 0x80407A04: addiu       $at, $zero, 0x4106
    ctx->r1 = ADD32(0, 0X4106);
    // 0x80407A08: beq         $v0, $at, L_80407A48
    if (ctx->r2 == ctx->r1) {
        // 0x80407A0C: nop
    
            goto L_80407A48;
    }
    // 0x80407A0C: nop

    // 0x80407A10: b           L_80407A54
    // 0x80407A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80407A54;
    // 0x80407A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80407A18:
    // 0x80407A18: jal         0x80407A60
    // 0x80407A1C: nop

    func_80407A60(rdram, ctx);
        goto after_0;
    // 0x80407A1C: nop

    after_0:
    // 0x80407A20: b           L_80407A54
    // 0x80407A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80407A54;
    // 0x80407A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80407A28:
    // 0x80407A28: jal         0x80407B24
    // 0x80407A2C: nop

    func_80407B24(rdram, ctx);
        goto after_1;
    // 0x80407A2C: nop

    after_1:
    // 0x80407A30: b           L_80407A54
    // 0x80407A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80407A54;
    // 0x80407A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80407A38:
    // 0x80407A38: jal         0x80407B8C
    // 0x80407A3C: nop

    func_80407B8C(rdram, ctx);
        goto after_2;
    // 0x80407A3C: nop

    after_2:
    // 0x80407A40: b           L_80407A54
    // 0x80407A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80407A54;
    // 0x80407A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80407A48:
    // 0x80407A48: jal         0x804081EC
    // 0x80407A4C: nop

    func_804081EC(rdram, ctx);
        goto after_3;
    // 0x80407A4C: nop

    after_3:
    // 0x80407A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80407A54:
    // 0x80407A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80407A58: jr          $ra
    // 0x80407A5C: nop

    return;
    // 0x80407A5C: nop

;}
RECOMP_FUNC void func_8045DD20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045DD20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8045DD24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045DD28: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8045DD2C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8045DD30: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8045DD34: jal         0x80066DE4
    // 0x8045DD38: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8045DD38: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x8045DD3C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8045DD40: jal         0x80066E88
    // 0x8045DD44: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8045DD44: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8045DD48: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8045DD4C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8045DD50: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8045DD54: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045DD58: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045DD5C: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x8045DD60: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8045DD64: nop

    // 0x8045DD68: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8045DD6C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8045DD70: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8045DD74: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045DD78: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045DD7C: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8045DD80: nop

    // 0x8045DD84: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8045DD88: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8045DD8C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8045DD90: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8045DD94: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8045DD98: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8045DD9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045DDA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8045DDA4: jr          $ra
    // 0x8045DDA8: nop

    return;
    // 0x8045DDA8: nop

;}
RECOMP_FUNC void func_805DBB44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DBB44: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x805DBB48: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x805DBB4C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x805DBB50: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x805DBB54: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x805DBB58: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x805DBB5C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x805DBB60: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x805DBB64: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x805DBB68: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x805DBB6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DBB70: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805DBB74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805DBB78: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x805DBB7C: bne         $t6, $at, L_805DBC24
    if (ctx->r14 != ctx->r1) {
        // 0x805DBB80: lw          $s6, 0x1F4($a0)
        ctx->r22 = MEM_W(ctx->r4, 0X1F4);
            goto L_805DBC24;
    }
    // 0x805DBB80: lw          $s6, 0x1F4($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DBB84: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805DBB88: slti        $at, $v0, 0x407A
    ctx->r1 = SIGNED(ctx->r2) < 0X407A ? 1 : 0;
    // 0x805DBB8C: bne         $at, $zero, L_805DBBD8
    if (ctx->r1 != 0) {
        // 0x805DBB90: slti        $at, $v0, 0x4093
        ctx->r1 = SIGNED(ctx->r2) < 0X4093 ? 1 : 0;
            goto L_805DBBD8;
    }
    // 0x805DBB90: slti        $at, $v0, 0x4093
    ctx->r1 = SIGNED(ctx->r2) < 0X4093 ? 1 : 0;
    // 0x805DBB94: bne         $at, $zero, L_805DBBBC
    if (ctx->r1 != 0) {
        // 0x805DBB98: addiu       $t7, $v0, -0x4532
        ctx->r15 = ADD32(ctx->r2, -0X4532);
            goto L_805DBBBC;
    }
    // 0x805DBB98: addiu       $t7, $v0, -0x4532
    ctx->r15 = ADD32(ctx->r2, -0X4532);
    // 0x805DBB9C: sltiu       $at, $t7, 0x15
    ctx->r1 = ctx->r15 < 0X15 ? 1 : 0;
    // 0x805DBBA0: beq         $at, $zero, L_805DBC30
    if (ctx->r1 == 0) {
        // 0x805DBBA4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_805DBC30;
    }
    // 0x805DBBA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805DBBA8: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X2808) << 16);
    // 0x805DBBAC: addu        $at, $at, $t7
    gpr jr_addend_805DBBB4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805DBBB0: lw          $t7, -0x2AF8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(480, 0X2808));
    // 0x805DBBB4: jr          $t7
    // 0x805DBBB8: nop

    switch (jr_addend_805DBBB4 >> 2) {
        case 0: goto L_805DBC10; break;
        case 1: goto L_805DBBFC; break;
        case 2: goto L_805DBBFC; break;
        case 3: goto L_805DBBFC; break;
        case 4: goto L_805DBC30; break;
        case 5: goto L_805DBC30; break;
        case 6: goto L_805DBC30; break;
        case 7: goto L_805DBC30; break;
        case 8: goto L_805DBC30; break;
        case 9: goto L_805DBC30; break;
        case 10: goto L_805DBC30; break;
        case 11: goto L_805DBBFC; break;
        case 12: goto L_805DBC30; break;
        case 13: goto L_805DBC30; break;
        case 14: goto L_805DBC30; break;
        case 15: goto L_805DBC30; break;
        case 16: goto L_805DBC30; break;
        case 17: goto L_805DBC30; break;
        case 18: goto L_805DBC30; break;
        case 19: goto L_805DBBFC; break;
        case 20: goto L_805DBBFC; break;
        default: switch_error(__func__, 0x805DBBB4, 0x805DD508);
    }
    // 0x805DBBB8: nop

L_805DBBBC:
    // 0x805DBBBC: addiu       $at, $zero, 0x407C
    ctx->r1 = ADD32(0, 0X407C);
    // 0x805DBBC0: beq         $v0, $at, L_805DBC10
    if (ctx->r2 == ctx->r1) {
        // 0x805DBBC4: addiu       $at, $zero, 0x4092
        ctx->r1 = ADD32(0, 0X4092);
            goto L_805DBC10;
    }
    // 0x805DBBC4: addiu       $at, $zero, 0x4092
    ctx->r1 = ADD32(0, 0X4092);
    // 0x805DBBC8: beql        $v0, $at, L_805DBC14
    if (ctx->r2 == ctx->r1) {
        // 0x805DBBCC: addiu       $a0, $zero, 0xC0
        ctx->r4 = ADD32(0, 0XC0);
            goto L_805DBC14;
    }
    goto skip_0;
    // 0x805DBBCC: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    skip_0:
    // 0x805DBBD0: b           L_805DBC34
    // 0x805DBBD4: addiu       $s3, $fp, 0xC4
    ctx->r19 = ADD32(ctx->r30, 0XC4);
        goto L_805DBC34;
    // 0x805DBBD4: addiu       $s3, $fp, 0xC4
    ctx->r19 = ADD32(ctx->r30, 0XC4);
L_805DBBD8:
    // 0x805DBBD8: addiu       $at, $zero, 0x4047
    ctx->r1 = ADD32(0, 0X4047);
    // 0x805DBBDC: beq         $v0, $at, L_805DBC10
    if (ctx->r2 == ctx->r1) {
        // 0x805DBBE0: addiu       $at, $zero, 0x4048
        ctx->r1 = ADD32(0, 0X4048);
            goto L_805DBC10;
    }
    // 0x805DBBE0: addiu       $at, $zero, 0x4048
    ctx->r1 = ADD32(0, 0X4048);
    // 0x805DBBE4: beq         $v0, $at, L_805DBC10
    if (ctx->r2 == ctx->r1) {
        // 0x805DBBE8: addiu       $at, $zero, 0x4079
        ctx->r1 = ADD32(0, 0X4079);
            goto L_805DBC10;
    }
    // 0x805DBBE8: addiu       $at, $zero, 0x4079
    ctx->r1 = ADD32(0, 0X4079);
    // 0x805DBBEC: beql        $v0, $at, L_805DBC14
    if (ctx->r2 == ctx->r1) {
        // 0x805DBBF0: addiu       $a0, $zero, 0xC0
        ctx->r4 = ADD32(0, 0XC0);
            goto L_805DBC14;
    }
    goto skip_1;
    // 0x805DBBF0: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    skip_1:
    // 0x805DBBF4: b           L_805DBC34
    // 0x805DBBF8: addiu       $s3, $fp, 0xC4
    ctx->r19 = ADD32(ctx->r30, 0XC4);
        goto L_805DBC34;
    // 0x805DBBF8: addiu       $s3, $fp, 0xC4
    ctx->r19 = ADD32(ctx->r30, 0XC4);
L_805DBBFC:
    // 0x805DBBFC: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x805DBC00: sb          $a0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r4;
    // 0x805DBC04: sb          $a0, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r4;
    // 0x805DBC08: b           L_805DBC30
    // 0x805DBC0C: sb          $a0, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r4;
        goto L_805DBC30;
    // 0x805DBC0C: sb          $a0, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r4;
L_805DBC10:
    // 0x805DBC10: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
L_805DBC14:
    // 0x805DBC14: sb          $a0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r4;
    // 0x805DBC18: sb          $a0, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r4;
    // 0x805DBC1C: b           L_805DBC30
    // 0x805DBC20: sb          $zero, 0x66($sp)
    MEM_B(0X66, ctx->r29) = 0;
        goto L_805DBC30;
    // 0x805DBC20: sb          $zero, 0x66($sp)
    MEM_B(0X66, ctx->r29) = 0;
L_805DBC24:
    // 0x805DBC24: sb          $zero, 0x64($sp)
    MEM_B(0X64, ctx->r29) = 0;
    // 0x805DBC28: sb          $zero, 0x66($sp)
    MEM_B(0X66, ctx->r29) = 0;
    // 0x805DBC2C: sb          $zero, 0x65($sp)
    MEM_B(0X65, ctx->r29) = 0;
L_805DBC30:
    // 0x805DBC30: addiu       $s3, $fp, 0xC4
    ctx->r19 = ADD32(ctx->r30, 0XC4);
L_805DBC34:
    // 0x805DBC34: lw          $t8, 0x68($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X68);
    // 0x805DBC38: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x805DBC3C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x805DBC40: bne         $t8, $zero, L_805DBC58
    if (ctx->r24 != 0) {
        // 0x805DBC44: or          $s5, $s6, $zero
        ctx->r21 = ctx->r22 | 0;
            goto L_805DBC58;
    }
    // 0x805DBC44: or          $s5, $s6, $zero
    ctx->r21 = ctx->r22 | 0;
    // 0x805DBC48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805DBC4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805DBC50: b           L_805DBC68
    // 0x805DBC54: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
        goto L_805DBC68;
    // 0x805DBC54: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
L_805DBC58:
    // 0x805DBC58: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805DBC5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DBC60: nop

    // 0x805DBC64: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
L_805DBC68:
    // 0x805DBC68: lw          $s0, 0x0($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X0);
    // 0x805DBC6C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x805DBC70: beql        $s0, $zero, L_805DBF5C
    if (ctx->r16 == 0) {
        // 0x805DBC74: sw          $zero, 0x0($s5)
        MEM_W(0X0, ctx->r21) = 0;
            goto L_805DBF5C;
    }
    goto skip_2;
    // 0x805DBC74: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    skip_2:
    // 0x805DBC78: jal         0x80047EB0
    // 0x805DBC7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047EB0(rdram, ctx);
        goto after_0;
    // 0x805DBC7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x805DBC80: beq         $v0, $zero, L_805DBF58
    if (ctx->r2 == 0) {
        // 0x805DBC84: sll         $s2, $s4, 1
        ctx->r18 = S32(ctx->r20 << 1);
            goto L_805DBF58;
    }
    // 0x805DBC84: sll         $s2, $s4, 1
    ctx->r18 = S32(ctx->r20 << 1);
    // 0x805DBC88: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x805DBC8C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805DBC90: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805DBC94: addiu       $at, $zero, 0x4194
    ctx->r1 = ADD32(0, 0X4194);
    // 0x805DBC98: beq         $v0, $at, L_805DBCB4
    if (ctx->r2 == ctx->r1) {
        // 0x805DBC9C: sw          $t9, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r25;
            goto L_805DBCB4;
    }
    // 0x805DBC9C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x805DBCA0: addiu       $at, $zero, 0x4195
    ctx->r1 = ADD32(0, 0X4195);
    // 0x805DBCA4: beq         $v0, $at, L_805DBCE4
    if (ctx->r2 == ctx->r1) {
        // 0x805DBCA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DBCE4;
    }
    // 0x805DBCA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DBCAC: b           L_805DBD10
    // 0x805DBCB0: lw          $v1, 0x16C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X16C);
        goto L_805DBD10;
    // 0x805DBCB0: lw          $v1, 0x16C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X16C);
L_805DBCB4:
    // 0x805DBCB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DBCB8: jal         0x805DAF64
    // 0x805DBCBC: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    func_805DAF64(rdram, ctx);
        goto after_1;
    // 0x805DBCBC: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_1:
    // 0x805DBCC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DBCC4: jal         0x805DAF64
    // 0x805DBCC8: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_805DAF64(rdram, ctx);
        goto after_2;
    // 0x805DBCC8: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_2:
    // 0x805DBCCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DBCD0: jal         0x805DAF64
    // 0x805DBCD4: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    func_805DAF64(rdram, ctx);
        goto after_3;
    // 0x805DBCD4: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    after_3:
    // 0x805DBCD8: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x805DBCDC: b           L_805DBD0C
    // 0x805DBCE0: sh          $t0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r8;
        goto L_805DBD0C;
    // 0x805DBCE0: sh          $t0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r8;
L_805DBCE4:
    // 0x805DBCE4: jal         0x805DAF64
    // 0x805DBCE8: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    func_805DAF64(rdram, ctx);
        goto after_4;
    // 0x805DBCE8: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    after_4:
    // 0x805DBCEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DBCF0: jal         0x805DAF64
    // 0x805DBCF4: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    func_805DAF64(rdram, ctx);
        goto after_5;
    // 0x805DBCF4: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_5:
    // 0x805DBCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DBCFC: jal         0x805DAF64
    // 0x805DBD00: addiu       $a1, $zero, 0x27E
    ctx->r5 = ADD32(0, 0X27E);
    func_805DAF64(rdram, ctx);
        goto after_6;
    // 0x805DBD00: addiu       $a1, $zero, 0x27E
    ctx->r5 = ADD32(0, 0X27E);
    after_6:
    // 0x805DBD04: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x805DBD08: sh          $t1, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r9;
L_805DBD0C:
    // 0x805DBD0C: lw          $v1, 0x16C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X16C);
L_805DBD10:
    // 0x805DBD10: lbu         $t2, 0x64($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X64);
    // 0x805DBD14: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x805DBD18: sb          $t2, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r10;
    // 0x805DBD1C: lbu         $t3, 0x65($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X65);
    // 0x805DBD20: sb          $t3, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r11;
    // 0x805DBD24: lbu         $t4, 0x66($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X66);
    // 0x805DBD28: sb          $t4, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r12;
    // 0x805DBD2C: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x805DBD30: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x805DBD34: beql        $a1, $zero, L_805DBD7C
    if (ctx->r5 == 0) {
        // 0x805DBD38: lw          $t1, 0x50($s6)
        ctx->r9 = MEM_W(ctx->r22, 0X50);
            goto L_805DBD7C;
    }
    goto skip_3;
    // 0x805DBD38: lw          $t1, 0x50($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X50);
    skip_3:
    // 0x805DBD3C: lw          $v0, 0x16C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X16C);
    // 0x805DBD40: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x805DBD44: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x805DBD48: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x805DBD4C: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x805DBD50: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    // 0x805DBD54: lbu         $t7, 0x2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X2);
    // 0x805DBD58: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    // 0x805DBD5C: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x805DBD60: sb          $t8, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r24;
    // 0x805DBD64: lbu         $t9, 0x5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5);
    // 0x805DBD68: sb          $t9, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r25;
    // 0x805DBD6C: lbu         $t0, 0x6($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X6);
    // 0x805DBD70: sb          $t0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r8;
    // 0x805DBD74: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x805DBD78: lw          $t1, 0x50($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X50);
L_805DBD7C:
    // 0x805DBD7C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x805DBD80: lwc1        $f4, 0x60($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X60);
    // 0x805DBD84: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x805DBD88: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x805DBD8C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805DBD90: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x805DBD94: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x805DBD98: nop

    // 0x805DBD9C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805DBDA0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x805DBDA4: nop

    // 0x805DBDA8: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x805DBDAC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x805DBDB0: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x805DBDB4: lw          $t4, 0x54($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X54);
    // 0x805DBDB8: lwc1        $f8, 0x64($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X64);
    // 0x805DBDBC: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805DBDC0: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x805DBDC4: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x805DBDC8: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x805DBDCC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x805DBDD0: nop

    // 0x805DBDD4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x805DBDD8: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x805DBDDC: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x805DBDE0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x805DBDE4: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x805DBDE8: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x805DBDEC: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805DBDF0: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x805DBDF4: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x805DBDF8: nop

    // 0x805DBDFC: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x805DBE00: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x805DBE04: sw          $t1, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r9;
    // 0x805DBE08: lw          $t2, 0x68($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X68);
    // 0x805DBE0C: bne         $t2, $zero, L_805DBE68
    if (ctx->r10 != 0) {
        // 0x805DBE10: nop
    
            goto L_805DBE68;
    }
    // 0x805DBE10: nop

    // 0x805DBE14: jal         0x800653D8
    // 0x805DBE18: nop

    func_800653D8(rdram, ctx);
        goto after_7;
    // 0x805DBE18: nop

    after_7:
    // 0x805DBE1C: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x805DBE20: beq         $t3, $zero, L_805DBE48
    if (ctx->r11 == 0) {
        // 0x805DBE24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DBE48;
    }
    // 0x805DBE24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DBE28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DBE2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DBE30: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805DBE34: jal         0x805DD234
    // 0x805DBE38: lw          $a3, 0x68($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X68);
    func_805DD234(rdram, ctx);
        goto after_8;
    // 0x805DBE38: lw          $a3, 0x68($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X68);
    after_8:
    // 0x805DBE3C: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x805DBE40: b           L_805DBEB8
    // 0x805DBE44: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
        goto L_805DBEB8;
    // 0x805DBE44: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
L_805DBE48:
    // 0x805DBE48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DBE4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805DBE50: jal         0x805DD234
    // 0x805DBE54: lw          $a3, 0x68($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X68);
    func_805DD234(rdram, ctx);
        goto after_9;
    // 0x805DBE54: lw          $a3, 0x68($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X68);
    after_9:
    // 0x805DBE58: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x805DBE5C: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x805DBE60: b           L_805DBEB8
    // 0x805DBE64: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
        goto L_805DBEB8;
    // 0x805DBE64: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
L_805DBE68:
    // 0x805DBE68: jal         0x800653D8
    // 0x805DBE6C: nop

    func_800653D8(rdram, ctx);
        goto after_10;
    // 0x805DBE6C: nop

    after_10:
    // 0x805DBE70: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x805DBE74: beq         $t4, $zero, L_805DBEA0
    if (ctx->r12 == 0) {
        // 0x805DBE78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805DBEA0;
    }
    // 0x805DBE78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DBE7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DBE80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DBE84: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805DBE88: jal         0x805DD234
    // 0x805DBE8C: lw          $a3, 0x68($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X68);
    func_805DD234(rdram, ctx);
        goto after_11;
    // 0x805DBE8C: lw          $a3, 0x68($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X68);
    after_11:
    // 0x805DBE90: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x805DBE94: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x805DBE98: b           L_805DBEB8
    // 0x805DBE9C: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
        goto L_805DBEB8;
    // 0x805DBE9C: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
L_805DBEA0:
    // 0x805DBEA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DBEA4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805DBEA8: jal         0x805DD234
    // 0x805DBEAC: lw          $a3, 0x68($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X68);
    func_805DD234(rdram, ctx);
        goto after_12;
    // 0x805DBEAC: lw          $a3, 0x68($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X68);
    after_12:
    // 0x805DBEB0: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x805DBEB4: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
L_805DBEB8:
    // 0x805DBEB8: jal         0x800653D8
    // 0x805DBEBC: nop

    func_800653D8(rdram, ctx);
        goto after_13;
    // 0x805DBEBC: nop

    after_13:
    // 0x805DBEC0: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x805DBEC4: beql        $t5, $zero, L_805DBEDC
    if (ctx->r13 == 0) {
        // 0x805DBEC8: lwc1        $f18, 0x10($s1)
        ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
            goto L_805DBEDC;
    }
    goto skip_4;
    // 0x805DBEC8: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    skip_4:
    // 0x805DBECC: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x805DBED0: b           L_805DBEE4
    // 0x805DBED4: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
        goto L_805DBEE4;
    // 0x805DBED4: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x805DBED8: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
L_805DBEDC:
    // 0x805DBEDC: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x805DBEE0: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
L_805DBEE4:
    // 0x805DBEE4: jal         0x800653D8
    // 0x805DBEE8: nop

    func_800653D8(rdram, ctx);
        goto after_14;
    // 0x805DBEE8: nop

    after_14:
    // 0x805DBEEC: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x805DBEF0: beq         $t6, $zero, L_805DBF10
    if (ctx->r14 == 0) {
        // 0x805DBEF4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_805DBF10;
    }
    // 0x805DBEF4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805DBEF8: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x805DBEFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805DBF00: nop

    // 0x805DBF04: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x805DBF08: b           L_805DBF28
    // 0x805DBF0C: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
        goto L_805DBF28;
    // 0x805DBF0C: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
L_805DBF10:
    // 0x805DBF10: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x805DBF14: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805DBF18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DBF1C: neg.s       $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = -ctx->f4.fl;
    // 0x805DBF20: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x805DBF24: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
L_805DBF28:
    // 0x805DBF28: lbu         $t7, 0x30($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X30);
    // 0x805DBF2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805DBF30: bne         $t7, $at, L_805DBF48
    if (ctx->r15 != ctx->r1) {
        // 0x805DBF34: nop
    
            goto L_805DBF48;
    }
    // 0x805DBF34: nop

    // 0x805DBF38: jal         0x8005FE48
    // 0x805DBF3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_15;
    // 0x805DBF3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x805DBF40: b           L_805DBF60
    // 0x805DBF44: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_805DBF60;
    // 0x805DBF44: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_805DBF48:
    // 0x805DBF48: jal         0x8005FDC4
    // 0x805DBF4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_16;
    // 0x805DBF4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x805DBF50: b           L_805DBF60
    // 0x805DBF54: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_805DBF60;
    // 0x805DBF54: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_805DBF58:
    // 0x805DBF58: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
L_805DBF5C:
    // 0x805DBF5C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_805DBF60:
    // 0x805DBF60: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x805DBF64: bne         $s4, $at, L_805DBC68
    if (ctx->r20 != ctx->r1) {
        // 0x805DBF68: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_805DBC68;
    }
    // 0x805DBF68: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x805DBF6C: bnel        $s7, $zero, L_805DBF80
    if (ctx->r23 != 0) {
        // 0x805DBF70: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_805DBF80;
    }
    goto skip_5;
    // 0x805DBF70: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_5:
    // 0x805DBF74: jal         0x800447C8
    // 0x805DBF78: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_800447C8(rdram, ctx);
        goto after_17;
    // 0x805DBF78: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_17:
    // 0x805DBF7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_805DBF80:
    // 0x805DBF80: div         $zero, $s7, $at
    lo = S32(S64(S32(ctx->r23)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r23)) % S64(S32(ctx->r1)));
    // 0x805DBF84: mflo        $t8
    ctx->r24 = lo;
    // 0x805DBF88: sw          $t8, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->r24;
    // 0x805DBF8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x805DBF90: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x805DBF94: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x805DBF98: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x805DBF9C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x805DBFA0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x805DBFA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x805DBFA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x805DBFAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x805DBFB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DBFB4: jr          $ra
    // 0x805DBFB8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x805DBFB8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80065C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065C44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065C48: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80065C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065C50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065C54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80065C58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80065C5C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065C60: jal         0x8006593C
    // 0x80065C64: subu        $a0, $a0, $t7
    ctx->r4 = SUB32(ctx->r4, ctx->r15);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80065C64: subu        $a0, $a0, $t7
    ctx->r4 = SUB32(ctx->r4, ctx->r15);
    after_0:
    // 0x80065C68: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80065C6C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80065C70: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80065C74: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80065C78: subu        $t1, $t0, $v0
    ctx->r9 = SUB32(ctx->r8, ctx->r2);
    // 0x80065C7C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80065C80: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80065C84: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80065C88: jal         0x8006593C
    // 0x80065C8C: subu        $a0, $t3, $t4
    ctx->r4 = SUB32(ctx->r11, ctx->r12);
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x80065C8C: subu        $a0, $t3, $t4
    ctx->r4 = SUB32(ctx->r11, ctx->r12);
    after_1:
    // 0x80065C90: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80065C94: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80065C98: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80065C9C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80065CA0: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80065CA4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80065CA8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80065CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065CB0: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80065CB4: slti        $v0, $v0, 0x0
    ctx->r2 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x80065CB8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80065CBC: beq         $v0, $zero, L_80065CCC
    if (ctx->r2 == 0) {
        // 0x80065CC0: nop
    
            goto L_80065CCC;
    }
    // 0x80065CC0: nop

    // 0x80065CC4: slti        $v0, $t8, 0x0
    ctx->r2 = SIGNED(ctx->r24) < 0X0 ? 1 : 0;
    // 0x80065CC8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_80065CCC:
    // 0x80065CCC: jr          $ra
    // 0x80065CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80065CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804CACF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CACF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CACFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CAD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CAD04: jal         0x80045A34
    // 0x804CAD08: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804CAD08: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x804CAD0C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x804CAD10: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x804CAD14: bne         $v0, $zero, L_804CAD2C
    if (ctx->r2 != 0) {
        // 0x804CAD18: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_804CAD2C;
    }
    // 0x804CAD18: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x804CAD1C: jal         0x800445A4
    // 0x804CAD20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804CAD20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x804CAD24: b           L_804CAD3C
    // 0x804CAD28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CAD3C;
    // 0x804CAD28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CAD2C:
    // 0x804CAD2C: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x804CAD30: jal         0x80065728
    // 0x804CAD34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x804CAD34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x804CAD38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804CAD3C:
    // 0x804CAD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CAD40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CAD44: jr          $ra
    // 0x804CAD48: nop

    return;
    // 0x804CAD48: nop

;}
RECOMP_FUNC void func_80435328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435328: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8043532C: lwc1        $f6, 0xE0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x80435330: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80435334: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80435338: nop

    // 0x8043533C: bc1t        L_80435354
    if (c1cs) {
        // 0x80435340: nop
    
            goto L_80435354;
    }
    // 0x80435340: nop

    // 0x80435344: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80435348: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8043534C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80435350: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
L_80435354:
    // 0x80435354: jr          $ra
    // 0x80435358: nop

    return;
    // 0x80435358: nop

;}
RECOMP_FUNC void func_8043A8A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043A8A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8043A8AC: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8043A8B0: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x8043A8B4: lhu         $t9, 0xC($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XC);
    // 0x8043A8B8: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8043A8BC: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8043A8C0: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x8043A8C4: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x8043A8C8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8043A8CC: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8043A8D0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8043A8D4: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8043A8D8: bnel        $t9, $at, L_8043AA2C
    if (ctx->r25 != ctx->r1) {
        // 0x8043A8DC: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8043AA2C;
    }
    goto skip_0;
    // 0x8043A8DC: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_0:
    // 0x8043A8E0: lw          $t0, 0x180($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X180);
    // 0x8043A8E4: bnel        $t0, $zero, L_8043AA2C
    if (ctx->r8 != 0) {
        // 0x8043A8E8: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8043AA2C;
    }
    goto skip_1;
    // 0x8043A8E8: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_1:
    // 0x8043A8EC: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8043A8F0: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8043A8F4: lwc1        $f14, 0x0($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8043A8F8: mul.s       $f16, $f18, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8043A8FC: nop

    // 0x8043A900: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8043A904: nop

    // 0x8043A908: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8043A90C: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8043A910: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8043A914: nop

    // 0x8043A918: bc1f        L_8043AA28
    if (!c1cs) {
        // 0x8043A91C: nop
    
            goto L_8043AA28;
    }
    // 0x8043A91C: nop

    // 0x8043A920: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8043A924: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11A8) << 16);
    // 0x8043A928: bc1fl       L_8043AA2C
    if (!c1cs) {
        // 0x8043A92C: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8043AA2C;
    }
    goto skip_2;
    // 0x8043A92C: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_2:
    // 0x8043A930: lwc1        $f4, -0x47F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11A8));
    // 0x8043A934: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8043A938: nop

    // 0x8043A93C: bc1fl       L_8043AA18
    if (!c1cs) {
        // 0x8043A940: lwc1        $f10, 0x3C($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
            goto L_8043AA18;
    }
    goto skip_3;
    // 0x8043A940: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    skip_3:
    // 0x8043A944: div.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8043A948: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11AC) << 16);
    // 0x8043A94C: lwc1        $f10, -0x47F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11AC));
    // 0x8043A950: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8043A954: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8043A958: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8043A95C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8043A960: nop

    // 0x8043A964: mul.s       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x8043A968: nop

    // 0x8043A96C: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8043A970: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8043A974: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8043A978: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8043A97C: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8043A980: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8043A984: swc1        $f6, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f6.u32l;
    // 0x8043A988: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8043A98C: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8043A990: lwc1        $f6, 0xC4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x8043A994: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8043A998: swc1        $f10, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f10.u32l;
    // 0x8043A99C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8043A9A0: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8043A9A4: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x8043A9A8: nop

    // 0x8043A9AC: bc1f        L_8043A9D8
    if (!c1cs) {
        // 0x8043A9B0: nop
    
            goto L_8043A9D8;
    }
    // 0x8043A9B0: nop

    // 0x8043A9B4: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8043A9B8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11B0) << 16);
    // 0x8043A9BC: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x8043A9C0: nop

    // 0x8043A9C4: bc1fl       L_8043A9DC
    if (!c1cs) {
        // 0x8043A9C8: lwc1        $f8, 0xC8($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0XC8);
            goto L_8043A9DC;
    }
    goto skip_4;
    // 0x8043A9C8: lwc1        $f8, 0xC8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC8);
    skip_4:
    // 0x8043A9CC: lwc1        $f10, -0x47F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11B0));
    // 0x8043A9D0: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8043A9D4: swc1        $f6, 0xC4($a1)
    MEM_W(0XC4, ctx->r5) = ctx->f6.u32l;
L_8043A9D8:
    // 0x8043A9D8: lwc1        $f8, 0xC8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC8);
L_8043A9DC:
    // 0x8043A9DC: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x8043A9E0: nop

    // 0x8043A9E4: bc1fl       L_8043AA2C
    if (!c1cs) {
        // 0x8043A9E8: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8043AA2C;
    }
    goto skip_5;
    // 0x8043A9E8: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_5:
    // 0x8043A9EC: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8043A9F0: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x8043A9F4: nop

    // 0x8043A9F8: bc1fl       L_8043AA2C
    if (!c1cs) {
        // 0x8043A9FC: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8043AA2C;
    }
    goto skip_6;
    // 0x8043A9FC: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_6:
    // 0x8043AA00: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8043AA04: lw          $t1, 0x34($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X34);
    // 0x8043AA08: ori         $t2, $t1, 0x3000
    ctx->r10 = ctx->r9 | 0X3000;
    // 0x8043AA0C: b           L_8043AA28
    // 0x8043AA10: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
        goto L_8043AA28;
    // 0x8043AA10: sw          $t2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r10;
    // 0x8043AA14: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
L_8043AA18:
    // 0x8043AA18: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8043AA1C: swc1        $f6, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f6.u32l;
    // 0x8043AA20: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8043AA24: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
L_8043AA28:
    // 0x8043AA28: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_8043AA2C:
    // 0x8043AA2C: jr          $ra
    // 0x8043AA30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8043AA30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804E7A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7A28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E7A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E7A30: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804E7A34: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804E7A38: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804E7A3C: lui         $t7, 0x804E
    ctx->r15 = S32(RELOC_HI16(261, 0X63C) << 16);
    // 0x804E7A40: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x804E7A44: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804E7A48: addiu       $t7, $t7, 0x7E9C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(261, 0X63C));
    // 0x804E7A4C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804E7A50: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804E7A54: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x804E7A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804E7A5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804E7A60: jal         0x804E7D5C
    // 0x804E7A64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804E7D5C(rdram, ctx);
        goto after_0;
    // 0x804E7A64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x804E7A68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804E7A6C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x804E7A70: addiu       $t9, $t9, 0x6418
    ctx->r25 = ADD32(ctx->r25, 0X6418);
    // 0x804E7A74: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x804E7A78: sw          $t9, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r25;
    // 0x804E7A7C: jal         0x804E7920
    // 0x804E7A80: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    func_804E7920(rdram, ctx);
        goto after_1;
    // 0x804E7A80: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    after_1:
    // 0x804E7A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E7A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E7A8C: jr          $ra
    // 0x804E7A90: nop

    return;
    // 0x804E7A90: nop

;}
RECOMP_FUNC void func_80010A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80010A78: sltiu       $at, $a0, 0x32
    ctx->r1 = ctx->r4 < 0X32 ? 1 : 0;
    // 0x80010A7C: beq         $at, $zero, L_80011350
    if (ctx->r1 == 0) {
        // 0x80010A80: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80011350;
    }
    // 0x80010A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010A84: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80010A88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80010A8C: addu        $at, $at, $t6
    gpr jr_addend_80010A94 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80010A90: lw          $t6, -0x3414($at)
    ctx->r14 = ADD32(ctx->r1, -0X3414);
    // 0x80010A94: jr          $t6
    // 0x80010A98: nop

    switch (jr_addend_80010A94 >> 2) {
        case 0: goto L_80011350; break;
        case 1: goto L_80010C74; break;
        case 2: goto L_80010CC0; break;
        case 3: goto L_80010A9C; break;
        case 4: goto L_80010AD0; break;
        case 5: goto L_80010B04; break;
        case 6: goto L_80010B38; break;
        case 7: goto L_80010B6C; break;
        case 8: goto L_80010BA0; break;
        case 9: goto L_80011054; break;
        case 10: goto L_80011080; break;
        case 11: goto L_80010BD4; break;
        case 12: goto L_80010C1C; break;
        case 13: goto L_80010CF4; break;
        case 14: goto L_80010D34; break;
        case 15: goto L_80010DA8; break;
        case 16: goto L_80010DB8; break;
        case 17: goto L_80010F34; break;
        case 18: goto L_80011064; break;
        case 19: goto L_800110B0; break;
        case 20: goto L_80011140; break;
        case 21: goto L_80011158; break;
        case 22: goto L_80011178; break;
        case 23: goto L_800111A4; break;
        case 24: goto L_800111D0; break;
        case 25: goto L_80010D74; break;
        case 26: goto L_80010F8C; break;
        case 27: goto L_800111E4; break;
        case 28: goto L_800111F8; break;
        case 29: goto L_8001120C; break;
        case 30: goto L_8001125C; break;
        case 31: goto L_80011270; break;
        case 32: goto L_80011284; break;
        case 33: goto L_800112AC; break;
        case 34: goto L_800112C0; break;
        case 35: goto L_80011350; break;
        case 36: goto L_800112DC; break;
        case 37: goto L_80010FEC; break;
        case 38: goto L_80011350; break;
        case 39: goto L_800112F8; break;
        case 40: goto L_80011334; break;
        case 41: goto L_80010C48; break;
        case 42: goto L_80011020; break;
        case 43: goto L_80011228; break;
        case 44: goto L_80010DC4; break;
        case 45: goto L_80010E1C; break;
        case 46: goto L_800110E0; break;
        case 47: goto L_80011110; break;
        case 48: goto L_80010E7C; break;
        case 49: goto L_80010ED4; break;
        default: switch_error(__func__, 0x80010A94, 0x800ACBEC);
    }
    // 0x80010A98: nop

L_80010A9C:
    // 0x80010A9C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010AA0: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80010AA4: jal         0x8001A900
    // 0x80010AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001A900(rdram, ctx);
        goto after_0;
    // 0x80010AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80010AAC: jal         0x80011400
    // 0x80010AB0: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_80011400(rdram, ctx);
        goto after_1;
    // 0x80010AB0: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_1:
    // 0x80010AB4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80010AB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010ABC: jal         0x8001A850
    // 0x80010AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A850(rdram, ctx);
        goto after_2;
    // 0x80010AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80010AC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010AC8: b           L_80011350
    // 0x80010ACC: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
        goto L_80011350;
    // 0x80010ACC: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
L_80010AD0:
    // 0x80010AD0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010AD4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80010AD8: jal         0x8001A900
    // 0x80010ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001A900(rdram, ctx);
        goto after_3;
    // 0x80010ADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80010AE0: jal         0x80011400
    // 0x80010AE4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_80011400(rdram, ctx);
        goto after_4;
    // 0x80010AE4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_4:
    // 0x80010AE8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80010AEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010AF0: jal         0x8001A850
    // 0x80010AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A850(rdram, ctx);
        goto after_5;
    // 0x80010AF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80010AF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010AFC: b           L_80011350
    // 0x80010B00: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
        goto L_80011350;
    // 0x80010B00: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
L_80010B04:
    // 0x80010B04: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010B08: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80010B0C: jal         0x8001A900
    // 0x80010B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001A900(rdram, ctx);
        goto after_6;
    // 0x80010B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80010B14: jal         0x80011400
    // 0x80010B18: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_80011400(rdram, ctx);
        goto after_7;
    // 0x80010B18: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_7:
    // 0x80010B1C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80010B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010B24: jal         0x8001A850
    // 0x80010B28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A850(rdram, ctx);
        goto after_8;
    // 0x80010B28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80010B2C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010B30: b           L_80011350
    // 0x80010B34: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
        goto L_80011350;
    // 0x80010B34: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
L_80010B38:
    // 0x80010B38: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010B3C: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80010B40: jal         0x8001A900
    // 0x80010B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001A900(rdram, ctx);
        goto after_9;
    // 0x80010B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80010B48: jal         0x80011400
    // 0x80010B4C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_80011400(rdram, ctx);
        goto after_10;
    // 0x80010B4C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_10:
    // 0x80010B50: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80010B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010B58: jal         0x8001A850
    // 0x80010B5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A850(rdram, ctx);
        goto after_11;
    // 0x80010B5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80010B60: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010B64: b           L_80011350
    // 0x80010B68: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
        goto L_80011350;
    // 0x80010B68: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
L_80010B6C:
    // 0x80010B6C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010B70: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80010B74: jal         0x8001A900
    // 0x80010B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001A900(rdram, ctx);
        goto after_12;
    // 0x80010B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80010B7C: jal         0x80011400
    // 0x80010B80: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_80011400(rdram, ctx);
        goto after_13;
    // 0x80010B80: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_13:
    // 0x80010B84: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80010B88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010B8C: jal         0x8001A850
    // 0x80010B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A850(rdram, ctx);
        goto after_14;
    // 0x80010B90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80010B94: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010B98: b           L_80011350
    // 0x80010B9C: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
        goto L_80011350;
    // 0x80010B9C: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
L_80010BA0:
    // 0x80010BA0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010BA4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80010BA8: jal         0x8001A900
    // 0x80010BAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001A900(rdram, ctx);
        goto after_15;
    // 0x80010BAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80010BB0: jal         0x80011400
    // 0x80010BB4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_80011400(rdram, ctx);
        goto after_16;
    // 0x80010BB4: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_16:
    // 0x80010BB8: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x80010BBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010BC0: jal         0x8001A850
    // 0x80010BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A850(rdram, ctx);
        goto after_17;
    // 0x80010BC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80010BC8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010BCC: b           L_80011350
    // 0x80010BD0: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
        goto L_80011350;
    // 0x80010BD0: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
L_80010BD4:
    // 0x80010BD4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80010BD8: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80010BDC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80010BE0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80010BE4: beq         $v0, $zero, L_80010BF0
    if (ctx->r2 == 0) {
        // 0x80010BE8: nop
    
            goto L_80010BF0;
    }
    // 0x80010BE8: nop

    // 0x80010BEC: sw          $t7, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r15;
L_80010BF0:
    // 0x80010BF0: jal         0x800113B0
    // 0x80010BF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800113B0(rdram, ctx);
        goto after_18;
    // 0x80010BF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80010BF8: jal         0x80018EF4
    // 0x80010BFC: nop

    func_80018EF4(rdram, ctx);
        goto after_19;
    // 0x80010BFC: nop

    after_19:
    // 0x80010C00: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80010C04: ori         $a1, $v0, 0x100
    ctx->r5 = ctx->r2 | 0X100;
    // 0x80010C08: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80010C0C: jal         0x8001AE64
    // 0x80010C10: lw          $a0, -0x6D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D6C);
    func_8001AE64(rdram, ctx);
        goto after_20;
    // 0x80010C10: lw          $a0, -0x6D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D6C);
    after_20:
    // 0x80010C14: b           L_80011354
    // 0x80010C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010C1C:
    // 0x80010C1C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80010C20: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80010C24: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80010C28: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80010C2C: beq         $v0, $zero, L_80010C38
    if (ctx->r2 == 0) {
        // 0x80010C30: nop
    
            goto L_80010C38;
    }
    // 0x80010C30: nop

    // 0x80010C34: sw          $t8, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r24;
L_80010C38:
    // 0x80010C38: jal         0x800113B0
    // 0x80010C3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800113B0(rdram, ctx);
        goto after_21;
    // 0x80010C3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80010C40: b           L_80011354
    // 0x80010C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010C48:
    // 0x80010C48: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80010C4C: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80010C50: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80010C54: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80010C58: beq         $v0, $zero, L_80010C64
    if (ctx->r2 == 0) {
        // 0x80010C5C: nop
    
            goto L_80010C64;
    }
    // 0x80010C5C: nop

    // 0x80010C60: sw          $t9, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r25;
L_80010C64:
    // 0x80010C64: jal         0x800113B0
    // 0x80010C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800113B0(rdram, ctx);
        goto after_22;
    // 0x80010C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80010C6C: b           L_80011354
    // 0x80010C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010C74:
    // 0x80010C74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80010C78: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010C7C: sb          $t0, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r8;
    // 0x80010C80: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010C84: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80010C88: sh          $t1, -0x6D98($at)
    MEM_H(-0X6D98, ctx->r1) = ctx->r9;
    // 0x80010C8C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80010C90: jal         0x80011600
    // 0x80010C94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_23;
    // 0x80010C94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x80010C98: jal         0x80011C3C
    // 0x80010C9C: nop

    func_80011C3C(rdram, ctx);
        goto after_24;
    // 0x80010C9C: nop

    after_24:
    // 0x80010CA0: addiu       $a0, $zero, 0x294
    ctx->r4 = ADD32(0, 0X294);
    // 0x80010CA4: jal         0x80011D1C
    // 0x80010CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_25;
    // 0x80010CA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80010CAC: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    // 0x80010CB0: jal         0x80011D1C
    // 0x80010CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_26;
    // 0x80010CB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80010CB8: b           L_80011354
    // 0x80010CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010CC0:
    // 0x80010CC0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80010CC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010CC8: sb          $t2, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r10;
    // 0x80010CCC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010CD0: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80010CD4: sh          $t3, -0x6D98($at)
    MEM_H(-0X6D98, ctx->r1) = ctx->r11;
    // 0x80010CD8: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x80010CDC: jal         0x80011600
    // 0x80010CE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_27;
    // 0x80010CE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80010CE4: jal         0x80011C3C
    // 0x80010CE8: nop

    func_80011C3C(rdram, ctx);
        goto after_28;
    // 0x80010CE8: nop

    after_28:
    // 0x80010CEC: b           L_80011354
    // 0x80010CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010CF4:
    // 0x80010CF4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80010CF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010CFC: sb          $t4, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r12;
    // 0x80010D00: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010D04: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80010D08: sh          $t5, -0x6D98($at)
    MEM_H(-0X6D98, ctx->r1) = ctx->r13;
    // 0x80010D0C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x80010D10: jal         0x80011600
    // 0x80010D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_29;
    // 0x80010D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80010D18: jal         0x80011C3C
    // 0x80010D1C: nop

    func_80011C3C(rdram, ctx);
        goto after_30;
    // 0x80010D1C: nop

    after_30:
    // 0x80010D20: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    // 0x80010D24: jal         0x80011D1C
    // 0x80010D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_31;
    // 0x80010D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x80010D2C: b           L_80011354
    // 0x80010D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010D34:
    // 0x80010D34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80010D38: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010D3C: sb          $t6, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r14;
    // 0x80010D40: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010D44: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80010D48: sh          $t7, -0x6D98($at)
    MEM_H(-0X6D98, ctx->r1) = ctx->r15;
    // 0x80010D4C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x80010D50: jal         0x80011600
    // 0x80010D54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_32;
    // 0x80010D54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80010D58: jal         0x80011C3C
    // 0x80010D5C: nop

    func_80011C3C(rdram, ctx);
        goto after_33;
    // 0x80010D5C: nop

    after_33:
    // 0x80010D60: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    // 0x80010D64: jal         0x80011D1C
    // 0x80010D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_34;
    // 0x80010D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_34:
    // 0x80010D6C: b           L_80011354
    // 0x80010D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010D74:
    // 0x80010D74: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80010D78: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010D7C: sb          $t8, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r24;
    // 0x80010D80: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010D84: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80010D88: sh          $t9, -0x6D98($at)
    MEM_H(-0X6D98, ctx->r1) = ctx->r25;
    // 0x80010D8C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80010D90: jal         0x80011600
    // 0x80010D94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_35;
    // 0x80010D94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_35:
    // 0x80010D98: jal         0x80011C3C
    // 0x80010D9C: nop

    func_80011C3C(rdram, ctx);
        goto after_36;
    // 0x80010D9C: nop

    after_36:
    // 0x80010DA0: b           L_80011354
    // 0x80010DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010DA8:
    // 0x80010DA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80010DAC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010DB0: b           L_80011350
    // 0x80010DB4: sb          $t0, -0x6D80($at)
    MEM_B(-0X6D80, ctx->r1) = ctx->r8;
        goto L_80011350;
    // 0x80010DB4: sb          $t0, -0x6D80($at)
    MEM_B(-0X6D80, ctx->r1) = ctx->r8;
L_80010DB8:
    // 0x80010DB8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010DBC: b           L_80011350
    // 0x80010DC0: sb          $zero, -0x6D80($at)
    MEM_B(-0X6D80, ctx->r1) = 0;
        goto L_80011350;
    // 0x80010DC0: sb          $zero, -0x6D80($at)
    MEM_B(-0X6D80, ctx->r1) = 0;
L_80010DC4:
    // 0x80010DC4: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80010DC8: lbu         $t2, -0x6D7C($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X6D7C);
    // 0x80010DCC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80010DD0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010DD4: beq         $t2, $zero, L_80010DE4
    if (ctx->r10 == 0) {
        // 0x80010DD8: sb          $t1, -0x6D78($at)
        MEM_B(-0X6D78, ctx->r1) = ctx->r9;
            goto L_80010DE4;
    }
    // 0x80010DD8: sb          $t1, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r9;
    // 0x80010DDC: jal         0x80010A74
    // 0x80010DE0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_80010A74(rdram, ctx);
        goto after_37;
    // 0x80010DE0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_37:
L_80010DE4:
    // 0x80010DE4: jal         0x8001168C
    // 0x80010DE8: nop

    func_8001168C(rdram, ctx);
        goto after_38;
    // 0x80010DE8: nop

    after_38:
    // 0x80010DEC: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80010DF0: jal         0x80011600
    // 0x80010DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_39;
    // 0x80010DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x80010DF8: jal         0x80011C64
    // 0x80010DFC: nop

    func_80011C64(rdram, ctx);
        goto after_40;
    // 0x80010DFC: nop

    after_40:
    // 0x80010E00: jal         0x80010A30
    // 0x80010E04: nop

    func_80010A30(rdram, ctx);
        goto after_41;
    // 0x80010E04: nop

    after_41:
    // 0x80010E08: addiu       $a0, $zero, 0xD8
    ctx->r4 = ADD32(0, 0XD8);
    // 0x80010E0C: jal         0x80011D1C
    // 0x80010E10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_42;
    // 0x80010E10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_42:
    // 0x80010E14: b           L_80011354
    // 0x80010E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010E1C:
    // 0x80010E1C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80010E20: lbu         $t3, -0x6D7C($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X6D7C);
    // 0x80010E24: beql        $t3, $zero, L_80010E38
    if (ctx->r11 == 0) {
        // 0x80010E28: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80010E38;
    }
    goto skip_0;
    // 0x80010E28: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_0:
    // 0x80010E2C: jal         0x80010A74
    // 0x80010E30: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_80010A74(rdram, ctx);
        goto after_43;
    // 0x80010E30: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_43:
    // 0x80010E34: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80010E38:
    // 0x80010E38: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010E3C: sb          $t4, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r12;
    // 0x80010E40: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010E44: jal         0x8001168C
    // 0x80010E48: sh          $zero, -0x6D74($at)
    MEM_H(-0X6D74, ctx->r1) = 0;
    func_8001168C(rdram, ctx);
        goto after_44;
    // 0x80010E48: sh          $zero, -0x6D74($at)
    MEM_H(-0X6D74, ctx->r1) = 0;
    after_44:
    // 0x80010E4C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x80010E50: jal         0x80011600
    // 0x80010E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_45;
    // 0x80010E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_45:
    // 0x80010E58: jal         0x80011C64
    // 0x80010E5C: nop

    func_80011C64(rdram, ctx);
        goto after_46;
    // 0x80010E5C: nop

    after_46:
    // 0x80010E60: jal         0x80010A30
    // 0x80010E64: nop

    func_80010A30(rdram, ctx);
        goto after_47;
    // 0x80010E64: nop

    after_47:
    // 0x80010E68: addiu       $a0, $zero, 0xD8
    ctx->r4 = ADD32(0, 0XD8);
    // 0x80010E6C: jal         0x80011D1C
    // 0x80010E70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_48;
    // 0x80010E70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_48:
    // 0x80010E74: b           L_80011354
    // 0x80010E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010E7C:
    // 0x80010E7C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80010E80: lbu         $t6, -0x6D7C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6D7C);
    // 0x80010E84: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80010E88: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010E8C: beq         $t6, $zero, L_80010E9C
    if (ctx->r14 == 0) {
        // 0x80010E90: sb          $t5, -0x6D78($at)
        MEM_B(-0X6D78, ctx->r1) = ctx->r13;
            goto L_80010E9C;
    }
    // 0x80010E90: sb          $t5, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r13;
    // 0x80010E94: jal         0x80010A74
    // 0x80010E98: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_80010A74(rdram, ctx);
        goto after_49;
    // 0x80010E98: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_49:
L_80010E9C:
    // 0x80010E9C: jal         0x8001168C
    // 0x80010EA0: nop

    func_8001168C(rdram, ctx);
        goto after_50;
    // 0x80010EA0: nop

    after_50:
    // 0x80010EA4: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80010EA8: jal         0x80011600
    // 0x80010EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_51;
    // 0x80010EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_51:
    // 0x80010EB0: jal         0x80011C64
    // 0x80010EB4: nop

    func_80011C64(rdram, ctx);
        goto after_52;
    // 0x80010EB4: nop

    after_52:
    // 0x80010EB8: jal         0x80010A30
    // 0x80010EBC: nop

    func_80010A30(rdram, ctx);
        goto after_53;
    // 0x80010EBC: nop

    after_53:
    // 0x80010EC0: addiu       $a0, $zero, 0xDA
    ctx->r4 = ADD32(0, 0XDA);
    // 0x80010EC4: jal         0x80011D1C
    // 0x80010EC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_54;
    // 0x80010EC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_54:
    // 0x80010ECC: b           L_80011354
    // 0x80010ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010ED4:
    // 0x80010ED4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80010ED8: lbu         $t7, -0x6D7C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6D7C);
    // 0x80010EDC: beql        $t7, $zero, L_80010EF0
    if (ctx->r15 == 0) {
        // 0x80010EE0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80010EF0;
    }
    goto skip_1;
    // 0x80010EE0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_1:
    // 0x80010EE4: jal         0x80010A74
    // 0x80010EE8: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_80010A74(rdram, ctx);
        goto after_55;
    // 0x80010EE8: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_55:
    // 0x80010EEC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80010EF0:
    // 0x80010EF0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010EF4: sb          $t8, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r24;
    // 0x80010EF8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010EFC: jal         0x8001168C
    // 0x80010F00: sh          $zero, -0x6D74($at)
    MEM_H(-0X6D74, ctx->r1) = 0;
    func_8001168C(rdram, ctx);
        goto after_56;
    // 0x80010F00: sh          $zero, -0x6D74($at)
    MEM_H(-0X6D74, ctx->r1) = 0;
    after_56:
    // 0x80010F04: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x80010F08: jal         0x80011600
    // 0x80010F0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_57;
    // 0x80010F0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_57:
    // 0x80010F10: jal         0x80011C64
    // 0x80010F14: nop

    func_80011C64(rdram, ctx);
        goto after_58;
    // 0x80010F14: nop

    after_58:
    // 0x80010F18: jal         0x80010A30
    // 0x80010F1C: nop

    func_80010A30(rdram, ctx);
        goto after_59;
    // 0x80010F1C: nop

    after_59:
    // 0x80010F20: addiu       $a0, $zero, 0xDA
    ctx->r4 = ADD32(0, 0XDA);
    // 0x80010F24: jal         0x80011D1C
    // 0x80010F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_60;
    // 0x80010F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_60:
    // 0x80010F2C: b           L_80011354
    // 0x80010F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010F34:
    // 0x80010F34: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80010F38: lbu         $t0, -0x6D7C($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X6D7C);
    // 0x80010F3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80010F40: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010F44: beq         $t0, $zero, L_80010F54
    if (ctx->r8 == 0) {
        // 0x80010F48: sb          $t9, -0x6D78($at)
        MEM_B(-0X6D78, ctx->r1) = ctx->r25;
            goto L_80010F54;
    }
    // 0x80010F48: sb          $t9, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r25;
    // 0x80010F4C: jal         0x80010A74
    // 0x80010F50: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_80010A74(rdram, ctx);
        goto after_61;
    // 0x80010F50: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_61:
L_80010F54:
    // 0x80010F54: jal         0x8001168C
    // 0x80010F58: nop

    func_8001168C(rdram, ctx);
        goto after_62;
    // 0x80010F58: nop

    after_62:
    // 0x80010F5C: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80010F60: jal         0x80011600
    // 0x80010F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_63;
    // 0x80010F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_63:
    // 0x80010F68: jal         0x80011C64
    // 0x80010F6C: nop

    func_80011C64(rdram, ctx);
        goto after_64;
    // 0x80010F6C: nop

    after_64:
    // 0x80010F70: jal         0x80010A30
    // 0x80010F74: nop

    func_80010A30(rdram, ctx);
        goto after_65;
    // 0x80010F74: nop

    after_65:
    // 0x80010F78: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    // 0x80010F7C: jal         0x80011D1C
    // 0x80010F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_66;
    // 0x80010F80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_66:
    // 0x80010F84: b           L_80011354
    // 0x80010F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010F8C:
    // 0x80010F8C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80010F90: lbu         $t1, -0x6D7C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X6D7C);
    // 0x80010F94: beql        $t1, $zero, L_80010FA8
    if (ctx->r9 == 0) {
        // 0x80010F98: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80010FA8;
    }
    goto skip_2;
    // 0x80010F98: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_2:
    // 0x80010F9C: jal         0x80010A74
    // 0x80010FA0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_80010A74(rdram, ctx);
        goto after_67;
    // 0x80010FA0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_67:
    // 0x80010FA4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80010FA8:
    // 0x80010FA8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010FAC: sb          $t2, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r10;
    // 0x80010FB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80010FB4: jal         0x8001168C
    // 0x80010FB8: sh          $zero, -0x6D74($at)
    MEM_H(-0X6D74, ctx->r1) = 0;
    func_8001168C(rdram, ctx);
        goto after_68;
    // 0x80010FB8: sh          $zero, -0x6D74($at)
    MEM_H(-0X6D74, ctx->r1) = 0;
    after_68:
    // 0x80010FBC: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x80010FC0: jal         0x80011600
    // 0x80010FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_69;
    // 0x80010FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_69:
    // 0x80010FC8: jal         0x80011C64
    // 0x80010FCC: nop

    func_80011C64(rdram, ctx);
        goto after_70;
    // 0x80010FCC: nop

    after_70:
    // 0x80010FD0: jal         0x80010A30
    // 0x80010FD4: nop

    func_80010A30(rdram, ctx);
        goto after_71;
    // 0x80010FD4: nop

    after_71:
    // 0x80010FD8: addiu       $a0, $zero, 0xCB
    ctx->r4 = ADD32(0, 0XCB);
    // 0x80010FDC: jal         0x80011D1C
    // 0x80010FE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_72;
    // 0x80010FE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_72:
    // 0x80010FE4: b           L_80011354
    // 0x80010FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80010FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80010FEC:
    // 0x80010FEC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80010FF0: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80010FF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80010FF8: beq         $v0, $zero, L_80011004
    if (ctx->r2 == 0) {
        // 0x80010FFC: nop
    
            goto L_80011004;
    }
    // 0x80010FFC: nop

    // 0x80011000: sw          $t3, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r11;
L_80011004:
    // 0x80011004: jal         0x8001137C
    // 0x80011008: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_8001137C(rdram, ctx);
        goto after_73;
    // 0x80011008: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_73:
    // 0x8001100C: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x80011010: jal         0x80011434
    // 0x80011014: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011434(rdram, ctx);
        goto after_74;
    // 0x80011014: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_74:
    // 0x80011018: b           L_80011354
    // 0x8001101C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x8001101C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011020:
    // 0x80011020: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80011024: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80011028: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8001102C: beq         $v0, $zero, L_80011038
    if (ctx->r2 == 0) {
        // 0x80011030: nop
    
            goto L_80011038;
    }
    // 0x80011030: nop

    // 0x80011034: sw          $t4, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r12;
L_80011038:
    // 0x80011038: jal         0x8001137C
    // 0x8001103C: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_8001137C(rdram, ctx);
        goto after_75;
    // 0x8001103C: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_75:
    // 0x80011040: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x80011044: jal         0x80011434
    // 0x80011048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011434(rdram, ctx);
        goto after_76;
    // 0x80011048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_76:
    // 0x8001104C: b           L_80011354
    // 0x80011050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80011050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011054:
    // 0x80011054: jal         0x80011484
    // 0x80011058: nop

    func_80011484(rdram, ctx);
        goto after_77;
    // 0x80011058: nop

    after_77:
    // 0x8001105C: b           L_80011354
    // 0x80011060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80011060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011064:
    // 0x80011064: jal         0x800114E8
    // 0x80011068: nop

    func_800114E8(rdram, ctx);
        goto after_78;
    // 0x80011068: nop

    after_78:
    // 0x8001106C: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    // 0x80011070: jal         0x80011D1C
    // 0x80011074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_79;
    // 0x80011074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_79:
    // 0x80011078: b           L_80011354
    // 0x8001107C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x8001107C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011080:
    // 0x80011080: jal         0x800114E8
    // 0x80011084: nop

    func_800114E8(rdram, ctx);
        goto after_80;
    // 0x80011084: nop

    after_80:
    // 0x80011088: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001108C: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80011090: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80011094: beq         $v0, $zero, L_800110A0
    if (ctx->r2 == 0) {
        // 0x80011098: nop
    
            goto L_800110A0;
    }
    // 0x80011098: nop

    // 0x8001109C: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
L_800110A0:
    // 0x800110A0: jal         0x80011434
    // 0x800110A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011434(rdram, ctx);
        goto after_81;
    // 0x800110A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_81:
    // 0x800110A8: b           L_80011354
    // 0x800110AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x800110AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800110B0:
    // 0x800110B0: jal         0x800114E8
    // 0x800110B4: nop

    func_800114E8(rdram, ctx);
        goto after_82;
    // 0x800110B4: nop

    after_82:
    // 0x800110B8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800110BC: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x800110C0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800110C4: beq         $v0, $zero, L_800110D0
    if (ctx->r2 == 0) {
        // 0x800110C8: nop
    
            goto L_800110D0;
    }
    // 0x800110C8: nop

    // 0x800110CC: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
L_800110D0:
    // 0x800110D0: jal         0x80011434
    // 0x800110D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011434(rdram, ctx);
        goto after_83;
    // 0x800110D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_83:
    // 0x800110D8: b           L_80011354
    // 0x800110DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x800110DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800110E0:
    // 0x800110E0: jal         0x800114E8
    // 0x800110E4: nop

    func_800114E8(rdram, ctx);
        goto after_84;
    // 0x800110E4: nop

    after_84:
    // 0x800110E8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800110EC: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x800110F0: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x800110F4: beq         $v0, $zero, L_80011100
    if (ctx->r2 == 0) {
        // 0x800110F8: nop
    
            goto L_80011100;
    }
    // 0x800110F8: nop

    // 0x800110FC: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
L_80011100:
    // 0x80011100: jal         0x80011434
    // 0x80011104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011434(rdram, ctx);
        goto after_85;
    // 0x80011104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_85:
    // 0x80011108: b           L_80011354
    // 0x8001110C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x8001110C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011110:
    // 0x80011110: jal         0x800114E8
    // 0x80011114: nop

    func_800114E8(rdram, ctx);
        goto after_86;
    // 0x80011114: nop

    after_86:
    // 0x80011118: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001111C: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80011120: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x80011124: beq         $v0, $zero, L_80011130
    if (ctx->r2 == 0) {
        // 0x80011128: nop
    
            goto L_80011130;
    }
    // 0x80011128: nop

    // 0x8001112C: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
L_80011130:
    // 0x80011130: jal         0x80011434
    // 0x80011134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011434(rdram, ctx);
        goto after_87;
    // 0x80011134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_87:
    // 0x80011138: b           L_80011354
    // 0x8001113C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x8001113C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011140:
    // 0x80011140: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80011144: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80011148: jal         0x80011540
    // 0x8001114C: sb          $t5, -0x6D7C($at)
    MEM_B(-0X6D7C, ctx->r1) = ctx->r13;
    func_80011540(rdram, ctx);
        goto after_88;
    // 0x8001114C: sb          $t5, -0x6D7C($at)
    MEM_B(-0X6D7C, ctx->r1) = ctx->r13;
    after_88:
    // 0x80011150: b           L_80011354
    // 0x80011154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80011154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011158:
    // 0x80011158: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001115C: jal         0x80011540
    // 0x80011160: sb          $zero, -0x6D7C($at)
    MEM_B(-0X6D7C, ctx->r1) = 0;
    func_80011540(rdram, ctx);
        goto after_89;
    // 0x80011160: sb          $zero, -0x6D7C($at)
    MEM_B(-0X6D7C, ctx->r1) = 0;
    after_89:
    // 0x80011164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011168: jal         0x80018CB0
    // 0x8001116C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80018CB0(rdram, ctx);
        goto after_90;
    // 0x8001116C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_90:
    // 0x80011170: b           L_80011354
    // 0x80011174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80011174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011178:
    // 0x80011178: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001117C: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80011180: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80011184: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x80011188: beq         $v0, $zero, L_80011194
    if (ctx->r2 == 0) {
        // 0x8001118C: nop
    
            goto L_80011194;
    }
    // 0x8001118C: nop

    // 0x80011190: sw          $t6, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r14;
L_80011194:
    // 0x80011194: jal         0x80011434
    // 0x80011198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011434(rdram, ctx);
        goto after_91;
    // 0x80011198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_91:
    // 0x8001119C: b           L_80011354
    // 0x800111A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x800111A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800111A4:
    // 0x800111A4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800111A8: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x800111AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800111B0: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x800111B4: beq         $v0, $zero, L_800111C0
    if (ctx->r2 == 0) {
        // 0x800111B8: nop
    
            goto L_800111C0;
    }
    // 0x800111B8: nop

    // 0x800111BC: sw          $t7, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r15;
L_800111C0:
    // 0x800111C0: jal         0x80011434
    // 0x800111C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011434(rdram, ctx);
        goto after_92;
    // 0x800111C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_92:
    // 0x800111C8: b           L_80011354
    // 0x800111CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x800111CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800111D0:
    // 0x800111D0: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    // 0x800111D4: jal         0x80011D1C
    // 0x800111D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011D1C(rdram, ctx);
        goto after_93;
    // 0x800111D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_93:
    // 0x800111DC: b           L_80011354
    // 0x800111E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x800111E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800111E4:
    // 0x800111E4: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x800111E8: jal         0x80011600
    // 0x800111EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_94;
    // 0x800111EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_94:
    // 0x800111F0: b           L_80011354
    // 0x800111F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x800111F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800111F8:
    // 0x800111F8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800111FC: jal         0x80011600
    // 0x80011200: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_80011600(rdram, ctx);
        goto after_95;
    // 0x80011200: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_95:
    // 0x80011204: b           L_80011354
    // 0x80011208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80011208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001120C:
    // 0x8001120C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80011210: jal         0x80011600
    // 0x80011214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_96;
    // 0x80011214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_96:
    // 0x80011218: jal         0x80011C64
    // 0x8001121C: nop

    func_80011C64(rdram, ctx);
        goto after_97;
    // 0x8001121C: nop

    after_97:
    // 0x80011220: b           L_80011354
    // 0x80011224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80011224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011228:
    // 0x80011228: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8001122C: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80011230: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80011234: beq         $v0, $zero, L_80011240
    if (ctx->r2 == 0) {
        // 0x80011238: nop
    
            goto L_80011240;
    }
    // 0x80011238: nop

    // 0x8001123C: sw          $t8, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r24;
L_80011240:
    // 0x80011240: jal         0x8001137C
    // 0x80011244: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_8001137C(rdram, ctx);
        goto after_98;
    // 0x80011244: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_98:
    // 0x80011248: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x8001124C: jal         0x80011434
    // 0x80011250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011434(rdram, ctx);
        goto after_99;
    // 0x80011250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_99:
    // 0x80011254: b           L_80011354
    // 0x80011258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80011258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001125C:
    // 0x8001125C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80011260: jal         0x80011600
    // 0x80011264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_100;
    // 0x80011264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_100:
    // 0x80011268: b           L_80011354
    // 0x8001126C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x8001126C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011270:
    // 0x80011270: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x80011274: jal         0x80011600
    // 0x80011278: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_80011600(rdram, ctx);
        goto after_101;
    // 0x80011278: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_101:
    // 0x8001127C: b           L_80011354
    // 0x80011280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80011280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011284:
    // 0x80011284: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80011288: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8001128C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80011290: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80011294: jal         0x8001ADC4
    // 0x80011298: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001ADC4(rdram, ctx);
        goto after_102;
    // 0x80011298: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_102:
    // 0x8001129C: jal         0x80011C64
    // 0x800112A0: nop

    func_80011C64(rdram, ctx);
        goto after_103;
    // 0x800112A0: nop

    after_103:
    // 0x800112A4: b           L_80011354
    // 0x800112A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x800112A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800112AC:
    // 0x800112AC: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x800112B0: jal         0x80011600
    // 0x800112B4: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_80011600(rdram, ctx);
        goto after_104;
    // 0x800112B4: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_104:
    // 0x800112B8: b           L_80011354
    // 0x800112BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x800112BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800112C0:
    // 0x800112C0: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x800112C4: jal         0x80011600
    // 0x800112C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80011600(rdram, ctx);
        goto after_105;
    // 0x800112C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_105:
    // 0x800112CC: jal         0x80011C64
    // 0x800112D0: nop

    func_80011C64(rdram, ctx);
        goto after_106;
    // 0x800112D0: nop

    after_106:
    // 0x800112D4: b           L_80011354
    // 0x800112D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x800112D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800112DC:
    // 0x800112DC: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x800112E0: jal         0x80011600
    // 0x800112E4: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_80011600(rdram, ctx);
        goto after_107;
    // 0x800112E4: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_107:
    // 0x800112E8: jal         0x80011C64
    // 0x800112EC: nop

    func_80011C64(rdram, ctx);
        goto after_108;
    // 0x800112EC: nop

    after_108:
    // 0x800112F0: b           L_80011354
    // 0x800112F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x800112F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800112F8:
    // 0x800112F8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800112FC: lw          $a0, -0x49C8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X49C8);
    // 0x80011300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011304: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80011308: bnel        $a0, $zero, L_80011324
    if (ctx->r4 != 0) {
        // 0x8001130C: lui         $a1, 0x3F80
        ctx->r5 = S32(0X3F80 << 16);
            goto L_80011324;
    }
    goto skip_3;
    // 0x8001130C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    skip_3:
    // 0x80011310: jal         0x80015E74
    // 0x80011314: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    func_80015E74(rdram, ctx);
        goto after_109;
    // 0x80011314: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_109:
    // 0x80011318: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001131C: lw          $a0, -0x49C8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X49C8);
    // 0x80011320: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
L_80011324:
    // 0x80011324: jal         0x8001BC68
    // 0x80011328: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    func_8001BC68(rdram, ctx);
        goto after_110;
    // 0x80011328: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_110:
    // 0x8001132C: b           L_80011354
    // 0x80011330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80011354;
    // 0x80011330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011334:
    // 0x80011334: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80011338: lw          $a0, -0x49C8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X49C8);
    // 0x8001133C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80011340: beql        $a0, $zero, L_80011354
    if (ctx->r4 == 0) {
        // 0x80011344: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80011354;
    }
    goto skip_4;
    // 0x80011344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80011348: jal         0x8001BC68
    // 0x8001134C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    func_8001BC68(rdram, ctx);
        goto after_111;
    // 0x8001134C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_111:
L_80011350:
    // 0x80011350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80011354:
    // 0x80011354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011358: jr          $ra
    // 0x8001135C: nop

    return;
    // 0x8001135C: nop

;}
RECOMP_FUNC void func_8001ADC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ADC4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8001ADC8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8001ADCC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001ADD0: beq         $a0, $zero, L_8001ADE0
    if (ctx->r4 == 0) {
        // 0x8001ADD4: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8001ADE0;
    }
    // 0x8001ADD4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8001ADD8: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
    // 0x8001ADDC: sh          $a2, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r6;
L_8001ADE0:
    // 0x8001ADE0: jr          $ra
    // 0x8001ADE4: nop

    return;
    // 0x8001ADE4: nop

;}
RECOMP_FUNC void func_8006C258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C258: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006C25C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8006C260: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006C264: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006C268: lw          $t6, -0x7D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D6C);
    // 0x8006C26C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006C270: lwc1        $f6, 0x1074($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1074);
    // 0x8006C274: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006C278: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8006C27C: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x8006C280: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8006C284: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8006C288: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006C28C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006C290: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8006C294: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x8006C298: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006C29C: addiu       $a0, $a0, 0x630
    ctx->r4 = ADD32(ctx->r4, 0X630);
    // 0x8006C2A0: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8006C2A4: addiu       $a1, $sp, 0x36
    ctx->r5 = ADD32(ctx->r29, 0X36);
    // 0x8006C2A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006C2AC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8006C2B0: jal         0x80086600
    // 0x8006C2B4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspective(rdram, ctx);
        goto after_0;
    // 0x8006C2B4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8006C2B8: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8006C2BC: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8006C2C0: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8006C2C4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8006C2C8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8006C2CC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8006C2D0: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8006C2D4: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8006C2D8: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8006C2DC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006C2E0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8006C2E4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006C2E8: addiu       $a0, $a0, 0x670
    ctx->r4 = ADD32(ctx->r4, 0X670);
    // 0x8006C2EC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8006C2F0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8006C2F4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8006C2F8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8006C2FC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8006C300: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8006C304: jal         0x80087338
    // 0x8006C308: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    guLookAt(rdram, ctx);
        goto after_1;
    // 0x8006C308: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8006C30C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006C310: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8006C314: addiu       $a1, $a1, 0x670
    ctx->r5 = ADD32(ctx->r5, 0X670);
    // 0x8006C318: jal         0x8007FD6C
    // 0x8006C31C: addiu       $a0, $a0, 0x630
    ctx->r4 = ADD32(ctx->r4, 0X630);
    func_8007FD6C(rdram, ctx);
        goto after_2;
    // 0x8006C31C: addiu       $a0, $a0, 0x630
    ctx->r4 = ADD32(ctx->r4, 0X630);
    after_2:
    // 0x8006C320: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8006C324: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8006C328: addiu       $v0, $v0, -0x7AF0
    ctx->r2 = ADD32(ctx->r2, -0X7AF0);
    // 0x8006C32C: addiu       $t8, $t8, 0x630
    ctx->r24 = ADD32(ctx->r24, 0X630);
    // 0x8006C330: addiu       $t1, $t8, 0x3C
    ctx->r9 = ADD32(ctx->r24, 0X3C);
    // 0x8006C334: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_8006C338:
    // 0x8006C338: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8006C33C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8006C340: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8006C344: sw          $t0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r8;
    // 0x8006C348: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x8006C34C: sw          $t9, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r25;
    // 0x8006C350: lw          $t0, -0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, -0X4);
    // 0x8006C354: bne         $t8, $t1, L_8006C338
    if (ctx->r24 != ctx->r9) {
        // 0x8006C358: sw          $t0, 0x1C($t7)
        MEM_W(0X1C, ctx->r15) = ctx->r8;
            goto L_8006C338;
    }
    // 0x8006C358: sw          $t0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r8;
    // 0x8006C35C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8006C360: sw          $t0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r8;
    // 0x8006C364: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8006C368: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x8006C36C: sh          $t2, 0x60($t3)
    MEM_H(0X60, ctx->r11) = ctx->r10;
    // 0x8006C370: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006C374: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8006C378: jr          $ra
    // 0x8006C37C: nop

    return;
    // 0x8006C37C: nop

;}
RECOMP_FUNC void func_8073F2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F2FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073F300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073F304: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x8073F308: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8073F30C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073F310: beq         $v1, $zero, L_8073F328
    if (ctx->r3 == 0) {
        // 0x8073F314: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8073F328;
    }
    // 0x8073F314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8073F318: beql        $v1, $a0, L_8073F368
    if (ctx->r3 == ctx->r4) {
        // 0x8073F31C: lw          $t8, 0x18($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X18);
            goto L_8073F368;
    }
    goto skip_0;
    // 0x8073F31C: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    skip_0:
    // 0x8073F320: b           L_8073F398
    // 0x8073F324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8073F398;
    // 0x8073F324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8073F328:
    // 0x8073F328: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8073F32C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8073F330: bnel        $a0, $t6, L_8073F398
    if (ctx->r4 != ctx->r14) {
        // 0x8073F334: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073F398;
    }
    goto skip_1;
    // 0x8073F334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8073F338: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x8073F33C: bnel        $t7, $zero, L_8073F398
    if (ctx->r15 != 0) {
        // 0x8073F340: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073F398;
    }
    goto skip_2;
    // 0x8073F340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8073F344: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8073F348: jal         0x80067BBC
    // 0x8073F34C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8073F34C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_0:
    // 0x8073F350: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    // 0x8073F354: jal         0x80067818
    // 0x8073F358: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8073F358: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8073F35C: b           L_8073F398
    // 0x8073F360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8073F398;
    // 0x8073F360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073F364: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
L_8073F368:
    // 0x8073F368: bnel        $a0, $t8, L_8073F398
    if (ctx->r4 != ctx->r24) {
        // 0x8073F36C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073F398;
    }
    goto skip_3;
    // 0x8073F36C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8073F370: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x8073F374: bnel        $t9, $zero, L_8073F398
    if (ctx->r25 != 0) {
        // 0x8073F378: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8073F398;
    }
    goto skip_4;
    // 0x8073F378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8073F37C: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8073F380: jal         0x80067BBC
    // 0x8073F384: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8073F384: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_2:
    // 0x8073F388: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    // 0x8073F38C: jal         0x80067818
    // 0x8073F390: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8073F390: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8073F394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8073F398:
    // 0x8073F398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073F39C: jr          $ra
    // 0x8073F3A0: nop

    return;
    // 0x8073F3A0: nop

;}
RECOMP_FUNC void func_8002CF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CF94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002CF98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002CF9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002CFA0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002CFA4: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8002CFA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002CFAC: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8002CFB0: beql        $v1, $zero, L_8002CFF0
    if (ctx->r3 == 0) {
        // 0x8002CFB4: lw          $v1, 0x180($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X180);
            goto L_8002CFF0;
    }
    goto skip_0;
    // 0x8002CFB4: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x8002CFB8: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8002CFBC: bnel        $v1, $t6, L_8002CFF0
    if (ctx->r3 != ctx->r14) {
        // 0x8002CFC0: lw          $v1, 0x180($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X180);
            goto L_8002CFF0;
    }
    goto skip_1;
    // 0x8002CFC0: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
    skip_1:
    // 0x8002CFC4: jal         0x80061170
    // 0x8002CFC8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80061170(rdram, ctx);
        goto after_0;
    // 0x8002CFC8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002CFCC: jal         0x8005FE48
    // 0x8002CFD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x8002CFD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002CFD4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8002CFD8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8002CFDC: sh          $zero, 0x10($t7)
    MEM_H(0X10, ctx->r15) = 0;
    // 0x8002CFE0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002CFE4: b           L_8002D06C
    // 0x8002CFE8: sh          $zero, 0x14($t8)
    MEM_H(0X14, ctx->r24) = 0;
        goto L_8002D06C;
    // 0x8002CFE8: sh          $zero, 0x14($t8)
    MEM_H(0X14, ctx->r24) = 0;
    // 0x8002CFEC: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
L_8002CFF0:
    // 0x8002CFF0: beql        $v1, $zero, L_8002D038
    if (ctx->r3 == 0) {
        // 0x8002CFF4: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_8002D038;
    }
    goto skip_2;
    // 0x8002CFF4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x8002CFF8: lhu         $t9, 0xC($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XC);
    // 0x8002CFFC: addiu       $at, $zero, 0x400B
    ctx->r1 = ADD32(0, 0X400B);
    // 0x8002D000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002D004: beql        $t9, $at, L_8002D038
    if (ctx->r25 == ctx->r1) {
        // 0x8002D008: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_8002D038;
    }
    goto skip_3;
    // 0x8002D008: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    skip_3:
    // 0x8002D00C: jal         0x8004816C
    // 0x8002D010: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8004816C(rdram, ctx);
        goto after_2;
    // 0x8002D010: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x8002D014: jal         0x8005FE48
    // 0x8002D018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x8002D018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8002D01C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8002D020: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8002D024: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
    // 0x8002D028: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8002D02C: b           L_8002D06C
    // 0x8002D030: sh          $zero, 0x14($t1)
    MEM_H(0X14, ctx->r9) = 0;
        goto L_8002D06C;
    // 0x8002D030: sh          $zero, 0x14($t1)
    MEM_H(0X14, ctx->r9) = 0;
    // 0x8002D034: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_8002D038:
    // 0x8002D038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002D03C: lbu         $t2, 0x76($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X76);
    // 0x8002D040: beql        $t2, $zero, L_8002D05C
    if (ctx->r10 == 0) {
        // 0x8002D044: lbu         $t3, 0x79($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X79);
            goto L_8002D05C;
    }
    goto skip_4;
    // 0x8002D044: lbu         $t3, 0x79($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X79);
    skip_4:
    // 0x8002D048: jal         0x8005FA94
    // 0x8002D04C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8005FA94(rdram, ctx);
        goto after_4;
    // 0x8002D04C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_4:
    // 0x8002D050: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8002D054: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8002D058: lbu         $t3, 0x79($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X79);
L_8002D05C:
    // 0x8002D05C: beql        $t3, $zero, L_8002D070
    if (ctx->r11 == 0) {
        // 0x8002D060: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002D070;
    }
    goto skip_5;
    // 0x8002D060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x8002D064: jal         0x8005FBC0
    // 0x8002D068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FBC0(rdram, ctx);
        goto after_5;
    // 0x8002D068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8002D06C:
    // 0x8002D06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002D070:
    // 0x8002D070: jal         0x8002AFDC
    // 0x8002D074: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8002AFDC(rdram, ctx);
        goto after_6;
    // 0x8002D074: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x8002D078: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x8002D07C: lw          $t4, -0x76F8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X76F8);
    // 0x8002D080: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002D088: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8002D08C: lw          $v0, 0x78($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X78);
    // 0x8002D090: beql        $v0, $zero, L_8002D0A4
    if (ctx->r2 == 0) {
        // 0x8002D094: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002D0A4;
    }
    goto skip_6;
    // 0x8002D094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8002D098: jalr        $v0
    // 0x8002D09C: lw          $a0, 0x108($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X108);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_7;
    // 0x8002D09C: lw          $a0, 0x108($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X108);
    after_7:
    // 0x8002D0A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002D0A4:
    // 0x8002D0A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D0A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002D0AC: jr          $ra
    // 0x8002D0B0: nop

    return;
    // 0x8002D0B0: nop

;}
RECOMP_FUNC void func_806F1BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1BF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F1BF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F1BFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F1C00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F1C04: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806F1C08: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806F1C0C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806F1C10: bne         $v0, $at, L_806F1D10
    if (ctx->r2 != ctx->r1) {
        // 0x806F1C14: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_806F1D10;
    }
    // 0x806F1C14: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x806F1C18: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806F1C1C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806F1C20: jal         0x80062AEC
    // 0x806F1C24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x806F1C24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x806F1C28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806F1C2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806F1C30: beq         $v0, $at, L_806F1C4C
    if (ctx->r2 == ctx->r1) {
        // 0x806F1C34: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_806F1C4C;
    }
    // 0x806F1C34: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x806F1C38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806F1C3C: beq         $v0, $at, L_806F1CB0
    if (ctx->r2 == ctx->r1) {
        // 0x806F1C40: nop
    
            goto L_806F1CB0;
    }
    // 0x806F1C40: nop

    // 0x806F1C44: b           L_806F1D14
    // 0x806F1C48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F1D14;
    // 0x806F1C48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F1C4C:
    // 0x806F1C4C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(679, 0X1BD8) << 16);
    // 0x806F1C50: lwc1        $f4, 0x3158($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(679, 0X1BD8));
    // 0x806F1C54: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806F1C58: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806F1C5C: nop

    // 0x806F1C60: bc1fl       L_806F1C9C
    if (!c1cs) {
        // 0x806F1C64: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806F1C9C;
    }
    goto skip_0;
    // 0x806F1C64: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x806F1C68: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806F1C6C: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806F1C70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F1C74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806F1C78: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806F1C7C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x806F1C80: nop

    // 0x806F1C84: bc1fl       L_806F1C9C
    if (!c1cs) {
        // 0x806F1C88: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806F1C9C;
    }
    goto skip_1;
    // 0x806F1C88: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_1:
    // 0x806F1C8C: lwc1        $f18, 0x3C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806F1C90: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x806F1C94: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x806F1C98: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_806F1C9C:
    // 0x806F1C9C: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x806F1CA0: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x806F1CA4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x806F1CA8: b           L_806F1D10
    // 0x806F1CAC: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
        goto L_806F1D10;
    // 0x806F1CAC: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
L_806F1CB0:
    // 0x806F1CB0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(679, 0X1BDC) << 16);
    // 0x806F1CB4: lwc1        $f8, 0x315C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(679, 0X1BDC));
    // 0x806F1CB8: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806F1CBC: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806F1CC0: nop

    // 0x806F1CC4: bc1fl       L_806F1D00
    if (!c1cs) {
        // 0x806F1CC8: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806F1D00;
    }
    goto skip_2;
    // 0x806F1CC8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_2:
    // 0x806F1CCC: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806F1CD0: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806F1CD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F1CD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806F1CDC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806F1CE0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x806F1CE4: nop

    // 0x806F1CE8: bc1fl       L_806F1D00
    if (!c1cs) {
        // 0x806F1CEC: lw          $v0, 0x1F4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F4);
            goto L_806F1D00;
    }
    goto skip_3;
    // 0x806F1CEC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    skip_3:
    // 0x806F1CF0: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806F1CF4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x806F1CF8: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x806F1CFC: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_806F1D00:
    // 0x806F1D00: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x806F1D04: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x806F1D08: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x806F1D0C: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_806F1D10:
    // 0x806F1D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F1D14:
    // 0x806F1D14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F1D18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F1D1C: jr          $ra
    // 0x806F1D20: nop

    return;
    // 0x806F1D20: nop

;}
RECOMP_FUNC void func_800067EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800067EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800067F0: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x800067F4: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
    // 0x800067F8: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800067FC: blez        $v1, L_80006844
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80006800: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80006844;
    }
    // 0x80006800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80006804: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80006808: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8000680C:
    // 0x8000680C: lw          $t6, 0x14($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X14);
    // 0x80006810: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006814: beql        $t6, $zero, L_8000683C
    if (ctx->r14 == 0) {
        // 0x80006818: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8000683C;
    }
    goto skip_0;
    // 0x80006818: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
    // 0x8000681C: lb          $t7, 0x18($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X18);
    // 0x80006820: bnel        $a3, $t7, L_8000683C
    if (ctx->r7 != ctx->r15) {
        // 0x80006824: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8000683C;
    }
    goto skip_1;
    // 0x80006824: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
    // 0x80006828: lw          $t8, 0x10($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X10);
    // 0x8000682C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80006830: sw          $t9, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r25;
    // 0x80006834: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x80006838: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8000683C:
    // 0x8000683C: bne         $at, $zero, L_8000680C
    if (ctx->r1 != 0) {
        // 0x80006840: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_8000680C;
    }
    // 0x80006840: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_80006844:
    // 0x80006844: jr          $ra
    // 0x80006848: nop

    return;
    // 0x80006848: nop

;}
RECOMP_FUNC void func_8002ED94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ED94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002ED98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002ED9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002EDA0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8002EDA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002EDA8: sw          $zero, 0x40($a1)
    MEM_W(0X40, ctx->r5) = 0;
    // 0x8002EDAC: sb          $v0, 0x154($a1)
    MEM_B(0X154, ctx->r5) = ctx->r2;
    // 0x8002EDB0: sb          $zero, 0x159($a1)
    MEM_B(0X159, ctx->r5) = 0;
    // 0x8002EDB4: sb          $v0, 0x156($a1)
    MEM_B(0X156, ctx->r5) = ctx->r2;
    // 0x8002EDB8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002EDBC: lwc1        $f0, -0x7670($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7670);
    // 0x8002EDC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002EDC4: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8002EDC8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002EDCC: nop

    // 0x8002EDD0: bc1fl       L_8002EDE4
    if (!c1cs) {
        // 0x8002EDD4: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_8002EDE4;
    }
    goto skip_0;
    // 0x8002EDD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_0:
    // 0x8002EDD8: b           L_8002EE08
    // 0x8002EDDC: swc1        $f2, 0x174($a1)
    MEM_W(0X174, ctx->r5) = ctx->f2.u32l;
        goto L_8002EE08;
    // 0x8002EDDC: swc1        $f2, 0x174($a1)
    MEM_W(0X174, ctx->r5) = ctx->f2.u32l;
    // 0x8002EDE0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_8002EDE4:
    // 0x8002EDE4: nop

    // 0x8002EDE8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8002EDEC: nop

    // 0x8002EDF0: bc1fl       L_8002EE04
    if (!c1cs) {
        // 0x8002EDF4: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8002EE04;
    }
    goto skip_1;
    // 0x8002EDF4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x8002EDF8: b           L_8002EE04
    // 0x8002EDFC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8002EE04;
    // 0x8002EDFC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8002EE00: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8002EE04:
    // 0x8002EE04: swc1        $f2, 0x174($a1)
    MEM_W(0X174, ctx->r5) = ctx->f2.u32l;
L_8002EE08:
    // 0x8002EE08: lbu         $t6, 0x155($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X155);
    // 0x8002EE0C: sb          $zero, 0x1AD($a1)
    MEM_B(0X1AD, ctx->r5) = 0;
    // 0x8002EE10: swc1        $f4, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f4.u32l;
    // 0x8002EE14: bne         $t6, $zero, L_8002EE2C
    if (ctx->r14 != 0) {
        // 0x8002EE18: sb          $zero, 0x21($a1)
        MEM_B(0X21, ctx->r5) = 0;
            goto L_8002EE2C;
    }
    // 0x8002EE18: sb          $zero, 0x21($a1)
    MEM_B(0X21, ctx->r5) = 0;
    // 0x8002EE1C: jal         0x8003D6E4
    // 0x8002EE20: nop

    func_8003D6E4(rdram, ctx);
        goto after_0;
    // 0x8002EE20: nop

    after_0:
    // 0x8002EE24: b           L_8002EE48
    // 0x8002EE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002EE48;
    // 0x8002EE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002EE2C:
    // 0x8002EE2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002EE30: jal         0x80032878
    // 0x8002EE34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80032878(rdram, ctx);
        goto after_1;
    // 0x8002EE34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8002EE38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002EE3C: jal         0x80032564
    // 0x8002EE40: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80032564(rdram, ctx);
        goto after_2;
    // 0x8002EE40: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8002EE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002EE48:
    // 0x8002EE48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002EE4C: jr          $ra
    // 0x8002EE50: nop

    return;
    // 0x8002EE50: nop

;}
RECOMP_FUNC void func_804CDD04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CDD04: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x804CDD08: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x804CDD0C: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x804CDD10: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x804CDD14: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x804CDD18: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x804CDD1C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x804CDD20: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x804CDD24: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804CDD28: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804CDD2C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804CDD30: lw          $s4, 0x1F4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CDD34: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x804CDD38: lw          $v1, 0xC($s4)
    ctx->r3 = MEM_W(ctx->r20, 0XC);
    // 0x804CDD3C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x804CDD40: lw          $a2, 0x10($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X10);
    // 0x804CDD44: addiu       $a3, $v1, -0x1
    ctx->r7 = ADD32(ctx->r3, -0X1);
    // 0x804CDD48: multu       $a3, $t0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804CDD4C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x804CDD50: addiu       $s5, $a2, -0x1
    ctx->r21 = ADD32(ctx->r6, -0X1);
    // 0x804CDD54: mflo        $t6
    ctx->r14 = lo;
    // 0x804CDD58: addu        $s3, $v0, $t6
    ctx->r19 = ADD32(ctx->r2, ctx->r14);
    // 0x804CDD5C: beq         $a2, $zero, L_804CDEF0
    if (ctx->r6 == 0) {
        // 0x804CDD60: nop
    
            goto L_804CDEF0;
    }
    // 0x804CDD60: nop

    // 0x804CDD64: multu       $s5, $t0
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804CDD68: lw          $t8, 0x8($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X8);
    // 0x804CDD6C: sll         $s0, $s5, 2
    ctx->r16 = S32(ctx->r21 << 2);
    // 0x804CDD70: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x804CDD74: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x804CDD78: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x804CDD7C: mflo        $t7
    ctx->r15 = lo;
    // 0x804CDD80: addu        $s2, $v0, $t7
    ctx->r18 = ADD32(ctx->r2, ctx->r15);
    // 0x804CDD84: jal         0x804CDC4C
    // 0x804CDD88: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    func_804CDC4C(rdram, ctx);
        goto after_0;
    // 0x804CDD88: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_0:
    // 0x804CDD8C: beq         $s5, $zero, L_804CDE50
    if (ctx->r21 == 0) {
        // 0x804CDD90: lw          $v0, 0x58($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X58);
            goto L_804CDE50;
    }
    // 0x804CDD90: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x804CDD94: subu        $t1, $v0, $s5
    ctx->r9 = SUB32(ctx->r2, ctx->r21);
    // 0x804CDD98: beq         $t1, $zero, L_804CDE50
    if (ctx->r9 == 0) {
        // 0x804CDD9C: sw          $t1, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r9;
            goto L_804CDE50;
    }
    // 0x804CDD9C: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x804CDDA0: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x804CDDA4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x804CDDA8: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x804CDDAC: bgez        $s5, L_804CDDC4
    if (SIGNED(ctx->r21) >= 0) {
        // 0x804CDDB0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_804CDDC4;
    }
    // 0x804CDDB0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x804CDDB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x804CDDB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804CDDBC: nop

    // 0x804CDDC0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_804CDDC4:
    // 0x804CDDC4: div.s       $f24, $f0, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x804CDDC8: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x804CDDCC: beq         $s5, $zero, L_804CDDFC
    if (ctx->r21 == 0) {
        // 0x804CDDD0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_804CDDFC;
    }
    // 0x804CDDD0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_804CDDD4:
    // 0x804CDDD4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x804CDDD8: jal         0x804CDC4C
    // 0x804CDDDC: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    func_804CDC4C(rdram, ctx);
        goto after_1;
    // 0x804CDDDC: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_1:
    // 0x804CDDE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x804CDDE4: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x804CDDE8: bne         $s0, $s5, L_804CDDD4
    if (ctx->r16 != ctx->r21) {
        // 0x804CDDEC: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_804CDDD4;
    }
    // 0x804CDDEC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x804CDDF0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x804CDDF4: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x804CDDF8: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
L_804CDDFC:
    // 0x804CDDFC: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x804CDE00: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x804CDE04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x804CDE08: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x804CDE0C: bgez        $t3, L_804CDE20
    if (SIGNED(ctx->r11) >= 0) {
        // 0x804CDE10: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_804CDE20;
    }
    // 0x804CDE10: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x804CDE14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804CDE18: nop

    // 0x804CDE1C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_804CDE20:
    // 0x804CDE20: sltu        $at, $s5, $v0
    ctx->r1 = ctx->r21 < ctx->r2 ? 1 : 0;
    // 0x804CDE24: beq         $at, $zero, L_804CDF24
    if (ctx->r1 == 0) {
        // 0x804CDE28: div.s       $f24, $f0, $f16
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
            goto L_804CDF24;
    }
    // 0x804CDE28: div.s       $f24, $f0, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
L_804CDE2C:
    // 0x804CDE2C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x804CDE30: jal         0x804CDC4C
    // 0x804CDE34: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    func_804CDC4C(rdram, ctx);
        goto after_2;
    // 0x804CDE34: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_2:
    // 0x804CDE38: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x804CDE3C: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x804CDE40: bne         $s5, $s0, L_804CDE2C
    if (ctx->r21 != ctx->r16) {
        // 0x804CDE44: addiu       $s3, $s3, -0xC
        ctx->r19 = ADD32(ctx->r19, -0XC);
            goto L_804CDE2C;
    }
    // 0x804CDE44: addiu       $s3, $s3, -0xC
    ctx->r19 = ADD32(ctx->r19, -0XC);
    // 0x804CDE48: b           L_804CDF28
    // 0x804CDE4C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_804CDF28;
    // 0x804CDE4C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_804CDE50:
    // 0x804CDE50: bnel        $s0, $zero, L_804CDEA8
    if (ctx->r16 != 0) {
        // 0x804CDE54: lw          $t6, 0xC($s4)
        ctx->r14 = MEM_W(ctx->r20, 0XC);
            goto L_804CDEA8;
    }
    goto skip_0;
    // 0x804CDE54: lw          $t6, 0xC($s4)
    ctx->r14 = MEM_W(ctx->r20, 0XC);
    skip_0:
    // 0x804CDE58: lw          $t4, 0xC($s4)
    ctx->r12 = MEM_W(ctx->r20, 0XC);
    // 0x804CDE5C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x804CDE60: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x804CDE64: sltiu       $at, $t4, 0x2
    ctx->r1 = ctx->r12 < 0X2 ? 1 : 0;
    // 0x804CDE68: bnel        $at, $zero, L_804CDF28
    if (ctx->r1 != 0) {
        // 0x804CDE6C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_804CDF28;
    }
    goto skip_1;
    // 0x804CDE6C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x804CDE70: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x804CDE74: nop

    // 0x804CDE78: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
L_804CDE7C:
    // 0x804CDE7C: jal         0x804CDB58
    // 0x804CDE80: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    func_804CDB58(rdram, ctx);
        goto after_3;
    // 0x804CDE80: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_3:
    // 0x804CDE84: lw          $t5, 0xC($s4)
    ctx->r13 = MEM_W(ctx->r20, 0XC);
    // 0x804CDE88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x804CDE8C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x804CDE90: sltu        $at, $s0, $t5
    ctx->r1 = ctx->r16 < ctx->r13 ? 1 : 0;
    // 0x804CDE94: bnel        $at, $zero, L_804CDE7C
    if (ctx->r1 != 0) {
        // 0x804CDE98: mfc1        $a1, $f22
        ctx->r5 = (int32_t)ctx->f22.u32l;
            goto L_804CDE7C;
    }
    goto skip_2;
    // 0x804CDE98: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    skip_2:
    // 0x804CDE9C: b           L_804CDF28
    // 0x804CDEA0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_804CDF28;
    // 0x804CDEA0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x804CDEA4: lw          $t6, 0xC($s4)
    ctx->r14 = MEM_W(ctx->r20, 0XC);
L_804CDEA8:
    // 0x804CDEA8: addiu       $s2, $s2, -0xC
    ctx->r18 = ADD32(ctx->r18, -0XC);
    // 0x804CDEAC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x804CDEB0: sltiu       $at, $t6, 0x2
    ctx->r1 = ctx->r14 < 0X2 ? 1 : 0;
    // 0x804CDEB4: bnel        $at, $zero, L_804CDF28
    if (ctx->r1 != 0) {
        // 0x804CDEB8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_804CDF28;
    }
    goto skip_3;
    // 0x804CDEB8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x804CDEBC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x804CDEC0: nop

    // 0x804CDEC4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
L_804CDEC8:
    // 0x804CDEC8: jal         0x804CDB58
    // 0x804CDECC: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    func_804CDB58(rdram, ctx);
        goto after_4;
    // 0x804CDECC: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_4:
    // 0x804CDED0: lw          $t7, 0xC($s4)
    ctx->r15 = MEM_W(ctx->r20, 0XC);
    // 0x804CDED4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x804CDED8: addiu       $s2, $s2, -0xC
    ctx->r18 = ADD32(ctx->r18, -0XC);
    // 0x804CDEDC: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x804CDEE0: bnel        $at, $zero, L_804CDEC8
    if (ctx->r1 != 0) {
        // 0x804CDEE4: mfc1        $a1, $f22
        ctx->r5 = (int32_t)ctx->f22.u32l;
            goto L_804CDEC8;
    }
    goto skip_4;
    // 0x804CDEE4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    skip_4:
    // 0x804CDEE8: b           L_804CDF28
    // 0x804CDEEC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_804CDF28;
    // 0x804CDEEC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_804CDEF0:
    // 0x804CDEF0: beq         $v1, $zero, L_804CDF24
    if (ctx->r3 == 0) {
        // 0x804CDEF4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_804CDF24;
    }
    // 0x804CDEF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x804CDEF8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x804CDEFC: nop

    // 0x804CDF00: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
L_804CDF04:
    // 0x804CDF04: jal         0x804CDB58
    // 0x804CDF08: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    func_804CDB58(rdram, ctx);
        goto after_5;
    // 0x804CDF08: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_5:
    // 0x804CDF0C: lw          $t8, 0xC($s4)
    ctx->r24 = MEM_W(ctx->r20, 0XC);
    // 0x804CDF10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x804CDF14: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x804CDF18: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x804CDF1C: bnel        $at, $zero, L_804CDF04
    if (ctx->r1 != 0) {
        // 0x804CDF20: mfc1        $a1, $f22
        ctx->r5 = (int32_t)ctx->f22.u32l;
            goto L_804CDF04;
    }
    goto skip_5;
    // 0x804CDF20: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    skip_5:
L_804CDF24:
    // 0x804CDF24: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_804CDF28:
    // 0x804CDF28: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804CDF2C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804CDF30: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804CDF34: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x804CDF38: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x804CDF3C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x804CDF40: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x804CDF44: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x804CDF48: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x804CDF4C: jr          $ra
    // 0x804CDF50: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x804CDF50: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80031230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031230: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80031234: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80031238: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003123C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031240: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80031244: jal         0x800310A0
    // 0x80031248: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031248: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003124C: jal         0x80030D14
    // 0x80031250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80030D14(rdram, ctx);
        goto after_1;
    // 0x80031250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80031254: beq         $v0, $zero, L_8003127C
    if (ctx->r2 == 0) {
        // 0x80031258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003127C;
    }
    // 0x80031258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003125C: jal         0x800310D0
    // 0x80031260: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800310D0(rdram, ctx);
        goto after_2;
    // 0x80031260: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80031264: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80031268: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8003126C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031270: lw          $a2, 0x78($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X78);
    // 0x80031274: jal         0x80031170
    // 0x80031278: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80031170(rdram, ctx);
        goto after_3;
    // 0x80031278: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
L_8003127C:
    // 0x8003127C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80031280: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80031284: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80031288: jr          $ra
    // 0x8003128C: nop

    return;
    // 0x8003128C: nop

;}
RECOMP_FUNC void func_804464B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804464B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804464B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804464BC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804464C0: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x804464C4: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x804464C8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804464CC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x804464D0: sw          $a1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r5;
    // 0x804464D4: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x804464D8: sw          $t6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r14;
    // 0x804464DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804464E0: sw          $t7, 0x6CB0($at)
    MEM_W(0X6CB0, ctx->r1) = ctx->r15;
    // 0x804464E4: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X131E8) << 16);
    // 0x804464E8: lw          $v1, 0x75C8($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X131E8));
    // 0x804464EC: beql        $v1, $zero, L_80446500
    if (ctx->r3 == 0) {
        // 0x804464F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80446500;
    }
    goto skip_0;
    // 0x804464F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804464F4: jalr        $v1
    // 0x804464F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804464F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x804464FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80446500:
    // 0x80446500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80446504: jr          $ra
    // 0x80446508: nop

    return;
    // 0x80446508: nop

;}
RECOMP_FUNC void func_804E7BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E7BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E7BCC: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x804E7BD0: addiu       $at, $zero, 0x40EC
    ctx->r1 = ADD32(0, 0X40EC);
    // 0x804E7BD4: beql        $t6, $at, L_804E7C00
    if (ctx->r14 == ctx->r1) {
        // 0x804E7BD8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_804E7C00;
    }
    goto skip_0;
    // 0x804E7BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x804E7BDC: jal         0x80059278
    // 0x804E7BE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80059278(rdram, ctx);
        goto after_0;
    // 0x804E7BE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804E7BE4: bne         $v0, $zero, L_804E7BFC
    if (ctx->r2 != 0) {
        // 0x804E7BE8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804E7BFC;
    }
    // 0x804E7BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804E7BEC: jal         0x800447C8
    // 0x804E7BF0: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804E7BF0: nop

    after_1:
    // 0x804E7BF4: b           L_804E7C00
    // 0x804E7BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804E7C00;
    // 0x804E7BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804E7BFC:
    // 0x804E7BFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804E7C00:
    // 0x804E7C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E7C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E7C08: jr          $ra
    // 0x804E7C0C: nop

    return;
    // 0x804E7C0C: nop

;}
RECOMP_FUNC void func_80445D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445D30: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80445D34: lbu         $v0, -0x7204($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7204);
    // 0x80445D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445D40: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80445D44: bgtz        $v0, L_80445D64
    if (SIGNED(ctx->r2) > 0) {
        // 0x80445D48: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80445D64;
    }
    // 0x80445D48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80445D4C: jal         0x80445CBC
    // 0x80445D50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80445CBC(rdram, ctx);
        goto after_0;
    // 0x80445D50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80445D54: jal         0x80445CC4
    // 0x80445D58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_1;
    // 0x80445D58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80445D5C: b           L_80445DE4
    // 0x80445D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80445DE4;
    // 0x80445D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80445D64:
    // 0x80445D64: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80445D68: beql        $at, $zero, L_80445D8C
    if (ctx->r1 == 0) {
        // 0x80445D6C: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_80445D8C;
    }
    goto skip_0;
    // 0x80445D6C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    skip_0:
    // 0x80445D70: jal         0x80445CBC
    // 0x80445D74: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80445CBC(rdram, ctx);
        goto after_2;
    // 0x80445D74: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80445D78: jal         0x80445CC4
    // 0x80445D7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_3;
    // 0x80445D7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80445D80: b           L_80445DE4
    // 0x80445D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80445DE4;
    // 0x80445D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445D88: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_80445D8C:
    // 0x80445D8C: beql        $at, $zero, L_80445DB0
    if (ctx->r1 == 0) {
        // 0x80445D90: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_80445DB0;
    }
    goto skip_1;
    // 0x80445D90: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    skip_1:
    // 0x80445D94: jal         0x80445CBC
    // 0x80445D98: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80445CBC(rdram, ctx);
        goto after_4;
    // 0x80445D98: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x80445D9C: jal         0x80445CC4
    // 0x80445DA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_5;
    // 0x80445DA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80445DA4: b           L_80445DE4
    // 0x80445DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80445DE4;
    // 0x80445DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445DAC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
L_80445DB0:
    // 0x80445DB0: beq         $at, $zero, L_80445DD0
    if (ctx->r1 == 0) {
        // 0x80445DB4: nop
    
            goto L_80445DD0;
    }
    // 0x80445DB4: nop

    // 0x80445DB8: jal         0x80445CBC
    // 0x80445DBC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80445CBC(rdram, ctx);
        goto after_6;
    // 0x80445DBC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_6:
    // 0x80445DC0: jal         0x80445CC4
    // 0x80445DC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_7;
    // 0x80445DC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80445DC8: b           L_80445DE4
    // 0x80445DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80445DE4;
    // 0x80445DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80445DD0:
    // 0x80445DD0: jal         0x80445CBC
    // 0x80445DD4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80445CBC(rdram, ctx);
        goto after_8;
    // 0x80445DD4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_8:
    // 0x80445DD8: jal         0x80445CC4
    // 0x80445DDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_9;
    // 0x80445DDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80445DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80445DE4:
    // 0x80445DE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445DE8: jr          $ra
    // 0x80445DEC: nop

    return;
    // 0x80445DEC: nop

;}
RECOMP_FUNC void func_8070F5F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070F5F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8070F5F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8070F5FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8070F600: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8070F604: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8070F608: lui         $t7, 0x8071
    ctx->r15 = S32(RELOC_HI16(724, 0X18B0) << 16);
    // 0x8070F60C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8070F610: addiu       $t7, $t7, 0xCA0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(724, 0X18B0));
    // 0x8070F614: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8070F618: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8070F61C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8070F620: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x8070F624: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8070F628: jal         0x80045A34
    // 0x8070F62C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8070F62C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_0:
    // 0x8070F630: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8070F634: jal         0x8070F454
    // 0x8070F638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8070F454(rdram, ctx);
        goto after_1;
    // 0x8070F638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8070F63C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070F640: jal         0x80710C50
    // 0x8070F644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80710C50(rdram, ctx);
        goto after_2;
    // 0x8070F644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8070F648: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
    // 0x8070F64C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8070F650: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8070F654: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8070F658: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8070F65C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x8070F660: jr          $ra
    // 0x8070F664: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8070F664: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80004A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004A6C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80004A70: addiu       $a2, $a2, 0x4D10
    ctx->r6 = ADD32(ctx->r6, 0X4D10);
    // 0x80004A74: lw          $v0, 0x1DC0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1DC0);
    // 0x80004A78: lh          $t6, 0x1D86($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X1D86);
    // 0x80004A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80004A80: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80004A84: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80004A88: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80004A8C: addu        $a0, $a2, $t9
    ctx->r4 = ADD32(ctx->r6, ctx->r25);
    // 0x80004A90: addiu       $v0, $zero, 0xB00
    ctx->r2 = ADD32(0, 0XB00);
    // 0x80004A94: sh          $t6, 0x1E8C($t8)
    MEM_H(0X1E8C, ctx->r24) = ctx->r14;
L_80004A98:
    // 0x80004A98: lw          $t0, 0x1E80($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1E80);
    // 0x80004A9C: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x80004AA0: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x80004AA4: lw          $t2, 0x1E80($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1E80);
    // 0x80004AA8: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x80004AAC: sh          $zero, 0x2($t3)
    MEM_H(0X2, ctx->r11) = 0;
    // 0x80004AB0: lw          $t4, 0x1E80($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1E80);
    // 0x80004AB4: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x80004AB8: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x80004ABC: lw          $t7, 0x1E80($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E80);
    // 0x80004AC0: addu        $t6, $t7, $a1
    ctx->r14 = ADD32(ctx->r15, ctx->r5);
    // 0x80004AC4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80004AC8: bne         $a1, $v0, L_80004A98
    if (ctx->r5 != ctx->r2) {
        // 0x80004ACC: sh          $zero, 0x6($t6)
        MEM_H(0X6, ctx->r14) = 0;
            goto L_80004A98;
    }
    // 0x80004ACC: sh          $zero, 0x6($t6)
    MEM_H(0X6, ctx->r14) = 0;
    // 0x80004AD0: jr          $ra
    // 0x80004AD4: nop

    return;
    // 0x80004AD4: nop

;}
RECOMP_FUNC void tmemLoad_B(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F38: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80082F3C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80082F40: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80082F44: lw          $t0, -0xF00($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XF00);
    // 0x80082F48: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80082F4C: lui         $t5, 0xE600
    ctx->r13 = S32(0XE600 << 16);
    // 0x80082F50: or          $t8, $a3, $zero
    ctx->r24 = ctx->r7 | 0;
    // 0x80082F54: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80082F58: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80082F5C: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80082F60: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x80082F64: sw          $a1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r5;
    // 0x80082F68: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80082F6C: lui         $t9, 0xF400
    ctx->r25 = S32(0XF400 << 16);
    // 0x80082F70: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80082F74: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80082F78: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80082F7C: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x80082F80: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80082F84: addiu       $t1, $a3, -0x1
    ctx->r9 = ADD32(ctx->r7, -0X1);
    // 0x80082F88: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80082F8C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80082F90: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80082F94: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x80082F98: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80082F9C: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x80082FA0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80082FA4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80082FA8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80082FAC: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80082FB0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80082FB4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80082FB8: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80082FBC: jr          $ra
    // 0x80082FC0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    return;
    // 0x80082FC0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
;}
