#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_806CDA80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CDA80: jr          $ra
    // 0x806CDA84: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806CDA84: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80469740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469740: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80469744: addiu       $at, $zero, 0x4118
    ctx->r1 = ADD32(0, 0X4118);
    // 0x80469748: beq         $v0, $at, L_80469760
    if (ctx->r2 == ctx->r1) {
        // 0x8046974C: addiu       $at, $zero, 0x4119
        ctx->r1 = ADD32(0, 0X4119);
            goto L_80469760;
    }
    // 0x8046974C: addiu       $at, $zero, 0x4119
    ctx->r1 = ADD32(0, 0X4119);
    // 0x80469750: beq         $v0, $at, L_8046976C
    if (ctx->r2 == ctx->r1) {
        // 0x80469754: nop
    
            goto L_8046976C;
    }
    // 0x80469754: nop

    // 0x80469758: b           L_80469778
    // 0x8046975C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80469778;
    // 0x8046975C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80469760:
    // 0x80469760: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(138, 0X26E8) << 16);
    // 0x80469764: jr          $ra
    // 0x80469768: addiu       $v0, $v0, -0x41D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(138, 0X26E8));
    return;
    // 0x80469768: addiu       $v0, $v0, -0x41D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(138, 0X26E8));
L_8046976C:
    // 0x8046976C: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(138, 0X1AF8) << 16);
    // 0x80469770: jr          $ra
    // 0x80469774: addiu       $v0, $v0, -0x4DC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(138, 0X1AF8));
    return;
    // 0x80469774: addiu       $v0, $v0, -0x4DC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(138, 0X1AF8));
L_80469778:
    // 0x80469778: jr          $ra
    // 0x8046977C: nop

    return;
    // 0x8046977C: nop

;}
RECOMP_FUNC void func_805AD274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AD274: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x805AD278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AD27C: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x805AD280: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x805AD284: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x805AD288: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x805AD28C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AD290: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805AD294: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805AD298: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x805AD29C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805AD2A0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x805AD2A4: lui         $t0, 0x805B
    ctx->r8 = S32(RELOC_HI16(441, 0X1308) << 16);
    // 0x805AD2A8: sb          $a3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r7;
    // 0x805AD2AC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805AD2B0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x805AD2B4: lw          $t0, -0x2B08($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(441, 0X1308));
    // 0x805AD2B8: sw          $v0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r2;
    // 0x805AD2BC: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x805AD2C0: jal         0x805AD218
    // 0x805AD2C4: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    func_805AD218(rdram, ctx);
        goto after_0;
    // 0x805AD2C4: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    after_0:
    // 0x805AD2C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AD2CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AD2D0: jr          $ra
    // 0x805AD2D4: nop

    return;
    // 0x805AD2D4: nop

    // 0x805AD2D8: nop

    // 0x805AD2DC: nop

;}
RECOMP_FUNC void func_80000FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000FA0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80000FA4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80000FA8: and         $t6, $a1, $at
    ctx->r14 = ctx->r5 & ctx->r1;
    // 0x80000FAC: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x80000FB0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80000FB4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80000FB8: jr          $ra
    // 0x80000FBC: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    return;
    // 0x80000FBC: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void func_800299E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800299E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800299E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800299E8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800299EC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800299F0: addiu       $a1, $a2, 0x1D0
    ctx->r5 = ADD32(ctx->r6, 0X1D0);
    // 0x800299F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800299F8: addiu       $a2, $a2, 0x1D8
    ctx->r6 = ADD32(ctx->r6, 0X1D8);
    // 0x800299FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80029A00: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80029A04: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80029A08: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80029A0C: jal         0x800292D4
    // 0x80029A10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800292D4(rdram, ctx);
        goto after_0;
    // 0x80029A10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80029A14: lbu         $t6, 0xF4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XF4);
    // 0x80029A18: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80029A1C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80029A20: bne         $t6, $zero, L_80029A4C
    if (ctx->r14 != 0) {
        // 0x80029A24: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80029A4C;
    }
    // 0x80029A24: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80029A28: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80029A2C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80029A30: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x80029A34: beql        $t8, $zero, L_80029A64
    if (ctx->r24 == 0) {
        // 0x80029A38: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80029A64;
    }
    goto skip_0;
    // 0x80029A38: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x80029A3C: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x80029A40: andi        $t0, $t9, 0x700
    ctx->r8 = ctx->r25 & 0X700;
    // 0x80029A44: bnel        $t0, $zero, L_80029A64
    if (ctx->r8 != 0) {
        // 0x80029A48: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80029A64;
    }
    goto skip_1;
    // 0x80029A48: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_1:
L_80029A4C:
    // 0x80029A4C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80029A50: jal         0x800298B4
    // 0x80029A54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800298B4(rdram, ctx);
        goto after_1;
    // 0x80029A54: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80029A58: b           L_80029A70
    // 0x80029A5C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_80029A70;
    // 0x80029A5C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80029A60: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80029A64:
    // 0x80029A64: jal         0x80029678
    // 0x80029A68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80029678(rdram, ctx);
        goto after_2;
    // 0x80029A68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80029A6C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80029A70:
    // 0x80029A70: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80029A74: jal         0x80029220
    // 0x80029A78: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80029220(rdram, ctx);
        goto after_3;
    // 0x80029A78: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80029A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80029A80: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029A84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80029A88: jr          $ra
    // 0x80029A8C: nop

    return;
    // 0x80029A8C: nop

;}
RECOMP_FUNC void func_8005934C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005934C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80059350: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80059354: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80059358: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x8005935C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80059360: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80059364: lwc1        $f10, 0x38($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80059368: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005936C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80059370: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80059374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059378: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8005937C: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x80059380: nop

    // 0x80059384: bc1f        L_80059390
    if (!c1cs) {
        // 0x80059388: nop
    
            goto L_80059390;
    }
    // 0x80059388: nop

    // 0x8005938C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059390:
    // 0x80059390: jr          $ra
    // 0x80059394: nop

    return;
    // 0x80059394: nop

;}
RECOMP_FUNC void func_80067114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006711C: jal         0x80066FA0
    // 0x80067120: nop

    func_80066FA0(rdram, ctx);
        goto after_0;
    // 0x80067120: nop

    after_0:
    // 0x80067124: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80067128: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8006712C: sra         $t8, $v0, 8
    ctx->r24 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80067130: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80067134: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80067138: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8006713C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80067140: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80067144: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80067148: lui         $at, 0x3FB4
    ctx->r1 = S32(0X3FB4 << 16);
    // 0x8006714C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80067150: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80067154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006715C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067160: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80067164: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80067168: jr          $ra
    // 0x8006716C: nop

    return;
    // 0x8006716C: nop

;}
RECOMP_FUNC void func_8005B1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B1E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8005B1E8: lh          $t6, 0x30($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X30);
    // 0x8005B1EC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8005B1F0: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8005B1F4: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005B1F8: lw          $t0, 0x3C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X3C);
    // 0x8005B1FC: mflo        $t7
    ctx->r15 = lo;
    // 0x8005B200: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8005B204: jr          $ra
    // 0x8005B208: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    return;
    // 0x8005B208: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
;}
RECOMP_FUNC void func_80450200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450200: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450204: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450208: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8045020C: sw          $zero, 0x6EF4($at)
    MEM_W(0X6EF4, ctx->r1) = 0;
    // 0x80450210: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450214: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80450218: jr          $ra
    // 0x8045021C: sw          $zero, 0x6EFC($at)
    MEM_W(0X6EFC, ctx->r1) = 0;
    return;
    // 0x8045021C: sw          $zero, 0x6EFC($at)
    MEM_W(0X6EFC, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80681BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681BBC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80681BC0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80681BC4: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80681BC8: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80681BCC: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80681BD0: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80681BD4: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80681BD8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80681BDC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80681BE0: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80681BE4: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80681BE8: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80681BEC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681BF0: lui         $s5, 0xE700
    ctx->r21 = S32(0XE700 << 16);
    // 0x80681BF4: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x80681BF8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80681BFC: lui         $s6, 0x400
    ctx->r22 = S32(0X400 << 16);
    // 0x80681C00: lw          $t8, 0x1F4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1F4);
    // 0x80681C04: lui         $t7, 0x104
    ctx->r15 = S32(0X104 << 16);
    // 0x80681C08: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x80681C0C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80681C10: lui         $s7, 0x8068
    ctx->r23 = S32(RELOC_HI16(550, 0X1D30) << 16);
    // 0x80681C14: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80681C18: lw          $v1, 0x1F4($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X1F4);
    // 0x80681C1C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80681C20: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80681C24: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80681C28: addiu       $s7, $s7, 0x2140
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(550, 0X1D30));
    // 0x80681C2C: ori         $s6, $s6, 0x81FF
    ctx->r22 = ctx->r22 | 0X81FF;
    // 0x80681C30: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x80681C34: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80681C38: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80681C3C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80681C40: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681C44: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80681C48: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80681C4C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80681C50: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80681C54: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80681C58: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80681C5C: addiu       $fp, $zero, 0x7E0
    ctx->r30 = ADD32(0, 0X7E0);
    // 0x80681C60: lui         $ra, 0xFD50
    ctx->r31 = S32(0XFD50 << 16);
    // 0x80681C64: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80681C68: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80681C6C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
L_80681C70:
    // 0x80681C70: slti        $at, $s0, 0x8
    ctx->r1 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x80681C74: bne         $at, $zero, L_80681CA4
    if (ctx->r1 != 0) {
        // 0x80681C78: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80681CA4;
    }
    // 0x80681C78: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80681C7C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681C80: sll         $t6, $s3, 4
    ctx->r14 = S32(ctx->r19 << 4);
    // 0x80681C84: addu        $t7, $s7, $t6
    ctx->r15 = ADD32(ctx->r23, ctx->r14);
    // 0x80681C88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80681C8C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80681C90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80681C94: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x80681C98: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80681C9C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80681CA0: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
L_80681CA4:
    // 0x80681CA4: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x80681CA8: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80681CAC: addiu       $t1, $v1, 0x2
    ctx->r9 = ADD32(ctx->r3, 0X2);
    // 0x80681CB0: addiu       $t2, $v1, 0x4
    ctx->r10 = ADD32(ctx->r3, 0X4);
    // 0x80681CB4: bne         $at, $zero, L_80681CC0
    if (ctx->r1 != 0) {
        // 0x80681CB8: addiu       $t3, $v1, 0x6
        ctx->r11 = ADD32(ctx->r3, 0X6);
            goto L_80681CC0;
    }
    // 0x80681CB8: addiu       $t3, $v1, 0x6
    ctx->r11 = ADD32(ctx->r3, 0X6);
    // 0x80681CBC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_80681CC0:
    // 0x80681CC0: multu       $t4, $fp
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80681CC4: lw          $t8, 0x168($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X168);
    // 0x80681CC8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681CCC: andi        $a0, $t2, 0xFF
    ctx->r4 = ctx->r10 & 0XFF;
    // 0x80681CD0: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x80681CD4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80681CD8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80681CDC: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80681CE0: lui         $at, 0xB100
    ctx->r1 = S32(0XB100 << 16);
    // 0x80681CE4: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80681CE8: mflo        $t6
    ctx->r14 = lo;
    // 0x80681CEC: addu        $t0, $t9, $t6
    ctx->r8 = ADD32(ctx->r25, ctx->r14);
    // 0x80681CF0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80681CF4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681CF8: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x80681CFC: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x80681D00: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80681D04: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80681D08: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80681D0C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80681D10: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681D14: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80681D18: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80681D1C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80681D20: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80681D24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80681D28: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80681D2C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681D30: lui         $t7, 0x73E
    ctx->r15 = S32(0X73E << 16);
    // 0x80681D34: ori         $t7, $t7, 0xF0AB
    ctx->r15 = ctx->r15 | 0XF0AB;
    // 0x80681D38: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80681D3C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80681D40: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80681D44: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80681D48: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681D4C: lui         $t6, 0xF548
    ctx->r14 = S32(0XF548 << 16);
    // 0x80681D50: ori         $t6, $t6, 0x1800
    ctx->r14 = ctx->r14 | 0X1800;
    // 0x80681D54: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80681D58: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80681D5C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80681D60: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80681D64: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681D68: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80681D6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80681D70: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80681D74: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80681D78: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80681D7C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80681D80: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681D84: lui         $t9, 0x17
    ctx->r25 = S32(0X17 << 16);
    // 0x80681D88: ori         $t9, $t9, 0xC050
    ctx->r25 = ctx->r25 | 0XC050;
    // 0x80681D8C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80681D90: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80681D94: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80681D98: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80681D9C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80681DA0: andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // 0x80681DA4: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x80681DA8: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80681DAC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80681DB0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80681DB4: sll         $t9, $v0, 8
    ctx->r25 = S32(ctx->r2 << 8);
    // 0x80681DB8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80681DBC: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x80681DC0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80681DC4: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x80681DC8: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80681DCC: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80681DD0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80681DD4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80681DD8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80681DDC: or          $t6, $t8, $a0
    ctx->r14 = ctx->r24 | ctx->r4;
    // 0x80681DE0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80681DE4: bne         $s2, $at, L_80681C70
    if (ctx->r18 != ctx->r1) {
        // 0x80681DE8: sw          $t6, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r14;
            goto L_80681C70;
    }
    // 0x80681DE8: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80681DEC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80681DF0: lui         $t7, 0xBD00
    ctx->r15 = S32(0XBD00 << 16);
    // 0x80681DF4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80681DF8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80681DFC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80681E00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80681E04: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80681E08: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80681E0C: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80681E10: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80681E14: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80681E18: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80681E1C: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80681E20: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80681E24: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80681E28: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80681E2C: jr          $ra
    // 0x80681E30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80681E30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80716F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716F78: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716F7C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716F80: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716F84: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716F88: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716F8C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716F90: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716F94: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716F98: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716F9C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716FA0: jr          $ra
    // 0x80716FA4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716FA4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8040C908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C908: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8040C90C: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(20, 0X1E10) << 16);
    // 0x8040C910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C914: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8040C918: addiu       $t7, $t7, -0x1BF0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(20, 0X1E10));
    // 0x8040C91C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8040C920: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040C924: addiu       $t6, $sp, 0x18
    ctx->r14 = ADD32(ctx->r29, 0X18);
    // 0x8040C928: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8040C92C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8040C930: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8040C934: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8040C938: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8040C93C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8040C940: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8040C944: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8040C948: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8040C94C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8040C950: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8040C954: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8040C958: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x8040C95C: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x8040C960: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x8040C964: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x8040C968: swc1        $f0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f0.u32l;
    // 0x8040C96C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8040C970: jal         0x8005FE48
    // 0x8040C974: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x8040C974: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x8040C978: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8040C97C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8040C980: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8040C984: lw          $t0, 0x28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X28);
    // 0x8040C988: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8040C98C: addu        $t9, $sp, $t1
    ctx->r25 = ADD32(ctx->r29, ctx->r9);
    // 0x8040C990: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x8040C994: jalr        $t9
    // 0x8040C998: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8040C998: nop

    after_1:
    // 0x8040C99C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040C9A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8040C9A4: jr          $ra
    // 0x8040C9A8: nop

    return;
    // 0x8040C9A8: nop

;}
RECOMP_FUNC void func_8044F384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044F384: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044F388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044F38C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044F390: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F394: addiu       $a1, $zero, -0x64
    ctx->r5 = ADD32(0, -0X64);
    // 0x8044F398: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x8044F39C: lw          $t6, 0x6A40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6A40);
    // 0x8044F3A0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F3A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8044F3A8: beq         $a1, $t6, L_8044F3B4
    if (ctx->r5 == ctx->r14) {
        // 0x8044F3AC: addu        $at, $at, $v1
        ctx->r1 = ADD32(ctx->r1, ctx->r3);
            goto L_8044F3B4;
    }
    // 0x8044F3AC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8044F3B0: sw          $t7, 0x6A44($at)
    MEM_W(0X6A44, ctx->r1) = ctx->r15;
L_8044F3B4:
    // 0x8044F3B4: lw          $t8, 0x6A44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X6A44);
    // 0x8044F3B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044F3BC: bnel        $t8, $at, L_8044F400
    if (ctx->r24 != ctx->r1) {
        // 0x8044F3C0: lw          $a0, 0x6A48($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X6A48);
            goto L_8044F400;
    }
    goto skip_0;
    // 0x8044F3C0: lw          $a0, 0x6A48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6A48);
    skip_0:
    // 0x8044F3C4: lw          $t9, 0x6A40($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X6A40);
    // 0x8044F3C8: beql        $a1, $t9, L_8044F400
    if (ctx->r5 == ctx->r25) {
        // 0x8044F3CC: lw          $a0, 0x6A48($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X6A48);
            goto L_8044F400;
    }
    goto skip_1;
    // 0x8044F3CC: lw          $a0, 0x6A48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6A48);
    skip_1:
    // 0x8044F3D0: lw          $t0, 0x6A48($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X6A48);
    // 0x8044F3D4: bnel        $t0, $zero, L_8044F400
    if (ctx->r8 != 0) {
        // 0x8044F3D8: lw          $a0, 0x6A48($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X6A48);
            goto L_8044F400;
    }
    goto skip_2;
    // 0x8044F3D8: lw          $a0, 0x6A48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6A48);
    skip_2:
    // 0x8044F3DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8044F3E0: jal         0x8044F28C
    // 0x8044F3E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8044F28C(rdram, ctx);
        goto after_0;
    // 0x8044F3E4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044F3E8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044F3EC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F3F0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8044F3F4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8044F3F8: sw          $zero, 0x6A44($at)
    MEM_W(0X6A44, ctx->r1) = 0;
    // 0x8044F3FC: lw          $a0, 0x6A48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X6A48);
L_8044F400:
    // 0x8044F400: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044F404: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8044F408: blez        $a0, L_8044F414
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8044F40C: addiu       $t1, $a0, -0x1
        ctx->r9 = ADD32(ctx->r4, -0X1);
            goto L_8044F414;
    }
    // 0x8044F40C: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x8044F410: sw          $t1, 0x6A48($at)
    MEM_W(0X6A48, ctx->r1) = ctx->r9;
L_8044F414:
    // 0x8044F414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044F418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044F41C: jr          $ra
    // 0x8044F420: nop

    return;
    // 0x8044F420: nop

;}
RECOMP_FUNC void func_805AA5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA5A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AA5AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA5B0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805AA5B4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x805AA5B8: lui         $t8, 0x805B
    ctx->r24 = S32(RELOC_HI16(432, 0XAD4) << 16);
    // 0x805AA5BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805AA5C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805AA5C4: lw          $t8, -0x523C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(432, 0XAD4));
    // 0x805AA5C8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805AA5CC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x805AA5D0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x805AA5D4: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x805AA5D8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805AA5DC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805AA5E0: beql        $v1, $zero, L_805AA614
    if (ctx->r3 == 0) {
        // 0x805AA5E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AA614;
    }
    goto skip_0;
    // 0x805AA5E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805AA5E8: jalr        $v1
    // 0x805AA5EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805AA5EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AA5F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AA5F4: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x805AA5F8: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x805AA5FC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x805AA600: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x805AA604: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x805AA608: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x805AA60C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x805AA610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AA614:
    // 0x805AA614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AA618: jr          $ra
    // 0x805AA61C: nop

    return;
    // 0x805AA61C: nop

;}
RECOMP_FUNC void func_80068D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068D28: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068D2C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068D34: addiu       $t6, $zero, 0x1B
    ctx->r14 = ADD32(0, 0X1B);
    // 0x80068D38: jal         0x8006D1C0
    // 0x80068D3C: sw          $t6, 0x5B4($v0)
    MEM_W(0X5B4, ctx->r2) = ctx->r14;
    func_8006D1C0(rdram, ctx);
        goto after_0;
    // 0x80068D3C: sw          $t6, 0x5B4($v0)
    MEM_W(0X5B4, ctx->r2) = ctx->r14;
    after_0:
    // 0x80068D40: jal         0x8006D774
    // 0x80068D44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8006D774(rdram, ctx);
        goto after_1;
    // 0x80068D44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80068D48: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80068D4C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80068D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068D54: sw          $zero, 0xAB0($v0)
    MEM_W(0XAB0, ctx->r2) = 0;
    // 0x80068D58: sw          $zero, 0xAB4($v0)
    MEM_W(0XAB4, ctx->r2) = 0;
    // 0x80068D5C: sw          $zero, 0xAB8($v0)
    MEM_W(0XAB8, ctx->r2) = 0;
    // 0x80068D60: sw          $zero, 0xABC($v0)
    MEM_W(0XABC, ctx->r2) = 0;
    // 0x80068D64: sw          $zero, 0xAC0($v0)
    MEM_W(0XAC0, ctx->r2) = 0;
    // 0x80068D68: sw          $zero, 0xAC4($v0)
    MEM_W(0XAC4, ctx->r2) = 0;
    // 0x80068D6C: sw          $zero, 0xAC8($v0)
    MEM_W(0XAC8, ctx->r2) = 0;
    // 0x80068D70: sw          $zero, 0xACC($v0)
    MEM_W(0XACC, ctx->r2) = 0;
    // 0x80068D74: sw          $zero, 0xAD0($v0)
    MEM_W(0XAD0, ctx->r2) = 0;
    // 0x80068D78: sw          $zero, 0xAD4($v0)
    MEM_W(0XAD4, ctx->r2) = 0;
    // 0x80068D7C: sw          $zero, 0xB30($v0)
    MEM_W(0XB30, ctx->r2) = 0;
    // 0x80068D80: sw          $zero, 0xBAC($v0)
    MEM_W(0XBAC, ctx->r2) = 0;
    // 0x80068D84: jr          $ra
    // 0x80068D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80068D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80430AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430AB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430AB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80430AB8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80430ABC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80430AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430AC4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80430AC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80430ACC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80430AD0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80430AD4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80430AD8: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(56, 0X38C8) << 16);
    // 0x80430ADC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80430AE0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80430AE4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80430AE8: lw          $t2, 0x19A8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(56, 0X38C8));
    // 0x80430AEC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80430AF0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80430AF4: jal         0x804305F8
    // 0x80430AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804305F8(rdram, ctx);
        goto after_0;
    // 0x80430AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80430AFC: jal         0x80430654
    // 0x80430B00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80430654(rdram, ctx);
        goto after_1;
    // 0x80430B00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80430B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80430B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80430B0C: jr          $ra
    // 0x80430B10: nop

    return;
    // 0x80430B10: nop

;}
RECOMP_FUNC void func_8045B9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B9F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045B9FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045BA00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8045BA04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045BA08: jal         0x80051194
    // 0x8045BA0C: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x8045BA0C: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x8045BA10: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x8045BA14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BA18: jal         0x8045BBF4
    // 0x8045BA1C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_8045BBF4(rdram, ctx);
        goto after_1;
    // 0x8045BA1C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_1:
    // 0x8045BA20: beq         $v0, $zero, L_8045BA4C
    if (ctx->r2 == 0) {
        // 0x8045BA24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8045BA4C;
    }
    // 0x8045BA24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BA28: jal         0x8045BCC4
    // 0x8045BA2C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_8045BCC4(rdram, ctx);
        goto after_2;
    // 0x8045BA2C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_2:
    // 0x8045BA30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BA34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045BA38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8045BA3C: jal         0x8045D680
    // 0x8045BA40: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8045D680(rdram, ctx);
        goto after_3;
    // 0x8045BA40: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x8045BA44: b           L_8045BA58
    // 0x8045BA48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8045BA58;
    // 0x8045BA48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045BA4C:
    // 0x8045BA4C: jal         0x800445A4
    // 0x8045BA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8045BA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8045BA54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045BA58:
    // 0x8045BA58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045BA5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045BA60: jr          $ra
    // 0x8045BA64: nop

    return;
    // 0x8045BA64: nop

;}
RECOMP_FUNC void func_804215D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804215D0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804215D4: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(32, 0X190) << 16);
    // 0x804215D8: addiu       $t6, $t6, 0x1250
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(32, 0X190));
    // 0x804215DC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804215E0: jr          $ra
    // 0x804215E4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804215E4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_807423AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807423AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807423B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807423B4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x807423B8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x807423BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x807423C0: jal         0x80066DE4
    // 0x807423C4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x807423C4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x807423C8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x807423CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807423D0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x807423D4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x807423D8: jal         0x80066E88
    // 0x807423DC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x807423DC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x807423E0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x807423E4: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807423E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807423EC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x807423F0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x807423F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807423F8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x807423FC: jr          $ra
    // 0x80742400: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    return;
    // 0x80742400: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
;}
RECOMP_FUNC void func_8000877C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000877C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80008780: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80008784: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80008788: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000878C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80008790: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80008794: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80008798: addiu       $t6, $t6, 0x4D10
    ctx->r14 = ADD32(ctx->r14, 0X4D10);
    // 0x8000879C: lw          $t7, 0x1E9C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1E9C);
    // 0x800087A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800087A4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800087A8: beq         $t7, $at, L_800087E4
    if (ctx->r15 == ctx->r1) {
        // 0x800087AC: lui         $s0, 0x800B
        ctx->r16 = S32(0X800B << 16);
            goto L_800087E4;
    }
    // 0x800087AC: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800087B0: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800087B4: addiu       $s2, $s2, 0x5250
    ctx->r18 = ADD32(ctx->r18, 0X5250);
    // 0x800087B8: addiu       $s0, $s0, 0x4D10
    ctx->r16 = ADD32(ctx->r16, 0X4D10);
    // 0x800087BC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800087C0: lb          $t8, 0xD88($s0)
    ctx->r24 = MEM_B(ctx->r16, 0XD88);
L_800087C4:
    // 0x800087C4: addiu       $a0, $s0, 0xD88
    ctx->r4 = ADD32(ctx->r16, 0XD88);
    // 0x800087C8: bnel        $s1, $t8, L_800087DC
    if (ctx->r17 != ctx->r24) {
        // 0x800087CC: addiu       $s0, $s0, 0x54
        ctx->r16 = ADD32(ctx->r16, 0X54);
            goto L_800087DC;
    }
    goto skip_0;
    // 0x800087CC: addiu       $s0, $s0, 0x54
    ctx->r16 = ADD32(ctx->r16, 0X54);
    skip_0:
    // 0x800087D0: jal         0x80008800
    // 0x800087D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80008800(rdram, ctx);
        goto after_0;
    // 0x800087D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800087D8: addiu       $s0, $s0, 0x54
    ctx->r16 = ADD32(ctx->r16, 0X54);
L_800087DC:
    // 0x800087DC: bnel        $s0, $s2, L_800087C4
    if (ctx->r16 != ctx->r18) {
        // 0x800087E0: lb          $t8, 0xD88($s0)
        ctx->r24 = MEM_B(ctx->r16, 0XD88);
            goto L_800087C4;
    }
    goto skip_1;
    // 0x800087E0: lb          $t8, 0xD88($s0)
    ctx->r24 = MEM_B(ctx->r16, 0XD88);
    skip_1:
L_800087E4:
    // 0x800087E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800087E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800087EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800087F0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800087F4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800087F8: jr          $ra
    // 0x800087FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800087FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8043DDB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DDB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043DDB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043DDBC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8043DDC0: lui         $v0, 0x8044
    ctx->r2 = S32(RELOC_HI16(92, 0X1B08) << 16);
    // 0x8043DDC4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8043DDC8: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8043DDCC: lw          $v0, -0x14B8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(92, 0X1B08));
    // 0x8043DDD0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8043DDD4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8043DDD8: beql        $v1, $zero, L_8043DDEC
    if (ctx->r3 == 0) {
        // 0x8043DDDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043DDEC;
    }
    goto skip_0;
    // 0x8043DDDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043DDE0: jalr        $v1
    // 0x8043DDE4: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8043DDE4: nop

    after_0:
    // 0x8043DDE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043DDEC:
    // 0x8043DDEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043DDF0: jr          $ra
    // 0x8043DDF4: nop

    return;
    // 0x8043DDF4: nop

;}
RECOMP_FUNC void func_80045B2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045B2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80045B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045B34: jal         0x80043A24
    // 0x80045B38: nop

    func_80043A24(rdram, ctx);
        goto after_0;
    // 0x80045B38: nop

    after_0:
    // 0x80045B3C: bne         $v0, $zero, L_80045B4C
    if (ctx->r2 != 0) {
        // 0x80045B40: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80045B4C;
    }
    // 0x80045B40: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80045B44: b           L_80045B54
    // 0x80045B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80045B54;
    // 0x80045B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80045B4C:
    // 0x80045B4C: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x80045B50: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80045B54:
    // 0x80045B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80045B58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045B5C: jr          $ra
    // 0x80045B60: nop

    return;
    // 0x80045B60: nop

;}
RECOMP_FUNC void func_8001B2E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B2E0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8001B2E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001B2E8: addiu       $a1, $a1, 0x660
    ctx->r5 = ADD32(ctx->r5, 0X660);
    // 0x8001B2EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B2F0: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
L_8001B2F4:
    // 0x8001B2F4: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B2F8: mflo        $t6
    ctx->r14 = lo;
    // 0x8001B2FC: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x8001B300: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8001B304: bne         $t7, $zero, L_8001B344
    if (ctx->r15 != 0) {
        // 0x8001B308: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8001B344;
    }
    // 0x8001B308: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B30C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B310: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x8001B314: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B318: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001B31C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001B320: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8001B324: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
    // 0x8001B328: sb          $zero, 0x3C($a0)
    MEM_B(0X3C, ctx->r4) = 0;
    // 0x8001B32C: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001B330: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8001B334: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x8001B338: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8001B33C: b           L_8001B35C
    // 0x8001B340: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
        goto L_8001B35C;
    // 0x8001B340: swc1        $f6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f6.u32l;
L_8001B344:
    // 0x8001B344: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B348: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001B34C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001B350: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x8001B354: bne         $at, $zero, L_8001B2F4
    if (ctx->r1 != 0) {
        // 0x8001B358: nop
    
            goto L_8001B2F4;
    }
    // 0x8001B358: nop

L_8001B35C:
    // 0x8001B35C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001B360: sw          $v1, -0x6CEC($at)
    MEM_W(-0X6CEC, ctx->r1) = ctx->r3;
    // 0x8001B364: jr          $ra
    // 0x8001B368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001B368: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_807A6640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A6644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6648: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x807A664C: addiu       $at, $zero, 0x471A
    ctx->r1 = ADD32(0, 0X471A);
    // 0x807A6650: bnel        $t6, $at, L_807A6704
    if (ctx->r14 != ctx->r1) {
        // 0x807A6654: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807A6704;
    }
    goto skip_0;
    // 0x807A6654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807A6658: jal         0x807A6558
    // 0x807A665C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A6558(rdram, ctx);
        goto after_0;
    // 0x807A665C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A6660: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x807A6664: beq         $at, $zero, L_807A66FC
    if (ctx->r1 == 0) {
        // 0x807A6668: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_807A66FC;
    }
    // 0x807A6668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807A666C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x807A6670: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(847, 0X1590) << 16);
    // 0x807A6674: addu        $at, $at, $t7
    gpr jr_addend_807A667C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x807A6678: lw          $t7, 0x7290($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(847, 0X1590));
    // 0x807A667C: jr          $t7
    // 0x807A6680: nop

    switch (jr_addend_807A667C >> 2) {
        case 0: goto L_807A6684; break;
        case 1: goto L_807A669C; break;
        case 2: goto L_807A66B4; break;
        case 3: goto L_807A66CC; break;
        case 4: goto L_807A66E4; break;
        default: switch_error(__func__, 0x807A667C, 0x807A7290);
    }
    // 0x807A6680: nop

L_807A6684:
    // 0x807A6684: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807A6688: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    // 0x807A668C: jal         0x807A65EC
    // 0x807A6690: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A65EC(rdram, ctx);
        goto after_1;
    // 0x807A6690: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x807A6694: b           L_807A6704
    // 0x807A6698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A6704;
    // 0x807A6698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A669C:
    // 0x807A669C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x807A66A0: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x807A66A4: jal         0x807A65EC
    // 0x807A66A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_807A65EC(rdram, ctx);
        goto after_2;
    // 0x807A66A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x807A66AC: b           L_807A6704
    // 0x807A66B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A6704;
    // 0x807A66B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A66B4:
    // 0x807A66B4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x807A66B8: sh          $t0, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r8;
    // 0x807A66BC: jal         0x807A65EC
    // 0x807A66C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_807A65EC(rdram, ctx);
        goto after_3;
    // 0x807A66C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x807A66C4: b           L_807A6704
    // 0x807A66C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A6704;
    // 0x807A66C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A66CC:
    // 0x807A66CC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x807A66D0: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x807A66D4: jal         0x807A65EC
    // 0x807A66D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_807A65EC(rdram, ctx);
        goto after_4;
    // 0x807A66D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x807A66DC: b           L_807A6704
    // 0x807A66E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A6704;
    // 0x807A66E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A66E4:
    // 0x807A66E4: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x807A66E8: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x807A66EC: jal         0x807A65EC
    // 0x807A66F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_807A65EC(rdram, ctx);
        goto after_5;
    // 0x807A66F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x807A66F4: b           L_807A6704
    // 0x807A66F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807A6704;
    // 0x807A66F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A66FC:
    // 0x807A66FC: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807A6700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807A6704:
    // 0x807A6704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A6708: jr          $ra
    // 0x807A670C: nop

    return;
    // 0x807A670C: nop

;}
RECOMP_FUNC void func_8044B03C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B03C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044B040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B044: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044B048: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B04C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B050: lw          $a1, 0x6A68($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A68);
    // 0x8044B054: beq         $a1, $zero, L_8044B06C
    if (ctx->r5 == 0) {
        // 0x8044B058: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044B06C;
    }
    // 0x8044B058: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044B05C: jal         0x80050A2C
    // 0x8044B060: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044B060: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044B064: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B068: sw          $zero, 0x6A68($v1)
    MEM_W(0X6A68, ctx->r3) = 0;
L_8044B06C:
    // 0x8044B06C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B070: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044B074: jr          $ra
    // 0x8044B078: nop

    return;
    // 0x8044B078: nop

;}
RECOMP_FUNC void func_804A4E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4E04: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A4E08: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A4E0C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A4E10: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A4E14: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A4E18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A4E1C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A4E20: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A4E24: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A4E28: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A4E2C: jr          $ra
    // 0x804A4E30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A4E30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804CC470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC470: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(237, 0X10) << 16);
    // 0x804CC474: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804CC478: jr          $ra
    // 0x804CC47C: addiu       $v0, $v0, -0x3B80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(237, 0X10));
    return;
    // 0x804CC47C: addiu       $v0, $v0, -0x3B80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(237, 0X10));
;}
RECOMP_FUNC void func_80009334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009334: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80009338: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000933C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80009340: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80009344: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x80009348: beq         $t6, $zero, L_80009384
    if (ctx->r14 == 0) {
        // 0x8000934C: sll         $t8, $v1, 6
        ctx->r24 = S32(ctx->r3 << 6);
            goto L_80009384;
    }
    // 0x8000934C: sll         $t8, $v1, 6
    ctx->r24 = S32(ctx->r3 << 6);
    // 0x80009350: bgez        $t8, L_80009384
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80009354: sll         $t9, $v1, 4
        ctx->r25 = S32(ctx->r3 << 4);
            goto L_80009384;
    }
    // 0x80009354: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x80009358: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x8000935C: beq         $t0, $zero, L_80009384
    if (ctx->r8 == 0) {
        // 0x80009360: lui         $v1, 0x800B
        ctx->r3 = S32(0X800B << 16);
            goto L_80009384;
    }
    // 0x80009360: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80009364: addiu       $v1, $v1, 0x4D10
    ctx->r3 = ADD32(ctx->r3, 0X4D10);
    // 0x80009368: lw          $t1, 0xD80($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XD80);
    // 0x8000936C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80009370: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x80009374: sw          $v0, 0x180($t3)
    MEM_W(0X180, ctx->r11) = ctx->r2;
    // 0x80009378: lw          $t4, 0xD80($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XD80);
    // 0x8000937C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80009380: sw          $t5, 0xD80($v1)
    MEM_W(0XD80, ctx->r3) = ctx->r13;
L_80009384:
    // 0x80009384: jr          $ra
    // 0x80009388: nop

    return;
    // 0x80009388: nop

;}
RECOMP_FUNC void func_8064AA5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064AA5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064AA60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064AA64: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064AA68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064AA6C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064AA70: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064AA74: nop

    // 0x8064AA78: bc1fl       L_8064AAC0
    if (!c1cs) {
        // 0x8064AA7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064AAC0;
    }
    goto skip_0;
    // 0x8064AA7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064AA80: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064AA84: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064AA88: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8064AA8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064AA90: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064AA94: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8064AA98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064AA9C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8064AAA0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064AAA4: nop

    // 0x8064AAA8: bc1fl       L_8064AAC0
    if (!c1cs) {
        // 0x8064AAAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064AAC0;
    }
    goto skip_1;
    // 0x8064AAAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064AAB0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064AAB4: jal         0x8064AEA8
    // 0x8064AAB8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064AEA8(rdram, ctx);
        goto after_0;
    // 0x8064AAB8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064AABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064AAC0:
    // 0x8064AAC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064AAC4: jr          $ra
    // 0x8064AAC8: nop

    return;
    // 0x8064AAC8: nop

;}
RECOMP_FUNC void func_800113B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800113B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800113B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800113BC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800113C0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800113C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800113C8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800113CC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800113D0: jal         0x8001A7A0
    // 0x800113D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8001A7A0(rdram, ctx);
        goto after_0;
    // 0x800113D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800113D8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800113DC: addiu       $v1, $v1, -0x6D6C
    ctx->r3 = ADD32(ctx->r3, -0X6D6C);
    // 0x800113E0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800113E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800113E8: jal         0x8001AE64
    // 0x800113EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001AE64(rdram, ctx);
        goto after_1;
    // 0x800113EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800113F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800113F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800113F8: jr          $ra
    // 0x800113FC: nop

    return;
    // 0x800113FC: nop

;}
RECOMP_FUNC void func_8002A034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A034: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A038: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8002A03C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002A040: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8002A044: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8002A048: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002A04C: bne         $t6, $zero, L_8002A05C
    if (ctx->r14 != 0) {
        // 0x8002A050: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_8002A05C;
    }
    // 0x8002A050: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8002A054: b           L_8002A0C0
    // 0x8002A058: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
        goto L_8002A0C0;
    // 0x8002A058: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
L_8002A05C:
    // 0x8002A05C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002A060: jal         0x80053924
    // 0x8002A064: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x8002A064: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8002A068: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8002A06C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002A070: bne         $v0, $at, L_8002A0BC
    if (ctx->r2 != ctx->r1) {
        // 0x8002A074: lwc1        $f2, 0x2C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8002A0BC;
    }
    // 0x8002A074: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002A078: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002A07C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002A080: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8002A084: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8002A088: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002A08C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002A090: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002A094: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002A098: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8002A09C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8002A0A0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8002A0A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8002A0A8: add.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002A0AC: jal         0x8002A034
    // 0x8002A0B0: add.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f2.fl;
    func_8002A034(rdram, ctx);
        goto after_1;
    // 0x8002A0B0: add.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f2.fl;
    after_1:
    // 0x8002A0B4: b           L_8002A0C4
    // 0x8002A0B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8002A0C4;
    // 0x8002A0B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002A0BC:
    // 0x8002A0BC: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
L_8002A0C0:
    // 0x8002A0C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002A0C4:
    // 0x8002A0C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002A0C8: jr          $ra
    // 0x8002A0CC: nop

    return;
    // 0x8002A0CC: nop

;}
RECOMP_FUNC void func_80024550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024550: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80024554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024558: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x8002455C: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80024560: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80024564: lh          $a2, 0xA2($sp)
    ctx->r6 = MEM_H(ctx->r29, 0XA2);
    // 0x80024568: jal         0x800244DC
    // 0x8002456C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800244DC(rdram, ctx);
        goto after_0;
    // 0x8002456C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80024570: lw          $a0, 0x98($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X98);
    // 0x80024574: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80024578: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002457C: jal         0x800520E0
    // 0x80024580: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    func_800520E0(rdram, ctx);
        goto after_1;
    // 0x80024580: lw          $a3, 0xA4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA4);
    after_1:
    // 0x80024584: lh          $t6, 0xA2($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XA2);
    // 0x80024588: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x8002458C: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x80024590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024594: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x80024598: jr          $ra
    // 0x8002459C: nop

    return;
    // 0x8002459C: nop

;}
RECOMP_FUNC void func_804BBB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BBB80: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BBB84: lui         $a0, 0x804C
    ctx->r4 = S32(RELOC_HI16(191, 0X3DE0) << 16);
    // 0x804BBB88: addiu       $a0, $a0, -0x8F0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(191, 0X3DE0));
    // 0x804BBB8C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804BBB90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x804BBB94: addiu       $a1, $v0, 0x2A0
    ctx->r5 = ADD32(ctx->r2, 0X2A0);
    // 0x804BBB98: addiu       $a3, $v0, 0x2D0
    ctx->r7 = ADD32(ctx->r2, 0X2D0);
L_804BBB9C:
    // 0x804BBB9C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x804BBBA0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x804BBBA4: slti        $at, $t0, 0x2A
    ctx->r1 = SIGNED(ctx->r8) < 0X2A ? 1 : 0;
    // 0x804BBBA8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x804BBBAC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x804BBBB0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x804BBBB4: sw          $t6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r14;
    // 0x804BBBB8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x804BBBBC: sw          $t7, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r15;
    // 0x804BBBC0: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x804BBBC4: bne         $at, $zero, L_804BBB9C
    if (ctx->r1 != 0) {
        // 0x804BBBC8: sw          $t6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r14;
            goto L_804BBB9C;
    }
    // 0x804BBBC8: sw          $t6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r14;
    // 0x804BBBCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804BBBD0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_804BBBD4:
    // 0x804BBBD4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x804BBBD8: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x804BBBDC: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x804BBBE0: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x804BBBE4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x804BBBE8: bne         $at, $zero, L_804BBBD4
    if (ctx->r1 != 0) {
        // 0x804BBBEC: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_804BBBD4;
    }
    // 0x804BBBEC: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x804BBBF0: sh          $zero, 0x4($a3)
    MEM_H(0X4, ctx->r7) = 0;
    // 0x804BBBF4: lh          $v1, 0x4($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X4);
    // 0x804BBBF8: sh          $zero, 0xA($a3)
    MEM_H(0XA, ctx->r7) = 0;
    // 0x804BBBFC: sh          $zero, 0x10($a3)
    MEM_H(0X10, ctx->r7) = 0;
    // 0x804BBC00: sh          $v1, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r3;
    // 0x804BBC04: sh          $v1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r3;
    // 0x804BBC08: lh          $v1, 0xA($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XA);
    // 0x804BBC0C: addiu       $a2, $a3, 0x12
    ctx->r6 = ADD32(ctx->r7, 0X12);
    // 0x804BBC10: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x804BBC14: sh          $v1, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r3;
    // 0x804BBC18: sh          $v1, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r3;
    // 0x804BBC1C: lh          $v1, 0x10($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X10);
    // 0x804BBC20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804BBC24: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x804BBC28: sh          $v1, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r3;
    // 0x804BBC2C: sh          $v1, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r3;
    // 0x804BBC30: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
    // 0x804BBC34: lh          $v1, 0x4($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X4);
    // 0x804BBC38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BBC3C: addiu       $t8, $zero, -0x5
    ctx->r24 = ADD32(0, -0X5);
    // 0x804BBC40: sh          $v1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r3;
    // 0x804BBC44: sh          $v1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r3;
    // 0x804BBC48: swc1        $f0, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f0.u32l;
    // 0x804BBC4C: swc1        $f0, 0x364($v0)
    MEM_W(0X364, ctx->r2) = ctx->f0.u32l;
    // 0x804BBC50: sw          $t8, 0x350($v0)
    MEM_W(0X350, ctx->r2) = ctx->r24;
    // 0x804BBC54: sw          $zero, 0x358($v0)
    MEM_W(0X358, ctx->r2) = 0;
    // 0x804BBC58: sw          $zero, 0x370($v0)
    MEM_W(0X370, ctx->r2) = 0;
    // 0x804BBC5C: sw          $zero, 0x374($v0)
    MEM_W(0X374, ctx->r2) = 0;
    // 0x804BBC60: swc1        $f2, 0x368($v0)
    MEM_W(0X368, ctx->r2) = ctx->f2.u32l;
    // 0x804BBC64: swc1        $f2, 0x360($v0)
    MEM_W(0X360, ctx->r2) = ctx->f2.u32l;
    // 0x804BBC68: jr          $ra
    // 0x804BBC6C: swc1        $f4, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x804BBC6C: swc1        $f4, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_807A1FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1FCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A1FD0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807A1FD4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x807A1FD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A1FDC: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(844, 0X190) << 16);
    // 0x807A1FE0: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    // 0x807A1FE4: lwc1        $f4, 0x2060($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(844, 0X190));
    // 0x807A1FE8: lui         $a0, 0x807A
    ctx->r4 = S32(RELOC_HI16(844, 0X220) << 16);
    // 0x807A1FEC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x807A1FF0: ori         $a1, $a1, 0x1800
    ctx->r5 = ctx->r5 | 0X1800;
    // 0x807A1FF4: lw          $a3, 0x8($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X8);
    // 0x807A1FF8: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x807A1FFC: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x807A2000: addiu       $a0, $a0, 0x20F0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(844, 0X220));
    // 0x807A2004: jal         0x80046804
    // 0x807A2008: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x807A2008: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x807A200C: bne         $v0, $zero, L_807A201C
    if (ctx->r2 != 0) {
        // 0x807A2010: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_807A201C;
    }
    // 0x807A2010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807A2014: b           L_807A2028
    // 0x807A2018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A2028;
    // 0x807A2018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A201C:
    // 0x807A201C: jal         0x80044194
    // 0x807A2020: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80044194(rdram, ctx);
        goto after_1;
    // 0x807A2020: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x807A2024: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_807A2028:
    // 0x807A2028: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807A202C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A2030: jr          $ra
    // 0x807A2034: nop

    return;
    // 0x807A2034: nop

    // 0x807A2038: nop

    // 0x807A203C: nop

;}
RECOMP_FUNC void func_80423120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423120: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80423124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80423128: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8042312C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80423130: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80423134: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80423138: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8042313C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80423140: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80423144: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80423148: lw          $t0, 0x20($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X20);
    // 0x8042314C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80423150: jal         0x80077338
    // 0x80423154: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    func_80077338(rdram, ctx);
        goto after_0;
    // 0x80423154: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    after_0:
    // 0x80423158: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8042315C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80423160: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80423164: jal         0x8007711C
    // 0x80423168: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x80423168: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    after_1:
    // 0x8042316C: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80423170: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x80423174: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80423178: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8042317C: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80423180: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80423184: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80423188: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x8042318C: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x80423190: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x80423194: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80423198: or          $t3, $t6, $t9
    ctx->r11 = ctx->r14 | ctx->r25;
    // 0x8042319C: lbu         $t9, 0x2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2);
    // 0x804231A0: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x804231A4: or          $t8, $t3, $t7
    ctx->r24 = ctx->r11 | ctx->r15;
    // 0x804231A8: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x804231AC: or          $t5, $t8, $t4
    ctx->r13 = ctx->r24 | ctx->r12;
    // 0x804231B0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x804231B4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x804231B8: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x804231BC: lui         $t5, 0xF550
    ctx->r13 = S32(0XF550 << 16);
    // 0x804231C0: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x804231C4: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x804231C8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x804231CC: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x804231D0: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x804231D4: ori         $t2, $t2, 0x40FF
    ctx->r10 = ctx->r10 | 0X40FF;
    // 0x804231D8: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x804231DC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x804231E0: lui         $t3, 0x701
    ctx->r11 = S32(0X701 << 16);
    // 0x804231E4: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x804231E8: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x804231EC: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x804231F0: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x804231F4: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x804231F8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x804231FC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80423200: lui         $t3, 0x73F
    ctx->r11 = S32(0X73F << 16);
    // 0x80423204: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80423208: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8042320C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80423210: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80423214: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80423218: ori         $t3, $t3, 0xF200
    ctx->r11 = ctx->r11 | 0XF200;
    // 0x8042321C: lui         $t5, 0xF300
    ctx->r13 = S32(0XF300 << 16);
    // 0x80423220: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x80423224: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80423228: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8042322C: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80423230: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80423234: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80423238: lui         $t5, 0xF548
    ctx->r13 = S32(0XF548 << 16);
    // 0x8042323C: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80423240: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80423244: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80423248: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8042324C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80423250: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x80423254: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x80423258: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x8042325C: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80423260: ori         $t5, $t5, 0x800
    ctx->r13 = ctx->r13 | 0X800;
    // 0x80423264: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80423268: sw          $t3, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r11;
    // 0x8042326C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80423270: lui         $t8, 0x7
    ctx->r24 = S32(0X7 << 16);
    // 0x80423274: ori         $t8, $t8, 0xC0FC
    ctx->r24 = ctx->r24 | 0XC0FC;
    // 0x80423278: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8042327C: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80423280: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x80423284: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80423288: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8042328C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80423290: lui         $v1, 0x8042
    ctx->r3 = S32(RELOC_HI16(35, 0X30E8) << 16);
    // 0x80423294: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80423298: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8042329C: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x804232A0: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x804232A4: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x804232A8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x804232AC: addiu       $v1, $v1, 0x5AE8
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(35, 0X30E8));
    // 0x804232B0: addiu       $t8, $t0, 0xE0
    ctx->r24 = ADD32(ctx->r8, 0XE0);
    // 0x804232B4: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x804232B8: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x804232BC: sw          $v1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r3;
    // 0x804232C0: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x804232C4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x804232C8: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x804232CC: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x804232D0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x804232D4: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x804232D8: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x804232DC: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x804232E0: ori         $t6, $t6, 0x185F
    ctx->r14 = ctx->r14 | 0X185F;
    // 0x804232E4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x804232E8: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x804232EC: sw          $v1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r3;
    // 0x804232F0: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x804232F4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x804232F8: addiu       $t9, $t0, 0x1C0
    ctx->r25 = ADD32(ctx->r8, 0X1C0);
    // 0x804232FC: lui         $t5, 0x8042
    ctx->r13 = S32(RELOC_HI16(35, 0X3160) << 16);
    // 0x80423300: addiu       $t7, $t3, 0x8
    ctx->r15 = ADD32(ctx->r11, 0X8);
    // 0x80423304: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80423308: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8042330C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80423310: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80423314: addiu       $t5, $t5, 0x5B60
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(35, 0X3160));
    // 0x80423318: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x8042331C: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80423320: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x80423324: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80423328: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8042332C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80423330: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x80423334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80423338: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8042333C: jr          $ra
    // 0x80423340: nop

    return;
    // 0x80423340: nop

;}
RECOMP_FUNC void func_804A3C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A3C2C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x804A3C30: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x804A3C34: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x804A3C38: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x804A3C3C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x804A3C40: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x804A3C44: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x804A3C48: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x804A3C4C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x804A3C50: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x804A3C54: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x804A3C58: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x804A3C5C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x804A3C60: lwc1        $f28, 0x3C($a0)
    ctx->f28.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A3C64: addiu       $s0, $v0, 0x188
    ctx->r16 = ADD32(ctx->r2, 0X188);
    // 0x804A3C68: lwc1        $f26, 0x40($a0)
    ctx->f26.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A3C6C: bne         $s0, $zero, L_804A3C7C
    if (ctx->r16 != 0) {
        // 0x804A3C70: lh          $s1, 0x184($v0)
        ctx->r17 = MEM_H(ctx->r2, 0X184);
            goto L_804A3C7C;
    }
    // 0x804A3C70: lh          $s1, 0x184($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X184);
    // 0x804A3C74: b           L_804A3D1C
    // 0x804A3C78: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_804A3D1C;
    // 0x804A3C78: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_804A3C7C:
    // 0x804A3C7C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A3C80: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x804A3C84: beq         $s1, $zero, L_804A3CF8
    if (ctx->r17 == 0) {
        // 0x804A3C88: or          $s2, $s3, $zero
        ctx->r18 = ctx->r19 | 0;
            goto L_804A3CF8;
    }
    // 0x804A3C88: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_804A3C8C:
    // 0x804A3C8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x804A3C90: beq         $v0, $zero, L_804A3CF0
    if (ctx->r2 == 0) {
        // 0x804A3C94: nop
    
            goto L_804A3CF0;
    }
    // 0x804A3C94: nop

    // 0x804A3C98: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x804A3C9C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x804A3CA0: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x804A3CA4: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x804A3CA8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804A3CAC: bc1f        L_804A3CF0
    if (!c1cs) {
        // 0x804A3CB0: nop
    
            goto L_804A3CF0;
    }
    // 0x804A3CB0: nop

    // 0x804A3CB4: lwc1        $f14, 0x3C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x804A3CB8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x804A3CBC: jal         0x804A3C08
    // 0x804A3CC0: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_804A3C08(rdram, ctx);
        goto after_0;
    // 0x804A3CC0: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_0:
    // 0x804A3CC4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x804A3CC8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x804A3CCC: jal         0x804A3C08
    // 0x804A3CD0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_804A3C08(rdram, ctx);
        goto after_1;
    // 0x804A3CD0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_1:
    // 0x804A3CD4: add.s       $f2, $f0, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x804A3CD8: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x804A3CDC: nop

    // 0x804A3CE0: bc1f        L_804A3CF0
    if (!c1cs) {
        // 0x804A3CE4: nop
    
            goto L_804A3CF0;
    }
    // 0x804A3CE4: nop

    // 0x804A3CE8: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x804A3CEC: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_804A3CF0:
    // 0x804A3CF0: bne         $s1, $zero, L_804A3C8C
    if (ctx->r17 != 0) {
        // 0x804A3CF4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_804A3C8C;
    }
    // 0x804A3CF4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_804A3CF8:
    // 0x804A3CF8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x804A3CFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A3D00: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x804A3D04: c.le.s      $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f4.fl <= ctx->f24.fl;
    // 0x804A3D08: nop

    // 0x804A3D0C: bc1f        L_804A3D1C
    if (!c1cs) {
        // 0x804A3D10: nop
    
            goto L_804A3D1C;
    }
    // 0x804A3D10: nop

    // 0x804A3D14: b           L_804A3D1C
    // 0x804A3D18: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_804A3D1C;
    // 0x804A3D18: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_804A3D1C:
    // 0x804A3D1C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x804A3D20: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804A3D24: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804A3D28: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804A3D2C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804A3D30: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x804A3D34: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x804A3D38: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x804A3D3C: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x804A3D40: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x804A3D44: jr          $ra
    // 0x804A3D48: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x804A3D48: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_805A3874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3874: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x805A3878: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x805A387C: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x805A3880: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x805A3884: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x805A3888: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x805A388C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x805A3890: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x805A3894: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x805A3898: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x805A389C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x805A38A0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x805A38A4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x805A38A8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x805A38AC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x805A38B0: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x805A38B4: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x805A38B8: lwc1        $f22, 0x0($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X0);
    // 0x805A38BC: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x805A38C0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805A38C4: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x805A38C8: ori         $t8, $t8, 0xFC7E
    ctx->r24 = ctx->r24 | 0XFC7E;
    // 0x805A38CC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x805A38D0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A38D4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805A38D8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x805A38DC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A38E0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A38E4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x805A38E8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x805A38EC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x805A38F0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805A38F4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A38F8: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x805A38FC: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x805A3900: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A3904: addiu       $t7, $zero, 0x2CF0
    ctx->r15 = ADD32(0, 0X2CF0);
    // 0x805A3908: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x805A390C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x805A3910: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x805A3914: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x805A3918: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x805A391C: ori         $a1, $a1, 0x41C8
    ctx->r5 = ctx->r5 | 0X41C8;
    // 0x805A3920: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x805A3924: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A392C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x805A3930: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x805A3934: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x805A3938: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x805A393C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x805A3940: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x805A3944: lw          $t7, 0x24($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X24);
    // 0x805A3948: lw          $t6, 0x2C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X2C);
    // 0x805A394C: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x805A3950: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x805A3954: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x805A3958: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x805A395C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x805A3960: addiu       $v0, $v0, 0x3F
    ctx->r2 = ADD32(ctx->r2, 0X3F);
    // 0x805A3964: and         $v0, $v0, $at
    ctx->r2 = ctx->r2 & ctx->r1;
    // 0x805A3968: sra         $t8, $v0, 3
    ctx->r24 = S32(SIGNED(ctx->r2) >> 3);
    // 0x805A396C: div         $zero, $t9, $t8
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r24)));
    // 0x805A3970: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
    // 0x805A3974: lw          $t6, 0x30($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X30);
    // 0x805A3978: mflo        $s4
    ctx->r20 = lo;
    // 0x805A397C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3980: bne         $t8, $zero, L_805A398C
    if (ctx->r24 != 0) {
        // 0x805A3984: nop
    
            goto L_805A398C;
    }
    // 0x805A3984: nop

    // 0x805A3988: break       7
    do_break(2153396616);
L_805A398C:
    // 0x805A398C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805A3990: bne         $t8, $at, L_805A39A4
    if (ctx->r24 != ctx->r1) {
        // 0x805A3994: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805A39A4;
    }
    // 0x805A3994: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805A3998: bne         $t9, $at, L_805A39A4
    if (ctx->r25 != ctx->r1) {
        // 0x805A399C: nop
    
            goto L_805A39A4;
    }
    // 0x805A399C: nop

    // 0x805A39A0: break       6
    do_break(2153396640);
L_805A39A4:
    // 0x805A39A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805A39A8: subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // 0x805A39AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x805A39B0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x805A39B4: blez        $v1, L_805A3C60
    if (SIGNED(ctx->r3) <= 0) {
        // 0x805A39B8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_805A3C60;
    }
    // 0x805A39B8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x805A39BC: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(414, 0X1D80) << 16);
    // 0x805A39C0: lwc1        $f26, 0x5110($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(414, 0X1D80));
    // 0x805A39C4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x805A39C8: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x805A39CC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x805A39D0: ori         $fp, $fp, 0x400
    ctx->r30 = ctx->r30 | 0X400;
    // 0x805A39D4: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x805A39D8: lui         $s7, 0xB300
    ctx->r23 = S32(0XB300 << 16);
    // 0x805A39DC: lui         $s6, 0xB400
    ctx->r22 = S32(0XB400 << 16);
    // 0x805A39E0: lui         $s5, 0xE400
    ctx->r21 = S32(0XE400 << 16);
L_805A39E4:
    // 0x805A39E4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x805A39E8: addu        $t5, $s1, $s4
    ctx->r13 = ADD32(ctx->r17, ctx->r20);
    // 0x805A39EC: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x805A39F0: slt         $at, $t7, $s4
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x805A39F4: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    // 0x805A39F8: lw          $a2, 0x2C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X2C);
    // 0x805A39FC: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x805A3A00: andi        $t4, $t4, 0xFFF
    ctx->r12 = ctx->r12 & 0XFFF;
    // 0x805A3A04: beq         $at, $zero, L_805A3A10
    if (ctx->r1 == 0) {
        // 0x805A3A08: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_805A3A10;
    }
    // 0x805A3A08: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x805A3A0C: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
L_805A3A10:
    // 0x805A3A10: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x805A3A14: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x805A3A18: lui         $t1, 0x10
    ctx->r9 = S32(0X10 << 16);
    // 0x805A3A1C: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x805A3A20: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x805A3A24: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x805A3A28: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x805A3A2C: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x805A3A30: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x805A3A34: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x805A3A38: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x805A3A3C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805A3A40: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805A3A44: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x805A3A48: subu        $a3, $a2, $a1
    ctx->r7 = SUB32(ctx->r6, ctx->r5);
    // 0x805A3A4C: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x805A3A50: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805A3A54: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x805A3A58: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    // 0x805A3A5C: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x805A3A60: andi        $t7, $t9, 0x7
    ctx->r15 = ctx->r25 & 0X7;
    // 0x805A3A64: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x805A3A68: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x805A3A6C: sra         $a3, $a3, 3
    ctx->r7 = S32(SIGNED(ctx->r7) >> 3);
    // 0x805A3A70: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3A74: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A3A78: andi        $a3, $a3, 0x1FF
    ctx->r7 = ctx->r7 & 0X1FF;
    // 0x805A3A7C: sll         $a3, $a3, 9
    ctx->r7 = S32(ctx->r7 << 9);
    // 0x805A3A80: or          $t9, $t6, $t1
    ctx->r25 = ctx->r14 | ctx->r9;
    // 0x805A3A84: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x805A3A88: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x805A3A8C: or          $t7, $t9, $a3
    ctx->r15 = ctx->r25 | ctx->r7;
    // 0x805A3A90: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x805A3A94: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x805A3A98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x805A3A9C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x805A3AA0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A3AA8: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x805A3AAC: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x805A3AB0: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x805A3AB4: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x805A3AB8: andi        $t1, $t1, 0xFFF
    ctx->r9 = ctx->r9 & 0XFFF;
    // 0x805A3ABC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3AC0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x805A3AC4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805A3AC8: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x805A3ACC: sll         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9 << 12);
    // 0x805A3AD0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x805A3AD4: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x805A3AD8: andi        $t2, $t2, 0xFFF
    ctx->r10 = ctx->r10 & 0XFFF;
    // 0x805A3ADC: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x805A3AE0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x805A3AE4: or          $t6, $t8, $t2
    ctx->r14 = ctx->r24 | ctx->r10;
    // 0x805A3AE8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3AEC: or          $t7, $t9, $t4
    ctx->r15 = ctx->r25 | ctx->r12;
    // 0x805A3AF0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x805A3AF4: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A3AF8: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x805A3AFC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x805A3B00: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x805A3B04: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x805A3B08: lw          $t7, 0x14($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X14);
    // 0x805A3B0C: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x805A3B10: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3B14: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x805A3B18: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x805A3B1C: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x805A3B20: lui         $at, 0x10
    ctx->r1 = S32(0X10 << 16);
    // 0x805A3B24: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x805A3B28: or          $t8, $t7, $a3
    ctx->r24 = ctx->r15 | ctx->r7;
    // 0x805A3B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A3B30: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3B34: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x805A3B38: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x805A3B3C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x805A3B40: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x805A3B44: or          $t3, $s0, $zero
    ctx->r11 = ctx->r16 | 0;
    // 0x805A3B48: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805A3B4C: or          $t8, $t1, $t2
    ctx->r24 = ctx->r9 | ctx->r10;
    // 0x805A3B50: or          $t7, $t9, $t4
    ctx->r15 = ctx->r25 | ctx->r12;
    // 0x805A3B54: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x805A3B58: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x805A3B5C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x805A3B60: blez        $s4, L_805A3C50
    if (SIGNED(ctx->r20) <= 0) {
        // 0x805A3B64: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_805A3C50;
    }
    // 0x805A3B64: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_805A3B68:
    // 0x805A3B68: jal         0x80082730
    // 0x805A3B6C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    fsin(rdram, ctx);
        goto after_0;
    // 0x805A3B6C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x805A3B70: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x805A3B74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x805A3B78: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x805A3B7C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x805A3B80: nop

    // 0x805A3B84: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x805A3B88: nop

    // 0x805A3B8C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x805A3B90: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x805A3B94: mul.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x805A3B98: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x805A3B9C: nop

    // 0x805A3BA0: slti        $at, $a1, -0x1
    ctx->r1 = SIGNED(ctx->r5) < -0X1 ? 1 : 0;
    // 0x805A3BA4: bne         $at, $zero, L_805A3BB8
    if (ctx->r1 != 0) {
        // 0x805A3BA8: nop
    
            goto L_805A3BB8;
    }
    // 0x805A3BA8: nop

    // 0x805A3BAC: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x805A3BB0: bnel        $at, $zero, L_805A3C44
    if (ctx->r1 != 0) {
        // 0x805A3BB4: lwc1        $f18, 0x4($s2)
        ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
            goto L_805A3C44;
    }
    goto skip_0;
    // 0x805A3BB4: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    skip_0:
L_805A3BB8:
    // 0x805A3BB8: lw          $a3, 0x2C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X2C);
    // 0x805A3BBC: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x805A3BC0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3BC4: addiu       $t7, $a3, 0x1
    ctx->r15 = ADD32(ctx->r7, 0X1);
    // 0x805A3BC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x805A3BCC: sll         $t9, $v0, 5
    ctx->r25 = S32(ctx->r2 << 5);
    // 0x805A3BD0: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x805A3BD4: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x805A3BD8: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x805A3BDC: addiu       $t8, $s1, 0x1
    ctx->r24 = ADD32(ctx->r17, 0X1);
    // 0x805A3BE0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x805A3BE4: or          $t7, $t9, $s5
    ctx->r15 = ctx->r25 | ctx->r21;
    // 0x805A3BE8: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x805A3BEC: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x805A3BF0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x805A3BF4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x805A3BF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x805A3BFC: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x805A3C00: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x805A3C04: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x805A3C08: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x805A3C0C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x805A3C10: sll         $t6, $s1, 5
    ctx->r14 = S32(ctx->r17 << 5);
    // 0x805A3C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A3C18: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3C1C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x805A3C20: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x805A3C24: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x805A3C28: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x805A3C2C: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x805A3C30: sw          $s6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r22;
    // 0x805A3C34: sw          $fp, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r30;
    // 0x805A3C38: sw          $s7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r23;
    // 0x805A3C3C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3C40: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
L_805A3C44:
    // 0x805A3C44: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x805A3C48: bne         $s3, $s4, L_805A3B68
    if (ctx->r19 != ctx->r20) {
        // 0x805A3C4C: add.s       $f22, $f22, $f18
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f18.fl;
            goto L_805A3B68;
    }
    // 0x805A3C4C: add.s       $f22, $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f18.fl;
L_805A3C50:
    // 0x805A3C50: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x805A3C54: subu        $v0, $v0, $s4
    ctx->r2 = SUB32(ctx->r2, ctx->r20);
    // 0x805A3C58: bgtz        $v0, L_805A39E4
    if (SIGNED(ctx->r2) > 0) {
        // 0x805A3C5C: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_805A39E4;
    }
    // 0x805A3C5C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
L_805A3C60:
    // 0x805A3C60: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x805A3C64: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x805A3C68: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x805A3C6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A3C70: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x805A3C74: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x805A3C78: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
    // 0x805A3C7C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x805A3C80: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x805A3C84: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x805A3C88: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x805A3C8C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x805A3C90: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x805A3C94: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x805A3C98: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x805A3C9C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x805A3CA0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x805A3CA4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x805A3CA8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x805A3CAC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805A3CB0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805A3CB4: jr          $ra
    // 0x805A3CB8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x805A3CB8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_80455104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455104: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80455108: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045510C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80455110: lui         $a1, 0x8045
    ctx->r5 = S32(RELOC_HI16(98, 0X13914) << 16);
    // 0x80455114: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80455118: jal         0x804548E4
    // 0x8045511C: lw          $a1, 0x7CF4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13914));
    func_804548E4(rdram, ctx);
        goto after_0;
    // 0x8045511C: lw          $a1, 0x7CF4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(98, 0X13914));
    after_0:
    // 0x80455120: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80455124: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455128: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x8045512C: addu        $a0, $v1, $at
    ctx->r4 = ADD32(ctx->r3, ctx->r1);
    // 0x80455130: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455134: ori         $at, $at, 0x6DDC
    ctx->r1 = ctx->r1 | 0X6DDC;
    // 0x80455138: addu        $a1, $v1, $at
    ctx->r5 = ADD32(ctx->r3, ctx->r1);
    // 0x8045513C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455140: ori         $at, $at, 0x6DE0
    ctx->r1 = ctx->r1 | 0X6DE0;
    // 0x80455144: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80455148: addu        $a2, $v1, $at
    ctx->r6 = ADD32(ctx->r3, ctx->r1);
    // 0x8045514C: jal         0x804549D4
    // 0x80455150: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804549D4(rdram, ctx);
        goto after_1;
    // 0x80455150: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80455154: beq         $v0, $zero, L_8045517C
    if (ctx->r2 == 0) {
        // 0x80455158: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8045517C;
    }
    // 0x80455158: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8045515C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455160: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80455164: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80455168: sw          $t6, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r14;
    // 0x8045516C: jal         0x804457C0
    // 0x80455170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804457C0(rdram, ctx);
        goto after_2;
    // 0x80455170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80455174: jal         0x8045360C
    // 0x80455178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8045360C(rdram, ctx);
        goto after_3;
    // 0x80455178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8045517C:
    // 0x8045517C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80455180: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80455184: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80455188: jr          $ra
    // 0x8045518C: nop

    return;
    // 0x8045518C: nop

;}
RECOMP_FUNC void func_806D93B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D93B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D93B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806D93B8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x806D93BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D93C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D93C4: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x806D93C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D93CC: beq         $a1, $at, L_806D93E8
    if (ctx->r5 == ctx->r1) {
        // 0x806D93D0: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_806D93E8;
    }
    // 0x806D93D0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D93D4: addiu       $at, $zero, 0x6A
    ctx->r1 = ADD32(0, 0X6A);
    // 0x806D93D8: beq         $a1, $at, L_806D9420
    if (ctx->r5 == ctx->r1) {
        // 0x806D93DC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_806D9420;
    }
    // 0x806D93DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806D93E0: b           L_806D943C
    // 0x806D93E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D943C;
    // 0x806D93E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D93E8:
    // 0x806D93E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x806D93EC: beq         $a0, $zero, L_806D9404
    if (ctx->r4 == 0) {
        // 0x806D93F0: nop
    
            goto L_806D9404;
    }
    // 0x806D93F0: nop

    // 0x806D93F4: jal         0x800447C8
    // 0x806D93F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x806D93F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x806D93FC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806D9400: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_806D9404:
    // 0x806D9404: jal         0x8003E304
    // 0x806D9408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003E304(rdram, ctx);
        goto after_1;
    // 0x806D9408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D940C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x806D9410: jal         0x806D9064
    // 0x806D9414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D9064(rdram, ctx);
        goto after_2;
    // 0x806D9414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806D9418: b           L_806D9438
    // 0x806D941C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
        goto L_806D9438;
    // 0x806D941C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
L_806D9420:
    // 0x806D9420: sb          $t6, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r14;
    // 0x806D9424: jal         0x806D9100
    // 0x806D9428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D9100(rdram, ctx);
        goto after_3;
    // 0x806D9428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806D942C: jal         0x8004A73C
    // 0x806D9430: lw          $a0, 0x174($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X174);
    func_8004A73C(rdram, ctx);
        goto after_4;
    // 0x806D9430: lw          $a0, 0x174($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X174);
    after_4:
    // 0x806D9434: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
L_806D9438:
    // 0x806D9438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D943C:
    // 0x806D943C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D9440: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806D9444: jr          $ra
    // 0x806D9448: nop

    return;
    // 0x806D9448: nop

;}
RECOMP_FUNC void func_8005784C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005784C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057854: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80057858: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8005785C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80057860: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80057864: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x80057868: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8005786C: jal         0x80056934
    // 0x80057870: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_80056934(rdram, ctx);
        goto after_0;
    // 0x80057870: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_0:
    // 0x80057874: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80057878: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8005787C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80057880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057884: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80057888: jr          $ra
    // 0x8005788C: nop

    return;
    // 0x8005788C: nop

;}
RECOMP_FUNC void func_805E4BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4BB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805E4BBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E4BC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E4BC4: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x805E4BC8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x805E4BCC: lui         $t7, 0x805E
    ctx->r15 = S32(RELOC_HI16(486, 0XFA8) << 16);
    // 0x805E4BD0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x805E4BD4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805E4BD8: addiu       $t7, $t7, 0x50E8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(486, 0XFA8));
    // 0x805E4BDC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805E4BE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E4BE4: jal         0x805E4548
    // 0x805E4BE8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_805E4548(rdram, ctx);
        goto after_0;
    // 0x805E4BE8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_0:
    // 0x805E4BEC: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805E4BF0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805E4BF4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805E4BF8: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x805E4BFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805E4C00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805E4C04: jal         0x80048378
    // 0x805E4C08: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x805E4C08: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    after_1:
    // 0x805E4C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E4C10: jal         0x80045A34
    // 0x805E4C14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x805E4C14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x805E4C18: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x805E4C1C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x805E4C20: sh          $t1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r9;
    // 0x805E4C24: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x805E4C28: lui         $t3, 0x805E
    ctx->r11 = S32(RELOC_HI16(486, 0XA50) << 16);
    // 0x805E4C2C: addiu       $t3, $t3, 0x4B90
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(486, 0XA50));
    // 0x805E4C30: sh          $zero, 0xC($t2)
    MEM_H(0XC, ctx->r10) = 0;
    // 0x805E4C34: sw          $t3, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r11;
    // 0x805E4C38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E4C3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E4C40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805E4C44: jr          $ra
    // 0x805E4C48: nop

    return;
    // 0x805E4C48: nop

;}
RECOMP_FUNC void func_8000AC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AC70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000AC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AC78: jal         0x8000A25C
    // 0x8000AC7C: nop

    func_8000A25C(rdram, ctx);
        goto after_0;
    // 0x8000AC7C: nop

    after_0:
    // 0x8000AC80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AC84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AC88: jr          $ra
    // 0x8000AC8C: nop

    return;
    // 0x8000AC8C: nop

;}
RECOMP_FUNC void func_80462988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046298C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80462990: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x80462994: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X3938) << 16);
    // 0x80462998: addiu       $t8, $t8, 0x3EC8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(122, 0X3938));
    // 0x8046299C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804629A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804629A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804629A8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804629AC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804629B0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804629B4: beql        $v1, $zero, L_804629EC
    if (ctx->r3 == 0) {
        // 0x804629B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804629EC;
    }
    goto skip_0;
    // 0x804629B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804629BC: jalr        $v1
    // 0x804629C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804629C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804629C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804629C8: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804629CC: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804629D0: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804629D4: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804629D8: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x804629DC: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804629E0: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x804629E4: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x804629E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804629EC:
    // 0x804629EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804629F0: jr          $ra
    // 0x804629F4: nop

    return;
    // 0x804629F4: nop

;}
RECOMP_FUNC void func_805849CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805849CC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805849D0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805849D4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805849D8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805849DC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805849E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805849E4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805849E8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805849EC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805849F0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805849F4: jr          $ra
    // 0x805849F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805849F8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8004DDD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DDD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004DDD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004DDDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004DDE0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004DDE4: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004DDE8: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8004DDEC: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8004DDF0: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004DDF4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004DDF8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004DDFC: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x8004DE00: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004DE04: beql        $v0, $zero, L_8004DE60
    if (ctx->r2 == 0) {
        // 0x8004DE08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DE60;
    }
    goto skip_0;
    // 0x8004DE08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004DE0C: beql        $v0, $at, L_8004DE60
    if (ctx->r2 == ctx->r1) {
        // 0x8004DE10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DE60;
    }
    goto skip_1;
    // 0x8004DE10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004DE14: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004DE18: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004DE1C: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004DE20: beq         $v0, $at, L_8004DE5C
    if (ctx->r2 == ctx->r1) {
        // 0x8004DE24: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004DE5C;
    }
    // 0x8004DE24: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004DE28: beq         $v0, $at, L_8004DE5C
    if (ctx->r2 == ctx->r1) {
        // 0x8004DE2C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004DE5C;
    }
    // 0x8004DE2C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004DE30: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8004DE34: jal         0x8004B3F8
    // 0x8004DE38: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8004B3F8(rdram, ctx);
        goto after_0;
    // 0x8004DE38: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004DE3C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DE40: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8004DE44: lbu         $t1, 0x14($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X14);
    // 0x8004DE48: beql        $t1, $zero, L_8004DE60
    if (ctx->r9 == 0) {
        // 0x8004DE4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DE60;
    }
    goto skip_2;
    // 0x8004DE4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8004DE50: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004DE54: ori         $t3, $t2, 0xF00
    ctx->r11 = ctx->r10 | 0XF00;
    // 0x8004DE58: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
L_8004DE5C:
    // 0x8004DE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004DE60:
    // 0x8004DE60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004DE64: jr          $ra
    // 0x8004DE68: nop

    return;
    // 0x8004DE68: nop

;}
RECOMP_FUNC void func_8001BA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA50: bnel        $a0, $zero, L_8001BA64
    if (ctx->r4 != 0) {
        // 0x8001BA54: lw          $v0, 0x40($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X40);
            goto L_8001BA64;
    }
    goto skip_0;
    // 0x8001BA54: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    skip_0:
    // 0x8001BA58: jr          $ra
    // 0x8001BA5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BA5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BA60: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
L_8001BA64:
    // 0x8001BA64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001BA68: beq         $v0, $at, L_8001BA78
    if (ctx->r2 == ctx->r1) {
        // 0x8001BA6C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8001BA78;
    }
    // 0x8001BA6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001BA70: bnel        $v0, $at, L_8001BA84
    if (ctx->r2 != ctx->r1) {
        // 0x8001BA74: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001BA84;
    }
    goto skip_1;
    // 0x8001BA74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_8001BA78:
    // 0x8001BA78: jr          $ra
    // 0x8001BA7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8001BA7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BA80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001BA84:
    // 0x8001BA84: jr          $ra
    // 0x8001BA88: nop

    return;
    // 0x8001BA88: nop

    // 0x8001BA8C: nop

;}
RECOMP_FUNC void func_8000859C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000859C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800085A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800085A4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800085A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800085AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800085B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800085B4: jal         0x800073BC
    // 0x800085B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800073BC(rdram, ctx);
        goto after_0;
    // 0x800085B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800085BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800085C0: jal         0x8000744C
    // 0x800085C4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8000744C(rdram, ctx);
        goto after_1;
    // 0x800085C4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x800085C8: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800085CC: addiu       $a2, $a2, 0x4D10
    ctx->r6 = ADD32(ctx->r6, 0X4D10);
    // 0x800085D0: lw          $t6, 0x12C8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X12C8);
    // 0x800085D4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800085D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800085DC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800085E0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800085E4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800085E8: addu        $v1, $a2, $t7
    ctx->r3 = ADD32(ctx->r6, ctx->r15);
    // 0x800085EC: lw          $t8, 0x12DC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X12DC);
    // 0x800085F0: sll         $t1, $a3, 4
    ctx->r9 = S32(ctx->r7 << 4);
    // 0x800085F4: addiu       $v1, $v1, 0x12CC
    ctx->r3 = ADD32(ctx->r3, 0X12CC);
    // 0x800085F8: bne         $t8, $at, L_80008604
    if (ctx->r24 != ctx->r1) {
        // 0x800085FC: addu        $a1, $v0, $t1
        ctx->r5 = ADD32(ctx->r2, ctx->r9);
            goto L_80008604;
    }
    // 0x800085FC: addu        $a1, $v0, $t1
    ctx->r5 = ADD32(ctx->r2, ctx->r9);
    // 0x80008600: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
L_80008604:
    // 0x80008604: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80008608: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x8000860C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80008610: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80008614: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80008618: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x8000861C: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80008620: sw          $t2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r10;
    // 0x80008624: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x80008628: addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
    // 0x8000862C: and         $a0, $a0, $at
    ctx->r4 = ctx->r4 & ctx->r1;
    // 0x80008630: sw          $a0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r4;
    // 0x80008634: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x80008638: lw          $t3, 0x10($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X10);
    // 0x8000863C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80008640: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80008644: lb          $t4, 0x18($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X18);
    // 0x80008648: sb          $a3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r7;
    // 0x8000864C: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x80008650: lw          $t5, 0x12C8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X12C8);
    // 0x80008654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000865C: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x80008660: jr          $ra
    // 0x80008664: sw          $t6, 0x12C8($a2)
    MEM_W(0X12C8, ctx->r6) = ctx->r14;
    return;
    // 0x80008664: sw          $t6, 0x12C8($a2)
    MEM_W(0X12C8, ctx->r6) = ctx->r14;
;}
RECOMP_FUNC void func_804609B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804609B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804609B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804609BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804609C0: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804609C4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39C0) << 16);
    // 0x804609C8: lwc1        $f6, 0x3F50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39C0));
    // 0x804609CC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x804609D0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39C4) << 16);
    // 0x804609D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804609D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804609DC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x804609E0: lwc1        $f10, 0x3F54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39C4));
    // 0x804609E4: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x804609E8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39CC) << 16);
    // 0x804609EC: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x804609F0: nop

    // 0x804609F4: bc1f        L_80460A14
    if (!c1cs) {
        // 0x804609F8: nop
    
            goto L_80460A14;
    }
    // 0x804609F8: nop

    // 0x804609FC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39C8) << 16);
    // 0x80460A00: lwc1        $f16, 0x3F58($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39C8));
    // 0x80460A04: sub.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80460A08: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80460A0C: b           L_80460A3C
    // 0x80460A10: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
        goto L_80460A3C;
    // 0x80460A10: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
L_80460A14:
    // 0x80460A14: lwc1        $f4, 0x3F5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39CC));
    // 0x80460A18: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39D0) << 16);
    // 0x80460A1C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80460A20: nop

    // 0x80460A24: bc1f        L_80460A3C
    if (!c1cs) {
        // 0x80460A28: nop
    
            goto L_80460A3C;
    }
    // 0x80460A28: nop

    // 0x80460A2C: lwc1        $f6, 0x3F60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39D0));
    // 0x80460A30: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80460A34: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80460A38: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
L_80460A3C:
    // 0x80460A3C: jal         0x80082730
    // 0x80460A40: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    fsin(rdram, ctx);
        goto after_0;
    // 0x80460A40: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_0:
    // 0x80460A44: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80460A48: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80460A4C: jal         0x80082730
    // 0x80460A50: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    fsin(rdram, ctx);
        goto after_1;
    // 0x80460A50: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80460A54: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80460A58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80460A5C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80460A60: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80460A64: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80460A68: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80460A6C: jal         0x8008D250
    // 0x80460A70: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    fcos(rdram, ctx);
        goto after_2;
    // 0x80460A70: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80460A74: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80460A78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80460A7C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80460A80: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80460A84: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80460A88: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80460A8C: addiu       $a0, $a1, 0xC4
    ctx->r4 = ADD32(ctx->r5, 0XC4);
    // 0x80460A90: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80460A94: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80460A98: lwc1        $f6, 0x3C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80460A9C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80460AA0: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80460AA4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80460AA8: lwc1        $f18, 0x40($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X40);
    // 0x80460AAC: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80460AB0: jal         0x80460954
    // 0x80460AB4: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    func_80460954(rdram, ctx);
        goto after_3;
    // 0x80460AB4: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    after_3:
    // 0x80460AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80460ABC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80460AC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80460AC4: jr          $ra
    // 0x80460AC8: nop

    return;
    // 0x80460AC8: nop

;}
RECOMP_FUNC void func_8004434C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004434C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80044350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044354: lh          $t6, 0x3C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X3C);
    // 0x80044358: addiu       $a3, $a0, 0x34
    ctx->r7 = ADD32(ctx->r4, 0X34);
    // 0x8004435C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80044360: blez        $t6, L_800443D8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80044364: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800443D8;
    }
    // 0x80044364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80044368: lw          $v1, 0x10($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X10);
    // 0x8004436C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80044370: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
L_80044374:
    // 0x80044374: beql        $a2, $zero, L_800443C4
    if (ctx->r6 == 0) {
        // 0x80044378: lh          $t1, 0x8($a1)
        ctx->r9 = MEM_H(ctx->r5, 0X8);
            goto L_800443C4;
    }
    goto skip_0;
    // 0x80044378: lh          $t1, 0x8($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X8);
    skip_0:
    // 0x8004437C: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x80044380: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80044384: bnel        $a0, $t8, L_800443C4
    if (ctx->r4 != ctx->r24) {
        // 0x80044388: lh          $t1, 0x8($a1)
        ctx->r9 = MEM_H(ctx->r5, 0X8);
            goto L_800443C4;
    }
    goto skip_1;
    // 0x80044388: lh          $t1, 0x8($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X8);
    skip_1:
    // 0x8004438C: lh          $a1, 0x17E($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X17E);
    // 0x80044390: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80044394: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80044398: jal         0x80043D0C
    // 0x8004439C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80043D0C(rdram, ctx);
        goto after_0;
    // 0x8004439C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800443A0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800443A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800443A8: lh          $t9, 0x6($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X6);
    // 0x800443AC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800443B0: jal         0x80044214
    // 0x800443B4: sh          $t0, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r8;
    func_80044214(rdram, ctx);
        goto after_1;
    // 0x800443B4: sh          $t0, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r8;
    after_1:
    // 0x800443B8: b           L_800443DC
    // 0x800443BC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_800443DC;
    // 0x800443BC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800443C0: lh          $t1, 0x8($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X8);
L_800443C4:
    // 0x800443C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800443C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800443CC: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800443D0: bnel        $at, $zero, L_80044374
    if (ctx->r1 != 0) {
        // 0x800443D4: lw          $a2, 0x0($v1)
        ctx->r6 = MEM_W(ctx->r3, 0X0);
            goto L_80044374;
    }
    goto skip_2;
    // 0x800443D4: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    skip_2:
L_800443D8:
    // 0x800443D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800443DC:
    // 0x800443DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800443E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800443E4: jr          $ra
    // 0x800443E8: nop

    return;
    // 0x800443E8: nop

;}
RECOMP_FUNC void func_80051EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051EC8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80051ECC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80051ED0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80051ED4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80051ED8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80051EDC: jr          $ra
    // 0x80051EE0: lw          $v0, 0x5AD4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5AD4);
    return;
    // 0x80051EE0: lw          $v0, 0x5AD4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5AD4);
;}
RECOMP_FUNC void func_80452768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045276C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452770: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80452774: jal         0x804525A8
    // 0x80452778: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_804525A8(rdram, ctx);
        goto after_0;
    // 0x80452778: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
    // 0x8045277C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452784: jr          $ra
    // 0x80452788: nop

    return;
    // 0x80452788: nop

;}
RECOMP_FUNC void func_80062818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062818: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006281C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80062820: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80062824: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80062828: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006282C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062830: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062834: lh          $s2, 0x184($a0)
    ctx->r18 = MEM_H(ctx->r4, 0X184);
    // 0x80062838: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8006283C: addiu       $s1, $a0, 0x188
    ctx->r17 = ADD32(ctx->r4, 0X188);
    // 0x80062840: beq         $s2, $zero, L_800628C4
    if (ctx->r18 == 0) {
        // 0x80062844: lui         $s4, 0x800A
        ctx->r20 = S32(0X800A << 16);
            goto L_800628C4;
    }
    // 0x80062844: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x80062848: addiu       $s4, $s4, 0x6500
    ctx->r20 = ADD32(ctx->r20, 0X6500);
L_8006284C:
    // 0x8006284C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80062850: beq         $s0, $zero, L_800628BC
    if (ctx->r16 == 0) {
        // 0x80062854: nop
    
            goto L_800628BC;
    }
    // 0x80062854: nop

    // 0x80062858: lw          $v0, 0x174($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174);
    // 0x8006285C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80062860: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80062864: beq         $v0, $zero, L_800628BC
    if (ctx->r2 == 0) {
        // 0x80062868: sra         $s2, $s2, 16
        ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
            goto L_800628BC;
    }
    // 0x80062868: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8006286C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80062870: bne         $s3, $t6, L_800628BC
    if (ctx->r19 != ctx->r14) {
        // 0x80062874: nop
    
            goto L_800628BC;
    }
    // 0x80062874: nop

    // 0x80062878: jal         0x80049018
    // 0x8006287C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8006287C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80062880: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80062884: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80062888: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x8006288C: lw          $t7, 0x174($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X174);
    // 0x80062890: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80062894: lw          $v1, 0x0($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X0);
    // 0x80062898: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x8006289C: lw          $t8, 0x70($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X70);
    // 0x800628A0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800628A4: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800628A8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800628AC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800628B0: nop

    // 0x800628B4: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800628B8: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
L_800628BC:
    // 0x800628BC: bne         $s2, $zero, L_8006284C
    if (ctx->r18 != 0) {
        // 0x800628C0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8006284C;
    }
    // 0x800628C0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800628C4:
    // 0x800628C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800628C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800628CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800628D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800628D4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800628D8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800628DC: jr          $ra
    // 0x800628E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800628E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8004FEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FEB4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8004FEB8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8004FEBC: swc1        $f12, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f12.u32l;
    // 0x8004FEC0: jr          $ra
    // 0x8004FEC4: swc1        $f14, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x8004FEC4: swc1        $f14, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80449318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044931C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449320: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80449324: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80449328: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8044932C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14068) << 16);
    // 0x80449330: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80449334: nop

    // 0x80449338: bc1f        L_80449368
    if (!c1cs) {
        // 0x8044933C: nop
    
            goto L_80449368;
    }
    // 0x8044933C: nop

    // 0x80449340: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80449344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449348: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8044934C: beql        $v0, $t6, L_804494B8
    if (ctx->r2 == ctx->r14) {
        // 0x80449350: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804494B8;
    }
    goto skip_0;
    // 0x80449350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80449354: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80449358: jal         0x80445904
    // 0x8044935C: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    func_80445904(rdram, ctx);
        goto after_0;
    // 0x8044935C: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    after_0:
    // 0x80449360: b           L_804494B8
    // 0x80449364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804494B8;
    // 0x80449364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449368:
    // 0x80449368: lwc1        $f6, -0x7BB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14068));
    // 0x8044936C: lui         $at, 0x4425
    ctx->r1 = S32(0X4425 << 16);
    // 0x80449370: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80449374: nop

    // 0x80449378: bc1fl       L_804493A8
    if (!c1cs) {
        // 0x8044937C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_804493A8;
    }
    goto skip_1;
    // 0x8044937C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x80449380: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x80449384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449388: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8044938C: beql        $v0, $t7, L_804494B8
    if (ctx->r2 == ctx->r15) {
        // 0x80449390: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804494B8;
    }
    goto skip_2;
    // 0x80449390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80449394: jal         0x80445904
    // 0x80449398: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    func_80445904(rdram, ctx);
        goto after_1;
    // 0x80449398: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    after_1:
    // 0x8044939C: b           L_804494B8
    // 0x804493A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804494B8;
    // 0x804493A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804493A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_804493A8:
    // 0x804493A8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1406C) << 16);
    // 0x804493AC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x804493B0: nop

    // 0x804493B4: bc1f        L_804493E0
    if (!c1cs) {
        // 0x804493B8: nop
    
            goto L_804493E0;
    }
    // 0x804493B8: nop

    // 0x804493BC: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x804493C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804493C4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x804493C8: beql        $v0, $t8, L_804494B8
    if (ctx->r2 == ctx->r24) {
        // 0x804493CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804494B8;
    }
    goto skip_3;
    // 0x804493CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x804493D0: jal         0x80445904
    // 0x804493D4: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    func_80445904(rdram, ctx);
        goto after_2;
    // 0x804493D4: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    after_2:
    // 0x804493D8: b           L_804494B8
    // 0x804493DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804494B8;
    // 0x804493DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804493E0:
    // 0x804493E0: lwc1        $f10, -0x7BB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1406C));
    // 0x804493E4: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x804493E8: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x804493EC: nop

    // 0x804493F0: bc1fl       L_80449420
    if (!c1cs) {
        // 0x804493F4: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80449420;
    }
    goto skip_4;
    // 0x804493F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_4:
    // 0x804493F8: lw          $t9, 0x14($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X14);
    // 0x804493FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449400: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80449404: beql        $v0, $t9, L_804494B8
    if (ctx->r2 == ctx->r25) {
        // 0x80449408: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804494B8;
    }
    goto skip_5;
    // 0x80449408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8044940C: jal         0x80445904
    // 0x80449410: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    func_80445904(rdram, ctx);
        goto after_3;
    // 0x80449410: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    after_3:
    // 0x80449414: b           L_804494B8
    // 0x80449418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804494B8;
    // 0x80449418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044941C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80449420:
    // 0x80449420: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14070) << 16);
    // 0x80449424: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80449428: nop

    // 0x8044942C: bc1f        L_80449458
    if (!c1cs) {
        // 0x80449430: nop
    
            goto L_80449458;
    }
    // 0x80449430: nop

    // 0x80449434: lw          $t0, 0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XC);
    // 0x80449438: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8044943C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80449440: beql        $v0, $t0, L_804494B8
    if (ctx->r2 == ctx->r8) {
        // 0x80449444: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804494B8;
    }
    goto skip_6;
    // 0x80449444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x80449448: jal         0x80445904
    // 0x8044944C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    func_80445904(rdram, ctx);
        goto after_4;
    // 0x8044944C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    after_4:
    // 0x80449450: b           L_804494B8
    // 0x80449454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804494B8;
    // 0x80449454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449458:
    // 0x80449458: lwc1        $f18, -0x7BB0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14070));
    // 0x8044945C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80449460: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x80449464: nop

    // 0x80449468: bc1fl       L_80449498
    if (!c1cs) {
        // 0x8044946C: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80449498;
    }
    goto skip_7;
    // 0x8044946C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_7:
    // 0x80449470: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80449474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8044947C: beql        $v0, $t1, L_804494B8
    if (ctx->r2 == ctx->r9) {
        // 0x80449480: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804494B8;
    }
    goto skip_8;
    // 0x80449480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80449484: jal         0x80445904
    // 0x80449488: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    func_80445904(rdram, ctx);
        goto after_5;
    // 0x80449488: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    after_5:
    // 0x8044948C: b           L_804494B8
    // 0x80449490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804494B8;
    // 0x80449490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80449494: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80449498:
    // 0x80449498: nop

    // 0x8044949C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x804494A0: nop

    // 0x804494A4: bc1fl       L_804494B8
    if (!c1cs) {
        // 0x804494A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804494B8;
    }
    goto skip_9;
    // 0x804494A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x804494AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804494B0: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x804494B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804494B8:
    // 0x804494B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804494BC: jr          $ra
    // 0x804494C0: nop

    return;
    // 0x804494C0: nop

;}
RECOMP_FUNC void func_80065414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065414: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80065418: addiu       $v0, $v0, 0x65CC
    ctx->r2 = ADD32(ctx->r2, 0X65CC);
    // 0x8006541C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80065420: lui         $at, 0x5D58
    ctx->r1 = S32(0X5D58 << 16);
    // 0x80065424: ori         $at, $at, 0x8B65
    ctx->r1 = ctx->r1 | 0X8B65;
    // 0x80065428: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006542C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80065430: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80065434: mflo        $t7
    ctx->r15 = lo;
    // 0x80065438: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8006543C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80065440: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80065444: bgez        $t9, L_8006545C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80065448: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_8006545C;
    }
    // 0x80065448: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8006544C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80065450: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80065454: nop

    // 0x80065458: add.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f6.d + ctx->f8.d;
L_8006545C:
    // 0x8006545C: lui         $at, 0x3DF0
    ctx->r1 = S32(0X3DF0 << 16);
    // 0x80065460: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80065464: nop

    // 0x80065468: mul.d       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8006546C: jr          $ra
    // 0x80065470: nop

    return;
    // 0x80065470: nop

;}
RECOMP_FUNC void func_8052D8A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052D8A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8052D8AC: lwc1        $f0, 0xF1C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XF1C);
    // 0x8052D8B0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8052D8B4: nop

    // 0x8052D8B8: bc1fl       L_8052D8D8
    if (!c1cs) {
        // 0x8052D8BC: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_8052D8D8;
    }
    goto skip_0;
    // 0x8052D8BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x8052D8C0: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8052D8C4: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x8052D8C8: nop

    // 0x8052D8CC: bc1tl       L_8052D8FC
    if (c1cs) {
        // 0x8052D8D0: lw          $v0, 0xF18($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XF18);
            goto L_8052D8FC;
    }
    goto skip_1;
    // 0x8052D8D0: lw          $v0, 0xF18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XF18);
    skip_1:
    // 0x8052D8D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_8052D8D8:
    // 0x8052D8D8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8052D8DC: bc1fl       L_8052D94C
    if (!c1cs) {
        // 0x8052D8E0: sw          $zero, 0xF24($a1)
        MEM_W(0XF24, ctx->r5) = 0;
            goto L_8052D94C;
    }
    goto skip_2;
    // 0x8052D8E0: sw          $zero, 0xF24($a1)
    MEM_W(0XF24, ctx->r5) = 0;
    skip_2:
    // 0x8052D8E4: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8052D8E8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8052D8EC: nop

    // 0x8052D8F0: bc1fl       L_8052D94C
    if (!c1cs) {
        // 0x8052D8F4: sw          $zero, 0xF24($a1)
        MEM_W(0XF24, ctx->r5) = 0;
            goto L_8052D94C;
    }
    goto skip_3;
    // 0x8052D8F4: sw          $zero, 0xF24($a1)
    MEM_W(0XF24, ctx->r5) = 0;
    skip_3:
    // 0x8052D8F8: lw          $v0, 0xF18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XF18);
L_8052D8FC:
    // 0x8052D8FC: bne         $v0, $zero, L_8052D940
    if (ctx->r2 != 0) {
        // 0x8052D900: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_8052D940;
    }
    // 0x8052D900: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8052D904: lw          $v0, 0xF24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XF24);
    // 0x8052D908: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(330, 0X16E0) << 16);
    // 0x8052D90C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8052D910: beq         $at, $zero, L_8052D938
    if (ctx->r1 == 0) {
        // 0x8052D914: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_8052D938;
    }
    // 0x8052D914: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8052D918: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8052D91C: sw          $t6, 0xF24($a1)
    MEM_W(0XF24, ctx->r5) = ctx->r14;
    // 0x8052D920: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8052D924: lh          $t9, -0x2350($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(330, 0X16E0));
    // 0x8052D928: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8052D92C: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x8052D930: jr          $ra
    // 0x8052D934: sw          $t0, 0xF18($a1)
    MEM_W(0XF18, ctx->r5) = ctx->r8;
    return;
    // 0x8052D934: sw          $t0, 0xF18($a1)
    MEM_W(0XF18, ctx->r5) = ctx->r8;
L_8052D938:
    // 0x8052D938: jr          $ra
    // 0x8052D93C: sw          $zero, 0xF24($a1)
    MEM_W(0XF24, ctx->r5) = 0;
    return;
    // 0x8052D93C: sw          $zero, 0xF24($a1)
    MEM_W(0XF24, ctx->r5) = 0;
L_8052D940:
    // 0x8052D940: jr          $ra
    // 0x8052D944: sw          $t1, 0xF18($a1)
    MEM_W(0XF18, ctx->r5) = ctx->r9;
    return;
    // 0x8052D944: sw          $t1, 0xF18($a1)
    MEM_W(0XF18, ctx->r5) = ctx->r9;
    // 0x8052D948: sw          $zero, 0xF24($a1)
    MEM_W(0XF24, ctx->r5) = 0;
L_8052D94C:
    // 0x8052D94C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8052D950: sw          $t2, 0xF20($a1)
    MEM_W(0XF20, ctx->r5) = ctx->r10;
    // 0x8052D954: jr          $ra
    // 0x8052D958: nop

    return;
    // 0x8052D958: nop

;}
RECOMP_FUNC void func_80708E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80708E64: jr          $ra
    // 0x80708E68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80708E68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8043B4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B4B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043B4B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043B4B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043B4BC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043B4C0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11E4) << 16);
    // 0x8043B4C4: lwc1        $f4, -0x47BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11E4));
    // 0x8043B4C8: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8043B4CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043B4D0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11E8) << 16);
    // 0x8043B4D4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8043B4D8: nop

    // 0x8043B4DC: bc1fl       L_8043B4F8
    if (!c1cs) {
        // 0x8043B4E0: lui         $at, 0x42FE
        ctx->r1 = S32(0X42FE << 16);
            goto L_8043B4F8;
    }
    goto skip_0;
    // 0x8043B4E0: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    skip_0:
    // 0x8043B4E4: lwc1        $f6, -0x47B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11E8));
    // 0x8043B4E8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8043B4EC: nop

    // 0x8043B4F0: bc1t        L_8043B574
    if (c1cs) {
        // 0x8043B4F4: lui         $at, 0x42FE
        ctx->r1 = S32(0X42FE << 16);
            goto L_8043B574;
    }
    // 0x8043B4F4: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
L_8043B4F8:
    // 0x8043B4F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043B4FC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8043B500: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8043B504: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8043B508: nop

    // 0x8043B50C: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8043B510: jal         0x80065954
    // 0x8043B514: nop

    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8043B514: nop

    after_0:
    // 0x8043B518: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8043B51C: lh          $t8, 0x1F0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1F0);
    // 0x8043B520: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8043B524: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8043B528: bnel        $t8, $at, L_8043B554
    if (ctx->r24 != ctx->r1) {
        // 0x8043B52C: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_8043B554;
    }
    goto skip_1;
    // 0x8043B52C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x8043B530: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8043B534: jal         0x80067D5C
    // 0x8043B538: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x8043B538: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8043B53C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8043B540: jal         0x80067F78
    // 0x8043B544: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_2;
    // 0x8043B544: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8043B548: b           L_8043B57C
    // 0x8043B54C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8043B57C;
    // 0x8043B54C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8043B550: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_8043B554:
    // 0x8043B554: jal         0x80067D5C
    // 0x8043B558: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x8043B558: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8043B55C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8043B560: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8043B564: jal         0x800678F0
    // 0x8043B568: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x8043B568: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x8043B56C: b           L_8043B580
    // 0x8043B570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043B580;
    // 0x8043B570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043B574:
    // 0x8043B574: jal         0x8043A6B4
    // 0x8043B578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043A6B4(rdram, ctx);
        goto after_5;
    // 0x8043B578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8043B57C:
    // 0x8043B57C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043B580:
    // 0x8043B580: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043B584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043B588: jr          $ra
    // 0x8043B58C: nop

    return;
    // 0x8043B58C: nop

;}
RECOMP_FUNC void func_80460C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460C80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460C84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460C88: jal         0x80045A34
    // 0x80460C8C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80460C8C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80460C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460C98: jr          $ra
    // 0x80460C9C: nop

    return;
    // 0x80460C9C: nop

;}
RECOMP_FUNC void func_806703E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806703E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806703E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806703EC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806703F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806703F4: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x806703F8: jal         0x80067878
    // 0x806703FC: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x806703FC: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    after_0:
    // 0x80670400: jal         0x80045BD8
    // 0x80670404: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80670404: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80670408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067040C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80670410: jr          $ra
    // 0x80670414: nop

    return;
    // 0x80670414: nop

;}
RECOMP_FUNC void func_804421FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804421FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80442200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80442204: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80442208: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8044220C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80442210: lui         $t8, 0x8044
    ctx->r24 = S32(RELOC_HI16(95, 0X4DCC) << 16);
    // 0x80442214: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80442218: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8044221C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80442220: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80442224: lw          $t8, 0x3CCC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(95, 0X4DCC));
    // 0x80442228: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8044222C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80442230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80442234: jal         0x80048490
    // 0x80442238: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80442238: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8044223C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80442240: jal         0x80048378
    // 0x80442244: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80442244: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80442248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044224C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80442250: jr          $ra
    // 0x80442254: nop

    return;
    // 0x80442254: nop

;}
RECOMP_FUNC void func_80532AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532AD0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80532AD4: addiu       $at, $zero, 0x4040
    ctx->r1 = ADD32(0, 0X4040);
    // 0x80532AD8: beq         $v0, $at, L_80532AF0
    if (ctx->r2 == ctx->r1) {
        // 0x80532ADC: addiu       $at, $zero, 0x450E
        ctx->r1 = ADD32(0, 0X450E);
            goto L_80532AF0;
    }
    // 0x80532ADC: addiu       $at, $zero, 0x450E
    ctx->r1 = ADD32(0, 0X450E);
    // 0x80532AE0: beq         $v0, $at, L_80532AFC
    if (ctx->r2 == ctx->r1) {
        // 0x80532AE4: nop
    
            goto L_80532AFC;
    }
    // 0x80532AE4: nop

    // 0x80532AE8: b           L_80532B08
    // 0x80532AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80532B08;
    // 0x80532AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80532AF0:
    // 0x80532AF0: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(345, 0XE14) << 16);
    // 0x80532AF4: jr          $ra
    // 0x80532AF8: addiu       $v0, $v0, 0x38E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(345, 0XE14));
    return;
    // 0x80532AF8: addiu       $v0, $v0, 0x38E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(345, 0XE14));
L_80532AFC:
    // 0x80532AFC: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(345, 0X174C) << 16);
    // 0x80532B00: jr          $ra
    // 0x80532B04: addiu       $v0, $v0, 0x421C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(345, 0X174C));
    return;
    // 0x80532B04: addiu       $v0, $v0, 0x421C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(345, 0X174C));
L_80532B08:
    // 0x80532B08: jr          $ra
    // 0x80532B0C: nop

    return;
    // 0x80532B0C: nop

;}
RECOMP_FUNC void func_8051AA54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051AA54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051AA58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8051AA5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8051AA60: jal         0x8051A530
    // 0x8051AA64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8051A530(rdram, ctx);
        goto after_0;
    // 0x8051AA64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8051AA68: jal         0x8051A8E0
    // 0x8051AA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051A8E0(rdram, ctx);
        goto after_1;
    // 0x8051AA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8051AA70: beq         $v0, $zero, L_8051AAC8
    if (ctx->r2 == 0) {
        // 0x8051AA74: nop
    
            goto L_8051AAC8;
    }
    // 0x8051AA74: nop

    // 0x8051AA78: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x8051AA7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8051AA80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8051AA84: beq         $t6, $at, L_8051AAAC
    if (ctx->r14 == ctx->r1) {
        // 0x8051AA88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8051AAAC;
    }
    // 0x8051AA88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8051AA8C: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x8051AA90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8051AA94: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8051AA98: xori        $a3, $t7, 0x1
    ctx->r7 = ctx->r15 ^ 0X1;
    // 0x8051AA9C: jal         0x8051ADC0
    // 0x8051AAA0: sw          $a3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r7;
    func_8051ADC0(rdram, ctx);
        goto after_2;
    // 0x8051AAA0: sw          $a3, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r7;
    after_2:
    // 0x8051AAA4: b           L_8051AAC8
    // 0x8051AAA8: nop

        goto L_8051AAC8;
    // 0x8051AAA8: nop

L_8051AAAC:
    // 0x8051AAAC: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8051AAB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8051AAB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8051AAB8: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8051AABC: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8051AAC0: jal         0x8051ADC0
    // 0x8051AAC4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8051ADC0(rdram, ctx);
        goto after_3;
    // 0x8051AAC4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
L_8051AAC8:
    // 0x8051AAC8: jal         0x8051A95C
    // 0x8051AACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051A95C(rdram, ctx);
        goto after_4;
    // 0x8051AACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8051AAD0: jal         0x8051A568
    // 0x8051AAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8051A568(rdram, ctx);
        goto after_5;
    // 0x8051AAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8051AAD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8051AADC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8051AAE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051AAE4: jr          $ra
    // 0x8051AAE8: nop

    return;
    // 0x8051AAE8: nop

;}
RECOMP_FUNC void func_804EF908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF90C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804EF910: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804EF914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF918: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804EF91C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804EF920: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804EF924: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804EF928: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804EF92C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804EF930: lui         $t1, 0x804F
    ctx->r9 = S32(RELOC_HI16(267, 0X10E8) << 16);
    // 0x804EF934: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804EF938: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804EF93C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804EF940: lw          $t1, -0x188($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(267, 0X10E8));
    // 0x804EF944: jal         0x804EF604
    // 0x804EF948: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_804EF604(rdram, ctx);
        goto after_0;
    // 0x804EF948: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x804EF94C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF954: jr          $ra
    // 0x804EF958: nop

    return;
    // 0x804EF958: nop

;}
RECOMP_FUNC void func_806DF624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DF628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF62C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806DF630: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806DF634: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806DF638: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(643, 0X1130) << 16);
    // 0x806DF63C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806DF640: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806DF644: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806DF648: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806DF64C: lw          $t8, 0x560($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(643, 0X1130));
    // 0x806DF650: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806DF654: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806DF658: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806DF65C: jal         0x80048490
    // 0x806DF660: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806DF660: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806DF664: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806DF668: jal         0x80048378
    // 0x806DF66C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x806DF66C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x806DF670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DF674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DF678: jr          $ra
    // 0x806DF67C: nop

    return;
    // 0x806DF67C: nop

;}
RECOMP_FUNC void func_8043CBA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043CBA0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043CBA4: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043CBA8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8043CBAC: lwc1        $f6, 0x324($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X324);
    // 0x8043CBB0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8043CBB4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8043CBB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8043CBBC: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8043CBC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8043CBC4: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8043CBC8: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043CBCC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8043CBD0: nop

    // 0x8043CBD4: bc1fl       L_8043CBF4
    if (!c1cs) {
        // 0x8043CBD8: c.lt.s      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
            goto L_8043CBF4;
    }
    goto skip_0;
    // 0x8043CBD8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    skip_0:
    // 0x8043CBDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8043CBE0: nop

    // 0x8043CBE4: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8043CBE8: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x8043CBEC: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8043CBF0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
L_8043CBF4:
    // 0x8043CBF4: nop

    // 0x8043CBF8: bc1f        L_8043CC08
    if (!c1cs) {
        // 0x8043CBFC: nop
    
            goto L_8043CC08;
    }
    // 0x8043CBFC: nop

    // 0x8043CC00: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8043CC04: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
L_8043CC08:
    // 0x8043CC08: jr          $ra
    // 0x8043CC0C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x8043CC0C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8042A3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A3E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042A3E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042A3E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042A3EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042A3F0: jal         0x80045A34
    // 0x8042A3F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8042A3F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8042A3F8: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8042A3FC: jal         0x80064D1C
    // 0x8042A400: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x8042A400: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_1:
    // 0x8042A404: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042A408: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8042A40C: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042A410: jal         0x80429EB4
    // 0x8042A414: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_80429EB4(rdram, ctx);
        goto after_2;
    // 0x8042A414: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x8042A418: jal         0x8042A2EC
    // 0x8042A41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042A2EC(rdram, ctx);
        goto after_3;
    // 0x8042A41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8042A420: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x8042A424: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(47, 0X454) << 16);
    // 0x8042A428: addiu       $t8, $t8, -0x5DDC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(47, 0X454));
    // 0x8042A42C: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x8042A430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042A434: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042A438: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042A43C: jr          $ra
    // 0x8042A440: nop

    return;
    // 0x8042A440: nop

;}
RECOMP_FUNC void func_8006CB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB78: lhu         $v0, 0x64($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X64);
    // 0x8006CB7C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8006CB80: beq         $t6, $zero, L_8006CC1C
    if (ctx->r14 == 0) {
        // 0x8006CB84: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8006CC1C;
    }
    // 0x8006CB84: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8006CB88: lwc1        $f0, 0x60($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X60);
    // 0x8006CB8C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006CB90: lwc1        $f12, 0x5C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x8006CB94: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8006CB98: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8006CB9C: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x8006CBA0: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006CBA4: beq         $t7, $zero, L_8006CBE4
    if (ctx->r15 == 0) {
        // 0x8006CBA8: sub.s       $f2, $f8, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f12.fl;
            goto L_8006CBE4;
    }
    // 0x8006CBA8: sub.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8006CBAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8006CBB0: nop

    // 0x8006CBB4: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x8006CBB8: nop

    // 0x8006CBBC: bc1fl       L_8006CC1C
    if (!c1cs) {
        // 0x8006CBC0: sh          $v0, 0x64($a0)
        MEM_H(0X64, ctx->r4) = ctx->r2;
            goto L_8006CC1C;
    }
    goto skip_0;
    // 0x8006CBC0: sh          $v0, 0x64($a0)
    MEM_H(0X64, ctx->r4) = ctx->r2;
    skip_0:
    // 0x8006CBC4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006CBC8: nop

    // 0x8006CBCC: bc1fl       L_8006CC1C
    if (!c1cs) {
        // 0x8006CBD0: sh          $v0, 0x64($a0)
        MEM_H(0X64, ctx->r4) = ctx->r2;
            goto L_8006CC1C;
    }
    goto skip_1;
    // 0x8006CBD0: sh          $v0, 0x64($a0)
    MEM_H(0X64, ctx->r4) = ctx->r2;
    skip_1:
    // 0x8006CBD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006CBD8: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
    // 0x8006CBDC: b           L_8006CC18
    // 0x8006CBE0: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
        goto L_8006CC18;
    // 0x8006CBE0: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
L_8006CBE4:
    // 0x8006CBE4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8006CBE8: nop

    // 0x8006CBEC: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x8006CBF0: nop

    // 0x8006CBF4: bc1fl       L_8006CC1C
    if (!c1cs) {
        // 0x8006CBF8: sh          $v0, 0x64($a0)
        MEM_H(0X64, ctx->r4) = ctx->r2;
            goto L_8006CC1C;
    }
    goto skip_2;
    // 0x8006CBF8: sh          $v0, 0x64($a0)
    MEM_H(0X64, ctx->r4) = ctx->r2;
    skip_2:
    // 0x8006CBFC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8006CC00: nop

    // 0x8006CC04: bc1fl       L_8006CC1C
    if (!c1cs) {
        // 0x8006CC08: sh          $v0, 0x64($a0)
        MEM_H(0X64, ctx->r4) = ctx->r2;
            goto L_8006CC1C;
    }
    goto skip_3;
    // 0x8006CC08: sh          $v0, 0x64($a0)
    MEM_H(0X64, ctx->r4) = ctx->r2;
    skip_3:
    // 0x8006CC0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006CC10: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x8006CC14: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
L_8006CC18:
    // 0x8006CC18: sh          $v0, 0x64($a0)
    MEM_H(0X64, ctx->r4) = ctx->r2;
L_8006CC1C:
    // 0x8006CC1C: jr          $ra
    // 0x8006CC20: nop

    return;
    // 0x8006CC20: nop

;}
RECOMP_FUNC void func_80518FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80518FF0: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(291, 0X12A4) << 16);
    // 0x80518FF4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80518FF8: addiu       $t7, $t7, -0x70EC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(291, 0X12A4));
    // 0x80518FFC: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80519000: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80519004: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    // 0x80519008: jr          $ra
    // 0x8051900C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8051900C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_804516BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804516BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804516C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804516C4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804516C8: jal         0x80450F20
    // 0x804516CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80450F20(rdram, ctx);
        goto after_0;
    // 0x804516CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804516D0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804516D4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804516D8: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x804516DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804516E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804516E4: sw          $t6, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r14;
    // 0x804516E8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804516EC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804516F0: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    // 0x804516F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804516F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804516FC: jr          $ra
    // 0x80451700: nop

    return;
    // 0x80451700: nop

;}
RECOMP_FUNC void func_804245BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804245BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804245C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804245C4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804245C8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804245CC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804245D0: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X3478) << 16);
    // 0x804245D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804245D8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804245DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804245E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804245E4: lw          $t8, 0x5E78($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X3478));
    // 0x804245E8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804245EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804245F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804245F4: jal         0x80048490
    // 0x804245F8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804245F8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804245FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80424600: jal         0x80048378
    // 0x80424604: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80424604: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80424608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042460C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80424610: jr          $ra
    // 0x80424614: nop

    return;
    // 0x80424614: nop

;}
RECOMP_FUNC void func_805A2780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A2780: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A2784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A2788: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A278C: lwc1        $f6, 0xE0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x805A2790: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805A2794: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A2798: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A279C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x805A27A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A27A4: bc1fl       L_805A27BC
    if (!c1cs) {
        // 0x805A27A8: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805A27BC;
    }
    goto skip_0;
    // 0x805A27A8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x805A27AC: lbu         $a2, 0x30($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X30);
    // 0x805A27B0: jal         0x805A2B28
    // 0x805A27B4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_0;
    // 0x805A27B4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_0:
    // 0x805A27B8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_805A27BC:
    // 0x805A27BC: jal         0x80048F84
    // 0x805A27C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x805A27C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805A27C4: jal         0x805A1848
    // 0x805A27C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1848(rdram, ctx);
        goto after_2;
    // 0x805A27C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805A27CC: jal         0x805A1BA8
    // 0x805A27D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A1BA8(rdram, ctx);
        goto after_3;
    // 0x805A27D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805A27D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A27D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A27DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A27E0: jr          $ra
    // 0x805A27E4: nop

    return;
    // 0x805A27E4: nop

;}
RECOMP_FUNC void func_80550B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80550B74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80550B78: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80550B7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80550B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80550B84: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x80550B88: sub.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f12.fl;
L_80550B8C:
    // 0x80550B8C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80550B90: lh          $a3, 0x0($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X0);
    // 0x80550B94: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550B98: andi        $t6, $v1, 0xF800
    ctx->r14 = ctx->r3 & 0XF800;
    // 0x80550B9C: sra         $t7, $t6, 11
    ctx->r15 = S32(SIGNED(ctx->r14) >> 11);
    // 0x80550BA0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80550BA4: andi        $t8, $a3, 0xF800
    ctx->r24 = ctx->r7 & 0XF800;
    // 0x80550BA8: sra         $t9, $t8, 11
    ctx->r25 = S32(SIGNED(ctx->r24) >> 11);
    // 0x80550BAC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80550BB0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80550BB4: andi        $t6, $v1, 0x7C0
    ctx->r14 = ctx->r3 & 0X7C0;
    // 0x80550BB8: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x80550BBC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80550BC0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80550BC4: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80550BC8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80550BCC: andi        $t6, $v1, 0x3E
    ctx->r14 = ctx->r3 & 0X3E;
    // 0x80550BD0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80550BD4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80550BD8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80550BDC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550BE0: nop

    // 0x80550BE4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80550BE8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550BEC: nop

    // 0x80550BF0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550BF4: beql        $t2, $zero, L_80550C44
    if (ctx->r10 == 0) {
        // 0x80550BF8: mfc1        $t2, $f8
        ctx->r10 = (int32_t)ctx->f8.u32l;
            goto L_80550C44;
    }
    goto skip_0;
    // 0x80550BF8: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80550BFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80550C00: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550C04: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80550C08: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550C0C: nop

    // 0x80550C10: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80550C14: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550C18: nop

    // 0x80550C1C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550C20: bne         $t2, $zero, L_80550C38
    if (ctx->r10 != 0) {
        // 0x80550C24: nop
    
            goto L_80550C38;
    }
    // 0x80550C24: nop

    // 0x80550C28: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80550C2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80550C30: b           L_80550C50
    // 0x80550C34: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80550C50;
    // 0x80550C34: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80550C38:
    // 0x80550C38: b           L_80550C50
    // 0x80550C3C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80550C50;
    // 0x80550C3C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80550C40: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
L_80550C44:
    // 0x80550C44: nop

    // 0x80550C48: bltz        $t2, L_80550C38
    if (SIGNED(ctx->r10) < 0) {
        // 0x80550C4C: nop
    
            goto L_80550C38;
    }
    // 0x80550C4C: nop

L_80550C50:
    // 0x80550C50: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80550C54: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80550C58: andi        $t8, $a3, 0x7C0
    ctx->r24 = ctx->r7 & 0X7C0;
    // 0x80550C5C: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x80550C60: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80550C64: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80550C68: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x80550C6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550C70: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x80550C74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80550C78: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80550C7C: or          $t5, $t4, $t3
    ctx->r13 = ctx->r12 | ctx->r11;
    // 0x80550C80: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80550C84: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80550C88: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80550C8C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80550C90: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80550C94: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550C98: nop

    // 0x80550C9C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80550CA0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550CA4: nop

    // 0x80550CA8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550CAC: beql        $t2, $zero, L_80550CFC
    if (ctx->r10 == 0) {
        // 0x80550CB0: mfc1        $t2, $f18
        ctx->r10 = (int32_t)ctx->f18.u32l;
            goto L_80550CFC;
    }
    goto skip_1;
    // 0x80550CB0: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x80550CB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80550CB8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550CBC: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80550CC0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550CC4: nop

    // 0x80550CC8: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80550CCC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550CD0: nop

    // 0x80550CD4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550CD8: bne         $t2, $zero, L_80550CF0
    if (ctx->r10 != 0) {
        // 0x80550CDC: nop
    
            goto L_80550CF0;
    }
    // 0x80550CDC: nop

    // 0x80550CE0: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80550CE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80550CE8: b           L_80550D08
    // 0x80550CEC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80550D08;
    // 0x80550CEC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80550CF0:
    // 0x80550CF0: b           L_80550D08
    // 0x80550CF4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80550D08;
    // 0x80550CF4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80550CF8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
L_80550CFC:
    // 0x80550CFC: nop

    // 0x80550D00: bltz        $t2, L_80550CF0
    if (SIGNED(ctx->r10) < 0) {
        // 0x80550D04: nop
    
            goto L_80550CF0;
    }
    // 0x80550D04: nop

L_80550D08:
    // 0x80550D08: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80550D0C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80550D10: andi        $t8, $a3, 0x3E
    ctx->r24 = ctx->r7 & 0X3E;
    // 0x80550D14: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80550D18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80550D1C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80550D20: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x80550D24: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550D28: or          $t3, $t5, $t4
    ctx->r11 = ctx->r13 | ctx->r12;
    // 0x80550D2C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80550D30: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80550D34: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80550D38: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80550D3C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80550D40: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80550D44: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550D48: nop

    // 0x80550D4C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80550D50: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550D54: nop

    // 0x80550D58: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550D5C: beql        $t2, $zero, L_80550DAC
    if (ctx->r10 == 0) {
        // 0x80550D60: mfc1        $t2, $f6
        ctx->r10 = (int32_t)ctx->f6.u32l;
            goto L_80550DAC;
    }
    goto skip_2;
    // 0x80550D60: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x80550D64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80550D68: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550D6C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80550D70: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550D74: nop

    // 0x80550D78: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80550D7C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550D80: nop

    // 0x80550D84: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550D88: bne         $t2, $zero, L_80550DA0
    if (ctx->r10 != 0) {
        // 0x80550D8C: nop
    
            goto L_80550DA0;
    }
    // 0x80550D8C: nop

    // 0x80550D90: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80550D94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80550D98: b           L_80550DB8
    // 0x80550D9C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80550DB8;
    // 0x80550D9C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80550DA0:
    // 0x80550DA0: b           L_80550DB8
    // 0x80550DA4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80550DB8;
    // 0x80550DA4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80550DA8: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
L_80550DAC:
    // 0x80550DAC: nop

    // 0x80550DB0: bltz        $t2, L_80550DA0
    if (SIGNED(ctx->r10) < 0) {
        // 0x80550DB4: nop
    
            goto L_80550DA0;
    }
    // 0x80550DB4: nop

L_80550DB8:
    // 0x80550DB8: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80550DBC: or          $t4, $t3, $t5
    ctx->r12 = ctx->r11 | ctx->r13;
    // 0x80550DC0: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x80550DC4: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80550DC8: lh          $a3, 0x2($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X2);
    // 0x80550DCC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80550DD0: andi        $t6, $v1, 0xF800
    ctx->r14 = ctx->r3 & 0XF800;
    // 0x80550DD4: sra         $t7, $t6, 11
    ctx->r15 = S32(SIGNED(ctx->r14) >> 11);
    // 0x80550DD8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80550DDC: andi        $t8, $a3, 0xF800
    ctx->r24 = ctx->r7 & 0XF800;
    // 0x80550DE0: sra         $t9, $t8, 11
    ctx->r25 = S32(SIGNED(ctx->r24) >> 11);
    // 0x80550DE4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80550DE8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80550DEC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550DF0: andi        $t6, $v1, 0x7C0
    ctx->r14 = ctx->r3 & 0X7C0;
    // 0x80550DF4: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x80550DF8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80550DFC: mul.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80550E00: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80550E04: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80550E08: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80550E0C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80550E10: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80550E14: andi        $t6, $v1, 0x3E
    ctx->r14 = ctx->r3 & 0X3E;
    // 0x80550E18: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80550E1C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80550E20: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550E24: nop

    // 0x80550E28: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80550E2C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550E30: nop

    // 0x80550E34: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550E38: beql        $t2, $zero, L_80550E88
    if (ctx->r10 == 0) {
        // 0x80550E3C: mfc1        $t2, $f16
        ctx->r10 = (int32_t)ctx->f16.u32l;
            goto L_80550E88;
    }
    goto skip_3;
    // 0x80550E3C: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x80550E40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80550E44: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550E48: sub.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80550E4C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550E50: nop

    // 0x80550E54: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80550E58: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550E5C: nop

    // 0x80550E60: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550E64: bne         $t2, $zero, L_80550E7C
    if (ctx->r10 != 0) {
        // 0x80550E68: nop
    
            goto L_80550E7C;
    }
    // 0x80550E68: nop

    // 0x80550E6C: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x80550E70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80550E74: b           L_80550E94
    // 0x80550E78: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80550E94;
    // 0x80550E78: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80550E7C:
    // 0x80550E7C: b           L_80550E94
    // 0x80550E80: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80550E94;
    // 0x80550E80: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80550E84: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
L_80550E88:
    // 0x80550E88: nop

    // 0x80550E8C: bltz        $t2, L_80550E7C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80550E90: nop
    
            goto L_80550E7C;
    }
    // 0x80550E90: nop

L_80550E94:
    // 0x80550E94: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80550E98: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80550E9C: andi        $t8, $a3, 0x7C0
    ctx->r24 = ctx->r7 & 0X7C0;
    // 0x80550EA0: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x80550EA4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80550EA8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80550EAC: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x80550EB0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550EB4: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x80550EB8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80550EBC: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80550EC0: or          $t4, $t5, $t3
    ctx->r12 = ctx->r13 | ctx->r11;
    // 0x80550EC4: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80550EC8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80550ECC: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80550ED0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80550ED4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80550ED8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550EDC: nop

    // 0x80550EE0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80550EE4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550EE8: nop

    // 0x80550EEC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550EF0: beql        $t2, $zero, L_80550F40
    if (ctx->r10 == 0) {
        // 0x80550EF4: mfc1        $t2, $f4
        ctx->r10 = (int32_t)ctx->f4.u32l;
            goto L_80550F40;
    }
    goto skip_4;
    // 0x80550EF4: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x80550EF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80550EFC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550F00: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80550F04: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550F08: nop

    // 0x80550F0C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80550F10: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550F14: nop

    // 0x80550F18: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550F1C: bne         $t2, $zero, L_80550F34
    if (ctx->r10 != 0) {
        // 0x80550F20: nop
    
            goto L_80550F34;
    }
    // 0x80550F20: nop

    // 0x80550F24: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80550F28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80550F2C: b           L_80550F4C
    // 0x80550F30: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80550F4C;
    // 0x80550F30: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80550F34:
    // 0x80550F34: b           L_80550F4C
    // 0x80550F38: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80550F4C;
    // 0x80550F38: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80550F3C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
L_80550F40:
    // 0x80550F40: nop

    // 0x80550F44: bltz        $t2, L_80550F34
    if (SIGNED(ctx->r10) < 0) {
        // 0x80550F48: nop
    
            goto L_80550F34;
    }
    // 0x80550F48: nop

L_80550F4C:
    // 0x80550F4C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80550F50: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80550F54: andi        $t8, $a3, 0x3E
    ctx->r24 = ctx->r7 & 0X3E;
    // 0x80550F58: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80550F5C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80550F60: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80550F64: sll         $t5, $t2, 6
    ctx->r13 = S32(ctx->r10 << 6);
    // 0x80550F68: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550F6C: or          $t3, $t4, $t5
    ctx->r11 = ctx->r12 | ctx->r13;
    // 0x80550F70: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80550F74: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80550F78: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80550F7C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80550F80: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80550F84: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80550F88: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550F8C: nop

    // 0x80550F90: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80550F94: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550F98: nop

    // 0x80550F9C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550FA0: beql        $t2, $zero, L_80550FF0
    if (ctx->r10 == 0) {
        // 0x80550FA4: mfc1        $t2, $f8
        ctx->r10 = (int32_t)ctx->f8.u32l;
            goto L_80550FF0;
    }
    goto skip_5;
    // 0x80550FA4: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    skip_5:
    // 0x80550FA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80550FAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80550FB0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80550FB4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80550FB8: nop

    // 0x80550FBC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80550FC0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80550FC4: nop

    // 0x80550FC8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80550FCC: bne         $t2, $zero, L_80550FE4
    if (ctx->r10 != 0) {
        // 0x80550FD0: nop
    
            goto L_80550FE4;
    }
    // 0x80550FD0: nop

    // 0x80550FD4: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80550FD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80550FDC: b           L_80550FFC
    // 0x80550FE0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80550FFC;
    // 0x80550FE0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80550FE4:
    // 0x80550FE4: b           L_80550FFC
    // 0x80550FE8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80550FFC;
    // 0x80550FE8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80550FEC: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
L_80550FF0:
    // 0x80550FF0: nop

    // 0x80550FF4: bltz        $t2, L_80550FE4
    if (SIGNED(ctx->r10) < 0) {
        // 0x80550FF8: nop
    
            goto L_80550FE4;
    }
    // 0x80550FF8: nop

L_80550FFC:
    // 0x80550FFC: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80551000: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80551004: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x80551008: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x8055100C: lh          $a3, 0x2($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X2);
    // 0x80551010: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80551014: andi        $t6, $v1, 0xF800
    ctx->r14 = ctx->r3 & 0XF800;
    // 0x80551018: sra         $t7, $t6, 11
    ctx->r15 = S32(SIGNED(ctx->r14) >> 11);
    // 0x8055101C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80551020: andi        $t8, $a3, 0xF800
    ctx->r24 = ctx->r7 & 0XF800;
    // 0x80551024: sra         $t9, $t8, 11
    ctx->r25 = S32(SIGNED(ctx->r24) >> 11);
    // 0x80551028: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8055102C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80551030: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80551034: andi        $t6, $v1, 0x7C0
    ctx->r14 = ctx->r3 & 0X7C0;
    // 0x80551038: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x8055103C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80551040: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80551044: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80551048: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8055104C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80551050: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80551054: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80551058: andi        $t6, $v1, 0x3E
    ctx->r14 = ctx->r3 & 0X3E;
    // 0x8055105C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80551060: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80551064: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80551068: nop

    // 0x8055106C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80551070: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80551074: nop

    // 0x80551078: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8055107C: beql        $t2, $zero, L_805510CC
    if (ctx->r10 == 0) {
        // 0x80551080: mfc1        $t2, $f18
        ctx->r10 = (int32_t)ctx->f18.u32l;
            goto L_805510CC;
    }
    goto skip_6;
    // 0x80551080: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    skip_6:
    // 0x80551084: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80551088: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8055108C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80551090: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80551094: nop

    // 0x80551098: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8055109C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805510A0: nop

    // 0x805510A4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805510A8: bne         $t2, $zero, L_805510C0
    if (ctx->r10 != 0) {
        // 0x805510AC: nop
    
            goto L_805510C0;
    }
    // 0x805510AC: nop

    // 0x805510B0: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x805510B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805510B8: b           L_805510D8
    // 0x805510BC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_805510D8;
    // 0x805510BC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_805510C0:
    // 0x805510C0: b           L_805510D8
    // 0x805510C4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_805510D8;
    // 0x805510C4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x805510C8: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
L_805510CC:
    // 0x805510CC: nop

    // 0x805510D0: bltz        $t2, L_805510C0
    if (SIGNED(ctx->r10) < 0) {
        // 0x805510D4: nop
    
            goto L_805510C0;
    }
    // 0x805510D4: nop

L_805510D8:
    // 0x805510D8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x805510DC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x805510E0: andi        $t8, $a3, 0x7C0
    ctx->r24 = ctx->r7 & 0X7C0;
    // 0x805510E4: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x805510E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805510EC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x805510F0: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x805510F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805510F8: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x805510FC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80551100: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80551104: or          $t5, $t4, $t3
    ctx->r13 = ctx->r12 | ctx->r11;
    // 0x80551108: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8055110C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80551110: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80551114: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80551118: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8055111C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80551120: nop

    // 0x80551124: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80551128: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8055112C: nop

    // 0x80551130: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80551134: beql        $t2, $zero, L_80551184
    if (ctx->r10 == 0) {
        // 0x80551138: mfc1        $t2, $f6
        ctx->r10 = (int32_t)ctx->f6.u32l;
            goto L_80551184;
    }
    goto skip_7;
    // 0x80551138: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    skip_7:
    // 0x8055113C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80551140: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80551144: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80551148: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8055114C: nop

    // 0x80551150: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80551154: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80551158: nop

    // 0x8055115C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80551160: bne         $t2, $zero, L_80551178
    if (ctx->r10 != 0) {
        // 0x80551164: nop
    
            goto L_80551178;
    }
    // 0x80551164: nop

    // 0x80551168: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8055116C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80551170: b           L_80551190
    // 0x80551174: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80551190;
    // 0x80551174: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80551178:
    // 0x80551178: b           L_80551190
    // 0x8055117C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80551190;
    // 0x8055117C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80551180: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
L_80551184:
    // 0x80551184: nop

    // 0x80551188: bltz        $t2, L_80551178
    if (SIGNED(ctx->r10) < 0) {
        // 0x8055118C: nop
    
            goto L_80551178;
    }
    // 0x8055118C: nop

L_80551190:
    // 0x80551190: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80551194: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80551198: andi        $t8, $a3, 0x3E
    ctx->r24 = ctx->r7 & 0X3E;
    // 0x8055119C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x805511A0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805511A4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x805511A8: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x805511AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805511B0: or          $t3, $t5, $t4
    ctx->r11 = ctx->r13 | ctx->r12;
    // 0x805511B4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805511B8: mul.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x805511BC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x805511C0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x805511C4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x805511C8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x805511CC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805511D0: nop

    // 0x805511D4: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x805511D8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805511DC: nop

    // 0x805511E0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805511E4: beql        $t2, $zero, L_80551234
    if (ctx->r10 == 0) {
        // 0x805511E8: mfc1        $t2, $f16
        ctx->r10 = (int32_t)ctx->f16.u32l;
            goto L_80551234;
    }
    goto skip_8;
    // 0x805511E8: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    skip_8:
    // 0x805511EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805511F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805511F4: sub.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x805511F8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805511FC: nop

    // 0x80551200: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80551204: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80551208: nop

    // 0x8055120C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80551210: bne         $t2, $zero, L_80551228
    if (ctx->r10 != 0) {
        // 0x80551214: nop
    
            goto L_80551228;
    }
    // 0x80551214: nop

    // 0x80551218: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8055121C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80551220: b           L_80551240
    // 0x80551224: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80551240;
    // 0x80551224: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80551228:
    // 0x80551228: b           L_80551240
    // 0x8055122C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80551240;
    // 0x8055122C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80551230: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
L_80551234:
    // 0x80551234: nop

    // 0x80551238: bltz        $t2, L_80551228
    if (SIGNED(ctx->r10) < 0) {
        // 0x8055123C: nop
    
            goto L_80551228;
    }
    // 0x8055123C: nop

L_80551240:
    // 0x80551240: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80551244: or          $t4, $t3, $t5
    ctx->r12 = ctx->r11 | ctx->r13;
    // 0x80551248: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x8055124C: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80551250: lh          $a3, 0x2($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X2);
    // 0x80551254: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80551258: andi        $t6, $v1, 0xF800
    ctx->r14 = ctx->r3 & 0XF800;
    // 0x8055125C: sra         $t7, $t6, 11
    ctx->r15 = S32(SIGNED(ctx->r14) >> 11);
    // 0x80551260: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80551264: andi        $t8, $a3, 0xF800
    ctx->r24 = ctx->r7 & 0XF800;
    // 0x80551268: sra         $t9, $t8, 11
    ctx->r25 = S32(SIGNED(ctx->r24) >> 11);
    // 0x8055126C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80551270: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80551274: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80551278: andi        $t6, $v1, 0x7C0
    ctx->r14 = ctx->r3 & 0X7C0;
    // 0x8055127C: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x80551280: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80551284: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80551288: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8055128C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80551290: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80551294: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80551298: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8055129C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x805512A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x805512A4: andi        $t6, $v1, 0x3E
    ctx->r14 = ctx->r3 & 0X3E;
    // 0x805512A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x805512AC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x805512B0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805512B4: nop

    // 0x805512B8: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x805512BC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805512C0: nop

    // 0x805512C4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805512C8: beql        $t2, $zero, L_80551318
    if (ctx->r10 == 0) {
        // 0x805512CC: mfc1        $t2, $f4
        ctx->r10 = (int32_t)ctx->f4.u32l;
            goto L_80551318;
    }
    goto skip_9;
    // 0x805512CC: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    skip_9:
    // 0x805512D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805512D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805512D8: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x805512DC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805512E0: nop

    // 0x805512E4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x805512E8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805512EC: nop

    // 0x805512F0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805512F4: bne         $t2, $zero, L_8055130C
    if (ctx->r10 != 0) {
        // 0x805512F8: nop
    
            goto L_8055130C;
    }
    // 0x805512F8: nop

    // 0x805512FC: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80551300: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80551304: b           L_80551324
    // 0x80551308: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80551324;
    // 0x80551308: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8055130C:
    // 0x8055130C: b           L_80551324
    // 0x80551310: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80551324;
    // 0x80551310: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80551314: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
L_80551318:
    // 0x80551318: nop

    // 0x8055131C: bltz        $t2, L_8055130C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80551320: nop
    
            goto L_8055130C;
    }
    // 0x80551320: nop

L_80551324:
    // 0x80551324: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80551328: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8055132C: andi        $t8, $a3, 0x7C0
    ctx->r24 = ctx->r7 & 0X7C0;
    // 0x80551330: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x80551334: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80551338: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8055133C: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x80551340: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80551344: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x80551348: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8055134C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80551350: or          $t4, $t5, $t3
    ctx->r12 = ctx->r13 | ctx->r11;
    // 0x80551354: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80551358: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8055135C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80551360: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80551364: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80551368: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8055136C: nop

    // 0x80551370: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80551374: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80551378: nop

    // 0x8055137C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80551380: beql        $t2, $zero, L_805513D0
    if (ctx->r10 == 0) {
        // 0x80551384: mfc1        $t2, $f8
        ctx->r10 = (int32_t)ctx->f8.u32l;
            goto L_805513D0;
    }
    goto skip_10;
    // 0x80551384: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    skip_10:
    // 0x80551388: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8055138C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80551390: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80551394: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80551398: nop

    // 0x8055139C: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x805513A0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805513A4: nop

    // 0x805513A8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805513AC: bne         $t2, $zero, L_805513C4
    if (ctx->r10 != 0) {
        // 0x805513B0: nop
    
            goto L_805513C4;
    }
    // 0x805513B0: nop

    // 0x805513B4: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x805513B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805513BC: b           L_805513DC
    // 0x805513C0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_805513DC;
    // 0x805513C0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_805513C4:
    // 0x805513C4: b           L_805513DC
    // 0x805513C8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_805513DC;
    // 0x805513C8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x805513CC: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
L_805513D0:
    // 0x805513D0: nop

    // 0x805513D4: bltz        $t2, L_805513C4
    if (SIGNED(ctx->r10) < 0) {
        // 0x805513D8: nop
    
            goto L_805513C4;
    }
    // 0x805513D8: nop

L_805513DC:
    // 0x805513DC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x805513E0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x805513E4: andi        $t8, $a3, 0x3E
    ctx->r24 = ctx->r7 & 0X3E;
    // 0x805513E8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x805513EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805513F0: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x805513F4: sll         $t5, $t2, 6
    ctx->r13 = S32(ctx->r10 << 6);
    // 0x805513F8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805513FC: or          $t3, $t4, $t5
    ctx->r11 = ctx->r12 | ctx->r13;
    // 0x80551400: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80551404: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80551408: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8055140C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80551410: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80551414: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80551418: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8055141C: nop

    // 0x80551420: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80551424: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80551428: nop

    // 0x8055142C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80551430: beql        $t2, $zero, L_80551480
    if (ctx->r10 == 0) {
        // 0x80551434: mfc1        $t2, $f18
        ctx->r10 = (int32_t)ctx->f18.u32l;
            goto L_80551480;
    }
    goto skip_11;
    // 0x80551434: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    skip_11:
    // 0x80551438: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8055143C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80551440: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80551444: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80551448: nop

    // 0x8055144C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80551450: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80551454: nop

    // 0x80551458: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8055145C: bne         $t2, $zero, L_80551474
    if (ctx->r10 != 0) {
        // 0x80551460: nop
    
            goto L_80551474;
    }
    // 0x80551460: nop

    // 0x80551464: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80551468: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8055146C: b           L_8055148C
    // 0x80551470: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8055148C;
    // 0x80551470: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80551474:
    // 0x80551474: b           L_8055148C
    // 0x80551478: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8055148C;
    // 0x80551478: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8055147C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
L_80551480:
    // 0x80551480: nop

    // 0x80551484: bltz        $t2, L_80551474
    if (SIGNED(ctx->r10) < 0) {
        // 0x80551488: nop
    
            goto L_80551474;
    }
    // 0x80551488: nop

L_8055148C:
    // 0x8055148C: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80551490: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80551494: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80551498: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x8055149C: bne         $v0, $t0, L_80550B8C
    if (ctx->r2 != ctx->r8) {
        // 0x805514A0: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80550B8C;
    }
    // 0x805514A0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x805514A4: jr          $ra
    // 0x805514A8: nop

    return;
    // 0x805514A8: nop

;}
RECOMP_FUNC void func_80473D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80473D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80473D74: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x80473D78: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(161, 0X1400) << 16);
    // 0x80473D7C: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(161, 0X1414) << 16);
    // 0x80473D80: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80473D84: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80473D88: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80473D8C: lw          $t6, 0x4590($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(161, 0X1400));
    // 0x80473D90: lw          $t8, 0x45A4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(161, 0X1414));
    // 0x80473D94: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x80473D98: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
    // 0x80473D9C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80473DA0: sw          $t8, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r24;
    // 0x80473DA4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80473DA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80473DAC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80473DB0: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x80473DB4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80473DB8: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80473DBC: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x80473DC0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80473DC4: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x80473DC8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80473DCC: sw          $a1, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r5;
    // 0x80473DD0: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80473DD4: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x80473DD8: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80473DDC: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80473DE0: jal         0x80048378
    // 0x80473DE4: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80473DE4: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    after_0:
    // 0x80473DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80473DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80473DF0: jr          $ra
    // 0x80473DF4: nop

    return;
    // 0x80473DF4: nop

;}
RECOMP_FUNC void func_807AF110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AF114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807AF118: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807AF11C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807AF120: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AF124: lui         $a0, 0x46F7
    ctx->r4 = S32(0X46F7 << 16);
    // 0x807AF128: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x807AF12C: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807AF130: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x807AF134: lui         $a1, 0xC1C0
    ctx->r5 = S32(0XC1C0 << 16);
    // 0x807AF138: jal         0x8004613C
    // 0x807AF13C: lui         $a2, 0x42DC
    ctx->r6 = S32(0X42DC << 16);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x807AF13C: lui         $a2, 0x42DC
    ctx->r6 = S32(0X42DC << 16);
    after_0:
    // 0x807AF140: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x807AF144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807AF148: jal         0x80047F9C
    // 0x807AF14C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x807AF14C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x807AF150: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x807AF154: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x807AF158: lui         $a0, 0x46F7
    ctx->r4 = S32(0X46F7 << 16);
    // 0x807AF15C: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x807AF160: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807AF164: ori         $a0, $a0, 0x201
    ctx->r4 = ctx->r4 | 0X201;
    // 0x807AF168: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    // 0x807AF16C: lui         $a2, 0x4200
    ctx->r6 = S32(0X4200 << 16);
    // 0x807AF170: jal         0x8004613C
    // 0x807AF174: sb          $t7, 0x17C($t8)
    MEM_B(0X17C, ctx->r24) = ctx->r15;
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x807AF174: sb          $t7, 0x17C($t8)
    MEM_B(0X17C, ctx->r24) = ctx->r15;
    after_2:
    // 0x807AF178: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x807AF17C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x807AF180: jal         0x80047F9C
    // 0x807AF184: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x807AF184: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x807AF188: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x807AF18C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x807AF190: addiu       $t7, $zero, 0xC0
    ctx->r15 = ADD32(0, 0XC0);
    // 0x807AF194: sb          $t9, 0x17C($t0)
    MEM_B(0X17C, ctx->r8) = ctx->r25;
    // 0x807AF198: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x807AF19C: lw          $t2, 0x16C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X16C);
    // 0x807AF1A0: sb          $zero, 0xD($t2)
    MEM_B(0XD, ctx->r10) = 0;
    // 0x807AF1A4: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x807AF1A8: lw          $t4, 0x16C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X16C);
    // 0x807AF1AC: sb          $zero, 0xE($t4)
    MEM_B(0XE, ctx->r12) = 0;
    // 0x807AF1B0: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x807AF1B4: lw          $t6, 0x16C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X16C);
    // 0x807AF1B8: sb          $zero, 0xF($t6)
    MEM_B(0XF, ctx->r14) = 0;
    // 0x807AF1BC: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x807AF1C0: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x807AF1C4: sb          $t7, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r15;
    // 0x807AF1C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807AF1CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807AF1D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AF1D4: jr          $ra
    // 0x807AF1D8: nop

    return;
    // 0x807AF1D8: nop

;}
RECOMP_FUNC void func_8073B5A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073B5A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8073B5AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073B5B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073B5B4: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x8073B5B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8073B5BC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8073B5C0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8073B5C4: bltzl       $t0, L_8073B6F0
    if (SIGNED(ctx->r8) < 0) {
        // 0x8073B5C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073B6F0;
    }
    goto skip_0;
    // 0x8073B5C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8073B5CC: lhu         $t6, 0x18($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X18);
    // 0x8073B5D0: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x8073B5D4: sll         $t5, $t0, 1
    ctx->r13 = S32(ctx->r8 << 1);
    // 0x8073B5D8: bne         $t6, $at, L_8073B66C
    if (ctx->r14 != ctx->r1) {
        // 0x8073B5DC: addu        $v1, $s0, $t5
        ctx->r3 = ADD32(ctx->r16, ctx->r13);
            goto L_8073B66C;
    }
    // 0x8073B5DC: addu        $v1, $s0, $t5
    ctx->r3 = ADD32(ctx->r16, ctx->r13);
    // 0x8073B5E0: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x8073B5E4: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
    // 0x8073B5E8: lhu         $t8, 0x1C($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X1C);
    // 0x8073B5EC: beql        $t8, $zero, L_8073B604
    if (ctx->r24 == 0) {
        // 0x8073B5F0: lhu         $a0, 0x1A($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X1A);
            goto L_8073B604;
    }
    goto skip_1;
    // 0x8073B5F0: lhu         $a0, 0x1A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1A);
    skip_1:
    // 0x8073B5F4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8073B5F8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8073B5FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8073B600: lhu         $a0, 0x1A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1A);
L_8073B604:
    // 0x8073B604: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8073B608: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8073B60C: jal         0x8073B430
    // 0x8073B610: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8073B430(rdram, ctx);
        goto after_0;
    // 0x8073B610: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8073B614: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8073B618: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8073B61C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8073B620: beq         $v0, $zero, L_8073B6EC
    if (ctx->r2 == 0) {
        // 0x8073B624: andi        $a1, $v0, 0xFFFF
        ctx->r5 = ctx->r2 & 0XFFFF;
            goto L_8073B6EC;
    }
    // 0x8073B624: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x8073B628: sh          $a1, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r5;
    // 0x8073B62C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8073B630: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8073B634: sll         $a2, $t0, 3
    ctx->r6 = S32(ctx->r8 << 3);
    // 0x8073B638: jal         0x8005C27C
    // 0x8073B63C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x8073B63C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8073B640: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8073B644: beql        $t1, $zero, L_8073B6F0
    if (ctx->r9 == 0) {
        // 0x8073B648: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073B6F0;
    }
    goto skip_2;
    // 0x8073B648: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8073B64C: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x8073B650: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8073B654: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8073B658: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x8073B65C: bne         $at, $zero, L_8073B6EC
    if (ctx->r1 != 0) {
        // 0x8073B660: sw          $t2, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r10;
            goto L_8073B6EC;
    }
    // 0x8073B660: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
    // 0x8073B664: b           L_8073B6EC
    // 0x8073B668: sw          $t4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r12;
        goto L_8073B6EC;
    // 0x8073B668: sw          $t4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r12;
L_8073B66C:
    // 0x8073B66C: lhu         $t6, 0x1C($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X1C);
    // 0x8073B670: beql        $t6, $zero, L_8073B688
    if (ctx->r14 == 0) {
        // 0x8073B674: lhu         $a0, 0x1A($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X1A);
            goto L_8073B688;
    }
    goto skip_3;
    // 0x8073B674: lhu         $a0, 0x1A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1A);
    skip_3:
    // 0x8073B678: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8073B67C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8073B680: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8073B684: lhu         $a0, 0x1A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X1A);
L_8073B688:
    // 0x8073B688: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8073B68C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8073B690: jal         0x8073B504
    // 0x8073B694: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8073B504(rdram, ctx);
        goto after_2;
    // 0x8073B694: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x8073B698: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8073B69C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8073B6A0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8073B6A4: beq         $v0, $zero, L_8073B6EC
    if (ctx->r2 == 0) {
        // 0x8073B6A8: andi        $a1, $v0, 0xFFFF
        ctx->r5 = ctx->r2 & 0XFFFF;
            goto L_8073B6EC;
    }
    // 0x8073B6A8: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x8073B6AC: sh          $a1, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r5;
    // 0x8073B6B0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8073B6B4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8073B6B8: sll         $a2, $t0, 3
    ctx->r6 = S32(ctx->r8 << 3);
    // 0x8073B6BC: jal         0x8005C27C
    // 0x8073B6C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x8073B6C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8073B6C4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8073B6C8: beql        $t1, $zero, L_8073B6F0
    if (ctx->r9 == 0) {
        // 0x8073B6CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073B6F0;
    }
    goto skip_4;
    // 0x8073B6CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8073B6D0: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x8073B6D4: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8073B6D8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8073B6DC: slti        $at, $t8, 0x6
    ctx->r1 = SIGNED(ctx->r24) < 0X6 ? 1 : 0;
    // 0x8073B6E0: bne         $at, $zero, L_8073B6EC
    if (ctx->r1 != 0) {
        // 0x8073B6E4: sw          $t8, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r24;
            goto L_8073B6EC;
    }
    // 0x8073B6E4: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8073B6E8: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
L_8073B6EC:
    // 0x8073B6EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073B6F0:
    // 0x8073B6F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073B6F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8073B6F8: jr          $ra
    // 0x8073B6FC: nop

    return;
    // 0x8073B6FC: nop

;}
RECOMP_FUNC void func_800312F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800312F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800312F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800312F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800312FC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031300: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80031304: jal         0x800310A0
    // 0x80031308: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031308: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003130C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031310: jal         0x80030DDC
    // 0x80031314: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80030DDC(rdram, ctx);
        goto after_1;
    // 0x80031314: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80031318: beql        $v0, $zero, L_80031358
    if (ctx->r2 == 0) {
        // 0x8003131C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80031358;
    }
    goto skip_0;
    // 0x8003131C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80031320: jal         0x80028220
    // 0x80031324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028220(rdram, ctx);
        goto after_2;
    // 0x80031324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80031328: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8003132C: sw          $v0, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->r2;
    // 0x80031330: jal         0x80065954
    // 0x80031334: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x80031334: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    after_3:
    // 0x80031338: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003133C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80031340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031344: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80031348: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003134C: jal         0x80041214
    // 0x80031350: nop

    func_80041214(rdram, ctx);
        goto after_4;
    // 0x80031350: nop

    after_4:
    // 0x80031354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80031358:
    // 0x80031358: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003135C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80031360: jr          $ra
    // 0x80031364: nop

    return;
    // 0x80031364: nop

;}
RECOMP_FUNC void func_8041E9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041E9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041E9B0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8041E9B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8041E9B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8041E9BC: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x8041E9C0: beq         $a0, $t7, L_8041E9E4
    if (ctx->r4 == ctx->r15) {
        // 0x8041E9C4: nop
    
            goto L_8041E9E4;
    }
    // 0x8041E9C4: nop

    // 0x8041E9C8: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    // 0x8041E9CC: jal         0x8004816C
    // 0x8041E9D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8004816C(rdram, ctx);
        goto after_0;
    // 0x8041E9D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8041E9D4: jal         0x800447C8
    // 0x8041E9D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8041E9D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8041E9DC: b           L_8041E9E4
    // 0x8041E9E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8041E9E4;
    // 0x8041E9E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8041E9E4:
    // 0x8041E9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041E9E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041E9EC: jr          $ra
    // 0x8041E9F0: nop

    return;
    // 0x8041E9F0: nop

;}
RECOMP_FUNC void func_804459A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804459A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804459A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804459AC: addiu       $a0, $zero, 0x203
    ctx->r4 = ADD32(0, 0X203);
    // 0x804459B0: jal         0x80067818
    // 0x804459B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x804459B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804459B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804459BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804459C0: jr          $ra
    // 0x804459C4: nop

    return;
    // 0x804459C4: nop

;}
RECOMP_FUNC void func_8073B8CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073B8CC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8073B8D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8073B8D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8073B8D8: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(739, 0X2454) << 16);
    // 0x8073B8DC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8073B8E0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8073B8E4: lw          $t8, -0x417C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(739, 0X2454));
    // 0x8073B8E8: jr          $ra
    // 0x8073B8EC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x8073B8EC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8000A8A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A8A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000A8A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000A8AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000A8B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000A8B4: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x8000A8B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000A8BC: addiu       $s1, $s1, 0x4D10
    ctx->r17 = ADD32(ctx->r17, 0X4D10);
    // 0x8000A8C0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8000A8C4: addiu       $s2, $sp, 0x28
    ctx->r18 = ADD32(ctx->r29, 0X28);
    // 0x8000A8C8: lw          $a0, 0x4F88($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4F88);
L_8000A8CC:
    // 0x8000A8CC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000A8D0: jal         0x800824B0
    // 0x8000A8D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000A8D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000A8D8: bnel        $v0, $s0, L_8000A8CC
    if (ctx->r2 != ctx->r16) {
        // 0x8000A8DC: lw          $a0, 0x4F88($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X4F88);
            goto L_8000A8CC;
    }
    goto skip_0;
    // 0x8000A8DC: lw          $a0, 0x4F88($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4F88);
    skip_0:
    // 0x8000A8E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000A8E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000A8E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A8EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000A8F0: jr          $ra
    // 0x8000A8F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000A8F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006B454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B454: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006B458: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x8006B45C: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8006B460: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8006B464: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006B468: multu       $t7, $a3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B46C: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x8006B470: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8006B474: lh          $s0, 0x22($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X22);
    // 0x8006B478: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8006B47C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8006B480: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006B484: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8006B488: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8006B48C: sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7 << 1);
    // 0x8006B490: mflo        $t8
    ctx->r24 = lo;
    // 0x8006B494: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8006B498: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8006B49C: bne         $at, $zero, L_8006B508
    if (ctx->r1 != 0) {
        // 0x8006B4A0: addu        $a2, $a2, $t1
        ctx->r6 = ADD32(ctx->r6, ctx->r9);
            goto L_8006B508;
    }
    // 0x8006B4A0: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
L_8006B4A4:
    // 0x8006B4A4: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x8006B4A8: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8006B4AC: addiu       $s0, $s0, -0x5
    ctx->r16 = ADD32(ctx->r16, -0X5);
    // 0x8006B4B0: sh          $t2, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r10;
    // 0x8006B4B4: lhu         $t3, 0x0($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X0);
    // 0x8006B4B8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006B4BC: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8006B4C0: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x8006B4C4: lhu         $t4, 0x0($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X0);
    // 0x8006B4C8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006B4CC: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8006B4D0: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x8006B4D4: lhu         $t5, 0x0($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X0);
    // 0x8006B4D8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006B4DC: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8006B4E0: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x8006B4E4: lhu         $t7, 0x0($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X0);
    // 0x8006B4E8: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8006B4EC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006B4F0: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006B4F4: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8006B4F8: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8006B4FC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006B500: beq         $at, $zero, L_8006B4A4
    if (ctx->r1 == 0) {
        // 0x8006B504: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_8006B4A4;
    }
    // 0x8006B504: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
L_8006B508:
    // 0x8006B508: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x8006B50C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006B510: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8006B514: beq         $t0, $zero, L_8006B548
    if (ctx->r8 == 0) {
        // 0x8006B518: sra         $s0, $s0, 16
        ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
            goto L_8006B548;
    }
    // 0x8006B518: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006B51C: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8006B520: sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7 << 1);
L_8006B524:
    // 0x8006B524: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x8006B528: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x8006B52C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006B530: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8006B534: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x8006B538: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006B53C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006B540: bne         $t0, $zero, L_8006B524
    if (ctx->r8 != 0) {
        // 0x8006B544: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_8006B524;
    }
    // 0x8006B544: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
L_8006B548:
    // 0x8006B548: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8006B54C: jr          $ra
    // 0x8006B550: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006B550: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800462C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800462C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800462C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800462C8: jal         0x800461F4
    // 0x800462CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800461F4(rdram, ctx);
        goto after_0;
    // 0x800462CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800462D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800462D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800462D8: jr          $ra
    // 0x800462DC: nop

    return;
    // 0x800462DC: nop

;}
RECOMP_FUNC void func_8067B8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067B8C4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8067B8C8: lw          $t6, 0x168($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X168);
    // 0x8067B8CC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067B8D0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8067B8D4: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x8067B8D8: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x8067B8DC: sll         $t8, $a2, 6
    ctx->r24 = S32(ctx->r6 << 6);
    // 0x8067B8E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8067B8E4: lui         $t3, 0xFD50
    ctx->r11 = S32(0XFD50 << 16);
    // 0x8067B8E8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8067B8EC: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x8067B8F0: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8067B8F4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067B8F8: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x8067B8FC: lui         $t5, 0xF550
    ctx->r13 = S32(0XF550 << 16);
    // 0x8067B900: addiu       $t4, $a3, 0x8
    ctx->r12 = ADD32(ctx->r7, 0X8);
    // 0x8067B904: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8067B908: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x8067B90C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8067B910: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067B914: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8067B918: lui         $t4, 0x701
    ctx->r12 = S32(0X701 << 16);
    // 0x8067B91C: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x8067B920: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8067B924: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8067B928: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8067B92C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067B930: ori         $t4, $t4, 0xF800
    ctx->r12 = ctx->r12 | 0XF800;
    // 0x8067B934: lui         $t3, 0xF300
    ctx->r11 = S32(0XF300 << 16);
    // 0x8067B938: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x8067B93C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8067B940: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x8067B944: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8067B948: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067B94C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8067B950: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x8067B954: addiu       $t5, $a3, 0x8
    ctx->r13 = ADD32(ctx->r7, 0X8);
    // 0x8067B958: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8067B95C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8067B960: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8067B964: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067B968: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8067B96C: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x8067B970: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x8067B974: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8067B978: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x8067B97C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8067B980: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8067B984: ori         $t4, $t4, 0xC01C
    ctx->r12 = ctx->r12 | 0XC01C;
    // 0x8067B988: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x8067B98C: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x8067B990: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8067B994: sw          $t4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r12;
    // 0x8067B998: jr          $ra
    // 0x8067B99C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    return;
    // 0x8067B99C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
;}
RECOMP_FUNC void func_80441FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441FF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80441FF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80441FFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80442000: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80442004: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x80442008: addiu       $a0, $zero, 0x4091
    ctx->r4 = ADD32(0, 0X4091);
    // 0x8044200C: jal         0x80047090
    // 0x80442010: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80442010: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80442014: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80442018: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8044201C: bne         $v0, $at, L_8044202C
    if (ctx->r2 != ctx->r1) {
        // 0x80442020: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_8044202C;
    }
    // 0x80442020: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x80442024: b           L_80442174
    // 0x80442028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80442174;
    // 0x80442028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8044202C:
    // 0x8044202C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80442030: lui         $at, 0x4091
    ctx->r1 = S32(0X4091 << 16);
    // 0x80442034: or          $a0, $t0, $at
    ctx->r4 = ctx->r8 | ctx->r1;
    // 0x80442038: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8044203C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80442040: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80442044: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x80442048: lw          $a1, 0x3C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X3C);
    // 0x8044204C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80442050: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
    // 0x80442054: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80442058: ori         $a3, $a3, 0x2666
    ctx->r7 = ctx->r7 | 0X2666;
    // 0x8044205C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80442060: jal         0x8004613C
    // 0x80442064: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80442064: nop

    after_1:
    // 0x80442068: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8044206C: lhu         $t0, 0x2A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2A);
    // 0x80442070: bne         $v0, $zero, L_80442080
    if (ctx->r2 != 0) {
        // 0x80442074: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80442080;
    }
    // 0x80442074: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80442078: b           L_80442174
    // 0x8044207C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80442174;
    // 0x8044207C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80442080:
    // 0x80442080: lhu         $t9, 0xE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XE);
    // 0x80442084: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
    // 0x80442088: andi        $t8, $t0, 0x3FF
    ctx->r24 = ctx->r8 & 0X3FF;
    // 0x8044208C: andi        $t1, $t9, 0xFC00
    ctx->r9 = ctx->r25 & 0XFC00;
    // 0x80442090: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x80442094: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80442098: lui         $t4, 0x8044
    ctx->r12 = S32(RELOC_HI16(95, 0X3D7C) << 16);
    // 0x8044209C: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    // 0x804420A0: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804420A4: sw          $t3, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r11;
    // 0x804420A8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804420AC: addiu       $t4, $t4, 0x2C7C
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(95, 0X3D7C));
    // 0x804420B0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x804420B4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804420B8: lw          $v0, 0x16C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X16C);
    // 0x804420BC: lbu         $t6, 0xD($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XD);
    // 0x804420C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804420C4: sb          $t6, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r14;
    // 0x804420C8: lbu         $t7, 0xE($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XE);
    // 0x804420CC: sb          $t7, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r15;
    // 0x804420D0: lbu         $t9, 0xF($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF);
    // 0x804420D4: sb          $t9, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r25;
    // 0x804420D8: lbu         $t8, 0x10($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X10);
    // 0x804420DC: jal         0x80441EB8
    // 0x804420E0: sb          $t8, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r24;
    func_80441EB8(rdram, ctx);
        goto after_2;
    // 0x804420E0: sb          $t8, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r24;
    after_2:
    // 0x804420E4: bne         $v0, $zero, L_804420FC
    if (ctx->r2 != 0) {
        // 0x804420E8: addiu       $t1, $zero, 0xF
        ctx->r9 = ADD32(0, 0XF);
            goto L_804420FC;
    }
    // 0x804420E8: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x804420EC: jal         0x800445A4
    // 0x804420F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x804420F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804420F4: b           L_80442174
    // 0x804420F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80442174;
    // 0x804420F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804420FC:
    // 0x804420FC: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x80442100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80442104: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80442108: sw          $t1, 0x262C($t2)
    MEM_W(0X262C, ctx->r10) = ctx->r9;
    // 0x8044210C: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x80442110: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80442114: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80442118: swc1        $f10, 0x1C24($t3)
    MEM_W(0X1C24, ctx->r11) = ctx->f10.u32l;
    // 0x8044211C: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    // 0x80442120: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EEC) << 16);
    // 0x80442124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80442128: swc1        $f16, 0x1C28($t4)
    MEM_W(0X1C28, ctx->r12) = ctx->f16.u32l;
    // 0x8044212C: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x80442130: lwc1        $f18, 0x3DEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EEC));
    // 0x80442134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80442138: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044213C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80442140: jal         0x80442188
    // 0x80442144: swc1        $f18, 0x1C2C($t5)
    MEM_W(0X1C2C, ctx->r13) = ctx->f18.u32l;
    func_80442188(rdram, ctx);
        goto after_4;
    // 0x80442144: swc1        $f18, 0x1C2C($t5)
    MEM_W(0X1C2C, ctx->r13) = ctx->f18.u32l;
    after_4:
    // 0x80442148: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(95, 0X154) << 16);
    // 0x8044214C: addiu       $t6, $t6, -0xFAC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(95, 0X154));
    // 0x80442150: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80442154: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    // 0x80442158: sh          $t7, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r15;
    // 0x8044215C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80442160: jal         0x80047F9C
    // 0x80442164: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x80442164: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80442168: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8044216C: sb          $t9, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r25;
    // 0x80442170: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80442174:
    // 0x80442174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80442178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8044217C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80442180: jr          $ra
    // 0x80442184: nop

    return;
    // 0x80442184: nop

;}
RECOMP_FUNC void func_807095E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807095E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807095E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807095EC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x807095F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807095F4: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x807095F8: beq         $a0, $t7, L_80709610
    if (ctx->r4 == ctx->r15) {
        // 0x807095FC: nop
    
            goto L_80709610;
    }
    // 0x807095FC: nop

    // 0x80709600: jal         0x807095C4
    // 0x80709604: nop

    func_807095C4(rdram, ctx);
        goto after_0;
    // 0x80709604: nop

    after_0:
    // 0x80709608: b           L_80709610
    // 0x8070960C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80709610;
    // 0x8070960C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80709610:
    // 0x80709610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80709614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80709618: jr          $ra
    // 0x8070961C: nop

    return;
    // 0x8070961C: nop

;}
RECOMP_FUNC void func_804B6924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6924: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804B6928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B692C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B6930: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x804B6934: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804B6938: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B693C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x804B6940: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804B6944: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x804B6948: lbu         $t8, 0x2C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2C);
    // 0x804B694C: bnel        $t8, $zero, L_804B6970
    if (ctx->r24 != 0) {
        // 0x804B6950: addiu       $v0, $s0, 0xC4
        ctx->r2 = ADD32(ctx->r16, 0XC4);
            goto L_804B6970;
    }
    goto skip_0;
    // 0x804B6950: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x804B6954: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x804B6958: slti        $v1, $v0, 0x3D
    ctx->r3 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x804B695C: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x804B6960: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x804B6964: beq         $v1, $zero, L_804B6998
    if (ctx->r3 == 0) {
        // 0x804B6968: sw          $t9, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r25;
            goto L_804B6998;
    }
    // 0x804B6968: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
    // 0x804B696C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
L_804B6970:
    // 0x804B6970: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x804B6974: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x804B6978: jal         0x804B6FF0
    // 0x804B697C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_0;
    // 0x804B697C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x804B6980: jal         0x8005FDC4
    // 0x804B6984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x804B6984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804B6988: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804B698C: jal         0x804B6580
    // 0x804B6990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804B6580(rdram, ctx);
        goto after_2;
    // 0x804B6990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x804B6994: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_804B6998:
    // 0x804B6998: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x804B699C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x804B69A0: jal         0x804B6580
    // 0x804B69A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804B6580(rdram, ctx);
        goto after_3;
    // 0x804B69A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x804B69A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804B69AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B69B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804B69B4: jr          $ra
    // 0x804B69B8: nop

    return;
    // 0x804B69B8: nop

;}
RECOMP_FUNC void func_807885D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807885D0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x807885D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807885D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x807885DC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807885E0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x807885E4: nop

    // 0x807885E8: bc1fl       L_807885F8
    if (!c1cs) {
        // 0x807885EC: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_807885F8;
    }
    goto skip_0;
    // 0x807885EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x807885F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x807885F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_807885F8:
    // 0x807885F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807885FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80788600: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80788604: nop

    // 0x80788608: bc1f        L_80788614
    if (!c1cs) {
        // 0x8078860C: nop
    
            goto L_80788614;
    }
    // 0x8078860C: nop

    // 0x80788610: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80788614:
    // 0x80788614: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80788618: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8078861C: lwc1        $f8, 0x10C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x80788620: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80788624: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80788628: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x8078862C: jr          $ra
    // 0x80788630: swc1        $f18, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80788630: swc1        $f18, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80059278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005927C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80059284: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80059288: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    // 0x8005928C: lh          $a2, 0x13C($t6)
    ctx->r6 = MEM_H(ctx->r14, 0X13C);
    // 0x80059290: lh          $a3, 0x13E($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X13E);
    // 0x80059294: jal         0x800591EC
    // 0x80059298: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_800591EC(rdram, ctx);
        goto after_0;
    // 0x80059298: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x8005929C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800592A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800592A4: jr          $ra
    // 0x800592A8: nop

    return;
    // 0x800592A8: nop

;}
RECOMP_FUNC void func_80674730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80674730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80674734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80674738: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8067473C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80674740: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80674744: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(529, 0X1B4C) << 16);
    // 0x80674748: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8067474C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80674750: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80674754: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80674758: lw          $t8, 0x4B2C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(529, 0X1B4C));
    // 0x8067475C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80674760: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80674764: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80674768: jal         0x80048490
    // 0x8067476C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8067476C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80674770: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80674774: jal         0x80048378
    // 0x80674778: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80674778: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8067477C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80674780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80674784: jr          $ra
    // 0x80674788: nop

    return;
    // 0x80674788: nop

;}
RECOMP_FUNC void func_8006BDA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BDA4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8006BDA8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8006BDAC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8006BDB0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8006BDB4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006BDB8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006BDBC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006BDC0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006BDC4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006BDC8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006BDCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006BDD0: lh          $s3, 0x0($a2)
    ctx->r19 = MEM_H(ctx->r6, 0X0);
    // 0x8006BDD4: lh          $t0, 0x2($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X2);
    // 0x8006BDD8: lh          $t1, 0x0($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X0);
    // 0x8006BDDC: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x8006BDE0: multu       $s3, $t0
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BDE4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8006BDE8: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8006BDEC: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x8006BDF0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8006BDF4: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8006BDF8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8006BDFC: mflo        $s6
    ctx->r22 = lo;
    // 0x8006BE00: nop

    // 0x8006BE04: nop

    // 0x8006BE08: div         $zero, $t1, $s3
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r19)));
    // 0x8006BE0C: mflo        $t6
    ctx->r14 = lo;
    // 0x8006BE10: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8006BE14: bne         $s3, $zero, L_8006BE20
    if (ctx->r19 != 0) {
        // 0x8006BE18: nop
    
            goto L_8006BE20;
    }
    // 0x8006BE18: nop

    // 0x8006BE1C: break       7
    do_break(2147925532);
L_8006BE20:
    // 0x8006BE20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BE24: bne         $s3, $at, L_8006BE38
    if (ctx->r19 != ctx->r1) {
        // 0x8006BE28: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006BE38;
    }
    // 0x8006BE28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006BE2C: bne         $t1, $at, L_8006BE38
    if (ctx->r9 != ctx->r1) {
        // 0x8006BE30: nop
    
            goto L_8006BE38;
    }
    // 0x8006BE30: nop

    // 0x8006BE34: break       6
    do_break(2147925556);
L_8006BE38:
    // 0x8006BE38: div         $zero, $v1, $t0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r8)));
    // 0x8006BE3C: mflo        $v0
    ctx->r2 = lo;
    // 0x8006BE40: or          $s7, $t6, $zero
    ctx->r23 = ctx->r14 | 0;
    // 0x8006BE44: bne         $t0, $zero, L_8006BE50
    if (ctx->r8 != 0) {
        // 0x8006BE48: nop
    
            goto L_8006BE50;
    }
    // 0x8006BE48: nop

    // 0x8006BE4C: break       7
    do_break(2147925580);
L_8006BE50:
    // 0x8006BE50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BE54: bne         $t0, $at, L_8006BE68
    if (ctx->r8 != ctx->r1) {
        // 0x8006BE58: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006BE68;
    }
    // 0x8006BE58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006BE5C: bne         $v1, $at, L_8006BE68
    if (ctx->r3 != ctx->r1) {
        // 0x8006BE60: nop
    
            goto L_8006BE68;
    }
    // 0x8006BE60: nop

    // 0x8006BE64: break       6
    do_break(2147925604);
L_8006BE68:
    // 0x8006BE68: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8006BE6C: blezl       $v0, L_8006BF20
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006BE70: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8006BF20;
    }
    goto skip_0;
    // 0x8006BE70: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8006BE74: multu       $t1, $t0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BE78: lw          $s1, 0x88($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X88);
    // 0x8006BE7C: mflo        $t7
    ctx->r15 = lo;
    // 0x8006BE80: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8006BE84: nop

L_8006BE88:
    // 0x8006BE88: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8006BE8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BE90: blezl       $t8, L_8006BF00
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8006BE94: lw          $t5, 0x54($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X54);
            goto L_8006BF00;
    }
    goto skip_1;
    // 0x8006BE94: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x8006BE98: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8006BE9C: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
L_8006BEA0:
    // 0x8006BEA0: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8006BEA4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006BEA8: addiu       $a0, $a0, 0x1050
    ctx->r4 = ADD32(ctx->r4, 0X1050);
    // 0x8006BEAC: slti        $at, $v0, 0x12C
    ctx->r1 = SIGNED(ctx->r2) < 0X12C ? 1 : 0;
    // 0x8006BEB0: bne         $at, $zero, L_8006BEC4
    if (ctx->r1 != 0) {
        // 0x8006BEB4: nop
    
            goto L_8006BEC4;
    }
    // 0x8006BEB4: nop

    // 0x8006BEB8: jal         0x80071380
    // 0x8006BEBC: addiu       $a1, $zero, 0x669
    ctx->r5 = ADD32(0, 0X669);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8006BEBC: addiu       $a1, $zero, 0x669
    ctx->r5 = ADD32(0, 0X669);
    after_0:
    // 0x8006BEC0: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
L_8006BEC4:
    // 0x8006BEC4: multu       $v0, $s6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BEC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006BECC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8006BED0: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8006BED4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8006BED8: mflo        $t9
    ctx->r25 = lo;
    // 0x8006BEDC: addu        $a2, $t9, $fp
    ctx->r6 = ADD32(ctx->r25, ctx->r30);
    // 0x8006BEE0: jal         0x8006BB04
    // 0x8006BEE4: nop

    func_8006BB04(rdram, ctx);
        goto after_1;
    // 0x8006BEE4: nop

    after_1:
    // 0x8006BEE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006BEEC: bne         $s0, $s7, L_8006BEA0
    if (ctx->r16 != ctx->r23) {
        // 0x8006BEF0: addu        $s2, $s2, $s3
        ctx->r18 = ADD32(ctx->r18, ctx->r19);
            goto L_8006BEA0;
    }
    // 0x8006BEF0: addu        $s2, $s2, $s3
    ctx->r18 = ADD32(ctx->r18, ctx->r19);
    // 0x8006BEF4: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8006BEF8: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8006BEFC: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
L_8006BF00:
    // 0x8006BF00: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8006BF04: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8006BF08: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8006BF0C: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8006BF10: bne         $at, $zero, L_8006BE88
    if (ctx->r1 != 0) {
        // 0x8006BF14: or          $s2, $t2, $zero
        ctx->r18 = ctx->r10 | 0;
            goto L_8006BE88;
    }
    // 0x8006BF14: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x8006BF18: sw          $s1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r17;
    // 0x8006BF1C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8006BF20:
    // 0x8006BF20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006BF24: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BF28: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006BF2C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006BF30: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006BF34: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006BF38: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006BF3C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8006BF40: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8006BF44: jr          $ra
    // 0x8006BF48: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8006BF48: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8006BF4C: nop

;}
RECOMP_FUNC void func_8076DE7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076DE7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8076DE80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076DE84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8076DE88: jal         0x8076DF28
    // 0x8076DE8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8076DF28(rdram, ctx);
        goto after_0;
    // 0x8076DE8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8076DE90: beq         $v0, $zero, L_8076DEF0
    if (ctx->r2 == 0) {
        // 0x8076DE94: lui         $t6, 0x8077
        ctx->r14 = S32(RELOC_HI16(766, 0X3A28) << 16);
            goto L_8076DEF0;
    }
    // 0x8076DE94: lui         $t6, 0x8077
    ctx->r14 = S32(RELOC_HI16(766, 0X3A28) << 16);
    // 0x8076DE98: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x8076DE9C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8076DEA0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8076DEA4: addiu       $t6, $t6, 0x218
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(766, 0X3A28));
    // 0x8076DEA8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8076DEAC: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8076DEB0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8076DEB4: jal         0x8076DF70
    // 0x8076DEB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8076DF70(rdram, ctx);
        goto after_1;
    // 0x8076DEB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8076DEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076DEC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076DEC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8076DEC8: jal         0x8076DD8C
    // 0x8076DECC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8076DD8C(rdram, ctx);
        goto after_2;
    // 0x8076DECC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8076DED0: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x8076DED4: lui         $t8, 0x8077
    ctx->r24 = S32(RELOC_HI16(766, 0X19A8) << 16);
    // 0x8076DED8: addiu       $t8, $t8, -0x1E68
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(766, 0X19A8));
    // 0x8076DEDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076DEE0: jal         0x8076DE4C
    // 0x8076DEE4: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    func_8076DE4C(rdram, ctx);
        goto after_3;
    // 0x8076DEE4: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    after_3:
    // 0x8076DEE8: b           L_8076DF18
    // 0x8076DEEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076DF18;
    // 0x8076DEEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076DEF0:
    // 0x8076DEF0: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    // 0x8076DEF4: beq         $a0, $zero, L_8076DF0C
    if (ctx->r4 == 0) {
        // 0x8076DEF8: nop
    
            goto L_8076DF0C;
    }
    // 0x8076DEF8: nop

    // 0x8076DEFC: jal         0x800445A4
    // 0x8076DF00: nop

    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8076DF00: nop

    after_4:
    // 0x8076DF04: b           L_8076DF18
    // 0x8076DF08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076DF18;
    // 0x8076DF08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076DF0C:
    // 0x8076DF0C: jal         0x800445A4
    // 0x8076DF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x8076DF10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8076DF14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076DF18:
    // 0x8076DF18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8076DF1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8076DF20: jr          $ra
    // 0x8076DF24: nop

    return;
    // 0x8076DF24: nop

;}
RECOMP_FUNC void func_80027E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027E7C: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80027E80: lw          $t8, 0x15C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X15C);
    // 0x80027E84: addiu       $t6, $t6, 0x7DAC
    ctx->r14 = ADD32(ctx->r14, 0X7DAC);
    // 0x80027E88: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x80027E8C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80027E90: jal         0x80027D78
    // 0x80027E94: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    func_80027D78(rdram, ctx);
        goto after_0;
    // 0x80027E94: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    after_0:
    // 0x80027E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027EA0: jr          $ra
    // 0x80027EA4: nop

    return;
    // 0x80027EA4: nop

;}
RECOMP_FUNC void func_80553924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553924: lwc1        $f4, 0xDB8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XDB8);
    // 0x80553928: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8055392C: jr          $ra
    // 0x80553930: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80553930: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8040A0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040A0F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040A0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040A0F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040A0FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8040A100: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8040A104: jal         0x80409928
    // 0x8040A108: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80409928(rdram, ctx);
        goto after_0;
    // 0x8040A108: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8040A10C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8040A110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040A114: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8040A118: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8040A11C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8040A120: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8040A124: jal         0x80409928
    // 0x8040A128: nop

    func_80409928(rdram, ctx);
        goto after_1;
    // 0x8040A128: nop

    after_1:
    // 0x8040A12C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040A130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040A134: jr          $ra
    // 0x8040A138: nop

    return;
    // 0x8040A138: nop

;}
RECOMP_FUNC void func_8074118C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8074118C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80741190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80741194: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80741198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8074119C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x807411A0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x807411A4: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x807411A8: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x807411AC: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x807411B0: addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // 0x807411B4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x807411B8: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
    // 0x807411BC: jal         0x80740E70
    // 0x807411C0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80740E70(rdram, ctx);
        goto after_0;
    // 0x807411C0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x807411C4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x807411C8: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807411CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x807411D0: lbu         $t8, 0x10($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X10);
    // 0x807411D4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x807411D8: bgez        $t8, L_807411EC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x807411DC: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_807411EC;
    }
    // 0x807411DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807411E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807411E4: nop

    // 0x807411E8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_807411EC:
    // 0x807411EC: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x807411F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807411F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x807411F8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x807411FC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80741200: nop

    // 0x80741204: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80741208: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8074120C: nop

    // 0x80741210: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80741214: beql        $t0, $zero, L_80741264
    if (ctx->r8 == 0) {
        // 0x80741218: mfc1        $t0, $f4
        ctx->r8 = (int32_t)ctx->f4.u32l;
            goto L_80741264;
    }
    goto skip_0;
    // 0x80741218: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x8074121C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80741220: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80741224: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80741228: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8074122C: nop

    // 0x80741230: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80741234: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80741238: nop

    // 0x8074123C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80741240: bne         $t0, $zero, L_80741258
    if (ctx->r8 != 0) {
        // 0x80741244: nop
    
            goto L_80741258;
    }
    // 0x80741244: nop

    // 0x80741248: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8074124C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80741250: b           L_80741270
    // 0x80741254: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_80741270;
    // 0x80741254: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80741258:
    // 0x80741258: b           L_80741270
    // 0x8074125C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_80741270;
    // 0x8074125C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80741260: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
L_80741264:
    // 0x80741264: nop

    // 0x80741268: bltz        $t0, L_80741258
    if (SIGNED(ctx->r8) < 0) {
        // 0x8074126C: nop
    
            goto L_80741258;
    }
    // 0x8074126C: nop

L_80741270:
    // 0x80741270: sb          $t0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r8;
    // 0x80741274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80741278: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8074127C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80741280: jr          $ra
    // 0x80741284: nop

    return;
    // 0x80741284: nop

;}
RECOMP_FUNC void func_806A98AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A98AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A98B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A98B4: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806A98B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806A98BC: beq         $t6, $zero, L_806A98F8
    if (ctx->r14 == 0) {
        // 0x806A98C0: nop
    
            goto L_806A98F8;
    }
    // 0x806A98C0: nop

    // 0x806A98C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806A98C8: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806A98CC: jalr        $t9
    // 0x806A98D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806A98D0: nop

    after_0:
    // 0x806A98D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806A98D8: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806A98DC: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806A98E0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x806A98E4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x806A98E8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806A98EC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x806A98F0: b           L_806A98F8
    // 0x806A98F4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806A98F8;
    // 0x806A98F4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806A98F8:
    // 0x806A98F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A98FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806A9900: jr          $ra
    // 0x806A9904: nop

    return;
    // 0x806A9904: nop

;}
RECOMP_FUNC void func_804357E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804357E4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x804357E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804357EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804357F0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x804357F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804357F8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804357FC: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80435800: addiu       $v1, $v0, 0xE8C
    ctx->r3 = ADD32(ctx->r2, 0XE8C);
L_80435804:
    // 0x80435804: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80435808: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8043580C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80435810: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80435814: addiu       $v1, $v1, 0x0
    ctx->r3 = ADD32(ctx->r3, 0X0);
    // 0x80435818: bc1fl       L_8043582C
    if (!c1cs) {
        // 0x8043581C: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_8043582C;
    }
    goto skip_0;
    // 0x8043581C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_0:
    // 0x80435820: b           L_8043583C
    // 0x80435824: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
        goto L_8043583C;
    // 0x80435824: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80435828: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_8043582C:
    // 0x8043582C: nop

    // 0x80435830: bc1fl       L_80435840
    if (!c1cs) {
        // 0x80435834: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80435840;
    }
    goto skip_1;
    // 0x80435834: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_1:
    // 0x80435838: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_8043583C:
    // 0x8043583C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80435840:
    // 0x80435840: nop

    // 0x80435844: bc1fl       L_80435854
    if (!c1cs) {
        // 0x80435848: swc1        $f0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
            goto L_80435854;
    }
    goto skip_2;
    // 0x80435848: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    skip_2:
    // 0x8043584C: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80435850: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_80435854:
    // 0x80435854: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x80435858: bgez        $a1, L_80435804
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8043585C: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80435804;
    }
    // 0x8043585C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80435860: jr          $ra
    // 0x80435864: nop

    return;
    // 0x80435864: nop

;}
RECOMP_FUNC void func_8004AF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004AF8C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8004AF90: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8004AF94: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004AF98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004AF9C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8004AFA0: lw          $a0, 0x174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X174);
    // 0x8004AFA4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8004AFA8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004AFAC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004AFB0: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004AFB4: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8004AFB8: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004AFBC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004AFC0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8004AFC4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004AFC8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8004AFCC: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8004AFD0: jal         0x80049864
    // 0x8004AFD4: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    func_80049864(rdram, ctx);
        goto after_0;
    // 0x8004AFD4: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004AFD8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8004AFDC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8004AFE0: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8004AFE4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8004AFE8: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8004AFEC: lwc1        $f6, 0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8004AFF0: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8004AFF4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004AFF8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8004AFFC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004B000: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8004B004: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8004B008: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x8004B00C: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004B010: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8004B014: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8004B018: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8004B01C: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8004B020: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x8004B024: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8004B028: sh          $t6, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r14;
    // 0x8004B02C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8004B030: srav        $t6, $t5, $t4
    ctx->r14 = S32(SIGNED(ctx->r13) >> (ctx->r12 & 31));
    // 0x8004B034: addiu       $t3, $v1, 0xC
    ctx->r11 = ADD32(ctx->r3, 0XC);
    // 0x8004B038: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8004B03C: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8004B040: andi        $t8, $t0, 0xF
    ctx->r24 = ctx->r8 & 0XF;
    // 0x8004B044: sh          $t8, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r24;
    // 0x8004B048: lh          $t9, 0x48($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X48);
    // 0x8004B04C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8004B050: sh          $t6, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r14;
    // 0x8004B054: subu        $t2, $t1, $t9
    ctx->r10 = SUB32(ctx->r9, ctx->r25);
    // 0x8004B058: sh          $t2, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r10;
    // 0x8004B05C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8004B060: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8004B064: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8004B068: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x8004B06C: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8004B070: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x8004B074: srl         $t5, $v0, 6
    ctx->r13 = S32(U32(ctx->r2) >> 6);
    // 0x8004B078: andi        $t7, $v0, 0x3F
    ctx->r15 = ctx->r2 & 0X3F;
    // 0x8004B07C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004B080: sll         $t4, $t5, 8
    ctx->r12 = S32(ctx->r13 << 8);
    // 0x8004B084: addu        $t1, $t4, $t8
    ctx->r9 = ADD32(ctx->r12, ctx->r24);
    // 0x8004B088: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8004B08C: lw          $t2, 0xA24($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XA24);
    // 0x8004B090: andi        $t4, $t6, 0xFFFF
    ctx->r12 = ctx->r14 & 0XFFFF;
    // 0x8004B094: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x8004B098: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x8004B09C: and         $t8, $t7, $t4
    ctx->r24 = ctx->r15 & ctx->r12;
    // 0x8004B0A0: beql        $t8, $zero, L_8004B140
    if (ctx->r24 == 0) {
        // 0x8004B0A4: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004B140;
    }
    goto skip_0;
    // 0x8004B0A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8004B0A8: lbu         $t1, 0x0($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X0);
    // 0x8004B0AC: lhu         $t2, 0x38($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X38);
    // 0x8004B0B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004B0B4: andi        $t9, $t1, 0x1
    ctx->r25 = ctx->r9 & 0X1;
    // 0x8004B0B8: beql        $t9, $zero, L_8004B140
    if (ctx->r25 == 0) {
        // 0x8004B0BC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004B140;
    }
    goto skip_1;
    // 0x8004B0BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x8004B0C0: sh          $t2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r10;
    // 0x8004B0C4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8004B0C8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8004B0CC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8004B0D0: jal         0x8004AD9C
    // 0x8004B0D4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_8004AD9C(rdram, ctx);
        goto after_1;
    // 0x8004B0D4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8004B0D8: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8004B0DC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8004B0E0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8004B0E4: bne         $at, $zero, L_8004B118
    if (ctx->r1 != 0) {
        // 0x8004B0E8: lwc1        $f2, 0x2C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8004B118;
    }
    // 0x8004B0E8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004B0EC: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8004B0F0: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8004B0F4: lhu         $t6, 0x22($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X22);
    // 0x8004B0F8: lwc1        $f16, 0x4($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8004B0FC: lwc1        $f18, 0x88($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X88);
    // 0x8004B100: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004B104: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8004B108: sub.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8004B10C: lwc1        $f4, 0x8B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X8B8);
    // 0x8004B110: b           L_8004B144
    // 0x8004B114: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
        goto L_8004B144;
    // 0x8004B114: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
L_8004B118:
    // 0x8004B118: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8004B11C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8004B120: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004B124: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004B128: sb          $t7, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r15;
    // 0x8004B12C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004B130: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8004B134: b           L_8004B144
    // 0x8004B138: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
        goto L_8004B144;
    // 0x8004B138: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8004B13C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8004B140:
    // 0x8004B140: nop

L_8004B144:
    // 0x8004B144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004B148: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8004B14C: jr          $ra
    // 0x8004B150: nop

    return;
    // 0x8004B150: nop

;}
RECOMP_FUNC void func_8000471C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000471C: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x80004720: lui         $t9, 0x8009
    ctx->r25 = S32(0X8009 << 16);
    // 0x80004724: addiu       $t9, $t9, 0x7638
    ctx->r25 = ADD32(ctx->r25, 0X7638);
    // 0x80004728: addiu       $t8, $t7, -0x10
    ctx->r24 = ADD32(ctx->r15, -0X10);
    // 0x8000472C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80004730: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80004734: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80004738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000473C:
    // 0x8000473C: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x80004740: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80004744: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80004748: sh          $t0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r8;
    // 0x8000474C: lh          $t1, 0x2($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X2);
    // 0x80004750: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80004754: sh          $t1, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r9;
    // 0x80004758: lh          $t2, -0x4($a2)
    ctx->r10 = MEM_H(ctx->r6, -0X4);
    // 0x8000475C: sh          $t2, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r10;
    // 0x80004760: lh          $t3, -0x2($a2)
    ctx->r11 = MEM_H(ctx->r6, -0X2);
    // 0x80004764: bne         $v0, $a0, L_8000473C
    if (ctx->r2 != ctx->r4) {
        // 0x80004768: sh          $t3, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r11;
            goto L_8000473C;
    }
    // 0x80004768: sh          $t3, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r11;
    // 0x8000476C: jr          $ra
    // 0x80004770: nop

    return;
    // 0x80004770: nop

;}
