#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8005FEBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FEBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FEC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FEC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005FEC8: jal         0x80049018
    // 0x8005FECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8005FECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005FED0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FED4: beq         $v0, $zero, L_8005FF04
    if (ctx->r2 == 0) {
        // 0x8005FED8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8005FF04;
    }
    // 0x8005FED8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005FEDC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FEE0: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8005FEE4: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8005FEE8: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x8005FEEC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8005FEF0: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005FEF4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005FEF8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005FEFC: b           L_8005FF28
    // 0x8005FF00: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
        goto L_8005FF28;
    // 0x8005FF00: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
L_8005FF04:
    // 0x8005FF04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FF08: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8005FF0C: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x8005FF10: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x8005FF14: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8005FF18: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8005FF1C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005FF20: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005FF24: add.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f16.fl;
L_8005FF28:
    // 0x8005FF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FF2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005FF30: jr          $ra
    // 0x8005FF34: nop

    return;
    // 0x8005FF34: nop

;}
RECOMP_FUNC void DmaMgr_Read(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DB60: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8007DB64: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8007DB68: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8007DB6C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8007DB70: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8007DB74: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8007DB78: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8007DB7C: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x8007DB80: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8007DB84: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x8007DB88: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x8007DB8C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8007DB90: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8007DB94: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8007DB98: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8007DB9C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8007DBA0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8007DBA4: jal         0x8008AE20
    // 0x8007DBA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8007DBA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007DBAC: lw          $s0, 0x84($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X84);
    // 0x8007DBB0: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x8007DBB4: lw          $s3, 0x78($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X78);
    // 0x8007DBB8: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x8007DBBC: beq         $at, $zero, L_8007DC08
    if (ctx->r1 == 0) {
        // 0x8007DBC0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8007DC08;
    }
L_8007DBC0:
    // 0x8007DBC0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8007DBC4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8007DBC8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8007DBCC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8007DBD0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8007DBD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007DBD8: jal         0x800891D0
    // 0x8007DBDC: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x8007DBDC: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    after_1:
    // 0x8007DBE0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8007DBE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007DBE8: jal         0x800824B0
    // 0x8007DBEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8007DBEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8007DBF0: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8007DBF4: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x8007DBF8: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
    // 0x8007DBFC: bne         $at, $zero, L_8007DBC0
    if (ctx->r1 != 0) {
        // 0x8007DC00: addu        $s3, $s3, $s0
        ctx->r19 = ADD32(ctx->r19, ctx->r16);
            goto L_8007DBC0;
    }
    // 0x8007DC00: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x8007DC04: sw          $s3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r19;
L_8007DC08:
    // 0x8007DC08: lw          $s3, 0x78($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X78);
    // 0x8007DC0C: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x8007DC10: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8007DC14: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8007DC18: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8007DC1C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8007DC20: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8007DC24: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8007DC28: jal         0x800891D0
    // 0x8007DC2C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x8007DC2C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_3:
    // 0x8007DC30: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8007DC34: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8007DC38: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8007DC3C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DC40: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8007DC44: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8007DC48: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8007DC4C: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x8007DC50: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8007DC54: jr          $ra
    // 0x8007DC58: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8007DC58: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8002C8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C8C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C8C8: jal         0x8002C7D8
    // 0x8002C8CC: nop

    func_8002C7D8(rdram, ctx);
        goto after_0;
    // 0x8002C8CC: nop

    after_0:
    // 0x8002C8D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C8D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002C8D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002C8DC: sw          $t6, -0x7640($at)
    MEM_W(-0X7640, ctx->r1) = ctx->r14;
    // 0x8002C8E0: jr          $ra
    // 0x8002C8E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002C8E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80446F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446F58: jr          $ra
    // 0x80446F5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80446F5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804A009C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A009C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A00A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A00A4: jal         0x804A0070
    // 0x804A00A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A0070(rdram, ctx);
        goto after_0;
    // 0x804A00A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A00AC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804A00B0: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x804A00B4: beql        $v0, $zero, L_804A00D4
    if (ctx->r2 == 0) {
        // 0x804A00B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A00D4;
    }
    goto skip_0;
    // 0x804A00B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A00BC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x804A00C0: beql        $a0, $zero, L_804A00D4
    if (ctx->r4 == 0) {
        // 0x804A00C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A00D4;
    }
    goto skip_1;
    // 0x804A00C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804A00C8: jal         0x800577D8
    // 0x804A00CC: nop

    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x804A00CC: nop

    after_1:
    // 0x804A00D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A00D4:
    // 0x804A00D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A00D8: jr          $ra
    // 0x804A00DC: nop

    return;
    // 0x804A00DC: nop

;}
RECOMP_FUNC void func_80461934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461934: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80461938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046193C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80461940: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80461944: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80461948: jal         0x80082730
    // 0x8046194C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    fsin(rdram, ctx);
        goto after_0;
    // 0x8046194C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80461950: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80461954: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80461958: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8046195C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80461960: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80461964: lwc1        $f4, 0x3C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x80461968: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8046196C: jal         0x8008D250
    // 0x80461970: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80461970: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x80461974: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80461978: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8046197C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80461980: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80461984: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80461988: lwc1        $f16, 0x40($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X40);
    // 0x8046198C: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80461990: jal         0x80081F80
    // 0x80461994: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    Math_FAsinF(rdram, ctx);
        goto after_2;
    // 0x80461994: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80461998: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8046199C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A28) << 16);
    // 0x804619A0: lwc1        $f8, 0x3FB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A28));
    // 0x804619A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804619A8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x804619AC: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x804619B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804619B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804619B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804619BC: jr          $ra
    // 0x804619C0: nop

    return;
    // 0x804619C0: nop

;}
RECOMP_FUNC void func_80460B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460B38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80460B3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80460B40: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80460B44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80460B48: jal         0x8004700C
    // 0x80460B4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80460B4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80460B50: beq         $v0, $zero, L_80460BC8
    if (ctx->r2 == 0) {
        // 0x80460B54: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80460BC8;
    }
    // 0x80460B54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80460B58: jal         0x8046088C
    // 0x80460B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8046088C(rdram, ctx);
        goto after_1;
    // 0x80460B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80460B60: jal         0x804608BC
    // 0x80460B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804608BC(rdram, ctx);
        goto after_2;
    // 0x80460B64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80460B68: jal         0x804609B4
    // 0x80460B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804609B4(rdram, ctx);
        goto after_3;
    // 0x80460B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80460B70: jal         0x80460ACC
    // 0x80460B74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80460ACC(rdram, ctx);
        goto after_4;
    // 0x80460B74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80460B78: jal         0x80460830
    // 0x80460B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80460830(rdram, ctx);
        goto after_5;
    // 0x80460B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80460B80: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x80460B84: bnel        $s1, $t6, L_80460BCC
    if (ctx->r17 != ctx->r14) {
        // 0x80460B88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80460BCC;
    }
    goto skip_0;
    // 0x80460B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80460B8C: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80460B90: lwc1        $f6, 0xC4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x80460B94: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80460B98: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80460B9C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80460BA0: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x80460BA4: lwc1        $f16, 0xC8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x80460BA8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80460BAC: jal         0x80460954
    // 0x80460BB0: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    func_80460954(rdram, ctx);
        goto after_6;
    // 0x80460BB0: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    after_6:
    // 0x80460BB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80460BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80460BBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80460BC0: jal         0x80460DB8
    // 0x80460BC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80460DB8(rdram, ctx);
        goto after_7;
    // 0x80460BC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_80460BC8:
    // 0x80460BC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80460BCC:
    // 0x80460BCC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80460BD0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80460BD4: jr          $ra
    // 0x80460BD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80460BD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80066190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066194: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80066198: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006619C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800661A0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800661A4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800661A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800661AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800661B0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800661B4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800661B8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800661BC: jal         0x8007FFF0
    // 0x800661C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8007FFF0(rdram, ctx);
        goto after_0;
    // 0x800661C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800661C4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800661C8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800661CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800661D0: beql        $t6, $zero, L_800661EC
    if (ctx->r14 == 0) {
        // 0x800661D4: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_800661EC;
    }
    goto skip_0;
    // 0x800661D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x800661D8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800661DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800661E0: b           L_800661F0
    // 0x800661E4: nop

        goto L_800661F0;
    // 0x800661E4: nop

    // 0x800661E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_800661EC:
    // 0x800661EC: nop

L_800661F0:
    // 0x800661F0: beq         $t7, $zero, L_80066208
    if (ctx->r15 == 0) {
        // 0x800661F4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80066208;
    }
    // 0x800661F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800661F8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800661FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066200: b           L_80066214
    // 0x80066204: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
        goto L_80066214;
    // 0x80066204: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_80066208:
    // 0x80066208: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006620C: nop

    // 0x80066210: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_80066214:
    // 0x80066214: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80066218: jal         0x8007FE74
    // 0x8006621C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8007FE74(rdram, ctx);
        goto after_1;
    // 0x8006621C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80066220: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80066224: lwc1        $f10, 0xEEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XEEC);
    // 0x80066228: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8006622C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066230: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80066234: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80066238: jal         0x8007FF58
    // 0x8006623C: nop

    func_8007FF58(rdram, ctx);
        goto after_2;
    // 0x8006623C: nop

    after_2:
    // 0x80066240: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80066244: lwc1        $f4, 0xEF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XEF0);
    // 0x80066248: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006624C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066250: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80066254: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80066258: jal         0x8007FF0C
    // 0x8006625C: nop

    func_8007FF0C(rdram, ctx);
        goto after_3;
    // 0x8006625C: nop

    after_3:
    // 0x80066260: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80066264: lwc1        $f10, 0xEF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XEF4);
    // 0x80066268: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8006626C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066270: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80066274: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80066278: jal         0x8007FEC8
    // 0x8006627C: nop

    func_8007FEC8(rdram, ctx);
        goto after_4;
    // 0x8006627C: nop

    after_4:
    // 0x80066280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066284: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80066288: jal         0x8007FE74
    // 0x8006628C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    func_8007FE74(rdram, ctx);
        goto after_5;
    // 0x8006628C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    after_5:
    // 0x80066290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066294: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80066298: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8006629C: jal         0x8007FFF0
    // 0x800662A0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_8007FFF0(rdram, ctx);
        goto after_6;
    // 0x800662A0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x800662A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800662A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800662AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800662B0: jr          $ra
    // 0x800662B4: nop

    return;
    // 0x800662B4: nop

;}
RECOMP_FUNC void func_8067B500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067B500: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8067B504: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067B508: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8067B50C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8067B510: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8067B514: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067B518: jal         0x80049D74
    // 0x8067B51C: lw          $a1, 0x174($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X174);
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x8067B51C: lw          $a1, 0x174($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X174);
    after_0:
    // 0x8067B520: lw          $t6, 0x174($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X174);
    // 0x8067B524: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8067B528: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8067B52C: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8067B530: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8067B534: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8067B538: beq         $t0, $zero, L_8067B5F8
    if (ctx->r8 == 0) {
        // 0x8067B53C: sh          $t9, 0x36($sp)
        MEM_H(0X36, ctx->r29) = ctx->r25;
            goto L_8067B5F8;
    }
    // 0x8067B53C: sh          $t9, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r25;
    // 0x8067B540: beq         $t0, $at, L_8067B5F8
    if (ctx->r8 == ctx->r1) {
        // 0x8067B544: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8067B5F8;
    }
    // 0x8067B544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067B548: jal         0x8067A2B4
    // 0x8067B54C: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    func_8067A2B4(rdram, ctx);
        goto after_1;
    // 0x8067B54C: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    after_1:
    // 0x8067B550: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x8067B554: addiu       $v1, $sp, 0x36
    ctx->r3 = ADD32(ctx->r29, 0X36);
    // 0x8067B558: beql        $t1, $zero, L_8067B5FC
    if (ctx->r9 == 0) {
        // 0x8067B55C: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_8067B5FC;
    }
    goto skip_0;
    // 0x8067B55C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8067B560: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8067B564: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8067B568: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8067B56C: bnel        $v0, $at, L_8067B5DC
    if (ctx->r2 != ctx->r1) {
        // 0x8067B570: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8067B5DC;
    }
    goto skip_1;
    // 0x8067B570: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    skip_1:
    // 0x8067B574: lbu         $a3, 0x1($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X1);
    // 0x8067B578: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x8067B57C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8067B580: andi        $a3, $a3, 0x3F
    ctx->r7 = ctx->r7 & 0X3F;
    // 0x8067B584: slti        $at, $a3, 0x20
    ctx->r1 = SIGNED(ctx->r7) < 0X20 ? 1 : 0;
    // 0x8067B588: beql        $at, $zero, L_8067B5A4
    if (ctx->r1 == 0) {
        // 0x8067B58C: slti        $at, $a3, 0x24
        ctx->r1 = SIGNED(ctx->r7) < 0X24 ? 1 : 0;
            goto L_8067B5A4;
    }
    goto skip_2;
    // 0x8067B58C: slti        $at, $a3, 0x24
    ctx->r1 = SIGNED(ctx->r7) < 0X24 ? 1 : 0;
    skip_2:
    // 0x8067B590: jal         0x8067AFC0
    // 0x8067B594: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8067AFC0(rdram, ctx);
        goto after_2;
    // 0x8067B594: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8067B598: b           L_8067B65C
    // 0x8067B59C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8067B65C;
    // 0x8067B59C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067B5A0: slti        $at, $a3, 0x24
    ctx->r1 = SIGNED(ctx->r7) < 0X24 ? 1 : 0;
L_8067B5A4:
    // 0x8067B5A4: bne         $at, $zero, L_8067B5C4
    if (ctx->r1 != 0) {
        // 0x8067B5A8: lhu         $a2, 0x36($sp)
        ctx->r6 = MEM_HU(ctx->r29, 0X36);
            goto L_8067B5C4;
    }
    // 0x8067B5A8: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x8067B5AC: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x8067B5B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8067B5B4: jal         0x8067B4A8
    // 0x8067B5B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8067B4A8(rdram, ctx);
        goto after_3;
    // 0x8067B5B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8067B5BC: b           L_8067B65C
    // 0x8067B5C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8067B65C;
    // 0x8067B5C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067B5C4:
    // 0x8067B5C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8067B5C8: jal         0x8067B4A8
    // 0x8067B5CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8067B4A8(rdram, ctx);
        goto after_4;
    // 0x8067B5CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8067B5D0: b           L_8067B65C
    // 0x8067B5D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8067B65C;
    // 0x8067B5D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067B5D8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
L_8067B5DC:
    // 0x8067B5DC: bne         $v0, $at, L_8067B5F8
    if (ctx->r2 != ctx->r1) {
        // 0x8067B5E0: lhu         $a2, 0x36($sp)
        ctx->r6 = MEM_HU(ctx->r29, 0X36);
            goto L_8067B5F8;
    }
    // 0x8067B5E0: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    // 0x8067B5E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8067B5E8: jal         0x8067B4D4
    // 0x8067B5EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8067B4D4(rdram, ctx);
        goto after_5;
    // 0x8067B5EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8067B5F0: b           L_8067B65C
    // 0x8067B5F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8067B65C;
    // 0x8067B5F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067B5F8:
    // 0x8067B5F8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_8067B5FC:
    // 0x8067B5FC: beql        $t2, $zero, L_8067B648
    if (ctx->r10 == 0) {
        // 0x8067B600: lwc1        $f12, 0xC8($s1)
        ctx->f12.u32l = MEM_W(ctx->r17, 0XC8);
            goto L_8067B648;
    }
    goto skip_3;
    // 0x8067B600: lwc1        $f12, 0xC8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC8);
    skip_3:
    // 0x8067B604: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8067B608: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8067B60C: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8067B610: jal         0x80066E88
    // 0x8067B614: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x8067B614: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x8067B618: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8067B61C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8067B620: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8067B624: jal         0x80066DE4
    // 0x8067B628: swc1        $f8, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f8.u32l;
    func_80066DE4(rdram, ctx);
        goto after_7;
    // 0x8067B628: swc1        $f8, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f8.u32l;
    after_7:
    // 0x8067B62C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8067B630: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8067B634: swc1        $f16, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f16.u32l;
    // 0x8067B638: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8067B63C: b           L_8067B658
    // 0x8067B640: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
        goto L_8067B658;
    // 0x8067B640: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x8067B644: lwc1        $f12, 0xC8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC8);
L_8067B648:
    // 0x8067B648: lwc1        $f14, 0xEC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8067B64C: jal         0x80065ABC
    // 0x8067B650: lw          $a2, 0xE0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_8;
    // 0x8067B650: lw          $a2, 0xE0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XE0);
    after_8:
    // 0x8067B654: swc1        $f0, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f0.u32l;
L_8067B658:
    // 0x8067B658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067B65C:
    // 0x8067B65C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8067B660: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8067B664: jr          $ra
    // 0x8067B668: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8067B668: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805DB22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DB22C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805DB230: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805DB234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DB238: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x805DB23C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805DB240: sh          $a1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r5;
    // 0x805DB244: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x805DB248: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x805DB24C: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x805DB250: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DB254: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X2804) << 16);
    // 0x805DB258: lwc1        $f10, -0x2AFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X2804));
    // 0x805DB25C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805DB260: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805DB264: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x805DB268: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805DB26C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x805DB270: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x805DB274: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x805DB278: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x805DB27C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x805DB280: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x805DB284: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x805DB288: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x805DB28C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x805DB290: lw          $t9, 0x54($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X54);
    // 0x805DB294: jalr        $t9
    // 0x805DB298: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805DB298: nop

    after_0:
    // 0x805DB29C: beq         $v0, $zero, L_805DB2C8
    if (ctx->r2 == 0) {
        // 0x805DB2A0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805DB2C8;
    }
    // 0x805DB2A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805DB2A4: sb          $zero, 0x17C($v0)
    MEM_B(0X17C, ctx->r2) = 0;
    // 0x805DB2A8: jal         0x8005FDC4
    // 0x805DB2AC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x805DB2AC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x805DB2B0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x805DB2B4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x805DB2B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805DB2BC: lw          $v0, 0x1F4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X1F4);
    // 0x805DB2C0: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x805DB2C4: sb          $t1, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r9;
L_805DB2C8:
    // 0x805DB2C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DB2CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805DB2D0: jr          $ra
    // 0x805DB2D4: nop

    return;
    // 0x805DB2D4: nop

;}
RECOMP_FUNC void func_8005DAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DAE4: lbu         $v0, 0xA80($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA80);
    // 0x8005DAE8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8005DAEC: addiu       $t7, $t7, 0x6344
    ctx->r15 = ADD32(ctx->r15, 0X6344);
    // 0x8005DAF0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8005DAF4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8005DAF8: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8005DAFC: sw          $t8, 0xA84($a0)
    MEM_W(0XA84, ctx->r4) = ctx->r24;
    // 0x8005DB00: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x8005DB04: sw          $t9, 0xA88($a0)
    MEM_W(0XA88, ctx->r4) = ctx->r25;
    // 0x8005DB08: lw          $t0, 0x34($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X34);
    // 0x8005DB0C: sw          $t0, 0xA8C($a0)
    MEM_W(0XA8C, ctx->r4) = ctx->r8;
    // 0x8005DB10: lw          $t1, 0x48($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X48);
    // 0x8005DB14: sw          $t1, 0xA90($a0)
    MEM_W(0XA90, ctx->r4) = ctx->r9;
    // 0x8005DB18: lw          $t2, 0x5C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X5C);
    // 0x8005DB1C: sw          $t2, 0xA94($a0)
    MEM_W(0XA94, ctx->r4) = ctx->r10;
    // 0x8005DB20: lw          $t3, 0x70($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X70);
    // 0x8005DB24: sw          $t3, 0xA98($a0)
    MEM_W(0XA98, ctx->r4) = ctx->r11;
    // 0x8005DB28: lw          $t4, 0x84($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X84);
    // 0x8005DB2C: jr          $ra
    // 0x8005DB30: sw          $t4, 0xA9C($a0)
    MEM_W(0XA9C, ctx->r4) = ctx->r12;
    return;
    // 0x8005DB30: sw          $t4, 0xA9C($a0)
    MEM_W(0XA9C, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void func_80707388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80707388: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8070738C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80707390: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80707394: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80707398: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8070739C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807073A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807073A4: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    // 0x807073A8: jal         0x80047090
    // 0x807073AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807073AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x807073B0: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x807073B4: beq         $a1, $v0, L_80707498
    if (ctx->r5 == ctx->r2) {
        // 0x807073B8: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80707498;
    }
    // 0x807073B8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x807073BC: beql        $a1, $v0, L_8070749C
    if (ctx->r5 == ctx->r2) {
        // 0x807073C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8070749C;
    }
    goto skip_0;
    // 0x807073C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x807073C4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x807073C8: addiu       $t2, $zero, 0x461F
    ctx->r10 = ADD32(0, 0X461F);
    // 0x807073CC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x807073D0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x807073D4: andi        $t9, $t7, 0x3
    ctx->r25 = ctx->r15 & 0X3;
    // 0x807073D8: bne         $t9, $zero, L_807073E4
    if (ctx->r25 != 0) {
        // 0x807073DC: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_807073E4;
    }
    // 0x807073DC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x807073E0: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
L_807073E4:
    // 0x807073E4: jal         0x80047090
    // 0x807073E8: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x807073E8: lhu         $a0, 0x36($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X36);
    after_1:
    // 0x807073EC: lhu         $v1, 0x36($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X36);
    // 0x807073F0: addiu       $at, $zero, 0x4605
    ctx->r1 = ADD32(0, 0X4605);
    // 0x807073F4: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x807073F8: beq         $v1, $at, L_8070740C
    if (ctx->r3 == ctx->r1) {
        // 0x807073FC: lui         $a0, 0x8070
        ctx->r4 = S32(RELOC_HI16(712, 0X758) << 16);
            goto L_8070740C;
    }
    // 0x807073FC: lui         $a0, 0x8070
    ctx->r4 = S32(RELOC_HI16(712, 0X758) << 16);
    // 0x80707400: addiu       $at, $zero, 0x461E
    ctx->r1 = ADD32(0, 0X461E);
    // 0x80707404: bne         $v1, $at, L_80707434
    if (ctx->r3 != ctx->r1) {
        // 0x80707408: sll         $t4, $v1, 16
        ctx->r12 = S32(ctx->r3 << 16);
            goto L_80707434;
    }
    // 0x80707408: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
L_8070740C:
    // 0x8070740C: lwc1        $f4, 0x44($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80707410: sll         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3 << 16);
    // 0x80707414: lw          $a2, 0x3C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X3C);
    // 0x80707418: lw          $a3, 0x40($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X40);
    // 0x8070741C: or          $a1, $t3, $t0
    ctx->r5 = ctx->r11 | ctx->r8;
    // 0x80707420: addiu       $a0, $a0, 0x78F8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(712, 0X758));
    // 0x80707424: jal         0x80046804
    // 0x80707428: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_2;
    // 0x80707428: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8070742C: b           L_80707458
    // 0x80707430: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80707458;
    // 0x80707430: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80707434:
    // 0x80707434: lwc1        $f6, 0x44($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80707438: lui         $a0, 0x8070
    ctx->r4 = S32(RELOC_HI16(712, 0X768) << 16);
    // 0x8070743C: lw          $a2, 0x3C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X3C);
    // 0x80707440: lw          $a3, 0x40($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X40);
    // 0x80707444: addiu       $a0, $a0, 0x7908
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(712, 0X768));
    // 0x80707448: or          $a1, $t4, $t0
    ctx->r5 = ctx->r12 | ctx->r8;
    // 0x8070744C: jal         0x80046804
    // 0x80707450: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80046804(rdram, ctx);
        goto after_3;
    // 0x80707450: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80707454: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80707458:
    // 0x80707458: beql        $v0, $zero, L_8070749C
    if (ctx->r2 == 0) {
        // 0x8070745C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8070749C;
    }
    goto skip_1;
    // 0x8070745C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80707460: jal         0x80052BA4
    // 0x80707464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_4;
    // 0x80707464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80707468: jal         0x80044194
    // 0x8070746C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_5;
    // 0x8070746C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80707470: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x80707474: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80707478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070747C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80707480: jal         0x8005FCA8
    // 0x80707484: sh          $t5, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r13;
    func_8005FCA8(rdram, ctx);
        goto after_6;
    // 0x80707484: sh          $t5, 0x12($t7)
    MEM_H(0X12, ctx->r15) = ctx->r13;
    after_6:
    // 0x80707488: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8070748C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80707490: jal         0x80707264
    // 0x80707494: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    func_80707264(rdram, ctx);
        goto after_7;
    // 0x80707494: lhu         $a2, 0x36($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X36);
    after_7:
L_80707498:
    // 0x80707498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8070749C:
    // 0x8070749C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807074A0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807074A4: jr          $ra
    // 0x807074A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x807074A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80677FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80677FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80677FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80677FF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80677FFC: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80678000: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80678004: beql        $a1, $at, L_8067803C
    if (ctx->r5 == ctx->r1) {
        // 0x80678008: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8067803C;
    }
    goto skip_0;
    // 0x80678008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8067800C: jal         0x80067930
    // 0x80678010: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80678010: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_0:
    // 0x80678014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80678018: bne         $v0, $at, L_8067802C
    if (ctx->r2 != ctx->r1) {
        // 0x8067801C: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_8067802C;
    }
    // 0x8067801C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80678020: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80678024: jal         0x80067878
    // 0x80678028: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80678028: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    after_1:
L_8067802C:
    // 0x8067802C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80678030: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80678034: sh          $t8, 0x1F0($t9)
    MEM_H(0X1F0, ctx->r25) = ctx->r24;
    // 0x80678038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8067803C:
    // 0x8067803C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80678040: jr          $ra
    // 0x80678044: nop

    return;
    // 0x80678044: nop

;}
RECOMP_FUNC void func_806E7158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E715C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E7160: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806E7164: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806E7168: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(661, 0XB0) << 16);
    // 0x806E716C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x806E7170: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806E7174: addiu       $t7, $t7, 0x71F0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(661, 0XB0));
    // 0x806E7178: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x806E717C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x806E7180: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x806E7184: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806E7188: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x806E718C: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x806E7190: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E7194: jal         0x806E71AC
    // 0x806E7198: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_806E71AC(rdram, ctx);
        goto after_0;
    // 0x806E7198: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x806E719C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E71A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E71A4: jr          $ra
    // 0x806E71A8: nop

    return;
    // 0x806E71A8: nop

;}
RECOMP_FUNC void func_8006D34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D34C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006D350: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x8006D354: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8006D358: jr          $ra
    // 0x8006D35C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    return;
    // 0x8006D35C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_804CF34C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF34C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CF350: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804CF354: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804CF358: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804CF35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CF360: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804CF364: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804CF368: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804CF36C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804CF370: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804CF374: lui         $t2, 0x804D
    ctx->r10 = S32(RELOC_HI16(240, 0X1A90) << 16);
    // 0x804CF378: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804CF37C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804CF380: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804CF384: lw          $t2, -0x2C0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(240, 0X1A90));
    // 0x804CF388: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804CF38C: jal         0x804CF13C
    // 0x804CF390: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804CF13C(rdram, ctx);
        goto after_0;
    // 0x804CF390: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804CF394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CF398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CF39C: jr          $ra
    // 0x804CF3A0: nop

    return;
    // 0x804CF3A0: nop

;}
RECOMP_FUNC void func_807B9C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B9C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9C0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807B9C10: jal         0x80045A34
    // 0x807B9C14: addiu       $a1, $zero, 0x44C
    ctx->r5 = ADD32(0, 0X44C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807B9C14: addiu       $a1, $zero, 0x44C
    ctx->r5 = ADD32(0, 0X44C);
    after_0:
    // 0x807B9C18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B9C1C: bne         $v0, $zero, L_807B9C2C
    if (ctx->r2 != 0) {
        // 0x807B9C20: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_807B9C2C;
    }
    // 0x807B9C20: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807B9C24: b           L_807B9C38
    // 0x807B9C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B9C38;
    // 0x807B9C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B9C2C:
    // 0x807B9C2C: jal         0x807B9B84
    // 0x807B9C30: nop

    func_807B9B84(rdram, ctx);
        goto after_1;
    // 0x807B9C30: nop

    after_1:
    // 0x807B9C34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807B9C38:
    // 0x807B9C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B9C3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B9C40: jr          $ra
    // 0x807B9C44: nop

    return;
    // 0x807B9C44: nop

;}
RECOMP_FUNC void func_804B64A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B64A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B64A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B64AC: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x804B64B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804B64B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B64B8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x804B64BC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x804B64C0: nop

    // 0x804B64C4: bc1fl       L_804B64D8
    if (!c1cs) {
        // 0x804B64C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804B64D8;
    }
    goto skip_0;
    // 0x804B64C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804B64CC: jal         0x804B6FF0
    // 0x804B64D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_0;
    // 0x804B64D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804B64D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804B64D8:
    // 0x804B64D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B64DC: jr          $ra
    // 0x804B64E0: nop

    return;
    // 0x804B64E0: nop

;}
RECOMP_FUNC void func_80449F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449F04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80449F08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80449F0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80449F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449F14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80449F18: bne         $a2, $zero, L_80449F40
    if (ctx->r6 != 0) {
        // 0x80449F1C: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80449F40;
    }
    // 0x80449F1C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80449F20: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x80449F24: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80449F28: bgtz        $t7, L_80449F80
    if (SIGNED(ctx->r15) > 0) {
        // 0x80449F2C: sw          $t7, 0x28($v0)
        MEM_W(0X28, ctx->r2) = ctx->r15;
            goto L_80449F80;
    }
    // 0x80449F2C: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
    // 0x80449F30: jal         0x80446B80
    // 0x80449F34: nop

    func_80446B80(rdram, ctx);
        goto after_0;
    // 0x80449F34: nop

    after_0:
    // 0x80449F38: b           L_80449F84
    // 0x80449F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449F84;
    // 0x80449F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449F40:
    // 0x80449F40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80449F44: bnel        $a2, $at, L_80449F70
    if (ctx->r6 != ctx->r1) {
        // 0x80449F48: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80449F70;
    }
    goto skip_0;
    // 0x80449F48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80449F4C: jal         0x80446B28
    // 0x80449F50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446B28(rdram, ctx);
        goto after_1;
    // 0x80449F50: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80449F54: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449F58: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449F5C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80449F60: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449F64: b           L_80449F80
    // 0x80449F68: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80449F80;
    // 0x80449F68: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x80449F6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80449F70:
    // 0x80449F70: bnel        $a2, $at, L_80449F84
    if (ctx->r6 != ctx->r1) {
        // 0x80449F74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449F84;
    }
    goto skip_1;
    // 0x80449F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80449F78: jal         0x80446B80
    // 0x80449F7C: nop

    func_80446B80(rdram, ctx);
        goto after_2;
    // 0x80449F7C: nop

    after_2:
L_80449F80:
    // 0x80449F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449F84:
    // 0x80449F84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80449F88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449F8C: jr          $ra
    // 0x80449F90: nop

    return;
    // 0x80449F90: nop

;}
RECOMP_FUNC void func_800420B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800420B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800420BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800420C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800420C4: lw          $v0, 0xC0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC0);
    // 0x800420C8: beql        $v0, $zero, L_80042138
    if (ctx->r2 == 0) {
        // 0x800420CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80042138;
    }
    goto skip_0;
    // 0x800420CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800420D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800420D4: jal         0x80021A44
    // 0x800420D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80021A44(rdram, ctx);
        goto after_0;
    // 0x800420D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800420DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800420E0: jal         0x80032CA0
    // 0x800420E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80032CA0(rdram, ctx);
        goto after_1;
    // 0x800420E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800420E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800420EC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800420F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800420F4: lw          $t6, 0xD8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XD8);
    // 0x800420F8: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x800420FC: bne         $at, $zero, L_80042108
    if (ctx->r1 != 0) {
        // 0x80042100: nop
    
            goto L_80042108;
    }
    // 0x80042100: nop

    // 0x80042104: lw          $v0, 0xC0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC0);
L_80042108:
    // 0x80042108: jalr        $v0
    // 0x8004210C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x8004210C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x80042110: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80042114: lw          $t7, 0xD8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XD8);
    // 0x80042118: sw          $zero, 0xC0($a1)
    MEM_W(0XC0, ctx->r5) = 0;
    // 0x8004211C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80042120: beq         $at, $zero, L_8004212C
    if (ctx->r1 == 0) {
        // 0x80042124: nop
    
            goto L_8004212C;
    }
    // 0x80042124: nop

    // 0x80042128: sw          $zero, 0xD8($a1)
    MEM_W(0XD8, ctx->r5) = 0;
L_8004212C:
    // 0x8004212C: b           L_80042138
    // 0x80042130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80042138;
    // 0x80042130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80042134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80042138:
    // 0x80042138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004213C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042140: jr          $ra
    // 0x80042144: nop

    return;
    // 0x80042144: nop

;}
RECOMP_FUNC void func_80445C04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445C0C: jal         0x80445BDC
    // 0x80445C10: nop

    func_80445BDC(rdram, ctx);
        goto after_0;
    // 0x80445C10: nop

    after_0:
    // 0x80445C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445C18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445C1C: jr          $ra
    // 0x80445C20: nop

    return;
    // 0x80445C20: nop

;}
RECOMP_FUNC void func_806E07F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E07F8: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x806E07FC: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x806E0800: lw          $v1, 0x16C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X16C);
    // 0x806E0804: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x806E0808: lbu         $t7, 0x10($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X10);
    // 0x806E080C: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x806E0810: jr          $ra
    // 0x806E0814: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
    return;
    // 0x806E0814: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_8058111C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058111C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80581120: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80581124: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80581128: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8058112C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80581130: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80581134: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80581138: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8058113C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80581140: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80581144: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80581148: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8058114C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80581150: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80581154: andi        $s6, $a1, 0xFF
    ctx->r22 = ctx->r5 & 0XFF;
    // 0x80581158: addu        $s0, $v1, $at
    ctx->r16 = ADD32(ctx->r3, ctx->r1);
    // 0x8058115C: jal         0x8057EF98
    // 0x80581160: lw          $a0, 0x6A28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6A28);
    func_8057EF98(rdram, ctx);
        goto after_0;
    // 0x80581160: lw          $a0, 0x6A28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6A28);
    after_0:
    // 0x80581164: bltz        $v0, L_80581178
    if (SIGNED(ctx->r2) < 0) {
        // 0x80581168: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80581178;
    }
    // 0x80581168: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8058116C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80581170: bne         $at, $zero, L_80581198
    if (ctx->r1 != 0) {
        // 0x80581174: nop
    
            goto L_80581198;
    }
    // 0x80581174: nop

L_80581178:
    // 0x80581178: jal         0x8057EF98
    // 0x8058117C: lw          $a0, 0x6A24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6A24);
    func_8057EF98(rdram, ctx);
        goto after_1;
    // 0x8058117C: lw          $a0, 0x6A24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6A24);
    after_1:
    // 0x80581180: bltz        $v0, L_80581194
    if (SIGNED(ctx->r2) < 0) {
        // 0x80581184: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80581194;
    }
    // 0x80581184: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80581188: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8058118C: bne         $at, $zero, L_80581198
    if (ctx->r1 != 0) {
        // 0x80581190: nop
    
            goto L_80581198;
    }
    // 0x80581190: nop

L_80581194:
    // 0x80581194: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80581198:
    // 0x80581198: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x8058119C: addu        $s2, $s2, $v1
    ctx->r18 = ADD32(ctx->r18, ctx->r3);
    // 0x805811A0: lui         $s1, 0x8058
    ctx->r17 = S32(RELOC_HI16(399, 0X4638) << 16);
    // 0x805811A4: lbu         $s2, -0x71FC($s2)
    ctx->r18 = MEM_BU(ctx->r18, -0X71FC);
    // 0x805811A8: addiu       $s1, $s1, 0x3448
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(399, 0X4638));
    // 0x805811AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x805811B0: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x805811B4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_805811B8:
    // 0x805811B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x805811BC: jal         0x8057EF14
    // 0x805811C0: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    func_8057EF14(rdram, ctx);
        goto after_2;
    // 0x805811C0: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    after_2:
    // 0x805811C4: beql        $v0, $zero, L_805811EC
    if (ctx->r2 == 0) {
        // 0x805811C8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_805811EC;
    }
    goto skip_0;
    // 0x805811C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x805811CC: beql        $s0, $s2, L_805811E0
    if (ctx->r16 == ctx->r18) {
        // 0x805811D0: sb          $zero, 0x165($v0)
        MEM_B(0X165, ctx->r2) = 0;
            goto L_805811E0;
    }
    goto skip_1;
    // 0x805811D0: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    skip_1:
    // 0x805811D4: b           L_805811E0
    // 0x805811D8: sb          $s3, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r19;
        goto L_805811E0;
    // 0x805811D8: sb          $s3, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r19;
    // 0x805811DC: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
L_805811E0:
    // 0x805811E0: lw          $t6, 0x16C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X16C);
    // 0x805811E4: sb          $s6, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r22;
    // 0x805811E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_805811EC:
    // 0x805811EC: bne         $s0, $s4, L_805811B8
    if (ctx->r16 != ctx->r20) {
        // 0x805811F0: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_805811B8;
    }
    // 0x805811F0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x805811F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x805811F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805811FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80581200: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80581204: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80581208: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8058120C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80581210: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80581214: jr          $ra
    // 0x80581218: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80581218: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80028A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028A78: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028A7C: lwc1        $f2, -0x23C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X23C);
    // 0x80028A80: lwc1        $f0, 0xAC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x80028A84: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80028A88: lw          $v1, 0x34($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X34);
    // 0x80028A8C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80028A90: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028A94: addiu       $v0, $v0, 0x1D8
    ctx->r2 = ADD32(ctx->r2, 0X1D8);
    // 0x80028A98: bc1tl       L_80028AB8
    if (c1cs) {
        // 0x80028A9C: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80028AB8;
    }
    goto skip_0;
    // 0x80028A9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x80028AA0: lwc1        $f12, -0x238($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X238);
    // 0x80028AA4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80028AA8: nop

    // 0x80028AAC: bc1fl       L_80028B54
    if (!c1cs) {
        // 0x80028AB0: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80028B54;
    }
    goto skip_1;
    // 0x80028AB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x80028AB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80028AB8:
    // 0x80028AB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028ABC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80028AC0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80028AC4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80028AC8: lwc1        $f12, -0x234($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X234);
    // 0x80028ACC: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80028AD0: bc1f        L_80028B1C
    if (!c1cs) {
        // 0x80028AD4: addu        $t9, $t9, $t8
        ctx->r25 = ADD32(ctx->r25, ctx->r24);
            goto L_80028B1C;
    }
    // 0x80028AD4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80028AD8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80028ADC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80028AE0: lw          $t7, -0x2234($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2234);
    // 0x80028AE4: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80028AE8: beq         $at, $zero, L_80028B5C
    if (ctx->r1 == 0) {
        // 0x80028AEC: nop
    
            goto L_80028B5C;
    }
    // 0x80028AEC: nop

    // 0x80028AF0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80028AF4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80028AF8: nop

    // 0x80028AFC: bc1t        L_80028B5C
    if (c1cs) {
        // 0x80028B00: nop
    
            goto L_80028B5C;
    }
    // 0x80028B00: nop

    // 0x80028B04: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80028B08: nop

    // 0x80028B0C: bc1fl       L_80028B54
    if (!c1cs) {
        // 0x80028B10: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80028B54;
    }
    goto skip_2;
    // 0x80028B10: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_2:
    // 0x80028B14: jr          $ra
    // 0x80028B18: nop

    return;
    // 0x80028B18: nop

L_80028B1C:
    // 0x80028B1C: lw          $t9, -0x227C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X227C);
    // 0x80028B20: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80028B24: beq         $at, $zero, L_80028B5C
    if (ctx->r1 == 0) {
        // 0x80028B28: nop
    
            goto L_80028B5C;
    }
    // 0x80028B28: nop

    // 0x80028B2C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80028B30: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80028B34: nop

    // 0x80028B38: bc1t        L_80028B5C
    if (c1cs) {
        // 0x80028B3C: nop
    
            goto L_80028B5C;
    }
    // 0x80028B3C: nop

    // 0x80028B40: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80028B44: nop

    // 0x80028B48: bc1t        L_80028B5C
    if (c1cs) {
        // 0x80028B4C: nop
    
            goto L_80028B5C;
    }
    // 0x80028B4C: nop

    // 0x80028B50: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80028B54:
    // 0x80028B54: nop

    // 0x80028B58: swc1        $f6, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f6.u32l;
L_80028B5C:
    // 0x80028B5C: jr          $ra
    // 0x80028B60: nop

    return;
    // 0x80028B60: nop

;}
RECOMP_FUNC void func_8002DBA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DBA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DBAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DBB0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DBB4: jal         0x8002DB14
    // 0x8002DBB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8002DB14(rdram, ctx);
        goto after_0;
    // 0x8002DBB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002DBBC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DBC0: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x8002DBC4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8002DBC8: sb          $zero, 0xF7($v0)
    MEM_B(0XF7, ctx->r2) = 0;
    // 0x8002DBCC: sw          $t6, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r14;
    // 0x8002DBD0: sb          $t7, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = ctx->r15;
    // 0x8002DBD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DBD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DBDC: jr          $ra
    // 0x8002DBE0: nop

    return;
    // 0x8002DBE0: nop

;}
RECOMP_FUNC void func_804400F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804400F0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x804400F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x804400F8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x804400FC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80440100: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80440104: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x80440108: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x8044010C: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x80440110: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80440114: lw          $t3, 0x478($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X478);
    // 0x80440118: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8044011C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80440120: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80440124: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80440128: lw          $t9, 0x262C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X262C);
    // 0x8044012C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80440130: addiu       $a2, $t1, 0x4
    ctx->r6 = ADD32(ctx->r9, 0X4);
    // 0x80440134: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80440138: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8044013C: lwc1        $f6, 0x38($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X38);
    // 0x80440140: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x80440144: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x80440148: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8044014C: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80440150: jal         0x80081C64
    // 0x80440154: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80440154: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x80440158: lw          $v0, 0x3F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3F4);
    // 0x8044015C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80440160: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80440164: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80440168: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8044016C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80440170: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80440174: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80440178: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8044017C: div.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80440180: jal         0x80081C64
    // 0x80440184: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x80440184: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80440188: lw          $v0, 0x3F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3F4);
    // 0x8044018C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80440190: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80440194: lwc1        $f20, 0x4($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80440198: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8044019C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EBC) << 16);
    // 0x804401A0: div.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x804401A4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x804401A8: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x804401AC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x804401B0: lwc1        $f8, 0x3DBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EBC));
    // 0x804401B4: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x804401B8: nop

    // 0x804401BC: mul.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x804401C0: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x804401C4: jal         0x80081C64
    // 0x804401C8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_2;
    // 0x804401C8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x804401CC: lw          $v0, 0x3F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3F4);
    // 0x804401D0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x804401D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804401D8: lwc1        $f20, 0x4($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804401DC: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x804401E0: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x804401E4: div.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x804401E8: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x804401EC: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x804401F0: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x804401F4: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x804401F8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x804401FC: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80440200: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80440204: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80440208: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8044020C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80440210: addu        $a3, $t1, $t4
    ctx->r7 = ADD32(ctx->r9, ctx->r12);
    // 0x80440214: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x80440218: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8044021C: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80440220: addiu       $a3, $a3, 0x1CA8
    ctx->r7 = ADD32(ctx->r7, 0X1CA8);
    // 0x80440224: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80440228: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8044022C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80440230: mul.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80440234: bltz        $a1, L_80440434
    if (SIGNED(ctx->r5) < 0) {
        // 0x80440238: add.s       $f12, $f2, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
            goto L_80440434;
    }
    // 0x80440238: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8044023C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80440240: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80440244: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80440248: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8044024C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80440250: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80440254: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80440258: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8044025C: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80440260: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80440264: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80440268: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8044026C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80440270: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80440274: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80440278: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8044027C: lui         $t0, 0xF600
    ctx->r8 = S32(0XF600 << 16);
L_80440280:
    // 0x80440280: lw          $v0, 0x478($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X478);
    // 0x80440284: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80440288: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8044028C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80440290: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80440294: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80440298: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8044029C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x804402A0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x804402A4: mul.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x804402A8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x804402AC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x804402B0: mul.s       $f2, $f4, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x804402B4: bc1f        L_8044042C
    if (!c1cs) {
        // 0x804402B8: nop
    
            goto L_8044042C;
    }
    // 0x804402B8: nop

    // 0x804402BC: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x804402C0: nop

    // 0x804402C4: bc1f        L_8044042C
    if (!c1cs) {
        // 0x804402C8: nop
    
            goto L_8044042C;
    }
    // 0x804402C8: nop

    // 0x804402CC: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x804402D0: nop

    // 0x804402D4: bc1f        L_8044042C
    if (!c1cs) {
        // 0x804402D8: nop
    
            goto L_8044042C;
    }
    // 0x804402D8: nop

    // 0x804402DC: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x804402E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804402E4: bc1f        L_8044042C
    if (!c1cs) {
        // 0x804402E8: nop
    
            goto L_8044042C;
    }
    // 0x804402E8: nop

    // 0x804402EC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x804402F0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x804402F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x804402F8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x804402FC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80440300: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80440304: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80440308: nop

    // 0x8044030C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80440310: beql        $v0, $zero, L_80440360
    if (ctx->r2 == 0) {
        // 0x80440314: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_80440360;
    }
    goto skip_0;
    // 0x80440314: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80440318: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8044031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80440320: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80440324: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80440328: nop

    // 0x8044032C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80440330: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80440334: nop

    // 0x80440338: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8044033C: bne         $v0, $zero, L_80440354
    if (ctx->r2 != 0) {
        // 0x80440340: nop
    
            goto L_80440354;
    }
    // 0x80440340: nop

    // 0x80440344: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80440348: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044034C: b           L_8044036C
    // 0x80440350: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_8044036C;
    // 0x80440350: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80440354:
    // 0x80440354: b           L_8044036C
    // 0x80440358: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8044036C;
    // 0x80440358: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8044035C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_80440360:
    // 0x80440360: nop

    // 0x80440364: bltz        $v0, L_80440354
    if (SIGNED(ctx->r2) < 0) {
        // 0x80440368: nop
    
            goto L_80440354;
    }
    // 0x80440368: nop

L_8044036C:
    // 0x8044036C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80440370: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80440374: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80440378: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8044037C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80440380: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80440384: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x80440388: or          $t3, $t9, $t0
    ctx->r11 = ctx->r25 | ctx->r8;
    // 0x8044038C: cvt.w.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80440390: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x80440394: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x80440398: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8044039C: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x804403A0: nop

    // 0x804403A4: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x804403A8: beql        $v1, $zero, L_804403F8
    if (ctx->r3 == 0) {
        // 0x804403AC: mfc1        $v1, $f8
        ctx->r3 = (int32_t)ctx->f8.u32l;
            goto L_804403F8;
    }
    goto skip_1;
    // 0x804403AC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x804403B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804403B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804403B8: sub.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x804403BC: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x804403C0: nop

    // 0x804403C4: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x804403C8: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x804403CC: nop

    // 0x804403D0: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x804403D4: bne         $v1, $zero, L_804403EC
    if (ctx->r3 != 0) {
        // 0x804403D8: nop
    
            goto L_804403EC;
    }
    // 0x804403D8: nop

    // 0x804403DC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x804403E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804403E4: b           L_80440404
    // 0x804403E8: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80440404;
    // 0x804403E8: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_804403EC:
    // 0x804403EC: b           L_80440404
    // 0x804403F0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80440404;
    // 0x804403F0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x804403F4: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
L_804403F8:
    // 0x804403F8: nop

    // 0x804403FC: bltz        $v1, L_804403EC
    if (SIGNED(ctx->r3) < 0) {
        // 0x80440400: nop
    
            goto L_804403EC;
    }
    // 0x80440400: nop

L_80440404:
    // 0x80440404: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x80440408: andi        $t5, $t4, 0x3FF
    ctx->r13 = ctx->r12 & 0X3FF;
    // 0x8044040C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80440410: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80440414: andi        $t4, $v1, 0x3FF
    ctx->r12 = ctx->r3 & 0X3FF;
    // 0x80440418: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8044041C: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80440420: or          $t3, $t9, $t5
    ctx->r11 = ctx->r25 | ctx->r13;
    // 0x80440424: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x80440428: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8044042C:
    // 0x8044042C: bgez        $a1, L_80440280
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80440430: addiu       $a2, $a2, 0x30
        ctx->r6 = ADD32(ctx->r6, 0X30);
            goto L_80440280;
    }
    // 0x80440430: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
L_80440434:
    // 0x80440434: lui         $t6, 0xB800
    ctx->r14 = S32(0XB800 << 16);
    // 0x80440438: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8044043C: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80440440: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80440444: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80440448: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8044044C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80440450: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80440454: jr          $ra
    // 0x80440458: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80440458: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_804D8FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8FDC: lui         $v0, 0x804E
    ctx->r2 = S32(RELOC_HI16(258, 0XE150) << 16);
    // 0x804D8FE0: addiu       $v0, $v0, 0x6E20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(258, 0XE150));
    // 0x804D8FE4: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x804D8FE8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x804D8FEC: jr          $ra
    // 0x804D8FF0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x804D8FF0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80038F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038F98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80038F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038FA0: jal         0x8004700C
    // 0x80038FA4: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80038FA4: nop

    after_0:
    // 0x80038FA8: beql        $v0, $zero, L_80038FE0
    if (ctx->r2 == 0) {
        // 0x80038FAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038FE0;
    }
    goto skip_0;
    // 0x80038FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80038FB0: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80038FB4: lw          $a0, 0x1F4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F4);
    // 0x80038FB8: beql        $a0, $zero, L_80038FE0
    if (ctx->r4 == 0) {
        // 0x80038FBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038FE0;
    }
    goto skip_1;
    // 0x80038FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80038FC0: jal         0x80044658
    // 0x80038FC4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80044658(rdram, ctx);
        goto after_1;
    // 0x80038FC4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x80038FC8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80038FCC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80038FD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80038FD4: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x80038FD8: sw          $zero, 0x1F4($v1)
    MEM_W(0X1F4, ctx->r3) = 0;
    // 0x80038FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038FE0:
    // 0x80038FE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80038FE4: jr          $ra
    // 0x80038FE8: nop

    return;
    // 0x80038FE8: nop

;}
RECOMP_FUNC void func_8067BB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BB94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067BB98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067BB9C: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067BBA0: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(541, 0X3C10) << 16);
    // 0x8067BBA4: lui         $t7, 0x8068
    ctx->r15 = S32(RELOC_HI16(541, 0X3C08) << 16);
    // 0x8067BBA8: lw          $a3, 0x30($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X30);
    // 0x8067BBAC: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8067BBB0: addiu       $t7, $t7, -0x2748
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(541, 0X3C08));
    // 0x8067BBB4: sll         $t0, $a3, 2
    ctx->r8 = S32(ctx->r7 << 2);
    // 0x8067BBB8: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x8067BBBC: lw          $t6, -0x2740($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(541, 0X3C10));
    // 0x8067BBC0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8067BBC4: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8067BBC8: bne         $at, $zero, L_8067BBDC
    if (ctx->r1 != 0) {
        // 0x8067BBCC: nop
    
            goto L_8067BBDC;
    }
    // 0x8067BBCC: nop

    // 0x8067BBD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8067BBD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8067BBD8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8067BBDC:
    // 0x8067BBDC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X3D8C) << 16);
    // 0x8067BBE0: lwc1        $f0, -0x25C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X3D8C));
    // 0x8067BBE4: sw          $a3, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r7;
    // 0x8067BBE8: sw          $v0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r2;
    // 0x8067BBEC: addu        $v1, $t0, $t7
    ctx->r3 = ADD32(ctx->r8, ctx->r15);
    // 0x8067BBF0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8067BBF4: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x8067BBF8: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x8067BBFC: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8067BC00: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8067BC04: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8067BC08: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8067BC0C: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x8067BC10: lwc1        $f8, 0x4($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8067BC14: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8067BC18: jal         0x80679E50
    // 0x8067BC1C: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    func_80679E50(rdram, ctx);
        goto after_0;
    // 0x8067BC1C: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    after_0:
    // 0x8067BC20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067BC24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067BC28: jr          $ra
    // 0x8067BC2C: nop

    return;
    // 0x8067BC2C: nop

;}
RECOMP_FUNC void func_8064F228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F228: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F22C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F230: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F234: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F238: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F23C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F240: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F244: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F248: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F24C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F250: jr          $ra
    // 0x8064F254: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F254: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805D27C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D27C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D27C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D27CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D27D0: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D27D4: jal         0x805D264C
    // 0x805D27D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_805D264C(rdram, ctx);
        goto after_0;
    // 0x805D27D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D27DC: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2550) << 16);
    // 0x805D27E0: lwc1        $f6, 0x3F80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(471, 0X2550));
    // 0x805D27E4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x805D27E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805D27EC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x805D27F0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805D27F4: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(471, 0XD34) << 16);
    // 0x805D27F8: addiu       $t7, $t7, 0x2764
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(471, 0XD34));
    // 0x805D27FC: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x805D2800: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x805D2804: bnel        $t6, $at, L_805D2844
    if (ctx->r14 != ctx->r1) {
        // 0x805D2808: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D2844;
    }
    goto skip_0;
    // 0x805D2808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805D280C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x805D2810: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x805D2814: beql        $a1, $zero, L_805D2844
    if (ctx->r5 == 0) {
        // 0x805D2818: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D2844;
    }
    goto skip_1;
    // 0x805D2818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805D281C: jal         0x80047EB0
    // 0x805D2820: nop

    func_80047EB0(rdram, ctx);
        goto after_1;
    // 0x805D2820: nop

    after_1:
    // 0x805D2824: beql        $v0, $zero, L_805D2844
    if (ctx->r2 == 0) {
        // 0x805D2828: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D2844;
    }
    goto skip_2;
    // 0x805D2828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805D282C: jal         0x8004816C
    // 0x805D2830: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    func_8004816C(rdram, ctx);
        goto after_2;
    // 0x805D2830: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_2:
    // 0x805D2834: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x805D2838: jal         0x8004A73C
    // 0x805D283C: lw          $a0, 0x174($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X174);
    func_8004A73C(rdram, ctx);
        goto after_3;
    // 0x805D283C: lw          $a0, 0x174($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X174);
    after_3:
    // 0x805D2840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D2844:
    // 0x805D2844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D2848: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D284C: jr          $ra
    // 0x805D2850: nop

    return;
    // 0x805D2850: nop

;}
RECOMP_FUNC void func_806D37B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D37B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806D37B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806D37B8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x806D37BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806D37C0: jal         0x806D373C
    // 0x806D37C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_806D373C(rdram, ctx);
        goto after_0;
    // 0x806D37C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x806D37C8: bnel        $v0, $zero, L_806D385C
    if (ctx->r2 != 0) {
        // 0x806D37CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_806D385C;
    }
    goto skip_0;
    // 0x806D37CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x806D37D0: jal         0x806D351C
    // 0x806D37D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_806D351C(rdram, ctx);
        goto after_1;
    // 0x806D37D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x806D37D8: lw          $v1, 0x1F4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1F4);
    // 0x806D37DC: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x806D37E0: bnel        $t6, $zero, L_806D3810
    if (ctx->r14 != 0) {
        // 0x806D37E4: addiu       $s0, $s1, 0xC4
        ctx->r16 = ADD32(ctx->r17, 0XC4);
            goto L_806D3810;
    }
    goto skip_1;
    // 0x806D37E4: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    skip_1:
    // 0x806D37E8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x806D37EC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x806D37F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D37F4: beq         $v0, $zero, L_806D3804
    if (ctx->r2 == 0) {
        // 0x806D37F8: nop
    
            goto L_806D3804;
    }
    // 0x806D37F8: nop

    // 0x806D37FC: bnel        $v0, $at, L_806D3810
    if (ctx->r2 != ctx->r1) {
        // 0x806D3800: addiu       $s0, $s1, 0xC4
        ctx->r16 = ADD32(ctx->r17, 0XC4);
            goto L_806D3810;
    }
    goto skip_2;
    // 0x806D3800: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    skip_2:
L_806D3804:
    // 0x806D3804: jal         0x806D357C
    // 0x806D3808: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    func_806D357C(rdram, ctx);
        goto after_2;
    // 0x806D3808: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_2:
    // 0x806D380C: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
L_806D3810:
    // 0x806D3810: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806D3814: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806D3818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806D381C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D3820: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x806D3824: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806D3828: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806D382C: bc1fl       L_806D3844
    if (!c1cs) {
        // 0x806D3830: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806D3844;
    }
    goto skip_3;
    // 0x806D3830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x806D3834: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    // 0x806D3838: jal         0x806D414C
    // 0x806D383C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_806D414C(rdram, ctx);
        goto after_3;
    // 0x806D383C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x806D3840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806D3844:
    // 0x806D3844: jal         0x806D30C4
    // 0x806D3848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806D30C4(rdram, ctx);
        goto after_4;
    // 0x806D3848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x806D384C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D3850: jal         0x806D30C4
    // 0x806D3854: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806D30C4(rdram, ctx);
        goto after_5;
    // 0x806D3854: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x806D3858: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806D385C:
    // 0x806D385C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x806D3860: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x806D3864: jr          $ra
    // 0x806D3868: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806D3868: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805581E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805581E0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805581E4: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x805581E8: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x805581EC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805581F0: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x805581F4: lui         $t9, 0x8056
    ctx->r25 = S32(RELOC_HI16(363, 0X9204) << 16);
    // 0x805581F8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x805581FC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80558200: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80558204: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80558208: lw          $t9, 0xD54($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(363, 0X9204));
    // 0x8055820C: lui         $t3, 0x8056
    ctx->r11 = S32(RELOC_HI16(363, 0X9274) << 16);
    // 0x80558210: lui         $t7, 0x8056
    ctx->r15 = S32(RELOC_HI16(363, 0X92E4) << 16);
    // 0x80558214: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x80558218: lbu         $t0, 0x30($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X30);
    // 0x8055821C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80558220: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x80558224: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80558228: lw          $t3, 0xDC4($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(363, 0X9274));
    // 0x8055822C: sw          $t3, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r11;
    // 0x80558230: lbu         $t4, 0x30($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X30);
    // 0x80558234: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80558238: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8055823C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80558240: lw          $t7, 0xE34($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(363, 0X92E4));
    // 0x80558244: jr          $ra
    // 0x80558248: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    return;
    // 0x80558248: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_8001D454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D454: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001D458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D45C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D460: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001D464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001D468: jal         0x8001D0FC
    // 0x8001D46C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_8001D0FC(rdram, ctx);
        goto after_0;
    // 0x8001D46C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8001D470: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8001D474: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8001D478: lw          $t7, 0xF10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XF10);
    // 0x8001D47C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D480: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D484: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001D488: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8001D48C: lw          $t0, 0xF14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XF14);
    // 0x8001D490: sltiu       $at, $t0, 0x9
    ctx->r1 = ctx->r8 < 0X9 ? 1 : 0;
    // 0x8001D494: beql        $at, $zero, L_8001D4CC
    if (ctx->r1 == 0) {
        // 0x8001D498: lwc1        $f0, 0x6C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
            goto L_8001D4CC;
    }
    goto skip_0;
    // 0x8001D498: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x8001D49C: jal         0x8001D698
    // 0x8001D4A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8001D698(rdram, ctx);
        goto after_1;
    // 0x8001D4A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8001D4A4: jal         0x8001CE24
    // 0x8001D4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001CE24(rdram, ctx);
        goto after_2;
    // 0x8001D4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8001D4AC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D4B0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001D4B4: sw          $t1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r9;
    // 0x8001D4B8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001D4BC: sb          $zero, 0x30($v0)
    MEM_B(0X30, ctx->r2) = 0;
    // 0x8001D4C0: b           L_8001D54C
    // 0x8001D4C4: sb          $t2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r10;
        goto L_8001D54C;
    // 0x8001D4C4: sb          $t2, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r10;
    // 0x8001D4C8: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
L_8001D4CC:
    // 0x8001D4CC: lbu         $t4, 0x31($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X31);
    // 0x8001D4D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001D4D4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8001D4D8: jal         0x8001CD9C
    // 0x8001D4DC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    func_8001CD9C(rdram, ctx);
        goto after_3;
    // 0x8001D4DC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    after_3:
    // 0x8001D4E0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8001D4E4: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001D4E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001D4EC: beq         $t5, $zero, L_8001D520
    if (ctx->r13 == 0) {
        // 0x8001D4F0: nop
    
            goto L_8001D520;
    }
    // 0x8001D4F0: nop

    // 0x8001D4F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001D4F8: lwc1        $f2, -0x464($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X464);
    // 0x8001D4FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001D500: lwc1        $f4, -0x460($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X460);
    // 0x8001D504: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8001D508: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001D50C: nop

    // 0x8001D510: bc1fl       L_8001D548
    if (!c1cs) {
        // 0x8001D514: swc1        $f0, 0x70($s0)
        MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
            goto L_8001D548;
    }
    goto skip_1;
    // 0x8001D514: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    skip_1:
    // 0x8001D518: b           L_8001D544
    // 0x8001D51C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001D544;
    // 0x8001D51C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001D520:
    // 0x8001D520: lwc1        $f2, -0x45C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X45C);
    // 0x8001D524: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001D528: lwc1        $f6, -0x458($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X458);
    // 0x8001D52C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8001D530: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001D534: nop

    // 0x8001D538: bc1fl       L_8001D548
    if (!c1cs) {
        // 0x8001D53C: swc1        $f0, 0x70($s0)
        MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
            goto L_8001D548;
    }
    goto skip_2;
    // 0x8001D53C: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    skip_2:
    // 0x8001D540: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001D544:
    // 0x8001D544: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
L_8001D548:
    // 0x8001D548: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_8001D54C:
    // 0x8001D54C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D550: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001D554: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001D558: jr          $ra
    // 0x8001D55C: nop

    return;
    // 0x8001D55C: nop

;}
RECOMP_FUNC void func_806ADE7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ADE7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806ADE80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ADE84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806ADE88: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x806ADE8C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x806ADE90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806ADE94: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x806ADE98: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x806ADE9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806ADEA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806ADEA4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x806ADEA8: jal         0x80053CF8
    // 0x806ADEAC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80053CF8(rdram, ctx);
        goto after_0;
    // 0x806ADEAC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x806ADEB0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x806ADEB4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x806ADEB8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x806ADEBC: jal         0x80053EE4
    // 0x806ADEC0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    func_80053EE4(rdram, ctx);
        goto after_1;
    // 0x806ADEC0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x806ADEC4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x806ADEC8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x806ADECC: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x806ADED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806ADED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806ADED8: jr          $ra
    // 0x806ADEDC: nop

    return;
    // 0x806ADEDC: nop

;}
RECOMP_FUNC void func_80068438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068438: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8006843C: lw          $a0, 0x6EB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EB0);
    // 0x80068440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068448: beql        $a0, $zero, L_80068464
    if (ctx->r4 == 0) {
        // 0x8006844C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068464;
    }
    goto skip_0;
    // 0x8006844C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80068450: jal         0x80064E84
    // 0x80068454: nop

    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80068454: nop

    after_0:
    // 0x80068458: jal         0x80068418
    // 0x8006845C: nop

    func_80068418(rdram, ctx);
        goto after_1;
    // 0x8006845C: nop

    after_1:
    // 0x80068460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068464:
    // 0x80068464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068468: jr          $ra
    // 0x8006846C: nop

    return;
    // 0x8006846C: nop

;}
RECOMP_FUNC void func_806ADE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ADE38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806ADE3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806ADE40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806ADE44: lw          $t6, 0x1E4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E4);
    // 0x806ADE48: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806ADE4C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x806ADE50: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x806ADE54: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x806ADE58: jal         0x80067D5C
    // 0x806ADE5C: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x806ADE5C: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    after_0:
    // 0x806ADE60: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806ADE64: jal         0x80067818
    // 0x806ADE68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806ADE68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806ADE6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806ADE70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806ADE74: jr          $ra
    // 0x806ADE78: nop

    return;
    // 0x806ADE78: nop

;}
RECOMP_FUNC void func_80742AF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742AF4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742AF8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742AFC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742B00: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742B04: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742B08: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742B0C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742B10: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742B14: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742B18: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742B1C: jr          $ra
    // 0x80742B20: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742B20: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804646E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804646E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804646E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804646EC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804646F0: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804646F4: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(125, 0X1D58) << 16);
    // 0x804646F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804646FC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80464700: lw          $t8, 0x6328($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(125, 0X1D58));
    // 0x80464704: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80464708: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8046470C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80464710: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80464714: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80464718: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8046471C: beql        $v1, $zero, L_80464750
    if (ctx->r3 == 0) {
        // 0x80464720: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80464750;
    }
    goto skip_0;
    // 0x80464720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80464724: jalr        $v1
    // 0x80464728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80464728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046472C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80464730: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80464734: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80464738: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8046473C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80464740: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80464744: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80464748: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8046474C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80464750:
    // 0x80464750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80464754: jr          $ra
    // 0x80464758: nop

    return;
    // 0x80464758: nop

;}
RECOMP_FUNC void func_8067F8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067F8F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8067F8F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067F8F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067F8FC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067F900: lw          $a2, 0x174($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X174);
    // 0x8067F904: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067F908: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8067F90C: jal         0x8004700C
    // 0x8067F910: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8067F910: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8067F914: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8067F918: beq         $v0, $zero, L_8067FA2C
    if (ctx->r2 == 0) {
        // 0x8067F91C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8067FA2C;
    }
    // 0x8067F91C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8067F920: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x8067F924: andi        $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 & 0XF00;
    // 0x8067F928: beql        $t7, $zero, L_8067FA24
    if (ctx->r15 == 0) {
        // 0x8067F92C: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8067FA24;
    }
    goto skip_0;
    // 0x8067F92C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
    // 0x8067F930: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x8067F934: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8067F938: andi        $t9, $t8, 0xF00
    ctx->r25 = ctx->r24 & 0XF00;
    // 0x8067F93C: bnel        $t9, $zero, L_8067FA24
    if (ctx->r25 != 0) {
        // 0x8067F940: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8067FA24;
    }
    goto skip_1;
    // 0x8067F940: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_1:
    // 0x8067F944: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8067F948: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8067F94C: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8067F950: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8067F954: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067F958: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8067F95C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8067F960: nop

    // 0x8067F964: bc1fl       L_8067F974
    if (!c1cs) {
        // 0x8067F968: swc1        $f8, 0xC8($s0)
        MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
            goto L_8067F974;
    }
    goto skip_2;
    // 0x8067F968: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    skip_2:
    // 0x8067F96C: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x8067F970: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
L_8067F974:
    // 0x8067F974: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8067F978: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8067F97C: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8067F980: lhu         $a0, 0x18($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X18);
    // 0x8067F984: jal         0x8004A97C
    // 0x8067F988: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8004A97C(rdram, ctx);
        goto after_1;
    // 0x8067F988: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8067F98C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8067F990: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8067F994: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8067F998: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067F99C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8067F9A0: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x8067F9A4: bc1fl       L_8067F9C8
    if (!c1cs) {
        // 0x8067F9A8: lwc1        $f6, 0x14($v1)
        ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8067F9C8;
    }
    goto skip_3;
    // 0x8067F9A8: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    skip_3:
    // 0x8067F9AC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8067F9B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067F9B4: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8067F9B8: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8067F9BC: b           L_8067F9E0
    // 0x8067F9C0: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
        goto L_8067F9E0;
    // 0x8067F9C0: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x8067F9C4: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
L_8067F9C8:
    // 0x8067F9C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067F9CC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8067F9D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8067F9D4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8067F9D8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8067F9DC: swc1        $f18, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f18.u32l;
L_8067F9E0:
    // 0x8067F9E0: lw          $t4, 0x174($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X174);
    // 0x8067F9E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8067F9E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067F9EC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8067F9F0: jal         0x8005FCA8
    // 0x8067F9F4: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
    func_8005FCA8(rdram, ctx);
        goto after_2;
    // 0x8067F9F4: sh          $t3, 0x12($t5)
    MEM_H(0X12, ctx->r13) = ctx->r11;
    after_2:
    // 0x8067F9F8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8067F9FC: jal         0x80067BBC
    // 0x8067FA00: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8067FA00: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8067FA04: addiu       $a0, $zero, 0x282
    ctx->r4 = ADD32(0, 0X282);
    // 0x8067FA08: jal         0x80067818
    // 0x8067FA0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8067FA0C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8067FA10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067FA14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067FA18: jal         0x80680194
    // 0x8067FA1C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80680194(rdram, ctx);
        goto after_5;
    // 0x8067FA1C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x8067FA20: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_8067FA24:
    // 0x8067FA24: jal         0x80048F84
    // 0x8067FA28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x8067FA28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_8067FA2C:
    // 0x8067FA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067FA30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067FA34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8067FA38: jr          $ra
    // 0x8067FA3C: nop

    return;
    // 0x8067FA3C: nop

;}
RECOMP_FUNC void func_804B6524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B652C: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804B6530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804B6534: beq         $t6, $zero, L_804B6570
    if (ctx->r14 == 0) {
        // 0x804B6538: nop
    
            goto L_804B6570;
    }
    // 0x804B6538: nop

    // 0x804B653C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B6540: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804B6544: jalr        $t9
    // 0x804B6548: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804B6548: nop

    after_0:
    // 0x804B654C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6550: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804B6554: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804B6558: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804B655C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804B6560: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804B6564: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804B6568: b           L_804B6570
    // 0x804B656C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804B6570;
    // 0x804B656C: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804B6570:
    // 0x804B6570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6578: jr          $ra
    // 0x804B657C: nop

    return;
    // 0x804B657C: nop

;}
RECOMP_FUNC void func_8004B79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B79C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8004B7A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004B7A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004B7A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8004B7AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8004B7B0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8004B7B4: lh          $v0, 0x4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X4);
    // 0x8004B7B8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8004B7BC: lh          $t0, 0x10($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X10);
    // 0x8004B7C0: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x8004B7C4: blez        $v0, L_8004B838
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004B7C8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8004B838;
    }
    // 0x8004B7C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004B7CC: lbu         $t2, 0x1($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X1);
    // 0x8004B7D0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8004B7D4: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x8004B7D8: srl         $t8, $t2, 6
    ctx->r24 = S32(U32(ctx->r10) >> 6);
    // 0x8004B7DC: andi        $t3, $t2, 0x3F
    ctx->r11 = ctx->r10 & 0X3F;
    // 0x8004B7E0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8004B7E4: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8004B7E8: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8004B7EC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8004B7F0: lw          $t6, 0xA24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XA24);
    // 0x8004B7F4: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x8004B7F8: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8004B7FC: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
L_8004B800:
    // 0x8004B800: negu        $t2, $t8
    ctx->r10 = SUB32(0, ctx->r24);
    // 0x8004B804: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8004B808: lhu         $t9, 0x0($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X0);
    // 0x8004B80C: and         $t4, $t9, $a1
    ctx->r12 = ctx->r25 & ctx->r5;
    // 0x8004B810: bnel        $t4, $zero, L_8004B824
    if (ctx->r12 != 0) {
        // 0x8004B814: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004B824;
    }
    goto skip_0;
    // 0x8004B814: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8004B818: b           L_8004BA00
    // 0x8004B81C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004BA00;
    // 0x8004B81C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004B820: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004B824:
    // 0x8004B824: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004B828: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004B82C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004B830: bnel        $at, $zero, L_8004B800
    if (ctx->r1 != 0) {
        // 0x8004B834: sll         $t8, $v1, 1
        ctx->r24 = S32(ctx->r3 << 1);
            goto L_8004B800;
    }
    goto skip_1;
    // 0x8004B834: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    skip_1:
L_8004B838:
    // 0x8004B838: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8004B83C: slti        $at, $t5, 0x11
    ctx->r1 = SIGNED(ctx->r13) < 0X11 ? 1 : 0;
    // 0x8004B840: bnel        $at, $zero, L_8004B854
    if (ctx->r1 != 0) {
        // 0x8004B844: sh          $v1, 0x38($sp)
        MEM_H(0X38, ctx->r29) = ctx->r3;
            goto L_8004B854;
    }
    goto skip_2;
    // 0x8004B844: sh          $v1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r3;
    skip_2:
    // 0x8004B848: b           L_8004BA00
    // 0x8004B84C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004BA00;
    // 0x8004B84C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004B850: sh          $v1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r3;
L_8004B854:
    // 0x8004B854: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    // 0x8004B858: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8004B85C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004B860: sh          $t6, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r14;
    // 0x8004B864: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004B868: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8004B86C: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004B870: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004B874: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004B878: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8004B87C: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004B880: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8004B884: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    // 0x8004B888: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8004B88C: jal         0x800534C0
    // 0x8004B890: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800534C0(rdram, ctx);
        goto after_0;
    // 0x8004B890: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8004B894: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x8004B898: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8004B89C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8004B8A0: sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
    // 0x8004B8A4: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8004B8A8: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8004B8AC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8004B8B0: andi        $t9, $v0, 0x7FF
    ctx->r25 = ctx->r2 & 0X7FF;
    // 0x8004B8B4: andi        $t2, $t8, 0xF8
    ctx->r10 = ctx->r24 & 0XF8;
    // 0x8004B8B8: bnel        $t2, $at, L_8004B8C8
    if (ctx->r10 != ctx->r1) {
        // 0x8004B8BC: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_8004B8C8;
    }
    goto skip_3;
    // 0x8004B8BC: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_3:
    // 0x8004B8C0: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8004B8C4: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
L_8004B8C8:
    // 0x8004B8C8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004B8CC: beql        $v0, $zero, L_8004BA00
    if (ctx->r2 == 0) {
        // 0x8004B8D0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004BA00;
    }
    goto skip_4;
    // 0x8004B8D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_4:
    // 0x8004B8D4: beql        $v0, $at, L_8004BA00
    if (ctx->r2 == ctx->r1) {
        // 0x8004B8D8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004BA00;
    }
    goto skip_5;
    // 0x8004B8D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_5:
    // 0x8004B8DC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004B8E0: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004B8E4: andi        $a0, $v0, 0xF8
    ctx->r4 = ctx->r2 & 0XF8;
    // 0x8004B8E8: beq         $a0, $at, L_8004B9FC
    if (ctx->r4 == ctx->r1) {
        // 0x8004B8EC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004B9FC;
    }
    // 0x8004B8EC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004B8F0: beq         $a0, $at, L_8004B9FC
    if (ctx->r4 == ctx->r1) {
        // 0x8004B8F4: andi        $t4, $v0, 0x2
        ctx->r12 = ctx->r2 & 0X2;
            goto L_8004B9FC;
    }
    // 0x8004B8F4: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x8004B8F8: beq         $t4, $zero, L_8004B9FC
    if (ctx->r12 == 0) {
        // 0x8004B8FC: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_8004B9FC;
    }
    // 0x8004B8FC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8004B900: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8004B904: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8004B908: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8004B90C: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x8004B910: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8004B914: srl         $t3, $v0, 6
    ctx->r11 = S32(U32(ctx->r2) >> 6);
    // 0x8004B918: andi        $t4, $v0, 0x3F
    ctx->r12 = ctx->r2 & 0X3F;
    // 0x8004B91C: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8004B920: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8004B924: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8004B928: sll         $t9, $t3, 8
    ctx->r25 = S32(ctx->r11 << 8);
    // 0x8004B92C: sh          $t8, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r24;
    // 0x8004B930: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8004B934: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8004B938: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8004B93C: lh          $t8, 0x10($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X10);
    // 0x8004B940: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    // 0x8004B944: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8004B948: lw          $t7, 0xA24($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XA24);
    // 0x8004B94C: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x8004B950: lhu         $t9, 0x2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2);
    // 0x8004B954: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x8004B958: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8004B95C: and         $t5, $t4, $t9
    ctx->r13 = ctx->r12 & ctx->r25;
    // 0x8004B960: beql        $t5, $zero, L_8004BA00
    if (ctx->r13 == 0) {
        // 0x8004B964: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004BA00;
    }
    goto skip_6;
    // 0x8004B964: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_6:
    // 0x8004B968: lhu         $t6, 0x0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X0);
    // 0x8004B96C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004B970: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
    // 0x8004B974: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8004B978: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8004B97C: sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    // 0x8004B980: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8004B984: jal         0x8004B79C
    // 0x8004B988: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_8004B79C(rdram, ctx);
        goto after_1;
    // 0x8004B988: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_1:
    // 0x8004B98C: lh          $v1, 0x3E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3E);
    // 0x8004B990: lbu         $a0, 0x36($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X36);
    // 0x8004B994: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8004B998: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004B99C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004B9A0: andi        $a1, $a0, 0x2
    ctx->r5 = ctx->r4 & 0X2;
    // 0x8004B9A4: beq         $a1, $zero, L_8004B9D4
    if (ctx->r5 == 0) {
        // 0x8004B9A8: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8004B9D4;
    }
    // 0x8004B9A8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004B9AC: lbu         $t8, 0x34($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X34);
    // 0x8004B9B0: lhu         $t2, 0x36($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X36);
    // 0x8004B9B4: andi        $t7, $t8, 0x2
    ctx->r15 = ctx->r24 & 0X2;
    // 0x8004B9B8: bnel        $t7, $zero, L_8004BA00
    if (ctx->r15 != 0) {
        // 0x8004B9BC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004BA00;
    }
    goto skip_7;
    // 0x8004B9BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_7:
    // 0x8004B9C0: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
    // 0x8004B9C4: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
    // 0x8004B9C8: sh          $t3, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r11;
    // 0x8004B9CC: b           L_8004BA00
    // 0x8004B9D0: lh          $v0, 0x38($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X38);
        goto L_8004BA00;
    // 0x8004B9D0: lh          $v0, 0x38($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X38);
L_8004B9D4:
    // 0x8004B9D4: andi        $t4, $a0, 0x1
    ctx->r12 = ctx->r4 & 0X1;
    // 0x8004B9D8: bnel        $t4, $zero, L_8004BA00
    if (ctx->r12 != 0) {
        // 0x8004B9DC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004BA00;
    }
    goto skip_8;
    // 0x8004B9DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_8:
    // 0x8004B9E0: beq         $a1, $zero, L_8004B9FC
    if (ctx->r5 == 0) {
        // 0x8004B9E4: lbu         $t9, 0x34($sp)
        ctx->r25 = MEM_BU(ctx->r29, 0X34);
            goto L_8004B9FC;
    }
    // 0x8004B9E4: lbu         $t9, 0x34($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X34);
    // 0x8004B9E8: andi        $t5, $t9, 0x2
    ctx->r13 = ctx->r25 & 0X2;
    // 0x8004B9EC: bne         $t5, $zero, L_8004B9FC
    if (ctx->r13 != 0) {
        // 0x8004B9F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004B9FC;
    }
    // 0x8004B9F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004B9F4: b           L_8004BA00
    // 0x8004B9F8: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
        goto L_8004BA00;
    // 0x8004B9F8: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
L_8004B9FC:
    // 0x8004B9FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004BA00:
    // 0x8004BA00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004BA04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004BA08: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8004BA0C: jr          $ra
    // 0x8004BA10: nop

    return;
    // 0x8004BA10: nop

;}
RECOMP_FUNC void func_805D23EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D23EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805D23F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D23F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D23F8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D23FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805D2400: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805D2404: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805D2408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805D240C: jal         0x805D1D0C
    // 0x805D2410: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_805D1D0C(rdram, ctx);
        goto after_0;
    // 0x805D2410: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x805D2414: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805D2418: jal         0x805D1D0C
    // 0x805D241C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805D1D0C(rdram, ctx);
        goto after_1;
    // 0x805D241C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805D2420: jal         0x805D2238
    // 0x805D2424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D2238(rdram, ctx);
        goto after_2;
    // 0x805D2424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805D2428: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
    // 0x805D242C: addiu       $at, $zero, 0x4526
    ctx->r1 = ADD32(0, 0X4526);
    // 0x805D2430: bnel        $t7, $at, L_805D2460
    if (ctx->r15 != ctx->r1) {
        // 0x805D2434: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_805D2460;
    }
    goto skip_0;
    // 0x805D2434: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x805D2438: lw          $t8, 0x1E4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E4);
    // 0x805D243C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D2440: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x805D2444: slti        $at, $t9, 0xB4
    ctx->r1 = SIGNED(ctx->r25) < 0XB4 ? 1 : 0;
    // 0x805D2448: bne         $at, $zero, L_805D245C
    if (ctx->r1 != 0) {
        // 0x805D244C: sw          $t9, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r25;
            goto L_805D245C;
    }
    // 0x805D244C: sw          $t9, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r25;
    // 0x805D2450: jal         0x805D2200
    // 0x805D2454: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    func_805D2200(rdram, ctx);
        goto after_3;
    // 0x805D2454: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_3:
    // 0x805D2458: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
L_805D245C:
    // 0x805D245C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_805D2460:
    // 0x805D2460: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805D2464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D2468: lw          $t1, 0x68($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X68);
    // 0x805D246C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D2470: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x805D2474: bne         $t1, $at, L_805D24A8
    if (ctx->r9 != ctx->r1) {
        // 0x805D2478: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_805D24A8;
    }
    // 0x805D2478: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805D247C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805D2480: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805D2484: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2544) << 16);
    // 0x805D2488: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x805D248C: nop

    // 0x805D2490: bc1fl       L_805D24D8
    if (!c1cs) {
        // 0x805D2494: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_805D24D8;
    }
    goto skip_1;
    // 0x805D2494: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x805D2498: lwc1        $f6, 0x3F74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(471, 0X2544));
    // 0x805D249C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x805D24A0: b           L_805D24D4
    // 0x805D24A4: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
        goto L_805D24D4;
    // 0x805D24A4: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
L_805D24A8:
    // 0x805D24A8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x805D24AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805D24B0: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805D24B4: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2548) << 16);
    // 0x805D24B8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x805D24BC: nop

    // 0x805D24C0: bc1fl       L_805D24D8
    if (!c1cs) {
        // 0x805D24C4: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_805D24D8;
    }
    goto skip_2;
    // 0x805D24C4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x805D24C8: lwc1        $f16, 0x3F78($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(471, 0X2548));
    // 0x805D24CC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x805D24D0: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
L_805D24D4:
    // 0x805D24D4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
L_805D24D8:
    // 0x805D24D8: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805D24DC: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x805D24E0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805D24E4: nop

    // 0x805D24E8: bc1fl       L_805D2504
    if (!c1cs) {
        // 0x805D24EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D2504;
    }
    goto skip_3;
    // 0x805D24EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x805D24F0: jal         0x805D3B18
    // 0x805D24F4: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    func_805D3B18(rdram, ctx);
        goto after_4;
    // 0x805D24F4: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    after_4:
    // 0x805D24F8: jal         0x805D2238
    // 0x805D24FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805D2238(rdram, ctx);
        goto after_5;
    // 0x805D24FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805D2500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D2504:
    // 0x805D2504: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D2508: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805D250C: jr          $ra
    // 0x805D2510: nop

    return;
    // 0x805D2510: nop

;}
RECOMP_FUNC void func_80714B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80714B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80714B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80714B28: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80714B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80714B30: beq         $t6, $zero, L_80714B6C
    if (ctx->r14 == 0) {
        // 0x80714B34: nop
    
            goto L_80714B6C;
    }
    // 0x80714B34: nop

    // 0x80714B38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80714B3C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80714B40: jalr        $t9
    // 0x80714B44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80714B44: nop

    after_0:
    // 0x80714B48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80714B4C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80714B50: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80714B54: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80714B58: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80714B5C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80714B60: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80714B64: b           L_80714B6C
    // 0x80714B68: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80714B6C;
    // 0x80714B68: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80714B6C:
    // 0x80714B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80714B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80714B74: jr          $ra
    // 0x80714B78: nop

    return;
    // 0x80714B78: nop

;}
RECOMP_FUNC void func_806F9D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9D40: jal         0x806F9C90
    // 0x806F9D44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F9C90(rdram, ctx);
        goto after_0;
    // 0x806F9D44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F9D48: jal         0x80045BD8
    // 0x806F9D4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x806F9D4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806F9D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F9D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F9D58: jr          $ra
    // 0x806F9D5C: nop

    return;
    // 0x806F9D5C: nop

;}
RECOMP_FUNC void func_80042880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042880: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80042884: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80042888: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004288C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042890: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80042894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042898: jal         0x80067930
    // 0x8004289C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x8004289C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x800428A0: beql        $v0, $zero, L_80042908
    if (ctx->r2 == 0) {
        // 0x800428A4: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80042908;
    }
    goto skip_0;
    // 0x800428A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    skip_0:
    // 0x800428A8: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    // 0x800428AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800428B0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800428B4: bne         $t6, $at, L_800428CC
    if (ctx->r14 != ctx->r1) {
        // 0x800428B8: nop
    
            goto L_800428CC;
    }
    // 0x800428B8: nop

    // 0x800428BC: lbu         $t7, 0x30($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X30);
    // 0x800428C0: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800428C4: beq         $t7, $at, L_800428DC
    if (ctx->r15 == ctx->r1) {
        // 0x800428C8: nop
    
            goto L_800428DC;
    }
    // 0x800428C8: nop

L_800428CC:
    // 0x800428CC: jal         0x80067878
    // 0x800428D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x800428D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800428D4: b           L_80042908
    // 0x800428D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_80042908;
    // 0x800428D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_800428DC:
    // 0x800428DC: jal         0x8001D770
    // 0x800428E0: nop

    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x800428E0: nop

    after_2:
    // 0x800428E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800428E8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x800428EC: jal         0x80067BF8
    // 0x800428F0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x800428F0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x800428F4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800428F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800428FC: jal         0x800678F0
    // 0x80042900: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x80042900: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x80042904: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_80042908:
    // 0x80042908: jal         0x80067930
    // 0x8004290C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_5;
    // 0x8004290C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80042910: beql        $v0, $zero, L_80042978
    if (ctx->r2 == 0) {
        // 0x80042914: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80042978;
    }
    goto skip_1;
    // 0x80042914: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    skip_1:
    // 0x80042918: lbu         $t8, 0x18($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18);
    // 0x8004291C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042920: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80042924: bne         $t8, $at, L_8004293C
    if (ctx->r24 != ctx->r1) {
        // 0x80042928: nop
    
            goto L_8004293C;
    }
    // 0x80042928: nop

    // 0x8004292C: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    // 0x80042930: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80042934: beq         $t9, $at, L_8004294C
    if (ctx->r25 == ctx->r1) {
        // 0x80042938: nop
    
            goto L_8004294C;
    }
    // 0x80042938: nop

L_8004293C:
    // 0x8004293C: jal         0x80067878
    // 0x80042940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_6;
    // 0x80042940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80042944: b           L_80042978
    // 0x80042948: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
        goto L_80042978;
    // 0x80042948: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_8004294C:
    // 0x8004294C: jal         0x8001D770
    // 0x80042950: nop

    func_8001D770(rdram, ctx);
        goto after_7;
    // 0x80042950: nop

    after_7:
    // 0x80042954: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042958: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8004295C: jal         0x80067BF8
    // 0x80042960: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_8;
    // 0x80042960: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_8:
    // 0x80042964: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80042968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004296C: jal         0x800678F0
    // 0x80042970: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_9;
    // 0x80042970: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_9:
    // 0x80042974: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80042978:
    // 0x80042978: jal         0x80067930
    // 0x8004297C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_10;
    // 0x8004297C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80042980: beql        $v0, $zero, L_800429F0
    if (ctx->r2 == 0) {
        // 0x80042984: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800429F0;
    }
    goto skip_2;
    // 0x80042984: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    skip_2:
    // 0x80042988: lbu         $t0, 0x18($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18);
    // 0x8004298C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042990: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80042994: bne         $t0, $at, L_800429B4
    if (ctx->r8 != ctx->r1) {
        // 0x80042998: nop
    
            goto L_800429B4;
    }
    // 0x80042998: nop

    // 0x8004299C: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x800429A0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800429A4: beq         $v0, $at, L_800429C4
    if (ctx->r2 == ctx->r1) {
        // 0x800429A8: addiu       $at, $zero, 0x23
        ctx->r1 = ADD32(0, 0X23);
            goto L_800429C4;
    }
    // 0x800429A8: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x800429AC: beq         $v0, $at, L_800429C4
    if (ctx->r2 == ctx->r1) {
        // 0x800429B0: nop
    
            goto L_800429C4;
    }
    // 0x800429B0: nop

L_800429B4:
    // 0x800429B4: jal         0x80067878
    // 0x800429B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_11;
    // 0x800429B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x800429BC: b           L_800429F0
    // 0x800429C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_800429F0;
    // 0x800429C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_800429C4:
    // 0x800429C4: jal         0x8001D770
    // 0x800429C8: nop

    func_8001D770(rdram, ctx);
        goto after_12;
    // 0x800429C8: nop

    after_12:
    // 0x800429CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800429D0: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x800429D4: jal         0x80067BF8
    // 0x800429D8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_13;
    // 0x800429D8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_13:
    // 0x800429DC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800429E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800429E4: jal         0x800678F0
    // 0x800429E8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_14;
    // 0x800429E8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_14:
    // 0x800429EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_800429F0:
    // 0x800429F0: jal         0x80067930
    // 0x800429F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_15;
    // 0x800429F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800429F8: beql        $v0, $zero, L_80042A8C
    if (ctx->r2 == 0) {
        // 0x800429FC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80042A8C;
    }
    goto skip_3;
    // 0x800429FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_3:
    // 0x80042A00: lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X18);
    // 0x80042A04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042A08: bnel        $v1, $at, L_80042A38
    if (ctx->r3 != ctx->r1) {
        // 0x80042A0C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80042A38;
    }
    goto skip_4;
    // 0x80042A0C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_4:
    // 0x80042A10: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x80042A14: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80042A18: beq         $v0, $at, L_80042A60
    if (ctx->r2 == ctx->r1) {
        // 0x80042A1C: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_80042A60;
    }
    // 0x80042A1C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80042A20: beq         $v0, $at, L_80042A60
    if (ctx->r2 == ctx->r1) {
        // 0x80042A24: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_80042A60;
    }
    // 0x80042A24: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x80042A28: beq         $v0, $at, L_80042A60
    if (ctx->r2 == ctx->r1) {
        // 0x80042A2C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80042A60;
    }
    // 0x80042A2C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x80042A30: beq         $v0, $at, L_80042A60
    if (ctx->r2 == ctx->r1) {
        // 0x80042A34: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80042A60;
    }
    // 0x80042A34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80042A38:
    // 0x80042A38: bne         $v1, $at, L_80042A50
    if (ctx->r3 != ctx->r1) {
        // 0x80042A3C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80042A50;
    }
    // 0x80042A3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80042A40: lbu         $t1, 0x30($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X30);
    // 0x80042A44: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80042A48: beq         $t1, $at, L_80042A60
    if (ctx->r9 == ctx->r1) {
        // 0x80042A4C: nop
    
            goto L_80042A60;
    }
    // 0x80042A4C: nop

L_80042A50:
    // 0x80042A50: jal         0x80067878
    // 0x80042A54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_16;
    // 0x80042A54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80042A58: b           L_80042A8C
    // 0x80042A5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80042A8C;
    // 0x80042A5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80042A60:
    // 0x80042A60: jal         0x8001D770
    // 0x80042A64: nop

    func_8001D770(rdram, ctx);
        goto after_17;
    // 0x80042A64: nop

    after_17:
    // 0x80042A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042A6C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80042A70: jal         0x80067BF8
    // 0x80042A74: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_18;
    // 0x80042A74: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_18:
    // 0x80042A78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80042A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042A80: jal         0x800678F0
    // 0x80042A84: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_19;
    // 0x80042A84: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_19:
    // 0x80042A88: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80042A8C:
    // 0x80042A8C: jal         0x80067930
    // 0x80042A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_20;
    // 0x80042A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80042A94: beq         $v0, $zero, L_80042ADC
    if (ctx->r2 == 0) {
        // 0x80042A98: lw          $t2, 0x34($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X34);
            goto L_80042ADC;
    }
    // 0x80042A98: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80042A9C: lw          $v0, 0x1F4($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X1F4);
    // 0x80042AA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80042AA4: bnel        $v0, $zero, L_80042AC0
    if (ctx->r2 != 0) {
        // 0x80042AA8: lw          $a0, 0x34($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X34);
            goto L_80042AC0;
    }
    goto skip_5;
    // 0x80042AA8: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    skip_5:
    // 0x80042AAC: jal         0x80067878
    // 0x80042AB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_21;
    // 0x80042AB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80042AB4: b           L_80042AE0
    // 0x80042AB8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
        goto L_80042AE0;
    // 0x80042AB8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80042ABC: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
L_80042AC0:
    // 0x80042AC0: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80042AC4: jal         0x80067D5C
    // 0x80042AC8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_22;
    // 0x80042AC8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_22:
    // 0x80042ACC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80042AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042AD4: jal         0x800678F0
    // 0x80042AD8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_23;
    // 0x80042AD8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_23:
L_80042ADC:
    // 0x80042ADC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_80042AE0:
    // 0x80042AE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042AE4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80042AE8: lbu         $t4, 0x111($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X111);
    // 0x80042AEC: bne         $t4, $at, L_80042C34
    if (ctx->r12 != ctx->r1) {
        // 0x80042AF0: nop
    
            goto L_80042C34;
    }
    // 0x80042AF0: nop

    // 0x80042AF4: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x80042AF8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80042AFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042B00: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80042B04: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x80042B08: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80042B0C: lbu         $t8, 0x18($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X18);
    // 0x80042B10: andi        $t9, $t8, 0xF8
    ctx->r25 = ctx->r24 & 0XF8;
    // 0x80042B14: bne         $t9, $at, L_80042BA8
    if (ctx->r25 != ctx->r1) {
        // 0x80042B18: nop
    
            goto L_80042BA8;
    }
    // 0x80042B18: nop

    // 0x80042B1C: jal         0x80067930
    // 0x80042B20: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_80067930(rdram, ctx);
        goto after_24;
    // 0x80042B20: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_24:
    // 0x80042B24: beq         $v0, $zero, L_80042B5C
    if (ctx->r2 == 0) {
        // 0x80042B28: nop
    
            goto L_80042B5C;
    }
    // 0x80042B28: nop

    // 0x80042B2C: jal         0x8001D770
    // 0x80042B30: nop

    func_8001D770(rdram, ctx);
        goto after_25;
    // 0x80042B30: nop

    after_25:
    // 0x80042B34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042B38: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80042B3C: jal         0x80067BF8
    // 0x80042B40: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_26;
    // 0x80042B40: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_26:
    // 0x80042B44: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80042B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042B4C: jal         0x800678F0
    // 0x80042B50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_27;
    // 0x80042B50: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_27:
    // 0x80042B54: b           L_80042B88
    // 0x80042B58: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
        goto L_80042B88;
    // 0x80042B58: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
L_80042B5C:
    // 0x80042B5C: jal         0x8001D770
    // 0x80042B60: nop

    func_8001D770(rdram, ctx);
        goto after_28;
    // 0x80042B60: nop

    after_28:
    // 0x80042B64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042B68: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80042B6C: jal         0x80067BF8
    // 0x80042B70: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_29;
    // 0x80042B70: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_29:
    // 0x80042B74: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80042B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042B7C: jal         0x80067838
    // 0x80042B80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_30;
    // 0x80042B80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_30:
    // 0x80042B84: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
L_80042B88:
    // 0x80042B88: jal         0x80067930
    // 0x80042B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_31;
    // 0x80042B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x80042B90: beq         $v0, $zero, L_80042C70
    if (ctx->r2 == 0) {
        // 0x80042B94: addiu       $a0, $zero, 0xD0
        ctx->r4 = ADD32(0, 0XD0);
            goto L_80042C70;
    }
    // 0x80042B94: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x80042B98: jal         0x80067878
    // 0x80042B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_32;
    // 0x80042B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80042BA0: b           L_80042C74
    // 0x80042BA4: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
        goto L_80042C74;
    // 0x80042BA4: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
L_80042BA8:
    // 0x80042BA8: jal         0x80067930
    // 0x80042BAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_33;
    // 0x80042BAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x80042BB0: beq         $v0, $zero, L_80042BE8
    if (ctx->r2 == 0) {
        // 0x80042BB4: nop
    
            goto L_80042BE8;
    }
    // 0x80042BB4: nop

    // 0x80042BB8: jal         0x8001D770
    // 0x80042BBC: nop

    func_8001D770(rdram, ctx);
        goto after_34;
    // 0x80042BBC: nop

    after_34:
    // 0x80042BC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042BC4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80042BC8: jal         0x80067BF8
    // 0x80042BCC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_35;
    // 0x80042BCC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_35:
    // 0x80042BD0: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x80042BD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042BD8: jal         0x800678F0
    // 0x80042BDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_36;
    // 0x80042BDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_36:
    // 0x80042BE0: b           L_80042C14
    // 0x80042BE4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
        goto L_80042C14;
    // 0x80042BE4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
L_80042BE8:
    // 0x80042BE8: jal         0x8001D770
    // 0x80042BEC: nop

    func_8001D770(rdram, ctx);
        goto after_37;
    // 0x80042BEC: nop

    after_37:
    // 0x80042BF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042BF4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80042BF8: jal         0x80067BF8
    // 0x80042BFC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_38;
    // 0x80042BFC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_38:
    // 0x80042C00: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x80042C04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042C08: jal         0x80067838
    // 0x80042C0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_39;
    // 0x80042C0C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_39:
    // 0x80042C10: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
L_80042C14:
    // 0x80042C14: jal         0x80067930
    // 0x80042C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_40;
    // 0x80042C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_40:
    // 0x80042C1C: beq         $v0, $zero, L_80042C70
    if (ctx->r2 == 0) {
        // 0x80042C20: addiu       $a0, $zero, 0x1D
        ctx->r4 = ADD32(0, 0X1D);
            goto L_80042C70;
    }
    // 0x80042C20: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80042C24: jal         0x80067878
    // 0x80042C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_41;
    // 0x80042C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_41:
    // 0x80042C2C: b           L_80042C74
    // 0x80042C30: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
        goto L_80042C74;
    // 0x80042C30: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
L_80042C34:
    // 0x80042C34: jal         0x80067930
    // 0x80042C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_42;
    // 0x80042C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_42:
    // 0x80042C3C: beq         $v0, $zero, L_80042C58
    if (ctx->r2 == 0) {
        // 0x80042C40: addiu       $a0, $zero, 0xD0
        ctx->r4 = ADD32(0, 0XD0);
            goto L_80042C58;
    }
    // 0x80042C40: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x80042C44: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80042C48: jal         0x80067878
    // 0x80042C4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_43;
    // 0x80042C4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x80042C50: b           L_80042C74
    // 0x80042C54: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
        goto L_80042C74;
    // 0x80042C54: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
L_80042C58:
    // 0x80042C58: jal         0x80067930
    // 0x80042C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_44;
    // 0x80042C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_44:
    // 0x80042C60: beq         $v0, $zero, L_80042C70
    if (ctx->r2 == 0) {
        // 0x80042C64: addiu       $a0, $zero, 0xD0
        ctx->r4 = ADD32(0, 0XD0);
            goto L_80042C70;
    }
    // 0x80042C64: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x80042C68: jal         0x80067878
    // 0x80042C6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_45;
    // 0x80042C6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_45:
L_80042C70:
    // 0x80042C70: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
L_80042C74:
    // 0x80042C74: jal         0x80067930
    // 0x80042C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_46;
    // 0x80042C78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_46:
    // 0x80042C7C: beql        $v0, $zero, L_80042CF4
    if (ctx->r2 == 0) {
        // 0x80042C80: lbu         $t3, 0x18($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X18);
            goto L_80042CF4;
    }
    goto skip_6;
    // 0x80042C80: lbu         $t3, 0x18($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X18);
    skip_6:
    // 0x80042C84: lbu         $t0, 0x18($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18);
    // 0x80042C88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042C8C: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80042C90: bne         $t0, $at, L_80042CB8
    if (ctx->r8 != ctx->r1) {
        // 0x80042C94: nop
    
            goto L_80042CB8;
    }
    // 0x80042C94: nop

    // 0x80042C98: lbu         $t1, 0x30($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X30);
    // 0x80042C9C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80042CA0: bne         $t1, $at, L_80042CB8
    if (ctx->r9 != ctx->r1) {
        // 0x80042CA4: nop
    
            goto L_80042CB8;
    }
    // 0x80042CA4: nop

    // 0x80042CA8: lw          $t2, 0x14C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14C);
    // 0x80042CAC: sltiu       $at, $t2, 0xC
    ctx->r1 = ctx->r10 < 0XC ? 1 : 0;
    // 0x80042CB0: beq         $at, $zero, L_80042CC8
    if (ctx->r1 == 0) {
        // 0x80042CB4: nop
    
            goto L_80042CC8;
    }
    // 0x80042CB4: nop

L_80042CB8:
    // 0x80042CB8: jal         0x80067878
    // 0x80042CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_47;
    // 0x80042CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_47:
    // 0x80042CC0: b           L_80042CF4
    // 0x80042CC4: lbu         $t3, 0x18($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X18);
        goto L_80042CF4;
    // 0x80042CC4: lbu         $t3, 0x18($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X18);
L_80042CC8:
    // 0x80042CC8: jal         0x8001D770
    // 0x80042CCC: nop

    func_8001D770(rdram, ctx);
        goto after_48;
    // 0x80042CCC: nop

    after_48:
    // 0x80042CD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042CD4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80042CD8: jal         0x80067BF8
    // 0x80042CDC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_49;
    // 0x80042CDC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_49:
    // 0x80042CE0: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80042CE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042CE8: jal         0x800678F0
    // 0x80042CEC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_50;
    // 0x80042CEC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_50:
    // 0x80042CF0: lbu         $t3, 0x18($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X18);
L_80042CF4:
    // 0x80042CF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80042CF8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80042CFC: bne         $t3, $at, L_80042D18
    if (ctx->r11 != ctx->r1) {
        // 0x80042D00: nop
    
            goto L_80042D18;
    }
    // 0x80042D00: nop

    // 0x80042D04: lbu         $t4, 0x30($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X30);
    // 0x80042D08: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80042D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042D10: beq         $t4, $at, L_80042D38
    if (ctx->r12 == ctx->r1) {
        // 0x80042D14: nop
    
            goto L_80042D38;
    }
    // 0x80042D14: nop

L_80042D18:
    // 0x80042D18: jal         0x80067930
    // 0x80042D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_51;
    // 0x80042D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_51:
    // 0x80042D20: beq         $v0, $zero, L_80042DB8
    if (ctx->r2 == 0) {
        // 0x80042D24: addiu       $a0, $zero, 0x37
        ctx->r4 = ADD32(0, 0X37);
            goto L_80042DB8;
    }
    // 0x80042D24: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80042D28: jal         0x80067878
    // 0x80042D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_52;
    // 0x80042D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_52:
    // 0x80042D30: b           L_80042DBC
    // 0x80042D34: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
        goto L_80042DBC;
    // 0x80042D34: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
L_80042D38:
    // 0x80042D38: jal         0x80067930
    // 0x80042D3C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    func_80067930(rdram, ctx);
        goto after_53;
    // 0x80042D3C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_53:
    // 0x80042D40: beq         $v0, $zero, L_80042D84
    if (ctx->r2 == 0) {
        // 0x80042D44: nop
    
            goto L_80042D84;
    }
    // 0x80042D44: nop

    // 0x80042D48: jal         0x8001D770
    // 0x80042D4C: nop

    func_8001D770(rdram, ctx);
        goto after_54;
    // 0x80042D4C: nop

    after_54:
    // 0x80042D50: jal         0x8001D840
    // 0x80042D54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8001D840(rdram, ctx);
        goto after_55;
    // 0x80042D54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_55:
    // 0x80042D58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80042D5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80042D60: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80042D64: jal         0x80067D94
    // 0x80042D68: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067D94(rdram, ctx);
        goto after_56;
    // 0x80042D68: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_56:
    // 0x80042D6C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80042D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042D74: jal         0x800678F0
    // 0x80042D78: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_57;
    // 0x80042D78: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_57:
    // 0x80042D7C: b           L_80042DBC
    // 0x80042D80: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
        goto L_80042DBC;
    // 0x80042D80: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
L_80042D84:
    // 0x80042D84: jal         0x8001D770
    // 0x80042D88: nop

    func_8001D770(rdram, ctx);
        goto after_58;
    // 0x80042D88: nop

    after_58:
    // 0x80042D8C: jal         0x8001D840
    // 0x80042D90: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8001D840(rdram, ctx);
        goto after_59;
    // 0x80042D90: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_59:
    // 0x80042D94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80042D98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80042D9C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80042DA0: jal         0x80067D94
    // 0x80042DA4: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    func_80067D94(rdram, ctx);
        goto after_60;
    // 0x80042DA4: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    after_60:
    // 0x80042DA8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80042DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042DB0: jal         0x80067838
    // 0x80042DB4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_61;
    // 0x80042DB4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_61:
L_80042DB8:
    // 0x80042DB8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
L_80042DBC:
    // 0x80042DBC: jal         0x80067930
    // 0x80042DC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_62;
    // 0x80042DC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_62:
    // 0x80042DC4: beql        $v0, $zero, L_80042E1C
    if (ctx->r2 == 0) {
        // 0x80042DC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80042E1C;
    }
    goto skip_7;
    // 0x80042DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80042DCC: lbu         $t5, 0x18($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X18);
    // 0x80042DD0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80042DD4: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x80042DD8: beq         $t5, $at, L_80042DF0
    if (ctx->r13 == ctx->r1) {
        // 0x80042DDC: nop
    
            goto L_80042DF0;
    }
    // 0x80042DDC: nop

    // 0x80042DE0: jal         0x80067878
    // 0x80042DE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_63;
    // 0x80042DE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_63:
    // 0x80042DE8: b           L_80042E1C
    // 0x80042DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80042E1C;
    // 0x80042DEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80042DF0:
    // 0x80042DF0: jal         0x8001D770
    // 0x80042DF4: nop

    func_8001D770(rdram, ctx);
        goto after_64;
    // 0x80042DF4: nop

    after_64:
    // 0x80042DF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80042DFC: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80042E00: jal         0x80067BF8
    // 0x80042E04: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_65;
    // 0x80042E04: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_65:
    // 0x80042E08: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x80042E0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80042E10: jal         0x800678F0
    // 0x80042E14: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_66;
    // 0x80042E14: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_66:
    // 0x80042E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80042E1C:
    // 0x80042E1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80042E20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80042E24: jr          $ra
    // 0x80042E28: nop

    return;
    // 0x80042E28: nop

;}
RECOMP_FUNC void func_80076070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076070: lui         $t0, 0x800B
    ctx->r8 = S32(0X800B << 16);
    // 0x80076074: addiu       $t0, $t0, -0x7AF0
    ctx->r8 = ADD32(ctx->r8, -0X7AF0);
    // 0x80076078: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8007607C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80076080: lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // 0x80076084: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80076088: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007608C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80076090: beql        $t7, $zero, L_80076188
    if (ctx->r15 == 0) {
        // 0x80076094: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80076188;
    }
    goto skip_0;
    // 0x80076094: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    skip_0:
    // 0x80076098: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007609C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800760A0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800760A4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800760A8: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x800760AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800760B0: lhu         $t1, 0x6($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X6);
    // 0x800760B4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800760B8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800760BC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800760C0: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x800760C4: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800760C8: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800760CC: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800760D0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800760D4: lui         $t7, 0xD00
    ctx->r15 = S32(0XD00 << 16);
    // 0x800760D8: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x800760DC: addiu       $t7, $t7, 0x198
    ctx->r15 = ADD32(ctx->r15, 0X198);
    // 0x800760E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800760E4: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800760E8: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x800760EC: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800760F0: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x800760F4: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x800760F8: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x800760FC: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80076100: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80076104: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076108: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8007610C: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x80076110: ori         $t1, $t1, 0x3
    ctx->r9 = ctx->r9 | 0X3;
    // 0x80076114: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80076118: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8007611C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076120: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80076124: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x80076128: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8007612C: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80076130: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80076134: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076138: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007613C: lui         $t4, 0xFFFC
    ctx->r12 = S32(0XFFFC << 16);
    // 0x80076140: ori         $t4, $t4, 0xFFFC
    ctx->r12 = ctx->r12 | 0XFFFC;
    // 0x80076144: lui         $t3, 0xF700
    ctx->r11 = S32(0XF700 << 16);
    // 0x80076148: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8007614C: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x80076150: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076154: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80076158: lui         $t5, 0xD00
    ctx->r13 = S32(0XD00 << 16);
    // 0x8007615C: addiu       $t5, $t5, 0x1B0
    ctx->r13 = ADD32(ctx->r13, 0X1B0);
    // 0x80076160: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x80076164: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80076168: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007616C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80076170: lui         $t6, 0xD00
    ctx->r14 = S32(0XD00 << 16);
    // 0x80076174: addiu       $t6, $t6, 0x180
    ctx->r14 = ADD32(ctx->r14, 0X180);
    // 0x80076178: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x8007617C: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x80076180: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076184: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80076188:
    // 0x80076188: jr          $ra
    // 0x8007618C: nop

    return;
    // 0x8007618C: nop

;}
RECOMP_FUNC void func_80047F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80047FA4: lh          $t6, 0x184($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X184);
    // 0x80047FA8: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x80047FAC: bnel        $at, $zero, L_80047FD0
    if (ctx->r1 != 0) {
        // 0x80047FB0: lw          $t7, 0x180($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X180);
            goto L_80047FD0;
    }
    goto skip_0;
    // 0x80047FB0: lw          $t7, 0x180($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X180);
    skip_0:
    // 0x80047FB4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80047FB8: addiu       $a0, $a0, 0x7A0
    ctx->r4 = ADD32(ctx->r4, 0X7A0);
    // 0x80047FBC: jal         0x80071380
    // 0x80047FC0: addiu       $a1, $zero, 0x966
    ctx->r5 = ADD32(0, 0X966);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80047FC0: addiu       $a1, $zero, 0x966
    ctx->r5 = ADD32(0, 0X966);
    after_0:
    // 0x80047FC4: b           L_80048054
    // 0x80047FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048054;
    // 0x80047FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80047FCC: lw          $t7, 0x180($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X180);
L_80047FD0:
    // 0x80047FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80047FD4: beq         $t7, $zero, L_80047FF4
    if (ctx->r15 == 0) {
        // 0x80047FD8: nop
    
            goto L_80047FF4;
    }
    // 0x80047FD8: nop

    // 0x80047FDC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80047FE0: addiu       $a0, $a0, 0x7B0
    ctx->r4 = ADD32(ctx->r4, 0X7B0);
    // 0x80047FE4: jal         0x80071380
    // 0x80047FE8: addiu       $a1, $zero, 0x970
    ctx->r5 = ADD32(0, 0X970);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80047FE8: addiu       $a1, $zero, 0x970
    ctx->r5 = ADD32(0, 0X970);
    after_1:
    // 0x80047FEC: b           L_80048054
    // 0x80047FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048054;
    // 0x80047FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80047FF4:
    // 0x80047FF4: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
L_80047FF8:
    // 0x80047FF8: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x80047FFC: lw          $t9, 0x188($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X188);
    // 0x80048000: bnel        $t9, $zero, L_8004802C
    if (ctx->r25 != 0) {
        // 0x80048004: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8004802C;
    }
    goto skip_1;
    // 0x80048004: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x80048008: sw          $a1, 0x188($v1)
    MEM_W(0X188, ctx->r3) = ctx->r5;
    // 0x8004800C: sb          $zero, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = 0;
    // 0x80048010: sh          $v0, 0x17E($a1)
    MEM_H(0X17E, ctx->r5) = ctx->r2;
    // 0x80048014: sw          $a0, 0x180($a1)
    MEM_W(0X180, ctx->r5) = ctx->r4;
    // 0x80048018: lh          $t0, 0x184($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X184);
    // 0x8004801C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80048020: b           L_80048050
    // 0x80048024: sh          $t1, 0x184($a0)
    MEM_H(0X184, ctx->r4) = ctx->r9;
        goto L_80048050;
    // 0x80048024: sh          $t1, 0x184($a0)
    MEM_H(0X184, ctx->r4) = ctx->r9;
    // 0x80048028: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8004802C:
    // 0x8004802C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80048030: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80048034: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80048038: bnel        $at, $zero, L_80047FF8
    if (ctx->r1 != 0) {
        // 0x8004803C: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80047FF8;
    }
    goto skip_2;
    // 0x8004803C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    skip_2:
    // 0x80048040: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80048044: addiu       $a0, $a0, 0x7C0
    ctx->r4 = ADD32(ctx->r4, 0X7C0);
    // 0x80048048: jal         0x80071380
    // 0x8004804C: addiu       $a1, $zero, 0x980
    ctx->r5 = ADD32(0, 0X980);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8004804C: addiu       $a1, $zero, 0x980
    ctx->r5 = ADD32(0, 0X980);
    after_2:
L_80048050:
    // 0x80048050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048054:
    // 0x80048054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048058: jr          $ra
    // 0x8004805C: nop

    return;
    // 0x8004805C: nop

;}
RECOMP_FUNC void func_806E41CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E41CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806E41D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E41D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E41D8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E41DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E41E0: jal         0x8004700C
    // 0x806E41E4: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806E41E4: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_0:
    // 0x806E41E8: jal         0x800653D8
    // 0x806E41EC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x806E41EC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x806E41F0: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x806E41F4: jal         0x800653D8
    // 0x806E41F8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x806E41F8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_2:
    // 0x806E41FC: andi        $t7, $v0, 0x1F
    ctx->r15 = ctx->r2 & 0X1F;
    // 0x806E4200: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x806E4204: jal         0x806E3DD0
    // 0x806E4208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E3DD0(rdram, ctx);
        goto after_3;
    // 0x806E4208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806E420C: jal         0x806E3A3C
    // 0x806E4210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E3A3C(rdram, ctx);
        goto after_4;
    // 0x806E4210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806E4214: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x806E4218: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x806E421C: beql        $t8, $zero, L_806E4720
    if (ctx->r24 == 0) {
        // 0x806E4220: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E4720;
    }
    goto skip_0;
    // 0x806E4220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806E4224: lw          $t9, 0x58($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X58);
    // 0x806E4228: bnel        $t9, $zero, L_806E4720
    if (ctx->r25 != 0) {
        // 0x806E422C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806E4720;
    }
    goto skip_1;
    // 0x806E422C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806E4230: lw          $t0, 0x38($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X38);
    // 0x806E4234: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x806E4238: beq         $at, $zero, L_806E46BC
    if (ctx->r1 == 0) {
        // 0x806E423C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_806E46BC;
    }
    // 0x806E423C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x806E4240: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X21E4) << 16);
    // 0x806E4244: addu        $at, $at, $t0
    gpr jr_addend_806E424C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x806E4248: lw          $t0, 0x59E4($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(649, 0X21E4));
    // 0x806E424C: jr          $t0
    // 0x806E4250: nop

    switch (jr_addend_806E424C >> 2) {
        case 0: goto L_806E4254; break;
        case 1: goto L_806E42B8; break;
        case 2: goto L_806E4490; break;
        case 3: goto L_806E4518; break;
        case 4: goto L_806E45C0; break;
        default: switch_error(__func__, 0x806E424C, 0x806E59E4);
    }
    // 0x806E4250: nop

L_806E4254:
    // 0x806E4254: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x806E4258: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806E425C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x806E4260: lwc1        $f4, 0x84($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X84);
    // 0x806E4264: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806E4268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E426C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806E4270: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x806E4274: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E4278: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806E427C: nop

    // 0x806E4280: bc1f        L_806E4298
    if (!c1cs) {
        // 0x806E4284: nop
    
            goto L_806E4298;
    }
    // 0x806E4284: nop

    // 0x806E4288: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E428C: sw          $a1, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r5;
    // 0x806E4290: b           L_806E46BC
    // 0x806E4294: sw          $a1, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r5;
        goto L_806E46BC;
    // 0x806E4294: sw          $a1, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r5;
L_806E4298:
    // 0x806E4298: bne         $t2, $zero, L_806E46BC
    if (ctx->r10 != 0) {
        // 0x806E429C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806E46BC;
    }
    // 0x806E429C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E42A0: jal         0x806E3D64
    // 0x806E42A4: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_806E3D64(rdram, ctx);
        goto after_5;
    // 0x806E42A4: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_5:
    // 0x806E42A8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x806E42AC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x806E42B0: b           L_806E46BC
    // 0x806E42B4: sw          $t3, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r11;
        goto L_806E46BC;
    // 0x806E42B4: sw          $t3, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r11;
L_806E42B8:
    // 0x806E42B8: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x806E42BC: lwc1        $f16, 0x18($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X18);
    // 0x806E42C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x806E42C4: nop

    // 0x806E42C8: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x806E42CC: nop

    // 0x806E42D0: bc1fl       L_806E42FC
    if (!c1cs) {
        // 0x806E42D4: lw          $v0, 0x40($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X40);
            goto L_806E42FC;
    }
    goto skip_2;
    // 0x806E42D4: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    skip_2:
    // 0x806E42D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x806E42DC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(649, 0X1D50) << 16);
    // 0x806E42E0: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x806E42E4: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x806E42E8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x806E42EC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x806E42F0: lwc1        $f4, 0x5550($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(649, 0X1D50));
    // 0x806E42F4: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
    // 0x806E42F8: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
L_806E42FC:
    // 0x806E42FC: beq         $v0, $zero, L_806E4308
    if (ctx->r2 == 0) {
        // 0x806E4300: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806E4308;
    }
    // 0x806E4300: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806E4304: sw          $t6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r14;
L_806E4308:
    // 0x806E4308: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x806E430C: beq         $v0, $zero, L_806E4318
    if (ctx->r2 == 0) {
        // 0x806E4310: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_806E4318;
    }
    // 0x806E4310: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x806E4314: sw          $t7, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r15;
L_806E4318:
    // 0x806E4318: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x806E431C: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806E4320: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x806E4324: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806E4328: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806E432C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E4330: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x806E4334: nop

    // 0x806E4338: bc1fl       L_806E4370
    if (!c1cs) {
        // 0x806E433C: lw          $t0, 0x30($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X30);
            goto L_806E4370;
    }
    goto skip_3;
    // 0x806E433C: lw          $t0, 0x30($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X30);
    skip_3:
    // 0x806E4340: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    // 0x806E4344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E4348: bnel        $t8, $zero, L_806E4370
    if (ctx->r24 != 0) {
        // 0x806E434C: lw          $t0, 0x30($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X30);
            goto L_806E4370;
    }
    goto skip_4;
    // 0x806E434C: lw          $t0, 0x30($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X30);
    skip_4:
    // 0x806E4350: jal         0x806E3D64
    // 0x806E4354: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_806E3D64(rdram, ctx);
        goto after_6;
    // 0x806E4354: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_6:
    // 0x806E4358: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x806E435C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x806E4360: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E4364: b           L_806E46BC
    // 0x806E4368: sw          $t9, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r25;
        goto L_806E46BC;
    // 0x806E4368: sw          $t9, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r25;
    // 0x806E436C: lw          $t0, 0x30($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X30);
L_806E4370:
    // 0x806E4370: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4374: bnel        $t0, $zero, L_806E4444
    if (ctx->r8 != 0) {
        // 0x806E4378: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_806E4444;
    }
    goto skip_5;
    // 0x806E4378: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x806E437C: lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X34);
    // 0x806E4380: lui         $t2, 0x806E
    ctx->r10 = S32(RELOC_HI16(649, 0X1D68) << 16);
    // 0x806E4384: sw          $a1, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r5;
    // 0x806E4388: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x806E438C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806E4390: lw          $t2, 0x5568($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(649, 0X1D68));
    // 0x806E4394: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x806E4398: andi        $a0, $t3, 0x3
    ctx->r4 = ctx->r11 & 0X3;
    // 0x806E439C: sw          $t3, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r11;
    // 0x806E43A0: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x806E43A4: bne         $a0, $zero, L_806E43D4
    if (ctx->r4 != 0) {
        // 0x806E43A8: sw          $t2, 0x3C($v1)
        MEM_W(0X3C, ctx->r3) = ctx->r10;
            goto L_806E43D4;
    }
    // 0x806E43A8: sw          $t2, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r10;
    // 0x806E43AC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806E43B0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806E43B4: jal         0x80067BBC
    // 0x806E43B8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_7;
    // 0x806E43B8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_7:
    // 0x806E43BC: addiu       $a0, $zero, 0x24C
    ctx->r4 = ADD32(0, 0X24C);
    // 0x806E43C0: jal         0x80067818
    // 0x806E43C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x806E43C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x806E43C8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x806E43CC: lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X34);
    // 0x806E43D0: andi        $a0, $v0, 0x3
    ctx->r4 = ctx->r2 & 0X3;
L_806E43D4:
    // 0x806E43D4: bnel        $a0, $zero, L_806E4404
    if (ctx->r4 != 0) {
        // 0x806E43D8: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_806E4404;
    }
    goto skip_6;
    // 0x806E43D8: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    skip_6:
    // 0x806E43DC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806E43E0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806E43E4: jal         0x80067BBC
    // 0x806E43E8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_9;
    // 0x806E43E8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_9:
    // 0x806E43EC: addiu       $a0, $zero, 0x259
    ctx->r4 = ADD32(0, 0X259);
    // 0x806E43F0: jal         0x80067818
    // 0x806E43F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x806E43F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x806E43F8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x806E43FC: lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X34);
    // 0x806E4400: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
L_806E4404:
    // 0x806E4404: bnel        $at, $zero, L_806E4444
    if (ctx->r1 != 0) {
        // 0x806E4408: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_806E4444;
    }
    goto skip_7;
    // 0x806E4408: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_7:
    // 0x806E440C: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E4410: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x806E4414: bnel        $t4, $zero, L_806E4444
    if (ctx->r12 != 0) {
        // 0x806E4418: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_806E4444;
    }
    goto skip_8;
    // 0x806E4418: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_8:
    // 0x806E441C: lw          $t5, 0x40($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X40);
    // 0x806E4420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E4424: bnel        $t5, $zero, L_806E4444
    if (ctx->r13 != 0) {
        // 0x806E4428: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_806E4444;
    }
    goto skip_9;
    // 0x806E4428: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_9:
    // 0x806E442C: jal         0x806E3D64
    // 0x806E4430: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_806E3D64(rdram, ctx);
        goto after_11;
    // 0x806E4430: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_11:
    // 0x806E4434: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x806E4438: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x806E443C: sw          $t6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r14;
    // 0x806E4440: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_806E4444:
    // 0x806E4444: lwc1        $f18, 0x84($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806E4448: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x806E444C: lwc1        $f16, 0x84($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X84);
    // 0x806E4450: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806E4454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E4458: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806E445C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E4460: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806E4464: nop

    // 0x806E4468: bc1fl       L_806E46C0
    if (!c1cs) {
        // 0x806E446C: lw          $t8, 0x44($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X44);
            goto L_806E46C0;
    }
    goto skip_10;
    // 0x806E446C: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
    skip_10:
    // 0x806E4470: jal         0x806E3D64
    // 0x806E4474: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_806E3D64(rdram, ctx);
        goto after_12;
    // 0x806E4474: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_12:
    // 0x806E4478: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x806E447C: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x806E4480: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x806E4484: sw          $t9, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r25;
    // 0x806E4488: b           L_806E46BC
    // 0x806E448C: sw          $t8, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r24;
        goto L_806E46BC;
    // 0x806E448C: sw          $t8, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r24;
L_806E4490:
    // 0x806E4490: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x806E4494: beq         $v0, $zero, L_806E44A4
    if (ctx->r2 == 0) {
        // 0x806E4498: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_806E44A4;
    }
    // 0x806E4498: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x806E449C: sw          $t0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r8;
    // 0x806E44A0: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_806E44A4:
    // 0x806E44A4: bnel        $v0, $zero, L_806E46C0
    if (ctx->r2 != 0) {
        // 0x806E44A8: lw          $t8, 0x44($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X44);
            goto L_806E46C0;
    }
    goto skip_11;
    // 0x806E44A8: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
    skip_11:
    // 0x806E44AC: lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X34);
    // 0x806E44B0: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(649, 0X1D98) << 16);
    // 0x806E44B4: lui         $t2, 0x806E
    ctx->r10 = S32(RELOC_HI16(649, 0X1D80) << 16);
    // 0x806E44B8: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x806E44BC: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x806E44C0: lw          $t1, 0x5598($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(649, 0X1D98));
    // 0x806E44C4: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x806E44C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x806E44CC: sw          $t1, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r9;
    // 0x806E44D0: lw          $t2, 0x5580($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(649, 0X1D80));
    // 0x806E44D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E44D8: bne         $v0, $at, L_806E44F4
    if (ctx->r2 != ctx->r1) {
        // 0x806E44DC: sw          $t2, 0x3C($v1)
        MEM_W(0X3C, ctx->r3) = ctx->r10;
            goto L_806E44F4;
    }
    // 0x806E44DC: sw          $t2, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r10;
    // 0x806E44E0: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x806E44E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x806E44E8: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x806E44EC: sw          $t5, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r13;
    // 0x806E44F0: lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X34);
L_806E44F4:
    // 0x806E44F4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x806E44F8: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x806E44FC: bne         $at, $zero, L_806E46BC
    if (ctx->r1 != 0) {
        // 0x806E4500: sw          $t6, 0x34($v1)
        MEM_W(0X34, ctx->r3) = ctx->r14;
            goto L_806E46BC;
    }
    // 0x806E4500: sw          $t6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r14;
    // 0x806E4504: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x806E4508: sw          $t8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r24;
    // 0x806E450C: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E4510: b           L_806E46BC
    // 0x806E4514: sw          $a1, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r5;
        goto L_806E46BC;
    // 0x806E4514: sw          $a1, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r5;
L_806E4518:
    // 0x806E4518: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x806E451C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x806E4520: beq         $v0, $zero, L_806E4530
    if (ctx->r2 == 0) {
        // 0x806E4524: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_806E4530;
    }
    // 0x806E4524: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x806E4528: sw          $t9, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r25;
    // 0x806E452C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_806E4530:
    // 0x806E4530: bnel        $v0, $zero, L_806E46C0
    if (ctx->r2 != 0) {
        // 0x806E4534: lw          $t8, 0x44($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X44);
            goto L_806E46C0;
    }
    goto skip_12;
    // 0x806E4534: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
    skip_12:
    // 0x806E4538: lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X34);
    // 0x806E453C: lui         $t2, 0x806E
    ctx->r10 = S32(RELOC_HI16(649, 0X1D58) << 16);
    // 0x806E4540: sw          $t0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r8;
    // 0x806E4544: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x806E4548: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806E454C: lw          $t2, 0x5558($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(649, 0X1D58));
    // 0x806E4550: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x806E4554: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x806E4558: sw          $t4, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r12;
    // 0x806E455C: bne         $at, $zero, L_806E46BC
    if (ctx->r1 != 0) {
        // 0x806E4560: sw          $t2, 0x3C($v1)
        MEM_W(0X3C, ctx->r3) = ctx->r10;
            goto L_806E46BC;
    }
    // 0x806E4560: sw          $t2, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r10;
    // 0x806E4564: lw          $t5, 0x48($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X48);
    // 0x806E4568: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E456C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x806E4570: sw          $t6, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r14;
    // 0x806E4574: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806E4578: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806E457C: jal         0x80067BBC
    // 0x806E4580: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_13;
    // 0x806E4580: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_13:
    // 0x806E4584: addiu       $a0, $zero, 0x24A
    ctx->r4 = ADD32(0, 0X24A);
    // 0x806E4588: jal         0x80067818
    // 0x806E458C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_14;
    // 0x806E458C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x806E4590: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x806E4594: lw          $t7, 0x48($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X48);
    // 0x806E4598: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x806E459C: bnel        $at, $zero, L_806E46C0
    if (ctx->r1 != 0) {
        // 0x806E45A0: lw          $t8, 0x44($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X44);
            goto L_806E46C0;
    }
    goto skip_13;
    // 0x806E45A0: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
    skip_13:
    // 0x806E45A4: lw          $t8, 0x54($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X54);
    // 0x806E45A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E45AC: sw          $zero, 0x48($v1)
    MEM_W(0X48, ctx->r3) = 0;
    // 0x806E45B0: bne         $t8, $zero, L_806E46BC
    if (ctx->r24 != 0) {
        // 0x806E45B4: sw          $a1, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->r5;
            goto L_806E46BC;
    }
    // 0x806E45B4: sw          $a1, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r5;
    // 0x806E45B8: b           L_806E46BC
    // 0x806E45BC: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
        goto L_806E46BC;
    // 0x806E45BC: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
L_806E45C0:
    // 0x806E45C0: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x806E45C4: beq         $v0, $zero, L_806E45D4
    if (ctx->r2 == 0) {
        // 0x806E45C8: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_806E45D4;
    }
    // 0x806E45C8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x806E45CC: sw          $t9, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r25;
    // 0x806E45D0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_806E45D4:
    // 0x806E45D4: bnel        $v0, $zero, L_806E4650
    if (ctx->r2 != 0) {
        // 0x806E45D8: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_806E4650;
    }
    goto skip_14;
    // 0x806E45D8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    skip_14:
    // 0x806E45DC: lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X34);
    // 0x806E45E0: lui         $t0, 0x806E
    ctx->r8 = S32(RELOC_HI16(649, 0X1EB0) << 16);
    // 0x806E45E4: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(649, 0X1DB0) << 16);
    // 0x806E45E8: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x806E45EC: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x806E45F0: lw          $t0, 0x56B0($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(649, 0X1EB0));
    // 0x806E45F4: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x806E45F8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x806E45FC: sw          $t0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r8;
    // 0x806E4600: lw          $t1, 0x55B0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(649, 0X1DB0));
    // 0x806E4604: slti        $at, $t2, 0x40
    ctx->r1 = SIGNED(ctx->r10) < 0X40 ? 1 : 0;
    // 0x806E4608: sw          $t2, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r10;
    // 0x806E460C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x806E4610: bne         $at, $zero, L_806E4620
    if (ctx->r1 != 0) {
        // 0x806E4614: sw          $t1, 0x3C($v1)
        MEM_W(0X3C, ctx->r3) = ctx->r9;
            goto L_806E4620;
    }
    // 0x806E4614: sw          $t1, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r9;
    // 0x806E4618: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E461C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806E4620:
    // 0x806E4620: andi        $t4, $v0, 0x7
    ctx->r12 = ctx->r2 & 0X7;
    // 0x806E4624: bnel        $t4, $zero, L_806E4650
    if (ctx->r12 != 0) {
        // 0x806E4628: lw          $t3, 0x34($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X34);
            goto L_806E4650;
    }
    goto skip_15;
    // 0x806E4628: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    skip_15:
    // 0x806E462C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806E4630: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806E4634: jal         0x80067BBC
    // 0x806E4638: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_15;
    // 0x806E4638: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_15:
    // 0x806E463C: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    // 0x806E4640: jal         0x80067818
    // 0x806E4644: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_16;
    // 0x806E4644: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x806E4648: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x806E464C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_806E4650:
    // 0x806E4650: lwc1        $f12, 0x84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806E4654: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x806E4658: lwc1        $f2, 0x84($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0X84);
    // 0x806E465C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E4660: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x806E4664: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E4668: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x806E466C: nop

    // 0x806E4670: bc1fl       L_806E4694
    if (!c1cs) {
        // 0x806E4674: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_806E4694;
    }
    goto skip_16;
    // 0x806E4674: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_16:
    // 0x806E4678: lw          $t5, 0x4C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4C);
    // 0x806E467C: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E4680: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E4684: sw          $t5, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r13;
    // 0x806E4688: b           L_806E46BC
    // 0x806E468C: sw          $a1, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r5;
        goto L_806E46BC;
    // 0x806E468C: sw          $a1, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r5;
    // 0x806E4690: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_806E4694:
    // 0x806E4694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806E4698: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x806E469C: bc1fl       L_806E46AC
    if (!c1cs) {
        // 0x806E46A0: lw          $t6, 0x138($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X138);
            goto L_806E46AC;
    }
    goto skip_17;
    // 0x806E46A0: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    skip_17:
    // 0x806E46A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806E46A8: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
L_806E46AC:
    // 0x806E46AC: beql        $v0, $t6, L_806E46C0
    if (ctx->r2 == ctx->r14) {
        // 0x806E46B0: lw          $t8, 0x44($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X44);
            goto L_806E46C0;
    }
    goto skip_18;
    // 0x806E46B0: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
    skip_18:
    // 0x806E46B4: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E46B8: sw          $t7, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r15;
L_806E46BC:
    // 0x806E46BC: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
L_806E46C0:
    // 0x806E46C0: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x806E46C4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x806E46C8: bne         $t8, $zero, L_806E46E0
    if (ctx->r24 != 0) {
        // 0x806E46CC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_806E46E0;
    }
    // 0x806E46CC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806E46D0: lw          $t9, -0x7294($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7294);
    // 0x806E46D4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806E46D8: beql        $t0, $zero, L_806E4704
    if (ctx->r8 == 0) {
        // 0x806E46DC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_806E4704;
    }
    goto skip_19;
    // 0x806E46DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_19:
L_806E46E0:
    // 0x806E46E0: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x806E46E4: sw          $t1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r9;
    // 0x806E46E8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x806E46EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E46F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E46F4: jal         0x806E511C
    // 0x806E46F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806E511C(rdram, ctx);
        goto after_17;
    // 0x806E46F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_17:
    // 0x806E46FC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x806E4700: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_806E4704:
    // 0x806E4704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806E4708: jal         0x80048F84
    // 0x806E470C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_18;
    // 0x806E470C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_18:
    // 0x806E4710: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806E4714: jal         0x80048F84
    // 0x806E4718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_19;
    // 0x806E4718: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x806E471C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806E4720:
    // 0x806E4720: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E4724: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x806E4728: jr          $ra
    // 0x806E472C: nop

    return;
    // 0x806E472C: nop

;}
RECOMP_FUNC void func_805365C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805365C4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805365C8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805365CC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805365D0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805365D4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805365D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805365DC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805365E0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805365E4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805365E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805365EC: jr          $ra
    // 0x805365F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805365F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80703480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80703480: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80703484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80703488: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070348C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80703490: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x80703494: jal         0x80049D74
    // 0x80703498: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x80703498: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8070349C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807034A0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x807034A4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807034A8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807034AC: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x807034B0: lbu         $v0, 0x60($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X60);
    // 0x807034B4: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x807034B8: xori        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 ^ 0X10;
    // 0x807034BC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x807034C0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x807034C4: sw          $v0, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r2;
    // 0x807034C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807034CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807034D0: jr          $ra
    // 0x807034D4: nop

    return;
    // 0x807034D4: nop

;}
RECOMP_FUNC void func_80798B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80798B20: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80798B24: slti        $at, $v0, 0x46E2
    ctx->r1 = SIGNED(ctx->r2) < 0X46E2 ? 1 : 0;
    // 0x80798B28: bne         $at, $zero, L_80798B50
    if (ctx->r1 != 0) {
        // 0x80798B2C: addiu       $at, $zero, 0x471C
        ctx->r1 = ADD32(0, 0X471C);
            goto L_80798B50;
    }
    // 0x80798B2C: addiu       $at, $zero, 0x471C
    ctx->r1 = ADD32(0, 0X471C);
    // 0x80798B30: beq         $v0, $at, L_80798BB4
    if (ctx->r2 == ctx->r1) {
        // 0x80798B34: addiu       $at, $zero, 0x471D
        ctx->r1 = ADD32(0, 0X471D);
            goto L_80798BB4;
    }
    // 0x80798B34: addiu       $at, $zero, 0x471D
    ctx->r1 = ADD32(0, 0X471D);
    // 0x80798B38: beq         $v0, $at, L_80798BB4
    if (ctx->r2 == ctx->r1) {
        // 0x80798B3C: addiu       $at, $zero, 0x471E
        ctx->r1 = ADD32(0, 0X471E);
            goto L_80798BB4;
    }
    // 0x80798B3C: addiu       $at, $zero, 0x471E
    ctx->r1 = ADD32(0, 0X471E);
    // 0x80798B40: beq         $v0, $at, L_80798BB4
    if (ctx->r2 == ctx->r1) {
        // 0x80798B44: nop
    
            goto L_80798BB4;
    }
    // 0x80798B44: nop

    // 0x80798B48: b           L_80798BF4
    // 0x80798B4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80798BF4;
    // 0x80798B4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80798B50:
    // 0x80798B50: slti        $at, $v0, 0x46D9
    ctx->r1 = SIGNED(ctx->r2) < 0X46D9 ? 1 : 0;
    // 0x80798B54: bne         $at, $zero, L_80798B74
    if (ctx->r1 != 0) {
        // 0x80798B58: addiu       $at, $zero, 0x46D9
        ctx->r1 = ADD32(0, 0X46D9);
            goto L_80798B74;
    }
    // 0x80798B58: addiu       $at, $zero, 0x46D9
    ctx->r1 = ADD32(0, 0X46D9);
    // 0x80798B5C: beq         $v0, $at, L_80798BE4
    if (ctx->r2 == ctx->r1) {
        // 0x80798B60: addiu       $at, $zero, 0x46E1
        ctx->r1 = ADD32(0, 0X46E1);
            goto L_80798BE4;
    }
    // 0x80798B60: addiu       $at, $zero, 0x46E1
    ctx->r1 = ADD32(0, 0X46E1);
    // 0x80798B64: beq         $v0, $at, L_80798BB4
    if (ctx->r2 == ctx->r1) {
        // 0x80798B68: nop
    
            goto L_80798BB4;
    }
    // 0x80798B68: nop

    // 0x80798B6C: b           L_80798BF4
    // 0x80798B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80798BF4;
    // 0x80798B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80798B74:
    // 0x80798B74: slti        $at, $v0, 0x46B9
    ctx->r1 = SIGNED(ctx->r2) < 0X46B9 ? 1 : 0;
    // 0x80798B78: bne         $at, $zero, L_80798B94
    if (ctx->r1 != 0) {
        // 0x80798B7C: addiu       $t6, $v0, -0x469B
        ctx->r14 = ADD32(ctx->r2, -0X469B);
            goto L_80798B94;
    }
    // 0x80798B7C: addiu       $t6, $v0, -0x469B
    ctx->r14 = ADD32(ctx->r2, -0X469B);
    // 0x80798B80: addiu       $at, $zero, 0x46D8
    ctx->r1 = ADD32(0, 0X46D8);
    // 0x80798B84: beq         $v0, $at, L_80798BD8
    if (ctx->r2 == ctx->r1) {
        // 0x80798B88: nop
    
            goto L_80798BD8;
    }
    // 0x80798B88: nop

    // 0x80798B8C: b           L_80798BF4
    // 0x80798B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80798BF4;
    // 0x80798B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80798B94:
    // 0x80798B94: sltiu       $at, $t6, 0x1E
    ctx->r1 = ctx->r14 < 0X1E ? 1 : 0;
    // 0x80798B98: beq         $at, $zero, L_80798BF0
    if (ctx->r1 == 0) {
        // 0x80798B9C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80798BF0;
    }
    // 0x80798B9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80798BA0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X2560) << 16);
    // 0x80798BA4: addu        $at, $at, $t6
    gpr jr_addend_80798BAC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80798BA8: lw          $t6, -0x4F80($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(826, 0X2560));
    // 0x80798BAC: jr          $t6
    // 0x80798BB0: nop

    switch (jr_addend_80798BAC >> 2) {
        case 0: goto L_80798BB4; break;
        case 1: goto L_80798BF0; break;
        case 2: goto L_80798BF0; break;
        case 3: goto L_80798BF0; break;
        case 4: goto L_80798BF0; break;
        case 5: goto L_80798BF0; break;
        case 6: goto L_80798BF0; break;
        case 7: goto L_80798BF0; break;
        case 8: goto L_80798BF0; break;
        case 9: goto L_80798BF0; break;
        case 10: goto L_80798BF0; break;
        case 11: goto L_80798BF0; break;
        case 12: goto L_80798BF0; break;
        case 13: goto L_80798BF0; break;
        case 14: goto L_80798BF0; break;
        case 15: goto L_80798BF0; break;
        case 16: goto L_80798BF0; break;
        case 17: goto L_80798BF0; break;
        case 18: goto L_80798BF0; break;
        case 19: goto L_80798BF0; break;
        case 20: goto L_80798BC0; break;
        case 21: goto L_80798BF0; break;
        case 22: goto L_80798BF0; break;
        case 23: goto L_80798BCC; break;
        case 24: goto L_80798BCC; break;
        case 25: goto L_80798BB4; break;
        case 26: goto L_80798BB4; break;
        case 27: goto L_80798BB4; break;
        case 28: goto L_80798BB4; break;
        case 29: goto L_80798BB4; break;
        default: switch_error(__func__, 0x80798BAC, 0x8079B080);
    }
    // 0x80798BB0: nop

L_80798BB4:
    // 0x80798BB4: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(826, 0X2318) << 16);
    // 0x80798BB8: jr          $ra
    // 0x80798BBC: addiu       $v0, $v0, -0x51C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(826, 0X2318));
    return;
    // 0x80798BBC: addiu       $v0, $v0, -0x51C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(826, 0X2318));
L_80798BC0:
    // 0x80798BC0: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(826, 0X290) << 16);
    // 0x80798BC4: jr          $ra
    // 0x80798BC8: addiu       $v0, $v0, -0x7250
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(826, 0X290));
    return;
    // 0x80798BC8: addiu       $v0, $v0, -0x7250
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(826, 0X290));
L_80798BCC:
    // 0x80798BCC: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(826, 0XA9C) << 16);
    // 0x80798BD0: jr          $ra
    // 0x80798BD4: addiu       $v0, $v0, -0x6A44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(826, 0XA9C));
    return;
    // 0x80798BD4: addiu       $v0, $v0, -0x6A44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(826, 0XA9C));
L_80798BD8:
    // 0x80798BD8: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(826, 0XCD0) << 16);
    // 0x80798BDC: jr          $ra
    // 0x80798BE0: addiu       $v0, $v0, -0x6810
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(826, 0XCD0));
    return;
    // 0x80798BE0: addiu       $v0, $v0, -0x6810
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(826, 0XCD0));
L_80798BE4:
    // 0x80798BE4: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(826, 0XD60) << 16);
    // 0x80798BE8: jr          $ra
    // 0x80798BEC: addiu       $v0, $v0, -0x6780
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(826, 0XD60));
    return;
    // 0x80798BEC: addiu       $v0, $v0, -0x6780
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(826, 0XD60));
L_80798BF0:
    // 0x80798BF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80798BF4:
    // 0x80798BF4: jr          $ra
    // 0x80798BF8: nop

    return;
    // 0x80798BF8: nop

;}
RECOMP_FUNC void func_804BD568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BD56C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD570: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804BD574: jal         0x80045A34
    // 0x804BD578: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804BD578: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    after_0:
    // 0x804BD57C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804BD580: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x804BD584: bne         $v0, $zero, L_804BD594
    if (ctx->r2 != 0) {
        // 0x804BD588: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BD594;
    }
    // 0x804BD588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BD58C: b           L_804BD598
    // 0x804BD590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BD598;
    // 0x804BD590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BD594:
    // 0x804BD594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804BD598:
    // 0x804BD598: jr          $ra
    // 0x804BD59C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804BD59C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804654F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804654F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804654FC: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x80465500: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x80465504: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80465508: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046550C: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80465510: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x80465514: lw          $a2, 0x2858($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X2858);
    // 0x80465518: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8046551C: lwc1        $f10, 0x78($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X78);
    // 0x80465520: lwc1        $f8, 0x30($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80465524: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80465528: lwc1        $f4, 0x7C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X7C);
    // 0x8046552C: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80465530: lwc1        $f14, 0xC8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80465534: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80465538: sub.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8046553C: bltz        $a2, L_80465618
    if (SIGNED(ctx->r6) < 0) {
        // 0x80465540: addiu       $a1, $v0, 0x1754
        ctx->r5 = ADD32(ctx->r2, 0X1754);
            goto L_80465618;
    }
    // 0x80465540: addiu       $a1, $v0, 0x1754
    ctx->r5 = ADD32(ctx->r2, 0X1754);
    // 0x80465544: lui         $at, 0xC37A
    ctx->r1 = S32(0XC37A << 16);
    // 0x80465548: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8046554C: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x80465550: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80465554: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80465558: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8046555C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80465560: sub.s       $f2, $f18, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x80465564: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80465568: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8046556C: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80465570: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80465574: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80465578: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8046557C: nop

L_80465580:
    // 0x80465580: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80465584: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80465588: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8046558C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80465590: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80465594: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80465598: nop

    // 0x8046559C: bc1fl       L_804655B4
    if (!c1cs) {
        // 0x804655A0: c.lt.s      $f12, $f24
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
            goto L_804655B4;
    }
    goto skip_0;
    // 0x804655A0: c.lt.s      $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
    skip_0:
    // 0x804655A4: sub.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x804655A8: b           L_804655C8
    // 0x804655AC: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
        goto L_804655C8;
    // 0x804655AC: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x804655B0: c.lt.s      $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
L_804655B4:
    // 0x804655B4: nop

    // 0x804655B8: bc1fl       L_804655CC
    if (!c1cs) {
        // 0x804655BC: lwc1        $f4, 0x4($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
            goto L_804655CC;
    }
    goto skip_1;
    // 0x804655BC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    skip_1:
    // 0x804655C0: add.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x804655C4: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_804655C8:
    // 0x804655C8: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
L_804655CC:
    // 0x804655CC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804655D0: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x804655D4: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x804655D8: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x804655DC: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x804655E0: nop

    // 0x804655E4: bc1fl       L_804655FC
    if (!c1cs) {
        // 0x804655E8: c.lt.s      $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
            goto L_804655FC;
    }
    goto skip_2;
    // 0x804655E8: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
    skip_2:
    // 0x804655EC: sub.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f20.fl;
    // 0x804655F0: b           L_80465610
    // 0x804655F4: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
        goto L_80465610;
    // 0x804655F4: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x804655F8: c.lt.s      $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f12.fl < ctx->f22.fl;
L_804655FC:
    // 0x804655FC: nop

    // 0x80465600: bc1f        L_80465610
    if (!c1cs) {
        // 0x80465604: nop
    
            goto L_80465610;
    }
    // 0x80465604: nop

    // 0x80465608: add.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x8046560C: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_80465610:
    // 0x80465610: bgez        $a2, L_80465580
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80465614: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80465580;
    }
    // 0x80465614: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80465618:
    // 0x80465618: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8046561C: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x80465620: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x80465624: jr          $ra
    // 0x80465628: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80465628: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_805DCC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCC90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DCC94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DCC98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805DCC9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805DCCA0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805DCCA4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x805DCCA8: lbu         $t8, 0x18($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X18);
    // 0x805DCCAC: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805DCCB0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DCCB4: bnel        $t8, $at, L_805DCCF0
    if (ctx->r24 != ctx->r1) {
        // 0x805DCCB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805DCCF0;
    }
    goto skip_0;
    // 0x805DCCB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805DCCBC: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x805DCCC0: beql        $a1, $zero, L_805DCCE4
    if (ctx->r5 == 0) {
        // 0x805DCCC4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_805DCCE4;
    }
    goto skip_1;
    // 0x805DCCC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x805DCCC8: jal         0x80047EB0
    // 0x805DCCCC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80047EB0(rdram, ctx);
        goto after_0;
    // 0x805DCCCC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805DCCD0: beq         $v0, $zero, L_805DCCE0
    if (ctx->r2 == 0) {
        // 0x805DCCD4: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_805DCCE0;
    }
    // 0x805DCCD4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805DCCD8: jal         0x8004816C
    // 0x805DCCDC: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x805DCCDC: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    after_1:
L_805DCCE0:
    // 0x805DCCE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_805DCCE4:
    // 0x805DCCE4: jal         0x8003DC78
    // 0x805DCCE8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8003DC78(rdram, ctx);
        goto after_2;
    // 0x805DCCE8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x805DCCEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805DCCF0:
    // 0x805DCCF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DCCF4: jr          $ra
    // 0x805DCCF8: nop

    return;
    // 0x805DCCF8: nop

;}
RECOMP_FUNC void func_804CF9D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF9D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CF9DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CF9E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804CF9E4: jal         0x80047090
    // 0x804CF9E8: addiu       $a0, $zero, 0x4123
    ctx->r4 = ADD32(0, 0X4123);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804CF9E8: addiu       $a0, $zero, 0x4123
    ctx->r4 = ADD32(0, 0X4123);
    after_0:
    // 0x804CF9EC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804CF9F0: bne         $v0, $at, L_804CFA00
    if (ctx->r2 != ctx->r1) {
        // 0x804CF9F4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804CFA00;
    }
    // 0x804CF9F4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804CF9F8: b           L_804CFA7C
    // 0x804CF9FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CFA7C;
    // 0x804CF9FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CFA00:
    // 0x804CFA00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804CFA04: lui         $at, 0x4123
    ctx->r1 = S32(0X4123 << 16);
    // 0x804CFA08: lui         $a3, 0xBC23
    ctx->r7 = S32(0XBC23 << 16);
    // 0x804CFA0C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804CFA10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x804CFA14: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x804CFA18: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804CFA1C: jal         0x8004613C
    // 0x804CFA20: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804CFA20: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x804CFA24: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x804CFA28: bne         $v0, $zero, L_804CFA38
    if (ctx->r2 != 0) {
        // 0x804CFA2C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804CFA38;
    }
    // 0x804CFA2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804CFA30: b           L_804CFA7C
    // 0x804CFA34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CFA7C;
    // 0x804CFA34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CFA38:
    // 0x804CFA38: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x804CFA3C: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x804CFA40: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x804CFA44: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x804CFA48: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x804CFA4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804CFA50: jal         0x80047F9C
    // 0x804CFA54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804CFA54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x804CFA58: jal         0x804CE928
    // 0x804CFA5C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_804CE928(rdram, ctx);
        goto after_3;
    // 0x804CFA5C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x804CFA60: bne         $v0, $zero, L_804CFA70
    if (ctx->r2 != 0) {
        // 0x804CFA64: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_804CFA70;
    }
    // 0x804CFA64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x804CFA68: b           L_804CFA7C
    // 0x804CFA6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804CFA7C;
    // 0x804CFA6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804CFA70:
    // 0x804CFA70: jal         0x8005FDC4
    // 0x804CFA74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x804CFA74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x804CFA78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804CFA7C:
    // 0x804CFA7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CFA80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CFA84: jr          $ra
    // 0x804CFA88: nop

    return;
    // 0x804CFA88: nop

;}
RECOMP_FUNC void func_806FB994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FB994: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806FB998: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806FB99C: lw          $t6, 0x14A0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14A0);
    // 0x806FB9A0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x806FB9A4: sw          $t7, 0x14A0($a1)
    MEM_W(0X14A0, ctx->r5) = ctx->r15;
    // 0x806FB9A8: bgez        $t7, L_806FB9B8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x806FB9AC: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_806FB9B8;
    }
    // 0x806FB9AC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x806FB9B0: addiu       $v1, $t7, 0x280
    ctx->r3 = ADD32(ctx->r15, 0X280);
    // 0x806FB9B4: sw          $v1, 0x14A0($a1)
    MEM_W(0X14A0, ctx->r5) = ctx->r3;
L_806FB9B8:
    // 0x806FB9B8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806FB9BC: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x806FB9C0: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x806FB9C4: swc1        $f4, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->f4.u32l;
    // 0x806FB9C8: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806FB9CC: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(700, 0X2600) << 16);
    // 0x806FB9D0: addiu       $v0, $v0, 0xA0
    ctx->r2 = ADD32(ctx->r2, 0XA0);
    // 0x806FB9D4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x806FB9D8: lw          $t0, 0x138($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X138);
    // 0x806FB9DC: lw          $a3, 0x40($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X40);
    // 0x806FB9E0: lw          $a2, 0x3C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X3C);
    // 0x806FB9E4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x806FB9E8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x806FB9EC: lwc1        $f8, -0x3DD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(700, 0X2600));
    // 0x806FB9F0: jal         0x806FA738
    // 0x806FB9F4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_806FA738(rdram, ctx);
        goto after_0;
    // 0x806FB9F4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x806FB9F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806FB9FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806FBA00: jr          $ra
    // 0x806FBA04: nop

    return;
    // 0x806FBA04: nop

;}
RECOMP_FUNC void func_80698F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80698F80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80698F84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80698F88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80698F8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80698F90: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80698F94: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x80698F98: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80698F9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80698FA0: bnel        $t6, $at, L_80699018
    if (ctx->r14 != ctx->r1) {
        // 0x80698FA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80699018;
    }
    goto skip_0;
    // 0x80698FA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80698FA8: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x80698FAC: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80698FB0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80698FB4: beql        $t7, $at, L_80699018
    if (ctx->r15 == ctx->r1) {
        // 0x80698FB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80699018;
    }
    goto skip_1;
    // 0x80698FB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80698FBC: jal         0x8002F92C
    // 0x80698FC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8002F92C(rdram, ctx);
        goto after_0;
    // 0x80698FC0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80698FC4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80698FC8: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x80698FCC: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x80698FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80698FD4: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80698FD8: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x80698FDC: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x80698FE0: jalr        $t9
    // 0x80698FE4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80698FE4: nop

    after_1:
    // 0x80698FE8: jal         0x800447C8
    // 0x80698FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x80698FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80698FF0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80698FF4: jal         0x8003D8DC
    // 0x80698FF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003D8DC(rdram, ctx);
        goto after_3;
    // 0x80698FF8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80698FFC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80699000: jal         0x80067BBC
    // 0x80699004: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x80699004: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x80699008: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x8069900C: jal         0x80067818
    // 0x80699010: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x80699010: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80699014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80699018:
    // 0x80699018: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069901C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80699020: jr          $ra
    // 0x80699024: nop

    return;
    // 0x80699024: nop

;}
RECOMP_FUNC void func_804C1ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1ABC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804C1AC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C1AC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C1AC8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C1ACC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C1AD0: jal         0x804C192C
    // 0x804C1AD4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_804C192C(rdram, ctx);
        goto after_0;
    // 0x804C1AD4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x804C1AD8: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x804C1ADC: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804C1AE0: lwc1        $f14, 0x28($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X28);
    // 0x804C1AE4: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x804C1AE8: jal         0x80065ABC
    // 0x804C1AEC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x804C1AEC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x804C1AF0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804C1AF4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x804C1AF8: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(203, 0X1144) << 16);
    // 0x804C1AFC: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x804C1B00: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x804C1B04: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804C1B08: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x804C1B0C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804C1B10: nop

    // 0x804C1B14: bc1fl       L_804C1B5C
    if (!c1cs) {
        // 0x804C1B18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804C1B5C;
    }
    goto skip_0;
    // 0x804C1B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804C1B1C: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x804C1B20: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804C1B24: lwc1        $f10, 0x28B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(203, 0X1144));
    // 0x804C1B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C1B2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C1B30: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804C1B34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x804C1B38: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x804C1B3C: jal         0x804C1F2C
    // 0x804C1B40: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804C1F2C(rdram, ctx);
        goto after_2;
    // 0x804C1B40: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x804C1B44: jal         0x804C19BC
    // 0x804C1B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C19BC(rdram, ctx);
        goto after_3;
    // 0x804C1B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804C1B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C1B50: jal         0x804C17B0
    // 0x804C1B54: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    func_804C17B0(rdram, ctx);
        goto after_4;
    // 0x804C1B54: addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    after_4:
    // 0x804C1B58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C1B5C:
    // 0x804C1B5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C1B60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804C1B64: jr          $ra
    // 0x804C1B68: nop

    return;
    // 0x804C1B68: nop

;}
RECOMP_FUNC void func_8007D508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D508: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007D50C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D510: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007D514: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8007D518: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8007D51C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007D520: jal         0x800824B0
    // 0x8007D524: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8007D524: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_0:
    // 0x8007D528: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007D52C: sh          $zero, 0x48($t6)
    MEM_H(0X48, ctx->r14) = 0;
    // 0x8007D530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D534: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D538: jr          $ra
    // 0x8007D53C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007D53C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80776C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80776C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80776C40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80776C44: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80776C48: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x80776C4C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80776C50: jal         0x80067BBC
    // 0x80776C54: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80776C54: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80776C58: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80776C5C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80776C60: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80776C64: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x80776C68: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80776C6C: bne         $a1, $at, L_80776C8C
    if (ctx->r5 != ctx->r1) {
        // 0x80776C70: nop
    
            goto L_80776C8C;
    }
    // 0x80776C70: nop

    // 0x80776C74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80776C78: jal         0x80067F78
    // 0x80776C7C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80776C7C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80776C80: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80776C84: b           L_80776C94
    // 0x80776C88: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
        goto L_80776C94;
    // 0x80776C88: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
L_80776C8C:
    // 0x80776C8C: jal         0x800678F0
    // 0x80776C90: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_800678F0(rdram, ctx);
        goto after_2;
    // 0x80776C90: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_2:
L_80776C94:
    // 0x80776C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80776C98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80776C9C: jr          $ra
    // 0x80776CA0: nop

    return;
    // 0x80776CA0: nop

;}
RECOMP_FUNC void func_806EE664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE664: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x806EE668: bnel        $t6, $zero, L_806EE690
    if (ctx->r14 != 0) {
        // 0x806EE66C: lh          $t9, 0x144($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X144);
            goto L_806EE690;
    }
    goto skip_0;
    // 0x806EE66C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    skip_0:
    // 0x806EE670: lh          $t7, 0x144($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X144);
    // 0x806EE674: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4A74) << 16);
    // 0x806EE678: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806EE67C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x806EE680: lwc1        $f4, 0x9C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4A74));
    // 0x806EE684: jr          $ra
    // 0x806EE688: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x806EE688: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x806EE68C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
L_806EE690:
    // 0x806EE690: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4A74) << 16);
    // 0x806EE694: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806EE698: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x806EE69C: lwc1        $f6, 0x9C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4A74));
    // 0x806EE6A0: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x806EE6A4: jr          $ra
    // 0x806EE6A8: nop

    return;
    // 0x806EE6A8: nop

;}
RECOMP_FUNC void func_8046BD6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046BD6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046BD70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046BD74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8046BD78: jal         0x80047090
    // 0x8046BD7C: addiu       $a0, $zero, 0x4119
    ctx->r4 = ADD32(0, 0X4119);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8046BD7C: addiu       $a0, $zero, 0x4119
    ctx->r4 = ADD32(0, 0X4119);
    after_0:
    // 0x8046BD80: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8046BD84: beq         $v0, $at, L_8046BE14
    if (ctx->r2 == ctx->r1) {
        // 0x8046BD88: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8046BE14;
    }
    // 0x8046BD88: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8046BD8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8046BD90: lui         $at, 0x4119
    ctx->r1 = S32(0X4119 << 16);
    // 0x8046BD94: ori         $at, $at, 0x1000
    ctx->r1 = ctx->r1 | 0X1000;
    // 0x8046BD98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8046BD9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8046BDA0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8046BDA4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x8046BDA8: jal         0x8004613C
    // 0x8046BDAC: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8046BDAC: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x8046BDB0: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x8046BDB4: beq         $v0, $zero, L_8046BE0C
    if (ctx->r2 == 0) {
        // 0x8046BDB8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8046BE0C;
    }
    // 0x8046BDB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8046BDBC: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x8046BDC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8046BDC4: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x8046BDC8: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x8046BDCC: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8046BDD0: sh          $t0, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r8;
    // 0x8046BDD4: lw          $t1, 0x138($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X138);
    // 0x8046BDD8: sw          $t1, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r9;
    // 0x8046BDDC: jal         0x80047F9C
    // 0x8046BDE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8046BDE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8046BDE4: jal         0x8046B238
    // 0x8046BDE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8046B238(rdram, ctx);
        goto after_3;
    // 0x8046BDE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8046BDEC: bne         $v0, $zero, L_8046BDFC
    if (ctx->r2 != 0) {
        // 0x8046BDF0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8046BDFC;
    }
    // 0x8046BDF0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8046BDF4: b           L_8046BE18
    // 0x8046BDF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8046BE18;
    // 0x8046BDF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8046BDFC:
    // 0x8046BDFC: jal         0x8005FDC4
    // 0x8046BE00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x8046BE00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x8046BE04: b           L_8046BE18
    // 0x8046BE08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8046BE18;
    // 0x8046BE08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8046BE0C:
    // 0x8046BE0C: b           L_8046BE18
    // 0x8046BE10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8046BE18;
    // 0x8046BE10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8046BE14:
    // 0x8046BE14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8046BE18:
    // 0x8046BE18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046BE1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046BE20: jr          $ra
    // 0x8046BE24: nop

    return;
    // 0x8046BE24: nop

;}
RECOMP_FUNC void func_80453088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453088: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045308C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453090: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80453094: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80453098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045309C: jal         0x8045030C
    // 0x804530A0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8045030C(rdram, ctx);
        goto after_0;
    // 0x804530A0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x804530A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804530A8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804530AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804530B0: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x804530B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804530B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804530BC: lwc1        $f4, 0x6CE0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CE0);
    // 0x804530C0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804530C4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804530C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804530CC: swc1        $f8, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f8.u32l;
    // 0x804530D0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14110) << 16);
    // 0x804530D4: lwc1        $f10, -0x7B10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14110));
    // 0x804530D8: lwc1        $f16, 0x6CE0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6CE0);
    // 0x804530DC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x804530E0: nop

    // 0x804530E4: bc1fl       L_804530F8
    if (!c1cs) {
        // 0x804530E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804530F8;
    }
    goto skip_0;
    // 0x804530E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804530EC: jal         0x804529CC
    // 0x804530F0: nop

    func_804529CC(rdram, ctx);
        goto after_1;
    // 0x804530F0: nop

    after_1:
    // 0x804530F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804530F8:
    // 0x804530F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804530FC: jr          $ra
    // 0x80453100: nop

    return;
    // 0x80453100: nop

;}
RECOMP_FUNC void func_80057978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005797C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057980: jal         0x800578D4
    // 0x80057984: addiu       $a1, $zero, 0x4007
    ctx->r5 = ADD32(0, 0X4007);
    func_800578D4(rdram, ctx);
        goto after_0;
    // 0x80057984: addiu       $a1, $zero, 0x4007
    ctx->r5 = ADD32(0, 0X4007);
    after_0:
    // 0x80057988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005798C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80057990: jr          $ra
    // 0x80057994: nop

    return;
    // 0x80057994: nop

    // 0x80057998: nop

    // 0x8005799C: nop

;}
RECOMP_FUNC void func_80465A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465A10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80465A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80465A18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80465A1C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80465A20: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
    // 0x80465A24: jal         0x800653D8
    // 0x80465A28: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80465A28: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x80465A2C: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x80465A30: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80465A34: mfhi        $t8
    ctx->r24 = hi;
    // 0x80465A38: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80465A3C: nop

    // 0x80465A40: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80465A44: jal         0x800653D8
    // 0x80465A48: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x80465A48: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80465A4C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80465A50: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80465A54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80465A58: lwc1        $f6, 0xC8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC8);
    // 0x80465A5C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80465A60: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80465A64: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80465A68: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80465A6C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80465A70: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x80465A74: addiu       $v1, $v1, 0x1754
    ctx->r3 = ADD32(ctx->r3, 0X1754);
    // 0x80465A78: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80465A7C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x80465A80: nop

    // 0x80465A84: div         $zero, $v0, $t1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r9)));
    // 0x80465A88: bne         $t1, $zero, L_80465A94
    if (ctx->r9 != 0) {
        // 0x80465A8C: nop
    
            goto L_80465A94;
    }
    // 0x80465A8C: nop

    // 0x80465A90: break       7
    do_break(2152094352);
L_80465A94:
    // 0x80465A94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80465A98: bne         $t1, $at, L_80465AAC
    if (ctx->r9 != ctx->r1) {
        // 0x80465A9C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80465AAC;
    }
    // 0x80465A9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80465AA0: bne         $v0, $at, L_80465AAC
    if (ctx->r2 != ctx->r1) {
        // 0x80465AA4: nop
    
            goto L_80465AAC;
    }
    // 0x80465AA4: nop

    // 0x80465AA8: break       6
    do_break(2152094376);
L_80465AAC:
    // 0x80465AAC: mfhi        $t2
    ctx->r10 = hi;
    // 0x80465AB0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80465AB4: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80465AB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80465ABC: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80465AC0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80465AC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80465AC8: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80465ACC: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80465AD0: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x80465AD4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80465AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80465ADC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80465AE0: jr          $ra
    // 0x80465AE4: nop

    return;
    // 0x80465AE4: nop

;}
RECOMP_FUNC void func_80030104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030104: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80030108: lw          $v1, 0x1A4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1A4);
    // 0x8003010C: beq         $v1, $zero, L_80030118
    if (ctx->r3 == 0) {
        // 0x80030110: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80030118;
    }
    // 0x80030110: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80030114: sw          $t6, 0x1A4($v0)
    MEM_W(0X1A4, ctx->r2) = ctx->r14;
L_80030118:
    // 0x80030118: jr          $ra
    // 0x8003011C: nop

    return;
    // 0x8003011C: nop

;}
RECOMP_FUNC void func_806D8EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D8EF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D8EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D8F00: lh          $a3, 0x1F0($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X1F0);
    // 0x806D8F04: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806D8F08: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806D8F0C: bne         $a3, $at, L_806D8F78
    if (ctx->r7 != ctx->r1) {
        // 0x806D8F10: sll         $a1, $a3, 16
        ctx->r5 = S32(ctx->r7 << 16);
            goto L_806D8F78;
    }
    // 0x806D8F10: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x806D8F14: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x806D8F18: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806D8F1C: jal         0x80067BBC
    // 0x806D8F20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806D8F20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x806D8F24: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x806D8F28: jal         0x80067F78
    // 0x806D8F2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x806D8F2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806D8F30: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x806D8F34: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x806D8F38: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806D8F3C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x806D8F40: beq         $v0, $at, L_806D8FC0
    if (ctx->r2 == ctx->r1) {
        // 0x806D8F44: sh          $v0, 0x1F0($a2)
        MEM_H(0X1F0, ctx->r6) = ctx->r2;
            goto L_806D8FC0;
    }
    // 0x806D8F44: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
    // 0x806D8F48: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x806D8F4C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806D8F50: jal         0x80067BBC
    // 0x806D8F54: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806D8F54: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_2:
    // 0x806D8F58: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x806D8F5C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x806D8F60: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806D8F64: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x806D8F68: jal         0x80067838
    // 0x806D8F6C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067838(rdram, ctx);
        goto after_3;
    // 0x806D8F6C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x806D8F70: b           L_806D8FC4
    // 0x806D8F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D8FC4;
    // 0x806D8F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D8F78:
    // 0x806D8F78: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x806D8F7C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806D8F80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806D8F84: jal         0x80067930
    // 0x806D8F88: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_4;
    // 0x806D8F88: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_4:
    // 0x806D8F8C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x806D8F90: beq         $v0, $zero, L_806D8FC0
    if (ctx->r2 == 0) {
        // 0x806D8F94: lh          $a3, 0x1E($sp)
        ctx->r7 = MEM_H(ctx->r29, 0X1E);
            goto L_806D8FC0;
    }
    // 0x806D8F94: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x806D8F98: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x806D8F9C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806D8FA0: jal         0x80067BBC
    // 0x806D8FA4: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x806D8FA4: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    after_5:
    // 0x806D8FA8: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x806D8FAC: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x806D8FB0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806D8FB4: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x806D8FB8: jal         0x800678F0
    // 0x806D8FBC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_800678F0(rdram, ctx);
        goto after_6;
    // 0x806D8FBC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_6:
L_806D8FC0:
    // 0x806D8FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D8FC4:
    // 0x806D8FC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D8FC8: jr          $ra
    // 0x806D8FCC: nop

    return;
    // 0x806D8FCC: nop

;}
RECOMP_FUNC void func_8041E090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E090: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8041E094: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8041E098: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8041E09C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8041E0A0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8041E0A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8041E0A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8041E0AC: jal         0x8041E20C
    // 0x8041E0B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8041E20C(rdram, ctx);
        goto after_0;
    // 0x8041E0B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8041E0B4: beq         $v0, $zero, L_8041E1E4
    if (ctx->r2 == 0) {
        // 0x8041E0B8: nop
    
            goto L_8041E1E4;
    }
    // 0x8041E0B8: nop

    // 0x8041E0BC: lw          $t6, 0x1F4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X1F4);
    // 0x8041E0C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8041E0C4: jal         0x8041E408
    // 0x8041E0C8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    func_8041E408(rdram, ctx);
        goto after_1;
    // 0x8041E0C8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_1:
    // 0x8041E0CC: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34EC) << 16);
    // 0x8041E0D0: lwc1        $f2, 0xB4C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34EC));
    // 0x8041E0D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8041E0D8: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8041E0DC: lui         $t9, 0x8042
    ctx->r25 = S32(RELOC_HI16(29, 0X554) << 16);
    // 0x8041E0E0: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8041E0E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8041E0E8: addiu       $t9, $t9, -0x244C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(29, 0X554));
    // 0x8041E0EC: sw          $t7, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->r15;
    // 0x8041E0F0: sb          $t8, 0x165($s3)
    MEM_B(0X165, ctx->r19) = ctx->r24;
    // 0x8041E0F4: sw          $zero, 0x1E0($s3)
    MEM_W(0X1E0, ctx->r19) = 0;
    // 0x8041E0F8: sw          $t9, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->r25;
    // 0x8041E0FC: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34F0) << 16);
    // 0x8041E100: swc1        $f2, 0xC8($s3)
    MEM_W(0XC8, ctx->r19) = ctx->f2.u32l;
    // 0x8041E104: swc1        $f0, 0xE8($s3)
    MEM_W(0XE8, ctx->r19) = ctx->f0.u32l;
    // 0x8041E108: swc1        $f0, 0xDC($s3)
    MEM_W(0XDC, ctx->r19) = ctx->f0.u32l;
    // 0x8041E10C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8041E110: lwc1        $f4, 0xB50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34F0));
    // 0x8041E114: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X34F4) << 16);
    // 0x8041E118: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8041E11C: swc1        $f4, 0xE0($s3)
    MEM_W(0XE0, ctx->r19) = ctx->f4.u32l;
    // 0x8041E120: lwc1        $f8, 0xB54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X34F4));
    // 0x8041E124: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8041E128: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8041E12C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8041E130: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8041E134: swc1        $f10, 0xEC($s3)
    MEM_W(0XEC, ctx->r19) = ctx->f10.u32l;
    // 0x8041E138: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8041E13C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8041E140: swc1        $f0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f0.u32l;
    // 0x8041E144: lwc1        $f16, 0x6C($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X6C);
    // 0x8041E148: lwc1        $f8, 0x70($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X70);
    // 0x8041E14C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8041E150: nop

    // 0x8041E154: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8041E158: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8041E15C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8041E160: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8041E164: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8041E168: sh          $t2, 0x13C($s3)
    MEM_H(0X13C, ctx->r19) = ctx->r10;
    // 0x8041E16C: jal         0x8041DEAC
    // 0x8041E170: sh          $t4, 0x13E($s3)
    MEM_H(0X13E, ctx->r19) = ctx->r12;
    func_8041DEAC(rdram, ctx);
        goto after_2;
    // 0x8041E170: sh          $t4, 0x13E($s3)
    MEM_H(0X13E, ctx->r19) = ctx->r12;
    after_2:
    // 0x8041E174: lui         $s2, 0x8042
    ctx->r18 = S32(RELOC_HI16(29, 0X32E8) << 16);
    // 0x8041E178: lui         $s1, 0x8042
    ctx->r17 = S32(RELOC_HI16(29, 0X3290) << 16);
    // 0x8041E17C: lui         $s4, 0x8042
    ctx->r20 = S32(RELOC_HI16(29, 0X3298) << 16);
    // 0x8041E180: lw          $s0, 0x1F4($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X1F4);
    // 0x8041E184: addiu       $s4, $s4, 0x8F8
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(29, 0X3298));
    // 0x8041E188: addiu       $s1, $s1, 0x8F0
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(29, 0X3290));
    // 0x8041E18C: addiu       $s2, $s2, 0x948
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(29, 0X32E8));
L_8041E190:
    // 0x8041E190: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8041E194: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x8041E198: jal         0x8041FE5C
    // 0x8041E19C: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    func_8041FE5C(rdram, ctx);
        goto after_3;
    // 0x8041E19C: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x8041E1A0: bne         $s0, $zero, L_8041E1B8
    if (ctx->r16 != 0) {
        // 0x8041E1A4: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8041E1B8;
    }
    // 0x8041E1A4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8041E1A8: jal         0x800445A4
    // 0x8041E1AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8041E1AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x8041E1B0: b           L_8041E1F0
    // 0x8041E1B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8041E1F0;
    // 0x8041E1B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8041E1B8:
    // 0x8041E1B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8041E1BC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8041E1C0: bne         $s1, $s4, L_8041E190
    if (ctx->r17 != ctx->r20) {
        // 0x8041E1C4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8041E190;
    }
    // 0x8041E1C4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8041E1C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8041E1CC: jal         0x8041E430
    // 0x8041E1D0: lw          $a1, 0x1F4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1F4);
    func_8041E430(rdram, ctx);
        goto after_5;
    // 0x8041E1D0: lw          $a1, 0x1F4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1F4);
    after_5:
    // 0x8041E1D4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8041E1D8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8041E1DC: b           L_8041E1EC
    // 0x8041E1E0: sh          $t5, 0x30($t6)
    MEM_H(0X30, ctx->r14) = ctx->r13;
        goto L_8041E1EC;
    // 0x8041E1E0: sh          $t5, 0x30($t6)
    MEM_H(0X30, ctx->r14) = ctx->r13;
L_8041E1E4:
    // 0x8041E1E4: jal         0x800445A4
    // 0x8041E1E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x8041E1E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
L_8041E1EC:
    // 0x8041E1EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8041E1F0:
    // 0x8041E1F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041E1F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8041E1F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8041E1FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8041E200: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8041E204: jr          $ra
    // 0x8041E208: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8041E208: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_804752A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804752A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804752A4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804752A8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804752AC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804752B0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804752B4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804752B8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804752BC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804752C0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804752C4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804752C8: jr          $ra
    // 0x804752CC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804752CC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806F5954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5954: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x806F5958: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x806F595C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x806F5960: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x806F5964: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x806F5968: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x806F596C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x806F5970: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x806F5974: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x806F5978: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x806F597C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F5980: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x806F5984: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806F5988: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806F598C: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(685, 0X288) << 16);
    // 0x806F5990: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806F5994: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x806F5998: addiu       $t7, $t7, 0x55E8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(685, 0X288));
    // 0x806F599C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x806F59A0: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806F59A4: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x806F59A8: lwc1        $f8, 0x88($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806F59AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x806F59B0: addiu       $s2, $sp, 0x84
    ctx->r18 = ADD32(ctx->r29, 0X84);
    // 0x806F59B4: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806F59B8: addiu       $v1, $sp, 0x96
    ctx->r3 = ADD32(ctx->r29, 0X96);
    // 0x806F59BC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x806F59C0: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
L_806F59C4:
    // 0x806F59C4: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x806F59C8: sltu        $at, $s2, $v1
    ctx->r1 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x806F59CC: bne         $at, $zero, L_806F59C4
    if (ctx->r1 != 0) {
        // 0x806F59D0: sh          $v0, -0x2($s2)
        MEM_H(-0X2, ctx->r18) = ctx->r2;
            goto L_806F59C4;
    }
    // 0x806F59D0: sh          $v0, -0x2($s2)
    MEM_H(-0X2, ctx->r18) = ctx->r2;
    // 0x806F59D4: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x806F59D8: sw          $a1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r5;
    // 0x806F59DC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806F59E0: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x806F59E4: nop

    // 0x806F59E8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806F59EC: jal         0x8006A99C
    // 0x806F59F0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x806F59F0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x806F59F4: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x806F59F8: sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // 0x806F59FC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806F5A00: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x806F5A04: nop

    // 0x806F5A08: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x806F5A0C: jal         0x8006A99C
    // 0x806F5A10: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x806F5A10: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x806F5A14: sll         $fp, $v0, 16
    ctx->r30 = S32(ctx->r2 << 16);
    // 0x806F5A18: sra         $fp, $fp, 16
    ctx->r30 = S32(SIGNED(ctx->r30) >> 16);
    // 0x806F5A1C: or          $s5, $fp, $zero
    ctx->r21 = ctx->r30 | 0;
    // 0x806F5A20: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x806F5A24: addiu       $s2, $sp, 0x84
    ctx->r18 = ADD32(ctx->r29, 0X84);
    // 0x806F5A28: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_806F5A2C:
    // 0x806F5A2C: sll         $s3, $s5, 16
    ctx->r19 = S32(ctx->r21 << 16);
    // 0x806F5A30: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x806F5A34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x806F5A38: lh          $s1, 0x82($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X82);
L_806F5A3C:
    // 0x806F5A3C: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x806F5A40: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x806F5A44: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806F5A48: jal         0x8006ABF0
    // 0x806F5A4C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006ABF0(rdram, ctx);
        goto after_2;
    // 0x806F5A4C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_2:
    // 0x806F5A50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806F5A54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x806F5A58: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x806F5A5C: bne         $s0, $s4, L_806F5A3C
    if (ctx->r16 != ctx->r20) {
        // 0x806F5A60: sh          $v0, -0x2($s2)
        MEM_H(-0X2, ctx->r18) = ctx->r2;
            goto L_806F5A3C;
    }
    // 0x806F5A60: sh          $v0, -0x2($s2)
    MEM_H(-0X2, ctx->r18) = ctx->r2;
    // 0x806F5A64: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x806F5A68: slti        $at, $s7, 0x3
    ctx->r1 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // 0x806F5A6C: bne         $at, $zero, L_806F5A2C
    if (ctx->r1 != 0) {
        // 0x806F5A70: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_806F5A2C;
    }
    // 0x806F5A70: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x806F5A74: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x806F5A78: addiu       $s2, $sp, 0x84
    ctx->r18 = ADD32(ctx->r29, 0X84);
    // 0x806F5A7C: addiu       $s6, $zero, 0x5800
    ctx->r22 = ADD32(0, 0X5800);
    // 0x806F5A80: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // 0x806F5A84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_806F5A88:
    // 0x806F5A88: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x806F5A8C: lh          $t0, 0x82($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X82);
    // 0x806F5A90: addu        $s3, $fp, $s7
    ctx->r19 = ADD32(ctx->r30, ctx->r23);
    // 0x806F5A94: beq         $s5, $v1, L_806F5AC8
    if (ctx->r21 == ctx->r3) {
        // 0x806F5A98: andi        $v0, $v1, 0xF800
        ctx->r2 = ctx->r3 & 0XF800;
            goto L_806F5AC8;
    }
    // 0x806F5A98: andi        $v0, $v1, 0xF800
    ctx->r2 = ctx->r3 & 0XF800;
    // 0x806F5A9C: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x806F5AA0: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x806F5AA4: bne         $s6, $v0, L_806F5AB0
    if (ctx->r22 != ctx->r2) {
        // 0x806F5AA8: addu        $s1, $t0, $s0
        ctx->r17 = ADD32(ctx->r8, ctx->r16);
            goto L_806F5AB0;
    }
    // 0x806F5AA8: addu        $s1, $t0, $s0
    ctx->r17 = ADD32(ctx->r8, ctx->r16);
    // 0x806F5AAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F5AB0:
    // 0x806F5AB0: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x806F5AB4: sll         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19 << 16);
    // 0x806F5AB8: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x806F5ABC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x806F5AC0: jal         0x8006B1C8
    // 0x806F5AC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006B1C8(rdram, ctx);
        goto after_3;
    // 0x806F5AC4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_3:
L_806F5AC8:
    // 0x806F5AC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x806F5ACC: bne         $s0, $s4, L_806F5A88
    if (ctx->r16 != ctx->r20) {
        // 0x806F5AD0: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_806F5A88;
    }
    // 0x806F5AD0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x806F5AD4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x806F5AD8: slti        $at, $s7, 0x3
    ctx->r1 = SIGNED(ctx->r23) < 0X3 ? 1 : 0;
    // 0x806F5ADC: bnel        $at, $zero, L_806F5A88
    if (ctx->r1 != 0) {
        // 0x806F5AE0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_806F5A88;
    }
    goto skip_0;
    // 0x806F5AE0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x806F5AE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F5AE8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806F5AEC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806F5AF0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(685, 0X11E0) << 16);
    // 0x806F5AF4: lwc1        $f8, 0x6540($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(685, 0X11E0));
    // 0x806F5AF8: lui         $s1, 0x806F
    ctx->r17 = S32(RELOC_HI16(685, 0X11C0) << 16);
    // 0x806F5AFC: lui         $s0, 0x806F
    ctx->r16 = S32(RELOC_HI16(685, 0X11D0) << 16);
    // 0x806F5B00: lui         $s4, 0x806F
    ctx->r20 = S32(RELOC_HI16(685, 0X11E0) << 16);
    // 0x806F5B04: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x806F5B08: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x806F5B0C: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x806F5B10: addiu       $s4, $s4, 0x6540
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(685, 0X11E0));
    // 0x806F5B14: addiu       $s0, $s0, 0x6530
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(685, 0X11D0));
    // 0x806F5B18: addiu       $s1, $s1, 0x6520
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(685, 0X11C0));
    // 0x806F5B1C: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
    // 0x806F5B20: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x806F5B24: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x806F5B28: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x806F5B2C: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x806F5B30: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x806F5B34: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x806F5B38: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
L_806F5B3C:
    // 0x806F5B3C: lw          $v0, 0xB0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB0);
    // 0x806F5B40: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x806F5B44: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806F5B48: lwc1        $f16, 0x84($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806F5B4C: lw          $t1, 0xA68($s3)
    ctx->r9 = MEM_W(ctx->r19, 0XA68);
    // 0x806F5B50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x806F5B54: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806F5B58: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x806F5B5C: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    // 0x806F5B60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F5B64: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x806F5B68: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x806F5B6C: lw          $t9, 0x28($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X28);
    // 0x806F5B70: jalr        $t9
    // 0x806F5B74: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x806F5B74: nop

    after_4:
    // 0x806F5B78: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806F5B7C: bne         $s0, $s4, L_806F5B3C
    if (ctx->r16 != ctx->r20) {
        // 0x806F5B80: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_806F5B3C;
    }
    // 0x806F5B80: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806F5B84: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x806F5B88: jal         0x806F5420
    // 0x806F5B8C: addiu       $a1, $zero, 0x223
    ctx->r5 = ADD32(0, 0X223);
    func_806F5420(rdram, ctx);
        goto after_5;
    // 0x806F5B8C: addiu       $a1, $zero, 0x223
    ctx->r5 = ADD32(0, 0X223);
    after_5:
    // 0x806F5B90: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x806F5B94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F5B98: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806F5B9C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806F5BA0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x806F5BA4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x806F5BA8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x806F5BAC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x806F5BB0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x806F5BB4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x806F5BB8: jr          $ra
    // 0x806F5BBC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x806F5BBC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8067E734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067E738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067E73C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8067E740: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(544, 0X1148) << 16);
    // 0x8067E744: addiu       $t6, $t6, -0xFF8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(544, 0X1148));
    // 0x8067E748: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8067E74C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8067E750: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8067E754: sw          $zero, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = 0;
    // 0x8067E758: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067E75C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8067E760: jal         0x8067EAE0
    // 0x8067E764: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8067EAE0(rdram, ctx);
        goto after_0;
    // 0x8067E764: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8067E768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067E76C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8067E770: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8067E774: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8067E778: jr          $ra
    // 0x8067E77C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8067E77C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806994D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806994D0: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(562, 0X10) << 16);
    // 0x806994D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x806994D8: jr          $ra
    // 0x806994DC: addiu       $v0, $v0, -0x6B20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(562, 0X10));
    return;
    // 0x806994DC: addiu       $v0, $v0, -0x6B20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(562, 0X10));
;}
RECOMP_FUNC void func_806800FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806800FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80680100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80680108: jal         0x80045A34
    // 0x8068010C: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8068010C: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    after_0:
    // 0x80680110: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80680114: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(547, 0X10A8) << 16);
    // 0x80680118: bne         $v0, $zero, L_80680130
    if (ctx->r2 != 0) {
        // 0x8068011C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80680130;
    }
    // 0x8068011C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80680120: jal         0x800445A4
    // 0x80680124: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80680124: nop

    after_1:
    // 0x80680128: b           L_80680188
    // 0x8068012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80680188;
    // 0x8068012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80680130:
    // 0x80680130: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80680134: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80680138: addiu       $t6, $t6, 0x298
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(547, 0X10A8));
    // 0x8068013C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80680140: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680144: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80680148: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8068014C: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x80680150: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80680154: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
    // 0x80680158: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8068015C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80680160: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80680164: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80680168: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8068016C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80680170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80680174: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80680178: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8068017C: jal         0x80680194
    // 0x80680180: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    func_80680194(rdram, ctx);
        goto after_2;
    // 0x80680180: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    after_2:
    // 0x80680184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80680188:
    // 0x80680188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8068018C: jr          $ra
    // 0x80680190: nop

    return;
    // 0x80680190: nop

;}
RECOMP_FUNC void func_805CC3C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CC3C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805CC3CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CC3D0: lw          $v1, 0x1E4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E4);
    // 0x805CC3D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805CC3D8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805CC3DC: beq         $v1, $zero, L_805CC458
    if (ctx->r3 == 0) {
        // 0x805CC3E0: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_805CC458;
    }
    // 0x805CC3E0: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x805CC3E4: sw          $t6, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = ctx->r14;
    // 0x805CC3E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x805CC3EC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805CC3F0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x805CC3F4: beq         $a0, $zero, L_805CC404
    if (ctx->r4 == 0) {
        // 0x805CC3F8: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_805CC404;
    }
    // 0x805CC3F8: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x805CC3FC: b           L_805CC460
    // 0x805CC400: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_805CC460;
    // 0x805CC400: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_805CC404:
    // 0x805CC404: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805CC408: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805CC40C: lwc1        $f4, 0x6C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X6C);
    // 0x805CC410: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x805CC414: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x805CC418: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x805CC41C: addiu       $a0, $a3, 0x3C
    ctx->r4 = ADD32(ctx->r7, 0X3C);
    // 0x805CC420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805CC424: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805CC428: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x805CC42C: lwc1        $f8, 0x70($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X70);
    // 0x805CC430: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x805CC434: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x805CC438: lwc1        $f16, 0x74($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X74);
    // 0x805CC43C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x805CC440: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x805CC444: lw          $t9, 0x4C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4C);
    // 0x805CC448: jalr        $t9
    // 0x805CC44C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805CC44C: nop

    after_0:
    // 0x805CC450: b           L_805CC464
    // 0x805CC454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805CC464;
    // 0x805CC454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CC458:
    // 0x805CC458: jal         0x800447C8
    // 0x805CC45C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x805CC45C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
L_805CC460:
    // 0x805CC460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CC464:
    // 0x805CC464: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805CC468: jr          $ra
    // 0x805CC46C: nop

    return;
    // 0x805CC46C: nop

;}
RECOMP_FUNC void func_800614CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800614CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800614D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800614D4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800614D8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800614DC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800614E0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800614E4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800614E8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800614EC: lw          $s3, 0x4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X4);
    // 0x800614F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800614F4: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800614F8: lh          $s1, 0x184($s3)
    ctx->r17 = MEM_H(ctx->r19, 0X184);
    // 0x800614FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80061500: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80061504: addiu       $s2, $s3, 0x188
    ctx->r18 = ADD32(ctx->r19, 0X188);
    // 0x80061508: beq         $s1, $zero, L_800615B0
    if (ctx->r17 == 0) {
        // 0x8006150C: swc1        $f8, 0x30($a0)
        MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
            goto L_800615B0;
    }
    // 0x8006150C: swc1        $f8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f8.u32l;
    // 0x80061510: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80061514: nop

L_80061518:
    // 0x80061518: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8006151C: beq         $v0, $zero, L_800615A8
    if (ctx->r2 == 0) {
        // 0x80061520: nop
    
            goto L_800615A8;
    }
    // 0x80061520: nop

    // 0x80061524: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80061528: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x8006152C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80061530: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80061534: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80061538: beq         $t6, $zero, L_800615A8
    if (ctx->r14 == 0) {
        // 0x8006153C: sw          $t6, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r14;
            goto L_800615A8;
    }
    // 0x8006153C: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    // 0x80061540: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80061544: bne         $s3, $t7, L_800615A8
    if (ctx->r19 != ctx->r15) {
        // 0x80061548: nop
    
            goto L_800615A8;
    }
    // 0x80061548: nop

    // 0x8006154C: lwc1        $f10, 0xC8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80061550: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
    // 0x80061554: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80061558: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8006155C: nop

    // 0x80061560: bc1fl       L_80061580
    if (!c1cs) {
        // 0x80061564: lw          $t8, 0x40($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X40);
            goto L_80061580;
    }
    goto skip_0;
    // 0x80061564: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    skip_0:
    // 0x80061568: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006156C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80061570: nop

    // 0x80061574: bc1t        L_800615A0
    if (c1cs) {
        // 0x80061578: nop
    
            goto L_800615A0;
    }
    // 0x80061578: nop

    // 0x8006157C: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
L_80061580:
    // 0x80061580: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80061584: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x80061588: bne         $t0, $zero, L_800615A0
    if (ctx->r8 != 0) {
        // 0x8006158C: nop
    
            goto L_800615A0;
    }
    // 0x8006158C: nop

    // 0x80061590: jal         0x80060960
    // 0x80061594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060960(rdram, ctx);
        goto after_0;
    // 0x80061594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80061598: bne         $v0, $zero, L_800615A8
    if (ctx->r2 != 0) {
        // 0x8006159C: nop
    
            goto L_800615A8;
    }
    // 0x8006159C: nop

L_800615A0:
    // 0x800615A0: jal         0x80060F6C
    // 0x800615A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060F6C(rdram, ctx);
        goto after_1;
    // 0x800615A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_800615A8:
    // 0x800615A8: bne         $s1, $zero, L_80061518
    if (ctx->r17 != 0) {
        // 0x800615AC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80061518;
    }
    // 0x800615AC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800615B0:
    // 0x800615B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800615B4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800615B8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800615BC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800615C0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800615C4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800615C8: jr          $ra
    // 0x800615CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800615CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_807B4D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4D4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B4D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B4D54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807B4D58: jal         0x807B4A10
    // 0x807B4D5C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_807B4A10(rdram, ctx);
        goto after_0;
    // 0x807B4D5C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x807B4D60: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(880, 0X2C90) << 16);
    // 0x807B4D64: addiu       $a1, $a1, 0x7490
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(880, 0X2C90));
    // 0x807B4D68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B4D6C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x807B4D70: jal         0x807B4900
    // 0x807B4D74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B4900(rdram, ctx);
        goto after_1;
    // 0x807B4D74: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807B4D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B4D7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B4D80: jr          $ra
    // 0x807B4D84: nop

    return;
    // 0x807B4D84: nop

;}
RECOMP_FUNC void func_806E7B70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7B70: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806E7B74: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x806E7B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E7B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E7B80: bne         $t6, $zero, L_806E7C58
    if (ctx->r14 != 0) {
        // 0x806E7B84: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806E7C58;
    }
    // 0x806E7B84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806E7B88: lhu         $t7, 0xC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XC);
    // 0x806E7B8C: addiu       $at, $zero, 0x466C
    ctx->r1 = ADD32(0, 0X466C);
    // 0x806E7B90: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x806E7B94: bne         $t7, $at, L_806E7C58
    if (ctx->r15 != ctx->r1) {
        // 0x806E7B98: nop
    
            goto L_806E7C58;
    }
    // 0x806E7B98: nop

    // 0x806E7B9C: jal         0x806E7E4C
    // 0x806E7BA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806E7E4C(rdram, ctx);
        goto after_0;
    // 0x806E7BA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806E7BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E7BA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E7BAC: jal         0x8005FD1C
    // 0x806E7BB0: sb          $a1, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r5;
    func_8005FD1C(rdram, ctx);
        goto after_1;
    // 0x806E7BB0: sb          $a1, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r5;
    after_1:
    // 0x806E7BB4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806E7BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E7BBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806E7BC0: lw          $t8, 0x174($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X174);
    // 0x806E7BC4: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x806E7BC8: addiu       $a0, $zero, 0x4027
    ctx->r4 = ADD32(0, 0X4027);
    // 0x806E7BCC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x806E7BD0: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
L_806E7BD4:
    // 0x806E7BD4: lw          $v0, 0x188($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X188);
    // 0x806E7BD8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x806E7BDC: beql        $v0, $zero, L_806E7BF8
    if (ctx->r2 == 0) {
        // 0x806E7BE0: lw          $v0, 0x18C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X18C);
            goto L_806E7BF8;
    }
    goto skip_0;
    // 0x806E7BE0: lw          $v0, 0x18C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18C);
    skip_0:
    // 0x806E7BE4: lhu         $t0, 0xC($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7BE8: bnel        $a0, $t0, L_806E7BF8
    if (ctx->r4 != ctx->r8) {
        // 0x806E7BEC: lw          $v0, 0x18C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X18C);
            goto L_806E7BF8;
    }
    goto skip_1;
    // 0x806E7BEC: lw          $v0, 0x18C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18C);
    skip_1:
    // 0x806E7BF0: sb          $a1, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r5;
    // 0x806E7BF4: lw          $v0, 0x18C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18C);
L_806E7BF8:
    // 0x806E7BF8: beql        $v0, $zero, L_806E7C14
    if (ctx->r2 == 0) {
        // 0x806E7BFC: lw          $v0, 0x190($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X190);
            goto L_806E7C14;
    }
    goto skip_2;
    // 0x806E7BFC: lw          $v0, 0x190($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X190);
    skip_2:
    // 0x806E7C00: lhu         $t1, 0xC($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7C04: bnel        $a0, $t1, L_806E7C14
    if (ctx->r4 != ctx->r9) {
        // 0x806E7C08: lw          $v0, 0x190($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X190);
            goto L_806E7C14;
    }
    goto skip_3;
    // 0x806E7C08: lw          $v0, 0x190($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X190);
    skip_3:
    // 0x806E7C0C: sb          $a1, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r5;
    // 0x806E7C10: lw          $v0, 0x190($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X190);
L_806E7C14:
    // 0x806E7C14: beql        $v0, $zero, L_806E7C30
    if (ctx->r2 == 0) {
        // 0x806E7C18: lw          $v0, 0x194($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X194);
            goto L_806E7C30;
    }
    goto skip_4;
    // 0x806E7C18: lw          $v0, 0x194($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X194);
    skip_4:
    // 0x806E7C1C: lhu         $t2, 0xC($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7C20: bnel        $a0, $t2, L_806E7C30
    if (ctx->r4 != ctx->r10) {
        // 0x806E7C24: lw          $v0, 0x194($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X194);
            goto L_806E7C30;
    }
    goto skip_5;
    // 0x806E7C24: lw          $v0, 0x194($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X194);
    skip_5:
    // 0x806E7C28: sb          $a1, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r5;
    // 0x806E7C2C: lw          $v0, 0x194($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X194);
L_806E7C30:
    // 0x806E7C30: beq         $v0, $zero, L_806E7C48
    if (ctx->r2 == 0) {
        // 0x806E7C34: nop
    
            goto L_806E7C48;
    }
    // 0x806E7C34: nop

    // 0x806E7C38: lhu         $t3, 0xC($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7C3C: bne         $a0, $t3, L_806E7C48
    if (ctx->r4 != ctx->r11) {
        // 0x806E7C40: nop
    
            goto L_806E7C48;
    }
    // 0x806E7C40: nop

    // 0x806E7C44: sb          $a1, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r5;
L_806E7C48:
    // 0x806E7C48: bne         $a2, $a3, L_806E7BD4
    if (ctx->r6 != ctx->r7) {
        // 0x806E7C4C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_806E7BD4;
    }
    // 0x806E7C4C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x806E7C50: b           L_806E7C58
    // 0x806E7C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806E7C58;
    // 0x806E7C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806E7C58:
    // 0x806E7C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E7C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E7C60: jr          $ra
    // 0x806E7C64: nop

    return;
    // 0x806E7C64: nop

;}
RECOMP_FUNC void func_80462680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80462684: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80462688: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8046268C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80462690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80462694: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80462698: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8046269C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804626A0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804626A4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804626A8: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(122, 0X3840) << 16);
    // 0x804626AC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804626B0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804626B4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804626B8: lw          $t2, 0x3DD0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(122, 0X3840));
    // 0x804626BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804626C0: jal         0x80462454
    // 0x804626C4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_80462454(rdram, ctx);
        goto after_0;
    // 0x804626C4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804626C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804626CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804626D0: jr          $ra
    // 0x804626D4: nop

    return;
    // 0x804626D4: nop

;}
RECOMP_FUNC void func_8002CE9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CE9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002CEA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CEA4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CEA8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002CEAC: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002CEB0: addiu       $a1, $a1, -0x3578
    ctx->r5 = ADD32(ctx->r5, -0X3578);
    // 0x8002CEB4: addiu       $t7, $t7, 0x1D88
    ctx->r15 = ADD32(ctx->r15, 0X1D88);
    // 0x8002CEB8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002CEBC: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8002CEC0: jal         0x80028118
    // 0x8002CEC4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002CEC4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002CEC8: jal         0x8002DAF0
    // 0x8002CECC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8002DAF0(rdram, ctx);
        goto after_1;
    // 0x8002CECC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002CED0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CED4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002CED8: sb          $t8, 0x1AC($t9)
    MEM_B(0X1AC, ctx->r25) = ctx->r24;
    // 0x8002CEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CEE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002CEE4: jr          $ra
    // 0x8002CEE8: nop

    return;
    // 0x8002CEE8: nop

;}
RECOMP_FUNC void func_80777488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80777488: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8077748C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80777490: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80777494: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80777498: lui         $a0, 0x8077
    ctx->r4 = S32(RELOC_HI16(775, 0X5C0) << 16);
    // 0x8077749C: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x807774A0: lui         $a1, 0x4651
    ctx->r5 = S32(0X4651 << 16);
    // 0x807774A4: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x807774A8: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x807774AC: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x807774B0: addiu       $a0, $a0, 0x79D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(775, 0X5C0));
    // 0x807774B4: jal         0x80046804
    // 0x807774B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x807774B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x807774BC: bne         $v0, $zero, L_807774CC
    if (ctx->r2 != 0) {
        // 0x807774C0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807774CC;
    }
    // 0x807774C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807774C4: b           L_807774F8
    // 0x807774C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807774F8;
    // 0x807774C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807774CC:
    // 0x807774CC: addiu       $a0, $zero, 0x4651
    ctx->r4 = ADD32(0, 0X4651);
    // 0x807774D0: jal         0x80047090
    // 0x807774D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x807774D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x807774D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x807774DC: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x807774E0: lhu         $t9, 0xE($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XE);
    // 0x807774E4: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x807774E8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x807774EC: jal         0x80044194
    // 0x807774F0: sh          $t1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x807774F0: sh          $t1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r9;
    after_2:
    // 0x807774F4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_807774F8:
    // 0x807774F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807774FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80777500: jr          $ra
    // 0x80777504: nop

    return;
    // 0x80777504: nop

;}
RECOMP_FUNC void func_8066B970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066B974: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8066B978: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8066B97C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8066B980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066B984: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8066B988: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8066B98C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8066B990: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8066B994: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8066B998: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8066B99C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8066B9A0: lui         $t2, 0x8067
    ctx->r10 = S32(RELOC_HI16(514, 0X2698) << 16);
    // 0x8066B9A4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8066B9A8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8066B9AC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8066B9B0: lw          $t2, -0x2D08($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(514, 0X2698));
    // 0x8066B9B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8066B9B8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8066B9BC: jal         0x8066ACCC
    // 0x8066B9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8066ACCC(rdram, ctx);
        goto after_0;
    // 0x8066B9C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066B9C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8066B9C8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B9CC: beql        $v1, $zero, L_8066B9E4
    if (ctx->r3 == 0) {
        // 0x8066B9D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8066B9E4;
    }
    goto skip_0;
    // 0x8066B9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8066B9D4: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8066B9D8: jal         0x8066AD88
    // 0x8066B9DC: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    func_8066AD88(rdram, ctx);
        goto after_1;
    // 0x8066B9DC: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    after_1:
    // 0x8066B9E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8066B9E4:
    // 0x8066B9E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066B9E8: jr          $ra
    // 0x8066B9EC: nop

    return;
    // 0x8066B9EC: nop

;}
RECOMP_FUNC void func_8001C300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001C304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C308: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001C30C: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001C310: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8001C314: lw          $t8, -0x7D6C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D6C);
    // 0x8001C318: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8001C31C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001C320: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001C324: lwc1        $f4, 0x10($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8001C328: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x8001C32C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8001C330: nop

    // 0x8001C334: bc1fl       L_8001C370
    if (!c1cs) {
        // 0x8001C338: lbu         $v0, 0x10($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X10);
            goto L_8001C370;
    }
    goto skip_0;
    // 0x8001C338: lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X10);
    skip_0:
    // 0x8001C33C: jal         0x8006CAE0
    // 0x8001C340: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8006CAE0(rdram, ctx);
        goto after_0;
    // 0x8001C340: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001C344: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8001C348: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001C34C: jal         0x8006C9DC
    // 0x8001C350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8006C9DC(rdram, ctx);
        goto after_1;
    // 0x8001C350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8001C354: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001C358: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001C35C: jal         0x8006CA74
    // 0x8001C360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8006CA74(rdram, ctx);
        goto after_2;
    // 0x8001C360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8001C364: b           L_8001C3D4
    // 0x8001C368: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
        goto L_8001C3D4;
    // 0x8001C368: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C36C: lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X10);
L_8001C370:
    // 0x8001C370: addiu       $a0, $zero, 0x265
    ctx->r4 = ADD32(0, 0X265);
    // 0x8001C374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001C378: bnel        $v0, $zero, L_8001C394
    if (ctx->r2 != 0) {
        // 0x8001C37C: slti        $at, $v0, 0xFB
        ctx->r1 = SIGNED(ctx->r2) < 0XFB ? 1 : 0;
            goto L_8001C394;
    }
    goto skip_1;
    // 0x8001C37C: slti        $at, $v0, 0xFB
    ctx->r1 = SIGNED(ctx->r2) < 0XFB ? 1 : 0;
    skip_1:
    // 0x8001C380: jal         0x80067818
    // 0x8001C384: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8001C384: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_3:
    // 0x8001C388: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8001C38C: lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X10);
    // 0x8001C390: slti        $at, $v0, 0xFB
    ctx->r1 = SIGNED(ctx->r2) < 0XFB ? 1 : 0;
L_8001C394:
    // 0x8001C394: beq         $at, $zero, L_8001C3A8
    if (ctx->r1 == 0) {
        // 0x8001C398: addiu       $t0, $zero, 0x8
        ctx->r8 = ADD32(0, 0X8);
            goto L_8001C3A8;
    }
    // 0x8001C398: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8001C39C: addiu       $t9, $v0, 0x4
    ctx->r25 = ADD32(ctx->r2, 0X4);
    // 0x8001C3A0: b           L_8001C3D0
    // 0x8001C3A4: sb          $t9, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r25;
        goto L_8001C3D0;
    // 0x8001C3A4: sb          $t9, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r25;
L_8001C3A8:
    // 0x8001C3A8: sb          $t0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r8;
    // 0x8001C3AC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8001C3B0: jal         0x8006CAE0
    // 0x8001C3B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8006CAE0(rdram, ctx);
        goto after_4;
    // 0x8001C3B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8001C3B8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8001C3BC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8001C3C0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001C3C4: sb          $t1, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r9;
    // 0x8001C3C8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C3CC: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
L_8001C3D0:
    // 0x8001C3D0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
L_8001C3D4:
    // 0x8001C3D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001C3D8: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8001C3DC: jalr        $t9
    // 0x8001C3E0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8001C3E0: nop

    after_5:
    // 0x8001C3E4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C3E8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8001C3EC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001C3F0: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8001C3F4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8001C3F8: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8001C3FC: lw          $t8, -0x69C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X69C0);
    // 0x8001C400: sw          $t8, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r24;
    // 0x8001C404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C408: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001C40C: jr          $ra
    // 0x8001C410: nop

    return;
    // 0x8001C410: nop

;}
RECOMP_FUNC void func_80581338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8058133C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581340: jal         0x8058129C
    // 0x80581344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8058129C(rdram, ctx);
        goto after_0;
    // 0x80581344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80581348: bne         $v0, $zero, L_80581364
    if (ctx->r2 != 0) {
        // 0x8058134C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80581364;
    }
    // 0x8058134C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80581350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80581354: jal         0x805814C4
    // 0x80581358: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_805814C4(rdram, ctx);
        goto after_1;
    // 0x80581358: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x8058135C: b           L_805813A8
    // 0x80581360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805813A8;
    // 0x80581360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80581364:
    // 0x80581364: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80581368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8058136C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80581370: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80581374: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80581378: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8058137C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80581380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80581384: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80581388: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8058138C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80581390: nop

    // 0x80581394: bc1fl       L_805813A8
    if (!c1cs) {
        // 0x80581398: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805813A8;
    }
    goto skip_0;
    // 0x80581398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8058139C: jal         0x805814C4
    // 0x805813A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_805814C4(rdram, ctx);
        goto after_2;
    // 0x805813A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x805813A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805813A8:
    // 0x805813A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805813AC: jr          $ra
    // 0x805813B0: nop

    return;
    // 0x805813B0: nop

;}
RECOMP_FUNC void func_80447A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447A30: jr          $ra
    // 0x80447A34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80447A34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8067F200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067F200: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8067F204: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8067F208: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8067F20C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8067F210: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8067F214: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8067F218: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8067F21C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8067F220: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8067F224: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8067F228: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067F22C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8067F230: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8067F234: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8067F238: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8067F23C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8067F240: jal         0x8004921C
    // 0x8067F244: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8067F244: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    after_0:
    // 0x8067F248: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8067F24C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067F250: jal         0x8004921C
    // 0x8067F254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8067F254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8067F258: lw          $a3, 0x168($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X168);
    // 0x8067F25C: addiu       $s4, $sp, 0xB0
    ctx->r20 = ADD32(ctx->r29, 0XB0);
    // 0x8067F260: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8067F264: lw          $t8, 0x80($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X80);
    // 0x8067F268: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8067F26C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8067F270: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x8067F274: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8067F278: lw          $s1, 0x88($a3)
    ctx->r17 = MEM_W(ctx->r7, 0X88);
    // 0x8067F27C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8067F280: jal         0x80077338
    // 0x8067F284: sw          $v1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r3;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x8067F284: sw          $v1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8067F288: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F28C: lw          $v1, 0x9C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X9C);
    // 0x8067F290: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8067F294: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8067F298: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x8067F29C: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x8067F2A0: ori         $t8, $t8, 0xACB0
    ctx->r24 = ctx->r24 | 0XACB0;
    // 0x8067F2A4: ori         $t7, $t7, 0x18
    ctx->r15 = ctx->r15 | 0X18;
    // 0x8067F2A8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8067F2AC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8067F2B0: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F2B4: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8067F2B8: lui         $a2, 0x55
    ctx->r6 = S32(0X55 << 16);
    // 0x8067F2BC: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8067F2C0: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x8067F2C4: ori         $a2, $a2, 0x3048
    ctx->r6 = ctx->r6 | 0X3048;
    // 0x8067F2C8: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x8067F2CC: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8067F2D0: sw          $a2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r6;
    // 0x8067F2D4: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F2D8: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x8067F2DC: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x8067F2E0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8067F2E4: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x8067F2E8: sw          $a2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r6;
    // 0x8067F2EC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8067F2F0: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F2F4: lui         $t9, 0xFC12
    ctx->r25 = S32(0XFC12 << 16);
    // 0x8067F2F8: ori         $t9, $t9, 0x7E24
    ctx->r25 = ctx->r25 | 0X7E24;
    // 0x8067F2FC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8067F300: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x8067F304: addiu       $t6, $zero, -0xC07
    ctx->r14 = ADD32(0, -0XC07);
    // 0x8067F308: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8067F30C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8067F310: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F314: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x8067F318: addiu       $t6, $zero, 0x204
    ctx->r14 = ADD32(0, 0X204);
    // 0x8067F31C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8067F320: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x8067F324: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8067F328: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8067F32C: lbu         $a1, 0x1C($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1C);
    // 0x8067F330: lbu         $a2, 0x1D($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1D);
    // 0x8067F334: lbu         $a3, 0x1E($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X1E);
    // 0x8067F338: lbu         $v0, 0x20($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X20);
    // 0x8067F33C: lbu         $t0, 0x21($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X21);
    // 0x8067F340: lbu         $t1, 0x22($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X22);
    // 0x8067F344: sb          $a1, 0x34($v1)
    MEM_B(0X34, ctx->r3) = ctx->r5;
    // 0x8067F348: sb          $a1, 0x44($v1)
    MEM_B(0X44, ctx->r3) = ctx->r5;
    // 0x8067F34C: sb          $a2, 0x35($v1)
    MEM_B(0X35, ctx->r3) = ctx->r6;
    // 0x8067F350: sb          $a2, 0x45($v1)
    MEM_B(0X45, ctx->r3) = ctx->r6;
    // 0x8067F354: sb          $a3, 0x36($v1)
    MEM_B(0X36, ctx->r3) = ctx->r7;
    // 0x8067F358: sb          $a3, 0x46($v1)
    MEM_B(0X46, ctx->r3) = ctx->r7;
    // 0x8067F35C: sb          $v0, 0x54($v1)
    MEM_B(0X54, ctx->r3) = ctx->r2;
    // 0x8067F360: sb          $v0, 0x64($v1)
    MEM_B(0X64, ctx->r3) = ctx->r2;
    // 0x8067F364: sb          $t0, 0x55($v1)
    MEM_B(0X55, ctx->r3) = ctx->r8;
    // 0x8067F368: sb          $t0, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r8;
    // 0x8067F36C: sb          $t1, 0x56($v1)
    MEM_B(0X56, ctx->r3) = ctx->r9;
    // 0x8067F370: sb          $t1, 0x66($v1)
    MEM_B(0X66, ctx->r3) = ctx->r9;
    // 0x8067F374: sw          $s0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r16;
    // 0x8067F378: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8067F37C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8067F380: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8067F384: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8067F388: jal         0x8007711C
    // 0x8067F38C: sw          $v1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r3;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8067F38C: sw          $v1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r3;
    after_3:
    // 0x8067F390: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F394: multu       $s2, $s3
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8067F398: lw          $v1, 0x9C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X9C);
    // 0x8067F39C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8067F3A0: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x8067F3A4: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8067F3A8: ori         $t9, $t9, 0x103F
    ctx->r25 = ctx->r25 | 0X103F;
    // 0x8067F3AC: addiu       $t6, $v1, 0x28
    ctx->r14 = ADD32(ctx->r3, 0X28);
    // 0x8067F3B0: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8067F3B4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8067F3B8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8067F3BC: addiu       $t7, $s2, -0x1
    ctx->r15 = ADD32(ctx->r18, -0X1);
    // 0x8067F3C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8067F3C4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8067F3C8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8067F3CC: addiu       $ra, $a0, 0x7
    ctx->r31 = ADD32(ctx->r4, 0X7);
    // 0x8067F3D0: sra         $ra, $ra, 3
    ctx->r31 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8067F3D4: addiu       $t7, $s3, -0x1
    ctx->r15 = ADD32(ctx->r19, -0X1);
    // 0x8067F3D8: mflo        $t4
    ctx->r12 = lo;
    // 0x8067F3DC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8067F3E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8067F3E4: andi        $ra, $ra, 0x1FF
    ctx->r31 = ctx->r31 & 0X1FF;
    // 0x8067F3E8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8067F3EC: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8067F3F0: sll         $ra, $ra, 9
    ctx->r31 = S32(ctx->r31 << 9);
    // 0x8067F3F4: sra         $t4, $t4, 1
    ctx->r12 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8067F3F8: lui         $s1, 0x8068
    ctx->r17 = S32(RELOC_HI16(547, 0X1090) << 16);
    // 0x8067F3FC: addiu       $s1, $s1, 0x280
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(547, 0X1090));
    // 0x8067F400: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8067F404: or          $s0, $t6, $t9
    ctx->r16 = ctx->r14 | ctx->r25;
    // 0x8067F408: lui         $s3, 0xF550
    ctx->r19 = S32(0XF550 << 16);
    // 0x8067F40C: lui         $s2, 0xFD50
    ctx->r18 = S32(0XFD50 << 16);
    // 0x8067F410: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8067F414: bgez        $a0, L_8067F424
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8067F418: sra         $a3, $a0, 3
        ctx->r7 = S32(SIGNED(ctx->r4) >> 3);
            goto L_8067F424;
    }
    // 0x8067F418: sra         $a3, $a0, 3
    ctx->r7 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8067F41C: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
    // 0x8067F420: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_8067F424:
    // 0x8067F424: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8067F428: or          $ra, $ra, $at
    ctx->r31 = ctx->r31 | ctx->r1;
    // 0x8067F42C: lui         $fp, 0x600
    ctx->r30 = S32(0X600 << 16);
    // 0x8067F430: lui         $s7, 0xF200
    ctx->r23 = S32(0XF200 << 16);
    // 0x8067F434: lui         $s6, 0xE700
    ctx->r22 = S32(0XE700 << 16);
    // 0x8067F438: lui         $s5, 0xF300
    ctx->r21 = S32(0XF300 << 16);
    // 0x8067F43C: lui         $s4, 0xE600
    ctx->r20 = S32(0XE600 << 16);
    // 0x8067F440: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
L_8067F444:
    // 0x8067F444: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F448: slti        $at, $t4, 0x7FF
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF ? 1 : 0;
    // 0x8067F44C: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
    // 0x8067F450: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8067F454: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x8067F458: sw          $s2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r18;
    // 0x8067F45C: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8067F460: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x8067F464: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8067F468: lh          $t9, 0x144($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X144);
    // 0x8067F46C: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8067F470: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8067F474: sll         $t7, $t9, 10
    ctx->r15 = S32(ctx->r25 << 10);
    // 0x8067F478: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8067F47C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8067F480: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F484: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8067F488: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x8067F48C: sw          $s3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r19;
    // 0x8067F490: sw          $t5, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r13;
    // 0x8067F494: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F498: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8067F49C: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8067F4A0: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x8067F4A4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8067F4A8: sw          $s4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r20;
    // 0x8067F4AC: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F4B0: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8067F4B4: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x8067F4B8: sw          $s5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r21;
    // 0x8067F4BC: beq         $at, $zero, L_8067F4CC
    if (ctx->r1 == 0) {
        // 0x8067F4C0: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_8067F4CC;
    }
    // 0x8067F4C0: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x8067F4C4: b           L_8067F4CC
    // 0x8067F4C8: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
        goto L_8067F4CC;
    // 0x8067F4C8: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
L_8067F4CC:
    // 0x8067F4CC: bgtz        $a3, L_8067F4DC
    if (SIGNED(ctx->r7) > 0) {
        // 0x8067F4D0: nop
    
            goto L_8067F4DC;
    }
    // 0x8067F4D0: nop

    // 0x8067F4D4: b           L_8067F4DC
    // 0x8067F4D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8067F4DC;
    // 0x8067F4D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8067F4DC:
    // 0x8067F4DC: bgtz        $a3, L_8067F4EC
    if (SIGNED(ctx->r7) > 0) {
        // 0x8067F4E0: addiu       $t8, $t1, 0x7FF
        ctx->r24 = ADD32(ctx->r9, 0X7FF);
            goto L_8067F4EC;
    }
    // 0x8067F4E0: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8067F4E4: b           L_8067F4EC
    // 0x8067F4E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8067F4EC;
    // 0x8067F4E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8067F4EC:
    // 0x8067F4EC: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x8067F4F0: mflo        $t6
    ctx->r14 = lo;
    // 0x8067F4F4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8067F4F8: bne         $a1, $zero, L_8067F504
    if (ctx->r5 != 0) {
        // 0x8067F4FC: nop
    
            goto L_8067F504;
    }
    // 0x8067F4FC: nop

    // 0x8067F500: break       7
    do_break(2154296576);
L_8067F504:
    // 0x8067F504: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8067F508: bne         $a1, $at, L_8067F51C
    if (ctx->r5 != ctx->r1) {
        // 0x8067F50C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8067F51C;
    }
    // 0x8067F50C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067F510: bne         $t8, $at, L_8067F51C
    if (ctx->r24 != ctx->r1) {
        // 0x8067F514: nop
    
            goto L_8067F51C;
    }
    // 0x8067F514: nop

    // 0x8067F518: break       6
    do_break(2154296600);
L_8067F51C:
    // 0x8067F51C: andi        $t8, $t0, 0xFFF
    ctx->r24 = ctx->r8 & 0XFFF;
    // 0x8067F520: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8067F524: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x8067F528: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8067F52C: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8067F530: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F534: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8067F538: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8067F53C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8067F540: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x8067F544: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8067F548: sw          $s6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r22;
    // 0x8067F54C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F550: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8067F554: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8067F558: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x8067F55C: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8067F560: sw          $ra, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r31;
    // 0x8067F564: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F568: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8067F56C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8067F570: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x8067F574: sw          $s0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r16;
    // 0x8067F578: sw          $s7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r23;
    // 0x8067F57C: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F580: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8067F584: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8067F588: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x8067F58C: sw          $s1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r17;
    // 0x8067F590: sw          $fp, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r30;
    // 0x8067F594: bne         $t2, $at, L_8067F444
    if (ctx->r10 != ctx->r1) {
        // 0x8067F598: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8067F444;
    }
    // 0x8067F598: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8067F59C: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x8067F5A0: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x8067F5A4: sw          $t8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r24;
    // 0x8067F5A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8067F5AC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8067F5B0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8067F5B4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8067F5B8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8067F5BC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8067F5C0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8067F5C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8067F5C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8067F5CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067F5D0: jr          $ra
    // 0x8067F5D4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8067F5D4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_80421120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80421124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80421128: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8042112C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80421130: beq         $t6, $zero, L_8042116C
    if (ctx->r14 == 0) {
        // 0x80421134: nop
    
            goto L_8042116C;
    }
    // 0x80421134: nop

    // 0x80421138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042113C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80421140: jalr        $t9
    // 0x80421144: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80421144: nop

    after_0:
    // 0x80421148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042114C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80421150: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80421154: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80421158: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8042115C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80421160: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80421164: b           L_8042116C
    // 0x80421168: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8042116C;
    // 0x80421168: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8042116C:
    // 0x8042116C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80421170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80421174: jr          $ra
    // 0x80421178: nop

    return;
    // 0x80421178: nop

;}
RECOMP_FUNC void func_8073EC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EC94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073EC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EC9C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8073ECA0: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(748, 0X238C) << 16);
    // 0x8073ECA4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8073ECA8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8073ECAC: addiu       $t6, $t6, 0xB7C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(748, 0X238C));
    // 0x8073ECB0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8073ECB4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8073ECB8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8073ECBC: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8073ECC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073ECC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073ECC8: jal         0x8073ECE0
    // 0x8073ECCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8073ECE0(rdram, ctx);
        goto after_0;
    // 0x8073ECCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8073ECD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073ECD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073ECD8: jr          $ra
    // 0x8073ECDC: nop

    return;
    // 0x8073ECDC: nop

;}
RECOMP_FUNC void func_80029180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029180: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80029184: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80029188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002918C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80029190: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80029194: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x80029198: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8002919C: addu        $t7, $a2, $v0
    ctx->r15 = ADD32(ctx->r6, ctx->r2);
    // 0x800291A0: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800291A4: mul.s       $f2, $f4, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800291A8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800291AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800291B0: mul.s       $f16, $f6, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800291B4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800291B8: sub.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800291BC: jal         0x80065954
    // 0x800291C0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x800291C0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800291C4: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800291C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800291CC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800291D0: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x800291D4: nop

    // 0x800291D8: bc1fl       L_800291EC
    if (!c1cs) {
        // 0x800291DC: lwc1        $f0, 0x0($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800291EC;
    }
    goto skip_0;
    // 0x800291DC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800291E0: b           L_80029210
    // 0x800291E4: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
        goto L_80029210;
    // 0x800291E4: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    // 0x800291E8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
L_800291EC:
    // 0x800291EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800291F0: nop

    // 0x800291F4: bc1fl       L_8002920C
    if (!c1cs) {
        // 0x800291F8: sub.s       $f18, $f0, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
            goto L_8002920C;
    }
    goto skip_1;
    // 0x800291F8: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    skip_1:
    // 0x800291FC: add.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80029200: b           L_80029210
    // 0x80029204: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
        goto L_80029210;
    // 0x80029204: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80029208: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
L_8002920C:
    // 0x8002920C: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
L_80029210:
    // 0x80029210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029214: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80029218: jr          $ra
    // 0x8002921C: nop

    return;
    // 0x8002921C: nop

;}
RECOMP_FUNC void func_800454EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800454EC: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x800454F0: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x800454F4: lw          $t7, 0x88($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X88);
    // 0x800454F8: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x800454FC: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x80045500: jr          $ra
    // 0x80045504: sb          $zero, 0x4($t9)
    MEM_B(0X4, ctx->r25) = 0;
    return;
    // 0x80045504: sb          $zero, 0x4($t9)
    MEM_B(0X4, ctx->r25) = 0;
;}
RECOMP_FUNC void func_8002F47C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F47C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F484: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F488: sw          $zero, 0xFC($v0)
    MEM_W(0XFC, ctx->r2) = 0;
    // 0x8002F48C: lwc1        $f4, 0x120($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X120);
    // 0x8002F490: lwc1        $f6, 0x68($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X68);
    // 0x8002F494: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002F498: jal         0x8002E110
    // 0x8002F49C: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    func_8002E110(rdram, ctx);
        goto after_0;
    // 0x8002F49C: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    after_0:
    // 0x8002F4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F4A8: jr          $ra
    // 0x8002F4AC: nop

    return;
    // 0x8002F4AC: nop

;}
RECOMP_FUNC void func_8044DBBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044DBBC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044DBC0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8044DBC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044DBC8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8044DBCC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8044DBD0: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x8044DBD4: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8044DBD8: sll         $t0, $a3, 2
    ctx->r8 = S32(ctx->r7 << 2);
    // 0x8044DBDC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8044DBE0: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x8044DBE4: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
    // 0x8044DBE8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8044DBEC: addu        $t7, $v1, $t0
    ctx->r15 = ADD32(ctx->r3, ctx->r8);
    // 0x8044DBF0: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x8044DBF4: beq         $t9, $zero, L_8044DC38
    if (ctx->r25 == 0) {
        // 0x8044DBF8: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_8044DC38;
    }
    // 0x8044DBF8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8044DBFC: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8044DC00: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8044DC04: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8044DC08: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x8044DC0C: addu        $a1, $t4, $a1
    ctx->r5 = ADD32(ctx->r12, ctx->r5);
    // 0x8044DC10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044DC14: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8044DC18: jal         0x8044D1F4
    // 0x8044DC1C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8044D1F4(rdram, ctx);
        goto after_0;
    // 0x8044DC1C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_0:
    // 0x8044DC20: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8044DC24: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8044DC28: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8044DC2C: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x8044DC30: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8044DC34: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8044DC38:
    // 0x8044DC38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044DC3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8044DC40: jr          $ra
    // 0x8044DC44: nop

    return;
    // 0x8044DC44: nop

;}
RECOMP_FUNC void func_80428460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428460: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80428464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80428468: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x8042846C: lwc1        $f4, 0xC4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x80428470: lwc1        $f12, 0x50($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X50);
    // 0x80428474: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80428478: lwc1        $f6, 0xC8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC8);
    // 0x8042847C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80428480: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x80428484: jal         0x80066DE4
    // 0x80428488: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80428488: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8042848C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80428490: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80428494: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x80428498: mul.s       $f14, $f0, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8042849C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x804284A0: jal         0x80066E88
    // 0x804284A4: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x804284A4: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x804284A8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804284AC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804284B0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EC0) << 16);
    // 0x804284B4: lwc1        $f10, -0x6800($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EC0));
    // 0x804284B8: sub.s       $f2, $f14, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x804284BC: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x804284C0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x804284C4: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EC4) << 16);
    // 0x804284C8: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x804284CC: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804284D0: bc1f        L_804284F8
    if (!c1cs) {
        // 0x804284D4: nop
    
            goto L_804284F8;
    }
    // 0x804284D4: nop

    // 0x804284D8: lwc1        $f18, -0x67FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EC4));
    // 0x804284DC: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    // 0x804284E0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x804284E4: nop

    // 0x804284E8: bc1f        L_804284F8
    if (!c1cs) {
        // 0x804284EC: nop
    
            goto L_804284F8;
    }
    // 0x804284EC: nop

    // 0x804284F0: b           L_80428514
    // 0x804284F4: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
        goto L_80428514;
    // 0x804284F4: swc1        $f14, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f14.u32l;
L_804284F8:
    // 0x804284F8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1EC8) << 16);
    // 0x804284FC: lwc1        $f18, -0x67F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1EC8));
    // 0x80428500: addiu       $v0, $a1, 0xC4
    ctx->r2 = ADD32(ctx->r5, 0XC4);
    // 0x80428504: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80428508: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8042850C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80428510: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_80428514:
    // 0x80428514: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80428518: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1ECC) << 16);
    // 0x8042851C: lwc1        $f4, -0x67F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1ECC));
    // 0x80428520: sub.s       $f2, $f12, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80428524: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80428528: nop

    // 0x8042852C: bc1f        L_8042854C
    if (!c1cs) {
        // 0x80428530: nop
    
            goto L_8042854C;
    }
    // 0x80428530: nop

    // 0x80428534: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80428538: nop

    // 0x8042853C: bc1f        L_8042854C
    if (!c1cs) {
        // 0x80428540: nop
    
            goto L_8042854C;
    }
    // 0x80428540: nop

    // 0x80428544: b           L_8042855C
    // 0x80428548: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
        goto L_8042855C;
    // 0x80428548: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
L_8042854C:
    // 0x8042854C: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80428550: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80428554: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80428558: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
L_8042855C:
    // 0x8042855C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80428560: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80428564: jr          $ra
    // 0x80428568: nop

    return;
    // 0x80428568: nop

;}
RECOMP_FUNC void func_8007814C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007814C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078154: jal         0x80078760
    // 0x80078158: nop

    func_80078760(rdram, ctx);
        goto after_0;
    // 0x80078158: nop

    after_0:
    // 0x8007815C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078164: jr          $ra
    // 0x80078168: nop

    return;
    // 0x80078168: nop

;}
RECOMP_FUNC void func_8078CFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078CFE8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8078CFEC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8078CFF0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078CFF4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8078CFF8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8078CFFC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8078D000: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8078D004: lui         $t1, 0x8079
    ctx->r9 = S32(RELOC_HI16(799, 0X1F8) << 16);
    // 0x8078D008: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8078D00C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8078D010: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8078D014: lw          $t1, -0x2F68($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(799, 0X1F8));
    // 0x8078D018: jr          $ra
    // 0x8078D01C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8078D01C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_805AD7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AD7C8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x805AD7CC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x805AD7D0: addu        $t7, $a2, $v0
    ctx->r15 = ADD32(ctx->r6, ctx->r2);
    // 0x805AD7D4: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x805AD7D8: bnel        $at, $zero, L_805AD7EC
    if (ctx->r1 != 0) {
        // 0x805AD7DC: lw          $t8, -0x4($t7)
        ctx->r24 = MEM_W(ctx->r15, -0X4);
            goto L_805AD7EC;
    }
    goto skip_0;
    // 0x805AD7DC: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    skip_0:
    // 0x805AD7E0: jr          $ra
    // 0x805AD7E4: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    return;
    // 0x805AD7E4: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x805AD7E8: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
L_805AD7EC:
    // 0x805AD7EC: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x805AD7F0: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x805AD7F4: bnel        $at, $zero, L_805AD808
    if (ctx->r1 != 0) {
        // 0x805AD7F8: slti        $at, $a3, 0x2
        ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_805AD808;
    }
    goto skip_1;
    // 0x805AD7F8: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    skip_1:
    // 0x805AD7FC: jr          $ra
    // 0x805AD800: lwc1        $f0, -0x4($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, -0X4);
    return;
    // 0x805AD800: lwc1        $f0, -0x4($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, -0X4);
    // 0x805AD804: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
L_805AD808:
    // 0x805AD808: bne         $at, $zero, L_805AD964
    if (ctx->r1 != 0) {
        // 0x805AD80C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_805AD964;
    }
    // 0x805AD80C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805AD810: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // 0x805AD814: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x805AD818: beql        $v1, $zero, L_805AD890
    if (ctx->r3 == 0) {
        // 0x805AD81C: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_805AD890;
    }
    goto skip_2;
    // 0x805AD81C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    skip_2:
    // 0x805AD820: addiu       $v0, $a2, 0x4
    ctx->r2 = ADD32(ctx->r6, 0X4);
    // 0x805AD824: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x805AD828: bnel        $a0, $t0, L_805AD83C
    if (ctx->r4 != ctx->r8) {
        // 0x805AD82C: lw          $v1, -0x4($v0)
        ctx->r3 = MEM_W(ctx->r2, -0X4);
            goto L_805AD83C;
    }
    goto skip_3;
    // 0x805AD82C: lw          $v1, -0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X4);
    skip_3:
    // 0x805AD830: jr          $ra
    // 0x805AD834: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    return;
    // 0x805AD834: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x805AD838: lw          $v1, -0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X4);
L_805AD83C:
    // 0x805AD83C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x805AD840: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x805AD844: beq         $at, $zero, L_805AD888
    if (ctx->r1 == 0) {
        // 0x805AD848: slt         $at, $a0, $t0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_805AD888;
    }
    // 0x805AD848: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x805AD84C: beq         $at, $zero, L_805AD888
    if (ctx->r1 == 0) {
        // 0x805AD850: subu        $t3, $a0, $v1
        ctx->r11 = SUB32(ctx->r4, ctx->r3);
            goto L_805AD888;
    }
    // 0x805AD850: subu        $t3, $a0, $v1
    ctx->r11 = SUB32(ctx->r4, ctx->r3);
    // 0x805AD854: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x805AD858: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x805AD85C: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x805AD860: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805AD864: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805AD868: subu        $t4, $t0, $v1
    ctx->r12 = SUB32(ctx->r8, ctx->r3);
    // 0x805AD86C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x805AD870: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x805AD874: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805AD878: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x805AD87C: div.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x805AD880: jr          $ra
    // 0x805AD884: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    return;
    // 0x805AD884: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
L_805AD888:
    // 0x805AD888: beq         $v0, $a3, L_805AD964
    if (ctx->r2 == ctx->r7) {
        // 0x805AD88C: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_805AD964;
    }
    // 0x805AD88C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
L_805AD890:
    // 0x805AD890: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
L_805AD894:
    // 0x805AD894: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x805AD898: bne         $a0, $a2, L_805AD8A8
    if (ctx->r4 != ctx->r6) {
        // 0x805AD89C: addu        $t5, $a1, $t0
        ctx->r13 = ADD32(ctx->r5, ctx->r8);
            goto L_805AD8A8;
    }
    // 0x805AD89C: addu        $t5, $a1, $t0
    ctx->r13 = ADD32(ctx->r5, ctx->r8);
    // 0x805AD8A0: jr          $ra
    // 0x805AD8A4: lwc1        $f0, 0x0($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X0);
    return;
    // 0x805AD8A4: lwc1        $f0, 0x0($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X0);
L_805AD8A8:
    // 0x805AD8A8: lw          $v1, -0x4($t1)
    ctx->r3 = MEM_W(ctx->r9, -0X4);
    // 0x805AD8AC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x805AD8B0: beq         $at, $zero, L_805AD8F4
    if (ctx->r1 == 0) {
        // 0x805AD8B4: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_805AD8F4;
    }
    // 0x805AD8B4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x805AD8B8: beq         $at, $zero, L_805AD8F4
    if (ctx->r1 == 0) {
        // 0x805AD8BC: subu        $t6, $a0, $v1
        ctx->r14 = SUB32(ctx->r4, ctx->r3);
            goto L_805AD8F4;
    }
    // 0x805AD8BC: subu        $t6, $a0, $v1
    ctx->r14 = SUB32(ctx->r4, ctx->r3);
    // 0x805AD8C0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x805AD8C4: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x805AD8C8: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x805AD8CC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805AD8D0: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805AD8D4: subu        $t7, $a2, $v1
    ctx->r15 = SUB32(ctx->r6, ctx->r3);
    // 0x805AD8D8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x805AD8DC: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x805AD8E0: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805AD8E4: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x805AD8E8: div.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805AD8EC: jr          $ra
    // 0x805AD8F0: add.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f2.fl;
    return;
    // 0x805AD8F0: add.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f2.fl;
L_805AD8F4:
    // 0x805AD8F4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x805AD8F8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x805AD8FC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x805AD900: bne         $a0, $t2, L_805AD914
    if (ctx->r4 != ctx->r10) {
        // 0x805AD904: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_805AD914;
    }
    // 0x805AD904: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x805AD908: addu        $t8, $a1, $t0
    ctx->r24 = ADD32(ctx->r5, ctx->r8);
    // 0x805AD90C: jr          $ra
    // 0x805AD910: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
    return;
    // 0x805AD910: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
L_805AD914:
    // 0x805AD914: beq         $at, $zero, L_805AD95C
    if (ctx->r1 == 0) {
        // 0x805AD918: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_805AD95C;
    }
    // 0x805AD918: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x805AD91C: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x805AD920: beq         $at, $zero, L_805AD95C
    if (ctx->r1 == 0) {
        // 0x805AD924: subu        $t9, $a0, $v1
        ctx->r25 = SUB32(ctx->r4, ctx->r3);
            goto L_805AD95C;
    }
    // 0x805AD924: subu        $t9, $a0, $v1
    ctx->r25 = SUB32(ctx->r4, ctx->r3);
    // 0x805AD928: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x805AD92C: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x805AD930: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805AD934: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805AD938: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805AD93C: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x805AD940: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x805AD944: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x805AD948: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x805AD94C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x805AD950: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x805AD954: jr          $ra
    // 0x805AD958: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    return;
    // 0x805AD958: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
L_805AD95C:
    // 0x805AD95C: bne         $v0, $a3, L_805AD894
    if (ctx->r2 != ctx->r7) {
        // 0x805AD960: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_805AD894;
    }
    // 0x805AD960: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_805AD964:
    // 0x805AD964: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805AD968: nop

    // 0x805AD96C: jr          $ra
    // 0x805AD970: nop

    return;
    // 0x805AD970: nop

;}
RECOMP_FUNC void func_804C3B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3B5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804C3B60: lui         $a2, 0xB800
    ctx->r6 = S32(0XB800 << 16);
    // 0x804C3B64: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x804C3B68: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804C3B6C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x804C3B70: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x804C3B74: jr          $ra
    // 0x804C3B78: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    return;
    // 0x804C3B78: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
;}
RECOMP_FUNC void func_8044A058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A058: jr          $ra
    // 0x8044A05C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8044A05C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80045730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80045734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045738: jal         0x80045328
    // 0x8004573C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045328(rdram, ctx);
        goto after_0;
    // 0x8004573C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80045740: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80045744: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045748: bne         $v0, $zero, L_80045764
    if (ctx->r2 != 0) {
        // 0x8004574C: sw          $v0, 0x16C($a1)
        MEM_W(0X16C, ctx->r5) = ctx->r2;
            goto L_80045764;
    }
    // 0x8004574C: sw          $v0, 0x16C($a1)
    MEM_W(0X16C, ctx->r5) = ctx->r2;
    // 0x80045750: addiu       $a0, $a0, 0x620
    ctx->r4 = ADD32(ctx->r4, 0X620);
    // 0x80045754: jal         0x80071380
    // 0x80045758: addiu       $a1, $zero, 0x14C
    ctx->r5 = ADD32(0, 0X14C);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80045758: addiu       $a1, $zero, 0x14C
    ctx->r5 = ADD32(0, 0X14C);
    after_1:
    // 0x8004575C: b           L_80045790
    // 0x80045760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80045790;
    // 0x80045760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80045764:
    // 0x80045764: lw          $a0, 0x16C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X16C);
    // 0x80045768: jal         0x800452C0
    // 0x8004576C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800452C0(rdram, ctx);
        goto after_2;
    // 0x8004576C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x80045770: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80045774: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80045778: lbu         $t6, 0x164($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X164);
    // 0x8004577C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80045780: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80045784: lw          $t9, 0x57C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X57C);
    // 0x80045788: jalr        $t9
    // 0x8004578C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8004578C: nop

    after_3:
L_80045790:
    // 0x80045790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80045794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045798: jr          $ra
    // 0x8004579C: nop

    return;
    // 0x8004579C: nop

;}
RECOMP_FUNC void func_804539F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804539F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804539F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804539F8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804539FC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453A00: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80453A04: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D44) << 16);
    // 0x80453A08: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80453A0C: sw          $a1, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r5;
    // 0x80453A10: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80453A14: lw          $t9, -0x7EDC($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D44));
    // 0x80453A18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80453A1C: jalr        $t9
    // 0x80453A20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80453A20: nop

    after_0:
    // 0x80453A24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80453A28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80453A2C: jal         0x80457164
    // 0x80453A30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80457164(rdram, ctx);
        goto after_1;
    // 0x80453A30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80453A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453A38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453A3C: jr          $ra
    // 0x80453A40: nop

    return;
    // 0x80453A40: nop

;}
